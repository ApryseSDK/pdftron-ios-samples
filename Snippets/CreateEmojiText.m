// This file shows how to create PDF text that includes an emoji character by creating a FreeText annotation and flattening it.

[self.pdfViewCtrl DocLock:YES withBlock:^(PTPDFDoc * _Nullable doc) {
        
        // where to place the rect in PDF coordinates
        PTPDFRect* pdfRect = [[PTPDFRect alloc] initWithX1:10 y1:10 x2:200 y2:200];
        PTFreeText* freeText = [PTFreeText Create:[doc GetSDFDoc] pos:pdfRect];
        
        // contents, font size
        [freeText SetContents:@"Emoji string 😄"];
        [freeText SetFontSize:24];
        
        // set font, must be the postscript name
        [freeText setFontWithName:@"Noteworthy-Light" pdfDoc:doc];
        
        // no border
        PTBorderStyle* bs = [freeText GetBorderStyle];
        [bs SetWidth:0];
        [freeText SetBorderStyle:bs oldStyleOnly:NO];
        
        // add annotation
        [[doc GetPage:1] AnnotPushBack:freeText];
        
        // create an appearance that include emoji
        [PTFreeTextCreate refreshAppearanceForAnnot:freeText onDoc:doc];
        
        // record where this annot is in screen space
        PTPDFRect* screenRect = [self.pdfViewCtrl GetScreenRectForAnnot:freeText page_num:1];
        
        // flatten it so it's part of the PDF, not an annotation
        [freeText Flatten:[doc GetPage:1]];
        
        // refresh the viewer
        [self.pdfViewCtrl UpdateWithRect:screenRect];
    } error:nil];

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>
#import <PDFNet/PDFNet.h>

/**
 Utilities for creating `PTPDFDoc` objects.
 */
PT_OBJC_RUNTIME_NAME(PDFTronUtil)
@interface PTPDFTronUtil : NSObject

//+(PTPDFDoc*)PTPDFDocFromURL:(NSURL *)url error:(NSError**)error;

/**
 Create a `PTPDFDoc` from a `UIImage` instance.
 */
+(PTPDFDoc*)PTPDFDocFromImage:(UIImage*)image;

@end

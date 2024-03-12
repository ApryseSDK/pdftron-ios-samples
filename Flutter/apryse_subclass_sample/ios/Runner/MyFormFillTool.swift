//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

import UIKit
import Tools

class MyFormFillTool : PTFormFillTool
{
    var formArrowView: UIImageView?

    override var currentAnnotation: PTAnnot?
    {
        get {
            return super.currentAnnotation
        }
        set {
            self.addArrowView(to: newValue)
            super.currentAnnotation = newValue
        }
    }

    func addArrowView(to annotation:PTAnnot?){
        guard let pdfViewCtrl else {return}

        if let formArrowView
        {
            pdfViewCtrl.removeFloating(formArrowView)
        }

        if let annotation,
           let rect = annotation.getRect(),
           let image = UIImage(systemName: "arrowtriangle.right.fill"),
           let markerRect = PTPDFRect(x1: rect.x1 - 20, y1: rect.y1, x2: rect.x1, y2: rect.y2)
        {

            formArrowView = UIImageView(image: image)
            if let formArrowView {
                pdfViewCtrl.addFloating(formArrowView, toPage: Int32(self.annotationPageNumber), withPageRect: markerRect, noZoom: false)
            }
        }
    }
}

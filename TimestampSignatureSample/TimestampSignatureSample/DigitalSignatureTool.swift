//
//  DigitalSignatureTool.swift
//  TimestampSignatureSample
//
//  Created by Yifan Zhang on 2021-12-06.
//

import UIKit
import PDFNet
import Tools

class DigitalSignatureTool: PTDigitalSignatureTool {
    override func addSignature(toWidget doc: PTPDFDoc) {
        let timeStampedDoc = createTimestampSignatureForWidget(doc: doc)

        super.addSignature(toWidget: timeStampedDoc)
    }
    
    override func addStamp(_ stampDoc: PTPDFDoc) {
        let timeStampedDoc = createTimestampSignature(doc: stampDoc)

        super.addStamp(timeStampedDoc)
    }
    
    func createTimestampSignature(doc: PTPDFDoc, width: Double, height: Double) -> PTPDFDoc {
        let tempDoc = PTPDFDoc()
        guard let page = doc.getPage(1) else { return doc }
        let timestampedSignaturePage = tempDoc?.pageCreate(PTPDFRect(x1: 0, y1: 0, x2: width, y2: height))
        tempDoc?.pagePushBack(timestampedSignaturePage)
        
        let sigStamp = PTStamper(size_type: e_ptrelative_scale, a: 1, b: 1)
        sigStamp?.setAlignment(e_pthorizontal_center, vertical_alignment: e_ptvertical_top)
        sigStamp?.stampPage(tempDoc, src_page: page, dest_pages: PTPageSet(one_page: 1))
        
        let timeStamp = PTStamper(size_type: e_ptrelative_scale, a: 1, b: 1)
        timeStamp?.setAlignment(e_pthorizontal_center, vertical_alignment: e_ptvertical_bottom)
        
        let dateFormatter = DateFormatter()
        dateFormatter.setLocalizedDateFormatFromTemplate("MMMM dd yyyy, HH:mm:ss")
        let dateString = dateFormatter.string(from: Date())
        timeStamp?.stampText(tempDoc, src_txt: dateString, dest_pages: PTPageSet(one_page: 1))
        
        return tempDoc ?? doc
    }
    
    func createTimestampSignature(doc: PTPDFDoc) -> PTPDFDoc {
        guard let page = doc.getPage(1) else { return doc }
        return createTimestampSignature(doc: doc, width: page.getWidth(e_ptcrop), height: page.getHeight(e_ptcrop) * 4/3)
    }
    
    func createTimestampSignatureForWidget(doc: PTPDFDoc) -> PTPDFDoc {
        return createTimestampSignature(doc: doc, width: 500, height: 450)
    }
}

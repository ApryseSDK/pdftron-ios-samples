//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

import UIKit
import Tools

class ViewController: UIViewController {

    // https://docs.apryse.com/documentation/ios/get-started/viewdoc/
    override func viewDidAppear(_ animated: Bool) {
        // Create a CustomDocumentController
        let documentController = MyDocumentController()
        // The PTDocumentController must be in a navigation controller before a document can be opened
        let navigationController = UINavigationController(rootViewController: documentController)
        navigationController.modalPresentationStyle = .fullScreen
        navigationController.navigationBar.isTranslucent = false
        navigationController.toolbar.isTranslucent = false
        // Open a file from URL.
        let fileURL: URL = URL(string:"https://pdftron.s3.amazonaws.com/downloads/pl/sample.pdf")!
        documentController.openDocument(with: fileURL)
        // Show navigation (and document) controller.
        self.present(navigationController, animated: true, completion: nil)
    }
}

class MyDocumentController : PTDocumentController
{
    override func toolManager(_ toolManager: PTToolManager, annotationAdded annotation: PTAnnot, onPageNumber pageNumber: UInt) {
        if annotation.extendedAnnotType == .square {

            try? pdfViewCtrl.docLock(true) { doc in
                guard let doc,
                      let draw = PTPDFDraw(dpi: 72), // PTPDFDraw object to render the area to an image
                      let rect = annotation.getRect(),
                      let screenRect = pdfViewCtrl.getScreenRect(for: annotation, page_num: Int32(pageNumber)),
                      let page = doc.getPage(UInt32(pdfViewCtrl.currentPage))
                else {return}

                // store the original user crop box so it can be restored
                let originalUserCrop = page.getBox(e_ptuser_crop)

                // don't draw the annotation when creating the image
                draw.setDrawAnnotations(false)

                // set the page user crop box to the exact rect of the annotation
                page.setBox(e_ptuser_crop, box: rect)

                // PTPDFDraw uses the user crop box for its drawing
                draw.setPageBox(e_ptuser_crop)

                // create a temporary file URL to save the output image
                let outputURL = FileManager.default.temporaryDirectory.appendingPathComponent("\(UUID().uuidString).png")
                draw.export(page, filename: outputURL.path, format: "png")

                // restore the original user crop box
                page.setBox(e_ptuser_crop, box: originalUserCrop)

                // remove the annotation after creating the image
                try? toolManager.annotationManager.removeAnnotation(annotation, onPageNumber: Int32(pageNumber))

                guard let data = FileManager.default.contents(atPath: outputURL.path),
                      let img = UIImage(data: data)
                else {return}
                // do something with the `img` or `outputURL`

                // show a share sheet with the `outputURL`
                let activityController = UIActivityViewController(activityItems: [outputURL], applicationActivities: nil)
                activityController.modalPresentationStyle = .popover
                activityController.popoverPresentationController?.sourceView = self.view
                activityController.popoverPresentationController?.sourceRect = screenRect.cgRectValue
                self.present(activityController, animated: true)
            }
        }
    }
}

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

import UIKit
import Tools

class ViewController: UIViewController {

    var documentController: PTDocumentController?
    var createDocItem: UIBarButtonItem?

    // https://docs.apryse.com/documentation/ios/get-started/viewdoc/
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        documentController = PTDocumentController()
        guard let documentController else {return}

        // The PTDocumentController must be in a navigation controller before a document can be opened
        let navigationController = UINavigationController(rootViewController: documentController)
        navigationController.modalPresentationStyle = .fullScreen
        navigationController.navigationBar.isTranslucent = false
        navigationController.toolbar.isTranslucent = false

        // Open a file from URL.
        let fileURL: URL = URL(string:"https://pdftron.s3.amazonaws.com/downloads/pl/sample.pdf")!
        documentController.openDocument(with: fileURL)

        createDocItem = UIBarButtonItem(image: UIImage(systemName: "doc.richtext"), style: .plain, target: self, action: #selector(createDoc))
        guard let createDocItem else {return}

        var leftItems = documentController.navigationItem.leftBarButtonItems ?? [UIBarButtonItem]()
        leftItems.append(createDocItem)
        documentController.navigationItem.leftBarButtonItems = leftItems

        // Show navigation (and document) controller.
        self.present(navigationController, animated: true, completion: nil)
    }

    @objc func createDoc() {
        guard let documentController else {return}

        let outputURL = FileManager.default.temporaryDirectory.appendingPathComponent("\(UUID().uuidString).pdf")
        try? documentController.pdfViewCtrl.docLockRead({ doc in
            guard let doc,
                  let newDoc = PTPDFDoc(),
                  let pageSet = PTPageSet()
            else {return}

            var pageNum: Int32 = 1
            let itr: PTPageIterator = doc.getPageIterator(1)
            var hasAnnots = false

            while itr.hasNext() {
                let page: PTPage = itr.current()
                let num_annots = page.getNumAnnots()
                if num_annots > 0 {
                    hasAnnots = true
                    pageSet.addPage(pageNum)
                }
                pageNum += 1
                itr.next()
            }
            guard hasAnnots else {return} // don't do anything if there are no annotations
            newDoc.insertPages(withPageSet: 0, src_doc: doc, source_page_set: pageSet, flag: e_ptinsert_bookmark)
            newDoc.save(toFile: outputURL.path, flags: e_ptlinearized.rawValue)
        })

        guard FileManager.default.fileExists(atPath: outputURL.path) else {return}

        // show a share sheet with the `outputURL`
        let activityController = UIActivityViewController(activityItems: [outputURL], applicationActivities: nil)
        activityController.modalPresentationStyle = .popover
        activityController.popoverPresentationController?.barButtonItem = createDocItem

        DispatchQueue.main.async { [weak self] in
            guard let self,
                  let documentController = self.documentController
            else {return}
            documentController.navigationController?.present(activityController, animated: true)
        }
    }
}

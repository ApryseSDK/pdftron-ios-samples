//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

import UIKit
import PDFNet
import Tools

class ViewController: UIViewController {

    // https://docs.apryse.com/documentation/ios/get-started/viewdoc/
    override func viewDidAppear(_ animated: Bool) {
        // Create a CustomDocumentController
        let documentController = CustomDocumentController()
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


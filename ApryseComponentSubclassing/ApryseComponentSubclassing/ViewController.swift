//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

import UIKit
import Tools

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        // Use the `PTOverrides` system to register your subclass. This should be done before any Apryse classes are invoked.
        PTOverrides.addOverriddenClass(MyAnnotStyle.self)
    }
    
    override func viewDidAppear(_ animated: Bool) {
        // Create a PTDocumentController
        let documentController = PTDocumentController()
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


//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

import UIKit
import Tools

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        guard let rtfFilePath = Bundle.main.path(forResource: "SampleRTF", ofType: "rtf") else {return}
        
        PTConvert.convertOffice(toPDF: rtfFilePath, paperSize: .zero) { outputPath in
            if let outputPath {
                let fileManager = FileManager.default
                let tempFileURL = fileManager.temporaryDirectory.appendingPathComponent("tempFile.pdf")
                if fileManager.fileExists(atPath: tempFileURL.path) {
                    try? fileManager.removeItem(at: tempFileURL)
                }
                try? fileManager.copyItem(atPath: outputPath, toPath: tempFileURL.path)
                self.openDoc(url: tempFileURL) // this should be a function you create to handle the document opening
            }
        }
    }

    func openDoc(url: URL) {
        let documentController = PTDocumentController()

        // The PTDocumentController must be in a navigation controller before a document can be opened
        let navigationController = UINavigationController(rootViewController: documentController)
        navigationController.modalPresentationStyle = .fullScreen
        navigationController.navigationBar.isTranslucent = false
        navigationController.toolbar.isTranslucent = false

        documentController.openDocument(with: url)
        // Show navigation (and document) controller.
        self.present(navigationController, animated: true, completion: nil)
    }
}


//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

import UIKit
import Tools
import PDFTronCollaboration

class ViewController: UIViewController {

    var documentController:PTCollaborationDocumentController?

    var collabClient:CollabClient?

    override func viewDidLoad() {
        super.viewDidLoad()

        guard let subscriptionURL = URL(string:"wss://collab-server.pdftron.com/subscribe"),
              let endpointURL = URL(string:"https://collab-server.pdftron.com")
        else {return}

        let documentID = "" // Leave blank to generate a new document

        let username = "Guest"

        // Initialize a CollabClient instance
        collabClient = CollabClient(endpointURL: endpointURL, subscriptionURL: subscriptionURL)

        guard let collabClient = collabClient else {
            return
        }

        // Login anonymously with a username and open a document with the specified ID
        collabClient.loginAnonymously(username: username) { user in
            guard let user = user else {
                // User not found
                return
            }
            // Get the document if it exists
            user.getDocument(documentID: documentID) { document in
                guard let document = document else {
                    // document doesn't exist, create one
                    user.createDocument(documentID: documentID, documentName: "NewDocument", isPublic: true, annotations: []) { document in
                        guard let document = document else { return }
                        // View the document — this step is to connect the user to the document for real-time annotation syncing
                        document.view()
                    }
                    return
                }
                // Add the user to the document if the document exists
                document.join { joined in
                    // View the document — this step is to connect the user to the document for real-time annotation syncing
                    document.view()
                }
            }
        }
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        showViewer()
    }

    func showViewer()
    {
        guard let collabClient = collabClient
        else {
            return
        }

        documentController = PTCollaborationDocumentController(collaborationService: collabClient)

        guard let documentController = documentController,
              let documentURL = URL(string: "https://pdftron.s3.amazonaws.com/downloads/pl/webviewer-demo.pdf")
        else {
            return
        }

        documentController.openDocument(with: documentURL)

        let navVC = UINavigationController(rootViewController: documentController)
        navVC.modalPresentationStyle = .fullScreen

        // Optional: add a share button to the viewer to
        let shareButton = UIBarButtonItem(barButtonSystemItem: .action, target: self, action: #selector(shareDocument))

        if let leftBarItems = documentController.navigationItem.leftBarButtonItems {
            var leftBarButtonItems = leftBarItems
            leftBarButtonItems.append(shareButton)
            documentController.navigationItem.leftBarButtonItems = leftBarButtonItems
        }

        self.present(navVC, animated: true, completion: nil)
    }
    
    @objc func dismissViewer()
    {
        self.dismiss(animated: true)
    }
    
    @objc func shareDocument()
    {
        guard let documentController = documentController,
              let documentID = documentController.service.documentID
        else {
            return
        }

        let alertVC = UIAlertController(title: "Share Link", message: nil, preferredStyle: .alert)
        let copyAction = UIAlertAction(title: "Copy Document ID to Clipboard", style: .default) { _ in
            UIPasteboard.general.string = documentID
        }

        let webViewerAction = UIAlertAction(title: "Open in WebViewer Showcase", style: .default) { _ in
            let urlString = "https://www.pdftron.com/webviewer/demo/document-collaboration/?shareId="+documentID+"&mobile=1"
            guard let url = URL(string: urlString) else { return }
            UIApplication.shared.open(url)
        }

        let cancelAction = UIAlertAction(title: "Cancel", style: .cancel)
        alertVC.addAction(copyAction)
        alertVC.addAction(webViewerAction)
        alertVC.addAction(cancelAction)
        documentController.present(alertVC, animated: true)
    }
}


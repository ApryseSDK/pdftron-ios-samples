//
//  DocumentView.swift
//  EmbeddedBasicPDFViewer
//
//  Created by Darren Chan on 2026-05-28.
//

import SwiftUI
import PDFNet
import Tools

struct DocumentView: UIViewControllerRepresentable {
    var url: URL

    func makeUIViewController(context: Context) -> UIViewController {
        let documentController = PTDocumentController()
        documentController.openDocument(with: url)
        
        return UINavigationController(rootViewController: documentController)
    }

    func updateUIViewController(_ uiViewController: UIViewController, context: Context) {
        // No update needed for static document display
    }
}

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

    func makeUIViewController(context: Context) -> PTDocumentController {
        let documentController = PTDocumentController()
        documentController.openDocument(with: url)
        return documentController
    }

    func updateUIViewController(_ uiViewController: PTDocumentController, context: Context) {
        // No update needed for static document display
    }
}

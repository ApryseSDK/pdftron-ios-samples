//
//  EmbeddedBasicPDFViewerApp.swift
//  EmbeddedBasicPDFViewer
//
//  Created by Darren Chan on 2026-05-28.
//

import SwiftUI
import PDFNet

@main
struct EmbeddedBasicPDFViewerApp: App {
    init() {
        PTPDFNet.initialize("")
    }

    var body: some Scene {
        WindowGroup {
            ContentView()
        }
    }
}

//
//  ContentView.swift
//  EmbeddedBasicPDFViewer
//
//  Created by Darren Chan on 2026-05-28.
//

import SwiftUI

struct ContentView: View {
    private let samplePDFURL = URL(string: "https://pdftron.s3.amazonaws.com/downloads/pl/PDFTRON_about.pdf")!

    var body: some View {
        VStack(spacing: 0) {
            // Top content area
            VStack(spacing: 8) {
                Image(systemName: "doc.richtext")
                    .imageScale(.large)
                    .foregroundStyle(.tint)
                Text("Embedded PDF Viewer")
                    .font(.headline)
                Text("This is a sample app that demonstrates our embedded PDF viewer in a user's app.")
                    .font(.subheadline)
                    .foregroundStyle(.secondary)
                    .multilineTextAlignment(.center)
                    .padding(.horizontal)
            }
            .padding()

            Divider()

            // Embedded PDF Document Viewer
            DocumentView(url: samplePDFURL)
                .border(Color.blue, width: 4)
                .padding(.horizontal, 8)

            Divider()

            // Bottom content area
            Text("End of document viewer")
                .font(.caption)
                .foregroundStyle(.secondary)
                .padding(8)
        }
    }
}

#Preview {
    ContentView()
}

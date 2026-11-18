# PDFTron iOS Samples

This repository contains a collection of samples for PDFTron's iOS SDK.

| Sample | Description |
|--|--|
|[CADViewer](./CADViewer)| CAD to PDF conversion using WebViewer Server as described [in this guide](https://docs.apryse.com/core/get-started/samples/cad2pdftest)|
|[CustomDocumentController](./CustomDocumentController)| Using a custom `PTDocumentController` subclass|
|[ToolbarCustomization](./ToolbarCustomization)| Customizing the UI of the viewer as described [in this guide](https://docs.apryse.com/ios/get-started/customize)|
|[ApryseComponentSubclassing](./ApryseComponentSubclassing)| Subclassing an Apryse SDK component (in this case `PTAnnotStyle`)|
|[RTFtoPDF](./RTFtoPDF)| Convert a file from RTF to PDF
|[RectToImage](./RectToImage)| Extract an area of a page to an image by drawing a rectangle annotation|
|[ExtractAnnotatedPages](./ExtractAnnotatedPages)| Extract annotated pages into a new document|
|[ReactNative/ApryseSubclassSample](./ReactNative/ApryseSubclassSample)| Subclassing an Apryse SDK component when using the React Native wrapper|
|[Flutter/apryse_subclass_sample](./Flutter/apryse_subclass_sample)| Subclassing an Apryse SDK component when using the Flutter wrapper|


More samples are included in the [.dmg download](https://docs.apryse.com/ios/get-started/integration):

| Sample | Description |
|--|--|
|Complete Reader|A fully developed PDF reader. This sample incorporates the source code for all of PDFTron's iOS UI via the "Tools" subproject, which builds `Tools.framework`.|
|Showcase|The source code for our feature showcase sample.|
|CPP Sample|Demonstrates how to use PDFTron via a C++ interface.|
|Custom|Demonstrates the use of a custom filter, which enables the implementation for custom DRM solutions.|
|Miscellaneous Samples|An Xcode project that contains demonstrates [core programmatic PDF functionality](https://docs.apryse.com/ios/get-started/samples).|

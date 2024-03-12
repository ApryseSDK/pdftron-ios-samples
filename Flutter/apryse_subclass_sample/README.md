This sample demonstrates how to subclass built-in Apryse components when integrating the Flutter Library:
https://docs.apryse.com/documentation/ios/get-started/flutter/ios/

The implementation is the same as when using the native iOS SDK:
https://docs.apryse.com/documentation/ios/guides/tools/customization/#override-classes

This sample demonstrates how to subclass the [`PTFormFillTool`](https://docs.apryse.com/api/ios/Classes/PTFormFillTool.html) and override its [`currentAnnotation`](https://docs.apryse.com/api/ios/Classes/PTTool.html#/c:objc(cs)PTTool(py)currentAnnotation) property to add an arrow image to the active form field.

# Getting Started

## Step 1: Open the Xcode project of your app

Navigate to the _ios_ directory in the app and open the `.xcworkspace` file, this will launch Xcode.

## Step 2: Add your subclass to the Xcode project

1. Use the `CMD-N` keyboard shortcut or go to `File > New > File…` in the menu bar.
2. Select `Cocoa Touch Class` from the dialog and press `Next`
3. Enter your class name in the `Class` field and select which class you want to override in the `Subclass of` field. In this sample we have added a new class called `MyFormFillTool` which is a subclass of `PTFormFillTool`.
4. If you chose to create your file in the Swift language then you should make sure to select `Yes` if it asks you to create the bridging header.

## Step 3: Implementing the subclass

Open your newly-created file in Xcode and import the Tools library at the top of the file, e.g. below any other imports such as UIKit:

```
import UIKit
import Tools
```

Add the customizations you require to your subclass, e.g overriding internal properties.
In this sample we have overridden the `currentAnnotation` property to add an arrow view when the property is set.

```
class MyFormFillTool : PTFormFillTool
{
    var formArrowView: UIImageView?

    override var currentAnnotation: PTAnnot?
    {
        get {
            return super.currentAnnotation
        }
        set {
            self.addArrowView(to: newValue)
            super.currentAnnotation = newValue
        }
    }

    func addArrowView(to annotation:PTAnnot?){
        guard let pdfViewCtrl else {return}

        if let formArrowView
        {
            pdfViewCtrl.removeFloating(formArrowView)
        }

        if let annotation,
           let rect = annotation.getRect(),
           let image = UIImage(systemName: "arrowtriangle.right.fill"),
           let markerRect = PTPDFRect(x1: rect.x1 - 20, y1: rect.y1, x2: rect.x1, y2: rect.y2)
        {

            formArrowView = UIImageView(image: image)
            if let formArrowView {
                pdfViewCtrl.addFloating(formArrowView, toPage: Int32(self.annotationPageNumber), withPageRect: markerRect, noZoom: false)
            }
        }
    }
}
```

## Step 4: Register your subclass with the Apryse SDK

To register the subclass with the SDK you will need to declare the override early in your app's lifecycle (before any Apryse components are loaded).
A good place to do this is inside your AppDelegate.

1. Open the `AppDelegate.swift` file in Xcode
2. Import the Tools library as well as your bridging header if you wrote your class in Swift:

```
import Tools
```

3. Inside the `override func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool` function you would call the `PTOverrides` method to register your class:
```
PTOverrides.addOverriddenClass(MyFormFillTool.self)
```

## Step 5: Run your app

You can now run your app and you should see the customizations you have added. Select a form field and an arrow should appear next to the field.
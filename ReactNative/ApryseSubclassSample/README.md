This sample demonstrates how to subclass built-in Apryse components when integrating the React Native Library:
https://github.com/PDFTron/pdftron-react-native

The implementation is the same as when using the native iOS SDK:
https://docs.apryse.com/documentation/ios/guides/tools/customization/#override-classes

This sample demonstrates how to subclass the [`PTOutlineViewController`](https://docs.apryse.com/api/ios/Classes/PTOutlineViewController.html) and override its [`readonly`](https://docs.apryse.com/api/ios/Classes/PTOutlineViewController.html#/c:objc(cs)PTOutlineViewController(py)readonly) property to disable editing of the outline.

# Getting Started

## Step 1: Open the Xcode project of your app

Navigate to the _ios_ directory in the app and open the `.xcworkspace` file, this will launch Xcode.

## Step 2: Add your subclass to the Xcode project

1. Use the `CMD-N` keyboard shortcut or go to `File > New > File…` in the menu bar.
2. Select `Cocoa Touch Class` from the dialog and press `Next`
3. Enter your class name in the `Class` field and select which class you want to override in the `Subclass of` field. In this sample we have added a new class called `MyOutlineViewController` which is a subclass of `PTOutlineViewController`.
4. If you chose to create your file in the Swift language then you should make sure to select `Yes` if it asks you to create the bridging header.

## Step 3: Implementing the subclass

Open your newly-created file in Xcode and import the Tools library at the top of the file, e.g. below any other imports such as UIKit:

```
import UIKit
import Tools
```

Add the customizations you require to your subclass, e.g overriding internal properties.
In this sample we have overridden the `readonly` property to always return true.

```
class MyOutlineViewController: PTOutlineViewController {

override var isReadonly: Bool
  {
    get {
      return true // always return true
    }
    set {
      super.isReadonly = newValue
    }
  }
}
```

## Step 4: Register your subclass with the Apryse SDK

To register the subclass with the SDK you will need to declare the override early in your app's lifecycle (before any Apryse components are loaded).
A good place to do this is inside your AppDelegate.

1. Open the `AppDelegate.mm` file in Xcode
2. Import the Tools library as well as your bridging header if you wrote your class in Swift:

```
#import "Tools/Tools.h"
#import "ApryseSubclassSample-Swift.h"
```

3. Inside the `- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions` function you would call the `PTOverrides` method to register your class:
```
[PTOverrides addOverriddenClass:[MyOutlineViewController class]];
```

## Step 5: Run your app

You can now run your app and you should see the customizations you have added.
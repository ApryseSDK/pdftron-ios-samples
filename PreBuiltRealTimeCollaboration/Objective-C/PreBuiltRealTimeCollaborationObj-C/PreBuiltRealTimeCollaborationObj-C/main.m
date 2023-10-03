//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

int main(int argc, char * argv[]) {
    NSString * appDelegateClassName;
    @autoreleasepool {
        // Setup code that might create autoreleased objects goes here.
        appDelegateClassName = NSStringFromClass([AppDelegate class]);
    }
    return UIApplicationMain(argc, argv, nil, appDelegateClassName);
}

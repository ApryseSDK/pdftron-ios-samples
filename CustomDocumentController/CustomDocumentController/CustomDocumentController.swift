//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

import UIKit
import Tools

// CustomDocumentController is a subclass of the Apryse PTDocumentController viewer component
class CustomDocumentController: PTDocumentController {

    // Override `PTToolManagerDelegate` methods here
    override func toolManager(_ toolManager: PTToolManager, shouldShowMenu menuController: UIMenuController, forAnnotation annotation: PTAnnot?, onPageNumber pageNumber: UInt) -> Bool {
        // Only show quick menu for the text select tool.
        guard let tool = toolManager.tool else {return true}
        if tool.isKind(of: PTTextSelectTool.self) {
            // Remove the annotation creation menu items.
            menuController.menuItems = removeAnnotationItems(menuController.menuItems!)
            return true
        } else {
            // If this tool is not the PTTextSelectTool, don't show the menu
            return false
        }
    }

    func removeAnnotationItems(_ items: [UIMenuItem]) -> [UIMenuItem] {
        let stringsToRemove = ["Highlight", "Underline", "Squiggly", "Strikeout"]

        // Filter out menu items with titles matching specified strings.
        return items.filter({ (menuItem) -> Bool in
            return !stringsToRemove.contains(menuItem.title)
        })
    }
}

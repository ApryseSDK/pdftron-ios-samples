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
        guard let annotation else { return true }
        if annotation.extendedAnnotType == .widget { // only modify the menu for widget annotations
            let selectDateItem = UIMenuItem(title: "Edit", action: #selector(editAction)) // you need to implement these
            let removeItem = UIMenuItem(title: "Add to all Pages", action: #selector(addToAllPages))
            menuController.menuItems = [selectDateItem, removeItem]
        } else if annotation.extendedAnnotType == .freeText { // only modify the menu for widget annotations
            let selectDateItem = UIMenuItem(title: "Select Date", action: #selector(selectDate)) // you need to implement these
            let removeItem = UIMenuItem(title: "Remove", action: #selector(removeField))
            menuController.menuItems = [selectDateItem, removeItem]
        }

        return true
    }

    @objc func editAction() {
        // do something here
    }

    @objc func addToAllPages() {
        // do something here
    }

    @objc func selectDate() {
        // do something here
    }

    @objc func removeField() {
        // do something here
    }
}

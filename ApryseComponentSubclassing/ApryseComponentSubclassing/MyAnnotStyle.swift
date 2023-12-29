//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

import UIKit
import Tools

class MyAnnotStyle: PTAnnotStyle {

    // Override the available style keys to remove the fillColor setting for square-type annotations
    override var availableStyleKeys: [PTAnnotStyleKey] {
        // Get the default style keys
        var styleKeys = super.availableStyleKeys

        // If the `annotType` is a square then remove the `fillColor` option
        if self.annotType == .square {
            styleKeys.removeAll { key in
                key == PTAnnotStyleKey.fillColor
            }
        }

        return styleKeys
    }
}

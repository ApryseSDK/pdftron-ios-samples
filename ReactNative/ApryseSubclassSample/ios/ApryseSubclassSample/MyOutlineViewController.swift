//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

import UIKit
import Tools

class MyOutlineViewController: PTOutlineViewController {

override var isReadonly: Bool
  {
    get {
      return true
    }
    set {
      super.isReadonly = newValue
    }
  }

}

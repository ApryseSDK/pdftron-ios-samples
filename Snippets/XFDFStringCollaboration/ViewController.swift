//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

import PDFNet
import Tools
import UIKit

class ViewController: UIViewController {

    let userIdentifier = "Local Author"
    
    var pdfViewCtrl: PTPDFViewCtrl?
    var toolManager: PTToolManager?
    var collaborationManager: PTBaseCollaborationManager?
    var collaborationServer: XFDFCollaborationServer?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Initialize PDFNet.
        PTPDFNet.initialize("<YOUR-LICENSE-KEY-HERE>")

        self.view.backgroundColor = UIColor(red:0.7, green:0.7, blue:0.7, alpha: 1.0)
        
        // Create a PTPDFViewCtrl and add it to the view.
        let pdfViewCtrl = PTPDFViewCtrl(frame: self.view.bounds)
        pdfViewCtrl.delegate = self
        
        pdfViewCtrl.setZoomLimits(e_trn_zoom_limit_relative, minimum: 1.0, maxiumum: 50.0)
        pdfViewCtrl.setBackgroundColor(0, g: 0, b: 0, a: 0)
        
        pdfViewCtrl.autoresizingMask = [.flexibleWidth, .flexibleHeight];
        self.view.addSubview(pdfViewCtrl)
        
        self.pdfViewCtrl = pdfViewCtrl
                
        // Add the toolmanager (used to implement text selection, annotation editing, etc.).
        self.toolManager = PTToolManager(pdfViewCtrl: pdfViewCtrl)
        pdfViewCtrl.toolDelegate = self.toolManager

        self.toolManager?.delegate = self

        // Restrict editing annotations made by other users/authors.
        self.toolManager?.isAnnotationAuthorCheckEnabled = true
        
        // Open the PDF document included in the bundle with the PTPDFViewCtrl.
        let docPath = Bundle.main.path(forResource: "mech", ofType: "pdf")
        let doc: PTPDFDoc = PTPDFDoc(filepath: docPath!)
        pdfViewCtrl.setDoc(doc)
        
        // Create an XFDF collaboration manager.
        let collaborationManager = PTBasicXFDFCollaborationManager(toolManager: toolManager!,
                                                                   userId: userIdentifier)
        self.collaborationManager = collaborationManager
        
        // Create a collaboration server backend instance.
        let collaborationServer = XFDFCollaborationServer()
        // The userID and documentID *must* be set before registering the server backend with the
        // collaboration manager.
        collaborationServer.userID = userIdentifier
        collaborationServer.documentID = docPath
        self.collaborationServer = collaborationServer
        
        // Register the server backend component and tell the backend that the document is loaded.
        collaborationManager.registerServerCommunicationComponent(collaborationServer)
        collaborationServer.documentLoaded()
    }
    
    @objc
    func showAnnotationReplies() {
        guard let collaborationManager = collaborationManager else {
            return
        }
        
        // Get the selected annotation and page number.
        guard let tool = toolManager?.tool,
              let selectedAnnotation = tool.currentAnnotation else {
            // No selected annotation.
            return
        }
        let selectedAnnotationPageNumber = tool.annotationPageNumber
        guard selectedAnnotationPageNumber > 0 else {
            return
        }
        
        // Get the selected annotation's identifier and screen rect.
        var selectedAnnotationIdentifier: String? = nil
        var selectedAnnotationRect: CGRect? = nil
        try? pdfViewCtrl?.docLockRead({ (pdfDoc) in
            selectedAnnotationIdentifier = selectedAnnotation.getUniqueIDAsString()
            if let screenRect = pdfViewCtrl?.getScreenRect(for: selectedAnnotation,
                                                           page_num: Int32(selectedAnnotationPageNumber)) {
                screenRect.normalize()
                
                let x1 = screenRect.getX1()
                let y1 = screenRect.getY1()
                let x2 = screenRect.getX2()
                let y2 = screenRect.getY2()
                
                let x = min(x1, x2)
                let y = min(y1, y2)
                let width = max(x1, x2) - x
                let height = max(y1, y2) - y
                
                selectedAnnotationRect = CGRect(x: x, y: y, width: width, height: height)
            }
        })
        guard selectedAnnotationIdentifier != nil,
              selectedAnnotationRect != nil else {
            // Failed to get selected annotation identifier or rect.
            return
        }
        
        // Create an annotation reply view controller.
        // NOTE: The same view controller instance can be used for subsequent presentations.
        let replyController = PTCollaborationAnnotationReplyViewController(collaborationManager: collaborationManager)
        replyController.currentAnnotationIdentifier = selectedAnnotationIdentifier
        
        // Embed the annotation reply view controller in a navigation controller.
        let navigationController = UINavigationController(rootViewController: replyController)

        // Optional: Show the annotation reply view controller in a popover when appropriate.
        navigationController.modalPresentationStyle = .popover
        if let popoverPresentationController = navigationController.popoverPresentationController {
            popoverPresentationController.sourceView = pdfViewCtrl
            popoverPresentationController.sourceRect = selectedAnnotationRect!
        }
        
        present(navigationController, animated: true, completion: nil)
    }
    
}

extension ViewController: PTPDFViewCtrlDelegate {
    
}

extension ViewController: PTToolManagerDelegate {
    
    func viewController(for toolManager: PTToolManager) -> UIViewController {
        return self
    }
    
    func toolManager(_ toolManager: PTToolManager, shouldShowMenu menuController: UIMenuController, forAnnotation annotation: PTAnnot?, onPageNumber pageNumber: UInt) -> Bool {
        addCommentsMenuItem(to: menuController, forAnnotation: annotation, onPageNumber: pageNumber)
        return true
    }
    
    func addCommentsMenuItem(to menuController: UIMenuController, forAnnotation annotation: PTAnnot?, onPageNumber pageNumber: UInt) {
        // Should the Comments menu item be added to the menu?
        guard shouldAddCommentsMenuItem(to: menuController, for: annotation, on: pageNumber) else {
            return
        }
        
        let commentsMenuItem = UIMenuItem(title: NSLocalizedString("Comments",
                                                                   comment: "Comments menu item title"),
                                          action: #selector(showAnnotationReplies))
        
        var menuItems = menuController.menuItems ?? []
        
        // Replace the "Note" menu item in the list of menu items, if present.
        let noteMenuItemIndex = menuItems.firstIndex(where: { (menuItem) -> Bool in
            return menuItem.action == #selector(PTTool.editSelectedAnnotationNote)
        })
        if let commentsMenuItemIndex = noteMenuItemIndex {
            menuItems[commentsMenuItemIndex] = commentsMenuItem
        } else {
            menuItems.insert(commentsMenuItem, at: 0)
        }
        
        menuController.menuItems = menuItems
    }
    
    func shouldAddCommentsMenuItem(to menuController: UIMenuController, for annotation: PTAnnot?, on pageNumber: UInt) -> Bool {
        // Skip for long-press menu (no annotation selected).
        guard annotation != nil else {
            return false
        }
        
        // Do not replace menu item before the collaboration manager is loaded.
        guard collaborationManager != nil else {
            return false
        }
        
        guard let menuItems = menuController.menuItems else {
            // There are no existing menu items, so the Comments item should be added.
            return true
        }
        
        // Find the "Note" menu item in the list of menu items.
        let noteMenuItem = menuItems.first(where: { (menuItem) -> Bool in
            return menuItem.action == #selector(PTTool.editSelectedAnnotationNote)
        })
        if noteMenuItem != nil {
            return true
        }
        
        // Ensure that the Comments menu item is not added more than once.
        let commentsMenuItem = menuItems.first(where: { (menuItem) -> Bool in
            return menuItem.action == #selector(showAnnotationReplies)
        })
        return commentsMenuItem == nil
    }
    
}

class XFDFCollaborationServer: NSObject, PTCollaborationServerCommunication {
    
    static let initialXFDF = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><xfdf xmlns=\"http://ns.adobe.com/xfdf/\" xml:space=\"preserve\"><annots></annots></xfdf>"
    
    var collaborationManager: PTBaseCollaborationManager?
    
    func localAnnotationAdded(_ collaborationAnnotation: PTCollaborationAnnotation) {
        // Export the updated XFDF for the document.
        exportXFDF()
    }
    
    func localAnnotationModified(_ collaborationAnnotation: PTCollaborationAnnotation) {
        // Export the updated XFDF for the document.
        exportXFDF()
    }
    
    func localAnnotationRemoved(_ collaborationAnnotation: PTCollaborationAnnotation) {
        // Export the updated XFDF for the document.
        exportXFDF()
    }
    
    func exportXFDF() {
        guard let collaborationManager = collaborationManager else {
            return
        }
        
        // Get the updated XFDF from the document.
        // Alternatively, collaborationManager.getLastXFDFCommand() can be used to get the XFDF
        // command string containing only the most recent loocal change(s) to the document.
        let xfdfString = try? collaborationManager.exportXFDFString()
        
        // Upload the updated XFDF string to server, etc.
        print(String(describing: xfdfString))
    }
    
    func documentLoaded() {
        collaborationManager?.importAnnotations(withXFDFString: XFDFCollaborationServer.initialXFDF)
    }
    
    var userID: String?
    
    var documentID: String?
    
}

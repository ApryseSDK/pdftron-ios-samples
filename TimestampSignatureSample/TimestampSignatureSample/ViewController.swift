//
//  ViewController.swift
//  TimestampSignatureSample
//
//  Created by Yifan Zhang on 2021-12-06.
//

import UIKit
import PDFNet
import Tools

class ViewController: UIViewController {
    
    let pdfController = PTDocumentController()
    
    override init(nibName nibNameOrNil: String?, bundle nibBundleOrNil: Bundle?) {
        super.init(nibName: nibNameOrNil, bundle: nibBundleOrNil)
        
        PTOverrides.overrideClass(PTDigitalSignatureTool.self, with: DigitalSignatureTool.self)
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
        
        PTOverrides.overrideClass(PTDigitalSignatureTool.self, with: DigitalSignatureTool.self)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        pdfController.toolGroupIndicatorView.isHidden = true
        
        guard let items = pdfController.toolGroupManager.insertItemGroup.barButtonItems else {
            pdfController.toolGroupManager.selectedGroup = pdfController.toolGroupManager.viewItemGroup
            return
        }
        
        for item in items {
            if let item = item as? PTToolBarButtonItem {
                if item.toolClass == DigitalSignatureTool.self {
                    pdfController.toolGroupManager.insertItemGroup.barButtonItems = [item]
                    break
                }
            }
        }
        pdfController.toolGroupManager.selectedGroup = pdfController.toolGroupManager.insertItemGroup
        pdfController.delegate = self
        if let path = Bundle.main.path(forResource: "blank", ofType: "pdf"), let doc = PTPDFDoc(filepath: path) {
            pdfController.openDocument(with: doc)
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        let navController = UINavigationController(rootViewController: pdfController)
        navController.modalPresentationStyle = .fullScreen
        present(navController, animated: true, completion: nil)
    }
}

extension ViewController: PTDocumentControllerDelegate {
    func documentControllerDidOpenDocument(_ documentController: PTDocumentController) {
        guard let doc = documentController.document else { return }
        let page = doc.getPage(1)
        
        let sigField = doc.createDigitalSignatureField("TimestampSignature")
        let signature = PTSignatureWidget.create(withDigitalSignatureField: doc, pos: PTPDFRect(x1: 100, y1: 500, x2: 500, y2: 300), field: sigField)
        signature?.refreshAppearance()
        page?.annotPushBack(signature)
        
        documentController.pdfViewCtrl.update()
    }
}


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
        pdfController.toolGroupManager.selectedGroup = pdfController.toolGroupManager.viewItemGroup
        pdfController.delegate = self
        if let path = Bundle.main.path(forResource: "blank", ofType: "pdf"), let doc = PTPDFDoc(filepath: path) {
            pdfController.openDocument(with: doc)
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        let navController = UINavigationController(rootViewController: pdfController)
        navController.navigationBar.isTranslucent = false
        navController.modalPresentationStyle = .fullScreen
        present(navController, animated: true, completion: nil)
    }
}

extension ViewController: PTDocumentControllerDelegate {
    func documentControllerDidOpenDocument(_ documentController: PTDocumentController) {
        guard let doc = documentController.document else { return }
        let page = doc.getPage(1)
        
        let sigField = doc.createDigitalSignatureField("TimestampSignature")
        let signature = PTSignatureWidget.create(withDigitalSignatureField: doc, pos: PTPDFRect(x1: 0, y1: 100, x2: 200, y2: 150), field: sigField)
        signature?.refreshAppearance()
        page?.annotPushBack(signature)
        doc.pagePushBack(page)
    }
}

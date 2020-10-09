//
//  ViewController.swift
//  CADViewer
//
//  Created by PDFTron on 2020-10-08.
//

import UIKit
import PDFNet
import Tools

class ViewController: UIViewController {

    override func viewDidAppear(_ animated: Bool) {
        // Do any additional setup after loading the view.
        super.viewDidAppear(animated)
        
        let pdfController = PTDocumentController()
        
        let navController = UINavigationController(rootViewController: pdfController)
        navController.navigationBar.isTranslucent = false
        navController.modalPresentationStyle = UIModalPresentationStyle.fullScreen
        self.present(navController, animated: true, completion: nil)
        
    }


}


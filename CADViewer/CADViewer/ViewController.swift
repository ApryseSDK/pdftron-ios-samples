//
//  ViewController.swift
//  CADViewer
//
//  Created by PDFTron on 2020-10-08.
//

import UIKit
import PDFNet
import Tools

let DWG_URL = "https://pdftron.s3.amazonaws.com/downloads/pl/visualization_condominium_with_skylight.dwg";

let BASE_URL = "https://demo.pdftron.com/"; // Your server root

class ViewController: UIViewController {
    
    let pdfController = PTDocumentController()

    override func viewDidAppear(_ animated: Bool) {
        // Do any additional setup after loading the view.
        super.viewDidAppear(animated)
        
        
        
        let navController = UINavigationController(rootViewController: pdfController)
        navController.navigationBar.isTranslucent = false
        navController.modalPresentationStyle = UIModalPresentationStyle.fullScreen
        self.present(navController, animated: true, completion: nil)
        
        displayCADFile(URL(string: DWG_URL)!)
        
    }
    
    func displayCADFile(_ cadFileUrl : URL) {
        // stuff
        
//        let urlRequest = MutableURLRequest()
//
//        urlRequest.httpMethod = "GET"
//        urlRequest.cachePolicy = .reloadIgnoringLocalAndRemoteCacheData
        
        
        
        var urlComponents = URLComponents(url: URL(string: BASE_URL)!, resolvingAgainstBaseURL: true)
        
        urlComponents?.path = "/blackbox/GetPDF"
        
        let qURI = URLQueryItem(name:"uri", value:DWG_URL)
        let qEXT = URLQueryItem(name:"ext", value:"dwg")
        
        urlComponents?.queryItems = [qURI, qEXT]
        
        guard let url = urlComponents?.url else {
            return
          }
        
        let defaultSession = URLSession(configuration: .default)
        
        var dataTask: URLSessionDataTask?

        
        dataTask =
            defaultSession.dataTask(with: url) { [weak self] data, response, error in
            defer {
              dataTask = nil
            }
            // 5
            if let error = error {
              print("DataTask error: " + error.localizedDescription + "\n")
            } else if
              let data = data,
              let response = response as? HTTPURLResponse,
              response.statusCode == 200 {
                

                struct Response: Codable { // or Decodable
                  let uri: String
                }

                var res : Array<Response> = []
                do {
                     res = try JSONDecoder().decode([Response].self, from: data)
                    print(res.first!.uri)
                  } catch let error {
                     print(error)
                  }
                       
                
              // 6
              DispatchQueue.main.async {
                // open doc
                let docLocation = URL(string: BASE_URL+"/blackbox/"+res.first!.uri)!
                self?.pdfController.openDocument(with: docLocation)
              }
            }
          }
          // 7
          dataTask?.resume()
        
    }


}


//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

import UIKit
import Tools

class ViewController: UITableViewController {

    var toolbarSwitcherHidden = false
    var toolbarsEnabled:[Bool] = [Bool]()
    var selectedGroupIndex:Int = 0

    var documentController = PTDocumentController()

    override func viewDidLoad() {
        super.viewDidLoad()
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "reuseIdentifier")
        toolbarsEnabled = [Bool]()
        for _ in documentController.toolGroupManager.groups {
            toolbarsEnabled.append(true)
        }

        let showViewerItem = UIBarButtonItem(title: "Show Viewer", style: .plain, target: self, action: #selector(showViewer))
        navigationItem.rightBarButtonItem = showViewerItem
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        // reset the document controller
        documentController = PTDocumentController()
    }

    @objc func showViewer(){
        // Show or hide the Toolbar switcher
        documentController.toolGroupIndicatorView.isHidden = toolbarSwitcherHidden

        // Disable selected groups
        documentController.toolGroupManager.groups = self.availableGroups

        // Select specific group
        documentController.toolGroupManager.selectedGroup = documentController.toolGroupManager.groups[self.selectedGroupIndex]

        // Open a file from URL.
        let fileURL: URL = URL(string:"https://pdftron.s3.amazonaws.com/downloads/pl/sample.pdf")!
        documentController.openDocument(with: fileURL)

        let navigationController = UINavigationController(rootViewController: documentController)
        navigationController.modalPresentationStyle = .fullScreen
        navigationController.navigationBar.isTranslucent = false
        navigationController.toolbar.isTranslucent = false

        let closeButton = UIBarButtonItem(barButtonSystemItem: .close, target: self, action: #selector(dismissViewer))
        documentController.navigationItem.leftBarButtonItems?.insert(closeButton, at: 0)

        // Show navigation (and document) controller.
        self.present(navigationController, animated: true, completion: nil)
    }

    @objc func dismissViewer() {
        self.dismiss(animated: true)
    }

    var availableGroups:[PTToolGroup] {
        var groups = documentController.toolGroupManager.groups
        for i in (0..<groups.count).reversed() {
            if toolbarsEnabled[i] == false {
                groups.remove(at: i)
            }
        }
        return groups
    }

    override func numberOfSections(in tableView: UITableView) -> Int {
        // toolbar switcher enabled, toolbars enabled, selected toolbar
        return 3
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        switch section {
        case 0:
            // Toolbar Switcher Enabled
            return 1
        case 1:
            // Available Toolbars
            return self.documentController.toolGroupManager.groups.count
        case 2:
            // Selected Tool Group
            return self.availableGroups.count
        default:
            return 0
        }
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "reuseIdentifier", for: indexPath)
        var config = cell.defaultContentConfiguration()

        let toggle = UISwitch()
        switch indexPath.section {
        case 0:
            config.text = "Toolbar Switcher Hidden"
            toggle.isOn = toolbarSwitcherHidden
            toggle.addTarget(self, action: #selector(self.toolbarHiddenToggled(_:)), for: .valueChanged)
            cell.accessoryView = toggle
        case 1:
            if let toolGroupTitle = self.documentController.toolGroupManager.groups[indexPath.row].title {
                config.text = "\(toolGroupTitle) Toolbar Enabled"
            }
            toggle.isOn = true
            toggle.addTarget(self, action: #selector(self.toolbarSwitchToggled(_:)), for: .valueChanged)
            toggle.tag = indexPath.row
            cell.accessoryView = toggle
        case 2:
            let group = self.availableGroups[indexPath.row]
            config.text = group.title
            cell.accessoryType = indexPath.row == self.selectedGroupIndex ? .checkmark : .none
        default:
            break
        }
        cell.contentConfiguration = config
        return cell
    }

    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        return section == 2 ? "Selected Group" : nil
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        if indexPath.section == 2 {
            self.selectedGroupIndex = indexPath.row
            tableView.reloadSections(IndexSet(integer: 2), with: .automatic)
        }
    }
}

extension ViewController
{
    @objc func toolbarHiddenToggled(_ sender : UISwitch!){
        self.toolbarSwitcherHidden = sender.isOn
    }

    @objc func toolbarSwitchToggled(_ sender : UISwitch!){
        toolbarsEnabled[sender.tag] = sender.isOn
        tableView.reloadSections(IndexSet(integer: 2), with: .automatic)
    }
}

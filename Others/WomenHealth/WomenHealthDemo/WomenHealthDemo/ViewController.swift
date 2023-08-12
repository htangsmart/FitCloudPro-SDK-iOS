//
//  ViewController.swift
//  WomenHealthDemo
//
//  Created by pcjbird on 7/12/23.
//

import UIKit
import WomenHealth

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }


    @IBAction func OnGoMainSettings(_ sender: Any) {
        WomenHealthModule.enterMainSettings(from: self)
    }
    
    @IBAction func OnEnterCurrentMode(_ sender: Any) {
        WomenHealthModule.enterCurrentModeHome(from: self)
    }
    
    @IBAction func OnExportDB(_ sender: Any) {
        WomenHealthModule.exportDB(self)
    }
    
}


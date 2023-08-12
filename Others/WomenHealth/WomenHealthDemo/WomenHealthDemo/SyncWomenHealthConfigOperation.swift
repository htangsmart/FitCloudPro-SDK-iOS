//
//  SyncWomenHealthConfigOperation.swift
//  WomenHealthDemo
//
//  Created by pcjbird on 7/6/23.
//

import UIKit
import FitCloudKit

internal class SyncWomenHealthConfigOperation: SmartWatchOperation {

    
    private var _whSetting: FitCloudWomenHealthSetting
    
    private var _executing: Bool = false
    private var _finished: Bool = false
    
    override class func identifier() -> String! {
        return "SyncWomenHealthConfigOperation"
    }
    
    override var isConcurrent: Bool {
        return true
    }
    
    override var isExecuting: Bool {
        return _executing
    }
    
    override var isFinished: Bool {
        return _finished
    }
    
    init(_ whSetting: FitCloudWomenHealthSetting) {
        self._whSetting = whSetting
    }
    
    override func start() {
        if (self.isCancelled) {
            self.willChangeValue(forKey: "isFinished")
            self._finished = true
            self.didChangeValue(forKey: "isFinished")
            return
        }
        self.willChangeValue(forKey: "isExecuting")
        Thread.detachNewThreadSelector(#selector(main), toTarget: self, with: nil)
        self._executing = true
        self.didChangeValue(forKey: "isExecuting")
        
    }
    
    override func main() {
        print("开始执行同步女性健康配置Operation...")
        if(FitCloudKit.deviceIdle()){
#if targetEnvironment(simulator)
            print("模拟器不支持该操作...")
            self.finish()
#else
            FitCloudKit.setWomenHealthConfig(self._whSetting) { _, _ in
                self.finish()
            }
#endif
            return
        }
        print("当前手表未连接或繁忙...")
        self.finish()
    }
    
    func finish() {
    
        self.willChangeValue(forKey: "isExecuting")
        self._executing = false
        self.didChangeValue(forKey: "isExecuting")
        
        self.willChangeValue(forKey: "isFinished")
        self._finished = true
        self.didChangeValue(forKey: "isFinished")
        
        print("同步女性健康配置Operation执行完毕！")
        if let internalCompletionBlock = self.internalCompletionBlock {
            internalCompletionBlock()
        }
    }
}

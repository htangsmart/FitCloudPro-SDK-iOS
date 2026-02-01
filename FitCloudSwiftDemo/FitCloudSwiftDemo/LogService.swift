//
//  LogService.swift
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2026-02-01.
//

import Foundation
import LogMate

class LogService : NSObject, LoggableProtocol {
    static let shared = LogService()
    
    func onLogMessage(_ message: String, level: LogMateLevel, subsystem: String?, category: String?) {
        XLOG_INFO("\(message)")
    }
}

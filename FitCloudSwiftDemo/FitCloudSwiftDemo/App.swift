//
//  App.swift
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2/19/25.
//

import Foundation


// Logging utilities for different severity levels
// Each function includes file, function and line information in the log message

/// Debug level logging
func XLOG_DEBUG(_ message: String,
                file: String = #file,
                function: String = #function,
                line: Int = #line) {
    let logMessage = "[\(URL(fileURLWithPath: file).lastPathComponent):\(line)] \(function) - \(message)"
    XLSharedFacility.logMessage(logMessage, withTag: nil, level: .logLevel_Debug)
}

/// Verbose level logging
func XLOG_VERBOSE(_ message: String,
                  file: String = #file,
                  function: String = #function,
                  line: Int = #line) {
    let logMessage = "[\(URL(fileURLWithPath: file).lastPathComponent):\(line)] \(function) - \(message)"
    XLSharedFacility.logMessage(logMessage, withTag: nil, level: .logLevel_Verbose)
}

/// Info level logging
func XLOG_INFO(_ message: String,
               file: String = #file,
               function: String = #function,
               line: Int = #line) {
    let logMessage = "[\(URL(fileURLWithPath: file).lastPathComponent):\(line)] \(function) - \(message)"
    XLSharedFacility.logMessage(logMessage, withTag: nil, level: .logLevel_Info)
}

/// Warning level logging
func XLOG_WARNING(_ message: String,
                  file: String = #file,
                  function: String = #function,
                  line: Int = #line) {
    let logMessage = "[\(URL(fileURLWithPath: file).lastPathComponent):\(line)] \(function) - \(message)"
    XLSharedFacility.logMessage(logMessage, withTag: nil, level: .logLevel_Warning)
}

/// Error level logging
func XLOG_ERROR(_ message: String,
                file: String = #file,
                function: String = #function,
                line: Int = #line) {
    let logMessage = "[\(URL(fileURLWithPath: file).lastPathComponent):\(line)] \(function) - \(message)"
    XLSharedFacility.logMessage(logMessage, withTag: nil, level: .logLevel_Error)
}

/// Exception level logging
func XLOG_EXCEPTION(_ message: String,
                    file: String = #file,
                    function: String = #function,
                    line: Int = #line) {
    let logMessage = "[\(URL(fileURLWithPath: file).lastPathComponent):\(line)] \(function) - \(message)"
    XLSharedFacility.logMessage(logMessage, withTag: nil, level: .logLevel_Exception)
}

/// Abort level logging
func XLOG_ABORT(_ message: String,
                file: String = #file,
                function: String = #function,
                line: Int = #line) {
    let logMessage = "[\(URL(fileURLWithPath: file).lastPathComponent):\(line)] \(function) - \(message)"
    XLSharedFacility.logMessage(logMessage, withTag: nil, level: .logLevel_Abort)
}

func getMainWindow() -> UIWindow {
    if #available(iOS 13.0, *) {
        // iOS13 及以上：优先取第一个带 scene 的 window
        if let windowScene = UIApplication.shared.connectedScenes.first(where: { $0 is UIWindowScene }) as? UIWindowScene {
            return windowScene.windows.first ?? UIWindow()
        }
    }
    // iOS13 以下或兜底：使用 keyWindow
    return UIApplication.shared.keyWindow ?? UIWindow()
}

func SwiftToast(_ message: String,
                atView view: UIView? = nil) {
    guard let parentView = view ?? getMainWindow().rootViewController?.view else {
        XLOG_ERROR("toast message `\(message)` failed, can not find parent view.")
        return
    }
    parentView.makeToast(message, duration: 3.0, position: CSToastPositionTop)
}

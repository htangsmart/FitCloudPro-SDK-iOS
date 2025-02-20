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

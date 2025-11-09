//
//  AppNotifcations.swift
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 11/9/25.
//

import Foundation

@objc final class AppNotifcations: NSObject
{
    
    @objc static let aiPhotoDidChange = Notification.Name("aiPhotoDidChange")

    @objc static let aiWatchfaceProgressTips = Notification.Name("aiWatchfaceProgressTips")

    @objc static let aiWatchfaceBinDidChange = Notification.Name("aiWatchfaceBinDidChange")
}

//
//  RTKAccessoryManager.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2020/3/3.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKAccessory.h"
#else
#import <RTKLEFoundation/RTKAccessory.h>
#endif


NS_ASSUME_NONNULL_BEGIN

@class RTKAccessoryManager;
@protocol RTKAccessoryManagerConnectionListener <NSObject>
/**
 * Tell the delegate object that a new accessory connection occured.
 */
- (void)accessoryManager:(RTKAccessoryManager *)manager didDetectConnectionOf:(RTKAccessory *)accessory;

/**
 * Tell the delegate object that an accessory disconnected.
 */
- (void)accessoryManager:(RTKAccessoryManager *)manager didDetectDisconnectionOf:(RTKAccessory *)accessory;

@end



/**
 * An object that monitoring iAP accessory connection and disconnection events.
 */
DEPRECATED_ATTRIBUTE
@interface RTKAccessoryManager : NSObject

/**
 * Initilize with specific protocol.
 */
- (instancetype)initWithProtocolString:(nullable NSString *)protocol;

/**
 * A list of all connected accessories that using the same protocol.
 */
@property (nonatomic, readonly) NSArray <RTKAccessory*> *connectedAccessories;

/**
 * The delegate object to notify connection events.
 */
@property (weak) id <RTKAccessoryManagerConnectionListener> delegate;

/**
 * The specfic protocol this manager interest in.
 */
@property (nonatomic, readonly) NSString *protocol;

@end


NS_ASSUME_NONNULL_END

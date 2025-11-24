//
//  NSData+KKAES.h
//  SecurityiOS
//
//  Created by cocoa on 16/12/15.
//  Copyright © 2016年 dev.keke@gmail.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Defines methods to encrypt or decrypt data using AES algorithm.
 */
@interface NSData (KKAES)

/**
 * Returns a data that is encrypted using AES Algorithm with CBC mode.
 *
 * @param key The AES key. Must be 16, or 24, or 32 bytes in length.
 * @param iv A data containing initialization vector bytes. Must be 16 bytes in length.
 */
- (NSData *)AES_CBC_EncryptWith:(NSData *)key iv:(NSData *)iv;


/**
 * Returns a data that is decrypted using AES Algorithm with CBC mode.
 *
 * @param key The AES key. Must be 16, or 24, or 32 bytes in length.
 * @param iv A data containing initialization vector bytes. Must be 16 bytes in length.
 */
- (NSData *)AES_CBC_DecryptWith:(NSData *)key iv:(NSData *)iv;


/**
 * Returns a data that is encrypted using AES Algorithm with ECB mode.
 *
 * @param key The AES key. Must be 16, or 24, or 32 bytes in length.
 */
- (NSData *)AES_ECB_EncryptWith:(NSData *)key;

/**
 * Returns a data that is decrypted using AES Algorithm with ECB mode.
 *
 * @param key The AES key. Must be 16, or 24, or 32 bytes in length.
 */
- (NSData *)AES_ECB_DecryptWith:(NSData *)key;


/**
 * Returns a data by encrypting availble bytes using AES Algorithm with ECB mode.
 *
 * @param key The AES key. Must be 16, or 24, or 32 bytes in length.
 * @discussion The returned data has the same length as receiver.
 */
- (NSData *)dataByAESEncryptAvailableBytesWith:(NSData *)key;

/**
 * Returns a data by decrypting availble bytes using AES Algorithm with ECB mode.
 *
 * @param key The AES key. Must be 16, or 24, or 32 bytes in length.
 * @discussion The returned data has the same length as receiver.
 */
- (NSData *)dataByAESDecryptAvailableBytesWith:(NSData *)key;

@end

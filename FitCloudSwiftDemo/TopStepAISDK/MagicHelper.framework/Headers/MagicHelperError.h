

#ifndef MagicHelperError_h
#define MagicHelperError_h

typedef NS_ENUM(NSUInteger, MagicErrorCode) {
    
    MagicNoInitSuccess = 1,/**< 未初始化或者初始化未成功 */
    MagicParamsError,/**< 参数错误 */
    MagicParamsServiceReturnError,/**< 服务器返回参数错误 */
    
    MagicTaskError,          /**任务生成失败**/
};

#endif /* MagicHelperError_h */

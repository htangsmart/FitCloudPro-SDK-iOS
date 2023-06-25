# 音乐推送 iOS 开发指南

**Step 1**

检查手表的电量，并获得升级的 dfuPeripheral，如果失败，我想你不应该继续接下来的流程。

```objc
[FitCloudKit enterDFUModeWithBlock:^(BOOL succeed, CBPeripheral *dfuPeripheral, FITCLOUDCHIPVENDOR chipVendor, NSError *error) {
}];
```

**Step 2**

创建 MusicBridge:

```
 [FitCloudDFUKit setDelegate:self];
FitCloudMusicBridge* musicBridge = [[FitCloudMusicBridge alloc] initWithPeripheral:musicPeripheral chipVendor:(FITCLOUDDFUCHIPVENDOR)chipVendor delegate:self];
```

添加 KVO：

```
[musicBridge addObserver:self forKeyPath:@"songs" options:NSKeyValueObservingOptionNew context:nil];
[musicBridge addObserver:self forKeyPath:@"totalSpace" options:NSKeyValueObservingOptionNew context:nil];
[musicBridge addObserver:self forKeyPath:@"freeSpace" options:NSKeyValueObservingOptionNew context:nil];

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
    if(object == self.musicBridge)
    {
        if([keyPath isEqualToString:@"songs"])
        {

        }

        else if ([keyPath isEqualToString:@"totalSpace"])
        {

        }
        else if ([keyPath isEqualToString:@"freeSpace"])
        {

        }
    }
}
```

实现代理：

```
-(void)bridge:(FitCloudMusicBridge *)bridge didActivate:(BOOL)success error:(NSError *)error
{
    XLOG_INFO(@"%@", APP_LOG_STRING(@"MusicBridge Activate: %@...", success ? @"成功" : @"失败"));
}

-(void)bridge:(FitCloudMusicBridge *)bridge didSendSong:(NSString *)songFile progress:(NSProgress *)progress
{

}
```

激活 MusicBridge:

```
[musicBridge activateWithCompletionHandler:nil];
```

获取 SD 卡存储空间信息：

```
 [musicBridge getSDSpaceWithCompletionHandler:^(BOOL success, NSError * _Nullable error, NSUInteger totalSpace, NSUInteger freeSpace) {

 }];
```

获取歌曲列表:

```
[musicBridge getSongsWithCompletionHandler:^(BOOL success, NSError * _Nullable error, NSArray<FitCloudSong *> * _Nullable songs) {

}];
```

添加歌曲：

```
[musicBridge addNewSongsWithFiles:toSendSongPaths completionHandler:^(BOOL success, NSError * _Nullable error) {

}];
```

删除歌曲：

```
[musicBridge deleteSong:song withCompletionHandler:^(BOOL success, NSError * _Nullable error) {

}];
```

处理 FitCloudDFUDelegate 与日志回调信息。当升级成功或失败，您需要监听 DFU 模式下的回连通知，就像这样：

```objc
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnReconnectWithDFUMode:) name:FITCLOUDEVENT_PERIPHERAL_RECONNECTEDWITHDFUMODE_NOTIFY object:nil];
}

-(void)OnReconnectWithDFUMode:(NSNotification*)notification
{
    NSLog(@"%@", APP_LOG_STRING(@"手表重启成功，此次推送%@。", _lastDFUSucceed ? @"成功" : @"失败"));
}

/**
 *@brief 记录日志数据
 *@param message 日志信息
 *@param level 日志等级
 */
-(void) OnLogMessage:(NSString*)message level:(FCDFUKLogLevel)level
{
    message = [[message stringByReplacingOccurrencesOfString:@"<" withString:@"["] stringByReplacingOccurrencesOfString:@">" withString:@"]"];
    if(level == FCDFUKLogLevel_Info)
    {
        XLOG_INFO(@"%@", message);
    }
    else if(level == FCDFUKLogLevel_Warning)
    {
        XLOG_WARNING(@"%@", message);
    }
    else if(level == FCDFUKLogLevel_Error)
    {
        XLOG_ERROR(@"%@", message);
    }
}
```

**Step 3**

当您决定不再推送音乐时，您需要调用以下方法，回到正常模式，当然此时会断开并重新连接手表。

```objc
[FitCloudKit exitDFUModeWithBlock:nil];
```

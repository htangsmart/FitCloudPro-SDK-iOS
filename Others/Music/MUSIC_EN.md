# Music Songs Push iOS Development Guide

**Step 1**

Check the battery level of the watch and obtain the upgraded dfuPeripheral. If it fails, I don't think you should proceed with the following process.

```objc
[FitCloudKit enterDFUModeWithBlock:^(BOOL succeed, CBPeripheral *dfuPeripheral, FITCLOUDCHIPVENDOR chipVendor, NSError *error) {
}];
```

**Step 2**

Create MusicBridge:

```
 [FitCloudDFUKit setDelegate:self];
FitCloudMusicBridge* musicBridge = [[FitCloudMusicBridge alloc] initWithPeripheral:musicPeripheral chipVendor:(FITCLOUDDFUCHIPVENDOR)chipVendor delegate:self];
```

Add KVO：

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

Implement the music bridge delegate：

```
-(void)bridge:(FitCloudMusicBridge *)bridge didActivate:(BOOL)success error:(NSError *)error
{
    XLOG_INFO(@"%@", APP_LOG_STRING(@"MusicBridge Activate: %@...", success ? @"Success" : @"Failed"));
}

-(void)bridge:(FitCloudMusicBridge *)bridge didSendSong:(NSString *)songFile progress:(NSProgress *)progress
{
    //observe the music song push progress
}
```

observe the music song push progress：

```
NSProgress* theProgress = xxx;
[theProgress addObserver:self forKeyPath:@"fractionCompleted" options:NSKeyValueObservingOptionNew context:nil];

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
    if(object == self.progress)
    {
        if([keyPath isEqualToString:@"fractionCompleted"])
        {
            CGFloat progress = MAX(MIN(self.progress.fractionCompleted, 1), 0);

        }
    }
}

```

Activate MusicBridge:

```
[musicBridge activateWithCompletionHandler:nil];
```

Get the SD storage space：

```
 [musicBridge getSDSpaceWithCompletionHandler:^(BOOL success, NSError * _Nullable error, NSUInteger totalSpace, NSUInteger freeSpace) {

 }];
```

Get music songs:

```
[musicBridge getSongsWithCompletionHandler:^(BOOL success, NSError * _Nullable error, NSArray<FitCloudSong *> * _Nullable songs) {

}];
```

Add music songs：

```
[musicBridge addNewSongsWithFiles:toSendSongPaths completionHandler:^(BOOL success, NSError * _Nullable error) {

}];
```

Delete music song：

```
[musicBridge deleteSong:song withCompletionHandler:^(BOOL success, NSError * _Nullable error) {

}];
```

Process the log:

```objc

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

Do something when you would like to stop the music push，

Remove KVO：

```
[musicBridge removeObserver:self forKeyPath:@"songs"];
[musicBridge removeObserver:self forKeyPath:@"totalSpace"];
[musicBridge removeObserver:self forKeyPath:@"freeSpace"];


 [theProgress removeObserver:self forKeyPath:@"fractionCompleted"];
```

Exit the dfu mode:

```objc
[FitCloudKit exitDFUModeWithBlock:nil];
```

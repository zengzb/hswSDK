# 好上网SDK IOS
##### 好上网致力于提供安全健康的网络环境，更多功能正在开发中，期待会更好

# 使用方法(Usage)



### 登录接口



如要使用好上网的所有服务，首先需要使用宽带账号或宽带绑定手机号与对应密码通过登录接口登录

```objective-c
[hswAPI login:@"test2" password:@"zzb12345678" complete:^(hswNWResponse *response){
    if (!response.success) {
        NSLog(@"error: %@\n", response.error.description);
    }
    hswUser *user = [hswAPI getUserInfo];
    NSLog(@"username: %@\n", user.username);
 }];
```

登录成功后，可以通过‘获取用户接口’获得用户的登记信息； 用户个人的基本信息，比如 用户名，电话号码，地址， 当前的网络模式，宽带账号和账号过期时间

# 公共对象(Public Objects)



### hswUser的属性



##### hswUser的属性:
```objective-c
@interface hswUser: NSObject
@property (nonatomic,retain) NSString *username;
@property (nonatomic,retain) NSString *teleNumber;
@property (nonatomic,retain) NSString *address;
@property (nonatomic,retain) NSString *account;
@property (nonatomic,retain) NSString *currentMode;
@property (nonatomic,retain) NSString *expiration;
```

如果登录失败，则可以通过hswNWResponse对象，了解具体失败的原因


### hswNWResponse



##### hswNWResponse的属性
```objective-c
@interface hswNWResponse: NSObject
@property (nonatomic,assign) BOOL success;
@property (nonatomic,retain) hswNWError *error;
```

##### 查看是否请求成功
```objective-c
if (!response.success) {
    //失败
}else{
    //成功
}
```
##### 查看具体失败的原因
```objective-c
if (!response.success) {
    NSLog(@"error: %@\n", response.error.description);
    //e.g. 账号或者密码错误
}
```

# 接口(API)



### 用户信息




### 获取用户接口:
```objective-c
hswUser *user = [hswAPI getUserInfo];
```

### 查看用户是否登录:
```objective-c
BOOL hasAuthenticated = [hswAPI hasAuthenticated];
```

### 更新用户信息:
```objective-c
[hswAPI updateUserInfo:@"testHSW" address:@"Lake Meixi Innovation Center, Yuelu, Changsha" complete:^(hswNWResponse *response){
    if (!response.success){
        NSLog(@"error: %@\n", response.error.description);
    }
    hswUser *user = [hswAPI getUserInfo];
    NSLog(@"username: %@\n", user.username);
}];
```

### 更改手机号时，发送绑定手机验证码:
```objective-c
[hswAPI sendCodeForTeleNumberUpdate:@"177777777777" complete:^(hswNWResponse *response){
    if (!response.success){
        NSLog(@"error: %@\n", response.error.description);
        return;
    }
    NSLog(@"验证码发送成功");
}];
```

### 更改绑定手机号
```objective-c
[hswAPI updateTeleNumber:@"177777777777" code:@"123456" complete:^(hswNWResponse *response){
    if (!response.success){
        NSLog(@"error: %@\n", response.error.description);
        return;
    }
    NSLog(@"修改手机号成功");
}];
```

### 更改密码
```objective-c
//密码格式至少6位，且必须包含数字和字母
[hswAPI changePsw:@"zzb123456" newPsw:@"zzb123456" complete:^(hswNWResponse *response){
    if (!response.success){
        NSLog(@"error: %@\n", response.error.description);
        return;
    }
    NSLog(@"修改密码成功");
}];
```

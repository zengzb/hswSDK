# 好上网SDK IOS
##### 好上网致力于提供安全健康的网络环境，更多功能正在开发中，期待会更好

# Usage

如要使用好上网的所有服务，首先需要使用宽带账号或宽带绑定手机号与对应密码通过登录接口登录

```objective-c
[hswAPI login:@"test2" password:@"888888" complete:^(hswNWResponse *response){
    if (!response.success) {
        NSLog(@"error: %@\n", response.error.description);
    }
    hswUser *user = [hswAPI getUserInfo];
    NSLog(@"username: %@\n", user.username);
 }];
```

登录后，可以通过‘获取用户接口’获得用户的登记信息； 用于存储个人的基本信息，比如 用户名，电话号码，地址， 当前的网络模式，宽带账号和账号过期时间

##### 获取用户接口
```objective-c
hswUser *user = [hswAPI getUserInfo];
```
##### hswUser的属性
```objective-c
@interface hswUser: NSObject
@property (nonatomic,retain) NSString *username;
@property (nonatomic,retain) NSString *teleNumber;
@property (nonatomic,retain) NSString *address;
@property (nonatomic,retain) NSString *account;
@property (nonatomic,retain) NSString *currentMode;
@property (nonatomic,retain) NSString *expiration;
```

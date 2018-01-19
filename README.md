# 好上网SDK IOS
##### 好上网致力于提供安全健康的网络环境，更多功能正在开发中，期待会更好

# 使用方法(Usage)



#### 登录接口



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

登录成功后，可以通过‘获取用户接口’获得用户的登记信息； 用户个人的基本信息，包括 用户名，电话号码，地址， 当前的网络模式，宽带账号和账号过期时间

# 公共对象(Public Objects)



#### hswUser的属性



##### hswUser的属性:
```objective-c
@interface hswUser: NSObject
@property (nonatomic,retain) NSString *username;
@property (nonatomic,retain) NSString *teleNumber;
@property (nonatomic,retain) NSString *address;
@property (nonatomic,retain) NSString *account;
@property (nonatomic) hswModeType currentMode;
@property (nonatomic,retain) NSString *expiration;
@end
```

如果登录失败，则可以通过hswNWResponse对象，了解具体失败的原因


#### hswNWResponse



##### hswNWResponse的属性
```objective-c
@interface hswNWResponse: NSObject
@property (nonatomic,assign) BOOL success;
@property (nonatomic,retain) hswNWError *error;
@end
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

#### 网络模式

##### 网络模式的所有类别
```objective-c
/*! @brief hswModeType enum type
 */
typedef enum {
    hswModeFree, //网络畅游模式
    hswModeEducation, //教育资源模式
    hswModeUnheathBlock, //不良内容拦截模式
    hswModeRewardCard   //奖励卡模式
} hswModeType;
```
##### 网络模式对象的属性和方法
```objective-c
@interface hswModeObject: NSObject
@property (nonatomic) hswModeType type;
@property (nonatomic,assign) BOOL selected;  //是否被选择

/*! @brief 初始化
 */
-(id)initWithType: (hswModeType)type selected:(BOOL)selected;

/*! @brief 获取模式文本名称
 *  @return 对应模式的名称文本
 */
-(NSString *)getModeName;
@end
```

# 接口(API)



## 用户信息



#### 获取用户接口:
```objective-c
hswUser *user = [hswAPI getUserInfo];
```

#### 获取用户最新信息:
```objective-c
[hswAPI getLatestUserInfo:^(hswNWResponse *response){
    if (!response.success) {
        NSLog(@"error: %@\n", response.error.description);
    }
    hswUser *user = [hswAPI getUserInfo];
    NSLog(@"username: %@\n", user.username);
}];
```

#### 查看用户是否登录:
```objective-c
BOOL hasAuthenticated = [hswAPI hasAuthenticated];
```

#### 更新用户信息:
```objective-c
[hswAPI updateUserInfo:@"testHSW" address:@"Lake Meixi Innovation Center, Yuelu, Changsha" complete:^(hswNWResponse *response){
    if (!response.success){
        NSLog(@"error: %@\n", response.error.description);
    }
    hswUser *user = [hswAPI getUserInfo];
    NSLog(@"username: %@\n", user.username);
}];
```

#### 更改手机号时，发送绑定手机验证码:
```objective-c
[hswAPI sendCodeForTeleNumberUpdate:@"177777777777" complete:^(hswNWResponse *response){
    if (!response.success){
        NSLog(@"error: %@\n", response.error.description);
        return;
    }
    NSLog(@"验证码发送成功");
}];
```

#### 更改绑定手机号
```objective-c
[hswAPI updateTeleNumber:@"177777777777" code:@"123456" complete:^(hswNWResponse *response){
    if (!response.success){
        NSLog(@"error: %@\n", response.error.description);
        return;
    }
    NSLog(@"修改手机号成功");
}];
```

#### 更改密码
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

## 时段控制

#### 时段控制对象

```objective-c
/*! @brief days of week
 */
typedef enum {
    hswTSDayOfWeekMonday = 0,  //周一
    hswTSDayOfWeekTuesday,  //周二
    hswTSDayOfWeekWednesday, //周三
    hswTSDayOfWeekThursday, //周四
    hswTSDayOfWeekFriday, //周五
    hswTSDayOfWeekSaturday, //周六
    hswTSDayOfWeekSunday //周日
} hswTSDayOfWeek;


/*! @brief hour of a day
 */
typedef enum {
    hswTSHourOfDay0To8 = 0, //从凌晨0:00到早8:00
    hswTSHourOfDay9,   //从8:00到9:00
    hswTSHourOfDay10,  //从9:00到10:00
    hswTSHourOfDay11,  //从10:00到11:00
    hswTSHourOfDay12,  //从11:00到12:00
    hswTSHourOfDay13,  //从12:00到13:00
    hswTSHourOfDay14,  //从13:00到14:00
    hswTSHourOfDay15,  //从14:00到15:00
    hswTSHourOfDay16,  //从15:00到16:00
    hswTSHourOfDay17,  //从16:00到17:00
    hswTSHourOfDay18,  //从17:00到18:00
    hswTSHourOfDay19,  //从18:00到19:00
    hswTSHourOfDay20,  //从19:00到20:00
    hswTSHourOfDay21,  //从20:00到21:00
    hswTSHourOfDay22,  //从21:00到22:00
    hswTSHourOfDay23,  //从22:00到23:00
    hswTSHourOfDay24   //从23:00到0:00
} hswTSHourOfDay;


/*! @brief 时段控制
 *  矩阵结构，通过索引查询本周各个时间段的管控开放状态
 */
@interface hswTimeSchedule: NSObject

-(instancetype)initWithRawData: (NSString *)rawDataString;

/*! @brief 获取礼拜几的某个时段的管控开放状态
 *  @param dayOfWeek 礼拜几
 *  @param hour hourOfDay 时段
 *  @return BOOL 该时段是否管控开放 YES->开放 NO->管控
 */
-(BOOL)getState: (hswTSDayOfWeek)dayOfWeek hourOfDay:(hswTSHourOfDay)hour;

/*! @brief 获取礼拜几的某个时段的管控开放状态
 *  @param startHour 从那个时段开始
 *  @param endHour To 到哪个时段
 *  @param dayOfWeek On 在礼拜几
 *  @return NSArray 该时段区间的各个时段的管控开放状态 [YES->开放 NO->管控]
 */
-(NSArray *)getStateFrom: (hswTSHourOfDay)startHour To:(hswTSHourOfDay)endHour On:(hswTSDayOfWeek)dayOfWeek;

/*! @brief 设置礼拜几的某个时段的管控开放状态
 *  @param dayOfWeek 礼拜几
 *  @param hour hourOfDay 时段
 */
-(void)setState:(BOOL)Status dayOfWeek:(hswTSDayOfWeek)dayOfWeek hourOfDay:(hswTSHourOfDay)hour;

/*! @brief 保存设置
 */
-(void)save:(void(^)(hswNWResponse *response))complete;

/*! @brief 重置本周所有时段设置
 */
-(void)resetAll;

/*! @brief 重置礼拜几的所有时段设置
 * @param dayOfWeek 礼拜几
 */
-(void)reset: (hswTSDayOfWeek)dayOfWeek;
@end
```

#### 获取最新时间管控
```objective-c
[hswAPI getCurrentTiemSchedule:^(hswTimeSchedule *timeSchedule, hswNWError *error){
    if (error != nil) {
        NSLog(@"error: %@\n", error.description);
        return;
    }
    //查询礼拜天0～8:00AM的时段控制状态
    BOOL state = [timeSchedule getState:hswTSDayOfWeekSunday hourOfDay:hswTSHourOfDay0To8];
    NSLog(@"state: %d\n", state);
    
    //查询礼拜五从0～2:00 PM的时段控制状态
    NSArray *arrayOfStates = [timeSchedule getStateFrom:hswTSHourOfDay0To8 To:hswTSHourOfDay14 On:hswTSDayOfWeekFriday];
    NSLog(@"arrayOfStates length: %lu", (unsigned long)arrayOfStates.count);
    
    //设置礼拜一8:00AM～9:00AM一个小时的时段管控为开放状态
    [timeSchedule setState:YES dayOfWeek:hswTSDayOfWeekMonday hourOfDay:hswTSHourOfDay9];
    
    //保存设置
    [timeSchedule save:^(hswNWResponse *response){
        if (!response.success){
            NSLog(@"error: %@\n", response.error.description);
            return;
        }
        NSLog(@"保存成功");
    }];
}];
```

## 功能


#### 网络模式

##### 获取所有功能列表
```objective-c
NSArray *features = [hswAPI getFeatures];
NSLog(@"共有%lu大功能", (unsigned long)features.count);
```

##### 获取网络模式列表
```objective-c
NSArray *modes = [hswAPI getModes];
NSLog(@"共有%lu大网络模式", (unsigned long)modes.count);
```

##### 获取个人最新当前网络模式
```objective-c
[hswAPI getCurrentMode:^(hswModeType type, hswNWError *error){
    if (error != nil) {
        //如果error不为空， 则默认的type为hswModeFree即网络畅游模式
        NSLog(@"error: %@\n", error.description);
        return;
    }
    NSLog(@"当前网络模式为%u", type);
}];
```

##### 模式切换
```objective-c
[hswAPI switchMode:hswModeUnheathBlock complete:^(hswNWResponse *response){
    if (!response.success){
        NSLog(@"error: %@\n", response.error.description);
        return;
    }
    hswUser *user = [hswAPI getUserInfo];
    NSLog(@"username: %@\n", user.username);
}];
```

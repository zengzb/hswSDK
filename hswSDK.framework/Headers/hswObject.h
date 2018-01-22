//
//  hswObject.h
//  hswSDK
//
//  Created by zibozeng on 03/01/2018.
//  Copyright © 2018 Tensafe Technology Co. All rights reserved.
//

#ifndef hswObject_h
#define hswObject_h


#endif /* hswObject_h */

#import <Foundation/Foundation.h>

#pragma mark - hswNWError

/*! @brief hswNWError enum type
 */
typedef enum {
    hswNWErrorInvalidInputs = 0,        //参数错误
    hswNWErrorReLogInRequest,           //请重新登录
    hswNWErrorUnAuthenticated,          //未登录
    hswNWErrorContentAlreadyExist,      //存在相同的内容
    hswNWErrorNoExist,                  //不存在
    hswNWErrorInvalidAccountOrPasswd,   //账号或者密码错误
    hswNWErrorNoSuchArea,               //该区域不存在
    hswNWErrorUnMatchedParameter,       //参数不匹配
    hswNWErrorLimitExceeded,            //超出限制
    hswNWErrorNoSuchProvider,           //运营商未开通
    hswNWErrorOthers,                   //其他错误
    hswNWErrorTeleNOHasBeenTaken,       //手机号已被使用
    hswNWErrorHasAlreadySignedIn,       //已经登录
    hswNWErrorTooMuchTries              //过多尝试
} hswNWErrorType;

/*! @brief Response Error
 */
@interface hswNWError: NSObject
@property (nonatomic) hswNWErrorType type;

// 存放错误的文本信息
@property (nonatomic, retain) NSString *description;
-(instancetype)initWithType:(hswNWErrorType)type error:(NSError *)error;
@end

#pragma mark - hswNWResponse

/*! @brief Http Response
 */
@interface hswNWResponse: NSObject
@property (nonatomic,assign) BOOL success;  //请求成功或失败
@property (nonatomic,retain) hswNWError *error;

-(instancetype)initWithData:(NSDictionary *)data error:(NSError *)error;

/*! @brief 返回一个success属性恒为NO的hswNWResponse
 *  包含的error的type为hswNWErrorTypeOthers，description为自定义的errorMsg
 *  @param errorMsg 自定义的error文本消息
 *  @return hswNWResponse
 */
-(instancetype)initWithErrorMsg:(NSString *)errorMsg;

-(id)objectForKey:(NSString *)key secret:(NSString *)secret;
@end

#pragma mark - hswMode

/*! @brief hswModeType enum type
 */
typedef enum {
    hswModeFree = 1,        //网络畅游模式
    hswModeEducation,       //教育资源模式
    hswModeUnheathBlock,    //不良内容拦截模式
    hswModeRewardCard       //奖励卡模式
} hswModeType;

/*! @brief 网络模式对象
 *  该对象包含模式类型和是否为当前被选择的模式
 */
@interface hswModeObject: NSObject
@property (nonatomic) hswModeType type;
@property (nonatomic,assign) BOOL selected;  //是否被选择
-(id)initWithType: (hswModeType)type selected:(BOOL)selected;

/*! @brief 获取模式文本名称
 *  @return 对应模式的名称文本
 */
-(NSString *)getModeName;
@end

#pragma mark - User

/*! @brief 用户的个人登记信息
 *  用于存储个人的基本信息，比如 用户名，电话号码，地址， 当前的网络模式，宽带账号和账号过期时间
 */
@interface hswUser: NSObject
@property (nonatomic,retain) NSString *username;
@property (nonatomic,retain) NSString *teleNumber;
@property (nonatomic,retain) NSString *address;
@property (nonatomic,retain) NSString *account;
@property (nonatomic) hswModeType currentMode;
@property (nonatomic,retain) NSString *expiration;

/*! @brief 初始化
 */
-(instancetype)initWithObject:(NSDictionary *)userInfo;
-(void)ApiParamMachine: (NSMutableDictionary *)params;

/*! @brief 更新用户的个人登记信息
 *  @param username 用户的昵称
 *  @param address 用户的地址
 *  成功，error为nil；失败，error为具体的错误信息
 */
-(void)updateUserInfo:(NSString *)username address:(NSString *)address complete:(void(^)(hswNWResponse *response))complete;

/*! @brief 获取用户最新的个人登记信息
 */
-(void)updateUser:(void(^)(hswNWResponse *response))complete;

/*! @brief 获取最新网络模式
 *  异步返回网络模式或者错误类型
 */
-(void)getCurrentMode:(void(^)(hswModeType type, hswNWError *error))complete;

/*! @brief 模式切换
 *  @param modeType hswModeType
 */
-(void)switchMode:(hswModeType)modeType complete:(void(^)(hswNWResponse *response))complete;

/*! @brief 获取绑定电话验证码
 *  @param teleNumber 电话号码
 *  成功，error为nil；失败，error为具体的错误信息
 */
-(void)sendCodeForTeleNumberUpdate:(NSString *)teleNumber complete:(void(^)(hswNWResponse *response))complete;

/*! @brief 更改绑定电话
 *  @param teleNumber 电话号码
 *  @param code 验证码
 *  成功，error为nil；失败，error为具体的错误信息
 */
-(void)updateTeleNumber:(NSString *)teleNumber code:(NSString *)code complete:(void(^)(hswNWResponse *response))complete;

/*! @brief 更改密码
 *  @param oldPsw 旧的密码
 *  @param newPsw 新的密码
 *  成功，error为nil；失败，error为具体的错误信息
 */
-(void)changePsw:(NSString *)oldPsw newPsw:(NSString *)newPsw complete:(void(^)(hswNWResponse *response))complete;
@end

#pragma mark - hswTimeSchedule

/*! @brief days of week
 */
typedef enum {
    hswTSDayOfWeekMonday = 0,   //周一
    hswTSDayOfWeekTuesday,      //周二
    hswTSDayOfWeekWednesday,    //周三
    hswTSDayOfWeekThursday,     //周四
    hswTSDayOfWeekFriday,       //周五
    hswTSDayOfWeekSaturday,     //周六
    hswTSDayOfWeekSunday        //周日
} hswTSDayOfWeek;


/*! @brief hour of a day
 */
typedef enum {
    hswTSHourOfDay0To8 = 0,     //从凌晨0:00到早8:00
    hswTSHourOfDay9,            //从8:00到9:00
    hswTSHourOfDay10,           //从9:00到10:00
    hswTSHourOfDay11,           //从10:00到11:00
    hswTSHourOfDay12,           //从11:00到12:00
    hswTSHourOfDay13,           //从12:00到13:00
    hswTSHourOfDay14,           //从13:00到14:00
    hswTSHourOfDay15,           //从14:00到15:00
    hswTSHourOfDay16,           //从15:00到16:00
    hswTSHourOfDay17,           //从16:00到17:00
    hswTSHourOfDay18,           //从17:00到18:00
    hswTSHourOfDay19,           //从18:00到19:00
    hswTSHourOfDay20,           //从19:00到20:00
    hswTSHourOfDay21,           //从20:00到21:00
    hswTSHourOfDay22,           //从21:00到22:00
    hswTSHourOfDay23,           //从22:00到23:00
    hswTSHourOfDay24            //从23:00到0:00
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

#pragma mark - hswTerminals

/*! @brief 终端管控
 */
@interface hswTerminals: NSObject

@end

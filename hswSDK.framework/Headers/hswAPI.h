//
//  hswAPI.h
//  hswSDK
//
//  Created by zibozeng on 03/01/2018.
//  Copyright © 2018 Tensafe Technology Co. All rights reserved.
//

#ifndef hswAPI_h
#define hswAPI_h


#endif /* hswAPI_h */

#import <hswSDK/hswObject.h>

@interface hswAPI: NSObject

#pragma mark - User

/*! @brief 使用用户id和密码登录好上网服务
 *
 *  如果登录成功，返回错误为空；失败，则不为空
 *  @param uid 为发送的用户账号
 *  @param password 为发送的账户密码
 *  成功，error为nil；失败，error为具体的错误信息。
 */
+(void)login:(NSString *)uid password:(NSString *)password complete:(void(^)(hswNWResponse *response))complete;

/*! @brief 退出登陆
 */
+(void)logout;

/*! @brief 获取用户的个人登记信息
 *  返回的内容包括 昵称，手机号，地址，宽带账号，当前的模式和账号过期时间
 *  @return hswUser
 */
+(hswUser *)getUserInfo;

/*! @brief 查看是否已登录
 *  @return 是否登录: BOOL
 */
+(BOOL)hasAuthenticated;

#pragma mark - Features

/*! @brief 获取功能列表
 *  @return 功能列表: NSArray
 */
+(NSArray *)getFeatures;

/*! @brief 获取模式列表
 *  @return 模式列表: NSArray
 */
+(NSArray *)getModes;

/*! @brief 获取最新时间管控
 */
+(void)getCurrentTimeSchedule:(void(^)(hswTimeSchedule *timeSchedule, hswNWError *error))complete;

@end

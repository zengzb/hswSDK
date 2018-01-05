# 好上网SDK IOS
##### 好上网致力于提供安全健康的网络环境，更多功能正在开发中，期待会更好

# Usage

如要使用好上网的所有服务，首先需要使用宽带账号或宽带绑定手机号与对应密码通过登录接口登录

```objective-c
+(void)login:(NSString *)uid password:(NSString *)password complete:(void(^)(hswNWResponse *response))complete;

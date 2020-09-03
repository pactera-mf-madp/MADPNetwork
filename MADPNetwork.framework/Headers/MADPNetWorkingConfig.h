//
//  MADPNetWorking.h
//  MADPH5Container
//
//  Created by 王    帅 on 2019/11/26.
//  Copyright © 2019 pactera. All rights reserved.
//  封装网络的具体实现

#import <Foundation/Foundation.h>


//加密类型
typedef NS_ENUM(NSInteger,EncryptionType){
    EncryptionType_International = 100,//国际加密
    EncryptionType_Domestic,//国密
};

@interface MADPNetWorkingConfig : NSObject

@property (nonatomic, strong) NSString *appId;//appID
@property (nonatomic, strong) NSString *appKey;//appkey
@property (nonatomic, strong) NSString *bundleId;//bundleId
@property (nonatomic, strong) NSString *workspaceId;//工作空间
@property (nonatomic, strong) NSString *restGW;//基础连接

@property (nonatomic, strong) NSNumber *isEncryption;//是否加密 initWithBool  直接使用基础类型bool assign不能持有，会被释放
@property (nonatomic, assign) EncryptionType encryptionType;//加密类型
@property (nonatomic, strong) NSDictionary *keyes;//秘钥对

/**
设置秘钥  默认从平台的配置文件.config文件中读取相关信息
@pagrame keyes  秘钥对
@pagrame encryptionType 加密类型
*/
-(void)setSecretKey:(NSDictionary *)keyes  withEncryptionType:(EncryptionType )encryptionType;

@end



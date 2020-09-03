//
//  MADPNetWorking.h
//  MADPH5Container
//
//  Created by 王    帅 on 2019/11/26.
//  Copyright © 2019 pactera. All rights reserved.
//  网络管理类

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MADPNetWorkingConfig.h"

//请求方式类型枚举
typedef NS_ENUM(NSInteger,RequestMethod){
    RequestMethod_Get = 100,
    RequestMethod_Post,
    RequestMethod_Put,
    RequestMethod_Delete,
};

typedef void(^UpProgressBlock)(NSProgress *uploadProgress);
typedef void(^DownProgressBlock)(NSProgress *downloadProgress);
typedef void(^SuccessBlock)(id respondseObjecte);
typedef void(^FailureBlock)(NSError *error);

@interface MADPNetWorkingManager : NSObject


@property (nonatomic, strong) MADPNetWorkingConfig * baseManager;


/*启动*/
-(void)start;


//初始化
+(MADPNetWorkingManager *)defaultManager;
/*
设置请求头 字典类型 可选
@pagrame header 请求头；
*/
-(void)reSetHeader:(NSDictionary *)header;

/*
请求数据 get请求
@pagrame url 请求路径；
@pagrame parameters 参数
@pagrame Success 成功回调
@pagrame failure 失败回调
*/
-(void)getWithUrlString:(NSString *)url parameters:(id)parameters success:(SuccessBlock)successBlock failure:(FailureBlock)failureBlock;
/*
请求数据 默认是post请求
@pagrame url 请求路径；
@pagrame parameters 参数
@pagrame Success 成功回调
@pagrame failure 失败回调
*/
-(void)requestWithUrl:(NSString *)url parameters:(NSDictionary *)parameters requestMethod:(RequestMethod)requestMethod Success:(SuccessBlock)success failure:(FailureBlock)failure;

/*
请求数据 post请求(临时的)
@pagrame url 请求路径；
@pagrame parameters 参数
@pagrame Success 成功回调
@pagrame failure 失败回调
*/
-(void)postWithUrlString:(NSString *)url parameters:(id)parameters  requestMethod:(NSString *) requestMethod success:(SuccessBlock)successBlock failure:(FailureBlock)failureBlock;

/*
上传文件
@pagrame url 请求路径；
@pagrame  filrPath 文件路径
@pagrame uploadProgress 上传进度
@pagrame Success 成功回调
@pagrame failure 失败回调
*/
-(void)uploadSomeThing:(NSString *)url filePath:(NSString *)filePath uploadProgress:(UpProgressBlock)uploadProgress Success:(SuccessBlock)success failure:(FailureBlock)failure;

/*
下载文件
@pagrame url 请求路径
@pagrame downloadProgress 下载进度
@pagrame Success 成功回调
@pagrame failure 失败回调
*/

-(void)downLoadFileWithurl:(NSString *)url Success:(SuccessBlock)success failure:(FailureBlock)failure downloadProgress:(DownProgressBlock)downloadProgress;

/***
 暂停下载任务
 注意需要先调用了下载，下载任务已经存在才有作用，否则调用此方法将没有任何作用
 */
-(void)suspendDownLoad:(NSString*)url;

/***
继续下载任务
注意需要先调用了下载，下载任务已经存在才有作用，否则调用此方法将没有任何作用
*/
-(void)ContinueDownLoad:(NSString*)url;

/***
停止下载任务
注意一旦task被取消了，将无法恢复
*/
-(void)stopDownLoad:(NSString*)url;


@end


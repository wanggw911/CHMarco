//
//  CHMarco+Tools.h
//  CHMarco
//
//  Created by GuowenWang on 2017/3/7.
//  Copyright © 2017年 GuowenWang. All rights reserved.
//

#ifndef CHMarco_Tools_h
#define CHMarco_Tools_h



//---- Tools
#define kSafetyObj(obj)             ((NSNull *)(obj) == [NSNull null] ? nil : (obj))
#define kCheckNull(obj)             ((obj) == [NSNull null] || ([(obj) isKindOfClass:[NSString class]] && [(obj) isEqualToString:@""])) ? nil : (obj)

#define kWeak(var)                  __weak __typeof(var) weak##_##var = var
#define kLocalizedString(key)       NSLocalizedString(key, nil)


//---- 本地存储
#define kUserDefaults               [NSUserDefaults standardUserDefaults]
#define kSetValueKey(value,key)     { \
                                        [kUserDefaults setValue:value forKey:key];\
                                        [kUserDefaults synchronize];\
                                    }
#define kGetValueWithKey(key)       [kUserDefaults valueForKey:key]
#define kGetStringWithKey(key)      [kUserDefaults stringForKey:key]
#define kGetBoolWithKey(key)        [kUserDefaults boolForKey:key]
#define kGetIntegerWithKey(key)     [kUserDefaults integerForKey:key]


//----  获取时间间隔
#define kTime_Start                 CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define kTime_EndAndLog             NSLog(@"____________Time Cost: %f", CFAbsoluteTimeGetCurrent() - start);


//----  TODO / FIXME
#define kTODO(message)              // TODO: message
#define kFIXME(message)             // FIXME: message


//---- 调试
#ifdef DEBUG
    #define NSLog(...) NSLog(__VA_ARGS__)
#else
    #define NSLog(...)
#endif

// 控制台输出不完整的完美解决：CHLog
// 解决方案来自： https://www.cnblogs.com/Rong-Shengcom/p/7851060.html
#ifdef DEBUG
#define CHLog(s, ... ) printf("class: <%p %s:(%d) > method: %s \n%s\n", self, [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, __PRETTY_FUNCTION__, [[NSString stringWithFormat:(s), ##__VA_ARGS__] UTF8String] )
#else
#define CHLog(s, ... )
#endif


//----  自定义：TODO
#define STRINGIFY(S) #S
#define DEFER_STRINGIFY(S) STRINGIFY(S)
#define PRAGMA_MESSAGE(MSG) _Pragma(STRINGIFY(message(MSG)))
#define FORMATTED_MESSAGE(MSG) "[TODO-" DEFER_STRINGIFY(__COUNTER__) "] " MSG " \n" \
        DEFER_STRINGIFY(__FILE__) " line " DEFER_STRINGIFY(__LINE__)
#define KEYWORDIFY try {} @catch (...) {}
//  TODO宏：最终使用下面的宏
#define TODO(MSG) KEYWORDIFY PRAGMA_MESSAGE(FORMATTED_MESSAGE(MSG))  // 使用方式：@TODO("123")


//----  Alert提示宏定义
#define kAlert(_S_, ...)        [[[UIAlertView alloc] initWithTitle:@"提示" \
                                                            message:[NSString stringWithFormat:(_S_), ##__VA_ARGS__] delegate:nil \
                                                  cancelButtonTitle:@"确定" \
                                                  otherButtonTitles:nil] show]


//----  宏定义检测block是否可用
#define BLOCK_EXEC(block, ...)  if (block) { block(__VA_ARGS__); };
/*
 // 宏定义之前的用法
 if (completionBlock)   {
 completionBlock(arg1, arg2);
 }
 // 宏定义之后的用法
 BLOCK_EXEC(completionBlock, arg1, arg2);
 
 */


//---- 控制台调试：
//控制台打印 View 所有子视图
//po [[self view] recursiveDescription]


#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)



#endif /* CHMarco_Tools_h */

//
//  Constants+Inline.h
//  Collect_Category
//
//  Created by GuowenWang on 2016/11/25.
//  Copyright © 2016年 GuowenWang. All rights reserved.
//


//#param mark - App Functions


static inline void CH_App_MakeACall(NSString *phoneNum) {
    NSString *phoneUrl = [NSString stringWithFormat:@"tel://%@", phoneNum];
    NSURL *url = [NSURL URLWithString:phoneUrl];
#ifdef __IPHONE_10_0
    [[UIApplication sharedApplication] openURL:url options:@{} completionHandler:nil];
#else
    [[UIApplication sharedApplication] openURL:url];
#endif
}

static inline void CH_App_OpenUrlInSafari(NSString *urlString) {
    NSURL *url = [NSURL URLWithString:urlString];
#ifdef __IPHONE_10_0
    [[UIApplication sharedApplication] openURL:url options:@{} completionHandler:nil];
#else
    [[UIApplication sharedApplication] openURL:url];
#endif
}

static inline void CH_App_OpenAppInAppStore(NSString *appId) {
    NSString *appUrl = [NSString stringWithFormat:@"https://itunes.apple.com/cn/app/id%@?mt=8", appId];
    NSURL *url = [NSURL URLWithString:appUrl];
#ifdef __IPHONE_10_0
    [[UIApplication sharedApplication] openURL:url options:@{} completionHandler:nil];
#else
    [[UIApplication sharedApplication] openURL:url];
#endif
}

static inline void CH_App_GoAppStoreEvaluate(NSString *appId) {
    NSString *appUrl = [NSString stringWithFormat:@"http://itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?id=%@&pageNumber=0&sortOrdering=2&type=Purple+Software&mt=8", appId];
    NSURL *url = [NSURL URLWithString:appUrl];
#ifdef __IPHONE_10_0
    [[UIApplication sharedApplication] openURL:url options:@{} completionHandler:nil];
#else
    [[UIApplication sharedApplication] openURL:url];
#endif
}

static inline void CH_App_CopyString(NSString *string) {
    UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
    pasteboard.string = string;
}

//#param mark - Thread

static inline void CH_RunOnMainThread(void(^doSomeThing)()) {
    if ([NSThread isMainThread]) {
        !doSomeThing ?: doSomeThing();
    }
    else {
        dispatch_async(dispatch_get_main_queue(), doSomeThing);
    }
}


//#param mark - Dispatch

static inline void CH_DelayDo(NSTimeInterval dalayInSeconds, void(^doSomeThing)()) {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(dalayInSeconds * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        !doSomeThing ?: doSomeThing();
    });
}


//#param mark - Alert

static inline void CH_WarnAlert(NSString *message) {
    UIViewController *viewController = [[UIApplication sharedApplication].delegate window].rootViewController;
    
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"提示" message:message preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"确认" style:UIAlertActionStyleDefault handler:nil];
    [alertController addAction:okAction];
    [viewController presentViewController:alertController animated:YES completion:nil];
}

static inline void CH_WarnAlertIn(UIViewController *viewController, NSString *message) {
    
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"提示" message:message preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"确认" style:UIAlertActionStyleDefault handler:nil];
    [alertController addAction:okAction];
    [viewController presentViewController:alertController animated:YES completion:nil];
}


//#param mark - Encrypt

static inline NSString * CH_SSKeychainService() {
    return [[NSBundle mainBundle] bundleIdentifier];
}

static inline NSString * CH_EncryptKey() {
    
    return @"5046057208a674eaa1f5535509bed529";
    
    /**
     *  加密流程:
     *  1. 将密钥随机插入空格后转换为十六进制
     *  2. 将转换后的十六进制字符串做 Base64 加密
     *
     *  解密流程:
     *  1. 将密钥做 Base64 解密
     *  2. 移除随机插入的空格
     *  3. 将十六进制转为 NSString.
     *
     *  https://www.branah.com/ascii-converter
     */
    
    static NSString *returnedKey = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        NSString *key = @"MzIyMDM2MjA2NTYyMzgzMzY2MjAzMDM3MzMyMDY2NjUzNDYyMzE2MTYxMjAzNjY1MzEzNTY0MzYzMzIwMzY2NDIwMzU2MjIwMzMzODY0MjA2Ng==";
        NSData *base64Data = [[NSData alloc] initWithBase64EncodedString:key options:0];
        NSString *decodedString = [[NSString alloc] initWithData:base64Data encoding:NSUTF8StringEncoding];
        NSString *hexedString = [decodedString stringByReplacingOccurrencesOfString:@"20" withString:@""];
        
        if (([hexedString length] % 2) != 0) {
            return;
        }
        
        NSMutableString *string = [NSMutableString string];
        
        for (NSInteger i = 0; i < [hexedString length]; i += 2) {
            NSString *hex = [hexedString substringWithRange:NSMakeRange(i, 2)];
            NSInteger decimalValue = 0;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"
            sscanf([hex UTF8String], "%x", &decimalValue);
            [string appendFormat:@"%c", decimalValue];
#pragma clang diagnostic pop
        }
        
        returnedKey = [string copy];
    });
    
    return returnedKey;
}

static inline NSString * CH_EncryptPayKey() {
    /**
     *  加密流程:
     *  1. 将密钥随机插入空格后转换为十六进制
     *  2. 将转换后的十六进制字符串做 Base64 加密
     *
     *  解密流程:
     *  1. 将密钥做 Base64 解密
     *  2. 移除随机插入的空格
     *  3. 将十六进制转为 NSString.
     *
     *  https://www.branah.com/ascii-converter
     */
    
    static NSString *returnedKey = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        NSString *key = @"MzIyMDM2MjA2NTYyMzgzMzY2MjAzMDM3MzMyMDY2NjUzNDYyMzE2MTYxMjAzNjY1MzEzNTY0MzYzMzIwMzY2NDIwMzU2MjIwMzMzODY0MjA2Ng==";
        NSData *base64Data = [[NSData alloc] initWithBase64EncodedString:key options:0];
        NSString *decodedString = [[NSString alloc] initWithData:base64Data encoding:NSUTF8StringEncoding];
        NSString *hexedString = [decodedString stringByReplacingOccurrencesOfString:@"20" withString:@""];
        
        if (([hexedString length] % 2) != 0) {
            return;
        }
        
        NSMutableString *string = [NSMutableString string];
        
        for (NSInteger i = 0; i < [hexedString length]; i += 2) {
            NSString *hex = [hexedString substringWithRange:NSMakeRange(i, 2)];
            NSInteger decimalValue = 0;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"
            sscanf([hex UTF8String], "%x", &decimalValue);
            [string appendFormat:@"%c", decimalValue];
#pragma clang diagnostic pop
        }
        
        returnedKey = [string copy];
    });
    
    return returnedKey;
}


//#param mark - String Opearation

static inline NSString * CH_StringByTrimingAllWhitespace(NSString *string) {
    return [string stringByReplacingOccurrencesOfString:@" " withString:@""];
}

static inline CGRect CH_RectOfString(NSString *string, CGSize size, UIFont *font) {
    //CGSizeMake(with, 1000)
    CGRect textFrame = [string boundingRectWithSize:size
                                             options:(NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading)
                                          attributes:@{NSFontAttributeName : font}
                                             context:nil];
    return textFrame;
}

static inline NSString * CH_FormatObject(NSObject *object) {
    if (!object) {
        return @"";
    }
    
    NSString *string = [NSString stringWithFormat:@"%@", object];
    NSRange range = [string rangeOfString:@"NULL"];
    if ([string isEqualToString:@"(null)"] || range.location != NSNotFound) {
        return @"";
    }
    
    return string;
}

static inline NSString * CH_FormatObjects(id object,...) {
    NSString *formatString = @"";
    NSMutableArray *argsArray = [NSMutableArray arrayWithCapacity:1];
    
    va_list params;//定义一个指向个数可变的参数列表指针
    va_start(params, object);//va_start 得到第一个可变参数地址
    
    NSString *arg;
    if (object) {
        //将第一个参数添加到array
        id prev = object;
        [argsArray addObject:prev];
        
        //va_arg 指向下一个参数地址
        while ((arg = va_arg(params, id))) {
            if (arg) {
                [argsArray addObject:arg ? arg : @""];
            }
        }
        //置空
        va_end(params);
    }
    
    for (id element in argsArray) {
        NSString *string = [NSString stringWithFormat:@"%@", element];
        formatString = [NSString stringWithFormat:@"%@%@", formatString, string];
    }
    
    return formatString;
}

static inline NSString * CH_FormatMoney(NSNumber *money) {
    if (!money) {
        return [NSString stringWithFormat:@"%.2f", [@(0) floatValue]];
    }
    
    return [NSString stringWithFormat:@"%.2f", [money floatValue]];
}

static inline NSString * CH_FormatUserRealName(NSString *realName) {
    NSString *formatString = @"";
    
    NSInteger formatCount = realName.length;
    if (formatCount <= 0) {
        return nil;
    }
    
    formatString = [realName substringToIndex:1];
    for (int i = 1; i < formatCount; i++) {
        formatString = [formatString stringByAppendingString:@"*"];
    }
    
    return formatString;
}

static inline NSString * CH_FormatUserPhoneNumber(NSString *phoneNum) {
    NSString *formatString = @"";
    
    NSInteger formatCount = phoneNum.length;
    if (formatCount <= 0) {
        return nil;
    }
    
    formatString = [phoneNum substringToIndex:3];
    formatString = [formatString stringByAppendingString:@" **** "];
    formatString = [formatString stringByAppendingString:[phoneNum substringFromIndex:7]];
    
    return formatString;
}

static inline NSString * CH_FormatUserIDCardNumber(NSString *userIDCardNum) {
    
    NSInteger formatCount = userIDCardNum.length - 4;
    
    //  6  4  4  4
    __autoreleasing NSMutableString *newString = [NSMutableString new];
    for (int i = 0; i < formatCount; i++) {
        [newString appendString:@"*"];
        if (i == 5 || i == 9 || i == 13) {
            [newString appendString:@" "];
        }
    }
    [newString appendString:[userIDCardNum substringFromIndex:formatCount]];
    
    return newString;
}

static inline NSString * CH_FormatUserBankCardNumber(NSString *bankCardNum) {
    NSInteger formatCount = bankCardNum.length - 4;
    if (formatCount <= 0) {
        return nil;
    }
    __autoreleasing NSMutableString *newString = [NSMutableString new];
    for (NSInteger index = 1; index <= formatCount; index++) {
        [newString appendString:@"*"];
        if (index % 4 == 0) {
            [newString appendString:@" "];
        }
    }
    [newString appendString:[bankCardNum substringFromIndex:formatCount]];
    return newString;
}


//#param mark - Object -> JsonString

static inline NSString * CH_ObjectConvertToJsonString(id obj) {
    if (!obj) {
        return @"";
    }
    
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:obj
                                                       options:NSJSONWritingPrettyPrinted
                                                         error:nil];
    NSString *string = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    return string ? string : @"";
}

//#param mark - JsonString -> Dictionary

static inline NSDictionary * CH_JsonConvertToDictionary(NSString *jsonString) {
    if (!jsonString) {
        return nil;
    }
    
    NSData *jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    id jsonObject = [NSJSONSerialization JSONObjectWithData:jsonData
                                                    options:NSJSONReadingMutableContainers
                                                      error:nil];
    if (jsonObject != nil && [jsonObject isKindOfClass:[NSDictionary class]]){
        return jsonObject;
    }
    return nil;
}

//#param mark - JsonString -> Array

static inline NSArray * CH_JsonConvertToArray(NSString *jsonString) {
    if (!jsonString) {
        return nil;
    }
    
    NSData *jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    id jsonObject = [NSJSONSerialization JSONObjectWithData:jsonData
                                                    options:NSJSONReadingMutableContainers
                                                      error:nil];
    if (jsonObject != nil && [jsonObject isKindOfClass:[NSArray class]]){
        return jsonObject;
    }
    return nil;
}



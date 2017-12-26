//
//  CHMarco+Foundation.h
//  CHMarco
//
//  Created by GuowenWang on 2017/3/7.
//  Copyright © 2017年 GuowenWang. All rights reserved.
//

#ifndef CHMarco_Foundation_h
#define CHMarco_Foundation_h



//---- AppInfo
#define kAppBundleInfoDict          [[NSBundle mainBundle] infoDictionary]
#define kAppName                    [kAppBundleInfoDict objectForKey:@"CFBundleDisplayName"]
#define kAppBunldID                 [kAppBundleInfoDict objectForKey:@"CFBundleIdentifier"]
#define kAppReleaseVersion          [kAppBundleInfoDict objectForKey:@"CFBundleShortVersionString"]
#define kAppDevelopVersion          [kAppBundleInfoDict objectForKey:(NSString *)kCFBundleVersionKey]
#define kAppVersionCode             ([kAppReleaseVersion stringByReplacingOccurrencesOfString:@"." withString:@""])

#define kAppSystemName              [UIDevice currentDevice].systemName
#define kAppSystemVersion           [UIDevice currentDevice].systemVersion

#define kIsIOS8                     (kAppSystemVersion.floatValue >= 8.0)
#define kIsIOS11                    (kAppSystemVersion.floatValue >= 11.0)


//---- Foundation
#define kRect(a, b, c, d)            CGRectMake(a, b, c, d)
#define kSize(w, h)                  CGSizeMake(w, h)
#define kRange(loc, len)             NSMakeRange(loc, len)
#define kEdgeInsets(t, l, b, r)      UIEdgeInsetsMake(t, l, b, r)
#define kIndexPath(index, section)   [NSIndexPath indexPathForItem:index inSection:section]
#define kCoordinate2D(lat, lon)      CLLocationCoordinate2DMake(lat, lon)


//---- Relativity
#define kRelativityWidth(x)         (( kIPHONE_WIDTH * x )/375.0 )
#define kRelativityHeight(x)        (( kIPHONE_HEIGTH * x )/667.0 )
#define kRelativitySize(w, h)       CGSizeMake(kRelativityWidth(w), kRelativityHeight(h))


//---- UIFont
#define kFont(x)                    [UIFont systemFontOfSize:x]
#define kFontB(x)                   [UIFont boldSystemFontOfSize:x]


//---- UIColor
#define kClearColor                 [UIColor clearColor]
#define kRedColor                   [UIColor redColor]
#define kWhiteColor                 [UIColor whiteColor]
#define kBlackColor                 [UIColor blackColor]
#define kGreenColor                 [UIColor greenColor]
#define kYellowColor                [UIColor yellowColor]
#define kBlueColor                  [UIColor blueColor]
#define kGrayColor                  [UIColor grayColor]
#define kLightGrayColor             [UIColor lightGrayColor]
//---- UIColor：十六进制
#define kColor(rgbValue)            [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0  \
                                    green:((float)((rgbValue & 0xFF00) >> 8))/255.0     \
                                    blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define kColorA(rgbValue, alpha)    [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0  \
                                    green:((float)((rgbValue & 0xFF00) >> 8))/255.0     \
                                    blue:((float)(rgbValue & 0xFF))/255.0 alpha:alpha]
//---- UIColor：RGB
#define kRGB_A(x)                   [UIColor colorWithRed:x/255.0 green:x/255.0 blue:x/255.0 alpha:1.0]     //后缀ABC排序
#define kRGB_B(x,y,z)               [UIColor colorWithRed:x/255.0 green:y/255.0 blue:z/255.0 alpha:1.0]     //只为控制联想时
#define kRGB_C(x,y,z,a)             [UIColor colorWithRed:x/255.0 green:y/255.0 blue:z/255.0 alpha:a/1.0]   //出现顺序
#define kRGB_D(x,a)                 [UIColor colorWithRed:x/255.0 green:x/255.0 blue:x/255.0 alpha:a/1.0]
//---- UIColor：Common
#define kColor_NormalBg             [UIColor groupTableViewBackgroundColor]  //kColor(0xE6E6E6)
#define kColor_Line                 kRGB_A(221)//[[UIColor lightGrayColor] colorWithAlphaComponent:0.4]
#define kColor_AppMainColor         kRGB_A(221)
#define kColor_PlaceHolder          kRGB_C(0, 0, 0.0980392, 0.22)


//---- UIIamge
#define kImage(x)                   [UIImage imageNamed:x]


//---- NSString
#define kString(x)                  [NSString stringWithFormat:@"%@", x == nil ? @"" : x]
#define kStringOfInt(x)             [NSString stringWithFormat:@"%d", x];
#define kStringOfInteger(x)         [NSString stringWithFormat:@"%li", (long)x]
#define kStringOfFloat(x)           [NSString stringWithFormat:@"%.6f", x]
#define kStringOfBool(x)            (x) ? @"1" : @"0"


//---- NSURL
#define kUrl(x)                     [NSURL URLWithString:(x?x:@"")]



#endif /* CHMarco_Foundation_h */

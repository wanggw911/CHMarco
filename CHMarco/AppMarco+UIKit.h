//
//  AppMarco+UIKit.h
//  CHMarco
//
//  Created by GuowenWang on 2017/3/7.
//  Copyright © 2017年 GuowenWang. All rights reserved.
//

#ifndef AppMarco_UIKit_h
#define AppMarco_UIKit_h



#define kKeyWindow              [UIApplication sharedApplication].keyWindow
#define kRootViewController     [[UIApplication sharedApplication].delegate window].rootViewController
#define kFirstResponder         [kKeyWindow performSelector:@selector(firstResponder)]

#define SINGLE_LINE_WIDTH       (1.f / [UIScreen mainScreen].scale)

#define kSCREEN_WIDTH           ([UIScreen mainScreen].bounds.size.width)
#define kSCREEN_HEIGHT          ([UIScreen mainScreen].bounds.size.height)

#define kWIDTH_IPHONE           kSCREEN_WIDTH
#define kHEIGTH_IPHONE          kSCREEN_HEIGHT


#define kIS_IPHONE              (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define kIS_Iphone5ORLow        ([UIScreen mainScreen].bounds.size.height<=568)
#define kIS_IphoneX             (SCREEN_HEIGHT == 812)


#define kView_Of_NIB(x)             [[[NSBundle mainBundle] loadNibNamed:x owner:self options:nil] lastObject]
#define kNib(x)                     [UINib nibWithNibName:x bundle:nil]

#define kStoryboard_Main            [UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]]
#define kController_of_MainSB(x)    [kStoryboard_Main instantiateViewControllerWithIdentifier:x]



#endif /* AppMarco_UIKit_h */

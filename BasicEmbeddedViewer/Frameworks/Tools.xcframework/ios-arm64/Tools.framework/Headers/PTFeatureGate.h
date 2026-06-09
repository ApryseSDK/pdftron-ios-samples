//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTFeatureGateKeys.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTFeatureGate;
@protocol PTFeatureGateDelegate;

PT_OBJC_RUNTIME_NAME(FeatureGateDelegate)
@protocol PTFeatureGateDelegate <NSObject>

-(BOOL)featureGate:(PTFeatureGate*)featureGate isAvailable:(NSString*)featureID;

-(void)featureGate:(PTFeatureGate *)featureGate handleFeature:(NSString *)featureID onController:(UIViewController*)controller;

- (UIImageView *)featureGateProImageView:(PTFeatureGate *)featureGate WithTintColor:(nullable UIColor *)tintColor;

- (NSString *)featureGate:(PTFeatureGate*)featureGate proButtonTitleForTitle:(NSString *)title forFeature:(NSString *)featureID;

- (UIImage *_Nullable)featureGateUnavailableIndicatorImage:(PTFeatureGate*)featureGate;

- (UIImage *_Nullable)featureGateUnavailableIconImage:(PTFeatureGate*)featureGate;

@end

PT_EXTERN
PT_OBJC_RUNTIME_NAME(FeatureGate)
@interface PTFeatureGate : NSObject <PTOverridable>

/**
 * The global instance of the shared tools settings manager.
 */
@property (nonatomic, class, readonly, strong) PTFeatureGate *sharedInstance;

-(BOOL)isAvailable:(NSString*)featureID;

- (void)handleFeature:(NSString *)featureID onController:(UIViewController*)controller;

- (NSString *)proButtonTitleForTitle:(NSString *)title forFeature:(NSString *)featureID;

- (UIImageView *)proImageViewWithTintColor:(nullable UIColor *)tintColor;

- (UIImage *)unavailableIndicatorImage;

- (UIImage *)unavailableIconImage;

- (void)didUpdateAvailability;

@property (nonatomic, weak, nullable) id<PTFeatureGateDelegate> delegate;

@end

#pragma mark - Notifications

PT_EXPORT const NSNotificationName PTFeatureGateDidUpdateFeatureAvailabilityNotification;

NS_ASSUME_NONNULL_END

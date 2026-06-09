//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDocumentViewSettings;

PT_EXTERN
PT_OBJC_RUNTIME_NAME(DocumentViewSettings)
@interface PTDocumentViewSettings : NSObject <NSCoding, NSCopying>

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithDocumentViewSettings:(PTDocumentViewSettings *)documentViewSettings NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

@property (nonatomic, assign) TrnPagePresentationMode pagePresentationMode;
@property (nonatomic, assign, getter=isReflowEnabled) BOOL reflowEnabled;

@property (nonatomic, assign) PTColorPostProcessMode colorPostProcessMode;
@property (nonatomic, strong, nullable) UIColor *colorPostProcessWhiteColor;
@property (nonatomic, strong, nullable) UIColor *colorPostProcessBlackColor;

@property (nonatomic, assign, getter=isNightModeEnabled) BOOL nightModeEnabled;

@property (nonatomic, assign, getter=isRightToLeft) BOOL rightToLeft;

@property (nonatomic, assign) PTRotate pageRotation;

@end

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_OBJC_RUNTIME_NAME(RubberStampColorModel)
@interface PTRubberStampColorModel : NSObject

/**
 * The start background color of the rubber stamp.
 */
@property (nonatomic, strong, readonly) UIColor *startColor;

/**
 * The end background color of the rubber stamp.
 */
@property (nonatomic, strong, readonly) UIColor *endColor;

/**
 * The text color of the rubber stamp.
 */
@property (nonatomic, strong, readonly) UIColor *textColor;

/**
 * The border color of the rubber stamp.
 */
@property (nonatomic, strong, readonly) UIColor *borderColor;

/**
 * Intializes the model with 4 different colors.
 */
- (instancetype)init: (UIColor*)startColor endColor:(UIColor*)endColor textColor:(UIColor*)textColor borderColor:(UIColor*)borderColor NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END

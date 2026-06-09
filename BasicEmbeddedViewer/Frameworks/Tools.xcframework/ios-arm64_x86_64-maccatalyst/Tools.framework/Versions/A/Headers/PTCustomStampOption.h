//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <Tools/PTRubberStampColorModel.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXPORT
PT_OBJC_RUNTIME_NAME(CustomStampOption)
@interface PTCustomStampOption : NSObject <NSCoding>

/**
 * The main text of the stamp annotation.
 */
@property (nonatomic, strong) NSString *text;

/**
 * The secondary text of the stamp annotation.
 */
@property (nonatomic, strong) NSString *secondText;

/**
 * The starting colour of the background gradient of the stamp annotation.
 */
@property (nonatomic, strong) UIColor *bgColorStart;

/**
 * The end colour of the background gradient of the stamp annotation.
 */
@property (nonatomic, strong) UIColor *bgColorEnd;

/**
 * The text color of the stamp annotation.
 */
@property (nonatomic, strong) UIColor *textColor;

/**
 * The border colour of the stamp annotation.
 */
@property (nonatomic, strong) UIColor *borderColor;

/**
 * The fill opacity of the stamp annotation.
 */
@property (nonatomic) CGFloat fillOpacity;

/**
 * Whether the stamp annotation is pointing left.
 */
@property (nonatomic) BOOL pointingLeft;

/**
 * Whether the stamp annotation is pointing right.
 */
@property (nonatomic) BOOL pointingRight;

/**
 * Returns an initialized `PTCustomStampOption`.
 *
 * @param text            The text to be displayed in the rubber stamp
 * @param secondText      The text to be displayed below first text
 * @param bgColorStart    The start background color in gradient background
 * @param bgColorEnd      The end background color in gradient background
 * @param textColor       The text color
 * @param borderColor     The border color
 * @param fillOpacity     The fill opacity
 * @param pointingLeft    True if pointing left
 * @param pointingRight   True if pointing right
 *
 * @return an initialized `PTCustomStampOption`.
 */
-(instancetype)initWithText:(NSString *)text secondText:(nullable NSString*)secondText bgColorStart:(UIColor*)bgColorStart bgColorEnd:(UIColor*)bgColorEnd textColor:(UIColor*)textColor borderColor:(UIColor*)borderColor fillOpacity:(CGFloat)fillOpacity pointingLeft:(BOOL)pointingLeft pointingRight:(BOOL)pointingRight NS_DESIGNATED_INITIALIZER;

/**
 * Returns an initialized `PTCustomStampOption`.
 *
 * @param text            The text to be displayed in the rubber stamp
 * @param secondText      The text to be displayed below first text
 * @param colourModel   The colour used in the stamp
 * @param fillOpacity     The fill opacity
 * @param pointingLeft    True if pointing left
 * @param pointingRight   True if pointing right
 *
 * @return an initialized `PTCustomStampOption`.
 */
-(instancetype)initWithText:(NSString *)text secondText:(nullable NSString*)secondText colourModel: (PTRubberStampColorModel*)colourModel fillOpacity:(CGFloat)fillOpacity pointingLeft:(BOOL)pointingLeft pointingRight:(BOOL)pointingRight;
/**
 * Returns an initialized `PTCustomStampOption`.
 *
 * @param stampObj The stamp SDF object with which to configure the custom stamp.
 *
 * @return an initialized `PTCustomStampOption`.
 */
-(instancetype)initWithFormXObject:(PTObj*)stampObj NS_DESIGNATED_INITIALIZER;

/**
 * Method to configure a rubber stamp's appearance object from a `PTCustomStampOption`.
*/
- (void)configureStampObject:(PTObj *)stampObj;


-(instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;


-(instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

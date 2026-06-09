//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTCustomStampOption.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTRubberStampColorModel.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXPORT NSString * const PTRubberStampKeyText;
PT_EXPORT NSString * const PTRubberStampKeyTextBelow;
PT_EXPORT NSString * const PTRubberStampKeyFillColorStart;
PT_EXPORT NSString * const PTRubberStampKeyFillColorEnd;
PT_EXPORT NSString * const PTRubberStampKeyTextColor;
PT_EXPORT NSString * const PTRubberStampKeyBorderColor;
PT_EXPORT NSString * const PTRubberStampKeyFillOpacity;
PT_EXPORT NSString * const PTRubberStampKeyPointingLeft;
PT_EXPORT NSString * const PTRubberStampKeyPointingRight;
PT_EXPORT NSString * const PTCustomStampOptionsUserDefaultsKey;

PT_OBJC_RUNTIME_NAME(RubberStampManager)
@interface PTRubberStampManager : NSObject<PTOverridable>

/**
 * The light red  color
 */
@property (nonatomic, class, strong, readonly) PTRubberStampColorModel *lightRed;

/**
 * The dark red color
 */
@property (nonatomic, class, strong, readonly) PTRubberStampColorModel *darkRed;

/**
 * The light green color
 */
@property (nonatomic, class, strong, readonly) PTRubberStampColorModel *lightGreen;

/**
 * The light blue color
 */
@property (nonatomic, class, strong, readonly) PTRubberStampColorModel *lightBlue;

/**
 * The yellow color
 */
@property (nonatomic, class, strong, readonly) PTRubberStampColorModel *yellow;

/**
 * The purple color
 */
@property (nonatomic, class, strong, readonly) PTRubberStampColorModel *purple;

/**
 * All the colors on rubber stamp in an array.
 */
@property (nonatomic, class, strong, readonly) NSArray<PTRubberStampColorModel*> *stampColors;

/**
 * Used to determine the number of standard stamps.
 *
 * @return the number of standard stamps.
 */
-(NSUInteger)numberOfStandardStamps;

/**
 * Used to determine the number of custom stamps.
 *
 * @return the number of custom stamps.
 */
-(NSUInteger)numberOfCustomStamps;

/**
 * An array of standard rubber stamp appearances.
 * This should be an array of `PTCustomStampOption`s
 */
@property (nonatomic, copy, nullable) NSArray<PTCustomStampOption*> *standardStampOptions;

/**
 * An array of custom rubber stamp appearances.
 * This should be an array of `PTCustomStampOption`s
 */
@property (nonatomic, copy, nullable) NSArray<PTCustomStampOption*> *customStampOptions;

/**
 * The standard `APPROVED` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* approvedStamp;

/**
 * The standard `AS IS` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* asIsStamp;

/**
 * The standard `COMPLETED` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* completedStamp;

/**
 * The standard `CONFIDENTIAL` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* confidentialStamp;

/**
 * The standard `DEPARTMENTAL` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* departmentalStamp;

/**
 * The standard `DRAFT` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* draftStamp;

/**
 * The standard `EXPERIMENTAL` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* experimentalStamp;

/**
 * The standard `EXPIRED` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* expiredStamp;

/**
 * The standard `APPROVED` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* finalStamp;

/**
 * The standard `FOR COMMENT` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* forCommentStamp;

/**
 * The standard `FOR PUBLIC RELEASE` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* forPublicReleaseStamp;

/**
 * The standard `INFORMATION ONLY` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* informationOnlyStamp;

/**
 * The standard `NOT APPROVED` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* notApprovedStamp;

/**
 * The standard `NOT FOR PUBLIC RELEASE` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* notForPublicReleaseStamp;

/**
 * The standard `PRELIMINARY RESULTS` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* preliminaryResultsStamp;

/**
 * The standard `SOLD` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* soldStamp;

/**
 * The standard `TOP SECRET` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* topSecretStamp;

/**
 * The standard `VOID` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* voidStamp;

/**
 * The standard `SIGN HERE` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* signHereStamp;

/**
 * The standard `WITNESS` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* witnessStamp;

/**
 * The standard `INITIAL HERE` stamp.
 */
@property (nonatomic, class, strong, readonly) PTCustomStampOption* initialHereStamp;

/**
 *
 * Saves a custom stamp created.
 *
 * @param stamp custom stamp created.
 *
 */
-(void) saveCustomStampOption:(PTCustomStampOption *)stamp;

/**
 *
 * Returns an image of the stamp with a given `PTCustomStampOption` appearance.
 *
 * @param height The desired height of the output image.
 *
 * @param width The desired width of the output image.
 *
 * @param stampOption A `PTCustomStampOption` appearance object.
 *
 * @return A rasterized copy of the signature.
 *
 */
+(UIImage*)getBitMapForStampWithHeight:(double)height width:(double)width option:(PTCustomStampOption*)stampOption;

@end

NS_ASSUME_NONNULL_END

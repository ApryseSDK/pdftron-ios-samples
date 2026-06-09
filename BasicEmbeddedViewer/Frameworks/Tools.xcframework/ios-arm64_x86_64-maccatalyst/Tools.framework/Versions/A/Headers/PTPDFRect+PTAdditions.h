//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Convenience additions to the `PTPDFRect` class.
 */
PT_EXTERN
@interface PTPDFRect (PTAdditions)

/**
 * The value of this rect represented as a `CGRect`. 
 */
@property (nonatomic, readonly, assign) CGRect CGRectValue;

/**
 * Creates a new `PTPDFRect` instance from the specified `CGRect` value.
 *
 * @param cgRect The `CGRect` value
 *
 * @return a new `PTPDFRect` instance
 */
+ (instancetype)rectFromCGRect:(CGRect)cgRect;

/**
 * Initializes a newly create `PTPDFRect` instance with the specified `CGRect` value.
 *
 * @param cgRect The `CGRect` value.
 *
 * @return an initialized `PTPDFRect` instance
 */
- (instancetype)initWithCGRect:(CGRect)cgRect;

/**
 * Returns a new `PTPDFRect` instance that encompasses the specified `points`.
 *
 * @param points The points for which to calculate a bounding box
 *
 * @return a new `PTPDFRect` bounding box, or `nil` if an error occurred
 */
+ (nullable PTPDFRect *)boundingBoxForPoints:(NSArray<PTPDFPoint *> *)points;

/**
 * The four vertices of this rect, in counter-clockwise order starting with the bottom-left vertex.
 *
 * @note The points are created from a normalized copy of this rect.
 */
@property (nonatomic, readonly) NSArray<PTPDFPoint *> *points;

/**
 * The center point of this rect.
 */
@property (nonatomic, readonly, strong) PTPDFPoint *center;

@end

NS_ASSUME_NONNULL_END

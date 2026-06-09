//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <PDFNet/PDFNetDefines.h>
#import <PDFNet/PDFNetOBJC.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPDFPoint;
@class PTPDFRect;
@class PTQuadPoint;

/**
 * Additions to the `PTPDFPoint` class.
 */
@interface PTPDFPoint (Additions) <NSCopying>

/**
 * The x-coordinate of the point.
 */
@property (nonatomic, assign, getter=PT_getX, setter=PT_setX:) double x;

/**
 * The y-coordinate of the point.
 */
@property (nonatomic, assign, getter=PT_getY,setter=PT_setY:) double y;

#pragma mark <NSCopying>

/**
 * Returns a copy of this point.
 *
 * @return a copy of this point
 */
- (instancetype)copy;

@end

/**
 * Additions to the `PTPDFRect` class.
 */
@interface PTPDFRect (Additions) <NSCoding, NSSecureCoding, NSCopying>

/**
 * The x-coordinate of the rect's first point (bottom-left in a normalized rect).
 */
@property (nonatomic, assign, getter=PT_x1, setter=PT_setX1:) double x1;

/**
 * The y-coordinate of the rect's first point (bottom-left in a normalized rect).
 */
@property (nonatomic, assign, getter=PT_y1, setter=PT_setY1:) double y1;

/**
 * The x-coordinate of the rect's second point (top-right in a normalized rect).
 */
@property (nonatomic, assign, getter=PT_x2, setter=PT_setX2:) double x2;

/**
 * The y-coordinate of the rect's second point (top-right in a normalized rect).
 */
@property (nonatomic, assign, getter=PT_y2, setter=PT_setY2:) double y2;

/**
 * The width of the rect.
 */
@property (nonatomic, readonly, assign, getter=PT_width) double width;

/**
 * The height of the rect.
 */
@property (nonatomic, readonly, assign, getter=PT_height) double height;

#pragma mark Points

/**
 * The rect's first point (bottom-left in a normalized rect).
 */
@property (nonatomic, strong, getter=PT_p1, setter=PT_setP1:) PTPDFPoint *p1;

/**
 * The rect's second point (top-right in a normalized rect).
 */
@property (nonatomic, strong, getter=PT_p2, setter=PT_setP2:) PTPDFPoint *p2;

/**
 * Initializes a newly created `PTPDFRect` instance with the specified points.
 *
 * @param p1 The first point of the rect.
 *
 * @param p2 The second point of the rect.
 *
 * @return an initialized `PTPDFRect` instance
 */
- (instancetype)initWithP1:(PTPDFPoint *)p1 p2:(PTPDFPoint *)p2;

#pragma mark Utility

/**
 * Returns a normalized copy of this rect.
 *
 * @return a normalized copy of this rect
 */
- (PTPDFRect *)NormalizedRect NS_WARN_UNUSED_RESULT;

#pragma mark <NSCopying>

/**
 * Returns a copy of this rect.
 *
 * @return a copy of this rect
 */
- (instancetype)copy;

@end

/**
 * Additions to the `PTQuadPoint` class.
 */
@interface PTQuadPoint (Additions) <NSCopying>

/**
 * The bottom-left point in a normal quad-point (counter-clockwise order).
 */
@property (nonatomic, strong, getter=PT_getP1, setter=PT_setP1:) PTPDFPoint *p1;

/**
 * The bottom-right point in a normal quad-point (counter-clockwise order).
 */
@property (nonatomic, strong, getter=PT_getP2, setter=PT_setP2:) PTPDFPoint *p2;

/**
 * The top-right point in a normal quad-point (counter-clockwise order).
 */
@property (nonatomic, strong, getter=PT_getP3, setter=PT_setP3:) PTPDFPoint *p3;

/**
 * The top-left point in a normal quad-point (counter-clockwise order).
 */
@property (nonatomic, strong, getter=PT_getP4, setter=PT_setP4:) PTPDFPoint *p4;

#pragma mark <NSCopying>

/**
 * Returns a copy of this quad-point.
 *
 * @return a copy of this quad-point
 */
- (instancetype)copy;

@end

NS_ASSUME_NONNULL_END

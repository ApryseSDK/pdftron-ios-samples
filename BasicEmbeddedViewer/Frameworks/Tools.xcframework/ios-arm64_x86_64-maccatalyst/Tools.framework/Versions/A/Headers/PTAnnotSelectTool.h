//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTTool.h>

NS_ASSUME_NONNULL_BEGIN

/**
* The PTAnnotSelectTool is used to select multiple annotations.
*/
PT_OBJC_RUNTIME_NAME(AnnotSelectTool)
@interface PTAnnotSelectTool : PTTool

/**
 * The pageNumber that this annotation will be created on.
 */
@property (nonatomic, readonly, assign) int pageNumber;

/**
 * The rectangle defined by the points when the user first touched and his/her finger has
 * moved to.
 */
@property (nonatomic, readonly, assign) CGRect drawArea;

/**
 * The point where the user's finger first made contact with the `PTPDFViewCtrl`.
 */
@property (nonatomic, assign) CGPoint startPoint;

/**
 * The point where the user's finger last made contact with the `PTPDFViewCtrl`.
 */
@property (nonatomic, assign) CGPoint endPoint;

@end

NS_ASSUME_NONNULL_END

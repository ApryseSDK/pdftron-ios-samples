//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Additions to the `PTElementReader` class.
 */
@interface PTElementReader (PTAdditions)

/**
 * Enumerate over the elements associated with this element reader. This element reader must have
 * already been set up with a call to a "Begin" method.
 *
 * @param block The block to execute for each element encountered in the content stream
 *
 * @note The `PTElement` instance passed into the block only exists for the duration of the block
 * and is invalidated immediately after. For this reason, it is not safe to hold onto references to
 * the element instance.
 */
- (void)EnumerateElementsUsingBlock:(void (NS_NOESCAPE ^)(PTElement *element))block;

@end

NS_ASSUME_NONNULL_END

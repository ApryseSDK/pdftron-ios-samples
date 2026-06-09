//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The default line, interitem, and section inset spacing.
 */
PT_EXPORT const CGFloat PTThumbnailViewLayoutDefaultSpacing;

/**
 * A `UICollectionViewLayout` for use with `PTThumbnailsViewController`.
 */
PT_OBJC_RUNTIME_NAME(ThumbnailViewLayout)
@interface PTThumbnailViewLayout : UICollectionViewFlowLayout


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A text selection end bar.
 */
PT_OBJC_RUNTIME_NAME(SelectionBar)
@interface PTSelectionBar : UIView

/**
 * Set to `YES` if bar is on the left (and has its selection handle at the top).
 */
@property (nonatomic, assign) BOOL isLeft;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationStylePresetsGroup.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAnnotationStylePresetsView;

/**
 * The `PTAnnotationStylePresetsViewDelegate` protocol allows the adopting class to respond to
 * messages from the `PTAnnotationStylePresetsView` class.
 */
PT_OBJC_RUNTIME_NAME(AnnotationStylePresetsViewDelegate)
@protocol PTAnnotationStylePresetsViewDelegate <NSObject>
@optional

/**
 * Notifies the delegate that the specified preset style should be edited.
 */
- (void)presetsView:(PTAnnotationStylePresetsView *)presetsView editPresetForStyle:(PTAnnotStyle *)style fromView:(UIView *)view;

@end

/**
 * The `PTAnnotationStylePresetsView` class displays a set of buttons for the styles in a
 * `PTAnnotationStylePresetsGroup` instance and allows the user to change the selected style.
 */
PT_OBJC_RUNTIME_NAME(AnnotationStylePresetsView)
@interface PTAnnotationStylePresetsView : UIView

/**
 * The annotation style presets displayed by this view.
 */
@property (nonatomic, strong, nullable) PTAnnotationStylePresetsGroup *presets;

/**
 * The content view of this view.
 */
@property (nonatomic, readonly, strong) UIView *contentView;

/**
 * The delegate object of this view.
 */
@property (nonatomic, weak, nullable) id<PTAnnotationStylePresetsViewDelegate> delegate;

@end

NS_ASSUME_NONNULL_END

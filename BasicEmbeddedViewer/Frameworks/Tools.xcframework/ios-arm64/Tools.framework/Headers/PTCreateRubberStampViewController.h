//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTRubberStampManager.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTCreateRubberStampViewController;

PT_OBJC_RUNTIME_NAME(CreateRubberStampViewControllerDelegate)
@protocol PTCreateRubberStampViewControllerDelegate <NSObject>
@optional
-(void)createRubberStampController:(PTCreateRubberStampViewController*)createRubberStampController createdStamp:(PTCustomStampOption*)stampOption;
@end


PT_OBJC_RUNTIME_NAME(CreateRubberStampViewController)
@interface PTCreateRubberStampViewController: UIViewController <PTOverridable>

/**
 * The rubber stamp manager used by the `PTRubberStampViewController`
 */
@property (nonatomic, readonly, strong) PTRubberStampManager* rubberStampManager;
/**
 * Notifies the delegate when the user wishes to save the rubber stamp
 */
@property (nonatomic, weak, nullable) id<PTCreateRubberStampViewControllerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END

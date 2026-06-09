//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTToolManager.h>
#import <Tools/PTRubberStampManager.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTRubberStampViewController;
/**
 * A delegate used to respond
*/
PT_OBJC_RUNTIME_NAME(RubberStampViewControllerDelegate)
@protocol PTRubberStampViewControllerDelegate <NSObject>

@required

/**
 * Notifies the delegate when the user wishes to save new to the document.
 *
 * @param stampOption A stamp option to add to the doc.
 *
 */
-(void)rubberStampController:(PTRubberStampViewController*)rubberStampController addStamp:(PTCustomStampOption*)stampOption;

@optional

/**
 * Notifies the delegate when the controller is dismissed.
 */
-(void)rubberStampControllerWasDismissed:(PTRubberStampViewController*)rubberStampController;

@end
PT_OBJC_RUNTIME_NAME(RubberStampViewController)
@interface PTRubberStampViewController : UIViewController <PTOverridable, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout>

/**
 * The collection view object managed by this view controller.
 */
@property (nonatomic, readonly, strong) UICollectionView *collectionView;

/**
 * Whether editing of thumbnails is allowed. The default is `YES`.
 */
@property (nonatomic, assign, getter=isEditingEnabled) BOOL editingEnabled;

/**
 * Whether editing of thumbnails is supported. Some modes of opperation do not support editing
 * and so the edit button will be disabled even if `editingEnabled` is true.
*/
@property (nonatomic, assign, readonly, getter=isEditingSupported) BOOL editingSupported;

/**
 * The rubber stamp manager used by the `PTRubberStampViewController`
 */
@property (nonatomic, readonly, strong) PTRubberStampManager* rubberStampManager;

/**
 * The PTRubberStampViewController object's delegate.
 */
@property (nonatomic, weak) id<PTRubberStampViewControllerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END

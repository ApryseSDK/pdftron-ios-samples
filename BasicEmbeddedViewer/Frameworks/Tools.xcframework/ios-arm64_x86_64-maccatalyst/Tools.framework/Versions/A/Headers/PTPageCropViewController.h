//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTToolManager.h>

#import <UIKit/UIKit.h>
#import <PDFNet/PDFNet.h>


NS_ASSUME_NONNULL_BEGIN

@class PTPageCropViewController;

/**
 * The `PTPageCropViewControllerDelegate` protocol allows the adopting class to respond to messages
 * from the `PTPageCropViewController` class.
 */

PT_OBJC_RUNTIME_NAME(PageCropViewControllerDelegate)
@protocol PTPageCropViewControllerDelegate <NSObject>
@optional

/**
 * This method is called when the crop is applied.
 *
 * @param pageCropViewController The page crop view controller applying the crop
 *
 * @param pageCropRects A dictionary of page numbers and the cropping rects for each page
 * { NSNumber pageNumber : PTPDFRect *rect }
 */
- (void)pageCropViewController:(PTPageCropViewController *)pageCropViewController applyPageCrop:(NSMutableDictionary<NSNumber *, PTPDFRect *>*)pageCropRects;

@end

/**
 * The `PTPageCropViewController` displays a control for cropping the pages of a document.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(PageCropViewController)
@interface PTPageCropViewController : UIViewController <PTOverridable>

/**
 * Initializes a new `PTPageCropViewController` instance.
 *
 * @param pdfViewCtrl the `PTPDFViewCtrl` instance that the control will coordinate with
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a new `PTPageCropViewController` instance.
 *
 * @param toolManager the `PTToolManager` instance that the control will coordinate with
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager;

/**
 * The `PTPDFViewCtrl` instance that this control coordinates with to receive page-related information.
 */
@property (nonatomic, readonly, strong, nullable) PTPDFViewCtrl *pdfViewCtrl;

/**
 * The `PTToolManager` instance that this control coordinates with to receive page-related events.
 */
@property (nonatomic, readonly, strong, nullable) PTToolManager *toolManager;

/**
 * Whether should export the document after cropping. Default is `NO`.
 */
@property (nonatomic, assign) BOOL shouldExport;

/**
 * Applies the user's specified crop to each page in the document.
 *
 * @param box the page box to which to apply the crop
 */
-(void)applyCropToPageBox:(PTBox)box;

/**
 * The page crop view controller's delegate object.
 */
@property (nonatomic, weak, nullable) id<PTPageCropViewControllerDelegate> delegate;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

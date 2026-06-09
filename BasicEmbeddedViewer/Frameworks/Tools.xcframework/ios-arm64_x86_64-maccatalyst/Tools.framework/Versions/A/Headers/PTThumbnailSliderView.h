//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTToolManager.h>
#import <Tools/PTOverrides.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A `PTThumbnailSliderView` object shows a set of page thumbnails for a `PTPDFViewCtrl`'s current
 * document. The view also acts similar to a `UISlider` control, allowing the current page of the
 * associated `PTPDFViewCtrl` to be changed with tap, pan, and long-press gestures on the pages.
 */
PT_OBJC_RUNTIME_NAME(ThumbnailSliderView)
@interface PTThumbnailSliderView : UIView <PTOverridable, UICollectionViewDataSource, UICollectionViewDelegate>

/**
 * Initializes a new `PTThumbnailSliderView` instance.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a new `PTThumbnailSliderView` instance.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager;

/**
 * The PDFViewCtrl used to provide page thumbnails and document information to this view.
 */
@property (nonatomic, readonly, strong) PTPDFViewCtrl *pdfViewCtrl;

/**
 * The tool manager used by this view.
 */
@property (nonatomic, readonly, strong, nullable) PTToolManager *toolManager;

/**
 * Whether the view is currently tracking touch events.
 */
@property (nonatomic, getter=isTracking) BOOL tracking;

/**
 * The maximum value of the magnification effect shown while tracking a touch.
 * The default value is 1.5.
 */
@property (nonatomic) CGFloat magnification;

/**
 * Whether the speed of scrubbing is adjusted when dragging vertically while scrubbing. The default
 * value is `YES`.
 */
@property (nonatomic) BOOL adjustsScrubbingSpeed;

/**
 * The collection view used by the view.
 */
@property (nonatomic, readonly, strong) UICollectionView *collectionView;


- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

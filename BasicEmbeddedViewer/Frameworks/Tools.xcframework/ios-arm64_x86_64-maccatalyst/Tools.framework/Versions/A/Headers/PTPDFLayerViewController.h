//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTToolManager.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTLayerInfo;
@class PTPDFLayerViewController;

/**
 * The `PTLayerInfo` class encapsulates a single Optional Content Group and its
 * visibility in the current context.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(LayerInfo)
@interface PTLayerInfo : NSObject

/**
 * The Optional Content Group (OCG) associated with a `PTLayerInfo` object.
 */
@property (nonatomic, strong, nullable) PTGroup *group;

/**
 * The current visibility state of the Optional Content Group (OCG) associated
 * with a `PTLayerInfo` object.
 */
@property (nonatomic, assign) BOOL state;

/**
 * The children layers' info associated with a `PTLayerInfo` object.
 */
@property (nonatomic, readonly, retain, nullable) NSArray<PTLayerInfo *> *children;

/**
 * The current name of the group, folder or layer associated
 * with a `PTLayerInfo` object.
 */
@property (nonatomic, copy) NSString *name;

/**
 * The level of the current layer in the layers tree.
 */
@property (nonatomic, assign) int level;

/**
 * The current visibility state of the `UITableViewCell` associated
 * with a `PTLayerInfo` object.
 */
@property (nonatomic, assign) BOOL isCollapsed;

/**
 * Indicate whether the current layer is a layer group or not.
 */
@property (nonatomic, assign) BOOL isGroup;

@end

/**
 * The methods declared by the PTPDFLayerViewControllerDelegate protocol allow the adopting delegate to respond to messages from
 * the PTPDFLayerViewController class.
 *
 */
PT_OBJC_RUNTIME_NAME(PDFLayerViewControllerDelegate)
@protocol PTPDFLayerViewControllerDelegate <NSObject>
@optional

/**
 * Tells the delegate that the annotation control wants to be closed.
 */
- (void)pdfLayerViewControllerDidCancel:(PTPDFLayerViewController *)pdfLayerViewController;

@end

/**
 * The PTPDFLayerViewController class displays a list of the document's Optional
 * Content Groups (OCGs), also known as layers.
 *
 * The visibility of each layer can be toggled on or off using this control.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(PDFLayerViewController)
@interface PTPDFLayerViewController : UITableViewController  <PTOverridable>

/**
 * An array of PDF layers (Optional Content Groups) and their state (visibility) in the current context
 */
@property (nonatomic, readonly, strong) NSArray<PTLayerInfo *> *flatLayers;

/**
 * Returns a new instance of a `PTPDFLayerViewController`.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * An object that conforms to the PTPDFLayerViewControllerDelegate protocol.
 */
@property (nonatomic, weak, nullable) id<PTPDFLayerViewControllerDelegate> delegate;

/**
 * Whether OCG top layers and sublayers can be viewed and edited. When disabled, any sublayers will
 * not be shown.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=areSublayersEnabled) BOOL sublayersEnabled;


- (instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

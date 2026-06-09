//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTToolManager.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>

#define KEY_PAGENUM     @"pageNumber"
#define KEY_TYPE        @"type"
#define KEY_SUBTYPE     @"subtype"
#define KEY_CONTENTS    @"contents"
#define KEY_RECT        @"rect"
#define KEY_OBJNUM      @"objNum"
#define KEY_COLOR       @"color"
// We need to augment the built-in annotation types (for example to distinguish b/w a line and an "arrow-head" line)
#define XE_ARROW        100000
#define XE_CLOUD        200000

NS_ASSUME_NONNULL_BEGIN

@class PTLegacyAnnotationViewController;

/**
 * The methods declared by the PTLegacyAnnotationViewControllerDelegate protocol allow the adopting delegate to respond to messages from
 * the PTLegacyAnnotationViewController class.
 *
 */
PT_OBJC_RUNTIME_NAME(LegacyAnnotationViewControllerDelegate)
@protocol PTLegacyAnnotationViewControllerDelegate <NSObject>
@optional

/**
 * Tells the delegate that an annotation in the list was selected.
 *
 * @param annotationViewController The `PTLegacyAnnotationViewController` object informing the delegate about the annotation's selection.
 *
 * @param anAnnotation A dictionary of bookmark information, with key-value pairs: {KEY_PAGENUM, NSNumber of the page number that the
 * annotation is on}, {KEY_SUBTYPE, NSString of the annotation subtype}, {KEY_TYPE, NSString of the annotation type}, {KEY_RECT,
 * PTPDFRect of the annotation's bounding box, in page coordinates}, {KEY_CONTENTS, NSString of the content's of the annotation's
 * popup note, {KEY_OBJNUM, NSNumber of the annotation's SDF object number}.
 */
- (void)annotationViewController:(PTLegacyAnnotationViewController *)annotationViewController selectedAnnotaion: (NSDictionary *)anAnnotation;

/**
 * Tells the delegate that the annotation control wants to be closed.
 */
- (void)annotationViewControllerDidCancel:(PTLegacyAnnotationViewController *)annotationViewController;

/**
 * Raised when the annotation view controller removes an annotation.
 */
- (void)annotationViewController:(PTLegacyAnnotationViewController *)annotationViewController annotationRemoved:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

@end

/**
 * The PTLegacyAnnotationViewController displays a list of all annotations in a document being viewed by a PTPDFViewCtrl
 * The list will contain any comments that have been added to the annotations, and selecting an annotation
 * will scroll the PTPDFViewCtrl to the position of the annotation. See the sample project Complete Reader for
 * example usage.
 *
 */
PT_OBJC_RUNTIME_NAME(LegacyAnnotationViewController)
@interface PTLegacyAnnotationViewController : UITableViewController <PTOverridable>

/**
 * The PTLegacyAnnotationViewController will display a list of the document's annotations that can be used to
 * navigate the document in a `PTPDFViewCtrl`. When an annotation is selected, the controller will navigate the
 * `PTPDFViewCtrl` to its page. See the sample project Complete Reader for example usage.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager;

/**
 * The PTLegacyAnnotationViewController will display a list of the document's annotations that can be used to
 * navigate the document in a `PTPDFViewCtrl`. When an annotation is selected, the controller will navigate the
 * `PTPDFViewCtrl` to its page. See the sample project Complete Reader for example usage.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * Whether annotations are considered readonly and cannot be modified or deleted. The default value
 * is `NO`, meaning that annotations can be deleted.
 *
 * @note The `PTToolManager.readonly` property is also consulted when determing if annotations can
 * be modified or deleted. When `PTToolManager.readonly` is set to `YES` that property takes
 * precedence over this property's value.
 */
@property (nonatomic, assign, getter=isReadonly) BOOL readonly;

/**
 * Whether annotations are hidden in the annotation list. The default value
 * is `NO`.
 */
@property (nonatomic, assign) BOOL annotationsHidden;

/**
 * An object that conforms to the PTLegacyAnnotationViewControllerDelegate protocol.
 */
@property (nonatomic, weak, nullable) id<PTLegacyAnnotationViewControllerDelegate> delegate;


/**
 * Returns the annotation object associated with the index path.
 *
 * @param indexPath The index path.
 *
 * @return The annotation associated with the given index path.
 */
-(nullable PTAnnot*)annotationForIndexPath:(NSIndexPath*)indexPath;

/**
 * Reloads the list of annotations from the document.
 *
 * This method should only be called when the view controller is visible to
 * avoid performing unnecessary work.
 */
- (void)refresh;

/**
 * Reloads the list of annotations from the document if this view controller's
 * view is currently visible (attached to a `UIWindow`).
 */
- (void)refreshIfVisible;


- (instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

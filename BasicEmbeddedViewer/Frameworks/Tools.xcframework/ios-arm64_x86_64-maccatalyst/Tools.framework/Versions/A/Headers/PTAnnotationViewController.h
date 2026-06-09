//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationModel.h>
#import <Tools/PTAnnotationSortMode.h>
#import <Tools/PTAnnotationViewCell.h>
#import <Tools/PTAnnotationViewControllerConfiguration.h>
#import <Tools/PTEmptyTableViewIndicator.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTToolManager.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAnnotationSortMode;
@class PTAnnotationViewCell;
@class PTAnnotationViewController;
@class PTAnnotationViewControllerConfiguration;
@class PTEmptyTableViewIndicator;
@class PTToolManager;
@protocol PTAnnotationModel;
@protocol PTAnnotationViewControllerDelegate;

/**
 * The methods declared by the `PTAnnotationViewControllerDelegate` protocol allow the adopting
 * class to respond to messages from the `PTAnnotationViewController` class.
 */
PT_OBJC_RUNTIME_NAME(AnnotationViewControllerDelegate)
@protocol PTAnnotationViewControllerDelegate <NSObject>
@optional

/**
 * This method is called when a view cell will be displayed in the `PTAnnotationViewController`.
 *
 * @param annotationViewController The annotation view controller that sent the message.
 *
 * @param cell The view cell that will be displayed.
 *
 * @param annotation The annotation model representing an annotation in the PDF document.
 */
- (void)annotationViewController:(PTAnnotationViewController *)annotationViewController
                 willDisplayCell:(PTAnnotationViewCell *)cell
              forAnnotationModel:(id<PTAnnotationModel>)annotation;

/**
 * This method is called when an annotation is selected in the `PTAnnotationViewController`.
 *
 * @param annotationViewController The annotation view controller that sent the message
 *
 * @param annotation The PDF annotation that was selected
 *
 * @param pageNumber The PDF page number of the selected annotation
 */
- (void)annotationViewController:(PTAnnotationViewController *)annotationViewController
             didSelectAnnotation:(PTAnnot *)annotation
                    onPageNumber:(int)pageNumber;

@end

/**
 * The `PTAnnotationViewController` displays a list of all annotations in a document.
 * The list will contain any comments that have been added to the annotations, and selecting an
 * annotation will scroll the `PTPDFViewCtrl` to the position of the annotation.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(AnnotationViewController)
@interface PTAnnotationViewController : UITableViewController <PTOverridable>

/**
 * Initializes a `PTAnnotationViewController` instance.
 *
 * @return an initialized `PTAnnotationViewController` instance
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a `PTAnnotationViewController` instance with the specified style.
 *
 * @param style The table view style to use
 *
 * @return an initialized `PTAnnotationViewController` instance
 */
- (instancetype)initWithStyle:(UITableViewStyle)style NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a `PTAnnotationViewController` instance with the given coder.
 *
 * @param coder The coder
 *
 * @return an initialized `PTAnnotationViewController` instance
 */
- (instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a newly created `PTAnnotationViewController` with an annotation manager.
 *
 * @param annotationManager The annotation manager to be used by this view controller
 *
 * @return an initialized `PTAnnotationViewController` instance
 */
- (instancetype)initWithAnnotationManager:(PTAnnotationManager *)annotationManager;

/**
 * Initializes a newly created `PTAnnotationViewController` with a tool manager.
 *
 * @param toolManager The tool manager to be used by this view controller
 *
 * @return an initialized `PTAnnotationViewController` instance
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager;

/**
 * The annotation manager associated with this control.
 */
@property (nonatomic, strong, nullable) PTAnnotationManager *annotationManager;

/**
 * The default configuration instance, initialized with the default property values.
 */
@property (nonatomic, class, readonly, strong) PTAnnotationViewControllerConfiguration *defaultConfiguration;

/**
 * The configuration used by this view controller.
 *
 * The default value of this property is a copy of the configuration specified by the
 * `PTAnnotationViewController.defaultConfiguration` class-property value.
 */
@property (nonatomic, readonly, strong) PTAnnotationViewControllerConfiguration *configuration;

/**
 * The delegate of this view controller.
 */
@property (nonatomic, weak, nullable) id<PTAnnotationViewControllerDelegate> delegate;

/**
 * Whether annotations are considered readonly and cannot be modified or deleted.
 *
 * The default value of this property is `NO`, meaning that annotations can be deleted.
 *
 * @note The `PTToolManager.readonly` property is also consulted when determining if annotations can
 * be modified or deleted. When the value of `PTToolManager.readonly` is set to `YES`, that property takes precedence over this property.
 */
@property (nonatomic, assign, getter=isReadonly) BOOL readonly;

/**
 * Whether annotation replies are displayed by this view controller.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=areAnnotationRepliesEnabled) BOOL annotationRepliesEnabled;

/**
 * Whether annotations are hidden in the annotation list.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=areAnnotationsHidden) BOOL annotationsHidden;

/**
 * A list of annotation types to exclude from the annotation view controller.
 *
 * The array entries are wrapped `PTAnnotType` enumeration values.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *excludedAnnotationTypes;

#pragma mark - Sort modes

/**
 * The list of available annotation sort modes for this view controller. The sort modes contained
 * in this property are displayed in the `moreMenu` to allow the user to change the current sort
 * mode.
 */
@property (nonatomic, copy, nullable) NSArray<PTAnnotationSortMode *> *sortModes;

/**
 * The current annotation sort mode. The value of this property is `nil` when the array of sort
 * modes in the `sortModes` property is empty of `nil`.
 *
 * When setting the value of this property, the specified `PTAnnotationSortMode` instance must be
 * in the `sortModes` array property.
 *
 * The default value of this property is `pageNumberSortMode`.
 */
@property (nonatomic, weak, nullable) PTAnnotationSortMode *currentSortMode;

#pragma mark Default sort modes

/**
 * In this sort mode, annotations are sorted and grouped by their page number, and then by their
 * creation dates.
 */
@property (nonatomic, readonly, strong) PTAnnotationSortMode *pageNumberSortMode;

/**
 * Annotations are sorted by their creation date and grouped by day.
 */
@property (nonatomic, readonly, strong) PTAnnotationSortMode *creationDateSortMode;

/**
 * Annotations are sorted by their modification date and then grouped by day.
 */
@property (nonatomic, readonly, strong) PTAnnotationSortMode *modificationDateSortMode;

#pragma mark - Bar button items

/**
 * The "Done" bar button item shown by this view controller to allow dismissing it when shown in a
 * non-popover modal presentation.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *doneButtonItem;

/**
 * The "More" action bar button item shown by this view controller to access additional actions in a
 * menu presentation.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *moreButtonItem;

/**
 * The menu shown by the `moreButtonItem` to access additional actions.
 */
@property (nonatomic, readonly, strong) UIMenu *moreMenu API_AVAILABLE(ios(14.0));

/**
 * The view shown by this controller when there are no annotations in the document.
 */
@property (nonatomic, readonly, strong) PTEmptyTableViewIndicator *emptyIndicator;

- (instancetype)initWithNibName:(nullable NSString *)nibName
                         bundle:(nullable NSBundle *)nibBundle NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

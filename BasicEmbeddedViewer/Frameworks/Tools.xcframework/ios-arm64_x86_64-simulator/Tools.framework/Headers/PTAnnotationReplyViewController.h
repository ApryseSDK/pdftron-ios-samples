//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationManager.h>
#import <Tools/PTAnnotationReplyInputViewController.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTToolManager.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAnnotationManager;
@class PTAnnotationReplyInputViewController;
@class PTAnnotationReplyViewController;

/**
 * Instances of the `PTAnnotationReplyViewController` class display a list of replies made to an annotation.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(AnnotationReplyViewController)
@interface PTAnnotationReplyViewController : UIViewController <PTOverridable>

/**
 * Initializes a newly created `PTAnnotationReplyViewController` instance with an annotation manager.
 */
- (instancetype)initWithAnnotationManager:(PTAnnotationManager *)annotationManager;

/**
 * The annotation manager associated with this control.
 */
@property (nonatomic, strong, nullable) PTAnnotationManager *annotationManager;

/**
 * The annotation reply input view controller.
 */
@property (nonatomic, readonly, strong) PTAnnotationReplyInputViewController *replyInputViewController;

/**
 * The PDF annotation for which replies will be shown.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, readonly, strong, nullable) PTAnnot *annotation;

/**
 * The PDF page number containing the current `annotation`.
 *
 * The default value of this property is `0`.
 */
@property (nonatomic, readonly, assign) int annotationPageNumber;

/**
 * Sets the current PDF annotation and page number for which replies will be shown by this controller.
 *
 * @param annotation the PDF annotation for which to show replies, or `nil` if deselecting
 * the previously-set annotation.
 *
 * @param pageNumber the PDF page number containing the `annotation`, or `0` if deselecting
 * the previously-set annotation.
 */
- (void)setAnnotation:(nullable PTAnnot *)annotation
         onPageNumber:(int)pageNumber;

/**
 * Whether the annotation state of the current PDF `annotation` can be set or updated by this view
 * controller. The visibility of the `annotationStateButtonItem` bar button item is controlled by
 * this property.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=isAnnotationStateEnabled) BOOL annotationStateEnabled;

@property (nonatomic, readonly, assign, getter=isLoadingAnnotationModel) BOOL loadingAnnotationModel;

@property (nonatomic, strong, nullable) id<PTAnnotationModel> annotationModel;

#pragma mark - Editing

/**
 * Whether editing of existing replies is enabled. When enabled, the `annotationManager` is consulted
 * to check whether a given annotation reply can be edited by the current author.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=isReplyEditingEnabled) BOOL replyEditingEnabled;

/**
 * The existing annotation reply that is currently being edited, if any.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) id<PTAnnotationModel> editingAnnotationModel;

#pragma mark - Bar button items

/**
 * The "Annotation State" bar button item shown by this view controller to allow setting or updating
 * the state of the current `annotation`.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *annotationStateButtonItem;

/**
 * The "Done" bar button item shown by this view controller to allow dismissing it when shown in a
 * non-popover modal presentation.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *doneButtonItem;

@end

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/AnnotTypes.h>
#import <Tools/PTOverrides.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTNoteEditController;
@protocol PTNoteEditControllerDelegate;

/**
 * Describes the methods that are called when the user wishes to save or cancel their changes
 * to the annotation's note.
 */
PT_OBJC_RUNTIME_NAME(NoteEditControllerDelegate)
@protocol PTNoteEditControllerDelegate <NSObject>
@optional
/**
 * Called when the user cancels any changes to the annotation's note.
 */
- (void)noteEditController:(PTNoteEditController *)noteEditController cancelButtonPressed:(BOOL)showSelectionMenu;

/**
 * Called when the user wishes to delete the annotation.
 */
- (void)noteEditControllerDeleteSelectedAnnotation:(PTNoteEditController *)noteEditController;

/**
 * Called when the user wishes to save the changes to the annotation's note.
 */
- (void)noteEditController:(PTNoteEditController *)noteEditController saveNewNoteForMovingAnnotationWithString:(NSString *)string;

/**
 * Called when the user wishes to open the style picker.
 */
- (void)noteEditControllerStyleButtonPressed:(PTNoteEditController *)noteEditController;

@end

/**
 * A view controller that displays and allows editing of an annotation's popup note.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(NoteEditController)
@interface PTNoteEditController : UIViewController <PTOverridable>

/**
 * Initializes a newly created `PTNoteEditController` instance.
 */
- (instancetype)initWithDelegate:(id<PTNoteEditControllerDelegate>)delegate annotType:(PTExtendedAnnotType)annotType NS_DESIGNATED_INITIALIZER;

/**
 * The delegate of the note edit controller.
 */
@property (nonatomic, weak, nullable) id<PTNoteEditControllerDelegate> delegate;

/**
 * The `UITextView` that displays the contents of the note.
 */
@property (nonatomic, readonly, strong) UITextView *textView;

/**
 * The contents of the note.
 */
@property (nonatomic, copy) NSString *noteString;

/**
 * Whether the UIBarButtonItem to change the style of the note should be hidden.
 * The default value is `NO`.
 */
@property (nonatomic, assign) BOOL styleButtonHidden;

/**
 * Whether the note is readonly and editing is disabled. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isReadonly) BOOL readonly;

/**
 * Whether this view controller's contents should be tinted to reflect the annotation's primary color.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=isAnnotationTintColorEnabled) BOOL annotationTintColorEnabled;

/**
 * The tinted background color of this view controller.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) UIColor *backgroundTintColor;

/**
 * The tinted button item color of this view controller.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) UIColor *buttonItemTintColor;

/**
 * This method is called when cancel button is pressed. Override point.
 */
- (void)cancelButtonPressed;

/**
 * This method is called when the delete button is pressed. Override point.
 */
- (void)deleteButtonPressed;

/**
 * This method is called when the save button is pressed. Override point.
 */
- (void)saveButtonPressed;

/**
 * This method is called when the style button is pressed. Override point.
 */
- (void)styleButtonPressed;

/**
 * This method is called when the done button is pressed. Override point.
 */
- (void)doneButtonPressed;

/**
 * The annotation type for which the note edit controller is being shown.
 */
@property (nonatomic) PTExtendedAnnotType annotType;

/**
 * The "Style" button item shown in the toolbar to modify the annotation's style.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *styleButtonItem;

/**
 * The "Delete" button item shown in the toolbar to delete the annotation's style.
 * Only shown for text (sticky note) annotations.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *deleteButtonItem;



-(instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


-(instancetype)initWithNibName:(nullable NSString *)nibName bundle:(nullable NSBundle *)bundle NS_UNAVAILABLE;


-(instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

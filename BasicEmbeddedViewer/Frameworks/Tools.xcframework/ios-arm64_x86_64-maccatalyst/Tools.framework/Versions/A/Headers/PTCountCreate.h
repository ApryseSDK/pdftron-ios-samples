//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTSavedCountGroupsViewController.h>
#import <Tools/PTStickyNoteCreate.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents whether the annotation is a count annotation.
*/
PT_EXPORT NSString * const PTCountKey;

/**
 * Key of the label of the count annotation.
*/
PT_EXPORT NSString * const PTCountLabelKey;

@class PTCountCreate;

/**
 * A delegate used to respond to events from a `PTCountCreate` instance.
 */
PT_OBJC_RUNTIME_NAME(CountCreateDelegate)
@protocol PTCountCreateDelegate <NSObject>
@optional

/**
 * Notifies the delegate that a new group is selected.
 *
 */
- (void)countCreateDidSelectGroupName:(nullable NSString *)groupName withColor:(nullable UIColor *)color;

@end

/**
 * Handles the creation and editing of count annotations.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(CountCreate)
@interface PTCountCreate : PTStickyNoteCreate <PTSavedCountGroupsViewControllerDelegate>

/**
 * Initializes a newly created `PTCountCreate` instance.
 *
 * @return an initialized `PTCountCreate` instance
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * An object that conforms to the `PTCountCreateDelegate` protocol.
 */
@property (nonatomic, weak, nullable) id<PTCountCreateDelegate> delegate;

/**
 * Whether a new group should be created.
 * `YES` if there is no saved group.
 * `No` if there is saved group.
 * The default value of this property is `YES`.
 */
@property (nonatomic) BOOL shouldCreateNewGroup;

/**
 * The color of the selected group.
 */
@property (nonatomic, strong, nullable) UIColor *pickedGroupColor;

/**
 * The name of the selected group.
 */
@property (nonatomic, strong, nullable) NSString *pickedGroupName;

/**
 * Show saved groups.
 */
- (void)showCountGroupList;

/**
 * Show saved groups as a popover view.
 */
- (void)showCountGroupList:(UIView *)view onSourceView:(UIView *)sourceView;

@end

NS_ASSUME_NONNULL_END

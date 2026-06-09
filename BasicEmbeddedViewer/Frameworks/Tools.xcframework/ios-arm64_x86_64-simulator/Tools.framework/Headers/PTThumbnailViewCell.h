//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A cell for use by the `PTThumbnailsViewController`.
 */
PT_OBJC_RUNTIME_NAME(ThumbnailViewCell)
@interface PTThumbnailViewCell : UICollectionViewCell

/**
 * Whether night mode is enabled and the cell's colors should be adjusted.
 */
@property (nonatomic, assign) BOOL nightMode;

/**
 * The page label's background view
 */
@property (nonatomic, strong) UIView *labelBackgroundView;

/**
 * Whether the cell is in an editable state. The default value is `NO`.
 *
 * This property is set by the thumbnails view controller when it enters editing mode.
 */
@property (nonatomic, assign, getter=isEditing) BOOL editing;

/**
 * Toggles the receiver into and out of editing mode.
 *
 * @param editing `YES` to enter editing mode, `NO` to leave it.
 *
 * @param animated `YES` to animate the appearance or disappearance of editing-related controls,
 * `NO` to make the transition immediate.
 */
- (void)setEditing:(BOOL)editing animated:(BOOL)animated;

/**
 * Updates the page number of the cell.
 *
 * @param pageNumber The page number.
 *
 * @param pageLabel The page label.
 */
-(void)setPageNumber:(NSInteger)pageNumber pageLabel:(nullable NSString *)pageLabel;

/**
 * Updates the state of the cell.
 *
 * @param pageNumber The page number.
 * @param pageLabel The page label.
 * @param isCurrent Whether the page number is the current page.
 * @param isEditing Whether the containing view controller is in edit mode.
 * @param isChecked Whether the cell is selected/checked.
 */
-(void)setPageNumber:(NSInteger)pageNumber pageLabel:(nullable NSString *)pageLabel isCurrentPage:(BOOL)isCurrent isEditing:(BOOL)isEditing isChecked:(BOOL)isChecked;

/**
 * Associates a thumbnail image with a page number
 *
 * @param image The image of the page.
 *
 * @param pageNum The page number of the page.
 */
-(void)setThumbnail:(nullable UIImage *)image forPage:(NSInteger)pageNum;

@end

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationModel.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAnnotationViewCell;
@protocol PTAnnotationModel;
@protocol PTAnnotationViewCellDelegate;

/**
 * The vertical alignment of an indicator view in a `PTAnnotationViewCell`.
 */
typedef NS_ENUM(NSUInteger, PTAnnotationViewCellIndicatorAlignment) {
    
    /**
     * The indicator is top-aligned.
     */
    PTAnnotationViewCellIndicatorAlignmentTop,
    
    /**
     * The indicator is center-aligned.
     */
    PTAnnotationViewCellIndicatorAlignmentCenter,
    
    /**
     * The indicator is bottom-aligned.
     */
    PTAnnotationViewCellIndicatorAlignmentBottom,
    
} NS_SWIFT_NAME(PTAnnotationViewCell.IndicatorAlignment);

/**
 * The interface for the delegate of a `PTAnnotationViewCell` instance.
 */
PT_OBJC_RUNTIME_NAME(AnnotationViewCellDelegate)
@protocol PTAnnotationViewCellDelegate <NSObject>
@optional

/**
 * Called by the annotation view cell to determine whether replies should be shown for the annotation.
 *
 * If this method is not implemented by the delegate, the default return value is `NO`.
 *
 * @param cell The annotation view cell.
 *
 * @param annotation The annotation model.
 *
 * @return `YES` if annotation reply comments should be shown, `NO` otherwise.
 */
- (BOOL)annotationViewCell:(PTAnnotationViewCell *)cell shouldShowRepliesForAnnotation:(id<PTAnnotationModel>)annotation;

@end

/**
 * A table view cell class capable of displaying PDF annotation info.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(AnnotationViewCell)
@interface PTAnnotationViewCell : UITableViewCell

/**
 * Initializes an annotation view cell with a style and reuse identifier.
 *
 * @param style The cell style.
 *
 * @param reuseIdentifier The cell reuse identifier.
 *
 * @return An initialized `PTAnnotationViewCell` instance.
 */
- (instancetype)initWithStyle:(UITableViewCellStyle)style
              reuseIdentifier:(nullable NSString *)reuseIdentifier NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;

/**
 * The delegate of the annotation view cell.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, weak, nullable) id<PTAnnotationViewCellDelegate> delegate;

/**
 * Whether the type name of the annotation is displayed.
 * 
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL displayAnnotationType;

/**
 * Whether the annotation author is displayed.
 * 
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign) BOOL displayAnnotationAuthor;

/**
 * The amount that the cell's content is inset from its edges.
 *
 * @note The default value of this property is `UIEdgeInsetsZero`.
 */
@property (nonatomic, assign) UIEdgeInsets contentInsets;

#pragma mark - Subviews

/**
 * The image view that displays an icon for the annotation's type.
 */
@property (nonatomic, readonly, strong) UIImageView *annotationImageView;

/**
 * The label showing the title of the cell.
 */
@property (nonatomic, readonly, strong) UILabel *titleLabel;

/**
 * The label displaying the (creation) date of the annotation.
 */
@property (nonatomic, readonly, strong) UILabel *dateLabel;

/**
 * The label displaying the annotation's text contents.
 */
@property (nonatomic, readonly, strong) UILabel *messageLabel;

/**
 * The optional action button in the cell that can be used to display annotation reply comments.
 *
 * The action button is hidden by default and can be controlled with the
 * `-[PTAnnotationViewCellDelegate annotationViewCell:shouldShowRepliesForAnnotation:]` delegate method.
 */
@property (nonatomic, readonly, strong) UIButton *actionButton;

#pragma mark Leading indicator view

/**
 * A view displayed at the leading edge of the cell that can be used to indicate some additional
 * state of the annotation.
 *
 * This view can be used to display an unread indicator dot or small indicator-like icon, for example.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) UIView *leadingIndicatorView;

/**
 * The vertical alignment of the `leadingIndicatorView`.
 *
 * @note The default value of this property is `PTAnnotationViewCellIndicatorAlignmentTop`.
 */
@property (nonatomic, assign) PTAnnotationViewCellIndicatorAlignment leadingIndicatorAlignment;

#pragma mark - Configuration

/**
 * Configures the cell with the given annotation model.
 *
 * @param annotation The annotation model.
 */
- (void)configureWithAnnotation:(id<PTAnnotationModel>)annotation;

@end

NS_ASSUME_NONNULL_END

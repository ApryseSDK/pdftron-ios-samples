//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTToolManager.h>
#import <Tools/PTAnnotStyle.h>
#import <Tools/PTColorPickerViewController.h>


#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAnnotStyleViewController;
@class PTToolManager;

/**
 * The methods declared by the PTAnnotStyleViewControllerDelegate protocol allow the adopting delegate
 * to respond to messages from the AnnotStyleViewController class.
 */
PT_OBJC_RUNTIME_NAME(AnnotStyleViewControllerDelegate)
@protocol PTAnnotStyleViewControllerDelegate <NSObject>
@required

/**
 * Informs the delegate when the annotation style has been committed by the user.
 */
- (void)annotStyleViewController:(PTAnnotStyleViewController *)annotStyleViewController didCommitStyle:(PTAnnotStyle *)annotStyle;

@optional

/**
 * Allows the delegate to adjust the minimum value for the given annotation
 * style and style key.
 */
- (void)annotStyleViewController:(PTAnnotStyleViewController *)annotStyleViewController minimumValue:(inout CGFloat *)minimumValue forStyle:(PTAnnotStyle *)annotStyle key:(PTAnnotStyleKey)styleKey;

/**
 * Allows the delegate to adjust the maximum value for the given annotation
 * style and style key.
 */
- (void)annotStyleViewController:(PTAnnotStyleViewController *)annotStyleViewController maximumValue:(inout CGFloat *)maximumValue forStyle:(PTAnnotStyle *)annotStyle key:(PTAnnotStyleKey)styleKey;

/**
 * Allows the delegate to adjust the available base unit scale values for the given annotation
 * style and style key
 */
- (NSArray<PTMeasurementUnitType>*)annotStyleViewController:(PTAnnotStyleViewController *)annotStyleViewController scaleUnitsForStyle:(PTAnnotStyle *)annotStyle key:(PTAnnotStyleKey)styleKey;

/**
 * Allows the delegate to adjust the available translate unit scale values for the given annotation
 * style and style key
 */
- (NSArray<PTMeasurementUnitType>*)annotStyleViewController:(PTAnnotStyleViewController *)annotStyleViewController translateScaleUnitsForStyle:(PTAnnotStyle *)annotStyle key:(PTAnnotStyleKey)styleKey;

/**
 * Allows the delegate to adjust the available precision levels for the given annotation
 * style and style key.
 * The array entries should be NSNumbers of integer type.
 */
- (NSArray<NSNumber*>*)annotStyleViewController:(PTAnnotStyleViewController *)annotStyleViewController precisionValuesForStyle:(PTAnnotStyle *)annotStyle key:(PTAnnotStyleKey)styleKey;

/**
 * Allows the delegate to adjust the available fractional precision levels for the given annotation
 * style and style key.
 * The array entries should be NSNumbers of integer type which represent the denominator of the fraction.
 * e.g. [NSNumber numberWithInt:16] represents 1/16.
 */
- (NSArray<NSNumber*>*)annotStyleViewController:(PTAnnotStyleViewController *)annotStyleViewController fractionalPrecisionValuesForStyle:(PTAnnotStyle *)annotStyle key:(PTAnnotStyleKey)styleKey;

/**
 * Informs the delegate when the annotation style has been changed by the user.
 */
- (void)annotStyleViewController:(PTAnnotStyleViewController *)annotStyleViewController didChangeStyle:(PTAnnotStyle *)annotStyle;

@end

/**
 * The AnnotStyleViewController displays a list of controls for adjusting the appearance and properties
 * of an annotation or annotation type.
 * The available controls are determined based on the type of annotation provided.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(AnnotStyleViewController)
@interface PTAnnotStyleViewController : UIViewController <PTOverridable, PTAnnotStyleDelegate>

/**
 * Returns an initialized instance of the `PTAnnotStyleViewController` class.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Returns an initialized instance of the `PTAnnotStyleViewController` class.
 *
 * @param annotStyle A `PTAnnotStyle` instance initialized with an annotation or annotation type.
 */
- (instancetype)initWithAnnotStyle:(nullable PTAnnotStyle *)annotStyle NS_DESIGNATED_INITIALIZER;

/**
 * Returns an initialized instance of the `PTAnnotStyleViewController` class.
 *
 * @param toolManager An instance of `PTToolManager`.
 * @param annotStyle An instance of `PTAnnotStyle` initialized with an annotation or annotation type.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager annotStyle:(PTAnnotStyle *)annotStyle;

/**
 * Returns an object initialized from data in a given unarchiver.
 *
 * @param coder An unarchiver object
 *
 * @return `self`, initialized using the data in decoder, or `nil` if the object could
 * not be initialized
 */
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

/**
 * An object that manages and stores the current colors and properties for an annotation.
 */
@property (nonatomic, strong, nullable) PTAnnotStyle *annotStyle;

/**
 * An object that conforms to the PTAnnotStyleViewControllerDelegate protocol.
 */
@property (nonatomic, weak, nullable) id<PTAnnotStyleViewControllerDelegate> delegate;

/**
 * Whether a preview of the annotation is shown with the current style.
 *
 * The default value of this property is `NO` when this view controller's `annotStyle` has an
 * annotation, ie. `PTAnnotStyle.annot` is nonnull; the default value is `YES` when the `annotStyle`
 * does not have an annotation.
 */
@property (nonatomic, assign) BOOL showsAnnotationPreview;

/**
 * The configuration that will be used for the font picker.
 */
@property (nonatomic, strong, nullable) UIFontPickerViewControllerConfiguration* fontPickerConfiguration NS_AVAILABLE_IOS(13_0);

/**
 * The `PTColorPickerViewController` managed by this view controller.
 */
@property (nonatomic, strong, readonly) PTColorPickerViewController *colorPickerViewController;

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 140000
/**
 * The iOS system `UIColorPickerViewController` managed by this view controller.
 */
@property (nonatomic, strong, readonly) UIColorPickerViewController *uiColorPickerViewController NS_AVAILABLE_IOS(14_0);
#endif

/**
 * If this view controller should resize itself to preferredContentSize. Default is `true`.
 */
@property (nonatomic) BOOL shouldResize;

/**
 * Request the AnnotStyleViewController to call its delegate's `annotStyleViewController:didCommitStyle` method.
 */
- (void)selectStyle;

/**
 * This method is called when the user selects a color from the `colorPickerViewController` or `uiColorPickerViewController`
 */
-(void)didSelectColor:(UIColor*)color withViewController:(UIViewController*)viewController;


- (instancetype)initWithNibName:(nullable NSString *)nibName bundle:(nullable NSBundle *)nibBundle NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

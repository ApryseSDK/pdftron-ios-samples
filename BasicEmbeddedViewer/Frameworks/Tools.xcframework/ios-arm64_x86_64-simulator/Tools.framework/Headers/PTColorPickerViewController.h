//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTColorPickerViewController;

/**
 * The methods declared by the PTColorPickerViewControllerDelegate protocol allow the adopting delegate to
 * respond to messages from the `PTColorPickerViewController` class.
 */
PT_OBJC_RUNTIME_NAME(ColorPickerViewControllerDelegate)
@protocol PTColorPickerViewControllerDelegate <NSObject>

/**
 * Informs the delegate that a color has been selected by the user.
 */
- (void)colorPickerController:(PTColorPickerViewController *)colorPickerController didSelectColor:(UIColor *)color;

@end

/**
 * The PTColorPickerViewController displays a grid of color cells for selection. Selecting a color cell notifies
 * the delegate object.
 */
PT_OBJC_RUNTIME_NAME(ColorPickerViewController)
@interface PTColorPickerViewController : UIPageViewController <PTOverridable, UIPageViewControllerDataSource>

 /**
  *
  * Initializes a newly created PTColorPickerViewController, with the option of setting the colors to display.
  *
  * @param style The style for transitions between pages.
  *
  * @param navigationOrientation The orientation of the page-by-page navigation.
  *
  * @param options A dictionary of options.
  *
  * @param colors An array of 28 colours, that will be displayed in a 4x7 grid.
  *
  */
- (instancetype)initWithTransitionStyle:(UIPageViewControllerTransitionStyle)style navigationOrientation:(UIPageViewControllerNavigationOrientation)navigationOrientation options:(nullable NSDictionary<UIPageViewControllerOptionsKey, id> *)options colors:(NSArray<UIColor*>* _Nonnull)colors;

/**
 *
 * Initializes a newly created PTColorPickerViewController, with the option of setting the colors to display.
 *
 * @param style The style for transitions between pages.
 *
 * @param navigationOrientation The orientation of the page-by-page navigation.
 *
 * @param options A dictionary of options.
 *
 */
- (instancetype)initWithTransitionStyle:(UIPageViewControllerTransitionStyle)style navigationOrientation:(UIPageViewControllerNavigationOrientation)navigationOrientation options:(nullable NSDictionary<UIPageViewControllerOptionsKey, id> *)options;

/**
 * The currently selected color.
 */
@property (nonatomic, strong, nullable) UIColor *color;

/**
 * An identifier that can be used to indicate the type of color being picked.
 */
@property (nonatomic, strong) id tag;

/**
 * An object that conforms to the `PTColorPickerViewControllerDelegate` protocol.
 */
@property (nonatomic, weak, nullable) id<PTColorPickerViewControllerDelegate> colorPickerDelegate;

/**
 * If this view controller should resize itself to preferredContentSize. Default is `true`.
 */
@property (nonatomic) BOOL shouldResize;

@end

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTToolsUtil.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPageTemplateViewController;

/**
 * The methods declared by the `PTPageTemplateViewControllerDelegate` protocol allow the adopting delegate to respond to messages from
 * the `PTPageTemplateViewController` class.
*/
PT_OBJC_RUNTIME_NAME(PageTemplateViewControllerDelegate)
@protocol PTPageTemplateViewControllerDelegate <NSObject>
- (void)pageTemplateViewController:(PTPageTemplateViewController *)pageTemplateViewController createdDoc:(PTPDFDoc *)newDoc;
- (void)pageTemplateViewControllerDidCancel:(PTPageTemplateViewController *)pageTemplateViewController;
@end

/**
 * Displays a control for adding blank pages. Allows the user to add pages with
 * various page background templates such as line, grid, graph, and music.
*/
PT_OBJC_RUNTIME_NAME(PageTemplateViewController)
@interface PTPageTemplateViewController : UITableViewController <PTOverridable>

/**
 * Initializes a newly created reflow view controller that scrolls horizontally.
 *
 * @param pdfViewCtrl the PDFViewCtrl instance that the control coordinates with
 *
 * @return The initialized reflow view controller.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 *
 * The list of page types available to use.
 * This should be an array of `PTPageTemplateStyle`s converted to NSNumbers.
 * e.g. `@[@(PTPageTemplateStyleBlank), @(PTPageTemplateStyleLined)];`
 */
@property(nullable,nonatomic, copy) NSArray<NSNumber*> *pageTemplates;

/**
 *
 * The list of page sizes available to select. The dictionary key should be the string
 * describing the page type. This will be displayed to the user.
 * The value should be an NSValue created from a CGSize whose dimensions are in inches.
 */
@property(nullable,nonatomic,copy) NSDictionary<NSString*, NSValue*> *pageSizes;

/**
 *
 * The list of page colors available to select.
 *
 */
@property(nullable,nonatomic,copy) NSArray<UIColor*> *pageColors;

/**
 *
 * The name of the default page size to use when displaying the control
 * This value must be present as a key in the `pageSizes` property,
 * otherwise the first key in that dictionary (sorted alphabetically) will be used.
 */
@property(nullable,nonatomic,copy) NSString *defaultPageSize;

/**
 * The page number that new pages will be insert after.
 */
@property(nonatomic,assign) int pageNumber;

/**
 * The flag to indicate if this view controller is to create a new document.
 * True for creating new documents.
 * False for creating new pages in a document.
 * Default value is false.
 */
@property (nonatomic, assign) BOOL createNewDoc;

/**
 * The name of the new document that this view controller is going to create.
 */
@property (nonatomic, copy) NSString *fileName;
/**
 * An object that conforms to the `PTPageTemplateViewControllerDelegate` protocol.
 */
@property (nonatomic, weak, nullable) id<PTPageTemplateViewControllerDelegate> delegate;


- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;

- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

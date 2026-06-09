//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTToolManager.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPDFViewCtrl;
@class PTToolManager;

/**
 * Instances of the `PTPageLabelManager` class manage the page labels associated with the `PTPDFDoc`
 * of a `PTPDFViewCtrl` instance.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(PageLabelManager)
@interface PTPageLabelManager : NSObject <PTOverridable>

/**
 * Initializes a `PTPageLabelManager` instance.
 *
 * @param pdfViewCtrl the PDFViewCtrl
 *
 * @return an initialized `PTPageLabelManager` instance
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl;

/**
 * The `PTPDFViewCtrl` associated with this page label manager.
 */
@property (nonatomic, strong, nullable) PTPDFViewCtrl *pdfViewCtrl;

/**
 * Returns the page label for the given page number of the current `PTPDFDoc` in the `pdfViewCtrl`.
 *
 * @param pageNumber the page number for which to get the label
 *
 * @return the page label for the given page number, or `nil` if no page label is set
 */
- (nullable PTPageLabel *)pageLabelForPageNumber:(int)pageNumber;

/**
 * Returns the page label prefix for the given page number of the current `PTPDFDoc` in the
 * `pdfViewCtrl`.
 *
 * @param pageNumber the page number for which to get the label prefix
 *
 * @return the page label prefix for the given page number, or `nil` if no page label is set
 */
- (nullable NSString *)pageLabelPrefixForPageNumber:(int)pageNumber;

/**
 * Returns the page label title for the given page number of the current `PTPDFDoc` in the
 * `pdfViewCtrl`.
 *
 * @param pageNumber the page number for which to get the label title
 *
 * @return the page label title for the given page number, or `nil` if no page label is set
 */
- (nullable NSString *)pageLabelTitleForPageNumber:(int)pageNumber;

/**
 * Returns the page number for the given page label title of the current `PTPDFDoc` in the
 * `pdfViewCtrl`.
 *
 * @param pageLabelTitle the page number for the given page label title, or `0` if the page label
 * cannot be found
 *
 * @return the page number for the given page label title, or `0` if the page label cannot be found
 */
- (int)pageNumberForPageLabelTitle:(NSString *)pageLabelTitle;

/**
 * Sets the page label for the given page range with the specified style, prefix, and starting value.
 *
 * @param pageLabelStyle one of `e_ptdecimal`, `e_ptroman_uppercase`, `e_ptroman_lowercase`, `e_ptalphabetic_uppercase`, `e_ptalphabetic_lowercase`, or `e_ptpg_none`
 *
 * @param firstPageNumber the first page number associated with this page label
 *
 * @param lastPageNumber the last page associated with this page label
 *
 * @return the page label set to this page, or `nil` if unsuccessfully set
 */
- (nullable PTPageLabel *)setPageLabelStyle:(PTPageLabelStyle)pageLabelStyle fromPageNumber:(int)firstPageNumber toPageNumber:(int)lastPageNumber;

/**
 * Sets the page label for the given page range with the specified style, prefix, and starting value.
 *
 * @param pageLabelStyle one of `e_ptdecimal`, `e_ptroman_uppercase`, `e_ptroman_lowercase`, `e_ptalphabetic_uppercase`, `e_ptalphabetic_lowercase`, or `e_ptpg_none`
 *
 * @param prefix text to prepend to the page label title
 *
 * @param startValue the value to use when generating the numeric portion of the first label in this range
 *
 * @param firstPageNumber the first page number associated with this page label
 *
 * @param lastPageNumber the last page associated with this page label
 *
 * @return the page label set to this page, or `nil` if unsuccessfully set
 */
- (nullable PTPageLabel *)setPageLabelStyle:(PTPageLabelStyle)pageLabelStyle prefix:(nullable NSString *)prefix startValue:(int)startValue fromPageNumber:(int)firstPageNumber toPageNumber:(int)lastPageNumber;

/**
 * Removes all of the page labels of the `PTPDFDoc` in the `pdfViewCtrl`.
 */
- (void)removeAllPageLabels;

/**
 * Executes a given block for every page label's pages of the `PTPDFDoc` in the `pdfViewCtrl`.
 * The block is executed for every page number that a page label applies.
 *
 * @param startPageNumber the page number at which to begin enumerating the page labels
 *
 * @param block the block to execute for every page label's pages
 */
- (void)enumeratePageLabelsStartingAtPageNumber:(int)startPageNumber withBlock:(void (^)(PTPageLabel *pageLabel, int pageNumber, BOOL *stop))block;

@end

NS_ASSUME_NONNULL_END

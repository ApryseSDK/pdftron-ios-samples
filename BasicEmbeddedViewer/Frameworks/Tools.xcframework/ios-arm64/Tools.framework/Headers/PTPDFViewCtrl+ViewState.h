//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTDocumentViewState.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDocumentViewState;

/**
 * View state additions.
 */
@interface PTPDFViewCtrl (ViewState)

/**
 * Returns the current view state of the PDFViewCtrl.
 *
 * @return the current view state of the PDFViewCtrl.
 */
- (PTDocumentViewState *)GetCurrentViewState;

/**
 * Sets the current view state of the PDFViewCtrl.
 *
 * @param documentViewState The new view state
 */
- (void)SetCurrentViewState:(PTDocumentViewState *)documentViewState;

@end

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTNavigationHistoryState.h>
#import <Tools/PTPageLabelManager.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTNavigationHistoryManager;
@class PTPDFViewCtrl;

PT_EXTERN
PT_OBJC_RUNTIME_NAME(NavigationHistoryManager)
@interface PTNavigationHistoryManager : NSObject

- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, strong) PTPDFViewCtrl *pdfViewCtrl;

@property (nonatomic, strong, nullable) PTPageLabelManager *pageLabelManager;

- (void)registerNavigationFromPageNumber:(int)fromPageNumber toPageNumber:(int)toPageNumber;

@property (nonatomic, readonly, strong) PTNavigationHistoryState *state;

@property (nonatomic, readonly, assign) BOOL canGoBack;
@property (nonatomic, readonly, assign) BOOL canGoForward;

- (void)goBack:(nullable id)sender;
- (void)goForward:(nullable id)sender;

- (void)clearNavigationHistory;

@end

PT_EXTERN const NSNotificationName PTNavigationHistoryWillChangeNotification;
PT_EXTERN const NSNotificationName PTNavigationHistoryDidChangeNotification;

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTTextSearchOptions.h>
#import <Tools/PTTextSearchSession.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTTextSearchOptions;
@class PTTextSearchSession;

PT_EXTERN
PT_OBJC_RUNTIME_NAME(TextSearchManager)
@interface PTTextSearchManager : NSObject <PTTextSearchSessionDelegate>

- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic, readonly, strong) PTPDFViewCtrl *pdfViewCtrl;

#pragma mark - Search session management

- (PTTextSearchSession *)beginSessionWithSearchString:(NSString *)searchString
                                              options:(PTTextSearchOptions *)options
    NS_SWIFT_NAME(beginSession(searchString:options:));

/**
 * The text manager's current session.
 *
 * The delegate of the `PTTextSearchSession` is this text search manager and should not be changed.
 */
@property (nonatomic, readonly, strong, nullable) PTTextSearchSession *currentSession;

@end

#pragma mark - Notifications

/**
 * This notification is posted when the text search manager's current session begins an interactive
 * search operation.
 *
 * The notification object is the posting `PTTextSearchManager`.
 */
PT_EXTERN const NSNotificationName PTTextSearchManagerInteractiveSearchDidBeginNotification NS_SWIFT_NAME(PTTextSearchManager.InteractiveSearchDidBeginNotification);

/**
 * This notification is posted when the text search manager's current session ends an interactive search
 * operation.
 *
 * The notification object is the posting `PTTextSearchManager`.
 */
PT_EXTERN const NSNotificationName PTTextSearchManagerInteractiveSearchDidEndNotification NS_SWIFT_NAME(PTTextSearchManager.InteractiveSearchDidEndNotification);

NS_ASSUME_NONNULL_END

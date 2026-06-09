//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTTextSearchOptions.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTTextSearchOptions;
@class PTTextSearchSession;

/**
 * The direction of a search in a `PTTextSearchSession`.
 */
typedef NS_ENUM(NSUInteger, PTTextSearchDirection) {
    /**
     * Search forwards in the document.
     */
    PTTextSearchDirectionForward,
    
    /**
     * Search backwards in the document.
     */
    PTTextSearchDirectionBackward,
    
} NS_SWIFT_NAME(PTTextSearchSession.SearchDirection);

PT_OBJC_RUNTIME_NAME(TextSearchSessionDelegate)
@protocol PTTextSearchSessionDelegate <NSObject>
@optional

/**
 * Tells the delegate when an interactive search operation begins in the session.
 *
 * @param textSearchSession The text search session in which an interactive search operation has begun.
 */
- (void)textSearchSessionDidBeginInteractiveSearch:(PTTextSearchSession *)textSearchSession;

/**
 * Tells the delegate when an interactive search operation ends in the session.
 *
 * @param textSearchSession The text search session in which an interactive search operation has ended.
 */
- (void)textSearchSessionDidEndInteractiveSearch:(PTTextSearchSession *)textSearchSession;

@end

PT_EXTERN
PT_OBJC_RUNTIME_NAME(TextSearchSession)
@interface PTTextSearchSession : NSObject

- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl
                       searchString:(NSString *)searchString
                            options:(PTTextSearchOptions *)options NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic, readonly, strong) PTPDFViewCtrl *pdfViewCtrl;

@property (nonatomic, readonly, copy) NSString *searchString;

@property (nonatomic, readonly, copy) PTTextSearchOptions *options;

/**
 * The delegate of the text search session.
 */
@property (nonatomic, weak, nullable) id<PTTextSearchSessionDelegate> delegate;

#pragma mark Controlling the search session

- (void)findNextResultInDirection:(PTTextSearchDirection)direction;

- (void)cancel;

@end

NS_ASSUME_NONNULL_END

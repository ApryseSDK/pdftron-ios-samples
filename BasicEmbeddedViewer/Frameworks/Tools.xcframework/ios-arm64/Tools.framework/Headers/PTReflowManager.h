//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Tools/PTToolManager.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Algorithm to use for reflow
typedef NS_ENUM(NSInteger, PTReflowMode) {
    /// Reflow text using fonts from the PDF
    PTReflowModeTextOnly,
    /// Reflow text using fonts from the PDF with images extracted and inserted into the reflowed content.
    PTReflowModeTextAndRawImages
};

@class PTReflowManager;

PT_OBJC_RUNTIME_NAME(ReflowManagerDelegate)
@protocol PTReflowManagerDelegate <NSObject>
@optional

- (void)reflowManager:(PTReflowManager *)reflowManager didBeginRequestForPageNumber:(int)pageNumber;

- (void)reflowManager:(PTReflowManager *)reflowManager didReceiveResult:(NSString*)html reflow:(PTReflow *)reflow forPageNumber:(int)pageNumber;

- (void)reflowManager:(PTReflowManager *)reflowManager requestCancelledForPageNumber:(int)pageNumber;

- (void)reflowManager:(PTReflowManager *)reflowManager requestFailedForPageNumber:(int)pageNumber;

- (void)reflowManager:(PTReflowManager *)reflowManager updateAnnotationMode:(BOOL)enabled;

@end

PT_EXPORT
// Handles local (in-memory) caching of reflow results
PT_OBJC_RUNTIME_NAME(ReflowManager)
@interface PTReflowManager : NSObject

- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

@property (nonatomic, weak, nullable) id<PTReflowManagerDelegate> delegate;

/**
 * Overrides the font to use for reflowed content.
 *
 * If this property is nil, the default PDF font will be used.
 *
 * Warning: If the original PDF has incorrect unicode, changing the font will render the PDF
 * unreadable, so use of this property in the general case is not recommended.
 *
 * The default value of this property is `nil`.
 *
 * @note This property only has effect when `reflowMode` is set to `PTReflowModeTextAndRawImages`.
 */
@property (nonatomic, copy) NSString* fontOverrideName;

@property (nonatomic, assign) PTReflowMode reflowMode;

/**
 * `true` if annotation is disabled; `false` otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL annotationToolsHidden;

/**
 * `true` if any images should be included; `false` otherwise. Default is `true`.
 */
@property (nonatomic, assign) BOOL includeImages;

/**
 * `true` if background images should be hidden; `false` otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL hideBackgroundImages;

/**
 * `true` if images should be hidden under text; `false` otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL hideImagesUnderText;

/**
 * `true` if images should be hidden under invisible text; `false` otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL hideImagesUnderInvisibleText;

/**
 * `true` if text should not reflow over images; `false` otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL doNotReflowTextOverImages;

/**
 * `true` if can create annotation; `false` otherwise. Default is `true`.
 * This property will be ignored if `annotationToolsHidden` is `true`.
 */
@property (nonatomic, assign) BOOL annotationModeEnabled;

- (void)requestReflowForPageNumber:(int)pageNumber;

- (void)clearCache;

- (int)pageNumberForReflowFile:(NSURL *)reflowFile;



PT_INIT_UNAVAILABLE

@end

NS_ASSUME_NONNULL_END

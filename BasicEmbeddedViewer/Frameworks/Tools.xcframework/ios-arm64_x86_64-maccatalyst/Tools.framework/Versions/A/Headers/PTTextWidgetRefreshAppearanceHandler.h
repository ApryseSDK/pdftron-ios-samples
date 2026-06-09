//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationRefreshCustomAppearanceHandler.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A `PTTextWidgetRefreshAppearanceHandler` generates custom PDF appearances for text widget annotations.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(TextWidgetRefreshAppearanceHandler)
@interface PTTextWidgetRefreshAppearanceHandler : PTAnnotationRefreshCustomAppearanceHandler

/**
 * Initializes a `PTTextWidgetRefreshAppearanceHandler` instance.
 *
 * @return An initialized `PTTextWidgetRefreshAppearanceHandler` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end

/**
 * Override-points for subclasses.
 */
@interface PTTextWidgetRefreshAppearanceHandler (SubclassingHooks)

/**
 * Draws the background for the text widget annotation.
 *
 * The default implementation of the method fills the bounds of the background with the annotation's
 * background color.
 *
 * @param textWidget The text widget annotation for which an appearance is being generated.
 *
 * @param backgroundRect The bounds of the background to be drawn.
 *
 * @param elementBuilder The element builder used to create new content stream elements.
 *
 * @param elementWriter The element writer used to write new elements to the output content stream.
 *
 * @param userInfo A dictionary containing additional information, or `nil`.
 */
- (void)drawBackgroundForTextWidget:(PTTextWidget *)textWidget
                             inRect:(PTPDFRect *)backgroundRect
                        withBuilder:(PTElementBuilder *)elementBuilder
                             writer:(PTElementWriter *)elementWriter
                           userInfo:(nullable NSDictionary<PTAnnotationRefreshAppearanceUserInfoKey, id> *)userInfo;

/**
 * Draws the content (text) of the text widget annotation.
 *
 * @param textWidget The text widget annotation for which an appearance is being generated.
 *
 * @param contentRect The bounds of the content (text) to be drawn.
 *
 * @param elementBuilder The element builder used to create new content stream elements.
 *
 * @param elementWriter The element writer used to write new elements to the output content stream.
 *
 * @param userInfo A dictionary containing additional information, or `nil`.
 */
- (void)drawContentsForTextWidget:(PTTextWidget *)textWidget
                           inRect:(PTPDFRect *)contentRect
                      withBuilder:(PTElementBuilder *)elementBuilder
                           writer:(PTElementWriter *)elementWriter
                         userInfo:(nullable NSDictionary<PTAnnotationRefreshAppearanceUserInfoKey, id> *)userInfo;

/**
 * Draws the border of the text widget annotation.
 *
 * The default implementation of this method strokes the border with the annotation's border color.
 *
 * @param textWidget The text widget annotation for which an appearance is being generated.
 *
 * @param borderRect The bounds of the border to be drawn. The entire border is drawn within this
 * rectangle (ie. the rectangle is inset on all sides by half of the border width).
 *
 * @param elementBuilder The element builder used to create new content stream elements.
 *
 * @param elementWriter The element writer used to write new elements to the output content stream.
 *
 * @param userInfo A dictionary containing additional information, or `nil`.
 */
- (void)drawBorderForTextWidget:(PTTextWidget *)textWidget
                         inRect:(PTPDFRect *)borderRect
                    withBuilder:(PTElementBuilder *)elementBuilder
                         writer:(PTElementWriter *)elementWriter
                       userInfo:(nullable NSDictionary<PTAnnotationRefreshAppearanceUserInfoKey, id> *)userInfo;

@end

NS_ASSUME_NONNULL_END

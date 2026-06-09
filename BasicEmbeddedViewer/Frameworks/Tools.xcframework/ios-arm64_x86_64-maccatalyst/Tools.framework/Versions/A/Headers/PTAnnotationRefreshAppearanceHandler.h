//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Keys of entries that can be included in a refresh-appearance request's user info dictionary.
 */
typedef NSString * PTAnnotationRefreshAppearanceUserInfoKey NS_TYPED_EXTENSIBLE_ENUM;

/**
 * Classes conforming to this protocol are responsible for refreshing the appearance stream of
 * annotations.
 */
PT_OBJC_RUNTIME_NAME(AnnotationRefreshAppearanceHandler)
@protocol PTAnnotationRefreshAppearanceHandler <NSObject>
@required

/**
 * Refresh the appearance stream for the specified annotation.
 *
 * @param annotation The annotation for which to refresh the appearance.
 *
 * @param refreshOptions The refresh options to use, or `nil`
 *
 * @param userInfo A dictionary containing additional information, or `nil`
 */
- (void)refreshAppearanceForAnnotation:(PTAnnot *)annotation
                           withOptions:(nullable PTRefreshOptions *)refreshOptions
                              userInfo:(nullable NSDictionary<PTAnnotationRefreshAppearanceUserInfoKey, id> *)userInfo;

@end

/**
 * Support for refreshing annotation appearances with a handler.
 */
@interface PTAnnot (RefreshAppearanceHandler)

#pragma mark - Refresh appearance handler

/**
 * Sets the refresh appearance handler for this annotation class.
 *
 * @param refreshAppearanceHandler The refresh appearance handler, or `nil`.
 */
+ (void)SetRefreshAppearanceHandler:(nullable id<PTAnnotationRefreshAppearanceHandler>)refreshAppearanceHandler;

/**
 * Returns the refresh appearance handler previously registered for this annotation class.
 *
 * If there is no refresh appearance handler registered for this specific annotation (sub)class then
 * its superclasses are searched and the first handler found is returned.
 *
 * @return The refresh appearance handler registered for this class, or `nil`.
 */
+ (nullable id<PTAnnotationRefreshAppearanceHandler>)GetRefreshAppearanceHandler;

#pragma mark - Requesting a refreshed appearance

/**
 * Request a refreshed appearance from the handler registered for this annotation's type.
 *
 * The default implementation of this method calls `-RequestRefreshAppearanceWithOptions:userInfo:`.
 *
 * @see `-RequestRefreshAppearanceWithOptions:userInfo:`
 */
- (void)RequestRefreshAppearance;

/**
 * Request a refreshed appearance from the `PTAnnotationRefreshAppearanceHandler`-conforming object
 * registered for this annotation class.
 *
 * Prior to getting the refresh appearance handler, the most derived annotation subclass corresponding
 * to this annotation's type is determined. This allows for the calling code to operate with instances
 * of the `PTAnnot` abstract base class or other intermediate abstract subclasses, but still use
 * the refresh appearance handler registered for the appropriate concrete annotation class.
 *
 * If there is no refresh appearance handler registered for the annotation subclass or its ancestors
 * then the `-[PTAnnot RefreshAppearance]` or `-[PTAnnot RefreshAppearanceWithOptions:]` method is
 * called, depending on whether refresh options were specified.
 *
 * @param refreshOptions The refresh options to use, or `nil`.
 *
 * @param userInfo A dictionary containing additional information, or `nil`.
 */
- (void)RequestRefreshAppearanceWithOptions:(nullable PTRefreshOptions *)refreshOptions
                                   userInfo:(nullable NSDictionary<PTAnnotationRefreshAppearanceUserInfoKey, id> *)userInfo;

@end

PT_OBJC_CATEGORY_LINK(PTAnnot, RefreshAppearanceHandler)

NS_ASSUME_NONNULL_END

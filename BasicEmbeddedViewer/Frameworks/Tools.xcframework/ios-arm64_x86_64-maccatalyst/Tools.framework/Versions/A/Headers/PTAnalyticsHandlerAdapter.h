//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define ANALYTICS_LOG(__EXCEPTION, __EXTRADATA) \
    [[PTAnalyticsHandlerAdapter getInstance] logException:__EXCEPTION withExtraData:__EXTRADATA];

/**
 This class is used to easily add an analytics framework to tools.
 Events of interest are be passed to (a subclass of) this generic class,
 and can then passed on to the analytics framework(s) of your choice.
 */
PT_DEPRECATED_MSG(6.10.0, "Use PTAnalyticsManager instead")
PT_OBJC_RUNTIME_NAME(AnalyticsHandlerAdapter)
@interface PTAnalyticsHandlerAdapter : NSObject

/**
 * Current instance of `PTAnalyticsHandlerAdapter`
 */
+ (instancetype) getInstance;

/**
 * Sets the instance of the `PTAnalyticsHandlerAdapter`.
 */
+ (void) setInstance:(PTAnalyticsHandlerAdapter*)value;

/**
 Sets a string for identifying the user.
 
 @param identifier the string identifying the user.
 */
- (void)setUserIdentifier:(NSString *)identifier;

/** 
 * Performs sdk specific initializations
 *
 */
- (void)initializeHandler;

/**
 * Call in catch blocks so that the analytics handler can log exceptions.
 */
- (BOOL)logException:(NSException *)exception withExtraData:(NSDictionary *)extraData;


/**
 * Call to register custom events with the analytics handler.
 */
- (BOOL)sendCustomEventWithTag:(NSString *)tag;

@end

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * PTAnalyticsEventCategory NS_TYPED_EXTENSIBLE_ENUM;

/**
 * Classes conforming to the `PTAnalyticsHandler` protocol receive analytics events when registered
 * with a `PTAnalyticsManager` instance.
 */
PT_OBJC_RUNTIME_NAME(AnalyticsHandler)
@protocol PTAnalyticsHandler <NSObject>
@optional

/**
 * Call in catch blocks so that the analytics handler can log exceptions.
 */
- (BOOL)logException:(NSException *)exception withExtraData:(nullable NSDictionary<id, id> *)extraData;

/**
 * Call to send custom events with the analytics handler.
 */
- (BOOL)sendCustomEventWithTag:(NSString *)tag;

/**
 * Call to log an event with the analytics handler.
 *
 * @param eventDescription A description of the event that has occurred.
 * @param category The category of the event, or `nil`.
 */
- (void)logEvent:(NSString *)eventDescription
    withCategory:(nullable PTAnalyticsEventCategory)category;

@end

/**
 * The `PTAnalyticsManager` class dispatches analytics events to registered handlers conforming to
 * the `PTAnalyticsHandler` protocol. Each event sent to an analytics manager is dispatched to all
 * registered handlers capable of handling the event.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(AnalyticsManager)
@interface PTAnalyticsManager : NSObject <PTAnalyticsHandler>

/**
 * The default analytics manager.
 */
@property (nonatomic, class, readonly, strong) PTAnalyticsManager *defaultManager;

/**
 * The currently registered analytics handlers.
 */
@property (nonatomic, readonly, copy) NSArray<id<PTAnalyticsHandler>> *handlers;

/**
 * Registers an analytics handler with the manager.
 *
 * @param handler the analytics handler to register
 */
- (void)addHandler:(id<PTAnalyticsHandler>)handler;

/**
 * Removes an analytics handler previously registered with the manager.
 *
 * @param handler the analytics handler to remove
 */
- (void)removeHandler:(id<PTAnalyticsHandler>)handler;

@end

#pragma mark - Exception logging convenience

/**
 * Use the default `PTAnalyticsManager` to log the given exception.
 *
 * @param exception the exception to log
 *
 * @param extraData extra information to pass along with the exception
 */
PT_EXPORT void PTLogException(NSException *exception, NSDictionary<id, id> * _Nullable extraData);

/**
 * Use the default `PTAnalyticsManager` to log the given event.
 *
 * @param eventDescription The format-string for the event description.
 * @param ... A comma-separated list of arguments to substitute into `eventDescription`.
 */
PT_EXPORT void PTLogAnalyticsEvent(PTAnalyticsEventCategory _Nullable category,
                                   NSString *eventDescription,
                                   ...) NS_FORMAT_FUNCTION(2, 3);

// A shorter alias for PTLogAnalyticsEvent()
#define PTLogEvent(...) PTLogAnalyticsEvent(__VA_ARGS__)

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTLogger;

/**
 * The type or severity of a log message.
 */
typedef NS_ENUM(NSUInteger, PTLogMessageType) {
    
    /**
     * An error message.
     */
    PTLogMessageError   = 1 << 0,
    
    /**
     * A warning message.
     */
    PTLogMessageWarning = 1 << 1,
    
    /**
     * An informational message.
     */
    PTLogMessageInfo    = 1 << 2,
    
    /**
     * A message used for debugging purposes.
     */
    PTLogMessageDebug   = 1 << 3,
    
    /**
     * A message used for tracing program control flow.
     */
    PTLogMessageTrace   = 1 << 4,
    
} NS_SWIFT_NAME(PTLogger.MessageType);

/**
 * The log message output level of a logger.
 */
typedef NS_ENUM(NSUInteger, PTLogOutputLevel) {
    
    /**
     * No log messages will be outputted.
     */
    PTLogOutputLevelNone = 0,
    
    /**
     * Output will include error log messages.
     */
    PTLogOutputLevelError   = (PTLogOutputLevelNone)    | (PTLogMessageError),
    
    /**
     * Output will include error and warning log messages.
     */
    PTLogOutputLevelWarning = (PTLogOutputLevelError)   | (PTLogMessageWarning),
    
    /**
     * Output will include error, warning, and info log messages.
     */
    PTLogOutputLevelInfo    = (PTLogOutputLevelWarning) | (PTLogMessageInfo),
    
    /**
     * Output will include error, warning, info, and debug log messages.
     */
    PTLogOutputLevelDebug   = (PTLogOutputLevelInfo)    | (PTLogMessageDebug),
    
    /**
     * Output will include error, warning, info, debug, and trace log messages.
     */
    PTLogOutputLevelTrace   = (PTLogOutputLevelDebug)   | (PTLogMessageTrace),
    
} NS_SWIFT_NAME(PTLogger.OutputLevel);

/**
 * A helper class that outputs messages to the log console.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(Logger)
@interface PTLogger : NSObject

/**
 * Initializes a newly created `PTLogger` instance.
 *
 * @return an initialized `PTLogger` instance
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * A default logger that can be used by any thread.
 */
@property (nonatomic, class, readonly, strong) PTLogger *sharedLogger NS_SWIFT_NAME(shared);

/**
 * The log message output level that determines which messages should be processed and which should
 * be ignored.
 *
 * The default value of this property is `PTLogOutputLevelNone` for non-debug (release) builds and
 * `PTLogOutputLevelDebug` for debug builds.
 */
@property (nonatomic, assign) PTLogOutputLevel outputLevel;

/**
 * An optional string tag to be added to each log message.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, copy, nullable) NSString *tag;

#pragma mark - Logging messages

/**
 * Logs a message of the specified type.
 *
 * @param messageType The type of the log message
 *
 * @param format The format-string for the log message
 */
- (void)logMessageWithType:(PTLogMessageType)messageType
                    format:(NSString *)format, ... NS_FORMAT_FUNCTION(2, 3);

/**
 * Logs a message of the specified type.
 *
 * @param messageType The type of the log message
 *
 * @param format The format-string for the log message
 *
 * @param arguments The list of variadic arguments used by the format-string
 *
 * @see `-logMessageWithType:format:`
 */
- (void)logMessageWithType:(PTLogMessageType)messageType
                    format:(NSString *)format
                 arguments:(va_list)arguments NS_FORMAT_FUNCTION(2, 0);

#pragma mark - Logging message types

/**
 * Logs an error message.
 *
 * The message is logged with the `PTLogMessageError` message type.
 *
 * @param format The format-string for the log message
 *
 * @see `-logMessageWithType:format:`
 */
- (void)logErrorMessage:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

/**
 * Logs a warning message.
 *
 * The message is logged with the `PTLogMessageWarning` message type.
 *
 * @param format The format-string for the log message
 *
 * @see `-logMessageWithType:format:`
 */
- (void)logWarningMessage:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

/**
 * Logs an informational message.
 *
 * The message is logged with the `PTLogMessageInfo` message type.
 *
 * @param format The format-string for the log message
 *
 * @see `-logMessageWithType:format:`
 */
- (void)logInfoMessage:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

/**
 * Logs a debugging message.
 *
 * The message is logged with the `PTLogMessageDebug` message type.
 *
 * @param format The format-string for the log message
 *
 * @see `-logMessageWithType:format:`
 */
- (void)logDebugMessage:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

/**
 * Logs a tracing message.
 *
 * The message is logged with the `PTLogMessageTrace` message type.
 *
 * @param format The format-string for the log message
 *
 * @see `-logMessageWithType:format:`
 */
- (void)logTraceMessage:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

@end

/**
 * @def PTLogError(logger, format, ...)
 *
 * @see `-[PTLogger logErrorMessage:]`
 */
#define PTLogError(logger, format, ...) ([(logger) logErrorMessage:(format), ##__VA_ARGS__])

/**
 * @def PTLogWarning(logger, format, ...)
 *
 * @see `-[PTLogger logWarningMessage:]`
 */
#define PTLogWarning(logger, format, ...) ([(logger) logWarningMessage:(format), ##__VA_ARGS__])

/**
 * @def PTLogInfo(logger, format, ...)
 *
 * @see `-[PTLogger logInfoMessage:]`
 */
#define PTLogInfo(logger, format, ...) ([(logger) logInfoMessage:(format), ##__VA_ARGS__])

/**
 * @def PTLogDebug(logger, format, ...)
 *
 * @see `-[PTLogger logDebugMessage:]`
 */
#define PTLogDebug(logger, format, ...) ([(logger) logDebugMessage:(format), ##__VA_ARGS__])

/**
 * @def PTLogTrace(logger, format, ...)
 *
 * @see `-[PTLogger logTraceMessage:]`
 */
#define PTLogTrace(logger, format, ...) ([(logger) logTraceMessage:(format), ##__VA_ARGS__])

#pragma mark - Function tracing

/**
 * @def PTLogTraceEnterFunction(logger)
 *
 * Logs the entry to the current function with the provided logger instance.
 *
 * @param logger The logger to receive the message
 */
#define PTLogTraceEnterFunction(logger) ([(logger) logTraceMessage:@"(trace) ENTER FUNCTION: %s", __PRETTY_FUNCTION__])

/**
 * @def PTLogTraceExitFunction(logger)
 *
 * Logs the exit from the current function with the provided logger instance.
 *
 * @param logger The logger to receive the message
 */
#define PTLogTraceExitFunction(logger) ([(logger) logTraceMessage:@"(trace) EXIT FUNCTION: %s", __PRETTY_FUNCTION__])

NS_ASSUME_NONNULL_END

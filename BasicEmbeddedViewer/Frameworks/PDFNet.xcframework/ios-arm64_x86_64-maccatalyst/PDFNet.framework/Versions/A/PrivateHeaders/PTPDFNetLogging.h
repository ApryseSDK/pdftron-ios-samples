//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <PDFNet/PDFNetDefines.h>
#import <PDFNet/PDFNetOBJC.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPDFNetLogging;

/**
 * Log backends for the `PTPDFNetLogging` class.
 */
typedef NS_ENUM(NSUInteger, PTPDFNetLoggingLogBackend) {
    /**
     * Log messages to the currently attached debugger.
     */
    PTPDFNetLoggingLogBackendDebugger   = 0,
    
    /**
     * Log messages to the file specified via `+[PTPDFNetLogging setLogLocationWithFilename:]` or
     * `+[PTPDFNetLogging setLogLocationWithDirectory:filename:]`.
     */
    PTPDFNetLoggingLogBackendDisk       = 1,
    
    /**
     * Not currently available.
     */
    PTPDFNetLoggingLogBackendCallback   = 2,
    
    /**
     * Log messages to standard output.
     */
    PTPDFNetLoggingLogBackendConsole    = 3,
} NS_SWIFT_NAME(PTPDFNetLogging.LogBackend);

/**
 * Log levels for the `PTPDFNetLogging` class.
 */
typedef NS_ENUM(NSUInteger, PTPDFNetLoggingLogLevel) {
    /**
     * The log level for tracing function calls and program logic.
     */
    PTPDFNetLoggingLogLevelTrace    = 0,
    
    /**
     * The log level for messages helpful during debugging.
     */
    PTPDFNetLoggingLogLevelDebug    = 1,
    
    /**
     * The log level for informational messages.
     */
    PTPDFNetLoggingLogLevelInfo     = 2,
    
    /**
     * The log level for warnings.
     */
    PTPDFNetLoggingLogLevelWarning  = 3,
    
    /**
     * The log level for non-fatal errors.
     */
    PTPDFNetLoggingLogLevelError    = 4,
    
    /**
     * The log level for fatal error messages.
     */
    PTPDFNetLoggingLogLevelFatal    = 5,
    
    /**
     * The log level used to disable messages sent with any level.
     *
     * This log level should only be used as a threshold level - it is not used for individual log
     * messages.
     */
    PTPDFNetLoggingLogLevelDisabled = 6,
} NS_SWIFT_NAME(PTPDFNetLogging.LogLevel);

/**
 * The name of a logging stream.
 */
typedef NSString * PTPDFNetLoggingStreamName NS_TYPED_EXTENSIBLE_ENUM NS_SWIFT_NAME(PTPDFNetLogging.StreamName);

/**
 * The logging stream for PDFView-related messages.
 */
PDFNET_EXTERN const PTPDFNetLoggingStreamName PTPDFNetLoggingStreamNamePDFView;

/**
 * The logging stream for rendering-related messages.
 */
PDFNET_EXTERN const PTPDFNetLoggingStreamName PTPDFNetLoggingStreamNameRender;

/**
 * The logging stream for messages relating to the rendering display cache (dispcache).
 */
PDFNET_EXTERN const PTPDFNetLoggingStreamName PTPDFNetLoggingStreamNameDispcache;

/**
 * The `PTPDFNetLogging` class enables control over the runtime logging in the PDFNet library.
 */
PDFNET_EXTERN
PDFNET_OBJC_RUNTIME_NAME(PTPDFNetLogging)
@interface PTPDFNetLogging : NSObject

/**
 * Whether the logging system is available.
 *
 * The availability of the system depends on whether the PDFNet library was built to include logging.
 */
@property (nonatomic, class, readonly, assign, getter=isAvailable) BOOL available;

/**
 * Logs a message with the logging system.
 *
 * @param threshold The importance of this log message.
 * @param message The message to be logged.
 * @param filename The filename from which the log message originates.
 * @param lineNumber The line number from which the log message originates.
 */
+ (void)logMessageWithThreshold:(PTPDFNetLoggingLogLevel)threshold
                        message:(NSString *)message
                       filename:(NSString *)filename
                     lineNumber:(int)lineNumber;

/**
 * Logs a message to a particular stream with the logging system.
 *
 * @param threshold The importance of this log message.
 * @param stream The name of the stream to which the message belongs (a category label).
 * @param message The message to be logged.
 * @param filename The filename from which the log message originates.
 * @param lineNumber The line number from which the log message originates.
 */
+ (void)logMessageWithThreshold:(PTPDFNetLoggingLogLevel)threshold
                         stream:(PTPDFNetLoggingStreamName)stream
                        message:(NSString *)message
                       filename:(NSString *)filename
                     lineNumber:(int)lineNumber;

/**
 * Set the directory and filename of the log file used as the destination for disk-based logging.
 *
 * If the directory does not exist, it will be created.
 *
 * @param logDirectory The path of the directory containing the log file.
 * @param logFilename The name of the log file.
 *
 * @return Returns @c YES if we were able to open a log file successfully.
 */
+ (BOOL)setLogLocationWithDirectory:(NSString *)logDirectory
                           filename:(NSString *)logFilename;

/**
 * Set the filename of the log file used as the destination for disk-based logging.
 *
 * @param logFilename The name of the log file.
 *
 * @return Returns @c YES if the system was able to open a log file successfully.
 */
+ (BOOL)setLogLocationWithFilename:(NSString *)logFilename;

/**
 * Sets the threshold log level for a particular stream.
 *
 * Entries with a priority greater than or equal to the threshold level will be logged.
 *
 * @param streamName The name of the stream to be configured.
 * @param threshold The stream threshold.
 */
+ (void)setThresholdForLogStream:(PTPDFNetLoggingStreamName)streamName
                       threshold:(PTPDFNetLoggingLogLevel)threshold;

/**
 * Sets the log level for streams that do not otherwise have their level set.
 *
 * Entries with a priority greater than or equal to the threshold level will be logged.
 *
 * @param threshold The threshold log level.
 */
+ (void)setDefaultLogThreshold:(PTPDFNetLoggingLogLevel)threshold;

/**
 * Sets the global log cutoff threshold.
 *
 * *No* log statements with a level less than this will pass.
 * Entries with a priority greater than or equal to the cutoff threshold level will be logged.
 *
 * @param threshold The cutoff threshold log level.
 */
+ (void)setCutoffLogThreshold:(PTPDFNetLoggingLogLevel)threshold;

/**
 * Enables a particular log backend.
 *
 * @param backend The log backend to enable.
 *
 * @return Returns @c YES if the backend is available and functioning.
 */
+ (BOOL)enableLogBackend:(PTPDFNetLoggingLogBackend)backend;

/**
 * Disables a particular log backend.
 *
 * @param backend The log backend to disable.
 */
+ (void)disableLogBackend:(PTPDFNetLoggingLogBackend)backend;

- (instancetype)init PDFNET_UNAVAILABLE_MSG("PTPDFNetLogging is a static class");
+ (instancetype)new PDFNET_UNAVAILABLE_MSG("PTPDFNetLogging is a static class");

@end

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDocumentOptions;

/**
 * Options to be used when opening or accessing a document.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(DocumentOptions)
@interface PTDocumentOptions : NSObject <NSCopying>

/**
 * Initializes a newly created `PTDocumentOptions` instance.
 *
 * @return an initialized `PTDocumentOptions` instance
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a newly created `PTDocumentOptions` instance with an existing instance.
 *
 * @param options the existing options instance
 *
 * @return an initialized `PTDocumentOptions` instance
 */
- (instancetype)initWithOptions:(PTDocumentOptions *)options NS_DESIGNATED_INITIALIZER;

/**
 * A convenience method that creates and initializes a new `PTDocumentOptions` instance.
 *
 * @return a new `PTDocumentOptions` instance.
 */
+ (instancetype)options;

/**
 * The password to be used when opening the document.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, copy, nullable) NSString *password;

/**
 * The page number to which the document should be opened when it is opened for the first time.
 * The value of this property must be greater than zero.
 *
 * The last-read page number of previously-opened documents will take priority over this setting.
 *
 * The default value of this property is `1`.
 */
@property (nonatomic, assign) NSUInteger initialPageNumber;

/**
 * The file path extension to be used for the source document. When set, the value of this property
 * takes precedence over the file path extension of the source file path, if any.
 *
 * This property can be used to override the inherent file path extension of the source file path
 * in the case where the inherent extension is incorrect, or to provide an extension when it is
 * missing.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, copy, nullable) NSString *sourcePathExtension;

/**
 * Whether an experimental file coordination system should be used.
 *
 * File coordination is used to respond to external changes to a file (modification, moving, deletion, etc.).
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isExperimentalFileCoordinationEnabled) BOOL experimentalFileCoordinationEnabled 
    PT_DEPRECATED_MSG(10.6.0, "This API will be removed in a future version");

#pragma mark - Equality

/**
 * Returns a Boolean value that indicates whether the receiver and the given `options` are equal.
 *
 * @param options The options to be compared to the receiver. May be `nil`, in which case this method
 * returns `NO`.
 *
 * @return `YES` if the receiver and `options` are equal, otherwise `NO`.
 */
- (BOOL)isEqualToOptions:(nullable PTDocumentOptions *)options;

@end

NS_ASSUME_NONNULL_END

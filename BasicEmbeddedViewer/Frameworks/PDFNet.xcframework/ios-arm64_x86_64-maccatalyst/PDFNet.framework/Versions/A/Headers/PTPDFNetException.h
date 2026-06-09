//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <PDFNet/PDFNetDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPDFNetException;

PDFNET_EXTERN const NSExceptionName PTPDFNetExceptionName;

PDFNET_EXTERN NSString * const PTPDFNetExceptionFileNameUserInfoKey;
PDFNET_EXTERN NSString * const PTPDFNetExceptionLineNumberUserInfoKey;
PDFNET_EXTERN NSString * const PTPDFNetExceptionFunctionUserInfoKey;
PDFNET_EXTERN NSString * const PTPDFNetExceptionMessageUserInfoKey;
PDFNET_EXTERN NSString * const PTPDFNetExceptionErrorCodeUserInfoKey;

PDFNET_EXTERN
PDFNET_OBJC_RUNTIME_NAME(PTPDFNetException)
@interface PTPDFNetException : NSException

@property (nonatomic, readonly, copy, nullable) NSString *fileName;
@property (nonatomic, readonly, assign) int lineNumber;
@property (nonatomic, readonly, copy, nullable) NSString *function;
@property (nonatomic, readonly, copy, nullable) NSString *message;
@property (nonatomic, readonly, assign) int errorCode;

@end

NS_ASSUME_NONNULL_END

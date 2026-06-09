//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Foundation/Foundation.h>
#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>

#import <PDFNet/PDFNet.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDigitalSignaturesManager;
@class PTToolManager;

/**
 * An object that manages digital signature validation.
 */
PT_OBJC_RUNTIME_NAME(DigitalSignaturesManager)
@interface PTDigitalSignaturesManager : NSObject <PTOverridable>

/**
 * Specifies the location of the root certificate used for digital signature validation.
 */
@property (nonatomic, nullable, copy) NSString *rootCertificateFilePath;

@end

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXTERN
@interface PTFileSpec (PTAdditions)

/**
 * Returns the descriptive text associated with the file specification.
 */
- (nullable NSString *)GetDesc;

/**
 * Sets the file path for this file specification.
 *
 * @param filePath The file path to set for this file specification.
 */
- (void)SetFilePath:(NSString *)filePath;

/**
 * Returns whether the file for this file specification is embedded in the PDF document.
 */
- (BOOL)IsEmbedded;

/**
 * Returns the embedded file dictionary object for this file specification, if the file is embedded.
 *
 * @see `-IsEmbedded`
 */
- (nullable PTObj *)GetEmbeddedFile;

/**
 * Returns the subtype of the embedded file, if the file is embedded.
 *
 * @see `-IsEmbedded`
 * @see `-GetEmbeddedFile`
 */
- (nullable NSString *)GetEmbeddedFileType;

/**
 * Sets the subtype of the embedded file to the specified value.
 *
 * If the file for this file specification is not embedded, this method throws an exception.
 *
 * @param type the subtype of the embedded file
 */
- (void)SetEmbeddedFileType:(NSString *)type;

@end

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTDocumentBaseViewController.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Document view state persistence.
 */
@interface PTDocumentBaseViewController (ViewStatePersistence)

/**
 * Whether view state persistence is enabled.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=isViewStatePersistenceEnabled) BOOL viewStatePersistenceEnabled;

/**
 * The string used to identify the saved view state for a document among other metadata.
 *
 * The default value of this property is a Tools-specific identifier string.
 */
@property (nonatomic, class, copy, null_resettable) NSString *savedViewStateIdentifier;

/**
 * Saves the document's current view state.
 *
 * @param error On input, a pointer to an error object. If an error occurs , this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the view state was saved, `NO` otherwise if an error occurred
 *
 * @note In Swift, this method is imported as a throwing function.
 */
- (BOOL)saveCurrentViewStateForDocumentWithError:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 * Restores the document's saved view state.
 *
 * @param error On input, a pointer to an error object. If an error occurs , this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the view state was restored, `NO` otherwise if an error occurred
 *
 * @note In Swift, this method is imported as a throwing function.
 */
- (BOOL)restoreCurrentViewStateForDocumentWithError:(NSError * _Nullable __autoreleasing * _Nullable)error;

@end

NS_ASSUME_NONNULL_END

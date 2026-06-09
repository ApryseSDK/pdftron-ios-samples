//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTPDFDocumentModel.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTCoordinatedDocument;
@protocol PTCoordinatedDocumentDelegate;

/**
 * A `UIDocument` subclass backed by a `PTPDFDoc` object.
 *
 * To instantiate a new `PTCoordinatedDocument`, use `initWithFileURL:`.
 */
PT_OBJC_RUNTIME_NAME(CoordinatedDocument)
@interface PTCoordinatedDocument : UIDocument

/**
 * The PDF document model used to access the underlying PDFDoc.
 *
 * The value of this property is `nil` if the model is not loaded.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, readonly, strong, nullable) PTPDFDocumentModel *documentModel;

/**
 * The underlying PDF document. This property will be `nil` until the `UIDocument` is loaded.
 *
 * This property should not generally be set, except when the document may have been modified
 * by out outside process, and needs to be reloaded.
 *
 * To instantiate a new `PTCoordinatedDocument`, use `initWithFileURL:`.
 *
 */
@property (nonatomic, readonly, strong, nullable) PTPDFDoc *pdfDoc;

/**
 * The last error that this document experienced.
 */
@property (nonatomic, strong, nullable) NSError *error;

/**
 The delegate of the `PTCoordinatedDocument` object.
 */
@property (nonatomic, weak, nullable) id<PTCoordinatedDocumentDelegate> delegate;

/**
 * The save flag(s) that will be used if the system triggers a save. Default is `e_ptincremental`.
 */
@property (nonatomic) PTSaveOptions defaultSaveFlags;


- (void)saveToURL:(NSURL *)url withSaveOptions:(PTSaveOptions)saveOptions forSaveOperation:(UIDocumentSaveOperation)saveOperation completionHandler:(void (^ __nullable)(BOOL success))completionHandler;

@end

/**
 The methods declared by the `PTCoordinatedDocumentDelegate` protocol allow the adopting delegate
 to respond to messages from the `PTCoordinatedDocument` class.
 */
PT_OBJC_RUNTIME_NAME(CoordinatedDocumentDelegate)
@protocol PTCoordinatedDocumentDelegate<NSObject>

/**
 *
 * Notifies the conforming object that the coordinated document changed.
 *
 * @param coordinatedDocument The `PTCoordinatedDocument` that changed.
 */
-(void)coordinatedDocumentDidChange:(PTCoordinatedDocument*)coordinatedDocument;

/**
 *
 * Notifies the conforming object that the coordinated document changed.
 *
 * @param coordinatedDocument The `PTCoordinatedDocument` that generated the event.
 *
 * @param newURL The url that the item was moved/renamed to.
 */
-(void)coordinatedDocument:(PTCoordinatedDocument*)coordinatedDocument presentedItemDidMoveToURL:(NSURL *)newURL;

/**
 *
 * Used to control if the document will be saved.
 *
 * @param coordinatedDocument The `PTCoordinatedDocument` that generated the event.
 *
 * @return YES to save; NO to not save.
 *
 */
-(BOOL)coordinatedDocumentShouldSave:(PTCoordinatedDocument*)coordinatedDocument;

/**
*
* Used to control if the document will be autosaved when such a save is triggered by iOS.
*
* @param coordinatedDocument The `PTCoordinatedDocument` that generated the event.
*
* @return YES to save; NO to not save.
*
*/
-(BOOL)coordinatedDocumentShouldAutoSave:(PTCoordinatedDocument*)coordinatedDocument;

@end

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTToolManager.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A `PTAnnotationPasteboard` instance facilitates annotation copying and pasting on the behalf of a
 * `PTPDFViewCtrl` or `PTToolManager` instance. Annotation pasteboards can be shared between multiple
 * PDFViewCtrls, viewers, tabs, etc. to allow annotations to be easily copied between documents.
 */
PT_OBJC_RUNTIME_NAME(AnnotationPasteboard)
@interface PTAnnotationPasteboard : NSObject

/**
 * The default annotation pasteboard, which is shared between different `PTToolManager` instances.
 */
@property (nonatomic, class, readonly, strong) PTAnnotationPasteboard *defaultPasteboard;

/**
 * The source page number of the copied annotation(s). If there are no copied annotations.
 */
@property (nonatomic, assign) int sourcePageNumber;

/**
 * The annotations copied into the pasteboard. If there are no copied annotations, the value is `nil`.
 */
@property (nonatomic, readonly, copy, nullable) NSArray<PTAnnot *> *annotations;

/** Copies the specified annotations to the pasteboard.
 *
 * @param annotations The annotations to be copied.
 *
 * @param pdfViewCtrl The PDFViewCtrl containing the annotations' document.
 *
 * @param completion The block to execute after the annotations have been copied. You may specifiy
 * `nil` for this parameter.
 */
- (void)copyAnnotations:(NSArray<PTAnnot *> *)annotations withPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl fromPageNumber:(int)pageNumber completion:(void (^ _Nullable)(void))completion;

/**
 * Pastes the pasteboard's copied annotations on the specified page number and page-coordinate
 * location of the `PTPDFViewCtrl` instance.
 *
 * @param pageNumber The page number on which to paste the annotations.
 *
 * @param pagePoint The page-coordinates location at which to paste the annotations.
 *
 * @param pdfViewCtrl The PDFViewCtrl to which the annotations will be pasted.
 *
 * @param completion The block to execute after the annotations have been pasted. The pasted
 * annotations are passed to the block on success, or an `NSError` object is passed in the case of
 * an error. You may specify `nil` for this parameter.
 */
- (void)pasteAnnotationsOnPageNumber:(int)pageNumber atPagePoint:(PTPDFPoint *)pagePoint withPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl completion:(void (^ _Nullable)(NSArray<PTAnnot *> * _Nullable pastedAnnotations, NSError * _Nullable error))completion;

/**
 * Pastes the pasteboard's copied annotations on the specified page number and page-coordinate
 * location of the `PTPDFViewCtrl` instance.
 *
 * @param pageNumber The page number on which to paste the annotations.
 *
 * @param pagePoint The page-coordinates location at which to paste the annotations.
 *
 * @param toolManager The tool manager to whose `PTPDFViewCtrl` the annotations will be pasted.
 *
 * @param completion The block to execute after the annotations have been pasted. The pasted
 * annotations are passed to the block on success, or an `NSError` object is passed in the case of
 * an error. You may specify `nil` for this parameter.
*/
- (void)pasteAnnotationsOnPageNumber:(int)pageNumber atPagePoint:(PTPDFPoint *)pagePoint withToolManager:(PTToolManager *)toolManager completion:(void (^ _Nullable)(NSArray<PTAnnot *> * _Nullable pastedAnnotations, NSError * _Nullable error))completion;

/**
 * Clears the pasteboard of all copied annotations.
 */
- (void)clear;

@end

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDocumentViewState;

/**
 * A model class used to represent the state of a document in a viewer.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(DocumentViewState)
@interface PTDocumentViewState : NSObject <NSCoding, NSSecureCoding, NSCopying>

/**
 * Initializes a newly created `PTDocumentViewState` instance.
 *
 * @return an initialized `PTDocumentViewState` instance
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a newly created `PTDocumentViewState` instance with an existing instance.
 *
 * @param documentViewState The existing instance
 *
 * @return an initialized `PTDocumentViewState` instance
 */
- (instancetype)initWithDocumentViewState:(PTDocumentViewState *)documentViewState NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a newly created `PTDocumentViewState` instance with the specified coder.
 *
 * @param coder The coder
 *
 * @return an initialized `PTDocumentViewState` instance
 */
- (instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

/**
 * The number of the viewer's current page.
 *
 * The default value of this property is `0`.
 */
@property (nonatomic, assign) int pageNumber;

/**
 * The current zoom level of the viewer.
 *
 * The default value of this property is `1.0`.
 */
@property (nonatomic, assign) double zoom;

/**
 * The page presentation mode. This can be used to determine how to interpret the viewport rect.
 *
 * The default value of this property is `e_ptsingle_page`.
 */
@property (nonatomic, assign) PTPagePresentationMode pagePresentationMode;

/**
 * The viewport of the viewer, specified in the PDF page coordinates of the current page.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, copy, nullable) PTPDFRect *viewportPageRect;

@end

NS_ASSUME_NONNULL_END

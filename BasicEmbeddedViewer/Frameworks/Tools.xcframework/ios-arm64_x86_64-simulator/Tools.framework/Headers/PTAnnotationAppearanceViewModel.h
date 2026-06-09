//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTPDFAnnotationProperties.h>
#import <Tools/PTPDFAnnotationState.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPDFAnnotationProperties;
@class PTPDFAnnotationState;

/**
 * A representation of a PDF annotation.
 *
 * The class is parameterized by the annotation and properties types which must be subclasses of
 * the `PTAnnot` and `PTPDFAnnotationProperties` classes, respectively.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(AnnotationAppearanceViewModel)
@interface PTAnnotationAppearanceViewModel<AnnotationType: PTAnnot *, PropertiesType: PTPDFAnnotationProperties *> : NSObject

/**
 * Initializes a `PTAnnotationAppearanceViewModel` instance.
 *
 * @return An initialized `PTAnnotationAppearanceViewModel` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Configures the view model with the specified annotation.
 *
 * @param annotation The PDF annotation.
 *
 * @param pageNumber The number of the PDF page containing the annotation in the document.
 *
 * @param document The PDF document, or `nil`.
 *
 * @param outError On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the view model was configured, or `NO` if an error occurred.
 *
 * @note In Swift, this method is imported as a throwing function.
 */
- (BOOL)configureWithAnnotation:(AnnotationType)annotation
                   onPageNumber:(int)pageNumber
                     inDocument:(nullable PTPDFDoc *)document
                          error:(out NSError * _Nullable __autoreleasing * _Nullable)outError;

/**
 * The PDF annotation represented by this view model.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, readonly, strong, nullable) AnnotationType annotation;

/**
 * The number of the PDF page containing the represented annotation, or `0` if there is no annotation.
 *
 * @note The default value of this property is `0`.
 */
@property (nonatomic, readonly, assign) int pageNumber;

/**
 * The PDF document containing the represented annotation, or `nil` if there is no annotation.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, readonly, strong, nullable) PTPDFDoc *document;

#pragma mark - Annotation properties & state

/**
 * The properties for the represented annotation.
 *
 * @see `PTAnnotationAppearanceViewModel.propertiesClass`
 */
@property (nonatomic, readonly, strong) PropertiesType properties;

/**
 * The state of the represented annotation.
 *
 * @see `PTAnnotationAppearanceViewModel.stateClass`
 */
@property (nonatomic, readonly, strong) PTPDFAnnotationState *state;

@end

@interface PTAnnotationAppearanceViewModel (SubclassingHooks)

/**
 * The `PTPDFAnnotationProperties` subclass used for the `PTAnnotationAppearanceViewModel.properties`
 * instance property.
 *
 * Subclasses of `PTAnnotationAppearanceViewModel` should override this class property to return
 * the appropriate annotation properties class.
 *
 * @note The default value of this property is the `PTPDFAnnotationProperties` class.
 *
 * @see `PTAnnotationAppearanceViewModel.properties`
 */
@property (nonatomic, class, readonly, strong) Class propertiesClass;

/**
 * The `PTPDFAnnotationState` subclass used for the `PTAnnotationAppearanceViewModel.state` instance
 * property.
 *
 * Subclasses of `PTAnnotationAppearanceViewModel` should override this class property to return
 * the appropriate annotation state class.
 *
 * @note The default value of this property is the `PTPDFAnnotationState` class.
 *
 * @see `PTAnnotationAppearanceViewModel.state`
 */
@property (nonatomic, class, readonly, strong) Class stateClass;

/**
 * Updates the view model from the represented annotation.
 *
 * Subclasses of `PTAnnotationAppearanceViewModel` should override this method to update any state
 * dependent on the annotation.
 *
 * @param outError On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the view model was updated, or `NO` if an error occurred.
 *
 * @note In Swift, this method is imported as a throwing function.
 */
- (BOOL)updateWithError:(out NSError * _Nullable __autoreleasing * _Nullable)outError NS_REQUIRES_SUPER;

@end

NS_ASSUME_NONNULL_END

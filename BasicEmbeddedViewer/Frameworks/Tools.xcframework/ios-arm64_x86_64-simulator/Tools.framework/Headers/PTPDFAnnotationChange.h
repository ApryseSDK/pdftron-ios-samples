//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPDFAnnotationChange;

/**
 * The type of change represented by a `PTPDFAnnotationChange` instance.
 */
typedef NS_ENUM(NSUInteger, PTPDFAnnotationChangeType) {
    /**
     * Add annotation change type.
     */
    PTPDFAnnotationChangeTypeAdd,
    /**
     * Modify annotation change type.
     */
    PTPDFAnnotationChangeTypeModify,
    /**
     * Remove annotation change type.
     */
    PTPDFAnnotationChangeTypeRemove,
    
    /**
     * Flatten annotation change type.
     */
    PTPDFAnnotationChangeTypeFlatten,
} NS_SWIFT_NAME(PTPDFAnnotationChange.ChangeType);

/**
 * Instances of this class represent annotation changes (add, modify, remove, etc.).
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(PDFAnnotationChange)
@interface PTPDFAnnotationChange : NSObject

/**
 * Initializes a newly created `PTPDFAnnotationChange` instance.
 *
 * @param type The type of this change
 *
 * @param annotation The annotation involved in the change
 *
 * @param pageNumber The PDF page number of the annotation
 *
 * @return an initialized instance of the `PTPDFAnnotationChange` class
 */
- (instancetype)initWithChangeType:(PTPDFAnnotationChangeType)type
                     forAnnotation:(PTAnnot *)annotation
                      onPageNumber:(int)pageNumber NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

/**
 * The type of this change.
 */
@property (nonatomic, readonly, assign) PTPDFAnnotationChangeType type;

/**
 * The annotation involved in this change.
 */
@property (nonatomic, readonly, strong, nullable) PTAnnot *annotation;

/**
 * The PDF page number of this change's `annotation`.
 */
@property (nonatomic, readonly, assign) int pageNumber;

/**
 * Returns whether the receiver and the specified `PTPDFAnnotationChange` instance are equal.
 *
 * @param change The other `PTPDFAnnotationChange` instance to compare for equality
 *
 * @return `YES` if the receiver is equal to the specified change, `NO` otherwise
 */
- (BOOL)isEqualToChange:(PTPDFAnnotationChange *)change;

@end

@interface PTPDFAnnotationChange (ChangeCreation)

/**
 * Creates a new `PTPDFAnnotationChange` instance initialized with the specified parameters.
 *
 * @param type The type of the change
 *
 * @param annotation The annotation involved in the change
 *
 * @param pageNumber The PDF page number of the annotation
 *
 * @return an initialized instance of the `PTPDFAnnotationChange` class
 */
+ (instancetype)changeWithType:(PTPDFAnnotationChangeType)type
                 forAnnotation:(PTAnnot *)annotation
                  onPageNumber:(int)pageNumber;

@end

NS_ASSUME_NONNULL_END

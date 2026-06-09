//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/AnnotTypes.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PTAnnotationAuthorModel;
@protocol PTAnnotationModel;
@protocol PTDocumentModel;
@protocol PTPageModel;

/**
 * A protocol that defines the interface of a document model object.
 */
PT_OBJC_RUNTIME_NAME(DocumentModel)
@protocol PTDocumentModel <NSObject>
@required

/**
 * The string that uniquely identifies this document.
 */
@property (nonatomic, readonly, copy, nullable) NSString *identifier;

/**
 * The number of pages in the modelled PDF document.
 */
@property (nonatomic, readonly, assign) int pageCount;

/**
 * The filename of the modelled PDF document.
 */
@property (nonatomic, readonly, copy, nullable) NSString *filename;

#pragma mark - Pages

/**
 * The set of page model objects for this document.
 */
@property (nonatomic, readonly, copy, nullable) NSSet<id<PTPageModel>> *pages;

#pragma mark Annotation authors

/**
 * The annotation author model objects for this document.
 */
@property (nonatomic, readonly, copy, nullable) NSSet<id<PTAnnotationAuthorModel>> *authors;

@end

/**
 * A protocol that defines the interface of a page model object.
 */
PT_OBJC_RUNTIME_NAME(PageModel)
@protocol PTPageModel <NSObject>
@required

/**
 * The page number of the modelled PDF page.
 */
@property (nonatomic, readonly, assign) int pageNumber;

/**
 * The document model object that contains this page.
 */
@property (nonatomic, readonly, weak, nullable) id<PTDocumentModel> document;

/**
 * The annotations on this page.
 */
@property (nonatomic, readonly, copy, nullable) NSSet<id<PTAnnotationModel>> *annotations;

@end

/**
 * A protocol that defines the interface of an annotation model object.
 */
PT_OBJC_RUNTIME_NAME(AnnotationModel)
@protocol PTAnnotationModel <NSObject>
@required

/**
 * A string that uniquely identifies this annotation on its page.
 */
@property (nonatomic, readonly, copy, nullable) NSString *identifier;

/**
 * Whether this annotation is a placeholder that was created to establish a parent-reply
 * relationship.
 */
@property (nonatomic, readonly, getter=isPlaceholder) BOOL placeholder;

/**
 * The type of the modelled PDF annotation.
 */
@property (nonatomic, readonly) PTAnnotType type;

/**
 * The extended annotation type name of the modelled PDF annotation.
 */
@property (nonatomic, readonly, copy, nullable) PTExtendedAnnotName typeName;

/**
 * The extended annotation type of the modelled PDF annotation.
 */
@property (nonatomic, readonly) PTExtendedAnnotType extendedAnnotType;

/**
 * The opacity of the annotation, from `0.0` to `1.0`.
 *
 * The default value of this property is `1.0`.
 */
@property (nonatomic, readonly) double opacity;

/**
 * The page model object that contains this annotation.
 */
@property (nonatomic, readonly, weak, nullable) id<PTPageModel> page;

/**
 * The PDF page number of this annotation.
 */
@property (nonatomic, readonly) int pageNumber;

/**
 * The PDF page-space rect of this annotation.
 */
@property (nonatomic, readonly) CGRect pageRect;

/**
 * The lower-left x coordinate of the annotation, in PDF page-space coordinates.
 *
 * @see `pageRect`
 */
@property (nonatomic, readonly) CGFloat x;

/**
 * The lower-left y coordinate of the annotation, in PDF page-space coordinates.
 */
@property (nonatomic, readonly) CGFloat y;

/**
 * The width of the annotation, in PDF page-space coordinates.
 */
@property (nonatomic, readonly) CGFloat width;

/**
 * The height of the annotation, in PDF page-space coordinates.
 */
@property (nonatomic, readonly) CGFloat height;

/**
 * The text contents of the annotation.
 */
@property (nonatomic, readonly, copy, nullable) NSString *contents;

/**
 * The primary color of the annotation.
 */
@property (nonatomic, readonly, retain, nullable) UIColor *color;

/**
 * The creation date of the annotation.
 */
@property (nonatomic, readonly, copy, nullable) NSDate *creationDate;

/**
 * The modification date of the annotation.
 */
@property (nonatomic, readonly, copy, nullable) NSDate *modificationDate;

/**
 * The date of the last reply to this annotation.
 */
@property (nonatomic, readonly, copy, nullable) NSDate *lastReplyDate;

/**
 * The state of the annotation.
 */
@property (nonatomic, readonly, copy, nullable) NSString *state;

/**
 * The parent annotation of this reply.
 */
@property (nonatomic, readonly, weak, nullable) id<PTAnnotationModel> parent;

/**
 * The replies made to this annotation.
 */
@property (nonatomic, readonly, copy, nullable) NSSet<id<PTAnnotationModel>> *replies;

/**
 * The most recent reply, by creation date, made to this annotation.
 */
@property (nonatomic, readonly, strong, nullable) id<PTAnnotationModel> lastReply;

/**
 * The number of replies made to this annotation.
 *
 * This property is a convenience for the count of replies in the `replies` property.
 */
@property (nonatomic, readonly) int replyCount;

/**
 * The author of this annotation.
 */
@property (nonatomic, readonly, strong, nullable) id<PTAnnotationAuthorModel> author;

#pragma mark - Sectioning

/**
 * A string identifier that can be used to group annotations by creation date day.
 */
@property (nonatomic, readonly, copy, nullable) NSString *creationDateDaySectionIdentifier;

/**
 * A string identifier that can be used to group annotations by modification date day.
 */
@property (nonatomic, readonly, copy, nullable) NSString *modificationDateDaySectionIdentifier;

@end

/**
 * A protocol that defines the interface of an annotation author model object.
 */
PT_OBJC_RUNTIME_NAME(AnnotationAuthorModel)
@protocol PTAnnotationAuthorModel <NSObject>
@required

/**
 * A string that uniquely identifies this author.
 */
@property (nonatomic, readonly, copy, nullable) NSString *identifier;

/**
 * The display name of this author.
 */
@property (nonatomic, readonly, copy, nullable) NSString *name;

/**
 * The annotations created by this author.
 */
@property (nonatomic, readonly, copy, nullable) NSSet<id<PTAnnotationModel>> *annotations;

/**
 * The documents that this author has edited in some way.
 */
@property (nonatomic, readonly, copy, nullable) NSSet<id<PTDocumentModel>> *documents;

@end

NS_ASSUME_NONNULL_END

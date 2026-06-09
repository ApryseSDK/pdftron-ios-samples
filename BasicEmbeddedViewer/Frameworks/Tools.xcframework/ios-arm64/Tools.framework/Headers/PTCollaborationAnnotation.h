//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A class that represents a `PTAnnot` for collaboration purposes.
 * It is typically passed between an instance of a `PTCollaborationManager` and an object that
 * conforms to the `PTCollaborationServerCommunication` protocol as a means of describing annotations
 * that have been created, modified and deleted.
 */
PT_OBJC_RUNTIME_NAME(CollaborationAnnotation)
@interface PTCollaborationAnnotation : NSObject

/**
 * The annotation's unique ID.
 */
@property (nonatomic, copy, nullable) NSString* annotationID;

/**
 * The user ID of the annotation's creator. This is defined by the `PTCollaborationServerCommunication`.
 */
@property (nonatomic, copy, nullable) NSString* userID;

/**
 * The user name of the annotation's creator.
 */
@property (nonatomic, copy, nullable) NSString* userName;

/**
 * The XFDF representation of the annotation.
 */
@property (nonatomic, copy, nullable) NSString* xfdf;

/**
 * The annotation's parent annotation's annotationID.
 */
@property (nonatomic, copy, nullable) NSString* parent;

/**
 * The unique ID of the document with which this annotation is associated.
 */
@property (nonatomic, copy, nullable) NSString* documentID;

#pragma mark - Validation

/**
 * Whether the annotation is valid for an add action.
 */
@property (nonatomic, readonly, getter=isValidForAdd) BOOL validForAdd;

/**
 * Whether the annotation is valid for a modify action.
 */
@property (nonatomic, readonly, getter=isValidForModify) BOOL validForModify;

/**
 * Whether the annotation is valid for a remove action.
 */
@property (nonatomic, readonly, getter=isValidForRemove) BOOL validForRemove;

@end

NS_ASSUME_NONNULL_END

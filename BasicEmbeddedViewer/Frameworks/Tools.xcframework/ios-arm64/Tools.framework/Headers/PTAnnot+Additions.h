//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The reply type of an annotation.
 */
typedef NS_ENUM(NSUInteger, PTAnnotReplyType) {
    /**
     * The annotation is a reply to the annotation specified by the annotation's "in reply to" entry.
     */
    PTAnnotReplyTypeReply,
    
    /**
     * The annotation is grouped with the annotation specified by the annotation's "in reply to"
     * entry.
     */
    PTAnnotReplyTypeGroup,
    
    /**
     * The reply type of the annotation is unknown.
     */
    PTAnnotReplyTypeUnknown,
};

/**
 * Convenience methods for the `PTAnnot` class.
 */
PT_EXTERN
@interface PTAnnot (Additions)

#pragma mark - Color

/**
 * Returns the color of the annotation.
 *
 * The number of color components can be determined with the `-[PTAnnot GetColorCompNum]` method.
 *
 * @return The color of the annotation, or `nil` if no color is set.
 */
- (nullable PTColorPt *)GetColor;

#pragma mark - Geometry

#pragma mark Non-standard rotation

/**
 * Gets the (possibly) non-standard rotation of the annotation, in degrees.
 *
 * Standard rotation values are 0, 90, 180, and 270; other values are considered non-standard and
 * are returned as 0 by the `-[PTAnnot GetRotation]` method.
 *
 * @see `-[PTAnnot GetRotation]`
 */
- (int)GetNonStandardRotation;

/**
 * Returns whether the annotation has a non-standard rotation.
 *
 * @see `-[PTAnnot GetNonStandardRotation]`
 */
- (BOOL)HasNonStandardRotation;

#pragma mark Unrotated rect

/**
 * Gets the annotation's unrotated rectangle.
 *
 * @return The unrotated rectangle of the annotation, or `nil` if it is not specified.
 */
- (nullable PTPDFRect *)GetUnrotatedRect;

/**
 * Sets the annotation's unrotated rectangle.
 *
 * @param rect The unrotated rectangle.
 */
- (void)SetUnrotatedRect:(PTPDFRect *)rect;

/**
 * Clears the annotation's unrotated rectangle information, if any.
 */
- (void)ClearUnrotatedRect;

#pragma mark - Unique ID

/**
 * Retrieves an annotation's unique ID as a string.
 *
 * @return The unique identifier for this annotation as a string, or `nil` if the identifier is not
 * available.
 */
- (nullable NSString *)GetUniqueIDAsString;

/**
 * Sets the annotation's unique ID with the given string.
 *
 * @param uniqueIDString The unique identifier string to set for this annotation.
 */
- (void)SetUniqueIDWithString:(NSString *)uniqueIDString;

#pragma mark - Replies

/**
 * Retrieves the annotation's "in reply to" entry.
 *
 * @return the annotation's "in reply to" entry, or `nil` if the annotation does not have such an
 * entry.
 */
- (nullable PTObj *)GetInReplyTo;

/**
 * Retrieves the annotation's "in reply to" entry as an annotation object.
 *
 * @return the annotation's "in reply to" entry as an annotation object, or `nil` if the annotation
 * does not have such an entry or it does not correspond to an annotation object.
 */
- (nullable PTAnnot *)GetInReplyToAsAnnot;

/**
 * Retrieves the annotation's "in reply to" entry as a string. The entry is usually represented as a
 * string in a `PTFDFDoc` to allow for a situation where the annotation being replied to is not in
 * the same FDF file. In that case, the text string contains the contents of the "NM" entry of the
 * annotation being replied to.
 *
 * @return the annotation's "in reply to" entry as a string, or `nil` if the annotation does not have
 * such an entry or it is not a string.
 */
- (nullable NSString *)GetInReplyToAsString;

/**
 * Returns the reply type of the annotation. This value is only meaningful when the annotation has
 * an "in reply to" entry as well.
 *
 * @return the reply type of the annotation. The default value is `PTAnnotReplyTypeReply`.
 */
- (PTAnnotReplyType)GetReplyType;

- (nullable NSString *)identifierWithError:(NSError * _Nullable __autoreleasing * _Nullable)error;

@end

NS_ASSUME_NONNULL_END

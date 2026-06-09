//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - (Extended) annotation types and names

/**
 * Annotation types, including those of `PTAnnotType`, and extra types
 * that are determined based on an annotation's properties.
 */
typedef NS_ENUM(NSUInteger, PTExtendedAnnotType) {
    // Basic annotation types:
    
    /// Text annotation
    PTExtendedAnnotTypeText,
    /// Link annotation
    PTExtendedAnnotTypeLink,
    /// Free text annotation
    PTExtendedAnnotTypeFreeText,
    /// Line annotation
    PTExtendedAnnotTypeLine,
    /// Square annotation
    PTExtendedAnnotTypeSquare,
    /// Circle annotation
    PTExtendedAnnotTypeCircle,
    /// Polygon annotation (with `e_ptNone` return value from `-[PTMarkup GetBorderEffect]`)
    PTExtendedAnnotTypePolygon,
    /// Polyline annotation
    PTExtendedAnnotTypePolyline,
    /// Highlight annotation
    PTExtendedAnnotTypeHighlight,
    /// Underline annotation
    PTExtendedAnnotTypeUnderline,
    /// Squiggly-underline annotation
    PTExtendedAnnotTypeSquiggly,
    /// Strikeout annotation
    PTExtendedAnnotTypeStrikeOut,
    /// Rubber stamp annotation
    PTExtendedAnnotTypeStamp,
    /// Caret annotation
    PTExtendedAnnotTypeCaret,
    /// Ink annotation
    PTExtendedAnnotTypeInk,
    /// Pop-up annotation
    PTExtendedAnnotTypePopup,
    /// File attachment annotation
    PTExtendedAnnotTypeFileAttachment,
    /// Sound annotation
    PTExtendedAnnotTypeSound,
    /// Movie annotation
    PTExtendedAnnotTypeMovie,
    /// Widget annotation
    PTExtendedAnnotTypeWidget,
    /// Screen annotation
    PTExtendedAnnotTypeScreen,
    /// Printer's mark annotation
    PTExtendedAnnotTypePrinterMark,
    /// Trap network annotation
    PTExtendedAnnotTypeTrapNet,
    /// Watermark annotation
    PTExtendedAnnotTypeWatermark,
    /// 3D annotation
    PTExtendedAnnotType3D NS_SWIFT_NAME(threeDimensional),
    /// Redaction annotation
    PTExtendedAnnotTypeRedact,
    /// Projection annotation, Adobe supplement to ISO 32000
    PTExtendedAnnotTypeProjection,
    /// Rich Media annotation, Adobe supplement to ISO 32000
    PTExtendedAnnotTypeRichMedia,
    
    /// Any other annotation type, not listed in the PDF specification and unrecognized by PDFTron software
    PTExtendedAnnotTypeUnknown,
    
    // Custom annotation types:
    
    /// Arrow annotation
    PTExtendedAnnotTypeArrow,
    /// Signature annotation
    PTExtendedAnnotTypeSignature,
    /// Cloudy annotation (with `e_ptCloudy` return value from `-[PTMarkup GetBorderEffect]`)
    PTExtendedAnnotTypeCloudy,
    /// Ruler annotation
    PTExtendedAnnotTypeRuler,
    /// Perimeter annotation
    PTExtendedAnnotTypePerimeter,
    /// Area annotation
    PTExtendedAnnotTypeArea,
    /// Image stamp annotation
    PTExtendedAnnotTypeImageStamp,
    /// Pencil drawing annotation
    PTExtendedAnnotTypePencilDrawing,
    /// Freehand highlight annotation.
    PTExtendedAnnotTypeFreehandHighlight,
    /// Free text callout annotation.
    PTExtendedAnnotTypeCallout,
    /// Text redact annotation
    PTExtendedAnnotTypeTextRedact,
    /// Text field annotation
    PTExtendedAnnotTypeTextField,
    /// Check box annotation
    PTExtendedAnnotTypeCheckBox,
    /// Radio button annotation
    PTExtendedAnnotTypeRadioButton,
    /// Combo box annotation
    PTExtendedAnnotTypeComboBox,
    /// List box annotation
    PTExtendedAnnotTypeListBox,
    /// Signature field annotation
    PTExtendedAnnotTypeSignatureField,
    /// Date text annotation
    PTExtendedAnnotTypeDateText,
    /// Spacing text annotation
    PTExtendedAnnotTypeSpacingText,
    /// Eraser 'annotation'
    PTExtendedAnnotTypeEraser,
      /// Count annotation
    PTExtendedAnnotTypeCount,
    
    /// The last enum value representing the total count of existing types
    PTExtendedAnnotTypeLastEnumValue,
};

/**
 * Annotation type names matching the cases in the `PTExtendedAnnotType` enum.
 */
typedef NSString * PTExtendedAnnotName NS_TYPED_EXTENSIBLE_ENUM;

/// Text annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameText;
/// Link annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameLink;
/// Free text annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameFreeText;
/// Line annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameLine;
/// Square annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameSquare;
/// Circle annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameCircle;
/// Polygon annotation (with `e_ptNone` return value from `-[PTMarkup GetBorderEffect]`)
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNamePolygon;
/// Polyline annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNamePolyline;
/// Highlight annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameHighlight;
/// Underline annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameUnderline;
/// Squiggly-underline annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameSquiggly;
/// Strikeout annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameStrikeOut;
/// Image stamp annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameImageStamp;
/// Rubber stamp annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameStamp;
/// Caret annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameCaret;
/// Ink annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameInk;
/// Pop-up annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNamePopup;
/// File attachment annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameFileAttachment;
/// Sound annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameSound;
/// Movie annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameMovie;
/// Widget annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameWidget;
/// Screen annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameScreen;
/// Printer's mark annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNamePrinterMark;
/// Trap network annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameTrapNet;
/// Watermark annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameWatermark;
/// 3D annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameThreeDimensional;
/// Redaction annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameRedact;
/// Projection annotation, Adobe supplement to ISO 32000
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameProjection;
/// Rich Media annotation, Adobe supplement to ISO 32000
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameRichMedia;

/// Arrow annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameArrow;
/// Signature annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameSignature;
/// Cloudy annotation (with `e_ptCloudy` return value from `-[PTMarkup GetBorderEffect]`)
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameCloudy;
/// Ruler annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameRuler;
/// Perimeter annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNamePerimeter;
/// Area annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameArea;
/// Pencil drawing annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNamePencilDrawing;
/// Freehand highlight annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameFreehandHighlight;
/// Free text callout annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameCallout;
/// Text redaction annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameTextRedact;
/// Text field annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameTextField;
/// Check box annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameCheckBox;
/// Radio button annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameRadioButton;
/// Combo box annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameComboBox;
/// List box annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameListBox;
/// Signature field annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameSignatureField;
/// Date text annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameDateText;
/// Spacing text annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameSpacingText;
/// Count annotation
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameCount;
/// Eraser 'annotation'
PT_EXPORT const PTExtendedAnnotName PTExtendedAnnotNameEraser;

/**
 * Returns the extended annotation type for the given name.
 *
 * @param name the annotation type name
 *
 * @return the corresponding extended annotation type, or `PTExtendedAnnotTypeUnknown` if the name is not known
 */
PT_EXPORT PTExtendedAnnotType PTExtendedAnnotTypeFromName(_Nullable PTExtendedAnnotName name);

/**
 * Returns the annotation name for the given extended annotation type.
 *
 * @param type the extended annotation type
 *
 * @return the corresponding annotation name, or `nil` if the annotation type is not known
 */
PT_EXPORT _Nullable PTExtendedAnnotName PTExtendedAnnotNameFromType(PTExtendedAnnotType type);

/**
 * Returns a localized display name for the given extended annotation type.
 *
 * @param type the extended annotation type
 *
 * @return the localized display name, or `nil` if the annotation type is not known
 */
PT_EXPORT NSString * _Nullable PTLocalizedAnnotationNameFromType(PTExtendedAnnotType type);

/**
 * An identifying string applied to signature (stamp) annotations.
 */
PT_EXPORT NSString * const PTSignatureAnnotationIdentifier;

/**
 * An identifying string applied to image (stamp) annotations.
 */
PT_EXPORT NSString * const PTImageStampAnnotationIdentifier;

/**
 * An identifying string applied to image (stamp) annotations relating to the stamp's rotation.
 */
PT_EXPORT NSString * const PTImageStampAnnotationRotationIdentifier;

/**
 * An identifying string applied to image (stamp) annotations relating to the stamp's rotation.
 */
PT_EXPORT NSString * const PTImageStampAnnotationRotationDegreeIdentifier;

/**
 * An identifying string applied to free text annotations relating to the free text's rotation.
 */
PT_EXPORT NSString * const PTFreeTextAnnotationRotationDegreeIdentifier PT_DEPRECATED_MSG(11.9.0, "Use PTAnnot.getNonStandardRotation() instead.");

/**
 * An identifying string applied to image (stamp) annotations created with PencilKit.
 */
PT_EXPORT NSString * const PTPencilDrawingAnnotationIdentifier;

/**
 * This `PTAnnot` category provides methods to determine the extended annotation type of an annotation.
 */
@interface PTAnnot (PTExtendedAnnotType)

/**
 * The extended annotation type, which takes various annotation properties (border effect, etc.) into account.
 */
@property (nonatomic, readonly, assign) PTExtendedAnnotType extendedAnnotType;

@end

NS_ASSUME_NONNULL_END

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/AnnotTypes.h>
#import <Tools/PTMeasurementScale.h>
#import <Tools/PTOverrides.h>
#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Constants to identify different annotation properties.
 */
typedef NSString * PTAnnotStyleKey NS_TYPED_ENUM;

/**
 * Annotation color.
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyColor;
/**
 * Annotation stroke color.
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyStrokeColor;
/**
 * Annotation fill color.
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyFillColor;
/**
 * Annotation text color.
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyTextColor;
/**
 * Annotation line/border thickness.
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyThickness;
/**
 * Annotation opacity.
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyOpacity;
/**
 * Annotation stroke style.
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyStrokeStyle;
/**
 * Annotation border effect.
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyBorderEffect;
/**
 * Annotation border effect intensity.
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyBorderEffectIntensity;
/**
 * Annotation text size.
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyTextSize;
/**
 * Annotation label.
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyLabel;
/**
 * Measurement scale.
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyScale;
/**
 * Measurement precision.
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyPrecision;
/**
 * Measurement tool snap-to.
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeySnapping;
/**
 * Annotation font
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyFont;
/**
 * Annotation horizontal alignment
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyHorizontalAlignment;
/**
 * Annotation vertical alignment
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyVerticalAlignment;
/**
 * Annotation date format.
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyDateFormat;
/**
 * Line annotation end styles
 */
PT_EXPORT PTAnnotStyleKey const PTAnnotStyleKeyLineEndStyles;
/**
 * The maximum eraser width.
 */
PT_EXPORT double const PTAnnotStyleMaximumEraserWidth;

/**
 * The stroke style of the annotation.
 */
typedef NS_ENUM(NSUInteger, PTStrokeStyle) {
    /**
     * The plain solid style.
     */
    PTStrokeStylePlain,
    /**
     * The cloudy solid style.
     */
    PTStrokeStyleCloudy,
    /**
     * The dashed style.
     */
    PTStrokeStyleDashed,
} NS_SWIFT_NAME(PTAnnotStyle.StrokeStyle);

@class PTAnnotStyle;

/**
 * The methods declared by the PTAnnotStyleDelegate protocol allow the adopting delegate
 * to respond to messages from the `PTAnnotStyle` class.
 */
PT_OBJC_RUNTIME_NAME(AnnotStyleDelegate)
@protocol PTAnnotStyleDelegate <NSObject>

@optional

/**
 * Tells the delegate that the annotation color changed.
 */
- (void)annotStyle:(PTAnnotStyle *)annotStyle colorDidChange:(UIColor *)color;

/**
 * Tells the delegate that the annotation stroke color changed.
 */
- (void)annotStyle:(PTAnnotStyle *)annotStyle strokeColorDidChange:(UIColor *)strokeColor;

/**
 * Tells the delegate that the annotation fill color changed.
 */
- (void)annotStyle:(PTAnnotStyle *)annotStyle fillColorDidChange:(UIColor *)fillColor;

/**
 * Tells the delegate that the annotation text color changed.
 */
- (void)annotStyle:(PTAnnotStyle *)annotStyle textColorDidChange:(UIColor *)textColor;

/**
 * Tells the delegate that the annotation line/border thickness changed.
 */
- (void)annotStyle:(PTAnnotStyle *)annotStyle thicknessDidChange:(CGFloat)thickness;

/**
 * Tells the delegate that the annotation opacity changed.
 */
- (void)annotStyle:(PTAnnotStyle *)annotStyle opacityDidChange:(CGFloat)opacity;

/**
 * Tells the delegate that the annotation stroke style changed.
 */
- (void)annotStyle:(PTAnnotStyle *)annotStyle strokeStyleDidChange:(PTStrokeStyle)strokeStyle;

/**
 * Tells the delegate that the annotation border effect changed.
 */
- (void)annotStyle:(PTAnnotStyle *)annotStyle borderEffectDidChange:(PTBorderEffect)borderEffect;

/**
 * Tells the delegate that the annotation border effect intensity changed.
 */
- (void)annotStyle:(PTAnnotStyle *)annotStyle borderEffectIntensityDidChange:(double)borderEffectIntensity;

/**
 * Tells the delegate that the annotation text size changed.
 */
- (void)annotStyle:(PTAnnotStyle *)annotStyle textSizeDidChange:(CGFloat)textSize;

/**
 * Tells the delegate that the annotation label changed.
 */
- (void)annotStyle:(PTAnnotStyle *)annotStyle labelDidChange:(nullable NSString *)label;

/**
 * Tells the delegate that the annotation measurement scale changed.
 */
- (void)annotStyle:(PTAnnotStyle *)annotStyle measurementScaleDidChange:(PTMeasurementScale *)ruler;

/**
 * Tells the delegate that the measurement tool snapping was toggled.
 */
- (void)annotStyle:(PTAnnotStyle *)annotStyle snappingToggled:(BOOL)snappingEnabled;

/**
* Tells the delegate that the free text font descriptor changed.
*/
-(void)annotStyle:(PTAnnotStyle *)annotStyle fontNameDidChange:(NSString*)fontName;

/**
* Tells the delegate that the line end styles changed.
*/
-(void)annotStyle:(PTAnnotStyle *)annotStyle lineEndStylesDidChange:(NSArray<NSNumber *> *)lineEndStyles;
@end

/**
 * This class wraps a `PTAnnot` and is used to store style appearance and property information before
 * the information is saved back to the annotation.
 */
PT_OBJC_RUNTIME_NAME(AnnotStyle)
@interface PTAnnotStyle : NSObject <NSCopying, NSCoding, PTOverridable>

/**
 * Returns a new instance of an AnnotStyle.
 *
 * @param annotType The annotation type used to initalize this object's properties.
 */
- (instancetype)initWithAnnotType:(PTExtendedAnnotType)annotType NS_DESIGNATED_INITIALIZER;

/**
 * Returns a new instance of an AnnotStyle for reflow webview.
 *
 * @param annotType The annotation type used to initalize this object's properties.
 */
- (instancetype)initWithAnnotTypeForWebView:(PTExtendedAnnotType)annotType NS_DESIGNATED_INITIALIZER;

/**
 * Returns a new instance of an AnnotStyle.
 *
 * @param annot The annotation used to initialize this object's properties.
 */
- (instancetype)initWithAnnot:(PTAnnot *)annot;

/**
 * Returns a new instance of an AnnotStyle.
 *
 * @param annot The annotation used to initialize this object's properties.
 *
 * @param pdfDoc The `PTPDFDoc` which the annotation is part of. This is required
 * to change a `PTFreeText`'s font.
 *
 */
- (instancetype)initWithAnnot:(PTAnnot *)annot onPDFDoc:(nullable PTPDFDoc *)pdfDoc NS_DESIGNATED_INITIALIZER;

/**
 * Returns a new instance of an AnnotStyle.
 *
 * @param coder The coder used to initialize this object's properties.
*/
- (instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

/**
 * The annotation type whose style appearance and properties are being controlled by this object.
 */
@property (nonatomic, readonly) PTExtendedAnnotType annotType;

/**
 * The annotation whose style appearance and properties are being controlled by this object.
 */
@property (nonatomic, readonly, strong, nullable) PTAnnot *annot;

/**
 * A list of the currently available style keys for the annotation type.
 */
@property (nonatomic, readonly, copy) NSArray<PTAnnotStyleKey> *availableStyleKeys;

/**
 * The color of the annotation. This is also an alias for the stroke color.
 */
@property (nonatomic, strong, nullable) UIColor *color;

/**
 * The stroke color of the annotation.
 */
@property (nonatomic, strong, nullable) UIColor *strokeColor;

/**
 * The fill color of the annotation.
 */
@property (nonatomic, strong, nullable) UIColor *fillColor;

/**
 * The text color of a free text annotation.
 */
@property (nonatomic, strong, nullable) UIColor *textColor;

/**
 * The line, stroke, or border thickness of the annotation.
 */
@property (nonatomic) CGFloat thickness;

/**
 * The opacity of the annotation.
 */
@property (nonatomic) CGFloat opacity;

/**
 * The stroke style of the annotation.
 */
@property (nonatomic) PTStrokeStyle strokeStyle;

/**
 * The border effect of the annotation.
 */
@property (nonatomic) PTBorderEffect borderEffect;

/**
 * The border effect intensity of the annotation.
 */
@property (nonatomic) double borderEffectIntensity;

/**
 * The text size of a free text annotation.
 */
@property (nonatomic) CGFloat textSize;

/**
 * The font descriptor to use to choose the free text font.
 */
@property (nonatomic, copy) NSString* fontName;

/**
 * The horizontal alignment of a free text annotation.
 */
@property (nonatomic) NSInteger horizontalAlignment;

/**
 * The vertical alignment of a free text annotation.
 */
@property (nonatomic) NSInteger verticalAlignment;

/**
 * The label applied to the annotation.
 */
@property (nonatomic, copy, nullable) NSString *label;

/**
 * The date format applied to the date text.
 */
@property (nonatomic, copy) NSString *dateFormat;

/**
 * The date of the date text.
 */
@property (nonatomic, copy) NSDate *date;
/**
 * The measurement scale for a measurement annotation.
 */
@property (nonatomic, strong, nullable) PTMeasurementScale *measurementScale;

/**
 * The line start style.
 */
@property (nonatomic) PTEndingStyle lineStartStyle;

/**
 * The line end style.
 */
@property (nonatomic) PTEndingStyle lineEndStyle;

/**
 * The line end styles.
 */
@property (nonatomic, copy) NSArray<NSNumber *> *lineEndStyles;

/**
 * Whether measurement tool snapping is enabled.
 */
@property (nonatomic) BOOL snappingEnabled;

/**
 * Whether `saveChanges` also saves the current style properties as the defaults
 * for the annotation type.
 *
 * The default valus is `YES`.
 */
@property (nonatomic) BOOL saveValuesAsDefaults;

/**
 * A calculated convenience string used for displaying the current thickness.
 */
@property (nonatomic, readonly, copy) NSString *thicknessIndicatorString;

/**
 * A calculated convenience string used for displaying the current opacity.
 */
@property (nonatomic, readonly, copy) NSString *opacityIndicatorString;

/**
 * A calculated convenience string used for displaying the current text size.
 */
@property (nonatomic, readonly, copy) NSString *textSizeIndicatorString;

/**
 * Configure text field's available style keys to edit text's style.
 */
- (void)configureTextField:(BOOL)textOnly;

/**
 * Save the current style properties back to the annotation.
 */
- (void)saveChanges;

/**
 * Apply the current style properties to the given annotation.
 */
- (void)applyToAnnotation:(PTAnnot *)annotation;

/**
 * Apply the current style properties to the given annotation and document.
 */
- (void)applyToAnnotation:(PTAnnot *)annotation doc:(nullable PTPDFDoc *)doc;

/**
 * Set the current style properties as the defaults for the annotation type.
 */
- (void)setCurrentValuesAsDefaults;

/**
 * An object that conforms to the AnnotStyleDelegate protocol.
 */
@property (nonatomic, weak, nullable) id<PTAnnotStyleDelegate> delegate;

/**
 * When instantiated via `initWithCoder`, if any properties were not encoded, they will be listed here.
 */
@property (nonatomic, readonly, strong, nullable) NSArray<NSString*>* uninitializedProperties;

/**
 * Compares the receiving annotation style instance to another instance.
 *
 * @param annotStyle an other annotation style instance
 *
 * @return `YES` if the annotation style instance is equal to the receiving instance, otherwise `NO`
 */
- (BOOL)isEqualToAnnotStyle:(PTAnnotStyle *)annotStyle;




- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

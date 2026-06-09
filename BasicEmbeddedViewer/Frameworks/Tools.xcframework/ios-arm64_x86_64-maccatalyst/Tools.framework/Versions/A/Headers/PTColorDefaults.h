//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/AnnotTypes.h>
#import <Tools/PTMeasurementScale.h>
#import <Tools/PTAnnotStyle.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>

// annotation attributes
#define ATTRIBUTE_STROKE_COLOR                @"Color"
#define ATTRIBUTE_TEXT_COLOR                  @"TextColor"
#define ATTRIBUTE_FILL_COLOR                  @"FillColor"
#define ATTRIBUTE_OPACITY                     @"Opacity"
#define ATTRIBUTE_STROKE_STYLE                @"StrokeStyle"
#define ATTRIBUTE_BORDER_EFFECT               @"BorderEffect"
#define ATTRIBUTE_BORDER_EFFECT_INTENSITY     @"BorderEffectIntensity"
#define ATTRIBUTE_BORDER_THICKNESS            @"BorderThickness"
#define ATTRIBUTE_FREETEXT_SIZE               @"FreeTextSize"
#define ATTRIBUTE_FREETEXT_FONT               @"FreeTextFont"
#define ATTRIBUTE_FREETEXT_V_ALIGNMENT        @"FreeTextVerticalAlignment"
#define ATTRIBUTE_FREETEXT_H_ALIGNMENT        @"FreeTextHorizontalAlignment"
#define ATTRIBUTE_DATETEXT_FORMAT             @"DateTextFormat"
#define ATTRIBUTE_MEASUREMENT_SCALE           @"MeasurementScale"
#define ATTRIBUTE_COUNT_LABEL                 @"CountLabel"
#define ATTRIBUTE_LINE_END_STYLES             @"LineEndStyles"

NS_ASSUME_NONNULL_BEGIN

/**
 * Used to persist annotion properties to user defaults so that the next annotation
 * of that type that is created can have the same properties.
 */
PT_OBJC_RUNTIME_NAME(ColorDefaults)
@interface PTColorDefaults : NSObject

/**
 * The colour palette used in the colour picker to stroke and fill different annotations.
 * The colours are:
 * #F1A099, #FFC680, #FFE6A2, #80E5B1, #92E8E8, #A6BEF4, #E2A1E6,
 * #E44234, #FF8D00, #FFCD45, #00CC63, #25D2D1, #4E7DE9, #C544CE,
 * #88271F, #B54800, #D69A00, #007A3B, #167E7D, #2E4B8B, #76287B,
 * #00000000, #FFFFFF, #CDCDCD, #9C9C9C, #696969, #373737, #000000.
 */
@property (class, nonatomic, copy) NSArray<UIColor *> *defaultColorPickerColors;

/**
 * The colour palette used in the colour picker for highlight and freehand highlight annotations.
 * The colours are:
 * #ff0000, #ff7f02, #ffff00, #00ff00, #00ffff, #0000ff, #ff00ff,
 * #ff6666, #ffb267, #ffff66, #66ff66, #6bfcfc, #6666ff, #ff66ff,
 * #ff9999, #ffcb99, #ffff99, #99ff99, #b2ffff, #9999ff, #ff99ff,
 * #ffcccc, #ffe5cc, #ffffcc, #ccffcc, #dcffff, #ccccff, #ffccff.
 */
@property (class, nonatomic, copy) NSArray<UIColor *> *highlightColorPickerColors;

/**
 * Sets the default `UIColor` for a given annotation type and attribute.
 *
 * @param type The type of annotation.
 *
 * @param attribute The annotation attribute. Arbitrary strings may be used to define
 * attributes. Standard attributes are defined in the header as `ATTRIBUTE_STROKE_COLOR`,
 * `ATTRIBUTE_FILL_COLOR`, `ATTRIBUTE_OPACITY`, `ATTRIBUTE_BORDER_THICKNESS` and
 * `ATTRIBUTE_FREETEXT_SIZE`.
 *
 * @param mode The color post processing mode.
 *
 *
 */
+(void)setDefaultColor:(UIColor*)color forAnnotType:(PTExtendedAnnotType)type attribute:(NSString*)attribute colorPostProcessMode:(PTColorPostProcessMode)mode;

/**
 * Gets the `UIColor` for a given annotation type and attribute.
 *
 * @param type The type of annotation.
 *
 * @param attribute The annotation attribute. Arbitrary strings may be used to define
 * attributes. Standard attributes are defined in the header as `ATTRIBUTE_STROKE_COLOR`,
 * `ATTRIBUTE_FILL_COLOR`, `ATTRIBUTE_OPACITY`, `ATTRIBUTE_BORDER_THICKNESS` and
 * `ATTRIBUTE_FREETEXT_SIZE`.
 *
 * @param mode The color post processing mode.
 *
 * @return The `PTColorPt`.
 *
 */
+(UIColor*)defaultColorForAnnotType:(PTExtendedAnnotType)type attribute:(NSString*)attribute colorPostProcessMode:(PTColorPostProcessMode)mode;


/**
 * Gets the `PTColorPt` for a given annotation type and attribute.
 *
 * @param type The type of annotation.
 *
 * @param attribute The annotation attribute. Arbitrary strings may be used to define
 * attributes. Standard attributes are defined in the header as `ATTRIBUTE_STROKE_COLOR`,
 * `ATTRIBUTE_FILL_COLOR`, `ATTRIBUTE_OPACITY`, `ATTRIBUTE_BORDER_THICKNESS` and
 * `ATTRIBUTE_FREETEXT_SIZE`.
 *
 * @param mode The color post processing mode.
 *
 * @return The `PTColorPt`.
 *
 */
+(PTColorPt*)defaultColorPtForAnnotType:(PTExtendedAnnotType)type attribute:(NSString*)attribute colorPostProcessMode:(PTColorPostProcessMode)mode;


/**
 * Gets the number of color components for an attribute of an annotation type
 *
 * @param type The type of annotaiton.
 *
 * @param attribute The annotation attribute. Arbitrary strings may be used to define
 * attributes. Standard attributes are defined in the header as `ATTRIBUTE_STROKE_COLOR`,
 * `ATTRIBUTE_FILL_COLOR`, `ATTRIBUTE_OPACITY`, A`TTRIBUTE_BORDER_THICKNESS` and
 * `ATTRIBUTE_FREETEXT_SIZE`.
 *
 * @return The number of components: 0 or 3.
 */
+(int)numCompsInColorPtForAnnotType:(PTExtendedAnnotType)type attribute:(NSString*)attribute;


/**
 * Gets the default opacity for an annotaiton of type `type`.
 *
 * @param opacity The opacity of the annotation, from 0. (fully transparant) to 1. (fully opaque).
 *
 * @param type The type of annotaiton.
 */
+(void)setDefaultOpacity:(double)opacity forAnnotType:(PTExtendedAnnotType)type;

/**
 * Sets the default opacity for an annotaiton of type `type`.
 *
 * @param type The type of annotaiton.
 *
 * @return The opacity of the annotation, from 0. (fully transparant) to 1. (fully opaque).
 */
+(double)defaultOpacityForAnnotType:(PTExtendedAnnotType)type;

/**
 * Sets the default border thickness for an annotaiton of type `type`.
 *
 * @param thickness The thickness of the border in points.
 *
 * @param type The type of annotaiton.
 */
+(void)setDefaultBorderThickness:(double)thickness forAnnotType:(PTExtendedAnnotType)type;

/**
 * Gets the default border thickness for an annotaiton of type `type`.
 *
 * @param type The type of annotaiton.
 *
 * @return The border thickness in points.
 */
+(double)defaultBorderThicknessForAnnotType:(PTExtendedAnnotType)type;

/**
 * Sets the default stroke style for an annotation of type `type`.
 *
 * @param strokeStyle The stroke style of the annotation.
 *
 * @param type The type of annotaiton.
 */
+ (void)setDefaultStrokeStyle:(PTStrokeStyle)strokeStyle forAnnotType:(PTExtendedAnnotType)type;

/**
 * Gets the default stroke style for an annotation of type `type`.
 *
 * @param type The type of annotaiton.
 *
 * @return The stroke style.
 */
+ (PTStrokeStyle)defaultStrokeStyleForAnnotType:(PTExtendedAnnotType)type;

/**
 * Sets the default border effect for an annotation of type `type`.
 *
 * @param borderEffect The border effect of the annotation.
 *
 * @param type The type of annotaiton.
 */
+(void)setDefaultBorderEffect:(PTBorderEffect)borderEffect forAnnotType:(PTExtendedAnnotType)type;

/**
 * Gets the default border effect for an annotation of type `type`.
 *
 * @param type The type of annotaiton.
 *
 * @return The border effect.
 */
+(PTBorderEffect)defaultBorderEffectForAnnotType:(PTExtendedAnnotType)type;

/**
 * Gets the default dash pattern.
 *
 * @param width The border width of annotaiton.
 *
 * @return The dash pattern.
 */
+ (NSMutableArray *)defaultDashEffectForWidth:(CGFloat)width;
/**
 * Sets the default border effect intensity for an annotation of type `type`.
 *
 * @param borderEffectIntensity The border effect of the annotation.
 *
 * @param type The type of annotaiton.
 */
+(void)setDefaultBorderEffectIntensity:(double)borderEffectIntensity forAnnotType:(PTExtendedAnnotType)type;

/**
 * Gets the default border effect intensity for an annotation of type `type`.
 *
 * @param type The type of annotaiton.
 *
 * @return The border effect intensity.
 */
+(double)defaultBorderEffectIntensityForAnnotType:(PTExtendedAnnotType)type;

/**
 * Set the font size for a free text annotation.
 *
 * @param size The size of the font in points.
 */
+(void)setDefaultFreeTextSize:(double)size forAnnotType:(PTExtendedAnnotType)type;

/**
 * Set the font size for a free text annotation.
 *
 * @param size The size of the font in points.
 */
+(void)setDefaultFreeTextSize:(double)size;

/**
 * The font size for free text annotations. If one has not been previous set with
 * `setDefaultFreeTextSize:` it will return 16.0.
 *
 * @return A font size.
 */
+(double)defaultFreeTextSize;

/**
 * The font size for free text annotations. If one has not been previous set with
 * `setDefaultFreeTextSize:` it will return 16.0.
 *
 * @return A font size.
 */
+(double)defaultFreeTextSizeForAnnotType:(PTExtendedAnnotType)annotType;

/**
 * Set the font name for a free text annotation. This must be the postscript font name,
 * which is returned via `myUIFontDescriptor.postscriptName` or `myUIFont.fontName`.
 *
 * @param fontName The name of the font.
 */
+(void)setDefaultFreeTextFontName:(nullable NSString*)fontName;

/**
* Set the font name for a free text annotation. This must be the postscript font name,
* which is returned via `myUIFontDescriptor.postscriptName` or `myUIFont.fontName`.
*
* @param fontName The name of the font.
*/
+(void)setDefaultFreeTextFontName:(nullable NSString*)fontName forAnnotType:(PTExtendedAnnotType)type;

/**
 * The vertical alignment for free text annotations. If one has not been previous set with
 * `setDefaultFreeTextVerticalAlignment:` it will return 0.
 *
 * @return An integer represents vertical alignment. 0 - top alignment; 1 - center alignment; 2 - bottom alignment.
 */
+ (NSInteger)defaultFreeTextVerticalAlignment;

/**
 * Set the vertical alignment for a free text annotation.
 *
 * @param verticalAlignment An integer represents vertical alignment. 0 - top alignment; 1 - center alignment; 2 - bottom alignment.
*/
+ (void)setDefaultFreeTextVerticalAlignment:(NSInteger)verticalAlignment;

/**
 * The horizontal alignment for free text annotations. If one has not been previous set with
 * `setDefaultFreeTextVerticalAlignment:` it will return 0.
 *
 * @return An integer represents vertical alignment. 0 - left alignment; 1 - center alignment; 2 - right alignment; 3 - justify alignment.
 */
+ (NSInteger)defaultFreeTextHorizontalAlignment;

/**
 * Set the horizontal alignment for a free text annotation.
 *
 * @param horizontalAlignment An integer represents horizontal alignment. 0 - left alignment;
 * 1 - center alignment; 2 - right alignment; 3 - justify alignment.
*/
+ (void)setDefaultFreeTextHorizontalAlignment:(NSInteger)horizontalAlignment;

/**
* Set the date format for a date text annotation.
*
* @param format The format of the date.
*/
+ (void)setDefaultDateTextFormat:(NSString*)format;

/**
 * The date format for date text annotations. If one has not been previously set with
 * `setDefaultDateTextFormat:` it will return "MMMM dd, yyyy".
 *
 * @return A date format.
 */
+ (NSString *)defaultDateTextFormat;

/**
 * The font name for free text annotations. If one has not been previous set with
 * `setDefaultFreeTextFontName:` it will return Helvetica.
 *
 * @return The name of the font.
 */
+(NSString*)defaultFreeTextFontName;

/**
 * The font name for free text annotations. If one has not been previous set with
 * `setDefaultFreeTextFontName:` it will return Helvetica.
 *
 * @return The name of the font.
 */
+(NSString*)defaultFreeTextFontNameForAnnotType:(PTExtendedAnnotType)annotType;


/**
 * Sets the default scale and precision for a ruler, perimeter, or area annotation.
 *
 * @param measurementScale The `PTMeasurementScale` containing the scale and precision information.
 */
+(void)setDefaultMeasurementScale:(PTMeasurementScale *)measurementScale forAnnotType:(PTExtendedAnnotType)type;

/**
 * The default scale and precision for a ruler, perimeter, or area annotation.
 *
 * @return A a `PTMeasurementScale`.
 */
+(PTMeasurementScale *)defaultMeasurementScaleForAnnotType:(PTExtendedAnnotType)type;

/**
 * The default group label for a count annotation.
 *
 * @return The label of the group.
 */
+ (nullable NSString *)defaultCountGroupLabel;

/**
 * Sets the default group labael for a count annotation.
 *
 * @param label The group label to be set.
 */
+ (void)setDefaultCountGroupLabel:(nullable NSString *)label;


/**
 * Sets the default line ending styles for a line annotation.
 *
 * @param lineEndStyles An array of `PTEndingStyles`, e.g. @[@(e_ptl_None),@(e_ptOpenArrow)]
 *
 * @param type The annotation type.
 */
+ (void)setDefaultLineEndStyles:(NSArray *)lineEndStyles forAnnotType:(PTExtendedAnnotType)type;

/**
 * The default line ending styles for a line annotation.
 *
 * @return The line ending styles of the annotation.
 */
+ (NSArray *)defaultLineEndStylesForAnnotType:(PTExtendedAnnotType)type;

/**
 * Converts a `UIColor` to a `PTColorPt`
 *
 * @param uiColor The `UIColor` to be converted
 *
 * @return A `PTColorPt` that represents the same color as the input `uiColor`
 */
+(PTColorPt*)colorPtFromUIColor:(UIColor*)uiColor;

/**
 * Gets the number of `PTColorPt` components for a given `UIColor`
 *
 * @param color The `UIColor` to examine
 *
 * @return The number of `PTColorPt` components: 0 or 3.
 */
+ (int)numCompsInColorPtForUIColor:(UIColor *)color;

/**
 * Converts a 'PTColorPT` to a `UIColor`
 *
 * @param colorpt The `PTColorPt` to be converted
 *
 * @param compNum The number of colorants (tint components) used in the color point
 *
 * @return A `UIColor` that represents the same color as the input `colorpt`
 */
+(nullable UIColor*)uiColorFromColorPt:(PTColorPt*)colorpt compNum:(int)compNum;

@end

NS_ASSUME_NONNULL_END

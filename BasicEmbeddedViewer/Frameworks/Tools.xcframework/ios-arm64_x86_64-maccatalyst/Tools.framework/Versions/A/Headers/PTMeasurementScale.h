//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/AnnotTypes.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * PTMeasurementUnitType NS_TYPED_EXTENSIBLE_ENUM;
static const PTMeasurementUnitType PTMeasurementUnitPoints = @"pt";
static const PTMeasurementUnitType PTMeasurementUnitInches = @"in";
static const PTMeasurementUnitType PTMeasurementUnitMillimeters = @"mm";
static const PTMeasurementUnitType PTMeasurementUnitCentimeters = @"cm";
static const PTMeasurementUnitType PTMeasurementUnitMeters = @"m";
static const PTMeasurementUnitType PTMeasurementUnitKilometers = @"km";
static const PTMeasurementUnitType PTMeasurementUnitFeet = @"ft";
static const PTMeasurementUnitType PTMeasurementUnitYards = @"yd";
static const PTMeasurementUnitType PTMeasurementUnitMiles = @"mi";
static const PTMeasurementUnitType PTMeasurementUnitNauticalMiles = @"nmi";
/**
 * A PTMeasurementScale is used to describe a measurement's conversion factors.
 */
PT_OBJC_RUNTIME_NAME(MeasurementScale)
@interface PTMeasurementScale : NSObject <NSCoding>

/**
 * Initializes a new instance of the class.
 *
 * @param baseValue The base conversion value in document space.
 */
- (instancetype)initWithBaseValue:(CGFloat)baseValue baseUnit:(NSString *)baseUnit translateValue:(CGFloat)translateValue translateUnit:(NSString *)translateUnit precision:(int)precision fractionPrecision:(int)fractionPrecision fractionDisplayEnabled:(BOOL)fractionDisplayEnabled NS_DESIGNATED_INITIALIZER PT_DEPRECATED_MSG(10.6, "Please use the PTMeasurementUnitType initializer instead");;

/**
 * Initializes a new instance of the class.
 *
 * @param baseValue The base conversion value in document space.
 */
- (instancetype)initWithBaseValue:(CGFloat)baseValue baseUnitType:(PTMeasurementUnitType)baseUnit translateValue:(CGFloat)translateValue translateUnitType:(PTMeasurementUnitType)translateUnit precision:(int)precision fractionPrecision:(int)fractionPrecision fractionDisplayEnabled:(BOOL)fractionDisplayEnabled NS_DESIGNATED_INITIALIZER;

/**
 * Sets the precision to display the measurement in fraction.
 *
 * @param fractionPrecision The precision with which to display the measurement in fraction.
 * Will be ignored if fraction display is disabled.
 */
- (void)setFractionPrecision:(int)fractionPrecision;

/**
 * Enables/disables displaying fraction number for measurement.
 *
 * @param fractionDisplayEnabled Whether to enable or disable the fraction display.
 */
- (void)enableFractionDisplay:(BOOL)fractionDisplayEnabled;

/**
 * The base value of the conversion. This is in document space.
 */
@property (nonatomic) CGFloat baseValue;

/**
 * The units of the base value.
 */
@property (nonatomic, copy) NSString *baseUnit;

/**
 * The translation value of the conversion. This is in world space.
 */
@property (nonatomic) CGFloat translateValue;

/**
 * The units of the translation value.
 */
@property (nonatomic, copy) NSString *translateUnit;

/**
 * The precision with which to display the measurement.
 */
@property (nonatomic) int precision;

/**
 * The precision with which to display the measurement in fraction, where the number is the denominator, eg 1/fractionPrecision of an inch. Powers of 2 supported (2,4,8, etc.).
 */
@property (nonatomic) int fractionPrecision;

/**
 * Whether to enable or disable the fraction display.
 */
@property (nonatomic) BOOL fractionDisplayEnabled;


- (instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

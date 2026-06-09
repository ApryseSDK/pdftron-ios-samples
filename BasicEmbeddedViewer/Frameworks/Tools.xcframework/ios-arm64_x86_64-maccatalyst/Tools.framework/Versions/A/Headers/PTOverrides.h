//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A class conforming to the `PTOverridable` protocol can be overridden with a subclass, registered
 * with the `PTOverrides` class. Once registered, the provided subclass will be used instead of the
 * original class wherever an instance is created.
 */
PT_OBJC_RUNTIME_NAME(Overridable)
@protocol PTOverridable <NSObject>
@optional

/**
 * Returns a new instance of the receiving class, or a subclass if the receiving class has been
 * overridden.
 *
 * @return a new instance of the receiving class or a subclass
 */
+ (instancetype)allocOverridden;

@end

/**
 * The `PTOverrides` class is used to register overridden subclasses of classes defined in the Tools
 * library. Once a class conforming to the `PTOverridable` protocol has been "overridden", whenever an
 * instance of the original class would be created the subclass is used instead.
 */
PT_OBJC_RUNTIME_NAME(Overrides)
@interface PTOverrides : NSObject

/**
 * Adds an overridden subclass of a class conforming to the `PTOverridable` protocol.
 *
 * @param subclass a subclass to use in place of its superclass
 *
 * @note An exception is thrown if none of the subclass's superclasses conform to the required
 * `PTOverridable` protocol.
 */
+ (void)addOverriddenClass:(Class)subclass;

/**
 * Override the given class with a subclass.
 *
 * @param cls the class to override, conforming to the `PTOverridable` protocol
 *
 * @param subclass the subclass to use in place of the `cls`
 */
+ (void)overrideClass:(Class)cls withClass:(Class)subclass;

/**
 * Returns the overridden subclass for the given class, if one has been registered.
 *
 * @param cls the original class
 *
 * @return the overridden subclass, or `Nil` if one has not been registered
 */
+ (nullable Class)overriddenClassForClass:(Class)cls;

@end

NS_ASSUME_NONNULL_END

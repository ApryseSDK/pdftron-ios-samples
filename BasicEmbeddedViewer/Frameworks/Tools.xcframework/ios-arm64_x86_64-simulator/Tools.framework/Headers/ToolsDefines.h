//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsConfig.h>

#import <Foundation/Foundation.h>

#pragma mark - Preprocessor macros

/**
 * PT_STRINGIFY
 *
 * Convert a token to a C-string literal using the '#' preprocessor operator.
 *
 * An extra level of macro-indirection is required to expand any macros or
 * defines in the macro parameter.
 */
#define PT_STRINGIFY__(x) # x
#define PT_STRINGIFY(x) PT_STRINGIFY__(x)

/**
 * PT_PASTE
 *
 * Concatenate two tokens into a single token using the '##' preprocessor operator.
 *
 * An extra level of macro-indirection is required to expand any macros or
 * defines in the macro parameters.
 */
#define PT_PASTE__(x, y) x ## y
#define PT_PASTE(x, y) PT_PASTE__(x, y)

/**
 * Visibility
 */

#ifdef __cplusplus
    #define PT_EXTERN extern "C"
#else
    #define PT_EXTERN extern
#endif

/**
 * @def PT_STATIC_INLINE
 */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define PT_STATIC_INLINE static inline
#elif defined(__cplusplus)
    #define PT_STATIC_INLINE static inline
#elif defined(__GNUC__)
    #define PT_STATIC_INLINE static __inline__
#else
    #define PT_STATIC_INLINE static
#endif

#pragma mark - Visibility

#if __has_attribute(visibility)
    #define PT_VISIBILITY_ATTRIBUTE(value) __attribute__((visibility(value)))
#else
    #define PT_VISIBILITY_ATTRIBUTE(value)
#endif

#define PT_VISIBILITY_HIDDEN PT_VISIBILITY_ATTRIBUTE("hidden")

/**
 * Set the visibility for multiple declarations.
 *
 * @see https://gcc.gnu.org/onlinedocs/gcc/Visibility-Pragmas.html#Visibility-Pragmas
 */

#define PT_VISIBILITY_BEGIN(value) _Pragma(PT_STRINGIFY(GCC visibility push(value)))
#define PT_VISIBILITY_END _Pragma(PT_STRINGIFY(GCC visibility pop))

#define PT_VISIBILITY_HIDDEN_BEGIN PT_VISIBILITY_BEGIN(hidden)

#ifndef TOOLS_STATIC
    #define PT_EXPORT PT_EXTERN PT_VISIBILITY_ATTRIBUTE("default")
#else
    #define PT_EXPORT PT_EXTERN
#endif /* TOOLS_STATIC */

#pragma mark - Unavailability

// PT_UNAVAILABLE_MSG(msg)

#if __has_attribute(unavailable)
    #if __has_extension(attribute_unavailable_with_message)
        #define PT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
    #else
        #define PT_UNAVAILABLE_MSG(msg) __attribute__((unavailable))
    #endif
#else
    #define PT_UNAVAILABLE_MSG(msg)
#endif

// PT_UNAVAILABLE

#define PT_UNAVAILABLE PT_UNAVAILABLE_MSG("")

#define PT_INIT_UNAVAILABLE \
- (instancetype)init PT_UNAVAILABLE; \
+ (instancetype)new PT_UNAVAILABLE;

#define PT_INIT_WITH_FRAME_UNAVAILABLE \
- (instancetype)initWithFrame:(CGRect)frame PT_UNAVAILABLE;

#define PT_INIT_WITH_CODER_UNAVAILABLE \
- (instancetype)initWithCoder:(NSCoder *)coder PT_UNAVAILABLE;

#define PT_INIT_WITH_NIB_NAME_BUNDLE_UNAVAILABLE \
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil PT_UNAVAILABLE;

/**
 * Deprecation
 */

#define PT_DEPRECATED_MSG(version, msg) \
    DEPRECATED_MSG_ATTRIBUTE("Deprecated in PDFTron for iOS " PT_STRINGIFY(version) ". " msg)

#define PT_DEPRECATED(version) \
    DEPRECATED_MSG_ATTRIBUTE("Deprecated in PDFTron for iOS " PT_STRINGIFY(version) ".")

/**
 * Diagnostics
 */

#define PT_CLANG_DIAGNOSTIC_PUSH _Pragma(PT_STRINGIFY(clang diagnostic push))
#define PT_CLANG_DIAGNOSTIC_IGNORE(warning) _Pragma(PT_STRINGIFY(clang diagnostic ignored warning))
#define PT_CLANG_DIAGNOSTIC_POP _Pragma(PT_STRINGIFY(clang diagnostic pop))

/**
 * Warnings
 */

#define PT_WARNING_NAME(warning) "-W" warning

#define PT_IGNORE_WARNINGS_BEGIN(warning) \
PT_CLANG_DIAGNOSTIC_PUSH \
PT_CLANG_DIAGNOSTIC_IGNORE(PT_WARNING_NAME(warning))

#define PT_IGNORE_WARNINGS_END PT_CLANG_DIAGNOSTIC_POP

/**
 * unused and used attributes.
 */

#if __has_attribute(unused)
    #define PT_UNUSED_ATTRIBUTE __attribute__((unused))
#else
    #define PT_UNUSED_ATTRIBUTE
#endif /* __has_attribute(unused) */

#if __has_attribute(used)
    #define PT_USED_ATTRIBUTE __attribute__((used))
#else
    #define PT_USED_ATTRIBUTE
#endif /* __has_attribute(used) */

/**
 * Block escaping attribute(s)
 */

#if __has_attribute(noescape)
    #define PT_NOESCAPE __attribute__((noescape))
#else
    #define PT_NOESCAPE
#endif /* __has_attribute(noescape) */

// Empty define, used for readability
#define PT_ESCAPING

#pragma mark - Miscellaneous Defines

/**
 * @def PT_PURE_FUNC
 *
 * Marks a function as being "pure", ie. it only depends on its arguments.
 */
#if __has_attribute(pure)
    #define PT_PURE_FUNC __attribute__((pure))
#else
    #define PT_PURE_FUNC
#endif /* __has_attribute(pure) */

/**
 * @def PT_OBJC_SUBCLASSING_RESTRICTED
 *
 * The `objc_subclassing_restricted` attribute.
 */
#if __has_attribute(objc_subclassing_restricted)
    #define PT_OBJC_SUBCLASSING_RESTRICTED __attribute__((objc_subclassing_restricted))
#else
    #define PT_OBJC_SUBCLASSING_RESTRICTED
#endif

/**
 * PT_OBJC_RUNTIME_PREFIX
 *
 * Defines the prefix to be added to Objective-C class and protocol names in the runtime.
 */
#ifndef PT_OBJC_RUNTIME_PREFIX
    // The default runtime prefix
    #define PT_OBJC_RUNTIME_PREFIX PT
#endif

/**
 * objc_runtime_name attribute
 *
 * @see https://clang.llvm.org/docs/AttributeReference.html#objc-runtime-name
 */
#if __has_attribute(objc_runtime_name)
    #define PT_OBJC_RUNTIME_NAME(name) \
        __attribute__((objc_runtime_name(PT_STRINGIFY(PT_PASTE(PT_OBJC_RUNTIME_PREFIX, name)))))
#else
    #define PT_OBJC_RUNTIME_NAME(name)
#endif

/**
 * objc_non_runtime_protocol
 *
 * @see https://clang.llvm.org/docs/AttributeReference.html#objc-non-runtime-protocol
 */

#if __has_attribute(objc_non_runtime_protocol)
    #define PT_OBJC_NON_RUNTIME_PROTOCOL __attribute__((objc_non_runtime_protocol))
#else
    #define PT_OBJC_NON_RUNTIME_PROTOCOL
#endif /* __has_attribute(objc_non_runtime_protocol) */

/**
 * objc_runtime_visible
 *
 * This attribute specifies that the Objective-C class to which it applies is visible to the Objective-C
 * runtime but not to the linker. Classes annotated with this attribute cannot be subclassed and
 * cannot have categories defined for them.
 *
 * @see https://clang.llvm.org/docs/AttributeReference.html#objc-runtime-visible
 */

#if __has_attribute(objc_runtime_visible)
    #define PT_OBJC_RUNTIME_VISIBLE __attribute__((objc_runtime_visible))
#else
    #define PT_OBJC_RUNTIME_VISIBLE
#endif /* __has_attribute(objc_runtime_visible) */

#pragma mark - Swift errors

/**
 * `swift_error` attribute macros.
 *
 * The `swift_error` attribute controls whether a particular function (or Objective-C method) is
 * imported into Swift as a throwing function, and if so, which dynamic convention it uses.
 *
 * All of the conventions except `none` require the function to have an `error` parameter.
 * Currently, the `error` parameter is always the last parameter of type `NSError**` or `CFErrorRef*`.
 * Swift will remove the `error` parameter from the imported API. When calling the API, Swift will
 * always pass a valid address initialized to a null pointer.
 */

#if __has_attribute(swift_error)
    #define PT_SWIFT_ERROR_ATTRIBUTE(convention) __attribute__((swift_error(convention)))
#else
    #define PT_SWIFT_ERROR_ATTRIBUTE(convention)
#endif /* __has_attribute(swift_error) */

/**
 * The function should not be imported as throwing. The `error` parameter and result type will be
 * imported normally.
 */
#define PT_SWIFT_ERROR_NONE PT_SWIFT_ERROR_ATTRIBUTE(none)

/**
 * Calls to the function should be considered to have thrown if they return a null value. The return
 * type must be a pointer type, and it will be imported into Swift with a non-optional type. This is
 * the default error convention for Objective-C methods that return pointers.
 */
#define PT_SWIFT_ERROR_NULL_RESULT PT_SWIFT_ERROR_ATTRIBUTE(null_result)

/**
 * Calls to the function should be considered to have thrown if they return a zero result. The return
 * type must be an integral type. If the return type would have been imported as `Bool`, it is instead
 * imported as `Void`. This is the default error convention for Objective-C methods that return a type
 * that would be imported as `Bool`.
 */
#define PT_SWIFT_ERROR_ZERO_RESULT PT_SWIFT_ERROR_ATTRIBUTE(zero_result)

/**
 * Calls to the function should be considered to have thrown if they return a non-zero result. The
 * return type must be an integral type. If the return type would have been imported as `Bool`,
 * it is instead imported as `Void`.
 */
#define PT_SWIFT_ERROR_NONZERO_RESULT PT_SWIFT_ERROR_ATTRIBUTE(nonzero_result)

/**
 * Calls to the function should be considered to have thrown if they leave a non-null error in the
 * `error` parameter. The return type is left unmodified.
 */
#define PT_SWIFT_ERROR_NONNULL_ERROR PT_SWIFT_ERROR_ATTRIBUTE(nonnull_error)

#pragma mark - Objective-C category linking

#define PT_OBJC_CATEGORY_LINKAGE_NAME(className, categoryName) \
    PT_PASTE(PT_OBJC_RUNTIME_PREFIX, PT_PASTE(_, PT_PASTE(className, PT_PASTE(_, PT_PASTE(categoryName, _Linkage)))))

#define PT_OBJC_CATEGORY_LINK_IMPL(linkageName) \
    PT_EXTERN \
    PT_VISIBILITY_HIDDEN \
    void linkageName(void); \
    \
    PT_USED_ATTRIBUTE \
    static void PT_PASTE(linkageName, _Link)(void) \
    { \
        linkageName(); \
    }

#define PT_OBJC_CATEGORY_LINKAGE_IMPL(linkageName) \
    void linkageName(void) \
    { \
        return; \
    } \

#ifdef TOOLS_STATIC
    #define PT_OBJC_CATEGORY_LINK(className, categoryName) \
        PT_OBJC_CATEGORY_LINK_IMPL(PT_OBJC_CATEGORY_LINKAGE_NAME(className, categoryName))
#else
    #define PT_OBJC_CATEGORY_LINK(className, categoryName)
#endif /* TOOLS_STATIC */

#ifdef TOOLS_STATIC
    #define PT_OBJC_CATEGORY_LINKAGE(className, categoryName) \
        PT_OBJC_CATEGORY_LINKAGE_IMPL(PT_OBJC_CATEGORY_LINKAGE_NAME(className, categoryName))
#else
    #define PT_OBJC_CATEGORY_LINKAGE(className, categoryName)
#endif /* TOOLS_STATIC */

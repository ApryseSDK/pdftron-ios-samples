// This file is not intended to be added in another header file.
// This file is also not intended to be distributed for release (The file is named .hpp so that it is excluded from
// packaging).
// This header intends to centralize the API's symbol visibility decorators so we can easily adjust and fix them here as
// necessary.

// Having said that, all compiled .cpp files which are intended to be the API definitions must include this file.

#if !defined(TRN_API_CONFIG_HPP)
#define TRN_API_CONFIG_HPP

#if defined(__GNUC__) && defined(NDEBUG) && !defined(TRN_HAS_GCC_DYNAMIC_LINKING)
    #define TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES 1
#endif // defined(__GNUC__) && defined(NDEBUG)

// Some systems do not need the symbol visibility decorators.
#if defined(__APPLE__) || defined(__clang__)
    #undef TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES
    #define TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES 0
#endif // defined(__APPLE__) ||  defined(__clang__)

#if defined(__ANDROID__)
    #undef TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES
    #define TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES 0
#endif // defined(__ANDROID__)

// Ensure the macros are defined
#if !defined(TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES)
    #define TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES 0
#endif // !defined(TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES)

#endif // !defined(TRN_API_CONFIG_HPP)

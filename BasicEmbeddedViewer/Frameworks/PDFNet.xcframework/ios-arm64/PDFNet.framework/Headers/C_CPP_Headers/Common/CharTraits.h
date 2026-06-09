//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPCommonCharTraits
#define PDFTRON_H_CPPCommonCharTraits

#if defined(__apple_build_version__) && __apple_build_version__ >= 17000013

#include <Common/BasicTypes.h>

#include <string>
#include <cwchar>
#include <ios>

namespace std
{

template<>
struct char_traits<pdftron::UInt32>
{
#if __cplusplus >= 201103L
	using char_type = pdftron::UInt32;
	using int_type = unsigned int;
	using off_type = std::streamoff;
	using pos_type = std::fpos<std::mbstate_t>;
	using state_type = std::mbstate_t;
#else
	typedef pdftron::UInt32 char_type;
	typedef unsigned int int_type;
	typedef std::streamoff off_type;
	typedef std::fpos<std::mbstate_t> pos_type;
	typedef std::mbstate_t state_type;
#endif

#if __cplusplus >= 201703L
	static constexpr void assign(char_type& left, const char_type& right) noexcept
#elif __cplusplus >= 201103L
	static void assign(char_type& left, const char_type& right) noexcept
#else
	static void assign(char_type& left, const char_type& right)
#endif
	{
		left = right;
	}

#if __cplusplus >= 202002L
	static constexpr char_type* assign(char_type* const first, std::size_t count, const char_type c)
#else
	static char_type* assign(char_type* const first, std::size_t count, const char_type c)
#endif
	{
		for (char_type* next = first; count > 0; --count, ++next)
		{
			*next = c;
		}

		return first;
	}

#if __cplusplus >= 201103L
	static constexpr bool eq(const char_type left, const char_type right) noexcept
#else
	static bool eq(const char_type left, const char_type right)
#endif
	{
		return left == right;
	}

#if __cplusplus >= 201103L
	static constexpr bool lt(const char_type left, const char_type right) noexcept
#else
	static bool lt(const char_type left, const char_type right)
#endif
	{
		return left < right;
	}

#if __cplusplus >= 202002L
	static constexpr char_type* move(char_type* const dst, const char_type* const src, const std::size_t count)
#else
	static char_type* move(char_type* const dst, const char_type* const src, const std::size_t count)
#endif
	{
		if(dst < src)
		{
			for(std::size_t i = 0; i < count; ++i)
			{
				dst[i] = src[i];
			}
		}
		else if(dst > src)
		{
			for(std::size_t i = count; i-- > 0;)
			{
				dst[i] = src[i];
			}
		}

		return dst;
	}

#if __cplusplus >= 202002L
	static constexpr char_type* copy(char_type* const dst, const char_type* const src, const std::size_t count)
#else
	static char_type* copy(char_type* const dst, const char_type* const src, const std::size_t count)
#endif
	{
		for(std::size_t i = 0; i < count; ++i)
		{
			dst[i] = src[i];
		}

		return dst;
	}

#if __cplusplus >= 201703L
	static constexpr int compare(const char_type* left, const char_type* right, std::size_t count)
#else
	static int compare(const char_type* left, const char_type* right, std::size_t count)
#endif
	{
		for (; count > 0; --count, ++left, ++right)
		{
			if (!eq(*left, *right))
			{
				return lt(*left, *right) ? -1 : 1;
			}
		}

		return 0;
	}

#if __cplusplus >= 201703L
	static constexpr std::size_t length(const char_type* str)
#else
	static std::size_t length(const char_type* str)
#endif
	{
		std::size_t count = 0;

		while (*str != 0)
		{
			++count;
			++str;
		}

		return count;
	}

#if __cplusplus >= 201703L
	static constexpr const char_type* find(const char_type* str, std::size_t count, const char_type& c)
#else
	static const char_type* find(const char_type* str, std::size_t count, const char_type& c)
#endif
	{
		for (; count > 0; --count, ++str)
		{
			if (*str == c)
			{
				return str;
			}
		}

		return nullptr;
	}

#if __cplusplus >= 201103L
	static constexpr char_type to_char_type(const int_type i) noexcept
#else
	static char_type to_char_type(const int_type i)
#endif
	{
		return static_cast<char_type>(i);
	}

#if __cplusplus >= 201103L
	static constexpr int_type to_int_type(const char_type c) noexcept
#else
	static int_type to_int_type(const char_type c)
#endif
	{
		return static_cast<int_type>(c);
	}

#if __cplusplus >= 201103L
	static constexpr bool eq_int_type(const int_type left, const int_type right) noexcept
#else
	static bool eq_int_type(const int_type left, const int_type right)
#endif
	{
		return left == right;
	}

#if __cplusplus >= 201103L
	static constexpr int_type eof() noexcept
#else
	static int_type eof()
#endif
	{
		return static_cast<int_type>(EOF);
	}

#if __cplusplus >= 201103L
	static constexpr int_type not_eof(const int_type i) noexcept
#else
	static int_type not_eof(const int_type i)
#endif
	{
		return i != eof() ? i : !eof();
	}
};

} // namespace std

#endif

#endif // PDFTRON_H_CPPCommonCharTraits

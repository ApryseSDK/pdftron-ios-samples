//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPTextRange
#define PDFTRON_H_CPPTextRange

#include <Common/UString.h>
#include <C/PDF/TRN_TextRange.h>

namespace pdftron { 
	namespace PDF {

/**
 * The TextRange class represents a contiguous range of text on a PDF page.
 * It may be the result of a text search, or simply a couple of highlighted or
 * underlined words.

 * Each text range contains a few pieces of information: 

 * page: the number of the page this piece of text is on;
 * position: the start position (text offset);
 * length: the length.

 * You are able to retrieve further information about the text range, such as its
 * coordinates, the text itself, as well as characters before and after.
 */
class TextRange
{
public:

	/**
	 * Constructor and destructor.
	 */
	TextRange();
	~TextRange();
	/**
	 * Copy constructor.
	 */
	TextRange(const TextRange& tr);

	/**
	 * Assignment operator.
	 */
	TextRange& operator = (const TextRange& tr);

	/**
	 * Get the page number of the text range.
	 */
	int GetPageNumber() const;

	/**
	 * Get the corresponding quadrangles of the text range.
	 * 
	 * @return the number of the resulting quadrangles. Each quadrangle has
	 * eight doubles (x1, y1), (x2, y2), (x3, y3), (x4, y4) denoting the four 
	 * vertices in counter-clockwise order.
	 *
	 * @note the 'quads' array is owned by the current TextRange and does not need to be 
	 * explicitly released. Since a highlight may correspond to multiple quadrangles, e.g., 
	 * when it crosses a line, the number of resulting quadrangles may be larger than 1.
	 */
	std::vector<QuadPoint> GetQuads() const;

#ifndef SWIG
	int GetQuads(const double* &quads) const;
#endif

	/**
	 * Get the Unicode string content of the text range.
	 * @return the text within the range
	 */
	UString GetText() const;

	/**
	 * Get the Unicode string content immediately before the text range.
	 * @param count the number of characters to retrieve before the text range
	 * @return the text before the range
	 */
	UString GetTextBefore(int count) const;

	/**
	 * Get the Unicode string content immediately after the text range.
	 * @param count the number of characters to retrieve before the text range
	 * @return the text after the range
	 */
	UString GetTextAfter(int count) const;

	/**
	 * Frees the native memory of the object.
	 */
	void Destroy();

	 
	//for xamarin use only
	static TextRange* CreateInternal(ptrdiff_t impl);
	ptrdiff_t GetHandleInternal();

#ifndef SWIGHIDDEN
    
//private:
	TRN_TextRange mp_textrange;
	//for xamarin use only
	TextRange(TRN_TextRange impl) : mp_textrange(impl) {}
#endif
};


#include <Impl/TextRange.inl>

	}	// namespace PDF
}	// namespace pdftron

#endif // PDFTRON_H_CPPTextRange

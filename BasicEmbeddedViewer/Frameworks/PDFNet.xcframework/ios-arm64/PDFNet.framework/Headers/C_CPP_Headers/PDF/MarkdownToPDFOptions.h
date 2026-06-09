#pragma once
#include <PDF/ConversionOptions.h>

namespace pdftron{ namespace PDF{ 

class MarkdownToPDFOptions : public ConversionOptions
{
public:
	MarkdownToPDFOptions();
	~MarkdownToPDFOptions();
	
	/**
	* Gets the value of FontFace from the options object
	* Override font face used in converted output.
	* @return a UString, the current value for FontFace.
	*/
	UString GetFontFace();

	/**
	* Sets the value for FontFace in the options object
	* Override font face used in converted output.
	* @param value: the new value for FontFace
	* @return this object, for call chaining
	*/
	MarkdownToPDFOptions& SetFontFace(const UString& value);

};

}
}

#include "../Impl/MarkdownToPDFOptions.inl"

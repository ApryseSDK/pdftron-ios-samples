inline TextStyledElement::TextStyledElement(TRN_TextStyledElement impl)
	: m_impl(impl)
{
}

inline void TextStyledElement::SetFontFace(const UString& font_name)
{

	REX(TRN_TextStyledElementSetFontFace(m_impl, font_name.mp_impl));
}

inline UString TextStyledElement::GetFontFace()
{
	RetStr(TRN_TextStyledElementGetFontFace(m_impl, &result));	
}

inline void TextStyledElement::SetFontSize(double font_size)
{
	REX(TRN_TextStyledElementSetFontSize(m_impl, font_size));
}

inline double TextStyledElement::GetFontSize()
{
	RetDbl(TRN_TextStyledElementGetFontSize(m_impl, &result));
}

inline void TextStyledElement::SetItalic(bool val)
{
	REX(TRN_TextStyledElementSetItalic(m_impl, BToTB(val)));
}

inline bool TextStyledElement::IsItalic()
{
	RetBool(TRN_TextStyledElementIsItalic(m_impl, &result));
}

inline void TextStyledElement::SetBold(bool val)
{
	REX(TRN_TextStyledElementSetBold(m_impl, BToTB(val)));
}

inline bool TextStyledElement::IsBold()
{
	RetBool(TRN_TextStyledElementIsBold(m_impl, &result));
}

inline void TextStyledElement::SetTextColor(UInt8 red, UInt8 green, UInt8 blue)
{
	REX(TRN_TextStyledElementSetTextColor(m_impl, red, green, blue));
}

inline void TextStyledElement::SetBackgroundColor(UInt8 red, UInt8 green, UInt8 blue)
{
	REX(TRN_TextStyledElementSetBackgroundColor(m_impl, red, green, blue));
}

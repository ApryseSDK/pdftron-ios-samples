inline TextRun::TextRun(TRN_TextRun impl)
	: ContentElement(impl)  
{
}

inline TextRun::~TextRun()
{
	Destroy();
}

inline void TextRun::Destroy() {}

inline void TextRun::SetText(const UString& text)
{
	REX(TRN_TextRunSetText(m_impl, text.mp_impl));
}

inline UString TextRun::GetText()
{
	RetStr(TRN_TextRunGetText(m_impl, &result));	
}

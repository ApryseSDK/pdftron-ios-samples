inline Paragraph::Paragraph(TRN_Paragraph impl)
	: ContentNode(impl)
{
}

inline Paragraph::~Paragraph()
{
	Destroy();
}

inline void Paragraph::Destroy() {}

inline TextRun Paragraph::AddText(const UString& text)
{
	TRN_TextRun impl;
	REX(TRN_ParagraphAddText(m_impl, text.mp_impl, &impl));
	return TextRun(impl);
}

inline void Paragraph::SetSpaceBefore(double val)
{
	REX(TRN_ParagraphSetSpaceBefore(m_impl, val));
}

inline double Paragraph::GetSpaceBefore()
{
	RetDbl(TRN_ParagraphGetSpaceBefore(m_impl, &result));
}

inline void Paragraph::SetSpaceAfter(double val)
{
	REX(TRN_ParagraphSetSpaceAfter(m_impl, val));
}

inline double Paragraph::GetSpaceAfter()
{
	RetDbl(TRN_ParagraphGetSpaceAfter(m_impl, &result));
}

inline void Paragraph::SetJustificationMode(TextJustification val)
{
	REX(TRN_ParagraphSetJustificationMode(m_impl, static_cast<TRN_ParagraphTextJustification>(val)));
}

inline Paragraph::TextJustification Paragraph::GetJustificationMode()
{
	TRN_ParagraphTextJustification result;
	REX(TRN_ParagraphGetJustificationMode(m_impl, &result));
	return (Paragraph::TextJustification) result;
}

inline void Paragraph::SetStartIndent(double val)
{
	REX(TRN_ParagraphSetStartIndent(m_impl, val));
}

inline double Paragraph::GetStartIndent()
{
	RetDbl(TRN_ParagraphGetStartIndent(m_impl, &result));
}

inline void Paragraph::SetEndIndent(double val)
{
	REX(TRN_ParagraphSetEndIndent(m_impl, val));
}

inline double Paragraph::GetEndIndent()
{
	RetDbl(TRN_ParagraphGetEndIndent(m_impl, &result));
}

inline void Paragraph::SetTextIndent(double val)
{
	REX(TRN_ParagraphSetTextIndent(m_impl, val));
}

inline double Paragraph::GetTextIndent()
{
	RetDbl(TRN_ParagraphGetTextIndent(m_impl, &result));
}

inline void Paragraph::SetBorder(double thickness, UInt8 red, UInt8 green, UInt8 blue)
{
	REX(TRN_ParagraphSetBorder(m_impl, thickness, red, green, blue));
}


inline double Paragraph::GetBorderThickness()
{
	RetDbl(TRN_ParagraphGetBorderThickness(m_impl, &result));
}

inline void Paragraph::AddTabStop(double val)
{
	REX(TRN_ParagraphAddTabStop(m_impl, val));
}

inline double Paragraph::GetNextTabStop(double val)
{
	RetDbl(TRN_ParagraphGetNextTabStop(m_impl, val, &result));
}

inline void Paragraph::SetDefaultTabStop(double val)
{
	REX(TRN_ParagraphSetDefaultTabStop(m_impl, val));
}

inline double Paragraph::GetDefaultTabStop()
{
	RetDbl(TRN_ParagraphGetDefaultTabStop(m_impl, &result));
}

inline void Paragraph::SetSpacesPerTab(UInt32 val)
{
	REX(TRN_ParagraphSetSpacesPerTab(m_impl, val));
}

inline UInt32 Paragraph::GetSpacesPerTab()
{
	TRN_UInt32 result;
	REX(TRN_ParagraphGetSpacesPerTab(m_impl, &result));
	return (UInt32)result;
}


inline void Paragraph::SetDisplayRtl(bool val)
{
	REX(TRN_ParagraphSetDisplayRtl(m_impl, BToTB(val)));
}

inline bool Paragraph::IsDisplayRtl()
{
	RetBool(TRN_ParagraphIsDisplayRtl(m_impl, &result));
}
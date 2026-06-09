namespace pdftron{ namespace PDF{ 

inline MarkdownToPDFOptions::MarkdownToPDFOptions()
	: ConversionOptions()
{
}

inline MarkdownToPDFOptions::~MarkdownToPDFOptions()
{
}

inline UString MarkdownToPDFOptions::GetFontFace()
{
	SDF::Obj found = m_dict.FindObj("FontFace");
	if (found.IsValid())
	{
		return (found.GetAsPDFText());
	}
	return ("");
}

inline MarkdownToPDFOptions& MarkdownToPDFOptions::SetFontFace(const UString& value)
{
	OptionsBase::PutText(m_dict, "FontFace", (value));
	return *this;
}

}
}

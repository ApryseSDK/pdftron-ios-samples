inline void ContentEdit::Begin(PDFDoc& input_pdf)
{
	REX(TRN_ContentEditBegin(input_pdf.mp_doc));
}

inline UString ContentEdit::RunXML(const UString& commands_xml)
{
	UString result;
	REX(TRN_ContentEditRunXML((const TRN_UString)commands_xml.mp_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline void ContentEdit::End()
{
	REX(TRN_ContentEditEnd());
}

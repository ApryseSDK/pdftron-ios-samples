inline SanitizeOptions Sanitizer::GetSanitizableContent(PDFDoc& doc)
{
	UString result;
	REX(TRN_SanitizerGetSanitizableContent(doc.mp_doc, (TRN_UString*)&result.mp_impl));
	return SanitizeOptions(result);
}

inline void Sanitizer::SanitizeDocument(PDFDoc& doc, const SanitizeOptions* options)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_SanitizerSanitizeDocument(doc.mp_doc, options ? &opt_in : 0));
}

inline void FindReplace::FindReplaceText(PDFDoc& input_output_pdf, const UString& from, const UString& to, const FindReplaceOptions& options)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options.GetInternalObj().mp_obj;
	REX(TRN_FindReplaceFindReplaceText(input_output_pdf.mp_doc, (const TRN_UString)from.mp_impl, (const TRN_UString)to.mp_impl, &opt_in));
}


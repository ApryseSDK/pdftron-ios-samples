inline void TransPDF::ExtractXLIFFWithFilter(PDFDoc& input_output_pdf, Filters::Filter& output_stream_for_xliff, const TransPDFOptions& options)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options.GetInternalObj().mp_obj;
	REX(TRN_TransPDFExtractXLIFFWithFilter(input_output_pdf.mp_doc, output_stream_for_xliff.m_impl, &opt_in));
}

inline void TransPDF::ApplyXLIFFWithFilter(PDFDoc& input, Filters::Filter& incoming_xliff, const TransPDFOptions& options)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options.GetInternalObj().mp_obj;
	REX(TRN_TransPDFApplyXLIFFWithFilter(input.mp_doc, incoming_xliff.m_impl, &opt_in));
}


inline void TransPDF::ExtractXLIFF(PDFDoc& input_output_pdf, const UString& output_xliff, const TransPDFOptions& options)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options.GetInternalObj().mp_obj;
	REX(TRN_TransPDFExtractXLIFF(input_output_pdf.mp_doc, (const TRN_UString)output_xliff.mp_impl, &opt_in));
}


inline void TransPDF::ApplyXLIFF(PDFDoc& input, const UString& incoming_xliff, const TransPDFOptions& options)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options.GetInternalObj().mp_obj;
	REX(TRN_TransPDFApplyXLIFF(input.mp_doc, (const TRN_UString)incoming_xliff.mp_impl, &opt_in));
}

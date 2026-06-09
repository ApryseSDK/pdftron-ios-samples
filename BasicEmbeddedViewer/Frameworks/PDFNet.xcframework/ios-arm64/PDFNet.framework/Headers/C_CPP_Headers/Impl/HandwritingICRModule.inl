inline bool HandwritingICRModule::IsModuleAvailable()
{
	TRN_Bool result = 0;
	REX(TRN_HandwritingICRModuleIsModuleAvailable(&result));
	return result != 0;
}

inline UString HandwritingICRModule::GetICRJsonFromPDF(PDFDoc& src, const HandwritingICROptions* options)
{
	UString result;
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_HandwritingICRModuleGetICRJsonFromPDF(src.mp_doc, &opt_in, (TRN_UString*)&result.mp_impl));
	return result;
}

void HandwritingICRModule::ApplyICRJsonToPDF(PDFDoc& dst, const UString& json)
{
	REX(TRN_HandwritingICRModuleApplyICRJsonToPDF(dst.mp_doc, (TRN_UString)json.mp_impl));
}

void HandwritingICRModule::ProcessPDF(PDFDoc& dst, const HandwritingICROptions* options)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_HandwritingICRModuleProcessPDF(dst.mp_doc, &opt_in));
}

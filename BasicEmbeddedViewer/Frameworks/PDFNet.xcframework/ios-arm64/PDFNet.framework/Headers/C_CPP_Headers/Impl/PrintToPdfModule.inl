inline bool PrintToPdfModule::IsModuleAvailable()
{
	TRN_Bool result = 0;
	REX(TRN_PrintToPdfModuleIsModuleAvailable(&result));
	return result != 0;
}

inline void PrintToPdfModule::PrintToPdf(PDFDoc& pdf_doc, const UString& file_to_print, PrintToPdfOptions* options)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_PrintToPdfModulePrintToPdf((TRN_PDFDoc)pdf_doc.mp_doc, (TRN_UString)file_to_print.mp_impl, &opt_in));
}


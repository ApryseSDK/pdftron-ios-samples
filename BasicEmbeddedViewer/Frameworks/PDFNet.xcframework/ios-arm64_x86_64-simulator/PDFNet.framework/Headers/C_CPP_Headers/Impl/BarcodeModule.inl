inline bool BarcodeModule::IsModuleAvailable()
{
	TRN_Bool result = 0;
	REX(TRN_BarcodeModuleIsModuleAvailable(&result));
	return result != 0;
}

inline void BarcodeModule::ExtractBarcodes(PDFDoc& src, const UString& output_file_path, const BarcodeOptions& options)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options.GetInternalObj().mp_obj;
	REX(TRN_BarcodeModuleExtractBarcodes(src.mp_doc, (TRN_UString)output_file_path.mp_impl, &opt_in));
}

inline UString BarcodeModule::ExtractBarcodesAsString(PDFDoc& src, const BarcodeOptions& options)
{
	UString result;
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options.GetInternalObj().mp_obj;
	REX(TRN_BarcodeModuleExtractBarcodesAsString(src.mp_doc, &opt_in, (TRN_UString*)&result.mp_impl));
	return result;
}


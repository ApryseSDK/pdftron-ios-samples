inline bool DataExtractionModule::IsModuleAvailable(DataExtractionEngine engine)
{
	TRN_Bool result = 0;
	REX(TRN_DataExtractionModuleIsModuleAvailable((enum TRN_DataExtractionModule_DataExtractionEngine) engine, &result));
	return result != 0;
}

inline UString DataExtractionModule::ExtractData(const UString& input_pdf_file, DataExtractionEngine engine, DataExtractionOptions* options)
{
	UString result;
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_DataExtractionModuleExtractDataAsString((TRN_UString)input_pdf_file.mp_impl, (enum TRN_DataExtractionModule_DataExtractionEngine) engine, &opt_in, (TRN_UString*)&result.mp_impl));
	return result;
}

inline void DataExtractionModule::ExtractData(const UString& input_pdf_file, const UString& output_json_file, DataExtractionEngine engine, DataExtractionOptions* options)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_DataExtractionModuleExtractData((TRN_UString)input_pdf_file.mp_impl, (TRN_UString)output_json_file.mp_impl, (enum TRN_DataExtractionModule_DataExtractionEngine) engine, &opt_in));
}

inline void DataExtractionModule::DetectAndAddFormFieldsToPDF(PDFDoc& doc, DataExtractionOptions* options)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_DataExtractionModuleDetectAndAddFormFieldsToPDF(doc.mp_doc, &opt_in));
}

inline void DataExtractionModule::ExtractToXLSX(const UString& input_pdf_file, const UString& output_xlsx_file, DataExtractionOptions* options)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_DataExtractionModuleExtractToXLSX((TRN_UString)input_pdf_file.mp_impl, (TRN_UString)output_xlsx_file.mp_impl, &opt_in));
}

inline void DataExtractionModule::ExtractToXLSX(const UString& input_pdf_file, Filters::Filter& output_xlsx_stream, DataExtractionOptions* options)
{
	TRN_optionbase opt_in;
	opt_in.type = e_option_type_sdf;
	opt_in.impl = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_DataExtractionModuleExtractToXLSXWithFilter((TRN_UString)input_pdf_file.mp_impl, output_xlsx_stream.m_impl, &opt_in));
}


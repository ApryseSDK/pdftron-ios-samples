
#ifdef SWIG
inline void PDFNet::Initialize(const char* license_key, const char* json_string)
{
	REX(TRN_PDFNetInitializeEx(license_key, json_string));
}
#endif

inline void PDFNet::Terminate(const int termination_level)
{
	REX(TRN_PDFNetTerminateEx(termination_level));
}

inline void PDFNet::Initialize(const char* license_key)
{
	std::string json_string = "{\"language\":\"C++\"}";//json format for more info
	REX(TRN_PDFNetInitializeEx(license_key, json_string.c_str()));
}

inline void PDFNet::EnableJavaScript(bool enable)
{
	REX(TRN_PDFNetEnableJavaScript(BToTB(enable)));
}

inline bool PDFNet::IsJavaScriptEnabled()
{
	TRN_Bool result;
	REX(TRN_PDFNetIsJavaScriptEnabled(&result));
	return TBToB(result);
}


#ifndef SWIG
inline void PDFNet::Terminate()
{
	REX(TRN_PDFNetTerminate());
}
#endif

inline bool PDFNet::SetResourcesPath(const UString& path)
{
	TRN_Bool result;
	REX(TRN_PDFNetSetResourcesPath(path.mp_impl,&result));
	return TBToB(result);
}

inline UString PDFNet::GetResourcesPath()
{
	RetStr(TRN_PDFNetGetResourcesPath(&result));
}

inline void PDFNet::AddResourceSearchPath(const UString& path)
{
	REX(TRN_PDFNetAddResourceSearchPath(path.mp_impl));
}

inline void PDFNet::SetColorManagement(CMSType t)
{
	REX(TRN_PDFNetSetColorManagement((enum TRN_PDFNetCMSType)t));
}

inline void PDFNet::SetDefaultDeviceCMYKProfile(const UString& icc_filename)
{
	REX(TRN_PDFNetSetDefaultDeviceCMYKProfile(icc_filename.mp_impl));
}

inline void PDFNet::SetDefaultDeviceRGBProfile(const UString& icc_filename)
{
	REX(TRN_PDFNetSetDefaultDeviceRGBProfile(icc_filename.mp_impl));
}

inline void PDFNet::SetDefaultDeviceCMYKProfile(Filters::Filter stream)
{
	stream.m_owner = false;
	REX(TRN_PDFNetSetDefaultDeviceCMYKProfileFromFilter(stream.m_impl));
	stream.m_impl = 0; 
}

inline void PDFNet::SetDefaultDeviceRGBProfile(Filters::Filter stream)
{
	stream.m_owner = false;
	REX(TRN_PDFNetSetDefaultDeviceRGBProfileFromFilter(stream.m_impl));
	stream.m_impl = 0; 
}

inline void PDFNet::SetDefaultDiskCachingEnabled( bool use_disk )
{
	REX(TRN_PDFNetSetDefaultDiskCachingEnabled(use_disk));
}

inline void PDFNet::SetDefaultFlateCompressionLevel(int level)
{
	REX(TRN_PDFNetSetDefaultFlateCompressionLevel(level));
}

inline void PDFNet::SetViewerCache(size_t max_cache_size, bool on_disk)
{
	REX(TRN_PDFNetSetViewerCache(max_cache_size, on_disk));
}

inline bool PDFNet::AddFontSubst(const char* fontname, const UString& fontpath)
{
	RetBool(TRN_PDFNetAddFontSubstFromName(fontname,fontpath.mp_impl,&result));
}

inline bool PDFNet::AddFontSubst(CharacterOrdering ordering, const UString& fontpath)
{
	RetBool(TRN_PDFNetAddFontSubst((enum TRN_PDFNetCharacterOrdering)ordering, fontpath.mp_impl,&result));
}

inline void PDFNet::SetTempPath(const UString& temp_path)
{
	TRN_PDFNetSetTempPath(temp_path.mp_impl);
}

inline void PDFNet::SetPersistentCachePath(const UString& persistent_path)
{
	TRN_PDFNetSetPersistentCachePath(persistent_path.mp_impl);
}

inline double PDFNet::GetVersion()
{
	RetDbl(TRN_PDFNetGetVersion(&result));
}

#ifndef SWIG
inline void PDFNet::RegisterSecurityHandler(const char* handler_name, const char* gui_name, CreateSecurityHandler factory_method)
{
	REX(TRN_PDFNetRegisterSecurityHandler(handler_name, gui_name, factory_method));
}

inline PDFNet::SecurityDescriptorIterator PDFNet::GetSecHdlrInfoIterator()
{
	TRN_Iterator result;
	REX(TRN_PDFNetGetSecHdlrInfoIterator(&result));
	return PDFNet::SecurityDescriptorIterator(result);
}

inline void PDFNet::SetNumberWriteProc(char* (*write_proc) (double num, char *in_buf, int in_buf_size)) {
	TRN_PDFNetSetNumberWriteProc(write_proc);
}

inline void PDFNet::SetNumberReadProc(TRN_Bool (*read_proc) (const TRN_UChar *buf, double *output)) {
	TRN_PDFNetSetNumberReadProc(read_proc);
}
#endif

inline void PDFNet::SetLogLevel(LogLevel level)
{
	TRN_PDFNetSetLogLevel(static_cast<TRN_PDFNetLogLevel>(level));
}

inline UString PDFNet::GetSystemFontList()
{
	RetStr(TRN_PDFNetGetSystemFontList(&result));
}

inline void PDFNet::AddPDFTronCustomHandler(UInt32 custom_id)
{
	TRN_PDFNetAddPDFTronCustomHandler((TRN_UInt32)custom_id);
}

inline void PDFNet::SetWriteAPIUsageLocally(bool write_usage)
{
	REX(TRN_PDFNetSetWriteAPIUsageLocally(BToTB(write_usage)));
}

inline const char* PDFNet::GetVersionString(){
	const char* result;
	REX(TRN_PDFNetGetVersionString(&result));
	return result;
}

inline void PDFNet::SetConnectionErrorHandlingMode(ConnectionErrorHandlingMode mode)
{
	TRN_PDFNetSetConnectionErrorHandlingMode(static_cast<TRN_PDFNetConnectionErrorHandlingMode>(mode));
}

#ifdef SWIG
inline void PDFNet::SetConnectionErrorProc(PDF::Callback* instance)
{
	REX(TRN_PDFNetSetConnectionErrorProc((TRN_PDFNetConnectionErrorProc)&(PDF::Callback::StaticConnectionErrorProc), instance));
}
#else
inline void PDFNet::SetConnectionErrorProc(PDFNet::ConnectionErrorProc error_proc, void* data)
{
	REX(TRN_PDFNetSetConnectionErrorProc((TRN_PDFNetConnectionErrorProc)error_proc, data));
}
#endif

#ifdef SWIG
inline void PDFNet::SetAPIDataOfflineProc(PDF::Callback* instance)
{
	REX(TRN_PDFNetSetAPIDataOfflineProc((TRN_PDFNetAPIDataOfflineProc) & (PDF::Callback::StaticAPIDataOfflineProc), instance));
}
#else
inline void PDFNet::SetAPIDataOfflineProc(PDFNet::APIDataOfflineProc api_data_proc, void* user_data)
{
	REX(TRN_PDFNetSetAPIDataOfflineProc((TRN_PDFNetAPIDataOfflineProc)api_data_proc, user_data));
}
#endif

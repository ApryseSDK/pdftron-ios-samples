//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFPDFNet
#define PDFTRON_H_CPDFPDFNet

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
TRN_API TRN_PDFNetInitializeEx(const char* license_key, const char* json_string);
TRN_API TRN_PDFNetInitialize(const char* license_key);
TRN_API TRN_PDFNetEnableJavaScript(TRN_Bool enable);
TRN_API TRN_PDFNetIsJavaScriptEnabled(TRN_Bool* result);
TRN_API TRN_Collect23();
TRN_API TRN_RequestAsyncCallback(void* net_callback, const int http_error_code, const char* xhr_response_buffer,
	const int buffer_size, const char* status_text, void* user_data_0, void* user_data_1, void* user_data_2);
TRN_API TRN_PDFNetTerminateEx(const int termination_level);
TRN_API TRN_PDFNetTerminate();
TRN_API TRN_PDFNetSetResourcesPath(TRN_UString path, TRN_Bool* result);
TRN_API TRN_PDFNetGetResourcesPath(TRN_UString* result);
TRN_API TRN_PDFNetSetResourceData(TRN_UChar* buf, size_t buf_size);
TRN_API TRN_PDFNetAddResourceSearchPath(TRN_UString path);


enum TRN_PDFNetCMSType
{
	e_PDFNet_lcms   = 0,
	e_PDFNet_icm    = 1,
	e_PDFNet_no_cms = 2
};

TRN_API TRN_PDFNetSetColorManagement(enum TRN_PDFNetCMSType t);
TRN_API TRN_PDFNetSetDefaultDeviceCMYKProfile(const TRN_UString icc_filename);
TRN_API TRN_PDFNetSetDefaultDeviceRGBProfile(const TRN_UString icc_filename);
TRN_API TRN_PDFNetSetDefaultDeviceCMYKProfileFromFilter(TRN_Filter stream);
TRN_API TRN_PDFNetSetDefaultDeviceRGBProfileFromFilter(TRN_Filter stream);
TRN_API TRN_PDFNetSetDefaultDiskCachingEnabled( TRN_Bool use_disk );
TRN_API TRN_PDFNetSetDefaultFlateCompressionLevel(int level);
TRN_API TRN_PDFNetSetViewerCache(TRN_Size max_cache_size, TRN_Bool on_disk);

enum TRN_PDFNetCharacterOrdering {
	e_PDFNet_Identity = 0,
	e_PDFNet_Japan1   = 1,
	e_PDFNet_Japan2   = 2,
	e_PDFNet_GB1      = 3,
	e_PDFNet_CNS1     = 4,
	e_PDFNet_Korea1   = 5
};

TRN_API TRN_PDFNetAddFontSubstFromName(const char* fontname, const TRN_UString fontpath, TRN_Bool* result);
TRN_API TRN_PDFNetAddFontSubst(enum TRN_PDFNetCharacterOrdering ordering, const TRN_UString fontpath, TRN_Bool* result);
TRN_API TRN_PDFNetSetTempPath(const TRN_UString temp_path);
TRN_API TRN_PDFNetGetTempPath(TRN_UString* result);
TRN_API TRN_PDFNetSetPersistentCachePath(const TRN_UString persistent_path);
TRN_API TRN_PDFNetGetVersion(double* result);

TRN_API TRN_PDFNetRegisterSecurityHandler(const char* handler_name, const char* gui_name, TRN_PDFNetCreateSecurityHandler factory_method);
TRN_API TRN_PDFNetGetSecHdlrInfoIterator(TRN_Iterator* result);

TRN_API TRN_PDFNetSetNumberWriteProc(char* (*write_proc) (double num, char *in_buf, int in_buf_size));
TRN_API TRN_PDFNetSetNumberReadProc(TRN_Bool (*read_proc) (const TRN_UChar *buf, double *output));

enum TRN_PDFNetLogLevel {
	e_PDFNet_LogLevel_Off		= -1,
	e_PDFNet_LogLevel_Fatal		= 5,
	e_PDFNet_LogLevel_Error		= 4,
	e_PDFNet_LogLevel_Warning	= 3,
	e_PDFNet_LogLevel_Info		= 2,
	e_PDFNet_LogLevel_Trace		= 1,
	e_PDFNet_LogLevel_Debug		= 0
};

TRN_API TRN_PDFNetSetLogLevel(enum TRN_PDFNetLogLevel level);
TRN_API TRN_PDFNetGetSystemFontList(TRN_UString* result);
TRN_API TRN_PDFNetAddPDFTronCustomHandler(TRN_UInt32 custom_id);
TRN_API TRN_PDFNetSetWriteAPIUsageLocally(TRN_Bool write_usage);
TRN_API TRN_PDFNetGetVersionString(const char** result);

enum TRN_PDFNetConnectionErrorHandlingMode
{
	e_PDFNet_continue, // Apryse SDK will continue running and if necessary switch to demo mode when encountering an unresolvable connection error
	e_PDFNet_continue_unless_switching_to_demo, // Apryse SDK will continue as long as it doesn't need to switch to demo mode in response to the connection error
										// If continuing without switching to demo mode is not possible, Apryse SDK functions will throw exceptions.
	e_PDFNet_stop // Apryse SDK will throw exceptions from subsequent usage if a connection error occurs
};
TRN_API TRN_PDFNetSetConnectionErrorHandlingMode(enum TRN_PDFNetConnectionErrorHandlingMode mode);

typedef void(*TRN_PDFNetConnectionErrorProc)(const char* message, const int error_code, TRN_Bool switch_to_demo, void* data);
TRN_API TRN_PDFNetSetConnectionErrorProc(TRN_PDFNetConnectionErrorProc error_proc, void* data);

typedef void(*TRN_PDFNetAPIDataOfflineProc) (const char* api_data_json, void* user_data);
TRN_API TRN_PDFNetSetAPIDataOfflineProc(TRN_PDFNetAPIDataOfflineProc api_data_proc, void* user_data);

#ifdef __cplusplus
} //extern C
#endif

#endif // PDFTRON_H_CPDFPDFNet

inline DocumentConversion::~DocumentConversion()
{
	Destroy();
}

inline DocumentConversion::DocumentConversion(const DocumentConversion& other)
	: m_impl(0)
{
	REX(TRN_DocumentConversionCopyCtor(other.m_impl, &m_impl));
}

inline void DocumentConversion::Destroy()
{
	DREX(m_impl, TRN_DocumentConversionDestroy(m_impl));
}

inline DocumentConversion& pdftron::PDF::DocumentConversion::operator= (const DocumentConversion& other)
{
	REX(TRN_DocumentConversionAssign(other.m_impl, &m_impl));
	return *this;
}

inline DocumentConversion::DocumentConversion()
	: m_impl(0)
{}

inline DocumentConversion::DocumentConversion(TRN_DocumentConversion impl)
	: m_impl(impl)
{}
inline DocumentConversion::Result DocumentConversion::TryConvert()
{
	Result result;
	REX(TRN_DocumentConversionTryConvert((TRN_DocumentConversion)m_impl, (enum TRN_DocumentConversion_Result*) &result));
	return result;
}

inline void DocumentConversion::Convert()
{
	REX(TRN_DocumentConversionConvert((TRN_DocumentConversion)m_impl));
}

inline void DocumentConversion::ConvertNextPage()
{
	REX(TRN_DocumentConversionConvertNextPage((TRN_DocumentConversion)m_impl));
}

inline PDFDoc DocumentConversion::GetDoc()
{
	TRN_PDFDoc doc;
	REX(TRN_DocumentConversionGetDoc((TRN_DocumentConversion)m_impl, &doc));
	return PDFDoc(doc);
}

inline DocumentConversion::Result DocumentConversion::GetConversionStatus() const
{
	Result result;
	REX(TRN_DocumentConversionGetConversionStatus((TRN_DocumentConversion)m_impl, (enum TRN_DocumentConversion_Result*) &result));
	return result;
}

inline void DocumentConversion::CancelConversion()
{
	REX(TRN_DocumentConversionCancelConversion((TRN_DocumentConversion)m_impl));
}

inline bool DocumentConversion::IsCancelled() const
{
	TRN_Bool result = 0;
	REX(TRN_DocumentConversionIsCancelled((TRN_DocumentConversion)m_impl, &result));
	return result != 0;
}

inline bool DocumentConversion::HasProgressTracking() const
{
	TRN_Bool result = 0;
	REX(TRN_DocumentConversionHasProgressTracking((TRN_DocumentConversion)m_impl, &result));
	return result != 0;
}

inline double DocumentConversion::GetProgress() const
{
	double result = 0;
	REX(TRN_DocumentConversionGetProgress((TRN_DocumentConversion)m_impl, &result));
	return result;
}

inline UString DocumentConversion::GetProgressLabel() const
{
	UString result;
	REX(TRN_DocumentConversionGetProgressLabel((TRN_DocumentConversion)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UInt32 DocumentConversion::GetNumConvertedPages() const
{
	UInt32 result = 0;
	REX(TRN_DocumentConversionGetNumConvertedPages((TRN_DocumentConversion)m_impl, &result));
	return result;
}

inline UString DocumentConversion::GetErrorString() const
{
	UString result;
	REX(TRN_DocumentConversionGetErrorString((TRN_DocumentConversion)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UInt32 DocumentConversion::GetNumWarnings() const
{
	UInt32 result = 0;
	REX(TRN_DocumentConversionGetNumWarnings((TRN_DocumentConversion)m_impl, &result));
	return result;
}

inline UString DocumentConversion::GetWarningString(UInt32 index) const
{
	UString result;
	REX(TRN_DocumentConversionGetWarningString((TRN_DocumentConversion)m_impl, index, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString DocumentConversion::GetCurrentExcelSheetName() const
{
	UString result;
	REX(TRN_DocumentConversionGetCurrentExcelSheetName((TRN_DocumentConversion)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UInt32 DocumentConversion::GetNextExcelSheetCellCount() const
{
	UInt32 result = 0;
	REX(TRN_DocumentConversionGetNextExcelSheetCellCount((TRN_DocumentConversion)m_impl, &result));
	return result;
}

inline void DocumentConversion::SkipNextExcelSheet()
{
	REX(TRN_DocumentConversionSkipNextExcelSheet((TRN_DocumentConversion)m_impl));
}


// ---------------------------------------------------
//for xamarin use only
inline DocumentConversion* DocumentConversion::CreateInternal(ptrdiff_t impl) {
	return new DocumentConversion((TRN_DocumentConversion)impl);
}

inline ptrdiff_t DocumentConversion::GetHandleInternal() {
    return (ptrdiff_t) m_impl;
}


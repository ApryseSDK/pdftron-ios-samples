inline TemplateDocument::~TemplateDocument()
{
	Destroy();
}

inline TemplateDocument::TemplateDocument(const TemplateDocument& other)
	: m_impl(0)
{
	REX(TRN_TemplateDocumentCopyCtor(other.m_impl, &m_impl))
}

inline void TemplateDocument::Destroy()
{
	DREX(m_impl, TRN_TemplateDocumentDestroy(m_impl));
}

inline TemplateDocument& pdftron::PDF::TemplateDocument::operator= (const TemplateDocument& other)
{
	REX(TRN_TemplateDocumentAssign(other.m_impl, &m_impl));
	return *this;
}

inline TemplateDocument::TemplateDocument()
	: m_impl(0)
{}

inline TemplateDocument::TemplateDocument(TRN_TemplateDocument impl)
	: m_impl(impl)
{}
inline PDFDoc TemplateDocument::FillTemplateJson(UString json)
{
	TRN_PDFDoc doc;
	REX(TRN_TemplateDocumentFillTemplateJson((TRN_TemplateDocument)m_impl, (TRN_UString)json.mp_impl, &doc));
	return PDFDoc(doc);
}

inline void TemplateDocument::FillTemplateJsonToOffice(UString json, UString output_path)
{
	REX(TRN_TemplateDocumentFillTemplateJsonToOffice((TRN_TemplateDocument)m_impl, (TRN_UString)json.mp_impl, (TRN_UString)output_path.mp_impl));
}

inline void TemplateDocument::FillTemplateJsonToOfficeWithFilter(UString json, Filters::Filter& output_stream)
{
	REX(TRN_TemplateDocumentFillTemplateJsonToOfficeWithFilter((TRN_TemplateDocument)m_impl, (TRN_UString)json.mp_impl, output_stream.m_impl));
}

inline UString TemplateDocument::GetTemplateKeysJson()
{
	UString result;
	REX(TRN_TemplateDocumentGetTemplateKeysJson((TRN_TemplateDocument)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString TemplateDocument::GetErrorString() const
{
	UString result;
	REX(TRN_TemplateDocumentGetErrorString((TRN_TemplateDocument)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline TemplateDocument::Result TemplateDocument::GetConversionStatus() const
{
	Result result;
	REX(TRN_TemplateDocumentGetConversionStatus((TRN_TemplateDocument)m_impl, (enum TRN_TemplateDocument_Result*) &result));
	return result;
}

inline void TemplateDocument::CancelConversion()
{
	REX(TRN_TemplateDocumentCancelConversion((TRN_TemplateDocument)m_impl));
}

inline bool TemplateDocument::IsCancelled() const
{
	TRN_Bool result = 0;
	REX(TRN_TemplateDocumentIsCancelled((TRN_TemplateDocument)m_impl, &result));
	return result != 0;
}

inline UInt32 TemplateDocument::GetNumWarnings() const
{
	UInt32 result = 0;
	REX(TRN_TemplateDocumentGetNumWarnings((TRN_TemplateDocument)m_impl, &result));
	return result;
}

inline UString TemplateDocument::GetWarningString(UInt32 index) const
{
	UString result;
	REX(TRN_TemplateDocumentGetWarningString((TRN_TemplateDocument)m_impl, index, (TRN_UString*)&result.mp_impl));
	return result;
}


// ---------------------------------------------------
//for xamarin use only
inline TemplateDocument* TemplateDocument::CreateInternal(ptrdiff_t impl) {
	return new TemplateDocument((TRN_TemplateDocument)impl);
}

inline ptrdiff_t TemplateDocument::GetHandleInternal() {
    return (ptrdiff_t) m_impl;
}


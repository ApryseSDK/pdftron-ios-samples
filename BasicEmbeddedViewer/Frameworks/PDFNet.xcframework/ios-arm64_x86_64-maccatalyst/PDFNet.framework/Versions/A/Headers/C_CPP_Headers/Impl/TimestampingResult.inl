#ifdef SWIG
inline TimestampingResult::TimestampingResult()
	: m_impl(0)
{}
#endif


inline TimestampingResult::~TimestampingResult()
{
	DREX(m_impl, TRN_TimestampingResultDestroy(m_impl));
}

inline TimestampingResult::TimestampingResult(const TimestampingResult& other)
{
	REX(TRN_TimestampingResultCopyCtor(other.m_impl, &m_impl));
}

inline void TimestampingResult::Destroy()
{
	REX(TRN_TimestampingResultDestroy(m_impl));
	m_impl = 0;
}

inline TimestampingResult& pdftron::PDF::TimestampingResult::operator= (const TimestampingResult& other)
{
	REX(TRN_TimestampingResultAssign(other.m_impl, &m_impl));
	return *this;
}


inline TimestampingResult::TimestampingResult(TRN_TimestampingResult impl)
	: m_impl(impl)
{}

inline bool TimestampingResult::GetStatus() const
{
	TRN_Bool result = 0;
	REX(TRN_TimestampingResultGetStatus((TRN_TimestampingResult)m_impl, &result));
	return result != 0;
}

inline UString TimestampingResult::GetString() const
{
	UString result;
	REX(TRN_TimestampingResultGetString((TRN_TimestampingResult)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline bool TimestampingResult::HasResponseVerificationResult() const
{
	TRN_Bool result = 0;
	REX(TRN_TimestampingResultHasResponseVerificationResult((TRN_TimestampingResult)m_impl, &result));
	return result != 0;
}

inline EmbeddedTimestampVerificationResult TimestampingResult::GetResponseVerificationResult() const
{
	TRN_EmbeddedTimestampVerificationResult result;
	REX(TRN_TimestampingResultGetResponseVerificationResult((TRN_TimestampingResult)m_impl, (TRN_EmbeddedTimestampVerificationResult*) &result));
	return EmbeddedTimestampVerificationResult(result);
}

inline std::vector<pdftron::UChar> TimestampingResult::GetData() const
{
	TRN_Vector cvector;
	REX(TRN_TimestampingResultGetData((TRN_TimestampingResult) m_impl, &cvector));
	void* arr;
	UInt32 size;
	REX(TRN_VectorGetData(cvector, &arr));
	REX(TRN_VectorGetSize(cvector, &size));
	std::vector<UChar> result(size);
	memcpy(&result[0], arr, size);
	TRN_VectorDestroy(cvector);
	return result;
}

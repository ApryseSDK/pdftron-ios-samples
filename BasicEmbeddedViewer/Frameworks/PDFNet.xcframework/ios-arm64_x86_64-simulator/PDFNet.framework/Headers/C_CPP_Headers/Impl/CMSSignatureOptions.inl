inline CMSSignatureOptions::~CMSSignatureOptions()
{
	Destroy();
}

inline CMSSignatureOptions::CMSSignatureOptions(const CMSSignatureOptions& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if (other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void CMSSignatureOptions::Destroy()
{
	if (m_owner)
	{
		DREX(m_impl, TRN_CMSSignatureOptionsDestroy(m_impl));
		m_owner = false;
	}
}

inline CMSSignatureOptions& CMSSignatureOptions::operator= (const CMSSignatureOptions& other)
{
	Destroy();

	m_impl = other.m_impl;

	if (other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline CMSSignatureOptions::CMSSignatureOptions(TRN_CMSSignatureOptions impl)
	: m_impl(impl)
	, m_owner(true)
{}

inline  CMSSignatureOptions::CMSSignatureOptions()
	: m_owner(true)
{
	REX(TRN_CMSSignatureOptionsCreate((TRN_CMSSignatureOptions*)&m_impl));
}

inline void CMSSignatureOptions::AddTimestampToken(const std::vector<UChar>& token_buf)
{
	REX(TRN_CMSSignatureOptionsAddTimestampToken((TRN_CMSSignatureOptions)m_impl, token_buf.data(), token_buf.size()));
}

#ifndef SWIG
inline void CMSSignatureOptions::AddTimestampToken(const UChar* token_buf, const size_t token_buf_size)
{
	REX(TRN_CMSSignatureOptionsAddTimestampToken((TRN_CMSSignatureOptions)m_impl, token_buf, token_buf_size));
}
#endif

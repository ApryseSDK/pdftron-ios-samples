
inline RSASSAPSSParams::RSASSAPSSParams(const RSASSAPSSParams& other)
	: AlgorithmParams(other)
{
}

inline RSASSAPSSParams& RSASSAPSSParams::operator= (const RSASSAPSSParams& other)
{
	Destroy();

	AlgorithmParams::operator=(other);

	return *this;
}

inline RSASSAPSSParams::RSASSAPSSParams(TRN_RSASSAPSSParams impl)
	: AlgorithmParams((TRN_AlgorithmParams)impl)
{}

inline  RSASSAPSSParams::RSASSAPSSParams()
{
	m_owner = true;
	REX(TRN_RSASSAPSSParamsCreate((TRN_RSASSAPSSParams*)&m_impl));
}

inline  RSASSAPSSParams::RSASSAPSSParams(const AlgorithmIdentifier& digest_algorithm_id, const UInt32 salt_length)
{
	m_owner = true;
	REX(TRN_RSASSAPSSParamsCreateFromAlgoIdAndSaltLen(digest_algorithm_id.m_impl, salt_length, (TRN_RSASSAPSSParams*)&m_impl));
}

inline AlgorithmIdentifier RSASSAPSSParams::GetDigestAlgorithm() const
{
	TRN_AlgorithmIdentifier result;
	REX(TRN_RSASSAPSSParamsGetDigestAlgorithm((TRN_RSASSAPSSParams)m_impl, &result));
	return AlgorithmIdentifier(result);
}

inline AlgorithmIdentifier RSASSAPSSParams::GetMaskGenAlgorithm() const
{
	TRN_AlgorithmIdentifier result;
	REX(TRN_RSASSAPSSParamsGetMaskGenAlgorithm((TRN_RSASSAPSSParams)m_impl, &result));
	return AlgorithmIdentifier(result);
}

inline UInt32 RSASSAPSSParams::GetSaltLength() const
{
	UInt32 result = 0;
	REX(TRN_RSASSAPSSParamsGetSaltLength((TRN_RSASSAPSSParams)m_impl, &result));
	return result;
}

inline UInt32 RSASSAPSSParams::GetTrailerField() const
{
	UInt32 result = 0;
	REX(TRN_RSASSAPSSParamsGetTrailerField((TRN_RSASSAPSSParams)m_impl, &result));
	return result;
}

inline void RSASSAPSSParams::SetDigestAlgorithm(const AlgorithmIdentifier& value)
{
	REX(TRN_RSASSAPSSParamsSetDigestAlgorithm((TRN_RSASSAPSSParams)m_impl, value.m_impl));
}

inline void RSASSAPSSParams::SetMaskGenAlgorithm(const AlgorithmIdentifier& value)
{
	REX(TRN_RSASSAPSSParamsSetMaskGenAlgorithm((TRN_RSASSAPSSParams)m_impl, value.m_impl));
}

inline void RSASSAPSSParams::SetSaltLength(UInt32 value)
{
	REX(TRN_RSASSAPSSParamsSetSaltLength((TRN_RSASSAPSSParams)m_impl, value));
}

inline void RSASSAPSSParams::SetTrailerField(UInt32 value)
{
	REX(TRN_RSASSAPSSParamsSetTrailerField((TRN_RSASSAPSSParams)m_impl, value));
}

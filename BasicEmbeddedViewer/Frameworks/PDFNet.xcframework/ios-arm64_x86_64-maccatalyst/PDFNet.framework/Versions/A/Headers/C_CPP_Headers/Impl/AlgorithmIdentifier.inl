inline AlgorithmIdentifier::~AlgorithmIdentifier()
{
	Destroy();
}

inline AlgorithmIdentifier::AlgorithmIdentifier(const AlgorithmIdentifier& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void AlgorithmIdentifier::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_AlgorithmIdentifierDestroy(m_impl));
		m_owner = false;
	}
}

inline AlgorithmIdentifier& AlgorithmIdentifier::operator= (const AlgorithmIdentifier& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

#ifdef SWIG
inline AlgorithmIdentifier::AlgorithmIdentifier()
	: m_impl(0)
	, m_owner(false)
{}
#endif

inline AlgorithmIdentifier::AlgorithmIdentifier(TRN_AlgorithmIdentifier impl)
	: m_impl(impl)
	, m_owner(true)
{}

inline  AlgorithmIdentifier::AlgorithmIdentifier(const ObjectIdentifier::Predefined oid)
	: m_owner(true)
{
	REX(TRN_AlgorithmIdentifierCreateFromPredefined((enum TRN_ObjectIdentifier_Predefined)oid, &m_impl));
}

inline  AlgorithmIdentifier::AlgorithmIdentifier(const ObjectIdentifier& oid)
	: m_owner(true)
{
	REX(TRN_AlgorithmIdentifierCreateFromObjectIdentifier(oid.m_impl, &m_impl));
}

inline  AlgorithmIdentifier::AlgorithmIdentifier(const DigestAlgorithm::Type digest_algorithm_type)
	: m_owner(true)
{
	REX(TRN_AlgorithmIdentifierCreateFromDigestAlgorithm((TRN_DigestAlgorithm_Type)digest_algorithm_type, &m_impl));
}

inline  AlgorithmIdentifier::AlgorithmIdentifier(const ObjectIdentifier::Predefined oid, const AlgorithmParams& params)
	: m_owner(true)
{
	REX(TRN_AlgorithmIdentifierCreateFromPredefinedAndParams((TRN_ObjectIdentifier_Predefined)oid, params.m_impl, &m_impl));
}

inline  AlgorithmIdentifier::AlgorithmIdentifier(const ObjectIdentifier& oid, const AlgorithmParams& params)
	: m_owner(true)
{
	REX(TRN_AlgorithmIdentifierCreateFromObjectIdentifierAndParams(oid.m_impl, params.m_impl, &m_impl));
}

inline  AlgorithmIdentifier::AlgorithmIdentifier(const DigestAlgorithm::Type digest_algorithm_type, const AlgorithmParams& params)
	: m_owner(true)
{
	REX(TRN_AlgorithmIdentifierCreateFromDigestAlgorithmAndParams((TRN_DigestAlgorithm_Type)digest_algorithm_type, params.m_impl, &m_impl));
}

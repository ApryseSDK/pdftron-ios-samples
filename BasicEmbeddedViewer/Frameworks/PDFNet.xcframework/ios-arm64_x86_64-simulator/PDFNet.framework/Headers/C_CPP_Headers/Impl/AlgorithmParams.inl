

inline AlgorithmParams::AlgorithmParams()
	: m_impl(0)
	, m_owner(false)
{}


inline AlgorithmParams::AlgorithmParams(const AlgorithmParams& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if (other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline AlgorithmParams& AlgorithmParams::operator= (const AlgorithmParams& other)
{
	m_impl = other.m_impl;

	if (other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline AlgorithmParams::AlgorithmParams(TRN_AlgorithmParams impl)
	: m_impl(impl)
	, m_owner(true)
{}

inline AlgorithmParams::~AlgorithmParams()
{
	Destroy();
}

inline void AlgorithmParams::Destroy()
{
	if (m_owner)
	{
		DREX(m_impl, TRN_AlgorithmParamsDestroy((TRN_AlgorithmParams)m_impl));
		m_owner = false;
	}
}

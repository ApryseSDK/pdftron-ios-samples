#ifndef PDFTRON_CPPPDFUAC_INL
#define PDFTRON_CPPPDFUAC_INL

namespace pdftron { namespace PDF { namespace PDFUA {


static inline TRN_optionbase TRNOptionsConvert(const PDFUAOptions& opt)
{
	TRN_optionbase ret;
	ret.impl = const_cast<PDFUAOptions&>(opt).GetInternalObj().mp_obj;
	ret.type = e_option_type_sdf;
	return ret;
}


inline PDFUAConformance::~PDFUAConformance()
{
	Destroy();
}

inline PDFUAConformance::PDFUAConformance(const PDFUAConformance& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void PDFUAConformance::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_PDFUAConformanceDestroy(m_impl));
		m_owner = false;
	}
}

inline PDFUAConformance& pdftron::PDF::PDFUA::PDFUAConformance::operator= (const PDFUAConformance& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline PDFUAConformance::PDFUAConformance()
	: m_impl(0)
	, m_owner(true)
{
	REX(TRN_PDFUAConformanceCreate((TRN_PDFUAConformance*)&m_impl));
}

inline PDFUAConformance::PDFUAConformance(TRN_PDFUAConformance impl)
	: m_impl(impl)
	, m_owner(true)
{}

inline void PDFUAConformance::AutoConvert(const UString& src_file, const UString& dest_file)
{
	PDFUAOptions default_opts;
	AutoConvert(src_file, dest_file, default_opts); // Forward to non-optional-param signature
}
inline void PDFUAConformance::AutoConvert(const UString& src_file, const UString& dest_file, const PDFUAOptions& options)
{
	TRN_optionbase trn_opt = TRNOptionsConvert(options);
	REX(TRN_PDFUAConformanceAutoConvert((TRN_PDFUAConformance)m_impl, (TRN_UString)src_file.mp_impl, (TRN_UString)dest_file.mp_impl, &trn_opt));
}


// ---------------------------------------------------
//for xamarin use only
inline PDFUAConformance* PDFUAConformance::CreateInternal(ptrdiff_t impl) {
	return new PDFUAConformance((TRN_PDFUAConformance)impl);
}

inline ptrdiff_t PDFUAConformance::GetHandleInternal() {
    return (ptrdiff_t) m_impl;
}

		} //end pdftron
	} //end PDF
} //end PDFUA

#endif
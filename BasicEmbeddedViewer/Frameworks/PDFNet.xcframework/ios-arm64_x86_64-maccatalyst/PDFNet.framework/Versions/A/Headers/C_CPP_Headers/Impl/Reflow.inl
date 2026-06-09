inline Reflow::~Reflow()
{
	Destroy();
}

inline Reflow::Reflow(const Reflow& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void Reflow::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_ReflowDestroy(m_impl));
		m_owner = false;
	}
}

inline Reflow& pdftron::PDF::Reflow::operator= (const Reflow& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline Reflow::Reflow()
	: m_impl(0)
	, m_owner(false)
{}

inline Reflow::Reflow(TRN_Reflow impl)
	: m_impl(impl)
	, m_owner(true)
{}
inline UString Reflow::GetHtml()
{
	UString result;
	REX(TRN_ReflowGetHtml((TRN_Reflow)m_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString Reflow::GetAnnot(UString in_id)
{
	UString result;
	REX(TRN_ReflowGetAnnot((TRN_Reflow)m_impl, (TRN_UString)in_id.mp_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString Reflow::SetAnnot(UString in_json)
{
	UString result;
	REX(TRN_ReflowSetAnnot((TRN_Reflow)m_impl, (TRN_UString)in_json.mp_impl, (TRN_UString*)&result.mp_impl));
	return result;
}

inline void Reflow::SetIncludeImages(bool include)
{
	REX(TRN_ReflowSetIncludeImages((TRN_Reflow)m_impl, include));
}

inline void Reflow::SetHTMLOutputTextMarkup(bool include)
{
	REX(TRN_ReflowSetHTMLOutputTextMarkup((TRN_Reflow)m_impl, include));
}

inline void Reflow::SetMessageWhenNoReflowContent(UString content)
{
	REX(TRN_ReflowSetMessageWhenNoReflowContent((TRN_Reflow)m_impl, (TRN_UString)content.mp_impl));
}

inline void Reflow::SetMessageWhenReflowFailed(UString content)
{
	REX(TRN_ReflowSetMessageWhenReflowFailed((TRN_Reflow)m_impl, (TRN_UString)content.mp_impl));
}

inline void Reflow::SetHideBackgroundImages(bool hide_background_images)
{
	REX(TRN_ReflowSetHideBackgroundImages((TRN_Reflow)m_impl, hide_background_images));
}

inline void Reflow::SetHideImagesUnderText(bool hide_images_under_text)
{
	REX(TRN_ReflowSetHideImagesUnderText((TRN_Reflow)m_impl, hide_images_under_text));
}

inline void Reflow::SetHideImagesUnderInvisibleText(bool hide_images_under_invisible_text)
{
	REX(TRN_ReflowSetHideImagesUnderInvisibleText((TRN_Reflow)m_impl, hide_images_under_invisible_text));
}

inline void Reflow::SetDoNotReflowTextOverImages(bool do_not_reflow_text_over_images)
{
	REX(TRN_ReflowSetDoNotReflowTextOverImages((TRN_Reflow)m_impl, do_not_reflow_text_over_images));
}

inline void Reflow::SetFontOverrideName(UString font_family)
{
	REX(TRN_ReflowSetFontOverrideName((TRN_Reflow)m_impl, (TRN_UString)font_family.mp_impl));
}

inline void Reflow::SetCustomStyles(UString styles)
{
	REX(TRN_ReflowSetCustomStyles((TRN_Reflow)m_impl, (TRN_UString)styles.mp_impl));
}

inline void Reflow::SetIncludeBBoxForRecognizedZones(bool include)
{
	REX(TRN_ReflowSetIncludeBBoxForRecognizedZones((TRN_Reflow)m_impl, include));
}


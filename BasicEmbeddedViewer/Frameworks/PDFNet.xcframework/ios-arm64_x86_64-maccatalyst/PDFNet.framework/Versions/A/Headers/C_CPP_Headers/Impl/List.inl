inline List::List(TRN_List impl)
	: ContentNode(0)
	, m_impl(impl)
{
	if (m_impl)
	{
		TRN_ListAsContentElement(m_impl, &(ContentElement::m_impl));
	}
}

inline List::~List()
{
	Destroy();
}

inline void List::Destroy()
{
}

inline void List::SetNumberFormat(const NumberFormat format, const UString& text, bool cascade)
{
	TRN_ListSetNumberFormat(m_impl, (TRN_ListNumberFormat)format, text.mp_impl, cascade);
}

inline void List::SetNumberFormat(const NumberFormat format)
{
	SetNumberFormat(format, UString("."), false);
}

inline TextStyledElement List::GetLabelStyle()
{
	TRN_ContentElement elem_impl;
	TRN_ListAsContentElement(m_impl, &elem_impl);
	return TextStyledElement(elem_impl);
}

inline void List::SetStartIndex(int idx)
{
	TRN_ListSetStartIndex(m_impl, idx);
}

inline ListItem List::AddItem()
{
	TRN_ListItem impl;
	TRN_ListAddItem(m_impl, &impl);
	return ListItem(impl);
}

inline void List::ContinueList()
{
	TRN_ListContinueList(m_impl);
}

inline int List::GetIndentationLevel()
{
	int level;
	TRN_ListGetIndentationLevel(m_impl, &level);
	return level;
}

inline int List::GetListIdentifier()
{
	int id;
	TRN_ListGetListIdentifier(m_impl, &id);
	return id;
}

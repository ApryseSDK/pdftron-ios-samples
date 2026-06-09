inline ListItem::ListItem(TRN_ListItem impl)
	: ContentNode(0)
	, m_impl(impl)
{
	if (m_impl)
	{
		TRN_ListItemAsContentElement(m_impl, &(ContentElement::m_impl));
	}
}

inline ListItem::~ListItem()
{
	Destroy();
}

inline void ListItem::Destroy()
{
}

inline Paragraph ListItem::AddParagraph()
{
	TRN_Paragraph para;
	TRN_ListItemAddParagraph(m_impl, &para);
	return Paragraph(para);
}

inline Paragraph ListItem::AddParagraph(const UString& text)
{
	TRN_Paragraph para;
	TRN_ListItemAddParagraphWithText(m_impl, text.mp_impl, &para);
	return Paragraph(para);
}

inline List ListItem::AddList()
{
	TRN_List impl;
	TRN_ListItemAddList(m_impl, &impl);
	return List(impl);
}

inline int ListItem::GetIndentationLevel()
{
	int level;
	TRN_ListItemGetIndentationLevel(m_impl, &level);
	return level;
}

inline int ListItem::GetListIdentifier()
{
	int id;
	TRN_ListItemGetListIdentifier(m_impl, &id);
	return id;
}

inline int ListItem::GetItemIndex()
{
	int index;
	TRN_ListItemGetItemIndex(m_impl, &index);
	return index;
}

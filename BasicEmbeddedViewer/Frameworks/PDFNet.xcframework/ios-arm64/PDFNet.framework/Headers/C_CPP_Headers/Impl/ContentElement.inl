inline ContentElement::ContentElement(TRN_ContentElement impl)
	: m_impl(impl)
{
}

inline ContentElement::~ContentElement()
{
	Destroy();
}

inline void ContentElement::Destroy() {}

inline ElementRef<ContentNode> ContentElement::AsContentNode() const
{
	TRN_ContentNode content_node_impl;
	REX(TRN_ContentElementAsContentNode(m_impl, &content_node_impl));
	return ElementRef<ContentNode>(content_node_impl);
}

inline ElementRef<TextRun> ContentElement::AsTextRun() const
{
	TRN_TextRun text_run_impl;
	REX(TRN_ContentElementAsTextRun(m_impl, &text_run_impl));
	return ElementRef<TextRun>(text_run_impl);
}

inline ElementRef<Paragraph> ContentElement::AsParagraph() const
{
	TRN_Paragraph paragraph_impl;
	REX(TRN_ContentElementAsParagraph(m_impl, &paragraph_impl));
	return ElementRef<Paragraph>(paragraph_impl);
}

inline ElementRef<Table> ContentElement::AsTable() const
{
	TRN_Table table_impl;
	REX(TRN_ContentElementAsTable(m_impl, &table_impl));
	return ElementRef<Table>(table_impl);
}

inline ElementRef<TableRow> ContentElement::AsTableRow() const
{
	TRN_TableRow table_row_impl;
	REX(TRN_ContentElementAsTableRow(m_impl, &table_row_impl));
	return ElementRef<TableRow>(table_row_impl);
}

inline ElementRef<TableCell> ContentElement::AsTableCell() const
{
	TRN_TableCell table_cell_impl;
	REX(TRN_ContentElementAsTableCell(m_impl, &table_cell_impl));
	return ElementRef<TableCell>(table_cell_impl);
}

inline TextStyledElement ContentElement::GetTextStyledElement()
{
	return TextStyledElement(m_impl);
}

inline ElementRef<List> ContentElement::AsList() const
{
	TRN_List list_impl;
	REX(TRN_ContentElementAsList(m_impl, &list_impl));
	return ElementRef<List>(list_impl);
}

inline ElementRef<ListItem> ContentElement::AsListItem() const
{
	TRN_ListItem list_item_impl;
	REX(TRN_ContentElementAsListItem(m_impl, &list_item_impl));
	return ElementRef<ListItem>(list_item_impl);
}


inline FlowDocument::~FlowDocument()
{
	Destroy();
}

inline FlowDocument::FlowDocument()
{
	TRN_FlowDocumentCreate(&m_impl);
}

inline void FlowDocument::Destroy()
{
	DREX(m_impl, TRN_FlowDocumentDestroy(m_impl));
}

inline ContentNode FlowDocument::GetBody() const
{
	TRN_ContentNode body;
	REX(TRN_FlowDocumentGetBody(m_impl, &body));
	return ContentNode(body);
}

inline PDF::PDFDoc FlowDocument::PaginateToPDF()
{
	TRN_PDFDoc doc;
	REX(TRN_FlowDocumentPaginateToPDF(m_impl, &doc));
	return PDF::PDFDoc(doc);
}

inline Paragraph FlowDocument::AddParagraph()
{
	TRN_Paragraph impl;
	TRN_FlowDocumentAddParagraph(m_impl, &impl);
	return Paragraph(impl);
}

inline Paragraph FlowDocument::AddParagraph(const UString& text)
{
	TRN_Paragraph impl;
	TRN_FlowDocumentAddParagraphWithText(m_impl, text.mp_impl, &impl);
	return Paragraph(impl);
}

inline Table FlowDocument::AddTable()
{
	TRN_Table new_table;
	TRN_FlowDocumentAddTable(m_impl, &new_table);
	return Table(new_table);
}

inline List FlowDocument::AddList()
{
	TRN_List impl;
	TRN_FlowDocumentAddList(m_impl, &impl);
	return List(impl);
}

inline void FlowDocument::SetDefaultPageSize(double width_points, double height_points)
{
	TRN_FlowDocumentSetDefaultPageSize(m_impl, width_points, height_points);
}

inline void FlowDocument::SetDefaultMargins(double left_points, double top_points, double right_points, double bottom_points)
{
	TRN_FlowDocumentSetDefaultMargins(m_impl, left_points, top_points, right_points, bottom_points);
}

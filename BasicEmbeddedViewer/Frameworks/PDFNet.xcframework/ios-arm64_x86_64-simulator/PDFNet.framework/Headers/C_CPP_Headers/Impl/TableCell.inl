inline TableCell::TableCell(TRN_TableCell impl)
	: ContentNode(impl)
{
}

inline TableCell::~TableCell()
{
	Destroy();
}

inline void TableCell::Destroy() {}


inline Paragraph TableCell::AddParagraph()
{
	TRN_Paragraph para;
	TRN_TableCellAddParagraph(m_impl, &para);
	return Paragraph(para);
}

inline Paragraph TableCell::AddParagraph(const UString& text)
{
	TRN_Paragraph para;
	TRN_TableCellAddParagraphWithText(m_impl, text.mp_impl, &para);
	return Paragraph(para);
}

inline Table TableCell::AddTable()
{
	TRN_Table new_table;
	TRN_TableCellAddTable(m_impl, &new_table);
	return Table(new_table);
}

inline TableCell TableCell::MergeCellsRight(UInt32 num)
{
	TRN_TableCell impl;
	REX(TRN_TableCellMergeCellsRight(m_impl, num, &impl));
	return TableCell(impl);
}

inline TableCell TableCell::MergeCellsDown(UInt32 num)
{
	TRN_TableCell impl;
	REX(TRN_TableCellMergeCellsDown(m_impl, num, &impl));
	return TableCell(impl);
}


inline void TableCell::SetBackgroundColor(UInt8 red, UInt8 green, UInt8 blue)
{
	REX(TRN_TableCellSetBackgroundColor(m_impl, red, green, blue));
}

inline void TableCell::SetBorder(double thickness, UInt8 red, UInt8 green, UInt8 blue)
{
	REX(TRN_TableCellSetBorder(m_impl, thickness, red, green, blue));
}


inline double TableCell::GetBorderThickness()
{
	RetDbl(TRN_TableCellGetBorderThickness(m_impl, &result));
}

inline void TableCell::SetVerticalAlignment(CellAlignmentVertical val)
{
	REX(TRN_TableCellSetVerticalAlignment(m_impl, static_cast<TRN_TableCellAlignmentVertical>(val)));
}


inline TableCell::CellAlignmentVertical TableCell::GetVerticalAlignment()
{
	TRN_TableCellAlignmentVertical result;
	REX(TRN_TableCellGetVerticalAlignment(m_impl, &result));
	return (CellAlignmentVertical)result;
}

inline void TableCell::SetHorizontalAlignment(CellAlignmentHorizontal val)
{
	REX(TRN_TableCellSetHorizontalAlignment(m_impl, static_cast<TRN_TableCellAlignmentHorizontal>(val)));
}

inline TableCell::CellAlignmentHorizontal TableCell::GetHorizontalAlignment()
{
	TRN_TableCellAlignmentHorizontal result;
	REX(TRN_TableCellGetHorizontalAlignment(m_impl, &result));
	return (CellAlignmentHorizontal)result;
}


inline void TableCell::SetHeight(double val)
{
	REX(TRN_TableCellSetHeight(m_impl, val));
}

inline double TableCell::GetHeight()
{
	RetDbl(TRN_TableCellGetHeight(m_impl, &result));
}

inline void TableCell::SetWidth(double val)
{
	REX(TRN_TableCellSetWidth(m_impl, val));
}

inline double TableCell::GetWidth()
{
	RetDbl(TRN_TableCellGetWidth(m_impl, &result));
}

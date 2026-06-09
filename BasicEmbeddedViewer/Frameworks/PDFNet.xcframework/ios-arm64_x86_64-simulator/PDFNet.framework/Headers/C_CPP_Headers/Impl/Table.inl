inline Table::Table(TRN_Table impl)
	: ContentNode(impl)
{
}

inline Table::~Table()
{
	Destroy();
}

inline void Table::Destroy() {}

 
inline TableRow Table::AddTableRow()
{
	TRN_TableRow impl;
	REX(TRN_TableAddTableRow(m_impl, &impl));
	return TableRow(impl);
}



inline void Table::SetDefaultColumnWidth(double val)
{
	REX(TRN_TableSetDefaultColumnWidth(m_impl, val));
}

inline void Table::SetDefaultRowHeight(double val)
{
	REX(TRN_TableSetDefaultRowHeight(m_impl, val));
}


inline double Table::GetDefaultRowHeight()
{
	RetDbl(TRN_TableGetDefaultRowHeight(m_impl, &result));
}


inline UInt32 Table::GetNumRows()
{
	TRN_UInt32 result;
	REX(TRN_TableGetNumRows(m_impl, &result));
	return (UInt32)result;
}

inline UInt32 Table::GetNumColumns()
{
	TRN_UInt32 result;
	REX(TRN_TableGetNumColumns(m_impl, &result));
	return (UInt32)result;
}

inline void Table::SetBorder(double thickness, UInt8 red, UInt8 green, UInt8 blue)
{
	REX(TRN_TableSetBorder(m_impl, thickness, red, green, blue));
}

inline double Table::GetBorderThickness()
{
	RetDbl(TRN_TableGetBorderThickness(m_impl, &result));
}

inline TableCell Table::GetTableCell(UInt32 column, UInt32 row)
{
	TRN_TableCell impl;
	REX(TRN_TableGetTableCell(m_impl, column, row, &impl));
	return TableCell(impl);
}

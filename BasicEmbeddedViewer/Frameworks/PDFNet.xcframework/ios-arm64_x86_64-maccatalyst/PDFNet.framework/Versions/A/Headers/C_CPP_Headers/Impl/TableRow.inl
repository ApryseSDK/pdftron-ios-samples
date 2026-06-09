inline TableRow::TableRow(TRN_TableRow impl)
	: ContentNode(impl)
{
}

inline TableRow::~TableRow()
{
	Destroy();
}

inline void TableRow::Destroy() {}


inline TableCell TableRow::AddTableCell()
{
	TRN_TableCell impl;
	REX(TRN_TableRowAddTableCell(m_impl, &impl));
	return TableCell(impl);
}


inline void TableRow::SetRowHeight(double val)
{
	REX(TRN_TableRowSetRowHeight(m_impl, val));
}

inline UInt32 TableRow::GetNumColumns()
{
	TRN_UInt32 result;
	REX(TRN_TableRowGetNumColumns(m_impl, &result));
	return (UInt32)result;
}

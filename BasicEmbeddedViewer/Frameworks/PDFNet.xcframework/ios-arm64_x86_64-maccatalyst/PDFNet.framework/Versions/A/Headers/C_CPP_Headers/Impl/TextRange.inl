//for xamarin use only
inline TextRange* TextRange::CreateInternal(ptrdiff_t impl) {
	return new TextRange((TRN_TextRange)impl);
}

inline ptrdiff_t TextRange::GetHandleInternal() {
    return (ptrdiff_t) mp_textrange;
}

inline TextRange::TextRange()
{
	REX(TRN_TextRangeCreate(&mp_textrange));
}


inline TextRange::~TextRange()
{
	DREX(mp_textrange, TRN_TextRangeDestroy(mp_textrange));
}

inline void TextRange::Destroy ()
{
	REX(TRN_TextRangeDestroy(mp_textrange));
	mp_textrange = 0;
}

inline TextRange::TextRange(const TextRange& tr)
{
	REX(TRN_TextRangeCopyCtor(tr.mp_textrange, &mp_textrange));
}

inline TextRange& TextRange::operator = (const TextRange& tr)
{
	REX(TRN_TextRangeAssign(mp_textrange, tr.mp_textrange));
	return *this;
}

inline int TextRange::GetPageNumber() const
{
	RetInt(TRN_TextRangeGetPageNumber(mp_textrange, &result));
}

inline std::vector<QuadPoint> TextRange::GetQuads() const
{
	int num;
	double* quads;
	TRN_TextRangeGetQuads(mp_textrange, ((const double**)&quads), &num);
	std::vector<QuadPoint> result;
	result.resize((std::vector<QuadPoint>::size_type)num);
	
	std::vector<QuadPoint>::size_type i;
	for(i = 0; i < (std::vector<QuadPoint>::size_type)num; i++) {
		Point p1 = Point(quads[i*8+0], quads[i*8+1]);
		Point p2 = Point(quads[i*8+2], quads[i*8+3]);
		Point p3 = Point(quads[i*8+4], quads[i*8+5]);
		Point p4 = Point(quads[i*8+6], quads[i*8+7]);
		result[i] = QuadPoint(p1, p2, p3, p4);
	}
	return result;
}

#ifndef SWIG
inline int TextRange::GetQuads(const double* &quads) const
{
	RetInt(TRN_TextRangeGetQuads(mp_textrange, &quads, &result));
}
#endif

inline UString TextRange::GetText() const
{
	UString result;
	REX(TRN_TextRangeGetText(mp_textrange, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString TextRange::GetTextBefore(int count) const
{
	UString result;
	REX(TRN_TextRangeGetTextBefore(mp_textrange, count, (TRN_UString*)&result.mp_impl));
	return result;
}

inline UString TextRange::GetTextAfter(int count) const
{
	UString result;
	REX(TRN_TextRangeGetTextAfter(mp_textrange, count, (TRN_UString*)&result.mp_impl));
	return result;
}

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFTextRange
#define PDFTRON_H_CPDFTextRange

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_TextRangeCreate(TRN_TextRange* result);
TRN_API TRN_TextRangeDestroy(TRN_TextRange tr);
TRN_API TRN_TextRangeCopyCtor(TRN_TextRange tr, TRN_TextRange* result);
TRN_API TRN_TextRangeAssign(TRN_TextRange result, TRN_TextRange tr);

TRN_API TRN_TextRangeGetPageNumber(TRN_TextRange tr, int* result);
TRN_API TRN_TextRangeGetQuads(TRN_TextRange tr, const double** quads, int* result);
TRN_API TRN_TextRangeGetText(TRN_TextRange tr, TRN_UString* result);
TRN_API TRN_TextRangeGetTextBefore(TRN_TextRange tr, int count, TRN_UString* result);
TRN_API TRN_TextRangeGetTextAfter(TRN_TextRange tr, int count, TRN_UString* result);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFTextRange

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CTimestampingResult
#define PDFTRON_H_CTimestampingResult

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>



/* methods: */
TRN_API TRN_TimestampingResultGetStatus(TRN_TimestampingResult self, TRN_Bool* result);
TRN_API TRN_TimestampingResultGetString(TRN_TimestampingResult self, TRN_UString* result);
TRN_API TRN_TimestampingResultHasResponseVerificationResult(TRN_TimestampingResult self, TRN_Bool* result);
TRN_API TRN_TimestampingResultGetResponseVerificationResult(TRN_TimestampingResult self, TRN_EmbeddedTimestampVerificationResult* result);
TRN_API TRN_TimestampingResultGetData(TRN_TimestampingResult self, TRN_Vector* result);

TRN_API TRN_TimestampingResultDestroy(TRN_TimestampingResult self);
TRN_API TRN_TimestampingResultCopyCtor(TRN_TimestampingResult source, TRN_TimestampingResult* result);
TRN_API TRN_TimestampingResultAssign(TRN_TimestampingResult source, TRN_TimestampingResult* result);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CTimestampingResult */

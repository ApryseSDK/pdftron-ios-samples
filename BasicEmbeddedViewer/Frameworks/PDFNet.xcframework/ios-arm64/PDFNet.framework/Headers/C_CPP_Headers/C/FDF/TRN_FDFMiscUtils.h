//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CFDFMiscUtils
#define PDFTRON_H_CFDFMiscUtils

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

#ifdef EMSCRIPTEN
TRN_API TRN_FDFDocConvertImagedataToAP(const char* input, TRN_UString* result);
#endif // EMSCRIPTEN

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CFDFMiscUtils

//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CContentEdit
#define PDFTRON_H_CContentEdit

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>

TRN_API TRN_ContentEditBegin(TRN_PDFDoc input);
TRN_API TRN_ContentEditRunXML(TRN_UString commandsXML, TRN_UString* result);
TRN_API TRN_ContentEditEnd(void);

#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CContentEdit */

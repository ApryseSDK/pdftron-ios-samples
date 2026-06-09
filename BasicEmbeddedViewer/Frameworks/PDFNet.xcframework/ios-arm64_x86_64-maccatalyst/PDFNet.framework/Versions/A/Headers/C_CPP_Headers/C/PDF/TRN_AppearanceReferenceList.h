//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFAppearanceReferenceList
#define PDFTRON_H_CPDFAppearanceReferenceList

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/PDF/TRN_Annot.h>

	TRN_API TRN_AppearanceReferenceListCreate(TRN_AppearanceReferenceList* result);
	TRN_API TRN_AppearanceReferenceListAddReference(TRN_AppearanceReferenceList references, TRN_UInt32 obj_num, TRN_UInt16 gen_num, const char* appearance_state, enum TRN_AnnotState annot_state);
	TRN_API TRN_AppearanceReferenceListDestroy(TRN_AppearanceReferenceList references);
	TRN_API TRN_AppearanceStringListCreate(TRN_AppearanceStringList* result);
	TRN_API TRN_AppearanceStringListAddString(TRN_AppearanceStringList strings, const char* base64str, double w, double h, const char* id);
	TRN_API TRN_AppearanceStringListDestroy(TRN_AppearanceStringList strings);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFAppearanceReferenceList

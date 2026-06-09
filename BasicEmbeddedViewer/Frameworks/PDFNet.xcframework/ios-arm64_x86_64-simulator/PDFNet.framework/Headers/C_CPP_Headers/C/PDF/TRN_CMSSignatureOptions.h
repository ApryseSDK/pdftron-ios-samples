//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CCMSSignatureOptions
#define PDFTRON_H_CCMSSignatureOptions

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>


struct TRN_CMSSignatureOptions_tag;
typedef struct TRN_CMSSignatureOptions_tag* TRN_CMSSignatureOptions;

TRN_API TRN_CMSSignatureOptionsCreate(TRN_CMSSignatureOptions* result);
TRN_API TRN_CMSSignatureOptionsAddTimestampToken(TRN_CMSSignatureOptions self, const TRN_UChar* token_buf, const size_t token_buf_size);

TRN_API TRN_CMSSignatureOptionsDestroy(TRN_CMSSignatureOptions self);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CCMSSignatureOptions */

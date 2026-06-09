//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CAlgorithmParams
#define PDFTRON_H_CAlgorithmParams

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>


TRN_API TRN_AlgorithmParamsDestroy(TRN_AlgorithmParams self);


TRN_API TRN_RSASSAPSSParamsCreate(TRN_RSASSAPSSParams* result);
TRN_API TRN_RSASSAPSSParamsCreateFromAlgoIdAndSaltLen(TRN_AlgorithmIdentifier digest_algorithm_id, TRN_UInt32 salt_length, TRN_RSASSAPSSParams* result);

TRN_API TRN_RSASSAPSSParamsGetDigestAlgorithm(TRN_RSASSAPSSParams self, TRN_AlgorithmIdentifier* result);
TRN_API TRN_RSASSAPSSParamsSetDigestAlgorithm(TRN_RSASSAPSSParams self, TRN_AlgorithmIdentifier value);
TRN_API TRN_RSASSAPSSParamsGetMaskGenAlgorithm(TRN_RSASSAPSSParams self, TRN_AlgorithmIdentifier* result);
TRN_API TRN_RSASSAPSSParamsSetMaskGenAlgorithm(TRN_RSASSAPSSParams self, TRN_AlgorithmIdentifier value);
TRN_API TRN_RSASSAPSSParamsGetSaltLength(TRN_RSASSAPSSParams self, TRN_UInt32* result);
TRN_API TRN_RSASSAPSSParamsSetSaltLength(TRN_RSASSAPSSParams self, TRN_UInt32 value);
TRN_API TRN_RSASSAPSSParamsGetTrailerField(TRN_RSASSAPSSParams self, TRN_UInt32* result);
TRN_API TRN_RSASSAPSSParamsSetTrailerField(TRN_RSASSAPSSParams self, TRN_UInt32 value);

#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CAlgorithmParams */

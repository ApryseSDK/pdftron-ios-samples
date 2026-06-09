//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CAlgorithmIdentifier
#define PDFTRON_H_CAlgorithmIdentifier

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>
#include <C/Crypto/TRN_ObjectIdentifier.h>


TRN_API TRN_AlgorithmIdentifierCreateFromPredefined(enum TRN_ObjectIdentifier_Predefined oid_type, TRN_AlgorithmIdentifier* result);
TRN_API TRN_AlgorithmIdentifierCreateFromObjectIdentifier(TRN_ObjectIdentifier oid, TRN_AlgorithmIdentifier* result);
TRN_API TRN_AlgorithmIdentifierCreateFromDigestAlgorithm(enum TRN_DigestAlgorithm_Type digest_algorithm_type, TRN_AlgorithmIdentifier* result);
TRN_API TRN_AlgorithmIdentifierCreateFromPredefinedAndParams(enum TRN_ObjectIdentifier_Predefined oid_type, TRN_AlgorithmParams params, TRN_AlgorithmIdentifier* result);
TRN_API TRN_AlgorithmIdentifierCreateFromObjectIdentifierAndParams(TRN_ObjectIdentifier oid, TRN_AlgorithmParams params, TRN_AlgorithmIdentifier* result);
TRN_API TRN_AlgorithmIdentifierCreateFromDigestAlgorithmAndParams(enum TRN_DigestAlgorithm_Type digest_algorithm_type, TRN_AlgorithmParams params, TRN_AlgorithmIdentifier* result);
TRN_API TRN_AlgorithmIdentifierDestroy(TRN_AlgorithmIdentifier self);

#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CAlgorithmIdentifier */

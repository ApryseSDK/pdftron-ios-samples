//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CObjectIdentifier
#define PDFTRON_H_CObjectIdentifier

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>
#include <C/Crypto/TRN_DigestAlgorithm.h>


struct TRN_ObjectIdentifier_tag;
typedef struct TRN_ObjectIdentifier_tag* TRN_ObjectIdentifier;

/* enums:  */
enum TRN_ObjectIdentifier_Predefined {
	e_ObjectIdentifier_commonName = 0,
	e_ObjectIdentifier_surname = 1,
	e_ObjectIdentifier_countryName = 2,
	e_ObjectIdentifier_localityName = 3,
	e_ObjectIdentifier_stateOrProvinceName = 4,
	e_ObjectIdentifier_streetAddress = 5,
	e_ObjectIdentifier_organizationName = 6,
	e_ObjectIdentifier_organizationalUnitName = 7,
	e_ObjectIdentifier_SHA1 = 8,
	e_ObjectIdentifier_SHA256 = 9,
	e_ObjectIdentifier_SHA384 = 10,
	e_ObjectIdentifier_SHA512 = 11,
	e_ObjectIdentifier_RIPEMD160 = 12,
	e_ObjectIdentifier_RSA_encryption_PKCS1 = 13,
	e_ObjectIdentifier_RSASSA_PSS = 14,
	e_ObjectIdentifier_MGF1 = 15
};

/* methods: */
TRN_API TRN_ObjectIdentifierCreateFromPredefined(enum TRN_ObjectIdentifier_Predefined in_oid_enum, TRN_ObjectIdentifier* result);
TRN_API TRN_ObjectIdentifierCreateFromIntArray(TRN_UInt32* in_list, TRN_UInt32 in_list_size, TRN_ObjectIdentifier* result);
TRN_API TRN_ObjectIdentifierCreateFromDigestAlgorithm(enum TRN_DigestAlgorithm_Type in_algorithm, TRN_ObjectIdentifier* result);
TRN_API TRN_ObjectIdentifierDestroy(TRN_ObjectIdentifier self);
TRN_API TRN_ObjectIdentifierGetRawValue(TRN_ObjectIdentifier self, TRN_Vector* result);

#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CObjectIdentifier */

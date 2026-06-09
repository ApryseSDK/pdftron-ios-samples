//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CVerificationOptions
#define PDFTRON_H_CVerificationOptions

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>
#include <C/Crypto/TRN_X509Certificate.h>


struct TRN_VerificationOptions_tag;
typedef struct TRN_VerificationOptions_tag* TRN_VerificationOptions;

/* enums:  */
enum TRN_VerificationOptions_SecurityLevel {
	e_VerificationOptions_compatibility_and_archiving = 0,
	e_VerificationOptions_maximum = 1
};
enum TRN_VerificationOptions_TimeMode {
	e_VerificationOptions_signing = 0,
	e_VerificationOptions_timestamp = 1,
	e_VerificationOptions_current = 2
};
enum TRN_VerificationOptions_CertificateTrustFlag {
	e_VerificationOptions_signing_trust = 0x0001,
	e_VerificationOptions_certification_trust = 0x0002,
	e_VerificationOptions_dynamic_content = 0x0004,
	e_VerificationOptions_javascript = 0x0010,
	e_VerificationOptions_identity = 0x0020,
	e_VerificationOptions_trust_anchor = 0x0040,
	e_VerificationOptions_default_trust = 0x0061,
	e_VerificationOptions_complete_trust = 0x0077
};

/* methods: */
TRN_API TRN_VerificationOptionsCreate(enum TRN_VerificationOptions_SecurityLevel in_level, TRN_VerificationOptions* result);
TRN_API TRN_VerificationOptionsAddTrustedCertificate(TRN_VerificationOptions self, const TRN_UChar* in_certificate_buf, const size_t in_buf_size, const TRN_UInt16 in_trust_flags);
TRN_API TRN_VerificationOptionsAddTrustedCertificateUString(TRN_VerificationOptions self, TRN_UString in_filepath, const TRN_UInt16 in_trust_flags);
TRN_API TRN_VerificationOptionsAddTrustedCertificates(TRN_VerificationOptions self, const TRN_UChar* in_P7C_binary_DER_certificates_file_data_buf, const size_t in_buf_size);
TRN_API TRN_VerificationOptionsLoadTrustList(TRN_VerificationOptions self, TRN_FDFDoc in_fdf_cert_exchange_data);
TRN_API TRN_VerificationOptionsEnableModificationVerification(TRN_VerificationOptions self, TRN_Bool in_on_or_off);
TRN_API TRN_VerificationOptionsEnableDigestVerification(TRN_VerificationOptions self, TRN_Bool in_on_or_off);
TRN_API TRN_VerificationOptionsEnableTrustVerification(TRN_VerificationOptions self, TRN_Bool in_on_or_off);
TRN_API TRN_VerificationOptionsSetRevocationProxyPrefix(TRN_VerificationOptions self, const TRN_UString in_str);
TRN_API TRN_VerificationOptionsSetRevocationTimeout(TRN_VerificationOptions self, const TRN_UInt32 in_revocation_timeout_milliseconds);
TRN_API TRN_VerificationOptionsEnableOnlineCRLRevocationChecking(TRN_VerificationOptions self, TRN_Bool in_on_or_off);
TRN_API TRN_VerificationOptionsEnableOnlineOCSPRevocationChecking(TRN_VerificationOptions self, TRN_Bool in_on_or_off);
TRN_API TRN_VerificationOptionsEnableOnlineRevocationChecking(TRN_VerificationOptions self, TRN_Bool in_on_or_off);

TRN_API TRN_VerificationOptionsDestroy(TRN_VerificationOptions self);

TRN_API TRN_VerificationOptionsGetTrustedCertificateCount(TRN_VerificationOptions self, TRN_UInt32* result);
TRN_API TRN_VerificationOptionsGetTrustedCertificate(TRN_VerificationOptions self, const TRN_UInt32 index, TRN_X509Certificate* result);

#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CVerificationOptions */

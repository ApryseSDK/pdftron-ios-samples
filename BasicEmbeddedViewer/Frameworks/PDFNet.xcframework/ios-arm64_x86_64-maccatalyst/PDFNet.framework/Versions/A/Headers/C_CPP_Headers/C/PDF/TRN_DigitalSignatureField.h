//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CDigitalSignatureField
#define PDFTRON_H_CDigitalSignatureField

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>
#include <C/Crypto/TRN_X509Certificate.h>
#include <C/PDF/TRN_TimestampingConfiguration.h>
#include <C/PDF/TRN_CMSSignatureOptions.h>
/* enums:  */

enum TRN_DigitalSignatureField_SubFilterType 
{
	e_DigitalSignatureField_adbe_x509_rsa_sha1,
	e_DigitalSignatureField_adbe_pkcs7_detached,
	e_DigitalSignatureField_adbe_pkcs7_sha1,
	e_DigitalSignatureField_ETSI_CAdES_detached,
	e_DigitalSignatureField_ETSI_RFC3161,
	e_DigitalSignatureField_unknown,
	e_DigitalSignatureField_absent
};
enum TRN_DigitalSignatureField_DocumentPermissions 
{
	e_DigitalSignatureField_no_changes_allowed = 1,
	e_DigitalSignatureField_formfilling_signing_allowed,
	e_DigitalSignatureField_annotating_formfilling_signing_allowed,
	e_DigitalSignatureField_unrestricted
};
enum TRN_DigitalSignatureField_FieldPermissions 
{
	e_DigitalSignatureField_lock_all,
	e_DigitalSignatureField_include,
	e_DigitalSignatureField_exclude
};

/* methods: */

TRN_API TRN_DigitalSignatureFieldHasCryptographicSignature(const TRN_DigitalSignatureField* self, TRN_Bool* result);
TRN_API TRN_DigitalSignatureFieldGetSubFilter(const TRN_DigitalSignatureField* self, enum TRN_DigitalSignatureField_SubFilterType* result);
TRN_API TRN_DigitalSignatureFieldGetSignatureName(const TRN_DigitalSignatureField* self, TRN_UString* result);
TRN_API TRN_DigitalSignatureFieldGetLocation(const TRN_DigitalSignatureField* self, TRN_UString* result);
TRN_API TRN_DigitalSignatureFieldGetReason(const TRN_DigitalSignatureField* self, TRN_UString* result);
TRN_API TRN_DigitalSignatureFieldGetContactInfo(const TRN_DigitalSignatureField* self, TRN_UString* result);
TRN_API TRN_DigitalSignatureFieldGetCertCount(const TRN_DigitalSignatureField* self, TRN_UInt32* result);
TRN_API TRN_DigitalSignatureFieldHasVisibleAppearance(const TRN_DigitalSignatureField* self, TRN_Bool* result);
TRN_API TRN_DigitalSignatureFieldSetContactInfo(TRN_DigitalSignatureField* self, const TRN_UString in_contact_info);
TRN_API TRN_DigitalSignatureFieldSetLocation(TRN_DigitalSignatureField* self, const TRN_UString in_location);
TRN_API TRN_DigitalSignatureFieldSetReason(TRN_DigitalSignatureField* self, const TRN_UString in_reason);
TRN_API TRN_DigitalSignatureFieldSetDocumentPermissions(TRN_DigitalSignatureField* self, enum TRN_DigitalSignatureField_DocumentPermissions in_perms);
TRN_API TRN_DigitalSignatureFieldSignOnNextSave(TRN_DigitalSignatureField* self, const TRN_UString in_pkcs12_keyfile_path, const TRN_UString in_password);
TRN_API TRN_DigitalSignatureFieldCertifyOnNextSave(TRN_DigitalSignatureField* self, const TRN_UString in_pkcs12_keyfile_path, const TRN_UString in_password);
TRN_API TRN_DigitalSignatureFieldIsLockedByDigitalSignature(const TRN_DigitalSignatureField* self, TRN_Bool* result);
TRN_API TRN_DigitalSignatureFieldGetDocumentPermissions(const TRN_DigitalSignatureField* self, enum TRN_DigitalSignatureField_DocumentPermissions* result);
TRN_API TRN_DigitalSignatureFieldClearSignature(TRN_DigitalSignatureField* self);

/* methods that were not originally codegened: */
// C version of: DigitalSignatureField(const PDF::Field& in_field)
TRN_API TRN_DigitalSignatureFieldCreateFromField(const TRN_Field* in_field, TRN_DigitalSignatureField* result);
TRN_API TRN_DigitalSignatureFieldGetSigningTime(const TRN_DigitalSignatureField* self, TRN_Date* result);
TRN_API TRN_DigitalSignatureFieldGetCert(const TRN_DigitalSignatureField* self, TRN_UInt32 in_index, TRN_Vector* result);
TRN_API TRN_DigitalSignatureFieldSetFieldPermissions(TRN_DigitalSignatureField* self, const enum TRN_DigitalSignatureField_FieldPermissions in_action, const TRN_UString* in_field_names_list, TRN_UInt32 in_field_names_list_size);
// C version of: void SignOnNextSave(const trn::UChar* in_pkcs12_buffer, const size_t in_pkcs12_buf_size, const UString& in_password);
TRN_API TRN_DigitalSignatureFieldSignOnNextSaveFromBuffer(TRN_DigitalSignatureField* self, const TRN_UChar* in_pkcs12_buffer, const TRN_UInt32 in_pkcs12_buf_size, const TRN_UString in_password);
TRN_API TRN_DigitalSignatureFieldSignOnNextSaveWithCustomHandler(TRN_DigitalSignatureField* self, const TRN_SignatureHandlerId in_signature_handler_id);
// C version of: void CertifyOnNextSave(const trn::UChar* in_pkcs12_buffer, const size_t in_pkcs12_buf_size, const UString& in_password);
TRN_API TRN_DigitalSignatureFieldCertifyOnNextSaveFromBuffer(TRN_DigitalSignatureField* self, const TRN_UChar* in_pkcs12_buffer, const TRN_UInt32 in_pkcs12_buf_size, const TRN_UString in_password);
TRN_API TRN_DigitalSignatureFieldCertifyOnNextSaveWithCustomHandler(TRN_DigitalSignatureField* self, const TRN_SignatureHandlerId in_signature_handler_id);
TRN_API TRN_DigitalSignatureFieldGetSDFObj(const TRN_DigitalSignatureField* self, TRN_Obj* result);
TRN_API TRN_DigitalSignatureFieldGetLockedFields(const TRN_DigitalSignatureField* self, TRN_Vector* result);
TRN_API TRN_DigitalSignatureFieldVerify(const TRN_DigitalSignatureField* self, const TRN_VerificationOptions in_opts, TRN_VerificationResult* result);
TRN_API TRN_DigitalSignatureFieldIsCertification(const TRN_DigitalSignatureField* self, TRN_Bool* result);
TRN_API TRN_DigitalSignatureFieldGetSignerCertFromCMS(const TRN_DigitalSignatureField* self, TRN_X509Certificate* result);
TRN_API TRN_DigitalSignatureFieldGetByteRanges(const TRN_DigitalSignatureField* self, TRN_Vector* result);
TRN_API TRN_DigitalSignatureFieldGetCertPathsFromCMS(const TRN_DigitalSignatureField* self, TRN_Vector* result, TRN_UInt32 index);
TRN_API TRN_DigitalSignatureFieldGetCertPathsFromCMS_GetOutterVecSize(const TRN_DigitalSignatureField* self, TRN_UInt32* result);
TRN_API TRN_DigitalSignatureFieldEnableLTVOfflineVerification(const TRN_DigitalSignatureField* self, TRN_VerificationResult in_verification_result, TRN_Bool* result);
TRN_API TRN_DigitalSignatureFieldTimestampOnNextSave(const TRN_DigitalSignatureField* self, TRN_TimestampingConfiguration in_timestamping_config, TRN_VerificationOptions in_timestamp_response_verification_options);
TRN_API TRN_DigitalSignatureFieldGenerateContentsWithEmbeddedTimestamp(const TRN_DigitalSignatureField* self, TRN_TimestampingConfiguration in_timestamping_config, TRN_VerificationOptions in_timestamp_response_verification_options, TRN_TimestampingResult* result);
TRN_API TRN_DigitalSignatureFieldUseSubFilter(TRN_DigitalSignatureField* self, const enum TRN_DigitalSignatureField_SubFilterType in_subfilter_type, const TRN_Bool in_make_mandatory);
TRN_API TRN_DigitalSignatureFieldCalculateDigest(TRN_DigitalSignatureField* self, const enum TRN_DigestAlgorithm_Type in_digest_algorithm_type, TRN_Vector* result);
TRN_API TRN_DigitalSignatureFieldSetPreferredDigestAlgorithm(TRN_DigitalSignatureField* self, const enum TRN_DigestAlgorithm_Type in_digest_algorithm_type, const TRN_Bool in_make_mandatory);
TRN_API TRN_DigitalSignatureFieldCreateSigDictForCustomCertification(TRN_DigitalSignatureField* self, TRN_UString in_filter_name, const enum TRN_DigitalSignatureField_SubFilterType in_subfilter_type, const TRN_UInt32 in_contents_size_to_reserve);
TRN_API TRN_DigitalSignatureFieldCreateSigDictForCustomSigning(TRN_DigitalSignatureField* self, TRN_UString in_filter_name, const enum TRN_DigitalSignatureField_SubFilterType in_subfilter_type, const TRN_UInt32 in_contents_size_to_reserve);
TRN_API TRN_DigitalSignatureFieldSetSigDictTimeOfSigning(TRN_DigitalSignatureField* self, const TRN_Date* in_date);
TRN_API TRN_DigitalSignatureFieldSignDigestPath(const TRN_UChar* in_digest_buf, const size_t in_digest_buf_size, const TRN_UString in_pkcs12_keyfile_path, const TRN_UString in_keyfile_password, const TRN_Bool in_pades_mode, const enum TRN_DigestAlgorithm_Type in_digest_algorithm_type, TRN_Vector* result);
TRN_API TRN_DigitalSignatureFieldSignDigestBuffer(const TRN_UChar* in_digest_buf, const size_t in_digest_buf_size, const TRN_UChar* in_pkcs12_buffer, const size_t in_pkcs12_buffer_size, const TRN_UString in_keyfile_password, const TRN_Bool in_pades_mode, const enum TRN_DigestAlgorithm_Type in_digest_algorithm_type, TRN_Vector* result);
TRN_API TRN_DigitalSignatureFieldGenerateESSSigningCertPAdESAttribute(const TRN_X509Certificate in_signer_cert, const enum TRN_DigestAlgorithm_Type in_digest_algorithm_type, TRN_Vector* result);
TRN_API TRN_DigitalSignatureFieldGenerateCMSSignedAttributes(const TRN_UChar* in_digest_buf, const size_t in_digest_buf_size, const TRN_UChar* in_custom_signedattributes_buf, const size_t in_custom_signedattributes_buf_size, TRN_Vector* result);
TRN_API TRN_DigitalSignatureFieldGenerateCMSSignature(const TRN_X509Certificate in_signer_cert, const TRN_X509Certificate* in_chain_certs_list, const size_t in_chain_certs_list_size, const TRN_ObjectIdentifier in_digest_algorithm_oid, const TRN_ObjectIdentifier in_signature_algorithm_oid, const TRN_UChar* in_signature_value_buf, const size_t in_signature_value_buf_size, const TRN_UChar* in_signedattributes_buf, const size_t in_signedattributes_buf_size, TRN_Vector* result);
TRN_API TRN_DigitalSignatureFieldGenerateCMSSignatureWithAlgoId(const TRN_X509Certificate signer_cert, const TRN_X509Certificate* chain_certs_list, const size_t chain_certs_list_size, const TRN_AlgorithmIdentifier digest_algorithm_id, const TRN_AlgorithmIdentifier signature_algorithm_id, const TRN_UChar* signature_value_buf, const size_t signature_value_buf_size, const TRN_UChar* signedattributes_buf, const size_t signedattributes_buf_size, TRN_CMSSignatureOptions cms_options, TRN_Vector* result);
TRN_API TRN_DigitalSignatureFieldSetDigSigLogFilename(const TRN_UString filename, TRN_Bool* result);
#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CDigitalSignatureField */

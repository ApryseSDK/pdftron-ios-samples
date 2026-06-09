//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFVerificationOptions
#define PDFTRON_H_CPPPDFVerificationOptions
#include <C/PDF/TRN_VerificationOptions.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>
#include <Crypto/X509Certificate.h>

namespace pdftron { namespace PDF { 


/**
 * Options pertaining to digital signature verification.
 */
class VerificationOptions
{
public:
	//enums:

	// An enumeration representing the level of security to use when verifying digital signatures.
	enum SecurityLevel {
		// For compatibility with other vendors such as Acrobat, one can use e_compatibility_and_archiving.
		e_compatibility_and_archiving = 0,
		// The e_maximum mode is a highly-restrictive mode which disables many common features of PDF digital signatures.
		e_maximum = 1
	};

	/* An enumeration representing the least-secure type of reference-time to use when verifying digital signatures.
	One can choose the time of signing (not very secure), timestamp time (more secure), current time (most secure, lower verification rate).
	Note: this is orthogonal to the expiry verification mode (shell/chain/hybrid). */
	enum TimeMode {
		/* If secure timestamp available, check signature certificates against the secure timestamp. Otherwise,
		if available, check signature certificates against the signingTime attribute in the PKCS #7/CMS of the signature.
		Otherwise, use the current time. This is the default option. Less secure. Suitable for archiving
		and interoperability with other vendors. */
		e_signing = 0,
		/* If available, check signature certificates against the signingTime attribute in the PKCS #7/CMS data
		of the signature. Otherwise, use the current time. */
		e_timestamp = 1,
		/* Check signature certificates against the current time.
		This is the most secure, and the most restrictive option. */
		e_current = 2
	};

	// An enumeration representing the level of trust associated with a particular certificate. Multiple flag values can be combined using bitwise operators.
	enum CertificateTrustFlag {
		e_signing_trust = 1, // analogous to "kPSSigTrustSigning" in FDF cert exchange specification. Automatically set even when not specified, just like in Acrobat.
		e_certification_trust = 2, // analogous to "kPSSigTrustAuthenticDocuments" in FDF cert exchange specification. Allows certifications using this identity to be verified.
		e_dynamic_content = 4, /* analogous to "kPSSigTrustDynamicContent" in FDF cert exchange specification. Just like in Acrobat, does not invalidate dynamic documents,
			just intended to stop viewers from allowing its use on documents which are not trusted for it. */
		e_javascript = 16, /* analogous to "kPSSigTrustJavaScript" in FDF cert exchange specification. Just like in Acrobat, does not invalidate JavaScript-containing documents,
			just intended to stop viewers from allowing its use on documents which are not trusted for it. */
		e_identity = 32, // analogous to "kPSSigTrustIdentity" in FDF cert exchange specification. If this flag is not set, all other flags are ignored, and certificate is used only for path building.
		e_trust_anchor = 64, // analogous to "kPSSigTrustAnchor" in FDF cert exchange specification. If this flag is set, paths may end with this certificate, and no revocation checks are done for it.
		e_default_trust = 97, // handy shortcut for what Acrobat does by default -- trust for everything except certification, javascript, and dynamic
		e_complete_trust = 119 // another handy shortcut for testing
	};
	VerificationOptions(const VerificationOptions& other);
	VerificationOptions(TRN_VerificationOptions impl);
	VerificationOptions& operator= (const VerificationOptions& other);
	~VerificationOptions();
	
	void Destroy();

	//methods:
	
	/**
	 * Constructs a set of options for digital signature verification.
	 * 
	 * @param level -- the general security level to use. Sets other security settings internally.
	 */
	VerificationOptions(SecurityLevel level);

	/**
	 * Adds a certificate to the store of trusted certificates inside this options object.
	 *
	 * @param in_certificate_buf -- a buffer consisting of the data of an X.509 public-key
	 * certificate encoded in binary DER (Distinguished Encoding Rules) format, or in PEM
	 * (appropriate Privacy-Enhanced Mail header+Base64 encoded DER+appropriate footer) format
	 * @param in_buf_size -- buffer size
	 * @param in_trust_flags -- a combination of trust flags (see enum CertificateTrustFlag)
	 * that determine for which situations this certificate should be trusted during trust verification.
	 * There is a default parameter value, the e_default_trust CertificateTrustFlag, which matches Acrobat's behaviour for this parameter.
	*/
	void AddTrustedCertificate(const UChar* in_certificate_buf, size_t in_buf_size, const UInt16 in_trust_flags = e_default_trust);

	/**
	 * Adds a certificate to the store of trusted certificates inside this options object, by loading it from a file.
	 * 
	 * @param in_filepath -- a path to a file containing the data of an X.509 public-key certificate encoded in binary DER (Distinguished Encoding Rules) format, or in PEM (appropriate Privacy-Enhanced Mail header+Base64 encoded DER+appropriate footer) format.
	 * @param in_trust_flags -- a combination of trust flags (see enum CertificateTrustFlag)
	 * that determine for which situations this certificate should be trusted during trust verification.
	 * There is a default parameter value, the e_default_trust CertificateTrustFlag, which matches Acrobat's behaviour for this parameter.
	 */
	void AddTrustedCertificate(const UString& in_filepath, const UInt16 in_trust_flags = e_default_trust);

	/**
	 * Bulk trust list loading API from P7C. Attempts to decode the input data as binary DER and trust multiple trusted
	 * root certificates from it. Compatible with Acrobat's .P7C format, which is a variation on PKCS #7/CMS that only
	 * contains certificates (i.e. no CRLs, no signature, etc.). If a certificate cannot be decoded, this is ignored
	 * and an attempt is made to decode the next certificate. This overload takes no account of trust-level flags
	 * because none are available in the P7C format. Therefore, when this function is used, all certificates in the
	 * P7C file will be loaded as if trusted for everything, which may lead to false positives when compared to other PDF software.
	 * (Most applications use the FDF Cert Exchange format.) The FDF-trust-list-loading function "LoadTrustList" should be
	 * used instead whenever possible.
	 *
	 * @param in_P7C_binary_DER_certificates_file_data -- the P7C-format bulk certificate data, encoded in binary DER (Distinguished Encoding Rules)
	 * @param in_size -- the size of the data, in bytes
	 */
	void AddTrustedCertificates(const UChar* in_P7C_binary_DER_certificates_file_data, const size_t in_size);
	
	/**
	 * Bulk trust list loading API with trust flag support. Loads a trust list that is
	 * structured in Acrobat's FDF Data/Cert Exchange format into the VerificationOptions
	 * certificate store. Use of this function is strongly recommended instead of the P7C
	 * API (i.e. AddTrustedCertificates). Certificates inside the FDF trust list that
	 * cannot be decoded and loaded, will be skipped.
	 *
	 * @param in_fdf_cert_exchange_data -- an FDFDoc from the FDF cert exchange data
	 */
	void LoadTrustList(const FDF::FDFDoc& in_fdf_cert_exchange_data);

	/**
	 * Sets a flag that can turn on or off the verification of the permissibility of any modifications made to the document after the signing of the digital signature being verified, in terms of the document and field permissions specified by the digital signature being verified.
	 * 
	 * @param in_on_or_off -- A boolean.
	 */
	void EnableModificationVerification(bool in_on_or_off);
	
	/**
	 * Sets a flag that can turn on or off the verification of the digest (cryptographic hash) component of a digital signature.
	 * 
	 * @param in_on_or_off -- A boolean.
	 */
	void EnableDigestVerification(bool in_on_or_off);
	
	/**
	 * Sets a flag that can turn on or off the verification of the trust status of a digital signature.
	 * 
	 * @param in_on_or_off -- A boolean.
	 */
	void EnableTrustVerification(bool in_on_or_off);

	/**
	 * Sets the timeout for online revocation requests.
	 *
	 * @param in_revocation_timeout_milliseconds The timeout value in milliseconds.
	 */
	void SetRevocationTimeout(const UInt32 in_revocation_timeout_milliseconds);

	/**
	 * Enables/disables online CRL revocation checking. The default setting is 
	 * for it to be turned off, but this may change in future versions.
	 *
	 * @note CRL checking is off by default because the technology is inherently complicated
	 * and resource-intensive, but may help improve verification rate when files are verified against 
	 * a recent reference-time (e.g. maximum security mode), because online CRLs will be valid within 
	 * that time. This mode will not be useful for old archival-type ('LTV') documents
	 * verified in archiving-and-compatibility security mode, because their online OCSP and/or CRL
	 * responder servers may not be alive anymore. However, such LTV documents can be created
	 * (if the CRL responder servers are still active) by enabling online checking, verifying, and then
	 * embedding the data using DigitalSignatureField.EnableLTVOfflineVerification.
	 *
	 * @param in_on_or_off -- what setting to use
     */
	void EnableOnlineCRLRevocationChecking(bool in_on_or_off);
	
	/**
	 * Enables/disables online OCSP revocation checking. The default setting is for it to be turned on.
	 * 
	 * @param in_on_or_off -- what setting to use.
	 */
	void EnableOnlineOCSPRevocationChecking(bool in_on_or_off);
	

	/** 
	 * Enables/disables all online revocation checking modes. The default settings are that 
	 * online OCSP is turned on and online CRL is turned off, but the default CRL setting may change in
	 * future versions. 
	 * 
	 *  @note CRL checking is off by default because the technology is inherently complicated
	 * and resource-intensive, but may help improve verification rate when files are verified against
	 * a recent reference-time (e.g. maximum security mode), because online CRLs will be valid within
	 * that time. This mode will not be useful for old archival-type ('LTV') documents
	 * verified in archiving-and-compatibility security mode, because their online OCSP and/or CRL
	 * responder servers may not be alive anymore. However, such LTV documents can be created
	 * (if the CRL responder servers are still active) by enabling online checking, verifying, and then
	 * embedding the data using DigitalSignatureField.EnableLTVOfflineVerification.
	 *
	 * @param in_on_or_off -- what setting to use
  	 */
	void EnableOnlineRevocationChecking(bool in_on_or_off);
	

	/**
	 * Get the number of trusted certificates that have been added.
	 * 
	 * @return the number of trusted certificates.
	 */
	UInt32 GetTrustedCertificateCount();
	
	/**
	 * Get the certificate at a specific position in the current list of trusted certificates.
	 * 
	 * @param index -- the index of the certificate in the current list.
	 * @return the certificate at position index in the list.
	 */
	Crypto::X509Certificate GetTrustedCertificate(const UInt32 index);


#ifndef SWIGHIDDEN
	TRN_VerificationOptions m_impl;
#endif

private:

#ifndef SWIGHIDDEN
	mutable bool m_owner; 
#endif
};

#include <Impl/VerificationOptions.inl>
} //end pdftron
} //end PDF


#endif //PDFTRON_H_CPPPDFVerificationOptions

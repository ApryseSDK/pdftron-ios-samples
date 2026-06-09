//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFDigestAlgorithm
#define PDFTRON_H_CPPPDFDigestAlgorithm
#include <C/Crypto/TRN_DigestAlgorithm.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

namespace pdftron { namespace Crypto { 


class DigestAlgorithm
{
public:
	//enums:
	enum Type {
		e_SHA1 = 0,
		e_SHA256 = 1,
		e_SHA384 = 2,
		e_SHA512 = 3,
		e_RIPEMD160 = 4,
		e_unknown_digest_algorithm = 5
	};

	/**
	* Calculates a digest of arbitrary data. Useful during CMS generation custom signing workflows for digesting signedAttributes before
	* sending off for CMS signatureValue generation (e.g. by HSM device or cloud signing platform).
	* @param in_digest_algorithm_type -- the digest algorithm to use
	* @param in_message_buf -- the message to digest
	* @return a container of bytes corresponding to the digest of the message
	*/
	static std::vector<UChar> CalculateDigest(DigestAlgorithm::Type in_digest_algorithm_type, const std::vector<UChar>& in_message_buf);
	
	/**
	 * Sign the digest of arbitrary data with private key in the provided PKCS #12 key file (.pfx). This function is part of the low-level custom signing API, and works with GenerateESSSigningCertPAdESAttribute, GenerateCMSSignedAttributes, and GenerateCMSSignature.
	 *
	 * @param digest_buf -- The digest to sign.
	 * @param digest_algorithm_type -- The digest algorithm used to generate the digest.
	 * @param pkcs12_keyfile_path -- The path to the PKCS #12 keyfile (usually has a .pfx extension) to use for signing.
	 * @param pkcs12_password -- The password to use to parse the PKCS #12 keyfile.
	 * @return the DER-serialized bytes of the signature.
	 */
	static std::vector<UChar> SignDigest(const std::vector<UChar>& digest_buf, const DigestAlgorithm::Type digest_algorithm_type, const UString pkcs12_keyfile_path, const UString pkcs12_password);

	/**
	 * Sign the digest of arbitrary data with private key in the provided PKCS #12 key file (.pfx). This function is part of the low-level custom signing API, and works with GenerateESSSigningCertPAdESAttribute, GenerateCMSSignedAttributes, and GenerateCMSSignature.
	 *
	 * @param digest_buf -- The digest to sign.
	 * @param digest_algorithm_type -- The digest algorithm used to generate the digest.
	 * @param pkcs12_buf -- The buffer containing the PKCS #12 key (as usually stored in .pfx files) to use for signing.
	 * @param pkcs12_password -- The password to use to parse the PKCS 12 key.
	 * @return the DER-serialized bytes of the signature.
	 */
	static std::vector<UChar> SignDigest(const std::vector<UChar>& digest_buf, const DigestAlgorithm::Type digest_algorithm_type, const std::vector<UChar>& pkcs12_buf, const UString pkcs12_password);
#ifndef SWIG
	/**
	* Calculates a digest of arbitrary data. Useful during CMS generation custom signing workflows for digesting signedAttributes before
	* sending off for CMS signatureValue generation (e.g. by HSM device or cloud signing platform).
	* @param in_digest_algorithm_type -- the digest algorithm to use
	* @param in_message_buf -- the message to digest
	* @param in_message_buf_size -- the size of in_message_buf
	* @return a container of bytes corresponding to the digest of the message
	*/
	static std::vector<UChar> CalculateDigest(DigestAlgorithm::Type in_digest_algorithm_type, const UChar* in_message_buf, const size_t in_message_buf_size);
	
	/**
	 * Sign the digest of arbitrary data with private key in the provided PKCS #12 key file (.pfx). This function is part of the low-level custom signing API, and works with GenerateESSSigningCertPAdESAttribute, GenerateCMSSignedAttributes, and GenerateCMSSignature.
	 *
	 * @param digest_buf -- The digest to sign.
	 * @param digest_buf_size -- The size of the digest.
	 * @param digest_algorithm_type -- The digest algorithm used to generate the digest.
	 * @param pkcs12_keyfile_path -- The path to the PKCS #12 keyfile (usually has a .pfx extension) to use for signing.
	 * @param pkcs12_password -- The password to use to parse the PKCS #12 keyfile.
	 * @return the DER-serialized bytes of the signature.
	 */
	static std::vector<UChar> SignDigest(const UChar* digest_buf, const size_t digest_buf_size, const DigestAlgorithm::Type digest_algorithm_type, const UString pkcs12_keyfile_path, const UString pkcs12_password);

	/**
	 * Sign the digest of arbitrary data with private key in the provided PKCS #12 key file (.pfx). This function is part of the low-level custom signing API, and works with GenerateESSSigningCertPAdESAttribute, GenerateCMSSignedAttributes, and GenerateCMSSignature.
	 *
	 * @param digest_buf -- The digest to sign.
	 * @param digest_buf_size -- The size of the digest.
	 * @param digest_algorithm_type -- The digest algorithm used to generate the digest.
	 * @param pkcs12_buf -- The buffer containing the PKCS #12 key (as usually stored in .pfx files) to use for signing.
	 * @param pkcs12_buf_size -- The size of the buffer containing the PKCS #12 key.
	 * @param pkcs12_password -- The password to use to parse the PKCS 12 key.
	 * @return the DER-serialized bytes of the signature.
	 */
	static std::vector<UChar> SignDigest(const UChar* digest_buf, const size_t digest_buf_size, const DigestAlgorithm::Type digest_algorithm_type, const UChar* pkcs12_buf, const size_t pkcs12_buf_size, const UString pkcs12_password);
#endif
};

#include <Impl/DigestAlgorithm.inl>
} //end Crypto
} //end pdftron


#endif //PDFTRON_H_CPPPDFDigestAlgorithm

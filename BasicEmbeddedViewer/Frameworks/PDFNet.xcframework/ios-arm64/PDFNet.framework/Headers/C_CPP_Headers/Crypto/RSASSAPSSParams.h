//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPCryptoRSASSAPSSParams
#define PDFTRON_H_CPPCryptoRSASSAPSSParams

#include <Common/BasicTypes.h>
#include <Crypto/AlgorithmParams.h>
#include <Crypto/AlgorithmIdentifier.h>

namespace pdftron { namespace Crypto { 

/**
 * The parameters for RSASSA-PSS algorithm
 */
class RSASSAPSSParams : public AlgorithmParams
{
public:
	RSASSAPSSParams(const RSASSAPSSParams& other);
	RSASSAPSSParams(TRN_RSASSAPSSParams impl);
	RSASSAPSSParams& operator= (const RSASSAPSSParams& other);
	
	/**
	 * Initialize RSASSA-PSS parameters with default values specified in RFC 4055.
	 */
	RSASSAPSSParams();
	
	/**
	 * Initialize RSASSA-PSS parameters with MGF1 for a given digest algorithm and salt length.
	 * @param digest_algorithm_id The digest algorithm.
	 * @param salt_length The salt length.
	 */
	RSASSAPSSParams(const AlgorithmIdentifier& digest_algorithm_id, const UInt32 salt_length);

	/**
	 * Get the digest algorithm parameter value.
	 * @return The digest algorithm.
	 */
	AlgorithmIdentifier GetDigestAlgorithm() const;

	/**
	 * Set the digest algorithm parameter value.
	 * @param value The digest algorithm.
	 */
	void SetDigestAlgorithm(const AlgorithmIdentifier& value);

	/**
	 * Get the mask generation function parameter value.
	 * @return The mask generation function.
	 */
	AlgorithmIdentifier GetMaskGenAlgorithm() const;

	/**
	 * Set the mask generation function parameter value.
	 * @param value The mask generation function.
	 */
	void SetMaskGenAlgorithm(const AlgorithmIdentifier& value);

	/**
	 * Get the salt length parameter value.
	 * @return The salt length.
	 */
	UInt32 GetSaltLength() const;

	/**
	 * Set the salt length parameter value.
	 * @param value The salt length.
	 */
	void SetSaltLength(UInt32 value);

	/**
	 * Get the trailer field parameter value.
	 * @return The trailer field.
	 */
	UInt32 GetTrailerField() const;

	/**
	 * Set the trailer field parameter value.
	 * @param value The trailer field.
	 */
	void SetTrailerField(UInt32 value);
};

#include <Impl/RSASSAPSSParams.inl>
} //end pdftron
} //end Crypto


#endif //PDFTRON_H_CPPCryptoRSASSAPSSParams

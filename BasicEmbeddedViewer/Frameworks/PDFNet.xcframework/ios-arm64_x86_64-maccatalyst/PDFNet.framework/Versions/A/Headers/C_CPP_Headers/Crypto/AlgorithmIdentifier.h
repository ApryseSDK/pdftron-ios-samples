//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPCryptoAlgorithmIdentifier
#define PDFTRON_H_CPPCryptoAlgorithmIdentifier
#include <C/Crypto/TRN_AlgorithmIdentifier.h>

#include <Common/BasicTypes.h>
#include <Crypto/AlgorithmParams.h>

namespace pdftron { namespace Crypto { 


/**
 * This class represents an algorithm identifier, as defined by ITU and
 * used in X.509.
 */
class AlgorithmIdentifier
{
public:
	AlgorithmIdentifier(const AlgorithmIdentifier& other);
	AlgorithmIdentifier& operator= (const AlgorithmIdentifier& other);
	~AlgorithmIdentifier();
	
	/**
	 * Constructs an AlgorithmIdentifier from a Predefined enum.
	 *
	 * @param oid_type The Predefined enumerated value to use.
	 */
	AlgorithmIdentifier(const ObjectIdentifier::Predefined oid_type);
	
	/**
	 * Constructs an AlgorithmIdentifier from an ObjectIdentifier.
	 *
	 * @param oid The ObjectIdentifier object to use.
	 */
	AlgorithmIdentifier(const ObjectIdentifier& oid);
	
	/**
	 * Constructs an AlgorithmIdentifier from a DigestAlgorithm enum.
	 *
	 * @param digest_algorithm_type The enumeration value corresponding to your desired digest algorithm.
	 */
	AlgorithmIdentifier(const DigestAlgorithm::Type digest_algorithm_type);
	
	/**
	 * Constructs an AlgorithmIdentifier from a Predefined enum and an AlgorithmParams object.
	 *
	 * @param oid_type The Predefined enumerated value to use.
	 * @param params The AlgorithmParams object to use.
	 */
	AlgorithmIdentifier(const ObjectIdentifier::Predefined oid_type, const AlgorithmParams& params);
	
	/**
	 * Constructs an AlgorithmIdentifier from an ObjectIdentifier and an AlgorithmParams object.
	 *
	 * @param oid The ObjectIdentifier object to use.
	 * @param params The AlgorithmParams object to use.
	 */
	AlgorithmIdentifier(const ObjectIdentifier& oid, const AlgorithmParams& params);
	
	/**
	 * Constructs an AlgorithmIdentifier from a DigestAlgorithm enum and an AlgorithmParams object.
	 *
	 * @param digest_algorithm_type The enumeration value corresponding to your desired digest algorithm.
	 * @param params The AlgorithmParams object to use.
	 */
	AlgorithmIdentifier(const DigestAlgorithm::Type digest_algorithm_type, const AlgorithmParams& params);

#ifdef SWIG
	AlgorithmIdentifier();
#endif

#ifndef SWIGHIDDEN
	AlgorithmIdentifier(TRN_AlgorithmIdentifier impl);
	TRN_AlgorithmIdentifier m_impl;
#endif

private:

	void Destroy();

#ifndef SWIGHIDDEN
	mutable bool m_owner; 
#endif
};

#include <Impl/AlgorithmIdentifier.inl>
} //end pdftron
} //end Crypto


#endif //PDFTRON_H_CPPCryptoAlgorithmIdentifier

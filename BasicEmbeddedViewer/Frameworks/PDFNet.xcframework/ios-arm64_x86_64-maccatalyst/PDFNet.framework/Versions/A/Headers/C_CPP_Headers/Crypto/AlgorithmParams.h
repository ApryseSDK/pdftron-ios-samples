//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPCryptoAlgorithmParams
#define PDFTRON_H_CPPCryptoAlgorithmParams
#include <C/Crypto/TRN_AlgorithmParams.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

namespace pdftron { namespace Crypto { 


/**
 * Base class for AlgorithmIdentifier parameters.
 */
class AlgorithmParams
{
public:
	AlgorithmParams();
	AlgorithmParams(const AlgorithmParams& other);
	AlgorithmParams& operator= (const AlgorithmParams& other);
	virtual ~AlgorithmParams();


#ifndef SWIGHIDDEN
	AlgorithmParams(TRN_AlgorithmParams impl);
	TRN_AlgorithmParams m_impl;
#endif

protected:

	void Destroy();

#ifndef SWIGHIDDEN
	mutable bool m_owner;
#endif
};

#include <Impl/AlgorithmParams.inl>
} //end pdftron
} //end Crypto


#endif //PDFTRON_H_CPPCryptoAlgorithmParams

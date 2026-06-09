//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFTimestampingResult
#define PDFTRON_H_CPPPDFTimestampingResult
#include <C/PDF/TRN_TimestampingResult.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

namespace pdftron { namespace PDF { 

class EmbeddedTimestampVerificationResult;

/**
 * A class representing the result of testing a timestamping configuration.
 */
class TimestampingResult
{
public:

	TimestampingResult(const TimestampingResult& other);
	TimestampingResult& operator= (const TimestampingResult& other);
	~TimestampingResult();
	
	void Destroy();

	//methods:
	
	/**
	 * Retrieves the overall status of the timestamping configuration testing operation.
	 * 
	 * @return a boolean value representing the status.
	 */
	bool GetStatus() const;
	
	/**
	 * Retrieves a result message regarding the timestamping configuration testing operation.
	 * 
	 * @return a string result message. 
	 * @note Output may change in future versions.
	 */
	UString GetString() const;

	/**
	 * Returns whether a timestamp response verification result is available. This means
	 * that false will be returned when a timestamp response was not received or was empty
	 * (e.g. network failures, improper server configuration, bad URL, etc.). This function
	 * should be called to check for the availability of a verification result before actually
	 * attempting to retrieve one using GetResponseVerificationResult (which throws if a result is not
	 * available).
	 *
	 * @return whether a timestamp response verification result is available
	 */
	bool HasResponseVerificationResult() const;
	
	/**
	 * If a timestamp response was successfully retrieved from a timestamp authority, returns
	 * the result of verifying it. If a timestamp response was not received, throws. One should
	 * call HasResponseVerificationResult first to see if a detailed result is available before calling
	 * this function.
	 * 
	 * @return a timestamp response verification result
	 */
	EmbeddedTimestampVerificationResult GetResponseVerificationResult() const;

	/**
	 * If GetStatus gives true, returns the data from the completed timestamping operation, otherwise throws.
	 * If this result was returned from TimestampOnNextSave, then this data is the timestamp token.
	 * However, if this result was returned from GenerateContentsWithEmbeddedTimestamp, then this data is the main
	 * document CMS signature of the DigitalSignatureField but with a newly-added embedded
	 * timestamp (unsigned signature-time-stamp attribute as specified in PAdES and PDF 2.0).
	 *
	 * @return the data representing the result of the timestamping operation, if GetStatus gives true
	*/
	std::vector<UChar> GetData() const;

#ifdef SWIG
	TimestampingResult();
#endif

#ifndef SWIGHIDDEN
	TimestampingResult(TRN_TimestampingResult impl);
	TRN_TimestampingResult m_impl;
#endif

};

#include <Impl/TimestampingResult.inl>
} //end pdftron
} //end PDF


#endif //PDFTRON_H_CPPPDFTimestampingResult

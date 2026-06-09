//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFCMSSignatureOptions
#define PDFTRON_H_CPPPDFCMSSignatureOptions
#include <C/PDF/TRN_CMSSignatureOptions.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

namespace pdftron { namespace PDF { 

/**
 * Optional data for CMS creation.
 */
class CMSSignatureOptions
{
public:
	CMSSignatureOptions();
	CMSSignatureOptions(const CMSSignatureOptions& other);
	CMSSignatureOptions& operator= (const CMSSignatureOptions& other);
	~CMSSignatureOptions();

	/**
	 * Add a timestamp token to the CMS.
	 *
	 * @param token_buf The timestamp token.
	 */
	void AddTimestampToken(const std::vector<UChar>& token_buf);

#ifndef SWIG
	/**
	 * Add a timestamp token to the CMS.
	 * 
	 * @param token_buf The timestamp token.
	 * @param token_buf_size The size of the timestamp token buffer.
	 */
	void AddTimestampToken(const UChar* token_buf, const size_t token_buf_size);
#endif

#ifndef SWIGHIDDEN
	CMSSignatureOptions(TRN_CMSSignatureOptions impl);
	TRN_CMSSignatureOptions m_impl;
#endif

protected:

	void Destroy();

#ifndef SWIGHIDDEN
	mutable bool m_owner;
#endif
};

#include <Impl/CMSSignatureOptions.inl>
} //end pdftron
} //end PDF


#endif //PDFTRON_H_CPPPDFCMSSignatureOptions

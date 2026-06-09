//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CPPPDFContentEdit
#define PDFTRON_H_CPPPDFContentEdit
#include <C/PDF/TRN_ContentEdit.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

namespace pdftron { namespace PDF { 


/* doxygen ignore - this is not a public interface
 * The class ContentEdit.
 * static interface to Iceni Content Edit functionality
 */
class ContentEdit
{
public:

	/* Doxygen ignore - this is not a public interface
	 * Begin a PDF content editing session. Does not support concurrency.
	 * Only 1 PDF can be edited at a time.
	 *
	 * @param input_pdf The PDF to be edited.
	 */
	static void Begin(PDFDoc& input_pdf);

	/* doxygen ignore - this is not a public interface
	 * Runs the command XML
	 *
	 * @param commands_xml The command XML.
	 * @return results XML.
	 */
	static UString RunXML(const UString& commands_xml);

	/* doxygen ignore - this is not a public interface
	 * Ends the content editing session and finalizes changes.
	 */
	static void End();
};

#include <Impl/ContentEdit.inl>
} //end pdftron
} //end PDF


#endif //PDFTRON_H_CPPPDFContentEdit

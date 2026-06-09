#ifndef PDFTRON_H_CPPFlowDocument
#define PDFTRON_H_CPPFlowDocument
#include <C/Layout/TRN_FlowDocument.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

#include "ContentTree.h"

namespace pdftron {
	namespace Layout {
		/**
		 * The class FlowDocument.
		 * Encapsulates document creation API.
		 */
		class FlowDocument
		{
			void Destroy();
		public:
			/**
			 * A constructor. Creates an empty document.
			 */
			FlowDocument();

			/**
			 * Destroy the FlowDocument object
			 */
			~FlowDocument();

			/**
			 * Adds a paragraph to the document.
			 *
			 * @return The paragraph object
			 */
			Paragraph AddParagraph();

			/**
			 * Adds a paragraph to the document and sets the text.
			 *
			 * @return The paragraph object
			 */
			Paragraph AddParagraph(const UString& text);

			/**
			 * Adds a list to the document.
			 *
			 * @return The list object
			 */
			List AddList();

			/**
			 * Adds a table to the document.
			 *
			 * @return The table object
			 */
			Table AddTable();

			/**
			 * Set the default margins for the document.
			 *
			 * @param left The left margin in points
			 * @param top The top margin in points
			 * @param right The right margin in points
			 * @param bottom The bottom margin in points
			 */
			void SetDefaultMargins(double left, double top, double right, double bottom);

			/**
			 * Set the default page size for the document.
			 *
			 * @param width The width in points
			 * @param height The height in points
			 */
			void SetDefaultPageSize(double width, double height);

			/**
			 * Gets the body of the document.
			 *
			 * <p>The body is the root of the content tree. It can be used to traverse
			 * the content tree via the ContentNodeIterator object.</p>
			 *
			 * @return The body of the document
			 */
			ContentNode GetBody() const;

			/**
			 * Paginates the content tree into a PDFDoc object.
			 *
			 * @return The PDFDoc object
			 */
			PDF::PDFDoc PaginateToPDF();

#ifndef SWIGHIDDEN
			TRN_FlowDocument m_impl;
#endif
		};

#include <Impl/FlowDocument.inl>
} //end pdftron
} //end PDF

#endif // PDFTRON_H_CPPFlowDocument

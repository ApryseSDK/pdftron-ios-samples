//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFViewerOptimizedOptions
#define PDFTRON_H_CPPPDFViewerOptimizedOptions

#include <C/PDF/TRN_Convert.h>
#include <SDF/Obj.h>
#include <SDF/ObjSet.h>
#include <Common/Common.h>
#include <PDF/PDFRasterizer.h>
#include <Common/BasicTypes.h>

namespace pdftron { 
	namespace PDF {

class ViewerOptimizedOptions
{
public:

	ViewerOptimizedOptions();

	/**
	 * For any pages that are not forced to include thumbnails this
	 * function adjusts whether we should include them depending on the
	 * complexity of the page. This can be used to include fewer or more thumbnails
	 * as required by the use case. In particular reducing this value
	 * will tend to increase the number of page thumbnails included and vice versa.
	 *
	 * @param threshold A number from 0 (include all thumbnails) to 100
	 * (include only the first thumbnail) representing the complexity at which
	 * SaveViewerOptimized would include the thumbnail. The default value is 50.
	 */
	void SetThumbnailRenderingThreshold(UInt32 threshold);

	/**
	* Set the number of pages starting from the first for which to guarantee thumbnails regardless of page complexity. 
	* This can help improve the viewing experience on the first few pages without increasing the file size dramatically. 
	* If this number is greater than the number of pages in the document all of the pages will have thumbnails. 
	*
	* @param initial_thumbs The number of pages starting with the first which are guaranteed to have thumbnails. The default value is 1,
	* which means only the first page is guaranteed to have a thumbnail.
	*/
	void SetMinimumInitialThumbnails(UInt32 initial_thumbs);

	/**
	 * The maximum allowed length for the thumbnail's height/width.
	 * The default thumbnail size is 1024.
	 * @param size the maximum dimension (width or height) that thumbnails will have.
	 */
	void SetThumbnailSize(UInt32 size);

	/**
	* Enable or disable support for overprint and overprint simulation in generated thumbnails.
	* Overprint is a device dependent feature and the results will vary depending on
	* the output color space and supported colorants (i.e. CMYK, CMYK+spot, RGB, etc).
	* Default is e_op_pdfx_on.
	*
	* @param mode e_op_on: always enabled; e_op_off: always disabled; e_op_pdfx_on: enabled for PDF/X files only.
	*/
	void SetOverprint(PDFRasterizer::OverprintPreviewMode mode);

// @cond PRIVATE_DOC
#ifndef SWIGHIDDEN
	TRN_Obj m_obj;
	SDF::ObjSet m_objset;
#endif
// @endcond
};

#include <Impl/ViewerOptimizedOptions.inl>

	};	// namespace PDF
};	// namespace pdftron

#endif

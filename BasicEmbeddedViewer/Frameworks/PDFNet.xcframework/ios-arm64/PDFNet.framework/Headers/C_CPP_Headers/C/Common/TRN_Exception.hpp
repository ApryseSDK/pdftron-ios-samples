#ifndef CEXCEPTION_HPP
#define CEXCEPTION_HPP

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_API_Config.hpp>

// All C++ standard library and internal header files must be inside these guards.
// C standard header files (e.g. stdio.h) are recommended to be outside of these guards.
#if TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES
#pragma GCC visibility push(hidden)
#endif // TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES

#include <Common/Exception.h>
#include <Common/UString.h>
#include <APIDataCollect/APIDataCollector.h>
#include <PDF/Utility/APIDataCollectionUtility.hpp>
#include <SDF/License.hpp>

#ifndef trn
using namespace trn;
#endif

TRN_Exception GetPDFNetException(Common::Exception& ex);
TRN_Exception GetException(std::string& ex);

#if TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES
#pragma GCC visibility pop
#endif // TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES

#define GSCast(state) ((PDF::GState*)state)
#define EleCast(element) ((PDF::Element*)element)
#define ObjCast(obj)	((SDF::Obj*)obj)

#define PDFDocCast(doc)    (*((PDFDoc*)(&doc)))

//heap casts
#define DocCast(doc) (*((SDF::SDFDoc*)doc))
#define ABSCast(abs) (*((PDF::Annot::BorderStyle*)abs))
#define FuncCast(func) (*((PDF::Function*)func))
#define CSCast(cs) (*((PDF::ColorSpace*)cs))
#define FontCast(font) (*((PDF::Font*)font))
#define ERCast(reader) (*((PDF::ElementReader*)reader))
#define EWCast(writer) (*((PDF::ElementWriter*)writer))
#define EBCast(builder) (*((PDF::ElementBuilder*)builder))
#define ShadeCast(shade) (*((PDF::Shading*)shade))
#define FilterCast(filter) (*((Filters::Filter*)filter))
#define FRCast(reader) (*((Filters::FilterReader*)reader))
#define FWCast(writer) (*((Filters::FilterWriter*)writer))
#define PCCast(pattern_color) (*((PDF::PatternColor*)pattern_color))
#define RastCast(rasterizer) (*((PDF::PDFRasterizer*)rasterizer))
#define DrawCast(pdfdraw) (*((PDF::PDFDraw*)pdfdraw))
#define ViewCast(pdfview) (*((PDF::PDFView*)pdfview))
#define ViewCCast(pdfviewctrl) (*((PDF::PDFViewCtrl*)pdfviewctrl))
#define TECast(extractor) (*((PDF::TextExtractor*)extractor))
#define OSetCast(set) (*((SDF::ObjSet*)set))
#define PDFACCast(pdfa) (*((PDFA::PDFACompliance*)pdfa))
#define HLCast(hlt) (*((PDF::Highlights*)hlt))
#define TRCast(tr) (*((PDF::TextRange*)tr))
#define TSCast(ts) (*((PDF::TextSearch*)ts))
#define ContRepCast(cr) (*((PDF::ContentReplacer*)cr))

//direct casts
#define FieldCast(field) (*((PDF::Field*)field))
#define DigSigFieldCast(dsfieldptr) (*((PDF::DigitalSignatureField*)dsfieldptr))
#define DateCast(date) (*((PDF::Date*)date))
#define CPCast(cp) (*((PDF::ColorPt*)cp))
#define RectCast(rect) (*((PDF::Rect*)rect))
#define CICast(item) (*((PDF::Struct::ContentItem*)item))
#define SEleCast(element) (*((PDF::Struct::SElement*)element))
#define M2DCast(matrix) (*((Common::Matrix2D*)matrix))
#define PLblCast(label) (*((PDF::PageLabel*)label))
#define FFieldCast(field) (*((FDF::FDFField*)field))
#define VSCast(pdfviewselection) (*((PDF::PDFView::Selection*)pdfviewselection))
#define TESCast(style) (*((PDF::TextExtractor::Style*)style))
#define TEWCast(word) (*((PDF::TextExtractor::Word*)word))
#define TELCast(line) (*((PDF::TextExtractor::Line*)line))
#define PointCast(point) (*((PDF::Point*)point))
#define QPCast(qp) (*((PDF::QuadPoint*)qp))


//shared impl casts
#define FSCast(fs) ((SDF::Obj*)fs)
#define ActCast(act) ((SDF::Obj*)act)
#define PageCast(page) ((SDF::Obj*)page)
#define AnnCast(annot) ((SDF::Obj*)annot)
#define UStrCast(ustr) ((void*)ustr)
#define DestCast(dest) ((SDF::Obj*)dest)
#define PDFDcCast(pdfdc) ((PDF::PDFDC*)(pdfdc))
#define PDFDCEXCast(pdfdcex) ((PDF::PDFDCEX*)(pdfdcex))
#define PDocCast(pdoc) ((SDF::SDFDoc*)(pdoc))
#define RefCountedDocCast(pdoc) ((SDF::SDFDoc*)(pdoc))->GetSharedReference()
#define PDInfoCast(pdinfo) ((SDF::Obj*)(pdinfo))
#define PDFPrefCast(pdfpref) ((SDF::Obj*)(pdfpref))
#define BMCast(bm) ((SDF::Obj*)bm)
#define STreeCast(tree) ((SDF::Obj*)tree)
#define RMapCast(map) ((SDF::Obj*)map)
#define CMapCast(map) ((SDF::Obj*)map)
#define ImgCast(img) ((SDF::Obj*)img)
#define FDocCast(fdoc) ((SDF::SDFDoc*)fdoc)
#define RetUStr(str) { UString res(str); *result=(TRN_UString)res.mp_impl; res.mp_impl=0; }
// Copies a UString implementation (basic_string<Unicode>) and returns the pointer (to be managed by caller). Used by codegen.
TRN_UString ExtractTRNUStringCodegen(const trn::UString& in_ustring);

//return casts for direct cast objects
#define RetM2D(matrix) (*((TRN_Matrix2D*)&matrix))
#define RetField(field) (*((TRN_Field*)&field))
#define RetCI(item) (*((TRN_ContentItem*)&item))
#define RetSEle(element) (*((TRN_SElement*)&element))
#define RetPLbl(label) (*((TRN_PageLabel*)&label))
#define RetFField(field) (*((TRN_FDFField*)&field))

#define EBEX 	catch(Common::Exception& e1) \
	{ \
		return GetPDFNetException(e1); \
	} \
	catch(std::exception& e2) \
	{ \
		std::string t(e2.what()); \
		return GetException(t); \
	} \
	catch(...) \
	{ \
		std::string t("An Unknown Exception Occurred\n"); \
		return GetException(t); \
	} \
	return 0;


#define VERIFY_FUNCTION_PACKAGE static const License::Packages package_permission = License::GetPackagePermission(__FUNCTION__ + 4); \
if (package_permission.IsNotNone()) \
{ \
	PDF::APIDataCollector::ThrowIfServerError(); \
	License::Instance().VerifyPermission(package_permission); \
}

// Use this macro if SetFormat in AdditionalAPIData class is used.
// Inside SetFormat function, License::Instance().VerifyPermission is invoked to check package permission.
// Verify Package Permission indirectly.
#define API_VAR_WPPI try{ \
PDF::APIDataCollector::ThrowIfServerError(); \
PDF::AdditionalAPIData api_data_local; \
api_data_local.SetAPIName(__FUNCTION__ + 4); \
PDF::AdditionalAPIData* api_data = &api_data_local;

// Use this macro if SetFormat in AdditionalAPIData class is not used.
// Verify Package Permission directly.
#define API_VAR_WPPD try{ \
VERIFY_FUNCTION_PACKAGE \
PDF::AdditionalAPIData api_data_local; \
PDF::AdditionalAPIData* api_data = &api_data_local;

// For initialize specifically since we should never call ThrowIfServerError there
#define INITIALIZE_BEX try{ 


#ifdef TRN_HAS_PWS

// For functions either don't have License::Instance() initialized properly yet,
// or are called many times without charges such as UString member functions.
// WOP_ : Without Package Permission checking
#define WOP_BEX try{

#define BEX try{ \
VERIFY_FUNCTION_PACKAGE

int TRN_GetPageCountFromDoc(TRN_PDFDoc doc);

// Macro that assumes we have a TRN_PDFDoc named doc.
// It will create an initial_pages int based on the initial number of pages in doc.
// Used in concert with DOC_INITIAL_PAGES_EEX
#define DOC_INITIAL_PAGES_BEX(doc) BEX int initial_pages = TRN_GetPageCountFromDoc(doc);

// Macro that assumes we have a TRN_PDFDoc named doc.
// It will create an initial_pages int based on the initial number of pages in doc.
// Used in concert with DOC_INITIAL_PAGES_EEX
// Verify Package Permission indirectly.
#define DOC_INITIAL_PAGES_WPPI_BEX(doc) API_VAR_WPPI int initial_pages = TRN_GetPageCountFromDoc(doc);

// Macro that creates a local api_data pointer when we need it
// This is to use in concert with API_VAR_EEX
// Use this macro if SetFormat in AdditionalAPIData class is used.
// Inside SetFormat function, License::Instance().VerifyPermission is invoked to check package permission.
// _WPPI_ means With Package Permission checking indirectly.
#define API_VAR_WPPI_BEX API_VAR_WPPI


// Macro that creates a local api_data pointer when we need it
// This is to use in concert with API_VAR_EEX
// Use this macro if SetFormat in AdditionalAPIData class is not used.
// Check package permission immediately.
#define API_VAR_BEX API_VAR_WPPD

#define EEX_NO_COLLECT } \
	EBEX


#define EEX if(License::ShouldCollectData()) { \
			PDF::APIDataCollector* adc_p = PDF::APIDataCollector::GetInstance(); 	adc_p->AddCall(__FUNCTION__ + 4); \
		} \
	} \
	EBEX

// Macro that assumes we already have a AdditionalAPIData* named api_data
// This is done automatically by API_VAR_BEX and this is the typical approach.
#define API_VAR_EEX if(License::ShouldCollectData()) { \
			PDF::APIDataCollector* adc_p = PDF::APIDataCollector::GetInstance(); 	adc_p->AddCall(__FUNCTION__ + 4, api_data); \
		} \
	} \
	EBEX

// Macro that takes an expression to create an AdditionalAPIData named api_data
#define API_EXPRESSION_EEX(get_data_expr) if(License::ShouldCollectData()) { \
			get_data_expr; \
			PDF::APIDataCollector* adc_p = PDF::APIDataCollector::GetInstance(); 	adc_p->AddCall(__FUNCTION__ + 4, &api_data);\
		} \
	} \
	EBEX

// Macro that assumes we already have an int named initial_pages and a TRN_PDFDoc named doc.
// initial_pages is created automatically by DOC_INITIAL_PAGES_BEX and this is the typical approach.
// Will record the number of pages added in the output.
#define DOC_INITIAL_PAGES_EEX(doc) API_EXPRESSION_EEX(PDF::AdditionalAPIData api_data; api_data.m_pages_in = api_data.m_pages_out = TRN_GetPageCountFromDoc(doc) - initial_pages)

// Macro that will record the number of pages in the provided doc.
#define DOC_PAGES_EEX(doc) int initial_pages = 0; DOC_INITIAL_PAGES_EEX(doc)

// Macro that takes the number of pages to record and does so
#define NUM_PAGES_EEX(num) API_EXPRESSION_EEX(PDF::AdditionalAPIData api_data; api_data.m_pages_in = api_data.m_pages_out = (num))

#else
// For functions either don't have License::Instance() initialized properly yet,
// or are called many times without charges such as UString member functions.
// WOP_ : Without Package Permission checking
#define WOP_BEX try{

#define BEX try{ \
VERIFY_FUNCTION_PACKAGE

// Macro that assumes we have a TRN_PDFDoc named doc.
// It will create an initial_pages int based on the initial number of pages in doc.
// Used in concert with DOC_INITIAL_PAGES_EEX
#define DOC_INITIAL_PAGES_BEX(doc) BEX

// Macro that assumes we have a TRN_PDFDoc named doc.
// It will create an initial_pages int based on the initial number of pages in doc.
// Used in concert with DOC_INITIAL_PAGES_EEX
// Verify Package Permission indirectly.
#define DOC_INITIAL_PAGES_WPPI_BEX(doc) API_VAR_WPPI

// Macro that creates a local api_data pointer when we need it
// This is to use in concert with API_VAR_EEX
// Use this macro if SetFormat in AdditionalAPIData class is used.
// Inside SetFormat function, License::Instance().VerifyPermission is invoked to check package permission.
// _WPPI_ means With Package Permission checking indirectly.
#define API_VAR_WPPI_BEX API_VAR_WPPI

// Macro that creates a local api_data pointer when we need it
// This is to use in concert with API_VAR_EEX
// Use this macro if SetFormat in AdditionalAPIData class is not used.
// Check package permission immediately/directly.
#define API_VAR_BEX API_VAR_WPPD

#define EEX_NO_COLLECT } \
	EBEX

#define EEX } \
	catch(Common::Exception& e1) \
	{ \
		return GetPDFNetException(e1); \
	} \
	catch(std::exception& e2) \
	{ \
		std::string t(e2.what()); \
		return GetException(t); \
	} \
	catch(...) \
	{ \
		std::string t("An Unknown Exception Occurred\n"); \
		return GetException(t); \
	} \
	return 0;


// Macro that assumes we already have a AdditionalAPIData* named api_data
// This is done automatically by API_VAR_BEX and this is the typical approach.
#define API_VAR_EEX EEX

// Macro that takes an expression to create an AdditionalAPIData named api_data
#define API_EXPRESSION_EEX(get_data_expr) EEX

// Macro that assumes we already have an int named initial_pages and a TRN_PDFDoc named doc.
// initial_pages is created automatically by DOC_INITIAL_PAGES_BEX and this is the typical approach.
// Will record the number of pages added in the output.
#define DOC_INITIAL_PAGES_EEX(doc) EEX

// Macro that will record the number of pages in the provided doc.
#define DOC_PAGES_EEX(doc) EEX

// Macro that takes the number of pages to record and does so
#define NUM_PAGES_EEX(num) EEX


#endif


#endif /* CEXCEPTION_HPP */

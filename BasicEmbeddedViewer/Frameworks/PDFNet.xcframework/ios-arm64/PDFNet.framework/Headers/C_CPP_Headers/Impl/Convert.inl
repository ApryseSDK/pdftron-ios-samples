#include <Impl/Utils.inl>
void SetFlattenContentImpl(TRN_Obj obj, enum Convert::FlattenFlag flatten, TRN_Obj* result);
void SetFlattenThresholdImpl(TRN_Obj obj, enum Convert::FlattenThresholdFlag threshold, TRN_Obj* result);

inline void Convert::FromXps(PDFDoc & in_pdfdoc, const UString & in_filename)
{
	REX(TRN_ConvertFromXps(in_pdfdoc.mp_doc, in_filename.mp_impl));
}

inline void Convert::FromXps(PDFDoc & in_pdfdoc, const char* buf, size_t buf_sz)
{
	REX(TRN_ConvertFromXpsMem(in_pdfdoc.mp_doc, buf, buf_sz));
}

inline void Convert::FromEmf(PDFDoc & in_pdfdoc, const UString & in_filename)
{
	REX(TRN_ConvertFromEmf(in_pdfdoc.mp_doc, in_filename.mp_impl));
}

inline void Convert::FromText(PDFDoc& in_pdfdoc, const UString& in_filename, const SDF::Obj& options)
{
	REX(TRN_ConvertFromText(in_pdfdoc.mp_doc, in_filename.mp_impl, options.mp_obj));
}

inline void Convert::ToEmf(PDFDoc & in_pdfdoc, const UString & in_filename)
{
	REX(TRN_ConvertDocToEmf(in_pdfdoc.mp_doc, in_filename.mp_impl));
}

inline void Convert::ToEmf(Page & in_page, const UString & in_filename)
{
	REX(TRN_ConvertPageToEmf(in_page.mp_page, in_filename.mp_impl));
}

inline SVGOutputOptions::SVGOutputOptions()
{
	m_obj = m_objset.CreateDict().mp_obj;
}

inline void SVGOutputOptions::SetEmbedImages(bool embed_images)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "EMBEDIMAGES", BToTB(embed_images), &result));
}

inline void SVGOutputOptions::SetNoFonts(bool no_fonts)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "NOFONTS", BToTB(no_fonts), &result));
}

inline void SVGOutputOptions::SetSvgFonts(bool svg_fonts)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "SVGFONTS", BToTB(svg_fonts), &result));
}

inline void SVGOutputOptions::SetEmbedFonts(bool embed_fonts)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "EMBEDFONTS", BToTB(embed_fonts), &result));
}

inline void SVGOutputOptions::SetFlattenContent(enum Convert::FlattenFlag flatten)
{
	TRN_Obj result;
	SetFlattenContentImpl(m_obj, flatten, &result);
}

inline void SVGOutputOptions::SetFlattenThreshold(enum Convert::FlattenThresholdFlag threshold)
{
	TRN_Obj result;
	SetFlattenThresholdImpl(m_obj, threshold, &result);
}

inline void SVGOutputOptions::SetFlattenDPI(UInt32 dpi)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "DPI", dpi, &result));
}

inline void SVGOutputOptions::SetFlattenMaximumImagePixels(UInt32 max_pixels)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "MAX_IMAGE_PIXELS", max_pixels, &result));
}

inline void SVGOutputOptions::SetCompress(bool svgz)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "SVGZ", BToTB(svgz), &result));
}

inline void SVGOutputOptions::SetOutputThumbnails(bool include_thumbs)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"NOTHUMBS",BToTB(!include_thumbs),&result));
}

inline void SVGOutputOptions::SetThumbnailSize(UInt32 size)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"THUMB_SIZE",size,&result));
}

inline void SVGOutputOptions::SetCreateXmlWrapper(bool xml)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "NOXMLDOC", BToTB(!xml), &result));
}

inline void SVGOutputOptions::SetDtd(bool dtd)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "OMITDTD", BToTB(!dtd), &result));
}

inline void SVGOutputOptions::SetAnnots(bool annots)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "NOANNOTS", BToTB(!annots), &result));
}

inline void SVGOutputOptions::SetNoUnicode(bool no_unicode)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "NOUNICODE", BToTB(no_unicode), &result));
}

inline void SVGOutputOptions::SetIndividualCharPlacement(bool individual_char_placement)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "INDIVIDUALCHARPLACEMENT", BToTB(individual_char_placement), &result));
}

inline void SVGOutputOptions::SetRemoveCharPlacement(bool remove_char_placement)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "REMOVECHARPLACEMENT", BToTB(remove_char_placement), &result));
}

inline void SVGOutputOptions::SetOverprint(PDFRasterizer::OverprintPreviewMode mode)
{
	TRN_Obj result;
	SetOverprintImpl(m_obj, mode, &result);
}

inline void Convert::ToSvg(PDFDoc & in_pdfdoc, const UString & in_filename)
{
	SVGOutputOptions in_options;
	Convert::ToSvg(in_pdfdoc, in_filename, in_options);
}

inline void Convert::ToSvg(PDFDoc & in_pdfdoc, const UString & in_filename, const SVGOutputOptions& in_options)
{
	REX(TRN_ConvertDocToSvgWithOptions(in_pdfdoc.mp_doc, in_filename.mp_impl, in_options.m_obj));
}

inline void Convert::ToSvg(Page & in_page, const UString & in_filename)
{
	SVGOutputOptions in_options;
	Convert::ToSvg(in_page, in_filename, in_options);
}

inline void Convert::ToSvg(Page & in_page, const UString & in_filename, const SVGOutputOptions& in_options)
{
	REX(TRN_ConvertPageToSvgWithOptions(in_page.mp_page, in_filename.mp_impl, in_options.m_obj));
}

inline XPSOutputCommonOptions::XPSOutputCommonOptions()
{
	m_obj=m_objset.CreateDict().mp_obj;
}

inline void XPSOutputCommonOptions::SetPrintMode(bool print_mode)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"PRINTMODE",BToTB(print_mode),&result));
}

inline void XPSOutputCommonOptions::SetDPI(UInt32 dpi)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"DPI",dpi,&result));
}

inline void XPSOutputCommonOptions::SetRenderPages(bool render)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"RENDER",BToTB(render),&result));
}

inline void XPSOutputCommonOptions::SetThickenLines(bool thicken)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"THICKENLINES",BToTB(thicken),&result));
}

inline void XPSOutputCommonOptions::GenerateURLLinks(bool generate)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"URL_LINKS",BToTB(generate),&result));
}

inline void XPSOutputCommonOptions::SetOverprint(enum OverprintPreviewMode mode)
{
	TRN_Obj result;
	SetOverprintImpl(m_obj, static_cast<PDFRasterizer::OverprintPreviewMode>(mode), &result);
}

inline void XPSOutputOptions::SetOpenXps(bool openxps)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"OPENXPS",BToTB(openxps),&result));
}

inline void XODOutputOptions::SetExtractUsingZorder(bool use_zorder)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"USEZORDER",BToTB(use_zorder),&result));
}

inline void XODOutputOptions::SetOutputThumbnails(bool include_thumbs)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"NOTHUMBS",BToTB(!include_thumbs),&result));
}

inline void XODOutputOptions::SetThumbnailSize(UInt32 size)
{
	SetThumbnailSize(size,size);
}

inline void XODOutputOptions::SetThumbnailSize(UInt32 regular_size, UInt32 large_size)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"THUMB_SIZE",regular_size,&result));
	REX(TRN_ObjPutNumber(m_obj,"LARGE_THUMB_SIZE",large_size,&result));

}

inline void XODOutputOptions::SetElementLimit(UInt32 element_limit)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"ELEMENTLIMIT",element_limit,&result));
}

inline void XODOutputOptions::SetOpacityMaskWorkaround(bool opacity_render)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"MASKRENDER",opacity_render,&result));
}

inline void XODOutputOptions::SetMaximumImagePixels(UInt32 max_pixels)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"MAX_IMAGE_PIXELS",max_pixels,&result));
}

inline void XODOutputOptions::SetFlattenContent(enum Convert::FlattenFlag flatten)
{
	TRN_Obj result;
	SetFlattenContentImpl(m_obj, flatten, &result);
}

inline void XODOutputOptions::SetFlattenThreshold(enum Convert::FlattenThresholdFlag threshold)
{
	TRN_Obj result;
	SetFlattenThresholdImpl(m_obj, threshold, &result);
}

inline void XODOutputOptions::SetPreferJPG(bool prefer_jpg)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"PREFER_JPEG",prefer_jpg,&result));
}

inline void XODOutputOptions::SetJPGQuality(UInt32 quality)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"JPEG_QUALITY",quality,&result));
}

inline void XODOutputOptions::SetSilverlightTextWorkaround(bool workaround)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"REMOVE_ROTATED_TEXT",workaround,&result));
}

inline void XODOutputOptions::SetAnnotationOutput(enum AnnotationOutputFlag annot_output)
{
	TRN_Obj result;
	switch (annot_output)
	{
		case e_internal_xfdf:
			REX(TRN_ObjPutName(m_obj, "ANNOTATION_OUTPUT", "INTERNAL", &result));
			break;
		case e_external_xfdf:
			REX(TRN_ObjPutName(m_obj, "ANNOTATION_OUTPUT", "EXTERNAL", &result));
			break;
		case e_flatten:
			REX(TRN_ObjPutName(m_obj, "ANNOTATION_OUTPUT", "FLATTEN", &result));
			break;
	}
}

inline void XODOutputOptions::SetExternalParts(bool generate)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "EXTERNAL_PARTS", generate, &result));
}

inline void XODOutputOptions::SetEncryptPassword(const char* pass)
{
	TRN_Obj result;
	REX(TRN_ObjPutName(m_obj, "ENCRYPT_PASSWORD", pass, &result));
}

inline void XODOutputOptions::UseSilverlightFlashCompatible(bool compatible)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "COMPATIBLE_XOD", compatible, &result));
}

inline UString OutputOptionsOCR::LanguageChoiceToString(LanguageChoice language)
{
	const char* lang_str = "au"; // automatic
	switch (language)
	{
		case e_lang_auto: lang_str = "au"; break;
		case e_lang_catalan: lang_str = "ca"; break;
		case e_lang_danish: lang_str = "da"; break;
		case e_lang_german: lang_str = "de"; break;
		case e_lang_english: lang_str = "en"; break;
		case e_lang_spanish: lang_str = "es"; break;
		case e_lang_finnish: lang_str = "fi"; break;
		case e_lang_french: lang_str = "fr"; break;
		case e_lang_italian: lang_str = "it"; break;
		case e_lang_dutch: lang_str = "nl"; break;
		case e_lang_norwegian: lang_str = "no"; break;
		case e_lang_portuguese: lang_str = "pt"; break;
		case e_lang_polish: lang_str = "pl"; break;
		case e_lang_romanian: lang_str = "ro"; break;
		case e_lang_russian: lang_str = "ru"; break;
		case e_lang_slovenian: lang_str = "sl"; break;
		case e_lang_swedish: lang_str = "sv"; break;
		case e_lang_turkish: lang_str = "tr"; break;
	}
	return UString(lang_str);
}

inline UString OutputOptionsOCR::PreferredOCRChoiceToString(PreferredOCREngine engine)
{
	const char* engine_str = "DEFAULT";
	switch (engine)
	{
		case e_engine_default: engine_str = "DEFAULT"; break;
		case e_engine_tesseract: engine_str = "TESS"; break;
	}
	return UString(engine_str);
}

inline StructuredOutputOptions::SectionConversionSetting  StructuredOutputOptions::SectionConversionSettingFromOption(TRN_Obj &obj)
{
	if (obj)
	{
		double num;
		TRN_ObjGetNumber(obj, &num);
		switch ((int)num)
		{
		case 1:
			return StructuredOutputOptions::e_DoNotDetect;
		case 2:
			return StructuredOutputOptions::e_DetectAndRemove;
		default:
			return StructuredOutputOptions::e_Recover;
		}
	}

	return StructuredOutputOptions::e_Recover;
}

inline HTMLOutputOptions::HTMLOutputOptions()
{
	m_obj=m_objset.CreateDict().mp_obj;
}

inline void HTMLOutputOptions::SetPreferJPG(bool prefer_jpg)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"PREFER_JPEG",prefer_jpg,&result));
}

inline void HTMLOutputOptions::SetJPGQuality(UInt32 quality)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"JPEG_QUALITY",quality,&result));
}


inline void HTMLOutputOptions::SetDPI(UInt32 dpi)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"DPI",dpi,&result));
}

inline void HTMLOutputOptions::SetMaximumImagePixels(UInt32 max_pixels)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"MAX_IMAGE_PIXELS",max_pixels,&result));
}

inline void HTMLOutputOptions::SetContentReflowSetting(ContentReflowSetting reflow)
{
	TRN_Obj result;
	switch (reflow)
	{
	case e_fixed_position:
		REX(TRN_ObjPutName(m_obj, "REFLOW", "FIXED_POSITION", &result));
		break;
	case e_reflow_paragraphs:
		REX(TRN_ObjPutName(m_obj, "REFLOW", "REFLOW_PARAGRAPHS", &result));
		break;
	case e_reflow_full:
		REX(TRN_ObjPutName(m_obj, "REFLOW", "REFLOW_FULL", &result));
		break;
	}
}

inline void HTMLOutputOptions::SetScale(double scale)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"SCALE",scale,&result));
}

inline void HTMLOutputOptions::SetExternalLinks(bool enable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"EXTERNAL_LINKS",enable,&result));
}

inline void HTMLOutputOptions::SetInternalLinks(bool enable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"INTERNAL_LINKS",enable,&result));
}

inline void HTMLOutputOptions::SetSimplifyText(bool enable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"SIMPLIFY_TEXT",enable,&result));
}

inline void HTMLOutputOptions::SetReportFile(const UString& path)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj,"REPORT_FILE",path.mp_impl,&result));
}

inline void HTMLOutputOptions::SetTitle(const UString& title)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "TITLE", title.mp_impl, &result));
}

inline void HTMLOutputOptions::SetImageDPI(UInt32 dpi)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "IMAGE_DPI", dpi, &result));
}

inline void HTMLOutputOptions::SetEmbedImages(bool enable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "EMBED_IMAGES", enable, &result));
}

inline void HTMLOutputOptions::SetFileConversionTimeoutSeconds(int seconds)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "FILE_TIMEOUT", seconds, &result));
}

inline void HTMLOutputOptions::SetPages(int page_from, int page_to)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "PAGE_FROM", page_from, &result));
	REX(TRN_ObjPutNumber(m_obj, "PAGE_TO", page_to, &result));
}

inline void HTMLOutputOptions::SetPDFPassword(const UString& password)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "PASSWORD", password.mp_impl, &result));
}

inline void HTMLOutputOptions::SetSearchableImageSetting(SearchableImageSetting setting)
{
	TRN_Obj result;
	switch (setting)
	{
	case e_ocr_image_text:
		REX(TRN_ObjPutName(m_obj, "OCRED", "IMAGE+TEXT", &result));
		break;
	case e_ocr_image:
		REX(TRN_ObjPutName(m_obj, "OCRED", "IMAGE", &result));
		break;
	case e_ocr_text:
		REX(TRN_ObjPutName(m_obj, "OCRED", "TEXT", &result));
		break;
	case e_ocr_always:
		REX(TRN_ObjPutName(m_obj, "OCRED", "ALWAYS", &result));
		break;
	case e_ocr_off:
		REX(TRN_ObjPutName(m_obj, "OCRED", "OFF", &result));
		break;
	}
}

inline void HTMLOutputOptions::SetTextRecoveryNSE(bool use_ocr)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "USE_OCR_NSE", BToTB(use_ocr), &result));
}

inline void HTMLOutputOptions::SetCustomOption(const UString& opt_name, const UString& opt_value)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, (std::string("!") + opt_name.ConvertToUtf8()).c_str(), opt_value.mp_impl, &result));
}

inline void HTMLOutputOptions::SetCustomOption(const UString& opt_name, int opt_value)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, (std::string("!") + opt_name.ConvertToUtf8()).c_str(), opt_value, &result));
}

inline void HTMLOutputOptions::SetSimpleLists(bool enable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "SIMPLE_LISTS", BToTB(enable), &result));
}

inline void HTMLOutputOptions::SetConnectHyphens(bool connect)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "CONNECT_HYPHENS", BToTB(connect), &result));
}

inline void HTMLOutputOptions::SetDisableVerticalSplit(bool disable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "DISABLE_VERTICAL_SPLIT", BToTB(disable), &result));
}

inline void HTMLOutputOptions::SetNoPageWidth(bool enable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "NO_PAGE_WIDTH", BToTB(enable), &result));
}

inline void HTMLOutputOptions::SetLanguage(OutputOptionsOCR::LanguageChoice language)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "LANGUAGE", OutputOptionsOCR::LanguageChoiceToString(language).mp_impl, &result));
}

inline void HTMLOutputOptions::SetPreferredOCREngine(OutputOptionsOCR::PreferredOCREngine engine)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "PREFERREDOCR", OutputOptionsOCR::PreferredOCRChoiceToString(engine).mp_impl, &result));
}

inline void HTMLOutputOptions::SetHeadersAndFootersSetting(StructuredOutputOptions::SectionConversionSetting option)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "DETECT_HEADERSANDFOOTERS", (int)option, &result));
}

inline void HTMLOutputOptions::SetFootnotesSetting(StructuredOutputOptions::SectionConversionSetting option)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "DETECT_FOOTNOTES", (int)option, &result));
}

inline StructuredOutputOptions::SectionConversionSetting HTMLOutputOptions::GetHeadersAndFootersSetting()
{
	TRN_Obj result;
	REX(TRN_ObjFindObj(m_obj, "DETECT_HEADERSANDFOOTERS", &result));
	return StructuredOutputOptions::SectionConversionSettingFromOption(result);
}

inline StructuredOutputOptions::SectionConversionSetting HTMLOutputOptions::GetFootnotesSetting()
{
	TRN_Obj result;
	REX(TRN_ObjFindObj(m_obj, "DETECT_FOOTNOTES", &result));
	return StructuredOutputOptions::SectionConversionSettingFromOption(result);
}

inline WordOutputOptions::WordOutputOptions()
{
	m_obj = m_objset.CreateDict().mp_obj;
}

inline void WordOutputOptions::SetWordOutputFormat(WordOutputFormat format)
{
	TRN_Obj result;
	switch (format)
	{
	case e_wof_docx:
		REX(TRN_ObjPutName(m_obj, "OUTPUT_FORMAT", "DOCX", &result));
		break;
	case e_wof_doc:
		REX(TRN_ObjPutName(m_obj, "OUTPUT_FORMAT", "DOC", &result));
		break;
	case e_wof_rtf:
		REX(TRN_ObjPutName(m_obj, "OUTPUT_FORMAT", "RTF", &result));
		break;
	case e_wof_txt:
		REX(TRN_ObjPutName(m_obj, "OUTPUT_FORMAT", "TXT", &result));
		break;
	}
}

inline void WordOutputOptions::SetPages(int page_from, int page_to)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "PAGE_FROM", page_from, &result));
	REX(TRN_ObjPutNumber(m_obj, "PAGE_TO", page_to, &result));
}

inline void WordOutputOptions::SetPDFPassword(const UString& password)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "PASSWORD", password.mp_impl, &result));
}

inline void WordOutputOptions::SetSearchableImageSetting(SearchableImageSetting setting)
{
	TRN_Obj result;
	switch (setting)
	{
	case e_ocr_image_text:
		REX(TRN_ObjPutName(m_obj, "OCRED", "IMAGE+TEXT", &result));
		break;
	case e_ocr_image:
		REX(TRN_ObjPutName(m_obj, "OCRED", "IMAGE", &result));
		break;
	case e_ocr_text:
		REX(TRN_ObjPutName(m_obj, "OCRED", "TEXT", &result));
		break;
	case e_ocr_always:
		REX(TRN_ObjPutName(m_obj, "OCRED", "ALWAYS", &result));
		break;
	case e_ocr_off:
		REX(TRN_ObjPutName(m_obj, "OCRED", "OFF", &result));
		break;
	}
}

inline void WordOutputOptions::SetTextRecoveryNSE(bool use_ocr)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "USE_OCR_NSE", BToTB(use_ocr), &result));
}

inline void WordOutputOptions::SetDetectTOC(bool detect_toc)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "DETECT_TOC", BToTB(detect_toc), &result));
}

inline void WordOutputOptions::SetCustomOption(const UString& opt_name, const UString& opt_value)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, (std::string("!") + opt_name.ConvertToUtf8()).c_str(), opt_value.mp_impl, &result));
}

inline void WordOutputOptions::SetCustomOption(const UString& opt_name, int opt_value)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, (std::string("!") + opt_name.ConvertToUtf8()).c_str(), opt_value, &result));
}

inline void WordOutputOptions::SetConnectHyphens(bool connect)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "CONNECT_HYPHENS", BToTB(connect), &result));
}

inline void WordOutputOptions::SetLanguage(OutputOptionsOCR::LanguageChoice language)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "LANGUAGE", OutputOptionsOCR::LanguageChoiceToString(language).mp_impl, &result));
}

inline void WordOutputOptions::SetPreferredOCREngine(OutputOptionsOCR::PreferredOCREngine engine)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "PREFERREDOCR", OutputOptionsOCR::PreferredOCRChoiceToString(engine).mp_impl, &result));
}

inline void WordOutputOptions::SetCustomOCRLanguage(const UString& ocrlang)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "LANGUAGE", ocrlang.mp_impl, &result));
}

inline void WordOutputOptions::SetPrioritizeVisualAppearance(bool replica)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "VISUAL_REPLICA", BToTB(replica), &result));
}

inline void WordOutputOptions::SetHeadersAndFootersSetting(StructuredOutputOptions::SectionConversionSetting option)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "DETECT_HEADERSANDFOOTERS", (int)option, &result));
}

inline void WordOutputOptions::SetFootnotesSetting(StructuredOutputOptions::SectionConversionSetting option)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "DETECT_FOOTNOTES", (int)option, &result));
}

inline StructuredOutputOptions::SectionConversionSetting WordOutputOptions::GetHeadersAndFootersSetting()
{
	TRN_Obj result;
	REX(TRN_ObjFindObj(m_obj, "DETECT_HEADERSANDFOOTERS", &result));
	return StructuredOutputOptions::SectionConversionSettingFromOption(result);
}

inline StructuredOutputOptions::SectionConversionSetting WordOutputOptions::GetFootnotesSetting()
{
	TRN_Obj result;
	REX(TRN_ObjFindObj(m_obj, "DETECT_FOOTNOTES", &result));
	return StructuredOutputOptions::SectionConversionSettingFromOption(result);
}

inline ExcelOutputOptions::ExcelOutputOptions()
{
	m_obj = m_objset.CreateDict().mp_obj;
}

inline void ExcelOutputOptions::SetPages(int page_from, int page_to)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "PAGE_FROM", page_from, &result));
	REX(TRN_ObjPutNumber(m_obj, "PAGE_TO", page_to, &result));
}

inline void ExcelOutputOptions::SetPDFPassword(const UString& password)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "PASSWORD", password.mp_impl, &result));
}

inline void ExcelOutputOptions::SetLanguage(OutputOptionsOCR::LanguageChoice language)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "LANGUAGE", OutputOptionsOCR::LanguageChoiceToString(language).mp_impl, &result));
}

inline void ExcelOutputOptions::SetPreferredOCREngine(OutputOptionsOCR::PreferredOCREngine engine)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "PREFERREDOCR", OutputOptionsOCR::PreferredOCRChoiceToString(engine).mp_impl, &result));
}

inline void ExcelOutputOptions::SetCustomOCRLanguage(const UString& ocrlang)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "LANGUAGE", ocrlang.mp_impl, &result));
}

inline void ExcelOutputOptions::SetSearchableImageSetting(SearchableImageSetting setting)
{
	TRN_Obj result;
	switch (setting)
	{
	case e_ocr_text:
		REX(TRN_ObjPutName(m_obj, "OCRED", "TEXT", &result));
		break;
	case e_ocr_always:
		REX(TRN_ObjPutName(m_obj, "OCRED", "ALWAYS", &result));
		break;
	case e_ocr_off:
		REX(TRN_ObjPutName(m_obj, "OCRED", "OFF", &result));
		break;
	}
}

inline void ExcelOutputOptions::SetTextRecoveryNSE(bool use_ocr)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "USE_OCR_NSE", BToTB(use_ocr), &result));
}

inline void ExcelOutputOptions::SetNonTableContent(bool non_tables)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "NON_TABLES", BToTB(non_tables), &result));
}

inline void ExcelOutputOptions::SetCustomOption(const UString& opt_name, const UString& opt_value)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, (std::string("!") + opt_name.ConvertToUtf8()).c_str(), opt_value.mp_impl, &result));
}

inline void ExcelOutputOptions::SetCustomOption(const UString& opt_name, int opt_value)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, (std::string("!") + opt_name.ConvertToUtf8()).c_str(), opt_value, &result));
}

inline void ExcelOutputOptions::SetSingleSheet(bool single_sheet)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "SINGLE_SHEET", BToTB(single_sheet), &result));
}

inline void ExcelOutputOptions::SetPageSingleSheet(bool page_single)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "PAGE_SINGLE", BToTB(page_single), &result));
}

inline void ExcelOutputOptions::SetHeadersAndFootersSetting(StructuredOutputOptions::SectionConversionSetting option)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "DETECT_HEADERSANDFOOTERS", (int)option, &result));
}

inline void ExcelOutputOptions::SetFootnotesSetting(StructuredOutputOptions::SectionConversionSetting option)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "DETECT_FOOTNOTES", (int)option, &result));
}

inline StructuredOutputOptions::SectionConversionSetting ExcelOutputOptions::GetHeadersAndFootersSetting()
{
	TRN_Obj result;
	REX(TRN_ObjFindObj(m_obj, "DETECT_HEADERSANDFOOTERS", &result));
	return StructuredOutputOptions::SectionConversionSettingFromOption(result);
}

inline StructuredOutputOptions::SectionConversionSetting ExcelOutputOptions::GetFootnotesSetting()
{
	TRN_Obj result;
	REX(TRN_ObjFindObj(m_obj, "DETECT_FOOTNOTES", &result));
	return StructuredOutputOptions::SectionConversionSettingFromOption(result);
}

inline PowerPointOutputOptions::PowerPointOutputOptions()
{
	m_obj = m_objset.CreateDict().mp_obj;
}

inline void PowerPointOutputOptions::SetPages(int page_from, int page_to)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "PAGE_FROM", page_from, &result));
	REX(TRN_ObjPutNumber(m_obj, "PAGE_TO", page_to, &result));
}

inline void PowerPointOutputOptions::SetPDFPassword(const UString& password)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "PASSWORD", password.mp_impl, &result));
}

inline void PowerPointOutputOptions::SetLanguage(OutputOptionsOCR::LanguageChoice language)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "LANGUAGE", OutputOptionsOCR::LanguageChoiceToString(language).mp_impl, &result));
}

inline void PowerPointOutputOptions::SetPreferredOCREngine(OutputOptionsOCR::PreferredOCREngine engine)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "PREFERREDOCR", OutputOptionsOCR::PreferredOCRChoiceToString(engine).mp_impl, &result));
}

inline void PowerPointOutputOptions::SetCustomOCRLanguage(const UString& ocrlang)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, "LANGUAGE", ocrlang.mp_impl, &result));
}

inline void PowerPointOutputOptions::SetSearchableImageSetting(SearchableImageSetting setting)
{
	TRN_Obj result;
	switch (setting)
	{
	case e_ocr_text:
		REX(TRN_ObjPutName(m_obj, "OCRED", "TEXT", &result));
		break;
	case e_ocr_always:
		REX(TRN_ObjPutName(m_obj, "OCRED", "ALWAYS", &result));
		break;
	case e_ocr_off:
		REX(TRN_ObjPutName(m_obj, "OCRED", "OFF", &result));
		break;
	}
}

inline void PowerPointOutputOptions::SetTextRecoveryNSE(bool use_ocr)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "USE_OCR_NSE", BToTB(use_ocr), &result));
}

inline void PowerPointOutputOptions::SetCustomOption(const UString& opt_name, const UString& opt_value)
{
	TRN_Obj result;
	REX(TRN_ObjPutText(m_obj, (std::string("!") + opt_name.ConvertToUtf8()).c_str(), opt_value.mp_impl, &result));
}

inline void PowerPointOutputOptions::SetCustomOption(const UString& opt_name, int opt_value)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, (std::string("!") + opt_name.ConvertToUtf8()).c_str(), opt_value, &result));
}

inline void PowerPointOutputOptions::SetHeadersAndFootersSetting(StructuredOutputOptions::SectionConversionSetting option)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "DETECT_HEADERSANDFOOTERS", (int)option, &result));
}

inline void PowerPointOutputOptions::SetFootnotesSetting(StructuredOutputOptions::SectionConversionSetting option)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj, "DETECT_FOOTNOTES", (int)option, &result));
}

inline StructuredOutputOptions::SectionConversionSetting PowerPointOutputOptions::GetHeadersAndFootersSetting()
{
	TRN_Obj result;
	REX(TRN_ObjFindObj(m_obj, "DETECT_HEADERSANDFOOTERS", &result));
	return StructuredOutputOptions::SectionConversionSettingFromOption(result);
}

inline StructuredOutputOptions::SectionConversionSetting PowerPointOutputOptions::GetFootnotesSetting()
{
	TRN_Obj result;
	REX(TRN_ObjFindObj(m_obj, "DETECT_FOOTNOTES", &result));
	return StructuredOutputOptions::SectionConversionSettingFromOption(result);
}

inline TiffOutputOptions::TiffOutputOptions()
{
	m_obj=m_objset.CreateDict().mp_obj;
}

inline void TiffOutputOptions::SetBox(enum Page::Box type)
{
	TRN_Obj result;
	switch (type)
	{
	case Page::e_media:
		REX(TRN_ObjPutName(m_obj, "BOX", "media", &result));
		break;
	case Page::e_crop:
		REX(TRN_ObjPutName(m_obj, "BOX", "crop", &result));
		break;
	case Page::e_bleed:
		REX(TRN_ObjPutName(m_obj, "BOX", "bleed", &result));
		break;
	case Page::e_trim:
		REX(TRN_ObjPutName(m_obj, "BOX", "trim", &result));
		break;
	case Page::e_art:
		REX(TRN_ObjPutName(m_obj, "BOX", "art", &result));
		break;
	case Page::e_user_crop:
		REX(TRN_ObjPutName(m_obj, "BOX", "user_crop", &result));
		break;
	}
}

inline void TiffOutputOptions::SetRotate(enum Page::Rotate rotation)
{
	TRN_Obj result;
	switch (rotation)
	{
	case Page::e_0:
		REX(TRN_ObjPutName(m_obj, "ROTATE", "0", &result));
		break;
	case Page::e_90:
		REX(TRN_ObjPutName(m_obj, "ROTATE", "90", &result));
		break;
	case Page::e_180:
		REX(TRN_ObjPutName(m_obj, "ROTATE", "180", &result));
		break;
	case Page::e_270:
		REX(TRN_ObjPutName(m_obj, "ROTATE", "270", &result));
		break;
	}
}

inline void TiffOutputOptions::SetClip(double x1, double y1, double x2, double y2)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"CLIP_X1",x1,&result));
	REX(TRN_ObjPutNumber(m_obj,"CLIP_Y1",y1,&result));
	REX(TRN_ObjPutNumber(m_obj,"CLIP_X2",x2,&result));
	REX(TRN_ObjPutNumber(m_obj,"CLIP_Y2",y2,&result));
}

inline void TiffOutputOptions::SetPages(const char* page_desc)
{
	TRN_Obj result;
	REX(TRN_ObjPutName(m_obj, "PAGES", page_desc, &result));
}

inline void TiffOutputOptions::SetOverprint(enum PDFRasterizer::OverprintPreviewMode mode)
{
	TRN_Obj result;
	SetOverprintImpl(m_obj, mode, &result);
}

inline void TiffOutputOptions::SetCMYK(bool enable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "CMYK", BToTB(enable), &result));
}

inline void TiffOutputOptions::SetDither(bool enable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "DITHER", BToTB(enable), &result));
}

inline void TiffOutputOptions::SetGray(bool enable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "GRAY", BToTB(enable), &result));
}

inline void TiffOutputOptions::SetMono(bool enable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "MONO", BToTB(enable), &result));
}

inline void TiffOutputOptions::SetAnnots(bool enable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "ANNOTS", BToTB(enable), &result));
}

inline void TiffOutputOptions::SetSmooth(bool enable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "SMOOTH", BToTB(enable), &result));
}

inline void TiffOutputOptions::SetPrintmode(bool enable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "PRINTMODE", BToTB(enable), &result));
}

inline void TiffOutputOptions::SetTransparentPage(bool enable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "TRANSPARENT_PAGE", BToTB(enable), &result));
}

inline void TiffOutputOptions::SetPalettized(bool enable)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj, "PALETTIZED", BToTB(enable), &result));
}

inline void TiffOutputOptions::SetDPI(double dpi)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"DPI",dpi,&result));
}

inline void TiffOutputOptions::SetGamma(double gamma)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"GAMMA",gamma,&result));
}

inline void TiffOutputOptions::SetHRes(int hres)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"HRES",static_cast<double>(hres),&result));
}

inline void TiffOutputOptions::SetVRes(int vres)
{
	TRN_Obj result;
	REX(TRN_ObjPutNumber(m_obj,"VRES",static_cast<double>(vres),&result));
}

inline EPUBOutputOptions::EPUBOutputOptions()
{
	m_obj=m_objset.CreateDict().mp_obj;
}

inline void EPUBOutputOptions::SetExpanded(bool expanded)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"EPUB_EXPANDED",expanded,&result));
}

inline void EPUBOutputOptions::SetReuseCover(bool reuse)
{
	TRN_Obj result;
	REX(TRN_ObjPutBool(m_obj,"EPUB_REUSE_COVER",reuse,&result));
}

inline void Convert::ToXps(PDFDoc & in_pdfdoc, const UString & in_filename)
{
	XPSOutputOptions options;
	Convert::ToXps( in_pdfdoc, in_filename, options);
}

inline void Convert::ToXps( PDFDoc & in_pdfdoc, const UString & in_filename, const XPSOutputOptions& options)
{
	REX(TRN_ConvertToXps(in_pdfdoc.mp_doc,in_filename.mp_impl, options.m_obj));
}

inline void Convert::ToXps(const UString & in_inputFilename, const UString & in_outputFilename)
{
	XPSOutputOptions options;
	Convert::ToXps( in_inputFilename, in_outputFilename, options);
}

inline void Convert::ToXps( const UString & in_inputFilename, const UString & in_outputFilename, const XPSOutputOptions& options)
{
	REX(TRN_ConvertFileToXps(in_inputFilename.mp_impl, in_outputFilename.mp_impl, options.m_obj));
}

inline void Convert::ToXod(const UString & in_filename, const UString & out_filename)
{
	XODOutputOptions options;
	Convert::ToXod( in_filename, out_filename, options);
}

inline void Convert::ToXod( const UString & in_filename, const UString & out_filename, const XODOutputOptions& options)
{
	REX(TRN_ConvertFileToXod(in_filename.mp_impl, out_filename.mp_impl, options.m_obj));
}

inline void Convert::ToXod(PDFDoc & in_pdfdoc, const UString & out_filename)
{
	XODOutputOptions options;
	Convert::ToXod( in_pdfdoc, out_filename, options);
}

inline void Convert::ToXod(PDFDoc & in_pdfdoc, const UString & out_filename, const XODOutputOptions& options)
{
	REX(TRN_ConvertToXod(in_pdfdoc.mp_doc, out_filename.mp_impl, options.m_obj));
}

inline Filters::Filter Convert::ToXod(const UString & in_filename)
{
	XODOutputOptions options;
	return Convert::ToXod( in_filename, options);
}

inline Filters::Filter Convert::ToXod( const UString & in_filename, const XODOutputOptions& options)
{
	TRN_Filter result;
	REX(TRN_ConvertFileToXodStream(in_filename.mp_impl, options.m_obj, &result));
	return Filters::Filter(result,true);
}

inline Filters::Filter Convert::ToXod(PDFDoc& in_pdfdoc)
{
	XODOutputOptions options;
	return Convert::ToXod( in_pdfdoc, options);
}

inline Filters::Filter Convert::ToXod(PDFDoc& in_pdfdoc, const XODOutputOptions& options)
{
	TRN_Filter result;
	REX(TRN_ConvertToXodStream(in_pdfdoc.mp_doc, options.m_obj, &result)); // try
	return Filters::Filter(result,true);
}

inline ConversionMonitor Convert::ToXodWithMonitor(PDFDoc& in_pdfdoc)
{
	XODOutputOptions options;
	return Convert::ToXodWithMonitor( in_pdfdoc, options);
}

inline ConversionMonitor Convert::ToXodWithMonitor(PDFDoc& in_pdfdoc, const XODOutputOptions& options)
{
	TRN_ConversionMonitor result;
	REX(TRN_ConvertToXodWithMonitor(in_pdfdoc.mp_doc, options.m_obj, &result));
	ConversionMonitor monitor = ConversionMonitor(result,true);
	return monitor;
}

inline ConversionMonitor::ConversionMonitor(TRN_ConversionMonitor impl, bool is_owner) {
	mp_impl=impl;
	m_owner=is_owner;
}
inline ConversionMonitor::ConversionMonitor() : mp_impl(0), m_owner(true) {}

inline bool ConversionMonitor::Next()
{
	RetBool(TRN_ConversionMonitorNext(mp_impl,&result));
}

inline bool ConversionMonitor::Ready()
{
	RetBool(TRN_ConversionMonitorReady(mp_impl,&result));
}

inline UInt32 ConversionMonitor::Progress()
{
	UInt32 result;
	REX(TRN_ConversionMonitorProgress(mp_impl,&result));
	return result;
}

inline Filters::Filter ConversionMonitor::Filter()
{
	TRN_Filter result;
	REX(TRN_ConversionMonitorFilter(mp_impl, &result));
	return Filters::Filter(result,true);
}

inline ConversionMonitor::ConversionMonitor(const ConversionMonitor& copy) 
{
	if(copy.m_owner) {
		((ConversionMonitor&)copy).m_owner = false;
		m_owner=true;
	}
	else {
		m_owner=false;
	}

	mp_impl=copy.mp_impl;
}

inline ConversionMonitor& ConversionMonitor::operator =(const ConversionMonitor& other) 
{
	if(m_owner) { 
		REX(TRN_ConversionMonitorDestroy(mp_impl));
		mp_impl=0;
	}

	if(other.m_owner) {
		((ConversionMonitor&)other).m_owner = false;
		m_owner=true;
	}
	else {
		m_owner=false;
	}

	mp_impl=other.mp_impl;
	return *this;
}
inline ConversionMonitor::~ConversionMonitor()
{
	if(m_owner) {
		DREX(mp_impl, TRN_ConversionMonitorDestroy(mp_impl));
	}
}

inline void ConversionMonitor::Destroy()
{
	if(m_owner) {
		REX(TRN_ConversionMonitorDestroy(mp_impl));
		mp_impl = 0;
	}
}

inline void Convert::ToHtml(const UString & in_filename, const UString & out_path)
{
	HTMLOutputOptions options;
	Convert::ToHtml( in_filename, out_path, options);
}

inline UString Convert::PageToHtml(const Page & page)
{
	TRN_UString result;
	REX(TRN_ConvertPageToHtml(page.mp_page, &result));
	return UString(result);
}

inline UString Convert::PageToHtmlZoned(const Page & page, const UString & json_zones)
{
	TRN_UString result;
	REX(TRN_ConvertPageToHtmlZoned(page.mp_page, json_zones.mp_impl, &result));
	return UString(result);
}

inline void Convert::ToHtml(const UString & in_filename, const UString & out_path, const HTMLOutputOptions& options)
{
	REX(TRN_ConvertFileToHtml(in_filename.mp_impl, out_path.mp_impl, options.m_obj));
}

inline void Convert::ToHtml(PDFDoc & in_pdfdoc, const UString & out_path)
{
	HTMLOutputOptions options;
	Convert::ToHtml( in_pdfdoc, out_path, options);
}

inline void Convert::ToHtml(PDFDoc & in_pdfdoc, const UString & out_path, const HTMLOutputOptions& options)
{
	REX(TRN_ConvertToHtml(in_pdfdoc.mp_doc, out_path.mp_impl, options.m_obj));
}

inline void Convert::ToWord(const UString & in_filename, const UString & out_path)
{
	WordOutputOptions options;
	Convert::ToWord(in_filename, out_path, options);
}

inline void Convert::ToWord(PDFDoc& in_pdfdoc, Filters::Filter& out_filter)
{
	WordOutputOptions options;
	Convert::ToWord(in_pdfdoc, out_filter, options);
}

inline void Convert::ToWord(PDFDoc& in_pdfdoc, Filters::Filter& out_filter, const WordOutputOptions& options)
{
	REX(TRN_ConvertToWordWithFilter(in_pdfdoc.mp_doc, out_filter.m_impl, options.m_obj));
}

inline void Convert::ToWord(const UString & in_filename, const UString & out_path, const WordOutputOptions& options)
{
	REX(TRN_ConvertFileToWord(in_filename.mp_impl, out_path.mp_impl, options.m_obj));
}

inline void Convert::ToWord(PDFDoc& in_pdfdoc, const UString& out_path)
{
	WordOutputOptions options;
	Convert::ToWord(in_pdfdoc, out_path, options);
}

inline void Convert::ToWord(PDFDoc & in_pdfdoc, const UString & out_path, const WordOutputOptions& options)
{
	REX(TRN_ConvertToWord(in_pdfdoc.mp_doc, out_path.mp_impl, options.m_obj));
}

inline void Convert::ToExcel(const UString& in_filename, const UString& out_path)
{
	ExcelOutputOptions options;
	Convert::ToExcel(in_filename, out_path, options);
}

inline void Convert::ToExcel(const UString& in_filename, const UString& out_path, const ExcelOutputOptions& options)
{
	REX(TRN_ConvertFileToExcel(in_filename.mp_impl, out_path.mp_impl, options.m_obj));
}

inline void Convert::ToExcel(PDFDoc& in_pdfdoc, const UString& out_path)
{
	ExcelOutputOptions options;
	Convert::ToExcel(in_pdfdoc, out_path, options);
}

inline void Convert::ToExcel(PDFDoc& in_pdfdoc, const UString& out_path, const ExcelOutputOptions& options)
{
	REX(TRN_ConvertToExcel(in_pdfdoc.mp_doc, out_path.mp_impl, options.m_obj));
}

inline void Convert::ToExcel(PDFDoc& in_pdfdoc, Filters::Filter& out_filter)
{
	ExcelOutputOptions options;
	Convert::ToExcel(in_pdfdoc, out_filter, options);
}

inline void Convert::ToExcel(PDFDoc& in_pdfdoc, Filters::Filter& out_filter, const ExcelOutputOptions& options)
{
	REX(TRN_ConvertToExcelWithFilter(in_pdfdoc.mp_doc, out_filter.m_impl, options.m_obj));
}

inline void Convert::ToPowerPoint(const UString& in_filename, const UString& out_path)
{
	PowerPointOutputOptions options;
	Convert::ToPowerPoint(in_filename, out_path, options);
}

inline void Convert::ToPowerPoint(const UString& in_filename, const UString& out_path, const PowerPointOutputOptions& options)
{
	REX(TRN_ConvertFileToPowerPoint(in_filename.mp_impl, out_path.mp_impl, options.m_obj));
}

inline void Convert::ToPowerPoint(PDFDoc& in_pdfdoc, const UString& out_path)
{
	PowerPointOutputOptions options;
	Convert::ToPowerPoint(in_pdfdoc, out_path, options);
}

inline void Convert::ToPowerPoint(PDFDoc& in_pdfdoc, const UString& out_path, const PowerPointOutputOptions& options)
{
	REX(TRN_ConvertToPowerPoint(in_pdfdoc.mp_doc, out_path.mp_impl, options.m_obj));
}

inline void Convert::ToPowerPoint(PDFDoc& in_pdfdoc, Filters::Filter& out_filter)
{
	PowerPointOutputOptions options;
	Convert::ToPowerPoint(in_pdfdoc, out_filter, options);
}

inline void Convert::ToPowerPoint(PDFDoc& in_pdfdoc, Filters::Filter& out_filter, const PowerPointOutputOptions& options)
{
	REX(TRN_ConvertToPowerPointWithFilter(in_pdfdoc.mp_doc, out_filter.m_impl, options.m_obj));
}

inline void Convert::ToTiff(const UString & in_filename, const UString & out_path)
{
	TiffOutputOptions options;
	Convert::ToTiff( in_filename, out_path, options);
}

inline void Convert::ToTiff(const UString & in_filename, const UString & out_path, const TiffOutputOptions& options)
{
	REX(TRN_ConvertFileToTiff(in_filename.mp_impl, out_path.mp_impl, options.m_obj));
}

inline void Convert::ToTiff(PDFDoc & in_pdfdoc, const UString & out_path)
{
	TiffOutputOptions options;
	Convert::ToTiff( in_pdfdoc, out_path, options);
}

inline void Convert::ToTiff(PDFDoc & in_pdfdoc, const UString & out_path, const TiffOutputOptions& options)
{
	REX(TRN_ConvertToTiff(in_pdfdoc.mp_doc, out_path.mp_impl, options.m_obj));
}

inline void Convert::ToTiff(const UString & in_filename, Filters::Filter& out_filter)
{
	TiffOutputOptions options;
	Convert::ToTiff(in_filename, out_filter, options);
}

inline void Convert::ToTiff(const UString & in_filename, Filters::Filter& out_filter, const TiffOutputOptions& options)
{
	REX(TRN_ConvertFileToTiffWithFilter(in_filename.mp_impl, out_filter.m_impl, options.m_obj));
}

inline void Convert::ToTiff(PDFDoc & in_pdfdoc, Filters::Filter& out_filter)
{
	TiffOutputOptions options;
	Convert::ToTiff(in_pdfdoc, out_filter, options);
}

inline void Convert::ToTiff(PDFDoc & in_pdfdoc, Filters::Filter& out_filter, const TiffOutputOptions& options)
{
	REX(TRN_ConvertToTiffWithFilter(in_pdfdoc.mp_doc, out_filter.m_impl, options.m_obj));
}

inline void Convert::ToEpub(const UString & in_filename, const UString & out_path)
{
	HTMLOutputOptions html_options;
	EPUBOutputOptions epub_options;
	Convert::ToEpub( in_filename, out_path, html_options, epub_options);
}

inline void Convert::ToEpub(const UString & in_filename, const UString & out_path, const HTMLOutputOptions& html_options)
{
	EPUBOutputOptions epub_options;
	Convert::ToEpub( in_filename, out_path, html_options, epub_options);
}

inline void Convert::ToEpub(const UString & in_filename, const UString & out_path, const HTMLOutputOptions& html_options, const EPUBOutputOptions& epub_options)
{
	REX(TRN_ConvertFileToEpub(in_filename.mp_impl, out_path.mp_impl, html_options.m_obj, epub_options.m_obj));
}

inline void Convert::ToEpub(PDFDoc & in_pdfdoc, const UString & out_path)
{
	HTMLOutputOptions html_options;
	EPUBOutputOptions epub_options;
	Convert::ToEpub( in_pdfdoc, out_path, html_options, epub_options);
}

inline void Convert::ToEpub(PDFDoc & in_pdfdoc, const UString & out_path, const HTMLOutputOptions& html_options)
{
	EPUBOutputOptions epub_options;
	Convert::ToEpub( in_pdfdoc, out_path, html_options, epub_options);
}

inline void Convert::ToEpub(PDFDoc & in_pdfdoc, const UString & out_path, const HTMLOutputOptions& html_options, const EPUBOutputOptions& epub_options)
{
	REX(TRN_ConvertToEpub(in_pdfdoc.mp_doc, out_path.mp_impl, html_options.m_obj, epub_options.m_obj));
}

inline DocumentConversion Convert::WordToPDFConversion(PDFDoc & in_pdfdoc, const UString & in_filename, WordToPDFOptions* options)
{
	DocumentConversion ret((TRN_DocumentConversion)0);
	// a pointer to a pointer to an sdf doc
	PDFDoc* ptr = &in_pdfdoc;
	// a pointer to a pointer to an sdf doc
	TRN_PDFDoc* to_pass = (TRN_PDFDoc*)ptr;
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_ConvertWordToPdfConversion(to_pass, in_filename.mp_impl, opt_ptr ,&ret.m_impl));
	return ret;
}

inline void Convert::WordToPDF(PDFDoc & in_pdfdoc, const UString & in_filename, WordToPDFOptions* options)
{
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_ConvertWordToPdf(in_pdfdoc.mp_doc, in_filename.mp_impl, opt_ptr));
}

inline DocumentConversion Convert::WordToPDFConversion(PDFDoc & in_pdfdoc, Filters::Filter in_data, WordToPDFOptions* options)
{
	DocumentConversion ret((TRN_DocumentConversion)0);
	// a pointer to a pointer to an sdf doc
	PDFDoc* ptr = &in_pdfdoc;
	// a pointer to a pointer to an sdf doc
	TRN_PDFDoc* to_pass = (TRN_PDFDoc*)ptr;
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	// make sure the filter doesn't die as it leaves this method scope (the conversion will take ownership)
	in_data.m_owner = false;
	REX(TRN_ConvertWordToPdfConversionWithFilter(to_pass, in_data.m_impl, opt_ptr ,&ret.m_impl));
	return ret;
}

inline void Convert::WordToPDF(PDFDoc & in_pdfdoc, Filters::Filter in_data, WordToPDFOptions* options)
{
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	// make sure the filter doesn't double-delete as it leaves this method scope 
	// (the conversion will take care of deletion)
	in_data.m_owner = false;
	REX(TRN_ConvertWordToPdfWithFilter(in_pdfdoc.mp_doc, in_data.m_impl, opt_ptr));
}

//////////////////////////////////////////////////////////////////////////
inline DocumentConversion Convert::StreamingPDFConversion(PDFDoc & in_pdfdoc, const UString & in_filename, ConversionOptions* options)
{
	DocumentConversion ret((TRN_DocumentConversion)0);
	// a pointer to a pointer to an sdf doc
	PDFDoc* ptr = &in_pdfdoc;
	// a pointer to a pointer to an sdf doc
	TRN_PDFDoc* to_pass = (TRN_PDFDoc*)ptr;
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_ConvertStreamingPdfConversionWithPdfAndPath(to_pass, in_filename.mp_impl, opt_ptr, &ret.m_impl));
	return ret;
}

inline DocumentConversion Convert::StreamingPDFConversion(const UString & in_filename, ConversionOptions* options)
{
	DocumentConversion ret((TRN_DocumentConversion)0);
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_ConvertStreamingPdfConversionWithPath(in_filename.mp_impl, opt_ptr, &ret.m_impl));
	return ret;
}

inline void Convert::OfficeToPDF(PDFDoc & in_pdfdoc, const UString & in_filename, ConversionOptions* options)
{
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_ConvertOfficeToPdfWithPath(in_pdfdoc.mp_doc, in_filename.mp_impl, opt_ptr));
}

inline DocumentConversion Convert::StreamingPDFConversion(PDFDoc & in_pdfdoc, Filters::Filter in_data, ConversionOptions* options)
{
	DocumentConversion ret((TRN_DocumentConversion)0);
	// a pointer to a pointer to an sdf doc
	PDFDoc* ptr = &in_pdfdoc;
	// a pointer to a pointer to an sdf doc
	TRN_PDFDoc* to_pass = (TRN_PDFDoc*)ptr;
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	// make sure the filter doesn't die as it leaves this method scope (the conversion will take ownership)
	in_data.m_owner = false;
	REX(TRN_ConvertStreamingPdfConversionWithPdfAndFilter(to_pass, in_data.m_impl, opt_ptr, &ret.m_impl));
	return ret;
}

inline DocumentConversion Convert::StreamingPDFConversion(Filters::Filter in_data, ConversionOptions* options)
{
	DocumentConversion ret((TRN_DocumentConversion)0);
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	// make sure the filter doesn't die as it leaves this method scope (the conversion will take ownership)
	in_data.m_owner = false;
	REX(TRN_ConvertStreamingPdfConversionWithFilter(in_data.m_impl, opt_ptr, &ret.m_impl));
	return ret;
}

inline Reflow Convert::CreateReflow(Page & in_page, const UString & json_zones)
{
	Reflow ret((TRN_Reflow)0);
	REX(TRN_ConvertCreateReflow(in_page.mp_page, json_zones.mp_impl, &ret.m_impl));
	return ret;
}

inline void Convert::OfficeToPDF(PDFDoc & in_pdfdoc, Filters::Filter in_data, ConversionOptions* options)
{
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	// make sure the filter doesn't double-delete as it leaves this method scope 
	// (the conversion will take care of deletion)
	in_data.m_owner = false;
	REX(TRN_ConvertOfficeToPdfWithFilter(in_pdfdoc.mp_doc, in_data.m_impl, opt_ptr));
}
//////////////////////////////////////////////////////////////////////////

inline TemplateDocument Convert::CreateOfficeTemplate(const UString& in_filename, ConversionOptions* options)
{
	TemplateDocument ret((TRN_TemplateDocument)0);
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_ConvertCreateOfficeTemplateWithPath(in_filename.mp_impl, opt_ptr, &ret.m_impl));
	return ret;
}

inline TemplateDocument Convert::CreateOfficeTemplate(Filters::Filter in_data, ConversionOptions* options)
{
	TemplateDocument ret((TRN_TemplateDocument)0);
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	// make sure the filter doesn't die as it leaves this method scope (the conversion will take ownership)
	in_data.m_owner = false;
	REX(TRN_ConvertCreateOfficeTemplateWithFilter(in_data.m_impl, opt_ptr, &ret.m_impl));
	return ret;
}

//////////////////////////////////////////////////////////////////////////

inline void Convert::ToPdf(PDFDoc & in_pdfdoc, const UString & in_filename)
{
	REX(TRN_ConvertToPdf(in_pdfdoc.mp_doc, in_filename.mp_impl));
}

inline void Convert::FromCAD(PDFDoc & in_pdfdoc, const UString & in_filename, CADConvertOptions* options)
{
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_ConvertFromCAD(in_pdfdoc.mp_doc, in_filename.mp_impl, opt_ptr));
}

inline void Convert::FromDICOM(PDFDoc & in_pdfdoc, const UString & in_filename, AdvancedImagingConvertOptions* options)
{
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_ConvertFromDICOM(in_pdfdoc.mp_doc, in_filename.mp_impl, opt_ptr));
}

inline void Convert::FromSVG(PDFDoc & in_pdfdoc, const UString & in_filename, SVGConvertOptions* options)
{
	TRN_Obj opt_ptr = options ? options->GetInternalObj().mp_obj : 0;
	REX(TRN_ConvertFromSVG(in_pdfdoc.mp_doc, in_filename.mp_impl, opt_ptr));
}

inline void Convert::FromTiff(PDFDoc & in_pdfdoc, Filters::Filter in_data)
{
	// make sure the filter doesn't double-delete as it leaves this method scope 
	// (the conversion will take care of deletion)
	in_data.m_owner = false;
	REX(TRN_ConvertFromTiff(in_pdfdoc.mp_doc, in_data.m_impl));
}

inline bool Convert::RequiresPrinter(const UString & in_filename)
{
	RetBool(TRN_ConvertRequiresPrinter(in_filename.mp_impl, &result));
}

inline void Printer::Install(const UString & in_printerName)
{
	REX(TRN_ConvertPrinterInstall(in_printerName.mp_impl));
}

inline void Printer::Uninstall()
{
	REX(TRN_ConvertPrinterUninstall());
}

inline const UString Printer::GetPrinterName()
{
	RetStr(TRN_ConvertPrinterGetPrinterName(&result));
}

inline void Printer::SetPrinterName(const UString & in_printerName)
{
	REX(TRN_ConvertPrinterSetPrinterName(in_printerName.mp_impl));
}

inline bool Printer::IsInstalled(const UString & in_printerName)
{
	RetBool(TRN_ConvertPrinterIsInstalled(in_printerName.mp_impl,&result));
}

inline void Printer::SetMode(Mode mode)
{
	REX(TRN_ConvertPrinterSetMode((enum TRN_ConvertPrinterMode)mode));
}

inline Printer::Mode Printer::GetMode()
{
	enum TRN_ConvertPrinterMode result;
	REX(TRN_ConvertPrinterGetMode(&result));
	return (Printer::Mode)result;
}

void SetFlattenContentImpl(TRN_Obj obj, enum Convert::FlattenFlag flatten, TRN_Obj* result)
{
	switch (flatten)
	{
		case Convert::e_off:
			REX(TRN_ObjPutName(obj, "FLATTEN_CONTENT", "OFF", result));
			break;
		case Convert::e_simple:
			REX(TRN_ObjPutName(obj, "FLATTEN_CONTENT", "SIMPLE", result));
			break;
		case Convert::e_fast:
			REX(TRN_ObjPutName(obj, "FLATTEN_CONTENT", "FAST", result));
			break;
		case Convert::e_high_quality:
			REX(TRN_ObjPutName(obj, "FLATTEN_CONTENT", "HIGH_QUALITY", result));
	}	
}

void SetFlattenThresholdImpl(TRN_Obj obj, enum Convert::FlattenThresholdFlag threshold, TRN_Obj* result)
{
	switch (threshold)
	{
		case Convert::e_very_strict:
			REX(TRN_ObjPutName(obj, "FLATTEN_THRESHOLD", "VERY_STRICT", result));
			break;
		case Convert::e_strict:
			REX(TRN_ObjPutName(obj, "FLATTEN_THRESHOLD", "STRICT", result));
			break;
		case Convert::e_default:
			REX(TRN_ObjPutName(obj, "FLATTEN_THRESHOLD", "DEFAULT", result));
			break;
		case Convert::e_keep_most:
			REX(TRN_ObjPutName(obj, "FLATTEN_THRESHOLD", "KEEP_MOST", result));
			break;
		case Convert::e_keep_all:
			REX(TRN_ObjPutName(obj, "FLATTEN_THRESHOLD", "KEEP_ALL", result));
			break;
	}
}

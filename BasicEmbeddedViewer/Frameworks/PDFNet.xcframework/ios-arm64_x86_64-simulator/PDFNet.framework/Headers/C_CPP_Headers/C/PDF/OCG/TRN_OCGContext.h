//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFOCGOCGContext
#define PDFTRON_H_CPDFOCGOCGContext

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_OCGContextCreateFromConfig(TRN_OCGConfig cfg, TRN_OCGContext* result);
TRN_API TRN_OCGContextCopy(const TRN_OCGContext c, TRN_OCGContext* result);

TRN_API TRN_OCGContextDestroy(TRN_OCGContext ctx);

TRN_API TRN_OCGContextGetState(const TRN_OCGContext c, const TRN_OCG grp, TRN_Bool* result);
TRN_API TRN_OCGContextSetState(const TRN_OCGContext c, const TRN_OCG grp, TRN_Bool state);
TRN_API TRN_OCGContextResetStates(const TRN_OCGContext c, TRN_Bool all_on);

TRN_API TRN_OCGContextSetNonOCDrawing(const TRN_OCGContext c, TRN_Bool draw_non_OC);
TRN_API TRN_OCGContextGetNonOCDrawing(const TRN_OCGContext c, TRN_Bool* result);

enum TRN_OCGContextOCDrawMode {
	e_OCGContext_VisibleOC,
	e_OCGContext_AllOC,
	e_OCGContext_NoOC
};

TRN_API TRN_OCGContextSetOCDrawMode(const TRN_OCGContext c, enum TRN_OCGContextOCDrawMode oc_draw_mode);
TRN_API TRN_OCGContextGetOCMode(const TRN_OCGContext c, enum TRN_OCGContextOCDrawMode* result);

enum TRN_OCGContextOCEventMode {
	e_OCGContext_EventView,
	e_OCGContext_EventPrint,
	e_OCGContext_EventExport
};

TRN_API TRN_OCGContextAdjustState(const TRN_OCGContext c, enum TRN_OCGContextOCEventMode oc_event_mode);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFOCGOCGContext

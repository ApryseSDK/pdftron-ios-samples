//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_ContentElement
#define PDFTRON_H_ContentElement

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

// All objects from the trn::Layout::iContentElement hierarchy are represented
// by a single opaque TRN_ContentElement pointer in C. The wrapper functions
// themselves know what type of object they are dealing with and cast the
// pointer to the appropriate type.
// 
// Via the contruction of objects in the inheritance hierarchy it
// is guaranteed that a certain class has the correct corresponding
// internal pointer as TRN_ContentElement. For example a
// Paragraph instance has an trn::Layout::iParagraph pointer
// that was casted to the trn::Layout::iContentElement base class
// pointer and stored as the TRN_ContentElement in the ContentElement
// wrapper class.
//
// Every function in the TRN layer can therefore rely that the TRN_ContentElement
// can be casted to the correct internal pointer type. This is guarded by
// an assertion in the Checked...SelfCast() functions

TRN_API TRN_ContentElementAsTextRun(TRN_ContentElement self, TRN_TextRun* result);
TRN_API TRN_ContentElementAsContentNode(TRN_ContentElement self, TRN_ContentNode* result);
TRN_API TRN_ContentElementAsParagraph(TRN_ContentElement self, TRN_Paragraph* result);
TRN_API TRN_ContentElementAsTable(TRN_ContentElement self, TRN_Table* result);
TRN_API TRN_ContentElementAsTableRow(TRN_ContentElement self, TRN_TableRow* result);
TRN_API TRN_ContentElementAsTableCell(TRN_ContentElement self, TRN_TableCell* result);
TRN_API TRN_ContentElementAsList(TRN_ContentElement self, TRN_List* result);
TRN_API TRN_ContentElementAsListItem(TRN_ContentElement self, TRN_ListItem* result);
TRN_API TRN_ContentElementGetTextStyledElement(TRN_ContentElement self, TRN_TextStyledElement* result);

#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_ContentElement */

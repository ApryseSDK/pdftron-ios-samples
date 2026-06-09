//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef uint32_t PTPDFPageNumber;

static const PTPDFPageNumber PTInvalidPDFPageNumber = 0;

static inline BOOL PTPDFPageNumberIsValid(PTPDFPageNumber pageNumber)
{
    return pageNumber != PTInvalidPDFPageNumber;
}

NS_ASSUME_NONNULL_END

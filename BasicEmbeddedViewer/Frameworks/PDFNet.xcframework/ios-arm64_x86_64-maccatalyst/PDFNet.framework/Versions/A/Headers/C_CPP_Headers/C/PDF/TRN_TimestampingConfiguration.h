//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by Apryse Software Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CTimestampingConfiguration
#define PDFTRON_H_CTimestampingConfiguration

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>

/* methods: */
TRN_API TRN_TimestampingConfigurationCreateFromURL(TRN_UString in_url, TRN_TimestampingConfiguration* result);
TRN_API TRN_TimestampingConfigurationSetTimestampAuthorityServerURL(TRN_TimestampingConfiguration self, TRN_UString in_url);
TRN_API TRN_TimestampingConfigurationSetTimestampAuthorityServerUsername(TRN_TimestampingConfiguration self, TRN_UString in_username);
TRN_API TRN_TimestampingConfigurationSetTimestampAuthorityServerPassword(TRN_TimestampingConfiguration self, TRN_UString in_password);
TRN_API TRN_TimestampingConfigurationSetUseNonce(TRN_TimestampingConfiguration self, TRN_Bool in_use_nonce);
TRN_API TRN_TimestampingConfigurationTestConfiguration(TRN_TimestampingConfiguration self, TRN_VerificationOptions in_opts, TRN_TimestampingResult* result);
TRN_API TRN_TimestampingConfigurationDestroy(TRN_TimestampingConfiguration self);
TRN_API TRN_TimestampingConfigurationCopyCtor(TRN_TimestampingConfiguration source, TRN_TimestampingConfiguration* result);
TRN_API TRN_TimestampingConfigurationAssign(TRN_TimestampingConfiguration source, TRN_TimestampingConfiguration* result);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CTimestampingConfiguration */

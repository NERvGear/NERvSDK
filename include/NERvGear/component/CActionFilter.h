
/***************************************************************
 * Name:      CActionFilter.h
 * Purpose:   Defines Action Filter Component
 * Author:    GPBeta ()
 * Created:   2015-09-26
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_CACTIONFILTER_H
#define NVG_CACTIONFILTER_H

#include <NERvGear/component/CUnknown.h>

#ifdef __cplusplus

namespace NERvGear {


/// \ingroup mod_com_nvg
///
/// \component NERvGear::CActionFilter
/// \extends NERvGear::CUnknown
/// \brief Filters actions to be executed.
///
/// \implguide
///     Objects that implement this component should provide a NERvGear::IExecute interface.\n
/// A Filter should return a success code (NVG_SUCC(retval) == true) from its IExecute::Invoke() method,
/// telling the caller that an action has been executed by this filter, otherwise, it should return a failure code
/// (NVG_FAIL(retval) == true) so that the caller could do further filtering search.
///
/// \see
///     NERvGear::CActionListener
///
/// \declid{Component,NERvGear::ID_CActionFilter,CORE_SYSTEM-7B76-4FB7-A4A4-F8904ACAB7D1}

// Component ID
NVG_EXPORT_UID(NVG_ID_CActionFilter, CATALOG::CORE_SYSTEM, 0x7B76, 0x4FB7, 0xA4, 0xA4, 0xF8, 0x90, 0x4A, 0xCA, 0xB7, 0xD1);
static const UID& ID_CActionFilter = NVG_ID_CActionFilter; ///< CORE_SYSTEM-7B76-4FB7-A4A4-F8904ACAB7D1
//#define ID_CActionFilter NVG_ID_CActionFilter


} // NERvGear

#else // C

#endif // __cplusplus

#endif // NVG_CACTIONFILTER_H

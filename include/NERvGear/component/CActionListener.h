
/***************************************************************
 * Name:      CActionListener.h
 * Purpose:   Defines Action Listener Component
 * Author:    GPBeta ()
 * Created:   2015-09-26
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_CACTIONLISTENER_H
#define NVG_CACTIONLISTENER_H

#include <NERvGear/component/CUnknown.h>

#ifdef __cplusplus

namespace NERvGear {


/// \ingroup mod_com_nvg
///
/// \component NERvGear::CActionListener
/// \extends NERvGear::CUnknown
/// \brief Get notified when executing an action.
///
/// \implguide
///     Objects that implement this component should provide a NERvGear::IExecute interface.
///
/// \see
///     NERvGear::CActionFilter
///
/// \declid{Component,NERvGear::ID_CActionListener,CORE_SYSTEM-7B76-4FB7-A4A4-F8904ACAB7D0}

// Component ID
NVG_EXPORT_UID(NVG_ID_CActionListener, CATALOG::CORE_SYSTEM, 0x7B76, 0x4FB7, 0xA4, 0xA4, 0xF8, 0x90, 0x4A, 0xCA, 0xB7, 0xD0);
static const UID& ID_CActionListener = NVG_ID_CActionListener; ///< CORE_SYSTEM-7B76-4FB7-A4A4-F8904ACAB7D0
//#define ID_CActionListener NVG_ID_CActionListener


} // NERvGear

#else // C

#endif // __cplusplus

#endif // NVG_CACTIONLISTENER_H

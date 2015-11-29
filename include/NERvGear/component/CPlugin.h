
/***************************************************************
 * Name:      CPlugin.h
 * Purpose:   Defines Nerve Gear Plug-in Component
 * Author:    GPBeta ()
 * Created:   2015-09-26
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_CPLUGIN_H
#define NVG_CPLUGIN_H

#include <NERvGear/component/CUnknown.h>

#ifdef __cplusplus

namespace NERvGear {


/// \ingroup mod_com_nvg
///
/// \component NERvGear::CPlugin
/// \extends NERvGear::CUnknown
/// \brief Nerve Gear Plug-in.
///
/// \note
///     Plug-ins (component implementations) are registered to a different database other than the normal components,
/// so it's not allowed and not possible to create a plug-in object through NERvCreateObject().
///
/// \implguide
///     Objects that implement this component should provide a NERvGear::IPlugin interface.\n
///
/// \declid{Component,NERvGear::ID_CPlugin,CORE_PLUGIN-0000-0000-0043-506C7567696E}

// Component ID
NVG_EXPORT_UID(NVG_ID_CPlugin, CATALOG::CORE_PLUGIN, 0x0000, 0x0000, 0x00, 0x43, 0x50, 0x6C, 0x75, 0x67, 0x69, 0x6E);
static const UID& ID_CPlugin = NVG_ID_CPlugin; ///< "CPlugin"
//#define ID_CPlugin NVG_ID_CPlugin


} // NERvGear

#else // C

#endif // __cplusplus

#endif // NVG_CPLUGIN_H

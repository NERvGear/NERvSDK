
/***************************************************************
 * Name:      IPlugin.h
 * Purpose:   Defines IPlugin Interface
 * Author:    GPBeta ()
 * Created:   2015-05-20
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_IPLUGIN_H
#define NVG_IPLUGIN_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

// forward declaration
struct PLUGIN_INFO;

namespace UI {

struct IWindow;

} // UI

namespace PLUGIN {

namespace CONFIG {

enum ID {
    INVALID,
    DEFAULT
};

typedef long TYPE;

} // CONFIG

} // PLUGIN

/// \ingroup mod_itf_nvg
///
/// \brief Nerve Gear plug-in interface.
/// 
/// \declid{Interface,NERvGear::ID_IPlugin,00000001-0000-0000-0049-506C7567696E}
NVG_INTERFACE_EXTEND(IPlugin, IUnknown) {

    virtual long NVG_METHOD OnInitial() NVG_PURE;
    virtual long NVG_METHOD OnReady() NVG_PURE;
    virtual long NVG_METHOD OnRelease() NVG_PURE;

    virtual long NVG_METHOD OnConfig(UI::IWindow* window, PLUGIN::CONFIG::TYPE type, void* param) NVG_PURE;

};

// Interface ID
NVG_EXPORT_UID(NVG_ID_IPlugin, 0x00000001, 0x0000, 0x0000, 0x00, 0x49, 0x50, 0x6C, 0x75, 0x67, 0x69, 0x6E);
static const UID& ID_IPlugin = NVG_ID_IPlugin; ///< "IPlugin" version 1
//#define ID_IPlugin NVG_ID_IPlugin

}

#else // C

#endif // __cplusplus


#endif // NVG_IPLUGIN_H

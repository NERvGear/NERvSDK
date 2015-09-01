
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

// IPlugin interface
NVG_INTERFACE_EXTEND(IPlugin, IUnknown) {

    virtual long NVG_METHOD OnInitial() NVG_PURE;
    virtual long NVG_METHOD OnReady() NVG_PURE;
    virtual long NVG_METHOD OnRelease() NVG_PURE;

    virtual long NVG_METHOD OnConfig(UI::IWindow* window, PLUGIN::CONFIG::TYPE type, void* param) NVG_PURE;

};

// declare IDs
NVG_DEFINE_UID(NVG_ID_CPlugin, CATALOG::CORE_PLUGIN, 0x0000, 0x0000, 0x00, 0x43, 0x50, 0x6C, 0x75, 0x67, 0x69, 0x6E); // "CPlugin"
NVG_DEFINE_UID(NVG_ID_IPlugin,           0x00000001, 0x0000, 0x0000, 0x00, 0x49, 0x50, 0x6C, 0x75, 0x67, 0x69, 0x6E); // "IPlugin" version 1

// define latest API
//#define ID_CPlugin NVG_ID_CPlugin
//#define ID_IPlugin NVG_ID_IPlugin
static const UID& ID_CPlugin = NVG_ID_CPlugin; // Class ID
static const UID& ID_IPlugin = NVG_ID_IPlugin; // Interface ID

}

#else // C

#endif // __cplusplus


#endif // NVG_IPLUGIN_H

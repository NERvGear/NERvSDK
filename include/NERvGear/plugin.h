
/***************************************************************
 * Name:      plugin.h
 * Purpose:   Defines Nerve Gear Plug-in APIs
 * Author:    GPBeta ()
 * Created:   2014-10-27
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_PLUGIN_H
#define NVG_PLUGIN_H

#include <NERvGear/COM.h>
#include <NERvGear/new.h>
#include <NERvGear/object.h>
#include <NERvGear/template.h>

#include <NERvGear/interface/IPlugin.h>

namespace NERvGear {

class PluginImpl : public IPlugin {
public:

    virtual long NVG_METHOD OnInitial() { return S_OK; }
    virtual long NVG_METHOD OnReady()   { return S_OK; }
    virtual long NVG_METHOD OnRelease() { return S_OK; }

    virtual long NVG_METHOD OnConfig(UI::IWindow* window, PLUGIN::CONFIG::TYPE type, void* param) { return E_NOTIMPL; }

    virtual long NVG_METHOD QueryInterface(const ::NERvGear::UID& interfaceID, void** ppvObject)
    {
        if (interfaceID == ID_IPlugin || interfaceID == ID_IUnknown) {
            *ppvObject = static_cast<IPlugin*>(this);
        } else {
            *ppvObject = NULL;
            return E_NOINTERFACE;
        }
        reinterpret_cast<IUnknown*>(*ppvObject)->AddRef();
        return S_OK;
    }

};

#define NVG_DECLARE_PLUGIN(_PLUGIN_CLASS)   public: virtual ~_PLUGIN_CLASS() {} \
                                                    static const ::NERvGear::OBJECT_INFO STATIC_OBJECT_INFO;

// NOTE: remove NVG_BEGIN_PLUGIN_INFO from Code Completion parser
#define NVG_BEGIN_PLUGIN_INFO(_PLUGIN_CLASS) const ::NERvGear::PLUGIN_INFO NVG_PLUGIN_INFO = { {NVS_VER_REV},
    #define NVG_DECLARE_PLUGIN_UID(_D1, _D2, _D3, _D41, _D42, _D43, _D44, _D45, _D46, _D47, _D48) \
                                  {_D1, _D2, _D3, _D41, _D42, _D43, _D44, _D45, _D46, _D47, _D48},
    #define NVG_DECLARE_PLUGIN_TYPE(_TYPE)                         _TYPE,
    #define NVG_DECLARE_PLUGIN_VERSION(_MAJOR, _MINOR, _SUBMINOR) NVG_DECLARE_VERSION(_MAJOR, _MINOR, _SUBMINOR, 0),
    #define NVG_DECLARE_PLUGIN_NAME(_NAME)                        NVG_TEXT(_NAME),
    #define NVG_DECLARE_PLUGIN_DESCRIP(_DESCRIP)                  NVG_TEXT(_DESCRIP),
    #define NVG_DECLARE_PLUGIN_COMMENT(_COMMENT)                  NVG_TEXT(_COMMENT),
    #define NVG_DECLARE_PLUGIN_AUTHOR(_AUTHOR)                    NVG_TEXT(_AUTHOR),
    #define NVG_DECLARE_PLUGIN_HOMEPAGE(_HOMEPAGE)                NVG_TEXT(_HOMEPAGE),
    #define NVG_DECLARE_PLUGIN_EMAIL(_EMAIL)                      NVG_TEXT(_EMAIL),
// NOTE: remove NVG_END_DEPENDENCY_LIST from Code Completion parser
#define NVG_END_PLUGIN_INFO(_PLUGIN_CLASS) NULL}; \
                                           const ::NERvGear::OBJECT_INFO _PLUGIN_CLASS::STATIC_OBJECT_INFO = \
                                           { {NVS_VER_REV}, ::NERvGear::ID_CPlugin, NVG_PLUGIN_INFO.id, NVG_PLUGIN_INFO.version, NVG_PLUGIN_INFO.name, NVG_PLUGIN_INFO.descrip, NULL }; \

#define NVG_NO_COMPONENT_REGISTER(_PLUGIN) namespace NERvGear { \
                                           NVG_EXPORT(long) DllRegisterServer() { return S_FALSE; } \
                                           NVG_EXPORT(long) DllUnregisterServer() { return S_FALSE; } }

#define NVG_BEGIN_COMPONENT_REGISTER(_PLUGIN) namespace NERvGear { NVG_EXPORT(long) DllRegisterServer() {
    #define NVG_REGISTER_OBJECT(_OBJ, _AGG) if (IObjectFactory* factory = nvg_new NerveFactoryT<_OBJ, _AGG>) { \
                                                NERvRegisterObject(_OBJ::STATIC_OBJECT_INFO.classID, _OBJ::STATIC_OBJECT_INFO.objectID, factory); \
                                                factory->Release(); \
                                            }
#define NVG_END_COMPONENT_REGISTER() return S_OK; } NVG_EXPORT(long) DllUnregisterServer() { return NERvUnregisterObject(ID_NULL, ID_NULL); } }

// NOTE: remove NVG_END_PLUGIN_INFO from Code Completion parser

#define NVG_IMPLEMENT_PLUGIN(_PLUGIN_CLASS) namespace NERvGear { \
                                            MODULE NVG_MODULE = { 0 }; \
                                            extern "C" bool __stdcall DllMain(void* hModule, unsigned long dwReason, void* lpReserved) \
                                            { \
                                                if (dwReason == 1/* DLL_PROCESS_ATTACH */) \
                                                    NVG_MODULE.hHandle = hModule; \
                                                return true; \
                                            } \
                                            \
                                            NVG_EXPORT(long) DllCanUnloadNow() \
                                            { \
                                                return (NVG_MODULE.nActive || NVG_MODULE.nLock) ? S_FALSE : S_OK; \
                                            } \
                                            \
                                            NVG_EXPORT(PLUGIN_INFO const *) DllGetInfo() \
                                            { \
                                                return &NVG_PLUGIN_INFO; \
                                            } \
                                            \
                                            NVG_EXPORT(MODULE*) DllRegisterModule(ModuleContext* context) \
                                            { \
                                                NVG_MODULE.context = context; \
                                                return &NVG_MODULE; \
                                            } \
                                            \
                                            NVG_EXPORT(long) DllGetClassObject(const GUID& classID, const GUID& interfaceID, void** ppv) \
                                            { \
                                                UID const & cid = *reinterpret_cast<const UID*>(&classID); \
                                                UID const & iid = *reinterpret_cast<const UID*>(&interfaceID); \
                                                if (cid == ID_CPlugin) { \
                                                    if (iid == ID_IUnknown || iid == ID_IClassFactory || iid == ID_IObjectFactory) \
                                                        return (*ppv = nvg_new NerveFactoryT<_PLUGIN_CLASS, false>) ? S_OK : E_OUTOFMEMORY; \
                                                    else \
                                                        return E_NOINTERFACE; \
                                                } else { return E_NOTIMPL; } \
                                                return E_FAIL; \
                                            } \
                                            } // NERvGear
// declaration

namespace PLUGIN {

enum FLAG {
    BASIC   = 0,

    WIDGET  = 0x00000001,
    THEME   = 0x00000002,

    MIXED   = 0xFFFFFFFF
};

typedef unsigned TYPE;

}

struct PLUGIN_INFO {
    VERSION sdk_version;

    UID id;
    PLUGIN::TYPE type;
    VERSION version;

    const wchar_t* name;
    const wchar_t* descrip;
    const wchar_t* comment;
    const wchar_t* author;
    const wchar_t* homepage;
    const wchar_t* email;

    void* reserved;
};

}

#endif // NVG_PLUGIN_H


/***************************************************************
 * Name:      object.h
 * Purpose:   Defines Nerve Gear Object APIs
 * Author:    GPBeta ()
 * Created:   2014-10-22
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_OBJECT_H
#define NVG_OBJECT_H

#include <NERvGear/COM.h>
#include <NERvGear/version.h>

#include <NERvGear/interface/IObjectFactory.h>

namespace NERvGear {

#define NVG_DECLARE_OBJECT(_OBJECT_CLASS) public: virtual long NVG_METHOD QueryInterface(const ::NERvGear::UID& interfaceID, void** ppvObject); \
                                                  static const ::NERvGear::OBJECT_INFO STATIC_OBJECT_INFO;

#define NVG_BEGIN_OBJECT_INFO(_OBJECT_CLASS) const OBJECT_INFO _OBJECT_CLASS::STATIC_OBJECT_INFO = { {NVS_VER_REV},
    #define NVG_DECLARE_OBJECT_CLASSID_UID(_ID) _ID,
    #define NVG_DECLARE_OBJECT_CLASSID(_D1, _D2, _D3, _D41, _D42, _D43, _D44, _D45, _D46, _D47, _D48) \
                                      {_D1, _D2, _D3, {_D41, _D42, _D43, _D44, _D45, _D46, _D47, _D48}},
    #define NVG_DECLARE_OBJECT_OBJECTID_UID(_ID) _ID,
    #define NVG_DECLARE_OBJECT_OBJECTID(_D1, _D2, _D3, _D41, _D42, _D43, _D44, _D45, _D46, _D47, _D48) \
                                       {_D1, _D2, _D3, {_D41, _D42, _D43, _D44, _D45, _D46, _D47, _D48}},
    #define NVG_DECLARE_OBJECT_VERSION(_MAJOR, _MINOR, _SUBMINOR) NVG_DECLARE_VERSION(_MAJOR, _MINOR, _SUBMINOR, 0),
    #define NVG_DECLARE_OBJECT_NAME(_NAME)                        NVG_TEXT(_NAME),
    #define NVG_DECLARE_OBJECT_DESCRIP(_DESCRIP)                  NVG_TEXT(_DESCRIP),
#define NVG_END_OBJECT_INFO() NULL};

// declaration

struct OBJECT_INFO {
    VERSION sdk_version;

    UID classID;
    UID objectID;
    VERSION version;

    const wchar_t* name;
    const wchar_t* descrip;

    void* reserved;
};

enum {
    E_OBJECT_NOT_FOUND  = NVG_MAKERESULT(ERROR, 1),
    E_OBJECT_DUPLICATED = NVG_MAKERESULT(ERROR, 2)
};

NVG_EXPORT(void) NERvTraceObject(MODULE* refModule, const UID& objectID, int n);
NVG_EXPORT(long) NERv1CreateObject(const UID& classID, const UID& objectID, const UID& interfaceID, IUnknown* unknownOuter, void** ppvObject, MODULE* module);
NVG_EXPORT(long) NERv1RegisterObject(const UID& classID, const UID& objectID, IObjectFactory* objectFactory, MODULE* module);
NVG_EXPORT(long) NERv1UnregisterObject(const UID& classID, const UID& objectID, MODULE* module);

// latest APIs
static inline long NERvCreateObject(const UID& classID, const UID& objectID, const UID& interfaceID, IUnknown* unknownOuter, void** ppvObject)
{ return NERv1CreateObject(classID, objectID, interfaceID, unknownOuter, ppvObject, &NVG_MODULE); }

static inline long NERvRegisterObject(const UID& classID, const UID& objectID, IObjectFactory* objectFactory)
{ return NERv1RegisterObject(classID, objectID, objectFactory, &NVG_MODULE); }

static inline long NERvUnregisterObject(const UID& classID, const UID& objectID)
{ return NERv1UnregisterObject(classID, objectID, &NVG_MODULE); }

}

#endif // NVG_OBJECT_H

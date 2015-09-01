
#ifndef NVG_IOBJECTFACTORY_H
#define NVG_IOBJECTFACTORY_H

#include "IClassFactory.h"

#ifdef __cplusplus

namespace NERvGear {

// forward declaration
struct OBJECT_INFO;

// IObjectFactory interface
NVG_INTERFACE_EXTEND(IObjectFactory, IClassFactory) {

    virtual long NVG_METHOD CreateInstanceEx(MODULE* refModule, IUnknown* unknownOuter, const UID& interfaceID, void** ppvObject) NVG_PURE;
    virtual const OBJECT_INFO& NVG_METHOD GetInfo() const NVG_PURE;

};

// declare interface ID
NVG_DEFINE_UID(NVG_ID_IObjectFactory, 0x4F490001, 0x6A62, 0x6365, 0x74, 0x46, 0x61, 0x63, 0x74, 0x6F, 0x72, 0x79); // "IObjectFactory" version 1

// define latest API
//#define ID_IObjectFactory NVG_ID_IObjectFactory
static const UID& ID_IObjectFactory = NVG_ID_IObjectFactory;

}

#else // C

#endif // __cplusplus


#endif // NVG_IOBJECTFACTORY_H

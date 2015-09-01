
#ifndef NVG_ICLASSFACTORY_H
#define NVG_ICLASSFACTORY_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

//! Reimplement of standard IClassFactory COM interface.
//! It's safe to cast a pointer between NERvGear::IClassFactory and ::IClassFactory.
NVG_INTERFACE_EXTEND(IClassFactory, IUnknown) {

    virtual long NVG_METHOD CreateInstance(IUnknown* unknownOuter, const UID& interfaceID, void** ppvObject) NVG_PURE;
    virtual long NVG_METHOD LockServer(bool lock) NVG_PURE;

};

// declare IDs
NVG_DEFINE_UID(NVG_ID_IClassFactory, 0x00000001, 0x0000, 0x0000, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46);

// define aliases
//#define ID_IClassFactory NVG_ID_IClassFactory
static const UID& ID_IClassFactory = NVG_ID_IClassFactory;

} // NERvGear

#else // C

#endif // __cplusplus

#endif // NVG_ICLASSFACTORY_H

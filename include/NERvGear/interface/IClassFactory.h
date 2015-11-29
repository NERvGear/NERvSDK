
/***************************************************************
 * Name:      IClassFactory.h
 * Purpose:   Defines IClassFactory Interface
 * Author:    GPBeta ()
 * Created:   2015-05-20
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_ICLASSFACTORY_H
#define NVG_ICLASSFACTORY_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

/// \ingroup mod_itf_com
///
/// \brief Reimplementation of standard IClassFactory COM interface.
///
/// \note
///     It's safe to cast a pointer between NERvGear::IClassFactory and ::IClassFactory.
///
/// \declid{Interface,NERvGear::ID_IClassFactory,00000001-0000-0000-C000-000000000046}
NVG_INTERFACE_EXTEND(IClassFactory, IUnknown) {

    virtual long NVG_METHOD CreateInstance(IUnknown* unknownOuter, const UID& interfaceID, void** ppvObject) NVG_PURE;
    virtual long NVG_METHOD LockServer(bool lock) NVG_PURE;

};

// Interface ID
NVG_EXPORT_UID(NVG_ID_IClassFactory, 0x00000001, 0x0000, 0x0000, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46);
static const UID& ID_IClassFactory = NVG_ID_IClassFactory; ///< 00000001-0000-0000-C000-000000000046
//#define ID_IClassFactory NVG_ID_IClassFactory

} // NERvGear

#else // C

#endif // __cplusplus

#endif // NVG_ICLASSFACTORY_H

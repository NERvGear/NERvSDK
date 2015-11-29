
/***************************************************************
 * Name:      IObjectFactory.h
 * Purpose:   Defines IObjectFactory Interface
 * Author:    GPBeta ()
 * Created:   2015-05-20
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_IOBJECTFACTORY_H
#define NVG_IOBJECTFACTORY_H

#include "IClassFactory.h"

#ifdef __cplusplus

namespace NERvGear {

// forward declaration
struct OBJECT_INFO;

/// \ingroup mod_itf_nvg
///
/// \brief Nerve Gear object factory interface.
/// 
/// \declid{Interface,NERvGear::ID_IObjectFactory,4F490001-6A62-6365-7446-6163746F7279}
NVG_INTERFACE_EXTEND(IObjectFactory, IClassFactory) {

    virtual long NVG_METHOD CreateInstanceEx(MODULE* refModule, IUnknown* unknownOuter, const UID& interfaceID, void** ppvObject) NVG_PURE;
    virtual const OBJECT_INFO& NVG_METHOD GetInfo() const NVG_PURE;

};

// Interface ID
NVG_EXPORT_UID(NVG_ID_IObjectFactory, 0x4F490001, 0x6A62, 0x6365, 0x74, 0x46, 0x61, 0x63, 0x74, 0x6F, 0x72, 0x79);
static const UID& ID_IObjectFactory = NVG_ID_IObjectFactory; ///< "IObjectFactory" version 1
//#define ID_IObjectFactory NVG_ID_IObjectFactory

}

#else // C

#endif // __cplusplus


#endif // NVG_IOBJECTFACTORY_H


/***************************************************************
 * Name:      IEventHandler.h
 * Purpose:   Defines IEventHandler Interface
 * Author:    GPBeta ()
 * Created:   2015-05-20
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_IEVENTHANDLER_H
#define NVG_IEVENTHANDLER_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

class Event;

/// \ingroup mod_itf_nvg
///
/// \brief Nerve Gear event handler interface.
/// 
/// \declid{Interface,NERvGear::ID_IEventHandler,49000001-7645-6E65-7448-616E646C6572}
NVG_INTERFACE_EXTEND(IEventHandler, IUnknown) {

    virtual long NVG_METHOD HandleEvent(Event& event) NVG_PURE;

};

// Interface ID
NVG_EXPORT_UID(NVG_ID_IEventHandler, 0x49000001, 0x7645, 0x6E65, 0x74, 0x48, 0x61, 0x6E, 0x64, 0x6C, 0x65, 0x72);
static const UID& ID_IEventHandler = NVG_ID_IEventHandler; ///< "IEventHandler" version 1
//#define ID_IEventHandler NVG_ID_IEventHandler

}

#else // C

#endif // __cplusplus

#endif // NVG_IEVENTHANDLER_H

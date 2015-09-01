
#ifndef NVG_IEVENTHANDLER_H
#define NVG_IEVENTHANDLER_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

class Event;

NVG_INTERFACE_EXTEND(IEventHandler, IUnknown) {

    virtual long NVG_METHOD HandleEvent(Event& event) NVG_PURE;

};

// declare interface ID
NVG_DEFINE_UID(NVG_ID_IEventHandler, 0x49000001, 0x7645, 0x6E65, 0x74, 0x48, 0x61, 0x6E, 0x64, 0x6C, 0x65, 0x72); // "IEventHandler" version 1

// define aliases
//#define ID_IEventHandler NVG_ID_IEventHandler
static const UID& ID_IEventHandler = NVG_ID_IEventHandler;

}

#else // C

#endif // __cplusplus

#endif // NVG_IEVENTHANDLER_H

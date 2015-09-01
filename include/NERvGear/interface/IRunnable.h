
#ifndef NVG_IRUNNABLE_H
#define NVG_IRUNNABLE_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

NVG_INTERFACE_EXTEND(IRunnable, IUnknown) {

    virtual int NVG_METHOD Run(IUnknown* userdata) NVG_PURE;
    virtual long NVG_METHOD Stop() NVG_PURE;

};

// declare interface ID
NVG_DEFINE_UID(NVG_ID_IRunnable, 0x00000001, 0x0000, 0x4900, 0x52, 0x75, 0x6E, 0x6E, 0x61, 0x62, 0x6C, 0x65); // "IRunnable" version 1

// define aliases
//#define ID_IRunnable NVG_ID_IRunnable
static const UID& ID_IRunnable = NVG_ID_IRunnable;

}

#else // C

#endif // __cplusplus

#endif // NVG_IRUNNABLE_H

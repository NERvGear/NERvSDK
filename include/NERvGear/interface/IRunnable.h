
/***************************************************************
 * Name:      IRunnable.h
 * Purpose:   Defines IRunnable Interface
 * Author:    GPBeta ()
 * Created:   2015-05-20
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_IRUNNABLE_H
#define NVG_IRUNNABLE_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

/// \ingroup mod_itf_nvg
///
/// \brief Nerve Gear runnable interface.
/// 
/// \declid{Interface,NERvGear::ID_IRunnable,00000001-0000-4900-5275-6E6E61626C65}
NVG_INTERFACE_EXTEND(IRunnable, IUnknown) {

    virtual int NVG_METHOD Run(IUnknown* userdata) NVG_PURE;
    virtual long NVG_METHOD Stop() NVG_PURE;

};

// Interface ID
NVG_EXPORT_UID(NVG_ID_IRunnable, 0x00000001, 0x0000, 0x4900, 0x52, 0x75, 0x6E, 0x6E, 0x61, 0x62, 0x6C, 0x65);
static const UID& ID_IRunnable = NVG_ID_IRunnable; ///< "IRunnable" version 1
//#define ID_IRunnable NVG_ID_IRunnable

}

#else // C

#endif // __cplusplus

#endif // NVG_IRUNNABLE_H

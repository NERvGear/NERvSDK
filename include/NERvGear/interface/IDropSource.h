
#ifndef NVG_IDROPSOURCE_H
#define NVG_IDROPSOURCE_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

//! Reimplement of standard IDropSource COM interface.
//! It's safe to cast a pointer between NERvGear::IDropSource and ::IDropSource.
NVG_INTERFACE_EXTEND(IDropSource, IUnknown) {
    virtual long NVG_METHOD QueryContinueDrag(int fEscapePressed, unsigned grfKeyState) NVG_PURE;
    virtual long NVG_METHOD GiveFeedback(unsigned dwEffect) NVG_PURE;
};

// declare IDs
NVG_DEFINE_UID(NVG_ID_IDropSource, 0x00000121, 0x0000, 0x0000, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46); // 00000121-0000-0000-C000-000000000046

// define aliases
//#define ID_IDropSource NVG_ID_IDropSource
static const UID& ID_IDropSource = NVG_ID_IDropSource;

}

#else // C

#endif // __cplusplus

#endif // NVG_IDROPSOURCE_H

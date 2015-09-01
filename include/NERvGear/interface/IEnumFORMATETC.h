
#ifndef NVG_IENUMFORMATETC_H
#define NVG_IENUMFORMATETC_H

#include "IUnknown.h"

#ifdef __cplusplus

typedef struct tagFORMATETC FORMATETC;

namespace NERvGear {

//! Reimplement of standard IEnumFORMATETC COM interface.
//! It's safe to cast a pointer between NERvGear::IEnumFORMATETC and ::IEnumFORMATETC.
NVG_INTERFACE_EXTEND(IEnumFORMATETC, IUnknown) {
    virtual long NVG_METHOD Next(unsigned celt, FORMATETC* rgelt, unsigned* pceltFetched) NVG_PURE;
    virtual long NVG_METHOD Skip(unsigned celt) NVG_PURE;
    virtual long NVG_METHOD Reset() NVG_PURE;
    virtual long NVG_METHOD Clone(IEnumFORMATETC** ppenum) NVG_PURE;
};

// declare IDs
NVG_DEFINE_UID(NVG_ID_IEnumFORMATETC, 0x00000103, 0x0000, 0x0000, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46); // 00000103-0000-0000-C000-000000000046

// define aliases
//#define ID_IEnumFORMATETC NVG_ID_IEnumFORMATETC
static const UID& ID_IEnumFORMATETC = NVG_ID_IEnumFORMATETC;

}

#else // C

#endif // __cplusplus

#endif // NVG_IENUMFORMATETC_H


/***************************************************************
 * Name:      IEnumFORMATETC.h
 * Purpose:   Defines IEnumFORMATETC Interface
 * Author:    GPBeta ()
 * Created:   2015-05-20
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_IENUMFORMATETC_H
#define NVG_IENUMFORMATETC_H

#include "IUnknown.h"

#ifdef __cplusplus

typedef struct tagFORMATETC FORMATETC;

namespace NERvGear {

/// \ingroup mod_itf_com
///
/// \brief Reimplementation of standard IEnumFORMATETC COM interface.
///
/// \note
///     It's safe to cast a pointer between NERvGear::IEnumFORMATETC and ::IEnumFORMATETC.
///
/// \declid{Interface,NERvGear::ID_IEnumFORMATETC,00000103-0000-0000-C000-000000000046}
NVG_INTERFACE_EXTEND(IEnumFORMATETC, IUnknown) {
    virtual long NVG_METHOD Next(unsigned celt, FORMATETC* rgelt, unsigned* pceltFetched) NVG_PURE;
    virtual long NVG_METHOD Skip(unsigned celt) NVG_PURE;
    virtual long NVG_METHOD Reset() NVG_PURE;
    virtual long NVG_METHOD Clone(IEnumFORMATETC** ppenum) NVG_PURE;
};

// Interface ID
NVG_EXPORT_UID(NVG_ID_IEnumFORMATETC, 0x00000103, 0x0000, 0x0000, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46);
static const UID& ID_IEnumFORMATETC = NVG_ID_IEnumFORMATETC; ///< 00000103-0000-0000-C000-000000000046
//#define ID_IEnumFORMATETC NVG_ID_IEnumFORMATETC

}

#else // C

#endif // __cplusplus

#endif // NVG_IENUMFORMATETC_H

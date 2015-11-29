
/***************************************************************
 * Name:      IDataObject.h
 * Purpose:   Defines IDataObject Interface
 * Author:    GPBeta ()
 * Created:   2015-05-20
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_IDATAOBJECT_H
#define NVG_IDATAOBJECT_H

#include "IUnknown.h"

#ifdef __cplusplus

typedef struct tagFORMATETC FORMATETC;
typedef struct tagSTGMEDIUM uSTGMEDIUM;
typedef uSTGMEDIUM STGMEDIUM;

namespace NERvGear {

struct IEnumFORMATETC;
struct IEnumSTATDATA;   // not defined in ::NERvGear
struct IAdviseSink;     // not defined in ::NERvGear

/// \ingroup mod_itf_com
///
/// \brief Reimplementation of standard IDataObject COM interface.
///
/// \note
///     It's safe to cast a pointer between NERvGear::IDataObject and ::IDataObject.
///
/// \declid{Interface,NERvGear::ID_IDataObject,00000010E-0000-0000-C000-000000000046}
NVG_INTERFACE_EXTEND(IDataObject, IUnknown) {

    virtual long NVG_METHOD GetData(FORMATETC* pformatetcIn, STGMEDIUM* pmedium) NVG_PURE;
    virtual long NVG_METHOD GetDataHere(FORMATETC* pformatetc, STGMEDIUM* pmedium) NVG_PURE;
    virtual long NVG_METHOD QueryGetData(FORMATETC* pformatetc) NVG_PURE;
    virtual long NVG_METHOD GetCanonicalFormatEtc(FORMATETC* pformatectIn, FORMATETC* pformatetcOut) NVG_PURE;
    virtual long NVG_METHOD SetData(FORMATETC* pformatetc, STGMEDIUM* pmedium, int fRelease) NVG_PURE;
    virtual long NVG_METHOD EnumFormatEtc(unsigned dwDirection, IEnumFORMATETC** ppenumFormatEtc) NVG_PURE;
    virtual long NVG_METHOD DAdvise(FORMATETC* pformatetc, unsigned advf, IAdviseSink* pAdvSink, unsigned* pdwConnection) NVG_PURE;
    virtual long NVG_METHOD DUnadvise(unsigned dwConnection) NVG_PURE;
    virtual long NVG_METHOD EnumDAdvise(IEnumSTATDATA** ppenumAdvise) NVG_PURE;
    
};

// Interface ID
NVG_EXPORT_UID(NVG_ID_IDataObject, 0x0000010E, 0x0000, 0x0000, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46);
static const UID& ID_IDataObject = NVG_ID_IDataObject; ///< 0000010E-0000-0000-C000-000000000046
//#define ID_IDataObject NVG_ID_IDataObject

}

#else // C

#endif // __cplusplus

#endif // NVG_IDATAOBJECT_H

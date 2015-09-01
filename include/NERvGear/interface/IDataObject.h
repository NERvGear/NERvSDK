
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

//! Reimplement of standard IDataObject COM interface.
//! It's safe to cast a pointer between NERvGear::IDataObject and ::IDataObject.
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

// declare IDs
NVG_DEFINE_UID(NVG_ID_IDataObject, 0x0000010E, 0x0000, 0x0000, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46); // 0000010e-0000-0000-C000-000000000046

// define aliases
//#define ID_IDataObject NVG_ID_IDataObject
static const UID& ID_IDataObject = NVG_ID_IDataObject;

}

#else // C

#endif // __cplusplus

#endif // NVG_IDATAOBJECT_H

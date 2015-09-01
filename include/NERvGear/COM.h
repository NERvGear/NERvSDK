
/***************************************************************
 * Name:      COM.h
 * Purpose:   Defines COM types compatible with Win32 COM components
 * Author:    GPBeta ()
 * Created:   2014-10-15
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_COM_H
#define NVG_COM_H

#include <NERvGear/basetype.h>

// forward declare
typedef struct _GUID GUID;

namespace NERvGear {

//! GUID UUID CLSID IID re-implement
//! It's safe to cast a pointer between NERvGear::UID and ::GUID.
union UID {
    struct {    // general GUID
        unsigned long  Data1;
        unsigned short Data2;
        unsigned short Data3;
        unsigned char  Data4[8];
    };
    struct {    // x64 optimized
        uint64_t lowPart;
        uint64_t highPart;
    };

    // limited conversion between standard GUID types
    operator GUID&() { return *reinterpret_cast<GUID*>(this); }
    UID& operator =(const GUID& id) { return *this = *reinterpret_cast<const UID*>(&id); }
};

static inline bool operator==(const UID& a, const UID& b)
{
    return a.lowPart == b.lowPart && a.highPart == b.highPart;
}

static inline bool operator!=(const UID& a, const UID& b)
{
    return a.lowPart != b.lowPart || a.highPart != b.highPart;
}

class ModuleContext;

extern struct MODULE {
    long  nActive;
    long  nPrivate;
    long  nLock;
    long  unused;
    ModuleContext* context;
    void* hHandle;
    void* reserved1;
    void* reserved2;
} NVG_MODULE;

// standard COM errors
#ifndef S_OK    // defined in winerror.h
enum {
    S_OK            = 0x00000000L,
    S_FALSE         = 0x00000001L,

    E_UNEXPECTED    = 0x8000FFFFL,
    E_NOTIMPL       = 0x80004001L,
    E_NOINTERFACE   = 0x80004002L,
    E_POINTER       = 0x80004003L,
    E_ABORT         = 0x80004004L,
    E_FAIL          = 0x80004005L,
    E_PENDING       = 0x8000000AL,

    E_ACCESSDENIED  = 0x80070005L,
    E_HANDLE        = 0x80070006L,
    E_OUTOFMEMORY   = 0x8007000EL,
    E_INVALIDARG    = 0x80070057L,

    CLASS_E_NOAGGREGATION = 0x80040110L
};
#endif // S_OK

template <class T>
static inline unsigned long NERvDestroy(T*& object)
{
    if (T* tmp = object) {
        object = 0;
        return tmp->Destroy();
    }

    return 0;
}

template <class T>
static inline unsigned long NERvRelease(T*& object)
{
    if (T* tmp = object) {
        object = 0;
        return tmp->Release();
    }

    return 0;
}

} // NERvGear

// COM-compatible errors
#define NVG_SUCC(_ERR) (_ERR >= 0)
#define NVG_FAIL(_ERR) (_ERR <  0)

#define _NVG_SEVERITY_SUCCESS 0x00000000
#define _NVG_SEVERITY_ERROR   0x80000000

/// \brief Make a custom error code into HRESULT which assign to the COM-compatible interface error code space.
/// Custom error code must be range from 0 to 65023 (0x0 - 0xFDFF).
#define NVG_MAKERESULT(_SEVERITY, _CODE) ((_NVG_SEVERITY_##_SEVERITY | 0x00040200L) + (0xFFFF & _CODE)) // (SEVERITY_ERROR | FACILITY_ITF | 0x0200) + _ERR

// COM-compatible interfaces
#define NVG_INTERFACE(_INTERFACE) struct _INTERFACE
#define NVG_INTERFACE_EXTEND(_INTERFACE, _BASE) struct _INTERFACE : public _BASE

#define NVG_OVERRIDE_INTERFACE_INFO(_CLASS) public: virtual long NVG_METHOD QueryInterface(const ::NERvGear::UID& interfaceID, void** ppvObject);
#define NVG_OVERRIDE_UNKNOWN_INTERFACE(_CLASS) NVG_OVERRIDE_INTERFACE_INFO(_CLASS) \
                                               virtual unsigned long NVG_METHOD AddRef() NVG_PURE; \
                                               virtual unsigned long NVG_METHOD Release() NVG_PURE;
#define NVG_OVERRIDE_UNKNOWN_INTERFACE_EX(_CLASS, _SUPER) NVG_OVERRIDE_INTERFACE_INFO(_CLASS) \
                                                          virtual unsigned long NVG_METHOD AddRef() { return _SUPER::AddRef(); } \
                                                          virtual unsigned long NVG_METHOD Release() { return _SUPER::Release(); }

#define NVG_BEGIN_INTERFACE_INFO(_OBJECT_CLASS) long NVG_METHOD _OBJECT_CLASS::QueryInterface(const UID& interfaceID, void** ppvObject) {
    #define NVG_DECLARE_INTERFACE(_ID, _INTERFACE, _OBJ) if (_ID == interfaceID) { *ppvObject = static_cast<_INTERFACE*>(_OBJ); (_OBJ)->AddRef(); return S_OK; }
    #define NVG_DECLARE_INTERFACE_EX(_ID, _INNER) if (_ID == interfaceID) { return _INNER->QueryInterface(interfaceID, ppvObject); }
#define NVG_END_INTERFACE_INFO() *ppvObject = NULL; return E_NOINTERFACE; }
#define NVG_END_INTERFACE_INFO_EX(_SUPER) return _SUPER::QueryInterface(interfaceID, ppvObject); }

#define NVG_METHOD __stdcall
#define NVG_PURE = 0

// COM-compatible arguments
#define NVG_ARGS_ITF_UID(_ITF)         /*SPACE*/::NERvGear::_ITF, ::NERvGear::NVG_ID_##_ITF
#define NVG_ARGS_ITF_UID_NS(_NS, _ITF) /*SPACE*/::NERvGear::_NS::_ITF, ::NERvGear::_NS::NVG_ID_##_ITF

#endif // NVG_COM_H

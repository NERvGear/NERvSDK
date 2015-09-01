
#ifndef NVG_IUNKNOWN_H
#define NVG_IUNKNOWN_H

#include <NERvGear/def.h>
#include <NERvGear/COM.h>

#ifdef __cplusplus

namespace NERvGear {

//! Reimplement of standard IUnknown COM interface.
//! It's safe to cast a pointer between NERvGear::IUnknown and ::IUnknown.
NVG_INTERFACE(IUnknown) {
    virtual long NVG_METHOD QueryInterface(const UID& interfaceID, void** ppvObject) NVG_PURE;
    virtual unsigned long NVG_METHOD AddRef() NVG_PURE;
    virtual unsigned long NVG_METHOD Release() NVG_PURE;
};

//! Treat as an IUnknown interface for aggregating
NVG_INTERFACE(IPrivateUnknown) {
    virtual long NVG_METHOD PrivateQueryInterface(const UID& interfaceID, void** ppvObject) NVG_PURE;
    virtual unsigned long NVG_METHOD PrivateAddRef() NVG_PURE;
    virtual unsigned long NVG_METHOD PrivateRelease() NVG_PURE;
};

// declare IDs
NVG_DEFINE_UID(NVG_ID_IUnknown, 0x00000000, 0x0000, 0x0000, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46);

// define latest API
// TODO: ID_XXX aliases NVG_ID_XXX #define replacement
// static const UID& ID_IUnknown = NVG_ID_IUnknown; does not work for template parameter
//#define ID_IUnknown NVG_ID_IUnknown
static const UID& ID_IUnknown = NVG_ID_IUnknown;

// minimum implementation for a COM object
class UnknownImpl : public IUnknown {
public:

    virtual unsigned long NVG_METHOD AddRef()
    {
        return NERvSyncIncrement(&m_refCount);
    }

    virtual unsigned long NVG_METHOD Release()
    {
        if (NERvSyncDecrement(&m_refCount) == 0) {
            delete this;
            return 0;
        }

        return m_refCount;
    }

    virtual long NVG_METHOD QueryInterface(const UID& interfaceID, void** ppvObject)
    {
        if (interfaceID == ID_IUnknown) {
            *ppvObject = static_cast<IUnknown*>(this);
            AddRef();
            return S_OK;
        }

        *ppvObject = NULL;
        return E_NOINTERFACE;
    }

    UnknownImpl() : m_refCount(1) { NERvSyncIncrement(&NVG_MODULE.nPrivate); /* Increase private component count */ }
    virtual ~UnknownImpl() { NERvSyncDecrement(&NVG_MODULE.nPrivate); /* Decrease private component count */ }

private:

    long m_refCount;
};


}

#else // C

#endif // __cplusplus

#endif // NVG_IUNKNOWN_H

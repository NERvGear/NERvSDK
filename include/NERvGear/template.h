
/***************************************************************
 * Name:      template.h
 * Purpose:   Defines Nerve Gear Templates
 * Author:    GPBeta ()
 * Created:   2014-10-25
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_TEMPLATE_H
#define NVG_TEMPLATE_H

#include <NERvGear/new.h>
#include <NERvGear/interface/IObjectFactory.h>

namespace NERvGear {

template <class T, const UID& I>
class ImplT : public T {
public:

    virtual long NVG_METHOD QueryInterface(const UID& interfaceID, void** ppvObject)
    {
        if (interfaceID == ID_IUnknown || interfaceID == I) {
            *ppvObject = static_cast<T*>(this);
            AddRef();
            return S_OK;
        }

        *ppvObject = NULL;
        return E_NOINTERFACE;
    }

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

    ImplT() : m_refCount(1) { NERvSyncIncrement(&NVG_MODULE.nPrivate); /* Increase private component count */ }
    virtual ~ImplT() { NERvSyncDecrement(&NVG_MODULE.nPrivate); /* Decrease private component count */ }

private:

    volatile long m_refCount;
};

// aggregate interface implement template

template <class T>
class AggregateT : public T {
public:

    virtual long NVG_METHOD QueryInterface(const UID& interfaceID, void** ppvObject)
    {
        return m_outer->QueryInterface(interfaceID, ppvObject);
    }

    virtual unsigned long NVG_METHOD AddRef()
    {
        return m_outer->AddRef();
    }

    virtual unsigned long NVG_METHOD Release()
    {
        return m_outer->Release();
    }

    AggregateT(IUnknown* outer) : m_outer(outer) {}
    virtual ~AggregateT() {}

    IUnknown* m_outer;
};

template <class T, const UID& I>
class InnerT : public AggregateT<T> {
public:

    virtual long NVG_METHOD QueryInterface(const UID& interfaceID, void** ppvObject)
    {
        if (interfaceID == ID_IUnknown || interfaceID == I) {
            *ppvObject = static_cast<T*>(this);
            AggregateT<T>::m_outer->AddRef();
            return S_OK;
        }

        *ppvObject = NULL;
        return E_NOINTERFACE;
    }

    InnerT(IUnknown* outer) : AggregateT<T>(outer) {}
};

template <class T>
class NerveObjectBaseT {
public:
    NerveObjectBaseT(MODULE* module) : m_refCount(0), m_refModule(module)
    {
        // Increment count of active components.
        NERvSyncIncrement(&NVG_MODULE.nActive);
        NERvTraceObject(m_refModule, T::STATIC_OBJECT_INFO.objectID, 1);
    }
    ~NerveObjectBaseT()
    {
        // Decrement count of active components.
        NERvSyncDecrement(&NVG_MODULE.nActive);
        NERvTraceObject(m_refModule, T::STATIC_OBJECT_INFO.objectID, -1);
    }

    volatile long m_refCount;
    MODULE* m_refModule;
};

template <class T, bool AGGREGATABLE> class NerveObjectT {};

template <class T>
class NerveObjectT<T, true> : public NerveObjectBaseT<T>, public AggregateT<T>, public IPrivateUnknown {
public:

    // NOTE: for debug use, declare functions below as pure virtual if needed

    virtual MODULE*       NVG_METHOD GetReferenceModule() const { return NerveObjectBaseT<T>::m_refModule; }
    virtual unsigned long NVG_METHOD GetReferenceCount() const { return NerveObjectBaseT<T>::m_refCount; }

    // implement IPrivateUnknown

    virtual long NVG_METHOD PrivateQueryInterface(const UID& interfaceID, void** ppvObject)
    {
        if (interfaceID == ID_IUnknown) {
            *ppvObject = static_cast<IPrivateUnknown*>(this);
            reinterpret_cast<IUnknown*>(*ppvObject)->AddRef();
            return S_OK;
        }

        return T::QueryInterface(interfaceID, ppvObject);
    }

    virtual unsigned long NVG_METHOD PrivateAddRef()
    {
        return NERvSyncIncrement(&(NerveObjectBaseT<T>::m_refCount));
    }

    virtual unsigned long NVG_METHOD PrivateRelease()
    {
        if (NERvSyncDecrement(&(NerveObjectBaseT<T>::m_refCount)) == 0) {
            delete this;
            return 0;
        }

        return NerveObjectBaseT<T>::m_refCount;
    }

    NerveObjectT(MODULE* module, IUnknown* outer) :
        NerveObjectBaseT<T>(module), AggregateT<T>(outer ? outer : reinterpret_cast<IUnknown*>(static_cast<IPrivateUnknown*>(this))) {}
};

template <class T>
class NerveObjectT<T, false> : public NerveObjectBaseT<T>,  public T {
public:

    // NOTE: for debug use, declare functions below as pure virtual if needed

    virtual MODULE*       NVG_METHOD GetReferenceModule() const { return NerveObjectBaseT<T>::m_refModule; }
    virtual unsigned long NVG_METHOD GetReferenceCount() const { return NerveObjectBaseT<T>::m_refCount; }

    // implement IUnknown

    virtual unsigned long NVG_METHOD AddRef()
    {
        return NERvSyncIncrement(&(NerveObjectBaseT<T>::m_refCount));
    }

    virtual unsigned long NVG_METHOD Release()
    {
        if (NERvSyncDecrement(&(NerveObjectBaseT<T>::m_refCount)) == 0) {
            delete this;
            return 0;
        }

        return NerveObjectBaseT<T>::m_refCount;
    }

    NerveObjectT(MODULE* module) : NerveObjectBaseT<T>(module) {}

};

class NerveFactoryBase : public IObjectFactory {
public:

    // implement IClassFactory

    virtual long NVG_METHOD CreateInstance(IUnknown* unknownOuter, const UID& interfaceID, void** ppvObject)
    {
        return CreateInstanceEx(&NVG_MODULE, unknownOuter, interfaceID, ppvObject);
    }

    virtual long NVG_METHOD LockServer(bool lock)
    {
        if (lock)
            NERvSyncIncrement(&NVG_MODULE.nLock);
        else
            NERvSyncDecrement(&NVG_MODULE.nLock);

        return S_OK;
    }

    // implement IUnknown

    long NVG_METHOD QueryInterface(const UID& interfaceID, void** ppvObject)
    {
        if (interfaceID == ID_IObjectFactory || interfaceID == ID_IClassFactory || interfaceID == ID_IUnknown) {
            *ppvObject = static_cast<IObjectFactory*>(this);
            AddRef();
            return S_OK;
        }

        *ppvObject = NULL;

        return E_NOINTERFACE;
    }

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

    NerveFactoryBase() : m_refCount(1) {}
    virtual ~NerveFactoryBase() {}

    volatile long m_refCount;

};

template <class T>
static inline long PrivateCreateInstance(MODULE* refModule, const UID& interfaceID, void** ppvObject, T*& ppt)
{
    if (NerveObjectT<T, false>* object = nvg_new NerveObjectT<T, false>(refModule)) {
        long res = object->QueryInterface(interfaceID, ppvObject);

        if (NVG_SUCC(res)) {
            ppt = static_cast<T*>(object);
            return res;
        }

        // failed
        ppvObject = NULL;
        ppt = NULL;
        delete object;
    } else { return E_OUTOFMEMORY; }

    return E_FAIL;
}

template <class T>
static inline long PrivateCreateInstance(MODULE* refModule, IUnknown* unknownOuter, const UID& interfaceID, void** ppvObject, T*& ppt)
{
    if (unknownOuter && interfaceID != ID_IUnknown)
        return CLASS_E_NOAGGREGATION;

    if (NerveObjectT<T, true>* object = nvg_new NerveObjectT<T, true>(refModule, unknownOuter)) {
        long res = object->PrivateQueryInterface(interfaceID, ppvObject);

        if (NVG_SUCC(res)) {
            ppt = static_cast<T*>(object);
            return res;
        }

        // failed
        ppvObject = NULL;
        ppt = NULL;
        delete object;
    } else { return E_OUTOFMEMORY; }

    return E_FAIL;
}


template <class T, bool AGGREGATABLE> class NerveFactoryT {};

template <class T>
class NerveFactoryT<T, true> : public NerveFactoryBase {
public:

    virtual long NVG_METHOD CreateInstanceEx(MODULE* refModule, IUnknown* unknownOuter, const UID& interfaceID, void** ppvObject)
    {
        T* unused;
        return PrivateCreateInstance<T>(refModule, unknownOuter, interfaceID, ppvObject, unused);
    }

    virtual const OBJECT_INFO& NVG_METHOD GetInfo() const { return T::STATIC_OBJECT_INFO; }
};

template <class T>
class NerveFactoryT<T, false> : public NerveFactoryBase {
public:
    virtual long NVG_METHOD CreateInstanceEx(MODULE* refModule, IUnknown* unknownOuter, const UID& interfaceID, void** ppvObject)
    {
        if (unknownOuter)
            return CLASS_E_NOAGGREGATION;

        T* unused;

        return PrivateCreateInstance<T>(refModule, interfaceID, ppvObject, unused);
    }

    virtual const OBJECT_INFO& NVG_METHOD GetInfo() const { return T::STATIC_OBJECT_INFO; }
};

}

#endif // NVG_TEMPLATE_H

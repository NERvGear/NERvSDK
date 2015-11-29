
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
class ObjectBaseT {
public:
    ObjectBaseT(MODULE* module) : m_refCount(0), m_refModule(module)
    {
        // Increment count of active components.
        NERvSyncIncrement(&NVG_MODULE.nActive);
        NERvTraceObject(m_refModule, T::STATIC_OBJECT_INFO.objectID, 1);
    }
    ~ObjectBaseT()
    {
        // Decrement count of active components.
        NERvSyncDecrement(&NVG_MODULE.nActive);
        NERvTraceObject(m_refModule, T::STATIC_OBJECT_INFO.objectID, -1);
    }

    volatile long m_refCount;
    MODULE* m_refModule;
};

template <class T, bool AGGREGATABLE> class ObjectT {};

template <class T>
class ObjectT<T, true> : public ObjectBaseT<T>, public AggregateT<T>, public IPrivateUnknown {

    // NOTE: silence warning C4355 on constructor initializing AggregateT<T>
    IUnknown* GetOuter(IUnknown* outer) { return outer ? outer : reinterpret_cast<IUnknown*>(static_cast<IPrivateUnknown*>(this)); }

public:

    // NOTE: for debug use, declare functions below as pure virtual if needed

    virtual MODULE*       NVG_METHOD GetReferenceModule() const { return ObjectBaseT<T>::m_refModule; }
    virtual unsigned long NVG_METHOD GetReferenceCount() const { return ObjectBaseT<T>::m_refCount; }

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
        return NERvSyncIncrement(&(ObjectBaseT<T>::m_refCount));
    }

    virtual unsigned long NVG_METHOD PrivateRelease()
    {
        if (NERvSyncDecrement(&(ObjectBaseT<T>::m_refCount)) == 0) {
            delete this;
            return 0;
        }

        return ObjectBaseT<T>::m_refCount;
    }

    ObjectT(MODULE* module, IUnknown* outer) :
        ObjectBaseT<T>(module), AggregateT<T>(GetOuter(outer)) {}
};

template <class T>
class ObjectT<T, false> : public ObjectBaseT<T>, public T {
public:

    // NOTE: for debug use, declare functions below as pure virtual if needed

    virtual MODULE*       NVG_METHOD GetReferenceModule() const { return ObjectBaseT<T>::m_refModule; }
    virtual unsigned long NVG_METHOD GetReferenceCount() const { return ObjectBaseT<T>::m_refCount; }

    // implement IUnknown

    virtual unsigned long NVG_METHOD AddRef()
    {
        return NERvSyncIncrement(&(ObjectBaseT<T>::m_refCount));
    }

    virtual unsigned long NVG_METHOD Release()
    {
        if (NERvSyncDecrement(&(ObjectBaseT<T>::m_refCount)) == 0) {
            delete this;
            return 0;
        }

        return ObjectBaseT<T>::m_refCount;
    }

    ObjectT(MODULE* module) : ObjectBaseT<T>(module) {}

};

class ObjectFactoryBase : public IObjectFactory {
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

    ObjectFactoryBase() : m_refCount(1) {}
    virtual ~ObjectFactoryBase() {}

    volatile long m_refCount;

};

template <class T>
static inline long PrivateCreateInstance(MODULE* refModule, const UID& interfaceID, void** ppvObject, T*& ppt)
{
    long res = E_OUTOFMEMORY;

    if (ObjectT<T, false>* object = nvg_new ObjectT<T, false>(refModule)) {
        // extra construction
        if (NVG_SUCC((res = object->OnCreate(refModule, NULL, interfaceID, ppvObject)))) {
            if (NVG_SUCC((res = object->QueryInterface(interfaceID, ppvObject)))) {
                ppt = static_cast<T*>(object);
                return res;
            }
        }

        // failed
        *ppvObject = NULL;
        ppt = NULL;
        delete object;
    }

    return res;
}

template <class T>
static inline long PrivateCreateInstance(MODULE* refModule, IUnknown* unknownOuter, const UID& interfaceID, void** ppvObject, T*& ppt)
{
    if (unknownOuter && interfaceID != ID_IUnknown)
        return CLASS_E_NOAGGREGATION;

    long res = E_OUTOFMEMORY;

    if (ObjectT<T, true>* object = nvg_new ObjectT<T, true>(refModule, unknownOuter)) {
        // extra construction
        if (NVG_SUCC((res = object->OnCreate(refModule, unknownOuter, interfaceID, ppvObject)))) {
            if (NVG_SUCC((res = object->PrivateQueryInterface(interfaceID, ppvObject)))) {
                ppt = static_cast<T*>(object);
                return res;
            }
        }

        // failed
        *ppvObject = NULL;
        ppt = NULL;
        delete object;
    }

    return res;
}

template <class T, bool AGGREGATABLE> class ObjectFactoryT {};

template <class T>
class ObjectFactoryT<T, true> : public ObjectFactoryBase {
public:

    virtual long NVG_METHOD CreateInstanceEx(MODULE* refModule, IUnknown* unknownOuter, const UID& interfaceID, void** ppvObject)
    {
        T* object;

        return PrivateCreateInstance<T>(refModule, unknownOuter, interfaceID, ppvObject, object);
    }

    virtual const OBJECT_INFO& NVG_METHOD GetInfo() const { return T::STATIC_OBJECT_INFO; }
};

template <class T>
class ObjectFactoryT<T, false> : public ObjectFactoryBase {
public:
    virtual long NVG_METHOD CreateInstanceEx(MODULE* refModule, IUnknown* unknownOuter, const UID& interfaceID, void** ppvObject)
    {
        if (unknownOuter)
            return CLASS_E_NOAGGREGATION;

        T* object;

        return PrivateCreateInstance<T>(refModule, interfaceID, ppvObject, object);
    }

    virtual const OBJECT_INFO& NVG_METHOD GetInfo() const { return T::STATIC_OBJECT_INFO; }
};

}

#endif // NVG_TEMPLATE_H

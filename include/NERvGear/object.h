
/***************************************************************
 * Name:      object.h
 * Purpose:   Defines Nerve Gear Object APIs
 * Author:    GPBeta ()
 * Created:   2014-10-22
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_OBJECT_H
#define NVG_OBJECT_H

#include <NERvGear/COM.h>
#include <NERvGear/version.h>

#include <NERvGear/interface/IObjectFactory.h>

namespace NERvGear {

// Override your own OnCreate() for the object to get extra construction.
#define NVG_DECLARE_OBJECT_BASE(_OBJECT_CLASS) public: \
    virtual long NVG_METHOD QueryInterface(const ::NERvGear::UID& interfaceID, void** ppvObject); \
    static const ::NERvGear::OBJECT_INFO STATIC_OBJECT_INFO;

#define NVG_DECLARE_OBJECT(_OBJECT_CLASS) public: \
    long OnCreate(::NERvGear::MODULE* module, ::NERvGear::IUnknown* outer, const ::NERvGear::UID& iid, void** ppv) { return 0; } \
    NVG_DECLARE_OBJECT_BASE(_OBJECT_CLASS)

#define NVG_BEGIN_OBJECT_INFO(_OBJECT_CLASS) const OBJECT_INFO _OBJECT_CLASS::STATIC_OBJECT_INFO = { {NVS_VER_REV},
    #define NVG_DECLARE_OBJECT_CLASSID_UID(_ID) _ID,
    #define NVG_DECLARE_OBJECT_CLASSID(_D1, _D2, _D3, _D41, _D42, _D43, _D44, _D45, _D46, _D47, _D48) \
                                      {_D1, _D2, _D3, {_D41, _D42, _D43, _D44, _D45, _D46, _D47, _D48}},
    #define NVG_DECLARE_OBJECT_OBJECTID_UID(_ID) _ID,
    #define NVG_DECLARE_OBJECT_OBJECTID(_D1, _D2, _D3, _D41, _D42, _D43, _D44, _D45, _D46, _D47, _D48) \
                                       {_D1, _D2, _D3, {_D41, _D42, _D43, _D44, _D45, _D46, _D47, _D48}},
    #define NVG_DECLARE_OBJECT_VERSION(_MAJOR, _MINOR, _SUBMINOR) NVG_DECLARE_VERSION(_MAJOR, _MINOR, _SUBMINOR, 0),
    #define NVG_DECLARE_OBJECT_NAME(_NAME)                        NVG_TEXT(_NAME),
    #define NVG_DECLARE_OBJECT_DESCRIP(_DESCRIP)                  NVG_TEXT(_DESCRIP),
#define NVG_END_OBJECT_INFO() NULL};

// declaration

struct OBJECT_INFO {
    VERSION sdk_version;

    UID classID;
    UID objectID;
    VERSION version;

    const wchar_t* name;
    const wchar_t* descrip;

    void* reserved;
};

enum {
    E_OBJECT_NOT_FOUND  = NVG_MAKERESULT(ERROR, 1),
    E_OBJECT_DUPLICATED = NVG_MAKERESULT(ERROR, 2)
};

NVG_EXPORT(void) NERvTraceObject(MODULE* refModule, const UID& objectID, int n);
NVG_EXPORT(long) NERv1CreateObject(const UID& classID, const UID& objectID, const UID& interfaceID, IUnknown* unknownOuter, void** ppvObject, MODULE* module);
NVG_EXPORT(long) NERv1RegisterObject(const UID& classID, const UID& objectID, IObjectFactory* objectFactory, MODULE* module);
NVG_EXPORT(long) NERv1UnregisterObject(const UID& classID, const UID& objectID, MODULE* module);

// latest APIs

/// \ingroup mod_function
/// @{

/// \brief Find and create an object instance of specified component.
///
/// \param [in]  classID     The UID of a component.
/// \param [in]  objectID    The UID of a component object. If ID_NULL,
///                          system will find a default implementation for this component.
/// \param [in]  interfaceID The UID of an interface.
/// \param [in]  outer       A pointer to the aggregate object's IUnknown interface (the controlling IUnknown).
/// 	                     This parameter could be NULL, indicates that the object is not being created as part of an aggregate. 
/// \param [out] object      Address of pointer that receives the interface pointer requested in \a interfaceID.
/// \retval S_OK                  Success. An instance of the specified component object was successfully created.
/// \retval CLASS_E_NOAGGREGATION Fail. A specified object cannot be created as part of an aggregate.
/// \retval E_OBJECT_NOT_FOUND    Fail. A specified object is not registered in the component object database.
/// \retval E_NOINTERFACE         Fail. A specified class does not implement the requested interface,
/// 	                          or the controlling IUnknown does not expose the requested interface.
/// \retval E_INVALIDARG          Fail. one or more parameters are invalid.
/// \retval E_FAIL                Failed with unknown error.
///
/// \version
///     0.1.0 NERv1CreateObject()
/// \see
/// 	NERvRegisterObject(), NERvUnregisterObject()
///
/// \header{NERvGear/object.h}
static inline long NERvCreateObject(const UID& classID, const UID& objectID, const UID& interfaceID, IUnknown* outer, void** object)
{ return NERv1CreateObject(classID, objectID, interfaceID, outer, object, &NVG_MODULE); }

/// \brief Register an object to the component object database.
///
/// \todo
///     Add object registration macro document.
///
/// \param [in]  classID  The UID of a component.
/// \param [in]  objectID The UID of a component object.
/// \param [in]  factory  A pointer to the IObjectFactory interface of an object factory.
/// \retval S_OK                Success. The component object was successfully registered.
/// \retval E_OBJECT_DUPLICATED Fail. A specified object is already registered in the component object database.
/// \retval E_INVALIDARG        Fail. The \a factory is NULL.
/// \retval E_FAIL              Failed with unknown error.
///
/// \version
/// 	0.1.0 NERv1RegisterObject()
/// \see
/// 	NERvUnregisterObject(), NERvCreateObject()
///
/// \header{NERvGear/object.h}
static inline long NERvRegisterObject(const UID& classID, const UID& objectID, IObjectFactory* factory)
{ return NERv1RegisterObject(classID, objectID, factory, &NVG_MODULE); }

/// \brief Unregister an object from the component object database.
///
/// \param [in]  classID  The UID of a component.
/// \param [in]  objectID The UID of a component object.
/// \retval S_OK               Success. The component object was successfully unregistered.
/// \retval E_OBJECT_NOT_FOUND Fail. A specified object is not registered in the component object database.
/// \retval E_FAIL             Failed with unknown error.
///
/// \version
/// 	0.1.0 NERv1UnregisterObject()
/// \see
/// 	NERvRegisterObject(), NERvCreateObject()
///
/// \header{NERvGear/object.h}
static inline long NERvUnregisterObject(const UID& classID, const UID& objectID)
{ return NERv1UnregisterObject(classID, objectID, &NVG_MODULE); }


/// @}


}

#endif // NVG_OBJECT_H

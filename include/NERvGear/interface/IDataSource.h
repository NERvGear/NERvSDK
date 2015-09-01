
#ifndef NVG_IDATASOURCE_H
#define NVG_IDATASOURCE_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

struct IData;

/// Nerve Gear data source interface.
NVG_INTERFACE_EXTEND(IDataSource, IUnknown) {

    /// Retrieve the UID of this data source object.
    ///
    /// \param [out] id Pointer to a UID, must not be NULL.
    /// \retval S_OK Success.
    /// \retval E_INVALIDARG Failed, the id parameter is NULL.
    /// \retval E_FAIL Failed with unknown error.
    ///
    /// \note The returned ID must be the same as the object ID specified in the object declaration.
    /// \todo Document for Object Declaration.
    virtual long NVG_METHOD GetId(UID* id) NVG_PURE;    // source id



    /// Retrieve the display name for this data source.
    ///
    /// \param [in]  len The size of the name buffer, in characters. If name is NULL, this parameter must be 0.
    /// \param [out] name A pointer to a buffer that receives the null terminated string for the display name, could be NULL.
    /// \return Returns the size copied into the name buffer, in characters.
    /// If the name is not NULL, the return value is the length of the string that is copied to the buffer, in characters,
    /// not including the terminating null character.
    /// If the buffer is too small to hold the name, the string is truncated to len characters including the terminating null character,
    /// the function returns len.
    /// If the name is NULL and len is 0, the return value is the length of the string buffer required, in characters.
    /// If the function fails, the return value is 0.
    virtual size_t NVG_METHOD GetName(size_t len, wchar_t* name) NVG_PURE;

    /// Retrieve the description for this data source.
    ///
    /// \see See IDataSource::GetName() for more details about parameters and return values.
    virtual size_t NVG_METHOD GetDescrip(size_t len, wchar_t* descrip) NVG_PURE;

    /// Retrieve the number of data providing by this data source.
    virtual unsigned NVG_METHOD GetDataCount() NVG_PURE;



    /// Retrieve a data represented by index.
    ///
    /// \param [in]  index A zero based number identifying a data locally.
    /// \param [out] data A pointer to a buffer receiving the IData pointer.
    /// \retval S_OK Success.
    /// \retval E_INVALIDARG Failed, the index parameter is invalid or the data parameter is NULL.
    /// \retval E_FAIL Failed with unknown error.
    virtual long NVG_METHOD GetData(unsigned index, IData** data) NVG_PURE;

    /// Retrieve a data indicated by UID.
    ///
    /// \param [in]  id A UID reference associating with a data.
    ///
    /// \see See IDataSource::GetData() for more details about parameters and return values.
    /// \see See also IData::GetId().
    virtual long NVG_METHOD FindData(const UID& id, IData** data) NVG_PURE;

};

// declare IDs
NVG_DEFINE_UID(NVG_ID_CDataSource, CATALOG::CORE_COMMON, 0x4300, 0x6144, 0x74, 0x61, 0x53, 0x6F, 0x75, 0x72, 0x63, 0x65); // "CDataSource"
NVG_DEFINE_UID(NVG_ID_ODataSource,           0x00000001, 0x4F00, 0x6144, 0x74, 0x61, 0x53, 0x6F, 0x75, 0x72, 0x63, 0x65); // "ODataSource" version 1
NVG_DEFINE_UID(NVG_ID_IDataSource,           0x00000001, 0x4900, 0x6144, 0x74, 0x61, 0x53, 0x6F, 0x75, 0x72, 0x63, 0x65); // "IDataSource" version 1

// define aliases
//#define ID_CDataSource NVG_ID_CDataSource
//#define ID_ODataSource NVG_ID_ODataSource
//#define ID_IDataSource NVG_ID_IDataSource
static const UID& ID_CDataSource = NVG_ID_CDataSource;
static const UID& ID_ODataSource = NVG_ID_ODataSource;
static const UID& ID_IDataSource = NVG_ID_IDataSource;


} // NERvGear

#else // C

#endif // __cplusplus

#endif // NVG_IDATASOURCE_H

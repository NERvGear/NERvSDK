
/***************************************************************
 * Name:      IDataSource.h
 * Purpose:   Defines Data Source Interface
 * Author:    GPBeta ()
 * Created:   2015-05-20
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_IDATASOURCE_H
#define NVG_IDATASOURCE_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

struct IData;

/// \ingroup mod_itf_nvg
///
/// \brief Nerve Gear data source interface.
///
/// \declid{Interface,NERvGear::ID_IDataSource,00000001-4900-6144-7461-536f75726365}
NVG_INTERFACE_EXTEND(IDataSource, IUnknown) {

    /// Retrieves the UID of this data source object.
    ///
    /// \param [out] id Pointer to a UID, must not be NULL.
    /// \retval S_OK         Success.
    /// \retval E_INVALIDARG Fail. The \a id is NULL.
    /// \retval E_FAIL       Failed with unknown error.
    ///
    /// \note
    ///     The returned ID must be the same as the object ID specified in the object declaration.
    virtual long NVG_METHOD GetId(UID* id) NVG_PURE;    // source id



    /// Retrieves the display name for this data source.
    ///
    /// \param [in]  len  The size of the name buffer, in characters. If \a name is NULL, this parameter must be 0.
    /// \param [out] name A pointer to a buffer that receives the null terminated string for the display name, could be NULL.
    /// \return
    ///     Returns the size copied into the \a name buffer, in characters.\n
    ///     If \a name is not NULL, the return value is the length of the string that is copied to the buffer, in characters,
    /// not including the terminating null character.\n
    ///     If \a name buffer is too small to hold the name, the string is truncated to \a len characters including the terminating null character,
    /// and the return value is \a len.\n
    ///     If \a name is NULL and \a len is 0, the return value is the length of the string buffer required, in characters,
    /// including the terminating null character.\n
    ///     If the function fails, the return value is 0.
    ///
    /// \see
    ///     NERvCopyString()
    virtual size_t NVG_METHOD GetName(size_t len, wchar_t* name) NVG_PURE;

    /// Retrieves the description for this data source.
    ///
    /// \remark
    ///     See IDataSource::GetName() for more details about parameters and return values.
    virtual size_t NVG_METHOD GetDescrip(size_t len, wchar_t* descrip) NVG_PURE;

    /// Retrieves the number of data providing by this data source.
    virtual unsigned NVG_METHOD GetDataCount() NVG_PURE;



    /// Retrieves a data represented by index.
    ///
    /// \param [in]  index A zero based number identifying a data locally.
    /// \param [out] data  A pointer to a buffer receiving the IData pointer.
    /// \retval S_OK         Success.
    /// \retval E_INVALIDARG Fail. The \a index is invalid or the data parameter is NULL.
    /// \retval E_FAIL       Failed with unknown error.
    virtual long NVG_METHOD GetData(unsigned index, IData** data) NVG_PURE;

    /// Retrieves a data indicated by UID.
    ///
    /// \param [in]  id A UID reference associating with a data.
    /// \param [out] data  A pointer to a buffer receiving the IData pointer.
    ///
    /// \remark
    ///     See IDataSource::GetData() for more details about parameters and return values.
    ///
    /// \see
    ///     IData::GetId()
    virtual long NVG_METHOD FindData(const UID& id, IData** data) NVG_PURE;

};

// Interface ID
NVG_EXPORT_UID(NVG_ID_IDataSource, 0x00000001, 0x4900, 0x6144, 0x74, 0x61, 0x53, 0x6F, 0x75, 0x72, 0x63, 0x65);
static const UID& ID_IDataSource = NVG_ID_IDataSource; ///< "IDataSource" version 1
//#define ID_IDataSource NVG_ID_IDataSource


} // NERvGear

#else // C

#endif // __cplusplus

#endif // NVG_IDATASOURCE_H

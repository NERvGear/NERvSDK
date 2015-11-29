
/***************************************************************
 * Name:      IData.h
 * Purpose:   Defines IData Interface
 * Author:    GPBeta ()
 * Created:   2015-05-20
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_IDATA_H
#define NVG_IDATA_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

struct IEventHandler;
struct IDataSource;

namespace UI {

struct IWindow;

} // UI

/// \declns{NERvGear::DATA}
namespace DATA {


/// \brief Available data types for NERvGear::IData.
///
/// \note
/// -# Numeric types could be in different sizes.
/// -# Always use wide CHARACTER / STRING for character or string data for international compatibilities.
enum TYPE {
    INVALID         = -1,
    NONE            = 0,

    NUMERIC_FIRST   = 1,
    INTEGER         = 1,    //!< int8, int16, int32, int64 types
    UNSIGNED,               //!< uint8, uint16, uint32, uint64 types
    FLOAT,                  //!< float, double types
    BOOLEAN,                //!< bool equipment
    ENUMERATOR,             //!< enums
    NUMERIC_LAST    = 100,

    CHARACTER_FIRST = 101,
    CHARACTER       = 101,  //!< wchar_t equipment
    CHAR_ASCII,             //!< char equipment
    CHAR_CP,                //!< code page characters start here, CHAR_CP + enum value of ENCODING::TYPE.
    CHARACTER_LAST  = 200,

    STRING_FIRST    = 201,
    STRING          = 201,  //!< wchar_t* null-terminated C string equipment
    STR_ASCII,              //!< char* null-terminated C string equipment
    STR_CP,                 //!< code page strings start here, STR_CP + enum value of ENCODING::TYPE.
    STRING_LAST     = 300,

    MISCELLANEOUS_FIRST = 301,
    MISC_VERSION,           // Version
    MISC_UID,               // UID
    MISCELLANEOUS_LAST  = 500,

    RAW             = 1000,

    INTERFACE_FIRST = 5001,
    IF_UNKNOWN,             // IUnknown
    IF_DATA,                // IData
    IF_DATASOURCE,          // IDataSource
    INTERFACE_LAST  = 10000,

    CUSTOM_FIRST    = 0x00010000,   //!< custom data types start here
    CUSTOM_LAST     = 0x00FFFFFF,   //!< custom data types end here

    TYPE_MASK       = 0x00FFFFFF,
    FLAG_ARRAY      = 0x01000000,
    FLAG_POINTER    = 0x02000000    //!< data returned is a pointer of one data type
};

/// Predefined value modes.
enum MODE { CURRENT, INVERSE, MAXIMUM, MINIMUM };

/// Configuration types.
enum CONFIG { NO_CFG, UPDATE, INVOKE };

} // DATA

/// \ingroup mod_itf_nvg
///
/// \brief Nerve Gear data interface.
///
/// \note
///     Any index parameters for member functions are zero-based.
///
/// \see
///     NERvGear::IDataSource
///
/// \declid{Interface,NERvGear::ID_IData,00000001-0000-0000-0000-004944617461}
NVG_INTERFACE_EXTEND(IData, IUnknown) {
        
    /// Retrieves the UID of this data object.
    ///
    /// \param [out] id Pointer to a UID, must not be NULL.
    /// \retval S_OK         Success.
    /// \retval E_INVALIDARG Fail. The \a id is NULL.
    /// \retval E_FAIL       Failed with unknown error.
    ///
    /// \note
    ///     An ID of a data is unique for one data and must be different from any other data.
    ///
    /// \see
    ///     IDataSource::FindData()
    virtual long NVG_METHOD GetId(UID* id) NVG_PURE;


    
    /// Retrieves the display name for this data.
    ///
    /// \param [in]  len  The size of \a name buffer, in characters. If \a name is NULL, this parameter must be 0.
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

    /// Retrieves the description for this data.
    ///
    /// \remark
    ///     See GetName() for more details about parameters and return values.
    virtual size_t NVG_METHOD GetDescrip(size_t len, wchar_t* descrip) NVG_PURE;

    /// Retrieves the source providing this data.
    ///
    /// \param [out] source A pointer to a buffer receiving the IDataSource pointer.
    /// \retval S_OK         Success.
    /// \retval E_INVALIDARG Fail. The \a source is NULL.
    /// \retval E_FAIL       Failed with unknown error.
    ///
    /// \note
    ///     The queried source must be the same object creating this data.
    virtual long NVG_METHOD QuerySource(IDataSource** source) NVG_PURE;



    /// Retrieves the number of values providing by this data.
    virtual unsigned NVG_METHOD GetValueCount() NVG_PURE;



    /// Retrieves an current value of this data.
    ///
    /// \param [in]  index A zero based number represents the value to get.
    /// \param [in]  nbyte The buffer size of \a buf, in bytes. If \a buf is NULL, this parameter must be 0.
    /// \param [out] buf   A pointer to the buffer receiving a value, could be NULL.
    /// \return
    ///     Returns the size copied into the buffer, in bytes.\n
    ///     If \a buf is NULL and \a nbyte is 0, the return value is the buffer size required to store the value, in bytes.\n
    ///     If the data does not have specified value, the return value is 0.
    ///
    /// \remark
    ///     You should Update() before any calls to GetValue(), GetMaximum(), GetMinimum() to confirm values are up to date.
    virtual size_t NVG_METHOD GetValue(unsigned index, size_t nbyte, void* buf) NVG_PURE;

    /// Retrieves an maximum value of this data.
    ///
    /// \remark
    ///     See GetValue() for more details about parameters and return values.
    virtual size_t NVG_METHOD GetMaximum(unsigned index, size_t nbyte, void* buf) NVG_PURE;

    /// Retrieves an minimum value of this data.
    ///
    /// \remark
    ///     See GetValue() for more details about parameters and return values.
    virtual size_t NVG_METHOD GetMinimum(unsigned index, size_t nbyte, void* buf) NVG_PURE;



    /// Retrieves the index of a data value.
    ///
    /// \param [in]  id A number represent a data value in public.
    /// \return
    ///     Returns a zero based number privately represent a data value.
    /// \retval NVG_ANY Fail. The \a id is invalid.
    ///
    /// \remark
    ///     Call GetValueId() to retrieve the id of a data value.
    virtual unsigned NVG_METHOD GetValueIndex(int id) NVG_PURE;

    /// Retrieves the ID of a data value.
    ///
    /// \return
    ///     Returns a number locally represent a data value.
    /// \retval NVG_ANY Fail. The \a index is invalid.
    ///
    /// \remark
    ///     Call GetValueIndex() to retrieve the index of a data value with an ID.
    ///
    /// \note
    ///     The ID returned by this function should identify a data value locally in a data space.
    ///     Once an ID is bond to a value and published, the ID of one value should not be changed,
    ///     while the index of a value could be changed if necessary in the future.
    virtual int NVG_METHOD GetValueId(unsigned index) NVG_PURE;

    /// Retrieves the data type of a data value.
    ///
    /// \return
    ///     Returns a data type which may be one of the enumeration values of NERvGear::DATA::TYPE.
    ///
    /// \note
    ///     The type of the value could be changed after a call on Update(),
    /// so you should check value type every time you update a value if you're not sure.
    virtual DATA::TYPE NVG_METHOD GetValueType(unsigned index) NVG_PURE;

    /// Retrieves the current unit of a data value.
    ///
    /// \remark
    ///     See GetName() for more details about parameters and return values.
    virtual size_t NVG_METHOD GetValueUnit(unsigned index, size_t len, wchar_t* unit) NVG_PURE;

    /// Retrieves the display name for a data value.
    ///
    /// \remark
    ///     See GetName() for more details about parameters and return values.
    virtual size_t NVG_METHOD GetValueName(unsigned index, size_t len, wchar_t* name) NVG_PURE;

    /// Retrieves the display name for a data value.
    ///
    /// \remark
    ///     See GetName() for more details about parameters and return values.
    virtual size_t NVG_METHOD GetValueDescrip(unsigned index, size_t len, wchar_t* descrip) NVG_PURE;



    /// Retrieves the recommended update interval for a data value.
    ///
    /// \return
    ///     Returns a recommended update interval, in millisecond.\n
    ///     If specified value supports auto or asynchronous update, the return value is 0. See SetEventListener() for more information.\n
    ///     If \a index is invalid or specified value does not exists, the return value is NVG_ANY(-1).
    virtual unsigned NVG_METHOD GetUpdateInterval(unsigned index) NVG_PURE;

    /// Update specified data values.
    ///
    /// \param [in]  index A zero based number represents the value to update, NVG_ANY means updating all values.
    /// \param [in]  param A pointer to the null terminated string as update parameter.
    /// \retval S_OK         Success.
    /// \retval E_PENDING    If event listener is set, the event handler will receive an EVT::DATAUPDATE event when value is updated.
    ///                      If event listener is not set, the values will be updated at undefined time.
    /// \retval E_INVALIDARG Fail. The \a index is invalid or value does not exists.
    /// \retval E_FAIL       Failed with unknown error.
    ///
    /// \note
    ///     This function must be called successfully at least once even if auto update is supported by this data.
    virtual long NVG_METHOD Update(unsigned index = NVG_ANY, const wchar_t* param = NULL) NVG_PURE;

    /// Reserved function.
    ///
    /// \retval E_NOTIMPL.
    virtual long NVG_METHOD Invoke(unsigned index, const wchar_t* param = NULL, UI::IWindow* window = NULL) NVG_PURE;

    /// Retrieves the configuration string for specified data value.
    ///
    /// The returned string could be used as the parameter for Update() or Invoke(), etc.
    ///
    /// \param [in]  index  A zero based number represents the value to configure.
    /// \param [in]  type   Configuration type, one of the NERvGear::DATA::CONFIG enumeration values.
    /// \param [in]  window Reserved, must be NULL.
    /// \param [in]  len    The size of \a param buffer, in characters. If \a param is NULL, this parameter must be 0.
    /// \param [out] param  A pointer to a buffer that receives the null terminated string for the parameter, could be NULL.
    ///
    /// \remark
    ///     See GetName() for more details about parameters and return values.
    virtual size_t NVG_METHOD Config(unsigned index, DATA::CONFIG type, UI::IWindow* window, size_t len, wchar_t* param) NVG_PURE;



    /// Specifies the unit for a data unit.
    ///
    /// \param [in]  index A zero based number represents the value to set unit.
    /// \param [in]  unit  A pointer to the null terminated string returned by EnumValueUnit().
    /// \retval S_OK         Success.
    /// \retval E_INVALIDARG Fail. The \a index is invalid or value does not exists, or \a unit is NULL or invalid.
    /// \retval E_FAIL       Fail. Specified value does not have unit, or failed to switch to specified unit.
    virtual long NVG_METHOD SetValueUnit(unsigned index, const wchar_t* unit) NVG_PURE;

    /// Enumerates all units supported by a data value.
    ///
    /// \param [in]  index A zero based number represents the value to enumerate.
    /// \param [in]  len   The buffer size of \a units, in characters. If \a units is NULL, this parameter must be 0.
    /// \param [out] units A pointer to the buffer receiving a double-null-terminated string, could be NULL.
    /// \return
    ///     Returns the size copied into the string buffer, in characters.\n
    ///     If \a units is not NULL, the return value is the length of the string that is copied to the buffer, in characters,
    /// not including the terminating null characters.\n
    ///     If \a units is NULL and \a len is 0, the return value is the buffer size required to store the string, in characters,
    /// including the terminating null characters.\n
    ///     If the data value does not have any units, the return value is 0.
    ///
    /// \see
    ///     NERvCopyStringDoubleNull()
    virtual size_t NVG_METHOD EnumValueUnit(unsigned index, size_t len, wchar_t* units) NVG_PURE;



    /// Sets an event listener receiving update events for this data object
    ///
    /// If the data object supports auto or asynchronous update, the event handler will receive EVT::DATAUPDATE when a value is updated.
    ///
    /// \param [in]  listener A pointer to the event handler that receives update events.
    /// \retval S_OK         Success.
    /// \retval E_INVALIDARG Fail. The \a listener is NULL.
    /// \retval E_NOTIMPL    Fail, It's not implemented by this data object.
    /// \retval E_FAIL       Failed with unknown error.
    ///
    /// \remark
    ///     Difference between auto and asynchronous update:
    ///     - Auto Update: The Update() call returns S_OK, EVT::DATAUPDATE will be sent to event handler continuous at the right time when a value is changed.
    ///     - Asynchronous Update: The Update() call returns E_PENDING, EVT::DATAUPDATE will be sent one time when a value is updated
    virtual long NVG_METHOD SetEventListener(IEventHandler* listener) NVG_PURE; // receiving EVT::DATAUPDATE

};


// Interface ID
NVG_EXPORT_UID(NVG_ID_IData, 0x00000001, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x49, 0x44, 0x61, 0x74, 0x61); 
static const UID& ID_IData = NVG_ID_IData; ///< "IData" version 1
//#define ID_IData NVG_ID_IData


} // NERvGear

#else // C

#endif // __cplusplus

#endif // NVG_IDATA_H


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

namespace DATA {

/// Available data types for IData.
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
    CHAR_CP,                //!< code page characters start here, CHAR_CP + enums in encoding.h
    CHARACTER_LAST  = 200,

    STRING_FIRST    = 201,
    STRING          = 201,  //!< wchar_t* null-terminated C string equipment
    STR_ASCII,              //!< char* null-terminated C string equipment
    STR_CP,                 //!< code page strings start here, STR_CP + enums in encoding.h
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

/// Nerve Gear data interface.
///
/// \note Any member functions take index parameter are zero-based.
NVG_INTERFACE_EXTEND(IData, IUnknown) {

    /// Retrieves the UID of this data object.
    ///
    /// \param [out] id Pointer to a UID, must not be NULL.
    /// \retval S_OK Success.
    /// \retval E_INVALIDARG Failed, the id parameter is NULL.
    /// \retval E_FAIL Failed with unknown error.
    ///
    /// \note An ID of a data is unique for one data and must be different from any other data.
    /// \see See also IDataSource::FindData().
    virtual long NVG_METHOD GetId(UID* id) NVG_PURE;



    /// Retrieves the display name for this data.
    ///
    /// \see See IDataSource::GetName() for more details about parameters and return values.
    virtual size_t NVG_METHOD GetName(size_t len, wchar_t* name) NVG_PURE;

    /// Retrieves the description for this data.
    ///
    /// \see See IDataSource::GetName() for more details about parameters and return values.
    virtual size_t NVG_METHOD GetDescrip(size_t len, wchar_t* descrip) NVG_PURE;

    /// Retrieves the source providing this data.
    ///
    /// \param [out] source A pointer to a buffer receiving the IDataSource pointer.
    /// \retval S_OK Success.
    /// \retval E_INVALIDARG Failed, the source parameter is NULL.
    /// \retval E_FAIL Failed with unknown error.
    ///
    /// \note The queried source must be the same object creating this data.
    virtual long NVG_METHOD QuerySource(IDataSource** source) NVG_PURE;



    /// Retrieves the number of values providing by this data.
    virtual unsigned NVG_METHOD GetValueCount() NVG_PURE;



    /// Retrieves an current value of this data.
    ///
    /// \param [in]  index A zero based number represents the value to get.
    /// \param [in]  nbyte The buffer size of buf, in bytes. If buf is NULL, this parameter must be 0.
    /// \param [out] buf A pointer to the buffer receiving a value, could be NULL.
    /// \return Returns the size copied into the buffer, in bytes.
    /// If buf is NULL and nbyte is 0, the return value is the buffer size required to store the value, in bytes.
    /// If the data does not have specified value, the return value is 0.
    ///
    /// \note Call IData::Update() before any calls to GetValue()/GetMaximum()/GetMinimum() to confirm values are up to date.
    virtual size_t NVG_METHOD GetValue(unsigned index, size_t nbyte, void* buf) NVG_PURE;

    /// Retrieves an maximum value of this data.
    ///
    /// \see See IData::GetValue() for more details about parameters and return values.
    virtual size_t NVG_METHOD GetMaximum(unsigned index, size_t nbyte, void* buf) NVG_PURE;

    /// Retrieves an minimum value of this data.
    ///
    /// \see See IData::GetValue() for more details about parameters and return values.
    virtual size_t NVG_METHOD GetMinimum(unsigned index, size_t nbyte, void* buf) NVG_PURE;



    /// Retrieves the index of a data value.
    ///
    /// \param [in]  id A number represent a data value in public.
    /// \return Returns a zero based number privately represent a data value.
    /// \retval NVG_ANY Failed, the id parameter is invalid.
    ///
    /// \see Call IData::GetValueId() to retrieve the id of a data value.
    virtual unsigned NVG_METHOD GetValueIndex(int id) NVG_PURE;

    /// Retrieves the ID of a data value.
    ///
    /// \return Returns a number locally represent a data value.
    /// \retval NVG_ANY Failed, the index parameter is invalid.
    ///
    /// \note The ID returned by this function should identify a data value locally in a data space.
    ///       Once an ID is bond to a value and published, the ID of one value should not be changed.
    /// \see Call IData::GetValueIndex() to retrieve the index of a data value.
    virtual int NVG_METHOD GetValueId(unsigned index) NVG_PURE;

    /// Retrieves the data type of a data value.
    ///
    /// \see See DATA::TYPE for available enumerators.
    virtual DATA::TYPE NVG_METHOD GetValueType(unsigned index) NVG_PURE;

    /// Retrieves the current unit of a data value.
    ///
    /// \see See IDataSource::GetName() for more details about parameters and return values.
    virtual size_t NVG_METHOD GetValueUnit(unsigned index, size_t len, wchar_t* unit) NVG_PURE;

    /// Retrieves the display name for a data value.
    ///
    /// \see See IDataSource::GetName() for more details about parameters and return values.
    virtual size_t NVG_METHOD GetValueName(unsigned index, size_t len, wchar_t* name) NVG_PURE;

    /// Retrieves the display name for a data value.
    ///
    /// \see See IDataSource::GetName() for more details about parameters and return values.
    virtual size_t NVG_METHOD GetValueDescrip(unsigned index, size_t len, wchar_t* descrip) NVG_PURE;



    /// Retrieves the recommended update interval for a data value.
    ///
    /// \return Returns a recommended update interval, in millisecond.
    /// If specified value supports auto or asynchronous update, the return value is 0.
    /// If an index is invalid or specified value does not exists, the return value is NVG_ANY(-1).
    virtual unsigned NVG_METHOD GetUpdateInterval(unsigned index) NVG_PURE;

    /// Update specified data values.
    /// \param [in]  index A zero based number represents the value to update, NVG_ANY means updating all values.
    /// \param [in]  param A pointer to the null terminated string as update parameter.
    /// \retval S_OK Success.
    /// \retval E_INVALIDARG Failed, the index parameter is invalid or value does not exists.
    /// \retval E_PENDING If event listener is setted, the event handler will an EVT::DATAUPDATE event when value is updated.
    ///                   If event listener is not setted, the values will be updated at undefined time.
    /// \retval E_FAIL Failed with unknown error.
    ///
    /// \note This function must be called successfully at least once even if auto update is supported by this data.
    virtual long NVG_METHOD Update(unsigned index = NVG_ANY, const wchar_t* param = NULL) NVG_PURE;

    /// Reserved function.
    ///
    /// \retval E_NOTIMPL.
    virtual long NVG_METHOD Invoke(unsigned index, const wchar_t* param = NULL, UI::IWindow* window = NULL) NVG_PURE;

    /// Retrieve specified parameter string for s data value.
    ///
    /// \param [in]  type Configuration type.
    /// \param [in]  window Reserved, must be NULL.
    /// \see See DATA::CONFIG for available configuration types.
    /// \see See IDataSource::GetName() for more details about parameters and return values.
    virtual size_t NVG_METHOD Config(unsigned index, DATA::CONFIG type, UI::IWindow* window, size_t len, wchar_t* param) NVG_PURE;



    /// Specifies the unit for a data unit.
    ///
    /// \param [in]  index A zero based number represents the value to set unit.
    /// \param [in]  unit A pointer to the null terminated string returned by IData::EnumValueUnit().
    /// \retval S_OK Success.
    /// \retval E_INVALIDARG Failed, the index parameter is invalid or value does not exists, or unit parameter is NULL or invalid.
    /// \retval E_FAIL Specified value does not have unit, or fails to switch to specified unit.
    virtual long NVG_METHOD SetValueUnit(unsigned index, const wchar_t* unit) NVG_PURE;

    /// Enumerate all units supported by a data value.
    ///
    /// \param [in]  index A zero based number represents the value to enumerate.
    /// \param [in]  len The buffer size of units, in characters. If units is NULL, this parameter must be 0.
    /// \param [out] units A pointer to the buffer receiving a double null terminated string, could be NULL.
    /// \return Returns the size copied into the string buffer, in characters.
    /// If units is NULL and len is 0, the return value is the buffer size required to store the string, in characters.
    /// If the data value does not have any units, the return value is 0.
    virtual size_t NVG_METHOD EnumValueUnit(unsigned index, size_t len, wchar_t* units) NVG_PURE;   // double NULL terminator



    /// Set an event listener receiving update events for this data object
    ///
    /// \param [in]  listener A pointer to the event handler that receives update events.
    /// \retval S_OK Success.
    /// \retval E_INVALIDARG Failed, the listener parameter is NULL.
    /// \retval E_NOTIMPL Failed, not implemented by this data object.
    /// \retval E_FAIL Failed with unknown error.
    ///
    /// If the data object supports auto or asynchronous update, the event handler will receive EVT::DATAUPDATE when a value is updated.
    ///
    /// \note Difference between auto and asynchronous update:
    /// - Auto Update: The Update() call returns S_OK, EVT::DATAUPDATE will be sent to event handler continuous at the right time when a value is changed.
    /// - Asynchronous Update: The Update() call returns E_PENDING, EVT::DATAUPDATE will be sent one time when a value is updated
    virtual long NVG_METHOD SetEventListener(IEventHandler* listener) NVG_PURE; // receiving EVT::DATAUPDATE

};

// declare IDs
NVG_DEFINE_UID(NVG_ID_IData, 0x00000001, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x49, 0x44, 0x61, 0x74, 0x61); // "IData" version 1

// define latest API
//#define ID_IData NVG_ID_IData
static const UID& ID_IData = NVG_ID_IData;

} // NERvGear

#else // C

#endif // __cplusplus

#endif // NVG_IDATA_H

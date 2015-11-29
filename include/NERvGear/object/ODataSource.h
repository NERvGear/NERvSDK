
/***************************************************************
 * Name:      ODataSource.h
 * Purpose:   Defines Data Source Object
 * Author:    GPBeta ()
 * Created:   2015-09-14
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_ODATASOURCE_H
#define NVG_ODATASOURCE_H

#include <NERvGear/component/CDataSource.h>
#include <NERvGear/interface/IDataSource.h>

#ifdef __cplusplus

namespace NERvGear {


/// \ingroup mod_obj_nvg
///
/// \object NERvGear::ODataSource
/// \extends NERvGear::OUnknown
/// \implements NERvGear::CDataSource
/// \implements NERvGear::IDataSource
///
/// \brief Nerve Gear data source implementation.
///
/// Available data, value and IDs:
/// - System Data
///   - Data UID: NERvGear::DATA::ID_SYS
///   - Data Values: NERvGear::DATA::SYS::VALUE
/// - Core Data
///   - Data UID: NERvGear::DATA::ID_CORE
///   - Data Values: NERvGear::DATA::CORE::VALUE
/// - CPU Usage Data
///   - Data UID: NERvGear::DATA::ID_CPU
///   - Data Values: Each value represents a CPU core, use IData::GetValueCount() to retrieve CPU core amount.
/// - RAM Usage Data
///   - Data UID: NERvGear::DATA::ID_RAM
///   - Data Values: NERvGear::DATA::RAM::VALUE
/// - Hard Disk Usage Data
///   - Data UID: NERvGear::DATA::ID_HDD
///   - Data Values: NERvGear::DATA::HDD::VALUE
/// - Power Data
///   - Data UID: NERvGear::DATA::ID_PWR
///   - Data Values: NERvGear::DATA::PWR::VALUE
/// - Miscellaneous Data
///   - Data UID: NERvGear::DATA::ID_MISC
///   - Data Values: NERvGear::DATA::MISC::VALUE
///
/// All of the value types are fixed and indicated by the prefix of their IDs.\n
/// For example, ID `NERvGear::DATA::SYS::STR_OS_NAME` indicates that the value of 'OS Name' is a string,
/// while `NERvGear::DATA::CORE::I32_SERVICE_COMPONENT` means the value of 'Component Service' is a 4-bytes integer.
///
/// \version 1.0.0
///     Initial release.
///
/// \depend{Nerve Gear 0.3.0 and above}
/// \module{NERvGear.DLL}
/// \declid{Object,NERvGear::ID_ODataSource,00000001-4F00-6144-7461-536f75726365}

namespace DATA {

/// \declns{NERvGear::DATA::SYS}
namespace SYS {

/// System data value IDs.
enum VALUE {
    STR_OS_NAME,
    STR_OS_VERSION,
    STR_OS_DESCRIP,
    STR_OS_DIRECTORY,
    STR_PROCESSOR,
    STR_RAM_INSTALLED,
    STR_COMPUTER_NAME,
    STR_ACCOUNT_NAME,
    STR_CURRENT_DATE,
    STR_CURRENT_TIME,
    STR_DEVICE_UPTIME,
    STR_PROGRAM_UPTIME
};

} // SYS

/// \declns{NERvGear::DATA::CORE}
namespace CORE {

/// Core data value IDs.
enum VALUE {
    I32_SERVICE_COMPONENT,
    I32_SERVICE_OBJECT,
    I32_SERVICE_LOCK,
    I32_USAGE_COMPONENT,
    I32_USAGE_OBJECT,
    I32_PRIVATE_OBJECT
};

} // CORE

/// \declns{NERvGear::DATA::RAM}
namespace RAM {

/// RAM usage value IDs.
enum VALUE {
    U64_PHYSICAL_SIZE,
    U64_VIRTUAL_SIZE,
    U64_PAGE_FILE
};

} // RAM

/// \declns{NERvGear::DATA::HDD}
namespace HDD {

/// Hard disk usage value IDs.
enum VALUE {
    U64_FREE_SPACE,
    U64_FREE_CLUSTER
};

} // HDD

/// \declns{NERvGear::DATA::PWR}
namespace PWR {

/// Power data value IDs.
enum VALUE {
    I32_AC_STATUS,
    I32_BATTERY_STATUS,
    U32_LIFE_TIME
};

} // PWR

/// \declns{NERvGear::DATA::MISC}
namespace MISC {

/// \brief Miscellaneous data value IDs.
enum VALUE {
    STR_CUSTOM_TEXT
};

} // MISC

NVG_DEFINE_UID(ID_SYS,  0xAE958FE5, 0x785E, 0x4C1D, 0x9D, 0xAE, 0x7F, 0xA7, 0x89, 0x08, 0x70, 0xA5); ///< AE958FE5-785E-4C1D-9DAE-7FA7890870A5
NVG_DEFINE_UID(ID_CORE, 0xC1076F86, 0xE06C, 0x4701, 0x81, 0x8E, 0xFE, 0x0B, 0x71, 0xD3, 0xBA, 0x40); ///< C1076F86-E06C-4701-818E-FE0B71D3BA40
NVG_DEFINE_UID(ID_CPU,  0x2F94BA5A, 0xBAD6, 0x472F, 0x9C, 0x27, 0x3A, 0xAE, 0x01, 0x5C, 0x19, 0x17); ///< 2F94BA5A-BAD6-472F-9C27-3AAE015C1917
NVG_DEFINE_UID(ID_RAM,  0x766A81E5, 0xFC74, 0x4C10, 0x90, 0x20, 0x27, 0x28, 0x08, 0x57, 0xB1, 0xCB); ///< 766A81E5-FC74-4C10-9020-27280857B1CB
NVG_DEFINE_UID(ID_HDD,  0x529DD40A, 0x12A4, 0x4196, 0xAF, 0x7A, 0x9A, 0x17, 0x49, 0x43, 0x13, 0x4B); ///< 529DD40A-12A4-4196-AF7A-9A174943134B
NVG_DEFINE_UID(ID_PWR,  0xBA8D07C2, 0xFA60, 0x4BBB, 0x84, 0xC4, 0x56, 0x44, 0xFE, 0xA3, 0x53, 0x88); ///< BA8D07C2-FA60-4BBB-84C4-5644FEA35388
NVG_DEFINE_UID(ID_MISC, 0x0712E2CB, 0x0366, 0x4946, 0x9E, 0x64, 0x62, 0xF6, 0xC7, 0xCD, 0xAB, 0xF2); ///< 0712E2CB-0366-4946-9E64-62F6C7CDABF2

} // DATA


// Object ID
NVG_EXPORT_UID(NVG_ID_ODataSource, 0x00000001, 0x4F00, 0x6144, 0x74, 0x61, 0x53, 0x6F, 0x75, 0x72, 0x63, 0x65);
static const UID& ID_ODataSource = NVG_ID_ODataSource; ///< "ODataSource" version 1
//#define ID_ODataSource NVG_ID_ODataSource


} // NERvGear

#else // C

#endif // __cplusplus

#endif // NVG_ODATASOURCE_H

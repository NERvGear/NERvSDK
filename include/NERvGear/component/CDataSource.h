
/***************************************************************
 * Name:      CDataSource.h
 * Purpose:   Defines Data Source Component
 * Author:    GPBeta ()
 * Created:   2015-09-14
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_CDATASOURCE_H
#define NVG_CDATASOURCE_H

#include <NERvGear/component/CUnknown.h>

#ifdef __cplusplus

namespace NERvGear {


/// \ingroup mod_com_nvg
///
/// \component NERvGear::CDataSource
/// \extends NERvGear::CUnknown
/// \brief A data source for varieties data.
///
/// \implguide
///     Objects that implement this component should provide a NERvGear::IDataSource interface.
///
/// \declid{Component,NERvGear::ID_CDataSource,CORE_COMMON-4300-6144-7461-536f75726365}

// Component ID
NVG_EXPORT_UID(NVG_ID_CDataSource, CATALOG::CORE_COMMON, 0x4300, 0x6144, 0x74, 0x61, 0x53, 0x6F, 0x75, 0x72, 0x63, 0x65);
static const UID& ID_CDataSource = NVG_ID_CDataSource; ///< "CDataSource"
//#define ID_CDataSource NVG_ID_CDataSource


} // NERvGear

#else // C

#endif // __cplusplus

#endif // NVG_CDATASOURCE_H

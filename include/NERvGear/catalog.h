
/***************************************************************
 * Name:      catalog.h
 * Purpose:   Defines Nerve Gear Catalogs
 * Author:    GPBeta ()
 * Created:   2014-10-22
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_CATALOG_H
#define NVG_CATALOG_H

namespace NERvGear {

/// \brief Predefined component catalogs.
///
// Please open an issue on NERvSDK repository if you want to add a catalog.
namespace CATALOG {

enum {
    CORE        = 0x00000000,
        CORE_COMMON     = 0x00010000,
        CORE_SYSTEM     = 0x00030000,
        CORE_UI         = 0x00050000,
            CORE_UI_VIEW        = 0x00050100,
            CORE_UI_CTRL        = 0x00050200,
            CORE_UI_THEME       = 0x00050300,
        CORE_PLUGIN     = 0x00070000,
    
    // Catalogs below are available for NERvHub defined components.
    
    SYSTEM      = 0x01000000,
    SECURITY    = 0x02000000,
    NETWORK     = 0x03000000,
    DESKTOP     = 0x04000000,
    GRAPHIC     = 0x05000000,
    VIDEO       = 0x06000000,
    AUDIO       = 0x07000000,

    ETC         = 0xFF000000
};

}

}

/// \declns{NERvGear::System}

/// \declns{NERvGear::Security}

/// \declns{NERvGear::Network}

/// \declns{NERvGear::Desktop}

/// \declns{NERvGear::Graphic}

/// \declns{NERvGear::Video}

/// \declns{NERvGear::Audio}

/// \declns{NERvGear::ETC}


#endif // NVG_CATALOG_H

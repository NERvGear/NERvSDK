
/***************************************************************
 * Name:      version.h
 * Purpose:   Defines Nerve Gear Version
 * Author:    GPBeta ()
 * Created:   2014-10-22
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_VERSION_H
#define NVG_VERSION_H

#include <NERvGear/def.h>

namespace NERvGear {

#define NVG_DECLARE_VERSION(_MAJOR, _MINOR, _SUBMINOR, _RESERVED) {_MAJOR, _MINOR, _SUBMINOR, _RESERVED}

#define NVG_DOT_VERSION(_MAJOR, _MINOR, _SUBMINOR, _RESERVED) NVG_MACRO_STR(_MAJOR._MINOR._SUBMINOR._RESERVED)
#define NVG_DOT_VERSION3(_MAJOR, _MINOR, _SUBMINOR)           NVG_MACRO_STR(_MAJOR._MINOR._SUBMINOR)
#define NVG_DOT_VERSION2(_MAJOR, _MINOR)                      NVG_MACRO_STR(_MAJOR._MINOR)
#define NVG_DOT_VERSION1(_MAJOR)                              NVG_MACRO_STR(_MAJOR)

#if defined(WIN64) || defined(_WIN64)
#define NVG_PLATFORM_SUFFIX "x64"
#else
#define NVG_PLATFORM_SUFFIX "x86"
#endif // WIN64

// define NERvSDK version
#define NVS_VER_MAJOR       0
#define NVS_VER_MINOR       2
#define NVS_VER_SUBMINOR    1
#define NVS_VER_RESERVED    34500 // 12.11 build 1

#define NVS_VER_REV                  NVS_VER_MAJOR, NVS_VER_MINOR, NVS_VER_SUBMINOR, NVS_VER_RESERVED
#define NVS_VER_STR  NVG_DOT_VERSION(NVS_VER_MAJOR, NVS_VER_MINOR, NVS_VER_SUBMINOR, NVS_VER_RESERVED)
#define NVS_VER_NAME NVG_TEXT(NVS_VER_STR) NVG_TEXT(" ") NVG_TEXT(NVG_PLATFORM_SUFFIX)

struct VERSION {
    int major;
    int minor;
    int subminor;
    unsigned reserved;
};

static inline bool operator==(const VERSION& a, const VERSION& b)
{
    return a.major == b.major && a.minor == b.minor && a.subminor == b.subminor && a.reserved == b.reserved;
}

static inline bool operator>(const VERSION& a, const VERSION& b)
{
    if (a.major == b.major) {
        if (a.minor == b.minor) {
            if (a.subminor == b.subminor)
                return a.reserved > b.reserved;
            return a.subminor > b.subminor;
        }
        return a.minor > b.minor;
    }
    return a.major > b.major;
}

static inline bool operator <(const VERSION& a, const VERSION& b) { return   b > a;  }
static inline bool operator>=(const VERSION& a, const VERSION& b) { return !(a < b); }
static inline bool operator<=(const VERSION& a, const VERSION& b) { return !(a > b); }
static inline bool operator!=(const VERSION& a, const VERSION& b) { return !(a == b); }


/// \ingroup mod_function
/// @{


// NERvGear core version


/// \brief Retrieves core(NERvGear) version code.
///
/// \see
///     NERvVerCodeHost()
///
/// \header{NERvGear/version.h}
NVG_EXPORT(VERSION) NERvVerCodeCore();

/// \brief Retrieves core(NERvGear) version name string.
///
/// e.g.
/// > "Beta 1 x64"
///
/// \see
///     NERvVerNameHost()
///
/// \header{NERvGear/version.h}
NVG_EXPORT(const wchar_t*) NERvVerNameCore();

/// \brief Retrieves core(NERvGear) name string.
///
/// e.g.
/// > "Nerve Gear"
///
/// \see
///     NERvGetHostName()
///
/// \header{NERvGear/version.h}
NVG_EXPORT(const wchar_t*) NERvGetCoreName();


// NERvGear host version


/// \brief Retrieves host program version code.
///
/// \see
///     NERvVerCodeCore()
///
/// \header{NERvGear/version.h}
NVG_EXPORT(VERSION) NERvVerCodeHost();

/// \brief Retrieves host program version name string.
///
/// e.g. SAO Utils.exe provides
/// > "Beta 1 x64"
/// while NERvSDK.exe provides
/// > "0.1.0.0 x64"
///
/// \see
///     NERvVerNameCore()
///
/// \header{NERvGear/version.h}
NVG_EXPORT(const wchar_t*) NERvVerNameHost();

/// \brief Retrieves host program name string.
///
/// e.g. SAO Utils.exe provides
/// > "SAO Utils"
/// while NERvSDK.exe provides
/// > "NERvSDK"
///
/// \see
///     NERvGetHostName()
///
/// \header{NERvGear/version.h}
NVG_EXPORT(const wchar_t*) NERvGetHostName();


/// @}


}

#endif // NVG_VERSION_H

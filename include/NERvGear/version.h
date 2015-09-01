
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
#define NVS_VER_MINOR       1
#define NVS_VER_SUBMINOR    0
#define NVS_VER_RESERVED    23300 // 8.20 build 1

#define NVS_VER_REV                  NVS_VER_MAJOR, NVS_VER_MINOR, NVS_VER_SUBMINOR, NVS_VER_RESERVED
#define NVS_VER_STR  NVG_DOT_VERSION(NVS_VER_MAJOR, NVS_VER_MINOR, NVS_VER_SUBMINOR, NVS_VER_RESERVED)
#define NVS_VER_NAME NVS_VER_STR " " NVG_PLATFORM_SUFFIX

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

static inline bool operator!=(const VERSION& a, const VERSION& b)
{
    return a.major != b.major || a.minor != b.minor || a.subminor != b.subminor || a.reserved != b.reserved;
}

// NERvGear core version
NVG_EXPORT(VERSION)        NERvVerCodeCore();
NVG_EXPORT(const wchar_t*) NERvVerNameCore();
NVG_EXPORT(const wchar_t*) NERvGetCoreName();
// NERvGear host version
NVG_EXPORT(VERSION)        NERvVerCodeHost();
NVG_EXPORT(const wchar_t*) NERvVerNameHost();
NVG_EXPORT(const wchar_t*) NERvGetHostName();

}

#endif // NVG_VERSION_H

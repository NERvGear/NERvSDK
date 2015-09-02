
/***************************************************************
 * Name:      def.h
 * Purpose:   Defines Nerve Gear Common Definitions
 * Author:    GPBeta ()
 * Created:   2014-10-15
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_DEF_H
#define NVG_DEF_H

namespace NERvGear {

#ifndef NULL
#define NULL 0
#endif // NULL

template<class T>
static inline T NERvMin(T a, T b) { return a < b ? a : b; }

template<class T>
static inline T NERvMax(T a, T b) { return a > b ? a : b; }

// defined in winbase.h
#ifdef __GNUC__     // GCC
#define NERvSyncIncrement(_PTR) __sync_add_and_fetch_4(_PTR, 1)
#define NERvSyncDecrement(_PTR) __sync_sub_and_fetch_4(_PTR, 1)
#elif _MSC_VER      // MSVC
extern "C" {
	long __cdecl _InterlockedIncrement(long volatile *Addend);
	long __cdecl _InterlockedDecrement(long volatile *Addend);
}
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
#define NERvSyncIncrement _InterlockedIncrement
#define NERvSyncDecrement _InterlockedDecrement
#else               // U can U up
#endif // __GNUC__

#define NVG_ANY -1

#define NVG_MACRO_STR(_STR) #_STR

#define _NVG_TEXT(_TEXT) L##_TEXT
#define NVG_TEXT(_TEXT) _NVG_TEXT(_TEXT)    // trick

#if defined(WIN64) || defined(_WIN64)
#define NVG_MODULE_DLL "module64.dll"
#else
#define NVG_MODULE_DLL "module32.dll"
#endif // WIN64 || _WIN64

#ifdef _NVG_DLLEXPORT_CONTROL
#define NVG_DLLEXPORT __declspec(dllexport)
#else
#define NVG_DLLEXPORT // MinGW export all symbols by default
#endif // _NVG_DLLEXPORT_CONTROL

#ifdef _NVG_BUILD_DLL
#define NVG_EXPORT(_RET) extern "C" NVG_DLLEXPORT _RET __cdecl
#define NVG_EXPORT_SYMBOL extern "C" NVG_DLLEXPORT
#else
#define NVG_EXPORT(_RET) extern "C" _RET __cdecl
#define NVG_EXPORT_SYMBOL extern "C" __declspec(dllimport)  // fix for VC
#endif // _NVG_BUILD_DLL

#ifdef _NVG_EXPORT_UID
#define NVG_DEFINE_UID(_NAME, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A) \
    extern "C" __declspec(dllexport) const UID _NAME = { _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A }
#else
//! Define NVG_FLAG_INIT_UID in a source file if you don't link against DLL containing the UID
#ifdef NVG_FLAG_INIT_UID
#define NVG_DEFINE_UID(_NAME, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A) \
    static const UID _NAME = { _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A }
#else
#define NVG_DEFINE_UID(_NAME, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A) \
    NVG_EXPORT_SYMBOL const UID _NAME
#endif // NVG_FLAG_INIT_UID
#endif // _NVG_EXPORT_UID

//! Define NVG_FLAG_IMPORT in your project when importing plug-in DLLs
#ifdef NVG_FLAG_IMPORT
#define NVG_EXPORT_CLASS __declspec(dllimport)
#elif defined(_MSC_VER) || defined(_NVG_DLLEXPORT_CONTROL)
#define NVG_EXPORT_CLASS __declspec(dllexport)
#else
#define NVG_EXPORT_CLASS
#endif // NVG_FLAG_IMPORT

#define NVG_DEPRECATED(_TYPE, _EXTRA) __declspec(deprecated("This " _TYPE " was deprecated, " _EXTRA "."))

// declare IDs

union UID;
NVG_DEFINE_UID(NVG_ID_NULL, 0x00000000, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
static const UID& ID_NULL = NVG_ID_NULL;

}

#endif // NVG_DEF_H

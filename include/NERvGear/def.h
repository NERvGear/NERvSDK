
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


/// \ingroup mod_function
/// @{


/// \brief Computes the minimum of \a a and \a b.
template<class T>
static inline T NERvMin(T a, T b) { return a < b ? a : b; }

/// \brief Computes the maximum of \a a and \a b.
template<class T>
static inline T NERvMax(T a, T b) { return a > b ? a : b; }


/// @}


// defined in winbase.h
#ifdef __GNUC__     // GCC
#define NERvSyncIncrement(_PTR) __sync_add_and_fetch_4(_PTR, 1)
#define NERvSyncDecrement(_PTR) __sync_sub_and_fetch_4(_PTR, 1)
#define NVG_WEAK_SYMBOL __attribute__((weak))
#elif _MSC_VER      // MSVC
extern "C" {
	long __cdecl _InterlockedIncrement(long volatile *Addend);
	long __cdecl _InterlockedDecrement(long volatile *Addend);
}
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
#define NERvSyncIncrement _InterlockedIncrement
#define NERvSyncDecrement _InterlockedDecrement
#define NVG_WEAK_SYMBOL __declspec(selectany)
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

#ifdef _NVG_BUILD_RES
#define NVG_SYMEXPORT __declspec(dllexport)
#else
#define NVG_SYMEXPORT __declspec(dllimport)
#endif // _NVG_BUILD_RES

#ifdef _NVG_BUILD_API
#define NVG_APIEXPORT __declspec(dllexport)
#else
// TODO: Remove source dependences between CORE and API.
#ifdef _NVG_BUILD_CORE
#define NVG_APIEXPORT
#else
#define NVG_APIEXPORT __declspec(dllimport)
#endif // _NVG_BUILD_CORE
#endif // _NVG_BUILD_API

#if defined(_NVG_BUILD_CORE)
#define NVG_COREXPORT __declspec(dllexport)
#elif defined(_NVG_BUILD_API) || defined(_NVG_BUILD_HOST)
#define NVG_COREXPORT __declspec(dllimport)
#else
#define NVG_COREXPORT
#endif // _NVG_BUILD_CORE

#define NVG_EXPORT_SYMBOL extern "C" NVG_SYMEXPORT
#define NVG_EXPORT(_RET)  extern "C" NVG_APIEXPORT _RET __cdecl

#ifdef NVG_FLAG_FORCE_EXPORT
#define _NVG_EXPORT(_RET) extern "C" __declspec(dllexport) _RET __cdecl
#else // VC use def file to export these symbols while MinGW has no need to declare explicitly.
#define _NVG_EXPORT(_RET) extern "C" _RET __cdecl
#endif // NVG_FLAG_FORCE_EXPORT

#ifdef NVG_FLAG_INIT_UID
#ifdef _NVG_BUILD_RES
#define NVG_EXPORT_UID(_NAME, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A) \
    extern "C" __declspec(dllexport) const ::NERvGear::UID _NAME = { _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A }
#else
#define NVG_EXPORT_UID(_NAME, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A) \
    extern const ::NERvGear::UID NVG_WEAK_SYMBOL _NAME = { _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A }
#endif // _NVG_BUILD_RES
#else
#define NVG_EXPORT_UID(_NAME, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A) \
    NVG_EXPORT_SYMBOL const ::NERvGear::UID _NAME
#endif // NVG_FLAG_INIT_UID

#define NVG_DEFINE_UID(_NAME, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A) \
    extern const ::NERvGear::UID NVG_WEAK_SYMBOL _NAME = { _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A }

//! Define NVG_FLAG_IMPORT in your project when importing plug-in DLLs
//! Define NVG_FLAG_FORCE_EXPORT in your project if you really want to export them explicitly.
// TODO: Change NVG_EXPORT_CLASS to NVG_DLLEXPORT
#ifdef NVG_FLAG_IMPORT
#define NVG_DLLEXPORT __declspec(dllimport)
#else
#if defined(_MSC_VER) || defined(NVG_FLAG_FORCE_EXPORT)
#define NVG_DLLEXPORT __declspec(dllexport)
#else
#define NVG_DLLEXPORT
#endif // _MSC_VER
#endif // NVG_FLAG_IMPORT

#define NVG_DEPRECATED(_TYPE, _EXTRA) __declspec(deprecated("This " _TYPE " was deprecated, " _EXTRA "."))

// declare module

NVG_COREXPORT extern struct MODULE NVG_MODULE;

// declare IDs

union UID;
NVG_EXPORT_SYMBOL const UID NVG_ID_NULL;
static const UID& ID_NULL = NVG_ID_NULL;

}

#endif // NVG_DEF_H

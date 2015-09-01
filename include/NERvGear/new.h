
/***************************************************************
 * Name:      new.h
 * Purpose:   Defines no throw new operator
 * Author:    GPBeta ()
 * Created:   2014-10-29
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_NEW_H
#define NVG_NEW_H

#ifdef _WIN64
typedef unsigned long long size_t;
#else
typedef unsigned size_t;
#endif // _WIN64

namespace std {

struct nothrow_t;
extern const nothrow_t nothrow;

}

void* __cdecl operator new(size_t, const std::nothrow_t&) throw();
void* __cdecl operator new[](size_t, const std::nothrow_t&) throw();

void __cdecl operator delete(void*, const std::nothrow_t&) throw();
void __cdecl operator delete[](void*, const std::nothrow_t&) throw();

#define nvg_new new(std::nothrow)       // no throw version of new

#endif // NVG_NEW_H

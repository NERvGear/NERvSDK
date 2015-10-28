
/***************************************************************
 * Name:      basetype.h
 * Purpose:   Defines Nerve Gear Base Types
 * Author:    GPBeta ()
 * Created:   2014-10-22
 * Copyright: GPBeta ()
 * License:
 **************************************************************/
 
#ifndef NVG_BASETYPE_H
#define NVG_BASETYPE_H

typedef signed char         int8_t;
typedef unsigned char       uint8_t;
typedef short               int16_t;
typedef unsigned short      uint16_t;
typedef int                 int32_t;
typedef unsigned            uint32_t;
typedef long long           int64_t;
typedef unsigned long long  uint64_t;

#if defined(WIN64) || defined(_WIN64)
typedef uint64_t size_t;
#else
typedef uint32_t size_t;
#endif // WIN64 || _WIN64

#endif // NVG_BASETYPE_H

/***************************************************************
 * Name:      string.h
 * Purpose:   Defines String Classes
 * Author:    GPBeta ()
 * Created:   2015-05-12
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_STRING_H
#define NVG_STRING_H

#include <NERvGear/basetype.h>
#include <NERvGear/def.h>

namespace NERvGear {

extern struct MODULE NVG_MODULE;


NVG_EXPORT(size_t) NERv1Translation(const wchar_t* catalog, const wchar_t* src, size_t nCharDst, wchar_t* dst, MODULE* module);

static inline void PrivateCopyCharArray(size_t nChar, const wchar_t* src, wchar_t* dst)
{
    for (; nChar--; ++src, ++dst)
        *dst = *src;
}

static inline size_t PrivateCopyString(const wchar_t* src, size_t nCharDst, wchar_t* dst)
{
    if (src && nCharDst) {
        for (size_t i = 0; i < nCharDst; ++i) {
            if (!(dst[i] = src[i]))
                return i;   // terminator is not in counting
        }
        dst[nCharDst - 1] = 0;
        return nCharDst;
    }

    return 0;
}

// latest APIs

static inline size_t NERvTranslation(const wchar_t* src, size_t nCharDst, wchar_t* dst) { return NERv1Translation(NULL, src, nCharDst, dst, &NVG_MODULE); }

static inline size_t NERvStringLength(const wchar_t* src)
{
    if (src) {
        size_t i = 0;
        while (src[i]) ++i;
        return i;
    }
    return 0;
}

static inline size_t NERvCopyCharArray(size_t nCharSrc, const wchar_t* src, size_t nCharDst, wchar_t* dst)
{
    if (dst) {
        if (src && nCharSrc) {
            if (nCharDst >= nCharSrc) {    // full copy
                PrivateCopyCharArray(nCharSrc, src, dst);
                return nCharSrc;
            } else {    // truncated copy
                PrivateCopyCharArray(nCharDst, src, dst);
                return nCharDst;
            }
        }
    } else { return nCharSrc; }

    return 0;
}

static inline size_t NERvCopyString(size_t nCharSrc/* null terminator included */, const wchar_t* src, size_t nCharDst, wchar_t* dst)
{
    if (dst)
        return PrivateCopyString(src, nCharDst, dst);

    return nCharSrc;
}

static inline size_t NERvCopyString(const wchar_t* src, size_t nCharDst, wchar_t* dst)
{
    if (dst)
        return PrivateCopyString(src, nCharDst, dst);

    return NERvStringLength(src);
}

static inline size_t NERvCopyStringDoubleNull(size_t nCharSrc/* double null terminator included */, const wchar_t* src, size_t nCharDst, wchar_t* dst)
{
    if (dst) {    // fix copied length
        if (nCharDst >= 2) {
            size_t nCopy = nCharDst;
            if (nCharDst < nCharSrc) {
                nCopy -= 2;
                *reinterpret_cast<unsigned*>(dst + nCopy) = 0;    // double null terminator
            }
            return NERvCopyCharArray(nCharSrc, src, nCopy, dst);
        }
    } else { return nCharSrc; }

    return 0;
}

template <size_t N_CHAR>
static inline size_t NERvCopyCharArray(const wchar_t (&src)[N_CHAR], size_t nChar, wchar_t* dst)
{
    return NERvCopyCharArray(N_CHAR, src, nChar, dst);
}

template <size_t N_CHAR>
static inline size_t NERvCopyString(const wchar_t (&src)[N_CHAR], size_t nChar, wchar_t* dst)
{
    return NERvCopyString(N_CHAR, src, nChar, dst);
}

template <size_t N_CHAR>
static inline size_t NERvCopyStringDoubleNull(const wchar_t (&src)[N_CHAR], size_t nChar, wchar_t* dst)
{
    return NERvCopyStringDoubleNull(N_CHAR, src, nChar, dst);
}

} // NERvGear


#endif // NVG_STRING_H

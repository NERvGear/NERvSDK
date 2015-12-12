
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


/// \ingroup mod_function
/// @{


/// \brief Finds the translation for a string and copy it to the destination buffer.
///
/// \todo
///     Add localization document.
///
/// \remark
///     If there's no translation for specified string, the \a src string is copied to the destination buffer.\n
///     See NERvCopyString(const wchar_t*, size_t, wchar_t*) for more details about parameters and return values.
///
/// \version
/// 	0.1.0 NERv1Translation()
///
/// \header{NERvGear/string.h}
static inline size_t NERvTranslation(const wchar_t* src, size_t nCharDst, wchar_t* dst) { return NERv1Translation(NULL, src, nCharDst, dst, &NVG_MODULE); }

/// \brief Counts the length of a string.
///
/// \return
///     Returns the size of \a src string, in characters, not including the null-terminator. \n
///     If \a src is NULL, the return value is 0.
///
/// \header{NERvGear/string.h}
static inline size_t NERvStringLength(const wchar_t* src)
{
    if (src) {
        size_t i = 0;
        while (src[i]) ++i;
        return i;
    }
    return 0;
}

/// \brief Copies a char array to the destination buffer.
///
/// \param [in]  nCharSrc The size of the \a src buffer, in characters.
/// \param [in]  src      A pointer to the source char array, must not be NULL.
/// \param [in]  nCharDst The size of the \a dst buffer, in characters. If \a dst is NULL, this parameter must be 0.
/// \param [out] dst      A pointer to a buffer that receives the \a src char array, could be NULL.
/// \return
///     Returns the size copied into the \a dst buffer, in characters.\n
///     If \a dst is not NULL, the return value is the length of the array that is copied to the buffer, in characters.
///     If \a dst buffer is too small to hold the string, the string is truncated to \a nCharDst characters,
/// and the return value is \a nCharDst.\n
///     If \a dst is NULL and \a nCharDst is 0, the return value is \a nCharSrc.\n
///     If the function fails, the return value is 0.
///
/// \see
///     NERvCopyCharArray(const wchar_t (&)[N_CHAR], size_t, wchar_t*)
///
/// \header{NERvGear/string.h}
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

/// \brief Copies a null-terminated string to the destination buffer.
///
/// \param [in]  nCharSrc The size of the \a src buffer, in characters, including the null terminator.
/// \param [in]  src      A pointer to the source string buffer, must not be NULL.
/// \param [in]  nCharDst The size of the \a dst buffer, in characters. If \a dst is NULL, this parameter must be 0.
/// \param [out] dst      A pointer to a buffer that receives the \a src null-terminated string, could be NULL.
/// \return
///     Returns the size copied into the \a dst buffer, in characters.\n
///     If \a dst is not NULL, the return value is the length of the string that is copied to the buffer, in characters,
/// not including the terminating null character.\n
///     If \a dst buffer is too small to hold the string, the string is truncated to \a nCharDst characters including the terminating null character,
/// and the return value is \a nCharDst.\n
///     If \a dst is NULL and \a nCharDst is 0, the return value is \a nCharSrc.\n
///     If the function fails, the return value is 0.
///
/// \see
///     NERvCopyString(const wchar_t*, size_t, wchar_t*), NERvCopyString(const wchar_t (&)[N_CHAR], size_t, wchar_t*)
///
/// \header{NERvGear/string.h}
static inline size_t NERvCopyString(size_t nCharSrc, const wchar_t* src, size_t nCharDst, wchar_t* dst)
{
    if (dst)
        return PrivateCopyString(src, nCharDst, dst);

    return nCharSrc;
}

/// \overloadfun{NERvCopyString(size_t, const wchar_t*, size_t, wchar_t*)}
///
/// This version is used when you don't know the length of the source string, the string's length will be counted if necessary.
///
/// \header{NERvGear/string.h}
static inline size_t NERvCopyString(const wchar_t* src, size_t nCharDst, wchar_t* dst)
{
    if (dst)
        return PrivateCopyString(src, nCharDst, dst);

    return NERvStringLength(src) + 1;
}

/// \brief Copies a double-null-terminated string to the destination buffer.
///
/// \param [in]  nCharSrc The size of the \a src buffer, in characters, including all the null terminators.
/// \param [in]  src      A pointer to the source string buffer, must not be NULL.
/// \param [in]  nCharDst The size of the \a dst buffer, in characters. If \a dst is NULL, this parameter must be 0.
/// \param [out] dst      A pointer to a buffer that receives the \a src double-null-terminated string, could be NULL.
/// \return
///     Returns the size copied into the string buffer, in characters.\n
///     If \a dst is not NULL, the return value is the length of the string that is copied to the buffer, in characters,
/// not including the terminating null characters.\n
///     If \a dst is NULL and \a len is 0, the return value is the buffer size required to store the string, in characters,
/// including the terminating null characters.\n
///     If the function fails, the return value is 0.
///
/// \header{NERvGear/string.h}
static inline size_t NERvCopyStringDoubleNull(size_t nCharSrc, const wchar_t* src, size_t nCharDst, wchar_t* dst)
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

/// \overloadfun{NERvCopyCharArray(size_t, const wchar_t*, size_t, wchar_t*)}
///
/// This version is used when you use a char array reference as the source char array.
///
/// \header{NERvGear/string.h}
template <size_t N_CHAR>
static inline size_t NERvCopyCharArray(const wchar_t (&src)[N_CHAR], size_t nChar, wchar_t* dst)
{
    return NERvCopyCharArray(N_CHAR, src, nChar, dst);
}

/// \overloadfun{NERvCopyString(size_t, const wchar_t*, size_t, wchar_t*)}
///
/// This version is used when you use a null-terminated char array reference as the source string.
///
/// \header{NERvGear/string.h}
template <size_t N_CHAR>
static inline size_t NERvCopyString(const wchar_t (&src)[N_CHAR], size_t nChar, wchar_t* dst)
{
    return NERvCopyString(N_CHAR, src, nChar, dst);
}

/// \overloadfun{NERvCopyStringDoubleNull(size_t, const wchar_t*, size_t, wchar_t*)}
///
/// This version is used when you use a double-null-terminated char array reference as the source string.
///
/// \header{NERvGear/string.h}
template <size_t N_CHAR>
static inline size_t NERvCopyStringDoubleNull(const wchar_t (&src)[N_CHAR], size_t nChar, wchar_t* dst)
{
    return NERvCopyStringDoubleNull(N_CHAR, src, nChar, dst);
}


/// @}



} // NERvGear


#endif // NVG_STRING_H


/***************************************************************
 * Name:      log.h
 * Purpose:   Defines Logging Class
 * Author:    GPBeta ()
 * Created:   2014-10-22
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_LOG_H
#define NVG_LOG_H

#include <NERvGear/def.h>

#include <stdarg.h>

namespace NERvGear {

/// \declns{NERvGear::LOG}
namespace LOG {

/// \brief Available logging level.
enum LEVEL {
    ERROR_LEVEL   = 0, ///< Error messages.
    WARN_LEVEL    = 1, ///< Warning messages.
    INFO_LEVEL    = 2, ///< Information messages.
    DEBUG_LEVEL   = 3, ///< Debugging messages.
    VERBOSE_LEVEL = 4  ///< Verbose messages.
};

} // log

// VC does not support __VA_ARGS__ macro, so we use C va_list way
#define _NVG_LOGV(_LEVEL) va_list argptr; va_start(argptr, format); NERvLogMessageV(_LEVEL, tag, format, argptr); va_end(argptr);


/// \ingroup mod_function
/// @{


/// \brief Logs a message with tag at specified level.
///
/// Takes \c printf() style variable argument syntax.
///
/// \param [in]  level  Logging level which could be one of the enumeration values of NERvGear::LOG::LEVEL.
/// \param [in]  tag    An optional string pointer to the custom tag(category), could be NULL.
/// \param [in]  format A pointer to the formating string.
///
/// \remark
///     Messages logged at a higher level than system logging level will be silent. The default logging level is NERvGear::LOG::INFO_LEVEL,
/// while the 'Verbose Mode' logging level is NERvGear::LOG::VERBOSE_LEVEL. In other words, logging messages in NERvGear::LOG::DEBUG_LEVEL
/// or NERvGear::LOG::VERBOSE_LEVEL will be filtered if 'Verbose Mode' was not turned on.\n
///     If the host program has a std output window (e.g. NERvGear.exe, does not produce log file under 'Verbose Mode'),
/// the messages will be printed on it.\n
///     If the host program does not have any std output window (e.g. SAO Utils.exe, produces log file under 'Verbose Mode'),
/// the messages will be invisible for users.
///
/// \note
///     You can also define NVG_NDEBUG macro in your project settings to strip the debug and verbose messages completely from the codes.
///
/// \see
///     NERvLogMessageV()
///
/// \header{NERvGear/log.h}
NVG_EXPORT(void)  NERvLogMessage(LOG::LEVEL level, const wchar_t* tag, const wchar_t* format, ...);

/// \overloadfun{NERvLogMessage()}
///
/// Takes \c vprintf() style variable argument syntax.
///
/// \header{NERvGear/log.h}
NVG_EXPORT(void) NERvLogMessageV(LOG::LEVEL level, const wchar_t* tag, const wchar_t* format, va_list argptr);

/// \brief Logs an error message with tag.
///
/// \note
///     This function calls NERvLogMessage() using NERvGear::LOG::ERROR_LEVEL for convenience purposes only.
///
/// \header{NERvGear/log.h}
static inline void NERvLogError(const wchar_t* tag, const wchar_t* format, ...) { _NVG_LOGV(LOG::ERROR_LEVEL) }

/// \brief Logs a warning message with tag.
///
/// \note
///     This function calls NERvLogMessage() using NERvGear::LOG::WARN_LEVEL for convenience purposes only.
///
/// \header{NERvGear/log.h}
static inline void  NERvLogWarn(const wchar_t* tag, const wchar_t* format, ...) { _NVG_LOGV(LOG::WARN_LEVEL) }

/// \brief Logs an information message with tag.
///
/// \note
///     This function calls NERvLogMessage() using NERvGear::LOG::INFO_LEVEL for convenience purposes only.
///
/// \header{NERvGear/log.h}
static inline void  NERvLogInfo(const wchar_t* tag, const wchar_t* format, ...) { _NVG_LOGV(LOG::INFO_LEVEL) }

#ifndef NVG_NDEBUG

/// \brief Logs a debug message with tag.
///
/// \note
///     This function calls NERvLogMessage() using NERvGear::LOG::DEBUG_LEVEL for convenience purposes only.
///
/// \header{NERvGear/log.h}
static inline void   NERvLogDebug(const wchar_t* tag, const wchar_t* format, ...) { _NVG_LOGV(LOG::DEBUG_LEVEL) }

/// \brief Logs a verbose message with tag.
///
/// \note
///     This function calls NERvLogMessage() using NERvGear::LOG::VERBOSE_LEVEL for convenience purposes only.
///
/// \header{NERvGear/log.h}
static inline void NERvLogVerbose(const wchar_t* tag, const wchar_t* format, ...) { _NVG_LOGV(LOG::VERBOSE_LEVEL) }

#else
static inline void   NERvLogDebug(const wchar_t* tag, const wchar_t* format, ...) {}
static inline void NERvLogVerbose(const wchar_t* tag, const wchar_t* format, ...) {}
#endif // NVG_NDEBUG


/// @}


}

#endif // NVG_LOG_H

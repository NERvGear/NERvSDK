
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

namespace LOG {

enum LEVEL {
    ERROR_LEVEL     = 0,
    WARN_LEVEL    = 1,
    INFO_LEVEL    = 2,
    DEBUG_LEVEL   = 3,
    VERBOSE_LEVEL = 4
};

}


NVG_EXPORT(void)  NERvLogMessage(LOG::LEVEL level, const wchar_t* tag, const wchar_t* format, ...);
NVG_EXPORT(void) NERvLogMessageV(LOG::LEVEL level, const wchar_t* tag, const wchar_t* format, va_list argptr);

// handy logging
// VC does not support __VA_ARGS__ macro, so we use C va_list way
#define _NVG_LOGV(_LEVEL) va_list argptr; va_start(argptr, format); NERvLogMessageV(_LEVEL, tag, format, argptr); va_end(argptr);
static inline void NERvLogError(const wchar_t* tag, const wchar_t* format, ...) { _NVG_LOGV(LOG::ERROR_LEVEL) }
static inline void  NERvLogWarn(const wchar_t* tag, const wchar_t* format, ...) { _NVG_LOGV(LOG::WARN_LEVEL) }
static inline void  NERvLogInfo(const wchar_t* tag, const wchar_t* format, ...) { _NVG_LOGV(LOG::INFO_LEVEL) }
#ifndef NVG_NDEBUG
static inline void   NERvLogDebug(const wchar_t* tag, const wchar_t* format, ...) { _NVG_LOGV(LOG::DEBUG_LEVEL) }
static inline void NERvLogVerbose(const wchar_t* tag, const wchar_t* format, ...) { _NVG_LOGV(LOG::VERBOSE_LEVEL) }
#else
static inline void   NERvLogDebug(const wchar_t* tag, const wchar_t* format, ...) {}
static inline void NERvLogVerbose(const wchar_t* tag, const wchar_t* format, ...) {}
#endif // NVG_NDEBUG

}

#endif // NVG_LOG_H

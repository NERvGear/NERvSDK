
#ifndef NVG_IMESSAGEHANDLER_H
#define NVG_IMESSAGEHANDLER_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

#if defined(WIN64) || defined(_WIN64)
typedef uint64_t wparam_t;
typedef  int64_t lparam_t;
#else
typedef uint32_t wparam_t;
typedef  int32_t lparam_t;
#endif // WIN64 || _WIN64

NVG_INTERFACE_EXTEND(IMessageHandler, IUnknown) {

    virtual long NVG_METHOD HandleMessage(unsigned message, wparam_t wParam, lparam_t lParam) NVG_PURE;

};

// declare interface ID
NVG_DEFINE_UID(NVG_ID_IMessageHandler, 0x654D4901, 0x7373, 0x6761, 0x65, 0x48, 0x61, 0x6E, 0x64, 0x6C, 0x65, 0x72); // "IMessageHandler" version 1

// define latest API
//#define ID_IMessageHandler NVG_ID_IMessageHandler
static const UID& ID_IMessageHandler = NVG_ID_IMessageHandler;

}

#else // C

#endif // __cplusplus

#endif // NVG_IMESSAGEHANDLER_H

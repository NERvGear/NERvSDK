
#ifndef NVG_IDROPTARGET_H
#define NVG_IDROPTARGET_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

struct IDataObject;

namespace UI {

class PixelPoint;

} // UI

//! Reimplement of standard IDropTarget COM interface.
//! It's safe to cast a pointer between NERvGear::IDropTarget and ::IDropTarget.
NVG_INTERFACE_EXTEND(IDropTarget, IUnknown) {
    virtual long NVG_METHOD DragEnter(IDataObject* pDataObj, unsigned grfKeyState, UI::PixelPoint pt, unsigned* pdwEffect) NVG_PURE;
    virtual long NVG_METHOD DragOver(unsigned grfKeyState, UI::PixelPoint pt, unsigned* pdwEffect) NVG_PURE;
    virtual long NVG_METHOD DragLeave() NVG_PURE;
    virtual long NVG_METHOD Drop(IDataObject* pDataObj, unsigned grfKeyState, UI::PixelPoint pt, unsigned* pdwEffect) NVG_PURE;
};

// declare IDs
NVG_DEFINE_UID(NVG_ID_IDropTarget, 0x00000122, 0x0000, 0x0000, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46); // 00000122-0000-0000-C000-000000000046

// define aliases
//#define ID_IDropTarget NVG_ID_IDropTarget
static const UID& ID_IDropTarget = NVG_ID_IDropTarget;

}

#else // C

#endif // __cplusplus

#endif // NVG_IDROPTARGET_H

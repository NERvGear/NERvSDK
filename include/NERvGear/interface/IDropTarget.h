
/***************************************************************
 * Name:      IDropTarget.h
 * Purpose:   Defines IDropTarget Interface
 * Author:    GPBeta ()
 * Created:   2015-05-20
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_IDROPTARGET_H
#define NVG_IDROPTARGET_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

struct IDataObject;

namespace UI {

class PixelPoint;

} // UI

/// \ingroup mod_itf_com
///
/// \brief Reimplementation of standard IDropTarget COM interface.
///
/// \note
///     It's safe to cast a pointer between NERvGear::IDropTarget and ::IDropTarget.
/// \declid{Interface,NERvGear::ID_IDropTarget,00000122-0000-0000-C000-000000000046}
NVG_INTERFACE_EXTEND(IDropTarget, IUnknown) {

    virtual long NVG_METHOD DragEnter(IDataObject* pDataObj, unsigned grfKeyState, UI::PixelPoint pt, unsigned* pdwEffect) NVG_PURE;
    virtual long NVG_METHOD DragOver(unsigned grfKeyState, UI::PixelPoint pt, unsigned* pdwEffect) NVG_PURE;
    virtual long NVG_METHOD DragLeave() NVG_PURE;
    virtual long NVG_METHOD Drop(IDataObject* pDataObj, unsigned grfKeyState, UI::PixelPoint pt, unsigned* pdwEffect) NVG_PURE;
    
};

// Interface ID
NVG_EXPORT_UID(NVG_ID_IDropTarget, 0x00000122, 0x0000, 0x0000, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46);
static const UID& ID_IDropTarget = NVG_ID_IDropTarget; ///< 00000122-0000-0000-C000-000000000046
//#define ID_IDropTarget NVG_ID_IDropTarget

}

#else // C

#endif // __cplusplus

#endif // NVG_IDROPTARGET_H

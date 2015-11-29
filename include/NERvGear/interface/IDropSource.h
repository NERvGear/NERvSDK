
/***************************************************************
 * Name:      IDropSource.h
 * Purpose:   Defines IDropSource Interface
 * Author:    GPBeta ()
 * Created:   2015-05-20
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_IDROPSOURCE_H
#define NVG_IDROPSOURCE_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

/// \ingroup mod_itf_com
///
/// \brief Reimplementation of standard IDropSource COM interface.
/// 
/// \note
///     It's safe to cast a pointer between NERvGear::IDropSource and ::IDropSource.
///
/// \declid{Interface,NERvGear::ID_IDropSource,00000121-0000-0000-C000-000000000046}
NVG_INTERFACE_EXTEND(IDropSource, IUnknown) {

    virtual long NVG_METHOD QueryContinueDrag(int fEscapePressed, unsigned grfKeyState) NVG_PURE;
    virtual long NVG_METHOD GiveFeedback(unsigned dwEffect) NVG_PURE;
    
};

// Interface ID
NVG_EXPORT_UID(NVG_ID_IDropSource, 0x00000121, 0x0000, 0x0000, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46);
static const UID& ID_IDropSource = NVG_ID_IDropSource; ///< 00000121-0000-0000-C000-000000000046
//#define ID_IDropSource NVG_ID_IDropSource

}

#else // C

#endif // __cplusplus

#endif // NVG_IDROPSOURCE_H

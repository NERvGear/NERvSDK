
/***************************************************************
 * Name:      IExecute.h
 * Purpose:   Defines IExecute Interface
 * Author:    GPBeta ()
 * Created:   2015-05-20
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_IEXECUTE_H
#define NVG_IEXECUTE_H

#include "IUnknown.h"

#ifdef __cplusplus

namespace NERvGear {

namespace UI {

struct IWindow;

} // UI

namespace EXEC {

typedef long TYPE;

} // EXEC

/// \ingroup mod_itf_nvg
///
/// \brief Nerve Gear execution interface.
///
/// \note
///     If an action filter returns an error or S_FALSE from its IExecute::Invoke(), the launcher menu will be kept and not get dismissed.
/// \see
///     NERvExecute()
///
/// \declid{Interface,NERvGear::ID_IData,00000001-0000-0000-4945-786563757465}
NVG_INTERFACE_EXTEND(IExecute, IUnknown) {

    /// Execute an action.
    ///
    /// \param [in]  window Reserved, must be NULL.
    /// \param [in]  cmd    The action command.
    /// \param [in]  param  The action parameter, can be NULL.
    /// \param [in]  cwd    The working directory for the action, can be NULL.
    /// \param [in]  type   The action type, can be one of the enumeration values of NERvGear::EXEC::ACTION or a custom value.
    /// \param [in]  option Reserved.
    /// \return
    ///     Returns the action's execution result.
    /// \retval S_OK    Success, indicates that caller should stop searching the filter chain.
    /// \retval S_FALSE Success, indicates that caller should stop searching the filter chain and this action could be ignored.
    /// \retval E_FAIL  Fail, indicates that caller could continue searching the filter chain.
	virtual long NVG_METHOD Invoke(UI::IWindow* window, const wchar_t* cmd, const wchar_t* param, const wchar_t* cwd, EXEC::TYPE type, long option) NVG_PURE;

};

// Interface ID
NVG_EXPORT_UID(NVG_ID_IExecute, 0x00000001, 0x0000, 0x0000, 0x49, 0x45, 0x78, 0x65, 0x63, 0x75, 0x74, 0x65);
static const UID& ID_IExecute = NVG_ID_IExecute; //< "IExecute" version 1
//#define ID_IExecute NVG_ID_IExecute

} // NERvGear

#else // C

#endif // __cplusplus

#endif // NVG_IEXECUTE_H

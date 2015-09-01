
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

/// Execution interface.
NVG_INTERFACE_EXTEND(IExecute, IUnknown) {

    /// Execute an action.
    ///
    /// \param [in]  window Reserved, the window which execute the action, can be NULL.
    /// \param [in]  cmd The action command, can be NULL.
    /// \param [in]  param The action parameter, can be NULL.
    /// \param [in]  cwd The working directory for the action, can be NULL.
    /// \param [in]  type The action type. Defined in <NERvGear/NERv1API.h>.
    /// \param [in]  option Reserved.
    /// \retval S_OK    Success, system stops searching the filter chain.
    /// \retval S_FALSE Success, system stops searching the filter chain and tell caller this execution has no action.
    /// \retval E_FAILED Failed, system continues search the filter chain.
    /// \return Returns the execution result. System continues search the filter chain if the filter return an error, otherwise, the system
    /// stops searching if the filter succeed.  Finally, if no filter executes the execution successfully, system execute this action
    /// with default behaviour.
    /// \note If an execution returns an error or EXEC::S_NO_ACTION code, the launcher menu will be kept and not dismissed.
	virtual long NVG_METHOD Invoke(UI::IWindow* window, const wchar_t* cmd, const wchar_t* param, const wchar_t* cwd, EXEC::TYPE type, long option) NVG_PURE;

};

// declare IDs
NVG_DEFINE_UID(NVG_ID_CActionListener, CATALOG::SYSTEM, 0x7B76, 0x4FB7, 0xA4, 0xA4, 0xF8, 0x90, 0x4A, 0xCA, 0xB7, 0xD0); // {::SYSTEM-7B76-4FB7-A4A4-F8904ACAB7D0}
NVG_DEFINE_UID(NVG_ID_CActionFilter,   CATALOG::SYSTEM, 0x7B76, 0x4FB7, 0xA4, 0xA4, 0xF8, 0x90, 0x4A, 0xCA, 0xB7, 0xD1); // {::SYSTEM-7B76-4FB7-A4A4-F8904ACAB7D1}
NVG_DEFINE_UID(NVG_ID_IExecute,             0x00000001, 0x0000, 0x0000, 0x49, 0x45, 0x78, 0x65, 0x63, 0x75, 0x74, 0x65); // "IExecute" version 1

// define aliases
//#define ID_CActionListener NVG_ID_CActionListener
//#define ID_CActionFilter NVG_ID_CActionFilter
//#define ID_IExecute NVG_ID_IExecute
static const UID& ID_CActionListener = NVG_ID_CActionListener;
static const UID& ID_CActionFilter = NVG_ID_CActionFilter;
static const UID& ID_IExecute = NVG_ID_IExecute;

} // NERvGear

#else // C

#endif // __cplusplus

#endif // NVG_IEXECUTE_H

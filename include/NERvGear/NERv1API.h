
/***************************************************************
 * Name:      NERv1API.h
 * Purpose:   Defines Nerve Gear SDK API Version 1
 * Author:    GPBeta ()
 * Created:   2014-10-22
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_NERV1API_H
#define NVG_NERV1API_H

#include <NERvGear/sound.h>
#include <NERvGear/UI.h>

namespace NERvGear {

class Event;
struct IPlugin;
struct IUnknown;
struct IRunnable;
struct IEventHandler;
struct INotification;

namespace EVT {

typedef long TYPE;

} // EVT

/// \declns{NERvGear::TASK}
namespace TASK {

/// \brief Available task flags for NERvQueueTask().
/// 
/// See the \a Flags parameter of [QueueUserWorkItem function](https://msdn.microsoft.com/en-us/library/windows/desktop/ms684957)
/// for more information about the meaning of these flags.
enum FLAG {
    EXECUTEDEFAULT               = 0x00000000,
    EXECUTEINIOTHREAD            = 0x00000001,
    EXECUTEINPERSISTENTTHREAD    = 0x00000080,
    EXECUTELONGFUNCTION          = 0x00000010,
    TRANSFER_IMPERSONATION       = 0x00000100
};

typedef long TYPE;

} // TASK

/// \declns{NERvGear::EXEC}
namespace EXEC {

/// \brief Available action types for NERvExecute().
enum ACTION {
    NONE = 0,
    PROGRAM,
    FILE,
    FOLDER,
    URL,
    COMMAND
};

typedef long TYPE;

} // EXEC

NVG_EXPORT(long) NERv1Balloon(const wchar_t* title, const wchar_t* msg);
//NVG_EXPORT(long) NERv1Toast(INotification* notify);
NVG_EXPORT(long) NERv1Notify(INotification* notify);
//NVG_EXPORT(long) NERv1Message(INotification* notify);
//NVG_EXPORT(long) NERv1Dialog(INotification* notify);

NVG_EXPORT(const wchar_t*) NERv1GetModulePath(MODULE* module);
NVG_EXPORT(IPlugin*) NERv1PluginInstance(MODULE* module);

NVG_EXPORT(EVT::TYPE) NERv1RegisterEvent(const UID& id, MODULE* module);
NVG_EXPORT(long) NERv1BindEvent(IEventHandler* handler, EVT::TYPE type, MODULE* module);
NVG_EXPORT(long) NERv1UnbindEvent(IEventHandler* handler, EVT::TYPE type, MODULE* module);
NVG_EXPORT(long) NERv1ProcessEvent(IEventHandler* handler, Event& event, MODULE* module);
NVG_EXPORT(long) NERv1QueueEvent(IEventHandler* handler, Event* event, MODULE* module);
NVG_EXPORT(long) NERv1QueueTask(IRunnable* task, IEventHandler* handler, IUnknown* userdata, TASK::TYPE type, MODULE* module);

NVG_EXPORT(long) NERv1Execute(UI::IWindow* window, const wchar_t* cmd, const wchar_t* param, const wchar_t* cwd, EXEC::TYPE type, long option, MODULE* module);


/// \ingroup mod_function
/// @{


/// \brief Shows a balloon notification closed to the task bar icon.
///
/// \param [in]  title The balloon title string.
/// \param [in]  msg   The balloon content string.
/// \retval S_OK   Success. The balloon has been shown.
/// \retval E_FAIL Failed with unknown error.
///
/// \version
/// 	0.1.0 NERv1Balloon()
///
/// \header{NERvGear/NERv1API.h}
static inline long NERvBalloon(const wchar_t* title, const wchar_t* msg) { return NERv1Balloon(title, msg); }

/// \brief Pops up an icon to notify user.
/// 
/// The notification icon keeps blinking until user click on it.
///
/// \note
///     This is a unpublished API while the NERvGear::INotification interface is not provided by the NERvSDK yet.
///
/// \param [in]  notify A pointer to the INotification interface.
/// \retval S_OK         Success. The notification has been queued.
/// \retval E_INVALIDARG The \a notify is NULL.
/// \retval E_FAIL       Failed with unknown error.
///
/// \version
/// 	0.1.0 NERv1Notify()
///
/// \header{NERvGear/NERv1API.h}
static inline long NERvNotify(INotification* notify) { return NERv1Notify(notify); }

//static inline long NERvToast(INotification* notify) { return NERv1Toast(notify); }
//static inline long NERvMessage(INotification* notify) { return NERv1Message(notify); }
//static inline long NERvDialog(INotification* notify) { return NERv1Dialog(notify); }

/// \brief Retrieves the plug-in path of current module.
///
/// The returned string is generally the full path to the plug-in directory, not including the module file name. e.g.
/// > "X:\SOME_DIRS\SAO Utils\Plugins\Plug-in Demo"
///
/// \version
/// 	0.1.0 NERv1GetModulePath()
///
/// \header{NERvGear/NERv1API.h}
static inline const wchar_t* NERvGetModulePath() { return NERv1GetModulePath(&NVG_MODULE); }

/// \brief Retrieves the plug-in instance of current module.
///
/// \return
///     Returns an interface pointer copy of the plug-in.\n
/// If this function fails, the return value is NULL.
///
/// \remark
///     The returned pointer can be converted to its original plug-in class pointer using <tt>static_cast<>()</tt> syntax.
///
/// \note
///     IPlugin::AddRef() was called to increase the interface's reference count before the function returns,
/// please remember to call IPlugin::Release() when you no longer need the interface pointer.
///
/// \version
/// 	0.1.0 NERv1PluginInstance()
///
/// \header{NERvGear/NERv1API.h}
static inline IPlugin* NERvPluginInstance() { return NERv1PluginInstance(&NVG_MODULE); }

/// \brief Registers the event handler to process a type of events.
///
/// \param [in]  handler A pointer to the NERvGear::IEventHandler interface processing the event.
/// \param [in]  type    The event type that the event handler can processed.
/// \retval S_OK         Success, the event handler is registered successfully.
/// \retval E_INVALIDARG Fail, the \a handler is NULL, or \a type is NVG_ANY.
/// \retval E_FAIL       Failed to register the event handler with unknown error.
///
/// \remark
///     Registered event handlers will get notified when the responding type of event is broadcast by NERvProcessEvent() or NERvQueueEvent().
/// One event handler could bind the same event type multiple times, remember to call NERvUnbindEvent() with the same times and parameters
/// to unregister all the event handlers.
///
/// \version
/// 	0.1.0 NERv1BindEvent()
///
/// \header{NERvGear/NERv1API.h}
static inline long NERvBindEvent(IEventHandler* handler, EVT::TYPE type) { return NERv1BindEvent(handler, type, &NVG_MODULE); }

/// \brief Unregisters the event handler.
///
/// \param [in]  handler A pointer to the NERvGear::IEventHandler interface processing the event.
/// \param [in]  type    The event type that the event handler can processed.
/// \retval S_OK         Success, the event handler is registered successfully.
/// \retval E_INVALIDARG Fail, the \a handler is NULL, or \a type is NVG_ANY.
/// \retval E_FAIL       Failed to register the event handler with unknown error.
///
/// \version
/// 	0.1.0 NERv1UnbindEvent()
/// \see
///     NERvBindEvent()
///
/// \header{NERvGear/NERv1API.h}
static inline long NERvUnbindEvent(IEventHandler* handler, EVT::TYPE type) { return NERv1UnbindEvent(handler, type, &NVG_MODULE); }

/// \brief Sends an event to the event handler or handlers.
///
/// \param [in]  handler A pointer to the NERvGear::IEventHandler interface processing the event, can be NULL.
/// \param [in]  event   The event to be processed.
/// \return
///     Returns the value that the handler's IEventHandler::HandlerEvent() method returned.
///
/// \remark
///     If \a handler is NULL, the specified event will be broadcast to all event handlers that register to process this type of event,
/// and the return value would be S_OK if succeed or E_FAIL if failed to broadcast this event.\n
///     If \a handler is not NULL, the call to this function is the same as calling a handler's IEventHandler::HandlerEvent() method directly.
///
/// \version
/// 	0.1.0 NERv1ProcessEvent()
/// \see
///     NERvQueueEvent(), NERvBindEvent()
///
/// \header{NERvGear/NERv1API.h}
static inline long NERvProcessEvent(IEventHandler* handler, Event& event) { return NERv1ProcessEvent(handler, event, &NVG_MODULE); }

/// \brief Post an event in the event queue of main thread.
///
/// This function returns without waiting for the thread to process the event.
///
/// \param [in]  handler A pointer to the NERvGear::IEventHandler interface processing the event, can be NULL.
/// \param [in]  event   A pointer to an event to be processed.
/// \retval S_OK         Success, the event is queued successfully.
/// \retval E_INVALIDARG Fail, the \a handler or \a event is NULL.
/// \retval E_FAIL       Failed to queue the event with unknown error.
///
/// \remark
///     If \a handler is NULL, the specified event will be broadcast to all event handlers that register to process this type of event.\n
///     If \a handler is not NULL, the \a handle will process this event.
///
/// \version
/// 	0.1.0 NERv1QueueEvent()
/// \see
///     NERvProcessEvent(), NERvBindEvent()
///
/// \header{NERvGear/NERv1API.h}
static inline long NERvQueueEvent(IEventHandler* handler, Event* event) { return NERv1QueueEvent(handler, event, &NVG_MODULE); }

/// \brief Queues a task to a worker thread in the thread pool.
///
/// \param [in]  task     A pointer to the NERvGear::IRunnable interface running the task.
/// \param [in]  handler  A pointer to the NERvGear::IEventHandler interface handling the task event, can be NULL.
/// \param [in]  userdata A pointer to the NERvGear::IUnknown interface containing user data, can be NULL.
/// \param [in]  type     The flags that control execution, can be one or more of the NERvGear::TASK::FLAG enumeration values.
/// \retval S_OK         Success, the task is queued successfully.
/// \retval E_INVALIDARG Fail, the \a task is NULL.
/// \retval E_FAIL       Failed to queue the task with unknown error.
///
/// \remark
///     The codes of queued task will be executed in a worker thread, pleased be careful about the thread safe and locking problems.\n
/// If \a handler is not NULL, specified event handler will receive a NERvGear::EVT::TASKQUEUE event when the task is finished
/// (executed or discard) in the main thread. The task event could be converted to NERvGear::TaskQueueEvent using
/// <TT>static_cast<>()</TT> syntax, the value of its \a retcode is the what the IRunnable::Run() method of queued task returned.
///
/// \version
/// 	0.1.0 NERv1QueueTask()
///
/// \header{NERvGear/NERv1API.h}
static inline long NERvQueueTask(IRunnable* task, IEventHandler* handler, IUnknown* userdata, TASK::TYPE type) { return NERv1QueueTask(task, handler, userdata, type, &NVG_MODULE); }

/// \brief Executes an action.
///
/// This function is used to open a file, URL or run a command with associated program or filter.
///
/// \param [in]  window Reserved, must be NULL.
/// \param [in]  cmd    The action command to be executed, \a type determinate the meaning of this command string.
/// | Action Type   | Meaning                                                                                           |
/// | ------------- | ------------------------------------------------------------------------------------------------- |
/// | EXEC::NONE    | Perform no action.                                                                                |
/// | EXEC::PROGRAM | Run a program, \a cwd is a path to the program file.                                              |
/// | EXEC::FILE    | Open a file, \a cwd is a the path to the file.                                                    |
/// | EXEC::FOLDER  | Open a folder, \a cwd is a path to the folder.                                                    |
/// | EXEC::URL     | Open a URL, \a cwd could be a custom or a general URI string started with <TT>XXX:\\</TT> prefix. |
/// | EXEC::COMMAND | Execute a command, \a cwd is a general command line string.                                       |
/// \param [in]  param  The parameter for command, can be NULL.
/// \param [in]  cwd    Reserved, must be NULL.
/// \param [in]  type   The type of the action, could be one of the NERvGear::EXEC::ACTION enumeration values.
/// \param [in]  option Reserved, must be 0.
/// \retval S_OK    Success, the action is executed successfully.
/// \retval S_FALSE Success, it's similar to S_OK but also indicates that the caller could 'ignore' this execution.
///                 Note that if \a type is NERvGear::EXEC::NONE, then the return value is also S_FALSE.
/// \retval E_FAIL  Failed with unknown error and the action is not executed.
///
/// \remark
///     This function firstly searches for the objects implementing NERvGear::CActionListener and calls all of their IExecute::Invoke() methods.
/// Then it searches for the objects implementing NERvGear::CActionFilter and calls their IExecute::Invoke() methods,
/// if one of these action filters returns an success code, the function stops further searching and return that code immediately.
/// Finally, if none of the action filters could handle this action, it tries to execute this action with system associated program.
///
/// \note
///     The launcher menu also use this function to execute actions, action filters (NERvGear::CActionFilter implementations)
/// that return S_FALSE will request to keep the launcher showing after executing this action.
///
/// \version
/// 	0.1.0 NERv1Execute()
///
/// \header{NERvGear/NERv1API.h}
static inline long NERvExecute(UI::IWindow* window, const wchar_t* cmd, const wchar_t* param, const wchar_t* cwd, EXEC::TYPE type, long option)
{ return NERv1Execute(window, cmd, param, cwd, type, option, &NVG_MODULE); }


/// @}


}

#endif // NVG_NERV1API_H

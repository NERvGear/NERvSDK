
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

namespace TASK {

enum FLAG {
    // ses https://msdn.microsoft.com/en-us/library/windows/desktop/ms684957(v=vs.85).aspx
    EXECUTEDEFAULT               = 0x00000000,
    EXECUTEINIOTHREAD            = 0x00000001,
    EXECUTEINPERSISTENTTHREAD    = 0x00000080,
    EXECUTELONGFUNCTION          = 0x00000010,
    TRANSFER_IMPERSONATION       = 0x00000100

};

typedef long TYPE;

} // TASK

namespace EXEC {

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

// latest APIs
static inline long NERvBalloon(const wchar_t* title, const wchar_t* msg) { return NERv1Balloon(title, msg); }
//static inline long NERvToast(INotification* notify) { return NERv1Toast(notify); }
static inline long NERvNotify(INotification* notify) { return NERv1Notify(notify); }
//static inline long NERvMessage(INotification* notify) { return NERv1Message(notify); }
//static inline long NERvDialog(INotification* notify) { return NERv1Dialog(notify); }

static inline const wchar_t* NERvGetModulePath() { return NERv1GetModulePath(&NVG_MODULE); }
static inline IPlugin* NERvPluginInstance() { return NERv1PluginInstance(&NVG_MODULE); }

static inline long NERvBindEvent(IEventHandler* handler, EVT::TYPE type) { return NERv1BindEvent(handler, type, &NVG_MODULE); }
static inline long NERvUnbindEvent(IEventHandler* handler, EVT::TYPE type) { return NERv1UnbindEvent(handler, type, &NVG_MODULE); }
static inline long NERvProcessEvent(IEventHandler* handler, Event& event) { return NERv1ProcessEvent(handler, event, &NVG_MODULE); }
static inline long NERvQueueEvent(IEventHandler* handler, Event* event) { return NERv1QueueEvent(handler, event, &NVG_MODULE); }
static inline long NERvQueueTask(IRunnable* task, IEventHandler* handler, IUnknown* userdata, TASK::TYPE type) { return NERv1QueueTask(task, handler, userdata, type, &NVG_MODULE); }

static inline long NERvExecute(UI::IWindow* window, const wchar_t* cmd, const wchar_t* param, const wchar_t* cwd, EXEC::TYPE type, long option)
{ return NERv1Execute(window, cmd, param, cwd, type, option, &NVG_MODULE); }

}

#endif // NVG_NERV1API_H

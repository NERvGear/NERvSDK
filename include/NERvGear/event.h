
/***************************************************************
 * Name:      event.h
 * Purpose:   Defines Nerve Gear Events and Event Classes
 * Author:    GPBeta ()
 * Created:   2014-12-27
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_EVENT_H
#define NVG_EVENT_H

#ifdef _NVG_PRIVATE_API
#include <UI/Rect.h>
#else
#include <NERvGear/UI/Rect.h>
#endif // _NVG_BUILD_DLL

// TODO: separate events into files

namespace NERvGear {

namespace EVT {

enum ID {

NONE                       = 0x0000,
//CREATE                     = 0x0001,
DESTROY                    = 0x0002,
MOVE                       = 0x0003,
SIZE                       = 0x0005,
//
//ACTIVATE                   = 0x0006,

SETFOCUS                   = 0x0007,
KILLFOCUS                  = 0x0008,
ENABLE                     = 0x000A,
//SETREDRAW                  = 0x000B,
//SETTEXT                    = 0x000C,
//GETTEXT                    = 0x000D,
//GETTEXTLENGTH              = 0x000E,
PAINT                      = 0x000F,
//CLOSE                      = 0x0010,
//
QUIT                       = 0x0012,
//ERASEBKGND                 = 0x0014,
//SYSCOLORCHANGE             = 0x0015,
SHOW                       = 0x0018,    // origin: WM_SHOWWINDOW
//WININICHANGE               = 0x001A,
//SETTINGCHANGE              = WININICHANGE,
//
//DEVMODECHANGE              = 0x001B,
//ACTIVATEAPP                = 0x001C,
//FONTCHANGE                 = 0x001D,
//TIMECHANGE                 = 0x001E,
//CANCELMODE                 = 0x001F,
//SETCURSOR                  = 0x0020,
//MOUSEACTIVATE              = 0x0021,
//CHILDACTIVATE              = 0x0022,
//QUEUESYNC                  = 0x0023,
//
//GETMINMAXINFO              = 0x0024,
//PAINTICON                  = 0x0026,
//ICONERASEBKGND             = 0x0027,
//NEXTDLGCTL                 = 0x0028,
//SPOOLERSTATUS              = 0x002A,
//DRAWITEM                   = 0x002B,
//MEASUREITEM                = 0x002C,
//DELETEITEM                 = 0x002D,
//VKEYTOITEM                 = 0x002E,
//CHARTOITEM                 = 0x002F,
//SETFONT                    = 0x0030,
//GETFONT                    = 0x0031,
//SETHOTKEY                  = 0x0032,
//GETHOTKEY                  = 0x0033,
//QUERYDRAGICON              = 0x0037,
//COMPAREITEM                = 0x0039,
//
//GETOBJECT                  = 0x003D,
//
//COMPACTING                 = 0x0041,
//COMMNOTIFY                 = 0x0044,
//WINDOWPOSCHANGING          = 0x0046,
//WINDOWPOSCHANGED           = 0x0047,
//
//POWER                      = 0x0048,
//
//COPYDATA                   = 0x004A,
//CANCELJOURNAL              = 0x004B,
//
//NOTIFY                     = 0x004E,
//INPUTLANGCHANGEREQUEST     = 0x0050,
//INPUTLANGCHANGE            = 0x0051,
//TCARD                      = 0x0052,
//HELP                       = 0x0053,
//USERCHANGED                = 0x0054,
//NOTIFYFORMAT               = 0x0055,
//
CONTEXTMENU                = 0x007B,
//STYLECHANGING              = 0x007C,
//STYLECHANGED               = 0x007D,
//DISPLAYCHANGE              = 0x007E,
//GETICON                    = 0x007F,
//SETICON                    = 0x0080,
//
//NCCREATE                   = 0x0081,
//NCDESTROY                  = 0x0082,
//NCCALCSIZE                 = 0x0083,
//NCHITTEST                  = 0x0084,
//NCPAINT                    = 0x0085,
//NCACTIVATE                 = 0x0086,
//GETDLGCODE                 = 0x0087,
//
//SYNCPAINT                  = 0x0088,
//
//NCMOUSEMOVE                = 0x00A0,
//NCLBUTTONDOWN              = 0x00A1,
//NCLBUTTONUP                = 0x00A2,
//NCLBUTTONDBLCLK            = 0x00A3,
//NCRBUTTONDOWN              = 0x00A4,
//NCRBUTTONUP                = 0x00A5,
//NCRBUTTONDBLCLK            = 0x00A6,
//NCMBUTTONDOWN              = 0x00A7,
//NCMBUTTONUP                = 0x00A8,
//NCMBUTTONDBLCLK            = 0x00A9,
//
//NCXBUTTONDOWN              = 0x00AB,
//NCXBUTTONUP                = 0x00AC,
//NCXBUTTONDBLCLK            = 0x00AD,
//
//INPUT_DEVICE_CHANGE        = 0x00FE,
//INPUT                      = 0x00FF,

KEYFIRST                   = 0x0100,
KEYDOWN                    = 0x0100,
KEYUP                      = 0x0101,
CHAR                       = 0x0102,
DEADCHAR                   = 0x0103,
SYSKEYDOWN                 = 0x0104,
SYSKEYUP                   = 0x0105,
SYSCHAR                    = 0x0106,
SYSDEADCHAR                = 0x0107,
UNICHAR                    = 0x0109,
KEYLAST                    = 0x0109,

//IME_STARTCOMPOSITION       = 0x010D,
//IME_ENDCOMPOSITION         = 0x010E,
//IME_COMPOSITION            = 0x010F,
//IME_KEYLAST                = 0x010F,
//
//INITDIALOG                 = 0x0110,
COMMAND                    = 0x0111,
//SYSCOMMAND                 = 0x0112,
TIMER                      = 0x0113,
HSCROLL                    = 0x0114,
VSCROLL                    = 0x0115,
//INITMENU                   = 0x0116,
//INITMENUPOPUP              = 0x0117,
//
//GESTURE                    = 0x0119,
//GESTURENOTIFY              = 0x011A,
//
//MENUSELECT                 = 0x011F,
//MENUCHAR                   = 0x0120,
//ENTERIDLE                  = 0x0121,
//
//MENURBUTTONUP              = 0x0122,
//MENUDRAG                   = 0x0123,
//MENUGETOBJECT              = 0x0124,
//UNINITMENUPOPUP            = 0x0125,
//MENUCOMMAND                = 0x0126,
//
//CHANGEUISTATE              = 0x0127,
//UPDATEUISTATE              = 0x0128,
//QUERYUISTATE               = 0x0129,
//
//CTLCOLORMSGBOX             = 0x0132,
//CTLCOLOREDIT               = 0x0133,
//CTLCOLORLISTBOX            = 0x0134,
//CTLCOLORBTN                = 0x0135,
//CTLCOLORDLG                = 0x0136,
//CTLCOLORSCROLLBAR          = 0x0137,
//CTLCOLORSTATIC             = 0x0138,
//MN_GETHMENU                    = 0x01E1,

MOUSEFIRST                 = 0x0200,
MOUSEMOVE                  = 0x0200,
LBUTTONDOWN                = 0x0201,
LBUTTONUP                  = 0x0202,
LBUTTONDBLCLK              = 0x0203,
RBUTTONDOWN                = 0x0204,
RBUTTONUP                  = 0x0205,
RBUTTONDBLCLK              = 0x0206,
MBUTTONDOWN                = 0x0207,
MBUTTONUP                  = 0x0208,
MBUTTONDBLCLK              = 0x0209,

MOUSEWHEEL                 = 0x020A,

XBUTTONDOWN                = 0x020B,
XBUTTONUP                  = 0x020C,
XBUTTONDBLCLK              = 0x020D,

MOUSEHWHEEL                = 0x020E,

MOUSELAST                  = 0x020E,

//PARENTNOTIFY               = 0x0210,
//ENTERMENULOOP              = 0x0211,
//EXITMENULOOP               = 0x0212,
//
//NEXTMENU                   = 0x0213,
//SIZING                     = 0x0214,
//CAPTURECHANGED             = 0x0215,
//MOVING                     = 0x0216,
//POWERBROADCAST             = 0x0218,
//DEVICECHANGE               = 0x0219,
//
//MDICREATE                  = 0x0220,
//MDIDESTROY                 = 0x0221,
//MDIACTIVATE                = 0x0222,
//MDIRESTORE                 = 0x0223,
//MDINEXT                    = 0x0224,
//MDIMAXIMIZE                = 0x0225,
//MDITILE                    = 0x0226,
//MDICASCADE                 = 0x0227,
//MDIICONARRANGE             = 0x0228,
//MDIGETACTIVE               = 0x0229,
//
//
//MDISETMENU                 = 0x0230,
//ENTERSIZEMOVE              = 0x0231,
//EXITSIZEMOVE               = 0x0232,
//DROPFILES                  = 0x0233,
//MDIREFRESHMENU             = 0x0234,
//
//POINTERDEVICECHANGE        = 0x238,
//POINTERDEVICEINRANGE       = 0x239,
//POINTERDEVICEOUTOFRANGE    = 0x23A,
//
//TOUCH                      = 0x0240,
//
//NCPOINTERUPDATE            = 0x0241,
//NCPOINTERDOWN              = 0x0242,
//NCPOINTERUP                = 0x0243,
//POINTERUPDATE              = 0x0245,
//POINTERDOWN                = 0x0246,
//POINTERUP                  = 0x0247,
//POINTERENTER               = 0x0249,
//POINTERLEAVE               = 0x024A,
//POINTERACTIVATE            = 0x024B,
//POINTERCAPTURECHANGED      = 0x024C,
//TOUCHHITTESTING            = 0x024D,
//POINTERWHEEL               = 0x024E,
//POINTERHWHEEL              = 0x024F,
//DM_POINTERHITTEST              = 0x0250,
//
//IME_SETCONTEXT             = 0x0281,
//IME_NOTIFY                 = 0x0282,
//IME_CONTROL                = 0x0283,
//IME_COMPOSITIONFULL        = 0x0284,
//IME_SELECT                 = 0x0285,
//IME_CHAR                   = 0x0286,
//
//IME_REQUEST                = 0x0288,
//IME_KEYDOWN                = 0x0290,
//IME_KEYUP                  = 0x0291,

MOUSEENTER                 = 0x02A0,    // send when a mouse enter a area, origin: WM_NCMOUSEHOVER,
MOUSEHOVER                 = 0x02A1,
MOUSEHOLD                  = 0x02A2,    // send when a mouse button held for a period of time, origin: WM_NCMOUSELEAVE,
MOUSELEAVE                 = 0x02A3,

//WTSSESSION_CHANGE          = 0x02B1,
//
//TABLET_FIRST               = 0x02c0,
//TABLET_LAST                = 0x02df,
//
//DPICHANGED                 = 0x02E0,
//
//CUT                        = 0x0300,
//COPY                       = 0x0301,
//PASTE                      = 0x0302,
//CLEAR                      = 0x0303,
//UNDO                       = 0x0304,
//RENDERFORMAT               = 0x0305,
//RENDERALLFORMATS           = 0x0306,
//DESTROYCLIPBOARD           = 0x0307,
//DRAWCLIPBOARD              = 0x0308,
//PAINTCLIPBOARD             = 0x0309,
//VSCROLLCLIPBOARD           = 0x030A,
//SIZECLIPBOARD              = 0x030B,
//ASKCBFORMATNAME            = 0x030C,
//CHANGECBCHAIN              = 0x030D,
//HSCROLLCLIPBOARD           = 0x030E,
//QUERYNEWPALETTE            = 0x030F,
//PALETTEISCHANGING          = 0x0310,
//PALETTECHANGED             = 0x0311,
//HOTKEY                     = 0x0312,
//
//PRINT                      = 0x0317,
//PRINTCLIENT                = 0x0318,
//
//APPCOMMAND                 = 0x0319,
//
//THEMECHANGED               = 0x031A,
//
//CLIPBOARDUPDATE            = 0x031D,
//
//DWMCOMPOSITIONCHANGED          = 0x031E,
//DWMNCRENDERINGCHANGED          = 0x031F,
//DWMCOLORIZATIONCOLORCHANGED    = 0x0320,
//DWMWINDOWMAXIMIZEDCHANGE       = 0x0321,
//DWMSENDICONICTHUMBNAIL         = 0x0323,
//DWMSENDICONICLIVEPREVIEWBITMAP = 0x0326,
//
//GETTITLEBARINFOEX          = 0x033F,
//
//HANDHELDFIRST              = 0x0358,
//HANDHELDLAST               = 0x035F,
//
//AFXFIRST                   = 0x0360,
//AFXLAST                    = 0x037F,
//
//PENWINFIRST                = 0x0380,
//PENWINLAST                 = 0x038F,
//

/*
 * NOTE: All Message Numbers below 0x0500 are RESERVED.
 *
 * Private View Events Start Here:
 */
USER                       = 0x0500,

/*
 * Application Events Start Here:
 */
APP                        = 0x8000,

/*
 * NERvGear Start Here:
 */
// Messages/Events EVT::RESERVED through 0xBFFF are reserved for NERvGear.
// So EVT::USER-0x7FFF and EVT::APP-0x9FFF are available for 3rd-party development.
RESERVED                   = 0xA000,

TASKQUEUE                  = 0xA100,
DATAUPDATE                 = 0xA120

};

typedef long TYPE;

} // EVT

namespace UI {
class View;
class Canvas;
} // UI

struct IUnknown;
struct IRunnable;
// basic events
class MoveEvent;
class SizeEvent;
class FocusEvent;
class EnableEvent;
class PaintEvent;
class QuitEvent;
class ShowEvent;
class ContextMenuEvent;
class KeyEvent;
class CommandEvent;
class TimerEvent;
class ScrollEvent;
class MouseEvent;
// extra events
class TaskQueueEvent;
class DataUpdateEvent;

class Event {
public:

    // basic events
    bool        IsMoveEvent() const { return m_type == EVT::MOVE; }
    bool        IsSizeEvent() const { return m_type == EVT::SIZE; }
    bool       IsFocusEvent() const { return m_type == EVT::SETFOCUS || m_type == EVT::KILLFOCUS; }
    bool      IsEnableEvent() const { return m_type == EVT::ENABLE; }
    bool       IsPaintEvent() const { return m_type == EVT::PAINT; }
    bool        IsQuitEvent() const { return m_type == EVT::QUIT; }
    bool        IsShowEvent() const { return m_type == EVT::SHOW; }
    bool IsContextMenuEvent() const { return m_type == EVT::CONTEXTMENU; }
    bool         IsKeyEvent() const { return m_type >= EVT::KEYFIRST && m_type <= EVT::KEYLAST; }
    bool     IsCommandEvent() const { return m_type == EVT::COMMAND; }
    bool       IsTimerEvent() const { return m_type == EVT::TIMER; }
    bool      IsScrollEvent() const { return m_type == EVT::HSCROLL || m_type == EVT::VSCROLL; }
    bool       IsMouseEvent() const
    {
        return (m_type >= EVT::MOUSEFIRST && m_type <= EVT::MOUSELAST) ||
               (m_type >= EVT::MOUSEENTER && m_type <= EVT::MOUSELEAVE);
    }
    // extra events
    bool  IsTaskQueueEvent() const { return m_type == EVT::TASKQUEUE; }
    bool IsDataUpdateEvent() const { return m_type == EVT::DATAUPDATE; }

    // safe event casting,
    // it's safe to static_cast any events to its real type

    // basic events
    inline        MoveEvent* ToMoveEvent();
    inline        SizeEvent* ToSizeEvent();
    inline       FocusEvent* ToFocusEvent();
    inline       PaintEvent* ToPaintEvent();
    inline      EnableEvent* ToEnableEvent();
    inline        QuitEvent* ToQuitEvent();
    inline        ShowEvent* ToShowEvent();
    inline ContextMenuEvent* ToContextMenuEvent();
    inline         KeyEvent* ToKeyEvent();
    inline     CommandEvent* ToCommandEvent();
    inline       TimerEvent* ToTimerEvent();
    inline      ScrollEvent* ToScrollEvent();
    inline       MouseEvent* ToMouseEvent();
    // extra events
    inline  TaskQueueEvent* ToTaskQueueEvent();
    inline DataUpdateEvent* ToDataUpdateEvent();

    template <class E>
    bool Verify()              const { return m_signature == sizeof(E); }
    bool Verify(unsigned sign) const { return m_signature == sign; }

    EVT::TYPE GetType() const { return m_type; }
    unsigned GetSignature() const { return m_signature; }
    IUnknown* GetSource() const { return m_source; }

    void SetType(EVT::TYPE type) { m_type = type; }
    void SetSignature(unsigned sign) { m_signature = sign; }
    Event& SetSource(IUnknown* source) { m_source = source; return *this; }

    virtual Event* __stdcall Clone() const { return NULL; }   // NOTE: Clone is not implemented
    virtual void __stdcall Destroy() const { delete this; }

    Event(EVT::TYPE event = EVT::NONE, IUnknown* source = NULL, unsigned sign = sizeof(Event)) :
        m_type(event), m_signature(sign), /*m_timestamp(::GetTickCount()), m_option(0),*/ m_source(source) {}
    virtual ~Event() {}

protected:

    EVT::TYPE m_type;
    unsigned m_signature;
    unsigned m_timestamp;
    unsigned m_option;  // TODO: propagate direction/level
    IUnknown* m_source;
    void* m_reserved;
};

class MoveEvent : public Event {
public:
    MoveEvent(const UI::PixelPoint& evtPoint, unsigned sign = sizeof(MoveEvent)) :
        Event(EVT::MOVE, NULL, sign), pt(evtPoint) {}

    // target position in parent-client coordinate
    UI::PixelPoint pt;
};

class SizeEvent : public Event {
public:
    SizeEvent(const UI::PixelSize& evtSize, unsigned sign = sizeof(SizeEvent)) :
        Event(EVT::SIZE, NULL, sign), sz(evtSize) {}

    // target size in parent-client coordinate
    UI::PixelSize sz;
};

class FocusEvent : public Event {
public:
    FocusEvent(EVT::TYPE evtType, UI::View* evtView, unsigned sign = sizeof(FocusEvent)) :
        Event(evtType, NULL, sign), view(evtView) {}

    // focus view when EVT::KILLFOCUS, lost focus view when EVT::SETFOCUS
    UI::View* view;
};

class EnableEvent : public Event {
public:
    EnableEvent(bool evtEnabled, unsigned sign = sizeof(EnableEvent)) :
        Event(EVT::ENABLE, NULL, sign), enabled(evtEnabled) {}

    // enabled or disabled
    bool enabled;
};

class PaintEvent : public Event {
public:
    PaintEvent(UI::Canvas* evtCanvas, const UI::PixelRect& evtRect, unsigned char evtAlpha, bool evtErase, unsigned sign = sizeof(PaintEvent)) :
        Event(EVT::PAINT, NULL, sign), canvas(evtCanvas), rect(evtRect), alpha(evtAlpha), hint(evtErase) {}

    UI::Canvas* canvas;
    UI::PixelRect rect;
    unsigned char alpha;
    struct Hint {
        bool ERASE_BG;

        Hint(bool erase = false) : ERASE_BG(erase) {}
    } hint;
};

class QuitEvent : public Event { // global event
public:
    QuitEvent(int evtCode, unsigned sign = sizeof(QuitEvent)) :
        Event(EVT::QUIT, NULL, sign), code(evtCode) {}

    bool code;
};

class ShowEvent : public Event {
public:
    ShowEvent(bool evtShow, unsigned sign = sizeof(ShowEvent)) :
        Event(EVT::SHOW, NULL, sign), shown(evtShow) {}

    bool shown;
};

class ContextMenuEvent : public Event {
public:
    ContextMenuEvent(const UI::PixelPoint& evtPt, UI::View* evtView, unsigned sign = sizeof(ContextMenuEvent)) :
        Event(EVT::CONTEXTMENU, NULL, sign), pt(evtPt), view(evtView) {}

    UI::PixelPoint pt;  // in client coordinate, NOT in view coordinate, WM_CONTEXTMENU's lParam is also changed
    UI::View* view;
};

class KeyEvent : public Event {
public:
    KeyEvent(EVT::TYPE evtType, unsigned evtCode, unsigned evtExtra, unsigned sign = sizeof(KeyEvent)) :
        Event(evtType, NULL, sign), code(evtCode), extra(evtExtra) {}

    // virtual key code or character code for responding events
    unsigned code;
    // extra information
    union KeyExtra {
        KeyExtra() : raw(0x0) {}
        KeyExtra(unsigned lParam) : raw(lParam) {}
        unsigned raw;
        struct {
            unsigned REPEAT_COUNT     : 16;
            unsigned SCAN_CODE        : 8;
            unsigned EXTENDED         : 1;
            unsigned RESERVED         : 4;
            unsigned CONTEXT_CODE     : 1;
            unsigned PREVIOUS_STATE   : 1;
            unsigned TRANSITION_STATE : 1;
        };
    } extra;
};

class CommandEvent : public Event {
public:
    CommandEvent(int evtNotify, int evtID, UI::View* evtView, unsigned sign = sizeof(CommandEvent)) :
        Event(EVT::COMMAND, NULL, sign), notify(evtNotify), id(evtID), view(evtView) {}

    int notify; // notification code
    int id;     // control defined identifier
    UI::View* view;
};

class TimerEvent : public Event {
public:
    TimerEvent(int evtInterval, int evtID, unsigned sign = sizeof(TimerEvent)) :
        Event(EVT::TIMER, NULL, sign), interval(evtInterval), id(evtID) {}

    int interval;
    int id;
};

namespace SCROLL {

enum TYPE {
    LINEUP          = 0,
    LINELEFT        = LINEUP,
    LINEDOWN        = 1,
    LINERIGHT       = LINEDOWN,
    PAGEUP          = 2,
    PAGELEFT        = PAGEUP,
    PAGEDOWN        = 3,
    PAGERIGHT       = PAGEDOWN,
    POSITION        = 4,
    TRACK           = 5,
    TOP             = 6,
    LEFT            = TOP,
    BOTTOM          = 7,
    RIGHT           = BOTTOM,
    ENDSCROLL       = 8
};

} // SCROLL

class ScrollEvent : public Event {
public:
    ScrollEvent(EVT::TYPE evtType, SCROLL::TYPE evtReq, int evtAmount, UI::View* evtScrollbar, unsigned sign = sizeof(ScrollEvent)) :
        Event(evtType, NULL, sign), request(evtReq), amount(evtAmount), scrollbar(evtScrollbar) {}

    SCROLL::TYPE request; // scroll request type
    int amount;           // current scroll states in different request scroll types:
                          // indicating scroll lines when scroll type is LINEXXX,
                          // indicating scroll page when scroll type is PAGEXXX,
                          // indicating scroll position when scroll type is POSITION or TRACK
                          // not used when scroll type is TOP, LEFT, BOTTOM, RIGHT or ENDSCROLL
    UI::View* scrollbar;  // scroll bar view if is sent by a scroll bar
};

class MouseEvent : public Event {
public:
    MouseEvent(EVT::TYPE evtType, const UI::PixelPoint& evtPt, short evtRotate, unsigned short evtKey, unsigned sign = sizeof(MouseEvent)) :
        Event(evtType, NULL, sign), pt(evtPt), rotate(evtRotate), key(evtKey) {}

    // mouse position in client coordinate
    UI::PixelPoint pt;
    // mouse wheel rotation
    short rotate;
    // virtual key modifier
    union ModifyKey {
        ModifyKey() : raw(0x0) {}
        ModifyKey(unsigned short wParam) : raw(wParam) {}
        unsigned short raw;
        struct {    // 1 byte
            bool LBUTTON   : 1;
            bool RBUTTON   : 1;
            bool SHIFT     : 1;
            bool CONTROL   : 1;
            bool MBUTTON   : 1;
            bool XBUTTON_1 : 1; // NOTE: XBUTTON1 & XBUTTON2 symbols
            bool XBUTTON_2 : 1; // conflict with winuser.h definition
            bool RESERVED  : 1;
        };
    } key;
};

// extra events start here

class TaskQueueEvent : public Event {
public:

    TaskQueueEvent(int evtCode, IUnknown* evtData, unsigned sign = sizeof(TaskQueueEvent)) :
        Event(EVT::TASKQUEUE, NULL, sign), state(INVALID), retcode(evtCode), userdata(evtData)
    {
    }

    enum { INVALID = -1, COMPLETED, DISCARDED } state;
    int retcode;    // return code of IRunnable::Run()
    IUnknown* userdata;

};

class DataUpdateEvent : public Event {
public:

    DataUpdateEvent(long evtCode, unsigned evtIndex, const wchar_t* evtParam, unsigned sign = sizeof(DataUpdateEvent)) :
        Event(EVT::DATAUPDATE, NULL, sign), retcode(evtCode), index(evtIndex), param(evtParam)
    {
    }

    long retcode;    // return code of IData::Update()
    unsigned index;  // could be NVG_ANY
    const wchar_t* param;
};

#define NVG_EVENT_CAST_IMPL(_EVENT) inline _EVENT* Event::To##_EVENT() { return Is##_EVENT() ? static_cast<_EVENT*>(this) : NULL; }

// basic events
NVG_EVENT_CAST_IMPL(MoveEvent)
NVG_EVENT_CAST_IMPL(SizeEvent)
NVG_EVENT_CAST_IMPL(FocusEvent)
NVG_EVENT_CAST_IMPL(EnableEvent)
NVG_EVENT_CAST_IMPL(PaintEvent)
NVG_EVENT_CAST_IMPL(QuitEvent)
NVG_EVENT_CAST_IMPL(ShowEvent)
NVG_EVENT_CAST_IMPL(ContextMenuEvent)
NVG_EVENT_CAST_IMPL(KeyEvent)
NVG_EVENT_CAST_IMPL(CommandEvent)
NVG_EVENT_CAST_IMPL(TimerEvent)
NVG_EVENT_CAST_IMPL(ScrollEvent)
NVG_EVENT_CAST_IMPL(MouseEvent)
// extra events
NVG_EVENT_CAST_IMPL(TaskQueueEvent)
NVG_EVENT_CAST_IMPL(DataUpdateEvent)

}   // NERvGear

#endif // NVG_EVENT_H

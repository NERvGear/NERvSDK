
/***************************************************************
 * Name:      UI.h
 * Purpose:   Defines Nerve Gear UI APIs
 * Author:    GPBeta ()
 * Created:   2015-03-12
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_UI_H
#define NVG_UI_H

#include <NERvGear/def.h>

namespace NERvGear {

struct IUnknown;

namespace UI {

class LogicPoint;
class LogicSize;
class LogicRect;

class PixelPoint;
class PixelSize;
class PixelRect;
class Window;
class View;
class Canvas;
class Animator;
class Font;
struct IWindow;
struct IAnimateListener;

typedef LogicPoint Point;
typedef LogicSize Size;
typedef LogicRect Rect;

namespace ZORDER {

enum STOCK {
    BOTTOMMOST  = 0x80000001,   // INT_MIN is reserved

    WIDGET      = -1000,

    DEFAULT     = 0,            // behave as normal window without fixed z-order

    LAUNCHER    = 1000,
    LAUNCHER_MENU = 1100,

    MESSAGEBOX  = 2000,

    TOPMOST     = 0x7FFFFFFE    // INT_MAX
};

} // ZORDER

NVG_EXPORT(Window*) NERv1CreateWindow(Window* parent, const PixelPoint& pos, const PixelSize& sz, const wchar_t* name, MODULE* module);
NVG_EXPORT(View*) NERv1CreateView(const PixelRect& rc, const wchar_t* name, int id, IUnknown** outer, MODULE* module);
NVG_EXPORT(Canvas*) NERv1CreateCanvas(const PixelSize& sz, MODULE* module);
NVG_EXPORT(Animator*) NERv1CreateAnimator(IAnimateListener* listener, MODULE* module);
NVG_EXPORT(Font*) NERv1CreateFont(const wchar_t* path, long nface, MODULE* module);

} // UI

// latest APIs

// with logical dimension
// static inline UI::Window* NERvCreateWindow(UI::Window* parent, const UI::Point& pos, const UI::Size& sz, const wchar_t* name = NULL)
// {
    // return NERv1CreateWindow(parent, pos.ToPixel(), sz.ToPixel(), name, &NVG_MODULE);
// }

// static inline UI::View* NERvCreateView(const UI::Rect& rc, const wchar_t* name = NULL, int id = NVG_ANY, IUnknown** outer = NULL)
// {
    // return NERv1CreateView(rc.ToPixel(), name, id, outer, &NVG_MODULE);
// }

// with pixel dimension
static inline UI::Window* NERvCreateWindow(UI::Window* parent, const UI::PixelPoint& pos, const UI::PixelSize& sz, const wchar_t* name = NULL)
{
    return UI::NERv1CreateWindow(parent, pos, sz, name, &NVG_MODULE);
}

static inline UI::View* NERvCreateView(const UI::PixelRect& rc, const wchar_t* name = NULL, int id = NVG_ANY, IUnknown** outer = NULL)
{
    return UI::NERv1CreateView(rc, name, id, outer, &NVG_MODULE);
}

static inline UI::Canvas* NERvCreateCanvas(const UI::PixelSize& sz)
{
    return UI::NERv1CreateCanvas(sz, &NVG_MODULE);
}

static inline UI::Animator* NERvCreateAnimator(UI::IAnimateListener* listener = NULL)
{
    return UI::NERv1CreateAnimator(listener, &NVG_MODULE);
}

static inline UI::Font* NERvCreateFont(const wchar_t* path, long nface = 0)
{
    return UI::NERv1CreateFont(path, nface, &NVG_MODULE);
}

} // NERvGear

#endif // NVG_UI_H


/***************************************************************
 * Name:      sound.h
 * Purpose:   Defines Nerve Gear Sound APIs
 * Author:    GPBeta ()
 * Created:   2015-03-01
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_SOUND_H
#define NVG_SOUND_H

#include <NERvGear/def.h>

namespace NERvGear {

namespace SOUND {

enum TYPE {
    NONE                        = 0,

    SFX_FEEDBACK                = 0x0100,
        FEEDBACK_CLICK          = 0x0120,
        FEEDBACK_CLICK_BUTTON   = FEEDBACK_CLICK,

    SFX_POPUP                   = 0x0200,
        POPUP_LAUNCHER,
        POPUP_MENU,
        POPUP_PANEL,
        POPUP_MESSAGE           = 0x0240,
        POPUP_WELCOME,
        POPUP_WARN,
        POPUP_ALERT,

    SFX_DISMISS                 = 0x0300,
        DISMISS_LAUNCHER,
        DISMISS_MENU,
        DISMISS_PANEL,
        DISMISS_MESSAGE         = 0x0340,

    SFX_NOTIFY                  = 0x0500,
        NOTIFY_MESSAGE,
        NOTIFY_SYSTEM           = 0x0540,

    SFX_ETC                     = 0x1000,
        ETC_LINK_START,
        ETC_APP_STARTUP

};

}

NVG_EXPORT(long) NERv1Sound(const wchar_t* path, SOUND::TYPE sound);

// latest APIs
static inline long NERvSound(const wchar_t* path, SOUND::TYPE sound) { return NERv1Sound(path, sound); }

}

#endif // NVG_SOUND_H

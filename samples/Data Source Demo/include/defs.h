
#ifndef DEFS_H
#define DEFS_H

#include <NERvGear/version.h>

#define _TRANSLATE(_STR) _STR    // help poEdit to find translate string

#define NAME_STRING    _TRANSLATE("Data Source Demo")
#define DESCRIP_STRING _TRANSLATE("Demo Data Source Plug-in for SAO Utils")
#define COMMENT_STRING _TRANSLATE("The SAO Utils Project by Joshua")

#define VER_MAJOR    1
#define VER_MINOR    0
#define VER_SUBMINOR 0
#define VER_RESERVED 0

#define VER_REV                 VER_MAJOR, VER_MINOR, VER_SUBMINOR, VER_RESERVED
#define VER_STR NVG_DOT_VERSION(VER_MAJOR, VER_MINOR, VER_SUBMINOR, VER_RESERVED)
#define VER_NAME VER_STR " " NVG_PLATFORM_SUFFIX


#endif // DEFS_H

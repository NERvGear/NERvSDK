
/***************************************************************
 * Name:      NERvSDK.h
 * Purpose:   Nerve Gear SDK Standard Header
 * Author:    GPBeta ()
 * Created:   2014-10-22
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

 
/// \defgroup mod_function Functions and Macros
/// Reference for all C function and macro APIs provided by the NERvSDK.
///
/// \section mod_fun_macro Macro And Flags
/// <DL>
/// <DT>NVG_FLAG_INIT_UID</DT>
/// <DD>
/// This macro is used to statically initialize UIDs.
/// \code{.cpp} #define NVG_FLAG_INIT_UID \endcode
/// Define <TT>NVG_FLAG_INIT_UID</TT> macro at the beginning of a source file
/// to initialize all the UIDs declared with `NVG_DEFINE_UID()` macro.\n
/// When you want to create an object from another plug-in or use an interface/component not provided by NERvGear,
/// you have to define this macro flag in the source file to initialize the object, interface and component UIDs,
/// otherwise, your linker might not find these UID symbols.
/// </DD>
/// </DL>


/// \defgroup mod_component Components
/// Reference for all components defined by the NERvGear and NERvHub.
/// @{

/// \defgroup mod_com_nvg NERvGear Components
/// Components defined by NERvGear.

/// \defgroup mod_com_system System Components
/// System related components.

/// \defgroup mod_com_security Security Components
/// Security related components.

/// \defgroup mod_com_network Network Components
/// Network related components.

/// \defgroup mod_com_desktop Desktop Components
/// Desktop related components.

/// \defgroup mod_com_graphic Graphics Components
/// Graphics related components.

/// \defgroup mod_com_video Video Components
/// Video related components.

/// \defgroup mod_com_audio Audio Components
/// Audio related components.

/// \defgroup mod_com_etc ETC Components
/// Currently uncatalogued components.

/// @}



/// \defgroup mod_object Objects
/// Reference for all components object implemented by the NERvGear and NERvHub.
/// @{

/// \defgroup mod_obj_nvg NERvGear Objects
/// Objects implemented by NERvGear.

/// \defgroup mod_obj_hub NERvHub Objects
/// Objects implemented by NERvHub.

/// @}



/// \defgroup mod_interface Interfaces
/// Reference for all interfaces defined by the NERvGear and NERvHub.
/// @{

/// \defgroup mod_itf_com Standard COM Interfaces
/// Interfaces defined by Microsoft. You can also find the documents for these interfaces at 
/// <A href="https://msdn.microsoft.com/en-us/library/windows/desktop/ms691212(v=vs.85).aspx">MSDN Library - Interfaces (COM)</A>.

/// \defgroup mod_itf_nvg NERvGear Interfaces
/// Interfaces defined by NERvGear.

/// \defgroup mod_itf_hub NERvHub Interfaces
/// Interfaces defined by NERvHub.

/// @}



/// \defgroup mod_plugin Plug-ins
/// Reference for all plug-ins of the framework.



/// \namespace NERvGear Namespace ::NERvGear.


#ifndef NVG_NERVSDK_H
#define NVG_NERVSDK_H

#include <NERvGear/def.h>
#include <NERvGear/log.h>
#include <NERvGear/event.h>
#include <NERvGear/version.h>

#include <NERvGear/NERv1API.h>

#endif // NVG_NERVSDK_H

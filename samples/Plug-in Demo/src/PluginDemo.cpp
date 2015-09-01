
/***************************************************************
 * Name:      PluginDemo.cpp
 * Purpose:   Code for Plug-in Demo Class
 * Author:    Joshua GPBeta (studiocghibli@gmail.com)
 * Created:   2014-10-26
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

/// ============================================================================
/// declarations
/// ============================================================================

/// ----------------------------------------------------------------------------
/// headers
/// ----------------------------------------------------------------------------

#include "PluginDemo.h"
#include "defs.h"

#include <NERvGear/NERvSDK.h>

using namespace NERvGear;

/// ----------------------------------------------------------------------------
/// variables
/// ----------------------------------------------------------------------------

/// ----------------------------------------------------------------------------
/// plug-in declaration
/// ----------------------------------------------------------------------------

NVG_BEGIN_PLUGIN_INFO(PluginDemo)
    NVG_DECLARE_PLUGIN_UID(0x12345678, 0x1234, 0x1234, 0x12, 0x34, 0x56, 0x78, 0x12, 0x34, 0x56, 0x78)
    NVG_DECLARE_PLUGIN_TYPE(PLUGIN::BASIC)
    NVG_DECLARE_PLUGIN_VERSION(VER_MAJOR, VER_MINOR, VER_SUBMINOR)
    NVG_DECLARE_PLUGIN_NAME(NAME_STRING)
    NVG_DECLARE_PLUGIN_DESCRIP(DESCRIP_STRING)
    NVG_DECLARE_PLUGIN_COMMENT(COMMENT_STRING)
    NVG_DECLARE_PLUGIN_AUTHOR("Joshua GPBeta")
    NVG_DECLARE_PLUGIN_HOMEPAGE("www.gpbeta.com")
    NVG_DECLARE_PLUGIN_EMAIL("studiocghibli@gmail.com")
NVG_END_PLUGIN_INFO(PluginDemo)

/// ----------------------------------------------------------------------------
/// component registration
/// ----------------------------------------------------------------------------

NVG_NO_COMPONENT_REGISTER(PluginDemo)

/// ============================================================================
/// implementation
/// ============================================================================

/// ----------------------------------------------------------------------------
/// event handlers
/// ----------------------------------------------------------------------------

long PluginDemo::OnInitial()
{
    NERvLogInfo(NVG_TEXT(NAME_STRING), L"PluginDemo::OnInitial()");

	return PluginImpl::OnInitial();
}

long PluginDemo::OnRelease()
{
    NERvLogInfo(NVG_TEXT(NAME_STRING), L"PluginDemo::OnRelease()");

    return PluginImpl::OnRelease();
}

long PluginDemo::OnReady()
{
    NERvLogInfo(NVG_TEXT(NAME_STRING), L"PluginDemo::OnReady()");
    return PluginImpl::OnReady();
}

NVG_IMPLEMENT_PLUGIN(PluginDemo)

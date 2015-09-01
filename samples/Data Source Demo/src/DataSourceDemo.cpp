
/***************************************************************
 * Name:      DataSourceDemo.cpp
 * Purpose:   Code for Data Source Demo Class
 * Author:    Joshua GPBeta (studiocghibli@gmail.com)
 * Created:   2015-05-13
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

/// ============================================================================
/// declarations
/// ============================================================================

/// ----------------------------------------------------------------------------
/// headers
/// ----------------------------------------------------------------------------

#include "DataSourceDemo.h"
#include "DemoDataSource.h"
#include "defs.h"

#include <NERvGear/NERvSDK.h>

using namespace NERvGear;

/// ----------------------------------------------------------------------------
/// variables
/// ----------------------------------------------------------------------------

/// ----------------------------------------------------------------------------
/// plug-in declaration
/// ----------------------------------------------------------------------------

NVG_BEGIN_PLUGIN_INFO(DataSourceDemo)
NVG_DECLARE_PLUGIN_UID(0x7b228678, 0xcb8f, 0x40c2, 0xb0, 0xc2, 0x55, 0xd5, 0x97, 0x26, 0x56, 0xb1) // {7B228678-CB8F-40C2-B0C2-55D5972656B1}
    NVG_DECLARE_PLUGIN_TYPE(PLUGIN::BASIC)
    NVG_DECLARE_PLUGIN_VERSION(VER_MAJOR, VER_MINOR, VER_SUBMINOR)
    NVG_DECLARE_PLUGIN_NAME(NAME_STRING)
    NVG_DECLARE_PLUGIN_DESCRIP(DESCRIP_STRING)
    NVG_DECLARE_PLUGIN_COMMENT(COMMENT_STRING)
    NVG_DECLARE_PLUGIN_AUTHOR("Joshua GPBeta")
    NVG_DECLARE_PLUGIN_HOMEPAGE("www.gpbeta.com")
    NVG_DECLARE_PLUGIN_EMAIL("studiocghibli@gmail.com")
NVG_END_PLUGIN_INFO(DataSourceDemo)

/// ----------------------------------------------------------------------------
/// component registration
/// ----------------------------------------------------------------------------

NVG_BEGIN_COMPONENT_REGISTER(DataSourceDemo)
NVG_REGISTER_OBJECT(DemoDataSource, false) // no aggregation
NVG_END_COMPONENT_REGISTER()

/// ============================================================================
/// implementation
/// ============================================================================

/// ----------------------------------------------------------------------------
/// event handlers
/// ----------------------------------------------------------------------------

long DataSourceDemo::OnInitial()
{
	return PluginImpl::OnInitial();
}

long DataSourceDemo::OnRelease()
{
    return PluginImpl::OnRelease();
}

long DataSourceDemo::OnReady()
{
    return PluginImpl::OnReady();
}

NVG_IMPLEMENT_PLUGIN(DataSourceDemo)

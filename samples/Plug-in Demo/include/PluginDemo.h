
/***************************************************************
 * Name:      PluginDemo.h
 * Purpose:   Defines Plug-in Demo Class
 * Author:    Joshua GPBeta (studiocghibli@gmail.com)
 * Created:   2014-10-26
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef PLUGINDEMO_H
#define PLUGINDEMO_H

#include <NERvGear/plugin.h>

/// ----------------------------------------------------------------------------
/// \class PluginDemo
/// \brief Demo Plug-in
/// ----------------------------------------------------------------------------
class PluginDemo : public NERvGear::PluginImpl {
public:

    /// Handlers
    /// -----------------

    // implementation of IPlugin

    virtual long NVG_METHOD OnInitial();
    virtual long NVG_METHOD OnReady();
    virtual long NVG_METHOD OnRelease();

    NVG_DECLARE_PLUGIN(PluginDemo)
};

#endif // PLUGINDEMO_H

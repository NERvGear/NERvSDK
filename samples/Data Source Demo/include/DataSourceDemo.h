
/***************************************************************
 * Name:      DataSourceDemo.h
 * Purpose:   Defines Data Source Demo Class
 * Author:    Joshua GPBeta (studiocghibli@gmail.com)
 * Created:   2015-05-13
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef DATASOURCEDEMO_H
#define DATASOURCEDEMO_H

#include <NERvGear/plugin.h>

class DataSourceDemo : public NERvGear::PluginImpl {
public:

    /// Handlers
    /// -----------------

    // implementation of IPlugin

    virtual long NVG_METHOD OnInitial();
    virtual long NVG_METHOD OnReady();
    virtual long NVG_METHOD OnRelease();

    NVG_DECLARE_PLUGIN(DataSourceDemo)
};

#endif // DATASOURCEDEMO_H

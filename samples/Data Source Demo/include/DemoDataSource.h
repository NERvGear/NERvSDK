
/***************************************************************
 * Name:      DemoDataSource.h
 * Purpose:   Defines Demo Data Source Classes
 * Author:    Joshua GPBeta (studiocghibli@gmail.com)
 * Created:   2015-05-13
 * Copyright: GPBeta ()
 * License:
 * Change log:
 *  2015-05-20 Add Chinese comments. @RangerCD
 **************************************************************/

#ifndef DEMODATASOURCE_H
#define DEMODATASOURCE_H

#include <NERvGear/interface/IDataSource.h>

#include <NERvGear/object.h>

/// ----------------------------------------------------------------------------
/// \class DemoDataSource
/// ----------------------------------------------------------------------------
class DemoDataSource : public NERvGear::IDataSource {
public:

	// We are providing 2 data in this data source,
	// this enumerator help us to index and count these data.
	enum DATA_LIST {
		DEMO_DATA_1,
		DEMO_DATA_2,

		//用于计数子Data种类
		DATA_COUNT
	};

    /// Overridden Functions
    /// --------------------------------------------------------------
	/// 详情见DemoDataSource.cpp

    virtual long NVG_METHOD GetId(NERvGear::UID* id);

    virtual size_t NVG_METHOD GetName(size_t len, wchar_t* name);
    virtual size_t NVG_METHOD GetDescrip(size_t len, wchar_t* descrip);

    virtual unsigned NVG_METHOD GetDataCount();

    virtual long NVG_METHOD GetData(unsigned index, NERvGear::IData** data);
    virtual long NVG_METHOD FindData(const NERvGear::UID& id, NERvGear::IData** data);

    /// Constructors & Destructor
    /// --------------------------------------------------------------

    DemoDataSource();	// Component object accepts default constructor only.
    virtual ~DemoDataSource();

private:

    /// Variables
    /// -----------------

    NVG_DECLARE_OBJECT(DemoDataSource)
};

#endif // DEMODATASOURCE_H


/***************************************************************
 * Name:      DemoDataSource.cpp
 * Purpose:   Code for Demo Data Source Classes
 * Author:    Joshua GPBeta (studiocghibli@gmail.com)
 * Created:   2015-05-13
 * Copyright: GPBeta ()
 * License:
 * Change log:
 *  2015-05-20 Add Chinese comments. @RangerCD
 **************************************************************/

/// ============================================================================
/// declarations
/// ============================================================================

/// ----------------------------------------------------------------------------
/// headers
/// ----------------------------------------------------------------------------

#include "DemoDataSource.h"
#include "DemoData1.h"
#include "DemoData2.h"
#include "defs.h"

#include <NERvGear/string.h>
#include <NERvGear/new.h>
#include <NERvGear/log.h>
#include <NERvGear/component/CDataSource.h>

using namespace NERvGear;

#ifdef _TRANSLATE
#undef _TRANSLATE
#endif

#define _TRANSLATE(_STR) L##_STR

/// ----------------------------------------------------------------------------
/// variables
/// ----------------------------------------------------------------------------

/// ----------------------------------------------------------------------------
/// object declaration
/// ----------------------------------------------------------------------------

NVG_BEGIN_OBJECT_INFO(DemoDataSource)
    NVG_DECLARE_OBJECT_CLASSID_UID(ID_CDataSource)
	//GUID使用guidgen生成
	NVG_DECLARE_OBJECT_OBJECTID(0xe8295e65, 0xdeaf, 0x416e, 0xb1, 0x1d, 0x0, 0x35, 0x55, 0x29, 0x70, 0x90) // {E8295E65-DEAF-416E-B11D-003555297090}
    NVG_DECLARE_OBJECT_VERSION(1, 0, 0)
	//Data Source名称，注册名称，非显示在Data Picker中的名称
    NVG_DECLARE_OBJECT_NAME("Data Source")
	//Data Source描述，同上，非显示在Data Picker中的描述
    NVG_DECLARE_OBJECT_DESCRIP("Demo Data Source Component")
NVG_END_OBJECT_INFO()

/// ----------------------------------------------------------------------------
/// interface information
/// ----------------------------------------------------------------------------

NVG_BEGIN_INTERFACE_INFO(DemoDataSource)
    NVG_DECLARE_INTERFACE(ID_IUnknown, IUnknown, this)
    NVG_DECLARE_INTERFACE(ID_IDataSource, IDataSource, this)
NVG_END_INTERFACE_INFO()

/// ============================================================================
/// implementation
/// ============================================================================

//不需修改
long DemoDataSource::GetId(NERvGear::UID* id)
{
    if (id == NULL)
        return E_INVALIDARG;

    *id = STATIC_OBJECT_INFO.objectID;

    return S_OK;
}

//Data Source名称，显示在Data Picker树的第一层
size_t DemoDataSource::GetName(size_t len, wchar_t* name)
{
	return NERvTranslation(_TRANSLATE("Demo Data Collection"), len, name);
}

//Data Source描述，显示在Data Picker的右下方文本框
size_t DemoDataSource::GetDescrip(size_t len, wchar_t* descrip)
{
	return NERvTranslation(_TRANSLATE("Data Source Component Sample"), len, descrip);
}

//不需修改
unsigned DemoDataSource::GetDataCount()
{
    return DATA_COUNT;
}

//获取Data对象
//index	选中Data的序号
//data	向该参数写入Data对象
//返回执行结果
long DemoDataSource::GetData(unsigned index, NERvGear::IData** data)
{
    if (index >= DATA_COUNT || data == NULL)
        return E_INVALIDARG;

	switch (index) {
	case DEMO_DATA_1: *data = nvg_new DemoData1(this); break;
	case DEMO_DATA_2: *data = nvg_new DemoData2(this); break;
	default: return E_FAIL;
	}

    return S_OK;
}

//通过ID获取Data对象
//id	传入的ID
//data	向该参数写入Data对象
//返回执行结果
long DemoDataSource::FindData(const NERvGear::UID& id, NERvGear::IData** data)
{
    if (data == NULL)
        return E_INVALIDARG;

    if (id == DemoData1::ID) {
		*data = nvg_new DemoData1(this);
	} else if (id == DemoData2::ID) {
		*data = nvg_new DemoData2(this);
	} else { return E_FAIL; }

    return S_OK;
}

/// ----------------------------------------------------------------------------
/// constructor & destructor
/// ----------------------------------------------------------------------------

DemoDataSource::DemoDataSource()
{
#ifdef _DEBUG
	NERvLogInfo(NAME_STRING, L"DemoDataSource::DemoDataSource()");
#endif
}

DemoDataSource::~DemoDataSource()
{
#ifdef _DEBUG
	NERvLogInfo(NAME_STRING, L"DemoDataSource::~DemoDataSource()");
#endif
}

/// ----------------------------------------------------------------------------
/// utilities functions
/// ----------------------------------------------------------------------------

/// ----------------------------------------------------------------------------
/// event handlers
/// ----------------------------------------------------------------------------



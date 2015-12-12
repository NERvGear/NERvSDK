
/***************************************************************
 * Name:      DemoData1.cpp
 * Purpose:   Code for Demo Data 1 Class
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

#include "DemoData1.h"
#include "DemoDataSource.h"
#include "defs.h"

#include <NERvGear/string.h>

#ifdef _TRANSLATE
#undef _TRANSLATE
#endif

#define _TRANSLATE(_STR) L##_STR

using namespace NERvGear;
using namespace std;

/// ----------------------------------------------------------------------------
/// variables
/// ----------------------------------------------------------------------------

//GUID使用guidgen生成
const UID DemoData1::ID = { 0xa2be7a22, 0x3829, 0x4c2b, { 0x9e, 0xbe, 0x50, 0x3, 0xc8, 0x55, 0x6e, 0x30 } }; // {A2BE7A22-3829-4C2B-9EBE-5003C8556E30}

//计量单位
static const wstring UNIT_NAME[] = { L"B", L"KB", L"MB", L"GB" };

//计量单位以'\0'分割，不可以'\0'作为首字符
//注意：若某单位以数字开头，如"1KB",此处的字符'1'可能与前一位分隔符'\0'组合成八进制转义字符，将'\0'写为'\000'可避免
//		例：×	"1B\01KB\0"		→	'1'+'B'+'\01'+'K'+'B'+'\0'
//			√	"1B\0001KB\0"	→	'1'+'B'+'\000'+'1'+'K'+'B'+'\0'
static const wchar_t  UNIT_ENUM[] = L"B\0KB\0MB\0GB\0";

/// ============================================================================
/// implementation
/// ============================================================================

//不需修改
long DemoData1::GetId(UID* id)
{
    if (id == NULL)
        return E_INVALIDARG;

    *id = ID;

    return S_OK;
}

//Data名称，显示在Data Picker树的第二层
size_t DemoData1::GetName(size_t len, wchar_t* name)
{
    return NERvTranslation(_TRANSLATE("Demo Data 1"), len, name);
}

//Data描述，显示在Data Picker的右下方文本框
size_t DemoData1::GetDescrip(size_t len, wchar_t* descrip)
{
    return NERvTranslation(_TRANSLATE("Data Implement 1"), len, descrip);
}

//获取该Data的父Data Source
//返回执行结果，一般不需修改
long DemoData1::QuerySource(IDataSource** source)
{
    if (source == NULL)
        return E_INVALIDARG;

    *source = m_source;
    (*source)->AddRef();

    return S_OK;
}

//获取该Data的子Value个数
//返回无符号整形，一般不需修改
unsigned DemoData1::GetValueCount()
{
    return VALUE_COUNT;
}

//获取Value
//index	选中Value的序号
//nbyte	数据类型为DATA::STRING时，传入buf长度
//buf	传入缓冲区，对该内存赋值，注意赋值类型
//返回缓冲区长度
size_t DemoData1::GetValue(unsigned index, size_t nbyte, void* buf)
{
    switch (index) {
	case STR_DEMO_VALUE_1: return NERvCopyString(m_cur1.c_str(), nbyte / 2, static_cast<wchar_t*>(buf)) * 2;
	case U32_DEMO_VALUE_2:
		if (buf)
			*reinterpret_cast<unsigned*>(buf) = m_cur2;

		return sizeof(unsigned);
    default: break;
    }

    return 0;
}

//获取Value最大值
//index	选中Value的序号
//nbyte	数据类型为DATA::STRING时，传入buf长度
//buf	传入缓冲区，对该内存赋值，注意赋值类型
//返回缓冲区长度
size_t DemoData1::GetMaximum(unsigned index, size_t nbyte, void* buf)
{
	switch (index) {
	case STR_DEMO_VALUE_1: break;	// value 1 has no maximum value
	case U32_DEMO_VALUE_2:
		if (buf) 
			*reinterpret_cast<unsigned*>(buf) = m_max2;

		return sizeof(unsigned);
	default: break;
	}

    return 0;
}

//获取Value最小值
//index	选中Value的序号
//nbyte	数据类型为DATA::STRING时，传入buf长度
//buf	传入缓冲区，对该内存赋值，注意赋值类型
//返回缓冲区长度
size_t DemoData1::GetMinimum(unsigned index, size_t nbyte, void* buf)
{
	switch (index) {
	case STR_DEMO_VALUE_1: break;	// value 1 has no minimum value
	case U32_DEMO_VALUE_2:
		if (buf)
			*reinterpret_cast<unsigned*>(buf) = 0;

		return sizeof(unsigned);
	default: break;
	}

    return 0;
}

unsigned DemoData1::GetValueIndex(int id)
{
	if (id > NVG_ANY && id < VALUE_COUNT)
		return id;

	return NVG_ANY;
}

int DemoData1::GetValueId(unsigned index)
{
	if (index < VALUE_COUNT)
		return index;

	return NVG_ANY;
}

//获取Value类型
//index	选中Value的序号
//返回对应Value数据类型
DATA::TYPE DemoData1::GetValueType(unsigned index)
{
    switch (index) {
	case STR_DEMO_VALUE_1: return DATA::STRING;
	case U32_DEMO_VALUE_2: return DATA::UNSIGNED;
    default: break;
    }

    return DATA::INVALID;
}

//获取Value计量单位
//index	选中Value的序号
//len	传入unit缓冲长度
//unit	传入字符串缓冲区，对该区域写入计量单位字符串
//返回缓冲区长度
size_t DemoData1::GetValueUnit(unsigned index, size_t len, wchar_t* unit)
{
	switch (index) {
	case STR_DEMO_VALUE_1: break;	// value 1 has no unit
	case U32_DEMO_VALUE_2: return NERvCopyString(UNIT_NAME[m_unit2].c_str(), len, unit);	// do not translate units
	default: break;
	}
	

    return 0;
}

//获取Value名称
//index	选中Value的序号
//len	传入name缓冲长度
//name	传入字符串缓冲区，对该区域写入Value名称字符串
//返回缓冲区长度
size_t DemoData1::GetValueName(unsigned index, size_t len, wchar_t* name)
{
    switch (index) {
	case STR_DEMO_VALUE_1: return NERvTranslation(_TRANSLATE("Demo Value 1"), len, name);
	case U32_DEMO_VALUE_2: return NERvTranslation(_TRANSLATE("Demo Value 2"), len, name);
    default: break;
    }

    return 0;
}

//获取Value描述
//index	选中Value的序号
//len	传入descrip缓冲长度
//descrip	传入字符串缓冲区，对该区域写入Value描述字符串
//返回缓冲区长度
size_t DemoData1::GetValueDescrip(unsigned index, size_t len, wchar_t* descrip)
{
    switch (index) {
	case STR_DEMO_VALUE_1: return NERvTranslation(_TRANSLATE("This is a value sample, the update parameter takes a custom text to return a string.\nExample: Welcome to Sword Art Online!"), len, descrip);
	case U32_DEMO_VALUE_2: // value 2 has no description
    default: break;
    }

    return 0;
}

//获取Value更新间隔
//index	选中Value的序号
//返回更新间隔，无符号整形
unsigned DemoData1::GetUpdateInterval(unsigned index)
{
    switch (index) {
	case STR_DEMO_VALUE_1: return 0;    // auto update (this example does not implement yet)
	case U32_DEMO_VALUE_2: return 1000;	// 1 sencod
    default: break;
    }

    return NVG_ANY;
}

//更新,仅作数据采集不传出
//数据传出在GetValue
//index	选中Value的序号
//param	传入Update Parameter
//返回执行结果
long DemoData1::Update(unsigned index, const wchar_t* param)
{
    if (index >= VALUE_COUNT)
        return E_INVALIDARG;

	static const unsigned CUR_VALUE_B = unsigned(1) * 1024 * 1024 * 1024; // 1 GB
	static const unsigned MAX_VALUE_B = unsigned(3) * 1024 * 1024 * 1024; // 3 GB

    const bool SINGLE = (index != unsigned(NVG_ANY));

    switch (index) {
    case NVG_ANY:   // update all
    case STR_DEMO_VALUE_1:
		m_cur1 = param;
		if (m_cur1.empty())
			m_cur1 = L"Please input update paramerter.";
        if (SINGLE) break;
	case U32_DEMO_VALUE_2:
		m_cur2 = CUR_VALUE_B;
		m_max2 = MAX_VALUE_B;

		switch (m_unit2) {
		case UNIT_GB: m_cur2 /= 1024; m_max2 /= 1024;
		case UNIT_MB: m_cur2 /= 1024; m_max2 /= 1024;
		case UNIT_KB: m_cur2 /= 1024; m_max2 /= 1024;
		case UNIT_B:
		default: break;
		}

		if (SINGLE) break;
	default: break;
    }

    return S_OK;
}

//预留
long DemoData1::Invoke(unsigned index, const wchar_t* param, UI::IWindow* window)
{
    return S_FALSE;
}

//配置，用于修改界面上Parameter
//初始化、单击Config按钮均会触发
//index	选中Value的序号
//type	指定当前配置Parameter类型[Update/Invoke等]
//window	指定窗体，预留
//len	传入param缓冲长度
//param	传入字符串缓冲区，若为非NULL值可修改对应Parameter
//返回缓冲区长度，若为0则禁用Config按钮
size_t DemoData1::Config(unsigned index, DATA::CONFIG type, UI::IWindow* window, size_t len, wchar_t* param)
{
	return 0;
}

//设置Value计量单位
//选择计量单位时触发
//index	选中Value的序号
//unit	传入指定计量单位字符串
//返回执行结果
long DemoData1::SetValueUnit(unsigned index, const wchar_t* unit)
{
	if (index >= VALUE_COUNT)
		return E_INVALIDARG;

	switch (index) {
	case STR_DEMO_VALUE_1: break; // value 1 has no unit
	case U32_DEMO_VALUE_2:
	{
		const wstring str(unit);

		for (unsigned i = 0; i < UNIT_COUNT; ++i) {
			if (str == UNIT_NAME[i]) {
				m_unit2 = static_cast<UNIT_TYPE>(i);
				return S_OK;
			}
		}
	}
	default: break;
	}

    return E_FAIL;
}

//枚举Value计量单位
//index	选中Value的序号
//len	传入unit缓冲长度
//units	传入字符串缓冲区，对该区域写入计量单位字符串
//返回缓冲区长度
size_t DemoData1::EnumValueUnit(unsigned index, size_t len, wchar_t* units)
{
	switch (index) {
	case STR_DEMO_VALUE_1: break; // value 1 has no unit
	case U32_DEMO_VALUE_2: return NERvCopyStringDoubleNull(UNIT_ENUM, len, units);
	default: break;
	}

	return 0;
}

//??
long DemoData1::SetEventListener(IEventHandler* listener)
{
    return E_NOTIMPL;
}


/// ----------------------------------------------------------------------------
/// constructor & destructor
/// ----------------------------------------------------------------------------

DemoData1::DemoData1(DemoDataSource* source) : m_source(source), m_unit2(UNIT_B)
{
	if (m_source)
		m_source->AddRef();
}

DemoData1::~DemoData1()
{
	if (m_source) {	// optional: use NERvRelease() instead
		m_source->Release();
		m_source = NULL;
	}
}

/// ----------------------------------------------------------------------------
/// utilities functions
/// ----------------------------------------------------------------------------

/// ----------------------------------------------------------------------------
/// event handlers
/// ----------------------------------------------------------------------------


/***************************************************************
 * Name:      DemoData2.cpp
 * Purpose:   Code for Demo Data 2 Class
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

#include "DemoData2.h"
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

const UID DemoData2::ID = { 0x66a4ec2a, 0x535f, 0x4297, { 0xa2, 0xdb, 0x5d, 0xfd, 0x47, 0x3d, 0xea, 0x52 } }; // {66A4EC2A-535F-4297-A2DB-5DFD473DEA52}

static const wstring UNIT_NAME[] = { L"B", L"KB", L"MB", L"GB" };
static const wchar_t  UNIT_ENUM[] = L"B\0KB\0MB\0GB\0";

/// ============================================================================
/// implementation
/// ============================================================================

long DemoData2::GetId(UID* id)
{
    if (id == NULL)
        return E_INVALIDARG;

    *id = ID;

    return S_OK;
}

size_t DemoData2::GetName(size_t len, wchar_t* name)
{
    return NERvTranslation(_TRANSLATE("Demo Data 1"), len, name);
}

size_t DemoData2::GetDescrip(size_t len, wchar_t* descrip)
{
    return NERvTranslation(_TRANSLATE("Data Implement 1"), len, descrip);
}

long DemoData2::QuerySource(IDataSource** source)
{
    if (source == NULL)
        return E_INVALIDARG;

    *source = m_source;
    (*source)->AddRef();

    return S_OK;
}

unsigned DemoData2::GetValueCount()
{
    return VALUE_COUNT;
}

size_t DemoData2::GetValue(unsigned index, size_t nbyte, void* buf)
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

size_t DemoData2::GetMaximum(unsigned index, size_t nbyte, void* buf)
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

size_t DemoData2::GetMinimum(unsigned index, size_t nbyte, void* buf)
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

unsigned DemoData2::GetValueIndex(int id)
{
	if (id > NVG_ANY && id < VALUE_COUNT)
		return id;

	return NVG_ANY;
}

int DemoData2::GetValueId(unsigned index)
{
	if (index < VALUE_COUNT)
		return index;

	return NVG_ANY;
}

DATA::TYPE DemoData2::GetValueType(unsigned index)
{
    switch (index) {
	case STR_DEMO_VALUE_1: return DATA::STRING;
	case U32_DEMO_VALUE_2: return DATA::UNSIGNED;
    default: break;
    }

    return DATA::INVALID;
}

size_t DemoData2::GetValueUnit(unsigned index, size_t len, wchar_t* unit)
{
	switch (index) {
	case STR_DEMO_VALUE_1: break;	// value 1 has no unit
	case U32_DEMO_VALUE_2: return NERvCopyString(UNIT_NAME[m_unit2].c_str(), len, unit);	// do not translate units
	default: break;
	}
	

    return 0;
}

size_t DemoData2::GetValueName(unsigned index, size_t len, wchar_t* name)
{
    switch (index) {
	case STR_DEMO_VALUE_1: return NERvTranslation(_TRANSLATE("Demo Value 1"), len, name);
	case U32_DEMO_VALUE_2: return NERvTranslation(_TRANSLATE("Demo Value 2"), len, name);
    default: break;
    }

    return 0;
}

size_t DemoData2::GetValueDescrip(unsigned index, size_t len, wchar_t* descrip)
{
    switch (index) {
	case STR_DEMO_VALUE_1: return NERvTranslation(_TRANSLATE("This is a value sample, the update parameter takes a custom text to return a string.\nExample: Welcome to Sword Art Online!"), len, descrip);
	case U32_DEMO_VALUE_2: // value 2 has no description
    default: break;
    }

    return 0;
}

unsigned DemoData2::GetUpdateInterval(unsigned index)
{
    switch (index) {
	case STR_DEMO_VALUE_1: return 0;    // auto update (this example does not implement yet)
	case U32_DEMO_VALUE_2: return 1000;	// 1 sencod
    default: break;
    }

    return NVG_ANY;
}

long DemoData2::Update(unsigned index, const wchar_t* param)
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

long DemoData2::Invoke(unsigned index, const wchar_t* param, UI::IWindow* window)
{
    return S_FALSE;
}

size_t DemoData2::Config(unsigned index, DATA::CONFIG type, UI::IWindow* window, size_t len, wchar_t* param)
{
	return 0;
}

long DemoData2::SetValueUnit(unsigned index, const wchar_t* unit)
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

size_t DemoData2::EnumValueUnit(unsigned index, size_t len, wchar_t* units)
{
	switch (index) {
	case STR_DEMO_VALUE_1: break; // value 1 has no unit
	case U32_DEMO_VALUE_2: return NERvCopyStringDoubleNull(UNIT_ENUM, len, units);
	default: break;
	}

	return 0;
}

long DemoData2::SetEventListener(IEventHandler* listener)
{
    return E_NOTIMPL;
}


/// ----------------------------------------------------------------------------
/// constructor & destructor
/// ----------------------------------------------------------------------------

DemoData2::DemoData2(DemoDataSource* source) : m_source(source), m_unit2(UNIT_B)
{
	if (m_source)
		m_source->AddRef();
}

DemoData2::~DemoData2()
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

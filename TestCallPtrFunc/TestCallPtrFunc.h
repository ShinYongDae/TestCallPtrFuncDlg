
// TestCallPtrFunc.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTestCallPtrFuncApp:
// �� Ŭ������ ������ ���ؼ��� TestCallPtrFunc.cpp�� �����Ͻʽÿ�.
//

class CTestCallPtrFuncApp : public CWinApp
{
public:
	CTestCallPtrFuncApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CTestCallPtrFuncApp theApp;
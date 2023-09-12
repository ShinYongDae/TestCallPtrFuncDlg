
// TestCallPtrFuncDlg.h : ��� ����
//

#pragma once

//#include <vector>
#include <queue>

// CTestCallPtrFuncDlg ��ȭ ����
class CTestCallPtrFuncDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CTestCallPtrFuncDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTCALLPTRFUNC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

	//typedef void(CTestCallPtrFuncDlg::*PtrFunc)();
	//typedef CArray<CTestCallPtrFuncDlg::PtrFunc, CTestCallPtrFuncDlg::PtrFunc> CArFunc;
	//CArFunc m_arFunc;
	//void CallArFunc();

	//typedef void(CTestCallPtrFuncDlg::*PtrFunc)();
	//std::vector<void(CTestCallPtrFuncDlg::*)()> m_vecFunc;
	//void CallArFunc();

	typedef void(CTestCallPtrFuncDlg::*PtrFunc)();
	std::queue<void(CTestCallPtrFuncDlg::*)()> m_queFunc;
	void CallArFunc();

	void Func1();
	void Func2();
	void Func3();

// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};

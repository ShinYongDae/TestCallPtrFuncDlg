
// TestCallPtrFuncDlg.h : 헤더 파일
//

#pragma once

//#include <vector>
#include <queue>

// CTestCallPtrFuncDlg 대화 상자
class CTestCallPtrFuncDlg : public CDialogEx
{
// 생성입니다.
public:
	CTestCallPtrFuncDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTCALLPTRFUNC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

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

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};

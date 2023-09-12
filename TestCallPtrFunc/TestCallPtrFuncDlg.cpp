
// TestCallPtrFuncDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "TestCallPtrFunc.h"
#include "TestCallPtrFuncDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestCallPtrFuncDlg 대화 상자



CTestCallPtrFuncDlg::CTestCallPtrFuncDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTCALLPTRFUNC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestCallPtrFuncDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestCallPtrFuncDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CTestCallPtrFuncDlg 메시지 처리기

BOOL CTestCallPtrFuncDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	void (CTestCallPtrFuncDlg::*fp)();

	fp = &CTestCallPtrFuncDlg::Func1;
	//m_arFunc.Add(fp);
	m_vecFunc.push_back(fp);

	fp = &CTestCallPtrFuncDlg::Func2;
	//m_arFunc.Add(fp);
	m_vecFunc.push_back(fp);

	fp = &CTestCallPtrFuncDlg::Func3;
	//m_arFunc.Add(fp);
	m_vecFunc.push_back(fp);

	CallArFunc();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTestCallPtrFuncDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTestCallPtrFuncDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTestCallPtrFuncDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestCallPtrFuncDlg::CallArFunc()
{
	//int nCount = m_arFunc.GetSize();
	//while (nCount > 0)
	//{
	//	void (CTestCallPtrFuncDlg::*fp)();
	//	fp = m_arFunc.GetAt(0);
	//	m_arFunc.RemoveAt(0);
	//	(((CTestCallPtrFuncDlg*)this)->*fp)(); //함수 포인터로 함수 호출
	//	nCount = m_arFunc.GetSize();
	//}

	void (CTestCallPtrFuncDlg::*ptr)();
	for (std::vector<void(CTestCallPtrFuncDlg::*)()>::iterator it = m_vecFunc.begin(); it < m_vecFunc.end(); it++)
	{
		ptr = (*it);
		(((CTestCallPtrFuncDlg*)this)->*ptr)(); //함수 포인터로 함수 호출
	}

	// vector를 iterator로 반복한다.
	//for (auto ptr = m_vecFunc.begin(); ptr < m_vecFunc.end(); ptr++)
	//{
	//	(*ptr)();
	//}
}

void CTestCallPtrFuncDlg::Func1()
{
	AfxMessageBox(_T("Func1"));
}

void CTestCallPtrFuncDlg::Func2()
{
	AfxMessageBox(_T("Func2"));
}

void CTestCallPtrFuncDlg::Func3()
{
	AfxMessageBox(_T("Func3"));
}

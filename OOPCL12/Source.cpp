#include "afxwin.h"

class CMyMainWnd : public CFrameWnd {
public:
	CMyMainWnd() { // конструктор
		Create(NULL, L"My title");
		//SetTimer(1, 1000, NULL);
		//SetTimer(2, 3000, NULL);
	}

	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT);
	afx_msg void OnVKeyDown(UINT, CWnd*, UINT);
	DECLARE_MESSAGE_MAP()

	//~CMyMainWnd() {
	//	KillTimer(1);
	//	//KillTimer(2);
	//}
};

BEGIN_MESSAGE_MAP(CMyMainWnd, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	//ON_WM_TIMER()
	ON_WM_KEYDOWN()
	//ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


class CMyApp : public CWinApp {
public:
	CMyApp() {}; // конструктор
	virtual BOOL InitInstance() {
		m_pMainWnd = new CMyMainWnd();
		m_pMainWnd->ShowWindow(SW_SHOW);
		return TRUE;
	}
};

CMyApp theApp;

void CMyMainWnd::OnLButtonDown(UINT, CPoint) {
	AfxMessageBox(L"Левая кнопка мыши");
}

void CMyMainWnd::OnPaint() {
	CPaintDC* pDC = new CPaintDC(this);
	pDC->Rectangle(5, 5, 50, 50);
}

void CMyMainWnd::OnTimer(UINT nIDEvent) {
	if (nIDEvent == 1)
		MessageBeep(-1);
	else
		SetWindowText(L"Title");
}


void CMyMainWnd::OnVKeyDown(UINT key, CWnd* , UINT) {
	if (key == 31) {
		CPaintDC* pDC = new CPaintDC(this);
		pDC->Ellipse(5, 5, 50, 50);
	}
	if (key == 32) {
		CPaintDC* pDC = new CPaintDC(this);
		pDC->Ellipse(105, 5, 50, 80);
	}
	if (key == 33) {
		CPaintDC* pDC = new CPaintDC(this);
		pDC->Rectangle(5, 105, 50, 80);

	}	
	if (key == 34) {
		CPaintDC* pDC = new CPaintDC(this);
		pDC->Rectangle(105, 105, 50, 50);

	}
	if (key == 35) {
		CPaintDC* pDC = new CPaintDC(this);
		pDC->Pie(165, 105, 50, 50, 60, 40, 30, 20);
	}
	if (key == 36) {
		CPaintDC* pDC = new CPaintDC(this);
		pDC->Chord(105, 165, 50, 50, 60, 40, 30, 20);
	}
}

#include "afxwin.h"
#include <string> 

COLORREF penColor = RGB(0, 0, 0);

class CMyMainWnd : public CFrameWnd {
public:
	CMyMainWnd() { 
		Create(NULL, L"My title");
	}

	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnRButtonDown(UINT, CPoint);
	afx_msg void OnTimer(UINT);
	
	afx_msg void OnVKeyDown(UINT, CWnd*, UINT);
	
	afx_msg void OnPaintEllipse();
	afx_msg void OnPaintCircle();
	afx_msg void OnPaintRectangle();
	afx_msg void OnPaintSquare();
	afx_msg void OnPaintPie();
	afx_msg void OnPaintChord();
	
	char str[50];
	int nMouseX, nMouseY, nOldMouseX, nOldMouseY;
	char pszMouseStr[50];

	DECLARE_MESSAGE_MAP()

	~CMyMainWnd() {
		//KillTimer(1);
		//KillTimer(2);
	}
};

BEGIN_MESSAGE_MAP(CMyMainWnd, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_PAINT()
	//ON_WM_TIMER()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

class CMyApp : public CWinApp {
public:
	CMyApp() {};
	virtual BOOL InitInstance() {
		m_pMainWnd = new CMyMainWnd();
		m_pMainWnd->ShowWindow(SW_SHOW);
		return TRUE;
	}
};

CMyApp theApp;

void CMyMainWnd::OnLButtonDown(UINT, CPoint) {
	AfxMessageBox(L"Левая кнопка мыши");
	Invalidate();
	UpdateWindow();
}

void CMyMainWnd::OnRButtonDown(UINT, CPoint loc) {
	nOldMouseX = nMouseX;
	nOldMouseY = nMouseY;
	strcpy(pszMouseStr, "Нажата правая кнопка");
	nMouseX = loc.x; nMouseY = loc.y;
	this->InvalidateRect(0);
}

void CMyMainWnd::OnTimer(UINT nIDEvent) {
	if (nIDEvent == 1)
		MessageBeep(-1);
	else
		SetWindowText(L"Title");
}

void  CMyMainWnd::OnPaintEllipse() {
	CPen aPen;
	penColor = RGB(rand() % 256, rand() % 256, rand() % 256);
	aPen.CreatePen(PS_SOLID, 2, penColor);
	CPaintDC* pDC = new CPaintDC(this);
	CPen* oldPen = pDC->SelectObject(&aPen);
	CPaintDC* pDCEllipse = new CPaintDC(this);
	pDCEllipse->Ellipse(105, 5, 50, 80);
	pDC->SelectObject(oldPen);
}

void  CMyMainWnd::OnPaintCircle() {
	CPen aPen;
	penColor = RGB(rand() % 256, rand() % 256, rand() % 256);
	aPen.CreatePen(PS_SOLID, 2, penColor);
	CPaintDC* pDC = new CPaintDC(this);
	CPen* oldPen = pDC->SelectObject(&aPen);
	CPaintDC* pDCCircle = new CPaintDC(this);
	pDCCircle->Ellipse(5, 5, 50, 50);
	pDC->SelectObject(oldPen);
}

void  CMyMainWnd::OnPaintRectangle() {
	CPen aPen;
	penColor = RGB(rand() % 256, rand() % 256, rand() % 256);
	aPen.CreatePen(PS_SOLID, 2, penColor);
	CPaintDC* pDC = new CPaintDC(this);
	CPen* oldPen = pDC->SelectObject(&aPen);
	CPaintDC* pDCRectangele = new CPaintDC(this);
	pDCRectangele->Rectangle(5, 105, 50, 80);
	pDC->SelectObject(oldPen);
}

void  CMyMainWnd::OnPaintSquare() {
	CPen aPen;
	penColor = RGB(rand() % 256, rand() % 256, rand() % 256);
	aPen.CreatePen(PS_SOLID, 2, penColor);
	CPaintDC* pDC = new CPaintDC(this);
	CPen* oldPen = pDC->SelectObject(&aPen);
	CPaintDC* pDCSquare = new CPaintDC(this);
	pDCSquare->Rectangle(105, 105, 50, 50);
	pDC->SelectObject(oldPen);
}

void  CMyMainWnd::OnPaintPie() {
	CPen aPen;
	penColor = RGB(rand() % 256, rand() % 256, rand() % 256);
	aPen.CreatePen(PS_SOLID, 2, penColor);
	CPaintDC* pDC = new CPaintDC(this);
	CPen* oldPen = pDC->SelectObject(&aPen);
	CPaintDC* pDCPie = new CPaintDC(this);
	pDCPie->Pie(165, 105, 50, 50, 60, 40, 30, 20);
	pDC->SelectObject(oldPen);
}

void  CMyMainWnd::OnPaintChord() {
	CPen aPen;
	penColor = RGB(rand() % 256, rand() % 256, rand() % 256);
	aPen.CreatePen(PS_SOLID, 2, penColor);
	CPaintDC* pDC = new CPaintDC(this);
	CPen* oldPen = pDC->SelectObject(&aPen);
	CPaintDC* pDCChord = new CPaintDC(this);
	pDCChord->Chord(105, 165, 50, 50, 60, 40, 30, 20);
	pDC->SelectObject(oldPen);
}

void CMyMainWnd::OnVKeyDown(UINT key, CWnd*, UINT) {
	if (key == '1') {
		OnPaintCircle();
	}
	if (key == '2') {
		OnPaintEllipse();
	}
	if (key == '3') {
		OnPaintRectangle();
	}
	if (key == '4') {
		OnPaintSquare();
	}
	if (key == '5') {
		OnPaintPie();
	}
	if (key == '6') {
		OnPaintChord();
	}
}

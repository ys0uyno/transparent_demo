
// mfc_transparent_buttonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mfc_transparent_button.h"
#include "mfc_transparent_buttonDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define CORNER_SIZE 2

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cmfc_transparent_buttonDlg dialog




Cmfc_transparent_buttonDlg::Cmfc_transparent_buttonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmfc_transparent_buttonDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmfc_transparent_buttonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cmfc_transparent_buttonDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_TEST0, &Cmfc_transparent_buttonDlg::OnBnClickedButtonTest0)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// Cmfc_transparent_buttonDlg message handlers

BOOL Cmfc_transparent_buttonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BACKGROUND);
	m_brush.CreatePatternBrush(&bitmap);
	bitmap.DeleteObject();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cmfc_transparent_buttonDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cmfc_transparent_buttonDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);

		CRect rect;
		GetClientRect(rect);

		// outside of window border
		CPen *old_pen = NULL;
		CPen new_pen1(PS_SOLID, 1, RGB(27, 147, 186));
		old_pen = dc.SelectObject(&new_pen1);

		dc.MoveTo(rect.left, CORNER_SIZE);
		dc.LineTo(CORNER_SIZE, rect.top);
		dc.LineTo(rect.right - CORNER_SIZE - 1, rect.top);
		dc.LineTo(rect.right - 1, CORNER_SIZE);
		dc.LineTo(rect.right - 1, rect.bottom - CORNER_SIZE - 1);
		dc.LineTo(rect.right - CORNER_SIZE - 1, rect.bottom - 1);
		dc.LineTo(CORNER_SIZE, rect.bottom - 1);
		dc.LineTo(rect.left, rect.bottom - CORNER_SIZE - 1);
		dc.LineTo(rect.left, CORNER_SIZE);

		// fill in gaps
		dc.MoveTo(rect.left + 1, CORNER_SIZE);
		dc.LineTo(CORNER_SIZE + 1, rect.top);
		dc.MoveTo(rect.right - CORNER_SIZE - 1, rect.top + 1);
		dc.LineTo(rect.right - 1, CORNER_SIZE + 1);
		dc.MoveTo(rect.right - 2, rect.bottom - CORNER_SIZE - 1);
		dc.LineTo(rect.right - CORNER_SIZE - 1, rect.bottom - 1);
		dc.MoveTo(CORNER_SIZE, rect.bottom - 2);
		dc.LineTo(rect.left, rect.bottom - CORNER_SIZE - 2);

		dc.SelectObject(old_pen);

		// inside of window border
		CPen new_pen2(PS_SOLID, 1, RGB(196, 234, 247));
		old_pen = dc.SelectObject(&new_pen2);

		dc.MoveTo(rect.left + 1, CORNER_SIZE + 1);
		dc.LineTo(CORNER_SIZE + 1, rect.top + 1);
		dc.LineTo(rect.right - CORNER_SIZE - 2, rect.top + 1);
		dc.LineTo(rect.right - 2, CORNER_SIZE + 1);
		dc.LineTo(rect.right - 2, rect.bottom - CORNER_SIZE - 2);
		dc.LineTo(rect.right - CORNER_SIZE - 2, rect.bottom - 2);
		dc.LineTo(CORNER_SIZE + 1, rect.bottom - 2);
		dc.LineTo(rect.left + 1, rect.bottom - CORNER_SIZE - 2);
		dc.LineTo(rect.left + 1, CORNER_SIZE + 1);

		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cmfc_transparent_buttonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HBRUSH Cmfc_transparent_buttonDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	if (pWnd == this)
	{
		return m_brush;
	}

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}

void Cmfc_transparent_buttonDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here

	// remove the four sharp corners of the border
	if (nType != SIZE_MAXIMIZED)
	{
		CRect rc;
		GetClientRect(&rc);

		CRgn rgn;
		CPoint points[8] =
		{
			CPoint(rc.left, CORNER_SIZE),
			CPoint(CORNER_SIZE, rc.top),
			CPoint(rc.right - CORNER_SIZE, rc.top),
			CPoint(rc.right, CORNER_SIZE),
			CPoint(rc.right, rc.bottom - CORNER_SIZE - 1),
			CPoint(rc.right - CORNER_SIZE - 1, rc.bottom),
			CPoint(CORNER_SIZE + 1, rc.bottom),
			CPoint(rc.left, rc.bottom - CORNER_SIZE - 1)
		};

		int nPolyCounts[1] = {8};
		int dd = rgn.CreatePolyPolygonRgn(points, nPolyCounts, 1, WINDING);
		SetWindowRgn(rgn, TRUE);
	}
	else
	{
		SetWindowRgn(NULL, FALSE);
	}
}

void Cmfc_transparent_buttonDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));

	CDialogEx::OnLButtonDown(nFlags, point);
}

void Cmfc_transparent_buttonDlg::OnBnClickedButtonTest0()
{
	// TODO: Add your control notification handler code here
}

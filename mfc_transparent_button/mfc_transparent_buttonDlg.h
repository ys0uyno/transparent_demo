
// mfc_transparent_buttonDlg.h : header file
//

#pragma once
#include "transparent_button.h"


// Cmfc_transparent_buttonDlg dialog
class Cmfc_transparent_buttonDlg : public CDialogEx
{
// Construction
public:
	Cmfc_transparent_buttonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFC_TRANSPARENT_BUTTON_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonTest0();

private:
	CBrush m_brush;
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButtonMinimize();
	afx_msg void OnBnClickedButtonClose();
	transparent_button m_button_minimize;
	transparent_button m_button_close;
	transparent_button m_button_test0;
};


// mfc_transparent_buttonDlg.h : header file
//

#pragma once


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
};

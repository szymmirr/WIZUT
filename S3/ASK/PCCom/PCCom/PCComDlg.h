// CPCComDlg.h : header file
//

#pragma once


// CCPCComDlg dialog
class CCPCComDlg : public CDialog
{
// Construction
public:
	CCPCComDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CPCCOM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HANDLE m_hCom;
	unsigned char m_aBuf[30];
	CString m_strRecText;
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};

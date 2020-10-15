// joystick2Dlg.h : header file
//
#pragma once
#include <mmsystem.h> 



// Cjoystick2Dlg dialog
class Cjoystick2Dlg : public CDialog
{
// Construction
public:
	Cjoystick2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_JOYSTICK2_DIALOG };

	protected:
		JOYINFOEX joystickInfo;
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnTimer();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};

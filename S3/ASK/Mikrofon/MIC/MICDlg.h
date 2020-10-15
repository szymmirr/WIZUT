// MICDlg.h : header file
//

#pragma once

#include "Mmsystem.h"

// CMICDlg dialog
class CMICDlg : public CDialog
{
// Construction
public:
	CMICDlg(CWnd* pParent = NULL);	// standard constructor

public:
	HWAVEOUT	outHandle;

	WAVEHDR		outBuffer;
	unsigned char outBufAudio[88000*2];

// Dialog Data
	enum { IDD = IDD_MIC_DIALOG };

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
	afx_msg void OnBnClickedButmicOutopen();
	afx_msg void OnBnClickedButmicOutclose();
	afx_msg void OnBnClickedButmicOutplay();

	afx_msg LRESULT OnOutDone(WPARAM wParam, LPARAM lParam);
};

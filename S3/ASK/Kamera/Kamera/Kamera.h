// Kamera.h : main header file for the Kamera application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CKameraApp:
// See Kamera.cpp for the implementation of this class
//

class CKameraApp : public CWinApp
{
public:
	CKameraApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CKameraApp theApp;
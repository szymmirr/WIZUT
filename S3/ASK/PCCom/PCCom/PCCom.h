// PCCom.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPCComApp:
// See PCCom.cpp for the implementation of this class
//

class CPCComApp : public CWinApp
{
public:
	CPCComApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPCComApp theApp;
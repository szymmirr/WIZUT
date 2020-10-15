// joystick2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cjoystick2App:
// See joystick2.cpp for the implementation of this class
//

class Cjoystick2App : public CWinApp
{
public:
	Cjoystick2App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cjoystick2App theApp;
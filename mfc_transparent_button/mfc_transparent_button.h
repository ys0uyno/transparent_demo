
// mfc_transparent_button.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cmfc_transparent_buttonApp:
// See mfc_transparent_button.cpp for the implementation of this class
//

class Cmfc_transparent_buttonApp : public CWinApp
{
public:
	Cmfc_transparent_buttonApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cmfc_transparent_buttonApp theApp;
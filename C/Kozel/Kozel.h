// Kozel.h : main header file for the Kozel application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


// CKozelApp:
// See Kozel.cpp for the implementation of this class
//

class CKozelApp : public CWinApp
{
public:
	CKozelApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CKozelApp theApp;
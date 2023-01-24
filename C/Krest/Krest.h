// Krest.h : main header file for the Krest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


// CKrestApp:
// See Krest.cpp for the implementation of this class
//

class CKrestApp : public CWinApp
{
public:
	CKrestApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CKrestApp theApp;
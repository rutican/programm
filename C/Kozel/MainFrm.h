// MainFrm.h : interface of the CMainFrame class
//
#include "KozelDoc.h"

#pragma once
class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
int m_nKolIgr;
// Operations
public:
// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	//CDialogBar m_dlgBar;
	CToolBar    m_wndTOOLBAR2;
// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
public:
		afx_msg void OnUpdateKolIgr(CCmdUI *pCmdUI);
		afx_msg void OnUpdatePobed(CCmdUI *pCmdUI);
		afx_msg void OnUpdatePartii(CCmdUI *pCmdUI);
		afx_msg void OnUpdateStchet(CCmdUI *pCmdUI);
		afx_msg void OnUpdateProigr(CCmdUI *pCmdUI);
};


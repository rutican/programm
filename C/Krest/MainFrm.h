// MainFrm.h : interface of the CMainFrame class
//


#pragma once

#include "ServerSok.h"
#include "KlientSok.h"

//#include "ChildView.h"
class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame();
	CRect rect0,rect1,rect2,rect3,rect4,rect5,rect6,rect7,rect8;
	BOOL Simbol;//1- крестик , 0 - нолик
	int UrovenSlognosti;
	BOOL KtoViigral();
	void OtvetKompa();
	void UpravlenieIgroi();


	bool pobeda;
	bool proigrish;
	bool nichya;

	int pobedi;
	int proigrishi;
	int nichi;

BOOL FlagPobed;

	//int line;//показыв какую линию зачеркнуть

//CServerSok   m_ServSok;
//CKlientSok m_KlientSok;
CServerSok*   pServSok;
CKlientSok* pKlientSok;

protected: 
	DECLARE_DYNAMIC(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
//	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	//CChildView    m_wndView;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	
	
	afx_msg void OnKrestic();
	
	afx_msg void OnNovayaIgra();
	afx_msg void OnUpdateKrestic(CCmdUI *pCmdUI);
	afx_msg void OnNolik();
	afx_msg void OnUpdateNolik(CCmdUI *pCmdUI);
	afx_msg void OnOchenProstoi();
	afx_msg void OnUpdateOchenProstoi(CCmdUI *pCmdUI);
	afx_msg void OnProstoi();
	afx_msg void OnUpdateProstoi(CCmdUI *pCmdUI);
	afx_msg void OnSlognii();
	afx_msg void OnUpdateSlognii(CCmdUI *pCmdUI);
	afx_msg void OnTimer(UINT nIDEvent);

	afx_msg void OnUpdatePobedi(CCmdUI *pCmdUI);
	afx_msg void  OnUpdatePorageniya(CCmdUI *pCmdUI);

	afx_msg LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnHelpHitTest(WPARAM wParam, LPARAM lParam);

	virtual void Serialize(CArchive& ar);
	afx_msg void OnServer();
	afx_msg void OnKlient();
	afx_msg void OnUpdateServer(CCmdUI *pCmdUI);
	afx_msg void OnUpdateKlient(CCmdUI *pCmdUI);
	
	afx_msg void OnVirubitSet();
	afx_msg void OnUpdateVirubitSet(CCmdUI *pCmdUI);
};



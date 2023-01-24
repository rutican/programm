// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Kozel.h"
#include <MMSYSTEM.H>//

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


static UINT BASED_CODE toolbar1[]=
{
	ID_SEPARATOR,
	ID_UDARIT,
	ID_SXODIT,
	ID_SBROSIT,
	ID_COMP_XODIT,
	ID_COMP_SKIDIVAET,
	ID_COMP_BIET,
	ID_RAZDAT,
	ID_UBRAT
};

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	// Global help commands
	ON_COMMAND(ID_HELP_FINDER, CFrameWnd::OnHelpFinder)
	ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, CFrameWnd::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, CFrameWnd::OnHelpFinder)

	ON_UPDATE_COMMAND_UI(ID_INDICATOR_CAPS, OnUpdateKolIgr)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_NUM, OnUpdatePobed)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_SCRL, OnUpdatePartii)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_OVR, OnUpdateStchet)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_PROIG, OnUpdateProigr)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR, 
	// status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_PROIG,
	ID_INDICATOR_SCRL,
	ID_INDICATOR_OVR
};


// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
m_wndStatusBar.SetPaneInfo(1,ID_INDICATOR_CAPS,0,50);
m_wndStatusBar.SetPaneInfo(2,ID_INDICATOR_NUM,0,60);
m_wndStatusBar.SetPaneInfo(3,ID_INDICATOR_PROIG,0,100);
m_wndStatusBar.SetPaneInfo(4,ID_INDICATOR_SCRL,0,80);
m_wndStatusBar.SetPaneInfo(5,ID_INDICATOR_OVR,0,170);


	if (!m_wndTOOLBAR2.CreateEx(this, TBSTYLE_ALTDRAG, WS_CHILD | WS_VISIBLE | CBRS_BOTTOM| CBRS_TOOLTIPS ) ||
		!m_wndTOOLBAR2.LoadToolBar(IDR_TOOLBAR1))

	{
		TRACE0("Failed to create toolbar2\n");
		return -1;      // fail to create
	}
m_wndTOOLBAR2.SetButtons(toolbar1,4);
	m_wndTOOLBAR2.SetButtonInfo(0,ID_SEPARATOR,TBBS_SEPARATOR,230);
	
	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style = WS_OVERLAPPED | WS_CAPTION 
		 | WS_MINIMIZEBOX | WS_SYSMENU;

	cs.x=50;//::GetSystemMetrics(SM_CXSCREEN);
	cs.y=50;//::GetSystemMetrics(SM_CYSCREEN);
	

cs.cx=700;
cs.cy=500;

PlaySound(MAKEINTRESOURCE(IDR_WAVE1),0,SND_RESOURCE|SND_LOOP | SND_ASYNC);

	return TRUE;
}


// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}


#endif //_DEBUG



void CMainFrame::OnUpdateKolIgr(CCmdUI *pCmdUI)
{
	CKozelDoc* pDoc=(CKozelDoc*)GetActiveDocument();

	TCHAR str2[30];
	wsprintf(str2,"Игр - %d",pDoc->m_nKolSigranIgr);

CStatusBar* pBar=&this->m_wndStatusBar;
pBar->SetPaneText(1,str2);
	/*pBar->SetPaneText(2,"Партий");
	pBar->SetPaneText(3,"Побед");
	pBar->SetPaneText(4,"Счет");*/
}


void CMainFrame::OnUpdateStchet(CCmdUI *pCmdUI)
{
	CKozelDoc* pDoc=(CKozelDoc*)GetActiveDocument();

	TCHAR str2[30];
	wsprintf(str2,"СЧЕТ: игрок %d :: %d комп ",pDoc->m_nShtrafOchkiIgroka,pDoc->m_nShtrafOchkiCompa);
CStatusBar* pBar=&this->m_wndStatusBar;
pBar->SetPaneText(5,str2);
}

void CMainFrame::OnUpdatePobed(CCmdUI *pCmdUI)
{
	CKozelDoc* pDoc=(CKozelDoc*)GetActiveDocument();

	TCHAR str2[30];
wsprintf(str2,"Побед - %d",pDoc->m_nSkolkoViigralIgrok);

CStatusBar* pBar=&this->m_wndStatusBar;
pBar->SetPaneText(2,str2);
}

void CMainFrame::OnUpdatePartii(CCmdUI *pCmdUI)
{
	CKozelDoc* pDoc=(CKozelDoc*)GetActiveDocument();

	TCHAR str2[30];
	wsprintf(str2,"Партий - %d",pDoc->m_nKolPartii);

CStatusBar* pBar=&this->m_wndStatusBar;
pBar->SetPaneText(4,str2);
}

void CMainFrame::OnUpdateProigr(CCmdUI *pCmdUI)
{
	CKozelDoc* pDoc=(CKozelDoc*)GetActiveDocument();

	TCHAR str2[30];
	wsprintf(str2,"Поражений - %d",pDoc->m_nPorageniiIgroka);

CStatusBar* pBar=&this->m_wndStatusBar;
pBar->SetPaneText(3,str2);
}
// CMainFrame message handlers


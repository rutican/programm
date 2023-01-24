// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"


#include "Krest.h"

#include "DlgIP.h"

//#include "..\..\MyBiblioteka\MyShowErr.h"

//#include "ServerSok.h"
//#include "KlientSok.h"


#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//#define _UNICODE

//==========================
BOOL NOVAYA_IGRA=FALSE;// не было вопроса о нач новой игры

int line;//показыв какую линию зачеркнуть
/////////ввожу переменные необходимые для управления игрой для ИНЕТА
int GAME_VID_IGRI=0;
//

//
TCHAR INDIKATOR[100];
int GAME_SOST=0;		 
BOOL XOD=1;//0-Ход комп  1-ход игрока
//

///////////Массив данных
int Mas[9]={0,0,0,0,0,0,0,0,0};
int Mas2[9]={0,0,0,0,0,0,0,0,0};
//////////Массив координат квадратов


//CRect rect0(50,50,100,100),rect1(100,50,150,100),rect2(150,50,200,100),
//		rect3(10,10,20,20),rect4(10,10,20,20),rect5(10,10,20,20),
//		rect6(10,10,20,20),rect7(10,10,20,20),rect8(10,10,20,20);


// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	// Global help commands
	ON_COMMAND(ID_HELP_FINDER, CFrameWnd::OnHelpFinder)
	ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, CFrameWnd::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, CFrameWnd::OnHelpFinder)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_KRESTIC, OnKrestic)
	ON_COMMAND(ID_NOVAYA_IGRA, OnNovayaIgra)
	ON_UPDATE_COMMAND_UI(ID_KRESTIC, OnUpdateKrestic)
	ON_COMMAND(ID_NOLIK, OnNolik)
	ON_UPDATE_COMMAND_UI(ID_NOLIK, OnUpdateNolik)
	ON_COMMAND(ID_OCHEN_PROSTOI, OnOchenProstoi)
	ON_UPDATE_COMMAND_UI(ID_OCHEN_PROSTOI, OnUpdateOchenProstoi)
	ON_COMMAND(ID_PROSTOI, OnProstoi)
	ON_UPDATE_COMMAND_UI(ID_PROSTOI, OnUpdateProstoi)
	ON_COMMAND(ID_SLOGNII, OnSlognii)
	ON_UPDATE_COMMAND_UI(ID_SLOGNII, OnUpdateSlognii)

	ON_MESSAGE(WM_COMMANDHELP, OnCommandHelp)
	ON_MESSAGE(WM_HELPHITTEST, OnHelpHitTest)

	ON_UPDATE_COMMAND_UI(ID_INDICATOR_CAPS, OnUpdatePobedi)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_NUM, OnUpdatePorageniya)

	ON_WM_TIMER()

	ON_COMMAND(ID_SERVER, OnServer)
	ON_COMMAND(ID_KLIENT, OnKlient)
	ON_UPDATE_COMMAND_UI(ID_SERVER, OnUpdateServer)
	ON_UPDATE_COMMAND_UI(ID_KLIENT, OnUpdateKlient)
	
	ON_COMMAND(ID_VIRUBIT_SET, OnVirubitSet)
	ON_UPDATE_COMMAND_UI(ID_VIRUBIT_SET, OnUpdateVirubitSet)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM
	
};


// CMainFrame construction/destruction

CMainFrame::CMainFrame():rect0(120,100,170,150),
						rect1(170,100,220,150),
						rect2(220,100,270,150),

						rect3(120,150,170,200),
						rect4(170,150,220,200),
						rect5(220,150,270,200),

						rect6(120,200,170,250),
						rect7(170,200,220,250),
						rect8(220,200,270,250)
{
	// TODO: add member initialization code here



	Simbol=TRUE;
	UrovenSlognosti=3;
	
	 pobeda=false;
	 proigrish=false;
	 nichya=false;
	 line=0;

	 pobedi=0;
	 proigrishi=0;
	 nichi=0;

	 FlagPobed=FALSE;
	 pServSok=0;
	 pKlientSok=0;
}

CMainFrame::~CMainFrame()
{
	if(pServSok)
	{
		////pServSok->Close();
		delete pServSok;
	}
    if(pKlientSok)
	{
		//pKlientSok->Close();
		delete pKlientSok;
	}
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	// create a view to occupy the client area of the frame
	/*if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}
	*/
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
	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

GAME_SOST=GAME_XOD_IGROKA;
SetTimer(555,200,NULL);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
//CRect rect;


	LOGBRUSH lb;
	lb.lbColor=RGB(0,128,0);
	lb.lbHatch=0;
	lb.lbStyle=BS_SOLID;


	//cs.dwExStyle |= WS_EX_CLIENTEDGE;
	//cs.style &= ~WS_BORDER;
cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW
		|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW),
		CreateBrushIndirect(&lb),  theApp.LoadIcon( IDR_MAINFRAME));
	
cs.style = WS_EX_CLIENTEDGE | WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		 | WS_MINIMIZEBOX | WS_SYSMENU;

cs.x=GetSystemMetrics(SM_CXSCREEN)/4;
cs.y=GetSystemMetrics(SM_CYSCREEN)/6;

cs.cx=400;
cs.cy=400;
	
//==============
GAME_VID_IGRI=SOK_NET;

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


// CMainFrame message handlers

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// forward focus to the view window
//	m_wndView.SetFocus();
}

//BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
//{
//	// let the view have first crack at the command
//	/*if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
//		return TRUE;*/
//
//	// otherwise, do default handling
//	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
//}

void CMainFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CFrameWnd::OnPaint() for painting messages
// Сетевая или обичная игра
dc.SetBkMode(TRANSPARENT);
if(GAME_VID_IGRI==SOK_NET)
	dc.TextOut(290,30,"Обычная игра!");
else if((GAME_VID_IGRI==SOK_KLIENT)|(GAME_VID_IGRI==SOK_SERVER))
	dc.TextOut(290,30,"Сетевая игра!");
//===========
	//Рисую индикатор состояния игры
	
	//wsprintf(INDIKATOR,"Всякая хрень");

	dc.TextOut(0,30,INDIKATOR);

//===========
CPen pen1(PS_SOLID,5,RGB(0,0,120));
CPen pen2(PS_SOLID,5,RGB(120,120,0));
CPen pen3(PS_SOLID,5,RGB(0,120,120));


CPen *pPen=dc.SelectObject(&pen1);

//dc.SetBkMode(RGB(0,128,0));

//Рисовани поля игры
dc.Rectangle(rect0);
dc.Rectangle(rect1);
dc.Rectangle(rect2);

dc.Rectangle(rect3);
dc.Rectangle(rect4);
dc.Rectangle(rect5);

dc.Rectangle(rect6);
dc.Rectangle(rect7);
dc.Rectangle(rect8);



for(int i=0; i<9; i++)////рисуем х и о так как заполнен массив
{

////////////////////крестик///////////
if(Mas[i]==4)
{
	dc.SelectObject(&pen2);
	switch(i)
	{
	case 0:
		if(!Simbol)
		{
			dc.MoveTo(rect0.left+10,rect0.top+10);
			dc.LineTo(rect0.right-10,rect0.bottom-10);

			dc.MoveTo(rect0.right-10,rect0.top+10);
			dc.LineTo(rect0.left+10,rect0.bottom-10);
		}
		else
		{
			dc.Ellipse(rect0.left+10,rect0.top+10,rect0.right-10,rect0.bottom-10);
		}
		
		break;

	case 1:
		if(!Simbol)
		{
			dc.MoveTo(rect1.left+10,rect1.top+10);
			dc.LineTo(rect1.right-10,rect1.bottom-10);

			dc.MoveTo(rect1.right-10,rect1.top+10);
			dc.LineTo(rect1.left+10,rect1.bottom-10);
		}
		else
		{
		dc.Ellipse(rect1.left+10,rect1.top+10,rect1.right-10,rect1.bottom-10);
		}
		break;

	case 2:
		if(!Simbol)
		{
			dc.MoveTo(rect2.left+10,rect2.top+10);
			dc.LineTo(rect2.right-10,rect2.bottom-10);

			dc.MoveTo(rect2.right-10,rect2.top+10);
			dc.LineTo(rect2.left+10,rect2.bottom-10);
		}
		else
		{
		dc.Ellipse(rect2.left+10,rect2.top+10,rect2.right-10,rect2.bottom-10);
		}
		break;

	case 3:
		if(!Simbol)
		{
			dc.MoveTo(rect3.left+10,rect3.top+10);
			dc.LineTo(rect3.right-10,rect3.bottom-10);

			dc.MoveTo(rect3.right-10,rect3.top+10);
			dc.LineTo(rect3.left+10,rect3.bottom-10);
		}
		else
		{
		dc.Ellipse(rect3.left+10,rect3.top+10,rect3.right-10,rect3.bottom-10);
		}
		break;

	case 4:
		if(!Simbol)
		{
			dc.MoveTo(rect4.left+10,rect4.top+10);
			dc.LineTo(rect4.right-10,rect4.bottom-10);

			dc.MoveTo(rect4.right-10,rect4.top+10);
			dc.LineTo(rect4.left+10,rect4.bottom-10);
		}
		else
		{
		dc.Ellipse(rect4.left+10,rect4.top+10,rect4.right-10,rect4.bottom-10);
		}
		break;

	case 5:
		if(!Simbol)
		{
			dc.MoveTo(rect5.left+10,rect5.top+10);
			dc.LineTo(rect5.right-10,rect5.bottom-10);

			dc.MoveTo(rect5.right-10,rect5.top+10);
			dc.LineTo(rect5.left+10,rect5.bottom-10);
		}
		else
		{
		dc.Ellipse(rect5.left+10,rect5.top+10,rect5.right-10,rect5.bottom-10);
		}
		break;

	case 6:
		if(!Simbol)
		{
			dc.MoveTo(rect6.left+10,rect6.top+10);
			dc.LineTo(rect6.right-10,rect6.bottom-10);

			dc.MoveTo(rect6.right-10,rect6.top+10);
			dc.LineTo(rect6.left+10,rect6.bottom-10);
		}
		else
		{
		dc.Ellipse(rect6.left+10,rect6.top+10,rect6.right-10,rect6.bottom-10);
		}
		break;

	case 7:
		if(!Simbol)
		{
			dc.MoveTo(rect7.left+10,rect7.top+10);
			dc.LineTo(rect7.right-10,rect7.bottom-10);

			dc.MoveTo(rect7.right-10,rect7.top+10);
			dc.LineTo(rect7.left+10,rect7.bottom-10);
		}
		else
		{
		dc.Ellipse(rect7.left+10,rect7.top+10,rect7.right-10,rect7.bottom-10);
		}
		break;

	case 8:
		if(!Simbol)
		{
			dc.MoveTo(rect8.left+10,rect8.top+10);
			dc.LineTo(rect8.right-10,rect8.bottom-10);

			dc.MoveTo(rect8.right-10,rect8.top+10);
			dc.LineTo(rect8.left+10,rect8.bottom-10);
		}
		else
		{
		dc.Ellipse(rect8.left+10,rect8.top+10,rect8.right-10,rect8.bottom-10);
		}
		break;
	}
}
//////////////////////

////////////////////////игрок///////////


//;

if((Mas[i]==1))//&&(Simbol))
{
	dc.SelectObject(&pen3);
	switch(i)
	{
	case 0:
		if(Simbol)
		{
			dc.MoveTo(rect0.left+10,rect0.top+10);
			dc.LineTo(rect0.right-10,rect0.bottom-10);

			dc.MoveTo(rect0.right-10,rect0.top+10);
			dc.LineTo(rect0.left+10,rect0.bottom-10);
		}
		else
		{
			dc.Ellipse(rect0.left+10,rect0.top+10,rect0.right-10,rect0.bottom-10);
		}
		
		break;

	case 1:
		if(Simbol)
		{
			dc.MoveTo(rect1.left+10,rect1.top+10);
			dc.LineTo(rect1.right-10,rect1.bottom-10);

			dc.MoveTo(rect1.right-10,rect1.top+10);
			dc.LineTo(rect1.left+10,rect1.bottom-10);
		}
		else
		{
		dc.Ellipse(rect1.left+10,rect1.top+10,rect1.right-10,rect1.bottom-10);
		}
		break;

	case 2:
		if(Simbol)
		{
			dc.MoveTo(rect2.left+10,rect2.top+10);
			dc.LineTo(rect2.right-10,rect2.bottom-10);

			dc.MoveTo(rect2.right-10,rect2.top+10);
			dc.LineTo(rect2.left+10,rect2.bottom-10);
		}
		else
		{
		dc.Ellipse(rect2.left+10,rect2.top+10,rect2.right-10,rect2.bottom-10);
		}
		break;

	case 3:
		if(Simbol)
		{
			dc.MoveTo(rect3.left+10,rect3.top+10);
			dc.LineTo(rect3.right-10,rect3.bottom-10);

			dc.MoveTo(rect3.right-10,rect3.top+10);
			dc.LineTo(rect3.left+10,rect3.bottom-10);
		}
		else
		{
		dc.Ellipse(rect3.left+10,rect3.top+10,rect3.right-10,rect3.bottom-10);
		}
		break;

	case 4:
		if(Simbol)
		{
			dc.MoveTo(rect4.left+10,rect4.top+10);
			dc.LineTo(rect4.right-10,rect4.bottom-10);

			dc.MoveTo(rect4.right-10,rect4.top+10);
			dc.LineTo(rect4.left+10,rect4.bottom-10);
		}
		else
		{
		dc.Ellipse(rect4.left+10,rect4.top+10,rect4.right-10,rect4.bottom-10);
		}
		break;

	case 5:
		if(Simbol)
		{
			dc.MoveTo(rect5.left+10,rect5.top+10);
			dc.LineTo(rect5.right-10,rect5.bottom-10);

			dc.MoveTo(rect5.right-10,rect5.top+10);
			dc.LineTo(rect5.left+10,rect5.bottom-10);
		}
		else
		{
		dc.Ellipse(rect5.left+10,rect5.top+10,rect5.right-10,rect5.bottom-10);
		}
		break;

	case 6:
		if(Simbol)
		{
			dc.MoveTo(rect6.left+10,rect6.top+10);
			dc.LineTo(rect6.right-10,rect6.bottom-10);

			dc.MoveTo(rect6.right-10,rect6.top+10);
			dc.LineTo(rect6.left+10,rect6.bottom-10);
		}
		else
		{
		dc.Ellipse(rect6.left+10,rect6.top+10,rect6.right-10,rect6.bottom-10);
		}
		break;

	case 7:
		if(Simbol)
		{
			dc.MoveTo(rect7.left+10,rect7.top+10);
			dc.LineTo(rect7.right-10,rect7.bottom-10);

			dc.MoveTo(rect7.right-10,rect7.top+10);
			dc.LineTo(rect7.left+10,rect7.bottom-10);
		}
		else
		{
		dc.Ellipse(rect7.left+10,rect7.top+10,rect7.right-10,rect7.bottom-10);
		}
		break;

	case 8:
		if(Simbol)
		{
			dc.MoveTo(rect8.left+10,rect8.top+10);
			dc.LineTo(rect8.right-10,rect8.bottom-10);

			dc.MoveTo(rect8.right-10,rect8.top+10);
			dc.LineTo(rect8.left+10,rect8.bottom-10);
		}
		else
		{
		dc.Ellipse(rect8.left+10,rect8.top+10,rect8.right-10,rect8.bottom-10);
		}
		break;
	}

}

//=====Зачеркиваю, показывая выигрыш
CPen pen4(BS_SOLID,4,RGB(255,0,0));
dc.SelectObject(&pen4);
switch(line)
{
	case 1:
		dc.MoveTo(120,125);
		dc.LineTo(270,125);
			break;
	case 2:
		dc.MoveTo(120,175);
		dc.LineTo(270,175);
			break;
	case 3:
		dc.MoveTo(120,225);
		dc.LineTo(270,225);
			break;
	case 4:
		dc.MoveTo(145,100);
		dc.LineTo(145,250);
		break;
	case 5:
		dc.MoveTo(195,100);
		dc.LineTo(195,250);
			break;
	case 6:
		dc.MoveTo(245,100);
		dc.LineTo(245,250);
			break;
	case 7:
		dc.MoveTo(120,100);
		dc.LineTo(270,250);
			break;
	case 8:
		dc.MoveTo(270,100);
		dc.LineTo(120,250);
			break;

}


////////////////////////////////////
}
dc.SelectObject(pPen);

}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//проверяю условия возможности хода игрока
	if(GAME_VID_IGRI==SOK_NET){
		if(GAME_SOST!=GAME_XOD_IGROKA)
			return;}
	else if (GAME_VID_IGRI==SOK_SERVER){
			if(GAME_SOST!=GAME_XOD_SERVERA)
				return;}
	else if (GAME_VID_IGRI==SOK_KLIENT){
			if(GAME_SOST!=GAME_XOD_KLIENTA)
				return;}

BOOL bilxod=false;

	CFrameWnd::OnLButtonDown(nFlags, point);

CRect RECT(120,100,270,250),rect;

if (!RECT.PtInRect(point))
{
	return;
}

if(rect0.PtInRect(point)&& Mas[0]==0){ Mas[0]=1;rect=rect0;bilxod=true;}
if(rect1.PtInRect(point)&& Mas[1]==0){ Mas[1]=1;rect=rect1;bilxod=true;}
if(rect2.PtInRect(point)&& Mas[2]==0){ Mas[2]=1;rect=rect2;bilxod=true;}
if(rect3.PtInRect(point)&& Mas[3]==0){ Mas[3]=1;rect=rect3;bilxod=true;}
if(rect4.PtInRect(point)&& Mas[4]==0){ Mas[4]=1;rect=rect4;bilxod=true;}
if(rect5.PtInRect(point)&& Mas[5]==0){ Mas[5]=1;rect=rect5;bilxod=true;}
if(rect6.PtInRect(point)&& Mas[6]==0){ Mas[6]=1;rect=rect6;bilxod=true;}
if(rect7.PtInRect(point)&& Mas[7]==0){ Mas[7]=1;rect=rect7;bilxod=true;}
if(rect8.PtInRect(point)&& Mas[8]==0){ Mas[8]=1;rect=rect8;bilxod=true;}


//if(rect0.PtInRect(point)&& Mas[0]==0)
//{ Mas[0]=1;}
//if(rect1.PtInRect(point)&& Mas[1]==0)
//{ Mas[1]=1;}
//if(rect2.PtInRect(point)&& Mas[2]==0)
//{ Mas[2]=1;}
//if(rect3.PtInRect(point)&& Mas[3]==0)
//{ Mas[3]=1;}
//if(rect4.PtInRect(point)&& Mas[4]==0)
//{ Mas[4]=1;}
//if(rect5.PtInRect(point)&& Mas[5]==0)
//{ Mas[5]=1;}
//if(rect6.PtInRect(point)&& Mas[6]==0)
//{ Mas[6]=1;}
//if(rect7.PtInRect(point)&& Mas[7]==0)
//{ Mas[7]=1;}
//if(rect8.PtInRect(point)&& Mas[8]==0)
//{ Mas[8]=1;}

if(bilxod){
if(GAME_VID_IGRI==SOK_NET)
	GAME_SOST=GAME_XOD_COMPA;
else if (GAME_VID_IGRI==SOK_SERVER)
	GAME_SOST=GAME_XOD_KLIENTA;
else if (GAME_VID_IGRI==SOK_KLIENT)
	GAME_SOST=GAME_XOD_SERVERA;

NOVAYA_IGRA=FALSE;//Разрешен вопрос аппаненту на новую игру!
InvalidateRect(CRect(120,100,270,250));
}//if

}


	


void CMainFrame::OnKrestic()
{
	// TODO: Add your command handler code here
	Simbol=TRUE;
	InvalidateRect(CRect(120,100,270,250));

//OnNovayaIgra();

}



void CMainFrame::OnNovayaIgra()
{
	// TODO: Add your command handler code here
	//GAME_SOST=GAME_XOD_IGROKA;
//-----передаю дсдерверу или клиенту Мас который сообщает о новой игре

	if((GAME_VID_IGRI==SOK_SERVER)&(!NOVAYA_IGRA))
	{
		for(int i=0; i<9; i++)
			Mas2[i]=11;
		pServSok->OnSend(1);
		if(GAME_SOST!=GAME_FINISH)
			return;

	}//if
	else if((GAME_VID_IGRI==SOK_KLIENT)&(!NOVAYA_IGRA)){
		for(int i=0; i<9; i++)
			Mas2[i]=11;
		pKlientSok->OnSend(1);//1- спросить о новой игре
		if(GAME_SOST!=GAME_FINISH)
			return;

	}//else if

//..==================
SetTimer(555,200,0);

	for(int i=0; i<9; i++)
	{
		Mas[i]=0;
	}
 pobeda=false;
proigrish=false;
 nichya=false;
line=0;

FlagPobed=FALSE;

 KillTimer(777);

	InvalidateRect(CRect(0,50,470,370));

//if(GAME_VID_IGRI==SOK_NET){
//		if(GAME_SOST!=GAME_XOD_IGROKA)
//			return;}
//else if (GAME_VID_IGRI==SOK_SERVER){
//			if(GAME_SOST!=GAME_XOD_SERVERA)
//				return;}
//else if (GAME_VID_IGRI==SOK_KLIENT){
//			if(GAME_SOST!=GAME_XOD_KLIENTA)
//				return;}	
 
}

void CMainFrame::OnUpdateKrestic(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
//int sum=0;
//for(int i=0; i<9; i++)
//{
//sum+=Mas[i];
//}
//pCmdUI->Enable(sum==0);
	//pCmdUI->SetCheck(Simbol);	
	pCmdUI->Enable(!Simbol);
}

void CMainFrame::OnNolik()
{
	// TODO: Add your command handler code here
	Simbol=FALSE;
	InvalidateRect(CRect(120,100,270,250));

	//OnNovayaIgra();
	
}

void CMainFrame::OnUpdateNolik(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	/*int sum=0;
for(int i=0; i<9; i++)
{
sum+=Mas[i];
}
pCmdUI->Enable(sum==0);*/
//pCmdUI->SetCheck(!Simbol);	
	pCmdUI->Enable(Simbol);

}

void CMainFrame::OnOchenProstoi()
{
	// TODO: Add your command handler code here
	UrovenSlognosti=1;
}

void CMainFrame::OnUpdateOchenProstoi(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetCheck(UrovenSlognosti==1);
		int sum=0;
for(int i=0; i<9; i++)
{
sum+=Mas[i];
}
pCmdUI->Enable(sum==0);

}

void CMainFrame::OnProstoi()
{
	// TODO: Add your command handler code here
	UrovenSlognosti=2;
}

void CMainFrame::OnUpdateProstoi(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetCheck(UrovenSlognosti==2);
		int sum=0;
for(int i=0; i<9; i++)
{
sum+=Mas[i];
}
pCmdUI->Enable(sum==0);

}

void CMainFrame::OnSlognii()
{
	// TODO: Add your command handler code here
	UrovenSlognosti=3;
}

void CMainFrame::OnUpdateSlognii(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetCheck(UrovenSlognosti==3);
		int sum=0;
for(int i=0; i<9; i++)
{
sum+=Mas[i];
}
pCmdUI->Enable(sum==0);

}


BOOL CMainFrame::KtoViigral()
{

//int i,j;
int sum=0;

 sum=Mas[0]+Mas[1]+Mas[2];
 if (sum==3){pobeda=true; line=1;} 
 if (sum==12){proigrish=true;line=1;} 
 {sum=0;}

 sum=Mas[3]+Mas[4]+Mas[5];
  if (sum==3){pobeda=true;line=2;} 
  if (sum==12){proigrish=true;line=2;} 
  {sum=0;}

 sum=Mas[6]+Mas[7]+Mas[8];
  if (sum==3){pobeda=true;line=3;} 
  if (sum==12){proigrish=true;line=3;} 
  {sum=0;}
 sum=Mas[0]+Mas[3]+Mas[6];
  if (sum==3){pobeda=true;line=4;} 
  if (sum==12){proigrish=true;line=4;} 
  {sum=0;}
 sum=Mas[1]+Mas[4]+Mas[7];
  if (sum==3){pobeda=true;line=5;} 
  if (sum==12){proigrish=true;line=5;} 
  {sum=0;}
 sum=Mas[2]+Mas[5]+Mas[8];
  if (sum==3){pobeda=true;line=6;} 
  if (sum==12){proigrish=true;line=6;} 
  {sum=0;}
 sum=Mas[0]+Mas[4]+Mas[8];
  if (sum==3){pobeda=true;line=7;} 
  if (sum==12){proigrish=true;line=7;} 
  {sum=0;}
 sum=Mas[6]+Mas[4]+Mas[2];
	 if (sum==3){pobeda=true;line=8;}
	 if (sum==12){proigrish=true;line=8;} 
	 {sum=0;}

	
	
if ((pobeda) &&(!FlagPobed))
{
//MessageBox (" ВЫ выиграли!","",NULL);
	SetTimer(777,200,NULL);
	FlagPobed=TRUE;
	pobedi+=1;
	InvalidateRect(CRect(120,100,270,250));
	GAME_SOST=GAME_FINISH;

}
if ((proigrish) &&(!FlagPobed))
{
//MessageBox (" ВЫ Проиграли!","",NULL);
SetTimer(777,200,NULL);
FlagPobed=TRUE;
proigrishi+=1;
InvalidateRect(CRect(120,100,270,250));
	GAME_SOST=GAME_FINISH;

}
int sum1=0;
for(int i=0; i<9; i++)
{
	sum1+=Mas[i];
}

if ((sum1==24 || sum1==21)&&(!FlagPobed))
	{nichya=true;}
	if (nichya) 
{
//MessageBox("  НИЧЬЯ!","",NULL);

	SetTimer(777,200,NULL);
	FlagPobed=TRUE;
	nichi+=1;
	InvalidateRect(CRect(120,100,270,250));
	GAME_SOST=GAME_FINISH;

}

//======заполняю массив, чтобы нельзя было сходить

for(int j=0; j<9; j++)
{
	if((Mas[j]==0) &&(pobeda || proigrish || nichya))
	{Mas[j]=9;}
}

return 0;
}


void CMainFrame::OtvetKompa()
{
	int nomKnop=0;
	int sum=0;
	bool XodSdelan=false;

////////////////
	
	
if(GAME_SOST!=GAME_XOD_COMPA)
		return;

////////Первый ход //////////////
	for(int i=0; i<9;i++)
	{
			sum+=Mas[i];
	}

	if ((sum==1) | (sum==0))
	{
		//if(Mas[0]+Mas[2]+Mas[6]+Mas[8]=1)
		if(Mas[4]==0)
		{
			
			Mas[4]=4;
		}
		else
		{
			
			Mas[8]=4;
		}
		XodSdelan=true;
	}

///////Сходить если можно выиграть////////////////////
if((UrovenSlognosti==2)||(UrovenSlognosti==3))
{
	sum=Mas[0]+Mas[1]+Mas[2];
 if ((sum==8) && (!XodSdelan))
 {if(Mas[0]==0)
	{
		
		Mas[0]=4;
	}
	if(Mas[1]==0)
	{
		
		Mas[1]=4;
	}
	if(Mas[2]==0)
	{
		
		Mas[2]=4;
	}
	XodSdelan=true;
} 
 else {sum=0;}

 sum=Mas[3]+Mas[4]+Mas[5];
  if ((sum==8)&& (!XodSdelan))
  {if(Mas[3]==0)
	{
		
		Mas[3]=4;
	}
	if(Mas[4]==0)
	{
		
		Mas[4]=4;
	}
	if(Mas[5]==0)
	{
		
		Mas[5]=4;
	}
	XodSdelan=true;
  }
  else {sum=0;}
 sum=Mas[6]+Mas[7]+Mas[8];
  if ((sum==8)&& (!XodSdelan))
  {if(Mas[6]==0)
	{
		
		Mas[6]=4;
	}
	if(Mas[7]==0)
	{
		
		Mas[7]=4;
	}
	if(Mas[8]==0)
	{
	
		Mas[8]=4;
	}
	XodSdelan=true;
  } 
  else {sum=0;}
 sum=Mas[0]+Mas[3]+Mas[6];
  if ((sum==8)&& (!XodSdelan))
  {if(Mas[0]==0)
	{
		
		Mas[0]=4;
	}
	  if(Mas[3]==0)
	{
		
		Mas[3]=4;
	}
	  if(Mas[6]==0)
	{
		
		Mas[6]=4;
	}
XodSdelan=true;
  } 
  else {sum=0;}
 sum=Mas[1]+Mas[4]+Mas[7];
  if ((sum==8)&& (!XodSdelan))
  {if(Mas[1]==0)
	{
	
		Mas[1]=4;
	}
	if(Mas[4]==0)
	{
	
		Mas[4]=4;
	}
	if(Mas[7]==0)
	{
		
		Mas[7]=4;
	}
	XodSdelan=true;
  } 
  else {sum=0;}
 sum=Mas[2]+Mas[5]+Mas[8];
  if ((sum==8)&& (!XodSdelan))
  {if(Mas[2]==0)
	{
		
		Mas[2]=4;
	}
	if(Mas[5]==0)
	{
		
		Mas[5]=4;
	}
	if(Mas[8]==0)
	{
		
		Mas[8]=4;
	}
	XodSdelan=true;
  } 
  else {sum=0;}
 sum=Mas[0]+Mas[4]+Mas[8];
  if ((sum==8)&& (!XodSdelan))
  {if(Mas[0]==0)
	{
		
		Mas[0]=4;
	}
	if(Mas[4]==0)
	{
		
		Mas[4]=4;
	}
	if(Mas[8]==0)
	{
	
		Mas[8]=4;
	}
XodSdelan=true;
  } 
  else {sum=0;}

 sum=Mas[6]+Mas[4]+Mas[2];
if ((sum==8)&& (!XodSdelan))
	 {if(Mas[6]==0)
	{
		
			Mas[6]=4;
	}
	if(Mas[4]==0)
	{
		
		Mas[4]=4;
	}
	if(Mas[2]==0)
	{
	
		Mas[2]=4;
	}
	XodSdelan=true;
} 
else {sum=0;}
}
/////////////////////Сходить в ответ//////////////////////
if((UrovenSlognosti==2) || (UrovenSlognosti==3))
{
sum=Mas[0]+Mas[1]+Mas[2];
 if ((sum==2) && (!XodSdelan))
 {if(Mas[0]==0)
	{
		
			Mas[0]=4;
	}
	if(Mas[1]==0)
	{
		
			Mas[1]=4;
	}
	if(Mas[2]==0)
	{
		
			Mas[2]=4;
	}
	XodSdelan=true;
} 
 else {sum=0;}

 sum=Mas[3]+Mas[4]+Mas[5];
  if ((sum==2)&& (!XodSdelan))
  {if(Mas[3]==0)
	{
		
			Mas[3]=4;
	}
	if(Mas[4]==0)
	{
		
			Mas[4]=4;
	}
	if(Mas[5]==0)
	{
		
			Mas[5]=4;
	}
	XodSdelan=true;
  }
  else {sum=0;}
 sum=Mas[6]+Mas[7]+Mas[8];
  if ((sum==2)&& (!XodSdelan))
  {if(Mas[6]==0)
	{
		
			Mas[6]=4;
	}
	if(Mas[7]==0)
	{
		
			Mas[7]=4;
	}
	if(Mas[8]==0)
	{
		
			Mas[8]=4;
	}
	XodSdelan=true;
  } 
  else {sum=0;}
 sum=Mas[0]+Mas[3]+Mas[6];
  if ((sum==2)&& (!XodSdelan))
  {if(Mas[0]==0)
	{
		
			Mas[0]=4;
	}
	  if(Mas[3]==0)
	{
		
			Mas[3]=4;
	}
	  if(Mas[6]==0)
	{
		
			Mas[6]=4;
	}
XodSdelan=true;
  } 
  else {sum=0;}
 sum=Mas[1]+Mas[4]+Mas[7];
  if ((sum==2)&& (!XodSdelan))
  {if(Mas[1]==0)
	{
		
		Mas[1]=4;
	}
	if(Mas[4]==0)
	{
		
		Mas[4]=4;
	}
	if(Mas[7]==0)
	{
	
	
		Mas[7]=4;
	}
	XodSdelan=true;
  } 
  else {sum=0;}
 sum=Mas[2]+Mas[5]+Mas[8];
  if ((sum==2)&& (!XodSdelan))
  {if(Mas[2]==0)
	{
	
		Mas[2]=4;
	}
	if(Mas[5]==0)
	{
		
		Mas[5]=4;
	}
	if(Mas[8]==0)
	{
		
		Mas[8]=4;
	}
	XodSdelan=true;
  } 
  else {sum=0;}
 sum=Mas[0]+Mas[4]+Mas[8];
  if ((sum==2)&& (!XodSdelan))
  {if(Mas[0]==0)
	{
		
		Mas[0]=4;
	}
	if(Mas[4]==0)
	{
	
		Mas[4]=4;
	}
	if(Mas[8]==0)
	{
		
		Mas[8]=4;
	}
XodSdelan=true;
  } 
  else {sum=0;}

 sum=Mas[6]+Mas[4]+Mas[2];
if ((sum==2)&& (!XodSdelan))
	 {if(Mas[6]==0)
	{
		
			Mas[6]=4;
	}
	if(Mas[4]==0)
	{
		
		Mas[4]=4;
	}
	if(Mas[2]==0)
	{
		
		Mas[2]=4;
	}
	XodSdelan=true;
} 
else {sum=0;}
}
if (!XodSdelan)// если все двойные ходы перекрыты сходить куда-нибудь
{
	for(int j=0;j<9;j++)
{
		if((UrovenSlognosti==3))//сложный уровень
{
		if((Mas[3]+Mas[4]+Mas[8]==6)&&(Mas[3]+Mas[8]==2)&& 
			(Mas[0]+Mas[1]+Mas[2]+Mas[5]+Mas[6]+Mas[7]==0))
		{
			
			Mas[6]=4;
			XodSdelan=true;
			break;
		}
		if((Mas[0]+Mas[4]+Mas[7]==6)&&(Mas[0]+Mas[7]==2)&& 
			(Mas[8]+Mas[1]+Mas[2]+Mas[5]+Mas[6]+Mas[3]==0))
		{
			
			Mas[6]=4;
			XodSdelan=true;
			break;
		}
		if((Mas[2]+Mas[4]+Mas[7]==6)&&(Mas[2]+Mas[7]==2)&& 
			(Mas[0]+Mas[1]+Mas[3]+Mas[5]+Mas[6]+Mas[8]==0))
		{
			
			Mas[8]=4;
			XodSdelan=true;
			break;
		}

		if((Mas[6]+Mas[4]+Mas[2]==6)&&(Mas[6]+Mas[2]==2)&& 
			(Mas[0]+Mas[1]+Mas[8]+Mas[5]+Mas[3]+Mas[7]==0))
		{
			
			Mas[7]=4;
			XodSdelan=true;
			break;
		}
		if((Mas[0]+Mas[4]+Mas[8]==6)&&(Mas[0]+Mas[8]==2)&& 
			(Mas[3]+Mas[1]+Mas[2]+Mas[5]+Mas[6]+Mas[7]==0))
		{
			Mas[7]=4;
			XodSdelan=true;
			break;
		}
		if (Mas[4]==0)
		{
			
			Mas[4]=4;
			break;
		}
	if ((Mas[3]+Mas[4]+Mas[7]==6)&&(Mas[0]+Mas[1]+Mas[2]+Mas[5]+Mas[6]+Mas[8]==0))
		{
			
			Mas[6]=4;
			XodSdelan=true;
			break;
		}


		if (Mas[2]==0)
		{
			
			Mas[2]=4;
			XodSdelan=true;
			break;
		}
}

		if	((Mas[j]==0)&& (!XodSdelan))
		{
			
			Mas[j]=4;
			break;
		}
	}
}

InvalidateRect(CRect(120,100,270,250));

GAME_SOST=GAME_XOD_IGROKA;

//KtoViigral();
}
void CMainFrame::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==777)
	{
CClientDC dc(this);
BOOL static stir=FALSE;
CFont font;


font.CreateFont(30,8,0,0,500,0,0,0,DEFAULT_CHARSET,
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
				PROOF_QUALITY,VARIABLE_PITCH| FF_DONTCARE,"Arial");

CFont *pFont=dc.SelectObject(&font);

dc.SetBkColor(RGB(0,128,0));
if(pobeda)
{
	dc.TextOut(130,60,"Вы Победили!");
	dc.TextOut(0,175,"Вы Победили!");
	dc.TextOut(275,175,"Вы Победили!");
	dc.TextOut(130,270,"Вы Победили!");
}

if(proigrish)
{
	dc.TextOut(130,60,"Вы Проиграли!");
	dc.TextOut(0,175,"Вы Проиграли!");
	dc.TextOut(275,175,"Вы Проиграли!");
	dc.TextOut(130,270,"Вы Проиграли!");

}

if((nichya)&&(proigrish||pobeda==FALSE))
{
	dc.TextOut(155,60,"Ничья!");
	dc.TextOut(30,175,"Ничья!");
	dc.TextOut(285,175,"Ничья!");
	dc.TextOut(155,270,"Ничья!");
}
dc.SelectObject(pFont);
	}
else if(nIDEvent== 555)
	{
		
		UpravlenieIgroi();
	}
	CFrameWnd::OnTimer(nIDEvent);

}

void CMainFrame::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar << UrovenSlognosti;
	}
	else
	{	// loading code
		ar >> UrovenSlognosti;
	}

	//заполняю строку состаяния

	/*CStatusBar* pBar=&this->m_wndStatusBar;
	pBar->SetPaneText(1,"Побед");*/

}

void CMainFrame::OnUpdatePobedi(CCmdUI *pCmdUI)
{
	//CString str="Побед";
	TCHAR str[15];//="Побед";
	TCHAR str2[5];
	wsprintf(str2,"  %d",pobedi);

//str+=str2;//pobedi;
wsprintf(str,"Побед%s",str2);
CStatusBar* pBar=&this->m_wndStatusBar;
	pBar->SetPaneText(1,str);
}
void  CMainFrame::OnUpdatePorageniya(CCmdUI *pCmdUI)
{
	//CString str="Поражений";
	TCHAR str[15];//="Поражений";
	TCHAR str2[5];
	wsprintf(str2,"  %d",proigrishi);

//str+=str2;//Поражений;
wsprintf(str,"Поражений%s",str2);
CStatusBar* pBar=&this->m_wndStatusBar;
	pBar->SetPaneText(2,str);
}

LRESULT CMainFrame::OnCommandHelp(WPARAM wParam, LPARAM lParam)
{
lParam=IDR_MAINFRAME+HID_BASE_RESOURCE;
AfxGetApp()->WinHelp(lParam);
return TRUE;
}

LRESULT  CMainFrame::OnHelpHitTest(WPARAM wParam, LPARAM lParam)
{
return IDR_MAINFRAME+HID_BASE_RESOURCE;
}

void CMainFrame::UpravlenieIgroi()
{
	if(GAME_VID_IGRI==SOK_NET){
	switch(GAME_SOST) 
	{
	case GAME_XOD_IGROKA:
			KtoViigral();
			wsprintf(INDIKATOR,"Ваш ход!");
			InvalidateRect(CRect(0,25,500,50));
			//OtvetKompa();
			break;
	case GAME_XOD_COMPA:
			KtoViigral();
			wsprintf(INDIKATOR,"Ход компа");
			InvalidateRect(CRect(0,25,500,50));
			OtvetKompa();
			break;
	case GAME_FINISH:
		wsprintf(INDIKATOR,"Финиш игры");
		InvalidateRect(CRect(0,25,500,50));		
		XOD=!XOD;
		 if(XOD)
			GAME_SOST=GAME_XOD_IGROKA;
		else
			GAME_SOST=GAME_XOD_COMPA;
		KillTimer(555);//убиваю таймер кот. вызыв этот код
			break;
		//memset(Mas,0,sizeof(Mas));
		
	}//switch
	}//if
	else if(GAME_VID_IGRI==SOK_SERVER){
		switch(GAME_SOST) 
		{
			case GAME_XOD_SERVERA:
				KtoViigral();
				wsprintf(INDIKATOR,"Ваш ход SERVER!");
				InvalidateRect(CRect(0,25,500,50));
				break;
			case GAME_XOD_KLIENTA:
				wsprintf(INDIKATOR,"Ход аппанента KLIENT!");
				InvalidateRect(CRect(0,25,500,50));
				//сервер сходил передаю данные клиенту и устанавлив его ход
				pServSok->OnSend(0);
				GAME_SOST=GAME_OGIDANIE;
				KtoViigral();
				break;
			case GAME_OGIDANIE:
					//?????????????
			wsprintf(INDIKATOR,"Ожидание  аппанента KLIENT!");
			InvalidateRect(CRect(0,25,500,50));
				break;
			case GAME_FINISH:
				wsprintf(INDIKATOR,"Финиш игры");
				InvalidateRect(CRect(0,25,500,50));		
			XOD=!XOD;
			if(XOD)
				GAME_SOST=GAME_XOD_SERVERA;
			else
				GAME_SOST=GAME_XOD_KLIENTA;
			KillTimer(555);//убиваю таймер кот. вызыв этот код
				break;
		}//switch
	}//else if
	else if(GAME_VID_IGRI==SOK_KLIENT){
		switch(GAME_SOST) 
		{
			case GAME_XOD_SERVERA:
				wsprintf(INDIKATOR,"Ход аппанента SERVER!");
				InvalidateRect(CRect(0,25,500,50));
				pKlientSok->OnSend(0);
				GAME_SOST=GAME_OGIDANIE;
				KtoViigral();
				break;
			case GAME_XOD_KLIENTA:
				wsprintf(INDIKATOR,"Ваш ход KLIENT!");
				InvalidateRect(CRect(0,25,500,50));

				KtoViigral();
				break;
			case GAME_OGIDANIE:
				wsprintf(INDIKATOR,"Ожидание аппанента SERVER!");
				InvalidateRect(CRect(0,25,500,50));
				break;
			case GAME_FINISH:
				wsprintf(INDIKATOR,"Финиш игры");
				InvalidateRect(CRect(0,25,500,50));	
			XOD=!XOD;
			if(XOD)
				GAME_SOST=GAME_XOD_SERVERA;
			else
				GAME_SOST=GAME_XOD_KLIENTA;
			KillTimer(555);//убиваю таймер кот. вызыв этот код

				break;

		}//switch

	}//else if

}
void CMainFrame::OnServer()
{
	// TODO: Add your command handler code here
	pServSok= new CServerSok;
OnNovayaIgra();
	BOOL fOK=pServSok->Create(2049);
		if(!fOK)
		{
			//ShowError();
			AfxMessageBox(" прошло неудачно Create",0,0);
			return;
		}
GAME_SOST=GAME_OGIDANIE;

	fOK=pServSok->Listen(1);
		if(!fOK)
		{
			//ShowError();
		   AfxMessageBox(" прошло неудачно Listen",0,0);
		   return;
		}

		
GAME_VID_IGRI=SOK_SERVER;//тип игры - сервер
GAME_SOST=GAME_OGIDANIE;//первый ход у сервера
XOD=1;//первый ход сервера
//char HostName[1024];
//LPHOSTENT lphost;
//DWORD m_HostIP = 0;
//if(!gethostname(HostName, 1024))
//{
//if( lphost = gethostbyname(HostName))
//m_HostIP = ((LPIN_ADDR)lphost->h_addr)->s_addr;
//char szIPAddr[17];
//strcpy(szIPAddr,inet_ntoa(*((in_addr*)lphost->h_addr_list[0]))); 
//
//lphost->
//int a=0;
}





void CMainFrame::OnKlient()
{
	// TODO: Add your command handler code here
//спросить IP-адрес

CDlgIP dlg;
TCHAR sIP[25];

dlg.m_strIP="127.0.0.1";
UpdateData();
int vibor=dlg.DoModal();
if(IDCANCEL==vibor)
		return;

wsprintf(sIP,dlg.m_strIP);

	pKlientSok=new CKlientSok;
OnNovayaIgra();
	if(!pKlientSok->Create()){
			AfxMessageBox("Create прошло неудачно",0,0);
			return;
	}
	
	
	GAME_SOST=GAME_OGIDANIE;

	BOOL fOK=pKlientSok->Connect(sIP,2049);
	if(!fOK)
	{
		delete pKlientSok;
		pKlientSok=0;
		AfxMessageBox("Connect прошло неудачно",0,0);
		return;
	}
	for(int i=0; i<9; i++)
		Mas2[i]=13;
pKlientSok->Send(Mas2,sizeof(Mas2));

GAME_VID_IGRI=SOK_KLIENT;// вид игры клиент
GAME_SOST=GAME_XOD_SERVERA;// первый ход сервера
XOD=0;//первый ход сервера
}

void CMainFrame::OnUpdateServer(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if((GAME_VID_IGRI==SOK_KLIENT)|(GAME_VID_IGRI==SOK_SERVER))
		pCmdUI->Enable(0);//выключить
}

void CMainFrame::OnUpdateKlient(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if((GAME_VID_IGRI==SOK_KLIENT)|(GAME_VID_IGRI==SOK_SERVER))
		pCmdUI->Enable(0);//выключить
}



void CMainFrame::OnVirubitSet()
{
	// TODO: Add your command handler code here
	if(GAME_VID_IGRI==SOK_SERVER){
		for(int i=0;i<9; i++)
			Mas2[i]=14;
		if(pServSok->pKlientSock)
			pServSok->pKlientSock->Send(Mas2,sizeof(Mas2));
		if(pServSok)
			delete pServSok;
		pServSok=0;}
	if(GAME_VID_IGRI==SOK_KLIENT){
		//for(int i=0;i<9; i++)
		/*	Mas2[i]=14;
		pKlientSok->Send(Mas2,sizeof(Mas2));*/
			if(pKlientSok)
		delete pKlientSok;
		pKlientSok=0;}

		GAME_VID_IGRI=SOK_NET;
		GAME_SOST=GAME_FINISH;
		OnNovayaIgra();
}

void CMainFrame::OnUpdateVirubitSet(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
		if(GAME_VID_IGRI==SOK_NET)
		pCmdUI->Enable(0);//выключить
}

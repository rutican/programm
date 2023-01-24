#include "kozelview.h"
// KozelView.cpp : implementation of the CKozelView class
//

#include "stdafx.h"
#include "Kozel.h"
#include "Karta.h"

#include <MMSYSTEM.H>//


#include "KozelDoc.h"
#include "OblogkiDLG.h"

#include "KozelView.h"
#include <time.h>


//#ifdef RAND_MAX
//#define RAND_MAX 36
//#endif


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

 
// CKozelView

IMPLEMENT_DYNCREATE(CKozelView, CView)

BEGIN_MESSAGE_MAP(CKozelView, CView)

	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
ON_COMMAND(ID_SXODIT, OnSxodit)
ON_UPDATE_COMMAND_UI(ID_SXODIT, OnUpdateSxodit)
ON_COMMAND(ID_COMP_BIET, OnCompBiet)
ON_COMMAND(ID_RAZDAT, OnRazdat)
ON_COMMAND(ID_COMP_XODIT, OnCompXodit)
ON_COMMAND(ID_UBRAT, OnUbrat)
ON_COMMAND(ID_COMP_SKIDIVAET, OnCompSkidivaet)
ON_UPDATE_COMMAND_UI(ID_COMP_SKIDIVAET, OnUpdateCompSkidivaet)
ON_UPDATE_COMMAND_UI(ID_COMP_BIET, OnUpdateCompBiet)
ON_UPDATE_COMMAND_UI(ID_RAZDAT, OnUpdateRazdat)
ON_UPDATE_COMMAND_UI(ID_COMP_XODIT, OnUpdateCompXodit)
ON_COMMAND(ID_UDARIT, OnUdarit)
ON_UPDATE_COMMAND_UI(ID_UDARIT, OnUpdateUdarit)
ON_COMMAND(ID_SBROSIT, OnSbrosit)
ON_UPDATE_COMMAND_UI(ID_SBROSIT, OnUpdateSbrosit)
ON_UPDATE_COMMAND_UI(ID_UBRAT, OnUpdateUbrat)
ON_WM_TIMER()

ON_COMMAND(ID_OBLOGKI, OnOblogki)
ON_COMMAND(ID_GAME_SPID_1, OnGameSpid1)
ON_UPDATE_COMMAND_UI(ID_GAME_SPID_1, OnUpdateGameSpid1)
ON_COMMAND(ID_GAME_SPID_2, OnGameSpid2)
ON_UPDATE_COMMAND_UI(ID_GAME_SPID_2, OnUpdateGameSpid2)
ON_COMMAND(ID_GAME_SPID_3, OnGameSpid3)
ON_UPDATE_COMMAND_UI(ID_GAME_SPID_3, OnUpdateGameSpid3)
ON_COMMAND(ID_GAME_SPID_4, OnGameSpid4)
ON_UPDATE_COMMAND_UI(ID_GAME_SPID_4, OnUpdateGameSpid4)
ON_WM_PAINT()
ON_COMMAND(ID_AVTOPILOT, OnAvtopilot)
ON_UPDATE_COMMAND_UI(ID_AVTOPILOT, OnUpdateAvtopilot)
ON_COMMAND(ID_172, On172)
ON_UPDATE_COMMAND_UI(ID_172, OnUpdate172)
ON_COMMAND(ID_MUZIK, OnMuzik)
ON_UPDATE_COMMAND_UI(ID_MUZIK, OnUpdateMuzik)
END_MESSAGE_MAP()

// CKozelView construction/destruction

CKozelView::CKozelView()
{
	// TODO: add construction code here
	//==========Создаю имиджи
bmBlac.LoadBitmap(IDB_BITMAP1);//обложки
bmRed.LoadBitmap(IDB_BITMAP2);//Black
bmOblogki.LoadBitmap(IDB_BITMAP3);//red
bmMast.LoadBitmap(IDB_BITMAP4);//масти


	m_ImBlac.Create(71,96,TRUE,1,1);
	m_ImBlac.Add(&bmBlac,RGB(0,128,0));
	
	m_ImRed.Create(71,96,TRUE,1,1);
	m_ImRed.Add(&bmRed,RGB(0,128,0));
	
	m_ImOblogki.Create(71,96,TRUE,1,1);
	m_ImOblogki.Add(&bmOblogki,RGB(0,128,0));

	m_ImMast.Create(24,22,TRUE,1,1);
	m_ImMast.Add(&bmMast,RGB(0,128,0));

	//=================

	/*bmZvetok.LoadBitmap((IDB_BITMAP6));
	m_ImZvetok.Create(47,47,TRUE,1,1);
	m_ImZvetok.Add(&bmZvetok,RGB(0,128,0));*/

	//======
	pDCm=new CDC;
	m_pBitmap= new CBitmap;

	//-------
	Musik=TRUE;
}

CKozelView::~CKozelView()
{
	delete pDCm;
	delete m_pBitmap;
}

BOOL CKozelView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

LOGBRUSH lb;
	lb.lbColor=RGB(0,128,0);
	lb.lbHatch=0;
	lb.lbStyle=BS_SOLID;
//cs.
	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(  CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW),CreateBrushIndirect(&lb), NULL);//::LoadIcon(NULL,"IDR_MAINFRAME"));
	


	return CView::PreCreateWindow(cs);
}

// CKozelView drawing

void CKozelView::OnDraw(CDC*pDC)
{
	CKozelDoc* pDoc=GetDocument();

//================вывожу нужные данные
//int i=pDoc->m_KartiCompa.GetCount();
//TCHAR stri[30];
//wsprintf(stri,"Кол-во карт компа= %d",i);
//pDC->TextOut(0,0,stri);
////-----------------------
//int j=pDoc->m_KartiIgroka.GetCount();
//TCHAR strj[30];
//wsprintf(strj,"Кол-во карт игрока= %d",j);
//pDC->TextOut(0,300,strj);
////---------------------------
//int k=pDoc->m_Koloda.GetCount();
//TCHAR strk[30];
//wsprintf(strk,"Кол-во карт в колоде= %d",k);
//pDC->TextOut(0,250,strk);
////---------------------------------------------
//int f=pDoc->m_VzjatkaCompa.GetCount();
//TCHAR strf[30];
//wsprintf(strf,"Кол-во взятка компа= %d",f);
//pDC->TextOut(0,25,strf);
////---------------------------------------------
//int w=pDoc->m_VzjatkaIgroka.GetCount();
//TCHAR strw[30];
//wsprintf(strw,"Кол-во, взятка игрока= %d",w);
//pDC->TextOut(0,275,strw);
////----------------------------состояние игры
//TCHAR strG[30];
//wsprintf(strG,"Состояние игры = %d",pDoc->GAME_STATE);
//pDC->TextOut(250,5,strG);
////================статистика
//CHAR strz[30];
//wsprintf(strz,"Кол-во игр= %d",pDoc->m_nKolSigranIgr);
//pDC->TextOut(510,180,strz);
////-----------------------
//CHAR str2[30];
//wsprintf(str2, "Кол-во побед=%d",pDoc->m_nSkolkoViigralIgrok);
//pDC->TextOut(510,210,str2);
////+___________------------------
//CHAR str3[30];
//wsprintf(str3, "Кол-во партий=%d",pDoc-> m_nKolPartii);
//pDC->TextOut(510,240,str3);
////-----------------------
//CHAR str4[30];
//wsprintf(str4,"Счет игры=%d : %d",pDoc->m_nShtrafOchkiIgroka,pDoc->m_nShtrafOchkiCompa);
//pDC->TextOut(510,270,str4);

////===========


////================

}


// CKozelView diagnostics

#ifdef _DEBUG
void CKozelView::AssertValid() const
{
	CView::AssertValid();
}

void CKozelView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKozelDoc* CKozelView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKozelDoc)));
	return (CKozelDoc*)m_pDocument;
}
#endif //_DEBUG


// CKozelView message handlers

//void CKozelView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
//{
//	// TODO: Add your specialized code here and/or call the base class
//return;
//}

void CKozelView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
CKozelDoc* pDoc=GetDocument();
	// TODO: Add your specialized code here and/or call the base class


//Создаю контекст в памяти
if(pDCm->GetSafeHdc()==0)
{
CClientDC dc(this);
CRect rect;
GetClientRect(&rect);

//dc.LPtoDP(rect);
pDCm->CreateCompatibleDC(&dc);
m_pBitmap->CreateCompatibleBitmap(&dc,rect.right, rect.bottom);
}

	SetTimer(1,pDoc->m_nSkorost_Igri, 0);
	//InvalidateRect(NULL);
}

void CKozelView::RisovatKolodu(CDC *pDC)
{
	CKozelDoc* pDoc=GetDocument();
	double x=25;
	double y=160;
	if(GetDocument()->m_Koloda.GetCount()>0)
	{
		for(int i=0; i<pDoc->m_Koloda.GetCount(); i++)
		{
			m_ImOblogki.Draw(pDC,pDoc->NomerOblogki,CPoint(x,y) ,ILD_NORMAL);
			x+=0.5;
			y-=0.5;
		}//for
	}

}

void CKozelView::RisovatKarti(CDC* pDC,CKartaList* pKartiIgrILICompa)
{
	
	POSITION position;
	CKozelDoc* pDoc = GetDocument();
	CKarta* pKarta;
	int m_nNomZagrIm=0;
	CImageList* pImList;
	
position=pKartiIgrILICompa->GetHeadPosition();

if(pKartiIgrILICompa->GetCount()>0)
{
	for(int i=0; i<pKartiIgrILICompa->GetCount(); i++)
	{

	pKarta=pKartiIgrILICompa->GetNext(position);

		if( (pKarta->m_nZnachenie<10))
		{m_nNomZagrIm=pKarta->m_nZnachenie-1;pImList=&m_ImRed;}
		else if( (pKarta->m_nZnachenie>10)&  (pKarta->m_nZnachenie<20))
		{m_nNomZagrIm=pKarta->m_nZnachenie-2;pImList=&m_ImRed;}
		else if( (pKarta->m_nZnachenie>20)&  (pKarta->m_nZnachenie<30))
		{m_nNomZagrIm=pKarta->m_nZnachenie-21;pImList=&m_ImBlac;}
		else if( (pKarta->m_nZnachenie>30)&  (pKarta->m_nZnachenie<40))
		{m_nNomZagrIm=pKarta->m_nZnachenie-22;pImList=&m_ImBlac;}
//===проверим что рисовать обложку или карту
		if(pKarta->m_bPokaziv==TRUE)
		{
	pImList->Draw(pDC,m_nNomZagrIm,pKarta->m_ptPologKarti ,ILD_NORMAL);
		}//if
		else if(pKarta->m_bPokaziv==FALSE)
		{
		m_ImOblogki.Draw(pDC,pDoc->NomerOblogki,pKarta->m_ptPologKarti ,ILD_NORMAL);
		}
	}//for
}//if

}




void CKozelView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default



//////////////////////////////////////////////
CKarta* pKarta,pKarta2;
CKozelDoc* pDoc=GetDocument();
CRect rect(150,248,505,376);
CRect rect2;
POSITION position;
POSITION position2;
//int i = 0;

position=pDoc->m_KartiIgroka.GetHeadPosition();
position2=position;
 int VibranMast=0;//0- ничего 1-бубы 2-черви 3-пики 4-крести.

if (pDoc->GAME_STATE==IGROK_XODIT)
{	


 {

if(rect.PtInRect(point))
{
	//=====выдвигать только карты одной масти, нахожу масть
	   for(int i=0; i <pDoc->m_KartiIgroka.GetCount(); i++)
	   {
		   	pKarta=pDoc->m_KartiIgroka.GetNext(position2);
			  if (pKarta->m_ptPologKarti.y==248)
			  {
				if(pKarta->m_nZnachenie<10)	
					VibranMast=1;
				if((pKarta->m_nZnachenie>10) & (pKarta->							m_nZnachenie<20))	
					VibranMast=2;
				if((pKarta->m_nZnachenie>20) & (pKarta->							m_nZnachenie<30))	
					VibranMast=3;
				if((pKarta->m_nZnachenie>30) & (pKarta->							m_nZnachenie<40))	
					VibranMast=4;
			  }//if

	   }//for
//======================
//Перебираю все карты игрока и выдвигаю удовл. условиям	
	   int i;
for( i=0; i <pDoc->m_KartiIgroka.GetCount(); i++)
{
	pKarta=pDoc->m_KartiIgroka.GetNext(position);

	rect2=CRect(pKarta->m_ptPologKarti.x,pKarta->m_ptPologKarti.y,	pKarta->m_ptPologKarti.x+71,pKarta->m_ptPologKarti.y+96);
	
	if(((rect2.PtInRect(point))& (pKarta->m_ptPologKarti.y==280)&		(VibranMast==0))|
	   	((rect2.PtInRect(point))& (pKarta->m_ptPologKarti.y==280)&		(VibranMast==pKarta->m_nMast)))
	//выдвинуть карту
	{	
		pKarta->m_ptPologKarti.y-=32;
		InvalidateRect(CRect(pKarta->m_ptPologKarti.x,pKarta->			m_ptPologKarti.y, pKarta->m_ptPologKarti.x+71,pKarta->			m_ptPologKarti.y+128),0);
	}//if
	
}//for
}//if(rect.PtInRect(point))

 }//if

 //else //ответ игрока на ход компа
 {
	// if(rect.PtInRect(point))
	//{
	//	
	////Перебираю все карты игрока и выдвигаю удовл. условиям	  
	//	for(int i=0; i <pDoc->m_KartiIgroka.GetCount(); i++)
	//	{
	//		pKarta=pDoc->m_KartiIgroka.GetNext(position);

	//		rect2=CRect(pKarta->m_ptPologKarti.x,pKarta->					m_ptPologKarti.y, pKarta->m_ptPologKarti.x+71,pKarta->			m_ptPologKarti.y+96);
	//		
	//			if(((rect2.PtInRect(point))& (pKarta->								m_ptPologKarti.y==280)))
	//			//выдвинуть карту
	//			{	
	//				pKarta->m_ptPologKarti.y-=32;
	//				InvalidateRect(CRect(pKarta->m_ptPologKarti.x,					pKarta->m_ptPologKarti.y, pKarta->								m_ptPologKarti.x+71,pKarta->m_ptPologKarti.y+					128));
	//			}//if
	//			else if((rect2.PtInRect(point))& (pKarta->							m_ptPologKarti.y==248))
	//			//вернуть карту обратно
	//			{
	//				pKarta->m_ptPologKarti.y+=32;
	//				InvalidateRect(CRect(pKarta->m_ptPologKarti.x,					pKarta->m_ptPologKarti.y-32, pKarta->							m_ptPologKarti.x+71,pKarta->m_ptPologKarti.y+						128));
	//			}//else if

	//	}//for
	//}//if(rect.PtInRect(point))

 }//else

}//if pDoc->GAME_STATE==IGROK_XODIT
else if(pDoc->GAME_STATE==IGROK_OTVETCHAET)
{
 if(rect.PtInRect(point))
	{
		
	//Перебираю все карты игрока и выдвигаю удовл. условиям	  
		for(int i=0; i <pDoc->m_KartiIgroka.GetCount(); i++)
		{
			pKarta=pDoc->m_KartiIgroka.GetNext(position);

			rect2=CRect(pKarta->m_ptPologKarti.x,pKarta->					m_ptPologKarti.y, pKarta->m_ptPologKarti.x+71,pKarta->			m_ptPologKarti.y+96);
			
				if(((rect2.PtInRect(point))& (pKarta->								m_ptPologKarti.y==280)))
				//выдвинуть карту
				{	
					pKarta->m_ptPologKarti.y-=32;
					InvalidateRect(CRect(pKarta->m_ptPologKarti.x,					pKarta->m_ptPologKarti.y, pKarta->								m_ptPologKarti.x+71,pKarta->m_ptPologKarti.y+					128),0);
				}//if
				else if((rect2.PtInRect(point))& (pKarta->							m_ptPologKarti.y==248))
				//вернуть карту обратно
				{
					pKarta->m_ptPologKarti.y+=32;
					InvalidateRect(CRect(pKarta->m_ptPologKarti.x,					pKarta->m_ptPologKarti.y-32, pKarta->							m_ptPologKarti.x+71,pKarta->m_ptPologKarti.y+						128),0);
				}//else if

		}//for
	}//if(rect.PtInRect(point)

}//if(pDoc->GAME_STATE==IGROK_OTVETCHAET)

	CView::OnLButtonDown(nFlags, point);
}

void CKozelView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	
CKarta* pKarta;
CKozelDoc* pDoc=GetDocument();
//CRect rect(150,248,505,376);
CRect rect2;
POSITION position;


if (pDoc->m_bCheiXod==FALSE)
	return;
//
position=pDoc->m_KartiIgroka.GetHeadPosition();

////======================
////Перебираю все карты игрока и задвигаю удовл. условиям	  
for(int i=0; i <pDoc->m_KartiIgroka.GetCount(); i++)
{
	pKarta=pDoc->m_KartiIgroka.GetNext(position);

	rect2=CRect(pKarta->m_ptPologKarti.x,pKarta->m_ptPologKarti.y,	pKarta->m_ptPologKarti.x+71,pKarta->m_ptPologKarti.y+96);


	if((rect2.PtInRect(point))& (pKarta->m_ptPologKarti.y==248))
				//вернуть карту обратно
				{
					pKarta->m_ptPologKarti.y+=32;
					InvalidateRect(CRect(pKarta->m_ptPologKarti.x,			pKarta->m_ptPologKarti.y-32, pKarta->m_ptPologKarti.x+			71,pKarta->m_ptPologKarti.y+128),0);

				}//if

}//for i
	


	CView::OnRButtonDown(nFlags, point);
}







void CKozelView::OnSxodit()
{

	CKarta* pKarta;
CKozelDoc* pDoc=GetDocument();
CRect rect(150,248,505,376);//квадрат карт игрока
CRect rect2;//квадрат карты на котор щелкнули мышью
POSITION position;
position=pDoc->m_KartiIgroka.GetHeadPosition();
{
	for(int i=0; i <pDoc->m_KartiIgroka.GetCount(); i++)
	{
		pKarta=pDoc->m_KartiIgroka.GetNext(position);

		rect2=CRect(pKarta->m_ptPologKarti.x,pKarta->m_ptPologKarti.y, pKarta->m_ptPologKarti.x+71,pKarta->m_ptPologKarti.y+96);

		if (pKarta->m_ptPologKarti.y==248)
		{//выдвигаю карту у=184
			pKarta->m_ptPologKarti.y-=64;
			InvalidateRect(CRect(pKarta->m_ptPologKarti.x,pKarta->m_ptPologKarti.y, pKarta->m_ptPologKarti.x+71,pKarta->m_ptPologKarti.y+160),0);
		   pDoc->GAME_STATE=COMP_OTVETCHAET;//игрок сходил!!
		}
	}
}
	// TODO: Add your command handler code here
InvalidateRect(CRect(150,184,506,380),0);
InvalidateRect(CRect(60,315,130,340),0);
InvalidateRect(CRect(20,65,150,95),0);//надпись
}

void CKozelView::OnUpdateSxodit(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	
CKarta* pKarta;
CKozelDoc* pDoc=GetDocument();
POSITION position;
BOOL m_bUpdade=0;

position=pDoc->m_KartiIgroka.GetHeadPosition();
//==============ищу выдвинутые карты
int j=(int)pDoc->m_KartiIgroka.GetCount();
	for(int i=0; i <j; i++)
	{
		pKarta=pDoc->m_KartiIgroka.GetNext(position);
		int m=pKarta->m_nZnachenie;
		if(pKarta->m_ptPologKarti.y==248)
		{		
		m_bUpdade=TRUE;//хоть одна карта выдвинута
		break;
		}//if
	}//for
	
pCmdUI->Enable(( pDoc->GAME_STATE==IGROK_XODIT) & m_bUpdade);

}

void CKozelView::OnCompBiet()
{
	// TODO: Add your command handler code here
CKarta* pKarta_Comp;
CKarta* pKarta_Igrok;
CKarta* pKarta_Comp_Dlya_Bitiya;

CKarta* Karta[5]={0,0,0,0,0};
CKarta* MasKartKotCompBIET[5]={0,0,0,0,0};

POSITION position_Comp;
POSITION position_Comp2;
POSITION position_Igrok;
POSITION position_Igrok2;
int KolKartKotSxodIgrok=0;
int KolKartKotSxodComp=0;
int k=0;

CKozelDoc* pDoc=GetDocument();

pDoc->m_bComp_Biet_Skidivaet=FALSE;//изначально комп всегда бьет

position_Comp=pDoc->m_KartiCompa.GetHeadPosition();
position_Igrok=pDoc->m_KartiIgroka.GetHeadPosition();

 position_Comp2= position_Comp;
 position_Igrok2= position_Igrok;
BOOL m_bMoguUdarit=FALSE;//1-комп бьет карту
//==============

int j=(int)pDoc->m_KartiCompa.GetCount();

	for(int i=0; i <j; i++)//прохожу по всем картам игрока
	{
		pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
	
	//==проверяю выдвинута(сходил ей)карта игрока
	if(pKarta_Igrok->m_ptPologKarti.y==184)
	{
		m_bMoguUdarit=FALSE;
		position_Comp= position_Comp2;//Когда начинается нов цикл п								  озиция должна быть опять первой!
		k=0;
		for( int m=0; m <j; m++)//перебираю карты компа 
		{//ищу не козырные
			pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
			
	 //нахожу все карты, которыми можно бить эту карту игрока	
			if(((pKarta_Comp->m_nZnachenie)>(pKarta_Igrok->						m_nZnachenie)) & ((pKarta_Comp->m_nMast)==						(pKarta_Igrok->m_nMast))& (pKarta_Comp->								m_nSOSTOYANIE_KARTI==0))
			{
					Karta[k]=pKarta_Comp;
				k++;
				m_bMoguUdarit=TRUE;
			}//if
		}//for

		//-----------------бью козырем если не сммог так ударить
		if(!m_bMoguUdarit)
		{
		position_Comp= position_Comp2;//Когда начинается нов цикл п								  озиция должна быть опять первой!
		k=0;
		for( int d=0; d <j; d++)//перебираю карты компа
		{
			pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
			
			{
			if(((pKarta_Comp->m_nMast)==(pDoc->m_nKozir))&
				(pKarta_Comp->m_nSOSTOYANIE_KARTI==0)&
				(pKarta_Igrok->m_nMast!=pDoc->m_nKozir))
			{
					Karta[k]=pKarta_Comp;
				k++;
				m_bMoguUdarit=TRUE;
			}//if
			else if(((pKarta_Comp->m_nMast)==(pDoc->m_nKozir))&
				(pKarta_Comp->m_nSOSTOYANIE_KARTI==0)&
				(pKarta_Igrok->m_nMast==pDoc->m_nKozir)&
				(pKarta_Comp->m_nZnachenie > 
				pKarta_Igrok->m_nZnachenie))
			{
				Karta[k]=pKarta_Comp;
				k++;
				m_bMoguUdarit=TRUE;
			}//else if
				
			}//if
		}//for

		}//if
			
		//--------------Комп не может побить карту ------------
		if(!m_bMoguUdarit)
		{
		//===========возвращаю карты назад
		position_Comp= position_Comp2;//Когда начинается нов цикл п								  озиция должна быть опять первой!
			for(int d=0; d <j; d++)//перебираю карты компа
			{
	    		pKarta_Comp=
					pDoc->m_KartiCompa.GetNext(position_Comp);
				pKarta_Comp->m_nSOSTOYANIE_KARTI=0;
			}//for
			//==========================
			pDoc->m_bComp_Biet_Skidivaet=TRUE;
			//pDoc->GAME_STATE=COMP_SBRASIVAET;//Надо скинуть игроку
			return ; //возврат, комп должен скидывать
		}//if

//=======выбрать наименьшую карту для битья карты игрока
		pKarta_Comp_Dlya_Bitiya=Karta[0];	
		Karta[0]=0;
		for(int l=1; l<5; l++)
		{
		pKarta_Comp=Karta[l];
		Karta[l]=0;
			if((pKarta_Comp!=0))
			{
				if((pKarta_Comp_Dlya_Bitiya->m_nZnachenie >							pKarta_Comp->m_nZnachenie) & 
					(pKarta_Comp->m_ptPologKarti.y==0))
					{
						pKarta_Comp_Dlya_Bitiya=pKarta_Comp;
					}//if
			}//if
		}//for
	
	//==================================
		//если есть такая карта, то выдвигаем ее
	if(pKarta_Comp_Dlya_Bitiya!=0)
	{//помечаю эту карту
			pKarta_Comp_Dlya_Bitiya->m_nSOSTOYANIE_KARTI=
			pKarta_Igrok->m_nZnachenie;

	}//if

	}//if

   }//for

//=========выдвигаю карты
   position_Igrok= position_Igrok2;
   int i;
   for( i=0; i <j; i++)//прохожу по всем картам игрока
	{
		pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
	
	//==проверяю выдвинута(сходил ей)карта игрока
	
		position_Comp= position_Comp2;//Когда начинается нов цикл п								  озиция должна быть опять первой!
		for(int  m=0; m <j; m++)//перебираю карты компа
		{
			pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
			if(pKarta_Comp->m_nSOSTOYANIE_KARTI==
				pKarta_Igrok->m_nZnachenie)
			{
				//int f=pKarta_Comp->m_nZnachenie;
			
				pKarta_Comp->m_ptPologKarti.x
					=pKarta_Igrok->m_ptPologKarti.x;

				pKarta_Comp->m_ptPologKarti.y=126;
				pKarta_Comp->m_bPokaziv=TRUE;
				pKarta_Comp->m_nSOSTOYANIE_KARTI=0;
			}//if


		}//for

	
	}//for

//===================================
	pDoc->GAME_STATE=COMP_UBIRAET_KARTI;
InvalidateRect(CRect(150,30,506,227),0);
InvalidateRect(CRect(20,65,150,95),0);//надпись
}

void CKozelView::PokazatKozir(CDC* pDC)
{
	CKozelDoc* pDoc=GetDocument();
m_ImMast.Draw(pDC,(pDoc->m_nKozir-1),CPoint(50,123),ILD_NORMAL);
m_ImMast.Draw(pDC,(pDoc->m_nKozir-1),CPoint(50,255),ILD_NORMAL);
m_ImMast.Draw(pDC,(pDoc->m_nKozir-1),CPoint(0,190),ILD_NORMAL);
m_ImMast.Draw(pDC,(pDoc->m_nKozir-1),CPoint(108,190),ILD_NORMAL);


}

void CKozelView::OnRazdat()
{
	// TODO: Add your command handler code here
CKozelDoc* pDoc=GetDocument();

	pDoc->RasdatKarti();
//========установить чей ход
	//if(pDoc->m_bCheiXod==IGROK_XODIT)
	//{
	//	pDoc->GAME_STATE=COMP_XODIT;
	//	pDoc->m_bCheiXod=COMP_XODIT;
	//}

	// else if(pDoc->m_bCheiXod==COMP_XODIT)
	//{
	//	pDoc->GAME_STATE=IGROK_XODIT;
	//	pDoc->m_bCheiXod=IGROK_XODIT;
	//}//if

	InvalidateRect(CRect(0,0,506,380),0);
}

void CKozelView::OnCompXodit()
{
	// TODO: Add your command handler code here

//CompXodit2();
//	return;

	CKozelDoc* pDoc=GetDocument();

CKarta* pKarta_Comp;

int MasKolMASTEI[4]={0,0,0,0};

POSITION position_Comp;
POSITION position_Comp2;

int MastDlyaXoda=0;

position_Comp=pDoc->m_KartiCompa.GetHeadPosition();
position_Comp2=position_Comp;

//========опред. сколько каких мастей имеется
int j=(int)pDoc->m_KartiCompa.GetCount();

for(int i=0; i<j; i++)
{
	pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);

	switch(pKarta_Comp->m_nMast)
	{
		case 1:
			MasKolMASTEI[0]++;
			break;
		case 2:
			MasKolMASTEI[1]++;
			break;
		case 3:
			MasKolMASTEI[2]++;
			break;
		case 4:
			MasKolMASTEI[3]++;
			break;
	}

}//for
int p=0;
switch(pDoc->m_nKozir)
{
	case 1:
		p=1;
		break;
	case 2:
		p=2;
		break;
	case 3:
		p=3;
		break;
	case 4:
		p=0;
		break;
}//switch

int max=MasKolMASTEI[p];//какой масти больше
int i;
for(i=0; i<4; i++)
{
	if( (max <= MasKolMASTEI[i]) &( (i+1)!=pDoc->m_nKozir) &
		(MasKolMASTEI[i]!=0))
	{//
		MastDlyaXoda=(i+1);
		max=MasKolMASTEI[i];
	}//if
	else if(( MasKolMASTEI[i])==j)//все карты козыри
	{
	MastDlyaXoda=pDoc->m_nKozir;
	}//else if
	else if((MasKolMASTEI[i] > max ) & (j==1))
	{
		MastDlyaXoda=(i+1);
	}//else if
	
}//for

//=======Cам ход
position_Comp=position_Comp2;

//========опред. сколько каких мастей имеется

int SkolkoKartSxodilo=0;
int k=(int)pDoc->m_KartiCompa.GetCount();

for( i=0; i<k; i++)
{
	pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
	if(pKarta_Comp->m_nMast==MastDlyaXoda)
	{
		SkolkoKartSxodilo++;
		pKarta_Comp->m_ptPologKarti.y=126;
		pKarta_Comp->m_bPokaziv=TRUE;
	}//if

}//for

//ASSERT(MastDlyaXoda!=0);
//ASSERT(SkolkoKartSxodilo!=0);

pDoc->GAME_STATE=IGROK_OTVETCHAET;//!!!!!!!!!!!

InvalidateRect(CRect(150,30,506,227),0);
InvalidateRect(CRect(60,315,130,340),0);
InvalidateRect(CRect(20,65,150,95),0);//надпись

}//OnCompXodit

void CKozelView::OnUbrat()
{
	CKozelDoc* pDoc=GetDocument();
POSITION position_Compa;
POSITION position_Igroka;

POSITION Pred_position_Compa;
POSITION Pred_position_Igroka;

CKarta* pKarta_Compa;
CKarta* pKarta_Igroka;

 int CompVzyalKart=(int)pDoc->m_VzjatkaCompa.GetCount();
 int IgrokVzyalKart=(int)pDoc->m_VzjatkaIgroka.GetCount();
/////=============делаю задержку т.к. нихрена не вижу чем бьют и что ски//дывают
//DWORD start_t=GetTickCount();
//
//while((GetTickCount()-start_t)<10000);
/////====================
//== проверка суммы карт  во взятках игроков
//ASSERT((pDoc->m_VzjatkaCompa.GetCount()+
		//pDoc->m_VzjatkaIgroka.GetCount()+pDoc->m_Koloda.GetCount())<=36);

//=========
int j=(int)pDoc->m_KartiCompa.GetCount();
 
position_Compa=pDoc->m_KartiCompa.GetHeadPosition();
position_Igroka=pDoc->m_KartiIgroka.GetHeadPosition();

//==удаляю карты у игроков передаю в биты
if((pDoc->GAME_STATE==COMP_UBIRAET_KARTI)|
   (pDoc->GAME_STATE==IGROK_SBRASIVAET))
{
	for(int i=0; i<j; i++)
	{
		//сохраняю предыд позиции для удаления
		Pred_position_Compa=position_Compa;
		Pred_position_Igroka=position_Igroka;

		pKarta_Compa=pDoc->m_KartiCompa.GetNext(position_Compa);
		if((pKarta_Compa->m_ptPologKarti.y==126)&(pKarta_Compa!=0))
		{
			pDoc->m_VzjatkaCompa.AddHead(pKarta_Compa);
			pDoc->m_KartiCompa.RemoveAt(Pred_position_Compa);
		}//if

		pKarta_Igroka=pDoc->m_KartiIgroka.GetNext(position_Igroka);
	if((pKarta_Igroka->m_ptPologKarti.y==184)&(pKarta_Igroka!=0))
		{
			pDoc->m_VzjatkaCompa.AddHead(pKarta_Igroka);
			pDoc->m_KartiIgroka.RemoveAt(Pred_position_Igroka);
		}
	}//for

	//проверка на окончание партии
	

	if((pDoc->m_VzjatkaCompa.GetCount()+
		pDoc->m_VzjatkaIgroka.GetCount())==36)
	{
		pDoc->GAME_STATE=PODSCHET_OCHKOV;
	}
	else
	{	
		pDoc->GAME_STATE=COMP_XODIT;//после того как комп 
	}						//ударил его ход
}//if(pDoc->GAME_STATE==COMP_UBIRAET_KARTI)	

else if((pDoc->GAME_STATE==IGROC_UBIRAET_KARTI)|
		(pDoc->GAME_STATE==COMP_SBRASIVAET))
{
for(int i=0; i<j; i++)
	{
		//сохраняю предыд позиции для удаления
		Pred_position_Compa=position_Compa;
		Pred_position_Igroka=position_Igroka;

		pKarta_Compa=pDoc->m_KartiCompa.GetNext(position_Compa);
		if((pKarta_Compa->m_ptPologKarti.y==126)&(pKarta_Compa!=0))
		{
			pDoc->m_VzjatkaIgroka.AddHead(pKarta_Compa);
			pDoc->m_KartiCompa.RemoveAt(Pred_position_Compa);
		}//if

		pKarta_Igroka=pDoc->m_KartiIgroka.GetNext(position_Igroka);
	if((pKarta_Igroka->m_ptPologKarti.y==184)&(pKarta_Igroka!=0))
		{
			pDoc->m_VzjatkaIgroka.AddHead(pKarta_Igroka);
			pDoc->m_KartiIgroka.RemoveAt(Pred_position_Igroka);
		}
	}//for
//=========кончились карты???
	if((pDoc->m_VzjatkaCompa.GetCount()+
		pDoc->m_VzjatkaIgroka.GetCount())==36)
	{
		pDoc->GAME_STATE=PODSCHET_OCHKOV;
	}
	else
	{
		pDoc->GAME_STATE=IGROK_XODIT;//после того как игрок
	}							//ударил его ход
}//else if(pDoc->GAME_STATE==IGROC_UBIRAET_KARTI)

InvalidateRect(NULL,0);

}

void CKozelView::OnCompSkidivaet()
{
	// TODO: Add your command handler code here
POSITION position_Comp;
POSITION position_Comp2;
POSITION position_Comp3;
POSITION position_Igrok;

CKozelDoc* pDoc=GetDocument();

CKarta* pKarta_Comp;
CKarta* pKarta_Igrok;
//CKarta* pKarta_Comp_Dlya_Skidivaniya;

CKarta* Karta[5]={0,0,0,0,0};

position_Igrok=pDoc->m_KartiIgroka.GetHeadPosition();
position_Comp=pDoc->m_KartiCompa.GetHeadPosition();
position_Comp2=position_Comp;
position_Comp3=position_Comp;

int MastIgroka=0; // масть карт с которых пошел игрок
int SkolkoSkidivat=0;
int Itog=0;
//ASSERT(pDoc->m_KartiIgroka.GetCount());//у игроков должны быть карт
//===для начала вычислим сколько карт скидывать

for(int i=0; i<pDoc->m_KartiIgroka.GetCount(); i++)
{
	 pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
		if(pKarta_Igrok->m_ptPologKarti.y==184)
		{
			SkolkoSkidivat++;
			MastIgroka=pKarta_Igrok->m_nMast;
		}//if
}//for
//========================
//=========ищем, что не жалко скинуть
//пока без козырей

int zn1=0;
int zn2=10;
int zn3=20;
int zn4=30;

while((zn1<9)|(Itog==SkolkoSkidivat))
{				
	zn1++;
	zn2++;
	zn3++;
	zn4++;
position_Comp=position_Comp2;
int i;
	for(i=0; i<pDoc->m_KartiIgroka.GetCount(); i++)//нахожу подходящую карту
	{
		pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
		if(pKarta_Comp->m_nMast!=pDoc->m_nKozir)
		{
			switch(pKarta_Comp->m_nMast)
			{
				case 1:
					if(pKarta_Comp->m_nZnachenie==zn1)
					{
						pKarta_Comp->m_nSOSTOYANIE_KARTI=1;
						Itog++;
					}//if				
				break;

				case 2:
					if(pKarta_Comp->m_nZnachenie==zn2)
					{
							Itog++;
						pKarta_Comp->m_nSOSTOYANIE_KARTI=1;
					}//if
					
				break;
				case 3:
					if(pKarta_Comp->m_nZnachenie==zn3)
					{
						pKarta_Comp->m_nSOSTOYANIE_KARTI=1;
						Itog++;
					}//if
						
				break;
				case 4:
					if(pKarta_Comp->m_nZnachenie==zn4)
					{
						pKarta_Comp->m_nSOSTOYANIE_KARTI=1;
							Itog++;
					}//if

				break;
			}
			
		}//if
		if((Itog==SkolkoSkidivat))
			break;
	}//for
	
		if((Itog==SkolkoSkidivat))
			break;
}//while
//-----------если не хватает простых скинуть скидыв. козырных
int znKOZ=0;
switch(pDoc->m_nKozir)
{
	case 1:
		znKOZ=0;
	break;
	case 2:
		znKOZ=10;
	break;
	case 3:
		znKOZ=20;
	break;
	case 4:
		znKOZ=30;
	break;
}

if(Itog<SkolkoSkidivat)
{
	
	while((znKOZ<40)|(Itog==SkolkoSkidivat))
	{
			znKOZ++;
		position_Comp=position_Comp2;
		int i=0;
		for(i=0; i<pDoc->m_KartiIgroka.GetCount(); i++)//нахожу под												ходящую карту
		{
			pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
			if((pKarta_Comp->m_nMast==pDoc->m_nKozir)&
				(pKarta_Comp->m_nZnachenie==znKOZ))
				{
					pKarta_Comp->m_nSOSTOYANIE_KARTI=1;
						Itog++;
				}//if
		}
		if((Itog==SkolkoSkidivat))
			break;
	}//while
}//if
	//------------------------------------выдвигаю карту
position_Comp=position_Comp2;
int x1=434;
for(int h=0; h<pDoc->m_KartiIgroka.GetCount(); h++)
{
	pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
	
	
	if(pKarta_Comp->m_nSOSTOYANIE_KARTI==1)
	{
		pKarta_Comp->m_ptPologKarti.y=126;
		pKarta_Comp->m_bPokaziv=FALSE;
	}//if

}//for

//=======================================
//pDoc->GAME_STATE=IGROC_UBIRAET_KARTI;
//проверим корректность
//ASSERT((Itog!=SkolkoSkidivat));
pDoc->GAME_STATE=COMP_SBRASIVAET;//Надо скинуть игроку
InvalidateRect(CRect(150,30,506,227 ),0);
InvalidateRect(CRect(20,65,150,95),0);//надпись

}

void CKozelView::OnUpdateCompSkidivaet(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here]
CKozelDoc* pDoc=GetDocument();
pCmdUI->Enable(pDoc->GAME_STATE==COMP_SBRASIVAET);
}

void CKozelView::OnUpdateCompBiet(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CKozelDoc* pDoc=GetDocument();
pCmdUI->Enable((pDoc->GAME_STATE==COMP_OTVETCHAET));
}

void CKozelView::OnUpdateRazdat(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here

}

void CKozelView::OnUpdateCompXodit(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
CKozelDoc* pDoc=GetDocument();
pCmdUI->Enable((pDoc->GAME_STATE==COMP_XODIT));
}

void CKozelView::OnUdarit()
{
	// TODO: Add your command handler code here

CKozelDoc* pDoc=GetDocument();

CKarta* pKarta_Comp;
CKarta* pKarta_Igrok;
CKarta* pKarta_Igroka_Dlya_Bitiya;

CKarta* Karta[5]={0,0,0,0,0};
BOOL bMoguUdarit=FALSE;

POSITION position_Comp;
POSITION position_Igrok;
POSITION position_Igrok2;

position_Comp=pDoc->m_KartiCompa.GetHeadPosition();
position_Igrok=pDoc->m_KartiIgroka.GetHeadPosition();

position_Igrok2= position_Igrok;
int k=0;
int j=(int)pDoc->m_KartiCompa.GetCount();//кол-во карт компа
//прохожу по всем картам компа, нахожу выдвинутые и для них нахожу
//ударные карты у игрока и ставлю их в нужную позицию.
for(int i=0; i<j; i++)
{
	pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
	k=0;
	position_Igrok= position_Igrok2;
	bMoguUdarit=FALSE;
	if(pKarta_Comp->m_ptPologKarti.y==126)
	{
		//нахожу для этой карты компа карту у игрока
		for(int l=0; l<j; l++)
		{
		  pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
			if((pKarta_Igrok->m_nZnachenie > 
				pKarta_Comp->m_nZnachenie)&
				(pKarta_Igrok->m_nMast==pKarta_Comp->m_nMast)&
				(pKarta_Igrok->m_ptPologKarti.y==248))
			{
					Karta[k]=pKarta_Igrok;
				k++;
				bMoguUdarit=TRUE;
			}//if

		}//for
		//козырные
		if(!bMoguUdarit)
		{
		position_Igrok=position_Igrok2;//Когда начинается нов цикл 								 позиция должна быть опять первой!
		k=0;
		for( int d=0; d <j; d++)//перебираю карты игрока
		{
		pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
			
			if(( !bMoguUdarit & ((pKarta_Igrok->m_nMast)==						(pDoc->m_nKozir))& (pKarta_Igrok->								m_ptPologKarti.y==248)))
			{
					Karta[k]=pKarta_Igrok;
				k++;
				bMoguUdarit=TRUE;
			}//if
		}//for
		}//if
//=======выбрать наименьшую карту для битья карты компа
	pKarta_Igroka_Dlya_Bitiya=Karta[0];	
	Karta[0]=0;
	for(int l=1; l<5; l++)
		{
			pKarta_Igrok=Karta[l];
			Karta[l]=0;
			if((pKarta_Igrok!=0))
			{
				if((pKarta_Igroka_Dlya_Bitiya->m_nZnachenie >							pKarta_Igrok->m_nZnachenie) & 
					(pKarta_Igrok->m_ptPologKarti.y==248))
					{
						pKarta_Igroka_Dlya_Bitiya=pKarta_Igrok;
					}//if
			}//if
		}//for
	
	//==================================
		//если есть такая карта, то выдвигаем ее
	if(pKarta_Igroka_Dlya_Bitiya!=0)
	{
		pKarta_Igroka_Dlya_Bitiya->m_ptPologKarti.x=pKarta_Comp->		m_ptPologKarti.x;
		pKarta_Igroka_Dlya_Bitiya->m_ptPologKarti.y=184;

	}//if

	}//if(pKarta_Comp->m_ptPologKarti.y==126)	

}//for проход по картам компа

pDoc->GAME_STATE=IGROC_UBIRAET_KARTI;//игрок ударил и берет карты!!
InvalidateRect(CRect(150,184,506,380),0);
}

void CKozelView::OnUpdateUdarit(CCmdUI *pCmdUI)
{

	// TODO: Add your command update UI handler code here

//если игрок выдвинул карты и эти карты бьют карты компа

CKarta* pKarta_Comp;
CKarta* pKarta_Igrok;
CKarta* pKarta_Igroka_Dlya_Bitiya;

POSITION position_Comp;
POSITION position_Comp2;
POSITION position_Igrok;
POSITION position_Igrok2;

CKozelDoc* pDoc=GetDocument();

CKarta* Karta[5]={0,0,0,0,0};

position_Comp=pDoc->m_KartiCompa.GetHeadPosition();
position_Igrok=pDoc->m_KartiIgroka.GetHeadPosition();

int j=(int)pDoc->m_KartiCompa.GetCount();//кол-во карт компа

//прохожу по всем картам компа во внешнем цикле
//во внутреннем по картам игрока, нахожу те карты, котор можно бить
//Если хотябы одну карту компа не может бить игрок, То  игрок может только скидывать. Следовательно деактевирую кнопку бить, Кнопка скидывать активирована
int k=0;
position_Igrok2= position_Igrok;
position_Comp2= position_Comp;
BOOL m_bMoguUdarit=FALSE;//1-комп бьет карту

//есть ли выдвинутые карты у игрока ==  они выдвинут у компа
int VidvinComp=0;
int VidvinIgroc=0;

for( int z=0; z <j; z++)//перебираю карты компа
		{
		   pKarta_Igrok=pDoc->m_KartiCompa.GetNext(position_Igrok);
			if(pKarta_Igrok->m_ptPologKarti.y==248)
			{
				VidvinIgroc++;
			}

	  		pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
			if(pKarta_Comp->m_ptPologKarti.y==126)
			{
				VidvinComp++;
			}
		}//for
if(VidvinComp!=VidvinIgroc)
{

	pCmdUI->Enable(FALSE);
	return;
}

//==============
position_Comp=position_Comp2;
for(int i=0; i <j; i++)//прохожу по всем картам компа
{
		pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
	
	//==проверяю выдвинута(сходил ей)карта компа
	if(pKarta_Comp->m_ptPologKarti.y==126)
	{
		m_bMoguUdarit=FALSE;

		position_Igrok= position_Igrok2;//Когда начинается нов цикл								позиция должна быть опять первой!
		k=0;
		for( int m=0; m <j; m++)//перебираю карты компа
		{
		   pKarta_Igrok=pDoc->m_KartiCompa.GetNext(position_Igrok);
			
	 //нахожу все карты, которыми можно бить эту карту игрока	
			if(((pKarta_Igrok->m_nZnachenie)>(pKarta_Comp->						m_nZnachenie)) & ((pKarta_Comp->m_nMast)==						(pKarta_Igrok->m_nMast))& 
				(pKarta_Igrok->m_nSOSTOYANIE_KARTI!=1)&
				(pKarta_Igrok->m_ptPologKarti.y==248))
			{
					Karta[k]=pKarta_Igrok;
				k++;
				m_bMoguUdarit=TRUE;
			}//if

		}//for

		//-----------------бью козырем если не сммог так ударить
		if(!m_bMoguUdarit)
		{
		position_Igrok= position_Igrok2;//Когда начинается нов цикл							позиция должна быть опять первой!
		k=0;
		for( int d=0; d <j; d++)//перебираю карты игрока
		{
		  pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
			
			if ((pKarta_Igrok->m_nMast==pDoc->m_nKozir)& 
				(pKarta_Igrok->m_nSOSTOYANIE_KARTI!=1)&
				(pKarta_Igrok->m_ptPologKarti.y==248)&
				(pKarta_Comp->m_nMast!=pDoc->m_nKozir))
			{
					Karta[k]=pKarta_Igrok;
				k++;
				m_bMoguUdarit=TRUE;
			}//if
			else if((pKarta_Igrok->m_nMast==pDoc->m_nKozir)& 
				(pKarta_Igrok->m_nSOSTOYANIE_KARTI!=1)&
				(pKarta_Igrok->m_ptPologKarti.y==248)&
				(pKarta_Comp->m_nMast==pDoc->m_nKozir)&
				(pKarta_Comp->m_nZnachenie <
				pKarta_Igrok->m_nZnachenie))
			{
					Karta[k]=pKarta_Igrok;
				k++;
				m_bMoguUdarit=TRUE;
			}

		}//for

		}//if
			
		//--------------Комп не может побить карту ------------
		if(!m_bMoguUdarit)
		{
		//pDoc->GAME_STATE=IGROK_SBRASIVAET;//Надо скинуть компу	
		position_Igrok= position_Igrok2;//Когда начинается нов цикл							позиция должна быть опять первой!
		for(int  s=0; s <j; s++)//перебираю карты игрока
		{
		  pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
		pKarta_Igrok->m_nSOSTOYANIE_KARTI=0;

		}

			pCmdUI->Enable(FALSE);
			return; //выходи из цикла, игрок должен скидывать
		}//if

//=======выбрать наименьшую карту для битья карты игрока
	pKarta_Igroka_Dlya_Bitiya=Karta[0];	
	Karta[0]=0;
	for(int l=1; l<5; l++)
		{
		pKarta_Igrok=Karta[l];
		Karta[l]=0;
		if((pKarta_Igrok!=0))
		{
				if((pKarta_Igroka_Dlya_Bitiya->m_nZnachenie >		                    pKarta_Igrok->m_nZnachenie) & 
					(pKarta_Igrok->m_nSOSTOYANIE_KARTI!=1)&
				(pKarta_Igrok->m_ptPologKarti.y==248))
				{
					pKarta_Igroka_Dlya_Bitiya=pKarta_Igrok;
				}//if
		}//if
		}//for

		//=============помечаю карту, чтоб в следущий раз не использовать для битья
		pKarta_Igroka_Dlya_Bitiya->m_nSOSTOYANIE_KARTI=1;
		pDoc->GAME_STATE=IGROK_OTVETCHAET;
//..===============
	}//if

   }//for

		
//===========================

//обнуляю все установки у игрока в картах
position_Igrok= position_Igrok2;//Когда начинается нов цикл							позиция должна быть опять первой!
		for(int  d=0; d <j; d++)//перебираю карты игрока
		{
		  pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
		pKarta_Igrok->m_nSOSTOYANIE_KARTI=0;

		}

//=================================

pCmdUI->Enable((pDoc->GAME_STATE==IGROK_OTVETCHAET));


}

void CKozelView::OnSbrosit()
{
	
	// TODO: Add your command handler code here
	CKarta* pKarta;
CKozelDoc* pDoc=GetDocument();
POSITION position;
position=pDoc->m_KartiIgroka.GetHeadPosition();
{
	for(int i=0; i <pDoc->m_KartiIgroka.GetCount(); i++)
	{
		pKarta=pDoc->m_KartiIgroka.GetNext(position);

		if (pKarta->m_ptPologKarti.y==248)
		{//выдвигаю карту у=184
			pKarta->m_ptPologKarti.y-=64;
			pKarta->m_bPokaziv=FALSE;
			InvalidateRect(CRect(pKarta->m_ptPologKarti.x,pKarta->m_ptPologKarti.y, pKarta->m_ptPologKarti.x+71,pKarta->m_ptPologKarti.y+160),0);
		}
	}
}
pDoc->GAME_STATE=IGROK_SBRASIVAET;//игрок сходил!!

InvalidateRect(CRect(150,184,506,380),0);
}

void CKozelView::RisovatKUCHI(CDC* pDC)
{
CKozelDoc* pDoc=GetDocument();
double x=576;
double y=35;
//====рисую в цикле карты друг на друге
for(int i=0; i<pDoc->m_VzjatkaCompa.GetCount(); i++)
{
	if(pDoc->m_VzjatkaCompa.GetCount()!=0)
	{
		m_ImOblogki.Draw(pDC,pDoc->NomerOblogki,CPoint(x,y),ILD_NORMAL);
	}//if
	x+=0.5;
	y-=0.5;
}//for
x=576;
double y2=280;
for(int i=0; i<pDoc->m_VzjatkaIgroka.GetCount(); i++)
{

	if(pDoc->m_VzjatkaIgroka.GetCount()!=0)
	{
		m_ImOblogki.Draw(pDC,pDoc->NomerOblogki,CPoint(x,y2),ILD_NORMAL);
	}//if
x+=0.5;
y2-=0.5;
}//for
}

void CKozelView::OnUpdateSbrosit(CCmdUI *pCmdUI)
{
	
	// TODO: Add your command update UI handler code here
CKozelDoc* pDoc=GetDocument();
CKarta* pKarta;
//POSITION position;
BOOL m_bUpdade=0;

CKarta* pKarta_Comp;
CKarta* pKarta_Igrok;

POSITION position_Comp;
POSITION position_Igrok;
POSITION position_Igrok2;

position_Comp=pDoc->m_KartiCompa.GetHeadPosition();
position_Igrok=pDoc->m_KartiIgroka.GetHeadPosition();

int j=(int)pDoc->m_KartiCompa.GetCount();//кол-во карт компа

position_Igrok2= position_Igrok;

//есть ли выдвинутые карты у игрока ==  они выдвинут у компа
int VidvinComp=0;
int VidvinIgroc=0;

for( int z=0; z <j; z++)//перебираю карты компа
		{
		   pKarta_Igrok=pDoc->m_KartiCompa.GetNext(position_Igrok);
			if(pKarta_Igrok->m_ptPologKarti.y==248)
			{
				VidvinIgroc++;
			}

	  		pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
			if(pKarta_Comp->m_ptPologKarti.y==126)
			{
				VidvinComp++;
			}
		}//for
if(VidvinComp!=VidvinIgroc)
{

	pCmdUI->Enable(FALSE);
	return;
}



position_Igrok=position_Igrok2;
//==============ищу выдвинутые карты
	for(int i=0; i <j; i++)
	{
		pKarta=pDoc->m_KartiIgroka.GetNext(position_Igrok);
		int m=pKarta->m_nZnachenie;
		if(pKarta->m_ptPologKarti.y==248)
		{		
		m_bUpdade=TRUE;//хоть одна карта выдвинута
		break;
		}//if
	}//for

 pCmdUI->Enable((pDoc->GAME_STATE==IGROK_OTVETCHAET)& m_bUpdade);
}

void CKozelView::OnUpdateUbrat(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CKozelDoc* pDoc=GetDocument ();
	 pCmdUI->Enable((pDoc->GAME_STATE==IGROC_UBIRAET_KARTI)|
		 (pDoc->GAME_STATE==COMP_UBIRAET_KARTI)|
		  (pDoc->GAME_STATE==COMP_SBRASIVAET)|
		  ( pDoc->GAME_STATE==IGROK_SBRASIVAET));

}

void CKozelView::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
//таймер будет управлять игрой компа
CKozelDoc* pDoc=GetDocument();

switch(pDoc->GAME_STATE)
{
case COMP_XODIT:
	OnCompXodit();
	break;
case COMP_OTVETCHAET:
	OnCompBiet();
	if(pDoc->m_bComp_Biet_Skidivaet==TRUE)
		OnCompSkidivaet();
	break;
case COMP_SBRASIVAET:
	OnUbrat();
	pDoc->RasdatKarti();
	break;
case COMP_UBIRAET_KARTI:
	OnUbrat();
	pDoc->RasdatKarti();
	break;

case IGROC_UBIRAET_KARTI:
	OnUbrat();
	pDoc->RasdatKarti();
	break;
case IGROK_SBRASIVAET:
	OnUbrat();
	pDoc->RasdatKarti();
	break;

case IGROK_XODIT:
	if(pDoc->m_bAVTOPILOT==TRUE)
		Sxodit();
	break;
case IGROK_OTVETCHAET:
	if(pDoc->m_bAVTOPILOT==TRUE)
		{
			Udarit();
			if(pDoc->m_bIgroc_Biet_Skidivaet==TRUE)
				Sbrosit();
		}
	break;

case PODSCHET_OCHKOV:
	pDoc->GAME_STATE=0;
	pDoc->PodschetOchkov();
	break;


}//switch


	CView::OnTimer(nIDEvent);
}

void CKozelView::OnOblogki()
{
	// TODO: Add your command handler code here
	CKozelDoc* pDoc=GetDocument();
	//int NomOblogki;
	COblogkiDLG dlg;
	pDoc->NomerOblogki=(int)dlg.DoModal();
	InvalidateRect(NULL,0);
}

void CKozelView::OnGameSpid1()
{
	// TODO: Add your command handler code here
	CKozelDoc* pDoc=GetDocument();
	pDoc->m_nSkorost_Igri=500;
	KillTimer(1);
	SetTimer(1,pDoc->m_nSkorost_Igri, 0);
}

void CKozelView::OnUpdateGameSpid1(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CKozelDoc* pDoc=GetDocument();
	pCmdUI->Enable(pDoc->m_nSkorost_Igri!=500);
}

void CKozelView::OnGameSpid2()
{
	// TODO: Add your command handler code here
	CKozelDoc* pDoc=GetDocument();
	pDoc->m_nSkorost_Igri=1000;
	KillTimer(1);
	SetTimer(1,pDoc->m_nSkorost_Igri, 0);
}

void CKozelView::OnUpdateGameSpid2(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CKozelDoc* pDoc=GetDocument();
	pCmdUI->Enable(pDoc->m_nSkorost_Igri!=1000);
}

void CKozelView::OnGameSpid3()
{
	// TODO: Add your command handler code here
	CKozelDoc* pDoc=GetDocument();
	pDoc->m_nSkorost_Igri=2000;
	KillTimer(1);
	SetTimer(1,pDoc->m_nSkorost_Igri, 0);
}

void CKozelView::OnUpdateGameSpid3(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CKozelDoc* pDoc=GetDocument();
	pCmdUI->Enable(pDoc->m_nSkorost_Igri!=2000);
}

void CKozelView::OnGameSpid4()
{
	// TODO: Add your command handler code here
	CKozelDoc* pDoc=GetDocument();
	pDoc->m_nSkorost_Igri=3000;
	KillTimer(1);
	SetTimer(1,pDoc->m_nSkorost_Igri, 0);
}

void CKozelView::OnUpdateGameSpid4(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CKozelDoc* pDoc=GetDocument();
	pCmdUI->Enable(pDoc->m_nSkorost_Igri!=3000);
}


void CKozelView::RisovatZveti(CDC* pDC)
{
//	int x=0; int y=0;
//	CRect rect;
//	GetClientRect(&rect);
//
//	CDC dc;
//dc.CreateCompatibleDC(pDC);
//CBitmap bm,* pbm;
//bm.CreateCompatibleBitmap(pDC,rect.right, rect.bottom);
//pbm=dc.SelectObject(&bm);
//CBrush br(RGB(0,128,0));
//dc.FillRect(rect,&br);
//
//	//for (int i=0; i<10; i++)
//	while(y<=rect.bottom)
//	{
//		if(x<=rect.right)
//		{
//			m_ImZvetok.Draw(&dc,0,CPoint(x,y),ILD_NORMAL);
//			x+=41;
//		}
//		else
//		{
//			x=0;
//			y+=41;
//		}
//	}//while
//
//	pDC->BitBlt(0,0,rect.Width(), rect.Height(),&dc,0,0,SRCCOPY);
//	
//	if(pbm)
//		dc.SelectObject(pbm);
//
//br.DeleteObject();
//dc.DeleteDC();
}
void CKozelView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CView::OnPaint() for painting messages
CRect rectrUpdate;
dc.GetClipBox(&rectrUpdate);

CDC  * pDC;
pDC=pDCm;

CBrush	br(RGB(0,128,0));
pDC->SelectObject(m_pBitmap);
pDC->SelectClipRgn(NULL );
pDC->IntersectClipRect(&rectrUpdate);
pDC->SelectObject(&br);

pDC->PatBlt(rectrUpdate.left,rectrUpdate.top,rectrUpdate.Width(),rectrUpdate.Height(),PATCOPY);

CRect rect;
GetClientRect(&rect);

CKozelDoc* pDoc = GetDocument();
ASSERT_VALID(pDoc);
CKartaList* pKartiIgrILICompa;


//RisovatZveti( pDC);
	// TODO: add draw code for native data here
//==================Рисую колоду
//x=150; int y=300;
RisovatKolodu(pDC);
PokazatKozir(pDC);
RisovatKUCHI(pDC);

if((pDoc->GAME_STATE==IGROK_XODIT)|
   (pDoc->GAME_STATE==COMP_OTVETCHAET)|
   (pDoc->GAME_STATE==COMP_UBIRAET_KARTI)|
   (pDoc->GAME_STATE==COMP_SBRASIVAET))
{//сверху будут рисоваться карты компа
pKartiIgrILICompa=&pDoc->m_KartiIgroka;
RisovatKarti(pDC,pKartiIgrILICompa);//,150,270);

pKartiIgrILICompa=&pDoc->m_KartiCompa;
RisovatKarti(pDC,pKartiIgrILICompa);//,150,30);
}//if
else if((pDoc->GAME_STATE==COMP_XODIT) |
		(pDoc->GAME_STATE==IGROK_OTVETCHAET)|
		(pDoc->GAME_STATE==IGROC_UBIRAET_KARTI)|
		(pDoc->GAME_STATE==IGROK_SBRASIVAET))
{//сверху будут рисоваться карты игрока
pKartiIgrILICompa=&pDoc->m_KartiCompa;
RisovatKarti(pDC,pKartiIgrILICompa);//,150,30)

pKartiIgrILICompa=&pDoc->m_KartiIgroka;
RisovatKarti(pDC,pKartiIgrILICompa);//,150,270);
}//
//====================обозначаю ход игрока
if((pDoc->GAME_STATE==IGROK_XODIT) |
		(pDoc->GAME_STATE==IGROK_OTVETCHAET))
{
	pDC->SetBkColor(RGB(0,128,0));
	pDC->SetTextColor(RGB(0,0,128));
	pDC->SetBkMode(TRANSPARENT);
	pDC->TextOut(60,315,"Ваш ход!!");

}//if
if((pDoc->GAME_STATE==COMP_XODIT) |
		(pDoc->GAME_STATE==COMP_OTVETCHAET)|
		(pDoc->GAME_STATE==COMP_SBRASIVAET))
{
	pDC->SetBkColor(RGB(0,128,0));
	pDC->SetTextColor(RGB(0,0,128));
	pDC->SetBkMode(TRANSPARENT);
	pDC->TextOut(20,65,"Ходит компьютер!!");

}//if

dc.BitBlt(0,0,rect.Width(), rect.Height(), pDC,0,0,SRCCOPY);
OnDraw(pDC);
}

void CKozelView::Udarit()
{

CKarta* pKarta_Comp;
CKarta* pKarta_Igrok;

//CKarta* pKarta_Igrok2;
CKarta* pKarta_Igrok_Dlya_Bitiya;

CKarta* Karta[5]={0,0,0,0,0};
CKarta* MasKartKotCompBIET[5]={0,0,0,0,0};

POSITION position_Comp;
POSITION position_Comp2;

POSITION position_Igrok;
POSITION position_Igrok2;

int KolKartKotSxodIgrok=0;
int KolKartKotSxodComp=0;
int k=0;

CKozelDoc* pDoc=GetDocument();

pDoc->m_bIgroc_Biet_Skidivaet=FALSE;//изначально комп всегда бьет

position_Comp=pDoc->m_KartiCompa.GetHeadPosition();
position_Igrok=pDoc->m_KartiIgroka.GetHeadPosition();

 position_Comp2= position_Comp;
 position_Igrok2= position_Igrok;

BOOL m_bMoguUdarit=FALSE;//1-Игрок бьет карту
//==============

int j=(int)pDoc->m_KartiCompa.GetCount();

	for(int i=0; i <j; i++)//прохожу по всем картам Компа
	{
		pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
	
	//==проверяю выдвинута(сходил ей)карта компа
	if(pKarta_Comp->m_ptPologKarti.y==126)
	{
		m_bMoguUdarit=FALSE;
		position_Igrok= position_Igrok2;//Когда начинается нов цикл п								  озиция должна быть опять первой!
		k=0;
		for( int m=0; m <j; m++)//перебираю карты игрока
		{//ищу не козырные
		pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
			
	 //нахожу все карты, которыми можно бить эту карту игрока	
			if(((pKarta_Igrok->m_nZnachenie)>(pKarta_Comp->						m_nZnachenie)) & ((pKarta_Igrok->m_nMast)==						(pKarta_Comp->m_nMast))& (pKarta_Igrok->								m_nSOSTOYANIE_KARTI==0))
			{
					Karta[k]=pKarta_Igrok;
				k++;
				m_bMoguUdarit=TRUE;
			}//if
		}//for

		//-----------------бью козырем если не сммог так ударить
		if(!m_bMoguUdarit)
		{
		position_Igrok= position_Igrok2;//Когда начинается нов цикл п								  озиция должна быть опять первой!
		k=0;
		for( int d=0; d <j; d++)//перебираю карты компа
		{
		pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
			
			{
			if(((pKarta_Igrok->m_nMast)==(pDoc->m_nKozir))&
				(pKarta_Igrok->m_nSOSTOYANIE_KARTI==0)&
				(pKarta_Comp->m_nMast!=pDoc->m_nKozir))
			{
					Karta[k]=pKarta_Igrok;
				k++;
				m_bMoguUdarit=TRUE;
			}//if
			else if(((pKarta_Igrok->m_nMast)==(pDoc->m_nKozir))&
				(pKarta_Igrok->m_nSOSTOYANIE_KARTI==0)&
				(pKarta_Comp->m_nMast==pDoc->m_nKozir)&
				(pKarta_Igrok->m_nZnachenie > 
				pKarta_Comp->m_nZnachenie))
			{
				Karta[k]=pKarta_Igrok;
				k++;
				m_bMoguUdarit=TRUE;
			}//else if
				
			}//if
		}//for

		}//if
			
		//--------------Игрок не может побить карту ------------
		if(!m_bMoguUdarit)
		{
		//===========возвращаю карты назад
		position_Igrok= position_Igrok2;//Когда начинается нов цикл п								  озиция должна быть опять первой!
			for(int d=0; d <j; d++)//перебираю карты компа
			{
	    		pKarta_Igrok=
					pDoc->m_KartiIgroka.GetNext(position_Igrok);
				pKarta_Igrok->m_nSOSTOYANIE_KARTI=0;
			}//for
			//==========================
			pDoc->m_bIgroc_Biet_Skidivaet=TRUE;//??????????
			//pDoc->GAME_STATE=COMP_SBRASIVAET;//Надо скинуть игроку
			return ; //возврат, комп должен скидывать
		}//if

//=======выбрать наименьшую карту для битья карты игрока
		pKarta_Igrok_Dlya_Bitiya=Karta[0];	
		Karta[0]=0;
		for(int l=1; l<5; l++)
		{
		pKarta_Igrok=Karta[l];
		Karta[l]=0;
			if((pKarta_Igrok!=0))
			{
				if((pKarta_Igrok_Dlya_Bitiya->m_nZnachenie >							pKarta_Igrok->m_nZnachenie) & 
					(pKarta_Igrok->m_ptPologKarti.y==0))
					{
						pKarta_Igrok_Dlya_Bitiya=pKarta_Comp;
					}//if
			}//if
		}//for
	
	//==================================
		//если есть такая карта, то выдвигаем ее
	if(pKarta_Igrok_Dlya_Bitiya!=0)
	{//помечаю эту карту
			pKarta_Igrok_Dlya_Bitiya->m_nSOSTOYANIE_KARTI=
			pKarta_Comp->m_nZnachenie;

	}//if

	}//if

   }//for

//=========выдвигаю карты
   position_Comp= position_Comp2;
   int i = 0;
   for( i=0; i <j; i++)//прохожу по всем картам компа
	{
		pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
	
	//==проверяю выдвинута(сходил ей)карта игрока
	
		position_Igrok= position_Igrok2;//Когда начинается нов цикл п								  озиция должна быть опять первой!
		for(int  m=0; m <j; m++)//перебираю карты компа
		{
		pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
			if(pKarta_Igrok->m_nSOSTOYANIE_KARTI==
				pKarta_Comp->m_nZnachenie)
			{
				//int f=pKarta_Comp->m_nZnachenie;
			
				pKarta_Igrok->m_ptPologKarti.x
					=pKarta_Comp->m_ptPologKarti.x;

				pKarta_Igrok->m_ptPologKarti.y=184;
				pKarta_Igrok->m_bPokaziv=TRUE;
				pKarta_Igrok->m_nSOSTOYANIE_KARTI=0;
			}//if


		}//for

	
	}//for

//===================================
	pDoc->GAME_STATE=IGROC_UBIRAET_KARTI;
//InvalidateRect(CRect(150,30,506,227),0);
//InvalidateRect(CRect(20,65,150,95),0);//надпи
	InvalidateRect(CRect(150,184,506,380),0);

}

void CKozelView::Sxodit()
{
CKozelDoc* pDoc=GetDocument();

CKarta* pKarta_Igrok;

int MasKolMASTEI[4]={0,0,0,0};

POSITION position_Igrok;
POSITION position_Igrok2;

int MastDlyaXoda=0;

position_Igrok=pDoc->m_KartiIgroka.GetHeadPosition();
position_Igrok2=position_Igrok;

//========опред. сколько каких мастей имеется
int j=(int)pDoc->m_KartiIgroka.GetCount();

for(int i=0; i<j; i++)
{
	pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);

	switch(pKarta_Igrok->m_nMast)
	{
		case 1:
			MasKolMASTEI[0]++;
			break;
		case 2:
			MasKolMASTEI[1]++;
			break;
		case 3:
			MasKolMASTEI[2]++;
			break;
		case 4:
			MasKolMASTEI[3]++;
			break;
	}

}//for
int p=0;
switch(pDoc->m_nKozir)
{
	case 1:
		p=1;
		break;
	case 2:
		p=2;
		break;
	case 3:
		p=3;
		break;
	case 4:
		p=0;
		break;
}//switch

int max=MasKolMASTEI[p];//какой масти больше
int i = 0;
for(i=0; i<4; i++)
{
	if( (max <= MasKolMASTEI[i]) &( (i+1)!=pDoc->m_nKozir) &
		(MasKolMASTEI[i]!=0))
	{//
		MastDlyaXoda=(i+1);
		max=MasKolMASTEI[i];
	}//if
	else if(( MasKolMASTEI[i])==j)//все карты козыри
	{
	MastDlyaXoda=pDoc->m_nKozir;
	}//else if
	else if((MasKolMASTEI[i] > max ) & (j==1))
	{
		MastDlyaXoda=(i+1);
	}//else if
	
}//for

//=======Cам ход
position_Igrok=position_Igrok2;

//========опред. сколько каких мастей имеется

int SkolkoKartSxodilo=0;
int k=(int)pDoc->m_KartiIgroka.GetCount();

for( i=0; i<k; i++)
{
	pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
	if(pKarta_Igrok->m_nMast==MastDlyaXoda)
	{
		SkolkoKartSxodilo++;
		pKarta_Igrok->m_ptPologKarti.y=184;
		pKarta_Igrok->m_bPokaziv=TRUE;
	}//if

}//for

//ASSERT(MastDlyaXoda!=0);
//ASSERT(SkolkoKartSxodilo!=0);
if(SkolkoKartSxodilo==0)
AfxMessageBox("ошибка в ходе");

pDoc->GAME_STATE=COMP_OTVETCHAET;//!!!!!!!!!!!

InvalidateRect(CRect(150,184,506,380),0);
InvalidateRect(CRect(60,315,130,340),0);
InvalidateRect(CRect(20,65,150,95),0);//надпись

}

void CKozelView::Sbrosit()
{

POSITION position_Comp;
POSITION position_Igrok2;
POSITION position_Igrok3;
POSITION position_Igrok;

CKozelDoc* pDoc=GetDocument();

CKarta* pKarta_Comp;
CKarta* pKarta_Igrok;
//CKarta* pKarta_Igrok_Dlya_Skidivaniya;

CKarta* Karta[5]={0,0,0,0,0};

position_Comp=pDoc->m_KartiCompa.GetHeadPosition();
position_Igrok=pDoc->m_KartiIgroka.GetHeadPosition();
position_Igrok2=position_Igrok;
position_Igrok3=position_Igrok ;

int MastCompa=0; // масть карт с которых пошел комп
int SkolkoSkidivat=0;
int Itog=0;
//ASSERT(pDoc->m_KartiIgroka.GetCount());//у игроков должны быть карт
//===для начала вычислим сколько карт скидывать

for(int i=0; i<pDoc->m_KartiCompa.GetCount(); i++)
{
	 pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
		if(pKarta_Comp->m_ptPologKarti.y==126)
		{
			SkolkoSkidivat++;
			MastCompa=pKarta_Comp->m_nMast;
		}//if
}//for
//========================
//=========ищем, что не жалко скинуть
//пока без козырей

int zn1=0;
int zn2=10;
int zn3=20;
int zn4=30;

while((zn1<9)|(Itog==SkolkoSkidivat))
{				
	zn1++;
	zn2++;
	zn3++;
	zn4++;
position_Igrok=position_Igrok2;
int i;
	for(i=0; i<pDoc->m_KartiCompa.GetCount(); i++)//нахожу подходящую карту
	{
		pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
		if(pKarta_Igrok->m_nMast!=pDoc->m_nKozir)
		{
			switch(pKarta_Igrok->m_nMast)
			{
				case 1:
					if(pKarta_Igrok->m_nZnachenie==zn1)
					{
						pKarta_Igrok->m_nSOSTOYANIE_KARTI=1;
						Itog++;
					}//if				
				break;

				case 2:
					if(pKarta_Igrok->m_nZnachenie==zn2)
					{
							Itog++;
						pKarta_Igrok->m_nSOSTOYANIE_KARTI=1;
					}//if
					
				break;
				case 3:
					if(pKarta_Igrok->m_nZnachenie==zn3)
					{
						pKarta_Igrok->m_nSOSTOYANIE_KARTI=1;
						Itog++;
					}//if
						
				break;
				case 4:
					if(pKarta_Igrok->m_nZnachenie==zn4)
					{
						pKarta_Igrok->m_nSOSTOYANIE_KARTI=1;
							Itog++;
					}//if

				break;
			}
			
		}//if
		if((Itog==SkolkoSkidivat))
			break;
	}//for
	
		if((Itog==SkolkoSkidivat))
			break;
}//while
//-----------если не хватает простых скинуть скидыв. козырных
int znKOZ=0;
switch(pDoc->m_nKozir)
{
	case 1:
		znKOZ=0;
	break;
	case 2:
		znKOZ=10;
	break;
	case 3:
		znKOZ=20;
	break;
	case 4:
		znKOZ=30;
	break;
}

if(Itog<SkolkoSkidivat)
{
	
	while((znKOZ<40)|(Itog==SkolkoSkidivat))
	{
			znKOZ++;
		position_Igrok=position_Igrok2;
		int i = 0;
		for(i=0; i<pDoc->m_KartiCompa.GetCount(); i++)//нахожу под												ходящую карту
		{
		pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
			if((pKarta_Igrok->m_nMast==pDoc->m_nKozir)&
				(pKarta_Igrok->m_nZnachenie==znKOZ))
				{
					pKarta_Igrok->m_nSOSTOYANIE_KARTI=1;
						Itog++;
				}//if
		}
		if((Itog==SkolkoSkidivat))
			break;
	}//while
}//if
	//------------------------------------выдвигаю карту
position_Igrok=position_Igrok2;
int x1=434;
for(int h=0; h<pDoc->m_KartiCompa.GetCount(); h++)
{
	pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
	
	
	if(pKarta_Igrok->m_nSOSTOYANIE_KARTI==1)
	{
		pKarta_Igrok->m_ptPologKarti.y=184;
		pKarta_Igrok->m_bPokaziv=FALSE;
	}//if

}//for

//=======================================
//pDoc->GAME_STATE=IGROC_UBIRAET_KARTI;
//проверим корректность
//ASSERT((Itog!=SkolkoSkidivat));
pDoc->GAME_STATE=IGROK_SBRASIVAET;//Надо скинуть игроку
InvalidateRect(CRect(150,184,506,380),0);

}

void CKozelView::OnAvtopilot()
{
	// TODO: Add your command handler code here
		CKozelDoc* pDoc=GetDocument();

pDoc->m_bAVTOPILOT=!pDoc->m_bAVTOPILOT;
}

void CKozelView::OnUpdateAvtopilot(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CKozelDoc* pDoc=GetDocument();
	int i=((pDoc->m_bAVTOPILOT==TRUE) ? 1:0);

	pCmdUI->SetCheck(i);
}

void CKozelView::On172()
{
	// TODO: Add your command handler code here
		CKozelDoc* pDoc=GetDocument();
		pDoc->m_bVividitOtchet=!pDoc->m_bVividitOtchet;

}

void CKozelView::OnUpdate172(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
		CKozelDoc* pDoc=GetDocument();
		if(pDoc->m_bVividitOtchet)
		{
			pCmdUI->SetText("Не выводить отчет.");
		}
		else
		{
			pCmdUI->SetText("Выводить отчет");
		}
}

void CKozelView::OnMuzik()
{
	// TODO: Add your command handler code here
	 Musik=!Musik;
if(Musik==TRUE)
	{
		PlaySound(MAKEINTRESOURCE(IDR_WAVE1),0,SND_RESOURCE|SND_LOOP | SND_ASYNC);
	}
		else
	{
		PlaySound(0,0,SND_PURGE);

	}//if

}

void CKozelView::OnUpdateMuzik(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if(Musik==TRUE)
	{
		pCmdUI->SetText("Выкл. музыку");
	}
	else
	{
		pCmdUI->SetText("Вкл. музыку");

	}//if
}

void CKozelView::CompXodit2()
{
CKozelDoc* pDoc=GetDocument();
CKarta* pKarta_Comp;

int OCHKI=0;
int* pOCHKI=&OCHKI;
int NetTakoiMasti=0;

int BIET=0;
BOOL Proverit=FALSE; //нужно ли  проверять может ли бить игрок


int Mas_Ocenoc[4][4]={{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};//бьет не бьет, очки, выбран для хода
CKarta* MasKART[4][5]={{0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, 
						            {0,0,0,0,0}};

POSITION position_Comp;
POSITION position_Comp2;

position_Comp=pDoc->m_KartiCompa.GetHeadPosition();
position_Comp2=position_Comp;

int j=(int)pDoc->m_KartiCompa.GetCount();

//==заполняю массив карт по мастям
for(int i=0; i<j; i++)
{
	pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
	
	MasKART[pKarta_Comp->m_nMast-1][i]=pKarta_Comp;

}//for
//====================
//=============== помечаю карты компа, которыми хочу сходить и вызваю для каждого хода ф-ю удара, которая возвращает нужные значения
for(int i=0; i<4; i++)
{
	BIET=0;
	NetTakoiMasti=0;
	OCHKI=0;
	//помечаю
	for(int k=0; k<j; k++)
	{
		if(MasKART[i][k]!=0)
		{
			MasKART[i][k]->m_nSOSTOYANIE_KARTI=1;
			Proverit=TRUE;
			OCHKI+=PodschetOchkov(MasKART[i][k]);
		}
	}//for k
	if (Proverit)
	{
		BIET=ProverkaUDARA(pOCHKI);
		Proverit=FALSE;
		NetTakoiMasti=1;
	}
	else
	{
		NetTakoiMasti=0;
	}//if
	//снимаю пометки
	for(int k=0; k<j; k++)
	{	
		if(MasKART[i][k]!=0)
		{
			MasKART[i][k]->m_nSOSTOYANIE_KARTI=0;
		}
	}//for k

	//=======заполняю массив оценок
	Mas_Ocenoc[i][0]=BIET;
	Mas_Ocenoc[i][1]+=*pOCHKI;
	Mas_Ocenoc[i][3]=NetTakoiMasti;
 }//for i


//==================Выбираю чем сходить

int VibranXod=0;
int VibranMast=0;
int KolOchkov=0;
//int VibrMas=0;

while(VibranXod==0)
{

	for(int i=0; i<4;i++)
	{
		if((Mas_Ocenoc[i][3]==1) & (pDoc->m_nKozir!=i+1))
		{//есть такая масть и она не козырная
			if((Mas_Ocenoc[i][0]==0) &(Mas_Ocenoc[i][2]!=1))// &
				//(Mas_Ocenoc[i][1]<KolOchkov))
			{//игрок не бьет
				//VibrMas=i;
				VibranXod+=1;
				VibranMast=i;
				Mas_Ocenoc[i][2]=VibranXod;
			}//if
			
		}//if
	}//for i

	if(VibranXod>1)
	{
		KolOchkov=Mas_Ocenoc[VibranMast][1];
		for(int i=0; i<4;i++)
		{		
			if(Mas_Ocenoc[i][1]>KolOchkov)
			{
				VibranMast=i;
				VibranXod=1;
			}
		}
	}
	
	if(VibranXod==0)
		{
		//====сходить хоть как-нибудь
			for(int i=0; i<4;i++)
			{
			 if((Mas_Ocenoc[i][3]==1) )
			 {//есть такая масть и она не козырная
				if((Mas_Ocenoc[i][0]==1) &(Mas_Ocenoc[i][2]!=1))//&
				//(Mas_Ocenoc[i][1]<KolOchkov))
					{//игрок не бьет
						VibranXod=1;
						VibranMast=i;
						Mas_Ocenoc[i][2]=VibranXod;
					}//if
			 }//if
			}//for
		}//if

	if(VibranXod==0)
		{//можно сходить козырями
			for(int i=0; i<4;i++)
			{
			 if((Mas_Ocenoc[i][3]==1) )
			 {//есть такая масть и она не козырная
				if((Mas_Ocenoc[i][0]==0) &(Mas_Ocenoc[i][2]!=1))
					{//игрок не бьет
						VibranXod=1;
						VibranMast=i;
						Mas_Ocenoc[i][2]=VibranXod;
					}//if
			 }//if
			}//for
		}//if
	
		
	
}//while
//==выбор сделан теперь ход
for(int i=0; i<4;i++)
	{
		if(MasKART[VibranMast][i]!=0)
		{
			MasKART[VibranMast][i]->m_ptPologKarti.y=126;
			MasKART[VibranMast][i]->m_bPokaziv=TRUE;
		}//if
	}//for

pDoc->GAME_STATE=IGROK_OTVETCHAET;//!!!!!!!!!!!
InvalidateRect(CRect(150,30,506,227),0);
InvalidateRect(CRect(60,315,130,340),0);
InvalidateRect(CRect(20,65,150,95),0);//надпис

}

int CKozelView::ProverkaUDARA(int* pOCHKI)
{
//если игрок выдвинул карты и эти карты бьют карты компа
int OCHKI=0;//*pOCHKI;

CKarta* pKarta_Comp;
CKarta* pKarta_Igrok;
CKarta* pKarta_Igroka_Dlya_Bitiya;

POSITION position_Comp;
POSITION position_Comp2;
POSITION position_Igrok;
POSITION position_Igrok2;

CKozelDoc* pDoc=GetDocument();

CKarta* MasKart[5]={0,0,0,0,0};
CKarta* MasKartDlyaBitya[5]={0,0,0,0,0};//тут будут карты которыми ударит игрок

position_Comp=pDoc->m_KartiCompa.GetHeadPosition();
position_Igrok=pDoc->m_KartiIgroka.GetHeadPosition();

int j=(int)pDoc->m_KartiCompa.GetCount();//кол-во карт компа

//прохожу по всем картам компа во внешнем цикле
//во внутреннем по картам игрока, нахожу те карты, котор можно бить
//Если хотябы одну карту компа не может бить игрок, То  игрок может только скидывать. Следовательно деактевирую кнопку бить, Кнопка скидывать активирована
int k=0;
position_Igrok2= position_Igrok;
position_Comp2= position_Comp;
BOOL m_bMoguUdarit=FALSE;//1-комп бьет карту


position_Comp=position_Comp2;
for(int i=0; i <j; i++)//прохожу по всем картам компа
{
		pKarta_Comp=pDoc->m_KartiCompa.GetNext(position_Comp);
	
	//==проверяю выдвинута(сходил ей)карта компа
	if(pKarta_Comp->m_nSOSTOYANIE_KARTI==1)
	{
		m_bMoguUdarit=FALSE;

		position_Igrok= position_Igrok2;//Когда начинается нов цикл								позиция должна быть опять первой!
		k=0;
		for( int m=0; m <j; m++)//перебираю карты компа
		{
		   pKarta_Igrok=pDoc->m_KartiCompa.GetNext(position_Igrok);
			
	 //нахожу все карты, которыми можно бить эту карту игрока	
			if(((pKarta_Igrok->m_nZnachenie)>(pKarta_Comp->						m_nZnachenie)) & ((pKarta_Comp->m_nMast)==						(pKarta_Igrok->m_nMast))& 
				(pKarta_Igrok->m_nSOSTOYANIE_KARTI!=1)&
				(pKarta_Igrok->m_ptPologKarti.y==280))
			{
					MasKart[k]=pKarta_Igrok;
				k++;
				m_bMoguUdarit=TRUE;
			}//if

		}//for

		//-----------------бью козырем если не сммог так ударить
		if(!m_bMoguUdarit)
		{
		position_Igrok= position_Igrok2;//Когда начинается нов цикл							позиция должна быть опять первой!
		k=0;
		for( int d=0; d <j; d++)//перебираю карты игрока
		{
		  pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
			
			if ((pKarta_Igrok->m_nMast==pDoc->m_nKozir)& 
				(pKarta_Igrok->m_nSOSTOYANIE_KARTI!=1)&
				(pKarta_Igrok->m_ptPologKarti.y==280)&
				(pKarta_Comp->m_nMast!=pDoc->m_nKozir))
			{
					MasKart[k]=pKarta_Igrok;
				k++;
				m_bMoguUdarit=TRUE;
			}//if
			else if((pKarta_Igrok->m_nMast==pDoc->m_nKozir)& 
				(pKarta_Igrok->m_nSOSTOYANIE_KARTI!=1)&
				(pKarta_Igrok->m_ptPologKarti.y==280)&
				(pKarta_Comp->m_nMast==pDoc->m_nKozir)&
				(pKarta_Comp->m_nZnachenie <
				pKarta_Igrok->m_nZnachenie))
			{
					MasKart[k]=pKarta_Igrok;
				k++;
				m_bMoguUdarit=TRUE;
			}

		}//for

		}//if
			
		//--------------Игрок не может побить карту ------------
		if(!m_bMoguUdarit)
		{
		//pDoc->GAME_STATE=IGROK_SBRASIVAET;//Надо скинуть компу	
		position_Igrok= position_Igrok2;//Когда начинается нов цикл							позиция должна быть опять первой!
		for(int  s=0; s <j; s++)//перебираю карты игрока
		{
		  pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
		pKarta_Igrok->m_nSOSTOYANIE_KARTI=0;

		}
			return 0; //выходи из цикла, игрок не может ударить
		}//if

//=======выбрать наименьшую карту для битья карты игрока
	pKarta_Igroka_Dlya_Bitiya=MasKart[0];	
	MasKart[0]=0;
	for(int l=1; l<5; l++)
		{
		pKarta_Igrok=MasKart[l];
		MasKart[l]=0;
		if((pKarta_Igrok!=0))
		{
				if((pKarta_Igroka_Dlya_Bitiya->m_nZnachenie >		                    pKarta_Igrok->m_nZnachenie) & 
					(pKarta_Igrok->m_nSOSTOYANIE_KARTI!=1)&
				(pKarta_Igrok->m_ptPologKarti.y==280))
				{
					pKarta_Igroka_Dlya_Bitiya=pKarta_Igrok;
				}//if
		}//if
		}//for

		//=============помечаю карту, чтоб в следущий раз не использовать для битья
		pKarta_Igroka_Dlya_Bitiya->m_nSOSTOYANIE_KARTI=1;
				// заполняю массив картами
			MasKartDlyaBitya[i]=pKarta_Igroka_Dlya_Bitiya;

//..===============
	}//if

   }//for

		
//===========================
//считаю очки 
   for(int y=0; y<5; y++)
   {
	   if (MasKartDlyaBitya[y]!=0)
	   {
		   OCHKI+=PodschetOchkov(MasKartDlyaBitya[y]);
	   }//if
   }
   *pOCHKI+=OCHKI;

//обнуляю все установки у игрока в картах
position_Igrok= position_Igrok2;//Когда начинается нов цикл							позиция должна быть опять первой!
		for(int  d=0; d <j; d++)//перебираю карты игрока
		{
		  pKarta_Igrok=pDoc->m_KartiIgroka.GetNext(position_Igrok);
			pKarta_Igrok->m_nSOSTOYANIE_KARTI=0;
		}

//=================================
return 1;

}

int CKozelView::PodschetOchkov(CKarta* Karta)
{
int OCHKI=0;

 //for(int y=0; y<5; y++)
   {
	   if ( Karta!=0)
	   {
		switch( Karta->m_nMast)
		{
		case 1:
			switch(Karta->m_nZnachenie)
		{
		/*case 1:
		case 2:
		case 3:
		case 4:*/
		case 5:
			OCHKI+=2;
			break;
		case 6:
			OCHKI+=3;
			break;
		case 7:
			OCHKI+=4;
			break;
		case 8:
			OCHKI+=10;
			break;
		case 9:
			OCHKI+=11;
			break;
		}//switch
			break;
			case 2:
		switch(Karta->m_nZnachenie)
		{
		/*case 1:
		case 12:
		case 3:
		case 4:*/
		case 15:
			OCHKI+=2;
			break;
		case 16:
			OCHKI+=3;
			break;
		case 17:
			OCHKI+=4;
			break;
		case 18:
			OCHKI+=10;
			break;
		case 19:
			OCHKI+=11;
			break;
		}//switch
		break;
	case 3:
		switch(Karta->m_nZnachenie)
		{
		/*case 1:
		case 2:
		case 3:
		case 4:*/
		case 25:
			OCHKI+=2;
			break;
		case 26:
			OCHKI+=3;
			break;
		case 27:
			OCHKI+=4;
			break;
		case 28:
			OCHKI+=10;
			break;
		case 29:
			OCHKI+=11;
			break;
		}//switch
		break;
	case 4:
		switch(Karta->m_nZnachenie)
		{
		/*case 1:
		case 2:
		case 3:
		case 4:*/
		case 35:
			OCHKI+=2;
			break;
		case 36:
			OCHKI+=3;
			break;
		case 37:
			OCHKI+=4;
			break;
		case 38:
			OCHKI+=10;
			break;
		case 39:
			OCHKI+=11;
			break;
		}//switch
		break;

		}//switch
		}//if 
   }//for y


return OCHKI;
}

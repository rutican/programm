// OtchetDLG.cpp : implementation file
//

#include "stdafx.h"
#include "Kozel.h"
#include "OtchetDLG.h"
#include "Karta.h"

// COtchetDLG dialog

IMPLEMENT_DYNAMIC(COtchetDLG, CDialog)
COtchetDLG::COtchetDLG(CWnd* pParent /*=NULL*/)
	: CDialog(COtchetDLG::IDD, pParent)
{
	OTOBRAGAT=0;//карты выигранные компом
}

COtchetDLG::~COtchetDLG()
{
}

void COtchetDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COtchetDLG, CDialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_SMENA, OnBnClickedSmena)
END_MESSAGE_MAP()


// COtchetDLG message handlers

void COtchetDLG::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialog::OnPaint() for painting messages
POSITION position;
POSITION position_Igroka;

TCHAR strVzyatka[30];

CKarta* pKarta;
int m_nNomZagrIm;
CImageList* pImList;
int x=10, y=20;

dc.SetBkMode(TRANSPARENT);
if(OTOBRAGAT==0)
{
	//strVzyatka="";
wsprintf(strVzyatka,"Взятка компа составляет %d ",pDoc->m_nVzyatkaCompa);

	dc.TextOut(110,0,strVzyatka);

position=pDoc->m_VzjatkaCompa.GetHeadPosition();

for(int i=0; i<pDoc->m_VzjatkaCompa.GetCount(); i++)
{
	pKarta=pDoc->m_VzjatkaCompa.GetNext(position);

		if( (pKarta->m_nZnachenie<10))
		{m_nNomZagrIm=pKarta->m_nZnachenie-1;pImList=&pView->m_ImRed;}
		else if( (pKarta->m_nZnachenie>10)&  (pKarta->m_nZnachenie<20))
		{m_nNomZagrIm=pKarta->m_nZnachenie-2;pImList=&pView->m_ImRed;}
		else if( (pKarta->m_nZnachenie>20)&  (pKarta->m_nZnachenie<30))
		{m_nNomZagrIm=pKarta->m_nZnachenie-21;pImList=&pView->m_ImBlac;}
		else if( (pKarta->m_nZnachenie>30)&  (pKarta->m_nZnachenie<40))
		{m_nNomZagrIm=pKarta->m_nZnachenie-22;pImList=&pView->m_ImBlac;}

		
	pImList->Draw((CDC*)&dc,m_nNomZagrIm,CPoint(x,y) ,ILD_NORMAL);

	if(y<=212)
	{
		if(x>=426)
		{
		x=10; y+=97;
		}
		else
			x+=72;
	}
	else
	{
		if(x>=497)
		{
		x=10; y+=97;
		}
		else
			x+=72;
	}//if
}//for
}//if
else
{
//	strVzyatka="";
	//выводим взятку
wsprintf(strVzyatka,"Взятка игрока составляет %d",pDoc->m_nVzyatkaIgroka);

	dc.TextOut(110,0,strVzyatka);


	position_Igroka=pDoc->m_VzjatkaIgroka.GetHeadPosition();

for(int i=0; i<pDoc->m_VzjatkaIgroka.GetCount(); i++)
{
	pKarta=pDoc->m_VzjatkaIgroka.GetNext(position_Igroka);

		if( (pKarta->m_nZnachenie<10))
		{m_nNomZagrIm=pKarta->m_nZnachenie-1;pImList=&pView->m_ImRed;}
		else if( (pKarta->m_nZnachenie>10)&  (pKarta->m_nZnachenie<20))
		{m_nNomZagrIm=pKarta->m_nZnachenie-2;pImList=&pView->m_ImRed;}
		else if( (pKarta->m_nZnachenie>20)&  (pKarta->m_nZnachenie<30))
		{m_nNomZagrIm=pKarta->m_nZnachenie-21;pImList=&pView->m_ImBlac;}
		else if( (pKarta->m_nZnachenie>30)&  (pKarta->m_nZnachenie<40))
		{m_nNomZagrIm=pKarta->m_nZnachenie-22;pImList=&pView->m_ImBlac;}

		
	pImList->Draw((CDC*)&dc,m_nNomZagrIm,CPoint(x,y) ,ILD_NORMAL);

	if(y<=212)
	{
		if(x>=426)
		{
		x=10; y+=97;
		}
		else
			x+=72;
	}
	else
	{
		if(x>=497)
		{
		x=10; y+=97;
		}
		else
			x+=72;
	}//if
}//for
}


}

BOOL COtchetDLG::OnInitDialog()
{
	CDialog::OnInitDialog();
pView=(CKozelView*)this->GetParentFrame()->GetActiveView();
pDoc=(CKozelDoc*)this->GetParentFrame()->GetActiveDocument();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void COtchetDLG::OnBnClickedSmena()
{
	// TODO: Add your control notification handler code here
	CButton* pBut=(CButton*)GetDlgItem(IDC_SMENA);
	OTOBRAGAT=!OTOBRAGAT;
	if(OTOBRAGAT==0)
	{
		pBut->SetWindowText("Показать выигрыш игрока");
	}
	else
	{
		pBut->SetWindowText("Показать выигрыш компьютера");
	}
	InvalidateRect(NULL );
}

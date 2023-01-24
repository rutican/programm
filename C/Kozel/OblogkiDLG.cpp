// OblogkiDLG.cpp : implementation file
//

#include "stdafx.h"
#include "Kozel.h"

#include "OblogkiDLG.h"


// COblogkiDLG dialog

CRect rect0(26,36,106,142), rect1(108,36,188,142),
		rect2(190,36,270,142),rect3(272,36,352,142);

IMPLEMENT_DYNAMIC(COblogkiDLG, CDialog)
COblogkiDLG::COblogkiDLG(CWnd* pParent /*=NULL*/)
	: CDialog(COblogkiDLG::IDD, pParent)
{
	m_nNomOblogki=0;
bmOblogki.LoadBitmap(IDB_BITMAP3);//red

m_ImOblogki.Create(71,96,TRUE,1,1);
m_ImOblogki.Add(&bmOblogki,RGB(128,128,128));
 
}

COblogkiDLG::~COblogkiDLG()
{
}

void COblogkiDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COblogkiDLG, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()


// COblogkiDLG message handlers

void COblogkiDLG::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
m_nNomStarojOblogki=m_nNomOblogki;

EndDialog(m_nNomStarojOblogki);
DestroyWindow();
	//OnOK();
}

BOOL COblogkiDLG::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

pDoc=(CKozelDoc*)this->GetParentFrame()->GetActiveDocument();
m_nNomOblogki=pDoc->NomerOblogki;
m_nNomStarojOblogki=pDoc->NomerOblogki;
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void COblogkiDLG::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialog::OnPaint() for painting messages
pView=(CKozelView*)this->GetParentFrame()->GetActiveView();
CBrush br(RGB(0,0,128));


///=====рисую кнопки
if(m_nNomOblogki==0)
{
dc.DrawFrameControl(rect0,DFC_BUTTON,DFCS_BUTTONPUSH|DFCS_PUSHED);
dc.FillRect(rect0,&br);
}
else 
	dc.DrawFrameControl(rect0,DFC_BUTTON,DFCS_BUTTONPUSH);

if(m_nNomOblogki==1)
{
dc.DrawFrameControl(rect1,DFC_BUTTON,DFCS_BUTTONPUSH|DFCS_PUSHED);
dc.FillRect(rect1,&br);
}
else
	dc.DrawFrameControl(rect1,DFC_BUTTON,DFCS_BUTTONPUSH);

if(m_nNomOblogki==2)
{
dc.DrawFrameControl(rect2,DFC_BUTTON,DFCS_BUTTONPUSH|DFCS_PUSHED);
dc.FillRect(rect2,&br);
}
else
	dc.DrawFrameControl(rect2,DFC_BUTTON,DFCS_BUTTONPUSH);

if(m_nNomOblogki==3)
{
dc.DrawFrameControl(rect3,DFC_BUTTON,DFCS_BUTTONPUSH|DFCS_PUSHED);
dc.FillRect(rect3,&br);
}
else
	dc.DrawFrameControl(rect3,DFC_BUTTON,DFCS_BUTTONPUSH);

//Рисую обложки
	int x=30, y=40;
for(int i=0; i<4; i++)
{
//m_ImOblogki.Draw((CDC*)&dc,i,CPoint(x,y),ILD_NORMAL);
	pView->m_ImOblogki.Draw((CDC*)&dc,i,CPoint(x,y),ILD_NORMAL);
x+=82;
}

br.DeleteObject();
}

void COblogkiDLG::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
CRect rect;
if(rect0.PtInRect(point))
{
m_nNomOblogki=0;
rect=rect0;
}
else if(rect1.PtInRect(point))
{
m_nNomOblogki=1;
rect=rect1;
}
else if(rect2.PtInRect(point))
{
m_nNomOblogki=2;
rect=rect2;
}
else if(rect3.PtInRect(point))
{
m_nNomOblogki=3;
rect=rect3;
}

InvalidateRect(CRect(26,36,352,142));

	CDialog::OnLButtonDown(nFlags, point);
}

void COblogkiDLG::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
EndDialog(m_nNomStarojOblogki);
DestroyWindow();
	//OnCancel();
}

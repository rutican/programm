// KozelDoc.cpp : implementation of the CKozelDoc class
//

#include "stdafx.h"
#include "Kozel.h"
#include "MainFrm.h"
#include "OtchetDLG.h"
#include "KozelDoc.h"

#include <MMSYSTEM.H>//

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CKozelDoc

IMPLEMENT_DYNCREATE(CKozelDoc, CDocument)

BEGIN_MESSAGE_MAP(CKozelDoc, CDocument)
END_MESSAGE_MAP()


// CKozelDoc construction/destruction

CKozelDoc::CKozelDoc()
: m_bVividitOtchet(false)
{
	// TODO: add one-time construction code here
	
//-----------инициирую начальные данные
//GAME_STATE=0;
	m_bCheiXod=0;

	m_nShtrafOchkiCompa=0;
	m_nShtrafOchkiIgroka=0;

	m_bComp_Biet_Skidivaet=FALSE;

	 m_bIgroc_Biet_Skidivaet=FALSE;
	 m_bAVTOPILOT=0;//Без автопилота.

	m_nKolSigranIgr=0;
	m_nKolPartii=0;
	m_nSkolkoViigralIgrok=0;
	m_nPorageniiIgroka=0;

	NomerOblogki=0;

	m_nSkorost_Igri=500;
	m_bVividitOtchet=TRUE;// выводить отчет

	 m_nVzyatkaCompa=0;
	 m_nVzyatkaIgroka=0;
}

CKozelDoc::~CKozelDoc()
{
	
}

BOOL CKozelDoc::OnNewDocument()
{
		
//int Vibor=0;
//Vibor=AfxMessageBox("Вы хотите начать новую игру?",MB_OKCANCEL);
//if(Vibor!=1)
//	return 1;


	if (!CDocument::OnNewDocument())
		return FALSE;

	New_IGRA();
	return TRUE;
}




// CKozelDoc serialization

void CKozelDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar <<m_bCheiXod<<(LONG)m_nKolSigranIgr<<(LONG)m_nSkolkoViigralIgrok<<(LONG)m_nSkolkoViigralComp<<(LONG)GAME_STATE
			<<(LONG)m_nKozir<<(LONG)m_nShtrafOchkiCompa
			<<(LONG)m_nShtrafOchkiIgroka <<(LONG)m_nKolSigranIgr
			<<(LONG)m_nKolPartii<<(LONG)m_nPorageniiIgroka
			<<(LONG)NomerOblogki<<(LONG)m_nSkorost_Igri;
	}
	else
	{
		// TODO: add loading code here
		ar >>m_bCheiXod>>(LONG&)m_nKolSigranIgr>>(LONG&)m_nSkolkoViigralIgrok>>(LONG&)m_nSkolkoViigralComp>>(LONG&)GAME_STATE
			>>(LONG&)m_nKozir>>(LONG&)m_nShtrafOchkiCompa
			>>(LONG&)m_nShtrafOchkiIgroka>>(LONG&)m_nKolSigranIgr
			>>(LONG&)m_nKolPartii>>(LONG&)m_nPorageniiIgroka
			>>(LONG&)NomerOblogki>>(LONG&)m_nSkorost_Igri;

	}

	m_Koloda.Serialize(ar);
m_KartiCompa.Serialize(ar);
m_KartiIgroka.Serialize(ar);

m_VzjatkaIgroka.Serialize(ar);
m_VzjatkaCompa.Serialize(ar);

}



// CKozelDoc diagnostics

#ifdef _DEBUG
void CKozelDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKozelDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CKozelDoc commands

//BOOL CKozelDoc::OnOpenDocument(LPCTSTR lpszPathName)
//{
//	if (!CDocument::OnOpenDocument(lpszPathName))
//		return FALSE;
//
//	// TODO:  Add your specialized creation code here
//
//	return TRUE;
//}

void CKozelDoc::DeleteContents()
{
	// TODO: Add your specialized code here and/or call the base class

OchistitCpiski();

m_nKolSigranIgr=0;
m_nKolPartii=0;
m_nSkolkoViigralIgrok=0;
m_nShtrafOchkiCompa=0;
m_nShtrafOchkiIgroka=0;
int m_nPorageniiIgroka=0;

	CDocument::DeleteContents();
}

BOOL CKozelDoc::RasdatKarti()
{
//=========
	CKarta* pKarta;
	int x=150; int y1=280; int y2=30; int x1=0, x2=0; //координаты
	//==												карты
int m_nSkolkoRazdatKart;//общее для компа и игрока

POSITION position_Compa;
POSITION position_Igroka;

POSITION position_Compa2;
POSITION position_Igroka2;

CKarta* pKarta_Compa;
CKarta* pKarta_Igroka;

position_Compa=m_KartiCompa.GetHeadPosition();
position_Igroka=m_KartiIgroka.GetHeadPosition();

position_Compa2=position_Compa;
position_Igroka2=position_Igroka;
BOOL IgrocSovpad=FALSE;// Произошло ли совпадение по координате
BOOL CompSovpad=FALSE;//1- не произ, значит добавить карту в с этим
					//координатами
//если колода пустая раздавать уже нечего
//если у игроков 5 карт, тоже не надо раздавать
	if((m_Koloda.GetCount()==0) | (m_KartiCompa.GetCount()==5))
		return 0;

	
m_nSkolkoRazdatKart=(int)(5-m_KartiIgroka.GetCount());

if(m_nSkolkoRazdatKart==5)//у игроков нет карт на руках
{
	for(int i=0; i<m_nSkolkoRazdatKart; i++)
	{

		if(m_Koloda.GetCount()==0)
			return 0;

		m_KartiIgroka.AddHead(m_Koloda.GetHead());//карта игроку
		pKarta=m_Koloda.GetHead();
		pKarta->m_ptPologKarti=CPoint(x,y1);
		m_Koloda.RemoveHead();	

		m_KartiCompa.AddHead(m_Koloda.GetHead());//карта компу
		pKarta=m_Koloda.GetHead();
		pKarta->m_ptPologKarti=CPoint(x,y2);
		m_Koloda.RemoveHead();


	x+=71;
	}//for
}//if
else if ((m_nSkolkoRazdatKart!=5) & (m_nSkolkoRazdatKart!=0)) // если игрокам нужно раздать меньше чем пять карт
{

 //===========================================================
//Для каждой позиции карты проверяю есть ли совпадения по координа	
	x1=x;
	x2=x;
for(int g=0; g<5; g++)
 {
	 //===== если колода пуста выход
	

	//перебираю все карты которые есть у игроков
	while(x1<=434)//крутится пока кол-во карт не станет больше чем у игро
	{
		position_Compa=position_Compa2;
		//инициирую заново
		CompSovpad=FALSE;
		for( int i=0; i<m_KartiIgroka.GetCount(); i++)
		{
			pKarta_Compa=m_KartiCompa.GetNext(position_Compa);
			pKarta_Compa->m_bPokaziv=FALSE;
			if (pKarta_Compa->m_ptPologKarti.x==x1)
			{
				CompSovpad=TRUE;//..совпадение было
			}//if
		
		}//for
	if(!CompSovpad)//добавляю в карты компа
	{
		if(m_Koloda.GetCount()==0)
			return 0;

		m_KartiCompa.AddTail(m_Koloda.GetHead());//карта компу

		pKarta=m_Koloda.GetHead();
		pKarta->m_ptPologKarti=CPoint(x1,y2);
		
		m_Koloda.RemoveHead();
		break;
	}//if

	if(m_KartiCompa.GetCount()!=m_KartiIgroka.GetCount())
		break;

		x1+=71;
	}//while

	while(x2<=434)//крутится пока не сравняется кол-во карт с компом
	{
		position_Igroka=position_Igroka2;
		IgrocSovpad=FALSE;
		for( int i=0; i<m_KartiIgroka.GetCount(); i++)
		{
			pKarta_Igroka=m_KartiIgroka.GetNext(position_Igroka);
			if (pKarta_Igroka->m_ptPologKarti.x==x2)
			{
				IgrocSovpad=TRUE;//совпадение было
			}//if
			
		}//for
	if(!IgrocSovpad)//добавляю в карты игрока карты 
	{
		if(m_Koloda.GetCount()==0)
			return 0;

		m_KartiIgroka.AddTail(m_Koloda.GetHead());//карта игроку
		
		pKarta=m_Koloda.GetHead();
		pKarta->m_ptPologKarti=CPoint(x2,y1);
		
		m_Koloda.RemoveHead();
		break;
	}//if

	if(m_KartiCompa.GetCount()==m_KartiIgroka.GetCount())
		break;

		x2+=71;

	}//while
	
 }//for

 //=============================================================
}//else

//==========спрятать карты компа

position_Compa=m_KartiCompa.GetHeadPosition();
for(int k=0; k<m_KartiCompa.GetCount(); k++)
{
	pKarta_Compa=m_KartiCompa.GetNext(position_Compa);
	pKarta_Compa->m_bPokaziv=FALSE;
}//for
//----------------------------------

return 1;
}

int CKozelDoc::OpredKozir()
{
CKarta* pKarta;

pKarta=m_Koloda.GetTail();
m_nKozir=pKarta->m_nMast;

return m_nKozir;
}

void CKozelDoc::PodschetOchkov()
{
	POSITION position_Compa;
	POSITION position_Igroka;
CKarta* pKartaCompa;
CKarta* pKartaIgroka;

//int m_nVzyatkaCompa=0;
//int m_nVzyatkaIgroka=0;

//считаем у компа
	position_Compa=m_VzjatkaCompa.GetHeadPosition();
for(int i=0; i< m_VzjatkaCompa.GetCount(); i++)
{
	pKartaCompa=m_VzjatkaCompa.GetNext(position_Compa);
	switch(pKartaCompa->m_nMast)
	{
	case 1:
		switch(pKartaCompa->m_nZnachenie)
		{
		/*case 1:
		case 2:
		case 3:
		case 4:*/
		case 5:
			m_nVzyatkaCompa+=2;
			break;
		case 6:
			m_nVzyatkaCompa+=3;
			break;
		case 7:
			m_nVzyatkaCompa+=4;
			break;
		case 8:
			m_nVzyatkaCompa+=10;
			break;
		case 9:
			m_nVzyatkaCompa+=11;
			break;
		}//switch
		break;
	case 2:
		switch(pKartaCompa->m_nZnachenie)
		{
		/*case 1:
		case 12:
		case 3:
		case 4:*/
		case 15:
			m_nVzyatkaCompa+=2;
			break;
		case 16:
			m_nVzyatkaCompa+=3;
			break;
		case 17:
			m_nVzyatkaCompa+=4;
			break;
		case 18:
			m_nVzyatkaCompa+=10;
			break;
		case 19:
			m_nVzyatkaCompa+=11;
			break;
		}//switch
		break;
	case 3:
		switch(pKartaCompa->m_nZnachenie)
		{
		/*case 1:
		case 2:
		case 3:
		case 4:*/
		case 25:
			m_nVzyatkaCompa+=2;
			break;
		case 26:
			m_nVzyatkaCompa+=3;
			break;
		case 27:
			m_nVzyatkaCompa+=4;
			break;
		case 28:
			m_nVzyatkaCompa+=10;
			break;
		case 29:
			m_nVzyatkaCompa+=11;
			break;
		}//switch
		break;
	case 4:
		switch(pKartaCompa->m_nZnachenie)
		{
		/*case 1:
		case 2:
		case 3:
		case 4:*/
		case 35:
			m_nVzyatkaCompa+=2;
			break;
		case 36:
			m_nVzyatkaCompa+=3;
			break;
		case 37:
			m_nVzyatkaCompa+=4;
			break;
		case 38:
			m_nVzyatkaCompa+=10;
			break;
		case 39:
			m_nVzyatkaCompa+=11;
			break;
		}//switch
		break;
	}//switch
	
}//for

	//===================================cчитаем у игрока
position_Igroka=m_VzjatkaIgroka.GetHeadPosition();
for(int i=0; i< m_VzjatkaIgroka.GetCount(); i++)
{
	pKartaIgroka=m_VzjatkaIgroka.GetNext(position_Igroka);
	switch(pKartaIgroka->m_nMast)
	{
	case 1:
		switch(pKartaIgroka->m_nZnachenie)
		{
		/*case 1:
		case 2:
		case 3:
		case 4:*/
		case 5:
			m_nVzyatkaIgroka+=2;
			break;
		case 6:
			m_nVzyatkaIgroka+=3;
			break;
		case 7:
			m_nVzyatkaIgroka+=4;
			break;
		case 8:
			m_nVzyatkaIgroka+=10;
			break;
		case 9:
			m_nVzyatkaIgroka+=11;
			break;
		}//switch
		break;
	case 2:
		switch(pKartaIgroka->m_nZnachenie)
		{
		/*case 1:
		case 12:
		case 3:
		case 4:*/
		case 15:
			m_nVzyatkaIgroka+=2;
			break;
		case 16:
			m_nVzyatkaIgroka+=3;
			break;
		case 17:
			m_nVzyatkaIgroka+=4;
			break;
		case 18:
			m_nVzyatkaIgroka+=10;
			break;
		case 19:
			m_nVzyatkaIgroka+=11;
			break;
		}//switch
		break;
	case 3:
		switch(pKartaIgroka->m_nZnachenie)
		{
		/*case 1:
		case 2:
		case 3:
		case 4:*/
		case 25:
			m_nVzyatkaIgroka+=2;
			break;
		case 26:
			m_nVzyatkaIgroka+=3;
			break;
		case 27:
			m_nVzyatkaIgroka+=4;
			break;
		case 28:
			m_nVzyatkaIgroka+=10;
			break;
		case 29:
			m_nVzyatkaIgroka+=11;
			break;
		}//switch
		break;
	case 4:
		switch(pKartaIgroka->m_nZnachenie)
		{
		/*case 1:
		case 2:
		case 3:
		case 4:*/
		case 35:
			m_nVzyatkaIgroka+=2;
			break;
		case 36:
			m_nVzyatkaIgroka+=3;
			break;
		case 37:
			m_nVzyatkaIgroka+=4;
			break;
		case 38:
			m_nVzyatkaIgroka+=10;
			break;
		case 39:
			m_nVzyatkaIgroka+=11;
			break;
		}//switch
		break;
	}//switch
	
}//for

//==============
TCHAR str2[55];
wsprintf(str2,"   Счет партии по очкам: \n\
у Игрока %d \n\
у Компа %d",m_nVzyatkaIgroka,m_nVzyatkaCompa);

//AfxMessageBox(str2,0,0);

//Нужно ли выводить отчет
if(m_bVividitOtchet==TRUE)
{
	COtchetDLG dlg;
	dlg.DoModal();
}

//очки подсчитали, теперь выдать сообщение о победителе в партии.
if(m_nVzyatkaCompa > m_nVzyatkaIgroka)
{//комп набрал больше очков
	if(m_nVzyatkaIgroka==0)
	{//6 
		m_nShtrafOchkiIgroka+=6;
		/*m_nShtrafOchkiCompa+=0;*/
	}//
	else if(m_nVzyatkaIgroka<31)
	{//4
		m_nShtrafOchkiIgroka+=4;
		/*m_nShtrafOchkiCompa+=0;*/
	}
	else if((m_nVzyatkaIgroka>=31) & (m_nVzyatkaIgroka<60))
	{//2
		m_nShtrafOchkiIgroka+=2;
		/*m_nShtrafOchkiCompa+=0;*/
	}

}
else if(m_nVzyatkaCompa == m_nVzyatkaIgroka)
{//яйца 0::0
		m_nShtrafOchkiIgroka+=0;
		m_nShtrafOchkiCompa+=0;
}
else if(m_nVzyatkaCompa < m_nVzyatkaIgroka)

{//игрок набрал больше очков
	if(m_nVzyatkaCompa==0)
	{//6 
		/*m_nShtrafOchkiIgroka+=0;*/
		m_nShtrafOchkiCompa+=6;
	}//
	else if(m_nVzyatkaCompa<31)
	{//4
		/*m_nShtrafOchkiIgroka=0;*/
		m_nShtrafOchkiCompa+=4;
	}
	else if((m_nVzyatkaCompa>=31) & (m_nVzyatkaCompa<60))
	{//2
	/*	m_nShtrafOchkiIgroka+=0;*/
		m_nShtrafOchkiCompa+=2;
	}
}//if
//Теперь проверить победу в игре
//===увеличиваю кол сыгран партий
m_nKolPartii++;

//---------------
TCHAR str[50];
wsprintf(str,"Общий счет: \n\
у Игрока %d \n\
у Компа %d",m_nShtrafOchkiIgroka,m_nShtrafOchkiCompa);

//AfxMessageBox(str,0,0);

m_nVzyatkaCompa=0;
m_nVzyatkaIgroka=0;

if(m_nShtrafOchkiIgroka>=12)
{
	m_nSkolkoViigralComp++;
	AfxMessageBox("К болшому сожалению вы проиграли!!",0,0);
	m_nShtrafOchkiCompa=0;
	m_nShtrafOchkiIgroka=0;
	m_nKolSigranIgr++;
	m_nKolPartii=0;
	m_nPorageniiIgroka++;
}
else if(m_nShtrafOchkiCompa>=12)
{
	m_nSkolkoViigralIgrok++;
	m_nShtrafOchkiCompa=0;
	m_nShtrafOchkiIgroka=0;
	m_nKolSigranIgr++;
	m_nKolPartii=0;
	AfxMessageBox("Поздравляю вы выиграли!",0,0);
}//if

//
New_IGRA();
InvalidateRect(NULL,CRect(0,0,600,600),1);
//Победа достигнута то 

}


BOOL CKozelDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	//CKozelView* pView
	if (!CDocument::OnOpenDocument(lpszPathName))
	{
	InvalidateRect(NULL,CRect(0,0,800,600),1);
		return FALSE;
	}

	// TODO:  Add your specialized creation code here
	//CView::InvalidateRect(NULL );
	//GAME_STATE=COMP_XODIT;
	return TRUE;
}

void CKozelDoc::New_IGRA()
{
	//зачищаю все списки на всякий случай !!
	OchistitCpiski();

int m_nMasSluchChisel[36];
	int VremMas[2][36];
	int VremMas2[2][36];

srand( (unsigned)time( NULL ) );
for(int j=0; j<36; j++)//заполняю массив случайными числами
{
	VremMas[0][j]=rand();
	VremMas[1][j]=j;
}
	
for(int n=0; n<36; n++)
{
	for(int k=36-1; k>n; --k)

	if(VremMas[0][k-1]>VremMas[0][k])
	{
		VremMas2[0][n]= VremMas[0][k-1];
		VremMas2[1][n]= VremMas[1][k-1];

		VremMas[0][k-1]=VremMas[0][k];
		VremMas[1][k-1]=VremMas[1][k];

		VremMas[0][k]= VremMas2[0][n];
		VremMas[1][k]= VremMas2[1][n];

	}

}
for(int t=0; t<36; t++)
{
m_nMasSluchChisel[t]=VremMas[1][t];
}

//==============

//---------------------------формирование колоды
	int l=0;
for(int i=0; i<36; i++)
{
	l=m_nMasSluchChisel[i];
	//заглушка, формирую нужную колоду
//l=i;
	CKarta* pKarta= new CKarta;
	if((l<9))
	{
	pKarta->m_nZnachenie=(l+1);
	pKarta->m_nMast=1;//Бубы
	}
	else if((l>8) & (l<18))
	{
	pKarta->m_nZnachenie=l+2;
		pKarta->m_nMast=2;//Черви
	}
	else if((l>17) & (l<27))
	{
	pKarta->m_nZnachenie=l+3;
		pKarta->m_nMast=3;//Пики
	}
	else if((l>26) & (l<36))
	{
	pKarta->m_nZnachenie=l+4;
		pKarta->m_nMast=4;//крести
	}

	pKarta->m_bPokaziv=TRUE;//рисовать карту
	m_Koloda.AddHead(pKarta);
}
//----------------------------------

OpredKozir();
int koz=OpredKozir();
RasdatKarti();

//==============установка начальных данных


//-----------начальное состояние новой игры
if(m_bCheiXod==0)
{
GAME_STATE=IGROK_XODIT;//ход игрока
m_bCheiXod=IGROK_XODIT;
}
else if (m_bCheiXod==IGROK_XODIT)
{
GAME_STATE=COMP_XODIT;
m_bCheiXod=COMP_XODIT;
}
else if(m_bCheiXod=COMP_XODIT)
{
GAME_STATE=IGROK_XODIT;//ход игрока
m_bCheiXod=IGROK_XODIT;

}
//удаление взяток
}

void CKozelDoc::OchistitCpiski()
{
while(m_Koloda.GetHeadPosition())
{
	delete m_Koloda.RemoveHead();
}

while(m_KartiIgroka.GetHeadPosition())
{
	delete m_KartiIgroka.RemoveHead();
}

while(m_KartiCompa.GetHeadPosition())
{
	delete m_KartiCompa.RemoveHead();
}

while(m_VzjatkaIgroka.GetHeadPosition())
{
	delete m_VzjatkaIgroka.RemoveHead();
}

while(m_VzjatkaCompa.GetHeadPosition())
{
	delete m_VzjatkaCompa.RemoveHead();
}
}

BOOL CKozelDoc::SaveModified()
{
	// TODO: Add your specialized code here and/or call the base class
CString put;
CFileDialog dlg(FALSE,0,0,OFN_HIDEREADONLY);

dlg.m_pOFN->lpstrFilter="*.kzl";
dlg.m_pOFN->nFilterIndex=1;

int Vibor=AfxMessageBox("Вы хотите сохранить игру?",MB_OKCANCEL);

if(Vibor==1)
{
	int otvet =(int)dlg.DoModal();
		if(otvet==1)
		{
			put=dlg.GetPathName();
			put+=".kzl";
			OnSaveDocument(put);
		}
}

	return CDocument::SaveModified();
}

BOOL CKozelDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: Add your specialized code here and/or call the base class

	return CDocument::OnSaveDocument(lpszPathName);
}

void CKozelDoc::OnCloseDocument()
{
	// TODO: Add your specialized code here and/or call the base class
	PlaySound(0,0,SND_PURGE);


	CDocument::OnCloseDocument();
}

// RecvSok.cpp : implementation file
//

#include "stdafx.h"
#include "Krest.h"
#include "RecvSok.h"
#include "MainFrm.h"

extern int Mas[9];
extern int Mas2[9];
// CRecvSok
extern int GAME_VID_IGRI;
extern int GAME_SOST;
extern BOOL NOVAYA_IGRA;
extern BOOL Perecl;
extern int line;

CRecvSok::CRecvSok()
{
	//NOVAYA_IGRA=0;// �� ���� ������� � ��� ����� ����
}

CRecvSok::~CRecvSok()
{
}


// CRecvSok member functions

void CRecvSok::OnClose(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class
			AfxMessageBox("������ ����� �� ������� ����",0,0);
	CMainFrame* pMF;
		
	pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;
	delete this;
	delete pMF->pServSok;
	pMF->pServSok=0;

		GAME_VID_IGRI=SOK_NET;
		GAME_SOST=GAME_FINISH;
		pMF->OnNovayaIgra();
	/*	this=0;*/
	CSocket::OnClose(nErrorCode);
}

void CRecvSok::OnReceive(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class
	CMainFrame* pMF;
	Receive(Mas2,sizeof(Mas));
	

	pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;

	int SUM=0;
	for(int i=0; i<9; i++)
	{
		SUM+=Mas2[i];
	}
	
		if(SUM==99){
			
			if(IDOK==AfxMessageBox("�� ������ ������ ����� ����??",MB_OKCANCEL,0)){
				if(NOVAYA_IGRA==FALSE){
					NOVAYA_IGRA=TRUE;
					pMF->OnNovayaIgra();
					//�������, ��� �������� � ����� �����
				for(int i=0; i<9; i++)
					Mas2[i]=13;
				Send(Mas2,sizeof(Mas2));

					NOVAYA_IGRA=FALSE;
					}//if
				return;
			}//if
			else
			{//�� ���������� �� ����� ����
				for(int i=0; i<9; i++)
					Mas2[i]=12;
				Send(Mas2,sizeof(Mas2));
				return;
			}
			
		}//if
		else if(SUM==108)//12,12,12,12.....
		{//
			//memset(Mas,0,sizeof(Mas));
				return;
		}
		else if(SUM==117)//12,12,12,12.....
		{//
			ZeroMemory(Mas,sizeof(Mas));
			pMF->KillTimer(777);
			pMF->SetTimer(555,200,0);
			pMF->pobeda=false;
			pMF->proigrish=false;
			pMF->nichya=false;
			line=0;
			pMF->FlagPobed=FALSE;
			pMF->InvalidateRect(CRect(0,25,400,500));
			return;
		}
		else if(SUM==126)//12,12,12,12.....
		{//����� ������� �� ����
			//AfxMessageBox("������ ����� �� ������� ����",0,0);
			return;
		}
		else{
			memcpy(Mas,Mas2,sizeof(Mas2));
			}

	for(int i=0; i<9; i++)
	{
		if(Mas[i]==4)
			Mas[i]=1;
		else if(Mas[i]==1)
			Mas[i]=4;
	}//for
	NOVAYA_IGRA=FALSE;
	GAME_SOST=GAME_XOD_SERVERA;
	pMF->InvalidateRect(CRect(120,100,270,250));
	CSocket::OnReceive(nErrorCode);
}

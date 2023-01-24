// KlientSok.cpp : implementation file
//

#include "stdafx.h"

#include "Krest.h"
#include "KlientSok.h"
#include "MainFrm.h"

extern int Mas[9];
extern int Mas2[9];

extern int GAME_SOST;
extern int line;
extern BOOL NOVAYA_IGRA;
extern int  GAME_VID_IGRI;
BOOL Perecl=TRUE; //разрешена модификаци€ состо€ни€ игры
// CKlientSok

CKlientSok::CKlientSok()
{
	//NOVAYA_IGRA=FALSE ;
}

CKlientSok::~CKlientSok()
{
}


// CKlientSok member functions

void CKlientSok::OnReceive(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class
	//int Mas1[9];
	CMainFrame* pMF;

	Receive(Mas2,sizeof(Mas));
	//===============
	int SUM=0;
	pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;
	
	for(int i=0; i<9; i++)
		{
			SUM+=Mas2[i];
		}
	
			if(SUM==99){
			
				if(IDOK==AfxMessageBox("¬ы хотите начать новую игру??",MB_OKCANCEL,0)){
					if(NOVAYA_IGRA==FALSE){
						NOVAYA_IGRA=TRUE;
						pMF->OnNovayaIgra();
							//передаю, что согласен с новой игрой
				for(int i=0; i<9; i++)
					Mas2[i]=13;
				Send(Mas2,sizeof(Mas2));

						NOVAYA_IGRA=FALSE;
					}//if
				return;
			}
			else
			{//не согласилс€ на новую игру
				for(int i=0; i<9; i++)
					Mas2[i]=12;
				OnSend(1);
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
		{//выход клиента из сети
			AfxMessageBox("—ервер вышел из сетевой игры",0,0);
			pMF->OnVirubitSet();
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
	GAME_SOST=GAME_XOD_KLIENTA;
	pMF->InvalidateRect(CRect(120,100,270,250));

	CSocket::OnReceive(nErrorCode);
}

void CKlientSok::OnSend(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class
	

	if(nErrorCode==0)
		Send(Mas,sizeof(Mas));
	else if(nErrorCode==1)//передача вопроса
		Send(Mas2,sizeof(Mas2));
	//GAME_SOST=GAME_XOD_SERVERA;//уже установлен
	CSocket::OnSend(nErrorCode);
}

void CKlientSok::OnClose(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class
		//AfxMessageBox("—в€зь разорвана Klient!",0,0);
	CMainFrame* pMF;
		
	pMF=(CMainFrame*)AfxGetApp()->m_pMainWnd;
	//delete this;
	delete pMF->pKlientSok;
	pMF->pKlientSok=0;

		GAME_VID_IGRI=SOK_NET;
		GAME_SOST=GAME_FINISH;
	CSocket::OnClose(nErrorCode);
}

// ServerSok.cpp : implementation file
//

#include "stdafx.h"

#include "Krest.h"

#include "ServerSok.h"
//#include "MainFrm.h"

extern int GAME_SOST;
extern int Mas[9];
extern BOOL NOVAYA_IGRA;
extern int Mas2[9];

// CServerSok

CServerSok::CServerSok()
{
	pKlientSock=0;
}

CServerSok::~CServerSok()
{
	/*if(pKlientSock)
		delete pKlientSock;*/
}


// CServerSok member functions

void CServerSok::OnAccept(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class

	/*if(pKlientSock==0)
			return;*/
	/*if(GAME_VID_IGRI==SOK_SERVER)
		return;*/

pKlientSock=new CRecvSok;

if(!Accept(*pKlientSock)){
			AfxMessageBox("Соединится не удалось!",0,0);
}
	GAME_SOST=GAME_XOD_SERVERA;//первый ход у сервера

	CSocket::OnAccept(nErrorCode);
}

//void CServerSok::OnClose(int nErrorCode)
//{
//	// TODO: Add your specialized code here and/or call the base class
//	AfxMessageBox("Связь разорвана Server!",0,0);
//	
//	CSocket::OnClose(nErrorCode);
//}

void CServerSok::OnSend(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class
	/*int SUM=0;
	for(int i=0; i<9; i++)
	{
		SUM+=Mas[i];
	}*/
	
		/*if(SUM==99)
			NOVAYA_IGRA=TRUE;*/
	if(nErrorCode==0)
		pKlientSock->Send(Mas,sizeof(Mas));
	else if(nErrorCode==1)//передача вопроса
		pKlientSock->Send(Mas2,sizeof(Mas2));

	CSocket::OnSend(nErrorCode);
}

void CServerSok::OnReceive(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class

	CSocket::OnReceive(nErrorCode);
}

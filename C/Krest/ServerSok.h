#pragma once

#include "RecvSok.h"


// CServerSok command target

class CServerSok : public CSocket
{
public:
	CRecvSok* pKlientSock;

	CServerSok();
	virtual ~CServerSok();
	virtual void OnAccept(int nErrorCode);
//	virtual void OnClose(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};



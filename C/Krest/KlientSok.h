#pragma once
//#include "stdafx.h"


// CKlientSok command target

class CKlientSok : public CSocket
{
public:
	CKlientSok();
	//BOOL NOVAYA_IGRA;
	virtual ~CKlientSok();
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};



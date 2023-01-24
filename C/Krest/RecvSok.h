#pragma once



// CRecvSok command target

class CRecvSok : public CSocket
{
public:
	//BOOL NOVAYA_IGRA;
	CRecvSok();
	virtual ~CRecvSok();
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};



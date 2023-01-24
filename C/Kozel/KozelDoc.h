// KozelDoc.h : interface of the CKozelDoc class
//

#include "Karta.h"
#pragma once

typedef CTypedPtrList<CObList, CKarta* > CKartaList;


class CKozelDoc : public CDocument
{
protected: // create from serialization only
	CKozelDoc();
	DECLARE_DYNCREATE(CKozelDoc)

// Attributes
public:
CKartaList m_Koloda;
CKartaList m_KartiIgroka;
CKartaList m_KartiCompa;
CKartaList m_VzjatkaIgroka;
CKartaList m_VzjatkaCompa;

//������
//====���������� ���������� ������������ ��������� ����
int GAME_STATE;
//1-��� ������, 2-����� ������, 3 -����� ����������,
//6-����� �����, 7-��� �����, 8- ���� ����������
//11-
//==============
int m_nKozir;//1- ����, 2-����� , 3- ����, 4-������ .
int NomerOblogki;

int m_nSkolkoViigralIgrok;//������� ��� ������� �����
int m_nSkolkoViigralComp;//������� ��� ������� ����

int m_nShtrafOchkiCompa;// ������������� ����
int m_nShtrafOchkiIgroka;

int m_nKolSigranIgr;
int m_nKolPartii;
int m_nPorageniiIgroka;

int m_bCheiXod; //1-������, 0-�����

int m_nSkorost_Igri;

int m_nVzyatkaCompa;
int m_nVzyatkaIgroka;


BOOL m_bComp_Biet_Skidivaet; //0-���� 1- ��������� ������ �����
BOOL m_bIgroc_Biet_Skidivaet;//

BOOL m_bAVTOPILOT;//1-���� ������ ��� � �����
//
//BOOL m_bPobedilComp;//1
//BOOL m_bPobedilIgrok;//1,PobedilComp=0


//==================�������
BOOL RasdatKarti();
int  OpredKozir();//���������� ������
void PodschetOchkov();
void New_IGRA();
void OchistitCpiski();

// Operations
public:

// Overrides
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CKozelDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DeleteContents();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);

protected:
	virtual BOOL SaveModified();
public:
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	// 1- �������� ����� �� ������, 0- �� �������� ����� �� ������
	bool m_bVividitOtchet;
	virtual void OnCloseDocument();
};



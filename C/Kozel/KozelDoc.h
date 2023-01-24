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

//Данные
//====Глобальная переменная обозначающая состояние игры
int GAME_STATE;
//1-ход игрока, 2-ответ игрока, 3 -игрок сбрасывает,
//6-ответ компа, 7-ход компа, 8- комп сбрасывает
//11-
//==============
int m_nKozir;//1- бубы, 2-черви , 3- пики, 4-крести .
int NomerOblogki;

int m_nSkolkoViigralIgrok;//сколько раз выиграл игрок
int m_nSkolkoViigralComp;//сколько раз выиграл комп

int m_nShtrafOchkiCompa;// характеризуют счет
int m_nShtrafOchkiIgroka;

int m_nKolSigranIgr;
int m_nKolPartii;
int m_nPorageniiIgroka;

int m_bCheiXod; //1-игрока, 0-компа

int m_nSkorost_Igri;

int m_nVzyatkaCompa;
int m_nVzyatkaIgroka;


BOOL m_bComp_Biet_Skidivaet; //0-бьет 1- скидывает Нужная перем
BOOL m_bIgroc_Biet_Skidivaet;//

BOOL m_bAVTOPILOT;//1-комп играет сам с собой
//
//BOOL m_bPobedilComp;//1
//BOOL m_bPobedilIgrok;//1,PobedilComp=0


//==================Функции
BOOL RasdatKarti();
int  OpredKozir();//возвращает козырь
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
	// 1- выводить отчет по партии, 0- не выводить отчет по партии
	bool m_bVividitOtchet;
	virtual void OnCloseDocument();
};



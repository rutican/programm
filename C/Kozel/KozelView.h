// KozelView.h : interface of the CKozelView class
//


#pragma once


class CKozelView : public CView
{
protected: // create from serialization only
	CKozelView();
	DECLARE_DYNCREATE(CKozelView)

// Attributes
public:
	CKozelDoc* GetDocument() const;
	CImageList m_ImBlac;
	CImageList m_ImRed;
	CImageList m_ImOblogki;
	CImageList m_ImMast;
	
	CBitmap bmBlac;
	CBitmap bmRed;
	CBitmap bmOblogki;
	CBitmap bmMast;

	/*CBitmap bmZvetok;
	CImageList m_ImZvetok;*/

	CBitmap* m_pBitmap;
	CDC* pDCm;

	BOOL Musik;// 1 играет 0 молчит
	//какая загружается обложка
// Operations
public://функции

void RisovatZveti(CDC* pDC);

void RisovatKolodu(CDC* pDC);
void RisovatKarti(CDC* pDC,CKartaList* pKartiIgrILICompa);
void RisovatKartiCompa(CDC* pDC);
void PokazatKozir( CDC* pDC);
void RisovatKUCHI(CDC* pDC);
//..===========автопилот
void Sxodit();
void Udarit();
void Sbrosit();
////==========================
//====функции интеллекта компа верчсия №2
int ProverkaUDARA(int*); // проверяет сможет ли игрок ударить карты или нет// возвращает 1 если бьет 0 - если нет

int PodschetOchkov(CKarta* );

void CompXodit2();


//=====

// Overrides
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CKozelView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
//	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
public:
	virtual void OnInitialUpdate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSxodit();
	afx_msg void OnUpdateSxodit(CCmdUI *pCmdUI);
	afx_msg void OnCompBiet();
	afx_msg void OnRazdat();
	afx_msg void OnCompXodit();
	afx_msg void OnUbrat();
	afx_msg void OnCompSkidivaet();
	afx_msg void OnUpdateCompSkidivaet(CCmdUI *pCmdUI);
	afx_msg void OnUpdateCompBiet(CCmdUI *pCmdUI);
	afx_msg void OnUpdateRazdat(CCmdUI *pCmdUI);
	afx_msg void OnUpdateCompXodit(CCmdUI *pCmdUI);
	afx_msg void OnUdarit();
	afx_msg void OnUpdateUdarit(CCmdUI *pCmdUI);
	afx_msg void OnSbrosit();
	afx_msg void OnUpdateSbrosit(CCmdUI *pCmdUI);
	afx_msg void OnUpdateUbrat(CCmdUI *pCmdUI);
	afx_msg void OnTimer(UINT nIDEvent);
protected:

public:
	afx_msg void OnOblogki();
	afx_msg void OnGameSpid1();
	afx_msg void OnUpdateGameSpid1(CCmdUI *pCmdUI);
	afx_msg void OnGameSpid2();
	afx_msg void OnUpdateGameSpid2(CCmdUI *pCmdUI);
	afx_msg void OnGameSpid3();
	afx_msg void OnUpdateGameSpid3(CCmdUI *pCmdUI);
	afx_msg void OnGameSpid4();
	afx_msg void OnUpdateGameSpid4(CCmdUI *pCmdUI);
	afx_msg void OnPaint();
	afx_msg void OnAvtopilot();
	afx_msg void OnUpdateAvtopilot(CCmdUI *pCmdUI);
	afx_msg void On172();
	afx_msg void OnUpdate172(CCmdUI *pCmdUI);
	afx_msg void OnMuzik();
	afx_msg void OnUpdateMuzik(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // debug version in KozelView.cpp
inline CKozelDoc* CKozelView::GetDocument() const
   { return reinterpret_cast<CKozelDoc*>(m_pDocument); }
#endif


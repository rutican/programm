#pragma once
#include "KozelDoc.h"
#include "KozelView.h"

// COblogkiDLG dialog

class COblogkiDLG : public CDialog
{
	DECLARE_DYNAMIC(COblogkiDLG)
public:
	int m_nNomOblogki;
	int m_nNomStarojOblogki;
	CImageList m_ImOblogki;

	CBitmap bmOblogki;
	CKozelView* pView;
	CKozelDoc* pDoc;

public:
	COblogkiDLG(CWnd* pParent = NULL);   // standard constructor
	virtual ~COblogkiDLG();

// Dialog Data
	enum { IDD = IDD_DLG_OBLOGKI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedCancel();
};

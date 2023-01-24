#pragma once
#include "KozelDoc.h"
#include "KozelView.h"

// COtchetDLG dialog

class COtchetDLG : public CDialog
{
	DECLARE_DYNAMIC(COtchetDLG)

public:
	COtchetDLG(CWnd* pParent = NULL);   // standard constructor
	virtual ~COtchetDLG();
CKozelDoc* pDoc;
CKozelView* pView;

int OTOBRAGAT;

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedSmena();
};

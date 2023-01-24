// DlgIP.cpp : implementation file
//

#include "stdafx.h"
#include "Krest.h"
#include "DlgIP.h"


// CDlgIP dialog

IMPLEMENT_DYNAMIC(CDlgIP, CDialog)
CDlgIP::CDlgIP(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgIP::IDD, pParent)
	, m_strIP(_T(""))
{
}

CDlgIP::~CDlgIP()
{
}

void CDlgIP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_IP, m_strIP);
}


BEGIN_MESSAGE_MAP(CDlgIP, CDialog)
END_MESSAGE_MAP()


// CDlgIP message handlers

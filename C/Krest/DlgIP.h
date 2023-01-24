#pragma once


// CDlgIP dialog

class CDlgIP : public CDialog
{
	DECLARE_DYNAMIC(CDlgIP)

public:
	CDlgIP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgIP();

// Dialog Data
	enum { IDD = IDD_IP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_strIP;
};

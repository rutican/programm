// Karta.cpp : implementation file
//

#include "stdafx.h"
#include "Kozel.h"
#include "Karta.h"

IMPLEMENT_SERIAL(CKarta,CObject,0)
// CKarta

CKarta::CKarta()
{
	m_nSOSTOYANIE_KARTI=0;
	m_bPokaziv=TRUE;// рисовать карту.
}

CKarta::~CKarta()
{
}


// CKarta member functions

void CKarta::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar<< m_ptPologKarti << m_bPokaziv<<(LONG)m_nZnachenie
			<<(LONG)m_nSOSTOYANIE_KARTI<<(LONG)m_nMast;
	}
	else
	{	// loading code
		ar  >> m_ptPologKarti >> m_bPokaziv >>(LONG&)m_nZnachenie
			>>(LONG&)m_nSOSTOYANIE_KARTI>>(LONG&)m_nMast;

	}
}

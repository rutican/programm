#pragma once



// CKarta command target

class CKarta : public CObject
{
	  DECLARE_SERIAL(CKarta)

public:
	CKarta();
int m_nZnachenie;//ќпредел€ет масть и значение карты
//int m_nNomKarti;//ѕоложение карты в колоде
CPoint m_ptPologKarti;//положение карты в окне дл€ рисовани€
BOOL m_bPokaziv;//1- рисовать карту, 0- рисовать обложку
int m_nSOSTOYANIE_KARTI;
int m_nMast;

void Draw(CDC * pDC);

	virtual ~CKarta();
	virtual void Serialize(CArchive& ar);
};



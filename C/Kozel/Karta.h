#pragma once



// CKarta command target

class CKarta : public CObject
{
	  DECLARE_SERIAL(CKarta)

public:
	CKarta();
int m_nZnachenie;//���������� ����� � �������� �����
//int m_nNomKarti;//��������� ����� � ������
CPoint m_ptPologKarti;//��������� ����� � ���� ��� ���������
BOOL m_bPokaziv;//1- �������� �����, 0- �������� �������
int m_nSOSTOYANIE_KARTI;
int m_nMast;

void Draw(CDC * pDC);

	virtual ~CKarta();
	virtual void Serialize(CArchive& ar);
};



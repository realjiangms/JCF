// guigeset.h : CguigeSet ���ʵ��



// CguigeSet ʵ��

// ���������� 2004��8��9��, 16:24

#include "stdafx.h"
#include "guigeset.h"
IMPLEMENT_DYNAMIC(CguigeSet, CRecordset)

CguigeSet::CguigeSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Guige = "";
	m_nFields = 1;
	m_nDefaultType = snapshot;
}

CString CguigeSet::GetDefaultConnect()
{
	return _T("DSN=JCF;APP=Microsoft\x00ae Visual Studio .NET;WSID=REDSTOP;DATABASE=JCF;Trusted_Connection=Yes");
}

CString CguigeSet::GetDefaultSQL()
{
	return _T("[dbo].[guige]");
}

void CguigeSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[Guige]"), m_Guige);

}
/////////////////////////////////////////////////////////////////////////////
// CguigeSet ���

#ifdef _DEBUG
void CguigeSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CguigeSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG



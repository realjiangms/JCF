// mingchenset.h : CmingchenSet ���ʵ��



// CmingchenSet ʵ��

// ���������� 2004��8��9��, 16:24

#include "stdafx.h"
#include "mingchenset.h"
IMPLEMENT_DYNAMIC(CmingchenSet, CRecordset)

CmingchenSet::CmingchenSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Mingchen = "";
	m_nFields = 1;
	m_nDefaultType = snapshot;
}

CString CmingchenSet::GetDefaultConnect()
{
	return _T("DSN=JCF;APP=Microsoft\x00ae Visual Studio .NET;WSID=REDSTOP;DATABASE=JCF;Trusted_Connection=Yes");
}

CString CmingchenSet::GetDefaultSQL()
{
	return _T("[dbo].[mingchen]");
}

void CmingchenSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[Mingchen]"), m_Mingchen);

}
/////////////////////////////////////////////////////////////////////////////
// CmingchenSet ���

#ifdef _DEBUG
void CmingchenSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CmingchenSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG



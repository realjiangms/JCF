// yonghuSet.h : CyonghuSet ���ʵ��



// CyonghuSet ʵ��

// ���������� 2004��8��14��, 10:17

#include "stdafx.h"
#include "yonghuSet.h"
IMPLEMENT_DYNAMIC(CyonghuSet, CRecordset)

CyonghuSet::CyonghuSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Yonghu = "";
	m_nFields = 1;
	m_nDefaultType = snapshot;
}

CString CyonghuSet::GetDefaultConnect()
{
	return _T("DSN=JCF;APP=Microsoft\x00ae Visual Studio .NET;WSID=JIANG;DATABASE=JCF;Trusted_Connection=Yes");
}

CString CyonghuSet::GetDefaultSQL()
{
	return _T("[dbo].[yonghu]");
}

void CyonghuSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[Yonghu]"), m_Yonghu);

}
/////////////////////////////////////////////////////////////////////////////
// CyonghuSet ���

#ifdef _DEBUG
void CyonghuSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CyonghuSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG



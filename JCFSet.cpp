// JCFSet.cpp : CJCFSet ���ʵ��
//

#include "stdafx.h"
#include "JCF.h"
#include "JCFSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJCFSet ʵ��

// ���������� 2004��8��9��, 14:49

IMPLEMENT_DYNAMIC(CJCFSet, CRecordset)

CJCFSet::CJCFSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Mingchen = "";
	m_Guige = "";
	m_Xianghao = "";
	m_Fahao = 0;
	m_Riqi;
	m_Yonghu = "";
	m_Bianhao = 0;
	m_nFields = 7;
	m_nDefaultType = snapshot;
}

CString CJCFSet::GetDefaultConnect()
{
	return _T("DSN=JCF;APP=Microsoft\x00ae Visual Studio .NET;WSID=REDSTOP;DATABASE=JCF;Trusted_Connection=Yes");
}

CString CJCFSet::GetDefaultSQL()
{
	return _T("[dbo].[JCF]");
}

void CJCFSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[Mingchen]"), m_Mingchen);
	RFX_Text(pFX, _T("[Guige]"), m_Guige);
	RFX_Text(pFX, _T("[Xianghao]"), m_Xianghao);
	RFX_Long(pFX, _T("[Fahao]"), m_Fahao);
	RFX_Date(pFX, _T("[Riqi]"), m_Riqi);
	RFX_Text(pFX, _T("[Yonghu]"), m_Yonghu);
	RFX_Long(pFX, _T("[Bianhao]"), m_Bianhao);

}
/////////////////////////////////////////////////////////////////////////////
// CJCFSet ���

#ifdef _DEBUG
void CJCFSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CJCFSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


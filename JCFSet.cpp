// JCFSet.cpp : CJCFSet 类的实现
//

#include "stdafx.h"
#include "JCF.h"
#include "JCFSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJCFSet 实现

// 代码生成在 2004年8月9日, 14:49

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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[Mingchen]"), m_Mingchen);
	RFX_Text(pFX, _T("[Guige]"), m_Guige);
	RFX_Text(pFX, _T("[Xianghao]"), m_Xianghao);
	RFX_Long(pFX, _T("[Fahao]"), m_Fahao);
	RFX_Date(pFX, _T("[Riqi]"), m_Riqi);
	RFX_Text(pFX, _T("[Yonghu]"), m_Yonghu);
	RFX_Long(pFX, _T("[Bianhao]"), m_Bianhao);

}
/////////////////////////////////////////////////////////////////////////////
// CJCFSet 诊断

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


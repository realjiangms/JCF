// mingchenset.h : CmingchenSet 类的实现



// CmingchenSet 实现

// 代码生成在 2004年8月9日, 16:24

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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[Mingchen]"), m_Mingchen);

}
/////////////////////////////////////////////////////////////////////////////
// CmingchenSet 诊断

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



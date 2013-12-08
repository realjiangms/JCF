// guigeset.h : CguigeSet 类的实现



// CguigeSet 实现

// 代码生成在 2004年8月9日, 16:24

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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[Guige]"), m_Guige);

}
/////////////////////////////////////////////////////////////////////////////
// CguigeSet 诊断

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



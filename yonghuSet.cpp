// yonghuSet.h : CyonghuSet 类的实现



// CyonghuSet 实现

// 代码生成在 2004年8月14日, 10:17

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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[Yonghu]"), m_Yonghu);

}
/////////////////////////////////////////////////////////////////////////////
// CyonghuSet 诊断

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



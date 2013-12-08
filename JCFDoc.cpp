// JCFDoc.cpp :  CJCFDoc 类的实现
//

#include "stdafx.h"
#include "JCF.h"

#include "JCFSet.h"
#include "JCFDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJCFDoc

IMPLEMENT_DYNCREATE(CJCFDoc, CDocument)

BEGIN_MESSAGE_MAP(CJCFDoc, CDocument)
END_MESSAGE_MAP()


// CJCFDoc 构造/析构

CJCFDoc::CJCFDoc()
{
	// TODO: 在此添加一次性构造代码

}

CJCFDoc::~CJCFDoc()
{
}

BOOL CJCFDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CJCFDoc 诊断

#ifdef _DEBUG
void CJCFDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CJCFDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CJCFDoc 命令

// JCFDoc.cpp :  CJCFDoc ���ʵ��
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


// CJCFDoc ����/����

CJCFDoc::CJCFDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CJCFDoc::~CJCFDoc()
{
}

BOOL CJCFDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CJCFDoc ���

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


// CJCFDoc ����

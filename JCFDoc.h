// JCFDoc.h :  CJCFDoc ��Ľӿ�
//


#pragma once
#include "JCFSet.h"

class CJCFDoc : public CDocument
{
protected: // �������л�����
	CJCFDoc();
	DECLARE_DYNCREATE(CJCFDoc)

// ����
public:
	CJCFSet m_JCFSet;

// ����
public:

// ��д
	public:
	virtual BOOL OnNewDocument();

// ʵ��
public:
	virtual ~CJCFDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};



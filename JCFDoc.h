// JCFDoc.h :  CJCFDoc 类的接口
//


#pragma once
#include "JCFSet.h"

class CJCFDoc : public CDocument
{
protected: // 仅从序列化创建
	CJCFDoc();
	DECLARE_DYNCREATE(CJCFDoc)

// 属性
public:
	CJCFSet m_JCFSet;

// 操作
public:

// 重写
	public:
	virtual BOOL OnNewDocument();

// 实现
public:
	virtual ~CJCFDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};



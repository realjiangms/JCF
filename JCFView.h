// JCFView.h : CJCFView ��Ľӿ�
//


#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#define DA_ZHI 1000

class CJCFSet;

class CJCFView : public CRecordView
{
protected: // �������л�����
	CJCFView();
	DECLARE_DYNCREATE(CJCFView)

public:
	enum{ IDD = IDD_JCF_FORM };
	CJCFSet* m_pSet;

// ����
public:
	CJCFDoc* GetDocument() const;

// ����
public:

// ��д
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CJCFView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNew();
	CListCtrl m_List;
	int Refresh(CString sql="");
	CString m_sql;
	afx_msg void OnOld();
	afx_msg void On32777();
	afx_msg void On32778();
	afx_msg void On32783();
	afx_msg void On32779();
	afx_msg void On32780();
	CString m_order;
	afx_msg void On32781();
	afx_msg void On32782();
	afx_msg void On32785();
	afx_msg void On32787();
	afx_msg void On32788();
	CFont m_font;
protected:
	
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
public:
	long m_nNext;
	double m_nCurRow;
	int m_kaitou[DA_ZHI];
	int Guji(CDC* pDC, CPrintInfo* pInfo);
	
	afx_msg void OnFileSave();
	afx_msg void On32786();
	afx_msg void On32799();
	afx_msg void On32800();
};

#ifndef _DEBUG  // JCFView.cpp �ĵ��԰汾
inline CJCFDoc* CJCFView::GetDocument() const
   { return reinterpret_cast<CJCFDoc*>(m_pDocument); }
#endif


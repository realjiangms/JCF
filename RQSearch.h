#pragma once
#include "afxwin.h"


// CRQSearch 对话框

class CRQSearch : public CDHtmlDialog
{
	DECLARE_DYNCREATE(CRQSearch)

public:
	CRQSearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRQSearch();
// 重写
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// 对话框数据
	enum { IDD = IDD_RQSEARCH, IDH = IDR_HTML_RQSEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	int m_year1;
	afx_msg void OnBnClickedOk();
	int m_month1;
	int m_day1;
	int m_year2;
	int m_month2;
	int m_day2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
};

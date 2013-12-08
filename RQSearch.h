#pragma once
#include "afxwin.h"


// CRQSearch �Ի���

class CRQSearch : public CDHtmlDialog
{
	DECLARE_DYNCREATE(CRQSearch)

public:
	CRQSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRQSearch();
// ��д
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// �Ի�������
	enum { IDD = IDD_RQSEARCH, IDH = IDR_HTML_RQSEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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

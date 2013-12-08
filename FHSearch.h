#pragma once


// CFHSearch 对话框

class CFHSearch : public CDHtmlDialog
{
	DECLARE_DYNCREATE(CFHSearch)

public:
	CFHSearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFHSearch();
// 重写
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// 对话框数据
	enum { IDD = IDD_FHSEARCH, IDH = IDR_HTML_FHSEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	CString m_fahao1;
	CString m_fahao2;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
};

#pragma once


// CBHSearch 对话框

class CBHSearch : public CDHtmlDialog
{
	DECLARE_DYNCREATE(CBHSearch)

public:
	CBHSearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBHSearch();
// 重写
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// 对话框数据
	enum { IDD = IDD_BHSEARCH, IDH = IDR_HTML_BHSEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	long m_bianhao1;
	long m_bianhao2;
};

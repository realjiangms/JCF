#pragma once


// CFHSearch �Ի���

class CFHSearch : public CDHtmlDialog
{
	DECLARE_DYNCREATE(CFHSearch)

public:
	CFHSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFHSearch();
// ��д
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// �Ի�������
	enum { IDD = IDD_FHSEARCH, IDH = IDR_HTML_FHSEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	CString m_fahao1;
	CString m_fahao2;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
};

#pragma once


// CBHSearch �Ի���

class CBHSearch : public CDHtmlDialog
{
	DECLARE_DYNCREATE(CBHSearch)

public:
	CBHSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBHSearch();
// ��д
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// �Ի�������
	enum { IDD = IDD_BHSEARCH, IDH = IDR_HTML_BHSEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	long m_bianhao1;
	long m_bianhao2;
};

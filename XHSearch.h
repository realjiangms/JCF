#pragma once


// CXHSearch �Ի���

class CXHSearch : public CDialog
{
	DECLARE_DYNAMIC(CXHSearch)

public:
	CXHSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CXHSearch();

// �Ի�������
	enum { IDD = IDD_XHSEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_xianghao;
	afx_msg void OnBnClickedButton1();
};

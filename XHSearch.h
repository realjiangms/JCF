#pragma once


// CXHSearch 对话框

class CXHSearch : public CDialog
{
	DECLARE_DYNAMIC(CXHSearch)

public:
	CXHSearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CXHSearch();

// 对话框数据
	enum { IDD = IDD_XHSEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_xianghao;
	afx_msg void OnBnClickedButton1();
};

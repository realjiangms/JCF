#pragma once
#include "afxwin.h"


// CGGSearch 对话框

class CGGSearch : public CDialog
{
	DECLARE_DYNAMIC(CGGSearch)

public:
	CGGSearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGGSearch();

// 对话框数据
	enum { IDD = IDD_GGSEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo;
	CString m_guige;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};

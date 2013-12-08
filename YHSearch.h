#pragma once
#include "afxwin.h"


// CYHSearch 对话框

class CYHSearch : public CDialog
{
	DECLARE_DYNAMIC(CYHSearch)

public:
	CYHSearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CYHSearch();

// 对话框数据
	enum { IDD = IDD_YHSEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo;
	CString m_yonghu;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};

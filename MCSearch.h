#pragma once
#include "afxwin.h"


// CMCSearch 对话框

class CMCSearch : public CDialog
{
	DECLARE_DYNAMIC(CMCSearch)

public:
	CMCSearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMCSearch();

// 对话框数据
	enum { IDD = IDD_MCSEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo;
	CString m_mingchen;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};

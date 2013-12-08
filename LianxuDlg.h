#pragma once


// CLianxuDlg 对话框

class CLianxuDlg : public CDialog
{
	DECLARE_DYNAMIC(CLianxuDlg)

public:
	CLianxuDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLianxuDlg();

// 对话框数据
	enum { IDD = IDD_LIANXU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long m_lianxu;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};

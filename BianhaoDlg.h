#pragma once


// CBianhaoDlg 对话框

class CBianhaoDlg : public CDialog
{
	DECLARE_DYNAMIC(CBianhaoDlg)

public:
	CBianhaoDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBianhaoDlg();

// 对话框数据
	enum { IDD = IDD_BIANHAO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_bianhao;
	afx_msg void OnBnClickedOk();
	int CheckCurrent(void);
};

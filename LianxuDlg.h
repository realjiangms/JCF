#pragma once


// CLianxuDlg �Ի���

class CLianxuDlg : public CDialog
{
	DECLARE_DYNAMIC(CLianxuDlg)

public:
	CLianxuDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLianxuDlg();

// �Ի�������
	enum { IDD = IDD_LIANXU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long m_lianxu;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};

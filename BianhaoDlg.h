#pragma once


// CBianhaoDlg �Ի���

class CBianhaoDlg : public CDialog
{
	DECLARE_DYNAMIC(CBianhaoDlg)

public:
	CBianhaoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBianhaoDlg();

// �Ի�������
	enum { IDD = IDD_BIANHAO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_bianhao;
	afx_msg void OnBnClickedOk();
	int CheckCurrent(void);
};

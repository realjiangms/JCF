#pragma once
#include "atlcomtime.h"
#include "afxwin.h"
#include <vector>


// CNewDlg �Ի���

class CNewDlg : public CDialog
{
	DECLARE_DYNAMIC(CNewDlg)

public:
	CNewDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNewDlg();

// �Ի�������
	enum { IDD = IDD_NEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_mingchen;
	CString m_guige;
	CString m_xianghao;
	CString m_fahao;
	COleDateTime m_riqi;
	CString m_yonghu;
	long m_bianhao;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CComboBox m_Combo1;
	CComboBox m_Combo2;
	virtual int CheckCurrent(void);
	CComboBox m_Combo3;
	// control of edit control:IDC_EDIT4
	CEdit m_fahaoCtrl;
	CString m_heji;
	long m_lianxu;
	int GetLianxu(void);
	afx_msg void OnBnClickedCancel();
public:
	std::vector<CString> m_fahaos;
};

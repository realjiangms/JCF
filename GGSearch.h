#pragma once
#include "afxwin.h"


// CGGSearch �Ի���

class CGGSearch : public CDialog
{
	DECLARE_DYNAMIC(CGGSearch)

public:
	CGGSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGGSearch();

// �Ի�������
	enum { IDD = IDD_GGSEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo;
	CString m_guige;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};

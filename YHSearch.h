#pragma once
#include "afxwin.h"


// CYHSearch �Ի���

class CYHSearch : public CDialog
{
	DECLARE_DYNAMIC(CYHSearch)

public:
	CYHSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CYHSearch();

// �Ի�������
	enum { IDD = IDD_YHSEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo;
	CString m_yonghu;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};

#pragma once
#include "afxwin.h"


// CMCSearch �Ի���

class CMCSearch : public CDialog
{
	DECLARE_DYNAMIC(CMCSearch)

public:
	CMCSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMCSearch();

// �Ի�������
	enum { IDD = IDD_MCSEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo;
	CString m_mingchen;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};

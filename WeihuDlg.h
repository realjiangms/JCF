#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CWeihuDlg �Ի���

class CWeihuDlg : public CDialog
{
	DECLARE_DYNAMIC(CWeihuDlg)

public:
	CWeihuDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CWeihuDlg();

// �Ի�������
	enum { IDD = IDD_WEIHU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_Combo;
	CListCtrl m_List;
	virtual BOOL OnInitDialog();
	CString m_table;
	afx_msg void OnCbnSelchangeCombo1();
	void Refresh(void);
	afx_msg void OnBnClickedButton1();
	CString m_in;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnLvnKeydownList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

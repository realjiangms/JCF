#pragma once
#include "afxcmn.h"


// COldDlg �Ի���

class COldDlg : public CDHtmlDialog
{
	DECLARE_DYNCREATE(COldDlg)

public:
	COldDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COldDlg();
// ��д
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// �Ի�������
	enum { IDD = IDD_OLD, IDH = IDR_HTML_OLDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	CListCtrl m_List;
	int Refresh();
	afx_msg void OnBnClickedButton1();
	long m_bianhao;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnLvnKeydownList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};

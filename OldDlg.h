#pragma once
#include "afxcmn.h"


// COldDlg 对话框

class COldDlg : public CDHtmlDialog
{
	DECLARE_DYNCREATE(COldDlg)

public:
	COldDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~COldDlg();
// 重写
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// 对话框数据
	enum { IDD = IDD_OLD, IDH = IDR_HTML_OLDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
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

// LianxuDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JCF.h"
#include "LianxuDlg.h"
#include ".\lianxudlg.h"


// CLianxuDlg 对话框

IMPLEMENT_DYNAMIC(CLianxuDlg, CDialog)
CLianxuDlg::CLianxuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLianxuDlg::IDD, pParent)
	, m_lianxu(0)
{
}

CLianxuDlg::~CLianxuDlg()
{
}

void CLianxuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_lianxu);
}


BEGIN_MESSAGE_MAP(CLianxuDlg, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CLianxuDlg 消息处理程序

void CLianxuDlg::OnBnClickedOk()
{
	UpdateData();
	if (m_lianxu==0)
		m_lianxu=1;
	else if (m_lianxu > 10)
	{
		AfxMessageBox("阀号连续 > 10个，误操作? 默认到1个");
		m_lianxu=1;
	}
	UpdateData(0);
	OnOK();
}

BOOL CLianxuDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_lianxu=1;
	UpdateData(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

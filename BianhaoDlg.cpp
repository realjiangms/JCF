// BianhaoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JCF.h"
#include "BianhaoDlg.h"
#include ".\bianhaodlg.h"


// CBianhaoDlg 对话框

IMPLEMENT_DYNAMIC(CBianhaoDlg, CDialog)
CBianhaoDlg::CBianhaoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBianhaoDlg::IDD, pParent)
	, m_bianhao(0)
{
}

CBianhaoDlg::~CBianhaoDlg()
{
}

void CBianhaoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_bianhao);
}


BEGIN_MESSAGE_MAP(CBianhaoDlg, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CBianhaoDlg 消息处理程序

void CBianhaoDlg::OnBnClickedOk()
{
	UpdateData();
	if (CheckCurrent())
		return;
	OnOK();
}

int CBianhaoDlg::CheckCurrent(void)
{
	if (m_bianhao==0)
	{
		AfxMessageBox("缺少提货单编号");
		return 1;
	}
	return 0;
}

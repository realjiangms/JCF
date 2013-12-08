// BianhaoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JCF.h"
#include "BianhaoDlg.h"
#include ".\bianhaodlg.h"


// CBianhaoDlg �Ի���

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


// CBianhaoDlg ��Ϣ�������

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
		AfxMessageBox("ȱ����������");
		return 1;
	}
	return 0;
}

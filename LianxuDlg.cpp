// LianxuDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JCF.h"
#include "LianxuDlg.h"
#include ".\lianxudlg.h"


// CLianxuDlg �Ի���

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


// CLianxuDlg ��Ϣ�������

void CLianxuDlg::OnBnClickedOk()
{
	UpdateData();
	if (m_lianxu==0)
		m_lianxu=1;
	else if (m_lianxu > 10)
	{
		AfxMessageBox("�������� > 10���������? Ĭ�ϵ�1��");
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
	// �쳣: OCX ����ҳӦ���� FALSE
}

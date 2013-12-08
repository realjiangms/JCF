// GGSearch.cpp : 实现文件
//

#include "stdafx.h"
#include "JCF.h"
#include "GGSearch.h"
#include ".\ggsearch.h"


// CGGSearch 对话框

IMPLEMENT_DYNAMIC(CGGSearch, CDialog)
CGGSearch::CGGSearch(CWnd* pParent /*=NULL*/)
	: CDialog(CGGSearch::IDD, pParent)
	, m_guige(_T(""))
{
}

CGGSearch::~CGGSearch()
{
}

void CGGSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_CBString(pDX, IDC_COMBO1, m_guige);
}


BEGIN_MESSAGE_MAP(CGGSearch, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
END_MESSAGE_MAP()


// CGGSearch 消息处理程序

void CGGSearch::OnBnClickedOk()
{
	UpdateData();
	// TODO: 在此添加控件通知处理程序代码
	if (m_guige=="")
		return;
	OnOK();
	
}

void CGGSearch::OnBnClickedButton1()
{
	if (!UpdateData(TRUE))
	{
		TRACE(traceAppMsg, 0, "UpdateData failed during dialog termination.\n");
		// the UpdateData routine will set focus to correct item
		return;
	}
	
	if (m_guige=="")
		return;
	EndDialog(IDC_BUTTON1);}

BOOL CGGSearch::OnInitDialog()
{
	CDialog::OnInitDialog();
	CguigeSet guige;
	guige.Open();
	m_combo.ResetContent();
	for(;!guige.IsEOF();guige.MoveNext())
		m_combo.AddString(guige.m_Guige);
	 UpdateData(0);	

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

// MCSearch.cpp : 实现文件
//

#include "stdafx.h"
#include "JCF.h"
#include "MCSearch.h"
#include ".\mcsearch.h"


// CMCSearch 对话框

IMPLEMENT_DYNAMIC(CMCSearch, CDialog)
CMCSearch::CMCSearch(CWnd* pParent /*=NULL*/)
	: CDialog(CMCSearch::IDD, pParent)
	, m_mingchen(_T(""))
{
}

CMCSearch::~CMCSearch()
{
}

void CMCSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_CBString(pDX, IDC_COMBO1, m_mingchen);
}


BEGIN_MESSAGE_MAP(CMCSearch, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
END_MESSAGE_MAP()


// CMCSearch 消息处理程序

void CMCSearch::OnBnClickedOk()
{
	UpdateData();
	// TODO: 在此添加控件通知处理程序代码
	if (m_mingchen=="")
		return;
	OnOK();
}

BOOL CMCSearch::OnInitDialog()
{
	CDialog::OnInitDialog();
	CmingchenSet mingchen;
	mingchen.Open();
	m_combo.ResetContent();
	for(;!mingchen.IsEOF();mingchen.MoveNext())
		m_combo.AddString(mingchen.m_Mingchen);
	 UpdateData(0);	

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CMCSearch::OnBnClickedButton1()
{
	if (!UpdateData(TRUE))
	{
		TRACE(traceAppMsg, 0, "UpdateData failed during dialog termination.\n");
		// the UpdateData routine will set focus to correct item
		return;
	}
	
	if (m_mingchen=="")
		return;
	EndDialog(IDC_BUTTON1);
}

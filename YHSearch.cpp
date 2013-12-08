// YHSearch.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JCF.h"
#include "YHSearch.h"
#include ".\yhsearch.h"


// CYHSearch �Ի���

IMPLEMENT_DYNAMIC(CYHSearch, CDialog)
CYHSearch::CYHSearch(CWnd* pParent /*=NULL*/)
	: CDialog(CYHSearch::IDD, pParent)
	, m_yonghu(_T(""))
{
}

CYHSearch::~CYHSearch()
{
}

void CYHSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_CBString(pDX, IDC_COMBO1, m_yonghu);
}


BEGIN_MESSAGE_MAP(CYHSearch, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CYHSearch ��Ϣ�������

void CYHSearch::OnBnClickedButton1()
{
	if (!UpdateData(TRUE))
	{
		TRACE(traceAppMsg, 0, "UpdateData failed during dialog termination.\n");
		// the UpdateData routine will set focus to correct item
		return;
	}
	
	if (m_yonghu=="")
		return;
	EndDialog(IDC_BUTTON1);
}

void CYHSearch::OnBnClickedOk()
{
	UpdateData();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_yonghu=="")
		return;
	OnOK();
}

BOOL CYHSearch::OnInitDialog()
{
	CDialog::OnInitDialog();

	CDialog::OnInitDialog();
	CyonghuSet yonghu;
	yonghu.Open();
	m_combo.ResetContent();
	for(;!yonghu.IsEOF();yonghu.MoveNext())
		m_combo.AddString(yonghu.m_Yonghu);
	 UpdateData(0);	

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

// XHSearch.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JCF.h"
#include "XHSearch.h"
#include ".\xhsearch.h"


// CXHSearch �Ի���

IMPLEMENT_DYNAMIC(CXHSearch, CDialog)
CXHSearch::CXHSearch(CWnd* pParent /*=NULL*/)
	: CDialog(CXHSearch::IDD, pParent)
	, m_xianghao(_T(""))
{
}

CXHSearch::~CXHSearch()
{
}

void CXHSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_xianghao);
}


BEGIN_MESSAGE_MAP(CXHSearch, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
END_MESSAGE_MAP()


// CXHSearch ��Ϣ�������

void CXHSearch::OnBnClickedOk()
{
	UpdateData();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_xianghao=="")
		return;
	OnOK();
}

void CXHSearch::OnBnClickedButton1()
{
	if (!UpdateData(TRUE))
	{
		TRACE(traceAppMsg, 0, "UpdateData failed during dialog termination.\n");
		// the UpdateData routine will set focus to correct item
		return;
	}
	
	if (m_xianghao=="")
		return;
	EndDialog(IDC_BUTTON1);
}

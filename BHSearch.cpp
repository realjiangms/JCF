// BHSearch.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JCF.h"
#include "BHSearch.h"
#include ".\bhsearch.h"


// CBHSearch �Ի���

IMPLEMENT_DYNCREATE(CBHSearch, CDHtmlDialog)

CBHSearch::CBHSearch(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CBHSearch::IDD, CBHSearch::IDH, pParent)
	, m_bianhao1(0)
	, m_bianhao2(0)
{
}

CBHSearch::~CBHSearch()
{
}

void CBHSearch::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_bianhao1);
	DDX_Text(pDX, IDC_EDIT2, m_bianhao2);
}

BOOL CBHSearch::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

BEGIN_MESSAGE_MAP(CBHSearch, CDHtmlDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
END_MESSAGE_MAP()

BEGIN_DHTML_EVENT_MAP(CBHSearch)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()



// CBHSearch ��Ϣ�������

HRESULT CBHSearch::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

HRESULT CBHSearch::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CBHSearch::OnBnClickedOk()
{
	UpdateData();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_bianhao1==0&&m_bianhao2==0)
		return;
	OnOK();
}

void CBHSearch::OnBnClickedButton1()
{
	if (!UpdateData(TRUE))
	{
		TRACE(traceAppMsg, 0, "UpdateData failed during dialog termination.\n");
		// the UpdateData routine will set focus to correct item
		return;
	}
	
	if (m_bianhao1==0&&m_bianhao2==0)
		return;
	EndDialog(IDC_BUTTON1);
}

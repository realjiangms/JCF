// FHSearch.cpp : 实现文件
//

#include "stdafx.h"
#include "JCF.h"
#include "FHSearch.h"
#include ".\fhsearch.h"


// CFHSearch 对话框

IMPLEMENT_DYNCREATE(CFHSearch, CDHtmlDialog)

CFHSearch::CFHSearch(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CFHSearch::IDD, CFHSearch::IDH, pParent)
	, m_fahao1("")
	, m_fahao2("")
{
}

CFHSearch::~CFHSearch()
{
}

void CFHSearch::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_fahao1);
	m_fahao1 = m_fahao1.Trim();
	DDX_Text(pDX, IDC_EDIT2, m_fahao2);
	m_fahao2 = m_fahao2.Trim();
}

BOOL CFHSearch::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

BEGIN_MESSAGE_MAP(CFHSearch, CDHtmlDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
END_MESSAGE_MAP()

BEGIN_DHTML_EVENT_MAP(CFHSearch)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()



// CFHSearch 消息处理程序

HRESULT CFHSearch::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;  // 除非将焦点设置到控件，否则返回 TRUE
}

HRESULT CFHSearch::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFHSearch::OnBnClickedOk()
{
	UpdateData();
	if (m_fahao1.Trim().IsEmpty() || m_fahao2.Trim().IsEmpty())
		return;
	OnOK();
}

void CFHSearch::OnBnClickedButton1()
{
	if (!UpdateData(TRUE))
	{
		TRACE(traceAppMsg, 0, "UpdateData failed during dialog termination.\n");
		// the UpdateData routine will set focus to correct item
		return;
	}
	
	if (m_fahao1.Trim().IsEmpty() || m_fahao2.Trim().IsEmpty())
		return;
	EndDialog(IDC_BUTTON1);
}

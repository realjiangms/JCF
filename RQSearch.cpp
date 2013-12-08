// RQSearch.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JCF.h"
#include "RQSearch.h"
#include ".\rqsearch.h"


// CRQSearch �Ի���

IMPLEMENT_DYNCREATE(CRQSearch, CDHtmlDialog)

CRQSearch::CRQSearch(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CRQSearch::IDD, CRQSearch::IDH, pParent)
	, m_year1(0)
	, m_month1(0)
	, m_day1(0)
	, m_year2(0)
	, m_month2(0)
	, m_day2(0)
{
}

CRQSearch::~CRQSearch()
{
}

void CRQSearch::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_year1);
	DDX_Text(pDX, IDC_EDIT2, m_month1);
	DDX_Text(pDX, IDC_EDIT3, m_day1);
	DDX_Text(pDX, IDC_EDIT4, m_year2);
	DDX_Text(pDX, IDC_EDIT5, m_month2);
	DDX_Text(pDX, IDC_EDIT6, m_day2);
}

BOOL CRQSearch::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();
	

	CEdit *temp=(CEdit *)(CDialog::GetDlgItem(IDC_EDIT1));
	temp->SetFocus();
	temp->SetSel(0,100);
	UpdateData(0);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

BEGIN_MESSAGE_MAP(CRQSearch, CDHtmlDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, OnEnChangeEdit6)
END_MESSAGE_MAP()

BEGIN_DHTML_EVENT_MAP(CRQSearch)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()



// CRQSearch ��Ϣ�������

HRESULT CRQSearch::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

HRESULT CRQSearch::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CRQSearch::OnBnClickedOk()
{
	UpdateData();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	OnOK();
}

void CRQSearch::OnBnClickedButton1()
{
if (!UpdateData(TRUE))
	{
		TRACE(traceAppMsg, 0, "UpdateData failed during dialog termination.\n");
		// the UpdateData routine will set focus to correct item
		return;
	}
	
	
	EndDialog(IDC_BUTTON1);
}

void CRQSearch::OnEnChangeEdit1()
{
	UpdateData();
	if (m_year1>1000)
	{
		CEdit *temp=(CEdit *)(CDialog::GetDlgItem(IDC_EDIT2));
		temp->SetFocus();
		temp->SetSel(0,100);
	}

	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDHtmlDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CRQSearch::OnEnChangeEdit2()
{
	UpdateData();
	if (m_month1>10)
	{
		CEdit *temp=(CEdit *)(CDialog::GetDlgItem(IDC_EDIT3));
		temp->SetFocus();
		temp->SetSel(0,100);
	}// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDHtmlDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CRQSearch::OnEnChangeEdit3()
{
	UpdateData();
	if (m_day1>10)
	{
		CEdit *temp=(CEdit *)(CDialog::GetDlgItem(IDC_EDIT4));
		temp->SetFocus();
		temp->SetSel(0,100);
	}// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDHtmlDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CRQSearch::OnEnChangeEdit4()
{
	UpdateData();
	if (m_year2>1000)
	{
		CEdit *temp=(CEdit *)(CDialog::GetDlgItem(IDC_EDIT5));
		temp->SetFocus();
		temp->SetSel(0,100);
	}

}

void CRQSearch::OnEnChangeEdit5()
{
	UpdateData();
	if (m_month2>10)
	{
		CEdit *temp=(CEdit *)(CDialog::GetDlgItem(IDC_EDIT6));
		temp->SetFocus();
		temp->SetSel(0,100);
	}
}

void CRQSearch::OnEnChangeEdit6()
{
	UpdateData();
	if (m_day1>10)
	{
		CEdit *temp=(CEdit *)(CDialog::GetDlgItem(IDOK));
		
	}
}

// NewDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JCF.h"
#include "NewDlg.h"
#include ".\newdlg.h"
#include "LianxuDlg.h"

// CNewDlg �Ի���

IMPLEMENT_DYNAMIC(CNewDlg, CDialog)
CNewDlg::CNewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewDlg::IDD, pParent)
	, m_mingchen(_T(""))
	, m_guige(_T(""))
	, m_xianghao(_T(""))
	, m_fahao("")
	, m_riqi(COleDateTime::GetCurrentTime())
	, m_yonghu(_T(""))
	, m_bianhao(0)
	, m_heji(_T(""))
{
}

CNewDlg::~CNewDlg()
{
}

void CNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_COMBO1, m_mingchen);
	DDX_Text(pDX,IDC_COMBO2, m_guige);
	DDX_Text(pDX, IDC_EDIT3, m_xianghao);
	DDV_MaxChars(pDX, m_xianghao, 9);
	DDX_Text(pDX, IDC_EDIT4, m_fahao);
	m_fahao = m_fahao.Trim();
	DDX_Text(pDX, IDC_EDIT5, m_riqi);
	DDX_Text(pDX, IDC_COMBO3, m_yonghu);
	DDX_Text(pDX, IDC_EDIT7, m_bianhao);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_COMBO3, m_Combo3);
	DDX_Control(pDX, IDC_EDIT4, m_fahaoCtrl);
	DDX_Text(pDX, IDC_STATIC1, m_heji);
}


BEGIN_MESSAGE_MAP(CNewDlg, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()


// CNewDlg ��Ϣ�������

void CNewDlg::OnBnClickedOk()
{
	UpdateData();
	if(CheckCurrent())
		return;
	// m_lianxu=GetLianxu();
	OnOK();
}

BOOL CNewDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	::CmingchenSet mingchen;
	mingchen.Open();
	::CguigeSet guige;
	guige.Open();
	::CyonghuSet yonghu;
	yonghu.Open();
	m_Combo1.ResetContent();
	m_Combo2.ResetContent();
	m_Combo3.ResetContent();
	for(;!mingchen.IsEOF();mingchen.MoveNext())
		m_Combo1.AddString(mingchen.m_Mingchen);
	for(;!guige.IsEOF();guige.MoveNext())
		m_Combo2.AddString(guige.m_Guige);
	for(;!yonghu.IsEOF();yonghu.MoveNext())
		m_Combo3.AddString(yonghu.m_Yonghu);
	m_riqi.SetDate(m_riqi.GetYear(),m_riqi.GetMonth(),m_riqi.GetDay());
	UpdateData(0);	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

int CNewDlg::CheckCurrent(void)
{
	if (m_xianghao.GetLength()<8||m_xianghao[4]!='-')
		if(AfxMessageBox("��Ÿ�ʽ����,������",MB_YESNO)==IDNO)
			return 1;
	if (m_fahao.Trim().IsEmpty())
	{
		AfxMessageBox("ȱ�ٷ���");
		return 1;
	}
	if (m_bianhao==0)
	{
		AfxMessageBox("ȱ����������");
		return 1;
	}

	CJCFSet jcf;
	CString sql="";
	sql.Format("select * from JCF where Fahao='%s' and Bianhao='%d'",m_fahao,m_bianhao);
	jcf.Open((-1),sql);
	if (!jcf.IsEOF())
	{
		AfxMessageBox("���ų�ͻ");
		return 1;
	}	
	if (m_mingchen.IsEmpty())
	{
		AfxMessageBox("ȱ�ٲ�Ʒ����");
		return 1;
	}
	if (m_guige.IsEmpty())
	{
		AfxMessageBox("ȱ�ٹ��");
		return 1;
	}
	if (m_yonghu.IsEmpty())
	{
		AfxMessageBox("ȱ���û�");
		return 1;
	}

	return 0;
}

int CNewDlg::GetLianxu(void)
{
	::CLianxuDlg temp;
	if(temp.DoModal()==IDCANCEL)
		return 1;
	else
		return temp.m_lianxu;
}

void CNewDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}

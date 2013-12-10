// NewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JCF.h"
#include "NewDlg.h"
#include ".\newdlg.h"
#include "LianxuDlg.h"
#include <map>

// CNewDlg 对话框

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


// CNewDlg 消息处理程序

void CNewDlg::OnBnClickedOk()
{
	UpdateData();
	if(CheckCurrent()) // Also update m_fahaos
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
	// 异常: OCX 属性页应返回 FALSE
}

int CNewDlg::CheckCurrent(void)
{
	if (m_xianghao.GetLength()<8||m_xianghao[4]!='-')
		if(AfxMessageBox("箱号格式错误,继续？",MB_YESNO)==IDNO)
			return 1;
	if (m_fahao.Trim().IsEmpty())
	{
		AfxMessageBox("缺少阀号");
		return 1;
	}
	if (m_bianhao==0)
	{
		AfxMessageBox("缺少提货单编号");
		return 1;
	}	
	
	CString oriStr=m_fahao;
	m_fahaos.clear();
	std::map<CString, int> checkF;
	checkF.clear();
	while (true)
	{
		CString n = oriStr.SpanExcluding(",\n\r\t ").Trim();
		if (!n.IsEmpty()) 
		{
			if (checkF[n])
			{
				CString msg;
				msg.Format("阀号重复: %s", n);
				AfxMessageBox(msg);
				return 1;
			}
			m_fahaos.push_back(n);
			checkF[n] = 1;
		}
		oriStr = oriStr.Right(oriStr.GetLength()-n.GetLength()-1);
		if (oriStr.IsEmpty())
		{
			break;
		}
	}

	CJCFSet jcf;
	CString sql="";
	
	for (std::vector<CString>::const_iterator it=m_fahaos.begin();it!=m_fahaos.end();it++)
	{
		sql.Format("select * from JCF where Fahao='%s' and Bianhao='%d'",*it,m_bianhao);
		jcf.Open((-1),sql);
		if (!jcf.IsEOF())
		{
			CString msg;
			msg.Format("阀号冲突: %s", *it);
			AfxMessageBox(msg);
			jcf.Close();
			return 1;
		}
		jcf.Close();
	}
		
	if (m_mingchen.IsEmpty())
	{
		AfxMessageBox("缺少产品名称");
		return 1;
	}
	if (m_guige.IsEmpty())
	{
		AfxMessageBox("缺少规格");
		return 1;
	}
	if (m_yonghu.IsEmpty())
	{
		AfxMessageBox("缺少用户");
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
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}

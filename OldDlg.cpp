// OldDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JCF.h"
#include "OldDlg.h"
#include ".\olddlg.h"
#include "NewDlg.h"


// COldDlg 对话框

IMPLEMENT_DYNCREATE(COldDlg, CDHtmlDialog)

COldDlg::COldDlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(COldDlg::IDD, COldDlg::IDH, pParent)
	, m_bianhao(0)
{
}

COldDlg::~COldDlg()
{
}

void COldDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}

BOOL COldDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();
	
	Refresh();;
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

BEGIN_MESSAGE_MAP(COldDlg, CDHtmlDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_NOTIFY(LVN_KEYDOWN, IDC_LIST1, OnLvnKeydownList1)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButton4)
END_MESSAGE_MAP()

BEGIN_DHTML_EVENT_MAP(COldDlg)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()



// COldDlg 消息处理程序

HRESULT COldDlg::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;  // 除非将焦点设置到控件，否则返回 TRUE
}

HRESULT COldDlg::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;  // 除非将焦点设置到控件，否则返回 TRUE
}

int COldDlg::Refresh()
{
	CString temp="";
	temp.Format("Select * from JCF where Bianhao=%d order by Riqi desc,Fahao asc",m_bianhao);
	return	SqlToList(&m_List,temp);

}

void COldDlg::OnBnClickedButton1()
{
	CNewDlg newd;
	CJCFSet jcf;
	CString sql("");
    CString temp="";
	temp.Format("Select * from JCF where Bianhao=%d order by Riqi desc,Fahao desc",m_bianhao);
	jcf.Open((-1),temp);
	newd.m_bianhao=m_bianhao;
	newd.m_mingchen=jcf.m_Mingchen;
	newd.m_guige=jcf.m_Guige;
	newd.m_xianghao=jcf.m_Xianghao;
	newd.m_fahao=jcf.m_Fahao;
	newd.m_yonghu=jcf.m_Yonghu;
	int heji=this->m_List.GetItemCount();
	newd.m_heji.Format("共 %d 个",heji);
	while(newd.DoModal()!=IDCANCEL)
	{
		sql.Format("insert into JCF(Mingchen,Guige,Xianghao,Fahao,Riqi,Yonghu,Bianhao) values ('%s','%s','%s','%s','%s','%s','%d')",newd.m_mingchen,newd.m_guige,newd.m_xianghao,newd.m_fahao,newd.m_riqi.Format("%Y-%m-%d"),newd.m_yonghu,newd.m_bianhao);
		dbase.ExecuteSQL(sql);
		heji+=1;
		newd.m_heji.Format("共 %d 个",heji);
	}
	Refresh();
}

void COldDlg::OnBnClickedButton2()
{
	int i=m_List.GetSelectionMark();
	if (i<0)
		return;
	else
	{
		CString sql="";
		char temp[100];
		m_List.GetItemText(i,3,temp,100);		
		sql.Format("delete from JCF where Bianhao=%d and Fahao='%s'", m_bianhao, temp);
		dbase.ExecuteSQL(sql);
		Refresh();
		return;
	}

}

void COldDlg::OnLvnKeydownList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLVKEYDOWN pLVKeyDow = reinterpret_cast<LPNMLVKEYDOWN>(pNMHDR);
	if (pLVKeyDow->wVKey==VK_DELETE)
		OnBnClickedButton2();
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

void COldDlg::OnBnClickedButton3()
{
	int i=m_List.GetSelectionMark();
	CString fahao = "";
	if (i<0)
		return;
	else
	{
		char ctemp[100];
		m_List.GetItemText(i,3,ctemp,100);		
		fahao = ctemp;	
	}
	CNewDlg newd;
	CJCFSet jcf;
	CString sql("");
	CString sqlre("");
    CString temp="";
	temp.Format("Select * from JCF where Fahao='%s'",fahao);
	jcf.Open((-1),temp);
	newd.m_bianhao=jcf.m_Bianhao;
	newd.m_mingchen=jcf.m_Mingchen;
	newd.m_guige=jcf.m_Guige;
	newd.m_xianghao=jcf.m_Xianghao;
	newd.m_fahao=jcf.m_Fahao;
	newd.m_yonghu=jcf.m_Yonghu;
	newd.m_riqi.SetDate(jcf.m_Riqi.GetYear(),jcf.m_Riqi.GetMonth(),jcf.m_Riqi.GetDay());
    sqlre.Format("insert into JCF(Mingchen,Guige,Xianghao,Fahao,Riqi,Yonghu,Bianhao) values ('%s','%s','%s','%s','%s','%s','%d')",newd.m_mingchen,newd.m_guige,newd.m_xianghao,newd.m_fahao,newd.m_riqi.Format("%Y-%m-%d"),newd.m_yonghu,newd.m_bianhao);
	sql.Format("delete from JCF where Fahao='%s'",fahao);
	dbase.ExecuteSQL(sql);
	if(newd.DoModal()!=IDCANCEL)
	{
		sql.Format("insert into JCF(Mingchen,Guige,Xianghao,Fahao,Riqi,Yonghu,Bianhao) values ('%s','%s','%s','%s','%s','%s','%d')",newd.m_mingchen,newd.m_guige,newd.m_xianghao,newd.m_fahao,newd.m_riqi.Format("%Y-%m-%d"),newd.m_yonghu,newd.m_bianhao);
		dbase.ExecuteSQL(sql);
	}
	else
		dbase.ExecuteSQL(sqlre);
	Refresh();
	
}

void COldDlg::OnBnClickedButton4()
{
	if(AfxMessageBox("删除全部？",MB_YESNO)==IDNO)
		return;
	CString sql="";
	sql.Format("delete from JCF where Bianhao=%d",m_bianhao);
	dbase.ExecuteSQL(sql);
	Refresh();
	return;
}

// WeihuDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JCF.h"
#include "WeihuDlg.h"
#include ".\weihudlg.h"


// CWeihuDlg �Ի���

IMPLEMENT_DYNAMIC(CWeihuDlg, CDialog)
CWeihuDlg::CWeihuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWeihuDlg::IDD, pParent)
	, m_table(_T(""))
	, m_in(_T(""))
{
}

CWeihuDlg::~CWeihuDlg()
{
}

void CWeihuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_EDIT1, m_in);
}


BEGIN_MESSAGE_MAP(CWeihuDlg, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_NOTIFY(LVN_KEYDOWN, IDC_LIST1, OnLvnKeydownList1)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CWeihuDlg ��Ϣ�������

BOOL CWeihuDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_Combo.ResetContent();
	m_Combo.AddString("��Ʒ����");
	m_Combo.AddString("���");
	m_Combo.AddString("�û�");
	m_Combo.SetCurSel(0);
	m_table="mingchen";
	CmingchenSet mingchen;
	mingchen.Open();
	m_List.DeleteAllItems();
	for(;!mingchen.IsEOF();mingchen.MoveNext())
		m_List.InsertItem(0,mingchen.m_Mingchen);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CWeihuDlg::OnCbnSelchangeCombo1()
{
	switch(m_Combo.GetCurSel())
	{
	case 0:
		m_table="mingchen";
		break;	
	case 1:
		m_table="guige";
		break;
	case 2:
		m_table="yonghu";
		break;
	default:
		break;
	}
	Refresh();
	return;
}

void CWeihuDlg::Refresh(void)
{
	CmingchenSet mingchen;
	CguigeSet guige;
	CyonghuSet yonghu;
	switch(m_Combo.GetCurSel())
	{
	case 0:
		mingchen.Open();
		m_List.DeleteAllItems();
		for(;!mingchen.IsEOF();mingchen.MoveNext())
			m_List.InsertItem(0,mingchen.m_Mingchen);
		break;
	case 1:
		guige.Open();
		m_List.DeleteAllItems();
		for(;!guige.IsEOF();guige.MoveNext())
			m_List.InsertItem(0,guige.m_Guige);
		break;
	case 2:
		yonghu.Open();
		m_List.DeleteAllItems();
		for(;!yonghu.IsEOF();yonghu.MoveNext())
			m_List.InsertItem(0,yonghu.m_Yonghu);
		break;
	default:
#ifdef _DEBUG
		ASSERT(1);
#endif
		break;
	}
	return;

}

void CWeihuDlg::OnBnClickedButton1()
{
	UpdateData();
	if (m_in.IsEmpty())
	{
		AfxMessageBox("��������մ�");
		return;
	}
	CString sql="";
	try
	{
		sql.Format("insert into %s values('%s')",m_table,m_in);
		dbase.ExecuteSQL(sql);
	}
	catch (CException* e)
	{
		AfxMessageBox("�����ظ���");
		e->Delete();
	}
	Refresh();
	return;
}

void CWeihuDlg::OnBnClickedButton2()
{
	UpdateData();
	int i=m_List.GetSelectionMark();
	if (i==-1)
		return;
	CString sql="";
	sql.Format("delete %s where %s='%s'",m_table,m_table,m_List.GetItemText(i,0));
	dbase.ExecuteSQL(sql);
	Refresh();
	return;
}

void CWeihuDlg::OnLvnKeydownList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLVKEYDOWN pLVKeyDow = reinterpret_cast<LPNMLVKEYDOWN>(pNMHDR);
	if (pLVKeyDow->wVKey==VK_DELETE)
		OnBnClickedButton2();
	if (pLVKeyDow->wVKey==VK_INSERT)
		OnBnClickedButton1();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}

void CWeihuDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	if (nChar==VK_DELETE)
		OnBnClickedButton2();
	if (nChar==VK_INSERT)
		OnBnClickedButton1();
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

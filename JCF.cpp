// JCF.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "JCF.h"
#include "MainFrm.h"

#include "JCFSet.h"
#include "JCFDoc.h"
#include "JCFView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int Output(CListCtrl *p,CWnd *parent)
{
	CString strPath;
	char szFileters[] = "Excel(*.xls)|*.xls||";
    CString filename, filePath;
	
	CFileDialog m_ExportDlg(FALSE,"xls", "*.xls",
		OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_ALLOWMULTISELECT,szFileters,parent);
	static char sztitle[] = _T("���");
	m_ExportDlg.m_ofn.lpstrTitle = sztitle;
	
	if(m_ExportDlg.DoModal()==IDCANCEL)return 0;
	DeleteFile(m_ExportDlg.GetPathName());
	
	CString strtemp;
	// CStudentDao m_StudentDao;
	
	CSpreadSheet SS(m_ExportDlg.GetPathName(), _T("XDDMS"),FALSE);
	CStringArray sampleArray, testRow;
	SS.DeleteSheet();
	SS.BeginTransaction();
	
	int row = 0,totalcount;
	char strarray[100];
	HDITEM hdi;
	int count;
	TCHAR lpBuffer[100];
	sampleArray.RemoveAll();
	CHeaderCtrl *m_pHdrCtrl =p->GetHeaderCtrl();
    count = m_pHdrCtrl->GetItemCount();
	hdi.mask = HDI_TEXT;
	hdi.pszText = lpBuffer;
	hdi.cchTextMax = 100;
	for(int j=0;j<count;j++)
	{
		m_pHdrCtrl->GetItem(j,&hdi);
		strtemp = (CString)hdi.pszText;
		sampleArray.Add(strtemp);
	}
	
	if(!SS.AddHeaders(sampleArray,TRUE))
		AfxMessageBox(SS.GetLastError());
	totalcount =p->GetItemCount();
	
	for(row=0;row<totalcount;row++)
	{
		sampleArray.RemoveAll();
		for(int j=0;j<count;j++)
		{
			p->GetItemText(row,j,strarray,sizeof(char[100]));
			strtemp = (CString)strarray;
			sampleArray.Add(strtemp);
		}
		SS.AddRow(sampleArray);
	}	
	SS.Commit();
	
	return 0;
/*	COutDlg temp;
	temp.DoModal();
*/	
}

// CJCFApp

BEGIN_MESSAGE_MAP(CJCFApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CJCFApp ����

CJCFApp::CJCFApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CJCFApp ����

CJCFApp theApp;
class CJCFView *GloView=NULL;
CDatabase dbase;

// CJCFApp ��ʼ��
int AppendSql(CString *sql,CString app)
{
	CString temp(_T(""));
	int i=0;
	if (sql==NULL||sql->IsEmpty()||app.IsEmpty())
		return -1;
	if (sql->Find("where")==(-1))
	{
		sql->AppendFormat(" where %s",app);
	}
	else
	{
		sql->AppendFormat(" and %s",app);
	}
	return 0;
}
int SqlToList(CListCtrl *inlist,CString sql)
{
	//��ʼ��//
	CJCFSet jcf;
	if (sql=="")
		jcf.Open();
	else
		jcf.Open((-1),sql);
	inlist->DeleteAllItems();
	while(inlist->DeleteColumn(0));
	int i=0;
	if (inlist->InsertColumn(i, "��Ʒ����",LVCFMT_LEFT,150) != i)
	{
		ASSERT(FALSE);
		return 1;
	}
	i++;
	if (inlist->InsertColumn(i, "���",LVCFMT_LEFT,90) != i)
	{
		ASSERT(FALSE);
		return 1;
	}
	i++;
	if (inlist->InsertColumn(i, "���",LVCFMT_LEFT,80) != i)
	{
		ASSERT(FALSE);
		return 1;
	}
	i++;
	if (inlist->InsertColumn(i, "����",LVCFMT_LEFT,50) != i)
	{
		ASSERT(FALSE);
		return 1;
	}
	i++;
	if (inlist->InsertColumn(i, "��������",LVCFMT_LEFT,100) != i)
	{
		ASSERT(FALSE);
		return 1;
	}
	i++;
	if (inlist->InsertColumn(i, "�û�",LVCFMT_LEFT, 150) != i)
	{
		ASSERT(FALSE);
		return 1;
	}
	i++;
	if (inlist->InsertColumn(i, "��������",LVCFMT_LEFT,80) != i)
	{
		ASSERT(FALSE);
		return 1;
	}
	i++;
	i=1;
	
	///////////list//////////////////////
	int k=0;
	CString str="";
	while(1)
	{
		i=1;
		if (jcf.IsEOF()) 
			break;
		inlist->InsertItem(k,jcf.m_Mingchen);
		inlist->SetItem(k, i++, LVIF_TEXT,jcf.m_Guige, -1, 0, 0, 0);
		inlist->SetItem(k, i++, LVIF_TEXT,jcf.m_Xianghao, -1, 0, 0, 0);
		inlist->SetItem(k, i++, LVIF_TEXT,jcf.m_Fahao, -1, 0, 0, 0);
		inlist->SetItem(k, i++, LVIF_TEXT,jcf.m_Riqi.Format("%Y-%m-%d"), -1, 0, 0, 0);
		inlist->SetItem(k, i++, LVIF_TEXT,jcf.m_Yonghu, -1, 0, 0, 0);
		str.Format("%d",jcf.m_Bianhao);
		inlist->SetItem(k, i++, LVIF_TEXT,str, -1, 0, 0, 0);
		k++;
		jcf.MoveNext();
	}
	return 0;
}
BOOL CJCFApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControls()�����򣬽��޷��������ڡ�
	InitCommonControls();

	CWinApp::InitInstance();

	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)
	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CJCFDoc),
		RUNTIME_CLASS(CMainFrame),       // �� SDI ��ܴ���
		RUNTIME_CLASS(CJCFView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);
	// ������׼������DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	//m_pMainWnd->ShowWindow(SW_SHOW);
	//m_pMainWnd->ShowWindow(SW_HIDE);
	m_pMainWnd->ShowWindow(3);
	m_pMainWnd->UpdateWindow();
	dbase.Open("JCF");
	// �������ں�׺ʱ�ŵ��� DragAcceptFiles��
	//  �� SDI Ӧ�ó����У���Ӧ�� ProcessShellCommand  ֮����
	return TRUE;
}



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CJCFApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CJCFApp ��Ϣ�������


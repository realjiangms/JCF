// JCF.cpp : 定义应用程序的类行为。
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
	static char sztitle[] = _T("输出");
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
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CJCFApp 构造

CJCFApp::CJCFApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CJCFApp 对象

CJCFApp theApp;
class CJCFView *GloView=NULL;
CDatabase dbase;

// CJCFApp 初始化
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
	//初始化//
	CJCFSet jcf;
	if (sql=="")
		jcf.Open();
	else
		jcf.Open((-1),sql);
	inlist->DeleteAllItems();
	while(inlist->DeleteColumn(0));
	int i=0;
	if (inlist->InsertColumn(i, "产品名称",LVCFMT_LEFT,150) != i)
	{
		ASSERT(FALSE);
		return 1;
	}
	i++;
	if (inlist->InsertColumn(i, "规格",LVCFMT_LEFT,90) != i)
	{
		ASSERT(FALSE);
		return 1;
	}
	i++;
	if (inlist->InsertColumn(i, "箱号",LVCFMT_LEFT,80) != i)
	{
		ASSERT(FALSE);
		return 1;
	}
	i++;
	if (inlist->InsertColumn(i, "阀号",LVCFMT_LEFT,50) != i)
	{
		ASSERT(FALSE);
		return 1;
	}
	i++;
	if (inlist->InsertColumn(i, "销售日期",LVCFMT_LEFT,100) != i)
	{
		ASSERT(FALSE);
		return 1;
	}
	i++;
	if (inlist->InsertColumn(i, "用户",LVCFMT_LEFT, 150) != i)
	{
		ASSERT(FALSE);
		return 1;
	}
	i++;
	if (inlist->InsertColumn(i, "提货单编号",LVCFMT_LEFT,80) != i)
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
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControls()。否则，将无法创建窗口。
	InitCommonControls();

	CWinApp::InitInstance();

	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)
	// 注册应用程序的文档模板。文档模板
	// 将用作文档、框架窗口和视图之间的连接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CJCFDoc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架窗口
		RUNTIME_CLASS(CJCFView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);
	// 分析标准外壳命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	// 调度在命令行中指定的命令。如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	//m_pMainWnd->ShowWindow(SW_SHOW);
	//m_pMainWnd->ShowWindow(SW_HIDE);
	m_pMainWnd->ShowWindow(3);
	m_pMainWnd->UpdateWindow();
	dbase.Open("JCF");
	// 仅当存在后缀时才调用 DragAcceptFiles，
	//  在 SDI 应用程序中，这应在 ProcessShellCommand  之后发生
	return TRUE;
}



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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

// 用于运行对话框的应用程序命令
void CJCFApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CJCFApp 消息处理程序


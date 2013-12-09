// JCFView.cpp : CJCFView 类的实现
//

#include "stdafx.h"
#include "JCF.h"

#include "JCFSet.h"
#include "JCFDoc.h"
#include "JCFView.h"
#include ".\jcfview.h"
#include "NewDlg.h"
#include "BianhaoDlg.h"
#include "OldDlg.h"
#include "mcsearch.h"
#include "ggsearch.h"
#include "yhsearch.h"
#include "xhsearch.h"
#include "FHSearch.h"
#include "BHSearch.h"
#include "RQSearch.h"
#include "WeihuDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJCFView

IMPLEMENT_DYNCREATE(CJCFView, CRecordView)

BEGIN_MESSAGE_MAP(CJCFView, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_NEW, OnNew)
	ON_COMMAND(ID_OLD, OnOld)
	ON_COMMAND(ID_32777, On32777)
	ON_COMMAND(ID_32778, On32778)
	ON_COMMAND(ID_32783, On32783)
	ON_COMMAND(ID_32779, On32779)
	ON_COMMAND(ID_32780, On32780)
	ON_COMMAND(ID_32781, On32781)
	ON_COMMAND(ID_32782, On32782)
	ON_COMMAND(ID_32785, On32785)
	ON_COMMAND(ID_32787, On32787)
	ON_COMMAND(ID_32788, On32788)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_32786, On32786)
	ON_COMMAND(ID_32799, On32799)
	ON_COMMAND(ID_32800, On32800)
END_MESSAGE_MAP()

// CJCFView 构造/析构

CJCFView::CJCFView()
	: CRecordView(CJCFView::IDD)
	, m_sql(_T(""))
	, m_order(_T(""))
{
	m_sql.Format("select * from JCF");
	m_order.Format(" order by Riqi desc,Fahao asc,Xianghao desc");
	m_pSet = NULL;
	GloView=this;
	// TODO: 在此处添加构造代码

}

CJCFView::~CJCFView()
{
}

void CJCFView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet)
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关更多信息，请参阅 MSDN 和 ODBC 示例
	DDX_Control(pDX, IDC_LIST1, m_List);
}

BOOL CJCFView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或
	// 样式

	return CRecordView::PreCreateWindow(cs);
}

void CJCFView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_JCFSet;
	CRecordView::OnInitialUpdate();
}


// CJCFView 打印

BOOL CJCFView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CJCFView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	CRecordView::OnBeginPrinting(pDC, pInfo);
	CWaitCursor wait;
	pInfo->m_nCurPage = 0xFFFF;
	OnPrepareDC(pDC, pInfo);
	UINT nCurPage = 1;
	pInfo->m_nCurPage = nCurPage;
	pInfo->m_rectDraw.SetRect(0, 0,
	pDC->GetDeviceCaps(HORZRES),
	pDC->GetDeviceCaps(VERTRES));
	pDC->DPtoLP(&pInfo->m_rectDraw);

	pInfo->SetMaxPage(Guji(pDC,pInfo));
	m_nNext=0;
	m_nCurRow=0;
	memset(m_kaitou,0,DA_ZHI*4);

}
void CJCFView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	if (pInfo->m_nCurPage>=1000)
		AfxMessageBox("!!!!!!!!!!!!!!!!!!!走召弓虽白勺言兑！！！！！！！！！！！");
	const int mili=16;
	int mirror=MulDiv(1, pDC->GetDeviceCaps(LOGPIXELSY),
		::GetDeviceCaps(::GetDC(NULL), LOGPIXELSY));
	
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int cyChar = tm.tmMaxCharWidth;
	CRect vrect=pInfo->m_rectDraw;
	vrect.left+=10;
	vrect.top+=2*cyChar;
	vrect.bottom-=2*cyChar;
	int hcur=vrect.top;
	//^^^ logic settings;
	static bool tag=false;
	CString tail,head;
	pDC->MoveTo(vrect.left,vrect.top-cyChar/2);
	pDC->LineTo(vrect.right,vrect.top-cyChar/2);
	pDC->MoveTo(vrect.left,vrect.bottom+cyChar/2);
	pDC->LineTo(vrect.right,vrect.bottom+cyChar/2);
	tail.Format("第%d页",pInfo->m_nCurPage);
	head=tail;
	
	pDC->TextOut(vrect.left,vrect.top-2*cyChar,head);
	pDC->TextOut(vrect.left,vrect.bottom+cyChar,tail);
	/////////////////////copy fons/////////////////////
	CFont font;
	CFont* pFont =m_List.GetFont();
	LOGFONT lf;
	LOGFONT lfSys;
	if (pFont == NULL)
		return;
	VERIFY(pFont->GetObject(sizeof(LOGFONT), &lf));
	VERIFY(::GetObject(::GetStockObject(SYSTEM_FONT), sizeof(LOGFONT),
		&lfSys));
	if (lstrcmpi((LPCTSTR)lf.lfFaceName, (LPCTSTR)lfSys.lfFaceName) == 0)
		return;

	// map to printer font metrics
	HDC hDCFrom = ::GetDC(NULL);
	lf.lfHeight = lf.lfHeight*(int)(mirror);
	lf.lfWidth = lf.lfWidth*(int)(mirror);
	::ReleaseDC(NULL, hDCFrom);
	
	
	VERIFY(font.CreateFontIndirect(&lf));
	CFont* def_font = pDC->SelectObject(&font);
	pDC->GetTextMetrics(&tm);
	cyChar = tm.tmMaxCharWidth;
	///////////////////////////////////////////////////////////////////////
	vrect.bottom-=cyChar;
	int count,totalcount,row,j;
	CHeaderCtrl *listctrl=m_List.GetHeaderCtrl();
	count =listctrl->GetItemCount();
	totalcount =m_List.GetItemCount();
	char strarray[500];
	CRect rect,recttmp;
	HDITEM hdi;
	hdi.mask = HDI_TEXT;
	hdi.pszText = strarray;
	hdi.cchTextMax = 500;
	if (pInfo->m_nCurPage==1)
	{
		int nx;
		CString title="title";
		nx=(pInfo->m_rectDraw.Width()-title.GetLength()*cyChar/2)/2;
		pDC->TextOut(nx,hcur,title);//error
		hcur+=(cyChar+cyChar/2);
		vrect.top=hcur;
	}


	for(j=0;j<count;j++)
	{
		listctrl->GetItem(j,&hdi);
		listctrl->GetItemRect(j,&rect);
		recttmp=rect;
		recttmp.left=mili+rect.left*mirror+vrect.left;
		recttmp.right=rect.right*mirror+vrect.left;//-mili
		recttmp.bottom=hcur+rect.Height()*mirror;
		recttmp.top=hcur;
		pDC->DrawText(CString(strarray),&recttmp,DT_LEFT);
		//pDC->TextOut(mili+rect.left*mirror+vrect.left,hcur,CString(strarray));
	//	pDC->MoveTo(rect.left*mirror+vrect.left,hcur-mili/2);
	//	pDC->LineTo(rect.left*mirror+vrect.left,vrect.bottom+mili/2);
	}
	
	
	vrect.right=rect.right*mirror+vrect.left;
	//pDC->MoveTo(vrect.right,hcur-mili/2);
	//pDC->LineTo(vrect.right,vrect.bottom+mili/2);
	pDC->MoveTo(vrect.left,hcur-mili/2);
	pDC->LineTo(vrect.right,hcur-mili/2);
	hcur+=(mirror*(rect.Height()));
	pDC->MoveTo(vrect.left,hcur-mili/2);
	pDC->LineTo(vrect.right,hcur-mili/2);
	if (pInfo->m_nCurPage==1)
		row=0;
	else
	{
		if ((row=m_kaitou[pInfo->m_nCurPage])==0)
			row=m_nCurRow;
		
			
	}
	for(;row<totalcount;row++)
	{
		
		if (hcur+mirror*(rect.Height())>=vrect.bottom)
				break;	
		for(j=0;j<count;j++)
		{
            m_List.GetSubItemRect(row,j,LVIR_LABEL,rect);
			m_List.GetItemText(row,j,strarray,sizeof(char[500]));
			recttmp=rect;
			recttmp.left=mili+rect.left*mirror+vrect.left;
			recttmp.right=rect.right*mirror+vrect.left;//-mili
			recttmp.bottom=hcur+rect.Height()*mirror;
			recttmp.top=hcur;
			//pDC->TextOut(mili+rect.left*mirror+vrect.left,hcur,CString(strarray));
			
			pDC->DrawText(CString(strarray),&recttmp,DT_LEFT);
			//pDC->Rectangle(&recttmp);
			
		}
		hcur+=(mirror*(rect.Height()));
		hcur+=mili;
		pDC->MoveTo(vrect.left,hcur-mili);
		pDC->LineTo(vrect.right,hcur-mili);
		
		

	}
	vrect.bottom=hcur-mili;
	for(j=0;j<count;j++)
	{
		listctrl->GetItem(j,&hdi);
		listctrl->GetItemRect(j,&rect);
		pDC->MoveTo(rect.left*mirror+vrect.left,vrect.top-mili/2);
		pDC->LineTo(rect.left*mirror+vrect.left,vrect.bottom+mili/2);
	}
	pDC->MoveTo(vrect.right,vrect.top-mili/2);
	pDC->LineTo(vrect.right,vrect.bottom+mili/2);
	
	if (m_kaitou[pInfo->m_nCurPage]==0)
	{
		
		m_kaitou[pInfo->m_nCurPage]=m_nCurRow;
		m_nCurRow=row;
	}
	//if (row>=totalcount)
	//	pInfo->SetMaxPage(pInfo->m_nCurPage);
	//else
//		pInfo->SetMaxPage(pInfo->m_nCurPage+1);
	

	pDC->SelectObject(def_font);

	// Done with the font. Delete the font object.
	font.DeleteObject();



}


void CJCFView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	m_nCurRow=0;
	memset(m_kaitou,0,sizeof(int(DA_ZHI)));
}


// CJCFView 诊断

#ifdef _DEBUG
void CJCFView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CJCFView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CJCFDoc* CJCFView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJCFDoc)));
	return (CJCFDoc*)m_pDocument;
}
#endif //_DEBUG


// CJCFView 数据库支持
CRecordset* CJCFView::OnGetRecordset()
{
	return m_pSet;
}



// CJCFView 消息处理程序

void CJCFView::OnNew()
{
	CNewDlg temp;
	CString sql("");
	
	int i=0;
	int heji=0;

	INT_PTR ret;
	while((ret = temp.DoModal())!=IDCANCEL)
	{
		for (std::vector<CString>::const_iterator it=temp.m_fahaos.begin();it!=temp.m_fahaos.end();it++)
		{
			sql.Format("insert into JCF(Mingchen,Guige,Xianghao,Fahao,Riqi,Yonghu,Bianhao) values ('%s','%s','%s','%s','%s','%s','%d')",temp.m_mingchen,temp.m_guige,temp.m_xianghao,*it,temp.m_riqi.Format("%Y-%m-%d"),temp.m_yonghu,temp.m_bianhao);
			dbase.ExecuteSQL(sql);		
			heji+=1;
		}		
		temp.m_heji.Format("共 %d 个",heji);
		i=1;
	}
	CString ssql="select * from JCF where Bianhao=";
	ssql.AppendFormat("%d",temp.m_bianhao);
	if (i)
		Refresh(ssql);
   
        
}

int CJCFView::Refresh(CString sql)
{
	if (sql.IsEmpty())
		return	SqlToList(&m_List,m_sql+m_order);
	else
		return	SqlToList(&m_List,sql);
}

void CJCFView::OnOld()
{	
    CBianhaoDlg bianhao;
	if (bianhao.DoModal()==IDOK)
	{
		COldDlg old;
		old.m_bianhao=bianhao.m_bianhao;
		old.DoModal();
		CString sql="select * from JCF where Bianhao=";
		sql.AppendFormat("%d",bianhao.m_bianhao);
		Refresh(sql);
		return;
	}
	else
		return;
}

void CJCFView::On32777()
{
	CMCSearch search;
	CString app;
	switch(search.DoModal())
	{
	case IDOK:
		m_sql.Format("select * from JCF where Mingchen='%s'",search.m_mingchen);
		break;
	case IDC_BUTTON1:
		app.Format("Mingchen='%s'",search.m_mingchen);
		AppendSql(&m_sql,app);
		break;
	case IDCANCEL:
		break;
	default:
		break;
	}
	Refresh();

}

void CJCFView::On32778()
{
	CGGSearch search;
	CString app;
	switch(search.DoModal())
	{
	case IDOK:
		m_sql.Format("select * from JCF where Guige='%s'",search.m_guige);
		break;
	case IDC_BUTTON1:
		app.Format("Guige='%s'",search.m_guige);
		AppendSql(&m_sql,app);
		break;
	case IDCANCEL:
		break;
	default:
		break;
	}
	Refresh();

}

void CJCFView::On32783()
{
	CYHSearch search;
	CString app;
	switch(search.DoModal())
	{
	case IDOK:
		m_sql.Format("select * from JCF where Yonghu='%s'",search.m_yonghu);
		break;
	case IDC_BUTTON1:
		app.Format("Yonghu='%s'",search.m_yonghu);
		AppendSql(&m_sql,app);
		break;
	case IDCANCEL:
		break;
	default:
		break;
	}
	Refresh();
}

void CJCFView::On32779()
{
	CXHSearch search;
	CString app;
	switch(search.DoModal())
	{
	case IDOK:
		m_sql.Format("select * from JCF where Xianghao='%s'",search.m_xianghao);
		break;
	case IDC_BUTTON1:
		app.Format("Xianghao='%s'",search.m_xianghao);
		AppendSql(&m_sql,app);
		break;
	case IDCANCEL:
		break;
	default:
		break;
	}
	Refresh();
}

void CJCFView::On32780()
{
	CFHSearch search;
	CString app;
	INT_PTR result=search.DoModal();
	switch(result)
	{
    case IDOK:
		m_sql.Format("select * from JCF where Fahao between '%s' and '%s'",search.m_fahao1,search.m_fahao2);
		break;
	case IDC_BUTTON1:
		app.Format("Fahao between '%s' and '%s'",search.m_fahao1,search.m_fahao2);
		AppendSql(&m_sql,app);
		break;
	case IDCANCEL:
		break;
	default:
		break;
	}
	Refresh();
}

void CJCFView::On32781()
{
	CBHSearch search;
	CString app;
	INT_PTR result=search.DoModal();
	switch(result)
	{
    case IDOK:
		m_sql.Format("select * from JCF where Bianhao>=%d and Bianhao<=%d",search.m_bianhao1,search.m_bianhao2);
		break;
	case IDC_BUTTON1:
		app.Format("Bianhao>=%d and Bianhao<=%d",search.m_bianhao1,search.m_bianhao2);
		AppendSql(&m_sql,app);
		break;
	case IDCANCEL:
		break;
	default:
		break;
	}
	Refresh();
}

void CJCFView::On32782()
{
	CRQSearch search;
	CString app;
	INT_PTR result=search.DoModal();
	switch(result)
	{
    case IDOK:
		m_sql.Format("select * from JCF where Riqi>='%d-%d-%d' and Riqi<='%d-%d-%d'",search.m_year1,search.m_month1,search.m_day1,search.m_year2,search.m_month2,search.m_day2);
		break;
	case IDC_BUTTON1:
		app.Format("Riqi>='%d-%d-%d' and Riqi<='%d-%d-%d'",search.m_year1,search.m_month1,search.m_day1,search.m_year2,search.m_month2,search.m_day2);
		AppendSql(&m_sql,app);
		break;
	case IDCANCEL:
		break;
	default:
		break;
	}
	CJCFView::Refresh();
}

void CJCFView::On32785()
{
	CWeihuDlg weihu;
	weihu.DoModal();
	
}


void CJCFView::On32787()
{
	m_sql.Format("select * from JCF");
	m_order.Format(" order by Riqi desc,Fahao asc");
	m_List.DeleteAllItems();
	while(m_List.DeleteColumn(0));

}

void CJCFView::On32788()
{
	CFont* pFont = GetFont();
	LOGFONT lf,m_lfDefFont;
	if (pFont != NULL)
		pFont->GetObject(sizeof(LOGFONT), &lf);
	else
		::GetObject(GetStockObject(SYSTEM_FONT), sizeof(LOGFONT), &lf);

	CFontDialog dlg(&lf, CF_SCREENFONTS|CF_INITTOLOGFONTSTRUCT);

	if (dlg.DoModal() == IDOK)
	{
		// switch to new font.
		m_font.DeleteObject();
		
		if (m_font.CreateFontIndirect(&lf))
		{
			CWaitCursor wait;

			m_List.SetFont(&m_font);
			m_lfDefFont = lf;

		}
	}
}


int CJCFView::Guji(CDC* pDC, CPrintInfo* pInfo)
{
	const int mili=16;
	int mirror=MulDiv(1, pDC->GetDeviceCaps(LOGPIXELSY),
		::GetDeviceCaps(::GetDC(NULL), LOGPIXELSY));
	
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int cyChar = tm.tmMaxCharWidth;
	CRect vrect=pInfo->m_rectDraw;
	vrect.left+=10;
	vrect.top+=2*cyChar;
	vrect.bottom-=2*cyChar;
	int hcur=vrect.top;
	//^^^ logic settings;
		/////////////////////copy fons/////////////////////
	CFont font;
	CFont* pFont =m_List.GetFont();
	LOGFONT lf;
	LOGFONT lfSys;
	if (pFont == NULL)
		return -1;
	VERIFY(pFont->GetObject(sizeof(LOGFONT), &lf));
	VERIFY(::GetObject(::GetStockObject(SYSTEM_FONT), sizeof(LOGFONT),
		&lfSys));
	if (lstrcmpi((LPCTSTR)lf.lfFaceName, (LPCTSTR)lfSys.lfFaceName) == 0)
		return -1;

	// map to printer font metrics
	HDC hDCFrom = ::GetDC(NULL);
	lf.lfHeight = lf.lfHeight*(int)(mirror);
	lf.lfWidth = lf.lfWidth*(int)(mirror);
	::ReleaseDC(NULL, hDCFrom);
	
	
	VERIFY(font.CreateFontIndirect(&lf));
	CFont* def_font = pDC->SelectObject(&font);
	pDC->GetTextMetrics(&tm);
	cyChar = tm.tmMaxCharWidth;
	///////////////////////////////////////////////////////////////////////
	vrect.bottom-=cyChar;
	static bool tag=false;
	int count,totalcount,row;
	CHeaderCtrl *listctrl=m_List.GetHeaderCtrl();
	count =listctrl->GetItemCount();
	totalcount =m_List.GetItemCount();
	CRect rect,recttmp;
	
	hcur+=(cyChar+cyChar/2);
	vrect.top=hcur;
	listctrl->GetItemRect(0,&rect);
	hcur+=(mirror*(rect.Height()));
	int maxpage=1;
	m_List.GetSubItemRect(0,0,LVIR_LABEL,rect);
	int hight=rect.Height();
	for(row=0;row<totalcount;row++)
	{
		
		if (hcur+mirror*(rect.Height())>=vrect.bottom)
		{
			hcur=vrect.top;
			maxpage++;
            continue;
		}
        
		hcur+=(mirror*hight);
		hcur+=mili;
	}
	pDC->SelectObject(def_font);

	// Done with the font. Delete the font object.
	font.DeleteObject();

	return maxpage;

}


void CJCFView::OnFileSave()
{
	Output(&m_List,this);
	return;
}

void CJCFView::On32786()
{
	Refresh();
}

void CJCFView::On32799()
{
	m_order.Format(" order by Fahao asc,Riqi desc,Xianghao desc");
	Refresh();
}

void CJCFView::On32800()
{
	m_order.Format(" order by Riqi desc,Fahao asc,Xianghao desc");
	Refresh();
}

// JCF.h : JCF 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error 在包含用于 PCH 的此文件之前包含“stdafx.h” 
#endif

#include "resource.h"       // 主符号
#include "JCFSet.h"
#include "mingchenset.h"
#include "guigeset.h"
#include "yonghuset.h"
#include "CSpreadSheet.h"
int Output(CListCtrl *p,CWnd *parent);
// CJCFApp:
// 有关此类的实现，请参阅 JCF.cpp
//
class CJCFView;
class CJCFApp : public CWinApp
{
public:
	CJCFApp();


// 重写
public:
	virtual BOOL InitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};
int AppendSql(CString *sql,CString app);
int SqlToList(CListCtrl *inlist,CString sql);
extern CJCFApp theApp;
extern CJCFView *GloView;
extern CDatabase dbase;

// JCF.h : JCF Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h�� 
#endif

#include "resource.h"       // ������
#include "JCFSet.h"
#include "mingchenset.h"
#include "guigeset.h"
#include "yonghuset.h"
#include "CSpreadSheet.h"
int Output(CListCtrl *p,CWnd *parent);
// CJCFApp:
// �йش����ʵ�֣������ JCF.cpp
//
class CJCFView;
class CJCFApp : public CWinApp
{
public:
	CJCFApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};
int AppendSql(CString *sql,CString app);
int SqlToList(CListCtrl *inlist,CString sql);
extern CJCFApp theApp;
extern CJCFView *GloView;
extern CDatabase dbase;

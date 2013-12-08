// JCFSet.h: CJCFSet ��Ľӿ�
//


#pragma once

// ���������� 2004��8��9��, 14:49

class CJCFSet : public CRecordset
{
public:
	CJCFSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CJCFSet)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	CStringA	m_Mingchen;
	CStringA	m_Guige;
	CStringA	m_Xianghao;
	CStringA	m_Fahao;
	CTime	m_Riqi;
	CStringA	m_Yonghu;
	long    	m_Bianhao;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


// MyBrowserDoc.cpp : CMyBrowserDoc ���ʵ��
//

#include "stdafx.h"
#include "MyBrowser.h"

#include "MyBrowserDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyBrowserDoc

IMPLEMENT_DYNCREATE(CMyBrowserDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyBrowserDoc, CDocument)
	
END_MESSAGE_MAP()


// CMyBrowserDoc ����/����

CMyBrowserDoc::CMyBrowserDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMyBrowserDoc::~CMyBrowserDoc()
{
}

BOOL CMyBrowserDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMyBrowserDoc ���л�

void CMyBrowserDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CMyBrowserDoc ���

#ifdef _DEBUG
void CMyBrowserDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyBrowserDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMyBrowserDoc ����


// MyBrowserDoc.cpp : CMyBrowserDoc 类的实现
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


// CMyBrowserDoc 构造/析构

CMyBrowserDoc::CMyBrowserDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMyBrowserDoc::~CMyBrowserDoc()
{
}

BOOL CMyBrowserDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMyBrowserDoc 序列化

void CMyBrowserDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CMyBrowserDoc 诊断

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


// CMyBrowserDoc 命令


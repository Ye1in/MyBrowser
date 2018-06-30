// MyBrowserView.cpp : CMyBrowserView 类的实现
//

#include "stdafx.h"
#include "MyBrowser.h"

#include "MyBrowserDoc.h"
#include "MyBrowserView.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyBrowserView

IMPLEMENT_DYNCREATE(CMyBrowserView, CHtmlView)

BEGIN_MESSAGE_MAP(CMyBrowserView, CHtmlView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_BN_CLICKED(PR, &CMyBrowserView::OnBnClickedPr)
	ON_BN_CLICKED(NE, &CMyBrowserView::OnBnClickedNe)
	ON_BN_CLICKED(FRESH, &CMyBrowserView::OnBnClickedFresh)
	ON_BN_CLICKED(STOP, &CMyBrowserView::OnBnClickedStop)
	ON_BN_CLICKED(HOME, &CMyBrowserView::OnBnClickedHome)

END_MESSAGE_MAP()

// CMyBrowserView 构造/析构

CMyBrowserView::CMyBrowserView()
{
	// TODO: 在此处添加构造代码

}

CMyBrowserView::~CMyBrowserView()
{
}

BOOL CMyBrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CHtmlView::PreCreateWindow(cs);
}

void CMyBrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("www.ujn.edu.cn"),NULL,NULL);
}


// CMyBrowserView 打印



// CMyBrowserView 诊断

#ifdef _DEBUG
void CMyBrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CMyBrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CMyBrowserDoc* CMyBrowserView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyBrowserDoc)));
	return (CMyBrowserDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyBrowserView 消息处理程序

void CMyBrowserView::OnBnClickedPr()
{
	// TODO: 在此添加控件通知处理程序代码
	CMyBrowserView::GoBack();
}

void CMyBrowserView::OnBnClickedNe()
{
	// TODO: 在此添加控件通知处理程序代码
	CMyBrowserView::GoForward();
}

void CMyBrowserView::OnBnClickedFresh()
{
	// TODO: 在此添加控件通知处理程序代码
	CMyBrowserView::Refresh();
}

void CMyBrowserView::OnBnClickedStop()
{
	// TODO: 在此添加控件通知处理程序代码
	CMyBrowserView::Stop();
}

void CMyBrowserView::OnBnClickedHome()
{
	// TODO: 在此添加控件通知处理程序代码
	CMyBrowserView::GoHome();
}

void CMyBrowserView::OnDocumentComplete(LPCTSTR lpszURL)
{
	
	// 每次当前页面改变，更新地址栏的内容和窗口的标题
	((CMainFrame *)GetParentFrame())->SetURL(lpszURL);
	GetDocument()->SetTitle(lpszURL);

	// TODO: 在此添加专用代码和/或调用基类
	CHtmlView::OnDocumentComplete(lpszURL);


}



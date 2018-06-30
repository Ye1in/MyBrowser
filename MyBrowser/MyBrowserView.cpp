// MyBrowserView.cpp : CMyBrowserView ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_BN_CLICKED(PR, &CMyBrowserView::OnBnClickedPr)
	ON_BN_CLICKED(NE, &CMyBrowserView::OnBnClickedNe)
	ON_BN_CLICKED(FRESH, &CMyBrowserView::OnBnClickedFresh)
	ON_BN_CLICKED(STOP, &CMyBrowserView::OnBnClickedStop)
	ON_BN_CLICKED(HOME, &CMyBrowserView::OnBnClickedHome)

END_MESSAGE_MAP()

// CMyBrowserView ����/����

CMyBrowserView::CMyBrowserView()
{
	// TODO: �ڴ˴���ӹ������

}

CMyBrowserView::~CMyBrowserView()
{
}

BOOL CMyBrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CHtmlView::PreCreateWindow(cs);
}

void CMyBrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("www.ujn.edu.cn"),NULL,NULL);
}


// CMyBrowserView ��ӡ



// CMyBrowserView ���

#ifdef _DEBUG
void CMyBrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CMyBrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CMyBrowserDoc* CMyBrowserView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyBrowserDoc)));
	return (CMyBrowserDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyBrowserView ��Ϣ�������

void CMyBrowserView::OnBnClickedPr()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMyBrowserView::GoBack();
}

void CMyBrowserView::OnBnClickedNe()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMyBrowserView::GoForward();
}

void CMyBrowserView::OnBnClickedFresh()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMyBrowserView::Refresh();
}

void CMyBrowserView::OnBnClickedStop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMyBrowserView::Stop();
}

void CMyBrowserView::OnBnClickedHome()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMyBrowserView::GoHome();
}

void CMyBrowserView::OnDocumentComplete(LPCTSTR lpszURL)
{
	
	// ÿ�ε�ǰҳ��ı䣬���µ�ַ�������ݺʹ��ڵı���
	((CMainFrame *)GetParentFrame())->SetURL(lpszURL);
	GetDocument()->SetTitle(lpszURL);

	// TODO: �ڴ����ר�ô����/����û���
	CHtmlView::OnDocumentComplete(lpszURL);


}



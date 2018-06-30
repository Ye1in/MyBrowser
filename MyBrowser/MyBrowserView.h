// MyBrowserView.h : CMyBrowserView ��Ľӿ�
//


#pragma once

class CMyBrowserView : public CHtmlView
{
protected: // �������л�����
	CMyBrowserView();
	DECLARE_DYNCREATE(CMyBrowserView)

// ����
public:
	CMyBrowserDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMyBrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedPr();
	afx_msg void OnBnClickedNe();
	afx_msg void OnBnClickedFresh();
	afx_msg void OnBnClickedStop();
	afx_msg void OnBnClickedHome();
	virtual void OnDocumentComplete(LPCTSTR lpszURL);
	afx_msg void OnBnClickedSavebutton();
};

#ifndef _DEBUG  // MyBrowserView.cpp �еĵ��԰汾
inline CMyBrowserDoc* CMyBrowserView::GetDocument() const
   { return reinterpret_cast<CMyBrowserDoc*>(m_pDocument); }
#endif


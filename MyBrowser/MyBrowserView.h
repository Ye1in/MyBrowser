// MyBrowserView.h : CMyBrowserView 类的接口
//


#pragma once

class CMyBrowserView : public CHtmlView
{
protected: // 仅从序列化创建
	CMyBrowserView();
	DECLARE_DYNCREATE(CMyBrowserView)

// 属性
public:
	CMyBrowserDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMyBrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // MyBrowserView.cpp 中的调试版本
inline CMyBrowserDoc* CMyBrowserView::GetDocument() const
   { return reinterpret_cast<CMyBrowserDoc*>(m_pDocument); }
#endif


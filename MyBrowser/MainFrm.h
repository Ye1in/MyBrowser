// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include <vector>
#include <string>
#include <regex> 

using std::regex;
using std::string;
using std::vector;
class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 属性
public:
	vector<string> v;
// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	CReBar      m_wndReBar;
	CDialogBar      m_wndDlgBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedsubmit();
	afx_msg void OnStnClickedSb();
	afx_msg void OnBnClickedSb();
	void SetURL(LPCTSTR lpszURL);

	afx_msg void OnBnClickedSavebutton();

	afx_msg void OnMenu();
	afx_msg void OnShoucang();
	afx_msg void MyFunction(CString address);
	afx_msg void On32774();
	afx_msg void OnEnChangeAddress();
	static void SplitString(const string& s, vector<string>& v, const string& c);
};
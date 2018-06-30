// MainFrm.h : CMainFrame ��Ľӿ�
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
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:
	vector<string> v;
// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	CReBar      m_wndReBar;
	CDialogBar      m_wndDlgBar;

// ���ɵ���Ϣӳ�亯��
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
#pragma once


// lishijiludlg 对话框
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class lishijiludlg : public CDialog
{
	DECLARE_DYNAMIC(lishijiludlg)

public:
	lishijiludlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~lishijiludlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = LISHIJILU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedShanchu();
	vector<string> v;
private:
	CListBox *list;
	
public:
	afx_msg void OnLbnDblclkLishilist();
};

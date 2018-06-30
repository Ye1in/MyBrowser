#pragma once
#include "afxwin.h"
#include <Afxtempl.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
// shoucangdlg 对话框

class shoucangdlg : public CDialog
{
	DECLARE_DYNAMIC(shoucangdlg)

public:
	shoucangdlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~shoucangdlg();

// 对话框数据
	enum { IDD = SHOUCANGDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAdd();
	afx_msg void OnLbnSelchangeShoucanglist();
	afx_msg void OnBnClickedRemove();
	CString address;
	
	afx_msg void OnLbnDblclkShoucanglist();
	afx_msg void OnLbnSetfocusShoucanglist();
private:
	CListBox list;
};

// lishijiludlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MyBrowser.h"
#include "lishijiludlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"

// lishijiludlg 对话框

IMPLEMENT_DYNAMIC(lishijiludlg, CDialog)

lishijiludlg::lishijiludlg(CWnd* pParent /*=nullptr*/)
	: CDialog(LISHIJILU, pParent)
{

}

lishijiludlg::~lishijiludlg()
{
}
static fstream file;
static const CString filename{ "C:\\Users\\Skywalker\\Desktop\\lsjl.txt" };
void lishijiludlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, LISHIJILU, list);
	list = (CListBox*)GetDlgItem(LISHILIST);
	for each (auto var in v)
	{
		CString cstr(var.c_str());
		list->AddString(cstr);
	}
}


BEGIN_MESSAGE_MAP(lishijiludlg, CDialog)
	ON_BN_CLICKED(SHANCHU, &lishijiludlg::OnBnClickedShanchu)
	ON_LBN_DBLCLK(LISHILIST, &lishijiludlg::OnLbnDblclkLishilist)
END_MESSAGE_MAP()


// lishijiludlg 消息处理程序


void lishijiludlg::OnBnClickedShanchu()
{
	int sel = list->GetCurSel();
	if (sel == -1) {
		this->EndDialog(0);
		return;
	}
	file.open(filename, ios::in | ios::out);
	if (!file) {
		cout << "can't open input file \"" << filename << "\"";
		exit(EXIT_FAILURE);
	}
	string str;
	CMainFrame::SplitString(str, v, ",");
	auto pos = v.begin() + sel;
	v.erase(pos);
	file.close();
	file.open(filename, ios::out);
	pos = v.begin();
	for each (auto var in v)
	{
		file << var << ",";
		++pos;
	}
	file.close();
	list->DeleteString(sel);

	}



void lishijiludlg::OnLbnDblclkLishilist()
{
	int sel = list->GetCurSel();
	CString csad;
	list->GetText(sel, csad);
	string address(CW2A(csad.GetString()));
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CString cstr(address.c_str());
	pFrame->MyFunction(cstr);
}

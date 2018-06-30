// shoucangdlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyBrowser.h"
#include "shoucangdlg.h"
#include "MainFrm.h"
// shoucangdlg 对话框

IMPLEMENT_DYNAMIC(shoucangdlg, CDialog)


shoucangdlg::shoucangdlg(CWnd* pParent /*=NULL*/)
	: CDialog(shoucangdlg::IDD, pParent)
	, address("")
{
}

shoucangdlg::~shoucangdlg()
{
}
static fstream file;
static const CString filename{ "C:\\Users\\Skywalker\\Desktop\\save.txt" };
void shoucangdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, SHOUCANGLIST, list);
	
	file.open(filename, ios::in | ios::out | ios::app);
	if (!file) {
		cout << "can't open input file \"" << filename << "\"";
		exit(EXIT_FAILURE);
	}
	string str;
	file >> str;
	vector<string>v;
	CMainFrame::SplitString(str, v, ",");
	for each (auto var in v)
	{
		CString cstr(var.c_str());
		list.AddString(cstr);
	}
	file.close();
}


BEGIN_MESSAGE_MAP(shoucangdlg, CDialog)
	ON_BN_CLICKED(ADD, &shoucangdlg::OnBnClickedAdd)

	ON_BN_CLICKED(REMOVE, &shoucangdlg::OnBnClickedRemove)
	ON_LBN_DBLCLK(SHOUCANGLIST, &shoucangdlg::OnLbnDblclkShoucanglist)
END_MESSAGE_MAP()


// shoucangdlg 消息处理程序

void shoucangdlg::OnBnClickedAdd()
{
	file.open(filename, ios::app);
	if (!file) {
		cout << "can't open input file \"" << filename << "\"";
		exit(EXIT_FAILURE);
	}
	string str(CW2A(address.GetString()));
	file << str << ",";
	file.close();
	list.AddString(address);
}


void shoucangdlg::OnBnClickedRemove()
{
	int sel = list.GetCurSel();	
	if (sel == -1) {
		this->EndDialog(0);
		return;
	}
	file.open(filename, ios::in | ios::out);
	if (!file) {
		cout << "can't open input file \"" << filename << "\"";
		exit(EXIT_FAILURE);
	}
	vector<string> v;
	string str;
	file >> str;
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
	list.DeleteString(sel);
}


void shoucangdlg::OnLbnDblclkShoucanglist()
{
	int sel = list.GetCurSel();
	CString csad;
	list.GetText(sel, csad);
	string address(CW2A(csad.GetString()));
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CString cstr(address.c_str());
	pFrame->MyFunction(cstr);
}


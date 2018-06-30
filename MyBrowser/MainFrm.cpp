// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "MyBrowser.h"
#include "shoucangdlg.h"
#include "MainFrm.h"
#include "lishijiludlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_BN_CLICKED(SB, &CMainFrame::OnBnClickedSb)
	


	ON_COMMAND(SHOUCANG, &CMainFrame::OnShoucang)
	ON_COMMAND(ID_32774, &CMainFrame::On32774)
	ON_EN_CHANGE(ADDRESS, &CMainFrame::OnEnChangeAddress)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
	fstream file;
	CString filename{ "C:\\Users\\Skywalker\\Desktop\\lsjl.txt" };
	file.open(filename, ios::in | ios::out | ios::app);
	if (!file) {
		cout << "can't open input file \"" << filename << "\"";
		exit(EXIT_FAILURE);
	}
	string str;
	file >> str;
	SplitString(str, v, ",");
	file.close();
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT | TBSTYLE_TRANSPARENT) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndDlgBar.Create(this, IDR_MAINFRAME, 
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("未能创建对话栏\n");
		return -1;		// 未能创建
	}

	/*if (!m_wndReBar.Create(this) ||
		!m_wndReBar.AddBar(&m_wndToolBar) ||
		!m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("未能创建 Rebar\n");
		return -1;      // 未能创建
	}*/

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}

	// TODO: 如果不需要工具提示，则将此移除
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}


// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame 消息处理程序





void CMainFrame::OnBnClickedSb()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sWebAddress;
	// 从编辑框获取用户输入的Web地址
	m_wndDlgBar.GetDlgItem(ADDRESS)->GetWindowText(sWebAddress);
	// 浏览相应的网页
	((CHtmlView *)GetActiveView())->Navigate(sWebAddress);

}

void CMainFrame::SetURL(LPCTSTR lpszURL)
{
	m_wndDlgBar.GetDlgItem(ADDRESS)->SetWindowTextW(lpszURL);
}



void CMainFrame::OnShoucang()
{

	CString sWebAddress;
	m_wndDlgBar.GetDlgItem(ADDRESS)->GetWindowText(sWebAddress);
	shoucangdlg test;
	test.address=sWebAddress;
	test.DoModal();
}

void CMainFrame::MyFunction(CString address)
{
	((CHtmlView *)GetActiveView())->Navigate(address);
}


void CMainFrame::On32774()
{
	lishijiludlg test;
	test.v = this->v;
	test.DoModal();
}


void CMainFrame::OnEnChangeAddress()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFrameWnd::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	fstream file;
	CString filename{ "C:\\Users\\Skywalker\\Desktop\\lsjl.txt" };
	file.open(filename, ios::app);
	if (!file) {
		cout << "can't open input file \"" << filename << "\"";
		exit(EXIT_FAILURE);
	}
	CString address;
	m_wndDlgBar.GetDlgItem(ADDRESS)->GetWindowText(address);
	string str(CW2A(address.GetString()));
	string::size_type pos1 = str.length();
	string::size_type pos2 = str.rfind(".");
//	long long tal = pos1 - pos2;
	if (pos2<200) {
		string domain = str.substr(pos2, pos1);
		regex re{ "(^.cn\\S)|(^.com\\S)" };
		if (regex_match(domain, re)) {
			file << str << ",";
			file.close();
			this->v.push_back(str);
		}
	}
}



void CMainFrame::SplitString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}

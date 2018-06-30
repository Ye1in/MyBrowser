// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
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
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndDlgBar.Create(this, IDR_MAINFRAME, 
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("δ�ܴ����Ի���\n");
		return -1;		// δ�ܴ���
	}

	/*if (!m_wndReBar.Create(this) ||
		!m_wndReBar.AddBar(&m_wndToolBar) ||
		!m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("δ�ܴ��� Rebar\n");
		return -1;      // δ�ܴ���
	}*/

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}

	// TODO: �������Ҫ������ʾ���򽫴��Ƴ�
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}


// CMainFrame ���

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


// CMainFrame ��Ϣ�������





void CMainFrame::OnBnClickedSb()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString sWebAddress;
	// �ӱ༭���ȡ�û������Web��ַ
	m_wndDlgBar.GetDlgItem(ADDRESS)->GetWindowText(sWebAddress);
	// �����Ӧ����ҳ
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFrameWnd::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

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

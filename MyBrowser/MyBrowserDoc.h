// MyBrowserDoc.h : CMyBrowserDoc ��Ľӿ�
//


#pragma once


class CMyBrowserDoc : public CDocument
{
protected: // �������л�����
	CMyBrowserDoc();
	DECLARE_DYNCREATE(CMyBrowserDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CMyBrowserDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSavebutton();
};



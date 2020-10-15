// KameraDoc.h : interface of the CKameraDoc class
//


#pragma once


class CKameraDoc : public CDocument
{
protected: // create from serialization only
	CKameraDoc();
	DECLARE_DYNCREATE(CKameraDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CKameraDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};



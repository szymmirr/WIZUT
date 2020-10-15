// KameraDoc.cpp : implementation of the CKameraDoc class
//

#include "stdafx.h"
#include "Kamera.h"

#include "KameraDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKameraDoc

IMPLEMENT_DYNCREATE(CKameraDoc, CDocument)

BEGIN_MESSAGE_MAP(CKameraDoc, CDocument)
END_MESSAGE_MAP()


// CKameraDoc construction/destruction

CKameraDoc::CKameraDoc()
{
	// TODO: add one-time construction code here

}

CKameraDoc::~CKameraDoc()
{
}

BOOL CKameraDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CKameraDoc serialization

void CKameraDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CKameraDoc diagnostics

#ifdef _DEBUG
void CKameraDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKameraDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CKameraDoc commands

// KameraView.cpp : implementation of the CKameraView class
//

#include "stdafx.h"
#include "Kamera.h"

#include "KameraDoc.h"
#include "KameraView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKameraView

IMPLEMENT_DYNCREATE(CKameraView, CView)

BEGIN_MESSAGE_MAP(CKameraView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_KAMERA_POBIERZRAMKE, &CKameraView::OnKameraPobierzramke)
	ON_WM_TIMER()
	ON_COMMAND(ID_KAMERA_FILM, &CKameraView::OnKameraFilm)
	ON_COMMAND(ID_KAMERA_FILM32773, &CKameraView::OnKameraFilm32773)
END_MESSAGE_MAP()

// CKameraView construction/destruction

CKameraView::CKameraView()
{
	// TODO: add construction code here

}

CKameraView::~CKameraView()
{
}

BOOL CKameraView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CKameraView drawing

void CKameraView::OnDraw(CDC* pDC)
{
	
	CKameraDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int y = 20;
	for( int i =0; i<10; i++ ){
		pDC->TextOut( 700, y, m_strDriversEnum[i] ); y += 20;
		if( m_bIsDrivers[i] ){
			pDC->TextOut( 700, y, m_strDriversParam[i] );
			y += 20;
		};
	};

	// TODO: add draw code for native data here
}


// CKameraView printing

BOOL CKameraView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CKameraView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CKameraView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CKameraView diagnostics

#ifdef _DEBUG
void CKameraView::AssertValid() const
{
	CView::AssertValid();
}

void CKameraView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKameraDoc* CKameraView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKameraDoc)));
	return (CKameraDoc*)m_pDocument;
}
#endif //_DEBUG


// CKameraView message handlers

LRESULT CALLBACK cbFunct(HWND hWnd, LPVIDEOHDR lpVHdr){
	long size = lpVHdr->dwBufferLength;
	for( int x=0; x<320; x++ )
		for( int y = 0; y<240; y++ ){
			int i0 = x*3 + y * 3 * 320;
			//lpVHdr->lpData[i0] = 255 - lpVHdr->lpData[i0]; // BLUE
			//lpVHdr->lpData[i0+1] = 255 - lpVHdr->lpData[i0+1]; // GREEN
			//lpVHdr->lpData[i0+2] = 255 - lpVHdr->lpData[i0+2]; // RED
			lpVHdr->lpData[i0] = lpVHdr->lpData[i0] / 0.0721; // BLUE
			lpVHdr->lpData[i0+1] = lpVHdr->lpData[i0+1] / 0.7154; // GREEN
			lpVHdr->lpData[i0+2] = lpVHdr->lpData[i0+2] / 0.2125; // RED
	};
	return (LRESULT) TRUE ;
}

void CKameraView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	HWND hwndParent = this->GetSafeHwnd();
	m_wndKamera = capCreateCaptureWindow( L"Nazwa",
							WS_CHILD | WS_VISIBLE,
							10, 10, 320, 240,
							hwndParent, ID_CAMWND );

	for( int i =0; i<10; i++ ){
		
		bool res = capDriverConnect( m_wndKamera, i );
		
		m_bIsDrivers[i] = res;
		m_strDriversParam[i] = L" ";
		if( res ){
			char mstring[80];
			capDriverGetName( m_wndKamera, mstring, 80 );
			CAPDRIVERCAPS drvCaps;
			capDriverGetCaps( m_wndKamera, &drvCaps, sizeof( drvCaps ) );
			m_strDriversEnum[i].Format( L"%d. %s", i, mstring );
			if( drvCaps.fHasDlgVideoSource ){
				m_strDriversParam[i] += L"SourceDLG; ";
			};
			if( drvCaps.fHasDlgVideoFormat ){
				m_strDriversParam[i] += L"FormatDLG; ";
			};
			if( drvCaps.fCaptureInitialized ){
				m_strDriversParam[i] += L"INIT; ";
			};
		}else{
			m_strDriversEnum[i].Format( L"%d. ----------", i );
		};
		capDriverDisconnect( m_wndKamera );
	};
	bool res = capDriverConnect( m_wndKamera, 0 );
	capDlgVideoFormat( m_wndKamera );

	capSetCallbackOnFrame( m_wndKamera, cbFunct );
}

void CKameraView::OnKameraPobierzramke()
{
	capGrabFrame( m_wndKamera, true );
}



void CKameraView::OnTimer(UINT_PTR nIDEvent)
{
	capGrabFrame( m_wndKamera, true );
	CView::OnTimer(nIDEvent);
}

void CKameraView::OnKameraFilm()
{
	SetTimer( 101, 50, NULL );
}

void CKameraView::OnKameraFilm32773()
{
	KillTimer( 101 );
}

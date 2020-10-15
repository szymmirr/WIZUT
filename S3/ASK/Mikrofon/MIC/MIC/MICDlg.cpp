// MICDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MIC.h"
#include "MICDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <math.h>

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMICDlg dialog




CMICDlg::CMICDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMICDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMICDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMICDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTMIC_OUTOPEN, &CMICDlg::OnBnClickedButmicOutopen)
	ON_BN_CLICKED(IDC_BUTMIC_OUTCLOSE, &CMICDlg::OnBnClickedButmicOutclose)
	ON_BN_CLICKED(IDC_BUTMIC_OUTPLAY, &CMICDlg::OnBnClickedButmicOutplay)
	ON_MESSAGE(WOM_DONE, &CMICDlg::OnOutDone )
END_MESSAGE_MAP()

LRESULT CMICDlg::OnOutDone(WPARAM wParam, LPARAM lParam)
{
	MessageBox( L"Bufor zagrany do konca, mozna wstawic nowy" );
	return 0;
};

// CMICDlg message handlers

BOOL CMICDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMICDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMICDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMICDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMICDlg::OnBnClickedButmicOutopen(){ 
unsigned long result; 
   WAVEFORMATEX   waveFormat;   
// --- Inicjalizacja wyjscia dla Audio ------------------ 
   waveFormat.wFormatTag = WAVE_FORMAT_PCM; 
   waveFormat.nChannels = 1; 
   waveFormat.nSamplesPerSec = 44100; 
   waveFormat.wBitsPerSample = 8; 
   waveFormat.nBlockAlign = waveFormat.nChannels * (waveFormat.wBitsPerSample/8); 
   waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign; 
   waveFormat.cbSize = 0; 
// --- Otworzenie urzadzenia audio wyjscie -------------- 
   result = waveOutOpen(&outHandle,WAVE_MAPPER,&waveFormat,(DWORD)(this->m_hWnd),0,CALLBACK_WINDOW); 
if ( result ){ 
       MessageBox( L"Blad otwierania wyjsciowego urzadzenia audio!!!" ); 
   }   
}

void CMICDlg::OnBnClickedButmicOutclose()
{
	waveOutClose( outHandle );
}

void CMICDlg::OnBnClickedButmicOutplay()
{
	const double pi = 3.1415926535;

	double wsp1Hz = 2.0 / 44100.0;
	double wsp = 50 * wsp1Hz;

	double wspI = 170.0 / (88000.0*2);

	/*for( int i=0; i<(88000*2); i++)
	{
		outBufAudio[i] = (unsigned char)( 170.0* (1.0 + sin( i*pi*wsp ) / 2.0) );
		wsp += wsp1Hz / 175.0;
	};*/

	//outBufAudio[0] = (unsigned char)( 170.0* (1.0 + sin( 50*pi*wsp ) / 2.0) );
	//outBufAudio[1] = (unsigned char)( 170.0* (1.0 + sin( 200*pi*wsp ) / 2.0) );
	//outBufAudio[2] = (unsigned char)( 170.0* (1.0 + sin( 500*pi*wsp ) / 2.0) );
	
	/*for( int i=0; i<(88000*2); i++)
	{
		outBufAudio[i] = (unsigned char)( 170.0* (1.0 + sin( i*pi*wsp ) / 2.0) );
		wsp += wsp1Hz / 175.0;
	};*/

	 /*for( int i=0; i<(8800); i++)
        {
                double wsp = 392.0 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
 
        for( int i=(8800); i<(8800*2); i++)
        {
                double wsp = 329.6 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
 
       
        for( int i=(19200); i<(8800*3); i++)
        {
                double wsp = 329.6 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
       
        for( int i=(8800.0*3); i<(8800*4); i++)
        {
                double wsp = 349.2 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
 
        for( int i=(8800.0*4); i<(8800*5); i++)
        {
                double wsp = 293.7 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
 
        for( int i=(45000); i<(8800*6); i++)
        {
                double wsp = 293.7 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
 
        for( int i=(8800.0*6); i<(8800*7); i++)
        {
                double wsp = 261.6 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
 
        for( int i=(8800.0*7); i<(8800*8); i++)
        {
                double wsp =  329.6 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
 
        for( int i=(8800.0*8); i<(8800*9); i++)
        {
                double wsp = 392.0 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
 
        ///////////////////////////////////2 wers
        for( int i=(8800.0*9); i<(8800*10); i++)
        {
                double wsp = 392.0 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
 
        for( int i=(8800.0*10); i<(8800*11); i++)
        {
                double wsp = 329.6 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
       
        for( int i=(98200); i<(8800*12); i++)
        {
                double wsp = 329.6 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
       
        for( int i=(8800.0*12); i<(8800*13); i++)
        {
                double wsp = 349.2 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
       
        for( int i=(8800.0*13); i<(8800*14); i++)
        {
                double wsp = 293.7 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
        for( int i=(124200); i<(8800*15); i++)
        {
                double wsp = 293.7 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
 
        for( int i=(8800.0*14); i<(8800*15); i++)
        {
                double wsp = 261.6 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
       
        for( int i=(8800.0*15); i<(8800*16); i++)
        {
                double wsp = 329.6 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };
       
        for( int i=(8800.0*16); i<(8800*17); i++)
        {
                double wsp = 261.6 * wsp1Hz;
                outBufAudio[i] = (unsigned char)(170.0* (1.0 + sin(i*pi*wsp) / 2.0) );
            //wsp += wsp1Hz / 175.0;
        };*/
	
	int n = 28;
	
	const double C = 261.6*2,
                Cis = 277.2*2,
                D = 293.7*2,
                Dis = 311.1*2,
                E = 329.6*2,
                F = 349.2*2,
                Fis = 370.0*2,
                G = 392.0*2,
                Gis = 415.3*2,
                A = 440.0*2,
                Ais = 466.2*2,
                H = 493.9*2,
				P = 1.0;

	//double kotek[18] = {784.0, 659.3, 659.3, 698.5, 587.3, 587.3, 523.3, 659.3, 784.0, 784.0, 659.3, 659.3, 698.5, 587.3, 587.3, 523.3, 659.3, 523.3};
	double kotek[18] = {G, E, E, F, D, D, C, E, G, G, E, E, F, D, D, C, E, C};
	double happy[28] = {D, D, E, D, G, F, P, P, P, D, D, E, D, A, G, D, D, D, H, G, F, E, C, C, H, G, A, G};
	
	unsigned int maxI = 88000*2;
       
    unsigned int skok = maxI/n;

	for ( unsigned int i=0; i<maxI; i++) {
                unsigned int ni = i/skok;
                outBufAudio[i] = (unsigned char) ( 170.0 * ( 1.0 + sin(pi*happy[ni]*100*wsp) / 2.0) );
                wsp += wsp1Hz / 175.0;
        }

	outBuffer.lpData = (LPSTR)( this->outBufAudio );
	outBuffer.dwBufferLength = (88000*2);
	outBuffer.dwFlags = 0;

	int err;
	if( (err= waveOutPrepareHeader( outHandle, &outBuffer, sizeof(WAVEHDR))) )
	{
		MessageBox( L"BLAD przygotowywania struktury WAVEHDR" );
	}

	waveOutWrite( outHandle, &outBuffer, sizeof(WAVEHDR) );
}

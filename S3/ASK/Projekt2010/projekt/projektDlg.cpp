// projektDlg.cpp : implementation file
//

#include "stdafx.h"
#include "projekt.h"
#include "projektDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CprojektDlg dialog




CprojektDlg::CprojektDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CprojektDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CprojektDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CprojektDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CprojektDlg message handlers

BOOL CprojektDlg::OnInitDialog()
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

void CprojektDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CprojektDlg::OnPaint()
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
		CPaintDC dc(this);
		unsigned char a=3;
		unsigned char b=2;
		unsigned char y;
		//int y=a+b;
		_asm
		{
			/*MOV AH,a ;dodawanie
			MOV AL,b
			ADD AH,AL
			MOV y,AH
			
			MOV BL,0
			MOV AH,a
			MOV al,0x01
			AND ah,0x01
			JZ etyk
			MOV bl,1
			etyk:
			MOV y,BL
			
			MOV AH,a
			MOV bl,0
			powrot:
			mov al,ah
			and al,0xFF
			jz koniec
			and al,0x01
			jz etyk2
			inc bl
			etyk2:
			shr ah,1
			jmp powrot
			koniec:
			mov y,bl*/

			/*mov ah, a; spr czy 0x15
			add ah, 0xEB
			mov y,0
			jz e
			mov y,1
e:*/
			/*mov ah, a; mnozenie razy 12
			mov al, a
			shl ah, 4
			shl al, 2
			sub ah, al
			mov y, ah*/

			mov ah, a
			mov al, b
			shl ah, 4
			shl al, 2
			sub ah, al
			mov y, ah

		}
		CString str1;
		str1.Format(L"%d+%d=%d",a,b,y);
		dc.TextOutW(15,10,str1);
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CprojektDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


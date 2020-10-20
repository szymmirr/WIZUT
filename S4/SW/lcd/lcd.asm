;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
; This file was generated Fri Jun 09 17:53:49 2017
;--------------------------------------------------------
	.module lcd
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _M
	.globl _y
	.globl _i
	.globl _INIT
	.globl _LCDWC
	.globl _LCDWD
	.globl _LCDRC
	.globl _LCDRD
	.globl _STROBE
	.globl _PZNAK
	.globl _PISZKOM
	.globl _CZYZAJ
	.globl _Delay
	.globl _GoToXY
	.globl _LicznikLCD
	.globl _StringLCD
	.globl _NumLCD
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_P1	=	0x0090
_SCON	=	0x0098
_SBUF	=	0x0099
_P2	=	0x00a0
_IE	=	0x00a8
_P3	=	0x00b0
_IP	=	0x00b8
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_RI	=	0x0098
_TI	=	0x0099
_RB8	=	0x009a
_TB8	=	0x009b
_REN	=	0x009c
_SM2	=	0x009d
_SM1	=	0x009e
_SM0	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES	=	0x00ac
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_RXD	=	0x00b0
_TXD	=	0x00b1
_INT0	=	0x00b2
_INT1	=	0x00b3
_T0	=	0x00b4
_T1	=	0x00b5
_WR	=	0x00b6
_RD	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS	=	0x00bc
_P	=	0x00d0
_F1	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_i::
	.ds 2
_y::
	.ds 2
_M::
	.ds 1
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area OSEG    (OVR,DATA)
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG	(DATA)
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	lcall	_main
;	return from main will lock up
	sjmp .
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'INIT'
;------------------------------------------------------------
;------------------------------------------------------------
;	Z:\AESOKZ~C\lcd.c:28: void INIT(void)
;	-----------------------------------------
;	 function INIT
;	-----------------------------------------
_INIT:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
;	Z:\AESOKZ~C\lcd.c:30: LCDWC();
	lcall	_LCDWC
;	Z:\AESOKZ~C\lcd.c:31: Delay(10000);
	mov	dptr,#0x2710
	lcall	_Delay
;	Z:\AESOKZ~C\lcd.c:32: LCDDataPort=0x38;
	mov	_P2,#0x38
;	Z:\AESOKZ~C\lcd.c:33: i=1;
	mov	_i,#0x01
	mov	(_i + 1),#0x00
;	Z:\AESOKZ~C\lcd.c:36: Delay(10000);
	mov	dptr,#0x2710
	lcall	_Delay
;	Z:\AESOKZ~C\lcd.c:37: LCDWC();
	lcall	_LCDWC
;	Z:\AESOKZ~C\lcd.c:38: STROBE();
	lcall	_STROBE
;	Z:\AESOKZ~C\lcd.c:39: i++;
	inc	_i
	clr	a
	cjne	a,_i,00107$
	inc	(_i + 1)
00107$:
;	Z:\AESOKZ~C\lcd.c:47: LCDWC();
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'LCDWC'
;------------------------------------------------------------
;------------------------------------------------------------
;	Z:\AESOKZ~C\lcd.c:51: void LCDWC(void)
;	-----------------------------------------
;	 function LCDWC
;	-----------------------------------------
_LCDWC:
;	Z:\AESOKZ~C\lcd.c:53: LCDRS=0;
	clr	_P0_0
;	Z:\AESOKZ~C\lcd.c:54: LCDRW=0;
	clr	_P0_1
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'LCDWD'
;------------------------------------------------------------
;------------------------------------------------------------
;	Z:\AESOKZ~C\lcd.c:57: void LCDWD(void)
;	-----------------------------------------
;	 function LCDWD
;	-----------------------------------------
_LCDWD:
;	Z:\AESOKZ~C\lcd.c:59: LCDRS=1;
	setb	_P0_0
;	Z:\AESOKZ~C\lcd.c:60: LCDRW=0;
	clr	_P0_1
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'LCDRC'
;------------------------------------------------------------
;------------------------------------------------------------
;	Z:\AESOKZ~C\lcd.c:63: void LCDRC(void)
;	-----------------------------------------
;	 function LCDRC
;	-----------------------------------------
_LCDRC:
;	Z:\AESOKZ~C\lcd.c:65: LCDDataPort = 0x0FF;
	mov	_P2,#0xFF
;	Z:\AESOKZ~C\lcd.c:66: LCDRS=0;
	clr	_P0_0
;	Z:\AESOKZ~C\lcd.c:67: LCDRW=1;
	setb	_P0_1
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'LCDRD'
;------------------------------------------------------------
;------------------------------------------------------------
;	Z:\AESOKZ~C\lcd.c:70: void LCDRD(void)
;	-----------------------------------------
;	 function LCDRD
;	-----------------------------------------
_LCDRD:
;	Z:\AESOKZ~C\lcd.c:72: LCDDataPort = 0x0FF;
	mov	_P2,#0xFF
;	Z:\AESOKZ~C\lcd.c:73: LCDRS=1;
	setb	_P0_0
;	Z:\AESOKZ~C\lcd.c:74: LCDRW=1;
	setb	_P0_1
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'STROBE'
;------------------------------------------------------------
;------------------------------------------------------------
;	Z:\AESOKZ~C\lcd.c:77: void STROBE(void)
;	-----------------------------------------
;	 function STROBE
;	-----------------------------------------
_STROBE:
;	Z:\AESOKZ~C\lcd.c:79: LCDE=1;
	setb	_P0_2
;	Z:\AESOKZ~C\lcd.c:80: Delay(5);
	mov	dptr,#0x0005
	lcall	_Delay
;	Z:\AESOKZ~C\lcd.c:81: LCDE=0;
	clr	_P0_2
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'PZNAK'
;------------------------------------------------------------
;M                         Allocated to registers 
;------------------------------------------------------------
;	Z:\AESOKZ~C\lcd.c:84: void PZNAK(char M)
;	-----------------------------------------
;	 function PZNAK
;	-----------------------------------------
_PZNAK:
	mov	_P2,dpl
;	Z:\AESOKZ~C\lcd.c:87: LCDWD();
	lcall	_LCDWD
;	Z:\AESOKZ~C\lcd.c:88: STROBE();
	lcall	_STROBE
;	Z:\AESOKZ~C\lcd.c:89: CZYZAJ();
	ljmp	_CZYZAJ
;------------------------------------------------------------
;Allocation info for local variables in function 'PISZKOM'
;------------------------------------------------------------
;M                         Allocated to registers r2 
;------------------------------------------------------------
;	Z:\AESOKZ~C\lcd.c:92: void PISZKOM(char M)
;	-----------------------------------------
;	 function PISZKOM
;	-----------------------------------------
_PISZKOM:
	mov	r2,dpl
;	Z:\AESOKZ~C\lcd.c:94: CZYZAJ();
	push	ar2
	lcall	_CZYZAJ
;	Z:\AESOKZ~C\lcd.c:95: LCDWC();
	lcall	_LCDWC
	pop	ar2
;	Z:\AESOKZ~C\lcd.c:96: LCDDataPort=M;
	mov	_P2,r2
;	Z:\AESOKZ~C\lcd.c:97: STROBE();
	ljmp	_STROBE
;------------------------------------------------------------
;Allocation info for local variables in function 'CZYZAJ'
;------------------------------------------------------------
;------------------------------------------------------------
;	Z:\AESOKZ~C\lcd.c:100: void CZYZAJ(void)
;	-----------------------------------------
;	 function CZYZAJ
;	-----------------------------------------
_CZYZAJ:
;	Z:\AESOKZ~C\lcd.c:102: LCDDataPort=LCDDataPort;
	mov	_P2,_P2
;	Z:\AESOKZ~C\lcd.c:103: LCDRW=1;
	setb	_P0_1
;	Z:\AESOKZ~C\lcd.c:104: LCDRS=0;
	clr	_P0_0
;	Z:\AESOKZ~C\lcd.c:105: if(LCDDataPort>127)
	mov	a,#0x7F
	cjne	a,_P2,00106$
00106$:
	jnc	00103$
;	Z:\AESOKZ~C\lcd.c:107: LCDE=1;
	setb	_P0_2
;	Z:\AESOKZ~C\lcd.c:108: LCDDataPort=LCDDataPort;
	mov	_P2,_P2
;	Z:\AESOKZ~C\lcd.c:109: LCDE=0;
	clr	_P0_2
00103$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Delay'
;------------------------------------------------------------
;X                         Allocated to registers 
;------------------------------------------------------------
;	Z:\AESOKZ~C\lcd.c:113: void Delay(int X)
;	-----------------------------------------
;	 function Delay
;	-----------------------------------------
_Delay:
	mov	r2,dpl
	mov	r3,dph
;	Z:\AESOKZ~C\lcd.c:115: y=1;
	mov	_y,#0x01
	mov	(_y + 1),#0x00
;	Z:\AESOKZ~C\lcd.c:116: if(y<X)
	clr	c
	mov	a,#0x01
	subb	a,r2
	clr	a
	subb	a,r3
	jnc	00103$
;	Z:\AESOKZ~C\lcd.c:118: y++;
	mov	_y,#0x02
	mov	(_y + 1),#0x00
00103$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'GoToXY'
;------------------------------------------------------------
;col                       Allocated to stack - offset -3
;row                       Allocated to registers r2 
;------------------------------------------------------------
;	Z:\AESOKZ~C\lcd.c:122: void GoToXY(char row, char col)
;	-----------------------------------------
;	 function GoToXY
;	-----------------------------------------
_GoToXY:
	push	_bp
	mov	_bp,sp
	mov	r2,dpl
;	Z:\AESOKZ~C\lcd.c:124: if(row>0)
	clr	c
	mov	a,#(0x00 ^ 0x80)
	mov	b,r2
	xrl	b,#0x80
	subb	a,b
	jnc	00102$
;	Z:\AESOKZ~C\lcd.c:126: PISZKOM(0x0c0+col);
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	a,#0xC0
	add	a,@r0
	mov	dpl,a
	lcall	_PISZKOM
	sjmp	00104$
00102$:
;	Z:\AESOKZ~C\lcd.c:130: PISZKOM(0x80+col);
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	a,#0x80
	add	a,@r0
	mov	dpl,a
	lcall	_PISZKOM
00104$:
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'LicznikLCD'
;------------------------------------------------------------
;y                         Allocated to stack - offset -3
;liczba                    Allocated to stack - offset -5
;x                         Allocated to registers r2 
;------------------------------------------------------------
;	Z:\AESOKZ~C\lcd.c:134: void LicznikLCD(char x, char y, unsigned int liczba)
;	-----------------------------------------
;	 function LicznikLCD
;	-----------------------------------------
_LicznikLCD:
	push	_bp
	mov	_bp,sp
	mov	r2,dpl
;	Z:\AESOKZ~C\lcd.c:136: i=1;
	mov	_i,#0x01
	mov	(_i + 1),#0x00
;	Z:\AESOKZ~C\lcd.c:137: if(i<liczba)
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	clr	c
	mov	a,#0x01
	subb	a,@r0
	clr	a
	inc	r0
	subb	a,@r0
	jnc	00103$
;	Z:\AESOKZ~C\lcd.c:139: GoToXY(x,y);
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	dpl,r2
	lcall	_GoToXY
	dec	sp
;	Z:\AESOKZ~C\lcd.c:140: NumLCD(i);
	mov	dpl,_i
	mov	dph,(_i + 1)
	lcall	_NumLCD
;	Z:\AESOKZ~C\lcd.c:141: Delay(5);
	mov	dptr,#0x0005
	lcall	_Delay
;	Z:\AESOKZ~C\lcd.c:142: i++;
	inc	_i
	clr	a
	cjne	a,_i,00107$
	inc	(_i + 1)
00107$:
00103$:
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'StringLCD'
;------------------------------------------------------------
;s                         Allocated to registers r2 r3 r4 
;i                         Allocated to registers 
;l                         Allocated to stack - offset 1
;------------------------------------------------------------
;	Z:\AESOKZ~C\lcd.c:146: void StringLCD(unsigned char *s)
;	-----------------------------------------
;	 function StringLCD
;	-----------------------------------------
_StringLCD:
	push	_bp
	mov	_bp,sp
	inc	sp
;	Z:\AESOKZ~C\lcd.c:149: i=strlen(s);
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	push	ar2
	push	ar3
	push	ar4
	lcall	_strlen
	pop	ar4
	pop	ar3
	pop	ar2
;	Z:\AESOKZ~C\lcd.c:151: if(i<l)
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	add	a,#0xff - 0x00
	jnc	00103$
;	Z:\AESOKZ~C\lcd.c:153: PZNAK((char)s);
	mov	dpl,r2
	lcall	_PZNAK
;	Z:\AESOKZ~C\lcd.c:154: Delay(100);
	mov	dptr,#0x0064
	lcall	_Delay
;	Z:\AESOKZ~C\lcd.c:156: i++;
00103$:
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'NumLCD'
;------------------------------------------------------------
;liczba                    Allocated to registers r2 r3 
;dtys                      Allocated to registers r4 
;tysiace                   Allocated to registers r5 
;setki                     Allocated to registers r6 
;dziesiatki                Allocated to stack - offset 1
;jednosci                  Allocated to registers r2 
;temp                      Allocated to registers r2 r3 
;------------------------------------------------------------
;	Z:\AESOKZ~C\lcd.c:160: void NumLCD(unsigned int liczba)
;	-----------------------------------------
;	 function NumLCD
;	-----------------------------------------
_NumLCD:
	push	_bp
	mov	_bp,sp
	inc	sp
	mov	r2,dpl
	mov	r3,dph
;	Z:\AESOKZ~C\lcd.c:164: dtys=liczba/10000;
	push	ar2
	push	ar3
	mov	a,#0x10
	push	acc
	mov	a,#0x27
	push	acc
	mov	dpl,r2
	mov	dph,r3
	lcall	__divuint
	mov	r4,dpl
	mov	r5,dph
	dec	sp
	dec	sp
	pop	ar3
	pop	ar2
;	Z:\AESOKZ~C\lcd.c:165: if(dtys==0)
	mov	a,r4
	jnz	00102$
;	Z:\AESOKZ~C\lcd.c:167: PZNAK(0x20);
	mov	dpl,#0x20
	push	ar2
	push	ar3
	push	ar4
	lcall	_PZNAK
	pop	ar4
	pop	ar3
	pop	ar2
	sjmp	00103$
00102$:
;	Z:\AESOKZ~C\lcd.c:171: PZNAK(dtys+0x30);
	mov	a,#0x30
	add	a,r4
	mov	dpl,a
	push	ar2
	push	ar3
	push	ar4
	lcall	_PZNAK
	pop	ar4
	pop	ar3
	pop	ar2
00103$:
;	Z:\AESOKZ~C\lcd.c:173: temp=liczba%100000;
	mov	r5,#0x00
	mov	r6,#0x00
	push	ar4
	mov	a,#0xA0
	push	acc
	mov	a,#0x86
	push	acc
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	mov	dpl,r2
	mov	dph,r3
	mov	b,r5
	mov	a,r6
	lcall	__modslong
	mov	r2,dpl
	mov	r3,dph
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
;	Z:\AESOKZ~C\lcd.c:174: tysiace=temp/1000;
	push	ar2
	push	ar3
	push	ar4
	mov	a,#0xE8
	push	acc
	mov	a,#0x03
	push	acc
	mov	dpl,r2
	mov	dph,r3
	lcall	__divuint
	mov	r5,dpl
	mov	r6,dph
	dec	sp
	dec	sp
	pop	ar4
	pop	ar3
	pop	ar2
;	Z:\AESOKZ~C\lcd.c:175: if(tysiace==0&&dtys==0)
	mov	a,r5
	jnz	00105$
	mov	a,r4
	jnz	00105$
;	Z:\AESOKZ~C\lcd.c:177: PZNAK(0x20);
	mov	dpl,#0x20
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	lcall	_PZNAK
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
	sjmp	00106$
00105$:
;	Z:\AESOKZ~C\lcd.c:181: PZNAK(tysiace+0x30);
	mov	a,#0x30
	add	a,r5
	mov	dpl,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	lcall	_PZNAK
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
00106$:
;	Z:\AESOKZ~C\lcd.c:183: temp=temp%1000;
	push	ar4
	push	ar5
	mov	a,#0xE8
	push	acc
	mov	a,#0x03
	push	acc
	mov	dpl,r2
	mov	dph,r3
	lcall	__moduint
	mov	r6,dpl
	mov	r7,dph
	dec	sp
	dec	sp
	pop	ar5
	pop	ar4
	mov	ar2,r6
	mov	ar3,r7
;	Z:\AESOKZ~C\lcd.c:184: setki=temp/100;
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	mov	a,#0x64
	push	acc
	clr	a
	push	acc
	mov	dpl,r2
	mov	dph,r3
	lcall	__divuint
	mov	r6,dpl
	mov	r7,dph
	dec	sp
	dec	sp
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	Z:\AESOKZ~C\lcd.c:185: if(setki==0&&tysiace==0&&dtys==0)
	mov	a,r6
	jnz	00109$
	mov	a,r5
	jnz	00109$
	mov	a,r4
	jnz	00109$
;	Z:\AESOKZ~C\lcd.c:187: PZNAK(0x20);
	mov	dpl,#0x20
	push	ar2
	push	ar3
	lcall	_PZNAK
	pop	ar3
	pop	ar2
	sjmp	00110$
00109$:
;	Z:\AESOKZ~C\lcd.c:191: PZNAK(dziesiatki+0x30);
	mov	r0,_bp
	inc	r0
	mov	a,#0x30
	add	a,@r0
	mov	dpl,a
	push	ar2
	push	ar3
	lcall	_PZNAK
	pop	ar3
	pop	ar2
00110$:
;	Z:\AESOKZ~C\lcd.c:193: temp=temp%10;
	mov	a,#0x0A
	push	acc
	clr	a
	push	acc
	mov	dpl,r2
	mov	dph,r3
	lcall	__moduint
	mov	r4,dpl
	mov	r5,dph
	dec	sp
	dec	sp
	mov	ar2,r4
	mov	ar3,r5
;	Z:\AESOKZ~C\lcd.c:194: jednosci=temp;
;	Z:\AESOKZ~C\lcd.c:195: PZNAK(jednosci+0x30);
	mov	a,#0x30
	add	a,r2
	mov	dpl,a
	lcall	_PZNAK
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;------------------------------------------------------------
;	Z:\AESOKZ~C\lcd.c:199: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	Z:\AESOKZ~C\lcd.c:201: INITLCD();
	lcall	_INITLCD
;	Z:\AESOKZ~C\lcd.c:202: GoToXY(0,1);
	mov	a,#0x01
	push	acc
	mov	dpl,#0x00
	lcall	_GoToXY
	dec	sp
;	Z:\AESOKZ~C\lcd.c:203: PZNAK(0x4D);
	mov	dpl,#0x4D
	lcall	_PZNAK
;	Z:\AESOKZ~C\lcd.c:204: GoToXY(1,1);
	mov	a,#0x01
	push	acc
	mov	dpl,#0x01
	lcall	_GoToXY
	dec	sp
;	Z:\AESOKZ~C\lcd.c:205: StringLCD('Napis');
	mov	dptr,#0x004E
	mov	b,#0x00
	lcall	_StringLCD
;	Z:\AESOKZ~C\lcd.c:206: LicznikLCD(1,8,65535);
	mov	a,#0xFF
	push	acc
	push	acc
	mov	a,#0x08
	push	acc
	mov	dpl,#0x01
	lcall	_LicznikLCD
	dec	sp
	dec	sp
	dec	sp
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)

;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
; This file was generated Wed Jun 07 11:31:21 2017
;--------------------------------------------------------
	.module silnik2
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _button1
	.globl _button0
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
	.globl _lobrotow
	.globl _liczba
	.globl _a
	.globl _i
	.globl _TablSiln
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
; overlayable bit register bank
;--------------------------------------------------------
	.area BIT_BANK	(REL,OVR,DATA)
bits:
	.ds 1
	b0 = bits[0]
	b1 = bits[1]
	b2 = bits[2]
	b3 = bits[3]
	b4 = bits[4]
	b5 = bits[5]
	b6 = bits[6]
	b7 = bits[7]
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_TablSiln::
	.ds 4
_i::
	.ds 1
_a::
	.ds 2
_liczba::
	.ds 2
_lobrotow::
	.ds 2
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
	ljmp	_button0
	.ds	5
	reti
	.ds	7
	ljmp	_button1
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
;	Z:\AESOKZ~C\silnik2.c:8: unsigned char TablSiln[]={3,6,12,9};//lewo
	mov	_TablSiln,#0x03
	mov	(_TablSiln + 0x0001),#0x06
	mov	(_TablSiln + 0x0002),#0x0C
	mov	(_TablSiln + 0x0003),#0x09
;	Z:\AESOKZ~C\silnik2.c:11: unsigned int a =0;
	clr	a
	mov	_a,a
	mov	(_a + 1),a
;	Z:\AESOKZ~C\silnik2.c:12: int liczba =515;
	mov	_liczba,#0x03
	mov	(_liczba + 1),#0x02
;	Z:\AESOKZ~C\silnik2.c:13: int lobrotow =0;
	clr	a
	mov	_lobrotow,a
	mov	(_lobrotow + 1),a
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
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;------------------------------------------------------------
;	Z:\AESOKZ~C\silnik2.c:14: int main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
;	Z:\AESOKZ~C\silnik2.c:16: EA =1;
	setb	_EA
;	Z:\AESOKZ~C\silnik2.c:17: EX0 =1;
	setb	_EX0
;	Z:\AESOKZ~C\silnik2.c:18: EX1 =1;
	setb	_EX1
;	Z:\AESOKZ~C\silnik2.c:19: IT1 =1;
	setb	_IT1
;	Z:\AESOKZ~C\silnik2.c:20: while(1);
00102$:
	sjmp	00102$
;------------------------------------------------------------
;Allocation info for local variables in function 'button0'
;------------------------------------------------------------
;------------------------------------------------------------
;	Z:\AESOKZ~C\silnik2.c:22: void button0(void)__interrupt(0)
;	-----------------------------------------
;	 function button0
;	-----------------------------------------
_button0:
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+2)
	push	(0+3)
	push	(0+4)
	push	(0+5)
	push	(0+6)
	push	(0+7)
	push	(0+0)
	push	(0+1)
	push	psw
	mov	psw,#0x00
;	Z:\AESOKZ~C\silnik2.c:24: for(a =0;a <10000;++a);
	mov	_a,#0x10
	mov	(_a + 1),#0x27
00103$:
	dec	_a
	mov	a,#0xff
	cjne	a,_a,00113$
	dec	(_a + 1)
00113$:
	mov	a,_a
	orl	a,(_a + 1)
	jnz	00103$
;	Z:\AESOKZ~C\silnik2.c:25: ++lobrotow;
	inc	_lobrotow
	clr	a
	cjne	a,_lobrotow,00115$
	inc	(_lobrotow + 1)
00115$:
;	Z:\AESOKZ~C\silnik2.c:26: for(a =0;a <10000;++a);
	mov	_a,#0x10
	mov	(_a + 1),#0x27
00106$:
	dec	_a
	mov	a,#0xff
	cjne	a,_a,00116$
	dec	(_a + 1)
00116$:
	mov	a,_a
	orl	a,(_a + 1)
	jnz	00106$
	mov	_a,#0x10
	mov	(_a + 1),#0x27
;	Z:\AESOKZ~C\silnik2.c:27: liczba =lobrotow *krok;
	push	_lobrotow
	push	(_lobrotow + 1)
	mov	dptr,#0x0203
	lcall	__mulint
	mov	_liczba,dpl
	mov	(_liczba + 1),dph
	dec	sp
	dec	sp
	pop	psw
	pop	(0+1)
	pop	(0+0)
	pop	(0+7)
	pop	(0+6)
	pop	(0+5)
	pop	(0+4)
	pop	(0+3)
	pop	(0+2)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	reti
;------------------------------------------------------------
;Allocation info for local variables in function 'button1'
;------------------------------------------------------------
;------------------------------------------------------------
;	Z:\AESOKZ~C\silnik2.c:29: void button1(void)__interrupt(2)
;	-----------------------------------------
;	 function button1
;	-----------------------------------------
_button1:
	push	acc
	push	ar0
	push	psw
	mov	psw,#0x00
;	Z:\AESOKZ~C\silnik2.c:31: while(liczba)
00101$:
	mov	a,_liczba
	orl	a,(_liczba + 1)
	jz	00111$
;	Z:\AESOKZ~C\silnik2.c:33: for(i =0;i <4;++i)
	mov	_i,#0x00
00107$:
	clr	c
	mov	a,_i
	xrl	a,#0x80
	subb	a,#0x84
	jnc	00110$
;	Z:\AESOKZ~C\silnik2.c:35: for(a =0;a <500;++a);
	mov	_a,#0xF4
	mov	(_a + 1),#0x01
00106$:
	dec	_a
	mov	a,#0xff
	cjne	a,_a,00121$
	dec	(_a + 1)
00121$:
	mov	a,_a
	orl	a,(_a + 1)
	jnz	00106$
	mov	_a,#0xF4
	mov	(_a + 1),#0x01
;	Z:\AESOKZ~C\silnik2.c:36: P0 =TablSiln[i];
	mov	a,_i
	add	a,#_TablSiln
	mov	r0,a
	mov	_P0,@r0
;	Z:\AESOKZ~C\silnik2.c:33: for(i =0;i <4;++i)
	inc	_i
	sjmp	00107$
00110$:
;	Z:\AESOKZ~C\silnik2.c:38: liczba--;
	dec	_liczba
	mov	a,#0xff
	cjne	a,_liczba,00123$
	dec	(_liczba + 1)
00123$:
	sjmp	00101$
00111$:
	pop	psw
	pop	ar0
	pop	acc
	reti
;	eliminated unneeded push/pop ar1
;	eliminated unneeded push/pop dpl
;	eliminated unneeded push/pop dph
;	eliminated unneeded push/pop b
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)

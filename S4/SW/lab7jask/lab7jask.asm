;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
; This file was generated Fri Apr 28 17:14:41 2017
;--------------------------------------------------------
	.module lab7jask
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _IntTIM0
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
	.globl _i
	.globl _KoniecImp
	.globl _zliczanie_1sek
	.globl _licznik
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
	.area REG_BANK_2	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_licznik::
	.ds 1
_zliczanie_1sek::
	.ds 1
_KoniecImp::
	.ds 1
_i::
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
	reti
	.ds	7
	ljmp	_IntTIM0
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
;	Z:\AESOKZ~C\lab7jask.c:9: unsigned char licznik=1;
	mov	_licznik,#0x01
;	Z:\AESOKZ~C\lab7jask.c:11: unsigned char KoniecImp = 5;
	mov	_KoniecImp,#0x05
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
;	Z:\AESOKZ~C\lab7jask.c:14: int main(void){
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
;	Z:\AESOKZ~C\lab7jask.c:15: TMOD = 0x11;
	mov	_TMOD,#0x11
;	Z:\AESOKZ~C\lab7jask.c:16: led=0;
	mov	_P2,#0x00
;	Z:\AESOKZ~C\lab7jask.c:18: TL0=Czas%256;
	mov	_TL0,#0x00
;	Z:\AESOKZ~C\lab7jask.c:19: TH0=Czas/256;
	mov	_TH0,#0x4C
;	Z:\AESOKZ~C\lab7jask.c:20: TR0=1;
	setb	_TR0
;	Z:\AESOKZ~C\lab7jask.c:21: zliczanie_1sek=0;
	mov	_zliczanie_1sek,#0x00
;	Z:\AESOKZ~C\lab7jask.c:23: IE = 0b10000010;
	mov	_IE,#0x82
;	Z:\AESOKZ~C\lab7jask.c:25: ET0 = 1;
	setb	_ET0
;	Z:\AESOKZ~C\lab7jask.c:26: EA = 1;
	setb	_EA
;	Z:\AESOKZ~C\lab7jask.c:29: while(but1 && but2);
00102$:
	jnb	_P3_0,00104$
	jb	_P3_1,00102$
00104$:
;	Z:\AESOKZ~C\lab7jask.c:30: for(i=0;i<500;i++); //zwloka na drgania
	mov	_i,#0xF4
	mov	(_i + 1),#0x01
00121$:
	dec	_i
	mov	a,#0xff
	cjne	a,_i,00141$
	dec	(_i + 1)
00141$:
	mov	a,_i
	orl	a,(_i + 1)
	jnz	00121$
	mov	_i,#0xF4
	mov	(_i + 1),#0x01
;	Z:\AESOKZ~C\lab7jask.c:31: if(but1){
	jnb	_P3_0,00110$
;	Z:\AESOKZ~C\lab7jask.c:32: if(KoniecImp < up)KoniecImp++;
	mov	a,#0x100 - 0x0A
	add	a,_KoniecImp
	jc	00113$
	inc	_KoniecImp
	sjmp	00113$
00110$:
;	Z:\AESOKZ~C\lab7jask.c:35: if(KoniecImp > down)KoniecImp--;
	mov	a,#0x01
	cjne	a,_KoniecImp,00145$
00145$:
	jnc	00113$
	dec	_KoniecImp
;	Z:\AESOKZ~C\lab7jask.c:38: while(!but1 || !but2);
00113$:
	jnb	_P3_0,00113$
	jnb	_P3_1,00113$
;	Z:\AESOKZ~C\lab7jask.c:40: for(i=0;i<500;i++);
	mov	_i,#0xF4
	mov	(_i + 1),#0x01
00124$:
	dec	_i
	mov	a,#0xff
	cjne	a,_i,00149$
	dec	(_i + 1)
00149$:
	mov	a,_i
	orl	a,(_i + 1)
	jnz	00124$
	mov	_i,#0xF4
	mov	(_i + 1),#0x01
	sjmp	00102$
;------------------------------------------------------------
;Allocation info for local variables in function 'IntTIM0'
;------------------------------------------------------------
;------------------------------------------------------------
;	Z:\AESOKZ~C\lab7jask.c:43: void IntTIM0() __interrupt(1) __using(2){
;	-----------------------------------------
;	 function IntTIM0
;	-----------------------------------------
_IntTIM0:
	ar2 = 0x12
	ar3 = 0x13
	ar4 = 0x14
	ar5 = 0x15
	ar6 = 0x16
	ar7 = 0x17
	ar0 = 0x10
	ar1 = 0x11
	push	acc
	push	psw
	mov	psw,#0x10
;	Z:\AESOKZ~C\lab7jask.c:44: TL0 = Czas % 256;
	mov	_TL0,#0x00
;	Z:\AESOKZ~C\lab7jask.c:45: TH0 = Czas / 256;
	mov	_TH0,#0x4C
;	Z:\AESOKZ~C\lab7jask.c:47: zliczanie_1sek++;
	inc	_zliczanie_1sek
;	Z:\AESOKZ~C\lab7jask.c:49: if(zliczanie_1sek >= KoniecImp){
	mov	a,_zliczanie_1sek
	cjne	a,_KoniecImp,00110$
00110$:
	jc	00106$
;	Z:\AESOKZ~C\lab7jask.c:50: if(P2 == 1){
	mov	a,#0x01
	cjne	a,_P2,00102$
;	Z:\AESOKZ~C\lab7jask.c:51: P2 = 0;
	mov	_P2,#0x00
	sjmp	00103$
00102$:
;	Z:\AESOKZ~C\lab7jask.c:54: P2 = 1;
	mov	_P2,#0x01
00103$:
;	Z:\AESOKZ~C\lab7jask.c:56: zliczanie_1sek = 0;
	mov	_zliczanie_1sek,#0x00
00106$:
	pop	psw
	pop	acc
	reti
;	eliminated unneeded push/pop dpl
;	eliminated unneeded push/pop dph
;	eliminated unneeded push/pop b
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)

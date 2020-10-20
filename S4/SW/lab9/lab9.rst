                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
                              4 ; This file was generated Fri May 12 17:46:49 2017
                              5 ;--------------------------------------------------------
                              6 	.module lab9
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _TablicaZnakow
                             13 	.globl _TablicaAnod
                             14 	.globl _timer0
                             15 	.globl _main
                             16 	.globl _CY
                             17 	.globl _AC
                             18 	.globl _F0
                             19 	.globl _RS1
                             20 	.globl _RS0
                             21 	.globl _OV
                             22 	.globl _F1
                             23 	.globl _P
                             24 	.globl _PS
                             25 	.globl _PT1
                             26 	.globl _PX1
                             27 	.globl _PT0
                             28 	.globl _PX0
                             29 	.globl _RD
                             30 	.globl _WR
                             31 	.globl _T1
                             32 	.globl _T0
                             33 	.globl _INT1
                             34 	.globl _INT0
                             35 	.globl _TXD
                             36 	.globl _RXD
                             37 	.globl _P3_7
                             38 	.globl _P3_6
                             39 	.globl _P3_5
                             40 	.globl _P3_4
                             41 	.globl _P3_3
                             42 	.globl _P3_2
                             43 	.globl _P3_1
                             44 	.globl _P3_0
                             45 	.globl _EA
                             46 	.globl _ES
                             47 	.globl _ET1
                             48 	.globl _EX1
                             49 	.globl _ET0
                             50 	.globl _EX0
                             51 	.globl _P2_7
                             52 	.globl _P2_6
                             53 	.globl _P2_5
                             54 	.globl _P2_4
                             55 	.globl _P2_3
                             56 	.globl _P2_2
                             57 	.globl _P2_1
                             58 	.globl _P2_0
                             59 	.globl _SM0
                             60 	.globl _SM1
                             61 	.globl _SM2
                             62 	.globl _REN
                             63 	.globl _TB8
                             64 	.globl _RB8
                             65 	.globl _TI
                             66 	.globl _RI
                             67 	.globl _P1_7
                             68 	.globl _P1_6
                             69 	.globl _P1_5
                             70 	.globl _P1_4
                             71 	.globl _P1_3
                             72 	.globl _P1_2
                             73 	.globl _P1_1
                             74 	.globl _P1_0
                             75 	.globl _TF1
                             76 	.globl _TR1
                             77 	.globl _TF0
                             78 	.globl _TR0
                             79 	.globl _IE1
                             80 	.globl _IT1
                             81 	.globl _IE0
                             82 	.globl _IT0
                             83 	.globl _P0_7
                             84 	.globl _P0_6
                             85 	.globl _P0_5
                             86 	.globl _P0_4
                             87 	.globl _P0_3
                             88 	.globl _P0_2
                             89 	.globl _P0_1
                             90 	.globl _P0_0
                             91 	.globl _B
                             92 	.globl _ACC
                             93 	.globl _PSW
                             94 	.globl _IP
                             95 	.globl _P3
                             96 	.globl _IE
                             97 	.globl _P2
                             98 	.globl _SBUF
                             99 	.globl _SCON
                            100 	.globl _P1
                            101 	.globl _TH1
                            102 	.globl _TH0
                            103 	.globl _TL1
                            104 	.globl _TL0
                            105 	.globl _TMOD
                            106 	.globl _TCON
                            107 	.globl _PCON
                            108 	.globl _DPH
                            109 	.globl _DPL
                            110 	.globl _SP
                            111 	.globl _P0
                            112 	.globl _i
                            113 	.globl _count
                            114 	.globl _Bufor
                            115 	.globl _Licznik
                            116 ;--------------------------------------------------------
                            117 ; special function registers
                            118 ;--------------------------------------------------------
                            119 	.area RSEG    (ABS,DATA)
   0000                     120 	.org 0x0000
                    0080    121 _P0	=	0x0080
                    0081    122 _SP	=	0x0081
                    0082    123 _DPL	=	0x0082
                    0083    124 _DPH	=	0x0083
                    0087    125 _PCON	=	0x0087
                    0088    126 _TCON	=	0x0088
                    0089    127 _TMOD	=	0x0089
                    008A    128 _TL0	=	0x008a
                    008B    129 _TL1	=	0x008b
                    008C    130 _TH0	=	0x008c
                    008D    131 _TH1	=	0x008d
                    0090    132 _P1	=	0x0090
                    0098    133 _SCON	=	0x0098
                    0099    134 _SBUF	=	0x0099
                    00A0    135 _P2	=	0x00a0
                    00A8    136 _IE	=	0x00a8
                    00B0    137 _P3	=	0x00b0
                    00B8    138 _IP	=	0x00b8
                    00D0    139 _PSW	=	0x00d0
                    00E0    140 _ACC	=	0x00e0
                    00F0    141 _B	=	0x00f0
                            142 ;--------------------------------------------------------
                            143 ; special function bits
                            144 ;--------------------------------------------------------
                            145 	.area RSEG    (ABS,DATA)
   0000                     146 	.org 0x0000
                    0080    147 _P0_0	=	0x0080
                    0081    148 _P0_1	=	0x0081
                    0082    149 _P0_2	=	0x0082
                    0083    150 _P0_3	=	0x0083
                    0084    151 _P0_4	=	0x0084
                    0085    152 _P0_5	=	0x0085
                    0086    153 _P0_6	=	0x0086
                    0087    154 _P0_7	=	0x0087
                    0088    155 _IT0	=	0x0088
                    0089    156 _IE0	=	0x0089
                    008A    157 _IT1	=	0x008a
                    008B    158 _IE1	=	0x008b
                    008C    159 _TR0	=	0x008c
                    008D    160 _TF0	=	0x008d
                    008E    161 _TR1	=	0x008e
                    008F    162 _TF1	=	0x008f
                    0090    163 _P1_0	=	0x0090
                    0091    164 _P1_1	=	0x0091
                    0092    165 _P1_2	=	0x0092
                    0093    166 _P1_3	=	0x0093
                    0094    167 _P1_4	=	0x0094
                    0095    168 _P1_5	=	0x0095
                    0096    169 _P1_6	=	0x0096
                    0097    170 _P1_7	=	0x0097
                    0098    171 _RI	=	0x0098
                    0099    172 _TI	=	0x0099
                    009A    173 _RB8	=	0x009a
                    009B    174 _TB8	=	0x009b
                    009C    175 _REN	=	0x009c
                    009D    176 _SM2	=	0x009d
                    009E    177 _SM1	=	0x009e
                    009F    178 _SM0	=	0x009f
                    00A0    179 _P2_0	=	0x00a0
                    00A1    180 _P2_1	=	0x00a1
                    00A2    181 _P2_2	=	0x00a2
                    00A3    182 _P2_3	=	0x00a3
                    00A4    183 _P2_4	=	0x00a4
                    00A5    184 _P2_5	=	0x00a5
                    00A6    185 _P2_6	=	0x00a6
                    00A7    186 _P2_7	=	0x00a7
                    00A8    187 _EX0	=	0x00a8
                    00A9    188 _ET0	=	0x00a9
                    00AA    189 _EX1	=	0x00aa
                    00AB    190 _ET1	=	0x00ab
                    00AC    191 _ES	=	0x00ac
                    00AF    192 _EA	=	0x00af
                    00B0    193 _P3_0	=	0x00b0
                    00B1    194 _P3_1	=	0x00b1
                    00B2    195 _P3_2	=	0x00b2
                    00B3    196 _P3_3	=	0x00b3
                    00B4    197 _P3_4	=	0x00b4
                    00B5    198 _P3_5	=	0x00b5
                    00B6    199 _P3_6	=	0x00b6
                    00B7    200 _P3_7	=	0x00b7
                    00B0    201 _RXD	=	0x00b0
                    00B1    202 _TXD	=	0x00b1
                    00B2    203 _INT0	=	0x00b2
                    00B3    204 _INT1	=	0x00b3
                    00B4    205 _T0	=	0x00b4
                    00B5    206 _T1	=	0x00b5
                    00B6    207 _WR	=	0x00b6
                    00B7    208 _RD	=	0x00b7
                    00B8    209 _PX0	=	0x00b8
                    00B9    210 _PT0	=	0x00b9
                    00BA    211 _PX1	=	0x00ba
                    00BB    212 _PT1	=	0x00bb
                    00BC    213 _PS	=	0x00bc
                    00D0    214 _P	=	0x00d0
                    00D1    215 _F1	=	0x00d1
                    00D2    216 _OV	=	0x00d2
                    00D3    217 _RS0	=	0x00d3
                    00D4    218 _RS1	=	0x00d4
                    00D5    219 _F0	=	0x00d5
                    00D6    220 _AC	=	0x00d6
                    00D7    221 _CY	=	0x00d7
                            222 ;--------------------------------------------------------
                            223 ; overlayable register banks
                            224 ;--------------------------------------------------------
                            225 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     226 	.ds 8
                            227 	.area REG_BANK_1	(REL,OVR,DATA)
   0008                     228 	.ds 8
                            229 ;--------------------------------------------------------
                            230 ; internal ram data
                            231 ;--------------------------------------------------------
                            232 	.area DSEG    (DATA)
   0010                     233 _Licznik::
   0010                     234 	.ds 1
   0011                     235 _Bufor::
   0011                     236 	.ds 4
   0015                     237 _count::
   0015                     238 	.ds 2
   0017                     239 _i::
   0017                     240 	.ds 2
                            241 ;--------------------------------------------------------
                            242 ; overlayable items in internal ram 
                            243 ;--------------------------------------------------------
                            244 	.area OSEG    (OVR,DATA)
                            245 ;--------------------------------------------------------
                            246 ; Stack segment in internal ram 
                            247 ;--------------------------------------------------------
                            248 	.area	SSEG	(DATA)
   0019                     249 __start__stack:
   0019                     250 	.ds	1
                            251 
                            252 ;--------------------------------------------------------
                            253 ; indirectly addressable internal ram data
                            254 ;--------------------------------------------------------
                            255 	.area ISEG    (DATA)
                            256 ;--------------------------------------------------------
                            257 ; absolute internal ram data
                            258 ;--------------------------------------------------------
                            259 	.area IABS    (ABS,DATA)
                            260 	.area IABS    (ABS,DATA)
                            261 ;--------------------------------------------------------
                            262 ; bit data
                            263 ;--------------------------------------------------------
                            264 	.area BSEG    (BIT)
                            265 ;--------------------------------------------------------
                            266 ; paged external ram data
                            267 ;--------------------------------------------------------
                            268 	.area PSEG    (PAG,XDATA)
                            269 ;--------------------------------------------------------
                            270 ; external ram data
                            271 ;--------------------------------------------------------
                            272 	.area XSEG    (XDATA)
                            273 ;--------------------------------------------------------
                            274 ; absolute external ram data
                            275 ;--------------------------------------------------------
                            276 	.area XABS    (ABS,XDATA)
                            277 ;--------------------------------------------------------
                            278 ; external initialized ram data
                            279 ;--------------------------------------------------------
                            280 	.area XISEG   (XDATA)
                            281 	.area HOME    (CODE)
                            282 	.area GSINIT0 (CODE)
                            283 	.area GSINIT1 (CODE)
                            284 	.area GSINIT2 (CODE)
                            285 	.area GSINIT3 (CODE)
                            286 	.area GSINIT4 (CODE)
                            287 	.area GSINIT5 (CODE)
                            288 	.area GSINIT  (CODE)
                            289 	.area GSFINAL (CODE)
                            290 	.area CSEG    (CODE)
                            291 ;--------------------------------------------------------
                            292 ; interrupt vector 
                            293 ;--------------------------------------------------------
                            294 	.area HOME    (CODE)
   0000                     295 __interrupt_vect:
   0000 02 00 13            296 	ljmp	__sdcc_gsinit_startup
   0003 32                  297 	reti
   0004                     298 	.ds	7
   000B 02 00 91            299 	ljmp	_timer0
                            300 ;--------------------------------------------------------
                            301 ; global & static initialisations
                            302 ;--------------------------------------------------------
                            303 	.area HOME    (CODE)
                            304 	.area GSINIT  (CODE)
                            305 	.area GSFINAL (CODE)
                            306 	.area GSINIT  (CODE)
                            307 	.globl __sdcc_gsinit_startup
                            308 	.globl __sdcc_program_startup
                            309 	.globl __start__stack
                            310 	.globl __mcs51_genXINIT
                            311 	.globl __mcs51_genXRAMCLEAR
                            312 	.globl __mcs51_genRAMCLEAR
                            313 ;	Z:\AESOKZ~C\lab9.c:21: unsigned char Licznik = 0;
   006C 75 10 00            314 	mov	_Licznik,#0x00
                            315 ;	Z:\AESOKZ~C\lab9.c:25: unsigned int count=50;	//co ktore przerwanie zmieniaj anode
   006F 75 15 32            316 	mov	_count,#0x32
   0072 75 16 00            317 	mov	(_count + 1),#0x00
                            318 ;	Z:\AESOKZ~C\lab9.c:44: int i=0;
   0075 E4                  319 	clr	a
   0076 F5 17               320 	mov	_i,a
   0078 F5 18               321 	mov	(_i + 1),a
                            322 	.area GSFINAL (CODE)
   007A 02 00 0E            323 	ljmp	__sdcc_program_startup
                            324 ;--------------------------------------------------------
                            325 ; Home
                            326 ;--------------------------------------------------------
                            327 	.area HOME    (CODE)
                            328 	.area HOME    (CODE)
   000E                     329 __sdcc_program_startup:
   000E 12 00 7D            330 	lcall	_main
                            331 ;	return from main will lock up
   0011 80 FE               332 	sjmp .
                            333 ;--------------------------------------------------------
                            334 ; code
                            335 ;--------------------------------------------------------
                            336 	.area CSEG    (CODE)
                            337 ;------------------------------------------------------------
                            338 ;Allocation info for local variables in function 'main'
                            339 ;------------------------------------------------------------
                            340 ;------------------------------------------------------------
                            341 ;	Z:\AESOKZ~C\lab9.c:27: int main(void)
                            342 ;	-----------------------------------------
                            343 ;	 function main
                            344 ;	-----------------------------------------
   007D                     345 _main:
                    0002    346 	ar2 = 0x02
                    0003    347 	ar3 = 0x03
                    0004    348 	ar4 = 0x04
                    0005    349 	ar5 = 0x05
                    0006    350 	ar6 = 0x06
                    0007    351 	ar7 = 0x07
                    0000    352 	ar0 = 0x00
                    0001    353 	ar1 = 0x01
                            354 ;	Z:\AESOKZ~C\lab9.c:29: TMOD = 1;
   007D 75 89 01            355 	mov	_TMOD,#0x01
                            356 ;	Z:\AESOKZ~C\lab9.c:30: TH0 = Czas/256;
   0080 75 8C FD            357 	mov	_TH0,#0xFD
                            358 ;	Z:\AESOKZ~C\lab9.c:31: TL0 = Czas%256;
   0083 75 8A 18            359 	mov	_TL0,#0x18
                            360 ;	Z:\AESOKZ~C\lab9.c:32: TR0 = 1;
   0086 D2 8C               361 	setb	_TR0
                            362 ;	Z:\AESOKZ~C\lab9.c:33: ET0 = 1;
   0088 D2 A9               363 	setb	_ET0
                            364 ;	Z:\AESOKZ~C\lab9.c:34: EA = 1;
   008A D2 AF               365 	setb	_EA
                            366 ;	Z:\AESOKZ~C\lab9.c:36: Bufor[0]=Blank;
   008C 75 11 0A            367 	mov	_Bufor,#0x0A
                            368 ;	Z:\AESOKZ~C\lab9.c:41: while(1);
   008F                     369 00102$:
   008F 80 FE               370 	sjmp	00102$
                            371 ;------------------------------------------------------------
                            372 ;Allocation info for local variables in function 'timer0'
                            373 ;------------------------------------------------------------
                            374 ;------------------------------------------------------------
                            375 ;	Z:\AESOKZ~C\lab9.c:45: void timer0(void) __interrupt(1) __using(1)
                            376 ;	-----------------------------------------
                            377 ;	 function timer0
                            378 ;	-----------------------------------------
   0091                     379 _timer0:
                    000A    380 	ar2 = 0x0a
                    000B    381 	ar3 = 0x0b
                    000C    382 	ar4 = 0x0c
                    000D    383 	ar5 = 0x0d
                    000E    384 	ar6 = 0x0e
                    000F    385 	ar7 = 0x0f
                    0008    386 	ar0 = 0x08
                    0009    387 	ar1 = 0x09
   0091 C0 E0               388 	push	acc
   0093 C0 F0               389 	push	b
   0095 C0 82               390 	push	dpl
   0097 C0 83               391 	push	dph
   0099 C0 D0               392 	push	psw
   009B 75 D0 08            393 	mov	psw,#0x08
                            394 ;	Z:\AESOKZ~C\lab9.c:47: TH0 = Czas/256;
   009E 75 8C FD            395 	mov	_TH0,#0xFD
                            396 ;	Z:\AESOKZ~C\lab9.c:48: TL0 = Czas%256;
   00A1 75 8A 18            397 	mov	_TL0,#0x18
                            398 ;	Z:\AESOKZ~C\lab9.c:50: if (++count>500)
   00A4 05 15               399 	inc	_count
   00A6 E4                  400 	clr	a
   00A7 B5 15 02            401 	cjne	a,_count,00109$
   00AA 05 16               402 	inc	(_count + 1)
   00AC                     403 00109$:
   00AC C3                  404 	clr	c
   00AD 74 F4               405 	mov	a,#0xF4
   00AF 95 15               406 	subb	a,_count
   00B1 74 01               407 	mov	a,#0x01
   00B3 95 16               408 	subb	a,(_count + 1)
   00B5 50 41               409 	jnc	00104$
                            410 ;	Z:\AESOKZ~C\lab9.c:52: PortAnod = TablicaAnod[3];
   00B7 90 01 0F            411 	mov	dptr,#(_TablicaAnod + 0x0003)
   00BA E4                  412 	clr	a
   00BB 93                  413 	movc	a,@a+dptr
   00BC FA                  414 	mov	r2,a
   00BD 8A 80               415 	mov	_P0,r2
                            416 ;	Z:\AESOKZ~C\lab9.c:54: i++;
   00BF 05 17               417 	inc	_i
   00C1 E4                  418 	clr	a
   00C2 B5 17 02            419 	cjne	a,_i,00111$
   00C5 05 18               420 	inc	(_i + 1)
   00C7                     421 00111$:
                            422 ;	Z:\AESOKZ~C\lab9.c:55: if(i>10) i=1;
   00C7 C3                  423 	clr	c
   00C8 74 0A               424 	mov	a,#0x0A
   00CA 95 17               425 	subb	a,_i
   00CC 74 80               426 	mov	a,#(0x00 ^ 0x80)
   00CE 85 18 F0            427 	mov	b,(_i + 1)
   00D1 63 F0 80            428 	xrl	b,#0x80
   00D4 95 F0               429 	subb	a,b
   00D6 50 06               430 	jnc	00102$
   00D8 75 17 01            431 	mov	_i,#0x01
   00DB 75 18 00            432 	mov	(_i + 1),#0x00
   00DE                     433 00102$:
                            434 ;	Z:\AESOKZ~C\lab9.c:56: PortAnod = TablicaAnod[3];
   00DE 8A 80               435 	mov	_P0,r2
                            436 ;	Z:\AESOKZ~C\lab9.c:57: PortSeg = TablicaZnakow[i];
   00E0 E5 17               437 	mov	a,_i
   00E2 24 10               438 	add	a,#_TablicaZnakow
   00E4 F5 82               439 	mov	dpl,a
   00E6 E5 18               440 	mov	a,(_i + 1)
   00E8 34 01               441 	addc	a,#(_TablicaZnakow >> 8)
   00EA F5 83               442 	mov	dph,a
   00EC E4                  443 	clr	a
   00ED 93                  444 	movc	a,@a+dptr
   00EE F5 A0               445 	mov	_P2,a
                            446 ;	Z:\AESOKZ~C\lab9.c:58: i++;
   00F0 05 17               447 	inc	_i
   00F2 E4                  448 	clr	a
   00F3 B5 17 02            449 	cjne	a,_i,00113$
   00F6 05 18               450 	inc	(_i + 1)
   00F8                     451 00113$:
   00F8                     452 00104$:
                            453 ;	Z:\AESOKZ~C\lab9.c:65: i=0;
   00F8 E4                  454 	clr	a
   00F9 F5 17               455 	mov	_i,a
   00FB F5 18               456 	mov	(_i + 1),a
   00FD D0 D0               457 	pop	psw
   00FF D0 83               458 	pop	dph
   0101 D0 82               459 	pop	dpl
   0103 D0 F0               460 	pop	b
   0105 D0 E0               461 	pop	acc
   0107 32                  462 	reti
                            463 	.area CSEG    (CODE)
                            464 	.area CONST   (CODE)
   010C                     465 _TablicaAnod:
   010C 0E                  466 	.db #0x0E	; 14
   010D 0D                  467 	.db #0x0D	; 13
   010E 0B                  468 	.db #0x0B	; 11
   010F 07                  469 	.db #0x07	; 7
   0110                     470 _TablicaZnakow:
   0110 03                  471 	.db #0x03	; 3
   0111 9F                  472 	.db #0x9F	; 159
   0112 25                  473 	.db #0x25	; 37
   0113 0D                  474 	.db #0x0D	; 13
   0114 99                  475 	.db #0x99	; 153
   0115 49                  476 	.db #0x49	; 73	I
   0116 41                  477 	.db #0x41	; 65	A
   0117 1F                  478 	.db #0x1F	; 31
   0118 01                  479 	.db #0x01	; 1
   0119 09                  480 	.db #0x09	; 9
   011A FF                  481 	.db #0xFF	; 255
                            482 	.area XINIT   (CODE)
                            483 	.area CABS    (ABS,CODE)

                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
                              4 ; This file was generated Fri Apr 28 17:47:52 2017
                              5 ;--------------------------------------------------------
                              6 	.module lab8dwa
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _IntINT1
                             13 	.globl _IntINT0
                             14 	.globl _IntTIM0
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
                            113 	.globl _KoniecImp
                            114 	.globl _Zliczanie_1sek
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
                            227 	.area REG_BANK_2	(REL,OVR,DATA)
   0010                     228 	.ds 8
                            229 ;--------------------------------------------------------
                            230 ; internal ram data
                            231 ;--------------------------------------------------------
                            232 	.area DSEG    (DATA)
   0008                     233 _Licznik::
   0008                     234 	.ds 1
   0009                     235 _Zliczanie_1sek::
   0009                     236 	.ds 1
   000A                     237 _KoniecImp::
   000A                     238 	.ds 1
   000B                     239 _i::
   000B                     240 	.ds 2
                            241 ;--------------------------------------------------------
                            242 ; overlayable items in internal ram 
                            243 ;--------------------------------------------------------
                            244 	.area OSEG    (OVR,DATA)
                            245 ;--------------------------------------------------------
                            246 ; Stack segment in internal ram 
                            247 ;--------------------------------------------------------
                            248 	.area	SSEG	(DATA)
   0018                     249 __start__stack:
   0018                     250 	.ds	1
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
   0000 02 00 1B            296 	ljmp	__sdcc_gsinit_startup
   0003 02 00 C1            297 	ljmp	_IntINT0
   0006                     298 	.ds	5
   000B 02 00 98            299 	ljmp	_IntTIM0
   000E                     300 	.ds	5
   0013 02 00 EF            301 	ljmp	_IntINT1
                            302 ;--------------------------------------------------------
                            303 ; global & static initialisations
                            304 ;--------------------------------------------------------
                            305 	.area HOME    (CODE)
                            306 	.area GSINIT  (CODE)
                            307 	.area GSFINAL (CODE)
                            308 	.area GSINIT  (CODE)
                            309 	.globl __sdcc_gsinit_startup
                            310 	.globl __sdcc_program_startup
                            311 	.globl __start__stack
                            312 	.globl __mcs51_genXINIT
                            313 	.globl __mcs51_genXRAMCLEAR
                            314 	.globl __mcs51_genRAMCLEAR
                            315 ;	Z:\AESOKZ~C\lab8dwa.c:6: unsigned char Licznik = 1;
   0074 75 08 01            316 	mov	_Licznik,#0x01
                            317 ;	Z:\AESOKZ~C\lab8dwa.c:8: unsigned char KoniecImp=5;
   0077 75 0A 05            318 	mov	_KoniecImp,#0x05
                            319 	.area GSFINAL (CODE)
   007A 02 00 16            320 	ljmp	__sdcc_program_startup
                            321 ;--------------------------------------------------------
                            322 ; Home
                            323 ;--------------------------------------------------------
                            324 	.area HOME    (CODE)
                            325 	.area HOME    (CODE)
   0016                     326 __sdcc_program_startup:
   0016 12 00 7D            327 	lcall	_main
                            328 ;	return from main will lock up
   0019 80 FE               329 	sjmp .
                            330 ;--------------------------------------------------------
                            331 ; code
                            332 ;--------------------------------------------------------
                            333 	.area CSEG    (CODE)
                            334 ;------------------------------------------------------------
                            335 ;Allocation info for local variables in function 'main'
                            336 ;------------------------------------------------------------
                            337 ;------------------------------------------------------------
                            338 ;	Z:\AESOKZ~C\lab8dwa.c:11: int main(void)
                            339 ;	-----------------------------------------
                            340 ;	 function main
                            341 ;	-----------------------------------------
   007D                     342 _main:
                    0002    343 	ar2 = 0x02
                    0003    344 	ar3 = 0x03
                    0004    345 	ar4 = 0x04
                    0005    346 	ar5 = 0x05
                    0006    347 	ar6 = 0x06
                    0007    348 	ar7 = 0x07
                    0000    349 	ar0 = 0x00
                    0001    350 	ar1 = 0x01
                            351 ;	Z:\AESOKZ~C\lab8dwa.c:13: TMOD=0x01;
   007D 75 89 01            352 	mov	_TMOD,#0x01
                            353 ;	Z:\AESOKZ~C\lab8dwa.c:14: PortLED=255;
   0080 75 A0 FF            354 	mov	_P2,#0xFF
                            355 ;	Z:\AESOKZ~C\lab8dwa.c:15: TL0 = Czas % 256;
   0083 75 8A 00            356 	mov	_TL0,#0x00
                            357 ;	Z:\AESOKZ~C\lab8dwa.c:16: TH0 = Czas / 256;
   0086 75 8C 4C            358 	mov	_TH0,#0x4C
                            359 ;	Z:\AESOKZ~C\lab8dwa.c:17: TR0 = 1;
   0089 D2 8C               360 	setb	_TR0
                            361 ;	Z:\AESOKZ~C\lab8dwa.c:18: Zliczanie_1sek=0;
   008B 75 09 00            362 	mov	_Zliczanie_1sek,#0x00
                            363 ;	Z:\AESOKZ~C\lab8dwa.c:19: ET0 = 1;
   008E D2 A9               364 	setb	_ET0
                            365 ;	Z:\AESOKZ~C\lab8dwa.c:20: EA = 1;
   0090 D2 AF               366 	setb	_EA
                            367 ;	Z:\AESOKZ~C\lab8dwa.c:21: EX0 = 1;
   0092 D2 A8               368 	setb	_EX0
                            369 ;	Z:\AESOKZ~C\lab8dwa.c:22: EX1 = 1;
   0094 D2 AA               370 	setb	_EX1
                            371 ;	Z:\AESOKZ~C\lab8dwa.c:25: while(1)
   0096                     372 00102$:
   0096 80 FE               373 	sjmp	00102$
                            374 ;------------------------------------------------------------
                            375 ;Allocation info for local variables in function 'IntTIM0'
                            376 ;------------------------------------------------------------
                            377 ;------------------------------------------------------------
                            378 ;	Z:\AESOKZ~C\lab8dwa.c:31: void IntTIM0(void) __interrupt(1) __using(2)
                            379 ;	-----------------------------------------
                            380 ;	 function IntTIM0
                            381 ;	-----------------------------------------
   0098                     382 _IntTIM0:
                    0012    383 	ar2 = 0x12
                    0013    384 	ar3 = 0x13
                    0014    385 	ar4 = 0x14
                    0015    386 	ar5 = 0x15
                    0016    387 	ar6 = 0x16
                    0017    388 	ar7 = 0x17
                    0010    389 	ar0 = 0x10
                    0011    390 	ar1 = 0x11
   0098 C0 E0               391 	push	acc
   009A C0 D0               392 	push	psw
   009C 75 D0 10            393 	mov	psw,#0x10
                            394 ;	Z:\AESOKZ~C\lab8dwa.c:33: TL0 = Czas % 256;
   009F 75 8A 00            395 	mov	_TL0,#0x00
                            396 ;	Z:\AESOKZ~C\lab8dwa.c:34: TH0 = Czas / 256;
   00A2 75 8C 4C            397 	mov	_TH0,#0x4C
                            398 ;	Z:\AESOKZ~C\lab8dwa.c:36: Zliczanie_1sek++;
   00A5 05 09               399 	inc	_Zliczanie_1sek
                            400 ;	Z:\AESOKZ~C\lab8dwa.c:37: if(Zliczanie_1sek==20)
   00A7 74 14               401 	mov	a,#0x14
   00A9 B5 09 06            402 	cjne	a,_Zliczanie_1sek,00102$
                            403 ;	Z:\AESOKZ~C\lab8dwa.c:39: P2=1;
   00AC 75 A0 01            404 	mov	_P2,#0x01
                            405 ;	Z:\AESOKZ~C\lab8dwa.c:40: Zliczanie_1sek=0;
   00AF 75 09 00            406 	mov	_Zliczanie_1sek,#0x00
   00B2                     407 00102$:
                            408 ;	Z:\AESOKZ~C\lab8dwa.c:42: if(Zliczanie_1sek >= KoniecImp)
   00B2 E5 09               409 	mov	a,_Zliczanie_1sek
   00B4 B5 0A 00            410 	cjne	a,_KoniecImp,00111$
   00B7                     411 00111$:
   00B7 40 03               412 	jc	00105$
                            413 ;	Z:\AESOKZ~C\lab8dwa.c:44: P2=0;
   00B9 75 A0 00            414 	mov	_P2,#0x00
   00BC                     415 00105$:
   00BC D0 D0               416 	pop	psw
   00BE D0 E0               417 	pop	acc
   00C0 32                  418 	reti
                            419 ;	eliminated unneeded push/pop dpl
                            420 ;	eliminated unneeded push/pop dph
                            421 ;	eliminated unneeded push/pop b
                            422 ;------------------------------------------------------------
                            423 ;Allocation info for local variables in function 'IntINT0'
                            424 ;------------------------------------------------------------
                            425 ;------------------------------------------------------------
                            426 ;	Z:\AESOKZ~C\lab8dwa.c:48: void IntINT0(void) __interrupt(0) __using(2)
                            427 ;	-----------------------------------------
                            428 ;	 function IntINT0
                            429 ;	-----------------------------------------
   00C1                     430 _IntINT0:
   00C1 C0 E0               431 	push	acc
   00C3 C0 D0               432 	push	psw
   00C5 75 D0 10            433 	mov	psw,#0x10
                            434 ;	Z:\AESOKZ~C\lab8dwa.c:50: (P3_2)=!(P3_2);
   00C8 B2 B2               435 	cpl	_P3_2
                            436 ;	Z:\AESOKZ~C\lab8dwa.c:51: for(i = 0; i<15000;i++);
   00CA 75 0B 98            437 	mov	_i,#0x98
   00CD 75 0C 3A            438 	mov	(_i + 1),#0x3A
   00D0                     439 00103$:
   00D0 15 0B               440 	dec	_i
   00D2 74 FF               441 	mov	a,#0xff
   00D4 B5 0B 02            442 	cjne	a,_i,00108$
   00D7 15 0C               443 	dec	(_i + 1)
   00D9                     444 00108$:
   00D9 E5 0B               445 	mov	a,_i
   00DB 45 0C               446 	orl	a,(_i + 1)
   00DD 70 F1               447 	jnz	00103$
   00DF 75 0B 98            448 	mov	_i,#0x98
   00E2 75 0C 3A            449 	mov	(_i + 1),#0x3A
                            450 ;	Z:\AESOKZ~C\lab8dwa.c:52: (P3_2)=!(P3_2);
   00E5 B2 B2               451 	cpl	_P3_2
                            452 ;	Z:\AESOKZ~C\lab8dwa.c:53: PortLED=16;
   00E7 75 A0 10            453 	mov	_P2,#0x10
   00EA D0 D0               454 	pop	psw
   00EC D0 E0               455 	pop	acc
   00EE 32                  456 	reti
                            457 ;	eliminated unneeded push/pop dpl
                            458 ;	eliminated unneeded push/pop dph
                            459 ;	eliminated unneeded push/pop b
                            460 ;------------------------------------------------------------
                            461 ;Allocation info for local variables in function 'IntINT1'
                            462 ;------------------------------------------------------------
                            463 ;------------------------------------------------------------
                            464 ;	Z:\AESOKZ~C\lab8dwa.c:56: void IntINT1(void) __interrupt(2) __using(2)
                            465 ;	-----------------------------------------
                            466 ;	 function IntINT1
                            467 ;	-----------------------------------------
   00EF                     468 _IntINT1:
   00EF C0 E0               469 	push	acc
   00F1 C0 D0               470 	push	psw
   00F3 75 D0 10            471 	mov	psw,#0x10
                            472 ;	Z:\AESOKZ~C\lab8dwa.c:58: (P3_3)=!(P3_3);
   00F6 B2 B3               473 	cpl	_P3_3
                            474 ;	Z:\AESOKZ~C\lab8dwa.c:59: for(i = 0; i<15000;i++);
   00F8 75 0B 98            475 	mov	_i,#0x98
   00FB 75 0C 3A            476 	mov	(_i + 1),#0x3A
   00FE                     477 00103$:
   00FE 15 0B               478 	dec	_i
   0100 74 FF               479 	mov	a,#0xff
   0102 B5 0B 02            480 	cjne	a,_i,00108$
   0105 15 0C               481 	dec	(_i + 1)
   0107                     482 00108$:
   0107 E5 0B               483 	mov	a,_i
   0109 45 0C               484 	orl	a,(_i + 1)
   010B 70 F1               485 	jnz	00103$
   010D 75 0B 98            486 	mov	_i,#0x98
   0110 75 0C 3A            487 	mov	(_i + 1),#0x3A
                            488 ;	Z:\AESOKZ~C\lab8dwa.c:60: (P3_3)=!(P3_3);
   0113 B2 B3               489 	cpl	_P3_3
                            490 ;	Z:\AESOKZ~C\lab8dwa.c:61: PortLED = 8;
   0115 75 A0 08            491 	mov	_P2,#0x08
   0118 D0 D0               492 	pop	psw
   011A D0 E0               493 	pop	acc
   011C 32                  494 	reti
                            495 ;	eliminated unneeded push/pop dpl
                            496 ;	eliminated unneeded push/pop dph
                            497 ;	eliminated unneeded push/pop b
                            498 	.area CSEG    (CODE)
                            499 	.area CONST   (CODE)
                            500 	.area XINIT   (CODE)
                            501 	.area CABS    (ABS,CODE)

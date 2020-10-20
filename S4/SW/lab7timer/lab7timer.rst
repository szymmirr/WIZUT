                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
                              4 ; This file was generated Fri Apr 28 16:51:46 2017
                              5 ;--------------------------------------------------------
                              6 	.module LEA43L_C
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _IntTIM0
                             13 	.globl _main
                             14 	.globl _CY
                             15 	.globl _AC
                             16 	.globl _F0
                             17 	.globl _RS1
                             18 	.globl _RS0
                             19 	.globl _OV
                             20 	.globl _F1
                             21 	.globl _P
                             22 	.globl _PS
                             23 	.globl _PT1
                             24 	.globl _PX1
                             25 	.globl _PT0
                             26 	.globl _PX0
                             27 	.globl _RD
                             28 	.globl _WR
                             29 	.globl _T1
                             30 	.globl _T0
                             31 	.globl _INT1
                             32 	.globl _INT0
                             33 	.globl _TXD
                             34 	.globl _RXD
                             35 	.globl _P3_7
                             36 	.globl _P3_6
                             37 	.globl _P3_5
                             38 	.globl _P3_4
                             39 	.globl _P3_3
                             40 	.globl _P3_2
                             41 	.globl _P3_1
                             42 	.globl _P3_0
                             43 	.globl _EA
                             44 	.globl _ES
                             45 	.globl _ET1
                             46 	.globl _EX1
                             47 	.globl _ET0
                             48 	.globl _EX0
                             49 	.globl _P2_7
                             50 	.globl _P2_6
                             51 	.globl _P2_5
                             52 	.globl _P2_4
                             53 	.globl _P2_3
                             54 	.globl _P2_2
                             55 	.globl _P2_1
                             56 	.globl _P2_0
                             57 	.globl _SM0
                             58 	.globl _SM1
                             59 	.globl _SM2
                             60 	.globl _REN
                             61 	.globl _TB8
                             62 	.globl _RB8
                             63 	.globl _TI
                             64 	.globl _RI
                             65 	.globl _P1_7
                             66 	.globl _P1_6
                             67 	.globl _P1_5
                             68 	.globl _P1_4
                             69 	.globl _P1_3
                             70 	.globl _P1_2
                             71 	.globl _P1_1
                             72 	.globl _P1_0
                             73 	.globl _TF1
                             74 	.globl _TR1
                             75 	.globl _TF0
                             76 	.globl _TR0
                             77 	.globl _IE1
                             78 	.globl _IT1
                             79 	.globl _IE0
                             80 	.globl _IT0
                             81 	.globl _P0_7
                             82 	.globl _P0_6
                             83 	.globl _P0_5
                             84 	.globl _P0_4
                             85 	.globl _P0_3
                             86 	.globl _P0_2
                             87 	.globl _P0_1
                             88 	.globl _P0_0
                             89 	.globl _B
                             90 	.globl _ACC
                             91 	.globl _PSW
                             92 	.globl _IP
                             93 	.globl _P3
                             94 	.globl _IE
                             95 	.globl _P2
                             96 	.globl _SBUF
                             97 	.globl _SCON
                             98 	.globl _P1
                             99 	.globl _TH1
                            100 	.globl _TH0
                            101 	.globl _TL1
                            102 	.globl _TL0
                            103 	.globl _TMOD
                            104 	.globl _TCON
                            105 	.globl _PCON
                            106 	.globl _DPH
                            107 	.globl _DPL
                            108 	.globl _SP
                            109 	.globl _P0
                            110 	.globl _i
                            111 	.globl _KoniecImp
                            112 	.globl _Zliczanie_1sek
                            113 	.globl _Licznik
                            114 ;--------------------------------------------------------
                            115 ; special function registers
                            116 ;--------------------------------------------------------
                            117 	.area RSEG    (ABS,DATA)
   0000                     118 	.org 0x0000
                    0080    119 _P0	=	0x0080
                    0081    120 _SP	=	0x0081
                    0082    121 _DPL	=	0x0082
                    0083    122 _DPH	=	0x0083
                    0087    123 _PCON	=	0x0087
                    0088    124 _TCON	=	0x0088
                    0089    125 _TMOD	=	0x0089
                    008A    126 _TL0	=	0x008a
                    008B    127 _TL1	=	0x008b
                    008C    128 _TH0	=	0x008c
                    008D    129 _TH1	=	0x008d
                    0090    130 _P1	=	0x0090
                    0098    131 _SCON	=	0x0098
                    0099    132 _SBUF	=	0x0099
                    00A0    133 _P2	=	0x00a0
                    00A8    134 _IE	=	0x00a8
                    00B0    135 _P3	=	0x00b0
                    00B8    136 _IP	=	0x00b8
                    00D0    137 _PSW	=	0x00d0
                    00E0    138 _ACC	=	0x00e0
                    00F0    139 _B	=	0x00f0
                            140 ;--------------------------------------------------------
                            141 ; special function bits
                            142 ;--------------------------------------------------------
                            143 	.area RSEG    (ABS,DATA)
   0000                     144 	.org 0x0000
                    0080    145 _P0_0	=	0x0080
                    0081    146 _P0_1	=	0x0081
                    0082    147 _P0_2	=	0x0082
                    0083    148 _P0_3	=	0x0083
                    0084    149 _P0_4	=	0x0084
                    0085    150 _P0_5	=	0x0085
                    0086    151 _P0_6	=	0x0086
                    0087    152 _P0_7	=	0x0087
                    0088    153 _IT0	=	0x0088
                    0089    154 _IE0	=	0x0089
                    008A    155 _IT1	=	0x008a
                    008B    156 _IE1	=	0x008b
                    008C    157 _TR0	=	0x008c
                    008D    158 _TF0	=	0x008d
                    008E    159 _TR1	=	0x008e
                    008F    160 _TF1	=	0x008f
                    0090    161 _P1_0	=	0x0090
                    0091    162 _P1_1	=	0x0091
                    0092    163 _P1_2	=	0x0092
                    0093    164 _P1_3	=	0x0093
                    0094    165 _P1_4	=	0x0094
                    0095    166 _P1_5	=	0x0095
                    0096    167 _P1_6	=	0x0096
                    0097    168 _P1_7	=	0x0097
                    0098    169 _RI	=	0x0098
                    0099    170 _TI	=	0x0099
                    009A    171 _RB8	=	0x009a
                    009B    172 _TB8	=	0x009b
                    009C    173 _REN	=	0x009c
                    009D    174 _SM2	=	0x009d
                    009E    175 _SM1	=	0x009e
                    009F    176 _SM0	=	0x009f
                    00A0    177 _P2_0	=	0x00a0
                    00A1    178 _P2_1	=	0x00a1
                    00A2    179 _P2_2	=	0x00a2
                    00A3    180 _P2_3	=	0x00a3
                    00A4    181 _P2_4	=	0x00a4
                    00A5    182 _P2_5	=	0x00a5
                    00A6    183 _P2_6	=	0x00a6
                    00A7    184 _P2_7	=	0x00a7
                    00A8    185 _EX0	=	0x00a8
                    00A9    186 _ET0	=	0x00a9
                    00AA    187 _EX1	=	0x00aa
                    00AB    188 _ET1	=	0x00ab
                    00AC    189 _ES	=	0x00ac
                    00AF    190 _EA	=	0x00af
                    00B0    191 _P3_0	=	0x00b0
                    00B1    192 _P3_1	=	0x00b1
                    00B2    193 _P3_2	=	0x00b2
                    00B3    194 _P3_3	=	0x00b3
                    00B4    195 _P3_4	=	0x00b4
                    00B5    196 _P3_5	=	0x00b5
                    00B6    197 _P3_6	=	0x00b6
                    00B7    198 _P3_7	=	0x00b7
                    00B0    199 _RXD	=	0x00b0
                    00B1    200 _TXD	=	0x00b1
                    00B2    201 _INT0	=	0x00b2
                    00B3    202 _INT1	=	0x00b3
                    00B4    203 _T0	=	0x00b4
                    00B5    204 _T1	=	0x00b5
                    00B6    205 _WR	=	0x00b6
                    00B7    206 _RD	=	0x00b7
                    00B8    207 _PX0	=	0x00b8
                    00B9    208 _PT0	=	0x00b9
                    00BA    209 _PX1	=	0x00ba
                    00BB    210 _PT1	=	0x00bb
                    00BC    211 _PS	=	0x00bc
                    00D0    212 _P	=	0x00d0
                    00D1    213 _F1	=	0x00d1
                    00D2    214 _OV	=	0x00d2
                    00D3    215 _RS0	=	0x00d3
                    00D4    216 _RS1	=	0x00d4
                    00D5    217 _F0	=	0x00d5
                    00D6    218 _AC	=	0x00d6
                    00D7    219 _CY	=	0x00d7
                            220 ;--------------------------------------------------------
                            221 ; overlayable register banks
                            222 ;--------------------------------------------------------
                            223 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     224 	.ds 8
                            225 	.area REG_BANK_2	(REL,OVR,DATA)
   0010                     226 	.ds 8
                            227 ;--------------------------------------------------------
                            228 ; internal ram data
                            229 ;--------------------------------------------------------
                            230 	.area DSEG    (DATA)
   0008                     231 _Licznik::
   0008                     232 	.ds 1
   0009                     233 _Zliczanie_1sek::
   0009                     234 	.ds 1
   000A                     235 _KoniecImp::
   000A                     236 	.ds 1
   000B                     237 _i::
   000B                     238 	.ds 2
                            239 ;--------------------------------------------------------
                            240 ; overlayable items in internal ram 
                            241 ;--------------------------------------------------------
                            242 	.area OSEG    (OVR,DATA)
                            243 ;--------------------------------------------------------
                            244 ; Stack segment in internal ram 
                            245 ;--------------------------------------------------------
                            246 	.area	SSEG	(DATA)
   0018                     247 __start__stack:
   0018                     248 	.ds	1
                            249 
                            250 ;--------------------------------------------------------
                            251 ; indirectly addressable internal ram data
                            252 ;--------------------------------------------------------
                            253 	.area ISEG    (DATA)
                            254 ;--------------------------------------------------------
                            255 ; absolute internal ram data
                            256 ;--------------------------------------------------------
                            257 	.area IABS    (ABS,DATA)
                            258 	.area IABS    (ABS,DATA)
                            259 ;--------------------------------------------------------
                            260 ; bit data
                            261 ;--------------------------------------------------------
                            262 	.area BSEG    (BIT)
                            263 ;--------------------------------------------------------
                            264 ; paged external ram data
                            265 ;--------------------------------------------------------
                            266 	.area PSEG    (PAG,XDATA)
                            267 ;--------------------------------------------------------
                            268 ; external ram data
                            269 ;--------------------------------------------------------
                            270 	.area XSEG    (XDATA)
                            271 ;--------------------------------------------------------
                            272 ; absolute external ram data
                            273 ;--------------------------------------------------------
                            274 	.area XABS    (ABS,XDATA)
                            275 ;--------------------------------------------------------
                            276 ; external initialized ram data
                            277 ;--------------------------------------------------------
                            278 	.area XISEG   (XDATA)
                            279 	.area HOME    (CODE)
                            280 	.area GSINIT0 (CODE)
                            281 	.area GSINIT1 (CODE)
                            282 	.area GSINIT2 (CODE)
                            283 	.area GSINIT3 (CODE)
                            284 	.area GSINIT4 (CODE)
                            285 	.area GSINIT5 (CODE)
                            286 	.area GSINIT  (CODE)
                            287 	.area GSFINAL (CODE)
                            288 	.area CSEG    (CODE)
                            289 ;--------------------------------------------------------
                            290 ; interrupt vector 
                            291 ;--------------------------------------------------------
                            292 	.area HOME    (CODE)
   0000                     293 __interrupt_vect:
   0000 02 00 13            294 	ljmp	__sdcc_gsinit_startup
   0003 32                  295 	reti
   0004                     296 	.ds	7
   000B 02 00 E4            297 	ljmp	_IntTIM0
                            298 ;--------------------------------------------------------
                            299 ; global & static initialisations
                            300 ;--------------------------------------------------------
                            301 	.area HOME    (CODE)
                            302 	.area GSINIT  (CODE)
                            303 	.area GSFINAL (CODE)
                            304 	.area GSINIT  (CODE)
                            305 	.globl __sdcc_gsinit_startup
                            306 	.globl __sdcc_program_startup
                            307 	.globl __start__stack
                            308 	.globl __mcs51_genXINIT
                            309 	.globl __mcs51_genXRAMCLEAR
                            310 	.globl __mcs51_genRAMCLEAR
                            311 ;	Z:\AESOKZ~C\LEA43L~C.C:8: unsigned char Licznik = 1;
   006C 75 08 01            312 	mov	_Licznik,#0x01
                            313 ;	Z:\AESOKZ~C\LEA43L~C.C:10: unsigned char KoniecImp=5;
   006F 75 0A 05            314 	mov	_KoniecImp,#0x05
                            315 	.area GSFINAL (CODE)
   0072 02 00 0E            316 	ljmp	__sdcc_program_startup
                            317 ;--------------------------------------------------------
                            318 ; Home
                            319 ;--------------------------------------------------------
                            320 	.area HOME    (CODE)
                            321 	.area HOME    (CODE)
   000E                     322 __sdcc_program_startup:
   000E 12 00 75            323 	lcall	_main
                            324 ;	return from main will lock up
   0011 80 FE               325 	sjmp .
                            326 ;--------------------------------------------------------
                            327 ; code
                            328 ;--------------------------------------------------------
                            329 	.area CSEG    (CODE)
                            330 ;------------------------------------------------------------
                            331 ;Allocation info for local variables in function 'main'
                            332 ;------------------------------------------------------------
                            333 ;------------------------------------------------------------
                            334 ;	Z:\AESOKZ~C\LEA43L~C.C:13: int main(void)
                            335 ;	-----------------------------------------
                            336 ;	 function main
                            337 ;	-----------------------------------------
   0075                     338 _main:
                    0002    339 	ar2 = 0x02
                    0003    340 	ar3 = 0x03
                    0004    341 	ar4 = 0x04
                    0005    342 	ar5 = 0x05
                    0006    343 	ar6 = 0x06
                    0007    344 	ar7 = 0x07
                    0000    345 	ar0 = 0x00
                    0001    346 	ar1 = 0x01
                            347 ;	Z:\AESOKZ~C\LEA43L~C.C:15: TMOD=0x11;
   0075 75 89 11            348 	mov	_TMOD,#0x11
                            349 ;	Z:\AESOKZ~C\LEA43L~C.C:16: PortLED=0;
   0078 75 A0 00            350 	mov	_P2,#0x00
                            351 ;	Z:\AESOKZ~C\LEA43L~C.C:17: TL0 = Czas % 256;
   007B 75 8A 00            352 	mov	_TL0,#0x00
                            353 ;	Z:\AESOKZ~C\LEA43L~C.C:18: TH0 = Czas / 256;
   007E 75 8C 4C            354 	mov	_TH0,#0x4C
                            355 ;	Z:\AESOKZ~C\LEA43L~C.C:19: TR0 = 1;
   0081 D2 8C               356 	setb	_TR0
                            357 ;	Z:\AESOKZ~C\LEA43L~C.C:20: Zliczanie_1sek=0;
   0083 75 09 00            358 	mov	_Zliczanie_1sek,#0x00
                            359 ;	Z:\AESOKZ~C\LEA43L~C.C:21: ET0 = 1;
   0086 D2 A9               360 	setb	_ET0
                            361 ;	Z:\AESOKZ~C\LEA43L~C.C:22: EA = 1;
   0088 D2 AF               362 	setb	_EA
                            363 ;	Z:\AESOKZ~C\LEA43L~C.C:26: while(StykP1 && StykP2);
   008A                     364 00102$:
   008A 30 B0 03            365 	jnb	_P3_0,00104$
   008D 20 B1 FA            366 	jb	_P3_1,00102$
   0090                     367 00104$:
                            368 ;	Z:\AESOKZ~C\LEA43L~C.C:27: for(i=1;i<5000;i++);
   0090 75 0B 87            369 	mov	_i,#0x87
   0093 75 0C 13            370 	mov	(_i + 1),#0x13
   0096                     371 00121$:
   0096 15 0B               372 	dec	_i
   0098 74 FF               373 	mov	a,#0xff
   009A B5 0B 02            374 	cjne	a,_i,00141$
   009D 15 0C               375 	dec	(_i + 1)
   009F                     376 00141$:
   009F E5 0B               377 	mov	a,_i
   00A1 45 0C               378 	orl	a,(_i + 1)
   00A3 70 F1               379 	jnz	00121$
   00A5 75 0B 88            380 	mov	_i,#0x88
   00A8 75 0C 13            381 	mov	(_i + 1),#0x13
                            382 ;	Z:\AESOKZ~C\LEA43L~C.C:28: if(StykP1)
   00AB 30 B0 0A            383 	jnb	_P3_0,00110$
                            384 ;	Z:\AESOKZ~C\LEA43L~C.C:30: if(KoniecImp < Gora)Licznik++;
   00AE 74 F6               385 	mov	a,#0x100 - 0x0A
   00B0 25 0A               386 	add	a,_KoniecImp
   00B2 40 0D               387 	jc	00113$
   00B4 05 08               388 	inc	_Licznik
   00B6 80 09               389 	sjmp	00113$
   00B8                     390 00110$:
                            391 ;	Z:\AESOKZ~C\LEA43L~C.C:34: if(KoniecImp > Dool)Licznik--;
   00B8 74 01               392 	mov	a,#0x01
   00BA B5 0A 00            393 	cjne	a,_KoniecImp,00145$
   00BD                     394 00145$:
   00BD 50 02               395 	jnc	00113$
   00BF 15 08               396 	dec	_Licznik
                            397 ;	Z:\AESOKZ~C\LEA43L~C.C:36: while(!StykP1 || !StykP2);
   00C1                     398 00113$:
   00C1 30 B0 FD            399 	jnb	_P3_0,00113$
   00C4 30 B1 FA            400 	jnb	_P3_1,00113$
                            401 ;	Z:\AESOKZ~C\LEA43L~C.C:37: for(i=0;i<5000;i++);
   00C7 75 0B 88            402 	mov	_i,#0x88
   00CA 75 0C 13            403 	mov	(_i + 1),#0x13
   00CD                     404 00124$:
   00CD 15 0B               405 	dec	_i
   00CF 74 FF               406 	mov	a,#0xff
   00D1 B5 0B 02            407 	cjne	a,_i,00149$
   00D4 15 0C               408 	dec	(_i + 1)
   00D6                     409 00149$:
   00D6 E5 0B               410 	mov	a,_i
   00D8 45 0C               411 	orl	a,(_i + 1)
   00DA 70 F1               412 	jnz	00124$
   00DC 75 0B 88            413 	mov	_i,#0x88
   00DF 75 0C 13            414 	mov	(_i + 1),#0x13
   00E2 80 A6               415 	sjmp	00102$
                            416 ;------------------------------------------------------------
                            417 ;Allocation info for local variables in function 'IntTIM0'
                            418 ;------------------------------------------------------------
                            419 ;------------------------------------------------------------
                            420 ;	Z:\AESOKZ~C\LEA43L~C.C:41: void IntTIM0(void) __interrupt(1) __using(2)
                            421 ;	-----------------------------------------
                            422 ;	 function IntTIM0
                            423 ;	-----------------------------------------
   00E4                     424 _IntTIM0:
                    0012    425 	ar2 = 0x12
                    0013    426 	ar3 = 0x13
                    0014    427 	ar4 = 0x14
                    0015    428 	ar5 = 0x15
                    0016    429 	ar6 = 0x16
                    0017    430 	ar7 = 0x17
                    0010    431 	ar0 = 0x10
                    0011    432 	ar1 = 0x11
   00E4 C0 E0               433 	push	acc
   00E6 C0 D0               434 	push	psw
   00E8 75 D0 10            435 	mov	psw,#0x10
                            436 ;	Z:\AESOKZ~C\LEA43L~C.C:43: TL0 = Czas % 256;
   00EB 75 8A 00            437 	mov	_TL0,#0x00
                            438 ;	Z:\AESOKZ~C\LEA43L~C.C:44: TH0 = Czas / 256;
   00EE 75 8C 4C            439 	mov	_TH0,#0x4C
                            440 ;	Z:\AESOKZ~C\LEA43L~C.C:46: Zliczanie_1sek++;
   00F1 05 09               441 	inc	_Zliczanie_1sek
                            442 ;	Z:\AESOKZ~C\LEA43L~C.C:47: if(Zliczanie_1sek==20)
   00F3 74 14               443 	mov	a,#0x14
   00F5 B5 09 06            444 	cjne	a,_Zliczanie_1sek,00102$
                            445 ;	Z:\AESOKZ~C\LEA43L~C.C:49: P2=1;
   00F8 75 A0 01            446 	mov	_P2,#0x01
                            447 ;	Z:\AESOKZ~C\LEA43L~C.C:50: Zliczanie_1sek=0;
   00FB 75 09 00            448 	mov	_Zliczanie_1sek,#0x00
   00FE                     449 00102$:
                            450 ;	Z:\AESOKZ~C\LEA43L~C.C:52: if(Zliczanie_1sek >= Licznik)
   00FE E5 09               451 	mov	a,_Zliczanie_1sek
   0100 B5 08 00            452 	cjne	a,_Licznik,00111$
   0103                     453 00111$:
   0103 40 03               454 	jc	00105$
                            455 ;	Z:\AESOKZ~C\LEA43L~C.C:54: P2=0;
   0105 75 A0 00            456 	mov	_P2,#0x00
   0108                     457 00105$:
   0108 D0 D0               458 	pop	psw
   010A D0 E0               459 	pop	acc
   010C 32                  460 	reti
                            461 ;	eliminated unneeded push/pop dpl
                            462 ;	eliminated unneeded push/pop dph
                            463 ;	eliminated unneeded push/pop b
                            464 	.area CSEG    (CODE)
                            465 	.area CONST   (CODE)
                            466 	.area XINIT   (CODE)
                            467 	.area CABS    (ABS,CODE)

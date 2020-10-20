                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
                              4 ; This file was generated Fri Jun 09 17:53:49 2017
                              5 ;--------------------------------------------------------
                              6 	.module lcd
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _CY
                             14 	.globl _AC
                             15 	.globl _F0
                             16 	.globl _RS1
                             17 	.globl _RS0
                             18 	.globl _OV
                             19 	.globl _F1
                             20 	.globl _P
                             21 	.globl _PS
                             22 	.globl _PT1
                             23 	.globl _PX1
                             24 	.globl _PT0
                             25 	.globl _PX0
                             26 	.globl _RD
                             27 	.globl _WR
                             28 	.globl _T1
                             29 	.globl _T0
                             30 	.globl _INT1
                             31 	.globl _INT0
                             32 	.globl _TXD
                             33 	.globl _RXD
                             34 	.globl _P3_7
                             35 	.globl _P3_6
                             36 	.globl _P3_5
                             37 	.globl _P3_4
                             38 	.globl _P3_3
                             39 	.globl _P3_2
                             40 	.globl _P3_1
                             41 	.globl _P3_0
                             42 	.globl _EA
                             43 	.globl _ES
                             44 	.globl _ET1
                             45 	.globl _EX1
                             46 	.globl _ET0
                             47 	.globl _EX0
                             48 	.globl _P2_7
                             49 	.globl _P2_6
                             50 	.globl _P2_5
                             51 	.globl _P2_4
                             52 	.globl _P2_3
                             53 	.globl _P2_2
                             54 	.globl _P2_1
                             55 	.globl _P2_0
                             56 	.globl _SM0
                             57 	.globl _SM1
                             58 	.globl _SM2
                             59 	.globl _REN
                             60 	.globl _TB8
                             61 	.globl _RB8
                             62 	.globl _TI
                             63 	.globl _RI
                             64 	.globl _P1_7
                             65 	.globl _P1_6
                             66 	.globl _P1_5
                             67 	.globl _P1_4
                             68 	.globl _P1_3
                             69 	.globl _P1_2
                             70 	.globl _P1_1
                             71 	.globl _P1_0
                             72 	.globl _TF1
                             73 	.globl _TR1
                             74 	.globl _TF0
                             75 	.globl _TR0
                             76 	.globl _IE1
                             77 	.globl _IT1
                             78 	.globl _IE0
                             79 	.globl _IT0
                             80 	.globl _P0_7
                             81 	.globl _P0_6
                             82 	.globl _P0_5
                             83 	.globl _P0_4
                             84 	.globl _P0_3
                             85 	.globl _P0_2
                             86 	.globl _P0_1
                             87 	.globl _P0_0
                             88 	.globl _B
                             89 	.globl _ACC
                             90 	.globl _PSW
                             91 	.globl _IP
                             92 	.globl _P3
                             93 	.globl _IE
                             94 	.globl _P2
                             95 	.globl _SBUF
                             96 	.globl _SCON
                             97 	.globl _P1
                             98 	.globl _TH1
                             99 	.globl _TH0
                            100 	.globl _TL1
                            101 	.globl _TL0
                            102 	.globl _TMOD
                            103 	.globl _TCON
                            104 	.globl _PCON
                            105 	.globl _DPH
                            106 	.globl _DPL
                            107 	.globl _SP
                            108 	.globl _P0
                            109 	.globl _M
                            110 	.globl _y
                            111 	.globl _i
                            112 	.globl _INIT
                            113 	.globl _LCDWC
                            114 	.globl _LCDWD
                            115 	.globl _LCDRC
                            116 	.globl _LCDRD
                            117 	.globl _STROBE
                            118 	.globl _PZNAK
                            119 	.globl _PISZKOM
                            120 	.globl _CZYZAJ
                            121 	.globl _Delay
                            122 	.globl _GoToXY
                            123 	.globl _LicznikLCD
                            124 	.globl _StringLCD
                            125 	.globl _NumLCD
                            126 ;--------------------------------------------------------
                            127 ; special function registers
                            128 ;--------------------------------------------------------
                            129 	.area RSEG    (ABS,DATA)
   0000                     130 	.org 0x0000
                    0080    131 _P0	=	0x0080
                    0081    132 _SP	=	0x0081
                    0082    133 _DPL	=	0x0082
                    0083    134 _DPH	=	0x0083
                    0087    135 _PCON	=	0x0087
                    0088    136 _TCON	=	0x0088
                    0089    137 _TMOD	=	0x0089
                    008A    138 _TL0	=	0x008a
                    008B    139 _TL1	=	0x008b
                    008C    140 _TH0	=	0x008c
                    008D    141 _TH1	=	0x008d
                    0090    142 _P1	=	0x0090
                    0098    143 _SCON	=	0x0098
                    0099    144 _SBUF	=	0x0099
                    00A0    145 _P2	=	0x00a0
                    00A8    146 _IE	=	0x00a8
                    00B0    147 _P3	=	0x00b0
                    00B8    148 _IP	=	0x00b8
                    00D0    149 _PSW	=	0x00d0
                    00E0    150 _ACC	=	0x00e0
                    00F0    151 _B	=	0x00f0
                            152 ;--------------------------------------------------------
                            153 ; special function bits
                            154 ;--------------------------------------------------------
                            155 	.area RSEG    (ABS,DATA)
   0000                     156 	.org 0x0000
                    0080    157 _P0_0	=	0x0080
                    0081    158 _P0_1	=	0x0081
                    0082    159 _P0_2	=	0x0082
                    0083    160 _P0_3	=	0x0083
                    0084    161 _P0_4	=	0x0084
                    0085    162 _P0_5	=	0x0085
                    0086    163 _P0_6	=	0x0086
                    0087    164 _P0_7	=	0x0087
                    0088    165 _IT0	=	0x0088
                    0089    166 _IE0	=	0x0089
                    008A    167 _IT1	=	0x008a
                    008B    168 _IE1	=	0x008b
                    008C    169 _TR0	=	0x008c
                    008D    170 _TF0	=	0x008d
                    008E    171 _TR1	=	0x008e
                    008F    172 _TF1	=	0x008f
                    0090    173 _P1_0	=	0x0090
                    0091    174 _P1_1	=	0x0091
                    0092    175 _P1_2	=	0x0092
                    0093    176 _P1_3	=	0x0093
                    0094    177 _P1_4	=	0x0094
                    0095    178 _P1_5	=	0x0095
                    0096    179 _P1_6	=	0x0096
                    0097    180 _P1_7	=	0x0097
                    0098    181 _RI	=	0x0098
                    0099    182 _TI	=	0x0099
                    009A    183 _RB8	=	0x009a
                    009B    184 _TB8	=	0x009b
                    009C    185 _REN	=	0x009c
                    009D    186 _SM2	=	0x009d
                    009E    187 _SM1	=	0x009e
                    009F    188 _SM0	=	0x009f
                    00A0    189 _P2_0	=	0x00a0
                    00A1    190 _P2_1	=	0x00a1
                    00A2    191 _P2_2	=	0x00a2
                    00A3    192 _P2_3	=	0x00a3
                    00A4    193 _P2_4	=	0x00a4
                    00A5    194 _P2_5	=	0x00a5
                    00A6    195 _P2_6	=	0x00a6
                    00A7    196 _P2_7	=	0x00a7
                    00A8    197 _EX0	=	0x00a8
                    00A9    198 _ET0	=	0x00a9
                    00AA    199 _EX1	=	0x00aa
                    00AB    200 _ET1	=	0x00ab
                    00AC    201 _ES	=	0x00ac
                    00AF    202 _EA	=	0x00af
                    00B0    203 _P3_0	=	0x00b0
                    00B1    204 _P3_1	=	0x00b1
                    00B2    205 _P3_2	=	0x00b2
                    00B3    206 _P3_3	=	0x00b3
                    00B4    207 _P3_4	=	0x00b4
                    00B5    208 _P3_5	=	0x00b5
                    00B6    209 _P3_6	=	0x00b6
                    00B7    210 _P3_7	=	0x00b7
                    00B0    211 _RXD	=	0x00b0
                    00B1    212 _TXD	=	0x00b1
                    00B2    213 _INT0	=	0x00b2
                    00B3    214 _INT1	=	0x00b3
                    00B4    215 _T0	=	0x00b4
                    00B5    216 _T1	=	0x00b5
                    00B6    217 _WR	=	0x00b6
                    00B7    218 _RD	=	0x00b7
                    00B8    219 _PX0	=	0x00b8
                    00B9    220 _PT0	=	0x00b9
                    00BA    221 _PX1	=	0x00ba
                    00BB    222 _PT1	=	0x00bb
                    00BC    223 _PS	=	0x00bc
                    00D0    224 _P	=	0x00d0
                    00D1    225 _F1	=	0x00d1
                    00D2    226 _OV	=	0x00d2
                    00D3    227 _RS0	=	0x00d3
                    00D4    228 _RS1	=	0x00d4
                    00D5    229 _F0	=	0x00d5
                    00D6    230 _AC	=	0x00d6
                    00D7    231 _CY	=	0x00d7
                            232 ;--------------------------------------------------------
                            233 ; overlayable register banks
                            234 ;--------------------------------------------------------
                            235 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     236 	.ds 8
                            237 ;--------------------------------------------------------
                            238 ; internal ram data
                            239 ;--------------------------------------------------------
                            240 	.area DSEG    (DATA)
   0008                     241 _i::
   0008                     242 	.ds 2
   000A                     243 _y::
   000A                     244 	.ds 2
   000C                     245 _M::
   000C                     246 	.ds 1
                            247 ;--------------------------------------------------------
                            248 ; overlayable items in internal ram 
                            249 ;--------------------------------------------------------
                            250 	.area OSEG    (OVR,DATA)
                            251 ;--------------------------------------------------------
                            252 ; Stack segment in internal ram 
                            253 ;--------------------------------------------------------
                            254 	.area	SSEG	(DATA)
   000E                     255 __start__stack:
   000E                     256 	.ds	1
                            257 
                            258 ;--------------------------------------------------------
                            259 ; indirectly addressable internal ram data
                            260 ;--------------------------------------------------------
                            261 	.area ISEG    (DATA)
                            262 ;--------------------------------------------------------
                            263 ; absolute internal ram data
                            264 ;--------------------------------------------------------
                            265 	.area IABS    (ABS,DATA)
                            266 	.area IABS    (ABS,DATA)
                            267 ;--------------------------------------------------------
                            268 ; bit data
                            269 ;--------------------------------------------------------
                            270 	.area BSEG    (BIT)
                            271 ;--------------------------------------------------------
                            272 ; paged external ram data
                            273 ;--------------------------------------------------------
                            274 	.area PSEG    (PAG,XDATA)
                            275 ;--------------------------------------------------------
                            276 ; external ram data
                            277 ;--------------------------------------------------------
                            278 	.area XSEG    (XDATA)
                            279 ;--------------------------------------------------------
                            280 ; absolute external ram data
                            281 ;--------------------------------------------------------
                            282 	.area XABS    (ABS,XDATA)
                            283 ;--------------------------------------------------------
                            284 ; external initialized ram data
                            285 ;--------------------------------------------------------
                            286 	.area XISEG   (XDATA)
                            287 	.area HOME    (CODE)
                            288 	.area GSINIT0 (CODE)
                            289 	.area GSINIT1 (CODE)
                            290 	.area GSINIT2 (CODE)
                            291 	.area GSINIT3 (CODE)
                            292 	.area GSINIT4 (CODE)
                            293 	.area GSINIT5 (CODE)
                            294 	.area GSINIT  (CODE)
                            295 	.area GSFINAL (CODE)
                            296 	.area CSEG    (CODE)
                            297 ;--------------------------------------------------------
                            298 ; interrupt vector 
                            299 ;--------------------------------------------------------
                            300 	.area HOME    (CODE)
   0000                     301 __interrupt_vect:
   0000 02 00 08            302 	ljmp	__sdcc_gsinit_startup
                            303 ;--------------------------------------------------------
                            304 ; global & static initialisations
                            305 ;--------------------------------------------------------
                            306 	.area HOME    (CODE)
                            307 	.area GSINIT  (CODE)
                            308 	.area GSFINAL (CODE)
                            309 	.area GSINIT  (CODE)
                            310 	.globl __sdcc_gsinit_startup
                            311 	.globl __sdcc_program_startup
                            312 	.globl __start__stack
                            313 	.globl __mcs51_genXINIT
                            314 	.globl __mcs51_genXRAMCLEAR
                            315 	.globl __mcs51_genRAMCLEAR
                            316 	.area GSFINAL (CODE)
   0061 02 00 03            317 	ljmp	__sdcc_program_startup
                            318 ;--------------------------------------------------------
                            319 ; Home
                            320 ;--------------------------------------------------------
                            321 	.area HOME    (CODE)
                            322 	.area HOME    (CODE)
   0003                     323 __sdcc_program_startup:
   0003 12 03 1D            324 	lcall	_main
                            325 ;	return from main will lock up
   0006 80 FE               326 	sjmp .
                            327 ;--------------------------------------------------------
                            328 ; code
                            329 ;--------------------------------------------------------
                            330 	.area CSEG    (CODE)
                            331 ;------------------------------------------------------------
                            332 ;Allocation info for local variables in function 'INIT'
                            333 ;------------------------------------------------------------
                            334 ;------------------------------------------------------------
                            335 ;	Z:\AESOKZ~C\lcd.c:28: void INIT(void)
                            336 ;	-----------------------------------------
                            337 ;	 function INIT
                            338 ;	-----------------------------------------
   0064                     339 _INIT:
                    0002    340 	ar2 = 0x02
                    0003    341 	ar3 = 0x03
                    0004    342 	ar4 = 0x04
                    0005    343 	ar5 = 0x05
                    0006    344 	ar6 = 0x06
                    0007    345 	ar7 = 0x07
                    0000    346 	ar0 = 0x00
                    0001    347 	ar1 = 0x01
                            348 ;	Z:\AESOKZ~C\lcd.c:30: LCDWC();
   0064 12 00 8B            349 	lcall	_LCDWC
                            350 ;	Z:\AESOKZ~C\lcd.c:31: Delay(10000);
   0067 90 27 10            351 	mov	dptr,#0x2710
   006A 12 00 E3            352 	lcall	_Delay
                            353 ;	Z:\AESOKZ~C\lcd.c:32: LCDDataPort=0x38;
   006D 75 A0 38            354 	mov	_P2,#0x38
                            355 ;	Z:\AESOKZ~C\lcd.c:33: i=1;
   0070 75 08 01            356 	mov	_i,#0x01
   0073 75 09 00            357 	mov	(_i + 1),#0x00
                            358 ;	Z:\AESOKZ~C\lcd.c:36: Delay(10000);
   0076 90 27 10            359 	mov	dptr,#0x2710
   0079 12 00 E3            360 	lcall	_Delay
                            361 ;	Z:\AESOKZ~C\lcd.c:37: LCDWC();
   007C 12 00 8B            362 	lcall	_LCDWC
                            363 ;	Z:\AESOKZ~C\lcd.c:38: STROBE();
   007F 12 00 A5            364 	lcall	_STROBE
                            365 ;	Z:\AESOKZ~C\lcd.c:39: i++;
   0082 05 08               366 	inc	_i
   0084 E4                  367 	clr	a
   0085 B5 08 02            368 	cjne	a,_i,00107$
   0088 05 09               369 	inc	(_i + 1)
   008A                     370 00107$:
                            371 ;	Z:\AESOKZ~C\lcd.c:47: LCDWC();
   008A 22                  372 	ret
                            373 ;------------------------------------------------------------
                            374 ;Allocation info for local variables in function 'LCDWC'
                            375 ;------------------------------------------------------------
                            376 ;------------------------------------------------------------
                            377 ;	Z:\AESOKZ~C\lcd.c:51: void LCDWC(void)
                            378 ;	-----------------------------------------
                            379 ;	 function LCDWC
                            380 ;	-----------------------------------------
   008B                     381 _LCDWC:
                            382 ;	Z:\AESOKZ~C\lcd.c:53: LCDRS=0;
   008B C2 80               383 	clr	_P0_0
                            384 ;	Z:\AESOKZ~C\lcd.c:54: LCDRW=0;
   008D C2 81               385 	clr	_P0_1
   008F 22                  386 	ret
                            387 ;------------------------------------------------------------
                            388 ;Allocation info for local variables in function 'LCDWD'
                            389 ;------------------------------------------------------------
                            390 ;------------------------------------------------------------
                            391 ;	Z:\AESOKZ~C\lcd.c:57: void LCDWD(void)
                            392 ;	-----------------------------------------
                            393 ;	 function LCDWD
                            394 ;	-----------------------------------------
   0090                     395 _LCDWD:
                            396 ;	Z:\AESOKZ~C\lcd.c:59: LCDRS=1;
   0090 D2 80               397 	setb	_P0_0
                            398 ;	Z:\AESOKZ~C\lcd.c:60: LCDRW=0;
   0092 C2 81               399 	clr	_P0_1
   0094 22                  400 	ret
                            401 ;------------------------------------------------------------
                            402 ;Allocation info for local variables in function 'LCDRC'
                            403 ;------------------------------------------------------------
                            404 ;------------------------------------------------------------
                            405 ;	Z:\AESOKZ~C\lcd.c:63: void LCDRC(void)
                            406 ;	-----------------------------------------
                            407 ;	 function LCDRC
                            408 ;	-----------------------------------------
   0095                     409 _LCDRC:
                            410 ;	Z:\AESOKZ~C\lcd.c:65: LCDDataPort = 0x0FF;
   0095 75 A0 FF            411 	mov	_P2,#0xFF
                            412 ;	Z:\AESOKZ~C\lcd.c:66: LCDRS=0;
   0098 C2 80               413 	clr	_P0_0
                            414 ;	Z:\AESOKZ~C\lcd.c:67: LCDRW=1;
   009A D2 81               415 	setb	_P0_1
   009C 22                  416 	ret
                            417 ;------------------------------------------------------------
                            418 ;Allocation info for local variables in function 'LCDRD'
                            419 ;------------------------------------------------------------
                            420 ;------------------------------------------------------------
                            421 ;	Z:\AESOKZ~C\lcd.c:70: void LCDRD(void)
                            422 ;	-----------------------------------------
                            423 ;	 function LCDRD
                            424 ;	-----------------------------------------
   009D                     425 _LCDRD:
                            426 ;	Z:\AESOKZ~C\lcd.c:72: LCDDataPort = 0x0FF;
   009D 75 A0 FF            427 	mov	_P2,#0xFF
                            428 ;	Z:\AESOKZ~C\lcd.c:73: LCDRS=1;
   00A0 D2 80               429 	setb	_P0_0
                            430 ;	Z:\AESOKZ~C\lcd.c:74: LCDRW=1;
   00A2 D2 81               431 	setb	_P0_1
   00A4 22                  432 	ret
                            433 ;------------------------------------------------------------
                            434 ;Allocation info for local variables in function 'STROBE'
                            435 ;------------------------------------------------------------
                            436 ;------------------------------------------------------------
                            437 ;	Z:\AESOKZ~C\lcd.c:77: void STROBE(void)
                            438 ;	-----------------------------------------
                            439 ;	 function STROBE
                            440 ;	-----------------------------------------
   00A5                     441 _STROBE:
                            442 ;	Z:\AESOKZ~C\lcd.c:79: LCDE=1;
   00A5 D2 82               443 	setb	_P0_2
                            444 ;	Z:\AESOKZ~C\lcd.c:80: Delay(5);
   00A7 90 00 05            445 	mov	dptr,#0x0005
   00AA 12 00 E3            446 	lcall	_Delay
                            447 ;	Z:\AESOKZ~C\lcd.c:81: LCDE=0;
   00AD C2 82               448 	clr	_P0_2
   00AF 22                  449 	ret
                            450 ;------------------------------------------------------------
                            451 ;Allocation info for local variables in function 'PZNAK'
                            452 ;------------------------------------------------------------
                            453 ;M                         Allocated to registers 
                            454 ;------------------------------------------------------------
                            455 ;	Z:\AESOKZ~C\lcd.c:84: void PZNAK(char M)
                            456 ;	-----------------------------------------
                            457 ;	 function PZNAK
                            458 ;	-----------------------------------------
   00B0                     459 _PZNAK:
   00B0 85 82 A0            460 	mov	_P2,dpl
                            461 ;	Z:\AESOKZ~C\lcd.c:87: LCDWD();
   00B3 12 00 90            462 	lcall	_LCDWD
                            463 ;	Z:\AESOKZ~C\lcd.c:88: STROBE();
   00B6 12 00 A5            464 	lcall	_STROBE
                            465 ;	Z:\AESOKZ~C\lcd.c:89: CZYZAJ();
   00B9 02 00 CD            466 	ljmp	_CZYZAJ
                            467 ;------------------------------------------------------------
                            468 ;Allocation info for local variables in function 'PISZKOM'
                            469 ;------------------------------------------------------------
                            470 ;M                         Allocated to registers r2 
                            471 ;------------------------------------------------------------
                            472 ;	Z:\AESOKZ~C\lcd.c:92: void PISZKOM(char M)
                            473 ;	-----------------------------------------
                            474 ;	 function PISZKOM
                            475 ;	-----------------------------------------
   00BC                     476 _PISZKOM:
   00BC AA 82               477 	mov	r2,dpl
                            478 ;	Z:\AESOKZ~C\lcd.c:94: CZYZAJ();
   00BE C0 02               479 	push	ar2
   00C0 12 00 CD            480 	lcall	_CZYZAJ
                            481 ;	Z:\AESOKZ~C\lcd.c:95: LCDWC();
   00C3 12 00 8B            482 	lcall	_LCDWC
   00C6 D0 02               483 	pop	ar2
                            484 ;	Z:\AESOKZ~C\lcd.c:96: LCDDataPort=M;
   00C8 8A A0               485 	mov	_P2,r2
                            486 ;	Z:\AESOKZ~C\lcd.c:97: STROBE();
   00CA 02 00 A5            487 	ljmp	_STROBE
                            488 ;------------------------------------------------------------
                            489 ;Allocation info for local variables in function 'CZYZAJ'
                            490 ;------------------------------------------------------------
                            491 ;------------------------------------------------------------
                            492 ;	Z:\AESOKZ~C\lcd.c:100: void CZYZAJ(void)
                            493 ;	-----------------------------------------
                            494 ;	 function CZYZAJ
                            495 ;	-----------------------------------------
   00CD                     496 _CZYZAJ:
                            497 ;	Z:\AESOKZ~C\lcd.c:102: LCDDataPort=LCDDataPort;
   00CD 85 A0 A0            498 	mov	_P2,_P2
                            499 ;	Z:\AESOKZ~C\lcd.c:103: LCDRW=1;
   00D0 D2 81               500 	setb	_P0_1
                            501 ;	Z:\AESOKZ~C\lcd.c:104: LCDRS=0;
   00D2 C2 80               502 	clr	_P0_0
                            503 ;	Z:\AESOKZ~C\lcd.c:105: if(LCDDataPort>127)
   00D4 74 7F               504 	mov	a,#0x7F
   00D6 B5 A0 00            505 	cjne	a,_P2,00106$
   00D9                     506 00106$:
   00D9 50 07               507 	jnc	00103$
                            508 ;	Z:\AESOKZ~C\lcd.c:107: LCDE=1;
   00DB D2 82               509 	setb	_P0_2
                            510 ;	Z:\AESOKZ~C\lcd.c:108: LCDDataPort=LCDDataPort;
   00DD 85 A0 A0            511 	mov	_P2,_P2
                            512 ;	Z:\AESOKZ~C\lcd.c:109: LCDE=0;
   00E0 C2 82               513 	clr	_P0_2
   00E2                     514 00103$:
   00E2 22                  515 	ret
                            516 ;------------------------------------------------------------
                            517 ;Allocation info for local variables in function 'Delay'
                            518 ;------------------------------------------------------------
                            519 ;X                         Allocated to registers 
                            520 ;------------------------------------------------------------
                            521 ;	Z:\AESOKZ~C\lcd.c:113: void Delay(int X)
                            522 ;	-----------------------------------------
                            523 ;	 function Delay
                            524 ;	-----------------------------------------
   00E3                     525 _Delay:
   00E3 AA 82               526 	mov	r2,dpl
   00E5 AB 83               527 	mov	r3,dph
                            528 ;	Z:\AESOKZ~C\lcd.c:115: y=1;
   00E7 75 0A 01            529 	mov	_y,#0x01
   00EA 75 0B 00            530 	mov	(_y + 1),#0x00
                            531 ;	Z:\AESOKZ~C\lcd.c:116: if(y<X)
   00ED C3                  532 	clr	c
   00EE 74 01               533 	mov	a,#0x01
   00F0 9A                  534 	subb	a,r2
   00F1 E4                  535 	clr	a
   00F2 9B                  536 	subb	a,r3
   00F3 50 06               537 	jnc	00103$
                            538 ;	Z:\AESOKZ~C\lcd.c:118: y++;
   00F5 75 0A 02            539 	mov	_y,#0x02
   00F8 75 0B 00            540 	mov	(_y + 1),#0x00
   00FB                     541 00103$:
   00FB 22                  542 	ret
                            543 ;------------------------------------------------------------
                            544 ;Allocation info for local variables in function 'GoToXY'
                            545 ;------------------------------------------------------------
                            546 ;col                       Allocated to stack - offset -3
                            547 ;row                       Allocated to registers r2 
                            548 ;------------------------------------------------------------
                            549 ;	Z:\AESOKZ~C\lcd.c:122: void GoToXY(char row, char col)
                            550 ;	-----------------------------------------
                            551 ;	 function GoToXY
                            552 ;	-----------------------------------------
   00FC                     553 _GoToXY:
   00FC C0 0D               554 	push	_bp
   00FE 85 81 0D            555 	mov	_bp,sp
   0101 AA 82               556 	mov	r2,dpl
                            557 ;	Z:\AESOKZ~C\lcd.c:124: if(row>0)
   0103 C3                  558 	clr	c
   0104 74 80               559 	mov	a,#(0x00 ^ 0x80)
   0106 8A F0               560 	mov	b,r2
   0108 63 F0 80            561 	xrl	b,#0x80
   010B 95 F0               562 	subb	a,b
   010D 50 0F               563 	jnc	00102$
                            564 ;	Z:\AESOKZ~C\lcd.c:126: PISZKOM(0x0c0+col);
   010F E5 0D               565 	mov	a,_bp
   0111 24 FD               566 	add	a,#0xfd
   0113 F8                  567 	mov	r0,a
   0114 74 C0               568 	mov	a,#0xC0
   0116 26                  569 	add	a,@r0
   0117 F5 82               570 	mov	dpl,a
   0119 12 00 BC            571 	lcall	_PISZKOM
   011C 80 0D               572 	sjmp	00104$
   011E                     573 00102$:
                            574 ;	Z:\AESOKZ~C\lcd.c:130: PISZKOM(0x80+col);
   011E E5 0D               575 	mov	a,_bp
   0120 24 FD               576 	add	a,#0xfd
   0122 F8                  577 	mov	r0,a
   0123 74 80               578 	mov	a,#0x80
   0125 26                  579 	add	a,@r0
   0126 F5 82               580 	mov	dpl,a
   0128 12 00 BC            581 	lcall	_PISZKOM
   012B                     582 00104$:
   012B D0 0D               583 	pop	_bp
   012D 22                  584 	ret
                            585 ;------------------------------------------------------------
                            586 ;Allocation info for local variables in function 'LicznikLCD'
                            587 ;------------------------------------------------------------
                            588 ;y                         Allocated to stack - offset -3
                            589 ;liczba                    Allocated to stack - offset -5
                            590 ;x                         Allocated to registers r2 
                            591 ;------------------------------------------------------------
                            592 ;	Z:\AESOKZ~C\lcd.c:134: void LicznikLCD(char x, char y, unsigned int liczba)
                            593 ;	-----------------------------------------
                            594 ;	 function LicznikLCD
                            595 ;	-----------------------------------------
   012E                     596 _LicznikLCD:
   012E C0 0D               597 	push	_bp
   0130 85 81 0D            598 	mov	_bp,sp
   0133 AA 82               599 	mov	r2,dpl
                            600 ;	Z:\AESOKZ~C\lcd.c:136: i=1;
   0135 75 08 01            601 	mov	_i,#0x01
   0138 75 09 00            602 	mov	(_i + 1),#0x00
                            603 ;	Z:\AESOKZ~C\lcd.c:137: if(i<liczba)
   013B E5 0D               604 	mov	a,_bp
   013D 24 FB               605 	add	a,#0xfb
   013F F8                  606 	mov	r0,a
   0140 C3                  607 	clr	c
   0141 74 01               608 	mov	a,#0x01
   0143 96                  609 	subb	a,@r0
   0144 E4                  610 	clr	a
   0145 08                  611 	inc	r0
   0146 96                  612 	subb	a,@r0
   0147 50 26               613 	jnc	00103$
                            614 ;	Z:\AESOKZ~C\lcd.c:139: GoToXY(x,y);
   0149 E5 0D               615 	mov	a,_bp
   014B 24 FD               616 	add	a,#0xfd
   014D F8                  617 	mov	r0,a
   014E E6                  618 	mov	a,@r0
   014F C0 E0               619 	push	acc
   0151 8A 82               620 	mov	dpl,r2
   0153 12 00 FC            621 	lcall	_GoToXY
   0156 15 81               622 	dec	sp
                            623 ;	Z:\AESOKZ~C\lcd.c:140: NumLCD(i);
   0158 85 08 82            624 	mov	dpl,_i
   015B 85 09 83            625 	mov	dph,(_i + 1)
   015E 12 01 A7            626 	lcall	_NumLCD
                            627 ;	Z:\AESOKZ~C\lcd.c:141: Delay(5);
   0161 90 00 05            628 	mov	dptr,#0x0005
   0164 12 00 E3            629 	lcall	_Delay
                            630 ;	Z:\AESOKZ~C\lcd.c:142: i++;
   0167 05 08               631 	inc	_i
   0169 E4                  632 	clr	a
   016A B5 08 02            633 	cjne	a,_i,00107$
   016D 05 09               634 	inc	(_i + 1)
   016F                     635 00107$:
   016F                     636 00103$:
   016F D0 0D               637 	pop	_bp
   0171 22                  638 	ret
                            639 ;------------------------------------------------------------
                            640 ;Allocation info for local variables in function 'StringLCD'
                            641 ;------------------------------------------------------------
                            642 ;s                         Allocated to registers r2 r3 r4 
                            643 ;i                         Allocated to registers 
                            644 ;l                         Allocated to stack - offset 1
                            645 ;------------------------------------------------------------
                            646 ;	Z:\AESOKZ~C\lcd.c:146: void StringLCD(unsigned char *s)
                            647 ;	-----------------------------------------
                            648 ;	 function StringLCD
                            649 ;	-----------------------------------------
   0172                     650 _StringLCD:
   0172 C0 0D               651 	push	_bp
   0174 85 81 0D            652 	mov	_bp,sp
   0177 05 81               653 	inc	sp
                            654 ;	Z:\AESOKZ~C\lcd.c:149: i=strlen(s);
   0179 AA 82               655 	mov	r2,dpl
   017B AB 83               656 	mov	r3,dph
   017D AC F0               657 	mov	r4,b
   017F C0 02               658 	push	ar2
   0181 C0 03               659 	push	ar3
   0183 C0 04               660 	push	ar4
   0185 12 04 55            661 	lcall	_strlen
   0188 D0 04               662 	pop	ar4
   018A D0 03               663 	pop	ar3
   018C D0 02               664 	pop	ar2
                            665 ;	Z:\AESOKZ~C\lcd.c:151: if(i<l)
   018E A8 0D               666 	mov	r0,_bp
   0190 08                  667 	inc	r0
   0191 E6                  668 	mov	a,@r0
   0192 24 FF               669 	add	a,#0xff - 0x00
   0194 50 0B               670 	jnc	00103$
                            671 ;	Z:\AESOKZ~C\lcd.c:153: PZNAK((char)s);
   0196 8A 82               672 	mov	dpl,r2
   0198 12 00 B0            673 	lcall	_PZNAK
                            674 ;	Z:\AESOKZ~C\lcd.c:154: Delay(100);
   019B 90 00 64            675 	mov	dptr,#0x0064
   019E 12 00 E3            676 	lcall	_Delay
                            677 ;	Z:\AESOKZ~C\lcd.c:156: i++;
   01A1                     678 00103$:
   01A1 85 0D 81            679 	mov	sp,_bp
   01A4 D0 0D               680 	pop	_bp
   01A6 22                  681 	ret
                            682 ;------------------------------------------------------------
                            683 ;Allocation info for local variables in function 'NumLCD'
                            684 ;------------------------------------------------------------
                            685 ;liczba                    Allocated to registers r2 r3 
                            686 ;dtys                      Allocated to registers r4 
                            687 ;tysiace                   Allocated to registers r5 
                            688 ;setki                     Allocated to registers r6 
                            689 ;dziesiatki                Allocated to stack - offset 1
                            690 ;jednosci                  Allocated to registers r2 
                            691 ;temp                      Allocated to registers r2 r3 
                            692 ;------------------------------------------------------------
                            693 ;	Z:\AESOKZ~C\lcd.c:160: void NumLCD(unsigned int liczba)
                            694 ;	-----------------------------------------
                            695 ;	 function NumLCD
                            696 ;	-----------------------------------------
   01A7                     697 _NumLCD:
   01A7 C0 0D               698 	push	_bp
   01A9 85 81 0D            699 	mov	_bp,sp
   01AC 05 81               700 	inc	sp
   01AE AA 82               701 	mov	r2,dpl
   01B0 AB 83               702 	mov	r3,dph
                            703 ;	Z:\AESOKZ~C\lcd.c:164: dtys=liczba/10000;
   01B2 C0 02               704 	push	ar2
   01B4 C0 03               705 	push	ar3
   01B6 74 10               706 	mov	a,#0x10
   01B8 C0 E0               707 	push	acc
   01BA 74 27               708 	mov	a,#0x27
   01BC C0 E0               709 	push	acc
   01BE 8A 82               710 	mov	dpl,r2
   01C0 8B 83               711 	mov	dph,r3
   01C2 12 03 5E            712 	lcall	__divuint
   01C5 AC 82               713 	mov	r4,dpl
   01C7 AD 83               714 	mov	r5,dph
   01C9 15 81               715 	dec	sp
   01CB 15 81               716 	dec	sp
   01CD D0 03               717 	pop	ar3
   01CF D0 02               718 	pop	ar2
                            719 ;	Z:\AESOKZ~C\lcd.c:165: if(dtys==0)
   01D1 EC                  720 	mov	a,r4
   01D2 70 14               721 	jnz	00102$
                            722 ;	Z:\AESOKZ~C\lcd.c:167: PZNAK(0x20);
   01D4 75 82 20            723 	mov	dpl,#0x20
   01D7 C0 02               724 	push	ar2
   01D9 C0 03               725 	push	ar3
   01DB C0 04               726 	push	ar4
   01DD 12 00 B0            727 	lcall	_PZNAK
   01E0 D0 04               728 	pop	ar4
   01E2 D0 03               729 	pop	ar3
   01E4 D0 02               730 	pop	ar2
   01E6 80 14               731 	sjmp	00103$
   01E8                     732 00102$:
                            733 ;	Z:\AESOKZ~C\lcd.c:171: PZNAK(dtys+0x30);
   01E8 74 30               734 	mov	a,#0x30
   01EA 2C                  735 	add	a,r4
   01EB F5 82               736 	mov	dpl,a
   01ED C0 02               737 	push	ar2
   01EF C0 03               738 	push	ar3
   01F1 C0 04               739 	push	ar4
   01F3 12 00 B0            740 	lcall	_PZNAK
   01F6 D0 04               741 	pop	ar4
   01F8 D0 03               742 	pop	ar3
   01FA D0 02               743 	pop	ar2
   01FC                     744 00103$:
                            745 ;	Z:\AESOKZ~C\lcd.c:173: temp=liczba%100000;
   01FC 7D 00               746 	mov	r5,#0x00
   01FE 7E 00               747 	mov	r6,#0x00
   0200 C0 04               748 	push	ar4
   0202 74 A0               749 	mov	a,#0xA0
   0204 C0 E0               750 	push	acc
   0206 74 86               751 	mov	a,#0x86
   0208 C0 E0               752 	push	acc
   020A 74 01               753 	mov	a,#0x01
   020C C0 E0               754 	push	acc
   020E E4                  755 	clr	a
   020F C0 E0               756 	push	acc
   0211 8A 82               757 	mov	dpl,r2
   0213 8B 83               758 	mov	dph,r3
   0215 8D F0               759 	mov	b,r5
   0217 EE                  760 	mov	a,r6
   0218 12 03 8F            761 	lcall	__modslong
   021B AA 82               762 	mov	r2,dpl
   021D AB 83               763 	mov	r3,dph
   021F E5 81               764 	mov	a,sp
   0221 24 FC               765 	add	a,#0xfc
   0223 F5 81               766 	mov	sp,a
   0225 D0 04               767 	pop	ar4
                            768 ;	Z:\AESOKZ~C\lcd.c:174: tysiace=temp/1000;
   0227 C0 02               769 	push	ar2
   0229 C0 03               770 	push	ar3
   022B C0 04               771 	push	ar4
   022D 74 E8               772 	mov	a,#0xE8
   022F C0 E0               773 	push	acc
   0231 74 03               774 	mov	a,#0x03
   0233 C0 E0               775 	push	acc
   0235 8A 82               776 	mov	dpl,r2
   0237 8B 83               777 	mov	dph,r3
   0239 12 03 5E            778 	lcall	__divuint
   023C AD 82               779 	mov	r5,dpl
   023E AE 83               780 	mov	r6,dph
   0240 15 81               781 	dec	sp
   0242 15 81               782 	dec	sp
   0244 D0 04               783 	pop	ar4
   0246 D0 03               784 	pop	ar3
   0248 D0 02               785 	pop	ar2
                            786 ;	Z:\AESOKZ~C\lcd.c:175: if(tysiace==0&&dtys==0)
   024A ED                  787 	mov	a,r5
   024B 70 1B               788 	jnz	00105$
   024D EC                  789 	mov	a,r4
   024E 70 18               790 	jnz	00105$
                            791 ;	Z:\AESOKZ~C\lcd.c:177: PZNAK(0x20);
   0250 75 82 20            792 	mov	dpl,#0x20
   0253 C0 02               793 	push	ar2
   0255 C0 03               794 	push	ar3
   0257 C0 04               795 	push	ar4
   0259 C0 05               796 	push	ar5
   025B 12 00 B0            797 	lcall	_PZNAK
   025E D0 05               798 	pop	ar5
   0260 D0 04               799 	pop	ar4
   0262 D0 03               800 	pop	ar3
   0264 D0 02               801 	pop	ar2
   0266 80 18               802 	sjmp	00106$
   0268                     803 00105$:
                            804 ;	Z:\AESOKZ~C\lcd.c:181: PZNAK(tysiace+0x30);
   0268 74 30               805 	mov	a,#0x30
   026A 2D                  806 	add	a,r5
   026B F5 82               807 	mov	dpl,a
   026D C0 02               808 	push	ar2
   026F C0 03               809 	push	ar3
   0271 C0 04               810 	push	ar4
   0273 C0 05               811 	push	ar5
   0275 12 00 B0            812 	lcall	_PZNAK
   0278 D0 05               813 	pop	ar5
   027A D0 04               814 	pop	ar4
   027C D0 03               815 	pop	ar3
   027E D0 02               816 	pop	ar2
   0280                     817 00106$:
                            818 ;	Z:\AESOKZ~C\lcd.c:183: temp=temp%1000;
   0280 C0 04               819 	push	ar4
   0282 C0 05               820 	push	ar5
   0284 74 E8               821 	mov	a,#0xE8
   0286 C0 E0               822 	push	acc
   0288 74 03               823 	mov	a,#0x03
   028A C0 E0               824 	push	acc
   028C 8A 82               825 	mov	dpl,r2
   028E 8B 83               826 	mov	dph,r3
   0290 12 04 89            827 	lcall	__moduint
   0293 AE 82               828 	mov	r6,dpl
   0295 AF 83               829 	mov	r7,dph
   0297 15 81               830 	dec	sp
   0299 15 81               831 	dec	sp
   029B D0 05               832 	pop	ar5
   029D D0 04               833 	pop	ar4
   029F 8E 02               834 	mov	ar2,r6
   02A1 8F 03               835 	mov	ar3,r7
                            836 ;	Z:\AESOKZ~C\lcd.c:184: setki=temp/100;
   02A3 C0 02               837 	push	ar2
   02A5 C0 03               838 	push	ar3
   02A7 C0 04               839 	push	ar4
   02A9 C0 05               840 	push	ar5
   02AB 74 64               841 	mov	a,#0x64
   02AD C0 E0               842 	push	acc
   02AF E4                  843 	clr	a
   02B0 C0 E0               844 	push	acc
   02B2 8A 82               845 	mov	dpl,r2
   02B4 8B 83               846 	mov	dph,r3
   02B6 12 03 5E            847 	lcall	__divuint
   02B9 AE 82               848 	mov	r6,dpl
   02BB AF 83               849 	mov	r7,dph
   02BD 15 81               850 	dec	sp
   02BF 15 81               851 	dec	sp
   02C1 D0 05               852 	pop	ar5
   02C3 D0 04               853 	pop	ar4
   02C5 D0 03               854 	pop	ar3
   02C7 D0 02               855 	pop	ar2
                            856 ;	Z:\AESOKZ~C\lcd.c:185: if(setki==0&&tysiace==0&&dtys==0)
   02C9 EE                  857 	mov	a,r6
   02CA 70 16               858 	jnz	00109$
   02CC ED                  859 	mov	a,r5
   02CD 70 13               860 	jnz	00109$
   02CF EC                  861 	mov	a,r4
   02D0 70 10               862 	jnz	00109$
                            863 ;	Z:\AESOKZ~C\lcd.c:187: PZNAK(0x20);
   02D2 75 82 20            864 	mov	dpl,#0x20
   02D5 C0 02               865 	push	ar2
   02D7 C0 03               866 	push	ar3
   02D9 12 00 B0            867 	lcall	_PZNAK
   02DC D0 03               868 	pop	ar3
   02DE D0 02               869 	pop	ar2
   02E0 80 13               870 	sjmp	00110$
   02E2                     871 00109$:
                            872 ;	Z:\AESOKZ~C\lcd.c:191: PZNAK(dziesiatki+0x30);
   02E2 A8 0D               873 	mov	r0,_bp
   02E4 08                  874 	inc	r0
   02E5 74 30               875 	mov	a,#0x30
   02E7 26                  876 	add	a,@r0
   02E8 F5 82               877 	mov	dpl,a
   02EA C0 02               878 	push	ar2
   02EC C0 03               879 	push	ar3
   02EE 12 00 B0            880 	lcall	_PZNAK
   02F1 D0 03               881 	pop	ar3
   02F3 D0 02               882 	pop	ar2
   02F5                     883 00110$:
                            884 ;	Z:\AESOKZ~C\lcd.c:193: temp=temp%10;
   02F5 74 0A               885 	mov	a,#0x0A
   02F7 C0 E0               886 	push	acc
   02F9 E4                  887 	clr	a
   02FA C0 E0               888 	push	acc
   02FC 8A 82               889 	mov	dpl,r2
   02FE 8B 83               890 	mov	dph,r3
   0300 12 04 89            891 	lcall	__moduint
   0303 AC 82               892 	mov	r4,dpl
   0305 AD 83               893 	mov	r5,dph
   0307 15 81               894 	dec	sp
   0309 15 81               895 	dec	sp
   030B 8C 02               896 	mov	ar2,r4
   030D 8D 03               897 	mov	ar3,r5
                            898 ;	Z:\AESOKZ~C\lcd.c:194: jednosci=temp;
                            899 ;	Z:\AESOKZ~C\lcd.c:195: PZNAK(jednosci+0x30);
   030F 74 30               900 	mov	a,#0x30
   0311 2A                  901 	add	a,r2
   0312 F5 82               902 	mov	dpl,a
   0314 12 00 B0            903 	lcall	_PZNAK
   0317 85 0D 81            904 	mov	sp,_bp
   031A D0 0D               905 	pop	_bp
   031C 22                  906 	ret
                            907 ;------------------------------------------------------------
                            908 ;Allocation info for local variables in function 'main'
                            909 ;------------------------------------------------------------
                            910 ;------------------------------------------------------------
                            911 ;	Z:\AESOKZ~C\lcd.c:199: void main(void)
                            912 ;	-----------------------------------------
                            913 ;	 function main
                            914 ;	-----------------------------------------
   031D                     915 _main:
                            916 ;	Z:\AESOKZ~C\lcd.c:201: INITLCD();
   031D 12 00 00            917 	lcall	_INITLCD
                            918 ;	Z:\AESOKZ~C\lcd.c:202: GoToXY(0,1);
   0320 74 01               919 	mov	a,#0x01
   0322 C0 E0               920 	push	acc
   0324 75 82 00            921 	mov	dpl,#0x00
   0327 12 00 FC            922 	lcall	_GoToXY
   032A 15 81               923 	dec	sp
                            924 ;	Z:\AESOKZ~C\lcd.c:203: PZNAK(0x4D);
   032C 75 82 4D            925 	mov	dpl,#0x4D
   032F 12 00 B0            926 	lcall	_PZNAK
                            927 ;	Z:\AESOKZ~C\lcd.c:204: GoToXY(1,1);
   0332 74 01               928 	mov	a,#0x01
   0334 C0 E0               929 	push	acc
   0336 75 82 01            930 	mov	dpl,#0x01
   0339 12 00 FC            931 	lcall	_GoToXY
   033C 15 81               932 	dec	sp
                            933 ;	Z:\AESOKZ~C\lcd.c:205: StringLCD('Napis');
   033E 90 00 4E            934 	mov	dptr,#0x004E
   0341 75 F0 00            935 	mov	b,#0x00
   0344 12 01 72            936 	lcall	_StringLCD
                            937 ;	Z:\AESOKZ~C\lcd.c:206: LicznikLCD(1,8,65535);
   0347 74 FF               938 	mov	a,#0xFF
   0349 C0 E0               939 	push	acc
   034B C0 E0               940 	push	acc
   034D 74 08               941 	mov	a,#0x08
   034F C0 E0               942 	push	acc
   0351 75 82 01            943 	mov	dpl,#0x01
   0354 12 01 2E            944 	lcall	_LicznikLCD
   0357 15 81               945 	dec	sp
   0359 15 81               946 	dec	sp
   035B 15 81               947 	dec	sp
   035D 22                  948 	ret
                            949 	.area CSEG    (CODE)
                            950 	.area CONST   (CODE)
                            951 	.area XINIT   (CODE)
                            952 	.area CABS    (ABS,CODE)

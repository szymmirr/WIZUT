                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
                              4 ; This file was generated Wed Jun 07 11:34:55 2017
                              5 ;--------------------------------------------------------
                              6 	.module silnik
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _Delay
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
                            110 	.globl _rozm
                            111 	.globl _lobrotow
                            112 	.globl _liczba
                            113 	.globl _a
                            114 	.globl _i
                            115 	.globl _TablSiln
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
                            227 ;--------------------------------------------------------
                            228 ; internal ram data
                            229 ;--------------------------------------------------------
                            230 	.area DSEG    (DATA)
   0008                     231 _TablSiln::
   0008                     232 	.ds 4
   000C                     233 _i::
   000C                     234 	.ds 1
   000D                     235 _a::
   000D                     236 	.ds 2
   000F                     237 _liczba::
   000F                     238 	.ds 2
   0011                     239 _lobrotow::
   0011                     240 	.ds 2
   0013                     241 _rozm::
   0013                     242 	.ds 1
                            243 ;--------------------------------------------------------
                            244 ; overlayable items in internal ram 
                            245 ;--------------------------------------------------------
                            246 	.area OSEG    (OVR,DATA)
                            247 ;--------------------------------------------------------
                            248 ; Stack segment in internal ram 
                            249 ;--------------------------------------------------------
                            250 	.area	SSEG	(DATA)
   0014                     251 __start__stack:
   0014                     252 	.ds	1
                            253 
                            254 ;--------------------------------------------------------
                            255 ; indirectly addressable internal ram data
                            256 ;--------------------------------------------------------
                            257 	.area ISEG    (DATA)
                            258 ;--------------------------------------------------------
                            259 ; absolute internal ram data
                            260 ;--------------------------------------------------------
                            261 	.area IABS    (ABS,DATA)
                            262 	.area IABS    (ABS,DATA)
                            263 ;--------------------------------------------------------
                            264 ; bit data
                            265 ;--------------------------------------------------------
                            266 	.area BSEG    (BIT)
                            267 ;--------------------------------------------------------
                            268 ; paged external ram data
                            269 ;--------------------------------------------------------
                            270 	.area PSEG    (PAG,XDATA)
                            271 ;--------------------------------------------------------
                            272 ; external ram data
                            273 ;--------------------------------------------------------
                            274 	.area XSEG    (XDATA)
                            275 ;--------------------------------------------------------
                            276 ; absolute external ram data
                            277 ;--------------------------------------------------------
                            278 	.area XABS    (ABS,XDATA)
                            279 ;--------------------------------------------------------
                            280 ; external initialized ram data
                            281 ;--------------------------------------------------------
                            282 	.area XISEG   (XDATA)
                            283 	.area HOME    (CODE)
                            284 	.area GSINIT0 (CODE)
                            285 	.area GSINIT1 (CODE)
                            286 	.area GSINIT2 (CODE)
                            287 	.area GSINIT3 (CODE)
                            288 	.area GSINIT4 (CODE)
                            289 	.area GSINIT5 (CODE)
                            290 	.area GSINIT  (CODE)
                            291 	.area GSFINAL (CODE)
                            292 	.area CSEG    (CODE)
                            293 ;--------------------------------------------------------
                            294 ; interrupt vector 
                            295 ;--------------------------------------------------------
                            296 	.area HOME    (CODE)
   0000                     297 __interrupt_vect:
   0000 02 00 08            298 	ljmp	__sdcc_gsinit_startup
                            299 ;--------------------------------------------------------
                            300 ; global & static initialisations
                            301 ;--------------------------------------------------------
                            302 	.area HOME    (CODE)
                            303 	.area GSINIT  (CODE)
                            304 	.area GSFINAL (CODE)
                            305 	.area GSINIT  (CODE)
                            306 	.globl __sdcc_gsinit_startup
                            307 	.globl __sdcc_program_startup
                            308 	.globl __start__stack
                            309 	.globl __mcs51_genXINIT
                            310 	.globl __mcs51_genXRAMCLEAR
                            311 	.globl __mcs51_genRAMCLEAR
                            312 ;	Z:\AESOKZ~C\silnik.c:5: unsigned char TablSiln[]={3,6,12,9};//krokowy
   0061 75 08 03            313 	mov	_TablSiln,#0x03
   0064 75 09 06            314 	mov	(_TablSiln + 0x0001),#0x06
   0067 75 0A 0C            315 	mov	(_TablSiln + 0x0002),#0x0C
   006A 75 0B 09            316 	mov	(_TablSiln + 0x0003),#0x09
                            317 ;	Z:\AESOKZ~C\silnik.c:8: unsigned int a =0;
   006D E4                  318 	clr	a
   006E F5 0D               319 	mov	_a,a
   0070 F5 0E               320 	mov	(_a + 1),a
                            321 ;	Z:\AESOKZ~C\silnik.c:9: int liczba =1;
   0072 75 0F 01            322 	mov	_liczba,#0x01
   0075 75 10 00            323 	mov	(_liczba + 1),#0x00
                            324 ;	Z:\AESOKZ~C\silnik.c:10: int lobrotow =1;
   0078 75 11 01            325 	mov	_lobrotow,#0x01
   007B 75 12 00            326 	mov	(_lobrotow + 1),#0x00
                            327 ;	Z:\AESOKZ~C\silnik.c:11: char rozm=0;//rozmiar TablSiln
   007E 75 13 00            328 	mov	_rozm,#0x00
                            329 	.area GSFINAL (CODE)
   0081 02 00 03            330 	ljmp	__sdcc_program_startup
                            331 ;--------------------------------------------------------
                            332 ; Home
                            333 ;--------------------------------------------------------
                            334 	.area HOME    (CODE)
                            335 	.area HOME    (CODE)
   0003                     336 __sdcc_program_startup:
   0003 12 00 A1            337 	lcall	_main
                            338 ;	return from main will lock up
   0006 80 FE               339 	sjmp .
                            340 ;--------------------------------------------------------
                            341 ; code
                            342 ;--------------------------------------------------------
                            343 	.area CSEG    (CODE)
                            344 ;------------------------------------------------------------
                            345 ;Allocation info for local variables in function 'Delay'
                            346 ;------------------------------------------------------------
                            347 ;Ile                       Allocated to registers r2 r3 
                            348 ;------------------------------------------------------------
                            349 ;	Z:\AESOKZ~C\silnik.c:12: void Delay(int Ile)
                            350 ;	-----------------------------------------
                            351 ;	 function Delay
                            352 ;	-----------------------------------------
   0084                     353 _Delay:
                    0002    354 	ar2 = 0x02
                    0003    355 	ar3 = 0x03
                    0004    356 	ar4 = 0x04
                    0005    357 	ar5 = 0x05
                    0006    358 	ar6 = 0x06
                    0007    359 	ar7 = 0x07
                    0000    360 	ar0 = 0x00
                    0001    361 	ar1 = 0x01
   0084 AA 82               362 	mov	r2,dpl
   0086 AB 83               363 	mov	r3,dph
                            364 ;	Z:\AESOKZ~C\silnik.c:14: for(a =0;a <Ile;++a);//opoznienie pomiedzy krokami
   0088 E4                  365 	clr	a
   0089 F5 0D               366 	mov	_a,a
   008B F5 0E               367 	mov	(_a + 1),a
   008D                     368 00101$:
   008D C3                  369 	clr	c
   008E E5 0D               370 	mov	a,_a
   0090 9A                  371 	subb	a,r2
   0091 E5 0E               372 	mov	a,(_a + 1)
   0093 9B                  373 	subb	a,r3
   0094 50 0A               374 	jnc	00105$
   0096 05 0D               375 	inc	_a
   0098 E4                  376 	clr	a
   0099 B5 0D F1            377 	cjne	a,_a,00101$
   009C 05 0E               378 	inc	(_a + 1)
   009E 80 ED               379 	sjmp	00101$
   00A0                     380 00105$:
   00A0 22                  381 	ret
                            382 ;------------------------------------------------------------
                            383 ;Allocation info for local variables in function 'main'
                            384 ;------------------------------------------------------------
                            385 ;------------------------------------------------------------
                            386 ;	Z:\AESOKZ~C\silnik.c:16: int main(void)
                            387 ;	-----------------------------------------
                            388 ;	 function main
                            389 ;	-----------------------------------------
   00A1                     390 _main:
                            391 ;	Z:\AESOKZ~C\silnik.c:18: rozm=sizeof(TablSiln);//rozmiar tablicy 
   00A1 75 13 04            392 	mov	_rozm,#0x04
                            393 ;	Z:\AESOKZ~C\silnik.c:20: P2=rozm;//wyswietl;
   00A4 75 A0 04            394 	mov	_P2,#0x04
                            395 ;	Z:\AESOKZ~C\silnik.c:21: while(1)
   00A7                     396 00102$:
                            397 ;	Z:\AESOKZ~C\silnik.c:24: for(i =rozm-1;i >=0;i--)//wykonaj sekwencje (PRAWO)
   00A7 E5 13               398 	mov	a,_rozm
   00A9 14                  399 	dec	a
   00AA F5 0C               400 	mov	_i,a
   00AC                     401 00107$:
   00AC E5 0C               402 	mov	a,_i
   00AE 20 E7 26            403 	jb	acc.7,00110$
                            404 ;	Z:\AESOKZ~C\silnik.c:26: for(a =0;a <500;++a);
   00B1 75 0D F4            405 	mov	_a,#0xF4
   00B4 75 0E 01            406 	mov	(_a + 1),#0x01
   00B7                     407 00106$:
   00B7 15 0D               408 	dec	_a
   00B9 74 FF               409 	mov	a,#0xff
   00BB B5 0D 02            410 	cjne	a,_a,00119$
   00BE 15 0E               411 	dec	(_a + 1)
   00C0                     412 00119$:
   00C0 E5 0D               413 	mov	a,_a
   00C2 45 0E               414 	orl	a,(_a + 1)
   00C4 70 F1               415 	jnz	00106$
                            416 ;	Z:\AESOKZ~C\silnik.c:27: P0 =TablSiln[i];
   00C6 E5 0C               417 	mov	a,_i
   00C8 24 08               418 	add	a,#_TablSiln
   00CA F8                  419 	mov	r0,a
   00CB 86 80               420 	mov	_P0,@r0
                            421 ;	Z:\AESOKZ~C\silnik.c:28: a++;
   00CD 75 0D F5            422 	mov	_a,#0xF5
   00D0 75 0E 01            423 	mov	(_a + 1),#0x01
                            424 ;	Z:\AESOKZ~C\silnik.c:24: for(i =rozm-1;i >=0;i--)//wykonaj sekwencje (PRAWO)
   00D3 15 0C               425 	dec	_i
   00D5 80 D5               426 	sjmp	00107$
   00D7                     427 00110$:
                            428 ;	Z:\AESOKZ~C\silnik.c:30: Delay(100);
   00D7 90 00 64            429 	mov	dptr,#0x0064
   00DA 12 00 84            430 	lcall	_Delay
   00DD 80 C8               431 	sjmp	00102$
                            432 	.area CSEG    (CODE)
                            433 	.area CONST   (CODE)
                            434 	.area XINIT   (CODE)
                            435 	.area CABS    (ABS,CODE)

                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
                              4 ; This file was generated Wed Jun 07 11:31:21 2017
                              5 ;--------------------------------------------------------
                              6 	.module silnik2
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _button1
                             13 	.globl _button0
                             14 	.globl _main
                             15 	.globl _CY
                             16 	.globl _AC
                             17 	.globl _F0
                             18 	.globl _RS1
                             19 	.globl _RS0
                             20 	.globl _OV
                             21 	.globl _F1
                             22 	.globl _P
                             23 	.globl _PS
                             24 	.globl _PT1
                             25 	.globl _PX1
                             26 	.globl _PT0
                             27 	.globl _PX0
                             28 	.globl _RD
                             29 	.globl _WR
                             30 	.globl _T1
                             31 	.globl _T0
                             32 	.globl _INT1
                             33 	.globl _INT0
                             34 	.globl _TXD
                             35 	.globl _RXD
                             36 	.globl _P3_7
                             37 	.globl _P3_6
                             38 	.globl _P3_5
                             39 	.globl _P3_4
                             40 	.globl _P3_3
                             41 	.globl _P3_2
                             42 	.globl _P3_1
                             43 	.globl _P3_0
                             44 	.globl _EA
                             45 	.globl _ES
                             46 	.globl _ET1
                             47 	.globl _EX1
                             48 	.globl _ET0
                             49 	.globl _EX0
                             50 	.globl _P2_7
                             51 	.globl _P2_6
                             52 	.globl _P2_5
                             53 	.globl _P2_4
                             54 	.globl _P2_3
                             55 	.globl _P2_2
                             56 	.globl _P2_1
                             57 	.globl _P2_0
                             58 	.globl _SM0
                             59 	.globl _SM1
                             60 	.globl _SM2
                             61 	.globl _REN
                             62 	.globl _TB8
                             63 	.globl _RB8
                             64 	.globl _TI
                             65 	.globl _RI
                             66 	.globl _P1_7
                             67 	.globl _P1_6
                             68 	.globl _P1_5
                             69 	.globl _P1_4
                             70 	.globl _P1_3
                             71 	.globl _P1_2
                             72 	.globl _P1_1
                             73 	.globl _P1_0
                             74 	.globl _TF1
                             75 	.globl _TR1
                             76 	.globl _TF0
                             77 	.globl _TR0
                             78 	.globl _IE1
                             79 	.globl _IT1
                             80 	.globl _IE0
                             81 	.globl _IT0
                             82 	.globl _P0_7
                             83 	.globl _P0_6
                             84 	.globl _P0_5
                             85 	.globl _P0_4
                             86 	.globl _P0_3
                             87 	.globl _P0_2
                             88 	.globl _P0_1
                             89 	.globl _P0_0
                             90 	.globl _B
                             91 	.globl _ACC
                             92 	.globl _PSW
                             93 	.globl _IP
                             94 	.globl _P3
                             95 	.globl _IE
                             96 	.globl _P2
                             97 	.globl _SBUF
                             98 	.globl _SCON
                             99 	.globl _P1
                            100 	.globl _TH1
                            101 	.globl _TH0
                            102 	.globl _TL1
                            103 	.globl _TL0
                            104 	.globl _TMOD
                            105 	.globl _TCON
                            106 	.globl _PCON
                            107 	.globl _DPH
                            108 	.globl _DPL
                            109 	.globl _SP
                            110 	.globl _P0
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
                            228 ; overlayable bit register bank
                            229 ;--------------------------------------------------------
                            230 	.area BIT_BANK	(REL,OVR,DATA)
   0020                     231 bits:
   0020                     232 	.ds 1
                    8000    233 	b0 = bits[0]
                    8100    234 	b1 = bits[1]
                    8200    235 	b2 = bits[2]
                    8300    236 	b3 = bits[3]
                    8400    237 	b4 = bits[4]
                    8500    238 	b5 = bits[5]
                    8600    239 	b6 = bits[6]
                    8700    240 	b7 = bits[7]
                            241 ;--------------------------------------------------------
                            242 ; internal ram data
                            243 ;--------------------------------------------------------
                            244 	.area DSEG    (DATA)
   0008                     245 _TablSiln::
   0008                     246 	.ds 4
   000C                     247 _i::
   000C                     248 	.ds 1
   000D                     249 _a::
   000D                     250 	.ds 2
   000F                     251 _liczba::
   000F                     252 	.ds 2
   0011                     253 _lobrotow::
   0011                     254 	.ds 2
                            255 ;--------------------------------------------------------
                            256 ; overlayable items in internal ram 
                            257 ;--------------------------------------------------------
                            258 	.area OSEG    (OVR,DATA)
                            259 ;--------------------------------------------------------
                            260 ; Stack segment in internal ram 
                            261 ;--------------------------------------------------------
                            262 	.area	SSEG	(DATA)
   0021                     263 __start__stack:
   0021                     264 	.ds	1
                            265 
                            266 ;--------------------------------------------------------
                            267 ; indirectly addressable internal ram data
                            268 ;--------------------------------------------------------
                            269 	.area ISEG    (DATA)
                            270 ;--------------------------------------------------------
                            271 ; absolute internal ram data
                            272 ;--------------------------------------------------------
                            273 	.area IABS    (ABS,DATA)
                            274 	.area IABS    (ABS,DATA)
                            275 ;--------------------------------------------------------
                            276 ; bit data
                            277 ;--------------------------------------------------------
                            278 	.area BSEG    (BIT)
                            279 ;--------------------------------------------------------
                            280 ; paged external ram data
                            281 ;--------------------------------------------------------
                            282 	.area PSEG    (PAG,XDATA)
                            283 ;--------------------------------------------------------
                            284 ; external ram data
                            285 ;--------------------------------------------------------
                            286 	.area XSEG    (XDATA)
                            287 ;--------------------------------------------------------
                            288 ; absolute external ram data
                            289 ;--------------------------------------------------------
                            290 	.area XABS    (ABS,XDATA)
                            291 ;--------------------------------------------------------
                            292 ; external initialized ram data
                            293 ;--------------------------------------------------------
                            294 	.area XISEG   (XDATA)
                            295 	.area HOME    (CODE)
                            296 	.area GSINIT0 (CODE)
                            297 	.area GSINIT1 (CODE)
                            298 	.area GSINIT2 (CODE)
                            299 	.area GSINIT3 (CODE)
                            300 	.area GSINIT4 (CODE)
                            301 	.area GSINIT5 (CODE)
                            302 	.area GSINIT  (CODE)
                            303 	.area GSFINAL (CODE)
                            304 	.area CSEG    (CODE)
                            305 ;--------------------------------------------------------
                            306 ; interrupt vector 
                            307 ;--------------------------------------------------------
                            308 	.area HOME    (CODE)
   0000                     309 __interrupt_vect:
   0000 02 00 1B            310 	ljmp	__sdcc_gsinit_startup
   0003 02 00 9D            311 	ljmp	_button0
   0006                     312 	.ds	5
   000B 32                  313 	reti
   000C                     314 	.ds	7
   0013 02 01 25            315 	ljmp	_button1
                            316 ;--------------------------------------------------------
                            317 ; global & static initialisations
                            318 ;--------------------------------------------------------
                            319 	.area HOME    (CODE)
                            320 	.area GSINIT  (CODE)
                            321 	.area GSFINAL (CODE)
                            322 	.area GSINIT  (CODE)
                            323 	.globl __sdcc_gsinit_startup
                            324 	.globl __sdcc_program_startup
                            325 	.globl __start__stack
                            326 	.globl __mcs51_genXINIT
                            327 	.globl __mcs51_genXRAMCLEAR
                            328 	.globl __mcs51_genRAMCLEAR
                            329 ;	Z:\AESOKZ~C\silnik2.c:8: unsigned char TablSiln[]={3,6,12,9};//lewo
   0074 75 08 03            330 	mov	_TablSiln,#0x03
   0077 75 09 06            331 	mov	(_TablSiln + 0x0001),#0x06
   007A 75 0A 0C            332 	mov	(_TablSiln + 0x0002),#0x0C
   007D 75 0B 09            333 	mov	(_TablSiln + 0x0003),#0x09
                            334 ;	Z:\AESOKZ~C\silnik2.c:11: unsigned int a =0;
   0080 E4                  335 	clr	a
   0081 F5 0D               336 	mov	_a,a
   0083 F5 0E               337 	mov	(_a + 1),a
                            338 ;	Z:\AESOKZ~C\silnik2.c:12: int liczba =515;
   0085 75 0F 03            339 	mov	_liczba,#0x03
   0088 75 10 02            340 	mov	(_liczba + 1),#0x02
                            341 ;	Z:\AESOKZ~C\silnik2.c:13: int lobrotow =0;
   008B E4                  342 	clr	a
   008C F5 11               343 	mov	_lobrotow,a
   008E F5 12               344 	mov	(_lobrotow + 1),a
                            345 	.area GSFINAL (CODE)
   0090 02 00 16            346 	ljmp	__sdcc_program_startup
                            347 ;--------------------------------------------------------
                            348 ; Home
                            349 ;--------------------------------------------------------
                            350 	.area HOME    (CODE)
                            351 	.area HOME    (CODE)
   0016                     352 __sdcc_program_startup:
   0016 12 00 93            353 	lcall	_main
                            354 ;	return from main will lock up
   0019 80 FE               355 	sjmp .
                            356 ;--------------------------------------------------------
                            357 ; code
                            358 ;--------------------------------------------------------
                            359 	.area CSEG    (CODE)
                            360 ;------------------------------------------------------------
                            361 ;Allocation info for local variables in function 'main'
                            362 ;------------------------------------------------------------
                            363 ;------------------------------------------------------------
                            364 ;	Z:\AESOKZ~C\silnik2.c:14: int main(void)
                            365 ;	-----------------------------------------
                            366 ;	 function main
                            367 ;	-----------------------------------------
   0093                     368 _main:
                    0002    369 	ar2 = 0x02
                    0003    370 	ar3 = 0x03
                    0004    371 	ar4 = 0x04
                    0005    372 	ar5 = 0x05
                    0006    373 	ar6 = 0x06
                    0007    374 	ar7 = 0x07
                    0000    375 	ar0 = 0x00
                    0001    376 	ar1 = 0x01
                            377 ;	Z:\AESOKZ~C\silnik2.c:16: EA =1;
   0093 D2 AF               378 	setb	_EA
                            379 ;	Z:\AESOKZ~C\silnik2.c:17: EX0 =1;
   0095 D2 A8               380 	setb	_EX0
                            381 ;	Z:\AESOKZ~C\silnik2.c:18: EX1 =1;
   0097 D2 AA               382 	setb	_EX1
                            383 ;	Z:\AESOKZ~C\silnik2.c:19: IT1 =1;
   0099 D2 8A               384 	setb	_IT1
                            385 ;	Z:\AESOKZ~C\silnik2.c:20: while(1);
   009B                     386 00102$:
   009B 80 FE               387 	sjmp	00102$
                            388 ;------------------------------------------------------------
                            389 ;Allocation info for local variables in function 'button0'
                            390 ;------------------------------------------------------------
                            391 ;------------------------------------------------------------
                            392 ;	Z:\AESOKZ~C\silnik2.c:22: void button0(void)__interrupt(0)
                            393 ;	-----------------------------------------
                            394 ;	 function button0
                            395 ;	-----------------------------------------
   009D                     396 _button0:
   009D C0 20               397 	push	bits
   009F C0 E0               398 	push	acc
   00A1 C0 F0               399 	push	b
   00A3 C0 82               400 	push	dpl
   00A5 C0 83               401 	push	dph
   00A7 C0 02               402 	push	(0+2)
   00A9 C0 03               403 	push	(0+3)
   00AB C0 04               404 	push	(0+4)
   00AD C0 05               405 	push	(0+5)
   00AF C0 06               406 	push	(0+6)
   00B1 C0 07               407 	push	(0+7)
   00B3 C0 00               408 	push	(0+0)
   00B5 C0 01               409 	push	(0+1)
   00B7 C0 D0               410 	push	psw
   00B9 75 D0 00            411 	mov	psw,#0x00
                            412 ;	Z:\AESOKZ~C\silnik2.c:24: for(a =0;a <10000;++a);
   00BC 75 0D 10            413 	mov	_a,#0x10
   00BF 75 0E 27            414 	mov	(_a + 1),#0x27
   00C2                     415 00103$:
   00C2 15 0D               416 	dec	_a
   00C4 74 FF               417 	mov	a,#0xff
   00C6 B5 0D 02            418 	cjne	a,_a,00113$
   00C9 15 0E               419 	dec	(_a + 1)
   00CB                     420 00113$:
   00CB E5 0D               421 	mov	a,_a
   00CD 45 0E               422 	orl	a,(_a + 1)
   00CF 70 F1               423 	jnz	00103$
                            424 ;	Z:\AESOKZ~C\silnik2.c:25: ++lobrotow;
   00D1 05 11               425 	inc	_lobrotow
   00D3 E4                  426 	clr	a
   00D4 B5 11 02            427 	cjne	a,_lobrotow,00115$
   00D7 05 12               428 	inc	(_lobrotow + 1)
   00D9                     429 00115$:
                            430 ;	Z:\AESOKZ~C\silnik2.c:26: for(a =0;a <10000;++a);
   00D9 75 0D 10            431 	mov	_a,#0x10
   00DC 75 0E 27            432 	mov	(_a + 1),#0x27
   00DF                     433 00106$:
   00DF 15 0D               434 	dec	_a
   00E1 74 FF               435 	mov	a,#0xff
   00E3 B5 0D 02            436 	cjne	a,_a,00116$
   00E6 15 0E               437 	dec	(_a + 1)
   00E8                     438 00116$:
   00E8 E5 0D               439 	mov	a,_a
   00EA 45 0E               440 	orl	a,(_a + 1)
   00EC 70 F1               441 	jnz	00106$
   00EE 75 0D 10            442 	mov	_a,#0x10
   00F1 75 0E 27            443 	mov	(_a + 1),#0x27
                            444 ;	Z:\AESOKZ~C\silnik2.c:27: liczba =lobrotow *krok;
   00F4 C0 11               445 	push	_lobrotow
   00F6 C0 12               446 	push	(_lobrotow + 1)
   00F8 90 02 03            447 	mov	dptr,#0x0203
   00FB 12 01 78            448 	lcall	__mulint
   00FE 85 82 0F            449 	mov	_liczba,dpl
   0101 85 83 10            450 	mov	(_liczba + 1),dph
   0104 15 81               451 	dec	sp
   0106 15 81               452 	dec	sp
   0108 D0 D0               453 	pop	psw
   010A D0 01               454 	pop	(0+1)
   010C D0 00               455 	pop	(0+0)
   010E D0 07               456 	pop	(0+7)
   0110 D0 06               457 	pop	(0+6)
   0112 D0 05               458 	pop	(0+5)
   0114 D0 04               459 	pop	(0+4)
   0116 D0 03               460 	pop	(0+3)
   0118 D0 02               461 	pop	(0+2)
   011A D0 83               462 	pop	dph
   011C D0 82               463 	pop	dpl
   011E D0 F0               464 	pop	b
   0120 D0 E0               465 	pop	acc
   0122 D0 20               466 	pop	bits
   0124 32                  467 	reti
                            468 ;------------------------------------------------------------
                            469 ;Allocation info for local variables in function 'button1'
                            470 ;------------------------------------------------------------
                            471 ;------------------------------------------------------------
                            472 ;	Z:\AESOKZ~C\silnik2.c:29: void button1(void)__interrupt(2)
                            473 ;	-----------------------------------------
                            474 ;	 function button1
                            475 ;	-----------------------------------------
   0125                     476 _button1:
   0125 C0 E0               477 	push	acc
   0127 C0 00               478 	push	ar0
   0129 C0 D0               479 	push	psw
   012B 75 D0 00            480 	mov	psw,#0x00
                            481 ;	Z:\AESOKZ~C\silnik2.c:31: while(liczba)
   012E                     482 00101$:
   012E E5 0F               483 	mov	a,_liczba
   0130 45 10               484 	orl	a,(_liczba + 1)
   0132 60 3D               485 	jz	00111$
                            486 ;	Z:\AESOKZ~C\silnik2.c:33: for(i =0;i <4;++i)
   0134 75 0C 00            487 	mov	_i,#0x00
   0137                     488 00107$:
   0137 C3                  489 	clr	c
   0138 E5 0C               490 	mov	a,_i
   013A 64 80               491 	xrl	a,#0x80
   013C 94 84               492 	subb	a,#0x84
   013E 50 26               493 	jnc	00110$
                            494 ;	Z:\AESOKZ~C\silnik2.c:35: for(a =0;a <500;++a);
   0140 75 0D F4            495 	mov	_a,#0xF4
   0143 75 0E 01            496 	mov	(_a + 1),#0x01
   0146                     497 00106$:
   0146 15 0D               498 	dec	_a
   0148 74 FF               499 	mov	a,#0xff
   014A B5 0D 02            500 	cjne	a,_a,00121$
   014D 15 0E               501 	dec	(_a + 1)
   014F                     502 00121$:
   014F E5 0D               503 	mov	a,_a
   0151 45 0E               504 	orl	a,(_a + 1)
   0153 70 F1               505 	jnz	00106$
   0155 75 0D F4            506 	mov	_a,#0xF4
   0158 75 0E 01            507 	mov	(_a + 1),#0x01
                            508 ;	Z:\AESOKZ~C\silnik2.c:36: P0 =TablSiln[i];
   015B E5 0C               509 	mov	a,_i
   015D 24 08               510 	add	a,#_TablSiln
   015F F8                  511 	mov	r0,a
   0160 86 80               512 	mov	_P0,@r0
                            513 ;	Z:\AESOKZ~C\silnik2.c:33: for(i =0;i <4;++i)
   0162 05 0C               514 	inc	_i
   0164 80 D1               515 	sjmp	00107$
   0166                     516 00110$:
                            517 ;	Z:\AESOKZ~C\silnik2.c:38: liczba--;
   0166 15 0F               518 	dec	_liczba
   0168 74 FF               519 	mov	a,#0xff
   016A B5 0F 02            520 	cjne	a,_liczba,00123$
   016D 15 10               521 	dec	(_liczba + 1)
   016F                     522 00123$:
   016F 80 BD               523 	sjmp	00101$
   0171                     524 00111$:
   0171 D0 D0               525 	pop	psw
   0173 D0 00               526 	pop	ar0
   0175 D0 E0               527 	pop	acc
   0177 32                  528 	reti
                            529 ;	eliminated unneeded push/pop ar1
                            530 ;	eliminated unneeded push/pop dpl
                            531 ;	eliminated unneeded push/pop dph
                            532 ;	eliminated unneeded push/pop b
                            533 	.area CSEG    (CODE)
                            534 	.area CONST   (CODE)
                            535 	.area XINIT   (CODE)
                            536 	.area CABS    (ABS,CODE)

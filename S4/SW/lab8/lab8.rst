                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
                              4 ; This file was generated Fri Apr 28 17:16:45 2017
                              5 ;--------------------------------------------------------
                              6 	.module lab8
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _button6
                             13 	.globl _button5
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
                            225 ;--------------------------------------------------------
                            226 ; internal ram data
                            227 ;--------------------------------------------------------
                            228 	.area DSEG    (DATA)
   0008                     229 _Licznik::
   0008                     230 	.ds 1
   0009                     231 _i::
   0009                     232 	.ds 2
                            233 ;--------------------------------------------------------
                            234 ; overlayable items in internal ram 
                            235 ;--------------------------------------------------------
                            236 	.area OSEG    (OVR,DATA)
                            237 ;--------------------------------------------------------
                            238 ; Stack segment in internal ram 
                            239 ;--------------------------------------------------------
                            240 	.area	SSEG	(DATA)
   000B                     241 __start__stack:
   000B                     242 	.ds	1
                            243 
                            244 ;--------------------------------------------------------
                            245 ; indirectly addressable internal ram data
                            246 ;--------------------------------------------------------
                            247 	.area ISEG    (DATA)
                            248 ;--------------------------------------------------------
                            249 ; absolute internal ram data
                            250 ;--------------------------------------------------------
                            251 	.area IABS    (ABS,DATA)
                            252 	.area IABS    (ABS,DATA)
                            253 ;--------------------------------------------------------
                            254 ; bit data
                            255 ;--------------------------------------------------------
                            256 	.area BSEG    (BIT)
                            257 ;--------------------------------------------------------
                            258 ; paged external ram data
                            259 ;--------------------------------------------------------
                            260 	.area PSEG    (PAG,XDATA)
                            261 ;--------------------------------------------------------
                            262 ; external ram data
                            263 ;--------------------------------------------------------
                            264 	.area XSEG    (XDATA)
                            265 ;--------------------------------------------------------
                            266 ; absolute external ram data
                            267 ;--------------------------------------------------------
                            268 	.area XABS    (ABS,XDATA)
                            269 ;--------------------------------------------------------
                            270 ; external initialized ram data
                            271 ;--------------------------------------------------------
                            272 	.area XISEG   (XDATA)
                            273 	.area HOME    (CODE)
                            274 	.area GSINIT0 (CODE)
                            275 	.area GSINIT1 (CODE)
                            276 	.area GSINIT2 (CODE)
                            277 	.area GSINIT3 (CODE)
                            278 	.area GSINIT4 (CODE)
                            279 	.area GSINIT5 (CODE)
                            280 	.area GSINIT  (CODE)
                            281 	.area GSFINAL (CODE)
                            282 	.area CSEG    (CODE)
                            283 ;--------------------------------------------------------
                            284 ; interrupt vector 
                            285 ;--------------------------------------------------------
                            286 	.area HOME    (CODE)
   0000                     287 __interrupt_vect:
   0000 02 00 1B            288 	ljmp	__sdcc_gsinit_startup
   0003 02 00 E7            289 	ljmp	_button5
   0006                     290 	.ds	5
   000B 02 00 97            291 	ljmp	_timer0
   000E                     292 	.ds	5
   0013 02 00 EB            293 	ljmp	_button6
                            294 ;--------------------------------------------------------
                            295 ; global & static initialisations
                            296 ;--------------------------------------------------------
                            297 	.area HOME    (CODE)
                            298 	.area GSINIT  (CODE)
                            299 	.area GSFINAL (CODE)
                            300 	.area GSINIT  (CODE)
                            301 	.globl __sdcc_gsinit_startup
                            302 	.globl __sdcc_program_startup
                            303 	.globl __start__stack
                            304 	.globl __mcs51_genXINIT
                            305 	.globl __mcs51_genXRAMCLEAR
                            306 	.globl __mcs51_genRAMCLEAR
                            307 ;	Z:\AESOKZ~C\lab8.c:6: unsigned char Licznik = 0;
   0074 75 08 00            308 	mov	_Licznik,#0x00
                            309 ;	Z:\AESOKZ~C\lab8.c:7: int i = 0;
   0077 E4                  310 	clr	a
   0078 F5 09               311 	mov	_i,a
   007A F5 0A               312 	mov	(_i + 1),a
                            313 	.area GSFINAL (CODE)
   007C 02 00 16            314 	ljmp	__sdcc_program_startup
                            315 ;--------------------------------------------------------
                            316 ; Home
                            317 ;--------------------------------------------------------
                            318 	.area HOME    (CODE)
                            319 	.area HOME    (CODE)
   0016                     320 __sdcc_program_startup:
   0016 12 00 7F            321 	lcall	_main
                            322 ;	return from main will lock up
   0019 80 FE               323 	sjmp .
                            324 ;--------------------------------------------------------
                            325 ; code
                            326 ;--------------------------------------------------------
                            327 	.area CSEG    (CODE)
                            328 ;------------------------------------------------------------
                            329 ;Allocation info for local variables in function 'main'
                            330 ;------------------------------------------------------------
                            331 ;------------------------------------------------------------
                            332 ;	Z:\AESOKZ~C\lab8.c:9: int main(void)
                            333 ;	-----------------------------------------
                            334 ;	 function main
                            335 ;	-----------------------------------------
   007F                     336 _main:
                    0002    337 	ar2 = 0x02
                    0003    338 	ar3 = 0x03
                    0004    339 	ar4 = 0x04
                    0005    340 	ar5 = 0x05
                    0006    341 	ar6 = 0x06
                    0007    342 	ar7 = 0x07
                    0000    343 	ar0 = 0x00
                    0001    344 	ar1 = 0x01
                            345 ;	Z:\AESOKZ~C\lab8.c:11: P2 = 255;
   007F 75 A0 FF            346 	mov	_P2,#0xFF
                            347 ;	Z:\AESOKZ~C\lab8.c:12: TMOD = 1;
   0082 75 89 01            348 	mov	_TMOD,#0x01
                            349 ;	Z:\AESOKZ~C\lab8.c:13: TH0 = CZAS_50ms / 256;
   0085 75 8C 84            350 	mov	_TH0,#0x84
                            351 ;	Z:\AESOKZ~C\lab8.c:14: TL0 = CZAS_50ms % 256;
   0088 75 8A 38            352 	mov	_TL0,#0x38
                            353 ;	Z:\AESOKZ~C\lab8.c:15: TR0 = 1; ET0 = 1; EA = 1;
   008B D2 8C               354 	setb	_TR0
   008D D2 A9               355 	setb	_ET0
   008F D2 AF               356 	setb	_EA
                            357 ;	Z:\AESOKZ~C\lab8.c:16: EX0 = 1; EX1 = 1;
   0091 D2 A8               358 	setb	_EX0
   0093 D2 AA               359 	setb	_EX1
                            360 ;	Z:\AESOKZ~C\lab8.c:17: while(1);
   0095                     361 00102$:
   0095 80 FE               362 	sjmp	00102$
                            363 ;------------------------------------------------------------
                            364 ;Allocation info for local variables in function 'timer0'
                            365 ;------------------------------------------------------------
                            366 ;------------------------------------------------------------
                            367 ;	Z:\AESOKZ~C\lab8.c:20: void timer0(void) __interrupt(1)
                            368 ;	-----------------------------------------
                            369 ;	 function timer0
                            370 ;	-----------------------------------------
   0097                     371 _timer0:
   0097 C0 E0               372 	push	acc
   0099 C0 F0               373 	push	b
   009B C0 D0               374 	push	psw
   009D 75 D0 00            375 	mov	psw,#0x00
                            376 ;	Z:\AESOKZ~C\lab8.c:22: TH0 = CZAS_50ms / 256;
   00A0 75 8C 84            377 	mov	_TH0,#0x84
                            378 ;	Z:\AESOKZ~C\lab8.c:23: TL0 = CZAS_50ms % 256;
   00A3 75 8A 38            379 	mov	_TL0,#0x38
                            380 ;	Z:\AESOKZ~C\lab8.c:24: i++;
   00A6 05 09               381 	inc	_i
   00A8 E4                  382 	clr	a
   00A9 B5 09 02            383 	cjne	a,_i,00114$
   00AC 05 0A               384 	inc	(_i + 1)
   00AE                     385 00114$:
                            386 ;	Z:\AESOKZ~C\lab8.c:25: if(i == 10)
   00AE 74 0A               387 	mov	a,#0x0A
   00B0 B5 09 06            388 	cjne	a,_i,00115$
   00B3 E4                  389 	clr	a
   00B4 B5 0A 02            390 	cjne	a,(_i + 1),00115$
   00B7 80 02               391 	sjmp	00116$
   00B9                     392 00115$:
   00B9 80 0F               393 	sjmp	00107$
   00BB                     394 00116$:
                            395 ;	Z:\AESOKZ~C\lab8.c:27: if(P2 == 255) P2 = 254; else P2 = 255;
   00BB 74 FF               396 	mov	a,#0xFF
   00BD B5 A0 05            397 	cjne	a,_P2,00102$
   00C0 75 A0 FE            398 	mov	_P2,#0xFE
   00C3 80 1B               399 	sjmp	00109$
   00C5                     400 00102$:
   00C5 75 A0 FF            401 	mov	_P2,#0xFF
   00C8 80 16               402 	sjmp	00109$
   00CA                     403 00107$:
                            404 ;	Z:\AESOKZ~C\lab8.c:29: else if (i > 10) i = 0;
   00CA C3                  405 	clr	c
   00CB 74 0A               406 	mov	a,#0x0A
   00CD 95 09               407 	subb	a,_i
   00CF 74 80               408 	mov	a,#(0x00 ^ 0x80)
   00D1 85 0A F0            409 	mov	b,(_i + 1)
   00D4 63 F0 80            410 	xrl	b,#0x80
   00D7 95 F0               411 	subb	a,b
   00D9 50 05               412 	jnc	00109$
   00DB E4                  413 	clr	a
   00DC F5 09               414 	mov	_i,a
   00DE F5 0A               415 	mov	(_i + 1),a
   00E0                     416 00109$:
   00E0 D0 D0               417 	pop	psw
   00E2 D0 F0               418 	pop	b
   00E4 D0 E0               419 	pop	acc
   00E6 32                  420 	reti
                            421 ;	eliminated unneeded push/pop dpl
                            422 ;	eliminated unneeded push/pop dph
                            423 ;------------------------------------------------------------
                            424 ;Allocation info for local variables in function 'button5'
                            425 ;------------------------------------------------------------
                            426 ;------------------------------------------------------------
                            427 ;	Z:\AESOKZ~C\lab8.c:32: void button5(void) __interrupt(0)
                            428 ;	-----------------------------------------
                            429 ;	 function button5
                            430 ;	-----------------------------------------
   00E7                     431 _button5:
                            432 ;	Z:\AESOKZ~C\lab8.c:34: P2 = 250;
   00E7 75 A0 FA            433 	mov	_P2,#0xFA
   00EA 32                  434 	reti
                            435 ;	eliminated unneeded push/pop psw
                            436 ;	eliminated unneeded push/pop dpl
                            437 ;	eliminated unneeded push/pop dph
                            438 ;	eliminated unneeded push/pop b
                            439 ;	eliminated unneeded push/pop acc
                            440 ;------------------------------------------------------------
                            441 ;Allocation info for local variables in function 'button6'
                            442 ;------------------------------------------------------------
                            443 ;------------------------------------------------------------
                            444 ;	Z:\AESOKZ~C\lab8.c:37: void button6(void) __interrupt(2)
                            445 ;	-----------------------------------------
                            446 ;	 function button6
                            447 ;	-----------------------------------------
   00EB                     448 _button6:
                            449 ;	Z:\AESOKZ~C\lab8.c:39: P2 = 240;
   00EB 75 A0 F0            450 	mov	_P2,#0xF0
   00EE 32                  451 	reti
                            452 ;	eliminated unneeded push/pop psw
                            453 ;	eliminated unneeded push/pop dpl
                            454 ;	eliminated unneeded push/pop dph
                            455 ;	eliminated unneeded push/pop b
                            456 ;	eliminated unneeded push/pop acc
                            457 	.area CSEG    (CODE)
                            458 	.area CONST   (CODE)
                            459 	.area XINIT   (CODE)
                            460 	.area CABS    (ABS,CODE)

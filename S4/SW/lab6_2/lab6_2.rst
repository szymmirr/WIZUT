                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
                              4 ; This file was generated Wed Apr 12 11:48:25 2017
                              5 ;--------------------------------------------------------
                              6 	.module lab6_2
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _timer0
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
                            110 	.globl _Licznik
                            111 ;--------------------------------------------------------
                            112 ; special function registers
                            113 ;--------------------------------------------------------
                            114 	.area RSEG    (ABS,DATA)
   0000                     115 	.org 0x0000
                    0080    116 _P0	=	0x0080
                    0081    117 _SP	=	0x0081
                    0082    118 _DPL	=	0x0082
                    0083    119 _DPH	=	0x0083
                    0087    120 _PCON	=	0x0087
                    0088    121 _TCON	=	0x0088
                    0089    122 _TMOD	=	0x0089
                    008A    123 _TL0	=	0x008a
                    008B    124 _TL1	=	0x008b
                    008C    125 _TH0	=	0x008c
                    008D    126 _TH1	=	0x008d
                    0090    127 _P1	=	0x0090
                    0098    128 _SCON	=	0x0098
                    0099    129 _SBUF	=	0x0099
                    00A0    130 _P2	=	0x00a0
                    00A8    131 _IE	=	0x00a8
                    00B0    132 _P3	=	0x00b0
                    00B8    133 _IP	=	0x00b8
                    00D0    134 _PSW	=	0x00d0
                    00E0    135 _ACC	=	0x00e0
                    00F0    136 _B	=	0x00f0
                            137 ;--------------------------------------------------------
                            138 ; special function bits
                            139 ;--------------------------------------------------------
                            140 	.area RSEG    (ABS,DATA)
   0000                     141 	.org 0x0000
                    0080    142 _P0_0	=	0x0080
                    0081    143 _P0_1	=	0x0081
                    0082    144 _P0_2	=	0x0082
                    0083    145 _P0_3	=	0x0083
                    0084    146 _P0_4	=	0x0084
                    0085    147 _P0_5	=	0x0085
                    0086    148 _P0_6	=	0x0086
                    0087    149 _P0_7	=	0x0087
                    0088    150 _IT0	=	0x0088
                    0089    151 _IE0	=	0x0089
                    008A    152 _IT1	=	0x008a
                    008B    153 _IE1	=	0x008b
                    008C    154 _TR0	=	0x008c
                    008D    155 _TF0	=	0x008d
                    008E    156 _TR1	=	0x008e
                    008F    157 _TF1	=	0x008f
                    0090    158 _P1_0	=	0x0090
                    0091    159 _P1_1	=	0x0091
                    0092    160 _P1_2	=	0x0092
                    0093    161 _P1_3	=	0x0093
                    0094    162 _P1_4	=	0x0094
                    0095    163 _P1_5	=	0x0095
                    0096    164 _P1_6	=	0x0096
                    0097    165 _P1_7	=	0x0097
                    0098    166 _RI	=	0x0098
                    0099    167 _TI	=	0x0099
                    009A    168 _RB8	=	0x009a
                    009B    169 _TB8	=	0x009b
                    009C    170 _REN	=	0x009c
                    009D    171 _SM2	=	0x009d
                    009E    172 _SM1	=	0x009e
                    009F    173 _SM0	=	0x009f
                    00A0    174 _P2_0	=	0x00a0
                    00A1    175 _P2_1	=	0x00a1
                    00A2    176 _P2_2	=	0x00a2
                    00A3    177 _P2_3	=	0x00a3
                    00A4    178 _P2_4	=	0x00a4
                    00A5    179 _P2_5	=	0x00a5
                    00A6    180 _P2_6	=	0x00a6
                    00A7    181 _P2_7	=	0x00a7
                    00A8    182 _EX0	=	0x00a8
                    00A9    183 _ET0	=	0x00a9
                    00AA    184 _EX1	=	0x00aa
                    00AB    185 _ET1	=	0x00ab
                    00AC    186 _ES	=	0x00ac
                    00AF    187 _EA	=	0x00af
                    00B0    188 _P3_0	=	0x00b0
                    00B1    189 _P3_1	=	0x00b1
                    00B2    190 _P3_2	=	0x00b2
                    00B3    191 _P3_3	=	0x00b3
                    00B4    192 _P3_4	=	0x00b4
                    00B5    193 _P3_5	=	0x00b5
                    00B6    194 _P3_6	=	0x00b6
                    00B7    195 _P3_7	=	0x00b7
                    00B0    196 _RXD	=	0x00b0
                    00B1    197 _TXD	=	0x00b1
                    00B2    198 _INT0	=	0x00b2
                    00B3    199 _INT1	=	0x00b3
                    00B4    200 _T0	=	0x00b4
                    00B5    201 _T1	=	0x00b5
                    00B6    202 _WR	=	0x00b6
                    00B7    203 _RD	=	0x00b7
                    00B8    204 _PX0	=	0x00b8
                    00B9    205 _PT0	=	0x00b9
                    00BA    206 _PX1	=	0x00ba
                    00BB    207 _PT1	=	0x00bb
                    00BC    208 _PS	=	0x00bc
                    00D0    209 _P	=	0x00d0
                    00D1    210 _F1	=	0x00d1
                    00D2    211 _OV	=	0x00d2
                    00D3    212 _RS0	=	0x00d3
                    00D4    213 _RS1	=	0x00d4
                    00D5    214 _F0	=	0x00d5
                    00D6    215 _AC	=	0x00d6
                    00D7    216 _CY	=	0x00d7
                            217 ;--------------------------------------------------------
                            218 ; overlayable register banks
                            219 ;--------------------------------------------------------
                            220 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     221 	.ds 8
                            222 	.area REG_BANK_1	(REL,OVR,DATA)
   0008                     223 	.ds 8
                            224 ;--------------------------------------------------------
                            225 ; internal ram data
                            226 ;--------------------------------------------------------
                            227 	.area DSEG    (DATA)
   0010                     228 _Licznik::
   0010                     229 	.ds 1
                            230 ;--------------------------------------------------------
                            231 ; overlayable items in internal ram 
                            232 ;--------------------------------------------------------
                            233 	.area OSEG    (OVR,DATA)
                            234 ;--------------------------------------------------------
                            235 ; Stack segment in internal ram 
                            236 ;--------------------------------------------------------
                            237 	.area	SSEG	(DATA)
   0011                     238 __start__stack:
   0011                     239 	.ds	1
                            240 
                            241 ;--------------------------------------------------------
                            242 ; indirectly addressable internal ram data
                            243 ;--------------------------------------------------------
                            244 	.area ISEG    (DATA)
                            245 ;--------------------------------------------------------
                            246 ; absolute internal ram data
                            247 ;--------------------------------------------------------
                            248 	.area IABS    (ABS,DATA)
                            249 	.area IABS    (ABS,DATA)
                            250 ;--------------------------------------------------------
                            251 ; bit data
                            252 ;--------------------------------------------------------
                            253 	.area BSEG    (BIT)
                            254 ;--------------------------------------------------------
                            255 ; paged external ram data
                            256 ;--------------------------------------------------------
                            257 	.area PSEG    (PAG,XDATA)
                            258 ;--------------------------------------------------------
                            259 ; external ram data
                            260 ;--------------------------------------------------------
                            261 	.area XSEG    (XDATA)
                            262 ;--------------------------------------------------------
                            263 ; absolute external ram data
                            264 ;--------------------------------------------------------
                            265 	.area XABS    (ABS,XDATA)
                            266 ;--------------------------------------------------------
                            267 ; external initialized ram data
                            268 ;--------------------------------------------------------
                            269 	.area XISEG   (XDATA)
                            270 	.area HOME    (CODE)
                            271 	.area GSINIT0 (CODE)
                            272 	.area GSINIT1 (CODE)
                            273 	.area GSINIT2 (CODE)
                            274 	.area GSINIT3 (CODE)
                            275 	.area GSINIT4 (CODE)
                            276 	.area GSINIT5 (CODE)
                            277 	.area GSINIT  (CODE)
                            278 	.area GSFINAL (CODE)
                            279 	.area CSEG    (CODE)
                            280 ;--------------------------------------------------------
                            281 ; interrupt vector 
                            282 ;--------------------------------------------------------
                            283 	.area HOME    (CODE)
   0000                     284 __interrupt_vect:
   0000 02 00 13            285 	ljmp	__sdcc_gsinit_startup
   0003 32                  286 	reti
   0004                     287 	.ds	7
   000B 02 00 86            288 	ljmp	_timer0
                            289 ;--------------------------------------------------------
                            290 ; global & static initialisations
                            291 ;--------------------------------------------------------
                            292 	.area HOME    (CODE)
                            293 	.area GSINIT  (CODE)
                            294 	.area GSFINAL (CODE)
                            295 	.area GSINIT  (CODE)
                            296 	.globl __sdcc_gsinit_startup
                            297 	.globl __sdcc_program_startup
                            298 	.globl __start__stack
                            299 	.globl __mcs51_genXINIT
                            300 	.globl __mcs51_genXRAMCLEAR
                            301 	.globl __mcs51_genRAMCLEAR
                            302 ;	Z:\AESOKZ~C\lab6_2.c:3: unsigned char Licznik = 0;
   006C 75 10 00            303 	mov	_Licznik,#0x00
                            304 	.area GSFINAL (CODE)
   006F 02 00 0E            305 	ljmp	__sdcc_program_startup
                            306 ;--------------------------------------------------------
                            307 ; Home
                            308 ;--------------------------------------------------------
                            309 	.area HOME    (CODE)
                            310 	.area HOME    (CODE)
   000E                     311 __sdcc_program_startup:
   000E 12 00 72            312 	lcall	_main
                            313 ;	return from main will lock up
   0011 80 FE               314 	sjmp .
                            315 ;--------------------------------------------------------
                            316 ; code
                            317 ;--------------------------------------------------------
                            318 	.area CSEG    (CODE)
                            319 ;------------------------------------------------------------
                            320 ;Allocation info for local variables in function 'main'
                            321 ;------------------------------------------------------------
                            322 ;------------------------------------------------------------
                            323 ;	Z:\AESOKZ~C\lab6_2.c:5: int main(void)
                            324 ;	-----------------------------------------
                            325 ;	 function main
                            326 ;	-----------------------------------------
   0072                     327 _main:
                    0002    328 	ar2 = 0x02
                    0003    329 	ar3 = 0x03
                    0004    330 	ar4 = 0x04
                    0005    331 	ar5 = 0x05
                    0006    332 	ar6 = 0x06
                    0007    333 	ar7 = 0x07
                    0000    334 	ar0 = 0x00
                    0001    335 	ar1 = 0x01
                            336 ;	Z:\AESOKZ~C\lab6_2.c:7: P2=0;
   0072 75 A0 00            337 	mov	_P2,#0x00
                            338 ;	Z:\AESOKZ~C\lab6_2.c:8: TMOD=1;
   0075 75 89 01            339 	mov	_TMOD,#0x01
                            340 ;	Z:\AESOKZ~C\lab6_2.c:9: TH0=Czas/256;
   0078 75 8C 4C            341 	mov	_TH0,#0x4C
                            342 ;	Z:\AESOKZ~C\lab6_2.c:10: TL0=Czas%256;
   007B 75 8A 00            343 	mov	_TL0,#0x00
                            344 ;	Z:\AESOKZ~C\lab6_2.c:11: TR0 = 1;
   007E D2 8C               345 	setb	_TR0
                            346 ;	Z:\AESOKZ~C\lab6_2.c:12: ET0 = 1;
   0080 D2 A9               347 	setb	_ET0
                            348 ;	Z:\AESOKZ~C\lab6_2.c:13: EA = 1;
   0082 D2 AF               349 	setb	_EA
                            350 ;	Z:\AESOKZ~C\lab6_2.c:15: while(1);
   0084                     351 00102$:
   0084 80 FE               352 	sjmp	00102$
                            353 ;------------------------------------------------------------
                            354 ;Allocation info for local variables in function 'timer0'
                            355 ;------------------------------------------------------------
                            356 ;------------------------------------------------------------
                            357 ;	Z:\AESOKZ~C\lab6_2.c:18: void timer0(void) __interrupt(1) __using(1)
                            358 ;	-----------------------------------------
                            359 ;	 function timer0
                            360 ;	-----------------------------------------
   0086                     361 _timer0:
                    000A    362 	ar2 = 0x0a
                    000B    363 	ar3 = 0x0b
                    000C    364 	ar4 = 0x0c
                    000D    365 	ar5 = 0x0d
                    000E    366 	ar6 = 0x0e
                    000F    367 	ar7 = 0x0f
                    0008    368 	ar0 = 0x08
                    0009    369 	ar1 = 0x09
   0086 C0 E0               370 	push	acc
   0088 C0 D0               371 	push	psw
   008A 75 D0 08            372 	mov	psw,#0x08
                            373 ;	Z:\AESOKZ~C\lab6_2.c:20: TH0 = Czas/256;
   008D 75 8C 4C            374 	mov	_TH0,#0x4C
                            375 ;	Z:\AESOKZ~C\lab6_2.c:21: TL0 = Czas%256;
   0090 75 8A 00            376 	mov	_TL0,#0x00
                            377 ;	Z:\AESOKZ~C\lab6_2.c:23: Licznik++;
   0093 05 10               378 	inc	_Licznik
                            379 ;	Z:\AESOKZ~C\lab6_2.c:25: if(Licznik > 63) Licznik = 0;
   0095 74 3F               380 	mov	a,#0x3F
   0097 B5 10 00            381 	cjne	a,_Licznik,00106$
   009A                     382 00106$:
   009A 50 03               383 	jnc	00102$
   009C 75 10 00            384 	mov	_Licznik,#0x00
   009F                     385 00102$:
                            386 ;	Z:\AESOKZ~C\lab6_2.c:26: P2=Licznik;
   009F 85 10 A0            387 	mov	_P2,_Licznik
   00A2 D0 D0               388 	pop	psw
   00A4 D0 E0               389 	pop	acc
   00A6 32                  390 	reti
                            391 ;	eliminated unneeded push/pop dpl
                            392 ;	eliminated unneeded push/pop dph
                            393 ;	eliminated unneeded push/pop b
                            394 	.area CSEG    (CODE)
                            395 	.area CONST   (CODE)
                            396 	.area XINIT   (CODE)
                            397 	.area CABS    (ABS,CODE)

                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
                              4 ; This file was generated Wed Apr 26 11:19:35 2017
                              5 ;--------------------------------------------------------
                              6 	.module lab7c
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _CzasZwloki
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
                            222 ;--------------------------------------------------------
                            223 ; internal ram data
                            224 ;--------------------------------------------------------
                            225 	.area DSEG    (DATA)
   0008                     226 _Licznik::
   0008                     227 	.ds 1
                            228 ;--------------------------------------------------------
                            229 ; overlayable items in internal ram 
                            230 ;--------------------------------------------------------
                            231 	.area OSEG    (OVR,DATA)
                            232 ;--------------------------------------------------------
                            233 ; Stack segment in internal ram 
                            234 ;--------------------------------------------------------
                            235 	.area	SSEG	(DATA)
   0009                     236 __start__stack:
   0009                     237 	.ds	1
                            238 
                            239 ;--------------------------------------------------------
                            240 ; indirectly addressable internal ram data
                            241 ;--------------------------------------------------------
                            242 	.area ISEG    (DATA)
                            243 ;--------------------------------------------------------
                            244 ; absolute internal ram data
                            245 ;--------------------------------------------------------
                            246 	.area IABS    (ABS,DATA)
                            247 	.area IABS    (ABS,DATA)
                            248 ;--------------------------------------------------------
                            249 ; bit data
                            250 ;--------------------------------------------------------
                            251 	.area BSEG    (BIT)
                            252 ;--------------------------------------------------------
                            253 ; paged external ram data
                            254 ;--------------------------------------------------------
                            255 	.area PSEG    (PAG,XDATA)
                            256 ;--------------------------------------------------------
                            257 ; external ram data
                            258 ;--------------------------------------------------------
                            259 	.area XSEG    (XDATA)
                            260 ;--------------------------------------------------------
                            261 ; absolute external ram data
                            262 ;--------------------------------------------------------
                            263 	.area XABS    (ABS,XDATA)
                            264 ;--------------------------------------------------------
                            265 ; external initialized ram data
                            266 ;--------------------------------------------------------
                            267 	.area XISEG   (XDATA)
                            268 	.area HOME    (CODE)
                            269 	.area GSINIT0 (CODE)
                            270 	.area GSINIT1 (CODE)
                            271 	.area GSINIT2 (CODE)
                            272 	.area GSINIT3 (CODE)
                            273 	.area GSINIT4 (CODE)
                            274 	.area GSINIT5 (CODE)
                            275 	.area GSINIT  (CODE)
                            276 	.area GSFINAL (CODE)
                            277 	.area CSEG    (CODE)
                            278 ;--------------------------------------------------------
                            279 ; interrupt vector 
                            280 ;--------------------------------------------------------
                            281 	.area HOME    (CODE)
   0000                     282 __interrupt_vect:
   0000 02 00 08            283 	ljmp	__sdcc_gsinit_startup
                            284 ;--------------------------------------------------------
                            285 ; global & static initialisations
                            286 ;--------------------------------------------------------
                            287 	.area HOME    (CODE)
                            288 	.area GSINIT  (CODE)
                            289 	.area GSFINAL (CODE)
                            290 	.area GSINIT  (CODE)
                            291 	.globl __sdcc_gsinit_startup
                            292 	.globl __sdcc_program_startup
                            293 	.globl __start__stack
                            294 	.globl __mcs51_genXINIT
                            295 	.globl __mcs51_genXRAMCLEAR
                            296 	.globl __mcs51_genRAMCLEAR
                            297 ;	Z:\AESOKZ~C\lab7c.c:7: unsigned char Licznik = 0;
   0061 75 08 00            298 	mov	_Licznik,#0x00
                            299 	.area GSFINAL (CODE)
   0064 02 00 03            300 	ljmp	__sdcc_program_startup
                            301 ;--------------------------------------------------------
                            302 ; Home
                            303 ;--------------------------------------------------------
                            304 	.area HOME    (CODE)
                            305 	.area HOME    (CODE)
   0003                     306 __sdcc_program_startup:
   0003 12 00 DA            307 	lcall	_main
                            308 ;	return from main will lock up
   0006 80 FE               309 	sjmp .
                            310 ;--------------------------------------------------------
                            311 ; code
                            312 ;--------------------------------------------------------
                            313 	.area CSEG    (CODE)
                            314 ;------------------------------------------------------------
                            315 ;Allocation info for local variables in function 'CzasZwloki'
                            316 ;------------------------------------------------------------
                            317 ;Ilosc                     Allocated to registers r2 r3 
                            318 ;------------------------------------------------------------
                            319 ;	Z:\AESOKZ~C\lab7c.c:9: void CzasZwloki(unsigned int Ilosc)
                            320 ;	-----------------------------------------
                            321 ;	 function CzasZwloki
                            322 ;	-----------------------------------------
   0067                     323 _CzasZwloki:
                    0002    324 	ar2 = 0x02
                    0003    325 	ar3 = 0x03
                    0004    326 	ar4 = 0x04
                    0005    327 	ar5 = 0x05
                    0006    328 	ar6 = 0x06
                    0007    329 	ar7 = 0x07
                    0000    330 	ar0 = 0x00
                    0001    331 	ar1 = 0x01
   0067 AA 82               332 	mov	r2,dpl
   0069 AB 83               333 	mov	r3,dph
                            334 ;	Z:\AESOKZ~C\lab7c.c:11: TL0 = (65536 - Ilosc) % 256;
   006B E4                  335 	clr	a
   006C FC                  336 	mov	r4,a
   006D FD                  337 	mov	r5,a
   006E C3                  338 	clr	c
   006F 9A                  339 	subb	a,r2
   0070 FA                  340 	mov	r2,a
   0071 E4                  341 	clr	a
   0072 9B                  342 	subb	a,r3
   0073 FB                  343 	mov	r3,a
   0074 74 01               344 	mov	a,#0x01
   0076 9C                  345 	subb	a,r4
   0077 FC                  346 	mov	r4,a
   0078 E4                  347 	clr	a
   0079 9D                  348 	subb	a,r5
   007A FD                  349 	mov	r5,a
   007B C0 02               350 	push	ar2
   007D C0 03               351 	push	ar3
   007F C0 04               352 	push	ar4
   0081 C0 05               353 	push	ar5
   0083 E4                  354 	clr	a
   0084 C0 E0               355 	push	acc
   0086 74 01               356 	mov	a,#0x01
   0088 C0 E0               357 	push	acc
   008A E4                  358 	clr	a
   008B C0 E0               359 	push	acc
   008D C0 E0               360 	push	acc
   008F 8A 82               361 	mov	dpl,r2
   0091 8B 83               362 	mov	dph,r3
   0093 8C F0               363 	mov	b,r4
   0095 ED                  364 	mov	a,r5
   0096 12 01 12            365 	lcall	__modslong
   0099 AE 82               366 	mov	r6,dpl
   009B E5 81               367 	mov	a,sp
   009D 24 FC               368 	add	a,#0xfc
   009F F5 81               369 	mov	sp,a
   00A1 D0 05               370 	pop	ar5
   00A3 D0 04               371 	pop	ar4
   00A5 D0 03               372 	pop	ar3
   00A7 D0 02               373 	pop	ar2
   00A9 8E 8A               374 	mov	_TL0,r6
                            375 ;	Z:\AESOKZ~C\lab7c.c:12: TH0 = (65536 - Ilosc) / 256;
   00AB E4                  376 	clr	a
   00AC C0 E0               377 	push	acc
   00AE 74 01               378 	mov	a,#0x01
   00B0 C0 E0               379 	push	acc
   00B2 E4                  380 	clr	a
   00B3 C0 E0               381 	push	acc
   00B5 C0 E0               382 	push	acc
   00B7 8A 82               383 	mov	dpl,r2
   00B9 8B 83               384 	mov	dph,r3
   00BB 8C F0               385 	mov	b,r4
   00BD ED                  386 	mov	a,r5
   00BE 12 01 66            387 	lcall	__divslong
   00C1 AA 82               388 	mov	r2,dpl
   00C3 AB 83               389 	mov	r3,dph
   00C5 AC F0               390 	mov	r4,b
   00C7 FD                  391 	mov	r5,a
   00C8 E5 81               392 	mov	a,sp
   00CA 24 FC               393 	add	a,#0xfc
   00CC F5 81               394 	mov	sp,a
   00CE 8A 8C               395 	mov	_TH0,r2
                            396 ;	Z:\AESOKZ~C\lab7c.c:13: TF0 = 0;
   00D0 C2 8D               397 	clr	_TF0
                            398 ;	Z:\AESOKZ~C\lab7c.c:14: TR0 = 1;
   00D2 D2 8C               399 	setb	_TR0
                            400 ;	Z:\AESOKZ~C\lab7c.c:15: while(!TF0);
   00D4                     401 00101$:
   00D4 30 8D FD            402 	jnb	_TF0,00101$
                            403 ;	Z:\AESOKZ~C\lab7c.c:16: TR0 = 0;
   00D7 C2 8C               404 	clr	_TR0
   00D9 22                  405 	ret
                            406 ;------------------------------------------------------------
                            407 ;Allocation info for local variables in function 'main'
                            408 ;------------------------------------------------------------
                            409 ;------------------------------------------------------------
                            410 ;	Z:\AESOKZ~C\lab7c.c:19: int main(void)
                            411 ;	-----------------------------------------
                            412 ;	 function main
                            413 ;	-----------------------------------------
   00DA                     414 _main:
                            415 ;	Z:\AESOKZ~C\lab7c.c:21: PortLED = 0;
   00DA 75 A0 00            416 	mov	_P2,#0x00
                            417 ;	Z:\AESOKZ~C\lab7c.c:24: while(StykP1 && StykP2);
   00DD                     418 00102$:
   00DD 30 93 03            419 	jnb	_P1_3,00104$
   00E0 20 94 FA            420 	jb	_P1_4,00102$
   00E3                     421 00104$:
                            422 ;	Z:\AESOKZ~C\lab7c.c:25: CzasZwloki(9600);
   00E3 90 25 80            423 	mov	dptr,#0x2580
   00E6 12 00 67            424 	lcall	_CzasZwloki
                            425 ;	Z:\AESOKZ~C\lab7c.c:26: if(StykP1)
   00E9 30 93 0A            426 	jnb	_P1_3,00108$
                            427 ;	Z:\AESOKZ~C\lab7c.c:28: CzasZwloki(9600);
   00EC 90 25 80            428 	mov	dptr,#0x2580
   00EF 12 00 67            429 	lcall	_CzasZwloki
                            430 ;	Z:\AESOKZ~C\lab7c.c:29: Licznik++;
   00F2 05 08               431 	inc	_Licznik
   00F4 80 0B               432 	sjmp	00109$
   00F6                     433 00108$:
                            434 ;	Z:\AESOKZ~C\lab7c.c:31: else if(StykP2)
   00F6 30 94 08            435 	jnb	_P1_4,00109$
                            436 ;	Z:\AESOKZ~C\lab7c.c:33: CzasZwloki(9600);
   00F9 90 25 80            437 	mov	dptr,#0x2580
   00FC 12 00 67            438 	lcall	_CzasZwloki
                            439 ;	Z:\AESOKZ~C\lab7c.c:34: Licznik--;
   00FF 15 08               440 	dec	_Licznik
   0101                     441 00109$:
                            442 ;	Z:\AESOKZ~C\lab7c.c:37: PortLED = Licznik;
   0101 85 08 A0            443 	mov	_P2,_Licznik
                            444 ;	Z:\AESOKZ~C\lab7c.c:38: while(!StykP1 || !StykP2);
   0104                     445 00111$:
   0104 30 93 FD            446 	jnb	_P1_3,00111$
   0107 30 94 FA            447 	jnb	_P1_4,00111$
                            448 ;	Z:\AESOKZ~C\lab7c.c:39: CzasZwloki(9600);
   010A 90 25 80            449 	mov	dptr,#0x2580
   010D 12 00 67            450 	lcall	_CzasZwloki
   0110 80 CB               451 	sjmp	00102$
                            452 	.area CSEG    (CODE)
                            453 	.area CONST   (CODE)
                            454 	.area XINIT   (CODE)
                            455 	.area CABS    (ABS,CODE)

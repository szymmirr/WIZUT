                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
                              4 ; This file was generated Fri Apr 07 17:42:21 2017
                              5 ;--------------------------------------------------------
                              6 	.module tajmerek
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
                            109 ;--------------------------------------------------------
                            110 ; special function registers
                            111 ;--------------------------------------------------------
                            112 	.area RSEG    (ABS,DATA)
   0000                     113 	.org 0x0000
                    0080    114 _P0	=	0x0080
                    0081    115 _SP	=	0x0081
                    0082    116 _DPL	=	0x0082
                    0083    117 _DPH	=	0x0083
                    0087    118 _PCON	=	0x0087
                    0088    119 _TCON	=	0x0088
                    0089    120 _TMOD	=	0x0089
                    008A    121 _TL0	=	0x008a
                    008B    122 _TL1	=	0x008b
                    008C    123 _TH0	=	0x008c
                    008D    124 _TH1	=	0x008d
                    0090    125 _P1	=	0x0090
                    0098    126 _SCON	=	0x0098
                    0099    127 _SBUF	=	0x0099
                    00A0    128 _P2	=	0x00a0
                    00A8    129 _IE	=	0x00a8
                    00B0    130 _P3	=	0x00b0
                    00B8    131 _IP	=	0x00b8
                    00D0    132 _PSW	=	0x00d0
                    00E0    133 _ACC	=	0x00e0
                    00F0    134 _B	=	0x00f0
                            135 ;--------------------------------------------------------
                            136 ; special function bits
                            137 ;--------------------------------------------------------
                            138 	.area RSEG    (ABS,DATA)
   0000                     139 	.org 0x0000
                    0080    140 _P0_0	=	0x0080
                    0081    141 _P0_1	=	0x0081
                    0082    142 _P0_2	=	0x0082
                    0083    143 _P0_3	=	0x0083
                    0084    144 _P0_4	=	0x0084
                    0085    145 _P0_5	=	0x0085
                    0086    146 _P0_6	=	0x0086
                    0087    147 _P0_7	=	0x0087
                    0088    148 _IT0	=	0x0088
                    0089    149 _IE0	=	0x0089
                    008A    150 _IT1	=	0x008a
                    008B    151 _IE1	=	0x008b
                    008C    152 _TR0	=	0x008c
                    008D    153 _TF0	=	0x008d
                    008E    154 _TR1	=	0x008e
                    008F    155 _TF1	=	0x008f
                    0090    156 _P1_0	=	0x0090
                    0091    157 _P1_1	=	0x0091
                    0092    158 _P1_2	=	0x0092
                    0093    159 _P1_3	=	0x0093
                    0094    160 _P1_4	=	0x0094
                    0095    161 _P1_5	=	0x0095
                    0096    162 _P1_6	=	0x0096
                    0097    163 _P1_7	=	0x0097
                    0098    164 _RI	=	0x0098
                    0099    165 _TI	=	0x0099
                    009A    166 _RB8	=	0x009a
                    009B    167 _TB8	=	0x009b
                    009C    168 _REN	=	0x009c
                    009D    169 _SM2	=	0x009d
                    009E    170 _SM1	=	0x009e
                    009F    171 _SM0	=	0x009f
                    00A0    172 _P2_0	=	0x00a0
                    00A1    173 _P2_1	=	0x00a1
                    00A2    174 _P2_2	=	0x00a2
                    00A3    175 _P2_3	=	0x00a3
                    00A4    176 _P2_4	=	0x00a4
                    00A5    177 _P2_5	=	0x00a5
                    00A6    178 _P2_6	=	0x00a6
                    00A7    179 _P2_7	=	0x00a7
                    00A8    180 _EX0	=	0x00a8
                    00A9    181 _ET0	=	0x00a9
                    00AA    182 _EX1	=	0x00aa
                    00AB    183 _ET1	=	0x00ab
                    00AC    184 _ES	=	0x00ac
                    00AF    185 _EA	=	0x00af
                    00B0    186 _P3_0	=	0x00b0
                    00B1    187 _P3_1	=	0x00b1
                    00B2    188 _P3_2	=	0x00b2
                    00B3    189 _P3_3	=	0x00b3
                    00B4    190 _P3_4	=	0x00b4
                    00B5    191 _P3_5	=	0x00b5
                    00B6    192 _P3_6	=	0x00b6
                    00B7    193 _P3_7	=	0x00b7
                    00B0    194 _RXD	=	0x00b0
                    00B1    195 _TXD	=	0x00b1
                    00B2    196 _INT0	=	0x00b2
                    00B3    197 _INT1	=	0x00b3
                    00B4    198 _T0	=	0x00b4
                    00B5    199 _T1	=	0x00b5
                    00B6    200 _WR	=	0x00b6
                    00B7    201 _RD	=	0x00b7
                    00B8    202 _PX0	=	0x00b8
                    00B9    203 _PT0	=	0x00b9
                    00BA    204 _PX1	=	0x00ba
                    00BB    205 _PT1	=	0x00bb
                    00BC    206 _PS	=	0x00bc
                    00D0    207 _P	=	0x00d0
                    00D1    208 _F1	=	0x00d1
                    00D2    209 _OV	=	0x00d2
                    00D3    210 _RS0	=	0x00d3
                    00D4    211 _RS1	=	0x00d4
                    00D5    212 _F0	=	0x00d5
                    00D6    213 _AC	=	0x00d6
                    00D7    214 _CY	=	0x00d7
                            215 ;--------------------------------------------------------
                            216 ; overlayable register banks
                            217 ;--------------------------------------------------------
                            218 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     219 	.ds 8
                            220 ;--------------------------------------------------------
                            221 ; internal ram data
                            222 ;--------------------------------------------------------
                            223 	.area DSEG    (DATA)
                            224 ;--------------------------------------------------------
                            225 ; overlayable items in internal ram 
                            226 ;--------------------------------------------------------
                            227 	.area OSEG    (OVR,DATA)
                            228 ;--------------------------------------------------------
                            229 ; Stack segment in internal ram 
                            230 ;--------------------------------------------------------
                            231 	.area	SSEG	(DATA)
   0008                     232 __start__stack:
   0008                     233 	.ds	1
                            234 
                            235 ;--------------------------------------------------------
                            236 ; indirectly addressable internal ram data
                            237 ;--------------------------------------------------------
                            238 	.area ISEG    (DATA)
                            239 ;--------------------------------------------------------
                            240 ; absolute internal ram data
                            241 ;--------------------------------------------------------
                            242 	.area IABS    (ABS,DATA)
                            243 	.area IABS    (ABS,DATA)
                            244 ;--------------------------------------------------------
                            245 ; bit data
                            246 ;--------------------------------------------------------
                            247 	.area BSEG    (BIT)
                            248 ;--------------------------------------------------------
                            249 ; paged external ram data
                            250 ;--------------------------------------------------------
                            251 	.area PSEG    (PAG,XDATA)
                            252 ;--------------------------------------------------------
                            253 ; external ram data
                            254 ;--------------------------------------------------------
                            255 	.area XSEG    (XDATA)
                            256 ;--------------------------------------------------------
                            257 ; absolute external ram data
                            258 ;--------------------------------------------------------
                            259 	.area XABS    (ABS,XDATA)
                            260 ;--------------------------------------------------------
                            261 ; external initialized ram data
                            262 ;--------------------------------------------------------
                            263 	.area XISEG   (XDATA)
                            264 	.area HOME    (CODE)
                            265 	.area GSINIT0 (CODE)
                            266 	.area GSINIT1 (CODE)
                            267 	.area GSINIT2 (CODE)
                            268 	.area GSINIT3 (CODE)
                            269 	.area GSINIT4 (CODE)
                            270 	.area GSINIT5 (CODE)
                            271 	.area GSINIT  (CODE)
                            272 	.area GSFINAL (CODE)
                            273 	.area CSEG    (CODE)
                            274 ;--------------------------------------------------------
                            275 ; interrupt vector 
                            276 ;--------------------------------------------------------
                            277 	.area HOME    (CODE)
   0000                     278 __interrupt_vect:
   0000 02 00 08            279 	ljmp	__sdcc_gsinit_startup
                            280 ;--------------------------------------------------------
                            281 ; global & static initialisations
                            282 ;--------------------------------------------------------
                            283 	.area HOME    (CODE)
                            284 	.area GSINIT  (CODE)
                            285 	.area GSFINAL (CODE)
                            286 	.area GSINIT  (CODE)
                            287 	.globl __sdcc_gsinit_startup
                            288 	.globl __sdcc_program_startup
                            289 	.globl __start__stack
                            290 	.globl __mcs51_genXINIT
                            291 	.globl __mcs51_genXRAMCLEAR
                            292 	.globl __mcs51_genRAMCLEAR
                            293 	.area GSFINAL (CODE)
   0061 02 00 03            294 	ljmp	__sdcc_program_startup
                            295 ;--------------------------------------------------------
                            296 ; Home
                            297 ;--------------------------------------------------------
                            298 	.area HOME    (CODE)
                            299 	.area HOME    (CODE)
   0003                     300 __sdcc_program_startup:
   0003 12 00 64            301 	lcall	_main
                            302 ;	return from main will lock up
   0006 80 FE               303 	sjmp .
                            304 ;--------------------------------------------------------
                            305 ; code
                            306 ;--------------------------------------------------------
                            307 	.area CSEG    (CODE)
                            308 ;------------------------------------------------------------
                            309 ;Allocation info for local variables in function 'main'
                            310 ;------------------------------------------------------------
                            311 ;------------------------------------------------------------
                            312 ;	Z:\AESOKZ~C\tajmerek.c:4: int main(void)
                            313 ;	-----------------------------------------
                            314 ;	 function main
                            315 ;	-----------------------------------------
   0064                     316 _main:
                    0002    317 	ar2 = 0x02
                    0003    318 	ar3 = 0x03
                    0004    319 	ar4 = 0x04
                    0005    320 	ar5 = 0x05
                    0006    321 	ar6 = 0x06
                    0007    322 	ar7 = 0x07
                    0000    323 	ar0 = 0x00
                    0001    324 	ar1 = 0x01
                            325 ;	Z:\AESOKZ~C\tajmerek.c:6: TMOD = 0x1;
   0064 75 89 01            326 	mov	_TMOD,#0x01
                            327 ;	Z:\AESOKZ~C\tajmerek.c:7: TR0 = 1;
   0067 D2 8C               328 	setb	_TR0
                            329 ;	Z:\AESOKZ~C\tajmerek.c:8: P2 = 0;
   0069 75 A0 00            330 	mov	_P2,#0x00
                            331 ;	Z:\AESOKZ~C\tajmerek.c:9: while(1)
   006C                     332 00108$:
                            333 ;	Z:\AESOKZ~C\tajmerek.c:11: P2 = P2 | 1;
   006C 43 A0 01            334 	orl	_P2,#0x01
                            335 ;	Z:\AESOKZ~C\tajmerek.c:12: TH0 = Czas/256;
   006F 75 8C 4C            336 	mov	_TH0,#0x4C
                            337 ;	Z:\AESOKZ~C\tajmerek.c:13: TL0 = Czas%256;
   0072 75 8A 00            338 	mov	_TL0,#0x00
                            339 ;	Z:\AESOKZ~C\tajmerek.c:14: while(TF0 == 0);
   0075                     340 00101$:
                            341 ;	Z:\AESOKZ~C\tajmerek.c:15: TF0 = 0;
   0075 10 8D 02            342 	jbc	_TF0,00117$
   0078 80 FB               343 	sjmp	00101$
   007A                     344 00117$:
                            345 ;	Z:\AESOKZ~C\tajmerek.c:17: P2 = P2 & ~1;
   007A 53 A0 FE            346 	anl	_P2,#0xFE
                            347 ;	Z:\AESOKZ~C\tajmerek.c:18: TH0 = Czas/256;
   007D 75 8C 4C            348 	mov	_TH0,#0x4C
                            349 ;	Z:\AESOKZ~C\tajmerek.c:19: TL0 = Czas%256;
   0080 75 8A 00            350 	mov	_TL0,#0x00
                            351 ;	Z:\AESOKZ~C\tajmerek.c:20: while(TF0 == 0);
   0083                     352 00104$:
                            353 ;	Z:\AESOKZ~C\tajmerek.c:21: TF0 = 0;
   0083 10 8D 02            354 	jbc	_TF0,00118$
   0086 80 FB               355 	sjmp	00104$
   0088                     356 00118$:
   0088 80 E2               357 	sjmp	00108$
                            358 	.area CSEG    (CODE)
                            359 	.area CONST   (CODE)
                            360 	.area XINIT   (CODE)
                            361 	.area CABS    (ABS,CODE)

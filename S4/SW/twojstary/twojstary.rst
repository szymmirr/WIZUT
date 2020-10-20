                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
                              4 ; This file was generated Fri Apr 07 17:33:44 2017
                              5 ;--------------------------------------------------------
                              6 	.module TTM7GO_I
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
                            109 	.globl _Czas
                            110 ;--------------------------------------------------------
                            111 ; special function registers
                            112 ;--------------------------------------------------------
                            113 	.area RSEG    (ABS,DATA)
   0000                     114 	.org 0x0000
                    0080    115 _P0	=	0x0080
                    0081    116 _SP	=	0x0081
                    0082    117 _DPL	=	0x0082
                    0083    118 _DPH	=	0x0083
                    0087    119 _PCON	=	0x0087
                    0088    120 _TCON	=	0x0088
                    0089    121 _TMOD	=	0x0089
                    008A    122 _TL0	=	0x008a
                    008B    123 _TL1	=	0x008b
                    008C    124 _TH0	=	0x008c
                    008D    125 _TH1	=	0x008d
                    0090    126 _P1	=	0x0090
                    0098    127 _SCON	=	0x0098
                    0099    128 _SBUF	=	0x0099
                    00A0    129 _P2	=	0x00a0
                    00A8    130 _IE	=	0x00a8
                    00B0    131 _P3	=	0x00b0
                    00B8    132 _IP	=	0x00b8
                    00D0    133 _PSW	=	0x00d0
                    00E0    134 _ACC	=	0x00e0
                    00F0    135 _B	=	0x00f0
                            136 ;--------------------------------------------------------
                            137 ; special function bits
                            138 ;--------------------------------------------------------
                            139 	.area RSEG    (ABS,DATA)
   0000                     140 	.org 0x0000
                    0080    141 _P0_0	=	0x0080
                    0081    142 _P0_1	=	0x0081
                    0082    143 _P0_2	=	0x0082
                    0083    144 _P0_3	=	0x0083
                    0084    145 _P0_4	=	0x0084
                    0085    146 _P0_5	=	0x0085
                    0086    147 _P0_6	=	0x0086
                    0087    148 _P0_7	=	0x0087
                    0088    149 _IT0	=	0x0088
                    0089    150 _IE0	=	0x0089
                    008A    151 _IT1	=	0x008a
                    008B    152 _IE1	=	0x008b
                    008C    153 _TR0	=	0x008c
                    008D    154 _TF0	=	0x008d
                    008E    155 _TR1	=	0x008e
                    008F    156 _TF1	=	0x008f
                    0090    157 _P1_0	=	0x0090
                    0091    158 _P1_1	=	0x0091
                    0092    159 _P1_2	=	0x0092
                    0093    160 _P1_3	=	0x0093
                    0094    161 _P1_4	=	0x0094
                    0095    162 _P1_5	=	0x0095
                    0096    163 _P1_6	=	0x0096
                    0097    164 _P1_7	=	0x0097
                    0098    165 _RI	=	0x0098
                    0099    166 _TI	=	0x0099
                    009A    167 _RB8	=	0x009a
                    009B    168 _TB8	=	0x009b
                    009C    169 _REN	=	0x009c
                    009D    170 _SM2	=	0x009d
                    009E    171 _SM1	=	0x009e
                    009F    172 _SM0	=	0x009f
                    00A0    173 _P2_0	=	0x00a0
                    00A1    174 _P2_1	=	0x00a1
                    00A2    175 _P2_2	=	0x00a2
                    00A3    176 _P2_3	=	0x00a3
                    00A4    177 _P2_4	=	0x00a4
                    00A5    178 _P2_5	=	0x00a5
                    00A6    179 _P2_6	=	0x00a6
                    00A7    180 _P2_7	=	0x00a7
                    00A8    181 _EX0	=	0x00a8
                    00A9    182 _ET0	=	0x00a9
                    00AA    183 _EX1	=	0x00aa
                    00AB    184 _ET1	=	0x00ab
                    00AC    185 _ES	=	0x00ac
                    00AF    186 _EA	=	0x00af
                    00B0    187 _P3_0	=	0x00b0
                    00B1    188 _P3_1	=	0x00b1
                    00B2    189 _P3_2	=	0x00b2
                    00B3    190 _P3_3	=	0x00b3
                    00B4    191 _P3_4	=	0x00b4
                    00B5    192 _P3_5	=	0x00b5
                    00B6    193 _P3_6	=	0x00b6
                    00B7    194 _P3_7	=	0x00b7
                    00B0    195 _RXD	=	0x00b0
                    00B1    196 _TXD	=	0x00b1
                    00B2    197 _INT0	=	0x00b2
                    00B3    198 _INT1	=	0x00b3
                    00B4    199 _T0	=	0x00b4
                    00B5    200 _T1	=	0x00b5
                    00B6    201 _WR	=	0x00b6
                    00B7    202 _RD	=	0x00b7
                    00B8    203 _PX0	=	0x00b8
                    00B9    204 _PT0	=	0x00b9
                    00BA    205 _PX1	=	0x00ba
                    00BB    206 _PT1	=	0x00bb
                    00BC    207 _PS	=	0x00bc
                    00D0    208 _P	=	0x00d0
                    00D1    209 _F1	=	0x00d1
                    00D2    210 _OV	=	0x00d2
                    00D3    211 _RS0	=	0x00d3
                    00D4    212 _RS1	=	0x00d4
                    00D5    213 _F0	=	0x00d5
                    00D6    214 _AC	=	0x00d6
                    00D7    215 _CY	=	0x00d7
                            216 ;--------------------------------------------------------
                            217 ; overlayable register banks
                            218 ;--------------------------------------------------------
                            219 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     220 	.ds 8
                            221 ;--------------------------------------------------------
                            222 ; internal ram data
                            223 ;--------------------------------------------------------
                            224 	.area DSEG    (DATA)
                            225 ;--------------------------------------------------------
                            226 ; overlayable items in internal ram 
                            227 ;--------------------------------------------------------
                            228 	.area OSEG    (OVR,DATA)
                            229 ;--------------------------------------------------------
                            230 ; Stack segment in internal ram 
                            231 ;--------------------------------------------------------
                            232 	.area	SSEG	(DATA)
   0008                     233 __start__stack:
   0008                     234 	.ds	1
                            235 
                            236 ;--------------------------------------------------------
                            237 ; indirectly addressable internal ram data
                            238 ;--------------------------------------------------------
                            239 	.area ISEG    (DATA)
                            240 ;--------------------------------------------------------
                            241 ; absolute internal ram data
                            242 ;--------------------------------------------------------
                            243 	.area IABS    (ABS,DATA)
                            244 	.area IABS    (ABS,DATA)
                            245 ;--------------------------------------------------------
                            246 ; bit data
                            247 ;--------------------------------------------------------
                            248 	.area BSEG    (BIT)
                            249 ;--------------------------------------------------------
                            250 ; paged external ram data
                            251 ;--------------------------------------------------------
                            252 	.area PSEG    (PAG,XDATA)
                            253 ;--------------------------------------------------------
                            254 ; external ram data
                            255 ;--------------------------------------------------------
                            256 	.area XSEG    (XDATA)
                            257 ;--------------------------------------------------------
                            258 ; absolute external ram data
                            259 ;--------------------------------------------------------
                            260 	.area XABS    (ABS,XDATA)
                            261 ;--------------------------------------------------------
                            262 ; external initialized ram data
                            263 ;--------------------------------------------------------
                            264 	.area XISEG   (XDATA)
                            265 	.area HOME    (CODE)
                            266 	.area GSINIT0 (CODE)
                            267 	.area GSINIT1 (CODE)
                            268 	.area GSINIT2 (CODE)
                            269 	.area GSINIT3 (CODE)
                            270 	.area GSINIT4 (CODE)
                            271 	.area GSINIT5 (CODE)
                            272 	.area GSINIT  (CODE)
                            273 	.area GSFINAL (CODE)
                            274 	.area CSEG    (CODE)
                            275 ;--------------------------------------------------------
                            276 ; interrupt vector 
                            277 ;--------------------------------------------------------
                            278 	.area HOME    (CODE)
   0000                     279 __interrupt_vect:
   0000 02 00 08            280 	ljmp	__sdcc_gsinit_startup
                            281 ;--------------------------------------------------------
                            282 ; global & static initialisations
                            283 ;--------------------------------------------------------
                            284 	.area HOME    (CODE)
                            285 	.area GSINIT  (CODE)
                            286 	.area GSFINAL (CODE)
                            287 	.area GSINIT  (CODE)
                            288 	.globl __sdcc_gsinit_startup
                            289 	.globl __sdcc_program_startup
                            290 	.globl __start__stack
                            291 	.globl __mcs51_genXINIT
                            292 	.globl __mcs51_genXRAMCLEAR
                            293 	.globl __mcs51_genRAMCLEAR
                            294 	.area GSFINAL (CODE)
   0061 02 00 03            295 	ljmp	__sdcc_program_startup
                            296 ;--------------------------------------------------------
                            297 ; Home
                            298 ;--------------------------------------------------------
                            299 	.area HOME    (CODE)
                            300 	.area HOME    (CODE)
   0003                     301 __sdcc_program_startup:
   0003 12 00 64            302 	lcall	_main
                            303 ;	return from main will lock up
   0006 80 FE               304 	sjmp .
                            305 ;--------------------------------------------------------
                            306 ; code
                            307 ;--------------------------------------------------------
                            308 	.area CSEG    (CODE)
                            309 ;------------------------------------------------------------
                            310 ;Allocation info for local variables in function 'main'
                            311 ;------------------------------------------------------------
                            312 ;------------------------------------------------------------
                            313 ;	Z:\AESOKZ~C\TTM7GO~I.C:5: int main(void)
                            314 ;	-----------------------------------------
                            315 ;	 function main
                            316 ;	-----------------------------------------
   0064                     317 _main:
                    0002    318 	ar2 = 0x02
                    0003    319 	ar3 = 0x03
                    0004    320 	ar4 = 0x04
                    0005    321 	ar5 = 0x05
                    0006    322 	ar6 = 0x06
                    0007    323 	ar7 = 0x07
                    0000    324 	ar0 = 0x00
                    0001    325 	ar1 = 0x01
                            326 ;	Z:\AESOKZ~C\TTM7GO~I.C:7: while(1)
   0064                     327 00102$:
                            328 ;	Z:\AESOKZ~C\TTM7GO~I.C:9: P2 = 0;
   0064 75 A0 00            329 	mov	_P2,#0x00
                            330 ;	Z:\AESOKZ~C\TTM7GO~I.C:10: Czas(10000);
   0067 90 27 10            331 	mov	dptr,#0x2710
   006A 12 00 78            332 	lcall	_Czas
                            333 ;	Z:\AESOKZ~C\TTM7GO~I.C:11: P2 = 1;
   006D 75 A0 01            334 	mov	_P2,#0x01
                            335 ;	Z:\AESOKZ~C\TTM7GO~I.C:12: Czas(10000);
   0070 90 27 10            336 	mov	dptr,#0x2710
   0073 12 00 78            337 	lcall	_Czas
   0076 80 EC               338 	sjmp	00102$
                            339 ;------------------------------------------------------------
                            340 ;Allocation info for local variables in function 'Czas'
                            341 ;------------------------------------------------------------
                            342 ;Ilosc                     Allocated to registers r2 r3 
                            343 ;i                         Allocated to registers r4 r5 
                            344 ;------------------------------------------------------------
                            345 ;	Z:\AESOKZ~C\TTM7GO~I.C:16: void Czas(unsigned int Ilosc)
                            346 ;	-----------------------------------------
                            347 ;	 function Czas
                            348 ;	-----------------------------------------
   0078                     349 _Czas:
   0078 AA 82               350 	mov	r2,dpl
   007A AB 83               351 	mov	r3,dph
                            352 ;	Z:\AESOKZ~C\TTM7GO~I.C:19: for(i = 0; i < Ilosc; i++);
   007C 7C 00               353 	mov	r4,#0x00
   007E 7D 00               354 	mov	r5,#0x00
   0080                     355 00101$:
   0080 C3                  356 	clr	c
   0081 EC                  357 	mov	a,r4
   0082 9A                  358 	subb	a,r2
   0083 ED                  359 	mov	a,r5
   0084 9B                  360 	subb	a,r3
   0085 50 07               361 	jnc	00105$
   0087 0C                  362 	inc	r4
   0088 BC 00 F5            363 	cjne	r4,#0x00,00101$
   008B 0D                  364 	inc	r5
   008C 80 F2               365 	sjmp	00101$
   008E                     366 00105$:
   008E 22                  367 	ret
                            368 	.area CSEG    (CODE)
                            369 	.area CONST   (CODE)
                            370 	.area XINIT   (CODE)
                            371 	.area CABS    (ABS,CODE)

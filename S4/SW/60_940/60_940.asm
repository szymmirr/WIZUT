ORG 0
CZAS_60 EQU 65535 - 55296 + 1
CZAS_940 EQU 65535 - 61883 + 1
D7 EQU P2.0
LICZNIK EQU R6
NrCYKL_ON  EQU 14
NrCYKL_OFF EQU 1
MOV P2,#0
MOV TMOD,#00000001B
SETB TR0

PETLA:
CLR D7
CALL CZAS_ON
CPL D7
CALL CZAS_OFF
SJMP PETLA

CZAS_ON:
MOV LICZNIK,#NrCYKL_ON

PETLA2:
MOV TH0,#HIGH CZAS_60
MOV TL0,#LOW CZAS_60
JNB TF0,$
CLR TF0
DJNZ LICZNIK,PETLA2
RET

CZAS_OFF:
MOV LICZNIK,#NrCYKL_OFF
MOV TMOD,#00000001B

SKOK:
MOV TH0,#HIGH CZAS_940
MOV TL0,#LOW CZAS_940
JNB TF0,$
CLR TF0
DJNZ LICZNIK,SKOK
RET
END
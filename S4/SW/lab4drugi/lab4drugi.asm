ORG 0
MS50 EQU 65535 - 46080 + 1
D7 EQU P2.0
LICZNIK EQU R6
LICZNIK2 EQU R6
ILE EQU 2
ILE2 EQU 18
MOV P2,#0
START:
MOV TMOD,#00000001B
SETB TR0
MOV LICZNIK,#ILE
MOV LICZNIK2,#ILE2
PETLA2:
MOV TH0,#HIGH MS50

JNB TF0,$
CLR TF0
DJNZ LICZNIK,PETLA2
PETLA3:
MOV TL0,#LOW MS50
JNB TF0,$
CLR TF0
DJNZ LICZNIK2,PETLA3

CPL D7
SJMP START
END
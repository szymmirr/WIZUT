(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: TunelPROGRAM
 * File: TunelPROGRAM.typ
 * Author: pmizo
 * Created: January 18, 2018
 ********************************************************************
 * Local data types of program TunelPROGRAM
 ********************************************************************)

TYPE
	TunelStruct : 	STRUCT 
		diCzujnikSpalin1 : BOOL := FALSE;
		diCzujnikSpalin2 : BOOL := FALSE;
		diCzujnikSpalin3 : BOOL := FALSE;
		diCzujnikSpalin4 : BOOL := FALSE;
		diEStop : BOOL := TRUE;
		diStart : BOOL := FALSE;
		diStop : BOOL := FALSE;
		doSystemAktywny : BOOL := FALSE;
		doWentylatorM3 : BOOL := FALSE;
		doWentylatorM2 : BOOL := FALSE;
		doWentylatorM1 : BOOL := FALSE;
	END_STRUCT;
END_TYPE

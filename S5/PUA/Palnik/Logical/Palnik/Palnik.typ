(********************************************************************
 * COPYRIGHT -- Microsoft
 ********************************************************************
 * Program: Palnik
 * File: Palnik.typ
 * Author: Liss_1
 * Created: January 04, 2018
 ********************************************************************
 * Local data types of program Palnik
 ********************************************************************)

TYPE
	SystemStruct : 	STRUCT 
		diStop : BOOL;
		diStart : BOOL;
		diEStop : BOOL;
		doSystemAktywny : BOOL;
	END_STRUCT;
	BurnerStruct : 	STRUCT 
		diFanStarter : BOOL;
		doAirFan : BOOL;
		diAirFlow : BOOL;
		diFlameDetector : BOOL;
		doPilotValve : BOOL;
		doMainValve : BOOL;
		doIgniter : BOOL;
	END_STRUCT;
END_TYPE

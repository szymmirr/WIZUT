(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: Ppoz
 * File: Ppoz.typ
 * Author: User
 * Created: November 16, 2017
 ********************************************************************
 * Local data types of program Ppoz
 ********************************************************************)

TYPE
	SystemStruct : 	STRUCT 
		diStop : BOOL;
		diStart : BOOL;
		uiStop : BOOL;
		uiStart : BOOL;
		uiSystemAktywny : BOOL;
		doSystemAktywny : BOOL;
		diReset : BOOL;
		uiReset : BOOL;
		doSyrena : BOOL;
		uiSyrena : BOOL;
		doKogut : BOOL;
		uiKogut : BOOL;
	END_STRUCT;
	RoomStruct : 	STRUCT 
		uiCzujnikSwiatlo : BOOL;
		uiCzujnikTemp : BOOL;
		uiTryskacz : BOOL;
		uiCzujnikDym : BOOL;
		diCzujnikSwiatlo : BOOL;
		diCzujnikTemp : BOOL;
		doTryskacz : BOOL;
		diCzujnikDym : BOOL;
	END_STRUCT;
END_TYPE

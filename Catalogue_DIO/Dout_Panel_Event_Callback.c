/*********************************************************************************************************************************
 * File name		: Dout_Panel_Event_Callback.c
 * Description		: Declare and implement the event call-back functions defined on the Dout panel.
 * Creator			: XU ZAN
 * Creation date	: Mon.	Jan. 13, 2014
 * Copyright(C)		2014	Hella Shanghai Electronics Co., Ltd.
 * All rights reserved.
 *
 *********************************************************************************************************************************/

//==============================================================================
// Include files
#include <userint.h>
#include <stdio.h>
#include "MCTBox_Diagnose_DoutPanel.h"
#include "DIO_Panel_Event_Callback.h"
#include "../misc.h"

#include "MCTBox_API_DIO.h"

//==============================================================================
// Constants

//==============================================================================
// Types																								    

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

int  CVICALLBACK CB_binswDoutBoardIDBit0_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDoutBoardID(panel, event);
}

int  CVICALLBACK CB_binswDoutBoardIDBit1_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDoutBoardID(panel, event);
}

int  CVICALLBACK CB_binswDoutBoardIDBit2_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDoutBoardID(panel, event);
}

int  CVICALLBACK CB_binswDoutBoardIDBit3_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDoutBoardID(panel, event);
}

int  CVICALLBACK CB_binswDoutBoardIDBit4_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDoutBoardID(panel, event);
}

int  CVICALLBACK CB_binswDoutBoardIDBit5_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDoutBoardID(panel, event);
}

int  CVICALLBACK CB_binswDoutBoardIDBit6_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDoutBoardID(panel, event);
}

int  CVICALLBACK CB_binswDoutBoardIDBit7_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDoutBoardID(panel, event);
}

int ChangeDoutBoardID(int hPanel, int iEvent)
{
	unsigned char ucDoutBoardID = 0x00, sDoutBoardID[8] = {0};
	int iSw0Val = 0, iSw1Val = 0, iSw2Val = 0, iSw3Val = 0, iSw4Val = 0, iSw5Val = 0, iSw6Val = 0, iSw7Val = 0;
	
	switch (iEvent)
	{
	case EVENT_COMMIT:
		GetCtrlVal(hPanel, pnlDOUT_binswDoutBoardIDBit0, &iSw0Val);
		GetCtrlVal(hPanel, pnlDOUT_binswDoutBoardIDBit1, &iSw1Val);
		GetCtrlVal(hPanel, pnlDOUT_binswDoutBoardIDBit2, &iSw2Val);  
		GetCtrlVal(hPanel, pnlDOUT_binswDoutBoardIDBit3, &iSw3Val);  
		GetCtrlVal(hPanel, pnlDOUT_binswDoutBoardIDBit4, &iSw4Val);  
		GetCtrlVal(hPanel, pnlDOUT_binswDoutBoardIDBit5, &iSw5Val);  
		GetCtrlVal(hPanel, pnlDOUT_binswDoutBoardIDBit6, &iSw6Val);  
		GetCtrlVal(hPanel, pnlDOUT_binswDoutBoardIDBit7, &iSw7Val);  
		
		ucDoutBoardID = (iSw7Val<<7) +
						(iSw6Val<<6) +
						(iSw5Val<<5) +
						(iSw4Val<<4) +
						(iSw3Val<<3) +
						(iSw2Val<<2) +
						(iSw1Val<<1) +
						(iSw0Val);
		sprintf(sDoutBoardID, "0x%02X", ucDoutBoardID);
		SetCtrlVal(hPanel, pnlDOUT_txtDoutBoardID, sDoutBoardID);
		break;
	default:
		break;
	}
	return 0;
}

int  CVICALLBACK CB_ExitDoutPanel(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
	case EVENT_COMMIT:
		QuitUserInterface(panel);
		break;
	default:
		break;
	}
	return 0;
}

int  CVICALLBACK CB_binswDoutPort10_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort10, 10);
}

int  CVICALLBACK CB_binswDoutPort11_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort11, 11);
}

int  CVICALLBACK CB_binswDoutPort12_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort12, 12);
}

int  CVICALLBACK CB_binswDoutPort13_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort13, 13);
}

int  CVICALLBACK CB_binswDoutPort14_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort14, 14);
}

int  CVICALLBACK CB_binswDoutPort15_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort15, 15);
}

int  CVICALLBACK CB_binswDoutPort16_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort16, 16);
}

int  CVICALLBACK CB_binswDoutPort17_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort17, 17);
}

int  CVICALLBACK CB_binswDoutPort18_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort18, 18);
}

int  CVICALLBACK CB_binswDoutPort19_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort19, 19);
}

int  CVICALLBACK CB_binswDoutPort1_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort1, 1);
}

int  CVICALLBACK CB_binswDoutPort20_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort20, 20);
}

int  CVICALLBACK CB_binswDoutPort21_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort21, 21);
}

int  CVICALLBACK CB_binswDoutPort22_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort22, 22);
}

int  CVICALLBACK CB_binswDoutPort23_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort23, 23);
}

int  CVICALLBACK CB_binswDoutPort24_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort24, 24);
}

int  CVICALLBACK CB_binswDoutPort2_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort2, 2);
}
int  CVICALLBACK CB_binswDoutPort3_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort3, 3);
}

int  CVICALLBACK CB_binswDoutPort4_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort4, 4);
}

int  CVICALLBACK CB_binswDoutPort5_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort5, 5);
}

int  CVICALLBACK CB_binswDoutPort6_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort6, 6);
}

int  CVICALLBACK CB_binswDoutPort7_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort7, 7);
}

int  CVICALLBACK CB_binswDoutPort8_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort8, 8);
}

int  CVICALLBACK CB_binswDoutPort9_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleDoutPort(panel, event, pnlDOUT_binswDoutPort9, 9);
}

int ControlSingleDoutPort(int hPanel, int iEvent, int iDoutPortCtrlID, int iDoutPortNr)
{
	int iResult = 0;
	int iDoutPortState = 0;
	char sDoutBoardID[8] = {0}, sError[256] = {0};
	long lDoutBoardID = 0x00;
	
	switch (iEvent)
	{
	case EVENT_COMMIT:
		GetCtrlVal(hPanel, iDoutPortCtrlID, &iDoutPortState);
		GetCtrlVal(hPanel, pnlDOUT_txtDoutBoardID, sDoutBoardID);
		
		iResult = HexStr2Long(sDoutBoardID, &lDoutBoardID, sError);
		if (iResult)
			return iResult;
		iResult = MCTBoxAPI_DIOModule_SetDoutPortHighLow(lDoutBoardID, iDoutPortNr, iDoutPortState, sError);
		if (iResult)
			return iResult;
		break;
	default:
		break;
	}
	return iResult;
}

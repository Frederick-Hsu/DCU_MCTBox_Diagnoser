/*******************************************************************************
 * File name	: Connect2MCTBox_UIEventCallback.c
 * Description	: This file is used to exclusively implement the event call-back
 *				  functions for "Connect2MCTBox" panel.
 * Creator		: XU ZAN	[HSE-OT]
 * Creation date: Wed.	Dec. 11, 2013
 * Copyright(C)		2013	Hella Shanghai Electronics Co., Ltd.
 * All rights reserved.
 *
 *******************************************************************************/

//==============================================================================
// Include files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Connect2MCTBox.h"
#include "MCTBox_API.h"
#include "utilities.h"
#include "macros.h"

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
int hPnl_Connect2MCTBox_Panel;
int g_iConnect2MCTBoxStatus = 0;

//==============================================================================
// Global functions
int  CVICALLBACK CB_ExitConnectPanel(int panel, int event, void *callbackData, int eventData1, int eventData2)
{
	int iResult = 0;
	switch (event)
	{
	case EVENT_CLOSE:
		iResult = QuitUserInterface(0);
		break;
	default:
		break;
	}
	return iResult;
}

int  CVICALLBACK CB_Connect2MCTBox(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int iResult = 0;
	char sError[256] = {0}, sComError[256] = {0}, sComPortNr[16] = {0}, sIntermediateComPortNr[16] = {0};
	char sMCTBoxResponse[256] = {0};
	int iComPortNr = 0;
	
	switch (event)
	{
	case EVENT_COMMIT:
		GetCtrlVal(hPnl_Connect2MCTBox_Panel, PnlConnect_strSerialPortNr, sComPortNr);
		if (!strnicmp(sComPortNr, "COM", 3))
		{
			strncpy(sIntermediateComPortNr, sComPortNr+3, strlen(sComPortNr)-3);
			iComPortNr = atoi(sIntermediateComPortNr);
		}
		else if (TestDigitString(sComPortNr))
		{											  
			iComPortNr = atoi(sComPortNr);
		}
		else
		{
			MessagePopup("Error", "The serial port number you entered is error.\nEnter again!");
			return -1;
		}
		/* Connect to MCTBox instrument and 
		 * initialize it through serial port.
		 */
		iResult = MCTBoxAPI_Init(iComPortNr, sComError);
		if (iResult != 0)
		{
			sprintf(sError, "Failed to connect to MCTBox instrument. \n\n%s", sComError);
			MessagePopup("Error", sError);
			QuitUserInterface(0);
			return iResult;
		}
		
		/* Say Hello to MCTBox instrument, to prove that
		 * MCTBox is alive and response well.
		 */
		iResult = MCTBoxAPI_SayHello2MCTBox(sMCTBoxResponse);
		if (0 == strlen(sMCTBoxResponse))
		{
			MessagePopup("Error", "Fail to get response from MCTBox!");
			QuitUserInterface(0);
			return iResult;
		}
		MessagePopup("Success", sMCTBoxResponse);
		g_iConnect2MCTBoxStatus = CONNECTED_2_MCTBOX_OK;
		
		/*
		 * Enable the MCTBox controllable features here.
		 * To be implemented later.
		 *
		 * Remarked by XU ZAN@2013-12-14
		 */
		
		QuitUserInterface(0);
		
		break;
	default:
		break;
	}
	return iResult;
}


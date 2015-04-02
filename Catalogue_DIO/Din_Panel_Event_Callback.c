/***************************************************************************************************************
 * File name		: Din_Panel_Event_Callback.c
 * Description		: To implement the event call-back functions on the Digital-IN panel.
 * Creator			: XU ZAN	[HSE-OT]
 * Creation date	: Tue.	Jan. 14, 2014
 * Copyright(C)		2014	Hella Shanghai Electronics Co., Ltd.
 * All rights reserved.
 *
 ***************************************************************************************************************/

//==============================================================================
// Include files
#include "asynctmr.h"
#include <stdio.h>
#include "MCTBox_Diagnose_DinPanel.h"
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
int iAsync_Timer_CtrlID = 0;

//==============================================================================
// Global functions
int  CVICALLBACK CB_ExitDinPanel(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
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

int  CVICALLBACK CB_binswDinBoardIDBit0_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDinBoardID(panel, event); 
}

int  CVICALLBACK CB_binswDinBoardIDBit1_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDinBoardID(panel, event); 
}

int  CVICALLBACK CB_binswDinBoardIDBit2_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDinBoardID(panel, event); 
}

int  CVICALLBACK CB_binswDinBoardIDBit3_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDinBoardID(panel, event); 
}

int  CVICALLBACK CB_binswDinBoardIDBit4_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDinBoardID(panel, event); 
}

int  CVICALLBACK CB_binswDinBoardIDBit5_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDinBoardID(panel, event); 
}

int  CVICALLBACK CB_binswDinBoardIDBit6_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDinBoardID(panel, event); 
}

int  CVICALLBACK CB_binswDinBoardIDBit7_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeDinBoardID(panel, event); 
}

int ChangeDinBoardID(int hPanel, int iEvent)
{
	unsigned char ucDinBoardID = 0x00, sDinBoardID[8] = {0};
	int iSw0Val = 0, iSw1Val = 0, iSw2Val = 0, iSw3Val = 0, iSw4Val = 0, iSw5Val = 0, iSw6Val = 0, iSw7Val = 0;
	
	switch (iEvent)
	{
	case EVENT_COMMIT:
		GetCtrlVal(hPanel, pnlDIN_binswDinBoardIDBit0, &iSw0Val);
		GetCtrlVal(hPanel, pnlDIN_binswDinBoardIDBit1, &iSw1Val);
		GetCtrlVal(hPanel, pnlDIN_binswDinBoardIDBit2, &iSw2Val);  
		GetCtrlVal(hPanel, pnlDIN_binswDinBoardIDBit3, &iSw3Val);  
		GetCtrlVal(hPanel, pnlDIN_binswDinBoardIDBit4, &iSw4Val);  
		GetCtrlVal(hPanel, pnlDIN_binswDinBoardIDBit5, &iSw5Val);  
		GetCtrlVal(hPanel, pnlDIN_binswDinBoardIDBit6, &iSw6Val);  
		GetCtrlVal(hPanel, pnlDIN_binswDinBoardIDBit7, &iSw7Val);  
		
		ucDinBoardID =  (iSw7Val<<7) +
						(iSw6Val<<6) +
						(iSw5Val<<5) +
						(iSw4Val<<4) +
						(iSw3Val<<3) +
						(iSw2Val<<2) +
						(iSw1Val<<1) +
						(iSw0Val);
		sprintf(sDinBoardID, "0x%02X", ucDinBoardID);
		SetCtrlVal(hPanel, pnlDIN_txtDinBoardID, sDinBoardID);
		break;
	default:
		break;
	}
	return 0;
}

/****************************************************************************************************************************************************************************************/
static unsigned long g_ulDinBoardID = 0x00;
static int hCurrentPanelHandle = 0;

int  CVICALLBACK CB_StartContinuousQueryDinPortState(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int iError = 0;
	char sDinBoardID[16] = {0}, sError[256] = {0};
	
	switch (event)
	{
	case EVENT_COMMIT:
		hCurrentPanelHandle = panel;	// Reserve the panel handle.
		{	// Set the controls of Board ID dimmed, forbid to change board ID during countinuous quering.
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit0, ATTR_DIMMED, 1);
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit1, ATTR_DIMMED, 1);
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit2, ATTR_DIMMED, 1);
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit3, ATTR_DIMMED, 1);
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit4, ATTR_DIMMED, 1);
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit5, ATTR_DIMMED, 1);
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit6, ATTR_DIMMED, 1);
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit7, ATTR_DIMMED, 1);
			
			// Set myself dimmed, enable the opposite object
			SetCtrlAttribute(panel, pnlDIN_picbtnStart, ATTR_DIMMED, 1);
			SetCtrlAttribute(panel, pnlDIN_picbtnStop, ATTR_DIMMED, 0);
			
			SetCtrlAttribute(panel, pnlDIN_cmdbtnDinExit, ATTR_DIMMED, 1);
		}
		GetCtrlVal(panel, pnlDIN_txtDinBoardID, sDinBoardID);
		iError = HexStr2Long(sDinBoardID, &g_ulDinBoardID, sError);
		if (iError)
		{
			MessagePopup("Error", sError);
			return iError;
		}
		
		/* 
		 * Start the async timer :
		 */
		ResumeAsyncTimerCallbacks();
		break;
	default:
		break;
	}
	return 0;
}

int  CVICALLBACK CB_StopContinuousQueryDinPortState(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
	case EVENT_COMMIT:
		/*
		 * Stop the async timer
		 */
		SuspendAsyncTimerCallbacks();
		
		{	// Set the controls of Board ID dimmed, forbid to change board ID during countinuous quering.
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit0, ATTR_DIMMED, 0);
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit1, ATTR_DIMMED, 0);
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit2, ATTR_DIMMED, 0);
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit3, ATTR_DIMMED, 0);
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit4, ATTR_DIMMED, 0);
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit5, ATTR_DIMMED, 0);
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit6, ATTR_DIMMED, 0);
			SetCtrlAttribute(panel, pnlDIN_binswDinBoardIDBit7, ATTR_DIMMED, 0);
			
			// Set myself dimmed, enable the opposite object
			SetCtrlAttribute(panel, pnlDIN_picbtnStop, ATTR_DIMMED, 1);
			SetCtrlAttribute(panel, pnlDIN_picbtnStart, ATTR_DIMMED, 0);
			
			SetCtrlAttribute(panel, pnlDIN_cmdbtnDinExit, ATTR_DIMMED, 0);
		}   
		
		// Turn Off all LEDs
		for (int iCnt=1; iCnt<=24; iCnt++)
		{
			TurnOnOffCurrentLED_ByChannelNr(panel, iCnt, LOW);
		}
		break;
	default:
		break;
	}
	return 0;
}

int CVICALLBACK CB_AsyncTimerContinuousQueryDinPortState(int 	iReserved,
														 int 	iAsyncTimerID,
														 int 	event,
														 void 	*callbackData,
														 int 	eventData1,
														 int 	eventData2)
{
	int iCnt = 0, iError = 0;
	EState eCurrentDinPortState = OFF, eDin24PortsState[24] = {OFF};
	char sError[256] = {0};
	
	switch (event)
	{
	case EVENT_TIMER_TICK:
#if 0
		for (iCnt=1; iCnt<=24; iCnt++)
		{
			// ProcessSystemEvents();
			iError = MCTBoxAPI_DIOModule_QueryDinPortState(g_ulDinBoardID, iCnt, &eCurrentDinPortState, sError);
			if (iError)
			{
				MessagePopup("Error", sError);
				return -1;
			}
			/* 
			 * Set current LED's state
			 */
			TurnOnOffCurrentLED_ByChannelNr(hCurrentPanelHandle, iCnt, eCurrentDinPortState);
		}
#else
		iError = MCTBoxAPI_DIOModule_ParallelQueryDin24PortsState(eDin24PortsState, sError);
		if (iError)
		{
			MessagePopup("Error", sError);
			return -1;
		}
		for (iCnt=1; iCnt<=24; iCnt++)
		{
			TurnOnOffCurrentLED_ByChannelNr(hCurrentPanelHandle, iCnt, eDin24PortsState[iCnt-1]);
		}
#endif
		break;
	default:
		break;
	}
	return 0;
}

void TurnOnOffCurrentLED_ByChannelNr(int hPanel, int iChannelNr, int iState)
{
	switch (iChannelNr)
	{
	case  1: TurnOnOffCurrentLED(hPanel,  pnlDIN_ledDinPort1, iState); break;
	case  2: TurnOnOffCurrentLED(hPanel,  pnlDIN_ledDinPort2, iState); break;
	case  3: TurnOnOffCurrentLED(hPanel,  pnlDIN_ledDinPort3, iState); break;
	case  4: TurnOnOffCurrentLED(hPanel,  pnlDIN_ledDinPort4, iState); break;
	case  5: TurnOnOffCurrentLED(hPanel,  pnlDIN_ledDinPort5, iState); break;
	case  6: TurnOnOffCurrentLED(hPanel,  pnlDIN_ledDinPort6, iState); break;
	case  7: TurnOnOffCurrentLED(hPanel,  pnlDIN_ledDinPort7, iState); break;
	case  8: TurnOnOffCurrentLED(hPanel,  pnlDIN_ledDinPort8, iState); break;
	case  9: TurnOnOffCurrentLED(hPanel,  pnlDIN_ledDinPort9, iState); break;
	case 10: TurnOnOffCurrentLED(hPanel, pnlDIN_ledDinPort10, iState); break;
	case 11: TurnOnOffCurrentLED(hPanel, pnlDIN_ledDinPort11, iState); break;
	case 12: TurnOnOffCurrentLED(hPanel, pnlDIN_ledDinPort12, iState); break;
	case 13: TurnOnOffCurrentLED(hPanel, pnlDIN_ledDinPort13, iState); break;
	case 14: TurnOnOffCurrentLED(hPanel, pnlDIN_ledDinPort14, iState); break;
	case 15: TurnOnOffCurrentLED(hPanel, pnlDIN_ledDinPort15, iState); break;
	case 16: TurnOnOffCurrentLED(hPanel, pnlDIN_ledDinPort16, iState); break;
	case 17: TurnOnOffCurrentLED(hPanel, pnlDIN_ledDinPort17, iState); break;
	case 18: TurnOnOffCurrentLED(hPanel, pnlDIN_ledDinPort18, iState); break;
	case 19: TurnOnOffCurrentLED(hPanel, pnlDIN_ledDinPort19, iState); break;
	case 20: TurnOnOffCurrentLED(hPanel, pnlDIN_ledDinPort20, iState); break;
	case 21: TurnOnOffCurrentLED(hPanel, pnlDIN_ledDinPort21, iState); break;
	case 22: TurnOnOffCurrentLED(hPanel, pnlDIN_ledDinPort22, iState); break;
	case 23: TurnOnOffCurrentLED(hPanel, pnlDIN_ledDinPort23, iState); break;
	case 24: TurnOnOffCurrentLED(hPanel, pnlDIN_ledDinPort24, iState); break;
	default:                                                           break;
	}
	return;
}

void TurnOnOffCurrentLED(int hPanel, int iLedCtrlID, int iState)
{
	if (iState == ON)
		SetCtrlAttribute(hPanel, iLedCtrlID, ATTR_OFF_COLOR, VAL_GREEN);
	else if (iState == OFF)
		SetCtrlAttribute(hPanel, iLedCtrlID, ATTR_OFF_COLOR, VAL_BLACK);
	return;
}

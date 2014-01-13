/***********************************************************************************************************************
 * Module			: Catalogue_SwitchControl
 * Description		: This module will implement the functions in the "Switch Control" panel.
 * =====================================================================================================================
 * File name		: Switch_Control.c
 * Description		: To collect and implement the event call-back functions.
 * Creator			: XU ZAN
 * Creation date	: Thur.	Dec. 19, 2013
 * Copyright(C)		2013	Hella Shanghai Electronics Co., Ltd.
 * All rights reserved.
 *
 ***********************************************************************************************************************/

//==============================================================================
// Include files
#include <stdio.h>
#include "Switch_Control.h"		
#include "../macros.h"
#include "MCTBox_Diagnose_SwitchControlPanel.h"
#include "MCTBox_API_SwitchControl.h"
#include "../misc.h"

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
hPnl_t hPnl_SwitchCtrl = 0;

//==============================================================================
// Global functions

int  CVICALLBACK CB_ExitSwitchControlPanel(int panel, int event, void *callbackData, int eventData1, int eventData2)
{
	int iResult = 0;
	switch (event)
	{
	case EVENT_CLOSE:
		QuitUserInterface(panel);
		break;
	default:
		break;
	}
	return iResult;
}

int  CVICALLBACK CB_CloseSwitchCtrlPanel(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
	case EVENT_COMMIT:
		QuitUserInterface(panel);	// To return the panel handle which you want to close
		break;
	default:
		break;
	}
	return 0;
}

int  CVICALLBACK CB_binswBoardIDBit0_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeBoardID(panel, event);
}

int  CVICALLBACK CB_binswBoardIDBit1_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeBoardID(panel, event);
}

int  CVICALLBACK CB_binswBoardIDBit2_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeBoardID(panel, event);
}

int  CVICALLBACK CB_binswBoardIDBit3_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeBoardID(panel, event);
}

int  CVICALLBACK CB_binswBoardIDBit4_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeBoardID(panel, event);
}

int  CVICALLBACK CB_binswBoardIDBit5_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeBoardID(panel, event);
}

int  CVICALLBACK CB_binswBoardIDBit6_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{	
	return ChangeBoardID(panel, event);
}

int  CVICALLBACK CB_binswBoardIDBit7_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ChangeBoardID(panel, event);
}

int ChangeBoardID(int hPanel, int iEvent)
{
	unsigned char ucBoardID = 0x00, sBoardID[8] = {0};
	int iCurrentSw0Value = 0,
		iCurrentSw1Value = 0,
		iCurrentSw2Value = 0,
		iCurrentSw3Value = 0,
		iCurrentSw4Value = 0,
		iCurrentSw5Value = 0,
		iCurrentSw6Value = 0,
		iCurrentSw7Value = 0;
	
	switch (iEvent)
	{
	case EVENT_COMMIT:
		GetCtrlVal(hPanel, pnlSwitch_binswBoardIDBit0, &iCurrentSw0Value);
		{	// Other 7 binary switch
			GetCtrlVal(hPanel, pnlSwitch_binswBoardIDBit1, &iCurrentSw1Value);
			GetCtrlVal(hPanel, pnlSwitch_binswBoardIDBit2, &iCurrentSw2Value);
			GetCtrlVal(hPanel, pnlSwitch_binswBoardIDBit3, &iCurrentSw3Value); 
			GetCtrlVal(hPanel, pnlSwitch_binswBoardIDBit4, &iCurrentSw4Value); 
			GetCtrlVal(hPanel, pnlSwitch_binswBoardIDBit5, &iCurrentSw5Value); 
			GetCtrlVal(hPanel, pnlSwitch_binswBoardIDBit6, &iCurrentSw6Value); 
			GetCtrlVal(hPanel, pnlSwitch_binswBoardIDBit7, &iCurrentSw7Value); 
		}   
		
		ucBoardID = (iCurrentSw7Value<<7) + 
					(iCurrentSw6Value<<6) +
					(iCurrentSw5Value<<5) +
					(iCurrentSw4Value<<4) +
					(iCurrentSw3Value<<3) +
					(iCurrentSw2Value<<2) +
					(iCurrentSw1Value<<1) +
					(iCurrentSw0Value);
		
		sprintf(sBoardID, "0x%02X", ucBoardID);
		SetCtrlVal(hPanel, pnlSwitch_txtBoardID, sBoardID);
		break;
	default:
		break;
	}
	return 0;
}


int  CVICALLBACK CB_binSwitch1_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch1, pnlSwitch_ledSwitch1, 1);
}

int ControlSingleSwitch(int hPanel, int iEvent, int iSwitchCtrl, int iLedCtrl, int iSwitchChannel)
{
	int iError = 0;
	int iSwitchState = 0;
	char sError[256] = {0};
	unsigned char sBoardID[32] = {0};
	long lBoardID = 0x00L;
	
	switch (iEvent)
	{
	case EVENT_COMMIT:
		GetCtrlVal(hPanel, iSwitchCtrl, &iSwitchState);
		GetCtrlVal(hPanel, pnlSwitch_txtBoardID, sBoardID);
		
		iError = HexStr2Long(sBoardID, &lBoardID, sError);
		if (iError)
			return iError;
		
		iError = MCTBoxAPI_SwitchModule_OpenCloseSwitch(lBoardID, iSwitchChannel, iSwitchState, sError);
		if (iError)
			return iError;
		if (iSwitchState == 1)
			SetCtrlAttribute(hPanel, iLedCtrl, ATTR_OFF_COLOR, VAL_GREEN);
		else if (iSwitchState == 0)
			SetCtrlAttribute(hPanel, iLedCtrl, ATTR_OFF_COLOR, VAL_BLACK);
		break;
	default:
		break;
	}
	
	return iError;
}

int  CVICALLBACK CB_binSwitch2_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch2, pnlSwitch_ledSwitch2, 2);
}

int  CVICALLBACK CB_binSwitch3_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch3, pnlSwitch_ledSwitch3, 3);
}

int  CVICALLBACK CB_binSwitch4_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch4, pnlSwitch_ledSwitch4, 4);
}

int  CVICALLBACK CB_binSwitch5_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch5, pnlSwitch_ledSwitch5, 5);
}

int  CVICALLBACK CB_binSwitch6_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch6, pnlSwitch_ledSwitch6, 6);
}

int  CVICALLBACK CB_binSwitch7_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch7, pnlSwitch_ledSwitch7, 7);
}

int  CVICALLBACK CB_binSwitch8_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch8, pnlSwitch_ledSwitch8, 8);
}

int  CVICALLBACK CB_binSwitch9_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch9, pnlSwitch_ledSwitch9, 9);
}

int  CVICALLBACK CB_binSwitch10_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch10, pnlSwitch_ledSwitch10, 10);
}

int  CVICALLBACK CB_binSwitch11_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch11, pnlSwitch_ledSwitch11, 11);
}

int  CVICALLBACK CB_binSwitch12_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch12, pnlSwitch_ledSwitch12, 12);
}

int  CVICALLBACK CB_binSwitch13_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch13, pnlSwitch_ledSwitch13, 13);
}

int  CVICALLBACK CB_binSwitch14_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch14, pnlSwitch_ledSwitch14, 14);
}

int  CVICALLBACK CB_binSwitch15_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch15, pnlSwitch_ledSwitch15, 15);
}

int  CVICALLBACK CB_binSwitch16_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch16, pnlSwitch_ledSwitch16, 16);
}

int  CVICALLBACK CB_binSwitch17_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch17, pnlSwitch_ledSwitch17, 17);
}

int  CVICALLBACK CB_binSwitch18_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch18, pnlSwitch_ledSwitch18, 18);
}

int  CVICALLBACK CB_binSwitch19_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch19, pnlSwitch_ledSwitch19, 19);
}

int  CVICALLBACK CB_binSwitch20_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch20, pnlSwitch_ledSwitch20, 20);
}

int  CVICALLBACK CB_binSwitch21_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch21, pnlSwitch_ledSwitch21, 21);
}

int  CVICALLBACK CB_binSwitch22_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch22, pnlSwitch_ledSwitch22, 22);
}

int  CVICALLBACK CB_binSwitch23_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch23, pnlSwitch_ledSwitch23, 23);
}

int  CVICALLBACK CB_binSwitch24_OnClick(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	return ControlSingleSwitch(panel, event, pnlSwitch_binSwitch24, pnlSwitch_ledSwitch24, 24);
}









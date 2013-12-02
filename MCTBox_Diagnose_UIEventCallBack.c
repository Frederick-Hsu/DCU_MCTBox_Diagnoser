/******************************************************************************
 * File name	: MCTBox_Diagnose_UIEventCallBack.c
 * Description	: This file is used to implement the UI event call-back 
 * 				  functions for MCTBox_Diagnose tool.
 * Creator		: XU ZAN	[HSE-OT]
 * Creation date: Mon.	Dec. 02, 2013
 * Copyright(C)		2013	Hella Shanghai Electronics Co., Ltd.
 * All rights reserved.
 *
 ******************************************************************************/

//==============================================================================
// Include files
#include "MCTBox_Diagnose.h"

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
int  CVICALLBACK CB_MCTBoxDiagnose_Exit(int panel, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
	case EVENT_CLOSE:
		QuitUserInterface(0);
		break;
	default:
		break;
	}
	return 0;
}

void CVICALLBACK CB_MenuFile_Connect(int menubar, int menuItem, void *callbackData, int panel)
{
}

void CVICALLBACK CB_MenuFile_Disconnect(int menubar, int menuItem, void *callbackData, int panel)
{
}

void CVICALLBACK CB_MenuFile_Exit(int menubar, int menuItem, void *callbackData, int panel)
{
}

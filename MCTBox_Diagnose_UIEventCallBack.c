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
#include <windows.h>
#include "asynctmr.h"

#include "MCTBox_Diagnose.h"
#include "Connect2MCTBox.h"
#include "MCTBox_API.h"
#include "macros.h"
#include "Catalogue_SwitchControl/MCTBox_Diagnose_SwitchControlPanel.h"
#include "Catalogue_DIO/MCTBox_Diagnose_DoutPanel.h"
#include "Catalogue_DIO/DIO_Panel_Event_Callback.h"

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
extern int MCTBox_Diagnose_Utility_Panel;	// Parent panel : Main UI ==> MCTBox_Diagnose.uir
extern int hPnl_Connect2MCTBox_Panel;		// Child panel  : Connect2MCTBox.uir
extern hPnl_t hPnl_SwitchCtrl;				// Child panel  : MCTBox_Diagnose_SwitchControlPanel.uir

extern int iAsync_Timer_CtrlID;

//==============================================================================
// Global functions

/****************************    "File" menu    ********************************/
int  CVICALLBACK CB_MCTBoxDiagnose_Exit(int panel, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
	case EVENT_CLOSE:
		QuitUserInterface(panel);
		break;
	default:
		break;
	}
	return 0;
}

void CVICALLBACK CB_MenuFile_Connect(int menubar, int menuItem, void *callbackData, int panel)
{
	int hPanel = 0;
	if ( (hPnl_Connect2MCTBox_Panel = LoadPanel(0, "Connect2MCTBox.uir", PnlConnect)) < 0 )
	{
		MessagePopup("Error", "Fail to load the 'Connect to MCTBox' panel!");
		return;
	}
	DisplayPanel(hPnl_Connect2MCTBox_Panel);
	hPanel = RunUserInterface();
	DiscardPanel(hPnl_Connect2MCTBox_Panel);
	// DiscardPanel(hPanel);
	
	SetMenuBarAttribute(menubar, MENUBAR_Menu_Catalogue, ATTR_DIMMED, 0);
	SetMenuBarAttribute(menubar, MENUBAR_Menu_Calibrate, ATTR_DIMMED, 0);
	
	SetMenuBarAttribute(menubar, MENUBAR_Menu_File_Connect, ATTR_DIMMED, 1);
	SetMenuBarAttribute(menubar, MENUBAR_Menu_File_Disconnect, ATTR_DIMMED, 0); 
	return;
}

void CVICALLBACK CB_MenuFile_Disconnect(int menubar, int menuItem, void *callbackData, int panel)
{
	int iResult = 0;
	char sError[256] = "";
	iResult = MCTBoxAPI_Exit(sError);
	if (iResult)
	{
		MessagePopup("Error", sError);
		return;
	}
	MessagePopup("Byebye", "Already disconnected with MCTBox.\n\nByebye!");
	
	/* Disable / Grey the MCTBox control panel.
	 * To be implemented later.
	 *
	 * Remarked by XU ZAN@2013-12-14
	 */
	SetMenuBarAttribute(menubar, MENUBAR_Menu_Catalogue, ATTR_DIMMED, 1);
	SetMenuBarAttribute(menubar, MENUBAR_Menu_Calibrate, ATTR_DIMMED, 1);
	
	SetMenuBarAttribute(menubar, MENUBAR_Menu_File_Connect, ATTR_DIMMED, 0);
	SetMenuBarAttribute(menubar, MENUBAR_Menu_File_Disconnect, ATTR_DIMMED, 1);
	return;
}

void CVICALLBACK CB_MenuFile_Exit(int menubar, int menuItem, void *callbackData, int panel)
{
	QuitUserInterface(panel);
}


/****************************    "Catalogue" menu    ********************************/   
void CVICALLBACK CB_MenuCatalogueSwitchCtrl_DisplaySwitchCtrlPanel(int menubar, int menuItem, void *callbackData, int panel)
{
	int hPanelWhichYouWantToClose = 0;
	HWND hParentWindow_MCTBoxMainPnl = NULL, hChildWindow_SwitchCtrlPnl = NULL;
	
	hPnl_t hCurrentPanel = 0;
	
	if ((hCurrentPanel = LoadPanel(MCTBox_Diagnose_Utility_Panel, "MCTBox_Diagnose_SwitchControlPanel.uir", pnlSwitch)) < 0)
	{
		MessagePopup("Error", "Failed to load the Switch Control Panel!");
		return;		// out of memory
	}

	/* 
	 * Get the window handle for both "MCTBox_Diagnose_Utility_Panel" and "hPnl_SwitchCtrl"
	 */
	GetPanelAttribute(MCTBox_Diagnose_Utility_Panel, ATTR_SYSTEM_WINDOW_HANDLE, (int *)&hParentWindow_MCTBoxMainPnl);
	GetPanelAttribute(hCurrentPanel, ATTR_SYSTEM_WINDOW_HANDLE, (int *)&hChildWindow_SwitchCtrlPnl);
	SetParent(hChildWindow_SwitchCtrlPnl, hParentWindow_MCTBoxMainPnl);
	
	DisplayPanel(hCurrentPanel);
	hPanelWhichYouWantToClose = RunUserInterface();
	DiscardPanel(hPanelWhichYouWantToClose);
	return;
}

void CVICALLBACK CB_MenuCatalogueDout_DisplayDoutPanel(int menubar, int menuItem, void *callbackData, int panel)
{
	int hDoutPanelWhichYouWant2Close = 0;
	HWND hParent_MainPnl = NULL, hChild_DoutPnl = NULL;
	
	hPnl_t hDoutPanel = 0;
	if ((hDoutPanel = LoadPanel(MCTBox_Diagnose_Utility_Panel, "MCTBox_Diagnose_DoutPanel.uir", pnlDOUT))<0)
	{
		MessagePopup("Error", "Failed to load the Digital-OUT Panel!");
		return;
	}
	
	GetPanelAttribute(MCTBox_Diagnose_Utility_Panel, ATTR_SYSTEM_WINDOW_HANDLE, (int *)&hParent_MainPnl);
	GetPanelAttribute(hDoutPanel, ATTR_SYSTEM_WINDOW_HANDLE, (int *)&hChild_DoutPnl);
	SetParent(hChild_DoutPnl, hParent_MainPnl);
	
	DisplayPanel(hDoutPanel);
	hDoutPanelWhichYouWant2Close = RunUserInterface();
	DiscardPanel(hDoutPanelWhichYouWant2Close);
	return;
}

static int iOpenFlagOfMultiDinPanels = 0;

void CVICALLBACK CB_MenuCatalogueDin_DisplayDinPanel(int menubar, int menuItem, void *callbackData, int panel)
{
	int hDinPanelWhichYouWant2Close = 0;
	HWND hParent_MainPnl = NULL, hChild_DinPnl = NULL;
	
	hPnl_t hDinPanel = 0;
	if (iOpenFlagOfMultiDinPanels == 0)
	{
		if ((hDinPanel = LoadPanel(MCTBox_Diagnose_Utility_Panel, "MCTBox_Diagnose_DinPanel.uir", pnlDOUT))<0)
		{
			MessagePopup("Error", "Failed to load the Digital-IN Panel!");
			return;
		}
		iOpenFlagOfMultiDinPanels = 1;	// It indicates that 1 DIN panel had been already created. 
	
		GetPanelAttribute(MCTBox_Diagnose_Utility_Panel, ATTR_SYSTEM_WINDOW_HANDLE, (int *)&hParent_MainPnl);
		GetPanelAttribute(hDinPanel, ATTR_SYSTEM_WINDOW_HANDLE, (int *)&hChild_DinPnl);
		SetParent(hChild_DinPnl, hParent_MainPnl);
	
		{	// Create a new asynchronous timer, and suspend it at the beginning phase.
			iAsync_Timer_CtrlID = NewAsyncTimer(1.0, -1, 1, CB_AsyncTimerContinuousQueryDinPortState, 0);
			SuspendAsyncTimerCallbacks();
		}
	
		DisplayPanel(hDinPanel);
		hDinPanelWhichYouWant2Close = RunUserInterface();
		DiscardPanel(hDinPanelWhichYouWant2Close);
	
		DiscardAsyncTimer(iAsync_Timer_CtrlID);
		
		/*
		 * Set the flag to avoid opening multi DIN panels.
		 * Why forbid opening multi DIN panels, that was limited by the feature of Async timer.
		 * But only 1 DIN panel can accommodate the Digital-IN acquiring capability. 
		 *
		 * Remarked by XU ZAN@2014-01-24
		 */
		iOpenFlagOfMultiDinPanels = 0;
	}
	
	return;
}

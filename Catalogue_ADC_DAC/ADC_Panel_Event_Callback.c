/*******************************************************************************************************************
 * File name		: ADC_Panel_Event_Callback.c
 * Description		: This file will implement the event call-back functions in ADC panel.
 * Creator			: XU ZAN
 * Creation date	: Wed.	Feb. 19, 2014
 * Copyright(C)		2014	Hella Shanghai Electronics Co., Ltd.
 * All rights reserved.
 *
 *******************************************************************************************************************/

//==============================================================================
// Include files
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "MCTBox_Diagnose_ADCPanel.h"
#include "MCTBox_API_AIO.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions
int MeasureDispalyCurrentValue(int hPnl, 
							   /* int iEvent, */
							   int iCH,					  
							   int iShuntResistorCtrl, 
							   int iVoltageValueCtrl,
							   int iCurrentValueCtrl);

//==============================================================================
// Global variables

//==============================================================================
// Global functions

int  CVICALLBACK CB_ExitADCPnl(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
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

int  CVICALLBACK CB_Measure8VoltagesByADC(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int iResult = 0;
	double d8Voltages[8] = {0.00};
	char s8VoltagesValue[8][64] = {{0}}, sError[256] = "";
	
	switch (event)
	{
	case EVENT_COMMIT:
		iResult = MCTBoxAPI_AIOModule_AcquireVoltagesOfAll8Channels(d8Voltages, sError);
		for (int i=0; i<8; i++)
		{
			sprintf((s8VoltagesValue)[i], "%.09f", d8Voltages[i]);
		}
		
		SetCtrlVal(panel, pnlADC_txtVoltage1, s8VoltagesValue[0]);
		SetCtrlVal(panel, pnlADC_txtVoltage2, s8VoltagesValue[1]);
		SetCtrlVal(panel, pnlADC_txtVoltage3, s8VoltagesValue[2]);
		SetCtrlVal(panel, pnlADC_txtVoltage4, s8VoltagesValue[3]);
		SetCtrlVal(panel, pnlADC_txtVoltage5, s8VoltagesValue[4]);
		SetCtrlVal(panel, pnlADC_txtVoltage6, s8VoltagesValue[5]);
		SetCtrlVal(panel, pnlADC_txtVoltage7, s8VoltagesValue[6]);
		SetCtrlVal(panel, pnlADC_txtVoltage8, s8VoltagesValue[7]);
		break;
	default:
		break;
	}
	
	return iResult;
}

int MeasureDispalyCurrentValue(int hPnl, 
							   /* int iEvent, */
							   int iCH,					  
							   int iShuntResistorCtrl, 
							   int iVoltageValueCtrl,
							   int iCurrentValueCtrl)
{
	int iResult = 0;
	char sError[256] = {0}, sCurrentValue[64] = {0}, sVoltageValue[64] = {0};
	double dShuntResistor = 0.00f, dCurrentValue = 0.00f, dVoltageValue = 0.00f;
	
	{
		GetCtrlVal(hPnl, iShuntResistorCtrl, &dShuntResistor);
		if (dShuntResistor<=0.0001)
		{
			MessagePopup("Error", "Please enter the correct shunt resistor value.");
			return -1;
		}
		
		iResult = MCTBoxAPI_AIOModule_AcquireVoltageOfAdcChannel(iCH, &dVoltageValue, sError);
		iResult = MCTBoxAPI_AIOModule_AcquireCurrentOfAdcChannel(iCH, dShuntResistor, &dCurrentValue, sError);
		if (iResult)
		{
			MessagePopup("Error", sError);
			return iResult;
		}
		sprintf(sVoltageValue, "%.09f", dVoltageValue);
		sprintf(sCurrentValue, "%.09f", dCurrentValue);
		SetCtrlVal(hPnl, iVoltageValueCtrl, sVoltageValue);
		SetCtrlVal(hPnl, iCurrentValueCtrl, sCurrentValue);
	}
	return iResult;
}
int  CVICALLBACK CB_MeasureCH1Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int iResult = 0;
	switch (event)
	{
	case EVENT_COMMIT:
		iResult = MeasureDispalyCurrentValue(panel, 1, pnlADC_numShuntResistor1, pnlADC_txtVoltage1, pnlADC_txtCurrentValue1);
		break;
	default:
		break;
	}
	return iResult;
}

int  CVICALLBACK CB_MeasureCH2Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int iResult = 0;
	switch (event)
	{
	case EVENT_COMMIT:
		iResult = MeasureDispalyCurrentValue(panel, 2, pnlADC_numShuntResistor2, pnlADC_txtVoltage2, pnlADC_txtCurrentValue2);
		break;
	default:
		break;
	}
	return iResult;
}

int  CVICALLBACK CB_MeasureCH3Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int iResult = 0;
	switch (event)
	{
	case EVENT_COMMIT:
		iResult = MeasureDispalyCurrentValue(panel, 3, pnlADC_numShuntResistor3, pnlADC_txtVoltage3, pnlADC_txtCurrentValue3);
		break;
	default:
		break;
	}
	return iResult;
}

int  CVICALLBACK CB_MeasureCH4Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int iResult = 0;
	switch (event)
	{
	case EVENT_COMMIT:
		iResult = MeasureDispalyCurrentValue(panel, 4, pnlADC_numShuntResistor4, pnlADC_txtVoltage4, pnlADC_txtCurrentValue4);
		break;
	default:
		break;
	}
	return iResult;
}

int  CVICALLBACK CB_MeasureCH5Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int iResult = 0;
	switch (event)
	{
	case EVENT_COMMIT:
		iResult = MeasureDispalyCurrentValue(panel, 5, pnlADC_numShuntResistor5, pnlADC_txtVoltage5, pnlADC_txtCurrentValue5);
		break;
	default:
		break;
	}
	return iResult;
}

int  CVICALLBACK CB_MeasureCH6Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int iResult = 0;
	switch (event)
	{
	case EVENT_COMMIT:
		iResult = MeasureDispalyCurrentValue(panel, 6, pnlADC_numShuntResistor6, pnlADC_txtVoltage6, pnlADC_txtCurrentValue6);
		break;
	default:
		break;
	}
	return iResult;
}

int  CVICALLBACK CB_MeasureCH7Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int iResult = 0;
	switch (event)
	{
	case EVENT_COMMIT:
		iResult = MeasureDispalyCurrentValue(panel, 7, pnlADC_numShuntResistor7, pnlADC_txtVoltage7, pnlADC_txtCurrentValue7);
		break;
	default:
		break;
	}
	return iResult;
}

int  CVICALLBACK CB_MeasureCH8Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int iResult = 0;
	switch (event)
	{
	case EVENT_COMMIT:
		iResult = MeasureDispalyCurrentValue(panel, 8, pnlADC_numShuntResistor8, pnlADC_txtVoltage8, pnlADC_txtCurrentValue8);
		break;
	default:
		break;
	}
	return iResult;
}

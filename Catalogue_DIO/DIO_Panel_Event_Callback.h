/*********************************************************************************************************************************
 * File name		: DIO_Panel_Event_Callback.h
 * Description		: Declare and implement the event call-back functions defined on the Dout panel.
 * Creator			: XU ZAN
 * Creation date	: Mon.	Jan. 13, 2014
 * Copyright(C)		2014	Hella Shanghai Electronics Co., Ltd.
 * All rights reserved.
 *
 *********************************************************************************************************************************/

#ifndef DIO_PANEL_EVENT_CALLBACK_H
#define DIO_PANEL_EVENT_CALLBACK_H

	#ifdef __cplusplus
	    extern "C" 
		{
	#endif

			//==============================================================================
			// Include files
			
			//==============================================================================
			// Constants

			//==============================================================================
			// Types

			//==============================================================================
			// External variables

			//==============================================================================
			// Global functions
			int ChangeDoutBoardID(int hPanel, int iEvent);
			int ControlSingleDoutPort(int hPanel, int iEvent, int iDoutPortCtrlID, int iDoutPortNr);
			int ChangeDinBoardID(int hPanel, int iEvent);
			
			int CVICALLBACK CB_AsyncTimerContinuousQueryDinPortState(int iReserved,
																	 int iAsyncTimerID,
																	 int event,
																	 void *callbackData,
																	 int eventData1,
																	 int eventData2);
			
			void TurnOnOffCurrentLED_ByChannelNr(int hPanel, int iChannelNr, int iState);
			void TurnOnOffCurrentLED(int hPanel, int iLedCtrlID, int iState);

	#ifdef __cplusplus
	    }
	#endif

#endif  /* ndef DIO_PANEL_EVENT_CALLBACK_H */

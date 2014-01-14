/*********************************************************************************************************************************
 * File name		: Dout_Panel_Event_Callback.h
 * Description		: Declare and implement the event call-back functions defined on the Dout panel.
 * Creator			: XU ZAN
 * Creation date	: Mon.	Jan. 13, 2014
 * Copyright(C)		2014	Hella Shanghai Electronics Co., Ltd.
 * All rights reserved.
 *
 *********************************************************************************************************************************/

#ifndef DOUT_PANEL_EVENT_CALLBACK_H
#define DOUT_PANEL_EVENT_CALLBACK_H

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

	#ifdef __cplusplus
	    }
	#endif

#endif  /* ndef DOUT_PANEL_EVENT_CALLBACK_H */

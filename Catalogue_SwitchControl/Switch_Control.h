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

#ifndef SWITCH_CONTROL_H
#define SWITCH_CONTROL_H

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
			int ControlSingleSwitch(int hPanel, int iEvent, int iSwitchCtrl, int iLedCtrl, int iSwitchChannel);
			int ChangeBoardID(int hPanel, int iEvent);
			
	#ifdef __cplusplus
	    }
	#endif

#endif  /* ndef __Switch_Control_H__ */

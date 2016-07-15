/**************************************************************************************************************
 * Project		: MCTBox_Diagnose
 * Description	: This project will build a graphic user utility to access the MCTBox instrument through
 *				  MCTBox_APIs. It provides the diagnosis interface for testing user, and can be integrated
 *				  into the "Test Sequenzer" application.
 * ------------------------------------------------------------------------------------------------------------
 * File name	: MCTBox_Diagnose.c
 * Description	: This file implements the main() entry function.
 * Creator		: XU ZAN	[HSE-OT]
 * Creation date: Mon.	Dec. 02, 2013
 * Copyright(C)		2013	Hella Shanghai Electronics Co., Ltd.
 * All rights reserved.
 *
 **************************************************************************************************************/

#include <cvirte.h>		
#include <userint.h>
#include "MCTBox_Diagnose.h"

int MCTBox_Diagnose_Utility_Panel;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((MCTBox_Diagnose_Utility_Panel = LoadPanel (0, "MCTBox_Diagnose.uir", MCTBox)) < 0)
		return -1;
	DisplayPanel (MCTBox_Diagnose_Utility_Panel);
	RunUserInterface ();
	DiscardPanel (MCTBox_Diagnose_Utility_Panel);
	return 0;
}

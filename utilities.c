/************************************************************************************************************
 * File name	: utilities.c
 * Description	: The "utilities" module provides some utility functions, which can be easily called by some
 *				  key process.
 * Creator		: XU ZAN	[HSE-OT]
 * Creation date: Wed.	Dec. 11, 2013
 * Copyright(C)		2013	Hella Shanghai Electronics Co., Ltd.
 * All rights reserved.
 *
 ************************************************************************************************************/

//==============================================================================
// Include files
#include <ctype.h>
#include <string.h>
#include "utilities.h"

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
int TestDigitString(char sDigitStr[])
{
	int iResult = 0;
	int iCnt = 0;
	
	for (iCnt=0; iCnt<strlen(sDigitStr); iCnt++)
	{
		iResult = isdigit(sDigitStr[iCnt]);
		if (!iResult)
			break;
	}
	return iResult;
}

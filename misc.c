/**********************************************************************************************************
 * File name		: misc.c
 * Description		: The miscellaneous module will provide some utility and misc functions.
 * Creator			: XU ZAN
 * Creation date	: Thur.		Jan. 09, 2014
 * Copyright(C)		2014	Hella Shanghai Electronics Co., Ltd.
 * All rights reserved.
 *
 **********************************************************************************************************/

//==============================================================================
// Include files
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "misc.h"

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

int HexStr2Long(char sHexStr[], long *lReturnValue, char *sError)
{
	int iError = 0;

	long lResult = 0x0000000000000000L;
	int iLen = 0, i = 0;
	char sTargetHexStr[64] = {0};
	
	if (strstr(sHexStr, "0x") || strstr(sHexStr, "0X"))		// For the hex format like : 0x5D
	{
		if ( (strstr(sHexStr, "H") == NULL) && (strstr(sHexStr, "h") == NULL) )
		{
			strcpy(sTargetHexStr, sHexStr+2);	// Should ignore the "0x" hex sign.
			iLen = strlen(sTargetHexStr);	
			for (i=iLen; i>0; i--)
			{
				if ( ((sTargetHexStr[i-1]>='0') && (sTargetHexStr[i-1]<='9')) || 
				     ((sTargetHexStr[i-1]>='A') && (sTargetHexStr[i-1]<='F')) ||
				     ((sTargetHexStr[i-1]>='a') && (sTargetHexStr[i-1]<='f')) )		// To check each character 
				{
					lResult += ((CalculateHexChar2Int(sTargetHexStr[i-1]))<<(4*(iLen-i)));
				}
				else
				{
					iError = -2;
					sprintf(sError, "%s", "Wrong heximal character.");
					return iError;
				}
			}
		}
		else
		{	// To avoid the redundant hex format like : 0x5DH
			iError = -1;
			sprintf(sError, "%s", "Wrong hex format.");
			return iError;
		}
	}
	else if ( strstr(sHexStr, "H") || strstr(sHexStr, "h") )	// For the hex format like : 5DH
	{
		if ((strstr(sHexStr, "0x")==NULL) && (strstr(sHexStr, "0X")==NULL))
		{
			strncpy(sTargetHexStr, sHexStr, strlen(sHexStr)-1);	// Ignore the 'H' hex sign.
			iLen = strlen(sTargetHexStr);
			for (i=iLen; i>0; i--)
			{
				if ( ((sHexStr[i-1]>='0') && (sHexStr[i-1]<='9')) ||
					 ((sHexStr[i-1]>='A') && (sHexStr[i-1]<='F')) ||
					 ((sHexStr[i-1]>='a') && (sHexStr[i-1]<='f')) )
				{
					lResult += ((CalculateHexChar2Int(sTargetHexStr[i-1]))<<(4*(iLen-i)));
				}
				else
				{
					iError = -2;
					sprintf(sError, "%s", "Wrong heximal character.");
					return iError;
				}
			}
		}
		else
		{
			iError = -1;
			sprintf(sError, "%s", "Wrong hex format.");
			return iError;
		}
	}
	else	// To process the implicit hex format like : 5C 
	{
		iLen = strlen(sHexStr);
		for (i=iLen; i>0; i--)
		{
			if ( ((sHexStr[i-1]>='0') && (sHexStr[i-1]<='9')) ||
 				 ((sHexStr[i-1]>='A') && (sHexStr[i-1]<='F')) ||
				 ((sHexStr[i-1]>='a') && (sHexStr[i-1]<='f')) )
			{
				lResult += ((CalculateHexChar2Int(sHexStr[i-1]))<<(4*(iLen-i)));
			}
			else
			{
				iError = -2;
				sprintf(sError, "%s", "Wrong heximal character.");
				return iError;
			}
		}
	}
	memcpy(lReturnValue, &lResult, sizeof(long));
	
	return iError;
}

void ToUpperCaseStr(char sARGIN_OriginalStr[], char *sARGOUT_UpperCaseStr)
{
	int iLen = strlen(sARGIN_OriginalStr), iCnt = 0;
	char cTemp = 0;

	for (iCnt=0; iCnt<iLen; iCnt++)
	{
		cTemp = toupper(sARGIN_OriginalStr[iCnt]);
		*(sARGOUT_UpperCaseStr+iCnt) = cTemp;
	}
	return;
}

void ToLowerCaseStr(char sARGIN_OriginalStr[], char *sARGOUT_LowerCaseStr)
{
	int iLen = strlen(sARGIN_OriginalStr), iCnt = 0;
	char cTemp = 0;

	for (iCnt=0; iCnt<iLen; iCnt++)
	{
		cTemp = tolower(sARGIN_OriginalStr[iCnt]);
		*(sARGOUT_LowerCaseStr+iCnt) = cTemp;
	}
	return;
}

int CalculateHexChar2Int(char cHexSingleChar)
{
	int iResult = -1;
	switch (cHexSingleChar)
	{
	case '0': iResult = 0;  break;
	case '1': iResult = 1;  break;
	case '2': iResult = 2;  break;
	case '3': iResult = 3;  break;
	case '4': iResult = 4;  break;
	case '5': iResult = 5;  break;
	case '6': iResult = 6;  break;
	case '7': iResult = 7;  break;
	case '8': iResult = 8;  break;
	case '9': iResult = 9;  break;
	case 'A':
	case 'a': iResult = 10; break;
	case 'B':
	case 'b': iResult = 11; break;
	case 'C':
	case 'c': iResult = 12; break;
	case 'D':
	case 'd': iResult = 13; break;
	case 'E':
	case 'e': iResult = 14; break;
	case 'F':
	case 'f': iResult = 15; break;
	default:  iResult = 0;  break;
	}
	return iResult;
}

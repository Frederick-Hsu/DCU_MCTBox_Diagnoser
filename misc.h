/**********************************************************************************************************
 * File name		: misc.h
 * Description		: The miscellaneous module will provide some utility and misc functions.
 * Creator			: XU ZAN
 * Creation date	: Thur.		Jan. 09, 2014
 * Copyright(C)		2014	Hella Shanghai Electronics Co., Ltd.
 * All rights reserved.
 *
 **********************************************************************************************************/

#ifndef MISC_H
#define MISC_H

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
			
			int HexStr2Long(char sHexStr[], long *lReturnValue, char *sError);
			void ToUpperCaseStr(char sARGIN_OriginalStr[], char *sARGOUT_UpperCaseStr);
			void ToLowerCaseStr(char sARGIN_OriginalStr[], char *sARGOUT_LowerCaseStr);
			int CalculateHexChar2Int(char cHexSingleChar);

	#ifdef __cplusplus
	    }
	#endif

#endif  /* ndef MISC_H */

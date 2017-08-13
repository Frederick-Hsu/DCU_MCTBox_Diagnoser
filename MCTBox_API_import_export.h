/***********************************************************************************************
 * File name	: MCTBox_API_import_export.h
 * Description	: Determine the direction of import/export for the MCTBox_API.
 * Creator		: XU ZAN	[HSE-OT]
 * Creation date: Mon.	Nov. 25, 2013
 * Copyright(C)		2013	Hella Shanghai Electronics Co., Ltd.
 *
 ***********************************************************************************************/

#ifndef MCTBOX_API_IMPORT_EXPORT_H
#define MCTBOX_API_IMPORT_EXPORT_H

	//==============================================================================
	// Macros :
	#if !defined (USE_API)
		#if !defined (API_IMPORT_EXPORT)
			#define API		__declspec(dllexport) __stdcall
		#else
			#define API		__declspec(dllimport) __stdcall
		#endif	/*  API_IMPORT_EXPORT  */
	#else
			#undef API
	#endif	/*  USE_API  */


/***********************************************************************************************/

	//==============================================================================
	// User defined types :
	typedef unsigned int UINT;
	typedef unsigned char BYTE;
	typedef unsigned char UCHAR;
	
	typedef enum State
	{
		OFF = 0,
		OPEN = 0,
		LOW = 0,
		
		ON = 1,
		CLOSE = 1,
		HIGH = 1
		
	}
	EState;

#endif  /* ndef MCTBOX_API_IMPORT_EXPORT_H */

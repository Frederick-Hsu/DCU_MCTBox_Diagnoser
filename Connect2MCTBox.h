/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2013. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PnlConnect                       1       /* callback function: CB_ExitConnectPanel */
#define  PnlConnect_strSerialPortNr       2       /* control type: string, callback function: (none) */
#define  PnlConnect_cmdbtnConnect2MCTBox  3       /* control type: command, callback function: CB_Connect2MCTBox */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK CB_Connect2MCTBox(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_ExitConnectPanel(int panel, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif

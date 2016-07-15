/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2014. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  pnlDIN                           1
#define  pnlDIN_binswDinBoardIDBit7       2       /* control type: binary, callback function: CB_binswDinBoardIDBit7_OnChange */
#define  pnlDIN_binswDinBoardIDBit6       3       /* control type: binary, callback function: CB_binswDinBoardIDBit6_OnChange */
#define  pnlDIN_binswDinBoardIDBit5       4       /* control type: binary, callback function: CB_binswDinBoardIDBit5_OnChange */
#define  pnlDIN_binswDinBoardIDBit4       5       /* control type: binary, callback function: CB_binswDinBoardIDBit4_OnChange */
#define  pnlDIN_binswDinBoardIDBit3       6       /* control type: binary, callback function: CB_binswDinBoardIDBit3_OnChange */
#define  pnlDIN_binswDinBoardIDBit2       7       /* control type: binary, callback function: CB_binswDinBoardIDBit2_OnChange */
#define  pnlDIN_binswDinBoardIDBit1       8       /* control type: binary, callback function: CB_binswDinBoardIDBit1_OnChange */
#define  pnlDIN_binswDinBoardIDBit0       9       /* control type: binary, callback function: CB_binswDinBoardIDBit0_OnChange */
#define  pnlDIN_DECORATION_2              10      /* control type: deco, callback function: (none) */
#define  pnlDIN_cmdbtnDinExit             11      /* control type: command, callback function: CB_ExitDinPanel */
#define  pnlDIN_DECORATION                12      /* control type: deco, callback function: (none) */
#define  pnlDIN_txtDinBoardID             13      /* control type: textMsg, callback function: (none) */
#define  pnlDIN_txtlblDinPortsArray       14      /* control type: textMsg, callback function: (none) */
#define  pnlDIN_txtlblDoutBoardID         15      /* control type: textMsg, callback function: (none) */
#define  pnlDIN_ledDinPort24              16      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort23              17      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort22              18      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort21              19      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort20              20      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort19              21      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort18              22      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort17              23      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort16              24      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort15              25      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort14              26      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort13              27      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort12              28      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort11              29      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort10              30      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort9               31      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort8               32      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort7               33      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort6               34      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort5               35      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort4               36      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort3               37      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort2               38      /* control type: LED, callback function: (none) */
#define  pnlDIN_ledDinPort1               39      /* control type: LED, callback function: (none) */
#define  pnlDIN_SPLITTER_2                40      /* control type: splitter, callback function: (none) */
#define  pnlDIN_SPLITTER                  41      /* control type: splitter, callback function: (none) */
#define  pnlDIN_picbtnStart               42      /* control type: pictButton, callback function: CB_StartContinuousQueryDinPortState */
#define  pnlDIN_picbtnStop                43      /* control type: pictButton, callback function: CB_StopContinuousQueryDinPortState */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK CB_binswDinBoardIDBit0_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDinBoardIDBit1_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDinBoardIDBit2_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDinBoardIDBit3_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDinBoardIDBit4_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDinBoardIDBit5_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDinBoardIDBit6_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDinBoardIDBit7_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_ExitDinPanel(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_StartContinuousQueryDinPortState(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_StopContinuousQueryDinPortState(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif

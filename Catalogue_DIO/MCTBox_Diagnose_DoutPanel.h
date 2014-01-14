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

#define  pnlDOUT                          1
#define  pnlDOUT_binswDoutBoardIDBit7     2       /* control type: binary, callback function: CB_binswDoutBoardIDBit7_OnChange */
#define  pnlDOUT_binswDoutBoardIDBit6     3       /* control type: binary, callback function: CB_binswDoutBoardIDBit6_OnChange */
#define  pnlDOUT_binswDoutBoardIDBit5     4       /* control type: binary, callback function: CB_binswDoutBoardIDBit5_OnChange */
#define  pnlDOUT_binswDoutBoardIDBit4     5       /* control type: binary, callback function: CB_binswDoutBoardIDBit4_OnChange */
#define  pnlDOUT_binswDoutBoardIDBit3     6       /* control type: binary, callback function: CB_binswDoutBoardIDBit3_OnChange */
#define  pnlDOUT_binswDoutBoardIDBit2     7       /* control type: binary, callback function: CB_binswDoutBoardIDBit2_OnChange */
#define  pnlDOUT_binswDoutBoardIDBit1     8       /* control type: binary, callback function: CB_binswDoutBoardIDBit1_OnChange */
#define  pnlDOUT_binswDoutBoardIDBit0     9       /* control type: binary, callback function: CB_binswDoutBoardIDBit0_OnChange */
#define  pnlDOUT_DECORATION_2             10      /* control type: deco, callback function: (none) */
#define  pnlDOUT_DECORATION               11      /* control type: deco, callback function: (none) */
#define  pnlDOUT_txtDoutBoardID           12      /* control type: textMsg, callback function: (none) */
#define  pnlDOUT_txtlblDoutPortsArray     13      /* control type: textMsg, callback function: (none) */
#define  pnlDOUT_txtlblDoutBoardID        14      /* control type: textMsg, callback function: (none) */
#define  pnlDOUT_cmdbtnExitDoutPanel      15      /* control type: command, callback function: CB_ExitDoutPanel */
#define  pnlDOUT_binswDoutPort24          16      /* control type: binary, callback function: CB_binswDoutPort24_OnChange */
#define  pnlDOUT_binswDoutPort23          17      /* control type: binary, callback function: CB_binswDoutPort23_OnChange */
#define  pnlDOUT_binswDoutPort22          18      /* control type: binary, callback function: CB_binswDoutPort22_OnChange */
#define  pnlDOUT_binswDoutPort21          19      /* control type: binary, callback function: CB_binswDoutPort21_OnChange */
#define  pnlDOUT_binswDoutPort20          20      /* control type: binary, callback function: CB_binswDoutPort20_OnChange */
#define  pnlDOUT_binswDoutPort19          21      /* control type: binary, callback function: CB_binswDoutPort19_OnChange */
#define  pnlDOUT_binswDoutPort18          22      /* control type: binary, callback function: CB_binswDoutPort18_OnChange */
#define  pnlDOUT_binswDoutPort17          23      /* control type: binary, callback function: CB_binswDoutPort17_OnChange */
#define  pnlDOUT_binswDoutPort16          24      /* control type: binary, callback function: CB_binswDoutPort16_OnChange */
#define  pnlDOUT_binswDoutPort15          25      /* control type: binary, callback function: CB_binswDoutPort15_OnChange */
#define  pnlDOUT_binswDoutPort14          26      /* control type: binary, callback function: CB_binswDoutPort14_OnChange */
#define  pnlDOUT_binswDoutPort13          27      /* control type: binary, callback function: CB_binswDoutPort13_OnChange */
#define  pnlDOUT_binswDoutPort12          28      /* control type: binary, callback function: CB_binswDoutPort12_OnChange */
#define  pnlDOUT_binswDoutPort11          29      /* control type: binary, callback function: CB_binswDoutPort11_OnChange */
#define  pnlDOUT_binswDoutPort10          30      /* control type: binary, callback function: CB_binswDoutPort10_OnChange */
#define  pnlDOUT_binswDoutPort9           31      /* control type: binary, callback function: CB_binswDoutPort9_OnChange */
#define  pnlDOUT_binswDoutPort8           32      /* control type: binary, callback function: CB_binswDoutPort8_OnChange */
#define  pnlDOUT_binswDoutPort7           33      /* control type: binary, callback function: CB_binswDoutPort7_OnChange */
#define  pnlDOUT_binswDoutPort6           34      /* control type: binary, callback function: CB_binswDoutPort6_OnChange */
#define  pnlDOUT_binswDoutPort5           35      /* control type: binary, callback function: CB_binswDoutPort5_OnChange */
#define  pnlDOUT_binswDoutPort4           36      /* control type: binary, callback function: CB_binswDoutPort4_OnChange */
#define  pnlDOUT_binswDoutPort3           37      /* control type: binary, callback function: CB_binswDoutPort3_OnChange */
#define  pnlDOUT_binswDoutPort2           38      /* control type: binary, callback function: CB_binswDoutPort2_OnChange */
#define  pnlDOUT_binswDoutPort1           39      /* control type: binary, callback function: CB_binswDoutPort1_OnChange */
#define  pnlDOUT_SPLITTER_2               40      /* control type: splitter, callback function: (none) */
#define  pnlDOUT_SPLITTER                 41      /* control type: splitter, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK CB_binswDoutBoardIDBit0_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutBoardIDBit1_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutBoardIDBit2_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutBoardIDBit3_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutBoardIDBit4_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutBoardIDBit5_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutBoardIDBit6_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutBoardIDBit7_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort10_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort11_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort12_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort13_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort14_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort15_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort16_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort17_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort18_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort19_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort1_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort20_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort21_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort22_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort23_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort24_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort2_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort3_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort4_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort5_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort6_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort7_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort8_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_binswDoutPort9_OnChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_ExitDoutPanel(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif

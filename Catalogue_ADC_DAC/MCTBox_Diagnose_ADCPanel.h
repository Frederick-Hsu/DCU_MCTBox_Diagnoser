/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  pnlADC                           1
#define  pnlADC_cmdbtnExitAdcPnl          2       /* control type: command, callback function: CB_ExitADCPnl */
#define  pnlADC_txtChannelNr              3       /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtVoltageValue           4       /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtShuntResistor          5       /* control type: textMsg, callback function: (none) */
#define  pnlADC_SPLITTER_21               6       /* control type: splitter, callback function: (none) */
#define  pnlADC_SPLITTER_20               7       /* control type: splitter, callback function: (none) */
#define  pnlADC_SPLITTER_19               8       /* control type: splitter, callback function: (none) */
#define  pnlADC_SPLITTER_18               9       /* control type: splitter, callback function: (none) */
#define  pnlADC_SPLITTER_17               10      /* control type: splitter, callback function: (none) */
#define  pnlADC_SPLITTER_15               11      /* control type: splitter, callback function: (none) */
#define  pnlADC_SPLITTER_14               12      /* control type: splitter, callback function: (none) */
#define  pnlADC_SPLITTER_13               13      /* control type: splitter, callback function: (none) */
#define  pnlADC_SPLITTER                  14      /* control type: splitter, callback function: (none) */
#define  pnlADC_SPLITTER_12               15      /* control type: splitter, callback function: (none) */
#define  pnlADC_SPLITTER_16               16      /* control type: splitter, callback function: (none) */
#define  pnlADC_SPLITTER_10               17      /* control type: splitter, callback function: (none) */
#define  pnlADC_txtCurrentValue           18      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtCh1                    19      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtCh2                    20      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtCh3                    21      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtCh4                    22      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtCh5                    23      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtCh7                    24      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtCh6                    25      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtCh8                    26      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtVoltage8               27      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtVoltage7               28      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtVoltage6               29      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtVoltage5               30      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtVoltage4               31      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtVoltage3               32      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtVoltage2               33      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtVoltage1               34      /* control type: textMsg, callback function: (none) */
#define  pnlADC_numShuntResistor8         35      /* control type: numeric, callback function: (none) */
#define  pnlADC_numShuntResistor7         36      /* control type: numeric, callback function: (none) */
#define  pnlADC_numShuntResistor1         37      /* control type: numeric, callback function: (none) */
#define  pnlADC_numShuntResistor2         38      /* control type: numeric, callback function: (none) */
#define  pnlADC_numShuntResistor3         39      /* control type: numeric, callback function: (none) */
#define  pnlADC_numShuntResistor4         40      /* control type: numeric, callback function: (none) */
#define  pnlADC_numShuntResistor5         41      /* control type: numeric, callback function: (none) */
#define  pnlADC_numShuntResistor6         42      /* control type: numeric, callback function: (none) */
#define  pnlADC_cmdbtnMeas8Voltages       43      /* control type: command, callback function: CB_Measure8VoltagesByADC */
#define  pnlADC_DECORATION                44      /* control type: deco, callback function: (none) */
#define  pnlADC_txtHeadInfo               45      /* control type: textMsg, callback function: (none) */
#define  pnlADC_cmdbtnMeasCH8Curren       46      /* control type: command, callback function: CB_MeasureCH8Current */
#define  pnlADC_cmdbtnMeasCH7Curren       47      /* control type: command, callback function: CB_MeasureCH7Current */
#define  pnlADC_cmdbtnMeasCH6Curren       48      /* control type: command, callback function: CB_MeasureCH6Current */
#define  pnlADC_cmdbtnMeasCH5Curren       49      /* control type: command, callback function: CB_MeasureCH5Current */
#define  pnlADC_cmdbtnMeasCH4Curren       50      /* control type: command, callback function: CB_MeasureCH4Current */
#define  pnlADC_cmdbtnMeasCH3Curren       51      /* control type: command, callback function: CB_MeasureCH3Current */
#define  pnlADC_cmdbtnMeasCH2Curren       52      /* control type: command, callback function: CB_MeasureCH2Current */
#define  pnlADC_txtCurrentValue1          53      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtCurrentValue2          54      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtCurrentValue3          55      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtCurrentValue4          56      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtCurrentValue5          57      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtCurrentValue6          58      /* control type: textMsg, callback function: (none) */
#define  pnlADC_txtCurrentValue7          59      /* control type: textMsg, callback function: (none) */
#define  pnlADC_cmdbtnMeasCH1Current      60      /* control type: command, callback function: CB_MeasureCH1Current */
#define  pnlADC_txtCurrentValue8          61      /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK CB_ExitADCPnl(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_Measure8VoltagesByADC(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_MeasureCH1Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_MeasureCH2Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_MeasureCH3Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_MeasureCH4Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_MeasureCH5Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_MeasureCH6Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_MeasureCH7Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_MeasureCH8Current(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif

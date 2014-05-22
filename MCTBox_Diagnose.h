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

#define  MCTBox                           1       /* callback function: CB_MCTBoxDiagnose_Exit */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

#define  MENUBAR                          1
#define  MENUBAR_Menu_File                2
#define  MENUBAR_Menu_File_Connect        3       /* callback function: CB_MenuFile_Connect */
#define  MENUBAR_Menu_File_Disconnect     4       /* callback function: CB_MenuFile_Disconnect */
#define  MENUBAR_Menu_File_Separator      5
#define  MENUBAR_Menu_File_Exit           6       /* callback function: CB_MenuFile_Exit */
#define  MENUBAR_Menu_Catalogue           7
#define  MENUBAR_Menu_Catalogue_SwitchCtrl 8      /* callback function: CB_MenuCatalogueSwitchCtrl_DisplaySwitchCtrlPanel */
#define  MENUBAR_Menu_Catalogue_DIO       9
#define  MENUBAR_Menu_Catalogue_DIO_SUBMENU 10
#define  MENUBAR_Menu_Catalogue_DIO_DIN   11      /* callback function: CB_MenuCatalogueDin_DisplayDinPanel */
#define  MENUBAR_Menu_Catalogue_DIO_DOUT  12      /* callback function: CB_MenuCatalogueDout_DisplayDoutPanel */
#define  MENUBAR_Menu_Catalogue_ADC       13
#define  MENUBAR_Menu_Catalogue_DAC       14
#define  MENUBAR_Menu_Catalogue_PWM       15
#define  MENUBAR_Menu_Catalogue_PWM_SUBMENU 16
#define  MENUBAR_Menu_Catalogue_PWM_PwmIn 17
#define  MENUBAR_Menu_Catalogue_PWM_PwmOut 18
#define  MENUBAR_Menu_Catalogue_CAN       19
#define  MENUBAR_Menu_Catalogue_LIN       20
#define  MENUBAR_Menu_Calibrate           21
#define  MENUBAR_Menu_Calibrate_CaliGainOffset 22
#define  MENUBAR_Menu_Help                23
#define  MENUBAR_Menu_Help_AboutMCTBox    24
#define  MENUBAR_Menu_Help_Version        25
#define  MENUBAR_Menu_Help_MCTBoxAPIManual 26
#define  MENUBAR_Menu_Help_MCTBoxProtocol 27


     /* Callback Prototypes: */

int  CVICALLBACK CB_MCTBoxDiagnose_Exit(int panel, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK CB_MenuCatalogueDin_DisplayDinPanel(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK CB_MenuCatalogueDout_DisplayDoutPanel(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK CB_MenuCatalogueSwitchCtrl_DisplaySwitchCtrlPanel(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK CB_MenuFile_Connect(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK CB_MenuFile_Disconnect(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK CB_MenuFile_Exit(int menubar, int menuItem, void *callbackData, int panel);


#ifdef __cplusplus
    }
#endif

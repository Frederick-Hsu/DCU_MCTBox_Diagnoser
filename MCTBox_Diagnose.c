#include <cvirte.h>		
#include <userint.h>
#include "MCTBox_Diagnose.h"

static int MCTBox_Diagnose_Utility_Panel;

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

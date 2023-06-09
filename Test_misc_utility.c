/************************************************************************************
 * File name		: Test_misc_utility.c
 * Description		: 测试misc模块里面的utility函数集
 * Creator			: XU ZAN	[HSE-OT]
 * Creation date	: Fri.	Jan. 10, 2014
 * Copyright(C)		2014	Hella Shanghai Electronics Co., Ltd.
 * All rights reserved.
 *
 ************************************************************************************/
#include <stdio.h>
#include "Test_misc_utility.h"
#include "misc.h"

void General_Test_Case(void)
{
	Test_HexStr2Long();
	Test_ToUpperCaseStr();
	Test_ToLowerCaseStr();
}

void Test_HexStr2Long(void)
{
	long lResult = 0L;
	int iError = 0;
	char sHexStr[32] = "0x569fdcb9", sError[256] = {0};

	iError = HexStr2Long(sHexStr, &lResult, sError); 
	if (iError)
	{
		printf(sError);
		printf("\n");
	}

	printf("The heximal number is: %s, \ntransferring to decimal number is: %d\n\n", sHexStr, lResult);
	return;
}

void Test_ToUpperCaseStr(void)
{
	char sTestCaseStr[256] = "Hello, how are you?";
	char sDest[256] = "";

	ToUpperCaseStr(sTestCaseStr, sDest);
	printf("The original string : %s\n", sTestCaseStr);
	printf("After upper case, the destination string : %s\n", sDest);
}

void Test_ToLowerCaseStr(void)
{
	char sTestCaseStr[256] = "HEllo, HOW are YOu TOdaY?";
	char sDest[256] = "";

	ToLowerCaseStr(sTestCaseStr, sDest);
	printf("The original string : %s\n", sTestCaseStr);
	printf("After lower case, the destination string : %s\n", sDest);
}
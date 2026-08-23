/*
 * FUNCTIONS.c
 *
 *  Created on: Aug 22, 2026
 *      Author: Target
 */

#include "../INCLUDE/LIB/FUNCTIONS.h"

#include <stdio.h>
#include <util/delay.h>


u64* str2int (u8 *stParameter,u16 numOfOperations)
{
    u16 valueDigit = 0,lengthNumber = 0;
    u64 valueNumber = 0;

    static u64 Parameters[10];

    for(u16 i=0;i<=numOfOperations;i++)
    {
    	valueNumber = 0;
    	lengthNumber = 0;
    	for(u16 j = 0; j < 20; j++)
    	    {
    		if(stParameter[i*11 + j] == '\0'){ break; }
    	        else{ lengthNumber++; }
    	    }
    	for(u16 j = 1;  j<= lengthNumber; j++)
    	    {
    	        valueDigit = (u16)(stParameter[i*11 + j-1] - '0');
    	        valueNumber = (valueNumber * 10) + valueDigit;
    	    }
    	Parameters[i]=valueNumber;
    }

    return Parameters;
}
u8 *int2str(s64 Result)
{
    u16 digit;
    static u8 stResult[20];
    u8 temp[20];
    u16 tempIndex = 0,stResultIndex=0;
    u8 isNegative = 0;

    if(Result == 0)
    {
        stResult[0] = '0';
        stResult[1] = '\0';
        return stResult;
    }

    if(Result < 0)
    {
        isNegative = 1;
        Result = -Result;
    }

    while(Result != 0)
    {
        digit = Result % 10;
        temp[tempIndex] = '0' + digit;
        tempIndex++;
        Result /= 10;
    }


    // Add negative sign if needed
    if(isNegative)
    {
        stResult[stResultIndex] = '-';
        stResultIndex++;
    }

    // Copy digits in reverse order (tempIndex is the length)
    while(tempIndex > 0)
    {
        tempIndex--;  // Decrement first to get the last valid index
        stResult[stResultIndex] = temp[tempIndex];
        stResultIndex++;
    }

    stResult[stResultIndex] = '\0';
    return stResult;
}

s64 sum(s64 x ,s64 y){return x+y;}
s64 sub(s64 x ,s64 y){return x-y;}
s64 mul(s64 x ,s64 y){return x * y;}
s64 div(s64 x ,s64 y)
{
	if (y==0)  //added
	{
		return 0xFFFF ;
	}

	return x/ y;

}

s64 calculate(u64 *Parameter,u8* Operation,u8 numOfOperations)
{
	u64 Result=Parameter[0];

	for(int i=0;i<numOfOperations;i++)
	{
		switch(Operation[i])
		{
		case'+':
		{
			Result=sum(Result,Parameter[i+1]);
			break;
		}
		case'-':
				{
					Result=sub(Result,Parameter[i+1]);
					break;
				}

		case'/':
				{
					Result=div(Result,Parameter[i+1]);
					break;
				}

		case'*':
				{
					Result=mul(Result,Parameter[i+1]);
					break;
				}
		}
		if(Result==0xFFFF){break;}
	}
	return Result;
}




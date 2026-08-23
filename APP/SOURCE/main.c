/*
 * main.c
 *
 *  Created on: Aug 18, 2026
 *      Author: Target
 */


#include "../INCLUDE/LIB/FUNCTIONS.h"


int main()
{

	HLCD_voidInit();
	KEYPAD_voidInit();

	HLCD_voidSendString("WELCOME");
	_delay_ms(1000);
	HLCD_voidClearDisplay();

	u8 stParameter[10][11],Operation[10];
	u64 *Parameter;

	s64 Result;
	u8 key;

	u8 numOfOperations=0,numOfParameters=0,
	   ParameterIndex=0,numOfchars=0;


	while(1)
	{

		key= KEYPAD_u8GetPressedKey();
		switch(key)
		{
		case 255:break;
		case'c':
		{
			HLCD_voidClearDisplay();

			numOfOperations=0;
			numOfParameters=0;
			ParameterIndex=0;
			numOfchars=0;

			break;
		}
		case '=':
		{
			HLCD_voidClearDisplay();
			HLCD_voidSendData('=');

			Parameter= str2int (stParameter,numOfOperations);
			Result=calculate(Parameter,Operation,numOfOperations);

			if(Result==0xFFFF)
			{
				HLCD_voidSendString("ER: DIV BY 0");
			}
			else if(numOfParameters!=numOfOperations+1)
			{
				HLCD_voidSendString("ER: INSUF PARAs");
			}
			else
			{
				u8* stResult = int2str(Result);
				HLCD_voidSendString(stResult);
			}
			numOfOperations=0;
			numOfParameters=0;
			ParameterIndex=0;
			numOfchars=0;

			while(KEYPAD_u8GetPressedKey()==255){}//STAY IN RESULT SCREEN UNTIL USER HITS ANY KEY

			HLCD_voidClearDisplay();//GOING BACK TO EQ. SCREEN
			break;
		}
		case '+':
		case '-':
		case '/':
		case '*':
		{
			if(numOfOperations<9)//LIMITS OPERATION INPUT TO MAX NUM
			{
			numOfchars++;
			if(numOfchars>16){HLCD_voidClearDisplay();numOfchars=0;}//CHECKS IF LCD IS FULL

			Operation[numOfOperations]=key;
			HLCD_voidSendData(key);
			numOfOperations++;
			ParameterIndex = 0;
			}
			break;
		}
		default:
		{
			if(ParameterIndex<10)//LIMITS DIGITS INPUT TO MAX NUM
			{

			numOfchars++;
			if(numOfchars>16){HLCD_voidClearDisplay();numOfchars=0;}//CHECKS IF LCD IS FULL

			HLCD_voidSendData(key);
			stParameter[numOfOperations][ParameterIndex]=key;
			ParameterIndex++;
            stParameter[numOfOperations][ParameterIndex] = '\0';

            if(ParameterIndex == 1)//NEW PARA IS COUNTED ONLY WHEN AT LEAST ONE DIGIT IS STORED
            {
            	numOfParameters++;
         	}
			}
			break;
		}
		}


	}

return 0;
}


/*
 * FUNCTIONS.h
 *
 *  Created on: Aug 22, 2026
 *      Author: Target
 */

#ifndef APP_INCLUDE_LIB_FUNCTIONS_H_
#define APP_INCLUDE_LIB_FUNCTIONS_H_


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../HAL/KEYPAD/KEYPAD_INTERFACE.h"

#include <stdio.h>
#include <util/delay.h>



u64* str2int (u8 *stParameter,u16 numOfOperations);

u8 *int2str(s64 Result);

s64 sum(s64 x ,s64 y);
s64 sub(s64 x ,s64 y);
s64 mul(s64 x ,s64 y);
s64 div(s64 x ,s64 y);


s64 calculate(u64 *Parameter,u8* Operation,u8 numOfOperations);

#endif /* APP_INCLUDE_LIB_FUNCTIONS_H_ */

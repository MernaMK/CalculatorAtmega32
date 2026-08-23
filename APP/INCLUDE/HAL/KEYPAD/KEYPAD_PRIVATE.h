/*
 * KEYPAD_PRIVATE.h
 *
 *  Created on: Aug 22, 2026
 *      Author: Target
 */

#ifndef APP_INCLUDE_HAL_KEYPAD_KEYPAD_PRIVATE_H_
#define APP_INCLUDE_HAL_KEYPAD_KEYPAD_PRIVATE_H_

//ACTIVE LOW
#define KEYPAD_PRESSED 0
#define KEYPAD_NOT_PRESSED 1

#define ROW_NO 4
#define COL_NO 4

u8 Global_u8ArrOfKeyValue[ROW_NO][COL_NO]={{'7','8','9','/'},
										   {'4','5','6','*'},
										   {'1','2','3','-'},
										   {'c','0','=','+'}};

#define KEYPAD_FLAG_DOWN 0
#define KEYPAD_FLAG_UP 1

#endif /* APP_INCLUDE_HAL_KEYPAD_KEYPAD_PRIVATE_H_ */

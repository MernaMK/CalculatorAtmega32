# Calculator System - Embedded C Project

📋 Overview
This is an embedded calculator system implemented in C for AVR microcontrollers. The system utilizes a 4x4 matrix keypad for input and an LCD display for output, providing a functional calculator with basic arithmetic operations.

🎯 Features
Basic Arithmetic Operations: Addition, subtraction, multiplication, and division

4x4 Keypad Interface: Input numbers and operations

LCD Display: 16x2 character LCD for output visualization

Error Handling: Division by zero detection and insufficient parameters validation

Debounce Mechanism: Prevents false key presses

User-Friendly Interface: Clear display functionality with 'c' key

🔧 Configuration
Keypad Configuration (KEYPAD_CFG.h)
Port: PORTC (default)

Rows: PIN0-PIN3

Columns: PIN4-PIN7

Debounce Delay: 30ms

LCD Configuration (LCD_CFG.h)
Data Port: PORTA

Control Port: PORTB

Mode: 4-bit (default)

Display: 2 lines, 5x7 character font

DIO Configuration (DIO_CFG.h)
All ports configured as outputs by default

Internal pull-up resistors enabled for all inputs

🚀 How It Works
Input Processing
The system waits for keypad input

Numbers are stored in parameter arrays

Operators are stored separately

'c' clears the current operation

'=' calculates and displays the result

Calculation Flow
User enters numbers and operations

On '=' press, parameters are extracted

Operations are performed in sequence

Result is displayed on LCD

Errors are handled gracefully

Error Handling
Division by Zero: Displays "ER: DIV BY 0"

Insufficient Parameters: Displays "ER: INSUF PARAs"

LCD Overflow: Automatically clears when full

📝 Usage Instructions
Power ON: System displays "WELCOME"

Enter Numbers: Press numeric keys (0-9)

Enter Operations: Press +, -, *, /

Calculate: Press '=' to get result

Clear: Press 'c' to reset

Continue: Press any key after result display

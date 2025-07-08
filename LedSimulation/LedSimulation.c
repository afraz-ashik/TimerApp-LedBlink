//******************************* Led Simulation ******************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
// File    : LedSimulation.c
// Summary : Display "LED ON" or "LED OFF". Also Blinks LED using gpio when
//           cross-compiling.
// Note    : None.
// Author  : Afraz Ashik
// Date    : 27/June/2025
//*****************************************************************************

//******************************* Include Files *******************************
#include "LedSimulation.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************
static bool gsblLedStatus = false;

//****************************** Local Functions ******************************

//*****************************************************************************

//****************************.LedSimulationDisplay.***************************
// Purpose : If the macro RPICODE is defined then sets gpio pin 22 to high or
//           low and also prints "LED ON" or "LED OFF".
//           Else LedSimulationDisplay() is called.
// Inputs  : None.
// Outputs : None.
// Return  : true.
// Notes   : None.
//*****************************************************************************
bool LedSimulationBlinkLED()
{
    // If Macro "RPICODE" is defined
    #ifdef RPICODE

    // Declare gpiochip number
    struct gpiod_chip *pstChip = NULL;
    pstChip = gpiod_chip_open_by_name("gpiochip0");

    // Open gpio line
    struct gpiod_line *pstLine = NULL;
    pstLine = gpiod_chip_get_line(pstChip,GPIO_PIN);

    // Open line for output
    gpiod_line_request_output(pstLine,"LedBlinkProgram",ACTIVE_LOW);

    // if LED is indicated to be OFF
    if (!gsblLedStatus)
    {
        // Set Output High
        gpiod_line_set_value(pstLine,ACTIVE_LOW);
        printf("\nLED OFF\n");
        usleep(OFF_TIME);

        // Set LED status to indicate ON
        gsblLedStatus = true;
    }
    // if LED is indicated to be ON
    else
    {
        // Set Output Low
        gpiod_line_set_value(pstLine,ACTIVE_HIGH);
        printf("\nLED ON\n");
        usleep(ON_TIME);

        // Set LED status to indicate OFF
        gsblLedStatus = false;
    }
    gpiod_line_release(pstLine);
    gpiod_chip_close(pstChip);

    // If macro not defined
    #else
    
    LedSimulationDisplay();
    
    #endif

    return true;
}

//****************************.LedSimulationDisplay.***************************
// Purpose : Prints "LED ON" or "LED OFF".
// Inputs  : None.
// Outputs : None.
// Return  : true.
// Notes   : None.
//*****************************************************************************
bool LedSimulationDisplay()
{

    // if LED is indicated to be OFF
    if (!gsblLedStatus)
    {
        printf("\nLED OFF\n");
        usleep(OFF_TIME);

        // Set LED status to indicate ON
        gsblLedStatus = true;
    }
    // if LED is indicated to be ON
    else
    {
        printf("\nLED ON\n");
        usleep(ON_TIME);

        // Set LED status to indicate OFF
        gsblLedStatus = false;
    }

    return true;
}
// EOF
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
#include "unistd.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//*****************************************************************************

//****************************.LedSimulationDisplay.***************************
// Purpose : Prints "LED ON" or "LED OFF".
//           Set gpio pin to high then low if cross-compiled.
// Inputs  : None.
// Outputs : None.
// Return  : true.
// Notes   : None.
//*****************************************************************************
bool LedSimulationDisplay()
{
    // If Macro "RPICODE" is defined
    #ifdef RPICODE

    static bool sblLedStatus = false;

    // Declare gpiochip number
    struct gpiod_chip *pstChip = NULL;
    pstChip = gpiod_chip_open_by_name("gpiochip0");

    // Open gpio line
    struct gpiod_line *pstLine = NULL;
    pstLine = gpiod_chip_get_line(pstChip,GPIO_PIN);

    // Open line for output
    gpiod_line_request_output(pstLine,"LedBlinkProgram",ACTIVE_LOW);

    // if LED is indicated to be OFF
    if (!sblLedStatus)
    {
        // Set Output High
        gpiod_line_set_value(pstLine,ACTIVE_HIGH);
        printf("\nLED OFF\n");
        usleep(OFF_TIME);

        // Set LED status to indicate ON
        sblLedStatus = true;
    }
    // if LED is indicated to be ON
    else
    {
        // Set Output Low
        gpiod_line_set_value(pstLine,ACTIVE_LOW);
        printf("\nLED ON\n");
        usleep(ON_TIME);

        // Set LED status to indicate OFF
        sblLedStatus = false;
    }
    gpiod_line_release(pstLine);
    gpiod_chip_close(pstChip);

    return true;

    // If macro not defined
    #else

    static bool sblLedStatus = false;
    // if LED is indicated to be OFF
    if (!sblLedStatus)
    {
        printf("\nLED OFF\n");
        usleep(OFF_TIME);

        // Set LED status to indicate ON
        sblLedStatus = true;
    }
    // if LED is indicated to be ON
    else
    {
        printf("\nLED ON\n");
        usleep(ON_TIME);

        // Set LED status to indicate OFF
        sblLedStatus = false;
    }

    return true;

    #endif
}

// EOF
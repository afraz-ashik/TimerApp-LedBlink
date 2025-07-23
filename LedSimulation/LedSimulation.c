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


//****************************** Local Functions ******************************

//*****************************************************************************

//****************************.LedSimulationDisplay.***************************
// Purpose : If the macro RPICODE is defined then sets gpio pin 22 to high or
//           low. Also calls LedSimulationDisplay().
// Inputs  : pstLine - pointer to GPIO line object.
// Outputs : None.
// Return  : true.
// Notes   : None.
//*****************************************************************************
bool LedSimulationBlinkLED(struct gpiod_line *pstLine, bool *pblLedStatus)
{
    // If Macro "RPICODE" is defined
    #ifdef RPICODE

    // if LED is indicated to be OFF
    if (true != *pblLedStatus)
    {
        // Set Output to low
        if (true != gpiodToolsGpioSet(&pstLine, ACTIVE_LOW))
        {
            printf("Failed to turn LED OFF");
        }
    }
    // if LED is indicated to be ON
    else
    {
        // Set Output to high
        if (true != gpiodToolsGpioSet(&pstLine, ACTIVE_HIGH))
        {
            printf("Failed to turn LED ON");
        }
    }
    #else

    (void) pstLine;

    #endif

    //Print LED Status
    LedSimulationDisplay(pblLedStatus);

    return true;
}

//****************************.LedSimulationDisplay.***************************
// Purpose : Prints LED status(ON/OFF).
// Inputs  : None.
// Outputs : None.
// Return  : true.
// Notes   : None.
//*****************************************************************************
bool LedSimulationDisplay(bool *pblLedStatus)
{

    // if LED is indicated to be OFF
    if (true != *pblLedStatus)
    {
        printf("\nLED OFF\n");

        usleep(OFF_TIME);

        // Set LED status to indicate ON
        *pblLedStatus = true;
    }
    // if LED is indicated to be ON
    else
    {
        printf("\nLED ON\n");

        usleep(ON_TIME);

        // Set LED status to indicate OFF
        *pblLedStatus = false;
    }

    return true;
}
// EOF
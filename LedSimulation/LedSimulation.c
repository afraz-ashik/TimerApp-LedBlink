//******************************* Led Simulation ******************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
// File    : LedSimulation.c
// Summary : Infinite printf of "LED ON" "LED OFF" every second.
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

//******************************.PrintLedStatus.*******************************
// Purpose : Prints "LED ON" "LED OFF" every second.
// Inputs  : *blpLedStatus - either true or false when fucntion is called
// Outputs : *blpLedStatus - compliment of input BlLedStatus.
// Return  : blResult - false if pointer is NULL, else true.
// Notes   : None.
//*****************************************************************************
bool LedSimulationDisplay(bool *blpLedStatus)
{
    bool blResult = true;

    // If pointer is Null
    if (NULL == blpLedStatus)
    {
        blResult = false;
    }
    // if LED is indicated to be OFF
    else if (!*blpLedStatus)
    {
        printf("\nLED OFF\n");

        // Set LED status to indicate OFF
        *blpLedStatus = true;
    }
    // if LED is indicated to be ON
    else
    {
        printf("\nLED ON\n");

        // Set LED status to indicate ON
        *blpLedStatus = false;
    }

    return blResult;
}

// EOF
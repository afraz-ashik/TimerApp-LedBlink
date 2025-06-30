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
static bool sblLedStatus = false;

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//*****************************************************************************

//******************************.PrintLedStatus.*******************************
// Purpose : Prints "LED ON" "LED OFF" every second.
// Inputs  : None.
// Outputs : None.
// Return  : blResult - true.
// Notes   : None.
//*****************************************************************************
bool LedSimulationDisplay()
{
    // if LED is indicated to be OFF
    if (!sblLedStatus)
    {
        printf("\nLED OFF\n");

        // Set LED status to indicate ON
        sblLedStatus = true;
    }
    // if LED is indicated to be ON
    else
    {
        printf("\nLED ON\n");

        // Set LED status to indicate OFF
        sblLedStatus = false;
    }

    return true;
}

// EOF
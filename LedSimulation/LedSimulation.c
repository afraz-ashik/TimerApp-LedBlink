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
//           low. Also calls LedSimulationDisplay().
// Inputs  : pstLine - pointer to GPIO line object.
// Outputs : None.
// Return  : true.
// Notes   : None.
//*****************************************************************************
bool LedSimulationBlinkLED(struct gpiod_line **pstLine)
{
    (void)*pstLine;
    // If Macro "RPICODE" is defined
    #ifdef RPICODE

    // if LED is indicated to be OFF
    if (!gsblLedStatus)
    {
        // Set Output to low
        if (!gpiodToolsGpioSet(pstLine,ACTIVE_LOW))
        {
            printf("Failed to turn LED OFF");
        }
    }
    // if LED is indicated to be ON
    else
    {
        // Set Output to high
        if (!gpiodToolsGpioSet(pstLine,ACTIVE_HIGH))
        {
            printf("Failed to turn LED ON");
        }
    }

    #endif

    //Print LED Status
    LedSimulationDisplay();

    return true;
}

//****************************.LedSimulationDisplay.***************************
// Purpose : Prints LED status(ON/OFF).
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
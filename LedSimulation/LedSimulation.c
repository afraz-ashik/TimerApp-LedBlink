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
#include "gpiodWrapper.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************
static bool gsblLedStatus = false;

//****************************** Local Functions ******************************

//*****************************************************************************

//****************************.LedSimulationDisplay.***************************
// Purpose : If the macro RPICODE is defined then sets gpio pin 22 to high or
//           low. Also calls LedSimulationDisplay().
// Inputs  : None.
// Outputs : None.
// Return  : true.
// Notes   : Functions in gpiodWrapper.c is used if cross-compiled.
//*****************************************************************************
bool LedSimulationBlinkLED()
{
    // If Macro "RPICODE" is defined
    #ifdef RPICODE

    // Declare gpiochip number
    struct gpiod_chip *pstChip = NULL;
    pstChip = gpiodWrapperOpenGpioChip();

    // Open gpio line
    struct gpiod_line *pstLine = NULL;
    pstLine = gpiodWrapperOpenGpioLine(pstChip);

    // if LED is indicated to be OFF
    if (!gsblLedStatus)
    {
        // Set Output to low
        gpiodWrapperSetGpio(pstLine,ACTIVE_LOW);
    }
    // if LED is indicated to be ON
    else
    {
        // Set Output to high
        gpiodWrapperSetGpio(pstLine,ACTIVE_HIGH);
    }
    gpiodWrapperCloseGpio(pstLine,pstChip);

    #endif

    LedSimulationDisplay();

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
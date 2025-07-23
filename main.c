//*********************************** Main ************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
// File    : main.c
// Summary : Prints current time in GMT, IST and PST timezone.
//           Infinite printf of "LED ON" "LED OFF" every second.
//           Blink LED in Raspberrypi if cross-compiled.
// Note    : None
// Author  : Afraz Ashik
// Date    : 18/JUNE/25
//*****************************************************************************

//******************************* Include Files *******************************
#include "appTimer.h"
#include "LedSimulation.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//*****************************************************************************

//******************************.mainFunction.*********************************
// Purpose : Display time and date in GMT, IST and PST timezone.
//           Prints "LED ON" "LED OFF" every second.
//           calls function to Set gpio pin to high/low if cross compiled.
// Inputs  : None.
// Outputs : None.
// Return  : Zero.
// Notes   : None.
//*****************************************************************************
int main()
{
    bool blLedStatus = false;
    time_t ulCurrentTime = 0;

    // If the macro is defined intitalize gpio chip
    #ifdef RPICODE

    // Declare gpiochip number
    struct gpiod_chip *pstChip = NULL;

    // Open gpio line
    struct gpiod_line *pstLine = NULL;

    if (!gpiodToolsGpioInit(&pstLine,&pstChip))
    {
        printf("Gpio initiaziation Failed!");
    }

    #endif

    while (true)
    {
        // Move Cursor to top-left and clear screen
        printf("\x1b[H\x1b[J");

        // Current time
        time(&ulCurrentTime);

        printf("\nUTC (0:00)\n");

        // GMT time
        if (AppTimerConvertToTime(ulCurrentTime))
        {
            printf("Epoch : %lu\n",ulCurrentTime);
        }
        else
        {
            printf("\nInvalid Epoch\n");
        }

        printf("\nIST (+5:30)\n");

        // IST time
        if (!AppTimerConvertToTime(ulCurrentTime + IST_DIFFERENCE))
        {
            printf("\nInvalid Epoch\n");
        }
        else
        {
            // Default case
        }

        printf("\nPST (-8:00)\n");

        // PST time
        if (!AppTimerConvertToTime(ulCurrentTime - PST_DIFFERENCE))
        {
            printf("\nInvalid Epoch\n");
        }
        else
        {
            // Default case
        }

        // If macro is defined, Call the function to Blink Led
        #ifdef RPICODE

        // Print LED Status and Blink LED
        LedSimulationBlinkLED(pstLine,&blLedStatus);

        // Only if macro not defined, call the function to print LED status
        #else

        LedSimulationDisplay(&blLedStatus);

        #endif
    }

    #ifdef RPICODE

    gpiodToolsGpioClose(&pstLine,&pstChip);

    #endif

    return 0;
}
//EOF
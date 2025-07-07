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
//           Set gpio pin to high then low if cross-compiled
// Inputs  : None.
// Outputs : None.
// Return  : Zero.
// Notes   : Refresh time every second.
//*****************************************************************************
int main()
{
    time_t ulCurrentTime = 0;

    while(true)
    {
        // Move Cursor to top-left and clear screen
        printf("\x1b[H\x1b[J");

        // Current time
        time(&ulCurrentTime);

        printf("\nUTC (0:00)\n");

        // GMT time
        if(AppTimerConvertToTime(ulCurrentTime))
        {
            printf("Epoch : %lu\n",ulCurrentTime);
        }
        else
        {
            printf("\nInvalid Epoch\n");
        }

        printf("\nIST (+5:30)\n");

        // IST time
        if(!AppTimerConvertToTime(ulCurrentTime + IST_DIFFERENCE))
        {
            printf("\nInvalid Epoch\n");
        }
        else
        {
            // Default case
        }

        printf("\nPST (-8:00)\n");

        // PST time
        if(!AppTimerConvertToTime(ulCurrentTime - PST_DIFFERENCE))
        {
            printf("\nInvalid Epoch\n");
        }
        else
        {
            // Default case
        }

        // Print LED Status
        LedSimulationDisplay();
    }

    return 0;
}
//EOF
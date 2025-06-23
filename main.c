//******************************** App Timer **********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
// File    : main.c
// Summary : Printing current time in GMT, IST and PST timezone.
// Note    : None
// Author  : Afraz Ashik
// Date    : 16/06/25
//*****************************************************************************

//******************************* Include Files *******************************
#include "appTimer.h"
#include <unistd.h>

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//******************************.mainFunction.*********************************
// Purpose : Display time and date in GMT, IST and PST timezone.
// Inputs  : None.
// Outputs : Prints time and date in GMT, IST and PST timezone.
// Return  : Zero.
// Notes   : Refresh time every second.
//*****************************************************************************
int main()
{
    time_t ulCurrentTime = ZERO;

    while(true)
    {
        printf("\x1b[H\x1b[J"); // Move Cursor to top-left and clear screen

        time(&ulCurrentTime); // Current time

        printf("\nUTC (0:00)\n");

        if(AppTimerConvertToTime(ulCurrentTime))// GMT time
        {
            printf("Epoch : %lu\n",ulCurrentTime);
        }
        else
        {
            printf("\nInvalid Epoch\n");
        }

        printf("\nIST (+5:30)\n");

        if(AppTimerConvertToTime(ulCurrentTime + IST_DIFFERENCE))// IST time
        {
            // Default case
        }
        else
        {
            printf("\nInvalid Epoch\n");
        }

        printf("\nPST (-8:00)\n");

        if(AppTimerConvertToTime(ulCurrentTime - PST_DIFFERENCE))// PST time
        {
            // Default case
        }
        else
        {
            printf("\nInvalid Epoch\n");
        }

        sleep(ONE_SECOND); // Wait one second for refreshing time
    }

    return 0;
}
//EOF
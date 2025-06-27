//******************************** App Timer **********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
// File    : main.c
// Summary : Prints current time in GMT, IST and PST timezone.
//           Infinte printf of "LED ON" "LED OFF" every second.
// Note    : None
// Author  : Afraz Ashik
// Date    : 18/JUNE/25
//*****************************************************************************

//******************************* Include Files *******************************
#include "appTimer.h"
#include <unistd.h>


//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************
static bool PrintLedStatus(bool *blLedStatus);

//******************************.PrintLedStatus.*******************************
// Purpose : Prints "LED ON" "LED OFF" every second.
// Inputs  : blLedStatus - either true or false when fucntion is called
// Outputs : blLedStatus - complimented.
// Return  : None.
// Notes   : None.
//*****************************************************************************
static bool PrintLedStatus(bool *blpLedStatus)
{
    bool blNullFLag =true;

    // If pointer is Null
    if (NULL == blpLedStatus)
    {
        blNullFLag = false;
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

    return blNullFLag;
}

//******************************.mainFunction.*********************************
// Purpose : Display time and date in GMT, IST and PST timezone.
//           Prints "LED ON" "LED OFF" every second.
// Inputs  : None.
// Outputs : None.
// Return  : Zero.
// Notes   : Refresh time every second.
//*****************************************************************************
int main()
{
    time_t ulCurrentTime = 0;
    bool blLedStatus = false;

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
        if (!PrintLedStatus(&blLedStatus))
        {
            printf("\nNull pointer\n");
        }

        // Wait one second for refreshing time
        sleep(1);
    }

    return 0;
}
//EOF
//******************************** App Timer **********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
// File    : main.c
// Summary : Print current time in real time in GMT, IST and PST timezone.
// Note    : None
// Author  : Afraz Ashik
// Date    : 16/06/25
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdio.h>
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
    while(true)
    {
        time_t CurrentTime;
        
        time(&CurrentTime); // Current time
        AppTimerUTC(CurrentTime); // GMT time
        AppTimerIST(CurrentTime); // IST time
        AppTimerPST(CurrentTime); // PST time
        
        sleep(ONE_SECOND); // Wait one second for refreshing time

    }

    return 0;
}
//EOF
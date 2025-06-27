//******************************** App Timer **********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
// File    : appTimer.c
// Summary : Display the current time in GMT, IST and PST timezone.
// Note    : Function to convert Epoch time to standard time defined here.
// Author  : Afraz Ashik
// Date    : 18/June/2025
//*****************************************************************************

//******************************* Include Files *******************************
#include "appTimer.h"
#include <string.h>

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//*****************************************************************************

//***************************.AppTimerConvertToTime.***************************
// Purpose : Convert Epoch time to Standard time .
// Inputs  : ulEpochTime - number of seconds since beginning of 1970
// Outputs : None
// Return  : blResult - false if ulEpochTime is zero, else true.
// Notes   : None
//*****************************************************************************
bool AppTimerConvertToTime(time_t ulEpochTime)
{
    // Return variable
    bool blResult = true;

    uint16 unMinutes = 0;
    uint16 unHours   = 0;
    uint16 unSeconds = 0;
    uint32 ulTotalDays = 0;
    uint16 unMonth = 0;
    uint16 unDay = 0;
    uint32 ulYear = 0;
    uint16 unIdx = 0;
    uint8 ucMeridium[MERIDIUM_SIZE] = "AM";

    if (ZERO == ulEpochTime)
    {
        blResult = false;
    }

    // Storing Current second
    unSeconds = ulEpochTime % SECONDS;
    ulEpochTime /= SECONDS;

    // Storing current Minute
    unMinutes = ulEpochTime % SECONDS_IN_A_MINUTE;
    ulEpochTime /= SECONDS_IN_A_MINUTE;

    // Storing Current Hour
    unHours= ulEpochTime % HOURS_IN_A_DAY;
    ulEpochTime /= HOURS_IN_A_DAY;

    //Storing remaining days
    ulTotalDays = ulEpochTime;

    //Store Current Year
    ulYear = (ulEpochTime / DAYS_IN_A_YEAR) + INITIAL_YEAR;

    for ( unIdx = INITIAL_YEAR; unIdx <= ulYear; unIdx++)
    {
        //If leap year
        if (ZERO == unIdx % LEAP_YEAR_GAP && 
           ((ZERO != (unIdx % LEAP_YEAR_CENTURY_EXCEPTION)) ||
           (ZERO == (unIdx % LEAP_YEAR_CENTURY_CORRECTION))))
        {
            // If current year is leap year
            if (unIdx == ulYear) 
            {
                // If current year is leap year & current month is Jan or Feb
                if (JAN_OR_FEB_DATE_FLAG >= ulTotalDays)
                {
                    break;
                }
                // Subtract a day
                ulTotalDays--;
                break;
            }

            // Subtract 366
            ulTotalDays -= DAYS_IN_LEAP_YEAR;
        }
        else
        {
            if (unIdx == ulYear)
            {
                break;
            }
            
            // Subtract 365
            ulTotalDays -= DAYS_IN_A_YEAR;
        }
    }
    
    for (unIdx = MONTH_START; unIdx <= NUMBER_OF_MONTHS; unIdx++)
    {
        if (MINIMUM_DAYS_THRESHOLD >= ulTotalDays)
        {
            break;
        }

        if (FIRST_PART_OF_THE_YEAR >= unIdx)
        {
            // If even subtract 30
            if (IS_EVEN(unIdx))
            {
                // If current month is February Subtract 28
                if (FEBRUARY == unIdx)
                {
                    ulTotalDays -= DAYS_IN_FEBRUARY;
                }
                else
                {
                    ulTotalDays -= MIN_DAYS_IN_A_MONTH;
                }
            }
            // Else subtract 31
            else
            {
                ulTotalDays -= MAX_DAYS_IN_A_MONTH;
            }
        }
        
        if (FIRST_PART_OF_THE_YEAR < unIdx)
        {
            // If even subtract 31
            if (IS_EVEN(unIdx))
            {
                ulTotalDays -= MAX_DAYS_IN_A_MONTH;
            }
            //Else subtract 30
            else
            {
                ulTotalDays -= MIN_DAYS_IN_A_MONTH;
            }
            
        }
    }
    // Store Current month
    unMonth = unIdx;
    // Store Current day - Add 1 to get current date
    unDay = ulTotalDays + INITIAL_DAY;

    if (PM_CHECK <= unHours)
    {
        strcpy((char*) ucMeridium,"PM");

        if (PM_CHECK < unHours)
        {
            // Update railway time
            unHours -= MERIDIUM_FACTOR;
        }
    }
    else
    {
        if (AM_CHECK == unHours)
        {
            // Update railway time
            unHours += MERIDIUM_FACTOR;
        }
    }

    printf("--------------------\n");
    printf("TIME  : %02hu:%02hu:%02hu %s\n",
           unHours,unMinutes,unSeconds,ucMeridium);
    printf("DATE  : %02hu/%02hu/%lu\n",unDay,unMonth,ulYear);

    return blResult;
}

// EOF
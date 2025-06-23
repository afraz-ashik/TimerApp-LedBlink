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
#include <common.h>

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//*****************************************************************************

//***************************.AppTimerConvertToTime.***************************
// Purpose : Convert Epoch time to Standard time .
// Inputs  : ulEpochTime - number of seconds since beginning of 1970
// Outputs : None
// Return  : blResult - False if ulEpochTime is zero, else true.
// Notes   : None
//*****************************************************************************
bool AppTimerConvertToTime(time_t ulEpochTime)
{
    bool blResult = true; // Return variable
    uint16 unMinutes = ZERO;
    uint16 unHours = ZERO;
    uint32 ulTotalDays = ZERO;
    uint32 ulYear = ZERO;
    uint16 unSeconds = ZERO;
    uint16 unIdx = ZERO;
    uint16 unMonth = ZERO;
    uint16 unDay = ZERO;
    uint8 ucMeridium[MERIDIUM_SIZE] = "AM";

    if (ZERO == ulEpochTime)
    {
        blResult = false;
    }

    unSeconds = ulEpochTime % SECONDS; // Storing Current second
    ulEpochTime /= SECONDS;

    unMinutes = ulEpochTime % SECONDS_IN_A_MINUTE; // Storing current Minute
    ulEpochTime /= SECONDS_IN_A_MINUTE;

    unHours= ulEpochTime % HOURS_IN_A_DAY; // Storing Current Hour
    ulEpochTime /= HOURS_IN_A_DAY;

    ulTotalDays = ulEpochTime; //Storing remaining days

    ulYear = (ulEpochTime / DAYS_IN_A_YEAR) + INITIAL_YEAR; // Store Curr_year

    for ( unIdx = INITIAL_YEAR; unIdx < ulYear; unIdx++)
    {
        if (ZERO == unIdx % LEAP_YEAR_GAP && 
            (ZERO != (unIdx % LEAP_YEAR_CENTURY_EXCEPTION) ||
             ZERO == (unIdx % LEAP_YEAR_CENTURY_CORRECTION)))
        {
            ulTotalDays -= DAYS_IN_LEAP_YEAR; // Subtract 366
        }
        else
        {
            ulTotalDays -= DAYS_IN_A_YEAR; // Subtract 365
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
            if (IS_EVEN(unIdx))
            {
                if (FEBRUARY == unIdx) // If February
                {
                    ulTotalDays -= DAYS_IN_FEBRUARY;

                    if (FEBRUARY == unIdx && 
                        (ZERO == ulYear % LEAP_YEAR_GAP &&
                         (ZERO != (ulYear % LEAP_YEAR_CENTURY_EXCEPTION)||
                          ZERO == (ulYear % LEAP_YEAR_CENTURY_CORRECTION))))
                        {
                            ulTotalDays--; // If leap year
                        }
                }
                else
                {
                    ulTotalDays -= MIN_DAYS_IN_A_MONTH;
                }
            }
            else // If odd
            {
                ulTotalDays -= MAX_DAYS_IN_A_MONTH;
            }
            
        }
        if (FIRST_PART_OF_THE_YEAR < unIdx)
        {
            if (IS_EVEN(unIdx))
            {
                ulTotalDays -= MAX_DAYS_IN_A_MONTH;
            }
            else // If odd
            {
                ulTotalDays -= MIN_DAYS_IN_A_MONTH;
            }
            
        } 
    }
    unMonth = unIdx; // Add 1 to index to get Current month
    unDay = ulTotalDays + INCREMENT_ONE; // Add 1 to remaining days - Curr_Day

    if (PM_CHECK <= unHours)
    {
        strcpy((char*) ucMeridium,"PM");
        if (PM_CHECK < unHours)
        {
            unHours -= MERIDIUM_FACTOR; // Update railway time
        }
    }
    else
    {
        if (AM_CHECK == unHours)
        {
            unHours += MERIDIUM_FACTOR; // Update railway time
        }
    }

    printf("--------------------\n");
    printf("TIME  : %02hu:%02hu:%02hu %s\n",
        unHours,unMinutes,unSeconds,ucMeridium);
    printf("DATE  : %02hu/%02hu/%lu\n",unDay,unMonth,ulYear);

    return blResult;
}

// EOF
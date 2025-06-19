//******************************** App Timer **********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
// File    : appTimer.c
// Summary : Print current time in real time in GMT, IST and PST timezone.
// Note    : Functions of GMT, IST and PST timezones are defined here.
// Author  : Afraz Ashik
// Date    : 18/June/2025
//*****************************************************************************
//******************************* Include Files *******************************
#include <stdio.h>
#include "appTimer.h"
#include <string.h>
#include <../common.h>

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//*****************************************************************************

//******************************.AppTimerUTC.**********************************
// Purpose : Prints current time in GMT timezone.
// Inputs  : EpochTime - number of seconds since beginning of 1970
// Outputs : None
// Return  : False if EpochTime is zero.
// Return  : True
// Notes   : None
//*****************************************************************************
bool AppTimerUTC(time_t EpochTime)
{
    if (ZERO == EpochTime)
    {
        return false;
    }

    time_t CurrentEpoch = EpochTime;
    uint16 unMinutes;
    uint16 unHours;
    uint32 ulTotalDays;
    uint32 ulYear;
    uint16 unSeconds;
    uint16 unIterator;
    uint16 unMonth;
    uint16 unDay;
    uint8 ucMeridium[MERIDIUM_SIZE];
    uint16 unDaysinMonths[]={DAYS_IN_JANUARY,DAYS_IN_FEBRUARY,DAYS_IN_MARCH,
    DAYS_IN_APRIL,DAYS_IN_MAY,DAYS_IN_JUNE,DAYS_IN_JULY,DAYS_IN_AUGUST,
    DAYS_IN_SEPTEMBER,DAYS_IN_OCTOBER,DAYS_IN_NOVEMBER,DAYS_IN_DECEMBER};
    
    unSeconds= EpochTime % SECONDS; // Current second
    EpochTime /= SECONDS;

    unMinutes= EpochTime % MINUTES; // Current Minute
    EpochTime /= MINUTES;

    unHours= EpochTime % HOURS_IN_A_DAY; // Current Hour
    ulTotalDays= EpochTime / HOURS_IN_A_DAY; // Remaining #days
    EpochTime /= HOURS_IN_A_DAY;
    ulYear= (EpochTime / DAYS_IN_A_YEAR) + INITIAL_YEAR; // Curr_year
    
    for ( unIterator = INITIAL_YEAR; unIterator < ulYear; unIterator++)
    {
        if (ZERO == unIterator % LEAP_YEAR_GAP && 
            (ZERO != (unIterator % LEAP_YEAR_CHECK_ONE) ||
             ZERO == (unIterator % LEAP_YEAR_CHECK_TWO)))
        {
            ulTotalDays -= DAYS_IN_LEAP_YEAR;
        }
        else
        {
            ulTotalDays -= DAYS_IN_A_YEAR;
        }
        
    }

    for (unIterator = ZERO; unIterator < NUMBER_OF_MONTHS; unIterator++)
    {
        if (MINIMUM_DAYS_IN_MONTH>=ulTotalDays)
        {
            break;
        }
        
        ulTotalDays -= unDaysinMonths[unIterator];
        if (FEBRUARY == unIterator && (ZERO == ulYear % LEAP_YEAR_GAP && 
            (ZERO != (ulYear % LEAP_YEAR_CHECK_ONE) ||
            ZERO == (ulYear % LEAP_YEAR_CHECK_TWO))))
        {
            ulTotalDays--;
        }

        unMonth = unIterator+INCREMENT_ONE;
        unDay = ulTotalDays;
    }
    
    if (PM_CHECK <= unHours)
    {
        strcpy(ucMeridium,"PM");
        if (PM_CHECK < unHours)
        {
            unHours -= MERIDIUM_FACTOR;
        }
    }
    else
    {
        strcpy(ucMeridium,"AM");
        if (AM_CHECK == unHours)
        {
            unHours += MERIDIUM_FACTOR;
        }
        
    }

    printf("UTC (0:00)\n");
    printf("--------------------\n");
    printf("TIME  : %02hu:%02hu:%02hu %s\n",
        unHours,unMinutes,unSeconds,ucMeridium);
    printf("DATE  : %02hu/%02hu/%lu\n",++unDay,++unMonth,ulYear);
    printf("Epoch : %d\n",CurrentEpoch);

    return true;
}

//******************************.AppTimerIST.**********************************
// Purpose : Prints current time in IST timezone.
// Inputs  : EpochTime - number of seconds since beginning of 1970
// Outputs : None
// Return  : False if EpochTime is zero.
// Return  : True
// Notes   : None
//*****************************************************************************
bool AppTimerIST(time_t EpochTime)
{
    if (ZERO == EpochTime)
    {
        return false;
    }

    uint16 unMinutes;
    uint16 unHours;
    uint32 ulTotalDays;
    uint32 ulYear;
    uint16 unSeconds;
    uint16 unIterator;
    uint16 unMonth;
    uint32 unDay;
    uint8 ucMeridium[MERIDIUM_SIZE];
    uint16 unDaysinMonths[]={DAYS_IN_JANUARY,DAYS_IN_FEBRUARY,DAYS_IN_MARCH,
    DAYS_IN_APRIL,DAYS_IN_MAY,DAYS_IN_JUNE,DAYS_IN_JULY,DAYS_IN_AUGUST,
    DAYS_IN_SEPTEMBER,DAYS_IN_OCTOBER,DAYS_IN_NOVEMBER,DAYS_IN_DECEMBER};
    
    EpochTime += IST_DIFFERENCE; // Convert to IST 
    unSeconds= EpochTime % SECONDS; // Current second
    EpochTime /= SECONDS;

    unMinutes= EpochTime % MINUTES; // Current Minute
    EpochTime /= MINUTES;

    unHours= EpochTime % HOURS_IN_A_DAY; // Current Hour
    ulTotalDays= EpochTime / HOURS_IN_A_DAY; // Remaining #days
    EpochTime /= HOURS_IN_A_DAY;
    ulYear= (EpochTime / DAYS_IN_A_YEAR) + INITIAL_YEAR; // Curr_year
    
    for ( unIterator = INITIAL_YEAR; unIterator < ulYear; unIterator++)
    {
        if (ZERO == unIterator % LEAP_YEAR_GAP && 
            (ZERO != (unIterator % LEAP_YEAR_CHECK_ONE) ||
             ZERO == (unIterator % LEAP_YEAR_CHECK_TWO)))
        {
            ulTotalDays -= DAYS_IN_LEAP_YEAR;
        }
        else
        {
            ulTotalDays -= DAYS_IN_A_YEAR;
        }
    }

    for (unIterator = ZERO; unIterator < NUMBER_OF_MONTHS; unIterator++)
    {
        if (MINIMUM_DAYS_IN_MONTH>=ulTotalDays)
        {
            break;
        }
        
        ulTotalDays -= unDaysinMonths[unIterator];
        if (FEBRUARY == unIterator && (ZERO == ulYear % LEAP_YEAR_GAP && 
            (ZERO != (ulYear % LEAP_YEAR_CHECK_ONE) ||
            ZERO == (ulYear % LEAP_YEAR_CHECK_TWO))))
        {
            ulTotalDays--;
        }

        unMonth = unIterator+INCREMENT_ONE;
        unDay = ulTotalDays;
    }
    
    if (PM_CHECK <= unHours)
    {
        strcpy(ucMeridium,"PM");
        if (PM_CHECK < unHours)
        {
            unHours -= MERIDIUM_FACTOR;
        }
    }
    else
    {
        strcpy(ucMeridium,"AM");
        if (AM_CHECK == unHours)
        {
            unHours += MERIDIUM_FACTOR;
        }
    }

    printf("\nIST (+5:30)\n");
    printf("--------------------\n");
    printf("TIME  : %02hu:%02hu:%02hu %s\n",
        unHours,unMinutes,unSeconds,ucMeridium);
    printf("DATE  : %02hu/%02hu/%lu\n",++unDay,++unMonth,ulYear);

    return true;
}

//******************************.AppTimerPST.**********************************
// Purpose : Prints current time in PST timezone.
// Inputs  : EpochTime - number of seconds since beginning of 1970
// Outputs : None
// Return  : False if EpochTime is zero.
// Return  : True
// Notes   : None
//*****************************************************************************
bool AppTimerPST(time_t EpochTime)
{
    if (ZERO == EpochTime)
    {
        return false;
    }

    uint16 unMinutes;
    uint16 unHours;
    uint32 ulTotalDays;
    uint32 ulYear;
    uint16 unSeconds;
    uint16 unIterator;
    uint16 unMonth;
    uint16 unDay;
    uint8 ucMeridium[MERIDIUM_SIZE];
    uint16 unDaysinMonths[]={DAYS_IN_JANUARY,DAYS_IN_FEBRUARY,DAYS_IN_MARCH,
    DAYS_IN_APRIL,DAYS_IN_MAY,DAYS_IN_JUNE,DAYS_IN_JULY,DAYS_IN_AUGUST,
    DAYS_IN_SEPTEMBER,DAYS_IN_OCTOBER,DAYS_IN_NOVEMBER,DAYS_IN_DECEMBER};
    
    EpochTime -= PST_DIFFERENCE; // Convert to IST 
    unSeconds= EpochTime % SECONDS; // Current second
    EpochTime /= SECONDS;

    unMinutes= EpochTime % MINUTES; // Current Minute
    EpochTime /= MINUTES;

    unHours= EpochTime % HOURS_IN_A_DAY; // Current Hour
    ulTotalDays= EpochTime / HOURS_IN_A_DAY; // Remaining #days
    EpochTime /= HOURS_IN_A_DAY;
    ulYear= (EpochTime / DAYS_IN_A_YEAR) + INITIAL_YEAR; // Curr_year
    
    for ( unIterator = INITIAL_YEAR; unIterator < ulYear; unIterator++)
    {
        if (ZERO == unIterator % LEAP_YEAR_GAP && 
            (ZERO != (unIterator % LEAP_YEAR_CHECK_ONE) ||
             ZERO == (unIterator % LEAP_YEAR_CHECK_TWO)))
        {
            ulTotalDays -= DAYS_IN_LEAP_YEAR;
        }
        else
        {
            ulTotalDays -= DAYS_IN_A_YEAR;
        }
        
    }

    for (unIterator = ZERO; unIterator < NUMBER_OF_MONTHS; unIterator++)
    {
        if (MINIMUM_DAYS_IN_MONTH>=ulTotalDays)
        {
            break;
        }
        
        ulTotalDays -= unDaysinMonths[unIterator];
        if (FEBRUARY == unIterator && (ZERO == ulYear % LEAP_YEAR_GAP && 
            (ZERO != (ulYear % LEAP_YEAR_CHECK_ONE) ||
            ZERO == (ulYear % LEAP_YEAR_CHECK_TWO))))
        {
            ulTotalDays--;
        }

        unMonth = unIterator+INCREMENT_ONE;
        unDay = ulTotalDays;
    }
    
    if (PM_CHECK <= unHours)
    {
        strcpy(ucMeridium,"PM");
        if (PM_CHECK < unHours)
        {
            unHours -= PM_CHECK;
        }
    }
    else
    {
        strcpy(ucMeridium,"AM");
        if (AM_CHECK == unHours)
        {
            unHours += MERIDIUM_FACTOR;
        }
        
    }
    
    printf("\nPST (-8:00)\n");
    printf("--------------------\n");
    printf("TIME  : %02hu:%02hu:%02hu %s\n",
        unHours,unMinutes,unSeconds,ucMeridium);
    printf("DATE  : %02hu/%02hu/%lu\n",++unDay,++unMonth,ulYear);

    return true;
}
// EOF
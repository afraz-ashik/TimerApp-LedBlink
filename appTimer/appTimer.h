//******************************** App Timer **********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//*****************************************************************************
//
// Summary : Macros and forwards decalrations are included
// Note    : None
// 
//*****************************************************************************
#ifndef _APP_TIMER_H_
#define _APP_TIMER_H_

//******************************* Include Files *******************************
#include <time.h>
#include <common.h>

//******************************* Global Types ********************************

//***************************** Global Constants ******************************
#define ZERO                            (0)
#define IS_EVEN(unNum)                  ((unNum % 2) == 0)
#define JAN_OR_FEB_DATE_FLAG            (58)
#define MONTH_START                     (1)
#define INITIAL_DAY                     (1)
#define SECONDS                         (60)
#define SECONDS_IN_A_MINUTE             (60)
#define HOURS_IN_A_DAY                  (24)
#define DAYS_IN_A_YEAR                  (365)
#define DAYS_IN_LEAP_YEAR               (366)
#define INITIAL_YEAR                    (1970)
#define NUMBER_OF_MONTHS                (12)
#define MAX_DAYS_IN_A_MONTH             (31)
#define MIN_DAYS_IN_A_MONTH             (30)
#define DAYS_IN_FEBRUARY                (28)
#define FIRST_PART_OF_THE_YEAR          (7)
#define LEAP_YEAR_GAP                   (4)
#define LEAP_YEAR_CENTURY_EXCEPTION     (100)
#define LEAP_YEAR_CENTURY_CORRECTION    (400)
#define MINIMUM_DAYS_THRESHOLD          (29)
#define FEBRUARY                        (2)
#define PM_CHECK                        (12)
#define AM_CHECK                        (0)
#define MERIDIUM_FACTOR                 (12)
#define MERIDIUM_SIZE                   (3)
#define IST_DIFFERENCE                  (19800)
#define PST_DIFFERENCE                  (25200)

//***************************** Global Variables ******************************

//**************************** Forward Declarations ***************************
bool AppTimerConvertToTime(time_t ulEpochTime);

//*********************** Inline Method Implementations ***********************

#endif // _APP_TIMER_H_ 
// EOF 
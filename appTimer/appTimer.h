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
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

//******************************* Global Types ******************************** 

//***************************** Global Constants ****************************** 
#define BUFFER_SIZE             (20)
#define ZERO                    (0)
#define ONE_SECOND              (1)
#define INCREMENT_ONE           (1)
#define SECONDS                 (60)
#define MINUTES                 (60)
#define HOURS_IN_A_DAY          (24)
#define DAYS_IN_A_YEAR          (365)
#define DAYS_IN_LEAP_YEAR       (366)
#define INITIAL_YEAR            (1970)
#define NUMBER_OF_MONTHS        (12)
#define DAYS_IN_JANUARY         (31)
#define DAYS_IN_FEBRUARY        (28)
#define DAYS_IN_MARCH           (31)
#define DAYS_IN_APRIL           (30)
#define DAYS_IN_MAY             (31)
#define DAYS_IN_JUNE            (30)
#define DAYS_IN_JULY            (31)
#define DAYS_IN_AUGUST          (31)
#define DAYS_IN_SEPTEMBER       (30)
#define DAYS_IN_OCTOBER         (31)
#define DAYS_IN_NOVEMBER        (30)
#define DAYS_IN_DECEMBER        (31)
#define LEAP_YEAR_GAP           (4)
#define LEAP_YEAR_CHECK_ONE     (100)
#define LEAP_YEAR_CHECK_TWO     (400)
#define MINIMUM_DAYS_IN_MONTH   (28)
#define FEBRUARY                (2)
#define PM_CHECK                (12)
#define AM_CHECK                (0)
#define MERIDIUM_FACTOR         (12)
#define MERIDIUM_SIZE           (3)
#define IST_DIFFERENCE          (19800)
#define PST_DIFFERENCE          (25200)

//***************************** Global Variables ****************************** 

//**************************** Forward Declarations *************************** 
bool AppTimerUTC(time_t CurrentTime);
bool AppTimerIST(time_t CurrentTime);
bool AppTimerPST(time_t CurrentTime);

//*********************** Inline Method Implementations *********************** 

#endif // _APP_TIMER_H_ 
// EOF 
//******************************* Led Simulation ******************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// Summary : Include files declared, macros & forward declarations are included
// Note    : None
//
//*****************************************************************************
#ifndef _LED_SIMULATION_H_
#define _LED_SIMULATION_H_

//******************************* Include Files *******************************
#include "common.h"
#include <unistd.h>
#include "gpiodTools.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************
#define ON_TIME     (840000)
#define OFF_TIME    (532000)
#define ACTIVE_HIGH (1)
#define ACTIVE_LOW  (0)

//***************************** Global Variables ******************************

//**************************** Forward Declarations ***************************
bool LedSimulationBlinkLED(struct gpiod_line *pstLine, bool *pblLedStatus);
bool LedSimulationDisplay(bool *pblLedStatus);

//*********************** Inline Method Implementations ***********************

#endif // _LED_SIMULATION_H_
// EOF
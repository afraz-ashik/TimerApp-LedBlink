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
#include "gpiod.h"
//******************************* Global Types ********************************

//***************************** Global Constants ******************************
#define GPIO_PIN    (22)
#define ON_TIME     (840000)
#define OFF_TIME    (532000)
#define ACTIVE_HIGH (1)
#define ACTIVE_LOW  (0)
//***************************** Global Variables ******************************

//**************************** Forward Declarations ***************************
bool LedSimulationBlinkLED();
bool LedSimulationDisplay();

//*********************** Inline Method Implementations ***********************

#endif // _LED_SIMULATION_H_
// EOF
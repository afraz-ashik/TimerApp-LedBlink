//******************************* gpiod Tools *******************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// Summary : Include files declared, macros & forward declarations are included
// Note    : None
//
//*****************************************************************************
#ifndef _GPIOD_TOOLS_H_
#define _GPIOD_TOOLS_H_

//******************************* Include Files *******************************
#include "common.h"
#include <gpiod.h>

//******************************* Global Types ********************************

//***************************** Global Constants ******************************
#define ACTIVE_HIGH (1)
#define ACTIVE_LOW  (0)
#define GPIO_PIN    (5)
#define ZERO        (0)

//***************************** Global Variables ******************************

//**************************** Forward Declarations ***************************
bool gpiodToolsGpioInit(struct gpiod_line **ppstLine, 
                                              struct gpiod_chip **ppstChip);
bool gpiodToolsGpioSet(struct gpiod_line **ppstLine, 
                                        uint16 unLevel);
bool gpiodToolsGpioClose(struct gpiod_line **ppstLine, 
                                              struct gpiod_chip **ppstChip);

//*********************** Inline Method Implementations ***********************

#endif // _GPIOD_Tools_H_
// EOF
//******************************* gpiod Wrapper *******************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// Summary : Include files declared, macros & forward declarations are included
// Note    : None
//
//*****************************************************************************
#ifndef _GPIOD_WRAPPER_H
#define _GPIOD_WRAPPER_H_

//******************************* Include Files *******************************
#include "common.h"
#include <gpiod.h>

//******************************* Global Types ********************************

//***************************** Global Constants ******************************
#define ACTIVE_HIGH (1)
#define ACTIVE_LOW  (0)
#define GPIO_PIN    (22)
#define ZERO        (0)

//***************************** Global Variables ******************************

//**************************** Forward Declarations ***************************
struct gpiod_chip* gpiodWrapperOpenGpioChip();
struct gpiod_line* gpiodWrapperOpenGpioLine(struct gpiod_chip *pstChip);
void gpiodWrapperSetGpio(struct gpiod_line *pstLine, 
                                        uint16 unLevel);
void gpiodWrapperCloseGpio(struct gpiod_line *pstline, 
                                              struct gpiod_chip *pstChip);

//*********************** Inline Method Implementations ***********************

#endif // _GPIOD_WRAPPER_H_
// EOF
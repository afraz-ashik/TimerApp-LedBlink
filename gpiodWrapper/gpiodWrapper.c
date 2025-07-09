//******************************* gpiod wrapper *******************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
// File    : gpiodWrapper.c
// Summary : Contains wrapper funtions related with libgpiod library.
// Note    : None.
// Author  : Afraz Ashik
// Date    : 8/July/2025
//*****************************************************************************

//******************************* Include Files *******************************
#include "gpiodWrapper.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//*****************************************************************************

//*************************.gpiodWrapperOpenGpioChip.*************************
// Purpose : To Open gpiochip0 of Raspberry Pi.
// Inputs  : None.
// Outputs : None.
// Return  : pstChip - Opened GPIO chip object.
// Notes   : None.
//*****************************************************************************
struct gpiod_chip* gpiodWrapperOpenGpioChip()
{
    // Declare gpiochip number
    struct gpiod_chip *pstChip = NULL;
    pstChip = gpiod_chip_open_by_name("gpiochip0");

    if (!pstChip)
    {
        perror("Open chip failed!");
    }

    return pstChip;
}

//*************************.gpiodWrapperOpenGpioLine.**************************
// Purpose : To open gpio line 22 of Raspberry Pi.
// Inputs  : pstChip - Contains opened GPIO chip object.
// Outputs : None.
// Return  : pstLine - GPIO line object.
// Notes   : None.
//*****************************************************************************
struct gpiod_line* gpiodWrapperOpenGpioLine(struct gpiod_chip *pstChip)
{
    // Open gpio line
    struct gpiod_line *pstLine = NULL;
    pstLine = gpiod_chip_get_line(pstChip,GPIO_PIN);

    if (!pstLine)
    {
        perror("Open gpio line failed!");
    }

    // Open line for output and check request status
    if (ZERO > gpiod_line_request_output(pstLine,"LedBlinkProgram",ACTIVE_LOW))
    {
        perror("Output request failed!");
    }

    return pstLine;
}

//****************************.gpiodWrapperSetGpio.****************************
// Purpose : To Set the GPIO line to High/Low.
// Inputs  : pstLine -  GPIO line object.
// Inputs  : unLevel - Active High or Active Low.
// Outputs : Value of GPIO line object changes to High/Low.
// Return  : None.
// Notes   : None.
//*****************************************************************************
void gpiodWrapperSetGpio(struct gpiod_line *pstLine, 
                                        uint16 unLevel)
{
    if(ZERO > gpiod_line_set_value(pstLine,unLevel))
    {
        perror("Failed to set value!");
    }
}

//****************************.gpiodWrapperCloseGpio.**************************
// Purpose : To release the gpio line and to close the gpiochip.
// Inputs  : pstLine -  GPIO line object.
// Inputs  : pstChip - Contains opened GPIO chip object.
// Outputs : None.
// Return  : None.
// Notes   : None.
//*****************************************************************************
void gpiodWrapperCloseGpio(struct gpiod_line *pstline, 
                                              struct gpiod_chip *pstChip)
{
    // Release the gpio line
    gpiod_line_release(pstline);
    // Close the gpiochip
    gpiod_chip_close(pstChip);
}
// EOF
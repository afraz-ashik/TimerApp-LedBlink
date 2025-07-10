//****************************** gpiod Tools **********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
// File    : gpiodTools.c
// Summary : Contains Tools funtions related with libgpiod library.
// Note    : None.
// Author  : Afraz Ashik
// Date    : 8/July/2025
//*****************************************************************************

//***************************** Include Files *********************************
#include "gpiodTools.h"

//****************************** Local Types **********************************

//**************************** Local Constants ********************************

//**************************** Local Variables ********************************

//**************************** Local Functions ********************************

//*****************************************************************************

//***************************.gpiodToolsGpioInit.******************************
// Purpose : To open gpio line of Raspberry Pi.
// Inputs  : pstLine - pointer to GPIO Line object.
// Inputs  : pstChip - pointer to GPIO chip object.
// Outputs : None.
// Return  : BlResult - false if pass by reference fails, else true.
// Notes   : None.
//*****************************************************************************
bool gpiodToolsGpioInit(struct gpiod_line **pstLine, 
                                              struct gpiod_chip **pstChip)
{
    bool blResult = true;

    if (NULL == pstLine || NULL == pstChip)
    {
        printf("NULL!");
        blResult = false;
    }

    // Define gpiochip number
    *pstChip = gpiod_chip_open_by_name("gpiochip0");

    if (!*pstChip)
    {
        perror("Open chip failed!");
    }

    // Open gpio line
    *pstLine = gpiod_chip_get_line(*pstChip,GPIO_PIN);

    if (!*pstLine)
    {
        perror("Open gpio line failed!");
    }

    // Open line for output and check request status
    if (ZERO > gpiod_line_request_output(*pstLine,"Led-Blink-22",ACTIVE_LOW))
    {
        perror("Output request failed!");
    }

    return blResult;
}

//****************************.gpiodToolsSetGpio.******************************
// Purpose : To Set the GPIO line to High/Low.
// Inputs  : pstLine - Pointer to GPIO line object.
// Inputs  : unLevel - Active High or Active Low.
// Outputs : Value of GPIO line object changes to High/Low.
// Return  : True.
// Notes   : None.
//*****************************************************************************
bool gpiodToolsGpioSet(struct gpiod_line **pstLine, uint16 unLevel)
{
    bool blResult = true;

    if (ZERO > gpiod_line_set_value(*pstLine,unLevel))
    {
        perror("Failed to set value!");
        blResult = false;
    }

    return blResult;
}

//****************************.gpiodToolsCloseGpio.****************************
// Purpose : To release the gpio line and to close the gpiochip.
// Inputs  : pstLine - Pointer to GPIO line object.
// Inputs  : pstChip - Pointer to GPIO chip object.
// Outputs : None.
// Return  : True.
// Notes   : None.
//*****************************************************************************
bool gpiodToolsGpioClose(struct gpiod_line **pstLine, 
                                              struct gpiod_chip **pstChip)
{
    // Release the gpio line
    gpiod_line_release(*pstLine);
    // Close the gpiochip
    gpiod_chip_close(*pstChip);

    return true;
}
// EOF
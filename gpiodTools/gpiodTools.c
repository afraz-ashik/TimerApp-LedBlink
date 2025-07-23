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
// Inputs  : ppstLine - pointer to GPIO Line object.
// Inputs  : ppstChip - pointer to GPIO chip object.
// Outputs : None.
// Return  : BlResult - false if pass by reference fails, else true.
// Notes   : None.
//*****************************************************************************
bool gpiodToolsGpioInit(struct gpiod_line **ppstLine, 
                                              struct gpiod_chip **ppstChip)
{
    bool blResult = true;

    do
    {
        if (NULL == ppstLine || NULL == ppstChip)
        {
            perror("Invalid arguments");

            break;
        }

        // Define gpiochip number
        *ppstChip = gpiod_chip_open_by_name("gpiochip0");

        if (NULL == *ppstChip)
        {
            perror("Open chip failed!");

            break;
        }

        // Open gpio line
        *ppstLine = gpiod_chip_get_line(*ppstChip, GPIO_PIN);

        if (NULL == *ppstLine)
        {
            perror("Open gpio line failed!");

            break;
        }

        // Open line for output and check request status
        if (ZERO > gpiod_line_request_output(*ppstLine,"Led-22", ACTIVE_LOW))
        {
            perror("Output request failed!");

            break;
        }

        blResult = true;

    } while (true != blResult);

    return blResult;
}

//****************************.gpiodToolsSetGpio.******************************
// Purpose : To Set the GPIO line to High/Low.
// Inputs  : ppstLine - Pointer to GPIO line object.
// Inputs  : unLevel - Active High or Active Low.
// Outputs : Value of GPIO line object changes to High/Low.
// Return  : True.
// Notes   : None.
//*****************************************************************************
bool gpiodToolsGpioSet(struct gpiod_line **ppstLine, uint16 unLevel)
{
    bool blResult = true;

    if (ZERO > gpiod_line_set_value(*ppstLine, unLevel))
    {
        perror("Failed to set value!");

        blResult = false;
    }

    return blResult;
}

//****************************.gpiodToolsCloseGpio.****************************
// Purpose : To release the gpio line and to close the gpiochip.
// Inputs  : ppstLine - Pointer to GPIO line object.
// Inputs  : ppstChip - Pointer to GPIO chip object.
// Outputs : None.
// Return  : True.
// Notes   : None.
//*****************************************************************************
bool gpiodToolsGpioClose(struct gpiod_line **ppstLine, 
                                              struct gpiod_chip **ppstChip)
{
    // Release the gpio line
    gpiod_line_release(*ppstLine);
    // Close the gpiochip
    gpiod_chip_close(*ppstChip);

    return true;
}
// EOF
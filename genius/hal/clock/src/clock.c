/*===================================================================================================
* The MIT License (MIT)
*
* Copyright:  $
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software
* and associated documentation files (the "Software"), to deal in the Software without restriction,
* including without limitation the rights to use, copy, modify, merge, publish, distribute,
* sublicense, and/or sell copies of the Software, and to permit persons to whom the Software
* is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies
* or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
* BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
* DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
*===================================================================================================*/
#include "clock.h"

void SET_GPIO_CLOCK(UINT8 port)
{
    switch (port) 
    {
        case PORTA:
            RCC_GPIOA_CLK_ENABLE();
            break;
        case PORTB:
            RCC_GPIOB_CLK_ENABLE();
            break;
        case PORTC:
            RCC_GPIOC_CLK_ENABLE();
            break;
        case PORTD:
            RCC_GPIOD_CLK_ENABLE();
            break;
        case PORTE:
            RCC_GPIOE_CLK_ENABLE();
            break;
        case PORTF:
            RCC_GPIOF_CLK_ENABLE();
            break;
        default:
            // error("Pinmap error: wrong port number.");
            break;
    }
}

#ifdef HISTORY
/***********************************************************************
*
*  $Log: llm_tyde.he,v $
*  Revision 1.0  10/05/2019
*  Initial Version
*  [Lam Huynh Van]
*
***********************************************************************/
#endif /* HISTORY */

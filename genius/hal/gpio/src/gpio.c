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
#include "gpio.h"

void GPIO_SET_MODE_PIN(UINT8 port, UINT8 pin, UINT32 mode_option)
{
    UINT32 temp_reg;
    GPIO_t *pPORT;

    switch(port)
    {
        case PORTA:
            pPORT = pPORTA;
            break;
        case PORTB:
            pPORT = pPORTB;
            break;
        case PORTC:
            pPORT = pPORTC;
            break;
        case PORTD:
            pPORT = pPORTD;
            break;
        case PORTE:
            pPORT = pPORTE;
            break;
        case PORTF:
            pPORT = pPORTF;
            break;
        default:
            pPORT = NULL_PTR;
            break;
    }

    if(NULL_PTR != pPORT)
    {
        /* mode */
        temp_reg = READ_REG_32(pPORT->MODER, ~(0x03U << (2 * pin)));
        if(GPIO_MODE_OPTION_INPUT == (mode_option & 0x03U))
        {
            temp_reg |= GPIO_MODE_OPTION_INPUT << (2 * pin);
            WRITE_REG_32(pPORT->MODER, temp_reg);
        }
        else if (GPIO_MODE_OPTION_OUTPUT == (mode_option & 0x03U))
        {
            temp_reg |= GPIO_MODE_OPTION_OUTPUT << (2 * pin);
            WRITE_REG_32(pPORT->MODER, temp_reg);
        }
        else if (GPIO_MODE_OPTION_ALT == (mode_option & 0x03U))
        {
            temp_reg |= GPIO_MODE_OPTION_ALT << (2 * pin);
            WRITE_REG_32(pPORT->MODER, temp_reg);
        }
        else if (GPIO_MODE_OPTION_ANALOG == (mode_option & 0x03U))
        {
            temp_reg |= GPIO_MODE_OPTION_ANALOG << (2 * pin);
            WRITE_REG_32(pPORT->MODER, temp_reg);
        }

        /* pull-up/down */
        temp_reg = READ_REG_32(pPORT->PUPDR, ~(0x03U << (2 * pin)));
        if(GPIO_MODE_OPTION_PULLUP == (mode_option & 0x0CU))
        {
            temp_reg |= 0x01U << (2 * pin);
            WRITE_REG_32(pPORT->PUPDR, temp_reg);
        }
        else if (GPIO_MODE_OPTION_PULLDOWN == (mode_option & 0x0CU))
        {
            temp_reg |= 0x02U << (2 * pin);
            WRITE_REG_32(pPORT->PUPDR, temp_reg);
        }

        /* alt mode */
        if (pin < 8)
        {
            temp_reg = READ_REG_32(pPORT->AFRL, ~(0x0FU << (4 * pin)));
            temp_reg |= ((mode_option & 0xF0) >> 4) << (4 * pin);
            WRITE_REG_32(pPORT->AFRL, temp_reg);
        }
        else
        {
            temp_reg = READ_REG_32(pPORT->AFRH, ~(0x0FU << (4 * pin)));
            temp_reg |= ((mode_option & 0xF0) >> 4) << (4 * (pin - 8));
            WRITE_REG_32(pPORT->AFRH, temp_reg);
        }
    }
}

void GPIO_WRITE_PIN(UINT8 port, UINT8 pin, UINT8 value)
{
    GPIO_t *pPORT;

    switch(port)
    {
        case PORTA:
            pPORT = pPORTA;
            break;
        case PORTB:
            pPORT = pPORTB;
            break;
        case PORTC:
            pPORT = pPORTC;
            break;
        case PORTD:
            pPORT = pPORTD;
            break;
        case PORTE:
            pPORT = pPORTE;
            break;
        case PORTF:
            pPORT = pPORTF;
            break;
        default:
            pPORT = NULL_PTR;
            break;
    }

    if(NULL_PTR != pPORT)
    {
        if(LOW == value)
        {
            SET_BITS_32(pPORT->BSRR, 0x01U << (pin + 16U));
        }
        else if (HIGH == value)
        {
            SET_BITS_32(pPORT->BSRR, 0x01U << pin);
        }
        else
        {
            /* Do nothing */
        }
    }
}

UINT8 GPIO_READ_PIN(UINT8 port, UINT8 pin)
{
    UINT32 value = 0x00U;
    GPIO_t *pPORT;

    switch(port)
    {
        case PORTA:
            pPORT = pPORTA;
            break;
        case PORTB:
            pPORT = pPORTB;
            break;
        case PORTC:
            pPORT = pPORTC;
            break;
        case PORTD:
            pPORT = pPORTD;
            break;
        case PORTE:
            pPORT = pPORTE;
            break;
        case PORTF:
            pPORT = pPORTF;
            break;
        default:
            pPORT = NULL_PTR;
            break;
    }

    if(NULL_PTR != pPORT)
    {
        value = READ_REG_16(pPORT->IDR, 0x01U << pin) >> pin;
    }

    return (UINT8)value;
}

UINT8 GPIO_TOGGLE_PIN(UINT8 port, UINT8 pin)
{
    GPIO_t *pPORT;

    switch(port)
    {
        case PORTA:
            pPORT = pPORTA;
            break;
        case PORTB:
            pPORT = pPORTB;
            break;
        case PORTC:
            pPORT = pPORTC;
            break;
        case PORTD:
            pPORT = pPORTD;
            break;
        case PORTE:
            pPORT = pPORTE;
            break;
        case PORTF:
            pPORT = pPORTF;
            break;
        default:
            pPORT = NULL_PTR;
            break;
    }

    if(NULL_PTR != pPORT)
    {
        if (LOW == (READ_REG_16(pPORT->ODR, 0x01U << pin) >> pin))
        {
            SET_BITS_32(pPORT->BSRR, 0x01U << pin);
        }
        else
        {
            SET_BITS_32(pPORT->BSRR, 0x01U << (pin + 16U));
        }
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

/*===================================================================================================
*
* MCU:     STM32F051R8
*
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

#include "gpio_common.h"

void delay(unsigned int timeout)
{
    unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}

unsigned int led_state = 0U;

void EXTI0_1_IRQHandler(void)
{
    unsigned int temp;
    /* Ngat cua PA0 */
    temp = (pEXTI->PR) & (0x01U << 0U);
    // temp = read_reg(EXTI_PR, (1U << 0U));
    if (0x01U == temp)
    {
        if(0 == led_state)
        {
            GPIO_WRITE_PIN(PORTC, LED3_PIN, HIGH);
            led_state = 1U;
        }
        else
        {
            GPIO_WRITE_PIN(PORTC, LED3_PIN, LOW);
            led_state = 0U;
        }
    }
    /* xoa co ngat */
    temp = 0x01U << 0U;
    // write_reg(EXTI_PR, temp);
    pEXTI->PR = temp;
    // write_reg(NVIC_ICPR, (0x01U << 5U));
    pNVIC->ICPR = (0x01U << 5U);
}
void main(void)
{
    UINT8 button_state = 0;
    SET_GPIO_CLOCK(PORTA);
    SET_GPIO_CLOCK(PORTC);
    GPIO_SET_MODE_PIN(PORTA, USER_BUTTON, GPIO_MODE_OPTION_INPUT);
    GPIO_SET_MODE_PIN(PORTC, LED3_PIN, GPIO_MODE_OPTION_OUTPUT);
    EXTI_INIT(PORTA, USER_BUTTON, EXTI_TRIGGER_FALLING);
    NVIC_SetPriority(EXTI0_1_IRQn, 0x01U);
    NVIC_EnableIRQ(EXTI0_1_IRQn);
    enable_global_irq;
    /*
    while(1)
    {
        if(GPIO_READ_PIN(PORTA, USER_BUTTON))
        {
            if(button_state)
            {
                GPIO_WRITE_PIN(PORTC, LED3_PIN, HIGH);
                button_state = 0;
            }
            else
            {
                GPIO_WRITE_PIN(PORTC, LED3_PIN, LOW);
                button_state = 1;
            }
        }
        delay(0x0f);
    }
    */
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

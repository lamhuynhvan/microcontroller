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
#include "interrupt.h"

void EXTI_INIT(UINT8 port, UINT8 pin, UINT8 trigger_event)
{
    /* Enable interrupt for EXTI0 */
    pEXTI->IMR &= ~((UINT32)1U << pin);
    pEXTI->IMR |=  ((UINT32)1U << pin);

    /* Rising/Falling trigger */
    if(EXTI_RISING_TRIGGER == trigger_event)
    {
        pEXTI->FTSR &= ~((UINT32)1U << pin);
        pEXTI->RTSR |=  ((UINT32)1U << pin);
    }
    else if(EXTI_FALLING_TRIGGER == trigger_event)
    {
        pEXTI->RTSR &= ~((UINT32)1U << pin);
        pEXTI->FTSR |=  ((UINT32)1U << pin);
    }
    else
    {
        /* Do nothing */
    }

    /* SYSCFG external interrupt configuration */
    switch(port)
    {
        case PORTA:
            pSYSCFG->EXTICR[pin / 4U] &= ~((UINT32)SYSCFG_EXTICR_EXTI_MASK << (4U * (pin / 4U)));
            pSYSCFG->EXTICR[pin / 4U] |=  (UINT32)SYSCFG_EXTICR_EXTI_PORTA << (4U * (pin / 4U));
            break;
        case PORTB:
            pSYSCFG->EXTICR[pin / 4U] &= ~((UINT32)SYSCFG_EXTICR_EXTI_MASK << (4U * (pin / 4U)));
            pSYSCFG->EXTICR[pin / 4U] |=  (UINT32)SYSCFG_EXTICR_EXTI_PORTB << (4U * (pin / 4U));
            break;
        case PORTC:
            pSYSCFG->EXTICR[pin / 4U] &= ~((UINT32)SYSCFG_EXTICR_EXTI_MASK << (4U * (pin / 4U)));
            pSYSCFG->EXTICR[pin / 4U] |=  (UINT32)SYSCFG_EXTICR_EXTI_PORTC << (4U * (pin / 4U));
            break;
        case PORTD:
            pSYSCFG->EXTICR[pin / 4U] &= ~((UINT32)SYSCFG_EXTICR_EXTI_MASK << (4U * (pin / 4U)));
            pSYSCFG->EXTICR[pin / 4U] |=  (UINT32)SYSCFG_EXTICR_EXTI_PORTD << (4U * (pin / 4U));
            break;
        case PORTE:
            pSYSCFG->EXTICR[pin / 4U] &= ~((UINT32)SYSCFG_EXTICR_EXTI_MASK << (4U * (pin / 4U)));
            pSYSCFG->EXTICR[pin / 4U] |=  (UINT32)SYSCFG_EXTICR_EXTI_PORTE << (4U * (pin / 4U));
            break;
        case PORTF:
            pSYSCFG->EXTICR[pin / 4U] &= ~((UINT32)SYSCFG_EXTICR_EXTI_MASK << (4U * (pin / 4U)));
            pSYSCFG->EXTICR[pin / 4U] |=  (UINT32)SYSCFG_EXTICR_EXTI_PORTF << (4U * (pin / 4U));
            break;
        default:
            break;
    }
}

void NVIC_SetPriority(IRQn_Type IRQn, UINT8 priority)
{
    pNVIC->IPR[IRQn] &= ~(UINT8)NVIC_IRQ_PRIORITY_MASK;
    pNVIC->IPR[IRQn] = (UINT8)(priority << (8U - NVIC_PRIO_BITS)) & (UINT8)NVIC_IRQ_PRIORITY_MASK;
}

void NVIC_EnableIRQ(IRQn_Type IRQn)
{
    pNVIC->ISER |= ((UINT32)1U << ((UINT8)IRQn & (UINT8)NVIC_IRQ_TYPE_MASK));
}

void Enable_Global_Interrupt(void)
{
    asm("cpsie i");
}



#ifdef HISTORY
/***********************************************************************
*
*  $Log: interrupt.c
*  Revision 1.0  10/05/2019
*  Initial Version
*  [Lam Huynh Van]
*
***********************************************************************/
#endif /* HISTORY */

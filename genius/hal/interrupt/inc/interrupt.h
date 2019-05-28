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
#ifndef _GPIO_H_
#define _GPIO_H_
#include "driver.h"

#define EXTI_RISING_TRIGGER                 0x00U
#define EXTI_FALLING_TRIGGER                0x01U
#define SYSCFG_EXTICR_EXTI_MASK             0x0FU
#define SYSCFG_EXTICR_EXTI_PORTA            0x00U
#define SYSCFG_EXTICR_EXTI_PORTB            0x01U
#define SYSCFG_EXTICR_EXTI_PORTC            0x02U
#define SYSCFG_EXTICR_EXTI_PORTD            0x03U
#define SYSCFG_EXTICR_EXTI_PORTE            0x04U
#define SYSCFG_EXTICR_EXTI_PORTF            0x05U

#define NVIC_IRQ_TYPE_MASK                  0x1FU
#define NVIC_IRQ_PRIORITY_MASK              0xFFU


void EXTI_INIT(UINT8 port, UINT8 pin, UINT8 trigger_event);
// void NVIC_SetPriority(IRQn_Type IRQn, UINT8 priority);
// void NVIC_EnableIRQ(IRQn_Type IRQn);
// void Enable_Global_Interrupt(void);

static inline void NVIC_SetPriority(IRQn_Type IRQn, UINT8 priority)
{
    pNVIC->IPR[IRQn] &= ~(UINT8)NVIC_IRQ_PRIORITY_MASK;
    pNVIC->IPR[IRQn] = (UINT8)(priority << (8U - NVIC_PRIO_BITS)) & (UINT8)NVIC_IRQ_PRIORITY_MASK;
}

static inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
    pNVIC->ISER |= ((UINT32)1U << ((UINT8)IRQn & (UINT8)NVIC_IRQ_TYPE_MASK));
}

#ifdef HISTORY
/***********************************************************************
*
*  $Log: interrupt.h
*  Revision 1.0  10/05/2019
*  Initial Version
*  [Lam Huynh Van]
*
***********************************************************************/
#endif /* HISTORY */

#endif /* _GPIO_H_ */

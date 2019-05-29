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

#ifndef _HW_PLATFORM_H_
#define _HW_PLATFORM_H_

#include "types.h"

/* =================== RCC register map ==================== */
typedef volatile struct
{
    UINT32    CR;
    UINT32    CFGR;
    UINT32    CIR;
    UINT32    APB2RSTR;
    UINT32    APB1RSTR;
    UINT32    AHBENR;
    UINT32    APB2ENR;
    UINT32    APB1ENR;
    UINT32    BDCR;
    UINT32    CSR;
    UINT32    AHBRSTR;
    UINT32    CFGR2;
    UINT32    CFGR3;
    UINT32    CR2;
}RCC_t;

#define RCC_BASE_ADDR          ((uint32)0x40021000UL)
#define pRCC                   ((RCC_t *)RCC_BASE_ADDR)

/* =================== GPIO Register Map =================== */
typedef volatile struct
{
    UINT32  MODER;
    UINT16  OTYPER;
    UINT16  Reserved1;
    UINT32  OSPEEDR;
    UINT32  PUPDR;
    UINT16  IDR;
    UINT16  Reserved2;
    UINT16  ODR;
    UINT16  Reserved3;
    UINT32  BSRR;
    UINT16  LCKR;
    UINT16  Reserved4;
    UINT32  AFRL;
    UINT32  AFRH;
    UINT16  BRR;
}GPIO_t;

#define PORTA_BASE_ADDR         ((uint32)0x48000000UL)
#define PORTB_BASE_ADDR         ((uint32)0x48000400UL)
#define PORTC_BASE_ADDR         ((uint32)0x48000800UL)
#define PORTD_BASE_ADDR         ((uint32)0x48000C00UL)
#define PORTE_BASE_ADDR         ((uint32)0x48001000UL)
#define PORTF_BASE_ADDR         ((uint32)0x48001400UL)

#define pPORTA                  ((GPIO_t *)PORTA_BASE_ADDR)
#define pPORTB                  ((GPIO_t *)PORTB_BASE_ADDR)
#define pPORTC                  ((GPIO_t *)PORTC_BASE_ADDR)
#define pPORTD                  ((GPIO_t *)PORTD_BASE_ADDR)
#define pPORTE                  ((GPIO_t *)PORTE_BASE_ADDR)
#define pPORTF                  ((GPIO_t *)PORTF_BASE_ADDR)

/* Definition port ID */
#define PORTA                   0u
#define PORTB                   1u
#define PORTC                   2u
#define PORTD                   3u
#define PORTE                   4u
#define PORTF                   5u

/* =================== EXTI Register Map =================== */
typedef volatile struct
{
    UINT32  IMR;
    UINT32  EMR;
    UINT32  RTSR;
    UINT32  FTSR;
    UINT32  SWIER;
    UINT32  PR;
}EXTI_t;

#define EXTI_BASE_ADDR          ((uint32)0x40010400UL)

#define pEXTI                   ((EXTI_t *)EXTI_BASE_ADDR)

/* ================== SYSCFG Register Map ================== */
typedef volatile struct
{
    UINT32  CFGR1;
    UINT32  EXTICR[4];
    UINT16  CFGR2;
}SYSCFG_t;

#define SYSCFG_BASE_ADDR        ((uint32)0x40010000UL)

#define pSYSCFG                 ((SYSCFG_t *)SYSCFG_BASE_ADDR)

/* ================== USART Register Map ================== */
typedef volatile struct
{
    UINT32  CR1;
    UINT32  CR2;
    UINT32  CR3;
    UINT32  BRR;
    UINT32  GTPR;
    UINT32  RTOR;
    UINT32  RQR;
    UINT32  ISR;
    UINT32  ICR;
    UINT32  RDR;
    UINT32  TDR;
}USART_t;

#define USART1_BASE_ADDR         ((uint32)0x40013800UL)
#define USART2_BASE_ADDR         ((uint32)0x40004400UL)
#define USART3_BASE_ADDR         ((uint32)0x40004800UL)
#define USART4_BASE_ADDR         ((uint32)0x40004C00UL)
#define USART5_BASE_ADDR         ((uint32)0x40005000UL)
#define USART6_BASE_ADDR         ((uint32)0x40011400UL)
#define USART7_BASE_ADDR         ((uint32)0x40011800UL)
#define USART8_BASE_ADDR         ((uint32)0x40011C00UL)

#define pUSART1                  ((USART1_t *)USART1_BASE_ADDR)
#define pUSART2                  ((USART2_t *)USART2_BASE_ADDR)
#define pUSART3                  ((USART3_t *)USART3_BASE_ADDR)
#define pUSART4                  ((USART4_t *)USART4_BASE_ADDR)
#define pUSART5                  ((USART5_t *)USART5_BASE_ADDR)
#define pUSART6                  ((USART6_t *)USART6_BASE_ADDR)
#define pUSART7                  ((USART7_t *)USART7_BASE_ADDR)
#define pUSART8                  ((USART8_t *)USART8_BASE_ADDR)





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

#endif /* _HW_PLATFORM_H_ */

/*
 *===================================================================================================
 * Revision History:
 *                              Modification     Tracking
 * Author (core ID)              Date D/M/Y       Number     Description of Changes
 *---------------------------   ------------   ------------  ----------------------------------------
 * Lam Huynh Van                 28/05/2019     ENGR11682    Initial version (STM32F051R8)
 *---------------------------   ------------   ------------  ----------------------------------------
 *===================================================================================================
 */

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

#define pUSART1                  ((USART1_t *)USART1_BASE_ADDR)

#endif /* _HW_PLATFORM_H_ */

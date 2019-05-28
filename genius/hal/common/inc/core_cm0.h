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

#ifndef _CORE_CM0_H_
#define _CORE_CM0_H_

#include "types.h"

/* ================== SCB Register Map =================== */
typedef volatile struct
{
    UINT32  CPUID;
    UINT32  ICSR;
    UINT32  Reserved1;
    UINT32  AIRCR;
    UINT32  SCR;
    UINT32  CCR;
    UINT32  Reserved2;
    UINT32  SHPR2;
    UINT32  SHPR3;
}SCB_t;

#define SCB_BASE_ADDR          ((uint32)0xE000ED00UL)

#define pSCB                   ((SCB_t *)SCB_BASE_ADDR)

/* ================== NVIC Register Map ================== */
typedef volatile struct
{
    UINT32  ISER;
    UINT32  Reserved1[31];
    UINT32  ICER;
    UINT32  Reserved2[31];
    UINT32  ISPR;
    UINT32  Reserved3[31];
    UINT32  ICPR;
    UINT32  Reserved4[95];
    UINT8   IPR[32];
}NVIC_t;

#define NVIC_BASE_ADDR          ((uint32)0xE000E100UL)

#define pNVIC                   ((NVIC_t *)NVIC_BASE_ADDR)

#define NVIC_PRIO_BITS          0x02U



/* ================== System Timer - Systick ================== */
typedef volatile struct
{
    UINT32  CSR;    /* SysTick Control and Status Register */
    UINT32  RVR;    /* SysTick Reload Value Register       */
    UINT32  CVR;    /* SysTick Current Value Register      */
    UINT32  CALIB;  /* SysTick Calibration Value Register  */
}SYST_t;

#define SYST_BASE_ADDR          ((uint32)0xE000E010UL)

#define pSYST                   ((SYST_t *)SYST_BASE_ADDR)





typedef enum IRQn
{
    /* Cortex-M0 Processor Exceptions Numbers */
    NonMaskableInt_IRQn             = -14,
    HardFault_IRQn                  = -13,
    SVCall_IRQn                     =  -5,
    PendSV_IRQn                     =  -2,
    SysTick_IRQn                    =  -1,
    /* ARMCM0 Specific Interrupt Numbers */
    WWDG_IRQn                       =   0,
    PVD_VDDIO2_IRQn                 =   1,
    RTC_IRQn                        =   2,
    FLASH_IRQn                      =   3,
    RCC_CRS_IRQn                    =   4,
    EXTI0_1_IRQn                    =   5,
    EXTI2_3_IRQn                    =   6,
    EXTI4_15_IRQn                   =   7,
    TSC_IRQn                        =   8,
    DMA_CH1_IRQn                    =   9,
    DMA_CH2_3_DMA2_CH1_2_IRQn       =   10,
    DMA_CH4_7_DMA2_CH3_5_IRQn       =   11,
    ADC_COMP_IRQn                   =   12,
    TIM1_BRK_UP_TRG_COM_IRQn        =   13,
    TIM1_CC_IRQn                    =   14,
    TIM2_IRQn                       =   15,
    TIM3_IRQn                       =   16,
    TIM6_DAC_IRQn                   =   17,
    TIM7_IRQn                       =   18,
    TIM14_IRQn                      =   19,
    TIM15_IRQn                      =   20,
    TIM16_IRQn                      =   21,
    TIM17_IRQn                      =   22,
    I2C1_IRQn                       =   23,
    I2C2_IRQn                       =   24,
    SPI1_IRQn                       =   25,
    SPI2_IRQn                       =   26,
    USART1_IRQn                     =   27,
    USART2_IRQn                     =   28,
    USART3_8_IRQn                   =   29,
    CEC_CAN_IRQn                    =   30,
    USB_IRQn                        =   31,
}IRQn_Type;


#define enable_global_irq                   asm("cpsie i")
#define disable_global_irq                  __asm volatile("cpsid i")




#ifdef HISTORY
/***********************************************************************
*
*  $Log: core_cm0.h
*  Revision 1.0  10/05/2019
*  Initial Version
*  [Lam Huynh Van]
*
***********************************************************************/
#endif /* HISTORY */

#endif /* _CORE_CM0_H_ */

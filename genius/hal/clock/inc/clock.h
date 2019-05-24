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
#ifndef _CLOCK_H_
#define _CLOCK_H_

#include "driver.h"

#define RCC_AHBENR_GPIOAEN_POS          (17U)
#define RCC_AHBENR_GPIOAEN_MASK         ((UINT32)0x1U << RCC_AHBENR_GPIOAEN_POS)
#define RCC_AHBENR_GPIOAEN              RCC_AHBENR_GPIOAEN_MASK

#define RCC_AHBENR_GPIOBEN_POS          (18U)
#define RCC_AHBENR_GPIOBEN_MASK         ((UINT32)0x1U << RCC_AHBENR_GPIOBEN_POS)
#define RCC_AHBENR_GPIOBEN              RCC_AHBENR_GPIOBEN_MASK

#define RCC_AHBENR_GPIOCEN_POS          ((UINT32)19U)
#define RCC_AHBENR_GPIOCEN_MASK         (0x1U << RCC_AHBENR_GPIOCEN_POS)
#define RCC_AHBENR_GPIOCEN              RCC_AHBENR_GPIOCEN_MASK

#define RCC_AHBENR_GPIODEN_POS          (20U)
#define RCC_AHBENR_GPIODEN_MASK         ((UINT32)0x1U << RCC_AHBENR_GPIODEN_POS)
#define RCC_AHBENR_GPIODEN              RCC_AHBENR_GPIODEN_MASK

#define RCC_AHBENR_GPIOEEN_POS          (21U)
#define RCC_AHBENR_GPIOEEN_MASK         ((UINT32)0x1U << RCC_AHBENR_GPIOEEN_POS)
#define RCC_AHBENR_GPIOEEN              RCC_AHBENR_GPIOEEN_MASK

#define RCC_AHBENR_GPIOFEN_POS          (22U)
#define RCC_AHBENR_GPIOFEN_MASK         ((UINT32)0x1U << RCC_AHBENR_GPIOFEN_POS)
#define RCC_AHBENR_GPIOFEN              RCC_AHBENR_GPIOFEN_MASK


#define RCC_GPIOA_CLK_ENABLE()          do {    \
                                         UINT32 temp_reg;   \
                                         SET_BITS_32(pRCC->AHBENR, RCC_AHBENR_GPIOAEN); \
                                         temp_reg = READ_BITS_32(pRCC->AHBENR, RCC_AHBENR_GPIOAEN); \
                                        }while(0U)

#define RCC_GPIOB_CLK_ENABLE()          do {    \
                                         UINT32 temp_reg;   \
                                         SET_BITS_32(pRCC->AHBENR, RCC_AHBENR_GPIOBEN); \
                                         temp_reg = READ_BITS_32(pRCC->AHBENR, RCC_AHBENR_GPIOBEN); \
                                        }while(0U)

#define RCC_GPIOC_CLK_ENABLE()          do {    \
                                         UINT32 temp_reg;   \
                                         SET_BITS_32(pRCC->AHBENR, RCC_AHBENR_GPIOCEN); \
                                         temp_reg = READ_BITS_32(pRCC->AHBENR, RCC_AHBENR_GPIOCEN); \
                                        }while(0U)

#define RCC_GPIOD_CLK_ENABLE()          do {    \
                                         UINT32 temp_reg;   \
                                         SET_BITS_32(pRCC->AHBENR, RCC_AHBENR_GPIODEN); \
                                         temp_reg = READ_BITS_32(pRCC->AHBENR, RCC_AHBENR_GPIODEN); \
                                        }while(0U)

#define RCC_GPIOE_CLK_ENABLE()          do {    \
                                         UINT32 temp_reg;   \
                                         SET_BITS_32(pRCC->AHBENR, RCC_AHBENR_GPIOEEN); \
                                         temp_reg = READ_BITS_32(pRCC->AHBENR, RCC_AHBENR_GPIOEEN); \
                                        }while(0U)

#define RCC_GPIOF_CLK_ENABLE()          do {    \
                                         UINT32 temp_reg;   \
                                         SET_BITS_32(pRCC->AHBENR, RCC_AHBENR_GPIOFEN); \
                                         temp_reg = READ_BITS_32(pRCC->AHBENR, RCC_AHBENR_GPIOFEN); \
                                        }while(0U)


void SET_GPIO_CLOCK(UINT8 port);

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

#endif /* _CLOCK_H_ */

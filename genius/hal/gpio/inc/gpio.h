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

/* GPIO mode option */
#define GPIO_MODE_OPTION_INPUT             (UINT32)0x00U
#define GPIO_MODE_OPTION_OUTPUT            (UINT32)0x01U
#define GPIO_MODE_OPTION_ALT               (UINT32)0x02U
#define GPIO_MODE_OPTION_ANALOG            (UINT32)0x03U

#define GPIO_MODE_OPTION_PULLUP            (UINT32)0x04U
#define GPIO_MODE_OPTION_PULLDOWN          (UINT32)0x08U

#define GPIO_MODE_OPTION_AF0               (UINT32)0x00U
#define GPIO_MODE_OPTION_AF1               (UINT32)0x10U
#define GPIO_MODE_OPTION_AF2               (UINT32)0x20U
#define GPIO_MODE_OPTION_AF3               (UINT32)0x30U
#define GPIO_MODE_OPTION_AF4               (UINT32)0x40U
#define GPIO_MODE_OPTION_AF5               (UINT32)0x50U
#define GPIO_MODE_OPTION_AF6               (UINT32)0x60U
#define GPIO_MODE_OPTION_AF7               (UINT32)0x70U

void GPIO_SET_MODE_PIN(UINT8 port, UINT8 pin, UINT32 mode_option);
void GPIO_WRITE_PIN(UINT8 port, UINT8 pin, UINT8 value);
UINT8 GPIO_READ_PIN(UINT8 port, UINT8 pin);
uint8_t GPIO_TOGGLE_PIN(uint8_t port, uint8_t pin);

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

#endif /* _GPIO_H_ */

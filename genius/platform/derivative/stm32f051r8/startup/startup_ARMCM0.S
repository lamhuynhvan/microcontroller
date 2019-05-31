/*
 ******************************************************************************************
 * @file      startup_stm32f051x8.s
 * @author    MCD Application Team
 * @brief     STM32F051x4/STM32F051x6/STM32F051x8 devices vector table for GCC toolchain.
 *            This module performs:
 *                - Set the initial SP
 *                - Set the initial PC == Reset_Handler,
 *                - Set the vector table entries with the exceptions ISR address
 *                - Branches to main in the C library (which eventually
 *                  calls main()).
 *            After Reset the Cortex-M0 processor is in Thread mode,
 *            priority is Privileged, and the Stack is set to Main.
 ******************************************************************************************
 */

  .syntax unified
  .cpu cortex-m0
  .fpu softvfp
  .thumb

.global g_pfnVectors
.global Default_Handler

/* start address for the initialization values of the .data section.
defined in linker script */
.word _sidata
/* start address for the .data section. defined in linker script */
.word _sdata
/* end address for the .data section. defined in linker script */
.word _edata
/* start address for the .bss section. defined in linker script */
.word _sbss
/* end address for the .bss section. defined in linker script */
.word _ebss

  .section .text.Reset_Handler
  .weak Reset_Handler
  .type Reset_Handler, %function
Reset_Handler:
  ldr   r0, =_estack
  mov   sp, r0          /* set stack pointer */

/* Copy the data segment initializers from flash to SRAM */
  ldr r0, =_sdata
  ldr r1, =_edata
  ldr r2, =_sidata
  movs r3, #0
  b LoopCopyDataInit

CopyDataInit:
  ldr r4, [r2, r3]
  str r4, [r0, r3]
  adds r3, r3, #4

LoopCopyDataInit:
  adds r4, r0, r3
  cmp r4, r1
  bcc CopyDataInit
  
/* Zero fill the bss segment. */
  ldr r2, =_sbss
  ldr r4, =_ebss
  movs r3, #0
  b LoopFillZerobss

FillZerobss:
  str  r3, [r2]
  adds r2, r2, #4

LoopFillZerobss:
  cmp r2, r4
  bcc FillZerobss

/* Call the clock system intitialization function.*/
/* bl  SystemInit */
/* Call static constructors */
/* bl __libc_init_array */
/* Call the application,s entry point.*/
  bl main

LoopForever:
    b LoopForever


.size Reset_Handler, .-Reset_Handler

/*
 * @brief  This is the code that gets called when the processor receives an
 *         unexpected interrupt.  This simply enters an infinite loop, preserving
 *         the system state for examination by a debugger.
 *
 * @param  None
 * @retval : None
 */
    .section .text.Default_Handler,"ax",%progbits
Default_Handler:
Infinite_Loop:
  b Infinite_Loop
  .size Default_Handler, .-Default_Handler
/******************************************************************************************
*
* The minimal vector table for a Cortex M0.  Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
*
******************************************************************************************/
   .section .isr_vector,"a",%progbits
  .type g_pfnVectors, %object
  .size g_pfnVectors, .-g_pfnVectors


g_pfnVectors:
  .word  _estack
  .word  Reset_Handler                      /* Reset Handler      */
  .word  NMI_Handler                        /* NMI Handler        */
  .word  HardFault_Handler                  /* Hard Fault Handler */
  .word  0                                  /* Reserved           */
  .word  0                                  /* Reserved           */
  .word  0                                  /* Reserved           */
  .word  0                                  /* Reserved           */
  .word  0                                  /* Reserved           */
  .word  0                                  /* Reserved           */
  .word  0                                  /* Reserved           */
  .word  SVC_Handler                        /* SVCall Handler     */
  .word  0                                  /* Reserved           */
  .word  0                                  /* Reserved           */
  .word  PendSV_Handler                     /* PendSV Handler     */
  .word  SysTick_Handler                    /* SysTick Handler    */

  .word  Reserved_IRQHandler                /*  0: Reserved       */
  .word  Reserved_IRQHandler                /*  1: Reserved       */
  .word  Reserved_IRQHandler                /*  2: Reserved       */
  .word  Reserved_IRQHandler                /*  3: Reserved       */
  .word  Reserved_IRQHandler                /*  4: Reserved       */
  .word  EXTI0_1_IRQHandler                 /*  5: EXTI0_1        */
  .word  EXTI2_3_IRQHandler                 /*  6: Reserved       */
  .word  EXTI4_15_IRQHandler                /*  7: Reserved       */
  .word  Reserved_IRQHandler                /*  8: Reserved       */
  .word  Reserved_IRQHandler                /*  9: Reserved       */
  .word  Reserved_IRQHandler                /* 10: Reserved       */
  .word  Reserved_IRQHandler                /* 11: Reserved       */
  .word  Reserved_IRQHandler                /* 12: Reserved       */
  .word  Reserved_IRQHandler                /* 13: Reserved       */
  .word  Reserved_IRQHandler                /* 14: Reserved       */
  .word  Reserved_IRQHandler                /* 15: Reserved       */
  .word  Reserved_IRQHandler                /* 16: Reserved       */
  .word  Reserved_IRQHandler                /* 17: Reserved       */
  .word  Reserved_IRQHandler                /* 18: Reserved       */
  .word  Reserved_IRQHandler                /* 19: Reserved       */
  .word  Reserved_IRQHandler                /* 20: Reserved       */
  .word  Reserved_IRQHandler                /* 21: Reserved       */
  .word  Reserved_IRQHandler                /* 22: Reserved       */
  .word  Reserved_IRQHandler                /* 23: Reserved       */
  .word  Reserved_IRQHandler                /* 24: Reserved       */
  .word  Reserved_IRQHandler                /* 25: Reserved       */
  .word  Reserved_IRQHandler                /* 26: Reserved       */
  .word  Reserved_IRQHandler                /* 27: Reserved       */
  .word  Reserved_IRQHandler                /* 28: Reserved       */
  .word  Reserved_IRQHandler                /* 29: Reserved       */
  .word  Reserved_IRQHandler                /* 30: Reserved       */
  .word  Reserved_IRQHandler                /* 31: Reserved       */

/*******************************************88*********************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler.
* As they are weak aliases, any function with the same name will override
* this definition.
*
*******************************************************************************************/

  .weak      NMI_Handler
  .thumb_set NMI_Handler,Default_Handler

  .weak      HardFault_Handler
  .thumb_set HardFault_Handler,Default_Handler

  .weak      SVC_Handler
  .thumb_set SVC_Handler,Default_Handler

  .weak      PendSV_Handler
  .thumb_set PendSV_Handler,Default_Handler

  .weak      SysTick_Handler
  .thumb_set SysTick_Handler,Default_Handler

  .weak      Reserved_IRQHandler
  .thumb_set Reserved_IRQHandler,Default_Handler

  .weak      PVD_IRQHandler
  .thumb_set PVD_IRQHandler,Default_Handler

  .weak      RTC_IRQHandler
  .thumb_set RTC_IRQHandler,Default_Handler

  .weak      FLASH_IRQHandler
  .thumb_set FLASH_IRQHandler,Default_Handler

  .weak      RCC_CRS_IRQHandler
  .thumb_set RCC_CRS_IRQHandler,Default_Handler

  .weak      EXTI0_1_IRQHandler
  .thumb_set EXTI0_1_IRQHandler,Default_Handler

  .weak      EXTI2_3_IRQHandler
  .thumb_set EXTI2_3_IRQHandler,Default_Handler

  .weak      EXTI4_15_IRQHandler
  .thumb_set EXTI4_15_IRQHandler,Default_Handler

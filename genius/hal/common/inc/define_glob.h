/*
 *===================================================================================================
 * Revision History:
 *                              Modification     Tracking
 * Author (core ID)              Date D/M/Y       Number     Description of Changes
 *---------------------------   ------------   ------------  ----------------------------------------
 * Lam Huynh Van                 28/05/2019     ENGR11682    Initial version
 *---------------------------   ------------   ------------  ----------------------------------------
 *===================================================================================================
 */

#ifndef _DEFINE_GLOB_H_
#define _DEFINE_GLOB_H_

#include "types.h"

#define BIT0                            (UINT8)0x01U
#define BIT1                            (UINT8)0x02U
#define BIT2                            (UINT8)0x04U
#define BIT3                            (UINT8)0x08U
#define BIT4                            (UINT8)0x10U
#define BIT5                            (UINT8)0x20U
#define BIT6                            (UINT8)0x40U
#define BIT7                            (UINT8)0x80U
#define BIT8                            (UINT16)0x0100U
#define BIT9                            (UINT16)0x0200U
#define BIT10                           (UINT16)0x0400U
#define BIT11                           (UINT16)0x0800U
#define BIT12                           (UINT16)0x1000U
#define BIT13                           (UINT16)0x2000U
#define BIT14                           (UINT16)0x4000U
#define BIT15                           (UINT16)0x8000U
#define BIT16                           (UINT32)0x00010000U
#define BIT17                           (UINT32)0x00020000U
#define BIT18                           (UINT32)0x00040000U
#define BIT19                           (UINT32)0x00080000U
#define BIT20                           (UINT32)0x00100000U
#define BIT21                           (UINT32)0x00200000U
#define BIT22                           (UINT32)0x00400000U
#define BIT23                           (UINT32)0x00800000U
#define BIT24                           (UINT32)0x01000000U
#define BIT25                           (UINT32)0x02000000U
#define BIT26                           (UINT32)0x04000000U
#define BIT27                           (UINT32)0x08000000U
#define BIT28                           (UINT32)0x10000000U
#define BIT29                           (UINT32)0x20000000U
#define BIT30                           (UINT32)0x40000000U
#define BIT31                           (UINT32)0x80000000U

#define SHIFT0                          (UINT8)0x00U
#define SHIFT1                          (UINT8)0x01U
#define SHIFT2                          (UINT8)0x02U
#define SHIFT3                          (UINT8)0x03U
#define SHIFT4                          (UINT8)0x04U
#define SHIFT5                          (UINT8)0x05U
#define SHIFT6                          (UINT8)0x06U
#define SHIFT7                          (UINT8)0x07U
#define SHIFT8                          (UINT8)0x08U
#define SHIFT9                          (UINT8)0x09U
#define SHIFT10                         (UINT8)0x0AU
#define SHIFT11                         (UINT8)0x0BU
#define SHIFT12                         (UINT8)0x0CU
#define SHIFT13                         (UINT8)0x0DU
#define SHIFT14                         (UINT8)0x0EU
#define SHIFT15                         (UINT8)0x0FU
#define SHIFT16                         (UINT8)0x10U
#define SHIFT17                         (UINT8)0x11U
#define SHIFT18                         (UINT8)0x12U
#define SHIFT19                         (UINT8)0x13U
#define SHIFT20                         (UINT8)0x14U
#define SHIFT21                         (UINT8)0x15U
#define SHIFT22                         (UINT8)0x16U
#define SHIFT23                         (UINT8)0x17U
#define SHIFT24                         (UINT8)0x18U
#define SHIFT25                         (UINT8)0x19U
#define SHIFT26                         (UINT8)0x1AU
#define SHIFT27                         (UINT8)0x1BU
#define SHIFT28                         (UINT8)0x1CU
#define SHIFT29                         (UINT8)0x1DU
#define SHIFT30                         (UINT8)0x1EU
#define SHIFT31                         (UINT8)0x1FU

#define SET                             (UINT8)0x1U
#define CLEAR                           (UINT8)0x0U
#define HIGH                            (UINT8)0x1U
#define LOW                             (UINT8)0x0U

#define SET_BITS_8(REG, BITS)           ((REG) |= ((UINT8)BITS))
#define CLEAR_BITS_8(REG, BITS)         ((REG) &= ~((UINT8)BITS))
#define READ_BITS_8(REG, BITS)          ((REG) & ((UINT8)BITS))
#define WRITE_REG_8(REG, VAL)           ((REG) = ((UINT8)VAL))
#define CLEAR_REG_8(REG)                ((REG) = ((UINT8)0x0U))
#define READ_REG_8(REG, MASK)           ((REG) & ((UINT8)MASK))

#define SET_BITS_16(REG, BITS)          ((REG) |= ((UINT16)BITS))
#define CLEAR_BITS_16(REG, BITS)        ((REG) &= ~((UINT16)BITS))
#define READ_BITS_16(REG, BITS)         ((REG) & ((UINT16)BITS))
#define WRITE_REG_16(REG, VAL)          ((REG) = ((UINT16)VAL))
#define CLEAR_REG_16(REG)               ((REG) = ((UINT16)0x0U))
#define READ_REG_16(REG, MASK)          ((REG) & ((UINT16)MASK))

#define SET_BITS_32(REG, BITS)          ((REG) |= ((UINT32)BITS))
#define CLEAR_BITS_32(REG, BITS)        ((REG) &= ~((UINT32)BITS))
#define READ_BITS_32(REG, BITS)         ((REG) & ((UINT32)BITS))
#define WRITE_REG_32(REG, VAL)          ((REG) = ((UINT32)VAL))
#define CLEAR_REG_32(REG)               ((REG) = ((UINT32)0x0U))
#define READ_REG_32(REG, MASK)          ((REG) & ((UINT32)MASK))

#endif /* _DEFINE_GLOB_H_ */

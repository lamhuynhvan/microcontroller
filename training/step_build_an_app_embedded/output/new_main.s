	.cpu cortex-m0
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"new_main.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.align	1
	.global	delay
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	delay, %function
delay:
.LFB0:
	.file 1 "./src/main.c"
	.loc 1 5 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	sub	sp, sp, #16
	.cfi_def_cfa_offset 24
	add	r7, sp, #0
	.cfi_def_cfa_register 7
	str	r0, [r7, #4]
	.loc 1 7 0
	movs	r3, #0
	str	r3, [r7, #12]
	b	.L2
.L5:
	.loc 1 9 0
	movs	r3, #0
	str	r3, [r7, #8]
	b	.L3
.L4:
	.loc 1 11 0 discriminator 3
	.syntax divided
@ 11 "./src/main.c" 1
	 nop
@ 0 "" 2
	.loc 1 9 0 discriminator 3
	.thumb
	.syntax unified
	ldr	r3, [r7, #8]
	adds	r3, r3, #1
	str	r3, [r7, #8]
.L3:
	.loc 1 9 0 is_stmt 0 discriminator 1
	ldr	r3, [r7, #8]
	ldr	r2, .L6
	cmp	r3, r2
	bls	.L4
	.loc 1 7 0 is_stmt 1 discriminator 2
	ldr	r3, [r7, #12]
	adds	r3, r3, #1
	str	r3, [r7, #12]
.L2:
	.loc 1 7 0 is_stmt 0 discriminator 1
	ldr	r2, [r7, #12]
	ldr	r3, [r7, #4]
	cmp	r2, r3
	bcc	.L5
	.loc 1 14 0 is_stmt 1
	nop
	mov	sp, r7
	add	sp, sp, #16
	@ sp needed
	pop	{r7, pc}
.L7:
	.align	2
.L6:
	.word	4094
	.cfi_endproc
.LFE0:
	.size	delay, .-delay
	.align	1
	.global	main
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	main, %function
main:
.LFB1:
	.loc 1 17 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	sub	sp, sp, #8
	.cfi_def_cfa_offset 16
	add	r7, sp, #0
	.cfi_def_cfa_register 7
.LBB2:
	.loc 1 19 0
	ldr	r3, .L10
	ldr	r3, [r3]
	ldr	r2, .L10+4
	ands	r3, r2
	str	r3, [r7, #4]
	ldr	r3, [r7, #4]
	movs	r2, #128
	lsls	r2, r2, #10
	orrs	r3, r2
	str	r3, [r7, #4]
	ldr	r3, .L10
	ldr	r2, [r7, #4]
	str	r2, [r3]
	movs	r0, #10
	bl	delay
.LBE2:
.LBB3:
	.loc 1 21 0
	movs	r3, #144
	lsls	r3, r3, #23
	ldr	r3, [r3]
	ldr	r2, .L10+8
	ands	r3, r2
	str	r3, [r7]
	ldr	r3, [r7]
	movs	r2, #128
	lsls	r2, r2, #1
	orrs	r3, r2
	str	r3, [r7]
	movs	r3, #144
	lsls	r3, r3, #23
	ldr	r2, [r7]
	str	r2, [r3]
.L9:
.LBE3:
	.loc 1 24 0 discriminator 1
	ldr	r3, .L10+12
	movs	r2, #0
	str	r2, [r3]
	.loc 1 25 0 discriminator 1
	movs	r0, #255
	bl	delay
	.loc 1 26 0 discriminator 1
	ldr	r3, .L10+12
	movs	r2, #16
	str	r2, [r3]
	.loc 1 27 0 discriminator 1
	movs	r0, #255
	bl	delay
	.loc 1 24 0 discriminator 1
	b	.L9
.L11:
	.align	2
.L10:
	.word	1073877012
	.word	-131073
	.word	-769
	.word	1207959572
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.align	1
	.global	Reserved_IRQHandler
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	Reserved_IRQHandler, %function
Reserved_IRQHandler:
.LFB2:
	.loc 1 33 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	add	r7, sp, #0
	.cfi_def_cfa_register 7
.L13:
	.loc 1 34 0 discriminator 1
	b	.L13
	.cfi_endproc
.LFE2:
	.size	Reserved_IRQHandler, .-Reserved_IRQHandler
	.align	1
	.global	NMI_Handler
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	NMI_Handler, %function
NMI_Handler:
.LFB3:
	.loc 1 41 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	add	r7, sp, #0
	.cfi_def_cfa_register 7
.L15:
	.loc 1 42 0 discriminator 1
	b	.L15
	.cfi_endproc
.LFE3:
	.size	NMI_Handler, .-NMI_Handler
	.align	1
	.global	HardFault_Handler
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	HardFault_Handler, %function
HardFault_Handler:
.LFB4:
	.loc 1 49 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	add	r7, sp, #0
	.cfi_def_cfa_register 7
.L17:
	.loc 1 50 0 discriminator 1
	b	.L17
	.cfi_endproc
.LFE4:
	.size	HardFault_Handler, .-HardFault_Handler
	.align	1
	.global	SVC_Handler
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	SVC_Handler, %function
SVC_Handler:
.LFB5:
	.loc 1 57 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	add	r7, sp, #0
	.cfi_def_cfa_register 7
.L19:
	.loc 1 58 0 discriminator 1
	b	.L19
	.cfi_endproc
.LFE5:
	.size	SVC_Handler, .-SVC_Handler
	.align	1
	.global	PendSV_Handler
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	PendSV_Handler, %function
PendSV_Handler:
.LFB6:
	.loc 1 65 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	add	r7, sp, #0
	.cfi_def_cfa_register 7
.L21:
	.loc 1 66 0 discriminator 1
	b	.L21
	.cfi_endproc
.LFE6:
	.size	PendSV_Handler, .-PendSV_Handler
	.align	1
	.global	SysTick_Handler
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	SysTick_Handler, %function
SysTick_Handler:
.LFB7:
	.loc 1 73 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	add	r7, sp, #0
	.cfi_def_cfa_register 7
.L23:
	.loc 1 74 0 discriminator 1
	b	.L23
	.cfi_endproc
.LFE7:
	.size	SysTick_Handler, .-SysTick_Handler
.Letext0:
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x11e
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF11
	.byte	0xc
	.4byte	.LASF12
	.4byte	.LASF13
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.4byte	.LASF0
	.byte	0x1
	.byte	0x48
	.4byte	.LFB7
	.4byte	.LFE7-.LFB7
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x2
	.4byte	.LASF1
	.byte	0x1
	.byte	0x40
	.4byte	.LFB6
	.4byte	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x2
	.4byte	.LASF2
	.byte	0x1
	.byte	0x38
	.4byte	.LFB5
	.4byte	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x2
	.4byte	.LASF3
	.byte	0x1
	.byte	0x30
	.4byte	.LFB4
	.4byte	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x2
	.4byte	.LASF4
	.byte	0x1
	.byte	0x28
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x2
	.4byte	.LASF5
	.byte	0x1
	.byte	0x20
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x3
	.4byte	.LASF7
	.byte	0x1
	.byte	0x10
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xd5
	.uleb128 0x4
	.4byte	.LBB2
	.4byte	.LBE2-.LBB2
	.4byte	0xbc
	.uleb128 0x5
	.4byte	.LASF6
	.byte	0x1
	.byte	0x13
	.4byte	0xd5
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0x6
	.4byte	.LBB3
	.4byte	.LBE3-.LBB3
	.uleb128 0x5
	.4byte	.LASF6
	.byte	0x1
	.byte	0x15
	.4byte	0xd5
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.byte	0
	.byte	0
	.uleb128 0x7
	.byte	0x4
	.byte	0x7
	.4byte	.LASF9
	.uleb128 0x8
	.4byte	.LASF8
	.byte	0x1
	.byte	0x4
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x11a
	.uleb128 0x9
	.4byte	.LASF14
	.byte	0x1
	.byte	0x4
	.4byte	0x11a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xa
	.ascii	"t1\000"
	.byte	0x1
	.byte	0x6
	.4byte	0x11a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0xa
	.ascii	"t2\000"
	.byte	0x1
	.byte	0x6
	.4byte	0x11a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.byte	0
	.uleb128 0x7
	.byte	0x4
	.byte	0x7
	.4byte	.LASF10
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF4:
	.ascii	"NMI_Handler\000"
.LASF0:
	.ascii	"SysTick_Handler\000"
.LASF10:
	.ascii	"unsigned int\000"
.LASF9:
	.ascii	"long unsigned int\000"
.LASF3:
	.ascii	"HardFault_Handler\000"
.LASF12:
	.ascii	"./output/new_main.c\000"
.LASF14:
	.ascii	"timeout\000"
.LASF11:
	.ascii	"GNU C11 7.2.1 20170904 (release) [ARM/embedded-7-br"
	.ascii	"anch revision 255204] -march=armv6-m -mcpu=cortex-m"
	.ascii	"0 -mthumb -g -O0\000"
.LASF6:
	.ascii	"tmpreg\000"
.LASF5:
	.ascii	"Reserved_IRQHandler\000"
.LASF8:
	.ascii	"delay\000"
.LASF7:
	.ascii	"main\000"
.LASF2:
	.ascii	"SVC_Handler\000"
.LASF1:
	.ascii	"PendSV_Handler\000"
.LASF13:
	.ascii	"D:\\Linux Embedded\\microcontroller\\training\\step"
	.ascii	"_build_an_app_embedded\000"
	.ident	"GCC: (GNU Tools for Arm Embedded Processors 7-2017-q4-major) 7.2.1 20170904 (release) [ARM/embedded-7-branch revision 255204]"

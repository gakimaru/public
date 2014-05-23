	.file	"sub.cpp"
	.text
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_00_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_00_aPcU8__vectorx:
LFB3571:
	.cfi_startproc
	rep ret
	.cfi_endproc
LFE3571:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_01_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_01_aPcU8__vectorx:
LFB3573:
	.cfi_startproc
	movl	4(%esp), %eax
	pextrb	$0, %xmm0, (%eax)
	ret
	.cfi_endproc
LFE3573:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_02_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_02_aPcU8__vectorx:
LFB3575:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movdqa	%xmm0, (%esp)
	movl	32(%esp), %eax
	movl	(%esp), %edx
	movw	%dx, (%eax)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3575:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_03_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_03_aPcU8__vectorx:
LFB3577:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %eax
	movdqa	%xmm0, (%esp)
	movdqa	(%esp), %xmm1
	movl	(%esp), %edx
	pextrb	$2, %xmm1, 2(%eax)
	movw	%dx, (%eax)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3577:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_04_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_04_aPcU8__vectorx:
LFB3579:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movdqa	%xmm0, (%esp)
	movl	32(%esp), %eax
	movl	(%esp), %edx
	movl	%edx, (%eax)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3579:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_05_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_05_aPcU8__vectorx:
LFB3581:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %eax
	movdqa	%xmm0, (%esp)
	movdqa	(%esp), %xmm1
	movl	(%esp), %edx
	pextrb	$4, %xmm1, 4(%eax)
	movl	%edx, (%eax)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3581:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_06_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_06_aPcU8__vectorx:
LFB3583:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %eax
	movdqa	%xmm0, (%esp)
	movl	(%esp), %edx
	movl	%edx, (%eax)
	movl	4(%esp), %edx
	movw	%dx, 4(%eax)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3583:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_07_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_07_aPcU8__vectorx:
LFB3585:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %eax
	movdqa	%xmm0, (%esp)
	movdqa	(%esp), %xmm1
	movl	(%esp), %edx
	pextrb	$6, %xmm1, 6(%eax)
	movl	%edx, (%eax)
	movl	4(%esp), %edx
	movw	%dx, 4(%eax)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3585:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_08_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_08_aPcU8__vectorx:
LFB3587:
	.cfi_startproc
	movl	4(%esp), %eax
	movq	%xmm0, (%eax)
	ret
	.cfi_endproc
LFE3587:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_09_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_09_aPcU8__vectorx:
LFB3589:
	.cfi_startproc
	movl	4(%esp), %eax
	movq	%xmm0, (%eax)
	pextrb	$8, %xmm0, 8(%eax)
	ret
	.cfi_endproc
LFE3589:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_10_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_10_aPcU8__vectorx:
LFB3591:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movdqa	%xmm0, %xmm1
	movl	32(%esp), %eax
	movdqa	%xmm0, (%esp)
	movl	8(%esp), %edx
	movq	%xmm1, (%eax)
	movw	%dx, 8(%eax)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3591:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_11_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_11_aPcU8__vectorx:
LFB3593:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movdqa	%xmm0, %xmm1
	movl	32(%esp), %eax
	movdqa	%xmm0, (%esp)
	movdqa	(%esp), %xmm2
	movl	8(%esp), %edx
	movq	%xmm1, (%eax)
	pextrb	$10, %xmm2, 10(%eax)
	movw	%dx, 8(%eax)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3593:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_12_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_12_aPcU8__vectorx:
LFB3595:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movdqa	%xmm0, %xmm1
	movl	32(%esp), %eax
	movdqa	%xmm0, (%esp)
	movl	8(%esp), %edx
	movq	%xmm1, (%eax)
	movl	%edx, 8(%eax)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3595:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_13_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_13_aPcU8__vectorx:
LFB3597:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movdqa	%xmm0, %xmm1
	movl	32(%esp), %eax
	movdqa	%xmm0, (%esp)
	movdqa	(%esp), %xmm2
	movl	8(%esp), %edx
	movq	%xmm1, (%eax)
	pextrb	$12, %xmm2, 12(%eax)
	movl	%edx, 8(%eax)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3597:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_14_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_14_aPcU8__vectorx:
LFB3599:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movdqa	%xmm0, %xmm1
	movl	32(%esp), %eax
	movdqa	%xmm0, (%esp)
	movl	8(%esp), %edx
	movq	%xmm1, (%eax)
	movl	%edx, 8(%eax)
	movl	12(%esp), %edx
	movw	%dx, 12(%eax)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3599:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_15_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_15_aPcU8__vectorx:
LFB3601:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movdqa	%xmm0, %xmm1
	movl	32(%esp), %eax
	movdqa	%xmm0, (%esp)
	movdqa	(%esp), %xmm2
	movl	8(%esp), %edx
	movq	%xmm1, (%eax)
	pextrb	$14, %xmm2, 14(%eax)
	movl	%edx, 8(%eax)
	movl	12(%esp), %edx
	movw	%dx, 12(%eax)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3601:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_16_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_16_aPcU8__vectorx:
LFB3603:
	.cfi_startproc
	movl	4(%esp), %eax
	movdqa	%xmm0, (%eax)
	ret
	.cfi_endproc
LFE3603:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_:
LFB3789:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	8(%esp), %eax
	movl	%edx, (%eax)
	ret
	.cfi_endproc
LFE3789:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_:
LFB3796:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	addl	$1, (%eax)
	ret
	.cfi_endproc
LFE3796:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE_E9_M_invokeERKSt9_Any_data:
LFB3881:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%edx)
	ret
	.cfi_endproc
LFE3881:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE0_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE0_E9_M_invokeERKSt9_Any_data:
LFB3885:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%edx)
	ret
	.cfi_endproc
LFE3885:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE1_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE1_E9_M_invokeERKSt9_Any_data:
LFB3889:
	.cfi_startproc
	movl	__ZZ9setLambdaRiE14static_counter, %eax
	addl	$1, %eax
	movl	%eax, __ZZ9setLambdaRiE14static_counter
	ret
	.cfi_endproc
LFE3889:
	.p2align 4,,15
	.def	__ZL18_strcpy_fast_case2PcPKc;	.scl	3;	.type	32;	.endef
__ZL18_strcpy_fast_case2PcPKc:
LFB3609:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	cmpb	$0, __ZGVZL18_strcpy_fast_case2PcPKcE4null
	movl	32(%esp), %esi
	movl	36(%esp), %ebx
	je	L48
L37:
	movl	%esi, %edx
	movdqa	__ZZL18_strcpy_fast_case2PcPKcE4null, %xmm1
	jmp	L40
	.p2align 4,,7
L49:
	movdqa	%xmm0, (%edx)
	addl	$16, %ebx
	addl	$16, %edx
L40:
	movdqu	(%ebx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L49
	movl	%edx, (%esp)
	call	*__ZL17_memcpy_m128i_a_x+4(,%ecx,4)
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	movl	%esi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L48:
	.cfi_restore_state
	movl	$__ZGVZL18_strcpy_fast_case2PcPKcE4null, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	je	L37
	movl	$__ZGVZL18_strcpy_fast_case2PcPKcE4null, (%esp)
	pxor	%xmm0, %xmm0
	movdqa	%xmm0, __ZZL18_strcpy_fast_case2PcPKcE4null
	call	___cxa_guard_release
	jmp	L37
	.cfi_endproc
LFE3609:
	.p2align 4,,15
	.def	__ZL18_strcpy_fast_case0PcPKc;	.scl	3;	.type	32;	.endef
__ZL18_strcpy_fast_case0PcPKc:
LFB3607:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	cmpb	$0, __ZGVZL18_strcpy_fast_case0PcPKcE4null
	movl	32(%esp), %esi
	movl	36(%esp), %ebx
	je	L62
L52:
	movdqa	__ZZL18_strcpy_fast_case0PcPKcE4null, %xmm1
	movl	%esi, %edx
	jmp	L55
	.p2align 4,,7
L63:
	movdqa	%xmm0, (%edx)
	addl	$16, %ebx
	addl	$16, %edx
L55:
	movdqa	(%ebx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L63
	movl	%edx, (%esp)
	call	*__ZL17_memcpy_m128i_a_x+4(,%ecx,4)
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	movl	%esi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L62:
	.cfi_restore_state
	movl	$__ZGVZL18_strcpy_fast_case0PcPKcE4null, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	je	L52
	movl	$__ZGVZL18_strcpy_fast_case0PcPKcE4null, (%esp)
	pxor	%xmm0, %xmm0
	movdqa	%xmm0, __ZZL18_strcpy_fast_case0PcPKcE4null
	call	___cxa_guard_release
	jmp	L52
	.cfi_endproc
LFE3607:
	.p2align 4,,15
	.def	__ZL19_strncpy_fast_case2PcPKcj;	.scl	3;	.type	32;	.endef
__ZL19_strncpy_fast_case2PcPKcj:
LFB3616:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	cmpb	$0, __ZGVZL19_strncpy_fast_case2PcPKcjE4null
	movl	32(%esp), %edi
	movl	36(%esp), %ebx
	je	L80
L66:
	movl	40(%esp), %eax
	movl	%edi, %esi
	addl	%ebx, %eax
	leal	-16(%eax), %edx
	cmpl	%edx, %ebx
	ja	L68
	movdqa	__ZZL19_strncpy_fast_case2PcPKcjE4null, %xmm1
	jmp	L71
	.p2align 4,,7
L69:
	addl	$16, %ebx
	movdqa	%xmm0, (%esi)
	addl	$16, %esi
	cmpl	%ebx, %edx
	jb	L68
L71:
	movdqu	(%ebx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L69
	movl	%ecx, 12(%esp)
	movl	%esi, (%esp)
	call	*__ZL17_memcpy_m128i_a_x(,%ecx,4)
	movl	12(%esp), %ecx
	movb	$0, (%esi,%ecx)
L70:
	addl	$16, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%edi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L68:
	.cfi_restore_state
	subl	%ebx, %eax
	je	L70
	movdqu	(%ebx), %xmm0
	movl	%esi, (%esp)
	call	*__ZL17_memcpy_m128i_a_x(,%eax,4)
	addl	$16, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%edi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L80:
	.cfi_restore_state
	movl	$__ZGVZL19_strncpy_fast_case2PcPKcjE4null, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	je	L66
	movl	$__ZGVZL19_strncpy_fast_case2PcPKcjE4null, (%esp)
	pxor	%xmm0, %xmm0
	movdqa	%xmm0, __ZZL19_strncpy_fast_case2PcPKcjE4null
	call	___cxa_guard_release
	jmp	L66
	.cfi_endproc
LFE3616:
	.p2align 4,,15
	.def	__ZL19_strncpy_fast_case0PcPKcj;	.scl	3;	.type	32;	.endef
__ZL19_strncpy_fast_case0PcPKcj:
LFB3614:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	cmpb	$0, __ZGVZL19_strncpy_fast_case0PcPKcjE4null
	movl	32(%esp), %edi
	movl	36(%esp), %ebx
	je	L97
L83:
	movl	40(%esp), %eax
	addl	%ebx, %eax
	leal	-16(%eax), %edx
	cmpl	%edx, %ebx
	ja	L89
	movdqa	__ZZL19_strncpy_fast_case0PcPKcjE4null, %xmm1
	movl	%edi, %esi
	jmp	L88
	.p2align 4,,7
L86:
	addl	$16, %ebx
	movdqa	%xmm0, (%esi)
	addl	$16, %esi
	cmpl	%ebx, %edx
	jb	L85
L88:
	movdqa	(%ebx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L86
	movl	%ecx, 12(%esp)
	movl	%esi, (%esp)
	call	*__ZL17_memcpy_m128i_a_x(,%ecx,4)
	movl	12(%esp), %ecx
	movb	$0, (%esi,%ecx)
L87:
	addl	$16, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%edi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
L89:
	.cfi_restore_state
	movl	%edi, %esi
	.p2align 4,,7
L85:
	subl	%ebx, %eax
	je	L87
	movdqa	(%ebx), %xmm0
	movl	%esi, (%esp)
	call	*__ZL17_memcpy_m128i_a_x(,%eax,4)
	addl	$16, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%edi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L97:
	.cfi_restore_state
	movl	$__ZGVZL19_strncpy_fast_case0PcPKcjE4null, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	je	L83
	movl	$__ZGVZL19_strncpy_fast_case0PcPKcjE4null, (%esp)
	pxor	%xmm0, %xmm0
	movdqa	%xmm0, __ZZL19_strncpy_fast_case0PcPKcjE4null
	call	___cxa_guard_release
	jmp	L83
	.cfi_endproc
LFE3614:
	.p2align 4,,15
	.def	__ZL18_strcmp_fast_case0PKcS0_;	.scl	3;	.type	32;	.endef
__ZL18_strcmp_fast_case0PKcS0_:
LFB3551:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %ebx
	movl	16(%esp), %edx
	jmp	L101
	.p2align 4,,7
L99:
	testl	%eax, %eax
	jne	L100
	addl	$16, %ebx
	addl	$16, %edx
L101:
	movdqa	(%edx), %xmm1
	movdqa	(%ebx), %xmm0
	pcmpistri	$26, %xmm1, %xmm0
	setc	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$0, %eax
	sete	%al
	testl	%esi, %esi
	je	L99
	movsbl	(%edx,%ecx), %eax
	movsbl	(%ebx,%ecx), %ebx
	subl	%eax, %ebx
	setne	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	sarl	$31, %ebx
	orl	%ebx, %esi
L100:
	movl	%esi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3551:
	.p2align 4,,15
	.def	__ZL18_strcmp_fast_case1PKcS0_;	.scl	3;	.type	32;	.endef
__ZL18_strcmp_fast_case1PKcS0_:
LFB3552:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %ebx
	movl	16(%esp), %edx
	jmp	L106
	.p2align 4,,7
L104:
	testl	%eax, %eax
	jne	L105
	addl	$16, %ebx
	addl	$16, %edx
L106:
	movdqu	(%ebx), %xmm0
	movdqa	(%edx), %xmm1
	pcmpistri	$26, %xmm1, %xmm0
	setc	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$0, %eax
	sete	%al
	testl	%esi, %esi
	je	L104
	movsbl	(%edx,%ecx), %eax
	movsbl	(%ebx,%ecx), %ebx
	subl	%eax, %ebx
	setne	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	sarl	$31, %ebx
	orl	%ebx, %esi
L105:
	movl	%esi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3552:
	.p2align 4,,15
	.def	__ZL18_strcmp_fast_case2PKcS0_;	.scl	3;	.type	32;	.endef
__ZL18_strcmp_fast_case2PKcS0_:
LFB3553:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %ebx
	movl	16(%esp), %edx
	jmp	L111
	.p2align 4,,7
L109:
	testl	%eax, %eax
	jne	L110
	addl	$16, %ebx
	addl	$16, %edx
L111:
	movdqu	(%edx), %xmm1
	movdqa	(%ebx), %xmm0
	pcmpistri	$26, %xmm1, %xmm0
	setc	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$0, %eax
	sete	%al
	testl	%esi, %esi
	je	L109
	movsbl	(%edx,%ecx), %eax
	movsbl	(%ebx,%ecx), %ebx
	subl	%eax, %ebx
	setne	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	sarl	$31, %ebx
	orl	%ebx, %esi
L110:
	movl	%esi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3553:
	.p2align 4,,15
	.def	__ZL18_strcmp_fast_case3PKcS0_;	.scl	3;	.type	32;	.endef
__ZL18_strcmp_fast_case3PKcS0_:
LFB3554:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %ebx
	movl	16(%esp), %edx
	jmp	L116
	.p2align 4,,7
L114:
	testl	%eax, %eax
	jne	L115
	addl	$16, %ebx
	addl	$16, %edx
L116:
	movdqu	(%ebx), %xmm0
	movdqu	(%edx), %xmm1
	pcmpistri	$26, %xmm1, %xmm0
	setc	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$0, %eax
	sete	%al
	testl	%esi, %esi
	je	L114
	movsbl	(%edx,%ecx), %eax
	movsbl	(%ebx,%ecx), %ebx
	subl	%eax, %ebx
	setne	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	sarl	$31, %ebx
	orl	%ebx, %esi
L115:
	movl	%esi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3554:
	.p2align 4,,15
	.def	__ZL22_strstr_fast_cmp_case0PKcS0_;	.scl	3;	.type	32;	.endef
__ZL22_strstr_fast_cmp_case0PKcS0_:
LFB3564:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %edx
	movl	16(%esp), %ebx
	jmp	L122
	.p2align 4,,7
L119:
	testl	%ecx, %ecx
	jne	L124
	addl	$16, %edx
	addl	$16, %ebx
L122:
	movl	$0, %eax
	movdqa	(%ebx), %xmm1
	movdqa	(%edx), %xmm0
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %esi
	setc	%al
	movl	$0, %ecx
	sete	%cl
	testl	%eax, %eax
	je	L119
	xorl	%ecx, %ecx
	cmpb	$0, (%ebx,%esi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	sete	%cl
	cmpb	$1, (%edx,%esi)
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	sbbl	%eax, %eax
	andl	$2, %eax
	orl	%ecx, %eax
	ret
	.p2align 4,,7
L124:
	.cfi_restore_state
	movl	$1, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3564:
	.p2align 4,,15
	.def	__ZL22_strstr_fast_cmp_case1PKcS0_;	.scl	3;	.type	32;	.endef
__ZL22_strstr_fast_cmp_case1PKcS0_:
LFB3565:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %edx
	movl	16(%esp), %ebx
	jmp	L130
	.p2align 4,,7
L127:
	testl	%ecx, %ecx
	jne	L132
	addl	$16, %edx
	addl	$16, %ebx
L130:
	movl	$0, %eax
	movdqu	(%edx), %xmm0
	movdqa	(%ebx), %xmm1
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %esi
	setc	%al
	movl	$0, %ecx
	sete	%cl
	testl	%eax, %eax
	je	L127
	xorl	%ecx, %ecx
	cmpb	$0, (%ebx,%esi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	sete	%cl
	cmpb	$1, (%edx,%esi)
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	sbbl	%eax, %eax
	andl	$2, %eax
	orl	%ecx, %eax
	ret
	.p2align 4,,7
L132:
	.cfi_restore_state
	movl	$1, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3565:
	.p2align 4,,15
	.def	__ZL22_strstr_fast_cmp_case2PKcS0_;	.scl	3;	.type	32;	.endef
__ZL22_strstr_fast_cmp_case2PKcS0_:
LFB3566:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %edx
	movl	16(%esp), %ebx
	jmp	L138
	.p2align 4,,7
L135:
	testl	%ecx, %ecx
	jne	L140
	addl	$16, %edx
	addl	$16, %ebx
L138:
	movl	$0, %eax
	movdqu	(%ebx), %xmm1
	movdqa	(%edx), %xmm0
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %esi
	setc	%al
	movl	$0, %ecx
	sete	%cl
	testl	%eax, %eax
	je	L135
	xorl	%ecx, %ecx
	cmpb	$0, (%ebx,%esi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	sete	%cl
	cmpb	$1, (%edx,%esi)
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	sbbl	%eax, %eax
	andl	$2, %eax
	orl	%ecx, %eax
	ret
	.p2align 4,,7
L140:
	.cfi_restore_state
	movl	$1, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3566:
	.p2align 4,,15
	.def	__ZL22_strstr_fast_cmp_case3PKcS0_;	.scl	3;	.type	32;	.endef
__ZL22_strstr_fast_cmp_case3PKcS0_:
LFB3567:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %edx
	movl	16(%esp), %ebx
	jmp	L146
	.p2align 4,,7
L143:
	testl	%ecx, %ecx
	jne	L148
	addl	$16, %edx
	addl	$16, %ebx
L146:
	movl	$0, %eax
	movdqu	(%edx), %xmm0
	movdqu	(%ebx), %xmm1
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %esi
	setc	%al
	movl	$0, %ecx
	sete	%cl
	testl	%eax, %eax
	je	L143
	xorl	%ecx, %ecx
	cmpb	$0, (%ebx,%esi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	sete	%cl
	cmpb	$1, (%edx,%esi)
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	sbbl	%eax, %eax
	andl	$2, %eax
	orl	%ecx, %eax
	ret
	.p2align 4,,7
L148:
	.cfi_restore_state
	movl	$1, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3567:
	.p2align 4,,15
	.def	__ZL19_strncmp_fast_case3PKcS0_j;	.scl	3;	.type	32;	.endef
__ZL19_strncmp_fast_case3PKcS0_j:
LFB3559:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	cmpb	$0, __ZGVZL19_strncmp_fast_case3PKcS0_jE4null
	movl	48(%esp), %ebx
	movl	52(%esp), %esi
	je	L171
L152:
	movl	56(%esp), %ebp
	addl	%ebx, %ebp
	leal	-16(%ebp), %edi
	cmpl	%edi, %ebx
	jbe	L158
	jmp	L154
	.p2align 4,,7
L155:
	testl	%edx, %edx
	jne	L159
	addl	$16, %ebx
	addl	$16, %esi
	cmpl	%ebx, %edi
	jb	L154
L158:
	movl	$0, %eax
	movdqu	(%ebx), %xmm0
	movdqu	(%esi), %xmm1
	movl	$0, %edx
	pcmpistri	$26, %xmm1, %xmm0
	setc	%al
	sete	%dl
	testl	%eax, %eax
	je	L155
L170:
	movsbl	(%esi,%ecx), %eax
	movsbl	(%ebx,%ecx), %edx
	subl	%eax, %edx
	setne	%al
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movzbl	%al, %eax
	sarl	$31, %edx
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	orl	%edx, %eax
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L154:
	.cfi_restore_state
	subl	%ebx, %ebp
	jne	L172
L159:
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L171:
	.cfi_restore_state
	movl	$__ZGVZL19_strncmp_fast_case3PKcS0_jE4null, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	je	L152
	movl	$__ZGVZL19_strncmp_fast_case3PKcS0_jE4null, (%esp)
	pxor	%xmm0, %xmm0
	movdqa	%xmm0, __ZZL19_strncmp_fast_case3PKcS0_jE4null
	call	___cxa_guard_release
	jmp	L152
	.p2align 4,,7
L172:
	movdqu	(%ebx), %xmm0
	pcmpistri	$26, (%esi), %xmm0
	jnc	L159
	cmpl	%ecx, %ebp
	ja	L170
	jmp	L159
	.cfi_endproc
LFE3559:
	.p2align 4,,15
	.def	__ZL19_strncmp_fast_case2PKcS0_j;	.scl	3;	.type	32;	.endef
__ZL19_strncmp_fast_case2PKcS0_j:
LFB3558:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	cmpb	$0, __ZGVZL19_strncmp_fast_case2PKcS0_jE4null
	movl	48(%esp), %ebx
	movl	52(%esp), %esi
	je	L194
L175:
	movl	56(%esp), %ebp
	addl	%ebx, %ebp
	leal	-16(%ebp), %edi
	cmpl	%edi, %ebx
	jbe	L181
	jmp	L177
	.p2align 4,,7
L178:
	testl	%edx, %edx
	jne	L182
	addl	$16, %ebx
	addl	$16, %esi
	cmpl	%ebx, %edi
	jb	L177
L181:
	movl	$0, %eax
	movdqu	(%esi), %xmm1
	movdqa	(%ebx), %xmm0
	movl	$0, %edx
	pcmpistri	$26, %xmm1, %xmm0
	setc	%al
	sete	%dl
	testl	%eax, %eax
	je	L178
L193:
	movsbl	(%esi,%ecx), %eax
	movsbl	(%ebx,%ecx), %edx
	subl	%eax, %edx
	setne	%al
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movzbl	%al, %eax
	sarl	$31, %edx
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	orl	%edx, %eax
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L177:
	.cfi_restore_state
	subl	%ebx, %ebp
	jne	L195
L182:
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L194:
	.cfi_restore_state
	movl	$__ZGVZL19_strncmp_fast_case2PKcS0_jE4null, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	je	L175
	movl	$__ZGVZL19_strncmp_fast_case2PKcS0_jE4null, (%esp)
	pxor	%xmm0, %xmm0
	movdqa	%xmm0, __ZZL19_strncmp_fast_case2PKcS0_jE4null
	call	___cxa_guard_release
	jmp	L175
	.p2align 4,,7
L195:
	movdqa	(%ebx), %xmm2
	pcmpistri	$26, (%esi), %xmm2
	jnc	L182
	cmpl	%ecx, %ebp
	ja	L193
	jmp	L182
	.cfi_endproc
LFE3558:
	.p2align 4,,15
	.def	__ZL19_strncmp_fast_case1PKcS0_j;	.scl	3;	.type	32;	.endef
__ZL19_strncmp_fast_case1PKcS0_j:
LFB3557:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	cmpb	$0, __ZGVZL19_strncmp_fast_case1PKcS0_jE4null
	movl	48(%esp), %ebx
	movl	52(%esp), %esi
	je	L217
L198:
	movl	56(%esp), %ebp
	addl	%ebx, %ebp
	leal	-16(%ebp), %edi
	cmpl	%edi, %ebx
	jbe	L204
	jmp	L200
	.p2align 4,,7
L201:
	testl	%edx, %edx
	jne	L205
	addl	$16, %ebx
	addl	$16, %esi
	cmpl	%ebx, %edi
	jb	L200
L204:
	movl	$0, %eax
	movdqu	(%ebx), %xmm0
	movdqa	(%esi), %xmm1
	movl	$0, %edx
	pcmpistri	$26, %xmm1, %xmm0
	setc	%al
	sete	%dl
	testl	%eax, %eax
	je	L201
L216:
	movsbl	(%esi,%ecx), %eax
	movsbl	(%ebx,%ecx), %edx
	subl	%eax, %edx
	setne	%al
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movzbl	%al, %eax
	sarl	$31, %edx
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	orl	%edx, %eax
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L200:
	.cfi_restore_state
	subl	%ebx, %ebp
	jne	L218
L205:
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L217:
	.cfi_restore_state
	movl	$__ZGVZL19_strncmp_fast_case1PKcS0_jE4null, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	je	L198
	movl	$__ZGVZL19_strncmp_fast_case1PKcS0_jE4null, (%esp)
	pxor	%xmm0, %xmm0
	movdqa	%xmm0, __ZZL19_strncmp_fast_case1PKcS0_jE4null
	call	___cxa_guard_release
	jmp	L198
	.p2align 4,,7
L218:
	movdqu	(%ebx), %xmm0
	pcmpistri	$26, (%esi), %xmm0
	jnc	L205
	cmpl	%ecx, %ebp
	ja	L216
	jmp	L205
	.cfi_endproc
LFE3557:
	.p2align 4,,15
	.def	__ZL19_strncmp_fast_case0PKcS0_j;	.scl	3;	.type	32;	.endef
__ZL19_strncmp_fast_case0PKcS0_j:
LFB3556:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	cmpb	$0, __ZGVZL19_strncmp_fast_case0PKcS0_jE4null
	movl	48(%esp), %ebx
	movl	52(%esp), %esi
	je	L238
L221:
	movl	56(%esp), %ebp
	addl	%ebx, %ebp
	leal	-16(%ebp), %edi
	cmpl	%edi, %ebx
	jbe	L226
	jmp	L223
	.p2align 4,,7
L224:
	testl	%edx, %edx
	jne	L225
	addl	$16, %ebx
	addl	$16, %esi
	cmpl	%ebx, %edi
	jb	L223
L226:
	movdqa	(%esi), %xmm1
	movdqa	(%ebx), %xmm0
	pcmpistri	$26, %xmm1, %xmm0
	setc	%al
	movl	$0, %edx
	movzbl	%al, %eax
	sete	%dl
	testl	%eax, %eax
	je	L224
L237:
	movsbl	(%esi,%ecx), %eax
	movsbl	(%ebx,%ecx), %edx
	subl	%eax, %edx
	setne	%al
	movzbl	%al, %eax
	sarl	$31, %edx
	orl	%edx, %eax
L225:
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L223:
	.cfi_restore_state
	xorl	%eax, %eax
	subl	%ebx, %ebp
	je	L225
	movdqa	(%ebx), %xmm2
	pcmpistri	$26, (%esi), %xmm2
	setc	%al
	movzbl	%al, %eax
	jnc	L225
	xorl	%eax, %eax
	cmpl	%ecx, %ebp
	ja	L237
	jmp	L225
	.p2align 4,,7
L238:
	movl	$__ZGVZL19_strncmp_fast_case0PKcS0_jE4null, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	je	L221
	movl	$__ZGVZL19_strncmp_fast_case0PKcS0_jE4null, (%esp)
	pxor	%xmm0, %xmm0
	movdqa	%xmm0, __ZZL19_strncmp_fast_case0PKcS0_jE4null
	call	___cxa_guard_release
	jmp	L221
	.cfi_endproc
LFE3556:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_16_uPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_16_uPcU8__vectorx:
LFB3604:
	.cfi_startproc
	movl	4(%esp), %eax
	movdqu	%xmm0, (%eax)
	ret
	.cfi_endproc
LFE3604:
	.p2align 4,,15
	.def	__ZL18_strcpy_fast_case3PcPKc;	.scl	3;	.type	32;	.endef
__ZL18_strcpy_fast_case3PcPKc:
LFB3610:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	cmpb	$0, __ZGVZL18_strcpy_fast_case3PcPKcE4null
	movl	32(%esp), %esi
	movl	36(%esp), %ebx
	je	L252
L242:
	movl	%esi, %edx
	jmp	L245
	.p2align 4,,7
L253:
	movdqu	%xmm0, (%edx)
	addl	$16, %ebx
	addl	$16, %edx
L245:
	movdqu	(%ebx), %xmm0
	movdqa	__ZZL18_strcpy_fast_case3PcPKcE4null, %xmm1
	pcmpistri	$10, %xmm0, %xmm1
	jne	L253
	movl	%edx, (%esp)
	call	*__ZL17_memcpy_m128i_u_x+4(,%ecx,4)
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	movl	%esi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L252:
	.cfi_restore_state
	movl	$__ZGVZL18_strcpy_fast_case3PcPKcE4null, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	je	L242
	movl	$__ZGVZL18_strcpy_fast_case3PcPKcE4null, (%esp)
	pxor	%xmm0, %xmm0
	movdqa	%xmm0, __ZZL18_strcpy_fast_case3PcPKcE4null
	call	___cxa_guard_release
	jmp	L242
	.cfi_endproc
LFE3610:
	.p2align 4,,15
	.def	__ZL18_strcpy_fast_case1PcPKc;	.scl	3;	.type	32;	.endef
__ZL18_strcpy_fast_case1PcPKc:
LFB3608:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	cmpb	$0, __ZGVZL18_strcpy_fast_case1PcPKcE4null
	movl	32(%esp), %esi
	movl	36(%esp), %ebx
	je	L266
L256:
	movl	%esi, %edx
	jmp	L259
	.p2align 4,,7
L267:
	movdqu	%xmm0, (%edx)
	addl	$16, %ebx
	addl	$16, %edx
L259:
	movdqa	(%ebx), %xmm0
	movdqa	__ZZL18_strcpy_fast_case1PcPKcE4null, %xmm2
	pcmpistri	$10, %xmm0, %xmm2
	jne	L267
	movl	%edx, (%esp)
	call	*__ZL17_memcpy_m128i_u_x+4(,%ecx,4)
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	movl	%esi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L266:
	.cfi_restore_state
	movl	$__ZGVZL18_strcpy_fast_case1PcPKcE4null, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	je	L256
	movl	$__ZGVZL18_strcpy_fast_case1PcPKcE4null, (%esp)
	pxor	%xmm0, %xmm0
	movdqa	%xmm0, __ZZL18_strcpy_fast_case1PcPKcE4null
	call	___cxa_guard_release
	jmp	L256
	.cfi_endproc
LFE3608:
	.p2align 4,,15
	.def	__ZL19_strncpy_fast_case3PcPKcj;	.scl	3;	.type	32;	.endef
__ZL19_strncpy_fast_case3PcPKcj:
LFB3617:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	cmpb	$0, __ZGVZL19_strncpy_fast_case3PcPKcjE4null
	movl	32(%esp), %edi
	movl	36(%esp), %ebx
	je	L284
L270:
	movl	40(%esp), %eax
	movl	%edi, %esi
	addl	%ebx, %eax
	leal	-16(%eax), %edx
	cmpl	%edx, %ebx
	jbe	L275
	jmp	L272
	.p2align 4,,7
L273:
	addl	$16, %ebx
	movdqu	%xmm0, (%esi)
	addl	$16, %esi
	cmpl	%ebx, %edx
	jb	L272
L275:
	movdqu	(%ebx), %xmm0
	movdqa	__ZZL19_strncpy_fast_case3PcPKcjE4null, %xmm1
	pcmpistri	$10, %xmm0, %xmm1
	jne	L273
	movl	%ecx, 12(%esp)
	movl	%esi, (%esp)
	call	*__ZL17_memcpy_m128i_u_x(,%ecx,4)
	movl	12(%esp), %ecx
	movb	$0, (%esi,%ecx)
L274:
	addl	$16, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%edi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L272:
	.cfi_restore_state
	subl	%ebx, %eax
	je	L274
	movdqu	(%ebx), %xmm0
	movl	%esi, (%esp)
	call	*__ZL17_memcpy_m128i_u_x(,%eax,4)
	addl	$16, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%edi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L284:
	.cfi_restore_state
	movl	$__ZGVZL19_strncpy_fast_case3PcPKcjE4null, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	je	L270
	movl	$__ZGVZL19_strncpy_fast_case3PcPKcjE4null, (%esp)
	pxor	%xmm0, %xmm0
	movdqa	%xmm0, __ZZL19_strncpy_fast_case3PcPKcjE4null
	call	___cxa_guard_release
	jmp	L270
	.cfi_endproc
LFE3617:
	.p2align 4,,15
	.def	__ZL19_strncpy_fast_case1PcPKcj;	.scl	3;	.type	32;	.endef
__ZL19_strncpy_fast_case1PcPKcj:
LFB3615:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	cmpb	$0, __ZGVZL19_strncpy_fast_case1PcPKcjE4null
	movl	32(%esp), %edi
	movl	36(%esp), %ebx
	je	L301
L287:
	movl	40(%esp), %eax
	movl	%edi, %esi
	addl	%ebx, %eax
	leal	-16(%eax), %edx
	cmpl	%edx, %ebx
	jbe	L292
	jmp	L289
	.p2align 4,,7
L290:
	addl	$16, %ebx
	movdqu	%xmm0, (%esi)
	addl	$16, %esi
	cmpl	%ebx, %edx
	jb	L289
L292:
	movdqa	(%ebx), %xmm0
	movdqa	__ZZL19_strncpy_fast_case1PcPKcjE4null, %xmm2
	pcmpistri	$10, %xmm0, %xmm2
	jne	L290
	movl	%ecx, 12(%esp)
	movl	%esi, (%esp)
	call	*__ZL17_memcpy_m128i_u_x(,%ecx,4)
	movl	12(%esp), %ecx
	movb	$0, (%esi,%ecx)
L291:
	addl	$16, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%edi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L289:
	.cfi_restore_state
	subl	%ebx, %eax
	je	L291
	movdqa	(%ebx), %xmm0
	movl	%esi, (%esp)
	call	*__ZL17_memcpy_m128i_u_x(,%eax,4)
	addl	$16, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%edi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L301:
	.cfi_restore_state
	movl	$__ZGVZL19_strncpy_fast_case1PcPKcjE4null, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	je	L287
	movl	$__ZGVZL19_strncpy_fast_case1PcPKcjE4null, (%esp)
	pxor	%xmm0, %xmm0
	movdqa	%xmm0, __ZZL19_strncpy_fast_case1PcPKcjE4null
	call	___cxa_guard_release
	jmp	L287
	.cfi_endproc
LFE3615:
	.p2align 4,,15
	.def	__Z41__static_initialization_and_destruction_0ii.part.35;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii.part.35:
LFB3979:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3979
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L303
	movl	$3, 8(%esp)
	movl	$_s_lambda3, 4(%esp)
	movl	$_s_lambda3, (%esp)
	call	*%eax
L303:
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L304
	movl	$3, 8(%esp)
	movl	$_s_lambda2, 4(%esp)
	movl	$_s_lambda2, (%esp)
	call	*%eax
L304:
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L305
	movl	$3, 8(%esp)
	movl	$_s_lambda1, 4(%esp)
	movl	$_s_lambda1, (%esp)
	call	*%eax
L305:
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitD1Ev
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3979:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA3979:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3979-LLSDACSB3979
LLSDACSB3979:
LLSDACSE3979:
	.text
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation:
LFB3791:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L318
	jle	L324
	cmpl	$2, %eax
	je	L321
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L317
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L317:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L321:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	(%eax), %ebx
	movl	$4, (%esp)
	call	__Znwj
	movl	(%ebx), %edx
	movl	%edx, (%eax)
	movl	32(%esp), %edx
	movl	%eax, (%edx)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L324:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L317
	movl	32(%esp), %eax
	movl	$__ZTIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_, (%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L318:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %ecx
	movl	(%eax), %eax
	movl	%eax, (%ecx)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3791:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation:
LFB3797:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L327
	jle	L333
	cmpl	$2, %eax
	je	L330
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L326
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L326:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L330:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	(%eax), %ebx
	movl	$4, (%esp)
	call	__Znwj
	movl	(%ebx), %edx
	movl	%edx, (%eax)
	movl	32(%esp), %edx
	movl	%eax, (%edx)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L333:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L326
	movl	32(%esp), %eax
	movl	$__ZTIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_, (%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L327:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %ecx
	movl	(%eax), %eax
	movl	%eax, (%ecx)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3797:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation:
LFB3882:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L336
	jle	L342
	cmpl	$2, %eax
	je	L339
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L335
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L335:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L339:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	(%eax), %ebx
	movl	$4, (%esp)
	call	__Znwj
	movl	(%ebx), %edx
	movl	%edx, (%eax)
	movl	32(%esp), %edx
	movl	%eax, (%edx)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L342:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L335
	movl	32(%esp), %eax
	movl	$__ZTIZ9setLambdaRiEUlvE_, (%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L336:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %ecx
	movl	(%eax), %eax
	movl	%eax, (%ecx)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3882:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation:
LFB3886:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L345
	jle	L351
	cmpl	$2, %eax
	je	L348
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L344
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L344:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L348:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	(%eax), %ebx
	movl	$4, (%esp)
	call	__Znwj
	movl	(%ebx), %edx
	movl	%edx, (%eax)
	movl	32(%esp), %edx
	movl	%eax, (%edx)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L351:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L344
	movl	32(%esp), %eax
	movl	$__ZTIZ9setLambdaRiEUlvE0_, (%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L345:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %ecx
	movl	(%eax), %eax
	movl	%eax, (%ecx)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3886:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation:
LFB3890:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L354
	jle	L360
	cmpl	$2, %eax
	je	L357
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L353
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L353:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L357:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L360:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L353
	movl	32(%esp), %eax
	movl	$__ZTIZ9setLambdaRiEUlvE1_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L354:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3890:
	.p2align 4,,15
	.globl	__Z22testOpt01_Type1_BeforeR11dataOpt01_t
	.def	__Z22testOpt01_Type1_BeforeR11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z22testOpt01_Type1_BeforeR11dataOpt01_t:
LFB2671:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$20, %esp
	.cfi_def_cfa_offset 40
	movl	40(%esp), %ebx
	leal	4(%ebx), %eax
	movl	(%ebx), %esi
	andl	$15, %eax
	shrl	$2, %eax
	negl	%eax
	andl	$3, %eax
	je	L370
	addl	4(%ebx), %esi
	cmpl	$1, %eax
	jbe	L371
	addl	8(%ebx), %esi
	cmpl	$2, %eax
	jbe	L372
	addl	12(%ebx), %esi
	movl	$9997, 4(%esp)
	movl	$3, (%esp)
L362:
	movl	$10000, %edi
	pxor	%xmm0, %xmm0
	subl	%eax, %edi
	movl	%edi, %ecx
	shrl	$2, %ecx
	leal	4(%ebx,%eax,4), %edx
	xorl	%eax, %eax
	leal	0(,%ecx,4), %ebp
	.p2align 4,,7
L369:
	addl	$1, %eax
	addl	$16, %edx
	paddd	-16(%edx), %xmm0
	cmpl	%eax, %ecx
	ja	L369
	movdqa	%xmm0, %xmm2
	movl	(%esp), %edx
	psrldq	$8, %xmm2
	movl	4(%esp), %ecx
	paddd	%xmm2, %xmm0
	movdqa	%xmm0, %xmm3
	psrldq	$4, %xmm3
	paddd	%xmm3, %xmm0
	pextrd	$0, %xmm0, %eax
	addl	%ebp, %edx
	addl	%esi, %eax
	subl	%ebp, %ecx
	cmpl	%ebp, %edi
	je	L367
	addl	4(%ebx,%edx,4), %eax
	cmpl	$1, %ecx
	leal	1(%edx), %esi
	je	L367
	addl	4(%ebx,%esi,4), %eax
	addl	$2, %edx
	cmpl	$2, %ecx
	je	L367
	addl	4(%ebx,%edx,4), %eax
L367:
	movl	%eax, (%ebx)
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L370:
	.cfi_restore_state
	movl	$10000, 4(%esp)
	movl	$0, (%esp)
	jmp	L362
	.p2align 4,,7
L371:
	movl	$9999, 4(%esp)
	movl	$1, (%esp)
	jmp	L362
	.p2align 4,,7
L372:
	movl	$9998, 4(%esp)
	movl	$2, (%esp)
	jmp	L362
	.cfi_endproc
LFE2671:
	.p2align 4,,15
	.globl	__Z22testOpt01_Type1_After1R11dataOpt01_t
	.def	__Z22testOpt01_Type1_After1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z22testOpt01_Type1_After1R11dataOpt01_t:
LFB2672:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$20, %esp
	.cfi_def_cfa_offset 40
	movl	40(%esp), %ebx
	leal	4(%ebx), %eax
	andl	$15, %eax
	shrl	$2, %eax
	negl	%eax
	andl	$3, %eax
	je	L388
	cmpl	$1, %eax
	movl	4(%ebx), %esi
	jbe	L389
	addl	8(%ebx), %esi
	cmpl	$2, %eax
	jbe	L390
	addl	12(%ebx), %esi
	movl	$9997, 4(%esp)
	movl	$3, (%esp)
L380:
	movl	$10000, %edi
	pxor	%xmm0, %xmm0
	subl	%eax, %edi
	movl	%edi, %ecx
	shrl	$2, %ecx
	leal	4(%ebx,%eax,4), %edx
	xorl	%eax, %eax
	leal	0(,%ecx,4), %ebp
	.p2align 4,,7
L387:
	addl	$1, %eax
	addl	$16, %edx
	paddd	-16(%edx), %xmm0
	cmpl	%eax, %ecx
	ja	L387
	movdqa	%xmm0, %xmm2
	psrldq	$8, %xmm2
	movl	4(%esp), %edx
	paddd	%xmm2, %xmm0
	movdqa	%xmm0, %xmm3
	psrldq	$4, %xmm3
	paddd	%xmm3, %xmm0
	pextrd	$0, %xmm0, %eax
	addl	%eax, %esi
	movl	(%esp), %eax
	subl	%ebp, %edx
	addl	%ebp, %eax
	cmpl	%ebp, %edi
	je	L385
	addl	4(%ebx,%eax,4), %esi
	cmpl	$1, %edx
	leal	1(%eax), %ecx
	je	L385
	addl	4(%ebx,%ecx,4), %esi
	addl	$2, %eax
	cmpl	$2, %edx
	je	L385
	addl	4(%ebx,%eax,4), %esi
L385:
	movl	%esi, (%ebx)
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L388:
	.cfi_restore_state
	movl	$10000, 4(%esp)
	xorl	%esi, %esi
	movl	$0, (%esp)
	jmp	L380
	.p2align 4,,7
L389:
	movl	$9999, 4(%esp)
	movl	$1, (%esp)
	jmp	L380
	.p2align 4,,7
L390:
	movl	$9998, 4(%esp)
	movl	$2, (%esp)
	jmp	L380
	.cfi_endproc
LFE2672:
	.p2align 4,,15
	.globl	__Z22testOpt01_Type1_After2R11dataOpt01_t
	.def	__Z22testOpt01_Type1_After2R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z22testOpt01_Type1_After2R11dataOpt01_t:
LFB2673:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$10000, %edx
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$20, %esp
	.cfi_def_cfa_offset 40
	movl	40(%esp), %eax
	leal	40004(%eax), %edi
	movl	%edi, %ebx
	leal	4(%eax), %ecx
	leal	5(%eax), %esi
	cmpl	%ebx, %esi
	movl	%ecx, %ebx
	movl	%edi, (%esp)
	movl	$1, %edi
	cmovbe	%edx, %edi
	andl	$15, %ebx
	shrl	$2, %ebx
	negl	%ebx
	andl	$3, %ebx
	cmpl	%edi, %ebx
	cmova	%edi, %ebx
	cmpl	$8, %edx
	leal	8(%eax), %ebp
	ja	L418
L409:
	movl	%edi, %ebx
L398:
	cmpl	$1, %ebx
	movl	4(%eax), %edx
	jbe	L411
	addl	8(%eax), %edx
	cmpl	$2, %ebx
	leal	12(%eax), %ecx
	jbe	L400
	addl	12(%eax), %edx
	cmpl	$3, %ebx
	leal	16(%eax), %ecx
	jbe	L400
	addl	16(%eax), %edx
	cmpl	$4, %ebx
	leal	20(%eax), %ecx
	jbe	L400
	addl	20(%eax), %edx
	cmpl	$5, %ebx
	leal	24(%eax), %ecx
	jbe	L400
	addl	24(%eax), %edx
	cmpl	$6, %ebx
	leal	28(%eax), %ecx
	jbe	L400
	addl	28(%eax), %edx
	cmpl	$7, %ebx
	leal	32(%eax), %ecx
	jbe	L400
	addl	32(%eax), %edx
	leal	36(%eax), %ecx
L400:
	cmpl	%ebx, %edi
	je	L401
L399:
	subl	%ebx, %edi
	movl	%edi, %esi
	shrl	$2, %esi
	leal	0(,%esi,4), %ebp
	testl	%ebp, %ebp
	movl	%esi, 4(%esp)
	je	L402
	leal	4(%eax,%ebx,4), %esi
	xorl	%ebx, %ebx
	pxor	%xmm0, %xmm0
L408:
	paddd	(%esi), %xmm0
	addl	$1, %ebx
	addl	$16, %esi
	cmpl	%ebx, 4(%esp)
	ja	L408
	movdqa	%xmm0, %xmm2
	psrldq	$8, %xmm2
	paddd	%xmm2, %xmm0
	movdqa	%xmm0, %xmm3
	psrldq	$4, %xmm3
	paddd	%xmm3, %xmm0
	pextrd	$0, %xmm0, %ebx
	addl	%ebx, %edx
	cmpl	%ebp, %edi
	leal	(%ecx,%ebp,4), %ecx
	je	L401
L402:
	movl	(%esp), %esi
	leal	4(%ecx), %ebx
	addl	(%ecx), %edx
	cmpl	%ebx, %esi
	jbe	L401
	leal	8(%ecx), %ebx
	addl	4(%ecx), %edx
	cmpl	%ebx, %esi
	jbe	L401
	addl	8(%ecx), %edx
L401:
	movl	%edx, (%eax)
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L418:
	.cfi_restore_state
	cmpl	(%esp), %esi
	ja	L409
	testl	%ebx, %ebx
	jne	L398
	xorl	%ebx, %ebx
	xorl	%edx, %edx
	.p2align 4,,2
	jmp	L399
	.p2align 4,,7
L411:
	movl	%ebp, %ecx
	jmp	L400
	.cfi_endproc
LFE2673:
	.p2align 4,,15
	.globl	__Z24testOpt01_Type1_AppendixR11dataOpt01_t
	.def	__Z24testOpt01_Type1_AppendixR11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z24testOpt01_Type1_AppendixR11dataOpt01_t:
LFB2674:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %ecx
	leal	4(%ecx), %eax
	leal	40004(%ecx), %ebx
	cmpl	%ebx, %eax
	je	L419
	movl	(%ecx), %edx
	.p2align 4,,7
L422:
	addl	(%eax), %edx
	addl	$4, %eax
	cmpl	%eax, %ebx
	movl	%edx, (%ecx)
	jne	L422
L419:
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2674:
	.p2align 4,,15
	.globl	__Z22testOpt02_Type1_BeforeR11dataOpt02_t
	.def	__Z22testOpt02_Type1_BeforeR11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z22testOpt02_Type1_BeforeR11dataOpt02_t:
LFB2676:
	.cfi_startproc
	subl	$108, %esp
	.cfi_def_cfa_offset 112
	xorl	%eax, %eax
	movl	112(%esp), %ecx
	movdqa	LC0, %xmm0
	movdqa	%xmm0, (%esp)
	movl	$8, 64(%esp)
	movdqa	LC1, %xmm0
	movdqa	%xmm0, 16(%esp)
	movl	$0, 68(%esp)
	movdqa	LC2, %xmm0
	movdqa	%xmm0, 32(%esp)
	movl	$9, 72(%esp)
	movdqa	LC3, %xmm0
	movdqa	%xmm0, 48(%esp)
	movl	$0, 76(%esp)
	movl	$10, 80(%esp)
	movl	$0, 84(%esp)
	.p2align 4,,7
L426:
	movl	(%ecx,%eax,4), %edx
	addl	$1, %eax
	addl	$1, 4(%esp,%edx,8)
	cmpl	$10000, %eax
	jne	L426
	movl	4(%esp), %eax
	movl	%esp, %edx
	cmpl	%eax, 12(%esp)
	jle	L427
	movl	12(%esp), %eax
	leal	8(%esp), %edx
L427:
	cmpl	20(%esp), %eax
	jge	L428
	movl	20(%esp), %eax
	leal	16(%esp), %edx
L428:
	cmpl	28(%esp), %eax
	jge	L429
	movl	28(%esp), %eax
	leal	24(%esp), %edx
L429:
	cmpl	36(%esp), %eax
	jge	L430
	movl	36(%esp), %eax
	leal	32(%esp), %edx
L430:
	cmpl	44(%esp), %eax
	jge	L431
	movl	44(%esp), %eax
	leal	40(%esp), %edx
L431:
	cmpl	52(%esp), %eax
	jge	L432
	movl	52(%esp), %eax
	leal	48(%esp), %edx
L432:
	cmpl	60(%esp), %eax
	jge	L433
	movl	60(%esp), %eax
	leal	56(%esp), %edx
L433:
	cmpl	68(%esp), %eax
	jge	L434
	movl	68(%esp), %eax
	leal	64(%esp), %edx
L434:
	cmpl	76(%esp), %eax
	jge	L435
	movl	76(%esp), %eax
	leal	72(%esp), %edx
L435:
	cmpl	%eax, 84(%esp)
	jle	L436
	movl	84(%esp), %eax
	leal	80(%esp), %edx
L436:
	sall	$16, %eax
	orl	(%edx), %eax
	addl	$108, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2676:
	.p2align 4,,15
	.globl	__Z22testOpt02_Type1_After1R11dataOpt02_t
	.def	__Z22testOpt02_Type1_After1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z22testOpt02_Type1_After1R11dataOpt02_t:
LFB2677:
	.cfi_startproc
	subl	$108, %esp
	.cfi_def_cfa_offset 112
	movl	112(%esp), %eax
	movdqa	LC0, %xmm0
	movdqa	%xmm0, (%esp)
	movl	$8, 64(%esp)
	movdqa	LC1, %xmm0
	movdqa	%xmm0, 16(%esp)
	movl	$0, 68(%esp)
	movdqa	LC2, %xmm0
	movdqa	%xmm0, 32(%esp)
	movl	$9, 72(%esp)
	movdqa	LC3, %xmm0
	movdqa	%xmm0, 48(%esp)
	movl	$0, 76(%esp)
	leal	40000(%eax), %ecx
	movl	$10, 80(%esp)
	movl	$0, 84(%esp)
	.p2align 4,,7
L441:
	movl	(%eax), %edx
	addl	$4, %eax
	addl	$1, 4(%esp,%edx,8)
	cmpl	%eax, %ecx
	ja	L441
	movl	4(%esp), %eax
	movl	%esp, %edx
	cmpl	%eax, 12(%esp)
	jle	L442
	movl	12(%esp), %eax
	leal	8(%esp), %edx
L442:
	cmpl	20(%esp), %eax
	jge	L443
	movl	20(%esp), %eax
	leal	16(%esp), %edx
L443:
	cmpl	28(%esp), %eax
	jge	L444
	movl	28(%esp), %eax
	leal	24(%esp), %edx
L444:
	cmpl	36(%esp), %eax
	jge	L445
	movl	36(%esp), %eax
	leal	32(%esp), %edx
L445:
	cmpl	44(%esp), %eax
	jge	L446
	movl	44(%esp), %eax
	leal	40(%esp), %edx
L446:
	cmpl	52(%esp), %eax
	jge	L447
	movl	52(%esp), %eax
	leal	48(%esp), %edx
L447:
	cmpl	60(%esp), %eax
	jge	L448
	movl	60(%esp), %eax
	leal	56(%esp), %edx
L448:
	cmpl	68(%esp), %eax
	jge	L449
	movl	68(%esp), %eax
	leal	64(%esp), %edx
L449:
	cmpl	76(%esp), %eax
	jge	L450
	movl	76(%esp), %eax
	leal	72(%esp), %edx
L450:
	cmpl	%eax, 84(%esp)
	jle	L452
	movl	84(%esp), %eax
	leal	80(%esp), %edx
L452:
	sall	$16, %eax
	orl	(%edx), %eax
	addl	$108, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2677:
	.p2align 4,,15
	.globl	__Z22testOpt02_Type1_After2R11dataOpt02_t
	.def	__Z22testOpt02_Type1_After2R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z22testOpt02_Type1_After2R11dataOpt02_t:
LFB2678:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$1, %eax
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$108, %esp
	.cfi_def_cfa_offset 128
	leal	8(%esp), %esi
	leal	95(%esp), %ebx
	subl	%esi, %ebx
	shrl	$3, %ebx
	leal	1(%esp), %ecx
	addl	$1, %ebx
	leal	88(%esp), %edx
	cmpl	%edx, %ecx
	cmovbe	%ebx, %eax
	movl	%eax, %edi
	shrl	$2, %edi
	leal	0(,%edi,4), %ebp
	testl	%ebp, %ebp
	je	L467
	cmpl	$5, %ebx
	setbe	%bl
	cmpl	%edx, %ecx
	seta	%cl
	orl	%ecx, %ebx
	cmpb	$1, %bl
	sbbl	%ecx, %ecx
	cmpb	$-1, %cl
	jne	L467
	movl	%esp, %ecx
	xorl	%ebx, %ebx
	movdqa	LC5, %xmm3
	movdqa	LC4, %xmm0
	pxor	%xmm1, %xmm1
L462:
	addl	$1, %ebx
	movdqa	%xmm0, %xmm4
	movdqa	%xmm0, %xmm2
	addl	$32, %ecx
	punpckldq	%xmm1, %xmm2
	punpckhdq	%xmm1, %xmm0
	movdqa	%xmm2, -32(%ecx)
	movdqa	%xmm0, -16(%ecx)
	cmpl	%ebx, %edi
	paddd	%xmm3, %xmm4
	jbe	L473
	movdqa	%xmm4, %xmm0
	jmp	L462
	.p2align 4,,7
L467:
	movl	%esp, %ecx
	xorl	%ebp, %ebp
L457:
	leal	8(%ecx), %ebx
	cmpl	%ebx, %edx
	leal	1(%ebp), %eax
	movl	%ebp, (%ecx)
	movl	$0, 4(%ecx)
	jbe	L460
	movl	%eax, 8(%ecx)
	leal	16(%ecx), %eax
	cmpl	%eax, %edx
	leal	2(%ebp), %ebx
	movl	$0, 12(%ecx)
	jbe	L460
	movl	%ebx, 16(%ecx)
	leal	24(%ecx), %ebx
	cmpl	%ebx, %edx
	leal	3(%ebp), %eax
	movl	$0, 20(%ecx)
	jbe	L460
	movl	%eax, 24(%ecx)
	leal	32(%ecx), %eax
	addl	$4, %ebp
	cmpl	%eax, %edx
	movl	$0, 28(%ecx)
	jbe	L460
	movl	%ebp, 32(%ecx)
	movl	$0, 36(%ecx)
L460:
	movl	128(%esp), %eax
	leal	40000(%eax), %ebx
	.p2align 4,,7
L464:
	movl	(%eax), %ecx
	addl	$4, %eax
	addl	$1, 4(%esp,%ecx,8)
	cmpl	%eax, %ebx
	ja	L464
	movl	4(%esp), %eax
	movl	%esp, %ebx
	.p2align 4,,7
L466:
	movl	4(%esi), %ecx
	cmpl	%eax, %ecx
	cmovg	%esi, %ebx
	cmpl	%ecx, %eax
	cmovl	%ecx, %eax
	addl	$8, %esi
	cmpl	%edx, %esi
	jb	L466
	sall	$16, %eax
	orl	(%ebx), %eax
	addl	$108, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L473:
	.cfi_restore_state
	cmpl	%eax, %ebp
	leal	(%esp,%ebp,8), %ecx
	jne	L457
	jmp	L460
	.cfi_endproc
LFE2678:
	.p2align 4,,15
	.globl	__Z22testOpt03_Type1_Beforeiii
	.def	__Z22testOpt03_Type1_Beforeiii;	.scl	2;	.type	32;	.endef
__Z22testOpt03_Type1_Beforeiii:
LFB2679:
	.cfi_startproc
	movl	8(%esp), %eax
	imull	4(%esp), %eax
	addl	12(%esp), %eax
	ret
	.cfi_endproc
LFE2679:
	.p2align 4,,15
	.globl	__Z22testOpt03_Type2_Beforeiiiiiiii
	.def	__Z22testOpt03_Type2_Beforeiiiiiiii;	.scl	2;	.type	32;	.endef
__Z22testOpt03_Type2_Beforeiiiiiiii:
LFB2680:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	20(%esp), %edx
	imull	16(%esp), %edx
	imull	4(%esp), %eax
	addl	12(%esp), %eax
	subl	%edx, %eax
	movl	32(%esp), %edx
	imull	28(%esp), %edx
	addl	24(%esp), %eax
	subl	%edx, %eax
	ret
	.cfi_endproc
LFE2680:
	.p2align 4,,15
	.globl	__Z22testOpt03_Type3_BeforeR11dataOpt03_t
	.def	__Z22testOpt03_Type3_BeforeR11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z22testOpt03_Type3_BeforeR11dataOpt03_t:
LFB3027:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3027
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	$4, (%esp)
	movl	$1, 16(%esp)
	movl	$0, 40(%esp)
LEHB0:
	call	__Znwj
LEHE0:
	movl	80(%esp), %esi
	leal	16(%esp), %edx
	movl	%edx, (%eax)
	movl	%eax, 32(%esp)
	movl	$__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_, 44(%esp)
	leal	40000(%esi), %edi
	cmpl	%edi, %esi
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, 40(%esp)
	jae	L579
	movl	%esi, %ebx
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %edx
	leal	32(%esp), %ebp
	jmp	L488
	.p2align 4,,7
L481:
	addl	$4, %ebx
	cmpl	%ebx, %edi
	jbe	L487
L580:
	movl	%eax, %edx
L488:
	movl	(%ebx), %ecx
	movl	%edx, %eax
	testl	%ecx, %ecx
	jne	L481
	testl	%edx, %edx
	je	L578
	movl	%ebx, 4(%esp)
	movl	%ebp, (%esp)
LEHB1:
	call	*44(%esp)
LEHE1:
	addl	$4, %ebx
	movl	40(%esp), %eax
	cmpl	%ebx, %edi
	ja	L580
L487:
	testl	%eax, %eax
	je	L489
L478:
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L489:
	movl	$4, (%esp)
	movl	$0, 28(%esp)
	movl	$0, 40(%esp)
LEHB2:
	call	__Znwj
LEHE2:
	cmpl	%edi, 80(%esp)
	leal	28(%esp), %ecx
	movl	%ecx, (%eax)
	movl	%eax, 32(%esp)
	movl	$__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_, 44(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, 40(%esp)
	jae	L581
	movl	80(%esp), %ebx
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %edx
	leal	32(%esp), %ebp
	jmp	L502
	.p2align 4,,7
L495:
	addl	$4, %ebx
	cmpl	%ebx, %edi
	jbe	L501
L582:
	movl	%eax, %edx
L502:
	cmpl	$1, (%ebx)
	movl	%edx, %eax
	jne	L495
	testl	%edx, %edx
	je	L578
	movl	%ebx, 4(%esp)
	movl	%ebp, (%esp)
LEHB3:
	call	*44(%esp)
LEHE3:
	addl	$4, %ebx
	movl	40(%esp), %eax
	cmpl	%ebx, %edi
	ja	L582
L501:
	testl	%eax, %eax
	je	L503
L492:
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L503:
	movl	28(%esp), %eax
	movl	$4, (%esp)
	movl	$0, 28(%esp)
	movl	$0, 40(%esp)
	movl	%eax, 12(%esp)
LEHB4:
	call	__Znwj
LEHE4:
	cmpl	%edi, 80(%esp)
	leal	28(%esp), %ecx
	movl	%ecx, (%eax)
	movl	%eax, 32(%esp)
	movl	$__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_, 44(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, 40(%esp)
	jae	L583
	movl	80(%esp), %ebx
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %edx
	leal	32(%esp), %ebp
	jmp	L516
	.p2align 4,,7
L509:
	addl	$4, %ebx
	cmpl	%ebx, %edi
	jbe	L515
L584:
	movl	%eax, %edx
L516:
	cmpl	$2, (%ebx)
	movl	%edx, %eax
	jne	L509
	testl	%edx, %edx
	je	L578
	movl	%ebx, 4(%esp)
	movl	%ebp, (%esp)
LEHB5:
	call	*44(%esp)
LEHE5:
	addl	$4, %ebx
	movl	40(%esp), %eax
	cmpl	%ebx, %edi
	ja	L584
L515:
	testl	%eax, %eax
	je	L517
L506:
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L517:
	movl	12(%esp), %ebx
	movl	$4, (%esp)
	addl	28(%esp), %ebx
	movl	$0, 40(%esp)
	movl	$0, 28(%esp)
LEHB6:
	call	__Znwj
LEHE6:
	cmpl	%edi, 80(%esp)
	leal	28(%esp), %ecx
	movl	%ecx, (%eax)
	movl	%eax, 32(%esp)
	movl	$__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_, 44(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, 40(%esp)
	jae	L585
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %edx
	leal	32(%esp), %ebp
	jmp	L530
	.p2align 4,,7
L523:
	addl	$4, %esi
	cmpl	%esi, %edi
	jbe	L529
L586:
	movl	%eax, %edx
L530:
	cmpl	$3, (%esi)
	movl	%edx, %eax
	jne	L523
	testl	%edx, %edx
	je	L578
	movl	%esi, 4(%esp)
	movl	%ebp, (%esp)
LEHB7:
	call	*44(%esp)
LEHE7:
	addl	$4, %esi
	movl	40(%esp), %eax
	cmpl	%esi, %edi
	ja	L586
L529:
	testl	%eax, %eax
	je	L531
L520:
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L531:
	movl	28(%esp), %eax
	addl	$60, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	addl	%ebx, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
L578:
	.cfi_restore_state
LEHB8:
	call	__ZSt25__throw_bad_function_callv
LEHE8:
L579:
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %eax
	jmp	L478
L585:
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %eax
	jmp	L520
L583:
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %eax
	jmp	L506
L581:
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %eax
	jmp	L492
L541:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L528
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
L528:
	movl	%ebx, (%esp)
LEHB9:
	call	__Unwind_Resume
LEHE9:
L538:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L528
	movl	$3, 8(%esp)
	movl	%ebp, 4(%esp)
	movl	%ebp, (%esp)
	call	*%edx
	jmp	L528
L539:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L528
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L528
L536:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L528
	movl	$3, 8(%esp)
	movl	%ebp, 4(%esp)
	movl	%ebp, (%esp)
	call	*%edx
	jmp	L528
L537:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L528
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L528
L542:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L528
	movl	$3, 8(%esp)
	movl	%ebp, 4(%esp)
	movl	%ebp, (%esp)
	call	*%edx
	jmp	L528
L543:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L528
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L528
L540:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L528
	movl	$3, 8(%esp)
	movl	%ebp, 4(%esp)
	movl	%ebp, (%esp)
	call	*%edx
	jmp	L528
	.cfi_endproc
LFE3027:
	.section	.gcc_except_table,"w"
LLSDA3027:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3027-LLSDACSB3027
LLSDACSB3027:
	.uleb128 LEHB0-LFB3027
	.uleb128 LEHE0-LEHB0
	.uleb128 L537-LFB3027
	.uleb128 0
	.uleb128 LEHB1-LFB3027
	.uleb128 LEHE1-LEHB1
	.uleb128 L536-LFB3027
	.uleb128 0
	.uleb128 LEHB2-LFB3027
	.uleb128 LEHE2-LEHB2
	.uleb128 L539-LFB3027
	.uleb128 0
	.uleb128 LEHB3-LFB3027
	.uleb128 LEHE3-LEHB3
	.uleb128 L538-LFB3027
	.uleb128 0
	.uleb128 LEHB4-LFB3027
	.uleb128 LEHE4-LEHB4
	.uleb128 L541-LFB3027
	.uleb128 0
	.uleb128 LEHB5-LFB3027
	.uleb128 LEHE5-LEHB5
	.uleb128 L540-LFB3027
	.uleb128 0
	.uleb128 LEHB6-LFB3027
	.uleb128 LEHE6-LEHB6
	.uleb128 L543-LFB3027
	.uleb128 0
	.uleb128 LEHB7-LFB3027
	.uleb128 LEHE7-LEHB7
	.uleb128 L542-LFB3027
	.uleb128 0
	.uleb128 LEHB8-LFB3027
	.uleb128 LEHE8-LEHB8
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB9-LFB3027
	.uleb128 LEHE9-LEHB9
	.uleb128 0
	.uleb128 0
LLSDACSE3027:
	.text
	.p2align 4,,15
	.globl	__Z21testOpt03_Type3_AfterR11dataOpt03_t
	.def	__Z21testOpt03_Type3_AfterR11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z21testOpt03_Type3_AfterR11dataOpt03_t:
LFB3035:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	20(%esp), %ebp
	leal	40000(%ebp), %edx
	cmpl	%edx, %ebp
	jae	L598
	movl	%ebp, %ecx
	movl	%ebp, %eax
	.p2align 4,,7
L591:
	movl	(%eax), %ebx
	testl	%ebx, %ebx
	jne	L589
	movl	$1, (%eax)
L589:
	addl	$4, %eax
	cmpl	%eax, %edx
	ja	L591
	movl	%ebp, %ebx
	xorl	%esi, %esi
	.p2align 4,,7
L593:
	cmpl	$1, (%ebx)
	leal	1(%esi), %edi
	cmove	%edi, %esi
	addl	$4, %ebx
	cmpl	%ebx, %edx
	ja	L593
	movl	%ebp, %eax
	xorl	%ebx, %ebx
	.p2align 4,,7
L595:
	cmpl	$2, (%eax)
	leal	1(%ebx), %edi
	cmove	%edi, %ebx
	addl	$4, %eax
	cmpl	%eax, %edx
	ja	L595
	addl	%ebx, %esi
	xorl	%eax, %eax
	.p2align 4,,7
L597:
	cmpl	$3, (%ecx)
	leal	1(%eax), %edi
	cmove	%edi, %eax
	addl	$4, %ecx
	cmpl	%ecx, %edx
	ja	L597
	addl	%esi, %eax
L599:
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
L598:
	.cfi_restore_state
	xorl	%eax, %eax
	jmp	L599
	.cfi_endproc
LFE3035:
	.p2align 4,,15
	.globl	__Z22testOpt04_Type1_BeforeR11dataOpt04_t
	.def	__Z22testOpt04_Type1_BeforeR11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type1_BeforeR11dataOpt04_t:
LFB3041:
	.cfi_startproc
	movl	4(%esp), %eax
	fldz
	leal	80000(%eax), %ecx
	movl	%eax, %edx
	.p2align 4,,7
L603:
	fildl	(%edx)
	addl	$8, %edx
	cmpl	%edx, %ecx
	faddp	%st, %st(1)
	ja	L603
	.p2align 4,,7
L605:
	fildl	(%eax)
	addl	$8, %eax
	fdiv	%st(1), %st
	fstps	-4(%eax)
	cmpl	%eax, %ecx
	ja	L605
	fstp	%st(0)
	ret
	.cfi_endproc
LFE3041:
	.p2align 4,,15
	.globl	__Z22testOpt04_Type1_After1R11dataOpt04_t
	.def	__Z22testOpt04_Type1_After1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type1_After1R11dataOpt04_t:
LFB3042:
	.cfi_startproc
	movl	4(%esp), %eax
	fldz
	leal	80000(%eax), %ecx
	movl	%eax, %edx
	.p2align 4,,7
L608:
	fildl	(%edx)
	addl	$8, %edx
	cmpl	%edx, %ecx
	faddp	%st, %st(1)
	ja	L608
	fdivrs	LC8
	.p2align 4,,7
L610:
	fildl	(%eax)
	addl	$8, %eax
	fmul	%st(1), %st
	fstps	-4(%eax)
	cmpl	%eax, %ecx
	ja	L610
	fstp	%st(0)
	ret
	.cfi_endproc
LFE3042:
	.p2align 4,,15
	.globl	__Z22testOpt04_Type1_After2R11dataOpt04_t
	.def	__Z22testOpt04_Type1_After2R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type1_After2R11dataOpt04_t:
LFB3043:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$10000, %ecx
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	movl	$1, %ebp
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$24, %esp
	.cfi_def_cfa_offset 44
	movl	44(%esp), %ebx
	leal	80000(%ebx), %edx
	leal	1(%ebx), %edi
	cmpl	%edi, %edx
	cmovae	%ecx, %ebp
	leal	-1(%ebp), %esi
	shrl	$2, %esi
	leal	0(,%esi,4), %eax
	testl	%eax, %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	je	L622
	cmpl	$10, %ecx
	setbe	%cl
	cmpl	%edi, %edx
	setb	%al
	movl	%eax, %edi
	orl	%edi, %ecx
	cmpb	$1, %cl
	sbbl	%ecx, %ecx
	cmpb	$-1, %cl
	jne	L622
	movl	%ebx, %ecx
	xorl	%edi, %edi
	pxor	%xmm0, %xmm0
	movl	%ebx, %eax
L619:
	movdqu	(%ecx), %xmm1
	movdqu	16(%ecx), %xmm2
	addl	$1, %edi
	shufps	$136, %xmm2, %xmm1
	addl	$32, %ecx
	cmpl	%edi, %esi
	paddd	%xmm1, %xmm0
	ja	L619
	movl	%eax, (%esp)
	movl	4(%esp), %eax
	movdqa	%xmm0, %xmm3
	psrldq	$8, %xmm3
	paddd	%xmm3, %xmm0
	movdqa	%xmm0, %xmm4
	psrldq	$4, %xmm4
	paddd	%xmm4, %xmm0
	cmpl	%eax, %ebp
	pextrd	$0, %xmm0, %ecx
	leal	(%ebx,%eax,8), %ebx
	je	L617
L613:
	leal	8(%ebx), %esi
	addl	(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L617
	leal	16(%ebx), %esi
	addl	8(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L617
	leal	24(%ebx), %esi
	addl	16(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L617
	leal	32(%ebx), %esi
	addl	24(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L617
	leal	40(%ebx), %esi
	addl	32(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L617
	leal	48(%ebx), %esi
	addl	40(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L617
	leal	56(%ebx), %esi
	addl	48(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L617
	leal	64(%ebx), %esi
	addl	56(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L617
	leal	72(%ebx), %esi
	addl	64(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L617
	addl	72(%ebx), %ecx
L617:
	movl	%ecx, 8(%esp)
	movl	(%esp), %eax
	fildl	8(%esp)
	fdivrs	LC8
	.p2align 4,,7
L621:
	fildl	(%eax)
	addl	$8, %eax
	fmul	%st(1), %st
	fstps	-4(%eax)
	cmpl	%eax, %edx
	ja	L621
	fstp	%st(0)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L622:
	.cfi_restore_state
	xorl	%ecx, %ecx
	jmp	L613
	.cfi_endproc
LFE3043:
	.p2align 4,,15
	.globl	__Z22testOpt05_Type1_BeforeiRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_
	.def	__Z22testOpt05_Type1_BeforeiRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_;	.scl	2;	.type	32;	.endef
__Z22testOpt05_Type1_BeforeiRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_:
LFB3047:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$1431655766, %ebp
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$4, %esp
	.cfi_def_cfa_offset 24
	movl	24(%esp), %ecx
	movl	28(%esp), %edi
	movl	32(%esp), %esi
	movl	40(%esp), %ebx
	leal	(%ecx,%ecx), %eax
	movl	%eax, (%edi)
	movl	36(%esp), %edi
	addl	%ecx, %eax
	movl	%eax, (%esi)
	leal	0(,%ecx,4), %edx
	movl	44(%esp), %esi
	sall	$3, %eax
	movl	%edx, (%edi)
	addl	%ecx, %edx
	movl	48(%esp), %edi
	movl	%edx, (%ebx)
	movl	52(%esp), %ebx
	addl	%edx, %edx
	movl	%edx, (%esi)
	movl	%ecx, %edx
	movl	56(%esp), %esi
	sall	$4, %edx
	movl	%edx, (%edi)
	movl	64(%esp), %edi
	movl	%eax, (%ebx)
	movl	%ecx, %eax
	movl	%ecx, %ebx
	shrl	$31, %eax
	addl	%ecx, %eax
	sarl	%eax
	movl	%eax, (%esi)
	movl	%ecx, %eax
	movl	$1717986919, %esi
	imull	%ebp
	movl	60(%esp), %eax
	sarl	$31, %ebx
	movl	%edx, %ebp
	subl	%ebx, %ebp
	testl	%ecx, %ecx
	movl	%ebp, (%eax)
	leal	3(%ecx), %eax
	cmovns	%ecx, %eax
	sarl	$2, %eax
	movl	%eax, (%edi)
	movl	%ecx, %eax
	imull	%esi
	movl	68(%esp), %eax
	movl	%edx, %edi
	movl	%edx, %esi
	sarl	$2, %esi
	sarl	%edi
	subl	%ebx, %edi
	movl	%esi, (%esp)
	subl	%ebx, (%esp)
	testl	%ecx, %ecx
	movl	(%esp), %edx
	movl	%edi, (%eax)
	movl	72(%esp), %eax
	movl	%edx, (%eax)
	movl	76(%esp), %edx
	leal	15(%ecx), %eax
	cmovns	%ecx, %eax
	sarl	$4, %eax
	movl	%eax, (%edx)
	movl	%ecx, %eax
	movl	$715827883, %edx
	imull	%edx
	movl	80(%esp), %eax
	sarl	$2, %edx
	subl	%ebx, %edx
	movl	%edx, (%eax)
	movl	%ebx, %eax
	shrl	$31, %eax
	movl	%eax, %esi
	addl	%ecx, %eax
	andl	$1, %eax
	subl	%esi, %eax
	movl	84(%esp), %esi
	movl	%eax, (%esi)
	movl	88(%esp), %esi
	leal	0(%ebp,%ebp,2), %eax
	movl	%ecx, %ebp
	subl	%eax, %ebp
	movl	%ebp, (%esi)
	movl	%ebx, %ebp
	movl	92(%esp), %esi
	shrl	$30, %ebp
	leal	(%ecx,%ebp), %eax
	andl	$3, %eax
	subl	%ebp, %eax
	movl	%eax, (%esi)
	leal	(%edi,%edi,4), %eax
	movl	%ecx, %edi
	subl	%eax, %edi
	movl	%ecx, %esi
	movl	%edi, %eax
	movl	96(%esp), %edi
	shrl	$28, %ebx
	movl	%eax, (%edi)
	movl	(%esp), %eax
	movl	36(%esp), %edi
	leal	(%eax,%eax,4), %eax
	addl	%eax, %eax
	subl	%eax, %esi
	movl	%esi, %eax
	movl	100(%esp), %esi
	movl	%eax, (%esi)
	leal	(%ecx,%ebx), %eax
	movl	44(%esp), %esi
	andl	$15, %eax
	subl	%ebx, %eax
	movl	104(%esp), %ebx
	movl	%eax, (%ebx)
	leal	(%edx,%edx,2), %eax
	movl	32(%esp), %ebx
	sall	$3, %eax
	movl	76(%esp), %edx
	subl	%eax, %ecx
	movl	108(%esp), %eax
	movl	%ecx, (%eax)
	movl	28(%esp), %eax
	movl	(%eax), %eax
	addl	(%ebx), %eax
	movl	40(%esp), %ebx
	addl	(%edi), %eax
	movl	48(%esp), %edi
	addl	(%ebx), %eax
	movl	52(%esp), %ebx
	addl	(%esi), %eax
	movl	56(%esp), %esi
	addl	(%edi), %eax
	movl	60(%esp), %edi
	addl	(%ebx), %eax
	movl	64(%esp), %ebx
	addl	(%esi), %eax
	movl	68(%esp), %esi
	addl	(%edi), %eax
	movl	72(%esp), %edi
	addl	(%ebx), %eax
	movl	80(%esp), %ebx
	addl	(%esi), %eax
	movl	84(%esp), %esi
	addl	(%edi), %eax
	movl	88(%esp), %edi
	addl	(%edx), %eax
	movl	92(%esp), %edx
	addl	(%ebx), %eax
	movl	96(%esp), %ebx
	addl	(%esi), %eax
	movl	100(%esp), %esi
	addl	(%edi), %eax
	movl	104(%esp), %edi
	addl	(%edx), %eax
	addl	(%ebx), %eax
	addl	(%esi), %eax
	addl	(%edi), %eax
	addl	$4, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	addl	%ecx, %eax
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3047:
	.p2align 4,,15
	.globl	__Z21testOpt05_Type1_AfteriRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_
	.def	__Z21testOpt05_Type1_AfteriRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_;	.scl	2;	.type	32;	.endef
__Z21testOpt05_Type1_AfteriRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_:
LFB3524:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	20(%esp), %ecx
	movl	24(%esp), %edi
	movl	28(%esp), %esi
	movl	36(%esp), %ebx
	leal	(%ecx,%ecx), %eax
	movl	%ecx, %ebp
	movl	%eax, (%edi)
	movl	32(%esp), %edi
	leal	(%ecx,%eax), %edx
	movl	%edx, (%esi)
	movl	40(%esp), %esi
	leal	0(,%ecx,4), %edx
	sarl	$31, %ebp
	movl	%edx, (%edi)
	addl	%ecx, %edx
	movl	44(%esp), %edi
	movl	%edx, (%ebx)
	leal	0(,%ecx,8), %edx
	movl	52(%esp), %ebx
	addl	%edx, %eax
	movl	%eax, (%esi)
	movl	%ecx, %eax
	movl	60(%esp), %esi
	sall	$4, %eax
	movl	%eax, (%edi)
	addl	%eax, %edx
	movl	48(%esp), %eax
	movl	$1431655766, %edi
	movl	%edx, (%eax)
	movl	%ecx, %eax
	sarl	%eax
	movl	%eax, (%ebx)
	movl	%ecx, %eax
	movl	$1717986919, %ebx
	imull	%edi
	movl	56(%esp), %eax
	movl	%edx, %edi
	subl	%ebp, %edi
	movl	%edi, (%eax)
	movl	%ecx, %eax
	sarl	$2, %eax
	movl	%eax, (%esi)
	movl	%ecx, %eax
	imull	%ebx
	movl	64(%esp), %eax
	movl	%edx, %esi
	movl	%edx, %ebx
	movl	72(%esp), %edx
	sarl	%esi
	subl	%ebp, %esi
	movl	%esi, (%eax)
	movl	68(%esp), %eax
	sarl	$2, %ebx
	subl	%ebp, %ebx
	movl	%ebx, (%eax)
	movl	%ecx, %eax
	sarl	$4, %eax
	movl	%eax, (%edx)
	movl	%ecx, %eax
	movl	$715827883, %edx
	imull	%edx
	movl	76(%esp), %eax
	sarl	$2, %edx
	subl	%ebp, %edx
	movl	80(%esp), %ebp
	movl	%edx, (%eax)
	movl	%ecx, %eax
	andl	$1, %eax
	movl	%eax, 0(%ebp)
	leal	(%edi,%edi,2), %eax
	movl	%ecx, %edi
	subl	%eax, %edi
	movl	%edi, %eax
	movl	84(%esp), %edi
	movl	%eax, (%edi)
	movl	88(%esp), %edi
	movl	%ecx, %eax
	andl	$3, %eax
	movl	%eax, (%edi)
	leal	(%esi,%esi,4), %eax
	movl	%ecx, %esi
	subl	%eax, %esi
	movl	32(%esp), %edi
	movl	%esi, %eax
	movl	92(%esp), %esi
	movl	%eax, (%esi)
	leal	(%ebx,%ebx,4), %eax
	movl	%ecx, %ebx
	addl	%eax, %eax
	movl	28(%esp), %esi
	subl	%eax, %ebx
	movl	%ebx, %eax
	movl	96(%esp), %ebx
	movl	%eax, (%ebx)
	movl	100(%esp), %ebx
	movl	%ecx, %eax
	andl	$15, %eax
	movl	%eax, (%ebx)
	leal	(%edx,%edx,2), %eax
	movl	36(%esp), %ebx
	sall	$3, %eax
	movl	72(%esp), %edx
	subl	%eax, %ecx
	movl	104(%esp), %eax
	movl	%ecx, (%eax)
	movl	24(%esp), %eax
	movl	(%eax), %eax
	addl	(%esi), %eax
	movl	40(%esp), %esi
	addl	(%edi), %eax
	movl	44(%esp), %edi
	addl	(%ebx), %eax
	movl	48(%esp), %ebx
	addl	(%esi), %eax
	movl	52(%esp), %esi
	addl	(%edi), %eax
	movl	56(%esp), %edi
	addl	(%ebx), %eax
	movl	60(%esp), %ebx
	addl	(%esi), %eax
	movl	64(%esp), %esi
	addl	(%edi), %eax
	movl	68(%esp), %edi
	addl	(%ebx), %eax
	movl	76(%esp), %ebx
	addl	(%esi), %eax
	addl	(%edi), %eax
	movl	84(%esp), %edi
	movl	96(%esp), %esi
	addl	(%edx), %eax
	movl	88(%esp), %edx
	addl	(%ebx), %eax
	movl	92(%esp), %ebx
	addl	0(%ebp), %eax
	addl	(%edi), %eax
	movl	100(%esp), %edi
	addl	(%edx), %eax
	addl	(%ebx), %eax
	addl	(%esi), %eax
	addl	(%edi), %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	addl	%ecx, %eax
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3524:
	.p2align 4,,15
	.globl	__Z22testOpt06_Type1_BeforeR11dataOpt06_tfff
	.def	__Z22testOpt06_Type1_BeforeR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
__Z22testOpt06_Type1_BeforeR11dataOpt06_tfff:
LFB3526:
	.cfi_startproc
	movl	4(%esp), %eax
	flds	8(%esp)
	flds	12(%esp)
	flds	16(%esp)
	leal	80000(%eax), %edx
	.p2align 4,,7
L633:
	flds	(%eax)
	addl	$8, %eax
	fmul	%st(3), %st
	fmul	%st(2), %st
	fdiv	%st(1), %st
	fstps	-4(%eax)
	cmpl	%eax, %edx
	ja	L633
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	ret
	.cfi_endproc
LFE3526:
	.p2align 4,,15
	.globl	__Z21testOpt06_Type1_AfterR11dataOpt06_tfff
	.def	__Z21testOpt06_Type1_AfterR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
__Z21testOpt06_Type1_AfterR11dataOpt06_tfff:
LFB3527:
	.cfi_startproc
	flds	12(%esp)
	fmuls	8(%esp)
	movl	4(%esp), %eax
	leal	80000(%eax), %edx
	fdivs	16(%esp)
	.p2align 4,,7
L636:
	flds	(%eax)
	addl	$8, %eax
	fmul	%st(1), %st
	fstps	-4(%eax)
	cmpl	%eax, %edx
	ja	L636
	fstp	%st(0)
	ret
	.cfi_endproc
LFE3527:
	.p2align 4,,15
	.globl	__Z12addMatrixOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_S4_
	.def	__Z12addMatrixOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_S4_;	.scl	2;	.type	32;	.endef
__Z12addMatrixOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_S4_:
LFB3533:
	.cfi_startproc
	movl	8(%esp), %ecx
	movl	12(%esp), %edx
	movl	4(%esp), %eax
	movaps	16(%ecx), %xmm2
	movaps	32(%ecx), %xmm1
	movaps	48(%ecx), %xmm0
	movaps	16(%edx), %xmm6
	movaps	32(%edx), %xmm5
	addps	%xmm6, %xmm2
	movaps	48(%edx), %xmm4
	addps	%xmm5, %xmm1
	movaps	(%ecx), %xmm3
	addps	%xmm4, %xmm0
	addps	(%edx), %xmm3
	movaps	%xmm2, 16(%eax)
	movaps	%xmm3, (%eax)
	movaps	%xmm1, 32(%eax)
	movaps	%xmm0, 48(%eax)
	ret
	.cfi_endproc
LFE3533:
	.p2align 4,,15
	.globl	__Z18mulMatrixScalarOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_f
	.def	__Z18mulMatrixScalarOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_f;	.scl	2;	.type	32;	.endef
__Z18mulMatrixScalarOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_f:
LFB3535:
	.cfi_startproc
	movl	8(%esp), %edx
	movss	12(%esp), %xmm0
	movl	4(%esp), %eax
	movaps	16(%edx), %xmm3
	shufps	$0, %xmm0, %xmm0
	movaps	32(%edx), %xmm2
	mulps	%xmm0, %xmm3
	movaps	48(%edx), %xmm1
	mulps	%xmm0, %xmm2
	movaps	(%edx), %xmm4
	mulps	%xmm0, %xmm1
	movaps	%xmm3, 16(%eax)
	mulps	%xmm0, %xmm4
	movaps	%xmm2, 32(%eax)
	movaps	%xmm1, 48(%eax)
	movaps	%xmm4, (%eax)
	ret
	.cfi_endproc
LFE3535:
	.p2align 4,,15
	.globl	__Z12mulMatrixOptILj4ELj4ELj4EEvR6matrixIXT_EXT0_EERKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	.def	__Z12mulMatrixOptILj4ELj4ELj4EEvR6matrixIXT_EXT0_EERKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
__Z12mulMatrixOptILj4ELj4ELj4EEvR6matrixIXT_EXT0_EERKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE:
LFB3537:
	.cfi_startproc
	subl	$44, %esp
	.cfi_def_cfa_offset 48
	movl	52(%esp), %ecx
	movl	56(%esp), %edx
	movl	48(%esp), %eax
	movaps	32(%ecx), %xmm7
	movaps	(%edx), %xmm4
	movaps	%xmm7, (%esp)
	movaps	16(%edx), %xmm7
	movaps	%xmm4, %xmm3
	movaps	48(%ecx), %xmm2
	unpcklps	%xmm7, %xmm3
	unpckhps	%xmm7, %xmm4
	movaps	32(%edx), %xmm6
	movaps	%xmm2, 16(%esp)
	movaps	48(%edx), %xmm1
	movaps	%xmm3, %xmm2
	movaps	%xmm6, %xmm3
	unpcklps	%xmm1, %xmm3
	unpckhps	%xmm1, %xmm6
	movaps	(%ecx), %xmm0
	movaps	%xmm2, %xmm1
	shufps	$238, %xmm3, %xmm2
	movlhps	%xmm3, %xmm1
	movaps	%xmm4, %xmm3
	shufps	$238, %xmm6, %xmm4
	movlhps	%xmm6, %xmm3
	movaps	%xmm0, %xmm6
	movaps	16(%ecx), %xmm5
	dpps	$241, %xmm4, %xmm6
	movaps	%xmm6, %xmm7
	movaps	%xmm0, %xmm6
	dpps	$241, %xmm3, %xmm6
	unpcklps	%xmm7, %xmm6
	movaps	%xmm0, %xmm7
	dpps	$241, %xmm2, %xmm7
	dpps	$241, %xmm1, %xmm0
	unpcklps	%xmm7, %xmm0
	movaps	16(%esp), %xmm7
	movlhps	%xmm6, %xmm0
	movaps	%xmm0, (%eax)
	movaps	%xmm5, %xmm6
	movaps	%xmm5, %xmm0
	dpps	$241, %xmm4, %xmm6
	dpps	$241, %xmm3, %xmm0
	unpcklps	%xmm6, %xmm0
	movaps	%xmm5, %xmm6
	dpps	$241, %xmm2, %xmm6
	dpps	$241, %xmm1, %xmm5
	unpcklps	%xmm6, %xmm5
	movaps	(%esp), %xmm6
	movlhps	%xmm0, %xmm5
	movaps	%xmm5, 16(%eax)
	movaps	%xmm6, %xmm0
	movaps	%xmm6, %xmm5
	dpps	$241, %xmm4, %xmm5
	dpps	$241, %xmm3, %xmm0
	dpps	$241, %xmm7, %xmm4
	dpps	$241, %xmm7, %xmm3
	unpcklps	%xmm5, %xmm0
	movaps	%xmm6, %xmm5
	dpps	$241, %xmm2, %xmm5
	unpcklps	%xmm4, %xmm3
	dpps	$241, %xmm1, %xmm6
	dpps	$241, %xmm7, %xmm2
	dpps	$241, %xmm7, %xmm1
	unpcklps	%xmm5, %xmm6
	movlhps	%xmm0, %xmm6
	movaps	%xmm6, 32(%eax)
	unpcklps	%xmm2, %xmm1
	movlhps	%xmm3, %xmm1
	movaps	%xmm1, 48(%eax)
	addl	$44, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3537:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strlen_BeforeiPKc
	.def	__Z29testOpt07_Type2_strlen_BeforeiPKc;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strlen_BeforeiPKc:
LFB3539:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	%eax, 4(%esp)
	jmp	_strlen
	.cfi_endproc
LFE3539:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	.def	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_:
LFB3540:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	_strcmp
	.cfi_endproc
LFE3540:
	.p2align 4,,15
	.globl	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	.def	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j;	.scl	2;	.type	32;	.endef
__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j:
LFB3541:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	16(%esp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	jmp	_strncmp
	.cfi_endproc
LFE3541:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	.def	__Z29testOpt07_Type2_strchr_BeforeiPKcc;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strchr_BeforeiPKcc:
LFB3542:
	.cfi_startproc
	movl	8(%esp), %eax
	movsbl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	_strchr
	.cfi_endproc
LFE3542:
	.p2align 4,,15
	.globl	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	.def	__Z30testOpt07_Type2_strrchr_BeforeiPKcc;	.scl	2;	.type	32;	.endef
__Z30testOpt07_Type2_strrchr_BeforeiPKcc:
LFB3543:
	.cfi_startproc
	movl	8(%esp), %eax
	movsbl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	_strrchr
	.cfi_endproc
LFE3543:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	.def	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strstr_BeforeiPKcS0_:
LFB3544:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	_strstr
	.cfi_endproc
LFE3544:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc
	.def	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strcpy_BeforeiPcPKc:
LFB3545:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	_strcpy
	.cfi_endproc
LFE3545:
	.p2align 4,,15
	.globl	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	.def	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj;	.scl	2;	.type	32;	.endef
__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj:
LFB3546:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	16(%esp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	jmp	_strncpy
	.cfi_endproc
LFE3546:
	.p2align 4,,15
	.globl	__Z12_strlen_fastPKc
	.def	__Z12_strlen_fastPKc;	.scl	2;	.type	32;	.endef
__Z12_strlen_fastPKc:
LFB3547:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	cmpb	$0, __ZGVZ12_strlen_fastPKcE4null
	movl	32(%esp), %ebx
	je	L663
L651:
	movl	%ebx, %edx
	movdqa	__ZZ12_strlen_fastPKcE4null, %xmm0
	andl	$15, %edx
	jne	L653
	movl	%ebx, %edx
	jmp	L658
	.p2align 4,,7
L656:
	addl	$16, %edx
L658:
	pcmpistri	$10, (%edx), %xmm0
	jne	L656
	subl	%ebx, %edx
	leal	(%edx,%ecx), %eax
L657:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L663:
	.cfi_restore_state
	movl	$__ZGVZ12_strlen_fastPKcE4null, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	je	L651
	movl	$__ZGVZ12_strlen_fastPKcE4null, (%esp)
	pxor	%xmm0, %xmm0
	movdqa	%xmm0, __ZZ12_strlen_fastPKcE4null
	call	___cxa_guard_release
	jmp	L651
	.p2align 4,,7
L653:
	pcmpistri	$10, (%ebx), %xmm0
	movl	%ecx, %eax
	je	L657
	movl	%ebx, %eax
	subl	%edx, %eax
	leal	16(%eax), %edx
	jmp	L658
	.cfi_endproc
LFE3547:
	.p2align 4,,15
	.globl	__Z13_strnlen_fastPKcj
	.def	__Z13_strnlen_fastPKcj;	.scl	2;	.type	32;	.endef
__Z13_strnlen_fastPKcj:
LFB3548:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	cmpb	$0, __ZGVZ13_strnlen_fastPKcjE4null
	movl	48(%esp), %edi
	movl	52(%esp), %esi
	je	L683
L666:
	movl	%edi, %eax
	movl	%edi, %edx
	leal	(%edi,%esi), %ebp
	andl	$15, %eax
	leal	-16(%ebp), %ebx
	jne	L684
L668:
	cmpl	%ebx, %edx
	ja	L671
	movdqa	__ZZ13_strnlen_fastPKcjE4null, %xmm0
	jmp	L673
	.p2align 4,,7
L672:
	addl	$16, %edx
	cmpl	%edx, %ebx
	jb	L671
L673:
	pcmpistri	$10, (%edx), %xmm0
	jne	L672
	subl	%edi, %edx
	leal	(%edx,%ecx), %eax
L670:
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L671:
	.cfi_restore_state
	cmpl	%edx, %ebp
	movl	%esi, %eax
	jbe	L670
	movdqa	__ZZ13_strnlen_fastPKcjE4null, %xmm2
	pcmpistri	$10, (%edx), %xmm2
	jne	L670
	subl	%edi, %edx
	addl	%ecx, %edx
	cmpl	%esi, %edx
	cmovbe	%edx, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L684:
	.cfi_restore_state
	movdqa	__ZZ13_strnlen_fastPKcjE4null, %xmm1
	pcmpistri	$10, (%edi), %xmm1
	jne	L669
	cmpl	%esi, %ecx
	movl	%esi, %eax
	cmovbe	%ecx, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L683:
	.cfi_restore_state
	movl	$__ZGVZ13_strnlen_fastPKcjE4null, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	je	L666
	movl	$__ZGVZ13_strnlen_fastPKcjE4null, (%esp)
	pxor	%xmm0, %xmm0
	movdqa	%xmm0, __ZZ13_strnlen_fastPKcjE4null
	call	___cxa_guard_release
	jmp	L666
	.p2align 4,,7
L669:
	movl	%edi, %ecx
	subl	%eax, %ecx
	leal	16(%ecx), %edx
	jmp	L668
	.cfi_endproc
LFE3548:
	.p2align 4,,15
	.globl	__Z12_strcmp_fastPKcS0_
	.def	__Z12_strcmp_fastPKcS0_;	.scl	2;	.type	32;	.endef
__Z12_strcmp_fastPKcS0_:
LFB3555:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %edx
	xorl	%ebx, %ebx
	movl	12(%esp), %ecx
	andl	$15, %edx
	movl	%ecx, %eax
	setne	%bl
	andl	$15, %eax
	cmpl	$1, %eax
	sbbl	%eax, %eax
	notl	%eax
	andl	$2, %eax
	orl	%ebx, %eax
	movl	__ZL18_strcmp_fast_casex(,%eax,4), %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	*%eax
	.cfi_endproc
LFE3555:
	.p2align 4,,15
	.globl	__Z13_strncmp_fastPKcS0_j
	.def	__Z13_strncmp_fastPKcS0_j;	.scl	2;	.type	32;	.endef
__Z13_strncmp_fastPKcS0_j:
LFB3560:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %edx
	xorl	%ebx, %ebx
	movl	12(%esp), %ecx
	andl	$15, %edx
	movl	%ecx, %eax
	setne	%bl
	andl	$15, %eax
	cmpl	$1, %eax
	sbbl	%eax, %eax
	notl	%eax
	andl	$2, %eax
	orl	%ebx, %eax
	movl	__ZL19_strncmp_fast_casex(,%eax,4), %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	*%eax
	.cfi_endproc
LFE3560:
	.p2align 4,,15
	.globl	__Z12_strchr_fastPKcc
	.def	__Z12_strchr_fastPKcc;	.scl	2;	.type	32;	.endef
__Z12_strchr_fastPKcc:
LFB3561:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pxor	%xmm0, %xmm0
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %eax
	movd	16(%esp), %xmm1
	pshufb	%xmm0, %xmm1
	movl	%eax, %edx
	andl	$15, %edx
	je	L699
	jmp	L706
	.p2align 4,,7
L698:
	testl	%ebx, %ebx
	jne	L697
	addl	$16, %eax
L699:
	movl	$0, %edx
	movdqa	(%eax), %xmm0
	movl	$0, %ebx
	pcmpistri	$10, %xmm0, %xmm1
	setc	%dl
	sete	%bl
	testl	%edx, %edx
	je	L698
	addl	%ecx, %eax
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L697:
	.cfi_restore_state
	xorl	%eax, %eax
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
L706:
	.cfi_restore_state
	movl	$0, %ebx
	movdqu	(%eax), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	movl	%ecx, %esi
	setc	%bl
	movl	$0, %ecx
	sete	%cl
	testl	%ebx, %ebx
	jne	L705
	testl	%ecx, %ecx
	jne	L697
	subl	%edx, %eax
	addl	$16, %eax
	jmp	L699
	.p2align 4,,7
L705:
	addl	%esi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3561:
	.p2align 4,,15
	.globl	__Z13_strrchr_fastPKcc
	.def	__Z13_strrchr_fastPKcc;	.scl	2;	.type	32;	.endef
__Z13_strrchr_fastPKcc:
LFB3562:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pxor	%xmm0, %xmm0
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %edx
	movd	20(%esp), %xmm1
	pshufb	%xmm0, %xmm1
	movl	%edx, %eax
	andl	$15, %eax
	je	L712
	jmp	L721
	.p2align 4,,7
L720:
	addl	$16, %edx
L712:
	movl	$0, %eax
	movdqa	(%edx), %xmm0
	movl	$0, %ebx
	pcmpistri	$74, %xmm0, %xmm1
	setc	%al
	sete	%bl
	addl	%edx, %ecx
	testl	%eax, %eax
	cmovne	%ecx, %esi
	testl	%ebx, %ebx
	je	L720
L710:
	movl	%esi, %eax
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
L721:
	.cfi_restore_state
	movdqu	(%edx), %xmm0
	pcmpistri	$74, %xmm0, %xmm1
	movl	%ecx, %edi
	movl	$0, %ecx
	movl	$0, %ebx
	setc	%cl
	sete	%bl
	addl	%edx, %edi
	testl	%ecx, %ecx
	cmovne	%edi, %esi
	testl	%ebx, %ebx
	jne	L710
	subl	%eax, %edx
	addl	$16, %edx
	jmp	L712
	.cfi_endproc
LFE3562:
	.p2align 4,,15
	.globl	__Z12_strstr_fastPKcS0_
	.def	__Z12_strstr_fastPKcS0_;	.scl	2;	.type	32;	.endef
__Z12_strstr_fastPKcS0_:
LFB3569:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$92, %esp
	.cfi_def_cfa_offset 112
	movl	116(%esp), %ebp
	movl	112(%esp), %edi
	movsbl	0(%ebp), %edx
	testb	%dl, %dl
	je	L723
	movzbl	1(%ebp), %eax
	testb	%al, %al
	movb	%al, 16(%esp)
	jne	L724
	cmpb	$0, (%edi)
	je	L730
	movl	%edi, 112(%esp)
	movl	%edx, 116(%esp)
	addl	$92, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_strchr
L839:
	.cfi_restore_state
	movl	$0, %esi
	movdqu	(%edi), %xmm1
	pcmpistrm	$10, %xmm1, %xmm2
	movl	%esi, %eax
	movdqa	%xmm0, 32(%esp)
	sete	%al
	movl	%eax, %esi
	jnc	L732
	movl	32(%esp), %eax
	testl	%eax, %eax
	je	L732
	movl	%edi, %ecx
	movl	%ebx, %ebp
	jmp	L735
	.p2align 4,,7
L733:
	addl	$1, %ecx
	shrl	%eax
	je	L838
L735:
	testb	$1, %al
	je	L733
	cmpb	(%ecx), %dl
	.p2align 4,,2
	jne	L733
	movzbl	16(%esp), %ebx
	cmpb	1(%ecx), %bl
	jne	L733
	movl	%ecx, %edi
	.p2align 4,,7
L723:
	addl	$92, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	%edi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L724:
	.cfi_restore_state
	cmpb	$0, 2(%ebp)
	jne	L726
	cmpb	$0, (%edi)
	je	L730
	cmpb	$0, 1(%edi)
	je	L730
	movl	%edi, %ebx
	movd	%edx, %xmm2
	pxor	%xmm0, %xmm0
	andl	$15, %ebx
	pshufb	%xmm0, %xmm2
	jne	L839
	movzbl	16(%esp), %esi
	.p2align 4,,7
L741:
	movl	$0, %ebp
	movdqa	(%edi), %xmm1
	pcmpistrm	$10, %xmm1, %xmm2
	movl	%ebp, %eax
	movdqa	%xmm0, 16(%esp)
	sete	%al
	movl	%eax, %ebp
	jnc	L738
	movl	16(%esp), %ecx
	testl	%ecx, %ecx
	je	L738
	movl	%edi, %eax
	jmp	L740
	.p2align 4,,7
L739:
	addl	$1, %eax
	shrl	%ecx
	je	L738
L740:
	testb	$1, %cl
	je	L739
	cmpb	(%eax), %dl
	jne	L739
	movl	%esi, %ebx
	cmpb	1(%eax), %bl
	jne	L739
	movl	%eax, %edi
	.p2align 4,,2
	jmp	L723
	.p2align 4,,7
L730:
	addl	$92, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	xorl	%edi, %edi
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	movl	%edi, %eax
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L726:
	.cfi_restore_state
	movl	%edi, %eax
	movd	%edx, %xmm2
	pxor	%xmm0, %xmm0
	andl	$15, %eax
	pshufb	%xmm0, %xmm2
	movl	%eax, 32(%esp)
	jne	L840
L742:
	movl	%ebp, %eax
	movl	%ebp, 48(%esp)
	movzbl	16(%esp), %ebp
	andl	$15, %eax
	movl	%eax, 32(%esp)
	.p2align 4,,7
L765:
	movl	$0, %ecx
	movdqa	(%edi), %xmm1
	pcmpistrm	$10, %xmm1, %xmm2
	movdqa	%xmm0, 16(%esp)
	sete	%cl
	jnc	L754
	movl	16(%esp), %ebx
	testl	%ebx, %ebx
	je	L754
	movl	32(%esp), %eax
	movl	%edi, %esi
	testl	%eax, %eax
	jne	L764
	jmp	L760
	.p2align 4,,7
L757:
	addl	$1, %esi
	shrl	%ebx
	je	L754
L760:
	testb	$1, %bl
	.p2align 4,,3
	je	L757
	cmpb	(%esi), %dl
	jne	L757
	movl	%ebp, %eax
	cmpb	1(%esi), %al
	jne	L757
	movl	%edx, 72(%esp)
	movl	48(%esp), %edx
	xorl	%eax, %eax
	testl	$15, %esi
	movdqa	%xmm2, 16(%esp)
	setne	%al
	movl	__ZL22_strstr_fast_cmp_casex(,%eax,4), %eax
	movl	%ecx, 76(%esp)
	movl	%edx, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
	movdqa	16(%esp), %xmm2
	movl	72(%esp), %edx
	movl	76(%esp), %ecx
	testl	%eax, %eax
	je	L757
L758:
	xorl	%edi, %edi
	cmpl	$1, %eax
	cmove	%esi, %edi
	jmp	L723
	.p2align 4,,7
L841:
	movl	%ebp, %eax
	cmpb	1(%esi), %al
	jne	L761
	movl	%edx, 72(%esp)
	movl	48(%esp), %edx
	xorl	%eax, %eax
	testl	$15, %esi
	movdqa	%xmm2, 16(%esp)
	setne	%al
	orl	$2, %eax
	movl	%ecx, 76(%esp)
	movl	%edx, 4(%esp)
	movl	%esi, (%esp)
	call	*__ZL22_strstr_fast_cmp_casex(,%eax,4)
	movdqa	16(%esp), %xmm2
	movl	72(%esp), %edx
	movl	76(%esp), %ecx
	testl	%eax, %eax
	jne	L758
	.p2align 4,,7
L761:
	addl	$1, %esi
	shrl	%ebx
	je	L754
L764:
	testb	$1, %bl
	je	L761
	cmpb	(%esi), %dl
	je	L841
	addl	$1, %esi
	shrl	%ebx
	jne	L764
	.p2align 4,,7
L754:
	testl	%ecx, %ecx
	jne	L730
	addl	$16, %edi
	jmp	L765
	.p2align 4,,7
L738:
	testl	%ebp, %ebp
	jne	L730
	addl	$16, %edi
	.p2align 4,,3
	jmp	L741
L840:
	movl	$0, %ecx
	movdqu	(%edi), %xmm1
	pcmpistrm	$10, %xmm1, %xmm2
	movdqa	%xmm0, 48(%esp)
	sete	%cl
	jnc	L743
	movl	48(%esp), %ebx
	testl	%ebx, %ebx
	je	L743
	testl	$15, %ebp
	movl	%edi, %esi
	jne	L753
	jmp	L749
	.p2align 4,,7
L746:
	addl	$1, %esi
	shrl	%ebx
	je	L743
L749:
	testb	$1, %bl
	.p2align 4,,3
	je	L746
	cmpb	(%esi), %dl
	jne	L746
	movzbl	16(%esp), %eax
	cmpb	1(%esi), %al
	jne	L746
	xorl	%eax, %eax
	testl	$15, %esi
	movdqa	%xmm2, 48(%esp)
	setne	%al
	movl	__ZL22_strstr_fast_cmp_casex(,%eax,4), %eax
	movl	%ecx, 76(%esp)
	movl	%edx, 72(%esp)
	movl	%ebp, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
	movdqa	48(%esp), %xmm2
	movl	72(%esp), %edx
	movl	76(%esp), %ecx
	testl	%eax, %eax
	je	L746
	jmp	L758
L843:
	movzbl	16(%esp), %eax
	cmpb	1(%esi), %al
	jne	L750
	xorl	%eax, %eax
	testl	$15, %esi
	movdqa	%xmm2, 48(%esp)
	setne	%al
	orl	$2, %eax
	movl	%ecx, 76(%esp)
	movl	%edx, 72(%esp)
	movl	%ebp, 4(%esp)
	movl	%esi, (%esp)
	call	*__ZL22_strstr_fast_cmp_casex(,%eax,4)
	movdqa	48(%esp), %xmm2
	movl	72(%esp), %edx
	movl	76(%esp), %ecx
	testl	%eax, %eax
	jne	L758
	.p2align 4,,7
L750:
	addl	$1, %esi
	shrl	%ebx
	je	L743
L753:
	testb	$1, %bl
	je	L750
	cmpb	(%esi), %dl
	jne	L750
	.p2align 4,,6
	jmp	L843
L743:
	testl	%ecx, %ecx
	.p2align 4,,7
	jne	L730
	subl	32(%esp), %edi
	addl	$16, %edi
	.p2align 4,,2
	jmp	L742
L838:
	movl	%ebp, %ebx
L732:
	testl	%esi, %esi
	jne	L730
	subl	%ebx, %edi
	movzbl	16(%esp), %esi
	addl	$16, %edi
	jmp	L741
	.cfi_endproc
LFE3569:
	.p2align 4,,15
	.globl	__Z13_strstr0_fastPKcS0_
	.def	__Z13_strstr0_fastPKcS0_;	.scl	2;	.type	32;	.endef
__Z13_strstr0_fastPKcS0_:
LFB3570:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	xorl	%ecx, %ecx
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	movl	36(%esp), %edx
	testb	$15, %bl
	movl	%edx, %eax
	setne	%cl
	andl	$15, %eax
	cmpl	$1, %eax
	sbbl	%eax, %eax
	notl	%eax
	andl	$2, %eax
	orl	%ecx, %eax
	movl	%edx, 4(%esp)
	movl	%ebx, (%esp)
	call	*__ZL22_strstr_fast_cmp_casex(,%eax,4)
	xorl	%edx, %edx
	cmpl	$1, %eax
	cmove	%ebx, %edx
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	movl	%edx, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3570:
	.p2align 4,,15
	.globl	__Z12_strcpy_fastPcPKc
	.def	__Z12_strcpy_fastPcPKc;	.scl	2;	.type	32;	.endef
__Z12_strcpy_fastPcPKc:
LFB3611:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %edx
	xorl	%ebx, %ebx
	movl	12(%esp), %ecx
	andl	$15, %edx
	movl	%ecx, %eax
	setne	%bl
	andl	$15, %eax
	cmpl	$1, %eax
	sbbl	%eax, %eax
	notl	%eax
	andl	$2, %eax
	orl	%ebx, %eax
	movl	__ZL18_strcpy_fast_casex(,%eax,4), %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	*%eax
	.cfi_endproc
LFE3611:
	.p2align 4,,15
	.globl	__Z13_strncpy_fastPcPKcj
	.def	__Z13_strncpy_fastPcPKcj;	.scl	2;	.type	32;	.endef
__Z13_strncpy_fastPcPKcj:
LFB3618:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %edx
	xorl	%ebx, %ebx
	movl	12(%esp), %ecx
	andl	$15, %edx
	movl	%ecx, %eax
	setne	%bl
	andl	$15, %eax
	cmpl	$1, %eax
	sbbl	%eax, %eax
	notl	%eax
	andl	$2, %eax
	orl	%ebx, %eax
	movl	__ZL19_strncpy_fast_casex(,%eax,4), %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	*%eax
	.cfi_endproc
LFE3618:
	.section .rdata,"dr"
LC9:
	.ascii "\0"
LC10:
	.ascii "len(\"%s\")=%d(%d)\12\0"
LC11:
	.ascii "a\0"
LC12:
	.ascii "ab\0"
LC13:
	.ascii "abc\0"
LC14:
	.ascii "abcd\0"
LC15:
	.ascii "abcde\0"
LC16:
	.ascii "a\0b\0"
LC17:
	.ascii "\0a\0"
LC18:
	.ascii "1234567890abcde\0"
LC19:
	.ascii "1234567890abcdef\0"
LC20:
	.ascii "1234567890abcdefg\0"
	.align 4
LC21:
	.ascii "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
	.ascii "\0"
LC22:
	.ascii "nlen(\"%s\", %d)=%d(%d)\12\0"
LC23:
	.ascii "cmp(\"%s\", \"%s\")=%d(%d)\12\0"
LC24:
	.ascii "b\0"
LC25:
	.ascii "aaa\0"
LC26:
	.ascii "aba\0"
LC27:
	.ascii "acb\0"
	.align 4
LC28:
	.ascii "1234567890abcdef1234567890abcdef\0"
	.align 4
LC29:
	.ascii "1234567890abcdef1234567890abcde0\0"
	.align 4
LC30:
	.ascii "1234567890abcdef1234567890abcde\0"
	.align 4
LC31:
	.ascii "1234567890abcdef1234567890abcdef1\0"
	.align 4
LC32:
	.ascii "1234567890abcdef1234567890abcdef0\0"
LC33:
	.ascii "\0b\0"
LC34:
	.ascii "ncmp(\"%s\", \"%s\", %d)=%d(%d)\12\0"
LC35:
	.ascii "aab\0"
	.align 4
LC36:
	.ascii "1234567890abcdef1234567890abcdef12\0"
	.align 4
LC37:
	.ascii "1234567890abcdef1234567890abcdef2\0"
	.align 4
LC38:
	.ascii "0234567890abcdef1234567890abcdef1\0"
	.align 4
LC39:
	.ascii "1034567890abcdef1234567890abcdef1\0"
	.align 4
LC40:
	.ascii "1234567890abcdef0234567890abcdef1\0"
	.align 4
LC41:
	.ascii "1234567890abcdef1034567890abcdef1\0"
LC42:
	.ascii "1\0"
LC43:
	.ascii "chr(\"%s\", '%c')=\"%s\"(\"%s\")\12\0"
LC44:
	.ascii "12\0"
LC45:
	.ascii "123\0"
LC46:
	.ascii "1234\0"
LC47:
	.ascii "12341\0"
LC48:
	.ascii "123412\0"
LC49:
	.ascii "123132\0"
LC50:
	.ascii "123x\0x123\0"
LC51:
	.ascii "1234567890abcdefx\0"
LC52:
	.ascii "1234567890abcdefxy\0"
LC53:
	.ascii "rchr(\"%s\", '%c')=\"%s\"(\"%s\")\12\0"
LC54:
	.ascii "23\0"
LC55:
	.ascii "str(\"%s\", \"%s\")=\"%s\"(\"%s\")\12\0"
LC56:
	.ascii "1234123\0"
LC57:
	.ascii "12x\0"
LC58:
	.ascii "12341234\0"
LC59:
	.ascii "x23\0"
LC60:
	.ascii "12312312313132132123x23123132\0"
LC61:
	.ascii "4\0"
LC62:
	.ascii "x\0"
	.align 4
LC63:
	.ascii "123a123b123c123d123e123f123x123h123i123j\0"
LC64:
	.ascii "123x123\0"
	.align 4
LC65:
	.ascii "a123b1123c2123d3123e1123f2123g3123x123h1123i2123jk\0"
LC66:
	.ascii "x234567890abcdef\0"
	.align 4
LC67:
	.ascii "1234567890abcdef1234567890abcdefx234567890abcdef\0"
LC68:
	.ascii "x234567890abcdefg\0"
	.align 4
LC69:
	.ascii "1234567890abcdef1234567890abcdefx234567890abcdefg\0"
	.align 4
LC70:
	.ascii "1234567890abcdef1234567890abcdefx234567890abcdefgh\0"
LC71:
	.ascii "x234567890abcdefx\0"
	.align 4
LC72:
	.ascii "1234567890abcdef1234567890abcdefx234567890abcdefx\0"
	.align 4
LC73:
	.ascii "1234567890abcdef1234567890abcdefx234567890abcdefxy\0"
LC74:
	.ascii "!!\0"
	.align 4
LC75:
	.ascii "1234567890abcde!!234567890abcdef\0"
	.align 4
LC76:
	.ascii "!1234567890!abcdef!!1234567890!abcdef!\0"
LC77:
	.ascii "1234567890abcdefgh\0"
	.align 4
LC78:
	.ascii "1234567890abcdef1234567890abcdefgh\0"
	.align 4
LC79:
	.ascii "10234567890abcdefgh1234567890abcdefgh\0"
LC80:
	.ascii "abcdefghijklmnopqrstuvwxyz\0"
	.align 4
LC81:
	.ascii "aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzabcdefghijklmnopqrstuvwxyz\0"
	.align 4
LC82:
	.ascii "bbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzabc\0"
	.align 4
LC83:
	.ascii "abcdefghijklmnopqrstuvwxyzaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzabcdefghijklmnopqrstuvwxyz\0"
LC84:
	.ascii "str0(\"%s\", \"%s\")=\"%s\"(\"%s\")\12\0"
LC85:
	.ascii "x12341234\0"
LC86:
	.ascii "x1234567890abcdefgh\0"
	.align 4
LC87:
	.ascii "1234567890abcdefghijklmnopqrstuvwxyz\0"
	.align 4
LC88:
	.ascii "1234567890abcdefghijklmnopqrstuvwxyz!\0"
	.align 4
LC89:
	.ascii "1234567890abcdefghijklmnopqrstuvwxyz!!\0"
	.align 4
LC90:
	.ascii "x1234567890abcdefghijklmnopqrstuvwxyz!!\0"
LC91:
	.ascii "(dummy_for_align=%d)\12\0"
	.align 4
LC92:
	.ascii "_memcpy_m128i_a(buff, str16,  0)=\"%s\"\12\0"
	.align 16
LC93:
	.long	858927408
	.long	926299444
	.long	1650538808
	.long	1717920867
	.align 4
LC94:
	.ascii "_memcpy_m128i_a(buff, str16,  1)=\"%s\"\12\0"
	.align 4
LC95:
	.ascii "_memcpy_m128i_a(buff, str16,  2)=\"%s\"\12\0"
	.align 4
LC96:
	.ascii "_memcpy_m128i_a(buff, str16,  3)=\"%s\"\12\0"
	.align 4
LC97:
	.ascii "_memcpy_m128i_a(buff, str16,  4)=\"%s\"\12\0"
	.align 4
LC98:
	.ascii "_memcpy_m128i_a(buff, str16,  5)=\"%s\"\12\0"
	.align 4
LC99:
	.ascii "_memcpy_m128i_a(buff, str16,  6)=\"%s\"\12\0"
	.align 4
LC100:
	.ascii "_memcpy_m128i_a(buff, str16,  7)=\"%s\"\12\0"
	.align 4
LC101:
	.ascii "_memcpy_m128i_a(buff, str16,  8)=\"%s\"\12\0"
	.align 4
LC102:
	.ascii "_memcpy_m128i_a(buff, str16,  9)=\"%s\"\12\0"
	.align 4
LC103:
	.ascii "_memcpy_m128i_a(buff, str16, 10)=\"%s\"\12\0"
	.align 4
LC104:
	.ascii "_memcpy_m128i_a(buff, str16, 11)=\"%s\"\12\0"
	.align 4
LC105:
	.ascii "_memcpy_m128i_a(buff, str16, 12)=\"%s\"\12\0"
	.align 4
LC106:
	.ascii "_memcpy_m128i_a(buff, str16, 13)=\"%s\"\12\0"
	.align 4
LC107:
	.ascii "_memcpy_m128i_a(buff, str16, 14)=\"%s\"\12\0"
	.align 4
LC108:
	.ascii "_memcpy_m128i_a(buff, str16, 15)=\"%s\"\12\0"
	.align 4
LC110:
	.ascii "_memcpy_m128i_a(buff, str16, 16)=\"%s\"\12\0"
	.align 4
LC111:
	.ascii "_memcpy_m128i_u(buffu, str16,  0)=\"%s\"\12\0"
	.align 4
LC112:
	.ascii "_memcpy_m128i_u(buffu, str16,  1)=\"%s\"\12\0"
	.align 4
LC113:
	.ascii "_memcpy_m128i_u(buffu, str16,  2)=\"%s\"\12\0"
	.align 4
LC114:
	.ascii "_memcpy_m128i_u(buffu, str16,  3)=\"%s\"\12\0"
	.align 4
LC115:
	.ascii "_memcpy_m128i_u(buffu, str16,  4)=\"%s\"\12\0"
	.align 4
LC116:
	.ascii "_memcpy_m128i_u(buffu, str16,  5)=\"%s\"\12\0"
	.align 4
LC117:
	.ascii "_memcpy_m128i_u(buffu, str16,  6)=\"%s\"\12\0"
	.align 4
LC118:
	.ascii "_memcpy_m128i_u(buffu, str16,  7)=\"%s\"\12\0"
	.align 4
LC119:
	.ascii "_memcpy_m128i_u(buffu, str16,  8)=\"%s\"\12\0"
	.align 4
LC120:
	.ascii "_memcpy_m128i_u(buffu, str16,  9)=\"%s\"\12\0"
	.align 4
LC121:
	.ascii "_memcpy_m128i_u(buffu, str16, 10)=\"%s\"\12\0"
	.align 4
LC122:
	.ascii "_memcpy_m128i_u(buffu, str16, 11)=\"%s\"\12\0"
	.align 4
LC123:
	.ascii "_memcpy_m128i_u(buffu, str16, 12)=\"%s\"\12\0"
	.align 4
LC124:
	.ascii "_memcpy_m128i_u(buffu, str16, 13)=\"%s\"\12\0"
	.align 4
LC125:
	.ascii "_memcpy_m128i_u(buffu, str16, 14)=\"%s\"\12\0"
	.align 4
LC126:
	.ascii "_memcpy_m128i_u(buffu, str16, 15)=\"%s\"\12\0"
	.align 4
LC128:
	.ascii "_memcpy_m128i_u(buffu, str16, 16)=\"%s\"\12\0"
	.align 4
LC129:
	.ascii "_memcpy_m128i_00_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC130:
	.ascii "_memcpy_m128i_01_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC131:
	.ascii "_memcpy_m128i_02_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC132:
	.ascii "_memcpy_m128i_03_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC133:
	.ascii "_memcpy_m128i_04_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC134:
	.ascii "_memcpy_m128i_05_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC135:
	.ascii "_memcpy_m128i_06_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC136:
	.ascii "_memcpy_m128i_07_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC137:
	.ascii "_memcpy_m128i_08_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC138:
	.ascii "_memcpy_m128i_09_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC139:
	.ascii "_memcpy_m128i_10_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC140:
	.ascii "_memcpy_m128i_11_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC141:
	.ascii "_memcpy_m128i_12_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC142:
	.ascii "_memcpy_m128i_13_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC143:
	.ascii "_memcpy_m128i_14_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC144:
	.ascii "_memcpy_m128i_15_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC145:
	.ascii "_memcpy_m128i_16_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC146:
	.ascii "_memcpy_m128i_00_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC147:
	.ascii "_memcpy_m128i_01_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC148:
	.ascii "_memcpy_m128i_02_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC149:
	.ascii "_memcpy_m128i_03_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC150:
	.ascii "_memcpy_m128i_04_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC151:
	.ascii "_memcpy_m128i_05_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC152:
	.ascii "_memcpy_m128i_06_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC153:
	.ascii "_memcpy_m128i_07_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC154:
	.ascii "_memcpy_m128i_08_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC155:
	.ascii "_memcpy_m128i_09_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC156:
	.ascii "_memcpy_m128i_10_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC157:
	.ascii "_memcpy_m128i_11_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC158:
	.ascii "_memcpy_m128i_12_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC159:
	.ascii "_memcpy_m128i_13_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC160:
	.ascii "_memcpy_m128i_14_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC161:
	.ascii "_memcpy_m128i_15_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC162:
	.ascii "_memcpy_m128i_16_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC163:
	.ascii "_memcpy_m128i_00_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC164:
	.ascii "_memcpy_m128i_01_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC165:
	.ascii "_memcpy_m128i_02_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC166:
	.ascii "_memcpy_m128i_03_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC167:
	.ascii "_memcpy_m128i_04_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC168:
	.ascii "_memcpy_m128i_05_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC169:
	.ascii "_memcpy_m128i_06_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC170:
	.ascii "_memcpy_m128i_07_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC171:
	.ascii "_memcpy_m128i_08_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC172:
	.ascii "_memcpy_m128i_09_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC173:
	.ascii "_memcpy_m128i_10_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC174:
	.ascii "_memcpy_m128i_11_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC175:
	.ascii "_memcpy_m128i_12_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC176:
	.ascii "_memcpy_m128i_13_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC177:
	.ascii "_memcpy_m128i_14_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC178:
	.ascii "_memcpy_m128i_15_a(buffu, str16)=\"%s\"\12\0"
LC179:
	.ascii "cpy(%p, \"%s\")=\"%s\"\12\0"
LC180:
	.ascii "ncpy(%p, \"%s\", %d)=\"%s\"\12\0"
LC181:
	.ascii "z\0"
LC182:
	.ascii "zy\0"
LC183:
	.ascii "zyx\0"
LC184:
	.ascii "zyxw\0"
LC185:
	.ascii "zyxwv\0"
LC186:
	.ascii "A\0B\0"
LC187:
	.ascii "\0C\0"
	.text
	.p2align 4,,15
	.globl	__Z27testOpt07_Type2_After_1timev
	.def	__Z27testOpt07_Type2_After_1timev;	.scl	2;	.type	32;	.endef
__Z27testOpt07_Type2_After_1timev:
LFB3619:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$188, %esp
	.cfi_def_cfa_offset 208
	movl	$LC9, (%esp)
	leal	96(%esp), %esi
	call	__Z12_strlen_fastPKc
	movl	$0, 12(%esp)
	movl	$LC9, 4(%esp)
	movl	$LC10, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$LC11, (%esp)
	call	__Z12_strlen_fastPKc
	movl	$1, 12(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC10, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$LC12, (%esp)
	call	__Z12_strlen_fastPKc
	movl	$2, 12(%esp)
	movl	$LC12, 4(%esp)
	movl	$LC10, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$LC13, (%esp)
	call	__Z12_strlen_fastPKc
	movl	$3, 12(%esp)
	movl	$LC13, 4(%esp)
	movl	$LC10, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$LC14, (%esp)
	call	__Z12_strlen_fastPKc
	movl	$4, 12(%esp)
	movl	$LC14, 4(%esp)
	movl	$LC10, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$LC15, (%esp)
	call	__Z12_strlen_fastPKc
	movl	$5, 12(%esp)
	movl	$LC15, 4(%esp)
	movl	$LC10, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$LC16, (%esp)
	call	__Z12_strlen_fastPKc
	movl	$1, 12(%esp)
	movl	$LC16, 4(%esp)
	movl	$LC10, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$LC17, (%esp)
	call	__Z12_strlen_fastPKc
	movl	$0, 12(%esp)
	movl	$LC17, 4(%esp)
	movl	$LC10, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$LC18, (%esp)
	call	__Z12_strlen_fastPKc
	movl	$15, 12(%esp)
	movl	$LC18, 4(%esp)
	movl	$LC10, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$LC19, (%esp)
	call	__Z12_strlen_fastPKc
	movl	$16, 12(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC10, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$LC20, (%esp)
	call	__Z12_strlen_fastPKc
	movl	$17, 12(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC10, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$LC21, (%esp)
	call	__Z12_strlen_fastPKc
	movl	$2000, 12(%esp)
	movl	$LC21, 4(%esp)
	movl	$LC10, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$LC9, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$0, 16(%esp)
	movl	$0, 8(%esp)
	movl	$LC9, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$LC11, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$1, 16(%esp)
	movl	$0, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$LC12, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$2, 16(%esp)
	movl	$0, 8(%esp)
	movl	$LC12, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$LC13, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$3, 16(%esp)
	movl	$0, 8(%esp)
	movl	$LC13, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$LC14, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$4, 16(%esp)
	movl	$0, 8(%esp)
	movl	$LC14, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$LC15, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$5, 16(%esp)
	movl	$0, 8(%esp)
	movl	$LC15, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$LC16, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$1, 16(%esp)
	movl	$0, 8(%esp)
	movl	$LC16, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$LC17, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$0, 16(%esp)
	movl	$0, 8(%esp)
	movl	$LC17, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$LC18, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$15, 16(%esp)
	movl	$0, 8(%esp)
	movl	$LC18, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$16, 16(%esp)
	movl	$0, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$LC20, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$17, 16(%esp)
	movl	$0, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$LC21, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$2000, 16(%esp)
	movl	$0, 8(%esp)
	movl	$LC21, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC9, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$0, 16(%esp)
	movl	$1, 8(%esp)
	movl	$LC9, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC11, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$1, 16(%esp)
	movl	$1, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC12, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$2, 16(%esp)
	movl	$1, 8(%esp)
	movl	$LC12, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC13, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$3, 16(%esp)
	movl	$1, 8(%esp)
	movl	$LC13, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC14, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$4, 16(%esp)
	movl	$1, 8(%esp)
	movl	$LC14, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC15, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$5, 16(%esp)
	movl	$1, 8(%esp)
	movl	$LC15, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC16, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$1, 16(%esp)
	movl	$1, 8(%esp)
	movl	$LC16, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC17, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$0, 16(%esp)
	movl	$1, 8(%esp)
	movl	$LC17, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC18, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$15, 16(%esp)
	movl	$1, 8(%esp)
	movl	$LC18, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$16, 16(%esp)
	movl	$1, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC20, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$17, 16(%esp)
	movl	$1, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC21, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$2000, 16(%esp)
	movl	$1, 8(%esp)
	movl	$LC21, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC9, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$0, 16(%esp)
	movl	$2, 8(%esp)
	movl	$LC9, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC11, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$1, 16(%esp)
	movl	$2, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC12, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$2, 16(%esp)
	movl	$2, 8(%esp)
	movl	$LC12, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC13, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$3, 16(%esp)
	movl	$2, 8(%esp)
	movl	$LC13, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC14, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$4, 16(%esp)
	movl	$2, 8(%esp)
	movl	$LC14, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC15, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$5, 16(%esp)
	movl	$2, 8(%esp)
	movl	$LC15, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC16, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$1, 16(%esp)
	movl	$2, 8(%esp)
	movl	$LC16, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC17, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$0, 16(%esp)
	movl	$2, 8(%esp)
	movl	$LC17, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC18, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$15, 16(%esp)
	movl	$2, 8(%esp)
	movl	$LC18, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$16, 16(%esp)
	movl	$2, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC20, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$17, 16(%esp)
	movl	$2, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC21, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$2000, 16(%esp)
	movl	$2, 8(%esp)
	movl	$LC21, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$15, 4(%esp)
	movl	$LC9, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$0, 16(%esp)
	movl	$15, 8(%esp)
	movl	$LC9, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$15, 4(%esp)
	movl	$LC11, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$1, 16(%esp)
	movl	$15, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$15, 4(%esp)
	movl	$LC12, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$2, 16(%esp)
	movl	$15, 8(%esp)
	movl	$LC12, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$15, 4(%esp)
	movl	$LC13, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$3, 16(%esp)
	movl	$15, 8(%esp)
	movl	$LC13, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$15, 4(%esp)
	movl	$LC14, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$4, 16(%esp)
	movl	$15, 8(%esp)
	movl	$LC14, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$15, 4(%esp)
	movl	$LC15, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$5, 16(%esp)
	movl	$15, 8(%esp)
	movl	$LC15, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$15, 4(%esp)
	movl	$LC16, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$1, 16(%esp)
	movl	$15, 8(%esp)
	movl	$LC16, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$15, 4(%esp)
	movl	$LC17, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$0, 16(%esp)
	movl	$15, 8(%esp)
	movl	$LC17, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$15, 4(%esp)
	movl	$LC18, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$15, 16(%esp)
	movl	$15, 8(%esp)
	movl	$LC18, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$15, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$16, 16(%esp)
	movl	$15, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$15, 4(%esp)
	movl	$LC20, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$17, 16(%esp)
	movl	$15, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$15, 4(%esp)
	movl	$LC21, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$2000, 16(%esp)
	movl	$15, 8(%esp)
	movl	$LC21, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$16, 4(%esp)
	movl	$LC9, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$0, 16(%esp)
	movl	$16, 8(%esp)
	movl	$LC9, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$16, 4(%esp)
	movl	$LC11, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$1, 16(%esp)
	movl	$16, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$16, 4(%esp)
	movl	$LC12, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$2, 16(%esp)
	movl	$16, 8(%esp)
	movl	$LC12, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$16, 4(%esp)
	movl	$LC13, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$3, 16(%esp)
	movl	$16, 8(%esp)
	movl	$LC13, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$16, 4(%esp)
	movl	$LC14, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$4, 16(%esp)
	movl	$16, 8(%esp)
	movl	$LC14, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$16, 4(%esp)
	movl	$LC15, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$5, 16(%esp)
	movl	$16, 8(%esp)
	movl	$LC15, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$16, 4(%esp)
	movl	$LC16, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$1, 16(%esp)
	movl	$16, 8(%esp)
	movl	$LC16, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$16, 4(%esp)
	movl	$LC17, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$0, 16(%esp)
	movl	$16, 8(%esp)
	movl	$LC17, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$16, 4(%esp)
	movl	$LC18, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$15, 16(%esp)
	movl	$16, 8(%esp)
	movl	$LC18, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$16, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$16, 16(%esp)
	movl	$16, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$16, 4(%esp)
	movl	$LC20, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$17, 16(%esp)
	movl	$16, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$16, 4(%esp)
	movl	$LC21, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$2000, 16(%esp)
	movl	$16, 8(%esp)
	movl	$LC21, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$17, 4(%esp)
	movl	$LC9, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$0, 16(%esp)
	movl	$17, 8(%esp)
	movl	$LC9, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$17, 4(%esp)
	movl	$LC11, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$1, 16(%esp)
	movl	$17, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$17, 4(%esp)
	movl	$LC12, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$2, 16(%esp)
	movl	$17, 8(%esp)
	movl	$LC12, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$17, 4(%esp)
	movl	$LC13, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$3, 16(%esp)
	movl	$17, 8(%esp)
	movl	$LC13, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$17, 4(%esp)
	movl	$LC14, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$4, 16(%esp)
	movl	$17, 8(%esp)
	movl	$LC14, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$17, 4(%esp)
	movl	$LC15, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$5, 16(%esp)
	movl	$17, 8(%esp)
	movl	$LC15, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$17, 4(%esp)
	movl	$LC16, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$1, 16(%esp)
	movl	$17, 8(%esp)
	movl	$LC16, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$17, 4(%esp)
	movl	$LC17, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$0, 16(%esp)
	movl	$17, 8(%esp)
	movl	$LC17, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$17, 4(%esp)
	movl	$LC18, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$15, 16(%esp)
	movl	$17, 8(%esp)
	movl	$LC18, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$17, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$16, 16(%esp)
	movl	$17, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$17, 4(%esp)
	movl	$LC20, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$17, 16(%esp)
	movl	$17, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$17, 4(%esp)
	movl	$LC21, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$2000, 16(%esp)
	movl	$17, 8(%esp)
	movl	$LC21, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$999, 4(%esp)
	movl	$LC9, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$0, 16(%esp)
	movl	$999, 8(%esp)
	movl	$LC9, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$999, 4(%esp)
	movl	$LC11, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$1, 16(%esp)
	movl	$999, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$999, 4(%esp)
	movl	$LC12, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$2, 16(%esp)
	movl	$999, 8(%esp)
	movl	$LC12, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$999, 4(%esp)
	movl	$LC13, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$3, 16(%esp)
	movl	$999, 8(%esp)
	movl	$LC13, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$999, 4(%esp)
	movl	$LC14, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$4, 16(%esp)
	movl	$999, 8(%esp)
	movl	$LC14, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$999, 4(%esp)
	movl	$LC15, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$5, 16(%esp)
	movl	$999, 8(%esp)
	movl	$LC15, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$999, 4(%esp)
	movl	$LC16, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$1, 16(%esp)
	movl	$999, 8(%esp)
	movl	$LC16, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$999, 4(%esp)
	movl	$LC17, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$0, 16(%esp)
	movl	$999, 8(%esp)
	movl	$LC17, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$999, 4(%esp)
	movl	$LC18, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$15, 16(%esp)
	movl	$999, 8(%esp)
	movl	$LC18, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$999, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$16, 16(%esp)
	movl	$999, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$999, 4(%esp)
	movl	$LC20, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$17, 16(%esp)
	movl	$999, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$999, 4(%esp)
	movl	$LC21, (%esp)
	call	__Z13_strnlen_fastPKcj
	movl	$2000, 16(%esp)
	movl	$999, 8(%esp)
	movl	$LC21, 4(%esp)
	movl	$LC22, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC11, 4(%esp)
	movl	$LC11, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC11, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC24, 4(%esp)
	movl	$LC11, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$-1, 16(%esp)
	movl	$LC24, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC11, 4(%esp)
	movl	$LC24, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$1, 16(%esp)
	movl	$LC11, 8(%esp)
	movl	$LC24, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC25, 4(%esp)
	movl	$LC26, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$1, 16(%esp)
	movl	$LC25, 8(%esp)
	movl	$LC26, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC26, 4(%esp)
	movl	$LC25, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$-1, 16(%esp)
	movl	$LC26, 8(%esp)
	movl	$LC25, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC27, 4(%esp)
	movl	$LC13, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$-1, 16(%esp)
	movl	$LC27, 8(%esp)
	movl	$LC13, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC13, 4(%esp)
	movl	$LC27, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$1, 16(%esp)
	movl	$LC13, 8(%esp)
	movl	$LC27, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC19, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$-1, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC19, 4(%esp)
	movl	$LC20, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$1, 16(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC19, 4(%esp)
	movl	$LC18, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$-1, 16(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC18, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC18, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$1, 16(%esp)
	movl	$LC18, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC28, 4(%esp)
	movl	$LC28, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC28, 8(%esp)
	movl	$LC28, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC28, 4(%esp)
	movl	$LC29, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$-1, 16(%esp)
	movl	$LC28, 8(%esp)
	movl	$LC29, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC29, 4(%esp)
	movl	$LC28, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$1, 16(%esp)
	movl	$LC29, 8(%esp)
	movl	$LC28, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC30, 4(%esp)
	movl	$LC28, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$1, 16(%esp)
	movl	$LC30, 8(%esp)
	movl	$LC28, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC31, 4(%esp)
	movl	$LC28, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$-1, 16(%esp)
	movl	$LC31, 8(%esp)
	movl	$LC28, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC28, 4(%esp)
	movl	$LC30, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$-1, 16(%esp)
	movl	$LC28, 8(%esp)
	movl	$LC30, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC28, 4(%esp)
	movl	$LC31, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$1, 16(%esp)
	movl	$LC28, 8(%esp)
	movl	$LC31, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC31, 4(%esp)
	movl	$LC31, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC31, 8(%esp)
	movl	$LC31, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC31, 4(%esp)
	movl	$LC32, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$-1, 16(%esp)
	movl	$LC31, 8(%esp)
	movl	$LC32, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC32, 4(%esp)
	movl	$LC31, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$1, 16(%esp)
	movl	$LC32, 8(%esp)
	movl	$LC31, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC33, 4(%esp)
	movl	$LC17, (%esp)
	call	__Z12_strcmp_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC33, 8(%esp)
	movl	$LC17, 4(%esp)
	movl	$LC23, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC11, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC11, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC24, 4(%esp)
	movl	$LC11, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$-1, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC24, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC24, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$1, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC11, 8(%esp)
	movl	$LC24, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC25, 4(%esp)
	movl	$LC25, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC25, 8(%esp)
	movl	$LC25, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC25, 4(%esp)
	movl	$LC35, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$1, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC25, 8(%esp)
	movl	$LC35, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC35, 4(%esp)
	movl	$LC25, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$-1, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC35, 8(%esp)
	movl	$LC25, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC25, 4(%esp)
	movl	$LC26, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$1, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC25, 8(%esp)
	movl	$LC26, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC26, 4(%esp)
	movl	$LC25, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$-1, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC26, 8(%esp)
	movl	$LC25, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC27, 4(%esp)
	movl	$LC13, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$-1, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC27, 8(%esp)
	movl	$LC13, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC13, 4(%esp)
	movl	$LC27, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$1, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC13, 8(%esp)
	movl	$LC27, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$2, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC11, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$2, 12(%esp)
	movl	$LC11, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$2, 8(%esp)
	movl	$LC24, 4(%esp)
	movl	$LC11, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$-1, 20(%esp)
	movl	$2, 12(%esp)
	movl	$LC24, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$2, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$LC24, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$1, 20(%esp)
	movl	$2, 12(%esp)
	movl	$LC11, 8(%esp)
	movl	$LC24, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$2, 8(%esp)
	movl	$LC25, 4(%esp)
	movl	$LC25, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$2, 12(%esp)
	movl	$LC25, 8(%esp)
	movl	$LC25, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$2, 8(%esp)
	movl	$LC25, 4(%esp)
	movl	$LC35, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$2, 12(%esp)
	movl	$LC25, 8(%esp)
	movl	$LC35, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$2, 8(%esp)
	movl	$LC35, 4(%esp)
	movl	$LC25, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$2, 12(%esp)
	movl	$LC35, 8(%esp)
	movl	$LC25, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$2, 8(%esp)
	movl	$LC25, 4(%esp)
	movl	$LC26, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$1, 20(%esp)
	movl	$2, 12(%esp)
	movl	$LC25, 8(%esp)
	movl	$LC26, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$2, 8(%esp)
	movl	$LC26, 4(%esp)
	movl	$LC25, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$-1, 20(%esp)
	movl	$2, 12(%esp)
	movl	$LC26, 8(%esp)
	movl	$LC25, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$2, 8(%esp)
	movl	$LC27, 4(%esp)
	movl	$LC13, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$-1, 20(%esp)
	movl	$2, 12(%esp)
	movl	$LC27, 8(%esp)
	movl	$LC13, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$2, 8(%esp)
	movl	$LC13, 4(%esp)
	movl	$LC27, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$1, 20(%esp)
	movl	$2, 12(%esp)
	movl	$LC13, 8(%esp)
	movl	$LC27, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC20, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC18, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$-1, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC18, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC18, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$1, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC18, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$16, 8(%esp)
	movl	$LC33, 4(%esp)
	movl	$LC17, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$16, 12(%esp)
	movl	$LC33, 8(%esp)
	movl	$LC17, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$15, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$15, 12(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$15, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$15, 12(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$15, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC20, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$15, 12(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$15, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC18, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$15, 12(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC18, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$15, 8(%esp)
	movl	$LC18, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$15, 12(%esp)
	movl	$LC18, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$15, 8(%esp)
	movl	$LC33, 4(%esp)
	movl	$LC17, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$15, 12(%esp)
	movl	$LC33, 8(%esp)
	movl	$LC17, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$33, 8(%esp)
	movl	$LC31, 4(%esp)
	movl	$LC31, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$33, 12(%esp)
	movl	$LC31, 8(%esp)
	movl	$LC31, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$33, 8(%esp)
	movl	$LC31, 4(%esp)
	movl	$LC36, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$33, 12(%esp)
	movl	$LC31, 8(%esp)
	movl	$LC36, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$33, 8(%esp)
	movl	$LC36, 4(%esp)
	movl	$LC31, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$0, 20(%esp)
	movl	$33, 12(%esp)
	movl	$LC36, 8(%esp)
	movl	$LC31, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$33, 8(%esp)
	movl	$LC28, 4(%esp)
	movl	$LC31, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$1, 20(%esp)
	movl	$33, 12(%esp)
	movl	$LC28, 8(%esp)
	movl	$LC31, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$33, 8(%esp)
	movl	$LC31, 4(%esp)
	movl	$LC28, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$-1, 20(%esp)
	movl	$33, 12(%esp)
	movl	$LC31, 8(%esp)
	movl	$LC28, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$33, 8(%esp)
	movl	$LC37, 4(%esp)
	movl	$LC31, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$-1, 20(%esp)
	movl	$33, 12(%esp)
	movl	$LC37, 8(%esp)
	movl	$LC31, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$33, 8(%esp)
	movl	$LC31, 4(%esp)
	movl	$LC37, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$1, 20(%esp)
	movl	$33, 12(%esp)
	movl	$LC31, 8(%esp)
	movl	$LC37, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$33, 8(%esp)
	movl	$LC38, 4(%esp)
	movl	$LC39, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$1, 20(%esp)
	movl	$33, 12(%esp)
	movl	$LC38, 8(%esp)
	movl	$LC39, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$33, 8(%esp)
	movl	$LC39, 4(%esp)
	movl	$LC38, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$-1, 20(%esp)
	movl	$33, 12(%esp)
	movl	$LC39, 8(%esp)
	movl	$LC38, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$33, 8(%esp)
	movl	$LC40, 4(%esp)
	movl	$LC41, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$1, 20(%esp)
	movl	$33, 12(%esp)
	movl	$LC40, 8(%esp)
	movl	$LC41, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$33, 8(%esp)
	movl	$LC41, 4(%esp)
	movl	$LC40, (%esp)
	call	__Z13_strncmp_fastPKcS0_j
	movl	$-1, 20(%esp)
	movl	$33, 12(%esp)
	movl	$LC41, 8(%esp)
	movl	$LC40, 4(%esp)
	movl	$LC34, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	$49, 4(%esp)
	movl	$LC42, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$LC42, 16(%esp)
	movl	$49, 8(%esp)
	movl	$LC42, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$49, 4(%esp)
	movl	$LC44, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$LC44, 16(%esp)
	movl	$49, 8(%esp)
	movl	$LC44, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$49, 4(%esp)
	movl	$LC45, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$LC45, 16(%esp)
	movl	$49, 8(%esp)
	movl	$LC45, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$49, 4(%esp)
	movl	$LC46, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$LC46, 16(%esp)
	movl	$49, 8(%esp)
	movl	$LC46, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$49, 4(%esp)
	movl	$LC47, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$LC47, 16(%esp)
	movl	$49, 8(%esp)
	movl	$LC47, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$49, 4(%esp)
	movl	$LC48, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$LC48, 16(%esp)
	movl	$49, 8(%esp)
	movl	$LC48, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$49, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$LC49, 16(%esp)
	movl	$49, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$50, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$LC49+1, 16(%esp)
	movl	$50, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$51, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$LC49+2, 16(%esp)
	movl	$51, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$52, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$0, 16(%esp)
	movl	$52, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$120, 4(%esp)
	movl	$LC50, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$LC50+3, 16(%esp)
	movl	$120, 8(%esp)
	movl	$LC50, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$48, 4(%esp)
	movl	$LC28, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$LC28+9, 16(%esp)
	movl	$48, 8(%esp)
	movl	$LC28, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$102, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$LC19+15, 16(%esp)
	movl	$102, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$120, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$0, 16(%esp)
	movl	$120, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$102, 4(%esp)
	movl	$LC51, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$LC51+15, 16(%esp)
	movl	$102, 8(%esp)
	movl	$LC51, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$120, 4(%esp)
	movl	$LC51, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$LC51+16, 16(%esp)
	movl	$120, 8(%esp)
	movl	$LC51, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$122, 4(%esp)
	movl	$LC51, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$0, 16(%esp)
	movl	$122, 8(%esp)
	movl	$LC51, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$120, 4(%esp)
	movl	$LC52, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$LC52+16, 16(%esp)
	movl	$120, 8(%esp)
	movl	$LC52, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$122, 4(%esp)
	movl	$LC52, (%esp)
	call	__Z12_strchr_fastPKcc
	movl	$0, 16(%esp)
	movl	$122, 8(%esp)
	movl	$LC52, 4(%esp)
	movl	$LC43, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$49, 4(%esp)
	movl	$LC42, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$LC42, 16(%esp)
	movl	$49, 8(%esp)
	movl	$LC42, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$49, 4(%esp)
	movl	$LC44, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$LC44, 16(%esp)
	movl	$49, 8(%esp)
	movl	$LC44, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$49, 4(%esp)
	movl	$LC45, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$LC45, 16(%esp)
	movl	$49, 8(%esp)
	movl	$LC45, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$49, 4(%esp)
	movl	$LC46, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$LC46, 16(%esp)
	movl	$49, 8(%esp)
	movl	$LC46, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$49, 4(%esp)
	movl	$LC47, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$LC47+4, 16(%esp)
	movl	$49, 8(%esp)
	movl	$LC47, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$49, 4(%esp)
	movl	$LC48, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$LC48+4, 16(%esp)
	movl	$49, 8(%esp)
	movl	$LC48, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$49, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$LC49+3, 16(%esp)
	movl	$49, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$50, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$LC49+5, 16(%esp)
	movl	$50, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$51, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$LC49+4, 16(%esp)
	movl	$51, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$52, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$0, 16(%esp)
	movl	$52, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$120, 4(%esp)
	movl	$LC50, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$LC50+3, 16(%esp)
	movl	$120, 8(%esp)
	movl	$LC50, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$48, 4(%esp)
	movl	$LC28, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$LC28+25, 16(%esp)
	movl	$48, 8(%esp)
	movl	$LC28, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$102, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$LC19+15, 16(%esp)
	movl	$102, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$120, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$0, 16(%esp)
	movl	$120, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$102, 4(%esp)
	movl	$LC51, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$LC51+15, 16(%esp)
	movl	$102, 8(%esp)
	movl	$LC51, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$120, 4(%esp)
	movl	$LC51, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$LC51+16, 16(%esp)
	movl	$120, 8(%esp)
	movl	$LC51, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$122, 4(%esp)
	movl	$LC51, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$0, 16(%esp)
	movl	$122, 8(%esp)
	movl	$LC51, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$120, 4(%esp)
	movl	$LC52, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$LC52+16, 16(%esp)
	movl	$120, 8(%esp)
	movl	$LC52, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$122, 4(%esp)
	movl	$LC52, (%esp)
	call	__Z13_strrchr_fastPKcc
	movl	$0, 16(%esp)
	movl	$122, 8(%esp)
	movl	$LC52, 4(%esp)
	movl	$LC53, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC54, 4(%esp)
	movl	$LC42, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC54, 8(%esp)
	movl	$LC42, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC54, 4(%esp)
	movl	$LC44, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC54, 8(%esp)
	movl	$LC44, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC54, 4(%esp)
	movl	$LC45, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC45+1, 16(%esp)
	movl	$LC54, 8(%esp)
	movl	$LC45, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC54, 4(%esp)
	movl	$LC46, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC46+1, 16(%esp)
	movl	$LC54, 8(%esp)
	movl	$LC46, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC54, 4(%esp)
	movl	$LC47, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC47+1, 16(%esp)
	movl	$LC54, 8(%esp)
	movl	$LC47, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC54, 4(%esp)
	movl	$LC48, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC48+1, 16(%esp)
	movl	$LC54, 8(%esp)
	movl	$LC48, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC54, 4(%esp)
	movl	$LC56, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC56+1, 16(%esp)
	movl	$LC54, 8(%esp)
	movl	$LC56, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC57, 4(%esp)
	movl	$LC58, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC57, 8(%esp)
	movl	$LC58, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC59, 4(%esp)
	movl	$LC58, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC59, 8(%esp)
	movl	$LC58, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC57, 4(%esp)
	movl	$LC60, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC57, 8(%esp)
	movl	$LC60, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC59, 4(%esp)
	movl	$LC60, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC60+20, 16(%esp)
	movl	$LC59, 8(%esp)
	movl	$LC60, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC61, 4(%esp)
	movl	$LC58, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC58+3, 16(%esp)
	movl	$LC61, 8(%esp)
	movl	$LC58, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC9, 4(%esp)
	movl	$LC58, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC58, 16(%esp)
	movl	$LC9, 8(%esp)
	movl	$LC58, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC62, 4(%esp)
	movl	$LC63, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC63+27, 16(%esp)
	movl	$LC62, 8(%esp)
	movl	$LC63, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC9, 4(%esp)
	movl	$LC63, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC63, 16(%esp)
	movl	$LC9, 8(%esp)
	movl	$LC63, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC64, 4(%esp)
	movl	$LC65, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC65+31, 16(%esp)
	movl	$LC64, 8(%esp)
	movl	$LC65, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC66, 4(%esp)
	movl	$LC67, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC67+32, 16(%esp)
	movl	$LC66, 8(%esp)
	movl	$LC67, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC68, 4(%esp)
	movl	$LC67, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC68, 8(%esp)
	movl	$LC67, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC68, 4(%esp)
	movl	$LC69, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC69+32, 16(%esp)
	movl	$LC68, 8(%esp)
	movl	$LC69, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC68, 4(%esp)
	movl	$LC70, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC70+32, 16(%esp)
	movl	$LC68, 8(%esp)
	movl	$LC70, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC71, 4(%esp)
	movl	$LC69, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC71, 8(%esp)
	movl	$LC69, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC71, 4(%esp)
	movl	$LC72, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC72+32, 16(%esp)
	movl	$LC71, 8(%esp)
	movl	$LC72, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC71, 4(%esp)
	movl	$LC73, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC73+32, 16(%esp)
	movl	$LC71, 8(%esp)
	movl	$LC73, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC74, 4(%esp)
	movl	$LC75, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC75+15, 16(%esp)
	movl	$LC74, 8(%esp)
	movl	$LC75, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC74, 4(%esp)
	movl	$LC76, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC76+18, 16(%esp)
	movl	$LC74, 8(%esp)
	movl	$LC76, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC19, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC19, 16(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC77, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC77, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC77, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC78, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC78+16, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC78, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC79, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC79+19, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC79, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC80, 4(%esp)
	movl	$LC81, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC81+100, 16(%esp)
	movl	$LC80, 8(%esp)
	movl	$LC81, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC82, 4(%esp)
	movl	$LC83, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC83+30, 16(%esp)
	movl	$LC82, 8(%esp)
	movl	$LC83, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC42, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC42, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC44, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC44, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC45, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC45, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC45, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC46, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC46, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC46, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC47, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC47, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC47, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC48, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC48, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC48, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC56, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC56, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC56, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC58, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC58, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC58, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC85, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC85+1, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC85, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC19, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC19, 16(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC19, 4(%esp)
	movl	$LC20, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC20, 16(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC20, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC20, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC77, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC77, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC77, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC86, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC86+1, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC86, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC87, 4(%esp)
	movl	$LC87, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC87, 16(%esp)
	movl	$LC87, 8(%esp)
	movl	$LC87, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC87, 4(%esp)
	movl	$LC88, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC88, 16(%esp)
	movl	$LC87, 8(%esp)
	movl	$LC88, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC88, 4(%esp)
	movl	$LC87, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC88, 8(%esp)
	movl	$LC87, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC88, 4(%esp)
	movl	$LC88, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC88, 16(%esp)
	movl	$LC88, 8(%esp)
	movl	$LC88, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC88, 4(%esp)
	movl	$LC89, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC89, 16(%esp)
	movl	$LC88, 8(%esp)
	movl	$LC89, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC88, 4(%esp)
	movl	$LC90, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC90+1, 16(%esp)
	movl	$LC88, 8(%esp)
	movl	$LC90, 4(%esp)
	movl	$LC84, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$123, 4(%esp)
	movl	$LC91, (%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC92, (%esp)
	movl	$0, 96(%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movzbl	LC93, %ecx
	movl	%esi, 4(%esp)
	movl	$LC94, (%esp)
	movl	$0, 96(%esp)
	movl	%ecx, 92(%esp)
	movb	%cl, 96(%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movzwl	LC93, %eax
	movl	%esi, 4(%esp)
	movl	$LC95, (%esp)
	movl	$0, 96(%esp)
	movl	%eax, %edi
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movw	%ax, 96(%esp)
	call	_printf
	movzbl	LC93+2, %edx
	movl	%esi, 4(%esp)
	movl	$LC96, (%esp)
	movl	$0, 96(%esp)
	movl	%edx, 88(%esp)
	movb	%dl, 98(%esp)
	movw	%di, 60(%esp)
	movw	%di, 96(%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	LC93, %eax
	movl	%esi, 4(%esp)
	movl	$LC97, (%esp)
	movl	$0, 100(%esp)
	movl	%eax, %edi
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	%eax, 96(%esp)
	call	_printf
	movzbl	LC93+4, %eax
	movl	%esi, 4(%esp)
	movl	$LC98, (%esp)
	movl	$0, 100(%esp)
	movl	%edi, 96(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movb	%al, 82(%esp)
	movb	%al, 100(%esp)
	call	_printf
	movzwl	LC93+4, %edx
	movl	%esi, 4(%esp)
	movl	$LC99, (%esp)
	movl	$0, 100(%esp)
	movl	%edx, %ebx
	movl	%edi, 96(%esp)
	movw	%dx, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movzbl	LC93+6, %edx
	movl	%esi, 4(%esp)
	movl	$LC100, (%esp)
	movl	$0, 100(%esp)
	movb	%dl, 83(%esp)
	movb	%dl, 102(%esp)
	movl	%edi, 52(%esp)
	movl	%edi, 96(%esp)
	movw	%bx, 62(%esp)
	movw	%bx, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC101, (%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	call	_printf
	movl	LC93, %edi
	movl	LC93+4, %ebp
	movzbl	LC93+8, %ecx
	movl	%esi, 4(%esp)
	movl	$LC102, (%esp)
	movl	$0, 104(%esp)
	movb	%cl, 84(%esp)
	movb	%cl, 104(%esp)
	movl	%edi, 96(%esp)
	movl	%ebp, 100(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movzwl	LC93+8, %ebx
	movl	%esi, 4(%esp)
	movl	$LC103, (%esp)
	movl	$0, 104(%esp)
	movl	%edi, 96(%esp)
	movl	%ebp, 100(%esp)
	movw	%bx, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	$0, 104(%esp)
	movw	%bx, 80(%esp)
	movw	%bx, 104(%esp)
	movzbl	LC93+10, %ebx
	movl	%esi, 4(%esp)
	movl	$LC104, (%esp)
	movl	%edi, 96(%esp)
	movl	%ebp, 100(%esp)
	movb	%bl, 85(%esp)
	movb	%bl, 106(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	LC93+8, %ebx
	movl	%esi, 4(%esp)
	movl	$LC105, (%esp)
	movl	%edi, 96(%esp)
	movl	%ebp, 100(%esp)
	movl	%ebx, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	%ebx, 32(%esp)
	movl	%ebx, 104(%esp)
	movzbl	LC93+12, %ebx
	movl	%esi, 4(%esp)
	movl	$LC106, (%esp)
	movl	$0, 108(%esp)
	movl	%edi, 96(%esp)
	movl	%ebp, 100(%esp)
	movb	%bl, 86(%esp)
	movb	%bl, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	32(%esp), %ebx
	movzwl	LC93+12, %edx
	movl	%esi, 4(%esp)
	movl	$LC107, (%esp)
	movl	$0, 108(%esp)
	movl	%edi, 96(%esp)
	movl	%ebp, 100(%esp)
	movl	%ebx, 104(%esp)
	movw	%dx, 58(%esp)
	movw	%dx, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movzwl	58(%esp), %edx
	movl	$0, 108(%esp)
	movl	%esi, 4(%esp)
	movl	$LC108, (%esp)
	movw	%dx, 108(%esp)
	movzbl	LC93+14, %edx
	movl	%edi, 96(%esp)
	movl	%ebp, 100(%esp)
	movl	%ebx, 32(%esp)
	movb	%dl, 87(%esp)
	movb	%dl, 110(%esp)
	movl	%ebx, 104(%esp)
	leal	142(%esp), %ebx
	movl	$0, 112(%esp)
	call	_printf
	movdqa	LC109, %xmm1
	movdqa	%xmm1, 96(%esp)
	movl	%esi, 4(%esp)
	movdqa	%xmm1, 64(%esp)
	movl	$LC110, (%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC111, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	call	_printf
	movl	92(%esp), %ecx
	movl	%ebx, 4(%esp)
	movl	$LC112, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movb	%cl, 142(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	call	_printf
	movzwl	60(%esp), %eax
	movl	%ebx, 4(%esp)
	movl	$LC113, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movw	%ax, 142(%esp)
	call	_printf
	movl	88(%esp), %edx
	movzwl	60(%esp), %eax
	movl	%ebx, 4(%esp)
	movl	$LC114, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movb	%dl, 144(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movw	%ax, 142(%esp)
	call	_printf
	movl	52(%esp), %ecx
	movl	%ebx, 4(%esp)
	movl	$LC115, (%esp)
	movl	$0, 146(%esp)
	movl	%ecx, 142(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	call	_printf
	movl	52(%esp), %ecx
	movzbl	82(%esp), %eax
	movl	%ebx, 4(%esp)
	movl	$LC116, (%esp)
	movl	%ecx, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	%al, 146(%esp)
	call	_printf
	movl	52(%esp), %eax
	movl	%ebx, 4(%esp)
	movl	$LC117, (%esp)
	movl	$0, 146(%esp)
	movl	%eax, 142(%esp)
	movzwl	62(%esp), %eax
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movw	%ax, 146(%esp)
	call	_printf
	movl	52(%esp), %eax
	movzbl	83(%esp), %edx
	movl	%ebx, 4(%esp)
	movl	$LC118, (%esp)
	movl	%eax, 142(%esp)
	movzwl	62(%esp), %eax
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movb	%dl, 148(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movw	%ax, 146(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC119, (%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	call	_printf
	movzbl	84(%esp), %ecx
	movl	%ebx, 4(%esp)
	movl	$LC120, (%esp)
	movl	$0, 150(%esp)
	movl	%edi, 142(%esp)
	movl	%ebp, 146(%esp)
	movb	%cl, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	call	_printf
	movzwl	80(%esp), %ecx
	movl	%ebx, 4(%esp)
	movl	$LC121, (%esp)
	movl	$0, 150(%esp)
	movl	%edi, 142(%esp)
	movl	%ebp, 146(%esp)
	movw	%cx, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	call	_printf
	movzwl	80(%esp), %ecx
	movzbl	85(%esp), %eax
	movl	%ebx, 4(%esp)
	movl	$LC122, (%esp)
	movl	$0, 150(%esp)
	movl	%edi, 142(%esp)
	movl	%ebp, 146(%esp)
	movw	%cx, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	%al, 152(%esp)
	call	_printf
	movl	32(%esp), %ecx
	movl	%ebx, 4(%esp)
	movl	$LC123, (%esp)
	movl	%edi, 142(%esp)
	movl	%ebp, 146(%esp)
	movl	%ecx, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	call	_printf
	movl	32(%esp), %ecx
	movzbl	86(%esp), %eax
	movl	%ebx, 4(%esp)
	movl	$LC124, (%esp)
	movl	$0, 154(%esp)
	movl	%edi, 142(%esp)
	movl	%ebp, 146(%esp)
	movl	%ecx, 150(%esp)
	movl	$0, 158(%esp)
	movb	%al, 154(%esp)
	call	_printf
	movl	32(%esp), %ecx
	movzwl	58(%esp), %eax
	movl	%ebx, 4(%esp)
	movl	$LC125, (%esp)
	movl	$0, 154(%esp)
	movl	%edi, 142(%esp)
	movl	%ebp, 146(%esp)
	movl	%ecx, 150(%esp)
	movl	$0, 158(%esp)
	movw	%ax, 154(%esp)
	call	_printf
	movl	32(%esp), %ecx
	movzbl	87(%esp), %edx
	movzwl	58(%esp), %eax
	movl	%ebx, 4(%esp)
	movl	$LC126, (%esp)
	movl	%ecx, 150(%esp)
	movl	$0, 154(%esp)
	movl	%edi, 142(%esp)
	movl	$13620, %edi
	movb	%dl, 156(%esp)
	movl	%ebp, 146(%esp)
	movl	$13620, %ebp
	movl	$0, 158(%esp)
	movw	%ax, 154(%esp)
	call	_printf
	movdqa	LC127, %xmm0
	movdqu	%xmm0, 142(%esp)
	movl	%ebx, 4(%esp)
	movdqa	%xmm0, 32(%esp)
	movl	$LC128, (%esp)
	movl	$0, 158(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC129, (%esp)
	movl	$0, 96(%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC130, (%esp)
	movl	$0, 96(%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movb	$48, 96(%esp)
	call	_printf
	movl	$12592, %edx
	movl	%esi, 4(%esp)
	movl	$LC131, (%esp)
	movl	$0, 96(%esp)
	movl	$0, 100(%esp)
	movw	%dx, 96(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	$12592, %ecx
	movl	%esi, 4(%esp)
	movl	$LC132, (%esp)
	movl	$0, 96(%esp)
	movl	$0, 100(%esp)
	movw	%cx, 96(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movb	$50, 98(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC133, (%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC134, (%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movb	$52, 100(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC135, (%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movw	%di, 100(%esp)
	movl	$14648, %edi
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC136, (%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movw	%bp, 100(%esp)
	movl	$14648, %ebp
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movb	$54, 102(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC137, (%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC138, (%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	movb	$56, 104(%esp)
	call	_printf
	movl	$14648, %eax
	movl	%esi, 4(%esp)
	movl	$LC139, (%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	movw	%ax, 104(%esp)
	call	_printf
	movl	$14648, %eax
	movl	%esi, 4(%esp)
	movl	$LC140, (%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	movw	%ax, 104(%esp)
	movb	$97, 106(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC141, (%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	movl	$1650538808, 104(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC142, (%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	movl	$1650538808, 104(%esp)
	movb	$99, 108(%esp)
	call	_printf
	movl	$25699, %eax
	movl	%esi, 4(%esp)
	movl	$LC143, (%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	movl	$1650538808, 104(%esp)
	movw	%ax, 108(%esp)
	call	_printf
	movl	$25699, %eax
	movl	%esi, 4(%esp)
	movl	$LC144, (%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	movl	$1650538808, 104(%esp)
	movw	%ax, 108(%esp)
	movb	$101, 110(%esp)
	call	_printf
	movdqa	64(%esp), %xmm1
	movdqa	%xmm1, 96(%esp)
	movl	%esi, 4(%esp)
	movl	$LC145, (%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC146, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC147, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC148, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	movb	$49, 143(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC149, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	movb	$49, 143(%esp)
	movb	$50, 144(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC150, (%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	movb	$49, 143(%esp)
	movb	$50, 144(%esp)
	movb	$51, 145(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC151, (%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	movb	$49, 143(%esp)
	movb	$50, 144(%esp)
	movb	$51, 145(%esp)
	movb	$52, 146(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC152, (%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	movb	$49, 143(%esp)
	movb	$50, 144(%esp)
	movb	$51, 145(%esp)
	movb	$52, 146(%esp)
	movb	$53, 147(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC153, (%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	movb	$49, 143(%esp)
	movb	$50, 144(%esp)
	movb	$51, 145(%esp)
	movb	$52, 146(%esp)
	movb	$53, 147(%esp)
	movb	$54, 148(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC154, (%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	movb	$49, 143(%esp)
	movb	$50, 144(%esp)
	movb	$51, 145(%esp)
	movb	$52, 146(%esp)
	movb	$53, 147(%esp)
	movb	$54, 148(%esp)
	movb	$55, 149(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC155, (%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	movb	$49, 143(%esp)
	movb	$50, 144(%esp)
	movb	$51, 145(%esp)
	movb	$52, 146(%esp)
	movb	$53, 147(%esp)
	movb	$54, 148(%esp)
	movb	$55, 149(%esp)
	movb	$56, 150(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC156, (%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	movb	$49, 143(%esp)
	movb	$50, 144(%esp)
	movb	$51, 145(%esp)
	movb	$52, 146(%esp)
	movb	$53, 147(%esp)
	movb	$54, 148(%esp)
	movb	$55, 149(%esp)
	movb	$56, 150(%esp)
	movb	$57, 151(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC157, (%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	movb	$49, 143(%esp)
	movb	$50, 144(%esp)
	movb	$51, 145(%esp)
	movb	$52, 146(%esp)
	movb	$53, 147(%esp)
	movb	$54, 148(%esp)
	movb	$55, 149(%esp)
	movb	$56, 150(%esp)
	movb	$57, 151(%esp)
	movb	$97, 152(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC158, (%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	movb	$49, 143(%esp)
	movb	$50, 144(%esp)
	movb	$51, 145(%esp)
	movb	$52, 146(%esp)
	movb	$53, 147(%esp)
	movb	$54, 148(%esp)
	movb	$55, 149(%esp)
	movb	$56, 150(%esp)
	movb	$57, 151(%esp)
	movb	$97, 152(%esp)
	movb	$98, 153(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC159, (%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	movb	$49, 143(%esp)
	movb	$50, 144(%esp)
	movb	$51, 145(%esp)
	movb	$52, 146(%esp)
	movb	$53, 147(%esp)
	movb	$54, 148(%esp)
	movb	$55, 149(%esp)
	movb	$56, 150(%esp)
	movb	$57, 151(%esp)
	movb	$97, 152(%esp)
	movb	$98, 153(%esp)
	movb	$99, 154(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC160, (%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	movb	$49, 143(%esp)
	movb	$50, 144(%esp)
	movb	$51, 145(%esp)
	movb	$52, 146(%esp)
	movb	$53, 147(%esp)
	movb	$54, 148(%esp)
	movb	$55, 149(%esp)
	movb	$56, 150(%esp)
	movb	$57, 151(%esp)
	movb	$97, 152(%esp)
	movb	$98, 153(%esp)
	movb	$99, 154(%esp)
	movb	$100, 155(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC161, (%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	movb	$49, 143(%esp)
	movb	$50, 144(%esp)
	movb	$51, 145(%esp)
	movb	$52, 146(%esp)
	movb	$53, 147(%esp)
	movb	$54, 148(%esp)
	movb	$55, 149(%esp)
	movb	$56, 150(%esp)
	movb	$57, 151(%esp)
	movb	$97, 152(%esp)
	movb	$98, 153(%esp)
	movb	$99, 154(%esp)
	movb	$100, 155(%esp)
	movb	$101, 156(%esp)
	call	_printf
	movdqa	32(%esp), %xmm0
	movdqu	%xmm0, 142(%esp)
	movl	%ebx, 4(%esp)
	movl	$LC162, (%esp)
	movl	$0, 158(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC163, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC164, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	call	_printf
	movl	$12592, %eax
	movl	%ebx, 4(%esp)
	movl	$LC165, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movw	%ax, 142(%esp)
	call	_printf
	movl	$12592, %eax
	movl	%ebx, 4(%esp)
	movl	$LC166, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movw	%ax, 142(%esp)
	movb	$50, 144(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC167, (%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC168, (%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movb	$52, 146(%esp)
	call	_printf
	movl	$13620, %edx
	movl	%ebx, 4(%esp)
	movl	$LC169, (%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movw	%dx, 146(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	call	_printf
	movl	$13620, %ecx
	movl	%ebx, 4(%esp)
	movl	$LC170, (%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movw	%cx, 146(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movb	$54, 148(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC171, (%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC172, (%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	movb	$56, 150(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC173, (%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	movw	%di, 150(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC174, (%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	movw	%bp, 150(%esp)
	movb	$97, 152(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC175, (%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	movl	$1650538808, 150(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC176, (%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	movl	$1650538808, 150(%esp)
	movb	$99, 154(%esp)
	call	_printf
	movl	$25699, %eax
	movl	%ebx, 4(%esp)
	movl	$LC177, (%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	movl	$1650538808, 150(%esp)
	movw	%ax, 154(%esp)
	call	_printf
	movl	$25699, %eax
	movl	%ebx, 4(%esp)
	movl	$LC178, (%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	movl	$1650538808, 150(%esp)
	movw	%ax, 154(%esp)
	movb	$101, 156(%esp)
	call	_printf
	xorl	%eax, %eax
L859:
	movl	$0, (%esi,%eax)
	addl	$4, %eax
	cmpl	$32, %eax
	jb	L859
	testb	$2, %bl
	movl	%ebx, %edx
	movl	$32, %ecx
	jne	L890
L861:
	movl	%ecx, %edi
	xorl	%eax, %eax
	andl	$-4, %edi
L862:
	movl	$0, (%edx,%eax)
	addl	$4, %eax
	cmpl	%edi, %eax
	jb	L862
	addl	%eax, %edx
	andl	$2, %ecx
	je	L865
	xorl	%eax, %eax
	movw	%ax, (%edx)
L865:
	movl	$123, 4(%esp)
	movl	%esi, %edi
	movl	$LC91, (%esp)
	call	_printf
	movl	$LC9, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC9, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC11, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC11, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC12, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC12, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC13, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC13, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC14, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC14, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC15, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC15, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC16, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC16, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC17, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC17, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC18, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC18, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC19, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC19, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC20, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC30, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC30, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC18, 4(%esp)
	movl	%ebx, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC18, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC19, 4(%esp)
	movl	%ebx, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC19, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	%ebx, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC20, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC30, 4(%esp)
	movl	%ebx, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC30, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$LC179, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	xorl	%eax, %eax
	movl	$8, %ecx
	rep stosl
	xorl	%eax, %eax
	testb	$2, %bl
	movl	$34, %edx
	movw	%ax, (%edi)
	movl	%ebx, %edi
	jne	L891
L866:
	movl	%edx, %ecx
	xorl	%eax, %eax
	shrl	$2, %ecx
	andl	$2, %edx
	rep stosl
	je	L868
	xorl	%eax, %eax
	movw	%ax, (%edi)
L868:
	movl	$123, 4(%esp)
	movl	$LC91, (%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC9, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC9, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC11, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC11, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC12, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC12, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC13, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC13, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC14, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC14, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC15, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC15, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC16, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC16, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC17, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC17, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC9, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC9, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC181, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC181, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC182, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC182, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC183, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC183, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC184, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC184, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC185, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC185, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC186, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC186, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC187, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC187, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC18, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC18, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC19, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC20, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC30, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC30, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$16, 8(%esp)
	movl	$LC18, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC18, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$16, 8(%esp)
	movl	$LC19, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$16, 8(%esp)
	movl	$LC20, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$16, 8(%esp)
	movl	$LC30, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC30, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$33, 8(%esp)
	movl	$LC28, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$33, 12(%esp)
	movl	$LC28, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$33, 8(%esp)
	movl	$LC31, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$33, 12(%esp)
	movl	$LC31, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$33, 8(%esp)
	movl	$LC36, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$33, 12(%esp)
	movl	$LC36, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$1, 8(%esp)
	movl	$LC13, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$1, 12(%esp)
	movl	$LC13, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$33, 8(%esp)
	movl	$LC28, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$33, 12(%esp)
	movl	$LC28, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$33, 8(%esp)
	movl	$LC31, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$33, 12(%esp)
	movl	$LC31, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$33, 8(%esp)
	movl	$LC36, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$33, 12(%esp)
	movl	$LC36, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$1, 8(%esp)
	movl	$LC13, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$1, 12(%esp)
	movl	$LC13, 8(%esp)
	movl	$LC180, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	addl	$188, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L890:
	.cfi_restore_state
	xorl	%eax, %eax
	movb	$30, %cl
	movw	%ax, 142(%esp)
	leal	144(%esp), %edx
	jmp	L861
L891:
	xorl	%eax, %eax
	movb	$32, %dl
	movw	%ax, 142(%esp)
	leal	144(%esp), %edi
	jmp	L866
	.cfi_endproc
LFE3619:
	.p2align 4,,15
	.globl	__Z28testOpt07_Type2_strlen_AfteriPKc
	.def	__Z28testOpt07_Type2_strlen_AfteriPKc;	.scl	2;	.type	32;	.endef
__Z28testOpt07_Type2_strlen_AfteriPKc:
LFB3620:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	%eax, 4(%esp)
	jmp	__Z12_strlen_fastPKc
	.cfi_endproc
LFE3620:
	.p2align 4,,15
	.globl	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	.def	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_;	.scl	2;	.type	32;	.endef
__Z28testOpt07_Type2_strcmp_AfteriPKcS0_:
LFB3621:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	__Z12_strcmp_fastPKcS0_
	.cfi_endproc
LFE3621:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	.def	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j:
LFB3622:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	16(%esp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	jmp	__Z13_strncmp_fastPKcS0_j
	.cfi_endproc
LFE3622:
	.p2align 4,,15
	.globl	__Z28testOpt07_Type2_strchr_AfteriPKcc
	.def	__Z28testOpt07_Type2_strchr_AfteriPKcc;	.scl	2;	.type	32;	.endef
__Z28testOpt07_Type2_strchr_AfteriPKcc:
LFB3623:
	.cfi_startproc
	movl	8(%esp), %eax
	movsbl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	__Z12_strchr_fastPKcc
	.cfi_endproc
LFE3623:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	.def	__Z29testOpt07_Type2_strrchr_AfteriPKcc;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strrchr_AfteriPKcc:
LFB3624:
	.cfi_startproc
	movl	8(%esp), %eax
	movsbl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	__Z13_strrchr_fastPKcc
	.cfi_endproc
LFE3624:
	.p2align 4,,15
	.globl	__Z28testOpt07_Type2_strstr_AfteriPKcS0_
	.def	__Z28testOpt07_Type2_strstr_AfteriPKcS0_;	.scl	2;	.type	32;	.endef
__Z28testOpt07_Type2_strstr_AfteriPKcS0_:
LFB3625:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	__Z12_strstr_fastPKcS0_
	.cfi_endproc
LFE3625:
	.p2align 4,,15
	.globl	__Z28testOpt07_Type2_strcpy_AfteriPcPKc
	.def	__Z28testOpt07_Type2_strcpy_AfteriPcPKc;	.scl	2;	.type	32;	.endef
__Z28testOpt07_Type2_strcpy_AfteriPcPKc:
LFB3626:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	__Z12_strcpy_fastPcPKc
	.cfi_endproc
LFE3626:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	.def	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strncpy_AfteriPcPKcj:
LFB3627:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	16(%esp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	jmp	__Z13_strncpy_fastPcPKcj
	.cfi_endproc
LFE3627:
	.section .rdata,"dr"
	.align 4
LC188:
	.ascii "lambda1()=%d, lambda2()=%d, lambda3()=%d\12\0"
	.text
	.p2align 4,,15
	.globl	__Z13callLambda123v
	.def	__Z13callLambda123v;	.scl	2;	.type	32;	.endef
__Z13callLambda123v:
LFB3631:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L902
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L902
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L902
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC188, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
L902:
	.cfi_restore_state
	call	__ZSt25__throw_bad_function_callv
	.cfi_endproc
LFE3631:
	.section .rdata,"dr"
	.align 4
LC189:
	.ascii "lambda1()=%d, lambda2()=NG!, lambda3()=%d\12\0"
	.text
	.p2align 4,,15
	.globl	__Z12callLambda13v
	.def	__Z12callLambda13v;	.scl	2;	.type	32;	.endef
__Z12callLambda13v:
LFB3632:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	_s_lambda3+8, %edx
	testl	%edx, %edx
	je	L906
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L906
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 8(%esp)
	movl	$LC189, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L906:
	.cfi_restore_state
	call	__ZSt25__throw_bad_function_callv
	.cfi_endproc
LFE3632:
	.section .rdata,"dr"
	.align 4
LC190:
	.ascii "Call lambda in block with counter in setLambda().\0"
LC191:
	.ascii "dummy=%d\12\0"
	.align 4
LC192:
	.ascii "Call lambda in block without counter in setLambda().\0"
	.align 4
LC193:
	.ascii "for lambda1: external_counter=%d\12\0"
	.align 4
LC194:
	.ascii "for lambda2: local_counter=%d\12\0"
	.align 4
LC195:
	.ascii "for lambda3: static_counter=%d\12\0"
	.text
	.p2align 4,,15
	.globl	__Z9setLambdaRi
	.def	__Z9setLambdaRi;	.scl	2;	.type	32;	.endef
__Z9setLambdaRi:
LFB3633:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3633
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$52, %esp
	.cfi_def_cfa_offset 64
	movl	_s_lambda1+8, %ebx
	testl	%ebx, %ebx
	je	L909
	movl	_s_lambda2+8, %ecx
	testl	%ecx, %ecx
	je	L909
L910:
	movl	$999, 4(%esp)
	movl	$LC191, (%esp)
LEHB10:
	call	_printf
	movl	$LC192, (%esp)
	call	_puts
	movl	_s_lambda3+8, %edx
	testl	%edx, %edx
	je	L924
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L924
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L924
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC188, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L924
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L924
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L924
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC188, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L924
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	_s_lambda2+8, %esi
	testl	%esi, %esi
	movl	%eax, %ebx
	je	L924
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	_s_lambda1+8, %ecx
	testl	%ecx, %ecx
	movl	%eax, %esi
	je	L924
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC188, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$52, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L909:
	.cfi_restore_state
	movl	64(%esp), %eax
	movl	$0, 16(%esp)
	movl	(%eax), %eax
	movl	$LC193, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	16(%esp), %eax
	movl	$LC194, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	__ZZ9setLambdaRiE14static_counter, %eax
	movl	$LC195, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
LEHE10:
	movl	$4, (%esp)
	movl	$0, 40(%esp)
LEHB11:
	call	__Znwj
LEHE11:
	movl	64(%esp), %ecx
	movl	%ecx, (%eax)
	movl	_s_lambda1+4, %edx
	movl	%eax, 32(%esp)
	movl	_s_lambda1, %eax
	movl	32(%esp), %ecx
	movl	36(%esp), %ebx
	movl	%edx, 36(%esp)
	movl	_s_lambda1+12, %edx
	movl	%eax, 32(%esp)
	movl	_s_lambda1+8, %eax
	movl	%ecx, _s_lambda1
	movl	%ebx, _s_lambda1+4
	movl	$__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, _s_lambda1+8
	testl	%eax, %eax
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	movl	$__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE_E9_M_invokeERKSt9_Any_data, _s_lambda1+12
	je	L912
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L912:
	movl	$4, (%esp)
	movl	$0, 40(%esp)
LEHB12:
	call	__Znwj
LEHE12:
	leal	16(%esp), %edx
	movl	%edx, (%eax)
	movl	_s_lambda2+4, %edx
	movl	%eax, 32(%esp)
	movl	_s_lambda2, %eax
	movl	32(%esp), %ecx
	movl	36(%esp), %ebx
	movl	%edx, 36(%esp)
	movl	_s_lambda2+12, %edx
	movl	%eax, 32(%esp)
	movl	_s_lambda2+8, %eax
	movl	%ecx, _s_lambda2
	movl	%ebx, _s_lambda2+4
	movl	$__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, _s_lambda2+8
	testl	%eax, %eax
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	movl	$__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE0_E9_M_invokeERKSt9_Any_data, _s_lambda2+12
	je	L916
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L916:
	movl	$1, (%esp)
	movl	$0, 40(%esp)
LEHB13:
	call	__Znwj
LEHE13:
	movl	%eax, 32(%esp)
	movl	_s_lambda3, %eax
	movl	_s_lambda3+4, %edx
	movl	32(%esp), %ecx
	movl	36(%esp), %ebx
	movl	%eax, 32(%esp)
	movl	_s_lambda3+8, %eax
	movl	%edx, 36(%esp)
	movl	_s_lambda3+12, %edx
	movl	%ecx, _s_lambda3
	movl	%ebx, _s_lambda3+4
	testl	%eax, %eax
	movl	%eax, 40(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, _s_lambda3+8
	movl	%edx, 44(%esp)
	movl	$__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE1_E9_M_invokeERKSt9_Any_data, _s_lambda3+12
	je	L920
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L920:
	movl	$LC190, (%esp)
LEHB14:
	call	_puts
	movl	_s_lambda3+8, %edx
	testl	%edx, %edx
	je	L924
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L924
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L924
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC188, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L924
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L924
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L924
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC188, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L924
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	_s_lambda2+8, %esi
	testl	%esi, %esi
	movl	%eax, %ebx
	je	L924
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	_s_lambda1+8, %ecx
	testl	%ecx, %ecx
	movl	%eax, %esi
	je	L924
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC188, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	jmp	L910
L924:
	call	__ZSt25__throw_bad_function_callv
LEHE14:
L926:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L922
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
L922:
	movl	%ebx, (%esp)
LEHB15:
	call	__Unwind_Resume
LEHE15:
L927:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L922
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L922
L928:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L922
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L922
	.cfi_endproc
LFE3633:
	.section	.gcc_except_table,"w"
LLSDA3633:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3633-LLSDACSB3633
LLSDACSB3633:
	.uleb128 LEHB10-LFB3633
	.uleb128 LEHE10-LEHB10
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB11-LFB3633
	.uleb128 LEHE11-LEHB11
	.uleb128 L926-LFB3633
	.uleb128 0
	.uleb128 LEHB12-LFB3633
	.uleb128 LEHE12-LEHB12
	.uleb128 L927-LFB3633
	.uleb128 0
	.uleb128 LEHB13-LFB3633
	.uleb128 LEHE13-LEHB13
	.uleb128 L928-LFB3633
	.uleb128 0
	.uleb128 LEHB14-LFB3633
	.uleb128 LEHE14-LEHB14
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB15-LFB3633
	.uleb128 LEHE15-LEHB15
	.uleb128 0
	.uleb128 0
LLSDACSE3633:
	.text
	.p2align 4,,15
	.globl	__Z10getLambda1v
	.def	__Z10getLambda1v;	.scl	2;	.type	32;	.endef
__Z10getLambda1v:
LFB3639:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3639
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	movl	$0, 8(%ebx)
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L940
	movl	_s_lambda1+12, %edx
	movl	%eax, 8(%ebx)
	movl	%edx, 12(%ebx)
	movl	$2, 8(%esp)
	movl	$_s_lambda1, 4(%esp)
	movl	%ebx, (%esp)
LEHB16:
	call	*_s_lambda1+8
LEHE16:
L940:
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	movl	%ebx, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret	$4
L944:
	.cfi_restore_state
	movl	8(%ebx), %edx
	movl	%eax, %esi
	testl	%edx, %edx
	je	L943
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%edx
L943:
	movl	%esi, (%esp)
LEHB17:
	call	__Unwind_Resume
LEHE17:
	.cfi_endproc
LFE3639:
	.section	.gcc_except_table,"w"
LLSDA3639:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3639-LLSDACSB3639
LLSDACSB3639:
	.uleb128 LEHB16-LFB3639
	.uleb128 LEHE16-LEHB16
	.uleb128 L944-LFB3639
	.uleb128 0
	.uleb128 LEHB17-LFB3639
	.uleb128 LEHE17-LEHB17
	.uleb128 0
	.uleb128 0
LLSDACSE3639:
	.text
	.p2align 4,,15
	.globl	__Z10getLambda2v
	.def	__Z10getLambda2v;	.scl	2;	.type	32;	.endef
__Z10getLambda2v:
LFB3640:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3640
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	movl	$0, 8(%ebx)
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L952
	movl	_s_lambda1+12, %edx
	movl	%eax, 8(%ebx)
	movl	%edx, 12(%ebx)
	movl	$2, 8(%esp)
	movl	$_s_lambda1, 4(%esp)
	movl	%ebx, (%esp)
LEHB18:
	call	*_s_lambda1+8
LEHE18:
L952:
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	movl	%ebx, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret	$4
L956:
	.cfi_restore_state
	movl	8(%ebx), %edx
	movl	%eax, %esi
	testl	%edx, %edx
	je	L955
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%edx
L955:
	movl	%esi, (%esp)
LEHB19:
	call	__Unwind_Resume
LEHE19:
	.cfi_endproc
LFE3640:
	.section	.gcc_except_table,"w"
LLSDA3640:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3640-LLSDACSB3640
LLSDACSB3640:
	.uleb128 LEHB18-LFB3640
	.uleb128 LEHE18-LEHB18
	.uleb128 L956-LFB3640
	.uleb128 0
	.uleb128 LEHB19-LFB3640
	.uleb128 LEHE19-LEHB19
	.uleb128 0
	.uleb128 0
LLSDACSE3640:
	.text
	.section	.text$_Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	.def	__Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
__Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE:
LFB3735:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	36(%esp), %ebp
	movl	40(%esp), %edi
	flds	48(%esp)
	movl	24(%esp), %ebx
	flds	0(%ebp)
	fadds	(%edi)
	movl	28(%esp), %eax
	movl	44(%esp), %ecx
	movl	32(%esp), %esi
	movl	56(%esp), %edx
	fstps	(%ebx)
	flds	4(%ebp)
	fadds	4(%edi)
	testl	$1, %esi
	fstps	4(%ebx)
	flds	8(%ebp)
	fadds	8(%edi)
	fstps	8(%ebx)
	flds	12(%ebp)
	fadds	12(%edi)
	fstps	12(%ebx)
	flds	16(%ebp)
	fadds	16(%edi)
	fstps	16(%ebx)
	flds	20(%ebp)
	fadds	20(%edi)
	fstps	20(%ebx)
	flds	24(%ebp)
	fadds	24(%edi)
	fstps	24(%ebx)
	flds	28(%ebp)
	fadds	28(%edi)
	fstps	28(%ebx)
	flds	32(%ebp)
	fadds	32(%edi)
	fstps	32(%ebx)
	flds	36(%ebp)
	fadds	36(%edi)
	fstps	36(%ebx)
	flds	40(%ebp)
	fadds	40(%edi)
	fstps	40(%ebx)
	flds	44(%ebp)
	fadds	44(%edi)
	fstps	44(%ebx)
	flds	48(%ebp)
	fadds	48(%edi)
	fstps	48(%ebx)
	flds	52(%ebp)
	fadds	52(%edi)
	fstps	52(%ebx)
	flds	56(%ebp)
	fadds	56(%edi)
	fstps	56(%ebx)
	flds	60(%ebp)
	fadds	60(%edi)
	movl	%esi, %edi
	fstps	60(%ebx)
	movl	$64, %ebx
	flds	(%ecx)
	fmul	%st(1), %st
	fstps	(%eax)
	flds	4(%ecx)
	fmul	%st(1), %st
	fstps	4(%eax)
	flds	8(%ecx)
	fmul	%st(1), %st
	fstps	8(%eax)
	flds	12(%ecx)
	fmul	%st(1), %st
	fstps	12(%eax)
	flds	16(%ecx)
	fmul	%st(1), %st
	fstps	16(%eax)
	flds	20(%ecx)
	fmul	%st(1), %st
	fstps	20(%eax)
	flds	24(%ecx)
	fmul	%st(1), %st
	fstps	24(%eax)
	flds	28(%ecx)
	fmul	%st(1), %st
	fstps	28(%eax)
	flds	32(%ecx)
	fmul	%st(1), %st
	fstps	32(%eax)
	flds	36(%ecx)
	fmul	%st(1), %st
	fstps	36(%eax)
	flds	40(%ecx)
	fmul	%st(1), %st
	fstps	40(%eax)
	flds	44(%ecx)
	fmul	%st(1), %st
	fstps	44(%eax)
	flds	48(%ecx)
	fmul	%st(1), %st
	fstps	48(%eax)
	flds	52(%ecx)
	fmul	%st(1), %st
	fstps	52(%eax)
	flds	56(%ecx)
	fmul	%st(1), %st
	fstps	56(%eax)
	fmuls	60(%ecx)
	fstps	60(%eax)
	jne	L984
	testl	$2, %edi
	jne	L985
L966:
	movl	%ebx, %ecx
	xorl	%eax, %eax
	shrl	$2, %ecx
	testb	$2, %bl
	rep stosl
	je	L967
	xorl	%ebp, %ebp
	addl	$2, %edi
	movw	%bp, -2(%edi)
L967:
	andl	$1, %ebx
	je	L968
	movb	$0, (%edi)
L968:
	movl	52(%esp), %edi
	xorl	%ebx, %ebx
	xorl	%eax, %eax
L969:
	sall	$4, %eax
	addl	$1, %ebx
	leal	(%edi,%eax), %ecx
	addl	%esi, %eax
	flds	(%ecx)
	cmpl	$4, %ebx
	fmuls	(%edx)
	fadds	(%eax)
	fsts	(%eax)
	flds	4(%ecx)
	fmuls	16(%edx)
	faddp	%st, %st(1)
	fsts	(%eax)
	flds	8(%ecx)
	fmuls	32(%edx)
	faddp	%st, %st(1)
	fsts	(%eax)
	flds	12(%ecx)
	fmuls	48(%edx)
	faddp	%st, %st(1)
	fstps	(%eax)
	flds	(%ecx)
	fmuls	4(%edx)
	fadds	4(%eax)
	fsts	4(%eax)
	flds	4(%ecx)
	fmuls	20(%edx)
	faddp	%st, %st(1)
	fsts	4(%eax)
	flds	8(%ecx)
	fmuls	36(%edx)
	faddp	%st, %st(1)
	fsts	4(%eax)
	flds	12(%ecx)
	fmuls	52(%edx)
	faddp	%st, %st(1)
	fstps	4(%eax)
	flds	(%ecx)
	fmuls	8(%edx)
	fadds	8(%eax)
	fsts	8(%eax)
	flds	4(%ecx)
	fmuls	24(%edx)
	faddp	%st, %st(1)
	fsts	8(%eax)
	flds	8(%ecx)
	fmuls	40(%edx)
	faddp	%st, %st(1)
	fsts	8(%eax)
	flds	12(%ecx)
	fmuls	56(%edx)
	faddp	%st, %st(1)
	fstps	8(%eax)
	flds	(%ecx)
	fmuls	12(%edx)
	fadds	12(%eax)
	fsts	12(%eax)
	flds	4(%ecx)
	fmuls	28(%edx)
	faddp	%st, %st(1)
	fsts	12(%eax)
	flds	8(%ecx)
	fmuls	44(%edx)
	faddp	%st, %st(1)
	fsts	12(%eax)
	flds	12(%ecx)
	fmuls	60(%edx)
	faddp	%st, %st(1)
	fstps	12(%eax)
	movl	%ebx, %eax
	jne	L969
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L984:
	.cfi_restore_state
	leal	1(%esi), %edi
	movb	$63, %bl
	testl	$2, %edi
	movb	$0, (%esi)
	je	L966
	.p2align 4,,7
L985:
	xorl	%eax, %eax
	addl	$2, %edi
	movw	%ax, -2(%edi)
	subl	$2, %ebx
	jmp	L966
	.cfi_endproc
LFE3735:
	.section	.text$_Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	.def	__Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
__Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE:
LFB3736:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	68(%esp), %esi
	movl	88(%esp), %ebx
	movaps	16(%ebp), %xmm2
	movaps	16(%edi), %xmm6
	movaps	32(%edi), %xmm5
	addps	%xmm6, %xmm2
	movaps	48(%edi), %xmm4
	movaps	32(%ebp), %xmm1
	movaps	48(%ebp), %xmm0
	addps	%xmm5, %xmm1
	movaps	0(%ebp), %xmm3
	addps	%xmm4, %xmm0
	movl	72(%esp), %ecx
	addps	(%edi), %xmm3
	movaps	%xmm0, 48(%esi)
	movss	92(%esp), %xmm0
	movaps	%xmm3, (%esi)
	movl	96(%esp), %edx
	movl	100(%esp), %eax
	movaps	%xmm2, 16(%esi)
	shufps	$0, %xmm0, %xmm0
	movaps	%xmm1, 32(%esi)
	movaps	16(%ebx), %xmm3
	movaps	32(%ebx), %xmm2
	mulps	%xmm0, %xmm3
	movaps	48(%ebx), %xmm1
	mulps	%xmm0, %xmm2
	movaps	(%ebx), %xmm4
	mulps	%xmm0, %xmm1
	movaps	%xmm3, 16(%ecx)
	mulps	%xmm0, %xmm4
	movaps	%xmm2, 32(%ecx)
	movaps	%xmm1, 48(%ecx)
	movaps	%xmm4, (%ecx)
	movaps	32(%edx), %xmm7
	movaps	(%edx), %xmm0
	movaps	16(%edx), %xmm5
	movaps	%xmm7, (%esp)
	movaps	(%eax), %xmm4
	movaps	16(%eax), %xmm7
	movaps	%xmm4, %xmm3
	movaps	48(%edx), %xmm2
	unpcklps	%xmm7, %xmm3
	unpckhps	%xmm7, %xmm4
	movaps	32(%eax), %xmm6
	movaps	%xmm2, 16(%esp)
	movaps	48(%eax), %xmm1
	movaps	%xmm3, %xmm2
	movaps	%xmm6, %xmm3
	movl	76(%esp), %eax
	unpcklps	%xmm1, %xmm3
	unpckhps	%xmm1, %xmm6
	movaps	%xmm2, %xmm1
	shufps	$238, %xmm3, %xmm2
	movlhps	%xmm3, %xmm1
	movaps	%xmm4, %xmm3
	shufps	$238, %xmm6, %xmm4
	movlhps	%xmm6, %xmm3
	movaps	%xmm0, %xmm6
	dpps	$241, %xmm4, %xmm6
	movaps	%xmm6, %xmm7
	movaps	%xmm0, %xmm6
	dpps	$241, %xmm3, %xmm6
	unpcklps	%xmm7, %xmm6
	movaps	%xmm0, %xmm7
	dpps	$241, %xmm2, %xmm7
	dpps	$241, %xmm1, %xmm0
	unpcklps	%xmm7, %xmm0
	movaps	16(%esp), %xmm7
	movlhps	%xmm6, %xmm0
	movaps	%xmm0, (%eax)
	movaps	%xmm5, %xmm6
	movaps	%xmm5, %xmm0
	dpps	$241, %xmm4, %xmm6
	dpps	$241, %xmm3, %xmm0
	unpcklps	%xmm6, %xmm0
	movaps	%xmm5, %xmm6
	dpps	$241, %xmm2, %xmm6
	dpps	$241, %xmm1, %xmm5
	unpcklps	%xmm6, %xmm5
	movaps	(%esp), %xmm6
	movlhps	%xmm0, %xmm5
	movaps	%xmm5, 16(%eax)
	movaps	%xmm6, %xmm0
	movaps	%xmm6, %xmm5
	dpps	$241, %xmm4, %xmm5
	dpps	$241, %xmm3, %xmm0
	dpps	$241, %xmm7, %xmm4
	dpps	$241, %xmm7, %xmm3
	unpcklps	%xmm5, %xmm0
	movaps	%xmm6, %xmm5
	dpps	$241, %xmm2, %xmm5
	unpcklps	%xmm4, %xmm3
	dpps	$241, %xmm1, %xmm6
	dpps	$241, %xmm7, %xmm2
	dpps	$241, %xmm7, %xmm1
	unpcklps	%xmm5, %xmm6
	movlhps	%xmm0, %xmm6
	movaps	%xmm6, 32(%eax)
	unpcklps	%xmm2, %xmm1
	movlhps	%xmm3, %xmm1
	movaps	%xmm1, 48(%eax)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3736:
	.section	.text$_Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	.def	__Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
__Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE:
LFB3737:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	36(%esp), %ebp
	movl	40(%esp), %edi
	flds	48(%esp)
	movl	24(%esp), %esi
	flds	0(%ebp)
	fadds	(%edi)
	movl	44(%esp), %ebx
	movl	32(%esp), %eax
	movl	52(%esp), %ecx
	movl	56(%esp), %edx
	fstps	(%esi)
	flds	4(%ebp)
	fadds	4(%edi)
	fstps	4(%esi)
	flds	8(%ebp)
	fadds	8(%edi)
	fstps	8(%esi)
	flds	12(%ebp)
	fadds	12(%edi)
	fstps	12(%esi)
	movl	28(%esp), %esi
	flds	(%ebx)
	fmul	%st(1), %st
	fstps	(%esi)
	flds	4(%ebx)
	fmul	%st(1), %st
	fstps	4(%esi)
	flds	8(%ebx)
	fmul	%st(1), %st
	fstps	8(%esi)
	fmuls	12(%ebx)
	fstps	12(%esi)
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	movl	$0, 8(%eax)
	movl	$0, 12(%eax)
	flds	(%ecx)
	fmuls	(%edx)
	fadds	(%eax)
	fsts	(%eax)
	flds	4(%ecx)
	fmuls	16(%edx)
	faddp	%st, %st(1)
	fsts	(%eax)
	flds	8(%ecx)
	fmuls	32(%edx)
	faddp	%st, %st(1)
	fstps	(%eax)
	flds	(%ecx)
	fmuls	4(%edx)
	fadds	4(%eax)
	fsts	4(%eax)
	flds	4(%ecx)
	fmuls	20(%edx)
	faddp	%st, %st(1)
	fsts	4(%eax)
	flds	8(%ecx)
	fmuls	36(%edx)
	faddp	%st, %st(1)
	fstps	4(%eax)
	flds	(%ecx)
	fmuls	8(%edx)
	fadds	8(%eax)
	fsts	8(%eax)
	flds	4(%ecx)
	fmuls	24(%edx)
	faddp	%st, %st(1)
	fsts	8(%eax)
	flds	8(%ecx)
	fmuls	40(%edx)
	faddp	%st, %st(1)
	fstps	8(%eax)
	flds	(%ecx)
	fmuls	12(%edx)
	fadds	12(%eax)
	fsts	12(%eax)
	flds	4(%ecx)
	fmuls	28(%edx)
	faddp	%st, %st(1)
	fsts	12(%eax)
	flds	8(%ecx)
	fmuls	44(%edx)
	faddp	%st, %st(1)
	fstps	12(%eax)
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3737:
	.section	.text$_Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	.def	__Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
__Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE:
LFB3738:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	36(%esp), %ebp
	movl	40(%esp), %edi
	flds	48(%esp)
	movl	24(%esp), %esi
	flds	0(%ebp)
	fadds	(%edi)
	movl	44(%esp), %ebx
	movl	32(%esp), %eax
	movl	52(%esp), %ecx
	movl	56(%esp), %edx
	fstps	(%esi)
	flds	4(%ebp)
	fadds	4(%edi)
	fstps	4(%esi)
	flds	8(%ebp)
	fadds	8(%edi)
	fstps	8(%esi)
	flds	12(%ebp)
	fadds	12(%edi)
	fstps	12(%esi)
	movl	28(%esp), %esi
	flds	(%ebx)
	fmul	%st(1), %st
	fstps	(%esi)
	flds	4(%ebx)
	fmul	%st(1), %st
	fstps	4(%esi)
	flds	8(%ebx)
	fmul	%st(1), %st
	fstps	8(%esi)
	fmuls	12(%ebx)
	fstps	12(%esi)
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	movl	$0, 8(%eax)
	movl	$0, 12(%eax)
	flds	(%ecx)
	fmuls	(%edx)
	fadds	(%eax)
	fsts	(%eax)
	flds	4(%ecx)
	fmuls	16(%edx)
	faddp	%st, %st(1)
	fsts	(%eax)
	flds	8(%ecx)
	fmuls	32(%edx)
	faddp	%st, %st(1)
	fstps	(%eax)
	flds	(%ecx)
	fmuls	4(%edx)
	fadds	4(%eax)
	fsts	4(%eax)
	flds	4(%ecx)
	fmuls	20(%edx)
	faddp	%st, %st(1)
	fsts	4(%eax)
	flds	8(%ecx)
	fmuls	36(%edx)
	faddp	%st, %st(1)
	fstps	4(%eax)
	flds	(%ecx)
	fmuls	8(%edx)
	fadds	8(%eax)
	fsts	8(%eax)
	flds	4(%ecx)
	fmuls	24(%edx)
	faddp	%st, %st(1)
	fsts	8(%eax)
	flds	8(%ecx)
	fmuls	40(%edx)
	faddp	%st, %st(1)
	fstps	8(%eax)
	flds	(%ecx)
	fmuls	12(%edx)
	fadds	12(%eax)
	fsts	12(%eax)
	flds	4(%ecx)
	fmuls	28(%edx)
	faddp	%st, %st(1)
	fsts	12(%eax)
	flds	8(%ecx)
	fmuls	44(%edx)
	faddp	%st, %st(1)
	fstps	12(%eax)
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3738:
	.section	.text$_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	.def	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv;	.scl	2;	.type	32;	.endef
__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv:
LFB3845:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	movl	48(%esp), %edx
	movl	2496(%edx), %eax
	cmpl	$623, %eax
	ja	L993
	leal	1(%eax), %ecx
	movl	(%edx,%eax,4), %eax
L994:
	movl	%ecx, 2496(%edx)
	movl	%eax, %edx
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	shrl	$11, %edx
	xorl	%eax, %edx
	movl	%edx, %eax
	sall	$7, %eax
	andl	$-1658038656, %eax
	xorl	%edx, %eax
	movl	%eax, %edx
	sall	$15, %edx
	andl	$-272236544, %edx
	xorl	%eax, %edx
	movl	%edx, %eax
	shrl	$18, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	xorl	%edx, %eax
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L993:
	.cfi_restore_state
	movl	%edx, %eax
	andl	$15, %eax
	shrl	$2, %eax
	negl	%eax
	andl	$3, %eax
	je	L1010
	movl	4(%edx), %esi
	movl	(%edx), %ecx
	movl	%esi, %ebx
	andl	$-2147483648, %ecx
	andl	$2147483647, %ebx
	orl	%ecx, %ebx
	movl	%ebx, %ecx
	andl	$1, %ecx
	negl	%ecx
	andl	$-1727483681, %ecx
	xorl	1588(%edx), %ecx
	shrl	%ebx
	xorl	%ebx, %ecx
	cmpl	$1, %eax
	movl	%ecx, (%edx)
	jbe	L1011
	movl	8(%edx), %edi
	andl	$-2147483648, %esi
	movl	%edi, %ebx
	andl	$2147483647, %ebx
	orl	%esi, %ebx
	movl	%ebx, %ecx
	andl	$1, %ecx
	negl	%ecx
	andl	$-1727483681, %ecx
	xorl	1592(%edx), %ecx
	shrl	%ebx
	xorl	%ebx, %ecx
	cmpl	$2, %eax
	movl	%ecx, 4(%edx)
	jbe	L1012
	movl	12(%edx), %ebx
	andl	$-2147483648, %edi
	movl	$3, %ebp
	movl	$224, (%esp)
	andl	$2147483647, %ebx
	orl	%edi, %ebx
	movl	%ebx, %ecx
	andl	$1, %ecx
	negl	%ecx
	andl	$-1727483681, %ecx
	xorl	1596(%edx), %ecx
	shrl	%ebx
	xorl	%ebx, %ecx
	movl	%ecx, 8(%edx)
L995:
	movl	$227, 4(%esp)
	xorl	%ecx, %ecx
	movdqa	LC196, %xmm2
	subl	%eax, 4(%esp)
	movdqa	LC197, %xmm3
	movdqa	LC198, %xmm4
	sall	$2, %eax
	movdqa	LC199, %xmm5
	pxor	%xmm6, %xmm6
	leal	(%edx,%eax), %ebx
	leal	4(%edx,%eax), %edi
	leal	1588(%edx,%eax), %esi
	xorl	%eax, %eax
	.p2align 4,,7
L1001:
	movdqu	(%edi,%eax), %xmm1
	movdqa	(%ebx,%eax), %xmm0
	pand	%xmm2, %xmm1
	pand	%xmm3, %xmm0
	addl	$1, %ecx
	por	%xmm0, %xmm1
	movdqa	%xmm1, %xmm0
	psrld	$1, %xmm1
	movdqu	(%esi,%eax), %xmm7
	pand	%xmm4, %xmm0
	pcmpeqd	%xmm6, %xmm0
	pandn	%xmm5, %xmm0
	pxor	%xmm7, %xmm0
	pxor	%xmm1, %xmm0
	movdqa	%xmm0, (%ebx,%eax)
	addl	$16, %eax
	cmpl	$55, %ecx
	jbe	L1001
	cmpl	$224, 4(%esp)
	leal	224(%ebp), %eax
	je	L999
	leal	225(%ebp), %ebx
	leal	(%edx,%eax,4), %edi
	movl	(%edx,%ebx,4), %eax
	movl	(%edi), %ecx
	movl	%eax, %esi
	andl	$-2147483648, %ecx
	andl	$2147483647, %esi
	orl	%ecx, %esi
	movl	%esi, %ecx
	andl	$1, %ecx
	negl	%ecx
	andl	$-1727483681, %ecx
	xorl	2484(%edx,%ebp,4), %ecx
	shrl	%esi
	xorl	%esi, %ecx
	cmpl	$225, (%esp)
	movl	%ecx, (%edi)
	je	L999
	leal	226(%ebp), %edi
	andl	$-2147483648, %eax
	movl	(%edx,%edi,4), %esi
	movl	%esi, %ecx
	andl	$2147483647, %ecx
	orl	%eax, %ecx
	movl	%ecx, %eax
	andl	$1, %eax
	negl	%eax
	andl	$-1727483681, %eax
	xorl	2488(%edx,%ebp,4), %eax
	shrl	%ecx
	xorl	%ecx, %eax
	cmpl	$226, (%esp)
	movl	%eax, (%edx,%ebx,4)
	je	L999
	movl	908(%edx,%ebp,4), %ecx
	andl	$-2147483648, %esi
	andl	$2147483647, %ecx
	orl	%esi, %ecx
	movl	%ecx, %eax
	andl	$1, %eax
	negl	%eax
	andl	$-1727483681, %eax
	xorl	2492(%edx,%ebp,4), %eax
	shrl	%ecx
	xorl	%ecx, %eax
	movl	%eax, (%edx,%edi,4)
L999:
	leal	908(%edx), %eax
	andl	$15, %eax
	shrl	$2, %eax
	negl	%eax
	andl	$3, %eax
	je	L1013
	movl	912(%edx), %esi
	movl	908(%edx), %ecx
	movl	%esi, %ebx
	andl	$-2147483648, %ecx
	andl	$2147483647, %ebx
	orl	%ecx, %ebx
	movl	%ebx, %ecx
	andl	$1, %ecx
	negl	%ecx
	andl	$-1727483681, %ecx
	xorl	(%edx), %ecx
	shrl	%ebx
	xorl	%ebx, %ecx
	cmpl	$1, %eax
	movl	%ecx, 908(%edx)
	jbe	L1014
	movl	916(%edx), %edi
	andl	$-2147483648, %esi
	movl	%edi, %ebx
	andl	$2147483647, %ebx
	orl	%esi, %ebx
	movl	%ebx, %ecx
	andl	$1, %ecx
	negl	%ecx
	andl	$-1727483681, %ecx
	xorl	4(%edx), %ecx
	shrl	%ebx
	xorl	%ebx, %ecx
	cmpl	$2, %eax
	movl	%ecx, 912(%edx)
	jbe	L1015
	movl	920(%edx), %ebx
	andl	$-2147483648, %edi
	movl	$393, 4(%esp)
	movl	$230, 8(%esp)
	andl	$2147483647, %ebx
	orl	%edi, %ebx
	movl	%ebx, %ecx
	andl	$1, %ecx
	negl	%ecx
	andl	$-1727483681, %ecx
	xorl	8(%edx), %ecx
	shrl	%ebx
	xorl	%ebx, %ecx
	movl	%ecx, 916(%edx)
L1002:
	movl	$396, (%esp)
	xorl	%ecx, %ecx
	pxor	%xmm6, %xmm6
	subl	%eax, (%esp)
	movl	(%esp), %esi
	leal	908(,%eax,4), %eax
	leal	(%edx,%eax), %ebx
	leal	4(%edx,%eax), %ebp
	shrl	$2, %esi
	leal	0(,%esi,4), %edi
	movl	%edi, 12(%esp)
	leal	-908(%edx,%eax), %edi
	xorl	%eax, %eax
	.p2align 4,,7
L1008:
	movdqu	0(%ebp,%eax), %xmm1
	movdqa	(%ebx,%eax), %xmm0
	pand	%xmm2, %xmm1
	pand	%xmm3, %xmm0
	addl	$1, %ecx
	por	%xmm0, %xmm1
	movdqa	%xmm1, %xmm0
	psrld	$1, %xmm1
	movdqu	(%edi,%eax), %xmm7
	pand	%xmm4, %xmm0
	pcmpeqd	%xmm6, %xmm0
	pandn	%xmm5, %xmm0
	pxor	%xmm7, %xmm0
	pxor	%xmm1, %xmm0
	movdqa	%xmm0, (%ebx,%eax)
	addl	$16, %eax
	cmpl	%ecx, %esi
	ja	L1008
	movl	12(%esp), %edi
	movl	4(%esp), %eax
	movl	8(%esp), %ecx
	movl	(%esp), %esi
	subl	%edi, %eax
	addl	%edi, %ecx
	cmpl	%esi, %edi
	movl	%eax, 4(%esp)
	je	L1006
	leal	1(%ecx), %esi
	leal	(%edx,%ecx,4), %ebp
	movl	(%edx,%esi,4), %eax
	movl	0(%ebp), %ebx
	movl	%eax, %edi
	andl	$-2147483648, %ebx
	andl	$2147483647, %edi
	orl	%ebx, %edi
	movl	%edi, %ebx
	andl	$1, %ebx
	negl	%ebx
	andl	$-1727483681, %ebx
	xorl	-908(%edx,%ecx,4), %ebx
	shrl	%edi
	xorl	%edi, %ebx
	cmpl	$1, 4(%esp)
	movl	%ebx, 0(%ebp)
	je	L1006
	leal	2(%ecx), %ebp
	andl	$-2147483648, %eax
	movl	(%edx,%ebp,4), %edi
	movl	%edi, %ebx
	andl	$2147483647, %ebx
	orl	%eax, %ebx
	movl	%ebx, %eax
	andl	$1, %eax
	negl	%eax
	andl	$-1727483681, %eax
	xorl	-904(%edx,%ecx,4), %eax
	shrl	%ebx
	xorl	%ebx, %eax
	cmpl	$2, 4(%esp)
	movl	%eax, (%edx,%esi,4)
	je	L1006
	movl	12(%edx,%ecx,4), %ebx
	andl	$-2147483648, %edi
	andl	$2147483647, %ebx
	orl	%edi, %ebx
	movl	%ebx, %eax
	andl	$1, %eax
	negl	%eax
	andl	$-1727483681, %eax
	xorl	-900(%edx,%ecx,4), %eax
	shrl	%ebx
	xorl	%ebx, %eax
	movl	%eax, (%edx,%ebp,4)
L1006:
	movl	(%edx), %eax
	movl	2492(%edx), %ecx
	movl	%eax, %ebx
	andl	$-2147483648, %ecx
	andl	$2147483647, %ebx
	orl	%ecx, %ebx
	movl	%ebx, %ecx
	andl	$1, %ebx
	shrl	%ecx
	negl	%ebx
	xorl	1584(%edx), %ecx
	andl	$-1727483681, %ebx
	xorl	%ebx, %ecx
	movl	%ecx, 2492(%edx)
	movl	$1, %ecx
	jmp	L994
	.p2align 4,,7
L1012:
	movl	$225, (%esp)
	movl	$2, %ebp
	jmp	L995
	.p2align 4,,7
L1011:
	movl	$226, (%esp)
	movl	$1, %ebp
	jmp	L995
	.p2align 4,,7
L1010:
	movl	$227, (%esp)
	xorl	%ebp, %ebp
	jmp	L995
	.p2align 4,,7
L1013:
	movl	$396, 4(%esp)
	movl	$227, 8(%esp)
	jmp	L1002
	.p2align 4,,7
L1015:
	movl	$394, 4(%esp)
	movl	$229, 8(%esp)
	jmp	L1002
	.p2align 4,,7
L1014:
	movl	$395, 4(%esp)
	movl	$228, 8(%esp)
	jmp	L1002
	.cfi_endproc
LFE3845:
	.text
	.p2align 4,,15
	.globl	__Z9initOpt04R11dataOpt04_t
	.def	__Z9initOpt04R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z9initOpt04R11dataOpt04_t:
LFB3040:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$1, %ecx
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	movl	$440509467, %edi
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$5489, %ebx
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	2560(%esp), %ebp
	leal	16(%esp), %esi
	movl	$5489, 16(%esp)
	.p2align 4,,7
L1033:
	movl	%ebx, %eax
	movl	%ecx, %edx
	shrl	$30, %eax
	xorl	%ebx, %eax
	shrl	$4, %edx
	imull	$1812433253, %eax, %ebx
	movl	%edx, %eax
	mull	%edi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	addl	%eax, %ebx
	movl	%ebx, (%esi,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1033
	leal	80000(%ebp), %ebx
	movl	$-1342177277, %edi
	cmpl	%ebx, %ebp
	movl	$624, 2512(%esp)
	je	L1031
	.p2align 4,,7
L1036:
	movl	%esi, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L1036
	mull	%edi
	addl	$8, %ebp
	movl	$0x00000000, -4(%ebp)
	shrl	$28, %edx
	movl	%edx, -8(%ebp)
	cmpl	%ebp, %ebx
	jne	L1036
L1031:
	addl	$2540, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3040:
	.p2align 4,,15
	.globl	__Z9initOpt06R11dataOpt06_t
	.def	__Z9initOpt06R11dataOpt06_t;	.scl	2;	.type	32;	.endef
__Z9initOpt06R11dataOpt06_t:
LFB3525:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$1, %ecx
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	movl	$440509467, %edi
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$5489, %ebx
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	2560(%esp), %ebp
	leal	16(%esp), %esi
	movl	$5489, 16(%esp)
	.p2align 4,,7
L1042:
	movl	%ebx, %eax
	movl	%ecx, %edx
	shrl	$30, %eax
	xorl	%ebx, %eax
	shrl	$4, %edx
	imull	$1812433253, %eax, %ebx
	movl	%edx, %eax
	mull	%edi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	addl	%eax, %ebx
	movl	%ebx, (%esi,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1042
	leal	80000(%ebp), %ebx
	cmpl	%ebx, %ebp
	movl	$624, 2512(%esp)
	je	L1040
	.p2align 4,,7
L1046:
	movl	%esi, (%esp)
	addl	$8, %ebp
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	movl	%eax, 4(%esp)
	movd	4(%esp), %xmm0
	movq	%xmm0, 8(%esp)
	fildq	8(%esp)
	fldz
	fadd	%st, %st(1)
	fxch	%st(1)
	fmuls	LC200
	fmuls	LC201
	fadd	%st(1), %st
	fstps	-8(%ebp)
	fstps	-4(%ebp)
	cmpl	%ebp, %ebx
	jne	L1046
L1040:
	addl	$2540, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3525:
	.p2align 4,,15
	.globl	__Z9initOpt02R11dataOpt02_t
	.def	__Z9initOpt02R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z9initOpt02R11dataOpt02_t:
LFB2675:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$1, %ecx
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	movl	$440509467, %edi
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$5489, %ebx
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	2560(%esp), %ebp
	leal	16(%esp), %esi
	movl	$5489, 16(%esp)
	.p2align 4,,7
L1050:
	movl	%ebx, %eax
	movl	%ecx, %edx
	shrl	$30, %eax
	xorl	%ebx, %eax
	shrl	$4, %edx
	imull	$1812433253, %eax, %ebx
	movl	%edx, %eax
	mull	%edi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	addl	%eax, %ebx
	movl	%ebx, (%esi,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1050
	leal	40000(%ebp), %ebx
	movl	$-1342177277, %edi
	cmpl	%ebx, %ebp
	movl	$624, 2512(%esp)
	je	L1048
	.p2align 4,,7
L1053:
	movl	%esi, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L1053
	mull	%edi
	addl	$4, %ebp
	shrl	$28, %edx
	movl	%edx, -4(%ebp)
	cmpl	%ebp, %ebx
	jne	L1053
L1048:
	addl	$2540, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2675:
	.p2align 4,,15
	.globl	__Z15initOpt03_Type3R11dataOpt03_t
	.def	__Z15initOpt03_Type3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z15initOpt03_Type3R11dataOpt03_t:
LFB2681:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$1, %ecx
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	movl	$440509467, %edi
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$5489, %ebx
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	2560(%esp), %ebp
	leal	16(%esp), %esi
	movl	$5489, 16(%esp)
	.p2align 4,,7
L1059:
	movl	%ebx, %eax
	movl	%ecx, %edx
	shrl	$30, %eax
	xorl	%ebx, %eax
	shrl	$4, %edx
	imull	$1812433253, %eax, %ebx
	movl	%edx, %eax
	mull	%edi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	addl	%eax, %ebx
	movl	%ebx, (%esi,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1059
	leal	40000(%ebp), %ebx
	movl	$-1342177277, %edi
	cmpl	%ebx, %ebp
	movl	$624, 2512(%esp)
	je	L1057
	.p2align 4,,7
L1062:
	movl	%esi, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L1062
	mull	%edi
	addl	$4, %ebp
	shrl	$28, %edx
	movl	%edx, -4(%ebp)
	cmpl	%ebp, %ebx
	jne	L1062
L1057:
	addl	$2540, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2681:
	.p2align 4,,15
	.globl	__Z9initOpt01R11dataOpt01_t
	.def	__Z9initOpt01R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z9initOpt01R11dataOpt01_t:
LFB2670:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$1, %ecx
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	movl	$440509467, %edi
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$5489, %ebx
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	2560(%esp), %ebp
	leal	16(%esp), %esi
	movl	$5489, 16(%esp)
	.p2align 4,,7
L1068:
	movl	%ebx, %eax
	movl	%ecx, %edx
	shrl	$30, %eax
	xorl	%ebx, %eax
	shrl	$4, %edx
	imull	$1812433253, %eax, %ebx
	movl	%edx, %eax
	mull	%edi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	addl	%eax, %ebx
	movl	%ebx, (%esi,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1068
	leal	40004(%ebp), %edi
	leal	4(%ebp), %ebx
	cmpl	%edi, %ebx
	movl	$0, 0(%ebp)
	movl	$-1342177277, %ebp
	movl	$624, 2512(%esp)
	je	L1066
	.p2align 4,,7
L1071:
	movl	%esi, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L1071
	mull	%ebp
	addl	$4, %ebx
	shrl	$28, %edx
	movl	%edx, -4(%ebx)
	cmpl	%ebx, %edi
	jne	L1071
L1066:
	addl	$2540, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2670:
	.section	.text.startup,"x"
	.p2align 4,,15
	.def	__GLOBAL__sub_I__Z9initOpt01R11dataOpt01_t;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z9initOpt01R11dataOpt01_t:
LFB3942:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
	movl	$0, _s_lambda1+8
	movl	$0, _s_lambda2+8
	movl	$0, _s_lambda3+8
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3942:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z9initOpt01R11dataOpt01_t
	.section	.text.exit,"x"
	.p2align 4,,15
	.def	__GLOBAL__sub_D__Z9initOpt01R11dataOpt01_t;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_D__Z9initOpt01R11dataOpt01_t:
LFB3943:
	.cfi_startproc
	jmp	__Z41__static_initialization_and_destruction_0ii.part.35
	.cfi_endproc
LFE3943:
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__sub_D__Z9initOpt01R11dataOpt01_t
.lcomm __ZZ9setLambdaRiE14static_counter,4,16
.lcomm __ZZL19_strncpy_fast_case0PcPKcjE4null,16,16
.lcomm __ZZL19_strncpy_fast_case1PcPKcjE4null,16,16
.lcomm __ZZL19_strncpy_fast_case2PcPKcjE4null,16,16
.lcomm __ZZL19_strncpy_fast_case3PcPKcjE4null,16,16
.lcomm __ZZL18_strcpy_fast_case0PcPKcE4null,16,16
.lcomm __ZZL18_strcpy_fast_case1PcPKcE4null,16,16
.lcomm __ZZL18_strcpy_fast_case2PcPKcE4null,16,16
.lcomm __ZZL18_strcpy_fast_case3PcPKcE4null,16,16
.lcomm __ZZL19_strncmp_fast_case0PKcS0_jE4null,16,16
.lcomm __ZZL19_strncmp_fast_case1PKcS0_jE4null,16,16
.lcomm __ZZL19_strncmp_fast_case2PKcS0_jE4null,16,16
.lcomm __ZZL19_strncmp_fast_case3PKcS0_jE4null,16,16
.lcomm __ZZ13_strnlen_fastPKcjE4null,16,16
.lcomm __ZZ12_strlen_fastPKcE4null,16,16
	.section .rdata,"dr"
	.align 32
__ZTSZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_:
	.ascii "*ZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_\0"
	.align 32
__ZTSZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_:
	.ascii "*ZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_\0"
__ZTSZ9setLambdaRiEUlvE_:
	.ascii "*Z9setLambdaRiEUlvE_\0"
__ZTSZ9setLambdaRiEUlvE0_:
	.ascii "*Z9setLambdaRiEUlvE0_\0"
__ZTSZ9setLambdaRiEUlvE1_:
	.ascii "*Z9setLambdaRiEUlvE1_\0"
	.align 4
__ZTIZ9setLambdaRiEUlvE1_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ9setLambdaRiEUlvE1_
	.align 4
__ZTIZ9setLambdaRiEUlvE0_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ9setLambdaRiEUlvE0_
	.align 4
__ZTIZ9setLambdaRiEUlvE_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ9setLambdaRiEUlvE_
	.align 4
__ZTIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_
	.align 4
__ZTIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_
	.align 4
__ZL19_strncpy_fast_casex:
	.long	__ZL19_strncpy_fast_case0PcPKcj
	.long	__ZL19_strncpy_fast_case1PcPKcj
	.long	__ZL19_strncpy_fast_case2PcPKcj
	.long	__ZL19_strncpy_fast_case3PcPKcj
	.align 4
__ZL18_strcpy_fast_casex:
	.long	__ZL18_strcpy_fast_case0PcPKc
	.long	__ZL18_strcpy_fast_case1PcPKc
	.long	__ZL18_strcpy_fast_case2PcPKc
	.long	__ZL18_strcpy_fast_case3PcPKc
	.align 32
__ZL17_memcpy_m128i_u_x:
	.long	__ZL18_memcpy_m128i_00_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_01_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_02_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_03_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_04_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_05_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_06_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_07_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_08_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_09_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_10_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_11_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_12_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_13_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_14_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_15_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_16_uPcU8__vectorx
	.align 32
__ZL17_memcpy_m128i_a_x:
	.long	__ZL18_memcpy_m128i_00_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_01_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_02_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_03_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_04_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_05_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_06_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_07_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_08_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_09_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_10_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_11_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_12_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_13_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_14_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_15_aPcU8__vectorx
	.long	__ZL18_memcpy_m128i_16_aPcU8__vectorx
	.align 4
__ZL22_strstr_fast_cmp_casex:
	.long	__ZL22_strstr_fast_cmp_case0PKcS0_
	.long	__ZL22_strstr_fast_cmp_case1PKcS0_
	.long	__ZL22_strstr_fast_cmp_case2PKcS0_
	.long	__ZL22_strstr_fast_cmp_case3PKcS0_
	.align 4
__ZL19_strncmp_fast_casex:
	.long	__ZL19_strncmp_fast_case0PKcS0_j
	.long	__ZL19_strncmp_fast_case1PKcS0_j
	.long	__ZL19_strncmp_fast_case2PKcS0_j
	.long	__ZL19_strncmp_fast_case3PKcS0_j
	.align 4
__ZL18_strcmp_fast_casex:
	.long	__ZL18_strcmp_fast_case0PKcS0_
	.long	__ZL18_strcmp_fast_case1PKcS0_
	.long	__ZL18_strcmp_fast_case2PKcS0_
	.long	__ZL18_strcmp_fast_case3PKcS0_
	.globl	_s_lambda3
	.bss
	.align 16
_s_lambda3:
	.space 16
	.globl	_s_lambda2
	.align 16
_s_lambda2:
	.space 16
	.globl	_s_lambda1
	.align 16
_s_lambda1:
	.space 16
.lcomm __ZGVZL19_strncpy_fast_case3PcPKcjE4null,8,16
.lcomm __ZGVZL19_strncpy_fast_case2PcPKcjE4null,8,16
.lcomm __ZGVZL19_strncpy_fast_case1PcPKcjE4null,8,16
.lcomm __ZGVZL19_strncpy_fast_case0PcPKcjE4null,8,16
.lcomm __ZGVZL18_strcpy_fast_case3PcPKcE4null,8,16
.lcomm __ZGVZL18_strcpy_fast_case2PcPKcE4null,8,16
.lcomm __ZGVZL18_strcpy_fast_case1PcPKcE4null,8,16
.lcomm __ZGVZL18_strcpy_fast_case0PcPKcE4null,8,16
.lcomm __ZGVZL19_strncmp_fast_case3PKcS0_jE4null,8,16
.lcomm __ZGVZL19_strncmp_fast_case2PKcS0_jE4null,8,16
.lcomm __ZGVZL19_strncmp_fast_case1PKcS0_jE4null,8,16
.lcomm __ZGVZL19_strncmp_fast_case0PKcS0_jE4null,8,16
.lcomm __ZGVZ13_strnlen_fastPKcjE4null,8,16
.lcomm __ZGVZ12_strlen_fastPKcE4null,8,16
.lcomm __ZStL8__ioinit,1,1
	.section .rdata,"dr"
	.align 16
LC0:
	.long	0
	.long	0
	.long	1
	.long	0
	.align 16
LC1:
	.long	2
	.long	0
	.long	3
	.long	0
	.align 16
LC2:
	.long	4
	.long	0
	.long	5
	.long	0
	.align 16
LC3:
	.long	6
	.long	0
	.long	7
	.long	0
	.align 16
LC4:
	.long	0
	.long	1
	.long	2
	.long	3
	.align 16
LC5:
	.long	4
	.long	4
	.long	4
	.long	4
	.align 4
LC8:
	.long	1065353216
	.align 16
LC109:
	.long	858927408
	.long	926299444
	.long	1650538808
	.long	1717920867
	.align 16
LC127:
	.byte	48
	.byte	49
	.byte	50
	.byte	51
	.byte	52
	.byte	53
	.byte	54
	.byte	55
	.byte	56
	.byte	57
	.byte	97
	.byte	98
	.byte	99
	.byte	100
	.byte	101
	.byte	102
	.align 16
LC196:
	.long	2147483647
	.long	2147483647
	.long	2147483647
	.long	2147483647
	.align 16
LC197:
	.long	-2147483648
	.long	-2147483648
	.long	-2147483648
	.long	-2147483648
	.align 16
LC198:
	.long	1
	.long	1
	.long	1
	.long	1
	.align 16
LC199:
	.long	-1727483681
	.long	-1727483681
	.long	-1727483681
	.long	-1727483681
	.align 4
LC200:
	.long	796917760
	.align 4
LC201:
	.long	1093664768
	.ident	"GCC: (GNU) 4.8.2"
	.def	___cxa_guard_acquire;	.scl	2;	.type	32;	.endef
	.def	___cxa_guard_release;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	___real__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	___real__Znwj;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	__ZSt25__throw_bad_function_callv;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_strcmp;	.scl	2;	.type	32;	.endef
	.def	_strncmp;	.scl	2;	.type	32;	.endef
	.def	_strchr;	.scl	2;	.type	32;	.endef
	.def	_strrchr;	.scl	2;	.type	32;	.endef
	.def	_strstr;	.scl	2;	.type	32;	.endef
	.def	_strcpy;	.scl	2;	.type	32;	.endef
	.def	_strncpy;	.scl	2;	.type	32;	.endef
	.def	__Z12_strlen_fastPKc;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	__Z13_strnlen_fastPKcj;	.scl	2;	.type	32;	.endef
	.def	__Z12_strcmp_fastPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z13_strncmp_fastPKcS0_j;	.scl	2;	.type	32;	.endef
	.def	__Z12_strchr_fastPKcc;	.scl	2;	.type	32;	.endef
	.def	__Z13_strrchr_fastPKcc;	.scl	2;	.type	32;	.endef
	.def	__Z12_strstr_fastPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z13_strstr0_fastPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z12_strcpy_fastPcPKc;	.scl	2;	.type	32;	.endef
	.def	__Z13_strncpy_fastPcPKcj;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef

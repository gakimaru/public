	.file	"sub.cpp"
	.text
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_00_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_00_aPcU8__vectorx:
LFB3573:
	.cfi_startproc
	rep ret
	.cfi_endproc
LFE3573:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_01_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_01_aPcU8__vectorx:
LFB3575:
	.cfi_startproc
	movl	4(%esp), %eax
	pextrb	$0, %xmm0, (%eax)
	ret
	.cfi_endproc
LFE3575:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_02_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_02_aPcU8__vectorx:
LFB3577:
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
LFE3577:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_03_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_03_aPcU8__vectorx:
LFB3579:
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
LFE3579:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_04_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_04_aPcU8__vectorx:
LFB3581:
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
LFE3581:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_05_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_05_aPcU8__vectorx:
LFB3583:
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
LFE3583:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_06_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_06_aPcU8__vectorx:
LFB3585:
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
LFE3585:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_07_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_07_aPcU8__vectorx:
LFB3587:
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
LFE3587:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_08_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_08_aPcU8__vectorx:
LFB3589:
	.cfi_startproc
	movl	4(%esp), %eax
	movq	%xmm0, (%eax)
	ret
	.cfi_endproc
LFE3589:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_09_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_09_aPcU8__vectorx:
LFB3591:
	.cfi_startproc
	movl	4(%esp), %eax
	movq	%xmm0, (%eax)
	pextrb	$8, %xmm0, 8(%eax)
	ret
	.cfi_endproc
LFE3591:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_10_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_10_aPcU8__vectorx:
LFB3593:
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
LFE3593:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_11_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_11_aPcU8__vectorx:
LFB3595:
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
LFE3595:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_12_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_12_aPcU8__vectorx:
LFB3597:
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
LFE3597:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_13_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_13_aPcU8__vectorx:
LFB3599:
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
LFE3599:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_14_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_14_aPcU8__vectorx:
LFB3601:
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
LFE3601:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_15_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_15_aPcU8__vectorx:
LFB3603:
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
LFE3603:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_16_aPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_16_aPcU8__vectorx:
LFB3605:
	.cfi_startproc
	movl	4(%esp), %eax
	movdqa	%xmm0, (%eax)
	ret
	.cfi_endproc
LFE3605:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_:
LFB3844:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	8(%esp), %eax
	movl	%edx, (%eax)
	ret
	.cfi_endproc
LFE3844:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_:
LFB3851:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	addl	$1, (%eax)
	ret
	.cfi_endproc
LFE3851:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE_E9_M_invokeERKSt9_Any_data:
LFB3936:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%edx)
	ret
	.cfi_endproc
LFE3936:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE0_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE0_E9_M_invokeERKSt9_Any_data:
LFB3940:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%edx)
	ret
	.cfi_endproc
LFE3940:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE1_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE1_E9_M_invokeERKSt9_Any_data:
LFB3944:
	.cfi_startproc
	movl	__ZZ9setLambdaRiE14static_counter, %eax
	addl	$1, %eax
	movl	%eax, __ZZ9setLambdaRiE14static_counter
	ret
	.cfi_endproc
LFE3944:
	.p2align 4,,15
	.def	__ZL18_strcpy_fast_case0PcPKc;	.scl	3;	.type	32;	.endef
__ZL18_strcpy_fast_case0PcPKc:
LFB3609:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pxor	%xmm1, %xmm1
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %esi
	movl	36(%esp), %ebx
	movl	%esi, %edx
	jmp	L37
	.p2align 4,,7
L42:
	movdqa	%xmm0, (%edx)
	addl	$16, %ebx
	addl	$16, %edx
L37:
	movdqa	(%ebx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L42
	movl	%edx, (%esp)
	call	*__ZL17_memcpy_m128i_a_x+4(,%ecx,4)
	addl	$20, %esp
	.cfi_def_cfa_offset 12
	movl	%esi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3609:
	.p2align 4,,15
	.def	__ZL18_strcpy_fast_case2PcPKc;	.scl	3;	.type	32;	.endef
__ZL18_strcpy_fast_case2PcPKc:
LFB3611:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pxor	%xmm1, %xmm1
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %esi
	movl	36(%esp), %ebx
	movl	%esi, %edx
	jmp	L45
	.p2align 4,,7
L49:
	movdqa	%xmm0, (%edx)
	addl	$16, %ebx
	addl	$16, %edx
L45:
	movdqu	(%ebx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L49
	movl	%edx, (%esp)
	call	*__ZL17_memcpy_m128i_a_x+4(,%ecx,4)
	addl	$20, %esp
	.cfi_def_cfa_offset 12
	movl	%esi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3611:
	.p2align 4,,15
	.def	__ZL19_strncpy_fast_case0PcPKcj;	.scl	3;	.type	32;	.endef
__ZL19_strncpy_fast_case0PcPKcj:
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
	movl	36(%esp), %edx
	movl	40(%esp), %eax
	movl	32(%esp), %edi
	addl	%edx, %eax
	leal	-16(%eax), %esi
	movl	%edi, %ebx
	cmpl	%esi, %edx
	ja	L51
	pxor	%xmm1, %xmm1
	jmp	L54
	.p2align 4,,7
L52:
	addl	$16, %edx
	movdqa	%xmm0, (%ebx)
	addl	$16, %ebx
	cmpl	%edx, %esi
	jb	L51
L54:
	movdqa	(%edx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L52
	movl	%ecx, 12(%esp)
	movl	%ebx, (%esp)
	call	*__ZL17_memcpy_m128i_a_x(,%ecx,4)
	movl	12(%esp), %ecx
	movb	$0, (%ebx,%ecx)
L53:
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
L51:
	.cfi_restore_state
	subl	%edx, %eax
	je	L53
	movdqa	(%edx), %xmm0
	movl	%ebx, (%esp)
	call	*__ZL17_memcpy_m128i_a_x(,%eax,4)
	addl	$16, %esp
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
	.cfi_endproc
LFE3616:
	.p2align 4,,15
	.def	__ZL19_strncpy_fast_case2PcPKcj;	.scl	3;	.type	32;	.endef
__ZL19_strncpy_fast_case2PcPKcj:
LFB3618:
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
	movl	36(%esp), %edx
	movl	40(%esp), %eax
	movl	32(%esp), %edi
	addl	%edx, %eax
	leal	-16(%eax), %esi
	movl	%edi, %ebx
	cmpl	%esi, %edx
	ja	L61
	pxor	%xmm1, %xmm1
	jmp	L64
	.p2align 4,,7
L62:
	addl	$16, %edx
	movdqa	%xmm0, (%ebx)
	addl	$16, %ebx
	cmpl	%edx, %esi
	jb	L61
L64:
	movdqu	(%edx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L62
	movl	%ecx, 12(%esp)
	movl	%ebx, (%esp)
	call	*__ZL17_memcpy_m128i_a_x(,%ecx,4)
	movl	12(%esp), %ecx
	movb	$0, (%ebx,%ecx)
L63:
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
L61:
	.cfi_restore_state
	subl	%edx, %eax
	je	L63
	movdqu	(%edx), %xmm0
	movl	%ebx, (%esp)
	call	*__ZL17_memcpy_m128i_a_x(,%eax,4)
	addl	$16, %esp
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
	.cfi_endproc
LFE3618:
	.p2align 4,,15
	.def	__ZL18_strcmp_fast_case0PKcS0_;	.scl	3;	.type	32;	.endef
__ZL18_strcmp_fast_case0PKcS0_:
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
	jmp	L73
	.p2align 4,,7
L71:
	testl	%eax, %eax
	jne	L72
	addl	$16, %ebx
	addl	$16, %edx
L73:
	movdqa	(%edx), %xmm1
	movdqa	(%ebx), %xmm0
	pcmpistri	$26, %xmm1, %xmm0
	setc	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$0, %eax
	sete	%al
	testl	%esi, %esi
	je	L71
	movsbl	(%edx,%ecx), %eax
	movsbl	(%ebx,%ecx), %ebx
	subl	%eax, %ebx
	setne	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	sarl	$31, %ebx
	orl	%ebx, %esi
L72:
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
	.def	__ZL18_strcmp_fast_case1PKcS0_;	.scl	3;	.type	32;	.endef
__ZL18_strcmp_fast_case1PKcS0_:
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
	jmp	L78
	.p2align 4,,7
L76:
	testl	%eax, %eax
	jne	L77
	addl	$16, %ebx
	addl	$16, %edx
L78:
	movdqu	(%ebx), %xmm0
	movdqa	(%edx), %xmm1
	pcmpistri	$26, %xmm1, %xmm0
	setc	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$0, %eax
	sete	%al
	testl	%esi, %esi
	je	L76
	movsbl	(%edx,%ecx), %eax
	movsbl	(%ebx,%ecx), %ebx
	subl	%eax, %ebx
	setne	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	sarl	$31, %ebx
	orl	%ebx, %esi
L77:
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
	.def	__ZL18_strcmp_fast_case2PKcS0_;	.scl	3;	.type	32;	.endef
__ZL18_strcmp_fast_case2PKcS0_:
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
	jmp	L83
	.p2align 4,,7
L81:
	testl	%eax, %eax
	jne	L82
	addl	$16, %ebx
	addl	$16, %edx
L83:
	movdqu	(%edx), %xmm1
	movdqa	(%ebx), %xmm0
	pcmpistri	$26, %xmm1, %xmm0
	setc	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$0, %eax
	sete	%al
	testl	%esi, %esi
	je	L81
	movsbl	(%edx,%ecx), %eax
	movsbl	(%ebx,%ecx), %ebx
	subl	%eax, %ebx
	setne	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	sarl	$31, %ebx
	orl	%ebx, %esi
L82:
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
	.def	__ZL18_strcmp_fast_case3PKcS0_;	.scl	3;	.type	32;	.endef
__ZL18_strcmp_fast_case3PKcS0_:
LFB3555:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %ebx
	movl	16(%esp), %edx
	jmp	L88
	.p2align 4,,7
L86:
	testl	%eax, %eax
	jne	L87
	addl	$16, %ebx
	addl	$16, %edx
L88:
	movdqu	(%ebx), %xmm0
	movdqu	(%edx), %xmm1
	pcmpistri	$26, %xmm1, %xmm0
	setc	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$0, %eax
	sete	%al
	testl	%esi, %esi
	je	L86
	movsbl	(%edx,%ecx), %eax
	movsbl	(%ebx,%ecx), %ebx
	subl	%eax, %ebx
	setne	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	sarl	$31, %ebx
	orl	%ebx, %esi
L87:
	movl	%esi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3555:
	.p2align 4,,15
	.def	__ZL19_strncmp_fast_case0PKcS0_j;	.scl	3;	.type	32;	.endef
__ZL19_strncmp_fast_case0PKcS0_j:
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
	movl	20(%esp), %edx
	movl	28(%esp), %ebp
	movl	24(%esp), %ebx
	addl	%edx, %ebp
	leal	-16(%ebp), %edi
	cmpl	%edi, %edx
	jbe	L94
	jmp	L91
	.p2align 4,,7
L92:
	testl	%eax, %eax
	jne	L93
	addl	$16, %edx
	addl	$16, %ebx
	cmpl	%edx, %edi
	jb	L91
L94:
	movdqa	(%ebx), %xmm1
	movdqa	(%edx), %xmm0
	pcmpistri	$26, %xmm1, %xmm0
	setc	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$0, %eax
	sete	%al
	testl	%esi, %esi
	je	L92
	movsbl	(%ebx,%ecx), %eax
	movsbl	(%edx,%ecx), %edx
	subl	%eax, %edx
	setne	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	sarl	$31, %edx
	orl	%edx, %esi
L93:
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	movl	%esi, %eax
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
L91:
	.cfi_restore_state
	xorl	%esi, %esi
	subl	%edx, %ebp
	je	L93
	movdqa	(%edx), %xmm2
	pcmpistri	$26, (%ebx), %xmm2
	setc	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	jnc	L93
	xorl	%esi, %esi
	cmpl	%ecx, %ebp
	jbe	L93
	movsbl	(%ebx,%ecx), %eax
	movsbl	(%edx,%ecx), %edx
	subl	%eax, %edx
	setne	%al
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	%edx, %eax
	sarl	$31, %eax
	orl	%eax, %esi
	jmp	L93
	.cfi_endproc
LFE3557:
	.p2align 4,,15
	.def	__ZL19_strncmp_fast_case1PKcS0_j;	.scl	3;	.type	32;	.endef
__ZL19_strncmp_fast_case1PKcS0_j:
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
	movl	20(%esp), %eax
	movl	28(%esp), %edi
	movl	24(%esp), %edx
	addl	%eax, %edi
	leal	-16(%edi), %esi
	cmpl	%esi, %eax
	jbe	L107
	jmp	L103
	.p2align 4,,7
L104:
	testl	%ecx, %ecx
	jne	L108
	addl	$16, %eax
	addl	$16, %edx
	cmpl	%eax, %esi
	jb	L103
L107:
	movl	$0, %ebx
	movdqu	(%eax), %xmm0
	movdqa	(%edx), %xmm1
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %ebp
	setc	%bl
	movl	$0, %ecx
	sete	%cl
	testl	%ebx, %ebx
	je	L104
	movsbl	(%eax,%ebp), %ecx
	movsbl	(%edx,%ebp), %eax
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
	subl	%eax, %ecx
	setne	%al
	movzbl	%al, %eax
	sarl	$31, %ecx
	orl	%ecx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L103:
	.cfi_restore_state
	subl	%eax, %edi
	jne	L116
L108:
	xorl	%eax, %eax
L105:
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
L116:
	.cfi_restore_state
	movdqu	(%eax), %xmm0
	pcmpistri	$26, (%edx), %xmm0
	jnc	L108
	cmpl	%ecx, %edi
	jbe	L108
	movsbl	(%eax,%ecx), %ebx
	movsbl	(%edx,%ecx), %eax
	subl	%eax, %ebx
	setne	%al
	movl	%ebx, %edx
	movzbl	%al, %eax
	sarl	$31, %edx
	orl	%edx, %eax
	jmp	L105
	.cfi_endproc
LFE3558:
	.p2align 4,,15
	.def	__ZL19_strncmp_fast_case2PKcS0_j;	.scl	3;	.type	32;	.endef
__ZL19_strncmp_fast_case2PKcS0_j:
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
	movl	20(%esp), %eax
	movl	28(%esp), %edi
	movl	24(%esp), %edx
	addl	%eax, %edi
	leal	-16(%edi), %esi
	cmpl	%esi, %eax
	jbe	L122
	jmp	L118
	.p2align 4,,7
L119:
	testl	%ecx, %ecx
	jne	L123
	addl	$16, %eax
	addl	$16, %edx
	cmpl	%eax, %esi
	jb	L118
L122:
	movl	$0, %ebx
	movdqu	(%edx), %xmm1
	movdqa	(%eax), %xmm0
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %ebp
	setc	%bl
	movl	$0, %ecx
	sete	%cl
	testl	%ebx, %ebx
	je	L119
	movsbl	(%eax,%ebp), %ecx
	movsbl	(%edx,%ebp), %eax
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
	subl	%eax, %ecx
	setne	%al
	movzbl	%al, %eax
	sarl	$31, %ecx
	orl	%ecx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L118:
	.cfi_restore_state
	subl	%eax, %edi
	jne	L131
L123:
	xorl	%eax, %eax
L120:
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
L131:
	.cfi_restore_state
	movdqa	(%eax), %xmm2
	pcmpistri	$26, (%edx), %xmm2
	jnc	L123
	cmpl	%ecx, %edi
	jbe	L123
	movsbl	(%eax,%ecx), %ebx
	movsbl	(%edx,%ecx), %eax
	subl	%eax, %ebx
	setne	%al
	movl	%ebx, %edx
	movzbl	%al, %eax
	sarl	$31, %edx
	orl	%edx, %eax
	jmp	L120
	.cfi_endproc
LFE3559:
	.p2align 4,,15
	.def	__ZL19_strncmp_fast_case3PKcS0_j;	.scl	3;	.type	32;	.endef
__ZL19_strncmp_fast_case3PKcS0_j:
LFB3560:
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
	movl	20(%esp), %eax
	movl	28(%esp), %edi
	movl	24(%esp), %edx
	addl	%eax, %edi
	leal	-16(%edi), %esi
	cmpl	%esi, %eax
	jbe	L137
	jmp	L133
	.p2align 4,,7
L134:
	testl	%ecx, %ecx
	jne	L138
	addl	$16, %eax
	addl	$16, %edx
	cmpl	%eax, %esi
	jb	L133
L137:
	movl	$0, %ebx
	movdqu	(%eax), %xmm0
	movdqu	(%edx), %xmm1
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %ebp
	setc	%bl
	movl	$0, %ecx
	sete	%cl
	testl	%ebx, %ebx
	je	L134
	movsbl	(%eax,%ebp), %ecx
	movsbl	(%edx,%ebp), %eax
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
	subl	%eax, %ecx
	setne	%al
	movzbl	%al, %eax
	sarl	$31, %ecx
	orl	%ecx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L133:
	.cfi_restore_state
	subl	%eax, %edi
	jne	L146
L138:
	xorl	%eax, %eax
L135:
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
L146:
	.cfi_restore_state
	movdqu	(%eax), %xmm0
	pcmpistri	$26, (%edx), %xmm0
	jnc	L138
	cmpl	%ecx, %edi
	jbe	L138
	movsbl	(%eax,%ecx), %ebx
	movsbl	(%edx,%ecx), %eax
	subl	%eax, %ebx
	setne	%al
	movl	%ebx, %edx
	movzbl	%al, %eax
	sarl	$31, %edx
	orl	%edx, %eax
	jmp	L135
	.cfi_endproc
LFE3560:
	.p2align 4,,15
	.def	__ZL22_strstr_fast_cmp_case0PKcS0_;	.scl	3;	.type	32;	.endef
__ZL22_strstr_fast_cmp_case0PKcS0_:
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
	jmp	L151
	.p2align 4,,7
L148:
	testl	%ecx, %ecx
	jne	L153
	addl	$16, %edx
	addl	$16, %ebx
L151:
	movl	$0, %eax
	movdqa	(%ebx), %xmm1
	movdqa	(%edx), %xmm0
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %esi
	setc	%al
	movl	$0, %ecx
	sete	%cl
	testl	%eax, %eax
	je	L148
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
L153:
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
	.def	__ZL22_strstr_fast_cmp_case1PKcS0_;	.scl	3;	.type	32;	.endef
__ZL22_strstr_fast_cmp_case1PKcS0_:
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
	jmp	L159
	.p2align 4,,7
L156:
	testl	%ecx, %ecx
	jne	L161
	addl	$16, %edx
	addl	$16, %ebx
L159:
	movl	$0, %eax
	movdqu	(%edx), %xmm0
	movdqa	(%ebx), %xmm1
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %esi
	setc	%al
	movl	$0, %ecx
	sete	%cl
	testl	%eax, %eax
	je	L156
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
L161:
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
	.def	__ZL22_strstr_fast_cmp_case2PKcS0_;	.scl	3;	.type	32;	.endef
__ZL22_strstr_fast_cmp_case2PKcS0_:
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
	jmp	L167
	.p2align 4,,7
L164:
	testl	%ecx, %ecx
	jne	L169
	addl	$16, %edx
	addl	$16, %ebx
L167:
	movl	$0, %eax
	movdqu	(%ebx), %xmm1
	movdqa	(%edx), %xmm0
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %esi
	setc	%al
	movl	$0, %ecx
	sete	%cl
	testl	%eax, %eax
	je	L164
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
L169:
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
	.def	__ZL22_strstr_fast_cmp_case3PKcS0_;	.scl	3;	.type	32;	.endef
__ZL22_strstr_fast_cmp_case3PKcS0_:
LFB3568:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %edx
	movl	16(%esp), %ebx
	jmp	L175
	.p2align 4,,7
L172:
	testl	%ecx, %ecx
	jne	L177
	addl	$16, %edx
	addl	$16, %ebx
L175:
	movl	$0, %eax
	movdqu	(%edx), %xmm0
	movdqu	(%ebx), %xmm1
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %esi
	setc	%al
	movl	$0, %ecx
	sete	%cl
	testl	%eax, %eax
	je	L172
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
L177:
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
LFE3568:
	.p2align 4,,15
	.def	__ZL18_memcpy_m128i_16_uPcU8__vectorx;	.scl	3;	.type	32;	.endef
__ZL18_memcpy_m128i_16_uPcU8__vectorx:
LFB3606:
	.cfi_startproc
	movl	4(%esp), %eax
	movdqu	%xmm0, (%eax)
	ret
	.cfi_endproc
LFE3606:
	.p2align 4,,15
	.def	__ZL18_strcpy_fast_case1PcPKc;	.scl	3;	.type	32;	.endef
__ZL18_strcpy_fast_case1PcPKc:
LFB3610:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pxor	%xmm2, %xmm2
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %esi
	movl	36(%esp), %ebx
	movl	%esi, %edx
	jmp	L182
	.p2align 4,,7
L186:
	movdqu	%xmm0, (%edx)
	addl	$16, %ebx
	addl	$16, %edx
L182:
	movdqa	(%ebx), %xmm0
	pcmpistri	$10, %xmm0, %xmm2
	jne	L186
	movl	%edx, (%esp)
	call	*__ZL17_memcpy_m128i_u_x+4(,%ecx,4)
	addl	$20, %esp
	.cfi_def_cfa_offset 12
	movl	%esi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3610:
	.p2align 4,,15
	.def	__ZL18_strcpy_fast_case3PcPKc;	.scl	3;	.type	32;	.endef
__ZL18_strcpy_fast_case3PcPKc:
LFB3612:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pxor	%xmm1, %xmm1
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %esi
	movl	36(%esp), %ebx
	movl	%esi, %edx
	jmp	L189
	.p2align 4,,7
L193:
	movdqu	%xmm0, (%edx)
	addl	$16, %ebx
	addl	$16, %edx
L189:
	movdqu	(%ebx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L193
	movl	%edx, (%esp)
	call	*__ZL17_memcpy_m128i_u_x+4(,%ecx,4)
	addl	$20, %esp
	.cfi_def_cfa_offset 12
	movl	%esi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3612:
	.p2align 4,,15
	.def	__ZL19_strncpy_fast_case1PcPKcj;	.scl	3;	.type	32;	.endef
__ZL19_strncpy_fast_case1PcPKcj:
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
	movl	36(%esp), %edx
	movl	40(%esp), %eax
	movl	32(%esp), %edi
	addl	%edx, %eax
	leal	-16(%eax), %esi
	movl	%edi, %ebx
	cmpl	%esi, %edx
	ja	L195
	pxor	%xmm2, %xmm2
	jmp	L198
	.p2align 4,,7
L196:
	addl	$16, %edx
	movdqu	%xmm0, (%ebx)
	addl	$16, %ebx
	cmpl	%edx, %esi
	jb	L195
L198:
	movdqa	(%edx), %xmm0
	pcmpistri	$10, %xmm0, %xmm2
	jne	L196
	movl	%ecx, 12(%esp)
	movl	%ebx, (%esp)
	call	*__ZL17_memcpy_m128i_u_x(,%ecx,4)
	movl	12(%esp), %ecx
	movb	$0, (%ebx,%ecx)
L197:
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
L195:
	.cfi_restore_state
	subl	%edx, %eax
	je	L197
	movdqa	(%edx), %xmm0
	movl	%ebx, (%esp)
	call	*__ZL17_memcpy_m128i_u_x(,%eax,4)
	addl	$16, %esp
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
	.cfi_endproc
LFE3617:
	.p2align 4,,15
	.def	__ZL19_strncpy_fast_case3PcPKcj;	.scl	3;	.type	32;	.endef
__ZL19_strncpy_fast_case3PcPKcj:
LFB3619:
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
	movl	36(%esp), %edx
	movl	40(%esp), %eax
	movl	32(%esp), %edi
	addl	%edx, %eax
	leal	-16(%eax), %esi
	movl	%edi, %ebx
	cmpl	%esi, %edx
	ja	L205
	pxor	%xmm1, %xmm1
	jmp	L208
	.p2align 4,,7
L206:
	addl	$16, %edx
	movdqu	%xmm0, (%ebx)
	addl	$16, %ebx
	cmpl	%edx, %esi
	jb	L205
L208:
	movdqu	(%edx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L206
	movl	%ecx, 12(%esp)
	movl	%ebx, (%esp)
	call	*__ZL17_memcpy_m128i_u_x(,%ecx,4)
	movl	12(%esp), %ecx
	movb	$0, (%ebx,%ecx)
L207:
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
L205:
	.cfi_restore_state
	subl	%edx, %eax
	je	L207
	movdqu	(%edx), %xmm0
	movl	%ebx, (%esp)
	call	*__ZL17_memcpy_m128i_u_x(,%eax,4)
	addl	$16, %esp
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
	.cfi_endproc
LFE3619:
	.p2align 4,,15
	.def	__Z41__static_initialization_and_destruction_0ii.part.37;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii.part.37:
LFB4036:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4036
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L215
	movl	$3, 8(%esp)
	movl	$_s_lambda3, 4(%esp)
	movl	$_s_lambda3, (%esp)
	call	*%eax
L215:
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L216
	movl	$3, 8(%esp)
	movl	$_s_lambda2, 4(%esp)
	movl	$_s_lambda2, (%esp)
	call	*%eax
L216:
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L217
	movl	$3, 8(%esp)
	movl	$_s_lambda1, 4(%esp)
	movl	$_s_lambda1, (%esp)
	call	*%eax
L217:
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitD1Ev
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE4036:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA4036:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4036-LLSDACSB4036
LLSDACSB4036:
LLSDACSE4036:
	.text
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation:
LFB3846:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L230
	jle	L236
	cmpl	$2, %eax
	je	L233
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L229
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L229:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L233:
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
L236:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L229
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
L230:
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
LFE3846:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation:
LFB3852:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L239
	jle	L245
	cmpl	$2, %eax
	je	L242
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L238
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L238:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L242:
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
L245:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L238
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
L239:
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
LFE3852:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation:
LFB3937:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L248
	jle	L254
	cmpl	$2, %eax
	je	L251
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L247
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L247:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L251:
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
L254:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L247
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
L248:
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
LFE3937:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation:
LFB3941:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L257
	jle	L263
	cmpl	$2, %eax
	je	L260
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L256
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L256:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L260:
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
L263:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L256
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
L257:
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
LFE3941:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation:
LFB3945:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L266
	jle	L272
	cmpl	$2, %eax
	je	L269
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L265
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L265:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L269:
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
L272:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L265
	movl	32(%esp), %eax
	movl	$__ZTIZ9setLambdaRiEUlvE1_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L266:
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
LFE3945:
	.p2align 4,,15
	.globl	__Z22testOpt01_Type1_BeforeR11dataOpt01_t
	.def	__Z22testOpt01_Type1_BeforeR11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z22testOpt01_Type1_BeforeR11dataOpt01_t:
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
	movl	(%ebx), %esi
	andl	$15, %eax
	shrl	$2, %eax
	negl	%eax
	andl	$3, %eax
	je	L282
	addl	4(%ebx), %esi
	cmpl	$1, %eax
	jbe	L283
	addl	8(%ebx), %esi
	cmpl	$2, %eax
	jbe	L284
	addl	12(%ebx), %esi
	movl	$9997, 4(%esp)
	movl	$3, (%esp)
L274:
	movl	$10000, %edi
	pxor	%xmm0, %xmm0
	subl	%eax, %edi
	movl	%edi, %ecx
	shrl	$2, %ecx
	leal	4(%ebx,%eax,4), %edx
	xorl	%eax, %eax
	leal	0(,%ecx,4), %ebp
	.p2align 4,,7
L281:
	addl	$1, %eax
	addl	$16, %edx
	paddd	-16(%edx), %xmm0
	cmpl	%eax, %ecx
	ja	L281
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
	je	L279
	addl	4(%ebx,%edx,4), %eax
	cmpl	$1, %ecx
	leal	1(%edx), %esi
	je	L279
	addl	4(%ebx,%esi,4), %eax
	addl	$2, %edx
	cmpl	$2, %ecx
	je	L279
	addl	4(%ebx,%edx,4), %eax
L279:
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
L282:
	.cfi_restore_state
	movl	$10000, 4(%esp)
	movl	$0, (%esp)
	jmp	L274
	.p2align 4,,7
L283:
	movl	$9999, 4(%esp)
	movl	$1, (%esp)
	jmp	L274
	.p2align 4,,7
L284:
	movl	$9998, 4(%esp)
	movl	$2, (%esp)
	jmp	L274
	.cfi_endproc
LFE2672:
	.p2align 4,,15
	.globl	__Z22testOpt01_Type1_After1R11dataOpt01_t
	.def	__Z22testOpt01_Type1_After1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z22testOpt01_Type1_After1R11dataOpt01_t:
LFB2673:
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
	je	L300
	cmpl	$1, %eax
	movl	4(%ebx), %esi
	jbe	L301
	addl	8(%ebx), %esi
	cmpl	$2, %eax
	jbe	L302
	addl	12(%ebx), %esi
	movl	$9997, 4(%esp)
	movl	$3, (%esp)
L292:
	movl	$10000, %edi
	pxor	%xmm0, %xmm0
	subl	%eax, %edi
	movl	%edi, %ecx
	shrl	$2, %ecx
	leal	4(%ebx,%eax,4), %edx
	xorl	%eax, %eax
	leal	0(,%ecx,4), %ebp
	.p2align 4,,7
L299:
	addl	$1, %eax
	addl	$16, %edx
	paddd	-16(%edx), %xmm0
	cmpl	%eax, %ecx
	ja	L299
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
	je	L297
	addl	4(%ebx,%eax,4), %esi
	cmpl	$1, %edx
	leal	1(%eax), %ecx
	je	L297
	addl	4(%ebx,%ecx,4), %esi
	addl	$2, %eax
	cmpl	$2, %edx
	je	L297
	addl	4(%ebx,%eax,4), %esi
L297:
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
L300:
	.cfi_restore_state
	movl	$10000, 4(%esp)
	xorl	%esi, %esi
	movl	$0, (%esp)
	jmp	L292
	.p2align 4,,7
L301:
	movl	$9999, 4(%esp)
	movl	$1, (%esp)
	jmp	L292
	.p2align 4,,7
L302:
	movl	$9998, 4(%esp)
	movl	$2, (%esp)
	jmp	L292
	.cfi_endproc
LFE2673:
	.p2align 4,,15
	.globl	__Z22testOpt01_Type1_After2R11dataOpt01_t
	.def	__Z22testOpt01_Type1_After2R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z22testOpt01_Type1_After2R11dataOpt01_t:
LFB2674:
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
	ja	L330
L321:
	movl	%edi, %ebx
L310:
	cmpl	$1, %ebx
	movl	4(%eax), %edx
	jbe	L323
	addl	8(%eax), %edx
	cmpl	$2, %ebx
	leal	12(%eax), %ecx
	jbe	L312
	addl	12(%eax), %edx
	cmpl	$3, %ebx
	leal	16(%eax), %ecx
	jbe	L312
	addl	16(%eax), %edx
	cmpl	$4, %ebx
	leal	20(%eax), %ecx
	jbe	L312
	addl	20(%eax), %edx
	cmpl	$5, %ebx
	leal	24(%eax), %ecx
	jbe	L312
	addl	24(%eax), %edx
	cmpl	$6, %ebx
	leal	28(%eax), %ecx
	jbe	L312
	addl	28(%eax), %edx
	cmpl	$7, %ebx
	leal	32(%eax), %ecx
	jbe	L312
	addl	32(%eax), %edx
	leal	36(%eax), %ecx
L312:
	cmpl	%ebx, %edi
	je	L313
L311:
	subl	%ebx, %edi
	movl	%edi, %esi
	shrl	$2, %esi
	leal	0(,%esi,4), %ebp
	testl	%ebp, %ebp
	movl	%esi, 4(%esp)
	je	L314
	leal	4(%eax,%ebx,4), %esi
	xorl	%ebx, %ebx
	pxor	%xmm0, %xmm0
L320:
	paddd	(%esi), %xmm0
	addl	$1, %ebx
	addl	$16, %esi
	cmpl	%ebx, 4(%esp)
	ja	L320
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
	je	L313
L314:
	movl	(%esp), %esi
	leal	4(%ecx), %ebx
	addl	(%ecx), %edx
	cmpl	%ebx, %esi
	jbe	L313
	leal	8(%ecx), %ebx
	addl	4(%ecx), %edx
	cmpl	%ebx, %esi
	jbe	L313
	addl	8(%ecx), %edx
L313:
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
L330:
	.cfi_restore_state
	cmpl	(%esp), %esi
	ja	L321
	testl	%ebx, %ebx
	jne	L310
	xorl	%ebx, %ebx
	xorl	%edx, %edx
	.p2align 4,,2
	jmp	L311
	.p2align 4,,7
L323:
	movl	%ebp, %ecx
	jmp	L312
	.cfi_endproc
LFE2674:
	.p2align 4,,15
	.globl	__Z24testOpt01_Type1_AppendixR11dataOpt01_t
	.def	__Z24testOpt01_Type1_AppendixR11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z24testOpt01_Type1_AppendixR11dataOpt01_t:
LFB2675:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %ecx
	leal	4(%ecx), %eax
	leal	40004(%ecx), %ebx
	cmpl	%ebx, %eax
	je	L331
	movl	(%ecx), %edx
	.p2align 4,,7
L334:
	addl	(%eax), %edx
	addl	$4, %eax
	cmpl	%eax, %ebx
	movl	%edx, (%ecx)
	jne	L334
L331:
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2675:
	.p2align 4,,15
	.globl	__Z22testOpt02_Type1_BeforeR11dataOpt02_t
	.def	__Z22testOpt02_Type1_BeforeR11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z22testOpt02_Type1_BeforeR11dataOpt02_t:
LFB2677:
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
L338:
	movl	(%ecx,%eax,4), %edx
	addl	$1, %eax
	addl	$1, 4(%esp,%edx,8)
	cmpl	$10000, %eax
	jne	L338
	movl	4(%esp), %eax
	movl	%esp, %edx
	cmpl	%eax, 12(%esp)
	jle	L339
	movl	12(%esp), %eax
	leal	8(%esp), %edx
L339:
	cmpl	20(%esp), %eax
	jge	L340
	movl	20(%esp), %eax
	leal	16(%esp), %edx
L340:
	cmpl	28(%esp), %eax
	jge	L341
	movl	28(%esp), %eax
	leal	24(%esp), %edx
L341:
	cmpl	36(%esp), %eax
	jge	L342
	movl	36(%esp), %eax
	leal	32(%esp), %edx
L342:
	cmpl	44(%esp), %eax
	jge	L343
	movl	44(%esp), %eax
	leal	40(%esp), %edx
L343:
	cmpl	52(%esp), %eax
	jge	L344
	movl	52(%esp), %eax
	leal	48(%esp), %edx
L344:
	cmpl	60(%esp), %eax
	jge	L345
	movl	60(%esp), %eax
	leal	56(%esp), %edx
L345:
	cmpl	68(%esp), %eax
	jge	L346
	movl	68(%esp), %eax
	leal	64(%esp), %edx
L346:
	cmpl	76(%esp), %eax
	jge	L347
	movl	76(%esp), %eax
	leal	72(%esp), %edx
L347:
	cmpl	%eax, 84(%esp)
	jle	L348
	movl	84(%esp), %eax
	leal	80(%esp), %edx
L348:
	sall	$16, %eax
	orl	(%edx), %eax
	addl	$108, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2677:
	.p2align 4,,15
	.globl	__Z22testOpt02_Type1_After1R11dataOpt02_t
	.def	__Z22testOpt02_Type1_After1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z22testOpt02_Type1_After1R11dataOpt02_t:
LFB2678:
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
L353:
	movl	(%eax), %edx
	addl	$4, %eax
	addl	$1, 4(%esp,%edx,8)
	cmpl	%eax, %ecx
	ja	L353
	movl	4(%esp), %eax
	movl	%esp, %edx
	cmpl	%eax, 12(%esp)
	jle	L354
	movl	12(%esp), %eax
	leal	8(%esp), %edx
L354:
	cmpl	20(%esp), %eax
	jge	L355
	movl	20(%esp), %eax
	leal	16(%esp), %edx
L355:
	cmpl	28(%esp), %eax
	jge	L356
	movl	28(%esp), %eax
	leal	24(%esp), %edx
L356:
	cmpl	36(%esp), %eax
	jge	L357
	movl	36(%esp), %eax
	leal	32(%esp), %edx
L357:
	cmpl	44(%esp), %eax
	jge	L358
	movl	44(%esp), %eax
	leal	40(%esp), %edx
L358:
	cmpl	52(%esp), %eax
	jge	L359
	movl	52(%esp), %eax
	leal	48(%esp), %edx
L359:
	cmpl	60(%esp), %eax
	jge	L360
	movl	60(%esp), %eax
	leal	56(%esp), %edx
L360:
	cmpl	68(%esp), %eax
	jge	L361
	movl	68(%esp), %eax
	leal	64(%esp), %edx
L361:
	cmpl	76(%esp), %eax
	jge	L362
	movl	76(%esp), %eax
	leal	72(%esp), %edx
L362:
	cmpl	%eax, 84(%esp)
	jle	L364
	movl	84(%esp), %eax
	leal	80(%esp), %edx
L364:
	sall	$16, %eax
	orl	(%edx), %eax
	addl	$108, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2678:
	.p2align 4,,15
	.globl	__Z22testOpt02_Type1_After2R11dataOpt02_t
	.def	__Z22testOpt02_Type1_After2R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z22testOpt02_Type1_After2R11dataOpt02_t:
LFB2679:
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
	je	L379
	cmpl	$5, %ebx
	setbe	%bl
	cmpl	%edx, %ecx
	seta	%cl
	orl	%ecx, %ebx
	cmpb	$1, %bl
	sbbl	%ecx, %ecx
	cmpb	$-1, %cl
	jne	L379
	movl	%esp, %ecx
	xorl	%ebx, %ebx
	movdqa	LC5, %xmm3
	movdqa	LC4, %xmm0
	pxor	%xmm1, %xmm1
L374:
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
	jbe	L385
	movdqa	%xmm4, %xmm0
	jmp	L374
	.p2align 4,,7
L379:
	movl	%esp, %ecx
	xorl	%ebp, %ebp
L369:
	leal	8(%ecx), %ebx
	cmpl	%ebx, %edx
	leal	1(%ebp), %eax
	movl	%ebp, (%ecx)
	movl	$0, 4(%ecx)
	jbe	L372
	movl	%eax, 8(%ecx)
	leal	16(%ecx), %eax
	cmpl	%eax, %edx
	leal	2(%ebp), %ebx
	movl	$0, 12(%ecx)
	jbe	L372
	movl	%ebx, 16(%ecx)
	leal	24(%ecx), %ebx
	cmpl	%ebx, %edx
	leal	3(%ebp), %eax
	movl	$0, 20(%ecx)
	jbe	L372
	movl	%eax, 24(%ecx)
	leal	32(%ecx), %eax
	addl	$4, %ebp
	cmpl	%eax, %edx
	movl	$0, 28(%ecx)
	jbe	L372
	movl	%ebp, 32(%ecx)
	movl	$0, 36(%ecx)
L372:
	movl	128(%esp), %eax
	leal	40000(%eax), %ebx
	.p2align 4,,7
L376:
	movl	(%eax), %ecx
	addl	$4, %eax
	addl	$1, 4(%esp,%ecx,8)
	cmpl	%eax, %ebx
	ja	L376
	movl	4(%esp), %eax
	movl	%esp, %ebx
	.p2align 4,,7
L378:
	movl	4(%esi), %ecx
	cmpl	%eax, %ecx
	cmovg	%esi, %ebx
	cmpl	%ecx, %eax
	cmovl	%ecx, %eax
	addl	$8, %esi
	cmpl	%edx, %esi
	jb	L378
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
L385:
	.cfi_restore_state
	cmpl	%eax, %ebp
	leal	(%esp,%ebp,8), %ecx
	jne	L369
	jmp	L372
	.cfi_endproc
LFE2679:
	.p2align 4,,15
	.globl	__Z22testOpt03_Type1_Beforeiii
	.def	__Z22testOpt03_Type1_Beforeiii;	.scl	2;	.type	32;	.endef
__Z22testOpt03_Type1_Beforeiii:
LFB2680:
	.cfi_startproc
	movl	8(%esp), %eax
	imull	4(%esp), %eax
	addl	12(%esp), %eax
	ret
	.cfi_endproc
LFE2680:
	.p2align 4,,15
	.globl	__Z22testOpt03_Type2_Beforeiiiiiiii
	.def	__Z22testOpt03_Type2_Beforeiiiiiiii;	.scl	2;	.type	32;	.endef
__Z22testOpt03_Type2_Beforeiiiiiiii:
LFB2681:
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
LFE2681:
	.p2align 4,,15
	.globl	__Z22testOpt03_Type3_BeforeR11dataOpt03_t
	.def	__Z22testOpt03_Type3_BeforeR11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z22testOpt03_Type3_BeforeR11dataOpt03_t:
LFB3028:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3028
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
	jae	L491
	movl	%esi, %ebx
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %edx
	leal	32(%esp), %ebp
	jmp	L400
	.p2align 4,,7
L393:
	addl	$4, %ebx
	cmpl	%ebx, %edi
	jbe	L399
L492:
	movl	%eax, %edx
L400:
	movl	(%ebx), %ecx
	movl	%edx, %eax
	testl	%ecx, %ecx
	jne	L393
	testl	%edx, %edx
	je	L490
	movl	%ebx, 4(%esp)
	movl	%ebp, (%esp)
LEHB1:
	call	*44(%esp)
LEHE1:
	addl	$4, %ebx
	movl	40(%esp), %eax
	cmpl	%ebx, %edi
	ja	L492
L399:
	testl	%eax, %eax
	je	L401
L390:
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L401:
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
	jae	L493
	movl	80(%esp), %ebx
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %edx
	leal	32(%esp), %ebp
	jmp	L414
	.p2align 4,,7
L407:
	addl	$4, %ebx
	cmpl	%ebx, %edi
	jbe	L413
L494:
	movl	%eax, %edx
L414:
	cmpl	$1, (%ebx)
	movl	%edx, %eax
	jne	L407
	testl	%edx, %edx
	je	L490
	movl	%ebx, 4(%esp)
	movl	%ebp, (%esp)
LEHB3:
	call	*44(%esp)
LEHE3:
	addl	$4, %ebx
	movl	40(%esp), %eax
	cmpl	%ebx, %edi
	ja	L494
L413:
	testl	%eax, %eax
	je	L415
L404:
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L415:
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
	jae	L495
	movl	80(%esp), %ebx
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %edx
	leal	32(%esp), %ebp
	jmp	L428
	.p2align 4,,7
L421:
	addl	$4, %ebx
	cmpl	%ebx, %edi
	jbe	L427
L496:
	movl	%eax, %edx
L428:
	cmpl	$2, (%ebx)
	movl	%edx, %eax
	jne	L421
	testl	%edx, %edx
	je	L490
	movl	%ebx, 4(%esp)
	movl	%ebp, (%esp)
LEHB5:
	call	*44(%esp)
LEHE5:
	addl	$4, %ebx
	movl	40(%esp), %eax
	cmpl	%ebx, %edi
	ja	L496
L427:
	testl	%eax, %eax
	je	L429
L418:
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L429:
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
	jae	L497
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %edx
	leal	32(%esp), %ebp
	jmp	L442
	.p2align 4,,7
L435:
	addl	$4, %esi
	cmpl	%esi, %edi
	jbe	L441
L498:
	movl	%eax, %edx
L442:
	cmpl	$3, (%esi)
	movl	%edx, %eax
	jne	L435
	testl	%edx, %edx
	je	L490
	movl	%esi, 4(%esp)
	movl	%ebp, (%esp)
LEHB7:
	call	*44(%esp)
LEHE7:
	addl	$4, %esi
	movl	40(%esp), %eax
	cmpl	%esi, %edi
	ja	L498
L441:
	testl	%eax, %eax
	je	L443
L432:
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L443:
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
L490:
	.cfi_restore_state
LEHB8:
	call	__ZSt25__throw_bad_function_callv
LEHE8:
L491:
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %eax
	jmp	L390
L497:
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %eax
	jmp	L432
L495:
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %eax
	jmp	L418
L493:
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %eax
	jmp	L404
L453:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L440
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
L440:
	movl	%ebx, (%esp)
LEHB9:
	call	__Unwind_Resume
LEHE9:
L450:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L440
	movl	$3, 8(%esp)
	movl	%ebp, 4(%esp)
	movl	%ebp, (%esp)
	call	*%edx
	jmp	L440
L451:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L440
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L440
L448:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L440
	movl	$3, 8(%esp)
	movl	%ebp, 4(%esp)
	movl	%ebp, (%esp)
	call	*%edx
	jmp	L440
L449:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L440
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L440
L454:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L440
	movl	$3, 8(%esp)
	movl	%ebp, 4(%esp)
	movl	%ebp, (%esp)
	call	*%edx
	jmp	L440
L455:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L440
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L440
L452:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L440
	movl	$3, 8(%esp)
	movl	%ebp, 4(%esp)
	movl	%ebp, (%esp)
	call	*%edx
	jmp	L440
	.cfi_endproc
LFE3028:
	.section	.gcc_except_table,"w"
LLSDA3028:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3028-LLSDACSB3028
LLSDACSB3028:
	.uleb128 LEHB0-LFB3028
	.uleb128 LEHE0-LEHB0
	.uleb128 L449-LFB3028
	.uleb128 0
	.uleb128 LEHB1-LFB3028
	.uleb128 LEHE1-LEHB1
	.uleb128 L448-LFB3028
	.uleb128 0
	.uleb128 LEHB2-LFB3028
	.uleb128 LEHE2-LEHB2
	.uleb128 L451-LFB3028
	.uleb128 0
	.uleb128 LEHB3-LFB3028
	.uleb128 LEHE3-LEHB3
	.uleb128 L450-LFB3028
	.uleb128 0
	.uleb128 LEHB4-LFB3028
	.uleb128 LEHE4-LEHB4
	.uleb128 L453-LFB3028
	.uleb128 0
	.uleb128 LEHB5-LFB3028
	.uleb128 LEHE5-LEHB5
	.uleb128 L452-LFB3028
	.uleb128 0
	.uleb128 LEHB6-LFB3028
	.uleb128 LEHE6-LEHB6
	.uleb128 L455-LFB3028
	.uleb128 0
	.uleb128 LEHB7-LFB3028
	.uleb128 LEHE7-LEHB7
	.uleb128 L454-LFB3028
	.uleb128 0
	.uleb128 LEHB8-LFB3028
	.uleb128 LEHE8-LEHB8
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB9-LFB3028
	.uleb128 LEHE9-LEHB9
	.uleb128 0
	.uleb128 0
LLSDACSE3028:
	.text
	.p2align 4,,15
	.globl	__Z21testOpt03_Type3_AfterR11dataOpt03_t
	.def	__Z21testOpt03_Type3_AfterR11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z21testOpt03_Type3_AfterR11dataOpt03_t:
LFB3036:
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
	jae	L510
	movl	%ebp, %ecx
	movl	%ebp, %eax
	.p2align 4,,7
L503:
	movl	(%eax), %ebx
	testl	%ebx, %ebx
	jne	L501
	movl	$1, (%eax)
L501:
	addl	$4, %eax
	cmpl	%eax, %edx
	ja	L503
	movl	%ebp, %ebx
	xorl	%esi, %esi
	.p2align 4,,7
L505:
	cmpl	$1, (%ebx)
	leal	1(%esi), %edi
	cmove	%edi, %esi
	addl	$4, %ebx
	cmpl	%ebx, %edx
	ja	L505
	movl	%ebp, %eax
	xorl	%ebx, %ebx
	.p2align 4,,7
L507:
	cmpl	$2, (%eax)
	leal	1(%ebx), %edi
	cmove	%edi, %ebx
	addl	$4, %eax
	cmpl	%eax, %edx
	ja	L507
	addl	%ebx, %esi
	xorl	%eax, %eax
	.p2align 4,,7
L509:
	cmpl	$3, (%ecx)
	leal	1(%eax), %edi
	cmove	%edi, %eax
	addl	$4, %ecx
	cmpl	%ecx, %edx
	ja	L509
	addl	%esi, %eax
L511:
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
L510:
	.cfi_restore_state
	xorl	%eax, %eax
	jmp	L511
	.cfi_endproc
LFE3036:
	.p2align 4,,15
	.globl	__Z22testOpt04_Type1_BeforeR11dataOpt04_t
	.def	__Z22testOpt04_Type1_BeforeR11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type1_BeforeR11dataOpt04_t:
LFB3042:
	.cfi_startproc
	movl	4(%esp), %eax
	fldz
	leal	80000(%eax), %ecx
	movl	%eax, %edx
	.p2align 4,,7
L515:
	fildl	(%edx)
	addl	$8, %edx
	cmpl	%edx, %ecx
	faddp	%st, %st(1)
	ja	L515
	.p2align 4,,7
L517:
	fildl	(%eax)
	addl	$8, %eax
	fdiv	%st(1), %st
	fstps	-4(%eax)
	cmpl	%eax, %ecx
	ja	L517
	fstp	%st(0)
	ret
	.cfi_endproc
LFE3042:
	.p2align 4,,15
	.globl	__Z22testOpt04_Type1_After1R11dataOpt04_t
	.def	__Z22testOpt04_Type1_After1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type1_After1R11dataOpt04_t:
LFB3043:
	.cfi_startproc
	movl	4(%esp), %eax
	fldz
	leal	80000(%eax), %ecx
	movl	%eax, %edx
	.p2align 4,,7
L520:
	fildl	(%edx)
	addl	$8, %edx
	cmpl	%edx, %ecx
	faddp	%st, %st(1)
	ja	L520
	fdivrs	LC8
	.p2align 4,,7
L522:
	fildl	(%eax)
	addl	$8, %eax
	fmul	%st(1), %st
	fstps	-4(%eax)
	cmpl	%eax, %ecx
	ja	L522
	fstp	%st(0)
	ret
	.cfi_endproc
LFE3043:
	.p2align 4,,15
	.globl	__Z22testOpt04_Type1_After2R11dataOpt04_t
	.def	__Z22testOpt04_Type1_After2R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type1_After2R11dataOpt04_t:
LFB3044:
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
	je	L534
	cmpl	$10, %ecx
	setbe	%cl
	cmpl	%edi, %edx
	setb	%al
	movl	%eax, %edi
	orl	%edi, %ecx
	cmpb	$1, %cl
	sbbl	%ecx, %ecx
	cmpb	$-1, %cl
	jne	L534
	movl	%ebx, %ecx
	xorl	%edi, %edi
	pxor	%xmm0, %xmm0
	movl	%ebx, %eax
L531:
	movdqu	(%ecx), %xmm1
	movdqu	16(%ecx), %xmm2
	addl	$1, %edi
	shufps	$136, %xmm2, %xmm1
	addl	$32, %ecx
	cmpl	%edi, %esi
	paddd	%xmm1, %xmm0
	ja	L531
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
	je	L529
L525:
	leal	8(%ebx), %esi
	addl	(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L529
	leal	16(%ebx), %esi
	addl	8(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L529
	leal	24(%ebx), %esi
	addl	16(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L529
	leal	32(%ebx), %esi
	addl	24(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L529
	leal	40(%ebx), %esi
	addl	32(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L529
	leal	48(%ebx), %esi
	addl	40(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L529
	leal	56(%ebx), %esi
	addl	48(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L529
	leal	64(%ebx), %esi
	addl	56(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L529
	leal	72(%ebx), %esi
	addl	64(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L529
	addl	72(%ebx), %ecx
L529:
	movl	%ecx, 8(%esp)
	movl	(%esp), %eax
	fildl	8(%esp)
	fdivrs	LC8
	.p2align 4,,7
L533:
	fildl	(%eax)
	addl	$8, %eax
	fmul	%st(1), %st
	fstps	-4(%eax)
	cmpl	%eax, %edx
	ja	L533
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
L534:
	.cfi_restore_state
	xorl	%ecx, %ecx
	jmp	L525
	.cfi_endproc
LFE3044:
	.p2align 4,,15
	.globl	__Z22testOpt05_Type1_BeforeiRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_
	.def	__Z22testOpt05_Type1_BeforeiRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_;	.scl	2;	.type	32;	.endef
__Z22testOpt05_Type1_BeforeiRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_:
LFB3048:
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
LFE3048:
	.p2align 4,,15
	.globl	__Z21testOpt05_Type1_AfteriRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_
	.def	__Z21testOpt05_Type1_AfteriRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_;	.scl	2;	.type	32;	.endef
__Z21testOpt05_Type1_AfteriRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_:
LFB3525:
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
LFE3525:
	.p2align 4,,15
	.globl	__Z22testOpt06_Type1_BeforeR11dataOpt06_tfff
	.def	__Z22testOpt06_Type1_BeforeR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
__Z22testOpt06_Type1_BeforeR11dataOpt06_tfff:
LFB3527:
	.cfi_startproc
	movl	4(%esp), %eax
	flds	8(%esp)
	flds	12(%esp)
	flds	16(%esp)
	leal	80000(%eax), %edx
	.p2align 4,,7
L545:
	flds	(%eax)
	addl	$8, %eax
	fmul	%st(3), %st
	fmul	%st(2), %st
	fdiv	%st(1), %st
	fstps	-4(%eax)
	cmpl	%eax, %edx
	ja	L545
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	ret
	.cfi_endproc
LFE3527:
	.p2align 4,,15
	.globl	__Z21testOpt06_Type1_AfterR11dataOpt06_tfff
	.def	__Z21testOpt06_Type1_AfterR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
__Z21testOpt06_Type1_AfterR11dataOpt06_tfff:
LFB3528:
	.cfi_startproc
	flds	12(%esp)
	fmuls	8(%esp)
	movl	4(%esp), %eax
	leal	80000(%eax), %edx
	fdivs	16(%esp)
	.p2align 4,,7
L548:
	flds	(%eax)
	addl	$8, %eax
	fmul	%st(1), %st
	fstps	-4(%eax)
	cmpl	%eax, %edx
	ja	L548
	fstp	%st(0)
	ret
	.cfi_endproc
LFE3528:
	.p2align 4,,15
	.globl	__Z12addMatrixOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_S4_
	.def	__Z12addMatrixOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_S4_;	.scl	2;	.type	32;	.endef
__Z12addMatrixOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_S4_:
LFB3534:
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
LFE3534:
	.p2align 4,,15
	.globl	__Z18mulMatrixScalarOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_f
	.def	__Z18mulMatrixScalarOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_f;	.scl	2;	.type	32;	.endef
__Z18mulMatrixScalarOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_f:
LFB3536:
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
LFE3536:
	.p2align 4,,15
	.globl	__Z12mulMatrixOptILj4ELj4ELj4EEvR6matrixIXT_EXT0_EERKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	.def	__Z12mulMatrixOptILj4ELj4ELj4EEvR6matrixIXT_EXT0_EERKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
__Z12mulMatrixOptILj4ELj4ELj4EEvR6matrixIXT_EXT0_EERKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE:
LFB3538:
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
LFE3538:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strlen_BeforeiPKc
	.def	__Z29testOpt07_Type2_strlen_BeforeiPKc;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strlen_BeforeiPKc:
LFB3540:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	%eax, 4(%esp)
	jmp	_strlen
	.cfi_endproc
LFE3540:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	.def	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_:
LFB3541:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	_strcmp
	.cfi_endproc
LFE3541:
	.p2align 4,,15
	.globl	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	.def	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j;	.scl	2;	.type	32;	.endef
__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j:
LFB3542:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	16(%esp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	jmp	_strncmp
	.cfi_endproc
LFE3542:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	.def	__Z29testOpt07_Type2_strchr_BeforeiPKcc;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strchr_BeforeiPKcc:
LFB3543:
	.cfi_startproc
	movl	8(%esp), %eax
	movsbl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	_strchr
	.cfi_endproc
LFE3543:
	.p2align 4,,15
	.globl	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	.def	__Z30testOpt07_Type2_strrchr_BeforeiPKcc;	.scl	2;	.type	32;	.endef
__Z30testOpt07_Type2_strrchr_BeforeiPKcc:
LFB3544:
	.cfi_startproc
	movl	8(%esp), %eax
	movsbl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	_strrchr
	.cfi_endproc
LFE3544:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	.def	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strstr_BeforeiPKcS0_:
LFB3545:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	_strstr
	.cfi_endproc
LFE3545:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc
	.def	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strcpy_BeforeiPcPKc:
LFB3546:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	_strcpy
	.cfi_endproc
LFE3546:
	.p2align 4,,15
	.globl	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	.def	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj;	.scl	2;	.type	32;	.endef
__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj:
LFB3547:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	16(%esp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	jmp	_strncpy
	.cfi_endproc
LFE3547:
	.p2align 4,,15
	.globl	__Z12_strlen_fastPKc
	.def	__Z12_strlen_fastPKc;	.scl	2;	.type	32;	.endef
__Z12_strlen_fastPKc:
LFB3548:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %ebx
	movl	%ebx, %esi
	movl	%ebx, %edx
	andl	$15, %esi
	jne	L570
L562:
	pxor	%xmm0, %xmm0
	jmp	L566
	.p2align 4,,7
L564:
	addl	$16, %edx
L566:
	pcmpistri	$10, (%edx), %xmm0
	jne	L564
	subl	%ebx, %edx
	leal	(%edx,%ecx), %eax
L565:
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L570:
	.cfi_restore_state
	pxor	%xmm0, %xmm0
	pcmpistri	$10, (%ebx), %xmm0
	movl	%ecx, %eax
	je	L565
	movl	%ebx, %eax
	subl	%esi, %eax
	leal	16(%eax), %edx
	jmp	L562
	.cfi_endproc
LFE3548:
	.p2align 4,,15
	.globl	__Z13_strnlen_fastPKcj
	.def	__Z13_strnlen_fastPKcj;	.scl	2;	.type	32;	.endef
__Z13_strnlen_fastPKcj:
LFB3549:
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
	movl	20(%esp), %esi
	movl	24(%esp), %eax
	movl	%esi, %ebp
	movl	%esi, %edx
	leal	(%esi,%eax), %edi
	andl	$15, %ebp
	leal	-16(%edi), %ebx
	jne	L584
L572:
	cmpl	%ebx, %edx
	ja	L575
	pxor	%xmm0, %xmm0
	jmp	L577
	.p2align 4,,7
L576:
	addl	$16, %edx
	cmpl	%edx, %ebx
	jb	L575
L577:
	pcmpistri	$10, (%edx), %xmm0
	jne	L576
	subl	%esi, %edx
	leal	(%edx,%ecx), %eax
L574:
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
L575:
	.cfi_restore_state
	cmpl	%edx, %edi
	jbe	L574
	pxor	%xmm0, %xmm0
	pcmpistri	$10, (%edx), %xmm0
	jne	L574
	subl	%esi, %edx
	addl	%ecx, %edx
	cmpl	%eax, %edx
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	cmovbe	%edx, %eax
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
L584:
	.cfi_restore_state
	pxor	%xmm0, %xmm0
	pcmpistri	$10, (%esi), %xmm0
	jne	L573
	cmpl	%eax, %ecx
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	cmovbe	%ecx, %eax
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
L573:
	.cfi_restore_state
	movl	%esi, %edx
	subl	%ebp, %edx
	addl	$16, %edx
	jmp	L572
	.cfi_endproc
LFE3549:
	.p2align 4,,15
	.globl	__Z12_strcmp_fastPKcS0_
	.def	__Z12_strcmp_fastPKcS0_;	.scl	2;	.type	32;	.endef
__Z12_strcmp_fastPKcS0_:
LFB3556:
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
LFE3556:
	.p2align 4,,15
	.globl	__Z13_strncmp_fastPKcS0_j
	.def	__Z13_strncmp_fastPKcS0_j;	.scl	2;	.type	32;	.endef
__Z13_strncmp_fastPKcS0_j:
LFB3561:
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
LFE3561:
	.p2align 4,,15
	.globl	__Z12_strchr_fastPKcc
	.def	__Z12_strchr_fastPKcc;	.scl	2;	.type	32;	.endef
__Z12_strchr_fastPKcc:
LFB3562:
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
	je	L599
	jmp	L606
	.p2align 4,,7
L598:
	testl	%ebx, %ebx
	jne	L597
	addl	$16, %eax
L599:
	movl	$0, %edx
	movdqa	(%eax), %xmm0
	movl	$0, %ebx
	pcmpistri	$10, %xmm0, %xmm1
	setc	%dl
	sete	%bl
	testl	%edx, %edx
	je	L598
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
L597:
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
L606:
	.cfi_restore_state
	movl	$0, %ebx
	movdqu	(%eax), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	movl	%ecx, %esi
	setc	%bl
	movl	$0, %ecx
	sete	%cl
	testl	%ebx, %ebx
	jne	L605
	testl	%ecx, %ecx
	jne	L597
	subl	%edx, %eax
	addl	$16, %eax
	jmp	L599
	.p2align 4,,7
L605:
	addl	%esi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3562:
	.p2align 4,,15
	.globl	__Z13_strrchr_fastPKcc
	.def	__Z13_strrchr_fastPKcc;	.scl	2;	.type	32;	.endef
__Z13_strrchr_fastPKcc:
LFB3563:
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
	je	L612
	jmp	L621
	.p2align 4,,7
L620:
	addl	$16, %edx
L612:
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
	je	L620
L610:
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
L621:
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
	jne	L610
	subl	%eax, %edx
	addl	$16, %edx
	jmp	L612
	.cfi_endproc
LFE3563:
	.p2align 4,,15
	.globl	__Z12_strstr_fastPKcS0_
	.def	__Z12_strstr_fastPKcS0_;	.scl	2;	.type	32;	.endef
__Z12_strstr_fastPKcS0_:
LFB3570:
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
	je	L623
	movzbl	1(%ebp), %eax
	testb	%al, %al
	movb	%al, 16(%esp)
	jne	L624
	cmpb	$0, (%edi)
	je	L630
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
L739:
	.cfi_restore_state
	movl	$0, %esi
	movdqu	(%edi), %xmm1
	pcmpistrm	$10, %xmm1, %xmm2
	movl	%esi, %eax
	movdqa	%xmm0, 32(%esp)
	sete	%al
	movl	%eax, %esi
	jnc	L632
	movl	32(%esp), %eax
	testl	%eax, %eax
	je	L632
	movl	%edi, %ecx
	movl	%ebx, %ebp
	jmp	L635
	.p2align 4,,7
L633:
	addl	$1, %ecx
	shrl	%eax
	je	L738
L635:
	testb	$1, %al
	je	L633
	cmpb	(%ecx), %dl
	.p2align 4,,2
	jne	L633
	movzbl	16(%esp), %ebx
	cmpb	1(%ecx), %bl
	jne	L633
	movl	%ecx, %edi
	.p2align 4,,7
L623:
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
L624:
	.cfi_restore_state
	cmpb	$0, 2(%ebp)
	jne	L626
	cmpb	$0, (%edi)
	je	L630
	cmpb	$0, 1(%edi)
	je	L630
	movl	%edi, %ebx
	movd	%edx, %xmm2
	pxor	%xmm0, %xmm0
	andl	$15, %ebx
	pshufb	%xmm0, %xmm2
	jne	L739
	movzbl	16(%esp), %esi
	.p2align 4,,7
L641:
	movl	$0, %ebp
	movdqa	(%edi), %xmm1
	pcmpistrm	$10, %xmm1, %xmm2
	movl	%ebp, %eax
	movdqa	%xmm0, 16(%esp)
	sete	%al
	movl	%eax, %ebp
	jnc	L638
	movl	16(%esp), %ecx
	testl	%ecx, %ecx
	je	L638
	movl	%edi, %eax
	jmp	L640
	.p2align 4,,7
L639:
	addl	$1, %eax
	shrl	%ecx
	je	L638
L640:
	testb	$1, %cl
	je	L639
	cmpb	(%eax), %dl
	jne	L639
	movl	%esi, %ebx
	cmpb	1(%eax), %bl
	jne	L639
	movl	%eax, %edi
	.p2align 4,,2
	jmp	L623
	.p2align 4,,7
L630:
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
L626:
	.cfi_restore_state
	movl	%edi, %eax
	movd	%edx, %xmm2
	pxor	%xmm0, %xmm0
	andl	$15, %eax
	pshufb	%xmm0, %xmm2
	movl	%eax, 32(%esp)
	jne	L740
L642:
	movl	%ebp, %eax
	movl	%ebp, 48(%esp)
	movzbl	16(%esp), %ebp
	andl	$15, %eax
	movl	%eax, 32(%esp)
	.p2align 4,,7
L665:
	movl	$0, %ecx
	movdqa	(%edi), %xmm1
	pcmpistrm	$10, %xmm1, %xmm2
	movdqa	%xmm0, 16(%esp)
	sete	%cl
	jnc	L654
	movl	16(%esp), %ebx
	testl	%ebx, %ebx
	je	L654
	movl	32(%esp), %eax
	movl	%edi, %esi
	testl	%eax, %eax
	jne	L664
	jmp	L660
	.p2align 4,,7
L657:
	addl	$1, %esi
	shrl	%ebx
	je	L654
L660:
	testb	$1, %bl
	.p2align 4,,3
	je	L657
	cmpb	(%esi), %dl
	jne	L657
	movl	%ebp, %eax
	cmpb	1(%esi), %al
	jne	L657
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
	je	L657
L658:
	xorl	%edi, %edi
	cmpl	$1, %eax
	cmove	%esi, %edi
	jmp	L623
	.p2align 4,,7
L741:
	movl	%ebp, %eax
	cmpb	1(%esi), %al
	jne	L661
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
	jne	L658
	.p2align 4,,7
L661:
	addl	$1, %esi
	shrl	%ebx
	je	L654
L664:
	testb	$1, %bl
	je	L661
	cmpb	(%esi), %dl
	je	L741
	addl	$1, %esi
	shrl	%ebx
	jne	L664
	.p2align 4,,7
L654:
	testl	%ecx, %ecx
	jne	L630
	addl	$16, %edi
	jmp	L665
	.p2align 4,,7
L638:
	testl	%ebp, %ebp
	jne	L630
	addl	$16, %edi
	.p2align 4,,3
	jmp	L641
L740:
	movl	$0, %ecx
	movdqu	(%edi), %xmm1
	pcmpistrm	$10, %xmm1, %xmm2
	movdqa	%xmm0, 48(%esp)
	sete	%cl
	jnc	L643
	movl	48(%esp), %ebx
	testl	%ebx, %ebx
	je	L643
	testl	$15, %ebp
	movl	%edi, %esi
	jne	L653
	jmp	L649
	.p2align 4,,7
L646:
	addl	$1, %esi
	shrl	%ebx
	je	L643
L649:
	testb	$1, %bl
	.p2align 4,,3
	je	L646
	cmpb	(%esi), %dl
	jne	L646
	movzbl	16(%esp), %eax
	cmpb	1(%esi), %al
	jne	L646
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
	je	L646
	jmp	L658
L743:
	movzbl	16(%esp), %eax
	cmpb	1(%esi), %al
	jne	L650
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
	jne	L658
	.p2align 4,,7
L650:
	addl	$1, %esi
	shrl	%ebx
	je	L643
L653:
	testb	$1, %bl
	je	L650
	cmpb	(%esi), %dl
	jne	L650
	.p2align 4,,6
	jmp	L743
L643:
	testl	%ecx, %ecx
	.p2align 4,,7
	jne	L630
	subl	32(%esp), %edi
	addl	$16, %edi
	.p2align 4,,2
	jmp	L642
L738:
	movl	%ebp, %ebx
L632:
	testl	%esi, %esi
	jne	L630
	subl	%ebx, %edi
	movzbl	16(%esp), %esi
	addl	$16, %edi
	jmp	L641
	.cfi_endproc
LFE3570:
	.p2align 4,,15
	.globl	__Z14_strstrbm_fastPKcS0_
	.def	__Z14_strstrbm_fastPKcS0_;	.scl	2;	.type	32;	.endef
__Z14_strstrbm_fastPKcS0_:
LFB3571:
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
	subl	$1084, %esp
	.cfi_def_cfa_offset 1104
	movl	1108(%esp), %ebx
	movl	1104(%esp), %edi
	movl	%ebx, (%esp)
	call	__Z12_strlen_fastPKc
	movl	%eax, %esi
	movsbl	(%ebx), %eax
	testb	%al, %al
	je	L764
	cmpb	$0, 1(%ebx)
	jne	L746
	cmpb	$0, (%edi)
	je	L768
	movl	%edi, 1104(%esp)
	movl	%eax, 1108(%esp)
	addl	$1084, %esp
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
	.p2align 4,,7
L764:
	.cfi_restore_state
	movl	%edi, %eax
L745:
	addl	$1084, %esp
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
L746:
	.cfi_restore_state
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	call	__Z13_strnlen_fastPKcj
	cmpl	%eax, %esi
	ja	L768
	movl	%esi, 16(%esp)
	leal	48(%esp), %edx
	leal	1072(%esp), %ecx
	movd	16(%esp), %xmm3
	pshufd	$0, %xmm3, %xmm0
	.p2align 4,,7
L750:
	movdqa	%xmm0, (%edx)
	addl	$16, %edx
	cmpl	%ecx, %edx
	jne	L750
	testl	%esi, %esi
	je	L765
	leal	-1(%esi), %eax
	movl	%ebx, %edx
	leal	(%ebx,%esi), %ebp
	movl	%eax, %esi
	.p2align 4,,7
L752:
	movsbl	(%edx), %ecx
	addl	$1, %edx
	movl	%esi, 48(%esp,%ecx,4)
	subl	$1, %esi
	cmpl	%ebp, %edx
	jne	L752
L751:
	leal	(%ebx,%eax), %ebp
	addl	%edi, %eax
	pxor	%xmm0, %xmm0
	movzbl	0(%ebp), %ecx
	leal	-1(%ebp), %edi
	movl	%edi, 44(%esp)
	movb	%cl, 16(%esp)
	movd	16(%esp), %xmm2
	pshufb	%xmm0, %xmm2
L753:
	movl	$0, %edi
	movdqu	(%eax), %xmm1
	pcmpistrm	$10, %xmm1, %xmm2
	movl	%edi, %ecx
	movdqa	%xmm0, 16(%esp)
	sete	%cl
	movl	%ecx, %edi
	jnc	L754
	movl	16(%esp), %esi
L776:
	testl	%esi, %esi
	je	L755
	testl	$1, %esi
	je	L756
	movzbl	-1(%ebp), %edx
	leal	-1(%eax), %ecx
	cmpb	%dl, -1(%eax)
	jne	L757
	movl	44(%esp), %edx
	cmpl	%edx, %ebx
	je	L767
	movl	%eax, 16(%esp)
	jmp	L759
	.p2align 4,,7
L760:
	cmpl	%edx, %ebx
	je	L767
L759:
	subl	$1, %ecx
	subl	$1, %edx
	movzbl	(%ecx), %eax
	cmpb	%al, (%edx)
	je	L760
	movl	16(%esp), %eax
L757:
	movzbl	1(%eax), %edx
	shrl	%esi
	movl	48(%esp,%edx,4), %ecx
	leal	1(%eax,%ecx), %eax
	shrl	%cl, %esi
	jmp	L776
	.p2align 4,,7
L756:
	shrl	%esi
	addl	$1, %eax
	jmp	L776
	.p2align 4,,7
L754:
	testl	%edi, %edi
	jne	L768
	addl	$16, %eax
	jmp	L753
	.p2align 4,,7
L767:
	addl	$1084, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	%ecx, %eax
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
L755:
	.cfi_restore_state
	testl	%edi, %edi
	je	L753
	.p2align 4,,7
L768:
	xorl	%eax, %eax
	jmp	L745
L765:
	movl	$-1, %eax
	.p2align 4,,2
	jmp	L751
	.cfi_endproc
LFE3571:
	.p2align 4,,15
	.globl	__Z13_strstr0_fastPKcS0_
	.def	__Z13_strstr0_fastPKcS0_;	.scl	2;	.type	32;	.endef
__Z13_strstr0_fastPKcS0_:
LFB3572:
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
LFE3572:
	.p2align 4,,15
	.globl	__Z12_strcpy_fastPcPKc
	.def	__Z12_strcpy_fastPcPKc;	.scl	2;	.type	32;	.endef
__Z12_strcpy_fastPcPKc:
LFB3613:
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
LFE3613:
	.p2align 4,,15
	.globl	__Z13_strncpy_fastPcPKcj
	.def	__Z13_strncpy_fastPcPKcj;	.scl	2;	.type	32;	.endef
__Z13_strncpy_fastPcPKcj:
LFB3620:
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
LFE3620:
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
	.ascii "\343\201\202\343\201\204\343\201\206\343\201\210\343\201\212\0"
	.align 4
LC67:
	.ascii "123a\343\201\202"
	.ascii "123b\343\201\202\343\201\204"
	.ascii "123c\343\201\202\343\201\204\343\201\206"
	.ascii "123d\343\201\202\343\201\204\343\201\206\343\201\210"
	.ascii "123e\343\201\204\343\201\206\343\201\210\343\201\212"
	.ascii "123f\343\201\202\343\201\204\343\201\206\343\201\210\343\201\212\343\201\213"
	.ascii "123x\0"
LC68:
	.ascii "x234567890abcdef\0"
	.align 4
LC69:
	.ascii "1234567890abcdef1234567890abcdefx234567890abcdef\0"
LC70:
	.ascii "x234567890abcdefg\0"
	.align 4
LC71:
	.ascii "1234567890abcdef1234567890abcdefx234567890abcdefg\0"
	.align 4
LC72:
	.ascii "1234567890abcdef1234567890abcdefx234567890abcdefgh\0"
LC73:
	.ascii "x234567890abcdefx\0"
	.align 4
LC74:
	.ascii "1234567890abcdef1234567890abcdefx234567890abcdefx\0"
	.align 4
LC75:
	.ascii "1234567890abcdef1234567890abcdefx234567890abcdefxy\0"
LC76:
	.ascii "!!\0"
	.align 4
LC77:
	.ascii "1234567890abcde!!234567890abcdef\0"
	.align 4
LC78:
	.ascii "!1234567890!abcdef!!1234567890!abcdef!\0"
LC79:
	.ascii "!!!!\0"
	.align 4
LC80:
	.ascii "1234567890abcd!!!!34567890abcdef\0"
	.align 4
LC81:
	.ascii "1234567890abcdef!!!!1234567890abcdef\0"
	.align 4
LC82:
	.ascii "!12345678!90abcdef!!!!12345678!90abcdef!\0"
	.align 4
LC83:
	.ascii "!!12345678!!90abcdef!!!!12345678!!90abcdef!!\0"
	.align 4
LC84:
	.ascii "!!!12345678!!!90abcdef!!!!12345678!!!90abcdef!!!\0"
	.align 4
LC85:
	.ascii "!!!12345678!!!90abcdef!!!12345678!!!90abcdef!!!\0"
	.align 4
LC86:
	.ascii "!!!12345678!!!90abcdef!!!12345678!!!90abcdef!!!!\0"
LC87:
	.ascii "1234567890abcdefgh\0"
	.align 4
LC88:
	.ascii "1234567890abcdef1234567890abcdefgh\0"
	.align 4
LC89:
	.ascii "10234567890abcdefgh1234567890abcdefgh\0"
LC90:
	.ascii "abcdefghijklmnopqrstuvwxyz\0"
	.align 4
LC91:
	.ascii "aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzabcdefghijklmnopqrstuvwxyz\0"
	.align 4
LC92:
	.ascii "bbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzabc\0"
	.align 4
LC93:
	.ascii "abcdefghijklmnopqrstuvwxyzaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzabcdefghijklmnopqrstuvwxyz\0"
LC94:
	.ascii "strbm(\"%s\", \"%s\")=\"%s\"(\"%s\")\12\0"
LC95:
	.ascii "str0(\"%s\", \"%s\")=\"%s\"(\"%s\")\12\0"
LC96:
	.ascii "x12341234\0"
LC97:
	.ascii "x1234567890abcdefgh\0"
	.align 4
LC98:
	.ascii "1234567890abcdefghijklmnopqrstuvwxyz\0"
	.align 4
LC99:
	.ascii "1234567890abcdefghijklmnopqrstuvwxyz!\0"
	.align 4
LC100:
	.ascii "1234567890abcdefghijklmnopqrstuvwxyz!!\0"
	.align 4
LC101:
	.ascii "x1234567890abcdefghijklmnopqrstuvwxyz!!\0"
LC102:
	.ascii "(dummy_for_align=%d)\12\0"
	.align 4
LC103:
	.ascii "_memcpy_m128i_a(buff, str16,  0)=\"%s\"\12\0"
	.align 16
LC104:
	.long	858927408
	.long	926299444
	.long	1650538808
	.long	1717920867
	.align 4
LC105:
	.ascii "_memcpy_m128i_a(buff, str16,  1)=\"%s\"\12\0"
	.align 4
LC106:
	.ascii "_memcpy_m128i_a(buff, str16,  2)=\"%s\"\12\0"
	.align 4
LC107:
	.ascii "_memcpy_m128i_a(buff, str16,  3)=\"%s\"\12\0"
	.align 4
LC108:
	.ascii "_memcpy_m128i_a(buff, str16,  4)=\"%s\"\12\0"
	.align 4
LC109:
	.ascii "_memcpy_m128i_a(buff, str16,  5)=\"%s\"\12\0"
	.align 4
LC110:
	.ascii "_memcpy_m128i_a(buff, str16,  6)=\"%s\"\12\0"
	.align 4
LC111:
	.ascii "_memcpy_m128i_a(buff, str16,  7)=\"%s\"\12\0"
	.align 4
LC112:
	.ascii "_memcpy_m128i_a(buff, str16,  8)=\"%s\"\12\0"
	.align 4
LC113:
	.ascii "_memcpy_m128i_a(buff, str16,  9)=\"%s\"\12\0"
	.align 4
LC114:
	.ascii "_memcpy_m128i_a(buff, str16, 10)=\"%s\"\12\0"
	.align 4
LC115:
	.ascii "_memcpy_m128i_a(buff, str16, 11)=\"%s\"\12\0"
	.align 4
LC116:
	.ascii "_memcpy_m128i_a(buff, str16, 12)=\"%s\"\12\0"
	.align 4
LC117:
	.ascii "_memcpy_m128i_a(buff, str16, 13)=\"%s\"\12\0"
	.align 4
LC118:
	.ascii "_memcpy_m128i_a(buff, str16, 14)=\"%s\"\12\0"
	.align 4
LC119:
	.ascii "_memcpy_m128i_a(buff, str16, 15)=\"%s\"\12\0"
	.align 4
LC121:
	.ascii "_memcpy_m128i_a(buff, str16, 16)=\"%s\"\12\0"
	.align 4
LC122:
	.ascii "_memcpy_m128i_u(buffu, str16,  0)=\"%s\"\12\0"
	.align 4
LC123:
	.ascii "_memcpy_m128i_u(buffu, str16,  1)=\"%s\"\12\0"
	.align 4
LC124:
	.ascii "_memcpy_m128i_u(buffu, str16,  2)=\"%s\"\12\0"
	.align 4
LC125:
	.ascii "_memcpy_m128i_u(buffu, str16,  3)=\"%s\"\12\0"
	.align 4
LC126:
	.ascii "_memcpy_m128i_u(buffu, str16,  4)=\"%s\"\12\0"
	.align 4
LC127:
	.ascii "_memcpy_m128i_u(buffu, str16,  5)=\"%s\"\12\0"
	.align 4
LC128:
	.ascii "_memcpy_m128i_u(buffu, str16,  6)=\"%s\"\12\0"
	.align 4
LC129:
	.ascii "_memcpy_m128i_u(buffu, str16,  7)=\"%s\"\12\0"
	.align 4
LC130:
	.ascii "_memcpy_m128i_u(buffu, str16,  8)=\"%s\"\12\0"
	.align 4
LC131:
	.ascii "_memcpy_m128i_u(buffu, str16,  9)=\"%s\"\12\0"
	.align 4
LC132:
	.ascii "_memcpy_m128i_u(buffu, str16, 10)=\"%s\"\12\0"
	.align 4
LC133:
	.ascii "_memcpy_m128i_u(buffu, str16, 11)=\"%s\"\12\0"
	.align 4
LC134:
	.ascii "_memcpy_m128i_u(buffu, str16, 12)=\"%s\"\12\0"
	.align 4
LC135:
	.ascii "_memcpy_m128i_u(buffu, str16, 13)=\"%s\"\12\0"
	.align 4
LC136:
	.ascii "_memcpy_m128i_u(buffu, str16, 14)=\"%s\"\12\0"
	.align 4
LC137:
	.ascii "_memcpy_m128i_u(buffu, str16, 15)=\"%s\"\12\0"
	.align 4
LC139:
	.ascii "_memcpy_m128i_u(buffu, str16, 16)=\"%s\"\12\0"
	.align 4
LC140:
	.ascii "_memcpy_m128i_00_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC141:
	.ascii "_memcpy_m128i_01_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC142:
	.ascii "_memcpy_m128i_02_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC143:
	.ascii "_memcpy_m128i_03_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC144:
	.ascii "_memcpy_m128i_04_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC145:
	.ascii "_memcpy_m128i_05_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC146:
	.ascii "_memcpy_m128i_06_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC147:
	.ascii "_memcpy_m128i_07_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC148:
	.ascii "_memcpy_m128i_08_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC149:
	.ascii "_memcpy_m128i_09_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC150:
	.ascii "_memcpy_m128i_10_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC151:
	.ascii "_memcpy_m128i_11_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC152:
	.ascii "_memcpy_m128i_12_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC153:
	.ascii "_memcpy_m128i_13_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC154:
	.ascii "_memcpy_m128i_14_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC155:
	.ascii "_memcpy_m128i_15_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC156:
	.ascii "_memcpy_m128i_16_a(buff, str16) =\"%s\"\12\0"
	.align 4
LC157:
	.ascii "_memcpy_m128i_00_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC158:
	.ascii "_memcpy_m128i_01_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC159:
	.ascii "_memcpy_m128i_02_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC160:
	.ascii "_memcpy_m128i_03_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC161:
	.ascii "_memcpy_m128i_04_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC162:
	.ascii "_memcpy_m128i_05_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC163:
	.ascii "_memcpy_m128i_06_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC164:
	.ascii "_memcpy_m128i_07_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC165:
	.ascii "_memcpy_m128i_08_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC166:
	.ascii "_memcpy_m128i_09_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC167:
	.ascii "_memcpy_m128i_10_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC168:
	.ascii "_memcpy_m128i_11_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC169:
	.ascii "_memcpy_m128i_12_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC170:
	.ascii "_memcpy_m128i_13_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC171:
	.ascii "_memcpy_m128i_14_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC172:
	.ascii "_memcpy_m128i_15_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC173:
	.ascii "_memcpy_m128i_16_u(buffu, str16)=\"%s\"\12\0"
	.align 4
LC174:
	.ascii "_memcpy_m128i_00_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC175:
	.ascii "_memcpy_m128i_01_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC176:
	.ascii "_memcpy_m128i_02_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC177:
	.ascii "_memcpy_m128i_03_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC178:
	.ascii "_memcpy_m128i_04_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC179:
	.ascii "_memcpy_m128i_05_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC180:
	.ascii "_memcpy_m128i_06_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC181:
	.ascii "_memcpy_m128i_07_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC182:
	.ascii "_memcpy_m128i_08_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC183:
	.ascii "_memcpy_m128i_09_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC184:
	.ascii "_memcpy_m128i_10_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC185:
	.ascii "_memcpy_m128i_11_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC186:
	.ascii "_memcpy_m128i_12_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC187:
	.ascii "_memcpy_m128i_13_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC188:
	.ascii "_memcpy_m128i_14_a(buffu, str16)=\"%s\"\12\0"
	.align 4
LC189:
	.ascii "_memcpy_m128i_15_a(buffu, str16)=\"%s\"\12\0"
LC190:
	.ascii "cpy(%p, \"%s\")=\"%s\"\12\0"
LC191:
	.ascii "ncpy(%p, \"%s\", %d)=\"%s\"\12\0"
LC192:
	.ascii "z\0"
LC193:
	.ascii "zy\0"
LC194:
	.ascii "zyx\0"
LC195:
	.ascii "zyxw\0"
LC196:
	.ascii "zyxwv\0"
LC197:
	.ascii "A\0B\0"
LC198:
	.ascii "\0C\0"
	.text
	.p2align 4,,15
	.globl	__Z27testOpt07_Type2_After_1timev
	.def	__Z27testOpt07_Type2_After_1timev;	.scl	2;	.type	32;	.endef
__Z27testOpt07_Type2_After_1timev:
LFB3621:
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
	movl	$LC67+66, 16(%esp)
	movl	$LC66, 8(%esp)
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
	movl	$LC70, 4(%esp)
	movl	$LC69, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC70, 8(%esp)
	movl	$LC69, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC70, 4(%esp)
	movl	$LC71, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC71+32, 16(%esp)
	movl	$LC70, 8(%esp)
	movl	$LC71, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC70, 4(%esp)
	movl	$LC72, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC72+32, 16(%esp)
	movl	$LC70, 8(%esp)
	movl	$LC72, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC73, 4(%esp)
	movl	$LC71, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC73, 8(%esp)
	movl	$LC71, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC73, 4(%esp)
	movl	$LC74, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC74+32, 16(%esp)
	movl	$LC73, 8(%esp)
	movl	$LC74, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC73, 4(%esp)
	movl	$LC75, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC75+32, 16(%esp)
	movl	$LC73, 8(%esp)
	movl	$LC75, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC76, 4(%esp)
	movl	$LC77, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC77+15, 16(%esp)
	movl	$LC76, 8(%esp)
	movl	$LC77, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC76, 4(%esp)
	movl	$LC78, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC78+18, 16(%esp)
	movl	$LC76, 8(%esp)
	movl	$LC78, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC79, 4(%esp)
	movl	$LC80, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC80+14, 16(%esp)
	movl	$LC79, 8(%esp)
	movl	$LC80, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC79, 4(%esp)
	movl	$LC81, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC81+16, 16(%esp)
	movl	$LC79, 8(%esp)
	movl	$LC81, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC79, 4(%esp)
	movl	$LC82, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC82+18, 16(%esp)
	movl	$LC79, 8(%esp)
	movl	$LC82, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC79, 4(%esp)
	movl	$LC83, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC83+20, 16(%esp)
	movl	$LC79, 8(%esp)
	movl	$LC83, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC79, 4(%esp)
	movl	$LC84, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC84+22, 16(%esp)
	movl	$LC79, 8(%esp)
	movl	$LC84, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC79, 4(%esp)
	movl	$LC85, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC79, 8(%esp)
	movl	$LC85, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC79, 4(%esp)
	movl	$LC86, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC86+44, 16(%esp)
	movl	$LC79, 8(%esp)
	movl	$LC86, 4(%esp)
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
	movl	$LC87, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC87, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC87, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC88, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC88+16, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC88, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC89, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC89+19, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC89, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC90, 4(%esp)
	movl	$LC91, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC91+100, 16(%esp)
	movl	$LC90, 8(%esp)
	movl	$LC91, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC92, 4(%esp)
	movl	$LC93, (%esp)
	call	__Z12_strstr_fastPKcS0_
	movl	$LC93+30, 16(%esp)
	movl	$LC92, 8(%esp)
	movl	$LC93, 4(%esp)
	movl	$LC55, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC54, 4(%esp)
	movl	$LC42, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC54, 8(%esp)
	movl	$LC42, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC54, 4(%esp)
	movl	$LC44, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC54, 8(%esp)
	movl	$LC44, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC54, 4(%esp)
	movl	$LC45, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC45+1, 16(%esp)
	movl	$LC54, 8(%esp)
	movl	$LC45, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC54, 4(%esp)
	movl	$LC46, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC46+1, 16(%esp)
	movl	$LC54, 8(%esp)
	movl	$LC46, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC54, 4(%esp)
	movl	$LC47, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC47+1, 16(%esp)
	movl	$LC54, 8(%esp)
	movl	$LC47, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC54, 4(%esp)
	movl	$LC48, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC48+1, 16(%esp)
	movl	$LC54, 8(%esp)
	movl	$LC48, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC54, 4(%esp)
	movl	$LC56, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC56+1, 16(%esp)
	movl	$LC54, 8(%esp)
	movl	$LC56, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC57, 4(%esp)
	movl	$LC58, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC57, 8(%esp)
	movl	$LC58, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC59, 4(%esp)
	movl	$LC58, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC59, 8(%esp)
	movl	$LC58, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC57, 4(%esp)
	movl	$LC60, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC57, 8(%esp)
	movl	$LC60, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC59, 4(%esp)
	movl	$LC60, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC60+20, 16(%esp)
	movl	$LC59, 8(%esp)
	movl	$LC60, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC61, 4(%esp)
	movl	$LC58, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC58+3, 16(%esp)
	movl	$LC61, 8(%esp)
	movl	$LC58, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC9, 4(%esp)
	movl	$LC58, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC58, 16(%esp)
	movl	$LC9, 8(%esp)
	movl	$LC58, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC62, 4(%esp)
	movl	$LC63, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC63+27, 16(%esp)
	movl	$LC62, 8(%esp)
	movl	$LC63, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC9, 4(%esp)
	movl	$LC63, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC63, 16(%esp)
	movl	$LC9, 8(%esp)
	movl	$LC63, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC64, 4(%esp)
	movl	$LC65, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC65+31, 16(%esp)
	movl	$LC64, 8(%esp)
	movl	$LC65, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC66, 4(%esp)
	movl	$LC67, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC67+66, 16(%esp)
	movl	$LC66, 8(%esp)
	movl	$LC67, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC68, 4(%esp)
	movl	$LC69, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC69+32, 16(%esp)
	movl	$LC68, 8(%esp)
	movl	$LC69, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC70, 4(%esp)
	movl	$LC69, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC70, 8(%esp)
	movl	$LC69, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC70, 4(%esp)
	movl	$LC71, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC71+32, 16(%esp)
	movl	$LC70, 8(%esp)
	movl	$LC71, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC70, 4(%esp)
	movl	$LC72, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC72+32, 16(%esp)
	movl	$LC70, 8(%esp)
	movl	$LC72, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC73, 4(%esp)
	movl	$LC71, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC73, 8(%esp)
	movl	$LC71, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC73, 4(%esp)
	movl	$LC74, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC74+32, 16(%esp)
	movl	$LC73, 8(%esp)
	movl	$LC74, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC73, 4(%esp)
	movl	$LC75, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC75+32, 16(%esp)
	movl	$LC73, 8(%esp)
	movl	$LC75, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC76, 4(%esp)
	movl	$LC77, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC77+15, 16(%esp)
	movl	$LC76, 8(%esp)
	movl	$LC77, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC76, 4(%esp)
	movl	$LC78, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC78+18, 16(%esp)
	movl	$LC76, 8(%esp)
	movl	$LC78, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC79, 4(%esp)
	movl	$LC80, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC80+14, 16(%esp)
	movl	$LC79, 8(%esp)
	movl	$LC80, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC79, 4(%esp)
	movl	$LC81, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC81+16, 16(%esp)
	movl	$LC79, 8(%esp)
	movl	$LC81, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC79, 4(%esp)
	movl	$LC82, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC82+18, 16(%esp)
	movl	$LC79, 8(%esp)
	movl	$LC82, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC79, 4(%esp)
	movl	$LC83, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC83+20, 16(%esp)
	movl	$LC79, 8(%esp)
	movl	$LC83, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC79, 4(%esp)
	movl	$LC84, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC84+22, 16(%esp)
	movl	$LC79, 8(%esp)
	movl	$LC84, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC79, 4(%esp)
	movl	$LC85, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC79, 8(%esp)
	movl	$LC85, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC79, 4(%esp)
	movl	$LC86, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC86+44, 16(%esp)
	movl	$LC79, 8(%esp)
	movl	$LC86, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC19, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC19, 16(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC87, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC87, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC87, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC88, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC88+16, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC88, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC89, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC89+19, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC89, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC90, 4(%esp)
	movl	$LC91, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC91+100, 16(%esp)
	movl	$LC90, 8(%esp)
	movl	$LC91, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC92, 4(%esp)
	movl	$LC93, (%esp)
	call	__Z14_strstrbm_fastPKcS0_
	movl	$LC93+30, 16(%esp)
	movl	$LC92, 8(%esp)
	movl	$LC93, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC42, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC42, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC44, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC44, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC45, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC45, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC45, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC46, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC46, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC46, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC47, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC47, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC47, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC48, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC48, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC48, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC56, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC56, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC56, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC58, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC58, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC58, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC45, 4(%esp)
	movl	$LC96, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC96+1, 16(%esp)
	movl	$LC45, 8(%esp)
	movl	$LC96, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC19, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC19, 16(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC19, 4(%esp)
	movl	$LC20, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC20, 16(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC19, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC20, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC20, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC87, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC87, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC87, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	$LC97, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC97+1, 16(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC97, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC98, 4(%esp)
	movl	$LC98, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC98, 16(%esp)
	movl	$LC98, 8(%esp)
	movl	$LC98, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC98, 4(%esp)
	movl	$LC99, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC99, 16(%esp)
	movl	$LC98, 8(%esp)
	movl	$LC99, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC99, 4(%esp)
	movl	$LC98, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$0, 16(%esp)
	movl	$LC99, 8(%esp)
	movl	$LC98, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC99, 4(%esp)
	movl	$LC99, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC99, 16(%esp)
	movl	$LC99, 8(%esp)
	movl	$LC99, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC99, 4(%esp)
	movl	$LC100, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC100, 16(%esp)
	movl	$LC99, 8(%esp)
	movl	$LC100, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC99, 4(%esp)
	movl	$LC101, (%esp)
	call	__Z13_strstr0_fastPKcS0_
	movl	$LC101+1, 16(%esp)
	movl	$LC99, 8(%esp)
	movl	$LC101, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$123, 4(%esp)
	movl	$LC102, (%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC103, (%esp)
	movl	$0, 96(%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movzbl	LC104, %ecx
	movl	%esi, 4(%esp)
	movl	$LC105, (%esp)
	movl	$0, 96(%esp)
	movl	%ecx, 92(%esp)
	movb	%cl, 96(%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movzwl	LC104, %eax
	movl	%esi, 4(%esp)
	movl	$LC106, (%esp)
	movl	$0, 96(%esp)
	movl	%eax, %edi
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movw	%ax, 96(%esp)
	call	_printf
	movzbl	LC104+2, %edx
	movl	%esi, 4(%esp)
	movl	$LC107, (%esp)
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
	movl	LC104, %eax
	movl	%esi, 4(%esp)
	movl	$LC108, (%esp)
	movl	$0, 100(%esp)
	movl	%eax, %edi
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	%eax, 96(%esp)
	call	_printf
	movzbl	LC104+4, %eax
	movl	%esi, 4(%esp)
	movl	$LC109, (%esp)
	movl	$0, 100(%esp)
	movl	%edi, 96(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movb	%al, 82(%esp)
	movb	%al, 100(%esp)
	call	_printf
	movzwl	LC104+4, %edx
	movl	%esi, 4(%esp)
	movl	$LC110, (%esp)
	movl	$0, 100(%esp)
	movl	%edx, %ebx
	movl	%edi, 96(%esp)
	movw	%dx, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movzbl	LC104+6, %edx
	movl	%esi, 4(%esp)
	movl	$LC111, (%esp)
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
	movl	$LC112, (%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	call	_printf
	movl	LC104, %edi
	movl	LC104+4, %ebp
	movzbl	LC104+8, %ecx
	movl	%esi, 4(%esp)
	movl	$LC113, (%esp)
	movl	$0, 104(%esp)
	movb	%cl, 84(%esp)
	movb	%cl, 104(%esp)
	movl	%edi, 96(%esp)
	movl	%ebp, 100(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movzwl	LC104+8, %ebx
	movl	%esi, 4(%esp)
	movl	$LC114, (%esp)
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
	movzbl	LC104+10, %ebx
	movl	%esi, 4(%esp)
	movl	$LC115, (%esp)
	movl	%edi, 96(%esp)
	movl	%ebp, 100(%esp)
	movb	%bl, 85(%esp)
	movb	%bl, 106(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	LC104+8, %ebx
	movl	%esi, 4(%esp)
	movl	$LC116, (%esp)
	movl	%edi, 96(%esp)
	movl	%ebp, 100(%esp)
	movl	%ebx, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	%ebx, 32(%esp)
	movl	%ebx, 104(%esp)
	movzbl	LC104+12, %ebx
	movl	%esi, 4(%esp)
	movl	$LC117, (%esp)
	movl	$0, 108(%esp)
	movl	%edi, 96(%esp)
	movl	%ebp, 100(%esp)
	movb	%bl, 86(%esp)
	movb	%bl, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	32(%esp), %ebx
	movzwl	LC104+12, %edx
	movl	%esi, 4(%esp)
	movl	$LC118, (%esp)
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
	movl	$LC119, (%esp)
	movw	%dx, 108(%esp)
	movzbl	LC104+14, %edx
	movl	%edi, 96(%esp)
	movl	%ebp, 100(%esp)
	movl	%ebx, 32(%esp)
	movb	%dl, 87(%esp)
	movb	%dl, 110(%esp)
	movl	%ebx, 104(%esp)
	leal	142(%esp), %ebx
	movl	$0, 112(%esp)
	call	_printf
	movdqa	LC120, %xmm1
	movdqa	%xmm1, 96(%esp)
	movl	%esi, 4(%esp)
	movdqa	%xmm1, 64(%esp)
	movl	$LC121, (%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC122, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	call	_printf
	movl	92(%esp), %ecx
	movl	%ebx, 4(%esp)
	movl	$LC123, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movb	%cl, 142(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	call	_printf
	movzwl	60(%esp), %eax
	movl	%ebx, 4(%esp)
	movl	$LC124, (%esp)
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
	movl	$LC125, (%esp)
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
	movl	$LC126, (%esp)
	movl	$0, 146(%esp)
	movl	%ecx, 142(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	call	_printf
	movl	52(%esp), %ecx
	movzbl	82(%esp), %eax
	movl	%ebx, 4(%esp)
	movl	$LC127, (%esp)
	movl	%ecx, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	%al, 146(%esp)
	call	_printf
	movl	52(%esp), %eax
	movl	%ebx, 4(%esp)
	movl	$LC128, (%esp)
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
	movl	$LC129, (%esp)
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
	movl	$LC130, (%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	call	_printf
	movzbl	84(%esp), %ecx
	movl	%ebx, 4(%esp)
	movl	$LC131, (%esp)
	movl	$0, 150(%esp)
	movl	%edi, 142(%esp)
	movl	%ebp, 146(%esp)
	movb	%cl, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	call	_printf
	movzwl	80(%esp), %ecx
	movl	%ebx, 4(%esp)
	movl	$LC132, (%esp)
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
	movl	$LC133, (%esp)
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
	movl	$LC134, (%esp)
	movl	%edi, 142(%esp)
	movl	%ebp, 146(%esp)
	movl	%ecx, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	call	_printf
	movl	32(%esp), %ecx
	movzbl	86(%esp), %eax
	movl	%ebx, 4(%esp)
	movl	$LC135, (%esp)
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
	movl	$LC136, (%esp)
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
	movl	$LC137, (%esp)
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
	movdqa	LC138, %xmm0
	movdqu	%xmm0, 142(%esp)
	movl	%ebx, 4(%esp)
	movdqa	%xmm0, 32(%esp)
	movl	$LC139, (%esp)
	movl	$0, 158(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC140, (%esp)
	movl	$0, 96(%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC141, (%esp)
	movl	$0, 96(%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movb	$48, 96(%esp)
	call	_printf
	movl	$12592, %edx
	movl	%esi, 4(%esp)
	movl	$LC142, (%esp)
	movl	$0, 96(%esp)
	movl	$0, 100(%esp)
	movw	%dx, 96(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	$12592, %ecx
	movl	%esi, 4(%esp)
	movl	$LC143, (%esp)
	movl	$0, 96(%esp)
	movl	$0, 100(%esp)
	movw	%cx, 96(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movb	$50, 98(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC144, (%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC145, (%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movb	$52, 100(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC146, (%esp)
	movl	$0, 100(%esp)
	movl	$0, 104(%esp)
	movw	%di, 100(%esp)
	movl	$14648, %edi
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC147, (%esp)
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
	movl	$LC148, (%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC149, (%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	movb	$56, 104(%esp)
	call	_printf
	movl	$14648, %eax
	movl	%esi, 4(%esp)
	movl	$LC150, (%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	movw	%ax, 104(%esp)
	call	_printf
	movl	$14648, %eax
	movl	%esi, 4(%esp)
	movl	$LC151, (%esp)
	movl	$0, 104(%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	movw	%ax, 104(%esp)
	movb	$97, 106(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC152, (%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	movl	$1650538808, 104(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC153, (%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	movl	$1650538808, 104(%esp)
	movb	$99, 108(%esp)
	call	_printf
	movl	$25699, %eax
	movl	%esi, 4(%esp)
	movl	$LC154, (%esp)
	movl	$0, 108(%esp)
	movl	$0, 112(%esp)
	movl	$858927408, 96(%esp)
	movl	$926299444, 100(%esp)
	movl	$1650538808, 104(%esp)
	movw	%ax, 108(%esp)
	call	_printf
	movl	$25699, %eax
	movl	%esi, 4(%esp)
	movl	$LC155, (%esp)
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
	movl	$LC156, (%esp)
	movl	$0, 112(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC157, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC158, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC159, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	movb	$49, 143(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC160, (%esp)
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
	movl	$LC161, (%esp)
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
	movl	$LC162, (%esp)
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
	movl	$LC163, (%esp)
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
	movl	$LC164, (%esp)
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
	movl	$LC165, (%esp)
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
	movl	$LC166, (%esp)
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
	movl	$LC167, (%esp)
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
	movl	$LC168, (%esp)
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
	movl	$LC169, (%esp)
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
	movl	$LC170, (%esp)
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
	movl	$LC171, (%esp)
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
	movl	$LC172, (%esp)
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
	movl	$LC173, (%esp)
	movl	$0, 158(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC174, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC175, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movb	$48, 142(%esp)
	call	_printf
	movl	$12592, %eax
	movl	%ebx, 4(%esp)
	movl	$LC176, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movw	%ax, 142(%esp)
	call	_printf
	movl	$12592, %eax
	movl	%ebx, 4(%esp)
	movl	$LC177, (%esp)
	movl	$0, 142(%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movw	%ax, 142(%esp)
	movb	$50, 144(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC178, (%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC179, (%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movb	$52, 146(%esp)
	call	_printf
	movl	$13620, %edx
	movl	%ebx, 4(%esp)
	movl	$LC180, (%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movw	%dx, 146(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	call	_printf
	movl	$13620, %ecx
	movl	%ebx, 4(%esp)
	movl	$LC181, (%esp)
	movl	$0, 146(%esp)
	movl	$0, 150(%esp)
	movw	%cx, 146(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movb	$54, 148(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC182, (%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC183, (%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	movb	$56, 150(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC184, (%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	movw	%di, 150(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC185, (%esp)
	movl	$0, 150(%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	movw	%bp, 150(%esp)
	movb	$97, 152(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC186, (%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	movl	$1650538808, 150(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC187, (%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	movl	$1650538808, 150(%esp)
	movb	$99, 154(%esp)
	call	_printf
	movl	$25699, %eax
	movl	%ebx, 4(%esp)
	movl	$LC188, (%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	movl	$1650538808, 150(%esp)
	movw	%ax, 154(%esp)
	call	_printf
	movl	$25699, %eax
	movl	%ebx, 4(%esp)
	movl	$LC189, (%esp)
	movl	$0, 154(%esp)
	movl	$0, 158(%esp)
	movl	$858927408, 142(%esp)
	movl	$926299444, 146(%esp)
	movl	$1650538808, 150(%esp)
	movw	%ax, 154(%esp)
	movb	$101, 156(%esp)
	call	_printf
	xorl	%eax, %eax
L792:
	movl	$0, (%esi,%eax)
	addl	$4, %eax
	cmpl	$32, %eax
	jb	L792
	testb	$2, %bl
	movl	%ebx, %edx
	movl	$32, %ecx
	jne	L823
L794:
	movl	%ecx, %edi
	xorl	%eax, %eax
	andl	$-4, %edi
L795:
	movl	$0, (%edx,%eax)
	addl	$4, %eax
	cmpl	%edi, %eax
	jb	L795
	addl	%eax, %edx
	andl	$2, %ecx
	je	L798
	xorl	%eax, %eax
	movw	%ax, (%edx)
L798:
	movl	$123, 4(%esp)
	movl	%esi, %edi
	movl	$LC102, (%esp)
	call	_printf
	movl	$LC9, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC9, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC190, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC11, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC11, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC190, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC12, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC12, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC190, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC13, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC13, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC190, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC14, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC14, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC190, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC15, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC15, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC190, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC16, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC16, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC190, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC17, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC17, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC190, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC18, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC18, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC190, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC19, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC19, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC190, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC20, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC190, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC30, 4(%esp)
	movl	%esi, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC30, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC190, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC18, 4(%esp)
	movl	%ebx, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC18, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$LC190, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC19, 4(%esp)
	movl	%ebx, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC19, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$LC190, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC20, 4(%esp)
	movl	%ebx, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC20, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$LC190, (%esp)
	movl	%eax, 12(%esp)
	call	_printf
	movl	$LC30, 4(%esp)
	movl	%ebx, (%esp)
	call	__Z12_strcpy_fastPcPKc
	movl	$LC30, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$LC190, (%esp)
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
	jne	L824
L799:
	movl	%edx, %ecx
	xorl	%eax, %eax
	shrl	$2, %ecx
	andl	$2, %edx
	rep stosl
	je	L801
	xorl	%eax, %eax
	movw	%ax, (%edi)
L801:
	movl	$123, 4(%esp)
	movl	$LC102, (%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC9, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC9, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC11, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC11, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC12, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC12, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC13, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC13, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC14, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC14, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC15, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC15, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC16, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC16, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC17, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC17, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC9, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC9, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC192, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC192, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC193, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC193, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC194, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC194, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC195, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC195, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC196, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC196, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC197, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC197, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$2, 8(%esp)
	movl	$LC198, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$2, 12(%esp)
	movl	$LC198, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC18, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC18, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC19, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC20, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$16, 8(%esp)
	movl	$LC30, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC30, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$16, 8(%esp)
	movl	$LC18, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC18, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$16, 8(%esp)
	movl	$LC19, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC19, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$16, 8(%esp)
	movl	$LC20, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$16, 8(%esp)
	movl	$LC30, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$16, 12(%esp)
	movl	$LC30, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$33, 8(%esp)
	movl	$LC28, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$33, 12(%esp)
	movl	$LC28, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$33, 8(%esp)
	movl	$LC31, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$33, 12(%esp)
	movl	$LC31, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$33, 8(%esp)
	movl	$LC36, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$33, 12(%esp)
	movl	$LC36, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%esi, (%esp)
	movl	$1, 8(%esp)
	movl	$LC13, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%esi, 4(%esp)
	movl	$1, 12(%esp)
	movl	$LC13, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$33, 8(%esp)
	movl	$LC28, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$33, 12(%esp)
	movl	$LC28, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$33, 8(%esp)
	movl	$LC31, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$33, 12(%esp)
	movl	$LC31, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$33, 8(%esp)
	movl	$LC36, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$33, 12(%esp)
	movl	$LC36, 8(%esp)
	movl	$LC191, (%esp)
	movl	%eax, 16(%esp)
	call	_printf
	movl	%ebx, (%esp)
	movl	$1, 8(%esp)
	movl	$LC13, 4(%esp)
	call	__Z13_strncpy_fastPcPKcj
	movl	%ebx, 4(%esp)
	movl	$1, 12(%esp)
	movl	$LC13, 8(%esp)
	movl	$LC191, (%esp)
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
L823:
	.cfi_restore_state
	xorl	%eax, %eax
	movb	$30, %cl
	movw	%ax, 142(%esp)
	leal	144(%esp), %edx
	jmp	L794
L824:
	xorl	%eax, %eax
	movb	$32, %dl
	movw	%ax, 142(%esp)
	leal	144(%esp), %edi
	jmp	L799
	.cfi_endproc
LFE3621:
	.p2align 4,,15
	.globl	__Z28testOpt07_Type2_strlen_AfteriPKc
	.def	__Z28testOpt07_Type2_strlen_AfteriPKc;	.scl	2;	.type	32;	.endef
__Z28testOpt07_Type2_strlen_AfteriPKc:
LFB3622:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	%eax, 4(%esp)
	jmp	__Z12_strlen_fastPKc
	.cfi_endproc
LFE3622:
	.p2align 4,,15
	.globl	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	.def	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_;	.scl	2;	.type	32;	.endef
__Z28testOpt07_Type2_strcmp_AfteriPKcS0_:
LFB3623:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	__Z12_strcmp_fastPKcS0_
	.cfi_endproc
LFE3623:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	.def	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j:
LFB3624:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	16(%esp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	jmp	__Z13_strncmp_fastPKcS0_j
	.cfi_endproc
LFE3624:
	.p2align 4,,15
	.globl	__Z28testOpt07_Type2_strchr_AfteriPKcc
	.def	__Z28testOpt07_Type2_strchr_AfteriPKcc;	.scl	2;	.type	32;	.endef
__Z28testOpt07_Type2_strchr_AfteriPKcc:
LFB3625:
	.cfi_startproc
	movl	8(%esp), %eax
	movsbl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	__Z12_strchr_fastPKcc
	.cfi_endproc
LFE3625:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	.def	__Z29testOpt07_Type2_strrchr_AfteriPKcc;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strrchr_AfteriPKcc:
LFB3626:
	.cfi_startproc
	movl	8(%esp), %eax
	movsbl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	__Z13_strrchr_fastPKcc
	.cfi_endproc
LFE3626:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	.def	__Z29testOpt07_Type2_strstr_After1iPKcS0_;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strstr_After1iPKcS0_:
LFB3627:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	__Z12_strstr_fastPKcS0_
	.cfi_endproc
LFE3627:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	.def	__Z29testOpt07_Type2_strstr_After2iPKcS0_;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strstr_After2iPKcS0_:
LFB3628:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	__Z14_strstrbm_fastPKcS0_
	.cfi_endproc
LFE3628:
	.p2align 4,,15
	.globl	__Z28testOpt07_Type2_strcpy_AfteriPcPKc
	.def	__Z28testOpt07_Type2_strcpy_AfteriPcPKc;	.scl	2;	.type	32;	.endef
__Z28testOpt07_Type2_strcpy_AfteriPcPKc:
LFB3629:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	__Z12_strcpy_fastPcPKc
	.cfi_endproc
LFE3629:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	.def	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strncpy_AfteriPcPKcj:
LFB3630:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	16(%esp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	jmp	__Z13_strncpy_fastPcPKcj
	.cfi_endproc
LFE3630:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type1_Beforei
	.def	__Z22testOpt08_Type1_Beforei;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type1_Beforei:
LFB3631:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	$4, %eax
	cmpl	$399, %edx
	jle	L839
L835:
	rep ret
	.p2align 4,,7
L839:
	cmpl	$299, %edx
	movb	$3, %al
	jg	L835
	cmpl	$199, %edx
	movb	$2, %al
	jg	L835
	xorl	%eax, %eax
	cmpl	$99, %edx
	setg	%al
	ret
	.cfi_endproc
LFE3631:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type1_After1i
	.def	__Z22testOpt08_Type1_After1i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type1_After1i:
LFB3632:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	$4, %eax
	cmpl	$399, %edx
	jle	L845
L841:
	rep ret
	.p2align 4,,7
L845:
	cmpl	$299, %edx
	movb	$3, %al
	jg	L841
	cmpl	$199, %edx
	movb	$2, %al
	jg	L841
	xorl	%eax, %eax
	cmpl	$99, %edx
	setg	%al
	ret
	.cfi_endproc
LFE3632:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type1_After2i
	.def	__Z22testOpt08_Type1_After2i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type1_After2i:
LFB3633:
	.cfi_startproc
	movl	4(%esp), %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$31, %ecx
	sarl	$5, %edx
	subl	%ecx, %edx
	movl	%edx, %eax
	ret
	.cfi_endproc
LFE3633:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type1_After3i
	.def	__Z22testOpt08_Type1_After3i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type1_After3i:
LFB3634:
	.cfi_startproc
	movl	4(%esp), %edx
	xorl	%ecx, %ecx
	cmpl	$99, %edx
	setg	%cl
	xorl	%eax, %eax
	cmpl	$199, %edx
	setg	%al
	addl	%ecx, %eax
	xorl	%ecx, %ecx
	cmpl	$299, %edx
	setg	%cl
	addl	%ecx, %eax
	cmpl	$399, %edx
	setg	%dl
	movzbl	%dl, %edx
	addl	%edx, %eax
	ret
	.cfi_endproc
LFE3634:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type2_Beforei
	.def	__Z22testOpt08_Type2_Beforei;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type2_Beforei:
LFB3635:
	.cfi_startproc
	cmpl	$199, 4(%esp)
	movl	$2, %eax
	jle	L851
	rep ret
	.p2align 4,,7
L851:
	xorl	%eax, %eax
	cmpl	$99, 4(%esp)
	setg	%al
	ret
	.cfi_endproc
LFE3635:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type2_After1i
	.def	__Z22testOpt08_Type2_After1i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type2_After1i:
LFB3636:
	.cfi_startproc
	cmpl	$199, 4(%esp)
	movl	$2, %eax
	jle	L855
	rep ret
	.p2align 4,,7
L855:
	xorl	%eax, %eax
	cmpl	$99, 4(%esp)
	setg	%al
	ret
	.cfi_endproc
LFE3636:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type2_After2i
	.def	__Z22testOpt08_Type2_After2i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type2_After2i:
LFB3637:
	.cfi_startproc
	movl	4(%esp), %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$31, %ecx
	sarl	$5, %edx
	subl	%ecx, %edx
	movl	%edx, %eax
	ret
	.cfi_endproc
LFE3637:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type2_After3i
	.def	__Z22testOpt08_Type2_After3i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type2_After3i:
LFB3638:
	.cfi_startproc
	movl	4(%esp), %edx
	xorl	%ecx, %ecx
	cmpl	$99, %edx
	setg	%cl
	xorl	%eax, %eax
	cmpl	$199, %edx
	setg	%al
	addl	%ecx, %eax
	ret
	.cfi_endproc
LFE3638:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type3_Beforeii
	.def	__Z22testOpt08_Type3_Beforeii;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type3_Beforeii:
LFB3639:
	.cfi_startproc
	cmpl	$99, 4(%esp)
	setg	%al
	cmpl	$99, 8(%esp)
	setg	%dl
	andl	%edx, %eax
	ret
	.cfi_endproc
LFE3639:
	.p2align 4,,15
	.globl	__Z21testOpt08_Type3_Afterii
	.def	__Z21testOpt08_Type3_Afterii;	.scl	2;	.type	32;	.endef
__Z21testOpt08_Type3_Afterii:
LFB3640:
	.cfi_startproc
	cmpl	$99, 4(%esp)
	setg	%al
	cmpl	$99, 8(%esp)
	setg	%dl
	andl	%edx, %eax
	ret
	.cfi_endproc
LFE3640:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type4_Beforei
	.def	__Z22testOpt08_Type4_Beforei;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type4_Beforei:
LFB3641:
	.cfi_startproc
	movl	4(%esp), %eax
	testb	$63, %al
	je	L861
	cltd
	shrl	$26, %edx
	leal	(%eax,%edx), %ecx
	andl	$63, %ecx
	subl	%ecx, %edx
	leal	64(%eax,%edx), %eax
L861:
	rep ret
	.cfi_endproc
LFE3641:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type4_After1i
	.def	__Z22testOpt08_Type4_After1i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type4_After1i:
LFB3642:
	.cfi_startproc
	movl	4(%esp), %eax
	cltd
	shrl	$26, %edx
	leal	(%eax,%edx), %ecx
	andl	$63, %ecx
	subl	%edx, %ecx
	je	L865
	subl	%ecx, %eax
	addl	$64, %eax
L865:
	rep ret
	.cfi_endproc
LFE3642:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type4_After2i
	.def	__Z22testOpt08_Type4_After2i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type4_After2i:
LFB3643:
	.cfi_startproc
	movl	4(%esp), %eax
	addl	$63, %eax
	andl	$-64, %eax
	ret
	.cfi_endproc
LFE3643:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type5_Beforei
	.def	__Z22testOpt08_Type5_Beforei;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type5_Beforei:
LFB3644:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %ecx
	movl	$32, %edx
	xorl	%eax, %eax
	.p2align 4,,7
L871:
	testb	$1, %cl
	leal	1(%eax), %ebx
	cmovne	%ebx, %eax
	sarl	%ecx
	subl	$1, %edx
	jne	L871
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3644:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type5_After1i
	.def	__Z22testOpt08_Type5_After1i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type5_After1i:
LFB3645:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	%edx, %eax
	andl	$1431655765, %edx
	shrl	%eax
	andl	$1431655765, %eax
	addl	%eax, %edx
	movl	%edx, %eax
	andl	$858993459, %edx
	shrl	$2, %eax
	andl	$858993459, %eax
	addl	%eax, %edx
	movl	%edx, %eax
	andl	$252645135, %edx
	shrl	$4, %eax
	andl	$252645135, %eax
	addl	%eax, %edx
	movl	%edx, %eax
	andl	$16711935, %edx
	shrl	$8, %eax
	andl	$16711935, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movzwl	%ax, %eax
	shrl	$16, %edx
	addl	%edx, %eax
	ret
	.cfi_endproc
LFE3645:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type5_After2i
	.def	__Z22testOpt08_Type5_After2i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type5_After2i:
LFB3646:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	%edx, %eax
	movl	%edx, %ecx
	shrl	%eax
	andl	$1, %ecx
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$2, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$3, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$4, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$5, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$6, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$7, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$8, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$9, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$10, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$11, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$12, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$13, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$14, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$15, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$16, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$17, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$18, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$19, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$20, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$21, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$22, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$23, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$24, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$25, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$26, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$27, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$28, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$29, %eax
	andl	$1, %eax
	addl	%eax, %ecx
	movl	%edx, %eax
	shrl	$30, %eax
	andl	$1, %eax
	addl	%ecx, %eax
	shrl	$31, %edx
	addl	%edx, %eax
	ret
	.cfi_endproc
LFE3646:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type6_Beforei
	.def	__Z22testOpt08_Type6_Beforei;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type6_Beforei:
LFB3647:
	.cfi_startproc
	movl	4(%esp), %edx
	testl	%edx, %edx
	js	L884
	addl	%edx, %edx
	movl	$30, %eax
	jmp	L879
	.p2align 4,,7
L886:
	subl	$1, %eax
	addl	%edx, %edx
	cmpl	$-1, %eax
	je	L885
L879:
	testl	%edx, %edx
	jns	L886
	rep ret
	.p2align 4,,7
L885:
	.p2align 4,,9
	rep ret
L884:
	movl	$31, %eax
	.p2align 4,,6
	ret
	.cfi_endproc
LFE3647:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type6_After1i
	.def	__Z22testOpt08_Type6_After1i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type6_After1i:
LFB3648:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	%eax, %edx
	shrl	$16, %edx
	orl	%eax, %edx
	movl	%edx, %eax
	shrl	$8, %eax
	orl	%edx, %eax
	movl	%eax, %edx
	shrl	$4, %edx
	orl	%eax, %edx
	movl	%edx, %eax
	shrl	$2, %eax
	orl	%edx, %eax
	movl	%eax, %edx
	shrl	%edx
	orl	%edx, %eax
	je	L889
	movl	%eax, %edx
	andl	$1431655765, %eax
	shrl	%edx
	andl	$1431655765, %edx
	addl	%edx, %eax
	movl	%eax, %edx
	andl	$858993459, %eax
	shrl	$2, %edx
	andl	$858993459, %edx
	addl	%eax, %edx
	movl	%edx, %eax
	andl	$252645135, %edx
	shrl	$4, %eax
	andl	$252645135, %eax
	addl	%eax, %edx
	movl	%edx, %eax
	andl	$16711935, %edx
	shrl	$8, %eax
	andl	$16711935, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movzwl	%ax, %eax
	shrl	$16, %edx
	leal	-1(%edx,%eax), %eax
	ret
	.p2align 4,,7
L889:
	movl	$-1, %eax
	ret
	.cfi_endproc
LFE3648:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type6_After2i
	.def	__Z22testOpt08_Type6_After2i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type6_After2i:
LFB3649:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	$31, %eax
	testl	%edx, %edx
	js	L891
	testl	$1073741824, %edx
	movb	$30, %al
	je	L923
L891:
	rep ret
	.p2align 4,,7
L923:
	testl	$536870912, %edx
	movb	$29, %al
	jne	L891
	testl	$268435456, %edx
	movb	$28, %al
	jne	L891
	testl	$134217728, %edx
	movb	$27, %al
	jne	L891
	testl	$67108864, %edx
	movb	$26, %al
	jne	L891
	testl	$33554432, %edx
	movb	$25, %al
	jne	L891
	testl	$16777216, %edx
	movb	$24, %al
	jne	L891
	testl	$8388608, %edx
	movb	$23, %al
	jne	L891
	testl	$4194304, %edx
	movb	$22, %al
	jne	L891
	testl	$2097152, %edx
	movb	$21, %al
	jne	L891
	testl	$1048576, %edx
	movb	$20, %al
	jne	L891
	testl	$524288, %edx
	movb	$19, %al
	jne	L891
	testl	$262144, %edx
	movb	$18, %al
	jne	L891
	testl	$131072, %edx
	movb	$17, %al
	jne	L891
	testl	$65536, %edx
	movb	$16, %al
	jne	L891
	testb	$128, %dh
	movb	$15, %al
	jne	L891
	testb	$64, %dh
	movb	$14, %al
	jne	L891
	testb	$32, %dh
	movb	$13, %al
	jne	L891
	testb	$16, %dh
	movb	$12, %al
	jne	L891
	testb	$8, %dh
	movb	$11, %al
	jne	L891
	testb	$4, %dh
	movb	$10, %al
	jne	L891
	testb	$2, %dh
	movb	$9, %al
	jne	L891
	testb	$1, %dh
	movb	$8, %al
	jne	L891
	testb	$-128, %dl
	movb	$7, %al
	jne	L891
	testb	$64, %dl
	movb	$6, %al
	jne	L891
	testb	$32, %dl
	movb	$5, %al
	jne	L891
	testb	$16, %dl
	movb	$4, %al
	jne	L891
	testb	$8, %dl
	movb	$3, %al
	jne	L891
	testb	$4, %dl
	movb	$2, %al
	jne	L891
	testb	$2, %dl
	movb	$1, %al
	jne	L891
	movl	%edx, %eax
	andl	$1, %eax
	xorl	$1, %eax
	negl	%eax
	ret
	.cfi_endproc
LFE3649:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type7_Beforei
	.def	__Z22testOpt08_Type7_Beforei;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type7_Beforei:
LFB3650:
	.cfi_startproc
	movl	4(%esp), %edx
	xorl	%eax, %eax
	jmp	L926
	.p2align 4,,7
L930:
	addl	$1, %eax
	sarl	%edx
	cmpl	$32, %eax
	je	L929
L926:
	testb	$1, %dl
	je	L930
	rep ret
	.p2align 4,,7
L929:
	movl	$-1, %eax
	.p2align 4,,3
	ret
	.cfi_endproc
LFE3650:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type7_After1i
	.def	__Z22testOpt08_Type7_After1i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type7_After1i:
LFB3651:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	%eax, %edx
	sall	$16, %edx
	orl	%eax, %edx
	movl	%edx, %eax
	sall	$8, %eax
	orl	%edx, %eax
	movl	%eax, %edx
	sall	$4, %edx
	orl	%eax, %edx
	leal	0(,%edx,4), %eax
	orl	%edx, %eax
	leal	(%eax,%eax), %edx
	orl	%edx, %eax
	je	L933
	notl	%eax
	movl	%eax, %edx
	andl	$1431655765, %eax
	shrl	%edx
	andl	$1431655765, %edx
	addl	%edx, %eax
	movl	%eax, %edx
	andl	$858993459, %eax
	shrl	$2, %edx
	andl	$858993459, %edx
	addl	%eax, %edx
	movl	%edx, %eax
	andl	$252645135, %edx
	shrl	$4, %eax
	andl	$252645135, %eax
	addl	%eax, %edx
	movl	%edx, %eax
	andl	$16711935, %edx
	shrl	$8, %eax
	andl	$16711935, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movzwl	%ax, %eax
	shrl	$16, %edx
	addl	%edx, %eax
	ret
	.p2align 4,,7
L933:
	movl	$-1, %eax
	ret
	.cfi_endproc
LFE3651:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type7_After2i
	.def	__Z22testOpt08_Type7_After2i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type7_After2i:
LFB3652:
	.cfi_startproc
	movl	4(%esp), %edx
	xorl	%eax, %eax
	testb	$1, %dl
	jne	L935
	testb	$2, %dl
	movb	$1, %al
	jne	L935
	testb	$4, %dl
	movb	$2, %al
	je	L968
L935:
	rep ret
	.p2align 4,,7
L968:
	testb	$8, %dl
	movb	$3, %al
	jne	L935
	testb	$16, %dl
	movb	$4, %al
	jne	L935
	testb	$32, %dl
	movb	$5, %al
	jne	L935
	testb	$64, %dl
	movb	$6, %al
	jne	L935
	testb	$-128, %dl
	movb	$7, %al
	jne	L935
	testb	$1, %dh
	movb	$8, %al
	jne	L935
	testb	$2, %dh
	movb	$9, %al
	jne	L935
	testb	$4, %dh
	movb	$10, %al
	jne	L935
	testb	$8, %dh
	movb	$11, %al
	jne	L935
	testb	$16, %dh
	movb	$12, %al
	jne	L935
	testb	$32, %dh
	movb	$13, %al
	jne	L935
	testb	$64, %dh
	movb	$14, %al
	jne	L935
	testb	$128, %dh
	movb	$15, %al
	jne	L935
	testl	$65536, %edx
	movb	$16, %al
	jne	L935
	testl	$131072, %edx
	movb	$17, %al
	jne	L935
	testl	$262144, %edx
	movb	$18, %al
	jne	L935
	testl	$524288, %edx
	movb	$19, %al
	jne	L935
	testl	$1048576, %edx
	movb	$20, %al
	jne	L935
	testl	$2097152, %edx
	movb	$21, %al
	jne	L935
	testl	$4194304, %edx
	movb	$22, %al
	jne	L935
	testl	$8388608, %edx
	movb	$23, %al
	jne	L935
	testl	$16777216, %edx
	movb	$24, %al
	jne	L935
	testl	$33554432, %edx
	movb	$25, %al
	jne	L935
	testl	$67108864, %edx
	movb	$26, %al
	jne	L935
	testl	$134217728, %edx
	movb	$27, %al
	jne	L935
	testl	$268435456, %edx
	movb	$28, %al
	jne	L935
	testl	$536870912, %edx
	movb	$29, %al
	jne	L935
	testl	$1073741824, %edx
	movb	$30, %al
	jne	L935
	movl	%edx, %eax
	sarl	$31, %eax
	andl	$32, %eax
	subl	$1, %eax
	ret
	.cfi_endproc
LFE3652:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type8_Beforei
	.def	__Z22testOpt08_Type8_Beforei;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type8_Beforei:
LFB3653:
	.cfi_startproc
	movl	4(%esp), %eax
	cltd
	xorl	%edx, %eax
	subl	%edx, %eax
	ret
	.cfi_endproc
LFE3653:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type8_After1i
	.def	__Z22testOpt08_Type8_After1i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type8_After1i:
LFB3654:
	.cfi_startproc
	movl	4(%esp), %eax
	cltd
	xorl	%edx, %eax
	subl	%edx, %eax
	ret
	.cfi_endproc
LFE3654:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type8_After2i
	.def	__Z22testOpt08_Type8_After2i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type8_After2i:
LFB3655:
	.cfi_startproc
	movl	4(%esp), %eax
	cltd
	xorl	%edx, %eax
	subl	%edx, %eax
	ret
	.cfi_endproc
LFE3655:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type9_Beforei
	.def	__Z22testOpt08_Type9_Beforei;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type9_Beforei:
LFB3656:
	.cfi_startproc
	movl	4(%esp), %eax
	testl	%eax, %eax
	js	L974
	setne	%al
	movzbl	%al, %eax
	ret
	.p2align 4,,7
L974:
	movl	$-1, %eax
	ret
	.cfi_endproc
LFE3656:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type9_After1i
	.def	__Z22testOpt08_Type9_After1i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type9_After1i:
LFB3657:
	.cfi_startproc
	movl	4(%esp), %eax
	testl	%eax, %eax
	js	L977
	setne	%al
	movzbl	%al, %eax
	ret
	.p2align 4,,7
L977:
	movl	$-1, %eax
	ret
	.cfi_endproc
LFE3657:
	.p2align 4,,15
	.globl	__Z22testOpt08_Type9_After2i
	.def	__Z22testOpt08_Type9_After2i;	.scl	2;	.type	32;	.endef
__Z22testOpt08_Type9_After2i:
LFB3658:
	.cfi_startproc
	movl	4(%esp), %edx
	xorl	%eax, %eax
	testl	%edx, %edx
	setne	%al
	sarl	$31, %edx
	orl	%edx, %eax
	ret
	.cfi_endproc
LFE3658:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type1_BeforeR12dataOpt08_t1
	.def	__Z22testOpt09_Type1_BeforeR12dataOpt08_t1;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type1_BeforeR12dataOpt08_t1:
LFB3660:
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
	movl	%ebx, %eax
	andl	$15, %eax
	shrl	$2, %eax
	negl	%eax
	andl	$3, %eax
	je	L988
	cmpl	$1, %eax
	movl	(%ebx), %esi
	jbe	L989
	addl	4(%ebx), %esi
	cmpl	$2, %eax
	jbe	L990
	addl	8(%ebx), %esi
	movl	$9997, 4(%esp)
	movl	$3, (%esp)
L980:
	movl	$10000, %edi
	pxor	%xmm0, %xmm0
	subl	%eax, %edi
	movl	%edi, %ecx
	shrl	$2, %ecx
	leal	(%ebx,%eax,4), %edx
	xorl	%eax, %eax
	leal	0(,%ecx,4), %ebp
	.p2align 4,,7
L987:
	addl	$1, %eax
	addl	$16, %edx
	paddd	-16(%edx), %xmm0
	cmpl	%eax, %ecx
	ja	L987
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
	je	L985
	addl	(%ebx,%edx,4), %eax
	cmpl	$1, %ecx
	leal	1(%edx), %esi
	je	L985
	addl	(%ebx,%esi,4), %eax
	addl	$2, %edx
	cmpl	$2, %ecx
	je	L985
	addl	(%ebx,%edx,4), %eax
L985:
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
L988:
	.cfi_restore_state
	movl	$10000, 4(%esp)
	xorl	%esi, %esi
	movl	$0, (%esp)
	jmp	L980
	.p2align 4,,7
L989:
	movl	$9999, 4(%esp)
	movl	$1, (%esp)
	jmp	L980
	.p2align 4,,7
L990:
	movl	$9998, 4(%esp)
	movl	$2, (%esp)
	jmp	L980
	.cfi_endproc
LFE3660:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type1_After1R12dataOpt08_t1
	.def	__Z22testOpt09_Type1_After1R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type1_After1R12dataOpt08_t1:
LFB3661:
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
	movl	%ebx, %eax
	andl	$15, %eax
	shrl	$2, %eax
	testl	%eax, %eax
	je	L1006
	cmpl	$1, %eax
	movl	39996(%ebx), %esi
	jbe	L1007
	addl	39992(%ebx), %esi
	cmpl	$2, %eax
	jbe	L1008
	addl	39988(%ebx), %esi
	movl	$9997, 4(%esp)
	movl	$9996, (%esp)
L998:
	movl	$10000, %edi
	pxor	%xmm0, %xmm0
	subl	%eax, %edi
	negl	%eax
	movl	%edi, %ecx
	shrl	$2, %ecx
	leal	39984(%ebx,%eax,4), %edx
	xorl	%eax, %eax
	leal	0(,%ecx,4), %ebp
	.p2align 4,,7
L1005:
	addl	$1, %eax
	pshufd	$27, (%edx), %xmm1
	subl	$16, %edx
	cmpl	%eax, %ecx
	paddd	%xmm1, %xmm0
	ja	L1005
	movdqa	%xmm0, %xmm2
	movl	(%esp), %edx
	psrldq	$8, %xmm2
	movl	4(%esp), %ecx
	paddd	%xmm2, %xmm0
	movdqa	%xmm0, %xmm3
	psrldq	$4, %xmm3
	paddd	%xmm3, %xmm0
	pextrd	$0, %xmm0, %eax
	subl	%ebp, %edx
	addl	%esi, %eax
	subl	%ebp, %ecx
	cmpl	%ebp, %edi
	je	L1003
	addl	(%ebx,%edx,4), %eax
	cmpl	$1, %ecx
	leal	-1(%edx), %esi
	je	L1003
	addl	(%ebx,%esi,4), %eax
	subl	$2, %edx
	cmpl	$2, %ecx
	je	L1003
	addl	(%ebx,%edx,4), %eax
L1003:
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
L1006:
	.cfi_restore_state
	movl	$10000, 4(%esp)
	xorl	%esi, %esi
	movl	$9999, (%esp)
	jmp	L998
	.p2align 4,,7
L1007:
	movl	$9999, 4(%esp)
	movl	$9998, (%esp)
	jmp	L998
	.p2align 4,,7
L1008:
	movl	$9998, 4(%esp)
	movl	$9997, (%esp)
	jmp	L998
	.cfi_endproc
LFE3661:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type1_After2R12dataOpt08_t1
	.def	__Z22testOpt09_Type1_After2R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type1_After2R12dataOpt08_t1:
LFB3662:
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
	movl	$1, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$16, %esp
	.cfi_def_cfa_offset 36
	movl	36(%esp), %edx
	leal	40000(%edx), %eax
	movl	%eax, %ebx
	leal	1(%edx), %edi
	cmpl	%ebx, %edi
	movl	%edx, %ebx
	movl	%eax, (%esp)
	movl	$10000, %eax
	cmovbe	%eax, %esi
	andl	$15, %ebx
	shrl	$2, %ebx
	negl	%ebx
	andl	$3, %ebx
	cmpl	%esi, %ebx
	cmova	%esi, %ebx
	cmpl	$8, %eax
	leal	4(%edx), %ebp
	ja	L1036
L1027:
	movl	%esi, %ebx
L1016:
	cmpl	$1, %ebx
	movl	(%edx), %eax
	jbe	L1029
	addl	4(%edx), %eax
	cmpl	$2, %ebx
	leal	8(%edx), %ecx
	jbe	L1018
	addl	8(%edx), %eax
	cmpl	$3, %ebx
	leal	12(%edx), %ecx
	jbe	L1018
	addl	12(%edx), %eax
	cmpl	$4, %ebx
	leal	16(%edx), %ecx
	jbe	L1018
	addl	16(%edx), %eax
	cmpl	$5, %ebx
	leal	20(%edx), %ecx
	jbe	L1018
	addl	20(%edx), %eax
	cmpl	$6, %ebx
	leal	24(%edx), %ecx
	jbe	L1018
	addl	24(%edx), %eax
	cmpl	$7, %ebx
	leal	28(%edx), %ecx
	jbe	L1018
	addl	28(%edx), %eax
	leal	32(%edx), %ecx
L1018:
	cmpl	%ebx, %esi
	je	L1019
L1017:
	subl	%ebx, %esi
	movl	%esi, %edi
	shrl	$2, %edi
	leal	0(,%edi,4), %ebp
	testl	%ebp, %ebp
	je	L1020
	leal	(%edx,%ebx,4), %ebx
	xorl	%edx, %edx
	pxor	%xmm0, %xmm0
L1026:
	addl	$1, %edx
	addl	$16, %ebx
	paddd	-16(%ebx), %xmm0
	cmpl	%edx, %edi
	ja	L1026
	movdqa	%xmm0, %xmm2
	psrldq	$8, %xmm2
	paddd	%xmm2, %xmm0
	movdqa	%xmm0, %xmm3
	psrldq	$4, %xmm3
	paddd	%xmm3, %xmm0
	pextrd	$0, %xmm0, %edx
	addl	%edx, %eax
	cmpl	%ebp, %esi
	leal	(%ecx,%ebp,4), %ecx
	je	L1019
L1020:
	movl	(%esp), %edi
	leal	4(%ecx), %edx
	addl	(%ecx), %eax
	cmpl	%edx, %edi
	jbe	L1019
	leal	8(%ecx), %edx
	addl	4(%ecx), %eax
	cmpl	%edx, %edi
	jbe	L1019
	addl	8(%ecx), %eax
L1019:
	addl	$16, %esp
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
L1036:
	.cfi_restore_state
	cmpl	(%esp), %edi
	ja	L1027
	testl	%ebx, %ebx
	jne	L1016
	movl	%edx, %ecx
	xorl	%ebx, %ebx
	xorl	%eax, %eax
	jmp	L1017
	.p2align 4,,7
L1029:
	movl	%ebp, %ecx
	jmp	L1018
	.cfi_endproc
LFE3662:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type1_After3R12dataOpt08_t1
	.def	__Z22testOpt09_Type1_After3R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type1_After3R12dataOpt08_t1:
LFB3663:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	movl	$5000, %edi
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$1, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$20, %esp
	.cfi_def_cfa_offset 40
	movl	40(%esp), %ecx
	leal	40000(%ecx), %ebx
	movl	%ecx, %edx
	leal	1(%ecx), %ebp
	cmpl	%ebp, %ebx
	cmovae	%edi, %esi
	movl	%esi, %eax
	shrl	%eax
	movl	%eax, (%esp)
	addl	%eax, %eax
	movl	%eax, 4(%esp)
	je	L1045
	cmpl	$4, %edi
	setbe	%al
	cmpl	%ebp, %ebx
	movl	%eax, %edi
	setb	%al
	movl	%eax, %ebp
	orl	%ebp, %edi
	movl	%edi, %eax
	cmpb	$1, %al
	sbbl	%edi, %edi
	movl	%edi, %eax
	cmpb	$-1, %al
	jne	L1045
	movl	(%esp), %eax
	xorl	%edx, %edx
	pxor	%xmm0, %xmm0
L1044:
	movl	%edx, %edi
	addl	$1, %edx
	sall	$4, %edi
	cmpl	%edx, %eax
	movdqu	(%ecx,%edi), %xmm1
	paddd	%xmm1, %xmm0
	ja	L1044
	movl	4(%esp), %edi
	movdqa	%xmm0, %xmm2
	psrldq	$8, %xmm2
	paddd	%xmm2, %xmm0
	movdqa	%xmm0, %xmm3
	psrldq	$4, %xmm3
	paddd	%xmm3, %xmm0
	cmpl	%edi, %esi
	pextrd	$0, %xmm0, %eax
	leal	(%ecx,%edi,8), %edx
	je	L1042
L1038:
	leal	8(%edx), %ecx
	addl	(%edx), %eax
	addl	4(%edx), %eax
	cmpl	%ecx, %ebx
	jbe	L1042
	leal	16(%edx), %ecx
	addl	8(%edx), %eax
	addl	12(%edx), %eax
	cmpl	%ecx, %ebx
	jbe	L1042
	leal	24(%edx), %ecx
	addl	16(%edx), %eax
	addl	20(%edx), %eax
	cmpl	%ecx, %ebx
	jbe	L1042
	addl	24(%edx), %eax
	addl	28(%edx), %eax
L1042:
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
L1045:
	.cfi_restore_state
	xorl	%eax, %eax
	jmp	L1038
	.cfi_endproc
LFE3663:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type1_After4R12dataOpt08_t1
	.def	__Z22testOpt09_Type1_After4R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type1_After4R12dataOpt08_t1:
LFB3664:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	movl	$2500, %ecx
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %edx
	movl	$1, %eax
	leal	1(%edx), %ebx
	leal	40000(%edx), %esi
	cmpl	%ebx, %esi
	cmovae	%ecx, %eax
	cmpl	$1, %ecx
	jbe	L1050
	cmpl	%ebx, %esi
	jb	L1050
	xorw	%cx, %cx
	pxor	%xmm0, %xmm0
L1053:
	movl	%ecx, %ebx
	addl	$1, %ecx
	sall	$4, %ebx
	cmpl	%ecx, %eax
	movdqu	(%edx,%ebx), %xmm1
	paddd	%xmm1, %xmm0
	ja	L1053
	movdqa	%xmm0, %xmm2
	psrldq	$8, %xmm2
	paddd	%xmm2, %xmm0
	movdqa	%xmm0, %xmm3
	psrldq	$4, %xmm3
	paddd	%xmm3, %xmm0
	pextrd	$0, %xmm0, %eax
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L1050:
	.cfi_restore_state
	movl	(%edx), %eax
	addl	4(%edx), %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	addl	8(%edx), %eax
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	addl	12(%edx), %eax
	ret
	.cfi_endproc
LFE3664:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type1_After5R12dataOpt08_t1
	.def	__Z22testOpt09_Type1_After5R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type1_After5R12dataOpt08_t1:
LFB3665:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$1000, %eax
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$1, %ebx
	subl	$17, %esp
	.cfi_def_cfa_offset 37
	movl	37(%esp), %ecx
	leal	1(%ecx), %edi
	movl	%ecx, %edx
	leal	40000(%ecx), %ebp
	cmpl	%edi, %ebp
	cmovae	%eax, %ebx
	movl	%ebx, %esi
	shrl	%esi
	movl	%esi, 1(%esp)
	addl	%esi, %esi
	je	L1060
	cmpl	$1, %eax
	setbe	(%esp)
	cmpl	%edi, %ebp
	setb	%al
	orb	%al, (%esp)
	cmpb	$1, (%esp)
	sbbl	%eax, %eax
	cmpb	$-1, %al
	jne	L1060
	movl	%ecx, %eax
	xorl	%edx, %edx
	pxor	%xmm1, %xmm1
	movdqa	%xmm1, %xmm2
	movdqa	%xmm1, %xmm3
	movdqa	%xmm1, %xmm0
	movdqa	%xmm1, %xmm4
L1059:
	movdqu	(%eax), %xmm5
	addl	$1, %edx
	paddd	%xmm5, %xmm4
	addl	$80, %eax
	movdqu	-64(%eax), %xmm5
	paddd	%xmm5, %xmm0
	movdqu	-48(%eax), %xmm5
	paddd	%xmm5, %xmm3
	movdqu	-32(%eax), %xmm5
	paddd	%xmm5, %xmm2
	movdqu	-16(%eax), %xmm5
	paddd	%xmm5, %xmm1
	cmpl	1(%esp), %edx
	jb	L1059
	paddd	%xmm4, %xmm0
	cmpl	%ebx, %esi
	paddd	%xmm3, %xmm0
	paddd	%xmm2, %xmm0
	paddd	%xmm1, %xmm0
	movdqa	%xmm0, %xmm6
	psrldq	$8, %xmm6
	paddd	%xmm6, %xmm0
	movdqa	%xmm0, %xmm7
	psrldq	$4, %xmm7
	paddd	%xmm7, %xmm0
	leal	(%esi,%esi,4), %edx
	pextrd	$0, %xmm0, %eax
	leal	(%ecx,%edx,8), %edx
	je	L1058
L1056:
	addl	(%edx), %eax
	addl	4(%edx), %eax
	addl	8(%edx), %eax
	addl	12(%edx), %eax
	addl	16(%edx), %eax
	addl	20(%edx), %eax
	addl	24(%edx), %eax
	addl	28(%edx), %eax
	addl	32(%edx), %eax
	addl	36(%edx), %eax
L1058:
	addl	$17, %esp
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
L1060:
	.cfi_restore_state
	xorl	%eax, %eax
	jmp	L1056
	.cfi_endproc
LFE3665:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type1_After6R12dataOpt08_t1
	.def	__Z22testOpt09_Type1_After6R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type1_After6R12dataOpt08_t1:
LFB3666:
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
	subl	$16, %esp
	.cfi_def_cfa_offset 36
	movl	36(%esp), %edx
	leal	40000(%edx), %esi
	movl	%edx, %eax
	andl	$15, %eax
	movl	%esi, %edi
	leal	4(%edx), %ebp
	subl	%ebp, %edi
	shrl	$2, %eax
	shrl	$2, %edi
	negl	%eax
	addl	$1, %edi
	andl	$3, %eax
	cmpl	%edi, %eax
	movl	%edi, %ebx
	cmova	%edi, %eax
	cmpl	$8, %edi
	ja	L1085
L1064:
	cmpl	$1, %ebx
	movl	(%edx), %eax
	jbe	L1078
	addl	4(%edx), %eax
	cmpl	$2, %ebx
	leal	8(%edx), %ecx
	jbe	L1066
	addl	8(%edx), %eax
	cmpl	$3, %ebx
	leal	12(%edx), %ecx
	jbe	L1066
	addl	12(%edx), %eax
	cmpl	$4, %ebx
	leal	16(%edx), %ecx
	jbe	L1066
	addl	16(%edx), %eax
	cmpl	$5, %ebx
	leal	20(%edx), %ecx
	jbe	L1066
	addl	20(%edx), %eax
	cmpl	$6, %ebx
	leal	24(%edx), %ecx
	jbe	L1066
	addl	24(%edx), %eax
	cmpl	$7, %ebx
	leal	28(%edx), %ecx
	jbe	L1066
	addl	28(%edx), %eax
	leal	32(%edx), %ecx
L1066:
	cmpl	%ebx, %edi
	je	L1063
L1065:
	subl	%ebx, %edi
	movl	%edi, (%esp)
	shrl	$2, %edi
	leal	0(,%edi,4), %ebp
	testl	%ebp, %ebp
	je	L1068
	leal	(%edx,%ebx,4), %ebx
	xorl	%edx, %edx
	pxor	%xmm0, %xmm0
L1074:
	addl	$1, %edx
	addl	$16, %ebx
	paddd	-16(%ebx), %xmm0
	cmpl	%edx, %edi
	ja	L1074
	movdqa	%xmm0, %xmm2
	psrldq	$8, %xmm2
	paddd	%xmm2, %xmm0
	movdqa	%xmm0, %xmm3
	psrldq	$4, %xmm3
	paddd	%xmm3, %xmm0
	pextrd	$0, %xmm0, %edx
	addl	%edx, %eax
	cmpl	%ebp, (%esp)
	leal	(%ecx,%ebp,4), %ecx
	je	L1063
L1068:
	leal	4(%ecx), %edx
	addl	(%ecx), %eax
	cmpl	%edx, %esi
	je	L1063
	leal	8(%ecx), %edx
	addl	4(%ecx), %eax
	cmpl	%edx, %esi
	je	L1063
	addl	8(%ecx), %eax
L1063:
	addl	$16, %esp
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
L1085:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L1086
	movl	%edx, %ecx
	xorl	%ebx, %ebx
	xorl	%eax, %eax
	jmp	L1065
	.p2align 4,,7
L1078:
	movl	%ebp, %ecx
	jmp	L1066
L1086:
	movl	%eax, %ebx
	jmp	L1064
	.cfi_endproc
LFE3666:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type2_BeforeR12dataOpt08_t2
	.def	__Z22testOpt09_Type2_BeforeR12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type2_BeforeR12dataOpt08_t2:
LFB3668:
	.cfi_startproc
	movl	4(%esp), %ecx
	xorl	%edx, %edx
	xorl	%eax, %eax
	.p2align 4,,7
L1089:
	addl	4(%ecx,%edx), %eax
	subl	(%ecx,%edx), %eax
	addl	$48, %edx
	cmpl	$480000, %edx
	jne	L1089
	rep ret
	.cfi_endproc
LFE3668:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type2_After1R12dataOpt08_t2
	.def	__Z22testOpt09_Type2_After1R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type2_After1R12dataOpt08_t2:
LFB3669:
	.cfi_startproc
	movl	4(%esp), %ecx
	xorl	%edx, %edx
	xorl	%eax, %eax
	.p2align 4,,7
L1092:
	addl	479956(%ecx,%edx), %eax
	subl	479952(%ecx,%edx), %eax
	subl	$48, %edx
	cmpl	$-480000, %edx
	jne	L1092
	rep ret
	.cfi_endproc
LFE3669:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type2_After2R12dataOpt08_t2
	.def	__Z22testOpt09_Type2_After2R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type2_After2R12dataOpt08_t2:
LFB3670:
	.cfi_startproc
	movl	4(%esp), %edx
	xorl	%eax, %eax
	leal	480000(%edx), %ecx
	.p2align 4,,7
L1095:
	addl	4(%edx), %eax
	addl	$48, %edx
	subl	-48(%edx), %eax
	cmpl	%edx, %ecx
	ja	L1095
	rep ret
	.cfi_endproc
LFE3670:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type2_After3R12dataOpt08_t2
	.def	__Z22testOpt09_Type2_After3R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type2_After3R12dataOpt08_t2:
LFB3671:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %edx
	xorl	%eax, %eax
	leal	480000(%edx), %ebx
	leal	52(%edx), %ecx
	.p2align 4,,7
L1098:
	addl	4(%edx), %eax
	addl	$96, %edx
	subl	-96(%edx), %eax
	addl	$96, %ecx
	addl	-96(%ecx), %eax
	subl	-100(%ecx), %eax
	cmpl	%edx, %ebx
	ja	L1098
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3671:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type2_After4R12dataOpt08_t2
	.def	__Z22testOpt09_Type2_After4R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type2_After4R12dataOpt08_t2:
LFB3672:
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
	subl	$4, %esp
	.cfi_def_cfa_offset 24
	movl	24(%esp), %ebp
	leal	480000(%ebp), %eax
	movl	%ebp, %edx
	movl	%eax, (%esp)
	leal	52(%ebp), %ebx
	xorl	%eax, %eax
	leal	100(%ebp), %ecx
	leal	144(%ebp), %edi
	.p2align 4,,7
L1102:
	movl	%edx, %esi
	addl	$192, %ebx
	subl	%ebp, %esi
	addl	$192, %edx
	addl	-188(%edx), %eax
	addl	$192, %ecx
	subl	-192(%edx), %eax
	addl	-192(%ebx), %eax
	subl	-196(%ebx), %eax
	addl	-192(%ecx), %eax
	subl	-196(%ecx), %eax
	addl	4(%esi,%edi), %eax
	subl	(%esi,%edi), %eax
	cmpl	%edx, (%esp)
	ja	L1102
	addl	$4, %esp
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
LFE3672:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type2_After5R12dataOpt08_t2
	.def	__Z22testOpt09_Type2_After5R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type2_After5R12dataOpt08_t2:
LFB3673:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	xorl	%edx, %edx
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
	movl	48(%esp), %eax
	movl	48(%esp), %ecx
	addl	$480000, %eax
	movl	%eax, (%esp)
	movl	%ecx, %eax
	addl	$96, %eax
	movl	%eax, 8(%esp)
	movl	%ecx, %eax
	addl	$144, %eax
	movl	%eax, 16(%esp)
	movl	%ecx, %eax
	addl	$192, %eax
	movl	%eax, 20(%esp)
	movl	%ecx, %eax
	addl	$384, %eax
	movl	%eax, 4(%esp)
	movl	%ecx, %eax
	leal	336(%ecx), %ebx
	addl	$432, %eax
	leal	48(%ecx), %ebp
	leal	240(%ecx), %edi
	leal	288(%ecx), %esi
	movl	%eax, 12(%esp)
	movl	%ebx, 24(%esp)
	.p2align 4,,7
L1106:
	movl	8(%esp), %ebx
	movl	%ecx, %eax
	addl	$480, %ecx
	subl	48(%esp), %eax
	addl	-476(%ecx), %edx
	subl	-480(%ecx), %edx
	addl	4(%eax,%ebp), %edx
	subl	(%eax,%ebp), %edx
	addl	4(%eax,%ebx), %edx
	subl	(%eax,%ebx), %edx
	movl	16(%esp), %ebx
	addl	4(%eax,%ebx), %edx
	subl	(%eax,%ebx), %edx
	movl	20(%esp), %ebx
	addl	4(%eax,%ebx), %edx
	subl	(%eax,%ebx), %edx
	movl	24(%esp), %ebx
	addl	4(%eax,%edi), %edx
	subl	(%eax,%edi), %edx
	addl	4(%eax,%esi), %edx
	subl	(%eax,%esi), %edx
	addl	4(%eax,%ebx), %edx
	subl	(%eax,%ebx), %edx
	movl	4(%esp), %ebx
	addl	4(%eax,%ebx), %edx
	subl	(%eax,%ebx), %edx
	movl	12(%esp), %ebx
	addl	4(%eax,%ebx), %edx
	subl	(%eax,%ebx), %edx
	cmpl	%ecx, (%esp)
	ja	L1106
	addl	$28, %esp
	.cfi_def_cfa_offset 20
	movl	%edx, %eax
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
LFE3673:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type2_After6R12dataOpt08_t2
	.def	__Z22testOpt09_Type2_After6R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type2_After6R12dataOpt08_t2:
LFB3674:
	.cfi_startproc
	movl	4(%esp), %edx
	xorl	%eax, %eax
	leal	480000(%edx), %ecx
	.p2align 4,,7
L1110:
	addl	4(%edx), %eax
	addl	$48, %edx
	subl	-48(%edx), %eax
	cmpl	%edx, %ecx
	jne	L1110
	rep ret
	.cfi_endproc
LFE3674:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type3_BeforePN12dataOpt08_t26elem_tEj
	.def	__Z22testOpt09_Type3_BeforePN12dataOpt08_t26elem_tEj;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type3_BeforePN12dataOpt08_t26elem_tEj:
LFB3675:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	16(%esp), %ebx
	movl	12(%esp), %esi
	testl	%ebx, %ebx
	je	L1115
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	xorl	%eax, %eax
	.p2align 4,,7
L1114:
	leal	(%ecx,%ecx,2), %ecx
	addl	$1, %edx
	sall	$4, %ecx
	addl	%esi, %ecx
	addl	4(%ecx), %eax
	subl	(%ecx), %eax
	cmpl	%ebx, %edx
	movl	%edx, %ecx
	jne	L1114
L1113:
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
L1115:
	.cfi_restore_state
	xorl	%eax, %eax
	jmp	L1113
	.cfi_endproc
LFE3675:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type3_After1PN12dataOpt08_t26elem_tEj
	.def	__Z22testOpt09_Type3_After1PN12dataOpt08_t26elem_tEj;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type3_After1PN12dataOpt08_t26elem_tEj:
LFB3676:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	%eax, %ecx
	subl	$1, %ecx
	js	L1120
	leal	(%eax,%eax,2), %edx
	xorl	%eax, %eax
	sall	$4, %edx
	addl	4(%esp), %edx
	.p2align 4,,7
L1119:
	addl	-44(%edx), %eax
	subl	$48, %edx
	subl	(%edx), %eax
	subl	$1, %ecx
	jns	L1119
	rep ret
L1120:
	xorl	%eax, %eax
	ret
	.cfi_endproc
LFE3676:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type3_After2PN12dataOpt08_t26elem_tEj
	.def	__Z22testOpt09_Type3_After2PN12dataOpt08_t26elem_tEj;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type3_After2PN12dataOpt08_t26elem_tEj:
LFB3677:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	4(%esp), %edx
	leal	(%eax,%eax,2), %ecx
	xorl	%eax, %eax
	sall	$4, %ecx
	addl	%edx, %ecx
	cmpl	%ecx, %edx
	jae	L1124
	.p2align 4,,7
L1123:
	addl	4(%edx), %eax
	addl	$48, %edx
	subl	-48(%edx), %eax
	cmpl	%edx, %ecx
	ja	L1123
	rep ret
L1124:
	rep ret
	.cfi_endproc
LFE3677:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type3_After3PN12dataOpt08_t26elem_tEj
	.def	__Z22testOpt09_Type3_After3PN12dataOpt08_t26elem_tEj;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type3_After3PN12dataOpt08_t26elem_tEj:
LFB3678:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	12(%esp), %eax
	movl	8(%esp), %edx
	leal	(%eax,%eax,2), %ebx
	sall	$4, %ebx
	addl	%edx, %ebx
	cmpl	%ebx, %edx
	jae	L1128
	leal	52(%edx), %ecx
	xorl	%eax, %eax
	.p2align 4,,7
L1127:
	addl	4(%edx), %eax
	addl	$96, %edx
	subl	-96(%edx), %eax
	addl	$96, %ecx
	addl	-96(%ecx), %eax
	subl	-100(%ecx), %eax
	cmpl	%edx, %ebx
	ja	L1127
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L1128:
	.cfi_restore_state
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3678:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type3_After4PN12dataOpt08_t26elem_tEj
	.def	__Z22testOpt09_Type3_After4PN12dataOpt08_t26elem_tEj;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type3_After4PN12dataOpt08_t26elem_tEj:
LFB3679:
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
	subl	$4, %esp
	.cfi_def_cfa_offset 24
	movl	28(%esp), %eax
	movl	24(%esp), %ebp
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	addl	%ebp, %eax
	cmpl	%eax, %ebp
	movl	%eax, (%esp)
	jae	L1133
	leal	52(%ebp), %ebx
	movl	%ebp, %edx
	leal	100(%ebp), %ecx
	xorl	%eax, %eax
	leal	144(%ebp), %edi
	.p2align 4,,7
L1132:
	movl	%edx, %esi
	addl	$192, %ebx
	subl	%ebp, %esi
	addl	$192, %edx
	addl	-188(%edx), %eax
	addl	$192, %ecx
	subl	-192(%edx), %eax
	addl	-192(%ebx), %eax
	subl	-196(%ebx), %eax
	addl	-192(%ecx), %eax
	subl	-196(%ecx), %eax
	addl	4(%esi,%edi), %eax
	subl	(%esi,%edi), %eax
	cmpl	%edx, (%esp)
	ja	L1132
L1131:
	addl	$4, %esp
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
L1133:
	.cfi_restore_state
	xorl	%eax, %eax
	jmp	L1131
	.cfi_endproc
LFE3679:
	.p2align 4,,15
	.globl	__Z22testOpt09_Type3_After5PN12dataOpt08_t26elem_tEj
	.def	__Z22testOpt09_Type3_After5PN12dataOpt08_t26elem_tEj;	.scl	2;	.type	32;	.endef
__Z22testOpt09_Type3_After5PN12dataOpt08_t26elem_tEj:
LFB3680:
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
	movl	52(%esp), %eax
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	addl	48(%esp), %eax
	cmpl	%eax, 48(%esp)
	movl	%eax, (%esp)
	jae	L1138
	movl	48(%esp), %ecx
	xorl	%edx, %edx
	movl	%ecx, %eax
	addl	$96, %eax
	movl	%eax, 12(%esp)
	movl	%ecx, %eax
	addl	$144, %eax
	movl	%eax, 16(%esp)
	movl	%ecx, %eax
	addl	$192, %eax
	movl	%eax, 20(%esp)
	movl	%ecx, %eax
	addl	$384, %eax
	movl	%eax, 4(%esp)
	movl	%ecx, %eax
	leal	336(%ecx), %ebx
	addl	$432, %eax
	leal	48(%ecx), %ebp
	leal	240(%ecx), %edi
	leal	288(%ecx), %esi
	movl	%eax, 8(%esp)
	movl	%ebx, 24(%esp)
	.p2align 4,,7
L1137:
	movl	12(%esp), %ebx
	movl	%ecx, %eax
	addl	$480, %ecx
	subl	48(%esp), %eax
	addl	-476(%ecx), %edx
	subl	-480(%ecx), %edx
	addl	4(%eax,%ebp), %edx
	subl	(%eax,%ebp), %edx
	addl	4(%eax,%ebx), %edx
	subl	(%eax,%ebx), %edx
	movl	16(%esp), %ebx
	addl	4(%eax,%ebx), %edx
	subl	(%eax,%ebx), %edx
	movl	20(%esp), %ebx
	addl	4(%eax,%ebx), %edx
	subl	(%eax,%ebx), %edx
	movl	24(%esp), %ebx
	addl	4(%eax,%edi), %edx
	subl	(%eax,%edi), %edx
	addl	4(%eax,%esi), %edx
	subl	(%eax,%esi), %edx
	addl	4(%eax,%ebx), %edx
	subl	(%eax,%ebx), %edx
	movl	4(%esp), %ebx
	addl	4(%eax,%ebx), %edx
	subl	(%eax,%ebx), %edx
	movl	8(%esp), %ebx
	addl	4(%eax,%ebx), %edx
	subl	(%eax,%ebx), %edx
	cmpl	%ecx, (%esp)
	ja	L1137
L1136:
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	%edx, %eax
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
L1138:
	.cfi_restore_state
	xorl	%edx, %edx
	jmp	L1136
	.cfi_endproc
LFE3680:
	.section .rdata,"dr"
	.align 4
LC199:
	.ascii "lambda1()=%d, lambda2()=%d, lambda3()=%d\12\0"
	.text
	.p2align 4,,15
	.globl	__Z13callLambda123v
	.def	__Z13callLambda123v;	.scl	2;	.type	32;	.endef
__Z13callLambda123v:
LFB3684:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	_s_lambda3+8, %edx
	testl	%edx, %edx
	je	L1142
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L1142
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L1142
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC199, (%esp)
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
L1142:
	.cfi_restore_state
	call	__ZSt25__throw_bad_function_callv
	.cfi_endproc
LFE3684:
	.section .rdata,"dr"
	.align 4
LC200:
	.ascii "lambda1()=%d, lambda2()=NG!, lambda3()=%d\12\0"
	.text
	.p2align 4,,15
	.globl	__Z12callLambda13v
	.def	__Z12callLambda13v;	.scl	2;	.type	32;	.endef
__Z12callLambda13v:
LFB3685:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	_s_lambda3+8, %ebx
	testl	%ebx, %ebx
	je	L1146
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	_s_lambda1+8, %ecx
	testl	%ecx, %ecx
	movl	%eax, %ebx
	je	L1146
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 8(%esp)
	movl	$LC200, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L1146:
	.cfi_restore_state
	call	__ZSt25__throw_bad_function_callv
	.cfi_endproc
LFE3685:
	.section .rdata,"dr"
	.align 4
LC201:
	.ascii "Call lambda in block with counter in setLambda().\0"
LC202:
	.ascii "dummy=%d\12\0"
	.align 4
LC203:
	.ascii "Call lambda in block without counter in setLambda().\0"
	.align 4
LC204:
	.ascii "for lambda1: external_counter=%d\12\0"
	.align 4
LC205:
	.ascii "for lambda2: local_counter=%d\12\0"
	.align 4
LC206:
	.ascii "for lambda3: static_counter=%d\12\0"
	.text
	.p2align 4,,15
	.globl	__Z9setLambdaRi
	.def	__Z9setLambdaRi;	.scl	2;	.type	32;	.endef
__Z9setLambdaRi:
LFB3686:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3686
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$52, %esp
	.cfi_def_cfa_offset 64
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L1149
	movl	_s_lambda2+8, %esi
	testl	%esi, %esi
	je	L1149
L1150:
	movl	$999, 4(%esp)
	movl	$LC202, (%esp)
LEHB10:
	call	_printf
	movl	$LC203, (%esp)
	call	_puts
	movl	_s_lambda3+8, %ebx
	testl	%ebx, %ebx
	je	L1164
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	_s_lambda2+8, %ecx
	testl	%ecx, %ecx
	movl	%eax, %ebx
	je	L1164
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	_s_lambda1+8, %edx
	testl	%edx, %edx
	movl	%eax, %esi
	je	L1164
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC199, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L1164
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L1164
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L1164
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC199, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L1164
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L1164
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L1164
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC199, (%esp)
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
L1149:
	.cfi_restore_state
	movl	64(%esp), %eax
	movl	$0, 16(%esp)
	movl	(%eax), %eax
	movl	$LC204, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	16(%esp), %eax
	movl	$LC205, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	__ZZ9setLambdaRiE14static_counter, %eax
	movl	$LC206, (%esp)
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
	je	L1152
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1152:
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
	je	L1156
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1156:
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
	je	L1160
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1160:
	movl	$LC201, (%esp)
LEHB14:
	call	_puts
	movl	_s_lambda3+8, %ebx
	testl	%ebx, %ebx
	je	L1164
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	_s_lambda2+8, %ecx
	testl	%ecx, %ecx
	movl	%eax, %ebx
	je	L1164
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	_s_lambda1+8, %edx
	testl	%edx, %edx
	movl	%eax, %esi
	je	L1164
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC199, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L1164
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L1164
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L1164
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC199, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L1164
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L1164
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L1164
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC199, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	jmp	L1150
L1164:
	call	__ZSt25__throw_bad_function_callv
LEHE14:
L1166:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1162
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
L1162:
	movl	%ebx, (%esp)
LEHB15:
	call	__Unwind_Resume
LEHE15:
L1167:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1162
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L1162
L1168:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1162
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L1162
	.cfi_endproc
LFE3686:
	.section	.gcc_except_table,"w"
LLSDA3686:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3686-LLSDACSB3686
LLSDACSB3686:
	.uleb128 LEHB10-LFB3686
	.uleb128 LEHE10-LEHB10
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB11-LFB3686
	.uleb128 LEHE11-LEHB11
	.uleb128 L1166-LFB3686
	.uleb128 0
	.uleb128 LEHB12-LFB3686
	.uleb128 LEHE12-LEHB12
	.uleb128 L1167-LFB3686
	.uleb128 0
	.uleb128 LEHB13-LFB3686
	.uleb128 LEHE13-LEHB13
	.uleb128 L1168-LFB3686
	.uleb128 0
	.uleb128 LEHB14-LFB3686
	.uleb128 LEHE14-LEHB14
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB15-LFB3686
	.uleb128 LEHE15-LEHB15
	.uleb128 0
	.uleb128 0
LLSDACSE3686:
	.text
	.p2align 4,,15
	.globl	__Z10getLambda1v
	.def	__Z10getLambda1v;	.scl	2;	.type	32;	.endef
__Z10getLambda1v:
LFB3692:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3692
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
	je	L1180
	movl	_s_lambda1+12, %edx
	movl	%eax, 8(%ebx)
	movl	%edx, 12(%ebx)
	movl	$2, 8(%esp)
	movl	$_s_lambda1, 4(%esp)
	movl	%ebx, (%esp)
LEHB16:
	call	*_s_lambda1+8
LEHE16:
L1180:
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
L1184:
	.cfi_restore_state
	movl	8(%ebx), %edx
	movl	%eax, %esi
	testl	%edx, %edx
	je	L1183
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%edx
L1183:
	movl	%esi, (%esp)
LEHB17:
	call	__Unwind_Resume
LEHE17:
	.cfi_endproc
LFE3692:
	.section	.gcc_except_table,"w"
LLSDA3692:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3692-LLSDACSB3692
LLSDACSB3692:
	.uleb128 LEHB16-LFB3692
	.uleb128 LEHE16-LEHB16
	.uleb128 L1184-LFB3692
	.uleb128 0
	.uleb128 LEHB17-LFB3692
	.uleb128 LEHE17-LEHB17
	.uleb128 0
	.uleb128 0
LLSDACSE3692:
	.text
	.p2align 4,,15
	.globl	__Z10getLambda2v
	.def	__Z10getLambda2v;	.scl	2;	.type	32;	.endef
__Z10getLambda2v:
LFB3693:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3693
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
	je	L1192
	movl	_s_lambda1+12, %edx
	movl	%eax, 8(%ebx)
	movl	%edx, 12(%ebx)
	movl	$2, 8(%esp)
	movl	$_s_lambda1, 4(%esp)
	movl	%ebx, (%esp)
LEHB18:
	call	*_s_lambda1+8
LEHE18:
L1192:
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
L1196:
	.cfi_restore_state
	movl	8(%ebx), %edx
	movl	%eax, %esi
	testl	%edx, %edx
	je	L1195
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%edx
L1195:
	movl	%esi, (%esp)
LEHB19:
	call	__Unwind_Resume
LEHE19:
	.cfi_endproc
LFE3693:
	.section	.gcc_except_table,"w"
LLSDA3693:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3693-LLSDACSB3693
LLSDACSB3693:
	.uleb128 LEHB18-LFB3693
	.uleb128 LEHE18-LEHB18
	.uleb128 L1196-LFB3693
	.uleb128 0
	.uleb128 LEHB19-LFB3693
	.uleb128 LEHE19-LEHB19
	.uleb128 0
	.uleb128 0
LLSDACSE3693:
	.text
	.section	.text$_Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	.def	__Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
__Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE:
LFB3788:
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
	jne	L1224
	testl	$2, %edi
	jne	L1225
L1206:
	movl	%ebx, %ecx
	xorl	%eax, %eax
	shrl	$2, %ecx
	testb	$2, %bl
	rep stosl
	je	L1207
	xorl	%eax, %eax
	addl	$2, %edi
	movw	%ax, -2(%edi)
L1207:
	andl	$1, %ebx
	je	L1208
	movb	$0, (%edi)
L1208:
	movl	52(%esp), %edi
	xorl	%ebx, %ebx
	xorl	%eax, %eax
L1209:
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
	jne	L1209
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
L1224:
	.cfi_restore_state
	leal	1(%esi), %edi
	movb	$63, %bl
	testl	$2, %edi
	movb	$0, (%esi)
	je	L1206
	.p2align 4,,7
L1225:
	xorl	%eax, %eax
	addl	$2, %edi
	movw	%ax, -2(%edi)
	subl	$2, %ebx
	jmp	L1206
	.cfi_endproc
LFE3788:
	.section	.text$_Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	.def	__Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
__Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE:
LFB3789:
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
LFE3789:
	.section	.text$_Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	.def	__Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
__Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE:
LFB3790:
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
LFE3790:
	.section	.text$_Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	.def	__Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
__Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE:
LFB3791:
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
LFE3791:
	.section	.text$_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	.def	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv;	.scl	2;	.type	32;	.endef
__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv:
LFB3900:
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
	ja	L1233
	leal	1(%eax), %ecx
	movl	(%edx,%eax,4), %eax
L1234:
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
L1233:
	.cfi_restore_state
	movl	%edx, %eax
	andl	$15, %eax
	shrl	$2, %eax
	negl	%eax
	andl	$3, %eax
	je	L1250
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
	jbe	L1251
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
	jbe	L1252
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
L1235:
	movl	$227, 4(%esp)
	xorl	%ecx, %ecx
	movdqa	LC207, %xmm2
	subl	%eax, 4(%esp)
	movdqa	LC208, %xmm3
	movdqa	LC209, %xmm4
	sall	$2, %eax
	movdqa	LC210, %xmm5
	pxor	%xmm6, %xmm6
	leal	(%edx,%eax), %ebx
	leal	4(%edx,%eax), %edi
	leal	1588(%edx,%eax), %esi
	xorl	%eax, %eax
	.p2align 4,,7
L1241:
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
	jbe	L1241
	cmpl	$224, 4(%esp)
	leal	224(%ebp), %eax
	je	L1239
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
	je	L1239
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
	je	L1239
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
L1239:
	leal	908(%edx), %eax
	andl	$15, %eax
	shrl	$2, %eax
	negl	%eax
	andl	$3, %eax
	je	L1253
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
	jbe	L1254
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
	jbe	L1255
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
L1242:
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
L1248:
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
	ja	L1248
	movl	12(%esp), %edi
	movl	4(%esp), %eax
	movl	8(%esp), %ecx
	movl	(%esp), %esi
	subl	%edi, %eax
	addl	%edi, %ecx
	cmpl	%esi, %edi
	movl	%eax, 4(%esp)
	je	L1246
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
	je	L1246
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
	je	L1246
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
L1246:
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
	jmp	L1234
	.p2align 4,,7
L1252:
	movl	$225, (%esp)
	movl	$2, %ebp
	jmp	L1235
	.p2align 4,,7
L1251:
	movl	$226, (%esp)
	movl	$1, %ebp
	jmp	L1235
	.p2align 4,,7
L1250:
	movl	$227, (%esp)
	xorl	%ebp, %ebp
	jmp	L1235
	.p2align 4,,7
L1253:
	movl	$396, 4(%esp)
	movl	$227, 8(%esp)
	jmp	L1242
	.p2align 4,,7
L1255:
	movl	$394, 4(%esp)
	movl	$229, 8(%esp)
	jmp	L1242
	.p2align 4,,7
L1254:
	movl	$395, 4(%esp)
	movl	$228, 8(%esp)
	jmp	L1242
	.cfi_endproc
LFE3900:
	.text
	.p2align 4,,15
	.globl	__Z9initOpt06R11dataOpt06_t
	.def	__Z9initOpt06R11dataOpt06_t;	.scl	2;	.type	32;	.endef
__Z9initOpt06R11dataOpt06_t:
LFB3526:
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
L1273:
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
	jne	L1273
	leal	80000(%ebp), %ebx
	cmpl	%ebx, %ebp
	movl	$624, 2512(%esp)
	je	L1271
	.p2align 4,,7
L1277:
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
	fmuls	LC211
	fmuls	LC212
	fadd	%st(1), %st
	fstps	-8(%ebp)
	fstps	-4(%ebp)
	cmpl	%ebp, %ebx
	jne	L1277
L1271:
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
LFE3526:
	.p2align 4,,15
	.globl	__Z9initOpt02R11dataOpt02_t
	.def	__Z9initOpt02R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z9initOpt02R11dataOpt02_t:
LFB2676:
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
L1281:
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
	jne	L1281
	leal	40000(%ebp), %ebx
	movl	$-1342177277, %edi
	cmpl	%ebx, %ebp
	movl	$624, 2512(%esp)
	je	L1279
	.p2align 4,,7
L1284:
	movl	%esi, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L1284
	mull	%edi
	addl	$4, %ebp
	shrl	$28, %edx
	movl	%edx, -4(%ebp)
	cmpl	%ebp, %ebx
	jne	L1284
L1279:
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
LFE2676:
	.p2align 4,,15
	.globl	__Z15initOpt03_Type3R11dataOpt03_t
	.def	__Z15initOpt03_Type3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z15initOpt03_Type3R11dataOpt03_t:
LFB2682:
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
L1290:
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
	jne	L1290
	leal	40000(%ebp), %ebx
	movl	$-1342177277, %edi
	cmpl	%ebx, %ebp
	movl	$624, 2512(%esp)
	je	L1288
	.p2align 4,,7
L1293:
	movl	%esi, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L1293
	mull	%edi
	addl	$4, %ebp
	shrl	$28, %edx
	movl	%edx, -4(%ebp)
	cmpl	%ebp, %ebx
	jne	L1293
L1288:
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
LFE2682:
	.p2align 4,,15
	.globl	__Z12initOpt08_t1R12dataOpt08_t1
	.def	__Z12initOpt08_t1R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
__Z12initOpt08_t1R12dataOpt08_t1:
LFB3659:
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
L1299:
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
	jne	L1299
	leal	40000(%ebp), %ebx
	movl	$-1342177277, %edi
	cmpl	%ebx, %ebp
	movl	$624, 2512(%esp)
	je	L1297
	.p2align 4,,7
L1302:
	movl	%esi, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L1302
	mull	%edi
	addl	$4, %ebp
	shrl	$28, %edx
	movl	%edx, -4(%ebp)
	cmpl	%ebp, %ebx
	jne	L1302
L1297:
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
LFE3659:
	.p2align 4,,15
	.globl	__Z9initOpt01R11dataOpt01_t
	.def	__Z9initOpt01R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z9initOpt01R11dataOpt01_t:
LFB2671:
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
L1308:
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
	jne	L1308
	leal	40004(%ebp), %edi
	leal	4(%ebp), %ebx
	cmpl	%edi, %ebx
	movl	$0, 0(%ebp)
	movl	$-1342177277, %ebp
	movl	$624, 2512(%esp)
	je	L1306
	.p2align 4,,7
L1311:
	movl	%esi, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L1311
	mull	%ebp
	addl	$4, %ebx
	shrl	$28, %edx
	movl	%edx, -4(%ebx)
	cmpl	%ebx, %edi
	jne	L1311
L1306:
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
LFE2671:
	.p2align 4,,15
	.globl	__Z9initOpt04R11dataOpt04_t
	.def	__Z9initOpt04R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z9initOpt04R11dataOpt04_t:
LFB3041:
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
L1317:
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
	jne	L1317
	leal	80000(%ebp), %ebx
	movl	$-1342177277, %edi
	cmpl	%ebx, %ebp
	movl	$624, 2512(%esp)
	je	L1315
	.p2align 4,,7
L1320:
	movl	%esi, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L1320
	mull	%edi
	addl	$8, %ebp
	movl	$0x00000000, -4(%ebp)
	shrl	$28, %edx
	movl	%edx, -8(%ebp)
	cmpl	%ebp, %ebx
	jne	L1320
L1315:
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
LFE3041:
	.p2align 4,,15
	.globl	__Z12initOpt08_t2R12dataOpt08_t2
	.def	__Z12initOpt08_t2R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z12initOpt08_t2R12dataOpt08_t2:
LFB3667:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$1, %ecx
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	movl	$440509467, %ebp
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$5489, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	2560(%esp), %edi
	leal	16(%esp), %ebx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L1326:
	movl	%esi, %eax
	movl	%ecx, %edx
	shrl	$30, %eax
	xorl	%esi, %eax
	shrl	$4, %edx
	imull	$1812433253, %eax, %esi
	movl	%edx, %eax
	mull	%ebp
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	addl	%eax, %esi
	movl	%esi, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1326
	leal	8(%edi), %eax
	movl	%eax, 8(%esp)
	leal	480000(%edi), %eax
	movl	$-1342177277, %edi
	movl	$624, 2512(%esp)
	movl	%eax, 12(%esp)
	.p2align 4,,7
L1329:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L1329
	mull	%edi
	movl	8(%esp), %eax
	shrl	$28, %edx
	movl	%edx, -8(%eax)
	.p2align 4,,7
L1331:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L1331
	mull	%edi
	movl	8(%esp), %eax
	shrl	$28, %edx
	movl	%eax, %esi
	movl	%edx, -4(%eax)
	leal	40(%eax), %ebp
	.p2align 4,,7
L1336:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L1336
	mull	%edi
	addl	$4, %esi
	shrl	$28, %edx
	movl	%edx, -4(%esi)
	cmpl	%esi, %ebp
	jne	L1336
	movl	8(%esp), %eax
	addl	$48, %eax
	cmpl	%ebp, 12(%esp)
	je	L1342
	movl	%eax, 8(%esp)
	jmp	L1329
L1342:
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
LFE3667:
	.section	.text.startup,"x"
	.p2align 4,,15
	.def	__GLOBAL__sub_I__Z9initOpt01R11dataOpt01_t;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z9initOpt01R11dataOpt01_t:
LFB3997:
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
LFE3997:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z9initOpt01R11dataOpt01_t
	.section	.text.exit,"x"
	.p2align 4,,15
	.def	__GLOBAL__sub_D__Z9initOpt01R11dataOpt01_t;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_D__Z9initOpt01R11dataOpt01_t:
LFB3998:
	.cfi_startproc
	jmp	__Z41__static_initialization_and_destruction_0ii.part.37
	.cfi_endproc
LFE3998:
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__sub_D__Z9initOpt01R11dataOpt01_t
.lcomm __ZZ9setLambdaRiE14static_counter,4,16
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
LC120:
	.long	858927408
	.long	926299444
	.long	1650538808
	.long	1717920867
	.align 16
LC138:
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
LC207:
	.long	2147483647
	.long	2147483647
	.long	2147483647
	.long	2147483647
	.align 16
LC208:
	.long	-2147483648
	.long	-2147483648
	.long	-2147483648
	.long	-2147483648
	.align 16
LC209:
	.long	1
	.long	1
	.long	1
	.long	1
	.align 16
LC210:
	.long	-1727483681
	.long	-1727483681
	.long	-1727483681
	.long	-1727483681
	.align 4
LC211:
	.long	796917760
	.align 4
LC212:
	.long	1093664768
	.ident	"GCC: (GNU) 4.8.2"
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
	.def	__Z13_strnlen_fastPKcj;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	__Z12_strcmp_fastPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z13_strncmp_fastPKcS0_j;	.scl	2;	.type	32;	.endef
	.def	__Z12_strchr_fastPKcc;	.scl	2;	.type	32;	.endef
	.def	__Z13_strrchr_fastPKcc;	.scl	2;	.type	32;	.endef
	.def	__Z12_strstr_fastPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z14_strstrbm_fastPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z13_strstr0_fastPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z12_strcpy_fastPcPKc;	.scl	2;	.type	32;	.endef
	.def	__Z13_strncpy_fastPcPKcj;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef

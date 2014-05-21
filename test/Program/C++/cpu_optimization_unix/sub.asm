	.file	"sub.cpp"
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_:
LFB3717:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	8(%esp), %eax
	movl	%edx, (%eax)
	ret
	.cfi_endproc
LFE3717:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_:
LFB3724:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	addl	$1, (%eax)
	ret
	.cfi_endproc
LFE3724:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE_E9_M_invokeERKSt9_Any_data:
LFB3809:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%edx)
	ret
	.cfi_endproc
LFE3809:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE0_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE0_E9_M_invokeERKSt9_Any_data:
LFB3813:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%edx)
	ret
	.cfi_endproc
LFE3813:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE1_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE1_E9_M_invokeERKSt9_Any_data:
LFB3817:
	.cfi_startproc
	movl	__ZZ9setLambdaRiE14static_counter, %eax
	addl	$1, %eax
	movl	%eax, __ZZ9setLambdaRiE14static_counter
	ret
	.cfi_endproc
LFE3817:
	.p2align 4,,15
	.def	__Z41__static_initialization_and_destruction_0ii.part.34;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii.part.34:
LFB3906:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3906
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L7
	movl	$3, 8(%esp)
	movl	$_s_lambda3, 4(%esp)
	movl	$_s_lambda3, (%esp)
	call	*%eax
L7:
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L8
	movl	$3, 8(%esp)
	movl	$_s_lambda2, 4(%esp)
	movl	$_s_lambda2, (%esp)
	call	*%eax
L8:
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L9
	movl	$3, 8(%esp)
	movl	$_s_lambda1, 4(%esp)
	movl	$_s_lambda1, (%esp)
	call	*%eax
L9:
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitD1Ev
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3906:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA3906:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3906-LLSDACSB3906
LLSDACSB3906:
LLSDACSE3906:
	.text
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation:
LFB3719:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L23
	jle	L29
	cmpl	$2, %eax
	je	L26
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L22
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L22:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L26:
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
L29:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L22
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
L23:
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
LFE3719:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation:
LFB3725:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L32
	jle	L38
	cmpl	$2, %eax
	je	L35
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L31
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L31:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L35:
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
L38:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L31
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
L32:
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
LFE3725:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation:
LFB3810:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L41
	jle	L47
	cmpl	$2, %eax
	je	L44
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L40
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L40:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L44:
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
L47:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L40
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
L41:
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
LFE3810:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation:
LFB3814:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L50
	jle	L56
	cmpl	$2, %eax
	je	L53
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L49
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L49:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L53:
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
L56:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L49
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
L50:
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
LFE3814:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation:
LFB3818:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L59
	jle	L65
	cmpl	$2, %eax
	je	L62
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L58
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L58:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L62:
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
L65:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L58
	movl	32(%esp), %eax
	movl	$__ZTIZ9setLambdaRiEUlvE1_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L59:
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
LFE3818:
	.p2align 4,,15
	.globl	__Z22testOpt01_Type1_BeforeR11dataOpt01_t
	.def	__Z22testOpt01_Type1_BeforeR11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z22testOpt01_Type1_BeforeR11dataOpt01_t:
LFB2661:
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
	je	L75
	addl	4(%ebx), %esi
	cmpl	$1, %eax
	jbe	L76
	addl	8(%ebx), %esi
	cmpl	$2, %eax
	jbe	L77
	addl	12(%ebx), %esi
	movl	$9997, 4(%esp)
	movl	$3, (%esp)
L67:
	movl	$10000, %edi
	pxor	%xmm0, %xmm0
	subl	%eax, %edi
	movl	%edi, %ecx
	shrl	$2, %ecx
	leal	4(%ebx,%eax,4), %edx
	xorl	%eax, %eax
	leal	0(,%ecx,4), %ebp
	.p2align 4,,7
L74:
	addl	$1, %eax
	addl	$16, %edx
	paddd	-16(%edx), %xmm0
	cmpl	%eax, %ecx
	ja	L74
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
	je	L72
	addl	4(%ebx,%edx,4), %eax
	cmpl	$1, %ecx
	leal	1(%edx), %esi
	je	L72
	addl	4(%ebx,%esi,4), %eax
	addl	$2, %edx
	cmpl	$2, %ecx
	je	L72
	addl	4(%ebx,%edx,4), %eax
L72:
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
L75:
	.cfi_restore_state
	movl	$10000, 4(%esp)
	movl	$0, (%esp)
	jmp	L67
	.p2align 4,,7
L76:
	movl	$9999, 4(%esp)
	movl	$1, (%esp)
	jmp	L67
	.p2align 4,,7
L77:
	movl	$9998, 4(%esp)
	movl	$2, (%esp)
	jmp	L67
	.cfi_endproc
LFE2661:
	.p2align 4,,15
	.globl	__Z22testOpt01_Type1_After1R11dataOpt01_t
	.def	__Z22testOpt01_Type1_After1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z22testOpt01_Type1_After1R11dataOpt01_t:
LFB2662:
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
	je	L93
	cmpl	$1, %eax
	movl	4(%ebx), %esi
	jbe	L94
	addl	8(%ebx), %esi
	cmpl	$2, %eax
	jbe	L95
	addl	12(%ebx), %esi
	movl	$9997, 4(%esp)
	movl	$3, (%esp)
L85:
	movl	$10000, %edi
	pxor	%xmm0, %xmm0
	subl	%eax, %edi
	movl	%edi, %ecx
	shrl	$2, %ecx
	leal	4(%ebx,%eax,4), %edx
	xorl	%eax, %eax
	leal	0(,%ecx,4), %ebp
	.p2align 4,,7
L92:
	addl	$1, %eax
	addl	$16, %edx
	paddd	-16(%edx), %xmm0
	cmpl	%eax, %ecx
	ja	L92
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
	je	L90
	addl	4(%ebx,%eax,4), %esi
	cmpl	$1, %edx
	leal	1(%eax), %ecx
	je	L90
	addl	4(%ebx,%ecx,4), %esi
	addl	$2, %eax
	cmpl	$2, %edx
	je	L90
	addl	4(%ebx,%eax,4), %esi
L90:
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
L93:
	.cfi_restore_state
	movl	$10000, 4(%esp)
	xorl	%esi, %esi
	movl	$0, (%esp)
	jmp	L85
	.p2align 4,,7
L94:
	movl	$9999, 4(%esp)
	movl	$1, (%esp)
	jmp	L85
	.p2align 4,,7
L95:
	movl	$9998, 4(%esp)
	movl	$2, (%esp)
	jmp	L85
	.cfi_endproc
LFE2662:
	.p2align 4,,15
	.globl	__Z22testOpt01_Type1_After2R11dataOpt01_t
	.def	__Z22testOpt01_Type1_After2R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z22testOpt01_Type1_After2R11dataOpt01_t:
LFB2663:
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
	ja	L123
L114:
	movl	%edi, %ebx
L103:
	cmpl	$1, %ebx
	movl	4(%eax), %edx
	jbe	L116
	addl	8(%eax), %edx
	cmpl	$2, %ebx
	leal	12(%eax), %ecx
	jbe	L105
	addl	12(%eax), %edx
	cmpl	$3, %ebx
	leal	16(%eax), %ecx
	jbe	L105
	addl	16(%eax), %edx
	cmpl	$4, %ebx
	leal	20(%eax), %ecx
	jbe	L105
	addl	20(%eax), %edx
	cmpl	$5, %ebx
	leal	24(%eax), %ecx
	jbe	L105
	addl	24(%eax), %edx
	cmpl	$6, %ebx
	leal	28(%eax), %ecx
	jbe	L105
	addl	28(%eax), %edx
	cmpl	$7, %ebx
	leal	32(%eax), %ecx
	jbe	L105
	addl	32(%eax), %edx
	leal	36(%eax), %ecx
L105:
	cmpl	%ebx, %edi
	je	L106
L104:
	subl	%ebx, %edi
	movl	%edi, %esi
	shrl	$2, %esi
	leal	0(,%esi,4), %ebp
	testl	%ebp, %ebp
	movl	%esi, 4(%esp)
	je	L107
	leal	4(%eax,%ebx,4), %esi
	xorl	%ebx, %ebx
	pxor	%xmm0, %xmm0
L113:
	paddd	(%esi), %xmm0
	addl	$1, %ebx
	addl	$16, %esi
	cmpl	%ebx, 4(%esp)
	ja	L113
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
	je	L106
L107:
	movl	(%esp), %esi
	leal	4(%ecx), %ebx
	addl	(%ecx), %edx
	cmpl	%ebx, %esi
	jbe	L106
	leal	8(%ecx), %ebx
	addl	4(%ecx), %edx
	cmpl	%ebx, %esi
	jbe	L106
	addl	8(%ecx), %edx
L106:
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
L123:
	.cfi_restore_state
	cmpl	(%esp), %esi
	ja	L114
	testl	%ebx, %ebx
	jne	L103
	xorl	%ebx, %ebx
	xorl	%edx, %edx
	.p2align 4,,2
	jmp	L104
	.p2align 4,,7
L116:
	movl	%ebp, %ecx
	jmp	L105
	.cfi_endproc
LFE2663:
	.p2align 4,,15
	.globl	__Z24testOpt01_Type1_AppendixR11dataOpt01_t
	.def	__Z24testOpt01_Type1_AppendixR11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z24testOpt01_Type1_AppendixR11dataOpt01_t:
LFB2664:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %ecx
	leal	4(%ecx), %eax
	leal	40004(%ecx), %ebx
	cmpl	%ebx, %eax
	je	L124
	movl	(%ecx), %edx
	.p2align 4,,7
L127:
	addl	(%eax), %edx
	addl	$4, %eax
	cmpl	%eax, %ebx
	movl	%edx, (%ecx)
	jne	L127
L124:
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2664:
	.p2align 4,,15
	.globl	__Z22testOpt02_Type1_BeforeR11dataOpt02_t
	.def	__Z22testOpt02_Type1_BeforeR11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z22testOpt02_Type1_BeforeR11dataOpt02_t:
LFB2666:
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
L131:
	movl	(%ecx,%eax,4), %edx
	addl	$1, %eax
	addl	$1, 4(%esp,%edx,8)
	cmpl	$10000, %eax
	jne	L131
	movl	4(%esp), %eax
	movl	%esp, %edx
	cmpl	%eax, 12(%esp)
	jle	L132
	movl	12(%esp), %eax
	leal	8(%esp), %edx
L132:
	cmpl	20(%esp), %eax
	jge	L133
	movl	20(%esp), %eax
	leal	16(%esp), %edx
L133:
	cmpl	28(%esp), %eax
	jge	L134
	movl	28(%esp), %eax
	leal	24(%esp), %edx
L134:
	cmpl	36(%esp), %eax
	jge	L135
	movl	36(%esp), %eax
	leal	32(%esp), %edx
L135:
	cmpl	44(%esp), %eax
	jge	L136
	movl	44(%esp), %eax
	leal	40(%esp), %edx
L136:
	cmpl	52(%esp), %eax
	jge	L137
	movl	52(%esp), %eax
	leal	48(%esp), %edx
L137:
	cmpl	60(%esp), %eax
	jge	L138
	movl	60(%esp), %eax
	leal	56(%esp), %edx
L138:
	cmpl	68(%esp), %eax
	jge	L139
	movl	68(%esp), %eax
	leal	64(%esp), %edx
L139:
	cmpl	76(%esp), %eax
	jge	L140
	movl	76(%esp), %eax
	leal	72(%esp), %edx
L140:
	cmpl	%eax, 84(%esp)
	jle	L141
	movl	84(%esp), %eax
	leal	80(%esp), %edx
L141:
	sall	$16, %eax
	orl	(%edx), %eax
	addl	$108, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2666:
	.p2align 4,,15
	.globl	__Z22testOpt02_Type1_After1R11dataOpt02_t
	.def	__Z22testOpt02_Type1_After1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z22testOpt02_Type1_After1R11dataOpt02_t:
LFB2667:
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
L146:
	movl	(%eax), %edx
	addl	$4, %eax
	addl	$1, 4(%esp,%edx,8)
	cmpl	%eax, %ecx
	ja	L146
	movl	4(%esp), %eax
	movl	%esp, %edx
	cmpl	%eax, 12(%esp)
	jle	L147
	movl	12(%esp), %eax
	leal	8(%esp), %edx
L147:
	cmpl	20(%esp), %eax
	jge	L148
	movl	20(%esp), %eax
	leal	16(%esp), %edx
L148:
	cmpl	28(%esp), %eax
	jge	L149
	movl	28(%esp), %eax
	leal	24(%esp), %edx
L149:
	cmpl	36(%esp), %eax
	jge	L150
	movl	36(%esp), %eax
	leal	32(%esp), %edx
L150:
	cmpl	44(%esp), %eax
	jge	L151
	movl	44(%esp), %eax
	leal	40(%esp), %edx
L151:
	cmpl	52(%esp), %eax
	jge	L152
	movl	52(%esp), %eax
	leal	48(%esp), %edx
L152:
	cmpl	60(%esp), %eax
	jge	L153
	movl	60(%esp), %eax
	leal	56(%esp), %edx
L153:
	cmpl	68(%esp), %eax
	jge	L154
	movl	68(%esp), %eax
	leal	64(%esp), %edx
L154:
	cmpl	76(%esp), %eax
	jge	L155
	movl	76(%esp), %eax
	leal	72(%esp), %edx
L155:
	cmpl	%eax, 84(%esp)
	jle	L157
	movl	84(%esp), %eax
	leal	80(%esp), %edx
L157:
	sall	$16, %eax
	orl	(%edx), %eax
	addl	$108, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2667:
	.p2align 4,,15
	.globl	__Z22testOpt02_Type1_After2R11dataOpt02_t
	.def	__Z22testOpt02_Type1_After2R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z22testOpt02_Type1_After2R11dataOpt02_t:
LFB2668:
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
	je	L172
	cmpl	$5, %ebx
	setbe	%bl
	cmpl	%edx, %ecx
	seta	%cl
	orl	%ecx, %ebx
	cmpb	$1, %bl
	sbbl	%ecx, %ecx
	cmpb	$-1, %cl
	jne	L172
	movl	%esp, %ecx
	xorl	%ebx, %ebx
	movdqa	LC5, %xmm3
	movdqa	LC4, %xmm0
	pxor	%xmm1, %xmm1
L167:
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
	jbe	L178
	movdqa	%xmm4, %xmm0
	jmp	L167
	.p2align 4,,7
L172:
	movl	%esp, %ecx
	xorl	%ebp, %ebp
L162:
	leal	8(%ecx), %ebx
	cmpl	%ebx, %edx
	leal	1(%ebp), %eax
	movl	%ebp, (%ecx)
	movl	$0, 4(%ecx)
	jbe	L165
	movl	%eax, 8(%ecx)
	leal	16(%ecx), %eax
	cmpl	%eax, %edx
	leal	2(%ebp), %ebx
	movl	$0, 12(%ecx)
	jbe	L165
	movl	%ebx, 16(%ecx)
	leal	24(%ecx), %ebx
	cmpl	%ebx, %edx
	leal	3(%ebp), %eax
	movl	$0, 20(%ecx)
	jbe	L165
	movl	%eax, 24(%ecx)
	leal	32(%ecx), %eax
	addl	$4, %ebp
	cmpl	%eax, %edx
	movl	$0, 28(%ecx)
	jbe	L165
	movl	%ebp, 32(%ecx)
	movl	$0, 36(%ecx)
L165:
	movl	128(%esp), %eax
	leal	40000(%eax), %ebx
	.p2align 4,,7
L169:
	movl	(%eax), %ecx
	addl	$4, %eax
	addl	$1, 4(%esp,%ecx,8)
	cmpl	%eax, %ebx
	ja	L169
	movl	4(%esp), %eax
	movl	%esp, %ebx
	.p2align 4,,7
L171:
	movl	4(%esi), %ecx
	cmpl	%eax, %ecx
	cmovg	%esi, %ebx
	cmpl	%ecx, %eax
	cmovl	%ecx, %eax
	addl	$8, %esi
	cmpl	%edx, %esi
	jb	L171
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
L178:
	.cfi_restore_state
	cmpl	%eax, %ebp
	leal	(%esp,%ebp,8), %ecx
	jne	L162
	jmp	L165
	.cfi_endproc
LFE2668:
	.p2align 4,,15
	.globl	__Z22testOpt03_Type1_Beforeiii
	.def	__Z22testOpt03_Type1_Beforeiii;	.scl	2;	.type	32;	.endef
__Z22testOpt03_Type1_Beforeiii:
LFB2669:
	.cfi_startproc
	movl	8(%esp), %eax
	imull	4(%esp), %eax
	addl	12(%esp), %eax
	ret
	.cfi_endproc
LFE2669:
	.p2align 4,,15
	.globl	__Z22testOpt03_Type2_Beforeiiiiiiii
	.def	__Z22testOpt03_Type2_Beforeiiiiiiii;	.scl	2;	.type	32;	.endef
__Z22testOpt03_Type2_Beforeiiiiiiii:
LFB2670:
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
LFE2670:
	.p2align 4,,15
	.globl	__Z22testOpt03_Type3_BeforeR11dataOpt03_t
	.def	__Z22testOpt03_Type3_BeforeR11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z22testOpt03_Type3_BeforeR11dataOpt03_t:
LFB3017:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3017
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
	jae	L284
	movl	%esi, %ebx
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %edx
	leal	32(%esp), %ebp
	jmp	L193
	.p2align 4,,7
L186:
	addl	$4, %ebx
	cmpl	%ebx, %edi
	jbe	L192
L285:
	movl	%eax, %edx
L193:
	movl	(%ebx), %ecx
	movl	%edx, %eax
	testl	%ecx, %ecx
	jne	L186
	testl	%edx, %edx
	je	L283
	movl	%ebx, 4(%esp)
	movl	%ebp, (%esp)
LEHB1:
	call	*44(%esp)
LEHE1:
	addl	$4, %ebx
	movl	40(%esp), %eax
	cmpl	%ebx, %edi
	ja	L285
L192:
	testl	%eax, %eax
	je	L194
L183:
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L194:
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
	jae	L286
	movl	80(%esp), %ebx
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %edx
	leal	32(%esp), %ebp
	jmp	L207
	.p2align 4,,7
L200:
	addl	$4, %ebx
	cmpl	%ebx, %edi
	jbe	L206
L287:
	movl	%eax, %edx
L207:
	cmpl	$1, (%ebx)
	movl	%edx, %eax
	jne	L200
	testl	%edx, %edx
	je	L283
	movl	%ebx, 4(%esp)
	movl	%ebp, (%esp)
LEHB3:
	call	*44(%esp)
LEHE3:
	addl	$4, %ebx
	movl	40(%esp), %eax
	cmpl	%ebx, %edi
	ja	L287
L206:
	testl	%eax, %eax
	je	L208
L197:
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L208:
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
	jae	L288
	movl	80(%esp), %ebx
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %edx
	leal	32(%esp), %ebp
	jmp	L221
	.p2align 4,,7
L214:
	addl	$4, %ebx
	cmpl	%ebx, %edi
	jbe	L220
L289:
	movl	%eax, %edx
L221:
	cmpl	$2, (%ebx)
	movl	%edx, %eax
	jne	L214
	testl	%edx, %edx
	je	L283
	movl	%ebx, 4(%esp)
	movl	%ebp, (%esp)
LEHB5:
	call	*44(%esp)
LEHE5:
	addl	$4, %ebx
	movl	40(%esp), %eax
	cmpl	%ebx, %edi
	ja	L289
L220:
	testl	%eax, %eax
	je	L222
L211:
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L222:
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
	jae	L290
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %edx
	leal	32(%esp), %ebp
	jmp	L235
	.p2align 4,,7
L228:
	addl	$4, %esi
	cmpl	%esi, %edi
	jbe	L234
L291:
	movl	%eax, %edx
L235:
	cmpl	$3, (%esi)
	movl	%edx, %eax
	jne	L228
	testl	%edx, %edx
	je	L283
	movl	%esi, 4(%esp)
	movl	%ebp, (%esp)
LEHB7:
	call	*44(%esp)
LEHE7:
	addl	$4, %esi
	movl	40(%esp), %eax
	cmpl	%esi, %edi
	ja	L291
L234:
	testl	%eax, %eax
	je	L236
L225:
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L236:
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
L283:
	.cfi_restore_state
LEHB8:
	call	__ZSt25__throw_bad_function_callv
LEHE8:
L284:
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %eax
	jmp	L183
L290:
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %eax
	jmp	L225
L288:
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %eax
	jmp	L211
L286:
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, %eax
	jmp	L197
L246:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L233
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
L233:
	movl	%ebx, (%esp)
LEHB9:
	call	__Unwind_Resume
LEHE9:
L243:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L233
	movl	$3, 8(%esp)
	movl	%ebp, 4(%esp)
	movl	%ebp, (%esp)
	call	*%edx
	jmp	L233
L244:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L233
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L233
L241:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L233
	movl	$3, 8(%esp)
	movl	%ebp, 4(%esp)
	movl	%ebp, (%esp)
	call	*%edx
	jmp	L233
L242:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L233
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L233
L247:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L233
	movl	$3, 8(%esp)
	movl	%ebp, 4(%esp)
	movl	%ebp, (%esp)
	call	*%edx
	jmp	L233
L248:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L233
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L233
L245:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L233
	movl	$3, 8(%esp)
	movl	%ebp, 4(%esp)
	movl	%ebp, (%esp)
	call	*%edx
	jmp	L233
	.cfi_endproc
LFE3017:
	.section	.gcc_except_table,"w"
LLSDA3017:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3017-LLSDACSB3017
LLSDACSB3017:
	.uleb128 LEHB0-LFB3017
	.uleb128 LEHE0-LEHB0
	.uleb128 L242-LFB3017
	.uleb128 0
	.uleb128 LEHB1-LFB3017
	.uleb128 LEHE1-LEHB1
	.uleb128 L241-LFB3017
	.uleb128 0
	.uleb128 LEHB2-LFB3017
	.uleb128 LEHE2-LEHB2
	.uleb128 L244-LFB3017
	.uleb128 0
	.uleb128 LEHB3-LFB3017
	.uleb128 LEHE3-LEHB3
	.uleb128 L243-LFB3017
	.uleb128 0
	.uleb128 LEHB4-LFB3017
	.uleb128 LEHE4-LEHB4
	.uleb128 L246-LFB3017
	.uleb128 0
	.uleb128 LEHB5-LFB3017
	.uleb128 LEHE5-LEHB5
	.uleb128 L245-LFB3017
	.uleb128 0
	.uleb128 LEHB6-LFB3017
	.uleb128 LEHE6-LEHB6
	.uleb128 L248-LFB3017
	.uleb128 0
	.uleb128 LEHB7-LFB3017
	.uleb128 LEHE7-LEHB7
	.uleb128 L247-LFB3017
	.uleb128 0
	.uleb128 LEHB8-LFB3017
	.uleb128 LEHE8-LEHB8
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB9-LFB3017
	.uleb128 LEHE9-LEHB9
	.uleb128 0
	.uleb128 0
LLSDACSE3017:
	.text
	.p2align 4,,15
	.globl	__Z21testOpt03_Type3_AfterR11dataOpt03_t
	.def	__Z21testOpt03_Type3_AfterR11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z21testOpt03_Type3_AfterR11dataOpt03_t:
LFB3025:
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
	jae	L303
	movl	%ebp, %ecx
	movl	%ebp, %eax
	.p2align 4,,7
L296:
	movl	(%eax), %ebx
	testl	%ebx, %ebx
	jne	L294
	movl	$1, (%eax)
L294:
	addl	$4, %eax
	cmpl	%eax, %edx
	ja	L296
	movl	%ebp, %ebx
	xorl	%esi, %esi
	.p2align 4,,7
L298:
	cmpl	$1, (%ebx)
	leal	1(%esi), %edi
	cmove	%edi, %esi
	addl	$4, %ebx
	cmpl	%ebx, %edx
	ja	L298
	movl	%ebp, %eax
	xorl	%ebx, %ebx
	.p2align 4,,7
L300:
	cmpl	$2, (%eax)
	leal	1(%ebx), %edi
	cmove	%edi, %ebx
	addl	$4, %eax
	cmpl	%eax, %edx
	ja	L300
	addl	%ebx, %esi
	xorl	%eax, %eax
	.p2align 4,,7
L302:
	cmpl	$3, (%ecx)
	leal	1(%eax), %edi
	cmove	%edi, %eax
	addl	$4, %ecx
	cmpl	%ecx, %edx
	ja	L302
	addl	%esi, %eax
L304:
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
L303:
	.cfi_restore_state
	xorl	%eax, %eax
	jmp	L304
	.cfi_endproc
LFE3025:
	.p2align 4,,15
	.globl	__Z22testOpt04_Type1_BeforeR11dataOpt04_t
	.def	__Z22testOpt04_Type1_BeforeR11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type1_BeforeR11dataOpt04_t:
LFB3031:
	.cfi_startproc
	movl	4(%esp), %eax
	fldz
	leal	80000(%eax), %ecx
	movl	%eax, %edx
	.p2align 4,,7
L308:
	fildl	(%edx)
	addl	$8, %edx
	cmpl	%edx, %ecx
	faddp	%st, %st(1)
	ja	L308
	.p2align 4,,7
L310:
	fildl	(%eax)
	addl	$8, %eax
	fdiv	%st(1), %st
	fstps	-4(%eax)
	cmpl	%eax, %ecx
	ja	L310
	fstp	%st(0)
	ret
	.cfi_endproc
LFE3031:
	.p2align 4,,15
	.globl	__Z22testOpt04_Type1_After1R11dataOpt04_t
	.def	__Z22testOpt04_Type1_After1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type1_After1R11dataOpt04_t:
LFB3032:
	.cfi_startproc
	movl	4(%esp), %eax
	fldz
	leal	80000(%eax), %ecx
	movl	%eax, %edx
	.p2align 4,,7
L313:
	fildl	(%edx)
	addl	$8, %edx
	cmpl	%edx, %ecx
	faddp	%st, %st(1)
	ja	L313
	fdivrs	LC8
	.p2align 4,,7
L315:
	fildl	(%eax)
	addl	$8, %eax
	fmul	%st(1), %st
	fstps	-4(%eax)
	cmpl	%eax, %ecx
	ja	L315
	fstp	%st(0)
	ret
	.cfi_endproc
LFE3032:
	.p2align 4,,15
	.globl	__Z22testOpt04_Type1_After2R11dataOpt04_t
	.def	__Z22testOpt04_Type1_After2R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type1_After2R11dataOpt04_t:
LFB3033:
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
	je	L327
	cmpl	$10, %ecx
	setbe	%cl
	cmpl	%edi, %edx
	setb	%al
	movl	%eax, %edi
	orl	%edi, %ecx
	cmpb	$1, %cl
	sbbl	%ecx, %ecx
	cmpb	$-1, %cl
	jne	L327
	movl	%ebx, %ecx
	xorl	%edi, %edi
	pxor	%xmm0, %xmm0
	movl	%ebx, %eax
L324:
	movdqu	(%ecx), %xmm1
	movdqu	16(%ecx), %xmm2
	addl	$1, %edi
	shufps	$136, %xmm2, %xmm1
	addl	$32, %ecx
	cmpl	%edi, %esi
	paddd	%xmm1, %xmm0
	ja	L324
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
	je	L322
L318:
	leal	8(%ebx), %esi
	addl	(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L322
	leal	16(%ebx), %esi
	addl	8(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L322
	leal	24(%ebx), %esi
	addl	16(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L322
	leal	32(%ebx), %esi
	addl	24(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L322
	leal	40(%ebx), %esi
	addl	32(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L322
	leal	48(%ebx), %esi
	addl	40(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L322
	leal	56(%ebx), %esi
	addl	48(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L322
	leal	64(%ebx), %esi
	addl	56(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L322
	leal	72(%ebx), %esi
	addl	64(%ebx), %ecx
	cmpl	%esi, %edx
	jbe	L322
	addl	72(%ebx), %ecx
L322:
	movl	%ecx, 8(%esp)
	movl	(%esp), %eax
	fildl	8(%esp)
	fdivrs	LC8
	.p2align 4,,7
L326:
	fildl	(%eax)
	addl	$8, %eax
	fmul	%st(1), %st
	fstps	-4(%eax)
	cmpl	%eax, %edx
	ja	L326
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
L327:
	.cfi_restore_state
	xorl	%ecx, %ecx
	jmp	L318
	.cfi_endproc
LFE3033:
	.p2align 4,,15
	.globl	__Z22testOpt05_Type1_BeforeiRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_
	.def	__Z22testOpt05_Type1_BeforeiRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_;	.scl	2;	.type	32;	.endef
__Z22testOpt05_Type1_BeforeiRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_:
LFB3037:
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
LFE3037:
	.p2align 4,,15
	.globl	__Z21testOpt05_Type1_AfteriRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_
	.def	__Z21testOpt05_Type1_AfteriRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_;	.scl	2;	.type	32;	.endef
__Z21testOpt05_Type1_AfteriRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_:
LFB3514:
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
LFE3514:
	.p2align 4,,15
	.globl	__Z22testOpt06_Type1_BeforeR11dataOpt06_tfff
	.def	__Z22testOpt06_Type1_BeforeR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
__Z22testOpt06_Type1_BeforeR11dataOpt06_tfff:
LFB3516:
	.cfi_startproc
	movl	4(%esp), %eax
	flds	8(%esp)
	flds	12(%esp)
	flds	16(%esp)
	leal	80000(%eax), %edx
	.p2align 4,,7
L338:
	flds	(%eax)
	addl	$8, %eax
	fmul	%st(3), %st
	fmul	%st(2), %st
	fdiv	%st(1), %st
	fstps	-4(%eax)
	cmpl	%eax, %edx
	ja	L338
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	ret
	.cfi_endproc
LFE3516:
	.p2align 4,,15
	.globl	__Z21testOpt06_Type1_AfterR11dataOpt06_tfff
	.def	__Z21testOpt06_Type1_AfterR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
__Z21testOpt06_Type1_AfterR11dataOpt06_tfff:
LFB3517:
	.cfi_startproc
	flds	12(%esp)
	fmuls	8(%esp)
	movl	4(%esp), %eax
	leal	80000(%eax), %edx
	fdivs	16(%esp)
	.p2align 4,,7
L341:
	flds	(%eax)
	addl	$8, %eax
	fmul	%st(1), %st
	fstps	-4(%eax)
	cmpl	%eax, %edx
	ja	L341
	fstp	%st(0)
	ret
	.cfi_endproc
LFE3517:
	.p2align 4,,15
	.globl	__Z12addMatrixOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_S4_
	.def	__Z12addMatrixOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_S4_;	.scl	2;	.type	32;	.endef
__Z12addMatrixOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_S4_:
LFB3523:
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
LFE3523:
	.p2align 4,,15
	.globl	__Z18mulMatrixScalarOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_f
	.def	__Z18mulMatrixScalarOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_f;	.scl	2;	.type	32;	.endef
__Z18mulMatrixScalarOptILj4ELj4EEvR6matrixIXT_EXT0_EERKS1_f:
LFB3525:
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
LFE3525:
	.p2align 4,,15
	.globl	__Z12mulMatrixOptILj4ELj4ELj4EEvR6matrixIXT_EXT0_EERKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	.def	__Z12mulMatrixOptILj4ELj4ELj4EEvR6matrixIXT_EXT0_EERKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
__Z12mulMatrixOptILj4ELj4ELj4EEvR6matrixIXT_EXT0_EERKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE:
LFB3527:
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
LFE3527:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strlen_BeforeiPKc
	.def	__Z29testOpt07_Type2_strlen_BeforeiPKc;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strlen_BeforeiPKc:
LFB3529:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	%eax, 4(%esp)
	jmp	_strlen
	.cfi_endproc
LFE3529:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	.def	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_:
LFB3530:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	_strcmp
	.cfi_endproc
LFE3530:
	.p2align 4,,15
	.globl	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	.def	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j;	.scl	2;	.type	32;	.endef
__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j:
LFB3531:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	16(%esp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	jmp	_strncmp
	.cfi_endproc
LFE3531:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	.def	__Z29testOpt07_Type2_strchr_BeforeiPKcc;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strchr_BeforeiPKcc:
LFB3532:
	.cfi_startproc
	movl	8(%esp), %eax
	movsbl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	_strchr
	.cfi_endproc
LFE3532:
	.p2align 4,,15
	.globl	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	.def	__Z30testOpt07_Type2_strrchr_BeforeiPKcc;	.scl	2;	.type	32;	.endef
__Z30testOpt07_Type2_strrchr_BeforeiPKcc:
LFB3533:
	.cfi_startproc
	movl	8(%esp), %eax
	movsbl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	_strrchr
	.cfi_endproc
LFE3533:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	.def	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strstr_BeforeiPKcS0_:
LFB3534:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	_strstr
	.cfi_endproc
LFE3534:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc
	.def	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strcpy_BeforeiPcPKc:
LFB3535:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	_strcpy
	.cfi_endproc
LFE3535:
	.p2align 4,,15
	.globl	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	.def	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj;	.scl	2;	.type	32;	.endef
__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj:
LFB3536:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	16(%esp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	jmp	_strncpy
	.cfi_endproc
LFE3536:
	.p2align 4,,15
	.globl	__Z11strlen_fastPKc
	.def	__Z11strlen_fastPKc;	.scl	2;	.type	32;	.endef
__Z11strlen_fastPKc:
LFB3537:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %eax
	testb	$15, %al
	movl	%eax, %edx
	jne	L364
L355:
	pxor	%xmm0, %xmm0
	jmp	L359
	.p2align 4,,7
L358:
	addl	$16, %edx
L359:
	pcmpistri	$10, (%edx), %xmm0
	jne	L358
	subl	%eax, %edx
	leal	(%edx,%ecx), %eax
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L364:
	.cfi_restore_state
	movl	$0, %ebx
	pxor	%xmm0, %xmm0
	pcmpistri	$10, (%eax), %xmm0
	leal	15(%eax), %edx
	sete	%bl
	andl	$-16, %edx
	testl	%ebx, %ebx
	je	L355
	movl	%ecx, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3537:
	.p2align 4,,15
	.globl	__Z11strcmp_fastPKcS0_
	.def	__Z11strcmp_fastPKcS0_;	.scl	2;	.type	32;	.endef
__Z11strcmp_fastPKcS0_:
LFB3539:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %edx
	xorl	%ebx, %ebx
	movl	16(%esp), %eax
	testb	$15, %dl
	movl	%eax, %ecx
	setne	%bl
	andl	$15, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	notl	%ecx
	andl	$2, %ecx
	orl	%ebx, %ecx
	cmpl	$1, %ecx
	je	L376
	cmpl	$2, %ecx
	je	L378
	testl	%ecx, %ecx
	jne	L380
	.p2align 4,,6
	jmp	L374
	.p2align 4,,7
L375:
	testl	%ecx, %ecx
	.p2align 4,,7
	jne	L373
	addl	$16, %edx
	addl	$16, %eax
L376:
	movl	$0, %ebx
	movdqu	(%edx), %xmm0
	movdqa	(%eax), %xmm1
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %esi
	setc	%bl
	movl	$0, %ecx
	sete	%cl
	testl	%ebx, %ebx
	je	L375
L387:
	movsbl	(%eax,%esi), %eax
	movsbl	(%edx,%esi), %edx
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	subl	%eax, %edx
	setne	%al
	movzbl	%al, %eax
	sarl	$31, %edx
	orl	%edx, %eax
	ret
	.p2align 4,,7
L379:
	.cfi_restore_state
	testl	%ecx, %ecx
	jne	L373
	addl	$16, %edx
	addl	$16, %eax
L380:
	movl	$0, %ebx
	movdqu	(%edx), %xmm0
	movdqu	(%eax), %xmm1
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %esi
	setc	%bl
	movl	$0, %ecx
	sete	%cl
	testl	%ebx, %ebx
	je	L379
	jmp	L387
	.p2align 4,,7
L371:
	testl	%ecx, %ecx
	jne	L373
	addl	$16, %edx
	addl	$16, %eax
L374:
	movl	$0, %ebx
	movdqa	(%eax), %xmm1
	movdqa	(%edx), %xmm0
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %esi
	setc	%bl
	movl	$0, %ecx
	sete	%cl
	testl	%ebx, %ebx
	je	L371
	jmp	L387
	.p2align 4,,7
L377:
	testl	%ecx, %ecx
	jne	L373
	addl	$16, %edx
	addl	$16, %eax
L378:
	movl	$0, %ebx
	movdqu	(%eax), %xmm1
	movdqa	(%edx), %xmm0
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %esi
	setc	%bl
	movl	$0, %ecx
	sete	%cl
	testl	%ebx, %ebx
	je	L377
	jmp	L387
	.p2align 4,,7
L373:
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3539:
	.p2align 4,,15
	.globl	__Z12strncmp_fastPKcS0_j
	.def	__Z12strncmp_fastPKcS0_j;	.scl	2;	.type	32;	.endef
__Z12strncmp_fastPKcS0_j:
LFB3540:
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
	xorl	%ebx, %ebx
	movl	24(%esp), %ebp
	testb	$15, %dl
	movl	%ebp, %ecx
	setne	%bl
	andl	$15, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	notl	%ecx
	andl	$2, %ecx
	orl	%ebx, %ecx
	movl	28(%esp), %ebx
	cmpl	$1, %ecx
	je	L401
	cmpl	$2, %ecx
	je	L404
	testl	%ecx, %ecx
	jne	L407
	.p2align 4,,6
	jmp	L398
L434:
	cmpl	$16, %ebx
	.p2align 4,,6
	jbe	L394
	.p2align 4,,7
L410:
	testl	%ecx, %ecx
	.p2align 4,,6
	jne	L429
	testl	%esi, %esi
	.p2align 4,,4
	jne	L394
	addl	$16, %edx
	addl	$16, %ebp
	subl	$16, %ebx
L401:
	movl	$0, %esi
	movdqu	(%edx), %xmm0
	movdqa	0(%ebp), %xmm1
	movl	%esi, %eax
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %edi
	movl	$0, %ecx
	sete	%al
	setc	%cl
	cmpl	%ebx, %edi
	movl	%eax, %esi
	jb	L410
	jmp	L434
L435:
	cmpl	$16, %ebx
	jbe	L394
	.p2align 4,,7
L412:
	testl	%ecx, %ecx
	.p2align 4,,6
	jne	L428
	testl	%esi, %esi
	.p2align 4,,4
	jne	L394
	addl	$16, %edx
	addl	$16, %ebp
	subl	$16, %ebx
L407:
	movl	$0, %esi
	movdqu	(%edx), %xmm0
	movdqu	0(%ebp), %xmm1
	movl	%esi, %eax
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %edi
	movl	$0, %ecx
	sete	%al
	setc	%cl
	cmpl	%ebx, %edi
	movl	%eax, %esi
	jb	L412
	jmp	L435
L436:
	cmpl	$16, %ebx
	jbe	L394
	.p2align 4,,7
L409:
	testl	%ecx, %ecx
	.p2align 4,,6
	jne	L428
	testl	%esi, %esi
	.p2align 4,,4
	jne	L394
	addl	$16, %edx
	addl	$16, %ebp
	subl	$16, %ebx
L398:
	movl	$0, %esi
	movdqa	0(%ebp), %xmm1
	movdqa	(%edx), %xmm0
	movl	%esi, %eax
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %edi
	movl	$0, %ecx
	sete	%al
	setc	%cl
	cmpl	%ebx, %edi
	movl	%eax, %esi
	jb	L409
	jmp	L436
L437:
	cmpl	$16, %ebx
	jbe	L394
	.p2align 4,,7
L411:
	testl	%ecx, %ecx
	.p2align 4,,6
	jne	L428
	testl	%esi, %esi
	.p2align 4,,4
	jne	L394
	addl	$16, %edx
	addl	$16, %ebp
	subl	$16, %ebx
L404:
	movl	$0, %esi
	movdqu	0(%ebp), %xmm1
	movdqa	(%edx), %xmm0
	movl	%esi, %eax
	pcmpistri	$26, %xmm1, %xmm0
	movl	%ecx, %edi
	movl	$0, %ecx
	sete	%al
	setc	%cl
	cmpl	%ebx, %edi
	movl	%eax, %esi
	jb	L411
	jmp	L437
	.p2align 4,,7
L394:
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	xorl	%eax, %eax
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
L428:
	.cfi_restore_state
	cmpl	%edi, %ebx
	cmova	%edi, %ebx
L427:
	movsbl	0(%ebp,%ebx), %eax
	movsbl	(%edx,%ebx), %edx
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
	subl	%eax, %edx
	setne	%al
	movzbl	%al, %eax
	sarl	$31, %edx
	orl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L429:
	.cfi_restore_state
	cmpl	%ebx, %edi
	cmovbe	%edi, %ebx
	jmp	L427
	.cfi_endproc
LFE3540:
	.p2align 4,,15
	.globl	__Z11strchr_fastPKcc
	.def	__Z11strchr_fastPKcc;	.scl	2;	.type	32;	.endef
__Z11strchr_fastPKcc:
LFB3541:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %eax
	pxor	%xmm0, %xmm0
	movd	12(%esp), %xmm1
	pshufb	%xmm0, %xmm1
	testb	$15, %al
	je	L444
	jmp	L451
	.p2align 4,,7
L443:
	testl	%ebx, %ebx
	jne	L442
	addl	$16, %eax
L444:
	movl	$0, %edx
	movdqa	(%eax), %xmm0
	movl	$0, %ebx
	pcmpistri	$10, %xmm0, %xmm1
	setc	%dl
	sete	%bl
	testl	%edx, %edx
	je	L443
L449:
	addl	%ecx, %eax
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L442:
	.cfi_restore_state
	xorl	%eax, %eax
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L451:
	.cfi_restore_state
	movl	$0, %edx
	movdqu	(%eax), %xmm0
	movl	$0, %ebx
	pcmpistri	$10, %xmm0, %xmm1
	setc	%dl
	sete	%bl
	testl	%edx, %edx
	jne	L449
	testl	%ebx, %ebx
	jne	L442
	addl	$15, %eax
	andl	$-16, %eax
	jmp	L444
	.cfi_endproc
LFE3541:
	.p2align 4,,15
	.globl	__Z12strrchr_fastPKcc
	.def	__Z12strrchr_fastPKcc;	.scl	2;	.type	32;	.endef
__Z12strrchr_fastPKcc:
LFB3542:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	xorl	%esi, %esi
	pxor	%xmm0, %xmm0
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %edx
	movd	16(%esp), %xmm1
	pshufb	%xmm0, %xmm1
	testb	$15, %dl
	je	L457
	jmp	L466
	.p2align 4,,7
L465:
	addl	$16, %edx
L457:
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
	je	L465
L455:
	movl	%esi, %eax
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
L466:
	.cfi_restore_state
	movl	$0, %ebx
	movdqu	(%edx), %xmm0
	movl	$0, %eax
	pcmpistri	$74, %xmm0, %xmm1
	setc	%bl
	sete	%al
	addl	%edx, %ecx
	testl	%ebx, %ebx
	cmovne	%ecx, %esi
	testl	%eax, %eax
	jne	L455
	addl	$15, %edx
	andl	$-16, %edx
	jmp	L457
	.cfi_endproc
LFE3542:
	.p2align 4,,15
	.globl	__Z11strstr_fastPKcS0_
	.def	__Z11strstr_fastPKcS0_;	.scl	2;	.type	32;	.endef
__Z11strstr_fastPKcS0_:
LFB3543:
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
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	52(%esp), %ebx
	movl	48(%esp), %eax
	testb	$15, %bl
	movl	%ebx, %edx
	jne	L496
L468:
	pxor	%xmm0, %xmm0
	jmp	L472
	.p2align 4,,7
L471:
	addl	$16, %edx
L472:
	pcmpistri	$10, (%edx), %xmm0
	jne	L471
	subl	%ebx, %edx
	leal	(%edx,%ecx), %esi
L470:
	movzbl	(%ebx), %edx
	testb	$15, %al
	pxor	%xmm0, %xmm0
	movb	%dl, 16(%esp)
	movd	16(%esp), %xmm1
	pshufb	%xmm0, %xmm1
	je	L478
	jmp	L497
	.p2align 4,,7
L477:
	testl	%ecx, %ecx
	jne	L476
	addl	$16, %eax
L478:
	movl	$0, %edx
	movdqa	(%eax), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	movl	%ecx, %edi
	setc	%dl
	movl	$0, %ecx
	sete	%cl
	testl	%edx, %edx
	je	L477
L495:
	addl	%eax, %edi
	movdqa	%xmm1, 16(%esp)
	testl	%edi, %edi
	je	L485
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	call	__Z12strncmp_fastPKcS0_j
	testl	%eax, %eax
	je	L485
	leal	1(%edi), %eax
	movdqa	16(%esp), %xmm1
	testb	$15, %al
	je	L478
L497:
	movl	$0, %edx
	movdqu	(%eax), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	movl	%ecx, %edi
	setc	%dl
	movl	$0, %ecx
	sete	%cl
	testl	%edx, %edx
	jne	L495
	testl	%ecx, %ecx
	jne	L476
	addl	$15, %eax
	andl	$-16, %eax
	jmp	L478
	.p2align 4,,7
L476:
	xorl	%edi, %edi
L485:
	addl	$32, %esp
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
L496:
	.cfi_restore_state
	pxor	%xmm0, %xmm0
	pcmpistri	$10, (%ebx), %xmm0
	movl	%ecx, %esi
	movl	$0, %ecx
	sete	%cl
	leal	15(%ebx), %edx
	andl	$-16, %edx
	testl	%ecx, %ecx
	je	L468
	jmp	L470
	.cfi_endproc
LFE3543:
	.p2align 4,,15
	.globl	__Z11strcpy_fastPcPKc
	.def	__Z11strcpy_fastPcPKc;	.scl	2;	.type	32;	.endef
__Z11strcpy_fastPcPKc:
LFB3545:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	xorl	%eax, %eax
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$84, %esp
	.cfi_def_cfa_offset 96
	movl	96(%esp), %esi
	movl	100(%esp), %edx
	testl	$15, %esi
	movl	%edx, %ecx
	setne	%al
	andl	$15, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	notl	%ecx
	andl	$2, %ecx
	orl	%eax, %ecx
	cmpl	$1, %ecx
	je	L501
	cmpl	$2, %ecx
	je	L502
	testl	%ecx, %ecx
	movl	%esi, %ebx
	pxor	%xmm1, %xmm1
	jne	L512
	movl	%esi, %eax
	pxor	%xmm1, %xmm1
	jmp	L506
	.p2align 4,,7
L504:
	movdqa	%xmm0, (%eax)
	addl	$16, %edx
	addl	$16, %eax
L506:
	movdqa	(%edx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L504
	leal	16(%esp), %edx
	addl	$1, %ecx
	movdqa	%xmm0, 16(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_memcpy
	addl	$84, %esp
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
L511:
	.cfi_restore_state
	movdqu	%xmm0, (%ebx)
	addl	$16, %edx
	addl	$16, %ebx
L512:
	movdqu	(%edx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L511
	leal	64(%esp), %eax
	addl	$1, %ecx
	movdqa	%xmm0, 64(%esp)
	movl	%ebx, (%esp)
	movl	%ecx, 8(%esp)
	movl	%eax, 4(%esp)
	call	_memcpy
	addl	$84, %esp
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
L502:
	.cfi_restore_state
	movl	%esi, %eax
	pxor	%xmm1, %xmm1
	jmp	L510
	.p2align 4,,7
L509:
	movdqa	%xmm0, (%eax)
	addl	$16, %edx
	addl	$16, %eax
L510:
	movdqu	(%edx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L509
	leal	48(%esp), %edx
	addl	$1, %ecx
	movdqa	%xmm0, 48(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_memcpy
	addl	$84, %esp
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
L501:
	.cfi_restore_state
	movl	%esi, %eax
	pxor	%xmm2, %xmm2
	jmp	L508
	.p2align 4,,7
L507:
	movdqu	%xmm1, (%eax)
	addl	$16, %edx
	addl	$16, %eax
L508:
	movdqa	(%edx), %xmm1
	pcmpistri	$10, %xmm1, %xmm2
	jne	L507
	leal	32(%esp), %edx
	addl	$1, %ecx
	movdqa	%xmm1, 32(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_memcpy
	addl	$84, %esp
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
LFE3545:
	.p2align 4,,15
	.globl	__Z12strncpy_fastPcPKcj
	.def	__Z12strncpy_fastPcPKcj;	.scl	2;	.type	32;	.endef
__Z12strncpy_fastPcPKcj:
LFB3547:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	xorl	%eax, %eax
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$144, %esp
	.cfi_def_cfa_offset 160
	movl	160(%esp), %esi
	movl	164(%esp), %edx
	testl	$15, %esi
	movl	%edx, %ecx
	setne	%al
	andl	$15, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	notl	%ecx
	andl	$2, %ecx
	orl	%eax, %ecx
	cmpl	$1, %ecx
	je	L519
	cmpl	$2, %ecx
	je	L520
	testl	%ecx, %ecx
	je	L538
	movl	168(%esp), %ebx
	movl	%esi, %edi
	pxor	%xmm1, %xmm1
	jmp	L534
	.p2align 4,,7
L532:
	testl	%eax, %eax
	jne	L539
	movdqu	%xmm0, (%edi)
	addl	$16, %edx
	addl	$16, %edi
	subl	$16, %ebx
L534:
	movl	$0, %eax
	movdqu	(%edx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	sete	%al
	cmpl	%ecx, %ebx
	ja	L532
	leal	112(%esp), %eax
	movdqa	%xmm0, 112(%esp)
	movl	%ebx, 8(%esp)
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_memcpy
	addl	$144, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%esi, %eax
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
L538:
	.cfi_restore_state
	movl	168(%esp), %eax
	movl	%esi, %ebx
	pxor	%xmm1, %xmm1
	jmp	L525
	.p2align 4,,7
L522:
	testl	%ecx, %ecx
	jne	L540
	movdqa	%xmm0, (%ebx)
	addl	$16, %edx
	addl	$16, %ebx
	subl	$16, %eax
L525:
	movdqa	(%edx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	movl	%ecx, %edi
	movl	$0, %ecx
	sete	%cl
	cmpl	%edi, %eax
	ja	L522
	leal	16(%esp), %edx
	movdqa	%xmm0, 16(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	call	_memcpy
	addl	$144, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%esi, %eax
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
L520:
	.cfi_restore_state
	movl	168(%esp), %eax
	movl	%esi, %ebx
	pxor	%xmm1, %xmm1
	jmp	L531
	.p2align 4,,7
L529:
	testl	%ecx, %ecx
	jne	L541
	movdqa	%xmm0, (%ebx)
	addl	$16, %edx
	addl	$16, %ebx
	subl	$16, %eax
L531:
	movdqu	(%edx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	movl	%ecx, %edi
	movl	$0, %ecx
	sete	%cl
	cmpl	%edi, %eax
	ja	L529
	leal	80(%esp), %edx
	movdqa	%xmm0, 80(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	call	_memcpy
	addl	$144, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%esi, %eax
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
L519:
	.cfi_restore_state
	movl	168(%esp), %eax
	movl	%esi, %ebx
	pxor	%xmm2, %xmm2
	jmp	L528
	.p2align 4,,7
L526:
	testl	%ecx, %ecx
	jne	L542
	movdqu	%xmm1, (%ebx)
	addl	$16, %edx
	addl	$16, %ebx
	subl	$16, %eax
L528:
	movdqa	(%edx), %xmm1
	pcmpistri	$10, %xmm1, %xmm2
	movl	%ecx, %edi
	movl	$0, %ecx
	sete	%cl
	cmpl	%edi, %eax
	ja	L526
	leal	48(%esp), %edx
	movdqa	%xmm1, 48(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	call	_memcpy
	addl	$144, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%esi, %eax
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
L539:
	.cfi_restore_state
	movl	%ebx, 8(%esp)
	movdqa	%xmm0, 128(%esp)
	movl	%edi, (%esp)
	movl	$0, 4(%esp)
	movl	%ecx, 12(%esp)
	call	_memset
	movl	12(%esp), %ecx
	leal	128(%esp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	addl	$1, %ecx
	movl	%ecx, 8(%esp)
	call	_memcpy
	addl	$144, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%esi, %eax
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
L542:
	.cfi_restore_state
	movl	%ebx, (%esp)
	movdqa	%xmm1, 64(%esp)
	addl	$1, %edi
	movl	%eax, 8(%esp)
	movl	$0, 4(%esp)
	call	_memset
	leal	64(%esp), %eax
	movl	%edi, 8(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	_memcpy
	addl	$144, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%esi, %eax
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
L541:
	.cfi_restore_state
	movl	%ebx, (%esp)
	movdqa	%xmm0, 96(%esp)
	addl	$1, %edi
	movl	%eax, 8(%esp)
	movl	$0, 4(%esp)
	call	_memset
	leal	96(%esp), %eax
	movl	%edi, 8(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	_memcpy
	addl	$144, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%esi, %eax
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
L540:
	.cfi_restore_state
	movl	%ebx, (%esp)
	movdqa	%xmm0, 32(%esp)
	addl	$1, %edi
	movl	%eax, 8(%esp)
	movl	$0, 4(%esp)
	call	_memset
	leal	32(%esp), %eax
	movl	%edi, 8(%esp)
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	_memcpy
	addl	$144, %esp
	.cfi_def_cfa_offset 16
	movl	%esi, %eax
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
LFE3547:
	.p2align 4,,15
	.globl	__Z28testOpt07_Type2_strlen_AfteriPKc
	.def	__Z28testOpt07_Type2_strlen_AfteriPKc;	.scl	2;	.type	32;	.endef
__Z28testOpt07_Type2_strlen_AfteriPKc:
LFB3548:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	12(%esp), %eax
	testb	$15, %al
	movl	%eax, %edx
	jne	L553
L544:
	pxor	%xmm0, %xmm0
	jmp	L548
	.p2align 4,,7
L547:
	addl	$16, %edx
L548:
	pcmpistri	$10, (%edx), %xmm0
	jne	L547
	subl	%eax, %edx
	leal	(%edx,%ecx), %eax
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L553:
	.cfi_restore_state
	movl	$0, %ebx
	pxor	%xmm0, %xmm0
	pcmpistri	$10, (%eax), %xmm0
	leal	15(%eax), %edx
	sete	%bl
	andl	$-16, %edx
	testl	%ebx, %ebx
	je	L544
	movl	%ecx, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3548:
	.p2align 4,,15
	.globl	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	.def	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_;	.scl	2;	.type	32;	.endef
__Z28testOpt07_Type2_strcmp_AfteriPKcS0_:
LFB3549:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	__Z11strcmp_fastPKcS0_
	.cfi_endproc
LFE3549:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	.def	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j:
LFB3550:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	16(%esp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	jmp	__Z12strncmp_fastPKcS0_j
	.cfi_endproc
LFE3550:
	.p2align 4,,15
	.globl	__Z28testOpt07_Type2_strchr_AfteriPKcc
	.def	__Z28testOpt07_Type2_strchr_AfteriPKcc;	.scl	2;	.type	32;	.endef
__Z28testOpt07_Type2_strchr_AfteriPKcc:
LFB3551:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	12(%esp), %eax
	pxor	%xmm0, %xmm0
	movd	16(%esp), %xmm1
	pshufb	%xmm0, %xmm1
	testb	$15, %al
	je	L562
	jmp	L569
	.p2align 4,,7
L561:
	testl	%ebx, %ebx
	jne	L560
	addl	$16, %eax
L562:
	movl	$0, %edx
	movdqa	(%eax), %xmm0
	movl	$0, %ebx
	pcmpistri	$10, %xmm0, %xmm1
	setc	%dl
	sete	%bl
	testl	%edx, %edx
	je	L561
L567:
	addl	%ecx, %eax
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L560:
	.cfi_restore_state
	xorl	%eax, %eax
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L569:
	.cfi_restore_state
	movl	$0, %edx
	movdqu	(%eax), %xmm0
	movl	$0, %ebx
	pcmpistri	$10, %xmm0, %xmm1
	setc	%dl
	sete	%bl
	testl	%edx, %edx
	jne	L567
	testl	%ebx, %ebx
	jne	L560
	addl	$15, %eax
	andl	$-16, %eax
	jmp	L562
	.cfi_endproc
LFE3551:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	.def	__Z29testOpt07_Type2_strrchr_AfteriPKcc;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strrchr_AfteriPKcc:
LFB3552:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	xorl	%esi, %esi
	pxor	%xmm0, %xmm0
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	16(%esp), %edx
	movd	20(%esp), %xmm1
	pshufb	%xmm0, %xmm1
	testb	$15, %dl
	je	L575
	jmp	L584
	.p2align 4,,7
L583:
	addl	$16, %edx
L575:
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
	je	L583
L573:
	movl	%esi, %eax
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
L584:
	.cfi_restore_state
	movl	$0, %ebx
	movdqu	(%edx), %xmm0
	movl	$0, %eax
	pcmpistri	$74, %xmm0, %xmm1
	setc	%bl
	sete	%al
	addl	%edx, %ecx
	testl	%ebx, %ebx
	cmovne	%ecx, %esi
	testl	%eax, %eax
	jne	L573
	addl	$15, %edx
	andl	$-16, %edx
	jmp	L575
	.cfi_endproc
LFE3552:
	.p2align 4,,15
	.globl	__Z28testOpt07_Type2_strstr_AfteriPKcS0_
	.def	__Z28testOpt07_Type2_strstr_AfteriPKcS0_;	.scl	2;	.type	32;	.endef
__Z28testOpt07_Type2_strstr_AfteriPKcS0_:
LFB3553:
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
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	56(%esp), %ebx
	movl	52(%esp), %eax
	testb	$15, %bl
	movl	%ebx, %edx
	jne	L614
L586:
	pxor	%xmm0, %xmm0
	jmp	L590
	.p2align 4,,7
L589:
	addl	$16, %edx
L590:
	pcmpistri	$10, (%edx), %xmm0
	jne	L589
	subl	%ebx, %edx
	leal	(%edx,%ecx), %esi
L588:
	movzbl	(%ebx), %edx
	testb	$15, %al
	pxor	%xmm0, %xmm0
	movb	%dl, 16(%esp)
	movd	16(%esp), %xmm1
	pshufb	%xmm0, %xmm1
	je	L596
	jmp	L615
	.p2align 4,,7
L595:
	testl	%ecx, %ecx
	jne	L594
	addl	$16, %eax
L596:
	movl	$0, %edx
	movdqa	(%eax), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	movl	%ecx, %edi
	setc	%dl
	movl	$0, %ecx
	sete	%cl
	testl	%edx, %edx
	je	L595
L613:
	addl	%eax, %edi
	movdqa	%xmm1, 16(%esp)
	testl	%edi, %edi
	je	L603
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	call	__Z12strncmp_fastPKcS0_j
	testl	%eax, %eax
	je	L603
	leal	1(%edi), %eax
	movdqa	16(%esp), %xmm1
	testb	$15, %al
	je	L596
L615:
	movl	$0, %edx
	movdqu	(%eax), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	movl	%ecx, %edi
	setc	%dl
	movl	$0, %ecx
	sete	%cl
	testl	%edx, %edx
	jne	L613
	testl	%ecx, %ecx
	jne	L594
	addl	$15, %eax
	andl	$-16, %eax
	jmp	L596
	.p2align 4,,7
L594:
	xorl	%edi, %edi
L603:
	addl	$32, %esp
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
L614:
	.cfi_restore_state
	pxor	%xmm0, %xmm0
	pcmpistri	$10, (%ebx), %xmm0
	movl	%ecx, %esi
	movl	$0, %ecx
	sete	%cl
	leal	15(%ebx), %edx
	andl	$-16, %edx
	testl	%ecx, %ecx
	je	L586
	jmp	L588
	.cfi_endproc
LFE3553:
	.p2align 4,,15
	.globl	__Z28testOpt07_Type2_strcpy_AfteriPcPKc
	.def	__Z28testOpt07_Type2_strcpy_AfteriPcPKc;	.scl	2;	.type	32;	.endef
__Z28testOpt07_Type2_strcpy_AfteriPcPKc:
LFB3554:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	xorl	%eax, %eax
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$84, %esp
	.cfi_def_cfa_offset 96
	movl	100(%esp), %esi
	movl	104(%esp), %edx
	testl	$15, %esi
	movl	%edx, %ecx
	setne	%al
	andl	$15, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	notl	%ecx
	andl	$2, %ecx
	orl	%eax, %ecx
	cmpl	$1, %ecx
	je	L619
	cmpl	$2, %ecx
	je	L620
	testl	%ecx, %ecx
	movl	%esi, %ebx
	pxor	%xmm1, %xmm1
	jne	L630
	movl	%esi, %eax
	pxor	%xmm1, %xmm1
	jmp	L624
	.p2align 4,,7
L622:
	movdqa	%xmm0, (%eax)
	addl	$16, %edx
	addl	$16, %eax
L624:
	movdqa	(%edx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L622
	leal	16(%esp), %edx
	addl	$1, %ecx
	movdqa	%xmm0, 16(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_memcpy
	addl	$84, %esp
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
L629:
	.cfi_restore_state
	movdqu	%xmm0, (%ebx)
	addl	$16, %edx
	addl	$16, %ebx
L630:
	movdqu	(%edx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L629
	leal	64(%esp), %eax
	addl	$1, %ecx
	movdqa	%xmm0, 64(%esp)
	movl	%ebx, (%esp)
	movl	%ecx, 8(%esp)
	movl	%eax, 4(%esp)
	call	_memcpy
	addl	$84, %esp
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
L620:
	.cfi_restore_state
	movl	%esi, %eax
	pxor	%xmm1, %xmm1
	jmp	L628
	.p2align 4,,7
L627:
	movdqa	%xmm0, (%eax)
	addl	$16, %edx
	addl	$16, %eax
L628:
	movdqu	(%edx), %xmm0
	pcmpistri	$10, %xmm0, %xmm1
	jne	L627
	leal	48(%esp), %edx
	addl	$1, %ecx
	movdqa	%xmm0, 48(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_memcpy
	addl	$84, %esp
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
L619:
	.cfi_restore_state
	movl	%esi, %eax
	pxor	%xmm2, %xmm2
	jmp	L626
	.p2align 4,,7
L625:
	movdqu	%xmm1, (%eax)
	addl	$16, %edx
	addl	$16, %eax
L626:
	movdqa	(%edx), %xmm1
	pcmpistri	$10, %xmm1, %xmm2
	jne	L625
	leal	32(%esp), %edx
	addl	$1, %ecx
	movdqa	%xmm1, 32(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_memcpy
	addl	$84, %esp
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
LFE3554:
	.p2align 4,,15
	.globl	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	.def	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj;	.scl	2;	.type	32;	.endef
__Z29testOpt07_Type2_strncpy_AfteriPcPKcj:
LFB3555:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	movl	16(%esp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	jmp	__Z12strncpy_fastPcPKcj
	.cfi_endproc
LFE3555:
	.section .rdata,"dr"
	.align 4
LC9:
	.ascii "lambda1()=%d, lambda2()=%d, lambda3()=%d\12\0"
	.text
	.p2align 4,,15
	.globl	__Z13callLambda123v
	.def	__Z13callLambda123v;	.scl	2;	.type	32;	.endef
__Z13callLambda123v:
LFB3559:
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
	je	L637
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L637
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L637
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC9, (%esp)
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
L637:
	.cfi_restore_state
	call	__ZSt25__throw_bad_function_callv
	.cfi_endproc
LFE3559:
	.section .rdata,"dr"
	.align 4
LC10:
	.ascii "lambda1()=%d, lambda2()=NG!, lambda3()=%d\12\0"
	.text
	.p2align 4,,15
	.globl	__Z12callLambda13v
	.def	__Z12callLambda13v;	.scl	2;	.type	32;	.endef
__Z12callLambda13v:
LFB3560:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L641
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L641
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 8(%esp)
	movl	$LC10, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L641:
	.cfi_restore_state
	call	__ZSt25__throw_bad_function_callv
	.cfi_endproc
LFE3560:
	.section .rdata,"dr"
	.align 4
LC11:
	.ascii "Call lambda in block with counter in setLambda().\0"
LC12:
	.ascii "dummy=%d\12\0"
	.align 4
LC13:
	.ascii "Call lambda in block without counter in setLambda().\0"
	.align 4
LC14:
	.ascii "for lambda1: external_counter=%d\12\0"
	.align 4
LC15:
	.ascii "for lambda2: local_counter=%d\12\0"
	.align 4
LC16:
	.ascii "for lambda3: static_counter=%d\12\0"
	.text
	.p2align 4,,15
	.globl	__Z9setLambdaRi
	.def	__Z9setLambdaRi;	.scl	2;	.type	32;	.endef
__Z9setLambdaRi:
LFB3561:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3561
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$52, %esp
	.cfi_def_cfa_offset 64
	movl	_s_lambda1+8, %ecx
	testl	%ecx, %ecx
	je	L644
	movl	_s_lambda2+8, %edx
	testl	%edx, %edx
	je	L644
L645:
	movl	$999, 4(%esp)
	movl	$LC12, (%esp)
LEHB10:
	call	_printf
	movl	$LC13, (%esp)
	call	_puts
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L659
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L659
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L659
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC9, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L659
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L659
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L659
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC9, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	_s_lambda3+8, %ecx
	testl	%ecx, %ecx
	je	L659
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	_s_lambda2+8, %edx
	testl	%edx, %edx
	movl	%eax, %ebx
	je	L659
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L659
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC9, (%esp)
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
L644:
	.cfi_restore_state
	movl	64(%esp), %eax
	movl	$0, 16(%esp)
	movl	(%eax), %eax
	movl	$LC14, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	16(%esp), %eax
	movl	$LC15, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	__ZZ9setLambdaRiE14static_counter, %eax
	movl	$LC16, (%esp)
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
	je	L647
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L647:
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
	je	L651
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L651:
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
	je	L655
	leal	32(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L655:
	movl	$LC11, (%esp)
LEHB14:
	call	_puts
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L659
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L659
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L659
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC9, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	_s_lambda3+8, %eax
	testl	%eax, %eax
	je	L659
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	%eax, %ebx
	movl	_s_lambda2+8, %eax
	testl	%eax, %eax
	je	L659
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	%eax, %esi
	movl	_s_lambda1+8, %eax
	testl	%eax, %eax
	je	L659
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC9, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	movl	_s_lambda3+8, %ebx
	testl	%ebx, %ebx
	je	L659
	movl	$_s_lambda3, (%esp)
	call	*_s_lambda3+12
	movl	_s_lambda2+8, %ecx
	testl	%ecx, %ecx
	movl	%eax, %ebx
	je	L659
	movl	$_s_lambda2, (%esp)
	call	*_s_lambda2+12
	movl	_s_lambda1+8, %edx
	testl	%edx, %edx
	movl	%eax, %esi
	je	L659
	movl	$_s_lambda1, (%esp)
	call	*_s_lambda1+12
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC9, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	jmp	L645
L659:
	call	__ZSt25__throw_bad_function_callv
LEHE14:
L661:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L657
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
L657:
	movl	%ebx, (%esp)
LEHB15:
	call	__Unwind_Resume
LEHE15:
L662:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L657
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L657
L663:
	movl	40(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L657
	leal	32(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L657
	.cfi_endproc
LFE3561:
	.section	.gcc_except_table,"w"
LLSDA3561:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3561-LLSDACSB3561
LLSDACSB3561:
	.uleb128 LEHB10-LFB3561
	.uleb128 LEHE10-LEHB10
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB11-LFB3561
	.uleb128 LEHE11-LEHB11
	.uleb128 L661-LFB3561
	.uleb128 0
	.uleb128 LEHB12-LFB3561
	.uleb128 LEHE12-LEHB12
	.uleb128 L662-LFB3561
	.uleb128 0
	.uleb128 LEHB13-LFB3561
	.uleb128 LEHE13-LEHB13
	.uleb128 L663-LFB3561
	.uleb128 0
	.uleb128 LEHB14-LFB3561
	.uleb128 LEHE14-LEHB14
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB15-LFB3561
	.uleb128 LEHE15-LEHB15
	.uleb128 0
	.uleb128 0
LLSDACSE3561:
	.text
	.p2align 4,,15
	.globl	__Z10getLambda1v
	.def	__Z10getLambda1v;	.scl	2;	.type	32;	.endef
__Z10getLambda1v:
LFB3567:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3567
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
	je	L675
	movl	_s_lambda1+12, %edx
	movl	%eax, 8(%ebx)
	movl	%edx, 12(%ebx)
	movl	$2, 8(%esp)
	movl	$_s_lambda1, 4(%esp)
	movl	%ebx, (%esp)
LEHB16:
	call	*_s_lambda1+8
LEHE16:
L675:
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
L679:
	.cfi_restore_state
	movl	8(%ebx), %edx
	movl	%eax, %esi
	testl	%edx, %edx
	je	L678
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%edx
L678:
	movl	%esi, (%esp)
LEHB17:
	call	__Unwind_Resume
LEHE17:
	.cfi_endproc
LFE3567:
	.section	.gcc_except_table,"w"
LLSDA3567:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3567-LLSDACSB3567
LLSDACSB3567:
	.uleb128 LEHB16-LFB3567
	.uleb128 LEHE16-LEHB16
	.uleb128 L679-LFB3567
	.uleb128 0
	.uleb128 LEHB17-LFB3567
	.uleb128 LEHE17-LEHB17
	.uleb128 0
	.uleb128 0
LLSDACSE3567:
	.text
	.p2align 4,,15
	.globl	__Z10getLambda2v
	.def	__Z10getLambda2v;	.scl	2;	.type	32;	.endef
__Z10getLambda2v:
LFB3568:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3568
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
	je	L687
	movl	_s_lambda1+12, %edx
	movl	%eax, 8(%ebx)
	movl	%edx, 12(%ebx)
	movl	$2, 8(%esp)
	movl	$_s_lambda1, 4(%esp)
	movl	%ebx, (%esp)
LEHB18:
	call	*_s_lambda1+8
LEHE18:
L687:
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
L691:
	.cfi_restore_state
	movl	8(%ebx), %edx
	movl	%eax, %esi
	testl	%edx, %edx
	je	L690
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%edx
L690:
	movl	%esi, (%esp)
LEHB19:
	call	__Unwind_Resume
LEHE19:
	.cfi_endproc
LFE3568:
	.section	.gcc_except_table,"w"
LLSDA3568:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3568-LLSDACSB3568
LLSDACSB3568:
	.uleb128 LEHB18-LFB3568
	.uleb128 LEHE18-LEHB18
	.uleb128 L691-LFB3568
	.uleb128 0
	.uleb128 LEHB19-LFB3568
	.uleb128 LEHE19-LEHB19
	.uleb128 0
	.uleb128 0
LLSDACSE3568:
	.text
	.section	.text$_Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	.def	__Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
__Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE:
LFB3663:
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
	jne	L719
	testl	$2, %edi
	jne	L720
L701:
	movl	%ebx, %ecx
	xorl	%eax, %eax
	shrl	$2, %ecx
	testb	$2, %bl
	rep stosl
	je	L702
	xorl	%ebp, %ebp
	addl	$2, %edi
	movw	%bp, -2(%edi)
L702:
	andl	$1, %ebx
	je	L703
	movb	$0, (%edi)
L703:
	movl	52(%esp), %edi
	xorl	%ebx, %ebx
	xorl	%eax, %eax
L704:
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
	jne	L704
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
L719:
	.cfi_restore_state
	leal	1(%esi), %edi
	movb	$63, %bl
	testl	$2, %edi
	movb	$0, (%esi)
	je	L701
	.p2align 4,,7
L720:
	xorl	%eax, %eax
	addl	$2, %edi
	movw	%ax, -2(%edi)
	subl	$2, %ebx
	jmp	L701
	.cfi_endproc
LFE3663:
	.section	.text$_Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	.def	__Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
__Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE:
LFB3664:
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
LFE3664:
	.section	.text$_Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	.def	__Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
__Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE:
LFB3665:
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
LFE3665:
	.section	.text$_Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	.def	__Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
__Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE:
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
LFE3666:
	.section	.text$_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	.def	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv;	.scl	2;	.type	32;	.endef
__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv:
LFB3773:
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
	ja	L728
	leal	1(%eax), %ecx
	movl	(%edx,%eax,4), %eax
L729:
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
L728:
	.cfi_restore_state
	movl	%edx, %eax
	andl	$15, %eax
	shrl	$2, %eax
	negl	%eax
	andl	$3, %eax
	je	L745
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
	jbe	L746
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
	jbe	L747
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
L730:
	movl	$227, 4(%esp)
	xorl	%ecx, %ecx
	movdqa	LC17, %xmm2
	subl	%eax, 4(%esp)
	movdqa	LC18, %xmm3
	movdqa	LC19, %xmm4
	sall	$2, %eax
	movdqa	LC20, %xmm5
	pxor	%xmm6, %xmm6
	leal	(%edx,%eax), %ebx
	leal	4(%edx,%eax), %edi
	leal	1588(%edx,%eax), %esi
	xorl	%eax, %eax
	.p2align 4,,7
L736:
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
	jbe	L736
	cmpl	$224, 4(%esp)
	leal	224(%ebp), %eax
	je	L734
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
	je	L734
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
	je	L734
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
L734:
	leal	908(%edx), %eax
	andl	$15, %eax
	shrl	$2, %eax
	negl	%eax
	andl	$3, %eax
	je	L748
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
	jbe	L749
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
	jbe	L750
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
L737:
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
L743:
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
	ja	L743
	movl	12(%esp), %edi
	movl	4(%esp), %eax
	movl	8(%esp), %ecx
	movl	(%esp), %esi
	subl	%edi, %eax
	addl	%edi, %ecx
	cmpl	%esi, %edi
	movl	%eax, 4(%esp)
	je	L741
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
	je	L741
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
	je	L741
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
L741:
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
	jmp	L729
	.p2align 4,,7
L747:
	movl	$225, (%esp)
	movl	$2, %ebp
	jmp	L730
	.p2align 4,,7
L746:
	movl	$226, (%esp)
	movl	$1, %ebp
	jmp	L730
	.p2align 4,,7
L745:
	movl	$227, (%esp)
	xorl	%ebp, %ebp
	jmp	L730
	.p2align 4,,7
L748:
	movl	$396, 4(%esp)
	movl	$227, 8(%esp)
	jmp	L737
	.p2align 4,,7
L750:
	movl	$394, 4(%esp)
	movl	$229, 8(%esp)
	jmp	L737
	.p2align 4,,7
L749:
	movl	$395, 4(%esp)
	movl	$228, 8(%esp)
	jmp	L737
	.cfi_endproc
LFE3773:
	.text
	.p2align 4,,15
	.globl	__Z9initOpt04R11dataOpt04_t
	.def	__Z9initOpt04R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z9initOpt04R11dataOpt04_t:
LFB3030:
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
L768:
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
	jne	L768
	leal	80000(%ebp), %ebx
	movl	$-1342177277, %edi
	cmpl	%ebx, %ebp
	movl	$624, 2512(%esp)
	je	L766
	.p2align 4,,7
L771:
	movl	%esi, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L771
	mull	%edi
	addl	$8, %ebp
	movl	$0x00000000, -4(%ebp)
	shrl	$28, %edx
	movl	%edx, -8(%ebp)
	cmpl	%ebp, %ebx
	jne	L771
L766:
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
LFE3030:
	.p2align 4,,15
	.globl	__Z9initOpt06R11dataOpt06_t
	.def	__Z9initOpt06R11dataOpt06_t;	.scl	2;	.type	32;	.endef
__Z9initOpt06R11dataOpt06_t:
LFB3515:
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
L777:
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
	jne	L777
	leal	80000(%ebp), %ebx
	cmpl	%ebx, %ebp
	movl	$624, 2512(%esp)
	je	L775
	.p2align 4,,7
L781:
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
	fmuls	LC21
	fmuls	LC22
	fadd	%st(1), %st
	fstps	-8(%ebp)
	fstps	-4(%ebp)
	cmpl	%ebp, %ebx
	jne	L781
L775:
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
LFE3515:
	.p2align 4,,15
	.globl	__Z9initOpt02R11dataOpt02_t
	.def	__Z9initOpt02R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z9initOpt02R11dataOpt02_t:
LFB2665:
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
L785:
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
	jne	L785
	leal	40000(%ebp), %ebx
	movl	$-1342177277, %edi
	cmpl	%ebx, %ebp
	movl	$624, 2512(%esp)
	je	L783
	.p2align 4,,7
L788:
	movl	%esi, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L788
	mull	%edi
	addl	$4, %ebp
	shrl	$28, %edx
	movl	%edx, -4(%ebp)
	cmpl	%ebp, %ebx
	jne	L788
L783:
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
LFE2665:
	.p2align 4,,15
	.globl	__Z15initOpt03_Type3R11dataOpt03_t
	.def	__Z15initOpt03_Type3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z15initOpt03_Type3R11dataOpt03_t:
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
L794:
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
	jne	L794
	leal	40000(%ebp), %ebx
	movl	$-1342177277, %edi
	cmpl	%ebx, %ebp
	movl	$624, 2512(%esp)
	je	L792
	.p2align 4,,7
L797:
	movl	%esi, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L797
	mull	%edi
	addl	$4, %ebp
	shrl	$28, %edx
	movl	%edx, -4(%ebp)
	cmpl	%ebp, %ebx
	jne	L797
L792:
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
	.globl	__Z9initOpt01R11dataOpt01_t
	.def	__Z9initOpt01R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z9initOpt01R11dataOpt01_t:
LFB2660:
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
L803:
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
	jne	L803
	leal	40004(%ebp), %edi
	leal	4(%ebp), %ebx
	cmpl	%edi, %ebx
	movl	$0, 0(%ebp)
	movl	$-1342177277, %ebp
	movl	$624, 2512(%esp)
	je	L801
	.p2align 4,,7
L806:
	movl	%esi, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-5, %eax
	ja	L806
	mull	%ebp
	addl	$4, %ebx
	shrl	$28, %edx
	movl	%edx, -4(%ebx)
	cmpl	%ebx, %edi
	jne	L806
L801:
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
LFE2660:
	.section	.text.startup,"x"
	.p2align 4,,15
	.def	__GLOBAL__sub_I__Z9initOpt01R11dataOpt01_t;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z9initOpt01R11dataOpt01_t:
LFB3870:
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
LFE3870:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z9initOpt01R11dataOpt01_t
	.section	.text.exit,"x"
	.p2align 4,,15
	.def	__GLOBAL__sub_D__Z9initOpt01R11dataOpt01_t;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_D__Z9initOpt01R11dataOpt01_t:
LFB3871:
	.cfi_startproc
	jmp	__Z41__static_initialization_and_destruction_0ii.part.34
	.cfi_endproc
LFE3871:
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
LC17:
	.long	2147483647
	.long	2147483647
	.long	2147483647
	.long	2147483647
	.align 16
LC18:
	.long	-2147483648
	.long	-2147483648
	.long	-2147483648
	.long	-2147483648
	.align 16
LC19:
	.long	1
	.long	1
	.long	1
	.long	1
	.align 16
LC20:
	.long	-1727483681
	.long	-1727483681
	.long	-1727483681
	.long	-1727483681
	.align 4
LC21:
	.long	796917760
	.align 4
LC22:
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
	.def	_memcpy;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef

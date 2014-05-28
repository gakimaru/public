	.file	"cpu_optimization.cpp"
	.section	.text$_Z22testOpt04_Type1_Beforef,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z22testOpt04_Type1_Beforef
	.def	__Z22testOpt04_Type1_Beforef;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type1_Beforef:
LFB2:
	.cfi_startproc
	flds	LC0
	fdivrs	4(%esp)
	ret
	.cfi_endproc
LFE2:
	.section	.text$_Z21testOpt04_Type1_Afterf,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z21testOpt04_Type1_Afterf
	.def	__Z21testOpt04_Type1_Afterf;	.scl	2;	.type	32;	.endef
__Z21testOpt04_Type1_Afterf:
LFB3:
	.cfi_startproc
	flds	LC2
	fmuls	4(%esp)
	ret
	.cfi_endproc
LFE3:
	.section	.text$_ZNSt17_Function_handlerIFffEPS0_E9_M_invokeERKSt9_Any_dataf,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__ZNSt17_Function_handlerIFffEPS0_E9_M_invokeERKSt9_Any_dataf
	.def	__ZNSt17_Function_handlerIFffEPS0_E9_M_invokeERKSt9_Any_dataf;	.scl	2;	.type	32;	.endef
__ZNSt17_Function_handlerIFffEPS0_E9_M_invokeERKSt9_Any_dataf:
LFB3400:
	.cfi_startproc
	movl	4(%esp), %eax
	flds	8(%esp)
	fstps	4(%esp)
	movl	(%eax), %eax
	jmp	*%eax
	.cfi_endproc
LFE3400:
	.section	.text$_ZNSt14_Function_base13_Base_managerIPFffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__ZNSt14_Function_base13_Base_managerIPFffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation
	.def	__ZNSt14_Function_base13_Base_managerIPFffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation;	.scl	2;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIPFffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation:
LFB3401:
	.cfi_startproc
	movl	12(%esp), %eax
	cmpl	$1, %eax
	je	L6
	cmpl	$2, %eax
	je	L7
	testl	%eax, %eax
	je	L13
L5:
	xorl	%eax, %eax
	.p2align 4,,4
	ret
	.p2align 4,,7
L13:
	movl	4(%esp), %eax
	movl	$__ZTIPFffE, (%eax)
	xorl	%eax, %eax
	ret
	.p2align 4,,7
L7:
	movl	4(%esp), %edx
	movl	8(%esp), %eax
	testl	%edx, %edx
	movl	(%eax), %eax
	je	L5
	movl	4(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	ret
	.p2align 4,,7
L6:
	movl	4(%esp), %eax
	movl	8(%esp), %edx
	movl	%edx, (%eax)
	xorl	%eax, %eax
	ret
	.cfi_endproc
LFE3401:
	.section	.text$_ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff
	.def	__ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff;	.scl	2;	.type	32;	.endef
__ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff:
LFB3405:
	.cfi_startproc
	movl	4(%esp), %eax
	flds	8(%esp)
	flds	12(%esp)
	fstps	8(%esp)
	fstps	4(%esp)
	movl	(%eax), %eax
	jmp	*%eax
	.cfi_endproc
LFE3405:
	.section	.text$_ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation
	.def	__ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation;	.scl	2;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation:
LFB3406:
	.cfi_startproc
	movl	12(%esp), %eax
	cmpl	$1, %eax
	je	L17
	cmpl	$2, %eax
	je	L18
	testl	%eax, %eax
	je	L23
L16:
	xorl	%eax, %eax
	.p2align 4,,4
	ret
	.p2align 4,,7
L23:
	movl	4(%esp), %eax
	movl	$__ZTIPFfffE, (%eax)
	xorl	%eax, %eax
	ret
	.p2align 4,,7
L18:
	movl	4(%esp), %ecx
	movl	8(%esp), %eax
	testl	%ecx, %ecx
	movl	(%eax), %eax
	je	L16
	movl	4(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	ret
	.p2align 4,,7
L17:
	movl	4(%esp), %eax
	movl	8(%esp), %edx
	movl	%edx, (%eax)
	xorl	%eax, %eax
	ret
	.cfi_endproc
LFE3406:
	.section	.text$_Z22testOpt04_Type4_After1f,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z22testOpt04_Type4_After1f
	.def	__Z22testOpt04_Type4_After1f;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type4_After1f:
LFB495:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movss	32(%esp), %xmm0
	shufps	$0, %xmm0, %xmm0
	movaps	%xmm0, %xmm1
	rsqrtss	%xmm0, %xmm1
	mulss	%xmm1, %xmm0
	movaps	%xmm0, (%esp)
	flds	(%esp)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE495:
	.section	.text$_Z22testOpt04_Type4_After2f,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z22testOpt04_Type4_After2f
	.def	__Z22testOpt04_Type4_After2f;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type4_After2f:
LFB496:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movss	32(%esp), %xmm0
	shufps	$0, %xmm0, %xmm0
	movaps	%xmm0, %xmm1
	movaps	%xmm0, %xmm3
	rsqrtss	%xmm0, %xmm1
	movaps	%xmm1, %xmm2
	mulss	%xmm1, %xmm2
	mulss	%xmm2, %xmm3
	movaps	LC3, %xmm2
	subss	%xmm3, %xmm2
	mulss	%xmm2, %xmm1
	mulss	LC4, %xmm1
	mulss	%xmm1, %xmm0
	movaps	%xmm0, (%esp)
	flds	(%esp)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE496:
	.section	.text$_Z22testOpt04_Type4_After3f,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z22testOpt04_Type4_After3f
	.def	__Z22testOpt04_Type4_After3f;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type4_After3f:
LFB497:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movss	32(%esp), %xmm0
	shufps	$0, %xmm0, %xmm0
	movaps	%xmm0, %xmm1
	movaps	%xmm0, %xmm3
	movaps	%xmm0, %xmm6
	rsqrtss	%xmm0, %xmm1
	movaps	%xmm1, %xmm2
	mulss	%xmm1, %xmm2
	mulss	%xmm2, %xmm3
	movaps	LC3, %xmm2
	movaps	%xmm2, %xmm5
	subss	%xmm3, %xmm5
	movaps	LC4, %xmm3
	mulss	%xmm5, %xmm1
	mulss	%xmm3, %xmm1
	movaps	%xmm1, %xmm4
	mulss	%xmm1, %xmm4
	mulss	%xmm4, %xmm6
	subss	%xmm6, %xmm2
	mulss	%xmm2, %xmm1
	mulss	%xmm3, %xmm1
	mulss	%xmm1, %xmm0
	movaps	%xmm0, (%esp)
	flds	(%esp)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE497:
	.section	.text$_Z22testOpt04_Type4_Beforef,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z22testOpt04_Type4_Beforef
	.def	__Z22testOpt04_Type4_Beforef;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type4_Beforef:
LFB494:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movss	32(%esp), %xmm0
	shufps	$0, %xmm0, %xmm0
	sqrtss	%xmm0, %xmm0
	movaps	%xmm0, (%esp)
	flds	(%esp)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE494:
	.section	.text$_Z22testOpt04_Type3_After1ff,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z22testOpt04_Type3_After1ff
	.def	__Z22testOpt04_Type3_After1ff;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type3_After1ff:
LFB491:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movss	36(%esp), %xmm1
	movss	32(%esp), %xmm0
	shufps	$0, %xmm1, %xmm1
	shufps	$0, %xmm0, %xmm0
	rcpss	%xmm1, %xmm1
	mulss	%xmm1, %xmm0
	movaps	%xmm0, (%esp)
	flds	(%esp)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE491:
	.section	.text$_Z22testOpt04_Type3_After2ff,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z22testOpt04_Type3_After2ff
	.def	__Z22testOpt04_Type3_After2ff;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type3_After2ff:
LFB492:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movss	36(%esp), %xmm0
	shufps	$0, %xmm0, %xmm0
	movaps	%xmm0, %xmm1
	movaps	%xmm0, %xmm2
	rcpss	%xmm0, %xmm1
	movaps	LC5, %xmm0
	mulss	%xmm1, %xmm2
	subss	%xmm2, %xmm0
	mulss	%xmm0, %xmm1
	movss	32(%esp), %xmm0
	shufps	$0, %xmm0, %xmm0
	mulss	%xmm1, %xmm0
	movaps	%xmm0, (%esp)
	flds	(%esp)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE492:
	.section	.text$_Z22testOpt04_Type3_After3ff,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z22testOpt04_Type3_After3ff
	.def	__Z22testOpt04_Type3_After3ff;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type3_After3ff:
LFB493:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movss	36(%esp), %xmm0
	movaps	LC5, %xmm1
	shufps	$0, %xmm0, %xmm0
	movaps	%xmm1, %xmm4
	movaps	%xmm0, %xmm2
	movaps	%xmm0, %xmm3
	rcpss	%xmm0, %xmm2
	mulss	%xmm2, %xmm3
	subss	%xmm3, %xmm4
	mulss	%xmm4, %xmm2
	mulss	%xmm2, %xmm0
	subss	%xmm0, %xmm1
	movss	32(%esp), %xmm0
	mulss	%xmm1, %xmm2
	shufps	$0, %xmm0, %xmm0
	mulss	%xmm2, %xmm0
	movaps	%xmm0, (%esp)
	flds	(%esp)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE493:
	.section	.text$_Z22testOpt04_Type3_Beforeff,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z22testOpt04_Type3_Beforeff
	.def	__Z22testOpt04_Type3_Beforeff;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type3_Beforeff:
LFB490:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movss	32(%esp), %xmm0
	movss	36(%esp), %xmm1
	shufps	$0, %xmm0, %xmm0
	shufps	$0, %xmm1, %xmm1
	divss	%xmm1, %xmm0
	movaps	%xmm0, (%esp)
	flds	(%esp)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE490:
	.section .rdata,"dr"
LC7:
	.ascii "*elapsed time=%.9lf\0"
	.text
	.p2align 4,,15
	.globl	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb
	.def	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb;	.scl	2;	.type	32;	.endef
__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb:
LFB2778:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	48(%esp), %esi
	movl	52(%esp), %ebx
	call	__ZNSt6chrono3_V212system_clock3nowEv
	subl	(%esi), %eax
	sbbl	4(%esi), %edx
	movl	$LC7, (%esp)
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	testb	%bl, %bl
	je	L43
	addl	$36, %esp
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
L43:
	.cfi_restore_state
	movl	$10, 48(%esp)
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2778:
	.section .rdata,"dr"
	.align 4
LC8:
	.ascii "----------------------------------------\0"
LC9:
	.ascii "[Optimize Test 01]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt01v
	.def	__Z12runTestOpt01v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt01v:
LFB2784:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$40040, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_def_cfa_offset 40048
	movl	$LC8, (%esp)
	leal	28(%esp), %ebx
	call	_puts
	movl	$LC9, (%esp)
	call	_puts
	movl	%ebx, (%esp)
	call	__Z9initOpt01R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z18runTestOpt01_Type1R11dataOpt01_t
	addl	$40040, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2784:
	.section .rdata,"dr"
LC10:
	.ascii "Type1: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt01_Type1R11dataOpt01_t
	.def	__Z18runTestOpt01_Type1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z18runTestOpt01_Type1R11dataOpt01_t:
LFB2785:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	movl	$100000, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	movl	%ebx, (%esp)
	call	__Z22testOpt01_Type1_BeforeR11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z22testOpt01_Type1_After1R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z22testOpt01_Type1_After2R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z22testOpt01_Type1_After3R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z22testOpt01_Type1_After4R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z24testOpt01_Type1_AppendixR11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt01_Type1_BeforeR11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt01_Type1_After1R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt01_Type1_After2R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt01_Type1_After3R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt01_Type1_After4R11dataOpt01_t
	movl	%ebx, 32(%esp)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	__Z27runTestOpt01_Type1_AppendixR11dataOpt01_t
	.cfi_endproc
LFE2785:
	.section .rdata,"dr"
LC11:
	.ascii "  Before   ... \0"
LC12:
	.ascii "  sum=%d\12\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt01_Type1_BeforeR11dataOpt01_t
	.def	__Z25runTestOpt01_Type1_BeforeR11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt01_Type1_BeforeR11dataOpt01_t:
LFB2786:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$100000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC11, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L50:
	movl	%esi, (%esp)
	call	__Z22testOpt01_Type1_BeforeR11dataOpt01_t
	subl	$1, %ebx
	jne	L50
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	(%esi), %eax
	movl	$LC12, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2786:
	.section .rdata,"dr"
LC13:
	.ascii "  After1   ... \0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt01_Type1_After1R11dataOpt01_t
	.def	__Z25runTestOpt01_Type1_After1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt01_Type1_After1R11dataOpt01_t:
LFB2787:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$100000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC13, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L54:
	movl	%esi, (%esp)
	call	__Z22testOpt01_Type1_After1R11dataOpt01_t
	subl	$1, %ebx
	jne	L54
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	(%esi), %eax
	movl	$LC12, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2787:
	.section .rdata,"dr"
LC14:
	.ascii "  After2   ... \0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt01_Type1_After2R11dataOpt01_t
	.def	__Z25runTestOpt01_Type1_After2R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt01_Type1_After2R11dataOpt01_t:
LFB2788:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$100000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC14, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L58:
	movl	%esi, (%esp)
	call	__Z22testOpt01_Type1_After2R11dataOpt01_t
	subl	$1, %ebx
	jne	L58
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	(%esi), %eax
	movl	$LC12, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2788:
	.section .rdata,"dr"
LC15:
	.ascii "  After3   ... \0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt01_Type1_After3R11dataOpt01_t
	.def	__Z25runTestOpt01_Type1_After3R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt01_Type1_After3R11dataOpt01_t:
LFB2789:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$100000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC15, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L62:
	movl	%esi, (%esp)
	call	__Z22testOpt01_Type1_After3R11dataOpt01_t
	subl	$1, %ebx
	jne	L62
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	(%esi), %eax
	movl	$LC12, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2789:
	.section .rdata,"dr"
LC16:
	.ascii "  After4   ... \0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt01_Type1_After4R11dataOpt01_t
	.def	__Z25runTestOpt01_Type1_After4R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt01_Type1_After4R11dataOpt01_t:
LFB2790:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$100000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC16, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L66:
	movl	%esi, (%esp)
	call	__Z22testOpt01_Type1_After4R11dataOpt01_t
	subl	$1, %ebx
	jne	L66
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	(%esi), %eax
	movl	$LC12, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2790:
	.section .rdata,"dr"
LC17:
	.ascii "  Appendix ... \0"
	.text
	.p2align 4,,15
	.globl	__Z27runTestOpt01_Type1_AppendixR11dataOpt01_t
	.def	__Z27runTestOpt01_Type1_AppendixR11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z27runTestOpt01_Type1_AppendixR11dataOpt01_t:
LFB2791:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$100000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC17, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L70:
	movl	%esi, (%esp)
	call	__Z24testOpt01_Type1_AppendixR11dataOpt01_t
	subl	$1, %ebx
	jne	L70
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	(%esi), %eax
	movl	$LC12, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2791:
	.section .rdata,"dr"
LC18:
	.ascii "[Optimize Test 02]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt02v
	.def	__Z12runTestOpt02v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt02v:
LFB2792:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$40024, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_def_cfa_offset 40032
	movl	$LC8, (%esp)
	leal	16(%esp), %ebx
	call	_puts
	movl	$LC18, (%esp)
	call	_puts
	movl	%ebx, (%esp)
	call	__Z9initOpt02R11dataOpt02_t
	movl	%ebx, (%esp)
	call	__Z18runTestOpt02_Type1R11dataOpt02_t
	addl	$40024, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2792:
	.p2align 4,,15
	.globl	__Z18runTestOpt02_Type1R11dataOpt02_t
	.def	__Z18runTestOpt02_Type1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z18runTestOpt02_Type1R11dataOpt02_t:
LFB2793:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	movl	$100000, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	movl	%ebx, (%esp)
	call	__Z22testOpt02_Type1_BeforeR11dataOpt02_t
	movl	%ebx, (%esp)
	call	__Z22testOpt02_Type1_After1R11dataOpt02_t
	movl	%ebx, (%esp)
	call	__Z22testOpt02_Type1_After2R11dataOpt02_t
	movl	%ebx, (%esp)
	call	__Z22testOpt02_Type1_After3R11dataOpt02_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt02_Type1_BeforeR11dataOpt02_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt02_Type1_After1R11dataOpt02_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt02_Type1_After2R11dataOpt02_t
	movl	%ebx, 32(%esp)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	__Z25runTestOpt02_Type1_After3R11dataOpt02_t
	.cfi_endproc
LFE2793:
	.p2align 4,,15
	.globl	__Z25runTestOpt02_Type1_BeforeR11dataOpt02_t
	.def	__Z25runTestOpt02_Type1_BeforeR11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt02_Type1_BeforeR11dataOpt02_t:
LFB2794:
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
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC11, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L78:
	movl	%esi, (%esp)
	call	__Z22testOpt02_Type1_BeforeR11dataOpt02_t
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L78
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE2794:
	.p2align 4,,15
	.globl	__Z25runTestOpt02_Type1_After1R11dataOpt02_t
	.def	__Z25runTestOpt02_Type1_After1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt02_Type1_After1R11dataOpt02_t:
LFB2795:
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
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC13, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L82:
	movl	%esi, (%esp)
	call	__Z22testOpt02_Type1_After1R11dataOpt02_t
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L82
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE2795:
	.p2align 4,,15
	.globl	__Z25runTestOpt02_Type1_After2R11dataOpt02_t
	.def	__Z25runTestOpt02_Type1_After2R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt02_Type1_After2R11dataOpt02_t:
LFB2796:
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
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC14, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L86:
	movl	%esi, (%esp)
	call	__Z22testOpt02_Type1_After2R11dataOpt02_t
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L86
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE2796:
	.p2align 4,,15
	.globl	__Z25runTestOpt02_Type1_After3R11dataOpt02_t
	.def	__Z25runTestOpt02_Type1_After3R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt02_Type1_After3R11dataOpt02_t:
LFB2797:
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
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC15, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L90:
	movl	%esi, (%esp)
	call	__Z22testOpt02_Type1_After3R11dataOpt02_t
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L90
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE2797:
	.section .rdata,"dr"
LC19:
	.ascii "[Optimize Test 03]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt03v
	.def	__Z12runTestOpt03v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt03v:
LFB2798:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$LC8, (%esp)
	call	_puts
	movl	$LC19, (%esp)
	call	_puts
	call	__Z18runTestOpt03_Type1v
	call	__Z18runTestOpt03_Type2v
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z18runTestOpt03_Type3v
	.cfi_endproc
LFE2798:
	.p2align 4,,15
	.globl	__Z25runTestOpt03_Type1_Beforeii
	.def	__Z25runTestOpt03_Type1_Beforeii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt03_Type1_Beforeii:
LFB2801:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	$LC11, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L96:
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%edi, 8(%esp)
	movl	%ebp, 4(%esp)
	call	__Z22testOpt03_Type1_Beforeiii
	addl	%eax, %esi
	cmpl	$100000000, %ebx
	jne	L96
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 68(%esp)
	movl	$LC12, 64(%esp)
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
	jmp	_printf
	.cfi_endproc
LFE2801:
	.section .rdata,"dr"
LC21:
	.ascii "  After    ... \0"
	.text
	.p2align 4,,15
	.globl	__Z24runTestOpt03_Type1_Afterii
	.def	__Z24runTestOpt03_Type1_Afterii;	.scl	2;	.type	32;	.endef
__Z24runTestOpt03_Type1_Afterii:
LFB2802:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$68, %esp
	.cfi_def_cfa_offset 80
	movl	80(%esp), %eax
	movl	$LC21, (%esp)
	movl	%eax, 16(%esp)
	movl	84(%esp), %eax
	movl	%eax, 32(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movd	16(%esp), %xmm6
	movd	32(%esp), %xmm7
	movdqa	LC22, %xmm5
	pshufd	$0, %xmm6, %xmm4
	pshufd	$0, %xmm7, %xmm3
	pxor	%xmm1, %xmm1
	movdqa	LC20, %xmm0
	movl	%eax, %ebx
	movl	%edx, %esi
	xorl	%eax, %eax
	jmp	L100
	.p2align 4,,7
L102:
	movdqa	%xmm2, %xmm0
L100:
	movdqa	%xmm0, %xmm2
	addl	$1, %eax
	pmulld	%xmm4, %xmm0
	paddd	%xmm3, %xmm0
	cmpl	$25000000, %eax
	paddd	%xmm5, %xmm2
	paddd	%xmm0, %xmm1
	jne	L102
	movdqa	%xmm1, %xmm6
	psrldq	$8, %xmm6
	paddd	%xmm6, %xmm1
	movdqa	%xmm1, %xmm7
	psrldq	$4, %xmm7
	movdqa	%xmm1, 32(%esp)
	movdqa	%xmm7, 16(%esp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%ebx, %eax
	sbbl	%esi, %edx
	movl	%eax, 56(%esp)
	movl	%edx, 60(%esp)
	fildq	56(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movdqa	32(%esp), %xmm1
	paddd	16(%esp), %xmm1
	movl	$LC12, 80(%esp)
	movd	%xmm1, 84(%esp)
	addl	$68, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	_printf
	.cfi_endproc
LFE2802:
	.p2align 4,,15
	.globl	__Z25runTestOpt03_Type2_Beforeiiiiiii
	.def	__Z25runTestOpt03_Type2_Beforeiiiiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt03_Type2_Beforeiiiiiii:
LFB2805:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$92, %esp
	.cfi_def_cfa_offset 112
	movl	120(%esp), %eax
	movl	$LC11, (%esp)
	movl	112(%esp), %ebp
	movl	116(%esp), %edi
	movl	%eax, 44(%esp)
	movl	124(%esp), %eax
	movl	%eax, 48(%esp)
	movl	128(%esp), %eax
	movl	%eax, 52(%esp)
	movl	132(%esp), %eax
	movl	%eax, 56(%esp)
	movl	136(%esp), %eax
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	.p2align 4,,7
L105:
	movl	60(%esp), %eax
	movl	%esi, (%esp)
	addl	$1, %esi
	movl	%edi, 8(%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 28(%esp)
	movl	56(%esp), %eax
	movl	%eax, 24(%esp)
	movl	52(%esp), %eax
	movl	%eax, 20(%esp)
	movl	48(%esp), %eax
	movl	%eax, 16(%esp)
	movl	44(%esp), %eax
	movl	%eax, 12(%esp)
	call	__Z22testOpt03_Type2_Beforeiiiiiiii
	addl	%eax, %ebx
	cmpl	$100000000, %esi
	jne	L105
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%ebx, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE2805:
	.p2align 4,,15
	.globl	__Z24runTestOpt03_Type2_Afteriiiiiii
	.def	__Z24runTestOpt03_Type2_Afteriiiiiii;	.scl	2;	.type	32;	.endef
__Z24runTestOpt03_Type2_Afteriiiiiii:
LFB2806:
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
	movl	112(%esp), %eax
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	132(%esp), %esi
	movl	%eax, 60(%esp)
	movl	116(%esp), %eax
	movl	136(%esp), %ebx
	movl	$LC21, (%esp)
	imull	%edi, %ebp
	movl	%eax, 64(%esp)
	movl	128(%esp), %eax
	imull	%ebx, %esi
	movl	%eax, 68(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movd	60(%esp), %xmm4
	movd	64(%esp), %xmm5
	movl	%ebp, 16(%esp)
	pshufd	$0, %xmm4, %xmm6
	movd	68(%esp), %xmm3
	movl	%esi, 32(%esp)
	movd	16(%esp), %xmm4
	movdqa	LC22, %xmm7
	movd	32(%esp), %xmm1
	pshufd	$0, %xmm5, %xmm5
	pshufd	$0, %xmm1, %xmm1
	pshufd	$0, %xmm4, %xmm4
	movdqa	%xmm1, 16(%esp)
	pshufd	$0, %xmm3, %xmm3
	pxor	%xmm1, %xmm1
	movdqa	LC20, %xmm0
	movl	%eax, 48(%esp)
	xorl	%eax, %eax
	movl	%edx, 52(%esp)
	jmp	L109
	.p2align 4,,7
L111:
	movdqa	%xmm2, %xmm0
L109:
	movdqa	%xmm0, %xmm2
	pmulld	%xmm6, %xmm0
	addl	$1, %eax
	paddd	%xmm5, %xmm0
	cmpl	$25000000, %eax
	psubd	%xmm4, %xmm0
	paddd	%xmm7, %xmm2
	paddd	%xmm3, %xmm0
	psubd	16(%esp), %xmm0
	paddd	%xmm0, %xmm1
	jne	L111
	movdqa	%xmm1, %xmm7
	psrldq	$8, %xmm7
	paddd	%xmm7, %xmm1
	movdqa	%xmm1, %xmm3
	psrldq	$4, %xmm3
	movdqa	%xmm1, 32(%esp)
	movdqa	%xmm3, 16(%esp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	48(%esp), %eax
	sbbl	52(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movdqa	32(%esp), %xmm1
	paddd	16(%esp), %xmm1
	movl	$LC12, 112(%esp)
	movd	%xmm1, 116(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE2806:
	.section .rdata,"dr"
LC23:
	.ascii "Type3: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt03_Type3v
	.def	__Z18runTestOpt03_Type3v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt03_Type3v:
LFB2807:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$40024, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_def_cfa_offset 40032
	leal	16(%esp), %ebx
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z22testOpt03_Type3_BeforeR11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z22testOpt03_Type3_After1R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z22testOpt03_Type3_After2R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z22testOpt03_Type3_After3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z26testOpt03_Type3_AppendixA1R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z26testOpt03_Type3_AppendixA2R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z26testOpt03_Type3_AppendixA3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z26testOpt03_Type3_AppendixB1R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z26testOpt03_Type3_AppendixB2R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z26testOpt03_Type3_AppendixB3R11dataOpt03_t
	movl	$10000, 4(%esp)
	movl	$LC23, (%esp)
	call	_printf
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt03_Type3_BeforeR11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt03_Type3_After1R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt03_Type3_After2R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt03_Type3_After3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z29runTestOpt03_Type3_AppendixA1R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z29runTestOpt03_Type3_AppendixA2R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z29runTestOpt03_Type3_AppendixA3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z29runTestOpt03_Type3_AppendixB1R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z29runTestOpt03_Type3_AppendixB2R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z29runTestOpt03_Type3_AppendixB3R11dataOpt03_t
	addl	$40024, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2807:
	.section .rdata,"dr"
LC24:
	.ascii "  count=%d\12\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt03_Type3_BeforeR11dataOpt03_t
	.def	__Z25runTestOpt03_Type3_BeforeR11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt03_Type3_BeforeR11dataOpt03_t:
LFB2808:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC11, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L116:
	movl	%edi, (%esp)
	call	__Z22testOpt03_Type3_BeforeR11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L116
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC24, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE2808:
	.p2align 4,,15
	.globl	__Z25runTestOpt03_Type3_After1R11dataOpt03_t
	.def	__Z25runTestOpt03_Type3_After1R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt03_Type3_After1R11dataOpt03_t:
LFB2809:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC13, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L120:
	movl	%edi, (%esp)
	call	__Z22testOpt03_Type3_After1R11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L120
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC24, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE2809:
	.p2align 4,,15
	.globl	__Z25runTestOpt03_Type3_After2R11dataOpt03_t
	.def	__Z25runTestOpt03_Type3_After2R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt03_Type3_After2R11dataOpt03_t:
LFB2810:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC14, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L124:
	movl	%edi, (%esp)
	call	__Z22testOpt03_Type3_After2R11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L124
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC24, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE2810:
	.p2align 4,,15
	.globl	__Z25runTestOpt03_Type3_After3R11dataOpt03_t
	.def	__Z25runTestOpt03_Type3_After3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt03_Type3_After3R11dataOpt03_t:
LFB2811:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC15, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L128:
	movl	%edi, (%esp)
	call	__Z22testOpt03_Type3_After3R11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L128
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC24, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE2811:
	.section .rdata,"dr"
LC25:
	.ascii "  AppendixA1.. \0"
	.text
	.p2align 4,,15
	.globl	__Z29runTestOpt03_Type3_AppendixA1R11dataOpt03_t
	.def	__Z29runTestOpt03_Type3_AppendixA1R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z29runTestOpt03_Type3_AppendixA1R11dataOpt03_t:
LFB2812:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC25, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L132:
	movl	%edi, (%esp)
	call	__Z26testOpt03_Type3_AppendixA1R11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L132
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC24, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE2812:
	.section .rdata,"dr"
LC26:
	.ascii "  AppendixA2.. \0"
	.text
	.p2align 4,,15
	.globl	__Z29runTestOpt03_Type3_AppendixA2R11dataOpt03_t
	.def	__Z29runTestOpt03_Type3_AppendixA2R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z29runTestOpt03_Type3_AppendixA2R11dataOpt03_t:
LFB2813:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC26, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L136:
	movl	%edi, (%esp)
	call	__Z26testOpt03_Type3_AppendixA2R11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L136
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC24, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE2813:
	.section .rdata,"dr"
LC27:
	.ascii "  AppendixA3.. \0"
	.text
	.p2align 4,,15
	.globl	__Z29runTestOpt03_Type3_AppendixA3R11dataOpt03_t
	.def	__Z29runTestOpt03_Type3_AppendixA3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z29runTestOpt03_Type3_AppendixA3R11dataOpt03_t:
LFB2814:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC27, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L140:
	movl	%edi, (%esp)
	call	__Z26testOpt03_Type3_AppendixA3R11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L140
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC24, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE2814:
	.section .rdata,"dr"
LC28:
	.ascii "  AppendixB1.. \0"
	.text
	.p2align 4,,15
	.globl	__Z29runTestOpt03_Type3_AppendixB1R11dataOpt03_t
	.def	__Z29runTestOpt03_Type3_AppendixB1R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z29runTestOpt03_Type3_AppendixB1R11dataOpt03_t:
LFB2815:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC28, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L144:
	movl	%edi, (%esp)
	call	__Z26testOpt03_Type3_AppendixB1R11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L144
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC24, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE2815:
	.section .rdata,"dr"
LC29:
	.ascii "  AppendixB2.. \0"
	.text
	.p2align 4,,15
	.globl	__Z29runTestOpt03_Type3_AppendixB2R11dataOpt03_t
	.def	__Z29runTestOpt03_Type3_AppendixB2R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z29runTestOpt03_Type3_AppendixB2R11dataOpt03_t:
LFB2816:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC29, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L148:
	movl	%edi, (%esp)
	call	__Z26testOpt03_Type3_AppendixB2R11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L148
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC24, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE2816:
	.section .rdata,"dr"
LC30:
	.ascii "  AppendixB3.. \0"
	.text
	.p2align 4,,15
	.globl	__Z29runTestOpt03_Type3_AppendixB3R11dataOpt03_t
	.def	__Z29runTestOpt03_Type3_AppendixB3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z29runTestOpt03_Type3_AppendixB3R11dataOpt03_t:
LFB2817:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC30, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L152:
	movl	%edi, (%esp)
	call	__Z26testOpt03_Type3_AppendixB3R11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L152
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC24, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE2817:
	.section .rdata,"dr"
LC31:
	.ascii "[Optimize Test 04]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt04v
	.def	__Z12runTestOpt04v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt04v:
LFB2818:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$80024, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_def_cfa_offset 80032
	movl	$LC8, (%esp)
	leal	16(%esp), %ebx
	call	_puts
	movl	$LC31, (%esp)
	call	_puts
	call	__Z18runTestOpt04_1timev
	movl	%ebx, (%esp)
	call	__Z9initOpt04R11dataOpt04_t
	call	__Z18runTestOpt04_Type1v
	movl	%ebx, (%esp)
	call	__Z18runTestOpt04_Type2R11dataOpt04_t
	movl	$0x3f99999a, (%esp)
	call	__Z18runTestOpt04_Type3f
	call	__Z18runTestOpt04_Type4v
	addl	$80024, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2818:
	.section .rdata,"dr"
LC40:
	.ascii "1\0"
	.align 4
LC41:
	.ascii "[CHECK:TYPE1:%s] div(%.5f~%.5f,%+.5f,*%.1fby%dt / %.5f) [tol=%.5f]\12\0"
	.align 4
LC43:
	.ascii "[CHECK:TYPE1:%s] ng=%d/%d(%.2f%%), diff-avg=%.5f, diff-max=%.5f(%.5f / %.5f)\12\0"
	.align 4
LC44:
	.ascii "[CHECK:TYPE3:%s] div(%.5f~%.5f,%+.5f,*%.1fby%dt / %.5f~%.5f,%+.5f,*%.1fby%dt) [tol=%.5f]\12\0"
LC47:
	.ascii "***** diff=%.5f(%.5f / %.5f)\12\0"
	.align 4
LC48:
	.ascii "[CHECK:TYPE3:%s] ng=%d/%d(%.2f%%), diff-avg=%.5f, diff-max=%.5f(%.5f / %.5f)\12\0"
LC49:
	.ascii "2\0"
LC50:
	.ascii "3\0"
	.align 4
LC51:
	.ascii "[CHECK:TYPE4:%s] sqrt(%.5f~%.5f,%+.5f,*%.1fby%dt) [tol=%.5f]\12\0"
LC52:
	.ascii "***** diff=%.5f(%.5f)\12\0"
	.align 4
LC53:
	.ascii "[CHECK:TYPE4:%s] ng=%d/%d(%.2f%%), diff-avg=%.5f, diff-max=%.5f(%.5f)\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt04_1timev
	.def	__Z18runTestOpt04_1timev;	.scl	2;	.type	32;	.endef
__Z18runTestOpt04_1timev:
LFB3162:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3162
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
	movl	$LC8, (%esp)
	movl	$__Z21testOpt04_Type1_Afterf, 160(%esp)
	movl	$__ZNSt17_Function_handlerIFffEPS0_E9_M_invokeERKSt9_Any_dataf, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 168(%esp)
	movl	$__Z22testOpt04_Type1_Beforef, 144(%esp)
	movl	$__ZNSt17_Function_handlerIFffEPS0_E9_M_invokeERKSt9_Any_dataf, 156(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 152(%esp)
LEHB0:
	call	_puts
LEHE0:
	flds	LC34
	fstl	52(%esp)
	movl	$1000, 40(%esp)
	flds	LC0
	fstpl	44(%esp)
	flds	LC39
	fstpl	32(%esp)
	fstpl	24(%esp)
	movl	$LC40, 4(%esp)
	flds	LC32
	fstpl	16(%esp)
	fldz
	fstpl	8(%esp)
	movl	$LC41, (%esp)
LEHB1:
	call	_printf
LEHE1:
	fldz
	xorl	%esi, %esi
	fstps	96(%esp)
	xorl	%ebp, %ebp
	movss	96(%esp), %xmm4
	flds	LC34
	leal	144(%esp), %ebx
	fstps	108(%esp)
	movss	%xmm4, 120(%esp)
	leal	160(%esp), %edi
	movss	%xmm4, 112(%esp)
	movss	%xmm4, 100(%esp)
	movl	$0, 116(%esp)
	jmp	L160
	.p2align 4,,7
L723:
	addl	$1, %ebp
L170:
	flds	100(%esp)
	fadd	%st(1), %st
	fstps	100(%esp)
	flds	112(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1044
	movss	96(%esp), %xmm3
	fstps	112(%esp)
	movss	%xmm3, 120(%esp)
	jmp	L171
	.p2align 4,,7
L1044:
	fstp	%st(0)
L171:
	flds	LC32
	flds	96(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L172
	addl	$1, %esi
	movl	$274877907, %edx
	movl	%esi, %eax
	imull	%edx
	movl	%esi, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %esi
	jne	L173
	flds	108(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	108(%esp)
L173:
	flds	96(%esp)
	fadds	108(%esp)
	flds	LC32
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	96(%esp)
L160:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L1003
	movss	96(%esp), %xmm7
	movl	%ebx, (%esp)
	movss	%xmm7, 4(%esp)
LEHB2:
	call	*156(%esp)
LEHE2:
	movl	168(%esp), %eax
	fstps	104(%esp)
	testl	%eax, %eax
	je	L1004
	movss	96(%esp), %xmm3
	movl	%edi, (%esp)
	movss	%xmm3, 4(%esp)
LEHB3:
	call	*172(%esp)
LEHE3:
	fsubs	104(%esp)
	fabs
	flds	LC34
	fucomip	%st(1), %st
	ja	L723
	addl	$1, 116(%esp)
	jmp	L170
L172:
	movl	116(%esp), %eax
	movl	$LC40, 4(%esp)
	movl	$LC43, (%esp)
	addl	%eax, %ebp
	movl	%ebp, 140(%esp)
	fildl	140(%esp)
	flds	LC0
	fstpl	48(%esp)
	flds	120(%esp)
	fstpl	40(%esp)
	movl	%eax, 140(%esp)
	flds	112(%esp)
	fstpl	32(%esp)
	movl	%ebp, 12(%esp)
	flds	100(%esp)
	fdiv	%st(1), %st
	movl	%eax, 8(%esp)
	fstpl	24(%esp)
	fildl	140(%esp)
	fdivp	%st, %st(1)
	fmuls	LC42
	fstpl	16(%esp)
LEHB4:
	call	_printf
LEHE4:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L178
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
L178:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L179
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L179:
	movl	$LC8, (%esp)
	movl	$__Z22testOpt04_Type3_After1ff, 160(%esp)
	movl	$__ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 168(%esp)
	movl	$__Z22testOpt04_Type3_Beforeff, 144(%esp)
	movl	$__ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff, 156(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 152(%esp)
LEHB5:
	call	_puts
LEHE5:
	flds	LC34
	fstl	80(%esp)
	movl	$1000, 76(%esp)
	flds	LC39
	fstl	68(%esp)
	fxch	%st(1)
	movl	$1000, 40(%esp)
	fstl	60(%esp)
	movl	$LC40, 4(%esp)
	flds	LC32
	fstl	52(%esp)
	fxch	%st(1)
	movl	$LC44, (%esp)
	fstl	44(%esp)
	fxch	%st(2)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fldz
	fstpl	8(%esp)
LEHB6:
	call	_printf
LEHE6:
	fldz
	xorl	%ebp, %ebp
	fstps	108(%esp)
	movss	108(%esp), %xmm5
	flds	LC34
	fstps	136(%esp)
	movss	%xmm5, 124(%esp)
	movss	%xmm5, 128(%esp)
	movss	%xmm5, 104(%esp)
	movss	%xmm5, 112(%esp)
	movl	$0, 132(%esp)
	movl	$0, 120(%esp)
	.p2align 4,,7
L183:
	flds	LC34
	xorl	%esi, %esi
	fstps	96(%esp)
	movss	96(%esp), %xmm0
	movss	%xmm0, 116(%esp)
	jmp	L184
	.p2align 4,,7
L724:
	addl	$1, %ebp
L194:
	flds	112(%esp)
	flds	100(%esp)
	fadd	%st, %st(1)
	fxch	%st(1)
	fstps	112(%esp)
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	jbe	L1045
	flds	LC34
	fucomi	%st(2), %st
	fstp	%st(2)
	jbe	L1046
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L199
	jmp	L197
	.p2align 4,,7
L1046:
	fstp	%st(0)
	fstp	%st(0)
L197:
	flds	LC45
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1047
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L199
	jmp	L200
	.p2align 4,,7
L1047:
	fstp	%st(0)
L200:
	flds	LC38
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1048
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L199
	jmp	L202
	.p2align 4,,7
L1048:
	fstp	%st(0)
L202:
	fld1
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	ja	L1005
	fstp	%st(0)
L204:
	flds	LC46
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1049
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L199
	jmp	L206
	.p2align 4,,7
L1049:
	fstp	%st(0)
L206:
	flds	LC42
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1050
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L199
	jmp	L208
	.p2align 4,,7
L1050:
	fstp	%st(0)
L208:
	flds	LC36
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1051
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L199
	jmp	L210
	.p2align 4,,7
L1051:
	fstp	%st(0)
L210:
	flds	LC35
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L932
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L199
	movss	96(%esp), %xmm2
	movss	108(%esp), %xmm3
	movss	100(%esp), %xmm4
	movss	%xmm2, 124(%esp)
	movss	%xmm3, 128(%esp)
	movss	%xmm4, 104(%esp)
	jmp	L195
	.p2align 4,,7
L1045:
	fstp	%st(0)
	fstp	%st(0)
L195:
	flds	LC32
	flds	96(%esp)
	fucomip	%st(1), %st
	jae	L215
	fstp	%st(0)
	jmp	L1008
	.p2align 4,,7
L1052:
	fstp	%st(0)
L1008:
	addl	$1, %esi
	movl	$274877907, %eax
	imull	%esi
	movl	%esi, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %esi
	jne	L216
	flds	116(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	116(%esp)
L216:
	flds	96(%esp)
	fadds	116(%esp)
	flds	LC32
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	96(%esp)
L184:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L1006
	movss	96(%esp), %xmm0
	movss	108(%esp), %xmm1
	movl	%ebx, (%esp)
	movss	%xmm0, 8(%esp)
	movss	%xmm1, 4(%esp)
LEHB7:
	call	*156(%esp)
LEHE7:
	movl	168(%esp), %eax
	fstps	100(%esp)
	testl	%eax, %eax
	je	L1007
	movss	96(%esp), %xmm2
	movss	108(%esp), %xmm3
	movl	%edi, (%esp)
	movss	%xmm2, 8(%esp)
	movss	%xmm3, 4(%esp)
LEHB8:
	call	*172(%esp)
LEHE8:
	flds	100(%esp)
	fsubrp	%st, %st(1)
	fabs
	fsts	100(%esp)
	flds	LC34
	fucomip	%st(1), %st
	fstp	%st(0)
	ja	L724
	addl	$1, 120(%esp)
	jmp	L194
	.p2align 4,,7
L1005:
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jb	L204
	.p2align 4,,7
L199:
	flds	96(%esp)
	fstpl	20(%esp)
	movl	$LC47, (%esp)
	flds	108(%esp)
	fstpl	12(%esp)
	flds	100(%esp)
	fstpl	4(%esp)
LEHB9:
	call	_printf
LEHE9:
	movss	96(%esp), %xmm2
	movss	108(%esp), %xmm3
	movss	100(%esp), %xmm0
	flds	LC32
	flds	96(%esp)
	fucomip	%st(1), %st
	movss	%xmm2, 124(%esp)
	movss	%xmm3, 128(%esp)
	movss	%xmm0, 104(%esp)
	jb	L1052
L215:
	flds	108(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L219
	addl	$1, 132(%esp)
	movl	$274877907, %eax
	movl	132(%esp), %ecx
	imull	%ecx
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %ecx
	jne	L220
	flds	136(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	136(%esp)
L220:
	flds	108(%esp)
	fadds	136(%esp)
	flds	LC32
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	108(%esp)
	jmp	L183
	.p2align 4,,7
L932:
	fstp	%st(0)
	movss	96(%esp), %xmm2
	movss	108(%esp), %xmm4
	movss	100(%esp), %xmm0
	movss	%xmm2, 124(%esp)
	movss	%xmm4, 128(%esp)
	movss	%xmm0, 104(%esp)
	jmp	L195
L219:
	movl	120(%esp), %eax
	movl	$LC40, 4(%esp)
	movl	$LC48, (%esp)
	addl	%eax, %ebp
	movl	%ebp, 140(%esp)
	fildl	140(%esp)
	flds	124(%esp)
	fstpl	48(%esp)
	movl	%eax, 140(%esp)
	flds	128(%esp)
	fstpl	40(%esp)
	movl	%ebp, 12(%esp)
	flds	104(%esp)
	fstpl	32(%esp)
	movl	%eax, 8(%esp)
	flds	112(%esp)
	fdiv	%st(1), %st
	fstpl	24(%esp)
	fildl	140(%esp)
	fdivp	%st, %st(1)
	fmuls	LC42
	fstpl	16(%esp)
LEHB10:
	call	_printf
LEHE10:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L225
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
L225:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L226
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L226:
	movl	$LC8, (%esp)
	movl	$__Z22testOpt04_Type3_After2ff, 160(%esp)
	movl	$__ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 168(%esp)
	movl	$__Z22testOpt04_Type3_Beforeff, 144(%esp)
	movl	$__ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff, 156(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 152(%esp)
LEHB11:
	call	_puts
LEHE11:
	flds	LC34
	fstl	80(%esp)
	movl	$1000, 76(%esp)
	flds	LC39
	fstl	68(%esp)
	fxch	%st(1)
	movl	$1000, 40(%esp)
	fstl	60(%esp)
	movl	$LC49, 4(%esp)
	flds	LC32
	fstl	52(%esp)
	fxch	%st(1)
	movl	$LC44, (%esp)
	fstl	44(%esp)
	fxch	%st(2)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fldz
	fstpl	8(%esp)
LEHB12:
	call	_printf
LEHE12:
	fldz
	xorl	%ebp, %ebp
	fstps	108(%esp)
	movss	108(%esp), %xmm7
	flds	LC34
	fstps	136(%esp)
	movss	%xmm7, 124(%esp)
	movss	%xmm7, 128(%esp)
	movss	%xmm7, 104(%esp)
	movss	%xmm7, 112(%esp)
	movl	$0, 132(%esp)
	movl	$0, 120(%esp)
	.p2align 4,,7
L230:
	flds	LC34
	xorl	%esi, %esi
	fstps	96(%esp)
	movss	96(%esp), %xmm4
	movss	%xmm4, 116(%esp)
	jmp	L231
	.p2align 4,,7
L734:
	addl	$1, %ebp
L241:
	flds	112(%esp)
	flds	100(%esp)
	fadd	%st, %st(1)
	fxch	%st(1)
	fstps	112(%esp)
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	jbe	L1053
	flds	LC34
	fucomi	%st(2), %st
	fstp	%st(2)
	jbe	L1054
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L246
	jmp	L244
	.p2align 4,,7
L1054:
	fstp	%st(0)
	fstp	%st(0)
L244:
	flds	LC45
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1055
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L246
	jmp	L247
	.p2align 4,,7
L1055:
	fstp	%st(0)
L247:
	flds	LC38
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1056
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L246
	jmp	L249
	.p2align 4,,7
L1056:
	fstp	%st(0)
L249:
	fld1
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	ja	L1009
	fstp	%st(0)
L251:
	flds	LC46
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1057
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L246
	jmp	L253
	.p2align 4,,7
L1057:
	fstp	%st(0)
L253:
	flds	LC42
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1058
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L246
	jmp	L255
	.p2align 4,,7
L1058:
	fstp	%st(0)
L255:
	flds	LC36
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1059
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L246
	jmp	L257
	.p2align 4,,7
L1059:
	fstp	%st(0)
L257:
	flds	LC35
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L939
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L246
	movss	96(%esp), %xmm0
	movss	108(%esp), %xmm7
	movss	100(%esp), %xmm1
	movss	%xmm0, 124(%esp)
	movss	%xmm7, 128(%esp)
	movss	%xmm1, 104(%esp)
	jmp	L242
	.p2align 4,,7
L1053:
	fstp	%st(0)
	fstp	%st(0)
L242:
	flds	LC32
	flds	96(%esp)
	fucomip	%st(1), %st
	jae	L262
	fstp	%st(0)
	jmp	L1012
	.p2align 4,,7
L1060:
	fstp	%st(0)
L1012:
	addl	$1, %esi
	movl	$274877907, %eax
	imull	%esi
	movl	%esi, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %esi
	jne	L263
	flds	116(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	116(%esp)
L263:
	flds	96(%esp)
	fadds	116(%esp)
	flds	LC32
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	96(%esp)
L231:
	movl	152(%esp), %ecx
	testl	%ecx, %ecx
	je	L1010
	movss	96(%esp), %xmm4
	movss	108(%esp), %xmm5
	movl	%ebx, (%esp)
	movss	%xmm4, 8(%esp)
	movss	%xmm5, 4(%esp)
LEHB13:
	call	*156(%esp)
LEHE13:
	movl	168(%esp), %edx
	fstps	100(%esp)
	testl	%edx, %edx
	je	L1011
	movss	96(%esp), %xmm6
	movss	108(%esp), %xmm7
	movl	%edi, (%esp)
	movss	%xmm6, 8(%esp)
	movss	%xmm7, 4(%esp)
LEHB14:
	call	*172(%esp)
LEHE14:
	flds	100(%esp)
	fsubrp	%st, %st(1)
	fabs
	fsts	100(%esp)
	flds	LC34
	fucomip	%st(1), %st
	fstp	%st(0)
	ja	L734
	addl	$1, 120(%esp)
	jmp	L241
	.p2align 4,,7
L1009:
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jb	L251
	.p2align 4,,7
L246:
	flds	96(%esp)
	fstpl	20(%esp)
	movl	$LC47, (%esp)
	flds	108(%esp)
	fstpl	12(%esp)
	flds	100(%esp)
	fstpl	4(%esp)
LEHB15:
	call	_printf
LEHE15:
	movss	96(%esp), %xmm1
	movss	108(%esp), %xmm4
	movss	100(%esp), %xmm5
	flds	LC32
	flds	96(%esp)
	fucomip	%st(1), %st
	movss	%xmm1, 124(%esp)
	movss	%xmm4, 128(%esp)
	movss	%xmm5, 104(%esp)
	jb	L1060
L262:
	flds	108(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L266
	addl	$1, 132(%esp)
	movl	$274877907, %eax
	movl	132(%esp), %ecx
	imull	%ecx
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %ecx
	jne	L267
	flds	136(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	136(%esp)
L267:
	flds	108(%esp)
	fadds	136(%esp)
	flds	LC32
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	108(%esp)
	jmp	L230
	.p2align 4,,7
L939:
	fstp	%st(0)
	movss	96(%esp), %xmm3
	movss	108(%esp), %xmm7
	movss	100(%esp), %xmm1
	movss	%xmm3, 124(%esp)
	movss	%xmm7, 128(%esp)
	movss	%xmm1, 104(%esp)
	jmp	L242
L266:
	movl	120(%esp), %eax
	movl	$LC49, 4(%esp)
	movl	$LC48, (%esp)
	addl	%eax, %ebp
	movl	%ebp, 140(%esp)
	fildl	140(%esp)
	flds	124(%esp)
	fstpl	48(%esp)
	movl	%eax, 140(%esp)
	flds	128(%esp)
	fstpl	40(%esp)
	movl	%ebp, 12(%esp)
	flds	104(%esp)
	fstpl	32(%esp)
	movl	%eax, 8(%esp)
	flds	112(%esp)
	fdiv	%st(1), %st
	fstpl	24(%esp)
	fildl	140(%esp)
	fdivp	%st, %st(1)
	fmuls	LC42
	fstpl	16(%esp)
LEHB16:
	call	_printf
LEHE16:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L272
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
L272:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L273
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L273:
	movl	$LC8, (%esp)
	movl	$__Z22testOpt04_Type3_After3ff, 160(%esp)
	movl	$__ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 168(%esp)
	movl	$__Z22testOpt04_Type3_Beforeff, 144(%esp)
	movl	$__ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff, 156(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 152(%esp)
LEHB17:
	call	_puts
LEHE17:
	flds	LC34
	fstl	80(%esp)
	movl	$1000, 76(%esp)
	flds	LC39
	fstl	68(%esp)
	fxch	%st(1)
	movl	$1000, 40(%esp)
	fstl	60(%esp)
	movl	$LC50, 4(%esp)
	flds	LC32
	fstl	52(%esp)
	fxch	%st(1)
	movl	$LC44, (%esp)
	fstl	44(%esp)
	fxch	%st(2)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fldz
	fstpl	8(%esp)
LEHB18:
	call	_printf
LEHE18:
	fldz
	xorl	%ebp, %ebp
	fstps	108(%esp)
	movss	108(%esp), %xmm3
	flds	LC34
	fstps	136(%esp)
	movss	%xmm3, 124(%esp)
	movss	%xmm3, 128(%esp)
	movss	%xmm3, 104(%esp)
	movss	%xmm3, 112(%esp)
	movl	$0, 132(%esp)
	movl	$0, 120(%esp)
	.p2align 4,,7
L277:
	flds	LC34
	xorl	%esi, %esi
	fstps	96(%esp)
	movss	96(%esp), %xmm1
	movss	%xmm1, 116(%esp)
	jmp	L278
	.p2align 4,,7
L744:
	addl	$1, %ebp
L288:
	flds	112(%esp)
	flds	100(%esp)
	fadd	%st, %st(1)
	fxch	%st(1)
	fstps	112(%esp)
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	jbe	L1061
	flds	LC34
	fucomi	%st(2), %st
	fstp	%st(2)
	jbe	L1062
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L293
	jmp	L291
	.p2align 4,,7
L1062:
	fstp	%st(0)
	fstp	%st(0)
L291:
	flds	LC45
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1063
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L293
	jmp	L294
	.p2align 4,,7
L1063:
	fstp	%st(0)
L294:
	flds	LC38
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1064
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L293
	jmp	L296
	.p2align 4,,7
L1064:
	fstp	%st(0)
L296:
	fld1
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	ja	L1013
	fstp	%st(0)
L298:
	flds	LC46
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1065
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L293
	jmp	L300
	.p2align 4,,7
L1065:
	fstp	%st(0)
L300:
	flds	LC42
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1066
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L293
	jmp	L302
	.p2align 4,,7
L1066:
	fstp	%st(0)
L302:
	flds	LC36
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1067
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L293
	jmp	L304
	.p2align 4,,7
L1067:
	fstp	%st(0)
L304:
	flds	LC35
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L946
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L293
	movss	96(%esp), %xmm5
	movss	108(%esp), %xmm2
	movss	100(%esp), %xmm0
	movss	%xmm5, 124(%esp)
	movss	%xmm2, 128(%esp)
	movss	%xmm0, 104(%esp)
	jmp	L289
	.p2align 4,,7
L1061:
	fstp	%st(0)
	fstp	%st(0)
L289:
	flds	LC32
	flds	96(%esp)
	fucomip	%st(1), %st
	jae	L309
	fstp	%st(0)
	jmp	L1016
	.p2align 4,,7
L1068:
	fstp	%st(0)
L1016:
	addl	$1, %esi
	movl	$274877907, %eax
	imull	%esi
	movl	%esi, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %esi
	jne	L310
	flds	116(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	116(%esp)
L310:
	flds	96(%esp)
	fadds	116(%esp)
	flds	LC32
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	96(%esp)
L278:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L1014
	movss	96(%esp), %xmm4
	movss	108(%esp), %xmm5
	movl	%ebx, (%esp)
	movss	%xmm4, 8(%esp)
	movss	%xmm5, 4(%esp)
LEHB19:
	call	*156(%esp)
LEHE19:
	movl	168(%esp), %eax
	fstps	100(%esp)
	testl	%eax, %eax
	je	L1015
	movss	96(%esp), %xmm6
	movss	108(%esp), %xmm7
	movl	%edi, (%esp)
	movss	%xmm6, 8(%esp)
	movss	%xmm7, 4(%esp)
LEHB20:
	call	*172(%esp)
LEHE20:
	flds	100(%esp)
	fsubrp	%st, %st(1)
	fabs
	fsts	100(%esp)
	flds	LC34
	fucomip	%st(1), %st
	fstp	%st(0)
	ja	L744
	addl	$1, 120(%esp)
	jmp	L288
	.p2align 4,,7
L1013:
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jb	L298
	.p2align 4,,7
L293:
	flds	96(%esp)
	fstpl	20(%esp)
	movl	$LC47, (%esp)
	flds	108(%esp)
	fstpl	12(%esp)
	flds	100(%esp)
	fstpl	4(%esp)
LEHB21:
	call	_printf
LEHE21:
	movss	96(%esp), %xmm6
	movss	108(%esp), %xmm7
	movss	100(%esp), %xmm1
	flds	LC32
	flds	96(%esp)
	fucomip	%st(1), %st
	movss	%xmm6, 124(%esp)
	movss	%xmm7, 128(%esp)
	movss	%xmm1, 104(%esp)
	jb	L1068
L309:
	flds	108(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L313
	addl	$1, 132(%esp)
	movl	$274877907, %eax
	movl	132(%esp), %ecx
	imull	%ecx
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %ecx
	jne	L314
	flds	136(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	136(%esp)
L314:
	flds	108(%esp)
	fadds	136(%esp)
	flds	LC32
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	108(%esp)
	jmp	L277
	.p2align 4,,7
L946:
	fstp	%st(0)
	movss	96(%esp), %xmm2
	movss	108(%esp), %xmm4
	movss	100(%esp), %xmm3
	movss	%xmm2, 124(%esp)
	movss	%xmm4, 128(%esp)
	movss	%xmm3, 104(%esp)
	jmp	L289
L313:
	movl	120(%esp), %eax
	movl	$LC50, 4(%esp)
	movl	$LC48, (%esp)
	addl	%eax, %ebp
	movl	%ebp, 140(%esp)
	fildl	140(%esp)
	flds	124(%esp)
	fstpl	48(%esp)
	movl	%eax, 140(%esp)
	flds	128(%esp)
	fstpl	40(%esp)
	movl	%ebp, 12(%esp)
	flds	104(%esp)
	fstpl	32(%esp)
	movl	%eax, 8(%esp)
	flds	112(%esp)
	fdiv	%st(1), %st
	fstpl	24(%esp)
	fildl	140(%esp)
	fdivp	%st, %st(1)
	fmuls	LC42
	fstpl	16(%esp)
LEHB22:
	call	_printf
LEHE22:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L319
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
L319:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L320
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L320:
	movl	$LC8, (%esp)
	movl	$__Z22testOpt04_Type3_After1ff, 160(%esp)
	movl	$__ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 168(%esp)
	movl	$__Z22testOpt04_Type3_Beforeff, 144(%esp)
	movl	$__ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff, 156(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 152(%esp)
LEHB23:
	call	_puts
LEHE23:
	flds	LC34
	fstl	80(%esp)
	movl	$1000, 76(%esp)
	flds	LC39
	fstl	68(%esp)
	movl	$1000, 40(%esp)
	flds	LC38
	fstpl	60(%esp)
	flds	LC36
	fstpl	52(%esp)
	fld1
	fstpl	44(%esp)
	fstpl	32(%esp)
	movl	$LC40, 4(%esp)
	fstpl	24(%esp)
	movl	$LC44, (%esp)
	flds	LC35
	fstpl	16(%esp)
	fldz
	fstpl	8(%esp)
LEHB24:
	call	_printf
LEHE24:
	fldz
	xorl	%ebp, %ebp
	fstps	108(%esp)
	movss	108(%esp), %xmm7
	flds	LC34
	fstps	136(%esp)
	movss	%xmm7, 124(%esp)
	movss	%xmm7, 128(%esp)
	movss	%xmm7, 104(%esp)
	movss	%xmm7, 112(%esp)
	movl	$0, 132(%esp)
	movl	$0, 120(%esp)
	.p2align 4,,7
L324:
	fld1
	xorl	%esi, %esi
	fstps	96(%esp)
	flds	LC38
	fstps	116(%esp)
	jmp	L325
	.p2align 4,,7
L754:
	addl	$1, %ebp
L335:
	flds	112(%esp)
	flds	100(%esp)
	fadd	%st, %st(1)
	fxch	%st(1)
	fstps	112(%esp)
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	jbe	L1069
	flds	LC34
	fucomi	%st(2), %st
	fstp	%st(2)
	jbe	L1070
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L340
	jmp	L338
	.p2align 4,,7
L1070:
	fstp	%st(0)
	fstp	%st(0)
L338:
	flds	LC45
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1071
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L340
	jmp	L341
	.p2align 4,,7
L1071:
	fstp	%st(0)
L341:
	flds	LC38
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1072
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L340
	jmp	L343
	.p2align 4,,7
L1072:
	fstp	%st(0)
L343:
	fld1
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	ja	L1017
	fstp	%st(0)
L345:
	flds	LC46
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1073
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L340
	jmp	L347
	.p2align 4,,7
L1073:
	fstp	%st(0)
L347:
	flds	LC42
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1074
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L340
	jmp	L349
	.p2align 4,,7
L1074:
	fstp	%st(0)
L349:
	flds	LC36
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1075
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L340
	jmp	L351
	.p2align 4,,7
L1075:
	fstp	%st(0)
L351:
	flds	LC35
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L953
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L340
	movss	96(%esp), %xmm3
	movss	108(%esp), %xmm4
	movss	100(%esp), %xmm7
	movss	%xmm3, 124(%esp)
	movss	%xmm4, 128(%esp)
	movss	%xmm7, 104(%esp)
	jmp	L336
	.p2align 4,,7
L1069:
	fstp	%st(0)
	fstp	%st(0)
L336:
	flds	LC36
	flds	96(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L356
L1020:
	addl	$1, %esi
	movl	$274877907, %eax
	imull	%esi
	movl	%esi, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %esi
	jne	L357
	flds	116(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	116(%esp)
L357:
	flds	96(%esp)
	fadds	116(%esp)
	flds	LC36
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	96(%esp)
L325:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L1018
	movss	96(%esp), %xmm0
	movss	108(%esp), %xmm1
	movl	%ebx, (%esp)
	movss	%xmm0, 8(%esp)
	movss	%xmm1, 4(%esp)
LEHB25:
	call	*156(%esp)
LEHE25:
	movl	168(%esp), %eax
	fstps	100(%esp)
	testl	%eax, %eax
	je	L1019
	movss	96(%esp), %xmm2
	movss	108(%esp), %xmm3
	movl	%edi, (%esp)
	movss	%xmm2, 8(%esp)
	movss	%xmm3, 4(%esp)
LEHB26:
	call	*172(%esp)
LEHE26:
	flds	100(%esp)
	fsubrp	%st, %st(1)
	fabs
	fsts	100(%esp)
	flds	LC34
	fucomip	%st(1), %st
	fstp	%st(0)
	ja	L754
	addl	$1, 120(%esp)
	jmp	L335
	.p2align 4,,7
L1017:
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jb	L345
	.p2align 4,,7
L340:
	flds	96(%esp)
	fstpl	20(%esp)
	movl	$LC47, (%esp)
	flds	108(%esp)
	fstpl	12(%esp)
	flds	100(%esp)
	fstpl	4(%esp)
LEHB27:
	call	_printf
LEHE27:
	movss	96(%esp), %xmm6
	movss	108(%esp), %xmm7
	movss	100(%esp), %xmm2
	flds	LC36
	flds	96(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	movss	%xmm6, 124(%esp)
	movss	%xmm7, 128(%esp)
	movss	%xmm2, 104(%esp)
	jb	L1020
L356:
	flds	LC35
	flds	108(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L360
	addl	$1, 132(%esp)
	movl	$274877907, %eax
	movl	132(%esp), %ecx
	imull	%ecx
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %ecx
	jne	L361
	flds	136(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	136(%esp)
L361:
	flds	108(%esp)
	fadds	136(%esp)
	flds	LC35
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	108(%esp)
	jmp	L324
	.p2align 4,,7
L953:
	fstp	%st(0)
	movss	96(%esp), %xmm0
	movss	108(%esp), %xmm7
	movss	100(%esp), %xmm1
	movss	%xmm0, 124(%esp)
	movss	%xmm7, 128(%esp)
	movss	%xmm1, 104(%esp)
	jmp	L336
L360:
	movl	120(%esp), %eax
	movl	$LC40, 4(%esp)
	movl	$LC48, (%esp)
	addl	%eax, %ebp
	movl	%ebp, 140(%esp)
	fildl	140(%esp)
	flds	124(%esp)
	fstpl	48(%esp)
	movl	%eax, 140(%esp)
	flds	128(%esp)
	fstpl	40(%esp)
	movl	%ebp, 12(%esp)
	flds	104(%esp)
	fstpl	32(%esp)
	movl	%eax, 8(%esp)
	flds	112(%esp)
	fdiv	%st(1), %st
	fstpl	24(%esp)
	fildl	140(%esp)
	fdivp	%st, %st(1)
	fmuls	LC42
	fstpl	16(%esp)
LEHB28:
	call	_printf
LEHE28:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L366
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
L366:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L367
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L367:
	movl	$LC8, (%esp)
	movl	$__Z22testOpt04_Type3_After2ff, 160(%esp)
	movl	$__ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 168(%esp)
	movl	$__Z22testOpt04_Type3_Beforeff, 144(%esp)
	movl	$__ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff, 156(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 152(%esp)
LEHB29:
	call	_puts
LEHE29:
	flds	LC34
	fstl	80(%esp)
	movl	$1000, 76(%esp)
	flds	LC39
	fstl	68(%esp)
	movl	$1000, 40(%esp)
	flds	LC38
	fstpl	60(%esp)
	flds	LC36
	fstpl	52(%esp)
	fld1
	fstpl	44(%esp)
	fstpl	32(%esp)
	movl	$LC49, 4(%esp)
	fstpl	24(%esp)
	movl	$LC44, (%esp)
	flds	LC35
	fstpl	16(%esp)
	fldz
	fstpl	8(%esp)
LEHB30:
	call	_printf
LEHE30:
	fldz
	xorl	%ebp, %ebp
	fstps	108(%esp)
	movss	108(%esp), %xmm1
	flds	LC34
	fstps	136(%esp)
	movss	%xmm1, 124(%esp)
	movss	%xmm1, 128(%esp)
	movss	%xmm1, 104(%esp)
	movss	%xmm1, 112(%esp)
	movl	$0, 132(%esp)
	movl	$0, 120(%esp)
	.p2align 4,,7
L371:
	fld1
	xorl	%esi, %esi
	fstps	96(%esp)
	flds	LC38
	fstps	116(%esp)
	jmp	L372
	.p2align 4,,7
L764:
	addl	$1, %ebp
L382:
	flds	112(%esp)
	flds	100(%esp)
	fadd	%st, %st(1)
	fxch	%st(1)
	fstps	112(%esp)
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	jbe	L1076
	flds	LC34
	fucomi	%st(2), %st
	fstp	%st(2)
	jbe	L1077
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L387
	jmp	L385
	.p2align 4,,7
L1077:
	fstp	%st(0)
	fstp	%st(0)
L385:
	flds	LC45
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1078
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L387
	jmp	L388
	.p2align 4,,7
L1078:
	fstp	%st(0)
L388:
	flds	LC38
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1079
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L387
	jmp	L390
	.p2align 4,,7
L1079:
	fstp	%st(0)
L390:
	fld1
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	ja	L1021
	fstp	%st(0)
L392:
	flds	LC46
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1080
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L387
	jmp	L394
	.p2align 4,,7
L1080:
	fstp	%st(0)
L394:
	flds	LC42
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1081
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L387
	jmp	L396
	.p2align 4,,7
L1081:
	fstp	%st(0)
L396:
	flds	LC36
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1082
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L387
	jmp	L398
	.p2align 4,,7
L1082:
	fstp	%st(0)
L398:
	flds	LC35
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L960
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L387
	movss	96(%esp), %xmm1
	movss	108(%esp), %xmm5
	movss	100(%esp), %xmm6
	movss	%xmm1, 124(%esp)
	movss	%xmm5, 128(%esp)
	movss	%xmm6, 104(%esp)
	jmp	L383
	.p2align 4,,7
L1076:
	fstp	%st(0)
	fstp	%st(0)
L383:
	flds	LC36
	flds	96(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L403
L1024:
	addl	$1, %esi
	movl	$274877907, %eax
	imull	%esi
	movl	%esi, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %esi
	jne	L404
	flds	116(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	116(%esp)
L404:
	flds	96(%esp)
	fadds	116(%esp)
	flds	LC36
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	96(%esp)
L372:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L1022
	movss	96(%esp), %xmm4
	movss	108(%esp), %xmm5
	movl	%ebx, (%esp)
	movss	%xmm4, 8(%esp)
	movss	%xmm5, 4(%esp)
LEHB31:
	call	*156(%esp)
LEHE31:
	movl	168(%esp), %eax
	fstps	100(%esp)
	testl	%eax, %eax
	je	L1023
	movss	96(%esp), %xmm6
	movss	108(%esp), %xmm7
	movl	%edi, (%esp)
	movss	%xmm6, 8(%esp)
	movss	%xmm7, 4(%esp)
LEHB32:
	call	*172(%esp)
LEHE32:
	flds	100(%esp)
	fsubrp	%st, %st(1)
	fabs
	fsts	100(%esp)
	flds	LC34
	fucomip	%st(1), %st
	fstp	%st(0)
	ja	L764
	addl	$1, 120(%esp)
	jmp	L382
	.p2align 4,,7
L1021:
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jb	L392
	.p2align 4,,7
L387:
	flds	96(%esp)
	fstpl	20(%esp)
	movl	$LC47, (%esp)
	flds	108(%esp)
	fstpl	12(%esp)
	flds	100(%esp)
	fstpl	4(%esp)
LEHB33:
	call	_printf
LEHE33:
	movss	96(%esp), %xmm3
	movss	108(%esp), %xmm0
	movss	100(%esp), %xmm4
	flds	LC36
	flds	96(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	movss	%xmm3, 124(%esp)
	movss	%xmm0, 128(%esp)
	movss	%xmm4, 104(%esp)
	jb	L1024
L403:
	flds	LC35
	flds	108(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L407
	addl	$1, 132(%esp)
	movl	$274877907, %eax
	movl	132(%esp), %ecx
	imull	%ecx
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %ecx
	jne	L408
	flds	136(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	136(%esp)
L408:
	flds	108(%esp)
	fadds	136(%esp)
	flds	LC35
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	108(%esp)
	jmp	L371
	.p2align 4,,7
L960:
	fstp	%st(0)
	movss	96(%esp), %xmm2
	movss	108(%esp), %xmm4
	movss	100(%esp), %xmm0
	movss	%xmm2, 124(%esp)
	movss	%xmm4, 128(%esp)
	movss	%xmm0, 104(%esp)
	jmp	L383
L407:
	movl	120(%esp), %eax
	movl	$LC49, 4(%esp)
	movl	$LC48, (%esp)
	addl	%eax, %ebp
	movl	%ebp, 140(%esp)
	fildl	140(%esp)
	flds	124(%esp)
	fstpl	48(%esp)
	movl	%eax, 140(%esp)
	flds	128(%esp)
	fstpl	40(%esp)
	movl	%ebp, 12(%esp)
	flds	104(%esp)
	fstpl	32(%esp)
	movl	%eax, 8(%esp)
	flds	112(%esp)
	fdiv	%st(1), %st
	fstpl	24(%esp)
	fildl	140(%esp)
	fdivp	%st, %st(1)
	fmuls	LC42
	fstpl	16(%esp)
LEHB34:
	call	_printf
LEHE34:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L413
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
L413:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L414
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L414:
	movl	$LC8, (%esp)
	movl	$__Z22testOpt04_Type3_After3ff, 160(%esp)
	movl	$__ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 168(%esp)
	movl	$__Z22testOpt04_Type3_Beforeff, 144(%esp)
	movl	$__ZNSt17_Function_handlerIFfffEPS0_E9_M_invokeERKSt9_Any_dataff, 156(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFfffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 152(%esp)
LEHB35:
	call	_puts
LEHE35:
	flds	LC34
	fstl	80(%esp)
	movl	$1000, 76(%esp)
	flds	LC39
	fstl	68(%esp)
	movl	$1000, 40(%esp)
	flds	LC38
	fstpl	60(%esp)
	flds	LC36
	fstpl	52(%esp)
	fld1
	fstpl	44(%esp)
	fstpl	32(%esp)
	movl	$LC50, 4(%esp)
	fstpl	24(%esp)
	movl	$LC44, (%esp)
	flds	LC35
	fstpl	16(%esp)
	fldz
	fstpl	8(%esp)
LEHB36:
	call	_printf
LEHE36:
	fldz
	xorl	%ebp, %ebp
	fstps	108(%esp)
	movss	108(%esp), %xmm3
	flds	LC34
	fstps	136(%esp)
	movss	%xmm3, 124(%esp)
	movss	%xmm3, 128(%esp)
	movss	%xmm3, 104(%esp)
	movss	%xmm3, 112(%esp)
	movl	$0, 132(%esp)
	movl	$0, 120(%esp)
	.p2align 4,,7
L418:
	fld1
	xorl	%esi, %esi
	fstps	96(%esp)
	flds	LC38
	fstps	116(%esp)
	jmp	L419
	.p2align 4,,7
L774:
	addl	$1, %ebp
L429:
	flds	112(%esp)
	flds	100(%esp)
	fadd	%st, %st(1)
	fxch	%st(1)
	fstps	112(%esp)
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	jbe	L1083
	flds	LC34
	fucomi	%st(2), %st
	fstp	%st(2)
	jbe	L1084
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L434
	jmp	L432
	.p2align 4,,7
L1084:
	fstp	%st(0)
	fstp	%st(0)
L432:
	flds	LC45
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1085
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L434
	jmp	L435
	.p2align 4,,7
L1085:
	fstp	%st(0)
L435:
	flds	LC38
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1086
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L434
	jmp	L437
	.p2align 4,,7
L1086:
	fstp	%st(0)
L437:
	fld1
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	ja	L1025
	fstp	%st(0)
L439:
	flds	LC46
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1087
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L434
	jmp	L441
	.p2align 4,,7
L1087:
	fstp	%st(0)
L441:
	flds	LC42
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1088
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L434
	jmp	L443
	.p2align 4,,7
L1088:
	fstp	%st(0)
L443:
	flds	LC36
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1089
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L434
	jmp	L445
	.p2align 4,,7
L1089:
	fstp	%st(0)
L445:
	flds	LC35
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L967
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L434
	movss	96(%esp), %xmm2
	movss	108(%esp), %xmm1
	movss	100(%esp), %xmm3
	movss	%xmm2, 124(%esp)
	movss	%xmm1, 128(%esp)
	movss	%xmm3, 104(%esp)
	jmp	L430
	.p2align 4,,7
L1083:
	fstp	%st(0)
	fstp	%st(0)
L430:
	flds	LC36
	flds	96(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L450
L1028:
	addl	$1, %esi
	movl	$274877907, %eax
	imull	%esi
	movl	%esi, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %esi
	jne	L451
	flds	116(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	116(%esp)
L451:
	flds	96(%esp)
	fadds	116(%esp)
	flds	LC36
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	96(%esp)
L419:
	movl	152(%esp), %ecx
	testl	%ecx, %ecx
	je	L1026
	movss	96(%esp), %xmm0
	movss	108(%esp), %xmm1
	movl	%ebx, (%esp)
	movss	%xmm0, 8(%esp)
	movss	%xmm1, 4(%esp)
LEHB37:
	call	*156(%esp)
LEHE37:
	movl	168(%esp), %edx
	fstps	100(%esp)
	testl	%edx, %edx
	je	L1027
	movss	96(%esp), %xmm2
	movss	108(%esp), %xmm3
	movl	%edi, (%esp)
	movss	%xmm2, 8(%esp)
	movss	%xmm3, 4(%esp)
LEHB38:
	call	*172(%esp)
LEHE38:
	flds	100(%esp)
	fsubrp	%st, %st(1)
	fabs
	fsts	100(%esp)
	flds	LC34
	fucomip	%st(1), %st
	fstp	%st(0)
	ja	L774
	addl	$1, 120(%esp)
	jmp	L429
	.p2align 4,,7
L1025:
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jb	L439
	.p2align 4,,7
L434:
	flds	96(%esp)
	fstpl	20(%esp)
	movl	$LC47, (%esp)
	flds	108(%esp)
	fstpl	12(%esp)
	flds	100(%esp)
	fstpl	4(%esp)
LEHB39:
	call	_printf
LEHE39:
	movss	96(%esp), %xmm5
	movss	100(%esp), %xmm6
	flds	LC36
	movss	%xmm5, 124(%esp)
	flds	96(%esp)
	movss	108(%esp), %xmm5
	fucomip	%st(1), %st
	fstp	%st(0)
	movss	%xmm6, 104(%esp)
	movss	%xmm5, 128(%esp)
	jb	L1028
L450:
	flds	LC35
	flds	108(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L454
	addl	$1, 132(%esp)
	movl	$274877907, %eax
	movl	132(%esp), %ecx
	imull	%ecx
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %ecx
	jne	L455
	flds	136(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	136(%esp)
L455:
	flds	108(%esp)
	fadds	136(%esp)
	flds	LC35
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	108(%esp)
	jmp	L418
	.p2align 4,,7
L967:
	fstp	%st(0)
	movss	96(%esp), %xmm3
	movss	108(%esp), %xmm7
	movss	100(%esp), %xmm1
	movss	%xmm3, 124(%esp)
	movss	%xmm7, 128(%esp)
	movss	%xmm1, 104(%esp)
	jmp	L430
L454:
	movl	120(%esp), %eax
	movl	$LC50, 4(%esp)
	movl	$LC48, (%esp)
	addl	%eax, %ebp
	movl	%ebp, 140(%esp)
	fildl	140(%esp)
	flds	124(%esp)
	fstpl	48(%esp)
	movl	%eax, 140(%esp)
	flds	128(%esp)
	fstpl	40(%esp)
	movl	%ebp, 12(%esp)
	flds	104(%esp)
	fstpl	32(%esp)
	movl	%eax, 8(%esp)
	flds	112(%esp)
	fdiv	%st(1), %st
	fstpl	24(%esp)
	fildl	140(%esp)
	fdivp	%st, %st(1)
	fmuls	LC42
	fstpl	16(%esp)
LEHB40:
	call	_printf
LEHE40:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L460
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
L460:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L461
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L461:
	movl	$LC8, (%esp)
	movl	$__Z22testOpt04_Type4_After1f, 160(%esp)
	movl	$__ZNSt17_Function_handlerIFffEPS0_E9_M_invokeERKSt9_Any_dataf, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 168(%esp)
	movl	$__Z22testOpt04_Type4_Beforef, 144(%esp)
	movl	$__ZNSt17_Function_handlerIFffEPS0_E9_M_invokeERKSt9_Any_dataf, 156(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 152(%esp)
LEHB41:
	call	_puts
LEHE41:
	flds	LC34
	fstl	44(%esp)
	movl	$1000, 40(%esp)
	flds	LC39
	fstpl	32(%esp)
	fstl	24(%esp)
	movl	$LC40, 4(%esp)
	flds	LC32
	fstpl	16(%esp)
	fstpl	8(%esp)
	movl	$LC51, (%esp)
LEHB42:
	call	_printf
LEHE42:
	flds	LC34
	xorl	%esi, %esi
	xorl	%ebp, %ebp
	fstps	96(%esp)
	fldz
	fstps	116(%esp)
	movss	116(%esp), %xmm3
	movss	96(%esp), %xmm1
	movl	$0, 120(%esp)
	movss	%xmm3, 104(%esp)
	movss	%xmm1, 112(%esp)
	movss	%xmm3, 108(%esp)
	.p2align 4,,7
L465:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L1029
	movss	96(%esp), %xmm2
	movl	%ebx, (%esp)
	movss	%xmm2, 4(%esp)
LEHB43:
	call	*156(%esp)
LEHE43:
	movl	168(%esp), %eax
	fstps	100(%esp)
	testl	%eax, %eax
	je	L1030
	movss	96(%esp), %xmm2
	movl	%edi, (%esp)
	movss	%xmm2, 4(%esp)
LEHB44:
	call	*172(%esp)
LEHE44:
	flds	100(%esp)
	fsubrp	%st, %st(1)
	fabs
	fsts	100(%esp)
	flds	LC34
	fucomip	%st(1), %st
	fstp	%st(0)
	jbe	L1031
	addl	$1, %ebp
L475:
	flds	108(%esp)
	flds	100(%esp)
	fadd	%st, %st(1)
	fxch	%st(1)
	fstps	108(%esp)
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	jbe	L1090
	flds	LC34
	fucomi	%st(2), %st
	fstp	%st(2)
	jbe	L1091
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L480
	jmp	L478
	.p2align 4,,7
L1091:
	fstp	%st(0)
	fstp	%st(0)
L478:
	flds	LC45
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1092
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L480
	jmp	L481
	.p2align 4,,7
L1092:
	fstp	%st(0)
L481:
	flds	LC38
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1093
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jb	L483
	.p2align 4,,7
L480:
	flds	96(%esp)
	fstpl	12(%esp)
	movl	$LC52, (%esp)
	flds	100(%esp)
	fstpl	4(%esp)
LEHB45:
	call	_printf
LEHE45:
	movss	96(%esp), %xmm2
	movss	100(%esp), %xmm3
	movss	%xmm2, 116(%esp)
	movss	%xmm3, 104(%esp)
	jmp	L476
	.p2align 4,,7
L1090:
	fstp	%st(0)
	fstp	%st(0)
L476:
	flds	LC32
	flds	96(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L490
L1033:
	addl	$1, %esi
	movl	$274877907, %eax
	imull	%esi
	movl	%esi, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %esi
	jne	L491
	flds	112(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	112(%esp)
L491:
	flds	96(%esp)
	fadds	112(%esp)
	flds	LC32
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	96(%esp)
	jmp	L465
L1093:
	fstp	%st(0)
L483:
	fld1
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	ja	L1032
	fstp	%st(0)
L485:
	flds	LC46
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L974
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L480
	movss	96(%esp), %xmm1
	movss	100(%esp), %xmm2
	flds	LC32
	flds	96(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	movss	%xmm1, 116(%esp)
	movss	%xmm2, 104(%esp)
	jb	L1033
L490:
	movl	120(%esp), %eax
	movl	$LC40, 4(%esp)
	movl	$LC53, (%esp)
	addl	%eax, %ebp
	movl	%ebp, 140(%esp)
	fildl	140(%esp)
	flds	116(%esp)
	fstpl	40(%esp)
	movl	%eax, 140(%esp)
	flds	104(%esp)
	fstpl	32(%esp)
	movl	%ebp, 12(%esp)
	flds	108(%esp)
	fdiv	%st(1), %st
	movl	%eax, 8(%esp)
	fstpl	24(%esp)
	fildl	140(%esp)
	fdivp	%st, %st(1)
	fmuls	LC42
	fstpl	16(%esp)
LEHB46:
	call	_printf
LEHE46:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L496
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
L496:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L497
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L497:
	movl	$LC8, (%esp)
	movl	$__Z22testOpt04_Type4_After2f, 160(%esp)
	movl	$__ZNSt17_Function_handlerIFffEPS0_E9_M_invokeERKSt9_Any_dataf, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 168(%esp)
	movl	$__Z22testOpt04_Type4_Beforef, 144(%esp)
	movl	$__ZNSt17_Function_handlerIFffEPS0_E9_M_invokeERKSt9_Any_dataf, 156(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 152(%esp)
LEHB47:
	call	_puts
LEHE47:
	flds	LC34
	fstl	44(%esp)
	movl	$1000, 40(%esp)
	flds	LC39
	fstpl	32(%esp)
	fstl	24(%esp)
	movl	$LC49, 4(%esp)
	flds	LC32
	fstpl	16(%esp)
	fstpl	8(%esp)
	movl	$LC51, (%esp)
LEHB48:
	call	_printf
LEHE48:
	flds	LC34
	xorl	%esi, %esi
	xorl	%ebp, %ebp
	fstps	96(%esp)
	fldz
	fstps	116(%esp)
	movss	116(%esp), %xmm6
	movss	96(%esp), %xmm5
	movl	$0, 120(%esp)
	movss	%xmm6, 104(%esp)
	movss	%xmm5, 112(%esp)
	movss	%xmm6, 108(%esp)
	.p2align 4,,7
L501:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L1034
	movss	96(%esp), %xmm4
	movl	%ebx, (%esp)
	movss	%xmm4, 4(%esp)
LEHB49:
	call	*156(%esp)
LEHE49:
	movl	168(%esp), %eax
	fstps	100(%esp)
	testl	%eax, %eax
	je	L1035
	movss	96(%esp), %xmm0
	movl	%edi, (%esp)
	movss	%xmm0, 4(%esp)
LEHB50:
	call	*172(%esp)
LEHE50:
	flds	100(%esp)
	fsubrp	%st, %st(1)
	fabs
	fsts	100(%esp)
	flds	LC34
	fucomip	%st(1), %st
	fstp	%st(0)
	jbe	L1036
	addl	$1, %ebp
L511:
	flds	108(%esp)
	flds	100(%esp)
	fadd	%st, %st(1)
	fxch	%st(1)
	fstps	108(%esp)
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	jbe	L1094
	flds	LC34
	fucomi	%st(2), %st
	fstp	%st(2)
	jbe	L1095
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L516
	jmp	L514
	.p2align 4,,7
L1095:
	fstp	%st(0)
	fstp	%st(0)
L514:
	flds	LC45
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1096
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L516
	jmp	L517
	.p2align 4,,7
L1096:
	fstp	%st(0)
L517:
	flds	LC38
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1097
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jb	L519
	.p2align 4,,7
L516:
	flds	96(%esp)
	fstpl	12(%esp)
	movl	$LC52, (%esp)
	flds	100(%esp)
	fstpl	4(%esp)
LEHB51:
	call	_printf
LEHE51:
	movss	96(%esp), %xmm4
	movss	100(%esp), %xmm0
	movss	%xmm4, 116(%esp)
	movss	%xmm0, 104(%esp)
	jmp	L512
	.p2align 4,,7
L1094:
	fstp	%st(0)
	fstp	%st(0)
L512:
	flds	LC32
	flds	96(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L526
L1038:
	addl	$1, %esi
	movl	$274877907, %eax
	imull	%esi
	movl	%esi, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %esi
	jne	L527
	flds	112(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	112(%esp)
L527:
	flds	96(%esp)
	fadds	112(%esp)
	flds	LC32
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	96(%esp)
	jmp	L501
	.p2align 4,,7
L1031:
	addl	$1, 120(%esp)
	jmp	L475
L1097:
	fstp	%st(0)
L519:
	fld1
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	ja	L1037
	fstp	%st(0)
L521:
	flds	LC46
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L981
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L516
	movss	96(%esp), %xmm1
	movss	100(%esp), %xmm2
	flds	LC32
	flds	96(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	movss	%xmm1, 116(%esp)
	movss	%xmm2, 104(%esp)
	jb	L1038
L526:
	movl	120(%esp), %eax
	movl	$LC49, 4(%esp)
	movl	$LC53, (%esp)
	addl	%eax, %ebp
	movl	%ebp, 140(%esp)
	fildl	140(%esp)
	flds	116(%esp)
	fstpl	40(%esp)
	movl	%eax, 140(%esp)
	flds	104(%esp)
	fstpl	32(%esp)
	movl	%ebp, 12(%esp)
	flds	108(%esp)
	fdiv	%st(1), %st
	movl	%eax, 8(%esp)
	fstpl	24(%esp)
	fildl	140(%esp)
	fdivp	%st, %st(1)
	fmuls	LC42
	fstpl	16(%esp)
LEHB52:
	call	_printf
LEHE52:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L532
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
L532:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L533
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L533:
	movl	$LC8, (%esp)
	movl	$__Z22testOpt04_Type4_After3f, 160(%esp)
	movl	$__ZNSt17_Function_handlerIFffEPS0_E9_M_invokeERKSt9_Any_dataf, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 168(%esp)
	movl	$__Z22testOpt04_Type4_Beforef, 144(%esp)
	movl	$__ZNSt17_Function_handlerIFffEPS0_E9_M_invokeERKSt9_Any_dataf, 156(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIPFffEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 152(%esp)
LEHB53:
	call	_puts
LEHE53:
	flds	LC34
	fstl	44(%esp)
	movl	$1000, 40(%esp)
	flds	LC39
	fstpl	32(%esp)
	fstl	24(%esp)
	movl	$LC50, 4(%esp)
	flds	LC32
	fstpl	16(%esp)
	fstpl	8(%esp)
	movl	$LC51, (%esp)
LEHB54:
	call	_printf
LEHE54:
	flds	LC34
	xorl	%esi, %esi
	xorl	%ebp, %ebp
	fstps	96(%esp)
	fldz
	fstps	116(%esp)
	movss	116(%esp), %xmm1
	movss	96(%esp), %xmm0
	movl	$0, 120(%esp)
	movss	%xmm1, 104(%esp)
	movss	%xmm0, 112(%esp)
	movss	%xmm1, 108(%esp)
	.p2align 4,,7
L537:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L1039
	movss	96(%esp), %xmm7
	movl	%ebx, (%esp)
	movss	%xmm7, 4(%esp)
LEHB55:
	call	*156(%esp)
LEHE55:
	movl	168(%esp), %eax
	fstps	100(%esp)
	testl	%eax, %eax
	je	L1040
	movss	96(%esp), %xmm1
	movl	%edi, (%esp)
	movss	%xmm1, 4(%esp)
LEHB56:
	call	*172(%esp)
LEHE56:
	flds	100(%esp)
	fsubrp	%st, %st(1)
	fabs
	fsts	100(%esp)
	flds	LC34
	fucomip	%st(1), %st
	fstp	%st(0)
	jbe	L1041
	addl	$1, %ebp
L547:
	flds	108(%esp)
	flds	100(%esp)
	fadd	%st, %st(1)
	fxch	%st(1)
	fstps	108(%esp)
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	jbe	L1098
	flds	LC34
	fucomi	%st(2), %st
	fstp	%st(2)
	jbe	L1099
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L552
	jmp	L550
	.p2align 4,,7
L1099:
	fstp	%st(0)
	fstp	%st(0)
L550:
	flds	LC45
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1100
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L552
	jmp	L553
	.p2align 4,,7
L1100:
	fstp	%st(0)
L553:
	flds	LC38
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L1101
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jb	L555
	.p2align 4,,7
L552:
	flds	96(%esp)
	fstpl	12(%esp)
	movl	$LC52, (%esp)
	flds	100(%esp)
	fstpl	4(%esp)
LEHB57:
	call	_printf
LEHE57:
	movss	96(%esp), %xmm7
	movss	100(%esp), %xmm1
	movss	%xmm7, 116(%esp)
	movss	%xmm1, 104(%esp)
	jmp	L548
	.p2align 4,,7
L1098:
	fstp	%st(0)
	fstp	%st(0)
L548:
	flds	LC32
	flds	96(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L562
L1043:
	addl	$1, %esi
	movl	$274877907, %eax
	imull	%esi
	movl	%esi, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %esi
	jne	L563
	flds	112(%esp)
	fld	%st(0)
	faddp	%st, %st(1)
	fstps	112(%esp)
L563:
	flds	96(%esp)
	fadds	112(%esp)
	flds	LC32
	fxch	%st(1)
	fucomi	%st(1), %st
	fcmovnbe	%st(1), %st
	fstp	%st(1)
	fstps	96(%esp)
	jmp	L537
	.p2align 4,,7
L1036:
	addl	$1, 120(%esp)
	jmp	L511
L1101:
	fstp	%st(0)
L555:
	fld1
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	ja	L1042
	fstp	%st(0)
L557:
	flds	LC46
	flds	104(%esp)
	fxch	%st(1)
	fucomi	%st(1), %st
	fstp	%st(1)
	jbe	L988
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L552
	movss	96(%esp), %xmm3
	movss	100(%esp), %xmm4
	flds	LC32
	flds	96(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	movss	%xmm3, 116(%esp)
	movss	%xmm4, 104(%esp)
	jb	L1043
L562:
	movl	120(%esp), %eax
	movl	$LC50, 4(%esp)
	movl	$LC53, (%esp)
	addl	%eax, %ebp
	movl	%ebp, 140(%esp)
	fildl	140(%esp)
	flds	116(%esp)
	fstpl	40(%esp)
	movl	%eax, 140(%esp)
	flds	104(%esp)
	fstpl	32(%esp)
	movl	%ebp, 12(%esp)
	flds	108(%esp)
	fdiv	%st(1), %st
	movl	%eax, 8(%esp)
	fstpl	24(%esp)
	fildl	140(%esp)
	fdivp	%st, %st(1)
	fmuls	LC42
	fstpl	16(%esp)
LEHB58:
	call	_printf
LEHE58:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L568
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
L568:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L156
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L156:
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
L1041:
	.cfi_restore_state
	addl	$1, 120(%esp)
	jmp	L547
L988:
	fstp	%st(0)
	movss	96(%esp), %xmm7
	movss	100(%esp), %xmm0
	movss	%xmm7, 116(%esp)
	movss	%xmm0, 104(%esp)
	jmp	L548
L974:
	fstp	%st(0)
	movss	96(%esp), %xmm3
	movss	100(%esp), %xmm4
	movss	%xmm3, 116(%esp)
	movss	%xmm4, 104(%esp)
	jmp	L476
L981:
	fstp	%st(0)
	movss	96(%esp), %xmm5
	movss	100(%esp), %xmm6
	movss	%xmm5, 116(%esp)
	movss	%xmm6, 104(%esp)
	jmp	L512
L1032:
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L480
	jmp	L485
L1042:
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L552
	.p2align 4,,5
	jmp	L557
L1037:
	flds	100(%esp)
	fucomip	%st(1), %st
	fstp	%st(0)
	jae	L516
	.p2align 4,,5
	jmp	L521
L1011:
	.p2align 4,,5
LEHB59:
	call	__ZSt25__throw_bad_function_callv
LEHE59:
L1006:
	.p2align 4,,8
LEHB60:
	call	__ZSt25__throw_bad_function_callv
LEHE60:
L1007:
	.p2align 4,,5
LEHB61:
	call	__ZSt25__throw_bad_function_callv
LEHE61:
L1010:
	.p2align 4,,5
LEHB62:
	call	__ZSt25__throw_bad_function_callv
LEHE62:
L669:
	movl	%eax, %esi
L577:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L599
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L599:
	movl	%esi, (%esp)
LEHB63:
	call	__Unwind_Resume
LEHE63:
L664:
L994:
	movl	%eax, %esi
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L574
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
L574:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L599
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
	jmp	L599
L662:
	movl	%eax, %esi
	jmp	L574
L671:
L995:
	movl	%eax, %esi
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L577
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
	jmp	L577
	.p2align 4,,7
L1022:
LEHB64:
	call	__ZSt25__throw_bad_function_callv
LEHE64:
L690:
	movl	%eax, %esi
L586:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L599
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
	jmp	L599
	.p2align 4,,7
L1014:
LEHB65:
	call	__ZSt25__throw_bad_function_callv
LEHE65:
L676:
	movl	%eax, %esi
L580:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L599
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
	jmp	L599
	.p2align 4,,7
L1019:
LEHB66:
	call	__ZSt25__throw_bad_function_callv
LEHE66:
L685:
L997:
	movl	%eax, %esi
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L583
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
L583:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L599
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
	jmp	L599
	.p2align 4,,7
L1018:
LEHB67:
	call	__ZSt25__throw_bad_function_callv
LEHE67:
L683:
	movl	%eax, %esi
	.p2align 4,,6
	jmp	L583
	.p2align 4,,7
L1023:
LEHB68:
	call	__ZSt25__throw_bad_function_callv
LEHE68:
L692:
L998:
	movl	%eax, %esi
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L586
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
	jmp	L586
	.p2align 4,,7
L1015:
LEHB69:
	call	__ZSt25__throw_bad_function_callv
LEHE69:
L678:
L996:
	movl	%eax, %esi
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L580
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
	jmp	L580
	.p2align 4,,7
L1026:
LEHB70:
	call	__ZSt25__throw_bad_function_callv
LEHE70:
L697:
	movl	%eax, %esi
L589:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L599
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
	jmp	L599
	.p2align 4,,7
L1027:
LEHB71:
	call	__ZSt25__throw_bad_function_callv
LEHE71:
L699:
L999:
	movl	%eax, %esi
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L589
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
	jmp	L589
L661:
	jmp	L994
L677:
	.p2align 4,,11
	jmp	L996
L681:
	.p2align 4,,11
	jmp	L997
L647:
	.p2align 4,,11
	jmp	L996
L680:
	.p2align 4,,11
	jmp	L996
L679:
	.p2align 4,,11
	jmp	L996
L650:
	.p2align 4,,11
	jmp	L999
L701:
	.p2align 4,,11
	jmp	L999
L707:
L1000:
	movl	%eax, %esi
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L592
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
L592:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L599
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
	jmp	L599
L1030:
LEHB72:
	call	__ZSt25__throw_bad_function_callv
LEHE72:
L719:
L1002:
	movl	%eax, %esi
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L598
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
L598:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L599
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
	jmp	L599
L706:
	jmp	L1000
L1029:
	.p2align 4,,11
LEHB73:
	call	__ZSt25__throw_bad_function_callv
LEHE73:
L659:
L993:
	movl	%eax, %ebx
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L571
	leal	144(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L571:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L572
	leal	160(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L572:
	movl	%ebx, (%esp)
LEHB74:
	call	__Unwind_Resume
LEHE74:
L704:
	movl	%eax, %esi
	jmp	L592
L1004:
LEHB75:
	call	__ZSt25__throw_bad_function_callv
LEHE75:
L657:
	.p2align 4,,6
	jmp	L993
L658:
	.p2align 4,,8
	jmp	L993
L1003:
	.p2align 4,,11
LEHB76:
	call	__ZSt25__throw_bad_function_callv
LEHE76:
L655:
	.p2align 4,,8
	jmp	L993
L656:
	movl	%eax, %ebx
	.p2align 4,,6
	jmp	L571
L654:
	.p2align 4,,9
	jmp	L993
L698:
	.p2align 4,,9
	jmp	L999
L693:
	.p2align 4,,11
	jmp	L998
L649:
	.p2align 4,,11
	jmp	L998
L694:
	.p2align 4,,11
	jmp	L998
L668:
	.p2align 4,,11
	jmp	L995
L663:
	.p2align 4,,11
	jmp	L994
L721:
	.p2align 4,,11
	jmp	L1002
L1040:
	.p2align 4,,11
LEHB77:
	call	__ZSt25__throw_bad_function_callv
LEHE77:
L651:
	.p2align 4,,8
	jmp	L1000
L720:
	.p2align 4,,8
	jmp	L1002
L653:
	.p2align 4,,11
	jmp	L1002
L648:
	.p2align 4,,11
	jmp	L997
L652:
L1001:
	movl	%eax, %esi
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L595
	movl	$3, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebx, (%esp)
	call	*%eax
L595:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L599
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
	jmp	L599
L660:
	jmp	L994
L644:
	.p2align 4,,11
	jmp	L993
L691:
	.p2align 4,,11
	jmp	L998
L700:
	.p2align 4,,11
	jmp	L999
L705:
	.p2align 4,,11
	jmp	L1000
L1039:
	.p2align 4,,11
LEHB78:
	call	__ZSt25__throw_bad_function_callv
LEHE78:
L717:
	.p2align 4,,8
	jmp	L1002
L718:
	movl	%eax, %esi
	.p2align 4,,6
	jmp	L598
L716:
	.p2align 4,,9
	jmp	L1002
L712:
	.p2align 4,,9
	jmp	L1001
L1034:
	.p2align 4,,11
LEHB79:
	call	__ZSt25__throw_bad_function_callv
LEHE79:
L710:
	.p2align 4,,8
	jmp	L1001
L711:
	movl	%eax, %esi
	.p2align 4,,6
	jmp	L595
L709:
	.p2align 4,,9
	jmp	L1001
L667:
	.p2align 4,,9
	jmp	L995
L645:
	.p2align 4,,11
	jmp	L994
L666:
	.p2align 4,,11
	jmp	L994
L665:
	.p2align 4,,11
	jmp	L994
L714:
	.p2align 4,,11
	jmp	L1001
L1035:
	.p2align 4,,11
LEHB80:
	call	__ZSt25__throw_bad_function_callv
LEHE80:
L715:
	.p2align 4,,8
	jmp	L1001
L713:
	.p2align 4,,8
	jmp	L1001
L670:
	.p2align 4,,11
	jmp	L995
L674:
	.p2align 4,,11
	jmp	L996
L646:
	.p2align 4,,11
	jmp	L995
L673:
	.p2align 4,,11
	jmp	L995
L672:
	.p2align 4,,11
	jmp	L995
L708:
	.p2align 4,,11
	jmp	L1000
L722:
	.p2align 4,,11
	jmp	L1002
L703:
	.p2align 4,,11
	jmp	L1000
L702:
	.p2align 4,,11
	jmp	L1000
L687:
	.p2align 4,,11
	jmp	L997
L686:
	.p2align 4,,11
	jmp	L997
L696:
	.p2align 4,,11
	jmp	L999
L695:
	.p2align 4,,11
	jmp	L999
L675:
	.p2align 4,,11
	jmp	L996
L684:
	.p2align 4,,11
	jmp	L997
L689:
	.p2align 4,,11
	jmp	L998
L688:
	.p2align 4,,11
	jmp	L998
L682:
	.p2align 4,,11
	jmp	L997
	.cfi_endproc
LFE3162:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA3162:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3162-LLSDACSB3162
LLSDACSB3162:
	.uleb128 LEHB0-LFB3162
	.uleb128 LEHE0-LEHB0
	.uleb128 L654-LFB3162
	.uleb128 0
	.uleb128 LEHB1-LFB3162
	.uleb128 LEHE1-LEHB1
	.uleb128 L655-LFB3162
	.uleb128 0
	.uleb128 LEHB2-LFB3162
	.uleb128 LEHE2-LEHB2
	.uleb128 L657-LFB3162
	.uleb128 0
	.uleb128 LEHB3-LFB3162
	.uleb128 LEHE3-LEHB3
	.uleb128 L659-LFB3162
	.uleb128 0
	.uleb128 LEHB4-LFB3162
	.uleb128 LEHE4-LEHB4
	.uleb128 L644-LFB3162
	.uleb128 0
	.uleb128 LEHB5-LFB3162
	.uleb128 LEHE5-LEHB5
	.uleb128 L660-LFB3162
	.uleb128 0
	.uleb128 LEHB6-LFB3162
	.uleb128 LEHE6-LEHB6
	.uleb128 L661-LFB3162
	.uleb128 0
	.uleb128 LEHB7-LFB3162
	.uleb128 LEHE7-LEHB7
	.uleb128 L663-LFB3162
	.uleb128 0
	.uleb128 LEHB8-LFB3162
	.uleb128 LEHE8-LEHB8
	.uleb128 L665-LFB3162
	.uleb128 0
	.uleb128 LEHB9-LFB3162
	.uleb128 LEHE9-LEHB9
	.uleb128 L666-LFB3162
	.uleb128 0
	.uleb128 LEHB10-LFB3162
	.uleb128 LEHE10-LEHB10
	.uleb128 L645-LFB3162
	.uleb128 0
	.uleb128 LEHB11-LFB3162
	.uleb128 LEHE11-LEHB11
	.uleb128 L667-LFB3162
	.uleb128 0
	.uleb128 LEHB12-LFB3162
	.uleb128 LEHE12-LEHB12
	.uleb128 L668-LFB3162
	.uleb128 0
	.uleb128 LEHB13-LFB3162
	.uleb128 LEHE13-LEHB13
	.uleb128 L670-LFB3162
	.uleb128 0
	.uleb128 LEHB14-LFB3162
	.uleb128 LEHE14-LEHB14
	.uleb128 L672-LFB3162
	.uleb128 0
	.uleb128 LEHB15-LFB3162
	.uleb128 LEHE15-LEHB15
	.uleb128 L673-LFB3162
	.uleb128 0
	.uleb128 LEHB16-LFB3162
	.uleb128 LEHE16-LEHB16
	.uleb128 L646-LFB3162
	.uleb128 0
	.uleb128 LEHB17-LFB3162
	.uleb128 LEHE17-LEHB17
	.uleb128 L674-LFB3162
	.uleb128 0
	.uleb128 LEHB18-LFB3162
	.uleb128 LEHE18-LEHB18
	.uleb128 L675-LFB3162
	.uleb128 0
	.uleb128 LEHB19-LFB3162
	.uleb128 LEHE19-LEHB19
	.uleb128 L677-LFB3162
	.uleb128 0
	.uleb128 LEHB20-LFB3162
	.uleb128 LEHE20-LEHB20
	.uleb128 L679-LFB3162
	.uleb128 0
	.uleb128 LEHB21-LFB3162
	.uleb128 LEHE21-LEHB21
	.uleb128 L680-LFB3162
	.uleb128 0
	.uleb128 LEHB22-LFB3162
	.uleb128 LEHE22-LEHB22
	.uleb128 L647-LFB3162
	.uleb128 0
	.uleb128 LEHB23-LFB3162
	.uleb128 LEHE23-LEHB23
	.uleb128 L681-LFB3162
	.uleb128 0
	.uleb128 LEHB24-LFB3162
	.uleb128 LEHE24-LEHB24
	.uleb128 L682-LFB3162
	.uleb128 0
	.uleb128 LEHB25-LFB3162
	.uleb128 LEHE25-LEHB25
	.uleb128 L684-LFB3162
	.uleb128 0
	.uleb128 LEHB26-LFB3162
	.uleb128 LEHE26-LEHB26
	.uleb128 L686-LFB3162
	.uleb128 0
	.uleb128 LEHB27-LFB3162
	.uleb128 LEHE27-LEHB27
	.uleb128 L687-LFB3162
	.uleb128 0
	.uleb128 LEHB28-LFB3162
	.uleb128 LEHE28-LEHB28
	.uleb128 L648-LFB3162
	.uleb128 0
	.uleb128 LEHB29-LFB3162
	.uleb128 LEHE29-LEHB29
	.uleb128 L688-LFB3162
	.uleb128 0
	.uleb128 LEHB30-LFB3162
	.uleb128 LEHE30-LEHB30
	.uleb128 L689-LFB3162
	.uleb128 0
	.uleb128 LEHB31-LFB3162
	.uleb128 LEHE31-LEHB31
	.uleb128 L691-LFB3162
	.uleb128 0
	.uleb128 LEHB32-LFB3162
	.uleb128 LEHE32-LEHB32
	.uleb128 L693-LFB3162
	.uleb128 0
	.uleb128 LEHB33-LFB3162
	.uleb128 LEHE33-LEHB33
	.uleb128 L694-LFB3162
	.uleb128 0
	.uleb128 LEHB34-LFB3162
	.uleb128 LEHE34-LEHB34
	.uleb128 L649-LFB3162
	.uleb128 0
	.uleb128 LEHB35-LFB3162
	.uleb128 LEHE35-LEHB35
	.uleb128 L695-LFB3162
	.uleb128 0
	.uleb128 LEHB36-LFB3162
	.uleb128 LEHE36-LEHB36
	.uleb128 L696-LFB3162
	.uleb128 0
	.uleb128 LEHB37-LFB3162
	.uleb128 LEHE37-LEHB37
	.uleb128 L698-LFB3162
	.uleb128 0
	.uleb128 LEHB38-LFB3162
	.uleb128 LEHE38-LEHB38
	.uleb128 L700-LFB3162
	.uleb128 0
	.uleb128 LEHB39-LFB3162
	.uleb128 LEHE39-LEHB39
	.uleb128 L701-LFB3162
	.uleb128 0
	.uleb128 LEHB40-LFB3162
	.uleb128 LEHE40-LEHB40
	.uleb128 L650-LFB3162
	.uleb128 0
	.uleb128 LEHB41-LFB3162
	.uleb128 LEHE41-LEHB41
	.uleb128 L702-LFB3162
	.uleb128 0
	.uleb128 LEHB42-LFB3162
	.uleb128 LEHE42-LEHB42
	.uleb128 L703-LFB3162
	.uleb128 0
	.uleb128 LEHB43-LFB3162
	.uleb128 LEHE43-LEHB43
	.uleb128 L705-LFB3162
	.uleb128 0
	.uleb128 LEHB44-LFB3162
	.uleb128 LEHE44-LEHB44
	.uleb128 L707-LFB3162
	.uleb128 0
	.uleb128 LEHB45-LFB3162
	.uleb128 LEHE45-LEHB45
	.uleb128 L708-LFB3162
	.uleb128 0
	.uleb128 LEHB46-LFB3162
	.uleb128 LEHE46-LEHB46
	.uleb128 L651-LFB3162
	.uleb128 0
	.uleb128 LEHB47-LFB3162
	.uleb128 LEHE47-LEHB47
	.uleb128 L709-LFB3162
	.uleb128 0
	.uleb128 LEHB48-LFB3162
	.uleb128 LEHE48-LEHB48
	.uleb128 L710-LFB3162
	.uleb128 0
	.uleb128 LEHB49-LFB3162
	.uleb128 LEHE49-LEHB49
	.uleb128 L712-LFB3162
	.uleb128 0
	.uleb128 LEHB50-LFB3162
	.uleb128 LEHE50-LEHB50
	.uleb128 L714-LFB3162
	.uleb128 0
	.uleb128 LEHB51-LFB3162
	.uleb128 LEHE51-LEHB51
	.uleb128 L715-LFB3162
	.uleb128 0
	.uleb128 LEHB52-LFB3162
	.uleb128 LEHE52-LEHB52
	.uleb128 L652-LFB3162
	.uleb128 0
	.uleb128 LEHB53-LFB3162
	.uleb128 LEHE53-LEHB53
	.uleb128 L716-LFB3162
	.uleb128 0
	.uleb128 LEHB54-LFB3162
	.uleb128 LEHE54-LEHB54
	.uleb128 L717-LFB3162
	.uleb128 0
	.uleb128 LEHB55-LFB3162
	.uleb128 LEHE55-LEHB55
	.uleb128 L719-LFB3162
	.uleb128 0
	.uleb128 LEHB56-LFB3162
	.uleb128 LEHE56-LEHB56
	.uleb128 L721-LFB3162
	.uleb128 0
	.uleb128 LEHB57-LFB3162
	.uleb128 LEHE57-LEHB57
	.uleb128 L722-LFB3162
	.uleb128 0
	.uleb128 LEHB58-LFB3162
	.uleb128 LEHE58-LEHB58
	.uleb128 L653-LFB3162
	.uleb128 0
	.uleb128 LEHB59-LFB3162
	.uleb128 LEHE59-LEHB59
	.uleb128 L671-LFB3162
	.uleb128 0
	.uleb128 LEHB60-LFB3162
	.uleb128 LEHE60-LEHB60
	.uleb128 L662-LFB3162
	.uleb128 0
	.uleb128 LEHB61-LFB3162
	.uleb128 LEHE61-LEHB61
	.uleb128 L664-LFB3162
	.uleb128 0
	.uleb128 LEHB62-LFB3162
	.uleb128 LEHE62-LEHB62
	.uleb128 L669-LFB3162
	.uleb128 0
	.uleb128 LEHB63-LFB3162
	.uleb128 LEHE63-LEHB63
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB64-LFB3162
	.uleb128 LEHE64-LEHB64
	.uleb128 L690-LFB3162
	.uleb128 0
	.uleb128 LEHB65-LFB3162
	.uleb128 LEHE65-LEHB65
	.uleb128 L676-LFB3162
	.uleb128 0
	.uleb128 LEHB66-LFB3162
	.uleb128 LEHE66-LEHB66
	.uleb128 L685-LFB3162
	.uleb128 0
	.uleb128 LEHB67-LFB3162
	.uleb128 LEHE67-LEHB67
	.uleb128 L683-LFB3162
	.uleb128 0
	.uleb128 LEHB68-LFB3162
	.uleb128 LEHE68-LEHB68
	.uleb128 L692-LFB3162
	.uleb128 0
	.uleb128 LEHB69-LFB3162
	.uleb128 LEHE69-LEHB69
	.uleb128 L678-LFB3162
	.uleb128 0
	.uleb128 LEHB70-LFB3162
	.uleb128 LEHE70-LEHB70
	.uleb128 L697-LFB3162
	.uleb128 0
	.uleb128 LEHB71-LFB3162
	.uleb128 LEHE71-LEHB71
	.uleb128 L699-LFB3162
	.uleb128 0
	.uleb128 LEHB72-LFB3162
	.uleb128 LEHE72-LEHB72
	.uleb128 L706-LFB3162
	.uleb128 0
	.uleb128 LEHB73-LFB3162
	.uleb128 LEHE73-LEHB73
	.uleb128 L704-LFB3162
	.uleb128 0
	.uleb128 LEHB74-LFB3162
	.uleb128 LEHE74-LEHB74
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB75-LFB3162
	.uleb128 LEHE75-LEHB75
	.uleb128 L658-LFB3162
	.uleb128 0
	.uleb128 LEHB76-LFB3162
	.uleb128 LEHE76-LEHB76
	.uleb128 L656-LFB3162
	.uleb128 0
	.uleb128 LEHB77-LFB3162
	.uleb128 LEHE77-LEHB77
	.uleb128 L720-LFB3162
	.uleb128 0
	.uleb128 LEHB78-LFB3162
	.uleb128 LEHE78-LEHB78
	.uleb128 L718-LFB3162
	.uleb128 0
	.uleb128 LEHB79-LFB3162
	.uleb128 LEHE79-LEHB79
	.uleb128 L711-LFB3162
	.uleb128 0
	.uleb128 LEHB80-LFB3162
	.uleb128 LEHE80-LEHB80
	.uleb128 L713-LFB3162
	.uleb128 0
LLSDACSE3162:
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt04_Type1v
	.def	__Z18runTestOpt04_Type1v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt04_Type1v:
LFB3178:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$100000000, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	call	__Z25runTestOpt04_Type1_Beforev
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z24runTestOpt04_Type1_Afterv
	.cfi_endproc
LFE3178:
	.section .rdata,"dr"
LC54:
	.ascii "  sum=%.5f\12\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt04_Type1_Beforev
	.def	__Z25runTestOpt04_Type1_Beforev;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type1_Beforev:
LFB3179:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC11, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	fldz
	movl	%eax, %ebx
	movl	%edx, %esi
	xorl	%eax, %eax
	flds	LC0
	.p2align 4,,7
L1106:
	movl	%eax, 20(%esp)
	addl	$1, %eax
	fildl	20(%esp)
	cmpl	$100000000, %eax
	fdiv	%st(1), %st
	faddp	%st, %st(2)
	jne	L1106
	fstp	%st(0)
	fstps	16(%esp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%ebx, %eax
	sbbl	%esi, %edx
	movl	%edx, 28(%esp)
	movl	%eax, 24(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$LC54, (%esp)
	flds	16(%esp)
	fstpl	4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3179:
	.p2align 4,,15
	.globl	__Z24runTestOpt04_Type1_Afterv
	.def	__Z24runTestOpt04_Type1_Afterv;	.scl	2;	.type	32;	.endef
__Z24runTestOpt04_Type1_Afterv:
LFB3180:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC21, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	fldz
	movl	%eax, %ebx
	movl	%edx, %esi
	xorl	%eax, %eax
	flds	LC2
	.p2align 4,,7
L1110:
	movl	%eax, 20(%esp)
	addl	$1, %eax
	fildl	20(%esp)
	cmpl	$100000000, %eax
	fmul	%st(1), %st
	faddp	%st, %st(2)
	jne	L1110
	fstp	%st(0)
	fstps	16(%esp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%ebx, %eax
	sbbl	%esi, %edx
	movl	%edx, 28(%esp)
	movl	%eax, 24(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$LC54, (%esp)
	flds	16(%esp)
	fstpl	4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3180:
	.section .rdata,"dr"
LC55:
	.ascii "Type2: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt04_Type2R11dataOpt04_t
	.def	__Z18runTestOpt04_Type2R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z18runTestOpt04_Type2R11dataOpt04_t:
LFB3181:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	movl	$10000, 4(%esp)
	movl	$LC55, (%esp)
	call	_printf
	movl	%ebx, (%esp)
	call	__Z22testOpt04_Type2_BeforeR11dataOpt04_t
	movl	%ebx, (%esp)
	call	__Z22testOpt04_Type2_After1R11dataOpt04_t
	movl	%ebx, (%esp)
	call	__Z22testOpt04_Type2_After2R11dataOpt04_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt04_Type2_BeforeR11dataOpt04_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt04_Type2_After1R11dataOpt04_t
	movl	%ebx, 32(%esp)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	__Z25runTestOpt04_Type2_After2R11dataOpt04_t
	.cfi_endproc
LFE3181:
	.p2align 4,,15
	.globl	__Z25runTestOpt04_Type2_BeforeR11dataOpt04_t
	.def	__Z25runTestOpt04_Type2_BeforeR11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type2_BeforeR11dataOpt04_t:
LFB3182:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$10000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC11, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1116:
	movl	%esi, (%esp)
	call	__Z22testOpt04_Type2_BeforeR11dataOpt04_t
	subl	$1, %ebx
	jne	L1116
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 48(%esp)
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE3182:
	.p2align 4,,15
	.globl	__Z25runTestOpt04_Type2_After1R11dataOpt04_t
	.def	__Z25runTestOpt04_Type2_After1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type2_After1R11dataOpt04_t:
LFB3183:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$10000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC13, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1120:
	movl	%esi, (%esp)
	call	__Z22testOpt04_Type2_After1R11dataOpt04_t
	subl	$1, %ebx
	jne	L1120
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 48(%esp)
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE3183:
	.p2align 4,,15
	.globl	__Z25runTestOpt04_Type2_After2R11dataOpt04_t
	.def	__Z25runTestOpt04_Type2_After2R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type2_After2R11dataOpt04_t:
LFB3184:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$10000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC14, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1124:
	movl	%esi, (%esp)
	call	__Z22testOpt04_Type2_After2R11dataOpt04_t
	subl	$1, %ebx
	jne	L1124
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 48(%esp)
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE3184:
	.p2align 4,,15
	.globl	__Z18runTestOpt04_Type3f
	.def	__Z18runTestOpt04_Type3f;	.scl	2;	.type	32;	.endef
__Z18runTestOpt04_Type3f:
LFB3185:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	flds	32(%esp)
	movl	$100000000, 4(%esp)
	fstps	12(%esp)
	movl	$LC23, (%esp)
	call	_printf
	movss	12(%esp), %xmm0
	movss	%xmm0, (%esp)
	call	__Z25runTestOpt04_Type3_Beforef
	movss	12(%esp), %xmm0
	movss	%xmm0, (%esp)
	call	__Z25runTestOpt04_Type3_After1f
	movss	12(%esp), %xmm0
	movss	%xmm0, (%esp)
	call	__Z25runTestOpt04_Type3_After2f
	movss	12(%esp), %xmm0
	movss	%xmm0, 32(%esp)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z25runTestOpt04_Type3_After3f
	.cfi_endproc
LFE3185:
	.p2align 4,,15
	.globl	__Z25runTestOpt04_Type3_Beforef
	.def	__Z25runTestOpt04_Type3_Beforef;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type3_Beforef:
LFB3186:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC11, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movss	48(%esp), %xmm1
	shufps	$0, %xmm1, %xmm1
	movl	%eax, %ebx
	movl	%edx, %esi
	xorl	%eax, %eax
	fldz
	.p2align 4,,7
L1130:
	movl	%eax, 20(%esp)
	addl	$1, %eax
	fildl	20(%esp)
	cmpl	$100000000, %eax
	fstps	16(%esp)
	movss	16(%esp), %xmm0
	shufps	$0, %xmm0, %xmm0
	divss	%xmm1, %xmm0
	movss	%xmm0, 16(%esp)
	fadds	16(%esp)
	jne	L1130
	fstps	16(%esp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%ebx, %eax
	sbbl	%esi, %edx
	movl	%edx, 28(%esp)
	movl	%eax, 24(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$LC54, (%esp)
	flds	16(%esp)
	fstpl	4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3186:
	.p2align 4,,15
	.globl	__Z25runTestOpt04_Type3_After1f
	.def	__Z25runTestOpt04_Type3_After1f;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type3_After1f:
LFB3187:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC13, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movss	48(%esp), %xmm1
	shufps	$0, %xmm1, %xmm1
	rcpss	%xmm1, %xmm1
	movl	%eax, %ebx
	movl	%edx, %esi
	xorl	%eax, %eax
	fldz
	.p2align 4,,7
L1134:
	movl	%eax, 20(%esp)
	addl	$1, %eax
	fildl	20(%esp)
	cmpl	$100000000, %eax
	fstps	16(%esp)
	movss	16(%esp), %xmm0
	shufps	$0, %xmm0, %xmm0
	mulss	%xmm1, %xmm0
	movss	%xmm0, 16(%esp)
	fadds	16(%esp)
	jne	L1134
	fstps	16(%esp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%ebx, %eax
	sbbl	%esi, %edx
	movl	%edx, 28(%esp)
	movl	%eax, 24(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$LC54, (%esp)
	flds	16(%esp)
	fstpl	4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3187:
	.p2align 4,,15
	.globl	__Z25runTestOpt04_Type3_After2f
	.def	__Z25runTestOpt04_Type3_After2f;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type3_After2f:
LFB3188:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC14, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movss	48(%esp), %xmm2
	movaps	LC5, %xmm0
	shufps	$0, %xmm2, %xmm2
	movaps	%xmm2, %xmm1
	movl	%eax, %ebx
	movl	%edx, %esi
	rcpss	%xmm2, %xmm1
	xorl	%eax, %eax
	fldz
	mulss	%xmm1, %xmm2
	subss	%xmm2, %xmm0
	mulss	%xmm0, %xmm1
	.p2align 4,,7
L1138:
	movl	%eax, 20(%esp)
	addl	$1, %eax
	fildl	20(%esp)
	cmpl	$100000000, %eax
	fstps	16(%esp)
	movss	16(%esp), %xmm0
	shufps	$0, %xmm0, %xmm0
	mulss	%xmm1, %xmm0
	movss	%xmm0, 16(%esp)
	fadds	16(%esp)
	jne	L1138
	fstps	16(%esp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%ebx, %eax
	sbbl	%esi, %edx
	movl	%edx, 28(%esp)
	movl	%eax, 24(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$LC54, (%esp)
	flds	16(%esp)
	fstpl	4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3188:
	.p2align 4,,15
	.globl	__Z25runTestOpt04_Type3_After3f
	.def	__Z25runTestOpt04_Type3_After3f;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type3_After3f:
LFB3189:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC15, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movss	48(%esp), %xmm0
	movaps	LC5, %xmm2
	shufps	$0, %xmm0, %xmm0
	movaps	%xmm2, %xmm4
	movaps	%xmm0, %xmm1
	movaps	%xmm0, %xmm3
	movl	%eax, %ebx
	rcpss	%xmm0, %xmm1
	movl	%edx, %esi
	xorl	%eax, %eax
	fldz
	mulss	%xmm1, %xmm3
	subss	%xmm3, %xmm4
	mulss	%xmm4, %xmm1
	mulss	%xmm1, %xmm0
	subss	%xmm0, %xmm2
	mulss	%xmm2, %xmm1
	.p2align 4,,7
L1142:
	movl	%eax, 20(%esp)
	addl	$1, %eax
	fildl	20(%esp)
	cmpl	$100000000, %eax
	fstps	16(%esp)
	movss	16(%esp), %xmm0
	shufps	$0, %xmm0, %xmm0
	mulss	%xmm1, %xmm0
	movss	%xmm0, 16(%esp)
	fadds	16(%esp)
	jne	L1142
	fstps	16(%esp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%ebx, %eax
	sbbl	%esi, %edx
	movl	%edx, 28(%esp)
	movl	%eax, 24(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$LC54, (%esp)
	flds	16(%esp)
	fstpl	4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3189:
	.section .rdata,"dr"
LC56:
	.ascii "Type4: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt04_Type4v
	.def	__Z18runTestOpt04_Type4v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt04_Type4v:
LFB3190:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$100000000, 4(%esp)
	movl	$LC56, (%esp)
	call	_printf
	call	__Z25runTestOpt04_Type4_Beforev
	call	__Z25runTestOpt04_Type4_After1v
	.p2align 4,,5
	call	__Z25runTestOpt04_Type4_After2v
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z25runTestOpt04_Type4_After3v
	.cfi_endproc
LFE3190:
	.p2align 4,,15
	.globl	__Z25runTestOpt04_Type4_Beforev
	.def	__Z25runTestOpt04_Type4_Beforev;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type4_Beforev:
LFB3191:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC11, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, %ebx
	movl	%edx, %esi
	movl	$1, %eax
	fldz
	.p2align 4,,7
L1148:
	movl	%eax, 20(%esp)
	addl	$1, %eax
	fildl	20(%esp)
	cmpl	$100000000, %eax
	fstps	16(%esp)
	movss	16(%esp), %xmm0
	shufps	$0, %xmm0, %xmm0
	sqrtss	%xmm0, %xmm0
	movss	%xmm0, 16(%esp)
	fadds	16(%esp)
	jne	L1148
	fstps	16(%esp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%ebx, %eax
	sbbl	%esi, %edx
	movl	%edx, 28(%esp)
	movl	%eax, 24(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$LC54, (%esp)
	flds	16(%esp)
	fstpl	4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3191:
	.p2align 4,,15
	.globl	__Z25runTestOpt04_Type4_After1v
	.def	__Z25runTestOpt04_Type4_After1v;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type4_After1v:
LFB3192:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC13, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, %ebx
	movl	%edx, %esi
	movl	$1, %eax
	fldz
	.p2align 4,,7
L1152:
	movl	%eax, 20(%esp)
	addl	$1, %eax
	fildl	20(%esp)
	cmpl	$100000000, %eax
	fstps	16(%esp)
	movss	16(%esp), %xmm0
	shufps	$0, %xmm0, %xmm0
	movaps	%xmm0, %xmm1
	rsqrtss	%xmm0, %xmm1
	mulss	%xmm1, %xmm0
	movss	%xmm0, 16(%esp)
	fadds	16(%esp)
	jne	L1152
	fstps	16(%esp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%ebx, %eax
	sbbl	%esi, %edx
	movl	%edx, 28(%esp)
	movl	%eax, 24(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$LC54, (%esp)
	flds	16(%esp)
	fstpl	4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3192:
	.p2align 4,,15
	.globl	__Z25runTestOpt04_Type4_After2v
	.def	__Z25runTestOpt04_Type4_After2v;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type4_After2v:
LFB3193:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC14, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movaps	LC3, %xmm2
	movaps	LC4, %xmm4
	movl	%eax, %ebx
	movl	%edx, %esi
	movl	$1, %eax
	fldz
	.p2align 4,,7
L1156:
	movl	%eax, 20(%esp)
	addl	$1, %eax
	fildl	20(%esp)
	cmpl	$100000000, %eax
	fstps	16(%esp)
	movss	16(%esp), %xmm0
	movaps	%xmm2, %xmm6
	shufps	$0, %xmm0, %xmm0
	movaps	%xmm0, %xmm1
	movaps	%xmm0, %xmm5
	rsqrtss	%xmm0, %xmm1
	movaps	%xmm1, %xmm3
	mulss	%xmm1, %xmm3
	mulss	%xmm3, %xmm5
	subss	%xmm5, %xmm6
	mulss	%xmm6, %xmm1
	mulss	%xmm4, %xmm1
	mulss	%xmm1, %xmm0
	movss	%xmm0, 16(%esp)
	fadds	16(%esp)
	jne	L1156
	fstps	16(%esp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%ebx, %eax
	sbbl	%esi, %edx
	movl	%edx, 28(%esp)
	movl	%eax, 24(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$LC54, (%esp)
	flds	16(%esp)
	fstpl	4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3193:
	.p2align 4,,15
	.globl	__Z25runTestOpt04_Type4_After3v
	.def	__Z25runTestOpt04_Type4_After3v;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type4_After3v:
LFB3194:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC15, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movaps	LC3, %xmm2
	movaps	LC4, %xmm3
	movl	%eax, %ebx
	movl	%edx, %esi
	movl	$1, %eax
	fldz
	.p2align 4,,7
L1160:
	movl	%eax, 20(%esp)
	addl	$1, %eax
	fildl	20(%esp)
	cmpl	$100000000, %eax
	fstps	16(%esp)
	movss	16(%esp), %xmm0
	movaps	%xmm2, %xmm6
	shufps	$0, %xmm0, %xmm0
	movaps	%xmm0, %xmm1
	movaps	%xmm0, %xmm5
	movaps	%xmm0, %xmm7
	rsqrtss	%xmm0, %xmm1
	movaps	%xmm1, %xmm4
	mulss	%xmm1, %xmm4
	mulss	%xmm4, %xmm5
	subss	%xmm5, %xmm6
	movaps	%xmm2, %xmm5
	mulss	%xmm6, %xmm1
	mulss	%xmm3, %xmm1
	movaps	%xmm1, %xmm4
	mulss	%xmm1, %xmm4
	mulss	%xmm4, %xmm7
	subss	%xmm7, %xmm5
	mulss	%xmm5, %xmm1
	mulss	%xmm3, %xmm1
	mulss	%xmm1, %xmm0
	movss	%xmm0, 16(%esp)
	fadds	16(%esp)
	jne	L1160
	fstps	16(%esp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%ebx, %eax
	sbbl	%esi, %edx
	movl	%edx, 28(%esp)
	movl	%eax, 24(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$LC54, (%esp)
	flds	16(%esp)
	fstpl	4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3194:
	.section .rdata,"dr"
LC57:
	.ascii "[Optimize Test 05]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt05v
	.def	__Z12runTestOpt05v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt05v:
LFB3195:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$LC8, (%esp)
	call	_puts
	movl	$LC57, (%esp)
	call	_puts
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z18runTestOpt05_Type1v
	.cfi_endproc
LFE3195:
	.p2align 4,,15
	.globl	__Z18runTestOpt05_Type1v
	.def	__Z18runTestOpt05_Type1v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt05_Type1v:
LFB3196:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$10000000, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	call	__Z25runTestOpt05_Type1_Beforev
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z24runTestOpt05_Type1_Afterv
	.cfi_endproc
LFE3196:
	.p2align 4,,15
	.globl	__Z25runTestOpt05_Type1_Beforev
	.def	__Z25runTestOpt05_Type1_Beforev;	.scl	2;	.type	32;	.endef
__Z25runTestOpt05_Type1_Beforev:
LFB3197:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$460, %esp
	.cfi_def_cfa_offset 480
	movl	$LC11, (%esp)
	leal	160(%esp), %ebp
	call	_printf
	leal	128(%esp), %edi
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 96(%esp)
	movl	%edx, 100(%esp)
	.p2align 4,,7
L1168:
	leal	432(%esp), %eax
	movl	%eax, 80(%esp)
	leal	416(%esp), %eax
	movl	%eax, 76(%esp)
	leal	400(%esp), %eax
	movl	%eax, 72(%esp)
	leal	384(%esp), %eax
	movl	%eax, 68(%esp)
	leal	368(%esp), %eax
	movl	%eax, 64(%esp)
	leal	352(%esp), %eax
	movl	%eax, 60(%esp)
	leal	336(%esp), %eax
	movl	%eax, 56(%esp)
	leal	320(%esp), %eax
	movl	%eax, 52(%esp)
	leal	304(%esp), %eax
	movl	%eax, 48(%esp)
	leal	288(%esp), %eax
	movl	%eax, 44(%esp)
	leal	272(%esp), %eax
	movl	%eax, 40(%esp)
	leal	256(%esp), %eax
	movl	%eax, 36(%esp)
	leal	240(%esp), %eax
	movl	%esi, 432(%esp)
	movl	%esi, 416(%esp)
	movl	%esi, 400(%esp)
	movl	%esi, 384(%esp)
	movl	%esi, 368(%esp)
	movl	%esi, 352(%esp)
	movl	%esi, 336(%esp)
	movl	%esi, 320(%esp)
	movl	%esi, 304(%esp)
	movl	%esi, 288(%esp)
	movl	%esi, 272(%esp)
	movl	%esi, 256(%esp)
	movl	%esi, 240(%esp)
	movl	%esi, 224(%esp)
	movl	%esi, 208(%esp)
	movl	%esi, 192(%esp)
	movl	%esi, 176(%esp)
	movl	%esi, 160(%esp)
	movl	%esi, 144(%esp)
	movl	%esi, 128(%esp)
	movl	%esi, 112(%esp)
	addl	$1, %esi
	movl	%eax, 32(%esp)
	leal	224(%esp), %eax
	movl	%eax, 28(%esp)
	leal	208(%esp), %eax
	movl	%eax, 24(%esp)
	leal	192(%esp), %eax
	movl	%eax, 20(%esp)
	leal	176(%esp), %eax
	movl	%eax, 16(%esp)
	leal	144(%esp), %eax
	movl	%eax, 8(%esp)
	leal	112(%esp), %eax
	movl	%ebp, 12(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	__Z22testOpt05_Type1_BeforeRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_
	addl	%eax, %ebx
	cmpl	$10000000, %esi
	jne	L1168
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	96(%esp), %eax
	sbbl	100(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$460, %esp
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
LFE3197:
	.p2align 4,,15
	.globl	__Z24runTestOpt05_Type1_Afterv
	.def	__Z24runTestOpt05_Type1_Afterv;	.scl	2;	.type	32;	.endef
__Z24runTestOpt05_Type1_Afterv:
LFB3198:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$460, %esp
	.cfi_def_cfa_offset 480
	movl	$LC21, (%esp)
	leal	160(%esp), %ebp
	call	_printf
	leal	128(%esp), %edi
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 96(%esp)
	movl	%edx, 100(%esp)
	.p2align 4,,7
L1172:
	leal	432(%esp), %eax
	movl	%eax, 80(%esp)
	leal	416(%esp), %eax
	movl	%eax, 76(%esp)
	leal	400(%esp), %eax
	movl	%eax, 72(%esp)
	leal	384(%esp), %eax
	movl	%eax, 68(%esp)
	leal	368(%esp), %eax
	movl	%eax, 64(%esp)
	leal	352(%esp), %eax
	movl	%eax, 60(%esp)
	leal	336(%esp), %eax
	movl	%eax, 56(%esp)
	leal	320(%esp), %eax
	movl	%eax, 52(%esp)
	leal	304(%esp), %eax
	movl	%eax, 48(%esp)
	leal	288(%esp), %eax
	movl	%eax, 44(%esp)
	leal	272(%esp), %eax
	movl	%eax, 40(%esp)
	leal	256(%esp), %eax
	movl	%eax, 36(%esp)
	leal	240(%esp), %eax
	movl	%esi, 432(%esp)
	movl	%esi, 416(%esp)
	movl	%esi, 400(%esp)
	movl	%esi, 384(%esp)
	movl	%esi, 368(%esp)
	movl	%esi, 352(%esp)
	movl	%esi, 336(%esp)
	movl	%esi, 320(%esp)
	movl	%esi, 304(%esp)
	movl	%esi, 288(%esp)
	movl	%esi, 272(%esp)
	movl	%esi, 256(%esp)
	movl	%esi, 240(%esp)
	movl	%esi, 224(%esp)
	movl	%esi, 208(%esp)
	movl	%esi, 192(%esp)
	movl	%esi, 176(%esp)
	movl	%esi, 160(%esp)
	movl	%esi, 144(%esp)
	movl	%esi, 128(%esp)
	movl	%esi, 112(%esp)
	addl	$1, %esi
	movl	%eax, 32(%esp)
	leal	224(%esp), %eax
	movl	%eax, 28(%esp)
	leal	208(%esp), %eax
	movl	%eax, 24(%esp)
	leal	192(%esp), %eax
	movl	%eax, 20(%esp)
	leal	176(%esp), %eax
	movl	%eax, 16(%esp)
	leal	144(%esp), %eax
	movl	%eax, 8(%esp)
	leal	112(%esp), %eax
	movl	%ebp, 12(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	__Z21testOpt05_Type1_AfterRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_
	addl	%eax, %ebx
	cmpl	$10000000, %esi
	jne	L1172
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	96(%esp), %eax
	sbbl	100(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$460, %esp
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
LFE3198:
	.p2align 4,,15
	.globl	__Z18runTestOpt06_Type1R11dataOpt06_tfff
	.def	__Z18runTestOpt06_Type1R11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
__Z18runTestOpt06_Type1R11dataOpt06_tfff:
LFB3201:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$40, %esp
	.cfi_def_cfa_offset 48
	flds	52(%esp)
	fstps	20(%esp)
	movl	48(%esp), %ebx
	flds	56(%esp)
	fstps	24(%esp)
	flds	60(%esp)
	movl	$10000, 4(%esp)
	fstps	28(%esp)
	movl	$LC10, (%esp)
	call	_printf
	movss	28(%esp), %xmm0
	movss	24(%esp), %xmm1
	movss	20(%esp), %xmm2
	movss	%xmm0, 12(%esp)
	movss	%xmm1, 8(%esp)
	movss	%xmm2, 4(%esp)
	movl	%ebx, (%esp)
	call	__Z25runTestOpt06_Type1_BeforeR11dataOpt06_tfff
	movss	28(%esp), %xmm0
	movss	24(%esp), %xmm1
	movss	20(%esp), %xmm2
	movl	%ebx, 48(%esp)
	movss	%xmm0, 60(%esp)
	movss	%xmm1, 56(%esp)
	movss	%xmm2, 52(%esp)
	addl	$40, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	__Z24runTestOpt06_Type1_AfterR11dataOpt06_tfff
	.cfi_endproc
LFE3201:
	.section .rdata,"dr"
LC58:
	.ascii "  sum=%.f\12\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt06_Type1_BeforeR11dataOpt06_tfff
	.def	__Z25runTestOpt06_Type1_BeforeR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
__Z25runTestOpt06_Type1_BeforeR11dataOpt06_tfff:
LFB3202:
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
	movl	$10000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	flds	84(%esp)
	fstps	28(%esp)
	movl	80(%esp), %esi
	flds	88(%esp)
	fstps	32(%esp)
	flds	92(%esp)
	movl	$LC11, (%esp)
	fstps	36(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	fldz
	movl	%eax, %edi
	movl	%edx, %ebp
	fstps	24(%esp)
	.p2align 4,,7
L1178:
	movss	36(%esp), %xmm0
	movss	32(%esp), %xmm1
	movss	28(%esp), %xmm2
	movss	%xmm0, 12(%esp)
	movss	%xmm1, 8(%esp)
	movss	%xmm2, 4(%esp)
	movl	%esi, (%esp)
	call	__Z22testOpt06_Type1_BeforeR11dataOpt06_tfff
	subl	$1, %ebx
	fadds	24(%esp)
	fstps	24(%esp)
	jne	L1178
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%edi, %eax
	sbbl	%ebp, %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$LC58, 80(%esp)
	flds	24(%esp)
	fstpl	84(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3202:
	.p2align 4,,15
	.globl	__Z24runTestOpt06_Type1_AfterR11dataOpt06_tfff
	.def	__Z24runTestOpt06_Type1_AfterR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
__Z24runTestOpt06_Type1_AfterR11dataOpt06_tfff:
LFB3203:
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
	movl	$10000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	flds	84(%esp)
	fstps	28(%esp)
	movl	80(%esp), %esi
	flds	88(%esp)
	fstps	32(%esp)
	flds	92(%esp)
	movl	$LC21, (%esp)
	fstps	36(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	fldz
	movl	%eax, %edi
	movl	%edx, %ebp
	fstps	24(%esp)
	.p2align 4,,7
L1182:
	movss	36(%esp), %xmm0
	movss	32(%esp), %xmm1
	movss	28(%esp), %xmm2
	movss	%xmm0, 12(%esp)
	movss	%xmm1, 8(%esp)
	movss	%xmm2, 4(%esp)
	movl	%esi, (%esp)
	call	__Z21testOpt06_Type1_AfterR11dataOpt06_tfff
	subl	$1, %ebx
	fadds	24(%esp)
	fstps	24(%esp)
	jne	L1182
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%edi, %eax
	sbbl	%ebp, %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$LC58, 80(%esp)
	flds	24(%esp)
	fstpl	84(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3203:
	.section .rdata,"dr"
LC59:
	.ascii "[Optimize Test 07]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt07v
	.def	__Z12runTestOpt07v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt07v:
LFB3204:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$LC8, (%esp)
	call	_puts
	movl	$LC59, (%esp)
	call	_puts
	call	__Z18runTestOpt07_Type1v
	movl	$1000000, 4(%esp)
	movl	$LC55, (%esp)
	call	_printf
	call	__Z25runTestOpt07_Type2_strlenv
	call	__Z25runTestOpt07_Type2_strcmpv
	.p2align 4,,5
	call	__Z26runTestOpt07_Type2_strncmpv
	.p2align 4,,5
	call	__Z25runTestOpt07_Type2_strchrv
	.p2align 4,,5
	call	__Z26runTestOpt07_Type2_strrchrv
	.p2align 4,,5
	call	__Z25runTestOpt07_Type2_strstrv
	.p2align 4,,5
	call	__Z25runTestOpt07_Type2_strcpyv
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z26runTestOpt07_Type2_strncpyv
	.cfi_endproc
LFE3204:
	.p2align 4,,15
	.globl	__Z18runTestOpt07_Type1v
	.def	__Z18runTestOpt07_Type1v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt07_Type1v:
LFB3205:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$10000000, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	call	__Z25runTestOpt07_Type1_Beforev
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z24runTestOpt07_Type1_Afterv
	.cfi_endproc
LFE3205:
	.p2align 4,,15
	.globl	__Z25runTestOpt07_Type1_Beforev
	.def	__Z25runTestOpt07_Type1_Beforev;	.scl	2;	.type	32;	.endef
__Z25runTestOpt07_Type1_Beforev:
LFB3206:
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
	subl	$588, %esp
	.cfi_def_cfa_offset 608
	movl	$LC11, (%esp)
	leal	256(%esp), %ebx
	call	_printf
	leal	384(%esp), %ebp
	call	__ZNSt6chrono3_V212system_clock3nowEv
	leal	448(%esp), %edi
	leal	512(%esp), %esi
	flds	LC42
	fldz
	fld	%st(0)
	fld	%st(2)
	fld	%st(2)
	movl	%eax, 48(%esp)
	fld1
	fxch	%st(1)
	xorl	%eax, %eax
	movl	%edx, 52(%esp)
	jmp	L1190
	.p2align 4,,7
L1196:
	fxch	%st(5)
L1190:
	fsts	(%ebx,%eax)
	fxch	%st(2)
	fsts	320(%esp,%eax)
	fxch	%st(3)
	fsts	0(%ebp,%eax)
	fxch	%st(4)
	fsts	(%edi,%eax)
	fxch	%st(5)
	fsts	(%esi,%eax)
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fsts	260(%esp,%eax)
	fxch	%st(4)
	fsts	324(%esp,%eax)
	fxch	%st(5)
	fsts	388(%esp,%eax)
	fxch	%st(2)
	fsts	452(%esp,%eax)
	fxch	%st(3)
	fsts	516(%esp,%eax)
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fsts	264(%esp,%eax)
	fxch	%st(2)
	fsts	328(%esp,%eax)
	fxch	%st(3)
	fsts	392(%esp,%eax)
	fxch	%st(4)
	fsts	456(%esp,%eax)
	fxch	%st(5)
	fsts	520(%esp,%eax)
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fsts	268(%esp,%eax)
	fxch	%st(4)
	fsts	332(%esp,%eax)
	fxch	%st(5)
	fsts	396(%esp,%eax)
	fxch	%st(2)
	fsts	460(%esp,%eax)
	fxch	%st(3)
	fsts	524(%esp,%eax)
	fxch	%st(4)
	addl	$16, %eax
	fadd	%st(1), %st
	fxch	%st(5)
	cmpl	$64, %eax
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	jne	L1196
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	xorb	%al, %al
	.p2align 4,,7
L1192:
	leal	320(%esp), %edx
	leal	192(%esp), %ecx
	movl	%edx, 20(%esp)
	leal	128(%esp), %edx
	movl	%ecx, 12(%esp)
	leal	64(%esp), %ecx
	movl	%eax, (%esp)
	movl	%esi, 36(%esp)
	movl	%edi, 32(%esp)
	movl	$0x40a00000, 28(%esp)
	movl	%ebp, 24(%esp)
	movl	%ebx, 16(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	movl	44(%esp), %eax
	addl	$1, %eax
	cmpl	$10000000, %eax
	jne	L1192
	movl	$0x00000000, 320(%esp)
	xorl	%eax, %eax
	movl	$0x42c80000, 384(%esp)
	movl	$0x00000000, 448(%esp)
	movl	$0x3f800000, 324(%esp)
	movl	$0x42ca0000, 388(%esp)
	movl	$0x3f800000, 452(%esp)
	movl	$0x40000000, 328(%esp)
	movl	$0x42cc0000, 392(%esp)
	movl	$0x40000000, 456(%esp)
	movl	$0x40400000, 332(%esp)
	movl	$0x42ce0000, 396(%esp)
	movl	$0x40400000, 460(%esp)
	movl	$0x00000000, 64(%esp)
	movl	$0x3f800000, 68(%esp)
	movl	$0x40000000, 72(%esp)
	movl	$0x42c80000, 512(%esp)
	movl	$0x42ca0000, 516(%esp)
	movl	$0x42cc0000, 520(%esp)
	movl	$0x42ce0000, 524(%esp)
	movl	$0x42d00000, 528(%esp)
	movl	$0x42d20000, 532(%esp)
	movl	$0x42d40000, 536(%esp)
	movl	$0x42d60000, 540(%esp)
	movl	$0x42d80000, 544(%esp)
	movl	$0x42da0000, 548(%esp)
	movl	$0x42dc0000, 552(%esp)
	movl	$0x42de0000, 556(%esp)
	.p2align 4,,7
L1194:
	leal	64(%esp), %edx
	leal	320(%esp), %ecx
	movl	%edx, 32(%esp)
	leal	192(%esp), %edx
	movl	%ecx, 16(%esp)
	leal	128(%esp), %ecx
	movl	%eax, (%esp)
	movl	%esi, 36(%esp)
	movl	$0x40a00000, 28(%esp)
	movl	%edi, 24(%esp)
	movl	%ebp, 20(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	movl	44(%esp), %eax
	addl	$1, %eax
	cmpl	$10000000, %eax
	jne	L1194
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	48(%esp), %eax
	sbbl	52(%esp), %edx
	movl	%eax, 56(%esp)
	movl	%edx, 60(%esp)
	fildq	56(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, (%esp)
	call	_putchar
	addl	$588, %esp
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
LFE3206:
	.p2align 4,,15
	.globl	__Z24runTestOpt07_Type1_Afterv
	.def	__Z24runTestOpt07_Type1_Afterv;	.scl	2;	.type	32;	.endef
__Z24runTestOpt07_Type1_Afterv:
LFB3207:
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
	subl	$588, %esp
	.cfi_def_cfa_offset 608
	movl	$LC21, (%esp)
	leal	256(%esp), %ebx
	call	_printf
	leal	384(%esp), %ebp
	call	__ZNSt6chrono3_V212system_clock3nowEv
	leal	448(%esp), %edi
	leal	512(%esp), %esi
	flds	LC42
	fldz
	fld	%st(0)
	fld	%st(2)
	fld	%st(2)
	movl	%eax, 48(%esp)
	fld1
	fxch	%st(1)
	xorl	%eax, %eax
	movl	%edx, 52(%esp)
	jmp	L1199
	.p2align 4,,7
L1205:
	fxch	%st(5)
L1199:
	fsts	(%ebx,%eax)
	fxch	%st(2)
	fsts	320(%esp,%eax)
	fxch	%st(3)
	fsts	0(%ebp,%eax)
	fxch	%st(4)
	fsts	(%edi,%eax)
	fxch	%st(5)
	fsts	(%esi,%eax)
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fsts	260(%esp,%eax)
	fxch	%st(4)
	fsts	324(%esp,%eax)
	fxch	%st(5)
	fsts	388(%esp,%eax)
	fxch	%st(2)
	fsts	452(%esp,%eax)
	fxch	%st(3)
	fsts	516(%esp,%eax)
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fsts	264(%esp,%eax)
	fxch	%st(2)
	fsts	328(%esp,%eax)
	fxch	%st(3)
	fsts	392(%esp,%eax)
	fxch	%st(4)
	fsts	456(%esp,%eax)
	fxch	%st(5)
	fsts	520(%esp,%eax)
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fsts	268(%esp,%eax)
	fxch	%st(4)
	fsts	332(%esp,%eax)
	fxch	%st(5)
	fsts	396(%esp,%eax)
	fxch	%st(2)
	fsts	460(%esp,%eax)
	fxch	%st(3)
	fsts	524(%esp,%eax)
	fxch	%st(4)
	addl	$16, %eax
	fadd	%st(1), %st
	fxch	%st(5)
	cmpl	$64, %eax
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	jne	L1205
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	xorb	%al, %al
	.p2align 4,,7
L1201:
	leal	320(%esp), %edx
	leal	192(%esp), %ecx
	movl	%edx, 20(%esp)
	leal	128(%esp), %edx
	movl	%ecx, 12(%esp)
	leal	64(%esp), %ecx
	movl	%eax, (%esp)
	movl	%esi, 36(%esp)
	movl	%edi, 32(%esp)
	movl	$0x40a00000, 28(%esp)
	movl	%ebp, 24(%esp)
	movl	%ebx, 16(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 44(%esp)
	call	__Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	movl	44(%esp), %eax
	addl	$1, %eax
	cmpl	$10000000, %eax
	jne	L1201
	movl	$0x00000000, 320(%esp)
	xorl	%eax, %eax
	movl	$0x42c80000, 384(%esp)
	movl	$0x00000000, 448(%esp)
	movl	$0x3f800000, 324(%esp)
	movl	$0x42ca0000, 388(%esp)
	movl	$0x3f800000, 452(%esp)
	movl	$0x40000000, 328(%esp)
	movl	$0x42cc0000, 392(%esp)
	movl	$0x40000000, 456(%esp)
	movl	$0x40400000, 332(%esp)
	movl	$0x42ce0000, 396(%esp)
	movl	$0x40400000, 460(%esp)
	movl	$0x00000000, 64(%esp)
	movl	$0x3f800000, 68(%esp)
	movl	$0x40000000, 72(%esp)
	movl	$0x42c80000, 512(%esp)
	movl	$0x42ca0000, 516(%esp)
	movl	$0x42cc0000, 520(%esp)
	movl	$0x42ce0000, 524(%esp)
	movl	$0x42d00000, 528(%esp)
	movl	$0x42d20000, 532(%esp)
	movl	$0x42d40000, 536(%esp)
	movl	$0x42d60000, 540(%esp)
	movl	$0x42d80000, 544(%esp)
	movl	$0x42da0000, 548(%esp)
	movl	$0x42dc0000, 552(%esp)
	movl	$0x42de0000, 556(%esp)
	.p2align 4,,7
L1203:
	leal	64(%esp), %edx
	leal	320(%esp), %ecx
	movl	%edx, 32(%esp)
	leal	192(%esp), %edx
	movl	%ecx, 16(%esp)
	leal	128(%esp), %ecx
	movl	%eax, (%esp)
	movl	%esi, 36(%esp)
	movl	$0x40a00000, 28(%esp)
	movl	%edi, 24(%esp)
	movl	%ebp, 20(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 44(%esp)
	call	__Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	movl	44(%esp), %eax
	addl	$1, %eax
	cmpl	$10000000, %eax
	jne	L1203
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	48(%esp), %eax
	sbbl	52(%esp), %edx
	movl	%eax, 56(%esp)
	movl	%edx, 60(%esp)
	fildq	56(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, (%esp)
	call	_putchar
	addl	$588, %esp
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
LFE3207:
	.section .rdata,"dr"
LC73:
	.ascii "Type2(strlen):\0"
LC74:
	.ascii "\0"
LC75:
	.ascii "123\0"
LC76:
	.ascii "1234567890abcdef\0"
LC77:
	.ascii "1234567890abcdefg\0"
	.align 4
LC78:
	.ascii "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt07_Type2_strlenv
	.def	__Z25runTestOpt07_Type2_strlenv;	.scl	2;	.type	32;	.endef
__Z25runTestOpt07_Type2_strlenv:
LFB3208:
	.cfi_startproc
	subl	$44, %esp
	.cfi_def_cfa_offset 48
	movl	$LC73, (%esp)
	call	_puts
	movl	$LC74, 16(%esp)
	movl	$LC75, 12(%esp)
	movl	$LC76, 8(%esp)
	movl	$LC77, 4(%esp)
	movl	$LC78, (%esp)
	call	__Z32runTestOpt07_Type2_strlen_BeforePKcS0_S0_S0_S0_
	movl	$LC74, 16(%esp)
	movl	$LC75, 12(%esp)
	movl	$LC76, 8(%esp)
	movl	$LC77, 4(%esp)
	movl	$LC78, (%esp)
	call	__Z31runTestOpt07_Type2_strlen_AfterPKcS0_S0_S0_S0_
	addl	$44, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3208:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strlen_BeforePKcS0_S0_S0_S0_
	.def	__Z32runTestOpt07_Type2_strlen_BeforePKcS0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strlen_BeforePKcS0_S0_S0_S0_:
LFB3209:
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
	xorl	%ebx, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	92(%esp), %eax
	movl	$LC11, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	88(%esp), %esi
	movl	%eax, 24(%esp)
	movl	96(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1210:
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	call	__Z29testOpt07_Type2_strlen_BeforeiPKc
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	call	__Z29testOpt07_Type2_strlen_BeforeiPKc
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	call	__Z29testOpt07_Type2_strlen_BeforeiPKc
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strlen_BeforeiPKc
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strlen_BeforeiPKc
	cmpl	$1000000, %ebx
	jne	L1210
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 80(%esp)
	addl	$60, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3209:
	.p2align 4,,15
	.globl	__Z31runTestOpt07_Type2_strlen_AfterPKcS0_S0_S0_S0_
	.def	__Z31runTestOpt07_Type2_strlen_AfterPKcS0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
__Z31runTestOpt07_Type2_strlen_AfterPKcS0_S0_S0_S0_:
LFB3210:
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
	xorl	%ebx, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	92(%esp), %eax
	movl	$LC21, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	88(%esp), %esi
	movl	%eax, 24(%esp)
	movl	96(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1214:
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	call	__Z28testOpt07_Type2_strlen_AfteriPKc
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	call	__Z28testOpt07_Type2_strlen_AfteriPKc
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	call	__Z28testOpt07_Type2_strlen_AfteriPKc
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strlen_AfteriPKc
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strlen_AfteriPKc
	cmpl	$1000000, %ebx
	jne	L1214
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 80(%esp)
	addl	$60, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3210:
	.section .rdata,"dr"
LC79:
	.ascii "Type2(strcmp):\0"
LC80:
	.ascii "123!\0"
LC81:
	.ascii "1234567890abcdef!\0"
	.align 4
LC82:
	.ascii "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_!\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt07_Type2_strcmpv
	.def	__Z25runTestOpt07_Type2_strcmpv;	.scl	2;	.type	32;	.endef
__Z25runTestOpt07_Type2_strcmpv:
LFB3211:
	.cfi_startproc
	subl	$92, %esp
	.cfi_def_cfa_offset 96
	movl	$LC79, (%esp)
	call	_puts
	movl	$LC74, 76(%esp)
	movl	$LC74, 72(%esp)
	movl	$LC75, 68(%esp)
	movl	$LC80, 64(%esp)
	movl	$LC80, 60(%esp)
	movl	$LC75, 56(%esp)
	movl	$LC75, 52(%esp)
	movl	$LC75, 48(%esp)
	movl	$LC76, 44(%esp)
	movl	$LC81, 40(%esp)
	movl	$LC81, 36(%esp)
	movl	$LC76, 32(%esp)
	movl	$LC76, 28(%esp)
	movl	$LC76, 24(%esp)
	movl	$LC78, 20(%esp)
	movl	$LC82, 16(%esp)
	movl	$LC82, 12(%esp)
	movl	$LC78, 8(%esp)
	movl	$LC78, 4(%esp)
	movl	$LC78, (%esp)
	call	__Z32runTestOpt07_Type2_strcmp_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	movl	$LC74, 76(%esp)
	movl	$LC74, 72(%esp)
	movl	$LC75, 68(%esp)
	movl	$LC80, 64(%esp)
	movl	$LC80, 60(%esp)
	movl	$LC75, 56(%esp)
	movl	$LC75, 52(%esp)
	movl	$LC75, 48(%esp)
	movl	$LC76, 44(%esp)
	movl	$LC81, 40(%esp)
	movl	$LC81, 36(%esp)
	movl	$LC76, 32(%esp)
	movl	$LC76, 28(%esp)
	movl	$LC76, 24(%esp)
	movl	$LC78, 20(%esp)
	movl	$LC82, 16(%esp)
	movl	$LC82, 12(%esp)
	movl	$LC78, 8(%esp)
	movl	$LC78, 4(%esp)
	movl	$LC78, (%esp)
	call	__Z31runTestOpt07_Type2_strcmp_AfterPKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	addl	$92, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3211:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strcmp_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	.def	__Z32runTestOpt07_Type2_strcmp_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strcmp_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_:
LFB3212:
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
	xorl	%ebx, %ebx
	subl	$108, %esp
	.cfi_def_cfa_offset 128
	movl	128(%esp), %eax
	movl	%eax, 12(%esp)
	movl	132(%esp), %eax
	movl	%eax, 16(%esp)
	movl	136(%esp), %eax
	movl	%eax, 20(%esp)
	movl	140(%esp), %eax
	movl	%eax, 24(%esp)
	movl	144(%esp), %eax
	movl	%eax, 28(%esp)
	movl	148(%esp), %eax
	movl	%eax, 32(%esp)
	movl	152(%esp), %eax
	movl	%eax, 36(%esp)
	movl	156(%esp), %eax
	movl	%eax, 40(%esp)
	movl	160(%esp), %eax
	movl	%eax, 44(%esp)
	movl	164(%esp), %eax
	movl	%eax, 48(%esp)
	movl	168(%esp), %eax
	movl	%eax, 52(%esp)
	movl	172(%esp), %eax
	movl	%eax, 56(%esp)
	movl	176(%esp), %eax
	movl	%eax, 60(%esp)
	movl	180(%esp), %eax
	movl	%eax, 64(%esp)
	movl	184(%esp), %eax
	movl	%eax, 68(%esp)
	movl	188(%esp), %eax
	movl	$LC11, (%esp)
	movl	192(%esp), %ebp
	movl	200(%esp), %edi
	movl	204(%esp), %esi
	movl	%eax, 72(%esp)
	movl	196(%esp), %eax
	movl	%eax, 76(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 80(%esp)
	movl	%edx, 84(%esp)
	.p2align 4,,7
L1220:
	movl	16(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	12(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	36(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	44(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	52(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	60(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	68(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	cmpl	$1000000, %ebx
	jne	L1220
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	80(%esp), %eax
	sbbl	84(%esp), %edx
	movl	%eax, 88(%esp)
	movl	%edx, 92(%esp)
	fildq	88(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 128(%esp)
	addl	$108, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3212:
	.p2align 4,,15
	.globl	__Z31runTestOpt07_Type2_strcmp_AfterPKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	.def	__Z31runTestOpt07_Type2_strcmp_AfterPKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
__Z31runTestOpt07_Type2_strcmp_AfterPKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_:
LFB3213:
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
	xorl	%ebx, %ebx
	subl	$108, %esp
	.cfi_def_cfa_offset 128
	movl	128(%esp), %eax
	movl	%eax, 12(%esp)
	movl	132(%esp), %eax
	movl	%eax, 16(%esp)
	movl	136(%esp), %eax
	movl	%eax, 20(%esp)
	movl	140(%esp), %eax
	movl	%eax, 24(%esp)
	movl	144(%esp), %eax
	movl	%eax, 28(%esp)
	movl	148(%esp), %eax
	movl	%eax, 32(%esp)
	movl	152(%esp), %eax
	movl	%eax, 36(%esp)
	movl	156(%esp), %eax
	movl	%eax, 40(%esp)
	movl	160(%esp), %eax
	movl	%eax, 44(%esp)
	movl	164(%esp), %eax
	movl	%eax, 48(%esp)
	movl	168(%esp), %eax
	movl	%eax, 52(%esp)
	movl	172(%esp), %eax
	movl	%eax, 56(%esp)
	movl	176(%esp), %eax
	movl	%eax, 60(%esp)
	movl	180(%esp), %eax
	movl	%eax, 64(%esp)
	movl	184(%esp), %eax
	movl	%eax, 68(%esp)
	movl	188(%esp), %eax
	movl	$LC21, (%esp)
	movl	192(%esp), %ebp
	movl	200(%esp), %edi
	movl	204(%esp), %esi
	movl	%eax, 72(%esp)
	movl	196(%esp), %eax
	movl	%eax, 76(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 80(%esp)
	movl	%edx, 84(%esp)
	.p2align 4,,7
L1224:
	movl	16(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	12(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	36(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	44(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	52(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	60(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	68(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	cmpl	$1000000, %ebx
	jne	L1224
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	80(%esp), %eax
	sbbl	84(%esp), %edx
	movl	%eax, 88(%esp)
	movl	%edx, 92(%esp)
	fildq	88(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 128(%esp)
	addl	$108, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3213:
	.section .rdata,"dr"
LC83:
	.ascii "Type2(strncmp):\0"
	.text
	.p2align 4,,15
	.globl	__Z26runTestOpt07_Type2_strncmpv
	.def	__Z26runTestOpt07_Type2_strncmpv;	.scl	2;	.type	32;	.endef
__Z26runTestOpt07_Type2_strncmpv:
LFB3214:
	.cfi_startproc
	subl	$220, %esp
	.cfi_def_cfa_offset 224
	movl	$LC83, (%esp)
	call	_puts
	movl	$0, 196(%esp)
	movl	$1, 192(%esp)
	movl	$2, 188(%esp)
	movl	$LC74, 184(%esp)
	movl	$LC74, 180(%esp)
	movl	$2, 176(%esp)
	movl	$3, 172(%esp)
	movl	$4, 168(%esp)
	movl	$LC75, 164(%esp)
	movl	$LC80, 160(%esp)
	movl	$2, 156(%esp)
	movl	$3, 152(%esp)
	movl	$4, 148(%esp)
	movl	$LC80, 144(%esp)
	movl	$LC75, 140(%esp)
	movl	$2, 136(%esp)
	movl	$3, 132(%esp)
	movl	$4, 128(%esp)
	movl	$LC75, 124(%esp)
	movl	$LC75, 120(%esp)
	movl	$15, 116(%esp)
	movl	$16, 112(%esp)
	movl	$17, 108(%esp)
	movl	$LC76, 104(%esp)
	movl	$LC81, 100(%esp)
	movl	$15, 96(%esp)
	movl	$16, 92(%esp)
	movl	$17, 88(%esp)
	movl	$LC81, 84(%esp)
	movl	$LC76, 80(%esp)
	movl	$15, 76(%esp)
	movl	$16, 72(%esp)
	movl	$17, 68(%esp)
	movl	$LC76, 64(%esp)
	movl	$LC76, 60(%esp)
	movl	$169, 56(%esp)
	movl	$170, 52(%esp)
	movl	$171, 48(%esp)
	movl	$LC78, 44(%esp)
	movl	$LC82, 40(%esp)
	movl	$169, 36(%esp)
	movl	$170, 32(%esp)
	movl	$171, 28(%esp)
	movl	$LC82, 24(%esp)
	movl	$LC78, 20(%esp)
	movl	$169, 16(%esp)
	movl	$170, 12(%esp)
	movl	$171, 8(%esp)
	movl	$LC78, 4(%esp)
	movl	$LC78, (%esp)
	call	__Z33runTestOpt07_Type2_strncmp_BeforePKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj
	movl	$0, 196(%esp)
	movl	$1, 192(%esp)
	movl	$2, 188(%esp)
	movl	$LC74, 184(%esp)
	movl	$LC74, 180(%esp)
	movl	$2, 176(%esp)
	movl	$3, 172(%esp)
	movl	$4, 168(%esp)
	movl	$LC75, 164(%esp)
	movl	$LC80, 160(%esp)
	movl	$2, 156(%esp)
	movl	$3, 152(%esp)
	movl	$4, 148(%esp)
	movl	$LC80, 144(%esp)
	movl	$LC75, 140(%esp)
	movl	$2, 136(%esp)
	movl	$3, 132(%esp)
	movl	$4, 128(%esp)
	movl	$LC75, 124(%esp)
	movl	$LC75, 120(%esp)
	movl	$15, 116(%esp)
	movl	$16, 112(%esp)
	movl	$17, 108(%esp)
	movl	$LC76, 104(%esp)
	movl	$LC81, 100(%esp)
	movl	$15, 96(%esp)
	movl	$16, 92(%esp)
	movl	$17, 88(%esp)
	movl	$LC81, 84(%esp)
	movl	$LC76, 80(%esp)
	movl	$15, 76(%esp)
	movl	$16, 72(%esp)
	movl	$17, 68(%esp)
	movl	$LC76, 64(%esp)
	movl	$LC76, 60(%esp)
	movl	$169, 56(%esp)
	movl	$170, 52(%esp)
	movl	$171, 48(%esp)
	movl	$LC78, 44(%esp)
	movl	$LC82, 40(%esp)
	movl	$169, 36(%esp)
	movl	$170, 32(%esp)
	movl	$171, 28(%esp)
	movl	$LC82, 24(%esp)
	movl	$LC78, 20(%esp)
	movl	$169, 16(%esp)
	movl	$170, 12(%esp)
	movl	$171, 8(%esp)
	movl	$LC78, 4(%esp)
	movl	$LC78, (%esp)
	call	__Z32runTestOpt07_Type2_strncmp_AfterPKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj
	addl	$220, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3214:
	.p2align 4,,15
	.globl	__Z33runTestOpt07_Type2_strncmp_BeforePKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj
	.def	__Z33runTestOpt07_Type2_strncmp_BeforePKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj;	.scl	2;	.type	32;	.endef
__Z33runTestOpt07_Type2_strncmp_BeforePKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj:
LFB3215:
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
	xorl	%ebx, %ebx
	subl	$236, %esp
	.cfi_def_cfa_offset 256
	movl	256(%esp), %eax
	movl	%eax, 20(%esp)
	movl	260(%esp), %eax
	movl	%eax, 24(%esp)
	movl	264(%esp), %eax
	movl	%eax, 88(%esp)
	movl	268(%esp), %eax
	movl	%eax, 92(%esp)
	movl	272(%esp), %eax
	movl	%eax, 96(%esp)
	movl	276(%esp), %eax
	movl	%eax, 28(%esp)
	movl	280(%esp), %eax
	movl	%eax, 32(%esp)
	movl	284(%esp), %eax
	movl	%eax, 100(%esp)
	movl	288(%esp), %eax
	movl	%eax, 104(%esp)
	movl	292(%esp), %eax
	movl	%eax, 108(%esp)
	movl	296(%esp), %eax
	movl	%eax, 36(%esp)
	movl	300(%esp), %eax
	movl	%eax, 40(%esp)
	movl	304(%esp), %eax
	movl	%eax, 112(%esp)
	movl	308(%esp), %eax
	movl	%eax, 116(%esp)
	movl	312(%esp), %eax
	movl	%eax, 120(%esp)
	movl	316(%esp), %eax
	movl	%eax, 44(%esp)
	movl	320(%esp), %eax
	movl	%eax, 48(%esp)
	movl	324(%esp), %eax
	movl	%eax, 124(%esp)
	movl	328(%esp), %eax
	movl	%eax, 128(%esp)
	movl	332(%esp), %eax
	movl	%eax, 132(%esp)
	movl	336(%esp), %eax
	movl	%eax, 52(%esp)
	movl	340(%esp), %eax
	movl	%eax, 56(%esp)
	movl	344(%esp), %eax
	movl	%eax, 136(%esp)
	movl	348(%esp), %eax
	movl	%eax, 140(%esp)
	movl	352(%esp), %eax
	movl	%eax, 144(%esp)
	movl	356(%esp), %eax
	movl	%eax, 60(%esp)
	movl	360(%esp), %eax
	movl	%eax, 64(%esp)
	movl	364(%esp), %eax
	movl	%eax, 148(%esp)
	movl	368(%esp), %eax
	movl	%eax, 152(%esp)
	movl	372(%esp), %eax
	movl	%eax, 156(%esp)
	movl	376(%esp), %eax
	movl	%eax, 68(%esp)
	movl	380(%esp), %eax
	movl	%eax, 72(%esp)
	movl	384(%esp), %eax
	movl	416(%esp), %ebp
	movl	436(%esp), %edi
	movl	440(%esp), %esi
	movl	%eax, 160(%esp)
	movl	388(%esp), %eax
	movl	%eax, 164(%esp)
	movl	392(%esp), %eax
	movl	%eax, 168(%esp)
	movl	396(%esp), %eax
	movl	%eax, 76(%esp)
	movl	400(%esp), %eax
	movl	%eax, 80(%esp)
	movl	404(%esp), %eax
	movl	%eax, 172(%esp)
	movl	408(%esp), %eax
	movl	%eax, 176(%esp)
	movl	412(%esp), %eax
	movl	%eax, 180(%esp)
	movl	420(%esp), %eax
	movl	%eax, 84(%esp)
	movl	424(%esp), %eax
	movl	%eax, 184(%esp)
	movl	428(%esp), %eax
	movl	%eax, 188(%esp)
	movl	432(%esp), %eax
	movl	%eax, 192(%esp)
	movl	444(%esp), %eax
	movl	%eax, 196(%esp)
	movl	448(%esp), %eax
	movl	%eax, 200(%esp)
	movl	452(%esp), %eax
	movl	%eax, 204(%esp)
	movl	$LC11, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 208(%esp)
	movl	%edx, 212(%esp)
	.p2align 4,,7
L1230:
	movl	88(%esp), %eax
	movl	20(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	24(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	92(%esp), %ecx
	movl	20(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	20(%esp), %edx
	movl	96(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	100(%esp), %eax
	movl	28(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	32(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	104(%esp), %edx
	movl	28(%esp), %ecx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	28(%esp), %ecx
	movl	108(%esp), %edx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	112(%esp), %eax
	movl	36(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	40(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	116(%esp), %ecx
	movl	36(%esp), %edx
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	36(%esp), %edx
	movl	120(%esp), %ecx
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	124(%esp), %eax
	movl	44(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	48(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	128(%esp), %edx
	movl	44(%esp), %ecx
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	44(%esp), %ecx
	movl	132(%esp), %edx
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	136(%esp), %eax
	movl	52(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	56(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	140(%esp), %ecx
	movl	52(%esp), %edx
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	52(%esp), %edx
	movl	144(%esp), %ecx
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	148(%esp), %eax
	movl	60(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	64(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	152(%esp), %edx
	movl	60(%esp), %ecx
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	60(%esp), %ecx
	movl	156(%esp), %edx
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	160(%esp), %eax
	movl	68(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	72(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	164(%esp), %ecx
	movl	68(%esp), %edx
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	68(%esp), %edx
	movl	168(%esp), %ecx
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	172(%esp), %eax
	movl	76(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	80(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	176(%esp), %edx
	movl	76(%esp), %ecx
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	76(%esp), %ecx
	movl	180(%esp), %edx
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	184(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 12(%esp)
	movl	84(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	188(%esp), %edx
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	192(%esp), %ecx
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	196(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	200(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	204(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	cmpl	$1000000, %ebx
	jne	L1230
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	208(%esp), %eax
	sbbl	212(%esp), %edx
	movl	%eax, 216(%esp)
	movl	%edx, 220(%esp)
	fildq	216(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 256(%esp)
	addl	$236, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3215:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strncmp_AfterPKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj
	.def	__Z32runTestOpt07_Type2_strncmp_AfterPKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strncmp_AfterPKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj:
LFB3216:
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
	xorl	%ebx, %ebx
	subl	$236, %esp
	.cfi_def_cfa_offset 256
	movl	256(%esp), %eax
	movl	%eax, 20(%esp)
	movl	260(%esp), %eax
	movl	%eax, 24(%esp)
	movl	264(%esp), %eax
	movl	%eax, 88(%esp)
	movl	268(%esp), %eax
	movl	%eax, 92(%esp)
	movl	272(%esp), %eax
	movl	%eax, 96(%esp)
	movl	276(%esp), %eax
	movl	%eax, 28(%esp)
	movl	280(%esp), %eax
	movl	%eax, 32(%esp)
	movl	284(%esp), %eax
	movl	%eax, 100(%esp)
	movl	288(%esp), %eax
	movl	%eax, 104(%esp)
	movl	292(%esp), %eax
	movl	%eax, 108(%esp)
	movl	296(%esp), %eax
	movl	%eax, 36(%esp)
	movl	300(%esp), %eax
	movl	%eax, 40(%esp)
	movl	304(%esp), %eax
	movl	%eax, 112(%esp)
	movl	308(%esp), %eax
	movl	%eax, 116(%esp)
	movl	312(%esp), %eax
	movl	%eax, 120(%esp)
	movl	316(%esp), %eax
	movl	%eax, 44(%esp)
	movl	320(%esp), %eax
	movl	%eax, 48(%esp)
	movl	324(%esp), %eax
	movl	%eax, 124(%esp)
	movl	328(%esp), %eax
	movl	%eax, 128(%esp)
	movl	332(%esp), %eax
	movl	%eax, 132(%esp)
	movl	336(%esp), %eax
	movl	%eax, 52(%esp)
	movl	340(%esp), %eax
	movl	%eax, 56(%esp)
	movl	344(%esp), %eax
	movl	%eax, 136(%esp)
	movl	348(%esp), %eax
	movl	%eax, 140(%esp)
	movl	352(%esp), %eax
	movl	%eax, 144(%esp)
	movl	356(%esp), %eax
	movl	%eax, 60(%esp)
	movl	360(%esp), %eax
	movl	%eax, 64(%esp)
	movl	364(%esp), %eax
	movl	%eax, 148(%esp)
	movl	368(%esp), %eax
	movl	%eax, 152(%esp)
	movl	372(%esp), %eax
	movl	%eax, 156(%esp)
	movl	376(%esp), %eax
	movl	%eax, 68(%esp)
	movl	380(%esp), %eax
	movl	%eax, 72(%esp)
	movl	384(%esp), %eax
	movl	416(%esp), %ebp
	movl	436(%esp), %edi
	movl	440(%esp), %esi
	movl	%eax, 160(%esp)
	movl	388(%esp), %eax
	movl	%eax, 164(%esp)
	movl	392(%esp), %eax
	movl	%eax, 168(%esp)
	movl	396(%esp), %eax
	movl	%eax, 76(%esp)
	movl	400(%esp), %eax
	movl	%eax, 80(%esp)
	movl	404(%esp), %eax
	movl	%eax, 172(%esp)
	movl	408(%esp), %eax
	movl	%eax, 176(%esp)
	movl	412(%esp), %eax
	movl	%eax, 180(%esp)
	movl	420(%esp), %eax
	movl	%eax, 84(%esp)
	movl	424(%esp), %eax
	movl	%eax, 184(%esp)
	movl	428(%esp), %eax
	movl	%eax, 188(%esp)
	movl	432(%esp), %eax
	movl	%eax, 192(%esp)
	movl	444(%esp), %eax
	movl	%eax, 196(%esp)
	movl	448(%esp), %eax
	movl	%eax, 200(%esp)
	movl	452(%esp), %eax
	movl	%eax, 204(%esp)
	movl	$LC21, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 208(%esp)
	movl	%edx, 212(%esp)
	.p2align 4,,7
L1234:
	movl	88(%esp), %eax
	movl	20(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	24(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	92(%esp), %ecx
	movl	20(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	20(%esp), %edx
	movl	96(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	100(%esp), %eax
	movl	28(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	32(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	104(%esp), %edx
	movl	28(%esp), %ecx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	28(%esp), %ecx
	movl	108(%esp), %edx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	112(%esp), %eax
	movl	36(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	40(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	116(%esp), %ecx
	movl	36(%esp), %edx
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	36(%esp), %edx
	movl	120(%esp), %ecx
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	124(%esp), %eax
	movl	44(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	48(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	128(%esp), %edx
	movl	44(%esp), %ecx
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	44(%esp), %ecx
	movl	132(%esp), %edx
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	136(%esp), %eax
	movl	52(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	56(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	140(%esp), %ecx
	movl	52(%esp), %edx
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	52(%esp), %edx
	movl	144(%esp), %ecx
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	148(%esp), %eax
	movl	60(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	64(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	152(%esp), %edx
	movl	60(%esp), %ecx
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	60(%esp), %ecx
	movl	156(%esp), %edx
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	160(%esp), %eax
	movl	68(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	72(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	164(%esp), %ecx
	movl	68(%esp), %edx
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	68(%esp), %edx
	movl	168(%esp), %ecx
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	172(%esp), %eax
	movl	76(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	80(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	176(%esp), %edx
	movl	76(%esp), %ecx
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	76(%esp), %ecx
	movl	180(%esp), %edx
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	184(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 12(%esp)
	movl	84(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	188(%esp), %edx
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	192(%esp), %ecx
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	196(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	200(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	204(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	cmpl	$1000000, %ebx
	jne	L1234
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	208(%esp), %eax
	sbbl	212(%esp), %edx
	movl	%eax, 216(%esp)
	movl	%edx, 220(%esp)
	fildq	216(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 256(%esp)
	addl	$236, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3216:
	.section .rdata,"dr"
LC84:
	.ascii "Type2(strchr):\0"
LC85:
	.ascii "123123\0"
LC86:
	.ascii "1234567812345678\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt07_Type2_strchrv
	.def	__Z25runTestOpt07_Type2_strchrv;	.scl	2;	.type	32;	.endef
__Z25runTestOpt07_Type2_strchrv:
LFB3217:
	.cfi_startproc
	subl	$92, %esp
	.cfi_def_cfa_offset 96
	movl	$LC84, (%esp)
	call	_puts
	movl	$46, 76(%esp)
	movl	$51, 72(%esp)
	movl	$50, 68(%esp)
	movl	$49, 64(%esp)
	movl	$LC74, 60(%esp)
	movl	$46, 56(%esp)
	movl	$51, 52(%esp)
	movl	$50, 48(%esp)
	movl	$49, 44(%esp)
	movl	$LC85, 40(%esp)
	movl	$46, 36(%esp)
	movl	$56, 32(%esp)
	movl	$53, 28(%esp)
	movl	$49, 24(%esp)
	movl	$LC86, 20(%esp)
	movl	$46, 16(%esp)
	movl	$95, 12(%esp)
	movl	$33, 8(%esp)
	movl	$49, 4(%esp)
	movl	$LC78, (%esp)
	call	__Z32runTestOpt07_Type2_strchr_BeforePKcccccS0_ccccS0_ccccS0_cccc
	movl	$46, 76(%esp)
	movl	$51, 72(%esp)
	movl	$50, 68(%esp)
	movl	$49, 64(%esp)
	movl	$LC74, 60(%esp)
	movl	$46, 56(%esp)
	movl	$51, 52(%esp)
	movl	$50, 48(%esp)
	movl	$49, 44(%esp)
	movl	$LC85, 40(%esp)
	movl	$46, 36(%esp)
	movl	$56, 32(%esp)
	movl	$53, 28(%esp)
	movl	$49, 24(%esp)
	movl	$LC86, 20(%esp)
	movl	$46, 16(%esp)
	movl	$95, 12(%esp)
	movl	$33, 8(%esp)
	movl	$49, 4(%esp)
	movl	$LC78, (%esp)
	call	__Z31runTestOpt07_Type2_strchr_AfterPKcccccS0_ccccS0_ccccS0_cccc
	addl	$92, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3217:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strchr_BeforePKcccccS0_ccccS0_ccccS0_cccc
	.def	__Z32runTestOpt07_Type2_strchr_BeforePKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strchr_BeforePKcccccS0_ccccS0_ccccS0_cccc:
LFB3218:
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
	subl	$124, %esp
	.cfi_def_cfa_offset 144
	movl	152(%esp), %eax
	movl	156(%esp), %ecx
	movl	160(%esp), %edx
	movl	164(%esp), %esi
	movl	%eax, 32(%esp)
	movl	176(%esp), %eax
	movl	%ecx, 40(%esp)
	movl	180(%esp), %ecx
	movl	%edx, 44(%esp)
	movl	188(%esp), %edx
	movl	%esi, 24(%esp)
	movl	172(%esp), %esi
	movl	168(%esp), %edi
	movl	%eax, 56(%esp)
	movl	196(%esp), %eax
	movl	%ecx, 60(%esp)
	movl	200(%esp), %ecx
	movl	%esi, 52(%esp)
	movl	192(%esp), %esi
	movl	%edx, 64(%esp)
	movl	208(%esp), %edx
	movl	148(%esp), %ebx
	movl	%edi, 48(%esp)
	movl	144(%esp), %ebp
	movl	%esi, 68(%esp)
	movl	184(%esp), %edi
	movl	%eax, 72(%esp)
	movl	204(%esp), %esi
	movl	%ecx, 76(%esp)
	movsbl	%bl, %ebx
	movl	%edx, 80(%esp)
	movl	216(%esp), %ecx
	movl	220(%esp), %edx
	movl	212(%esp), %eax
	movl	$LC11, (%esp)
	movl	%ecx, 96(%esp)
	movl	%edx, 100(%esp)
	movl	%eax, 84(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%ebx, 28(%esp)
	movsbl	32(%esp), %ebx
	movl	%ebx, 36(%esp)
	movsbl	40(%esp), %ebx
	movl	%eax, 88(%esp)
	movsbl	84(%esp), %eax
	movl	%edx, 92(%esp)
	movl	%ebx, 40(%esp)
	movsbl	44(%esp), %ebx
	movl	%ebx, 32(%esp)
	movsbl	48(%esp), %ebx
	movl	%ebx, 44(%esp)
	movsbl	52(%esp), %ebx
	movl	%ebx, 48(%esp)
	movsbl	56(%esp), %ebx
	movl	%ebx, 52(%esp)
	movsbl	60(%esp), %ebx
	movl	%ebx, 56(%esp)
	movsbl	64(%esp), %ebx
	movl	%ebx, 60(%esp)
	movsbl	68(%esp), %ebx
	movl	%ebx, 64(%esp)
	movsbl	72(%esp), %ebx
	movl	%ebx, 68(%esp)
	movsbl	76(%esp), %ebx
	movl	%ebx, 72(%esp)
	movsbl	80(%esp), %ebx
	movl	%eax, 80(%esp)
	movsbl	96(%esp), %eax
	movl	%ebx, 76(%esp)
	xorl	%ebx, %ebx
	movl	%eax, 84(%esp)
	movsbl	100(%esp), %eax
	movl	%eax, 96(%esp)
	.p2align 4,,7
L1240:
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	44(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	48(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	52(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	56(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	68(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	96(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	cmpl	$1000000, %ebx
	jne	L1240
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	88(%esp), %eax
	sbbl	92(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 144(%esp)
	addl	$124, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3218:
	.p2align 4,,15
	.globl	__Z31runTestOpt07_Type2_strchr_AfterPKcccccS0_ccccS0_ccccS0_cccc
	.def	__Z31runTestOpt07_Type2_strchr_AfterPKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
__Z31runTestOpt07_Type2_strchr_AfterPKcccccS0_ccccS0_ccccS0_cccc:
LFB3219:
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
	subl	$124, %esp
	.cfi_def_cfa_offset 144
	movl	152(%esp), %eax
	movl	156(%esp), %ecx
	movl	160(%esp), %edx
	movl	164(%esp), %esi
	movl	%eax, 32(%esp)
	movl	176(%esp), %eax
	movl	%ecx, 40(%esp)
	movl	180(%esp), %ecx
	movl	%edx, 44(%esp)
	movl	188(%esp), %edx
	movl	%esi, 24(%esp)
	movl	172(%esp), %esi
	movl	168(%esp), %edi
	movl	%eax, 56(%esp)
	movl	196(%esp), %eax
	movl	%ecx, 60(%esp)
	movl	200(%esp), %ecx
	movl	%esi, 52(%esp)
	movl	192(%esp), %esi
	movl	%edx, 64(%esp)
	movl	208(%esp), %edx
	movl	148(%esp), %ebx
	movl	%edi, 48(%esp)
	movl	144(%esp), %ebp
	movl	%esi, 68(%esp)
	movl	184(%esp), %edi
	movl	%eax, 72(%esp)
	movl	204(%esp), %esi
	movl	%ecx, 76(%esp)
	movsbl	%bl, %ebx
	movl	%edx, 80(%esp)
	movl	216(%esp), %ecx
	movl	220(%esp), %edx
	movl	212(%esp), %eax
	movl	$LC21, (%esp)
	movl	%ecx, 96(%esp)
	movl	%edx, 100(%esp)
	movl	%eax, 84(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%ebx, 28(%esp)
	movsbl	32(%esp), %ebx
	movl	%ebx, 36(%esp)
	movsbl	40(%esp), %ebx
	movl	%eax, 88(%esp)
	movsbl	84(%esp), %eax
	movl	%edx, 92(%esp)
	movl	%ebx, 40(%esp)
	movsbl	44(%esp), %ebx
	movl	%ebx, 32(%esp)
	movsbl	48(%esp), %ebx
	movl	%ebx, 44(%esp)
	movsbl	52(%esp), %ebx
	movl	%ebx, 48(%esp)
	movsbl	56(%esp), %ebx
	movl	%ebx, 52(%esp)
	movsbl	60(%esp), %ebx
	movl	%ebx, 56(%esp)
	movsbl	64(%esp), %ebx
	movl	%ebx, 60(%esp)
	movsbl	68(%esp), %ebx
	movl	%ebx, 64(%esp)
	movsbl	72(%esp), %ebx
	movl	%ebx, 68(%esp)
	movsbl	76(%esp), %ebx
	movl	%ebx, 72(%esp)
	movsbl	80(%esp), %ebx
	movl	%eax, 80(%esp)
	movsbl	96(%esp), %eax
	movl	%ebx, 76(%esp)
	xorl	%ebx, %ebx
	movl	%eax, 84(%esp)
	movsbl	100(%esp), %eax
	movl	%eax, 96(%esp)
	.p2align 4,,7
L1244:
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	44(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	48(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	52(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	56(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	68(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	96(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	cmpl	$1000000, %ebx
	jne	L1244
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	88(%esp), %eax
	sbbl	92(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 144(%esp)
	addl	$124, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3219:
	.section .rdata,"dr"
LC87:
	.ascii "Type2(strrchr):\0"
	.text
	.p2align 4,,15
	.globl	__Z26runTestOpt07_Type2_strrchrv
	.def	__Z26runTestOpt07_Type2_strrchrv;	.scl	2;	.type	32;	.endef
__Z26runTestOpt07_Type2_strrchrv:
LFB3220:
	.cfi_startproc
	subl	$92, %esp
	.cfi_def_cfa_offset 96
	movl	$LC87, (%esp)
	call	_puts
	movl	$46, 76(%esp)
	movl	$51, 72(%esp)
	movl	$50, 68(%esp)
	movl	$49, 64(%esp)
	movl	$LC74, 60(%esp)
	movl	$46, 56(%esp)
	movl	$51, 52(%esp)
	movl	$50, 48(%esp)
	movl	$49, 44(%esp)
	movl	$LC85, 40(%esp)
	movl	$46, 36(%esp)
	movl	$56, 32(%esp)
	movl	$53, 28(%esp)
	movl	$49, 24(%esp)
	movl	$LC86, 20(%esp)
	movl	$46, 16(%esp)
	movl	$95, 12(%esp)
	movl	$33, 8(%esp)
	movl	$49, 4(%esp)
	movl	$LC78, (%esp)
	call	__Z33runTestOpt07_Type2_strrchr_BeforePKcccccS0_ccccS0_ccccS0_cccc
	movl	$46, 76(%esp)
	movl	$51, 72(%esp)
	movl	$50, 68(%esp)
	movl	$49, 64(%esp)
	movl	$LC74, 60(%esp)
	movl	$46, 56(%esp)
	movl	$51, 52(%esp)
	movl	$50, 48(%esp)
	movl	$49, 44(%esp)
	movl	$LC85, 40(%esp)
	movl	$46, 36(%esp)
	movl	$56, 32(%esp)
	movl	$53, 28(%esp)
	movl	$49, 24(%esp)
	movl	$LC86, 20(%esp)
	movl	$46, 16(%esp)
	movl	$95, 12(%esp)
	movl	$33, 8(%esp)
	movl	$49, 4(%esp)
	movl	$LC78, (%esp)
	call	__Z32runTestOpt07_Type2_strrchr_AfterPKcccccS0_ccccS0_ccccS0_cccc
	addl	$92, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3220:
	.p2align 4,,15
	.globl	__Z33runTestOpt07_Type2_strrchr_BeforePKcccccS0_ccccS0_ccccS0_cccc
	.def	__Z33runTestOpt07_Type2_strrchr_BeforePKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
__Z33runTestOpt07_Type2_strrchr_BeforePKcccccS0_ccccS0_ccccS0_cccc:
LFB3221:
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
	subl	$124, %esp
	.cfi_def_cfa_offset 144
	movl	152(%esp), %eax
	movl	156(%esp), %ecx
	movl	160(%esp), %edx
	movl	164(%esp), %esi
	movl	%eax, 32(%esp)
	movl	176(%esp), %eax
	movl	%ecx, 40(%esp)
	movl	180(%esp), %ecx
	movl	%edx, 44(%esp)
	movl	188(%esp), %edx
	movl	%esi, 24(%esp)
	movl	172(%esp), %esi
	movl	168(%esp), %edi
	movl	%eax, 56(%esp)
	movl	196(%esp), %eax
	movl	%ecx, 60(%esp)
	movl	200(%esp), %ecx
	movl	%esi, 52(%esp)
	movl	192(%esp), %esi
	movl	%edx, 64(%esp)
	movl	208(%esp), %edx
	movl	148(%esp), %ebx
	movl	%edi, 48(%esp)
	movl	144(%esp), %ebp
	movl	%esi, 68(%esp)
	movl	184(%esp), %edi
	movl	%eax, 72(%esp)
	movl	204(%esp), %esi
	movl	%ecx, 76(%esp)
	movsbl	%bl, %ebx
	movl	%edx, 80(%esp)
	movl	216(%esp), %ecx
	movl	220(%esp), %edx
	movl	212(%esp), %eax
	movl	$LC11, (%esp)
	movl	%ecx, 96(%esp)
	movl	%edx, 100(%esp)
	movl	%eax, 84(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%ebx, 28(%esp)
	movsbl	32(%esp), %ebx
	movl	%ebx, 36(%esp)
	movsbl	40(%esp), %ebx
	movl	%eax, 88(%esp)
	movsbl	84(%esp), %eax
	movl	%edx, 92(%esp)
	movl	%ebx, 40(%esp)
	movsbl	44(%esp), %ebx
	movl	%ebx, 32(%esp)
	movsbl	48(%esp), %ebx
	movl	%ebx, 44(%esp)
	movsbl	52(%esp), %ebx
	movl	%ebx, 48(%esp)
	movsbl	56(%esp), %ebx
	movl	%ebx, 52(%esp)
	movsbl	60(%esp), %ebx
	movl	%ebx, 56(%esp)
	movsbl	64(%esp), %ebx
	movl	%ebx, 60(%esp)
	movsbl	68(%esp), %ebx
	movl	%ebx, 64(%esp)
	movsbl	72(%esp), %ebx
	movl	%ebx, 68(%esp)
	movsbl	76(%esp), %ebx
	movl	%ebx, 72(%esp)
	movsbl	80(%esp), %ebx
	movl	%eax, 80(%esp)
	movsbl	96(%esp), %eax
	movl	%ebx, 76(%esp)
	xorl	%ebx, %ebx
	movl	%eax, 84(%esp)
	movsbl	100(%esp), %eax
	movl	%eax, 96(%esp)
	.p2align 4,,7
L1250:
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	44(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	48(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	52(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	56(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	68(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	96(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	cmpl	$1000000, %ebx
	jne	L1250
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	88(%esp), %eax
	sbbl	92(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 144(%esp)
	addl	$124, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3221:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strrchr_AfterPKcccccS0_ccccS0_ccccS0_cccc
	.def	__Z32runTestOpt07_Type2_strrchr_AfterPKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strrchr_AfterPKcccccS0_ccccS0_ccccS0_cccc:
LFB3222:
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
	subl	$124, %esp
	.cfi_def_cfa_offset 144
	movl	152(%esp), %eax
	movl	156(%esp), %ecx
	movl	160(%esp), %edx
	movl	164(%esp), %esi
	movl	%eax, 32(%esp)
	movl	176(%esp), %eax
	movl	%ecx, 40(%esp)
	movl	180(%esp), %ecx
	movl	%edx, 44(%esp)
	movl	188(%esp), %edx
	movl	%esi, 24(%esp)
	movl	172(%esp), %esi
	movl	168(%esp), %edi
	movl	%eax, 56(%esp)
	movl	196(%esp), %eax
	movl	%ecx, 60(%esp)
	movl	200(%esp), %ecx
	movl	%esi, 52(%esp)
	movl	192(%esp), %esi
	movl	%edx, 64(%esp)
	movl	208(%esp), %edx
	movl	148(%esp), %ebx
	movl	%edi, 48(%esp)
	movl	144(%esp), %ebp
	movl	%esi, 68(%esp)
	movl	184(%esp), %edi
	movl	%eax, 72(%esp)
	movl	204(%esp), %esi
	movl	%ecx, 76(%esp)
	movsbl	%bl, %ebx
	movl	%edx, 80(%esp)
	movl	216(%esp), %ecx
	movl	220(%esp), %edx
	movl	212(%esp), %eax
	movl	$LC21, (%esp)
	movl	%ecx, 96(%esp)
	movl	%edx, 100(%esp)
	movl	%eax, 84(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%ebx, 28(%esp)
	movsbl	32(%esp), %ebx
	movl	%ebx, 36(%esp)
	movsbl	40(%esp), %ebx
	movl	%eax, 88(%esp)
	movsbl	84(%esp), %eax
	movl	%edx, 92(%esp)
	movl	%ebx, 40(%esp)
	movsbl	44(%esp), %ebx
	movl	%ebx, 32(%esp)
	movsbl	48(%esp), %ebx
	movl	%ebx, 44(%esp)
	movsbl	52(%esp), %ebx
	movl	%ebx, 48(%esp)
	movsbl	56(%esp), %ebx
	movl	%ebx, 52(%esp)
	movsbl	60(%esp), %ebx
	movl	%ebx, 56(%esp)
	movsbl	64(%esp), %ebx
	movl	%ebx, 60(%esp)
	movsbl	68(%esp), %ebx
	movl	%ebx, 64(%esp)
	movsbl	72(%esp), %ebx
	movl	%ebx, 68(%esp)
	movsbl	76(%esp), %ebx
	movl	%ebx, 72(%esp)
	movsbl	80(%esp), %ebx
	movl	%eax, 80(%esp)
	movsbl	96(%esp), %eax
	movl	%ebx, 76(%esp)
	xorl	%ebx, %ebx
	movl	%eax, 84(%esp)
	movsbl	100(%esp), %eax
	movl	%eax, 96(%esp)
	.p2align 4,,7
L1254:
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	44(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	48(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	52(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	56(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	68(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	96(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	cmpl	$1000000, %ebx
	jne	L1254
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	88(%esp), %eax
	sbbl	92(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 144(%esp)
	addl	$124, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3222:
	.section .rdata,"dr"
LC88:
	.ascii "Type2(strstr):\0"
LC89:
	.ascii ".\0"
LC90:
	.ascii "23\0"
LC91:
	.ascii "1x\0"
LC92:
	.ascii "12\0"
LC93:
	.ascii "234567812345678\0"
LC94:
	.ascii "7x\0"
LC95:
	.ascii "678\0"
LC96:
	.ascii "78\0"
LC97:
	.ascii "8\0"
LC98:
	.ascii "1234567812345678x\0"
	.align 4
LC99:
	.ascii "!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980\0"
	.align 4
LC100:
	.ascii "ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&(.\0"
	.align 4
LC101:
	.ascii "ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&(\0"
LC102:
	.ascii "ABCDEFGHIJKLMNOPx\0"
LC103:
	.ascii "ABCDEFGHIJKLMNOx\0"
LC104:
	.ascii "ABCDEFGHIJKLMNOPQ\0"
LC105:
	.ascii "ABCDEFGHIJKLMNOP\0"
LC106:
	.ascii "AB\0"
LC107:
	.ascii "A\0"
LC108:
	.ascii "1234567980!abcdefx\0"
LC109:
	.ascii "1234567980!abcdx\0"
LC110:
	.ascii "1234567980!abcdef\0"
LC111:
	.ascii "1234567980!abcde\0"
	.align 4
LC112:
	.ascii "1111222233334444555566667777888899990000!1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt07_Type2_strstrv
	.def	__Z25runTestOpt07_Type2_strstrv;	.scl	2;	.type	32;	.endef
__Z25runTestOpt07_Type2_strstrv:
LFB3223:
	.cfi_startproc
	subl	$188, %esp
	.cfi_def_cfa_offset 192
	movl	$LC88, (%esp)
	call	_puts
	movl	$LC74, 164(%esp)
	movl	$LC89, 160(%esp)
	movl	$LC74, 156(%esp)
	movl	$LC74, 152(%esp)
	movl	$LC89, 148(%esp)
	movl	$LC90, 144(%esp)
	movl	$LC91, 140(%esp)
	movl	$LC92, 136(%esp)
	movl	$LC40, 132(%esp)
	movl	$LC85, 128(%esp)
	movl	$LC74, 124(%esp)
	movl	$LC89, 120(%esp)
	movl	$LC93, 116(%esp)
	movl	$LC94, 112(%esp)
	movl	$LC95, 108(%esp)
	movl	$LC96, 104(%esp)
	movl	$LC97, 100(%esp)
	movl	$LC98, 96(%esp)
	movl	$LC86, 92(%esp)
	movl	$LC91, 88(%esp)
	movl	$LC92, 84(%esp)
	movl	$LC40, 80(%esp)
	movl	$LC86, 76(%esp)
	movl	$LC74, 72(%esp)
	movl	$LC89, 68(%esp)
	movl	$LC99, 64(%esp)
	movl	$LC100, 60(%esp)
	movl	$LC101, 56(%esp)
	movl	$LC102, 52(%esp)
	movl	$LC103, 48(%esp)
	movl	$LC104, 44(%esp)
	movl	$LC105, 40(%esp)
	movl	$LC106, 36(%esp)
	movl	$LC107, 32(%esp)
	movl	$LC108, 28(%esp)
	movl	$LC109, 24(%esp)
	movl	$LC110, 20(%esp)
	movl	$LC111, 16(%esp)
	movl	$LC91, 12(%esp)
	movl	$LC92, 8(%esp)
	movl	$LC40, 4(%esp)
	movl	$LC112, (%esp)
	call	__Z32runTestOpt07_Type2_strstr_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	movl	$LC74, 164(%esp)
	movl	$LC89, 160(%esp)
	movl	$LC74, 156(%esp)
	movl	$LC74, 152(%esp)
	movl	$LC89, 148(%esp)
	movl	$LC90, 144(%esp)
	movl	$LC91, 140(%esp)
	movl	$LC92, 136(%esp)
	movl	$LC40, 132(%esp)
	movl	$LC85, 128(%esp)
	movl	$LC74, 124(%esp)
	movl	$LC89, 120(%esp)
	movl	$LC93, 116(%esp)
	movl	$LC94, 112(%esp)
	movl	$LC95, 108(%esp)
	movl	$LC96, 104(%esp)
	movl	$LC97, 100(%esp)
	movl	$LC98, 96(%esp)
	movl	$LC86, 92(%esp)
	movl	$LC91, 88(%esp)
	movl	$LC92, 84(%esp)
	movl	$LC40, 80(%esp)
	movl	$LC86, 76(%esp)
	movl	$LC74, 72(%esp)
	movl	$LC89, 68(%esp)
	movl	$LC99, 64(%esp)
	movl	$LC100, 60(%esp)
	movl	$LC101, 56(%esp)
	movl	$LC102, 52(%esp)
	movl	$LC103, 48(%esp)
	movl	$LC104, 44(%esp)
	movl	$LC105, 40(%esp)
	movl	$LC106, 36(%esp)
	movl	$LC107, 32(%esp)
	movl	$LC108, 28(%esp)
	movl	$LC109, 24(%esp)
	movl	$LC110, 20(%esp)
	movl	$LC111, 16(%esp)
	movl	$LC91, 12(%esp)
	movl	$LC92, 8(%esp)
	movl	$LC40, 4(%esp)
	movl	$LC112, (%esp)
	call	__Z32runTestOpt07_Type2_strstr_After1PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	movl	$LC74, 164(%esp)
	movl	$LC89, 160(%esp)
	movl	$LC74, 156(%esp)
	movl	$LC74, 152(%esp)
	movl	$LC89, 148(%esp)
	movl	$LC90, 144(%esp)
	movl	$LC91, 140(%esp)
	movl	$LC92, 136(%esp)
	movl	$LC40, 132(%esp)
	movl	$LC85, 128(%esp)
	movl	$LC74, 124(%esp)
	movl	$LC89, 120(%esp)
	movl	$LC93, 116(%esp)
	movl	$LC94, 112(%esp)
	movl	$LC95, 108(%esp)
	movl	$LC96, 104(%esp)
	movl	$LC97, 100(%esp)
	movl	$LC98, 96(%esp)
	movl	$LC86, 92(%esp)
	movl	$LC91, 88(%esp)
	movl	$LC92, 84(%esp)
	movl	$LC40, 80(%esp)
	movl	$LC86, 76(%esp)
	movl	$LC74, 72(%esp)
	movl	$LC89, 68(%esp)
	movl	$LC99, 64(%esp)
	movl	$LC100, 60(%esp)
	movl	$LC101, 56(%esp)
	movl	$LC102, 52(%esp)
	movl	$LC103, 48(%esp)
	movl	$LC104, 44(%esp)
	movl	$LC105, 40(%esp)
	movl	$LC106, 36(%esp)
	movl	$LC107, 32(%esp)
	movl	$LC108, 28(%esp)
	movl	$LC109, 24(%esp)
	movl	$LC110, 20(%esp)
	movl	$LC111, 16(%esp)
	movl	$LC91, 12(%esp)
	movl	$LC92, 8(%esp)
	movl	$LC40, 4(%esp)
	movl	$LC112, (%esp)
	call	__Z32runTestOpt07_Type2_strstr_After2PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	addl	$188, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3223:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strstr_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	.def	__Z32runTestOpt07_Type2_strstr_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strstr_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_:
LFB3224:
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
	xorl	%ebx, %ebx
	subl	$204, %esp
	.cfi_def_cfa_offset 224
	movl	228(%esp), %eax
	movl	224(%esp), %esi
	movl	%eax, 24(%esp)
	movl	232(%esp), %eax
	movl	%eax, 28(%esp)
	movl	236(%esp), %eax
	movl	%eax, 32(%esp)
	movl	240(%esp), %eax
	movl	%eax, 36(%esp)
	movl	244(%esp), %eax
	movl	%eax, 40(%esp)
	movl	248(%esp), %eax
	movl	%eax, 44(%esp)
	movl	252(%esp), %eax
	movl	%eax, 48(%esp)
	movl	256(%esp), %eax
	movl	%eax, 52(%esp)
	movl	260(%esp), %eax
	movl	%eax, 56(%esp)
	movl	264(%esp), %eax
	movl	%eax, 60(%esp)
	movl	268(%esp), %eax
	movl	%eax, 64(%esp)
	movl	272(%esp), %eax
	movl	%eax, 68(%esp)
	movl	276(%esp), %eax
	movl	%eax, 72(%esp)
	movl	280(%esp), %eax
	movl	%eax, 76(%esp)
	movl	284(%esp), %eax
	movl	300(%esp), %edi
	movl	352(%esp), %ebp
	movl	%eax, 80(%esp)
	movl	288(%esp), %eax
	movl	%eax, 84(%esp)
	movl	292(%esp), %eax
	movl	%eax, 88(%esp)
	movl	296(%esp), %eax
	movl	%eax, 92(%esp)
	movl	304(%esp), %eax
	movl	%eax, 96(%esp)
	movl	308(%esp), %eax
	movl	%eax, 100(%esp)
	movl	312(%esp), %eax
	movl	%eax, 104(%esp)
	movl	316(%esp), %eax
	movl	%eax, 108(%esp)
	movl	320(%esp), %eax
	movl	%eax, 112(%esp)
	movl	324(%esp), %eax
	movl	%eax, 116(%esp)
	movl	328(%esp), %eax
	movl	%eax, 120(%esp)
	movl	332(%esp), %eax
	movl	%eax, 124(%esp)
	movl	336(%esp), %eax
	movl	%eax, 128(%esp)
	movl	340(%esp), %eax
	movl	%eax, 132(%esp)
	movl	344(%esp), %eax
	movl	%eax, 136(%esp)
	movl	348(%esp), %eax
	movl	%eax, 140(%esp)
	movl	356(%esp), %eax
	movl	%eax, 144(%esp)
	movl	360(%esp), %eax
	movl	$LC11, (%esp)
	movl	%eax, 148(%esp)
	movl	364(%esp), %eax
	movl	%eax, 152(%esp)
	movl	368(%esp), %eax
	movl	%eax, 156(%esp)
	movl	372(%esp), %eax
	movl	%eax, 160(%esp)
	movl	376(%esp), %eax
	movl	%eax, 164(%esp)
	movl	380(%esp), %eax
	movl	%eax, 20(%esp)
	movl	384(%esp), %eax
	movl	%eax, 168(%esp)
	movl	388(%esp), %eax
	movl	%eax, 172(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 176(%esp)
	movl	%edx, 180(%esp)
	.p2align 4,,7
L1260:
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	44(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	52(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	68(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	88(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	92(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	96(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	100(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	104(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	108(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	112(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	116(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	120(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	124(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	128(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	132(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	136(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	140(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	144(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	148(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	152(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	156(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	160(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	164(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	168(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	172(%esp), %edx
	movl	20(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	cmpl	$1000000, %ebx
	jne	L1260
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	176(%esp), %eax
	sbbl	180(%esp), %edx
	movl	%eax, 184(%esp)
	movl	%edx, 188(%esp)
	fildq	184(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 224(%esp)
	addl	$204, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3224:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strstr_After1PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	.def	__Z32runTestOpt07_Type2_strstr_After1PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strstr_After1PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_:
LFB3225:
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
	xorl	%ebx, %ebx
	subl	$204, %esp
	.cfi_def_cfa_offset 224
	movl	228(%esp), %eax
	movl	224(%esp), %esi
	movl	%eax, 24(%esp)
	movl	232(%esp), %eax
	movl	%eax, 28(%esp)
	movl	236(%esp), %eax
	movl	%eax, 32(%esp)
	movl	240(%esp), %eax
	movl	%eax, 36(%esp)
	movl	244(%esp), %eax
	movl	%eax, 40(%esp)
	movl	248(%esp), %eax
	movl	%eax, 44(%esp)
	movl	252(%esp), %eax
	movl	%eax, 48(%esp)
	movl	256(%esp), %eax
	movl	%eax, 52(%esp)
	movl	260(%esp), %eax
	movl	%eax, 56(%esp)
	movl	264(%esp), %eax
	movl	%eax, 60(%esp)
	movl	268(%esp), %eax
	movl	%eax, 64(%esp)
	movl	272(%esp), %eax
	movl	%eax, 68(%esp)
	movl	276(%esp), %eax
	movl	%eax, 72(%esp)
	movl	280(%esp), %eax
	movl	%eax, 76(%esp)
	movl	284(%esp), %eax
	movl	300(%esp), %edi
	movl	352(%esp), %ebp
	movl	%eax, 80(%esp)
	movl	288(%esp), %eax
	movl	%eax, 84(%esp)
	movl	292(%esp), %eax
	movl	%eax, 88(%esp)
	movl	296(%esp), %eax
	movl	%eax, 92(%esp)
	movl	304(%esp), %eax
	movl	%eax, 96(%esp)
	movl	308(%esp), %eax
	movl	%eax, 100(%esp)
	movl	312(%esp), %eax
	movl	%eax, 104(%esp)
	movl	316(%esp), %eax
	movl	%eax, 108(%esp)
	movl	320(%esp), %eax
	movl	%eax, 112(%esp)
	movl	324(%esp), %eax
	movl	%eax, 116(%esp)
	movl	328(%esp), %eax
	movl	%eax, 120(%esp)
	movl	332(%esp), %eax
	movl	%eax, 124(%esp)
	movl	336(%esp), %eax
	movl	%eax, 128(%esp)
	movl	340(%esp), %eax
	movl	%eax, 132(%esp)
	movl	344(%esp), %eax
	movl	%eax, 136(%esp)
	movl	348(%esp), %eax
	movl	%eax, 140(%esp)
	movl	356(%esp), %eax
	movl	%eax, 144(%esp)
	movl	360(%esp), %eax
	movl	$LC13, (%esp)
	movl	%eax, 148(%esp)
	movl	364(%esp), %eax
	movl	%eax, 152(%esp)
	movl	368(%esp), %eax
	movl	%eax, 156(%esp)
	movl	372(%esp), %eax
	movl	%eax, 160(%esp)
	movl	376(%esp), %eax
	movl	%eax, 164(%esp)
	movl	380(%esp), %eax
	movl	%eax, 20(%esp)
	movl	384(%esp), %eax
	movl	%eax, 168(%esp)
	movl	388(%esp), %eax
	movl	%eax, 172(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 176(%esp)
	movl	%edx, 180(%esp)
	.p2align 4,,7
L1264:
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	44(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	52(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	68(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	88(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	92(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	96(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	100(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	104(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	108(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	112(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	116(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	120(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	124(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	128(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	132(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	136(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	140(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	144(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	148(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	152(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	156(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	160(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	164(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	168(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	172(%esp), %edx
	movl	20(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	cmpl	$1000000, %ebx
	jne	L1264
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	176(%esp), %eax
	sbbl	180(%esp), %edx
	movl	%eax, 184(%esp)
	movl	%edx, 188(%esp)
	fildq	184(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 224(%esp)
	addl	$204, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3225:
	.section .rdata,"dr"
LC113:
	.ascii "  After2(bm).. \0"
	.text
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strstr_After2PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	.def	__Z32runTestOpt07_Type2_strstr_After2PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strstr_After2PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_:
LFB3226:
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
	xorl	%ebx, %ebx
	subl	$204, %esp
	.cfi_def_cfa_offset 224
	movl	228(%esp), %eax
	movl	224(%esp), %esi
	movl	%eax, 24(%esp)
	movl	232(%esp), %eax
	movl	%eax, 28(%esp)
	movl	236(%esp), %eax
	movl	%eax, 32(%esp)
	movl	240(%esp), %eax
	movl	%eax, 36(%esp)
	movl	244(%esp), %eax
	movl	%eax, 40(%esp)
	movl	248(%esp), %eax
	movl	%eax, 44(%esp)
	movl	252(%esp), %eax
	movl	%eax, 48(%esp)
	movl	256(%esp), %eax
	movl	%eax, 52(%esp)
	movl	260(%esp), %eax
	movl	%eax, 56(%esp)
	movl	264(%esp), %eax
	movl	%eax, 60(%esp)
	movl	268(%esp), %eax
	movl	%eax, 64(%esp)
	movl	272(%esp), %eax
	movl	%eax, 68(%esp)
	movl	276(%esp), %eax
	movl	%eax, 72(%esp)
	movl	280(%esp), %eax
	movl	%eax, 76(%esp)
	movl	284(%esp), %eax
	movl	300(%esp), %edi
	movl	352(%esp), %ebp
	movl	%eax, 80(%esp)
	movl	288(%esp), %eax
	movl	%eax, 84(%esp)
	movl	292(%esp), %eax
	movl	%eax, 88(%esp)
	movl	296(%esp), %eax
	movl	%eax, 92(%esp)
	movl	304(%esp), %eax
	movl	%eax, 96(%esp)
	movl	308(%esp), %eax
	movl	%eax, 100(%esp)
	movl	312(%esp), %eax
	movl	%eax, 104(%esp)
	movl	316(%esp), %eax
	movl	%eax, 108(%esp)
	movl	320(%esp), %eax
	movl	%eax, 112(%esp)
	movl	324(%esp), %eax
	movl	%eax, 116(%esp)
	movl	328(%esp), %eax
	movl	%eax, 120(%esp)
	movl	332(%esp), %eax
	movl	%eax, 124(%esp)
	movl	336(%esp), %eax
	movl	%eax, 128(%esp)
	movl	340(%esp), %eax
	movl	%eax, 132(%esp)
	movl	344(%esp), %eax
	movl	%eax, 136(%esp)
	movl	348(%esp), %eax
	movl	%eax, 140(%esp)
	movl	356(%esp), %eax
	movl	%eax, 144(%esp)
	movl	360(%esp), %eax
	movl	$LC113, (%esp)
	movl	%eax, 148(%esp)
	movl	364(%esp), %eax
	movl	%eax, 152(%esp)
	movl	368(%esp), %eax
	movl	%eax, 156(%esp)
	movl	372(%esp), %eax
	movl	%eax, 160(%esp)
	movl	376(%esp), %eax
	movl	%eax, 164(%esp)
	movl	380(%esp), %eax
	movl	%eax, 20(%esp)
	movl	384(%esp), %eax
	movl	%eax, 168(%esp)
	movl	388(%esp), %eax
	movl	%eax, 172(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 176(%esp)
	movl	%edx, 180(%esp)
	.p2align 4,,7
L1268:
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	44(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	52(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	68(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	88(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	92(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	96(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	100(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	104(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	108(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	112(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	116(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	120(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	124(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	128(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	132(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	136(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	140(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	144(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	148(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	152(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	156(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	160(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	164(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	168(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	172(%esp), %edx
	movl	20(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	cmpl	$1000000, %ebx
	jne	L1268
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	176(%esp), %eax
	sbbl	180(%esp), %edx
	movl	%eax, 184(%esp)
	movl	%edx, 188(%esp)
	fildq	184(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 224(%esp)
	addl	$204, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3226:
	.section .rdata,"dr"
LC114:
	.ascii "Type2(strcpy):\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt07_Type2_strcpyv
	.def	__Z25runTestOpt07_Type2_strcpyv;	.scl	2;	.type	32;	.endef
__Z25runTestOpt07_Type2_strcpyv:
LFB3227:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$1064, %esp
	.cfi_def_cfa_offset 1072
	leal	32(%esp), %ebx
	movl	$LC114, (%esp)
	call	_puts
	movl	%ebx, (%esp)
	movl	$LC74, 20(%esp)
	movl	$LC75, 16(%esp)
	movl	$LC76, 12(%esp)
	movl	$LC77, 8(%esp)
	movl	$LC78, 4(%esp)
	call	__Z32runTestOpt07_Type2_strcpy_BeforePcPKcS1_S1_S1_S1_
	movl	%ebx, (%esp)
	movl	$LC74, 20(%esp)
	movl	$LC75, 16(%esp)
	movl	$LC76, 12(%esp)
	movl	$LC77, 8(%esp)
	movl	$LC78, 4(%esp)
	call	__Z31runTestOpt07_Type2_strcpy_AfterPcPKcS1_S1_S1_S1_
	addl	$1064, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3227:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strcpy_BeforePcPKcS1_S1_S1_S1_
	.def	__Z32runTestOpt07_Type2_strcpy_BeforePcPKcS1_S1_S1_S1_;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strcpy_BeforePcPKcS1_S1_S1_S1_:
LFB3228:
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
	xorl	%ebx, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	92(%esp), %eax
	movl	$LC11, (%esp)
	movl	80(%esp), %esi
	movl	84(%esp), %ebp
	movl	88(%esp), %edi
	movl	%eax, 20(%esp)
	movl	96(%esp), %eax
	movl	%eax, 24(%esp)
	movl	100(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1274:
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	call	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc
	movl	%ebx, (%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc
	movl	20(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc
	cmpl	$1000000, %ebx
	jne	L1274
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 80(%esp)
	addl	$60, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3228:
	.p2align 4,,15
	.globl	__Z31runTestOpt07_Type2_strcpy_AfterPcPKcS1_S1_S1_S1_
	.def	__Z31runTestOpt07_Type2_strcpy_AfterPcPKcS1_S1_S1_S1_;	.scl	2;	.type	32;	.endef
__Z31runTestOpt07_Type2_strcpy_AfterPcPKcS1_S1_S1_S1_:
LFB3229:
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
	xorl	%ebx, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	92(%esp), %eax
	movl	$LC21, (%esp)
	movl	80(%esp), %esi
	movl	84(%esp), %ebp
	movl	88(%esp), %edi
	movl	%eax, 20(%esp)
	movl	96(%esp), %eax
	movl	%eax, 24(%esp)
	movl	100(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1278:
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	call	__Z28testOpt07_Type2_strcpy_AfteriPcPKc
	movl	%ebx, (%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	__Z28testOpt07_Type2_strcpy_AfteriPcPKc
	movl	20(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strcpy_AfteriPcPKc
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strcpy_AfteriPcPKc
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strcpy_AfteriPcPKc
	cmpl	$1000000, %ebx
	jne	L1278
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 80(%esp)
	addl	$60, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3229:
	.section .rdata,"dr"
LC115:
	.ascii "Type2(strncpy):\0"
	.text
	.p2align 4,,15
	.globl	__Z26runTestOpt07_Type2_strncpyv
	.def	__Z26runTestOpt07_Type2_strncpyv;	.scl	2;	.type	32;	.endef
__Z26runTestOpt07_Type2_strncpyv:
LFB3230:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$1128, %esp
	.cfi_def_cfa_offset 1136
	leal	96(%esp), %ebx
	movl	$LC115, (%esp)
	call	_puts
	movl	%ebx, (%esp)
	movl	$0, 80(%esp)
	movl	$1, 76(%esp)
	movl	$2, 72(%esp)
	movl	$LC74, 68(%esp)
	movl	$2, 64(%esp)
	movl	$3, 60(%esp)
	movl	$4, 56(%esp)
	movl	$LC75, 52(%esp)
	movl	$15, 48(%esp)
	movl	$16, 44(%esp)
	movl	$17, 40(%esp)
	movl	$LC76, 36(%esp)
	movl	$16, 32(%esp)
	movl	$17, 28(%esp)
	movl	$18, 24(%esp)
	movl	$LC77, 20(%esp)
	movl	$169, 16(%esp)
	movl	$170, 12(%esp)
	movl	$171, 8(%esp)
	movl	$LC78, 4(%esp)
	call	__Z33runTestOpt07_Type2_strncpy_BeforePcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj
	movl	%ebx, (%esp)
	movl	$0, 80(%esp)
	movl	$1, 76(%esp)
	movl	$2, 72(%esp)
	movl	$LC74, 68(%esp)
	movl	$2, 64(%esp)
	movl	$3, 60(%esp)
	movl	$4, 56(%esp)
	movl	$LC75, 52(%esp)
	movl	$15, 48(%esp)
	movl	$16, 44(%esp)
	movl	$17, 40(%esp)
	movl	$LC76, 36(%esp)
	movl	$16, 32(%esp)
	movl	$17, 28(%esp)
	movl	$18, 24(%esp)
	movl	$LC77, 20(%esp)
	movl	$169, 16(%esp)
	movl	$170, 12(%esp)
	movl	$171, 8(%esp)
	movl	$LC78, 4(%esp)
	call	__Z32runTestOpt07_Type2_strncpy_AfterPcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj
	addl	$1128, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3230:
	.p2align 4,,15
	.globl	__Z33runTestOpt07_Type2_strncpy_BeforePcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj
	.def	__Z33runTestOpt07_Type2_strncpy_BeforePcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj;	.scl	2;	.type	32;	.endef
__Z33runTestOpt07_Type2_strncpy_BeforePcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj:
LFB3231:
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
	xorl	%ebx, %ebx
	subl	$124, %esp
	.cfi_def_cfa_offset 144
	movl	148(%esp), %eax
	movl	144(%esp), %esi
	movl	196(%esp), %ebp
	movl	%eax, 24(%esp)
	movl	152(%esp), %eax
	movl	%eax, 36(%esp)
	movl	156(%esp), %eax
	movl	%eax, 40(%esp)
	movl	160(%esp), %eax
	movl	%eax, 44(%esp)
	movl	164(%esp), %eax
	movl	%eax, 28(%esp)
	movl	168(%esp), %eax
	movl	%eax, 48(%esp)
	movl	172(%esp), %eax
	movl	%eax, 52(%esp)
	movl	176(%esp), %eax
	movl	%eax, 56(%esp)
	movl	180(%esp), %eax
	movl	%eax, 32(%esp)
	movl	184(%esp), %eax
	movl	%eax, 60(%esp)
	movl	188(%esp), %eax
	movl	%eax, 64(%esp)
	movl	192(%esp), %eax
	movl	%eax, 68(%esp)
	movl	200(%esp), %eax
	movl	%eax, 72(%esp)
	movl	204(%esp), %eax
	movl	%eax, 76(%esp)
	movl	208(%esp), %eax
	movl	$LC11, (%esp)
	movl	212(%esp), %edi
	movl	%eax, 80(%esp)
	movl	216(%esp), %eax
	movl	%eax, 84(%esp)
	movl	220(%esp), %eax
	movl	%eax, 88(%esp)
	movl	224(%esp), %eax
	movl	%eax, 92(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 96(%esp)
	movl	%edx, 100(%esp)
	.p2align 4,,7
L1284:
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	movl	24(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	40(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	44(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	movl	28(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	52(%esp), %edx
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	56(%esp), %ecx
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	movl	32(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	64(%esp), %edx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	68(%esp), %ecx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	88(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	92(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	cmpl	$1000000, %ebx
	jne	L1284
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	96(%esp), %eax
	sbbl	100(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 144(%esp)
	addl	$124, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3231:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strncpy_AfterPcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj
	.def	__Z32runTestOpt07_Type2_strncpy_AfterPcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strncpy_AfterPcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj:
LFB3232:
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
	xorl	%ebx, %ebx
	subl	$124, %esp
	.cfi_def_cfa_offset 144
	movl	148(%esp), %eax
	movl	144(%esp), %esi
	movl	196(%esp), %ebp
	movl	%eax, 24(%esp)
	movl	152(%esp), %eax
	movl	%eax, 36(%esp)
	movl	156(%esp), %eax
	movl	%eax, 40(%esp)
	movl	160(%esp), %eax
	movl	%eax, 44(%esp)
	movl	164(%esp), %eax
	movl	%eax, 28(%esp)
	movl	168(%esp), %eax
	movl	%eax, 48(%esp)
	movl	172(%esp), %eax
	movl	%eax, 52(%esp)
	movl	176(%esp), %eax
	movl	%eax, 56(%esp)
	movl	180(%esp), %eax
	movl	%eax, 32(%esp)
	movl	184(%esp), %eax
	movl	%eax, 60(%esp)
	movl	188(%esp), %eax
	movl	%eax, 64(%esp)
	movl	192(%esp), %eax
	movl	%eax, 68(%esp)
	movl	200(%esp), %eax
	movl	%eax, 72(%esp)
	movl	204(%esp), %eax
	movl	%eax, 76(%esp)
	movl	208(%esp), %eax
	movl	$LC21, (%esp)
	movl	212(%esp), %edi
	movl	%eax, 80(%esp)
	movl	216(%esp), %eax
	movl	%eax, 84(%esp)
	movl	220(%esp), %eax
	movl	%eax, 88(%esp)
	movl	224(%esp), %eax
	movl	%eax, 92(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 96(%esp)
	movl	%edx, 100(%esp)
	.p2align 4,,7
L1288:
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	movl	24(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	40(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	44(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	movl	28(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	52(%esp), %edx
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	56(%esp), %ecx
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	movl	32(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	64(%esp), %edx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	68(%esp), %ecx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	88(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	92(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	cmpl	$1000000, %ebx
	jne	L1288
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	96(%esp), %eax
	sbbl	100(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	$10, 144(%esp)
	addl	$124, %esp
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
	jmp	_putchar
	.cfi_endproc
LFE3232:
	.section .rdata,"dr"
LC116:
	.ascii "[Optimize Test 08]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt08v
	.def	__Z12runTestOpt08v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt08v:
LFB3233:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$LC8, (%esp)
	call	_puts
	movl	$LC116, (%esp)
	call	_puts
	call	__Z18runTestOpt08_Type1v
	call	__Z18runTestOpt08_Type2v
	.p2align 4,,5
	call	__Z18runTestOpt08_Type3v
	.p2align 4,,5
	call	__Z18runTestOpt08_Type4v
	.p2align 4,,5
	call	__Z18runTestOpt08_Type5v
	.p2align 4,,5
	call	__Z18runTestOpt08_Type6v
	.p2align 4,,5
	call	__Z18runTestOpt08_Type7v
	.p2align 4,,5
	call	__Z18runTestOpt08_Type8v
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z18runTestOpt08_Type9v
	.cfi_endproc
LFE3233:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type1_Beforeiiii
	.def	__Z25runTestOpt08_Type1_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type1_Beforeiiii:
LFB3235:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	88(%esp), %eax
	movl	$LC11, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	%eax, 24(%esp)
	movl	92(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1294:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type1_Beforei
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1294
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 84(%esp)
	movl	$LC12, 80(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3235:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type1_After1iiii
	.def	__Z25runTestOpt08_Type1_After1iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type1_After1iiii:
LFB3236:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	88(%esp), %eax
	movl	$LC13, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	%eax, 24(%esp)
	movl	92(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1298:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type1_After1i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type1_After1i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type1_After1i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1298
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 84(%esp)
	movl	$LC12, 80(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3236:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type1_After2iiii
	.def	__Z25runTestOpt08_Type1_After2iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type1_After2iiii:
LFB3237:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	88(%esp), %eax
	movl	$LC14, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	%eax, 24(%esp)
	movl	92(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1302:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type1_After2i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type1_After2i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type1_After2i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1302
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 84(%esp)
	movl	$LC12, 80(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3237:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type1_After3iiii
	.def	__Z25runTestOpt08_Type1_After3iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type1_After3iiii:
LFB3238:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	88(%esp), %eax
	movl	$LC15, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	%eax, 24(%esp)
	movl	92(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1306:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type1_After3i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type1_After3i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type1_After3i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type1_After3i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1306
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 84(%esp)
	movl	$LC12, 80(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3238:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type2_Beforeiiii
	.def	__Z25runTestOpt08_Type2_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type2_Beforeiiii:
LFB3240:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	88(%esp), %eax
	movl	$LC11, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	%eax, 24(%esp)
	movl	92(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1310:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type2_Beforei
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1310
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 84(%esp)
	movl	$LC12, 80(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3240:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type2_After1iiii
	.def	__Z25runTestOpt08_Type2_After1iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type2_After1iiii:
LFB3241:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	88(%esp), %eax
	movl	$LC13, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	%eax, 24(%esp)
	movl	92(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1314:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type2_After1i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type2_After1i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type2_After1i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type2_After1i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1314
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 84(%esp)
	movl	$LC12, 80(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3241:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type2_After2iiii
	.def	__Z25runTestOpt08_Type2_After2iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type2_After2iiii:
LFB3242:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	88(%esp), %eax
	movl	$LC14, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	%eax, 24(%esp)
	movl	92(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1318:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type2_After2i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type2_After2i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type2_After2i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type2_After2i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1318
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 84(%esp)
	movl	$LC12, 80(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3242:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type2_After3iiii
	.def	__Z25runTestOpt08_Type2_After3iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type2_After3iiii:
LFB3243:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	88(%esp), %eax
	movl	$LC15, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	%eax, 24(%esp)
	movl	92(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1322:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type2_After3i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type2_After3i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type2_After3i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type2_After3i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1322
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 84(%esp)
	movl	$LC12, 80(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3243:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type3_Beforeiiii
	.def	__Z25runTestOpt08_Type3_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type3_Beforeiiii:
LFB3245:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	88(%esp), %eax
	movl	$LC11, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	%eax, 24(%esp)
	movl	92(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1326:
	movl	%edi, 4(%esp)
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type3_Beforeii
	movzbl	%al, %eax
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type3_Beforeii
	movzbl	%al, %eax
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1326
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 84(%esp)
	movl	$LC12, 80(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3245:
	.p2align 4,,15
	.globl	__Z24runTestOpt08_Type3_Afteriiii
	.def	__Z24runTestOpt08_Type3_Afteriiii;	.scl	2;	.type	32;	.endef
__Z24runTestOpt08_Type3_Afteriiii:
LFB3246:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	88(%esp), %eax
	movl	$LC13, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	%eax, 24(%esp)
	movl	92(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1330:
	movl	%edi, 4(%esp)
	movl	%ebp, (%esp)
	call	__Z21testOpt08_Type3_Afterii
	movzbl	%al, %eax
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z21testOpt08_Type3_Afterii
	movzbl	%al, %eax
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1330
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 84(%esp)
	movl	$LC12, 80(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3246:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type4_Beforeiiii
	.def	__Z25runTestOpt08_Type4_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type4_Beforeiiii:
LFB3248:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	88(%esp), %eax
	movl	$LC11, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	%eax, 24(%esp)
	movl	92(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1334:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type4_Beforei
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1334
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 84(%esp)
	movl	$LC12, 80(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3248:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type4_After1iiii
	.def	__Z25runTestOpt08_Type4_After1iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type4_After1iiii:
LFB3249:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	88(%esp), %eax
	movl	$LC13, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	%eax, 24(%esp)
	movl	92(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1338:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type4_After1i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type4_After1i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type4_After1i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type4_After1i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1338
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 84(%esp)
	movl	$LC12, 80(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3249:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type4_After2iiii
	.def	__Z25runTestOpt08_Type4_After2iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type4_After2iiii:
LFB3250:
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
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	88(%esp), %eax
	movl	$LC14, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	%eax, 24(%esp)
	movl	92(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1342:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type4_After2i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type4_After2i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type4_After2i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type4_After2i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1342
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 84(%esp)
	movl	$LC12, 80(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3250:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type5_Beforeiiii
	.def	__Z25runTestOpt08_Type5_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type5_Beforeiiii:
LFB3252:
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
	movl	112(%esp), %eax
	movl	$LC11, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1346:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type5_Beforei
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type5_Beforei
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1346
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3252:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type5_After1iiii
	.def	__Z25runTestOpt08_Type5_After1iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type5_After1iiii:
LFB3253:
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
	movl	112(%esp), %eax
	movl	$LC13, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1350:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After1i
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After1i
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type5_After1i
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After1i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After1i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After1i
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After1i
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After1i
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After1i
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After1i
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After1i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1350
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3253:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type5_After2iiii
	.def	__Z25runTestOpt08_Type5_After2iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type5_After2iiii:
LFB3254:
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
	movl	112(%esp), %eax
	movl	$LC14, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1354:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After2i
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After2i
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After2i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After2i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After2i
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After2i
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After2i
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After2i
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After2i
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After2i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1354
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3254:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type5_After3iiii
	.def	__Z25runTestOpt08_Type5_After3iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type5_After3iiii:
LFB3255:
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
	movl	112(%esp), %eax
	movl	$LC15, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1358:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After3i
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After3i
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type5_After3i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type5_After3i
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After3i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After3i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After3i
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After3i
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After3i
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After3i
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After3i
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After3i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1358
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3255:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type6_Beforeiiii
	.def	__Z25runTestOpt08_Type6_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type6_Beforeiiii:
LFB3257:
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
	movl	112(%esp), %eax
	movl	$LC11, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1362:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type6_Beforei
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type6_Beforei
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1362
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3257:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type6_After1iiii
	.def	__Z25runTestOpt08_Type6_After1iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type6_After1iiii:
LFB3258:
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
	movl	112(%esp), %eax
	movl	$LC13, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1366:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After1i
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After1i
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type6_After1i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type6_After1i
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After1i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After1i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After1i
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After1i
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After1i
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After1i
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After1i
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After1i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1366
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3258:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type6_After2iiii
	.def	__Z25runTestOpt08_Type6_After2iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type6_After2iiii:
LFB3259:
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
	movl	112(%esp), %eax
	movl	$LC14, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1370:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After2i
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After2i
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After2i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After2i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After2i
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After2i
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After2i
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After2i
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After2i
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After2i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1370
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3259:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type6_After3iiii
	.def	__Z25runTestOpt08_Type6_After3iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type6_After3iiii:
LFB3260:
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
	movl	112(%esp), %eax
	movl	$LC15, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1374:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After3i
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After3i
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type6_After3i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type6_After3i
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After3i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After3i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After3i
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After3i
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After3i
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After3i
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After3i
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After3i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1374
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3260:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type6_After4iiii
	.def	__Z25runTestOpt08_Type6_After4iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type6_After4iiii:
LFB3261:
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
	movl	112(%esp), %eax
	movl	$LC16, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1378:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After4i
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After4i
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type6_After4i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type6_After4i
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After4i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After4i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After4i
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After4i
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After4i
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After4i
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After4i
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After4i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1378
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3261:
	.section .rdata,"dr"
LC117:
	.ascii "  After5   ... \0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type6_After5iiii
	.def	__Z25runTestOpt08_Type6_After5iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type6_After5iiii:
LFB3262:
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
	movl	112(%esp), %eax
	movl	$LC117, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1382:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After5i
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type6_After5i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type6_After5i
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After5i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After5i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After5i
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After5i
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After5i
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After5i
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After5i
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After5i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1382
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3262:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type7_Beforeiiii
	.def	__Z25runTestOpt08_Type7_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type7_Beforeiiii:
LFB3264:
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
	movl	112(%esp), %eax
	movl	$LC11, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1386:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type7_Beforei
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type7_Beforei
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1386
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3264:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type7_After1iiii
	.def	__Z25runTestOpt08_Type7_After1iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type7_After1iiii:
LFB3265:
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
	movl	112(%esp), %eax
	movl	$LC13, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1390:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After1i
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After1i
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type7_After1i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type7_After1i
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After1i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After1i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After1i
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After1i
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After1i
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After1i
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After1i
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After1i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1390
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3265:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type7_After2iiii
	.def	__Z25runTestOpt08_Type7_After2iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type7_After2iiii:
LFB3266:
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
	movl	112(%esp), %eax
	movl	$LC14, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1394:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After2i
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After2i
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After2i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After2i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After2i
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After2i
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After2i
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After2i
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After2i
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After2i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1394
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3266:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type7_After3iiii
	.def	__Z25runTestOpt08_Type7_After3iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type7_After3iiii:
LFB3267:
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
	movl	112(%esp), %eax
	movl	$LC15, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1398:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After3i
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After3i
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type7_After3i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type7_After3i
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After3i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After3i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After3i
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After3i
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After3i
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After3i
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After3i
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After3i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1398
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3267:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type7_After4iiii
	.def	__Z25runTestOpt08_Type7_After4iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type7_After4iiii:
LFB3268:
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
	movl	112(%esp), %eax
	movl	$LC16, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1402:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After4i
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After4i
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type7_After4i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type7_After4i
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After4i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After4i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After4i
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After4i
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After4i
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After4i
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After4i
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After4i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1402
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3268:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type7_After5iiii
	.def	__Z25runTestOpt08_Type7_After5iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type7_After5iiii:
LFB3269:
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
	movl	112(%esp), %eax
	movl	$LC117, (%esp)
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	%eax, %ebx
	movl	%eax, 56(%esp)
	movl	116(%esp), %eax
	movl	%eax, %esi
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %ecx
	xorw	%cx, %cx
	movl	%ecx, 28(%esp)
	movl	%ebp, %ecx
	xorw	%cx, %cx
	movl	%ecx, 24(%esp)
	movl	%edi, %ecx
	xorw	%cx, %cx
	movl	%eax, 64(%esp)
	movzwl	%bx, %eax
	movl	%eax, 40(%esp)
	movzwl	%si, %eax
	xorl	%esi, %esi
	movl	%edx, 68(%esp)
	movl	%ebx, %edx
	movl	$10000000, %ebx
	movl	%eax, 48(%esp)
	movzwl	%bp, %eax
	xorw	%dx, %dx
	movl	%eax, 32(%esp)
	movzwl	%di, %eax
	movl	%edx, 36(%esp)
	movl	%ecx, 44(%esp)
	movl	%eax, 52(%esp)
	.p2align 4,,7
L1406:
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After5i
	addl	%eax, %esi
	movl	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	%ebp, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type7_After5i
	movl	%edi, (%esp)
	addl	%eax, %esi
	call	__Z22testOpt08_Type7_After5i
	addl	%eax, %esi
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After5i
	addl	%eax, %esi
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After5i
	addl	%eax, %esi
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After5i
	addl	%eax, %esi
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After5i
	addl	%eax, %esi
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After5i
	addl	%eax, %esi
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After5i
	addl	%eax, %esi
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After5i
	addl	%eax, %esi
	movl	52(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After5i
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L1406
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 116(%esp)
	movl	$LC12, 112(%esp)
	addl	$92, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3269:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type8_Beforeiiii
	.def	__Z25runTestOpt08_Type8_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type8_Beforeiiii:
LFB3271:
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
	subl	$80, %esp
	.cfi_def_cfa_offset 96
	movl	96(%esp), %eax
	movl	$LC11, (%esp)
	movl	%eax, 16(%esp)
	movl	100(%esp), %eax
	movl	%eax, 32(%esp)
	movl	104(%esp), %eax
	movl	%eax, 48(%esp)
	movl	108(%esp), %eax
	movl	%eax, 68(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movd	16(%esp), %xmm7
	movdqa	LC22, %xmm3
	pshufd	$0, %xmm7, %xmm7
	pxor	%xmm1, %xmm1
	movdqa	LC20, %xmm0
	movl	%eax, %esi
	movl	%edx, %edi
	xorl	%eax, %eax
	jmp	L1410
	.p2align 4,,7
L1434:
	movdqa	%xmm2, %xmm0
L1410:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm7, %xmm0
	cmpl	$2500000, %eax
	pabsd	%xmm0, %xmm0
	paddd	%xmm3, %xmm2
	paddd	%xmm0, %xmm1
	jne	L1434
	movdqa	%xmm1, %xmm6
	psrldq	$8, %xmm6
	movdqa	LC22, %xmm3
	paddd	%xmm6, %xmm1
	xorl	%eax, %eax
	movdqa	LC20, %xmm0
	movdqa	%xmm1, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm1
	movd	32(%esp), %xmm6
	pshufd	$0, %xmm6, %xmm6
	pextrd	$0, %xmm1, %edx
	pxor	%xmm1, %xmm1
	jmp	L1412
	.p2align 4,,7
L1435:
	movdqa	%xmm2, %xmm0
L1412:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm6, %xmm0
	cmpl	$2500000, %eax
	pabsd	%xmm0, %xmm0
	paddd	%xmm3, %xmm2
	paddd	%xmm0, %xmm1
	jne	L1435
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm3
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	movd	48(%esp), %xmm5
	pshufd	$0, %xmm5, %xmm5
	pextrd	$0, %xmm1, %eax
	movdqa	%xmm5, 16(%esp)
	addl	%eax, %edx
	pxor	%xmm1, %xmm1
	xorl	%eax, %eax
	movdqa	%xmm5, %xmm4
	jmp	L1414
	.p2align 4,,7
L1436:
	movdqa	%xmm2, %xmm0
L1414:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm4, %xmm0
	cmpl	$2500000, %eax
	pabsd	%xmm0, %xmm0
	paddd	%xmm3, %xmm2
	paddd	%xmm0, %xmm1
	jne	L1436
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm3
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	movd	68(%esp), %xmm5
	pshufd	$0, %xmm5, %xmm5
	pextrd	$0, %xmm1, %eax
	movdqa	%xmm5, 32(%esp)
	addl	%eax, %edx
	pxor	%xmm1, %xmm1
	xorl	%eax, %eax
	movdqa	%xmm5, %xmm4
	jmp	L1416
	.p2align 4,,7
L1437:
	movdqa	%xmm2, %xmm0
L1416:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm4, %xmm0
	cmpl	$2500000, %eax
	pabsd	%xmm0, %xmm0
	paddd	%xmm3, %xmm2
	paddd	%xmm0, %xmm1
	jne	L1437
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm4
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	pcmpeqd	%xmm3, %xmm3
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	pextrd	$0, %xmm1, %eax
	pxor	%xmm1, %xmm1
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1418
	.p2align 4,,7
L1438:
	movdqa	%xmm2, %xmm0
L1418:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm7, %xmm0
	cmpl	$2500000, %eax
	pxor	%xmm3, %xmm0
	paddd	%xmm4, %xmm2
	pabsd	%xmm0, %xmm0
	paddd	%xmm0, %xmm1
	jne	L1438
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm4
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	pcmpeqd	%xmm3, %xmm3
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	pextrd	$0, %xmm1, %eax
	pxor	%xmm1, %xmm1
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1420
	.p2align 4,,7
L1439:
	movdqa	%xmm2, %xmm0
L1420:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm6, %xmm0
	cmpl	$2500000, %eax
	pxor	%xmm3, %xmm0
	paddd	%xmm4, %xmm2
	pabsd	%xmm0, %xmm0
	paddd	%xmm0, %xmm1
	jne	L1439
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm4
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	pcmpeqd	%xmm3, %xmm3
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	movdqa	16(%esp), %xmm5
	pextrd	$0, %xmm1, %eax
	pxor	%xmm1, %xmm1
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1422
	.p2align 4,,7
L1440:
	movdqa	%xmm2, %xmm0
L1422:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm5, %xmm0
	cmpl	$2500000, %eax
	pxor	%xmm3, %xmm0
	paddd	%xmm4, %xmm2
	pabsd	%xmm0, %xmm0
	paddd	%xmm0, %xmm1
	jne	L1440
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm4
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	pcmpeqd	%xmm3, %xmm3
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	movdqa	32(%esp), %xmm5
	pextrd	$0, %xmm1, %eax
	pxor	%xmm1, %xmm1
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1424
	.p2align 4,,7
L1441:
	movdqa	%xmm2, %xmm0
L1424:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm5, %xmm0
	cmpl	$2500000, %eax
	pxor	%xmm3, %xmm0
	paddd	%xmm4, %xmm2
	pabsd	%xmm0, %xmm0
	paddd	%xmm0, %xmm1
	jne	L1441
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC118, %xmm0
	paddd	%xmm5, %xmm1
	movdqa	%xmm6, 48(%esp)
	pxor	%xmm2, %xmm2
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	movdqa	%xmm0, %xmm5
	psrlq	$32, %xmm5
	pextrd	$0, %xmm1, %eax
	movdqa	%xmm5, %xmm6
	addl	%eax, %edx
	movdqa	LC20, %xmm1
	xorl	%eax, %eax
	jmp	L1426
	.p2align 4,,7
L1442:
	movdqa	%xmm5, %xmm1
L1426:
	movdqa	LC22, %xmm5
	paddd	%xmm1, %xmm5
	pmulld	%xmm7, %xmm1
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	%xmm6, %xmm3
	pmuldq	%xmm0, %xmm4
	pshufb	LC119, %xmm4
	pshufb	LC120, %xmm3
	psrad	$31, %xmm1
	por	%xmm4, %xmm3
	addl	$1, %eax
	psrad	$22, %xmm3
	psubd	%xmm1, %xmm3
	cmpl	$2500000, %eax
	pabsd	%xmm3, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1442
	movdqa	%xmm2, %xmm7
	psrldq	$8, %xmm7
	movdqa	%xmm0, %xmm5
	paddd	%xmm7, %xmm2
	psrlq	$32, %xmm5
	movdqa	48(%esp), %xmm6
	movdqa	%xmm2, %xmm7
	psrldq	$4, %xmm7
	movdqa	LC20, %xmm1
	paddd	%xmm7, %xmm2
	movdqa	%xmm5, 48(%esp)
	movdqa	LC22, %xmm7
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1428
	.p2align 4,,7
L1443:
	movdqa	%xmm5, %xmm1
L1428:
	movdqa	%xmm1, %xmm5
	pmulld	%xmm6, %xmm1
	addl	$1, %eax
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	48(%esp), %xmm3
	pmuldq	%xmm0, %xmm4
	pshufb	LC119, %xmm4
	psrad	$31, %xmm1
	cmpl	$2500000, %eax
	paddd	%xmm7, %xmm5
	pshufb	LC120, %xmm3
	por	%xmm4, %xmm3
	psrad	$22, %xmm3
	psubd	%xmm1, %xmm3
	pabsd	%xmm3, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1443
	movdqa	%xmm2, %xmm7
	psrldq	$8, %xmm7
	movdqa	LC20, %xmm1
	paddd	%xmm7, %xmm2
	movdqa	LC22, %xmm7
	movdqa	%xmm2, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm2
	movdqa	%xmm0, %xmm6
	psrlq	$32, %xmm6
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1430
	.p2align 4,,7
L1444:
	movdqa	%xmm5, %xmm1
L1430:
	movdqa	%xmm1, %xmm5
	pmulld	16(%esp), %xmm1
	addl	$1, %eax
	cmpl	$2500000, %eax
	paddd	%xmm7, %xmm5
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	%xmm6, %xmm3
	pmuldq	%xmm0, %xmm4
	pshufb	LC119, %xmm4
	pshufb	LC120, %xmm3
	psrad	$31, %xmm1
	por	%xmm4, %xmm3
	psrad	$22, %xmm3
	psubd	%xmm1, %xmm3
	pabsd	%xmm3, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1444
	movdqa	%xmm2, %xmm7
	psrldq	$8, %xmm7
	movdqa	%xmm0, %xmm6
	paddd	%xmm7, %xmm2
	movdqa	LC20, %xmm1
	psrlq	$32, %xmm6
	movdqa	%xmm2, %xmm7
	psrldq	$4, %xmm7
	paddd	%xmm7, %xmm2
	movdqa	LC22, %xmm7
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1432
	.p2align 4,,7
L1445:
	movdqa	%xmm5, %xmm1
L1432:
	movdqa	%xmm1, %xmm5
	pmulld	32(%esp), %xmm1
	addl	$1, %eax
	cmpl	$2500000, %eax
	paddd	%xmm7, %xmm5
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	%xmm6, %xmm3
	pmuldq	%xmm0, %xmm4
	pshufb	LC119, %xmm4
	pshufb	LC120, %xmm3
	psrad	$31, %xmm1
	por	%xmm4, %xmm3
	psrad	$22, %xmm3
	psubd	%xmm1, %xmm3
	pabsd	%xmm3, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1445
	movdqa	%xmm2, %xmm7
	psrldq	$8, %xmm7
	paddd	%xmm7, %xmm2
	movdqa	%xmm2, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm2
	pextrd	$0, %xmm2, %ebx
	addl	%edx, %ebx
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%esi, %eax
	sbbl	%edi, %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%ebx, 100(%esp)
	movl	$LC12, 96(%esp)
	addl	$80, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	jmp	_printf
	.cfi_endproc
LFE3271:
	.p2align 4,,15
	.globl	__Z24runTestOpt08_Type8_Afteriiii
	.def	__Z24runTestOpt08_Type8_Afteriiii;	.scl	2;	.type	32;	.endef
__Z24runTestOpt08_Type8_Afteriiii:
LFB3272:
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
	subl	$80, %esp
	.cfi_def_cfa_offset 96
	movl	96(%esp), %eax
	movl	$LC13, (%esp)
	movl	%eax, 16(%esp)
	movl	100(%esp), %eax
	movl	%eax, 32(%esp)
	movl	104(%esp), %eax
	movl	%eax, 48(%esp)
	movl	108(%esp), %eax
	movl	%eax, 68(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movd	16(%esp), %xmm6
	movdqa	LC22, %xmm3
	pshufd	$0, %xmm6, %xmm7
	pxor	%xmm1, %xmm1
	movdqa	LC20, %xmm0
	movl	%eax, %esi
	movl	%edx, %edi
	xorl	%eax, %eax
	jmp	L1448
	.p2align 4,,7
L1472:
	movdqa	%xmm4, %xmm0
L1448:
	movdqa	%xmm0, %xmm4
	pmulld	%xmm7, %xmm0
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	psrad	$31, %xmm2
	cmpl	$2500000, %eax
	pxor	%xmm2, %xmm0
	psubd	%xmm2, %xmm0
	paddd	%xmm3, %xmm4
	paddd	%xmm0, %xmm1
	jne	L1472
	movdqa	%xmm1, %xmm6
	psrldq	$8, %xmm6
	movdqa	LC22, %xmm4
	paddd	%xmm6, %xmm1
	xorl	%eax, %eax
	pxor	%xmm2, %xmm2
	movdqa	%xmm1, %xmm6
	psrldq	$4, %xmm6
	movdqa	LC20, %xmm0
	paddd	%xmm6, %xmm1
	movd	32(%esp), %xmm6
	pshufd	$0, %xmm6, %xmm6
	pextrd	$0, %xmm1, %edx
	jmp	L1450
	.p2align 4,,7
L1473:
	movdqa	%xmm3, %xmm0
L1450:
	movdqa	%xmm0, %xmm3
	pmulld	%xmm6, %xmm0
	addl	$1, %eax
	movdqa	%xmm0, %xmm1
	psrad	$31, %xmm1
	cmpl	$2500000, %eax
	pxor	%xmm1, %xmm0
	psubd	%xmm1, %xmm0
	paddd	%xmm4, %xmm3
	paddd	%xmm0, %xmm2
	jne	L1473
	movdqa	%xmm2, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm4
	paddd	%xmm5, %xmm2
	movdqa	LC20, %xmm0
	movdqa	%xmm2, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm2
	pextrd	$0, %xmm2, %eax
	movd	48(%esp), %xmm2
	addl	%eax, %edx
	pshufd	$0, %xmm2, %xmm2
	xorl	%eax, %eax
	movdqa	%xmm2, %xmm5
	movdqa	%xmm2, 16(%esp)
	pxor	%xmm2, %xmm2
	jmp	L1452
	.p2align 4,,7
L1474:
	movdqa	%xmm3, %xmm0
L1452:
	movdqa	%xmm0, %xmm3
	pmulld	%xmm5, %xmm0
	addl	$1, %eax
	movdqa	%xmm0, %xmm1
	psrad	$31, %xmm1
	cmpl	$2500000, %eax
	pxor	%xmm1, %xmm0
	psubd	%xmm1, %xmm0
	paddd	%xmm4, %xmm3
	paddd	%xmm0, %xmm2
	jne	L1474
	movdqa	%xmm2, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm4
	paddd	%xmm5, %xmm2
	movdqa	LC20, %xmm0
	movdqa	%xmm2, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm2
	pextrd	$0, %xmm2, %eax
	movd	68(%esp), %xmm2
	addl	%eax, %edx
	pshufd	$0, %xmm2, %xmm2
	xorl	%eax, %eax
	movdqa	%xmm2, %xmm5
	movdqa	%xmm2, 32(%esp)
	pxor	%xmm2, %xmm2
	jmp	L1454
	.p2align 4,,7
L1475:
	movdqa	%xmm3, %xmm0
L1454:
	movdqa	%xmm0, %xmm3
	pmulld	%xmm5, %xmm0
	addl	$1, %eax
	movdqa	%xmm0, %xmm1
	psrad	$31, %xmm1
	cmpl	$2500000, %eax
	pxor	%xmm1, %xmm0
	psubd	%xmm1, %xmm0
	paddd	%xmm4, %xmm3
	paddd	%xmm0, %xmm2
	jne	L1475
	movdqa	%xmm2, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC20, %xmm0
	paddd	%xmm5, %xmm2
	pcmpeqd	%xmm4, %xmm4
	movdqa	%xmm2, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm2
	movdqa	LC22, %xmm5
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1456
	.p2align 4,,7
L1476:
	movdqa	%xmm3, %xmm0
L1456:
	movdqa	%xmm0, %xmm3
	pmulld	%xmm7, %xmm0
	addl	$1, %eax
	pxor	%xmm4, %xmm0
	movdqa	%xmm0, %xmm1
	psrad	$31, %xmm1
	pxor	%xmm1, %xmm0
	cmpl	$2500000, %eax
	psubd	%xmm1, %xmm0
	paddd	%xmm5, %xmm3
	paddd	%xmm0, %xmm2
	jne	L1476
	movdqa	%xmm2, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC20, %xmm0
	paddd	%xmm5, %xmm2
	pcmpeqd	%xmm4, %xmm4
	movdqa	%xmm2, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm2
	movdqa	LC22, %xmm5
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1458
	.p2align 4,,7
L1477:
	movdqa	%xmm3, %xmm0
L1458:
	movdqa	%xmm0, %xmm3
	pmulld	%xmm6, %xmm0
	addl	$1, %eax
	pxor	%xmm4, %xmm0
	movdqa	%xmm0, %xmm1
	psrad	$31, %xmm1
	pxor	%xmm1, %xmm0
	cmpl	$2500000, %eax
	psubd	%xmm1, %xmm0
	paddd	%xmm5, %xmm3
	paddd	%xmm0, %xmm2
	jne	L1477
	movdqa	%xmm2, %xmm5
	psrldq	$8, %xmm5
	movdqa	%xmm7, 48(%esp)
	paddd	%xmm5, %xmm2
	movdqa	LC20, %xmm0
	pcmpeqd	%xmm4, %xmm4
	movdqa	%xmm2, %xmm5
	psrldq	$4, %xmm5
	movdqa	16(%esp), %xmm7
	paddd	%xmm5, %xmm2
	movdqa	LC22, %xmm5
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1460
	.p2align 4,,7
L1478:
	movdqa	%xmm3, %xmm0
L1460:
	movdqa	%xmm0, %xmm3
	pmulld	%xmm7, %xmm0
	addl	$1, %eax
	pxor	%xmm4, %xmm0
	movdqa	%xmm0, %xmm1
	psrad	$31, %xmm1
	pxor	%xmm1, %xmm0
	cmpl	$2500000, %eax
	psubd	%xmm1, %xmm0
	paddd	%xmm5, %xmm3
	paddd	%xmm0, %xmm2
	jne	L1478
	movdqa	%xmm2, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC20, %xmm0
	paddd	%xmm5, %xmm2
	pcmpeqd	%xmm4, %xmm4
	movdqa	32(%esp), %xmm7
	movdqa	%xmm2, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm2
	movdqa	LC22, %xmm5
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1462
	.p2align 4,,7
L1479:
	movdqa	%xmm3, %xmm0
L1462:
	movdqa	%xmm0, %xmm3
	pmulld	%xmm7, %xmm0
	addl	$1, %eax
	pxor	%xmm4, %xmm0
	movdqa	%xmm0, %xmm1
	psrad	$31, %xmm1
	pxor	%xmm1, %xmm0
	cmpl	$2500000, %eax
	psubd	%xmm1, %xmm0
	paddd	%xmm5, %xmm3
	paddd	%xmm0, %xmm2
	jne	L1479
	movdqa	%xmm2, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC118, %xmm0
	paddd	%xmm5, %xmm2
	movdqa	48(%esp), %xmm7
	movdqa	LC20, %xmm1
	movdqa	%xmm2, %xmm5
	psrldq	$4, %xmm5
	movdqa	%xmm6, 48(%esp)
	paddd	%xmm5, %xmm2
	movdqa	%xmm0, %xmm5
	psrlq	$32, %xmm5
	pextrd	$0, %xmm2, %eax
	movdqa	%xmm5, %xmm6
	addl	%eax, %edx
	pxor	%xmm2, %xmm2
	xorl	%eax, %eax
	jmp	L1464
	.p2align 4,,7
L1480:
	movdqa	%xmm5, %xmm1
L1464:
	movdqa	LC22, %xmm5
	paddd	%xmm1, %xmm5
	pmulld	%xmm7, %xmm1
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	%xmm6, %xmm3
	pmuldq	%xmm0, %xmm4
	psrad	$31, %xmm1
	pshufb	LC119, %xmm4
	pshufb	LC120, %xmm3
	por	%xmm4, %xmm3
	psrad	$22, %xmm3
	addl	$1, %eax
	psubd	%xmm1, %xmm3
	cmpl	$2500000, %eax
	movdqa	%xmm3, %xmm1
	psrad	$31, %xmm1
	pxor	%xmm1, %xmm3
	psubd	%xmm1, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1480
	movdqa	%xmm2, %xmm7
	psrldq	$8, %xmm7
	movdqa	%xmm0, %xmm5
	paddd	%xmm7, %xmm2
	psrlq	$32, %xmm5
	movdqa	48(%esp), %xmm6
	movdqa	%xmm2, %xmm7
	psrldq	$4, %xmm7
	movdqa	LC20, %xmm1
	paddd	%xmm7, %xmm2
	movdqa	%xmm5, 48(%esp)
	movdqa	LC22, %xmm7
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1466
	.p2align 4,,7
L1481:
	movdqa	%xmm5, %xmm1
L1466:
	movdqa	%xmm1, %xmm5
	pmulld	%xmm6, %xmm1
	addl	$1, %eax
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	48(%esp), %xmm3
	pmuldq	%xmm0, %xmm4
	psrad	$31, %xmm1
	pshufb	LC119, %xmm4
	cmpl	$2500000, %eax
	paddd	%xmm7, %xmm5
	pshufb	LC120, %xmm3
	por	%xmm4, %xmm3
	psrad	$22, %xmm3
	psubd	%xmm1, %xmm3
	movdqa	%xmm3, %xmm1
	psrad	$31, %xmm1
	pxor	%xmm1, %xmm3
	psubd	%xmm1, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1481
	movdqa	%xmm2, %xmm6
	psrldq	$8, %xmm6
	movdqa	LC22, %xmm7
	paddd	%xmm6, %xmm2
	movdqa	LC20, %xmm1
	movdqa	%xmm2, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm2
	movdqa	%xmm0, %xmm6
	psrlq	$32, %xmm6
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1468
	.p2align 4,,7
L1482:
	movdqa	%xmm5, %xmm1
L1468:
	movdqa	%xmm1, %xmm5
	pmulld	16(%esp), %xmm1
	addl	$1, %eax
	cmpl	$2500000, %eax
	paddd	%xmm7, %xmm5
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	%xmm6, %xmm3
	pmuldq	%xmm0, %xmm4
	psrad	$31, %xmm1
	pshufb	LC119, %xmm4
	pshufb	LC120, %xmm3
	por	%xmm4, %xmm3
	psrad	$22, %xmm3
	psubd	%xmm1, %xmm3
	movdqa	%xmm3, %xmm1
	psrad	$31, %xmm1
	pxor	%xmm1, %xmm3
	psubd	%xmm1, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1482
	movdqa	%xmm2, %xmm6
	psrldq	$8, %xmm6
	movdqa	LC22, %xmm7
	paddd	%xmm6, %xmm2
	movdqa	LC20, %xmm1
	movdqa	%xmm2, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm2
	movdqa	%xmm0, %xmm6
	psrlq	$32, %xmm6
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1470
	.p2align 4,,7
L1483:
	movdqa	%xmm5, %xmm1
L1470:
	movdqa	%xmm1, %xmm5
	pmulld	32(%esp), %xmm1
	addl	$1, %eax
	cmpl	$2500000, %eax
	paddd	%xmm7, %xmm5
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	%xmm6, %xmm3
	pmuldq	%xmm0, %xmm4
	psrad	$31, %xmm1
	pshufb	LC119, %xmm4
	pshufb	LC120, %xmm3
	por	%xmm4, %xmm3
	psrad	$22, %xmm3
	psubd	%xmm1, %xmm3
	movdqa	%xmm3, %xmm1
	psrad	$31, %xmm1
	pxor	%xmm1, %xmm3
	psubd	%xmm1, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1483
	movdqa	%xmm2, %xmm6
	psrldq	$8, %xmm6
	paddd	%xmm6, %xmm2
	movdqa	%xmm2, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm2
	pextrd	$0, %xmm2, %ebx
	addl	%edx, %ebx
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%esi, %eax
	sbbl	%edi, %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%ebx, 100(%esp)
	movl	$LC12, 96(%esp)
	addl	$80, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	jmp	_printf
	.cfi_endproc
LFE3272:
	.section .rdata,"dr"
LC121:
	.ascii "  Appendix1... \0"
	.text
	.p2align 4,,15
	.globl	__Z28runTestOpt08_Type8_Appendix1iiii
	.def	__Z28runTestOpt08_Type8_Appendix1iiii;	.scl	2;	.type	32;	.endef
__Z28runTestOpt08_Type8_Appendix1iiii:
LFB3273:
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
	subl	$80, %esp
	.cfi_def_cfa_offset 96
	movl	96(%esp), %eax
	movl	$LC121, (%esp)
	movl	%eax, 16(%esp)
	movl	100(%esp), %eax
	movl	%eax, 32(%esp)
	movl	104(%esp), %eax
	movl	%eax, 48(%esp)
	movl	108(%esp), %eax
	movl	%eax, 68(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movd	16(%esp), %xmm7
	movdqa	LC22, %xmm3
	pshufd	$0, %xmm7, %xmm7
	pxor	%xmm1, %xmm1
	movdqa	LC20, %xmm0
	movl	%eax, %esi
	movl	%edx, %edi
	xorl	%eax, %eax
	jmp	L1486
	.p2align 4,,7
L1510:
	movdqa	%xmm2, %xmm0
L1486:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm7, %xmm0
	cmpl	$2500000, %eax
	pabsd	%xmm0, %xmm0
	paddd	%xmm3, %xmm2
	paddd	%xmm0, %xmm1
	jne	L1510
	movdqa	%xmm1, %xmm6
	psrldq	$8, %xmm6
	movdqa	LC22, %xmm3
	paddd	%xmm6, %xmm1
	xorl	%eax, %eax
	movdqa	LC20, %xmm0
	movdqa	%xmm1, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm1
	movd	32(%esp), %xmm6
	pshufd	$0, %xmm6, %xmm6
	pextrd	$0, %xmm1, %edx
	pxor	%xmm1, %xmm1
	jmp	L1488
	.p2align 4,,7
L1511:
	movdqa	%xmm2, %xmm0
L1488:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm6, %xmm0
	cmpl	$2500000, %eax
	pabsd	%xmm0, %xmm0
	paddd	%xmm3, %xmm2
	paddd	%xmm0, %xmm1
	jne	L1511
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm3
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	movd	48(%esp), %xmm5
	pshufd	$0, %xmm5, %xmm5
	pextrd	$0, %xmm1, %eax
	movdqa	%xmm5, 16(%esp)
	addl	%eax, %edx
	pxor	%xmm1, %xmm1
	xorl	%eax, %eax
	movdqa	%xmm5, %xmm4
	jmp	L1490
	.p2align 4,,7
L1512:
	movdqa	%xmm2, %xmm0
L1490:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm4, %xmm0
	cmpl	$2500000, %eax
	pabsd	%xmm0, %xmm0
	paddd	%xmm3, %xmm2
	paddd	%xmm0, %xmm1
	jne	L1512
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm3
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	movd	68(%esp), %xmm5
	pshufd	$0, %xmm5, %xmm5
	pextrd	$0, %xmm1, %eax
	movdqa	%xmm5, 32(%esp)
	addl	%eax, %edx
	pxor	%xmm1, %xmm1
	xorl	%eax, %eax
	movdqa	%xmm5, %xmm4
	jmp	L1492
	.p2align 4,,7
L1513:
	movdqa	%xmm2, %xmm0
L1492:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm4, %xmm0
	cmpl	$2500000, %eax
	pabsd	%xmm0, %xmm0
	paddd	%xmm3, %xmm2
	paddd	%xmm0, %xmm1
	jne	L1513
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm4
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	pcmpeqd	%xmm3, %xmm3
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	pextrd	$0, %xmm1, %eax
	pxor	%xmm1, %xmm1
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1494
	.p2align 4,,7
L1514:
	movdqa	%xmm2, %xmm0
L1494:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm7, %xmm0
	cmpl	$2500000, %eax
	pxor	%xmm3, %xmm0
	paddd	%xmm4, %xmm2
	pabsd	%xmm0, %xmm0
	paddd	%xmm0, %xmm1
	jne	L1514
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm4
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	pcmpeqd	%xmm3, %xmm3
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	pextrd	$0, %xmm1, %eax
	pxor	%xmm1, %xmm1
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1496
	.p2align 4,,7
L1515:
	movdqa	%xmm2, %xmm0
L1496:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm6, %xmm0
	cmpl	$2500000, %eax
	pxor	%xmm3, %xmm0
	paddd	%xmm4, %xmm2
	pabsd	%xmm0, %xmm0
	paddd	%xmm0, %xmm1
	jne	L1515
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm4
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	pcmpeqd	%xmm3, %xmm3
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	movdqa	16(%esp), %xmm5
	pextrd	$0, %xmm1, %eax
	pxor	%xmm1, %xmm1
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1498
	.p2align 4,,7
L1516:
	movdqa	%xmm2, %xmm0
L1498:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm5, %xmm0
	cmpl	$2500000, %eax
	pxor	%xmm3, %xmm0
	paddd	%xmm4, %xmm2
	pabsd	%xmm0, %xmm0
	paddd	%xmm0, %xmm1
	jne	L1516
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm4
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	pcmpeqd	%xmm3, %xmm3
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	movdqa	32(%esp), %xmm5
	pextrd	$0, %xmm1, %eax
	pxor	%xmm1, %xmm1
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1500
	.p2align 4,,7
L1517:
	movdqa	%xmm2, %xmm0
L1500:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm5, %xmm0
	cmpl	$2500000, %eax
	pxor	%xmm3, %xmm0
	paddd	%xmm4, %xmm2
	pabsd	%xmm0, %xmm0
	paddd	%xmm0, %xmm1
	jne	L1517
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC118, %xmm0
	paddd	%xmm5, %xmm1
	movdqa	%xmm6, 48(%esp)
	pxor	%xmm2, %xmm2
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	movdqa	%xmm0, %xmm5
	psrlq	$32, %xmm5
	pextrd	$0, %xmm1, %eax
	movdqa	%xmm5, %xmm6
	addl	%eax, %edx
	movdqa	LC20, %xmm1
	xorl	%eax, %eax
	jmp	L1502
	.p2align 4,,7
L1518:
	movdqa	%xmm5, %xmm1
L1502:
	movdqa	LC22, %xmm5
	paddd	%xmm1, %xmm5
	pmulld	%xmm7, %xmm1
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	%xmm6, %xmm3
	pmuldq	%xmm0, %xmm4
	pshufb	LC119, %xmm4
	pshufb	LC120, %xmm3
	psrad	$31, %xmm1
	por	%xmm4, %xmm3
	addl	$1, %eax
	psrad	$22, %xmm3
	psubd	%xmm1, %xmm3
	cmpl	$2500000, %eax
	pabsd	%xmm3, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1518
	movdqa	%xmm2, %xmm7
	psrldq	$8, %xmm7
	movdqa	%xmm0, %xmm5
	paddd	%xmm7, %xmm2
	psrlq	$32, %xmm5
	movdqa	48(%esp), %xmm6
	movdqa	%xmm2, %xmm7
	psrldq	$4, %xmm7
	movdqa	LC20, %xmm1
	paddd	%xmm7, %xmm2
	movdqa	%xmm5, 48(%esp)
	movdqa	LC22, %xmm7
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1504
	.p2align 4,,7
L1519:
	movdqa	%xmm5, %xmm1
L1504:
	movdqa	%xmm1, %xmm5
	pmulld	%xmm6, %xmm1
	addl	$1, %eax
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	48(%esp), %xmm3
	pmuldq	%xmm0, %xmm4
	pshufb	LC119, %xmm4
	psrad	$31, %xmm1
	cmpl	$2500000, %eax
	paddd	%xmm7, %xmm5
	pshufb	LC120, %xmm3
	por	%xmm4, %xmm3
	psrad	$22, %xmm3
	psubd	%xmm1, %xmm3
	pabsd	%xmm3, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1519
	movdqa	%xmm2, %xmm7
	psrldq	$8, %xmm7
	movdqa	LC20, %xmm1
	paddd	%xmm7, %xmm2
	movdqa	LC22, %xmm7
	movdqa	%xmm2, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm2
	movdqa	%xmm0, %xmm6
	psrlq	$32, %xmm6
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1506
	.p2align 4,,7
L1520:
	movdqa	%xmm5, %xmm1
L1506:
	movdqa	%xmm1, %xmm5
	pmulld	16(%esp), %xmm1
	addl	$1, %eax
	cmpl	$2500000, %eax
	paddd	%xmm7, %xmm5
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	%xmm6, %xmm3
	pmuldq	%xmm0, %xmm4
	pshufb	LC119, %xmm4
	pshufb	LC120, %xmm3
	psrad	$31, %xmm1
	por	%xmm4, %xmm3
	psrad	$22, %xmm3
	psubd	%xmm1, %xmm3
	pabsd	%xmm3, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1520
	movdqa	%xmm2, %xmm7
	psrldq	$8, %xmm7
	movdqa	%xmm0, %xmm6
	paddd	%xmm7, %xmm2
	movdqa	LC20, %xmm1
	psrlq	$32, %xmm6
	movdqa	%xmm2, %xmm7
	psrldq	$4, %xmm7
	paddd	%xmm7, %xmm2
	movdqa	LC22, %xmm7
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1508
	.p2align 4,,7
L1521:
	movdqa	%xmm5, %xmm1
L1508:
	movdqa	%xmm1, %xmm5
	pmulld	32(%esp), %xmm1
	addl	$1, %eax
	cmpl	$2500000, %eax
	paddd	%xmm7, %xmm5
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	%xmm6, %xmm3
	pmuldq	%xmm0, %xmm4
	pshufb	LC119, %xmm4
	pshufb	LC120, %xmm3
	psrad	$31, %xmm1
	por	%xmm4, %xmm3
	psrad	$22, %xmm3
	psubd	%xmm1, %xmm3
	pabsd	%xmm3, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1521
	movdqa	%xmm2, %xmm7
	psrldq	$8, %xmm7
	paddd	%xmm7, %xmm2
	movdqa	%xmm2, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm2
	pextrd	$0, %xmm2, %ebx
	addl	%edx, %ebx
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%esi, %eax
	sbbl	%edi, %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%ebx, 100(%esp)
	movl	$LC12, 96(%esp)
	addl	$80, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	jmp	_printf
	.cfi_endproc
LFE3273:
	.section .rdata,"dr"
LC122:
	.ascii "  Appendix2... \0"
	.text
	.p2align 4,,15
	.globl	__Z28runTestOpt08_Type8_Appendix2iiii
	.def	__Z28runTestOpt08_Type8_Appendix2iiii;	.scl	2;	.type	32;	.endef
__Z28runTestOpt08_Type8_Appendix2iiii:
LFB3274:
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
	subl	$80, %esp
	.cfi_def_cfa_offset 96
	movl	96(%esp), %eax
	movl	$LC122, (%esp)
	movl	%eax, 16(%esp)
	movl	100(%esp), %eax
	movl	%eax, 32(%esp)
	movl	104(%esp), %eax
	movl	%eax, 48(%esp)
	movl	108(%esp), %eax
	movl	%eax, 68(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movd	16(%esp), %xmm7
	movdqa	LC22, %xmm3
	pshufd	$0, %xmm7, %xmm7
	pxor	%xmm1, %xmm1
	movdqa	LC20, %xmm0
	movl	%eax, %esi
	movl	%edx, %edi
	xorl	%eax, %eax
	jmp	L1524
	.p2align 4,,7
L1548:
	movdqa	%xmm2, %xmm0
L1524:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm7, %xmm0
	cmpl	$2500000, %eax
	pabsd	%xmm0, %xmm0
	paddd	%xmm3, %xmm2
	paddd	%xmm0, %xmm1
	jne	L1548
	movdqa	%xmm1, %xmm6
	psrldq	$8, %xmm6
	movdqa	LC22, %xmm3
	paddd	%xmm6, %xmm1
	xorl	%eax, %eax
	movdqa	LC20, %xmm0
	movdqa	%xmm1, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm1
	movd	32(%esp), %xmm6
	pshufd	$0, %xmm6, %xmm6
	pextrd	$0, %xmm1, %edx
	pxor	%xmm1, %xmm1
	jmp	L1526
	.p2align 4,,7
L1549:
	movdqa	%xmm2, %xmm0
L1526:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm6, %xmm0
	cmpl	$2500000, %eax
	pabsd	%xmm0, %xmm0
	paddd	%xmm3, %xmm2
	paddd	%xmm0, %xmm1
	jne	L1549
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm3
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	movd	48(%esp), %xmm5
	pshufd	$0, %xmm5, %xmm5
	pextrd	$0, %xmm1, %eax
	movdqa	%xmm5, 16(%esp)
	addl	%eax, %edx
	pxor	%xmm1, %xmm1
	xorl	%eax, %eax
	movdqa	%xmm5, %xmm4
	jmp	L1528
	.p2align 4,,7
L1550:
	movdqa	%xmm2, %xmm0
L1528:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm4, %xmm0
	cmpl	$2500000, %eax
	pabsd	%xmm0, %xmm0
	paddd	%xmm3, %xmm2
	paddd	%xmm0, %xmm1
	jne	L1550
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm3
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	movd	68(%esp), %xmm5
	pshufd	$0, %xmm5, %xmm5
	pextrd	$0, %xmm1, %eax
	movdqa	%xmm5, 32(%esp)
	addl	%eax, %edx
	pxor	%xmm1, %xmm1
	xorl	%eax, %eax
	movdqa	%xmm5, %xmm4
	jmp	L1530
	.p2align 4,,7
L1551:
	movdqa	%xmm2, %xmm0
L1530:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm4, %xmm0
	cmpl	$2500000, %eax
	pabsd	%xmm0, %xmm0
	paddd	%xmm3, %xmm2
	paddd	%xmm0, %xmm1
	jne	L1551
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm4
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	pcmpeqd	%xmm3, %xmm3
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	pextrd	$0, %xmm1, %eax
	pxor	%xmm1, %xmm1
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1532
	.p2align 4,,7
L1552:
	movdqa	%xmm2, %xmm0
L1532:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm7, %xmm0
	cmpl	$2500000, %eax
	pxor	%xmm3, %xmm0
	paddd	%xmm4, %xmm2
	pabsd	%xmm0, %xmm0
	paddd	%xmm0, %xmm1
	jne	L1552
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm4
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	pcmpeqd	%xmm3, %xmm3
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	pextrd	$0, %xmm1, %eax
	pxor	%xmm1, %xmm1
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1534
	.p2align 4,,7
L1553:
	movdqa	%xmm2, %xmm0
L1534:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm6, %xmm0
	cmpl	$2500000, %eax
	pxor	%xmm3, %xmm0
	paddd	%xmm4, %xmm2
	pabsd	%xmm0, %xmm0
	paddd	%xmm0, %xmm1
	jne	L1553
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm4
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	pcmpeqd	%xmm3, %xmm3
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	movdqa	16(%esp), %xmm5
	pextrd	$0, %xmm1, %eax
	pxor	%xmm1, %xmm1
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1536
	.p2align 4,,7
L1554:
	movdqa	%xmm2, %xmm0
L1536:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm5, %xmm0
	cmpl	$2500000, %eax
	pxor	%xmm3, %xmm0
	paddd	%xmm4, %xmm2
	pabsd	%xmm0, %xmm0
	paddd	%xmm0, %xmm1
	jne	L1554
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm4
	paddd	%xmm5, %xmm1
	movdqa	LC20, %xmm0
	pcmpeqd	%xmm3, %xmm3
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	movdqa	32(%esp), %xmm5
	pextrd	$0, %xmm1, %eax
	pxor	%xmm1, %xmm1
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1538
	.p2align 4,,7
L1555:
	movdqa	%xmm2, %xmm0
L1538:
	addl	$1, %eax
	movdqa	%xmm0, %xmm2
	pmulld	%xmm5, %xmm0
	cmpl	$2500000, %eax
	pxor	%xmm3, %xmm0
	paddd	%xmm4, %xmm2
	pabsd	%xmm0, %xmm0
	paddd	%xmm0, %xmm1
	jne	L1555
	movdqa	%xmm1, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC118, %xmm0
	paddd	%xmm5, %xmm1
	movdqa	%xmm6, 48(%esp)
	pxor	%xmm2, %xmm2
	movdqa	%xmm1, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm1
	movdqa	%xmm0, %xmm5
	psrlq	$32, %xmm5
	pextrd	$0, %xmm1, %eax
	movdqa	%xmm5, %xmm6
	addl	%eax, %edx
	movdqa	LC20, %xmm1
	xorl	%eax, %eax
	jmp	L1540
	.p2align 4,,7
L1556:
	movdqa	%xmm5, %xmm1
L1540:
	movdqa	LC22, %xmm5
	paddd	%xmm1, %xmm5
	pmulld	%xmm7, %xmm1
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	%xmm6, %xmm3
	pmuldq	%xmm0, %xmm4
	pshufb	LC119, %xmm4
	pshufb	LC120, %xmm3
	psrad	$31, %xmm1
	por	%xmm4, %xmm3
	addl	$1, %eax
	psrad	$22, %xmm3
	psubd	%xmm1, %xmm3
	cmpl	$2500000, %eax
	pabsd	%xmm3, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1556
	movdqa	%xmm2, %xmm7
	psrldq	$8, %xmm7
	movdqa	%xmm0, %xmm5
	paddd	%xmm7, %xmm2
	psrlq	$32, %xmm5
	movdqa	48(%esp), %xmm6
	movdqa	%xmm2, %xmm7
	psrldq	$4, %xmm7
	movdqa	LC20, %xmm1
	paddd	%xmm7, %xmm2
	movdqa	%xmm5, 48(%esp)
	movdqa	LC22, %xmm7
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1542
	.p2align 4,,7
L1557:
	movdqa	%xmm5, %xmm1
L1542:
	movdqa	%xmm1, %xmm5
	pmulld	%xmm6, %xmm1
	addl	$1, %eax
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	48(%esp), %xmm3
	pmuldq	%xmm0, %xmm4
	pshufb	LC119, %xmm4
	psrad	$31, %xmm1
	cmpl	$2500000, %eax
	paddd	%xmm7, %xmm5
	pshufb	LC120, %xmm3
	por	%xmm4, %xmm3
	psrad	$22, %xmm3
	psubd	%xmm1, %xmm3
	pabsd	%xmm3, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1557
	movdqa	%xmm2, %xmm7
	psrldq	$8, %xmm7
	movdqa	LC20, %xmm1
	paddd	%xmm7, %xmm2
	movdqa	LC22, %xmm7
	movdqa	%xmm2, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm2
	movdqa	%xmm0, %xmm6
	psrlq	$32, %xmm6
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1544
	.p2align 4,,7
L1558:
	movdqa	%xmm5, %xmm1
L1544:
	movdqa	%xmm1, %xmm5
	pmulld	16(%esp), %xmm1
	addl	$1, %eax
	cmpl	$2500000, %eax
	paddd	%xmm7, %xmm5
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	%xmm6, %xmm3
	pmuldq	%xmm0, %xmm4
	pshufb	LC119, %xmm4
	pshufb	LC120, %xmm3
	psrad	$31, %xmm1
	por	%xmm4, %xmm3
	psrad	$22, %xmm3
	psubd	%xmm1, %xmm3
	pabsd	%xmm3, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1558
	movdqa	%xmm2, %xmm7
	psrldq	$8, %xmm7
	movdqa	%xmm0, %xmm6
	paddd	%xmm7, %xmm2
	movdqa	LC20, %xmm1
	psrlq	$32, %xmm6
	movdqa	%xmm2, %xmm7
	psrldq	$4, %xmm7
	paddd	%xmm7, %xmm2
	movdqa	LC22, %xmm7
	pextrd	$0, %xmm2, %eax
	pxor	%xmm2, %xmm2
	addl	%eax, %edx
	xorl	%eax, %eax
	jmp	L1546
	.p2align 4,,7
L1559:
	movdqa	%xmm5, %xmm1
L1546:
	movdqa	%xmm1, %xmm5
	pmulld	32(%esp), %xmm1
	addl	$1, %eax
	cmpl	$2500000, %eax
	paddd	%xmm7, %xmm5
	movdqa	%xmm1, %xmm3
	psrlq	$32, %xmm3
	movdqa	%xmm1, %xmm4
	pmuldq	%xmm6, %xmm3
	pmuldq	%xmm0, %xmm4
	pshufb	LC119, %xmm4
	pshufb	LC120, %xmm3
	psrad	$31, %xmm1
	por	%xmm4, %xmm3
	psrad	$22, %xmm3
	psubd	%xmm1, %xmm3
	pabsd	%xmm3, %xmm3
	paddd	%xmm3, %xmm2
	jne	L1559
	movdqa	%xmm2, %xmm7
	psrldq	$8, %xmm7
	paddd	%xmm7, %xmm2
	movdqa	%xmm2, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm2
	pextrd	$0, %xmm2, %ebx
	addl	%edx, %ebx
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	%esi, %eax
	sbbl	%edi, %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%ebx, 100(%esp)
	movl	$LC12, 96(%esp)
	addl	$80, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	jmp	_printf
	.cfi_endproc
LFE3274:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type9_Beforeiiii
	.def	__Z25runTestOpt08_Type9_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type9_Beforeiiii:
LFB3276:
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
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	84(%esp), %eax
	movl	$LC11, (%esp)
	movl	80(%esp), %ebp
	movl	%eax, 16(%esp)
	movl	88(%esp), %eax
	movl	%eax, 20(%esp)
	movl	92(%esp), %eax
	movl	%eax, 32(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	pxor	%xmm3, %xmm3
	movdqa	LC22, %xmm7
	movl	%ebp, 36(%esp)
	movdqa	LC20, %xmm1
	movdqa	%xmm3, %xmm4
	movd	36(%esp), %xmm6
	pshufd	$0, %xmm6, %xmm6
	movl	%eax, 24(%esp)
	xorl	%eax, %eax
	movl	%edx, 28(%esp)
	jmp	L1562
	.p2align 4,,7
L1594:
	movdqa	%xmm5, %xmm1
L1562:
	addl	$1, %eax
	movdqa	%xmm1, %xmm5
	pmulld	%xmm6, %xmm1
	cmpl	$2500000, %eax
	movdqa	%xmm1, %xmm2
	movdqa	%xmm4, %xmm0
	pcmpeqd	%xmm4, %xmm2
	pcmpgtd	%xmm1, %xmm0
	pandn	LC123, %xmm2
	movdqa	%xmm0, %xmm1
	paddd	%xmm7, %xmm5
	por	%xmm2, %xmm1
	paddd	%xmm1, %xmm3
	jne	L1594
	movdqa	%xmm3, %xmm6
	psrldq	$8, %xmm6
	movdqa	LC22, %xmm7
	paddd	%xmm6, %xmm3
	xorl	%eax, %eax
	movdqa	LC20, %xmm1
	movdqa	%xmm3, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm3
	movd	16(%esp), %xmm6
	pshufd	$0, %xmm6, %xmm6
	pextrd	$0, %xmm3, %edx
	pxor	%xmm3, %xmm3
	movdqa	%xmm3, %xmm4
	jmp	L1564
	.p2align 4,,7
L1595:
	movdqa	%xmm5, %xmm1
L1564:
	addl	$1, %eax
	movdqa	%xmm1, %xmm5
	pmulld	%xmm6, %xmm1
	cmpl	$2500000, %eax
	movdqa	%xmm1, %xmm2
	movdqa	%xmm4, %xmm0
	pcmpeqd	%xmm4, %xmm2
	pcmpgtd	%xmm1, %xmm0
	pandn	LC123, %xmm2
	movdqa	%xmm0, %xmm1
	paddd	%xmm7, %xmm5
	por	%xmm2, %xmm1
	paddd	%xmm1, %xmm3
	jne	L1595
	movdqa	%xmm3, %xmm6
	psrldq	$8, %xmm6
	movdqa	LC22, %xmm7
	paddd	%xmm6, %xmm3
	movdqa	LC20, %xmm1
	movdqa	%xmm3, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm3
	movd	20(%esp), %xmm6
	pshufd	$0, %xmm6, %xmm6
	pextrd	$0, %xmm3, %eax
	pxor	%xmm3, %xmm3
	addl	%eax, %edx
	movdqa	%xmm3, %xmm4
	xorl	%eax, %eax
	jmp	L1566
	.p2align 4,,7
L1596:
	movdqa	%xmm5, %xmm1
L1566:
	addl	$1, %eax
	movdqa	%xmm1, %xmm5
	pmulld	%xmm6, %xmm1
	cmpl	$2500000, %eax
	movdqa	%xmm1, %xmm2
	movdqa	%xmm4, %xmm0
	pcmpeqd	%xmm4, %xmm2
	pcmpgtd	%xmm1, %xmm0
	pandn	LC123, %xmm2
	movdqa	%xmm0, %xmm1
	paddd	%xmm7, %xmm5
	por	%xmm2, %xmm1
	paddd	%xmm1, %xmm3
	jne	L1596
	movdqa	%xmm3, %xmm6
	psrldq	$8, %xmm6
	movdqa	LC20, %xmm1
	paddd	%xmm6, %xmm3
	movdqa	%xmm3, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm3
	movdqa	LC22, %xmm6
	pextrd	$0, %xmm3, %eax
	movd	32(%esp), %xmm3
	addl	%eax, %edx
	pshufd	$0, %xmm3, %xmm5
	xorl	%eax, %eax
	pxor	%xmm3, %xmm3
	movdqa	%xmm3, %xmm4
	jmp	L1569
	.p2align 4,,7
L1567:
	movdqa	%xmm7, %xmm1
L1569:
	addl	$1, %eax
	movdqa	%xmm1, %xmm7
	pmulld	%xmm5, %xmm1
	cmpl	$2500000, %eax
	movdqa	%xmm1, %xmm2
	movdqa	%xmm4, %xmm0
	pcmpeqd	%xmm4, %xmm2
	pcmpgtd	%xmm1, %xmm0
	pandn	LC123, %xmm2
	movdqa	%xmm0, %xmm1
	paddd	%xmm6, %xmm7
	por	%xmm2, %xmm1
	paddd	%xmm1, %xmm3
	jne	L1567
	movdqa	%xmm3, %xmm6
	psrldq	$8, %xmm6
	movl	%ebp, %edi
	paddd	%xmm6, %xmm3
	movl	$10000000, %eax
	movdqa	%xmm3, %xmm6
	psrldq	$4, %xmm6
	movl	$-1, %ecx
	paddd	%xmm6, %xmm3
	negl	%edi
	pextrd	$0, %xmm3, %ebx
	addl	%edx, %ebx
	movl	%ebp, %esi
	xorl	%edx, %edx
	addl	%ecx, %ebx
	subl	$1, %eax
	notl	%esi
	movl	%ebp, 36(%esp)
	je	L1597
	.p2align 4,,7
L1571:
	movl	%esi, %ebp
	movl	$-1, %ecx
	addl	%edx, %ebp
	js	L1570
	setne	%cl
	movzbl	%cl, %ecx
L1570:
	addl	%edi, %edx
	addl	%ecx, %ebx
	subl	$1, %eax
	jne	L1571
L1597:
	movl	16(%esp), %esi
	movl	$10000000, %eax
	movl	$-1, %ecx
	xorl	%edx, %edx
	addl	%ecx, %ebx
	movl	%esi, %edi
	notl	%esi
	negl	%edi
	subl	$1, %eax
	je	L1598
	.p2align 4,,7
L1574:
	movl	%esi, %ebp
	movl	$-1, %ecx
	addl	%edx, %ebp
	js	L1573
	setne	%cl
	movzbl	%cl, %ecx
L1573:
	addl	%edi, %edx
	addl	%ecx, %ebx
	subl	$1, %eax
	jne	L1574
L1598:
	movl	20(%esp), %esi
	movl	$10000000, %eax
	movl	$-1, %ecx
	xorl	%edx, %edx
	addl	%ecx, %ebx
	movl	%esi, %edi
	notl	%esi
	negl	%edi
	subl	$1, %eax
	je	L1599
	.p2align 4,,7
L1577:
	movl	%esi, %ebp
	movl	$-1, %ecx
	addl	%edx, %ebp
	js	L1576
	setne	%cl
	movzbl	%cl, %ecx
L1576:
	addl	%edi, %edx
	addl	%ecx, %ebx
	subl	$1, %eax
	jne	L1577
L1599:
	movl	32(%esp), %esi
	movl	$10000000, %eax
	movl	$-1, %ecx
	xorl	%edx, %edx
	addl	%ecx, %ebx
	movl	%esi, %edi
	notl	%esi
	negl	%edi
	subl	$1, %eax
	je	L1600
	.p2align 4,,7
L1580:
	movl	%esi, %ebp
	movl	$-1, %ecx
	addl	%edx, %ebp
	js	L1579
	setne	%cl
	movzbl	%cl, %ecx
L1579:
	addl	%edi, %edx
	addl	%ecx, %ebx
	subl	$1, %eax
	jne	L1580
L1600:
	movl	36(%esp), %ebp
	xorl	%ecx, %ecx
	movl	$10000000, %esi
	movl	$-1, %edi
	.p2align 4,,7
L1582:
	movl	$1801439851, %eax
	imull	%ecx
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$22, %edx
	subl	%eax, %edx
	setne	%al
	testl	%edx, %edx
	movzbl	%al, %eax
	cmovs	%edi, %eax
	addl	%ebp, %ecx
	addl	%eax, %ebx
	subl	$1, %esi
	jne	L1582
	xorl	%ecx, %ecx
	movl	$10000000, %esi
	movl	$1801439851, %ebp
	movl	$-1, %edi
	.p2align 4,,7
L1584:
	movl	%ecx, %eax
	imull	%ebp
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$22, %edx
	subl	%eax, %edx
	setne	%al
	testl	%edx, %edx
	movzbl	%al, %eax
	cmovs	%edi, %eax
	addl	%eax, %ebx
	addl	16(%esp), %ecx
	subl	$1, %esi
	jne	L1584
	xorl	%ecx, %ecx
	movl	$10000000, %esi
	movl	$1801439851, %ebp
	movl	$-1, %edi
	.p2align 4,,7
L1586:
	movl	%ecx, %eax
	imull	%ebp
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$22, %edx
	subl	%eax, %edx
	setne	%al
	testl	%edx, %edx
	movzbl	%al, %eax
	cmovs	%edi, %eax
	addl	%eax, %ebx
	addl	20(%esp), %ecx
	subl	$1, %esi
	jne	L1586
	xorl	%ecx, %ecx
	movl	$10000000, %esi
	movl	$1801439851, %ebp
	movl	$-1, %edi
	.p2align 4,,7
L1588:
	movl	%ecx, %eax
	imull	%ebp
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$22, %edx
	subl	%eax, %edx
	setne	%al
	testl	%edx, %edx
	movzbl	%al, %eax
	cmovs	%edi, %eax
	addl	%eax, %ebx
	addl	32(%esp), %ecx
	subl	$1, %esi
	jne	L1588
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	24(%esp), %eax
	sbbl	28(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%ebx, 84(%esp)
	movl	$LC12, 80(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3276:
	.p2align 4,,15
	.globl	__Z24runTestOpt08_Type9_Afteriiii
	.def	__Z24runTestOpt08_Type9_Afteriiii;	.scl	2;	.type	32;	.endef
__Z24runTestOpt08_Type9_Afteriiii:
LFB3277:
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
	subl	$124, %esp
	.cfi_def_cfa_offset 144
	movl	148(%esp), %eax
	movl	$LC21, (%esp)
	movl	144(%esp), %edi
	movl	%eax, 68(%esp)
	movl	152(%esp), %eax
	movl	%eax, 72(%esp)
	movl	156(%esp), %eax
	movl	%eax, 76(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	pxor	%xmm3, %xmm3
	movdqa	LC22, %xmm6
	movl	%edi, 16(%esp)
	movdqa	LC20, %xmm2
	movdqa	%xmm3, %xmm5
	movd	16(%esp), %xmm0
	pshufd	$0, %xmm0, %xmm7
	movdqa	LC123, %xmm0
	movl	%eax, 96(%esp)
	xorl	%eax, %eax
	movl	%edx, 100(%esp)
	jmp	L1603
	.p2align 4,,7
L1627:
	movdqa	%xmm4, %xmm2
L1603:
	movdqa	%xmm2, %xmm4
	addl	$1, %eax
	pmulld	%xmm7, %xmm2
	movdqa	%xmm2, %xmm1
	cmpl	$2500000, %eax
	psrad	$31, %xmm1
	pcmpeqd	%xmm5, %xmm2
	paddd	%xmm6, %xmm4
	pandn	%xmm0, %xmm2
	por	%xmm2, %xmm1
	paddd	%xmm1, %xmm3
	jne	L1627
	movdqa	%xmm3, %xmm5
	psrldq	$8, %xmm5
	movdqa	%xmm7, 32(%esp)
	paddd	%xmm5, %xmm3
	xorl	%eax, %eax
	movd	68(%esp), %xmm5
	movdqa	%xmm3, %xmm6
	psrldq	$4, %xmm6
	pshufd	$0, %xmm5, %xmm5
	paddd	%xmm6, %xmm3
	movdqa	%xmm5, %xmm4
	movdqa	%xmm5, 16(%esp)
	pextrd	$0, %xmm3, %edx
	movdqa	LC22, %xmm6
	pxor	%xmm3, %xmm3
	movdqa	LC20, %xmm2
	movdqa	%xmm3, %xmm5
	movdqa	%xmm4, %xmm7
	jmp	L1605
	.p2align 4,,7
L1628:
	movdqa	%xmm4, %xmm2
L1605:
	movdqa	%xmm2, %xmm4
	addl	$1, %eax
	pmulld	%xmm7, %xmm2
	movdqa	%xmm2, %xmm1
	cmpl	$2500000, %eax
	psrad	$31, %xmm1
	pcmpeqd	%xmm5, %xmm2
	paddd	%xmm6, %xmm4
	pandn	%xmm0, %xmm2
	por	%xmm2, %xmm1
	paddd	%xmm1, %xmm3
	jne	L1628
	movdqa	%xmm3, %xmm6
	psrldq	$8, %xmm6
	movdqa	32(%esp), %xmm7
	paddd	%xmm6, %xmm3
	movdqa	%xmm7, 48(%esp)
	movdqa	LC22, %xmm6
	movdqa	%xmm3, %xmm5
	psrldq	$4, %xmm5
	movdqa	LC20, %xmm2
	paddd	%xmm5, %xmm3
	movd	72(%esp), %xmm5
	pshufd	$0, %xmm5, %xmm5
	pextrd	$0, %xmm3, %eax
	movdqa	%xmm5, %xmm4
	addl	%eax, %edx
	movdqa	%xmm5, 32(%esp)
	pxor	%xmm3, %xmm3
	xorl	%eax, %eax
	movdqa	%xmm3, %xmm5
	movdqa	%xmm4, %xmm7
	jmp	L1607
	.p2align 4,,7
L1629:
	movdqa	%xmm4, %xmm2
L1607:
	movdqa	%xmm2, %xmm4
	addl	$1, %eax
	pmulld	%xmm7, %xmm2
	movdqa	%xmm2, %xmm1
	cmpl	$2500000, %eax
	psrad	$31, %xmm1
	pcmpeqd	%xmm5, %xmm2
	paddd	%xmm6, %xmm4
	pandn	%xmm0, %xmm2
	por	%xmm2, %xmm1
	paddd	%xmm1, %xmm3
	jne	L1629
	movdqa	%xmm3, %xmm6
	psrldq	$8, %xmm6
	movdqa	48(%esp), %xmm7
	paddd	%xmm6, %xmm3
	movd	76(%esp), %xmm5
	movdqa	%xmm7, 80(%esp)
	movdqa	%xmm3, %xmm6
	psrldq	$4, %xmm6
	pshufd	$0, %xmm5, %xmm5
	paddd	%xmm6, %xmm3
	movdqa	%xmm5, %xmm4
	movdqa	%xmm5, 48(%esp)
	pextrd	$0, %xmm3, %eax
	movdqa	LC22, %xmm6
	addl	%eax, %edx
	pxor	%xmm3, %xmm3
	xorl	%eax, %eax
	movdqa	LC20, %xmm2
	movdqa	%xmm3, %xmm5
	movdqa	%xmm4, %xmm7
	jmp	L1609
	.p2align 4,,7
L1630:
	movdqa	%xmm4, %xmm2
L1609:
	movdqa	%xmm2, %xmm4
	addl	$1, %eax
	pmulld	%xmm7, %xmm2
	movdqa	%xmm2, %xmm1
	cmpl	$2500000, %eax
	psrad	$31, %xmm1
	pcmpeqd	%xmm5, %xmm2
	paddd	%xmm6, %xmm4
	pandn	%xmm0, %xmm2
	por	%xmm2, %xmm1
	paddd	%xmm1, %xmm3
	jne	L1630
	movdqa	%xmm3, %xmm5
	psrldq	$8, %xmm5
	movdqa	80(%esp), %xmm7
	paddd	%xmm5, %xmm3
	movdqa	LC20, %xmm1
	movdqa	%xmm3, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm3
	pcmpeqd	%xmm6, %xmm6
	pextrd	$0, %xmm3, %eax
	pxor	%xmm3, %xmm3
	addl	%eax, %edx
	movdqa	%xmm3, %xmm5
	xorl	%eax, %eax
	jmp	L1611
	.p2align 4,,7
L1631:
	movdqa	%xmm4, %xmm1
L1611:
	movdqa	LC22, %xmm4
	addl	$1, %eax
	paddd	%xmm1, %xmm4
	pmulld	%xmm7, %xmm1
	cmpl	$2500000, %eax
	pxor	%xmm6, %xmm1
	movdqa	%xmm1, %xmm2
	psrad	$31, %xmm2
	pcmpeqd	%xmm5, %xmm1
	pandn	%xmm0, %xmm1
	por	%xmm1, %xmm2
	paddd	%xmm2, %xmm3
	jne	L1631
	movdqa	%xmm3, %xmm7
	psrldq	$8, %xmm7
	movdqa	LC20, %xmm1
	paddd	%xmm7, %xmm3
	pcmpeqd	%xmm6, %xmm6
	movdqa	%xmm3, %xmm7
	psrldq	$4, %xmm7
	paddd	%xmm7, %xmm3
	movdqa	LC22, %xmm7
	pextrd	$0, %xmm3, %eax
	pxor	%xmm3, %xmm3
	addl	%eax, %edx
	movdqa	%xmm3, %xmm5
	xorl	%eax, %eax
	jmp	L1613
	.p2align 4,,7
L1632:
	movdqa	%xmm4, %xmm1
L1613:
	movdqa	%xmm1, %xmm4
	pmulld	16(%esp), %xmm1
	addl	$1, %eax
	cmpl	$2500000, %eax
	paddd	%xmm7, %xmm4
	pxor	%xmm6, %xmm1
	movdqa	%xmm1, %xmm2
	psrad	$31, %xmm2
	pcmpeqd	%xmm5, %xmm1
	pandn	%xmm0, %xmm1
	por	%xmm1, %xmm2
	paddd	%xmm2, %xmm3
	jne	L1632
	movdqa	%xmm3, %xmm5
	psrldq	$8, %xmm5
	movdqa	LC22, %xmm7
	paddd	%xmm5, %xmm3
	movdqa	LC20, %xmm1
	movdqa	%xmm3, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm3
	pcmpeqd	%xmm6, %xmm6
	pextrd	$0, %xmm3, %eax
	pxor	%xmm3, %xmm3
	addl	%eax, %edx
	movdqa	%xmm3, %xmm5
	xorl	%eax, %eax
	jmp	L1615
	.p2align 4,,7
L1633:
	movdqa	%xmm4, %xmm1
L1615:
	movdqa	%xmm1, %xmm4
	pmulld	32(%esp), %xmm1
	addl	$1, %eax
	cmpl	$2500000, %eax
	paddd	%xmm7, %xmm4
	pxor	%xmm6, %xmm1
	movdqa	%xmm1, %xmm2
	psrad	$31, %xmm2
	pcmpeqd	%xmm5, %xmm1
	pandn	%xmm0, %xmm1
	por	%xmm1, %xmm2
	paddd	%xmm2, %xmm3
	jne	L1633
	movdqa	%xmm3, %xmm7
	psrldq	$8, %xmm7
	movdqa	LC20, %xmm1
	paddd	%xmm7, %xmm3
	pcmpeqd	%xmm6, %xmm6
	movdqa	LC22, %xmm7
	movdqa	%xmm3, %xmm5
	psrldq	$4, %xmm5
	paddd	%xmm5, %xmm3
	pextrd	$0, %xmm3, %eax
	pxor	%xmm3, %xmm3
	addl	%eax, %edx
	movdqa	%xmm3, %xmm5
	xorl	%eax, %eax
	jmp	L1617
	.p2align 4,,7
L1634:
	movdqa	%xmm4, %xmm1
L1617:
	movdqa	%xmm1, %xmm4
	pmulld	48(%esp), %xmm1
	addl	$1, %eax
	cmpl	$2500000, %eax
	paddd	%xmm7, %xmm4
	pxor	%xmm6, %xmm1
	movdqa	%xmm1, %xmm2
	psrad	$31, %xmm2
	pcmpeqd	%xmm5, %xmm1
	pandn	%xmm0, %xmm1
	por	%xmm1, %xmm2
	paddd	%xmm2, %xmm3
	jne	L1634
	movdqa	%xmm3, %xmm0
	psrldq	$8, %xmm0
	xorl	%ecx, %ecx
	paddd	%xmm0, %xmm3
	movl	$10000000, %esi
	movdqa	%xmm3, %xmm0
	psrldq	$4, %xmm0
	movl	$1801439851, %ebp
	paddd	%xmm0, %xmm3
	pextrd	$0, %xmm3, %ebx
	addl	%edx, %ebx
	.p2align 4,,7
L1619:
	movl	%ecx, %eax
	imull	%ebp
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$22, %edx
	subl	%eax, %edx
	setne	%al
	addl	%edi, %ecx
	sarl	$31, %edx
	movzbl	%al, %eax
	orl	%edx, %eax
	addl	%eax, %ebx
	subl	$1, %esi
	jne	L1619
	movl	68(%esp), %ebp
	xorl	%ecx, %ecx
	movl	$10000000, %esi
	movl	$1801439851, %edi
	.p2align 4,,7
L1621:
	movl	%ecx, %eax
	imull	%edi
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$22, %edx
	subl	%eax, %edx
	setne	%al
	addl	%ebp, %ecx
	sarl	$31, %edx
	movzbl	%al, %eax
	orl	%edx, %eax
	addl	%eax, %ebx
	subl	$1, %esi
	jne	L1621
	movl	72(%esp), %ebp
	xorl	%ecx, %ecx
	movl	$10000000, %esi
	movl	$1801439851, %edi
	.p2align 4,,7
L1623:
	movl	%ecx, %eax
	imull	%edi
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$22, %edx
	subl	%eax, %edx
	setne	%al
	addl	%ebp, %ecx
	sarl	$31, %edx
	movzbl	%al, %eax
	orl	%edx, %eax
	addl	%eax, %ebx
	subl	$1, %esi
	jne	L1623
	movl	76(%esp), %ebp
	xorl	%ecx, %ecx
	movl	$10000000, %esi
	movl	$1801439851, %edi
	.p2align 4,,7
L1625:
	movl	%ecx, %eax
	imull	%edi
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$22, %edx
	subl	%eax, %edx
	setne	%al
	addl	%ebp, %ecx
	sarl	$31, %edx
	movzbl	%al, %eax
	orl	%edx, %eax
	addl	%eax, %ebx
	subl	$1, %esi
	jne	L1625
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	96(%esp), %eax
	sbbl	100(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%ebx, 148(%esp)
	movl	$LC12, 144(%esp)
	addl	$124, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3277:
	.p2align 4,,15
	.globl	__Z27runTestOpt08_Type9_Appendixiiii
	.def	__Z27runTestOpt08_Type9_Appendixiiii;	.scl	2;	.type	32;	.endef
__Z27runTestOpt08_Type9_Appendixiiii:
LFB3278:
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
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	84(%esp), %eax
	movl	$LC17, (%esp)
	movl	80(%esp), %ebp
	movl	%eax, 16(%esp)
	movl	88(%esp), %eax
	movl	%eax, 20(%esp)
	movl	92(%esp), %eax
	movl	%eax, 32(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	pxor	%xmm3, %xmm3
	movdqa	LC22, %xmm7
	movl	%ebp, 36(%esp)
	movdqa	LC20, %xmm1
	movdqa	%xmm3, %xmm4
	movd	36(%esp), %xmm6
	pshufd	$0, %xmm6, %xmm6
	movl	%eax, 24(%esp)
	xorl	%eax, %eax
	movl	%edx, 28(%esp)
	jmp	L1637
	.p2align 4,,7
L1669:
	movdqa	%xmm5, %xmm1
L1637:
	addl	$1, %eax
	movdqa	%xmm1, %xmm5
	pmulld	%xmm6, %xmm1
	cmpl	$2500000, %eax
	movdqa	%xmm1, %xmm2
	movdqa	%xmm4, %xmm0
	pcmpeqd	%xmm4, %xmm2
	pcmpgtd	%xmm1, %xmm0
	pandn	LC123, %xmm2
	movdqa	%xmm0, %xmm1
	paddd	%xmm7, %xmm5
	por	%xmm2, %xmm1
	paddd	%xmm1, %xmm3
	jne	L1669
	movdqa	%xmm3, %xmm6
	psrldq	$8, %xmm6
	movdqa	LC22, %xmm7
	paddd	%xmm6, %xmm3
	xorl	%eax, %eax
	movdqa	LC20, %xmm1
	movdqa	%xmm3, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm3
	movd	16(%esp), %xmm6
	pshufd	$0, %xmm6, %xmm6
	pextrd	$0, %xmm3, %edx
	pxor	%xmm3, %xmm3
	movdqa	%xmm3, %xmm4
	jmp	L1639
	.p2align 4,,7
L1670:
	movdqa	%xmm5, %xmm1
L1639:
	addl	$1, %eax
	movdqa	%xmm1, %xmm5
	pmulld	%xmm6, %xmm1
	cmpl	$2500000, %eax
	movdqa	%xmm1, %xmm2
	movdqa	%xmm4, %xmm0
	pcmpeqd	%xmm4, %xmm2
	pcmpgtd	%xmm1, %xmm0
	pandn	LC123, %xmm2
	movdqa	%xmm0, %xmm1
	paddd	%xmm7, %xmm5
	por	%xmm2, %xmm1
	paddd	%xmm1, %xmm3
	jne	L1670
	movdqa	%xmm3, %xmm6
	psrldq	$8, %xmm6
	movdqa	LC22, %xmm7
	paddd	%xmm6, %xmm3
	movdqa	LC20, %xmm1
	movdqa	%xmm3, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm3
	movd	20(%esp), %xmm6
	pshufd	$0, %xmm6, %xmm6
	pextrd	$0, %xmm3, %eax
	pxor	%xmm3, %xmm3
	addl	%eax, %edx
	movdqa	%xmm3, %xmm4
	xorl	%eax, %eax
	jmp	L1641
	.p2align 4,,7
L1671:
	movdqa	%xmm5, %xmm1
L1641:
	addl	$1, %eax
	movdqa	%xmm1, %xmm5
	pmulld	%xmm6, %xmm1
	cmpl	$2500000, %eax
	movdqa	%xmm1, %xmm2
	movdqa	%xmm4, %xmm0
	pcmpeqd	%xmm4, %xmm2
	pcmpgtd	%xmm1, %xmm0
	pandn	LC123, %xmm2
	movdqa	%xmm0, %xmm1
	paddd	%xmm7, %xmm5
	por	%xmm2, %xmm1
	paddd	%xmm1, %xmm3
	jne	L1671
	movdqa	%xmm3, %xmm6
	psrldq	$8, %xmm6
	movdqa	LC20, %xmm1
	paddd	%xmm6, %xmm3
	movdqa	%xmm3, %xmm6
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm3
	movdqa	LC22, %xmm6
	pextrd	$0, %xmm3, %eax
	movd	32(%esp), %xmm3
	addl	%eax, %edx
	pshufd	$0, %xmm3, %xmm5
	xorl	%eax, %eax
	pxor	%xmm3, %xmm3
	movdqa	%xmm3, %xmm4
	jmp	L1644
	.p2align 4,,7
L1642:
	movdqa	%xmm7, %xmm1
L1644:
	addl	$1, %eax
	movdqa	%xmm1, %xmm7
	pmulld	%xmm5, %xmm1
	cmpl	$2500000, %eax
	movdqa	%xmm1, %xmm2
	movdqa	%xmm4, %xmm0
	pcmpeqd	%xmm4, %xmm2
	pcmpgtd	%xmm1, %xmm0
	pandn	LC123, %xmm2
	movdqa	%xmm0, %xmm1
	paddd	%xmm6, %xmm7
	por	%xmm2, %xmm1
	paddd	%xmm1, %xmm3
	jne	L1642
	movdqa	%xmm3, %xmm6
	psrldq	$8, %xmm6
	movl	%ebp, %edi
	paddd	%xmm6, %xmm3
	movl	$10000000, %eax
	movdqa	%xmm3, %xmm6
	psrldq	$4, %xmm6
	movl	$-1, %ecx
	paddd	%xmm6, %xmm3
	negl	%edi
	pextrd	$0, %xmm3, %ebx
	addl	%edx, %ebx
	movl	%ebp, %esi
	xorl	%edx, %edx
	addl	%ecx, %ebx
	subl	$1, %eax
	notl	%esi
	movl	%ebp, 36(%esp)
	je	L1672
	.p2align 4,,7
L1646:
	movl	%esi, %ebp
	movl	$-1, %ecx
	addl	%edx, %ebp
	js	L1645
	setne	%cl
	movzbl	%cl, %ecx
L1645:
	addl	%edi, %edx
	addl	%ecx, %ebx
	subl	$1, %eax
	jne	L1646
L1672:
	movl	16(%esp), %esi
	movl	$10000000, %eax
	movl	$-1, %ecx
	xorl	%edx, %edx
	addl	%ecx, %ebx
	movl	%esi, %edi
	notl	%esi
	negl	%edi
	subl	$1, %eax
	je	L1673
	.p2align 4,,7
L1649:
	movl	%esi, %ebp
	movl	$-1, %ecx
	addl	%edx, %ebp
	js	L1648
	setne	%cl
	movzbl	%cl, %ecx
L1648:
	addl	%edi, %edx
	addl	%ecx, %ebx
	subl	$1, %eax
	jne	L1649
L1673:
	movl	20(%esp), %esi
	movl	$10000000, %eax
	movl	$-1, %ecx
	xorl	%edx, %edx
	addl	%ecx, %ebx
	movl	%esi, %edi
	notl	%esi
	negl	%edi
	subl	$1, %eax
	je	L1674
	.p2align 4,,7
L1652:
	movl	%esi, %ebp
	movl	$-1, %ecx
	addl	%edx, %ebp
	js	L1651
	setne	%cl
	movzbl	%cl, %ecx
L1651:
	addl	%edi, %edx
	addl	%ecx, %ebx
	subl	$1, %eax
	jne	L1652
L1674:
	movl	32(%esp), %esi
	movl	$10000000, %eax
	movl	$-1, %ecx
	xorl	%edx, %edx
	addl	%ecx, %ebx
	movl	%esi, %edi
	notl	%esi
	negl	%edi
	subl	$1, %eax
	je	L1675
	.p2align 4,,7
L1655:
	movl	%esi, %ebp
	movl	$-1, %ecx
	addl	%edx, %ebp
	js	L1654
	setne	%cl
	movzbl	%cl, %ecx
L1654:
	addl	%edi, %edx
	addl	%ecx, %ebx
	subl	$1, %eax
	jne	L1655
L1675:
	movl	36(%esp), %ebp
	xorl	%ecx, %ecx
	movl	$10000000, %esi
	movl	$-1, %edi
	.p2align 4,,7
L1657:
	movl	$1801439851, %eax
	imull	%ecx
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$22, %edx
	subl	%eax, %edx
	setne	%al
	testl	%edx, %edx
	movzbl	%al, %eax
	cmovs	%edi, %eax
	addl	%ebp, %ecx
	addl	%eax, %ebx
	subl	$1, %esi
	jne	L1657
	xorl	%ecx, %ecx
	movl	$10000000, %esi
	movl	$1801439851, %ebp
	movl	$-1, %edi
	.p2align 4,,7
L1659:
	movl	%ecx, %eax
	imull	%ebp
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$22, %edx
	subl	%eax, %edx
	setne	%al
	testl	%edx, %edx
	movzbl	%al, %eax
	cmovs	%edi, %eax
	addl	%eax, %ebx
	addl	16(%esp), %ecx
	subl	$1, %esi
	jne	L1659
	xorl	%ecx, %ecx
	movl	$10000000, %esi
	movl	$1801439851, %ebp
	movl	$-1, %edi
	.p2align 4,,7
L1661:
	movl	%ecx, %eax
	imull	%ebp
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$22, %edx
	subl	%eax, %edx
	setne	%al
	testl	%edx, %edx
	movzbl	%al, %eax
	cmovs	%edi, %eax
	addl	%eax, %ebx
	addl	20(%esp), %ecx
	subl	$1, %esi
	jne	L1661
	xorl	%ecx, %ecx
	movl	$10000000, %esi
	movl	$1801439851, %ebp
	movl	$-1, %edi
	.p2align 4,,7
L1663:
	movl	%ecx, %eax
	imull	%ebp
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$22, %edx
	subl	%eax, %edx
	setne	%al
	testl	%edx, %edx
	movzbl	%al, %eax
	cmovs	%edi, %eax
	addl	%eax, %ebx
	addl	32(%esp), %ecx
	subl	$1, %esi
	jne	L1663
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	24(%esp), %eax
	sbbl	28(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%ebx, 84(%esp)
	movl	$LC12, 80(%esp)
	addl	$60, %esp
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
	jmp	_printf
	.cfi_endproc
LFE3278:
	.section .rdata,"dr"
	.align 4
LC124:
	.ascii "Judge1(%d) ... %d / %d / %d (%d)\12\0"
	.align 4
LC125:
	.ascii "Judge2(%d) ... %d / %d / %d (%d)\12\0"
LC126:
	.ascii "Judge3(%d, %d) ... %d (%d)\12\0"
LC127:
	.ascii "Align64(%d) ... %d / %d (%d)\12\0"
	.align 4
LC128:
	.ascii "CountBits(0x%08x) ... %d / %d / %d (%d)\12\0"
	.align 4
LC129:
	.ascii "MSB(0x%08x) ... %d / %d / %d / %d / %d (%d)\12\0"
	.align 4
LC130:
	.ascii "LSB(0x%08x) ... %d / %d / %d / %d / %d (%d)\12\0"
	.align 4
LC131:
	.ascii "Abs(%d) ... %d / %d / %d (%d)\12\0"
LC132:
	.ascii "Sign(%d) ... %d / %d (%d)\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt08_1timev
	.def	__Z18runTestOpt08_1timev;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_1timev:
LFB3279:
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
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	$0, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$0, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$0, 4(%esp)
	movl	$LC124, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$10, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$10, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$10, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$10, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$10, 4(%esp)
	movl	$LC124, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$100, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$100, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$100, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$100, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$100, 4(%esp)
	movl	$LC124, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$150, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$150, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$150, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$150, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$150, 4(%esp)
	movl	$LC124, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$200, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$200, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$200, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$200, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$200, 4(%esp)
	movl	$LC124, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$250, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$250, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$250, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$250, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$250, 4(%esp)
	movl	$LC124, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$300, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$300, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$300, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$300, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$300, 4(%esp)
	movl	$LC124, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$350, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$350, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$350, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$350, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$350, 4(%esp)
	movl	$LC124, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$400, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$400, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$400, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$400, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$400, 4(%esp)
	movl	$LC124, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$450, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$450, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$450, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$450, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$450, 4(%esp)
	movl	$LC124, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$0, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	$0, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type2_After3i
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type2_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type2_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$0, 4(%esp)
	movl	$LC125, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$10, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	$10, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type2_After3i
	movl	$10, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type2_After2i
	movl	$10, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type2_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$10, 4(%esp)
	movl	$LC125, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$100, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	$100, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type2_After3i
	movl	$100, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type2_After2i
	movl	$100, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type2_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$100, 4(%esp)
	movl	$LC125, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$150, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	$150, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type2_After3i
	movl	$150, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type2_After2i
	movl	$150, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type2_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$150, 4(%esp)
	movl	$LC125, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$200, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	$200, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type2_After3i
	movl	$200, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type2_After2i
	movl	$200, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type2_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$200, 4(%esp)
	movl	$LC125, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$250, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	$250, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type2_After3i
	movl	$250, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type2_After2i
	movl	$250, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type2_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$250, 4(%esp)
	movl	$LC125, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	call	__Z22testOpt08_Type3_Beforeii
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	movzbl	%al, %ebx
	call	__Z21testOpt08_Type3_Afterii
	movl	%ebx, 16(%esp)
	movl	$0, 8(%esp)
	movl	$0, 4(%esp)
	movl	$LC126, (%esp)
	movzbl	%al, %eax
	movl	%eax, 12(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$100, (%esp)
	call	__Z22testOpt08_Type3_Beforeii
	movl	$0, 4(%esp)
	movl	$100, (%esp)
	movzbl	%al, %ebx
	call	__Z21testOpt08_Type3_Afterii
	movl	%ebx, 16(%esp)
	movl	$0, 8(%esp)
	movl	$100, 4(%esp)
	movl	$LC126, (%esp)
	movzbl	%al, %eax
	movl	%eax, 12(%esp)
	call	_printf
	movl	$100, 4(%esp)
	movl	$0, (%esp)
	call	__Z22testOpt08_Type3_Beforeii
	movl	$100, 4(%esp)
	movl	$0, (%esp)
	movzbl	%al, %ebx
	call	__Z21testOpt08_Type3_Afterii
	movl	%ebx, 16(%esp)
	movl	$100, 8(%esp)
	movl	$0, 4(%esp)
	movl	$LC126, (%esp)
	movzbl	%al, %eax
	movl	%eax, 12(%esp)
	call	_printf
	movl	$100, 4(%esp)
	movl	$100, (%esp)
	call	__Z22testOpt08_Type3_Beforeii
	movl	$100, 4(%esp)
	movl	$100, (%esp)
	movzbl	%al, %ebx
	call	__Z21testOpt08_Type3_Afterii
	movl	%ebx, 16(%esp)
	movl	$100, 8(%esp)
	movl	$100, 4(%esp)
	movl	$LC126, (%esp)
	movzbl	%al, %eax
	movl	%eax, 12(%esp)
	call	_printf
	movl	$0, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type4_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type4_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$0, 4(%esp)
	movl	$LC127, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$63, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	$63, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type4_After2i
	movl	$63, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type4_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$63, 4(%esp)
	movl	$LC127, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$64, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	$64, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type4_After2i
	movl	$64, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type4_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$64, 4(%esp)
	movl	$LC127, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$65, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	$65, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type4_After2i
	movl	$65, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type4_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$65, 4(%esp)
	movl	$LC127, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$127, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	$127, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type4_After2i
	movl	$127, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type4_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$127, 4(%esp)
	movl	$LC127, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$128, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	$128, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type4_After2i
	movl	$128, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type4_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$128, 4(%esp)
	movl	$LC127, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$129, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	$129, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type4_After2i
	movl	$129, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type4_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$129, 4(%esp)
	movl	$LC127, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$0, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$0, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$0, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$1, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-2147483648, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$-2147483648, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$-2147483648, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$-2147483648, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-2147483648, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-2147483647, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$-2147483647, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$-2147483647, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$-2147483647, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-2147483647, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$98304, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$98304, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$98304, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$98304, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$98304, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$528384, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$528384, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$528384, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$528384, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$528384, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1050624, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$1050624, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$1050624, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$1050624, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1050624, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$8388864, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$8388864, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$8388864, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$8388864, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$8388864, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$16777344, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$16777344, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$16777344, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$16777344, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$16777344, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$134217744, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$134217744, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$134217744, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$134217744, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$134217744, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$268435464, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$268435464, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$268435464, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$268435464, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$268435464, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$286331153, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$286331153, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$286331153, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$286331153, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$286331153, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-2004318072, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$-2004318072, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$-2004318072, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$-2004318072, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-2004318072, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1431655765, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$1431655765, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$1431655765, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$1431655765, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1431655765, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-1431655766, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$-1431655766, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$-1431655766, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$-1431655766, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-1431655766, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$305419896, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$305419896, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$305419896, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$305419896, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$305419896, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-1698898192, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$-1698898192, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$-1698898192, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$-1698898192, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-1698898192, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-1, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$-1, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$-1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$-1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-1, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$0, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$0, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$0, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$1, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$2, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$2, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$2, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$2, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$2, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$4, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$4, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$4, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$4, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$4, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$8, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$8, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$8, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$8, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$8, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$16, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$16, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$16, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$16, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$16, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$32, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$32, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$32, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$32, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$32, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$64, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$64, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$64, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$64, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$64, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$128, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$128, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$128, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$128, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$128, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$256, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$256, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$256, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$256, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$256, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$512, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$512, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$512, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$512, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$512, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1024, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$1024, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$1024, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$1024, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1024, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$2048, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$2048, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$2048, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$2048, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$2048, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$4096, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$4096, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$4096, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$4096, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$4096, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$8192, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$8192, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$8192, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$8192, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$8192, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$16384, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$16384, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$16384, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$16384, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$16384, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$32768, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$32768, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$32768, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$32768, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$32768, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$65536, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$65536, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$65536, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$65536, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$65536, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$131072, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$131072, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$131072, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$131072, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$131072, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$262144, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$262144, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$262144, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$262144, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$262144, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$524288, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$524288, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$524288, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$524288, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$524288, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1048576, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$1048576, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$1048576, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$1048576, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1048576, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$2097152, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$2097152, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$2097152, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$2097152, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$2097152, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$4194304, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$4194304, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$4194304, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$4194304, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$4194304, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$8388608, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$8388608, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$8388608, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$8388608, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$8388608, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$16777216, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$16777216, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$16777216, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$16777216, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$16777216, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$33554432, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$33554432, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$33554432, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$33554432, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$33554432, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$67108864, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$67108864, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$67108864, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$67108864, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$67108864, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$134217728, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$134217728, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$134217728, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$134217728, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$134217728, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$268435456, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$268435456, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$268435456, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$268435456, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$268435456, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$536870912, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$536870912, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$536870912, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$536870912, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$536870912, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1073741824, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$1073741824, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$1073741824, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$1073741824, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1073741824, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-2147483648, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$-2147483648, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type5_After3i
	movl	$-2147483648, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$-2147483648, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-2147483648, 4(%esp)
	movl	$LC128, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$0, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$0, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$0, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$0, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$0, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$1, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$1, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$1, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$1, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$-2147483648, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$-2147483648, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$-2147483648, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$-2147483648, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$-2147483648, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$-2147483648, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$-2147483648, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$286331153, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$286331153, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$286331153, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$286331153, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$286331153, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$286331153, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$286331153, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$-2004318072, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$-2004318072, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$-2004318072, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$-2004318072, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$-2004318072, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$-2004318072, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$-2004318072, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$98304, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$98304, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$98304, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$98304, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$98304, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$98304, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$98304, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$528384, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$528384, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$528384, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$528384, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$528384, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$528384, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$528384, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$1050624, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$1050624, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$1050624, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$1050624, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$1050624, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$1050624, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1050624, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$8388864, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$8388864, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$8388864, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$8388864, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$8388864, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$8388864, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$8388864, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$16777344, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$16777344, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$16777344, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$16777344, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$16777344, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$16777344, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$16777344, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$134217744, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$134217744, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$134217744, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$134217744, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$134217744, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$134217744, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$134217744, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$268435464, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$268435464, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$268435464, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$268435464, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$268435464, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$268435464, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$268435464, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$1431655765, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$1431655765, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$1431655765, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$1431655765, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$1431655765, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$1431655765, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1431655765, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$-1431655766, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$-1431655766, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$-1431655766, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$-1431655766, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$-1431655766, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$-1431655766, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$-1431655766, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$305419896, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$305419896, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$305419896, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$305419896, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$305419896, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$305419896, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$305419896, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$-1698898192, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$-1698898192, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$-1698898192, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$-1698898192, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$-1698898192, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$-1698898192, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$-1698898192, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$-1, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$-1, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$-1, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$-1, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$-1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$-1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$-1, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$0, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$0, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$0, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$0, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$0, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$1, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$1, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$1, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$1, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$2, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$2, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$2, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$2, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$2, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$2, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$2, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$4, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$4, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$4, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$4, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$4, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$4, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$4, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$8, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$8, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$8, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$8, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$8, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$8, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$8, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$16, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$16, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$16, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$16, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$16, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$16, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$16, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$32, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$32, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$32, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$32, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$32, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$32, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$32, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$64, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$64, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$64, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$64, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$64, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$64, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$64, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$128, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$128, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$128, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$128, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$128, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$128, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$128, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$256, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$256, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$256, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$256, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$256, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$256, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$256, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$512, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$512, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$512, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$512, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$512, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$512, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$512, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$1024, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$1024, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$1024, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$1024, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$1024, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$1024, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1024, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$2048, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$2048, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$2048, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$2048, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$2048, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$2048, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$2048, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$4096, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$4096, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$4096, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$4096, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$4096, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$4096, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$4096, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$8192, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$8192, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$8192, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$8192, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$8192, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$8192, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$8192, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$16384, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$16384, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$16384, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$16384, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$16384, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$16384, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$16384, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$32768, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$32768, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$32768, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$32768, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$32768, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$32768, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$32768, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$65536, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$65536, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$65536, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$65536, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$65536, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$65536, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$65536, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$131072, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$131072, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$131072, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$131072, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$131072, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$131072, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$131072, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$262144, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$262144, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$262144, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$262144, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$262144, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$262144, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$262144, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$524288, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$524288, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$524288, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$524288, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$524288, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$524288, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$524288, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$1048576, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$1048576, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$1048576, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$1048576, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$1048576, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$1048576, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1048576, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$2097152, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$2097152, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$2097152, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$2097152, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$2097152, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$2097152, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$2097152, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$4194304, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$4194304, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$4194304, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$4194304, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$4194304, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$4194304, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$4194304, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$8388608, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$8388608, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$8388608, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$8388608, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$8388608, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$8388608, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$8388608, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$16777216, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$16777216, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$16777216, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$16777216, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$16777216, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$16777216, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$16777216, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$33554432, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$33554432, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$33554432, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$33554432, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$33554432, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$33554432, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$33554432, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$67108864, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$67108864, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$67108864, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$67108864, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$67108864, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$67108864, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$67108864, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$134217728, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$134217728, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$134217728, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$134217728, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$134217728, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$134217728, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$134217728, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$268435456, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$268435456, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$268435456, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$268435456, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$268435456, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$268435456, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$268435456, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$536870912, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$536870912, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$536870912, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$536870912, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$536870912, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$536870912, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$536870912, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$1073741824, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$1073741824, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$1073741824, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$1073741824, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$1073741824, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$1073741824, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1073741824, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$-2147483648, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$-2147483648, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type6_After5i
	movl	$-2147483648, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type6_After4i
	movl	$-2147483648, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type6_After3i
	movl	$-2147483648, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$-2147483648, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$-2147483648, 4(%esp)
	movl	$LC129, (%esp)
	call	_printf
	movl	$0, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$0, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$0, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$0, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$0, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$1, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$1, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$1, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$1, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$-2147483648, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$-2147483648, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$-2147483648, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$-2147483648, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$-2147483648, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$-2147483648, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$-2147483648, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$286331153, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$286331153, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$286331153, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$286331153, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$286331153, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$286331153, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$286331153, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$-2004318072, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$-2004318072, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$-2004318072, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$-2004318072, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$-2004318072, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$-2004318072, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$-2004318072, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$98304, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$98304, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$98304, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$98304, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$98304, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$98304, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$98304, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$528384, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$528384, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$528384, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$528384, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$528384, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$528384, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$528384, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$1050624, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$1050624, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$1050624, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$1050624, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$1050624, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$1050624, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1050624, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$8388864, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$8388864, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$8388864, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$8388864, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$8388864, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$8388864, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$8388864, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$16777344, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$16777344, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$16777344, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$16777344, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$16777344, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$16777344, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$16777344, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$134217744, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$134217744, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$134217744, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$134217744, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$134217744, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$134217744, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$134217744, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$268435464, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$268435464, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$268435464, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$268435464, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$268435464, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$268435464, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$268435464, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$1431655765, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$1431655765, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$1431655765, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$1431655765, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$1431655765, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$1431655765, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1431655765, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$-1431655766, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$-1431655766, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$-1431655766, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$-1431655766, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$-1431655766, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$-1431655766, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$-1431655766, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$305419896, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$305419896, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$305419896, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$305419896, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$305419896, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$305419896, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$305419896, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$-1698898192, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$-1698898192, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$-1698898192, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$-1698898192, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$-1698898192, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$-1698898192, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$-1698898192, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$-1, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$-1, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$-1, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$-1, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$-1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$-1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$-1, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$0, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$0, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$0, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$0, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$0, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$1, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$1, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$1, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$1, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$2, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$2, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$2, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$2, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$2, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$2, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$2, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$4, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$4, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$4, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$4, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$4, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$4, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$4, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$8, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$8, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$8, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$8, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$8, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$8, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$8, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$16, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$16, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$16, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$16, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$16, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$16, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$16, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$32, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$32, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$32, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$32, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$32, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$32, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$32, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$64, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$64, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$64, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$64, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$64, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$64, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$64, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$128, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$128, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$128, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$128, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$128, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$128, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$128, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$256, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$256, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$256, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$256, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$256, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$256, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$256, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$512, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$512, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$512, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$512, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$512, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$512, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$512, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$1024, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$1024, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$1024, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$1024, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$1024, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$1024, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1024, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$2048, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$2048, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$2048, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$2048, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$2048, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$2048, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$2048, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$4096, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$4096, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$4096, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$4096, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$4096, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$4096, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$4096, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$8192, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$8192, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$8192, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$8192, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$8192, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$8192, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$8192, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$16384, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$16384, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$16384, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$16384, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$16384, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$16384, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$16384, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$32768, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$32768, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$32768, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$32768, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$32768, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$32768, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$32768, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$65536, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$65536, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$65536, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$65536, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$65536, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$65536, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$65536, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$131072, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$131072, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$131072, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$131072, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$131072, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$131072, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$131072, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$262144, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$262144, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$262144, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$262144, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$262144, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$262144, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$262144, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$524288, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$524288, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$524288, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$524288, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$524288, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$524288, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$524288, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$1048576, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$1048576, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$1048576, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$1048576, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$1048576, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$1048576, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1048576, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$2097152, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$2097152, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$2097152, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$2097152, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$2097152, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$2097152, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$2097152, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$4194304, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$4194304, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$4194304, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$4194304, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$4194304, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$4194304, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$4194304, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$8388608, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$8388608, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$8388608, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$8388608, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$8388608, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$8388608, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$8388608, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$16777216, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$16777216, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$16777216, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$16777216, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$16777216, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$16777216, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$16777216, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$33554432, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$33554432, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$33554432, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$33554432, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$33554432, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$33554432, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$33554432, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$67108864, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$67108864, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$67108864, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$67108864, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$67108864, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$67108864, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$67108864, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$134217728, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$134217728, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$134217728, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$134217728, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$134217728, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$134217728, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$134217728, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$268435456, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$268435456, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$268435456, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$268435456, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$268435456, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$268435456, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$268435456, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$536870912, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$536870912, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$536870912, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$536870912, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$536870912, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$536870912, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$536870912, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$1073741824, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$1073741824, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$1073741824, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$1073741824, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$1073741824, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$1073741824, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1073741824, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$-2147483648, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$-2147483648, (%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt08_Type7_After5i
	movl	$-2147483648, (%esp)
	movl	%eax, %ebp
	call	__Z22testOpt08_Type7_After4i
	movl	$-2147483648, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type7_After3i
	movl	$-2147483648, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$-2147483648, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	44(%esp), %edx
	movl	%ebp, 24(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 28(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$-2147483648, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	$0, 20(%esp)
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	$0, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	$1, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	$1, 8(%esp)
	movl	$-1, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
	movl	$2, 20(%esp)
	movl	$2, 16(%esp)
	movl	$2, 12(%esp)
	movl	$2, 8(%esp)
	movl	$2, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
	movl	$2, 20(%esp)
	movl	$2, 16(%esp)
	movl	$2, 12(%esp)
	movl	$2, 8(%esp)
	movl	$-2, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
	movl	$100, 20(%esp)
	movl	$100, 16(%esp)
	movl	$100, 12(%esp)
	movl	$100, 8(%esp)
	movl	$100, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
	movl	$100, 20(%esp)
	movl	$100, 16(%esp)
	movl	$100, 12(%esp)
	movl	$100, 8(%esp)
	movl	$-100, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
	movl	$65536, 20(%esp)
	movl	$65536, 16(%esp)
	movl	$65536, 12(%esp)
	movl	$65536, 8(%esp)
	movl	$65536, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
	movl	$65536, 20(%esp)
	movl	$65536, 16(%esp)
	movl	$65536, 12(%esp)
	movl	$65536, 8(%esp)
	movl	$-65536, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
	movl	$2147483647, 20(%esp)
	movl	$2147483647, 16(%esp)
	movl	$2147483647, 12(%esp)
	movl	$2147483647, 8(%esp)
	movl	$2147483647, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
	movl	$-2147483648, 20(%esp)
	movl	$-2147483648, 16(%esp)
	movl	$-2147483648, 12(%esp)
	movl	$-2147483648, 8(%esp)
	movl	$-2147483648, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	$0, 4(%esp)
	movl	$LC132, (%esp)
	call	_printf
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	$1, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC132, (%esp)
	call	_printf
	movl	$-1, 16(%esp)
	movl	$-1, 12(%esp)
	movl	$-1, 8(%esp)
	movl	$-1, 4(%esp)
	movl	$LC132, (%esp)
	call	_printf
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	$1, 8(%esp)
	movl	$2, 4(%esp)
	movl	$LC132, (%esp)
	call	_printf
	movl	$-1, 16(%esp)
	movl	$-1, 12(%esp)
	movl	$-1, 8(%esp)
	movl	$-2, 4(%esp)
	movl	$LC132, (%esp)
	call	_printf
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	$1, 8(%esp)
	movl	$100, 4(%esp)
	movl	$LC132, (%esp)
	call	_printf
	movl	$-1, 16(%esp)
	movl	$-1, 12(%esp)
	movl	$-1, 8(%esp)
	movl	$-100, 4(%esp)
	movl	$LC132, (%esp)
	call	_printf
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	$1, 8(%esp)
	movl	$65536, 4(%esp)
	movl	$LC132, (%esp)
	call	_printf
	movl	$-1, 16(%esp)
	movl	$-1, 12(%esp)
	movl	$-1, 8(%esp)
	movl	$-65536, 4(%esp)
	movl	$LC132, (%esp)
	call	_printf
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	$1, 8(%esp)
	movl	$2147483647, 4(%esp)
	movl	$LC132, (%esp)
	call	_printf
	movl	$-1, 16(%esp)
	movl	$-1, 12(%esp)
	movl	$-1, 8(%esp)
	movl	$-2147483648, 4(%esp)
	movl	$LC132, (%esp)
	call	_printf
	addl	$60, %esp
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
LFE3279:
	.section .rdata,"dr"
LC133:
	.ascii "[Optimize Test 09]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt09v
	.def	__Z12runTestOpt09v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt09v:
LFB3280:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$LC8, (%esp)
	call	_puts
	movl	$LC133, (%esp)
	call	_puts
	call	__Z18runTestOpt09_Type1v
	call	__Z18runTestOpt09_Type2v
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z18runTestOpt09_Type3v
	.cfi_endproc
LFE3280:
	.p2align 4,,15
	.globl	__Z18runTestOpt09_Type1v
	.def	__Z18runTestOpt09_Type1v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt09_Type1v:
LFB3281:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$40024, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_def_cfa_offset 40032
	leal	16(%esp), %ebx
	movl	$100000, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	movl	%ebx, (%esp)
	call	__Z12initOpt09_t1R12dataOpt09_t1
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type1_BeforeR12dataOpt09_t1
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type1_After1R12dataOpt09_t1
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type1_After2R12dataOpt09_t1
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type1_After3R12dataOpt09_t1
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type1_After4R12dataOpt09_t1
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type1_After5R12dataOpt09_t1
	movl	%ebx, (%esp)
	call	__Z27runTestOpt09_Type1_AppendixR12dataOpt09_t1
	addl	$40024, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3281:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type1_BeforeR12dataOpt09_t1
	.def	__Z25runTestOpt09_Type1_BeforeR12dataOpt09_t1;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type1_BeforeR12dataOpt09_t1:
LFB3282:
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
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC11, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1684:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type1_BeforeR12dataOpt09_t1
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1684
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3282:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type1_After1R12dataOpt09_t1
	.def	__Z25runTestOpt09_Type1_After1R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type1_After1R12dataOpt09_t1:
LFB3283:
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
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC13, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1688:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type1_After1R12dataOpt09_t1
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1688
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3283:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type1_After2R12dataOpt09_t1
	.def	__Z25runTestOpt09_Type1_After2R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type1_After2R12dataOpt09_t1:
LFB3284:
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
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC14, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1692:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type1_After2R12dataOpt09_t1
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1692
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3284:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type1_After3R12dataOpt09_t1
	.def	__Z25runTestOpt09_Type1_After3R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type1_After3R12dataOpt09_t1:
LFB3285:
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
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC15, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1696:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type1_After3R12dataOpt09_t1
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1696
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3285:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type1_After4R12dataOpt09_t1
	.def	__Z25runTestOpt09_Type1_After4R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type1_After4R12dataOpt09_t1:
LFB3286:
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
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC16, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1700:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type1_After4R12dataOpt09_t1
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1700
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3286:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type1_After5R12dataOpt09_t1
	.def	__Z25runTestOpt09_Type1_After5R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type1_After5R12dataOpt09_t1:
LFB3287:
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
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC117, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1704:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type1_After5R12dataOpt09_t1
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1704
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3287:
	.p2align 4,,15
	.globl	__Z27runTestOpt09_Type1_AppendixR12dataOpt09_t1
	.def	__Z27runTestOpt09_Type1_AppendixR12dataOpt09_t1;	.scl	2;	.type	32;	.endef
__Z27runTestOpt09_Type1_AppendixR12dataOpt09_t1:
LFB3288:
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
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC17, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1708:
	movl	%esi, (%esp)
	call	__Z24testOpt09_Type1_AppendixR12dataOpt09_t1
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1708
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3288:
	.p2align 4,,15
	.globl	__Z18runTestOpt09_Type2v
	.def	__Z18runTestOpt09_Type2v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt09_Type2v:
LFB3289:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$480024, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_def_cfa_offset 480032
	leal	16(%esp), %ebx
	movl	$10000, 4(%esp)
	movl	$LC55, (%esp)
	call	_printf
	movl	%ebx, (%esp)
	call	__Z12initOpt09_t2R12dataOpt09_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type2_BeforeR12dataOpt09_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type2_After1R12dataOpt09_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type2_After2R12dataOpt09_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type2_After3R12dataOpt09_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type2_After4R12dataOpt09_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type2_After5R12dataOpt09_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type2_After6R12dataOpt09_t2
	movl	%ebx, (%esp)
	call	__Z27runTestOpt09_Type2_AppendixR12dataOpt09_t2
	addl	$480024, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3289:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type2_BeforeR12dataOpt09_t2
	.def	__Z25runTestOpt09_Type2_BeforeR12dataOpt09_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type2_BeforeR12dataOpt09_t2:
LFB3290:
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
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC11, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1714:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type2_BeforeR12dataOpt09_t2
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1714
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3290:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type2_After1R12dataOpt09_t2
	.def	__Z25runTestOpt09_Type2_After1R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type2_After1R12dataOpt09_t2:
LFB3291:
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
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC13, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1718:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type2_After1R12dataOpt09_t2
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1718
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3291:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type2_After2R12dataOpt09_t2
	.def	__Z25runTestOpt09_Type2_After2R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type2_After2R12dataOpt09_t2:
LFB3292:
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
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC14, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1722:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type2_After2R12dataOpt09_t2
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1722
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3292:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type2_After3R12dataOpt09_t2
	.def	__Z25runTestOpt09_Type2_After3R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type2_After3R12dataOpt09_t2:
LFB3293:
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
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC15, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1726:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type2_After3R12dataOpt09_t2
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1726
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3293:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type2_After4R12dataOpt09_t2
	.def	__Z25runTestOpt09_Type2_After4R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type2_After4R12dataOpt09_t2:
LFB3294:
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
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC16, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1730:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type2_After4R12dataOpt09_t2
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1730
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3294:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type2_After5R12dataOpt09_t2
	.def	__Z25runTestOpt09_Type2_After5R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type2_After5R12dataOpt09_t2:
LFB3295:
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
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC117, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1734:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type2_After5R12dataOpt09_t2
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1734
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3295:
	.section .rdata,"dr"
LC134:
	.ascii "  After6   ... \0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type2_After6R12dataOpt09_t2
	.def	__Z25runTestOpt09_Type2_After6R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type2_After6R12dataOpt09_t2:
LFB3296:
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
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC134, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1738:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type2_After6R12dataOpt09_t2
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1738
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3296:
	.p2align 4,,15
	.globl	__Z27runTestOpt09_Type2_AppendixR12dataOpt09_t2
	.def	__Z27runTestOpt09_Type2_AppendixR12dataOpt09_t2;	.scl	2;	.type	32;	.endef
__Z27runTestOpt09_Type2_AppendixR12dataOpt09_t2:
LFB3297:
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
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC17, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1742:
	movl	%esi, (%esp)
	call	__Z24testOpt09_Type2_AppendixR12dataOpt09_t2
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1742
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3297:
	.p2align 4,,15
	.globl	__Z18runTestOpt09_Type3v
	.def	__Z18runTestOpt09_Type3v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt09_Type3v:
LFB3298:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$480024, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_def_cfa_offset 480032
	leal	16(%esp), %ebx
	movl	$10000, 4(%esp)
	movl	$LC23, (%esp)
	call	_printf
	movl	%ebx, (%esp)
	call	__Z12initOpt09_t2R12dataOpt09_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type3_BeforeR12dataOpt09_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type3_After1R12dataOpt09_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type3_After2R12dataOpt09_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type3_After3R12dataOpt09_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type3_After4R12dataOpt09_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type3_After5R12dataOpt09_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type3_After6R12dataOpt09_t2
	addl	$480024, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3298:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type3_BeforeR12dataOpt09_t2
	.def	__Z25runTestOpt09_Type3_BeforeR12dataOpt09_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type3_BeforeR12dataOpt09_t2:
LFB3299:
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
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC11, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1748:
	movl	$10000, 4(%esp)
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type3_BeforePN12dataOpt09_t26elem_tEj
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1748
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3299:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type3_After1R12dataOpt09_t2
	.def	__Z25runTestOpt09_Type3_After1R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type3_After1R12dataOpt09_t2:
LFB3300:
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
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC13, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1752:
	movl	$10000, 4(%esp)
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type3_After1PN12dataOpt09_t26elem_tEj
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1752
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3300:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type3_After2R12dataOpt09_t2
	.def	__Z25runTestOpt09_Type3_After2R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type3_After2R12dataOpt09_t2:
LFB3301:
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
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC14, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1756:
	movl	$10000, 4(%esp)
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type3_After2PN12dataOpt09_t26elem_tEj
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1756
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3301:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type3_After3R12dataOpt09_t2
	.def	__Z25runTestOpt09_Type3_After3R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type3_After3R12dataOpt09_t2:
LFB3302:
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
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC15, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1760:
	movl	$10000, 4(%esp)
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type3_After3PN12dataOpt09_t26elem_tEj
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1760
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3302:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type3_After4R12dataOpt09_t2
	.def	__Z25runTestOpt09_Type3_After4R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type3_After4R12dataOpt09_t2:
LFB3303:
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
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC16, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1764:
	movl	$10000, 4(%esp)
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type3_After4PN12dataOpt09_t26elem_tEj
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1764
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3303:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type3_After5R12dataOpt09_t2
	.def	__Z25runTestOpt09_Type3_After5R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type3_After5R12dataOpt09_t2:
LFB3304:
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
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC117, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1768:
	movl	$10000, 4(%esp)
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type3_After5PN12dataOpt09_t26elem_tEj
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1768
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3304:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type3_After6R12dataOpt09_t2
	.def	__Z25runTestOpt09_Type3_After6R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type3_After6R12dataOpt09_t2:
LFB3305:
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
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC134, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L1772:
	movl	$10000, 4(%esp)
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type3_After6PN12dataOpt09_t26elem_tEj
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L1772
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC6
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
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
LFE3305:
	.section .rdata,"dr"
	.align 4
LC135:
	.ascii "[Test for Lambda with closure]\0"
LC136:
	.ascii "Call lambda in main().\0"
	.text
	.p2align 4,,15
	.globl	__Z14testForClosurev
	.def	__Z14testForClosurev;	.scl	2;	.type	32;	.endef
__Z14testForClosurev:
LFB3306:
	.cfi_startproc
	subl	$44, %esp
	.cfi_def_cfa_offset 48
	movl	$LC8, (%esp)
	call	_puts
	movl	$LC135, (%esp)
	call	_puts
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	movl	$0, 28(%esp)
	call	__Z9setLambdaRi
	movl	$LC136, (%esp)
	call	_puts
	call	__Z12callLambda13v
	call	__Z12callLambda13v
	.p2align 4,,5
	call	__Z12callLambda13v
	addl	$44, %esp
	.cfi_def_cfa_offset 4
	.p2align 4,,2
	ret
	.cfi_endproc
LFE3306:
	.section	.text$_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	.def	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv;	.scl	2;	.type	32;	.endef
__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv:
LFB3425:
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
	ja	L1777
	leal	1(%eax), %ecx
	movl	(%edx,%eax,4), %eax
L1778:
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
L1777:
	.cfi_restore_state
	movl	%edx, %eax
	andl	$15, %eax
	shrl	$2, %eax
	negl	%eax
	andl	$3, %eax
	je	L1794
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
	jbe	L1795
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
	jbe	L1796
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
L1779:
	movl	$227, 4(%esp)
	xorl	%ecx, %ecx
	movdqa	LC137, %xmm3
	subl	%eax, 4(%esp)
	movdqa	LC138, %xmm4
	movdqa	LC123, %xmm2
	sall	$2, %eax
	movdqa	LC139, %xmm5
	pxor	%xmm6, %xmm6
	leal	(%edx,%eax), %ebx
	leal	4(%edx,%eax), %edi
	leal	1588(%edx,%eax), %esi
	xorl	%eax, %eax
	.p2align 4,,7
L1785:
	movdqu	(%edi,%eax), %xmm1
	movdqa	(%ebx,%eax), %xmm0
	pand	%xmm3, %xmm1
	pand	%xmm4, %xmm0
	addl	$1, %ecx
	por	%xmm0, %xmm1
	movdqa	%xmm1, %xmm0
	psrld	$1, %xmm1
	movdqu	(%esi,%eax), %xmm7
	pand	%xmm2, %xmm0
	pcmpeqd	%xmm6, %xmm0
	pandn	%xmm5, %xmm0
	pxor	%xmm7, %xmm0
	pxor	%xmm1, %xmm0
	movdqa	%xmm0, (%ebx,%eax)
	addl	$16, %eax
	cmpl	$55, %ecx
	jbe	L1785
	cmpl	$224, 4(%esp)
	leal	224(%ebp), %eax
	je	L1783
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
	je	L1783
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
	je	L1783
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
L1783:
	leal	908(%edx), %eax
	andl	$15, %eax
	shrl	$2, %eax
	negl	%eax
	andl	$3, %eax
	je	L1797
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
	jbe	L1798
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
	jbe	L1799
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
L1786:
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
L1792:
	movdqu	0(%ebp,%eax), %xmm1
	movdqa	(%ebx,%eax), %xmm0
	pand	%xmm3, %xmm1
	pand	%xmm4, %xmm0
	addl	$1, %ecx
	por	%xmm0, %xmm1
	movdqa	%xmm1, %xmm0
	psrld	$1, %xmm1
	movdqu	(%edi,%eax), %xmm7
	pand	%xmm2, %xmm0
	pcmpeqd	%xmm6, %xmm0
	pandn	%xmm5, %xmm0
	pxor	%xmm7, %xmm0
	pxor	%xmm1, %xmm0
	movdqa	%xmm0, (%ebx,%eax)
	addl	$16, %eax
	cmpl	%ecx, %esi
	ja	L1792
	movl	12(%esp), %edi
	movl	4(%esp), %eax
	movl	8(%esp), %ecx
	movl	(%esp), %esi
	subl	%edi, %eax
	addl	%edi, %ecx
	cmpl	%esi, %edi
	movl	%eax, 4(%esp)
	je	L1790
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
	je	L1790
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
	je	L1790
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
L1790:
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
	jmp	L1778
	.p2align 4,,7
L1796:
	movl	$225, (%esp)
	movl	$2, %ebp
	jmp	L1779
	.p2align 4,,7
L1795:
	movl	$226, (%esp)
	movl	$1, %ebp
	jmp	L1779
	.p2align 4,,7
L1794:
	movl	$227, (%esp)
	xorl	%ebp, %ebp
	jmp	L1779
	.p2align 4,,7
L1797:
	movl	$396, 4(%esp)
	movl	$227, 8(%esp)
	jmp	L1786
	.p2align 4,,7
L1799:
	movl	$394, 4(%esp)
	movl	$229, 8(%esp)
	jmp	L1786
	.p2align 4,,7
L1798:
	movl	$395, 4(%esp)
	movl	$228, 8(%esp)
	jmp	L1786
	.cfi_endproc
LFE3425:
	.section .rdata,"dr"
LC140:
	.ascii "[Optimize Test 06]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt06v
	.def	__Z12runTestOpt06v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt06v:
LFB3199:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$122572, %eax
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	call	___chkstk_ms
	movl	$5489, %ebx
	movl	$440509467, %ebp
	subl	%eax, %esp
	.cfi_def_cfa_offset 122592
	movl	$LC8, (%esp)
	leal	2560(%esp), %edi
	call	_puts
	leal	48(%esp), %esi
	movl	$LC140, (%esp)
	call	_puts
	movl	%edi, (%esp)
	call	__Z9initOpt06R11dataOpt06_t
	movl	$1, %ecx
	movl	$5489, 48(%esp)
	.p2align 4,,7
L1817:
	movl	%ebx, %eax
	movl	%ecx, %edx
	shrl	$30, %eax
	xorl	%ebx, %eax
	shrl	$4, %edx
	imull	$1812433253, %eax, %ebx
	movl	%edx, %eax
	mull	%ebp
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	addl	%eax, %ebx
	movl	%ebx, (%esi,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1817
	movl	%esi, (%esp)
	movl	$624, 2544(%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	movl	%esi, (%esp)
	movl	%eax, 28(%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	movl	%esi, (%esp)
	movl	%eax, 32(%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	movd	32(%esp), %xmm1
	movd	28(%esp), %xmm2
	movl	%edi, (%esp)
	movl	%eax, 36(%esp)
	movd	36(%esp), %xmm0
	movq	%xmm0, 40(%esp)
	fildq	40(%esp)
	fldz
	movq	%xmm1, 40(%esp)
	fadd	%st, %st(1)
	flds	LC141
	fmul	%st, %st(2)
	flds	LC46
	fmul	%st, %st(3)
	fxch	%st(3)
	fadd	%st(2), %st
	fstps	12(%esp)
	fildq	40(%esp)
	movq	%xmm2, 40(%esp)
	fadd	%st(2), %st
	fmul	%st(1), %st
	fmul	%st(3), %st
	fadd	%st(2), %st
	fstps	8(%esp)
	fildq	40(%esp)
	fadd	%st(2), %st
	fmulp	%st, %st(1)
	fmulp	%st, %st(2)
	faddp	%st, %st(1)
	fstps	4(%esp)
	call	__Z18runTestOpt06_Type1R11dataOpt06_tfff
	addl	$122572, %esp
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
LFE3199:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB3307:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	call	___main
	call	__Z12runTestOpt01v
	call	__Z12runTestOpt02v
	.p2align 4,,5
	call	__Z12runTestOpt03v
	.p2align 4,,5
	call	__Z12runTestOpt04v
	.p2align 4,,5
	call	__Z12runTestOpt05v
	.p2align 4,,5
	call	__Z12runTestOpt06v
	.p2align 4,,5
	call	__Z12runTestOpt07v
	.p2align 4,,5
	call	__Z12runTestOpt08v
	.p2align 4,,5
	call	__Z12runTestOpt09v
	.p2align 4,,5
	call	__Z14testForClosurev
	xorl	%eax, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	.p2align 4,,2
	ret
	.cfi_endproc
LFE3307:
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt03_Type1v
	.def	__Z18runTestOpt03_Type1v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt03_Type1v:
LFB2799:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	movl	$5489, %edx
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	movl	$1, %ecx
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$440509467, %esi
	subl	$2528, %esp
	.cfi_def_cfa_offset 2544
	movl	$5489, 16(%esp)
	leal	16(%esp), %ebx
	.p2align 4,,7
L1823:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1823
	movl	$624, 2512(%esp)
	.p2align 4,,7
L1825:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L1825
	movl	$671088641, %esi
	mull	%esi
	movl	%edx, %esi
	shrl	$26, %esi
	.p2align 4,,7
L1827:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L1827
	movl	$671088641, %ebx
	mull	%ebx
	movl	$100000000, 4(%esp)
	movl	$LC10, (%esp)
	movl	%edx, %ebx
	shrl	$26, %ebx
	call	_printf
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt03_Type1_Beforeii
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
	call	__Z24runTestOpt03_Type1_Afterii
	addl	$2528, %esp
	.cfi_def_cfa_offset 16
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
LFE2799:
	.p2align 4,,15
	.globl	__Z18runTestOpt03_Type2v
	.def	__Z18runTestOpt03_Type2v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt03_Type2v:
LFB2803:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$5489, %edx
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$1, %ebx
	subl	$2572, %esp
	.cfi_def_cfa_offset 2592
	movl	$5489, 48(%esp)
	leal	48(%esp), %ebp
	.p2align 4,,7
L1831:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ebx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %ecx
	movl	%edx, %eax
	mull	%esi
	movl	%ebx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%ecx, %edx
	movl	%edx, 0(%ebp,%ebx,4)
	addl	$1, %ebx
	cmpl	$624, %ebx
	jne	L1831
	movl	$624, 2544(%esp)
	.p2align 4,,7
L1833:
	movl	%ebp, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L1833
	movl	$671088641, %edx
	mull	%edx
	movl	%edx, 32(%esp)
	shrl	$26, 32(%esp)
	.p2align 4,,7
L1835:
	movl	%ebp, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L1835
	movl	$671088641, %edx
	mull	%edx
	movl	%edx, 36(%esp)
	shrl	$26, 36(%esp)
	.p2align 4,,7
L1837:
	movl	%ebp, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L1837
	movl	$671088641, %ebx
	mull	%ebx
	movl	%edx, %ebx
	shrl	$26, %ebx
	.p2align 4,,7
L1839:
	movl	%ebp, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L1839
	movl	$671088641, %esi
	mull	%esi
	movl	%edx, %esi
	shrl	$26, %esi
	.p2align 4,,7
L1841:
	movl	%ebp, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L1841
	movl	$671088641, %edx
	mull	%edx
	movl	%edx, %edi
	shrl	$26, %edi
	.p2align 4,,7
L1843:
	movl	%ebp, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L1843
	movl	$671088641, %edx
	mull	%edx
	movl	%edx, 40(%esp)
	shrl	$26, 40(%esp)
	.p2align 4,,7
L1845:
	movl	%ebp, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L1845
	movl	$671088641, %edx
	mull	%edx
	movl	$100000000, 4(%esp)
	movl	$LC55, (%esp)
	shrl	$26, %edx
	movl	%edx, 44(%esp)
	call	_printf
	movl	40(%esp), %ebp
	movl	44(%esp), %edx
	movl	36(%esp), %eax
	movl	32(%esp), %ecx
	movl	%ebp, 20(%esp)
	movl	%edx, 24(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%ecx, (%esp)
	call	__Z25runTestOpt03_Type2_Beforeiiiiiii
	movl	44(%esp), %edx
	movl	36(%esp), %eax
	movl	32(%esp), %ecx
	movl	%ebp, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%edx, 24(%esp)
	movl	%eax, 4(%esp)
	movl	%ecx, (%esp)
	call	__Z24runTestOpt03_Type2_Afteriiiiiii
	addl	$2572, %esp
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
LFE2803:
	.section .rdata,"dr"
LC142:
	.ascii "Type6: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type6v
	.def	__Z18runTestOpt08_Type6v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type6v:
LFB3256:
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
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$10000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC142, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L1849:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1849
	movl	$624, 2512(%esp)
	.p2align 4,,7
L1851:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L1851
	leal	-1(%eax), %esi
	.p2align 4,,7
L1853:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L1853
	leal	-1(%eax), %edi
	.p2align 4,,7
L1857:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L1857
	leal	-1(%eax), %ebp
	.p2align 4,,7
L1858:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L1858
	leal	-1(%eax), %ebx
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type6_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type6_After1iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type6_After2iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type6_After3iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type6_After4iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type6_After5iiii
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
LFE3256:
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type3v
	.def	__Z18runTestOpt08_Type3v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type3v:
LFB3244:
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
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$100000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC23, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L1864:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1864
	movl	$624, 2512(%esp)
	.p2align 4,,7
L1866:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-97, %eax
	ja	L1866
	shrl	$2, %eax
	movl	$838860819, %edx
	mull	%edx
	movl	%edx, %esi
	shrl	$20, %esi
	.p2align 4,,7
L1868:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-97, %eax
	ja	L1868
	shrl	$2, %eax
	movl	$838860819, %edx
	mull	%edx
	movl	%edx, %edi
	shrl	$20, %edi
	.p2align 4,,7
L1870:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-97, %eax
	ja	L1870
	shrl	$2, %eax
	movl	$838860819, %edx
	mull	%edx
	movl	%edx, %ebp
	shrl	$20, %ebp
	.p2align 4,,7
L1872:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-97, %eax
	ja	L1872
	shrl	$2, %eax
	movl	$838860819, %edx
	mull	%edx
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	movl	%edx, %ebx
	shrl	$20, %ebx
	movl	%ebx, 12(%esp)
	call	__Z25runTestOpt08_Type3_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z24runTestOpt08_Type3_Afteriiii
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
LFE3244:
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type4v
	.def	__Z18runTestOpt08_Type4v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type4v:
LFB3247:
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
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$100000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC56, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L1876:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1876
	movl	$624, 2512(%esp)
	.p2align 4,,7
L1878:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-1022, %eax
	ja	L1878
	movl	$-2145385985, %esi
	mull	%esi
	movl	%edx, %esi
	shrl	$21, %esi
	.p2align 4,,7
L1880:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-1022, %eax
	ja	L1880
	movl	$-2145385985, %edi
	mull	%edi
	movl	%edx, %edi
	shrl	$21, %edi
	.p2align 4,,7
L1882:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-1022, %eax
	ja	L1882
	movl	$-2145385985, %ebp
	mull	%ebp
	movl	%edx, %ebp
	shrl	$21, %ebp
	.p2align 4,,7
L1884:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-1022, %eax
	ja	L1884
	movl	$-2145385985, %ebx
	mull	%ebx
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	movl	%edx, %ebx
	shrl	$21, %ebx
	movl	%ebx, 12(%esp)
	call	__Z25runTestOpt08_Type4_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type4_After1iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type4_After2iiii
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
LFE3247:
	.section .rdata,"dr"
LC143:
	.ascii "Type9: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type9v
	.def	__Z18runTestOpt08_Type9v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type9v:
LFB3275:
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
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$10000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC143, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L1888:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1888
	movl	$624, 2512(%esp)
	.p2align 4,,7
L1890:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L1890
	movl	$-922746801, %edx
	mull	%edx
	shrl	$24, %edx
	leal	-100(%edx), %esi
	.p2align 4,,7
L1892:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L1892
	movl	$-922746801, %edx
	mull	%edx
	shrl	$24, %edx
	leal	-100(%edx), %edi
	.p2align 4,,7
L1894:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L1894
	movl	$-922746801, %edx
	mull	%edx
	shrl	$24, %edx
	leal	-100(%edx), %ebp
	.p2align 4,,7
L1896:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L1896
	movl	$-922746801, %edx
	mull	%edx
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	shrl	$24, %edx
	leal	-100(%edx), %ebx
	movl	%ebx, 12(%esp)
	call	__Z25runTestOpt08_Type9_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z24runTestOpt08_Type9_Afteriiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z27runTestOpt08_Type9_Appendixiiii
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
LFE3275:
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type2v
	.def	__Z18runTestOpt08_Type2v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type2v:
LFB3239:
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
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$100000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC55, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L1900:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1900
	movl	$624, 2512(%esp)
	.p2align 4,,7
L1902:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L1902
	movl	$-1778384781, %esi
	mull	%esi
	movl	%edx, %esi
	shrl	$23, %esi
	.p2align 4,,7
L1904:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L1904
	movl	$-1778384781, %edi
	mull	%edi
	movl	%edx, %edi
	shrl	$23, %edi
	.p2align 4,,7
L1906:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L1906
	movl	$-1778384781, %ebp
	mull	%ebp
	movl	%edx, %ebp
	shrl	$23, %ebp
	.p2align 4,,7
L1908:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L1908
	movl	$-1778384781, %ebx
	mull	%ebx
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	movl	%edx, %ebx
	shrl	$23, %ebx
	movl	%ebx, 12(%esp)
	call	__Z25runTestOpt08_Type2_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type2_After1iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type2_After2iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type2_After3iiii
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
LFE3239:
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type1v
	.def	__Z18runTestOpt08_Type1v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type1v:
LFB3234:
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
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$100000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC10, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L1912:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1912
	movl	$624, 2512(%esp)
	.p2align 4,,7
L1914:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L1914
	movl	$-1778384781, %esi
	mull	%esi
	movl	%edx, %esi
	shrl	$23, %esi
	.p2align 4,,7
L1916:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L1916
	movl	$-1778384781, %edi
	mull	%edi
	movl	%edx, %edi
	shrl	$23, %edi
	.p2align 4,,7
L1918:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L1918
	movl	$-1778384781, %ebp
	mull	%ebp
	movl	%edx, %ebp
	shrl	$23, %ebp
	.p2align 4,,7
L1920:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L1920
	movl	$-1778384781, %ebx
	mull	%ebx
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	movl	%edx, %ebx
	shrl	$23, %ebx
	movl	%ebx, 12(%esp)
	call	__Z25runTestOpt08_Type1_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type1_After1iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type1_After2iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type1_After3iiii
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
LFE3234:
	.section .rdata,"dr"
LC144:
	.ascii "Type5: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type5v
	.def	__Z18runTestOpt08_Type5v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type5v:
LFB3251:
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
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$10000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC144, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L1924:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1924
	movl	$624, 2512(%esp)
	.p2align 4,,7
L1926:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L1926
	leal	-1(%eax), %esi
	.p2align 4,,7
L1928:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L1928
	leal	-1(%eax), %edi
	.p2align 4,,7
L1932:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L1932
	leal	-1(%eax), %ebp
	.p2align 4,,7
L1933:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L1933
	leal	-1(%eax), %ebx
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type5_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type5_After1iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type5_After2iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type5_After3iiii
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
LFE3251:
	.section .rdata,"dr"
LC145:
	.ascii "Type8: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type8v
	.def	__Z18runTestOpt08_Type8v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type8v:
LFB3270:
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
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$10000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC145, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L1939:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1939
	movl	$624, 2512(%esp)
	.p2align 4,,7
L1941:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L1941
	movl	$-922746801, %edx
	mull	%edx
	shrl	$24, %edx
	leal	-100(%edx), %esi
	.p2align 4,,7
L1943:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L1943
	movl	$-922746801, %edx
	mull	%edx
	shrl	$24, %edx
	leal	-100(%edx), %edi
	.p2align 4,,7
L1945:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L1945
	movl	$-922746801, %edx
	mull	%edx
	shrl	$24, %edx
	leal	-100(%edx), %ebp
	.p2align 4,,7
L1947:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L1947
	movl	$-922746801, %edx
	mull	%edx
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	shrl	$24, %edx
	leal	-100(%edx), %ebx
	movl	%ebx, 12(%esp)
	call	__Z25runTestOpt08_Type8_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z24runTestOpt08_Type8_Afteriiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z28runTestOpt08_Type8_Appendix1iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z28runTestOpt08_Type8_Appendix2iiii
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
LFE3270:
	.section .rdata,"dr"
LC146:
	.ascii "Type7: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type7v
	.def	__Z18runTestOpt08_Type7v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type7v:
LFB3263:
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
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$10000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC146, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L1951:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L1951
	movl	$624, 2512(%esp)
	.p2align 4,,7
L1953:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L1953
	leal	-1(%eax), %esi
	.p2align 4,,7
L1955:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L1955
	leal	-1(%eax), %edi
	.p2align 4,,7
L1959:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L1959
	leal	-1(%eax), %ebp
	.p2align 4,,7
L1960:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L1960
	leal	-1(%eax), %ebx
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type7_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type7_After1iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type7_After2iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type7_After3iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type7_After4iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type7_After5iiii
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
LFE3263:
	.globl	__ZTIFffE
	.section	.rdata$_ZTIFffE,"dr"
	.linkonce same_size
	.align 4
__ZTIFffE:
	.long	__ZTVN10__cxxabiv120__function_type_infoE+8
	.long	__ZTSFffE
	.globl	__ZTSFffE
	.section	.rdata$_ZTSFffE,"dr"
	.linkonce same_size
__ZTSFffE:
	.ascii "FffE\0"
	.globl	__ZTIFfffE
	.section	.rdata$_ZTIFfffE,"dr"
	.linkonce same_size
	.align 4
__ZTIFfffE:
	.long	__ZTVN10__cxxabiv120__function_type_infoE+8
	.long	__ZTSFfffE
	.globl	__ZTSFfffE
	.section	.rdata$_ZTSFfffE,"dr"
	.linkonce same_size
__ZTSFfffE:
	.ascii "FfffE\0"
	.globl	__ZTIPFffE
	.section	.rdata$_ZTIPFffE,"dr"
	.linkonce same_size
	.align 4
__ZTIPFffE:
	.long	__ZTVN10__cxxabiv119__pointer_type_infoE+8
	.long	__ZTSPFffE
	.long	0
	.long	__ZTIFffE
	.globl	__ZTSPFffE
	.section	.rdata$_ZTSPFffE,"dr"
	.linkonce same_size
__ZTSPFffE:
	.ascii "PFffE\0"
	.globl	__ZTIPFfffE
	.section	.rdata$_ZTIPFfffE,"dr"
	.linkonce same_size
	.align 4
__ZTIPFfffE:
	.long	__ZTVN10__cxxabiv119__pointer_type_infoE+8
	.long	__ZTSPFfffE
	.long	0
	.long	__ZTIFfffE
	.globl	__ZTSPFfffE
	.section	.rdata$_ZTSPFfffE,"dr"
	.linkonce same_size
__ZTSPFfffE:
	.ascii "PFfffE\0"
	.section .rdata,"dr"
	.align 4
LC0:
	.long	1067030938
	.align 4
LC2:
	.long	1062557013
	.align 16
LC3:
	.long	1077936128
	.long	1077936128
	.long	1077936128
	.long	1077936128
	.align 16
LC4:
	.long	1056964608
	.long	1056964608
	.long	1056964608
	.long	1056964608
	.align 16
LC5:
	.long	1073741824
	.long	1073741824
	.long	1073741824
	.long	1073741824
	.align 4
LC6:
	.long	1315859240
	.align 16
LC20:
	.long	0
	.long	1
	.long	2
	.long	3
	.align 16
LC22:
	.long	4
	.long	4
	.long	4
	.long	4
	.align 4
LC32:
	.long	1203982336
	.align 4
LC34:
	.long	981668463
	.align 4
LC35:
	.long	1176256512
	.align 4
LC36:
	.long	1148846080
	.align 4
LC38:
	.long	1036831949
	.align 4
LC39:
	.long	1073741824
	.align 4
LC42:
	.long	1120403456
	.align 4
LC45:
	.long	1008981770
	.align 4
LC46:
	.long	1092616192
	.align 16
LC118:
	.long	1801439851
	.long	1801439851
	.long	1801439851
	.long	1801439851
	.align 16
LC119:
	.byte	4
	.byte	5
	.byte	6
	.byte	7
	.byte	-128
	.byte	-128
	.byte	-128
	.byte	-128
	.byte	12
	.byte	13
	.byte	14
	.byte	15
	.byte	-128
	.byte	-128
	.byte	-128
	.byte	-128
	.align 16
LC120:
	.byte	-128
	.byte	-128
	.byte	-128
	.byte	-128
	.byte	4
	.byte	5
	.byte	6
	.byte	7
	.byte	-128
	.byte	-128
	.byte	-128
	.byte	-128
	.byte	12
	.byte	13
	.byte	14
	.byte	15
	.align 16
LC123:
	.long	1
	.long	1
	.long	1
	.long	1
	.align 16
LC137:
	.long	2147483647
	.long	2147483647
	.long	2147483647
	.long	2147483647
	.align 16
LC138:
	.long	-2147483648
	.long	-2147483648
	.long	-2147483648
	.long	-2147483648
	.align 16
LC139:
	.long	-1727483681
	.long	-1727483681
	.long	-1727483681
	.long	-1727483681
	.align 4
LC141:
	.long	796917760
	.ident	"GCC: (GNU) 4.8.2"
	.def	__ZNSt6chrono3_V212system_clock3nowEv;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	__Z9initOpt01R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt01_Type1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt01_Type1_BeforeR11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt01_Type1_After1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt01_Type1_After2R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt01_Type1_After3R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt01_Type1_After4R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z24testOpt01_Type1_AppendixR11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt01_Type1_BeforeR11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt01_Type1_After1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt01_Type1_After2R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt01_Type1_After3R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt01_Type1_After4R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z27runTestOpt01_Type1_AppendixR11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z9initOpt02R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt02_Type1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt02_Type1_BeforeR11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt02_Type1_After1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt02_Type1_After2R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt02_Type1_After3R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt02_Type1_BeforeR11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt02_Type1_After1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt02_Type1_After2R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt02_Type1_After3R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt03_Type1v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt03_Type2v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt03_Type3v;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt03_Type1_Beforeiii;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt03_Type2_Beforeiiiiiiii;	.scl	2;	.type	32;	.endef
	.def	__Z15initOpt03_Type3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt03_Type3_BeforeR11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt03_Type3_After1R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt03_Type3_After2R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt03_Type3_After3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z26testOpt03_Type3_AppendixA1R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z26testOpt03_Type3_AppendixA2R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z26testOpt03_Type3_AppendixA3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z26testOpt03_Type3_AppendixB1R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z26testOpt03_Type3_AppendixB2R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z26testOpt03_Type3_AppendixB3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt03_Type3_BeforeR11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt03_Type3_After1R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt03_Type3_After2R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt03_Type3_After3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z29runTestOpt03_Type3_AppendixA1R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z29runTestOpt03_Type3_AppendixA2R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z29runTestOpt03_Type3_AppendixA3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z29runTestOpt03_Type3_AppendixB1R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z29runTestOpt03_Type3_AppendixB2R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z29runTestOpt03_Type3_AppendixB3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt04_1timev;	.scl	2;	.type	32;	.endef
	.def	__Z9initOpt04R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt04_Type1v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt04_Type2R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt04_Type3f;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt04_Type4v;	.scl	2;	.type	32;	.endef
	.def	__ZSt25__throw_bad_function_callv;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type1_Beforev;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt04_Type1_Afterv;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt04_Type2_BeforeR11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt04_Type2_After1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt04_Type2_After2R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type2_BeforeR11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type2_After1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type2_After2R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type3_Beforef;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type3_After1f;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type3_After2f;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type3_After3f;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type4_Beforev;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type4_After1v;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type4_After2v;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type4_After3v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt05_Type1v;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt05_Type1_Beforev;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt05_Type1_Afterv;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt05_Type1_BeforeRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_;	.scl	2;	.type	32;	.endef
	.def	__Z21testOpt05_Type1_AfterRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt06_Type1_BeforeR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt06_Type1_AfterR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt06_Type1_BeforeR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
	.def	__Z21testOpt06_Type1_AfterR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt07_Type1v;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt07_Type2_strlenv;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt07_Type2_strcmpv;	.scl	2;	.type	32;	.endef
	.def	__Z26runTestOpt07_Type2_strncmpv;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt07_Type2_strchrv;	.scl	2;	.type	32;	.endef
	.def	__Z26runTestOpt07_Type2_strrchrv;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt07_Type2_strstrv;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt07_Type2_strcpyv;	.scl	2;	.type	32;	.endef
	.def	__Z26runTestOpt07_Type2_strncpyv;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt07_Type1_Beforev;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt07_Type1_Afterv;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
	.def	__Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
	.def	__Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strlen_BeforePKcS0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
	.def	__Z31runTestOpt07_Type2_strlen_AfterPKcS0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strlen_BeforeiPKc;	.scl	2;	.type	32;	.endef
	.def	__Z28testOpt07_Type2_strlen_AfteriPKc;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strcmp_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
	.def	__Z31runTestOpt07_Type2_strcmp_AfterPKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z33runTestOpt07_Type2_strncmp_BeforePKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strncmp_AfterPKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj;	.scl	2;	.type	32;	.endef
	.def	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strchr_BeforePKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
	.def	__Z31runTestOpt07_Type2_strchr_AfterPKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strchr_BeforeiPKcc;	.scl	2;	.type	32;	.endef
	.def	__Z28testOpt07_Type2_strchr_AfteriPKcc;	.scl	2;	.type	32;	.endef
	.def	__Z33runTestOpt07_Type2_strrchr_BeforePKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strrchr_AfterPKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
	.def	__Z30testOpt07_Type2_strrchr_BeforeiPKcc;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strrchr_AfteriPKcc;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strstr_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strstr_After1PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strstr_After2PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strstr_After1iPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strstr_After2iPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strcpy_BeforePcPKcS1_S1_S1_S1_;	.scl	2;	.type	32;	.endef
	.def	__Z31runTestOpt07_Type2_strcpy_AfterPcPKcS1_S1_S1_S1_;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc;	.scl	2;	.type	32;	.endef
	.def	__Z28testOpt07_Type2_strcpy_AfteriPcPKc;	.scl	2;	.type	32;	.endef
	.def	__Z33runTestOpt07_Type2_strncpy_BeforePcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strncpy_AfterPcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj;	.scl	2;	.type	32;	.endef
	.def	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type1v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type2v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type3v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type4v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type5v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type6v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type7v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type8v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type9v;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type1_Beforei;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type1_After1i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type1_After2i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type1_After3i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type2_Beforei;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type2_After1i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type2_After2i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type2_After3i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type3_Beforeii;	.scl	2;	.type	32;	.endef
	.def	__Z21testOpt08_Type3_Afterii;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type4_Beforei;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type4_After1i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type4_After2i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type5_Beforei;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type5_After1i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type5_After2i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type5_After3i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type6_Beforei;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type6_After1i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type6_After2i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type6_After3i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type6_After4i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type6_After5i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type7_Beforei;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type7_After1i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type7_After2i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type7_After3i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type7_After4i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type7_After5i;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt09_Type1v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt09_Type2v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt09_Type3v;	.scl	2;	.type	32;	.endef
	.def	__Z12initOpt09_t1R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type1_BeforeR12dataOpt09_t1;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type1_After1R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type1_After2R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type1_After3R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type1_After4R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type1_After5R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
	.def	__Z27runTestOpt09_Type1_AppendixR12dataOpt09_t1;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type1_BeforeR12dataOpt09_t1;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type1_After1R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type1_After2R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type1_After3R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type1_After4R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type1_After5R12dataOpt09_t1;	.scl	2;	.type	32;	.endef
	.def	__Z24testOpt09_Type1_AppendixR12dataOpt09_t1;	.scl	2;	.type	32;	.endef
	.def	__Z12initOpt09_t2R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type2_BeforeR12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type2_After1R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type2_After2R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type2_After3R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type2_After4R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type2_After5R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type2_After6R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z27runTestOpt09_Type2_AppendixR12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type2_BeforeR12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type2_After1R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type2_After2R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type2_After3R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type2_After4R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type2_After5R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type2_After6R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z24testOpt09_Type2_AppendixR12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type3_BeforeR12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type3_After1R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type3_After2R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type3_After3R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type3_After4R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type3_After5R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type3_After6R12dataOpt09_t2;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type3_BeforePN12dataOpt09_t26elem_tEj;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type3_After1PN12dataOpt09_t26elem_tEj;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type3_After2PN12dataOpt09_t26elem_tEj;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type3_After3PN12dataOpt09_t26elem_tEj;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type3_After4PN12dataOpt09_t26elem_tEj;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type3_After5PN12dataOpt09_t26elem_tEj;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type3_After6PN12dataOpt09_t26elem_tEj;	.scl	2;	.type	32;	.endef
	.def	__Z9setLambdaRi;	.scl	2;	.type	32;	.endef
	.def	__Z12callLambda13v;	.scl	2;	.type	32;	.endef
	.def	__Z9initOpt06R11dataOpt06_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt06_Type1R11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt03_Type1_Beforeii;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt03_Type1_Afterii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt03_Type2_Beforeiiiiiii;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt03_Type2_Afteriiiiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type6_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type6_After1iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type6_After2iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type6_After3iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type6_After4iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type6_After5iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type3_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt08_Type3_Afteriiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type4_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type4_After1iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type4_After2iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type9_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt08_Type9_Afteriiii;	.scl	2;	.type	32;	.endef
	.def	__Z27runTestOpt08_Type9_Appendixiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type2_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type2_After1iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type2_After2iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type2_After3iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type1_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type1_After1iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type1_After2iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type1_After3iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type5_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type5_After1iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type5_After2iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type5_After3iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type8_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt08_Type8_Afteriiii;	.scl	2;	.type	32;	.endef
	.def	__Z28runTestOpt08_Type8_Appendix1iiii;	.scl	2;	.type	32;	.endef
	.def	__Z28runTestOpt08_Type8_Appendix2iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type7_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type7_After1iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type7_After2iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type7_After3iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type7_After4iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type7_After5iiii;	.scl	2;	.type	32;	.endef

	.file	"sub2.cpp"
	.text
	.p2align 4,,15
	.globl	__Z33commonProc_testOpt03_Type3_BeforePijiPFvRiE
	.def	__Z33commonProc_testOpt03_Type3_BeforePijiPFvRiE;	.scl	2;	.type	32;	.endef
__Z33commonProc_testOpt03_Type3_BeforePijiPFvRiE:
LFB1082:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	xorl	%eax, %eax
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
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	movl	52(%esp), %edi
	movl	48(%esp), %esi
	movl	56(%esp), %ebp
	testl	%edi, %edi
	jne	L6
	jmp	L1
	.p2align 4,,7
L3:
	addl	$1, %ebx
	cmpl	%edi, %ebx
	movl	%ebx, %eax
	je	L1
L6:
	leal	(%esi,%eax,4), %eax
	cmpl	%ebp, (%eax)
	jne	L3
	addl	$1, %ebx
	movl	%eax, (%esp)
	call	*60(%esp)
	cmpl	%edi, %ebx
	movl	%ebx, %eax
	jne	L6
	.p2align 4,,7
L1:
	addl	$28, %esp
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
LFE1082:
	.p2align 4,,15
	.globl	__Z36commonProc_testOpt03_Type3_AppendixBPijiSt8functionIFvRiEE
	.def	__Z36commonProc_testOpt03_Type3_AppendixBPijiSt8functionIFvRiEE;	.scl	2;	.type	32;	.endef
__Z36commonProc_testOpt03_Type3_AppendixBPijiSt8functionIFvRiEE:
LFB1083:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	xorl	%eax, %eax
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
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	movl	52(%esp), %esi
	movl	48(%esp), %ebp
	movl	56(%esp), %edi
	movl	60(%esp), %edx
	testl	%esi, %esi
	jne	L15
	jmp	L9
	.p2align 4,,7
L11:
	addl	$1, %ebx
	cmpl	%esi, %ebx
	movl	%ebx, %eax
	je	L9
L15:
	leal	0(%ebp,%eax,4), %eax
	cmpl	%edi, (%eax)
	jne	L11
	movl	8(%edx), %ecx
	testl	%ecx, %ecx
	je	L17
	addl	$1, %ebx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	movl	%edx, 12(%esp)
	call	*12(%edx)
	cmpl	%esi, %ebx
	movl	12(%esp), %edx
	movl	%ebx, %eax
	jne	L15
	.p2align 4,,7
L9:
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
L17:
	.cfi_restore_state
	call	__ZSt25__throw_bad_function_callv
	.cfi_endproc
LFE1083:
	.ident	"GCC: (GNU) 4.8.2"
	.def	__ZSt25__throw_bad_function_callv;	.scl	2;	.type	32;	.endef

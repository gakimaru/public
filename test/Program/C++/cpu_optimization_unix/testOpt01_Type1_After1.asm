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

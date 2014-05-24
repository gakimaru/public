LFE2680:
	.p2align 4,,15
	.globl	__Z22testOpt02_Type1_After2R11dataOpt02_t
	.def	__Z22testOpt02_Type1_After2R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z22testOpt02_Type1_After2R11dataOpt02_t:
LFB2681:
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
	je	L420
	cmpl	$5, %ebx
	setbe	%bl
	cmpl	%edx, %ecx
	seta	%cl
	orl	%ecx, %ebx
	cmpb	$1, %bl
	sbbl	%ecx, %ecx
	cmpb	$-1, %cl
	jne	L420
	movl	%esp, %ecx
	xorl	%ebx, %ebx
	movdqa	LC5, %xmm3
	movdqa	LC4, %xmm0
	pxor	%xmm1, %xmm1
L415:
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
	jbe	L426
	movdqa	%xmm4, %xmm0
	jmp	L415
	.p2align 4,,7
L420:
	movl	%esp, %ecx
	xorl	%ebp, %ebp
L410:
	leal	8(%ecx), %ebx
	cmpl	%ebx, %edx
	leal	1(%ebp), %eax
	movl	%ebp, (%ecx)
	movl	$0, 4(%ecx)
	jbe	L413
	movl	%eax, 8(%ecx)
	leal	16(%ecx), %eax
	cmpl	%eax, %edx
	leal	2(%ebp), %ebx
	movl	$0, 12(%ecx)
	jbe	L413
	movl	%ebx, 16(%ecx)
	leal	24(%ecx), %ebx
	cmpl	%ebx, %edx
	leal	3(%ebp), %eax
	movl	$0, 20(%ecx)
	jbe	L413
	movl	%eax, 24(%ecx)
	leal	32(%ecx), %eax
	addl	$4, %ebp
	cmpl	%eax, %edx
	movl	$0, 28(%ecx)
	jbe	L413
	movl	%ebp, 32(%ecx)
	movl	$0, 36(%ecx)
L413:
	movl	128(%esp), %eax
	leal	40000(%eax), %ebx
	.p2align 4,,7
L417:
	movl	(%eax), %ecx
	addl	$4, %eax
	addl	$1, 4(%esp,%ecx,8)
	cmpl	%eax, %ebx
	ja	L417
	movl	4(%esp), %eax
	movl	%esp, %ebx
	.p2align 4,,7
L419:
	movl	4(%esi), %ecx
	cmpl	%eax, %ecx
	cmovg	%esi, %ebx
	cmpl	%ecx, %eax
	cmovl	%ecx, %eax
	addl	$8, %esi
	cmpl	%edx, %esi
	jb	L419
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
L426:
	.cfi_restore_state
	cmpl	%eax, %ebp
	leal	(%esp,%ebp,8), %ecx
	jne	L410
	jmp	L413
	.cfi_endproc

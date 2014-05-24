LFE2675:
	.p2align 4,,15
	.globl	__Z22testOpt01_Type1_After4R11dataOpt01_t
	.def	__Z22testOpt01_Type1_After4R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z22testOpt01_Type1_After4R11dataOpt01_t:
LFB2676:
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
	ja	L370
L361:
	movl	%edi, %ebx
L350:
	cmpl	$1, %ebx
	movl	4(%eax), %edx
	jbe	L363
	addl	8(%eax), %edx
	cmpl	$2, %ebx
	leal	12(%eax), %ecx
	jbe	L352
	addl	12(%eax), %edx
	cmpl	$3, %ebx
	leal	16(%eax), %ecx
	jbe	L352
	addl	16(%eax), %edx
	cmpl	$4, %ebx
	leal	20(%eax), %ecx
	jbe	L352
	addl	20(%eax), %edx
	cmpl	$5, %ebx
	leal	24(%eax), %ecx
	jbe	L352
	addl	24(%eax), %edx
	cmpl	$6, %ebx
	leal	28(%eax), %ecx
	jbe	L352
	addl	28(%eax), %edx
	cmpl	$7, %ebx
	leal	32(%eax), %ecx
	jbe	L352
	addl	32(%eax), %edx
	leal	36(%eax), %ecx
L352:
	cmpl	%ebx, %edi
	je	L353
L351:
	subl	%ebx, %edi
	movl	%edi, %esi
	shrl	$2, %esi
	leal	0(,%esi,4), %ebp
	testl	%ebp, %ebp
	movl	%esi, 4(%esp)
	je	L354
	leal	4(%eax,%ebx,4), %esi
	xorl	%ebx, %ebx
	pxor	%xmm0, %xmm0
L360:
	paddd	(%esi), %xmm0
	addl	$1, %ebx
	addl	$16, %esi
	cmpl	%ebx, 4(%esp)
	ja	L360
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
	je	L353
L354:
	movl	(%esp), %esi
	leal	4(%ecx), %ebx
	addl	(%ecx), %edx
	cmpl	%ebx, %esi
	jbe	L353
	leal	8(%ecx), %ebx
	addl	4(%ecx), %edx
	cmpl	%ebx, %esi
	jbe	L353
	addl	8(%ecx), %edx
L353:
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
L370:
	.cfi_restore_state
	cmpl	(%esp), %esi
	ja	L361
	testl	%ebx, %ebx
	jne	L350
	xorl	%ebx, %ebx
	xorl	%edx, %edx
	.p2align 4,,2
	jmp	L351
	.p2align 4,,7
L363:
	movl	%ebp, %ecx
	jmp	L352
	.cfi_endproc

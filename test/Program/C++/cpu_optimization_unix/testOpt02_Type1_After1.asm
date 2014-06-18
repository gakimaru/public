LFE2679:
	.p2align 4,,15
	.globl	__Z22testOpt02_Type1_After1R11dataOpt02_t
	.def	__Z22testOpt02_Type1_After1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z22testOpt02_Type1_After1R11dataOpt02_t:
LFB2680:
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
L394:
	movl	(%eax), %edx
	addl	$4, %eax
	addl	$1, 4(%esp,%edx,8)
	cmpl	%eax, %ecx
	ja	L394
	movl	4(%esp), %eax
	movl	%esp, %edx
	cmpl	%eax, 12(%esp)
	jle	L395
	movl	12(%esp), %eax
	leal	8(%esp), %edx
L395:
	cmpl	20(%esp), %eax
	jge	L396
	movl	20(%esp), %eax
	leal	16(%esp), %edx
L396:
	cmpl	28(%esp), %eax
	jge	L397
	movl	28(%esp), %eax
	leal	24(%esp), %edx
L397:
	cmpl	36(%esp), %eax
	jge	L398
	movl	36(%esp), %eax
	leal	32(%esp), %edx
L398:
	cmpl	44(%esp), %eax
	jge	L399
	movl	44(%esp), %eax
	leal	40(%esp), %edx
L399:
	cmpl	52(%esp), %eax
	jge	L400
	movl	52(%esp), %eax
	leal	48(%esp), %edx
L400:
	cmpl	60(%esp), %eax
	jge	L401
	movl	60(%esp), %eax
	leal	56(%esp), %edx
L401:
	cmpl	68(%esp), %eax
	jge	L402
	movl	68(%esp), %eax
	leal	64(%esp), %edx
L402:
	cmpl	76(%esp), %eax
	jge	L403
	movl	76(%esp), %eax
	leal	72(%esp), %edx
L403:
	cmpl	%eax, 84(%esp)
	jle	L405
	movl	84(%esp), %eax
	leal	80(%esp), %edx
L405:
	sall	$16, %eax
	orl	(%edx), %eax
	addl	$108, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc

LFE2681:
	.p2align 4,,15
	.globl	__Z22testOpt02_Type1_After3R11dataOpt02_t
	.def	__Z22testOpt02_Type1_After3R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z22testOpt02_Type1_After3R11dataOpt02_t:
LFB2682:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	xorl	%eax, %eax
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$100, %esp
	.cfi_def_cfa_offset 112
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
L429:
	movl	(%ecx,%eax,4), %edx
	addl	$1, %eax
	addl	$1, 4(%esp,%edx,8)
	cmpl	$10000, %eax
	jne	L429
	movl	12(%esp), %eax
	leal	8(%esp), %edx
	movl	%esp, %ecx
	movl	4(%esp), %ebx
	movl	84(%esp), %esi
	cmpl	%ebx, %eax
	cmovg	%edx, %ecx
	cmpl	%eax, %ebx
	cmovl	%eax, %ebx
	movl	20(%esp), %eax
	leal	16(%esp), %edx
	cmpl	%eax, %ebx
	cmovl	%eax, %ebx
	movl	28(%esp), %eax
	cmovge	%ecx, %edx
	leal	24(%esp), %ecx
	cmpl	%eax, %ebx
	cmovl	%eax, %ebx
	movl	36(%esp), %eax
	cmovge	%edx, %ecx
	leal	32(%esp), %edx
	cmpl	%eax, %ebx
	cmovl	%eax, %ebx
	movl	44(%esp), %eax
	cmovge	%ecx, %edx
	leal	40(%esp), %ecx
	cmpl	%eax, %ebx
	cmovl	%eax, %ebx
	movl	52(%esp), %eax
	cmovge	%edx, %ecx
	leal	48(%esp), %edx
	cmpl	%eax, %ebx
	cmovl	%eax, %ebx
	movl	60(%esp), %eax
	cmovge	%ecx, %edx
	leal	56(%esp), %ecx
	cmpl	%eax, %ebx
	cmovl	%eax, %ebx
	movl	68(%esp), %eax
	cmovge	%edx, %ecx
	leal	64(%esp), %edx
	cmpl	%eax, %ebx
	cmovl	%eax, %ebx
	movl	76(%esp), %eax
	cmovge	%ecx, %edx
	leal	72(%esp), %ecx
	cmpl	%eax, %ebx
	cmovl	%eax, %ebx
	cmovge	%edx, %ecx
	movl	%esi, %eax
	cmpl	%esi, %ebx
	cmovge	%ebx, %eax
	sall	$16, %eax
	cmpl	%ebx, %esi
	leal	80(%esp), %edx
	cmovle	%ecx, %edx
	orl	(%edx), %eax
	addl	$100, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2682:
	.p2align 4,,15
	.globl	__Z22testOpt03_Type1_Beforeiii
	.def	__Z22testOpt03_Type1_Beforeiii;	.scl	2;	.type	32;	.endef
__Z22testOpt03_Type1_Beforeiii:
LFB2683:
	.cfi_startproc
	movl	8(%esp), %eax
	imull	4(%esp), %eax
	addl	12(%esp), %eax
	ret
	.cfi_endproc

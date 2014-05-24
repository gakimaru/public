LFE2676:
	.p2align 4,,15
	.globl	__Z24testOpt01_Type1_AppendixR11dataOpt01_t
	.def	__Z24testOpt01_Type1_AppendixR11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z24testOpt01_Type1_AppendixR11dataOpt01_t:
LFB2677:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %ecx
	xorl	%edx, %edx
	leal	40004(%ecx), %ebx
	leal	4(%ecx), %eax
	cmpl	%ebx, %eax
	movl	$0, (%ecx)
	je	L371
	.p2align 4,,7
L375:
	addl	(%eax), %edx
	addl	$4, %eax
	cmpl	%eax, %ebx
	movl	%edx, (%ecx)
	jne	L375
L371:
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc

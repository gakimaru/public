	.file	"sub.cpp"
	.text
	.p2align 4,,15
	.globl	__Z3subR4vec3S0_S0_S0_S0_S0_RfS1_S1_S0_S0_S0_S0_ffffi
	.def	__Z3subR4vec3S0_S0_S0_S0_S0_RfS1_S1_S0_S0_S0_S0_ffffi;	.scl	2;	.type	32;	.endef
__Z3subR4vec3S0_S0_S0_S0_S0_RfS1_S1_S0_S0_S0_S0_ffffi:
LFB711:
	.cfi_startproc
	movaps	LC0, %xmm0
	movaps	%xmm0, %xmm1
	movl	4(%esp), %edx
	movaps	%xmm0, %xmm3
	movl	40(%esp), %eax
	dpps	$119, %xmm0, %xmm1
	movaps	%xmm0, (%edx)
	movl	8(%esp), %edx
	sqrtps	%xmm1, %xmm1
	divps	%xmm1, %xmm3
	movaps	LC1, %xmm1
	movaps	%xmm1, %xmm2
	movaps	%xmm1, %xmm4
	dpps	$119, %xmm1, %xmm2
	sqrtps	%xmm2, %xmm2
	divps	%xmm2, %xmm4
	movaps	%xmm1, %xmm2
	subps	%xmm0, %xmm2
	movaps	%xmm3, (%edx)
	movl	12(%esp), %edx
	movaps	%xmm2, %xmm5
	movaps	%xmm1, (%edx)
	movl	16(%esp), %edx
	dpps	$119, %xmm2, %xmm5
	sqrtps	%xmm5, %xmm5
	movaps	%xmm4, (%edx)
	movl	20(%esp), %edx
	dpps	$113, %xmm4, %xmm3
	movaps	%xmm2, (%edx)
	movl	24(%esp), %edx
	divps	%xmm5, %xmm2
	movaps	%xmm2, (%edx)
	movl	28(%esp), %edx
	movaps	%xmm0, %xmm2
	dpps	$113, %xmm1, %xmm2
	movss	%xmm5, (%edx)
	movl	32(%esp), %edx
	movss	%xmm2, (%edx)
	movl	36(%esp), %edx
	movaps	%xmm0, %xmm2
	shufps	$210, %xmm0, %xmm2
	shufps	$201, %xmm0, %xmm0
	movss	%xmm3, (%edx)
	movl	44(%esp), %edx
	movaps	%xmm1, %xmm3
	shufps	$201, %xmm1, %xmm3
	shufps	$210, %xmm1, %xmm1
	mulps	%xmm3, %xmm2
	mulps	%xmm1, %xmm0
	subps	%xmm2, %xmm0
	movss	56(%esp), %xmm2
	movaps	%xmm0, %xmm1
	movaps	%xmm0, (%eax)
	shufps	$0, %xmm2, %xmm2
	dpps	$119, %xmm0, %xmm1
	sqrtps	%xmm1, %xmm1
	divps	%xmm1, %xmm0
	movaps	%xmm0, (%edx)
	movaps	(%eax), %xmm1
	movaps	%xmm1, %xmm0
	movl	48(%esp), %eax
	movaps	%xmm1, %xmm6
	dpps	$119, %xmm1, %xmm0
	sqrtps	%xmm0, %xmm0
	divps	%xmm0, %xmm6
	movaps	%xmm6, %xmm0
	mulps	%xmm2, %xmm0
	movss	68(%esp), %xmm2
	shufps	$0, %xmm2, %xmm2
	addps	%xmm1, %xmm0
	movss	60(%esp), %xmm1
	shufps	$0, %xmm1, %xmm1
	mulps	%xmm1, %xmm0
	movss	64(%esp), %xmm1
	shufps	$0, %xmm1, %xmm1
	divps	%xmm1, %xmm0
	movaps	%xmm0, %xmm1
	movaps	%xmm0, %xmm7
	dpps	$119, %xmm0, %xmm1
	sqrtps	%xmm1, %xmm1
	divps	%xmm1, %xmm7
	movaps	%xmm7, %xmm1
	mulps	%xmm2, %xmm1
	subps	%xmm1, %xmm0
	movaps	%xmm0, %xmm1
	movaps	%xmm0, (%eax)
	movl	52(%esp), %eax
	dpps	$119, %xmm0, %xmm1
	sqrtps	%xmm1, %xmm1
	divps	%xmm1, %xmm0
	movaps	%xmm0, (%eax)
	ret
	.cfi_endproc
LFE711:
	.section .rdata,"dr"
	.align 16
LC0:
	.long	1065353216
	.long	1073741824
	.long	1077936128
	.long	0
	.align 16
LC1:
	.long	-1065353216
	.long	-1063256064
	.long	-1061158912
	.long	0
	.ident	"GCC: (GNU) 4.8.2"

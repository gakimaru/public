	.file	"sub.cpp"
	.text
	.p2align 4,,15
	.globl	__Z3subR4vec3S0_S0_S0_S0_S0_RfS1_S1_S0_S0_S0_S0_ffffi
	.def	__Z3subR4vec3S0_S0_S0_S0_S0_RfS1_S1_S0_S0_S0_S0_ffffi;	.scl	2;	.type	32;	.endef
__Z3subR4vec3S0_S0_S0_S0_S0_RfS1_S1_S0_S0_S0_S0_ffffi:
LFB709:
	.cfi_startproc
	movaps	LC0, %xmm0
	movaps	%xmm0, %xmm1
	movl	4(%esp), %edx
	movaps	%xmm0, %xmm4
	movl	40(%esp), %eax
	dpps	$113, %xmm0, %xmm1
	movaps	%xmm0, (%edx)
	movl	8(%esp), %edx
	sqrtss	%xmm1, %xmm1
	shufps	$0, %xmm1, %xmm1
	divps	%xmm1, %xmm4
	movaps	LC1, %xmm1
	movaps	%xmm1, %xmm2
	movaps	%xmm1, %xmm5
	movaps	%xmm1, %xmm3
	subps	%xmm0, %xmm3
	dpps	$113, %xmm1, %xmm2
	sqrtss	%xmm2, %xmm2
	shufps	$0, %xmm2, %xmm2
	divps	%xmm2, %xmm5
	movaps	%xmm3, %xmm2
	movaps	%xmm4, (%edx)
	movl	12(%esp), %edx
	movaps	%xmm1, (%edx)
	movl	16(%esp), %edx
	dpps	$113, %xmm3, %xmm2
	sqrtss	%xmm2, %xmm2
	movaps	%xmm2, %xmm6
	shufps	$0, %xmm2, %xmm6
	movaps	%xmm5, (%edx)
	movl	20(%esp), %edx
	dpps	$113, %xmm5, %xmm4
	movaps	%xmm3, (%edx)
	movl	24(%esp), %edx
	divps	%xmm6, %xmm3
	movaps	%xmm3, (%edx)
	movl	28(%esp), %edx
	movaps	%xmm1, %xmm3
	shufps	$201, %xmm1, %xmm3
	movss	%xmm2, (%edx)
	movl	32(%esp), %edx
	movaps	%xmm0, %xmm2
	dpps	$113, %xmm1, %xmm2
	shufps	$210, %xmm1, %xmm1
	movss	%xmm2, (%edx)
	movl	36(%esp), %edx
	movaps	%xmm0, %xmm2
	shufps	$210, %xmm0, %xmm2
	shufps	$201, %xmm0, %xmm0
	mulps	%xmm3, %xmm2
	movss	%xmm4, (%edx)
	movl	44(%esp), %edx
	mulps	%xmm1, %xmm0
	subps	%xmm2, %xmm0
	movss	56(%esp), %xmm2
	movaps	%xmm0, %xmm1
	movaps	%xmm0, (%eax)
	shufps	$0, %xmm2, %xmm2
	dpps	$113, %xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	shufps	$0, %xmm1, %xmm1
	divps	%xmm1, %xmm0
	movaps	%xmm0, (%edx)
	movaps	(%eax), %xmm1
	movaps	%xmm1, %xmm0
	movl	48(%esp), %eax
	movaps	%xmm1, %xmm7
	dpps	$113, %xmm1, %xmm0
	sqrtss	%xmm0, %xmm0
	shufps	$0, %xmm0, %xmm0
	divps	%xmm0, %xmm7
	movaps	%xmm7, %xmm0
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
	dpps	$113, %xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	shufps	$0, %xmm1, %xmm1
	divps	%xmm1, %xmm7
	movaps	%xmm7, %xmm1
	mulps	%xmm2, %xmm1
	subps	%xmm1, %xmm0
	movaps	%xmm0, %xmm1
	movaps	%xmm0, (%eax)
	movl	52(%esp), %eax
	dpps	$113, %xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	shufps	$0, %xmm1, %xmm1
	divps	%xmm1, %xmm0
	movaps	%xmm0, (%eax)
	ret
	.cfi_endproc
LFE709:
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

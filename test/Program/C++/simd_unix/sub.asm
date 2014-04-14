	.file	"sub.cpp"
	.text
	.p2align 4,,15
	.globl	__Z3subR4vec4S0_S0_S0_S0_S0_Rfffff
	.def	__Z3subR4vec4S0_S0_S0_S0_S0_Rfffff;	.scl	2;	.type	32;	.endef
__Z3subR4vec4S0_S0_S0_S0_S0_Rfffff:
LFB663:
	.cfi_startproc
	movss	32(%esp), %xmm2
	movaps	LC0, %xmm3
	shufps	$0, %xmm2, %xmm2
	movl	4(%esp), %eax
	movss	36(%esp), %xmm0
	addps	%xmm3, %xmm2
	movaps	%xmm3, %xmm1
	shufps	$0, %xmm0, %xmm0
	mulps	%xmm3, %xmm1
	movaps	%xmm3, %xmm4
	movaps	%xmm3, (%eax)
	movl	8(%esp), %eax
	mulps	%xmm0, %xmm2
	movss	40(%esp), %xmm0
	shufps	$0, %xmm0, %xmm0
	divps	%xmm0, %xmm2
	movss	44(%esp), %xmm0
	shufps	$0, %xmm0, %xmm0
	subps	%xmm0, %xmm2
	xorps	%xmm0, %xmm0
	movaps	%xmm2, %xmm5
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	shufps	$0, %xmm1, %xmm1
	divps	%xmm1, %xmm4
	movaps	%xmm2, %xmm1
	mulps	%xmm2, %xmm1
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	shufps	$0, %xmm1, %xmm1
	movaps	%xmm4, (%eax)
	movl	12(%esp), %eax
	divps	%xmm1, %xmm5
	movaps	%xmm2, (%eax)
	movl	16(%esp), %eax
	subps	%xmm3, %xmm2
	movaps	%xmm2, %xmm1
	mulps	%xmm2, %xmm1
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	movaps	%xmm5, (%eax)
	movl	20(%esp), %eax
	movaps	%xmm1, %xmm0
	shufps	$0, %xmm1, %xmm0
	movaps	%xmm2, (%eax)
	movl	24(%esp), %eax
	divps	%xmm0, %xmm2
	movaps	%xmm2, (%eax)
	movl	28(%esp), %eax
	movss	%xmm1, (%eax)
	ret
	.cfi_endproc
LFE663:
	.section .rdata,"dr"
	.align 16
LC0:
	.long	1065353216
	.long	1073741824
	.long	1077936128
	.long	1082130432
	.ident	"GCC: (GNU) 4.8.2"

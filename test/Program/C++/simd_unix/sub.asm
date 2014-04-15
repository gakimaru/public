	.file	"sub.cpp"
	.text
	.p2align 4,,15
	.globl	__Z3subR4vec3S0_S0_S0_S0_S0_RfS1_S1_S0_S0_S0_S0_ffffi
	.def	__Z3subR4vec3S0_S0_S0_S0_S0_RfS1_S1_S0_S0_S0_S0_ffffi;	.scl	2;	.type	32;	.endef
__Z3subR4vec3S0_S0_S0_S0_S0_RfS1_S1_S0_S0_S0_S0_ffffi:
LFB700:
	.cfi_startproc
	movaps	LC0, %xmm2
	xorps	%xmm0, %xmm0
	movaps	%xmm2, %xmm1
	movl	4(%esp), %edx
	movaps	LC1, %xmm3
	mulps	%xmm2, %xmm1
	movaps	%xmm2, %xmm6
	movl	40(%esp), %eax
	movaps	%xmm3, %xmm7
	movaps	%xmm3, %xmm4
	subps	%xmm2, %xmm4
	movaps	%xmm2, (%edx)
	movl	8(%esp), %edx
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	shufps	$0, %xmm1, %xmm1
	divps	%xmm1, %xmm6
	movaps	%xmm3, %xmm1
	mulps	%xmm3, %xmm1
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	shufps	$0, %xmm1, %xmm1
	movaps	%xmm6, (%edx)
	movl	12(%esp), %edx
	divps	%xmm1, %xmm7
	movaps	%xmm4, %xmm1
	movaps	%xmm3, (%edx)
	movl	16(%esp), %edx
	mulps	%xmm4, %xmm1
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	movaps	%xmm7, (%edx)
	movl	20(%esp), %edx
	movaps	%xmm1, %xmm5
	shufps	$0, %xmm1, %xmm5
	movaps	%xmm4, (%edx)
	movl	24(%esp), %edx
	divps	%xmm5, %xmm4
	movaps	%xmm4, (%edx)
	movl	28(%esp), %edx
	movaps	%xmm3, %xmm4
	shufps	$201, %xmm3, %xmm4
	shufps	$210, %xmm3, %xmm3
	movss	%xmm1, (%edx)
	movl	32(%esp), %edx
	movaps	%xmm2, %xmm1
	shufps	$210, %xmm2, %xmm1
	shufps	$201, %xmm2, %xmm2
	mulps	%xmm4, %xmm1
	movl	$0xc2000000, (%edx)
	movl	36(%esp), %edx
	mulps	%xmm3, %xmm2
	movl	$0xbf798178, (%edx)
	movl	44(%esp), %edx
	subps	%xmm1, %xmm2
	movaps	%xmm2, %xmm1
	movaps	%xmm2, (%eax)
	mulps	%xmm2, %xmm1
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	shufps	$0, %xmm1, %xmm1
	divps	%xmm1, %xmm2
	movaps	%xmm2, (%edx)
	movaps	(%eax), %xmm3
	movaps	%xmm3, %xmm1
	movl	48(%esp), %eax
	movaps	%xmm3, %xmm2
	mulps	%xmm3, %xmm1
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	shufps	$0, %xmm1, %xmm1
	divps	%xmm1, %xmm2
	movss	56(%esp), %xmm1
	shufps	$0, %xmm1, %xmm1
	mulps	%xmm1, %xmm2
	movss	60(%esp), %xmm1
	shufps	$0, %xmm1, %xmm1
	addps	%xmm3, %xmm2
	movss	68(%esp), %xmm3
	mulps	%xmm1, %xmm2
	movss	64(%esp), %xmm1
	shufps	$0, %xmm3, %xmm3
	shufps	$0, %xmm1, %xmm1
	divps	%xmm1, %xmm2
	movaps	%xmm2, %xmm1
	movaps	%xmm2, %xmm6
	mulps	%xmm2, %xmm1
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	shufps	$0, %xmm1, %xmm1
	divps	%xmm1, %xmm6
	movaps	%xmm6, %xmm1
	mulps	%xmm3, %xmm1
	subps	%xmm1, %xmm2
	movaps	%xmm2, %xmm1
	movaps	%xmm2, (%eax)
	movl	52(%esp), %eax
	mulps	%xmm2, %xmm1
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	shufps	$0, %xmm1, %xmm1
	divps	%xmm1, %xmm2
	movaps	%xmm2, (%eax)
	ret
	.cfi_endproc
LFE700:
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

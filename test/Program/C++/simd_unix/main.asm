	.file	"main.cpp"
	.def	___main;	.scl	2;	.type	32;	.endef
	.def	___divdi3;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC5:
	.ascii "<use simd>\0"
LC6:
	.ascii "repeat = %d times\12\0"
LC7:
	.ascii "elapsed time = %.6f sec\12\0"
	.align 4
LC8:
	.ascii "v1 ={%.2f, %.2f, %.2f, %.2f}(%.4f)\12\0"
	.align 4
LC9:
	.ascii "v1n={%.2f, %.2f, %.2f, %.2f}(%.4f)\12\0"
	.align 4
LC10:
	.ascii "v2 ={%.2f, %.2f, %.2f, %.2f}(%.4f)\12\0"
	.align 4
LC11:
	.ascii "v2n={%.2f, %.2f, %.2f, %.2f}(%.4f)\12\0"
	.align 4
LC12:
	.ascii "vd ={%.2f, %.2f, %.2f, %.2f}(%.4f)\12\0"
	.align 4
LC13:
	.ascii "vdn={%.2f, %.2f, %.2f, %.2f}(%.4f)\12\0"
LC14:
	.ascii "dist=%.4f\12\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB933:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	$10000000, %ebx
	andl	$-16, %esp
	subl	$208, %esp
	call	___main
	leal	128(%esp), %edi
	call	__ZNSt6chrono3_V212system_clock3nowEv
	xorps	%xmm0, %xmm0
	leal	112(%esp), %esi
	movaps	%xmm0, 112(%esp)
	movaps	%xmm0, 128(%esp)
	movaps	%xmm0, 144(%esp)
	movaps	%xmm0, 160(%esp)
	movaps	%xmm0, 176(%esp)
	movaps	%xmm0, 192(%esp)
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	.p2align 4,,7
L3:
	leal	96(%esp), %eax
	movl	%eax, 24(%esp)
	leal	192(%esp), %eax
	movl	%eax, 20(%esp)
	leal	176(%esp), %eax
	movl	%eax, 16(%esp)
	leal	160(%esp), %eax
	movl	%eax, 12(%esp)
	leal	144(%esp), %eax
	movl	$0x40800000, 40(%esp)
	movl	$0x40400000, 36(%esp)
	movl	$0x40000000, 32(%esp)
	movl	$0x3f800000, 28(%esp)
	movl	%eax, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z3subR4vec4S0_S0_S0_S0_S0_Rfffff
	subl	$1, %ebx
	jne	L3
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$1000, 8(%esp)
	movl	$0, 12(%esp)
	subl	72(%esp), %eax
	sbbl	76(%esp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	___divdi3
	movl	$LC5, (%esp)
	movl	%edx, 84(%esp)
	movl	%eax, 80(%esp)
	fildq	80(%esp)
	fdivs	LC4
	fstps	92(%esp)
	flds	92(%esp)
	fstps	72(%esp)
	call	_puts
	movl	$10000000, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	$LC7, (%esp)
	flds	72(%esp)
	fstpl	4(%esp)
	call	_printf
	xorps	%xmm0, %xmm0
	movaps	112(%esp), %xmm1
	movl	$LC8, (%esp)
	mulps	%xmm1, %xmm1
	movaps	%xmm0, 48(%esp)
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	movss	%xmm1, 72(%esp)
	flds	72(%esp)
	fstpl	36(%esp)
	flds	124(%esp)
	fstpl	28(%esp)
	flds	120(%esp)
	fstpl	20(%esp)
	flds	116(%esp)
	fstpl	12(%esp)
	flds	112(%esp)
	fstpl	4(%esp)
	call	_printf
	movaps	128(%esp), %xmm1
	movl	$LC9, (%esp)
	mulps	%xmm1, %xmm1
	movaps	48(%esp), %xmm0
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	movss	%xmm1, 72(%esp)
	flds	72(%esp)
	fstpl	36(%esp)
	flds	140(%esp)
	fstpl	28(%esp)
	flds	136(%esp)
	fstpl	20(%esp)
	flds	132(%esp)
	fstpl	12(%esp)
	flds	128(%esp)
	fstpl	4(%esp)
	call	_printf
	movaps	144(%esp), %xmm1
	movl	$LC10, (%esp)
	mulps	%xmm1, %xmm1
	movaps	48(%esp), %xmm0
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	movss	%xmm1, 72(%esp)
	flds	72(%esp)
	fstpl	36(%esp)
	flds	156(%esp)
	fstpl	28(%esp)
	flds	152(%esp)
	fstpl	20(%esp)
	flds	148(%esp)
	fstpl	12(%esp)
	flds	144(%esp)
	fstpl	4(%esp)
	call	_printf
	movaps	160(%esp), %xmm1
	movl	$LC11, (%esp)
	mulps	%xmm1, %xmm1
	movaps	48(%esp), %xmm0
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	movss	%xmm1, 72(%esp)
	flds	72(%esp)
	fstpl	36(%esp)
	flds	172(%esp)
	fstpl	28(%esp)
	flds	168(%esp)
	fstpl	20(%esp)
	flds	164(%esp)
	fstpl	12(%esp)
	flds	160(%esp)
	fstpl	4(%esp)
	call	_printf
	movaps	176(%esp), %xmm1
	movl	$LC12, (%esp)
	mulps	%xmm1, %xmm1
	movaps	48(%esp), %xmm0
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	movss	%xmm1, 72(%esp)
	flds	72(%esp)
	fstpl	36(%esp)
	flds	188(%esp)
	fstpl	28(%esp)
	flds	184(%esp)
	fstpl	20(%esp)
	flds	180(%esp)
	fstpl	12(%esp)
	flds	176(%esp)
	fstpl	4(%esp)
	call	_printf
	movaps	192(%esp), %xmm1
	movl	$LC13, (%esp)
	mulps	%xmm1, %xmm1
	movaps	48(%esp), %xmm0
	haddps	%xmm0, %xmm1
	haddps	%xmm0, %xmm1
	sqrtss	%xmm1, %xmm1
	movss	%xmm1, 72(%esp)
	flds	72(%esp)
	fstpl	36(%esp)
	flds	204(%esp)
	fstpl	28(%esp)
	flds	200(%esp)
	fstpl	20(%esp)
	flds	196(%esp)
	fstpl	12(%esp)
	flds	192(%esp)
	fstpl	4(%esp)
	call	_printf
	movl	$LC14, (%esp)
	flds	96(%esp)
	fstpl	4(%esp)
	call	_printf
	leal	-12(%ebp), %esp
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE933:
	.section .rdata,"dr"
	.align 4
LC4:
	.long	1232348160
	.ident	"GCC: (GNU) 4.8.2"
	.def	__ZNSt6chrono3_V212system_clock3nowEv;	.scl	2;	.type	32;	.endef
	.def	__Z3subR4vec4S0_S0_S0_S0_S0_Rfffff;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef

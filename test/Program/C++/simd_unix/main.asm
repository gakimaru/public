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
	.ascii "v1       ={%.2f, %.2f, %.2f}(%.4f)\12\0"
	.align 4
LC9:
	.ascii "v1_n     ={%.2f, %.2f, %.2f}(%.4f)\12\0"
	.align 4
LC10:
	.ascii "v2       ={%.2f, %.2f, %.2f}(%.4f)\12\0"
	.align 4
LC11:
	.ascii "v2_n     ={%.2f, %.2f, %.2f}(%.4f)\12\0"
	.align 4
LC12:
	.ascii "vdist    ={%.2f, %.2f, %.2f}(%.4f)\12\0"
	.align 4
LC13:
	.ascii "vdist_n  ={%.2f, %.2f, %.2f}(%.4f)\12\0"
LC14:
	.ascii "dist_val =%.4f\12\0"
LC15:
	.ascii "dot_val  =%.4f\12\0"
LC16:
	.ascii "dot_val_n=%.4f\12\0"
	.align 4
LC17:
	.ascii "vcross   ={%.2f, %.2f, %.2f}(%.4f)\12\0"
	.align 4
LC18:
	.ascii "vcross_n ={%.2f, %.2f, %.2f}(%.4f)\12\0"
	.align 4
LC19:
	.ascii "v3       ={%.2f, %.2f, %.2f}(%.4f)\12\0"
	.align 4
LC20:
	.ascii "v3_n     ={%.2f, %.2f, %.2f}(%.4f)\12\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB981:
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
	xorl	%ebx, %ebx
	andl	$-16, %esp
	subl	$304, %esp
	call	___main
	leal	176(%esp), %edi
	call	__ZNSt6chrono3_V212system_clock3nowEv
	xorps	%xmm0, %xmm0
	leal	160(%esp), %esi
	movaps	%xmm0, 144(%esp)
	movaps	%xmm0, 160(%esp)
	movaps	%xmm0, 176(%esp)
	movaps	%xmm0, 192(%esp)
	movaps	%xmm0, 208(%esp)
	movaps	%xmm0, 224(%esp)
	movaps	%xmm0, 240(%esp)
	movaps	%xmm0, 256(%esp)
	movaps	%xmm0, 272(%esp)
	movaps	%xmm0, 288(%esp)
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	.p2align 4,,7
L3:
	leal	288(%esp), %eax
	movl	%eax, 48(%esp)
	leal	272(%esp), %eax
	movl	%eax, 44(%esp)
	leal	256(%esp), %eax
	movl	%eax, 40(%esp)
	leal	240(%esp), %eax
	movl	%eax, 36(%esp)
	leal	128(%esp), %eax
	movl	%eax, 32(%esp)
	leal	112(%esp), %eax
	movl	%eax, 28(%esp)
	leal	96(%esp), %eax
	movl	%eax, 24(%esp)
	leal	224(%esp), %eax
	movl	%eax, 20(%esp)
	leal	208(%esp), %eax
	movl	%eax, 16(%esp)
	leal	192(%esp), %eax
	movl	%eax, 12(%esp)
	leal	144(%esp), %eax
	movl	%ebx, 68(%esp)
	addl	$1, %ebx
	movl	$0x40800000, 64(%esp)
	movl	$0x40400000, 60(%esp)
	movl	$0x40000000, 56(%esp)
	movl	$0x3f800000, 52(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	__Z3subR4vec3S0_S0_S0_S0_S0_RfS1_S1_S0_S0_S0_S0_ffffi
	cmpl	$100000000, %ebx
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
	movl	$100000000, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	$LC7, (%esp)
	flds	72(%esp)
	fstpl	4(%esp)
	call	_printf
	movaps	144(%esp), %xmm0
	movl	$LC8, (%esp)
	dpps	$119, %xmm0, %xmm0
	sqrtps	%xmm0, %xmm0
	movss	%xmm0, 72(%esp)
	flds	72(%esp)
	fstpl	28(%esp)
	flds	152(%esp)
	fstpl	20(%esp)
	flds	148(%esp)
	fstpl	12(%esp)
	flds	144(%esp)
	fstpl	4(%esp)
	call	_printf
	movaps	160(%esp), %xmm0
	movl	$LC9, (%esp)
	dpps	$119, %xmm0, %xmm0
	sqrtps	%xmm0, %xmm0
	movss	%xmm0, 72(%esp)
	flds	72(%esp)
	fstpl	28(%esp)
	flds	168(%esp)
	fstpl	20(%esp)
	flds	164(%esp)
	fstpl	12(%esp)
	flds	160(%esp)
	fstpl	4(%esp)
	call	_printf
	movaps	176(%esp), %xmm0
	movl	$LC10, (%esp)
	dpps	$119, %xmm0, %xmm0
	sqrtps	%xmm0, %xmm0
	movss	%xmm0, 72(%esp)
	flds	72(%esp)
	fstpl	28(%esp)
	flds	184(%esp)
	fstpl	20(%esp)
	flds	180(%esp)
	fstpl	12(%esp)
	flds	176(%esp)
	fstpl	4(%esp)
	call	_printf
	movaps	192(%esp), %xmm0
	movl	$LC11, (%esp)
	dpps	$119, %xmm0, %xmm0
	sqrtps	%xmm0, %xmm0
	movss	%xmm0, 72(%esp)
	flds	72(%esp)
	fstpl	28(%esp)
	flds	200(%esp)
	fstpl	20(%esp)
	flds	196(%esp)
	fstpl	12(%esp)
	flds	192(%esp)
	fstpl	4(%esp)
	call	_printf
	movaps	208(%esp), %xmm0
	movl	$LC12, (%esp)
	dpps	$119, %xmm0, %xmm0
	sqrtps	%xmm0, %xmm0
	movss	%xmm0, 72(%esp)
	flds	72(%esp)
	fstpl	28(%esp)
	flds	216(%esp)
	fstpl	20(%esp)
	flds	212(%esp)
	fstpl	12(%esp)
	flds	208(%esp)
	fstpl	4(%esp)
	call	_printf
	movaps	224(%esp), %xmm0
	movl	$LC13, (%esp)
	dpps	$119, %xmm0, %xmm0
	sqrtps	%xmm0, %xmm0
	movss	%xmm0, 72(%esp)
	flds	72(%esp)
	fstpl	28(%esp)
	flds	232(%esp)
	fstpl	20(%esp)
	flds	228(%esp)
	fstpl	12(%esp)
	flds	224(%esp)
	fstpl	4(%esp)
	call	_printf
	movl	$LC14, (%esp)
	flds	96(%esp)
	fstpl	4(%esp)
	call	_printf
	movl	$LC15, (%esp)
	flds	112(%esp)
	fstpl	4(%esp)
	call	_printf
	movl	$LC16, (%esp)
	flds	128(%esp)
	fstpl	4(%esp)
	call	_printf
	movaps	240(%esp), %xmm0
	movl	$LC17, (%esp)
	dpps	$119, %xmm0, %xmm0
	sqrtps	%xmm0, %xmm0
	movss	%xmm0, 72(%esp)
	flds	72(%esp)
	fstpl	28(%esp)
	flds	248(%esp)
	fstpl	20(%esp)
	flds	244(%esp)
	fstpl	12(%esp)
	flds	240(%esp)
	fstpl	4(%esp)
	call	_printf
	movaps	256(%esp), %xmm0
	movl	$LC18, (%esp)
	dpps	$119, %xmm0, %xmm0
	sqrtps	%xmm0, %xmm0
	movss	%xmm0, 72(%esp)
	flds	72(%esp)
	fstpl	28(%esp)
	flds	264(%esp)
	fstpl	20(%esp)
	flds	260(%esp)
	fstpl	12(%esp)
	flds	256(%esp)
	fstpl	4(%esp)
	call	_printf
	movaps	272(%esp), %xmm0
	movl	$LC19, (%esp)
	dpps	$119, %xmm0, %xmm0
	sqrtps	%xmm0, %xmm0
	movss	%xmm0, 72(%esp)
	flds	72(%esp)
	fstpl	28(%esp)
	flds	280(%esp)
	fstpl	20(%esp)
	flds	276(%esp)
	fstpl	12(%esp)
	flds	272(%esp)
	fstpl	4(%esp)
	call	_printf
	movaps	288(%esp), %xmm0
	movl	$LC20, (%esp)
	dpps	$119, %xmm0, %xmm0
	sqrtps	%xmm0, %xmm0
	movss	%xmm0, 72(%esp)
	flds	72(%esp)
	fstpl	28(%esp)
	flds	296(%esp)
	fstpl	20(%esp)
	flds	292(%esp)
	fstpl	12(%esp)
	flds	288(%esp)
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
LFE981:
	.section .rdata,"dr"
	.align 4
LC4:
	.long	1232348160
	.ident	"GCC: (GNU) 4.8.2"
	.def	__ZNSt6chrono3_V212system_clock3nowEv;	.scl	2;	.type	32;	.endef
	.def	__Z3subR4vec3S0_S0_S0_S0_S0_RfS1_S1_S0_S0_S0_S0_ffffi;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef

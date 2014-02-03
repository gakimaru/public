	.file	"constexpr.cpp"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "{%d, %d, %d, %d, %d, %d, %d}\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$64, %esp
	call	___main
	movl	$2, 60(%esp)
	movl	$5, 56(%esp)
	movl	$9, 52(%esp)
	movl	$14, 48(%esp)
	movl	$14, 44(%esp)
	movl	$6, 40(%esp)
	movl	$15, 36(%esp)
	movl	$15, 28(%esp)
	movl	$6, 24(%esp)
	movl	$14, 20(%esp)
	movl	$14, 16(%esp)
	movl	$9, 12(%esp)
	movl	$5, 8(%esp)
	movl	$2, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.ident	"GCC: (GNU) 4.8.2"
	.def	_printf;	.scl	2;	.type	32;	.endef

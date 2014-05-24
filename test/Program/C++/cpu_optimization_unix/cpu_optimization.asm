	.file	"cpu_optimization.cpp"
	.section .rdata,"dr"
LC1:
	.ascii "*elapsed time=%.9lf\0"
	.text
	.p2align 4,,15
	.globl	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb
	.def	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb;	.scl	2;	.type	32;	.endef
__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb:
LFB2761:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	48(%esp), %esi
	movl	52(%esp), %ebx
	call	__ZNSt6chrono3_V212system_clock3nowEv
	subl	(%esi), %eax
	sbbl	4(%esi), %edx
	movl	$LC1, (%esp)
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	testb	%bl, %bl
	je	L5
	addl	$36, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L5:
	.cfi_restore_state
	movl	$10, 48(%esp)
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2761:
	.section .rdata,"dr"
	.align 4
LC3:
	.ascii "----------------------------------------\0"
LC4:
	.ascii "[Optimize Test 01]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt01v
	.def	__Z12runTestOpt01v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt01v:
LFB2767:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$40040, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_def_cfa_offset 40048
	movl	$LC3, (%esp)
	leal	28(%esp), %ebx
	call	_puts
	movl	$LC4, (%esp)
	call	_puts
	movl	%ebx, (%esp)
	call	__Z9initOpt01R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z18runTestOpt01_Type1R11dataOpt01_t
	addl	$40040, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2767:
	.section .rdata,"dr"
LC5:
	.ascii "Type1: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt01_Type1R11dataOpt01_t
	.def	__Z18runTestOpt01_Type1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z18runTestOpt01_Type1R11dataOpt01_t:
LFB2768:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	movl	$100000, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	%ebx, (%esp)
	call	__Z22testOpt01_Type1_BeforeR11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z22testOpt01_Type1_After1R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z22testOpt01_Type1_After2R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z22testOpt01_Type1_After3R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z22testOpt01_Type1_After4R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z24testOpt01_Type1_AppendixR11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt01_Type1_BeforeR11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt01_Type1_After1R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt01_Type1_After2R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt01_Type1_After3R11dataOpt01_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt01_Type1_After4R11dataOpt01_t
	movl	%ebx, 32(%esp)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	__Z27runTestOpt01_Type1_AppendixR11dataOpt01_t
	.cfi_endproc
LFE2768:
	.section .rdata,"dr"
LC6:
	.ascii "  Before   ... \0"
LC7:
	.ascii "  sum=%d\12\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt01_Type1_BeforeR11dataOpt01_t
	.def	__Z25runTestOpt01_Type1_BeforeR11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt01_Type1_BeforeR11dataOpt01_t:
LFB2769:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$100000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC6, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L12:
	movl	%esi, (%esp)
	call	__Z22testOpt01_Type1_BeforeR11dataOpt01_t
	subl	$1, %ebx
	jne	L12
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	(%esi), %eax
	movl	$LC7, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2769:
	.section .rdata,"dr"
LC8:
	.ascii "  After1   ... \0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt01_Type1_After1R11dataOpt01_t
	.def	__Z25runTestOpt01_Type1_After1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt01_Type1_After1R11dataOpt01_t:
LFB2770:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$100000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC8, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L16:
	movl	%esi, (%esp)
	call	__Z22testOpt01_Type1_After1R11dataOpt01_t
	subl	$1, %ebx
	jne	L16
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	(%esi), %eax
	movl	$LC7, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2770:
	.section .rdata,"dr"
LC9:
	.ascii "  After2   ... \0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt01_Type1_After2R11dataOpt01_t
	.def	__Z25runTestOpt01_Type1_After2R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt01_Type1_After2R11dataOpt01_t:
LFB2771:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$100000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC9, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L20:
	movl	%esi, (%esp)
	call	__Z22testOpt01_Type1_After2R11dataOpt01_t
	subl	$1, %ebx
	jne	L20
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	(%esi), %eax
	movl	$LC7, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2771:
	.section .rdata,"dr"
LC10:
	.ascii "  After3   ... \0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt01_Type1_After3R11dataOpt01_t
	.def	__Z25runTestOpt01_Type1_After3R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt01_Type1_After3R11dataOpt01_t:
LFB2772:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$100000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC10, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L24:
	movl	%esi, (%esp)
	call	__Z22testOpt01_Type1_After3R11dataOpt01_t
	subl	$1, %ebx
	jne	L24
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	(%esi), %eax
	movl	$LC7, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2772:
	.section .rdata,"dr"
LC11:
	.ascii "  After4   ... \0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt01_Type1_After4R11dataOpt01_t
	.def	__Z25runTestOpt01_Type1_After4R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt01_Type1_After4R11dataOpt01_t:
LFB2773:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$100000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC11, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L28:
	movl	%esi, (%esp)
	call	__Z22testOpt01_Type1_After4R11dataOpt01_t
	subl	$1, %ebx
	jne	L28
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	(%esi), %eax
	movl	$LC7, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2773:
	.section .rdata,"dr"
LC12:
	.ascii "  Appendix ... \0"
	.text
	.p2align 4,,15
	.globl	__Z27runTestOpt01_Type1_AppendixR11dataOpt01_t
	.def	__Z27runTestOpt01_Type1_AppendixR11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z27runTestOpt01_Type1_AppendixR11dataOpt01_t:
LFB2774:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$100000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC12, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L32:
	movl	%esi, (%esp)
	call	__Z24testOpt01_Type1_AppendixR11dataOpt01_t
	subl	$1, %ebx
	jne	L32
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	(%esi), %eax
	movl	$LC7, (%esp)
	movl	%eax, 4(%esp)
	call	_printf
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2774:
	.section .rdata,"dr"
LC13:
	.ascii "[Optimize Test 02]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt02v
	.def	__Z12runTestOpt02v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt02v:
LFB2775:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$40024, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_def_cfa_offset 40032
	movl	$LC3, (%esp)
	leal	16(%esp), %ebx
	call	_puts
	movl	$LC13, (%esp)
	call	_puts
	movl	%ebx, (%esp)
	call	__Z9initOpt02R11dataOpt02_t
	movl	%ebx, (%esp)
	call	__Z18runTestOpt02_Type1R11dataOpt02_t
	addl	$40024, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2775:
	.p2align 4,,15
	.globl	__Z18runTestOpt02_Type1R11dataOpt02_t
	.def	__Z18runTestOpt02_Type1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z18runTestOpt02_Type1R11dataOpt02_t:
LFB2776:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	movl	$100000, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	%ebx, (%esp)
	call	__Z22testOpt02_Type1_BeforeR11dataOpt02_t
	movl	%ebx, (%esp)
	call	__Z22testOpt02_Type1_After1R11dataOpt02_t
	movl	%ebx, (%esp)
	call	__Z22testOpt02_Type1_After2R11dataOpt02_t
	movl	%ebx, (%esp)
	call	__Z22testOpt02_Type1_After3R11dataOpt02_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt02_Type1_BeforeR11dataOpt02_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt02_Type1_After1R11dataOpt02_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt02_Type1_After2R11dataOpt02_t
	movl	%ebx, 32(%esp)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	__Z25runTestOpt02_Type1_After3R11dataOpt02_t
	.cfi_endproc
LFE2776:
	.p2align 4,,15
	.globl	__Z25runTestOpt02_Type1_BeforeR11dataOpt02_t
	.def	__Z25runTestOpt02_Type1_BeforeR11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt02_Type1_BeforeR11dataOpt02_t:
LFB2777:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC6, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L40:
	movl	%esi, (%esp)
	call	__Z22testOpt02_Type1_BeforeR11dataOpt02_t
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L40
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2777:
	.p2align 4,,15
	.globl	__Z25runTestOpt02_Type1_After1R11dataOpt02_t
	.def	__Z25runTestOpt02_Type1_After1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt02_Type1_After1R11dataOpt02_t:
LFB2778:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC8, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L44:
	movl	%esi, (%esp)
	call	__Z22testOpt02_Type1_After1R11dataOpt02_t
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L44
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2778:
	.p2align 4,,15
	.globl	__Z25runTestOpt02_Type1_After2R11dataOpt02_t
	.def	__Z25runTestOpt02_Type1_After2R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt02_Type1_After2R11dataOpt02_t:
LFB2779:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC9, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L48:
	movl	%esi, (%esp)
	call	__Z22testOpt02_Type1_After2R11dataOpt02_t
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L48
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2779:
	.p2align 4,,15
	.globl	__Z25runTestOpt02_Type1_After3R11dataOpt02_t
	.def	__Z25runTestOpt02_Type1_After3R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt02_Type1_After3R11dataOpt02_t:
LFB2780:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC10, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L52:
	movl	%esi, (%esp)
	call	__Z22testOpt02_Type1_After3R11dataOpt02_t
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L52
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2780:
	.section .rdata,"dr"
LC14:
	.ascii "[Optimize Test 03]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt03v
	.def	__Z12runTestOpt03v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt03v:
LFB2781:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$LC3, (%esp)
	call	_puts
	movl	$LC14, (%esp)
	call	_puts
	call	__Z18runTestOpt03_Type1v
	call	__Z18runTestOpt03_Type2v
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z18runTestOpt03_Type3v
	.cfi_endproc
LFE2781:
	.p2align 4,,15
	.globl	__Z25runTestOpt03_Type1_Beforeii
	.def	__Z25runTestOpt03_Type1_Beforeii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt03_Type1_Beforeii:
LFB2784:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	$LC6, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L58:
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%edi, 8(%esp)
	movl	%ebp, 4(%esp)
	call	__Z22testOpt03_Type1_Beforeiii
	addl	%eax, %esi
	cmpl	$100000000, %ebx
	jne	L58
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 68(%esp)
	movl	$LC7, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_printf
	.cfi_endproc
LFE2784:
	.section .rdata,"dr"
LC16:
	.ascii "  After    ... \0"
	.text
	.p2align 4,,15
	.globl	__Z24runTestOpt03_Type1_Afterii
	.def	__Z24runTestOpt03_Type1_Afterii;	.scl	2;	.type	32;	.endef
__Z24runTestOpt03_Type1_Afterii:
LFB2785:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$68, %esp
	.cfi_def_cfa_offset 80
	movl	80(%esp), %eax
	movl	$LC16, (%esp)
	movl	%eax, 16(%esp)
	movl	84(%esp), %eax
	movl	%eax, 32(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movd	16(%esp), %xmm6
	movd	32(%esp), %xmm7
	movdqa	LC17, %xmm5
	pshufd	$0, %xmm6, %xmm4
	pshufd	$0, %xmm7, %xmm3
	pxor	%xmm1, %xmm1
	movdqa	LC15, %xmm0
	movl	%eax, %ebx
	movl	%edx, %esi
	xorl	%eax, %eax
	jmp	L62
	.p2align 4,,7
L64:
	movdqa	%xmm2, %xmm0
L62:
	movdqa	%xmm0, %xmm2
	addl	$1, %eax
	pmulld	%xmm4, %xmm0
	paddd	%xmm3, %xmm0
	cmpl	$25000000, %eax
	paddd	%xmm5, %xmm2
	paddd	%xmm0, %xmm1
	jne	L64
	movdqa	%xmm1, %xmm6
	psrldq	$8, %xmm6
	paddd	%xmm6, %xmm1
	movdqa	%xmm1, %xmm7
	psrldq	$4, %xmm7
	movdqa	%xmm1, 32(%esp)
	movdqa	%xmm7, 16(%esp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	%ebx, %eax
	sbbl	%esi, %edx
	movl	%eax, 56(%esp)
	movl	%edx, 60(%esp)
	fildq	56(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movdqa	32(%esp), %xmm1
	paddd	16(%esp), %xmm1
	movl	$LC7, 80(%esp)
	movd	%xmm1, 84(%esp)
	addl	$68, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	_printf
	.cfi_endproc
LFE2785:
	.p2align 4,,15
	.globl	__Z25runTestOpt03_Type2_Beforeiiiiiii
	.def	__Z25runTestOpt03_Type2_Beforeiiiiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt03_Type2_Beforeiiiiiii:
LFB2788:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$92, %esp
	.cfi_def_cfa_offset 112
	movl	120(%esp), %eax
	movl	$LC6, (%esp)
	movl	112(%esp), %ebp
	movl	116(%esp), %edi
	movl	%eax, 44(%esp)
	movl	124(%esp), %eax
	movl	%eax, 48(%esp)
	movl	128(%esp), %eax
	movl	%eax, 52(%esp)
	movl	132(%esp), %eax
	movl	%eax, 56(%esp)
	movl	136(%esp), %eax
	movl	%eax, 60(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	.p2align 4,,7
L67:
	movl	60(%esp), %eax
	movl	%esi, (%esp)
	addl	$1, %esi
	movl	%edi, 8(%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 28(%esp)
	movl	56(%esp), %eax
	movl	%eax, 24(%esp)
	movl	52(%esp), %eax
	movl	%eax, 20(%esp)
	movl	48(%esp), %eax
	movl	%eax, 16(%esp)
	movl	44(%esp), %eax
	movl	%eax, 12(%esp)
	call	__Z22testOpt03_Type2_Beforeiiiiiiii
	addl	%eax, %ebx
	cmpl	$100000000, %esi
	jne	L67
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	64(%esp), %eax
	sbbl	68(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%ebx, 116(%esp)
	movl	$LC7, 112(%esp)
	addl	$92, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_printf
	.cfi_endproc
LFE2788:
	.p2align 4,,15
	.globl	__Z24runTestOpt03_Type2_Afteriiiiiii
	.def	__Z24runTestOpt03_Type2_Afteriiiiiii;	.scl	2;	.type	32;	.endef
__Z24runTestOpt03_Type2_Afteriiiiiii:
LFB2789:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$92, %esp
	.cfi_def_cfa_offset 112
	movl	112(%esp), %eax
	movl	120(%esp), %ebp
	movl	124(%esp), %edi
	movl	132(%esp), %esi
	movl	%eax, 60(%esp)
	movl	116(%esp), %eax
	movl	136(%esp), %ebx
	movl	$LC16, (%esp)
	imull	%edi, %ebp
	movl	%eax, 64(%esp)
	movl	128(%esp), %eax
	imull	%ebx, %esi
	movl	%eax, 68(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movd	60(%esp), %xmm4
	movd	64(%esp), %xmm5
	movl	%ebp, 16(%esp)
	pshufd	$0, %xmm4, %xmm6
	movd	68(%esp), %xmm3
	movl	%esi, 32(%esp)
	movd	16(%esp), %xmm4
	movdqa	LC17, %xmm7
	movd	32(%esp), %xmm1
	pshufd	$0, %xmm5, %xmm5
	pshufd	$0, %xmm1, %xmm1
	pshufd	$0, %xmm4, %xmm4
	movdqa	%xmm1, 16(%esp)
	pshufd	$0, %xmm3, %xmm3
	pxor	%xmm1, %xmm1
	movdqa	LC15, %xmm0
	movl	%eax, 48(%esp)
	xorl	%eax, %eax
	movl	%edx, 52(%esp)
	jmp	L71
	.p2align 4,,7
L73:
	movdqa	%xmm2, %xmm0
L71:
	movdqa	%xmm0, %xmm2
	pmulld	%xmm6, %xmm0
	addl	$1, %eax
	paddd	%xmm5, %xmm0
	cmpl	$25000000, %eax
	psubd	%xmm4, %xmm0
	paddd	%xmm7, %xmm2
	paddd	%xmm3, %xmm0
	psubd	16(%esp), %xmm0
	paddd	%xmm0, %xmm1
	jne	L73
	movdqa	%xmm1, %xmm7
	psrldq	$8, %xmm7
	paddd	%xmm7, %xmm1
	movdqa	%xmm1, %xmm3
	psrldq	$4, %xmm3
	movdqa	%xmm1, 32(%esp)
	movdqa	%xmm3, 16(%esp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	48(%esp), %eax
	sbbl	52(%esp), %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	fildq	72(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movdqa	32(%esp), %xmm1
	paddd	16(%esp), %xmm1
	movl	$LC7, 112(%esp)
	movd	%xmm1, 116(%esp)
	addl	$92, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_printf
	.cfi_endproc
LFE2789:
	.section .rdata,"dr"
LC18:
	.ascii "Type3: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt03_Type3v
	.def	__Z18runTestOpt03_Type3v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt03_Type3v:
LFB2790:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$40024, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_def_cfa_offset 40032
	leal	16(%esp), %ebx
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z22testOpt03_Type3_BeforeR11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z22testOpt03_Type3_After1R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z22testOpt03_Type3_After2R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z22testOpt03_Type3_After3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z25testOpt03_Type3_Appendix1R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z25testOpt03_Type3_Appendix2R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z25testOpt03_Type3_Appendix3R11dataOpt03_t
	movl	$10000, 4(%esp)
	movl	$LC18, (%esp)
	call	_printf
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt03_Type3_BeforeR11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt03_Type3_After1R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt03_Type3_After2R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt03_Type3_After3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z28runTestOpt03_Type3_Appendix1R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z28runTestOpt03_Type3_Appendix2R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	%ebx, (%esp)
	call	__Z28runTestOpt03_Type3_Appendix3R11dataOpt03_t
	addl	$40024, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2790:
	.section .rdata,"dr"
LC19:
	.ascii "  count=%d\12\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt03_Type3_BeforeR11dataOpt03_t
	.def	__Z25runTestOpt03_Type3_BeforeR11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt03_Type3_BeforeR11dataOpt03_t:
LFB2791:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC6, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L78:
	movl	%edi, (%esp)
	call	__Z22testOpt03_Type3_BeforeR11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L78
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC19, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2791:
	.p2align 4,,15
	.globl	__Z25runTestOpt03_Type3_After1R11dataOpt03_t
	.def	__Z25runTestOpt03_Type3_After1R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt03_Type3_After1R11dataOpt03_t:
LFB2792:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC8, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L82:
	movl	%edi, (%esp)
	call	__Z22testOpt03_Type3_After1R11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L82
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC19, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2792:
	.p2align 4,,15
	.globl	__Z25runTestOpt03_Type3_After2R11dataOpt03_t
	.def	__Z25runTestOpt03_Type3_After2R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt03_Type3_After2R11dataOpt03_t:
LFB2793:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC9, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L86:
	movl	%edi, (%esp)
	call	__Z22testOpt03_Type3_After2R11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L86
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC19, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2793:
	.p2align 4,,15
	.globl	__Z25runTestOpt03_Type3_After3R11dataOpt03_t
	.def	__Z25runTestOpt03_Type3_After3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt03_Type3_After3R11dataOpt03_t:
LFB2794:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC10, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L90:
	movl	%edi, (%esp)
	call	__Z22testOpt03_Type3_After3R11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L90
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC19, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2794:
	.section .rdata,"dr"
LC20:
	.ascii "  Appendix1... \0"
	.text
	.p2align 4,,15
	.globl	__Z28runTestOpt03_Type3_Appendix1R11dataOpt03_t
	.def	__Z28runTestOpt03_Type3_Appendix1R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z28runTestOpt03_Type3_Appendix1R11dataOpt03_t:
LFB2795:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC20, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L94:
	movl	%edi, (%esp)
	call	__Z25testOpt03_Type3_Appendix1R11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L94
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC19, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2795:
	.section .rdata,"dr"
LC21:
	.ascii "  Appendix2... \0"
	.text
	.p2align 4,,15
	.globl	__Z28runTestOpt03_Type3_Appendix2R11dataOpt03_t
	.def	__Z28runTestOpt03_Type3_Appendix2R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z28runTestOpt03_Type3_Appendix2R11dataOpt03_t:
LFB2796:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC21, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L98:
	movl	%edi, (%esp)
	call	__Z25testOpt03_Type3_Appendix2R11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L98
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC19, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2796:
	.section .rdata,"dr"
LC22:
	.ascii "  Appendix3... \0"
	.text
	.p2align 4,,15
	.globl	__Z28runTestOpt03_Type3_Appendix3R11dataOpt03_t
	.def	__Z28runTestOpt03_Type3_Appendix3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z28runTestOpt03_Type3_Appendix3R11dataOpt03_t:
LFB2797:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	xorl	%esi, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC22, (%esp)
	movl	48(%esp), %edi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L102:
	movl	%edi, (%esp)
	call	__Z25testOpt03_Type3_Appendix3R11dataOpt03_t
	addl	%eax, %esi
	subl	$1, %ebx
	jne	L102
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%esi, 4(%esp)
	movl	$LC19, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2797:
	.section .rdata,"dr"
LC23:
	.ascii "[Optimize Test 04]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt04v
	.def	__Z12runTestOpt04v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt04v:
LFB2798:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$80024, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_def_cfa_offset 80032
	movl	$LC3, (%esp)
	leal	16(%esp), %ebx
	call	_puts
	movl	$LC23, (%esp)
	call	_puts
	movl	%ebx, (%esp)
	call	__Z9initOpt04R11dataOpt04_t
	movl	%ebx, (%esp)
	call	__Z18runTestOpt04_Type1R11dataOpt04_t
	addl	$80024, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2798:
	.p2align 4,,15
	.globl	__Z18runTestOpt04_Type1R11dataOpt04_t
	.def	__Z18runTestOpt04_Type1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z18runTestOpt04_Type1R11dataOpt04_t:
LFB2799:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	movl	$10000, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	%ebx, (%esp)
	call	__Z25runTestOpt04_Type1_BeforeR11dataOpt04_t
	movl	%ebx, (%esp)
	call	__Z25runTestOpt04_Type1_After1R11dataOpt04_t
	movl	%ebx, 32(%esp)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	__Z25runTestOpt04_Type1_After2R11dataOpt04_t
	.cfi_endproc
LFE2799:
	.p2align 4,,15
	.globl	__Z25runTestOpt04_Type1_BeforeR11dataOpt04_t
	.def	__Z25runTestOpt04_Type1_BeforeR11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type1_BeforeR11dataOpt04_t:
LFB2800:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$10000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC6, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L110:
	movl	%esi, (%esp)
	call	__Z22testOpt04_Type1_BeforeR11dataOpt04_t
	subl	$1, %ebx
	jne	L110
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 48(%esp)
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2800:
	.p2align 4,,15
	.globl	__Z25runTestOpt04_Type1_After1R11dataOpt04_t
	.def	__Z25runTestOpt04_Type1_After1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type1_After1R11dataOpt04_t:
LFB2801:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$10000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC8, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L114:
	movl	%esi, (%esp)
	call	__Z22testOpt04_Type1_After1R11dataOpt04_t
	subl	$1, %ebx
	jne	L114
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 48(%esp)
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2801:
	.p2align 4,,15
	.globl	__Z25runTestOpt04_Type1_After2R11dataOpt04_t
	.def	__Z25runTestOpt04_Type1_After2R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type1_After2R11dataOpt04_t:
LFB2802:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	$10000, %ebx
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$LC9, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L118:
	movl	%esi, (%esp)
	call	__Z22testOpt04_Type1_After2R11dataOpt04_t
	subl	$1, %ebx
	jne	L118
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 48(%esp)
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2802:
	.section .rdata,"dr"
LC24:
	.ascii "[Optimize Test 05]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt05v
	.def	__Z12runTestOpt05v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt05v:
LFB2803:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$LC3, (%esp)
	call	_puts
	movl	$LC24, (%esp)
	call	_puts
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z18runTestOpt05_Type1v
	.cfi_endproc
LFE2803:
	.p2align 4,,15
	.globl	__Z18runTestOpt05_Type1v
	.def	__Z18runTestOpt05_Type1v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt05_Type1v:
LFB2804:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$10000000, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	call	__Z25runTestOpt05_Type1_Beforev
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z24runTestOpt05_Type1_Afterv
	.cfi_endproc
LFE2804:
	.p2align 4,,15
	.globl	__Z25runTestOpt05_Type1_Beforev
	.def	__Z25runTestOpt05_Type1_Beforev;	.scl	2;	.type	32;	.endef
__Z25runTestOpt05_Type1_Beforev:
LFB2805:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$220, %esp
	.cfi_def_cfa_offset 240
	movl	$LC6, (%esp)
	leal	136(%esp), %ebp
	call	_printf
	leal	132(%esp), %edi
	call	__ZNSt6chrono3_V212system_clock3nowEv
	leal	128(%esp), %esi
	movl	%eax, 96(%esp)
	movl	%edx, 100(%esp)
	.p2align 4,,7
L126:
	leal	204(%esp), %eax
	movl	%eax, 84(%esp)
	leal	200(%esp), %eax
	movl	%eax, 80(%esp)
	leal	196(%esp), %eax
	movl	%eax, 76(%esp)
	leal	192(%esp), %eax
	movl	%eax, 72(%esp)
	leal	188(%esp), %eax
	movl	%eax, 68(%esp)
	leal	184(%esp), %eax
	movl	%eax, 64(%esp)
	leal	180(%esp), %eax
	movl	%eax, 60(%esp)
	leal	176(%esp), %eax
	movl	%eax, 56(%esp)
	leal	172(%esp), %eax
	movl	%eax, 52(%esp)
	leal	168(%esp), %eax
	movl	%eax, 48(%esp)
	leal	164(%esp), %eax
	movl	%eax, 44(%esp)
	leal	160(%esp), %eax
	movl	%eax, 40(%esp)
	leal	156(%esp), %eax
	movl	%eax, 36(%esp)
	leal	152(%esp), %eax
	movl	%eax, 32(%esp)
	leal	148(%esp), %eax
	movl	%eax, 28(%esp)
	leal	144(%esp), %eax
	movl	%eax, 24(%esp)
	leal	140(%esp), %eax
	movl	%eax, 20(%esp)
	leal	124(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%ebp, 16(%esp)
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z22testOpt05_Type1_BeforeiRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_
	cmpl	$10000000, %ebx
	jne	L126
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	96(%esp), %eax
	sbbl	100(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, (%esp)
	call	_putchar
	addl	$220, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2805:
	.p2align 4,,15
	.globl	__Z24runTestOpt05_Type1_Afterv
	.def	__Z24runTestOpt05_Type1_Afterv;	.scl	2;	.type	32;	.endef
__Z24runTestOpt05_Type1_Afterv:
LFB2806:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$220, %esp
	.cfi_def_cfa_offset 240
	movl	$LC16, (%esp)
	leal	136(%esp), %ebp
	call	_printf
	leal	132(%esp), %edi
	call	__ZNSt6chrono3_V212system_clock3nowEv
	leal	128(%esp), %esi
	movl	%eax, 96(%esp)
	movl	%edx, 100(%esp)
	.p2align 4,,7
L130:
	leal	204(%esp), %eax
	movl	%eax, 84(%esp)
	leal	200(%esp), %eax
	movl	%eax, 80(%esp)
	leal	196(%esp), %eax
	movl	%eax, 76(%esp)
	leal	192(%esp), %eax
	movl	%eax, 72(%esp)
	leal	188(%esp), %eax
	movl	%eax, 68(%esp)
	leal	184(%esp), %eax
	movl	%eax, 64(%esp)
	leal	180(%esp), %eax
	movl	%eax, 60(%esp)
	leal	176(%esp), %eax
	movl	%eax, 56(%esp)
	leal	172(%esp), %eax
	movl	%eax, 52(%esp)
	leal	168(%esp), %eax
	movl	%eax, 48(%esp)
	leal	164(%esp), %eax
	movl	%eax, 44(%esp)
	leal	160(%esp), %eax
	movl	%eax, 40(%esp)
	leal	156(%esp), %eax
	movl	%eax, 36(%esp)
	leal	152(%esp), %eax
	movl	%eax, 32(%esp)
	leal	148(%esp), %eax
	movl	%eax, 28(%esp)
	leal	144(%esp), %eax
	movl	%eax, 24(%esp)
	leal	140(%esp), %eax
	movl	%eax, 20(%esp)
	leal	124(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%ebp, 16(%esp)
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z21testOpt05_Type1_AfteriRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_
	cmpl	$10000000, %ebx
	jne	L130
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	96(%esp), %eax
	sbbl	100(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, (%esp)
	call	_putchar
	addl	$220, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2806:
	.p2align 4,,15
	.globl	__Z18runTestOpt06_Type1R11dataOpt06_tfff
	.def	__Z18runTestOpt06_Type1R11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
__Z18runTestOpt06_Type1R11dataOpt06_tfff:
LFB2809:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$40, %esp
	.cfi_def_cfa_offset 48
	flds	52(%esp)
	fstps	20(%esp)
	movl	48(%esp), %ebx
	flds	56(%esp)
	fstps	24(%esp)
	flds	60(%esp)
	movl	$10000, 4(%esp)
	fstps	28(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movss	28(%esp), %xmm0
	movss	24(%esp), %xmm1
	movss	20(%esp), %xmm2
	movss	%xmm0, 12(%esp)
	movss	%xmm1, 8(%esp)
	movss	%xmm2, 4(%esp)
	movl	%ebx, (%esp)
	call	__Z25runTestOpt06_Type1_BeforeR11dataOpt06_tfff
	movss	28(%esp), %xmm0
	movss	24(%esp), %xmm1
	movss	20(%esp), %xmm2
	movl	%ebx, 48(%esp)
	movss	%xmm0, 60(%esp)
	movss	%xmm1, 56(%esp)
	movss	%xmm2, 52(%esp)
	addl	$40, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	__Z24runTestOpt06_Type1_AfterR11dataOpt06_tfff
	.cfi_endproc
LFE2809:
	.p2align 4,,15
	.globl	__Z25runTestOpt06_Type1_BeforeR11dataOpt06_tfff
	.def	__Z25runTestOpt06_Type1_BeforeR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
__Z25runTestOpt06_Type1_BeforeR11dataOpt06_tfff:
LFB2810:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$10000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	flds	84(%esp)
	fstps	28(%esp)
	movl	80(%esp), %esi
	flds	88(%esp)
	fstps	32(%esp)
	flds	92(%esp)
	movl	$LC6, (%esp)
	fstps	36(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, %edi
	movl	%edx, %ebp
	.p2align 4,,7
L136:
	movss	36(%esp), %xmm0
	movss	32(%esp), %xmm1
	movss	28(%esp), %xmm2
	movss	%xmm0, 12(%esp)
	movss	%xmm1, 8(%esp)
	movss	%xmm2, 4(%esp)
	movl	%esi, (%esp)
	call	__Z22testOpt06_Type1_BeforeR11dataOpt06_tfff
	subl	$1, %ebx
	jne	L136
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	%edi, %eax
	sbbl	%ebp, %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 80(%esp)
	addl	$60, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2810:
	.p2align 4,,15
	.globl	__Z24runTestOpt06_Type1_AfterR11dataOpt06_tfff
	.def	__Z24runTestOpt06_Type1_AfterR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
__Z24runTestOpt06_Type1_AfterR11dataOpt06_tfff:
LFB2811:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$10000, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	flds	84(%esp)
	fstps	28(%esp)
	movl	80(%esp), %esi
	flds	88(%esp)
	fstps	32(%esp)
	flds	92(%esp)
	movl	$LC16, (%esp)
	fstps	36(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, %edi
	movl	%edx, %ebp
	.p2align 4,,7
L140:
	movss	36(%esp), %xmm0
	movss	32(%esp), %xmm1
	movss	28(%esp), %xmm2
	movss	%xmm0, 12(%esp)
	movss	%xmm1, 8(%esp)
	movss	%xmm2, 4(%esp)
	movl	%esi, (%esp)
	call	__Z21testOpt06_Type1_AfterR11dataOpt06_tfff
	subl	$1, %ebx
	jne	L140
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	%edi, %eax
	sbbl	%ebp, %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 80(%esp)
	addl	$60, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2811:
	.section .rdata,"dr"
LC25:
	.ascii "[Optimize Test 07]\0"
LC26:
	.ascii "Type2: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt07v
	.def	__Z12runTestOpt07v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt07v:
LFB2812:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$LC3, (%esp)
	call	_puts
	movl	$LC25, (%esp)
	call	_puts
	call	__Z18runTestOpt07_Type1v
	movl	$1000000, 4(%esp)
	movl	$LC26, (%esp)
	call	_printf
	call	__Z25runTestOpt07_Type2_strlenv
	call	__Z25runTestOpt07_Type2_strcmpv
	.p2align 4,,5
	call	__Z26runTestOpt07_Type2_strncmpv
	.p2align 4,,5
	call	__Z25runTestOpt07_Type2_strchrv
	.p2align 4,,5
	call	__Z26runTestOpt07_Type2_strrchrv
	.p2align 4,,5
	call	__Z25runTestOpt07_Type2_strstrv
	.p2align 4,,5
	call	__Z25runTestOpt07_Type2_strcpyv
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z26runTestOpt07_Type2_strncpyv
	.cfi_endproc
LFE2812:
	.p2align 4,,15
	.globl	__Z18runTestOpt07_Type1v
	.def	__Z18runTestOpt07_Type1v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt07_Type1v:
LFB2813:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$10000000, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	call	__Z25runTestOpt07_Type1_Beforev
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z24runTestOpt07_Type1_Afterv
	.cfi_endproc
LFE2813:
	.p2align 4,,15
	.globl	__Z25runTestOpt07_Type1_Beforev
	.def	__Z25runTestOpt07_Type1_Beforev;	.scl	2;	.type	32;	.endef
__Z25runTestOpt07_Type1_Beforev:
LFB2814:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$588, %esp
	.cfi_def_cfa_offset 608
	movl	$LC6, (%esp)
	leal	256(%esp), %ebx
	call	_printf
	leal	384(%esp), %ebp
	call	__ZNSt6chrono3_V212system_clock3nowEv
	leal	448(%esp), %edi
	leal	512(%esp), %esi
	flds	LC27
	fldz
	fld	%st(0)
	fld	%st(2)
	fld	%st(2)
	movl	%eax, 48(%esp)
	fld1
	fxch	%st(1)
	xorl	%eax, %eax
	movl	%edx, 52(%esp)
	jmp	L148
	.p2align 4,,7
L154:
	fxch	%st(5)
L148:
	fsts	(%ebx,%eax)
	fxch	%st(2)
	fsts	320(%esp,%eax)
	fxch	%st(3)
	fsts	0(%ebp,%eax)
	fxch	%st(4)
	fsts	(%edi,%eax)
	fxch	%st(5)
	fsts	(%esi,%eax)
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fsts	260(%esp,%eax)
	fxch	%st(4)
	fsts	324(%esp,%eax)
	fxch	%st(5)
	fsts	388(%esp,%eax)
	fxch	%st(2)
	fsts	452(%esp,%eax)
	fxch	%st(3)
	fsts	516(%esp,%eax)
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fsts	264(%esp,%eax)
	fxch	%st(2)
	fsts	328(%esp,%eax)
	fxch	%st(3)
	fsts	392(%esp,%eax)
	fxch	%st(4)
	fsts	456(%esp,%eax)
	fxch	%st(5)
	fsts	520(%esp,%eax)
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fsts	268(%esp,%eax)
	fxch	%st(4)
	fsts	332(%esp,%eax)
	fxch	%st(5)
	fsts	396(%esp,%eax)
	fxch	%st(2)
	fsts	460(%esp,%eax)
	fxch	%st(3)
	fsts	524(%esp,%eax)
	fxch	%st(4)
	addl	$16, %eax
	fadd	%st(1), %st
	fxch	%st(5)
	cmpl	$64, %eax
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	jne	L154
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	xorb	%al, %al
	.p2align 4,,7
L150:
	leal	320(%esp), %edx
	leal	192(%esp), %ecx
	movl	%edx, 20(%esp)
	leal	128(%esp), %edx
	movl	%ecx, 12(%esp)
	leal	64(%esp), %ecx
	movl	%eax, (%esp)
	movl	%esi, 36(%esp)
	movl	%edi, 32(%esp)
	movl	$0x40a00000, 28(%esp)
	movl	%ebp, 24(%esp)
	movl	%ebx, 16(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	movl	44(%esp), %eax
	addl	$1, %eax
	cmpl	$10000000, %eax
	jne	L150
	movl	$0x00000000, 320(%esp)
	xorl	%eax, %eax
	movl	$0x42c80000, 384(%esp)
	movl	$0x00000000, 448(%esp)
	movl	$0x3f800000, 324(%esp)
	movl	$0x42ca0000, 388(%esp)
	movl	$0x3f800000, 452(%esp)
	movl	$0x40000000, 328(%esp)
	movl	$0x42cc0000, 392(%esp)
	movl	$0x40000000, 456(%esp)
	movl	$0x40400000, 332(%esp)
	movl	$0x42ce0000, 396(%esp)
	movl	$0x40400000, 460(%esp)
	movl	$0x00000000, 64(%esp)
	movl	$0x3f800000, 68(%esp)
	movl	$0x40000000, 72(%esp)
	movl	$0x42c80000, 512(%esp)
	movl	$0x42ca0000, 516(%esp)
	movl	$0x42cc0000, 520(%esp)
	movl	$0x42ce0000, 524(%esp)
	movl	$0x42d00000, 528(%esp)
	movl	$0x42d20000, 532(%esp)
	movl	$0x42d40000, 536(%esp)
	movl	$0x42d60000, 540(%esp)
	movl	$0x42d80000, 544(%esp)
	movl	$0x42da0000, 548(%esp)
	movl	$0x42dc0000, 552(%esp)
	movl	$0x42de0000, 556(%esp)
	.p2align 4,,7
L152:
	leal	64(%esp), %edx
	leal	320(%esp), %ecx
	movl	%edx, 32(%esp)
	leal	192(%esp), %edx
	movl	%ecx, 16(%esp)
	leal	128(%esp), %ecx
	movl	%eax, (%esp)
	movl	%esi, 36(%esp)
	movl	$0x40a00000, 28(%esp)
	movl	%edi, 24(%esp)
	movl	%ebp, 20(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 44(%esp)
	call	__Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	movl	44(%esp), %eax
	addl	$1, %eax
	cmpl	$10000000, %eax
	jne	L152
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	48(%esp), %eax
	sbbl	52(%esp), %edx
	movl	%eax, 56(%esp)
	movl	%edx, 60(%esp)
	fildq	56(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, (%esp)
	call	_putchar
	addl	$588, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2814:
	.p2align 4,,15
	.globl	__Z24runTestOpt07_Type1_Afterv
	.def	__Z24runTestOpt07_Type1_Afterv;	.scl	2;	.type	32;	.endef
__Z24runTestOpt07_Type1_Afterv:
LFB2815:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$588, %esp
	.cfi_def_cfa_offset 608
	movl	$LC16, (%esp)
	leal	256(%esp), %ebx
	call	_printf
	leal	384(%esp), %ebp
	call	__ZNSt6chrono3_V212system_clock3nowEv
	leal	448(%esp), %edi
	leal	512(%esp), %esi
	flds	LC27
	fldz
	fld	%st(0)
	fld	%st(2)
	fld	%st(2)
	movl	%eax, 48(%esp)
	fld1
	fxch	%st(1)
	xorl	%eax, %eax
	movl	%edx, 52(%esp)
	jmp	L157
	.p2align 4,,7
L163:
	fxch	%st(5)
L157:
	fsts	(%ebx,%eax)
	fxch	%st(2)
	fsts	320(%esp,%eax)
	fxch	%st(3)
	fsts	0(%ebp,%eax)
	fxch	%st(4)
	fsts	(%edi,%eax)
	fxch	%st(5)
	fsts	(%esi,%eax)
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fsts	260(%esp,%eax)
	fxch	%st(4)
	fsts	324(%esp,%eax)
	fxch	%st(5)
	fsts	388(%esp,%eax)
	fxch	%st(2)
	fsts	452(%esp,%eax)
	fxch	%st(3)
	fsts	516(%esp,%eax)
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fsts	264(%esp,%eax)
	fxch	%st(2)
	fsts	328(%esp,%eax)
	fxch	%st(3)
	fsts	392(%esp,%eax)
	fxch	%st(4)
	fsts	456(%esp,%eax)
	fxch	%st(5)
	fsts	520(%esp,%eax)
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	fxch	%st(5)
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fsts	268(%esp,%eax)
	fxch	%st(4)
	fsts	332(%esp,%eax)
	fxch	%st(5)
	fsts	396(%esp,%eax)
	fxch	%st(2)
	fsts	460(%esp,%eax)
	fxch	%st(3)
	fsts	524(%esp,%eax)
	fxch	%st(4)
	addl	$16, %eax
	fadd	%st(1), %st
	fxch	%st(5)
	cmpl	$64, %eax
	fadd	%st(1), %st
	fxch	%st(2)
	fadd	%st(1), %st
	fxch	%st(3)
	fadd	%st(1), %st
	fxch	%st(4)
	fadd	%st(1), %st
	jne	L163
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	xorb	%al, %al
	.p2align 4,,7
L159:
	leal	320(%esp), %edx
	leal	192(%esp), %ecx
	movl	%edx, 20(%esp)
	leal	128(%esp), %edx
	movl	%ecx, 12(%esp)
	leal	64(%esp), %ecx
	movl	%eax, (%esp)
	movl	%esi, 36(%esp)
	movl	%edi, 32(%esp)
	movl	$0x40a00000, 28(%esp)
	movl	%ebp, 24(%esp)
	movl	%ebx, 16(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 44(%esp)
	call	__Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	movl	44(%esp), %eax
	addl	$1, %eax
	cmpl	$10000000, %eax
	jne	L159
	movl	$0x00000000, 320(%esp)
	xorl	%eax, %eax
	movl	$0x42c80000, 384(%esp)
	movl	$0x00000000, 448(%esp)
	movl	$0x3f800000, 324(%esp)
	movl	$0x42ca0000, 388(%esp)
	movl	$0x3f800000, 452(%esp)
	movl	$0x40000000, 328(%esp)
	movl	$0x42cc0000, 392(%esp)
	movl	$0x40000000, 456(%esp)
	movl	$0x40400000, 332(%esp)
	movl	$0x42ce0000, 396(%esp)
	movl	$0x40400000, 460(%esp)
	movl	$0x00000000, 64(%esp)
	movl	$0x3f800000, 68(%esp)
	movl	$0x40000000, 72(%esp)
	movl	$0x42c80000, 512(%esp)
	movl	$0x42ca0000, 516(%esp)
	movl	$0x42cc0000, 520(%esp)
	movl	$0x42ce0000, 524(%esp)
	movl	$0x42d00000, 528(%esp)
	movl	$0x42d20000, 532(%esp)
	movl	$0x42d40000, 536(%esp)
	movl	$0x42d60000, 540(%esp)
	movl	$0x42d80000, 544(%esp)
	movl	$0x42da0000, 548(%esp)
	movl	$0x42dc0000, 552(%esp)
	movl	$0x42de0000, 556(%esp)
	.p2align 4,,7
L161:
	leal	64(%esp), %edx
	leal	320(%esp), %ecx
	movl	%edx, 32(%esp)
	leal	192(%esp), %edx
	movl	%ecx, 16(%esp)
	leal	128(%esp), %ecx
	movl	%eax, (%esp)
	movl	%esi, 36(%esp)
	movl	$0x40a00000, 28(%esp)
	movl	%edi, 24(%esp)
	movl	%ebp, 20(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 44(%esp)
	call	__Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE
	movl	44(%esp), %eax
	addl	$1, %eax
	cmpl	$10000000, %eax
	jne	L161
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	48(%esp), %eax
	sbbl	52(%esp), %edx
	movl	%eax, 56(%esp)
	movl	%edx, 60(%esp)
	fildq	56(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, (%esp)
	call	_putchar
	addl	$588, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2815:
	.section .rdata,"dr"
LC44:
	.ascii "Type2(strlen):\0"
LC45:
	.ascii "\0"
LC46:
	.ascii "123\0"
LC47:
	.ascii "1234567890abcdef\0"
LC48:
	.ascii "1234567890abcdefg\0"
	.align 4
LC49:
	.ascii "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt07_Type2_strlenv
	.def	__Z25runTestOpt07_Type2_strlenv;	.scl	2;	.type	32;	.endef
__Z25runTestOpt07_Type2_strlenv:
LFB2816:
	.cfi_startproc
	subl	$44, %esp
	.cfi_def_cfa_offset 48
	movl	$LC44, (%esp)
	call	_puts
	movl	$LC45, 16(%esp)
	movl	$LC46, 12(%esp)
	movl	$LC47, 8(%esp)
	movl	$LC48, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z32runTestOpt07_Type2_strlen_BeforePKcS0_S0_S0_S0_
	movl	$LC45, 16(%esp)
	movl	$LC46, 12(%esp)
	movl	$LC47, 8(%esp)
	movl	$LC48, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z31runTestOpt07_Type2_strlen_AfterPKcS0_S0_S0_S0_
	addl	$44, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2816:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strlen_BeforePKcS0_S0_S0_S0_
	.def	__Z32runTestOpt07_Type2_strlen_BeforePKcS0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strlen_BeforePKcS0_S0_S0_S0_:
LFB2817:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	92(%esp), %eax
	movl	$LC6, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	88(%esp), %esi
	movl	%eax, 24(%esp)
	movl	96(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L168:
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	call	__Z29testOpt07_Type2_strlen_BeforeiPKc
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	call	__Z29testOpt07_Type2_strlen_BeforeiPKc
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	call	__Z29testOpt07_Type2_strlen_BeforeiPKc
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strlen_BeforeiPKc
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strlen_BeforeiPKc
	cmpl	$1000000, %ebx
	jne	L168
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 80(%esp)
	addl	$60, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2817:
	.p2align 4,,15
	.globl	__Z31runTestOpt07_Type2_strlen_AfterPKcS0_S0_S0_S0_
	.def	__Z31runTestOpt07_Type2_strlen_AfterPKcS0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
__Z31runTestOpt07_Type2_strlen_AfterPKcS0_S0_S0_S0_:
LFB2818:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	92(%esp), %eax
	movl	$LC16, (%esp)
	movl	80(%esp), %ebp
	movl	84(%esp), %edi
	movl	88(%esp), %esi
	movl	%eax, 24(%esp)
	movl	96(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L172:
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	call	__Z28testOpt07_Type2_strlen_AfteriPKc
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	call	__Z28testOpt07_Type2_strlen_AfteriPKc
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	call	__Z28testOpt07_Type2_strlen_AfteriPKc
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strlen_AfteriPKc
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strlen_AfteriPKc
	cmpl	$1000000, %ebx
	jne	L172
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 80(%esp)
	addl	$60, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2818:
	.section .rdata,"dr"
LC50:
	.ascii "Type2(strcmp):\0"
LC51:
	.ascii "123!\0"
LC52:
	.ascii "1234567890abcdef!\0"
	.align 4
LC53:
	.ascii "1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_!\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt07_Type2_strcmpv
	.def	__Z25runTestOpt07_Type2_strcmpv;	.scl	2;	.type	32;	.endef
__Z25runTestOpt07_Type2_strcmpv:
LFB2819:
	.cfi_startproc
	subl	$92, %esp
	.cfi_def_cfa_offset 96
	movl	$LC50, (%esp)
	call	_puts
	movl	$LC45, 76(%esp)
	movl	$LC45, 72(%esp)
	movl	$LC46, 68(%esp)
	movl	$LC51, 64(%esp)
	movl	$LC51, 60(%esp)
	movl	$LC46, 56(%esp)
	movl	$LC46, 52(%esp)
	movl	$LC46, 48(%esp)
	movl	$LC47, 44(%esp)
	movl	$LC52, 40(%esp)
	movl	$LC52, 36(%esp)
	movl	$LC47, 32(%esp)
	movl	$LC47, 28(%esp)
	movl	$LC47, 24(%esp)
	movl	$LC49, 20(%esp)
	movl	$LC53, 16(%esp)
	movl	$LC53, 12(%esp)
	movl	$LC49, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z32runTestOpt07_Type2_strcmp_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	movl	$LC45, 76(%esp)
	movl	$LC45, 72(%esp)
	movl	$LC46, 68(%esp)
	movl	$LC51, 64(%esp)
	movl	$LC51, 60(%esp)
	movl	$LC46, 56(%esp)
	movl	$LC46, 52(%esp)
	movl	$LC46, 48(%esp)
	movl	$LC47, 44(%esp)
	movl	$LC52, 40(%esp)
	movl	$LC52, 36(%esp)
	movl	$LC47, 32(%esp)
	movl	$LC47, 28(%esp)
	movl	$LC47, 24(%esp)
	movl	$LC49, 20(%esp)
	movl	$LC53, 16(%esp)
	movl	$LC53, 12(%esp)
	movl	$LC49, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z31runTestOpt07_Type2_strcmp_AfterPKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	addl	$92, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2819:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strcmp_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	.def	__Z32runTestOpt07_Type2_strcmp_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strcmp_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_:
LFB2820:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$108, %esp
	.cfi_def_cfa_offset 128
	movl	128(%esp), %eax
	movl	%eax, 12(%esp)
	movl	132(%esp), %eax
	movl	%eax, 16(%esp)
	movl	136(%esp), %eax
	movl	%eax, 20(%esp)
	movl	140(%esp), %eax
	movl	%eax, 24(%esp)
	movl	144(%esp), %eax
	movl	%eax, 28(%esp)
	movl	148(%esp), %eax
	movl	%eax, 32(%esp)
	movl	152(%esp), %eax
	movl	%eax, 36(%esp)
	movl	156(%esp), %eax
	movl	%eax, 40(%esp)
	movl	160(%esp), %eax
	movl	%eax, 44(%esp)
	movl	164(%esp), %eax
	movl	%eax, 48(%esp)
	movl	168(%esp), %eax
	movl	%eax, 52(%esp)
	movl	172(%esp), %eax
	movl	%eax, 56(%esp)
	movl	176(%esp), %eax
	movl	%eax, 60(%esp)
	movl	180(%esp), %eax
	movl	%eax, 64(%esp)
	movl	184(%esp), %eax
	movl	%eax, 68(%esp)
	movl	188(%esp), %eax
	movl	$LC6, (%esp)
	movl	192(%esp), %ebp
	movl	200(%esp), %edi
	movl	204(%esp), %esi
	movl	%eax, 72(%esp)
	movl	196(%esp), %eax
	movl	%eax, 76(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 80(%esp)
	movl	%edx, 84(%esp)
	.p2align 4,,7
L178:
	movl	16(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	12(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	36(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	44(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	52(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	60(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	68(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	call	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_
	cmpl	$1000000, %ebx
	jne	L178
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	80(%esp), %eax
	sbbl	84(%esp), %edx
	movl	%eax, 88(%esp)
	movl	%edx, 92(%esp)
	fildq	88(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 128(%esp)
	addl	$108, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2820:
	.p2align 4,,15
	.globl	__Z31runTestOpt07_Type2_strcmp_AfterPKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	.def	__Z31runTestOpt07_Type2_strcmp_AfterPKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
__Z31runTestOpt07_Type2_strcmp_AfterPKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_:
LFB2821:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$108, %esp
	.cfi_def_cfa_offset 128
	movl	128(%esp), %eax
	movl	%eax, 12(%esp)
	movl	132(%esp), %eax
	movl	%eax, 16(%esp)
	movl	136(%esp), %eax
	movl	%eax, 20(%esp)
	movl	140(%esp), %eax
	movl	%eax, 24(%esp)
	movl	144(%esp), %eax
	movl	%eax, 28(%esp)
	movl	148(%esp), %eax
	movl	%eax, 32(%esp)
	movl	152(%esp), %eax
	movl	%eax, 36(%esp)
	movl	156(%esp), %eax
	movl	%eax, 40(%esp)
	movl	160(%esp), %eax
	movl	%eax, 44(%esp)
	movl	164(%esp), %eax
	movl	%eax, 48(%esp)
	movl	168(%esp), %eax
	movl	%eax, 52(%esp)
	movl	172(%esp), %eax
	movl	%eax, 56(%esp)
	movl	176(%esp), %eax
	movl	%eax, 60(%esp)
	movl	180(%esp), %eax
	movl	%eax, 64(%esp)
	movl	184(%esp), %eax
	movl	%eax, 68(%esp)
	movl	188(%esp), %eax
	movl	$LC16, (%esp)
	movl	192(%esp), %ebp
	movl	200(%esp), %edi
	movl	204(%esp), %esi
	movl	%eax, 72(%esp)
	movl	196(%esp), %eax
	movl	%eax, 76(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 80(%esp)
	movl	%edx, 84(%esp)
	.p2align 4,,7
L182:
	movl	16(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	12(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	36(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	44(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	52(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	60(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	68(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	call	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_
	cmpl	$1000000, %ebx
	jne	L182
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	80(%esp), %eax
	sbbl	84(%esp), %edx
	movl	%eax, 88(%esp)
	movl	%edx, 92(%esp)
	fildq	88(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 128(%esp)
	addl	$108, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2821:
	.section .rdata,"dr"
LC54:
	.ascii "Type2(strncmp):\0"
	.text
	.p2align 4,,15
	.globl	__Z26runTestOpt07_Type2_strncmpv
	.def	__Z26runTestOpt07_Type2_strncmpv;	.scl	2;	.type	32;	.endef
__Z26runTestOpt07_Type2_strncmpv:
LFB2822:
	.cfi_startproc
	subl	$220, %esp
	.cfi_def_cfa_offset 224
	movl	$LC54, (%esp)
	call	_puts
	movl	$0, 196(%esp)
	movl	$1, 192(%esp)
	movl	$2, 188(%esp)
	movl	$LC45, 184(%esp)
	movl	$LC45, 180(%esp)
	movl	$2, 176(%esp)
	movl	$3, 172(%esp)
	movl	$4, 168(%esp)
	movl	$LC46, 164(%esp)
	movl	$LC51, 160(%esp)
	movl	$2, 156(%esp)
	movl	$3, 152(%esp)
	movl	$4, 148(%esp)
	movl	$LC51, 144(%esp)
	movl	$LC46, 140(%esp)
	movl	$2, 136(%esp)
	movl	$3, 132(%esp)
	movl	$4, 128(%esp)
	movl	$LC46, 124(%esp)
	movl	$LC46, 120(%esp)
	movl	$15, 116(%esp)
	movl	$16, 112(%esp)
	movl	$17, 108(%esp)
	movl	$LC47, 104(%esp)
	movl	$LC52, 100(%esp)
	movl	$15, 96(%esp)
	movl	$16, 92(%esp)
	movl	$17, 88(%esp)
	movl	$LC52, 84(%esp)
	movl	$LC47, 80(%esp)
	movl	$15, 76(%esp)
	movl	$16, 72(%esp)
	movl	$17, 68(%esp)
	movl	$LC47, 64(%esp)
	movl	$LC47, 60(%esp)
	movl	$169, 56(%esp)
	movl	$170, 52(%esp)
	movl	$171, 48(%esp)
	movl	$LC49, 44(%esp)
	movl	$LC53, 40(%esp)
	movl	$169, 36(%esp)
	movl	$170, 32(%esp)
	movl	$171, 28(%esp)
	movl	$LC53, 24(%esp)
	movl	$LC49, 20(%esp)
	movl	$169, 16(%esp)
	movl	$170, 12(%esp)
	movl	$171, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z33runTestOpt07_Type2_strncmp_BeforePKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj
	movl	$0, 196(%esp)
	movl	$1, 192(%esp)
	movl	$2, 188(%esp)
	movl	$LC45, 184(%esp)
	movl	$LC45, 180(%esp)
	movl	$2, 176(%esp)
	movl	$3, 172(%esp)
	movl	$4, 168(%esp)
	movl	$LC46, 164(%esp)
	movl	$LC51, 160(%esp)
	movl	$2, 156(%esp)
	movl	$3, 152(%esp)
	movl	$4, 148(%esp)
	movl	$LC51, 144(%esp)
	movl	$LC46, 140(%esp)
	movl	$2, 136(%esp)
	movl	$3, 132(%esp)
	movl	$4, 128(%esp)
	movl	$LC46, 124(%esp)
	movl	$LC46, 120(%esp)
	movl	$15, 116(%esp)
	movl	$16, 112(%esp)
	movl	$17, 108(%esp)
	movl	$LC47, 104(%esp)
	movl	$LC52, 100(%esp)
	movl	$15, 96(%esp)
	movl	$16, 92(%esp)
	movl	$17, 88(%esp)
	movl	$LC52, 84(%esp)
	movl	$LC47, 80(%esp)
	movl	$15, 76(%esp)
	movl	$16, 72(%esp)
	movl	$17, 68(%esp)
	movl	$LC47, 64(%esp)
	movl	$LC47, 60(%esp)
	movl	$169, 56(%esp)
	movl	$170, 52(%esp)
	movl	$171, 48(%esp)
	movl	$LC49, 44(%esp)
	movl	$LC53, 40(%esp)
	movl	$169, 36(%esp)
	movl	$170, 32(%esp)
	movl	$171, 28(%esp)
	movl	$LC53, 24(%esp)
	movl	$LC49, 20(%esp)
	movl	$169, 16(%esp)
	movl	$170, 12(%esp)
	movl	$171, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z32runTestOpt07_Type2_strncmp_AfterPKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj
	addl	$220, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2822:
	.p2align 4,,15
	.globl	__Z33runTestOpt07_Type2_strncmp_BeforePKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj
	.def	__Z33runTestOpt07_Type2_strncmp_BeforePKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj;	.scl	2;	.type	32;	.endef
__Z33runTestOpt07_Type2_strncmp_BeforePKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj:
LFB2823:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$236, %esp
	.cfi_def_cfa_offset 256
	movl	256(%esp), %eax
	movl	%eax, 20(%esp)
	movl	260(%esp), %eax
	movl	%eax, 24(%esp)
	movl	264(%esp), %eax
	movl	%eax, 88(%esp)
	movl	268(%esp), %eax
	movl	%eax, 92(%esp)
	movl	272(%esp), %eax
	movl	%eax, 96(%esp)
	movl	276(%esp), %eax
	movl	%eax, 28(%esp)
	movl	280(%esp), %eax
	movl	%eax, 32(%esp)
	movl	284(%esp), %eax
	movl	%eax, 100(%esp)
	movl	288(%esp), %eax
	movl	%eax, 104(%esp)
	movl	292(%esp), %eax
	movl	%eax, 108(%esp)
	movl	296(%esp), %eax
	movl	%eax, 36(%esp)
	movl	300(%esp), %eax
	movl	%eax, 40(%esp)
	movl	304(%esp), %eax
	movl	%eax, 112(%esp)
	movl	308(%esp), %eax
	movl	%eax, 116(%esp)
	movl	312(%esp), %eax
	movl	%eax, 120(%esp)
	movl	316(%esp), %eax
	movl	%eax, 44(%esp)
	movl	320(%esp), %eax
	movl	%eax, 48(%esp)
	movl	324(%esp), %eax
	movl	%eax, 124(%esp)
	movl	328(%esp), %eax
	movl	%eax, 128(%esp)
	movl	332(%esp), %eax
	movl	%eax, 132(%esp)
	movl	336(%esp), %eax
	movl	%eax, 52(%esp)
	movl	340(%esp), %eax
	movl	%eax, 56(%esp)
	movl	344(%esp), %eax
	movl	%eax, 136(%esp)
	movl	348(%esp), %eax
	movl	%eax, 140(%esp)
	movl	352(%esp), %eax
	movl	%eax, 144(%esp)
	movl	356(%esp), %eax
	movl	%eax, 60(%esp)
	movl	360(%esp), %eax
	movl	%eax, 64(%esp)
	movl	364(%esp), %eax
	movl	%eax, 148(%esp)
	movl	368(%esp), %eax
	movl	%eax, 152(%esp)
	movl	372(%esp), %eax
	movl	%eax, 156(%esp)
	movl	376(%esp), %eax
	movl	%eax, 68(%esp)
	movl	380(%esp), %eax
	movl	%eax, 72(%esp)
	movl	384(%esp), %eax
	movl	416(%esp), %ebp
	movl	436(%esp), %edi
	movl	440(%esp), %esi
	movl	%eax, 160(%esp)
	movl	388(%esp), %eax
	movl	%eax, 164(%esp)
	movl	392(%esp), %eax
	movl	%eax, 168(%esp)
	movl	396(%esp), %eax
	movl	%eax, 76(%esp)
	movl	400(%esp), %eax
	movl	%eax, 80(%esp)
	movl	404(%esp), %eax
	movl	%eax, 172(%esp)
	movl	408(%esp), %eax
	movl	%eax, 176(%esp)
	movl	412(%esp), %eax
	movl	%eax, 180(%esp)
	movl	420(%esp), %eax
	movl	%eax, 84(%esp)
	movl	424(%esp), %eax
	movl	%eax, 184(%esp)
	movl	428(%esp), %eax
	movl	%eax, 188(%esp)
	movl	432(%esp), %eax
	movl	%eax, 192(%esp)
	movl	444(%esp), %eax
	movl	%eax, 196(%esp)
	movl	448(%esp), %eax
	movl	%eax, 200(%esp)
	movl	452(%esp), %eax
	movl	%eax, 204(%esp)
	movl	$LC6, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 208(%esp)
	movl	%edx, 212(%esp)
	.p2align 4,,7
L188:
	movl	88(%esp), %eax
	movl	20(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	24(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	92(%esp), %ecx
	movl	20(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	20(%esp), %edx
	movl	96(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	100(%esp), %eax
	movl	28(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	32(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	104(%esp), %edx
	movl	28(%esp), %ecx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	28(%esp), %ecx
	movl	108(%esp), %edx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	112(%esp), %eax
	movl	36(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	40(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	116(%esp), %ecx
	movl	36(%esp), %edx
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	36(%esp), %edx
	movl	120(%esp), %ecx
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	124(%esp), %eax
	movl	44(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	48(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	128(%esp), %edx
	movl	44(%esp), %ecx
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	44(%esp), %ecx
	movl	132(%esp), %edx
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	136(%esp), %eax
	movl	52(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	56(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	140(%esp), %ecx
	movl	52(%esp), %edx
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	52(%esp), %edx
	movl	144(%esp), %ecx
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	148(%esp), %eax
	movl	60(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	64(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	152(%esp), %edx
	movl	60(%esp), %ecx
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	60(%esp), %ecx
	movl	156(%esp), %edx
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	160(%esp), %eax
	movl	68(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	72(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	164(%esp), %ecx
	movl	68(%esp), %edx
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	68(%esp), %edx
	movl	168(%esp), %ecx
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	172(%esp), %eax
	movl	76(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	80(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	176(%esp), %edx
	movl	76(%esp), %ecx
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	76(%esp), %ecx
	movl	180(%esp), %edx
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	184(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 12(%esp)
	movl	84(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	188(%esp), %edx
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	192(%esp), %ecx
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	196(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	200(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	movl	204(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j
	cmpl	$1000000, %ebx
	jne	L188
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	208(%esp), %eax
	sbbl	212(%esp), %edx
	movl	%eax, 216(%esp)
	movl	%edx, 220(%esp)
	fildq	216(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 256(%esp)
	addl	$236, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2823:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strncmp_AfterPKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj
	.def	__Z32runTestOpt07_Type2_strncmp_AfterPKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strncmp_AfterPKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj:
LFB2824:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$236, %esp
	.cfi_def_cfa_offset 256
	movl	256(%esp), %eax
	movl	%eax, 20(%esp)
	movl	260(%esp), %eax
	movl	%eax, 24(%esp)
	movl	264(%esp), %eax
	movl	%eax, 88(%esp)
	movl	268(%esp), %eax
	movl	%eax, 92(%esp)
	movl	272(%esp), %eax
	movl	%eax, 96(%esp)
	movl	276(%esp), %eax
	movl	%eax, 28(%esp)
	movl	280(%esp), %eax
	movl	%eax, 32(%esp)
	movl	284(%esp), %eax
	movl	%eax, 100(%esp)
	movl	288(%esp), %eax
	movl	%eax, 104(%esp)
	movl	292(%esp), %eax
	movl	%eax, 108(%esp)
	movl	296(%esp), %eax
	movl	%eax, 36(%esp)
	movl	300(%esp), %eax
	movl	%eax, 40(%esp)
	movl	304(%esp), %eax
	movl	%eax, 112(%esp)
	movl	308(%esp), %eax
	movl	%eax, 116(%esp)
	movl	312(%esp), %eax
	movl	%eax, 120(%esp)
	movl	316(%esp), %eax
	movl	%eax, 44(%esp)
	movl	320(%esp), %eax
	movl	%eax, 48(%esp)
	movl	324(%esp), %eax
	movl	%eax, 124(%esp)
	movl	328(%esp), %eax
	movl	%eax, 128(%esp)
	movl	332(%esp), %eax
	movl	%eax, 132(%esp)
	movl	336(%esp), %eax
	movl	%eax, 52(%esp)
	movl	340(%esp), %eax
	movl	%eax, 56(%esp)
	movl	344(%esp), %eax
	movl	%eax, 136(%esp)
	movl	348(%esp), %eax
	movl	%eax, 140(%esp)
	movl	352(%esp), %eax
	movl	%eax, 144(%esp)
	movl	356(%esp), %eax
	movl	%eax, 60(%esp)
	movl	360(%esp), %eax
	movl	%eax, 64(%esp)
	movl	364(%esp), %eax
	movl	%eax, 148(%esp)
	movl	368(%esp), %eax
	movl	%eax, 152(%esp)
	movl	372(%esp), %eax
	movl	%eax, 156(%esp)
	movl	376(%esp), %eax
	movl	%eax, 68(%esp)
	movl	380(%esp), %eax
	movl	%eax, 72(%esp)
	movl	384(%esp), %eax
	movl	416(%esp), %ebp
	movl	436(%esp), %edi
	movl	440(%esp), %esi
	movl	%eax, 160(%esp)
	movl	388(%esp), %eax
	movl	%eax, 164(%esp)
	movl	392(%esp), %eax
	movl	%eax, 168(%esp)
	movl	396(%esp), %eax
	movl	%eax, 76(%esp)
	movl	400(%esp), %eax
	movl	%eax, 80(%esp)
	movl	404(%esp), %eax
	movl	%eax, 172(%esp)
	movl	408(%esp), %eax
	movl	%eax, 176(%esp)
	movl	412(%esp), %eax
	movl	%eax, 180(%esp)
	movl	420(%esp), %eax
	movl	%eax, 84(%esp)
	movl	424(%esp), %eax
	movl	%eax, 184(%esp)
	movl	428(%esp), %eax
	movl	%eax, 188(%esp)
	movl	432(%esp), %eax
	movl	%eax, 192(%esp)
	movl	444(%esp), %eax
	movl	%eax, 196(%esp)
	movl	448(%esp), %eax
	movl	%eax, 200(%esp)
	movl	452(%esp), %eax
	movl	%eax, 204(%esp)
	movl	$LC16, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 208(%esp)
	movl	%edx, 212(%esp)
	.p2align 4,,7
L192:
	movl	88(%esp), %eax
	movl	20(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	24(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	92(%esp), %ecx
	movl	20(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	20(%esp), %edx
	movl	96(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	100(%esp), %eax
	movl	28(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	32(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	104(%esp), %edx
	movl	28(%esp), %ecx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	28(%esp), %ecx
	movl	108(%esp), %edx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	112(%esp), %eax
	movl	36(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	40(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	116(%esp), %ecx
	movl	36(%esp), %edx
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	36(%esp), %edx
	movl	120(%esp), %ecx
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	124(%esp), %eax
	movl	44(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	48(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	128(%esp), %edx
	movl	44(%esp), %ecx
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	44(%esp), %ecx
	movl	132(%esp), %edx
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	136(%esp), %eax
	movl	52(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	56(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	140(%esp), %ecx
	movl	52(%esp), %edx
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	52(%esp), %edx
	movl	144(%esp), %ecx
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	148(%esp), %eax
	movl	60(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	64(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	152(%esp), %edx
	movl	60(%esp), %ecx
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	60(%esp), %ecx
	movl	156(%esp), %edx
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	160(%esp), %eax
	movl	68(%esp), %edx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	72(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	164(%esp), %ecx
	movl	68(%esp), %edx
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	68(%esp), %edx
	movl	168(%esp), %ecx
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	172(%esp), %eax
	movl	76(%esp), %ecx
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	80(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	176(%esp), %edx
	movl	76(%esp), %ecx
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 12(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	76(%esp), %ecx
	movl	180(%esp), %edx
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	184(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 12(%esp)
	movl	84(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	188(%esp), %edx
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	192(%esp), %ecx
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	196(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	200(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	movl	204(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j
	cmpl	$1000000, %ebx
	jne	L192
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	208(%esp), %eax
	sbbl	212(%esp), %edx
	movl	%eax, 216(%esp)
	movl	%edx, 220(%esp)
	fildq	216(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 256(%esp)
	addl	$236, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2824:
	.section .rdata,"dr"
LC55:
	.ascii "Type2(strchr):\0"
LC56:
	.ascii "123123\0"
LC57:
	.ascii "1234567812345678\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt07_Type2_strchrv
	.def	__Z25runTestOpt07_Type2_strchrv;	.scl	2;	.type	32;	.endef
__Z25runTestOpt07_Type2_strchrv:
LFB2825:
	.cfi_startproc
	subl	$92, %esp
	.cfi_def_cfa_offset 96
	movl	$LC55, (%esp)
	call	_puts
	movl	$46, 76(%esp)
	movl	$51, 72(%esp)
	movl	$50, 68(%esp)
	movl	$49, 64(%esp)
	movl	$LC45, 60(%esp)
	movl	$46, 56(%esp)
	movl	$51, 52(%esp)
	movl	$50, 48(%esp)
	movl	$49, 44(%esp)
	movl	$LC56, 40(%esp)
	movl	$46, 36(%esp)
	movl	$56, 32(%esp)
	movl	$53, 28(%esp)
	movl	$49, 24(%esp)
	movl	$LC57, 20(%esp)
	movl	$46, 16(%esp)
	movl	$95, 12(%esp)
	movl	$33, 8(%esp)
	movl	$49, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z32runTestOpt07_Type2_strchr_BeforePKcccccS0_ccccS0_ccccS0_cccc
	movl	$46, 76(%esp)
	movl	$51, 72(%esp)
	movl	$50, 68(%esp)
	movl	$49, 64(%esp)
	movl	$LC45, 60(%esp)
	movl	$46, 56(%esp)
	movl	$51, 52(%esp)
	movl	$50, 48(%esp)
	movl	$49, 44(%esp)
	movl	$LC56, 40(%esp)
	movl	$46, 36(%esp)
	movl	$56, 32(%esp)
	movl	$53, 28(%esp)
	movl	$49, 24(%esp)
	movl	$LC57, 20(%esp)
	movl	$46, 16(%esp)
	movl	$95, 12(%esp)
	movl	$33, 8(%esp)
	movl	$49, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z31runTestOpt07_Type2_strchr_AfterPKcccccS0_ccccS0_ccccS0_cccc
	addl	$92, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2825:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strchr_BeforePKcccccS0_ccccS0_ccccS0_cccc
	.def	__Z32runTestOpt07_Type2_strchr_BeforePKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strchr_BeforePKcccccS0_ccccS0_ccccS0_cccc:
LFB2826:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$124, %esp
	.cfi_def_cfa_offset 144
	movl	152(%esp), %eax
	movl	156(%esp), %ecx
	movl	160(%esp), %edx
	movl	164(%esp), %esi
	movl	%eax, 32(%esp)
	movl	176(%esp), %eax
	movl	%ecx, 40(%esp)
	movl	180(%esp), %ecx
	movl	%edx, 44(%esp)
	movl	188(%esp), %edx
	movl	%esi, 24(%esp)
	movl	172(%esp), %esi
	movl	168(%esp), %edi
	movl	%eax, 56(%esp)
	movl	196(%esp), %eax
	movl	%ecx, 60(%esp)
	movl	200(%esp), %ecx
	movl	%esi, 52(%esp)
	movl	192(%esp), %esi
	movl	%edx, 64(%esp)
	movl	208(%esp), %edx
	movl	148(%esp), %ebx
	movl	%edi, 48(%esp)
	movl	144(%esp), %ebp
	movl	%esi, 68(%esp)
	movl	184(%esp), %edi
	movl	%eax, 72(%esp)
	movl	204(%esp), %esi
	movl	%ecx, 76(%esp)
	movsbl	%bl, %ebx
	movl	%edx, 80(%esp)
	movl	216(%esp), %ecx
	movl	220(%esp), %edx
	movl	212(%esp), %eax
	movl	$LC6, (%esp)
	movl	%ecx, 96(%esp)
	movl	%edx, 100(%esp)
	movl	%eax, 84(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%ebx, 28(%esp)
	movsbl	32(%esp), %ebx
	movl	%ebx, 36(%esp)
	movsbl	40(%esp), %ebx
	movl	%eax, 88(%esp)
	movsbl	84(%esp), %eax
	movl	%edx, 92(%esp)
	movl	%ebx, 40(%esp)
	movsbl	44(%esp), %ebx
	movl	%ebx, 32(%esp)
	movsbl	48(%esp), %ebx
	movl	%ebx, 44(%esp)
	movsbl	52(%esp), %ebx
	movl	%ebx, 48(%esp)
	movsbl	56(%esp), %ebx
	movl	%ebx, 52(%esp)
	movsbl	60(%esp), %ebx
	movl	%ebx, 56(%esp)
	movsbl	64(%esp), %ebx
	movl	%ebx, 60(%esp)
	movsbl	68(%esp), %ebx
	movl	%ebx, 64(%esp)
	movsbl	72(%esp), %ebx
	movl	%ebx, 68(%esp)
	movsbl	76(%esp), %ebx
	movl	%ebx, 72(%esp)
	movsbl	80(%esp), %ebx
	movl	%eax, 80(%esp)
	movsbl	96(%esp), %eax
	movl	%ebx, 76(%esp)
	xorl	%ebx, %ebx
	movl	%eax, 84(%esp)
	movsbl	100(%esp), %eax
	movl	%eax, 96(%esp)
	.p2align 4,,7
L198:
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	44(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	48(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	52(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	56(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	68(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	movl	96(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strchr_BeforeiPKcc
	cmpl	$1000000, %ebx
	jne	L198
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	88(%esp), %eax
	sbbl	92(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 144(%esp)
	addl	$124, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2826:
	.p2align 4,,15
	.globl	__Z31runTestOpt07_Type2_strchr_AfterPKcccccS0_ccccS0_ccccS0_cccc
	.def	__Z31runTestOpt07_Type2_strchr_AfterPKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
__Z31runTestOpt07_Type2_strchr_AfterPKcccccS0_ccccS0_ccccS0_cccc:
LFB2827:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$124, %esp
	.cfi_def_cfa_offset 144
	movl	152(%esp), %eax
	movl	156(%esp), %ecx
	movl	160(%esp), %edx
	movl	164(%esp), %esi
	movl	%eax, 32(%esp)
	movl	176(%esp), %eax
	movl	%ecx, 40(%esp)
	movl	180(%esp), %ecx
	movl	%edx, 44(%esp)
	movl	188(%esp), %edx
	movl	%esi, 24(%esp)
	movl	172(%esp), %esi
	movl	168(%esp), %edi
	movl	%eax, 56(%esp)
	movl	196(%esp), %eax
	movl	%ecx, 60(%esp)
	movl	200(%esp), %ecx
	movl	%esi, 52(%esp)
	movl	192(%esp), %esi
	movl	%edx, 64(%esp)
	movl	208(%esp), %edx
	movl	148(%esp), %ebx
	movl	%edi, 48(%esp)
	movl	144(%esp), %ebp
	movl	%esi, 68(%esp)
	movl	184(%esp), %edi
	movl	%eax, 72(%esp)
	movl	204(%esp), %esi
	movl	%ecx, 76(%esp)
	movsbl	%bl, %ebx
	movl	%edx, 80(%esp)
	movl	216(%esp), %ecx
	movl	220(%esp), %edx
	movl	212(%esp), %eax
	movl	$LC16, (%esp)
	movl	%ecx, 96(%esp)
	movl	%edx, 100(%esp)
	movl	%eax, 84(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%ebx, 28(%esp)
	movsbl	32(%esp), %ebx
	movl	%ebx, 36(%esp)
	movsbl	40(%esp), %ebx
	movl	%eax, 88(%esp)
	movsbl	84(%esp), %eax
	movl	%edx, 92(%esp)
	movl	%ebx, 40(%esp)
	movsbl	44(%esp), %ebx
	movl	%ebx, 32(%esp)
	movsbl	48(%esp), %ebx
	movl	%ebx, 44(%esp)
	movsbl	52(%esp), %ebx
	movl	%ebx, 48(%esp)
	movsbl	56(%esp), %ebx
	movl	%ebx, 52(%esp)
	movsbl	60(%esp), %ebx
	movl	%ebx, 56(%esp)
	movsbl	64(%esp), %ebx
	movl	%ebx, 60(%esp)
	movsbl	68(%esp), %ebx
	movl	%ebx, 64(%esp)
	movsbl	72(%esp), %ebx
	movl	%ebx, 68(%esp)
	movsbl	76(%esp), %ebx
	movl	%ebx, 72(%esp)
	movsbl	80(%esp), %ebx
	movl	%eax, 80(%esp)
	movsbl	96(%esp), %eax
	movl	%ebx, 76(%esp)
	xorl	%ebx, %ebx
	movl	%eax, 84(%esp)
	movsbl	100(%esp), %eax
	movl	%eax, 96(%esp)
	.p2align 4,,7
L202:
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	44(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	48(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	52(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	56(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	68(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	movl	96(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strchr_AfteriPKcc
	cmpl	$1000000, %ebx
	jne	L202
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	88(%esp), %eax
	sbbl	92(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 144(%esp)
	addl	$124, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2827:
	.section .rdata,"dr"
LC58:
	.ascii "Type2(strrchr):\0"
	.text
	.p2align 4,,15
	.globl	__Z26runTestOpt07_Type2_strrchrv
	.def	__Z26runTestOpt07_Type2_strrchrv;	.scl	2;	.type	32;	.endef
__Z26runTestOpt07_Type2_strrchrv:
LFB2828:
	.cfi_startproc
	subl	$92, %esp
	.cfi_def_cfa_offset 96
	movl	$LC58, (%esp)
	call	_puts
	movl	$46, 76(%esp)
	movl	$51, 72(%esp)
	movl	$50, 68(%esp)
	movl	$49, 64(%esp)
	movl	$LC45, 60(%esp)
	movl	$46, 56(%esp)
	movl	$51, 52(%esp)
	movl	$50, 48(%esp)
	movl	$49, 44(%esp)
	movl	$LC56, 40(%esp)
	movl	$46, 36(%esp)
	movl	$56, 32(%esp)
	movl	$53, 28(%esp)
	movl	$49, 24(%esp)
	movl	$LC57, 20(%esp)
	movl	$46, 16(%esp)
	movl	$95, 12(%esp)
	movl	$33, 8(%esp)
	movl	$49, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z33runTestOpt07_Type2_strrchr_BeforePKcccccS0_ccccS0_ccccS0_cccc
	movl	$46, 76(%esp)
	movl	$51, 72(%esp)
	movl	$50, 68(%esp)
	movl	$49, 64(%esp)
	movl	$LC45, 60(%esp)
	movl	$46, 56(%esp)
	movl	$51, 52(%esp)
	movl	$50, 48(%esp)
	movl	$49, 44(%esp)
	movl	$LC56, 40(%esp)
	movl	$46, 36(%esp)
	movl	$56, 32(%esp)
	movl	$53, 28(%esp)
	movl	$49, 24(%esp)
	movl	$LC57, 20(%esp)
	movl	$46, 16(%esp)
	movl	$95, 12(%esp)
	movl	$33, 8(%esp)
	movl	$49, 4(%esp)
	movl	$LC49, (%esp)
	call	__Z32runTestOpt07_Type2_strrchr_AfterPKcccccS0_ccccS0_ccccS0_cccc
	addl	$92, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2828:
	.p2align 4,,15
	.globl	__Z33runTestOpt07_Type2_strrchr_BeforePKcccccS0_ccccS0_ccccS0_cccc
	.def	__Z33runTestOpt07_Type2_strrchr_BeforePKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
__Z33runTestOpt07_Type2_strrchr_BeforePKcccccS0_ccccS0_ccccS0_cccc:
LFB2829:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$124, %esp
	.cfi_def_cfa_offset 144
	movl	152(%esp), %eax
	movl	156(%esp), %ecx
	movl	160(%esp), %edx
	movl	164(%esp), %esi
	movl	%eax, 32(%esp)
	movl	176(%esp), %eax
	movl	%ecx, 40(%esp)
	movl	180(%esp), %ecx
	movl	%edx, 44(%esp)
	movl	188(%esp), %edx
	movl	%esi, 24(%esp)
	movl	172(%esp), %esi
	movl	168(%esp), %edi
	movl	%eax, 56(%esp)
	movl	196(%esp), %eax
	movl	%ecx, 60(%esp)
	movl	200(%esp), %ecx
	movl	%esi, 52(%esp)
	movl	192(%esp), %esi
	movl	%edx, 64(%esp)
	movl	208(%esp), %edx
	movl	148(%esp), %ebx
	movl	%edi, 48(%esp)
	movl	144(%esp), %ebp
	movl	%esi, 68(%esp)
	movl	184(%esp), %edi
	movl	%eax, 72(%esp)
	movl	204(%esp), %esi
	movl	%ecx, 76(%esp)
	movsbl	%bl, %ebx
	movl	%edx, 80(%esp)
	movl	216(%esp), %ecx
	movl	220(%esp), %edx
	movl	212(%esp), %eax
	movl	$LC6, (%esp)
	movl	%ecx, 96(%esp)
	movl	%edx, 100(%esp)
	movl	%eax, 84(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%ebx, 28(%esp)
	movsbl	32(%esp), %ebx
	movl	%ebx, 36(%esp)
	movsbl	40(%esp), %ebx
	movl	%eax, 88(%esp)
	movsbl	84(%esp), %eax
	movl	%edx, 92(%esp)
	movl	%ebx, 40(%esp)
	movsbl	44(%esp), %ebx
	movl	%ebx, 32(%esp)
	movsbl	48(%esp), %ebx
	movl	%ebx, 44(%esp)
	movsbl	52(%esp), %ebx
	movl	%ebx, 48(%esp)
	movsbl	56(%esp), %ebx
	movl	%ebx, 52(%esp)
	movsbl	60(%esp), %ebx
	movl	%ebx, 56(%esp)
	movsbl	64(%esp), %ebx
	movl	%ebx, 60(%esp)
	movsbl	68(%esp), %ebx
	movl	%ebx, 64(%esp)
	movsbl	72(%esp), %ebx
	movl	%ebx, 68(%esp)
	movsbl	76(%esp), %ebx
	movl	%ebx, 72(%esp)
	movsbl	80(%esp), %ebx
	movl	%eax, 80(%esp)
	movsbl	96(%esp), %eax
	movl	%ebx, 76(%esp)
	xorl	%ebx, %ebx
	movl	%eax, 84(%esp)
	movsbl	100(%esp), %eax
	movl	%eax, 96(%esp)
	.p2align 4,,7
L208:
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	44(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	48(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	52(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	56(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	68(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	movl	96(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strrchr_BeforeiPKcc
	cmpl	$1000000, %ebx
	jne	L208
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	88(%esp), %eax
	sbbl	92(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 144(%esp)
	addl	$124, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2829:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strrchr_AfterPKcccccS0_ccccS0_ccccS0_cccc
	.def	__Z32runTestOpt07_Type2_strrchr_AfterPKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strrchr_AfterPKcccccS0_ccccS0_ccccS0_cccc:
LFB2830:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$124, %esp
	.cfi_def_cfa_offset 144
	movl	152(%esp), %eax
	movl	156(%esp), %ecx
	movl	160(%esp), %edx
	movl	164(%esp), %esi
	movl	%eax, 32(%esp)
	movl	176(%esp), %eax
	movl	%ecx, 40(%esp)
	movl	180(%esp), %ecx
	movl	%edx, 44(%esp)
	movl	188(%esp), %edx
	movl	%esi, 24(%esp)
	movl	172(%esp), %esi
	movl	168(%esp), %edi
	movl	%eax, 56(%esp)
	movl	196(%esp), %eax
	movl	%ecx, 60(%esp)
	movl	200(%esp), %ecx
	movl	%esi, 52(%esp)
	movl	192(%esp), %esi
	movl	%edx, 64(%esp)
	movl	208(%esp), %edx
	movl	148(%esp), %ebx
	movl	%edi, 48(%esp)
	movl	144(%esp), %ebp
	movl	%esi, 68(%esp)
	movl	184(%esp), %edi
	movl	%eax, 72(%esp)
	movl	204(%esp), %esi
	movl	%ecx, 76(%esp)
	movsbl	%bl, %ebx
	movl	%edx, 80(%esp)
	movl	216(%esp), %ecx
	movl	220(%esp), %edx
	movl	212(%esp), %eax
	movl	$LC16, (%esp)
	movl	%ecx, 96(%esp)
	movl	%edx, 100(%esp)
	movl	%eax, 84(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%ebx, 28(%esp)
	movsbl	32(%esp), %ebx
	movl	%ebx, 36(%esp)
	movsbl	40(%esp), %ebx
	movl	%eax, 88(%esp)
	movsbl	84(%esp), %eax
	movl	%edx, 92(%esp)
	movl	%ebx, 40(%esp)
	movsbl	44(%esp), %ebx
	movl	%ebx, 32(%esp)
	movsbl	48(%esp), %ebx
	movl	%ebx, 44(%esp)
	movsbl	52(%esp), %ebx
	movl	%ebx, 48(%esp)
	movsbl	56(%esp), %ebx
	movl	%ebx, 52(%esp)
	movsbl	60(%esp), %ebx
	movl	%ebx, 56(%esp)
	movsbl	64(%esp), %ebx
	movl	%ebx, 60(%esp)
	movsbl	68(%esp), %ebx
	movl	%ebx, 64(%esp)
	movsbl	72(%esp), %ebx
	movl	%ebx, 68(%esp)
	movsbl	76(%esp), %ebx
	movl	%ebx, 72(%esp)
	movsbl	80(%esp), %ebx
	movl	%eax, 80(%esp)
	movsbl	96(%esp), %eax
	movl	%ebx, 76(%esp)
	xorl	%ebx, %ebx
	movl	%eax, 84(%esp)
	movsbl	100(%esp), %eax
	movl	%eax, 96(%esp)
	.p2align 4,,7
L212:
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	44(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	48(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	52(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ecx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	56(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	68(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	movl	96(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strrchr_AfteriPKcc
	cmpl	$1000000, %ebx
	jne	L212
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	88(%esp), %eax
	sbbl	92(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 144(%esp)
	addl	$124, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2830:
	.section .rdata,"dr"
LC59:
	.ascii "Type2(strstr):\0"
LC60:
	.ascii ".\0"
LC61:
	.ascii "23\0"
LC62:
	.ascii "1x\0"
LC63:
	.ascii "12\0"
LC64:
	.ascii "1\0"
LC65:
	.ascii "234567812345678\0"
LC66:
	.ascii "7x\0"
LC67:
	.ascii "678\0"
LC68:
	.ascii "78\0"
LC69:
	.ascii "8\0"
LC70:
	.ascii "1234567812345678x\0"
	.align 4
LC71:
	.ascii "!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980\0"
	.align 4
LC72:
	.ascii "ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&(.\0"
	.align 4
LC73:
	.ascii "ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&(\0"
LC74:
	.ascii "ABCDEFGHIJKLMNOPx\0"
LC75:
	.ascii "ABCDEFGHIJKLMNOx\0"
LC76:
	.ascii "ABCDEFGHIJKLMNOPQ\0"
LC77:
	.ascii "ABCDEFGHIJKLMNOP\0"
LC78:
	.ascii "AB\0"
LC79:
	.ascii "A\0"
LC80:
	.ascii "1234567980!abcdefx\0"
LC81:
	.ascii "1234567980!abcdx\0"
LC82:
	.ascii "1234567980!abcdef\0"
LC83:
	.ascii "1234567980!abcde\0"
	.align 4
LC84:
	.ascii "1111222233334444555566667777888899990000!1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_1234567980!abcdefghijklmnopqrstuvwxyz!ABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()<>[]{}|~-=+*?_\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt07_Type2_strstrv
	.def	__Z25runTestOpt07_Type2_strstrv;	.scl	2;	.type	32;	.endef
__Z25runTestOpt07_Type2_strstrv:
LFB2831:
	.cfi_startproc
	subl	$188, %esp
	.cfi_def_cfa_offset 192
	movl	$LC59, (%esp)
	call	_puts
	movl	$LC45, 164(%esp)
	movl	$LC60, 160(%esp)
	movl	$LC45, 156(%esp)
	movl	$LC45, 152(%esp)
	movl	$LC60, 148(%esp)
	movl	$LC61, 144(%esp)
	movl	$LC62, 140(%esp)
	movl	$LC63, 136(%esp)
	movl	$LC64, 132(%esp)
	movl	$LC56, 128(%esp)
	movl	$LC45, 124(%esp)
	movl	$LC60, 120(%esp)
	movl	$LC65, 116(%esp)
	movl	$LC66, 112(%esp)
	movl	$LC67, 108(%esp)
	movl	$LC68, 104(%esp)
	movl	$LC69, 100(%esp)
	movl	$LC70, 96(%esp)
	movl	$LC57, 92(%esp)
	movl	$LC62, 88(%esp)
	movl	$LC63, 84(%esp)
	movl	$LC64, 80(%esp)
	movl	$LC57, 76(%esp)
	movl	$LC45, 72(%esp)
	movl	$LC60, 68(%esp)
	movl	$LC71, 64(%esp)
	movl	$LC72, 60(%esp)
	movl	$LC73, 56(%esp)
	movl	$LC74, 52(%esp)
	movl	$LC75, 48(%esp)
	movl	$LC76, 44(%esp)
	movl	$LC77, 40(%esp)
	movl	$LC78, 36(%esp)
	movl	$LC79, 32(%esp)
	movl	$LC80, 28(%esp)
	movl	$LC81, 24(%esp)
	movl	$LC82, 20(%esp)
	movl	$LC83, 16(%esp)
	movl	$LC62, 12(%esp)
	movl	$LC63, 8(%esp)
	movl	$LC64, 4(%esp)
	movl	$LC84, (%esp)
	call	__Z32runTestOpt07_Type2_strstr_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	movl	$LC45, 164(%esp)
	movl	$LC60, 160(%esp)
	movl	$LC45, 156(%esp)
	movl	$LC45, 152(%esp)
	movl	$LC60, 148(%esp)
	movl	$LC61, 144(%esp)
	movl	$LC62, 140(%esp)
	movl	$LC63, 136(%esp)
	movl	$LC64, 132(%esp)
	movl	$LC56, 128(%esp)
	movl	$LC45, 124(%esp)
	movl	$LC60, 120(%esp)
	movl	$LC65, 116(%esp)
	movl	$LC66, 112(%esp)
	movl	$LC67, 108(%esp)
	movl	$LC68, 104(%esp)
	movl	$LC69, 100(%esp)
	movl	$LC70, 96(%esp)
	movl	$LC57, 92(%esp)
	movl	$LC62, 88(%esp)
	movl	$LC63, 84(%esp)
	movl	$LC64, 80(%esp)
	movl	$LC57, 76(%esp)
	movl	$LC45, 72(%esp)
	movl	$LC60, 68(%esp)
	movl	$LC71, 64(%esp)
	movl	$LC72, 60(%esp)
	movl	$LC73, 56(%esp)
	movl	$LC74, 52(%esp)
	movl	$LC75, 48(%esp)
	movl	$LC76, 44(%esp)
	movl	$LC77, 40(%esp)
	movl	$LC78, 36(%esp)
	movl	$LC79, 32(%esp)
	movl	$LC80, 28(%esp)
	movl	$LC81, 24(%esp)
	movl	$LC82, 20(%esp)
	movl	$LC83, 16(%esp)
	movl	$LC62, 12(%esp)
	movl	$LC63, 8(%esp)
	movl	$LC64, 4(%esp)
	movl	$LC84, (%esp)
	call	__Z32runTestOpt07_Type2_strstr_After1PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	movl	$LC45, 164(%esp)
	movl	$LC60, 160(%esp)
	movl	$LC45, 156(%esp)
	movl	$LC45, 152(%esp)
	movl	$LC60, 148(%esp)
	movl	$LC61, 144(%esp)
	movl	$LC62, 140(%esp)
	movl	$LC63, 136(%esp)
	movl	$LC64, 132(%esp)
	movl	$LC56, 128(%esp)
	movl	$LC45, 124(%esp)
	movl	$LC60, 120(%esp)
	movl	$LC65, 116(%esp)
	movl	$LC66, 112(%esp)
	movl	$LC67, 108(%esp)
	movl	$LC68, 104(%esp)
	movl	$LC69, 100(%esp)
	movl	$LC70, 96(%esp)
	movl	$LC57, 92(%esp)
	movl	$LC62, 88(%esp)
	movl	$LC63, 84(%esp)
	movl	$LC64, 80(%esp)
	movl	$LC57, 76(%esp)
	movl	$LC45, 72(%esp)
	movl	$LC60, 68(%esp)
	movl	$LC71, 64(%esp)
	movl	$LC72, 60(%esp)
	movl	$LC73, 56(%esp)
	movl	$LC74, 52(%esp)
	movl	$LC75, 48(%esp)
	movl	$LC76, 44(%esp)
	movl	$LC77, 40(%esp)
	movl	$LC78, 36(%esp)
	movl	$LC79, 32(%esp)
	movl	$LC80, 28(%esp)
	movl	$LC81, 24(%esp)
	movl	$LC82, 20(%esp)
	movl	$LC83, 16(%esp)
	movl	$LC62, 12(%esp)
	movl	$LC63, 8(%esp)
	movl	$LC64, 4(%esp)
	movl	$LC84, (%esp)
	call	__Z32runTestOpt07_Type2_strstr_After2PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	addl	$188, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2831:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strstr_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	.def	__Z32runTestOpt07_Type2_strstr_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strstr_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_:
LFB2832:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$204, %esp
	.cfi_def_cfa_offset 224
	movl	228(%esp), %eax
	movl	224(%esp), %esi
	movl	%eax, 24(%esp)
	movl	232(%esp), %eax
	movl	%eax, 28(%esp)
	movl	236(%esp), %eax
	movl	%eax, 32(%esp)
	movl	240(%esp), %eax
	movl	%eax, 36(%esp)
	movl	244(%esp), %eax
	movl	%eax, 40(%esp)
	movl	248(%esp), %eax
	movl	%eax, 44(%esp)
	movl	252(%esp), %eax
	movl	%eax, 48(%esp)
	movl	256(%esp), %eax
	movl	%eax, 52(%esp)
	movl	260(%esp), %eax
	movl	%eax, 56(%esp)
	movl	264(%esp), %eax
	movl	%eax, 60(%esp)
	movl	268(%esp), %eax
	movl	%eax, 64(%esp)
	movl	272(%esp), %eax
	movl	%eax, 68(%esp)
	movl	276(%esp), %eax
	movl	%eax, 72(%esp)
	movl	280(%esp), %eax
	movl	%eax, 76(%esp)
	movl	284(%esp), %eax
	movl	300(%esp), %edi
	movl	352(%esp), %ebp
	movl	%eax, 80(%esp)
	movl	288(%esp), %eax
	movl	%eax, 84(%esp)
	movl	292(%esp), %eax
	movl	%eax, 88(%esp)
	movl	296(%esp), %eax
	movl	%eax, 92(%esp)
	movl	304(%esp), %eax
	movl	%eax, 96(%esp)
	movl	308(%esp), %eax
	movl	%eax, 100(%esp)
	movl	312(%esp), %eax
	movl	%eax, 104(%esp)
	movl	316(%esp), %eax
	movl	%eax, 108(%esp)
	movl	320(%esp), %eax
	movl	%eax, 112(%esp)
	movl	324(%esp), %eax
	movl	%eax, 116(%esp)
	movl	328(%esp), %eax
	movl	%eax, 120(%esp)
	movl	332(%esp), %eax
	movl	%eax, 124(%esp)
	movl	336(%esp), %eax
	movl	%eax, 128(%esp)
	movl	340(%esp), %eax
	movl	%eax, 132(%esp)
	movl	344(%esp), %eax
	movl	%eax, 136(%esp)
	movl	348(%esp), %eax
	movl	%eax, 140(%esp)
	movl	356(%esp), %eax
	movl	%eax, 144(%esp)
	movl	360(%esp), %eax
	movl	$LC6, (%esp)
	movl	%eax, 148(%esp)
	movl	364(%esp), %eax
	movl	%eax, 152(%esp)
	movl	368(%esp), %eax
	movl	%eax, 156(%esp)
	movl	372(%esp), %eax
	movl	%eax, 160(%esp)
	movl	376(%esp), %eax
	movl	%eax, 164(%esp)
	movl	380(%esp), %eax
	movl	%eax, 20(%esp)
	movl	384(%esp), %eax
	movl	%eax, 168(%esp)
	movl	388(%esp), %eax
	movl	%eax, 172(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 176(%esp)
	movl	%edx, 180(%esp)
	.p2align 4,,7
L218:
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	44(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	52(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	68(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	88(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	92(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	96(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	100(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	104(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	108(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	112(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	116(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	120(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	124(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	128(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	132(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	136(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	140(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	144(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	148(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	152(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	156(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	160(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	164(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	168(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	movl	172(%esp), %edx
	movl	20(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_
	cmpl	$1000000, %ebx
	jne	L218
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	176(%esp), %eax
	sbbl	180(%esp), %edx
	movl	%eax, 184(%esp)
	movl	%edx, 188(%esp)
	fildq	184(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 224(%esp)
	addl	$204, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2832:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strstr_After1PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	.def	__Z32runTestOpt07_Type2_strstr_After1PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strstr_After1PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_:
LFB2833:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$204, %esp
	.cfi_def_cfa_offset 224
	movl	228(%esp), %eax
	movl	224(%esp), %esi
	movl	%eax, 24(%esp)
	movl	232(%esp), %eax
	movl	%eax, 28(%esp)
	movl	236(%esp), %eax
	movl	%eax, 32(%esp)
	movl	240(%esp), %eax
	movl	%eax, 36(%esp)
	movl	244(%esp), %eax
	movl	%eax, 40(%esp)
	movl	248(%esp), %eax
	movl	%eax, 44(%esp)
	movl	252(%esp), %eax
	movl	%eax, 48(%esp)
	movl	256(%esp), %eax
	movl	%eax, 52(%esp)
	movl	260(%esp), %eax
	movl	%eax, 56(%esp)
	movl	264(%esp), %eax
	movl	%eax, 60(%esp)
	movl	268(%esp), %eax
	movl	%eax, 64(%esp)
	movl	272(%esp), %eax
	movl	%eax, 68(%esp)
	movl	276(%esp), %eax
	movl	%eax, 72(%esp)
	movl	280(%esp), %eax
	movl	%eax, 76(%esp)
	movl	284(%esp), %eax
	movl	300(%esp), %edi
	movl	352(%esp), %ebp
	movl	%eax, 80(%esp)
	movl	288(%esp), %eax
	movl	%eax, 84(%esp)
	movl	292(%esp), %eax
	movl	%eax, 88(%esp)
	movl	296(%esp), %eax
	movl	%eax, 92(%esp)
	movl	304(%esp), %eax
	movl	%eax, 96(%esp)
	movl	308(%esp), %eax
	movl	%eax, 100(%esp)
	movl	312(%esp), %eax
	movl	%eax, 104(%esp)
	movl	316(%esp), %eax
	movl	%eax, 108(%esp)
	movl	320(%esp), %eax
	movl	%eax, 112(%esp)
	movl	324(%esp), %eax
	movl	%eax, 116(%esp)
	movl	328(%esp), %eax
	movl	%eax, 120(%esp)
	movl	332(%esp), %eax
	movl	%eax, 124(%esp)
	movl	336(%esp), %eax
	movl	%eax, 128(%esp)
	movl	340(%esp), %eax
	movl	%eax, 132(%esp)
	movl	344(%esp), %eax
	movl	%eax, 136(%esp)
	movl	348(%esp), %eax
	movl	%eax, 140(%esp)
	movl	356(%esp), %eax
	movl	%eax, 144(%esp)
	movl	360(%esp), %eax
	movl	$LC8, (%esp)
	movl	%eax, 148(%esp)
	movl	364(%esp), %eax
	movl	%eax, 152(%esp)
	movl	368(%esp), %eax
	movl	%eax, 156(%esp)
	movl	372(%esp), %eax
	movl	%eax, 160(%esp)
	movl	376(%esp), %eax
	movl	%eax, 164(%esp)
	movl	380(%esp), %eax
	movl	%eax, 20(%esp)
	movl	384(%esp), %eax
	movl	%eax, 168(%esp)
	movl	388(%esp), %eax
	movl	%eax, 172(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 176(%esp)
	movl	%edx, 180(%esp)
	.p2align 4,,7
L222:
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	44(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	52(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	68(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	88(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	92(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	96(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	100(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	104(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	108(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	112(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	116(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	120(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	124(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	128(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	132(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	136(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	140(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	144(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	148(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	152(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	156(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	160(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	164(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	168(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	movl	172(%esp), %edx
	movl	20(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strstr_After1iPKcS0_
	cmpl	$1000000, %ebx
	jne	L222
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	176(%esp), %eax
	sbbl	180(%esp), %edx
	movl	%eax, 184(%esp)
	movl	%edx, 188(%esp)
	fildq	184(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 224(%esp)
	addl	$204, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2833:
	.section .rdata,"dr"
LC85:
	.ascii "  After2(bm).. \0"
	.text
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strstr_After2PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_
	.def	__Z32runTestOpt07_Type2_strstr_After2PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strstr_After2PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_:
LFB2834:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$204, %esp
	.cfi_def_cfa_offset 224
	movl	228(%esp), %eax
	movl	224(%esp), %esi
	movl	%eax, 24(%esp)
	movl	232(%esp), %eax
	movl	%eax, 28(%esp)
	movl	236(%esp), %eax
	movl	%eax, 32(%esp)
	movl	240(%esp), %eax
	movl	%eax, 36(%esp)
	movl	244(%esp), %eax
	movl	%eax, 40(%esp)
	movl	248(%esp), %eax
	movl	%eax, 44(%esp)
	movl	252(%esp), %eax
	movl	%eax, 48(%esp)
	movl	256(%esp), %eax
	movl	%eax, 52(%esp)
	movl	260(%esp), %eax
	movl	%eax, 56(%esp)
	movl	264(%esp), %eax
	movl	%eax, 60(%esp)
	movl	268(%esp), %eax
	movl	%eax, 64(%esp)
	movl	272(%esp), %eax
	movl	%eax, 68(%esp)
	movl	276(%esp), %eax
	movl	%eax, 72(%esp)
	movl	280(%esp), %eax
	movl	%eax, 76(%esp)
	movl	284(%esp), %eax
	movl	300(%esp), %edi
	movl	352(%esp), %ebp
	movl	%eax, 80(%esp)
	movl	288(%esp), %eax
	movl	%eax, 84(%esp)
	movl	292(%esp), %eax
	movl	%eax, 88(%esp)
	movl	296(%esp), %eax
	movl	%eax, 92(%esp)
	movl	304(%esp), %eax
	movl	%eax, 96(%esp)
	movl	308(%esp), %eax
	movl	%eax, 100(%esp)
	movl	312(%esp), %eax
	movl	%eax, 104(%esp)
	movl	316(%esp), %eax
	movl	%eax, 108(%esp)
	movl	320(%esp), %eax
	movl	%eax, 112(%esp)
	movl	324(%esp), %eax
	movl	%eax, 116(%esp)
	movl	328(%esp), %eax
	movl	%eax, 120(%esp)
	movl	332(%esp), %eax
	movl	%eax, 124(%esp)
	movl	336(%esp), %eax
	movl	%eax, 128(%esp)
	movl	340(%esp), %eax
	movl	%eax, 132(%esp)
	movl	344(%esp), %eax
	movl	%eax, 136(%esp)
	movl	348(%esp), %eax
	movl	%eax, 140(%esp)
	movl	356(%esp), %eax
	movl	%eax, 144(%esp)
	movl	360(%esp), %eax
	movl	$LC85, (%esp)
	movl	%eax, 148(%esp)
	movl	364(%esp), %eax
	movl	%eax, 152(%esp)
	movl	368(%esp), %eax
	movl	%eax, 156(%esp)
	movl	372(%esp), %eax
	movl	%eax, 160(%esp)
	movl	376(%esp), %eax
	movl	%eax, 164(%esp)
	movl	380(%esp), %eax
	movl	%eax, 20(%esp)
	movl	384(%esp), %eax
	movl	%eax, 168(%esp)
	movl	388(%esp), %eax
	movl	%eax, 172(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 176(%esp)
	movl	%edx, 180(%esp)
	.p2align 4,,7
L226:
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	40(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	44(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	52(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	56(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	64(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	68(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	88(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	92(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	96(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	100(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	104(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	108(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	112(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	116(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	120(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	124(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	128(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	132(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	136(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	140(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	144(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	148(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	152(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	156(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	160(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	164(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	168(%esp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	movl	172(%esp), %edx
	movl	20(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	__Z29testOpt07_Type2_strstr_After2iPKcS0_
	cmpl	$1000000, %ebx
	jne	L226
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	176(%esp), %eax
	sbbl	180(%esp), %edx
	movl	%eax, 184(%esp)
	movl	%edx, 188(%esp)
	fildq	184(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 224(%esp)
	addl	$204, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2834:
	.section .rdata,"dr"
LC86:
	.ascii "Type2(strcpy):\0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt07_Type2_strcpyv
	.def	__Z25runTestOpt07_Type2_strcpyv;	.scl	2;	.type	32;	.endef
__Z25runTestOpt07_Type2_strcpyv:
LFB2835:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$1064, %esp
	.cfi_def_cfa_offset 1072
	leal	32(%esp), %ebx
	movl	$LC86, (%esp)
	call	_puts
	movl	%ebx, (%esp)
	movl	$LC45, 20(%esp)
	movl	$LC46, 16(%esp)
	movl	$LC47, 12(%esp)
	movl	$LC48, 8(%esp)
	movl	$LC49, 4(%esp)
	call	__Z32runTestOpt07_Type2_strcpy_BeforePcPKcS1_S1_S1_S1_
	movl	%ebx, (%esp)
	movl	$LC45, 20(%esp)
	movl	$LC46, 16(%esp)
	movl	$LC47, 12(%esp)
	movl	$LC48, 8(%esp)
	movl	$LC49, 4(%esp)
	call	__Z31runTestOpt07_Type2_strcpy_AfterPcPKcS1_S1_S1_S1_
	addl	$1064, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2835:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strcpy_BeforePcPKcS1_S1_S1_S1_
	.def	__Z32runTestOpt07_Type2_strcpy_BeforePcPKcS1_S1_S1_S1_;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strcpy_BeforePcPKcS1_S1_S1_S1_:
LFB2836:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	92(%esp), %eax
	movl	$LC6, (%esp)
	movl	80(%esp), %esi
	movl	84(%esp), %ebp
	movl	88(%esp), %edi
	movl	%eax, 20(%esp)
	movl	96(%esp), %eax
	movl	%eax, 24(%esp)
	movl	100(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L232:
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	call	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc
	movl	%ebx, (%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc
	movl	20(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc
	cmpl	$1000000, %ebx
	jne	L232
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 80(%esp)
	addl	$60, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2836:
	.p2align 4,,15
	.globl	__Z31runTestOpt07_Type2_strcpy_AfterPcPKcS1_S1_S1_S1_
	.def	__Z31runTestOpt07_Type2_strcpy_AfterPcPKcS1_S1_S1_S1_;	.scl	2;	.type	32;	.endef
__Z31runTestOpt07_Type2_strcpy_AfterPcPKcS1_S1_S1_S1_:
LFB2837:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	92(%esp), %eax
	movl	$LC16, (%esp)
	movl	80(%esp), %esi
	movl	84(%esp), %ebp
	movl	88(%esp), %edi
	movl	%eax, 20(%esp)
	movl	96(%esp), %eax
	movl	%eax, 24(%esp)
	movl	100(%esp), %eax
	movl	%eax, 28(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	.p2align 4,,7
L236:
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	call	__Z28testOpt07_Type2_strcpy_AfteriPcPKc
	movl	%ebx, (%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	__Z28testOpt07_Type2_strcpy_AfteriPcPKc
	movl	20(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strcpy_AfteriPcPKc
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strcpy_AfteriPcPKc
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	call	__Z28testOpt07_Type2_strcpy_AfteriPcPKc
	cmpl	$1000000, %ebx
	jne	L236
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 80(%esp)
	addl	$60, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2837:
	.section .rdata,"dr"
LC87:
	.ascii "Type2(strncpy):\0"
	.text
	.p2align 4,,15
	.globl	__Z26runTestOpt07_Type2_strncpyv
	.def	__Z26runTestOpt07_Type2_strncpyv;	.scl	2;	.type	32;	.endef
__Z26runTestOpt07_Type2_strncpyv:
LFB2838:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$1128, %esp
	.cfi_def_cfa_offset 1136
	leal	96(%esp), %ebx
	movl	$LC87, (%esp)
	call	_puts
	movl	%ebx, (%esp)
	movl	$0, 80(%esp)
	movl	$1, 76(%esp)
	movl	$2, 72(%esp)
	movl	$LC45, 68(%esp)
	movl	$2, 64(%esp)
	movl	$3, 60(%esp)
	movl	$4, 56(%esp)
	movl	$LC46, 52(%esp)
	movl	$15, 48(%esp)
	movl	$16, 44(%esp)
	movl	$17, 40(%esp)
	movl	$LC47, 36(%esp)
	movl	$16, 32(%esp)
	movl	$17, 28(%esp)
	movl	$18, 24(%esp)
	movl	$LC48, 20(%esp)
	movl	$169, 16(%esp)
	movl	$170, 12(%esp)
	movl	$171, 8(%esp)
	movl	$LC49, 4(%esp)
	call	__Z33runTestOpt07_Type2_strncpy_BeforePcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj
	movl	%ebx, (%esp)
	movl	$0, 80(%esp)
	movl	$1, 76(%esp)
	movl	$2, 72(%esp)
	movl	$LC45, 68(%esp)
	movl	$2, 64(%esp)
	movl	$3, 60(%esp)
	movl	$4, 56(%esp)
	movl	$LC46, 52(%esp)
	movl	$15, 48(%esp)
	movl	$16, 44(%esp)
	movl	$17, 40(%esp)
	movl	$LC47, 36(%esp)
	movl	$16, 32(%esp)
	movl	$17, 28(%esp)
	movl	$18, 24(%esp)
	movl	$LC48, 20(%esp)
	movl	$169, 16(%esp)
	movl	$170, 12(%esp)
	movl	$171, 8(%esp)
	movl	$LC49, 4(%esp)
	call	__Z32runTestOpt07_Type2_strncpy_AfterPcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj
	addl	$1128, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2838:
	.p2align 4,,15
	.globl	__Z33runTestOpt07_Type2_strncpy_BeforePcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj
	.def	__Z33runTestOpt07_Type2_strncpy_BeforePcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj;	.scl	2;	.type	32;	.endef
__Z33runTestOpt07_Type2_strncpy_BeforePcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj:
LFB2839:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$124, %esp
	.cfi_def_cfa_offset 144
	movl	148(%esp), %eax
	movl	144(%esp), %esi
	movl	196(%esp), %ebp
	movl	%eax, 24(%esp)
	movl	152(%esp), %eax
	movl	%eax, 36(%esp)
	movl	156(%esp), %eax
	movl	%eax, 40(%esp)
	movl	160(%esp), %eax
	movl	%eax, 44(%esp)
	movl	164(%esp), %eax
	movl	%eax, 28(%esp)
	movl	168(%esp), %eax
	movl	%eax, 48(%esp)
	movl	172(%esp), %eax
	movl	%eax, 52(%esp)
	movl	176(%esp), %eax
	movl	%eax, 56(%esp)
	movl	180(%esp), %eax
	movl	%eax, 32(%esp)
	movl	184(%esp), %eax
	movl	%eax, 60(%esp)
	movl	188(%esp), %eax
	movl	%eax, 64(%esp)
	movl	192(%esp), %eax
	movl	%eax, 68(%esp)
	movl	200(%esp), %eax
	movl	%eax, 72(%esp)
	movl	204(%esp), %eax
	movl	%eax, 76(%esp)
	movl	208(%esp), %eax
	movl	$LC6, (%esp)
	movl	212(%esp), %edi
	movl	%eax, 80(%esp)
	movl	216(%esp), %eax
	movl	%eax, 84(%esp)
	movl	220(%esp), %eax
	movl	%eax, 88(%esp)
	movl	224(%esp), %eax
	movl	%eax, 92(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 96(%esp)
	movl	%edx, 100(%esp)
	.p2align 4,,7
L242:
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	movl	24(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	40(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	44(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	movl	28(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	52(%esp), %edx
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	56(%esp), %ecx
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	movl	32(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	64(%esp), %edx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	68(%esp), %ecx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	88(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	movl	92(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj
	cmpl	$1000000, %ebx
	jne	L242
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	96(%esp), %eax
	sbbl	100(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 144(%esp)
	addl	$124, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2839:
	.p2align 4,,15
	.globl	__Z32runTestOpt07_Type2_strncpy_AfterPcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj
	.def	__Z32runTestOpt07_Type2_strncpy_AfterPcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj;	.scl	2;	.type	32;	.endef
__Z32runTestOpt07_Type2_strncpy_AfterPcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj:
LFB2840:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	xorl	%ebx, %ebx
	subl	$124, %esp
	.cfi_def_cfa_offset 144
	movl	148(%esp), %eax
	movl	144(%esp), %esi
	movl	196(%esp), %ebp
	movl	%eax, 24(%esp)
	movl	152(%esp), %eax
	movl	%eax, 36(%esp)
	movl	156(%esp), %eax
	movl	%eax, 40(%esp)
	movl	160(%esp), %eax
	movl	%eax, 44(%esp)
	movl	164(%esp), %eax
	movl	%eax, 28(%esp)
	movl	168(%esp), %eax
	movl	%eax, 48(%esp)
	movl	172(%esp), %eax
	movl	%eax, 52(%esp)
	movl	176(%esp), %eax
	movl	%eax, 56(%esp)
	movl	180(%esp), %eax
	movl	%eax, 32(%esp)
	movl	184(%esp), %eax
	movl	%eax, 60(%esp)
	movl	188(%esp), %eax
	movl	%eax, 64(%esp)
	movl	192(%esp), %eax
	movl	%eax, 68(%esp)
	movl	200(%esp), %eax
	movl	%eax, 72(%esp)
	movl	204(%esp), %eax
	movl	%eax, 76(%esp)
	movl	208(%esp), %eax
	movl	$LC16, (%esp)
	movl	212(%esp), %edi
	movl	%eax, 80(%esp)
	movl	216(%esp), %eax
	movl	%eax, 84(%esp)
	movl	220(%esp), %eax
	movl	%eax, 88(%esp)
	movl	224(%esp), %eax
	movl	%eax, 92(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 96(%esp)
	movl	%edx, 100(%esp)
	.p2align 4,,7
L246:
	movl	36(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	movl	24(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	40(%esp), %edx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	44(%esp), %ecx
	movl	24(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	48(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	movl	28(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	52(%esp), %edx
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	56(%esp), %ecx
	movl	28(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	60(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	movl	32(%esp), %eax
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	64(%esp), %edx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	68(%esp), %ecx
	movl	32(%esp), %eax
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, 8(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	72(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	76(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	80(%esp), %eax
	movl	%ebx, (%esp)
	movl	%ebp, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	84(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	88(%esp), %eax
	movl	%ebx, (%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	movl	92(%esp), %eax
	movl	%ebx, (%esp)
	addl	$1, %ebx
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj
	cmpl	$1000000, %ebx
	jne	L246
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	96(%esp), %eax
	sbbl	100(%esp), %edx
	movl	%eax, 104(%esp)
	movl	%edx, 108(%esp)
	fildq	104(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 144(%esp)
	addl	$124, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2840:
	.section .rdata,"dr"
LC88:
	.ascii "[Optimize Test 08]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt08v
	.def	__Z12runTestOpt08v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt08v:
LFB2841:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$LC3, (%esp)
	call	_puts
	movl	$LC88, (%esp)
	call	_puts
	call	__Z18runTestOpt08_Type1v
	call	__Z18runTestOpt08_Type2v
	.p2align 4,,5
	call	__Z18runTestOpt08_Type3v
	.p2align 4,,5
	call	__Z18runTestOpt08_Type4v
	.p2align 4,,5
	call	__Z18runTestOpt08_Type5v
	.p2align 4,,5
	call	__Z18runTestOpt08_Type6v
	.p2align 4,,5
	call	__Z18runTestOpt08_Type7v
	.p2align 4,,5
	call	__Z18runTestOpt08_Type8v
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z18runTestOpt08_Type9v
	.cfi_endproc
LFE2841:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type1_Beforeiiii
	.def	__Z25runTestOpt08_Type1_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type1_Beforeiiii:
LFB2843:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC6, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L252:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	subl	$1, %ebx
	jne	L252
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2843:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type1_After1iiii
	.def	__Z25runTestOpt08_Type1_After1iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type1_After1iiii:
LFB2844:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC8, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L256:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type1_After1i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type1_After1i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type1_After1i
	subl	$1, %ebx
	jne	L256
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2844:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type1_After2iiii
	.def	__Z25runTestOpt08_Type1_After2iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type1_After2iiii:
LFB2845:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC9, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L260:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type1_After2i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type1_After2i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type1_After2i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type1_After2i
	subl	$1, %ebx
	jne	L260
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2845:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type1_After3iiii
	.def	__Z25runTestOpt08_Type1_After3iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type1_After3iiii:
LFB2846:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC10, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L264:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type1_After3i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type1_After3i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type1_After3i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type1_After3i
	subl	$1, %ebx
	jne	L264
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2846:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type2_Beforeiiii
	.def	__Z25runTestOpt08_Type2_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type2_Beforeiiii:
LFB2848:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC6, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L268:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	subl	$1, %ebx
	jne	L268
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2848:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type2_After1iiii
	.def	__Z25runTestOpt08_Type2_After1iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type2_After1iiii:
LFB2849:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC8, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L272:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type2_After1i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type2_After1i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type2_After1i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type2_After1i
	subl	$1, %ebx
	jne	L272
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2849:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type2_After2iiii
	.def	__Z25runTestOpt08_Type2_After2iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type2_After2iiii:
LFB2850:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC9, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L276:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type2_After2i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type2_After2i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type2_After2i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type2_After2i
	subl	$1, %ebx
	jne	L276
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2850:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type2_After3iiii
	.def	__Z25runTestOpt08_Type2_After3iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type2_After3iiii:
LFB2851:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC10, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L280:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type2_After3i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type2_After3i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type2_After3i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type2_After3i
	subl	$1, %ebx
	jne	L280
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2851:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type3_Beforeiiii
	.def	__Z25runTestOpt08_Type3_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type3_Beforeiiii:
LFB2853:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC6, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L284:
	movl	%edi, 4(%esp)
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type3_Beforeii
	movl	12(%esp), %eax
	movl	%esi, (%esp)
	movl	%eax, 4(%esp)
	call	__Z22testOpt08_Type3_Beforeii
	subl	$1, %ebx
	jne	L284
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2853:
	.p2align 4,,15
	.globl	__Z24runTestOpt08_Type3_Afteriiii
	.def	__Z24runTestOpt08_Type3_Afteriiii;	.scl	2;	.type	32;	.endef
__Z24runTestOpt08_Type3_Afteriiii:
LFB2854:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC8, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L288:
	movl	%edi, 4(%esp)
	movl	%ebp, (%esp)
	call	__Z21testOpt08_Type3_Afterii
	movl	12(%esp), %eax
	movl	%esi, (%esp)
	movl	%eax, 4(%esp)
	call	__Z21testOpt08_Type3_Afterii
	subl	$1, %ebx
	jne	L288
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2854:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type4_Beforeiiii
	.def	__Z25runTestOpt08_Type4_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type4_Beforeiiii:
LFB2856:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC6, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L292:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	subl	$1, %ebx
	jne	L292
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2856:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type4_After1iiii
	.def	__Z25runTestOpt08_Type4_After1iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type4_After1iiii:
LFB2857:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC8, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L296:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type4_After1i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type4_After1i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type4_After1i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type4_After1i
	subl	$1, %ebx
	jne	L296
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2857:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type4_After2iiii
	.def	__Z25runTestOpt08_Type4_After2iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type4_After2iiii:
LFB2858:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC9, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L300:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type4_After2i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type4_After2i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type4_After2i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type4_After2i
	subl	$1, %ebx
	jne	L300
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2858:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type5_Beforeiiii
	.def	__Z25runTestOpt08_Type5_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type5_Beforeiiii:
LFB2860:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$10000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC6, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L304:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	subl	$1, %ebx
	jne	L304
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2860:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type5_After1iiii
	.def	__Z25runTestOpt08_Type5_After1iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type5_After1iiii:
LFB2861:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$10000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC8, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L308:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type5_After1i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type5_After1i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After1i
	subl	$1, %ebx
	jne	L308
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2861:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type5_After2iiii
	.def	__Z25runTestOpt08_Type5_After2iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type5_After2iiii:
LFB2862:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$10000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC9, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L312:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type5_After2i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type5_After2i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type5_After2i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type5_After2i
	subl	$1, %ebx
	jne	L312
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2862:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type6_Beforeiiii
	.def	__Z25runTestOpt08_Type6_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type6_Beforeiiii:
LFB2864:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$10000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC6, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L316:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	subl	$1, %ebx
	jne	L316
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2864:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type6_After1iiii
	.def	__Z25runTestOpt08_Type6_After1iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type6_After1iiii:
LFB2865:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$10000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC8, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L320:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type6_After1i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type6_After1i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After1i
	subl	$1, %ebx
	jne	L320
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2865:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type6_After2iiii
	.def	__Z25runTestOpt08_Type6_After2iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type6_After2iiii:
LFB2866:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$10000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC9, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L324:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type6_After2i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type6_After2i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type6_After2i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type6_After2i
	subl	$1, %ebx
	jne	L324
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2866:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type7_Beforeiiii
	.def	__Z25runTestOpt08_Type7_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type7_Beforeiiii:
LFB2868:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$10000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC6, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L328:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	subl	$1, %ebx
	jne	L328
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2868:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type7_After1iiii
	.def	__Z25runTestOpt08_Type7_After1iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type7_After1iiii:
LFB2869:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$10000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC8, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L332:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type7_After1i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type7_After1i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After1i
	subl	$1, %ebx
	jne	L332
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2869:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type7_After2iiii
	.def	__Z25runTestOpt08_Type7_After2iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type7_After2iiii:
LFB2870:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$10000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC9, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L336:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type7_After2i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type7_After2i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type7_After2i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type7_After2i
	subl	$1, %ebx
	jne	L336
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2870:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type8_Beforeiiii
	.def	__Z25runTestOpt08_Type8_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type8_Beforeiiii:
LFB2872:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC6, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L340:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type8_Beforei
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type8_Beforei
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type8_Beforei
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type8_Beforei
	subl	$1, %ebx
	jne	L340
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2872:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type8_After1iiii
	.def	__Z25runTestOpt08_Type8_After1iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type8_After1iiii:
LFB2873:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC8, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L344:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type8_After1i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type8_After1i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type8_After1i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type8_After1i
	subl	$1, %ebx
	jne	L344
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2873:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type8_After2iiii
	.def	__Z25runTestOpt08_Type8_After2iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type8_After2iiii:
LFB2874:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC9, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L348:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type8_After2i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type8_After2i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type8_After2i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type8_After2i
	subl	$1, %ebx
	jne	L348
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2874:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type9_Beforeiiii
	.def	__Z25runTestOpt08_Type9_Beforeiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type9_Beforeiiii:
LFB2876:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC6, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L352:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type9_Beforei
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type9_Beforei
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type9_Beforei
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type9_Beforei
	subl	$1, %ebx
	jne	L352
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2876:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type9_After1iiii
	.def	__Z25runTestOpt08_Type9_After1iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type9_After1iiii:
LFB2877:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC8, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L356:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type9_After1i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type9_After1i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type9_After1i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type9_After1i
	subl	$1, %ebx
	jne	L356
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2877:
	.p2align 4,,15
	.globl	__Z25runTestOpt08_Type9_After2iiii
	.def	__Z25runTestOpt08_Type9_After2iiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt08_Type9_After2iiii:
LFB2878:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$100000000, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	$LC9, (%esp)
	movl	64(%esp), %ebp
	movl	68(%esp), %edi
	movl	72(%esp), %esi
	movl	%eax, 12(%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L360:
	movl	%ebp, (%esp)
	call	__Z22testOpt08_Type9_After2i
	movl	%edi, (%esp)
	call	__Z22testOpt08_Type9_After2i
	movl	%esi, (%esp)
	call	__Z22testOpt08_Type9_After2i
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt08_Type9_After2i
	subl	$1, %ebx
	jne	L360
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	$10, 64(%esp)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	_putchar
	.cfi_endproc
LFE2878:
	.section .rdata,"dr"
	.align 4
LC89:
	.ascii "Judge1(%d) ... %d / %d / %d (%d)\12\0"
	.align 4
LC90:
	.ascii "Judge2(%d) ... %d / %d / %d (%d)\12\0"
LC91:
	.ascii "Judge3(%d, %d) ... %d (%d)\12\0"
LC92:
	.ascii "Align64(%d) ... %d / %d (%d)\12\0"
	.align 4
LC93:
	.ascii "CountBits(0x%08x) ... %d / %d (%d)\12\0"
LC94:
	.ascii "MSB(0x%08x) ... %d / %d (%d)\12\0"
LC95:
	.ascii "LSB(0x%08x) ... %d / %d (%d)\12\0"
LC96:
	.ascii "Abs(%d) ... %d / %d (%d)\12\0"
LC97:
	.ascii "Sign(%d) ... %d / %d (%d)\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt08_1timev
	.def	__Z18runTestOpt08_1timev;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_1timev:
LFB2879:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$0, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$0, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$0, 4(%esp)
	movl	$LC89, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$10, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$10, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$10, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$10, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$10, 4(%esp)
	movl	$LC89, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$100, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$100, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$100, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$100, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$100, 4(%esp)
	movl	$LC89, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$150, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$150, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$150, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$150, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$150, 4(%esp)
	movl	$LC89, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$200, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$200, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$200, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$200, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$200, 4(%esp)
	movl	$LC89, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$250, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$250, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$250, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$250, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$250, 4(%esp)
	movl	$LC89, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$300, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$300, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$300, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$300, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$300, 4(%esp)
	movl	$LC89, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$350, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$350, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$350, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$350, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$350, 4(%esp)
	movl	$LC89, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$400, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$400, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$400, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$400, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$400, 4(%esp)
	movl	$LC89, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$450, (%esp)
	call	__Z22testOpt08_Type1_Beforei
	movl	$450, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type1_After3i
	movl	$450, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type1_After2i
	movl	$450, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type1_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$450, 4(%esp)
	movl	$LC89, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$0, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	$0, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type2_After3i
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type2_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type2_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$0, 4(%esp)
	movl	$LC90, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$10, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	$10, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type2_After3i
	movl	$10, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type2_After2i
	movl	$10, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type2_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$10, 4(%esp)
	movl	$LC90, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$100, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	$100, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type2_After3i
	movl	$100, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type2_After2i
	movl	$100, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type2_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$100, 4(%esp)
	movl	$LC90, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$150, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	$150, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type2_After3i
	movl	$150, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type2_After2i
	movl	$150, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type2_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$150, 4(%esp)
	movl	$LC90, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$200, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	$200, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type2_After3i
	movl	$200, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type2_After2i
	movl	$200, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type2_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$200, 4(%esp)
	movl	$LC90, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$250, (%esp)
	call	__Z22testOpt08_Type2_Beforei
	movl	$250, (%esp)
	movl	%eax, %edi
	call	__Z22testOpt08_Type2_After3i
	movl	$250, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type2_After2i
	movl	$250, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type2_After1i
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$250, 4(%esp)
	movl	$LC90, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	call	__Z22testOpt08_Type3_Beforeii
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	movzbl	%al, %ebx
	call	__Z21testOpt08_Type3_Afterii
	movl	%ebx, 16(%esp)
	movl	$0, 8(%esp)
	movl	$0, 4(%esp)
	movl	$LC91, (%esp)
	movzbl	%al, %eax
	movl	%eax, 12(%esp)
	call	_printf
	movl	$0, 4(%esp)
	movl	$100, (%esp)
	call	__Z22testOpt08_Type3_Beforeii
	movl	$0, 4(%esp)
	movl	$100, (%esp)
	movzbl	%al, %ebx
	call	__Z21testOpt08_Type3_Afterii
	movl	%ebx, 16(%esp)
	movl	$0, 8(%esp)
	movl	$100, 4(%esp)
	movl	$LC91, (%esp)
	movzbl	%al, %eax
	movl	%eax, 12(%esp)
	call	_printf
	movl	$100, 4(%esp)
	movl	$0, (%esp)
	call	__Z22testOpt08_Type3_Beforeii
	movl	$100, 4(%esp)
	movl	$0, (%esp)
	movzbl	%al, %ebx
	call	__Z21testOpt08_Type3_Afterii
	movl	%ebx, 16(%esp)
	movl	$100, 8(%esp)
	movl	$0, 4(%esp)
	movl	$LC91, (%esp)
	movzbl	%al, %eax
	movl	%eax, 12(%esp)
	call	_printf
	movl	$100, 4(%esp)
	movl	$100, (%esp)
	call	__Z22testOpt08_Type3_Beforeii
	movl	$100, 4(%esp)
	movl	$100, (%esp)
	movzbl	%al, %ebx
	call	__Z21testOpt08_Type3_Afterii
	movl	%ebx, 16(%esp)
	movl	$100, 8(%esp)
	movl	$100, 4(%esp)
	movl	$LC91, (%esp)
	movzbl	%al, %eax
	movl	%eax, 12(%esp)
	call	_printf
	movl	$0, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type4_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type4_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$0, 4(%esp)
	movl	$LC92, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$63, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	$63, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type4_After2i
	movl	$63, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type4_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$63, 4(%esp)
	movl	$LC92, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$64, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	$64, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type4_After2i
	movl	$64, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type4_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$64, 4(%esp)
	movl	$LC92, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$65, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	$65, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type4_After2i
	movl	$65, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type4_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$65, 4(%esp)
	movl	$LC92, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$127, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	$127, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type4_After2i
	movl	$127, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type4_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$127, 4(%esp)
	movl	$LC92, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$128, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	$128, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type4_After2i
	movl	$128, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type4_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$128, 4(%esp)
	movl	$LC92, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$129, (%esp)
	call	__Z22testOpt08_Type4_Beforei
	movl	$129, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type4_After2i
	movl	$129, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type4_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$129, 4(%esp)
	movl	$LC92, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$0, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$0, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-2147483648, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$-2147483648, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$-2147483648, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-2147483648, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-2147483647, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$-2147483647, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$-2147483647, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-2147483647, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$98304, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$98304, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$98304, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$98304, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$528384, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$528384, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$528384, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$528384, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1050624, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$1050624, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$1050624, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1050624, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$8388864, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$8388864, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$8388864, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$8388864, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$16777344, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$16777344, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$16777344, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$16777344, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$134217744, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$134217744, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$134217744, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$134217744, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$268435464, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$268435464, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$268435464, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$268435464, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$286331153, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$286331153, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$286331153, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$286331153, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-2004318072, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$-2004318072, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$-2004318072, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-2004318072, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1431655765, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$1431655765, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$1431655765, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1431655765, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-1431655766, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$-1431655766, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$-1431655766, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-1431655766, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$305419896, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$305419896, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$305419896, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$305419896, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-1698898192, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$-1698898192, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$-1698898192, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-1698898192, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-1, (%esp)
	call	__Z22testOpt08_Type5_Beforei
	movl	$-1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type5_After2i
	movl	$-1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type5_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-1, 4(%esp)
	movl	$LC93, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$0, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$0, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-2147483648, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$-2147483648, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$-2147483648, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-2147483648, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$286331153, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$286331153, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$286331153, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$286331153, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-2004318072, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$-2004318072, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$-2004318072, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-2004318072, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$98304, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$98304, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$98304, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$98304, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$528384, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$528384, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$528384, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$528384, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1050624, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$1050624, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$1050624, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1050624, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$8388864, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$8388864, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$8388864, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$8388864, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$16777344, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$16777344, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$16777344, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$16777344, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$134217744, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$134217744, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$134217744, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$134217744, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$268435464, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$268435464, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$268435464, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$268435464, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1431655765, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$1431655765, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$1431655765, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1431655765, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-1431655766, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$-1431655766, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$-1431655766, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-1431655766, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$305419896, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$305419896, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$305419896, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$305419896, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-1698898192, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$-1698898192, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$-1698898192, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-1698898192, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-1, (%esp)
	call	__Z22testOpt08_Type6_Beforei
	movl	$-1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type6_After2i
	movl	$-1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type6_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-1, 4(%esp)
	movl	$LC94, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$0, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$0, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-2147483648, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$-2147483648, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$-2147483648, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-2147483648, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$286331153, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$286331153, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$286331153, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$286331153, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-2004318072, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$-2004318072, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$-2004318072, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-2004318072, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$98304, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$98304, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$98304, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$98304, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$528384, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$528384, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$528384, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$528384, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1050624, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$1050624, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$1050624, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1050624, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$8388864, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$8388864, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$8388864, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$8388864, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$16777344, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$16777344, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$16777344, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$16777344, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$134217744, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$134217744, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$134217744, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$134217744, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$268435464, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$268435464, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$268435464, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$268435464, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1431655765, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$1431655765, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$1431655765, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1431655765, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-1431655766, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$-1431655766, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$-1431655766, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-1431655766, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$305419896, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$305419896, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$305419896, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$305419896, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-1698898192, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$-1698898192, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$-1698898192, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-1698898192, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-1, (%esp)
	call	__Z22testOpt08_Type7_Beforei
	movl	$-1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type7_After2i
	movl	$-1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type7_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-1, 4(%esp)
	movl	$LC95, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$0, (%esp)
	call	__Z22testOpt08_Type8_Beforei
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type8_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type8_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$0, 4(%esp)
	movl	$LC96, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1, (%esp)
	call	__Z22testOpt08_Type8_Beforei
	movl	$1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type8_After2i
	movl	$1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type8_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1, 4(%esp)
	movl	$LC96, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-1, (%esp)
	call	__Z22testOpt08_Type8_Beforei
	movl	$-1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type8_After2i
	movl	$-1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type8_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-1, 4(%esp)
	movl	$LC96, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$2, (%esp)
	call	__Z22testOpt08_Type8_Beforei
	movl	$2, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type8_After2i
	movl	$2, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type8_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$2, 4(%esp)
	movl	$LC96, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-2, (%esp)
	call	__Z22testOpt08_Type8_Beforei
	movl	$-2, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type8_After2i
	movl	$-2, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type8_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-2, 4(%esp)
	movl	$LC96, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$100, (%esp)
	call	__Z22testOpt08_Type8_Beforei
	movl	$100, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type8_After2i
	movl	$100, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type8_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$100, 4(%esp)
	movl	$LC96, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-100, (%esp)
	call	__Z22testOpt08_Type8_Beforei
	movl	$-100, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type8_After2i
	movl	$-100, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type8_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-100, 4(%esp)
	movl	$LC96, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$65536, (%esp)
	call	__Z22testOpt08_Type8_Beforei
	movl	$65536, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type8_After2i
	movl	$65536, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type8_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$65536, 4(%esp)
	movl	$LC96, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-65536, (%esp)
	call	__Z22testOpt08_Type8_Beforei
	movl	$-65536, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type8_After2i
	movl	$-65536, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type8_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-65536, 4(%esp)
	movl	$LC96, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$2147483647, (%esp)
	call	__Z22testOpt08_Type8_Beforei
	movl	$2147483647, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type8_After2i
	movl	$2147483647, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type8_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$2147483647, 4(%esp)
	movl	$LC96, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-2147483648, (%esp)
	call	__Z22testOpt08_Type8_Beforei
	movl	$-2147483648, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type8_After2i
	movl	$-2147483648, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type8_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-2147483648, 4(%esp)
	movl	$LC96, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$0, (%esp)
	call	__Z22testOpt08_Type9_Beforei
	movl	$0, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type9_After2i
	movl	$0, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type9_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$0, 4(%esp)
	movl	$LC97, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$1, (%esp)
	call	__Z22testOpt08_Type9_Beforei
	movl	$1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type9_After2i
	movl	$1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type9_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$1, 4(%esp)
	movl	$LC97, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-1, (%esp)
	call	__Z22testOpt08_Type9_Beforei
	movl	$-1, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type9_After2i
	movl	$-1, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type9_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-1, 4(%esp)
	movl	$LC97, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$2, (%esp)
	call	__Z22testOpt08_Type9_Beforei
	movl	$2, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type9_After2i
	movl	$2, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type9_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$2, 4(%esp)
	movl	$LC97, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-2, (%esp)
	call	__Z22testOpt08_Type9_Beforei
	movl	$-2, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type9_After2i
	movl	$-2, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type9_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-2, 4(%esp)
	movl	$LC97, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$100, (%esp)
	call	__Z22testOpt08_Type9_Beforei
	movl	$100, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type9_After2i
	movl	$100, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type9_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$100, 4(%esp)
	movl	$LC97, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-100, (%esp)
	call	__Z22testOpt08_Type9_Beforei
	movl	$-100, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type9_After2i
	movl	$-100, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type9_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-100, 4(%esp)
	movl	$LC97, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$65536, (%esp)
	call	__Z22testOpt08_Type9_Beforei
	movl	$65536, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type9_After2i
	movl	$65536, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type9_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$65536, 4(%esp)
	movl	$LC97, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-65536, (%esp)
	call	__Z22testOpt08_Type9_Beforei
	movl	$-65536, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type9_After2i
	movl	$-65536, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type9_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-65536, 4(%esp)
	movl	$LC97, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$2147483647, (%esp)
	call	__Z22testOpt08_Type9_Beforei
	movl	$2147483647, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type9_After2i
	movl	$2147483647, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type9_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$2147483647, 4(%esp)
	movl	$LC97, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	movl	$-2147483648, (%esp)
	call	__Z22testOpt08_Type9_Beforei
	movl	$-2147483648, (%esp)
	movl	%eax, %esi
	call	__Z22testOpt08_Type9_After2i
	movl	$-2147483648, (%esp)
	movl	%eax, %ebx
	call	__Z22testOpt08_Type9_After1i
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$-2147483648, 4(%esp)
	movl	$LC97, (%esp)
	movl	%eax, 8(%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2879:
	.section .rdata,"dr"
LC98:
	.ascii "[Optimize Test 09]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt09v
	.def	__Z12runTestOpt09v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt09v:
LFB2880:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$LC3, (%esp)
	call	_puts
	movl	$LC98, (%esp)
	call	_puts
	call	__Z18runTestOpt09_Type1v
	call	__Z18runTestOpt09_Type2v
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	jmp	__Z18runTestOpt09_Type3v
	.cfi_endproc
LFE2880:
	.p2align 4,,15
	.globl	__Z18runTestOpt09_Type1v
	.def	__Z18runTestOpt09_Type1v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt09_Type1v:
LFB2881:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$40024, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_def_cfa_offset 40032
	leal	16(%esp), %ebx
	movl	$100000, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	%ebx, (%esp)
	call	__Z12initOpt08_t1R12dataOpt08_t1
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type1_BeforeR12dataOpt08_t1
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type1_After1R12dataOpt08_t1
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type1_After2R12dataOpt08_t1
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type1_After3R12dataOpt08_t1
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type1_After4R12dataOpt08_t1
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type1_After5R12dataOpt08_t1
	movl	%ebx, (%esp)
	call	__Z27runTestOpt09_Type1_AppendixR12dataOpt08_t1
	addl	$40024, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2881:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type1_BeforeR12dataOpt08_t1
	.def	__Z25runTestOpt09_Type1_BeforeR12dataOpt08_t1;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type1_BeforeR12dataOpt08_t1:
LFB2882:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC6, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L370:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type1_BeforeR12dataOpt08_t1
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L370
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2882:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type1_After1R12dataOpt08_t1
	.def	__Z25runTestOpt09_Type1_After1R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type1_After1R12dataOpt08_t1:
LFB2883:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC8, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L374:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type1_After1R12dataOpt08_t1
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L374
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2883:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type1_After2R12dataOpt08_t1
	.def	__Z25runTestOpt09_Type1_After2R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type1_After2R12dataOpt08_t1:
LFB2884:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC9, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L378:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type1_After2R12dataOpt08_t1
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L378
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2884:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type1_After3R12dataOpt08_t1
	.def	__Z25runTestOpt09_Type1_After3R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type1_After3R12dataOpt08_t1:
LFB2885:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC10, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L382:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type1_After3R12dataOpt08_t1
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L382
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2885:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type1_After4R12dataOpt08_t1
	.def	__Z25runTestOpt09_Type1_After4R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type1_After4R12dataOpt08_t1:
LFB2886:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC11, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L386:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type1_After4R12dataOpt08_t1
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L386
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2886:
	.section .rdata,"dr"
LC99:
	.ascii "  After5   ... \0"
	.text
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type1_After5R12dataOpt08_t1
	.def	__Z25runTestOpt09_Type1_After5R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type1_After5R12dataOpt08_t1:
LFB2887:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC99, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L390:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type1_After5R12dataOpt08_t1
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L390
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2887:
	.p2align 4,,15
	.globl	__Z27runTestOpt09_Type1_AppendixR12dataOpt08_t1
	.def	__Z27runTestOpt09_Type1_AppendixR12dataOpt08_t1;	.scl	2;	.type	32;	.endef
__Z27runTestOpt09_Type1_AppendixR12dataOpt08_t1:
LFB2888:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$100000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC12, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L394:
	movl	%esi, (%esp)
	call	__Z24testOpt09_Type1_AppendixR12dataOpt08_t1
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L394
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2888:
	.p2align 4,,15
	.globl	__Z18runTestOpt09_Type2v
	.def	__Z18runTestOpt09_Type2v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt09_Type2v:
LFB2889:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$480024, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_def_cfa_offset 480032
	leal	16(%esp), %ebx
	movl	$50000, 4(%esp)
	movl	$LC26, (%esp)
	call	_printf
	movl	%ebx, (%esp)
	call	__Z12initOpt08_t2R12dataOpt08_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type2_BeforeR12dataOpt08_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type2_After1R12dataOpt08_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type2_After2R12dataOpt08_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type2_After3R12dataOpt08_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type2_After4R12dataOpt08_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type2_After5R12dataOpt08_t2
	movl	%ebx, (%esp)
	call	__Z27runTestOpt09_Type2_AppendixR12dataOpt08_t2
	addl	$480024, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2889:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type2_BeforeR12dataOpt08_t2
	.def	__Z25runTestOpt09_Type2_BeforeR12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type2_BeforeR12dataOpt08_t2:
LFB2890:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$50000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC6, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L400:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type2_BeforeR12dataOpt08_t2
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L400
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2890:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type2_After1R12dataOpt08_t2
	.def	__Z25runTestOpt09_Type2_After1R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type2_After1R12dataOpt08_t2:
LFB2891:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$50000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC8, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L404:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type2_After1R12dataOpt08_t2
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L404
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2891:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type2_After2R12dataOpt08_t2
	.def	__Z25runTestOpt09_Type2_After2R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type2_After2R12dataOpt08_t2:
LFB2892:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$50000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC9, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L408:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type2_After2R12dataOpt08_t2
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L408
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2892:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type2_After3R12dataOpt08_t2
	.def	__Z25runTestOpt09_Type2_After3R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type2_After3R12dataOpt08_t2:
LFB2893:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$50000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC10, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L412:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type2_After3R12dataOpt08_t2
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L412
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2893:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type2_After4R12dataOpt08_t2
	.def	__Z25runTestOpt09_Type2_After4R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type2_After4R12dataOpt08_t2:
LFB2894:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$50000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC11, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L416:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type2_After4R12dataOpt08_t2
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L416
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2894:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type2_After5R12dataOpt08_t2
	.def	__Z25runTestOpt09_Type2_After5R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type2_After5R12dataOpt08_t2:
LFB2895:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$50000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC99, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L420:
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type2_After5R12dataOpt08_t2
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L420
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2895:
	.p2align 4,,15
	.globl	__Z27runTestOpt09_Type2_AppendixR12dataOpt08_t2
	.def	__Z27runTestOpt09_Type2_AppendixR12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z27runTestOpt09_Type2_AppendixR12dataOpt08_t2:
LFB2896:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$50000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC12, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L424:
	movl	%esi, (%esp)
	call	__Z24testOpt09_Type2_AppendixR12dataOpt08_t2
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L424
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2896:
	.p2align 4,,15
	.globl	__Z18runTestOpt09_Type3v
	.def	__Z18runTestOpt09_Type3v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt09_Type3v:
LFB2897:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$480024, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_def_cfa_offset 480032
	leal	16(%esp), %ebx
	movl	$50000, 4(%esp)
	movl	$LC18, (%esp)
	call	_printf
	movl	%ebx, (%esp)
	call	__Z12initOpt08_t2R12dataOpt08_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type3_BeforeR12dataOpt08_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type3_After1R12dataOpt08_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type3_After2R12dataOpt08_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type3_After3R12dataOpt08_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type3_After4R12dataOpt08_t2
	movl	%ebx, (%esp)
	call	__Z25runTestOpt09_Type3_After5R12dataOpt08_t2
	addl	$480024, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2897:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type3_BeforeR12dataOpt08_t2
	.def	__Z25runTestOpt09_Type3_BeforeR12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type3_BeforeR12dataOpt08_t2:
LFB2898:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$50000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC6, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L430:
	movl	$10000, 4(%esp)
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type3_BeforePN12dataOpt08_t26elem_tEj
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L430
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2898:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type3_After1R12dataOpt08_t2
	.def	__Z25runTestOpt09_Type3_After1R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type3_After1R12dataOpt08_t2:
LFB2899:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$50000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC8, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L434:
	movl	$10000, 4(%esp)
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type3_After1PN12dataOpt08_t26elem_tEj
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L434
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2899:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type3_After2R12dataOpt08_t2
	.def	__Z25runTestOpt09_Type3_After2R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type3_After2R12dataOpt08_t2:
LFB2900:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$50000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC9, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L438:
	movl	$10000, 4(%esp)
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type3_After2PN12dataOpt08_t26elem_tEj
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L438
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2900:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type3_After3R12dataOpt08_t2
	.def	__Z25runTestOpt09_Type3_After3R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type3_After3R12dataOpt08_t2:
LFB2901:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$50000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC10, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L442:
	movl	$10000, 4(%esp)
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type3_After3PN12dataOpt08_t26elem_tEj
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L442
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2901:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type3_After4R12dataOpt08_t2
	.def	__Z25runTestOpt09_Type3_After4R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type3_After4R12dataOpt08_t2:
LFB2902:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$50000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC11, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L446:
	movl	$10000, 4(%esp)
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type3_After4PN12dataOpt08_t26elem_tEj
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L446
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2902:
	.p2align 4,,15
	.globl	__Z25runTestOpt09_Type3_After5R12dataOpt08_t2
	.def	__Z25runTestOpt09_Type3_After5R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
__Z25runTestOpt09_Type3_After5R12dataOpt08_t2:
LFB2903:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$50000, %ebx
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	movl	$LC99, (%esp)
	movl	48(%esp), %esi
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	.p2align 4,,7
L450:
	movl	$10000, 4(%esp)
	movl	%esi, (%esp)
	call	__Z22testOpt09_Type3_After5PN12dataOpt08_t26elem_tEj
	subl	$1, %ebx
	movl	%eax, %edi
	jne	L450
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC1, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC0
	fstpl	4(%esp)
	call	_printf
	movl	%edi, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2903:
	.section .rdata,"dr"
	.align 4
LC100:
	.ascii "[Test for Lambda with closure]\0"
LC101:
	.ascii "Call lambda in main().\0"
	.text
	.p2align 4,,15
	.globl	__Z14testForClosurev
	.def	__Z14testForClosurev;	.scl	2;	.type	32;	.endef
__Z14testForClosurev:
LFB2904:
	.cfi_startproc
	subl	$44, %esp
	.cfi_def_cfa_offset 48
	movl	$LC3, (%esp)
	call	_puts
	movl	$LC100, (%esp)
	call	_puts
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	movl	$0, 28(%esp)
	call	__Z9setLambdaRi
	movl	$LC101, (%esp)
	call	_puts
	call	__Z12callLambda13v
	call	__Z12callLambda13v
	.p2align 4,,5
	call	__Z12callLambda13v
	addl	$44, %esp
	.cfi_def_cfa_offset 4
	.p2align 4,,2
	ret
	.cfi_endproc
LFE2904:
	.section	.text$_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	.def	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv;	.scl	2;	.type	32;	.endef
__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv:
LFB2984:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	movl	48(%esp), %edx
	movl	2496(%edx), %eax
	cmpl	$623, %eax
	ja	L455
	leal	1(%eax), %ecx
	movl	(%edx,%eax,4), %eax
L456:
	movl	%ecx, 2496(%edx)
	movl	%eax, %edx
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	shrl	$11, %edx
	xorl	%eax, %edx
	movl	%edx, %eax
	sall	$7, %eax
	andl	$-1658038656, %eax
	xorl	%edx, %eax
	movl	%eax, %edx
	sall	$15, %edx
	andl	$-272236544, %edx
	xorl	%eax, %edx
	movl	%edx, %eax
	shrl	$18, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	xorl	%edx, %eax
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L455:
	.cfi_restore_state
	movl	%edx, %eax
	andl	$15, %eax
	shrl	$2, %eax
	negl	%eax
	andl	$3, %eax
	je	L472
	movl	4(%edx), %esi
	movl	(%edx), %ecx
	movl	%esi, %ebx
	andl	$-2147483648, %ecx
	andl	$2147483647, %ebx
	orl	%ecx, %ebx
	movl	%ebx, %ecx
	andl	$1, %ecx
	negl	%ecx
	andl	$-1727483681, %ecx
	xorl	1588(%edx), %ecx
	shrl	%ebx
	xorl	%ebx, %ecx
	cmpl	$1, %eax
	movl	%ecx, (%edx)
	jbe	L473
	movl	8(%edx), %edi
	andl	$-2147483648, %esi
	movl	%edi, %ebx
	andl	$2147483647, %ebx
	orl	%esi, %ebx
	movl	%ebx, %ecx
	andl	$1, %ecx
	negl	%ecx
	andl	$-1727483681, %ecx
	xorl	1592(%edx), %ecx
	shrl	%ebx
	xorl	%ebx, %ecx
	cmpl	$2, %eax
	movl	%ecx, 4(%edx)
	jbe	L474
	movl	12(%edx), %ebx
	andl	$-2147483648, %edi
	movl	$3, %ebp
	movl	$224, (%esp)
	andl	$2147483647, %ebx
	orl	%edi, %ebx
	movl	%ebx, %ecx
	andl	$1, %ecx
	negl	%ecx
	andl	$-1727483681, %ecx
	xorl	1596(%edx), %ecx
	shrl	%ebx
	xorl	%ebx, %ecx
	movl	%ecx, 8(%edx)
L457:
	movl	$227, 4(%esp)
	xorl	%ecx, %ecx
	movdqa	LC102, %xmm2
	subl	%eax, 4(%esp)
	movdqa	LC103, %xmm3
	movdqa	LC104, %xmm4
	sall	$2, %eax
	movdqa	LC105, %xmm5
	pxor	%xmm6, %xmm6
	leal	(%edx,%eax), %ebx
	leal	4(%edx,%eax), %edi
	leal	1588(%edx,%eax), %esi
	xorl	%eax, %eax
	.p2align 4,,7
L463:
	movdqu	(%edi,%eax), %xmm1
	movdqa	(%ebx,%eax), %xmm0
	pand	%xmm2, %xmm1
	pand	%xmm3, %xmm0
	addl	$1, %ecx
	por	%xmm0, %xmm1
	movdqa	%xmm1, %xmm0
	psrld	$1, %xmm1
	movdqu	(%esi,%eax), %xmm7
	pand	%xmm4, %xmm0
	pcmpeqd	%xmm6, %xmm0
	pandn	%xmm5, %xmm0
	pxor	%xmm7, %xmm0
	pxor	%xmm1, %xmm0
	movdqa	%xmm0, (%ebx,%eax)
	addl	$16, %eax
	cmpl	$55, %ecx
	jbe	L463
	cmpl	$224, 4(%esp)
	leal	224(%ebp), %eax
	je	L461
	leal	225(%ebp), %ebx
	leal	(%edx,%eax,4), %edi
	movl	(%edx,%ebx,4), %eax
	movl	(%edi), %ecx
	movl	%eax, %esi
	andl	$-2147483648, %ecx
	andl	$2147483647, %esi
	orl	%ecx, %esi
	movl	%esi, %ecx
	andl	$1, %ecx
	negl	%ecx
	andl	$-1727483681, %ecx
	xorl	2484(%edx,%ebp,4), %ecx
	shrl	%esi
	xorl	%esi, %ecx
	cmpl	$225, (%esp)
	movl	%ecx, (%edi)
	je	L461
	leal	226(%ebp), %edi
	andl	$-2147483648, %eax
	movl	(%edx,%edi,4), %esi
	movl	%esi, %ecx
	andl	$2147483647, %ecx
	orl	%eax, %ecx
	movl	%ecx, %eax
	andl	$1, %eax
	negl	%eax
	andl	$-1727483681, %eax
	xorl	2488(%edx,%ebp,4), %eax
	shrl	%ecx
	xorl	%ecx, %eax
	cmpl	$226, (%esp)
	movl	%eax, (%edx,%ebx,4)
	je	L461
	movl	908(%edx,%ebp,4), %ecx
	andl	$-2147483648, %esi
	andl	$2147483647, %ecx
	orl	%esi, %ecx
	movl	%ecx, %eax
	andl	$1, %eax
	negl	%eax
	andl	$-1727483681, %eax
	xorl	2492(%edx,%ebp,4), %eax
	shrl	%ecx
	xorl	%ecx, %eax
	movl	%eax, (%edx,%edi,4)
L461:
	leal	908(%edx), %eax
	andl	$15, %eax
	shrl	$2, %eax
	negl	%eax
	andl	$3, %eax
	je	L475
	movl	912(%edx), %esi
	movl	908(%edx), %ecx
	movl	%esi, %ebx
	andl	$-2147483648, %ecx
	andl	$2147483647, %ebx
	orl	%ecx, %ebx
	movl	%ebx, %ecx
	andl	$1, %ecx
	negl	%ecx
	andl	$-1727483681, %ecx
	xorl	(%edx), %ecx
	shrl	%ebx
	xorl	%ebx, %ecx
	cmpl	$1, %eax
	movl	%ecx, 908(%edx)
	jbe	L476
	movl	916(%edx), %edi
	andl	$-2147483648, %esi
	movl	%edi, %ebx
	andl	$2147483647, %ebx
	orl	%esi, %ebx
	movl	%ebx, %ecx
	andl	$1, %ecx
	negl	%ecx
	andl	$-1727483681, %ecx
	xorl	4(%edx), %ecx
	shrl	%ebx
	xorl	%ebx, %ecx
	cmpl	$2, %eax
	movl	%ecx, 912(%edx)
	jbe	L477
	movl	920(%edx), %ebx
	andl	$-2147483648, %edi
	movl	$393, 4(%esp)
	movl	$230, 8(%esp)
	andl	$2147483647, %ebx
	orl	%edi, %ebx
	movl	%ebx, %ecx
	andl	$1, %ecx
	negl	%ecx
	andl	$-1727483681, %ecx
	xorl	8(%edx), %ecx
	shrl	%ebx
	xorl	%ebx, %ecx
	movl	%ecx, 916(%edx)
L464:
	movl	$396, (%esp)
	xorl	%ecx, %ecx
	pxor	%xmm6, %xmm6
	subl	%eax, (%esp)
	movl	(%esp), %esi
	leal	908(,%eax,4), %eax
	leal	(%edx,%eax), %ebx
	leal	4(%edx,%eax), %ebp
	shrl	$2, %esi
	leal	0(,%esi,4), %edi
	movl	%edi, 12(%esp)
	leal	-908(%edx,%eax), %edi
	xorl	%eax, %eax
	.p2align 4,,7
L470:
	movdqu	0(%ebp,%eax), %xmm1
	movdqa	(%ebx,%eax), %xmm0
	pand	%xmm2, %xmm1
	pand	%xmm3, %xmm0
	addl	$1, %ecx
	por	%xmm0, %xmm1
	movdqa	%xmm1, %xmm0
	psrld	$1, %xmm1
	movdqu	(%edi,%eax), %xmm7
	pand	%xmm4, %xmm0
	pcmpeqd	%xmm6, %xmm0
	pandn	%xmm5, %xmm0
	pxor	%xmm7, %xmm0
	pxor	%xmm1, %xmm0
	movdqa	%xmm0, (%ebx,%eax)
	addl	$16, %eax
	cmpl	%ecx, %esi
	ja	L470
	movl	12(%esp), %edi
	movl	4(%esp), %eax
	movl	8(%esp), %ecx
	movl	(%esp), %esi
	subl	%edi, %eax
	addl	%edi, %ecx
	cmpl	%esi, %edi
	movl	%eax, 4(%esp)
	je	L468
	leal	1(%ecx), %esi
	leal	(%edx,%ecx,4), %ebp
	movl	(%edx,%esi,4), %eax
	movl	0(%ebp), %ebx
	movl	%eax, %edi
	andl	$-2147483648, %ebx
	andl	$2147483647, %edi
	orl	%ebx, %edi
	movl	%edi, %ebx
	andl	$1, %ebx
	negl	%ebx
	andl	$-1727483681, %ebx
	xorl	-908(%edx,%ecx,4), %ebx
	shrl	%edi
	xorl	%edi, %ebx
	cmpl	$1, 4(%esp)
	movl	%ebx, 0(%ebp)
	je	L468
	leal	2(%ecx), %ebp
	andl	$-2147483648, %eax
	movl	(%edx,%ebp,4), %edi
	movl	%edi, %ebx
	andl	$2147483647, %ebx
	orl	%eax, %ebx
	movl	%ebx, %eax
	andl	$1, %eax
	negl	%eax
	andl	$-1727483681, %eax
	xorl	-904(%edx,%ecx,4), %eax
	shrl	%ebx
	xorl	%ebx, %eax
	cmpl	$2, 4(%esp)
	movl	%eax, (%edx,%esi,4)
	je	L468
	movl	12(%edx,%ecx,4), %ebx
	andl	$-2147483648, %edi
	andl	$2147483647, %ebx
	orl	%edi, %ebx
	movl	%ebx, %eax
	andl	$1, %eax
	negl	%eax
	andl	$-1727483681, %eax
	xorl	-900(%edx,%ecx,4), %eax
	shrl	%ebx
	xorl	%ebx, %eax
	movl	%eax, (%edx,%ebp,4)
L468:
	movl	(%edx), %eax
	movl	2492(%edx), %ecx
	movl	%eax, %ebx
	andl	$-2147483648, %ecx
	andl	$2147483647, %ebx
	orl	%ecx, %ebx
	movl	%ebx, %ecx
	andl	$1, %ebx
	shrl	%ecx
	negl	%ebx
	xorl	1584(%edx), %ecx
	andl	$-1727483681, %ebx
	xorl	%ebx, %ecx
	movl	%ecx, 2492(%edx)
	movl	$1, %ecx
	jmp	L456
	.p2align 4,,7
L474:
	movl	$225, (%esp)
	movl	$2, %ebp
	jmp	L457
	.p2align 4,,7
L473:
	movl	$226, (%esp)
	movl	$1, %ebp
	jmp	L457
	.p2align 4,,7
L472:
	movl	$227, (%esp)
	xorl	%ebp, %ebp
	jmp	L457
	.p2align 4,,7
L475:
	movl	$396, 4(%esp)
	movl	$227, 8(%esp)
	jmp	L464
	.p2align 4,,7
L477:
	movl	$394, 4(%esp)
	movl	$229, 8(%esp)
	jmp	L464
	.p2align 4,,7
L476:
	movl	$395, 4(%esp)
	movl	$228, 8(%esp)
	jmp	L464
	.cfi_endproc
LFE2984:
	.section .rdata,"dr"
LC106:
	.ascii "[Optimize Test 06]\0"
	.text
	.p2align 4,,15
	.globl	__Z12runTestOpt06v
	.def	__Z12runTestOpt06v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt06v:
LFB2807:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$82572, %eax
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	call	___chkstk_ms
	movl	$5489, %ebx
	movl	$440509467, %ebp
	subl	%eax, %esp
	.cfi_def_cfa_offset 82592
	movl	$LC3, (%esp)
	leal	2560(%esp), %edi
	call	_puts
	leal	48(%esp), %esi
	movl	$LC106, (%esp)
	call	_puts
	movl	%edi, (%esp)
	call	__Z9initOpt06R11dataOpt06_t
	movl	$1, %ecx
	movl	$5489, 48(%esp)
	.p2align 4,,7
L495:
	movl	%ebx, %eax
	movl	%ecx, %edx
	shrl	$30, %eax
	xorl	%ebx, %eax
	shrl	$4, %edx
	imull	$1812433253, %eax, %ebx
	movl	%edx, %eax
	mull	%ebp
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	addl	%eax, %ebx
	movl	%ebx, (%esi,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L495
	movl	%esi, (%esp)
	movl	$624, 2544(%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	movl	%esi, (%esp)
	movl	%eax, 28(%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	movl	%esi, (%esp)
	movl	%eax, 32(%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	movd	32(%esp), %xmm1
	movd	28(%esp), %xmm2
	movl	%edi, (%esp)
	movl	%eax, 36(%esp)
	movd	36(%esp), %xmm0
	movq	%xmm0, 40(%esp)
	fildq	40(%esp)
	fldz
	movq	%xmm1, 40(%esp)
	fadd	%st, %st(1)
	flds	LC107
	fmul	%st, %st(2)
	flds	LC108
	fmul	%st, %st(3)
	fxch	%st(3)
	fadd	%st(2), %st
	fstps	12(%esp)
	fildq	40(%esp)
	movq	%xmm2, 40(%esp)
	fadd	%st(2), %st
	fmul	%st(1), %st
	fmul	%st(3), %st
	fadd	%st(2), %st
	fstps	8(%esp)
	fildq	40(%esp)
	fadd	%st(2), %st
	fmulp	%st, %st(1)
	fmulp	%st, %st(2)
	faddp	%st, %st(1)
	fstps	4(%esp)
	call	__Z18runTestOpt06_Type1R11dataOpt06_tfff
	addl	$82572, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2807:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB2905:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	call	___main
	call	__Z12runTestOpt01v
	call	__Z12runTestOpt02v
	.p2align 4,,5
	call	__Z12runTestOpt03v
	.p2align 4,,5
	call	__Z12runTestOpt04v
	.p2align 4,,5
	call	__Z12runTestOpt05v
	.p2align 4,,5
	call	__Z12runTestOpt06v
	.p2align 4,,5
	call	__Z12runTestOpt07v
	.p2align 4,,5
	call	__Z12runTestOpt08v
	.p2align 4,,5
	call	__Z12runTestOpt09v
	.p2align 4,,5
	call	__Z14testForClosurev
	xorl	%eax, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	.p2align 4,,2
	ret
	.cfi_endproc
LFE2905:
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt03_Type1v
	.def	__Z18runTestOpt03_Type1v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt03_Type1v:
LFB2782:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	movl	$5489, %edx
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	movl	$1, %ecx
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$440509467, %esi
	subl	$2528, %esp
	.cfi_def_cfa_offset 2544
	movl	$5489, 16(%esp)
	leal	16(%esp), %ebx
	.p2align 4,,7
L501:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L501
	movl	$624, 2512(%esp)
	.p2align 4,,7
L503:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L503
	movl	$671088641, %esi
	mull	%esi
	movl	%edx, %esi
	shrl	$26, %esi
	.p2align 4,,7
L505:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L505
	movl	$671088641, %ebx
	mull	%ebx
	movl	$100000000, 4(%esp)
	movl	$LC5, (%esp)
	movl	%edx, %ebx
	shrl	$26, %ebx
	call	_printf
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt03_Type1_Beforeii
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
	call	__Z24runTestOpt03_Type1_Afterii
	addl	$2528, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2782:
	.p2align 4,,15
	.globl	__Z18runTestOpt03_Type2v
	.def	__Z18runTestOpt03_Type2v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt03_Type2v:
LFB2786:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$5489, %edx
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	$1, %ebx
	subl	$2572, %esp
	.cfi_def_cfa_offset 2592
	movl	$5489, 48(%esp)
	leal	48(%esp), %ebp
	.p2align 4,,7
L509:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ebx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %ecx
	movl	%edx, %eax
	mull	%esi
	movl	%ebx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%ecx, %edx
	movl	%edx, 0(%ebp,%ebx,4)
	addl	$1, %ebx
	cmpl	$624, %ebx
	jne	L509
	movl	$624, 2544(%esp)
	.p2align 4,,7
L511:
	movl	%ebp, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L511
	movl	$671088641, %edx
	mull	%edx
	movl	%edx, 32(%esp)
	shrl	$26, 32(%esp)
	.p2align 4,,7
L513:
	movl	%ebp, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L513
	movl	$671088641, %edx
	mull	%edx
	movl	%edx, 36(%esp)
	shrl	$26, 36(%esp)
	.p2align 4,,7
L515:
	movl	%ebp, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L515
	movl	$671088641, %ebx
	mull	%ebx
	movl	%edx, %ebx
	shrl	$26, %ebx
	.p2align 4,,7
L517:
	movl	%ebp, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L517
	movl	$671088641, %esi
	mull	%esi
	movl	%edx, %esi
	shrl	$26, %esi
	.p2align 4,,7
L519:
	movl	%ebp, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L519
	movl	$671088641, %edx
	mull	%edx
	movl	%edx, %edi
	shrl	$26, %edi
	.p2align 4,,7
L521:
	movl	%ebp, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L521
	movl	$671088641, %edx
	mull	%edx
	movl	%edx, 40(%esp)
	shrl	$26, 40(%esp)
	.p2align 4,,7
L523:
	movl	%ebp, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-7, %eax
	ja	L523
	movl	$671088641, %edx
	mull	%edx
	movl	$100000000, 4(%esp)
	movl	$LC26, (%esp)
	shrl	$26, %edx
	movl	%edx, 44(%esp)
	call	_printf
	movl	40(%esp), %ebp
	movl	44(%esp), %edx
	movl	36(%esp), %eax
	movl	32(%esp), %ecx
	movl	%ebp, 20(%esp)
	movl	%edx, 24(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%ecx, (%esp)
	call	__Z25runTestOpt03_Type2_Beforeiiiiiii
	movl	44(%esp), %edx
	movl	36(%esp), %eax
	movl	32(%esp), %ecx
	movl	%ebp, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%edx, 24(%esp)
	movl	%eax, 4(%esp)
	movl	%ecx, (%esp)
	call	__Z24runTestOpt03_Type2_Afteriiiiiii
	addl	$2572, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2786:
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type2v
	.def	__Z18runTestOpt08_Type2v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type2v:
LFB2847:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$100000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC26, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L527:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L527
	movl	$624, 2512(%esp)
	.p2align 4,,7
L529:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L529
	movl	$-1778384781, %esi
	mull	%esi
	movl	%edx, %esi
	shrl	$23, %esi
	.p2align 4,,7
L531:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L531
	movl	$-1778384781, %edi
	mull	%edi
	movl	%edx, %edi
	shrl	$23, %edi
	.p2align 4,,7
L533:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L533
	movl	$-1778384781, %ebp
	mull	%ebp
	movl	%edx, %ebp
	shrl	$23, %ebp
	.p2align 4,,7
L535:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L535
	movl	$-1778384781, %ebx
	mull	%ebx
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	movl	%edx, %ebx
	shrl	$23, %ebx
	movl	%ebx, 12(%esp)
	call	__Z25runTestOpt08_Type2_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type2_After1iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type2_After2iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type2_After3iiii
	addl	$2540, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2847:
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type3v
	.def	__Z18runTestOpt08_Type3v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type3v:
LFB2852:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$100000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC18, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L539:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L539
	movl	$624, 2512(%esp)
	.p2align 4,,7
L541:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-97, %eax
	ja	L541
	shrl	$2, %eax
	movl	$838860819, %edx
	mull	%edx
	movl	%edx, %esi
	shrl	$20, %esi
	.p2align 4,,7
L543:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-97, %eax
	ja	L543
	shrl	$2, %eax
	movl	$838860819, %edx
	mull	%edx
	movl	%edx, %edi
	shrl	$20, %edi
	.p2align 4,,7
L545:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-97, %eax
	ja	L545
	shrl	$2, %eax
	movl	$838860819, %edx
	mull	%edx
	movl	%edx, %ebp
	shrl	$20, %ebp
	.p2align 4,,7
L547:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-97, %eax
	ja	L547
	shrl	$2, %eax
	movl	$838860819, %edx
	mull	%edx
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	movl	%edx, %ebx
	shrl	$20, %ebx
	movl	%ebx, 12(%esp)
	call	__Z25runTestOpt08_Type3_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z24runTestOpt08_Type3_Afteriiii
	addl	$2540, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2852:
	.section .rdata,"dr"
LC109:
	.ascii "Type7: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type7v
	.def	__Z18runTestOpt08_Type7v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type7v:
LFB2867:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$10000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC109, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L551:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L551
	movl	$624, 2512(%esp)
	.p2align 4,,7
L553:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L553
	leal	-1(%eax), %esi
	.p2align 4,,7
L555:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L555
	leal	-1(%eax), %edi
	.p2align 4,,7
L559:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L559
	leal	-1(%eax), %ebp
	.p2align 4,,7
L560:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L560
	leal	-1(%eax), %ebx
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type7_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type7_After1iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type7_After2iiii
	addl	$2540, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2867:
	.section .rdata,"dr"
LC110:
	.ascii "Type4: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type4v
	.def	__Z18runTestOpt08_Type4v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type4v:
LFB2855:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$100000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC110, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L566:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L566
	movl	$624, 2512(%esp)
	.p2align 4,,7
L568:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-1022, %eax
	ja	L568
	movl	$-2145385985, %esi
	mull	%esi
	movl	%edx, %esi
	shrl	$21, %esi
	.p2align 4,,7
L570:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-1022, %eax
	ja	L570
	movl	$-2145385985, %edi
	mull	%edi
	movl	%edx, %edi
	shrl	$21, %edi
	.p2align 4,,7
L572:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-1022, %eax
	ja	L572
	movl	$-2145385985, %ebp
	mull	%ebp
	movl	%edx, %ebp
	shrl	$21, %ebp
	.p2align 4,,7
L574:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-1022, %eax
	ja	L574
	movl	$-2145385985, %ebx
	mull	%ebx
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	movl	%edx, %ebx
	shrl	$21, %ebx
	movl	%ebx, 12(%esp)
	call	__Z25runTestOpt08_Type4_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type4_After1iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type4_After2iiii
	addl	$2540, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2855:
	.section .rdata,"dr"
LC111:
	.ascii "Type5: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type5v
	.def	__Z18runTestOpt08_Type5v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type5v:
LFB2859:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$10000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC111, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L578:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L578
	movl	$624, 2512(%esp)
	.p2align 4,,7
L580:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L580
	leal	-1(%eax), %esi
	.p2align 4,,7
L582:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L582
	leal	-1(%eax), %edi
	.p2align 4,,7
L586:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L586
	leal	-1(%eax), %ebp
	.p2align 4,,7
L587:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L587
	leal	-1(%eax), %ebx
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type5_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type5_After1iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type5_After2iiii
	addl	$2540, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2859:
	.section .rdata,"dr"
LC112:
	.ascii "Type6: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type6v
	.def	__Z18runTestOpt08_Type6v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type6v:
LFB2863:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$10000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC112, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L593:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L593
	movl	$624, 2512(%esp)
	.p2align 4,,7
L595:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L595
	leal	-1(%eax), %esi
	.p2align 4,,7
L597:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L597
	leal	-1(%eax), %edi
	.p2align 4,,7
L601:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L601
	leal	-1(%eax), %ebp
	.p2align 4,,7
L602:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-2147483648, %eax
	ja	L602
	leal	-1(%eax), %ebx
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type6_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type6_After1iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type6_After2iiii
	addl	$2540, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2863:
	.section .rdata,"dr"
LC113:
	.ascii "Type9: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type9v
	.def	__Z18runTestOpt08_Type9v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type9v:
LFB2875:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$100000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC113, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L608:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L608
	movl	$624, 2512(%esp)
	.p2align 4,,7
L610:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L610
	movl	$-922746801, %edx
	mull	%edx
	shrl	$24, %edx
	leal	-100(%edx), %esi
	.p2align 4,,7
L612:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L612
	movl	$-922746801, %edx
	mull	%edx
	shrl	$24, %edx
	leal	-100(%edx), %edi
	.p2align 4,,7
L614:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L614
	movl	$-922746801, %edx
	mull	%edx
	shrl	$24, %edx
	leal	-100(%edx), %ebp
	.p2align 4,,7
L616:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L616
	movl	$-922746801, %edx
	mull	%edx
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	shrl	$24, %edx
	leal	-100(%edx), %ebx
	movl	%ebx, 12(%esp)
	call	__Z25runTestOpt08_Type9_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type9_After1iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type9_After2iiii
	addl	$2540, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2875:
	.section .rdata,"dr"
LC114:
	.ascii "Type8: *%d times repeated.\12\0"
	.text
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type8v
	.def	__Z18runTestOpt08_Type8v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type8v:
LFB2871:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$100000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC114, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L620:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L620
	movl	$624, 2512(%esp)
	.p2align 4,,7
L622:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L622
	movl	$-922746801, %edx
	mull	%edx
	shrl	$24, %edx
	leal	-100(%edx), %esi
	.p2align 4,,7
L624:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L624
	movl	$-922746801, %edx
	mull	%edx
	shrl	$24, %edx
	leal	-100(%edx), %edi
	.p2align 4,,7
L626:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L626
	movl	$-922746801, %edx
	mull	%edx
	shrl	$24, %edx
	leal	-100(%edx), %ebp
	.p2align 4,,7
L628:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-101, %eax
	ja	L628
	movl	$-922746801, %edx
	mull	%edx
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	shrl	$24, %edx
	leal	-100(%edx), %ebx
	movl	%ebx, 12(%esp)
	call	__Z25runTestOpt08_Type8_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type8_After1iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type8_After2iiii
	addl	$2540, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2871:
	.p2align 4,,15
	.globl	__Z18runTestOpt08_Type1v
	.def	__Z18runTestOpt08_Type1v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt08_Type1v:
LFB2842:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$440509467, %esi
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$2540, %esp
	.cfi_def_cfa_offset 2560
	movl	$100000000, 4(%esp)
	leal	16(%esp), %ebx
	movl	$LC5, (%esp)
	call	_printf
	movl	$5489, %edx
	movl	$1, %ecx
	movl	$5489, 16(%esp)
	.p2align 4,,7
L632:
	movl	%edx, %eax
	shrl	$30, %eax
	xorl	%edx, %eax
	movl	%ecx, %edx
	shrl	$4, %edx
	imull	$1812433253, %eax, %edi
	movl	%edx, %eax
	mull	%esi
	movl	%ecx, %eax
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	addl	%edi, %edx
	movl	%edx, (%ebx,%ecx,4)
	addl	$1, %ecx
	cmpl	$624, %ecx
	jne	L632
	movl	$624, 2512(%esp)
	.p2align 4,,7
L634:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L634
	movl	$-1778384781, %esi
	mull	%esi
	movl	%edx, %esi
	shrl	$23, %esi
	.p2align 4,,7
L636:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L636
	movl	$-1778384781, %edi
	mull	%edi
	movl	%edx, %edi
	shrl	$23, %edi
	.p2align 4,,7
L638:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L638
	movl	$-1778384781, %ebp
	mull	%ebp
	movl	%edx, %ebp
	shrl	$23, %ebp
	.p2align 4,,7
L640:
	movl	%ebx, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	cmpl	$-197, %eax
	ja	L640
	movl	$-1778384781, %ebx
	mull	%ebx
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	movl	%edx, %ebx
	shrl	$23, %ebx
	movl	%ebx, 12(%esp)
	call	__Z25runTestOpt08_Type1_Beforeiiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type1_After1iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type1_After2iiii
	movl	%ebx, 12(%esp)
	movl	%ebp, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	__Z25runTestOpt08_Type1_After3iiii
	addl	$2540, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2842:
	.section .rdata,"dr"
	.align 4
LC0:
	.long	1315859240
	.align 16
LC15:
	.long	0
	.long	1
	.long	2
	.long	3
	.align 16
LC17:
	.long	4
	.long	4
	.long	4
	.long	4
	.align 4
LC27:
	.long	1120403456
	.align 16
LC102:
	.long	2147483647
	.long	2147483647
	.long	2147483647
	.long	2147483647
	.align 16
LC103:
	.long	-2147483648
	.long	-2147483648
	.long	-2147483648
	.long	-2147483648
	.align 16
LC104:
	.long	1
	.long	1
	.long	1
	.long	1
	.align 16
LC105:
	.long	-1727483681
	.long	-1727483681
	.long	-1727483681
	.long	-1727483681
	.align 4
LC107:
	.long	796917760
	.align 4
LC108:
	.long	1092616192
	.ident	"GCC: (GNU) 4.8.2"
	.def	__ZNSt6chrono3_V212system_clock3nowEv;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	__Z9initOpt01R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt01_Type1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt01_Type1_BeforeR11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt01_Type1_After1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt01_Type1_After2R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt01_Type1_After3R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt01_Type1_After4R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z24testOpt01_Type1_AppendixR11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt01_Type1_BeforeR11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt01_Type1_After1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt01_Type1_After2R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt01_Type1_After3R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt01_Type1_After4R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z27runTestOpt01_Type1_AppendixR11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z9initOpt02R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt02_Type1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt02_Type1_BeforeR11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt02_Type1_After1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt02_Type1_After2R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt02_Type1_After3R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt02_Type1_BeforeR11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt02_Type1_After1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt02_Type1_After2R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt02_Type1_After3R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt03_Type1v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt03_Type2v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt03_Type3v;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt03_Type1_Beforeiii;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt03_Type2_Beforeiiiiiiii;	.scl	2;	.type	32;	.endef
	.def	__Z15initOpt03_Type3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt03_Type3_BeforeR11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt03_Type3_After1R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt03_Type3_After2R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt03_Type3_After3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z25testOpt03_Type3_Appendix1R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z25testOpt03_Type3_Appendix2R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z25testOpt03_Type3_Appendix3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt03_Type3_BeforeR11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt03_Type3_After1R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt03_Type3_After2R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt03_Type3_After3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z28runTestOpt03_Type3_Appendix1R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z28runTestOpt03_Type3_Appendix2R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z28runTestOpt03_Type3_Appendix3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z9initOpt04R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt04_Type1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type1_BeforeR11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type1_After1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type1_After2R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt04_Type1_BeforeR11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt04_Type1_After1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt04_Type1_After2R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt05_Type1v;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt05_Type1_Beforev;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt05_Type1_Afterv;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt05_Type1_BeforeiRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_;	.scl	2;	.type	32;	.endef
	.def	__Z21testOpt05_Type1_AfteriRiS_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_S_;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt06_Type1_BeforeR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt06_Type1_AfterR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt06_Type1_BeforeR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
	.def	__Z21testOpt06_Type1_AfterR11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt07_Type1v;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt07_Type2_strlenv;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt07_Type2_strcmpv;	.scl	2;	.type	32;	.endef
	.def	__Z26runTestOpt07_Type2_strncmpv;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt07_Type2_strchrv;	.scl	2;	.type	32;	.endef
	.def	__Z26runTestOpt07_Type2_strrchrv;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt07_Type2_strstrv;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt07_Type2_strcpyv;	.scl	2;	.type	32;	.endef
	.def	__Z26runTestOpt07_Type2_strncpyv;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt07_Type1_Beforev;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt07_Type1_Afterv;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt07_Type1_BeforeILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt07_Type1_BeforeILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
	.def	__Z21testOpt07_Type1_AfterILj4ELj4ELj4EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
	.def	__Z21testOpt07_Type1_AfterILj1ELj4ELj3EEviR6matrixIXT_EXT0_EES2_S2_RKS1_S4_S4_fRKS0_IXT_EXT1_EERKS0_IXT1_EXT0_EE;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strlen_BeforePKcS0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
	.def	__Z31runTestOpt07_Type2_strlen_AfterPKcS0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strlen_BeforeiPKc;	.scl	2;	.type	32;	.endef
	.def	__Z28testOpt07_Type2_strlen_AfteriPKc;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strcmp_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
	.def	__Z31runTestOpt07_Type2_strcmp_AfterPKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strcmp_BeforeiPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z28testOpt07_Type2_strcmp_AfteriPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z33runTestOpt07_Type2_strncmp_BeforePKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strncmp_AfterPKcS0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjjS0_S0_jjj;	.scl	2;	.type	32;	.endef
	.def	__Z30testOpt07_Type2_strncmp_BeforeiPKcS0_j;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strncmp_AfteriPKcS0_j;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strchr_BeforePKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
	.def	__Z31runTestOpt07_Type2_strchr_AfterPKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strchr_BeforeiPKcc;	.scl	2;	.type	32;	.endef
	.def	__Z28testOpt07_Type2_strchr_AfteriPKcc;	.scl	2;	.type	32;	.endef
	.def	__Z33runTestOpt07_Type2_strrchr_BeforePKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strrchr_AfterPKcccccS0_ccccS0_ccccS0_cccc;	.scl	2;	.type	32;	.endef
	.def	__Z30testOpt07_Type2_strrchr_BeforeiPKcc;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strrchr_AfteriPKcc;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strstr_BeforePKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strstr_After1PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strstr_After2PKcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strstr_BeforeiPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strstr_After1iPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strstr_After2iPKcS0_;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strcpy_BeforePcPKcS1_S1_S1_S1_;	.scl	2;	.type	32;	.endef
	.def	__Z31runTestOpt07_Type2_strcpy_AfterPcPKcS1_S1_S1_S1_;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strcpy_BeforeiPcPKc;	.scl	2;	.type	32;	.endef
	.def	__Z28testOpt07_Type2_strcpy_AfteriPcPKc;	.scl	2;	.type	32;	.endef
	.def	__Z33runTestOpt07_Type2_strncpy_BeforePcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj;	.scl	2;	.type	32;	.endef
	.def	__Z32runTestOpt07_Type2_strncpy_AfterPcPKcjjjS1_jjjS1_jjjS1_jjjS1_jjj;	.scl	2;	.type	32;	.endef
	.def	__Z30testOpt07_Type2_strncpy_BeforeiPcPKcj;	.scl	2;	.type	32;	.endef
	.def	__Z29testOpt07_Type2_strncpy_AfteriPcPKcj;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type1v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type2v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type3v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type4v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type5v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type6v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type7v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type8v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt08_Type9v;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type1_Beforei;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type1_After1i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type1_After2i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type1_After3i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type2_Beforei;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type2_After1i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type2_After2i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type2_After3i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type3_Beforeii;	.scl	2;	.type	32;	.endef
	.def	__Z21testOpt08_Type3_Afterii;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type4_Beforei;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type4_After1i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type4_After2i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type5_Beforei;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type5_After1i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type5_After2i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type6_Beforei;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type6_After1i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type6_After2i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type7_Beforei;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type7_After1i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type7_After2i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type8_Beforei;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type8_After1i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type8_After2i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type9_Beforei;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type9_After1i;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt08_Type9_After2i;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt09_Type1v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt09_Type2v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt09_Type3v;	.scl	2;	.type	32;	.endef
	.def	__Z12initOpt08_t1R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type1_BeforeR12dataOpt08_t1;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type1_After1R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type1_After2R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type1_After3R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type1_After4R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type1_After5R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
	.def	__Z27runTestOpt09_Type1_AppendixR12dataOpt08_t1;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type1_BeforeR12dataOpt08_t1;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type1_After1R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type1_After2R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type1_After3R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type1_After4R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type1_After5R12dataOpt08_t1;	.scl	2;	.type	32;	.endef
	.def	__Z24testOpt09_Type1_AppendixR12dataOpt08_t1;	.scl	2;	.type	32;	.endef
	.def	__Z12initOpt08_t2R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type2_BeforeR12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type2_After1R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type2_After2R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type2_After3R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type2_After4R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type2_After5R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z27runTestOpt09_Type2_AppendixR12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type2_BeforeR12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type2_After1R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type2_After2R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type2_After3R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type2_After4R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type2_After5R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z24testOpt09_Type2_AppendixR12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type3_BeforeR12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type3_After1R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type3_After2R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type3_After3R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type3_After4R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt09_Type3_After5R12dataOpt08_t2;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type3_BeforePN12dataOpt08_t26elem_tEj;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type3_After1PN12dataOpt08_t26elem_tEj;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type3_After2PN12dataOpt08_t26elem_tEj;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type3_After3PN12dataOpt08_t26elem_tEj;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type3_After4PN12dataOpt08_t26elem_tEj;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt09_Type3_After5PN12dataOpt08_t26elem_tEj;	.scl	2;	.type	32;	.endef
	.def	__Z9setLambdaRi;	.scl	2;	.type	32;	.endef
	.def	__Z12callLambda13v;	.scl	2;	.type	32;	.endef
	.def	__Z9initOpt06R11dataOpt06_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt06_Type1R11dataOpt06_tfff;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt03_Type1_Beforeii;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt03_Type1_Afterii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt03_Type2_Beforeiiiiiii;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt03_Type2_Afteriiiiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type2_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type2_After1iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type2_After2iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type2_After3iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type3_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt08_Type3_Afteriiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type7_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type7_After1iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type7_After2iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type4_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type4_After1iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type4_After2iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type5_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type5_After1iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type5_After2iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type6_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type6_After1iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type6_After2iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type9_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type9_After1iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type9_After2iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type8_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type8_After1iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type8_After2iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type1_Beforeiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type1_After1iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type1_After2iiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt08_Type1_After3iiii;	.scl	2;	.type	32;	.endef

	.file	"call_point.cpp"
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
	.section	.text$_ZNSt12_Base_bitsetILj1EE11_S_whichbitEj,"x"
	.linkonce discard
	.globl	__ZNSt12_Base_bitsetILj1EE11_S_whichbitEj
	.def	__ZNSt12_Base_bitsetILj1EE11_S_whichbitEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj1EE11_S_whichbitEj:
LFB773:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	andl	$31, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE773:
	.section	.text$_ZNSt12_Base_bitsetILj1EE10_S_maskbitEj,"x"
	.linkonce discard
	.globl	__ZNSt12_Base_bitsetILj1EE10_S_maskbitEj
	.def	__ZNSt12_Base_bitsetILj1EE10_S_maskbitEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj1EE10_S_maskbitEj:
LFB774:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Base_bitsetILj1EE11_S_whichbitEj
	movl	$1, %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE774:
	.section	.text$_ZNSt12_Base_bitsetILj1EE10_M_getwordEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Base_bitsetILj1EE10_M_getwordEj
	.def	__ZNSt12_Base_bitsetILj1EE10_M_getwordEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj1EE10_M_getwordEj:
LFB775:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE775:
	.section	.text$_ZNSt12_Base_bitsetILj1EE11_M_do_resetEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Base_bitsetILj1EE11_M_do_resetEv
	.def	__ZNSt12_Base_bitsetILj1EE11_M_do_resetEv;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj1EE11_M_do_resetEv:
LFB787:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE787:
	.section .rdata,"dr"
__ZStL13allocator_arg:
	.space 1
__ZStL6ignore:
	.space 1
	.section	.text$_ZN6dbgLog5color11changeColorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5color11changeColorEv
	.def	__ZN6dbgLog5color11changeColorEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5color11changeColorEv:
LFB3501:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movzbl	1(%eax), %eax
	cmpb	$32, %al
	jne	L9
	jmp	L8
L9:
	movl	8(%ebp), %eax
	movzbl	2(%eax), %eax
	movzbl	%al, %ecx
	movl	8(%ebp), %eax
	movzbl	1(%eax), %eax
	movzbl	%al, %edx
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5color11changeColorENS0_8target_tENS0_7color_tES2_
L8:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3501:
	.section .rdata,"dr"
LC0:
	.ascii "\33[39m\33[49m\0"
LC1:
	.ascii "\33[%dm\33[%dm\0"
	.section	.text$_ZN6dbgLog5color11changeColorENS0_8target_tENS0_7color_tES2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5color11changeColorENS0_8target_tENS0_7color_tES2_
	.def	__ZN6dbgLog5color11changeColorENS0_8target_tENS0_7color_tES2_;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5color11changeColorENS0_8target_tENS0_7color_tES2_:
LFB3502:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	12(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -28(%ebp)
	movb	%dl, -32(%ebp)
	movb	%al, -36(%ebp)
	movzbl	-28(%ebp), %eax
	movl	__ZN6dbgLog5color8m_handleE(,%eax,4), %eax
	movl	%eax, -12(%ebp)
	cmpb	$16, -32(%ebp)
	jne	L12
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$10, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC0, (%esp)
	call	_fwrite
	jmp	L11
L12:
	movzbl	-36(%ebp), %eax
	andl	$8, %eax
	testl	%eax, %eax
	je	L14
	movl	$100, %eax
	jmp	L15
L14:
	movl	$40, %eax
L15:
	movzbl	-36(%ebp), %edx
	andl	$7, %edx
	addl	%eax, %edx
	movzbl	-32(%ebp), %eax
	andl	$8, %eax
	testl	%eax, %eax
	je	L16
	movl	$90, %eax
	jmp	L17
L16:
	movl	$30, %eax
L17:
	movzbl	-32(%ebp), %ecx
	andl	$7, %ecx
	addl	%ecx, %eax
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
L11:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3502:
	.section	.text$_ZN6dbgLog5colorC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5colorC1Ev
	.def	__ZN6dbgLog5colorC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5colorC1Ev:
LFB3505:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movb	$0, (%eax)
	movl	8(%ebp), %eax
	movb	$16, 1(%eax)
	movl	8(%ebp), %eax
	movb	$16, 2(%eax)
	movl	8(%ebp), %eax
	movb	$16, 3(%eax)
	movl	8(%ebp), %eax
	movb	$16, 4(%eax)
	movl	8(%ebp), %eax
	movb	$0, 5(%eax)
	call	__ZN6dbgLog5color14initializeOnceEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3505:
	.section	.text$_ZN6dbgLog5colorC1EOS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5colorC1EOS0_
	.def	__ZN6dbgLog5colorC1EOS0_;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5colorC1EOS0_:
LFB3508:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	movzbl	(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, (%eax)
	movl	12(%ebp), %eax
	movzbl	1(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, 1(%eax)
	movl	12(%ebp), %eax
	movzbl	2(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, 2(%eax)
	movl	12(%ebp), %eax
	movzbl	3(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, 3(%eax)
	movl	12(%ebp), %eax
	movzbl	4(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, 4(%eax)
	movl	12(%ebp), %eax
	movzbl	5(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, 5(%eax)
	movl	12(%ebp), %eax
	addl	$5, %eax
	movb	$0, (%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3508:
	.section	.text$_ZN6dbgLog5colorC1ENS0_8target_tENS0_7color_tES2_b,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5colorC1ENS0_8target_tENS0_7color_tES2_b
	.def	__ZN6dbgLog5colorC1ENS0_8target_tENS0_7color_tES2_b;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5colorC1ENS0_8target_tENS0_7color_tES2_b:
LFB3511:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %ebx
	movl	16(%ebp), %ecx
	movl	20(%ebp), %edx
	movl	24(%ebp), %eax
	movb	%bl, -12(%ebp)
	movb	%cl, -16(%ebp)
	movb	%dl, -20(%ebp)
	movb	%al, -24(%ebp)
	movl	8(%ebp), %eax
	movzbl	-12(%ebp), %edx
	movb	%dl, (%eax)
	movl	8(%ebp), %eax
	movzbl	-16(%ebp), %edx
	movb	%dl, 1(%eax)
	movl	8(%ebp), %eax
	movzbl	-20(%ebp), %edx
	movb	%dl, 2(%eax)
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movzbl	__ZN6dbgLog5color14m_nowForeColorE(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, 3(%eax)
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movzbl	__ZN6dbgLog5color14m_nowBackColorE(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, 4(%eax)
	movl	8(%ebp), %eax
	movzbl	-24(%ebp), %edx
	movb	%dl, 5(%eax)
	movl	8(%ebp), %eax
	movzbl	1(%eax), %eax
	cmpb	$32, %al
	je	L21
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L22
L21:
	jmp	L20
L22:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movzbl	1(%edx), %edx
	movb	%dl, __ZN6dbgLog5color14m_nowForeColorE(%eax)
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movzbl	2(%edx), %edx
	movb	%dl, __ZN6dbgLog5color14m_nowBackColorE(%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5color11changeColorEv
L20:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3511:
	.section	.text$_ZN6dbgLog5colorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5colorD1Ev
	.def	__ZN6dbgLog5colorD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5colorD1Ev:
LFB3514:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3514
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movzbl	1(%eax), %eax
	cmpb	$32, %al
	je	L24
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	jne	L24
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movzbl	3(%edx), %edx
	movb	%dl, __ZN6dbgLog5color14m_nowForeColorE(%eax)
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movzbl	4(%edx), %edx
	movb	%dl, __ZN6dbgLog5color14m_nowBackColorE(%eax)
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %ecx
	movl	8(%ebp), %eax
	movzbl	3(%eax), %eax
	movzbl	%al, %edx
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5color11changeColorENS0_8target_tENS0_7color_tES2_
L24:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3514:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA3514:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3514-LLSDACSB3514
LLSDACSB3514:
LLSDACSE3514:
	.section	.text$_ZN6dbgLog5colorD1Ev,"x"
	.linkonce discard
	.globl	__ZN6dbgLog5color15m_isInitializedE
	.bss
__ZN6dbgLog5color15m_isInitializedE:
	.space 1
	.globl	__ZN6dbgLog5color14m_nowForeColorE
	.data
__ZN6dbgLog5color14m_nowForeColorE:
	.byte	16
	.byte	16
	.globl	__ZN6dbgLog5color14m_nowBackColorE
__ZN6dbgLog5color14m_nowBackColorE:
	.byte	16
	.byte	16
	.globl	__ZN6dbgLog5color8m_handleE
	.bss
	.align 4
__ZN6dbgLog5color8m_handleE:
	.space 8
	.text
	.align 2
	.globl	__ZN6dbgLog5color14initializeOnceEv
	.def	__ZN6dbgLog5color14initializeOnceEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5color14initializeOnceEv:
LFB3515:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movzbl	__ZN6dbgLog5color15m_isInitializedE, %eax
	testb	%al, %al
	je	L27
	jmp	L26
L27:
	movb	$1, __ZN6dbgLog5color15m_isInitializedE
L26:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3515:
.lcomm __ZN6dbgLogL20s_colorForInitializeE,6,1
	.section	.text$_ZNK6dbgLog5level8iteratordeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level8iteratordeEv
	.def	__ZNK6dbgLog5level8iteratordeEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level8iteratordeEv:
LFB3517:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level9container3getEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3517:
	.section	.text$_ZNK6dbgLog5level8iteratorneES1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level8iteratorneES1_
	.def	__ZNK6dbgLog5level8iteratorneES1_;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level8iteratorneES1_:
LFB3519:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	(%eax), %edx
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	%al, %dl
	setne	%al
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3519:
	.section	.text$_ZNK6dbgLog5level8iteratorppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level8iteratorppEv
	.def	__ZNK6dbgLog5level8iteratorppEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level8iteratorppEv:
LFB3520:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movzbl	(%eax), %ebx
	call	__ZN6dbgLog5level9container8endValueEv
	cmpb	%al, %bl
	jb	L34
	call	__ZN6dbgLog5level9container6getEndEv
	jmp	L35
L34:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, (%eax)
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level9container3getEh
L35:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3520:
	.section	.text$_ZNSt8iteratorISt26bidirectional_iterator_tagN6dbgLog5levelEiPS2_RS2_EC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8iteratorISt26bidirectional_iterator_tagN6dbgLog5levelEiPS2_RS2_EC2Ev
	.def	__ZNSt8iteratorISt26bidirectional_iterator_tagN6dbgLog5levelEiPS2_RS2_EC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt8iteratorISt26bidirectional_iterator_tagN6dbgLog5levelEiPS2_RS2_EC2Ev:
LFB3527:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3527:
	.section	.text$_ZN6dbgLog5level8iteratorC1Eh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5level8iteratorC1Eh
	.def	__ZN6dbgLog5level8iteratorC1Eh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5level8iteratorC1Eh:
LFB3530:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	12(%ebp), %eax
	movb	%al, -4(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8iteratorISt26bidirectional_iterator_tagN6dbgLog5levelEiPS2_RS2_EC2Ev
	movl	8(%ebp), %eax
	movzbl	-4(%ebp), %edx
	movb	%dl, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3530:
	.section	.text$_ZN6dbgLog5level8iteratorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5level8iteratorD1Ev
	.def	__ZN6dbgLog5level8iteratorD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5level8iteratorD1Ev:
LFB3545:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3545:
	.section	.text$_ZN6dbgLog5level9container10beginValueEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog5level9container10beginValueEv
	.def	__ZN6dbgLog5level9container10beginValueEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5level9container10beginValueEv:
LFB3546:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$0, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3546:
	.section	.text$_ZN6dbgLog5level9container8endValueEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog5level9container8endValueEv
	.def	__ZN6dbgLog5level9container8endValueEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5level9container8endValueEv:
LFB3547:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$13, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3547:
	.section	.text$_ZN6dbgLog5level9container3getEh,"x"
	.linkonce discard
	.globl	__ZN6dbgLog5level9container3getEh
	.def	__ZN6dbgLog5level9container3getEh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5level9container3getEh:
LFB3548:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movb	%al, -4(%ebp)
	movl	__ZN6dbgLog5level9container9m_poolPtrE, %ecx
	movzbl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3548:
	.section	.text$_ZN6dbgLog5level9container6getEndEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog5level9container6getEndEv
	.def	__ZN6dbgLog5level9container6getEndEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5level9container6getEndEv:
LFB3550:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	.cfi_offset 3, -12
	movl	__ZN6dbgLog5level9container9m_poolPtrE, %ebx
	call	__ZN6dbgLog5level9container8endValueEv
	movzbl	%al, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ebx, %eax
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3550:
	.section	.text$_ZN6dbgLog5level9container3setEhRKS0_,"x"
	.linkonce discard
	.globl	__ZN6dbgLog5level9container3setEhRKS0_
	.def	__ZN6dbgLog5level9container3setEhRKS0_;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5level9container3setEhRKS0_:
LFB3551:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	movzbl	-28(%ebp), %edx
	leal	-24(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	$__ZN6dbgLog5level9container15m_isAlreadyPoolE, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj14EEixEj
	subl	$4, %esp
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6bitsetILj14EE9referencecvbEv
	xorl	$1, %eax
	movl	%eax, %ebx
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj14EE9referenceD1Ev
	testb	%bl, %bl
	je	L49
	movl	__ZN6dbgLog5level9container9m_poolPtrE, %ecx
	movzbl	-28(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZN6dbgLog5levelaSERKS0_
	movzbl	-28(%ebp), %edx
	leal	-16(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	$__ZN6dbgLog5level9container15m_isAlreadyPoolE, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj14EEixEj
	subl	$4, %esp
	movl	$1, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj14EE9referenceaSEb
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj14EE9referenceD1Ev
L49:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3551:
	.section	.text$_ZN6dbgLog5level9container5beginEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog5level9container5beginEv
	.def	__ZN6dbgLog5level9container5beginEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5level9container5beginEv:
LFB3552:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	__ZN6dbgLog5level9container10beginValueEv
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level8iteratorC1Eh
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3552:
	.section	.text$_ZN6dbgLog5level9container3endEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog5level9container3endEv
	.def	__ZN6dbgLog5level9container3endEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5level9container3endEv:
LFB3553:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	__ZN6dbgLog5level9container8endValueEv
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level8iteratorC1Eh
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3553:
	.section	.text$_ZNK6dbgLog5levelgeERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5levelgeERKS0_
	.def	__ZNK6dbgLog5levelgeERKS0_;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5levelgeERKS0_:
LFB3559:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level13valueAsOutputEv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level13valueAsOutputEv
	cmpb	%al, %bl
	setae	%al
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3559:
	.section	.text$_ZN6dbgLog5levelaSERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5levelaSERKS0_
	.def	__ZN6dbgLog5levelaSERKS0_;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5levelaSERKS0_:
LFB3562:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$12, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_memcpy
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3562:
	.section	.text$_ZNK6dbgLog5level5valueEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level5valueEv
	.def	__ZNK6dbgLog5level5valueEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level5valueEv:
LFB3566:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3566:
	.section	.text$_ZNK6dbgLog5level4nameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level4nameEv
	.def	__ZNK6dbgLog5level4nameEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level4nameEv:
LFB3567:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3567:
	.section	.text$_ZNK6dbgLog5level13valueAsOutputEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level13valueAsOutputEv
	.def	__ZNK6dbgLog5level13valueAsOutputEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level13valueAsOutputEv:
LFB3568:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	sarl	%eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3568:
	.section	.text$_ZNK6dbgLog5level6forLogEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level6forLogEv
	.def	__ZNK6dbgLog5level6forLogEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level6forLogEv:
LFB3569:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3569:
	.section	.text$_ZNK6dbgLog5level9forNoticeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level9forNoticeEv
	.def	__ZNK6dbgLog5level9forNoticeEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level9forNoticeEv:
LFB3570:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	6(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3570:
	.section	.text$_ZNK6dbgLog5level7forMaskEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level7forMaskEv
	.def	__ZNK6dbgLog5level7forMaskEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level7forMaskEv:
LFB3571:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	7(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3571:
	.section	.text$_ZSt4moveIN6dbgLog5colorEEONSt16remove_referenceIT_E4typeEOS3_,"x"
	.linkonce discard
	.globl	__ZSt4moveIN6dbgLog5colorEEONSt16remove_referenceIT_E4typeEOS3_
	.def	__ZSt4moveIN6dbgLog5colorEEONSt16remove_referenceIT_E4typeEOS3_;	.scl	2;	.type	32;	.endef
__ZSt4moveIN6dbgLog5colorEEONSt16remove_referenceIT_E4typeEOS3_:
LFB3573:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3573:
	.section	.text$_ZNK6dbgLog5level11changeColorEb,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level11changeColorEb
	.def	__ZNK6dbgLog5level11changeColorEb;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level11changeColorEb:
LFB3575:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	16(%ebp), %eax
	movb	%al, -28(%ebp)
	movzbl	-28(%ebp), %eax
	xorl	$1, %eax
	movzbl	%al, %ecx
	movl	12(%ebp), %eax
	movzbl	9(%eax), %eax
	movzbl	%al, %edx
	movl	12(%ebp), %eax
	movzbl	8(%eax), %eax
	movzbl	%al, %eax
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$0, 4(%esp)
	leal	-14(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5colorC1ENS0_8target_tENS0_7color_tES2_b
	leal	-14(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIN6dbgLog5colorEEONSt16remove_referenceIT_E4typeEOS3_
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5colorC1EOS0_
	leal	-14(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5colorD1Ev
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3575:
	.section	.text$_ZNK6dbgLog5level20changeColorForNoticeEb,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level20changeColorForNoticeEb
	.def	__ZNK6dbgLog5level20changeColorForNoticeEb;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level20changeColorForNoticeEb:
LFB3576:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	16(%ebp), %eax
	movb	%al, -28(%ebp)
	movzbl	-28(%ebp), %eax
	xorl	$1, %eax
	movzbl	%al, %ecx
	movl	12(%ebp), %eax
	movzbl	11(%eax), %eax
	movzbl	%al, %edx
	movl	12(%ebp), %eax
	movzbl	10(%eax), %eax
	movzbl	%al, %eax
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1, 4(%esp)
	leal	-14(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5colorC1ENS0_8target_tENS0_7color_tES2_b
	leal	-14(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIN6dbgLog5colorEEONSt16remove_referenceIT_E4typeEOS3_
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5colorC1EOS0_
	leal	-14(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5colorD1Ev
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3576:
	.section	.text$_ZN6dbgLog5level3getEh,"x"
	.linkonce discard
	.globl	__ZN6dbgLog5level3getEh
	.def	__ZN6dbgLog5level3getEh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5level3getEh:
LFB3577:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movb	%al, -4(%ebp)
	movzbl	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level9container3getEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3577:
	.section	.text$_ZNK6dbgLog5level4prevEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level4prevEv
	.def	__ZNK6dbgLog5level4prevEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level4prevEv:
LFB3578:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level13valueAsOutputEv
	testb	%al, %al
	je	L80
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level13valueAsOutputEv
	cmpb	$5, %al
	ja	L80
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L81
	movl	8(%ebp), %eax
	movzbl	6(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L81
L80:
	movl	$1, %eax
	jmp	L82
L81:
	movl	$0, %eax
L82:
	testb	%al, %al
	je	L83
	movl	__ZN6dbgLog5level9container9m_poolPtrE, %ecx
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	jmp	L84
L83:
	movl	__ZN6dbgLog5level9container9m_poolPtrE, %ecx
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	sarl	%eax
	subl	$1, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
L84:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3578:
	.section	.text$_ZNK6dbgLog5level4nextEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level4nextEv
	.def	__ZNK6dbgLog5level4nextEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level4nextEv:
LFB3579:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level13valueAsOutputEv
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level13valueAsOutputEv
	cmpb	$4, %al
	ja	L86
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L87
	movl	8(%ebp), %eax
	movzbl	6(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L87
L86:
	movl	$1, %eax
	jmp	L88
L87:
	movl	$0, %eax
L88:
	testb	%al, %al
	je	L89
	movl	__ZN6dbgLog5level9container9m_poolPtrE, %ecx
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	jmp	L90
L89:
	movl	__ZN6dbgLog5level9container9m_poolPtrE, %ecx
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	sarl	%eax
	addl	$1, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
L90:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3579:
	.section	.text$_ZN6dbgLog5levelC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5levelC1Ev
	.def	__ZN6dbgLog5levelC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5levelC1Ev:
LFB3582:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	8(%ebp), %eax
	movb	$-1, 4(%eax)
	movl	8(%ebp), %eax
	movb	$0, 5(%eax)
	movl	8(%ebp), %eax
	movb	$0, 6(%eax)
	movl	8(%ebp), %eax
	movb	$0, 7(%eax)
	movl	8(%ebp), %eax
	movb	$32, 8(%eax)
	movl	8(%ebp), %eax
	movb	$32, 9(%eax)
	movl	8(%ebp), %eax
	movb	$32, 10(%eax)
	movl	8(%ebp), %eax
	movb	$32, 11(%eax)
	call	__ZN6dbgLog5level9container14initializeOnceEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3582:
	.section .rdata,"dr"
	.align 4
LC2:
	.ascii "value >= BEGIN && value <= END\0"
LC3:
	.ascii "call_point.cpp\0"
	.section	.text$_ZN6dbgLog5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	.def	__ZN6dbgLog5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_:
LFB3587:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	12(%ebp), %edx
	movl	20(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	24(%ebp), %ecx
	movl	%ecx, -64(%ebp)
	movl	28(%ebp), %edi
	movl	32(%ebp), %esi
	movl	36(%ebp), %ebx
	movl	40(%ebp), %ecx
	movl	44(%ebp), %eax
	movb	%dl, -28(%ebp)
	movzbl	-60(%ebp), %edx
	movb	%dl, -32(%ebp)
	movzbl	-64(%ebp), %edx
	movb	%dl, -36(%ebp)
	movl	%edi, %edx
	movb	%dl, -40(%ebp)
	movl	%esi, %edx
	movb	%dl, -44(%ebp)
	movb	%bl, -48(%ebp)
	movb	%cl, -52(%ebp)
	movb	%al, -56(%ebp)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movzbl	-28(%ebp), %edx
	movb	%dl, 4(%eax)
	movl	8(%ebp), %eax
	movzbl	-32(%ebp), %edx
	movb	%dl, 5(%eax)
	movl	8(%ebp), %eax
	movzbl	-36(%ebp), %edx
	movb	%dl, 6(%eax)
	movl	8(%ebp), %eax
	movzbl	-40(%ebp), %edx
	movb	%dl, 7(%eax)
	movl	8(%ebp), %eax
	movzbl	-44(%ebp), %edx
	movb	%dl, 8(%eax)
	movl	8(%ebp), %eax
	movzbl	-48(%ebp), %edx
	movb	%dl, 9(%eax)
	movl	8(%ebp), %eax
	movzbl	-52(%ebp), %edx
	movb	%dl, 10(%eax)
	movl	8(%ebp), %eax
	movzbl	-56(%ebp), %edx
	movb	%dl, 11(%eax)
	cmpb	$13, -28(%ebp)
	jbe	L93
	movl	$LC2, 12(%esp)
	movl	$__ZZN6dbgLog5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_E19__PRETTY_FUNCTION__, 8(%esp)
	movl	$472, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L93:
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level9container3setEhRKS0_
	addl	$76, %esp
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
LFE3587:
	.section	.text$_ZN6dbgLog5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_
	.def	__ZN6dbgLog5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_:
LFB3588:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	12(%ebp), %edx
	movl	20(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	24(%ebp), %ecx
	movl	%ecx, -64(%ebp)
	movl	28(%ebp), %edi
	movl	32(%ebp), %esi
	movl	36(%ebp), %ebx
	movl	40(%ebp), %ecx
	movl	44(%ebp), %eax
	movb	%dl, -28(%ebp)
	movzbl	-60(%ebp), %edx
	movb	%dl, -32(%ebp)
	movzbl	-64(%ebp), %edx
	movb	%dl, -36(%ebp)
	movl	%edi, %edx
	movb	%dl, -40(%ebp)
	movl	%esi, %edx
	movb	%dl, -44(%ebp)
	movb	%bl, -48(%ebp)
	movb	%cl, -52(%ebp)
	movb	%al, -56(%ebp)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movzbl	-28(%ebp), %edx
	movb	%dl, 4(%eax)
	movl	8(%ebp), %eax
	movzbl	-32(%ebp), %edx
	movb	%dl, 5(%eax)
	movl	8(%ebp), %eax
	movzbl	-36(%ebp), %edx
	movb	%dl, 6(%eax)
	movl	8(%ebp), %eax
	movzbl	-40(%ebp), %edx
	movb	%dl, 7(%eax)
	movl	8(%ebp), %eax
	movzbl	-44(%ebp), %edx
	movb	%dl, 8(%eax)
	movl	8(%ebp), %eax
	movzbl	-48(%ebp), %edx
	movb	%dl, 9(%eax)
	movl	8(%ebp), %eax
	movzbl	-52(%ebp), %edx
	movb	%dl, 10(%eax)
	movl	8(%ebp), %eax
	movzbl	-56(%ebp), %edx
	movb	%dl, 11(%eax)
	cmpb	$13, -28(%ebp)
	jbe	L95
	movl	$LC2, 12(%esp)
	movl	$__ZZN6dbgLog5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_E19__PRETTY_FUNCTION__, 8(%esp)
	movl	$472, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L95:
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level9container3setEhRKS0_
	addl	$76, %esp
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
LFE3588:
	.section	.text$_ZN6dbgLog5levelC1Eh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5levelC1Eh
	.def	__ZN6dbgLog5levelC1Eh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5levelC1Eh:
LFB3591:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	movb	%al, -12(%ebp)
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	8(%ebp), %eax
	movzbl	-12(%ebp), %edx
	movb	%dl, 4(%eax)
	movl	8(%ebp), %eax
	movb	$0, 5(%eax)
	movl	8(%ebp), %eax
	movb	$0, 6(%eax)
	movl	8(%ebp), %eax
	movb	$0, 7(%eax)
	movl	8(%ebp), %eax
	movb	$32, 8(%eax)
	movl	8(%ebp), %eax
	movb	$32, 9(%eax)
	movl	8(%ebp), %eax
	movb	$32, 10(%eax)
	movl	8(%ebp), %eax
	movb	$32, 11(%eax)
	cmpb	$13, -12(%ebp)
	jbe	L97
	movl	$LC2, 12(%esp)
	movl	$__ZZN6dbgLog5levelC1EhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$486, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L97:
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level9container3getEh
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelaSERKS0_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3591:
	.section	.text$_ZN6dbgLog5levelD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5levelD2Ev
	.def	__ZN6dbgLog5levelD2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5levelD2Ev:
LFB3593:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3593:
	.section	.text$_ZN6dbgLog5levelD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5levelD1Ev
	.def	__ZN6dbgLog5levelD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5levelD1Ev:
LFB3594:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3594:
	.section .rdata,"dr"
LC4:
	.ascii "(END)\0"
	.section	.text$_ZN6dbgLog9level_endC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog9level_endC1Ev
	.def	__ZN6dbgLog9level_endC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog9level_endC1Ev:
LFB3599:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$32, 36(%esp)
	movl	$32, 32(%esp)
	movl	$32, 28(%esp)
	movl	$32, 24(%esp)
	movl	$0, 20(%esp)
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	$LC4, 8(%esp)
	movl	$13, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3599:
	.section	.text$_ZN6dbgLog12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EED2Ev
	.def	__ZN6dbgLog12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EED2Ev:
LFB3602:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3602:
	.section .rdata,"dr"
LC5:
	.ascii "asNormal\0"
	.section	.text$_ZN6dbgLog14level_asNormalC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14level_asNormalC1Ev
	.def	__ZN6dbgLog14level_asNormalC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14level_asNormalC1Ev:
LFB3605:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3605:
	.section	.text$_ZN6dbgLog12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev
	.def	__ZN6dbgLog12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev:
LFB3608:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3608:
	.section .rdata,"dr"
LC6:
	.ascii "asVerbose\0"
	.section	.text$_ZN6dbgLog15level_asVerboseC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog15level_asVerboseC1Ev
	.def	__ZN6dbgLog15level_asVerboseC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog15level_asVerboseC1Ev:
LFB3611:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC6, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3611:
	.section	.text$_ZN6dbgLog12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev
	.def	__ZN6dbgLog12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev:
LFB3614:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3614:
	.section .rdata,"dr"
LC7:
	.ascii "asDetail\0"
	.section	.text$_ZN6dbgLog14level_asDetailC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14level_asDetailC1Ev
	.def	__ZN6dbgLog14level_asDetailC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14level_asDetailC1Ev:
LFB3617:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC7, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3617:
	.section	.text$_ZN6dbgLog12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EED2Ev
	.def	__ZN6dbgLog12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EED2Ev:
LFB3620:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3620:
	.section .rdata,"dr"
LC8:
	.ascii "asImportant\0"
	.section	.text$_ZN6dbgLog17level_asImportantC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17level_asImportantC1Ev
	.def	__ZN6dbgLog17level_asImportantC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17level_asImportantC1Ev:
LFB3623:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC8, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3623:
	.section	.text$_ZN6dbgLog12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EED2Ev
	.def	__ZN6dbgLog12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EED2Ev:
LFB3626:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3626:
	.section .rdata,"dr"
LC9:
	.ascii "asWarning\0"
	.section	.text$_ZN6dbgLog15level_asWarningC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog15level_asWarningC1Ev
	.def	__ZN6dbgLog15level_asWarningC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog15level_asWarningC1Ev:
LFB3629:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC9, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3629:
	.section	.text$_ZN6dbgLog12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EED2Ev
	.def	__ZN6dbgLog12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EED2Ev:
LFB3632:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3632:
	.section .rdata,"dr"
LC10:
	.ascii "asCritical\0"
	.section	.text$_ZN6dbgLog16level_asCriticalC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16level_asCriticalC1Ev
	.def	__ZN6dbgLog16level_asCriticalC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16level_asCriticalC1Ev:
LFB3635:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC10, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3635:
	.section	.text$_ZN6dbgLog12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EED2Ev
	.def	__ZN6dbgLog12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EED2Ev:
LFB3638:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3638:
	.section .rdata,"dr"
LC11:
	.ascii "asAbsolute\0"
	.section	.text$_ZN6dbgLog16level_asAbsoluteC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16level_asAbsoluteC1Ev
	.def	__ZN6dbgLog16level_asAbsoluteC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16level_asAbsoluteC1Ev:
LFB3641:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC11, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3641:
	.section	.text$_ZN6dbgLog13level_specialILh11EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog13level_specialILh11EED2Ev
	.def	__ZN6dbgLog13level_specialILh11EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog13level_specialILh11EED2Ev:
LFB3644:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3644:
	.section .rdata,"dr"
LC12:
	.ascii "asSilent\0"
	.section	.text$_ZN6dbgLog14level_asSilentC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14level_asSilentC1Ev
	.def	__ZN6dbgLog14level_asSilentC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14level_asSilentC1Ev:
LFB3647:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC12, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog13level_specialILh11EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3647:
	.section	.text$_ZN6dbgLog13level_specialILh12EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog13level_specialILh12EED2Ev
	.def	__ZN6dbgLog13level_specialILh12EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog13level_specialILh12EED2Ev:
LFB3650:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3650:
	.section .rdata,"dr"
LC13:
	.ascii "asSilentAbsolutely\0"
	.section	.text$_ZN6dbgLog24level_asSilentAbsolutelyC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog24level_asSilentAbsolutelyC1Ev
	.def	__ZN6dbgLog24level_asSilentAbsolutelyC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog24level_asSilentAbsolutelyC1Ev:
LFB3653:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC13, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog13level_specialILh12EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3653:
	.globl	__ZN6dbgLog5level9container15m_isInitializedE
	.bss
__ZN6dbgLog5level9container15m_isInitializedE:
	.space 1
	.globl	__ZN6dbgLog5level9container9m_poolPtrE
	.align 4
__ZN6dbgLog5level9container9m_poolPtrE:
	.space 4
	.globl	__ZN6dbgLog5level9container6m_poolE
	.align 32
__ZN6dbgLog5level9container6m_poolE:
	.space 168
	.globl	__ZN6dbgLog5level9container15m_isAlreadyPoolE
	.align 4
__ZN6dbgLog5level9container15m_isAlreadyPoolE:
	.space 4
	.section	.text$_ZN6dbgLog14level_asNormalD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14level_asNormalD1Ev
	.def	__ZN6dbgLog14level_asNormalD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14level_asNormalD1Ev:
LFB3660:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3660:
	.section	.text$_ZN6dbgLog15level_asVerboseD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog15level_asVerboseD1Ev
	.def	__ZN6dbgLog15level_asVerboseD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog15level_asVerboseD1Ev:
LFB3663:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3663:
	.section	.text$_ZN6dbgLog14level_asDetailD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14level_asDetailD1Ev
	.def	__ZN6dbgLog14level_asDetailD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14level_asDetailD1Ev:
LFB3666:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3666:
	.section	.text$_ZN6dbgLog17level_asImportantD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17level_asImportantD1Ev
	.def	__ZN6dbgLog17level_asImportantD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17level_asImportantD1Ev:
LFB3669:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3669:
	.section	.text$_ZN6dbgLog15level_asWarningD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog15level_asWarningD1Ev
	.def	__ZN6dbgLog15level_asWarningD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog15level_asWarningD1Ev:
LFB3672:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3672:
	.section	.text$_ZN6dbgLog16level_asCriticalD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16level_asCriticalD1Ev
	.def	__ZN6dbgLog16level_asCriticalD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16level_asCriticalD1Ev:
LFB3675:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3675:
	.section	.text$_ZN6dbgLog16level_asAbsoluteD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16level_asAbsoluteD1Ev
	.def	__ZN6dbgLog16level_asAbsoluteD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16level_asAbsoluteD1Ev:
LFB3678:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3678:
	.section	.text$_ZN6dbgLog14level_asSilentD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14level_asSilentD1Ev
	.def	__ZN6dbgLog14level_asSilentD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14level_asSilentD1Ev:
LFB3681:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog13level_specialILh11EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3681:
	.section	.text$_ZN6dbgLog24level_asSilentAbsolutelyD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog24level_asSilentAbsolutelyD1Ev
	.def	__ZN6dbgLog24level_asSilentAbsolutelyD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog24level_asSilentAbsolutelyD1Ev:
LFB3684:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog13level_specialILh12EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3684:
	.section	.text$_ZN6dbgLog9level_endD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog9level_endD1Ev
	.def	__ZN6dbgLog9level_endD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog9level_endD1Ev:
LFB3687:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3687:
	.section .rdata,"dr"
LC14:
	.ascii "(undefined)\0"
	.text
	.align 2
	.globl	__ZN6dbgLog5level9container14initializeOnceEv
	.def	__ZN6dbgLog5level9container14initializeOnceEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5level9container14initializeOnceEv:
LFB3657:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$200, %esp
	movzbl	__ZN6dbgLog5level9container15m_isInitializedE, %eax
	testb	%al, %al
	je	L151
	jmp	L150
L151:
	movb	$1, __ZN6dbgLog5level9container15m_isInitializedE
	movl	$__ZN6dbgLog5level9container15m_isAlreadyPoolE, (%esp)
	call	__ZNSt6bitsetILj14EE5resetEv
	movl	$168, 8(%esp)
	movl	$0, 4(%esp)
	movl	$__ZN6dbgLog5level9container6m_poolE, (%esp)
	call	_memset
	movl	$__ZN6dbgLog5level9container6m_poolE, __ZN6dbgLog5level9container9m_poolPtrE
	movb	$0, -9(%ebp)
	jmp	L153
L154:
	movzbl	-9(%ebp), %eax
	movl	$32, 36(%esp)
	movl	$32, 32(%esp)
	movl	$32, 28(%esp)
	movl	$32, 24(%esp)
	movl	$0, 20(%esp)
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	$LC14, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_
	leal	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelD1Ev
	movzbl	-9(%ebp), %edx
	leal	-140(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	$__ZN6dbgLog5level9container15m_isAlreadyPoolE, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj14EEixEj
	subl	$4, %esp
	movl	$0, 4(%esp)
	leal	-140(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj14EE9referenceaSEb
	leal	-140(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj14EE9referenceD1Ev
	addb	$1, -9(%ebp)
L153:
	cmpb	$12, -9(%ebp)
	jbe	L154
	leal	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog14level_asNormalC1Ev
	leal	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog14level_asNormalD1Ev
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog15level_asVerboseC1Ev
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog15level_asVerboseD1Ev
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog14level_asDetailC1Ev
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog14level_asDetailD1Ev
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17level_asImportantC1Ev
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17level_asImportantD1Ev
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog15level_asWarningC1Ev
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog15level_asWarningD1Ev
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog16level_asCriticalC1Ev
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog16level_asCriticalD1Ev
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog16level_asAbsoluteC1Ev
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog16level_asAbsoluteD1Ev
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog14level_asSilentC1Ev
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog14level_asSilentD1Ev
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog24level_asSilentAbsolutelyC1Ev
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog24level_asSilentAbsolutelyD1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog9level_endC1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog9level_endD1Ev
L150:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3657:
.lcomm __ZN6dbgLogL20s_levelForInitializeE,12,4
	.section .rdata,"dr"
	.align 4
LC15:
	.ascii "level=%d, name=\"%s\", valueAsOutput=%d, forLog=%d, forNotice=%d, forMask=%d\12\0"
LC16:
	.ascii "           prev=%s(%d)\12\0"
LC17:
	.ascii "           next=%s(%d)\12\0"
	.text
	.globl	__ZN6dbgLog13printLevelAllEv
	.def	__ZN6dbgLog13printLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog13printLevelAllEv:
LFB3688:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3688
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$92, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	leal	-42(%ebp), %eax
	movl	%eax, -28(%ebp)
	leal	-43(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level9container5beginEv
	subl	$4, %esp
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level9container3endEv
	subl	$4, %esp
	jmp	L156
L157:
	leal	-43(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level8iteratordeEv
	movl	%eax, -32(%ebp)
	leal	-50(%ebp), %eax
	movl	$0, 8(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB0:
	call	__ZNK6dbgLog5level11changeColorEb
LEHE0:
	subl	$4, %esp
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level7forMaskEv
	movzbl	%al, %eax
	movl	%eax, -60(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level9forNoticeEv
	movzbl	%al, %eax
	movl	%eax, -64(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level6forLogEv
	movzbl	%al, %eax
	movl	%eax, -68(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level13valueAsOutputEv
	movzbl	%al, %edi
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level4nameEv
	movl	%eax, %ebx
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level5valueEv
	movzbl	%al, %esi
LEHB1:
	call	___getreent
	movl	8(%eax), %eax
	movl	-60(%ebp), %ecx
	movl	%ecx, 28(%esp)
	movl	-64(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	-68(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC15, 4(%esp)
	movl	%eax, (%esp)
	call	_fprintf
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level4prevEv
	movl	%eax, -36(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level4nextEv
	movl	%eax, -40(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level5valueEv
	movzbl	%al, %esi
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level4nameEv
	movl	%eax, %ebx
	call	___getreent
	movl	8(%eax), %eax
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	$LC16, 4(%esp)
	movl	%eax, (%esp)
	call	_fprintf
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level5valueEv
	movzbl	%al, %esi
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level4nameEv
	movl	%eax, %ebx
	call	___getreent
	movl	8(%eax), %eax
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	$LC17, 4(%esp)
	movl	%eax, (%esp)
	call	_fprintf
LEHE1:
	leal	-50(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5colorD1Ev
	leal	-43(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level8iteratorppEv
L156:
	movzbl	-44(%ebp), %eax
	movb	%al, -41(%ebp)
	leal	-41(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-43(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level8iteratorneES1_
	movl	%eax, %ebx
	leal	-41(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level8iteratorD1Ev
	testb	%bl, %bl
	jne	L157
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level8iteratorD1Ev
	leal	-43(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level8iteratorD1Ev
	jmp	L162
L161:
	movl	%eax, %ebx
	leal	-50(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5colorD1Ev
	movl	%ebx, %eax
	jmp	L159
L160:
L159:
	movl	%eax, %ebx
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level8iteratorD1Ev
	leal	-43(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level8iteratorD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB2:
	call	__Unwind_Resume
LEHE2:
L162:
	leal	-12(%ebp), %esp
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
LFE3688:
	.section	.gcc_except_table,"w"
LLSDA3688:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3688-LLSDACSB3688
LLSDACSB3688:
	.uleb128 LEHB0-LFB3688
	.uleb128 LEHE0-LEHB0
	.uleb128 L160-LFB3688
	.uleb128 0
	.uleb128 LEHB1-LFB3688
	.uleb128 LEHE1-LEHB1
	.uleb128 L161-LFB3688
	.uleb128 0
	.uleb128 LEHB2-LFB3688
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
LLSDACSE3688:
	.text
	.section	.text$_ZNK6dbgLog8category8iteratordeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category8iteratordeEv
	.def	__ZNK6dbgLog8category8iteratordeEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category8iteratordeEv:
LFB3690:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category9container3getEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3690:
	.section	.text$_ZNK6dbgLog8category8iteratorneES1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category8iteratorneES1_
	.def	__ZNK6dbgLog8category8iteratorneES1_;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category8iteratorneES1_:
LFB3692:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	(%eax), %edx
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	%al, %dl
	setne	%al
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3692:
	.section	.text$_ZNK6dbgLog8category8iteratorppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category8iteratorppEv
	.def	__ZNK6dbgLog8category8iteratorppEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category8iteratorppEv:
LFB3693:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movzbl	(%eax), %ebx
	call	__ZN6dbgLog8category9container8endValueEv
	cmpb	%al, %bl
	jb	L168
	call	__ZN6dbgLog8category9container6getEndEv
	jmp	L169
L168:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, (%eax)
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category9container3getEh
L169:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3693:
	.section	.text$_ZNSt8iteratorISt26bidirectional_iterator_tagN6dbgLog8categoryEiPS2_RS2_EC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8iteratorISt26bidirectional_iterator_tagN6dbgLog8categoryEiPS2_RS2_EC2Ev
	.def	__ZNSt8iteratorISt26bidirectional_iterator_tagN6dbgLog8categoryEiPS2_RS2_EC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt8iteratorISt26bidirectional_iterator_tagN6dbgLog8categoryEiPS2_RS2_EC2Ev:
LFB3700:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3700:
	.section	.text$_ZN6dbgLog8category8iteratorC1Eh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8category8iteratorC1Eh
	.def	__ZN6dbgLog8category8iteratorC1Eh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category8iteratorC1Eh:
LFB3703:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	12(%ebp), %eax
	movb	%al, -4(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8iteratorISt26bidirectional_iterator_tagN6dbgLog8categoryEiPS2_RS2_EC2Ev
	movl	8(%ebp), %eax
	movzbl	-4(%ebp), %edx
	movb	%dl, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3703:
	.section	.text$_ZN6dbgLog8category8iteratorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8category8iteratorD1Ev
	.def	__ZN6dbgLog8category8iteratorD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category8iteratorD1Ev:
LFB3718:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3718:
	.section	.text$_ZN6dbgLog8category9container10beginValueEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog8category9container10beginValueEv
	.def	__ZN6dbgLog8category9container10beginValueEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container10beginValueEv:
LFB3719:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$0, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3719:
	.section	.text$_ZN6dbgLog8category9container8endValueEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog8category9container8endValueEv
	.def	__ZN6dbgLog8category9container8endValueEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container8endValueEv:
LFB3720:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$67, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3720:
	.section	.text$_ZN6dbgLog8category9container3getEh,"x"
	.linkonce discard
	.globl	__ZN6dbgLog8category9container3getEh
	.def	__ZN6dbgLog8category9container3getEh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container3getEh:
LFB3721:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movb	%al, -4(%ebp)
	movl	__ZN6dbgLog8category9container9m_poolPtrE, %ecx
	movzbl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3721:
	.section	.text$_ZN6dbgLog8category9container6getEndEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog8category9container6getEndEv
	.def	__ZN6dbgLog8category9container6getEndEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container6getEndEv:
LFB3723:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	.cfi_offset 3, -12
	movl	__ZN6dbgLog8category9container9m_poolPtrE, %ebx
	call	__ZN6dbgLog8category9container8endValueEv
	movzbl	%al, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ebx, %eax
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3723:
	.section	.text$_ZN6dbgLog8category9container3setEhRKS0_,"x"
	.linkonce discard
	.globl	__ZN6dbgLog8category9container3setEhRKS0_
	.def	__ZN6dbgLog8category9container3setEhRKS0_;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container3setEhRKS0_:
LFB3724:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	movzbl	-28(%ebp), %edx
	leal	-24(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	$__ZN6dbgLog8category9container15m_isAlreadyPoolE, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj68EEixEj
	subl	$4, %esp
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6bitsetILj68EE9referencecvbEv
	xorl	$1, %eax
	movl	%eax, %ebx
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj68EE9referenceD1Ev
	testb	%bl, %bl
	je	L183
	movl	__ZN6dbgLog8category9container9m_poolPtrE, %ecx
	movzbl	-28(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZN6dbgLog8categoryaSERKS0_
	movzbl	-28(%ebp), %edx
	leal	-16(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	$__ZN6dbgLog8category9container15m_isAlreadyPoolE, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj68EEixEj
	subl	$4, %esp
	movl	$1, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj68EE9referenceaSEb
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj68EE9referenceD1Ev
L183:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3724:
	.section	.text$_ZN6dbgLog8category9container5beginEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog8category9container5beginEv
	.def	__ZN6dbgLog8category9container5beginEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container5beginEv:
LFB3725:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	__ZN6dbgLog8category9container10beginValueEv
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category8iteratorC1Eh
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3725:
	.section	.text$_ZN6dbgLog8category9container3endEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog8category9container3endEv
	.def	__ZN6dbgLog8category9container3endEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container3endEv:
LFB3726:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	__ZN6dbgLog8category9container8endValueEv
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category8iteratorC1Eh
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3726:
	.section	.text$_ZN6dbgLog8categoryaSERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8categoryaSERKS0_
	.def	__ZN6dbgLog8categoryaSERKS0_;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8categoryaSERKS0_:
LFB3731:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$12, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_memcpy
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3731:
	.section	.text$_ZNK6dbgLog8category5valueEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category5valueEv
	.def	__ZNK6dbgLog8category5valueEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category5valueEv:
LFB3735:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3735:
	.section	.text$_ZNK6dbgLog8category4nameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category4nameEv
	.def	__ZNK6dbgLog8category4nameEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category4nameEv:
LFB3736:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3736:
	.section	.text$_ZNK6dbgLog8category10isAssignedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category10isAssignedEv
	.def	__ZNK6dbgLog8category10isAssignedEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category10isAssignedEv:
LFB3737:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3737:
	.section	.text$_ZNK6dbgLog8category10isReservedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category10isReservedEv
	.def	__ZNK6dbgLog8category10isReservedEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category10isReservedEv:
LFB3738:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	xorl	$1, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3738:
	.section	.text$_ZNK6dbgLog8category6forLogEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category6forLogEv
	.def	__ZNK6dbgLog8category6forLogEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category6forLogEv:
LFB3739:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	6(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3739:
	.section	.text$_ZNK6dbgLog8category9forNoticeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category9forNoticeEv
	.def	__ZNK6dbgLog8category9forNoticeEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category9forNoticeEv:
LFB3740:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	7(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3740:
	.section	.text$_ZNK6dbgLog8category7forMaskEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category7forMaskEv
	.def	__ZNK6dbgLog8category7forMaskEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category7forMaskEv:
LFB3741:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	8(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3741:
	.section	.text$_ZN6dbgLog8category3getEh,"x"
	.linkonce discard
	.globl	__ZN6dbgLog8category3getEh
	.def	__ZN6dbgLog8category3getEh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category3getEh:
LFB3742:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movb	%al, -4(%ebp)
	movzbl	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category9container3getEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3742:
	.section	.text$_ZN6dbgLog8categoryC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8categoryC1Ev
	.def	__ZN6dbgLog8categoryC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8categoryC1Ev:
LFB3745:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	8(%ebp), %eax
	movb	$-1, 4(%eax)
	movl	8(%ebp), %eax
	movb	$0, 5(%eax)
	movl	8(%ebp), %eax
	movb	$0, 6(%eax)
	movl	8(%ebp), %eax
	movb	$0, 7(%eax)
	movl	8(%ebp), %eax
	movb	$0, 8(%eax)
	call	__ZN6dbgLog8category9container14initializeOnceEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3745:
	.section	.text$_ZN6dbgLog8categoryC2EhPKcbbbb,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8categoryC2EhPKcbbbb
	.def	__ZN6dbgLog8categoryC2EhPKcbbbb;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8categoryC2EhPKcbbbb:
LFB3750:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	12(%ebp), %esi
	movl	20(%ebp), %ebx
	movl	24(%ebp), %ecx
	movl	28(%ebp), %edx
	movl	32(%ebp), %edi
	movl	%esi, %eax
	movb	%al, -28(%ebp)
	movb	%bl, -32(%ebp)
	movb	%cl, -36(%ebp)
	movb	%dl, -40(%ebp)
	movl	%edi, %eax
	movb	%al, -44(%ebp)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movzbl	-28(%ebp), %edx
	movb	%dl, 4(%eax)
	movl	8(%ebp), %eax
	movzbl	-32(%ebp), %edx
	movb	%dl, 5(%eax)
	movl	8(%ebp), %eax
	movzbl	-36(%ebp), %edx
	movb	%dl, 6(%eax)
	movl	8(%ebp), %eax
	movzbl	-40(%ebp), %edx
	movb	%dl, 7(%eax)
	movl	8(%ebp), %eax
	movzbl	-44(%ebp), %edx
	movb	%dl, 8(%eax)
	cmpb	$67, -28(%ebp)
	jbe	L209
	movl	$LC2, 12(%esp)
	movl	$__ZZN6dbgLog8categoryC1EhPKcbbbbE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$828, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L209:
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category9container3setEhRKS0_
	addl	$60, %esp
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
LFE3750:
	.section	.text$_ZN6dbgLog8categoryC1EhPKcbbbb,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8categoryC1EhPKcbbbb
	.def	__ZN6dbgLog8categoryC1EhPKcbbbb;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8categoryC1EhPKcbbbb:
LFB3751:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	12(%ebp), %esi
	movl	20(%ebp), %ebx
	movl	24(%ebp), %ecx
	movl	28(%ebp), %edx
	movl	32(%ebp), %edi
	movl	%esi, %eax
	movb	%al, -28(%ebp)
	movb	%bl, -32(%ebp)
	movb	%cl, -36(%ebp)
	movb	%dl, -40(%ebp)
	movl	%edi, %eax
	movb	%al, -44(%ebp)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movzbl	-28(%ebp), %edx
	movb	%dl, 4(%eax)
	movl	8(%ebp), %eax
	movzbl	-32(%ebp), %edx
	movb	%dl, 5(%eax)
	movl	8(%ebp), %eax
	movzbl	-36(%ebp), %edx
	movb	%dl, 6(%eax)
	movl	8(%ebp), %eax
	movzbl	-40(%ebp), %edx
	movb	%dl, 7(%eax)
	movl	8(%ebp), %eax
	movzbl	-44(%ebp), %edx
	movb	%dl, 8(%eax)
	cmpb	$67, -28(%ebp)
	jbe	L211
	movl	$LC2, 12(%esp)
	movl	$__ZZN6dbgLog8categoryC1EhPKcbbbbE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$828, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L211:
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category9container3setEhRKS0_
	addl	$60, %esp
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
LFE3751:
	.section	.text$_ZN6dbgLog8categoryD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8categoryD2Ev
	.def	__ZN6dbgLog8categoryD2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8categoryD2Ev:
LFB3756:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3756:
	.section	.text$_ZN6dbgLog8categoryD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8categoryD1Ev
	.def	__ZN6dbgLog8categoryD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8categoryD1Ev:
LFB3757:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3757:
	.section	.text$_ZN6dbgLog12category_endC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12category_endC1Ev
	.def	__ZN6dbgLog12category_endC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12category_endC1Ev:
LFB3763:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$0, 24(%esp)
	movl	$0, 20(%esp)
	movl	$0, 16(%esp)
	movl	$1, 12(%esp)
	movl	$LC4, 8(%esp)
	movl	$67, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3763:
	.section	.text$_ZN6dbgLog17category_assignedILh0ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh0ELb1ELb1EED2Ev
	.def	__ZN6dbgLog17category_assignedILh0ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh0ELb1ELb1EED2Ev:
LFB3766:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3766:
	.section .rdata,"dr"
LC18:
	.ascii "forAny\0"
	.section	.text$_ZN6dbgLog15category_forAnyC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog15category_forAnyC1Ev
	.def	__ZN6dbgLog15category_forAnyC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog15category_forAnyC1Ev:
LFB3769:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC18, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh0ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3769:
	.section	.text$_ZN6dbgLog17category_assignedILh1ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh1ELb1ELb1EED2Ev
	.def	__ZN6dbgLog17category_assignedILh1ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh1ELb1ELb1EED2Ev:
LFB3772:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3772:
	.section .rdata,"dr"
LC19:
	.ascii "forLogic\0"
	.section	.text$_ZN6dbgLog17category_forLogicC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_forLogicC1Ev
	.def	__ZN6dbgLog17category_forLogicC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_forLogicC1Ev:
LFB3775:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC19, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh1ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3775:
	.section	.text$_ZN6dbgLog17category_assignedILh2ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh2ELb1ELb1EED2Ev
	.def	__ZN6dbgLog17category_assignedILh2ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh2ELb1ELb1EED2Ev:
LFB3778:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3778:
	.section .rdata,"dr"
LC20:
	.ascii "forResource\0"
	.section	.text$_ZN6dbgLog20category_forResourceC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog20category_forResourceC1Ev
	.def	__ZN6dbgLog20category_forResourceC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog20category_forResourceC1Ev:
LFB3781:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC20, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh2ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3781:
	.section	.text$_ZN6dbgLog17category_assignedILh3ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh3ELb1ELb1EED2Ev
	.def	__ZN6dbgLog17category_assignedILh3ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh3ELb1ELb1EED2Ev:
LFB3784:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3784:
	.section .rdata,"dr"
LC21:
	.ascii "for3D\0"
	.section	.text$_ZN6dbgLog14category_for3DC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14category_for3DC1Ev
	.def	__ZN6dbgLog14category_for3DC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14category_for3DC1Ev:
LFB3787:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC21, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh3ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3787:
	.section	.text$_ZN6dbgLog17category_assignedILh4ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh4ELb1ELb1EED2Ev
	.def	__ZN6dbgLog17category_assignedILh4ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh4ELb1ELb1EED2Ev:
LFB3790:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3790:
	.section .rdata,"dr"
LC22:
	.ascii "for2D\0"
	.section	.text$_ZN6dbgLog14category_for2DC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14category_for2DC1Ev
	.def	__ZN6dbgLog14category_for2DC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14category_for2DC1Ev:
LFB3793:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC22, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh4ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3793:
	.section	.text$_ZN6dbgLog17category_assignedILh5ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh5ELb1ELb1EED2Ev
	.def	__ZN6dbgLog17category_assignedILh5ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh5ELb1ELb1EED2Ev:
LFB3796:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3796:
	.section .rdata,"dr"
LC23:
	.ascii "forSound\0"
	.section	.text$_ZN6dbgLog17category_forSoundC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_forSoundC1Ev
	.def	__ZN6dbgLog17category_forSoundC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_forSoundC1Ev:
LFB3799:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC23, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh5ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3799:
	.section	.text$_ZN6dbgLog17category_assignedILh6ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh6ELb1ELb1EED2Ev
	.def	__ZN6dbgLog17category_assignedILh6ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh6ELb1ELb1EED2Ev:
LFB3802:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3802:
	.section .rdata,"dr"
LC24:
	.ascii "forScript\0"
	.section	.text$_ZN6dbgLog18category_forScriptC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog18category_forScriptC1Ev
	.def	__ZN6dbgLog18category_forScriptC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog18category_forScriptC1Ev:
LFB3805:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC24, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh6ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3805:
	.section	.text$_ZN6dbgLog17category_assignedILh7ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh7ELb1ELb1EED2Ev
	.def	__ZN6dbgLog17category_assignedILh7ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh7ELb1ELb1EED2Ev:
LFB3808:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3808:
	.section .rdata,"dr"
LC25:
	.ascii "forGameData\0"
	.section	.text$_ZN6dbgLog20category_forGameDataC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog20category_forGameDataC1Ev
	.def	__ZN6dbgLog20category_forGameDataC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog20category_forGameDataC1Ev:
LFB3811:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC25, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh7ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3811:
	.section	.text$_ZN6dbgLog16category_specialILh64ELb0ELb0ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16category_specialILh64ELb0ELb0ELb1EED2Ev
	.def	__ZN6dbgLog16category_specialILh64ELb0ELb0ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16category_specialILh64ELb0ELb0ELb1EED2Ev:
LFB3814:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3814:
	.section .rdata,"dr"
LC26:
	.ascii "forEvery\0"
	.section	.text$_ZN6dbgLog17category_forEveryC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_forEveryC1Ev
	.def	__ZN6dbgLog17category_forEveryC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_forEveryC1Ev:
LFB3817:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC26, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog16category_specialILh64ELb0ELb0ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3817:
	.section	.text$_ZN6dbgLog16category_specialILh65ELb1ELb1ELb0EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16category_specialILh65ELb1ELb1ELb0EED2Ev
	.def	__ZN6dbgLog16category_specialILh65ELb1ELb1ELb0EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16category_specialILh65ELb1ELb1ELb0EED2Ev:
LFB3820:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3820:
	.section .rdata,"dr"
LC27:
	.ascii "forCallppoint\0"
	.section	.text$_ZN6dbgLog22category_forCallppointC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog22category_forCallppointC1Ev
	.def	__ZN6dbgLog22category_forCallppointC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog22category_forCallppointC1Ev:
LFB3823:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC27, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog16category_specialILh65ELb1ELb1ELb0EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3823:
	.section	.text$_ZN6dbgLog16category_specialILh66ELb1ELb1ELb0EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16category_specialILh66ELb1ELb1ELb0EED2Ev
	.def	__ZN6dbgLog16category_specialILh66ELb1ELb1ELb0EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16category_specialILh66ELb1ELb1ELb0EED2Ev:
LFB3826:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3826:
	.section .rdata,"dr"
LC28:
	.ascii "forCriticalCallppoint\0"
	.section	.text$_ZN6dbgLog30category_forCriticalCallppointC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog30category_forCriticalCallppointC1Ev
	.def	__ZN6dbgLog30category_forCriticalCallppointC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog30category_forCriticalCallppointC1Ev:
LFB3829:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC28, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog16category_specialILh66ELb1ELb1ELb0EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3829:
	.globl	__ZN6dbgLog8category9container15m_isInitializedE
	.bss
__ZN6dbgLog8category9container15m_isInitializedE:
	.space 1
	.globl	__ZN6dbgLog8category9container9m_poolPtrE
	.align 4
__ZN6dbgLog8category9container9m_poolPtrE:
	.space 4
	.globl	__ZN6dbgLog8category9container6m_poolE
	.align 32
__ZN6dbgLog8category9container6m_poolE:
	.space 816
	.globl	__ZN6dbgLog8category9container15m_isAlreadyPoolE
	.align 4
__ZN6dbgLog8category9container15m_isAlreadyPoolE:
	.space 12
	.section	.text$_ZN6dbgLog15category_forAnyD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog15category_forAnyD1Ev
	.def	__ZN6dbgLog15category_forAnyD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog15category_forAnyD1Ev:
LFB3839:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh0ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3839:
	.section	.text$_ZN6dbgLog17category_forLogicD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_forLogicD1Ev
	.def	__ZN6dbgLog17category_forLogicD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_forLogicD1Ev:
LFB3842:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh1ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3842:
	.section	.text$_ZN6dbgLog20category_forResourceD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog20category_forResourceD1Ev
	.def	__ZN6dbgLog20category_forResourceD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog20category_forResourceD1Ev:
LFB3845:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh2ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3845:
	.section	.text$_ZN6dbgLog14category_for3DD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14category_for3DD1Ev
	.def	__ZN6dbgLog14category_for3DD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14category_for3DD1Ev:
LFB3848:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh3ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3848:
	.section	.text$_ZN6dbgLog14category_for2DD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14category_for2DD1Ev
	.def	__ZN6dbgLog14category_for2DD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14category_for2DD1Ev:
LFB3851:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh4ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3851:
	.section	.text$_ZN6dbgLog17category_forSoundD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_forSoundD1Ev
	.def	__ZN6dbgLog17category_forSoundD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_forSoundD1Ev:
LFB3854:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh5ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3854:
	.section	.text$_ZN6dbgLog18category_forScriptD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog18category_forScriptD1Ev
	.def	__ZN6dbgLog18category_forScriptD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog18category_forScriptD1Ev:
LFB3857:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh6ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3857:
	.section	.text$_ZN6dbgLog20category_forGameDataD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog20category_forGameDataD1Ev
	.def	__ZN6dbgLog20category_forGameDataD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog20category_forGameDataD1Ev:
LFB3860:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh7ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3860:
	.section	.text$_ZN6dbgLog17category_forEveryD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_forEveryD1Ev
	.def	__ZN6dbgLog17category_forEveryD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_forEveryD1Ev:
LFB3863:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog16category_specialILh64ELb0ELb0ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3863:
	.section	.text$_ZN6dbgLog22category_forCallppointD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog22category_forCallppointD1Ev
	.def	__ZN6dbgLog22category_forCallppointD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog22category_forCallppointD1Ev:
LFB3866:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog16category_specialILh65ELb1ELb1ELb0EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3866:
	.section	.text$_ZN6dbgLog30category_forCriticalCallppointD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog30category_forCriticalCallppointD1Ev
	.def	__ZN6dbgLog30category_forCriticalCallppointD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog30category_forCriticalCallppointD1Ev:
LFB3869:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog16category_specialILh66ELb1ELb1ELb0EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3869:
	.section	.text$_ZN6dbgLog12category_endD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12category_endD1Ev
	.def	__ZN6dbgLog12category_endD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12category_endD1Ev:
LFB3872:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3872:
	.text
	.align 2
	.globl	__ZN6dbgLog8category9container14initializeOnceEv
	.def	__ZN6dbgLog8category9container14initializeOnceEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container14initializeOnceEv:
LFB3836:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$216, %esp
	movzbl	__ZN6dbgLog8category9container15m_isInitializedE, %eax
	testb	%al, %al
	je	L275
	jmp	L274
L275:
	movb	$1, __ZN6dbgLog8category9container15m_isInitializedE
	movl	$__ZN6dbgLog8category9container15m_isAlreadyPoolE, (%esp)
	call	__ZNSt6bitsetILj68EE5resetEv
	movl	$816, 8(%esp)
	movl	$0, 4(%esp)
	movl	$__ZN6dbgLog8category9container6m_poolE, (%esp)
	call	_memset
	movl	$__ZN6dbgLog8category9container6m_poolE, __ZN6dbgLog8category9container9m_poolPtrE
	movb	$0, -9(%ebp)
	jmp	L277
L278:
	movzbl	-9(%ebp), %eax
	movl	$0, 24(%esp)
	movl	$0, 20(%esp)
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	$LC14, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC1EhPKcbbbb
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD1Ev
	movzbl	-9(%ebp), %edx
	leal	-164(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	$__ZN6dbgLog8category9container15m_isAlreadyPoolE, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj68EEixEj
	subl	$4, %esp
	movl	$0, 4(%esp)
	leal	-164(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj68EE9referenceaSEb
	leal	-164(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj68EE9referenceD1Ev
	addb	$1, -9(%ebp)
L277:
	cmpb	$66, -9(%ebp)
	jbe	L278
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog15category_forAnyC1Ev
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog15category_forAnyD1Ev
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_forLogicC1Ev
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_forLogicD1Ev
	leal	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog20category_forResourceC1Ev
	leal	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog20category_forResourceD1Ev
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog14category_for3DC1Ev
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog14category_for3DD1Ev
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog14category_for2DC1Ev
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog14category_for2DD1Ev
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_forSoundC1Ev
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_forSoundD1Ev
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog18category_forScriptC1Ev
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog18category_forScriptD1Ev
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog20category_forGameDataC1Ev
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog20category_forGameDataD1Ev
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_forEveryC1Ev
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_forEveryD1Ev
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog22category_forCallppointC1Ev
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog22category_forCallppointD1Ev
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog30category_forCriticalCallppointC1Ev
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog30category_forCriticalCallppointD1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12category_endC1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12category_endD1Ev
L274:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3836:
.lcomm __ZN6dbgLogL23s_categoryForInitializeE,12,4
	.section .rdata,"dr"
	.align 4
LC29:
	.ascii "category=%d, name=\"%s\", isAssigned=%d, isReserved=%d, forLog=%d, forNotice=%d, forMask=%d\12\0"
	.text
	.globl	__ZN6dbgLog16printCategoryAllEv
	.def	__ZN6dbgLog16printCategoryAllEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16printCategoryAllEv:
LFB3873:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3873
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	leal	-34(%ebp), %eax
	movl	%eax, -28(%ebp)
	leal	-35(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category9container5beginEv
	subl	$4, %esp
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category9container3endEv
	subl	$4, %esp
	jmp	L280
L281:
	leal	-35(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category8iteratordeEv
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category7forMaskEv
	movzbl	%al, %eax
	movl	%eax, -44(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category9forNoticeEv
	movzbl	%al, %ecx
	movl	%ecx, -48(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category6forLogEv
	movzbl	%al, %esi
	movl	%esi, -52(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category10isReservedEv
	movzbl	%al, %edi
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category10isAssignedEv
	movzbl	%al, %esi
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category4nameEv
	movl	%eax, %ebx
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category5valueEv
	movzbl	%al, %eax
	movl	-44(%ebp), %edx
	movl	%edx, 28(%esp)
	movl	-48(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-52(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC29, (%esp)
LEHB3:
	call	_printf
LEHE3:
	leal	-35(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category8iteratorppEv
L280:
	movzbl	-36(%ebp), %eax
	movb	%al, -33(%ebp)
	leal	-33(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-35(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category8iteratorneES1_
	movl	%eax, %ebx
	leal	-33(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category8iteratorD1Ev
	testb	%bl, %bl
	jne	L281
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category8iteratorD1Ev
	leal	-35(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category8iteratorD1Ev
	jmp	L284
L283:
	movl	%eax, %ebx
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category8iteratorD1Ev
	leal	-35(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category8iteratorD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB4:
	call	__Unwind_Resume
LEHE4:
L284:
	leal	-12(%ebp), %esp
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
LFE3873:
	.section	.gcc_except_table,"w"
LLSDA3873:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3873-LLSDACSB3873
LLSDACSB3873:
	.uleb128 LEHB3-LFB3873
	.uleb128 LEHE3-LEHB3
	.uleb128 L283-LFB3873
	.uleb128 0
	.uleb128 LEHB4-LFB3873
	.uleb128 LEHE4-LEHB4
	.uleb128 0
	.uleb128 0
LLSDACSE3873:
	.text
	.section	.text$_ZN6dbgLog3log16resetLogLevelAllEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log16resetLogLevelAllEv
	.def	__ZN6dbgLog3log16resetLogLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log16resetLogLevelAllEv:
LFB3874:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$__ZN6dbgLog3log10m_logLevelE, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-8(%ebp), %eax
	addl	$64, %eax
	movl	%eax, -12(%ebp)
	jmp	L286
L287:
	movl	-4(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movb	$2, (%eax)
	addl	$1, -4(%ebp)
L286:
	movl	-4(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jne	L287
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3874:
	.section	.text$_ZN6dbgLog3log19resetNoticeLevelAllEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log19resetNoticeLevelAllEv
	.def	__ZN6dbgLog3log19resetNoticeLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log19resetNoticeLevelAllEv:
LFB3875:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$__ZN6dbgLog3log13m_noticeLevelE, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-8(%ebp), %eax
	addl	$64, %eax
	movl	%eax, -12(%ebp)
	jmp	L289
L290:
	movl	-4(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movb	$8, (%eax)
	addl	$1, -4(%ebp)
L289:
	movl	-4(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jne	L290
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3875:
	.section .rdata,"dr"
LC30:
	.ascii "o_category.forMask() == true\0"
LC31:
	.ascii "o_category.forLog() == true\0"
	.section	.text$_ZN6dbgLog3log11getLogLevelEh,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log11getLogLevelEh
	.def	__ZN6dbgLog3log11getLogLevelEh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log11getLogLevelEh:
LFB3876:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	movzbl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category3getEh
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category7forMaskEv
	testb	%al, %al
	jne	L292
	movl	$LC30, 12(%esp)
	movl	$__ZZN6dbgLog3log11getLogLevelEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1052, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L292:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category6forLogEv
	testb	%al, %al
	jne	L293
	movl	$LC31, 12(%esp)
	movl	$__ZZN6dbgLog3log11getLogLevelEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1053, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L293:
	movzbl	-28(%ebp), %eax
	movzbl	__ZN6dbgLog3log10m_logLevelE(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3876:
	.section .rdata,"dr"
LC32:
	.ascii "o_level.forMask() == true\0"
	.section	.text$_ZN6dbgLog3log11setLogLevelEhh,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log11setLogLevelEhh
	.def	__ZN6dbgLog3log11setLogLevelEhh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log11setLogLevelEhh:
LFB3877:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$72, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movb	%dl, -44(%ebp)
	movb	%al, -48(%ebp)
	movzbl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level3getEh
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level7forMaskEv
	testb	%al, %al
	jne	L296
	movl	$LC32, 12(%esp)
	movl	$__ZZN6dbgLog3log11setLogLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1062, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L296:
	movzbl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category3getEh
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category7forMaskEv
	testb	%al, %al
	jne	L297
	movl	$LC30, 12(%esp)
	movl	$__ZZN6dbgLog3log11setLogLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1064, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L297:
	cmpb	$64, -44(%ebp)
	jne	L298
	movzbl	__ZN6dbgLog3log10m_logLevelE, %eax
	movb	%al, -21(%ebp)
	movl	$__ZN6dbgLog3log10m_logLevelE, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-28(%ebp), %eax
	addl	$64, %eax
	movl	%eax, -32(%ebp)
	jmp	L299
L300:
	movl	-12(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movzbl	-48(%ebp), %edx
	movb	%dl, (%eax)
	addl	$1, -12(%ebp)
L299:
	movl	-12(%ebp), %eax
	cmpl	-32(%ebp), %eax
	jne	L300
	movzbl	-21(%ebp), %eax
	jmp	L301
L298:
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category6forLogEv
	testb	%al, %al
	jne	L302
	movl	$LC31, 12(%esp)
	movl	$__ZZN6dbgLog3log11setLogLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1072, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L302:
	movzbl	-44(%ebp), %eax
	movzbl	__ZN6dbgLog3log10m_logLevelE(%eax), %eax
	movb	%al, -37(%ebp)
	movzbl	-44(%ebp), %eax
	movzbl	-48(%ebp), %edx
	movb	%dl, __ZN6dbgLog3log10m_logLevelE(%eax)
	movzbl	-37(%ebp), %eax
L301:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3877:
	.section .rdata,"dr"
	.align 4
LC33:
	.ascii "o_category.forNotice() == true\0"
	.section	.text$_ZN6dbgLog3log14getNoticeLevelEh,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log14getNoticeLevelEh
	.def	__ZN6dbgLog3log14getNoticeLevelEh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log14getNoticeLevelEh:
LFB3878:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	movzbl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category3getEh
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category7forMaskEv
	testb	%al, %al
	jne	L304
	movl	$LC30, 12(%esp)
	movl	$__ZZN6dbgLog3log14getNoticeLevelEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1081, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L304:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category9forNoticeEv
	testb	%al, %al
	jne	L305
	movl	$LC33, 12(%esp)
	movl	$__ZZN6dbgLog3log14getNoticeLevelEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1082, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L305:
	movzbl	-28(%ebp), %eax
	movzbl	__ZN6dbgLog3log13m_noticeLevelE(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3878:
	.section	.text$_ZN6dbgLog3log14setNoticeLevelEhh,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log14setNoticeLevelEhh
	.def	__ZN6dbgLog3log14setNoticeLevelEhh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log14setNoticeLevelEhh:
LFB3879:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$72, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movb	%dl, -44(%ebp)
	movb	%al, -48(%ebp)
	movzbl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level3getEh
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level7forMaskEv
	testb	%al, %al
	jne	L308
	movl	$LC32, 12(%esp)
	movl	$__ZZN6dbgLog3log14setNoticeLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1091, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L308:
	movzbl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category3getEh
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category7forMaskEv
	testb	%al, %al
	jne	L309
	movl	$LC30, 12(%esp)
	movl	$__ZZN6dbgLog3log14setNoticeLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1093, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L309:
	cmpb	$64, -44(%ebp)
	jne	L310
	movzbl	__ZN6dbgLog3log13m_noticeLevelE, %eax
	movb	%al, -21(%ebp)
	movl	$__ZN6dbgLog3log13m_noticeLevelE, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-28(%ebp), %eax
	addl	$64, %eax
	movl	%eax, -32(%ebp)
	jmp	L311
L312:
	movl	-12(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movzbl	-48(%ebp), %edx
	movb	%dl, (%eax)
	addl	$1, -12(%ebp)
L311:
	movl	-12(%ebp), %eax
	cmpl	-32(%ebp), %eax
	jne	L312
	movzbl	-21(%ebp), %eax
	jmp	L313
L310:
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category9forNoticeEv
	testb	%al, %al
	jne	L314
	movl	$LC33, 12(%esp)
	movl	$__ZZN6dbgLog3log14setNoticeLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1101, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L314:
	movzbl	-44(%ebp), %eax
	movzbl	__ZN6dbgLog3log13m_noticeLevelE(%eax), %eax
	movb	%al, -37(%ebp)
	movzbl	-44(%ebp), %eax
	movzbl	-48(%ebp), %edx
	movb	%dl, __ZN6dbgLog3log13m_noticeLevelE(%eax)
	movzbl	-37(%ebp), %eax
L313:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3879:
	.section .rdata,"dr"
	.align 4
LC34:
	.ascii "o_level.forLog() == true || o_level.forNotice() == true\0"
	.align 4
LC35:
	.ascii "o_category.forLog() == true || o_category.forNotice() == true\0"
	.section	.text$_ZN6dbgLog3log6vprintEhhhhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log6vprintEhhhhPKcPc
	.def	__ZN6dbgLog3log6vprintEhhhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log6vprintEhhhhPKcPc:
LFB3880:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3880
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$84, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %ebx
	movl	12(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%bl, -60(%ebp)
	movb	%cl, -64(%ebp)
	movb	%dl, -68(%ebp)
	movb	%al, -72(%ebp)
	movzbl	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level3getEh
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level6forLogEv
	xorl	$1, %eax
	testb	%al, %al
	je	L316
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level9forNoticeEv
	xorl	$1, %eax
	testb	%al, %al
	je	L316
	movl	$LC34, 12(%esp)
	movl	$__ZZN6dbgLog3log6vprintEhhhhPKcPcE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1112, 4(%esp)
	movl	$LC3, (%esp)
LEHB5:
	call	___assert_func
L316:
	movzbl	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category3getEh
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category6forLogEv
	xorl	$1, %eax
	testb	%al, %al
	je	L317
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category9forNoticeEv
	xorl	$1, %eax
	testb	%al, %al
	je	L317
	movl	$LC35, 12(%esp)
	movl	$__ZZN6dbgLog3log6vprintEhhhhPKcPcE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1114, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
LEHE5:
L317:
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	movzbl	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level3getEh
	movl	%eax, -28(%ebp)
	movzbl	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level3getEh
	movl	%eax, -32(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5levelgeERKS0_
	testb	%al, %al
	je	L318
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level6forLogEv
	testb	%al, %al
	je	L318
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category6forLogEv
	testb	%al, %al
	je	L318
	movl	$1, %eax
	jmp	L319
L318:
	movl	$0, %eax
L319:
	testb	%al, %al
	je	L320
	leal	-38(%ebp), %eax
	movl	$0, 8(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB6:
	call	__ZNK6dbgLog5level11changeColorEb
LEHE6:
	subl	$4, %esp
LEHB7:
	call	___getreent
	movl	8(%eax), %eax
	movl	28(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_vfprintf
LEHE7:
	movl	%eax, -12(%ebp)
	leal	-38(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5colorD1Ev
L320:
	movl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5levelgeERKS0_
	testb	%al, %al
	je	L321
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level9forNoticeEv
	testb	%al, %al
	je	L321
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category9forNoticeEv
	testb	%al, %al
	je	L321
	movl	$1, %eax
	jmp	L322
L321:
	movl	$0, %eax
L322:
	testb	%al, %al
	je	L323
	leal	-44(%ebp), %eax
	movl	$0, 8(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB8:
	call	__ZNK6dbgLog5level20changeColorForNoticeEb
LEHE8:
	subl	$4, %esp
LEHB9:
	call	___getreent
	movl	12(%eax), %eax
	movl	28(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_vfprintf
LEHE9:
	movl	%eax, -16(%ebp)
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5colorD1Ev
L323:
	movl	-12(%ebp), %eax
	cmpl	-16(%ebp), %eax
	jle	L324
	movl	-12(%ebp), %eax
	jmp	L335
L324:
	movl	-16(%ebp), %eax
	jmp	L335
L332:
	movl	%eax, %ebx
	leal	-38(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5colorD1Ev
	movl	%ebx, %eax
	jmp	L328
L331:
L328:
	movl	%eax, (%esp)
LEHB10:
	call	__Unwind_Resume
L334:
	movl	%eax, %ebx
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5colorD1Ev
	movl	%ebx, %eax
	jmp	L330
L333:
L330:
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE10:
L335:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3880:
	.section	.gcc_except_table,"w"
LLSDA3880:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3880-LLSDACSB3880
LLSDACSB3880:
	.uleb128 LEHB5-LFB3880
	.uleb128 LEHE5-LEHB5
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB6-LFB3880
	.uleb128 LEHE6-LEHB6
	.uleb128 L331-LFB3880
	.uleb128 0
	.uleb128 LEHB7-LFB3880
	.uleb128 LEHE7-LEHB7
	.uleb128 L332-LFB3880
	.uleb128 0
	.uleb128 LEHB8-LFB3880
	.uleb128 LEHE8-LEHB8
	.uleb128 L333-LFB3880
	.uleb128 0
	.uleb128 LEHB9-LFB3880
	.uleb128 LEHE9-LEHB9
	.uleb128 L334-LFB3880
	.uleb128 0
	.uleb128 LEHB10-LFB3880
	.uleb128 LEHE10-LEHB10
	.uleb128 0
	.uleb128 0
LLSDACSE3880:
	.section	.text$_ZN6dbgLog3log6vprintEhhhhPKcPc,"x"
	.linkonce discard
	.section	.text$_ZN6dbgLog3log6vprintEhhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log6vprintEhhPKcPc
	.def	__ZN6dbgLog3log6vprintEhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log6vprintEhhPKcPc:
LFB3881:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$48, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movb	%dl, -28(%ebp)
	movb	%al, -32(%ebp)
	movzbl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3log11getLogLevelEh
	movb	%al, -9(%ebp)
	movzbl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3log14getNoticeLevelEh
	movb	%al, -10(%ebp)
	movzbl	-32(%ebp), %ebx
	movzbl	-28(%ebp), %ecx
	movzbl	-10(%ebp), %edx
	movzbl	-9(%ebp), %eax
	movl	20(%ebp), %esi
	movl	%esi, 20(%esp)
	movl	16(%ebp), %esi
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog3log6vprintEhhhhPKcPc
	addl	$48, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3881:
	.section	.text$_ZN6dbgLog3log4vlogEhhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log4vlogEhhPKcPc
	.def	__ZN6dbgLog3log4vlogEhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log4vlogEhhPKcPc:
LFB3882:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movb	%dl, -28(%ebp)
	movb	%al, -32(%ebp)
	movzbl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3log11getLogLevelEh
	movb	%al, -9(%ebp)
	movb	$12, -10(%ebp)
	movzbl	-32(%ebp), %ecx
	movzbl	-28(%ebp), %edx
	movzbl	-9(%ebp), %eax
	movl	20(%ebp), %ebx
	movl	%ebx, 20(%esp)
	movl	16(%ebp), %ebx
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	$12, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog3log6vprintEhhhhPKcPc
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3882:
	.section	.text$_ZN6dbgLog3log7vnoticeEhhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log7vnoticeEhhPKcPc
	.def	__ZN6dbgLog3log7vnoticeEhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log7vnoticeEhhPKcPc:
LFB3883:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movb	%dl, -28(%ebp)
	movb	%al, -32(%ebp)
	movb	$12, -9(%ebp)
	movzbl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3log14getNoticeLevelEh
	movb	%al, -10(%ebp)
	movzbl	-32(%ebp), %ecx
	movzbl	-28(%ebp), %edx
	movzbl	-10(%ebp), %eax
	movl	20(%ebp), %ebx
	movl	%ebx, 20(%esp)
	movl	16(%ebp), %ebx
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$12, (%esp)
	call	__ZN6dbgLog3log6vprintEhhhhPKcPc
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3883:
	.section	.text$_ZN6dbgLog3log14vprintAsNormalEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log14vprintAsNormalEhPKcPc
	.def	__ZN6dbgLog3log14vprintAsNormalEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log14vprintAsNormalEhPKcPc:
LFB3887:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$2, (%esp)
	call	__ZN6dbgLog3log6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3887:
	.section	.text$_ZN6dbgLog3log12vlogAsNormalEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log12vlogAsNormalEhPKcPc
	.def	__ZN6dbgLog3log12vlogAsNormalEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log12vlogAsNormalEhPKcPc:
LFB3888:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$2, (%esp)
	call	__ZN6dbgLog3log4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3888:
	.section	.text$_ZN6dbgLog3log15vnoticeAsNormalEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log15vnoticeAsNormalEhPKcPc
	.def	__ZN6dbgLog3log15vnoticeAsNormalEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log15vnoticeAsNormalEhPKcPc:
LFB3889:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$2, (%esp)
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3889:
	.section	.text$_ZN6dbgLog3log15vprintAsVerboseEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log15vprintAsVerboseEhPKcPc
	.def	__ZN6dbgLog3log15vprintAsVerboseEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log15vprintAsVerboseEhPKcPc:
LFB3890:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	__ZN6dbgLog3log6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3890:
	.section	.text$_ZN6dbgLog3log13vlogAsVerboseEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log13vlogAsVerboseEhPKcPc
	.def	__ZN6dbgLog3log13vlogAsVerboseEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log13vlogAsVerboseEhPKcPc:
LFB3891:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	__ZN6dbgLog3log4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3891:
	.section	.text$_ZN6dbgLog3log16vnoticeAsVerboseEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log16vnoticeAsVerboseEhPKcPc
	.def	__ZN6dbgLog3log16vnoticeAsVerboseEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log16vnoticeAsVerboseEhPKcPc:
LFB3892:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3892:
	.section	.text$_ZN6dbgLog3log14vprintAsDetailEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log14vprintAsDetailEhPKcPc
	.def	__ZN6dbgLog3log14vprintAsDetailEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log14vprintAsDetailEhPKcPc:
LFB3893:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	call	__ZN6dbgLog3log6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3893:
	.section	.text$_ZN6dbgLog3log12vlogAsDetailEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log12vlogAsDetailEhPKcPc
	.def	__ZN6dbgLog3log12vlogAsDetailEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log12vlogAsDetailEhPKcPc:
LFB3894:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	call	__ZN6dbgLog3log4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3894:
	.section	.text$_ZN6dbgLog3log15vnoticeAsDetailEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log15vnoticeAsDetailEhPKcPc
	.def	__ZN6dbgLog3log15vnoticeAsDetailEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log15vnoticeAsDetailEhPKcPc:
LFB3895:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3895:
	.section	.text$_ZN6dbgLog3log17vprintAsImportantEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log17vprintAsImportantEhPKcPc
	.def	__ZN6dbgLog3log17vprintAsImportantEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log17vprintAsImportantEhPKcPc:
LFB3896:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZN6dbgLog3log6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3896:
	.section	.text$_ZN6dbgLog3log15vlogAsImportantEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log15vlogAsImportantEhPKcPc
	.def	__ZN6dbgLog3log15vlogAsImportantEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log15vlogAsImportantEhPKcPc:
LFB3897:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZN6dbgLog3log4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3897:
	.section	.text$_ZN6dbgLog3log18vnoticeAsImportantEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log18vnoticeAsImportantEhPKcPc
	.def	__ZN6dbgLog3log18vnoticeAsImportantEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log18vnoticeAsImportantEhPKcPc:
LFB3898:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3898:
	.section	.text$_ZN6dbgLog3log15vprintAsWarningEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log15vprintAsWarningEhPKcPc
	.def	__ZN6dbgLog3log15vprintAsWarningEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log15vprintAsWarningEhPKcPc:
LFB3899:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$6, (%esp)
	call	__ZN6dbgLog3log6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3899:
	.section	.text$_ZN6dbgLog3log13vlogAsWarningEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log13vlogAsWarningEhPKcPc
	.def	__ZN6dbgLog3log13vlogAsWarningEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log13vlogAsWarningEhPKcPc:
LFB3900:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$6, (%esp)
	call	__ZN6dbgLog3log4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3900:
	.section	.text$_ZN6dbgLog3log16vnoticeAsWarningEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log16vnoticeAsWarningEhPKcPc
	.def	__ZN6dbgLog3log16vnoticeAsWarningEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log16vnoticeAsWarningEhPKcPc:
LFB3901:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$6, (%esp)
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3901:
	.section	.text$_ZN6dbgLog3log16vprintAsCriticalEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log16vprintAsCriticalEhPKcPc
	.def	__ZN6dbgLog3log16vprintAsCriticalEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log16vprintAsCriticalEhPKcPc:
LFB3902:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZN6dbgLog3log6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3902:
	.section	.text$_ZN6dbgLog3log14vlogAsCriticalEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log14vlogAsCriticalEhPKcPc
	.def	__ZN6dbgLog3log14vlogAsCriticalEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log14vlogAsCriticalEhPKcPc:
LFB3903:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZN6dbgLog3log4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3903:
	.section	.text$_ZN6dbgLog3log17vnoticeAsCriticalEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log17vnoticeAsCriticalEhPKcPc
	.def	__ZN6dbgLog3log17vnoticeAsCriticalEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log17vnoticeAsCriticalEhPKcPc:
LFB3904:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3904:
	.section	.text$_ZN6dbgLog3log16vprintAsAbsoluteEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log16vprintAsAbsoluteEhPKcPc
	.def	__ZN6dbgLog3log16vprintAsAbsoluteEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log16vprintAsAbsoluteEhPKcPc:
LFB3905:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$10, (%esp)
	call	__ZN6dbgLog3log6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3905:
	.section	.text$_ZN6dbgLog3log14vlogAsAbsoluteEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log14vlogAsAbsoluteEhPKcPc
	.def	__ZN6dbgLog3log14vlogAsAbsoluteEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log14vlogAsAbsoluteEhPKcPc:
LFB3906:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$10, (%esp)
	call	__ZN6dbgLog3log4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3906:
	.section	.text$_ZN6dbgLog3log17vnoticeAsAbsoluteEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log17vnoticeAsAbsoluteEhPKcPc
	.def	__ZN6dbgLog3log17vnoticeAsAbsoluteEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log17vnoticeAsAbsoluteEhPKcPc:
LFB3907:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$10, (%esp)
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3907:
	.section	.text$_ZN6dbgLog3logC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3logC1Ev
	.def	__ZN6dbgLog3logC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3logC1Ev:
LFB3931:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	__ZN6dbgLog3log14initializeOnceEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3931:
	.section	.text$_ZN6dbgLog3logD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3logD1Ev
	.def	__ZN6dbgLog3logD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3logD1Ev:
LFB3937:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3937:
	.globl	__ZN6dbgLog3log15m_isInitializedE
	.bss
__ZN6dbgLog3log15m_isInitializedE:
	.space 1
	.globl	__ZN6dbgLog3log10m_logLevelE
	.align 32
__ZN6dbgLog3log10m_logLevelE:
	.space 64
	.globl	__ZN6dbgLog3log13m_noticeLevelE
	.align 32
__ZN6dbgLog3log13m_noticeLevelE:
	.space 64
	.text
	.align 2
	.globl	__ZN6dbgLog3log14initializeOnceEv
	.def	__ZN6dbgLog3log14initializeOnceEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log14initializeOnceEv:
LFB3938:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movzbl	__ZN6dbgLog3log15m_isInitializedE, %eax
	testb	%al, %al
	je	L388
	jmp	L387
L388:
	movb	$1, __ZN6dbgLog3log15m_isInitializedE
	call	__ZN6dbgLog3log16resetLogLevelAllEv
	call	__ZN6dbgLog3log19resetNoticeLevelAllEv
L387:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3938:
.lcomm __ZN6dbgLogL18s_logForInitializeE,132,32
	.globl	__ZN6dbgLog16resetLogLevelAllEv
	.def	__ZN6dbgLog16resetLogLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16resetLogLevelAllEv:
LFB3939:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__ZN6dbgLog3log16resetLogLevelAllEv
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3939:
	.globl	__ZN6dbgLog19resetNoticeLevelAllEv
	.def	__ZN6dbgLog19resetNoticeLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog19resetNoticeLevelAllEv:
LFB3940:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__ZN6dbgLog3log19resetNoticeLevelAllEv
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3940:
	.globl	__ZN6dbgLog11getLogLevelEh
	.def	__ZN6dbgLog11getLogLevelEh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog11getLogLevelEh:
LFB3941:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3log11getLogLevelEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3941:
	.globl	__ZN6dbgLog11setLogLevelEhh
	.def	__ZN6dbgLog11setLogLevelEhh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog11setLogLevelEhh:
LFB3942:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movb	%dl, -12(%ebp)
	movb	%al, -16(%ebp)
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog3log11setLogLevelEhh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3942:
	.globl	__ZN6dbgLog14getNoticeLevelEh
	.def	__ZN6dbgLog14getNoticeLevelEh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14getNoticeLevelEh:
LFB3943:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3log14getNoticeLevelEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3943:
	.globl	__ZN6dbgLog14setNoticeLevelEhh
	.def	__ZN6dbgLog14setNoticeLevelEhh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14setNoticeLevelEhh:
LFB3944:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movb	%dl, -12(%ebp)
	movb	%al, -16(%ebp)
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog3log14setNoticeLevelEhh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3944:
	.def	__ZN6dbgLogL6vprintEhhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL6vprintEhhPKcPc:
LFB3945:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movb	%dl, -12(%ebp)
	movb	%al, -16(%ebp)
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	20(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog3log6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3945:
	.def	__ZN6dbgLogL4vlogEhhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL4vlogEhhPKcPc:
LFB3946:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movb	%dl, -12(%ebp)
	movb	%al, -16(%ebp)
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	20(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog3log4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3946:
	.def	__ZN6dbgLogL7vnoticeEhhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL7vnoticeEhhPKcPc:
LFB3947:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movb	%dl, -12(%ebp)
	movb	%al, -16(%ebp)
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	20(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3947:
	.def	__ZN6dbgLogL5printEhhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL5printEhhPKcz:
LFB3948:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3948
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movb	%dl, -28(%ebp)
	movb	%al, -32(%ebp)
	leal	20(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %ecx
	movzbl	-32(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%ecx, 12(%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB11:
	call	__ZN6dbgLog3log6vprintEhhPKcPc
LEHE11:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L410
L409:
	movl	%eax, (%esp)
LEHB12:
	call	__Unwind_Resume
LEHE12:
L410:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3948:
	.section	.gcc_except_table,"w"
LLSDA3948:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3948-LLSDACSB3948
LLSDACSB3948:
	.uleb128 LEHB11-LFB3948
	.uleb128 LEHE11-LEHB11
	.uleb128 L409-LFB3948
	.uleb128 0
	.uleb128 LEHB12-LFB3948
	.uleb128 LEHE12-LEHB12
	.uleb128 0
	.uleb128 0
LLSDACSE3948:
	.text
	.def	__ZN6dbgLogL4log_EhhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL4log_EhhPKcz:
LFB3949:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3949
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movb	%dl, -28(%ebp)
	movb	%al, -32(%ebp)
	leal	20(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %ecx
	movzbl	-32(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%ecx, 12(%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB13:
	call	__ZN6dbgLog3log4vlogEhhPKcPc
LEHE13:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L415
L414:
	movl	%eax, (%esp)
LEHB14:
	call	__Unwind_Resume
LEHE14:
L415:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3949:
	.section	.gcc_except_table,"w"
LLSDA3949:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3949-LLSDACSB3949
LLSDACSB3949:
	.uleb128 LEHB13-LFB3949
	.uleb128 LEHE13-LEHB13
	.uleb128 L414-LFB3949
	.uleb128 0
	.uleb128 LEHB14-LFB3949
	.uleb128 LEHE14-LEHB14
	.uleb128 0
	.uleb128 0
LLSDACSE3949:
	.text
	.def	__ZN6dbgLogL6noticeEhhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL6noticeEhhPKcz:
LFB3950:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3950
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movb	%dl, -28(%ebp)
	movb	%al, -32(%ebp)
	leal	20(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %ecx
	movzbl	-32(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%ecx, 12(%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB15:
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
LEHE15:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L420
L419:
	movl	%eax, (%esp)
LEHB16:
	call	__Unwind_Resume
LEHE16:
L420:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3950:
	.section	.gcc_except_table,"w"
LLSDA3950:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3950-LLSDACSB3950
LLSDACSB3950:
	.uleb128 LEHB15-LFB3950
	.uleb128 LEHE15-LEHB15
	.uleb128 L419-LFB3950
	.uleb128 0
	.uleb128 LEHB16-LFB3950
	.uleb128 LEHE16-LEHB16
	.uleb128 0
	.uleb128 0
LLSDACSE3950:
	.text
	.def	__ZN6dbgLogL14vprintAsNormalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL14vprintAsNormalEhPKcPc:
LFB3951:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$2, (%esp)
	call	__ZN6dbgLog3log6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3951:
	.def	__ZN6dbgLogL12vlogAsNormalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL12vlogAsNormalEhPKcPc:
LFB3952:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$2, (%esp)
	call	__ZN6dbgLog3log4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3952:
	.def	__ZN6dbgLogL15vnoticeAsNormalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL15vnoticeAsNormalEhPKcPc:
LFB3953:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$2, (%esp)
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3953:
	.def	__ZN6dbgLogL15vprintAsVerboseEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL15vprintAsVerboseEhPKcPc:
LFB3954:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	__ZN6dbgLog3log6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3954:
	.def	__ZN6dbgLogL13vlogAsVerboseEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL13vlogAsVerboseEhPKcPc:
LFB3955:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	__ZN6dbgLog3log4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3955:
	.def	__ZN6dbgLogL16vnoticeAsVerboseEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL16vnoticeAsVerboseEhPKcPc:
LFB3956:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3956:
	.def	__ZN6dbgLogL14vprintAsDetailEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL14vprintAsDetailEhPKcPc:
LFB3957:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	call	__ZN6dbgLog3log6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3957:
	.def	__ZN6dbgLogL12vlogAsDetailEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL12vlogAsDetailEhPKcPc:
LFB3958:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	call	__ZN6dbgLog3log4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3958:
	.def	__ZN6dbgLogL15vnoticeAsDetailEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL15vnoticeAsDetailEhPKcPc:
LFB3959:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3959:
	.def	__ZN6dbgLogL17vprintAsImportantEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL17vprintAsImportantEhPKcPc:
LFB3960:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZN6dbgLog3log6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3960:
	.def	__ZN6dbgLogL15vlogAsImportantEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL15vlogAsImportantEhPKcPc:
LFB3961:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZN6dbgLog3log4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3961:
	.def	__ZN6dbgLogL18vnoticeAsImportantEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL18vnoticeAsImportantEhPKcPc:
LFB3962:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3962:
	.def	__ZN6dbgLogL15vprintAsWarningEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL15vprintAsWarningEhPKcPc:
LFB3963:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$6, (%esp)
	call	__ZN6dbgLog3log6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3963:
	.def	__ZN6dbgLogL13vlogAsWarningEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL13vlogAsWarningEhPKcPc:
LFB3964:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$6, (%esp)
	call	__ZN6dbgLog3log4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3964:
	.def	__ZN6dbgLogL16vnoticeAsWarningEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL16vnoticeAsWarningEhPKcPc:
LFB3965:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$6, (%esp)
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3965:
	.def	__ZN6dbgLogL16vprintAsCriticalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL16vprintAsCriticalEhPKcPc:
LFB3966:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZN6dbgLog3log6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3966:
	.def	__ZN6dbgLogL14vlogAsCriticalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL14vlogAsCriticalEhPKcPc:
LFB3967:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZN6dbgLog3log4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3967:
	.def	__ZN6dbgLogL17vnoticeAsCriticalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL17vnoticeAsCriticalEhPKcPc:
LFB3968:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3968:
	.def	__ZN6dbgLogL16vprintAsAbsoluteEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL16vprintAsAbsoluteEhPKcPc:
LFB3969:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$10, (%esp)
	call	__ZN6dbgLog3log6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3969:
	.def	__ZN6dbgLogL14vlogAsAbsoluteEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL14vlogAsAbsoluteEhPKcPc:
LFB3970:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$10, (%esp)
	call	__ZN6dbgLog3log4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3970:
	.def	__ZN6dbgLogL17vnoticeAsAbsoluteEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL17vnoticeAsAbsoluteEhPKcPc:
LFB3971:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$10, (%esp)
	call	__ZN6dbgLog3log7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3971:
	.def	__ZN6dbgLogL13printAsNormalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL13printAsNormalEhPKcz:
LFB3972:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3972
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB17:
	call	__ZN6dbgLog3log14vprintAsNormalEhPKcPc
LEHE17:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L467
L466:
	movl	%eax, (%esp)
LEHB18:
	call	__Unwind_Resume
LEHE18:
L467:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3972:
	.section	.gcc_except_table,"w"
LLSDA3972:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3972-LLSDACSB3972
LLSDACSB3972:
	.uleb128 LEHB17-LFB3972
	.uleb128 LEHE17-LEHB17
	.uleb128 L466-LFB3972
	.uleb128 0
	.uleb128 LEHB18-LFB3972
	.uleb128 LEHE18-LEHB18
	.uleb128 0
	.uleb128 0
LLSDACSE3972:
	.text
	.def	__ZN6dbgLogL11logAsNormalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL11logAsNormalEhPKcz:
LFB3973:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3973
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB19:
	call	__ZN6dbgLog3log12vlogAsNormalEhPKcPc
LEHE19:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L472
L471:
	movl	%eax, (%esp)
LEHB20:
	call	__Unwind_Resume
LEHE20:
L472:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3973:
	.section	.gcc_except_table,"w"
LLSDA3973:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3973-LLSDACSB3973
LLSDACSB3973:
	.uleb128 LEHB19-LFB3973
	.uleb128 LEHE19-LEHB19
	.uleb128 L471-LFB3973
	.uleb128 0
	.uleb128 LEHB20-LFB3973
	.uleb128 LEHE20-LEHB20
	.uleb128 0
	.uleb128 0
LLSDACSE3973:
	.text
	.def	__ZN6dbgLogL14noticeAsNormalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL14noticeAsNormalEhPKcz:
LFB3974:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3974
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB21:
	call	__ZN6dbgLog3log15vnoticeAsNormalEhPKcPc
LEHE21:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L477
L476:
	movl	%eax, (%esp)
LEHB22:
	call	__Unwind_Resume
LEHE22:
L477:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3974:
	.section	.gcc_except_table,"w"
LLSDA3974:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3974-LLSDACSB3974
LLSDACSB3974:
	.uleb128 LEHB21-LFB3974
	.uleb128 LEHE21-LEHB21
	.uleb128 L476-LFB3974
	.uleb128 0
	.uleb128 LEHB22-LFB3974
	.uleb128 LEHE22-LEHB22
	.uleb128 0
	.uleb128 0
LLSDACSE3974:
	.text
	.def	__ZN6dbgLogL14printAsVerboseEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL14printAsVerboseEhPKcz:
LFB3975:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3975
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB23:
	call	__ZN6dbgLog3log15vprintAsVerboseEhPKcPc
LEHE23:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L482
L481:
	movl	%eax, (%esp)
LEHB24:
	call	__Unwind_Resume
LEHE24:
L482:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3975:
	.section	.gcc_except_table,"w"
LLSDA3975:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3975-LLSDACSB3975
LLSDACSB3975:
	.uleb128 LEHB23-LFB3975
	.uleb128 LEHE23-LEHB23
	.uleb128 L481-LFB3975
	.uleb128 0
	.uleb128 LEHB24-LFB3975
	.uleb128 LEHE24-LEHB24
	.uleb128 0
	.uleb128 0
LLSDACSE3975:
	.text
	.def	__ZN6dbgLogL12logAsVerboseEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL12logAsVerboseEhPKcz:
LFB3976:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3976
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB25:
	call	__ZN6dbgLog3log13vlogAsVerboseEhPKcPc
LEHE25:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L487
L486:
	movl	%eax, (%esp)
LEHB26:
	call	__Unwind_Resume
LEHE26:
L487:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3976:
	.section	.gcc_except_table,"w"
LLSDA3976:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3976-LLSDACSB3976
LLSDACSB3976:
	.uleb128 LEHB25-LFB3976
	.uleb128 LEHE25-LEHB25
	.uleb128 L486-LFB3976
	.uleb128 0
	.uleb128 LEHB26-LFB3976
	.uleb128 LEHE26-LEHB26
	.uleb128 0
	.uleb128 0
LLSDACSE3976:
	.text
	.def	__ZN6dbgLogL15noticeAsVerboseEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL15noticeAsVerboseEhPKcz:
LFB3977:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3977
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB27:
	call	__ZN6dbgLog3log16vnoticeAsVerboseEhPKcPc
LEHE27:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L492
L491:
	movl	%eax, (%esp)
LEHB28:
	call	__Unwind_Resume
LEHE28:
L492:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3977:
	.section	.gcc_except_table,"w"
LLSDA3977:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3977-LLSDACSB3977
LLSDACSB3977:
	.uleb128 LEHB27-LFB3977
	.uleb128 LEHE27-LEHB27
	.uleb128 L491-LFB3977
	.uleb128 0
	.uleb128 LEHB28-LFB3977
	.uleb128 LEHE28-LEHB28
	.uleb128 0
	.uleb128 0
LLSDACSE3977:
	.text
	.def	__ZN6dbgLogL13printAsDetailEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL13printAsDetailEhPKcz:
LFB3978:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3978
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB29:
	call	__ZN6dbgLog3log14vprintAsDetailEhPKcPc
LEHE29:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L497
L496:
	movl	%eax, (%esp)
LEHB30:
	call	__Unwind_Resume
LEHE30:
L497:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3978:
	.section	.gcc_except_table,"w"
LLSDA3978:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3978-LLSDACSB3978
LLSDACSB3978:
	.uleb128 LEHB29-LFB3978
	.uleb128 LEHE29-LEHB29
	.uleb128 L496-LFB3978
	.uleb128 0
	.uleb128 LEHB30-LFB3978
	.uleb128 LEHE30-LEHB30
	.uleb128 0
	.uleb128 0
LLSDACSE3978:
	.text
	.def	__ZN6dbgLogL11logAsDetailEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL11logAsDetailEhPKcz:
LFB3979:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3979
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB31:
	call	__ZN6dbgLog3log12vlogAsDetailEhPKcPc
LEHE31:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L502
L501:
	movl	%eax, (%esp)
LEHB32:
	call	__Unwind_Resume
LEHE32:
L502:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3979:
	.section	.gcc_except_table,"w"
LLSDA3979:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3979-LLSDACSB3979
LLSDACSB3979:
	.uleb128 LEHB31-LFB3979
	.uleb128 LEHE31-LEHB31
	.uleb128 L501-LFB3979
	.uleb128 0
	.uleb128 LEHB32-LFB3979
	.uleb128 LEHE32-LEHB32
	.uleb128 0
	.uleb128 0
LLSDACSE3979:
	.text
	.def	__ZN6dbgLogL14noticeAsDetailEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL14noticeAsDetailEhPKcz:
LFB3980:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3980
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB33:
	call	__ZN6dbgLog3log15vnoticeAsDetailEhPKcPc
LEHE33:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L507
L506:
	movl	%eax, (%esp)
LEHB34:
	call	__Unwind_Resume
LEHE34:
L507:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3980:
	.section	.gcc_except_table,"w"
LLSDA3980:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3980-LLSDACSB3980
LLSDACSB3980:
	.uleb128 LEHB33-LFB3980
	.uleb128 LEHE33-LEHB33
	.uleb128 L506-LFB3980
	.uleb128 0
	.uleb128 LEHB34-LFB3980
	.uleb128 LEHE34-LEHB34
	.uleb128 0
	.uleb128 0
LLSDACSE3980:
	.text
	.def	__ZN6dbgLogL16printAsImportantEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL16printAsImportantEhPKcz:
LFB3981:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3981
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB35:
	call	__ZN6dbgLog3log17vprintAsImportantEhPKcPc
LEHE35:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L512
L511:
	movl	%eax, (%esp)
LEHB36:
	call	__Unwind_Resume
LEHE36:
L512:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3981:
	.section	.gcc_except_table,"w"
LLSDA3981:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3981-LLSDACSB3981
LLSDACSB3981:
	.uleb128 LEHB35-LFB3981
	.uleb128 LEHE35-LEHB35
	.uleb128 L511-LFB3981
	.uleb128 0
	.uleb128 LEHB36-LFB3981
	.uleb128 LEHE36-LEHB36
	.uleb128 0
	.uleb128 0
LLSDACSE3981:
	.text
	.def	__ZN6dbgLogL14logAsImportantEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL14logAsImportantEhPKcz:
LFB3982:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3982
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB37:
	call	__ZN6dbgLog3log15vlogAsImportantEhPKcPc
LEHE37:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L517
L516:
	movl	%eax, (%esp)
LEHB38:
	call	__Unwind_Resume
LEHE38:
L517:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3982:
	.section	.gcc_except_table,"w"
LLSDA3982:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3982-LLSDACSB3982
LLSDACSB3982:
	.uleb128 LEHB37-LFB3982
	.uleb128 LEHE37-LEHB37
	.uleb128 L516-LFB3982
	.uleb128 0
	.uleb128 LEHB38-LFB3982
	.uleb128 LEHE38-LEHB38
	.uleb128 0
	.uleb128 0
LLSDACSE3982:
	.text
	.def	__ZN6dbgLogL17noticeAsImportantEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL17noticeAsImportantEhPKcz:
LFB3983:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3983
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB39:
	call	__ZN6dbgLog3log18vnoticeAsImportantEhPKcPc
LEHE39:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L522
L521:
	movl	%eax, (%esp)
LEHB40:
	call	__Unwind_Resume
LEHE40:
L522:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3983:
	.section	.gcc_except_table,"w"
LLSDA3983:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3983-LLSDACSB3983
LLSDACSB3983:
	.uleb128 LEHB39-LFB3983
	.uleb128 LEHE39-LEHB39
	.uleb128 L521-LFB3983
	.uleb128 0
	.uleb128 LEHB40-LFB3983
	.uleb128 LEHE40-LEHB40
	.uleb128 0
	.uleb128 0
LLSDACSE3983:
	.text
	.def	__ZN6dbgLogL14printAsWarningEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL14printAsWarningEhPKcz:
LFB3984:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3984
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB41:
	call	__ZN6dbgLog3log15vprintAsWarningEhPKcPc
LEHE41:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L527
L526:
	movl	%eax, (%esp)
LEHB42:
	call	__Unwind_Resume
LEHE42:
L527:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3984:
	.section	.gcc_except_table,"w"
LLSDA3984:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3984-LLSDACSB3984
LLSDACSB3984:
	.uleb128 LEHB41-LFB3984
	.uleb128 LEHE41-LEHB41
	.uleb128 L526-LFB3984
	.uleb128 0
	.uleb128 LEHB42-LFB3984
	.uleb128 LEHE42-LEHB42
	.uleb128 0
	.uleb128 0
LLSDACSE3984:
	.text
	.def	__ZN6dbgLogL12logAsWarningEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL12logAsWarningEhPKcz:
LFB3985:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3985
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB43:
	call	__ZN6dbgLog3log13vlogAsWarningEhPKcPc
LEHE43:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L532
L531:
	movl	%eax, (%esp)
LEHB44:
	call	__Unwind_Resume
LEHE44:
L532:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3985:
	.section	.gcc_except_table,"w"
LLSDA3985:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3985-LLSDACSB3985
LLSDACSB3985:
	.uleb128 LEHB43-LFB3985
	.uleb128 LEHE43-LEHB43
	.uleb128 L531-LFB3985
	.uleb128 0
	.uleb128 LEHB44-LFB3985
	.uleb128 LEHE44-LEHB44
	.uleb128 0
	.uleb128 0
LLSDACSE3985:
	.text
	.def	__ZN6dbgLogL15noticeAsWarningEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL15noticeAsWarningEhPKcz:
LFB3986:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3986
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB45:
	call	__ZN6dbgLog3log16vnoticeAsWarningEhPKcPc
LEHE45:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L537
L536:
	movl	%eax, (%esp)
LEHB46:
	call	__Unwind_Resume
LEHE46:
L537:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3986:
	.section	.gcc_except_table,"w"
LLSDA3986:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3986-LLSDACSB3986
LLSDACSB3986:
	.uleb128 LEHB45-LFB3986
	.uleb128 LEHE45-LEHB45
	.uleb128 L536-LFB3986
	.uleb128 0
	.uleb128 LEHB46-LFB3986
	.uleb128 LEHE46-LEHB46
	.uleb128 0
	.uleb128 0
LLSDACSE3986:
	.text
	.def	__ZN6dbgLogL15printAsCriticalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL15printAsCriticalEhPKcz:
LFB3987:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3987
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB47:
	call	__ZN6dbgLog3log16vprintAsCriticalEhPKcPc
LEHE47:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L542
L541:
	movl	%eax, (%esp)
LEHB48:
	call	__Unwind_Resume
LEHE48:
L542:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3987:
	.section	.gcc_except_table,"w"
LLSDA3987:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3987-LLSDACSB3987
LLSDACSB3987:
	.uleb128 LEHB47-LFB3987
	.uleb128 LEHE47-LEHB47
	.uleb128 L541-LFB3987
	.uleb128 0
	.uleb128 LEHB48-LFB3987
	.uleb128 LEHE48-LEHB48
	.uleb128 0
	.uleb128 0
LLSDACSE3987:
	.text
	.def	__ZN6dbgLogL13logAsCriticalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL13logAsCriticalEhPKcz:
LFB3988:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3988
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB49:
	call	__ZN6dbgLog3log14vlogAsCriticalEhPKcPc
LEHE49:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L547
L546:
	movl	%eax, (%esp)
LEHB50:
	call	__Unwind_Resume
LEHE50:
L547:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3988:
	.section	.gcc_except_table,"w"
LLSDA3988:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3988-LLSDACSB3988
LLSDACSB3988:
	.uleb128 LEHB49-LFB3988
	.uleb128 LEHE49-LEHB49
	.uleb128 L546-LFB3988
	.uleb128 0
	.uleb128 LEHB50-LFB3988
	.uleb128 LEHE50-LEHB50
	.uleb128 0
	.uleb128 0
LLSDACSE3988:
	.text
	.def	__ZN6dbgLogL16noticeAsCriticalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL16noticeAsCriticalEhPKcz:
LFB3989:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3989
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB51:
	call	__ZN6dbgLog3log17vnoticeAsCriticalEhPKcPc
LEHE51:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L552
L551:
	movl	%eax, (%esp)
LEHB52:
	call	__Unwind_Resume
LEHE52:
L552:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3989:
	.section	.gcc_except_table,"w"
LLSDA3989:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3989-LLSDACSB3989
LLSDACSB3989:
	.uleb128 LEHB51-LFB3989
	.uleb128 LEHE51-LEHB51
	.uleb128 L551-LFB3989
	.uleb128 0
	.uleb128 LEHB52-LFB3989
	.uleb128 LEHE52-LEHB52
	.uleb128 0
	.uleb128 0
LLSDACSE3989:
	.text
	.def	__ZN6dbgLogL15printAsAbsoluteEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL15printAsAbsoluteEhPKcz:
LFB3990:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3990
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB53:
	call	__ZN6dbgLog3log16vprintAsAbsoluteEhPKcPc
LEHE53:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L557
L556:
	movl	%eax, (%esp)
LEHB54:
	call	__Unwind_Resume
LEHE54:
L557:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3990:
	.section	.gcc_except_table,"w"
LLSDA3990:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3990-LLSDACSB3990
LLSDACSB3990:
	.uleb128 LEHB53-LFB3990
	.uleb128 LEHE53-LEHB53
	.uleb128 L556-LFB3990
	.uleb128 0
	.uleb128 LEHB54-LFB3990
	.uleb128 LEHE54-LEHB54
	.uleb128 0
	.uleb128 0
LLSDACSE3990:
	.text
	.def	__ZN6dbgLogL13logAsAbsoluteEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL13logAsAbsoluteEhPKcz:
LFB3991:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3991
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB55:
	call	__ZN6dbgLog3log14vlogAsAbsoluteEhPKcPc
LEHE55:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L562
L561:
	movl	%eax, (%esp)
LEHB56:
	call	__Unwind_Resume
LEHE56:
L562:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3991:
	.section	.gcc_except_table,"w"
LLSDA3991:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3991-LLSDACSB3991
LLSDACSB3991:
	.uleb128 LEHB55-LFB3991
	.uleb128 LEHE55-LEHB55
	.uleb128 L561-LFB3991
	.uleb128 0
	.uleb128 LEHB56-LFB3991
	.uleb128 LEHE56-LEHB56
	.uleb128 0
	.uleb128 0
LLSDACSE3991:
	.text
	.def	__ZN6dbgLogL16noticeAsAbsoluteEhPKcz;	.scl	3;	.type	32;	.endef
__ZN6dbgLogL16noticeAsAbsoluteEhPKcz:
LFB3992:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3992
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB57:
	call	__ZN6dbgLog3log17vnoticeAsAbsoluteEhPKcPc
LEHE57:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L567
L566:
	movl	%eax, (%esp)
LEHB58:
	call	__Unwind_Resume
LEHE58:
L567:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3992:
	.section	.gcc_except_table,"w"
LLSDA3992:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3992-LLSDACSB3992
LLSDACSB3992:
	.uleb128 LEHB57-LFB3992
	.uleb128 LEHE57-LEHB57
	.uleb128 L566-LFB3992
	.uleb128 0
	.uleb128 LEHB58-LFB3992
	.uleb128 LEHE58-LEHB58
	.uleb128 0
	.uleb128 0
LLSDACSE3992:
	.text
	.section	.text$_ZN6dbgLog17category_reservedILh8ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_reservedILh8ELb1ELb1EED2Ev
	.def	__ZN6dbgLog17category_reservedILh8ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_reservedILh8ELb1ELb1EED2Ev:
LFB3995:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3995:
	.section .rdata,"dr"
LC36:
	.ascii "forReserved01\0"
	.section	.text$_ZN6dbgLog3ext22category_forReserved01C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3ext22category_forReserved01C1Ev
	.def	__ZN6dbgLog3ext22category_forReserved01C1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3ext22category_forReserved01C1Ev:
LFB3998:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC36, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_reservedILh8ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3998:
	.section	.text$_ZN6dbgLog17category_reservedILh9ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_reservedILh9ELb1ELb1EED2Ev
	.def	__ZN6dbgLog17category_reservedILh9ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_reservedILh9ELb1ELb1EED2Ev:
LFB4001:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4001:
	.section .rdata,"dr"
LC37:
	.ascii "forReserved02\0"
	.section	.text$_ZN6dbgLog3ext22category_forReserved02C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3ext22category_forReserved02C1Ev
	.def	__ZN6dbgLog3ext22category_forReserved02C1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3ext22category_forReserved02C1Ev:
LFB4004:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC37, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_reservedILh9ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4004:
	.section	.text$_ZN6dbgLog17category_reservedILh10ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_reservedILh10ELb1ELb1EED2Ev
	.def	__ZN6dbgLog17category_reservedILh10ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_reservedILh10ELb1ELb1EED2Ev:
LFB4007:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4007:
	.section .rdata,"dr"
LC38:
	.ascii "forReserved03\0"
	.section	.text$_ZN6dbgLog3ext22category_forReserved03C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3ext22category_forReserved03C1Ev
	.def	__ZN6dbgLog3ext22category_forReserved03C1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3ext22category_forReserved03C1Ev:
LFB4010:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC38, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_reservedILh10ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4010:
	.section	.text$_ZN6dbgLog3ext22category_forReserved01D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3ext22category_forReserved01D1Ev
	.def	__ZN6dbgLog3ext22category_forReserved01D1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3ext22category_forReserved01D1Ev:
LFB4014:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_reservedILh8ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4014:
	.section	.text$_ZN6dbgLog3ext22category_forReserved02D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3ext22category_forReserved02D1Ev
	.def	__ZN6dbgLog3ext22category_forReserved02D1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3ext22category_forReserved02D1Ev:
LFB4017:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_reservedILh9ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4017:
	.section	.text$_ZN6dbgLog3ext22category_forReserved03D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3ext22category_forReserved03D1Ev
	.def	__ZN6dbgLog3ext22category_forReserved03D1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3ext22category_forReserved03D1Ev:
LFB4020:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_reservedILh10ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4020:
	.section	.text$_ZN6dbgLog3ext20categoryContainerExtC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3ext20categoryContainerExtC1Ev
	.def	__ZN6dbgLog3ext20categoryContainerExtC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3ext20categoryContainerExtC1Ev:
LFB4022:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$72, %esp
	call	__ZN6dbgLog8category9container14initializeOnceEv
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3ext22category_forReserved01C1Ev
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3ext22category_forReserved01D1Ev
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3ext22category_forReserved02C1Ev
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3ext22category_forReserved02D1Ev
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3ext22category_forReserved03C1Ev
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3ext22category_forReserved03D1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4022:
.lcomm __ZN6dbgLog3extL23s_categoryForInitializeE,1,1
	.section .rdata,"dr"
	.align 4
LC39:
	.ascii "---------- printCommon() ----------\0"
LC40:
	.ascii "logLevel=%s, noticeLevel=%s\12\0"
LC41:
	.ascii "\343\203\206\343\202\271\343\203\210\0"
LC42:
	.ascii "\351\200\232\345\270\270\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC43:
	.ascii "\345\206\227\351\225\267\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC44:
	.ascii "\350\251\263\347\264\260\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC45:
	.ascii "\351\207\215\350\246\201\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC46:
	.ascii "\350\255\246\345\221\212\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC47:
	.ascii "\351\207\215\345\244\247\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC48:
	.ascii "\347\265\266\345\257\276\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
	.align 4
LC49:
	.ascii "\343\200\220\343\203\255\343\202\260\345\207\272\345\212\233\345\260\202\347\224\250\343\200\221\351\207\215\345\244\247\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
	.align 4
LC50:
	.ascii "\343\200\220\347\224\273\351\235\242\351\200\232\347\237\245\345\260\202\347\224\250\343\200\221\351\207\215\345\244\247\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
	.text
	.globl	__Z11printCommonv
	.def	__Z11printCommonv;	.scl	2;	.type	32;	.endef
__Z11printCommonv:
LFB4023:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4023
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	$LC39, (%esp)
LEHB59:
	call	_puts
	movl	$0, (%esp)
	call	__ZN6dbgLog14getNoticeLevelEh
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC1Eh
LEHE59:
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level4nameEv
	movl	%eax, %ebx
	movl	$0, (%esp)
LEHB60:
	call	__ZN6dbgLog11getLogLevelEh
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC1Eh
LEHE60:
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level4nameEv
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC40, (%esp)
LEHB61:
	call	_printf
LEHE61:
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelD1Ev
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelD1Ev
	movl	$LC41, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC42, 4(%esp)
	movl	$0, (%esp)
LEHB62:
	call	__ZN6dbgLogL13printAsNormalEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC43, 4(%esp)
	movl	$0, (%esp)
	call	__ZN6dbgLogL14printAsVerboseEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC44, 4(%esp)
	movl	$0, (%esp)
	call	__ZN6dbgLogL13printAsDetailEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC45, 4(%esp)
	movl	$0, (%esp)
	call	__ZN6dbgLogL16printAsImportantEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC46, 4(%esp)
	movl	$0, (%esp)
	call	__ZN6dbgLogL14printAsWarningEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC47, 4(%esp)
	movl	$0, (%esp)
	call	__ZN6dbgLogL15printAsCriticalEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC48, 4(%esp)
	movl	$0, (%esp)
	call	__ZN6dbgLogL15printAsAbsoluteEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$LC42, 8(%esp)
	movl	$0, 4(%esp)
	movl	$2, (%esp)
	call	__ZN6dbgLogL5printEhhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$0, (%esp)
	call	__ZN6dbgLogL13logAsCriticalEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC50, 4(%esp)
	movl	$0, (%esp)
	call	__ZN6dbgLogL16noticeAsCriticalEhPKcz
	jmp	L589
L588:
	movl	%eax, %ebx
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelD1Ev
	jmp	L586
L587:
	movl	%eax, %ebx
L586:
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE62:
L589:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4023:
	.section	.gcc_except_table,"w"
LLSDA4023:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4023-LLSDACSB4023
LLSDACSB4023:
	.uleb128 LEHB59-LFB4023
	.uleb128 LEHE59-LEHB59
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB60-LFB4023
	.uleb128 LEHE60-LEHB60
	.uleb128 L587-LFB4023
	.uleb128 0
	.uleb128 LEHB61-LFB4023
	.uleb128 LEHE61-LEHB61
	.uleb128 L588-LFB4023
	.uleb128 0
	.uleb128 LEHB62-LFB4023
	.uleb128 LEHE62-LEHB62
	.uleb128 0
	.uleb128 0
LLSDACSE4023:
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB4024:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	call	__ZN6dbgLog13printLevelAllEv
	call	__ZN6dbgLog16printCategoryAllEv
	call	__Z11printCommonv
	movl	$1, 4(%esp)
	movl	$64, (%esp)
	call	__ZN6dbgLog11setLogLevelEhh
	movl	$1, 4(%esp)
	movl	$64, (%esp)
	call	__ZN6dbgLog14setNoticeLevelEhh
	call	__Z11printCommonv
	movl	$12, 4(%esp)
	movl	$64, (%esp)
	call	__ZN6dbgLog11setLogLevelEhh
	movl	$12, 4(%esp)
	movl	$64, (%esp)
	call	__ZN6dbgLog14setNoticeLevelEhh
	call	__Z11printCommonv
	call	__ZN6dbgLog16resetLogLevelAllEv
	call	__ZN6dbgLog19resetNoticeLevelAllEv
	call	__Z11printCommonv
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4024:
	.section	.text$_ZNSt6bitsetILj14EEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EEixEj
	.def	__ZNSt6bitsetILj14EEixEj;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EEixEj:
LFB4061:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj14EE9referenceC1ERS0_j
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE4061:
	.section	.text$_ZNSt6bitsetILj14EE9referenceD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE9referenceD1Ev
	.def	__ZNSt6bitsetILj14EE9referenceD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE9referenceD1Ev:
LFB4064:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4064:
	.section	.text$_ZNKSt6bitsetILj14EE9referencecvbEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6bitsetILj14EE9referencecvbEv
	.def	__ZNKSt6bitsetILj14EE9referencecvbEv;	.scl	2;	.type	32;	.endef
__ZNKSt6bitsetILj14EE9referencecvbEv:
LFB4065:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %ebx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Base_bitsetILj1EE10_S_maskbitEj
	andl	%ebx, %eax
	testl	%eax, %eax
	setne	%al
	addl	$4, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4065:
	.section	.text$_ZNSt6bitsetILj14EE9referenceaSEb,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE9referenceaSEb
	.def	__ZNSt6bitsetILj14EE9referenceaSEb;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE9referenceaSEb:
LFB4066:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	12(%ebp), %eax
	movb	%al, -4(%ebp)
	cmpb	$0, -4(%ebp)
	je	L599
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Base_bitsetILj1EE10_S_maskbitEj
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %ecx
	movl	(%ecx), %ecx
	movl	(%ecx), %ecx
	orl	%ecx, %edx
	movl	%edx, (%eax)
	jmp	L600
L599:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Base_bitsetILj1EE10_S_maskbitEj
	notl	%eax
	movl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	(%edx), %edx
	andl	%ecx, %edx
	movl	%edx, (%eax)
L600:
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4066:
	.section	.text$_ZN6dbgLog12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc
	.def	__ZN6dbgLog12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc:
LFB4068:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$15, 36(%esp)
	movl	$0, 32(%esp)
	movl	$16, 28(%esp)
	movl	$16, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4068:
	.section	.text$_ZN6dbgLog12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc
	.def	__ZN6dbgLog12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc:
LFB4071:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$15, 36(%esp)
	movl	$8, 32(%esp)
	movl	$0, 28(%esp)
	movl	$8, 24(%esp)
	movl	$1, 20(%esp)
	movl	$0, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4071:
	.section	.text$_ZN6dbgLog12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc
	.def	__ZN6dbgLog12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc:
LFB4074:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$15, 36(%esp)
	movl	$8, 32(%esp)
	movl	$0, 28(%esp)
	movl	$8, 24(%esp)
	movl	$1, 20(%esp)
	movl	$0, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4074:
	.section	.text$_ZN6dbgLog12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc
	.def	__ZN6dbgLog12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc:
LFB4077:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$15, 36(%esp)
	movl	$12, 32(%esp)
	movl	$0, 28(%esp)
	movl	$12, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$4, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4077:
	.section	.text$_ZN6dbgLog12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc
	.def	__ZN6dbgLog12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc:
LFB4080:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$13, 36(%esp)
	movl	$0, 32(%esp)
	movl	$0, 28(%esp)
	movl	$13, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$6, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4080:
	.section	.text$_ZN6dbgLog12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc
	.def	__ZN6dbgLog12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc:
LFB4083:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$9, 36(%esp)
	movl	$11, 32(%esp)
	movl	$0, 28(%esp)
	movl	$9, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$8, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4083:
	.section	.text$_ZN6dbgLog12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc
	.def	__ZN6dbgLog12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc:
LFB4086:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$32, 36(%esp)
	movl	$32, 32(%esp)
	movl	$32, 28(%esp)
	movl	$32, 24(%esp)
	movl	$1, 20(%esp)
	movl	$0, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$10, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4086:
	.section	.text$_ZN6dbgLog13level_specialILh11EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog13level_specialILh11EEC2EPKc
	.def	__ZN6dbgLog13level_specialILh11EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog13level_specialILh11EEC2EPKc:
LFB4089:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$32, 36(%esp)
	movl	$32, 32(%esp)
	movl	$32, 28(%esp)
	movl	$32, 24(%esp)
	movl	$1, 20(%esp)
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$11, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4089:
	.section	.text$_ZN6dbgLog13level_specialILh12EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog13level_specialILh12EEC2EPKc
	.def	__ZN6dbgLog13level_specialILh12EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog13level_specialILh12EEC2EPKc:
LFB4092:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$32, 36(%esp)
	movl	$32, 32(%esp)
	movl	$32, 28(%esp)
	movl	$32, 24(%esp)
	movl	$1, 20(%esp)
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$12, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4092:
	.section	.text$_ZNSt6bitsetILj14EE5resetEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE5resetEv
	.def	__ZNSt6bitsetILj14EE5resetEv;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE5resetEv:
LFB4094:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Base_bitsetILj1EE11_M_do_resetEv
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4094:
	.section	.text$_ZNSt6bitsetILj68EEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EEixEj
	.def	__ZNSt6bitsetILj68EEixEj;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EEixEj:
LFB4095:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj68EE9referenceC1ERS0_j
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE4095:
	.section	.text$_ZNSt6bitsetILj68EE9referenceD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE9referenceD1Ev
	.def	__ZNSt6bitsetILj68EE9referenceD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE9referenceD1Ev:
LFB4098:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4098:
	.section	.text$_ZNSt12_Base_bitsetILj3EE11_S_whichbitEj,"x"
	.linkonce discard
	.globl	__ZNSt12_Base_bitsetILj3EE11_S_whichbitEj
	.def	__ZNSt12_Base_bitsetILj3EE11_S_whichbitEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE11_S_whichbitEj:
LFB4101:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	andl	$31, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4101:
	.section	.text$_ZNSt12_Base_bitsetILj3EE10_S_maskbitEj,"x"
	.linkonce discard
	.globl	__ZNSt12_Base_bitsetILj3EE10_S_maskbitEj
	.def	__ZNSt12_Base_bitsetILj3EE10_S_maskbitEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE10_S_maskbitEj:
LFB4100:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Base_bitsetILj3EE11_S_whichbitEj
	movl	$1, %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4100:
	.section	.text$_ZNKSt6bitsetILj68EE9referencecvbEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6bitsetILj68EE9referencecvbEv
	.def	__ZNKSt6bitsetILj68EE9referencecvbEv;	.scl	2;	.type	32;	.endef
__ZNKSt6bitsetILj68EE9referencecvbEv:
LFB4099:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %ebx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Base_bitsetILj3EE10_S_maskbitEj
	andl	%ebx, %eax
	testl	%eax, %eax
	setne	%al
	addl	$4, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4099:
	.section	.text$_ZNSt6bitsetILj68EE9referenceaSEb,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE9referenceaSEb
	.def	__ZNSt6bitsetILj68EE9referenceaSEb;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE9referenceaSEb:
LFB4102:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	12(%ebp), %eax
	movb	%al, -4(%ebp)
	cmpb	$0, -4(%ebp)
	je	L624
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Base_bitsetILj3EE10_S_maskbitEj
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %ecx
	movl	(%ecx), %ecx
	movl	(%ecx), %ecx
	orl	%ecx, %edx
	movl	%edx, (%eax)
	jmp	L625
L624:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Base_bitsetILj3EE10_S_maskbitEj
	notl	%eax
	movl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	(%edx), %edx
	andl	%ecx, %edx
	movl	%edx, (%eax)
L625:
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4102:
	.section	.text$_ZN6dbgLog17category_assignedILh0ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh0ELb1ELb1EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh0ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh0ELb1ELb1EEC2EPKc:
LFB4104:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4104:
	.section	.text$_ZN6dbgLog17category_assignedILh1ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh1ELb1ELb1EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh1ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh1ELb1ELb1EEC2EPKc:
LFB4107:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4107:
	.section	.text$_ZN6dbgLog17category_assignedILh2ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh2ELb1ELb1EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh2ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh2ELb1ELb1EEC2EPKc:
LFB4110:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4110:
	.section	.text$_ZN6dbgLog17category_assignedILh3ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh3ELb1ELb1EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh3ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh3ELb1ELb1EEC2EPKc:
LFB4113:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$3, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4113:
	.section	.text$_ZN6dbgLog17category_assignedILh4ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh4ELb1ELb1EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh4ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh4ELb1ELb1EEC2EPKc:
LFB4116:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$4, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4116:
	.section	.text$_ZN6dbgLog17category_assignedILh5ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh5ELb1ELb1EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh5ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh5ELb1ELb1EEC2EPKc:
LFB4119:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4119:
	.section	.text$_ZN6dbgLog17category_assignedILh6ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh6ELb1ELb1EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh6ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh6ELb1ELb1EEC2EPKc:
LFB4122:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$6, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4122:
	.section	.text$_ZN6dbgLog17category_assignedILh7ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh7ELb1ELb1EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh7ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh7ELb1ELb1EEC2EPKc:
LFB4125:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$7, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4125:
	.section	.text$_ZN6dbgLog16category_specialILh64ELb0ELb0ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16category_specialILh64ELb0ELb0ELb1EEC2EPKc
	.def	__ZN6dbgLog16category_specialILh64ELb0ELb0ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16category_specialILh64ELb0ELb0ELb1EEC2EPKc:
LFB4128:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 24(%esp)
	movl	$0, 20(%esp)
	movl	$0, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$64, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4128:
	.section	.text$_ZN6dbgLog16category_specialILh65ELb1ELb1ELb0EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16category_specialILh65ELb1ELb1ELb0EEC2EPKc
	.def	__ZN6dbgLog16category_specialILh65ELb1ELb1ELb0EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16category_specialILh65ELb1ELb1ELb0EEC2EPKc:
LFB4131:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$0, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$65, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4131:
	.section	.text$_ZN6dbgLog16category_specialILh66ELb1ELb1ELb0EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16category_specialILh66ELb1ELb1ELb0EEC2EPKc
	.def	__ZN6dbgLog16category_specialILh66ELb1ELb1ELb0EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16category_specialILh66ELb1ELb1ELb0EEC2EPKc:
LFB4134:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$0, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$66, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4134:
	.section	.text$_ZNSt6bitsetILj68EE5resetEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE5resetEv
	.def	__ZNSt6bitsetILj68EE5resetEv;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE5resetEv:
LFB4136:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Base_bitsetILj3EE11_M_do_resetEv
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4136:
	.section	.text$_ZN6dbgLog17category_reservedILh8ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_reservedILh8ELb1ELb1EEC2EPKc
	.def	__ZN6dbgLog17category_reservedILh8ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_reservedILh8ELb1ELb1EEC2EPKc:
LFB4138:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$0, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$8, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4138:
	.section	.text$_ZN6dbgLog17category_reservedILh9ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_reservedILh9ELb1ELb1EEC2EPKc
	.def	__ZN6dbgLog17category_reservedILh9ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_reservedILh9ELb1ELb1EEC2EPKc:
LFB4141:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$0, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$9, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4141:
	.section	.text$_ZN6dbgLog17category_reservedILh10ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_reservedILh10ELb1ELb1EEC2EPKc
	.def	__ZN6dbgLog17category_reservedILh10ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_reservedILh10ELb1ELb1EEC2EPKc:
LFB4144:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 24(%esp)
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$0, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$10, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4144:
	.section	.text$_ZNSt6bitsetILj14EE9referenceC1ERS0_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE9referenceC1ERS0_j
	.def	__ZNSt6bitsetILj14EE9referenceC1ERS0_j;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE9referenceC1ERS0_j:
LFB4169:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt12_Base_bitsetILj1EE10_M_getwordEj
	movl	8(%ebp), %edx
	movl	%eax, (%edx)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Base_bitsetILj1EE11_S_whichbitEj
	movl	8(%ebp), %edx
	movl	%eax, 4(%edx)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4169:
	.section	.text$_ZNSt6bitsetILj68EE9referenceC1ERS0_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE9referenceC1ERS0_j
	.def	__ZNSt6bitsetILj68EE9referenceC1ERS0_j;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE9referenceC1ERS0_j:
LFB4172:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt12_Base_bitsetILj3EE10_M_getwordEj
	movl	8(%ebp), %edx
	movl	%eax, (%edx)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Base_bitsetILj3EE11_S_whichbitEj
	movl	8(%ebp), %edx
	movl	%eax, 4(%edx)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4172:
	.section	.text$_ZNSt12_Base_bitsetILj3EE11_M_do_resetEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Base_bitsetILj3EE11_M_do_resetEv
	.def	__ZNSt12_Base_bitsetILj3EE11_M_do_resetEv;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE11_M_do_resetEv:
LFB4173:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$12, %edx
	movl	8(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	_memset
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4173:
	.section	.text$_ZNSt12_Base_bitsetILj3EE12_S_whichwordEj,"x"
	.linkonce discard
	.globl	__ZNSt12_Base_bitsetILj3EE12_S_whichwordEj
	.def	__ZNSt12_Base_bitsetILj3EE12_S_whichwordEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE12_S_whichwordEj:
LFB4184:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	shrl	$5, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4184:
	.section	.text$_ZNSt12_Base_bitsetILj3EE10_M_getwordEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Base_bitsetILj3EE10_M_getwordEj
	.def	__ZNSt12_Base_bitsetILj3EE10_M_getwordEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE10_M_getwordEj:
LFB4183:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Base_bitsetILj3EE12_S_whichwordEj
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4183:
	.text
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB4196:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L651
	cmpl	$65535, 12(%ebp)
	jne	L651
	call	___getreent
	movl	8(%eax), %eax
	movl	%eax, __ZN6dbgLog5color8m_handleE
	call	___getreent
	movl	12(%eax), %eax
	movl	%eax, __ZN6dbgLog5color8m_handleE+4
	movl	$__ZN6dbgLogL20s_colorForInitializeE, (%esp)
	call	__ZN6dbgLog5colorC1Ev
	movl	$__ZN6dbgLogL20s_levelForInitializeE, (%esp)
	call	__ZN6dbgLog5levelC1Ev
	movl	$__ZN6dbgLogL23s_categoryForInitializeE, (%esp)
	call	__ZN6dbgLog8categoryC1Ev
	movl	$__ZN6dbgLogL18s_logForInitializeE, (%esp)
	call	__ZN6dbgLog3logC1Ev
	movl	$__ZN6dbgLog3extL23s_categoryForInitializeE, (%esp)
	call	__ZN6dbgLog3ext20categoryContainerExtC1Ev
L651:
	cmpl	$0, 8(%ebp)
	jne	L650
	cmpl	$65535, 12(%ebp)
	jne	L650
	movl	$__ZN6dbgLogL18s_logForInitializeE, (%esp)
	call	__ZN6dbgLog3logD1Ev
	movl	$__ZN6dbgLogL23s_categoryForInitializeE, (%esp)
	call	__ZN6dbgLog8categoryD1Ev
	movl	$__ZN6dbgLogL20s_levelForInitializeE, (%esp)
	call	__ZN6dbgLog5levelD1Ev
	movl	$__ZN6dbgLogL20s_colorForInitializeE, (%esp)
	call	__ZN6dbgLog5colorD1Ev
L650:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4196:
	.def	__GLOBAL__sub_I__ZN6dbgLog5color15m_isInitializedE;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__ZN6dbgLog5color15m_isInitializedE:
LFB4197:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4197:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__ZN6dbgLog5color15m_isInitializedE
	.text
	.def	__GLOBAL__sub_D__ZN6dbgLog5color15m_isInitializedE;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_D__ZN6dbgLog5color15m_isInitializedE:
LFB4198:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$0, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4198:
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__sub_D__ZN6dbgLog5color15m_isInitializedE
	.section .rdata,"dr"
	.align 32
__ZZN6dbgLog5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_E19__PRETTY_FUNCTION__:
	.ascii "dbgLog::level::level(dbgLog::level::value_t, const char*, bool, bool, bool, dbgLog::color::color_t, dbgLog::color::color_t, dbgLog::color::color_t, dbgLog::color::color_t)\0"
	.align 32
__ZZN6dbgLog8categoryC1EhPKcbbbbE19__PRETTY_FUNCTION__:
	.ascii "dbgLog::category::category(dbgLog::category::value_t, const char*, bool, bool, bool, bool)\0"
	.align 32
__ZZN6dbgLog3log11getLogLevelEhE19__PRETTY_FUNCTION__:
	.ascii "static dbgLog::level::value_t dbgLog::log::getLogLevel(dbgLog::category::value_t)\0"
	.align 32
__ZZN6dbgLog3log11setLogLevelEhhE19__PRETTY_FUNCTION__:
	.ascii "static dbgLog::level::value_t dbgLog::log::setLogLevel(dbgLog::category::value_t, dbgLog::level::value_t)\0"
	.align 32
__ZZN6dbgLog3log14getNoticeLevelEhE19__PRETTY_FUNCTION__:
	.ascii "static dbgLog::level::value_t dbgLog::log::getNoticeLevel(dbgLog::category::value_t)\0"
	.align 32
__ZZN6dbgLog3log14setNoticeLevelEhhE19__PRETTY_FUNCTION__:
	.ascii "static dbgLog::level::value_t dbgLog::log::setNoticeLevel(dbgLog::category::value_t, dbgLog::level::value_t)\0"
	.align 32
__ZZN6dbgLog3log6vprintEhhhhPKcPcE19__PRETTY_FUNCTION__:
	.ascii "static int dbgLog::log::vprint(dbgLog::level::value_t, dbgLog::level::value_t, dbgLog::level::value_t, dbgLog::category::value_t, const char*, va_list)\0"
	.align 32
__ZZN6dbgLog5levelC1EhE19__PRETTY_FUNCTION__:
	.ascii "dbgLog::level::level(dbgLog::level::value_t)\0"
	.ident	"GCC: (GNU) 4.8.2"
	.def	_fwrite;	.scl	2;	.type	32;	.endef
	.def	_fprintf;	.scl	2;	.type	32;	.endef
	.def	_memcpy;	.scl	2;	.type	32;	.endef
	.def	___assert_func;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef
	.def	___getreent;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_vfprintf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef

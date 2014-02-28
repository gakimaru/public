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
	.section	.text$_ZNK6dbgLog5level9forOutputEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level9forOutputEv
	.def	__ZNK6dbgLog5level9forOutputEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level9forOutputEv:
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
	.section	.text$_ZNK6dbgLog5level13forOutputMaskEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level13forOutputMaskEv
	.def	__ZNK6dbgLog5level13forOutputMaskEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level13forOutputMaskEv:
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
	.section	.text$_ZSt4moveIN6dbgLog5colorEEONSt16remove_referenceIT_E4typeEOS3_,"x"
	.linkonce discard
	.globl	__ZSt4moveIN6dbgLog5colorEEONSt16remove_referenceIT_E4typeEOS3_
	.def	__ZSt4moveIN6dbgLog5colorEEONSt16remove_referenceIT_E4typeEOS3_;	.scl	2;	.type	32;	.endef
__ZSt4moveIN6dbgLog5colorEEONSt16remove_referenceIT_E4typeEOS3_:
LFB3572:
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
LFE3572:
	.section	.text$_ZNK6dbgLog5level11changeColorEb,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level11changeColorEb
	.def	__ZNK6dbgLog5level11changeColorEb;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level11changeColorEb:
LFB3574:
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
	movzbl	8(%eax), %eax
	movzbl	%al, %edx
	movl	12(%ebp), %eax
	movzbl	7(%eax), %eax
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
LFE3574:
	.section	.text$_ZNK6dbgLog5level4prevEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level4prevEv
	.def	__ZNK6dbgLog5level4prevEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level4prevEv:
LFB3577:
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
	je	L72
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level13valueAsOutputEv
	cmpb	$5, %al
	ja	L72
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L73
L72:
	movl	$1, %eax
	jmp	L74
L73:
	movl	$0, %eax
L74:
	testb	%al, %al
	je	L75
	movl	__ZN6dbgLog5level9container9m_poolPtrE, %ecx
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	jmp	L76
L75:
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
L76:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3577:
	.section	.text$_ZNK6dbgLog5level4nextEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog5level4nextEv
	.def	__ZNK6dbgLog5level4nextEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog5level4nextEv:
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
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level13valueAsOutputEv
	cmpb	$4, %al
	ja	L78
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L79
L78:
	movl	$1, %eax
	jmp	L80
L79:
	movl	$0, %eax
L80:
	testb	%al, %al
	je	L81
	movl	__ZN6dbgLog5level9container9m_poolPtrE, %ecx
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	jmp	L82
L81:
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
L82:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3578:
	.section	.text$_ZN6dbgLog5levelC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5levelC1Ev
	.def	__ZN6dbgLog5levelC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5levelC1Ev:
LFB3581:
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
	movb	$32, 7(%eax)
	movl	8(%ebp), %eax
	movb	$32, 8(%eax)
	movl	8(%ebp), %eax
	movb	$32, 9(%eax)
	movl	8(%ebp), %eax
	movb	$32, 10(%eax)
	call	__ZN6dbgLog5level9container14initializeOnceEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3581:
	.section .rdata,"dr"
	.align 4
LC2:
	.ascii "value >= BEGIN && value <= END\0"
LC3:
	.ascii "call_point.cpp\0"
	.section	.text$_ZN6dbgLog5levelC2EhPKcbbNS_5color7color_tES4_S4_S4_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5levelC2EhPKcbbNS_5color7color_tES4_S4_S4_
	.def	__ZN6dbgLog5levelC2EhPKcbbNS_5color7color_tES4_S4_S4_;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5levelC2EhPKcbbNS_5color7color_tES4_S4_S4_:
LFB3586:
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
	movl	12(%ebp), %eax
	movl	20(%ebp), %edi
	movl	24(%ebp), %esi
	movl	28(%ebp), %ebx
	movl	32(%ebp), %ecx
	movl	36(%ebp), %edx
	movl	%edx, -56(%ebp)
	movl	40(%ebp), %edx
	movb	%al, -28(%ebp)
	movl	%edi, %eax
	movb	%al, -32(%ebp)
	movl	%esi, %eax
	movb	%al, -36(%ebp)
	movb	%bl, -40(%ebp)
	movb	%cl, -44(%ebp)
	movzbl	-56(%ebp), %eax
	movb	%al, -48(%ebp)
	movl	%edx, %eax
	movb	%al, -52(%ebp)
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
	cmpb	$13, -28(%ebp)
	jbe	L85
	movl	$LC2, 12(%esp)
	movl	$__ZZN6dbgLog5levelC1EhPKcbbNS_5color7color_tES4_S4_S4_E19__PRETTY_FUNCTION__, 8(%esp)
	movl	$467, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L85:
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level9container3setEhRKS0_
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
LFE3586:
	.section	.text$_ZN6dbgLog5levelC1EhPKcbbNS_5color7color_tES4_S4_S4_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5levelC1EhPKcbbNS_5color7color_tES4_S4_S4_
	.def	__ZN6dbgLog5levelC1EhPKcbbNS_5color7color_tES4_S4_S4_;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5levelC1EhPKcbbNS_5color7color_tES4_S4_S4_:
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
	subl	$60, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	12(%ebp), %eax
	movl	20(%ebp), %edi
	movl	24(%ebp), %esi
	movl	28(%ebp), %ebx
	movl	32(%ebp), %ecx
	movl	36(%ebp), %edx
	movl	%edx, -56(%ebp)
	movl	40(%ebp), %edx
	movb	%al, -28(%ebp)
	movl	%edi, %eax
	movb	%al, -32(%ebp)
	movl	%esi, %eax
	movb	%al, -36(%ebp)
	movb	%bl, -40(%ebp)
	movb	%cl, -44(%ebp)
	movzbl	-56(%ebp), %eax
	movb	%al, -48(%ebp)
	movl	%edx, %eax
	movb	%al, -52(%ebp)
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
	cmpb	$13, -28(%ebp)
	jbe	L87
	movl	$LC2, 12(%esp)
	movl	$__ZZN6dbgLog5levelC1EhPKcbbNS_5color7color_tES4_S4_S4_E19__PRETTY_FUNCTION__, 8(%esp)
	movl	$467, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L87:
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level9container3setEhRKS0_
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
LFE3587:
	.section	.text$_ZN6dbgLog5levelD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5levelD2Ev
	.def	__ZN6dbgLog5levelD2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5levelD2Ev:
LFB3592:
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
LFE3592:
	.section	.text$_ZN6dbgLog5levelD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog5levelD1Ev
	.def	__ZN6dbgLog5levelD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5levelD1Ev:
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
	.section .rdata,"dr"
LC4:
	.ascii "(END)\0"
	.section	.text$_ZN6dbgLog9level_endC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog9level_endC1Ev
	.def	__ZN6dbgLog9level_endC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog9level_endC1Ev:
LFB3598:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$32, 32(%esp)
	movl	$32, 28(%esp)
	movl	$32, 24(%esp)
	movl	$32, 20(%esp)
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	$LC4, 8(%esp)
	movl	$13, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3598:
	.section	.text$_ZN6dbgLog12level_normalILh2ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh2ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EED2Ev
	.def	__ZN6dbgLog12level_normalILh2ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh2ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EED2Ev:
LFB3601:
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
LFE3601:
	.section .rdata,"dr"
LC5:
	.ascii "asNormal\0"
	.section	.text$_ZN6dbgLog14level_asNormalC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14level_asNormalC1Ev
	.def	__ZN6dbgLog14level_asNormalC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14level_asNormalC1Ev:
LFB3604:
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
	call	__ZN6dbgLog12level_normalILh2ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3604:
	.section	.text$_ZN6dbgLog12level_normalILh0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev
	.def	__ZN6dbgLog12level_normalILh0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev:
LFB3607:
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
LFE3607:
	.section .rdata,"dr"
LC6:
	.ascii "asVerbose\0"
	.section	.text$_ZN6dbgLog15level_asVerboseC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog15level_asVerboseC1Ev
	.def	__ZN6dbgLog15level_asVerboseC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog15level_asVerboseC1Ev:
LFB3610:
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
	call	__ZN6dbgLog12level_normalILh0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3610:
	.section	.text$_ZN6dbgLog12level_normalILh1ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh1ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev
	.def	__ZN6dbgLog12level_normalILh1ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh1ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev:
LFB3613:
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
LFE3613:
	.section .rdata,"dr"
LC7:
	.ascii "asDetail\0"
	.section	.text$_ZN6dbgLog14level_asDetailC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14level_asDetailC1Ev
	.def	__ZN6dbgLog14level_asDetailC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14level_asDetailC1Ev:
LFB3616:
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
	call	__ZN6dbgLog12level_normalILh1ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3616:
	.section	.text$_ZN6dbgLog12level_normalILh4ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh4ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EED2Ev
	.def	__ZN6dbgLog12level_normalILh4ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh4ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EED2Ev:
LFB3619:
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
LFE3619:
	.section .rdata,"dr"
LC8:
	.ascii "asImportant\0"
	.section	.text$_ZN6dbgLog17level_asImportantC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17level_asImportantC1Ev
	.def	__ZN6dbgLog17level_asImportantC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17level_asImportantC1Ev:
LFB3622:
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
	call	__ZN6dbgLog12level_normalILh4ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3622:
	.section	.text$_ZN6dbgLog12level_normalILh6ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh6ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EED2Ev
	.def	__ZN6dbgLog12level_normalILh6ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh6ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EED2Ev:
LFB3625:
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
LFE3625:
	.section .rdata,"dr"
LC9:
	.ascii "asWarning\0"
	.section	.text$_ZN6dbgLog15level_asWarningC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog15level_asWarningC1Ev
	.def	__ZN6dbgLog15level_asWarningC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog15level_asWarningC1Ev:
LFB3628:
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
	call	__ZN6dbgLog12level_normalILh6ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3628:
	.section	.text$_ZN6dbgLog12level_normalILh8ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh8ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EED2Ev
	.def	__ZN6dbgLog12level_normalILh8ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh8ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EED2Ev:
LFB3631:
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
LFE3631:
	.section .rdata,"dr"
LC10:
	.ascii "asCritical\0"
	.section	.text$_ZN6dbgLog16level_asCriticalC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16level_asCriticalC1Ev
	.def	__ZN6dbgLog16level_asCriticalC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16level_asCriticalC1Ev:
LFB3634:
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
	call	__ZN6dbgLog12level_normalILh8ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3634:
	.section	.text$_ZN6dbgLog12level_normalILh10ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh10ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EED2Ev
	.def	__ZN6dbgLog12level_normalILh10ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh10ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EED2Ev:
LFB3637:
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
LFE3637:
	.section .rdata,"dr"
LC11:
	.ascii "asAbsolute\0"
	.section	.text$_ZN6dbgLog16level_asAbsoluteC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16level_asAbsoluteC1Ev
	.def	__ZN6dbgLog16level_asAbsoluteC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16level_asAbsoluteC1Ev:
LFB3640:
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
	call	__ZN6dbgLog12level_normalILh10ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3640:
	.section	.text$_ZN6dbgLog13level_specialILh11EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog13level_specialILh11EED2Ev
	.def	__ZN6dbgLog13level_specialILh11EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog13level_specialILh11EED2Ev:
LFB3643:
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
LFE3643:
	.section .rdata,"dr"
LC12:
	.ascii "asSilent\0"
	.section	.text$_ZN6dbgLog14level_asSilentC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14level_asSilentC1Ev
	.def	__ZN6dbgLog14level_asSilentC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14level_asSilentC1Ev:
LFB3646:
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
LFE3646:
	.section	.text$_ZN6dbgLog13level_specialILh12EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog13level_specialILh12EED2Ev
	.def	__ZN6dbgLog13level_specialILh12EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog13level_specialILh12EED2Ev:
LFB3649:
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
LFE3649:
	.section .rdata,"dr"
LC13:
	.ascii "asSilentAbsolutely\0"
	.section	.text$_ZN6dbgLog24level_asSilentAbsolutelyC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog24level_asSilentAbsolutelyC1Ev
	.def	__ZN6dbgLog24level_asSilentAbsolutelyC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog24level_asSilentAbsolutelyC1Ev:
LFB3652:
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
LFE3652:
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
LFB3659:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh2ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3659:
	.section	.text$_ZN6dbgLog15level_asVerboseD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog15level_asVerboseD1Ev
	.def	__ZN6dbgLog15level_asVerboseD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog15level_asVerboseD1Ev:
LFB3662:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3662:
	.section	.text$_ZN6dbgLog14level_asDetailD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14level_asDetailD1Ev
	.def	__ZN6dbgLog14level_asDetailD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14level_asDetailD1Ev:
LFB3665:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh1ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3665:
	.section	.text$_ZN6dbgLog17level_asImportantD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17level_asImportantD1Ev
	.def	__ZN6dbgLog17level_asImportantD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17level_asImportantD1Ev:
LFB3668:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh4ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3668:
	.section	.text$_ZN6dbgLog15level_asWarningD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog15level_asWarningD1Ev
	.def	__ZN6dbgLog15level_asWarningD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog15level_asWarningD1Ev:
LFB3671:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh6ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3671:
	.section	.text$_ZN6dbgLog16level_asCriticalD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16level_asCriticalD1Ev
	.def	__ZN6dbgLog16level_asCriticalD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16level_asCriticalD1Ev:
LFB3674:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh8ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3674:
	.section	.text$_ZN6dbgLog16level_asAbsoluteD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16level_asAbsoluteD1Ev
	.def	__ZN6dbgLog16level_asAbsoluteD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16level_asAbsoluteD1Ev:
LFB3677:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12level_normalILh10ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3677:
	.section	.text$_ZN6dbgLog14level_asSilentD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14level_asSilentD1Ev
	.def	__ZN6dbgLog14level_asSilentD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14level_asSilentD1Ev:
LFB3680:
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
LFE3680:
	.section	.text$_ZN6dbgLog24level_asSilentAbsolutelyD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog24level_asSilentAbsolutelyD1Ev
	.def	__ZN6dbgLog24level_asSilentAbsolutelyD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog24level_asSilentAbsolutelyD1Ev:
LFB3683:
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
LFE3683:
	.section	.text$_ZN6dbgLog9level_endD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog9level_endD1Ev
	.def	__ZN6dbgLog9level_endD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog9level_endD1Ev:
LFB3686:
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
LFE3686:
	.section .rdata,"dr"
LC14:
	.ascii "(undefined)\0"
	.text
	.align 2
	.globl	__ZN6dbgLog5level9container14initializeOnceEv
	.def	__ZN6dbgLog5level9container14initializeOnceEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog5level9container14initializeOnceEv:
LFB3656:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$200, %esp
	movzbl	__ZN6dbgLog5level9container15m_isInitializedE, %eax
	testb	%al, %al
	je	L141
	jmp	L140
L141:
	movb	$1, __ZN6dbgLog5level9container15m_isInitializedE
	movl	$__ZN6dbgLog5level9container15m_isAlreadyPoolE, (%esp)
	call	__ZNSt6bitsetILj14EE5resetEv
	movl	$168, 8(%esp)
	movl	$0, 4(%esp)
	movl	$__ZN6dbgLog5level9container6m_poolE, (%esp)
	call	_memset
	movl	$__ZN6dbgLog5level9container6m_poolE, __ZN6dbgLog5level9container9m_poolPtrE
	movb	$0, -9(%ebp)
	jmp	L143
L144:
	movzbl	-9(%ebp), %eax
	movl	$32, 32(%esp)
	movl	$32, 28(%esp)
	movl	$32, 24(%esp)
	movl	$32, 20(%esp)
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	$LC14, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC1EhPKcbbNS_5color7color_tES4_S4_S4_
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
L143:
	cmpb	$12, -9(%ebp)
	jbe	L144
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
L140:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3656:
.lcomm __ZN6dbgLogL20s_levelForInitializeE,12,4
	.section .rdata,"dr"
	.align 4
LC15:
	.ascii "level=%d, name=\"%s\", valueAsOutput=%d, forOutput=%d, forOutputMask=%d\12\0"
LC16:
	.ascii "           prev=%s(%d)\12\0"
LC17:
	.ascii "           next=%s(%d)\12\0"
	.text
	.globl	__ZN6dbgLog13printLevelAllEv
	.def	__ZN6dbgLog13printLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog13printLevelAllEv:
LFB3687:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3687
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
	jmp	L146
L147:
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
	call	__ZNK6dbgLog5level13forOutputMaskEv
	movzbl	%al, %eax
	movl	%eax, -60(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog5level9forOutputEv
	movzbl	%al, %eax
	movl	%eax, -64(%ebp)
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
	movl	%ecx, 24(%esp)
	movl	-64(%ebp), %edx
	movl	%edx, 20(%esp)
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
L146:
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
	jne	L147
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level8iteratorD1Ev
	leal	-43(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5level8iteratorD1Ev
	jmp	L152
L151:
	movl	%eax, %ebx
	leal	-50(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog5colorD1Ev
	movl	%ebx, %eax
	jmp	L149
L150:
L149:
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
L152:
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
LFE3687:
	.section	.gcc_except_table,"w"
LLSDA3687:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3687-LLSDACSB3687
LLSDACSB3687:
	.uleb128 LEHB0-LFB3687
	.uleb128 LEHE0-LEHB0
	.uleb128 L150-LFB3687
	.uleb128 0
	.uleb128 LEHB1-LFB3687
	.uleb128 LEHE1-LEHB1
	.uleb128 L151-LFB3687
	.uleb128 0
	.uleb128 LEHB2-LFB3687
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
LLSDACSE3687:
	.text
	.section	.text$_ZNK6dbgLog8category8iteratordeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category8iteratordeEv
	.def	__ZNK6dbgLog8category8iteratordeEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category8iteratordeEv:
LFB3689:
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
LFE3689:
	.section	.text$_ZNK6dbgLog8category8iteratorneES1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category8iteratorneES1_
	.def	__ZNK6dbgLog8category8iteratorneES1_;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category8iteratorneES1_:
LFB3691:
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
LFE3691:
	.section	.text$_ZNK6dbgLog8category8iteratorppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category8iteratorppEv
	.def	__ZNK6dbgLog8category8iteratorppEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category8iteratorppEv:
LFB3692:
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
	jb	L158
	call	__ZN6dbgLog8category9container6getEndEv
	jmp	L159
L158:
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
L159:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3692:
	.section	.text$_ZNSt8iteratorISt26bidirectional_iterator_tagN6dbgLog8categoryEiPS2_RS2_EC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8iteratorISt26bidirectional_iterator_tagN6dbgLog8categoryEiPS2_RS2_EC2Ev
	.def	__ZNSt8iteratorISt26bidirectional_iterator_tagN6dbgLog8categoryEiPS2_RS2_EC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt8iteratorISt26bidirectional_iterator_tagN6dbgLog8categoryEiPS2_RS2_EC2Ev:
LFB3699:
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
LFE3699:
	.section	.text$_ZN6dbgLog8category8iteratorC1Eh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8category8iteratorC1Eh
	.def	__ZN6dbgLog8category8iteratorC1Eh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category8iteratorC1Eh:
LFB3702:
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
LFE3702:
	.section	.text$_ZN6dbgLog8category8iteratorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8category8iteratorD1Ev
	.def	__ZN6dbgLog8category8iteratorD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category8iteratorD1Ev:
LFB3717:
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
LFE3717:
	.section	.text$_ZN6dbgLog8category9container10beginValueEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog8category9container10beginValueEv
	.def	__ZN6dbgLog8category9container10beginValueEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container10beginValueEv:
LFB3718:
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
LFE3718:
	.section	.text$_ZN6dbgLog8category9container8endValueEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog8category9container8endValueEv
	.def	__ZN6dbgLog8category9container8endValueEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container8endValueEv:
LFB3719:
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
LFE3719:
	.section	.text$_ZN6dbgLog8category9container3getEh,"x"
	.linkonce discard
	.globl	__ZN6dbgLog8category9container3getEh
	.def	__ZN6dbgLog8category9container3getEh;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container3getEh:
LFB3720:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movb	%al, -4(%ebp)
	movl	__ZN6dbgLog8category9container9m_poolPtrE, %eax
	movzbl	-4(%ebp), %edx
	sall	$3, %edx
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3720:
	.section	.text$_ZN6dbgLog8category9container6getEndEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog8category9container6getEndEv
	.def	__ZN6dbgLog8category9container6getEndEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container6getEndEv:
LFB3722:
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
	movzbl	%al, %eax
	sall	$3, %eax
	addl	%ebx, %eax
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3722:
	.section	.text$_ZN6dbgLog8category9container3setEhRKS0_,"x"
	.linkonce discard
	.globl	__ZN6dbgLog8category9container3setEhRKS0_
	.def	__ZN6dbgLog8category9container3setEhRKS0_;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container3setEhRKS0_:
LFB3723:
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
	je	L173
	movl	__ZN6dbgLog8category9container9m_poolPtrE, %eax
	movzbl	-28(%ebp), %edx
	sall	$3, %edx
	addl	%eax, %edx
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
L173:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3723:
	.section	.text$_ZN6dbgLog8category9container5beginEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog8category9container5beginEv
	.def	__ZN6dbgLog8category9container5beginEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container5beginEv:
LFB3724:
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
LFE3724:
	.section	.text$_ZN6dbgLog8category9container3endEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog8category9container3endEv
	.def	__ZN6dbgLog8category9container3endEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container3endEv:
LFB3725:
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
LFE3725:
	.section	.text$_ZN6dbgLog8categoryaSERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8categoryaSERKS0_
	.def	__ZN6dbgLog8categoryaSERKS0_;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8categoryaSERKS0_:
LFB3730:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$8, 8(%esp)
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
LFE3730:
	.section	.text$_ZNK6dbgLog8category5valueEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category5valueEv
	.def	__ZNK6dbgLog8category5valueEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category5valueEv:
LFB3734:
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
LFE3734:
	.section	.text$_ZNK6dbgLog8category4nameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category4nameEv
	.def	__ZNK6dbgLog8category4nameEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category4nameEv:
LFB3735:
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
LFE3735:
	.section	.text$_ZNK6dbgLog8category10isAssignedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category10isAssignedEv
	.def	__ZNK6dbgLog8category10isAssignedEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category10isAssignedEv:
LFB3736:
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
LFE3736:
	.section	.text$_ZNK6dbgLog8category10isReservedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category10isReservedEv
	.def	__ZNK6dbgLog8category10isReservedEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category10isReservedEv:
LFB3737:
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
LFE3737:
	.section	.text$_ZNK6dbgLog8category9forOutputEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category9forOutputEv
	.def	__ZNK6dbgLog8category9forOutputEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category9forOutputEv:
LFB3738:
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
LFE3738:
	.section	.text$_ZNK6dbgLog8category11forSetLevelEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6dbgLog8category11forSetLevelEv
	.def	__ZNK6dbgLog8category11forSetLevelEv;	.scl	2;	.type	32;	.endef
__ZNK6dbgLog8category11forSetLevelEv:
LFB3739:
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
LFE3739:
	.section	.text$_ZN6dbgLog8categoryC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8categoryC1Ev
	.def	__ZN6dbgLog8categoryC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8categoryC1Ev:
LFB3743:
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
	call	__ZN6dbgLog8category9container14initializeOnceEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3743:
	.section	.text$_ZN6dbgLog8categoryC2EhPKcbbb,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8categoryC2EhPKcbbb
	.def	__ZN6dbgLog8categoryC2EhPKcbbb;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8categoryC2EhPKcbbb:
LFB3748:
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
	movl	20(%ebp), %ecx
	movl	24(%ebp), %edx
	movl	28(%ebp), %eax
	movb	%bl, -12(%ebp)
	movb	%cl, -16(%ebp)
	movb	%dl, -20(%ebp)
	movb	%al, -24(%ebp)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movzbl	-12(%ebp), %edx
	movb	%dl, 4(%eax)
	movl	8(%ebp), %eax
	movzbl	-16(%ebp), %edx
	movb	%dl, 5(%eax)
	movl	8(%ebp), %eax
	movzbl	-20(%ebp), %edx
	movb	%dl, 6(%eax)
	movl	8(%ebp), %eax
	movzbl	-24(%ebp), %edx
	movb	%dl, 7(%eax)
	cmpb	$67, -12(%ebp)
	jbe	L195
	movl	$LC2, 12(%esp)
	movl	$__ZZN6dbgLog8categoryC1EhPKcbbbE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$814, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L195:
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category9container3setEhRKS0_
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3748:
	.section	.text$_ZN6dbgLog8categoryC1EhPKcbbb,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8categoryC1EhPKcbbb
	.def	__ZN6dbgLog8categoryC1EhPKcbbb;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8categoryC1EhPKcbbb:
LFB3749:
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
	movl	20(%ebp), %ecx
	movl	24(%ebp), %edx
	movl	28(%ebp), %eax
	movb	%bl, -12(%ebp)
	movb	%cl, -16(%ebp)
	movb	%dl, -20(%ebp)
	movb	%al, -24(%ebp)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movzbl	-12(%ebp), %edx
	movb	%dl, 4(%eax)
	movl	8(%ebp), %eax
	movzbl	-16(%ebp), %edx
	movb	%dl, 5(%eax)
	movl	8(%ebp), %eax
	movzbl	-20(%ebp), %edx
	movb	%dl, 6(%eax)
	movl	8(%ebp), %eax
	movzbl	-24(%ebp), %edx
	movb	%dl, 7(%eax)
	cmpb	$67, -12(%ebp)
	jbe	L197
	movl	$LC2, 12(%esp)
	movl	$__ZZN6dbgLog8categoryC1EhPKcbbbE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$814, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L197:
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category9container3setEhRKS0_
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3749:
	.section	.text$_ZN6dbgLog8categoryD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8categoryD2Ev
	.def	__ZN6dbgLog8categoryD2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8categoryD2Ev:
LFB3754:
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
LFE3754:
	.section	.text$_ZN6dbgLog8categoryD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog8categoryD1Ev
	.def	__ZN6dbgLog8categoryD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8categoryD1Ev:
LFB3755:
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
LFE3755:
	.section	.text$_ZN6dbgLog12category_endC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12category_endC1Ev
	.def	__ZN6dbgLog12category_endC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12category_endC1Ev:
LFB3761:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$0, 20(%esp)
	movl	$0, 16(%esp)
	movl	$1, 12(%esp)
	movl	$LC4, 8(%esp)
	movl	$67, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3761:
	.section	.text$_ZN6dbgLog17category_assignedILh0EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh0EED2Ev
	.def	__ZN6dbgLog17category_assignedILh0EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh0EED2Ev:
LFB3764:
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
LFE3764:
	.section .rdata,"dr"
LC18:
	.ascii "forAny\0"
	.section	.text$_ZN6dbgLog15category_forAnyC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog15category_forAnyC1Ev
	.def	__ZN6dbgLog15category_forAnyC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog15category_forAnyC1Ev:
LFB3767:
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
	call	__ZN6dbgLog17category_assignedILh0EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3767:
	.section	.text$_ZN6dbgLog17category_assignedILh1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh1EED2Ev
	.def	__ZN6dbgLog17category_assignedILh1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh1EED2Ev:
LFB3770:
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
LFE3770:
	.section .rdata,"dr"
LC19:
	.ascii "forLogic\0"
	.section	.text$_ZN6dbgLog17category_forLogicC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_forLogicC1Ev
	.def	__ZN6dbgLog17category_forLogicC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_forLogicC1Ev:
LFB3773:
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
	call	__ZN6dbgLog17category_assignedILh1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3773:
	.section	.text$_ZN6dbgLog17category_assignedILh2EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh2EED2Ev
	.def	__ZN6dbgLog17category_assignedILh2EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh2EED2Ev:
LFB3776:
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
LFE3776:
	.section .rdata,"dr"
LC20:
	.ascii "forResource\0"
	.section	.text$_ZN6dbgLog20category_forResourceC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog20category_forResourceC1Ev
	.def	__ZN6dbgLog20category_forResourceC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog20category_forResourceC1Ev:
LFB3779:
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
	call	__ZN6dbgLog17category_assignedILh2EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3779:
	.section	.text$_ZN6dbgLog17category_assignedILh3EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh3EED2Ev
	.def	__ZN6dbgLog17category_assignedILh3EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh3EED2Ev:
LFB3782:
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
LFE3782:
	.section .rdata,"dr"
LC21:
	.ascii "for3D\0"
	.section	.text$_ZN6dbgLog14category_for3DC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14category_for3DC1Ev
	.def	__ZN6dbgLog14category_for3DC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14category_for3DC1Ev:
LFB3785:
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
	call	__ZN6dbgLog17category_assignedILh3EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3785:
	.section	.text$_ZN6dbgLog17category_assignedILh4EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh4EED2Ev
	.def	__ZN6dbgLog17category_assignedILh4EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh4EED2Ev:
LFB3788:
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
LFE3788:
	.section .rdata,"dr"
LC22:
	.ascii "for2D\0"
	.section	.text$_ZN6dbgLog14category_for2DC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14category_for2DC1Ev
	.def	__ZN6dbgLog14category_for2DC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14category_for2DC1Ev:
LFB3791:
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
	call	__ZN6dbgLog17category_assignedILh4EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3791:
	.section	.text$_ZN6dbgLog17category_assignedILh5EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh5EED2Ev
	.def	__ZN6dbgLog17category_assignedILh5EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh5EED2Ev:
LFB3794:
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
LFE3794:
	.section .rdata,"dr"
LC23:
	.ascii "forSound\0"
	.section	.text$_ZN6dbgLog17category_forSoundC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_forSoundC1Ev
	.def	__ZN6dbgLog17category_forSoundC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_forSoundC1Ev:
LFB3797:
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
	call	__ZN6dbgLog17category_assignedILh5EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3797:
	.section	.text$_ZN6dbgLog17category_assignedILh6EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh6EED2Ev
	.def	__ZN6dbgLog17category_assignedILh6EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh6EED2Ev:
LFB3800:
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
LFE3800:
	.section .rdata,"dr"
LC24:
	.ascii "forScript\0"
	.section	.text$_ZN6dbgLog18category_forScriptC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog18category_forScriptC1Ev
	.def	__ZN6dbgLog18category_forScriptC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog18category_forScriptC1Ev:
LFB3803:
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
	call	__ZN6dbgLog17category_assignedILh6EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3803:
	.section	.text$_ZN6dbgLog17category_assignedILh7EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh7EED2Ev
	.def	__ZN6dbgLog17category_assignedILh7EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh7EED2Ev:
LFB3806:
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
LFE3806:
	.section .rdata,"dr"
LC25:
	.ascii "forGameData\0"
	.section	.text$_ZN6dbgLog20category_forGameDataC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog20category_forGameDataC1Ev
	.def	__ZN6dbgLog20category_forGameDataC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog20category_forGameDataC1Ev:
LFB3809:
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
	call	__ZN6dbgLog17category_assignedILh7EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3809:
	.section	.text$_ZN6dbgLog16category_specialILh64ELb0ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16category_specialILh64ELb0ELb1EED2Ev
	.def	__ZN6dbgLog16category_specialILh64ELb0ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16category_specialILh64ELb0ELb1EED2Ev:
LFB3812:
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
LFE3812:
	.section .rdata,"dr"
LC26:
	.ascii "forEvery\0"
	.section	.text$_ZN6dbgLog17category_forEveryC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_forEveryC1Ev
	.def	__ZN6dbgLog17category_forEveryC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_forEveryC1Ev:
LFB3815:
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
	call	__ZN6dbgLog16category_specialILh64ELb0ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3815:
	.section	.text$_ZN6dbgLog16category_specialILh65ELb1ELb0EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16category_specialILh65ELb1ELb0EED2Ev
	.def	__ZN6dbgLog16category_specialILh65ELb1ELb0EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16category_specialILh65ELb1ELb0EED2Ev:
LFB3818:
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
LFE3818:
	.section .rdata,"dr"
LC27:
	.ascii "forCallppoint\0"
	.section	.text$_ZN6dbgLog22category_forCallppointC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog22category_forCallppointC1Ev
	.def	__ZN6dbgLog22category_forCallppointC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog22category_forCallppointC1Ev:
LFB3821:
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
	call	__ZN6dbgLog16category_specialILh65ELb1ELb0EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3821:
	.section	.text$_ZN6dbgLog16category_specialILh66ELb1ELb0EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16category_specialILh66ELb1ELb0EED2Ev
	.def	__ZN6dbgLog16category_specialILh66ELb1ELb0EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16category_specialILh66ELb1ELb0EED2Ev:
LFB3824:
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
LFE3824:
	.section .rdata,"dr"
LC28:
	.ascii "forCriticalCallppoint\0"
	.section	.text$_ZN6dbgLog30category_forCriticalCallppointC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog30category_forCriticalCallppointC1Ev
	.def	__ZN6dbgLog30category_forCriticalCallppointC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog30category_forCriticalCallppointC1Ev:
LFB3827:
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
	call	__ZN6dbgLog16category_specialILh66ELb1ELb0EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3827:
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
	.space 544
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
LFB3837:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh0EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3837:
	.section	.text$_ZN6dbgLog17category_forLogicD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_forLogicD1Ev
	.def	__ZN6dbgLog17category_forLogicD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_forLogicD1Ev:
LFB3840:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3840:
	.section	.text$_ZN6dbgLog20category_forResourceD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog20category_forResourceD1Ev
	.def	__ZN6dbgLog20category_forResourceD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog20category_forResourceD1Ev:
LFB3843:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh2EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3843:
	.section	.text$_ZN6dbgLog14category_for3DD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14category_for3DD1Ev
	.def	__ZN6dbgLog14category_for3DD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14category_for3DD1Ev:
LFB3846:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh3EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3846:
	.section	.text$_ZN6dbgLog14category_for2DD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog14category_for2DD1Ev
	.def	__ZN6dbgLog14category_for2DD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog14category_for2DD1Ev:
LFB3849:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh4EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3849:
	.section	.text$_ZN6dbgLog17category_forSoundD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_forSoundD1Ev
	.def	__ZN6dbgLog17category_forSoundD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_forSoundD1Ev:
LFB3852:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh5EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3852:
	.section	.text$_ZN6dbgLog18category_forScriptD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog18category_forScriptD1Ev
	.def	__ZN6dbgLog18category_forScriptD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog18category_forScriptD1Ev:
LFB3855:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh6EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3855:
	.section	.text$_ZN6dbgLog20category_forGameDataD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog20category_forGameDataD1Ev
	.def	__ZN6dbgLog20category_forGameDataD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog20category_forGameDataD1Ev:
LFB3858:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_assignedILh7EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3858:
	.section	.text$_ZN6dbgLog17category_forEveryD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_forEveryD1Ev
	.def	__ZN6dbgLog17category_forEveryD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_forEveryD1Ev:
LFB3861:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog16category_specialILh64ELb0ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3861:
	.section	.text$_ZN6dbgLog22category_forCallppointD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog22category_forCallppointD1Ev
	.def	__ZN6dbgLog22category_forCallppointD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog22category_forCallppointD1Ev:
LFB3864:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog16category_specialILh65ELb1ELb0EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3864:
	.section	.text$_ZN6dbgLog30category_forCriticalCallppointD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog30category_forCriticalCallppointD1Ev
	.def	__ZN6dbgLog30category_forCriticalCallppointD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog30category_forCriticalCallppointD1Ev:
LFB3867:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog16category_specialILh66ELb1ELb0EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3867:
	.section	.text$_ZN6dbgLog12category_endD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12category_endD1Ev
	.def	__ZN6dbgLog12category_endD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12category_endD1Ev:
LFB3870:
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
LFE3870:
	.text
	.align 2
	.globl	__ZN6dbgLog8category9container14initializeOnceEv
	.def	__ZN6dbgLog8category9container14initializeOnceEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog8category9container14initializeOnceEv:
LFB3834:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$168, %esp
	movzbl	__ZN6dbgLog8category9container15m_isInitializedE, %eax
	testb	%al, %al
	je	L261
	jmp	L260
L261:
	movb	$1, __ZN6dbgLog8category9container15m_isInitializedE
	movl	$__ZN6dbgLog8category9container15m_isAlreadyPoolE, (%esp)
	call	__ZNSt6bitsetILj68EE5resetEv
	movl	$544, 8(%esp)
	movl	$0, 4(%esp)
	movl	$__ZN6dbgLog8category9container6m_poolE, (%esp)
	call	_memset
	movl	$__ZN6dbgLog8category9container6m_poolE, __ZN6dbgLog8category9container9m_poolPtrE
	movb	$0, -9(%ebp)
	jmp	L263
L264:
	movzbl	-9(%ebp), %eax
	movl	$0, 20(%esp)
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	$LC14, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC1EhPKcbbb
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryD1Ev
	movzbl	-9(%ebp), %edx
	leal	-116(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	$__ZN6dbgLog8category9container15m_isAlreadyPoolE, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj68EEixEj
	subl	$4, %esp
	movl	$0, 4(%esp)
	leal	-116(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj68EE9referenceaSEb
	leal	-116(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6bitsetILj68EE9referenceD1Ev
	addb	$1, -9(%ebp)
L263:
	cmpb	$66, -9(%ebp)
	jbe	L264
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog15category_forAnyC1Ev
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog15category_forAnyD1Ev
	leal	-100(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_forLogicC1Ev
	leal	-100(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_forLogicD1Ev
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog20category_forResourceC1Ev
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog20category_forResourceD1Ev
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog14category_for3DC1Ev
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog14category_for3DD1Ev
	leal	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog14category_for2DC1Ev
	leal	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog14category_for2DD1Ev
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_forSoundC1Ev
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_forSoundD1Ev
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog18category_forScriptC1Ev
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog18category_forScriptD1Ev
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog20category_forGameDataC1Ev
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog20category_forGameDataD1Ev
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_forEveryC1Ev
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_forEveryD1Ev
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog22category_forCallppointC1Ev
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog22category_forCallppointD1Ev
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog30category_forCriticalCallppointC1Ev
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog30category_forCriticalCallppointD1Ev
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12category_endC1Ev
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog12category_endD1Ev
L260:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3834:
.lcomm __ZN6dbgLogL23s_categoryForInitializeE,8,4
	.section .rdata,"dr"
	.align 4
LC29:
	.ascii "category=%d, name=\"%s\", isAssigned=%d, isReserved=%d, forOutput=%d, forSetLevel=%d\12\0"
	.text
	.globl	__ZN6dbgLog16printCategoryAllEv
	.def	__ZN6dbgLog16printCategoryAllEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16printCategoryAllEv:
LFB3871:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3871
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
	jmp	L266
L267:
	leal	-35(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category8iteratordeEv
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category11forSetLevelEv
	movzbl	%al, %eax
	movl	%eax, -44(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6dbgLog8category9forOutputEv
	movzbl	%al, %ecx
	movl	%ecx, -48(%ebp)
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
	movl	%edx, 24(%esp)
	movl	-48(%ebp), %ecx
	movl	%ecx, 20(%esp)
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
L266:
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
	jne	L267
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category8iteratorD1Ev
	leal	-35(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog8category8iteratorD1Ev
	jmp	L270
L269:
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
L270:
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
LFE3871:
	.section	.gcc_except_table,"w"
LLSDA3871:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3871-LLSDACSB3871
LLSDACSB3871:
	.uleb128 LEHB3-LFB3871
	.uleb128 LEHE3-LEHB3
	.uleb128 L269-LFB3871
	.uleb128 0
	.uleb128 LEHB4-LFB3871
	.uleb128 LEHE4-LEHB4
	.uleb128 0
	.uleb128 0
LLSDACSE3871:
	.text
	.section	.text$_ZN6dbgLog3log16resetLogLevelAllEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log16resetLogLevelAllEv
	.def	__ZN6dbgLog3log16resetLogLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log16resetLogLevelAllEv:
LFB3872:
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
	jmp	L272
L273:
	movl	-4(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movb	$2, (%eax)
	addl	$1, -4(%ebp)
L272:
	movl	-4(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jne	L273
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3872:
	.section	.text$_ZN6dbgLog3log19resetNoticeLevelAllEv,"x"
	.linkonce discard
	.globl	__ZN6dbgLog3log19resetNoticeLevelAllEv
	.def	__ZN6dbgLog3log19resetNoticeLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3log19resetNoticeLevelAllEv:
LFB3873:
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
	jmp	L275
L276:
	movl	-4(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movb	$8, (%eax)
	addl	$1, -4(%ebp)
L275:
	movl	-4(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jne	L276
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3873:
	.section	.text$_ZN6dbgLog3logC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3logC1Ev
	.def	__ZN6dbgLog3logC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3logC1Ev:
LFB3880:
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
LFE3880:
	.section	.text$_ZN6dbgLog3logD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3logD1Ev
	.def	__ZN6dbgLog3logD1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3logD1Ev:
LFB3886:
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
LFE3886:
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
LFB3887:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movzbl	__ZN6dbgLog3log15m_isInitializedE, %eax
	testb	%al, %al
	je	L281
	jmp	L280
L281:
	movb	$1, __ZN6dbgLog3log15m_isInitializedE
	call	__ZN6dbgLog3log16resetLogLevelAllEv
	call	__ZN6dbgLog3log19resetNoticeLevelAllEv
L280:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3887:
.lcomm __ZN6dbgLogL18s_logForInitializeE,132,32
	.section	.text$_ZN6dbgLog17category_reservedILh8EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_reservedILh8EED2Ev
	.def	__ZN6dbgLog17category_reservedILh8EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_reservedILh8EED2Ev:
LFB3890:
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
LFE3890:
	.section .rdata,"dr"
LC30:
	.ascii "forReserved01\0"
	.section	.text$_ZN6dbgLog3ext22category_forReserved01C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3ext22category_forReserved01C1Ev
	.def	__ZN6dbgLog3ext22category_forReserved01C1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3ext22category_forReserved01C1Ev:
LFB3893:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC30, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_reservedILh8EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3893:
	.section	.text$_ZN6dbgLog17category_reservedILh9EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_reservedILh9EED2Ev
	.def	__ZN6dbgLog17category_reservedILh9EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_reservedILh9EED2Ev:
LFB3896:
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
LFE3896:
	.section .rdata,"dr"
LC31:
	.ascii "forReserved02\0"
	.section	.text$_ZN6dbgLog3ext22category_forReserved02C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3ext22category_forReserved02C1Ev
	.def	__ZN6dbgLog3ext22category_forReserved02C1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3ext22category_forReserved02C1Ev:
LFB3899:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC31, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_reservedILh9EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3899:
	.section	.text$_ZN6dbgLog17category_reservedILh10EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_reservedILh10EED2Ev
	.def	__ZN6dbgLog17category_reservedILh10EED2Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_reservedILh10EED2Ev:
LFB3902:
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
LFE3902:
	.section .rdata,"dr"
LC32:
	.ascii "forReserved03\0"
	.section	.text$_ZN6dbgLog3ext22category_forReserved03C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3ext22category_forReserved03C1Ev
	.def	__ZN6dbgLog3ext22category_forReserved03C1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3ext22category_forReserved03C1Ev:
LFB3905:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC32, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_reservedILh10EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3905:
	.section	.text$_ZN6dbgLog3ext22category_forReserved01D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3ext22category_forReserved01D1Ev
	.def	__ZN6dbgLog3ext22category_forReserved01D1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3ext22category_forReserved01D1Ev:
LFB3909:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_reservedILh8EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3909:
	.section	.text$_ZN6dbgLog3ext22category_forReserved02D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3ext22category_forReserved02D1Ev
	.def	__ZN6dbgLog3ext22category_forReserved02D1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3ext22category_forReserved02D1Ev:
LFB3912:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_reservedILh9EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3912:
	.section	.text$_ZN6dbgLog3ext22category_forReserved03D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3ext22category_forReserved03D1Ev
	.def	__ZN6dbgLog3ext22category_forReserved03D1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3ext22category_forReserved03D1Ev:
LFB3915:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog17category_reservedILh10EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3915:
	.section	.text$_ZN6dbgLog3ext20categoryContainerExtC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog3ext20categoryContainerExtC1Ev
	.def	__ZN6dbgLog3ext20categoryContainerExtC1Ev;	.scl	2;	.type	32;	.endef
__ZN6dbgLog3ext20categoryContainerExtC1Ev:
LFB3917:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	call	__ZN6dbgLog8category9container14initializeOnceEv
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3ext22category_forReserved01C1Ev
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3ext22category_forReserved01D1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3ext22category_forReserved02C1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3ext22category_forReserved02D1Ev
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3ext22category_forReserved03C1Ev
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6dbgLog3ext22category_forReserved03D1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3917:
.lcomm __ZN6dbgLog3extL23s_categoryForInitializeE,1,1
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB3918:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	call	___main
	call	__ZN6dbgLog13printLevelAllEv
	call	__ZN6dbgLog16printCategoryAllEv
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3918:
	.section	.text$_ZNSt6bitsetILj14EEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EEixEj
	.def	__ZNSt6bitsetILj14EEixEj;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EEixEj:
LFB3955:
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
LFE3955:
	.section	.text$_ZNSt6bitsetILj14EE9referenceD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE9referenceD1Ev
	.def	__ZNSt6bitsetILj14EE9referenceD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE9referenceD1Ev:
LFB3958:
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
LFE3958:
	.section	.text$_ZNKSt6bitsetILj14EE9referencecvbEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6bitsetILj14EE9referencecvbEv
	.def	__ZNKSt6bitsetILj14EE9referencecvbEv;	.scl	2;	.type	32;	.endef
__ZNKSt6bitsetILj14EE9referencecvbEv:
LFB3959:
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
LFE3959:
	.section	.text$_ZNSt6bitsetILj14EE9referenceaSEb,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE9referenceaSEb
	.def	__ZNSt6bitsetILj14EE9referenceaSEb;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE9referenceaSEb:
LFB3960:
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
	je	L308
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
	jmp	L309
L308:
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
L309:
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3960:
	.section	.text$_ZN6dbgLog12level_normalILh2ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh2ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc
	.def	__ZN6dbgLog12level_normalILh2ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh2ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc:
LFB3962:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$15, 32(%esp)
	movl	$0, 28(%esp)
	movl	$16, 24(%esp)
	movl	$16, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3962:
	.section	.text$_ZN6dbgLog12level_normalILh0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc
	.def	__ZN6dbgLog12level_normalILh0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc:
LFB3965:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$15, 32(%esp)
	movl	$8, 28(%esp)
	movl	$0, 24(%esp)
	movl	$8, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3965:
	.section	.text$_ZN6dbgLog12level_normalILh1ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh1ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc
	.def	__ZN6dbgLog12level_normalILh1ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh1ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc:
LFB3968:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$15, 32(%esp)
	movl	$8, 28(%esp)
	movl	$0, 24(%esp)
	movl	$8, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3968:
	.section	.text$_ZN6dbgLog12level_normalILh4ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh4ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc
	.def	__ZN6dbgLog12level_normalILh4ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh4ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc:
LFB3971:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$15, 32(%esp)
	movl	$12, 28(%esp)
	movl	$0, 24(%esp)
	movl	$12, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$4, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3971:
	.section	.text$_ZN6dbgLog12level_normalILh6ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh6ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc
	.def	__ZN6dbgLog12level_normalILh6ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh6ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc:
LFB3974:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$13, 32(%esp)
	movl	$0, 28(%esp)
	movl	$0, 24(%esp)
	movl	$13, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$6, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3974:
	.section	.text$_ZN6dbgLog12level_normalILh8ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh8ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc
	.def	__ZN6dbgLog12level_normalILh8ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh8ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc:
LFB3977:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$9, 32(%esp)
	movl	$11, 28(%esp)
	movl	$0, 24(%esp)
	movl	$9, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$8, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3977:
	.section	.text$_ZN6dbgLog12level_normalILh10ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog12level_normalILh10ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc
	.def	__ZN6dbgLog12level_normalILh10ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog12level_normalILh10ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc:
LFB3980:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$32, 32(%esp)
	movl	$32, 28(%esp)
	movl	$32, 24(%esp)
	movl	$32, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$10, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3980:
	.section	.text$_ZN6dbgLog13level_specialILh11EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog13level_specialILh11EEC2EPKc
	.def	__ZN6dbgLog13level_specialILh11EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog13level_specialILh11EEC2EPKc:
LFB3983:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$32, 32(%esp)
	movl	$32, 28(%esp)
	movl	$32, 24(%esp)
	movl	$32, 20(%esp)
	movl	$1, 16(%esp)
	movl	$0, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$11, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3983:
	.section	.text$_ZN6dbgLog13level_specialILh12EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog13level_specialILh12EEC2EPKc
	.def	__ZN6dbgLog13level_specialILh12EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog13level_specialILh12EEC2EPKc:
LFB3986:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	$32, 32(%esp)
	movl	$32, 28(%esp)
	movl	$32, 24(%esp)
	movl	$32, 20(%esp)
	movl	$1, 16(%esp)
	movl	$0, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$12, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog5levelC2EhPKcbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3986:
	.section	.text$_ZNSt6bitsetILj14EE5resetEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE5resetEv
	.def	__ZNSt6bitsetILj14EE5resetEv;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE5resetEv:
LFB3988:
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
LFE3988:
	.section	.text$_ZNSt6bitsetILj68EEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EEixEj
	.def	__ZNSt6bitsetILj68EEixEj;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EEixEj:
LFB3989:
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
LFE3989:
	.section	.text$_ZNSt6bitsetILj68EE9referenceD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE9referenceD1Ev
	.def	__ZNSt6bitsetILj68EE9referenceD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE9referenceD1Ev:
LFB3992:
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
LFE3992:
	.section	.text$_ZNSt12_Base_bitsetILj3EE11_S_whichbitEj,"x"
	.linkonce discard
	.globl	__ZNSt12_Base_bitsetILj3EE11_S_whichbitEj
	.def	__ZNSt12_Base_bitsetILj3EE11_S_whichbitEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE11_S_whichbitEj:
LFB3995:
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
LFE3995:
	.section	.text$_ZNSt12_Base_bitsetILj3EE10_S_maskbitEj,"x"
	.linkonce discard
	.globl	__ZNSt12_Base_bitsetILj3EE10_S_maskbitEj
	.def	__ZNSt12_Base_bitsetILj3EE10_S_maskbitEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE10_S_maskbitEj:
LFB3994:
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
LFE3994:
	.section	.text$_ZNKSt6bitsetILj68EE9referencecvbEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6bitsetILj68EE9referencecvbEv
	.def	__ZNKSt6bitsetILj68EE9referencecvbEv;	.scl	2;	.type	32;	.endef
__ZNKSt6bitsetILj68EE9referencecvbEv:
LFB3993:
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
LFE3993:
	.section	.text$_ZNSt6bitsetILj68EE9referenceaSEb,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE9referenceaSEb
	.def	__ZNSt6bitsetILj68EE9referenceaSEb;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE9referenceaSEb:
LFB3996:
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
	je	L333
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
	jmp	L334
L333:
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
L334:
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3996:
	.section	.text$_ZN6dbgLog17category_assignedILh0EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh0EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh0EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh0EEC2EPKc:
LFB3998:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3998:
	.section	.text$_ZN6dbgLog17category_assignedILh1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh1EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh1EEC2EPKc:
LFB4001:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4001:
	.section	.text$_ZN6dbgLog17category_assignedILh2EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh2EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh2EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh2EEC2EPKc:
LFB4004:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4004:
	.section	.text$_ZN6dbgLog17category_assignedILh3EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh3EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh3EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh3EEC2EPKc:
LFB4007:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$3, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4007:
	.section	.text$_ZN6dbgLog17category_assignedILh4EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh4EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh4EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh4EEC2EPKc:
LFB4010:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$4, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4010:
	.section	.text$_ZN6dbgLog17category_assignedILh5EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh5EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh5EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh5EEC2EPKc:
LFB4013:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4013:
	.section	.text$_ZN6dbgLog17category_assignedILh6EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh6EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh6EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh6EEC2EPKc:
LFB4016:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$6, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4016:
	.section	.text$_ZN6dbgLog17category_assignedILh7EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_assignedILh7EEC2EPKc
	.def	__ZN6dbgLog17category_assignedILh7EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_assignedILh7EEC2EPKc:
LFB4019:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$7, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4019:
	.section	.text$_ZN6dbgLog16category_specialILh64ELb0ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16category_specialILh64ELb0ELb1EEC2EPKc
	.def	__ZN6dbgLog16category_specialILh64ELb0ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16category_specialILh64ELb0ELb1EEC2EPKc:
LFB4022:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 20(%esp)
	movl	$0, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$64, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4022:
	.section	.text$_ZN6dbgLog16category_specialILh65ELb1ELb0EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16category_specialILh65ELb1ELb0EEC2EPKc
	.def	__ZN6dbgLog16category_specialILh65ELb1ELb0EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16category_specialILh65ELb1ELb0EEC2EPKc:
LFB4025:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$0, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$65, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4025:
	.section	.text$_ZN6dbgLog16category_specialILh66ELb1ELb0EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog16category_specialILh66ELb1ELb0EEC2EPKc
	.def	__ZN6dbgLog16category_specialILh66ELb1ELb0EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog16category_specialILh66ELb1ELb0EEC2EPKc:
LFB4028:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$0, 20(%esp)
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$66, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4028:
	.section	.text$_ZNSt6bitsetILj68EE5resetEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE5resetEv
	.def	__ZNSt6bitsetILj68EE5resetEv;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE5resetEv:
LFB4030:
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
LFE4030:
	.section	.text$_ZN6dbgLog17category_reservedILh8EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_reservedILh8EEC2EPKc
	.def	__ZN6dbgLog17category_reservedILh8EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_reservedILh8EEC2EPKc:
LFB4032:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$0, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$8, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4032:
	.section	.text$_ZN6dbgLog17category_reservedILh9EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_reservedILh9EEC2EPKc
	.def	__ZN6dbgLog17category_reservedILh9EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_reservedILh9EEC2EPKc:
LFB4035:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$0, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$9, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4035:
	.section	.text$_ZN6dbgLog17category_reservedILh10EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6dbgLog17category_reservedILh10EEC2EPKc
	.def	__ZN6dbgLog17category_reservedILh10EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN6dbgLog17category_reservedILh10EEC2EPKc:
LFB4038:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$1, 20(%esp)
	movl	$1, 16(%esp)
	movl	$0, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$10, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6dbgLog8categoryC2EhPKcbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4038:
	.section	.text$_ZNSt6bitsetILj14EE9referenceC1ERS0_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE9referenceC1ERS0_j
	.def	__ZNSt6bitsetILj14EE9referenceC1ERS0_j;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE9referenceC1ERS0_j:
LFB4063:
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
LFE4063:
	.section	.text$_ZNSt6bitsetILj68EE9referenceC1ERS0_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE9referenceC1ERS0_j
	.def	__ZNSt6bitsetILj68EE9referenceC1ERS0_j;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE9referenceC1ERS0_j:
LFB4066:
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
LFE4066:
	.section	.text$_ZNSt12_Base_bitsetILj3EE11_M_do_resetEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Base_bitsetILj3EE11_M_do_resetEv
	.def	__ZNSt12_Base_bitsetILj3EE11_M_do_resetEv;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE11_M_do_resetEv:
LFB4067:
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
LFE4067:
	.section	.text$_ZNSt12_Base_bitsetILj3EE12_S_whichwordEj,"x"
	.linkonce discard
	.globl	__ZNSt12_Base_bitsetILj3EE12_S_whichwordEj
	.def	__ZNSt12_Base_bitsetILj3EE12_S_whichwordEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE12_S_whichwordEj:
LFB4078:
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
LFE4078:
	.section	.text$_ZNSt12_Base_bitsetILj3EE10_M_getwordEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Base_bitsetILj3EE10_M_getwordEj
	.def	__ZNSt12_Base_bitsetILj3EE10_M_getwordEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE10_M_getwordEj:
LFB4077:
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
LFE4077:
	.text
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB4090:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L360
	cmpl	$65535, 12(%ebp)
	jne	L360
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
L360:
	cmpl	$0, 8(%ebp)
	jne	L359
	cmpl	$65535, 12(%ebp)
	jne	L359
	movl	$__ZN6dbgLogL18s_logForInitializeE, (%esp)
	call	__ZN6dbgLog3logD1Ev
	movl	$__ZN6dbgLogL23s_categoryForInitializeE, (%esp)
	call	__ZN6dbgLog8categoryD1Ev
	movl	$__ZN6dbgLogL20s_levelForInitializeE, (%esp)
	call	__ZN6dbgLog5levelD1Ev
	movl	$__ZN6dbgLogL20s_colorForInitializeE, (%esp)
	call	__ZN6dbgLog5colorD1Ev
L359:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4090:
	.def	__GLOBAL__sub_I__ZN6dbgLog5color15m_isInitializedE;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__ZN6dbgLog5color15m_isInitializedE:
LFB4091:
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
LFE4091:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__ZN6dbgLog5color15m_isInitializedE
	.text
	.def	__GLOBAL__sub_D__ZN6dbgLog5color15m_isInitializedE;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_D__ZN6dbgLog5color15m_isInitializedE:
LFB4092:
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
LFE4092:
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__sub_D__ZN6dbgLog5color15m_isInitializedE
	.section .rdata,"dr"
	.align 32
__ZZN6dbgLog5levelC1EhPKcbbNS_5color7color_tES4_S4_S4_E19__PRETTY_FUNCTION__:
	.ascii "dbgLog::level::level(dbgLog::level::value_t, const char*, bool, bool, dbgLog::color::color_t, dbgLog::color::color_t, dbgLog::color::color_t, dbgLog::color::color_t)\0"
	.align 32
__ZZN6dbgLog8categoryC1EhPKcbbbE19__PRETTY_FUNCTION__:
	.ascii "dbgLog::category::category(dbgLog::category::value_t, const char*, bool, bool, bool)\0"
	.ident	"GCC: (GNU) 4.8.2"
	.def	_fwrite;	.scl	2;	.type	32;	.endef
	.def	_fprintf;	.scl	2;	.type	32;	.endef
	.def	_memcpy;	.scl	2;	.type	32;	.endef
	.def	___assert_func;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef
	.def	___getreent;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef

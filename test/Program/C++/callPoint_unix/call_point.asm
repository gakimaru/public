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
	.text
	.globl	__Z11getFileNamePKc
	.def	__Z11getFileNamePKc;	.scl	2;	.type	32;	.endef
__Z11getFileNamePKc:
LFB3903:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	cmpl	$0, 8(%ebp)
	jne	L9
	movl	$0, %eax
	jmp	L10
L9:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	addl	%edx, %eax
	movl	%eax, -16(%ebp)
	jmp	L11
L14:
	movl	-16(%ebp), %eax
	subl	$1, %eax
	movzbl	(%eax), %eax
	movb	%al, -17(%ebp)
	cmpb	$92, -17(%ebp)
	je	L12
	cmpb	$47, -17(%ebp)
	jne	L13
L12:
	movl	-16(%ebp), %eax
	jmp	L10
L13:
	subl	$1, -12(%ebp)
	subl	$1, -16(%ebp)
L11:
	cmpl	$0, -12(%ebp)
	jne	L14
	movl	8(%ebp), %eax
L10:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3903:
	.section	.text$_ZN3dbg5color11changeColorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg5color11changeColorEv
	.def	__ZN3dbg5color11changeColorEv;	.scl	2;	.type	32;	.endef
__ZN3dbg5color11changeColorEv:
LFB3912:
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
	jne	L16
	jmp	L15
L16:
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
	call	__ZN3dbg5color11changeColorENS0_8target_tENS0_7color_tES2_
L15:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3912:
	.section .rdata,"dr"
LC0:
	.ascii "\33[39m\33[49m\0"
LC1:
	.ascii "\33[%dm\33[%dm\0"
	.section	.text$_ZN3dbg5color11changeColorENS0_8target_tENS0_7color_tES2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg5color11changeColorENS0_8target_tENS0_7color_tES2_
	.def	__ZN3dbg5color11changeColorENS0_8target_tENS0_7color_tES2_;	.scl	2;	.type	32;	.endef
__ZN3dbg5color11changeColorENS0_8target_tENS0_7color_tES2_:
LFB3913:
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
	movl	__ZN3dbg5color8m_handleE(,%eax,4), %eax
	movl	%eax, -12(%ebp)
	cmpb	$16, -32(%ebp)
	jne	L19
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$10, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC0, (%esp)
	call	_fwrite
	jmp	L18
L19:
	movzbl	-36(%ebp), %eax
	andl	$8, %eax
	testl	%eax, %eax
	je	L21
	movl	$100, %eax
	jmp	L22
L21:
	movl	$40, %eax
L22:
	movzbl	-36(%ebp), %edx
	andl	$7, %edx
	addl	%eax, %edx
	movzbl	-32(%ebp), %eax
	andl	$8, %eax
	testl	%eax, %eax
	je	L23
	movl	$90, %eax
	jmp	L24
L23:
	movl	$30, %eax
L24:
	movzbl	-32(%ebp), %ecx
	andl	$7, %ecx
	addl	%ecx, %eax
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
L18:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3913:
	.section	.text$_ZN3dbg5colorC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg5colorC1Ev
	.def	__ZN3dbg5colorC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg5colorC1Ev:
LFB3916:
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
	call	__ZN3dbg5color14initializeOnceEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3916:
	.section	.text$_ZN3dbg5colorC1EOS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg5colorC1EOS0_
	.def	__ZN3dbg5colorC1EOS0_;	.scl	2;	.type	32;	.endef
__ZN3dbg5colorC1EOS0_:
LFB3919:
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
LFE3919:
	.section	.text$_ZN3dbg5colorC1ENS0_8target_tENS0_7color_tES2_b,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg5colorC1ENS0_8target_tENS0_7color_tES2_b
	.def	__ZN3dbg5colorC1ENS0_8target_tENS0_7color_tES2_b;	.scl	2;	.type	32;	.endef
__ZN3dbg5colorC1ENS0_8target_tENS0_7color_tES2_b:
LFB3922:
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
	movzbl	__ZN3dbg5color14m_nowForeColorE(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, 3(%eax)
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movzbl	__ZN3dbg5color14m_nowBackColorE(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, 4(%eax)
	movl	8(%ebp), %eax
	movzbl	-24(%ebp), %edx
	movb	%dl, 5(%eax)
	movl	8(%ebp), %eax
	movzbl	1(%eax), %eax
	cmpb	$32, %al
	je	L28
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L29
L28:
	jmp	L27
L29:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movzbl	1(%edx), %edx
	movb	%dl, __ZN3dbg5color14m_nowForeColorE(%eax)
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movzbl	2(%edx), %edx
	movb	%dl, __ZN3dbg5color14m_nowBackColorE(%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5color11changeColorEv
L27:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3922:
	.section	.text$_ZN3dbg5colorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg5colorD1Ev
	.def	__ZN3dbg5colorD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg5colorD1Ev:
LFB3925:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3925
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movzbl	1(%eax), %eax
	cmpb	$32, %al
	je	L31
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	jne	L31
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movzbl	3(%edx), %edx
	movb	%dl, __ZN3dbg5color14m_nowForeColorE(%eax)
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movzbl	4(%edx), %edx
	movb	%dl, __ZN3dbg5color14m_nowBackColorE(%eax)
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
	call	__ZN3dbg5color11changeColorENS0_8target_tENS0_7color_tES2_
L31:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3925:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA3925:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3925-LLSDACSB3925
LLSDACSB3925:
LLSDACSE3925:
	.section	.text$_ZN3dbg5colorD1Ev,"x"
	.linkonce discard
	.globl	__ZN3dbg5color15m_isInitializedE
	.bss
__ZN3dbg5color15m_isInitializedE:
	.space 1
	.globl	__ZN3dbg5color14m_nowForeColorE
	.data
__ZN3dbg5color14m_nowForeColorE:
	.byte	16
	.byte	16
	.globl	__ZN3dbg5color14m_nowBackColorE
__ZN3dbg5color14m_nowBackColorE:
	.byte	16
	.byte	16
	.globl	__ZN3dbg5color8m_handleE
	.bss
	.align 4
__ZN3dbg5color8m_handleE:
	.space 8
	.text
	.align 2
	.globl	__ZN3dbg5color14initializeOnceEv
	.def	__ZN3dbg5color14initializeOnceEv;	.scl	2;	.type	32;	.endef
__ZN3dbg5color14initializeOnceEv:
LFB3926:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movzbl	__ZN3dbg5color15m_isInitializedE, %eax
	testb	%al, %al
	je	L34
	jmp	L33
L34:
	movb	$1, __ZN3dbg5color15m_isInitializedE
L33:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3926:
.lcomm __ZN3dbgL20s_colorForInitializeE,6,1
	.section	.text$_ZNK3dbg5level8iteratordeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg5level8iteratordeEv
	.def	__ZNK3dbg5level8iteratordeEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg5level8iteratordeEv:
LFB3928:
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
	call	__ZN3dbg5level9container3getEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3928:
	.section	.text$_ZNK3dbg5level8iteratorneES1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg5level8iteratorneES1_
	.def	__ZNK3dbg5level8iteratorneES1_;	.scl	2;	.type	32;	.endef
__ZNK3dbg5level8iteratorneES1_:
LFB3930:
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
LFE3930:
	.section	.text$_ZNK3dbg5level8iteratorppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg5level8iteratorppEv
	.def	__ZNK3dbg5level8iteratorppEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg5level8iteratorppEv:
LFB3931:
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
	call	__ZN3dbg5level9container8endValueEv
	cmpb	%al, %bl
	jb	L41
	call	__ZN3dbg5level9container6getEndEv
	jmp	L42
L41:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, (%eax)
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level9container3getEh
L42:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3931:
	.section	.text$_ZNSt8iteratorISt26bidirectional_iterator_tagN3dbg5levelEiPS2_RS2_EC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8iteratorISt26bidirectional_iterator_tagN3dbg5levelEiPS2_RS2_EC2Ev
	.def	__ZNSt8iteratorISt26bidirectional_iterator_tagN3dbg5levelEiPS2_RS2_EC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt8iteratorISt26bidirectional_iterator_tagN3dbg5levelEiPS2_RS2_EC2Ev:
LFB3938:
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
LFE3938:
	.section	.text$_ZN3dbg5level8iteratorC1Eh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg5level8iteratorC1Eh
	.def	__ZN3dbg5level8iteratorC1Eh;	.scl	2;	.type	32;	.endef
__ZN3dbg5level8iteratorC1Eh:
LFB3941:
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
	call	__ZNSt8iteratorISt26bidirectional_iterator_tagN3dbg5levelEiPS2_RS2_EC2Ev
	movl	8(%ebp), %eax
	movzbl	-4(%ebp), %edx
	movb	%dl, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3941:
	.section	.text$_ZN3dbg5level8iteratorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg5level8iteratorD1Ev
	.def	__ZN3dbg5level8iteratorD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg5level8iteratorD1Ev:
LFB3956:
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
LFE3956:
	.section	.text$_ZN3dbg5level9container10beginValueEv,"x"
	.linkonce discard
	.globl	__ZN3dbg5level9container10beginValueEv
	.def	__ZN3dbg5level9container10beginValueEv;	.scl	2;	.type	32;	.endef
__ZN3dbg5level9container10beginValueEv:
LFB3957:
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
LFE3957:
	.section	.text$_ZN3dbg5level9container8endValueEv,"x"
	.linkonce discard
	.globl	__ZN3dbg5level9container8endValueEv
	.def	__ZN3dbg5level9container8endValueEv;	.scl	2;	.type	32;	.endef
__ZN3dbg5level9container8endValueEv:
LFB3958:
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
LFE3958:
	.section	.text$_ZN3dbg5level9container3getEh,"x"
	.linkonce discard
	.globl	__ZN3dbg5level9container3getEh
	.def	__ZN3dbg5level9container3getEh;	.scl	2;	.type	32;	.endef
__ZN3dbg5level9container3getEh:
LFB3959:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movb	%al, -4(%ebp)
	movl	__ZN3dbg5level9container9m_poolPtrE, %ecx
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
LFE3959:
	.section	.text$_ZN3dbg5level9container6getEndEv,"x"
	.linkonce discard
	.globl	__ZN3dbg5level9container6getEndEv
	.def	__ZN3dbg5level9container6getEndEv;	.scl	2;	.type	32;	.endef
__ZN3dbg5level9container6getEndEv:
LFB3961:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	.cfi_offset 3, -12
	movl	__ZN3dbg5level9container9m_poolPtrE, %ebx
	call	__ZN3dbg5level9container8endValueEv
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
LFE3961:
	.section	.text$_ZN3dbg5level9container3setEhRKS0_,"x"
	.linkonce discard
	.globl	__ZN3dbg5level9container3setEhRKS0_
	.def	__ZN3dbg5level9container3setEhRKS0_;	.scl	2;	.type	32;	.endef
__ZN3dbg5level9container3setEhRKS0_:
LFB3962:
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
	movl	$__ZN3dbg5level9container15m_isAlreadyPoolE, 4(%esp)
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
	je	L56
	movl	__ZN3dbg5level9container9m_poolPtrE, %ecx
	movzbl	-28(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZN3dbg5levelaSERKS0_
	movzbl	-28(%ebp), %edx
	leal	-16(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	$__ZN3dbg5level9container15m_isAlreadyPoolE, 4(%esp)
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
L56:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3962:
	.section	.text$_ZN3dbg5level9container5beginEv,"x"
	.linkonce discard
	.globl	__ZN3dbg5level9container5beginEv
	.def	__ZN3dbg5level9container5beginEv;	.scl	2;	.type	32;	.endef
__ZN3dbg5level9container5beginEv:
LFB3963:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	__ZN3dbg5level9container10beginValueEv
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level8iteratorC1Eh
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3963:
	.section	.text$_ZN3dbg5level9container3endEv,"x"
	.linkonce discard
	.globl	__ZN3dbg5level9container3endEv
	.def	__ZN3dbg5level9container3endEv;	.scl	2;	.type	32;	.endef
__ZN3dbg5level9container3endEv:
LFB3964:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	__ZN3dbg5level9container8endValueEv
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level8iteratorC1Eh
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3964:
	.section	.text$_ZNK3dbg5levelgeERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg5levelgeERKS0_
	.def	__ZNK3dbg5levelgeERKS0_;	.scl	2;	.type	32;	.endef
__ZNK3dbg5levelgeERKS0_:
LFB3970:
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
	call	__ZNK3dbg5level13valueAsOutputEv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level13valueAsOutputEv
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
LFE3970:
	.section	.text$_ZN3dbg5levelaSERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg5levelaSERKS0_
	.def	__ZN3dbg5levelaSERKS0_;	.scl	2;	.type	32;	.endef
__ZN3dbg5levelaSERKS0_:
LFB3973:
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
LFE3973:
	.section	.text$_ZNK3dbg5level5valueEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg5level5valueEv
	.def	__ZNK3dbg5level5valueEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg5level5valueEv:
LFB3977:
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
LFE3977:
	.section	.text$_ZNK3dbg5level4nameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg5level4nameEv
	.def	__ZNK3dbg5level4nameEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg5level4nameEv:
LFB3978:
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
LFE3978:
	.section	.text$_ZN3dbg5level17calcValueAsOutputEh,"x"
	.linkonce discard
	.globl	__ZN3dbg5level17calcValueAsOutputEh
	.def	__ZN3dbg5level17calcValueAsOutputEh;	.scl	2;	.type	32;	.endef
__ZN3dbg5level17calcValueAsOutputEh:
LFB3979:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movb	%al, -4(%ebp)
	movzbl	-4(%ebp), %eax
	sarl	%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3979:
	.section	.text$_ZNK3dbg5level13valueAsOutputEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg5level13valueAsOutputEv
	.def	__ZNK3dbg5level13valueAsOutputEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg5level13valueAsOutputEv:
LFB3980:
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
LFE3980:
	.section	.text$_ZNK3dbg5level6forLogEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg5level6forLogEv
	.def	__ZNK3dbg5level6forLogEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg5level6forLogEv:
LFB3981:
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
LFE3981:
	.section	.text$_ZNK3dbg5level9forNoticeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg5level9forNoticeEv
	.def	__ZNK3dbg5level9forNoticeEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg5level9forNoticeEv:
LFB3982:
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
LFE3982:
	.section	.text$_ZNK3dbg5level7forMaskEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg5level7forMaskEv
	.def	__ZNK3dbg5level7forMaskEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg5level7forMaskEv:
LFB3983:
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
LFE3983:
	.section	.text$_ZSt4moveIN3dbg5colorEEONSt16remove_referenceIT_E4typeEOS3_,"x"
	.linkonce discard
	.globl	__ZSt4moveIN3dbg5colorEEONSt16remove_referenceIT_E4typeEOS3_
	.def	__ZSt4moveIN3dbg5colorEEONSt16remove_referenceIT_E4typeEOS3_;	.scl	2;	.type	32;	.endef
__ZSt4moveIN3dbg5colorEEONSt16remove_referenceIT_E4typeEOS3_:
LFB3985:
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
LFE3985:
	.section	.text$_ZNK3dbg5level11changeColorEb,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg5level11changeColorEb
	.def	__ZNK3dbg5level11changeColorEb;	.scl	2;	.type	32;	.endef
__ZNK3dbg5level11changeColorEb:
LFB3987:
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
	call	__ZN3dbg5colorC1ENS0_8target_tENS0_7color_tES2_b
	leal	-14(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIN3dbg5colorEEONSt16remove_referenceIT_E4typeEOS3_
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5colorC1EOS0_
	leal	-14(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5colorD1Ev
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3987:
	.section	.text$_ZNK3dbg5level20changeColorForNoticeEb,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg5level20changeColorForNoticeEb
	.def	__ZNK3dbg5level20changeColorForNoticeEb;	.scl	2;	.type	32;	.endef
__ZNK3dbg5level20changeColorForNoticeEb:
LFB3988:
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
	call	__ZN3dbg5colorC1ENS0_8target_tENS0_7color_tES2_b
	leal	-14(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIN3dbg5colorEEONSt16remove_referenceIT_E4typeEOS3_
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5colorC1EOS0_
	leal	-14(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5colorD1Ev
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3988:
	.section	.text$_ZN3dbg5level3getEh,"x"
	.linkonce discard
	.globl	__ZN3dbg5level3getEh
	.def	__ZN3dbg5level3getEh;	.scl	2;	.type	32;	.endef
__ZN3dbg5level3getEh:
LFB3989:
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
	call	__ZN3dbg5level9container3getEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3989:
	.section	.text$_ZNK3dbg5level4prevEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg5level4prevEv
	.def	__ZNK3dbg5level4prevEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg5level4prevEv:
LFB3990:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level13valueAsOutputEv
	testb	%al, %al
	je	L89
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level13valueAsOutputEv
	cmpb	$5, %al
	ja	L89
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L90
	movl	8(%ebp), %eax
	movzbl	6(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L90
L89:
	movl	$1, %eax
	jmp	L91
L90:
	movl	$0, %eax
L91:
	testb	%al, %al
	je	L92
	movl	__ZN3dbg5level9container9m_poolPtrE, %ecx
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	jmp	L93
L92:
	movl	__ZN3dbg5level9container9m_poolPtrE, %ecx
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
L93:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3990:
	.section	.text$_ZNK3dbg5level4nextEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg5level4nextEv
	.def	__ZNK3dbg5level4nextEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg5level4nextEv:
LFB3991:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level13valueAsOutputEv
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level13valueAsOutputEv
	cmpb	$4, %al
	ja	L95
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L96
	movl	8(%ebp), %eax
	movzbl	6(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L96
L95:
	movl	$1, %eax
	jmp	L97
L96:
	movl	$0, %eax
L97:
	testb	%al, %al
	je	L98
	movl	__ZN3dbg5level9container9m_poolPtrE, %ecx
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	jmp	L99
L98:
	movl	__ZN3dbg5level9container9m_poolPtrE, %ecx
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
L99:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3991:
	.section	.text$_ZN3dbg5levelC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg5levelC1Ev
	.def	__ZN3dbg5levelC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg5levelC1Ev:
LFB3994:
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
	call	__ZN3dbg5level9container14initializeOnceEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3994:
	.section .rdata,"dr"
	.align 4
LC2:
	.ascii "value >= BEGIN && value <= END\0"
LC3:
	.ascii "call_point.cpp\0"
	.section	.text$_ZN3dbg5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	.def	__ZN3dbg5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_;	.scl	2;	.type	32;	.endef
__ZN3dbg5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_:
LFB3999:
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
	jbe	L102
	movl	$LC2, 12(%esp)
	movl	$__ZZN3dbg5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_E19__PRETTY_FUNCTION__, 8(%esp)
	movl	$507, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L102:
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg5level9container3setEhRKS0_
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
LFE3999:
	.section	.text$_ZN3dbg5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_
	.def	__ZN3dbg5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_;	.scl	2;	.type	32;	.endef
__ZN3dbg5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_:
LFB4000:
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
	jbe	L104
	movl	$LC2, 12(%esp)
	movl	$__ZZN3dbg5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_E19__PRETTY_FUNCTION__, 8(%esp)
	movl	$507, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L104:
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg5level9container3setEhRKS0_
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
LFE4000:
	.section	.text$_ZN3dbg5levelC1Eh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg5levelC1Eh
	.def	__ZN3dbg5levelC1Eh;	.scl	2;	.type	32;	.endef
__ZN3dbg5levelC1Eh:
LFB4003:
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
	jbe	L106
	movl	$LC2, 12(%esp)
	movl	$__ZZN3dbg5levelC1EhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$521, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L106:
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level9container3getEh
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelaSERKS0_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4003:
	.section	.text$_ZN3dbg5levelD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg5levelD2Ev
	.def	__ZN3dbg5levelD2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg5levelD2Ev:
LFB4005:
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
LFE4005:
	.section	.text$_ZN3dbg5levelD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg5levelD1Ev
	.def	__ZN3dbg5levelD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg5levelD1Ev:
LFB4006:
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
LFE4006:
	.section .rdata,"dr"
LC4:
	.ascii "(END)\0"
	.section	.text$_ZN3dbg9level_endC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg9level_endC1Ev
	.def	__ZN3dbg9level_endC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg9level_endC1Ev:
LFB4011:
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
	call	__ZN3dbg5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4011:
	.section	.text$_ZN3dbg12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EED2Ev
	.def	__ZN3dbg12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EED2Ev:
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
	call	__ZN3dbg5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4014:
	.section .rdata,"dr"
LC5:
	.ascii "asNormal\0"
	.section	.text$_ZN3dbg14level_asNormalC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg14level_asNormalC1Ev
	.def	__ZN3dbg14level_asNormalC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg14level_asNormalC1Ev:
LFB4017:
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
	call	__ZN3dbg12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4017:
	.section	.text$_ZN3dbg12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev
	.def	__ZN3dbg12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev:
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
	call	__ZN3dbg5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4020:
	.section .rdata,"dr"
LC6:
	.ascii "asVerbose\0"
	.section	.text$_ZN3dbg15level_asVerboseC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg15level_asVerboseC1Ev
	.def	__ZN3dbg15level_asVerboseC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg15level_asVerboseC1Ev:
LFB4023:
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
	call	__ZN3dbg12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4023:
	.section	.text$_ZN3dbg12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev
	.def	__ZN3dbg12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev:
LFB4026:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4026:
	.section .rdata,"dr"
LC7:
	.ascii "asDetail\0"
	.section	.text$_ZN3dbg14level_asDetailC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg14level_asDetailC1Ev
	.def	__ZN3dbg14level_asDetailC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg14level_asDetailC1Ev:
LFB4029:
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
	call	__ZN3dbg12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4029:
	.section	.text$_ZN3dbg12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EED2Ev
	.def	__ZN3dbg12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EED2Ev:
LFB4032:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4032:
	.section .rdata,"dr"
LC8:
	.ascii "asImportant\0"
	.section	.text$_ZN3dbg17level_asImportantC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17level_asImportantC1Ev
	.def	__ZN3dbg17level_asImportantC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17level_asImportantC1Ev:
LFB4035:
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
	call	__ZN3dbg12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4035:
	.section	.text$_ZN3dbg12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EED2Ev
	.def	__ZN3dbg12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EED2Ev:
LFB4038:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4038:
	.section .rdata,"dr"
LC9:
	.ascii "asWarning\0"
	.section	.text$_ZN3dbg15level_asWarningC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg15level_asWarningC1Ev
	.def	__ZN3dbg15level_asWarningC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg15level_asWarningC1Ev:
LFB4041:
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
	call	__ZN3dbg12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4041:
	.section	.text$_ZN3dbg12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EED2Ev
	.def	__ZN3dbg12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EED2Ev:
LFB4044:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4044:
	.section .rdata,"dr"
LC10:
	.ascii "asCritical\0"
	.section	.text$_ZN3dbg16level_asCriticalC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg16level_asCriticalC1Ev
	.def	__ZN3dbg16level_asCriticalC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg16level_asCriticalC1Ev:
LFB4047:
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
	call	__ZN3dbg12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4047:
	.section	.text$_ZN3dbg12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EED2Ev
	.def	__ZN3dbg12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EED2Ev:
LFB4050:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4050:
	.section .rdata,"dr"
LC11:
	.ascii "asAbsolute\0"
	.section	.text$_ZN3dbg16level_asAbsoluteC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg16level_asAbsoluteC1Ev
	.def	__ZN3dbg16level_asAbsoluteC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg16level_asAbsoluteC1Ev:
LFB4053:
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
	call	__ZN3dbg12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4053:
	.section	.text$_ZN3dbg13level_specialILh11EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg13level_specialILh11EED2Ev
	.def	__ZN3dbg13level_specialILh11EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg13level_specialILh11EED2Ev:
LFB4056:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4056:
	.section .rdata,"dr"
LC12:
	.ascii "asSilent\0"
	.section	.text$_ZN3dbg14level_asSilentC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg14level_asSilentC1Ev
	.def	__ZN3dbg14level_asSilentC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg14level_asSilentC1Ev:
LFB4059:
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
	call	__ZN3dbg13level_specialILh11EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4059:
	.section	.text$_ZN3dbg13level_specialILh12EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg13level_specialILh12EED2Ev
	.def	__ZN3dbg13level_specialILh12EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg13level_specialILh12EED2Ev:
LFB4062:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4062:
	.section .rdata,"dr"
LC13:
	.ascii "asSilentAbsolutely\0"
	.section	.text$_ZN3dbg24level_asSilentAbsolutelyC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg24level_asSilentAbsolutelyC1Ev
	.def	__ZN3dbg24level_asSilentAbsolutelyC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg24level_asSilentAbsolutelyC1Ev:
LFB4065:
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
	call	__ZN3dbg13level_specialILh12EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4065:
	.globl	__ZN3dbg5level9container15m_isInitializedE
	.bss
__ZN3dbg5level9container15m_isInitializedE:
	.space 1
	.globl	__ZN3dbg5level9container9m_poolPtrE
	.align 4
__ZN3dbg5level9container9m_poolPtrE:
	.space 4
	.globl	__ZN3dbg5level9container6m_poolE
	.align 32
__ZN3dbg5level9container6m_poolE:
	.space 168
	.globl	__ZN3dbg5level9container15m_isAlreadyPoolE
	.align 4
__ZN3dbg5level9container15m_isAlreadyPoolE:
	.space 4
	.section	.text$_ZN3dbg14level_asNormalD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg14level_asNormalD1Ev
	.def	__ZN3dbg14level_asNormalD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg14level_asNormalD1Ev:
LFB4072:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4072:
	.section	.text$_ZN3dbg15level_asVerboseD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg15level_asVerboseD1Ev
	.def	__ZN3dbg15level_asVerboseD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg15level_asVerboseD1Ev:
LFB4075:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4075:
	.section	.text$_ZN3dbg14level_asDetailD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg14level_asDetailD1Ev
	.def	__ZN3dbg14level_asDetailD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg14level_asDetailD1Ev:
LFB4078:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4078:
	.section	.text$_ZN3dbg17level_asImportantD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17level_asImportantD1Ev
	.def	__ZN3dbg17level_asImportantD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17level_asImportantD1Ev:
LFB4081:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4081:
	.section	.text$_ZN3dbg15level_asWarningD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg15level_asWarningD1Ev
	.def	__ZN3dbg15level_asWarningD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg15level_asWarningD1Ev:
LFB4084:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4084:
	.section	.text$_ZN3dbg16level_asCriticalD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg16level_asCriticalD1Ev
	.def	__ZN3dbg16level_asCriticalD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg16level_asCriticalD1Ev:
LFB4087:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4087:
	.section	.text$_ZN3dbg16level_asAbsoluteD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg16level_asAbsoluteD1Ev
	.def	__ZN3dbg16level_asAbsoluteD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg16level_asAbsoluteD1Ev:
LFB4090:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4090:
	.section	.text$_ZN3dbg14level_asSilentD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg14level_asSilentD1Ev
	.def	__ZN3dbg14level_asSilentD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg14level_asSilentD1Ev:
LFB4093:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg13level_specialILh11EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4093:
	.section	.text$_ZN3dbg24level_asSilentAbsolutelyD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg24level_asSilentAbsolutelyD1Ev
	.def	__ZN3dbg24level_asSilentAbsolutelyD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg24level_asSilentAbsolutelyD1Ev:
LFB4096:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg13level_specialILh12EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4096:
	.section	.text$_ZN3dbg9level_endD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg9level_endD1Ev
	.def	__ZN3dbg9level_endD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg9level_endD1Ev:
LFB4099:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4099:
	.section .rdata,"dr"
LC14:
	.ascii "(undefined)\0"
	.text
	.align 2
	.globl	__ZN3dbg5level9container14initializeOnceEv
	.def	__ZN3dbg5level9container14initializeOnceEv;	.scl	2;	.type	32;	.endef
__ZN3dbg5level9container14initializeOnceEv:
LFB4069:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$200, %esp
	movzbl	__ZN3dbg5level9container15m_isInitializedE, %eax
	testb	%al, %al
	je	L160
	jmp	L159
L160:
	movb	$1, __ZN3dbg5level9container15m_isInitializedE
	movl	$__ZN3dbg5level9container15m_isAlreadyPoolE, (%esp)
	call	__ZNSt6bitsetILj14EE5resetEv
	movl	$168, 8(%esp)
	movl	$0, 4(%esp)
	movl	$__ZN3dbg5level9container6m_poolE, (%esp)
	call	_memset
	movl	$__ZN3dbg5level9container6m_poolE, __ZN3dbg5level9container9m_poolPtrE
	movb	$0, -9(%ebp)
	jmp	L162
L163:
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
	call	__ZN3dbg5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_
	leal	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD1Ev
	movzbl	-9(%ebp), %edx
	leal	-140(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	$__ZN3dbg5level9container15m_isAlreadyPoolE, 4(%esp)
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
L162:
	cmpb	$12, -9(%ebp)
	jbe	L163
	leal	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg14level_asNormalC1Ev
	leal	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg14level_asNormalD1Ev
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg15level_asVerboseC1Ev
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg15level_asVerboseD1Ev
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg14level_asDetailC1Ev
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg14level_asDetailD1Ev
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17level_asImportantC1Ev
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17level_asImportantD1Ev
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg15level_asWarningC1Ev
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg15level_asWarningD1Ev
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg16level_asCriticalC1Ev
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg16level_asCriticalD1Ev
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg16level_asAbsoluteC1Ev
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg16level_asAbsoluteD1Ev
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg14level_asSilentC1Ev
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg14level_asSilentD1Ev
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg24level_asSilentAbsolutelyC1Ev
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg24level_asSilentAbsolutelyD1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg9level_endC1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg9level_endD1Ev
L159:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4069:
.lcomm __ZN3dbgL20s_levelForInitializeE,12,4
	.section .rdata,"dr"
	.align 4
LC15:
	.ascii "level=%d, name=\"%s\", valueAsOutput=%d, forLog=%d, forNotice=%d, forMask=%d\12\0"
LC16:
	.ascii "           prev=%s(%d)\12\0"
LC17:
	.ascii "           next=%s(%d)\12\0"
	.text
	.globl	__ZN3dbg13printLevelAllEv
	.def	__ZN3dbg13printLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN3dbg13printLevelAllEv:
LFB4100:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4100
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
	call	__ZN3dbg5level9container5beginEv
	subl	$4, %esp
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level9container3endEv
	subl	$4, %esp
	jmp	L165
L166:
	leal	-43(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level8iteratordeEv
	movl	%eax, -32(%ebp)
	leal	-50(%ebp), %eax
	movl	$0, 8(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB0:
	call	__ZNK3dbg5level11changeColorEb
LEHE0:
	subl	$4, %esp
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level7forMaskEv
	movzbl	%al, %eax
	movl	%eax, -60(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level9forNoticeEv
	movzbl	%al, %eax
	movl	%eax, -64(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level6forLogEv
	movzbl	%al, %eax
	movl	%eax, -68(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level13valueAsOutputEv
	movzbl	%al, %edi
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level4nameEv
	movl	%eax, %ebx
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level5valueEv
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
	call	__ZNK3dbg5level4prevEv
	movl	%eax, -36(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level4nextEv
	movl	%eax, -40(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level5valueEv
	movzbl	%al, %esi
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level4nameEv
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
	call	__ZNK3dbg5level5valueEv
	movzbl	%al, %esi
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level4nameEv
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
	call	__ZN3dbg5colorD1Ev
	leal	-43(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level8iteratorppEv
L165:
	movzbl	-44(%ebp), %eax
	movb	%al, -41(%ebp)
	leal	-41(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-43(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level8iteratorneES1_
	movl	%eax, %ebx
	leal	-41(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level8iteratorD1Ev
	testb	%bl, %bl
	jne	L166
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level8iteratorD1Ev
	leal	-43(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level8iteratorD1Ev
	jmp	L171
L170:
	movl	%eax, %ebx
	leal	-50(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5colorD1Ev
	movl	%ebx, %eax
	jmp	L168
L169:
L168:
	movl	%eax, %ebx
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level8iteratorD1Ev
	leal	-43(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level8iteratorD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB2:
	call	__Unwind_Resume
LEHE2:
L171:
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
LFE4100:
	.section	.gcc_except_table,"w"
LLSDA4100:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4100-LLSDACSB4100
LLSDACSB4100:
	.uleb128 LEHB0-LFB4100
	.uleb128 LEHE0-LEHB0
	.uleb128 L169-LFB4100
	.uleb128 0
	.uleb128 LEHB1-LFB4100
	.uleb128 LEHE1-LEHB1
	.uleb128 L170-LFB4100
	.uleb128 0
	.uleb128 LEHB2-LFB4100
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
LLSDACSE4100:
	.text
	.section	.text$_ZNK3dbg8category8iteratordeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg8category8iteratordeEv
	.def	__ZNK3dbg8category8iteratordeEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg8category8iteratordeEv:
LFB4102:
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
	call	__ZN3dbg8category9container3getEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4102:
	.section	.text$_ZNK3dbg8category8iteratorneES1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg8category8iteratorneES1_
	.def	__ZNK3dbg8category8iteratorneES1_;	.scl	2;	.type	32;	.endef
__ZNK3dbg8category8iteratorneES1_:
LFB4104:
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
LFE4104:
	.section	.text$_ZNK3dbg8category8iteratorppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg8category8iteratorppEv
	.def	__ZNK3dbg8category8iteratorppEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg8category8iteratorppEv:
LFB4105:
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
	call	__ZN3dbg8category9container8endValueEv
	cmpb	%al, %bl
	jb	L177
	call	__ZN3dbg8category9container6getEndEv
	jmp	L178
L177:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, (%eax)
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category9container3getEh
L178:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4105:
	.section	.text$_ZNSt8iteratorISt26bidirectional_iterator_tagN3dbg8categoryEiPS2_RS2_EC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8iteratorISt26bidirectional_iterator_tagN3dbg8categoryEiPS2_RS2_EC2Ev
	.def	__ZNSt8iteratorISt26bidirectional_iterator_tagN3dbg8categoryEiPS2_RS2_EC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt8iteratorISt26bidirectional_iterator_tagN3dbg8categoryEiPS2_RS2_EC2Ev:
LFB4112:
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
LFE4112:
	.section	.text$_ZN3dbg8category8iteratorC1Eh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg8category8iteratorC1Eh
	.def	__ZN3dbg8category8iteratorC1Eh;	.scl	2;	.type	32;	.endef
__ZN3dbg8category8iteratorC1Eh:
LFB4115:
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
	call	__ZNSt8iteratorISt26bidirectional_iterator_tagN3dbg8categoryEiPS2_RS2_EC2Ev
	movl	8(%ebp), %eax
	movzbl	-4(%ebp), %edx
	movb	%dl, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4115:
	.section	.text$_ZN3dbg8category8iteratorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg8category8iteratorD1Ev
	.def	__ZN3dbg8category8iteratorD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg8category8iteratorD1Ev:
LFB4130:
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
LFE4130:
	.section	.text$_ZN3dbg8category9container10beginValueEv,"x"
	.linkonce discard
	.globl	__ZN3dbg8category9container10beginValueEv
	.def	__ZN3dbg8category9container10beginValueEv;	.scl	2;	.type	32;	.endef
__ZN3dbg8category9container10beginValueEv:
LFB4131:
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
LFE4131:
	.section	.text$_ZN3dbg8category9container8endValueEv,"x"
	.linkonce discard
	.globl	__ZN3dbg8category9container8endValueEv
	.def	__ZN3dbg8category9container8endValueEv;	.scl	2;	.type	32;	.endef
__ZN3dbg8category9container8endValueEv:
LFB4132:
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
LFE4132:
	.section	.text$_ZN3dbg8category9container3getEh,"x"
	.linkonce discard
	.globl	__ZN3dbg8category9container3getEh
	.def	__ZN3dbg8category9container3getEh;	.scl	2;	.type	32;	.endef
__ZN3dbg8category9container3getEh:
LFB4133:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movb	%al, -4(%ebp)
	movl	__ZN3dbg8category9container9m_poolPtrE, %ecx
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
LFE4133:
	.section	.text$_ZN3dbg8category9container6getEndEv,"x"
	.linkonce discard
	.globl	__ZN3dbg8category9container6getEndEv
	.def	__ZN3dbg8category9container6getEndEv;	.scl	2;	.type	32;	.endef
__ZN3dbg8category9container6getEndEv:
LFB4135:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	.cfi_offset 3, -12
	movl	__ZN3dbg8category9container9m_poolPtrE, %ebx
	call	__ZN3dbg8category9container8endValueEv
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
LFE4135:
	.section	.text$_ZN3dbg8category9container3setEhRKS0_,"x"
	.linkonce discard
	.globl	__ZN3dbg8category9container3setEhRKS0_
	.def	__ZN3dbg8category9container3setEhRKS0_;	.scl	2;	.type	32;	.endef
__ZN3dbg8category9container3setEhRKS0_:
LFB4136:
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
	movl	$__ZN3dbg8category9container15m_isAlreadyPoolE, 4(%esp)
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
	je	L192
	movl	__ZN3dbg8category9container9m_poolPtrE, %ecx
	movzbl	-28(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZN3dbg8categoryaSERKS0_
	movzbl	-28(%ebp), %edx
	leal	-16(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	$__ZN3dbg8category9container15m_isAlreadyPoolE, 4(%esp)
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
L192:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4136:
	.section	.text$_ZN3dbg8category9container5beginEv,"x"
	.linkonce discard
	.globl	__ZN3dbg8category9container5beginEv
	.def	__ZN3dbg8category9container5beginEv;	.scl	2;	.type	32;	.endef
__ZN3dbg8category9container5beginEv:
LFB4137:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	__ZN3dbg8category9container10beginValueEv
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category8iteratorC1Eh
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE4137:
	.section	.text$_ZN3dbg8category9container3endEv,"x"
	.linkonce discard
	.globl	__ZN3dbg8category9container3endEv
	.def	__ZN3dbg8category9container3endEv;	.scl	2;	.type	32;	.endef
__ZN3dbg8category9container3endEv:
LFB4138:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	__ZN3dbg8category9container8endValueEv
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category8iteratorC1Eh
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE4138:
	.section	.text$_ZN3dbg8categoryaSERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg8categoryaSERKS0_
	.def	__ZN3dbg8categoryaSERKS0_;	.scl	2;	.type	32;	.endef
__ZN3dbg8categoryaSERKS0_:
LFB4143:
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
LFE4143:
	.section	.text$_ZNK3dbg8category5valueEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg8category5valueEv
	.def	__ZNK3dbg8category5valueEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg8category5valueEv:
LFB4147:
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
LFE4147:
	.section	.text$_ZNK3dbg8category4nameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg8category4nameEv
	.def	__ZNK3dbg8category4nameEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg8category4nameEv:
LFB4148:
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
LFE4148:
	.section	.text$_ZNK3dbg8category10isAssignedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg8category10isAssignedEv
	.def	__ZNK3dbg8category10isAssignedEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg8category10isAssignedEv:
LFB4149:
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
LFE4149:
	.section	.text$_ZNK3dbg8category10isReservedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg8category10isReservedEv
	.def	__ZNK3dbg8category10isReservedEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg8category10isReservedEv:
LFB4150:
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
LFE4150:
	.section	.text$_ZNK3dbg8category6forLogEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg8category6forLogEv
	.def	__ZNK3dbg8category6forLogEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg8category6forLogEv:
LFB4151:
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
LFE4151:
	.section	.text$_ZNK3dbg8category9forNoticeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg8category9forNoticeEv
	.def	__ZNK3dbg8category9forNoticeEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg8category9forNoticeEv:
LFB4152:
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
LFE4152:
	.section	.text$_ZNK3dbg8category7forMaskEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg8category7forMaskEv
	.def	__ZNK3dbg8category7forMaskEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg8category7forMaskEv:
LFB4153:
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
LFE4153:
	.section	.text$_ZN3dbg8category3getEh,"x"
	.linkonce discard
	.globl	__ZN3dbg8category3getEh
	.def	__ZN3dbg8category3getEh;	.scl	2;	.type	32;	.endef
__ZN3dbg8category3getEh:
LFB4154:
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
	call	__ZN3dbg8category9container3getEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4154:
	.section	.text$_ZN3dbg8categoryC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg8categoryC1Ev
	.def	__ZN3dbg8categoryC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg8categoryC1Ev:
LFB4157:
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
	call	__ZN3dbg8category9container14initializeOnceEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4157:
	.section	.text$_ZN3dbg8categoryC2EhPKcbbbb,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg8categoryC2EhPKcbbbb
	.def	__ZN3dbg8categoryC2EhPKcbbbb;	.scl	2;	.type	32;	.endef
__ZN3dbg8categoryC2EhPKcbbbb:
LFB4162:
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
	jbe	L218
	movl	$LC2, 12(%esp)
	movl	$__ZZN3dbg8categoryC1EhPKcbbbbE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$863, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L218:
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg8category9container3setEhRKS0_
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
LFE4162:
	.section	.text$_ZN3dbg8categoryC1EhPKcbbbb,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg8categoryC1EhPKcbbbb
	.def	__ZN3dbg8categoryC1EhPKcbbbb;	.scl	2;	.type	32;	.endef
__ZN3dbg8categoryC1EhPKcbbbb:
LFB4163:
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
	jbe	L220
	movl	$LC2, 12(%esp)
	movl	$__ZZN3dbg8categoryC1EhPKcbbbbE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$863, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L220:
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg8category9container3setEhRKS0_
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
LFE4163:
	.section	.text$_ZN3dbg8categoryD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg8categoryD2Ev
	.def	__ZN3dbg8categoryD2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg8categoryD2Ev:
LFB4168:
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
LFE4168:
	.section	.text$_ZN3dbg8categoryD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg8categoryD1Ev
	.def	__ZN3dbg8categoryD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg8categoryD1Ev:
LFB4169:
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
LFE4169:
	.section	.text$_ZN3dbg12category_endC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12category_endC1Ev
	.def	__ZN3dbg12category_endC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg12category_endC1Ev:
LFB4175:
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
	call	__ZN3dbg8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4175:
	.section	.text$_ZN3dbg17category_assignedILh0ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh0ELb1ELb1EED2Ev
	.def	__ZN3dbg17category_assignedILh0ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh0ELb1ELb1EED2Ev:
LFB4178:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4178:
	.section .rdata,"dr"
LC18:
	.ascii "forAny\0"
	.section	.text$_ZN3dbg15category_forAnyC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg15category_forAnyC1Ev
	.def	__ZN3dbg15category_forAnyC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg15category_forAnyC1Ev:
LFB4181:
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
	call	__ZN3dbg17category_assignedILh0ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4181:
	.section	.text$_ZN3dbg17category_assignedILh1ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh1ELb1ELb1EED2Ev
	.def	__ZN3dbg17category_assignedILh1ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh1ELb1ELb1EED2Ev:
LFB4184:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4184:
	.section .rdata,"dr"
LC19:
	.ascii "forLogic\0"
	.section	.text$_ZN3dbg17category_forLogicC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_forLogicC1Ev
	.def	__ZN3dbg17category_forLogicC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_forLogicC1Ev:
LFB4187:
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
	call	__ZN3dbg17category_assignedILh1ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4187:
	.section	.text$_ZN3dbg17category_assignedILh2ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh2ELb1ELb1EED2Ev
	.def	__ZN3dbg17category_assignedILh2ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh2ELb1ELb1EED2Ev:
LFB4190:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4190:
	.section .rdata,"dr"
LC20:
	.ascii "forResource\0"
	.section	.text$_ZN3dbg20category_forResourceC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg20category_forResourceC1Ev
	.def	__ZN3dbg20category_forResourceC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg20category_forResourceC1Ev:
LFB4193:
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
	call	__ZN3dbg17category_assignedILh2ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4193:
	.section	.text$_ZN3dbg17category_assignedILh3ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh3ELb1ELb1EED2Ev
	.def	__ZN3dbg17category_assignedILh3ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh3ELb1ELb1EED2Ev:
LFB4196:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4196:
	.section .rdata,"dr"
LC21:
	.ascii "for3D\0"
	.section	.text$_ZN3dbg14category_for3DC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg14category_for3DC1Ev
	.def	__ZN3dbg14category_for3DC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg14category_for3DC1Ev:
LFB4199:
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
	call	__ZN3dbg17category_assignedILh3ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4199:
	.section	.text$_ZN3dbg17category_assignedILh4ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh4ELb1ELb1EED2Ev
	.def	__ZN3dbg17category_assignedILh4ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh4ELb1ELb1EED2Ev:
LFB4202:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4202:
	.section .rdata,"dr"
LC22:
	.ascii "for2D\0"
	.section	.text$_ZN3dbg14category_for2DC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg14category_for2DC1Ev
	.def	__ZN3dbg14category_for2DC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg14category_for2DC1Ev:
LFB4205:
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
	call	__ZN3dbg17category_assignedILh4ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4205:
	.section	.text$_ZN3dbg17category_assignedILh5ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh5ELb1ELb1EED2Ev
	.def	__ZN3dbg17category_assignedILh5ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh5ELb1ELb1EED2Ev:
LFB4208:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4208:
	.section .rdata,"dr"
LC23:
	.ascii "forSound\0"
	.section	.text$_ZN3dbg17category_forSoundC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_forSoundC1Ev
	.def	__ZN3dbg17category_forSoundC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_forSoundC1Ev:
LFB4211:
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
	call	__ZN3dbg17category_assignedILh5ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4211:
	.section	.text$_ZN3dbg17category_assignedILh6ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh6ELb1ELb1EED2Ev
	.def	__ZN3dbg17category_assignedILh6ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh6ELb1ELb1EED2Ev:
LFB4214:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4214:
	.section .rdata,"dr"
LC24:
	.ascii "forScript\0"
	.section	.text$_ZN3dbg18category_forScriptC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg18category_forScriptC1Ev
	.def	__ZN3dbg18category_forScriptC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg18category_forScriptC1Ev:
LFB4217:
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
	call	__ZN3dbg17category_assignedILh6ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4217:
	.section	.text$_ZN3dbg17category_assignedILh7ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh7ELb1ELb1EED2Ev
	.def	__ZN3dbg17category_assignedILh7ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh7ELb1ELb1EED2Ev:
LFB4220:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4220:
	.section .rdata,"dr"
LC25:
	.ascii "forGameData\0"
	.section	.text$_ZN3dbg20category_forGameDataC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg20category_forGameDataC1Ev
	.def	__ZN3dbg20category_forGameDataC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg20category_forGameDataC1Ev:
LFB4223:
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
	call	__ZN3dbg17category_assignedILh7ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4223:
	.section	.text$_ZN3dbg16category_specialILh64ELb0ELb0ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg16category_specialILh64ELb0ELb0ELb1EED2Ev
	.def	__ZN3dbg16category_specialILh64ELb0ELb0ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg16category_specialILh64ELb0ELb0ELb1EED2Ev:
LFB4226:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4226:
	.section .rdata,"dr"
LC26:
	.ascii "forEvery\0"
	.section	.text$_ZN3dbg17category_forEveryC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_forEveryC1Ev
	.def	__ZN3dbg17category_forEveryC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_forEveryC1Ev:
LFB4229:
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
	call	__ZN3dbg16category_specialILh64ELb0ELb0ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4229:
	.section	.text$_ZN3dbg16category_specialILh65ELb1ELb1ELb0EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg16category_specialILh65ELb1ELb1ELb0EED2Ev
	.def	__ZN3dbg16category_specialILh65ELb1ELb1ELb0EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg16category_specialILh65ELb1ELb1ELb0EED2Ev:
LFB4232:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4232:
	.section .rdata,"dr"
LC27:
	.ascii "forCallPoint\0"
	.section	.text$_ZN3dbg21category_forCallPointC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg21category_forCallPointC1Ev
	.def	__ZN3dbg21category_forCallPointC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg21category_forCallPointC1Ev:
LFB4235:
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
	call	__ZN3dbg16category_specialILh65ELb1ELb1ELb0EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4235:
	.section	.text$_ZN3dbg16category_specialILh66ELb1ELb1ELb0EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg16category_specialILh66ELb1ELb1ELb0EED2Ev
	.def	__ZN3dbg16category_specialILh66ELb1ELb1ELb0EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg16category_specialILh66ELb1ELb1ELb0EED2Ev:
LFB4238:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4238:
	.section .rdata,"dr"
LC28:
	.ascii "forCriticalCallPoint\0"
	.section	.text$_ZN3dbg29category_forCriticalCallPointC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg29category_forCriticalCallPointC1Ev
	.def	__ZN3dbg29category_forCriticalCallPointC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg29category_forCriticalCallPointC1Ev:
LFB4241:
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
	call	__ZN3dbg16category_specialILh66ELb1ELb1ELb0EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4241:
	.globl	__ZN3dbg8category9container15m_isInitializedE
	.bss
__ZN3dbg8category9container15m_isInitializedE:
	.space 1
	.globl	__ZN3dbg8category9container9m_poolPtrE
	.align 4
__ZN3dbg8category9container9m_poolPtrE:
	.space 4
	.globl	__ZN3dbg8category9container6m_poolE
	.align 32
__ZN3dbg8category9container6m_poolE:
	.space 816
	.globl	__ZN3dbg8category9container15m_isAlreadyPoolE
	.align 4
__ZN3dbg8category9container15m_isAlreadyPoolE:
	.space 12
	.section	.text$_ZN3dbg15category_forAnyD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg15category_forAnyD1Ev
	.def	__ZN3dbg15category_forAnyD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg15category_forAnyD1Ev:
LFB4251:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_assignedILh0ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4251:
	.section	.text$_ZN3dbg17category_forLogicD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_forLogicD1Ev
	.def	__ZN3dbg17category_forLogicD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_forLogicD1Ev:
LFB4254:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_assignedILh1ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4254:
	.section	.text$_ZN3dbg20category_forResourceD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg20category_forResourceD1Ev
	.def	__ZN3dbg20category_forResourceD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg20category_forResourceD1Ev:
LFB4257:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_assignedILh2ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4257:
	.section	.text$_ZN3dbg14category_for3DD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg14category_for3DD1Ev
	.def	__ZN3dbg14category_for3DD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg14category_for3DD1Ev:
LFB4260:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_assignedILh3ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4260:
	.section	.text$_ZN3dbg14category_for2DD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg14category_for2DD1Ev
	.def	__ZN3dbg14category_for2DD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg14category_for2DD1Ev:
LFB4263:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_assignedILh4ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4263:
	.section	.text$_ZN3dbg17category_forSoundD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_forSoundD1Ev
	.def	__ZN3dbg17category_forSoundD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_forSoundD1Ev:
LFB4266:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_assignedILh5ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4266:
	.section	.text$_ZN3dbg18category_forScriptD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg18category_forScriptD1Ev
	.def	__ZN3dbg18category_forScriptD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg18category_forScriptD1Ev:
LFB4269:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_assignedILh6ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4269:
	.section	.text$_ZN3dbg20category_forGameDataD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg20category_forGameDataD1Ev
	.def	__ZN3dbg20category_forGameDataD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg20category_forGameDataD1Ev:
LFB4272:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_assignedILh7ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4272:
	.section	.text$_ZN3dbg17category_forEveryD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_forEveryD1Ev
	.def	__ZN3dbg17category_forEveryD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_forEveryD1Ev:
LFB4275:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg16category_specialILh64ELb0ELb0ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4275:
	.section	.text$_ZN3dbg21category_forCallPointD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg21category_forCallPointD1Ev
	.def	__ZN3dbg21category_forCallPointD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg21category_forCallPointD1Ev:
LFB4278:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg16category_specialILh65ELb1ELb1ELb0EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4278:
	.section	.text$_ZN3dbg29category_forCriticalCallPointD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg29category_forCriticalCallPointD1Ev
	.def	__ZN3dbg29category_forCriticalCallPointD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg29category_forCriticalCallPointD1Ev:
LFB4281:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg16category_specialILh66ELb1ELb1ELb0EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4281:
	.section	.text$_ZN3dbg12category_endD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12category_endD1Ev
	.def	__ZN3dbg12category_endD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg12category_endD1Ev:
LFB4284:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4284:
	.text
	.align 2
	.globl	__ZN3dbg8category9container14initializeOnceEv
	.def	__ZN3dbg8category9container14initializeOnceEv;	.scl	2;	.type	32;	.endef
__ZN3dbg8category9container14initializeOnceEv:
LFB4248:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$216, %esp
	movzbl	__ZN3dbg8category9container15m_isInitializedE, %eax
	testb	%al, %al
	je	L284
	jmp	L283
L284:
	movb	$1, __ZN3dbg8category9container15m_isInitializedE
	movl	$__ZN3dbg8category9container15m_isAlreadyPoolE, (%esp)
	call	__ZNSt6bitsetILj68EE5resetEv
	movl	$816, 8(%esp)
	movl	$0, 4(%esp)
	movl	$__ZN3dbg8category9container6m_poolE, (%esp)
	call	_memset
	movl	$__ZN3dbg8category9container6m_poolE, __ZN3dbg8category9container9m_poolPtrE
	movb	$0, -9(%ebp)
	jmp	L286
L287:
	movzbl	-9(%ebp), %eax
	movl	$0, 24(%esp)
	movl	$0, 20(%esp)
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	$LC14, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryC1EhPKcbbbb
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD1Ev
	movzbl	-9(%ebp), %edx
	leal	-164(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	$__ZN3dbg8category9container15m_isAlreadyPoolE, 4(%esp)
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
L286:
	cmpb	$66, -9(%ebp)
	jbe	L287
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg15category_forAnyC1Ev
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg15category_forAnyD1Ev
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_forLogicC1Ev
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_forLogicD1Ev
	leal	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg20category_forResourceC1Ev
	leal	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg20category_forResourceD1Ev
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg14category_for3DC1Ev
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg14category_for3DD1Ev
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg14category_for2DC1Ev
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg14category_for2DD1Ev
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_forSoundC1Ev
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_forSoundD1Ev
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg18category_forScriptC1Ev
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg18category_forScriptD1Ev
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg20category_forGameDataC1Ev
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg20category_forGameDataD1Ev
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_forEveryC1Ev
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_forEveryD1Ev
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg21category_forCallPointC1Ev
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg21category_forCallPointD1Ev
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg29category_forCriticalCallPointC1Ev
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg29category_forCriticalCallPointD1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg12category_endC1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg12category_endD1Ev
L283:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4248:
.lcomm __ZN3dbgL23s_categoryForInitializeE,12,4
	.section .rdata,"dr"
	.align 4
LC29:
	.ascii "category=%d, name=\"%s\", isAssigned=%d, isReserved=%d, forLog=%d, forNotice=%d, forMask=%d\12\0"
	.text
	.globl	__ZN3dbg16printCategoryAllEv
	.def	__ZN3dbg16printCategoryAllEv;	.scl	2;	.type	32;	.endef
__ZN3dbg16printCategoryAllEv:
LFB4285:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4285
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
	call	__ZN3dbg8category9container5beginEv
	subl	$4, %esp
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category9container3endEv
	subl	$4, %esp
	jmp	L289
L290:
	leal	-35(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category8iteratordeEv
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category7forMaskEv
	movzbl	%al, %eax
	movl	%eax, -44(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category9forNoticeEv
	movzbl	%al, %ecx
	movl	%ecx, -48(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category6forLogEv
	movzbl	%al, %esi
	movl	%esi, -52(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category10isReservedEv
	movzbl	%al, %edi
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category10isAssignedEv
	movzbl	%al, %esi
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category4nameEv
	movl	%eax, %ebx
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category5valueEv
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
	call	__ZNK3dbg8category8iteratorppEv
L289:
	movzbl	-36(%ebp), %eax
	movb	%al, -33(%ebp)
	leal	-33(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-35(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category8iteratorneES1_
	movl	%eax, %ebx
	leal	-33(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category8iteratorD1Ev
	testb	%bl, %bl
	jne	L290
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category8iteratorD1Ev
	leal	-35(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category8iteratorD1Ev
	jmp	L293
L292:
	movl	%eax, %ebx
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category8iteratorD1Ev
	leal	-35(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category8iteratorD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB4:
	call	__Unwind_Resume
LEHE4:
L293:
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
LFE4285:
	.section	.gcc_except_table,"w"
LLSDA4285:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4285-LLSDACSB4285
LLSDACSB4285:
	.uleb128 LEHB3-LFB4285
	.uleb128 LEHE3-LEHB3
	.uleb128 L292-LFB4285
	.uleb128 0
	.uleb128 LEHB4-LFB4285
	.uleb128 LEHE4-LEHB4
	.uleb128 0
	.uleb128 0
LLSDACSE4285:
	.text
	.section	.text$_ZNK3dbg7message8getLevelEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg7message8getLevelEv
	.def	__ZNK3dbg7message8getLevelEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg7message8getLevelEv:
LFB4286:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4286:
	.section	.text$_ZNK3dbg7message11getCategoryEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg7message11getCategoryEv
	.def	__ZNK3dbg7message11getCategoryEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg7message11getCategoryEv:
LFB4287:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	1(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4287:
	.section	.text$_ZNK3dbg7message7getNameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg7message7getNameEv
	.def	__ZNK3dbg7message7getNameEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg7message7getNameEv:
LFB4288:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4288:
	.section	.text$_ZNK3dbg7message14getSrcFileNameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg7message14getSrcFileNameEv
	.def	__ZNK3dbg7message14getSrcFileNameEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg7message14getSrcFileNameEv:
LFB4289:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__Z11getFileNamePKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4289:
	.section	.text$_ZNK3dbg7message11getFuncNameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg7message11getFuncNameEv
	.def	__ZNK3dbg7message11getFuncNameEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg7message11getFuncNameEv:
LFB4290:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4290:
	.section	.text$_ZNK3dbg7message18logLevelHasChangedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg7message18logLevelHasChangedEv
	.def	__ZNK3dbg7message18logLevelHasChangedEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg7message18logLevelHasChangedEv:
LFB4291:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	20(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4291:
	.section	.text$_ZNK3dbg7message21noticeLevelHasChangedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg7message21noticeLevelHasChangedEv
	.def	__ZNK3dbg7message21noticeLevelHasChangedEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg7message21noticeLevelHasChangedEv:
LFB4292:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	21(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4292:
	.section	.text$_ZN3dbg7message20adjustProperCategoryEh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message20adjustProperCategoryEh
	.def	__ZN3dbg7message20adjustProperCategoryEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message20adjustProperCategoryEh:
LFB4293:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	cmpb	$65, -28(%ebp)
	jne	L309
	call	__ZN3dbg7message16getLastCallPointEv
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	L310
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message11getCategoryEv
	jmp	L311
L310:
	movl	$0, %eax
	jmp	L311
L309:
	cmpb	$66, -28(%ebp)
	jne	L312
	call	__ZN3dbg7message24getLastCriticalCallPointEv
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	je	L313
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message11getCategoryEv
	jmp	L311
L313:
	movl	$0, %eax
	jmp	L311
L312:
	movzbl	-28(%ebp), %eax
L311:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4293:
	.section	.text$_ZN3dbg7message12copyLogLevelEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message12copyLogLevelEv
	.def	__ZN3dbg7message12copyLogLevelEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message12copyLogLevelEv:
LFB4294:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movzbl	20(%eax), %eax
	testb	%al, %al
	je	L315
	jmp	L314
L315:
	movl	8(%ebp), %eax
	movb	$1, 20(%eax)
	call	__ZN3dbg7message38getLastCallPointWithLogLevelHasChangedEv
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	L317
	movl	-12(%ebp), %eax
	leal	22(%eax), %edx
	movl	8(%ebp), %eax
	addl	$22, %eax
	movl	$64, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_memcpy
	jmp	L314
L317:
	movl	8(%ebp), %eax
	movl	__ZN3dbg7message11m_logLevelGE, %edx
	movl	%edx, 22(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+4, %edx
	movl	%edx, 26(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+8, %edx
	movl	%edx, 30(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+12, %edx
	movl	%edx, 34(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+16, %edx
	movl	%edx, 38(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+20, %edx
	movl	%edx, 42(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+24, %edx
	movl	%edx, 46(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+28, %edx
	movl	%edx, 50(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+32, %edx
	movl	%edx, 54(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+36, %edx
	movl	%edx, 58(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+40, %edx
	movl	%edx, 62(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+44, %edx
	movl	%edx, 66(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+48, %edx
	movl	%edx, 70(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+52, %edx
	movl	%edx, 74(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+56, %edx
	movl	%edx, 78(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+60, %edx
	movl	%edx, 82(%eax)
L314:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4294:
	.section .rdata,"dr"
LC30:
	.ascii "o_category.forMask() == true\0"
LC31:
	.ascii "o_category.forLog() == true\0"
	.section	.text$_ZN3dbg7message12getLogLevelGEh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message12getLogLevelGEh
	.def	__ZN3dbg7message12getLogLevelGEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message12getLogLevelGEh:
LFB4295:
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
	call	__ZN3dbg8category3getEh
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category7forMaskEv
	testb	%al, %al
	jne	L319
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message12getLogLevelGEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1119, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L319:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category6forLogEv
	testb	%al, %al
	jne	L320
	movl	$LC31, 12(%esp)
	movl	$__ZZN3dbg7message12getLogLevelGEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1120, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L320:
	movzbl	-28(%ebp), %eax
	movzbl	__ZN3dbg7message11m_logLevelGE(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4295:
	.section	.text$_ZN3dbg7message15getLogLevelG_CPEh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message15getLogLevelG_CPEh
	.def	__ZN3dbg7message15getLogLevelG_CPEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message15getLogLevelG_CPEh:
LFB4296:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	call	__ZN3dbg7message38getLastCallPointWithLogLevelHasChangedEv
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L323
	movzbl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message12getLogLevelGEh
	jmp	L324
L323:
	movzbl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message11getLogLevelEh
L324:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4296:
	.section	.text$_ZN3dbg7message19isValidTempLogLevelEh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message19isValidTempLogLevelEh
	.def	__ZN3dbg7message19isValidTempLogLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message19isValidTempLogLevelEh:
LFB4297:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movb	%al, -28(%ebp)
	movzbl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category3getEh
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category7forMaskEv
	testb	%al, %al
	jne	L326
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message19isValidTempLogLevelEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1136, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L326:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category6forLogEv
	testb	%al, %al
	jne	L327
	movl	$LC31, 12(%esp)
	movl	$__ZZN3dbg7message19isValidTempLogLevelEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1137, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L327:
	movl	8(%ebp), %eax
	movzbl	20(%eax), %eax
	testb	%al, %al
	je	L328
	movzbl	-28(%ebp), %eax
	movzbl	__ZN3dbg7message11m_logLevelGE(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	movl	%eax, %ebx
	movzbl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movzbl	22(%edx,%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	cmpb	%al, %bl
	ja	L328
	movl	$1, %eax
	jmp	L329
L328:
	movl	$0, %eax
L329:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4297:
	.section	.text$_ZN3dbg7message11getLogLevelEh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message11getLogLevelEh
	.def	__ZN3dbg7message11getLogLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message11getLogLevelEh:
LFB4298:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message19isValidTempLogLevelEh
	testb	%al, %al
	je	L332
	movzbl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movzbl	22(%edx,%eax), %eax
	jmp	L333
L332:
	movzbl	-12(%ebp), %eax
	movzbl	__ZN3dbg7message11m_logLevelGE(%eax), %eax
L333:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4298:
	.section	.text$_ZN3dbg7message14getLogLevel_CPEh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message14getLogLevel_CPEh
	.def	__ZN3dbg7message14getLogLevel_CPEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message14getLogLevel_CPEh:
LFB4299:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message19isValidTempLogLevelEh
	testb	%al, %al
	je	L336
	movzbl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movzbl	22(%edx,%eax), %eax
	jmp	L337
L336:
	movzbl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message15getLogLevelG_CPEh
L337:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4299:
	.section .rdata,"dr"
LC32:
	.ascii "o_level.forMask() == true\0"
	.section	.text$_ZN3dbg7message12setLogLevelGEhh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message12setLogLevelGEhh
	.def	__ZN3dbg7message12setLogLevelGEhh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message12setLogLevelGEhh:
LFB4300:
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
	movzbl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level3getEh
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level7forMaskEv
	testb	%al, %al
	jne	L340
	movl	$LC32, 12(%esp)
	movl	$__ZZN3dbg7message12setLogLevelGEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1156, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L340:
	movzbl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category3getEh
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category7forMaskEv
	testb	%al, %al
	jne	L341
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message12setLogLevelGEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1158, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L341:
	cmpb	$64, -48(%ebp)
	jne	L342
	movzbl	__ZN3dbg7message11m_logLevelGE, %eax
	movb	%al, -21(%ebp)
	movl	$__ZN3dbg7message11m_logLevelGE, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-28(%ebp), %eax
	addl	$64, %eax
	movl	%eax, -32(%ebp)
	jmp	L343
L344:
	movl	-12(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movzbl	-44(%ebp), %edx
	movb	%dl, (%eax)
	addl	$1, -12(%ebp)
L343:
	movl	-12(%ebp), %eax
	cmpl	-32(%ebp), %eax
	jne	L344
	movzbl	-21(%ebp), %eax
	jmp	L345
L342:
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category6forLogEv
	testb	%al, %al
	jne	L346
	movl	$LC31, 12(%esp)
	movl	$__ZZN3dbg7message12setLogLevelGEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1166, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L346:
	movzbl	-48(%ebp), %eax
	movzbl	__ZN3dbg7message11m_logLevelGE(%eax), %eax
	movb	%al, -37(%ebp)
	movzbl	-48(%ebp), %eax
	movzbl	-44(%ebp), %edx
	movb	%dl, __ZN3dbg7message11m_logLevelGE(%eax)
	movzbl	-37(%ebp), %eax
L345:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4300:
	.section	.text$_ZN3dbg7message11setLogLevelEhh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message11setLogLevelEhh
	.def	__ZN3dbg7message11setLogLevelEhh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message11setLogLevelEhh:
LFB4301:
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
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	movb	%dl, -28(%ebp)
	movb	%al, -32(%ebp)
	movzbl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level3getEh
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level7forMaskEv
	testb	%al, %al
	jne	L348
	movl	$LC32, 12(%esp)
	movl	$__ZZN3dbg7message11setLogLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1175, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L348:
	movzbl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category3getEh
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category7forMaskEv
	testb	%al, %al
	jne	L349
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message11setLogLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1177, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L349:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message12copyLogLevelEv
	cmpb	$64, -32(%ebp)
	jne	L350
	movl	8(%ebp), %eax
	movzbl	22(%eax), %eax
	movb	%al, -21(%ebp)
	movl	$0, -12(%ebp)
	jmp	L351
L354:
	movl	-12(%ebp), %eax
	addl	$__ZN3dbg7message11m_logLevelGE, %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	movl	%eax, %ebx
	movzbl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	cmpb	%al, %bl
	jbe	L352
	movl	-12(%ebp), %eax
	addl	$__ZN3dbg7message11m_logLevelGE, %eax
	movzbl	(%eax), %eax
	jmp	L353
L352:
	movzbl	-28(%ebp), %eax
L353:
	movl	8(%ebp), %ecx
	movl	-12(%ebp), %edx
	addl	%ecx, %edx
	addl	$16, %edx
	movb	%al, 6(%edx)
	addl	$1, -12(%ebp)
L351:
	cmpl	$63, -12(%ebp)
	jle	L354
	movzbl	-21(%ebp), %eax
	jmp	L355
L350:
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category6forLogEv
	testb	%al, %al
	jne	L356
	movl	$LC31, 12(%esp)
	movl	$__ZZN3dbg7message11setLogLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1191, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L356:
	movzbl	-32(%ebp), %eax
	movl	8(%ebp), %edx
	movzbl	22(%edx,%eax), %eax
	movb	%al, -22(%ebp)
	movzbl	-32(%ebp), %ebx
	movzbl	-32(%ebp), %eax
	movzbl	__ZN3dbg7message11m_logLevelGE(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	movl	%eax, %esi
	movzbl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	movl	%esi, %ecx
	cmpb	%al, %cl
	jbe	L357
	movzbl	-32(%ebp), %eax
	movzbl	__ZN3dbg7message11m_logLevelGE(%eax), %eax
	jmp	L358
L357:
	movzbl	-28(%ebp), %eax
L358:
	movl	8(%ebp), %edx
	movb	%al, 22(%edx,%ebx)
	movzbl	-22(%ebp), %eax
L355:
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
LFE4301:
	.section	.text$_ZN3dbg7message14resetLogLevelGEh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message14resetLogLevelGEh
	.def	__ZN3dbg7message14resetLogLevelGEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message14resetLogLevelGEh:
LFB4302:
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
	movl	%eax, 4(%esp)
	movl	$2, (%esp)
	call	__ZN3dbg7message12setLogLevelGEhh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4302:
	.section	.text$_ZN3dbg7message13resetLogLevelEh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message13resetLogLevelEh
	.def	__ZN3dbg7message13resetLogLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message13resetLogLevelEh:
LFB4303:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$2, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message11setLogLevelEhh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4303:
	.section	.text$_ZN3dbg7message17resetLogLevelAllGEv,"x"
	.linkonce discard
	.globl	__ZN3dbg7message17resetLogLevelAllGEv
	.def	__ZN3dbg7message17resetLogLevelAllGEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message17resetLogLevelAllGEv:
LFB4304:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$__ZN3dbg7message11m_logLevelGE, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-8(%ebp), %eax
	addl	$64, %eax
	movl	%eax, -12(%ebp)
	jmp	L362
L363:
	movl	-4(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movb	$2, (%eax)
	addl	$1, -4(%ebp)
L362:
	movl	-4(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jne	L363
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4304:
	.section	.text$_ZN3dbg7message16resetLogLevelAllEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message16resetLogLevelAllEv
	.def	__ZN3dbg7message16resetLogLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16resetLogLevelAllEv:
LFB4305:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$64, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message13resetLogLevelEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4305:
	.section	.text$_ZN3dbg7message15copyNoticeLevelEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message15copyNoticeLevelEv
	.def	__ZN3dbg7message15copyNoticeLevelEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message15copyNoticeLevelEv:
LFB4306:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movzbl	21(%eax), %eax
	testb	%al, %al
	je	L366
	jmp	L365
L366:
	movl	8(%ebp), %eax
	movb	$1, 21(%eax)
	call	__ZN3dbg7message38getLastCallPointWithLogLevelHasChangedEv
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	L368
	movl	-12(%ebp), %eax
	leal	86(%eax), %edx
	movl	8(%ebp), %eax
	addl	$86, %eax
	movl	$64, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_memcpy
	jmp	L365
L368:
	movl	8(%ebp), %eax
	movl	__ZN3dbg7message14m_noticeLevelGE, %edx
	movl	%edx, 86(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+4, %edx
	movl	%edx, 90(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+8, %edx
	movl	%edx, 94(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+12, %edx
	movl	%edx, 98(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+16, %edx
	movl	%edx, 102(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+20, %edx
	movl	%edx, 106(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+24, %edx
	movl	%edx, 110(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+28, %edx
	movl	%edx, 114(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+32, %edx
	movl	%edx, 118(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+36, %edx
	movl	%edx, 122(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+40, %edx
	movl	%edx, 126(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+44, %edx
	movl	%edx, 130(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+48, %edx
	movl	%edx, 134(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+52, %edx
	movl	%edx, 138(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+56, %edx
	movl	%edx, 142(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+60, %edx
	movl	%edx, 146(%eax)
L365:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4306:
	.section .rdata,"dr"
	.align 4
LC33:
	.ascii "o_category.forNotice() == true\0"
	.section	.text$_ZN3dbg7message15getNoticeLevelGEh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message15getNoticeLevelGEh
	.def	__ZN3dbg7message15getNoticeLevelGEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message15getNoticeLevelGEh:
LFB4307:
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
	call	__ZN3dbg8category3getEh
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category7forMaskEv
	testb	%al, %al
	jne	L370
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message15getNoticeLevelGEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1237, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L370:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category9forNoticeEv
	testb	%al, %al
	jne	L371
	movl	$LC33, 12(%esp)
	movl	$__ZZN3dbg7message15getNoticeLevelGEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1238, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L371:
	movzbl	-28(%ebp), %eax
	movzbl	__ZN3dbg7message14m_noticeLevelGE(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4307:
	.section	.text$_ZN3dbg7message18getNoticeLevelG_CPEh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message18getNoticeLevelG_CPEh
	.def	__ZN3dbg7message18getNoticeLevelG_CPEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message18getNoticeLevelG_CPEh:
LFB4308:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	call	__ZN3dbg7message41getLastCallPointWithNoticeLevelHasChangedEv
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L374
	movzbl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message15getNoticeLevelGEh
	jmp	L375
L374:
	movzbl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message14getNoticeLevelEh
L375:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4308:
	.section	.text$_ZN3dbg7message22isValidTempNoticeLevelEh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message22isValidTempNoticeLevelEh
	.def	__ZN3dbg7message22isValidTempNoticeLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message22isValidTempNoticeLevelEh:
LFB4309:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movb	%al, -28(%ebp)
	movzbl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category3getEh
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category7forMaskEv
	testb	%al, %al
	jne	L377
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message22isValidTempNoticeLevelEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1254, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L377:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category9forNoticeEv
	testb	%al, %al
	jne	L378
	movl	$LC33, 12(%esp)
	movl	$__ZZN3dbg7message22isValidTempNoticeLevelEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1255, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L378:
	movl	8(%ebp), %eax
	movzbl	21(%eax), %eax
	testb	%al, %al
	je	L379
	movzbl	-28(%ebp), %eax
	movzbl	__ZN3dbg7message14m_noticeLevelGE(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	movl	%eax, %ebx
	movzbl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movzbl	86(%edx,%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	cmpb	%al, %bl
	ja	L379
	movl	$1, %eax
	jmp	L380
L379:
	movl	$0, %eax
L380:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4309:
	.section	.text$_ZN3dbg7message14getNoticeLevelEh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message14getNoticeLevelEh
	.def	__ZN3dbg7message14getNoticeLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message14getNoticeLevelEh:
LFB4310:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message22isValidTempNoticeLevelEh
	testb	%al, %al
	je	L383
	movzbl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movzbl	86(%edx,%eax), %eax
	jmp	L384
L383:
	movzbl	-12(%ebp), %eax
	movzbl	__ZN3dbg7message14m_noticeLevelGE(%eax), %eax
L384:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4310:
	.section	.text$_ZN3dbg7message17getNoticeLevel_CPEh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message17getNoticeLevel_CPEh
	.def	__ZN3dbg7message17getNoticeLevel_CPEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message17getNoticeLevel_CPEh:
LFB4311:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message22isValidTempNoticeLevelEh
	testb	%al, %al
	je	L387
	movzbl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movzbl	86(%edx,%eax), %eax
	jmp	L388
L387:
	movzbl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message18getNoticeLevelG_CPEh
L388:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4311:
	.section	.text$_ZN3dbg7message15setNoticeLevelGEhh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message15setNoticeLevelGEhh
	.def	__ZN3dbg7message15setNoticeLevelGEhh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message15setNoticeLevelGEhh:
LFB4312:
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
	movzbl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level3getEh
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level7forMaskEv
	testb	%al, %al
	jne	L391
	movl	$LC32, 12(%esp)
	movl	$__ZZN3dbg7message15setNoticeLevelGEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1274, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L391:
	movzbl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category3getEh
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category7forMaskEv
	testb	%al, %al
	jne	L392
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message15setNoticeLevelGEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1276, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L392:
	cmpb	$64, -48(%ebp)
	jne	L393
	movzbl	__ZN3dbg7message14m_noticeLevelGE, %eax
	movb	%al, -21(%ebp)
	movl	$__ZN3dbg7message14m_noticeLevelGE, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-28(%ebp), %eax
	addl	$64, %eax
	movl	%eax, -32(%ebp)
	jmp	L394
L395:
	movl	-12(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movzbl	-44(%ebp), %edx
	movb	%dl, (%eax)
	addl	$1, -12(%ebp)
L394:
	movl	-12(%ebp), %eax
	cmpl	-32(%ebp), %eax
	jne	L395
	movzbl	-21(%ebp), %eax
	jmp	L396
L393:
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category9forNoticeEv
	testb	%al, %al
	jne	L397
	movl	$LC33, 12(%esp)
	movl	$__ZZN3dbg7message15setNoticeLevelGEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1284, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L397:
	movzbl	-48(%ebp), %eax
	movzbl	__ZN3dbg7message14m_noticeLevelGE(%eax), %eax
	movb	%al, -37(%ebp)
	movzbl	-48(%ebp), %eax
	movzbl	-44(%ebp), %edx
	movb	%dl, __ZN3dbg7message14m_noticeLevelGE(%eax)
	movzbl	-37(%ebp), %eax
L396:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4312:
	.section	.text$_ZN3dbg7message14setNoticeLevelEhh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message14setNoticeLevelEhh
	.def	__ZN3dbg7message14setNoticeLevelEhh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message14setNoticeLevelEhh:
LFB4313:
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
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	movb	%dl, -28(%ebp)
	movb	%al, -32(%ebp)
	movzbl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level3getEh
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level7forMaskEv
	testb	%al, %al
	jne	L399
	movl	$LC32, 12(%esp)
	movl	$__ZZN3dbg7message14setNoticeLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1293, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L399:
	movzbl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category3getEh
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category7forMaskEv
	testb	%al, %al
	jne	L400
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message14setNoticeLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1295, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L400:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message15copyNoticeLevelEv
	cmpb	$64, -32(%ebp)
	jne	L401
	movl	8(%ebp), %eax
	movzbl	86(%eax), %eax
	movb	%al, -21(%ebp)
	movl	$0, -12(%ebp)
	jmp	L402
L405:
	movl	-12(%ebp), %eax
	addl	$__ZN3dbg7message14m_noticeLevelGE, %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	movl	%eax, %ebx
	movzbl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	cmpb	%al, %bl
	jbe	L403
	movl	-12(%ebp), %eax
	addl	$__ZN3dbg7message14m_noticeLevelGE, %eax
	movzbl	(%eax), %eax
	jmp	L404
L403:
	movzbl	-28(%ebp), %eax
L404:
	movl	8(%ebp), %ecx
	movl	-12(%ebp), %edx
	addl	%ecx, %edx
	addl	$80, %edx
	movb	%al, 6(%edx)
	addl	$1, -12(%ebp)
L402:
	cmpl	$63, -12(%ebp)
	jle	L405
	movzbl	-21(%ebp), %eax
	jmp	L406
L401:
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category9forNoticeEv
	testb	%al, %al
	jne	L407
	movl	$LC33, 12(%esp)
	movl	$__ZZN3dbg7message14setNoticeLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1309, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L407:
	movzbl	-32(%ebp), %eax
	movl	8(%ebp), %edx
	movzbl	86(%edx,%eax), %eax
	movb	%al, -22(%ebp)
	movzbl	-32(%ebp), %ebx
	movzbl	-32(%ebp), %eax
	movzbl	__ZN3dbg7message14m_noticeLevelGE(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	movl	%eax, %esi
	movzbl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	movl	%esi, %ecx
	cmpb	%al, %cl
	jbe	L408
	movzbl	-32(%ebp), %eax
	movzbl	__ZN3dbg7message14m_noticeLevelGE(%eax), %eax
	jmp	L409
L408:
	movzbl	-28(%ebp), %eax
L409:
	movl	8(%ebp), %edx
	movb	%al, 86(%edx,%ebx)
	movzbl	-22(%ebp), %eax
L406:
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
LFE4313:
	.section	.text$_ZN3dbg7message17resetNoticeLevelGEh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message17resetNoticeLevelGEh
	.def	__ZN3dbg7message17resetNoticeLevelGEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message17resetNoticeLevelGEh:
LFB4314:
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
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZN3dbg7message15setNoticeLevelGEhh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4314:
	.section	.text$_ZN3dbg7message16resetNoticeLevelEh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message16resetNoticeLevelEh
	.def	__ZN3dbg7message16resetNoticeLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16resetNoticeLevelEh:
LFB4315:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movb	%al, -12(%ebp)
	movzbl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$8, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message14setNoticeLevelEhh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4315:
	.section	.text$_ZN3dbg7message20resetNoticeLevelAllGEv,"x"
	.linkonce discard
	.globl	__ZN3dbg7message20resetNoticeLevelAllGEv
	.def	__ZN3dbg7message20resetNoticeLevelAllGEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message20resetNoticeLevelAllGEv:
LFB4316:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$__ZN3dbg7message14m_noticeLevelGE, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-8(%ebp), %eax
	addl	$64, %eax
	movl	%eax, -12(%ebp)
	jmp	L413
L414:
	movl	-4(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movb	$8, (%eax)
	addl	$1, -4(%ebp)
L413:
	movl	-4(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jne	L414
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4316:
	.section	.text$_ZN3dbg7message19resetNoticeLevelAllEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message19resetNoticeLevelAllEv
	.def	__ZN3dbg7message19resetNoticeLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message19resetNoticeLevelAllEv:
LFB4317:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$64, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message16resetNoticeLevelEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4317:
	.section	.text$_ZN3dbg7message11beginBufferEv,"x"
	.linkonce discard
	.globl	__ZN3dbg7message11beginBufferEv
	.def	__ZN3dbg7message11beginBufferEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message11beginBufferEv:
LFB4318:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	$___emutls_v._ZN3dbg7message13m_messageBuffE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L417
	call	__ZN3dbg7message10freeBufferEv
L417:
	movl	$___emutls_v._ZN3dbg7message17m_messageBuffSizeE, (%esp)
	call	___emutls_get_address
	movl	%eax, %ebx
	movl	$2048, (%ebx)
	movl	$___emutls_v._ZN3dbg7message17m_messageBuffUsedE, (%esp)
	call	___emutls_get_address
	movl	$0, (%eax)
	movl	(%ebx), %eax
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %ebx
	movl	$___emutls_v._ZN3dbg7message13m_messageBuffE, (%esp)
	call	___emutls_get_address
	movl	%ebx, (%eax)
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L416
	movl	$___emutls_v._ZN3dbg7message17m_messageBuffSizeE, (%esp)
	call	___emutls_get_address
	movl	$0, (%eax)
L416:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4318:
	.section	.text$_ZN3dbg7message10freeBufferEv,"x"
	.linkonce discard
	.globl	__ZN3dbg7message10freeBufferEv
	.def	__ZN3dbg7message10freeBufferEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message10freeBufferEv:
LFB4319:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	$___emutls_v._ZN3dbg7message13m_messageBuffE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L420
	jmp	L419
L420:
	movl	$___emutls_v._ZN3dbg7message13m_messageBuffE, (%esp)
	call	___emutls_get_address
	movl	%eax, %ebx
	movl	(%ebx), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	movl	$0, (%ebx)
	movl	$___emutls_v._ZN3dbg7message17m_messageBuffSizeE, (%esp)
	call	___emutls_get_address
	movl	$0, (%eax)
	movl	$___emutls_v._ZN3dbg7message17m_messageBuffUsedE, (%esp)
	call	___emutls_get_address
	movl	$0, (%eax)
L419:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4319:
	.section	.text$_ZN3dbg7message11flushBufferERKNS_5levelEbbb,"x"
	.linkonce discard
	.globl	__ZN3dbg7message11flushBufferERKNS_5levelEbbb
	.def	__ZN3dbg7message11flushBufferERKNS_5levelEbbb;	.scl	2;	.type	32;	.endef
__ZN3dbg7message11flushBufferERKNS_5levelEbbb:
LFB4320:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4320
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -28(%ebp)
	movb	%dl, -32(%ebp)
	movb	%al, -36(%ebp)
	movl	$___emutls_v._ZN3dbg7message13m_messageBuffE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L423
	jmp	L422
L423:
	cmpb	$0, -28(%ebp)
	je	L425
	cmpb	$0, -36(%ebp)
	je	L426
	movl	$___emutls_v._ZN3dbg7message13m_messageBuffE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %ebx
LEHB5:
	call	___getreent
	movl	8(%eax), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_fprintf
LEHE5:
	jmp	L425
L426:
	leal	-14(%ebp), %eax
	movl	$0, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB6:
	call	__ZNK3dbg5level11changeColorEb
LEHE6:
	subl	$4, %esp
	movl	$___emutls_v._ZN3dbg7message13m_messageBuffE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %ebx
LEHB7:
	call	___getreent
	movl	8(%eax), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_fprintf
LEHE7:
	leal	-14(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5colorD1Ev
L425:
	cmpb	$0, -32(%ebp)
	je	L428
	leal	-20(%ebp), %eax
	movl	$0, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB8:
	call	__ZNK3dbg5level20changeColorForNoticeEb
LEHE8:
	subl	$4, %esp
	movl	$___emutls_v._ZN3dbg7message13m_messageBuffE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %ebx
LEHB9:
	call	___getreent
	movl	12(%eax), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_fprintf
LEHE9:
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5colorD1Ev
L428:
	call	__ZN3dbg7message10freeBufferEv
	jmp	L422
L434:
	movl	%eax, %ebx
	leal	-14(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5colorD1Ev
	movl	%ebx, %eax
	jmp	L430
L433:
L430:
	movl	%eax, (%esp)
LEHB10:
	call	__Unwind_Resume
L436:
	movl	%eax, %ebx
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5colorD1Ev
	movl	%ebx, %eax
	jmp	L432
L435:
L432:
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE10:
L422:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4320:
	.section	.gcc_except_table,"w"
LLSDA4320:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4320-LLSDACSB4320
LLSDACSB4320:
	.uleb128 LEHB5-LFB4320
	.uleb128 LEHE5-LEHB5
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB6-LFB4320
	.uleb128 LEHE6-LEHB6
	.uleb128 L433-LFB4320
	.uleb128 0
	.uleb128 LEHB7-LFB4320
	.uleb128 LEHE7-LEHB7
	.uleb128 L434-LFB4320
	.uleb128 0
	.uleb128 LEHB8-LFB4320
	.uleb128 LEHE8-LEHB8
	.uleb128 L435-LFB4320
	.uleb128 0
	.uleb128 LEHB9-LFB4320
	.uleb128 LEHE9-LEHB9
	.uleb128 L436-LFB4320
	.uleb128 0
	.uleb128 LEHB10-LFB4320
	.uleb128 LEHE10-LEHB10
	.uleb128 0
	.uleb128 0
LLSDACSE4320:
	.section	.text$_ZN3dbg7message11flushBufferERKNS_5levelEbbb,"x"
	.linkonce discard
	.section	.text$_ZN3dbg7message7vbufferEPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message7vbufferEPKcPc
	.def	__ZN3dbg7message7vbufferEPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message7vbufferEPKcPc:
LFB4321:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$32, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	$___emutls_v._ZN3dbg7message17m_messageBuffSizeE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %ebx
	movl	$___emutls_v._ZN3dbg7message17m_messageBuffUsedE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	subl	%eax, %ebx
	movl	%ebx, %eax
	movl	%eax, -12(%ebp)
	movl	$___emutls_v._ZN3dbg7message13m_messageBuffE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L438
	cmpl	$0, -12(%ebp)
	jne	L439
L438:
	movl	$0, %eax
	jmp	L440
L439:
	movl	$___emutls_v._ZN3dbg7message13m_messageBuffE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %esi
	movl	$___emutls_v._ZN3dbg7message17m_messageBuffUsedE, (%esp)
	call	___emutls_get_address
	movl	%eax, %ebx
	movl	(%ebx), %eax
	leal	(%esi,%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_vsprintf
	movl	%eax, -16(%ebp)
	movl	(%ebx), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, (%ebx)
	movl	-16(%ebp), %eax
L440:
	addl	$32, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4321:
	.section	.text$_ZN3dbg7message6bufferEPKcz,"x"
	.linkonce discard
	.globl	__ZN3dbg7message6bufferEPKcz
	.def	__ZN3dbg7message6bufferEPKcz;	.scl	2;	.type	32;	.endef
__ZN3dbg7message6bufferEPKcz:
LFB4322:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message7vbufferEPKcPc
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4322:
	.section .rdata,"dr"
	.align 4
LC34:
	.ascii "o_level.forLog() == true || o_level.forNotice() == true\0"
	.align 4
LC35:
	.ascii "o_category.forLog() == true || o_category.forNotice() == true\0"
	.section	.text$_ZN3dbg7message12isAllowPrintERbS1_hhhh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message12isAllowPrintERbS1_hhhh
	.def	__ZN3dbg7message12isAllowPrintERbS1_hhhh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message12isAllowPrintERbS1_hhhh:
LFB4323:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %ebx
	movl	20(%ebp), %ecx
	movl	24(%ebp), %edx
	movl	28(%ebp), %eax
	movb	%bl, -28(%ebp)
	movb	%cl, -32(%ebp)
	movb	%dl, -36(%ebp)
	movb	%al, -40(%ebp)
	movzbl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level3getEh
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level6forLogEv
	xorl	$1, %eax
	testb	%al, %al
	je	L444
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level9forNoticeEv
	xorl	$1, %eax
	testb	%al, %al
	je	L444
	movl	$LC34, 12(%esp)
	movl	$__ZZN3dbg7message12isAllowPrintERbS1_hhhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1413, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L444:
	movzbl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category3getEh
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category6forLogEv
	xorl	$1, %eax
	testb	%al, %al
	je	L445
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category9forNoticeEv
	xorl	$1, %eax
	testb	%al, %al
	je	L445
	movl	$LC35, 12(%esp)
	movl	$__ZZN3dbg7message12isAllowPrintERbS1_hhhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1415, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L445:
	movzbl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level3getEh
	movl	%eax, -20(%ebp)
	movzbl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level3getEh
	movl	%eax, -24(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5levelgeERKS0_
	testb	%al, %al
	je	L446
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level6forLogEv
	testb	%al, %al
	je	L446
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category6forLogEv
	testb	%al, %al
	je	L446
	movl	$1, %eax
	jmp	L447
L446:
	movl	$0, %eax
L447:
	movl	8(%ebp), %edx
	movb	%al, (%edx)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5levelgeERKS0_
	testb	%al, %al
	je	L448
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level9forNoticeEv
	testb	%al, %al
	je	L448
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category9forNoticeEv
	testb	%al, %al
	je	L448
	movl	$1, %eax
	jmp	L449
L448:
	movl	$0, %eax
L449:
	movl	12(%ebp), %edx
	movb	%al, (%edx)
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4323:
	.section .rdata,"dr"
LC36:
	.ascii "[%s,%s]\0"
LC37:
	.ascii " \0"
	.section	.text$_ZN3dbg7message12vprintCommonEhhhhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message12vprintCommonEhhhhPKcPc
	.def	__ZN3dbg7message12vprintCommonEhhhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message12vprintCommonEhhhhPKcPc:
LFB4324:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4324
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %ebx
	movl	12(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%bl, -28(%ebp)
	movb	%cl, -32(%ebp)
	movb	%dl, -36(%ebp)
	movb	%al, -40(%ebp)
	movzbl	-40(%ebp), %ebx
	movzbl	-36(%ebp), %ecx
	movzbl	-32(%ebp), %edx
	movzbl	-28(%ebp), %eax
	movl	%ebx, 20(%esp)
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	leal	-22(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-21(%ebp), %eax
	movl	%eax, (%esp)
LEHB11:
	call	__ZN3dbg7message12isAllowPrintERbS1_hhhh
	movzbl	-21(%ebp), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L451
	movzbl	-22(%ebp), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L451
	movl	$0, %eax
	jmp	L457
L451:
	movzbl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level3getEh
	movl	%eax, -12(%ebp)
	movzbl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category3getEh
	movl	%eax, -16(%ebp)
	call	__ZN3dbg7message11beginBufferEv
	movzbl	-21(%ebp), %eax
	testb	%al, %al
	je	L453
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category4nameEv
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level4nameEv
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC36, (%esp)
	call	__ZN3dbg7message6bufferEPKcz
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	$1, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message11flushBufferERKNS_5levelEbbb
	call	__ZN3dbg7message11beginBufferEv
	movl	$LC37, (%esp)
	call	__ZN3dbg7message6bufferEPKcz
L453:
	movl	28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message7vbufferEPKcPc
	movl	%eax, -20(%ebp)
	movzbl	-22(%ebp), %eax
	movzbl	%al, %edx
	movzbl	-21(%ebp), %eax
	movzbl	%al, %eax
	movl	$1, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message11flushBufferERKNS_5levelEbbb
LEHE11:
	movl	-20(%ebp), %eax
	jmp	L457
L456:
	movl	%eax, (%esp)
LEHB12:
	call	__Unwind_Resume
LEHE12:
L457:
	addl	$68, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4324:
	.section	.gcc_except_table,"w"
LLSDA4324:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4324-LLSDACSB4324
LLSDACSB4324:
	.uleb128 LEHB11-LFB4324
	.uleb128 LEHE11-LEHB11
	.uleb128 L456-LFB4324
	.uleb128 0
	.uleb128 LEHB12-LFB4324
	.uleb128 LEHE12-LEHB12
	.uleb128 0
	.uleb128 0
LLSDACSE4324:
	.section	.text$_ZN3dbg7message12vprintCommonEhhhhPKcPc,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC38:
	.ascii "============================================================\12\0"
LC39:
	.ascii " Call point stack at \"%s\"\12\0"
	.align 4
LC40:
	.ascii "----------------------------------------\12\0"
LC41:
	.ascii "  \"%s\" \0"
LC42:
	.ascii " ... \0"
LC43:
	.ascii "%s\0"
LC44:
	.ascii " : \0"
LC45:
	.ascii " %s\0"
LC46:
	.ascii "\12\0"
	.section	.text$_ZN3dbg7message18printCPStackCommonEhhhPKcbb,"x"
	.linkonce discard
	.globl	__ZN3dbg7message18printCPStackCommonEhhhPKcbb
	.def	__ZN3dbg7message18printCPStackCommonEhhhPKcbb;	.scl	2;	.type	32;	.endef
__ZN3dbg7message18printCPStackCommonEhhhPKcbb:
LFB4325:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4325
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
	movl	8(%ebp), %esi
	movl	12(%ebp), %ebx
	movl	16(%ebp), %ecx
	movl	24(%ebp), %edx
	movl	28(%ebp), %edi
	movl	%esi, %eax
	movb	%al, -60(%ebp)
	movb	%bl, -64(%ebp)
	movb	%cl, -68(%ebp)
	movb	%dl, -72(%ebp)
	movl	%edi, %eax
	movb	%al, -76(%ebp)
	movzbl	-68(%ebp), %ecx
	movzbl	-64(%ebp), %edx
	movzbl	-60(%ebp), %eax
	movl	%ecx, 20(%esp)
	movl	%edx, 16(%esp)
	movl	$12, 12(%esp)
	movl	%eax, 8(%esp)
	leal	-46(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-45(%ebp), %eax
	movl	%eax, (%esp)
LEHB13:
	call	__ZN3dbg7message12isAllowPrintERbS1_hhhh
	movzbl	-45(%ebp), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L459
	jmp	L458
L459:
	movzbl	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level3getEh
	movl	%eax, -32(%ebp)
	movzbl	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category3getEh
	movl	%eax, -36(%ebp)
	call	__ZN3dbg7message11beginBufferEv
	movl	$LC38, (%esp)
	call	__ZN3dbg7message6bufferEPKcz
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category4nameEv
	movl	%eax, %ebx
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level4nameEv
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC36, (%esp)
	call	__ZN3dbg7message6bufferEPKcz
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	$1, 4(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message11flushBufferERKNS_5levelEbbb
	call	__ZN3dbg7message11beginBufferEv
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC39, (%esp)
	call	__ZN3dbg7message6bufferEPKcz
	movl	$LC40, (%esp)
	call	__ZN3dbg7message6bufferEPKcz
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	movl	%eax, -28(%ebp)
	jmp	L461
L466:
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message7getNameEv
	movl	%eax, 4(%esp)
	movl	$LC41, (%esp)
	call	__ZN3dbg7message6bufferEPKcz
	movl	$1, 12(%esp)
	movl	$0, 8(%esp)
	movl	$1, 4(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message11flushBufferERKNS_5levelEbbb
	call	__ZN3dbg7message11beginBufferEv
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message8getLevelEv
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level3getEh
	movl	%eax, -40(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message11getCategoryEv
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category3getEh
	movl	%eax, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category4nameEv
	movl	%eax, %ebx
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level4nameEv
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC36, (%esp)
	call	__ZN3dbg7message6bufferEPKcz
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	$1, 4(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message11flushBufferERKNS_5levelEbbb
	call	__ZN3dbg7message11beginBufferEv
	cmpb	$0, -72(%ebp)
	jne	L462
	cmpb	$0, -76(%ebp)
	je	L463
L462:
	movl	$LC42, (%esp)
	call	__ZN3dbg7message6bufferEPKcz
	cmpb	$0, -72(%ebp)
	je	L464
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message11getFuncNameEv
	movl	%eax, 4(%esp)
	movl	$LC43, (%esp)
	call	__ZN3dbg7message6bufferEPKcz
L464:
	cmpb	$0, -72(%ebp)
	je	L465
	cmpb	$0, -76(%ebp)
	je	L465
	movl	$LC44, (%esp)
	call	__ZN3dbg7message6bufferEPKcz
L465:
	cmpb	$0, -76(%ebp)
	je	L463
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message14getSrcFileNameEv
	movl	%eax, 4(%esp)
	movl	$LC45, (%esp)
	call	__ZN3dbg7message6bufferEPKcz
L463:
	movl	$LC46, (%esp)
	call	__ZN3dbg7message6bufferEPKcz
	movl	-28(%ebp), %eax
	movl	16(%eax), %eax
	movl	%eax, -28(%ebp)
L461:
	cmpl	$0, -28(%ebp)
	jne	L466
	movl	$1, 12(%esp)
	movl	$0, 8(%esp)
	movl	$1, 4(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message11flushBufferERKNS_5levelEbbb
	call	__ZN3dbg7message11beginBufferEv
	movl	$LC38, (%esp)
	call	__ZN3dbg7message6bufferEPKcz
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	$1, 4(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message11flushBufferERKNS_5levelEbbb
LEHE13:
	jmp	L458
L468:
	movl	%eax, (%esp)
LEHB14:
	call	__Unwind_Resume
LEHE14:
L458:
	addl	$92, %esp
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
LFE4325:
	.section	.gcc_except_table,"w"
LLSDA4325:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4325-LLSDACSB4325
LLSDACSB4325:
	.uleb128 LEHB13-LFB4325
	.uleb128 LEHE13-LEHB13
	.uleb128 L468-LFB4325
	.uleb128 0
	.uleb128 LEHB14-LFB4325
	.uleb128 LEHE14-LEHB14
	.uleb128 0
	.uleb128 0
LLSDACSE4325:
	.section	.text$_ZN3dbg7message18printCPStackCommonEhhhPKcbb,"x"
	.linkonce discard
	.section	.text$_ZN3dbg7message7vprintGEhhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message7vprintGEhhPKcPc
	.def	__ZN3dbg7message7vprintGEhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message7vprintGEhhPKcPc:
LFB4326:
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
	call	__ZN3dbg7message20adjustProperCategoryEh
	movb	%al, -9(%ebp)
	movzbl	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message15getLogLevelG_CPEh
	movb	%al, -10(%ebp)
	movzbl	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message18getNoticeLevelG_CPEh
	movb	%al, -11(%ebp)
	movzbl	-9(%ebp), %ebx
	movzbl	-28(%ebp), %ecx
	movzbl	-11(%ebp), %edx
	movzbl	-10(%ebp), %eax
	movl	20(%ebp), %esi
	movl	%esi, 20(%esp)
	movl	16(%ebp), %esi
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message12vprintCommonEhhhhPKcPc
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
LFE4326:
	.section	.text$_ZN3dbg7message6vprintEhhPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message6vprintEhhPKcPc
	.def	__ZN3dbg7message6vprintEhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message6vprintEhhPKcPc:
LFB4327:
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
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	movb	%dl, -28(%ebp)
	movb	%al, -32(%ebp)
	movzbl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message20adjustProperCategoryEh
	movb	%al, -9(%ebp)
	movzbl	-9(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message14getLogLevel_CPEh
	movb	%al, -10(%ebp)
	movzbl	-9(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message17getNoticeLevel_CPEh
	movb	%al, -11(%ebp)
	movzbl	-9(%ebp), %ebx
	movzbl	-28(%ebp), %ecx
	movzbl	-11(%ebp), %edx
	movzbl	-10(%ebp), %eax
	movl	24(%ebp), %esi
	movl	%esi, 20(%esp)
	movl	20(%ebp), %esi
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message12vprintCommonEhhhhPKcPc
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
LFE4327:
	.section	.text$_ZN3dbg7message6vprintEhPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message6vprintEhPKcPc
	.def	__ZN3dbg7message6vprintEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message6vprintEhPKcPc:
LFB4328:
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
	movzbl	1(%eax), %eax
	movzbl	%al, %edx
	movzbl	-12(%ebp), %eax
	movl	20(%ebp), %ecx
	movl	%ecx, 16(%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message6vprintEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4328:
	.section	.text$_ZN3dbg7message5vlogGEhhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message5vlogGEhhPKcPc
	.def	__ZN3dbg7message5vlogGEhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message5vlogGEhhPKcPc:
LFB4330:
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
	call	__ZN3dbg7message20adjustProperCategoryEh
	movb	%al, -9(%ebp)
	movzbl	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message15getLogLevelG_CPEh
	movb	%al, -10(%ebp)
	movb	$12, -11(%ebp)
	movzbl	-9(%ebp), %ecx
	movzbl	-28(%ebp), %edx
	movzbl	-10(%ebp), %eax
	movl	20(%ebp), %ebx
	movl	%ebx, 20(%esp)
	movl	16(%ebp), %ebx
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	$12, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message12vprintCommonEhhhhPKcPc
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4330:
	.section	.text$_ZN3dbg7message4vlogEhhPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message4vlogEhhPKcPc
	.def	__ZN3dbg7message4vlogEhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message4vlogEhhPKcPc:
LFB4331:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	movb	%dl, -28(%ebp)
	movb	%al, -32(%ebp)
	movzbl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message20adjustProperCategoryEh
	movb	%al, -9(%ebp)
	movzbl	-9(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message14getLogLevel_CPEh
	movb	%al, -10(%ebp)
	movb	$12, -11(%ebp)
	movzbl	-9(%ebp), %ecx
	movzbl	-28(%ebp), %edx
	movzbl	-10(%ebp), %eax
	movl	24(%ebp), %ebx
	movl	%ebx, 20(%esp)
	movl	20(%ebp), %ebx
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	$12, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message12vprintCommonEhhhhPKcPc
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4331:
	.section	.text$_ZN3dbg7message4vlogEhPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message4vlogEhPKcPc
	.def	__ZN3dbg7message4vlogEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message4vlogEhPKcPc:
LFB4332:
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
	movzbl	1(%eax), %eax
	movzbl	%al, %edx
	movzbl	-12(%ebp), %eax
	movl	20(%ebp), %ecx
	movl	%ecx, 16(%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4332:
	.section	.text$_ZN3dbg7message4vlogEPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message4vlogEPKcPc
	.def	__ZN3dbg7message4vlogEPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message4vlogEPKcPc:
LFB4333:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movzbl	1(%eax), %eax
	movzbl	%al, %edx
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	16(%ebp), %ecx
	movl	%ecx, 16(%esp)
	movl	12(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message4vlogEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4333:
	.section	.text$_ZN3dbg7message8vnoticeGEhhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message8vnoticeGEhhPKcPc
	.def	__ZN3dbg7message8vnoticeGEhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message8vnoticeGEhhPKcPc:
LFB4334:
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
	call	__ZN3dbg7message20adjustProperCategoryEh
	movb	%al, -9(%ebp)
	movb	$12, -10(%ebp)
	movzbl	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message18getNoticeLevelG_CPEh
	movb	%al, -11(%ebp)
	movzbl	-9(%ebp), %ecx
	movzbl	-28(%ebp), %edx
	movzbl	-11(%ebp), %eax
	movl	20(%ebp), %ebx
	movl	%ebx, 20(%esp)
	movl	16(%ebp), %ebx
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$12, (%esp)
	call	__ZN3dbg7message12vprintCommonEhhhhPKcPc
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4334:
	.section	.text$_ZN3dbg7message7vnoticeEhhPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message7vnoticeEhhPKcPc
	.def	__ZN3dbg7message7vnoticeEhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message7vnoticeEhhPKcPc:
LFB4335:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	movb	%dl, -28(%ebp)
	movb	%al, -32(%ebp)
	movzbl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message20adjustProperCategoryEh
	movb	%al, -9(%ebp)
	movb	$12, -10(%ebp)
	movzbl	-9(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message17getNoticeLevel_CPEh
	movb	%al, -11(%ebp)
	movzbl	-9(%ebp), %ecx
	movzbl	-28(%ebp), %edx
	movzbl	-11(%ebp), %eax
	movl	24(%ebp), %ebx
	movl	%ebx, 20(%esp)
	movl	20(%ebp), %ebx
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$12, (%esp)
	call	__ZN3dbg7message12vprintCommonEhhhhPKcPc
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4335:
	.section	.text$_ZN3dbg7message7vnoticeEPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message7vnoticeEPKcPc
	.def	__ZN3dbg7message7vnoticeEPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message7vnoticeEPKcPc:
LFB4337:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movzbl	1(%eax), %eax
	movzbl	%al, %edx
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	16(%ebp), %ecx
	movl	%ecx, 16(%esp)
	movl	12(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message7vnoticeEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4337:
	.section	.text$_ZN3dbg7message3logEPKcz,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message3logEPKcz
	.def	__ZN3dbg7message3logEPKcz;	.scl	2;	.type	32;	.endef
__ZN3dbg7message3logEPKcz:
LFB4345:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4345
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB15:
	call	__ZN3dbg7message4vlogEPKcPc
LEHE15:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L493
L492:
	movl	%eax, (%esp)
LEHB16:
	call	__Unwind_Resume
LEHE16:
L493:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4345:
	.section	.gcc_except_table,"w"
LLSDA4345:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4345-LLSDACSB4345
LLSDACSB4345:
	.uleb128 LEHB15-LFB4345
	.uleb128 LEHE15-LEHB15
	.uleb128 L492-LFB4345
	.uleb128 0
	.uleb128 LEHB16-LFB4345
	.uleb128 LEHE16-LEHB16
	.uleb128 0
	.uleb128 0
LLSDACSE4345:
	.section	.text$_ZN3dbg7message3logEPKcz,"x"
	.linkonce discard
	.section	.text$_ZN3dbg7message6noticeEPKcz,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message6noticeEPKcz
	.def	__ZN3dbg7message6noticeEPKcz;	.scl	2;	.type	32;	.endef
__ZN3dbg7message6noticeEPKcz:
LFB4349:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4349
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB17:
	call	__ZN3dbg7message7vnoticeEPKcPc
LEHE17:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L498
L497:
	movl	%eax, (%esp)
LEHB18:
	call	__Unwind_Resume
LEHE18:
L498:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4349:
	.section	.gcc_except_table,"w"
LLSDA4349:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4349-LLSDACSB4349
LLSDACSB4349:
	.uleb128 LEHB17-LFB4349
	.uleb128 LEHE17-LEHB17
	.uleb128 L497-LFB4349
	.uleb128 0
	.uleb128 LEHB18-LFB4349
	.uleb128 LEHE18-LEHB18
	.uleb128 0
	.uleb128 0
LLSDACSE4349:
	.section	.text$_ZN3dbg7message6noticeEPKcz,"x"
	.linkonce discard
	.section	.text$_ZN3dbg7message15vprintAsNormalGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message15vprintAsNormalGEhPKcPc
	.def	__ZN3dbg7message15vprintAsNormalGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message15vprintAsNormalGEhPKcPc:
LFB4350:
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
	call	__ZN3dbg7message7vprintGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4350:
	.section	.text$_ZN3dbg7message14vprintAsNormalEPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message14vprintAsNormalEPKcPc
	.def	__ZN3dbg7message14vprintAsNormalEPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message14vprintAsNormalEPKcPc:
LFB4352:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$2, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message6vprintEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4352:
	.section	.text$_ZN3dbg7message13vlogAsNormalGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message13vlogAsNormalGEhPKcPc
	.def	__ZN3dbg7message13vlogAsNormalGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message13vlogAsNormalGEhPKcPc:
LFB4353:
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
	call	__ZN3dbg7message5vlogGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4353:
	.section	.text$_ZN3dbg7message12vlogAsNormalEPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message12vlogAsNormalEPKcPc
	.def	__ZN3dbg7message12vlogAsNormalEPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message12vlogAsNormalEPKcPc:
LFB4355:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$2, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message4vlogEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4355:
	.section	.text$_ZN3dbg7message16vnoticeAsNormalGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message16vnoticeAsNormalGEhPKcPc
	.def	__ZN3dbg7message16vnoticeAsNormalGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16vnoticeAsNormalGEhPKcPc:
LFB4356:
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
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4356:
	.section	.text$_ZN3dbg7message16vprintAsVerboseGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message16vprintAsVerboseGEhPKcPc
	.def	__ZN3dbg7message16vprintAsVerboseGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16vprintAsVerboseGEhPKcPc:
LFB4359:
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
	call	__ZN3dbg7message7vprintGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4359:
	.section	.text$_ZN3dbg7message14vlogAsVerboseGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message14vlogAsVerboseGEhPKcPc
	.def	__ZN3dbg7message14vlogAsVerboseGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message14vlogAsVerboseGEhPKcPc:
LFB4362:
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
	call	__ZN3dbg7message5vlogGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4362:
	.section	.text$_ZN3dbg7message17vnoticeAsVerboseGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message17vnoticeAsVerboseGEhPKcPc
	.def	__ZN3dbg7message17vnoticeAsVerboseGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message17vnoticeAsVerboseGEhPKcPc:
LFB4365:
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
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4365:
	.section	.text$_ZN3dbg7message15vprintAsDetailGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message15vprintAsDetailGEhPKcPc
	.def	__ZN3dbg7message15vprintAsDetailGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message15vprintAsDetailGEhPKcPc:
LFB4368:
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
	call	__ZN3dbg7message7vprintGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4368:
	.section	.text$_ZN3dbg7message13vlogAsDetailGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message13vlogAsDetailGEhPKcPc
	.def	__ZN3dbg7message13vlogAsDetailGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message13vlogAsDetailGEhPKcPc:
LFB4371:
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
	call	__ZN3dbg7message5vlogGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4371:
	.section	.text$_ZN3dbg7message16vnoticeAsDetailGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message16vnoticeAsDetailGEhPKcPc
	.def	__ZN3dbg7message16vnoticeAsDetailGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16vnoticeAsDetailGEhPKcPc:
LFB4374:
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
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4374:
	.section	.text$_ZN3dbg7message18vprintAsImportantGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message18vprintAsImportantGEhPKcPc
	.def	__ZN3dbg7message18vprintAsImportantGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message18vprintAsImportantGEhPKcPc:
LFB4377:
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
	call	__ZN3dbg7message7vprintGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4377:
	.section	.text$_ZN3dbg7message16vlogAsImportantGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message16vlogAsImportantGEhPKcPc
	.def	__ZN3dbg7message16vlogAsImportantGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16vlogAsImportantGEhPKcPc:
LFB4380:
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
	call	__ZN3dbg7message5vlogGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4380:
	.section	.text$_ZN3dbg7message19vnoticeAsImportantGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message19vnoticeAsImportantGEhPKcPc
	.def	__ZN3dbg7message19vnoticeAsImportantGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message19vnoticeAsImportantGEhPKcPc:
LFB4383:
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
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4383:
	.section	.text$_ZN3dbg7message16vprintAsWarningGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message16vprintAsWarningGEhPKcPc
	.def	__ZN3dbg7message16vprintAsWarningGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16vprintAsWarningGEhPKcPc:
LFB4386:
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
	call	__ZN3dbg7message7vprintGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4386:
	.section	.text$_ZN3dbg7message14vlogAsWarningGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message14vlogAsWarningGEhPKcPc
	.def	__ZN3dbg7message14vlogAsWarningGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message14vlogAsWarningGEhPKcPc:
LFB4389:
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
	call	__ZN3dbg7message5vlogGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4389:
	.section	.text$_ZN3dbg7message17vnoticeAsWarningGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message17vnoticeAsWarningGEhPKcPc
	.def	__ZN3dbg7message17vnoticeAsWarningGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message17vnoticeAsWarningGEhPKcPc:
LFB4392:
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
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4392:
	.section	.text$_ZN3dbg7message17vprintAsCriticalGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message17vprintAsCriticalGEhPKcPc
	.def	__ZN3dbg7message17vprintAsCriticalGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message17vprintAsCriticalGEhPKcPc:
LFB4395:
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
	call	__ZN3dbg7message7vprintGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4395:
	.section	.text$_ZN3dbg7message15vlogAsCriticalGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message15vlogAsCriticalGEhPKcPc
	.def	__ZN3dbg7message15vlogAsCriticalGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message15vlogAsCriticalGEhPKcPc:
LFB4398:
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
	call	__ZN3dbg7message5vlogGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4398:
	.section	.text$_ZN3dbg7message18vnoticeAsCriticalGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message18vnoticeAsCriticalGEhPKcPc
	.def	__ZN3dbg7message18vnoticeAsCriticalGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message18vnoticeAsCriticalGEhPKcPc:
LFB4401:
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
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4401:
	.section	.text$_ZN3dbg7message17vprintAsAbsoluteGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message17vprintAsAbsoluteGEhPKcPc
	.def	__ZN3dbg7message17vprintAsAbsoluteGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message17vprintAsAbsoluteGEhPKcPc:
LFB4404:
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
	call	__ZN3dbg7message7vprintGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4404:
	.section	.text$_ZN3dbg7message15vlogAsAbsoluteGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message15vlogAsAbsoluteGEhPKcPc
	.def	__ZN3dbg7message15vlogAsAbsoluteGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message15vlogAsAbsoluteGEhPKcPc:
LFB4407:
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
	call	__ZN3dbg7message5vlogGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4407:
	.section	.text$_ZN3dbg7message18vnoticeAsAbsoluteGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message18vnoticeAsAbsoluteGEhPKcPc
	.def	__ZN3dbg7message18vnoticeAsAbsoluteGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message18vnoticeAsAbsoluteGEhPKcPc:
LFB4410:
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
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4410:
	.section	.text$_ZN3dbg7message13printAsNormalEPKcz,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message13printAsNormalEPKcz
	.def	__ZN3dbg7message13printAsNormalEPKcz;	.scl	2;	.type	32;	.endef
__ZN3dbg7message13printAsNormalEPKcz:
LFB4415:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4415
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB19:
	call	__ZN3dbg7message14vprintAsNormalEPKcPc
LEHE19:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L549
L548:
	movl	%eax, (%esp)
LEHB20:
	call	__Unwind_Resume
LEHE20:
L549:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4415:
	.section	.gcc_except_table,"w"
LLSDA4415:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4415-LLSDACSB4415
LLSDACSB4415:
	.uleb128 LEHB19-LFB4415
	.uleb128 LEHE19-LEHB19
	.uleb128 L548-LFB4415
	.uleb128 0
	.uleb128 LEHB20-LFB4415
	.uleb128 LEHE20-LEHB20
	.uleb128 0
	.uleb128 0
LLSDACSE4415:
	.section	.text$_ZN3dbg7message13printAsNormalEPKcz,"x"
	.linkonce discard
	.section	.text$_ZN3dbg7message11logAsNormalEPKcz,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message11logAsNormalEPKcz
	.def	__ZN3dbg7message11logAsNormalEPKcz;	.scl	2;	.type	32;	.endef
__ZN3dbg7message11logAsNormalEPKcz:
LFB4418:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4418
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB21:
	call	__ZN3dbg7message12vlogAsNormalEPKcPc
LEHE21:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L554
L553:
	movl	%eax, (%esp)
LEHB22:
	call	__Unwind_Resume
LEHE22:
L554:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4418:
	.section	.gcc_except_table,"w"
LLSDA4418:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4418-LLSDACSB4418
LLSDACSB4418:
	.uleb128 LEHB21-LFB4418
	.uleb128 LEHE21-LEHB21
	.uleb128 L553-LFB4418
	.uleb128 0
	.uleb128 LEHB22-LFB4418
	.uleb128 LEHE22-LEHB22
	.uleb128 0
	.uleb128 0
LLSDACSE4418:
	.section	.text$_ZN3dbg7message11logAsNormalEPKcz,"x"
	.linkonce discard
	.section .rdata,"dr"
LC47:
	.ascii "m_callPointStackHead != this\0"
	.section	.text$_ZN3dbg7message13pushCallPointEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message13pushCallPointEv
	.def	__ZN3dbg7message13pushCallPointEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message13pushCallPointEv:
LFB4476:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	jne	L556
	movl	$LC47, 12(%esp)
	movl	$__ZZN3dbg7message13pushCallPointEvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1799, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L556:
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %ecx
	movl	8(%ebp), %edx
	movl	%ecx, 16(%edx)
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4476:
	.section .rdata,"dr"
LC48:
	.ascii "m_callPointStackHead == this\0"
	.section	.text$_ZN3dbg7message12popCallPointEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message12popCallPointEv
	.def	__ZN3dbg7message12popCallPointEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message12popCallPointEv:
LFB4477:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	je	L558
	movl	$LC48, 12(%esp)
	movl	$__ZZN3dbg7message12popCallPointEvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1806, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L558:
	movl	8(%ebp), %eax
	movl	16(%eax), %ebx
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	%ebx, (%eax)
	movl	8(%ebp), %eax
	movl	$0, 16(%eax)
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4477:
	.section	.text$_ZN3dbg7message16getLastCallPointEv,"x"
	.linkonce discard
	.globl	__ZN3dbg7message16getLastCallPointEv
	.def	__ZN3dbg7message16getLastCallPointEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16getLastCallPointEv:
LFB4478:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4478:
	.section	.text$_ZN3dbg7message24getLastCriticalCallPointEv,"x"
	.linkonce discard
	.globl	__ZN3dbg7message24getLastCriticalCallPointEv
	.def	__ZN3dbg7message24getLastCriticalCallPointEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message24getLastCriticalCallPointEv:
LFB4479:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	jmp	L562
L565:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message8getLevelEv
	cmpb	$8, %al
	sete	%al
	testb	%al, %al
	je	L563
	jmp	L564
L563:
	movl	-12(%ebp), %eax
	movl	16(%eax), %eax
	movl	%eax, -12(%ebp)
L562:
	cmpl	$0, -12(%ebp)
	jne	L565
L564:
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4479:
	.section	.text$_ZN3dbg7message38getLastCallPointWithLogLevelHasChangedEv,"x"
	.linkonce discard
	.globl	__ZN3dbg7message38getLastCallPointWithLogLevelHasChangedEv
	.def	__ZN3dbg7message38getLastCallPointWithLogLevelHasChangedEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message38getLastCallPointWithLogLevelHasChangedEv:
LFB4480:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	jmp	L568
L571:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message18logLevelHasChangedEv
	testb	%al, %al
	je	L569
	jmp	L570
L569:
	movl	-12(%ebp), %eax
	movl	16(%eax), %eax
	movl	%eax, -12(%ebp)
L568:
	cmpl	$0, -12(%ebp)
	jne	L571
L570:
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4480:
	.section	.text$_ZN3dbg7message41getLastCallPointWithNoticeLevelHasChangedEv,"x"
	.linkonce discard
	.globl	__ZN3dbg7message41getLastCallPointWithNoticeLevelHasChangedEv
	.def	__ZN3dbg7message41getLastCallPointWithNoticeLevelHasChangedEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message41getLastCallPointWithNoticeLevelHasChangedEv:
LFB4481:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	jmp	L574
L577:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message21noticeLevelHasChangedEv
	testb	%al, %al
	je	L575
	jmp	L576
L575:
	movl	-12(%ebp), %eax
	movl	16(%eax), %eax
	movl	%eax, -12(%ebp)
L574:
	cmpl	$0, -12(%ebp)
	jne	L577
L576:
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4481:
	.section	.text$_ZN3dbg7message13printCPStackGEhhPKcbb,"x"
	.linkonce discard
	.globl	__ZN3dbg7message13printCPStackGEhhPKcbb
	.def	__ZN3dbg7message13printCPStackGEhhPKcbb;	.scl	2;	.type	32;	.endef
__ZN3dbg7message13printCPStackGEhhPKcbb:
LFB4482:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$64, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	8(%ebp), %ebx
	movl	12(%ebp), %ecx
	movl	20(%ebp), %edx
	movl	24(%ebp), %eax
	movb	%bl, -28(%ebp)
	movb	%cl, -32(%ebp)
	movb	%dl, -36(%ebp)
	movb	%al, -40(%ebp)
	movzbl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message20adjustProperCategoryEh
	movb	%al, -9(%ebp)
	movzbl	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message15getLogLevelG_CPEh
	movb	%al, -10(%ebp)
	movzbl	-40(%ebp), %esi
	movzbl	-36(%ebp), %ebx
	movzbl	-9(%ebp), %ecx
	movzbl	-28(%ebp), %edx
	movzbl	-10(%ebp), %eax
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	16(%ebp), %ebx
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message18printCPStackCommonEhhhPKcbb
	addl	$64, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4482:
	.section	.text$_ZN3dbg7message21printCPStackAsNormalGEhPKcbb,"x"
	.linkonce discard
	.globl	__ZN3dbg7message21printCPStackAsNormalGEhPKcbb
	.def	__ZN3dbg7message21printCPStackAsNormalGEhPKcbb;	.scl	2;	.type	32;	.endef
__ZN3dbg7message21printCPStackAsNormalGEhPKcbb:
LFB4484:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -12(%ebp)
	movb	%dl, -16(%ebp)
	movb	%al, -20(%ebp)
	movzbl	-20(%ebp), %ecx
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$2, (%esp)
	call	__ZN3dbg7message13printCPStackGEhhPKcbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4484:
	.section	.text$_ZN3dbg7message22printCPStackAsVerboseGEhPKcbb,"x"
	.linkonce discard
	.globl	__ZN3dbg7message22printCPStackAsVerboseGEhPKcbb
	.def	__ZN3dbg7message22printCPStackAsVerboseGEhPKcbb;	.scl	2;	.type	32;	.endef
__ZN3dbg7message22printCPStackAsVerboseGEhPKcbb:
LFB4487:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -12(%ebp)
	movb	%dl, -16(%ebp)
	movb	%al, -20(%ebp)
	movzbl	-20(%ebp), %ecx
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbg7message13printCPStackGEhhPKcbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4487:
	.section	.text$_ZN3dbg7message21printCPStackAsDetailGEhPKcbb,"x"
	.linkonce discard
	.globl	__ZN3dbg7message21printCPStackAsDetailGEhPKcbb
	.def	__ZN3dbg7message21printCPStackAsDetailGEhPKcbb;	.scl	2;	.type	32;	.endef
__ZN3dbg7message21printCPStackAsDetailGEhPKcbb:
LFB4490:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -12(%ebp)
	movb	%dl, -16(%ebp)
	movb	%al, -20(%ebp)
	movzbl	-20(%ebp), %ecx
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	call	__ZN3dbg7message13printCPStackGEhhPKcbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4490:
	.section	.text$_ZN3dbg7message24printCPStackAsImportantGEhPKcbb,"x"
	.linkonce discard
	.globl	__ZN3dbg7message24printCPStackAsImportantGEhPKcbb
	.def	__ZN3dbg7message24printCPStackAsImportantGEhPKcbb;	.scl	2;	.type	32;	.endef
__ZN3dbg7message24printCPStackAsImportantGEhPKcbb:
LFB4493:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -12(%ebp)
	movb	%dl, -16(%ebp)
	movb	%al, -20(%ebp)
	movzbl	-20(%ebp), %ecx
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZN3dbg7message13printCPStackGEhhPKcbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4493:
	.section	.text$_ZN3dbg7message22printCPStackAsWarningGEhPKcbb,"x"
	.linkonce discard
	.globl	__ZN3dbg7message22printCPStackAsWarningGEhPKcbb
	.def	__ZN3dbg7message22printCPStackAsWarningGEhPKcbb;	.scl	2;	.type	32;	.endef
__ZN3dbg7message22printCPStackAsWarningGEhPKcbb:
LFB4496:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -12(%ebp)
	movb	%dl, -16(%ebp)
	movb	%al, -20(%ebp)
	movzbl	-20(%ebp), %ecx
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$6, (%esp)
	call	__ZN3dbg7message13printCPStackGEhhPKcbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4496:
	.section	.text$_ZN3dbg7message23printCPStackAsCriticalGEhPKcbb,"x"
	.linkonce discard
	.globl	__ZN3dbg7message23printCPStackAsCriticalGEhPKcbb
	.def	__ZN3dbg7message23printCPStackAsCriticalGEhPKcbb;	.scl	2;	.type	32;	.endef
__ZN3dbg7message23printCPStackAsCriticalGEhPKcbb:
LFB4499:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -12(%ebp)
	movb	%dl, -16(%ebp)
	movb	%al, -20(%ebp)
	movzbl	-20(%ebp), %ecx
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZN3dbg7message13printCPStackGEhhPKcbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4499:
	.section	.text$_ZN3dbg7message23printCPStackAsAbsoluteGEhPKcbb,"x"
	.linkonce discard
	.globl	__ZN3dbg7message23printCPStackAsAbsoluteGEhPKcbb
	.def	__ZN3dbg7message23printCPStackAsAbsoluteGEhPKcbb;	.scl	2;	.type	32;	.endef
__ZN3dbg7message23printCPStackAsAbsoluteGEhPKcbb:
LFB4502:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -12(%ebp)
	movb	%dl, -16(%ebp)
	movb	%al, -20(%ebp)
	movzbl	-20(%ebp), %ecx
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$10, (%esp)
	call	__ZN3dbg7message13printCPStackGEhhPKcbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4502:
	.section	.text$_ZN3dbg7messageC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7messageC1Ev
	.def	__ZN3dbg7messageC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg7messageC1Ev:
LFB4507:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movb	$2, (%eax)
	movl	8(%ebp), %eax
	movb	$0, 1(%eax)
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	8(%ebp), %eax
	movl	$0, 8(%eax)
	movl	8(%ebp), %eax
	movl	$0, 12(%eax)
	movl	8(%ebp), %eax
	movl	$0, 16(%eax)
	movl	8(%ebp), %eax
	movb	$0, 20(%eax)
	movl	8(%ebp), %eax
	movb	$0, 21(%eax)
	call	__ZN3dbg7message14initializeOnceEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4507:
	.section .rdata,"dr"
	.align 4
LC49:
	.ascii "category_ >= category::NORMAL_MIN && category_ <= category::NORMAL_MAX\0"
	.section	.text$_ZN3dbg7messageC2EhhPKcS2_S2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7messageC2EhhPKcS2_S2_
	.def	__ZN3dbg7messageC2EhhPKcS2_S2_;	.scl	2;	.type	32;	.endef
__ZN3dbg7messageC2EhhPKcS2_S2_:
LFB4509:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	movb	%dl, -12(%ebp)
	movb	%al, -16(%ebp)
	movl	8(%ebp), %eax
	movzbl	-12(%ebp), %edx
	movb	%dl, (%eax)
	movl	8(%ebp), %eax
	movzbl	-16(%ebp), %edx
	movb	%dl, 1(%eax)
	movl	8(%ebp), %eax
	movl	20(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	24(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	28(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	8(%ebp), %eax
	movl	$0, 16(%eax)
	movl	8(%ebp), %eax
	movb	$0, 20(%eax)
	movl	8(%ebp), %eax
	movb	$0, 21(%eax)
	cmpb	$63, -16(%ebp)
	jbe	L588
	movl	$LC49, 12(%esp)
	movl	$__ZZN3dbg7messageC1EhhPKcS2_S2_E19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1910, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L588:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4509:
	.section	.text$_ZN3dbg7messageC1EhhPKcS2_S2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7messageC1EhhPKcS2_S2_
	.def	__ZN3dbg7messageC1EhhPKcS2_S2_;	.scl	2;	.type	32;	.endef
__ZN3dbg7messageC1EhhPKcS2_S2_:
LFB4510:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	movb	%dl, -12(%ebp)
	movb	%al, -16(%ebp)
	movl	8(%ebp), %eax
	movzbl	-12(%ebp), %edx
	movb	%dl, (%eax)
	movl	8(%ebp), %eax
	movzbl	-16(%ebp), %edx
	movb	%dl, 1(%eax)
	movl	8(%ebp), %eax
	movl	20(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	24(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	28(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	8(%ebp), %eax
	movl	$0, 16(%eax)
	movl	8(%ebp), %eax
	movb	$0, 20(%eax)
	movl	8(%ebp), %eax
	movb	$0, 21(%eax)
	cmpb	$63, -16(%ebp)
	jbe	L590
	movl	$LC49, 12(%esp)
	movl	$__ZZN3dbg7messageC1EhhPKcS2_S2_E19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1910, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L590:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4510:
	.section	.text$_ZN3dbg7messageD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7messageD2Ev
	.def	__ZN3dbg7messageD2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg7messageD2Ev:
LFB4512:
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
LFE4512:
	.section	.text$_ZN3dbg7messageD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7messageD1Ev
	.def	__ZN3dbg7messageD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg7messageD1Ev:
LFB4513:
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
LFE4513:
	.globl	__ZN3dbg7message15m_isInitializedE
	.bss
__ZN3dbg7message15m_isInitializedE:
	.space 1
	.globl	__ZN3dbg7message11m_logLevelGE
	.align 32
__ZN3dbg7message11m_logLevelGE:
	.space 64
	.globl	__ZN3dbg7message14m_noticeLevelGE
	.align 32
__ZN3dbg7message14m_noticeLevelGE:
	.space 64
	.text
	.align 2
	.globl	__ZN3dbg7message14initializeOnceEv
	.def	__ZN3dbg7message14initializeOnceEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message14initializeOnceEv:
LFB4514:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movzbl	__ZN3dbg7message15m_isInitializedE, %eax
	testb	%al, %al
	je	L597
	jmp	L596
L597:
	movb	$1, __ZN3dbg7message15m_isInitializedE
	call	__ZN3dbg7message17resetLogLevelAllGEv
	call	__ZN3dbg7message20resetNoticeLevelAllGEv
L596:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4514:
.lcomm __ZN3dbgL22s_messageForInitializeE,152,32
	.section	.text$_ZN3dbg9callPointC1EhhPKcjS2_S2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg9callPointC1EhhPKcjS2_S2_
	.def	__ZN3dbg9callPointC1EhhPKcjS2_S2_;	.scl	2;	.type	32;	.endef
__ZN3dbg9callPointC1EhhPKcjS2_S2_:
LFB4528:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4528
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	movb	%dl, -12(%ebp)
	movb	%al, -16(%ebp)
	movzbl	-16(%ebp), %ecx
	movzbl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	32(%ebp), %ebx
	movl	%ebx, 20(%esp)
	movl	28(%ebp), %ebx
	movl	%ebx, 16(%esp)
	movl	20(%ebp), %ebx
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB23:
	call	__ZN3dbg7messageC2EhhPKcS2_S2_
LEHE23:
	movl	8(%ebp), %eax
	movl	24(%ebp), %edx
	movl	%edx, 152(%eax)
	movl	8(%ebp), %eax
	leal	160(%eax), %ebx
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, (%ebx)
	movl	%edx, 4(%ebx)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB24:
	call	__ZN3dbg7message13pushCallPointEv
LEHE24:
	jmp	L602
L601:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7messageD2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB25:
	call	__Unwind_Resume
LEHE25:
L602:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4528:
	.section	.gcc_except_table,"w"
LLSDA4528:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4528-LLSDACSB4528
LLSDACSB4528:
	.uleb128 LEHB23-LFB4528
	.uleb128 LEHE23-LEHB23
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB24-LFB4528
	.uleb128 LEHE24-LEHB24
	.uleb128 L601-LFB4528
	.uleb128 0
	.uleb128 LEHB25-LFB4528
	.uleb128 LEHE25-LEHB25
	.uleb128 0
	.uleb128 0
LLSDACSE4528:
	.section	.text$_ZN3dbg9callPointC1EhhPKcjS2_S2_,"x"
	.linkonce discard
	.section	.text$_ZN3dbg9callPointD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg9callPointD1Ev
	.def	__ZN3dbg9callPointD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg9callPointD1Ev:
LFB4531:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4531
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message12popCallPointEv
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7messageD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4531:
	.section	.gcc_except_table,"w"
LLSDA4531:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4531-LLSDACSB4531
LLSDACSB4531:
LLSDACSE4531:
	.section	.text$_ZN3dbg9callPointD1Ev,"x"
	.linkonce discard
	.text
	.globl	__ZN3dbg11getLogLevelEh
	.def	__ZN3dbg11getLogLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg11getLogLevelEh:
LFB4532:
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
	call	__ZN3dbg7message12getLogLevelGEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4532:
	.globl	__ZN3dbg11setLogLevelEhh
	.def	__ZN3dbg11setLogLevelEhh;	.scl	2;	.type	32;	.endef
__ZN3dbg11setLogLevelEhh:
LFB4533:
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
	call	__ZN3dbg7message12setLogLevelGEhh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4533:
	.globl	__ZN3dbg13resetLogLevelEh
	.def	__ZN3dbg13resetLogLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg13resetLogLevelEh:
LFB4534:
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
	call	__ZN3dbg7message14resetLogLevelGEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4534:
	.globl	__ZN3dbg16resetLogLevelAllEv
	.def	__ZN3dbg16resetLogLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN3dbg16resetLogLevelAllEv:
LFB4535:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__ZN3dbg7message17resetLogLevelAllGEv
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4535:
	.globl	__ZN3dbg14getNoticeLevelEh
	.def	__ZN3dbg14getNoticeLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg14getNoticeLevelEh:
LFB4536:
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
	call	__ZN3dbg7message15getNoticeLevelGEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4536:
	.globl	__ZN3dbg14setNoticeLevelEhh
	.def	__ZN3dbg14setNoticeLevelEhh;	.scl	2;	.type	32;	.endef
__ZN3dbg14setNoticeLevelEhh:
LFB4537:
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
	call	__ZN3dbg7message15setNoticeLevelGEhh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4537:
	.globl	__ZN3dbg16resetNoticeLevelEh
	.def	__ZN3dbg16resetNoticeLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg16resetNoticeLevelEh:
LFB4538:
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
	call	__ZN3dbg7message17resetNoticeLevelGEh
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4538:
	.globl	__ZN3dbg19resetNoticeLevelAllEv
	.def	__ZN3dbg19resetNoticeLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN3dbg19resetNoticeLevelAllEv:
LFB4539:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__ZN3dbg7message20resetNoticeLevelAllGEv
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4539:
	.def	__ZN3dbgL6vprintEhhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL6vprintEhhPKcPc:
LFB4540:
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
	call	__ZN3dbg7message7vprintGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4540:
	.def	__ZN3dbgL4vlogEhhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL4vlogEhhPKcPc:
LFB4541:
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
	call	__ZN3dbg7message5vlogGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4541:
	.def	__ZN3dbgL7vnoticeEhhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL7vnoticeEhhPKcPc:
LFB4542:
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
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4542:
	.def	__ZN3dbgL5printEhhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL5printEhhPKcz:
LFB4543:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4543
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
LEHB26:
	call	__ZN3dbg7message7vprintGEhhPKcPc
LEHE26:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L627
L626:
	movl	%eax, (%esp)
LEHB27:
	call	__Unwind_Resume
LEHE27:
L627:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4543:
	.section	.gcc_except_table,"w"
LLSDA4543:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4543-LLSDACSB4543
LLSDACSB4543:
	.uleb128 LEHB26-LFB4543
	.uleb128 LEHE26-LEHB26
	.uleb128 L626-LFB4543
	.uleb128 0
	.uleb128 LEHB27-LFB4543
	.uleb128 LEHE27-LEHB27
	.uleb128 0
	.uleb128 0
LLSDACSE4543:
	.text
	.def	__ZN3dbgL3logEhhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL3logEhhPKcz:
LFB4544:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4544
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
LEHB28:
	call	__ZN3dbg7message5vlogGEhhPKcPc
LEHE28:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L632
L631:
	movl	%eax, (%esp)
LEHB29:
	call	__Unwind_Resume
LEHE29:
L632:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4544:
	.section	.gcc_except_table,"w"
LLSDA4544:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4544-LLSDACSB4544
LLSDACSB4544:
	.uleb128 LEHB28-LFB4544
	.uleb128 LEHE28-LEHB28
	.uleb128 L631-LFB4544
	.uleb128 0
	.uleb128 LEHB29-LFB4544
	.uleb128 LEHE29-LEHB29
	.uleb128 0
	.uleb128 0
LLSDACSE4544:
	.text
	.def	__ZN3dbgL6noticeEhhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL6noticeEhhPKcz:
LFB4545:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4545
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
LEHB30:
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
LEHE30:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L637
L636:
	movl	%eax, (%esp)
LEHB31:
	call	__Unwind_Resume
LEHE31:
L637:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4545:
	.section	.gcc_except_table,"w"
LLSDA4545:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4545-LLSDACSB4545
LLSDACSB4545:
	.uleb128 LEHB30-LFB4545
	.uleb128 LEHE30-LEHB30
	.uleb128 L636-LFB4545
	.uleb128 0
	.uleb128 LEHB31-LFB4545
	.uleb128 LEHE31-LEHB31
	.uleb128 0
	.uleb128 0
LLSDACSE4545:
	.text
	.def	__ZN3dbgL14vprintAsNormalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL14vprintAsNormalEhPKcPc:
LFB4546:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message15vprintAsNormalGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4546:
	.def	__ZN3dbgL12vlogAsNormalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL12vlogAsNormalEhPKcPc:
LFB4547:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message13vlogAsNormalGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4547:
	.def	__ZN3dbgL15vnoticeAsNormalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL15vnoticeAsNormalEhPKcPc:
LFB4548:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message16vnoticeAsNormalGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4548:
	.def	__ZN3dbgL15vprintAsVerboseEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL15vprintAsVerboseEhPKcPc:
LFB4549:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message16vprintAsVerboseGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4549:
	.def	__ZN3dbgL13vlogAsVerboseEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL13vlogAsVerboseEhPKcPc:
LFB4550:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message14vlogAsVerboseGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4550:
	.def	__ZN3dbgL16vnoticeAsVerboseEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL16vnoticeAsVerboseEhPKcPc:
LFB4551:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message17vnoticeAsVerboseGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4551:
	.def	__ZN3dbgL14vprintAsDetailEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL14vprintAsDetailEhPKcPc:
LFB4552:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message15vprintAsDetailGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4552:
	.def	__ZN3dbgL12vlogAsDetailEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL12vlogAsDetailEhPKcPc:
LFB4553:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message13vlogAsDetailGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4553:
	.def	__ZN3dbgL15vnoticeAsDetailEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL15vnoticeAsDetailEhPKcPc:
LFB4554:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message16vnoticeAsDetailGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4554:
	.def	__ZN3dbgL17vprintAsImportantEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL17vprintAsImportantEhPKcPc:
LFB4555:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message18vprintAsImportantGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4555:
	.def	__ZN3dbgL15vlogAsImportantEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL15vlogAsImportantEhPKcPc:
LFB4556:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message16vlogAsImportantGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4556:
	.def	__ZN3dbgL18vnoticeAsImportantEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL18vnoticeAsImportantEhPKcPc:
LFB4557:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message19vnoticeAsImportantGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4557:
	.def	__ZN3dbgL15vprintAsWarningEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL15vprintAsWarningEhPKcPc:
LFB4558:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message16vprintAsWarningGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4558:
	.def	__ZN3dbgL13vlogAsWarningEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL13vlogAsWarningEhPKcPc:
LFB4559:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message14vlogAsWarningGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4559:
	.def	__ZN3dbgL16vnoticeAsWarningEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL16vnoticeAsWarningEhPKcPc:
LFB4560:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message17vnoticeAsWarningGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4560:
	.def	__ZN3dbgL16vprintAsCriticalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL16vprintAsCriticalEhPKcPc:
LFB4561:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message17vprintAsCriticalGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4561:
	.def	__ZN3dbgL14vlogAsCriticalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL14vlogAsCriticalEhPKcPc:
LFB4562:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message15vlogAsCriticalGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4562:
	.def	__ZN3dbgL17vnoticeAsCriticalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL17vnoticeAsCriticalEhPKcPc:
LFB4563:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message18vnoticeAsCriticalGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4563:
	.def	__ZN3dbgL16vprintAsAbsoluteEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL16vprintAsAbsoluteEhPKcPc:
LFB4564:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message17vprintAsAbsoluteGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4564:
	.def	__ZN3dbgL14vlogAsAbsoluteEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL14vlogAsAbsoluteEhPKcPc:
LFB4565:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message15vlogAsAbsoluteGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4565:
	.def	__ZN3dbgL17vnoticeAsAbsoluteEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL17vnoticeAsAbsoluteEhPKcPc:
LFB4566:
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
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message18vnoticeAsAbsoluteGEhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4566:
	.def	__ZN3dbgL13printAsNormalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL13printAsNormalEhPKcz:
LFB4567:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4567
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
LEHB32:
	call	__ZN3dbg7message15vprintAsNormalGEhPKcPc
LEHE32:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L684
L683:
	movl	%eax, (%esp)
LEHB33:
	call	__Unwind_Resume
LEHE33:
L684:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4567:
	.section	.gcc_except_table,"w"
LLSDA4567:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4567-LLSDACSB4567
LLSDACSB4567:
	.uleb128 LEHB32-LFB4567
	.uleb128 LEHE32-LEHB32
	.uleb128 L683-LFB4567
	.uleb128 0
	.uleb128 LEHB33-LFB4567
	.uleb128 LEHE33-LEHB33
	.uleb128 0
	.uleb128 0
LLSDACSE4567:
	.text
	.def	__ZN3dbgL11logAsNormalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL11logAsNormalEhPKcz:
LFB4568:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4568
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
LEHB34:
	call	__ZN3dbg7message13vlogAsNormalGEhPKcPc
LEHE34:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L689
L688:
	movl	%eax, (%esp)
LEHB35:
	call	__Unwind_Resume
LEHE35:
L689:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4568:
	.section	.gcc_except_table,"w"
LLSDA4568:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4568-LLSDACSB4568
LLSDACSB4568:
	.uleb128 LEHB34-LFB4568
	.uleb128 LEHE34-LEHB34
	.uleb128 L688-LFB4568
	.uleb128 0
	.uleb128 LEHB35-LFB4568
	.uleb128 LEHE35-LEHB35
	.uleb128 0
	.uleb128 0
LLSDACSE4568:
	.text
	.def	__ZN3dbgL14noticeAsNormalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL14noticeAsNormalEhPKcz:
LFB4569:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4569
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
LEHB36:
	call	__ZN3dbg7message16vnoticeAsNormalGEhPKcPc
LEHE36:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L694
L693:
	movl	%eax, (%esp)
LEHB37:
	call	__Unwind_Resume
LEHE37:
L694:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4569:
	.section	.gcc_except_table,"w"
LLSDA4569:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4569-LLSDACSB4569
LLSDACSB4569:
	.uleb128 LEHB36-LFB4569
	.uleb128 LEHE36-LEHB36
	.uleb128 L693-LFB4569
	.uleb128 0
	.uleb128 LEHB37-LFB4569
	.uleb128 LEHE37-LEHB37
	.uleb128 0
	.uleb128 0
LLSDACSE4569:
	.text
	.def	__ZN3dbgL14printAsVerboseEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL14printAsVerboseEhPKcz:
LFB4570:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4570
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
LEHB38:
	call	__ZN3dbg7message16vprintAsVerboseGEhPKcPc
LEHE38:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L699
L698:
	movl	%eax, (%esp)
LEHB39:
	call	__Unwind_Resume
LEHE39:
L699:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4570:
	.section	.gcc_except_table,"w"
LLSDA4570:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4570-LLSDACSB4570
LLSDACSB4570:
	.uleb128 LEHB38-LFB4570
	.uleb128 LEHE38-LEHB38
	.uleb128 L698-LFB4570
	.uleb128 0
	.uleb128 LEHB39-LFB4570
	.uleb128 LEHE39-LEHB39
	.uleb128 0
	.uleb128 0
LLSDACSE4570:
	.text
	.def	__ZN3dbgL12logAsVerboseEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL12logAsVerboseEhPKcz:
LFB4571:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4571
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
LEHB40:
	call	__ZN3dbg7message14vlogAsVerboseGEhPKcPc
LEHE40:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L704
L703:
	movl	%eax, (%esp)
LEHB41:
	call	__Unwind_Resume
LEHE41:
L704:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4571:
	.section	.gcc_except_table,"w"
LLSDA4571:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4571-LLSDACSB4571
LLSDACSB4571:
	.uleb128 LEHB40-LFB4571
	.uleb128 LEHE40-LEHB40
	.uleb128 L703-LFB4571
	.uleb128 0
	.uleb128 LEHB41-LFB4571
	.uleb128 LEHE41-LEHB41
	.uleb128 0
	.uleb128 0
LLSDACSE4571:
	.text
	.def	__ZN3dbgL15noticeAsVerboseEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL15noticeAsVerboseEhPKcz:
LFB4572:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4572
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
LEHB42:
	call	__ZN3dbg7message17vnoticeAsVerboseGEhPKcPc
LEHE42:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L709
L708:
	movl	%eax, (%esp)
LEHB43:
	call	__Unwind_Resume
LEHE43:
L709:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4572:
	.section	.gcc_except_table,"w"
LLSDA4572:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4572-LLSDACSB4572
LLSDACSB4572:
	.uleb128 LEHB42-LFB4572
	.uleb128 LEHE42-LEHB42
	.uleb128 L708-LFB4572
	.uleb128 0
	.uleb128 LEHB43-LFB4572
	.uleb128 LEHE43-LEHB43
	.uleb128 0
	.uleb128 0
LLSDACSE4572:
	.text
	.def	__ZN3dbgL13printAsDetailEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL13printAsDetailEhPKcz:
LFB4573:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4573
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
LEHB44:
	call	__ZN3dbg7message15vprintAsDetailGEhPKcPc
LEHE44:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L714
L713:
	movl	%eax, (%esp)
LEHB45:
	call	__Unwind_Resume
LEHE45:
L714:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4573:
	.section	.gcc_except_table,"w"
LLSDA4573:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4573-LLSDACSB4573
LLSDACSB4573:
	.uleb128 LEHB44-LFB4573
	.uleb128 LEHE44-LEHB44
	.uleb128 L713-LFB4573
	.uleb128 0
	.uleb128 LEHB45-LFB4573
	.uleb128 LEHE45-LEHB45
	.uleb128 0
	.uleb128 0
LLSDACSE4573:
	.text
	.def	__ZN3dbgL11logAsDetailEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL11logAsDetailEhPKcz:
LFB4574:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4574
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
LEHB46:
	call	__ZN3dbg7message13vlogAsDetailGEhPKcPc
LEHE46:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L719
L718:
	movl	%eax, (%esp)
LEHB47:
	call	__Unwind_Resume
LEHE47:
L719:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4574:
	.section	.gcc_except_table,"w"
LLSDA4574:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4574-LLSDACSB4574
LLSDACSB4574:
	.uleb128 LEHB46-LFB4574
	.uleb128 LEHE46-LEHB46
	.uleb128 L718-LFB4574
	.uleb128 0
	.uleb128 LEHB47-LFB4574
	.uleb128 LEHE47-LEHB47
	.uleb128 0
	.uleb128 0
LLSDACSE4574:
	.text
	.def	__ZN3dbgL14noticeAsDetailEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL14noticeAsDetailEhPKcz:
LFB4575:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4575
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
LEHB48:
	call	__ZN3dbg7message16vnoticeAsDetailGEhPKcPc
LEHE48:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L724
L723:
	movl	%eax, (%esp)
LEHB49:
	call	__Unwind_Resume
LEHE49:
L724:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4575:
	.section	.gcc_except_table,"w"
LLSDA4575:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4575-LLSDACSB4575
LLSDACSB4575:
	.uleb128 LEHB48-LFB4575
	.uleb128 LEHE48-LEHB48
	.uleb128 L723-LFB4575
	.uleb128 0
	.uleb128 LEHB49-LFB4575
	.uleb128 LEHE49-LEHB49
	.uleb128 0
	.uleb128 0
LLSDACSE4575:
	.text
	.def	__ZN3dbgL16printAsImportantEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL16printAsImportantEhPKcz:
LFB4576:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4576
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
LEHB50:
	call	__ZN3dbg7message18vprintAsImportantGEhPKcPc
LEHE50:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L729
L728:
	movl	%eax, (%esp)
LEHB51:
	call	__Unwind_Resume
LEHE51:
L729:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4576:
	.section	.gcc_except_table,"w"
LLSDA4576:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4576-LLSDACSB4576
LLSDACSB4576:
	.uleb128 LEHB50-LFB4576
	.uleb128 LEHE50-LEHB50
	.uleb128 L728-LFB4576
	.uleb128 0
	.uleb128 LEHB51-LFB4576
	.uleb128 LEHE51-LEHB51
	.uleb128 0
	.uleb128 0
LLSDACSE4576:
	.text
	.def	__ZN3dbgL14logAsImportantEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL14logAsImportantEhPKcz:
LFB4577:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4577
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
LEHB52:
	call	__ZN3dbg7message16vlogAsImportantGEhPKcPc
LEHE52:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L734
L733:
	movl	%eax, (%esp)
LEHB53:
	call	__Unwind_Resume
LEHE53:
L734:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4577:
	.section	.gcc_except_table,"w"
LLSDA4577:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4577-LLSDACSB4577
LLSDACSB4577:
	.uleb128 LEHB52-LFB4577
	.uleb128 LEHE52-LEHB52
	.uleb128 L733-LFB4577
	.uleb128 0
	.uleb128 LEHB53-LFB4577
	.uleb128 LEHE53-LEHB53
	.uleb128 0
	.uleb128 0
LLSDACSE4577:
	.text
	.def	__ZN3dbgL17noticeAsImportantEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL17noticeAsImportantEhPKcz:
LFB4578:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4578
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
LEHB54:
	call	__ZN3dbg7message19vnoticeAsImportantGEhPKcPc
LEHE54:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L739
L738:
	movl	%eax, (%esp)
LEHB55:
	call	__Unwind_Resume
LEHE55:
L739:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4578:
	.section	.gcc_except_table,"w"
LLSDA4578:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4578-LLSDACSB4578
LLSDACSB4578:
	.uleb128 LEHB54-LFB4578
	.uleb128 LEHE54-LEHB54
	.uleb128 L738-LFB4578
	.uleb128 0
	.uleb128 LEHB55-LFB4578
	.uleb128 LEHE55-LEHB55
	.uleb128 0
	.uleb128 0
LLSDACSE4578:
	.text
	.def	__ZN3dbgL14printAsWarningEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL14printAsWarningEhPKcz:
LFB4579:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4579
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
LEHB56:
	call	__ZN3dbg7message16vprintAsWarningGEhPKcPc
LEHE56:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L744
L743:
	movl	%eax, (%esp)
LEHB57:
	call	__Unwind_Resume
LEHE57:
L744:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4579:
	.section	.gcc_except_table,"w"
LLSDA4579:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4579-LLSDACSB4579
LLSDACSB4579:
	.uleb128 LEHB56-LFB4579
	.uleb128 LEHE56-LEHB56
	.uleb128 L743-LFB4579
	.uleb128 0
	.uleb128 LEHB57-LFB4579
	.uleb128 LEHE57-LEHB57
	.uleb128 0
	.uleb128 0
LLSDACSE4579:
	.text
	.def	__ZN3dbgL12logAsWarningEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL12logAsWarningEhPKcz:
LFB4580:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4580
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
LEHB58:
	call	__ZN3dbg7message14vlogAsWarningGEhPKcPc
LEHE58:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L749
L748:
	movl	%eax, (%esp)
LEHB59:
	call	__Unwind_Resume
LEHE59:
L749:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4580:
	.section	.gcc_except_table,"w"
LLSDA4580:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4580-LLSDACSB4580
LLSDACSB4580:
	.uleb128 LEHB58-LFB4580
	.uleb128 LEHE58-LEHB58
	.uleb128 L748-LFB4580
	.uleb128 0
	.uleb128 LEHB59-LFB4580
	.uleb128 LEHE59-LEHB59
	.uleb128 0
	.uleb128 0
LLSDACSE4580:
	.text
	.def	__ZN3dbgL15noticeAsWarningEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL15noticeAsWarningEhPKcz:
LFB4581:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4581
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
LEHB60:
	call	__ZN3dbg7message17vnoticeAsWarningGEhPKcPc
LEHE60:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L754
L753:
	movl	%eax, (%esp)
LEHB61:
	call	__Unwind_Resume
LEHE61:
L754:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4581:
	.section	.gcc_except_table,"w"
LLSDA4581:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4581-LLSDACSB4581
LLSDACSB4581:
	.uleb128 LEHB60-LFB4581
	.uleb128 LEHE60-LEHB60
	.uleb128 L753-LFB4581
	.uleb128 0
	.uleb128 LEHB61-LFB4581
	.uleb128 LEHE61-LEHB61
	.uleb128 0
	.uleb128 0
LLSDACSE4581:
	.text
	.def	__ZN3dbgL15printAsCriticalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL15printAsCriticalEhPKcz:
LFB4582:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4582
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
LEHB62:
	call	__ZN3dbg7message17vprintAsCriticalGEhPKcPc
LEHE62:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L759
L758:
	movl	%eax, (%esp)
LEHB63:
	call	__Unwind_Resume
LEHE63:
L759:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4582:
	.section	.gcc_except_table,"w"
LLSDA4582:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4582-LLSDACSB4582
LLSDACSB4582:
	.uleb128 LEHB62-LFB4582
	.uleb128 LEHE62-LEHB62
	.uleb128 L758-LFB4582
	.uleb128 0
	.uleb128 LEHB63-LFB4582
	.uleb128 LEHE63-LEHB63
	.uleb128 0
	.uleb128 0
LLSDACSE4582:
	.text
	.def	__ZN3dbgL13logAsCriticalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL13logAsCriticalEhPKcz:
LFB4583:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4583
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
LEHB64:
	call	__ZN3dbg7message15vlogAsCriticalGEhPKcPc
LEHE64:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L764
L763:
	movl	%eax, (%esp)
LEHB65:
	call	__Unwind_Resume
LEHE65:
L764:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4583:
	.section	.gcc_except_table,"w"
LLSDA4583:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4583-LLSDACSB4583
LLSDACSB4583:
	.uleb128 LEHB64-LFB4583
	.uleb128 LEHE64-LEHB64
	.uleb128 L763-LFB4583
	.uleb128 0
	.uleb128 LEHB65-LFB4583
	.uleb128 LEHE65-LEHB65
	.uleb128 0
	.uleb128 0
LLSDACSE4583:
	.text
	.def	__ZN3dbgL16noticeAsCriticalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL16noticeAsCriticalEhPKcz:
LFB4584:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4584
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
LEHB66:
	call	__ZN3dbg7message18vnoticeAsCriticalGEhPKcPc
LEHE66:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L769
L768:
	movl	%eax, (%esp)
LEHB67:
	call	__Unwind_Resume
LEHE67:
L769:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4584:
	.section	.gcc_except_table,"w"
LLSDA4584:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4584-LLSDACSB4584
LLSDACSB4584:
	.uleb128 LEHB66-LFB4584
	.uleb128 LEHE66-LEHB66
	.uleb128 L768-LFB4584
	.uleb128 0
	.uleb128 LEHB67-LFB4584
	.uleb128 LEHE67-LEHB67
	.uleb128 0
	.uleb128 0
LLSDACSE4584:
	.text
	.def	__ZN3dbgL15printAsAbsoluteEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL15printAsAbsoluteEhPKcz:
LFB4585:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4585
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
LEHB68:
	call	__ZN3dbg7message17vprintAsAbsoluteGEhPKcPc
LEHE68:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L774
L773:
	movl	%eax, (%esp)
LEHB69:
	call	__Unwind_Resume
LEHE69:
L774:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4585:
	.section	.gcc_except_table,"w"
LLSDA4585:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4585-LLSDACSB4585
LLSDACSB4585:
	.uleb128 LEHB68-LFB4585
	.uleb128 LEHE68-LEHB68
	.uleb128 L773-LFB4585
	.uleb128 0
	.uleb128 LEHB69-LFB4585
	.uleb128 LEHE69-LEHB69
	.uleb128 0
	.uleb128 0
LLSDACSE4585:
	.text
	.def	__ZN3dbgL13logAsAbsoluteEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL13logAsAbsoluteEhPKcz:
LFB4586:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4586
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
LEHB70:
	call	__ZN3dbg7message15vlogAsAbsoluteGEhPKcPc
LEHE70:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L779
L778:
	movl	%eax, (%esp)
LEHB71:
	call	__Unwind_Resume
LEHE71:
L779:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4586:
	.section	.gcc_except_table,"w"
LLSDA4586:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4586-LLSDACSB4586
LLSDACSB4586:
	.uleb128 LEHB70-LFB4586
	.uleb128 LEHE70-LEHB70
	.uleb128 L778-LFB4586
	.uleb128 0
	.uleb128 LEHB71-LFB4586
	.uleb128 LEHE71-LEHB71
	.uleb128 0
	.uleb128 0
LLSDACSE4586:
	.text
	.def	__ZN3dbgL16noticeAsAbsoluteEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL16noticeAsAbsoluteEhPKcz:
LFB4587:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4587
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
LEHB72:
	call	__ZN3dbg7message18vnoticeAsAbsoluteGEhPKcPc
LEHE72:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L784
L783:
	movl	%eax, (%esp)
LEHB73:
	call	__Unwind_Resume
LEHE73:
L784:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4587:
	.section	.gcc_except_table,"w"
LLSDA4587:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4587-LLSDACSB4587
LLSDACSB4587:
	.uleb128 LEHB72-LFB4587
	.uleb128 LEHE72-LEHB72
	.uleb128 L783-LFB4587
	.uleb128 0
	.uleb128 LEHB73-LFB4587
	.uleb128 LEHE73-LEHB73
	.uleb128 0
	.uleb128 0
LLSDACSE4587:
	.text
	.globl	__ZN3dbg12printCPStackEhhPKcbb
	.def	__ZN3dbg12printCPStackEhhPKcbb;	.scl	2;	.type	32;	.endef
__ZN3dbg12printCPStackEhhPKcbb:
LFB4588:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %ebx
	movl	12(%ebp), %ecx
	movl	20(%ebp), %edx
	movl	24(%ebp), %eax
	movb	%bl, -12(%ebp)
	movb	%cl, -16(%ebp)
	movb	%dl, -20(%ebp)
	movb	%al, -24(%ebp)
	movzbl	-24(%ebp), %ebx
	movzbl	-20(%ebp), %ecx
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message13printCPStackGEhhPKcbb
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4588:
	.def	__ZN3dbgL20printCPStackAsNormalEhPKcbb;	.scl	3;	.type	32;	.endef
__ZN3dbgL20printCPStackAsNormalEhPKcbb:
LFB4589:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -12(%ebp)
	movb	%dl, -16(%ebp)
	movb	%al, -20(%ebp)
	movzbl	-20(%ebp), %ecx
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message21printCPStackAsNormalGEhPKcbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4589:
	.def	__ZN3dbgL21printCPStackAsVerboseEhPKcbb;	.scl	3;	.type	32;	.endef
__ZN3dbgL21printCPStackAsVerboseEhPKcbb:
LFB4590:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -12(%ebp)
	movb	%dl, -16(%ebp)
	movb	%al, -20(%ebp)
	movzbl	-20(%ebp), %ecx
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message22printCPStackAsVerboseGEhPKcbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4590:
	.def	__ZN3dbgL20printCPStackAsDetailEhPKcbb;	.scl	3;	.type	32;	.endef
__ZN3dbgL20printCPStackAsDetailEhPKcbb:
LFB4591:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -12(%ebp)
	movb	%dl, -16(%ebp)
	movb	%al, -20(%ebp)
	movzbl	-20(%ebp), %ecx
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message21printCPStackAsDetailGEhPKcbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4591:
	.def	__ZN3dbgL23printCPStackAsImportantEhPKcbb;	.scl	3;	.type	32;	.endef
__ZN3dbgL23printCPStackAsImportantEhPKcbb:
LFB4592:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -12(%ebp)
	movb	%dl, -16(%ebp)
	movb	%al, -20(%ebp)
	movzbl	-20(%ebp), %ecx
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message24printCPStackAsImportantGEhPKcbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4592:
	.def	__ZN3dbgL21printCPStackAsWarningEhPKcbb;	.scl	3;	.type	32;	.endef
__ZN3dbgL21printCPStackAsWarningEhPKcbb:
LFB4593:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -12(%ebp)
	movb	%dl, -16(%ebp)
	movb	%al, -20(%ebp)
	movzbl	-20(%ebp), %ecx
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message22printCPStackAsWarningGEhPKcbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4593:
	.def	__ZN3dbgL22printCPStackAsCriticalEhPKcbb;	.scl	3;	.type	32;	.endef
__ZN3dbgL22printCPStackAsCriticalEhPKcbb:
LFB4594:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -12(%ebp)
	movb	%dl, -16(%ebp)
	movb	%al, -20(%ebp)
	movzbl	-20(%ebp), %ecx
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message23printCPStackAsCriticalGEhPKcbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4594:
	.def	__ZN3dbgL22printCPStackAsAbsoluteEhPKcbb;	.scl	3;	.type	32;	.endef
__ZN3dbgL22printCPStackAsAbsoluteEhPKcbb:
LFB4595:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movb	%cl, -12(%ebp)
	movb	%dl, -16(%ebp)
	movb	%al, -20(%ebp)
	movzbl	-20(%ebp), %ecx
	movzbl	-16(%ebp), %edx
	movzbl	-12(%ebp), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message23printCPStackAsAbsoluteGEhPKcbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4595:
	.section	.text$_ZN3dbg17category_reservedILh8ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_reservedILh8ELb1ELb1EED2Ev
	.def	__ZN3dbg17category_reservedILh8ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_reservedILh8ELb1ELb1EED2Ev:
LFB4598:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4598:
	.section .rdata,"dr"
LC50:
	.ascii "forReserved01\0"
	.section	.text$_ZN3dbg3ext22category_forReserved01C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg3ext22category_forReserved01C1Ev
	.def	__ZN3dbg3ext22category_forReserved01C1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg3ext22category_forReserved01C1Ev:
LFB4601:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC50, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg17category_reservedILh8ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4601:
	.section	.text$_ZN3dbg17category_reservedILh9ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_reservedILh9ELb1ELb1EED2Ev
	.def	__ZN3dbg17category_reservedILh9ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_reservedILh9ELb1ELb1EED2Ev:
LFB4604:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4604:
	.section .rdata,"dr"
LC51:
	.ascii "forReserved02\0"
	.section	.text$_ZN3dbg3ext22category_forReserved02C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg3ext22category_forReserved02C1Ev
	.def	__ZN3dbg3ext22category_forReserved02C1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg3ext22category_forReserved02C1Ev:
LFB4607:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC51, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg17category_reservedILh9ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4607:
	.section	.text$_ZN3dbg17category_reservedILh10ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_reservedILh10ELb1ELb1EED2Ev
	.def	__ZN3dbg17category_reservedILh10ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_reservedILh10ELb1ELb1EED2Ev:
LFB4610:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8categoryD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4610:
	.section .rdata,"dr"
LC52:
	.ascii "forReserved03\0"
	.section	.text$_ZN3dbg3ext22category_forReserved03C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg3ext22category_forReserved03C1Ev
	.def	__ZN3dbg3ext22category_forReserved03C1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg3ext22category_forReserved03C1Ev:
LFB4613:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC52, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg17category_reservedILh10ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4613:
	.section	.text$_ZN3dbg3ext22category_forReserved01D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg3ext22category_forReserved01D1Ev
	.def	__ZN3dbg3ext22category_forReserved01D1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg3ext22category_forReserved01D1Ev:
LFB4617:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_reservedILh8ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4617:
	.section	.text$_ZN3dbg3ext22category_forReserved02D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg3ext22category_forReserved02D1Ev
	.def	__ZN3dbg3ext22category_forReserved02D1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg3ext22category_forReserved02D1Ev:
LFB4620:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_reservedILh9ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4620:
	.section	.text$_ZN3dbg3ext22category_forReserved03D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg3ext22category_forReserved03D1Ev
	.def	__ZN3dbg3ext22category_forReserved03D1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg3ext22category_forReserved03D1Ev:
LFB4623:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg17category_reservedILh10ELb1ELb1EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4623:
	.section	.text$_ZN3dbg3ext20categoryContainerExtC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg3ext20categoryContainerExtC1Ev
	.def	__ZN3dbg3ext20categoryContainerExtC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg3ext20categoryContainerExtC1Ev:
LFB4625:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$72, %esp
	call	__ZN3dbg8category9container14initializeOnceEv
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg3ext22category_forReserved01C1Ev
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg3ext22category_forReserved01D1Ev
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg3ext22category_forReserved02C1Ev
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg3ext22category_forReserved02D1Ev
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg3ext22category_forReserved03C1Ev
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg3ext22category_forReserved03D1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4625:
.lcomm __ZN3dbg3extL23s_categoryForInitializeE,1,1
	.section .rdata,"dr"
	.align 4
LC53:
	.ascii "---------- printCommon() ----------\0"
LC54:
	.ascii "logLevel=%s, noticeLevel=%s\12\0"
LC55:
	.ascii "\343\203\206\343\202\271\343\203\210\0"
LC56:
	.ascii "\351\200\232\345\270\270\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC57:
	.ascii "\345\206\227\351\225\267\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC58:
	.ascii "\350\251\263\347\264\260\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC59:
	.ascii "\351\207\215\350\246\201\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC60:
	.ascii "\350\255\246\345\221\212\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC61:
	.ascii "\351\207\215\345\244\247\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC62:
	.ascii "\347\265\266\345\257\276\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
	.align 4
LC63:
	.ascii "\343\200\220\343\203\255\343\202\260\345\207\272\345\212\233\345\260\202\347\224\250\343\200\221\351\207\215\345\244\247\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
	.align 4
LC64:
	.ascii "\343\200\220\347\224\273\351\235\242\351\200\232\347\237\245\345\260\202\347\224\250\343\200\221\351\207\215\345\244\247\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
	.text
	.globl	__Z11printCommonv
	.def	__Z11printCommonv;	.scl	2;	.type	32;	.endef
__Z11printCommonv:
LFB4626:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4626
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	$LC53, (%esp)
LEHB74:
	call	_puts
	movl	$0, (%esp)
	call	__ZN3dbg11getLogLevelEh
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelC1Eh
LEHE74:
	movl	$0, (%esp)
LEHB75:
	call	__ZN3dbg14getNoticeLevelEh
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelC1Eh
LEHE75:
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level4nameEv
	movl	%eax, %ebx
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level4nameEv
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC54, (%esp)
LEHB76:
	call	_printf
	movl	$LC55, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC56, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL13printAsNormalEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC57, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL14printAsVerboseEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC58, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL13printAsDetailEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC59, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL16printAsImportantEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC60, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL14printAsWarningEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC61, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL15printAsCriticalEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC62, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL15printAsAbsoluteEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$LC56, 8(%esp)
	movl	$0, 4(%esp)
	movl	$2, (%esp)
	call	__ZN3dbgL5printEhhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC63, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL13logAsCriticalEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC64, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL16noticeAsCriticalEhPKcz
LEHE76:
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD1Ev
	jmp	L816
L815:
	movl	%eax, %ebx
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD1Ev
	jmp	L811
L814:
	movl	%eax, %ebx
L811:
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD1Ev
	movl	%ebx, %eax
	jmp	L812
L813:
L812:
	movl	%eax, (%esp)
LEHB77:
	call	__Unwind_Resume
LEHE77:
L816:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4626:
	.section	.gcc_except_table,"w"
LLSDA4626:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4626-LLSDACSB4626
LLSDACSB4626:
	.uleb128 LEHB74-LFB4626
	.uleb128 LEHE74-LEHB74
	.uleb128 L813-LFB4626
	.uleb128 0
	.uleb128 LEHB75-LFB4626
	.uleb128 LEHE75-LEHB75
	.uleb128 L814-LFB4626
	.uleb128 0
	.uleb128 LEHB76-LFB4626
	.uleb128 LEHE76-LEHB76
	.uleb128 L815-LFB4626
	.uleb128 0
	.uleb128 LEHB77-LFB4626
	.uleb128 LEHE77-LEHB77
	.uleb128 0
	.uleb128 0
LLSDACSE4626:
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC65:
	.ascii "call_point.cpp(2274)[Fri Feb 28 19:24:11 2014]\0"
LC66:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "1\0"
LC67:
	.ascii "\343\203\206\343\202\271\343\203\210\345\207\246\347\220\206\0"
LC68:
	.ascii "print:\343\203\206\343\202\271\343\203\210\357\274\210%d\357\274\211\12\0"
LC69:
	.ascii "log:\343\203\206\343\202\271\343\203\210\357\274\210%d\357\274\211\12\0"
LC70:
	.ascii "notice:\343\203\206\343\202\271\343\203\210\357\274\210%d\357\274\211\12\0"
	.align 4
LC71:
	.ascii "name=\"%s\", srcFile=\"%s\", funcName=\"%s\"\12\0"
	.align 4
LC72:
	.ascii "call_point.cpp(2284)[Fri Feb 28 19:24:11 2014]\0"
LC73:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "2\0"
LC74:
	.ascii "TEST1!\0"
LC75:
	.ascii "TEST2!\0"
LC76:
	.ascii "TEST3!\0"
LC77:
	.ascii "TEST4!\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB4627:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4627
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$528, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	call	___main
LEHB78:
	call	__ZN3dbg13printLevelAllEv
	call	__ZN3dbg16printCategoryAllEv
	call	__Z11printCommonv
	movl	$64, 4(%esp)
	movl	$1, (%esp)
	call	__ZN3dbg11setLogLevelEhh
	movl	$64, 4(%esp)
	movl	$1, (%esp)
	call	__ZN3dbg14setNoticeLevelEhh
	call	__Z11printCommonv
LEHE78:
	movl	$LC65, %eax
	movl	$__ZZ4mainE19__PRETTY_FUNCTION__, 24(%esp)
	movl	$LC65, 20(%esp)
	movl	%eax, 16(%esp)
	movl	$LC66, 12(%esp)
	movl	$3, 8(%esp)
	movl	$1, 4(%esp)
	leal	192(%esp), %eax
	movl	%eax, (%esp)
LEHB79:
	call	__ZN3dbg9callPointC1EhhPKcjS2_S2_
LEHE79:
	movl	$0, 20(%esp)
	movl	$0, 16(%esp)
	movl	$LC67, 12(%esp)
	movl	$8, 8(%esp)
	movl	$8, 4(%esp)
	leal	40(%esp), %eax
	movl	%eax, (%esp)
LEHB80:
	call	__ZN3dbg7messageC1EhhPKcS2_S2_
LEHE80:
	movl	$1, 8(%esp)
	movl	$LC68, 4(%esp)
	leal	40(%esp), %eax
	movl	%eax, (%esp)
LEHB81:
	call	__ZN3dbg7message13printAsNormalEPKcz
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message16resetLogLevelAllEv
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message19resetNoticeLevelAllEv
	movl	$2, 8(%esp)
	movl	$LC68, 4(%esp)
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message13printAsNormalEPKcz
	movl	$3, 8(%esp)
	movl	$LC69, 4(%esp)
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message3logEPKcz
	movl	$4, 8(%esp)
	movl	$LC70, 4(%esp)
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message6noticeEPKcz
	leal	192(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message11getFuncNameEv
	movl	%eax, %esi
	leal	192(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message14getSrcFileNameEv
	movl	%eax, %ebx
	leal	192(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message7getNameEv
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$LC71, 4(%esp)
	leal	192(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message11logAsNormalEPKcz
LEHE81:
	movl	$LC72, %eax
	movl	$__ZZ4mainE19__PRETTY_FUNCTION__, 24(%esp)
	movl	$LC72, 20(%esp)
	movl	%eax, 16(%esp)
	movl	$LC73, 12(%esp)
	movl	$4, 8(%esp)
	movl	$2, 4(%esp)
	leal	360(%esp), %eax
	movl	%eax, (%esp)
LEHB82:
	call	__ZN3dbg9callPointC1EhhPKcjS2_S2_
LEHE82:
	movl	$1, 16(%esp)
	movl	$1, 12(%esp)
	movl	$LC74, 8(%esp)
	movl	$0, 4(%esp)
	movl	$8, (%esp)
LEHB83:
	call	__ZN3dbg12printCPStackEhhPKcbb
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	$LC75, 8(%esp)
	movl	$0, 4(%esp)
	movl	$2, (%esp)
	call	__ZN3dbg12printCPStackEhhPKcbb
	movl	$0, 16(%esp)
	movl	$1, 12(%esp)
	movl	$LC76, 8(%esp)
	movl	$0, 4(%esp)
	movl	$6, (%esp)
	call	__ZN3dbg12printCPStackEhhPKcbb
	movl	$1, 16(%esp)
	movl	$0, 12(%esp)
	movl	$LC77, 8(%esp)
	movl	$0, 4(%esp)
	movl	$10, (%esp)
	call	__ZN3dbg12printCPStackEhhPKcbb
LEHE83:
	leal	360(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg9callPointD1Ev
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7messageD1Ev
	leal	192(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg9callPointD1Ev
	movl	$64, 4(%esp)
	movl	$12, (%esp)
LEHB84:
	call	__ZN3dbg11setLogLevelEhh
	movl	$64, 4(%esp)
	movl	$12, (%esp)
	call	__ZN3dbg14setNoticeLevelEhh
	call	__Z11printCommonv
	call	__ZN3dbg16resetLogLevelAllEv
	call	__ZN3dbg19resetNoticeLevelAllEv
	call	__Z11printCommonv
LEHE84:
	leal	360(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7messageC1Ev
	movl	$4, (%esp)
LEHB85:
	call	__ZN3dbg7message12getLogLevelGEh
	movl	$4, 4(%esp)
	leal	360(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message11getLogLevelEh
LEHE85:
	movl	$0, %ebx
	leal	360(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7messageD1Ev
	movl	%ebx, %eax
	jmp	L833
L831:
	movl	%eax, %ebx
	leal	360(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg9callPointD1Ev
	movl	%ebx, %eax
	jmp	L820
L830:
L820:
	movl	%eax, %ebx
	jmp	L821
L829:
	movl	%eax, %ebx
L821:
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7messageD1Ev
	jmp	L822
L828:
	movl	%eax, %ebx
L822:
	leal	192(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg9callPointD1Ev
	movl	%ebx, %eax
	jmp	L824
L827:
	jmp	L824
L832:
	movl	%eax, %ebx
	leal	360(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7messageD1Ev
	movl	%ebx, %eax
	jmp	L824
L826:
L824:
	movl	%eax, (%esp)
LEHB86:
	call	__Unwind_Resume
LEHE86:
L833:
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4627:
	.section	.gcc_except_table,"w"
LLSDA4627:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4627-LLSDACSB4627
LLSDACSB4627:
	.uleb128 LEHB78-LFB4627
	.uleb128 LEHE78-LEHB78
	.uleb128 L826-LFB4627
	.uleb128 0
	.uleb128 LEHB79-LFB4627
	.uleb128 LEHE79-LEHB79
	.uleb128 L827-LFB4627
	.uleb128 0
	.uleb128 LEHB80-LFB4627
	.uleb128 LEHE80-LEHB80
	.uleb128 L828-LFB4627
	.uleb128 0
	.uleb128 LEHB81-LFB4627
	.uleb128 LEHE81-LEHB81
	.uleb128 L829-LFB4627
	.uleb128 0
	.uleb128 LEHB82-LFB4627
	.uleb128 LEHE82-LEHB82
	.uleb128 L830-LFB4627
	.uleb128 0
	.uleb128 LEHB83-LFB4627
	.uleb128 LEHE83-LEHB83
	.uleb128 L831-LFB4627
	.uleb128 0
	.uleb128 LEHB84-LFB4627
	.uleb128 LEHE84-LEHB84
	.uleb128 L826-LFB4627
	.uleb128 0
	.uleb128 LEHB85-LFB4627
	.uleb128 LEHE85-LEHB85
	.uleb128 L832-LFB4627
	.uleb128 0
	.uleb128 LEHB86-LFB4627
	.uleb128 LEHE86-LEHB86
	.uleb128 0
	.uleb128 0
LLSDACSE4627:
	.text
	.section	.text$_ZNSt6bitsetILj14EEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EEixEj
	.def	__ZNSt6bitsetILj14EEixEj;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EEixEj:
LFB4664:
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
LFE4664:
	.section	.text$_ZNSt6bitsetILj14EE9referenceD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE9referenceD1Ev
	.def	__ZNSt6bitsetILj14EE9referenceD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE9referenceD1Ev:
LFB4667:
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
LFE4667:
	.section	.text$_ZNKSt6bitsetILj14EE9referencecvbEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6bitsetILj14EE9referencecvbEv
	.def	__ZNKSt6bitsetILj14EE9referencecvbEv;	.scl	2;	.type	32;	.endef
__ZNKSt6bitsetILj14EE9referencecvbEv:
LFB4668:
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
LFE4668:
	.section	.text$_ZNSt6bitsetILj14EE9referenceaSEb,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE9referenceaSEb
	.def	__ZNSt6bitsetILj14EE9referenceaSEb;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE9referenceaSEb:
LFB4669:
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
	je	L841
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
	jmp	L842
L841:
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
L842:
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4669:
	.section	.text$_ZN3dbg12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc
	.def	__ZN3dbg12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc:
LFB4671:
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
	call	__ZN3dbg5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4671:
	.section	.text$_ZN3dbg12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc
	.def	__ZN3dbg12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc:
LFB4674:
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
	call	__ZN3dbg5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4674:
	.section	.text$_ZN3dbg12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc
	.def	__ZN3dbg12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc:
LFB4677:
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
	call	__ZN3dbg5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4677:
	.section	.text$_ZN3dbg12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc
	.def	__ZN3dbg12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc:
LFB4680:
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
	call	__ZN3dbg5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4680:
	.section	.text$_ZN3dbg12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc
	.def	__ZN3dbg12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc:
LFB4683:
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
	call	__ZN3dbg5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4683:
	.section	.text$_ZN3dbg12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc
	.def	__ZN3dbg12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc:
LFB4686:
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
	call	__ZN3dbg5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4686:
	.section	.text$_ZN3dbg12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc
	.def	__ZN3dbg12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc:
LFB4689:
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
	call	__ZN3dbg5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4689:
	.section	.text$_ZN3dbg13level_specialILh11EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg13level_specialILh11EEC2EPKc
	.def	__ZN3dbg13level_specialILh11EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg13level_specialILh11EEC2EPKc:
LFB4692:
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
	call	__ZN3dbg5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4692:
	.section	.text$_ZN3dbg13level_specialILh12EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg13level_specialILh12EEC2EPKc
	.def	__ZN3dbg13level_specialILh12EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg13level_specialILh12EEC2EPKc:
LFB4695:
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
	call	__ZN3dbg5levelC2EhPKcbbbNS_5color7color_tES4_S4_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4695:
	.section	.text$_ZNSt6bitsetILj14EE5resetEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE5resetEv
	.def	__ZNSt6bitsetILj14EE5resetEv;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE5resetEv:
LFB4697:
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
LFE4697:
	.section	.text$_ZNSt6bitsetILj68EEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EEixEj
	.def	__ZNSt6bitsetILj68EEixEj;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EEixEj:
LFB4698:
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
LFE4698:
	.section	.text$_ZNSt6bitsetILj68EE9referenceD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE9referenceD1Ev
	.def	__ZNSt6bitsetILj68EE9referenceD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE9referenceD1Ev:
LFB4701:
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
LFE4701:
	.section	.text$_ZNSt12_Base_bitsetILj3EE11_S_whichbitEj,"x"
	.linkonce discard
	.globl	__ZNSt12_Base_bitsetILj3EE11_S_whichbitEj
	.def	__ZNSt12_Base_bitsetILj3EE11_S_whichbitEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE11_S_whichbitEj:
LFB4704:
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
LFE4704:
	.section	.text$_ZNSt12_Base_bitsetILj3EE10_S_maskbitEj,"x"
	.linkonce discard
	.globl	__ZNSt12_Base_bitsetILj3EE10_S_maskbitEj
	.def	__ZNSt12_Base_bitsetILj3EE10_S_maskbitEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE10_S_maskbitEj:
LFB4703:
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
LFE4703:
	.section	.text$_ZNKSt6bitsetILj68EE9referencecvbEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6bitsetILj68EE9referencecvbEv
	.def	__ZNKSt6bitsetILj68EE9referencecvbEv;	.scl	2;	.type	32;	.endef
__ZNKSt6bitsetILj68EE9referencecvbEv:
LFB4702:
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
LFE4702:
	.section	.text$_ZNSt6bitsetILj68EE9referenceaSEb,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE9referenceaSEb
	.def	__ZNSt6bitsetILj68EE9referenceaSEb;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE9referenceaSEb:
LFB4705:
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
	je	L866
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
	jmp	L867
L866:
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
L867:
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4705:
	.section	.text$_ZN3dbg17category_assignedILh0ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh0ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh0ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh0ELb1ELb1EEC2EPKc:
LFB4707:
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
	call	__ZN3dbg8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4707:
	.section	.text$_ZN3dbg17category_assignedILh1ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh1ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh1ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh1ELb1ELb1EEC2EPKc:
LFB4710:
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
	call	__ZN3dbg8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4710:
	.section	.text$_ZN3dbg17category_assignedILh2ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh2ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh2ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh2ELb1ELb1EEC2EPKc:
LFB4713:
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
	call	__ZN3dbg8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4713:
	.section	.text$_ZN3dbg17category_assignedILh3ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh3ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh3ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh3ELb1ELb1EEC2EPKc:
LFB4716:
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
	call	__ZN3dbg8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4716:
	.section	.text$_ZN3dbg17category_assignedILh4ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh4ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh4ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh4ELb1ELb1EEC2EPKc:
LFB4719:
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
	call	__ZN3dbg8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4719:
	.section	.text$_ZN3dbg17category_assignedILh5ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh5ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh5ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh5ELb1ELb1EEC2EPKc:
LFB4722:
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
	call	__ZN3dbg8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4722:
	.section	.text$_ZN3dbg17category_assignedILh6ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh6ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh6ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh6ELb1ELb1EEC2EPKc:
LFB4725:
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
	call	__ZN3dbg8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4725:
	.section	.text$_ZN3dbg17category_assignedILh7ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh7ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh7ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh7ELb1ELb1EEC2EPKc:
LFB4728:
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
	call	__ZN3dbg8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4728:
	.section	.text$_ZN3dbg16category_specialILh64ELb0ELb0ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg16category_specialILh64ELb0ELb0ELb1EEC2EPKc
	.def	__ZN3dbg16category_specialILh64ELb0ELb0ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg16category_specialILh64ELb0ELb0ELb1EEC2EPKc:
LFB4731:
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
	call	__ZN3dbg8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4731:
	.section	.text$_ZN3dbg16category_specialILh65ELb1ELb1ELb0EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg16category_specialILh65ELb1ELb1ELb0EEC2EPKc
	.def	__ZN3dbg16category_specialILh65ELb1ELb1ELb0EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg16category_specialILh65ELb1ELb1ELb0EEC2EPKc:
LFB4734:
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
	call	__ZN3dbg8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4734:
	.section	.text$_ZN3dbg16category_specialILh66ELb1ELb1ELb0EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg16category_specialILh66ELb1ELb1ELb0EEC2EPKc
	.def	__ZN3dbg16category_specialILh66ELb1ELb1ELb0EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg16category_specialILh66ELb1ELb1ELb0EEC2EPKc:
LFB4737:
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
	call	__ZN3dbg8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4737:
	.section	.text$_ZNSt6bitsetILj68EE5resetEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE5resetEv
	.def	__ZNSt6bitsetILj68EE5resetEv;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE5resetEv:
LFB4739:
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
LFE4739:
	.section	.text$_ZN3dbg17category_reservedILh8ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_reservedILh8ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_reservedILh8ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_reservedILh8ELb1ELb1EEC2EPKc:
LFB4741:
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
	call	__ZN3dbg8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4741:
	.section	.text$_ZN3dbg17category_reservedILh9ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_reservedILh9ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_reservedILh9ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_reservedILh9ELb1ELb1EEC2EPKc:
LFB4744:
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
	call	__ZN3dbg8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4744:
	.section	.text$_ZN3dbg17category_reservedILh10ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_reservedILh10ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_reservedILh10ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_reservedILh10ELb1ELb1EEC2EPKc:
LFB4747:
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
	call	__ZN3dbg8categoryC2EhPKcbbbb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4747:
	.section	.text$_ZNSt6bitsetILj14EE9referenceC1ERS0_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE9referenceC1ERS0_j
	.def	__ZNSt6bitsetILj14EE9referenceC1ERS0_j;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE9referenceC1ERS0_j:
LFB4772:
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
LFE4772:
	.section	.text$_ZNSt6bitsetILj68EE9referenceC1ERS0_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE9referenceC1ERS0_j
	.def	__ZNSt6bitsetILj68EE9referenceC1ERS0_j;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE9referenceC1ERS0_j:
LFB4775:
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
LFE4775:
	.section	.text$_ZNSt12_Base_bitsetILj3EE11_M_do_resetEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Base_bitsetILj3EE11_M_do_resetEv
	.def	__ZNSt12_Base_bitsetILj3EE11_M_do_resetEv;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE11_M_do_resetEv:
LFB4776:
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
LFE4776:
	.section	.text$_ZNSt12_Base_bitsetILj3EE12_S_whichwordEj,"x"
	.linkonce discard
	.globl	__ZNSt12_Base_bitsetILj3EE12_S_whichwordEj
	.def	__ZNSt12_Base_bitsetILj3EE12_S_whichwordEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE12_S_whichwordEj:
LFB4787:
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
LFE4787:
	.section	.text$_ZNSt12_Base_bitsetILj3EE10_M_getwordEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Base_bitsetILj3EE10_M_getwordEj
	.def	__ZNSt12_Base_bitsetILj3EE10_M_getwordEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE10_M_getwordEj:
LFB4786:
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
LFE4786:
	.text
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB4799:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L893
	cmpl	$65535, 12(%ebp)
	jne	L893
	call	___getreent
	movl	8(%eax), %eax
	movl	%eax, __ZN3dbg5color8m_handleE
	call	___getreent
	movl	12(%eax), %eax
	movl	%eax, __ZN3dbg5color8m_handleE+4
	movl	$__ZN3dbgL20s_colorForInitializeE, (%esp)
	call	__ZN3dbg5colorC1Ev
	movl	$__ZN3dbgL20s_levelForInitializeE, (%esp)
	call	__ZN3dbg5levelC1Ev
	movl	$__ZN3dbgL23s_categoryForInitializeE, (%esp)
	call	__ZN3dbg8categoryC1Ev
	movl	$__ZN3dbgL22s_messageForInitializeE, (%esp)
	call	__ZN3dbg7messageC1Ev
	movl	$__ZN3dbg3extL23s_categoryForInitializeE, (%esp)
	call	__ZN3dbg3ext20categoryContainerExtC1Ev
L893:
	cmpl	$0, 8(%ebp)
	jne	L892
	cmpl	$65535, 12(%ebp)
	jne	L892
	movl	$__ZN3dbgL22s_messageForInitializeE, (%esp)
	call	__ZN3dbg7messageD1Ev
	movl	$__ZN3dbgL23s_categoryForInitializeE, (%esp)
	call	__ZN3dbg8categoryD1Ev
	movl	$__ZN3dbgL20s_levelForInitializeE, (%esp)
	call	__ZN3dbg5levelD1Ev
	movl	$__ZN3dbgL20s_colorForInitializeE, (%esp)
	call	__ZN3dbg5colorD1Ev
L892:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4799:
	.def	__GLOBAL__sub_I__Z11getFileNamePKc;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z11getFileNamePKc:
LFB4800:
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
LFE4800:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z11getFileNamePKc
	.text
	.def	__GLOBAL__sub_D__Z11getFileNamePKc;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_D__Z11getFileNamePKc:
LFB4801:
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
LFE4801:
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__sub_D__Z11getFileNamePKc
	.section .rdata,"dr"
	.align 32
__ZZN3dbg5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_E19__PRETTY_FUNCTION__:
	.ascii "dbg::level::level(dbg::level::value_t, const char*, bool, bool, bool, dbg::color::color_t, dbg::color::color_t, dbg::color::color_t, dbg::color::color_t)\0"
	.align 32
__ZZN3dbg8categoryC1EhPKcbbbbE19__PRETTY_FUNCTION__:
	.ascii "dbg::category::category(dbg::category::value_t, const char*, bool, bool, bool, bool)\0"
	.align 32
__ZZN3dbg7message12getLogLevelGEhE19__PRETTY_FUNCTION__:
	.ascii "static dbg::level::value_t dbg::message::getLogLevelG(dbg::category::value_t)\0"
	.align 32
__ZZN3dbg7message12setLogLevelGEhhE19__PRETTY_FUNCTION__:
	.ascii "static dbg::level::value_t dbg::message::setLogLevelG(dbg::level::value_t, dbg::category::value_t)\0"
	.align 32
__ZZN3dbg7message15getNoticeLevelGEhE19__PRETTY_FUNCTION__:
	.ascii "static dbg::level::value_t dbg::message::getNoticeLevelG(dbg::category::value_t)\0"
	.align 32
__ZZN3dbg7message15setNoticeLevelGEhhE19__PRETTY_FUNCTION__:
	.ascii "static dbg::level::value_t dbg::message::setNoticeLevelG(dbg::level::value_t, dbg::category::value_t)\0"
	.align 32
__ZZN3dbg7message19isValidTempLogLevelEhE19__PRETTY_FUNCTION__:
	.ascii "bool dbg::message::isValidTempLogLevel(dbg::category::value_t)\0"
	.align 32
__ZZN3dbg7message22isValidTempNoticeLevelEhE19__PRETTY_FUNCTION__:
	.ascii "bool dbg::message::isValidTempNoticeLevel(dbg::category::value_t)\0"
	.align 32
__ZZN3dbg7message12isAllowPrintERbS1_hhhhE19__PRETTY_FUNCTION__:
	.ascii "static void dbg::message::isAllowPrint(bool&, bool&, dbg::level::value_t, dbg::level::value_t, dbg::level::value_t, dbg::category::value_t)\0"
	.align 32
__ZZN3dbg5levelC1EhE19__PRETTY_FUNCTION__:
	.ascii "dbg::level::level(dbg::level::value_t)\0"
__ZZ4mainE19__PRETTY_FUNCTION__:
	.ascii "int main(int, const char**)\0"
	.align 32
__ZZN3dbg7messageC1EhhPKcS2_S2_E19__PRETTY_FUNCTION__:
	.ascii "dbg::message::message(dbg::level::value_t, dbg::category::value_t, const char*, const char*, const char*)\0"
	.align 32
__ZZN3dbg7message11setLogLevelEhhE19__PRETTY_FUNCTION__:
	.ascii "dbg::level::value_t dbg::message::setLogLevel(dbg::level::value_t, dbg::category::value_t)\0"
	.align 32
__ZZN3dbg7message14setNoticeLevelEhhE19__PRETTY_FUNCTION__:
	.ascii "dbg::level::value_t dbg::message::setNoticeLevel(dbg::level::value_t, dbg::category::value_t)\0"
	.align 32
__ZZN3dbg7message13pushCallPointEvE19__PRETTY_FUNCTION__:
	.ascii "void dbg::message::pushCallPoint()\0"
	.align 32
__ZZN3dbg7message12popCallPointEvE19__PRETTY_FUNCTION__:
	.ascii "void dbg::message::popCallPoint()\0"
	.align 4
___emutls_t._ZN3dbg7message17m_messageBuffUsedE:
	.space 4
	.globl	___emutls_v._ZN3dbg7message17m_messageBuffUsedE
	.data
	.align 4
___emutls_v._ZN3dbg7message17m_messageBuffUsedE:
	.long	4
	.long	4
	.long	0
	.long	___emutls_t._ZN3dbg7message17m_messageBuffUsedE
	.section .rdata,"dr"
	.align 4
___emutls_t._ZN3dbg7message17m_messageBuffSizeE:
	.space 4
	.globl	___emutls_v._ZN3dbg7message17m_messageBuffSizeE
	.data
	.align 4
___emutls_v._ZN3dbg7message17m_messageBuffSizeE:
	.long	4
	.long	4
	.long	0
	.long	___emutls_t._ZN3dbg7message17m_messageBuffSizeE
	.section .rdata,"dr"
	.align 4
___emutls_t._ZN3dbg7message13m_messageBuffE:
	.space 4
	.globl	___emutls_v._ZN3dbg7message13m_messageBuffE
	.data
	.align 4
___emutls_v._ZN3dbg7message13m_messageBuffE:
	.long	4
	.long	4
	.long	0
	.long	___emutls_t._ZN3dbg7message13m_messageBuffE
	.section .rdata,"dr"
	.align 4
___emutls_t._ZN3dbg7message20m_callPointStackHeadE:
	.space 4
	.globl	___emutls_v._ZN3dbg7message20m_callPointStackHeadE
	.data
	.align 4
___emutls_v._ZN3dbg7message20m_callPointStackHeadE:
	.long	4
	.long	4
	.long	0
	.long	___emutls_t._ZN3dbg7message20m_callPointStackHeadE
	.ident	"GCC: (GNU) 4.8.2"
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_fwrite;	.scl	2;	.type	32;	.endef
	.def	_fprintf;	.scl	2;	.type	32;	.endef
	.def	_memcpy;	.scl	2;	.type	32;	.endef
	.def	___assert_func;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef
	.def	___getreent;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	___emutls_get_address;	.scl	2;	.type	32;	.endef
	.def	___real__Znaj;	.scl	2;	.type	32;	.endef
	.def	__Znaj;	.scl	2;	.type	32;	.endef
	.def	___real__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	_vsprintf;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6chrono3_V212system_clock3nowEv;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef

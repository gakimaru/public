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
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	addl	%edx, %eax
	movl	%eax, -16(%ebp)
	jmp	L9
L13:
	movl	-16(%ebp), %eax
	subl	$1, %eax
	movzbl	(%eax), %eax
	movb	%al, -17(%ebp)
	cmpb	$92, -17(%ebp)
	je	L10
	cmpb	$47, -17(%ebp)
	jne	L11
L10:
	movl	-16(%ebp), %eax
	jmp	L12
L11:
	subl	$1, -12(%ebp)
	subl	$1, -16(%ebp)
L9:
	cmpl	$0, -12(%ebp)
	jne	L13
	movl	8(%ebp), %eax
L12:
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
	jne	L15
	jmp	L14
L15:
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
L14:
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
	jne	L18
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$10, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC0, (%esp)
	call	_fwrite
	jmp	L17
L18:
	movzbl	-36(%ebp), %eax
	andl	$8, %eax
	testl	%eax, %eax
	je	L20
	movl	$100, %eax
	jmp	L21
L20:
	movl	$40, %eax
L21:
	movzbl	-36(%ebp), %edx
	andl	$7, %edx
	addl	%eax, %edx
	movzbl	-32(%ebp), %eax
	andl	$8, %eax
	testl	%eax, %eax
	je	L22
	movl	$90, %eax
	jmp	L23
L22:
	movl	$30, %eax
L23:
	movzbl	-32(%ebp), %ecx
	andl	$7, %ecx
	addl	%ecx, %eax
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
L17:
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
	je	L27
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L28
L27:
	jmp	L26
L28:
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
L26:
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
	je	L30
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	jne	L30
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
L30:
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
	je	L33
	jmp	L32
L33:
	movb	$1, __ZN3dbg5color15m_isInitializedE
L32:
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
	jb	L40
	call	__ZN3dbg5level9container6getEndEv
	jmp	L41
L40:
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
L41:
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
	je	L55
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
L55:
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
	je	L88
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level13valueAsOutputEv
	cmpb	$5, %al
	ja	L88
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L89
	movl	8(%ebp), %eax
	movzbl	6(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L89
L88:
	movl	$1, %eax
	jmp	L90
L89:
	movl	$0, %eax
L90:
	testb	%al, %al
	je	L91
	movl	__ZN3dbg5level9container9m_poolPtrE, %ecx
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	jmp	L92
L91:
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
L92:
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
	ja	L94
	movl	8(%ebp), %eax
	movzbl	5(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L95
	movl	8(%ebp), %eax
	movzbl	6(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L95
L94:
	movl	$1, %eax
	jmp	L96
L95:
	movl	$0, %eax
L96:
	testb	%al, %al
	je	L97
	movl	__ZN3dbg5level9container9m_poolPtrE, %ecx
	movl	8(%ebp), %eax
	movzbl	4(%eax), %eax
	movzbl	%al, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	jmp	L98
L97:
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
L98:
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
	jbe	L101
	movl	$LC2, 12(%esp)
	movl	$__ZZN3dbg5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_E19__PRETTY_FUNCTION__, 8(%esp)
	movl	$504, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L101:
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
	jbe	L103
	movl	$LC2, 12(%esp)
	movl	$__ZZN3dbg5levelC1EhPKcbbbNS_5color7color_tES4_S4_S4_E19__PRETTY_FUNCTION__, 8(%esp)
	movl	$504, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L103:
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
	jbe	L105
	movl	$LC2, 12(%esp)
	movl	$__ZZN3dbg5levelC1EhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$518, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L105:
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
	je	L159
	jmp	L158
L159:
	movb	$1, __ZN3dbg5level9container15m_isInitializedE
	movl	$__ZN3dbg5level9container15m_isAlreadyPoolE, (%esp)
	call	__ZNSt6bitsetILj14EE5resetEv
	movl	$168, 8(%esp)
	movl	$0, 4(%esp)
	movl	$__ZN3dbg5level9container6m_poolE, (%esp)
	call	_memset
	movl	$__ZN3dbg5level9container6m_poolE, __ZN3dbg5level9container9m_poolPtrE
	movb	$0, -9(%ebp)
	jmp	L161
L162:
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
L161:
	cmpb	$12, -9(%ebp)
	jbe	L162
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
L158:
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
	jmp	L164
L165:
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
L164:
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
	jne	L165
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level8iteratorD1Ev
	leal	-43(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level8iteratorD1Ev
	jmp	L170
L169:
	movl	%eax, %ebx
	leal	-50(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5colorD1Ev
	movl	%ebx, %eax
	jmp	L167
L168:
L167:
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
L170:
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
	.uleb128 L168-LFB4100
	.uleb128 0
	.uleb128 LEHB1-LFB4100
	.uleb128 LEHE1-LEHB1
	.uleb128 L169-LFB4100
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
	jb	L176
	call	__ZN3dbg8category9container6getEndEv
	jmp	L177
L176:
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
L177:
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
	je	L191
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
L191:
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
	jbe	L217
	movl	$LC2, 12(%esp)
	movl	$__ZZN3dbg8categoryC1EhPKcbbbbE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$860, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L217:
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
	jbe	L219
	movl	$LC2, 12(%esp)
	movl	$__ZZN3dbg8categoryC1EhPKcbbbbE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$860, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L219:
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
	je	L283
	jmp	L282
L283:
	movb	$1, __ZN3dbg8category9container15m_isInitializedE
	movl	$__ZN3dbg8category9container15m_isAlreadyPoolE, (%esp)
	call	__ZNSt6bitsetILj68EE5resetEv
	movl	$816, 8(%esp)
	movl	$0, 4(%esp)
	movl	$__ZN3dbg8category9container6m_poolE, (%esp)
	call	_memset
	movl	$__ZN3dbg8category9container6m_poolE, __ZN3dbg8category9container9m_poolPtrE
	movb	$0, -9(%ebp)
	jmp	L285
L286:
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
L285:
	cmpb	$66, -9(%ebp)
	jbe	L286
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
L282:
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
	jmp	L288
L289:
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
L288:
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
	jne	L289
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category8iteratorD1Ev
	leal	-35(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category8iteratorD1Ev
	jmp	L292
L291:
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
L292:
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
	.uleb128 L291-LFB4285
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
	.section	.text$_ZNK3dbg7message11getFuncnameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK3dbg7message11getFuncnameEv
	.def	__ZNK3dbg7message11getFuncnameEv;	.scl	2;	.type	32;	.endef
__ZNK3dbg7message11getFuncnameEv:
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
	.section	.text$_ZN3dbg7message20adjustProperCategoryEh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message20adjustProperCategoryEh
	.def	__ZN3dbg7message20adjustProperCategoryEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message20adjustProperCategoryEh:
LFB4291:
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
	jne	L304
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L305
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message11getCategoryEv
	jmp	L306
L305:
	movl	$0, %eax
	jmp	L306
L304:
	cmpb	$66, -28(%ebp)
	jne	L307
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	jmp	L308
L310:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message8getLevelEv
	cmpb	$8, %al
	sete	%al
	testb	%al, %al
	je	L309
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message11getCategoryEv
	jmp	L306
L309:
	movl	-12(%ebp), %eax
	movl	16(%eax), %eax
	movl	%eax, -12(%ebp)
L308:
	cmpl	$0, -12(%ebp)
	jne	L310
	movl	$0, %eax
	jmp	L306
L307:
	movzbl	-28(%ebp), %eax
L306:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4291:
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
LFB4292:
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
	jne	L312
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message12getLogLevelGEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1102, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L312:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category6forLogEv
	testb	%al, %al
	jne	L313
	movl	$LC31, 12(%esp)
	movl	$__ZZN3dbg7message12getLogLevelGEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1103, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L313:
	movzbl	-28(%ebp), %eax
	movzbl	__ZN3dbg7message11m_logLevelGE(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4292:
	.section	.text$_ZN3dbg7message11getLogLevelEh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message11getLogLevelEh
	.def	__ZN3dbg7message11getLogLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message11getLogLevelEh:
LFB4293:
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
	jne	L316
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message11getLogLevelEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1110, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L316:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category6forLogEv
	testb	%al, %al
	jne	L317
	movl	$LC31, 12(%esp)
	movl	$__ZZN3dbg7message11getLogLevelEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1111, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L317:
	movzbl	-28(%ebp), %eax
	movzbl	__ZN3dbg7message11m_logLevelGE(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	movl	%eax, %ebx
	movzbl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movzbl	20(%edx,%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	cmpb	%al, %bl
	jbe	L318
	movzbl	-28(%ebp), %eax
	movzbl	__ZN3dbg7message11m_logLevelGE(%eax), %eax
	jmp	L319
L318:
	movzbl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movzbl	20(%edx,%eax), %eax
L319:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4293:
	.section	.text$_ZN3dbg7message13getLogLevelCPEh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message13getLogLevelCPEh
	.def	__ZN3dbg7message13getLogLevelCPEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message13getLogLevelCPEh:
LFB4294:
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
	movb	%al, -12(%ebp)
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L322
	movzbl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message12getLogLevelGEh
	jmp	L323
L322:
	movzbl	-12(%ebp), %ebx
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message11getLogLevelEh
L323:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4294:
	.section .rdata,"dr"
LC32:
	.ascii "o_level.forMask() == true\0"
	.section	.text$_ZN3dbg7message12setLogLevelGEhh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message12setLogLevelGEhh
	.def	__ZN3dbg7message12setLogLevelGEhh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message12setLogLevelGEhh:
LFB4295:
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
	jne	L325
	movl	$LC32, 12(%esp)
	movl	$__ZZN3dbg7message12setLogLevelGEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1129, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L325:
	movzbl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category3getEh
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category7forMaskEv
	testb	%al, %al
	jne	L326
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message12setLogLevelGEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1131, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L326:
	cmpb	$64, -48(%ebp)
	jne	L327
	movzbl	__ZN3dbg7message11m_logLevelGE, %eax
	movb	%al, -21(%ebp)
	movl	$__ZN3dbg7message11m_logLevelGE, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-28(%ebp), %eax
	addl	$64, %eax
	movl	%eax, -32(%ebp)
	jmp	L328
L329:
	movl	-12(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movzbl	-44(%ebp), %edx
	movb	%dl, (%eax)
	addl	$1, -12(%ebp)
L328:
	movl	-12(%ebp), %eax
	cmpl	-32(%ebp), %eax
	jne	L329
	movzbl	-21(%ebp), %eax
	jmp	L330
L327:
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category6forLogEv
	testb	%al, %al
	jne	L331
	movl	$LC31, 12(%esp)
	movl	$__ZZN3dbg7message12setLogLevelGEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1139, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L331:
	movzbl	-48(%ebp), %eax
	movzbl	__ZN3dbg7message11m_logLevelGE(%eax), %eax
	movb	%al, -37(%ebp)
	movzbl	-48(%ebp), %eax
	movzbl	-44(%ebp), %edx
	movb	%dl, __ZN3dbg7message11m_logLevelGE(%eax)
	movzbl	-37(%ebp), %eax
L330:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4295:
	.section	.text$_ZN3dbg7message11setLogLevelEhh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message11setLogLevelEhh
	.def	__ZN3dbg7message11setLogLevelEhh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message11setLogLevelEhh:
LFB4296:
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
	jne	L333
	movl	$LC32, 12(%esp)
	movl	$__ZZN3dbg7message11setLogLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1148, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L333:
	movzbl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category3getEh
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category7forMaskEv
	testb	%al, %al
	jne	L334
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message11setLogLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1150, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L334:
	cmpb	$64, -32(%ebp)
	jne	L335
	movl	8(%ebp), %eax
	movzbl	20(%eax), %eax
	movb	%al, -21(%ebp)
	movl	$0, -12(%ebp)
	jmp	L336
L339:
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
	jbe	L337
	movl	-12(%ebp), %eax
	addl	$__ZN3dbg7message11m_logLevelGE, %eax
	movzbl	(%eax), %eax
	jmp	L338
L337:
	movzbl	-28(%ebp), %eax
L338:
	movl	8(%ebp), %ecx
	movl	-12(%ebp), %edx
	addl	%ecx, %edx
	addl	$16, %edx
	movb	%al, 4(%edx)
	addl	$1, -12(%ebp)
L336:
	cmpl	$63, -12(%ebp)
	jle	L339
	movzbl	-21(%ebp), %eax
	jmp	L340
L335:
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category6forLogEv
	testb	%al, %al
	jne	L341
	movl	$LC31, 12(%esp)
	movl	$__ZZN3dbg7message11setLogLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1163, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L341:
	movzbl	-32(%ebp), %eax
	movl	8(%ebp), %edx
	movzbl	20(%edx,%eax), %eax
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
	jbe	L342
	movzbl	-32(%ebp), %eax
	movzbl	__ZN3dbg7message11m_logLevelGE(%eax), %eax
	jmp	L343
L342:
	movzbl	-28(%ebp), %eax
L343:
	movl	8(%ebp), %edx
	movb	%al, 20(%edx,%ebx)
	movzbl	-22(%ebp), %eax
L340:
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
LFE4296:
	.section	.text$_ZN3dbg7message14resetLogLevelGEh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message14resetLogLevelGEh
	.def	__ZN3dbg7message14resetLogLevelGEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message14resetLogLevelGEh:
LFB4297:
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
LFE4297:
	.section	.text$_ZN3dbg7message13resetLogLevelEh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message13resetLogLevelEh
	.def	__ZN3dbg7message13resetLogLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message13resetLogLevelEh:
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
LFE4298:
	.section	.text$_ZN3dbg7message17resetLogLevelAllGEv,"x"
	.linkonce discard
	.globl	__ZN3dbg7message17resetLogLevelAllGEv
	.def	__ZN3dbg7message17resetLogLevelAllGEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message17resetLogLevelAllGEv:
LFB4299:
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
	jmp	L347
L348:
	movl	-4(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movb	$2, (%eax)
	addl	$1, -4(%ebp)
L347:
	movl	-4(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jne	L348
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4299:
	.section	.text$_ZN3dbg7message16resetLogLevelAllEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message16resetLogLevelAllEv
	.def	__ZN3dbg7message16resetLogLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16resetLogLevelAllEv:
LFB4300:
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
LFE4300:
	.section .rdata,"dr"
	.align 4
LC33:
	.ascii "o_category.forNotice() == true\0"
	.section	.text$_ZN3dbg7message15getNoticeLevelGEh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message15getNoticeLevelGEh
	.def	__ZN3dbg7message15getNoticeLevelGEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message15getNoticeLevelGEh:
LFB4301:
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
	jne	L351
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message15getNoticeLevelGEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1197, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L351:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category9forNoticeEv
	testb	%al, %al
	jne	L352
	movl	$LC33, 12(%esp)
	movl	$__ZZN3dbg7message15getNoticeLevelGEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1198, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L352:
	movzbl	-28(%ebp), %eax
	movzbl	__ZN3dbg7message14m_noticeLevelGE(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4301:
	.section	.text$_ZN3dbg7message14getNoticeLevelEh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message14getNoticeLevelEh
	.def	__ZN3dbg7message14getNoticeLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message14getNoticeLevelEh:
LFB4302:
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
	jne	L355
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message14getNoticeLevelEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1205, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L355:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category9forNoticeEv
	testb	%al, %al
	jne	L356
	movl	$LC33, 12(%esp)
	movl	$__ZZN3dbg7message14getNoticeLevelEhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1206, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L356:
	movzbl	-28(%ebp), %eax
	movzbl	__ZN3dbg7message14m_noticeLevelGE(%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	movl	%eax, %ebx
	movzbl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movzbl	84(%edx,%eax), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level17calcValueAsOutputEh
	cmpb	%al, %bl
	jbe	L357
	movzbl	-28(%ebp), %eax
	movzbl	__ZN3dbg7message14m_noticeLevelGE(%eax), %eax
	jmp	L358
L357:
	movzbl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movzbl	84(%edx,%eax), %eax
L358:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4302:
	.section	.text$_ZN3dbg7message16getNoticeLevelCPEh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message16getNoticeLevelCPEh
	.def	__ZN3dbg7message16getNoticeLevelCPEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16getNoticeLevelCPEh:
LFB4303:
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
	movb	%al, -12(%ebp)
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L361
	movzbl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message15getNoticeLevelGEh
	jmp	L362
L361:
	movzbl	-12(%ebp), %ebx
	movl	$___emutls_v._ZN3dbg7message20m_callPointStackHeadE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg7message14getNoticeLevelEh
L362:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4303:
	.section	.text$_ZN3dbg7message15setNoticeLevelGEhh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message15setNoticeLevelGEhh
	.def	__ZN3dbg7message15setNoticeLevelGEhh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message15setNoticeLevelGEhh:
LFB4304:
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
	jne	L364
	movl	$LC32, 12(%esp)
	movl	$__ZZN3dbg7message15setNoticeLevelGEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1224, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L364:
	movzbl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category3getEh
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category7forMaskEv
	testb	%al, %al
	jne	L365
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message15setNoticeLevelGEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1226, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L365:
	cmpb	$64, -48(%ebp)
	jne	L366
	movzbl	__ZN3dbg7message14m_noticeLevelGE, %eax
	movb	%al, -21(%ebp)
	movl	$__ZN3dbg7message14m_noticeLevelGE, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-28(%ebp), %eax
	addl	$64, %eax
	movl	%eax, -32(%ebp)
	jmp	L367
L368:
	movl	-12(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movzbl	-44(%ebp), %edx
	movb	%dl, (%eax)
	addl	$1, -12(%ebp)
L367:
	movl	-12(%ebp), %eax
	cmpl	-32(%ebp), %eax
	jne	L368
	movzbl	-21(%ebp), %eax
	jmp	L369
L366:
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category9forNoticeEv
	testb	%al, %al
	jne	L370
	movl	$LC33, 12(%esp)
	movl	$__ZZN3dbg7message15setNoticeLevelGEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1234, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L370:
	movzbl	-48(%ebp), %eax
	movzbl	__ZN3dbg7message14m_noticeLevelGE(%eax), %eax
	movb	%al, -37(%ebp)
	movzbl	-48(%ebp), %eax
	movzbl	-44(%ebp), %edx
	movb	%dl, __ZN3dbg7message14m_noticeLevelGE(%eax)
	movzbl	-37(%ebp), %eax
L369:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4304:
	.section	.text$_ZN3dbg7message14setNoticeLevelEhh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message14setNoticeLevelEhh
	.def	__ZN3dbg7message14setNoticeLevelEhh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message14setNoticeLevelEhh:
LFB4305:
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
	jne	L372
	movl	$LC32, 12(%esp)
	movl	$__ZZN3dbg7message14setNoticeLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1243, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L372:
	movzbl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category3getEh
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category7forMaskEv
	testb	%al, %al
	jne	L373
	movl	$LC30, 12(%esp)
	movl	$__ZZN3dbg7message14setNoticeLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1245, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L373:
	cmpb	$64, -32(%ebp)
	jne	L374
	movl	8(%ebp), %eax
	movzbl	84(%eax), %eax
	movb	%al, -21(%ebp)
	movl	$0, -12(%ebp)
	jmp	L375
L378:
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
	jbe	L376
	movl	-12(%ebp), %eax
	addl	$__ZN3dbg7message14m_noticeLevelGE, %eax
	movzbl	(%eax), %eax
	jmp	L377
L376:
	movzbl	-28(%ebp), %eax
L377:
	movl	8(%ebp), %ecx
	movl	-12(%ebp), %edx
	addl	%ecx, %edx
	addl	$80, %edx
	movb	%al, 4(%edx)
	addl	$1, -12(%ebp)
L375:
	cmpl	$63, -12(%ebp)
	jle	L378
	movzbl	-21(%ebp), %eax
	jmp	L379
L374:
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category9forNoticeEv
	testb	%al, %al
	jne	L380
	movl	$LC33, 12(%esp)
	movl	$__ZZN3dbg7message14setNoticeLevelEhhE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1258, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L380:
	movzbl	-32(%ebp), %eax
	movl	8(%ebp), %edx
	movzbl	84(%edx,%eax), %eax
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
	jbe	L381
	movzbl	-32(%ebp), %eax
	movzbl	__ZN3dbg7message14m_noticeLevelGE(%eax), %eax
	jmp	L382
L381:
	movzbl	-28(%ebp), %eax
L382:
	movl	8(%ebp), %edx
	movb	%al, 84(%edx,%ebx)
	movzbl	-22(%ebp), %eax
L379:
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
LFE4305:
	.section	.text$_ZN3dbg7message17resetNoticeLevelGEh,"x"
	.linkonce discard
	.globl	__ZN3dbg7message17resetNoticeLevelGEh
	.def	__ZN3dbg7message17resetNoticeLevelGEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message17resetNoticeLevelGEh:
LFB4306:
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
LFE4306:
	.section	.text$_ZN3dbg7message16resetNoticeLevelEh,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message16resetNoticeLevelEh
	.def	__ZN3dbg7message16resetNoticeLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16resetNoticeLevelEh:
LFB4307:
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
LFE4307:
	.section	.text$_ZN3dbg7message20resetNoticeLevelAllGEv,"x"
	.linkonce discard
	.globl	__ZN3dbg7message20resetNoticeLevelAllGEv
	.def	__ZN3dbg7message20resetNoticeLevelAllGEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message20resetNoticeLevelAllGEv:
LFB4308:
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
	jmp	L386
L387:
	movl	-4(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movb	$8, (%eax)
	addl	$1, -4(%ebp)
L386:
	movl	-4(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jne	L387
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4308:
	.section	.text$_ZN3dbg7message19resetNoticeLevelAllEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message19resetNoticeLevelAllEv
	.def	__ZN3dbg7message19resetNoticeLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN3dbg7message19resetNoticeLevelAllEv:
LFB4309:
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
LFE4309:
	.section .rdata,"dr"
	.align 4
LC34:
	.ascii "o_level.forLog() == true || o_level.forNotice() == true\0"
	.align 4
LC35:
	.ascii "o_category.forLog() == true || o_category.forNotice() == true\0"
LC36:
	.ascii "[%s,%s]\0"
	.section	.text$_ZN3dbg7message12vprintCommonEhhhhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message12vprintCommonEhhhhPKcPc
	.def	__ZN3dbg7message12vprintCommonEhhhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message12vprintCommonEhhhhPKcPc:
LFB4310:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4310
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$80, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
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
	call	__ZN3dbg5level3getEh
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level6forLogEv
	xorl	$1, %eax
	testb	%al, %al
	je	L390
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level9forNoticeEv
	xorl	$1, %eax
	testb	%al, %al
	je	L390
	movl	$LC34, 12(%esp)
	movl	$__ZZN3dbg7message12vprintCommonEhhhhPKcPcE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1294, 4(%esp)
	movl	$LC3, (%esp)
LEHB5:
	call	___assert_func
L390:
	movzbl	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg8category3getEh
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category6forLogEv
	xorl	$1, %eax
	testb	%al, %al
	je	L391
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category9forNoticeEv
	xorl	$1, %eax
	testb	%al, %al
	je	L391
	movl	$LC35, 12(%esp)
	movl	$__ZZN3dbg7message12vprintCommonEhhhhPKcPcE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1296, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
LEHE5:
L391:
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	movzbl	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level3getEh
	movl	%eax, -28(%ebp)
	movzbl	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5level3getEh
	movl	%eax, -32(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5levelgeERKS0_
	testb	%al, %al
	je	L392
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level6forLogEv
	testb	%al, %al
	je	L392
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category6forLogEv
	testb	%al, %al
	je	L392
	movl	$1, %eax
	jmp	L393
L392:
	movl	$0, %eax
L393:
	testb	%al, %al
	je	L394
	leal	-38(%ebp), %eax
	movl	$0, 8(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB6:
	call	__ZNK3dbg5level11changeColorEb
LEHE6:
	subl	$4, %esp
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category4nameEv
	movl	%eax, %esi
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level4nameEv
	movl	%eax, %ebx
LEHB7:
	call	___getreent
	movl	8(%eax), %eax
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	$LC36, 4(%esp)
	movl	%eax, (%esp)
	call	_fprintf
LEHE7:
	leal	-38(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5colorD1Ev
LEHB8:
	call	___getreent
	movl	8(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fputc
	call	___getreent
	movl	8(%eax), %eax
	movl	28(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_vfprintf
LEHE8:
	movl	%eax, -12(%ebp)
L394:
	movl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5levelgeERKS0_
	testb	%al, %al
	je	L395
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level9forNoticeEv
	testb	%al, %al
	je	L395
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg8category9forNoticeEv
	testb	%al, %al
	je	L395
	movl	$1, %eax
	jmp	L396
L395:
	movl	$0, %eax
L396:
	testb	%al, %al
	je	L397
	leal	-44(%ebp), %eax
	movl	$0, 8(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB9:
	call	__ZNK3dbg5level20changeColorForNoticeEb
LEHE9:
	subl	$4, %esp
LEHB10:
	call	___getreent
	movl	12(%eax), %eax
	movl	28(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_vfprintf
LEHE10:
	movl	%eax, -16(%ebp)
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5colorD1Ev
L397:
	movl	-12(%ebp), %eax
	cmpl	-16(%ebp), %eax
	jle	L398
	movl	-12(%ebp), %eax
	jmp	L409
L398:
	movl	-16(%ebp), %eax
	jmp	L409
L406:
	movl	%eax, %ebx
	leal	-38(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5colorD1Ev
	movl	%ebx, %eax
	jmp	L402
L405:
L402:
	movl	%eax, (%esp)
LEHB11:
	call	__Unwind_Resume
L408:
	movl	%eax, %ebx
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5colorD1Ev
	movl	%ebx, %eax
	jmp	L404
L407:
L404:
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE11:
L409:
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
LFE4310:
	.section	.gcc_except_table,"w"
LLSDA4310:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4310-LLSDACSB4310
LLSDACSB4310:
	.uleb128 LEHB5-LFB4310
	.uleb128 LEHE5-LEHB5
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB6-LFB4310
	.uleb128 LEHE6-LEHB6
	.uleb128 L405-LFB4310
	.uleb128 0
	.uleb128 LEHB7-LFB4310
	.uleb128 LEHE7-LEHB7
	.uleb128 L406-LFB4310
	.uleb128 0
	.uleb128 LEHB8-LFB4310
	.uleb128 LEHE8-LEHB8
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB9-LFB4310
	.uleb128 LEHE9-LEHB9
	.uleb128 L407-LFB4310
	.uleb128 0
	.uleb128 LEHB10-LFB4310
	.uleb128 LEHE10-LEHB10
	.uleb128 L408-LFB4310
	.uleb128 0
	.uleb128 LEHB11-LFB4310
	.uleb128 LEHE11-LEHB11
	.uleb128 0
	.uleb128 0
LLSDACSE4310:
	.section	.text$_ZN3dbg7message12vprintCommonEhhhhPKcPc,"x"
	.linkonce discard
	.section	.text$_ZN3dbg7message7vprintGEhhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message7vprintGEhhPKcPc
	.def	__ZN3dbg7message7vprintGEhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message7vprintGEhhPKcPc:
LFB4311:
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
	call	__ZN3dbg7message13getLogLevelCPEh
	movb	%al, -10(%ebp)
	movzbl	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message16getNoticeLevelCPEh
	movb	%al, -11(%ebp)
	movzbl	-32(%ebp), %ebx
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
LFE4311:
	.section	.text$_ZN3dbg7message6vprintEhhPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message6vprintEhhPKcPc
	.def	__ZN3dbg7message6vprintEhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message6vprintEhhPKcPc:
LFB4312:
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
	call	__ZN3dbg7message11getLogLevelEh
	movb	%al, -10(%ebp)
	movzbl	-9(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message14getNoticeLevelEh
	movb	%al, -11(%ebp)
	movzbl	-32(%ebp), %ebx
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
LFE4312:
	.section	.text$_ZN3dbg7message6vprintEhPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message6vprintEhPKcPc
	.def	__ZN3dbg7message6vprintEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message6vprintEhPKcPc:
LFB4313:
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
LFE4313:
	.section	.text$_ZN3dbg7message5vlogGEhhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message5vlogGEhhPKcPc
	.def	__ZN3dbg7message5vlogGEhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message5vlogGEhhPKcPc:
LFB4315:
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
	call	__ZN3dbg7message13getLogLevelCPEh
	movb	%al, -10(%ebp)
	movb	$12, -11(%ebp)
	movzbl	-32(%ebp), %ecx
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
LFE4315:
	.section	.text$_ZN3dbg7message4vlogEhhPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message4vlogEhhPKcPc
	.def	__ZN3dbg7message4vlogEhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message4vlogEhhPKcPc:
LFB4316:
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
	call	__ZN3dbg7message11getLogLevelEh
	movb	%al, -10(%ebp)
	movb	$12, -11(%ebp)
	movzbl	-32(%ebp), %ecx
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
LFE4316:
	.section	.text$_ZN3dbg7message4vlogEhPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message4vlogEhPKcPc
	.def	__ZN3dbg7message4vlogEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message4vlogEhPKcPc:
LFB4317:
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
LFE4317:
	.section	.text$_ZN3dbg7message4vlogEPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message4vlogEPKcPc
	.def	__ZN3dbg7message4vlogEPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message4vlogEPKcPc:
LFB4318:
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
LFE4318:
	.section	.text$_ZN3dbg7message8vnoticeGEhhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message8vnoticeGEhhPKcPc
	.def	__ZN3dbg7message8vnoticeGEhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message8vnoticeGEhhPKcPc:
LFB4319:
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
	call	__ZN3dbg7message16getNoticeLevelCPEh
	movb	%al, -11(%ebp)
	movzbl	-32(%ebp), %ecx
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
LFE4319:
	.section	.text$_ZN3dbg7message7vnoticeEhhPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message7vnoticeEhhPKcPc
	.def	__ZN3dbg7message7vnoticeEhhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message7vnoticeEhhPKcPc:
LFB4320:
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
	call	__ZN3dbg7message14getNoticeLevelEh
	movb	%al, -11(%ebp)
	movzbl	-32(%ebp), %ecx
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
LFE4320:
	.section	.text$_ZN3dbg7message7vnoticeEPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message7vnoticeEPKcPc
	.def	__ZN3dbg7message7vnoticeEPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message7vnoticeEPKcPc:
LFB4322:
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
LFE4322:
	.section	.text$_ZN3dbg7message3logEPKcz,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message3logEPKcz
	.def	__ZN3dbg7message3logEPKcz;	.scl	2;	.type	32;	.endef
__ZN3dbg7message3logEPKcz:
LFB4330:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4330
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
LEHB12:
	call	__ZN3dbg7message4vlogEPKcPc
LEHE12:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L434
L433:
	movl	%eax, (%esp)
LEHB13:
	call	__Unwind_Resume
LEHE13:
L434:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4330:
	.section	.gcc_except_table,"w"
LLSDA4330:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4330-LLSDACSB4330
LLSDACSB4330:
	.uleb128 LEHB12-LFB4330
	.uleb128 LEHE12-LEHB12
	.uleb128 L433-LFB4330
	.uleb128 0
	.uleb128 LEHB13-LFB4330
	.uleb128 LEHE13-LEHB13
	.uleb128 0
	.uleb128 0
LLSDACSE4330:
	.section	.text$_ZN3dbg7message3logEPKcz,"x"
	.linkonce discard
	.section	.text$_ZN3dbg7message6noticeEPKcz,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message6noticeEPKcz
	.def	__ZN3dbg7message6noticeEPKcz;	.scl	2;	.type	32;	.endef
__ZN3dbg7message6noticeEPKcz:
LFB4334:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4334
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
LEHB14:
	call	__ZN3dbg7message7vnoticeEPKcPc
LEHE14:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L439
L438:
	movl	%eax, (%esp)
LEHB15:
	call	__Unwind_Resume
LEHE15:
L439:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4334:
	.section	.gcc_except_table,"w"
LLSDA4334:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4334-LLSDACSB4334
LLSDACSB4334:
	.uleb128 LEHB14-LFB4334
	.uleb128 LEHE14-LEHB14
	.uleb128 L438-LFB4334
	.uleb128 0
	.uleb128 LEHB15-LFB4334
	.uleb128 LEHE15-LEHB15
	.uleb128 0
	.uleb128 0
LLSDACSE4334:
	.section	.text$_ZN3dbg7message6noticeEPKcz,"x"
	.linkonce discard
	.section	.text$_ZN3dbg7message15vprintAsNormalGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message15vprintAsNormalGEhPKcPc
	.def	__ZN3dbg7message15vprintAsNormalGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message15vprintAsNormalGEhPKcPc:
LFB4335:
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
LFE4335:
	.section	.text$_ZN3dbg7message14vprintAsNormalEPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message14vprintAsNormalEPKcPc
	.def	__ZN3dbg7message14vprintAsNormalEPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message14vprintAsNormalEPKcPc:
LFB4337:
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
LFE4337:
	.section	.text$_ZN3dbg7message13vlogAsNormalGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message13vlogAsNormalGEhPKcPc
	.def	__ZN3dbg7message13vlogAsNormalGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message13vlogAsNormalGEhPKcPc:
LFB4338:
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
LFE4338:
	.section	.text$_ZN3dbg7message12vlogAsNormalEPKcPc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message12vlogAsNormalEPKcPc
	.def	__ZN3dbg7message12vlogAsNormalEPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message12vlogAsNormalEPKcPc:
LFB4340:
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
LFE4340:
	.section	.text$_ZN3dbg7message16vnoticeAsNormalGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message16vnoticeAsNormalGEhPKcPc
	.def	__ZN3dbg7message16vnoticeAsNormalGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16vnoticeAsNormalGEhPKcPc:
LFB4341:
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
LFE4341:
	.section	.text$_ZN3dbg7message16vprintAsVerboseGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message16vprintAsVerboseGEhPKcPc
	.def	__ZN3dbg7message16vprintAsVerboseGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16vprintAsVerboseGEhPKcPc:
LFB4344:
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
LFE4344:
	.section	.text$_ZN3dbg7message14vlogAsVerboseGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message14vlogAsVerboseGEhPKcPc
	.def	__ZN3dbg7message14vlogAsVerboseGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message14vlogAsVerboseGEhPKcPc:
LFB4347:
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
LFE4347:
	.section	.text$_ZN3dbg7message17vnoticeAsVerboseGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message17vnoticeAsVerboseGEhPKcPc
	.def	__ZN3dbg7message17vnoticeAsVerboseGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message17vnoticeAsVerboseGEhPKcPc:
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
	movl	$0, (%esp)
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4350:
	.section	.text$_ZN3dbg7message15vprintAsDetailGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message15vprintAsDetailGEhPKcPc
	.def	__ZN3dbg7message15vprintAsDetailGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message15vprintAsDetailGEhPKcPc:
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
	movl	$1, (%esp)
	call	__ZN3dbg7message7vprintGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4353:
	.section	.text$_ZN3dbg7message13vlogAsDetailGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message13vlogAsDetailGEhPKcPc
	.def	__ZN3dbg7message13vlogAsDetailGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message13vlogAsDetailGEhPKcPc:
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
	movl	$1, (%esp)
	call	__ZN3dbg7message5vlogGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4356:
	.section	.text$_ZN3dbg7message16vnoticeAsDetailGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message16vnoticeAsDetailGEhPKcPc
	.def	__ZN3dbg7message16vnoticeAsDetailGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16vnoticeAsDetailGEhPKcPc:
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
	movl	$1, (%esp)
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4359:
	.section	.text$_ZN3dbg7message18vprintAsImportantGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message18vprintAsImportantGEhPKcPc
	.def	__ZN3dbg7message18vprintAsImportantGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message18vprintAsImportantGEhPKcPc:
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
	movl	$4, (%esp)
	call	__ZN3dbg7message7vprintGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4362:
	.section	.text$_ZN3dbg7message16vlogAsImportantGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message16vlogAsImportantGEhPKcPc
	.def	__ZN3dbg7message16vlogAsImportantGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16vlogAsImportantGEhPKcPc:
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
	movl	$4, (%esp)
	call	__ZN3dbg7message5vlogGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4365:
	.section	.text$_ZN3dbg7message19vnoticeAsImportantGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message19vnoticeAsImportantGEhPKcPc
	.def	__ZN3dbg7message19vnoticeAsImportantGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message19vnoticeAsImportantGEhPKcPc:
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
	movl	$4, (%esp)
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4368:
	.section	.text$_ZN3dbg7message16vprintAsWarningGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message16vprintAsWarningGEhPKcPc
	.def	__ZN3dbg7message16vprintAsWarningGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message16vprintAsWarningGEhPKcPc:
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
	movl	$6, (%esp)
	call	__ZN3dbg7message7vprintGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4371:
	.section	.text$_ZN3dbg7message14vlogAsWarningGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message14vlogAsWarningGEhPKcPc
	.def	__ZN3dbg7message14vlogAsWarningGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message14vlogAsWarningGEhPKcPc:
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
	movl	$6, (%esp)
	call	__ZN3dbg7message5vlogGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4374:
	.section	.text$_ZN3dbg7message17vnoticeAsWarningGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message17vnoticeAsWarningGEhPKcPc
	.def	__ZN3dbg7message17vnoticeAsWarningGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message17vnoticeAsWarningGEhPKcPc:
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
	movl	$6, (%esp)
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4377:
	.section	.text$_ZN3dbg7message17vprintAsCriticalGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message17vprintAsCriticalGEhPKcPc
	.def	__ZN3dbg7message17vprintAsCriticalGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message17vprintAsCriticalGEhPKcPc:
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
	movl	$8, (%esp)
	call	__ZN3dbg7message7vprintGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4380:
	.section	.text$_ZN3dbg7message15vlogAsCriticalGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message15vlogAsCriticalGEhPKcPc
	.def	__ZN3dbg7message15vlogAsCriticalGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message15vlogAsCriticalGEhPKcPc:
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
	movl	$8, (%esp)
	call	__ZN3dbg7message5vlogGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4383:
	.section	.text$_ZN3dbg7message18vnoticeAsCriticalGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message18vnoticeAsCriticalGEhPKcPc
	.def	__ZN3dbg7message18vnoticeAsCriticalGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message18vnoticeAsCriticalGEhPKcPc:
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
	movl	$8, (%esp)
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4386:
	.section	.text$_ZN3dbg7message17vprintAsAbsoluteGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message17vprintAsAbsoluteGEhPKcPc
	.def	__ZN3dbg7message17vprintAsAbsoluteGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message17vprintAsAbsoluteGEhPKcPc:
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
	movl	$10, (%esp)
	call	__ZN3dbg7message7vprintGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4389:
	.section	.text$_ZN3dbg7message15vlogAsAbsoluteGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message15vlogAsAbsoluteGEhPKcPc
	.def	__ZN3dbg7message15vlogAsAbsoluteGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message15vlogAsAbsoluteGEhPKcPc:
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
	movl	$10, (%esp)
	call	__ZN3dbg7message5vlogGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4392:
	.section	.text$_ZN3dbg7message18vnoticeAsAbsoluteGEhPKcPc,"x"
	.linkonce discard
	.globl	__ZN3dbg7message18vnoticeAsAbsoluteGEhPKcPc
	.def	__ZN3dbg7message18vnoticeAsAbsoluteGEhPKcPc;	.scl	2;	.type	32;	.endef
__ZN3dbg7message18vnoticeAsAbsoluteGEhPKcPc:
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
	movl	$10, (%esp)
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4395:
	.section	.text$_ZN3dbg7message13printAsNormalEPKcz,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message13printAsNormalEPKcz
	.def	__ZN3dbg7message13printAsNormalEPKcz;	.scl	2;	.type	32;	.endef
__ZN3dbg7message13printAsNormalEPKcz:
LFB4400:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4400
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
LEHB16:
	call	__ZN3dbg7message14vprintAsNormalEPKcPc
LEHE16:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L490
L489:
	movl	%eax, (%esp)
LEHB17:
	call	__Unwind_Resume
LEHE17:
L490:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4400:
	.section	.gcc_except_table,"w"
LLSDA4400:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4400-LLSDACSB4400
LLSDACSB4400:
	.uleb128 LEHB16-LFB4400
	.uleb128 LEHE16-LEHB16
	.uleb128 L489-LFB4400
	.uleb128 0
	.uleb128 LEHB17-LFB4400
	.uleb128 LEHE17-LEHB17
	.uleb128 0
	.uleb128 0
LLSDACSE4400:
	.section	.text$_ZN3dbg7message13printAsNormalEPKcz,"x"
	.linkonce discard
	.section	.text$_ZN3dbg7message11logAsNormalEPKcz,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7message11logAsNormalEPKcz
	.def	__ZN3dbg7message11logAsNormalEPKcz;	.scl	2;	.type	32;	.endef
__ZN3dbg7message11logAsNormalEPKcz:
LFB4403:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4403
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
LEHB18:
	call	__ZN3dbg7message12vlogAsNormalEPKcPc
LEHE18:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L495
L494:
	movl	%eax, (%esp)
LEHB19:
	call	__Unwind_Resume
LEHE19:
L495:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4403:
	.section	.gcc_except_table,"w"
LLSDA4403:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4403-LLSDACSB4403
LLSDACSB4403:
	.uleb128 LEHB18-LFB4403
	.uleb128 LEHE18-LEHB18
	.uleb128 L494-LFB4403
	.uleb128 0
	.uleb128 LEHB19-LFB4403
	.uleb128 LEHE19-LEHB19
	.uleb128 0
	.uleb128 0
LLSDACSE4403:
	.section	.text$_ZN3dbg7message11logAsNormalEPKcz,"x"
	.linkonce discard
	.section	.text$_ZN3dbg7messageC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7messageC1Ev
	.def	__ZN3dbg7messageC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg7messageC1Ev:
LFB4466:
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
	call	__ZN3dbg7message14initializeOnceEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4466:
	.section .rdata,"dr"
	.align 4
LC37:
	.ascii "category_ >= category::NORMAL_MIN && category_ <= category::NORMAL_MAX\0"
	.section	.text$_ZN3dbg7messageC1EhhPKcS2_S2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7messageC1EhhPKcS2_S2_
	.def	__ZN3dbg7messageC1EhhPKcS2_S2_;	.scl	2;	.type	32;	.endef
__ZN3dbg7messageC1EhhPKcS2_S2_:
LFB4469:
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
	cmpb	$63, -16(%ebp)
	jbe	L498
	movl	$LC37, 12(%esp)
	movl	$__ZZN3dbg7messageC1EhhPKcS2_S2_E19__PRETTY_FUNCTION__, 8(%esp)
	movl	$1663, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L498:
	movl	8(%ebp), %eax
	movl	__ZN3dbg7message11m_logLevelGE, %edx
	movl	%edx, 20(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+4, %edx
	movl	%edx, 24(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+8, %edx
	movl	%edx, 28(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+12, %edx
	movl	%edx, 32(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+16, %edx
	movl	%edx, 36(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+20, %edx
	movl	%edx, 40(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+24, %edx
	movl	%edx, 44(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+28, %edx
	movl	%edx, 48(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+32, %edx
	movl	%edx, 52(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+36, %edx
	movl	%edx, 56(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+40, %edx
	movl	%edx, 60(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+44, %edx
	movl	%edx, 64(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+48, %edx
	movl	%edx, 68(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+52, %edx
	movl	%edx, 72(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+56, %edx
	movl	%edx, 76(%eax)
	movl	__ZN3dbg7message11m_logLevelGE+60, %edx
	movl	%edx, 80(%eax)
	movl	8(%ebp), %eax
	movl	__ZN3dbg7message14m_noticeLevelGE, %edx
	movl	%edx, 84(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+4, %edx
	movl	%edx, 88(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+8, %edx
	movl	%edx, 92(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+12, %edx
	movl	%edx, 96(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+16, %edx
	movl	%edx, 100(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+20, %edx
	movl	%edx, 104(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+24, %edx
	movl	%edx, 108(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+28, %edx
	movl	%edx, 112(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+32, %edx
	movl	%edx, 116(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+36, %edx
	movl	%edx, 120(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+40, %edx
	movl	%edx, 124(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+44, %edx
	movl	%edx, 128(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+48, %edx
	movl	%edx, 132(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+52, %edx
	movl	%edx, 136(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+56, %edx
	movl	%edx, 140(%eax)
	movl	__ZN3dbg7message14m_noticeLevelGE+60, %edx
	movl	%edx, 144(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4469:
	.section	.text$_ZN3dbg7messageD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg7messageD1Ev
	.def	__ZN3dbg7messageD1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg7messageD1Ev:
LFB4472:
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
LFE4472:
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
LFB4473:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movzbl	__ZN3dbg7message15m_isInitializedE, %eax
	testb	%al, %al
	je	L502
	jmp	L501
L502:
	movb	$1, __ZN3dbg7message15m_isInitializedE
	call	__ZN3dbg7message17resetLogLevelAllGEv
	call	__ZN3dbg7message20resetNoticeLevelAllGEv
L501:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4473:
.lcomm __ZN3dbgL22s_messageForInitializeE,148,32
	.globl	__ZN3dbg11getLogLevelEh
	.def	__ZN3dbg11getLogLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg11getLogLevelEh:
LFB4474:
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
LFE4474:
	.globl	__ZN3dbg11setLogLevelEhh
	.def	__ZN3dbg11setLogLevelEhh;	.scl	2;	.type	32;	.endef
__ZN3dbg11setLogLevelEhh:
LFB4475:
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
LFE4475:
	.globl	__ZN3dbg13resetLogLevelEh
	.def	__ZN3dbg13resetLogLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg13resetLogLevelEh:
LFB4476:
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
LFE4476:
	.globl	__ZN3dbg16resetLogLevelAllEv
	.def	__ZN3dbg16resetLogLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN3dbg16resetLogLevelAllEv:
LFB4477:
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
LFE4477:
	.globl	__ZN3dbg14getNoticeLevelEh
	.def	__ZN3dbg14getNoticeLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg14getNoticeLevelEh:
LFB4478:
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
LFE4478:
	.globl	__ZN3dbg14setNoticeLevelEhh
	.def	__ZN3dbg14setNoticeLevelEhh;	.scl	2;	.type	32;	.endef
__ZN3dbg14setNoticeLevelEhh:
LFB4479:
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
LFE4479:
	.globl	__ZN3dbg16resetNoticeLevelEh
	.def	__ZN3dbg16resetNoticeLevelEh;	.scl	2;	.type	32;	.endef
__ZN3dbg16resetNoticeLevelEh:
LFB4480:
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
LFE4480:
	.globl	__ZN3dbg19resetNoticeLevelAllEv
	.def	__ZN3dbg19resetNoticeLevelAllEv;	.scl	2;	.type	32;	.endef
__ZN3dbg19resetNoticeLevelAllEv:
LFB4481:
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
LFE4481:
	.def	__ZN3dbgL6vprintEhhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL6vprintEhhPKcPc:
LFB4482:
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
LFE4482:
	.def	__ZN3dbgL4vlogEhhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL4vlogEhhPKcPc:
LFB4483:
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
LFE4483:
	.def	__ZN3dbgL7vnoticeEhhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL7vnoticeEhhPKcPc:
LFB4484:
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
LFE4484:
	.def	__ZN3dbgL5printEhhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL5printEhhPKcz:
LFB4485:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4485
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
LEHB20:
	call	__ZN3dbg7message7vprintGEhhPKcPc
LEHE20:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L526
L525:
	movl	%eax, (%esp)
LEHB21:
	call	__Unwind_Resume
LEHE21:
L526:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4485:
	.section	.gcc_except_table,"w"
LLSDA4485:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4485-LLSDACSB4485
LLSDACSB4485:
	.uleb128 LEHB20-LFB4485
	.uleb128 LEHE20-LEHB20
	.uleb128 L525-LFB4485
	.uleb128 0
	.uleb128 LEHB21-LFB4485
	.uleb128 LEHE21-LEHB21
	.uleb128 0
	.uleb128 0
LLSDACSE4485:
	.text
	.def	__ZN3dbgL3logEhhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL3logEhhPKcz:
LFB4486:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4486
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
LEHB22:
	call	__ZN3dbg7message5vlogGEhhPKcPc
LEHE22:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L531
L530:
	movl	%eax, (%esp)
LEHB23:
	call	__Unwind_Resume
LEHE23:
L531:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4486:
	.section	.gcc_except_table,"w"
LLSDA4486:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4486-LLSDACSB4486
LLSDACSB4486:
	.uleb128 LEHB22-LFB4486
	.uleb128 LEHE22-LEHB22
	.uleb128 L530-LFB4486
	.uleb128 0
	.uleb128 LEHB23-LFB4486
	.uleb128 LEHE23-LEHB23
	.uleb128 0
	.uleb128 0
LLSDACSE4486:
	.text
	.def	__ZN3dbgL6noticeEhhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL6noticeEhhPKcz:
LFB4487:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4487
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
LEHB24:
	call	__ZN3dbg7message8vnoticeGEhhPKcPc
LEHE24:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L536
L535:
	movl	%eax, (%esp)
LEHB25:
	call	__Unwind_Resume
LEHE25:
L536:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4487:
	.section	.gcc_except_table,"w"
LLSDA4487:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4487-LLSDACSB4487
LLSDACSB4487:
	.uleb128 LEHB24-LFB4487
	.uleb128 LEHE24-LEHB24
	.uleb128 L535-LFB4487
	.uleb128 0
	.uleb128 LEHB25-LFB4487
	.uleb128 LEHE25-LEHB25
	.uleb128 0
	.uleb128 0
LLSDACSE4487:
	.text
	.def	__ZN3dbgL14vprintAsNormalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL14vprintAsNormalEhPKcPc:
LFB4488:
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
LFE4488:
	.def	__ZN3dbgL12vlogAsNormalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL12vlogAsNormalEhPKcPc:
LFB4489:
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
LFE4489:
	.def	__ZN3dbgL15vnoticeAsNormalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL15vnoticeAsNormalEhPKcPc:
LFB4490:
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
LFE4490:
	.def	__ZN3dbgL15vprintAsVerboseEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL15vprintAsVerboseEhPKcPc:
LFB4491:
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
LFE4491:
	.def	__ZN3dbgL13vlogAsVerboseEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL13vlogAsVerboseEhPKcPc:
LFB4492:
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
LFE4492:
	.def	__ZN3dbgL16vnoticeAsVerboseEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL16vnoticeAsVerboseEhPKcPc:
LFB4493:
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
LFE4493:
	.def	__ZN3dbgL14vprintAsDetailEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL14vprintAsDetailEhPKcPc:
LFB4494:
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
LFE4494:
	.def	__ZN3dbgL12vlogAsDetailEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL12vlogAsDetailEhPKcPc:
LFB4495:
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
LFE4495:
	.def	__ZN3dbgL15vnoticeAsDetailEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL15vnoticeAsDetailEhPKcPc:
LFB4496:
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
LFE4496:
	.def	__ZN3dbgL17vprintAsImportantEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL17vprintAsImportantEhPKcPc:
LFB4497:
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
LFE4497:
	.def	__ZN3dbgL15vlogAsImportantEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL15vlogAsImportantEhPKcPc:
LFB4498:
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
LFE4498:
	.def	__ZN3dbgL18vnoticeAsImportantEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL18vnoticeAsImportantEhPKcPc:
LFB4499:
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
LFE4499:
	.def	__ZN3dbgL15vprintAsWarningEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL15vprintAsWarningEhPKcPc:
LFB4500:
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
LFE4500:
	.def	__ZN3dbgL13vlogAsWarningEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL13vlogAsWarningEhPKcPc:
LFB4501:
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
LFE4501:
	.def	__ZN3dbgL16vnoticeAsWarningEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL16vnoticeAsWarningEhPKcPc:
LFB4502:
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
LFE4502:
	.def	__ZN3dbgL16vprintAsCriticalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL16vprintAsCriticalEhPKcPc:
LFB4503:
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
LFE4503:
	.def	__ZN3dbgL14vlogAsCriticalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL14vlogAsCriticalEhPKcPc:
LFB4504:
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
LFE4504:
	.def	__ZN3dbgL17vnoticeAsCriticalEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL17vnoticeAsCriticalEhPKcPc:
LFB4505:
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
LFE4505:
	.def	__ZN3dbgL16vprintAsAbsoluteEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL16vprintAsAbsoluteEhPKcPc:
LFB4506:
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
LFE4506:
	.def	__ZN3dbgL14vlogAsAbsoluteEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL14vlogAsAbsoluteEhPKcPc:
LFB4507:
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
LFE4507:
	.def	__ZN3dbgL17vnoticeAsAbsoluteEhPKcPc;	.scl	3;	.type	32;	.endef
__ZN3dbgL17vnoticeAsAbsoluteEhPKcPc:
LFB4508:
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
LFE4508:
	.def	__ZN3dbgL13printAsNormalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL13printAsNormalEhPKcz:
LFB4509:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4509
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
LEHB26:
	call	__ZN3dbg7message15vprintAsNormalGEhPKcPc
LEHE26:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L583
L582:
	movl	%eax, (%esp)
LEHB27:
	call	__Unwind_Resume
LEHE27:
L583:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4509:
	.section	.gcc_except_table,"w"
LLSDA4509:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4509-LLSDACSB4509
LLSDACSB4509:
	.uleb128 LEHB26-LFB4509
	.uleb128 LEHE26-LEHB26
	.uleb128 L582-LFB4509
	.uleb128 0
	.uleb128 LEHB27-LFB4509
	.uleb128 LEHE27-LEHB27
	.uleb128 0
	.uleb128 0
LLSDACSE4509:
	.text
	.def	__ZN3dbgL11logAsNormalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL11logAsNormalEhPKcz:
LFB4510:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4510
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
LEHB28:
	call	__ZN3dbg7message13vlogAsNormalGEhPKcPc
LEHE28:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L588
L587:
	movl	%eax, (%esp)
LEHB29:
	call	__Unwind_Resume
LEHE29:
L588:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4510:
	.section	.gcc_except_table,"w"
LLSDA4510:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4510-LLSDACSB4510
LLSDACSB4510:
	.uleb128 LEHB28-LFB4510
	.uleb128 LEHE28-LEHB28
	.uleb128 L587-LFB4510
	.uleb128 0
	.uleb128 LEHB29-LFB4510
	.uleb128 LEHE29-LEHB29
	.uleb128 0
	.uleb128 0
LLSDACSE4510:
	.text
	.def	__ZN3dbgL14noticeAsNormalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL14noticeAsNormalEhPKcz:
LFB4511:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4511
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
LEHB30:
	call	__ZN3dbg7message16vnoticeAsNormalGEhPKcPc
LEHE30:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L593
L592:
	movl	%eax, (%esp)
LEHB31:
	call	__Unwind_Resume
LEHE31:
L593:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4511:
	.section	.gcc_except_table,"w"
LLSDA4511:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4511-LLSDACSB4511
LLSDACSB4511:
	.uleb128 LEHB30-LFB4511
	.uleb128 LEHE30-LEHB30
	.uleb128 L592-LFB4511
	.uleb128 0
	.uleb128 LEHB31-LFB4511
	.uleb128 LEHE31-LEHB31
	.uleb128 0
	.uleb128 0
LLSDACSE4511:
	.text
	.def	__ZN3dbgL14printAsVerboseEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL14printAsVerboseEhPKcz:
LFB4512:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4512
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
	call	__ZN3dbg7message16vprintAsVerboseGEhPKcPc
LEHE32:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L598
L597:
	movl	%eax, (%esp)
LEHB33:
	call	__Unwind_Resume
LEHE33:
L598:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4512:
	.section	.gcc_except_table,"w"
LLSDA4512:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4512-LLSDACSB4512
LLSDACSB4512:
	.uleb128 LEHB32-LFB4512
	.uleb128 LEHE32-LEHB32
	.uleb128 L597-LFB4512
	.uleb128 0
	.uleb128 LEHB33-LFB4512
	.uleb128 LEHE33-LEHB33
	.uleb128 0
	.uleb128 0
LLSDACSE4512:
	.text
	.def	__ZN3dbgL12logAsVerboseEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL12logAsVerboseEhPKcz:
LFB4513:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4513
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
	call	__ZN3dbg7message14vlogAsVerboseGEhPKcPc
LEHE34:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L603
L602:
	movl	%eax, (%esp)
LEHB35:
	call	__Unwind_Resume
LEHE35:
L603:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4513:
	.section	.gcc_except_table,"w"
LLSDA4513:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4513-LLSDACSB4513
LLSDACSB4513:
	.uleb128 LEHB34-LFB4513
	.uleb128 LEHE34-LEHB34
	.uleb128 L602-LFB4513
	.uleb128 0
	.uleb128 LEHB35-LFB4513
	.uleb128 LEHE35-LEHB35
	.uleb128 0
	.uleb128 0
LLSDACSE4513:
	.text
	.def	__ZN3dbgL15noticeAsVerboseEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL15noticeAsVerboseEhPKcz:
LFB4514:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4514
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
	call	__ZN3dbg7message17vnoticeAsVerboseGEhPKcPc
LEHE36:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L608
L607:
	movl	%eax, (%esp)
LEHB37:
	call	__Unwind_Resume
LEHE37:
L608:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4514:
	.section	.gcc_except_table,"w"
LLSDA4514:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4514-LLSDACSB4514
LLSDACSB4514:
	.uleb128 LEHB36-LFB4514
	.uleb128 LEHE36-LEHB36
	.uleb128 L607-LFB4514
	.uleb128 0
	.uleb128 LEHB37-LFB4514
	.uleb128 LEHE37-LEHB37
	.uleb128 0
	.uleb128 0
LLSDACSE4514:
	.text
	.def	__ZN3dbgL13printAsDetailEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL13printAsDetailEhPKcz:
LFB4515:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4515
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
	call	__ZN3dbg7message15vprintAsDetailGEhPKcPc
LEHE38:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L613
L612:
	movl	%eax, (%esp)
LEHB39:
	call	__Unwind_Resume
LEHE39:
L613:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4515:
	.section	.gcc_except_table,"w"
LLSDA4515:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4515-LLSDACSB4515
LLSDACSB4515:
	.uleb128 LEHB38-LFB4515
	.uleb128 LEHE38-LEHB38
	.uleb128 L612-LFB4515
	.uleb128 0
	.uleb128 LEHB39-LFB4515
	.uleb128 LEHE39-LEHB39
	.uleb128 0
	.uleb128 0
LLSDACSE4515:
	.text
	.def	__ZN3dbgL11logAsDetailEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL11logAsDetailEhPKcz:
LFB4516:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4516
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
	call	__ZN3dbg7message13vlogAsDetailGEhPKcPc
LEHE40:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L618
L617:
	movl	%eax, (%esp)
LEHB41:
	call	__Unwind_Resume
LEHE41:
L618:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4516:
	.section	.gcc_except_table,"w"
LLSDA4516:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4516-LLSDACSB4516
LLSDACSB4516:
	.uleb128 LEHB40-LFB4516
	.uleb128 LEHE40-LEHB40
	.uleb128 L617-LFB4516
	.uleb128 0
	.uleb128 LEHB41-LFB4516
	.uleb128 LEHE41-LEHB41
	.uleb128 0
	.uleb128 0
LLSDACSE4516:
	.text
	.def	__ZN3dbgL14noticeAsDetailEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL14noticeAsDetailEhPKcz:
LFB4517:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4517
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
	call	__ZN3dbg7message16vnoticeAsDetailGEhPKcPc
LEHE42:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L623
L622:
	movl	%eax, (%esp)
LEHB43:
	call	__Unwind_Resume
LEHE43:
L623:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4517:
	.section	.gcc_except_table,"w"
LLSDA4517:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4517-LLSDACSB4517
LLSDACSB4517:
	.uleb128 LEHB42-LFB4517
	.uleb128 LEHE42-LEHB42
	.uleb128 L622-LFB4517
	.uleb128 0
	.uleb128 LEHB43-LFB4517
	.uleb128 LEHE43-LEHB43
	.uleb128 0
	.uleb128 0
LLSDACSE4517:
	.text
	.def	__ZN3dbgL16printAsImportantEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL16printAsImportantEhPKcz:
LFB4518:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4518
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
	call	__ZN3dbg7message18vprintAsImportantGEhPKcPc
LEHE44:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L628
L627:
	movl	%eax, (%esp)
LEHB45:
	call	__Unwind_Resume
LEHE45:
L628:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4518:
	.section	.gcc_except_table,"w"
LLSDA4518:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4518-LLSDACSB4518
LLSDACSB4518:
	.uleb128 LEHB44-LFB4518
	.uleb128 LEHE44-LEHB44
	.uleb128 L627-LFB4518
	.uleb128 0
	.uleb128 LEHB45-LFB4518
	.uleb128 LEHE45-LEHB45
	.uleb128 0
	.uleb128 0
LLSDACSE4518:
	.text
	.def	__ZN3dbgL14logAsImportantEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL14logAsImportantEhPKcz:
LFB4519:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4519
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
	call	__ZN3dbg7message16vlogAsImportantGEhPKcPc
LEHE46:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L633
L632:
	movl	%eax, (%esp)
LEHB47:
	call	__Unwind_Resume
LEHE47:
L633:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4519:
	.section	.gcc_except_table,"w"
LLSDA4519:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4519-LLSDACSB4519
LLSDACSB4519:
	.uleb128 LEHB46-LFB4519
	.uleb128 LEHE46-LEHB46
	.uleb128 L632-LFB4519
	.uleb128 0
	.uleb128 LEHB47-LFB4519
	.uleb128 LEHE47-LEHB47
	.uleb128 0
	.uleb128 0
LLSDACSE4519:
	.text
	.def	__ZN3dbgL17noticeAsImportantEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL17noticeAsImportantEhPKcz:
LFB4520:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4520
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
	call	__ZN3dbg7message19vnoticeAsImportantGEhPKcPc
LEHE48:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L638
L637:
	movl	%eax, (%esp)
LEHB49:
	call	__Unwind_Resume
LEHE49:
L638:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4520:
	.section	.gcc_except_table,"w"
LLSDA4520:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4520-LLSDACSB4520
LLSDACSB4520:
	.uleb128 LEHB48-LFB4520
	.uleb128 LEHE48-LEHB48
	.uleb128 L637-LFB4520
	.uleb128 0
	.uleb128 LEHB49-LFB4520
	.uleb128 LEHE49-LEHB49
	.uleb128 0
	.uleb128 0
LLSDACSE4520:
	.text
	.def	__ZN3dbgL14printAsWarningEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL14printAsWarningEhPKcz:
LFB4521:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4521
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
	call	__ZN3dbg7message16vprintAsWarningGEhPKcPc
LEHE50:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L643
L642:
	movl	%eax, (%esp)
LEHB51:
	call	__Unwind_Resume
LEHE51:
L643:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4521:
	.section	.gcc_except_table,"w"
LLSDA4521:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4521-LLSDACSB4521
LLSDACSB4521:
	.uleb128 LEHB50-LFB4521
	.uleb128 LEHE50-LEHB50
	.uleb128 L642-LFB4521
	.uleb128 0
	.uleb128 LEHB51-LFB4521
	.uleb128 LEHE51-LEHB51
	.uleb128 0
	.uleb128 0
LLSDACSE4521:
	.text
	.def	__ZN3dbgL12logAsWarningEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL12logAsWarningEhPKcz:
LFB4522:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4522
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
	call	__ZN3dbg7message14vlogAsWarningGEhPKcPc
LEHE52:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L648
L647:
	movl	%eax, (%esp)
LEHB53:
	call	__Unwind_Resume
LEHE53:
L648:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4522:
	.section	.gcc_except_table,"w"
LLSDA4522:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4522-LLSDACSB4522
LLSDACSB4522:
	.uleb128 LEHB52-LFB4522
	.uleb128 LEHE52-LEHB52
	.uleb128 L647-LFB4522
	.uleb128 0
	.uleb128 LEHB53-LFB4522
	.uleb128 LEHE53-LEHB53
	.uleb128 0
	.uleb128 0
LLSDACSE4522:
	.text
	.def	__ZN3dbgL15noticeAsWarningEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL15noticeAsWarningEhPKcz:
LFB4523:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4523
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
	call	__ZN3dbg7message17vnoticeAsWarningGEhPKcPc
LEHE54:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L653
L652:
	movl	%eax, (%esp)
LEHB55:
	call	__Unwind_Resume
LEHE55:
L653:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4523:
	.section	.gcc_except_table,"w"
LLSDA4523:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4523-LLSDACSB4523
LLSDACSB4523:
	.uleb128 LEHB54-LFB4523
	.uleb128 LEHE54-LEHB54
	.uleb128 L652-LFB4523
	.uleb128 0
	.uleb128 LEHB55-LFB4523
	.uleb128 LEHE55-LEHB55
	.uleb128 0
	.uleb128 0
LLSDACSE4523:
	.text
	.def	__ZN3dbgL15printAsCriticalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL15printAsCriticalEhPKcz:
LFB4524:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4524
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
	call	__ZN3dbg7message17vprintAsCriticalGEhPKcPc
LEHE56:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L658
L657:
	movl	%eax, (%esp)
LEHB57:
	call	__Unwind_Resume
LEHE57:
L658:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4524:
	.section	.gcc_except_table,"w"
LLSDA4524:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4524-LLSDACSB4524
LLSDACSB4524:
	.uleb128 LEHB56-LFB4524
	.uleb128 LEHE56-LEHB56
	.uleb128 L657-LFB4524
	.uleb128 0
	.uleb128 LEHB57-LFB4524
	.uleb128 LEHE57-LEHB57
	.uleb128 0
	.uleb128 0
LLSDACSE4524:
	.text
	.def	__ZN3dbgL13logAsCriticalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL13logAsCriticalEhPKcz:
LFB4525:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4525
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
	call	__ZN3dbg7message15vlogAsCriticalGEhPKcPc
LEHE58:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L663
L662:
	movl	%eax, (%esp)
LEHB59:
	call	__Unwind_Resume
LEHE59:
L663:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4525:
	.section	.gcc_except_table,"w"
LLSDA4525:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4525-LLSDACSB4525
LLSDACSB4525:
	.uleb128 LEHB58-LFB4525
	.uleb128 LEHE58-LEHB58
	.uleb128 L662-LFB4525
	.uleb128 0
	.uleb128 LEHB59-LFB4525
	.uleb128 LEHE59-LEHB59
	.uleb128 0
	.uleb128 0
LLSDACSE4525:
	.text
	.def	__ZN3dbgL16noticeAsCriticalEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL16noticeAsCriticalEhPKcz:
LFB4526:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4526
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
	call	__ZN3dbg7message18vnoticeAsCriticalGEhPKcPc
LEHE60:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L668
L667:
	movl	%eax, (%esp)
LEHB61:
	call	__Unwind_Resume
LEHE61:
L668:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4526:
	.section	.gcc_except_table,"w"
LLSDA4526:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4526-LLSDACSB4526
LLSDACSB4526:
	.uleb128 LEHB60-LFB4526
	.uleb128 LEHE60-LEHB60
	.uleb128 L667-LFB4526
	.uleb128 0
	.uleb128 LEHB61-LFB4526
	.uleb128 LEHE61-LEHB61
	.uleb128 0
	.uleb128 0
LLSDACSE4526:
	.text
	.def	__ZN3dbgL15printAsAbsoluteEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL15printAsAbsoluteEhPKcz:
LFB4527:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4527
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
	call	__ZN3dbg7message17vprintAsAbsoluteGEhPKcPc
LEHE62:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L673
L672:
	movl	%eax, (%esp)
LEHB63:
	call	__Unwind_Resume
LEHE63:
L673:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4527:
	.section	.gcc_except_table,"w"
LLSDA4527:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4527-LLSDACSB4527
LLSDACSB4527:
	.uleb128 LEHB62-LFB4527
	.uleb128 LEHE62-LEHB62
	.uleb128 L672-LFB4527
	.uleb128 0
	.uleb128 LEHB63-LFB4527
	.uleb128 LEHE63-LEHB63
	.uleb128 0
	.uleb128 0
LLSDACSE4527:
	.text
	.def	__ZN3dbgL13logAsAbsoluteEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL13logAsAbsoluteEhPKcz:
LFB4528:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4528
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
	call	__ZN3dbg7message15vlogAsAbsoluteGEhPKcPc
LEHE64:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L678
L677:
	movl	%eax, (%esp)
LEHB65:
	call	__Unwind_Resume
LEHE65:
L678:
	leave
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
	.uleb128 LEHB64-LFB4528
	.uleb128 LEHE64-LEHB64
	.uleb128 L677-LFB4528
	.uleb128 0
	.uleb128 LEHB65-LFB4528
	.uleb128 LEHE65-LEHB65
	.uleb128 0
	.uleb128 0
LLSDACSE4528:
	.text
	.def	__ZN3dbgL16noticeAsAbsoluteEhPKcz;	.scl	3;	.type	32;	.endef
__ZN3dbgL16noticeAsAbsoluteEhPKcz:
LFB4529:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4529
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
	call	__ZN3dbg7message18vnoticeAsAbsoluteGEhPKcPc
LEHE66:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L683
L682:
	movl	%eax, (%esp)
LEHB67:
	call	__Unwind_Resume
LEHE67:
L683:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4529:
	.section	.gcc_except_table,"w"
LLSDA4529:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4529-LLSDACSB4529
LLSDACSB4529:
	.uleb128 LEHB66-LFB4529
	.uleb128 LEHE66-LEHB66
	.uleb128 L682-LFB4529
	.uleb128 0
	.uleb128 LEHB67-LFB4529
	.uleb128 LEHE67-LEHB67
	.uleb128 0
	.uleb128 0
LLSDACSE4529:
	.text
	.section	.text$_ZN3dbg17category_reservedILh8ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_reservedILh8ELb1ELb1EED2Ev
	.def	__ZN3dbg17category_reservedILh8ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_reservedILh8ELb1ELb1EED2Ev:
LFB4532:
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
LFE4532:
	.section .rdata,"dr"
LC38:
	.ascii "forReserved01\0"
	.section	.text$_ZN3dbg3ext22category_forReserved01C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg3ext22category_forReserved01C1Ev
	.def	__ZN3dbg3ext22category_forReserved01C1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg3ext22category_forReserved01C1Ev:
LFB4535:
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
	call	__ZN3dbg17category_reservedILh8ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4535:
	.section	.text$_ZN3dbg17category_reservedILh9ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_reservedILh9ELb1ELb1EED2Ev
	.def	__ZN3dbg17category_reservedILh9ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_reservedILh9ELb1ELb1EED2Ev:
LFB4538:
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
LFE4538:
	.section .rdata,"dr"
LC39:
	.ascii "forReserved02\0"
	.section	.text$_ZN3dbg3ext22category_forReserved02C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg3ext22category_forReserved02C1Ev
	.def	__ZN3dbg3ext22category_forReserved02C1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg3ext22category_forReserved02C1Ev:
LFB4541:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC39, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg17category_reservedILh9ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4541:
	.section	.text$_ZN3dbg17category_reservedILh10ELb1ELb1EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_reservedILh10ELb1ELb1EED2Ev
	.def	__ZN3dbg17category_reservedILh10ELb1ELb1EED2Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_reservedILh10ELb1ELb1EED2Ev:
LFB4544:
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
LFE4544:
	.section .rdata,"dr"
LC40:
	.ascii "forReserved03\0"
	.section	.text$_ZN3dbg3ext22category_forReserved03C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg3ext22category_forReserved03C1Ev
	.def	__ZN3dbg3ext22category_forReserved03C1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg3ext22category_forReserved03C1Ev:
LFB4547:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$LC40, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN3dbg17category_reservedILh10ELb1ELb1EEC2EPKc
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4547:
	.section	.text$_ZN3dbg3ext22category_forReserved01D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg3ext22category_forReserved01D1Ev
	.def	__ZN3dbg3ext22category_forReserved01D1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg3ext22category_forReserved01D1Ev:
LFB4551:
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
LFE4551:
	.section	.text$_ZN3dbg3ext22category_forReserved02D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg3ext22category_forReserved02D1Ev
	.def	__ZN3dbg3ext22category_forReserved02D1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg3ext22category_forReserved02D1Ev:
LFB4554:
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
LFE4554:
	.section	.text$_ZN3dbg3ext22category_forReserved03D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg3ext22category_forReserved03D1Ev
	.def	__ZN3dbg3ext22category_forReserved03D1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg3ext22category_forReserved03D1Ev:
LFB4557:
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
LFE4557:
	.section	.text$_ZN3dbg3ext20categoryContainerExtC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg3ext20categoryContainerExtC1Ev
	.def	__ZN3dbg3ext20categoryContainerExtC1Ev;	.scl	2;	.type	32;	.endef
__ZN3dbg3ext20categoryContainerExtC1Ev:
LFB4559:
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
LFE4559:
.lcomm __ZN3dbg3extL23s_categoryForInitializeE,1,1
	.section .rdata,"dr"
	.align 4
LC41:
	.ascii "---------- printCommon() ----------\0"
LC42:
	.ascii "logLevel=%s, noticeLevel=%s\12\0"
LC43:
	.ascii "\343\203\206\343\202\271\343\203\210\0"
LC44:
	.ascii "\351\200\232\345\270\270\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC45:
	.ascii "\345\206\227\351\225\267\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC46:
	.ascii "\350\251\263\347\264\260\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC47:
	.ascii "\351\207\215\350\246\201\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC48:
	.ascii "\350\255\246\345\221\212\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC49:
	.ascii "\351\207\215\345\244\247\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
LC50:
	.ascii "\347\265\266\345\257\276\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
	.align 4
LC51:
	.ascii "\343\200\220\343\203\255\343\202\260\345\207\272\345\212\233\345\260\202\347\224\250\343\200\221\351\207\215\345\244\247\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
	.align 4
LC52:
	.ascii "\343\200\220\347\224\273\351\235\242\351\200\232\347\237\245\345\260\202\347\224\250\343\200\221\351\207\215\345\244\247\343\203\241\343\203\203\343\202\273\343\203\274\343\202\270 by %s\12\0"
	.text
	.globl	__Z11printCommonv
	.def	__Z11printCommonv;	.scl	2;	.type	32;	.endef
__Z11printCommonv:
LFB4560:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4560
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	$LC41, (%esp)
LEHB68:
	call	_puts
	movl	$0, (%esp)
	call	__ZN3dbg11getLogLevelEh
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelC1Eh
LEHE68:
	movl	$0, (%esp)
LEHB69:
	call	__ZN3dbg14getNoticeLevelEh
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelC1Eh
LEHE69:
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level4nameEv
	movl	%eax, %ebx
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg5level4nameEv
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC42, (%esp)
LEHB70:
	call	_printf
	movl	$LC43, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC44, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL13printAsNormalEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC45, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL14printAsVerboseEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC46, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL13printAsDetailEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC47, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL16printAsImportantEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC48, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL14printAsWarningEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL15printAsCriticalEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC50, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL15printAsAbsoluteEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$LC44, 8(%esp)
	movl	$0, 4(%esp)
	movl	$2, (%esp)
	call	__ZN3dbgL5printEhhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC51, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL13logAsCriticalEhPKcz
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC52, 4(%esp)
	movl	$0, (%esp)
	call	__ZN3dbgL16noticeAsCriticalEhPKcz
LEHE70:
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD1Ev
	jmp	L707
L706:
	movl	%eax, %ebx
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD1Ev
	jmp	L702
L705:
	movl	%eax, %ebx
L702:
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg5levelD1Ev
	movl	%ebx, %eax
	jmp	L703
L704:
L703:
	movl	%eax, (%esp)
LEHB71:
	call	__Unwind_Resume
LEHE71:
L707:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4560:
	.section	.gcc_except_table,"w"
LLSDA4560:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4560-LLSDACSB4560
LLSDACSB4560:
	.uleb128 LEHB68-LFB4560
	.uleb128 LEHE68-LEHB68
	.uleb128 L704-LFB4560
	.uleb128 0
	.uleb128 LEHB69-LFB4560
	.uleb128 LEHE69-LEHB69
	.uleb128 L705-LFB4560
	.uleb128 0
	.uleb128 LEHB70-LFB4560
	.uleb128 LEHE70-LEHB70
	.uleb128 L706-LFB4560
	.uleb128 0
	.uleb128 LEHB71-LFB4560
	.uleb128 LEHE71-LEHB71
	.uleb128 0
	.uleb128 0
LLSDACSE4560:
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC53:
	.ascii "call_point.cpp(1965)  [Fri Feb 28 15:46:27 2014]\0"
LC54:
	.ascii "\343\203\206\343\202\271\343\203\210\345\207\246\347\220\206\0"
LC55:
	.ascii "print:\343\203\206\343\202\271\343\203\210\357\274\210%d\357\274\211\12\0"
LC56:
	.ascii "log:\343\203\206\343\202\271\343\203\210\357\274\210%d\357\274\211\12\0"
LC57:
	.ascii "notice:\343\203\206\343\202\271\343\203\210\357\274\210%d\357\274\211\12\0"
	.align 4
LC58:
	.ascii "name=\"%s\", srcFile=\"%s\", funcName=\"%s\"\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB4561:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4561
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$336, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	call	___main
LEHB72:
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
LEHE72:
	movl	$__ZZ4mainE19__PRETTY_FUNCTION__, 20(%esp)
	movl	$LC53, 16(%esp)
	movl	$LC54, 12(%esp)
	movl	$8, 8(%esp)
	movl	$8, 4(%esp)
	leal	40(%esp), %eax
	movl	%eax, (%esp)
LEHB73:
	call	__ZN3dbg7messageC1EhhPKcS2_S2_
LEHE73:
	movl	$1, 8(%esp)
	movl	$LC55, 4(%esp)
	leal	40(%esp), %eax
	movl	%eax, (%esp)
LEHB74:
	call	__ZN3dbg7message13printAsNormalEPKcz
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message16resetLogLevelAllEv
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message19resetNoticeLevelAllEv
	movl	$2, 8(%esp)
	movl	$LC55, 4(%esp)
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message13printAsNormalEPKcz
	movl	$3, 8(%esp)
	movl	$LC56, 4(%esp)
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message3logEPKcz
	movl	$4, 8(%esp)
	movl	$LC57, 4(%esp)
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message6noticeEPKcz
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message11getFuncnameEv
	movl	%eax, %esi
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message14getSrcFileNameEv
	movl	%eax, %ebx
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNK3dbg7message7getNameEv
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$LC58, 4(%esp)
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message11logAsNormalEPKcz
LEHE74:
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7messageD1Ev
	movl	$64, 4(%esp)
	movl	$12, (%esp)
LEHB75:
	call	__ZN3dbg11setLogLevelEhh
	movl	$64, 4(%esp)
	movl	$12, (%esp)
	call	__ZN3dbg14setNoticeLevelEhh
	call	__Z11printCommonv
	call	__ZN3dbg16resetLogLevelAllEv
	call	__ZN3dbg19resetNoticeLevelAllEv
	call	__Z11printCommonv
LEHE75:
	leal	188(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7messageC1Ev
	movl	$4, (%esp)
LEHB76:
	call	__ZN3dbg7message12getLogLevelGEh
	movl	$4, 4(%esp)
	leal	188(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7message11getLogLevelEh
LEHE76:
	movl	$0, %ebx
	leal	188(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7messageD1Ev
	movl	%ebx, %eax
	jmp	L718
L716:
	movl	%eax, %ebx
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7messageD1Ev
	movl	%ebx, %eax
	jmp	L712
L715:
	jmp	L712
L717:
	movl	%eax, %ebx
	leal	188(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN3dbg7messageD1Ev
	movl	%ebx, %eax
	jmp	L712
L714:
L712:
	movl	%eax, (%esp)
LEHB77:
	call	__Unwind_Resume
LEHE77:
L718:
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
LFE4561:
	.section	.gcc_except_table,"w"
LLSDA4561:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4561-LLSDACSB4561
LLSDACSB4561:
	.uleb128 LEHB72-LFB4561
	.uleb128 LEHE72-LEHB72
	.uleb128 L714-LFB4561
	.uleb128 0
	.uleb128 LEHB73-LFB4561
	.uleb128 LEHE73-LEHB73
	.uleb128 L715-LFB4561
	.uleb128 0
	.uleb128 LEHB74-LFB4561
	.uleb128 LEHE74-LEHB74
	.uleb128 L716-LFB4561
	.uleb128 0
	.uleb128 LEHB75-LFB4561
	.uleb128 LEHE75-LEHB75
	.uleb128 L714-LFB4561
	.uleb128 0
	.uleb128 LEHB76-LFB4561
	.uleb128 LEHE76-LEHB76
	.uleb128 L717-LFB4561
	.uleb128 0
	.uleb128 LEHB77-LFB4561
	.uleb128 LEHE77-LEHB77
	.uleb128 0
	.uleb128 0
LLSDACSE4561:
	.text
	.section	.text$_ZNSt6bitsetILj14EEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EEixEj
	.def	__ZNSt6bitsetILj14EEixEj;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EEixEj:
LFB4598:
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
LFE4598:
	.section	.text$_ZNSt6bitsetILj14EE9referenceD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE9referenceD1Ev
	.def	__ZNSt6bitsetILj14EE9referenceD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE9referenceD1Ev:
LFB4601:
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
LFE4601:
	.section	.text$_ZNKSt6bitsetILj14EE9referencecvbEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6bitsetILj14EE9referencecvbEv
	.def	__ZNKSt6bitsetILj14EE9referencecvbEv;	.scl	2;	.type	32;	.endef
__ZNKSt6bitsetILj14EE9referencecvbEv:
LFB4602:
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
LFE4602:
	.section	.text$_ZNSt6bitsetILj14EE9referenceaSEb,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE9referenceaSEb
	.def	__ZNSt6bitsetILj14EE9referenceaSEb;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE9referenceaSEb:
LFB4603:
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
	je	L726
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
	jmp	L727
L726:
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
L727:
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4603:
	.section	.text$_ZN3dbg12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc
	.def	__ZN3dbg12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh2ELb1ELb1ELNS_5color7color_tE16ELS2_16ELS2_0ELS2_15EEC2EPKc:
LFB4605:
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
LFE4605:
	.section	.text$_ZN3dbg12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc
	.def	__ZN3dbg12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh0ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc:
LFB4608:
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
LFE4608:
	.section	.text$_ZN3dbg12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc
	.def	__ZN3dbg12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh1ELb1ELb0ELNS_5color7color_tE8ELS2_0ELS2_8ELS2_15EEC2EPKc:
LFB4611:
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
LFE4611:
	.section	.text$_ZN3dbg12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc
	.def	__ZN3dbg12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh4ELb1ELb1ELNS_5color7color_tE12ELS2_0ELS2_12ELS2_15EEC2EPKc:
LFB4614:
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
LFE4614:
	.section	.text$_ZN3dbg12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc
	.def	__ZN3dbg12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh6ELb1ELb1ELNS_5color7color_tE13ELS2_0ELS2_0ELS2_13EEC2EPKc:
LFB4617:
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
LFE4617:
	.section	.text$_ZN3dbg12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc
	.def	__ZN3dbg12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh8ELb1ELb1ELNS_5color7color_tE9ELS2_0ELS2_11ELS2_9EEC2EPKc:
LFB4620:
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
LFE4620:
	.section	.text$_ZN3dbg12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc
	.def	__ZN3dbg12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg12level_normalILh10ELb1ELb0ELNS_5color7color_tE32ELS2_32ELS2_32ELS2_32EEC2EPKc:
LFB4623:
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
LFE4623:
	.section	.text$_ZN3dbg13level_specialILh11EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg13level_specialILh11EEC2EPKc
	.def	__ZN3dbg13level_specialILh11EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg13level_specialILh11EEC2EPKc:
LFB4626:
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
LFE4626:
	.section	.text$_ZN3dbg13level_specialILh12EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg13level_specialILh12EEC2EPKc
	.def	__ZN3dbg13level_specialILh12EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg13level_specialILh12EEC2EPKc:
LFB4629:
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
LFE4629:
	.section	.text$_ZNSt6bitsetILj14EE5resetEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE5resetEv
	.def	__ZNSt6bitsetILj14EE5resetEv;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE5resetEv:
LFB4631:
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
LFE4631:
	.section	.text$_ZNSt6bitsetILj68EEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EEixEj
	.def	__ZNSt6bitsetILj68EEixEj;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EEixEj:
LFB4632:
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
LFE4632:
	.section	.text$_ZNSt6bitsetILj68EE9referenceD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE9referenceD1Ev
	.def	__ZNSt6bitsetILj68EE9referenceD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE9referenceD1Ev:
LFB4635:
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
LFE4635:
	.section	.text$_ZNSt12_Base_bitsetILj3EE11_S_whichbitEj,"x"
	.linkonce discard
	.globl	__ZNSt12_Base_bitsetILj3EE11_S_whichbitEj
	.def	__ZNSt12_Base_bitsetILj3EE11_S_whichbitEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE11_S_whichbitEj:
LFB4638:
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
LFE4638:
	.section	.text$_ZNSt12_Base_bitsetILj3EE10_S_maskbitEj,"x"
	.linkonce discard
	.globl	__ZNSt12_Base_bitsetILj3EE10_S_maskbitEj
	.def	__ZNSt12_Base_bitsetILj3EE10_S_maskbitEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE10_S_maskbitEj:
LFB4637:
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
LFE4637:
	.section	.text$_ZNKSt6bitsetILj68EE9referencecvbEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6bitsetILj68EE9referencecvbEv
	.def	__ZNKSt6bitsetILj68EE9referencecvbEv;	.scl	2;	.type	32;	.endef
__ZNKSt6bitsetILj68EE9referencecvbEv:
LFB4636:
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
LFE4636:
	.section	.text$_ZNSt6bitsetILj68EE9referenceaSEb,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE9referenceaSEb
	.def	__ZNSt6bitsetILj68EE9referenceaSEb;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE9referenceaSEb:
LFB4639:
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
	je	L751
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
	jmp	L752
L751:
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
L752:
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4639:
	.section	.text$_ZN3dbg17category_assignedILh0ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh0ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh0ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh0ELb1ELb1EEC2EPKc:
LFB4641:
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
LFE4641:
	.section	.text$_ZN3dbg17category_assignedILh1ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh1ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh1ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh1ELb1ELb1EEC2EPKc:
LFB4644:
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
LFE4644:
	.section	.text$_ZN3dbg17category_assignedILh2ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh2ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh2ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh2ELb1ELb1EEC2EPKc:
LFB4647:
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
LFE4647:
	.section	.text$_ZN3dbg17category_assignedILh3ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh3ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh3ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh3ELb1ELb1EEC2EPKc:
LFB4650:
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
LFE4650:
	.section	.text$_ZN3dbg17category_assignedILh4ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh4ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh4ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh4ELb1ELb1EEC2EPKc:
LFB4653:
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
LFE4653:
	.section	.text$_ZN3dbg17category_assignedILh5ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh5ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh5ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh5ELb1ELb1EEC2EPKc:
LFB4656:
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
LFE4656:
	.section	.text$_ZN3dbg17category_assignedILh6ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh6ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh6ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh6ELb1ELb1EEC2EPKc:
LFB4659:
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
LFE4659:
	.section	.text$_ZN3dbg17category_assignedILh7ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_assignedILh7ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_assignedILh7ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_assignedILh7ELb1ELb1EEC2EPKc:
LFB4662:
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
LFE4662:
	.section	.text$_ZN3dbg16category_specialILh64ELb0ELb0ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg16category_specialILh64ELb0ELb0ELb1EEC2EPKc
	.def	__ZN3dbg16category_specialILh64ELb0ELb0ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg16category_specialILh64ELb0ELb0ELb1EEC2EPKc:
LFB4665:
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
LFE4665:
	.section	.text$_ZN3dbg16category_specialILh65ELb1ELb1ELb0EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg16category_specialILh65ELb1ELb1ELb0EEC2EPKc
	.def	__ZN3dbg16category_specialILh65ELb1ELb1ELb0EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg16category_specialILh65ELb1ELb1ELb0EEC2EPKc:
LFB4668:
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
LFE4668:
	.section	.text$_ZN3dbg16category_specialILh66ELb1ELb1ELb0EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg16category_specialILh66ELb1ELb1ELb0EEC2EPKc
	.def	__ZN3dbg16category_specialILh66ELb1ELb1ELb0EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg16category_specialILh66ELb1ELb1ELb0EEC2EPKc:
LFB4671:
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
LFE4671:
	.section	.text$_ZNSt6bitsetILj68EE5resetEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE5resetEv
	.def	__ZNSt6bitsetILj68EE5resetEv;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE5resetEv:
LFB4673:
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
LFE4673:
	.section	.text$_ZN3dbg17category_reservedILh8ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_reservedILh8ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_reservedILh8ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_reservedILh8ELb1ELb1EEC2EPKc:
LFB4675:
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
LFE4675:
	.section	.text$_ZN3dbg17category_reservedILh9ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_reservedILh9ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_reservedILh9ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_reservedILh9ELb1ELb1EEC2EPKc:
LFB4678:
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
LFE4678:
	.section	.text$_ZN3dbg17category_reservedILh10ELb1ELb1EEC2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3dbg17category_reservedILh10ELb1ELb1EEC2EPKc
	.def	__ZN3dbg17category_reservedILh10ELb1ELb1EEC2EPKc;	.scl	2;	.type	32;	.endef
__ZN3dbg17category_reservedILh10ELb1ELb1EEC2EPKc:
LFB4681:
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
LFE4681:
	.section	.text$_ZNSt6bitsetILj14EE9referenceC1ERS0_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj14EE9referenceC1ERS0_j
	.def	__ZNSt6bitsetILj14EE9referenceC1ERS0_j;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj14EE9referenceC1ERS0_j:
LFB4706:
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
LFE4706:
	.section	.text$_ZNSt6bitsetILj68EE9referenceC1ERS0_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6bitsetILj68EE9referenceC1ERS0_j
	.def	__ZNSt6bitsetILj68EE9referenceC1ERS0_j;	.scl	2;	.type	32;	.endef
__ZNSt6bitsetILj68EE9referenceC1ERS0_j:
LFB4709:
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
LFE4709:
	.section	.text$_ZNSt12_Base_bitsetILj3EE11_M_do_resetEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Base_bitsetILj3EE11_M_do_resetEv
	.def	__ZNSt12_Base_bitsetILj3EE11_M_do_resetEv;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE11_M_do_resetEv:
LFB4710:
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
LFE4710:
	.section	.text$_ZNSt12_Base_bitsetILj3EE12_S_whichwordEj,"x"
	.linkonce discard
	.globl	__ZNSt12_Base_bitsetILj3EE12_S_whichwordEj
	.def	__ZNSt12_Base_bitsetILj3EE12_S_whichwordEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE12_S_whichwordEj:
LFB4721:
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
LFE4721:
	.section	.text$_ZNSt12_Base_bitsetILj3EE10_M_getwordEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Base_bitsetILj3EE10_M_getwordEj
	.def	__ZNSt12_Base_bitsetILj3EE10_M_getwordEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Base_bitsetILj3EE10_M_getwordEj:
LFB4720:
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
LFE4720:
	.text
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB4733:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L778
	cmpl	$65535, 12(%ebp)
	jne	L778
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
L778:
	cmpl	$0, 8(%ebp)
	jne	L777
	cmpl	$65535, 12(%ebp)
	jne	L777
	movl	$__ZN3dbgL22s_messageForInitializeE, (%esp)
	call	__ZN3dbg7messageD1Ev
	movl	$__ZN3dbgL23s_categoryForInitializeE, (%esp)
	call	__ZN3dbg8categoryD1Ev
	movl	$__ZN3dbgL20s_levelForInitializeE, (%esp)
	call	__ZN3dbg5levelD1Ev
	movl	$__ZN3dbgL20s_colorForInitializeE, (%esp)
	call	__ZN3dbg5colorD1Ev
L777:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4733:
	.def	__GLOBAL__sub_I__Z11getFileNamePKc;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z11getFileNamePKc:
LFB4734:
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
LFE4734:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z11getFileNamePKc
	.text
	.def	__GLOBAL__sub_D__Z11getFileNamePKc;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_D__Z11getFileNamePKc:
LFB4735:
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
LFE4735:
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
__ZZN3dbg7message11getLogLevelEhE19__PRETTY_FUNCTION__:
	.ascii "dbg::level::value_t dbg::message::getLogLevel(dbg::category::value_t)\0"
	.align 32
__ZZN3dbg7message14getNoticeLevelEhE19__PRETTY_FUNCTION__:
	.ascii "dbg::level::value_t dbg::message::getNoticeLevel(dbg::category::value_t)\0"
	.align 32
__ZZN3dbg7message12vprintCommonEhhhhPKcPcE19__PRETTY_FUNCTION__:
	.ascii "static int dbg::message::vprintCommon(dbg::level::value_t, dbg::level::value_t, dbg::level::value_t, dbg::category::value_t, const char*, va_list)\0"
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
	.def	_fputc;	.scl	2;	.type	32;	.endef
	.def	_vfprintf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef

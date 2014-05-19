	.file	"sub.cpp"
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
	.text
	.globl	__Z9initOpt01R11dataOpt01_t
	.def	__Z9initOpt01R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z9initOpt01R11dataOpt01_t:
LFB2054:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2054
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$2552, %esp
	movl	$5489, 4(%esp)
	leal	-2532(%ebp), %eax
	movl	%eax, (%esp)
LEHB0:
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC1Ej
	movl	$10, 8(%esp)
	movl	$0, 4(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt24uniform_int_distributionIiEC1Eii
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-16(%ebp), %eax
	addl	$40000, %eax
	movl	%eax, -20(%ebp)
	jmp	L2
L3:
	movl	-12(%ebp), %eax
	movl	%eax, -24(%ebp)
	leal	-2532(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_
LEHE0:
	movl	-24(%ebp), %edx
	movl	%eax, (%edx)
	addl	$4, -12(%ebp)
L2:
	movl	-12(%ebp), %eax
	cmpl	-20(%ebp), %eax
	jne	L3
	jmp	L6
L5:
	movl	%eax, (%esp)
LEHB1:
	call	__Unwind_Resume
LEHE1:
L6:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2054:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA2054:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2054-LLSDACSB2054
LLSDACSB2054:
	.uleb128 LEHB0-LFB2054
	.uleb128 LEHE0-LEHB0
	.uleb128 L5-LFB2054
	.uleb128 0
	.uleb128 LEHB1-LFB2054
	.uleb128 LEHE1-LEHB1
	.uleb128 0
	.uleb128 0
LLSDACSE2054:
	.text
	.globl	__Z22testOpt01_Type1_BeforeR11dataOpt01_t
	.def	__Z22testOpt01_Type1_BeforeR11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z22testOpt01_Type1_BeforeR11dataOpt01_t:
LFB2055:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	L8
L9:
	movl	8(%ebp), %eax
	movl	(%eax), %ecx
	movl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	4(%eax,%edx,4), %eax
	leal	(%ecx,%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	addl	$1, -12(%ebp)
L8:
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__Z8extentofIN11dataOpt01_t6elem_tELj10000EEjRAT0__KT_
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	jne	L9
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2055:
	.globl	__Z22testOpt01_Type1_After1R11dataOpt01_t
	.def	__Z22testOpt01_Type1_After1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z22testOpt01_Type1_After1R11dataOpt01_t:
LFB2056:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L11
L12:
	movl	8(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	4(%eax,%edx,4), %eax
	addl	%eax, -12(%ebp)
	addl	$1, -16(%ebp)
L11:
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__Z8extentofIN11dataOpt01_t6elem_tELj10000EEjRAT0__KT_
	cmpl	-16(%ebp), %eax
	seta	%al
	testb	%al, %al
	jne	L12
	movl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2056:
	.globl	__Z22testOpt01_Type1_After2R11dataOpt01_t
	.def	__Z22testOpt01_Type1_After2R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z22testOpt01_Type1_After2R11dataOpt01_t:
LFB2057:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__Z8extentofIN11dataOpt01_t6elem_tELj10000EEjRAT0__KT_
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	addl	$4, %eax
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, -16(%ebp)
	jmp	L14
L15:
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	addl	%eax, -12(%ebp)
	addl	$4, -16(%ebp)
L14:
	movl	-16(%ebp), %eax
	cmpl	-20(%ebp), %eax
	jb	L15
	movl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2057:
	.globl	__Z24testOpt01_Type1_AppendixR11dataOpt01_t
	.def	__Z24testOpt01_Type1_AppendixR11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z24testOpt01_Type1_AppendixR11dataOpt01_t:
LFB2058:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-8(%ebp), %eax
	addl	$40000, %eax
	movl	%eax, -12(%ebp)
	jmp	L17
L18:
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	addl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	addl	$4, -4(%ebp)
L17:
	movl	-4(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jne	L18
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2058:
	.globl	__Z9initOpt02R11dataOpt02_t
	.def	__Z9initOpt02R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z9initOpt02R11dataOpt02_t:
LFB2059:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2059
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$2552, %esp
	movl	$5489, 4(%esp)
	leal	-2532(%ebp), %eax
	movl	%eax, (%esp)
LEHB2:
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC1Ej
	movl	$10, 8(%esp)
	movl	$0, 4(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt24uniform_int_distributionIiEC1Eii
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-16(%ebp), %eax
	addl	$40000, %eax
	movl	%eax, -20(%ebp)
	jmp	L20
L21:
	movl	-12(%ebp), %eax
	movl	%eax, -24(%ebp)
	leal	-2532(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_
LEHE2:
	movl	-24(%ebp), %edx
	movl	%eax, (%edx)
	addl	$4, -12(%ebp)
L20:
	movl	-12(%ebp), %eax
	cmpl	-20(%ebp), %eax
	jne	L21
	jmp	L24
L23:
	movl	%eax, (%esp)
LEHB3:
	call	__Unwind_Resume
LEHE3:
L24:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2059:
	.section	.gcc_except_table,"w"
LLSDA2059:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2059-LLSDACSB2059
LLSDACSB2059:
	.uleb128 LEHB2-LFB2059
	.uleb128 LEHE2-LEHB2
	.uleb128 L23-LFB2059
	.uleb128 0
	.uleb128 LEHB3-LFB2059
	.uleb128 LEHE3-LEHB3
	.uleb128 0
	.uleb128 0
LLSDACSE2059:
	.text
	.globl	__Z22testOpt02_Type1_BeforeR11dataOpt02_t
	.def	__Z22testOpt02_Type1_BeforeR11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z22testOpt02_Type1_BeforeR11dataOpt02_t:
LFB2060:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$136, %esp
	movl	$0, -12(%ebp)
	jmp	L26
L27:
	movl	-12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, -112(%ebp,%eax,8)
	movl	-12(%ebp), %eax
	movl	$0, -108(%ebp,%eax,8)
	addl	$1, -12(%ebp)
L26:
	movl	-12(%ebp), %eax
	cmpl	$10, %eax
	jbe	L27
	movl	$0, -16(%ebp)
	jmp	L28
L29:
	movl	8(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	movl	-108(%ebp,%eax,8), %edx
	addl	$1, %edx
	movl	%edx, -108(%ebp,%eax,8)
	addl	$1, -16(%ebp)
L28:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z8extentofIN11dataOpt02_t6elem_tELj10000EEjRAT0__KT_
	cmpl	-16(%ebp), %eax
	seta	%al
	testb	%al, %al
	jne	L29
	leal	-112(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	$1, -24(%ebp)
	jmp	L30
L32:
	movl	-20(%ebp), %eax
	movl	4(%eax), %edx
	movl	-24(%ebp), %eax
	movl	-108(%ebp,%eax,8), %eax
	cmpl	%eax, %edx
	jge	L31
	leal	-112(%ebp), %eax
	movl	-24(%ebp), %edx
	sall	$3, %edx
	addl	%edx, %eax
	movl	%eax, -20(%ebp)
L31:
	addl	$1, -24(%ebp)
L30:
	cmpl	$10, -24(%ebp)
	jbe	L32
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	sall	$16, %eax
	movl	%eax, %edx
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	orl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2060:
	.globl	__Z22testOpt02_Type1_After1R11dataOpt02_t
	.def	__Z22testOpt02_Type1_After1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z22testOpt02_Type1_After1R11dataOpt02_t:
LFB2061:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$136, %esp
	movl	$0, -12(%ebp)
	jmp	L35
L36:
	movl	-12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, -116(%ebp,%eax,8)
	movl	-12(%ebp), %eax
	movl	$0, -112(%ebp,%eax,8)
	addl	$1, -12(%ebp)
L35:
	movl	-12(%ebp), %eax
	cmpl	$10, %eax
	jbe	L36
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z8extentofIN11dataOpt02_t6elem_tELj10000EEjRAT0__KT_
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	jmp	L37
L38:
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	-112(%ebp,%eax,8), %edx
	addl	$1, %edx
	movl	%edx, -112(%ebp,%eax,8)
	addl	$4, -16(%ebp)
L37:
	movl	-16(%ebp), %eax
	cmpl	-28(%ebp), %eax
	jb	L38
	leal	-116(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	$1, -24(%ebp)
	jmp	L39
L41:
	movl	-20(%ebp), %eax
	movl	4(%eax), %edx
	movl	-24(%ebp), %eax
	movl	-112(%ebp,%eax,8), %eax
	cmpl	%eax, %edx
	jge	L40
	leal	-116(%ebp), %eax
	movl	-24(%ebp), %edx
	sall	$3, %edx
	addl	%edx, %eax
	movl	%eax, -20(%ebp)
L40:
	addl	$1, -24(%ebp)
L39:
	cmpl	$10, -24(%ebp)
	jbe	L41
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	sall	$16, %eax
	movl	%eax, %edx
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	orl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2061:
	.globl	__Z22testOpt02_Type1_After2R11dataOpt02_t
	.def	__Z22testOpt02_Type1_After2R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z22testOpt02_Type1_After2R11dataOpt02_t:
LFB2062:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$152, %esp
	leal	-124(%ebp), %eax
	addl	$88, %eax
	movl	%eax, -32(%ebp)
	movl	$0, -12(%ebp)
	leal	-124(%ebp), %eax
	movl	%eax, -16(%ebp)
	jmp	L44
L45:
	movl	-12(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -12(%ebp)
	movl	-16(%ebp), %edx
	movl	%eax, (%edx)
	movl	-16(%ebp), %eax
	movl	$0, 4(%eax)
	addl	$8, -16(%ebp)
L44:
	movl	-16(%ebp), %eax
	cmpl	-32(%ebp), %eax
	jb	L45
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z8extentofIN11dataOpt02_t6elem_tELj10000EEjRAT0__KT_
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -36(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -20(%ebp)
	jmp	L46
L47:
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	-120(%ebp,%eax,8), %edx
	addl	$1, %edx
	movl	%edx, -120(%ebp,%eax,8)
	addl	$4, -20(%ebp)
L46:
	movl	-20(%ebp), %eax
	cmpl	-36(%ebp), %eax
	jb	L47
	leal	-124(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	addl	$8, %eax
	movl	%eax, -28(%ebp)
	jmp	L48
L50:
	movl	-24(%ebp), %eax
	movl	4(%eax), %edx
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	%eax, %edx
	jge	L49
	movl	-28(%ebp), %eax
	movl	%eax, -24(%ebp)
L49:
	addl	$8, -28(%ebp)
L48:
	movl	-28(%ebp), %eax
	cmpl	-32(%ebp), %eax
	jb	L50
	movl	-24(%ebp), %eax
	movl	4(%eax), %eax
	sall	$16, %eax
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	movl	(%eax), %eax
	orl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2062:
	.globl	__Z22testOpt03_Type1_Beforeiii
	.def	__Z22testOpt03_Type1_Beforeiii;	.scl	2;	.type	32;	.endef
__Z22testOpt03_Type1_Beforeiii:
LFB2063:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	imull	12(%ebp), %eax
	movl	%eax, %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2063:
	.globl	__Z22testOpt03_Type2_Beforeiiiiiiii
	.def	__Z22testOpt03_Type2_Beforeiiiiiiii;	.scl	2;	.type	32;	.endef
__Z22testOpt03_Type2_Beforeiiiiiiii:
LFB2064:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	imull	12(%ebp), %eax
	movl	%eax, %edx
	movl	16(%ebp), %eax
	addl	%eax, %edx
	movl	20(%ebp), %eax
	imull	24(%ebp), %eax
	subl	%eax, %edx
	movl	28(%ebp), %eax
	addl	%eax, %edx
	movl	32(%ebp), %eax
	imull	36(%ebp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2064:
	.globl	__Z15initOpt03_Type3R11dataOpt03_t
	.def	__Z15initOpt03_Type3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z15initOpt03_Type3R11dataOpt03_t:
LFB2065:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2065
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$2552, %esp
	movl	$5489, 4(%esp)
	leal	-2532(%ebp), %eax
	movl	%eax, (%esp)
LEHB4:
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC1Ej
	movl	$10, 8(%esp)
	movl	$0, 4(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt24uniform_int_distributionIiEC1Eii
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-16(%ebp), %eax
	addl	$40000, %eax
	movl	%eax, -20(%ebp)
	jmp	L57
L58:
	movl	-12(%ebp), %eax
	movl	%eax, -24(%ebp)
	leal	-2532(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_
LEHE4:
	movl	-24(%ebp), %edx
	movl	%eax, (%edx)
	addl	$4, -12(%ebp)
L57:
	movl	-12(%ebp), %eax
	cmpl	-20(%ebp), %eax
	jne	L58
	jmp	L61
L60:
	movl	%eax, (%esp)
LEHB5:
	call	__Unwind_Resume
LEHE5:
L61:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2065:
	.section	.gcc_except_table,"w"
LLSDA2065:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2065-LLSDACSB2065
LLSDACSB2065:
	.uleb128 LEHB4-LFB2065
	.uleb128 LEHE4-LEHB4
	.uleb128 L60-LFB2065
	.uleb128 0
	.uleb128 LEHB5-LFB2065
	.uleb128 LEHE5-LEHB5
	.uleb128 0
	.uleb128 0
LLSDACSE2065:
	.text
	.section .rdata,"dr"
__ZStL13allocator_arg:
	.space 1
__ZStL6ignore:
	.space 1
	.section	.text$_ZNSt9_Any_data9_M_accessEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt9_Any_data9_M_accessEv
	.def	__ZNSt9_Any_data9_M_accessEv;	.scl	2;	.type	32;	.endef
__ZNSt9_Any_data9_M_accessEv:
LFB2349:
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
LFE2349:
	.section	.text$_ZNKSt9_Any_data9_M_accessEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt9_Any_data9_M_accessEv
	.def	__ZNKSt9_Any_data9_M_accessEv;	.scl	2;	.type	32;	.endef
__ZNKSt9_Any_data9_M_accessEv:
LFB2350:
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
LFE2350:
	.section	.text$_ZNSt14_Function_baseC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt14_Function_baseC2Ev
	.def	__ZNSt14_Function_baseC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt14_Function_baseC2Ev:
LFB2375:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	$0, 8(%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2375:
	.section	.text$_ZNSt14_Function_baseD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt14_Function_baseD2Ev
	.def	__ZNSt14_Function_baseD2Ev;	.scl	2;	.type	32;	.endef
__ZNSt14_Function_baseD2Ev:
LFB2378:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2378
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	testl	%eax, %eax
	je	L67
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	8(%ebp), %ecx
	movl	8(%ebp), %edx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L67:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2378:
	.section	.gcc_except_table,"w"
LLSDA2378:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2378-LLSDACSB2378
LLSDACSB2378:
LLSDACSE2378:
	.section	.text$_ZNSt14_Function_baseD2Ev,"x"
	.linkonce discard
	.section	.text$_ZNKSt14_Function_base8_M_emptyEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt14_Function_base8_M_emptyEv
	.def	__ZNKSt14_Function_base8_M_emptyEv;	.scl	2;	.type	32;	.endef
__ZNKSt14_Function_base8_M_emptyEv:
LFB2380:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	testl	%eax, %eax
	sete	%al
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2380:
	.text
	.align 2
	.def	__ZZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiENKUlRiE_clES2_;	.scl	3;	.type	32;	.endef
__ZZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiENKUlRiE_clES2_:
LFB2413:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2413:
	.section	.text$_ZNSt8functionIFvRiEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8functionIFvRiEED1Ev
	.def	__ZNSt8functionIFvRiEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8functionIFvRiEED1Ev:
LFB2416:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_baseD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2416:
	.text
	.align 2
	.def	__ZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEii;	.scl	3;	.type	32;	.endef
__ZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEii:
LFB2412:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2412
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	leal	16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
LEHB6:
	call	__ZNSt8functionIFvRiEEC1IZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_vEET_
LEHE6:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	leal	-24(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
LEHB7:
	call	__Z33commonProc_testOpt03_Type3_BeforeIiLj10000EEvRAT0__T_S0_St8functionIFvRiEE
LEHE7:
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8functionIFvRiEED1Ev
	jmp	L77
L76:
	movl	%eax, %ebx
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8functionIFvRiEED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB8:
	call	__Unwind_Resume
LEHE8:
L77:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2412:
	.section	.gcc_except_table,"w"
LLSDA2412:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2412-LLSDACSB2412
LLSDACSB2412:
	.uleb128 LEHB6-LFB2412
	.uleb128 LEHE6-LEHB6
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB7-LFB2412
	.uleb128 LEHE7-LEHB7
	.uleb128 L76-LFB2412
	.uleb128 0
	.uleb128 LEHB8-LFB2412
	.uleb128 LEHE8-LEHB8
	.uleb128 0
	.uleb128 0
LLSDACSE2412:
	.text
	.align 2
	.def	__ZZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiENKUlRiE_clES2_;	.scl	3;	.type	32;	.endef
__ZZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiENKUlRiE_clES2_:
LFB2418:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	addl	$1, %edx
	movl	%edx, (%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2418:
	.align 2
	.def	__ZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEi;	.scl	3;	.type	32;	.endef
__ZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEi:
LFB2417:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2417
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	$0, -28(%ebp)
	leal	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
LEHB9:
	call	__ZNSt8functionIFvRiEEC1IZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_vEET_
LEHE9:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	leal	-24(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB10:
	call	__Z33commonProc_testOpt03_Type3_BeforeIiLj10000EEvRAT0__T_S0_St8functionIFvRiEE
LEHE10:
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8functionIFvRiEED1Ev
	movl	-28(%ebp), %eax
	jmp	L85
L84:
	movl	%eax, %ebx
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8functionIFvRiEED1Ev
	movl	%ebx, %eax
	jmp	L82
L83:
L82:
	movl	%eax, (%esp)
LEHB11:
	call	__Unwind_Resume
LEHE11:
L85:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2417:
	.section	.gcc_except_table,"w"
LLSDA2417:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2417-LLSDACSB2417
LLSDACSB2417:
	.uleb128 LEHB9-LFB2417
	.uleb128 LEHE9-LEHB9
	.uleb128 L83-LFB2417
	.uleb128 0
	.uleb128 LEHB10-LFB2417
	.uleb128 LEHE10-LEHB10
	.uleb128 L84-LFB2417
	.uleb128 0
	.uleb128 LEHB11-LFB2417
	.uleb128 LEHE11-LEHB11
	.uleb128 0
	.uleb128 0
LLSDACSE2417:
	.text
	.globl	__Z22testOpt03_Type3_BeforeR11dataOpt03_t
	.def	__Z22testOpt03_Type3_BeforeR11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z22testOpt03_Type3_BeforeR11dataOpt03_t:
LFB2411:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2411
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	$1, 8(%esp)
	movl	$0, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
LEHB12:
	call	__ZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEii
	movl	$1, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEi
	movl	%eax, %ebx
	movl	$2, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEi
	addl	%eax, %ebx
	movl	$3, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEi
LEHE12:
	addl	%ebx, %eax
	jmp	L90
L89:
	movl	%eax, (%esp)
LEHB13:
	call	__Unwind_Resume
LEHE13:
L90:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2411:
	.section	.gcc_except_table,"w"
LLSDA2411:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2411-LLSDACSB2411
LLSDACSB2411:
	.uleb128 LEHB12-LFB2411
	.uleb128 LEHE12-LEHB12
	.uleb128 L89-LFB2411
	.uleb128 0
	.uleb128 LEHB13-LFB2411
	.uleb128 LEHE13-LEHB13
	.uleb128 0
	.uleb128 0
LLSDACSE2411:
	.text
	.align 2
	.def	__ZZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliiE_clEiiENKUlRiE_clES2_;	.scl	3;	.type	32;	.endef
__ZZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliiE_clEiiENKUlRiE_clES2_:
LFB2421:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2421:
	.align 2
	.def	__ZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliiE_clEii;	.scl	3;	.type	32;	.endef
__ZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliiE_clEii:
LFB2420:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	leal	16(%ebp), %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__Z32commonProc_testOpt03_Type3_AfterIiLj10000EZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliiE_clEiiEUlRiE_EvRAT0__T_S5_T1_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2420:
	.align 2
	.def	__ZZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliE0_clEiENKUlRiE_clES2_;	.scl	3;	.type	32;	.endef
__ZZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliE0_clEiENKUlRiE_clES2_:
LFB2423:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	addl	$1, %edx
	movl	%edx, (%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2423:
	.align 2
	.def	__ZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliE0_clEi;	.scl	3;	.type	32;	.endef
__ZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliE0_clEi:
LFB2422:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	leal	-12(%ebp), %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__Z32commonProc_testOpt03_Type3_AfterIiLj10000EZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliE0_clEiEUlRiE_EvRAT0__T_S5_T1_
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2422:
	.globl	__Z21testOpt03_Type3_AfterR11dataOpt03_t
	.def	__Z21testOpt03_Type3_AfterR11dataOpt03_t;	.scl	2;	.type	32;	.endef
__Z21testOpt03_Type3_AfterR11dataOpt03_t:
LFB2419:
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
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	$1, 8(%esp)
	movl	$0, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliiE_clEii
	movl	$1, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliE0_clEi
	movl	%eax, %ebx
	movl	$2, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliE0_clEi
	addl	%eax, %ebx
	movl	$3, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliE0_clEi
	addl	%ebx, %eax
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2419:
	.globl	__Z9initOpt04R11dataOpt04_t
	.def	__Z9initOpt04R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z9initOpt04R11dataOpt04_t:
LFB2424:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2424
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$2552, %esp
	movl	$5489, 4(%esp)
	leal	-2532(%ebp), %eax
	movl	%eax, (%esp)
LEHB14:
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC1Ej
	movl	$10, 8(%esp)
	movl	$0, 4(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt24uniform_int_distributionIiEC1Eii
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-16(%ebp), %eax
	addl	$80000, %eax
	movl	%eax, -20(%ebp)
	jmp	L99
L100:
	movl	-12(%ebp), %eax
	movl	%eax, -24(%ebp)
	leal	-2532(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_
LEHE14:
	movl	-24(%ebp), %edx
	movl	%eax, (%edx)
	movl	-24(%ebp), %edx
	movl	LC0, %eax
	movl	%eax, 4(%edx)
	addl	$8, -12(%ebp)
L99:
	movl	-12(%ebp), %eax
	cmpl	-20(%ebp), %eax
	jne	L100
	jmp	L103
L102:
	movl	%eax, (%esp)
LEHB15:
	call	__Unwind_Resume
LEHE15:
L103:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2424:
	.section	.gcc_except_table,"w"
LLSDA2424:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2424-LLSDACSB2424
LLSDACSB2424:
	.uleb128 LEHB14-LFB2424
	.uleb128 LEHE14-LEHB14
	.uleb128 L102-LFB2424
	.uleb128 0
	.uleb128 LEHB15-LFB2424
	.uleb128 LEHE15-LEHB15
	.uleb128 0
	.uleb128 0
LLSDACSE2424:
	.text
	.globl	__Z22testOpt04_Type1_BeforeR11dataOpt04_t
	.def	__Z22testOpt04_Type1_BeforeR11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type1_BeforeR11dataOpt04_t:
LFB2425:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	LC0, %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z8extentofIN11dataOpt04_t6elem_tELj10000EEjRAT0__KT_
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	jmp	L105
L106:
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -28(%ebp)
	fildl	-28(%ebp)
	flds	-12(%ebp)
	faddp	%st, %st(1)
	fstps	-12(%ebp)
	addl	$8, -16(%ebp)
L105:
	movl	-16(%ebp), %eax
	cmpl	-24(%ebp), %eax
	jb	L106
	movl	8(%ebp), %eax
	movl	%eax, -20(%ebp)
	jmp	L107
L108:
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -28(%ebp)
	fildl	-28(%ebp)
	fdivs	-12(%ebp)
	movl	-20(%ebp), %eax
	fstps	4(%eax)
	addl	$8, -20(%ebp)
L107:
	movl	-20(%ebp), %eax
	cmpl	-24(%ebp), %eax
	jb	L108
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2425:
	.globl	__Z22testOpt04_Type1_After1R11dataOpt04_t
	.def	__Z22testOpt04_Type1_After1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type1_After1R11dataOpt04_t:
LFB2426:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	LC0, %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z8extentofIN11dataOpt04_t6elem_tELj10000EEjRAT0__KT_
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	jmp	L110
L111:
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -44(%ebp)
	fildl	-44(%ebp)
	flds	-12(%ebp)
	faddp	%st, %st(1)
	fstps	-12(%ebp)
	addl	$8, -16(%ebp)
L110:
	movl	-16(%ebp), %eax
	cmpl	-24(%ebp), %eax
	jb	L111
	fld1
	fdivs	-12(%ebp)
	fstps	-28(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -20(%ebp)
	jmp	L112
L113:
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -44(%ebp)
	fildl	-44(%ebp)
	fmuls	-28(%ebp)
	movl	-20(%ebp), %eax
	fstps	4(%eax)
	addl	$8, -20(%ebp)
L112:
	movl	-20(%ebp), %eax
	cmpl	-24(%ebp), %eax
	jb	L113
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2426:
	.globl	__Z22testOpt04_Type1_After2R11dataOpt04_t
	.def	__Z22testOpt04_Type1_After2R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type1_After2R11dataOpt04_t:
LFB2427:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	$0, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z8extentofIN11dataOpt04_t6elem_tELj10000EEjRAT0__KT_
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	jmp	L115
L116:
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	addl	%eax, -12(%ebp)
	addl	$8, -16(%ebp)
L115:
	movl	-16(%ebp), %eax
	cmpl	-24(%ebp), %eax
	jb	L116
	fildl	-12(%ebp)
	fld1
	fdivp	%st, %st(1)
	fstps	-28(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -20(%ebp)
	jmp	L117
L118:
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -44(%ebp)
	fildl	-44(%ebp)
	fmuls	-28(%ebp)
	movl	-20(%ebp), %eax
	fstps	4(%eax)
	addl	$8, -20(%ebp)
L117:
	movl	-20(%ebp), %eax
	cmpl	-24(%ebp), %eax
	jb	L118
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2427:
	.section	.text$_ZNSt8functionIFivEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8functionIFivEED1Ev
	.def	__ZNSt8functionIFivEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8functionIFivEED1Ev:
LFB2430:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_baseD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2430:
	.globl	_s_lambda1
	.bss
	.align 4
_s_lambda1:
	.space 16
	.globl	_s_lambda2
	.align 4
_s_lambda2:
	.space 16
	.globl	_s_lambda3
	.align 4
_s_lambda3:
	.space 16
	.section .rdata,"dr"
	.align 4
LC3:
	.ascii "lambda1()=%d, lambda2()=%d, lambda3()=%d\12\0"
	.text
	.globl	__Z13callLambda123v
	.def	__Z13callLambda123v;	.scl	2;	.type	32;	.endef
__Z13callLambda123v:
LFB2431:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	$_s_lambda3, (%esp)
	call	__ZNKSt8functionIFivEEclEv
	movl	%eax, %esi
	movl	$_s_lambda2, (%esp)
	call	__ZNKSt8functionIFivEEclEv
	movl	%eax, %ebx
	movl	$_s_lambda1, (%esp)
	call	__ZNKSt8functionIFivEEclEv
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2431:
	.section .rdata,"dr"
	.align 4
LC4:
	.ascii "lambda1()=%d, lambda2()=NG!, lambda3()=%d\12\0"
	.text
	.globl	__Z12callLambda13v
	.def	__Z12callLambda13v;	.scl	2;	.type	32;	.endef
__Z12callLambda13v:
LFB2432:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	$_s_lambda3, (%esp)
	call	__ZNKSt8functionIFivEEclEv
	movl	%eax, %ebx
	movl	$_s_lambda1, (%esp)
	call	__ZNKSt8functionIFivEEclEv
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2432:
	.align 2
	.def	__ZZ9setLambdaRiENKUlvE_clEv;	.scl	3;	.type	32;	.endef
__ZZ9setLambdaRiENKUlvE_clEv:
LFB2434:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	addl	$1, %edx
	movl	%edx, (%eax)
	movl	(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2434:
	.align 2
	.def	__ZZ9setLambdaRiENKUlvE0_clEv;	.scl	3;	.type	32;	.endef
__ZZ9setLambdaRiENKUlvE0_clEv:
LFB2435:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	addl	$1, %edx
	movl	%edx, (%eax)
	movl	(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2435:
	.align 2
	.def	__ZZ9setLambdaRiENKUlvE1_clEv;	.scl	3;	.type	32;	.endef
__ZZ9setLambdaRiENKUlvE1_clEv:
LFB2436:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	__ZZ9setLambdaRiE14static_counter, %eax
	addl	$1, %eax
	movl	%eax, __ZZ9setLambdaRiE14static_counter
	movl	__ZZ9setLambdaRiE14static_counter, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2436:
	.section .rdata,"dr"
	.align 4
LC5:
	.ascii "for lambda1: external_counter=%d\12\0"
	.align 4
LC6:
	.ascii "for lambda2: local_counter=%d\12\0"
	.align 4
LC7:
	.ascii "for lambda3: static_counter=%d\12\0"
	.align 4
LC8:
	.ascii "Call lambda in block with counter in setLambda().\0"
LC9:
	.ascii "dummy=%d\12\0"
	.align 4
LC10:
	.ascii "Call lambda in block without counter in setLambda().\0"
	.text
	.globl	__Z9setLambdaRi
	.def	__Z9setLambdaRi;	.scl	2;	.type	32;	.endef
__Z9setLambdaRi:
LFB2433:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2433
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	$_s_lambda1, (%esp)
	call	__ZNKSt8functionIFivEEcvbEv
	xorl	$1, %eax
	testb	%al, %al
	jne	L130
	movl	$_s_lambda2, (%esp)
	call	__ZNKSt8functionIFivEEcvbEv
	xorl	$1, %eax
	testb	%al, %al
	je	L131
L130:
	movl	$1, %eax
	jmp	L132
L131:
	movl	$0, %eax
L132:
	testb	%al, %al
	je	L133
	movl	$0, -28(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
LEHB16:
	call	_printf
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	__ZZ9setLambdaRiE14static_counter, %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
LEHE16:
	movl	8(%ebp), %eax
	movl	%eax, -24(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$_s_lambda1, (%esp)
LEHB17:
	call	__ZNSt8functionIFivEEaSIZ9setLambdaRiEUlvE_EENSt9enable_ifIXsrSt5__or_IISt7is_voidIiESt14is_convertibleIDTclcl18__callable_functorcl7declvalIRT_EEEEEiEEE5valueERS1_E4typeEOSA_
LEHE17:
	leal	-28(%ebp), %eax
	movl	%eax, -20(%ebp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$_s_lambda2, (%esp)
LEHB18:
	call	__ZNSt8functionIFivEEaSIZ9setLambdaRiEUlvE0_EENSt9enable_ifIXsrSt5__or_IISt7is_voidIiESt14is_convertibleIDTclcl18__callable_functorcl7declvalIRT_EEEEEiEEE5valueERS1_E4typeEOSA_
LEHE18:
	leal	-13(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$_s_lambda3, (%esp)
LEHB19:
	call	__ZNSt8functionIFivEEaSIZ9setLambdaRiEUlvE1_EENSt9enable_ifIXsrSt5__or_IISt7is_voidIiESt14is_convertibleIDTclcl18__callable_functorcl7declvalIRT_EEEEEiEEE5valueERS1_E4typeEOSA_
LEHE19:
	movl	$LC8, (%esp)
LEHB20:
	call	_puts
	call	__Z13callLambda123v
	call	__Z13callLambda123v
	call	__Z13callLambda123v
LEHE20:
L133:
	movl	$999, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC9, (%esp)
LEHB21:
	call	_printf
	movl	$LC10, (%esp)
	call	_puts
	call	__Z13callLambda123v
	call	__Z13callLambda123v
	call	__Z13callLambda123v
	jmp	L142
L139:
	jmp	L135
L140:
	jmp	L135
L141:
	jmp	L135
L138:
L135:
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE21:
L142:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2433:
	.section	.gcc_except_table,"w"
LLSDA2433:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2433-LLSDACSB2433
LLSDACSB2433:
	.uleb128 LEHB16-LFB2433
	.uleb128 LEHE16-LEHB16
	.uleb128 L138-LFB2433
	.uleb128 0
	.uleb128 LEHB17-LFB2433
	.uleb128 LEHE17-LEHB17
	.uleb128 L139-LFB2433
	.uleb128 0
	.uleb128 LEHB18-LFB2433
	.uleb128 LEHE18-LEHB18
	.uleb128 L140-LFB2433
	.uleb128 0
	.uleb128 LEHB19-LFB2433
	.uleb128 LEHE19-LEHB19
	.uleb128 L141-LFB2433
	.uleb128 0
	.uleb128 LEHB20-LFB2433
	.uleb128 LEHE20-LEHB20
	.uleb128 L138-LFB2433
	.uleb128 0
	.uleb128 LEHB21-LFB2433
	.uleb128 LEHE21-LEHB21
	.uleb128 0
	.uleb128 0
LLSDACSE2433:
	.text
	.globl	__Z10getLambda1v
	.def	__Z10getLambda1v;	.scl	2;	.type	32;	.endef
__Z10getLambda1v:
LFB2439:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$_s_lambda1, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8functionIFivEEC1ERKS1_
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE2439:
	.globl	__Z10getLambda2v
	.def	__Z10getLambda2v;	.scl	2;	.type	32;	.endef
__Z10getLambda2v:
LFB2440:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$_s_lambda1, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8functionIFivEEC1ERKS1_
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE2440:
	.section	.text$_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC1Ej,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC1Ej
	.def	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC1Ej;	.scl	2;	.type	32;	.endef
__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC1Ej:
LFB2461:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE4seedEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2461:
	.section	.text$_ZNSt24uniform_int_distributionIiEC1Eii,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt24uniform_int_distributionIiEC1Eii
	.def	__ZNSt24uniform_int_distributionIiEC1Eii;	.scl	2;	.type	32;	.endef
__ZNSt24uniform_int_distributionIiEC1Eii:
LFB2464:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt24uniform_int_distributionIiE10param_typeC1Eii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2464:
	.section	.text$_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_
	.def	__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_;	.scl	2;	.type	32;	.endef
__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_:
LFB2465:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2465:
	.section	.text$_Z8extentofIN11dataOpt01_t6elem_tELj10000EEjRAT0__KT_,"x"
	.linkonce discard
	.globl	__Z8extentofIN11dataOpt01_t6elem_tELj10000EEjRAT0__KT_
	.def	__Z8extentofIN11dataOpt01_t6elem_tELj10000EEjRAT0__KT_;	.scl	2;	.type	32;	.endef
__Z8extentofIN11dataOpt01_t6elem_tELj10000EEjRAT0__KT_:
LFB2466:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$10000, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2466:
	.section	.text$_Z8extentofIN11dataOpt02_t6elem_tELj10000EEjRAT0__KT_,"x"
	.linkonce discard
	.globl	__Z8extentofIN11dataOpt02_t6elem_tELj10000EEjRAT0__KT_
	.def	__Z8extentofIN11dataOpt02_t6elem_tELj10000EEjRAT0__KT_;	.scl	2;	.type	32;	.endef
__Z8extentofIN11dataOpt02_t6elem_tELj10000EEjRAT0__KT_:
LFB2467:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$10000, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2467:
	.section	.text$_ZNSt14unary_functionIRivEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt14unary_functionIRivEC2Ev
	.def	__ZNSt14unary_functionIRivEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt14unary_functionIRivEC2Ev:
LFB2471:
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
LFE2471:
	.section	.text$_ZNSt31_Maybe_unary_or_binary_functionIvIRiEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt31_Maybe_unary_or_binary_functionIvIRiEEC2Ev
	.def	__ZNSt31_Maybe_unary_or_binary_functionIvIRiEEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt31_Maybe_unary_or_binary_functionIvIRiEEC2Ev:
LFB2473:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14unary_functionIRivEC2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2473:
	.weak	__ZNSt31_Maybe_unary_or_binary_functionIvJRiEEC2Ev
	.def	__ZNSt31_Maybe_unary_or_binary_functionIvJRiEEC2Ev;	.scl	2;	.type	32;	.endef
	.set	__ZNSt31_Maybe_unary_or_binary_functionIvJRiEEC2Ev,__ZNSt31_Maybe_unary_or_binary_functionIvIRiEEC2Ev
	.text
	.def	__ZSt4moveIRZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_EONSt16remove_referenceIT_E4typeEOS7_;	.scl	3;	.type	32;	.endef
__ZSt4moveIRZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_EONSt16remove_referenceIT_E4typeEOS7_:
LFB2475:
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
LFE2475:
	.align 2
	.def	__ZNSt8functionIFvRiEEC2IZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_vEET_;	.scl	3;	.type	32;	.endef
__ZNSt8functionIFvRiEEC2IZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_vEET_:
LFB2476:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2476
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
	call	__ZNSt31_Maybe_unary_or_binary_functionIvIRiEEC2Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_baseC2Ev
	leal	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E21_M_not_empty_functionIS5_EEbRKT_
	testb	%al, %al
	je	L163
	leal	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_EONSt16remove_referenceIT_E4typeEOS7_
	movl	8(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
LEHB22:
	call	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E15_M_init_functorERSt9_Any_dataOS5_
LEHE22:
	movl	8(%ebp), %eax
	movl	$__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_, 12(%eax)
	movl	8(%ebp), %eax
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, 8(%eax)
	jmp	L163
L162:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_baseD2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB23:
	call	__Unwind_Resume
LEHE23:
L163:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2476:
	.section	.gcc_except_table,"w"
LLSDA2476:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2476-LLSDACSB2476
LLSDACSB2476:
	.uleb128 LEHB22-LFB2476
	.uleb128 LEHE22-LEHB22
	.uleb128 L162-LFB2476
	.uleb128 0
	.uleb128 LEHB23-LFB2476
	.uleb128 LEHE23-LEHB23
	.uleb128 0
	.uleb128 0
LLSDACSE2476:
	.text
	.def	__ZNSt8functionIFvRiEEC1IZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_vEET_;	.scl	3;	.type	32;	.endef
	.set	__ZNSt8functionIFvRiEEC1IZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_vEET_,__ZNSt8functionIFvRiEEC2IZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_vEET_
	.section	.text$_Z33commonProc_testOpt03_Type3_BeforeIiLj10000EEvRAT0__T_S0_St8functionIFvRiEE,"x"
	.linkonce discard
	.globl	__Z33commonProc_testOpt03_Type3_BeforeIiLj10000EEvRAT0__T_S0_St8functionIFvRiEE
	.def	__Z33commonProc_testOpt03_Type3_BeforeIiLj10000EEvRAT0__T_S0_St8functionIFvRiEE;	.scl	2;	.type	32;	.endef
__Z33commonProc_testOpt03_Type3_BeforeIiLj10000EEvRAT0__T_S0_St8functionIFvRiEE:
LFB2481:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	addl	$40000, %eax
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -12(%ebp)
	jmp	L165
L167:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	12(%ebp), %eax
	jne	L166
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8functionIFvRiEEclES0_
L166:
	addl	$4, -12(%ebp)
L165:
	movl	-12(%ebp), %eax
	cmpl	-16(%ebp), %eax
	jb	L167
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2481:
	.text
	.def	__ZSt4moveIRZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_EONSt16remove_referenceIT_E4typeEOS7_;	.scl	3;	.type	32;	.endef
__ZSt4moveIRZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_EONSt16remove_referenceIT_E4typeEOS7_:
LFB2483:
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
LFE2483:
	.align 2
	.def	__ZNSt8functionIFvRiEEC2IZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_vEET_;	.scl	3;	.type	32;	.endef
__ZNSt8functionIFvRiEEC2IZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_vEET_:
LFB2484:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2484
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
	call	__ZNSt31_Maybe_unary_or_binary_functionIvIRiEEC2Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_baseC2Ev
	leal	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E21_M_not_empty_functionIS5_EEbRKT_
	testb	%al, %al
	je	L174
	leal	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_EONSt16remove_referenceIT_E4typeEOS7_
	movl	8(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
LEHB24:
	call	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E15_M_init_functorERSt9_Any_dataOS5_
LEHE24:
	movl	8(%ebp), %eax
	movl	$__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_, 12(%eax)
	movl	8(%ebp), %eax
	movl	$__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation, 8(%eax)
	jmp	L174
L173:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_baseD2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB25:
	call	__Unwind_Resume
LEHE25:
L174:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2484:
	.section	.gcc_except_table,"w"
LLSDA2484:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2484-LLSDACSB2484
LLSDACSB2484:
	.uleb128 LEHB24-LFB2484
	.uleb128 LEHE24-LEHB24
	.uleb128 L173-LFB2484
	.uleb128 0
	.uleb128 LEHB25-LFB2484
	.uleb128 LEHE25-LEHB25
	.uleb128 0
	.uleb128 0
LLSDACSE2484:
	.text
	.def	__ZNSt8functionIFvRiEEC1IZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_vEET_;	.scl	3;	.type	32;	.endef
	.set	__ZNSt8functionIFvRiEEC1IZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_vEET_,__ZNSt8functionIFvRiEEC2IZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_vEET_
	.def	__Z32commonProc_testOpt03_Type3_AfterIiLj10000EZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliiE_clEiiEUlRiE_EvRAT0__T_S5_T1_;	.scl	3;	.type	32;	.endef
__Z32commonProc_testOpt03_Type3_AfterIiLj10000EZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliiE_clEiiEUlRiE_EvRAT0__T_S5_T1_:
LFB2486:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$40000, %eax
	movl	%eax, -8(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	L176
L178:
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	cmpl	12(%ebp), %eax
	jne	L177
	movl	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliiE_clEiiENKUlRiE_clES2_
L177:
	addl	$4, -4(%ebp)
L176:
	movl	-4(%ebp), %eax
	cmpl	-8(%ebp), %eax
	jb	L178
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2486:
	.def	__Z32commonProc_testOpt03_Type3_AfterIiLj10000EZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliE0_clEiEUlRiE_EvRAT0__T_S5_T1_;	.scl	3;	.type	32;	.endef
__Z32commonProc_testOpt03_Type3_AfterIiLj10000EZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliE0_clEiEUlRiE_EvRAT0__T_S5_T1_:
LFB2487:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$40000, %eax
	movl	%eax, -8(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	L180
L182:
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	cmpl	12(%ebp), %eax
	jne	L181
	movl	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZZ21testOpt03_Type3_AfterR11dataOpt03_tENKUliE0_clEiENKUlRiE_clES2_
L181:
	addl	$4, -4(%ebp)
L180:
	movl	-4(%ebp), %eax
	cmpl	-8(%ebp), %eax
	jb	L182
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2487:
	.section	.text$_Z8extentofIN11dataOpt04_t6elem_tELj10000EEjRAT0__KT_,"x"
	.linkonce discard
	.globl	__Z8extentofIN11dataOpt04_t6elem_tELj10000EEjRAT0__KT_
	.def	__Z8extentofIN11dataOpt04_t6elem_tELj10000EEjRAT0__KT_;	.scl	2;	.type	32;	.endef
__Z8extentofIN11dataOpt04_t6elem_tELj10000EEjRAT0__KT_:
LFB2488:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$10000, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2488:
	.section	.text$_ZNSt31_Maybe_unary_or_binary_functionIiIEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt31_Maybe_unary_or_binary_functionIiIEEC2Ev
	.def	__ZNSt31_Maybe_unary_or_binary_functionIiIEEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt31_Maybe_unary_or_binary_functionIiIEEC2Ev:
LFB2491:
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
LFE2491:
	.weak	__ZNSt31_Maybe_unary_or_binary_functionIiJEEC2Ev
	.def	__ZNSt31_Maybe_unary_or_binary_functionIiJEEC2Ev;	.scl	2;	.type	32;	.endef
	.set	__ZNSt31_Maybe_unary_or_binary_functionIiJEEC2Ev,__ZNSt31_Maybe_unary_or_binary_functionIiIEEC2Ev
	.section	.text$_ZNSt8functionIFivEEC1EDn,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8functionIFivEEC1EDn
	.def	__ZNSt8functionIFivEEC1EDn;	.scl	2;	.type	32;	.endef
__ZNSt8functionIFivEEC1EDn:
LFB2494:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt31_Maybe_unary_or_binary_functionIiIEEC2Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_baseC2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2494:
	.section	.text$_ZNKSt8functionIFivEEclEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8functionIFivEEclEv
	.def	__ZNKSt8functionIFivEEclEv;	.scl	2;	.type	32;	.endef
__ZNKSt8functionIFivEEclEv:
LFB2498:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt14_Function_base8_M_emptyEv
	testb	%al, %al
	je	L188
	call	__ZSt25__throw_bad_function_callv
L188:
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2498:
	.section	.text$_ZNKSt8functionIFivEEcvbEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8functionIFivEEcvbEv
	.def	__ZNKSt8functionIFivEEcvbEv;	.scl	2;	.type	32;	.endef
__ZNKSt8functionIFivEEcvbEv:
LFB2499:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt14_Function_base8_M_emptyEv
	xorl	$1, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2499:
	.text
	.def	__ZSt7forwardIZ9setLambdaRiEUlvE_EOT_RNSt16remove_referenceIS2_E4typeE;	.scl	3;	.type	32;	.endef
__ZSt7forwardIZ9setLambdaRiEUlvE_EOT_RNSt16remove_referenceIS2_E4typeE:
LFB2501:
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
LFE2501:
	.align 2
	.def	__ZNSt8functionIFivEEaSIZ9setLambdaRiEUlvE_EENSt9enable_ifIXsrSt5__or_IISt7is_voidIiESt14is_convertibleIDTclcl18__callable_functorcl7declvalIRT_EEEEEiEEE5valueERS1_E4typeEOSA_;	.scl	3;	.type	32;	.endef
__ZNSt8functionIFivEEaSIZ9setLambdaRiEUlvE_EENSt9enable_ifIXsrSt5__or_IISt7is_voidIiESt14is_convertibleIDTclcl18__callable_functorcl7declvalIRT_EEEEEiEEE5valueERS1_E4typeEOSA_:
LFB2500:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIZ9setLambdaRiEUlvE_EOT_RNSt16remove_referenceIS2_E4typeE
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8functionIFivEEC1IZ9setLambdaRiEUlvE_vEET_
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8functionIFivEE4swapERS1_
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8functionIFivEED1Ev
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2500:
	.def	__ZSt7forwardIZ9setLambdaRiEUlvE0_EOT_RNSt16remove_referenceIS2_E4typeE;	.scl	3;	.type	32;	.endef
__ZSt7forwardIZ9setLambdaRiEUlvE0_EOT_RNSt16remove_referenceIS2_E4typeE:
LFB2503:
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
LFE2503:
	.align 2
	.def	__ZNSt8functionIFivEEaSIZ9setLambdaRiEUlvE0_EENSt9enable_ifIXsrSt5__or_IISt7is_voidIiESt14is_convertibleIDTclcl18__callable_functorcl7declvalIRT_EEEEEiEEE5valueERS1_E4typeEOSA_;	.scl	3;	.type	32;	.endef
__ZNSt8functionIFivEEaSIZ9setLambdaRiEUlvE0_EENSt9enable_ifIXsrSt5__or_IISt7is_voidIiESt14is_convertibleIDTclcl18__callable_functorcl7declvalIRT_EEEEEiEEE5valueERS1_E4typeEOSA_:
LFB2502:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIZ9setLambdaRiEUlvE0_EOT_RNSt16remove_referenceIS2_E4typeE
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8functionIFivEEC1IZ9setLambdaRiEUlvE0_vEET_
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8functionIFivEE4swapERS1_
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8functionIFivEED1Ev
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2502:
	.def	__ZSt7forwardIZ9setLambdaRiEUlvE1_EOT_RNSt16remove_referenceIS2_E4typeE;	.scl	3;	.type	32;	.endef
__ZSt7forwardIZ9setLambdaRiEUlvE1_EOT_RNSt16remove_referenceIS2_E4typeE:
LFB2505:
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
LFE2505:
	.align 2
	.def	__ZNSt8functionIFivEEaSIZ9setLambdaRiEUlvE1_EENSt9enable_ifIXsrSt5__or_IISt7is_voidIiESt14is_convertibleIDTclcl18__callable_functorcl7declvalIRT_EEEEEiEEE5valueERS1_E4typeEOSA_;	.scl	3;	.type	32;	.endef
__ZNSt8functionIFivEEaSIZ9setLambdaRiEUlvE1_EENSt9enable_ifIXsrSt5__or_IISt7is_voidIiESt14is_convertibleIDTclcl18__callable_functorcl7declvalIRT_EEEEEiEEE5valueERS1_E4typeEOSA_:
LFB2504:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIZ9setLambdaRiEUlvE1_EOT_RNSt16remove_referenceIS2_E4typeE
	movb	%bl, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8functionIFivEEC1IZ9setLambdaRiEUlvE1_vEET_
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8functionIFivEE4swapERS1_
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8functionIFivEED1Ev
	movl	8(%ebp), %eax
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2504:
	.section	.text$_ZNSt8functionIFivEEC1ERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8functionIFivEEC1ERKS1_
	.def	__ZNSt8functionIFivEEC1ERKS1_;	.scl	2;	.type	32;	.endef
__ZNSt8functionIFivEEC1ERKS1_:
LFB2508:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2508
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
	call	__ZNSt31_Maybe_unary_or_binary_functionIiIEEC2Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_baseC2Ev
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8functionIFivEEcvbEv
	testb	%al, %al
	je	L208
	movl	12(%ebp), %eax
	movl	12(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 12(%eax)
	movl	12(%ebp), %eax
	movl	8(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 8(%eax)
	movl	12(%ebp), %eax
	movl	8(%eax), %eax
	movl	12(%ebp), %ecx
	movl	8(%ebp), %edx
	movl	$2, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
LEHB26:
	call	*%eax
LEHE26:
	jmp	L208
L207:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_baseD2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB27:
	call	__Unwind_Resume
LEHE27:
L208:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2508:
	.section	.gcc_except_table,"w"
LLSDA2508:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2508-LLSDACSB2508
LLSDACSB2508:
	.uleb128 LEHB26-LFB2508
	.uleb128 LEHE26-LEHB26
	.uleb128 L207-LFB2508
	.uleb128 0
	.uleb128 LEHB27-LFB2508
	.uleb128 LEHE27-LEHB27
	.uleb128 0
	.uleb128 0
LLSDACSE2508:
	.section	.text$_ZNSt8functionIFivEEC1ERKS1_,"x"
	.linkonce discard
	.section	.text$_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE4seedEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE4seedEj
	.def	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE4seedEj;	.scl	2;	.type	32;	.endef
__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE4seedEj:
LFB2530:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_
	movl	8(%ebp), %edx
	movl	%eax, (%edx)
	movl	$1, -12(%ebp)
	jmp	L210
L211:
	movl	-12(%ebp), %eax
	leal	-1(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax,%edx,4), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	shrl	$30, %eax
	xorl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	imull	$1812433253, %eax, %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail5__modIjLj624ELj1ELj0EEET_S1_
	addl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_
	movl	8(%ebp), %edx
	movl	-12(%ebp), %ecx
	movl	%eax, (%edx,%ecx,4)
	addl	$1, -12(%ebp)
L210:
	cmpl	$623, -12(%ebp)
	jbe	L211
	movl	8(%ebp), %eax
	movl	$624, 2496(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2530:
	.section	.text$_ZNSt24uniform_int_distributionIiE10param_typeC1Eii,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt24uniform_int_distributionIiE10param_typeC1Eii
	.def	__ZNSt24uniform_int_distributionIiE10param_typeC1Eii;	.scl	2;	.type	32;	.endef
__ZNSt24uniform_int_distributionIiE10param_typeC1Eii:
LFB2533:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 4(%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2533:
	.section	.text$_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE
	.def	__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE;	.scl	2;	.type	32;	.endef
__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE:
LFB2534:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	$0, -16(%ebp)
	movl	$-1, -20(%ebp)
	movl	$-1, -24(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt24uniform_int_distributionIiE10param_type1bEv
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt24uniform_int_distributionIiE10param_type1aEv
	subl	%eax, %ebx
	movl	%ebx, %eax
	movl	%eax, -28(%ebp)
	cmpl	$-1, -28(%ebp)
	je	L214
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -32(%ebp)
	movl	$-1, %eax
	movl	$0, %edx
	divl	-32(%ebp)
	movl	%eax, -36(%ebp)
	movl	-32(%ebp), %eax
	imull	-36(%ebp), %eax
	movl	%eax, -40(%ebp)
L215:
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	cmpl	-40(%ebp), %eax
	jae	L215
	movl	-12(%ebp), %eax
	movl	$0, %edx
	divl	-36(%ebp)
	movl	%eax, -12(%ebp)
	jmp	L216
L214:
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	movl	%eax, -12(%ebp)
L216:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt24uniform_int_distributionIiE10param_type1aEv
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	addl	$68, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2534:
	.text
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E21_M_not_empty_functionIS5_EEbRKT_;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E21_M_not_empty_functionIS5_EEbRKT_:
LFB2537:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$1, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2537:
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E15_M_init_functorERSt9_Any_dataOS5_;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E15_M_init_functorERSt9_Any_dataOS5_:
LFB2538:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2538
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_EONSt16remove_referenceIT_E4typeEOS7_
	movb	%bl, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB28:
	call	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E15_M_init_functorERSt9_Any_dataOS5_St17integral_constantIbLb0EE
LEHE28:
	jmp	L223
L222:
	movl	%eax, (%esp)
LEHB29:
	call	__Unwind_Resume
LEHE29:
L223:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2538:
	.section	.gcc_except_table,"w"
LLSDA2538:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2538-LLSDACSB2538
LLSDACSB2538:
	.uleb128 LEHB28-LFB2538
	.uleb128 LEHE28-LEHB28
	.uleb128 L222-LFB2538
	.uleb128 0
	.uleb128 LEHB29-LFB2538
	.uleb128 LEHE29-LEHB29
	.uleb128 0
	.uleb128 0
LLSDACSE2538:
	.text
	.section	.text$_ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE
	.def	__ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE:
LFB2540:
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
LFE2540:
	.text
	.def	__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_:
LFB2539:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E14_M_get_pointerERKSt9_Any_data
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiENKUlRiE_clES2_
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2539:
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation:
LFB2541:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2541
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	cmpl	$1, %eax
	je	L229
	cmpl	$1, %eax
	jg	L230
	testl	%eax, %eax
	je	L231
	jmp	L228
L230:
	cmpl	$2, %eax
	je	L232
	cmpl	$3, %eax
	je	L233
	jmp	L228
L231:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v
	movl	$__ZTIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_, (%eax)
	jmp	L228
L229:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_EERT_v
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
LEHB30:
	call	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E14_M_get_pointerERKSt9_Any_data
LEHE30:
	movl	%eax, (%ebx)
	jmp	L228
L232:
	movb	%cl, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB31:
	call	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E8_M_cloneERSt9_Any_dataRKS7_St17integral_constantIbLb0EE
LEHE31:
	jmp	L228
L233:
	movb	%dl, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE
	nop
L228:
	movl	$0, %eax
	jmp	L237
L236:
	movl	%eax, (%esp)
LEHB32:
	call	__Unwind_Resume
LEHE32:
L237:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2541:
	.section	.gcc_except_table,"w"
LLSDA2541:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2541-LLSDACSB2541
LLSDACSB2541:
	.uleb128 LEHB30-LFB2541
	.uleb128 LEHE30-LEHB30
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB31-LFB2541
	.uleb128 LEHE31-LEHB31
	.uleb128 L236-LFB2541
	.uleb128 0
	.uleb128 LEHB32-LFB2541
	.uleb128 LEHE32-LEHB32
	.uleb128 0
	.uleb128 0
LLSDACSE2541:
	.text
	.section	.text$_ZNKSt8functionIFvRiEEclES0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8functionIFvRiEEclES0_
	.def	__ZNKSt8functionIFvRiEEclES0_;	.scl	2;	.type	32;	.endef
__ZNKSt8functionIFvRiEEclES0_:
LFB2543:
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
	call	__ZNKSt14_Function_base8_M_emptyEv
	testb	%al, %al
	je	L239
	call	__ZSt25__throw_bad_function_callv
L239:
	movl	8(%ebp), %eax
	movl	12(%eax), %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE
	movl	8(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	*%ebx
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2543:
	.text
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E21_M_not_empty_functionIS5_EEbRKT_;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E21_M_not_empty_functionIS5_EEbRKT_:
LFB2544:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$1, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2544:
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E15_M_init_functorERSt9_Any_dataOS5_;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E15_M_init_functorERSt9_Any_dataOS5_:
LFB2545:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2545
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_EONSt16remove_referenceIT_E4typeEOS7_
	movb	%bl, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB33:
	call	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E15_M_init_functorERSt9_Any_dataOS5_St17integral_constantIbLb0EE
LEHE33:
	jmp	L246
L245:
	movl	%eax, (%esp)
LEHB34:
	call	__Unwind_Resume
LEHE34:
L246:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2545:
	.section	.gcc_except_table,"w"
LLSDA2545:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2545-LLSDACSB2545
LLSDACSB2545:
	.uleb128 LEHB33-LFB2545
	.uleb128 LEHE33-LEHB33
	.uleb128 L245-LFB2545
	.uleb128 0
	.uleb128 LEHB34-LFB2545
	.uleb128 LEHE34-LEHB34
	.uleb128 0
	.uleb128 0
LLSDACSE2545:
	.text
	.def	__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFvRiEZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlS0_E_E9_M_invokeERKSt9_Any_dataS0_:
LFB2546:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E14_M_get_pointerERKSt9_Any_data
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiENKUlRiE_clES2_
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2546:
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_managerERSt9_Any_dataRKS7_St18_Manager_operation:
LFB2547:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2547
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	cmpl	$1, %eax
	je	L250
	cmpl	$1, %eax
	jg	L251
	testl	%eax, %eax
	je	L252
	jmp	L249
L251:
	cmpl	$2, %eax
	je	L253
	cmpl	$3, %eax
	je	L254
	jmp	L249
L252:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v
	movl	$__ZTIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_, (%eax)
	jmp	L249
L250:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_EERT_v
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
LEHB35:
	call	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E14_M_get_pointerERKSt9_Any_data
LEHE35:
	movl	%eax, (%ebx)
	jmp	L249
L253:
	movb	%cl, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB36:
	call	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E8_M_cloneERSt9_Any_dataRKS7_St17integral_constantIbLb0EE
LEHE36:
	jmp	L249
L254:
	movb	%dl, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE
	nop
L249:
	movl	$0, %eax
	jmp	L258
L257:
	movl	%eax, (%esp)
LEHB37:
	call	__Unwind_Resume
LEHE37:
L258:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2547:
	.section	.gcc_except_table,"w"
LLSDA2547:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2547-LLSDACSB2547
LLSDACSB2547:
	.uleb128 LEHB35-LFB2547
	.uleb128 LEHE35-LEHB35
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB36-LFB2547
	.uleb128 LEHE36-LEHB36
	.uleb128 L257-LFB2547
	.uleb128 0
	.uleb128 LEHB37-LFB2547
	.uleb128 LEHE37-LEHB37
	.uleb128 0
	.uleb128 0
LLSDACSE2547:
	.text
	.section	.text$_ZNSt8functionIFivEE4swapERS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8functionIFivEE4swapERS1_
	.def	__ZNSt8functionIFivEE4swapERS1_;	.scl	2;	.type	32;	.endef
__ZNSt8functionIFivEE4swapERS1_:
LFB2548:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt4swapISt9_Any_dataEvRT_S2_
	movl	12(%ebp), %eax
	leal	8(%eax), %edx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt4swapIPFbRSt9_Any_dataRKS0_St18_Manager_operationEEvRT_S8_
	movl	12(%ebp), %eax
	leal	12(%eax), %edx
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt4swapIPFiRKSt9_Any_dataEEvRT_S6_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2548:
	.text
	.def	__ZSt4moveIRZ9setLambdaRiEUlvE_EONSt16remove_referenceIT_E4typeEOS4_;	.scl	3;	.type	32;	.endef
__ZSt4moveIRZ9setLambdaRiEUlvE_EONSt16remove_referenceIT_E4typeEOS4_:
LFB2550:
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
LFE2550:
	.align 2
	.def	__ZNSt8functionIFivEEC2IZ9setLambdaRiEUlvE_vEET_;	.scl	3;	.type	32;	.endef
__ZNSt8functionIFivEEC2IZ9setLambdaRiEUlvE_vEET_:
LFB2551:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2551
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
	call	__ZNSt31_Maybe_unary_or_binary_functionIiIEEC2Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_baseC2Ev
	leal	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E21_M_not_empty_functionIS2_EEbRKT_
	testb	%al, %al
	je	L266
	leal	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRZ9setLambdaRiEUlvE_EONSt16remove_referenceIT_E4typeEOS4_
	movl	8(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
LEHB38:
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E15_M_init_functorERSt9_Any_dataOS2_
LEHE38:
	movl	8(%ebp), %eax
	movl	$__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE_E9_M_invokeERKSt9_Any_data, 12(%eax)
	movl	8(%ebp), %eax
	movl	$__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 8(%eax)
	jmp	L266
L265:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_baseD2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB39:
	call	__Unwind_Resume
LEHE39:
L266:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2551:
	.section	.gcc_except_table,"w"
LLSDA2551:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2551-LLSDACSB2551
LLSDACSB2551:
	.uleb128 LEHB38-LFB2551
	.uleb128 LEHE38-LEHB38
	.uleb128 L265-LFB2551
	.uleb128 0
	.uleb128 LEHB39-LFB2551
	.uleb128 LEHE39-LEHB39
	.uleb128 0
	.uleb128 0
LLSDACSE2551:
	.text
	.def	__ZNSt8functionIFivEEC1IZ9setLambdaRiEUlvE_vEET_;	.scl	3;	.type	32;	.endef
	.set	__ZNSt8functionIFivEEC1IZ9setLambdaRiEUlvE_vEET_,__ZNSt8functionIFivEEC2IZ9setLambdaRiEUlvE_vEET_
	.def	__ZSt4moveIRZ9setLambdaRiEUlvE0_EONSt16remove_referenceIT_E4typeEOS4_;	.scl	3;	.type	32;	.endef
__ZSt4moveIRZ9setLambdaRiEUlvE0_EONSt16remove_referenceIT_E4typeEOS4_:
LFB2554:
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
LFE2554:
	.align 2
	.def	__ZNSt8functionIFivEEC2IZ9setLambdaRiEUlvE0_vEET_;	.scl	3;	.type	32;	.endef
__ZNSt8functionIFivEEC2IZ9setLambdaRiEUlvE0_vEET_:
LFB2555:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2555
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
	call	__ZNSt31_Maybe_unary_or_binary_functionIiIEEC2Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_baseC2Ev
	leal	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E21_M_not_empty_functionIS2_EEbRKT_
	testb	%al, %al
	je	L273
	leal	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRZ9setLambdaRiEUlvE0_EONSt16remove_referenceIT_E4typeEOS4_
	movl	8(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
LEHB40:
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E15_M_init_functorERSt9_Any_dataOS2_
LEHE40:
	movl	8(%ebp), %eax
	movl	$__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE0_E9_M_invokeERKSt9_Any_data, 12(%eax)
	movl	8(%ebp), %eax
	movl	$__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 8(%eax)
	jmp	L273
L272:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_baseD2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB41:
	call	__Unwind_Resume
LEHE41:
L273:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2555:
	.section	.gcc_except_table,"w"
LLSDA2555:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2555-LLSDACSB2555
LLSDACSB2555:
	.uleb128 LEHB40-LFB2555
	.uleb128 LEHE40-LEHB40
	.uleb128 L272-LFB2555
	.uleb128 0
	.uleb128 LEHB41-LFB2555
	.uleb128 LEHE41-LEHB41
	.uleb128 0
	.uleb128 0
LLSDACSE2555:
	.text
	.def	__ZNSt8functionIFivEEC1IZ9setLambdaRiEUlvE0_vEET_;	.scl	3;	.type	32;	.endef
	.set	__ZNSt8functionIFivEEC1IZ9setLambdaRiEUlvE0_vEET_,__ZNSt8functionIFivEEC2IZ9setLambdaRiEUlvE0_vEET_
	.def	__ZSt4moveIRZ9setLambdaRiEUlvE1_EONSt16remove_referenceIT_E4typeEOS4_;	.scl	3;	.type	32;	.endef
__ZSt4moveIRZ9setLambdaRiEUlvE1_EONSt16remove_referenceIT_E4typeEOS4_:
LFB2558:
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
LFE2558:
	.align 2
	.def	__ZNSt8functionIFivEEC2IZ9setLambdaRiEUlvE1_vEET_;	.scl	3;	.type	32;	.endef
__ZNSt8functionIFivEEC2IZ9setLambdaRiEUlvE1_vEET_:
LFB2559:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2559
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
	call	__ZNSt31_Maybe_unary_or_binary_functionIiIEEC2Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_baseC2Ev
	leal	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E21_M_not_empty_functionIS2_EEbRKT_
	testb	%al, %al
	je	L280
	leal	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRZ9setLambdaRiEUlvE1_EONSt16remove_referenceIT_E4typeEOS4_
	movl	8(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
LEHB42:
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E15_M_init_functorERSt9_Any_dataOS2_
LEHE42:
	movl	8(%ebp), %eax
	movl	$__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE1_E9_M_invokeERKSt9_Any_data, 12(%eax)
	movl	8(%ebp), %eax
	movl	$__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 8(%eax)
	jmp	L280
L279:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_baseD2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB43:
	call	__Unwind_Resume
LEHE43:
L280:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2559:
	.section	.gcc_except_table,"w"
LLSDA2559:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2559-LLSDACSB2559
LLSDACSB2559:
	.uleb128 LEHB42-LFB2559
	.uleb128 LEHE42-LEHB42
	.uleb128 L279-LFB2559
	.uleb128 0
	.uleb128 LEHB43-LFB2559
	.uleb128 LEHE43-LEHB43
	.uleb128 0
	.uleb128 0
LLSDACSE2559:
	.text
	.def	__ZNSt8functionIFivEEC1IZ9setLambdaRiEUlvE1_vEET_;	.scl	3;	.type	32;	.endef
	.set	__ZNSt8functionIFivEEC1IZ9setLambdaRiEUlvE1_vEET_,__ZNSt8functionIFivEEC2IZ9setLambdaRiEUlvE1_vEET_
	.section	.text$_ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_,"x"
	.linkonce discard
	.globl	__ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_
	.def	__ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_:
LFB2570:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail4_ModIjLj0ELj1ELj0ELb1ELb0EE6__calcEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2570:
	.section	.text$_ZNSt8__detail5__modIjLj624ELj1ELj0EEET_S1_,"x"
	.linkonce discard
	.globl	__ZNSt8__detail5__modIjLj624ELj1ELj0EEET_S1_
	.def	__ZNSt8__detail5__modIjLj624ELj1ELj0EEET_S1_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail5__modIjLj624ELj1ELj0EEET_S1_:
LFB2571:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2571:
	.section	.text$_ZNKSt24uniform_int_distributionIiE10param_type1aEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt24uniform_int_distributionIiE10param_type1aEv
	.def	__ZNKSt24uniform_int_distributionIiE10param_type1aEv;	.scl	2;	.type	32;	.endef
__ZNKSt24uniform_int_distributionIiE10param_type1aEv:
LFB2572:
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
LFE2572:
	.section	.text$_ZNKSt24uniform_int_distributionIiE10param_type1bEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt24uniform_int_distributionIiE10param_type1bEv
	.def	__ZNKSt24uniform_int_distributionIiE10param_type1bEv;	.scl	2;	.type	32;	.endef
__ZNKSt24uniform_int_distributionIiE10param_type1bEv:
LFB2573:
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
LFE2573:
	.section	.text$_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	.def	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv;	.scl	2;	.type	32;	.endef
__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv:
LFB2574:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	2496(%eax), %eax
	cmpl	$623, %eax
	jbe	L290
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv
L290:
	movl	8(%ebp), %eax
	movl	2496(%eax), %eax
	leal	1(%eax), %ecx
	movl	8(%ebp), %edx
	movl	%ecx, 2496(%edx)
	movl	8(%ebp), %edx
	movl	(%edx,%eax,4), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	shrl	$11, %eax
	xorl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	sall	$7, %eax
	andl	$-1658038656, %eax
	xorl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	sall	$15, %eax
	andl	$-272236544, %eax
	xorl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	shrl	$18, %eax
	xorl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2574:
	.text
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E15_M_init_functorERSt9_Any_dataOS5_St17integral_constantIbLb0EE;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E15_M_init_functorERSt9_Any_dataOS5_St17integral_constantIbLb0EE:
LFB2575:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_EONSt16remove_referenceIT_E4typeEOS7_
	movl	%eax, %esi
	movl	$4, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	(%esi), %eax
	movl	%eax, (%ebx)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_EERT_v
	movl	%ebx, (%eax)
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2575:
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E14_M_get_pointerERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E14_M_get_pointerERKSt9_Any_data:
LFB2576:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_EERKT_v
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2576:
	.section	.text$_ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v
	.def	__ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v;	.scl	2;	.type	32;	.endef
__ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v:
LFB2577:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2577:
	.text
	.align 2
	.def	__ZNSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_EERT_v;	.scl	3;	.type	32;	.endef
__ZNSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_EERT_v:
LFB2578:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2578:
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E8_M_cloneERSt9_Any_dataRKS7_St17integral_constantIbLb0EE;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E8_M_cloneERSt9_Any_dataRKS7_St17integral_constantIbLb0EE:
LFB2579:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_EERKT_v
	movl	(%eax), %esi
	movl	$4, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	(%esi), %eax
	movl	%eax, (%ebx)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_EERT_v
	movl	%ebx, (%eax)
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2579:
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_E10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE:
LFB2580:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_EERT_v
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2580:
	.section	.text$_ZSt4moveIRSt9_Any_dataEONSt16remove_referenceIT_E4typeEOS3_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRSt9_Any_dataEONSt16remove_referenceIT_E4typeEOS3_
	.def	__ZSt4moveIRSt9_Any_dataEONSt16remove_referenceIT_E4typeEOS3_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRSt9_Any_dataEONSt16remove_referenceIT_E4typeEOS3_:
LFB2582:
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
LFE2582:
	.section	.text$_ZSt4swapISt9_Any_dataEvRT_S2_,"x"
	.linkonce discard
	.globl	__ZSt4swapISt9_Any_dataEvRT_S2_
	.def	__ZSt4swapISt9_Any_dataEvRT_S2_;	.scl	2;	.type	32;	.endef
__ZSt4swapISt9_Any_dataEvRT_S2_:
LFB2581:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRSt9_Any_dataEONSt16remove_referenceIT_E4typeEOS3_
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, -8(%ebp)
	movl	%edx, -4(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRSt9_Any_dataEONSt16remove_referenceIT_E4typeEOS3_
	movl	8(%ebp), %ecx
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	leal	-8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRSt9_Any_dataEONSt16remove_referenceIT_E4typeEOS3_
	movl	12(%ebp), %ecx
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2581:
	.section	.text$_ZSt4moveIRPFbRSt9_Any_dataRKS0_St18_Manager_operationEEONSt16remove_referenceIT_E4typeEOS9_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRPFbRSt9_Any_dataRKS0_St18_Manager_operationEEONSt16remove_referenceIT_E4typeEOS9_
	.def	__ZSt4moveIRPFbRSt9_Any_dataRKS0_St18_Manager_operationEEONSt16remove_referenceIT_E4typeEOS9_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRPFbRSt9_Any_dataRKS0_St18_Manager_operationEEONSt16remove_referenceIT_E4typeEOS9_:
LFB2584:
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
LFE2584:
	.section	.text$_ZSt4swapIPFbRSt9_Any_dataRKS0_St18_Manager_operationEEvRT_S8_,"x"
	.linkonce discard
	.globl	__ZSt4swapIPFbRSt9_Any_dataRKS0_St18_Manager_operationEEvRT_S8_
	.def	__ZSt4swapIPFbRSt9_Any_dataRKS0_St18_Manager_operationEEvRT_S8_;	.scl	2;	.type	32;	.endef
__ZSt4swapIPFbRSt9_Any_dataRKS0_St18_Manager_operationEEvRT_S8_:
LFB2583:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRPFbRSt9_Any_dataRKS0_St18_Manager_operationEEONSt16remove_referenceIT_E4typeEOS9_
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRPFbRSt9_Any_dataRKS0_St18_Manager_operationEEONSt16remove_referenceIT_E4typeEOS9_
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	leal	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRPFbRSt9_Any_dataRKS0_St18_Manager_operationEEONSt16remove_referenceIT_E4typeEOS9_
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2583:
	.text
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E15_M_init_functorERSt9_Any_dataOS5_St17integral_constantIbLb0EE;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E15_M_init_functorERSt9_Any_dataOS5_St17integral_constantIbLb0EE:
LFB2587:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_EONSt16remove_referenceIT_E4typeEOS7_
	movl	%eax, %esi
	movl	$4, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	(%esi), %eax
	movl	%eax, (%ebx)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_EERT_v
	movl	%ebx, (%eax)
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2587:
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E14_M_get_pointerERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E14_M_get_pointerERKSt9_Any_data:
LFB2588:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_EERKT_v
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2588:
	.align 2
	.def	__ZNSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_EERT_v;	.scl	3;	.type	32;	.endef
__ZNSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_EERT_v:
LFB2589:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2589:
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E8_M_cloneERSt9_Any_dataRKS7_St17integral_constantIbLb0EE;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E8_M_cloneERSt9_Any_dataRKS7_St17integral_constantIbLb0EE:
LFB2590:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_EERKT_v
	movl	(%eax), %esi
	movl	$4, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	(%esi), %eax
	movl	%eax, (%ebx)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_EERT_v
	movl	%ebx, (%eax)
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2590:
	.def	__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_E10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE:
LFB2591:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_EERT_v
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2591:
	.section	.text$_ZSt4moveIRPFiRKSt9_Any_dataEEONSt16remove_referenceIT_E4typeEOS7_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRPFiRKSt9_Any_dataEEONSt16remove_referenceIT_E4typeEOS7_
	.def	__ZSt4moveIRPFiRKSt9_Any_dataEEONSt16remove_referenceIT_E4typeEOS7_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRPFiRKSt9_Any_dataEEONSt16remove_referenceIT_E4typeEOS7_:
LFB2593:
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
LFE2593:
	.section	.text$_ZSt4swapIPFiRKSt9_Any_dataEEvRT_S6_,"x"
	.linkonce discard
	.globl	__ZSt4swapIPFiRKSt9_Any_dataEEvRT_S6_
	.def	__ZSt4swapIPFiRKSt9_Any_dataEEvRT_S6_;	.scl	2;	.type	32;	.endef
__ZSt4swapIPFiRKSt9_Any_dataEEvRT_S6_:
LFB2592:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRPFiRKSt9_Any_dataEEONSt16remove_referenceIT_E4typeEOS7_
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRPFiRKSt9_Any_dataEEONSt16remove_referenceIT_E4typeEOS7_
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	leal	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRPFiRKSt9_Any_dataEEONSt16remove_referenceIT_E4typeEOS7_
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2592:
	.text
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E21_M_not_empty_functionIS2_EEbRKT_;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E21_M_not_empty_functionIS2_EEbRKT_:
LFB2594:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$1, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2594:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E15_M_init_functorERSt9_Any_dataOS2_;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E15_M_init_functorERSt9_Any_dataOS2_:
LFB2595:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2595
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRZ9setLambdaRiEUlvE_EONSt16remove_referenceIT_E4typeEOS4_
	movb	%bl, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB44:
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E15_M_init_functorERSt9_Any_dataOS2_St17integral_constantIbLb0EE
LEHE44:
	jmp	L322
L321:
	movl	%eax, (%esp)
LEHB45:
	call	__Unwind_Resume
LEHE45:
L322:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2595:
	.section	.gcc_except_table,"w"
LLSDA2595:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2595-LLSDACSB2595
LLSDACSB2595:
	.uleb128 LEHB44-LFB2595
	.uleb128 LEHE44-LEHB44
	.uleb128 L321-LFB2595
	.uleb128 0
	.uleb128 LEHB45-LFB2595
	.uleb128 LEHE45-LEHB45
	.uleb128 0
	.uleb128 0
LLSDACSE2595:
	.text
	.def	__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE_E9_M_invokeERKSt9_Any_data:
LFB2596:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E14_M_get_pointerERKSt9_Any_data
	movl	%eax, (%esp)
	call	__ZZ9setLambdaRiENKUlvE_clEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2596:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation:
LFB2597:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2597
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	cmpl	$1, %eax
	je	L327
	cmpl	$1, %eax
	jg	L328
	testl	%eax, %eax
	je	L329
	jmp	L326
L328:
	cmpl	$2, %eax
	je	L330
	cmpl	$3, %eax
	je	L331
	jmp	L326
L329:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v
	movl	$__ZTIZ9setLambdaRiEUlvE_, (%eax)
	jmp	L326
L327:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE_EERT_v
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
LEHB46:
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E14_M_get_pointerERKSt9_Any_data
LEHE46:
	movl	%eax, (%ebx)
	jmp	L326
L330:
	movb	%cl, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB47:
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E8_M_cloneERSt9_Any_dataRKS4_St17integral_constantIbLb0EE
LEHE47:
	jmp	L326
L331:
	movb	%dl, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE
	nop
L326:
	movl	$0, %eax
	jmp	L335
L334:
	movl	%eax, (%esp)
LEHB48:
	call	__Unwind_Resume
LEHE48:
L335:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2597:
	.section	.gcc_except_table,"w"
LLSDA2597:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2597-LLSDACSB2597
LLSDACSB2597:
	.uleb128 LEHB46-LFB2597
	.uleb128 LEHE46-LEHB46
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB47-LFB2597
	.uleb128 LEHE47-LEHB47
	.uleb128 L334-LFB2597
	.uleb128 0
	.uleb128 LEHB48-LFB2597
	.uleb128 LEHE48-LEHB48
	.uleb128 0
	.uleb128 0
LLSDACSE2597:
	.text
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E21_M_not_empty_functionIS2_EEbRKT_;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E21_M_not_empty_functionIS2_EEbRKT_:
LFB2598:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$1, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2598:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E15_M_init_functorERSt9_Any_dataOS2_;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E15_M_init_functorERSt9_Any_dataOS2_:
LFB2599:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2599
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRZ9setLambdaRiEUlvE0_EONSt16remove_referenceIT_E4typeEOS4_
	movb	%bl, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB49:
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E15_M_init_functorERSt9_Any_dataOS2_St17integral_constantIbLb0EE
LEHE49:
	jmp	L341
L340:
	movl	%eax, (%esp)
LEHB50:
	call	__Unwind_Resume
LEHE50:
L341:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2599:
	.section	.gcc_except_table,"w"
LLSDA2599:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2599-LLSDACSB2599
LLSDACSB2599:
	.uleb128 LEHB49-LFB2599
	.uleb128 LEHE49-LEHB49
	.uleb128 L340-LFB2599
	.uleb128 0
	.uleb128 LEHB50-LFB2599
	.uleb128 LEHE50-LEHB50
	.uleb128 0
	.uleb128 0
LLSDACSE2599:
	.text
	.def	__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE0_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE0_E9_M_invokeERKSt9_Any_data:
LFB2600:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E14_M_get_pointerERKSt9_Any_data
	movl	%eax, (%esp)
	call	__ZZ9setLambdaRiENKUlvE0_clEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2600:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation:
LFB2601:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2601
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	cmpl	$1, %eax
	je	L346
	cmpl	$1, %eax
	jg	L347
	testl	%eax, %eax
	je	L348
	jmp	L345
L347:
	cmpl	$2, %eax
	je	L349
	cmpl	$3, %eax
	je	L350
	jmp	L345
L348:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v
	movl	$__ZTIZ9setLambdaRiEUlvE0_, (%eax)
	jmp	L345
L346:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE0_EERT_v
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
LEHB51:
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E14_M_get_pointerERKSt9_Any_data
LEHE51:
	movl	%eax, (%ebx)
	jmp	L345
L349:
	movb	%cl, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB52:
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E8_M_cloneERSt9_Any_dataRKS4_St17integral_constantIbLb0EE
LEHE52:
	jmp	L345
L350:
	movb	%dl, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE
	nop
L345:
	movl	$0, %eax
	jmp	L354
L353:
	movl	%eax, (%esp)
LEHB53:
	call	__Unwind_Resume
LEHE53:
L354:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2601:
	.section	.gcc_except_table,"w"
LLSDA2601:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2601-LLSDACSB2601
LLSDACSB2601:
	.uleb128 LEHB51-LFB2601
	.uleb128 LEHE51-LEHB51
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB52-LFB2601
	.uleb128 LEHE52-LEHB52
	.uleb128 L353-LFB2601
	.uleb128 0
	.uleb128 LEHB53-LFB2601
	.uleb128 LEHE53-LEHB53
	.uleb128 0
	.uleb128 0
LLSDACSE2601:
	.text
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E21_M_not_empty_functionIS2_EEbRKT_;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E21_M_not_empty_functionIS2_EEbRKT_:
LFB2602:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$1, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2602:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E15_M_init_functorERSt9_Any_dataOS2_;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E15_M_init_functorERSt9_Any_dataOS2_:
LFB2603:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2603
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRZ9setLambdaRiEUlvE1_EONSt16remove_referenceIT_E4typeEOS4_
	movb	%bl, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB54:
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E15_M_init_functorERSt9_Any_dataOS2_St17integral_constantIbLb0EE
LEHE54:
	jmp	L360
L359:
	movl	%eax, (%esp)
LEHB55:
	call	__Unwind_Resume
LEHE55:
L360:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2603:
	.section	.gcc_except_table,"w"
LLSDA2603:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2603-LLSDACSB2603
LLSDACSB2603:
	.uleb128 LEHB54-LFB2603
	.uleb128 LEHE54-LEHB54
	.uleb128 L359-LFB2603
	.uleb128 0
	.uleb128 LEHB55-LFB2603
	.uleb128 LEHE55-LEHB55
	.uleb128 0
	.uleb128 0
LLSDACSE2603:
	.text
	.def	__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE1_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFivEZ9setLambdaRiEUlvE1_E9_M_invokeERKSt9_Any_data:
LFB2604:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E14_M_get_pointerERKSt9_Any_data
	movl	%eax, (%esp)
	call	__ZZ9setLambdaRiENKUlvE1_clEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2604:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation:
LFB2605:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2605
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	cmpl	$1, %eax
	je	L365
	cmpl	$1, %eax
	jg	L366
	testl	%eax, %eax
	je	L367
	jmp	L364
L366:
	cmpl	$2, %eax
	je	L368
	cmpl	$3, %eax
	je	L369
	jmp	L364
L367:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPKSt9type_infoEERT_v
	movl	$__ZTIZ9setLambdaRiEUlvE1_, (%eax)
	jmp	L364
L365:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE1_EERT_v
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
LEHB56:
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E14_M_get_pointerERKSt9_Any_data
LEHE56:
	movl	%eax, (%ebx)
	jmp	L364
L368:
	movb	%cl, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB57:
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E8_M_cloneERSt9_Any_dataRKS4_St17integral_constantIbLb0EE
LEHE57:
	jmp	L364
L369:
	movb	%dl, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE
	nop
L364:
	movl	$0, %eax
	jmp	L373
L372:
	movl	%eax, (%esp)
LEHB58:
	call	__Unwind_Resume
LEHE58:
L373:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2605:
	.section	.gcc_except_table,"w"
LLSDA2605:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2605-LLSDACSB2605
LLSDACSB2605:
	.uleb128 LEHB56-LFB2605
	.uleb128 LEHE56-LEHB56
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB57-LFB2605
	.uleb128 LEHE57-LEHB57
	.uleb128 L372-LFB2605
	.uleb128 0
	.uleb128 LEHB58-LFB2605
	.uleb128 LEHE58-LEHB58
	.uleb128 0
	.uleb128 0
LLSDACSE2605:
	.text
	.section	.text$_ZNSt8__detail4_ModIjLj0ELj1ELj0ELb1ELb0EE6__calcEj,"x"
	.linkonce discard
	.globl	__ZNSt8__detail4_ModIjLj0ELj1ELj0ELb1ELb0EE6__calcEj
	.def	__ZNSt8__detail4_ModIjLj0ELj1ELj0ELb1ELb0EE6__calcEj;	.scl	2;	.type	32;	.endef
__ZNSt8__detail4_ModIjLj0ELj1ELj0ELb1ELb0EE6__calcEj:
LFB2614:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2614:
	.section	.text$_ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj,"x"
	.linkonce discard
	.globl	__ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj
	.def	__ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj;	.scl	2;	.type	32;	.endef
__ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj:
LFB2615:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %ecx
	movl	%ecx, %eax
	shrl	$4, %eax
	movl	$440509467, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$2, %eax
	imull	$624, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2615:
	.section	.text$_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv
	.def	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv;	.scl	2;	.type	32;	.endef
__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv:
LFB2616:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$32, %esp
	movl	$-2147483648, -12(%ebp)
	movl	$2147483647, -16(%ebp)
	movl	$0, -4(%ebp)
	jmp	L379
L382:
	movl	8(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	andl	$-2147483648, %eax
	movl	%eax, %ecx
	movl	-4(%ebp), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax,%edx,4), %eax
	andl	$2147483647, %eax
	orl	%ecx, %eax
	movl	%eax, -20(%ebp)
	movl	-4(%ebp), %eax
	leal	397(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax,%edx,4), %eax
	movl	-20(%ebp), %edx
	shrl	%edx
	xorl	%eax, %edx
	movl	-20(%ebp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	L380
	movl	$-1727483681, %eax
	jmp	L381
L380:
	movl	$0, %eax
L381:
	movl	%edx, %ecx
	xorl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%ecx, (%eax,%edx,4)
	addl	$1, -4(%ebp)
L379:
	cmpl	$226, -4(%ebp)
	jbe	L382
	movl	$227, -8(%ebp)
	jmp	L383
L386:
	movl	8(%ebp), %eax
	movl	-8(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	andl	$-2147483648, %eax
	movl	%eax, %ecx
	movl	-8(%ebp), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax,%edx,4), %eax
	andl	$2147483647, %eax
	orl	%ecx, %eax
	movl	%eax, -24(%ebp)
	movl	-8(%ebp), %eax
	leal	-227(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax,%edx,4), %eax
	movl	-24(%ebp), %edx
	shrl	%edx
	xorl	%eax, %edx
	movl	-24(%ebp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	L384
	movl	$-1727483681, %eax
	jmp	L385
L384:
	movl	$0, %eax
L385:
	movl	%edx, %ecx
	xorl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	-8(%ebp), %edx
	movl	%ecx, (%eax,%edx,4)
	addl	$1, -8(%ebp)
L383:
	cmpl	$622, -8(%ebp)
	jbe	L386
	movl	8(%ebp), %eax
	movl	2492(%eax), %eax
	andl	$-2147483648, %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	andl	$2147483647, %eax
	orl	%edx, %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	movl	1584(%eax), %eax
	movl	-28(%ebp), %edx
	shrl	%edx
	xorl	%eax, %edx
	movl	-28(%ebp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	L387
	movl	$-1727483681, %eax
	jmp	L388
L387:
	movl	$0, %eax
L388:
	xorl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, 2492(%eax)
	movl	8(%ebp), %eax
	movl	$0, 2496(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2616:
	.text
	.align 2
	.def	__ZNKSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_EERKT_v;	.scl	3;	.type	32;	.endef
__ZNKSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_EERKT_v:
LFB2619:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9_Any_data9_M_accessEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2619:
	.align 2
	.def	__ZNKSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_EERKT_v;	.scl	3;	.type	32;	.endef
__ZNKSt9_Any_data9_M_accessIPZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_EERKT_v:
LFB2622:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9_Any_data9_M_accessEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2622:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E15_M_init_functorERSt9_Any_dataOS2_St17integral_constantIbLb0EE;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E15_M_init_functorERSt9_Any_dataOS2_St17integral_constantIbLb0EE:
LFB2623:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRZ9setLambdaRiEUlvE_EONSt16remove_referenceIT_E4typeEOS4_
	movl	%eax, %esi
	movl	$4, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	(%esi), %eax
	movl	%eax, (%ebx)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE_EERT_v
	movl	%ebx, (%eax)
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2623:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E14_M_get_pointerERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E14_M_get_pointerERKSt9_Any_data:
LFB2624:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE_EERKT_v
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2624:
	.align 2
	.def	__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE_EERT_v;	.scl	3;	.type	32;	.endef
__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE_EERT_v:
LFB2625:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2625:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E8_M_cloneERSt9_Any_dataRKS4_St17integral_constantIbLb0EE;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E8_M_cloneERSt9_Any_dataRKS4_St17integral_constantIbLb0EE:
LFB2626:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE_EERKT_v
	movl	(%eax), %esi
	movl	$4, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	(%esi), %eax
	movl	%eax, (%ebx)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE_EERT_v
	movl	%ebx, (%eax)
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2626:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE_E10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE:
LFB2627:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE_EERT_v
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2627:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E15_M_init_functorERSt9_Any_dataOS2_St17integral_constantIbLb0EE;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E15_M_init_functorERSt9_Any_dataOS2_St17integral_constantIbLb0EE:
LFB2628:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRZ9setLambdaRiEUlvE0_EONSt16remove_referenceIT_E4typeEOS4_
	movl	%eax, %esi
	movl	$4, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	(%esi), %eax
	movl	%eax, (%ebx)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE0_EERT_v
	movl	%ebx, (%eax)
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2628:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E14_M_get_pointerERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E14_M_get_pointerERKSt9_Any_data:
LFB2629:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE0_EERKT_v
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2629:
	.align 2
	.def	__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE0_EERT_v;	.scl	3;	.type	32;	.endef
__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE0_EERT_v:
LFB2630:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2630:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E8_M_cloneERSt9_Any_dataRKS4_St17integral_constantIbLb0EE;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E8_M_cloneERSt9_Any_dataRKS4_St17integral_constantIbLb0EE:
LFB2631:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE0_EERKT_v
	movl	(%eax), %esi
	movl	$4, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	(%esi), %eax
	movl	%eax, (%ebx)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE0_EERT_v
	movl	%ebx, (%eax)
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2631:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE0_E10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE:
LFB2632:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE0_EERT_v
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2632:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E15_M_init_functorERSt9_Any_dataOS2_St17integral_constantIbLb0EE;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E15_M_init_functorERSt9_Any_dataOS2_St17integral_constantIbLb0EE:
LFB2633:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRZ9setLambdaRiEUlvE1_EONSt16remove_referenceIT_E4typeEOS4_
	movl	$1, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE1_EERT_v
	movl	%ebx, (%eax)
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2633:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E14_M_get_pointerERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E14_M_get_pointerERKSt9_Any_data:
LFB2634:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE1_EERKT_v
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2634:
	.align 2
	.def	__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE1_EERT_v;	.scl	3;	.type	32;	.endef
__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE1_EERT_v:
LFB2635:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2635:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E8_M_cloneERSt9_Any_dataRKS4_St17integral_constantIbLb0EE;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E8_M_cloneERSt9_Any_dataRKS4_St17integral_constantIbLb0EE:
LFB2636:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE1_EERKT_v
	movl	$1, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE1_EERT_v
	movl	%ebx, (%eax)
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2636:
	.def	__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ9setLambdaRiEUlvE1_E10_M_destroyERSt9_Any_dataSt17integral_constantIbLb0EE:
LFB2637:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE1_EERT_v
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2637:
	.align 2
	.def	__ZNKSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE_EERKT_v;	.scl	3;	.type	32;	.endef
__ZNKSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE_EERKT_v:
LFB2643:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9_Any_data9_M_accessEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2643:
	.align 2
	.def	__ZNKSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE0_EERKT_v;	.scl	3;	.type	32;	.endef
__ZNKSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE0_EERKT_v:
LFB2646:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9_Any_data9_M_accessEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2646:
	.align 2
	.def	__ZNKSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE1_EERKT_v;	.scl	3;	.type	32;	.endef
__ZNKSt9_Any_data9_M_accessIPZ9setLambdaRiEUlvE1_EERKT_v:
LFB2649:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9_Any_data9_M_accessEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2649:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB2650:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L421
	cmpl	$65535, 12(%ebp)
	jne	L421
	movl	$0, 4(%esp)
	movl	$_s_lambda1, (%esp)
	call	__ZNSt8functionIFivEEC1EDn
	movl	$0, 4(%esp)
	movl	$_s_lambda2, (%esp)
	call	__ZNSt8functionIFivEEC1EDn
	movl	$0, 4(%esp)
	movl	$_s_lambda3, (%esp)
	call	__ZNSt8functionIFivEEC1EDn
L421:
	cmpl	$0, 8(%ebp)
	jne	L420
	cmpl	$65535, 12(%ebp)
	jne	L420
	movl	$_s_lambda3, (%esp)
	call	__ZNSt8functionIFivEED1Ev
	movl	$_s_lambda2, (%esp)
	call	__ZNSt8functionIFivEED1Ev
	movl	$_s_lambda1, (%esp)
	call	__ZNSt8functionIFivEED1Ev
L420:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2650:
	.section .rdata,"dr"
	.align 4
__ZTIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_
	.align 4
__ZTIZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_
	.align 4
__ZTIZ9setLambdaRiEUlvE_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ9setLambdaRiEUlvE_
	.align 4
__ZTIZ9setLambdaRiEUlvE0_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ9setLambdaRiEUlvE0_
	.align 4
__ZTIZ9setLambdaRiEUlvE1_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ9setLambdaRiEUlvE1_
__ZTSZ9setLambdaRiEUlvE1_:
	.ascii "*Z9setLambdaRiEUlvE1_\0"
__ZTSZ9setLambdaRiEUlvE0_:
	.ascii "*Z9setLambdaRiEUlvE0_\0"
__ZTSZ9setLambdaRiEUlvE_:
	.ascii "*Z9setLambdaRiEUlvE_\0"
	.align 32
__ZTSZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_:
	.ascii "*ZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliE0_clEiEUlRiE_\0"
	.align 32
__ZTSZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_:
	.ascii "*ZZ22testOpt03_Type3_BeforeR11dataOpt03_tENKUliiE_clEiiEUlRiE_\0"
	.text
	.def	__GLOBAL__sub_I__Z9initOpt01R11dataOpt01_t;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z9initOpt01R11dataOpt01_t:
LFB2651:
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
LFE2651:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z9initOpt01R11dataOpt01_t
	.text
	.def	__GLOBAL__sub_D__Z9initOpt01R11dataOpt01_t;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_D__Z9initOpt01R11dataOpt01_t:
LFB2652:
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
LFE2652:
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__sub_D__Z9initOpt01R11dataOpt01_t
.lcomm __ZZ9setLambdaRiE14static_counter,4,4
	.section .rdata,"dr"
	.align 4
LC0:
	.long	0
	.ident	"GCC: (GNU) 4.8.2"
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	__ZSt25__throw_bad_function_callv;	.scl	2;	.type	32;	.endef
	.def	___real__Znwj;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	___real__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef

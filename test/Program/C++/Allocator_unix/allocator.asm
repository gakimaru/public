	.file	"allocator.cpp"
	.section	.text$_ZnwjPv,"x"
	.linkonce discard
	.globl	__ZnwjPv
	.def	__ZnwjPv;	.scl	2;	.type	32;	.endef
__ZnwjPv:
LFB41:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE41:
	.section	.text$_ZdlPvS_,"x"
	.linkonce discard
	.globl	__ZdlPvS_
	.def	__ZdlPvS_;	.scl	2;	.type	32;	.endef
__ZdlPvS_:
LFB43:
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
LFE43:
	.section	.text$_ZNKSt9type_info4nameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt9type_info4nameEv
	.def	__ZNKSt9type_info4nameEv;	.scl	2;	.type	32;	.endef
__ZNKSt9type_info4nameEv:
LFB45:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movzbl	(%eax), %eax
	cmpb	$42, %al
	jne	L5
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	addl	$1, %eax
	jmp	L6
L5:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
L6:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE45:
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "CTest0::Constructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest0C1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest0C1EPKc
	.def	__ZN6CTest0C1EPKc;	.scl	2;	.type	32;	.endef
__ZN6CTest0C1EPKc:
LFB61:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE61:
	.section .rdata,"dr"
	.align 4
LC1:
	.ascii "CTest0::Destructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest0D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest0D1Ev
	.def	__ZN6CTest0D1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest0D1Ev:
LFB64:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA64
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE64:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA64:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE64-LLSDACSB64
LLSDACSB64:
LLSDACSE64:
	.section	.text$_ZN6CTest0D1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC2:
	.ascii "---------- test0:\345\233\272\345\256\232\343\203\220\343\203\203\343\203\225\343\202\241\351\205\215\347\275\256new/\351\205\215\347\275\256delete ----------\0"
LC3:
	.ascii "buff=0x%p\12\0"
LC4:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "0\0"
LC5:
	.ascii "obj_p=0x%p\12\0"
	.text
	.globl	__Z5test0v
	.def	__Z5test0v;	.scl	2;	.type	32;	.endef
__Z5test0v:
LFB65:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA65
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$72, %esp
	movl	$LC2, (%esp)
LEHB0:
	call	_puts
	leal	-44(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, 4(%esp)
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z7new_ptrI6CTest0IPKcEEPT_PcDpT0_
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	leal	-44(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrI6CTest0EvRPT_Pc
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
LEHE0:
	jmp	L14
L13:
	movl	%eax, (%esp)
LEHB1:
	call	__Unwind_Resume
LEHE1:
L14:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE65:
	.section	.gcc_except_table,"w"
LLSDA65:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE65-LLSDACSB65
LLSDACSB65:
	.uleb128 LEHB0-LFB65
	.uleb128 LEHE0-LEHB0
	.uleb128 L13-LFB65
	.uleb128 0
	.uleb128 LEHB1-LFB65
	.uleb128 LEHE1-LEHB1
	.uleb128 0
	.uleb128 0
LLSDACSE65:
	.text
	.section .rdata,"dr"
	.align 4
LC6:
	.ascii "placement new(size=%d, where=0x%p)\12\0"
	.text
	.globl	__ZnwjPc
	.def	__ZnwjPc;	.scl	2;	.type	32;	.endef
__ZnwjPc:
LFB66:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA66
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
LEHB2:
	call	_printf
LEHE2:
	movl	12(%ebp), %eax
	jmp	L20
L19:
	cmpl	$-1, %edx
	je	L18
	movl	%eax, (%esp)
LEHB3:
	call	__Unwind_Resume
L18:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE3:
L20:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE66:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA66:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT66-LLSDATTD66
LLSDATTD66:
	.byte	0x1
	.uleb128 LLSDACSE66-LLSDACSB66
LLSDACSB66:
	.uleb128 LEHB2-LFB66
	.uleb128 LEHE2-LEHB2
	.uleb128 L19-LFB66
	.uleb128 0x1
	.uleb128 LEHB3-LFB66
	.uleb128 LEHE3-LEHB3
	.uleb128 0
	.uleb128 0
LLSDACSE66:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT66:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC7:
	.ascii "placement new[](size=%d, where=0x%p)\12\0"
	.text
	.globl	__ZnajPc
	.def	__ZnajPc;	.scl	2;	.type	32;	.endef
__ZnajPc:
LFB67:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA67
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
LEHB4:
	call	_printf
LEHE4:
	movl	12(%ebp), %eax
	jmp	L26
L25:
	cmpl	$-1, %edx
	je	L24
	movl	%eax, (%esp)
LEHB5:
	call	__Unwind_Resume
L24:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE5:
L26:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE67:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA67:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT67-LLSDATTD67
LLSDATTD67:
	.byte	0x1
	.uleb128 LLSDACSE67-LLSDACSB67
LLSDACSB67:
	.uleb128 LEHB4-LFB67
	.uleb128 LEHE4-LEHB4
	.uleb128 L25-LFB67
	.uleb128 0x1
	.uleb128 LEHB5-LFB67
	.uleb128 LEHE5-LEHB5
	.uleb128 0
	.uleb128 0
LLSDACSE67:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT67:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC8:
	.ascii "placement delete(p=0x%p, where=0x%p)\12\0"
	.text
	.globl	__ZdlPvPc
	.def	__ZdlPvPc;	.scl	2;	.type	32;	.endef
__ZdlPvPc:
LFB68:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA68
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC8, (%esp)
LEHB6:
	call	_printf
LEHE6:
	jmp	L31
L30:
	cmpl	$-1, %edx
	je	L29
	movl	%eax, (%esp)
LEHB7:
	call	__Unwind_Resume
L29:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE7:
L31:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE68:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA68:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT68-LLSDATTD68
LLSDATTD68:
	.byte	0x1
	.uleb128 LLSDACSE68-LLSDACSB68
LLSDACSB68:
	.uleb128 LEHB6-LFB68
	.uleb128 LEHE6-LEHB6
	.uleb128 L30-LFB68
	.uleb128 0x1
	.uleb128 LEHB7-LFB68
	.uleb128 LEHE7-LEHB7
	.uleb128 0
	.uleb128 0
LLSDACSE68:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT68:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC9:
	.ascii "placement delete[](p=0x%p, where=0x%p)\12\0"
	.text
	.globl	__ZdaPvPc
	.def	__ZdaPvPc;	.scl	2;	.type	32;	.endef
__ZdaPvPc:
LFB69:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA69
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC9, (%esp)
LEHB8:
	call	_printf
LEHE8:
	jmp	L36
L35:
	cmpl	$-1, %edx
	je	L34
	movl	%eax, (%esp)
LEHB9:
	call	__Unwind_Resume
L34:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE9:
L36:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE69:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA69:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT69-LLSDATTD69
LLSDATTD69:
	.byte	0x1
	.uleb128 LLSDACSE69-LLSDACSB69
LLSDACSB69:
	.uleb128 LEHB8-LFB69
	.uleb128 LEHE8-LEHB8
	.uleb128 L35-LFB69
	.uleb128 0x1
	.uleb128 LEHB9-LFB69
	.uleb128 LEHE9-LEHB9
	.uleb128 0
	.uleb128 0
LLSDACSE69:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT69:
	.byte	0
	.text
	.section .rdata,"dr"
LC10:
	.ascii "(default)\0"
	.align 4
LC11:
	.ascii "CTest1::DefaultConstructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest1C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest1C1Ev
	.def	__ZN6CTest1C1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest1C1Ev:
LFB74:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA74
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	$LC10, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB10:
	call	__ZN6CTest1C1EPKc
LEHE10:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC11, (%esp)
LEHB11:
	call	_printf
LEHE11:
	jmp	L40
L39:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest1D1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB12:
	call	__Unwind_Resume
LEHE12:
L40:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE74:
	.section	.gcc_except_table,"w"
LLSDA74:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE74-LLSDACSB74
LLSDACSB74:
	.uleb128 LEHB10-LFB74
	.uleb128 LEHE10-LEHB10
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB11-LFB74
	.uleb128 LEHE11-LEHB11
	.uleb128 L39-LFB74
	.uleb128 0
	.uleb128 LEHB12-LFB74
	.uleb128 LEHE12-LEHB12
	.uleb128 0
	.uleb128 0
LLSDACSE74:
	.section	.text$_ZN6CTest1C1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC12:
	.ascii "CTest1::Constructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest1C2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest1C2EPKc
	.def	__ZN6CTest1C2EPKc;	.scl	2;	.type	32;	.endef
__ZN6CTest1C2EPKc:
LFB76:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE76:
	.section	.text$_ZN6CTest1C1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest1C1EPKc
	.def	__ZN6CTest1C1EPKc;	.scl	2;	.type	32;	.endef
__ZN6CTest1C1EPKc:
LFB77:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE77:
	.section .rdata,"dr"
	.align 4
LC13:
	.ascii "CTest1::Destructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest1D2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest1D2Ev
	.def	__ZN6CTest1D2Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest1D2Ev:
LFB79:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA79
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC13, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE79:
	.section	.gcc_except_table,"w"
LLSDA79:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE79-LLSDACSB79
LLSDACSB79:
LLSDACSE79:
	.section	.text$_ZN6CTest1D2Ev,"x"
	.linkonce discard
	.section	.text$_ZN6CTest1D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest1D1Ev
	.def	__ZN6CTest1D1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest1D1Ev:
LFB80:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA80
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC13, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE80:
	.section	.gcc_except_table,"w"
LLSDA80:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE80-LLSDACSB80
LLSDACSB80:
LLSDACSE80:
	.section	.text$_ZN6CTest1D1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
LC14:
	.ascii "CTest1ex::Constructor\0"
	.section	.text$_ZN8CTest1exC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest1exC2Ev
	.def	__ZN8CTest1exC2Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest1exC2Ev:
LFB82:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$LC14, (%esp)
	call	_puts
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE82:
	.section .rdata,"dr"
LC15:
	.ascii "CTest1ex::Destructor\0"
	.section	.text$_ZN8CTest1exD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest1exD2Ev
	.def	__ZN8CTest1exD2Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest1exD2Ev:
LFB85:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA85
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$LC15, (%esp)
	call	_puts
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE85:
	.section	.gcc_except_table,"w"
LLSDA85:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE85-LLSDACSB85
LLSDACSB85:
LLSDACSE85:
	.section	.text$_ZN8CTest1exD2Ev,"x"
	.linkonce discard
	.section	.text$_ZN8CTest1exD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest1exD1Ev
	.def	__ZN8CTest1exD1Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest1exD1Ev:
LFB86:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA86
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$LC15, (%esp)
	call	_puts
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE86:
	.section	.gcc_except_table,"w"
LLSDA86:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE86-LLSDACSB86
LLSDACSB86:
LLSDACSE86:
	.section	.text$_ZN8CTest1exD1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC16:
	.ascii "CDerivedTest1::Constructor : name=\"%s\"\12\0"
	.section	.text$_ZN13CDerivedTest1C1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CDerivedTest1C1EPKc
	.def	__ZN13CDerivedTest1C1EPKc;	.scl	2;	.type	32;	.endef
__ZN13CDerivedTest1C1EPKc:
LFB92:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA92
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB13:
	call	__ZN6CTest1C2EPKc
LEHE13:
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	%eax, (%esp)
LEHB14:
	call	__ZN8CTest1exC2Ev
LEHE14:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC16, (%esp)
LEHB15:
	call	_printf
LEHE15:
	jmp	L57
L56:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	%eax, (%esp)
	call	__ZN8CTest1exD2Ev
	jmp	L54
L55:
	movl	%eax, %ebx
L54:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest1D2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB16:
	call	__Unwind_Resume
LEHE16:
L57:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE92:
	.section	.gcc_except_table,"w"
LLSDA92:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE92-LLSDACSB92
LLSDACSB92:
	.uleb128 LEHB13-LFB92
	.uleb128 LEHE13-LEHB13
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB14-LFB92
	.uleb128 LEHE14-LEHB14
	.uleb128 L55-LFB92
	.uleb128 0
	.uleb128 LEHB15-LFB92
	.uleb128 LEHE15-LEHB15
	.uleb128 L56-LFB92
	.uleb128 0
	.uleb128 LEHB16-LFB92
	.uleb128 LEHE16-LEHB16
	.uleb128 0
	.uleb128 0
LLSDACSE92:
	.section	.text$_ZN13CDerivedTest1C1EPKc,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC17:
	.ascii "---------- test1:\345\233\272\345\256\232\343\203\220\343\203\203\343\203\225\343\202\241\351\205\215\347\275\256new/\351\205\215\347\275\256delete\357\274\210\346\214\231\345\213\225\347\242\272\350\252\215\357\274\211----------\0"
LC18:
	.ascii "----------\343\202\257\343\203\251\343\202\271\0"
LC19:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "1\0"
LC20:
	.ascii "----------\343\202\257\343\203\251\343\202\271\343\201\256\351\205\215\345\210\227\0"
	.align 4
LC21:
	.ascii "*reinterpret_cast<int*>(buff)=%d\12\0"
	.align 4
LC22:
	.ascii "----------\343\203\227\343\203\252\343\203\237\343\203\206\343\202\243\343\203\226\345\236\213\0"
LC23:
	.ascii "data_p=0x%p\12\0"
LC24:
	.ascii "*data_p(0x%p)=%d\12\0"
	.align 4
LC25:
	.ascii "----------\343\203\227\343\203\252\343\203\237\343\203\206\343\202\243\343\203\226\345\236\213\343\201\256\351\205\215\345\210\227\0"
LC26:
	.ascii "*data_p(0x%p)[0]=%d\12\0"
	.align 4
LC27:
	.ascii "----------\345\244\232\351\207\215\347\266\231\346\211\277\343\202\257\343\203\251\343\202\271\0"
LC28:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "1\345\244\232\351\207\215\347\266\231\346\211\277\0"
	.align 4
LC29:
	.ascii "obj_p=0x%p, parent_p=0x%p, parent_ex_p=0x%p\12\0"
	.text
	.globl	__Z5test1v
	.def	__Z5test1v;	.scl	2;	.type	32;	.endef
__Z5test1v:
LFB96:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA96
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$156, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	$LC17, (%esp)
LEHB17:
	call	_puts
LEHE17:
	movl	$LC18, (%esp)
LEHB18:
	call	_puts
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
LEHE18:
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZnwjPc
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L59
	movl	$LC19, 4(%esp)
	movl	%ebx, (%esp)
LEHB19:
	call	__ZN6CTest1C1EPKc
LEHE19:
	movl	%ebx, %eax
	jmp	L60
L59:
	movl	%ebx, %eax
L60:
	movl	%eax, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
LEHB20:
	call	_printf
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrI6CTest1EvRPT_
LEHE20:
	movl	$LC20, (%esp)
LEHB21:
	call	_puts
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
LEHE21:
	movl	$3, -28(%ebp)
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$28, (%esp)
	call	__ZnajPc
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L61
	movl	$3, (%ebx)
	leal	4(%ebx), %esi
	movl	$2, %edi
	movl	%esi, -140(%ebp)
	jmp	L62
L63:
	movl	-140(%ebp), %eax
	movl	%eax, (%esp)
LEHB22:
	call	__ZN6CTest1C1Ev
LEHE22:
	addl	$8, -140(%ebp)
	subl	$1, %edi
L62:
	cmpl	$-1, %edi
	jne	L63
	leal	4(%ebx), %eax
	jmp	L64
L61:
	movl	%ebx, %eax
L64:
	movl	%eax, -48(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
LEHB23:
	call	_printf
	leal	-124(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC21, (%esp)
	call	_printf
	movl	$3, 4(%esp)
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrI6CTest1EvRPT_j
LEHE23:
	movl	$LC22, (%esp)
LEHB24:
	call	_puts
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	call	__ZnwjPc
	movl	%eax, -52(%ebp)
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC23, (%esp)
	call	_printf
	movl	-52(%ebp), %eax
	movb	$123, (%eax)
	movl	-52(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	-52(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC24, (%esp)
	call	_printf
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrIcEvRPT_
LEHE24:
	movl	$LC25, (%esp)
LEHB25:
	call	_puts
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$3, -32(%ebp)
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$3, (%esp)
	call	__ZnajPc
	movl	%eax, -56(%ebp)
	movl	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC23, (%esp)
	call	_printf
	leal	-124(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC21, (%esp)
	call	_printf
	movl	-56(%ebp), %eax
	movb	$123, (%eax)
	movl	-56(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	-56(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC26, (%esp)
	call	_printf
	movl	$3, 4(%esp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrIcEvRPT_j
LEHE25:
	movl	$LC27, (%esp)
LEHB26:
	call	_puts
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
LEHE26:
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$16, (%esp)
	call	__ZnwjPc
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L65
	movl	$LC28, 4(%esp)
	movl	%ebx, (%esp)
LEHB27:
	call	__ZN13CDerivedTest1C1EPKc
LEHE27:
	movl	%ebx, %eax
	jmp	L66
L65:
	movl	%ebx, %eax
L66:
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, -40(%ebp)
	cmpl	$0, -36(%ebp)
	je	L67
	movl	-36(%ebp), %eax
	addl	$8, %eax
	jmp	L68
L67:
	movl	$0, %eax
L68:
	movl	%eax, -60(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC29, (%esp)
LEHB28:
	call	_printf
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrI8CTest1exEvRPT_
LEHE28:
	jmp	L87
L80:
	movl	%eax, %esi
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvPc
	movl	%esi, %eax
	jmp	L70
L79:
L70:
	movl	%eax, (%esp)
LEHB29:
	call	__Unwind_Resume
L82:
	movl	%eax, -140(%ebp)
	testl	%esi, %esi
	je	L72
	movl	$2, %eax
	subl	%edi, %eax
	sall	$3, %eax
	leal	(%esi,%eax), %edi
L73:
	cmpl	%esi, %edi
	je	L72
	subl	$8, %edi
	movl	%edi, (%esp)
	call	__ZN6CTest1D1Ev
	jmp	L73
L72:
	movl	-140(%ebp), %esi
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdaPvPc
	movl	%esi, %eax
	jmp	L74
L81:
L74:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L83:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L84:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L86:
	movl	%eax, %esi
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvPc
	movl	%esi, %eax
	jmp	L78
L85:
L78:
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE29:
L87:
	addl	$156, %esp
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
LFE96:
	.section	.gcc_except_table,"w"
LLSDA96:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE96-LLSDACSB96
LLSDACSB96:
	.uleb128 LEHB17-LFB96
	.uleb128 LEHE17-LEHB17
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB18-LFB96
	.uleb128 LEHE18-LEHB18
	.uleb128 L79-LFB96
	.uleb128 0
	.uleb128 LEHB19-LFB96
	.uleb128 LEHE19-LEHB19
	.uleb128 L80-LFB96
	.uleb128 0
	.uleb128 LEHB20-LFB96
	.uleb128 LEHE20-LEHB20
	.uleb128 L79-LFB96
	.uleb128 0
	.uleb128 LEHB21-LFB96
	.uleb128 LEHE21-LEHB21
	.uleb128 L81-LFB96
	.uleb128 0
	.uleb128 LEHB22-LFB96
	.uleb128 LEHE22-LEHB22
	.uleb128 L82-LFB96
	.uleb128 0
	.uleb128 LEHB23-LFB96
	.uleb128 LEHE23-LEHB23
	.uleb128 L81-LFB96
	.uleb128 0
	.uleb128 LEHB24-LFB96
	.uleb128 LEHE24-LEHB24
	.uleb128 L83-LFB96
	.uleb128 0
	.uleb128 LEHB25-LFB96
	.uleb128 LEHE25-LEHB25
	.uleb128 L84-LFB96
	.uleb128 0
	.uleb128 LEHB26-LFB96
	.uleb128 LEHE26-LEHB26
	.uleb128 L85-LFB96
	.uleb128 0
	.uleb128 LEHB27-LFB96
	.uleb128 LEHE27-LEHB27
	.uleb128 L86-LFB96
	.uleb128 0
	.uleb128 LEHB28-LFB96
	.uleb128 LEHE28-LEHB28
	.uleb128 L85-LFB96
	.uleb128 0
	.uleb128 LEHB29-LFB96
	.uleb128 LEHE29-LEHB29
	.uleb128 0
	.uleb128 0
LLSDACSE96:
	.text
.lcomm __ZL19s_buffForTestClass2,64,32
	.section .rdata,"dr"
LC30:
	.ascii "CTest2::new(size=%d)\12\0"
	.section	.text$_ZN6CTest2nwEj,"x"
	.linkonce discard
	.globl	__ZN6CTest2nwEj
	.def	__ZN6CTest2nwEj;	.scl	2;	.type	32;	.endef
__ZN6CTest2nwEj:
LFB97:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA97
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC30, (%esp)
LEHB30:
	call	_printf
LEHE30:
	movl	$__ZL19s_buffForTestClass2, %eax
	jmp	L93
L92:
	cmpl	$-1, %edx
	je	L91
	movl	%eax, (%esp)
LEHB31:
	call	__Unwind_Resume
L91:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE31:
L93:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE97:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA97:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT97-LLSDATTD97
LLSDATTD97:
	.byte	0x1
	.uleb128 LLSDACSE97-LLSDACSB97
LLSDACSB97:
	.uleb128 LEHB30-LFB97
	.uleb128 LEHE30-LEHB30
	.uleb128 L92-LFB97
	.uleb128 0x1
	.uleb128 LEHB31-LFB97
	.uleb128 LEHE31-LEHB31
	.uleb128 0
	.uleb128 0
LLSDACSE97:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT97:
	.byte	0
	.section	.text$_ZN6CTest2nwEj,"x"
	.linkonce discard
	.section .rdata,"dr"
LC31:
	.ascii "CTest2::new[](size=%d)\12\0"
	.section	.text$_ZN6CTest2naEj,"x"
	.linkonce discard
	.globl	__ZN6CTest2naEj
	.def	__ZN6CTest2naEj;	.scl	2;	.type	32;	.endef
__ZN6CTest2naEj:
LFB98:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA98
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC31, (%esp)
LEHB32:
	call	_printf
LEHE32:
	movl	$__ZL19s_buffForTestClass2, %eax
	jmp	L99
L98:
	cmpl	$-1, %edx
	je	L97
	movl	%eax, (%esp)
LEHB33:
	call	__Unwind_Resume
L97:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE33:
L99:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE98:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA98:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT98-LLSDATTD98
LLSDATTD98:
	.byte	0x1
	.uleb128 LLSDACSE98-LLSDACSB98
LLSDACSB98:
	.uleb128 LEHB32-LFB98
	.uleb128 LEHE32-LEHB32
	.uleb128 L98-LFB98
	.uleb128 0x1
	.uleb128 LEHB33-LFB98
	.uleb128 LEHE33-LEHB33
	.uleb128 0
	.uleb128 0
LLSDACSE98:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT98:
	.byte	0
	.section	.text$_ZN6CTest2naEj,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC32:
	.ascii "CTest2::delete(p=0x%p, size=%d)\12\0"
	.section	.text$_ZN6CTest2dlEPvj,"x"
	.linkonce discard
	.globl	__ZN6CTest2dlEPvj
	.def	__ZN6CTest2dlEPvj;	.scl	2;	.type	32;	.endef
__ZN6CTest2dlEPvj:
LFB99:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA99
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC32, (%esp)
LEHB34:
	call	_printf
LEHE34:
	jmp	L104
L103:
	cmpl	$-1, %edx
	je	L102
	movl	%eax, (%esp)
LEHB35:
	call	__Unwind_Resume
L102:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE35:
L104:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE99:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA99:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT99-LLSDATTD99
LLSDATTD99:
	.byte	0x1
	.uleb128 LLSDACSE99-LLSDACSB99
LLSDACSB99:
	.uleb128 LEHB34-LFB99
	.uleb128 LEHE34-LEHB34
	.uleb128 L103-LFB99
	.uleb128 0x1
	.uleb128 LEHB35-LFB99
	.uleb128 LEHE35-LEHB35
	.uleb128 0
	.uleb128 0
LLSDACSE99:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT99:
	.byte	0
	.section	.text$_ZN6CTest2dlEPvj,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC33:
	.ascii "CTest2::delete[](p=0x%p, size=%d)\12\0"
	.section	.text$_ZN6CTest2daEPvj,"x"
	.linkonce discard
	.globl	__ZN6CTest2daEPvj
	.def	__ZN6CTest2daEPvj;	.scl	2;	.type	32;	.endef
__ZN6CTest2daEPvj:
LFB100:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA100
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC33, (%esp)
LEHB36:
	call	_printf
LEHE36:
	jmp	L109
L108:
	cmpl	$-1, %edx
	je	L107
	movl	%eax, (%esp)
LEHB37:
	call	__Unwind_Resume
L107:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE37:
L109:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE100:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA100:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT100-LLSDATTD100
LLSDATTD100:
	.byte	0x1
	.uleb128 LLSDACSE100-LLSDACSB100
LLSDACSB100:
	.uleb128 LEHB36-LFB100
	.uleb128 LEHE36-LEHB36
	.uleb128 L108-LFB100
	.uleb128 0x1
	.uleb128 LEHB37-LFB100
	.uleb128 LEHE37-LEHB37
	.uleb128 0
	.uleb128 0
LLSDACSE100:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT100:
	.byte	0
	.section	.text$_ZN6CTest2daEPvj,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC34:
	.ascii "CTest2::DefaultConstructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest2C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest2C1Ev
	.def	__ZN6CTest2C1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest2C1Ev:
LFB103:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA103
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	$LC10, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB38:
	call	__ZN6CTest2C1EPKc
LEHE38:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC34, (%esp)
LEHB39:
	call	_printf
LEHE39:
	jmp	L113
L112:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest2D1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB40:
	call	__Unwind_Resume
LEHE40:
L113:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE103:
	.section	.gcc_except_table,"w"
LLSDA103:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE103-LLSDACSB103
LLSDACSB103:
	.uleb128 LEHB38-LFB103
	.uleb128 LEHE38-LEHB38
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB39-LFB103
	.uleb128 LEHE39-LEHB39
	.uleb128 L112-LFB103
	.uleb128 0
	.uleb128 LEHB40-LFB103
	.uleb128 LEHE40-LEHB40
	.uleb128 0
	.uleb128 0
LLSDACSE103:
	.section	.text$_ZN6CTest2C1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC35:
	.ascii "CTest2::Constructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest2C2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest2C2EPKc
	.def	__ZN6CTest2C2EPKc;	.scl	2;	.type	32;	.endef
__ZN6CTest2C2EPKc:
LFB105:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV6CTest2+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC35, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE105:
	.section	.text$_ZN6CTest2C1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest2C1EPKc
	.def	__ZN6CTest2C1EPKc;	.scl	2;	.type	32;	.endef
__ZN6CTest2C1EPKc:
LFB106:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV6CTest2+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC35, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE106:
	.section .rdata,"dr"
	.align 4
LC36:
	.ascii "CTest2::Destructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest2D2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest2D2Ev
	.def	__ZN6CTest2D2Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest2D2Ev:
LFB108:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA108
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV6CTest2+8, (%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC36, (%esp)
	call	_printf
	movl	$0, %eax
	testl	%eax, %eax
	je	L116
	movl	$12, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest2dlEPvj
L116:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE108:
	.section	.gcc_except_table,"w"
LLSDA108:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE108-LLSDACSB108
LLSDACSB108:
LLSDACSE108:
	.section	.text$_ZN6CTest2D2Ev,"x"
	.linkonce discard
	.section	.text$_ZN6CTest2D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest2D1Ev
	.def	__ZN6CTest2D1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest2D1Ev:
LFB109:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA109
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV6CTest2+8, (%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC36, (%esp)
	call	_printf
	movl	$0, %eax
	testl	%eax, %eax
	je	L119
	movl	$12, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest2dlEPvj
L119:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE109:
	.section	.gcc_except_table,"w"
LLSDA109:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE109-LLSDACSB109
LLSDACSB109:
LLSDACSE109:
	.section	.text$_ZN6CTest2D1Ev,"x"
	.linkonce discard
	.section	.text$_ZN6CTest2D0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest2D0Ev
	.def	__ZN6CTest2D0Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest2D0Ev:
LFB110:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest2D1Ev
	movl	$12, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest2dlEPvj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE110:
	.section .rdata,"dr"
LC37:
	.ascii "CTest2ex::delete(p=0x%p)\12\0"
	.section	.text$_ZN8CTest2exdlEPv,"x"
	.linkonce discard
	.globl	__ZN8CTest2exdlEPv
	.def	__ZN8CTest2exdlEPv;	.scl	2;	.type	32;	.endef
__ZN8CTest2exdlEPv:
LFB112:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA112
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC37, (%esp)
LEHB41:
	call	_printf
LEHE41:
	jmp	L128
L127:
	cmpl	$-1, %edx
	je	L126
	movl	%eax, (%esp)
LEHB42:
	call	__Unwind_Resume
L126:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE42:
L128:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE112:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA112:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT112-LLSDATTD112
LLSDATTD112:
	.byte	0x1
	.uleb128 LLSDACSE112-LLSDACSB112
LLSDACSB112:
	.uleb128 LEHB41-LFB112
	.uleb128 LEHE41-LEHB41
	.uleb128 L127-LFB112
	.uleb128 0x1
	.uleb128 LEHB42-LFB112
	.uleb128 LEHE42-LEHB42
	.uleb128 0
	.uleb128 0
LLSDACSE112:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT112:
	.byte	0
	.section	.text$_ZN8CTest2exdlEPv,"x"
	.linkonce discard
	.section .rdata,"dr"
LC38:
	.ascii "CTest2ex::Constructor\0"
	.section	.text$_ZN8CTest2exC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest2exC2Ev
	.def	__ZN8CTest2exC2Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest2exC2Ev:
LFB114:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV8CTest2ex+8, (%eax)
	movl	$LC38, (%esp)
	call	_puts
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE114:
	.section .rdata,"dr"
LC39:
	.ascii "CTest2ex::Destructor\0"
	.section	.text$_ZN8CTest2exD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest2exD2Ev
	.def	__ZN8CTest2exD2Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest2exD2Ev:
LFB117:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA117
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV8CTest2ex+8, (%eax)
	movl	$LC39, (%esp)
	call	_puts
	movl	$0, %eax
	testl	%eax, %eax
	je	L130
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN8CTest2exdlEPv
L130:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE117:
	.section	.gcc_except_table,"w"
LLSDA117:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE117-LLSDACSB117
LLSDACSB117:
LLSDACSE117:
	.section	.text$_ZN8CTest2exD2Ev,"x"
	.linkonce discard
	.section	.text$_ZN8CTest2exD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest2exD1Ev
	.def	__ZN8CTest2exD1Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest2exD1Ev:
LFB118:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA118
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV8CTest2ex+8, (%eax)
	movl	$LC39, (%esp)
	call	_puts
	movl	$0, %eax
	testl	%eax, %eax
	je	L133
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN8CTest2exdlEPv
L133:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE118:
	.section	.gcc_except_table,"w"
LLSDA118:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE118-LLSDACSB118
LLSDACSB118:
LLSDACSE118:
	.section	.text$_ZN8CTest2exD1Ev,"x"
	.linkonce discard
	.section	.text$_ZN8CTest2exD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest2exD0Ev
	.def	__ZN8CTest2exD0Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest2exD0Ev:
LFB119:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN8CTest2exD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN8CTest2exdlEPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE119:
	.section .rdata,"dr"
LC40:
	.ascii "CDerivedTest2::new(size=%d)\12\0"
	.section	.text$_ZN13CDerivedTest2nwEj,"x"
	.linkonce discard
	.globl	__ZN13CDerivedTest2nwEj
	.def	__ZN13CDerivedTest2nwEj;	.scl	2;	.type	32;	.endef
__ZN13CDerivedTest2nwEj:
LFB120:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA120
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC40, (%esp)
LEHB43:
	call	_printf
LEHE43:
	movl	$__ZL19s_buffForTestClass2, %eax
	jmp	L143
L142:
	cmpl	$-1, %edx
	je	L141
	movl	%eax, (%esp)
LEHB44:
	call	__Unwind_Resume
L141:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE44:
L143:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE120:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA120:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT120-LLSDATTD120
LLSDATTD120:
	.byte	0x1
	.uleb128 LLSDACSE120-LLSDACSB120
LLSDACSB120:
	.uleb128 LEHB43-LFB120
	.uleb128 LEHE43-LEHB43
	.uleb128 L142-LFB120
	.uleb128 0x1
	.uleb128 LEHB44-LFB120
	.uleb128 LEHE44-LEHB44
	.uleb128 0
	.uleb128 0
LLSDACSE120:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT120:
	.byte	0
	.section	.text$_ZN13CDerivedTest2nwEj,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC41:
	.ascii "CDerivedTest2::delete(p=0x%p)\12\0"
	.section	.text$_ZN13CDerivedTest2dlEPv,"x"
	.linkonce discard
	.globl	__ZN13CDerivedTest2dlEPv
	.def	__ZN13CDerivedTest2dlEPv;	.scl	2;	.type	32;	.endef
__ZN13CDerivedTest2dlEPv:
LFB121:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA121
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC41, (%esp)
LEHB45:
	call	_printf
LEHE45:
	jmp	L148
L147:
	cmpl	$-1, %edx
	je	L146
	movl	%eax, (%esp)
LEHB46:
	call	__Unwind_Resume
L146:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE46:
L148:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE121:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA121:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT121-LLSDATTD121
LLSDATTD121:
	.byte	0x1
	.uleb128 LLSDACSE121-LLSDACSB121
LLSDACSB121:
	.uleb128 LEHB45-LFB121
	.uleb128 LEHE45-LEHB45
	.uleb128 L147-LFB121
	.uleb128 0x1
	.uleb128 LEHB46-LFB121
	.uleb128 LEHE46-LEHB46
	.uleb128 0
	.uleb128 0
LLSDACSE121:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT121:
	.byte	0
	.section	.text$_ZN13CDerivedTest2dlEPv,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC42:
	.ascii "CDerivedTest2::Constructor : name=\"%s\"\12\0"
	.section	.text$_ZN13CDerivedTest2C1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CDerivedTest2C1EPKc
	.def	__ZN13CDerivedTest2C1EPKc;	.scl	2;	.type	32;	.endef
__ZN13CDerivedTest2C1EPKc:
LFB127:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA127
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB47:
	call	__ZN6CTest2C2EPKc
LEHE47:
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
LEHB48:
	call	__ZN8CTest2exC2Ev
LEHE48:
	movl	8(%ebp), %eax
	movl	$__ZTV13CDerivedTest2+8, (%eax)
	movl	8(%ebp), %eax
	movl	$__ZTV13CDerivedTest2+24, 12(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC42, (%esp)
LEHB49:
	call	_printf
LEHE49:
	jmp	L154
L153:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__ZN8CTest2exD2Ev
	jmp	L151
L152:
	movl	%eax, %ebx
L151:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest2D2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB50:
	call	__Unwind_Resume
LEHE50:
L154:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE127:
	.section	.gcc_except_table,"w"
LLSDA127:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE127-LLSDACSB127
LLSDACSB127:
	.uleb128 LEHB47-LFB127
	.uleb128 LEHE47-LEHB47
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB48-LFB127
	.uleb128 LEHE48-LEHB48
	.uleb128 L152-LFB127
	.uleb128 0
	.uleb128 LEHB49-LFB127
	.uleb128 LEHE49-LEHB49
	.uleb128 L153-LFB127
	.uleb128 0
	.uleb128 LEHB50-LFB127
	.uleb128 LEHE50-LEHB50
	.uleb128 0
	.uleb128 0
LLSDACSE127:
	.section	.text$_ZN13CDerivedTest2C1EPKc,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC43:
	.ascii "CDerivedTest2::Destructor : name=\"%s\"\12\0"
	.section	.text$_ZN13CDerivedTest2D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CDerivedTest2D1Ev
	.def	__ZN13CDerivedTest2D1Ev;	.scl	2;	.type	32;	.endef
__ZN13CDerivedTest2D1Ev:
LFB130:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA130
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV13CDerivedTest2+8, (%eax)
	movl	8(%ebp), %eax
	movl	$__ZTV13CDerivedTest2+24, 12(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC43, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__ZN8CTest2exD2Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest2D2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L155
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CDerivedTest2dlEPv
L155:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE130:
	.section	.gcc_except_table,"w"
LLSDA130:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE130-LLSDACSB130
LLSDACSB130:
LLSDACSE130:
	.section	.text$_ZN13CDerivedTest2D1Ev,"x"
	.linkonce discard
	.section	.text$_ZThn12_N13CDerivedTest2D1Ev,"x"
	.linkonce discard
	.globl	__ZThn12_N13CDerivedTest2D1Ev
	.def	__ZThn12_N13CDerivedTest2D1Ev;	.scl	2;	.type	32;	.endef
__ZThn12_N13CDerivedTest2D1Ev:
LFB3871:
	.cfi_startproc
	subl	$12, 4(%esp)
	jmp	__ZN13CDerivedTest2D1Ev
	.cfi_endproc
LFE3871:
	.section	.text$_ZN13CDerivedTest2D0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CDerivedTest2D0Ev
	.def	__ZN13CDerivedTest2D0Ev;	.scl	2;	.type	32;	.endef
__ZN13CDerivedTest2D0Ev:
LFB131:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CDerivedTest2D1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CDerivedTest2dlEPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE131:
	.section	.text$_ZThn12_N13CDerivedTest2D0Ev,"x"
	.linkonce discard
	.globl	__ZThn12_N13CDerivedTest2D0Ev
	.def	__ZThn12_N13CDerivedTest2D0Ev;	.scl	2;	.type	32;	.endef
__ZThn12_N13CDerivedTest2D0Ev:
LFB3872:
	.cfi_startproc
	subl	$12, 4(%esp)
	jmp	__ZN13CDerivedTest2D0Ev
	.cfi_endproc
LFE3872:
	.section .rdata,"dr"
	.align 4
LC44:
	.ascii "---------- test2:\343\202\257\343\203\251\343\202\271\345\206\205new/delete ----------\0"
LC45:
	.ascii "s_buffForTestClass2=0x%p\12\0"
LC46:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "2\0"
	.align 4
LC47:
	.ascii "*reinterpret_cast<int*>(s_buffForTestClass2)=%d\12\0"
LC48:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "2\345\244\232\351\207\215\347\266\231\346\211\277\0"
	.text
	.globl	__Z5test2v
	.def	__Z5test2v;	.scl	2;	.type	32;	.endef
__Z5test2v:
LFB132:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA132
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
	movl	$LC44, (%esp)
LEHB51:
	call	_puts
	movl	$LC18, (%esp)
	call	_puts
	movl	$__ZL19s_buffForTestClass2, 4(%esp)
	movl	$LC45, (%esp)
	call	_printf
LEHE51:
	movl	$12, (%esp)
	call	__ZN6CTest2nwEj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L161
	movl	$LC46, 4(%esp)
	movl	%ebx, (%esp)
LEHB52:
	call	__ZN6CTest2C1EPKc
LEHE52:
	movl	%ebx, %eax
	jmp	L162
L161:
	movl	%ebx, %eax
L162:
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
LEHB53:
	call	_printf
	cmpl	$0, -28(%ebp)
	je	L163
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
L163:
	movl	$LC20, (%esp)
	call	_puts
	movl	$__ZL19s_buffForTestClass2, 4(%esp)
	movl	$LC45, (%esp)
	call	_printf
LEHE53:
	movl	$40, (%esp)
	call	__ZN6CTest2naEj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L164
	movl	$3, (%ebx)
	leal	4(%ebx), %edi
	movl	$2, %esi
	movl	%edi, -60(%ebp)
	jmp	L165
L166:
	movl	-60(%ebp), %eax
	movl	%eax, (%esp)
LEHB54:
	call	__ZN6CTest2C1Ev
LEHE54:
	addl	$12, -60(%ebp)
	subl	$1, %esi
L165:
	cmpl	$-1, %esi
	jne	L166
	leal	4(%ebx), %eax
	jmp	L167
L164:
	movl	%ebx, %eax
L167:
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
LEHB55:
	call	_printf
	movl	$__ZL19s_buffForTestClass2, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC47, (%esp)
	call	_printf
	cmpl	$0, -32(%ebp)
	je	L168
	movl	-32(%ebp), %eax
	subl	$4, %eax
	movl	(%eax), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, %edx
	movl	-32(%ebp), %eax
	leal	(%edx,%eax), %ebx
L170:
	cmpl	-32(%ebp), %ebx
	je	L169
	subl	$12, %ebx
	movl	(%ebx), %eax
	movl	(%eax), %eax
	movl	%ebx, (%esp)
	call	*%eax
	jmp	L170
L169:
	movl	-32(%ebp), %eax
	subl	$4, %eax
	movl	(%eax), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	4(%eax), %edx
	movl	-32(%ebp), %eax
	subl	$4, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6CTest2daEPvj
L168:
	movl	$LC27, (%esp)
	call	_puts
	movl	$__ZL19s_buffForTestClass2, 4(%esp)
	movl	$LC45, (%esp)
	call	_printf
LEHE55:
	movl	$24, (%esp)
	call	__ZN13CDerivedTest2nwEj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L171
	movl	$LC48, 4(%esp)
	movl	%ebx, (%esp)
LEHB56:
	call	__ZN13CDerivedTest2C1EPKc
LEHE56:
	movl	%ebx, %eax
	jmp	L172
L171:
	movl	%ebx, %eax
L172:
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, -40(%ebp)
	cmpl	$0, -36(%ebp)
	je	L173
	movl	-36(%ebp), %eax
	addl	$12, %eax
	jmp	L174
L173:
	movl	$0, %eax
L174:
	movl	%eax, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC29, (%esp)
LEHB57:
	call	_printf
	cmpl	$0, -44(%ebp)
	je	L184
	movl	-44(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-44(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	jmp	L184
L181:
	movl	%eax, %esi
	movl	$12, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN6CTest2dlEPvj
	movl	%esi, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
L182:
	movl	%eax, -60(%ebp)
	testl	%edi, %edi
	je	L178
	movl	$2, %eax
	subl	%esi, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%edi,%eax), %esi
L179:
	cmpl	%edi, %esi
	je	L178
	subl	$12, %esi
	movl	(%esi), %eax
	movl	(%eax), %eax
	movl	%esi, (%esp)
	call	*%eax
	jmp	L179
L178:
	movl	-60(%ebp), %esi
	movl	$40, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN6CTest2daEPvj
	movl	%esi, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
L183:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZN13CDerivedTest2dlEPv
	movl	%esi, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE57:
L184:
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
LFE132:
	.section	.gcc_except_table,"w"
LLSDA132:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE132-LLSDACSB132
LLSDACSB132:
	.uleb128 LEHB51-LFB132
	.uleb128 LEHE51-LEHB51
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB52-LFB132
	.uleb128 LEHE52-LEHB52
	.uleb128 L181-LFB132
	.uleb128 0
	.uleb128 LEHB53-LFB132
	.uleb128 LEHE53-LEHB53
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB54-LFB132
	.uleb128 LEHE54-LEHB54
	.uleb128 L182-LFB132
	.uleb128 0
	.uleb128 LEHB55-LFB132
	.uleb128 LEHE55-LEHB55
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB56-LFB132
	.uleb128 LEHE56-LEHB56
	.uleb128 L183-LFB132
	.uleb128 0
	.uleb128 LEHB57-LFB132
	.uleb128 LEHE57-LEHB57
	.uleb128 0
	.uleb128 0
LLSDACSE132:
	.text
	.section	.text$_ZN16CTest3Singleton111getSigletonEv,"x"
	.linkonce discard
	.globl	__ZN16CTest3Singleton111getSigletonEv
	.def	__ZN16CTest3Singleton111getSigletonEv;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton111getSigletonEv:
LFB133:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$__ZN16CTest3Singleton111m_singletonE, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE133:
	.section	.text$_ZNK16CTest3Singleton17getDataEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK16CTest3Singleton17getDataEv
	.def	__ZNK16CTest3Singleton17getDataEv;	.scl	2;	.type	32;	.endef
__ZNK16CTest3Singleton17getDataEv:
LFB134:
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
LFE134:
	.section	.text$_ZN16CTest3Singleton17setDataEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16CTest3Singleton17setDataEi
	.def	__ZN16CTest3Singleton17setDataEi;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton17setDataEi:
LFB135:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE135:
	.section .rdata,"dr"
	.align 4
LC49:
	.ascii "CTest3Singleton1::Constructor : m_data=%d\12\0"
	.section	.text$_ZN16CTest3Singleton1C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16CTest3Singleton1C1Ev
	.def	__ZN16CTest3Singleton1C1Ev;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton1C1Ev:
LFB138:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC49, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE138:
	.section .rdata,"dr"
	.align 4
LC50:
	.ascii "CTest3Singleton1::Destructor : m_data=%d\12\0"
	.section	.text$_ZN16CTest3Singleton1D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16CTest3Singleton1D1Ev
	.def	__ZN16CTest3Singleton1D1Ev;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton1D1Ev:
LFB141:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA141
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC50, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE141:
	.section	.gcc_except_table,"w"
LLSDA141:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE141-LLSDACSB141
LLSDACSB141:
LLSDACSE141:
	.section	.text$_ZN16CTest3Singleton1D1Ev,"x"
	.linkonce discard
	.globl	__ZN16CTest3Singleton111m_singletonE
	.bss
	.align 4
__ZN16CTest3Singleton111m_singletonE:
	.space 4
	.section .rdata,"dr"
LC51:
	.ascii "singleton_p->getData()=%d\12\0"
	.text
	.globl	__Z16printData_typeA1v
	.def	__Z16printData_typeA1v;	.scl	2;	.type	32;	.endef
__Z16printData_typeA1v:
LFB142:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	call	__ZN16CTest3Singleton111getSigletonEv
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK16CTest3Singleton17getDataEv
	movl	%eax, 4(%esp)
	movl	$LC51, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE142:
	.globl	__Z17updateData_typeA1v
	.def	__Z17updateData_typeA1v;	.scl	2;	.type	32;	.endef
__Z17updateData_typeA1v:
LFB143:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	call	__ZN16CTest3Singleton111getSigletonEv
	movl	%eax, -4(%ebp)
	movl	$123, 4(%esp)
	movl	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16CTest3Singleton17setDataEi
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE143:
	.section	.text$_ZN16CTest3Singleton211getSigletonEv,"x"
	.linkonce discard
	.globl	__ZN16CTest3Singleton211getSigletonEv
	.def	__ZN16CTest3Singleton211getSigletonEv;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton211getSigletonEv:
LFB144:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	__ZN16CTest3Singleton26createEv
	movl	__ZN16CTest3Singleton211m_singletonE, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE144:
	.section	.text$_ZNK16CTest3Singleton27getDataEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK16CTest3Singleton27getDataEv
	.def	__ZNK16CTest3Singleton27getDataEv;	.scl	2;	.type	32;	.endef
__ZNK16CTest3Singleton27getDataEv:
LFB145:
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
LFE145:
	.section	.text$_ZN16CTest3Singleton27setDataEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16CTest3Singleton27setDataEi
	.def	__ZN16CTest3Singleton27setDataEi;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton27setDataEi:
LFB146:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE146:
	.section	.text$_ZN16CTest3Singleton2nwEj,"x"
	.linkonce discard
	.globl	__ZN16CTest3Singleton2nwEj
	.def	__ZN16CTest3Singleton2nwEj;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton2nwEj:
LFB147:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$__ZN16CTest3Singleton215m_singletonBuffE, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE147:
	.section	.text$_ZN16CTest3Singleton2dlEPv,"x"
	.linkonce discard
	.globl	__ZN16CTest3Singleton2dlEPv
	.def	__ZN16CTest3Singleton2dlEPv;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton2dlEPv:
LFB148:
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
LFE148:
	.section	.text$_ZN16CTest3Singleton26createEv,"x"
	.linkonce discard
	.globl	__ZN16CTest3Singleton26createEv
	.def	__ZN16CTest3Singleton26createEv;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton26createEv:
LFB149:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA149
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
	movl	__ZN16CTest3Singleton211m_singletonE, %eax
	testl	%eax, %eax
	je	L204
	jmp	L203
L204:
	movl	$4, (%esp)
	call	__ZN16CTest3Singleton2nwEj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L206
	movl	%ebx, (%esp)
LEHB58:
	call	__ZN16CTest3Singleton2C1Ev
LEHE58:
	movl	%ebx, %eax
	jmp	L207
L206:
	movl	%ebx, %eax
L207:
	movl	%eax, __ZN16CTest3Singleton211m_singletonE
	jmp	L203
L209:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZN16CTest3Singleton2dlEPv
	movl	%esi, %eax
	movl	%eax, (%esp)
LEHB59:
	call	__Unwind_Resume
LEHE59:
L203:
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
LFE149:
	.section	.gcc_except_table,"w"
LLSDA149:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE149-LLSDACSB149
LLSDACSB149:
	.uleb128 LEHB58-LFB149
	.uleb128 LEHE58-LEHB58
	.uleb128 L209-LFB149
	.uleb128 0
	.uleb128 LEHB59-LFB149
	.uleb128 LEHE59-LEHB59
	.uleb128 0
	.uleb128 0
LLSDACSE149:
	.section	.text$_ZN16CTest3Singleton26createEv,"x"
	.linkonce discard
	.section	.text$_ZN16CTest3Singleton27destroyEv,"x"
	.linkonce discard
	.globl	__ZN16CTest3Singleton27destroyEv
	.def	__ZN16CTest3Singleton27destroyEv;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton27destroyEv:
LFB150:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	__ZN16CTest3Singleton211m_singletonE, %eax
	testl	%eax, %eax
	jne	L211
	jmp	L210
L211:
	movl	__ZN16CTest3Singleton211m_singletonE, %ebx
	testl	%ebx, %ebx
	je	L213
	movl	%ebx, (%esp)
	call	__ZN16CTest3Singleton2D1Ev
	movl	%ebx, (%esp)
	call	__ZN16CTest3Singleton2dlEPv
L213:
	movl	$0, __ZN16CTest3Singleton211m_singletonE
L210:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE150:
	.section .rdata,"dr"
	.align 4
LC52:
	.ascii "CTest3Singleton2::Constructor : m_data=%d\12\0"
	.section	.text$_ZN16CTest3Singleton2C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16CTest3Singleton2C1Ev
	.def	__ZN16CTest3Singleton2C1Ev;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton2C1Ev:
LFB153:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC52, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE153:
	.section .rdata,"dr"
	.align 4
LC53:
	.ascii "CTest3Singleton2::Destructor : m_data=%d\12\0"
	.section	.text$_ZN16CTest3Singleton2D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16CTest3Singleton2D1Ev
	.def	__ZN16CTest3Singleton2D1Ev;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton2D1Ev:
LFB156:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA156
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC53, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE156:
	.section	.gcc_except_table,"w"
LLSDA156:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE156-LLSDACSB156
LLSDACSB156:
LLSDACSE156:
	.section	.text$_ZN16CTest3Singleton2D1Ev,"x"
	.linkonce discard
	.globl	__ZN16CTest3Singleton211m_singletonE
	.bss
	.align 4
__ZN16CTest3Singleton211m_singletonE:
	.space 4
	.globl	__ZN16CTest3Singleton215m_singletonBuffE
__ZN16CTest3Singleton215m_singletonBuffE:
	.space 4
	.text
	.globl	__Z16printData_typeA2v
	.def	__Z16printData_typeA2v;	.scl	2;	.type	32;	.endef
__Z16printData_typeA2v:
LFB157:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	call	__ZN16CTest3Singleton211getSigletonEv
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK16CTest3Singleton27getDataEv
	movl	%eax, 4(%esp)
	movl	$LC51, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE157:
	.globl	__Z17updateData_typeA2v
	.def	__Z17updateData_typeA2v;	.scl	2;	.type	32;	.endef
__Z17updateData_typeA2v:
LFB158:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	call	__ZN16CTest3Singleton211getSigletonEv
	movl	%eax, -12(%ebp)
	movl	$123, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN16CTest3Singleton27setDataEi
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE158:
	.globl	__Z26deleteIntentionally_typeA2v
	.def	__Z26deleteIntentionally_typeA2v;	.scl	2;	.type	32;	.endef
__Z26deleteIntentionally_typeA2v:
LFB159:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	__ZN16CTest3Singleton27destroyEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE159:
	.section	.text$_ZNK6CTest37getDataEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6CTest37getDataEv
	.def	__ZNK6CTest37getDataEv;	.scl	2;	.type	32;	.endef
__ZNK6CTest37getDataEv:
LFB165:
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
LFE165:
	.section	.text$_ZN6CTest37setDataEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest37setDataEi
	.def	__ZN6CTest37setDataEi;	.scl	2;	.type	32;	.endef
__ZN6CTest37setDataEi:
LFB166:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE166:
	.section .rdata,"dr"
	.align 4
LC54:
	.ascii "CTest3::Constructor : m_data=%d\12\0"
	.section	.text$_ZN6CTest3C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest3C1Ev
	.def	__ZN6CTest3C1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest3C1Ev:
LFB169:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC54, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE169:
	.section .rdata,"dr"
	.align 4
LC55:
	.ascii "CTest3::Destructor : m_data=%d\12\0"
	.section	.text$_ZN6CTest3D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest3D1Ev
	.def	__ZN6CTest3D1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest3D1Ev:
LFB172:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA172
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC55, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE172:
	.section	.gcc_except_table,"w"
LLSDA172:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE172-LLSDACSB172
LLSDACSB172:
LLSDACSE172:
	.section	.text$_ZN6CTest3D1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
LC56:
	.ascii "singleton->getData()=%d\12\0"
	.text
	.globl	__Z15printData_typeBv
	.def	__Z15printData_typeBv;	.scl	2;	.type	32;	.endef
__Z15printData_typeBv:
LFB173:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA173
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
LEHB60:
	call	__ZN10CSingletonI6CTest3EC1Ev
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10CSingletonI6CTest3EptEv
	movl	%eax, (%esp)
	call	__ZNK6CTest37getDataEv
	movl	%eax, 4(%esp)
	movl	$LC56, (%esp)
	call	_printf
LEHE60:
	jmp	L229
L228:
	movl	%eax, (%esp)
LEHB61:
	call	__Unwind_Resume
LEHE61:
L229:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE173:
	.section	.gcc_except_table,"w"
LLSDA173:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE173-LLSDACSB173
LLSDACSB173:
	.uleb128 LEHB60-LFB173
	.uleb128 LEHE60-LEHB60
	.uleb128 L228-LFB173
	.uleb128 0
	.uleb128 LEHB61-LFB173
	.uleb128 LEHE61-LEHB61
	.uleb128 0
	.uleb128 0
LLSDACSE173:
	.text
	.globl	__Z16updateData_typeBv
	.def	__Z16updateData_typeBv;	.scl	2;	.type	32;	.endef
__Z16updateData_typeBv:
LFB174:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA174
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
LEHB62:
	call	__ZN10CSingletonI6CTest3EC1Ev
LEHE62:
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10CSingletonI6CTest3EptEv
	movl	$123, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN6CTest37setDataEi
	jmp	L233
L232:
	movl	%eax, (%esp)
LEHB63:
	call	__Unwind_Resume
LEHE63:
L233:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE174:
	.section	.gcc_except_table,"w"
LLSDA174:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE174-LLSDACSB174
LLSDACSB174:
	.uleb128 LEHB62-LFB174
	.uleb128 LEHE62-LEHB62
	.uleb128 L232-LFB174
	.uleb128 0
	.uleb128 LEHB63-LFB174
	.uleb128 LEHE63-LEHB63
	.uleb128 0
	.uleb128 0
LLSDACSE174:
	.text
	.globl	__Z25deleteIntentionally_typeBv
	.def	__Z25deleteIntentionally_typeBv;	.scl	2;	.type	32;	.endef
__Z25deleteIntentionally_typeBv:
LFB175:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA175
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
LEHB64:
	call	__ZN10CSingletonI6CTest3EC1Ev
LEHE64:
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10CSingletonI6CTest3E7destroyEv
	jmp	L237
L236:
	movl	%eax, (%esp)
LEHB65:
	call	__Unwind_Resume
LEHE65:
L237:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE175:
	.section	.gcc_except_table,"w"
LLSDA175:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE175-LLSDACSB175
LLSDACSB175:
	.uleb128 LEHB64-LFB175
	.uleb128 LEHE64-LEHB64
	.uleb128 L236-LFB175
	.uleb128 0
	.uleb128 LEHB65-LFB175
	.uleb128 LEHE65-LEHB65
	.uleb128 0
	.uleb128 0
LLSDACSE175:
	.text
	.section .rdata,"dr"
	.align 4
LC57:
	.ascii "---------- test3:\343\202\267\343\203\263\343\202\260\343\203\253\343\203\210\343\203\263 ----------\0"
	.align 4
LC58:
	.ascii "----------\345\260\202\347\224\250\343\202\267\343\203\263\343\202\260\343\203\253\343\203\210\343\203\263\357\274\232\345\215\230\347\264\224\343\202\277\343\202\244\343\203\227\0"
	.align 4
LC59:
	.ascii "----------\345\260\202\347\224\250\343\202\267\343\203\263\343\202\260\343\203\253\343\203\210\343\203\263\357\274\232\343\202\244\343\203\263\343\202\271\343\202\277\343\203\263\343\202\271\346\223\215\344\275\234\343\202\277\343\202\244\343\203\227\0"
	.align 4
LC60:
	.ascii "----------\346\261\216\347\224\250\343\202\267\343\203\263\343\202\260\343\203\253\343\203\210\343\203\263\0"
	.text
	.globl	__Z5test3v
	.def	__Z5test3v;	.scl	2;	.type	32;	.endef
__Z5test3v:
LFB176:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$LC57, (%esp)
	call	_puts
	movl	$LC58, (%esp)
	call	_puts
	call	__Z16printData_typeA1v
	call	__Z17updateData_typeA1v
	call	__Z16printData_typeA1v
	movl	$LC59, (%esp)
	call	_puts
	call	__Z16printData_typeA2v
	call	__Z17updateData_typeA2v
	call	__Z16printData_typeA2v
	call	__Z26deleteIntentionally_typeA2v
	call	__Z16printData_typeA2v
	movl	$LC60, (%esp)
	call	_puts
	call	__Z15printData_typeBv
	call	__Z16updateData_typeBv
	call	__Z15printData_typeBv
	call	__Z25deleteIntentionally_typeBv
	call	__Z15printData_typeBv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE176:
	.section	.text$_ZN15IStackAllocatorD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15IStackAllocatorD2Ev
	.def	__ZN15IStackAllocatorD2Ev;	.scl	2;	.type	32;	.endef
__ZN15IStackAllocatorD2Ev:
LFB178:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV15IStackAllocator+8, (%eax)
	movl	$0, %eax
	testl	%eax, %eax
	je	L239
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L239:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE178:
	.section	.text$_ZN15IStackAllocatorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15IStackAllocatorD1Ev
	.def	__ZN15IStackAllocatorD1Ev;	.scl	2;	.type	32;	.endef
__ZN15IStackAllocatorD1Ev:
LFB179:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV15IStackAllocator+8, (%eax)
	movl	$0, %eax
	testl	%eax, %eax
	je	L242
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L242:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE179:
	.section	.text$_ZN15IStackAllocatorD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15IStackAllocatorD0Ev
	.def	__ZN15IStackAllocatorD0Ev;	.scl	2;	.type	32;	.endef
__ZN15IStackAllocatorD0Ev:
LFB180:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15IStackAllocatorD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE180:
	.section	.text$_ZNK15CStackAllocator8getTotalEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator8getTotalEv
	.def	__ZNK15CStackAllocator8getTotalEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator8getTotalEv:
LFB181:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE181:
	.section	.text$_ZNK15CStackAllocator7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator7getUsedEv
	.def	__ZNK15CStackAllocator7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator7getUsedEv:
LFB182:
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
LFE182:
	.section	.text$_ZNK15CStackAllocator9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator9getRemainEv
	.def	__ZNK15CStackAllocator9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator9getRemainEv:
LFB183:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE183:
	.section	.text$_ZNK15CStackAllocator7getBuffEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator7getBuffEv
	.def	__ZNK15CStackAllocator7getBuffEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator7getBuffEv:
LFB184:
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
LFE184:
	.section	.text$_ZNK15CStackAllocator10getNowPtrNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator10getNowPtrNEv
	.def	__ZNK15CStackAllocator10getNowPtrNEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator10getNowPtrNEv:
LFB185:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	addl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE185:
	.section	.text$_ZNK15CStackAllocator9getNowPtrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator9getNowPtrEv
	.def	__ZNK15CStackAllocator9getNowPtrEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator9getNowPtrEv:
LFB186:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK15CStackAllocator10getNowPtrNEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE186:
	.section	.text$_ZNK15CStackAllocator10getMarkerNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator10getMarkerNEv
	.def	__ZNK15CStackAllocator10getMarkerNEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator10getMarkerNEv:
LFB187:
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
LFE187:
	.section	.text$_ZNK15CStackAllocator9getMarkerEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator9getMarkerEv
	.def	__ZNK15CStackAllocator9getMarkerEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator9getMarkerEv:
LFB188:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK15CStackAllocator10getMarkerNEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE188:
	.section .rdata,"dr"
	.align 4
LC61:
	.ascii "stack overflow!(size=%d+align=%d, remain=%d)\12\0"
	.section	.text$_ZN15CStackAllocator6allocNEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator6allocNEjj
	.def	__ZN15CStackAllocator6allocNEjj;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator6allocNEjj:
LFB189:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	addl	%edx, %eax
	movl	%eax, -12(%ebp)
	cmpl	$0, 16(%ebp)
	je	L264
	movl	-12(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	testl	%eax, %eax
	je	L265
	movl	-12(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	movl	16(%ebp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	jmp	L267
L265:
	movl	$0, %eax
	jmp	L267
L264:
	movl	$0, %eax
L267:
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	movl	12(%eax), %edx
	movl	-16(%ebp), %eax
	addl	%eax, %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	-20(%ebp), %eax
	jae	L268
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, 12(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC61, (%esp)
	call	_printf
	movl	$0, %eax
	jmp	L269
L268:
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	addl	%edx, %eax
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	-24(%ebp), %eax
L269:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE189:
	.section	.text$_ZN15CStackAllocator5allocEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator5allocEjj
	.def	__ZN15CStackAllocator5allocEjj;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator5allocEjj:
LFB190:
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
	call	__ZN15CStackAllocator6allocNEjj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE190:
	.section	.text$_ZN15CStackAllocator5backNEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator5backNEj
	.def	__ZN15CStackAllocator5backNEj;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator5backNEj:
LFB191:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	cmpl	12(%ebp), %eax
	ja	L273
	jmp	L272
L273:
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 12(%eax)
L272:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE191:
	.section	.text$_ZN15CStackAllocator4backEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator4backEj
	.def	__ZN15CStackAllocator4backEj;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator4backEj:
LFB192:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CStackAllocator5backNEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE192:
	.section	.text$_ZN15CStackAllocator5backNEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator5backNEPKv
	.def	__ZN15CStackAllocator5backNEPKv;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator5backNEPKv:
LFB193:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE193:
	.section	.text$_ZN15CStackAllocator4backEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator4backEPKv
	.def	__ZN15CStackAllocator4backEPKv;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator4backEPKv:
LFB194:
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
	call	__ZN15CStackAllocator5backNEPKv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE194:
	.section	.text$_ZN15CStackAllocator6clearNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator6clearNEv
	.def	__ZN15CStackAllocator6clearNEv;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator6clearNEv:
LFB195:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	$0, 12(%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE195:
	.section	.text$_ZN15CStackAllocator5clearEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator5clearEv
	.def	__ZN15CStackAllocator5clearEv;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator5clearEv:
LFB196:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CStackAllocator6clearNEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE196:
	.section	.text$_ZN15CStackAllocator8clearAllEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator8clearAllEv
	.def	__ZN15CStackAllocator8clearAllEv;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator8clearAllEv:
LFB197:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CStackAllocator6clearNEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE197:
	.section	.text$_ZN15IStackAllocatorC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15IStackAllocatorC2Ev
	.def	__ZN15IStackAllocatorC2Ev;	.scl	2;	.type	32;	.endef
__ZN15IStackAllocatorC2Ev:
LFB200:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	$__ZTV15IStackAllocator+8, (%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE200:
	.section	.text$_ZN15CStackAllocatorC2EPvj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocatorC2EPvj
	.def	__ZN15CStackAllocatorC2EPvj;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocatorC2EPvj:
LFB202:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15IStackAllocatorC2Ev
	movl	8(%ebp), %eax
	movl	$__ZTV15CStackAllocator+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	$0, 12(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE202:
	.section	.text$_ZN15CStackAllocatorD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocatorD2Ev
	.def	__ZN15CStackAllocatorD2Ev;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocatorD2Ev:
LFB205:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV15CStackAllocator+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15IStackAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L284
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L284:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE205:
	.section	.text$_ZN15CStackAllocatorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocatorD1Ev
	.def	__ZN15CStackAllocatorD1Ev;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocatorD1Ev:
LFB206:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV15CStackAllocator+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15IStackAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L287
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L287:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE206:
	.section	.text$_ZN15CStackAllocatorD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocatorD0Ev
	.def	__ZN15CStackAllocatorD0Ev;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocatorD0Ev:
LFB207:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CStackAllocatorD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE207:
	.section .rdata,"dr"
	.align 4
LC62:
	.ascii "placement new(size=%d, stack_allocator.marker=%d, align=%d)\12\0"
	.text
	.globl	__ZnwjR15CStackAllocatorj
	.def	__ZnwjR15CStackAllocatorj;	.scl	2;	.type	32;	.endef
__ZnwjR15CStackAllocatorj:
LFB208:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA208
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
LEHB66:
	call	*%eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC62, (%esp)
	call	_printf
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$20, %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
LEHE66:
	jmp	L297
L296:
	cmpl	$-1, %edx
	je	L295
	movl	%eax, (%esp)
LEHB67:
	call	__Unwind_Resume
L295:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE67:
L297:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE208:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA208:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT208-LLSDATTD208
LLSDATTD208:
	.byte	0x1
	.uleb128 LLSDACSE208-LLSDACSB208
LLSDACSB208:
	.uleb128 LEHB66-LFB208
	.uleb128 LEHE66-LEHB66
	.uleb128 L296-LFB208
	.uleb128 0x1
	.uleb128 LEHB67-LFB208
	.uleb128 LEHE67-LEHB67
	.uleb128 0
	.uleb128 0
LLSDACSE208:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT208:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC63:
	.ascii "placement new[](size=%d, stack_allocator.marker=%d, align=%d)\12\0"
	.text
	.globl	__ZnajR15CStackAllocatorj
	.def	__ZnajR15CStackAllocatorj;	.scl	2;	.type	32;	.endef
__ZnajR15CStackAllocatorj:
LFB209:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA209
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
LEHB68:
	call	*%eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC63, (%esp)
	call	_printf
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$20, %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
LEHE68:
	jmp	L303
L302:
	cmpl	$-1, %edx
	je	L301
	movl	%eax, (%esp)
LEHB69:
	call	__Unwind_Resume
L301:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE69:
L303:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE209:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA209:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT209-LLSDATTD209
LLSDATTD209:
	.byte	0x1
	.uleb128 LLSDACSE209-LLSDACSB209
LLSDACSB209:
	.uleb128 LEHB68-LFB209
	.uleb128 LEHE68-LEHB68
	.uleb128 L302-LFB209
	.uleb128 0x1
	.uleb128 LEHB69-LFB209
	.uleb128 LEHE69-LEHB69
	.uleb128 0
	.uleb128 0
LLSDACSE209:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT209:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC64:
	.ascii "placement delete(p=0x%p, stack_allocator.marker=%d)\12\0"
	.text
	.globl	__ZdlPvR15CStackAllocatorj
	.def	__ZdlPvR15CStackAllocatorj;	.scl	2;	.type	32;	.endef
__ZdlPvR15CStackAllocatorj:
LFB210:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA210
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
LEHB70:
	call	*%eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC64, (%esp)
	call	_printf
LEHE70:
	jmp	L308
L307:
	cmpl	$-1, %edx
	je	L306
	movl	%eax, (%esp)
LEHB71:
	call	__Unwind_Resume
L306:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE71:
L308:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE210:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA210:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT210-LLSDATTD210
LLSDATTD210:
	.byte	0x1
	.uleb128 LLSDACSE210-LLSDACSB210
LLSDACSB210:
	.uleb128 LEHB70-LFB210
	.uleb128 LEHE70-LEHB70
	.uleb128 L307-LFB210
	.uleb128 0x1
	.uleb128 LEHB71-LFB210
	.uleb128 LEHE71-LEHB71
	.uleb128 0
	.uleb128 0
LLSDACSE210:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT210:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC65:
	.ascii "placement delete[](p=0x%p, stack_allocator.marker=%d)\12\0"
	.text
	.globl	__ZdaPvR15CStackAllocatorj
	.def	__ZdaPvR15CStackAllocatorj;	.scl	2;	.type	32;	.endef
__ZdaPvR15CStackAllocatorj:
LFB211:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA211
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
LEHB72:
	call	*%eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC65, (%esp)
	call	_printf
LEHE72:
	jmp	L313
L312:
	cmpl	$-1, %edx
	je	L311
	movl	%eax, (%esp)
LEHB73:
	call	__Unwind_Resume
L311:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE73:
L313:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE211:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA211:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT211-LLSDATTD211
LLSDATTD211:
	.byte	0x1
	.uleb128 LLSDACSE211-LLSDACSB211
LLSDACSB211:
	.uleb128 LEHB72-LFB211
	.uleb128 LEHE72-LEHB72
	.uleb128 L312-LFB211
	.uleb128 0x1
	.uleb128 LEHB73-LFB211
	.uleb128 LEHE73-LEHB73
	.uleb128 0
	.uleb128 0
LLSDACSE211:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT211:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC66:
	.ascii "CTest4a::DefaultConstructor : name=\"%s\"\12\0"
	.section	.text$_ZN7CTest4aC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7CTest4aC1Ev
	.def	__ZN7CTest4aC1Ev;	.scl	2;	.type	32;	.endef
__ZN7CTest4aC1Ev:
LFB218:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA218
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	$LC10, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB74:
	call	__ZN7CTest4aC1EPKc
LEHE74:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC66, (%esp)
LEHB75:
	call	_printf
LEHE75:
	jmp	L317
L316:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN7CTest4aD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB76:
	call	__Unwind_Resume
LEHE76:
L317:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE218:
	.section	.gcc_except_table,"w"
LLSDA218:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE218-LLSDACSB218
LLSDACSB218:
	.uleb128 LEHB74-LFB218
	.uleb128 LEHE74-LEHB74
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB75-LFB218
	.uleb128 LEHE75-LEHB75
	.uleb128 L316-LFB218
	.uleb128 0
	.uleb128 LEHB76-LFB218
	.uleb128 LEHE76-LEHB76
	.uleb128 0
	.uleb128 0
LLSDACSE218:
	.section	.text$_ZN7CTest4aC1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC67:
	.ascii "CTest4a::Constructor : name=\"%s\"\12\0"
	.section	.text$_ZN7CTest4aC1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7CTest4aC1EPKc
	.def	__ZN7CTest4aC1EPKc;	.scl	2;	.type	32;	.endef
__ZN7CTest4aC1EPKc:
LFB221:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC67, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE221:
	.section .rdata,"dr"
	.align 4
LC68:
	.ascii "CTest4a::Destructor : name=\"%s\"\12\0"
	.section	.text$_ZN7CTest4aD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7CTest4aD1Ev
	.def	__ZN7CTest4aD1Ev;	.scl	2;	.type	32;	.endef
__ZN7CTest4aD1Ev:
LFB224:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA224
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC68, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE224:
	.section	.gcc_except_table,"w"
LLSDA224:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE224-LLSDACSB224
LLSDACSB224:
LLSDACSE224:
	.section	.text$_ZN7CTest4aD1Ev,"x"
	.linkonce discard
	.section	.text$_ZNK19CDualStackAllocator8getTotalEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator8getTotalEv
	.def	__ZNK19CDualStackAllocator8getTotalEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator8getTotalEv:
LFB225:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE225:
	.section	.text$_ZNK19CDualStackAllocator7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator7getUsedEv
	.def	__ZNK19CDualStackAllocator7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator7getUsedEv:
LFB226:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%eax), %edx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	addl	%eax, %edx
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE226:
	.section	.text$_ZNK19CDualStackAllocator9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator9getRemainEv
	.def	__ZNK19CDualStackAllocator9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator9getRemainEv:
LFB227:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	16(%eax), %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE227:
	.section	.text$_ZNK19CDualStackAllocator17getDefaultOrderedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator17getDefaultOrderedEv
	.def	__ZNK19CDualStackAllocator17getDefaultOrderedEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator17getDefaultOrderedEv:
LFB228:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE228:
	.section	.text$_ZN19CDualStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE
	.def	__ZN19CDualStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE:
LFB229:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	cmpl	$-1, 12(%ebp)
	jne	L330
	movl	$-1, %eax
	jmp	L331
L330:
	movl	$1, %eax
L331:
	movl	8(%ebp), %edx
	movl	%eax, 20(%edx)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE229:
	.section	.text$_ZNK19CDualStackAllocator7getBuffEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator7getBuffEv
	.def	__ZNK19CDualStackAllocator7getBuffEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator7getBuffEv:
LFB230:
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
LFE230:
	.section	.text$_ZNK19CDualStackAllocator10getNowPtrNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator10getNowPtrNEv
	.def	__ZNK19CDualStackAllocator10getNowPtrNEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator10getNowPtrNEv:
LFB231:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	addl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE231:
	.section	.text$_ZNK19CDualStackAllocator10getNowPtrREv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator10getNowPtrREv
	.def	__ZNK19CDualStackAllocator10getNowPtrREv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator10getNowPtrREv:
LFB232:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	addl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE232:
	.section	.text$_ZNK19CDualStackAllocator10getNowPtrDEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator10getNowPtrDEv
	.def	__ZNK19CDualStackAllocator10getNowPtrDEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator10getNowPtrDEv:
LFB233:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator9getNowPtrEN15IStackAllocator9E_ORDEREDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE233:
	.section	.text$_ZNK19CDualStackAllocator9getNowPtrEN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator9getNowPtrEN15IStackAllocator9E_ORDEREDE
	.def	__ZNK19CDualStackAllocator9getNowPtrEN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator9getNowPtrEN15IStackAllocator9E_ORDEREDE:
LFB234:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L341
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getNowPtrDEv
	jmp	L342
L341:
	cmpl	$-1, 12(%ebp)
	jne	L343
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getNowPtrREv
	jmp	L342
L343:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getNowPtrNEv
L342:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE234:
	.section	.text$_ZNK19CDualStackAllocator9getNowPtrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator9getNowPtrEv
	.def	__ZNK19CDualStackAllocator9getNowPtrEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator9getNowPtrEv:
LFB235:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getNowPtrDEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE235:
	.section	.text$_ZNK19CDualStackAllocator10getMarkerNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator10getMarkerNEv
	.def	__ZNK19CDualStackAllocator10getMarkerNEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator10getMarkerNEv:
LFB236:
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
LFE236:
	.section	.text$_ZNK19CDualStackAllocator10getMarkerREv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator10getMarkerREv
	.def	__ZNK19CDualStackAllocator10getMarkerREv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator10getMarkerREv:
LFB237:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE237:
	.section	.text$_ZNK19CDualStackAllocator10getMarkerDEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator10getMarkerDEv
	.def	__ZNK19CDualStackAllocator10getMarkerDEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator10getMarkerDEv:
LFB238:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator9getMarkerEN15IStackAllocator9E_ORDEREDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE238:
	.section	.text$_ZNK19CDualStackAllocator9getMarkerEN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator9getMarkerEN15IStackAllocator9E_ORDEREDE
	.def	__ZNK19CDualStackAllocator9getMarkerEN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator9getMarkerEN15IStackAllocator9E_ORDEREDE:
LFB239:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L355
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerDEv
	jmp	L356
L355:
	cmpl	$-1, 12(%ebp)
	jne	L357
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerREv
	jmp	L356
L357:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
L356:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE239:
	.section	.text$_ZNK19CDualStackAllocator9getMarkerEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator9getMarkerEv
	.def	__ZNK19CDualStackAllocator9getMarkerEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator9getMarkerEv:
LFB240:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerDEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE240:
	.section .rdata,"dr"
	.align 4
LC69:
	.ascii "normal-stack overflow!(size=%d+align=%d, remain=%d)\12\0"
	.section	.text$_ZN19CDualStackAllocator6allocNEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator6allocNEjj
	.def	__ZN19CDualStackAllocator6allocNEjj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator6allocNEjj:
LFB241:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	addl	%edx, %eax
	movl	%eax, -12(%ebp)
	cmpl	$0, 16(%ebp)
	je	L363
	movl	-12(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	testl	%eax, %eax
	je	L364
	movl	-12(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	movl	16(%ebp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	jmp	L366
L364:
	movl	$0, %eax
	jmp	L366
L363:
	movl	$0, %eax
L366:
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	movl	12(%eax), %edx
	movl	-16(%ebp), %eax
	addl	%eax, %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	cmpl	-20(%ebp), %eax
	jae	L367
	movl	8(%ebp), %eax
	movl	16(%eax), %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, 12(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC69, (%esp)
	call	_printf
	movl	$0, %eax
	jmp	L368
L367:
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	addl	%edx, %eax
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	-24(%ebp), %eax
L368:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE241:
	.section .rdata,"dr"
	.align 4
LC70:
	.ascii "reversed-stack overflow!(size=%d+align=%d, remain=%d)\12\0"
	.section	.text$_ZN19CDualStackAllocator6allocREjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator6allocREjj
	.def	__ZN19CDualStackAllocator6allocREjj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator6allocREjj:
LFB242:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	addl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -16(%ebp)
	cmpl	$0, 16(%ebp)
	je	L370
	movl	-16(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	jmp	L371
L370:
	movl	$0, %eax
L371:
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	subl	12(%ebp), %eax
	subl	-20(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	cmpl	-24(%ebp), %eax
	ja	L372
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	-24(%ebp), %eax
	jae	L373
L372:
	movl	8(%ebp), %eax
	movl	16(%eax), %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, 12(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC70, (%esp)
	call	_printf
	movl	$0, %eax
	jmp	L374
L373:
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	subl	-20(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, 16(%eax)
	movl	-28(%ebp), %eax
L374:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE242:
	.section	.text$_ZN19CDualStackAllocator6allocDEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator6allocDEjj
	.def	__ZN19CDualStackAllocator6allocDEjj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator6allocDEjj:
LFB243:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE243:
	.section	.text$_ZN19CDualStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj
	.def	__ZN19CDualStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj:
LFB244:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L378
	movl	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator6allocDEjj
	jmp	L379
L378:
	cmpl	$-1, 12(%ebp)
	jne	L380
	movl	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator6allocREjj
	jmp	L379
L380:
	movl	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator6allocNEjj
L379:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE244:
	.section	.text$_ZN19CDualStackAllocator5allocEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5allocEjj
	.def	__ZN19CDualStackAllocator5allocEjj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5allocEjj:
LFB245:
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
	call	__ZN19CDualStackAllocator6allocDEjj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE245:
	.section	.text$_ZN19CDualStackAllocator5backNEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5backNEj
	.def	__ZN19CDualStackAllocator5backNEj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5backNEj:
LFB246:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	cmpl	12(%ebp), %eax
	jae	L386
	jmp	L385
L386:
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 12(%eax)
L385:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE246:
	.section	.text$_ZN19CDualStackAllocator5backNEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5backNEPKv
	.def	__ZN19CDualStackAllocator5backNEPKv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5backNEPKv:
LFB247:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backNEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE247:
	.section	.text$_ZN19CDualStackAllocator5backREj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5backREj
	.def	__ZN19CDualStackAllocator5backREj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5backREj:
LFB248:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	cmpl	12(%ebp), %eax
	ja	L390
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	12(%ebp), %eax
	jae	L391
L390:
	jmp	L389
L391:
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 16(%eax)
L389:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE248:
	.section	.text$_ZN19CDualStackAllocator5backREPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5backREPKv
	.def	__ZN19CDualStackAllocator5backREPKv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5backREPKv:
LFB249:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backREj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE249:
	.section	.text$_ZN19CDualStackAllocator5backDEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5backDEj
	.def	__ZN19CDualStackAllocator5backDEj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5backDEj:
LFB250:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator4backEN15IStackAllocator9E_ORDEREDEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE250:
	.section	.text$_ZN19CDualStackAllocator5backDEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5backDEPKv
	.def	__ZN19CDualStackAllocator5backDEPKv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5backDEPKv:
LFB251:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator4backEN15IStackAllocator9E_ORDEREDEPKv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE251:
	.section	.text$_ZN19CDualStackAllocator4backEN15IStackAllocator9E_ORDEREDEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator4backEN15IStackAllocator9E_ORDEREDEj
	.def	__ZN19CDualStackAllocator4backEN15IStackAllocator9E_ORDEREDEj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator4backEN15IStackAllocator9E_ORDEREDEj:
LFB252:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L397
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backDEj
	jmp	L396
L397:
	cmpl	$-1, 12(%ebp)
	jne	L399
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backREj
	jmp	L396
L399:
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backNEj
L396:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE252:
	.section	.text$_ZN19CDualStackAllocator4backEN15IStackAllocator9E_ORDEREDEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator4backEN15IStackAllocator9E_ORDEREDEPKv
	.def	__ZN19CDualStackAllocator4backEN15IStackAllocator9E_ORDEREDEPKv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator4backEN15IStackAllocator9E_ORDEREDEPKv:
LFB253:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L401
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backDEPKv
	jmp	L400
L401:
	cmpl	$-1, 12(%ebp)
	jne	L403
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backREPKv
	jmp	L400
L403:
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backNEPKv
L400:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE253:
	.section	.text$_ZN19CDualStackAllocator4backEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator4backEj
	.def	__ZN19CDualStackAllocator4backEj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator4backEj:
LFB254:
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
	call	__ZN19CDualStackAllocator5backDEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE254:
	.section	.text$_ZN19CDualStackAllocator4backEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator4backEPKv
	.def	__ZN19CDualStackAllocator4backEPKv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator4backEPKv:
LFB255:
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
	call	__ZN19CDualStackAllocator5backDEPKv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE255:
	.section	.text$_ZN19CDualStackAllocator6clearNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator6clearNEv
	.def	__ZN19CDualStackAllocator6clearNEv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator6clearNEv:
LFB256:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	$0, 12(%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE256:
	.section	.text$_ZN19CDualStackAllocator6clearREv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator6clearREv
	.def	__ZN19CDualStackAllocator6clearREv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator6clearREv:
LFB257:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 16(%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE257:
	.section	.text$_ZN19CDualStackAllocator6clearDEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator6clearDEv
	.def	__ZN19CDualStackAllocator6clearDEv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator6clearDEv:
LFB258:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5clearEN15IStackAllocator9E_ORDEREDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE258:
	.section	.text$_ZN19CDualStackAllocator7clearNREv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator7clearNREv
	.def	__ZN19CDualStackAllocator7clearNREv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator7clearNREv:
LFB259:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator6clearNEv
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator6clearREv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE259:
	.section	.text$_ZN19CDualStackAllocator5clearEN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5clearEN15IStackAllocator9E_ORDEREDE
	.def	__ZN19CDualStackAllocator5clearEN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5clearEN15IStackAllocator9E_ORDEREDE:
LFB260:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L411
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator6clearDEv
	jmp	L410
L411:
	cmpl	$-1, 12(%ebp)
	jne	L413
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator6clearREv
	jmp	L410
L413:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator6clearNEv
L410:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE260:
	.section	.text$_ZN19CDualStackAllocator5clearEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5clearEv
	.def	__ZN19CDualStackAllocator5clearEv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5clearEv:
LFB261:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator6clearDEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE261:
	.section	.text$_ZN19CDualStackAllocator8clearAllEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator8clearAllEv
	.def	__ZN19CDualStackAllocator8clearAllEv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator8clearAllEv:
LFB262:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator7clearNREv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE262:
	.section	.text$_ZN19CDualStackAllocatorC2EPvjN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocatorC2EPvjN15IStackAllocator9E_ORDEREDE
	.def	__ZN19CDualStackAllocatorC2EPvjN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocatorC2EPvjN15IStackAllocator9E_ORDEREDE:
LFB264:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15IStackAllocatorC2Ev
	movl	8(%ebp), %eax
	movl	$__ZTV19CDualStackAllocator+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	$0, 12(%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 16(%eax)
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE264:
	.section	.text$_ZN19CDualStackAllocatorD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocatorD2Ev
	.def	__ZN19CDualStackAllocatorD2Ev;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocatorD2Ev:
LFB267:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV19CDualStackAllocator+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15IStackAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L417
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L417:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE267:
	.section	.text$_ZN19CDualStackAllocatorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocatorD1Ev
	.def	__ZN19CDualStackAllocatorD1Ev;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocatorD1Ev:
LFB268:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV19CDualStackAllocator+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15IStackAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L420
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L420:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE268:
	.section	.text$_ZN19CDualStackAllocatorD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocatorD0Ev
	.def	__ZN19CDualStackAllocatorD0Ev;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocatorD0Ev:
LFB269:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocatorD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE269:
	.section .rdata,"dr"
	.align 4
LC71:
	.ascii "placement new(size=%d, dual_allocator.marker=%d,%d, align=%d, ordered=%d)\12\0"
	.text
	.globl	__ZnwjR19CDualStackAllocatorjN15IStackAllocator9E_ORDEREDE
	.def	__ZnwjR19CDualStackAllocatorjN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZnwjR19CDualStackAllocatorjN15IStackAllocator9E_ORDEREDE:
LFB270:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA270
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
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	20(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC71, (%esp)
LEHB77:
	call	_printf
	movl	16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj
LEHE77:
	jmp	L430
L429:
	cmpl	$-1, %edx
	je	L428
	movl	%eax, (%esp)
LEHB78:
	call	__Unwind_Resume
L428:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE78:
L430:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE270:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA270:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT270-LLSDATTD270
LLSDATTD270:
	.byte	0x1
	.uleb128 LLSDACSE270-LLSDACSB270
LLSDACSB270:
	.uleb128 LEHB77-LFB270
	.uleb128 LEHE77-LEHB77
	.uleb128 L429-LFB270
	.uleb128 0x1
	.uleb128 LEHB78-LFB270
	.uleb128 LEHE78-LEHB78
	.uleb128 0
	.uleb128 0
LLSDACSE270:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT270:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC72:
	.ascii "placement new(size=%d, dual_allocator.marker=%d,%d, (align=%d), ordered=%d)\12\0"
	.text
	.globl	__ZnwjR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE
	.def	__ZnwjR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZnwjR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE:
LFB271:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA271
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	$4, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	16(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	$4, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC72, (%esp)
LEHB79:
	call	_printf
	movl	$4, 12(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj
LEHE79:
	jmp	L436
L435:
	cmpl	$-1, %edx
	je	L434
	movl	%eax, (%esp)
LEHB80:
	call	__Unwind_Resume
L434:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE80:
L436:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE271:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA271:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT271-LLSDATTD271
LLSDATTD271:
	.byte	0x1
	.uleb128 LLSDACSE271-LLSDACSB271
LLSDACSB271:
	.uleb128 LEHB79-LFB271
	.uleb128 LEHE79-LEHB79
	.uleb128 L435-LFB271
	.uleb128 0x1
	.uleb128 LEHB80-LFB271
	.uleb128 LEHE80-LEHB80
	.uleb128 0
	.uleb128 0
LLSDACSE271:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT271:
	.byte	0
	.text
	.globl	__ZnajR19CDualStackAllocatorjN15IStackAllocator9E_ORDEREDE
	.def	__ZnajR19CDualStackAllocatorjN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZnajR19CDualStackAllocatorjN15IStackAllocator9E_ORDEREDE:
LFB272:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA272
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
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	20(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC71, (%esp)
LEHB81:
	call	_printf
	movl	16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj
LEHE81:
	jmp	L442
L441:
	cmpl	$-1, %edx
	je	L440
	movl	%eax, (%esp)
LEHB82:
	call	__Unwind_Resume
L440:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE82:
L442:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE272:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA272:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT272-LLSDATTD272
LLSDATTD272:
	.byte	0x1
	.uleb128 LLSDACSE272-LLSDACSB272
LLSDACSB272:
	.uleb128 LEHB81-LFB272
	.uleb128 LEHE81-LEHB81
	.uleb128 L441-LFB272
	.uleb128 0x1
	.uleb128 LEHB82-LFB272
	.uleb128 LEHE82-LEHB82
	.uleb128 0
	.uleb128 0
LLSDACSE272:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT272:
	.byte	0
	.text
	.globl	__ZnajR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE
	.def	__ZnajR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZnajR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE:
LFB273:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA273
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	$4, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	16(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	$4, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC72, (%esp)
LEHB83:
	call	_printf
	movl	$4, 12(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj
LEHE83:
	jmp	L448
L447:
	cmpl	$-1, %edx
	je	L446
	movl	%eax, (%esp)
LEHB84:
	call	__Unwind_Resume
L446:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE84:
L448:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE273:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA273:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT273-LLSDATTD273
LLSDATTD273:
	.byte	0x1
	.uleb128 LLSDACSE273-LLSDACSB273
LLSDACSB273:
	.uleb128 LEHB83-LFB273
	.uleb128 LEHE83-LEHB83
	.uleb128 L447-LFB273
	.uleb128 0x1
	.uleb128 LEHB84-LFB273
	.uleb128 LEHE84-LEHB84
	.uleb128 0
	.uleb128 0
LLSDACSE273:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT273:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC73:
	.ascii "placement delete(p=0x%p, dual_allocator.marker=%d,%d, align)\12\0"
	.text
	.globl	__ZdlPvR19CDualStackAllocatorjN15IStackAllocator9E_ORDEREDE
	.def	__ZdlPvR19CDualStackAllocatorjN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZdlPvR19CDualStackAllocatorjN15IStackAllocator9E_ORDEREDE:
LFB274:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA274
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
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC73, (%esp)
LEHB85:
	call	_printf
LEHE85:
	jmp	L453
L452:
	cmpl	$-1, %edx
	je	L451
	movl	%eax, (%esp)
LEHB86:
	call	__Unwind_Resume
L451:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE86:
L453:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE274:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA274:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT274-LLSDATTD274
LLSDATTD274:
	.byte	0x1
	.uleb128 LLSDACSE274-LLSDACSB274
LLSDACSB274:
	.uleb128 LEHB85-LFB274
	.uleb128 LEHE85-LEHB85
	.uleb128 L452-LFB274
	.uleb128 0x1
	.uleb128 LEHB86-LFB274
	.uleb128 LEHE86-LEHB86
	.uleb128 0
	.uleb128 0
LLSDACSE274:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT274:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC74:
	.ascii "placement delete(p=0x%p, dual_allocator.marker=%d,%d)\12\0"
	.text
	.globl	__ZdlPvR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE
	.def	__ZdlPvR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZdlPvR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE:
LFB275:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA275
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
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC74, (%esp)
LEHB87:
	call	_printf
LEHE87:
	jmp	L458
L457:
	cmpl	$-1, %edx
	je	L456
	movl	%eax, (%esp)
LEHB88:
	call	__Unwind_Resume
L456:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE88:
L458:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE275:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA275:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT275-LLSDATTD275
LLSDATTD275:
	.byte	0x1
	.uleb128 LLSDACSE275-LLSDACSB275
LLSDACSB275:
	.uleb128 LEHB87-LFB275
	.uleb128 LEHE87-LEHB87
	.uleb128 L457-LFB275
	.uleb128 0x1
	.uleb128 LEHB88-LFB275
	.uleb128 LEHE88-LEHB88
	.uleb128 0
	.uleb128 0
LLSDACSE275:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT275:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC75:
	.ascii "placement delete[](p=0x%p, dual_allocator.marker=%d,%d, align)\12\0"
	.text
	.globl	__ZdaPvR19CDualStackAllocatorjN15IStackAllocator9E_ORDEREDE
	.def	__ZdaPvR19CDualStackAllocatorjN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZdaPvR19CDualStackAllocatorjN15IStackAllocator9E_ORDEREDE:
LFB276:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA276
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
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC75, (%esp)
LEHB89:
	call	_printf
LEHE89:
	jmp	L463
L462:
	cmpl	$-1, %edx
	je	L461
	movl	%eax, (%esp)
LEHB90:
	call	__Unwind_Resume
L461:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE90:
L463:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE276:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA276:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT276-LLSDATTD276
LLSDATTD276:
	.byte	0x1
	.uleb128 LLSDACSE276-LLSDACSB276
LLSDACSB276:
	.uleb128 LEHB89-LFB276
	.uleb128 LEHE89-LEHB89
	.uleb128 L462-LFB276
	.uleb128 0x1
	.uleb128 LEHB90-LFB276
	.uleb128 LEHE90-LEHB90
	.uleb128 0
	.uleb128 0
LLSDACSE276:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT276:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC76:
	.ascii "placement delete[](p=0x%p, dual_allocator.marker=%d,%d)\12\0"
	.text
	.globl	__ZdaPvR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE
	.def	__ZdaPvR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZdaPvR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE:
LFB277:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA277
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	$4, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC76, (%esp)
LEHB91:
	call	_printf
LEHE91:
	jmp	L468
L467:
	cmpl	$-1, %edx
	je	L466
	movl	%eax, (%esp)
LEHB92:
	call	__Unwind_Resume
L466:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE92:
L468:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE277:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA277:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT277-LLSDATTD277
LLSDATTD277:
	.byte	0x1
	.uleb128 LLSDACSE277-LLSDACSB277
LLSDACSB277:
	.uleb128 LEHB91-LFB277
	.uleb128 LEHE91-LEHB91
	.uleb128 L467-LFB277
	.uleb128 0x1
	.uleb128 LEHB92-LFB277
	.uleb128 LEHE92-LEHB92
	.uleb128 0
	.uleb128 0
LLSDACSE277:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT277:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC77:
	.ascii "CTest4b::DefaultConstructor : name=\"%s\"\12\0"
	.section	.text$_ZN7CTest4bC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7CTest4bC1Ev
	.def	__ZN7CTest4bC1Ev;	.scl	2;	.type	32;	.endef
__ZN7CTest4bC1Ev:
LFB284:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA284
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	$LC10, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB93:
	call	__ZN7CTest4bC1EPKc
LEHE93:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC77, (%esp)
LEHB94:
	call	_printf
LEHE94:
	jmp	L472
L471:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN7CTest4bD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB95:
	call	__Unwind_Resume
LEHE95:
L472:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE284:
	.section	.gcc_except_table,"w"
LLSDA284:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE284-LLSDACSB284
LLSDACSB284:
	.uleb128 LEHB93-LFB284
	.uleb128 LEHE93-LEHB93
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB94-LFB284
	.uleb128 LEHE94-LEHB94
	.uleb128 L471-LFB284
	.uleb128 0
	.uleb128 LEHB95-LFB284
	.uleb128 LEHE95-LEHB95
	.uleb128 0
	.uleb128 0
LLSDACSE284:
	.section	.text$_ZN7CTest4bC1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC78:
	.ascii "CTest4b::Constructor : name=\"%s\"\12\0"
	.section	.text$_ZN7CTest4bC1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7CTest4bC1EPKc
	.def	__ZN7CTest4bC1EPKc;	.scl	2;	.type	32;	.endef
__ZN7CTest4bC1EPKc:
LFB287:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC78, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE287:
	.section .rdata,"dr"
	.align 4
LC79:
	.ascii "CTest4b::Destructor : name=\"%s\"\12\0"
	.section	.text$_ZN7CTest4bD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7CTest4bD1Ev
	.def	__ZN7CTest4bD1Ev;	.scl	2;	.type	32;	.endef
__ZN7CTest4bD1Ev:
LFB290:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA290
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC79, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE290:
	.section	.gcc_except_table,"w"
LLSDA290:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE290-LLSDACSB290
LLSDACSB290:
LLSDACSE290:
	.section	.text$_ZN7CTest4bD1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC80:
	.ascii "---------- test4a:\343\202\271\343\202\277\343\203\203\343\202\257\343\202\242\343\203\255\343\202\261\343\203\274\343\202\277 ----------\0"
LC81:
	.ascii "-----\0"
LC82:
	.ascii "i1=0x%p\12\0"
LC83:
	.ascii "c1=0x%p\12\0"
LC84:
	.ascii "marker=%d\12\0"
LC85:
	.ascii "f1=0x%p\12\0"
LC86:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "4a\0"
LC87:
	.ascii "obj1_p=0x%p\12\0"
LC88:
	.ascii "back(%d)\12\0"
LC89:
	.ascii "obj2_p=0x%p\12\0"
LC90:
	.ascii "i2=0x%p\12\0"
LC91:
	.ascii "f2=0x%p\12\0"
LC92:
	.ascii "c2=0x%p\12\0"
LC93:
	.ascii "over=0x%p\12\0"
	.text
	.globl	__Z6test4av
	.def	__Z6test4av;	.scl	2;	.type	32;	.endef
__Z6test4av:
LFB291:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA291
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$156, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	$LC80, (%esp)
LEHB96:
	call	_puts
LEHE96:
	leal	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EEC1Ev
	leal	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK15CStackAllocator7getBuffEv
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
LEHB97:
	call	_printf
LEHE97:
	movl	$LC81, (%esp)
LEHB98:
	call	_puts
	movl	$4, 8(%esp)
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZnajR15CStackAllocatorj
	movl	%eax, -40(%ebp)
	movl	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC82, (%esp)
	call	_printf
	movl	$1, 8(%esp)
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$13, (%esp)
	call	__ZnajR15CStackAllocatorj
	movl	%eax, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC83, (%esp)
	call	_printf
	movl	-148(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	leal	-148(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC84, (%esp)
	call	_printf
	movl	$4, 8(%esp)
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$16, (%esp)
	call	__ZnajR15CStackAllocatorj
	movl	%eax, -48(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC85, (%esp)
	call	_printf
LEHE98:
	movl	$4, 8(%esp)
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZnwjR15CStackAllocatorj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L477
	movl	$LC86, 4(%esp)
	movl	%ebx, (%esp)
LEHB99:
	call	__ZN7CTest4aC1EPKc
LEHE99:
	movl	%ebx, %eax
	jmp	L478
L477:
	movl	%ebx, %eax
L478:
	movl	%eax, -52(%ebp)
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC87, (%esp)
LEHB100:
	call	_printf
	leal	-148(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$4, 4(%esp)
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrIfEvRPT_jR15CStackAllocator
	leal	-148(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$15, 4(%esp)
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrIcEvRPT_jR15CStackAllocator
	leal	-148(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$2, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrIiEvRPT_jR15CStackAllocator
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrI7CTest4aEvRPT_R15CStackAllocator
	movl	-148(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	movl	-28(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-148(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC88, (%esp)
	call	_printf
LEHE100:
	movl	$LC81, (%esp)
LEHB101:
	call	_puts
	movl	-148(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	leal	-148(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC84, (%esp)
	call	_printf
LEHE101:
	movl	$4, 8(%esp)
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$28, (%esp)
	call	__ZnajR15CStackAllocatorj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L479
	movl	$3, (%ebx)
	leal	4(%ebx), %esi
	movl	$2, %edi
	movl	%esi, -156(%ebp)
	jmp	L480
L481:
	movl	-156(%ebp), %eax
	movl	%eax, (%esp)
LEHB102:
	call	__ZN7CTest4aC1Ev
LEHE102:
	addl	$8, -156(%ebp)
	subl	$1, %edi
L480:
	cmpl	$-1, %edi
	jne	L481
	leal	4(%ebx), %eax
	jmp	L482
L479:
	movl	%ebx, %eax
L482:
	movl	%eax, -56(%ebp)
	movl	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC89, (%esp)
LEHB103:
	call	_printf
	movl	$4, 8(%esp)
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZnwjR15CStackAllocatorj
	movl	%eax, -60(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC90, (%esp)
	call	_printf
	movl	$4, 8(%esp)
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZnwjR15CStackAllocatorj
	movl	%eax, -64(%ebp)
	movl	-64(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC91, (%esp)
	call	_printf
	movl	$1, 8(%esp)
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	call	__ZnwjR15CStackAllocatorj
	movl	%eax, -68(%ebp)
	movl	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC92, (%esp)
	call	_printf
	movl	$4, 8(%esp)
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$40, (%esp)
	call	__ZnajR15CStackAllocatorj
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC93, (%esp)
	call	_printf
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrIfEvRPT_R15CStackAllocator
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrIcEvRPT_R15CStackAllocator
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrIiEvRPT_R15CStackAllocator
	leal	-148(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$3, 4(%esp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrI7CTest4aEvRPT_jR15CStackAllocator
LEHE103:
	leal	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EED1Ev
	jmp	L497
L494:
	movl	%eax, %esi
	movl	$4, 8(%esp)
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvR15CStackAllocatorj
	movl	%esi, %eax
	jmp	L484
L493:
L484:
	movl	%eax, %ebx
	jmp	L485
L496:
	movl	%eax, -156(%ebp)
	testl	%esi, %esi
	je	L487
	movl	$2, %eax
	subl	%edi, %eax
	sall	$3, %eax
	leal	(%esi,%eax), %edi
L488:
	cmpl	%esi, %edi
	je	L487
	subl	$8, %edi
	movl	%edi, (%esp)
	call	__ZN7CTest4aD1Ev
	jmp	L488
L487:
	movl	-156(%ebp), %esi
	movl	$4, 8(%esp)
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdaPvR15CStackAllocatorj
	movl	%esi, %eax
	jmp	L489
L495:
L489:
	movl	%eax, %ebx
	jmp	L485
L492:
	movl	%eax, %ebx
L485:
	leal	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EED1Ev
	movl	%ebx, %eax
	jmp	L490
L491:
L490:
	movl	%eax, (%esp)
LEHB104:
	call	__Unwind_Resume
LEHE104:
L497:
	addl	$156, %esp
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
LFE291:
	.section	.gcc_except_table,"w"
LLSDA291:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE291-LLSDACSB291
LLSDACSB291:
	.uleb128 LEHB96-LFB291
	.uleb128 LEHE96-LEHB96
	.uleb128 L491-LFB291
	.uleb128 0
	.uleb128 LEHB97-LFB291
	.uleb128 LEHE97-LEHB97
	.uleb128 L492-LFB291
	.uleb128 0
	.uleb128 LEHB98-LFB291
	.uleb128 LEHE98-LEHB98
	.uleb128 L493-LFB291
	.uleb128 0
	.uleb128 LEHB99-LFB291
	.uleb128 LEHE99-LEHB99
	.uleb128 L494-LFB291
	.uleb128 0
	.uleb128 LEHB100-LFB291
	.uleb128 LEHE100-LEHB100
	.uleb128 L493-LFB291
	.uleb128 0
	.uleb128 LEHB101-LFB291
	.uleb128 LEHE101-LEHB101
	.uleb128 L495-LFB291
	.uleb128 0
	.uleb128 LEHB102-LFB291
	.uleb128 LEHE102-LEHB102
	.uleb128 L496-LFB291
	.uleb128 0
	.uleb128 LEHB103-LFB291
	.uleb128 LEHE103-LEHB103
	.uleb128 L495-LFB291
	.uleb128 0
	.uleb128 LEHB104-LFB291
	.uleb128 LEHE104-LEHB104
	.uleb128 0
	.uleb128 0
LLSDACSE291:
	.text
	.section .rdata,"dr"
	.align 4
LC94:
	.ascii "---------- test4b:\345\217\214\346\226\271\345\220\221\343\202\271\343\202\277\343\203\203\343\202\257\343\202\242\343\203\255\343\202\261\343\203\274\343\202\277 ----------\0"
LC95:
	.ascii "getDefaultOrdered()=%d\12\0"
	.align 4
LC96:
	.ascii "marker: default=%d, normal=%d, reverse=%d\12\0"
LC97:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "4b\0"
LC98:
	.ascii "backN(%d)\12\0"
LC99:
	.ascii "backR(%d)\12\0"
LC100:
	.ascii "over1=0x%p\12\0"
LC101:
	.ascii "over2=0x%p\12\0"
	.text
	.globl	__Z6test4bv
	.def	__Z6test4bv;	.scl	2;	.type	32;	.endef
__Z6test4bv:
LFB292:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA292
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$204, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	$LC94, (%esp)
LEHB105:
	call	_puts
LEHE105:
	movl	$1, 4(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EEC1EN15IStackAllocator9E_ORDEREDE
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator7getBuffEv
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
LEHB106:
	call	_printf
LEHE106:
	movl	$LC81, (%esp)
LEHB107:
	call	_puts
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator17getDefaultOrderedEv
	movl	%eax, 4(%esp)
	movl	$LC95, (%esp)
	call	_printf
	movl	$0, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZnajR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE
	movl	%eax, -60(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC82, (%esp)
	call	_printf
	movl	$-1, 12(%esp)
	movl	$1, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$13, (%esp)
	call	__ZnajR19CDualStackAllocatorjN15IStackAllocator9E_ORDEREDE
	movl	%eax, -64(%ebp)
	movl	-64(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC83, (%esp)
	call	_printf
	movl	-176(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	leal	-176(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, -28(%ebp)
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	%eax, -32(%ebp)
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC96, (%esp)
	call	_printf
	movl	$0, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$16, (%esp)
	call	__ZnajR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE
	movl	%eax, -68(%ebp)
	movl	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC85, (%esp)
	call	_printf
LEHE107:
	movl	$-1, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZnwjR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L499
	movl	$LC97, 4(%esp)
	movl	%ebx, (%esp)
LEHB108:
	call	__ZN7CTest4bC1EPKc
LEHE108:
	movl	%ebx, %eax
	jmp	L500
L499:
	movl	%ebx, %eax
L500:
	movl	%eax, -72(%ebp)
	movl	-72(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC87, (%esp)
LEHB109:
	call	_printf
	leal	-176(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$4, 4(%esp)
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrIfEvRPT_jR19CDualStackAllocator
	leal	-176(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$15, 4(%esp)
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrIcEvRPT_jR19CDualStackAllocator
	leal	-176(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$2, 4(%esp)
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrIiEvRPT_jR19CDualStackAllocator
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrI7CTest4bEvRPT_R19CDualStackAllocator
	movl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backNEj
	movl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC98, (%esp)
	call	_printf
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backREj
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC99, (%esp)
	call	_printf
LEHE109:
	movl	$LC81, (%esp)
LEHB110:
	call	_puts
	movl	$-1, 4(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator17getDefaultOrderedEv
	movl	%eax, 4(%esp)
	movl	$LC95, (%esp)
	call	_printf
	movl	-176(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	leal	-176(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, -40(%ebp)
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	%eax, -44(%ebp)
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, -48(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC96, (%esp)
	call	_printf
LEHE110:
	movl	$1, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$28, (%esp)
	call	__ZnajR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L501
	movl	$3, (%ebx)
	leal	4(%ebx), %esi
	movl	$2, %edi
	movl	%esi, -188(%ebp)
	jmp	L502
L503:
	movl	-188(%ebp), %eax
	movl	%eax, (%esp)
LEHB111:
	call	__ZN7CTest4bC1Ev
LEHE111:
	addl	$8, -188(%ebp)
	subl	$1, %edi
L502:
	cmpl	$-1, %edi
	jne	L503
	leal	4(%ebx), %eax
	jmp	L504
L501:
	movl	%ebx, %eax
L504:
	movl	%eax, -76(%ebp)
	movl	-76(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC89, (%esp)
LEHB112:
	call	_printf
	movl	$0, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZnwjR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE
	movl	%eax, -80(%ebp)
	movl	-80(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC90, (%esp)
	call	_printf
	movl	$1, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZnwjR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE
	movl	%eax, -84(%ebp)
	movl	-84(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC91, (%esp)
	call	_printf
	movl	$0, 12(%esp)
	movl	$1, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	call	__ZnwjR19CDualStackAllocatorjN15IStackAllocator9E_ORDEREDE
	movl	%eax, -88(%ebp)
	movl	-88(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC92, (%esp)
	call	_printf
	movl	$1, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$40, (%esp)
	call	__ZnajR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE
	movl	%eax, -52(%ebp)
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC100, (%esp)
	call	_printf
	movl	$0, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$40, (%esp)
	call	__ZnajR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE
	movl	%eax, -56(%ebp)
	movl	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC101, (%esp)
	call	_printf
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrIfEvRPT_R19CDualStackAllocator
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrIcEvRPT_R19CDualStackAllocator
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrIiEvRPT_R19CDualStackAllocator
	leal	-176(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$3, 4(%esp)
	leal	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrI7CTest4bEvRPT_jR19CDualStackAllocator
LEHE112:
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev
	jmp	L519
L516:
	movl	%eax, %esi
	movl	$-1, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE
	movl	%esi, %eax
	jmp	L506
L515:
L506:
	movl	%eax, %ebx
	jmp	L507
L518:
	movl	%eax, -188(%ebp)
	testl	%esi, %esi
	je	L509
	movl	$2, %eax
	subl	%edi, %eax
	sall	$3, %eax
	leal	(%esi,%eax), %edi
L510:
	cmpl	%esi, %edi
	je	L509
	subl	$8, %edi
	movl	%edi, (%esp)
	call	__ZN7CTest4bD1Ev
	jmp	L510
L509:
	movl	-188(%ebp), %esi
	movl	$1, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdaPvR19CDualStackAllocatorN15IStackAllocator9E_ORDEREDE
	movl	%esi, %eax
	jmp	L511
L517:
L511:
	movl	%eax, %ebx
	jmp	L507
L514:
	movl	%eax, %ebx
L507:
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev
	movl	%ebx, %eax
	jmp	L512
L513:
L512:
	movl	%eax, (%esp)
LEHB113:
	call	__Unwind_Resume
LEHE113:
L519:
	addl	$204, %esp
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
LFE292:
	.section	.gcc_except_table,"w"
LLSDA292:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE292-LLSDACSB292
LLSDACSB292:
	.uleb128 LEHB105-LFB292
	.uleb128 LEHE105-LEHB105
	.uleb128 L513-LFB292
	.uleb128 0
	.uleb128 LEHB106-LFB292
	.uleb128 LEHE106-LEHB106
	.uleb128 L514-LFB292
	.uleb128 0
	.uleb128 LEHB107-LFB292
	.uleb128 LEHE107-LEHB107
	.uleb128 L515-LFB292
	.uleb128 0
	.uleb128 LEHB108-LFB292
	.uleb128 LEHE108-LEHB108
	.uleb128 L516-LFB292
	.uleb128 0
	.uleb128 LEHB109-LFB292
	.uleb128 LEHE109-LEHB109
	.uleb128 L515-LFB292
	.uleb128 0
	.uleb128 LEHB110-LFB292
	.uleb128 LEHE110-LEHB110
	.uleb128 L517-LFB292
	.uleb128 0
	.uleb128 LEHB111-LFB292
	.uleb128 LEHE111-LEHB111
	.uleb128 L518-LFB292
	.uleb128 0
	.uleb128 LEHB112-LFB292
	.uleb128 LEHE112-LEHB112
	.uleb128 L517-LFB292
	.uleb128 0
	.uleb128 LEHB113-LFB292
	.uleb128 LEHE113-LEHB113
	.uleb128 0
	.uleb128 0
LLSDACSE292:
	.text
	.section	.text$_ZStanSt12memory_orderSt23__memory_order_modifier,"x"
	.linkonce discard
	.globl	__ZStanSt12memory_orderSt23__memory_order_modifier
	.def	__ZStanSt12memory_orderSt23__memory_order_modifier;	.scl	2;	.type	32;	.endef
__ZStanSt12memory_orderSt23__memory_order_modifier:
LFB294:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	andl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE294:
	.section	.text$_ZNSt11atomic_flag12test_and_setESt12memory_order,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11atomic_flag12test_and_setESt12memory_order
	.def	__ZNSt11atomic_flag12test_and_setESt12memory_order;	.scl	2;	.type	32;	.endef
__ZNSt11atomic_flag12test_and_setESt12memory_order:
LFB303:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	$1, %edx
	xchgb	(%eax), %dl
	movl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE303:
	.section	.text$_ZNSt11atomic_flag5clearESt12memory_order,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11atomic_flag5clearESt12memory_order
	.def	__ZNSt11atomic_flag5clearESt12memory_order;	.scl	2;	.type	32;	.endef
__ZNSt11atomic_flag5clearESt12memory_order:
LFB305:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZStanSt12memory_orderSt23__memory_order_modifier
	movl	%eax, -4(%ebp)
	movl	8(%ebp), %eax
	movl	$0, %edx
	xchgb	(%eax), %dl
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE305:
	.section	.text$_ZNK14CPoolAllocator7getBuffEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK14CPoolAllocator7getBuffEv
	.def	__ZNK14CPoolAllocator7getBuffEv;	.scl	2;	.type	32;	.endef
__ZNK14CPoolAllocator7getBuffEv:
LFB619:
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
LFE619:
	.section	.text$_ZNK14CPoolAllocator12getBlockSizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK14CPoolAllocator12getBlockSizeEv
	.def	__ZNK14CPoolAllocator12getBlockSizeEv;	.scl	2;	.type	32;	.endef
__ZNK14CPoolAllocator12getBlockSizeEv:
LFB620:
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
LFE620:
	.section	.text$_ZNK14CPoolAllocator12getBlocksNumEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK14CPoolAllocator12getBlocksNumEv
	.def	__ZNK14CPoolAllocator12getBlocksNumEv;	.scl	2;	.type	32;	.endef
__ZNK14CPoolAllocator12getBlocksNumEv:
LFB621:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE621:
	.section	.text$_ZNK14CPoolAllocator7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK14CPoolAllocator7getUsedEv
	.def	__ZNK14CPoolAllocator7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK14CPoolAllocator7getUsedEv:
LFB622:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIiE4loadESt12memory_order
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE622:
	.section	.text$_ZNK14CPoolAllocator9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK14CPoolAllocator9getRemainEv
	.def	__ZNK14CPoolAllocator9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK14CPoolAllocator9getRemainEv:
LFB623:
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
	movl	8(%eax), %ebx
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIiE4loadESt12memory_order
	subl	%eax, %ebx
	movl	%ebx, %eax
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE623:
	.section	.text$_ZN14CPoolAllocator8getBlockEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator8getBlockEi
	.def	__ZN14CPoolAllocator8getBlockEi;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator8getBlockEi:
LFB625:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %ecx
	movl	12(%ebp), %eax
	imull	%ecx, %eax
	addl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE625:
	.section	.text$_ZN14CPoolAllocator5resetEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator5resetEv
	.def	__ZN14CPoolAllocator5resetEv;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator5resetEv:
LFB626:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE5storeEiSt12memory_order
	movl	8(%ebp), %eax
	movl	$0, 16(%eax)
	movl	8(%ebp), %eax
	movl	$2147483647, 20(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE626:
	.section	.text$_ZN14CPoolAllocator6assignEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6assignEv
	.def	__ZN14CPoolAllocator6assignEv;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6assignEv:
LFB627:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIiE4loadESt12memory_order
	movl	8(%ebp), %edx
	movl	8(%edx), %edx
	cmpl	%edx, %eax
	setge	%al
	testb	%al, %al
	je	L539
	movl	$2147483647, %eax
	jmp	L540
L539:
	movl	$2147483647, -12(%ebp)
	movl	8(%ebp), %eax
	movl	16(%eax), %edx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	jge	L541
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	leal	1(%eax), %ecx
	movl	8(%ebp), %edx
	movl	%ecx, 16(%edx)
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE9fetch_addEiSt12memory_order
	jmp	L542
L541:
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	cmpl	$2147483647, %eax
	je	L542
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator8getBlockEi
	movl	(%eax), %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, 20(%eax)
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE9fetch_addEiSt12memory_order
L542:
	movl	-12(%ebp), %eax
L540:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE627:
	.section	.text$_ZN14CPoolAllocator7releaseEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7releaseEi
	.def	__ZN14CPoolAllocator7releaseEi;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7releaseEi:
LFB628:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	js	L544
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	12(%ebp), %eax
	jg	L545
L544:
	jmp	L543
L545:
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator8getBlockEi
	movl	8(%ebp), %edx
	movl	20(%edx), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 20(%eax)
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE9fetch_subEiSt12memory_order
L543:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE628:
	.section	.text$_ZN14CPoolAllocator5allocEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator5allocEj
	.def	__ZN14CPoolAllocator5allocEj;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator5allocEj:
LFB629:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	12(%ebp), %eax
	jae	L548
	movl	$0, %eax
	jmp	L549
L548:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator6assignEv
	movl	%eax, -12(%ebp)
	cmpl	$2147483647, -12(%ebp)
	je	L550
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator8getBlockEi
	jmp	L551
L550:
	movl	$0, %eax
L551:
L549:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE629:
	.section	.text$_ZN14CPoolAllocator4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator4freeEPv
	.def	__ZN14CPoolAllocator4freeEPv;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator4freeEPv:
LFB630:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	cmpl	$0, 12(%ebp)
	jne	L553
	jmp	L552
L553:
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	4(%edx), %ecx
	movl	$0, %edx
	divl	%ecx
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator7releaseEi
L552:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE630:
	.section	.text$_ZNSt13__atomic_baseIiEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13__atomic_baseIiEC2Ev
	.def	__ZNSt13__atomic_baseIiEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt13__atomic_baseIiEC2Ev:
LFB636:
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
LFE636:
	.section	.text$_ZNSt6atomicIiEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6atomicIiEC1Ev
	.def	__ZNSt6atomicIiEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6atomicIiEC1Ev:
LFB639:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiEC2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE639:
	.section	.text$_ZN14CPoolAllocatorC2EPvji,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocatorC2EPvji
	.def	__ZN14CPoolAllocatorC2EPvji;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocatorC2EPvji:
LFB640:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	20(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__ZNSt6atomicIiEC1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator5resetEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE640:
	.section	.text$_ZN14CPoolAllocatorD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocatorD2Ev
	.def	__ZN14CPoolAllocatorD2Ev;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocatorD2Ev:
LFB643:
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
LFE643:
	.section .rdata,"dr"
	.align 4
LC102:
	.ascii "placement new(size=%d, pool_allocator.used=%d/%d/%d)\12\0"
	.text
	.globl	__ZnwjR14CPoolAllocator
	.def	__ZnwjR14CPoolAllocator;	.scl	2;	.type	32;	.endef
__ZnwjR14CPoolAllocator:
LFB645:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA645
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
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK14CPoolAllocator9getRemainEv
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK14CPoolAllocator7getUsedEv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK14CPoolAllocator12getBlocksNumEv
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC102, (%esp)
LEHB114:
	call	_printf
LEHE114:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator5allocEj
	jmp	L565
L564:
	cmpl	$-1, %edx
	je	L563
	movl	%eax, (%esp)
LEHB115:
	call	__Unwind_Resume
L563:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE115:
L565:
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
LFE645:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA645:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT645-LLSDATTD645
LLSDATTD645:
	.byte	0x1
	.uleb128 LLSDACSE645-LLSDACSB645
LLSDACSB645:
	.uleb128 LEHB114-LFB645
	.uleb128 LEHE114-LEHB114
	.uleb128 L564-LFB645
	.uleb128 0x1
	.uleb128 LEHB115-LFB645
	.uleb128 LEHE115-LEHB115
	.uleb128 0
	.uleb128 0
LLSDACSE645:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT645:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC103:
	.ascii "placement delete(p=0x%p, pool_allocator.used=%d/%d/%d)\12\0"
	.text
	.globl	__ZdlPvR14CPoolAllocator
	.def	__ZdlPvR14CPoolAllocator;	.scl	2;	.type	32;	.endef
__ZdlPvR14CPoolAllocator:
LFB646:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA646
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
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK14CPoolAllocator9getRemainEv
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK14CPoolAllocator7getUsedEv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK14CPoolAllocator12getBlocksNumEv
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC103, (%esp)
LEHB116:
	call	_printf
LEHE116:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator4freeEPv
	jmp	L570
L569:
	cmpl	$-1, %edx
	je	L568
	movl	%eax, (%esp)
LEHB117:
	call	__Unwind_Resume
L568:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE117:
L570:
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
LFE646:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA646:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT646-LLSDATTD646
LLSDATTD646:
	.byte	0x1
	.uleb128 LLSDACSE646-LLSDACSB646
LLSDACSB646:
	.uleb128 LEHB116-LFB646
	.uleb128 LEHE116-LEHB116
	.uleb128 L569-LFB646
	.uleb128 0x1
	.uleb128 LEHB117-LFB646
	.uleb128 LEHE117-LEHB117
	.uleb128 0
	.uleb128 0
LLSDACSE646:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT646:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC104:
	.ascii "CTest5::Constructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest5C1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest5C1EPKc
	.def	__ZN6CTest5C1EPKc;	.scl	2;	.type	32;	.endef
__ZN6CTest5C1EPKc:
LFB658:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC104, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE658:
	.section .rdata,"dr"
	.align 4
LC105:
	.ascii "CTest5::Destructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest5D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest5D1Ev
	.def	__ZN6CTest5D1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest5D1Ev:
LFB661:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA661
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC105, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE661:
	.section	.gcc_except_table,"w"
LLSDA661:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE661-LLSDACSB661
LLSDACSB661:
LLSDACSE661:
	.section	.text$_ZN6CTest5D1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC106:
	.ascii "---------- test5:\343\203\227\343\203\274\343\203\253\343\202\242\343\203\255\343\202\261\343\203\274\343\202\277 ----------\0"
LC107:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "5-1\0"
LC108:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "5-2\0"
LC109:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "5-3\0"
LC110:
	.ascii "obj3_p=0x%p\12\0"
LC111:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "5-4\0"
LC112:
	.ascii "obj4_p=0x%p\12\0"
LC113:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "5-5\0"
LC114:
	.ascii "obj5_p=0x%p\12\0"
LC115:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "5-6\0"
LC116:
	.ascii "obj6_p=0x%p\12\0"
LC117:
	.ascii "obj_l_p=0x%p\12\0"
LC118:
	.ascii "c_p=0x%p\12\0"
LC119:
	.ascii "s_p=0x%p\12\0"
LC120:
	.ascii "i_p=0x%p\12\0"
LC121:
	.ascii "f_p=0x%p\12\0"
LC122:
	.ascii "d_p=0x%p\12\0"
LC123:
	.ascii "ll_p=0x%p\12\0"
	.text
	.globl	__Z5test5v
	.def	__Z5test5v;	.scl	2;	.type	32;	.endef
__Z5test5v:
LFB662:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA662
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$148, %esp
	.cfi_offset 3, -12
	movl	$LC106, (%esp)
LEHB118:
	call	_puts
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EEC1Ev
LEHE118:
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK14CPoolAllocator7getBuffEv
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
LEHB119:
	call	_printf
LEHE119:
	movl	$LC81, (%esp)
LEHB120:
	call	_puts
	movl	$LC107, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC87, (%esp)
	call	_printf
	movl	$LC108, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC89, (%esp)
	call	_printf
	movl	$LC109, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC110, (%esp)
	call	_printf
	movl	$LC111, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC112, (%esp)
	call	_printf
	movl	$LC113, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC114, (%esp)
	call	_printf
	movl	$LC115, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC116, (%esp)
	call	_printf
	leal	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE11destroyDataERPS0_
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE11destroyDataERPS0_
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE11destroyDataERPS0_
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE11destroyDataERPS0_
	leal	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE11destroyDataERPS0_
	leal	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE11destroyDataERPS0_
LEHE120:
	movl	$LC81, (%esp)
LEHB121:
	call	_puts
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator6createI7CTest5LIEEEPT_DpT0_
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC117, (%esp)
	call	_printf
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator6createIcIEEEPT_DpT0_
	movl	%eax, -40(%ebp)
	movl	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC118, (%esp)
	call	_printf
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator6createIsIEEEPT_DpT0_
	movl	%eax, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC119, (%esp)
	call	_printf
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator6createIiIEEEPT_DpT0_
	movl	%eax, -48(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC120, (%esp)
	call	_printf
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator6createIfIEEEPT_DpT0_
	movl	%eax, -52(%ebp)
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC121, (%esp)
	call	_printf
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator6createIdIEEEPT_DpT0_
	movl	%eax, -56(%ebp)
	movl	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC122, (%esp)
	call	_printf
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator6createIxIEEEPT_DpT0_
	movl	%eax, -60(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC123, (%esp)
	call	_printf
LEHE121:
	leal	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator7destroyI7CTest5LEEvRPT_
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator7destroyIcEEvRPT_
	leal	-44(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator7destroyIsEEvRPT_
	leal	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator7destroyIiEEvRPT_
	leal	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator7destroyIfEEvRPT_
	leal	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator7destroyIdEEvRPT_
	leal	-60(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator7destroyIxEEvRPT_
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EED1Ev
	jmp	L583
L581:
	movl	%eax, %ebx
	jmp	L576
L582:
	movl	%eax, %ebx
	jmp	L576
L580:
	movl	%eax, %ebx
L576:
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EED1Ev
	movl	%ebx, %eax
	jmp	L578
L579:
L578:
	movl	%eax, (%esp)
LEHB122:
	call	__Unwind_Resume
LEHE122:
L583:
	addl	$148, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE662:
	.section	.gcc_except_table,"w"
LLSDA662:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE662-LLSDACSB662
LLSDACSB662:
	.uleb128 LEHB118-LFB662
	.uleb128 LEHE118-LEHB118
	.uleb128 L579-LFB662
	.uleb128 0
	.uleb128 LEHB119-LFB662
	.uleb128 LEHE119-LEHB119
	.uleb128 L580-LFB662
	.uleb128 0
	.uleb128 LEHB120-LFB662
	.uleb128 LEHE120-LEHB120
	.uleb128 L581-LFB662
	.uleb128 0
	.uleb128 LEHB121-LFB662
	.uleb128 LEHE121-LEHB121
	.uleb128 L582-LFB662
	.uleb128 0
	.uleb128 LEHB122-LFB662
	.uleb128 LEHE122-LEHB122
	.uleb128 0
	.uleb128 0
LLSDACSE662:
	.text
	.section	.text$_ZN10IAllocatorD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10IAllocatorD2Ev
	.def	__ZN10IAllocatorD2Ev;	.scl	2;	.type	32;	.endef
__ZN10IAllocatorD2Ev:
LFB664:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV10IAllocator+8, (%eax)
	movl	$0, %eax
	testl	%eax, %eax
	je	L584
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L584:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE664:
	.section	.text$_ZN10IAllocatorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10IAllocatorD1Ev
	.def	__ZN10IAllocatorD1Ev;	.scl	2;	.type	32;	.endef
__ZN10IAllocatorD1Ev:
LFB665:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV10IAllocator+8, (%eax)
	movl	$0, %eax
	testl	%eax, %eax
	je	L587
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L587:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE665:
	.section	.text$_ZN10IAllocatorD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10IAllocatorD0Ev
	.def	__ZN10IAllocatorD0Ev;	.scl	2;	.type	32;	.endef
__ZN10IAllocatorD0Ev:
LFB666:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10IAllocatorD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE666:
	.section .rdata,"dr"
LC124:
	.ascii "CStdAllocAdp\0"
	.section	.text$_ZNK12CStdAllocAdp7getNameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK12CStdAllocAdp7getNameEv
	.def	__ZNK12CStdAllocAdp7getNameEv;	.scl	2;	.type	32;	.endef
__ZNK12CStdAllocAdp7getNameEv:
LFB667:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$LC124, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE667:
	.section	.text$_ZNK12CStdAllocAdp8getTotalEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK12CStdAllocAdp8getTotalEv
	.def	__ZNK12CStdAllocAdp8getTotalEv;	.scl	2;	.type	32;	.endef
__ZNK12CStdAllocAdp8getTotalEv:
LFB668:
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
LFE668:
	.section	.text$_ZNK12CStdAllocAdp7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK12CStdAllocAdp7getUsedEv
	.def	__ZNK12CStdAllocAdp7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK12CStdAllocAdp7getUsedEv:
LFB669:
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
LFE669:
	.section	.text$_ZNK12CStdAllocAdp9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK12CStdAllocAdp9getRemainEv
	.def	__ZNK12CStdAllocAdp9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK12CStdAllocAdp9getRemainEv:
LFB670:
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
LFE670:
	.section	.text$_ZN12CStdAllocAdpnwEj,"x"
	.linkonce discard
	.globl	__ZN12CStdAllocAdpnwEj
	.def	__ZN12CStdAllocAdpnwEj;	.scl	2;	.type	32;	.endef
__ZN12CStdAllocAdpnwEj:
LFB671:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$__ZN12CStdAllocAdp6m_buffE, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE671:
	.section	.text$_ZN12CStdAllocAdpdlEPv,"x"
	.linkonce discard
	.globl	__ZN12CStdAllocAdpdlEPv
	.def	__ZN12CStdAllocAdpdlEPv;	.scl	2;	.type	32;	.endef
__ZN12CStdAllocAdpdlEPv:
LFB672:
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
LFE672:
	.section	.text$_ZN12CStdAllocAdp5allocEjjPK10ALLOC_INFO,"x"
	.linkonce discard
	.align 2
	.globl	__ZN12CStdAllocAdp5allocEjjPK10ALLOC_INFO
	.def	__ZN12CStdAllocAdp5allocEjjPK10ALLOC_INFO;	.scl	2;	.type	32;	.endef
__ZN12CStdAllocAdp5allocEjjPK10ALLOC_INFO:
LFB673:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_memalign
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE673:
	.section	.text$_ZN12CStdAllocAdp4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN12CStdAllocAdp4freeEPv
	.def	__ZN12CStdAllocAdp4freeEPv;	.scl	2;	.type	32;	.endef
__ZN12CStdAllocAdp4freeEPv:
LFB674:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L606
	jmp	L605
L606:
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
L605:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE674:
	.section	.text$_ZN10IAllocatorC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10IAllocatorC2Ev
	.def	__ZN10IAllocatorC2Ev;	.scl	2;	.type	32;	.endef
__ZN10IAllocatorC2Ev:
LFB677:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	$__ZTV10IAllocator+8, (%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE677:
	.section	.text$_ZN12CStdAllocAdpC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN12CStdAllocAdpC1Ev
	.def	__ZN12CStdAllocAdpC1Ev;	.scl	2;	.type	32;	.endef
__ZN12CStdAllocAdpC1Ev:
LFB680:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10IAllocatorC2Ev
	movl	8(%ebp), %eax
	movl	$__ZTV12CStdAllocAdp+8, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE680:
	.section	.text$_ZN12CStdAllocAdpD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN12CStdAllocAdpD1Ev
	.def	__ZN12CStdAllocAdpD1Ev;	.scl	2;	.type	32;	.endef
__ZN12CStdAllocAdpD1Ev:
LFB683:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV12CStdAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10IAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L610
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN12CStdAllocAdpdlEPv
L610:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE683:
	.section	.text$_ZN12CStdAllocAdpD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN12CStdAllocAdpD0Ev
	.def	__ZN12CStdAllocAdpD0Ev;	.scl	2;	.type	32;	.endef
__ZN12CStdAllocAdpD0Ev:
LFB684:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN12CStdAllocAdpD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN12CStdAllocAdpdlEPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE684:
	.globl	__ZN12CStdAllocAdp6m_buffE
	.bss
__ZN12CStdAllocAdp6m_buffE:
	.space 4
	.section .rdata,"dr"
LC125:
	.ascii "CMonoAllocAdp\0"
	.section	.text$_ZNK13CMonoAllocAdp7getNameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK13CMonoAllocAdp7getNameEv
	.def	__ZNK13CMonoAllocAdp7getNameEv;	.scl	2;	.type	32;	.endef
__ZNK13CMonoAllocAdp7getNameEv:
LFB685:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$LC125, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE685:
	.section	.text$_ZNK13CMonoAllocAdp8getTotalEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK13CMonoAllocAdp8getTotalEv
	.def	__ZNK13CMonoAllocAdp8getTotalEv;	.scl	2;	.type	32;	.endef
__ZNK13CMonoAllocAdp8getTotalEv:
LFB686:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE686:
	.section	.text$_ZNK13CMonoAllocAdp7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK13CMonoAllocAdp7getUsedEv
	.def	__ZNK13CMonoAllocAdp7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK13CMonoAllocAdp7getUsedEv:
LFB687:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	12(%eax), %eax
	testb	%al, %al
	je	L620
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	jmp	L621
L620:
	movl	$0, %eax
L621:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE687:
	.section	.text$_ZNK13CMonoAllocAdp9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK13CMonoAllocAdp9getRemainEv
	.def	__ZNK13CMonoAllocAdp9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK13CMonoAllocAdp9getRemainEv:
LFB688:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	12(%eax), %eax
	testb	%al, %al
	je	L624
	movl	$0, %eax
	jmp	L625
L624:
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
L625:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE688:
	.section	.text$_ZN13CMonoAllocAdp5allocEjjPK10ALLOC_INFO,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CMonoAllocAdp5allocEjjPK10ALLOC_INFO
	.def	__ZN13CMonoAllocAdp5allocEjjPK10ALLOC_INFO;	.scl	2;	.type	32;	.endef
__ZN13CMonoAllocAdp5allocEjjPK10ALLOC_INFO:
LFB692:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	12(%eax), %eax
	testb	%al, %al
	je	L628
	movl	$0, %eax
	jmp	L629
L628:
	movl	8(%ebp), %eax
	movb	$1, 12(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
L629:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE692:
	.section	.text$_ZN13CMonoAllocAdp4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CMonoAllocAdp4freeEPv
	.def	__ZN13CMonoAllocAdp4freeEPv;	.scl	2;	.type	32;	.endef
__ZN13CMonoAllocAdp4freeEPv:
LFB693:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	cmpl	$0, 12(%ebp)
	jne	L631
	jmp	L630
L631:
	movl	8(%ebp), %eax
	movzbl	12(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L633
	jmp	L630
L633:
	movl	8(%ebp), %eax
	movb	$0, 12(%eax)
L630:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE693:
	.section	.text$_ZN13CMonoAllocAdpC2EPvj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CMonoAllocAdpC2EPvj
	.def	__ZN13CMonoAllocAdpC2EPvj;	.scl	2;	.type	32;	.endef
__ZN13CMonoAllocAdpC2EPvj:
LFB695:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10IAllocatorC2Ev
	movl	8(%ebp), %eax
	movl	$__ZTV13CMonoAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movb	$0, 12(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE695:
	.section	.text$_ZN13CMonoAllocAdpD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CMonoAllocAdpD2Ev
	.def	__ZN13CMonoAllocAdpD2Ev;	.scl	2;	.type	32;	.endef
__ZN13CMonoAllocAdpD2Ev:
LFB698:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV13CMonoAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10IAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L635
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L635:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE698:
	.section	.text$_ZN13CMonoAllocAdpD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CMonoAllocAdpD1Ev
	.def	__ZN13CMonoAllocAdpD1Ev;	.scl	2;	.type	32;	.endef
__ZN13CMonoAllocAdpD1Ev:
LFB699:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV13CMonoAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10IAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L638
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L638:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE699:
	.section	.text$_ZN13CMonoAllocAdpD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CMonoAllocAdpD0Ev
	.def	__ZN13CMonoAllocAdpD0Ev;	.scl	2;	.type	32;	.endef
__ZN13CMonoAllocAdpD0Ev:
LFB700:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CMonoAllocAdpD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE700:
	.section .rdata,"dr"
LC126:
	.ascii "CIStackAllocAdp\0"
	.section	.text$_ZNK15CIStackAllocAdp7getNameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CIStackAllocAdp7getNameEv
	.def	__ZNK15CIStackAllocAdp7getNameEv;	.scl	2;	.type	32;	.endef
__ZNK15CIStackAllocAdp7getNameEv:
LFB703:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$LC126, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE703:
	.section	.text$_ZNK15CIStackAllocAdp8getTotalEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CIStackAllocAdp8getTotalEv
	.def	__ZNK15CIStackAllocAdp8getTotalEv;	.scl	2;	.type	32;	.endef
__ZNK15CIStackAllocAdp8getTotalEv:
LFB704:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	4(%edx), %edx
	movl	%edx, (%esp)
	call	*%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE704:
	.section	.text$_ZNK15CIStackAllocAdp7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CIStackAllocAdp7getUsedEv
	.def	__ZNK15CIStackAllocAdp7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK15CIStackAllocAdp7getUsedEv:
LFB705:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	4(%edx), %edx
	movl	%edx, (%esp)
	call	*%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE705:
	.section	.text$_ZNK15CIStackAllocAdp9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CIStackAllocAdp9getRemainEv
	.def	__ZNK15CIStackAllocAdp9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK15CIStackAllocAdp9getRemainEv:
LFB706:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	4(%edx), %edx
	movl	%edx, (%esp)
	call	*%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE706:
	.section	.text$_ZN15CIStackAllocAdp5allocEjjPK10ALLOC_INFO,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CIStackAllocAdp5allocEjjPK10ALLOC_INFO
	.def	__ZN15CIStackAllocAdp5allocEjjPK10ALLOC_INFO;	.scl	2;	.type	32;	.endef
__ZN15CIStackAllocAdp5allocEjjPK10ALLOC_INFO:
LFB712:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	(%eax), %eax
	addl	$20, %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	4(%edx), %edx
	movl	16(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	12(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE712:
	.section	.text$_ZN15CIStackAllocAdp4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CIStackAllocAdp4freeEPv
	.def	__ZN15CIStackAllocAdp4freeEPv;	.scl	2;	.type	32;	.endef
__ZN15CIStackAllocAdp4freeEPv:
LFB713:
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
LFE713:
	.section	.text$_ZN15CIStackAllocAdpC2ER15IStackAllocatorNS_13E_AUTO_REWINDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CIStackAllocAdpC2ER15IStackAllocatorNS_13E_AUTO_REWINDE
	.def	__ZN15CIStackAllocAdpC2ER15IStackAllocatorNS_13E_AUTO_REWINDE;	.scl	2;	.type	32;	.endef
__ZN15CIStackAllocAdpC2ER15IStackAllocatorNS_13E_AUTO_REWINDE:
LFB715:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA715
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
	call	__ZN10IAllocatorC2Ev
	movl	8(%ebp), %eax
	movl	$__ZTV15CIStackAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	4(%edx), %edx
	movl	%edx, (%esp)
LEHB123:
	call	*%eax
LEHE123:
	movl	8(%ebp), %edx
	movl	%eax, 12(%edx)
	jmp	L657
L656:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10IAllocatorD2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB124:
	call	__Unwind_Resume
LEHE124:
L657:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE715:
	.section	.gcc_except_table,"w"
LLSDA715:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE715-LLSDACSB715
LLSDACSB715:
	.uleb128 LEHB123-LFB715
	.uleb128 LEHE123-LEHB123
	.uleb128 L656-LFB715
	.uleb128 0
	.uleb128 LEHB124-LFB715
	.uleb128 LEHE124-LEHB124
	.uleb128 0
	.uleb128 0
LLSDACSE715:
	.section	.text$_ZN15CIStackAllocAdpC2ER15IStackAllocatorNS_13E_AUTO_REWINDE,"x"
	.linkonce discard
	.section	.text$_ZN15CIStackAllocAdpC1ER15IStackAllocatorNS_13E_AUTO_REWINDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CIStackAllocAdpC1ER15IStackAllocatorNS_13E_AUTO_REWINDE
	.def	__ZN15CIStackAllocAdpC1ER15IStackAllocatorNS_13E_AUTO_REWINDE;	.scl	2;	.type	32;	.endef
__ZN15CIStackAllocAdpC1ER15IStackAllocatorNS_13E_AUTO_REWINDE:
LFB716:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA716
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
	call	__ZN10IAllocatorC2Ev
	movl	8(%ebp), %eax
	movl	$__ZTV15CIStackAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	4(%edx), %edx
	movl	%edx, (%esp)
LEHB125:
	call	*%eax
LEHE125:
	movl	8(%ebp), %edx
	movl	%eax, 12(%edx)
	jmp	L661
L660:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10IAllocatorD2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB126:
	call	__Unwind_Resume
LEHE126:
L661:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE716:
	.section	.gcc_except_table,"w"
LLSDA716:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE716-LLSDACSB716
LLSDACSB716:
	.uleb128 LEHB125-LFB716
	.uleb128 LEHE125-LEHB125
	.uleb128 L660-LFB716
	.uleb128 0
	.uleb128 LEHB126-LFB716
	.uleb128 LEHE126-LEHB126
	.uleb128 0
	.uleb128 0
LLSDACSE716:
	.section	.text$_ZN15CIStackAllocAdpC1ER15IStackAllocatorNS_13E_AUTO_REWINDE,"x"
	.linkonce discard
	.section	.text$_ZN15CIStackAllocAdpD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CIStackAllocAdpD2Ev
	.def	__ZN15CIStackAllocAdpD2Ev;	.scl	2;	.type	32;	.endef
__ZN15CIStackAllocAdpD2Ev:
LFB718:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA718
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV15CIStackAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	$1, %eax
	jne	L663
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	(%eax), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	12(%edx), %ecx
	movl	8(%ebp), %edx
	movl	4(%edx), %edx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L663:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10IAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L662
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L662:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE718:
	.section	.gcc_except_table,"w"
LLSDA718:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE718-LLSDACSB718
LLSDACSB718:
LLSDACSE718:
	.section	.text$_ZN15CIStackAllocAdpD2Ev,"x"
	.linkonce discard
	.section	.text$_ZN15CIStackAllocAdpD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CIStackAllocAdpD1Ev
	.def	__ZN15CIStackAllocAdpD1Ev;	.scl	2;	.type	32;	.endef
__ZN15CIStackAllocAdpD1Ev:
LFB719:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA719
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV15CIStackAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	$1, %eax
	jne	L667
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	(%eax), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	12(%edx), %ecx
	movl	8(%ebp), %edx
	movl	4(%edx), %edx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L667:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10IAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L666
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L666:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE719:
	.section	.gcc_except_table,"w"
LLSDA719:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE719-LLSDACSB719
LLSDACSB719:
LLSDACSE719:
	.section	.text$_ZN15CIStackAllocAdpD1Ev,"x"
	.linkonce discard
	.section	.text$_ZN15CIStackAllocAdpD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CIStackAllocAdpD0Ev
	.def	__ZN15CIStackAllocAdpD0Ev;	.scl	2;	.type	32;	.endef
__ZN15CIStackAllocAdpD0Ev:
LFB720:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE720:
	.section .rdata,"dr"
LC127:
	.ascii "CStackAllocAdp\0"
	.section	.text$_ZNK14CStackAllocAdp7getNameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK14CStackAllocAdp7getNameEv
	.def	__ZNK14CStackAllocAdp7getNameEv;	.scl	2;	.type	32;	.endef
__ZNK14CStackAllocAdp7getNameEv:
LFB721:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$LC127, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE721:
	.section	.text$_ZN14CStackAllocAdp12getAllocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CStackAllocAdp12getAllocatorEv
	.def	__ZN14CStackAllocAdp12getAllocatorEv;	.scl	2;	.type	32;	.endef
__ZN14CStackAllocAdp12getAllocatorEv:
LFB722:
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
LFE722:
	.section	.text$_ZN14CStackAllocAdp5allocEjjPK10ALLOC_INFO,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CStackAllocAdp5allocEjjPK10ALLOC_INFO
	.def	__ZN14CStackAllocAdp5allocEjjPK10ALLOC_INFO;	.scl	2;	.type	32;	.endef
__ZN14CStackAllocAdp5allocEjjPK10ALLOC_INFO:
LFB724:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CStackAllocAdp12getAllocatorEv
	movl	%eax, -12(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CStackAllocator6allocNEjj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE724:
	.section	.text$_ZN14CStackAllocAdp4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CStackAllocAdp4freeEPv
	.def	__ZN14CStackAllocAdp4freeEPv;	.scl	2;	.type	32;	.endef
__ZN14CStackAllocAdp4freeEPv:
LFB725:
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
LFE725:
	.section	.text$_ZN14CStackAllocAdpC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CStackAllocAdpC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
	.def	__ZN14CStackAllocAdpC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE;	.scl	2;	.type	32;	.endef
__ZN14CStackAllocAdpC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE:
LFB728:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	16(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpC2ER15IStackAllocatorNS_13E_AUTO_REWINDE
	movl	8(%ebp), %eax
	movl	$__ZTV14CStackAllocAdp+8, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE728:
	.section	.text$_ZN14CStackAllocAdpD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CStackAllocAdpD1Ev
	.def	__ZN14CStackAllocAdpD1Ev;	.scl	2;	.type	32;	.endef
__ZN14CStackAllocAdpD1Ev:
LFB731:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV14CStackAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L680
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L680:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE731:
	.section	.text$_ZN14CStackAllocAdpD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CStackAllocAdpD0Ev
	.def	__ZN14CStackAllocAdpD0Ev;	.scl	2;	.type	32;	.endef
__ZN14CStackAllocAdpD0Ev:
LFB732:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CStackAllocAdpD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE732:
	.section .rdata,"dr"
LC128:
	.ascii "CDualStackAllocAdp\0"
	.section	.text$_ZNK18CDualStackAllocAdp7getNameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK18CDualStackAllocAdp7getNameEv
	.def	__ZNK18CDualStackAllocAdp7getNameEv;	.scl	2;	.type	32;	.endef
__ZNK18CDualStackAllocAdp7getNameEv:
LFB733:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$LC128, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE733:
	.section	.text$_ZN18CDualStackAllocAdp12getAllocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CDualStackAllocAdp12getAllocatorEv
	.def	__ZN18CDualStackAllocAdp12getAllocatorEv;	.scl	2;	.type	32;	.endef
__ZN18CDualStackAllocAdp12getAllocatorEv:
LFB734:
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
LFE734:
	.section	.text$_ZN18CDualStackAllocAdp5allocEjjPK10ALLOC_INFO,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CDualStackAllocAdp5allocEjjPK10ALLOC_INFO
	.def	__ZN18CDualStackAllocAdp5allocEjjPK10ALLOC_INFO;	.scl	2;	.type	32;	.endef
__ZN18CDualStackAllocAdp5allocEjjPK10ALLOC_INFO:
LFB740:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CDualStackAllocAdp12getAllocatorEv
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE740:
	.section	.text$_ZN18CDualStackAllocAdp4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CDualStackAllocAdp4freeEPv
	.def	__ZN18CDualStackAllocAdp4freeEPv;	.scl	2;	.type	32;	.endef
__ZN18CDualStackAllocAdp4freeEPv:
LFB741:
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
LFE741:
	.section	.text$_ZN18CDualStackAllocAdpC1ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CDualStackAllocAdpC1ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE
	.def	__ZN18CDualStackAllocAdpC1ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE;	.scl	2;	.type	32;	.endef
__ZN18CDualStackAllocAdpC1ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE:
LFB744:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	20(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpC2ER15IStackAllocatorNS_13E_AUTO_REWINDE
	movl	8(%ebp), %eax
	movl	$__ZTV18CDualStackAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 16(%eax)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	8(%ebp), %edx
	movl	%eax, 12(%edx)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	8(%ebp), %edx
	movl	%eax, 20(%edx)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE744:
	.section	.text$_ZN18CDualStackAllocAdpD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CDualStackAllocAdpD1Ev
	.def	__ZN18CDualStackAllocAdpD1Ev;	.scl	2;	.type	32;	.endef
__ZN18CDualStackAllocAdpD1Ev:
LFB747:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV18CDualStackAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	$2, %eax
	jne	L694
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CDualStackAllocAdp12getAllocatorEv
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backNEj
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backREj
	jmp	L695
L694:
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	$1, %eax
	jne	L695
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CDualStackAllocAdp12getAllocatorEv
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	cmpl	$1, %eax
	jne	L696
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backNEj
	jmp	L697
L696:
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	cmpl	$-1, %eax
	jne	L698
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backREj
	jmp	L697
L698:
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator17getDefaultOrderedEv
	cmpl	$-1, %eax
	sete	%al
	testb	%al, %al
	je	L699
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backREj
	jmp	L697
L699:
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backNEj
	jmp	L695
L697:
L695:
	movl	8(%ebp), %eax
	movl	$0, 8(%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L693
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L693:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE747:
	.section	.text$_ZN18CDualStackAllocAdpD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CDualStackAllocAdpD0Ev
	.def	__ZN18CDualStackAllocAdpD0Ev;	.scl	2;	.type	32;	.endef
__ZN18CDualStackAllocAdpD0Ev:
LFB748:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CDualStackAllocAdpD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE748:
	.section .rdata,"dr"
LC129:
	.ascii "CPoolAllocAdp\0"
	.section	.text$_ZNK13CPoolAllocAdp7getNameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK13CPoolAllocAdp7getNameEv
	.def	__ZNK13CPoolAllocAdp7getNameEv;	.scl	2;	.type	32;	.endef
__ZNK13CPoolAllocAdp7getNameEv:
LFB749:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$LC129, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE749:
	.section	.text$_ZNK13CPoolAllocAdp8getTotalEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK13CPoolAllocAdp8getTotalEv
	.def	__ZNK13CPoolAllocAdp8getTotalEv;	.scl	2;	.type	32;	.endef
__ZNK13CPoolAllocAdp8getTotalEv:
LFB750:
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
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNK14CPoolAllocator12getBlocksNumEv
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNK14CPoolAllocator12getBlockSizeEv
	imull	%ebx, %eax
	addl	$4, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE750:
	.section	.text$_ZNK13CPoolAllocAdp7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK13CPoolAllocAdp7getUsedEv
	.def	__ZNK13CPoolAllocAdp7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK13CPoolAllocAdp7getUsedEv:
LFB751:
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
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNK14CPoolAllocator7getUsedEv
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNK14CPoolAllocator12getBlockSizeEv
	imull	%ebx, %eax
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE751:
	.section	.text$_ZNK13CPoolAllocAdp9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK13CPoolAllocAdp9getRemainEv
	.def	__ZNK13CPoolAllocAdp9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK13CPoolAllocAdp9getRemainEv:
LFB752:
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
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNK14CPoolAllocator9getRemainEv
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNK14CPoolAllocator12getBlockSizeEv
	imull	%ebx, %eax
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE752:
	.section	.text$_ZN13CPoolAllocAdp5allocEjjPK10ALLOC_INFO,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CPoolAllocAdp5allocEjjPK10ALLOC_INFO
	.def	__ZN13CPoolAllocAdp5allocEjjPK10ALLOC_INFO;	.scl	2;	.type	32;	.endef
__ZN13CPoolAllocAdp5allocEjjPK10ALLOC_INFO:
LFB754:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator5allocEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE754:
	.section	.text$_ZN13CPoolAllocAdp4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CPoolAllocAdp4freeEPv
	.def	__ZN13CPoolAllocAdp4freeEPv;	.scl	2;	.type	32;	.endef
__ZN13CPoolAllocAdp4freeEPv:
LFB755:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator4freeEPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE755:
	.section	.text$_ZN13CPoolAllocAdpC1ER14CPoolAllocator,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CPoolAllocAdpC1ER14CPoolAllocator
	.def	__ZN13CPoolAllocAdpC1ER14CPoolAllocator;	.scl	2;	.type	32;	.endef
__ZN13CPoolAllocAdpC1ER14CPoolAllocator:
LFB758:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10IAllocatorC2Ev
	movl	8(%ebp), %eax
	movl	$__ZTV13CPoolAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE758:
	.section	.text$_ZN13CPoolAllocAdpD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CPoolAllocAdpD1Ev
	.def	__ZN13CPoolAllocAdpD1Ev;	.scl	2;	.type	32;	.endef
__ZN13CPoolAllocAdpD1Ev:
LFB761:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV13CPoolAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10IAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L717
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L717:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE761:
	.section	.text$_ZN13CPoolAllocAdpD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CPoolAllocAdpD0Ev
	.def	__ZN13CPoolAllocAdpD0Ev;	.scl	2;	.type	32;	.endef
__ZN13CPoolAllocAdpD0Ev:
LFB762:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CPoolAllocAdpD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE762:
	.section .rdata,"dr"
	.align 4
LC130:
	.ascii "placement new(size=%d, i_allocator=\"%s\":%d/%d/%d)\12\0"
LC131:
	.ascii "  p=0x%p\12\0"
	.text
	.globl	__ZnwjR10IAllocator
	.def	__ZnwjR10IAllocator;	.scl	2;	.type	32;	.endef
__ZnwjR10IAllocator:
LFB763:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA763
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
	movl	(%eax), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
LEHB127:
	call	*%eax
	movl	%eax, %edi
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC130, (%esp)
	call	_printf
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	$0, 12(%esp)
	movl	$4, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
LEHE127:
	movl	-28(%ebp), %eax
	jmp	L727
L726:
	cmpl	$-1, %edx
	je	L725
	movl	%eax, (%esp)
LEHB128:
	call	__Unwind_Resume
L725:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE128:
L727:
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
LFE763:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA763:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT763-LLSDATTD763
LLSDATTD763:
	.byte	0x1
	.uleb128 LLSDACSE763-LLSDACSB763
LLSDACSB763:
	.uleb128 LEHB127-LFB763
	.uleb128 LEHE127-LEHB127
	.uleb128 L726-LFB763
	.uleb128 0x1
	.uleb128 LEHB128-LFB763
	.uleb128 LEHE128-LEHB128
	.uleb128 0
	.uleb128 0
LLSDACSE763:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT763:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC132:
	.ascii "placement new[](size=%d, i_allocator=\"%s\":%d/%d/%d)\12\0"
	.text
	.globl	__ZnajR10IAllocator
	.def	__ZnajR10IAllocator;	.scl	2;	.type	32;	.endef
__ZnajR10IAllocator:
LFB764:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA764
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
	movl	(%eax), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
LEHB129:
	call	*%eax
	movl	%eax, %edi
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC132, (%esp)
	call	_printf
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	$0, 12(%esp)
	movl	$4, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
LEHE129:
	movl	-28(%ebp), %eax
	jmp	L733
L732:
	cmpl	$-1, %edx
	je	L731
	movl	%eax, (%esp)
LEHB130:
	call	__Unwind_Resume
L731:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE130:
L733:
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
LFE764:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA764:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT764-LLSDATTD764
LLSDATTD764:
	.byte	0x1
	.uleb128 LLSDACSE764-LLSDACSB764
LLSDACSB764:
	.uleb128 LEHB129-LFB764
	.uleb128 LEHE129-LEHB129
	.uleb128 L732-LFB764
	.uleb128 0x1
	.uleb128 LEHB130-LFB764
	.uleb128 LEHE130-LEHB130
	.uleb128 0
	.uleb128 0
LLSDACSE764:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT764:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC133:
	.ascii "placement delete(p=0x%p, i_allocator=\"%s\":%d/%d/%d)\12\0"
	.text
	.globl	__ZdlPvR10IAllocator
	.def	__ZdlPvR10IAllocator;	.scl	2;	.type	32;	.endef
__ZdlPvR10IAllocator:
LFB765:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA765
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
LEHB131:
	call	*%eax
	movl	%eax, %edi
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC133, (%esp)
	call	_printf
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$20, %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
LEHE131:
	jmp	L738
L737:
	cmpl	$-1, %edx
	je	L736
	movl	%eax, (%esp)
LEHB132:
	call	__Unwind_Resume
L736:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE132:
L738:
	addl	$44, %esp
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
LFE765:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA765:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT765-LLSDATTD765
LLSDATTD765:
	.byte	0x1
	.uleb128 LLSDACSE765-LLSDACSB765
LLSDACSB765:
	.uleb128 LEHB131-LFB765
	.uleb128 LEHE131-LEHB131
	.uleb128 L737-LFB765
	.uleb128 0x1
	.uleb128 LEHB132-LFB765
	.uleb128 LEHE132-LEHB132
	.uleb128 0
	.uleb128 0
LLSDACSE765:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT765:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC134:
	.ascii "placement delete[](p=0x%p, i_allocator=\"%s\":%d/%d/%d)\12\0"
	.text
	.globl	__ZdaPvR10IAllocator
	.def	__ZdaPvR10IAllocator;	.scl	2;	.type	32;	.endef
__ZdaPvR10IAllocator:
LFB766:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA766
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
LEHB133:
	call	*%eax
	movl	%eax, %edi
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC134, (%esp)
	call	_printf
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$20, %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
LEHE133:
	jmp	L743
L742:
	cmpl	$-1, %edx
	je	L741
	movl	%eax, (%esp)
LEHB134:
	call	__Unwind_Resume
L741:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE134:
L743:
	addl	$44, %esp
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
LFE766:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA766:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT766-LLSDATTD766
LLSDATTD766:
	.byte	0x1
	.uleb128 LLSDACSE766-LLSDACSB766
LLSDACSB766:
	.uleb128 LEHB133-LFB766
	.uleb128 LEHE133-LEHB133
	.uleb128 L742-LFB766
	.uleb128 0x1
	.uleb128 LEHB134-LFB766
	.uleb128 LEHE134-LEHB134
	.uleb128 0
	.uleb128 0
LLSDACSE766:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT766:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC135:
	.ascii "CTest6::DefaultConstructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest6C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest6C1Ev
	.def	__ZN6CTest6C1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest6C1Ev:
LFB771:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA771
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	$LC10, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB135:
	call	__ZN6CTest6C1EPKc
LEHE135:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC135, (%esp)
LEHB136:
	call	_printf
LEHE136:
	jmp	L747
L746:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest6D1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB137:
	call	__Unwind_Resume
LEHE137:
L747:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE771:
	.section	.gcc_except_table,"w"
LLSDA771:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE771-LLSDACSB771
LLSDACSB771:
	.uleb128 LEHB135-LFB771
	.uleb128 LEHE135-LEHB135
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB136-LFB771
	.uleb128 LEHE136-LEHB136
	.uleb128 L746-LFB771
	.uleb128 0
	.uleb128 LEHB137-LFB771
	.uleb128 LEHE137-LEHB137
	.uleb128 0
	.uleb128 0
LLSDACSE771:
	.section	.text$_ZN6CTest6C1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC136:
	.ascii "CTest6::Constructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest6C2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest6C2EPKc
	.def	__ZN6CTest6C2EPKc;	.scl	2;	.type	32;	.endef
__ZN6CTest6C2EPKc:
LFB773:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV6CTest6+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC136, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE773:
	.section	.text$_ZN6CTest6C1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest6C1EPKc
	.def	__ZN6CTest6C1EPKc;	.scl	2;	.type	32;	.endef
__ZN6CTest6C1EPKc:
LFB774:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV6CTest6+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC136, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE774:
	.section .rdata,"dr"
	.align 4
LC137:
	.ascii "CTest6::Destructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest6D2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest6D2Ev
	.def	__ZN6CTest6D2Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest6D2Ev:
LFB776:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA776
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV6CTest6+8, (%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC137, (%esp)
	call	_printf
	movl	$0, %eax
	testl	%eax, %eax
	je	L750
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L750:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE776:
	.section	.gcc_except_table,"w"
LLSDA776:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE776-LLSDACSB776
LLSDACSB776:
LLSDACSE776:
	.section	.text$_ZN6CTest6D2Ev,"x"
	.linkonce discard
	.section	.text$_ZN6CTest6D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest6D1Ev
	.def	__ZN6CTest6D1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest6D1Ev:
LFB777:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA777
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV6CTest6+8, (%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC137, (%esp)
	call	_printf
	movl	$0, %eax
	testl	%eax, %eax
	je	L753
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L753:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE777:
	.section	.gcc_except_table,"w"
LLSDA777:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE777-LLSDACSB777
LLSDACSB777:
LLSDACSE777:
	.section	.text$_ZN6CTest6D1Ev,"x"
	.linkonce discard
	.section	.text$_ZN6CTest6D0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest6D0Ev
	.def	__ZN6CTest6D0Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest6D0Ev:
LFB778:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest6D1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE778:
	.section .rdata,"dr"
LC138:
	.ascii "CTest6ex::Constructor\0"
	.section	.text$_ZN8CTest6exC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest6exC2Ev
	.def	__ZN8CTest6exC2Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest6exC2Ev:
LFB780:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV8CTest6ex+8, (%eax)
	movl	$LC138, (%esp)
	call	_puts
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE780:
	.section .rdata,"dr"
LC139:
	.ascii "CTest6ex::Destructor\0"
	.section	.text$_ZN8CTest6exD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest6exD2Ev
	.def	__ZN8CTest6exD2Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest6exD2Ev:
LFB783:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA783
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV8CTest6ex+8, (%eax)
	movl	$LC139, (%esp)
	call	_puts
	movl	$0, %eax
	testl	%eax, %eax
	je	L759
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L759:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE783:
	.section	.gcc_except_table,"w"
LLSDA783:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE783-LLSDACSB783
LLSDACSB783:
LLSDACSE783:
	.section	.text$_ZN8CTest6exD2Ev,"x"
	.linkonce discard
	.section	.text$_ZN8CTest6exD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest6exD1Ev
	.def	__ZN8CTest6exD1Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest6exD1Ev:
LFB784:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA784
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV8CTest6ex+8, (%eax)
	movl	$LC139, (%esp)
	call	_puts
	movl	$0, %eax
	testl	%eax, %eax
	je	L762
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L762:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE784:
	.section	.gcc_except_table,"w"
LLSDA784:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE784-LLSDACSB784
LLSDACSB784:
LLSDACSE784:
	.section	.text$_ZN8CTest6exD1Ev,"x"
	.linkonce discard
	.section	.text$_ZN8CTest6exD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest6exD0Ev
	.def	__ZN8CTest6exD0Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest6exD0Ev:
LFB785:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN8CTest6exD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE785:
	.section .rdata,"dr"
	.align 4
LC140:
	.ascii "CDerivedTest6::Constructor : name=\"%s\"\12\0"
	.section	.text$_ZN13CDerivedTest6C1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CDerivedTest6C1EPKc
	.def	__ZN13CDerivedTest6C1EPKc;	.scl	2;	.type	32;	.endef
__ZN13CDerivedTest6C1EPKc:
LFB791:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA791
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB138:
	call	__ZN6CTest6C2EPKc
LEHE138:
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
LEHB139:
	call	__ZN8CTest6exC2Ev
LEHE139:
	movl	8(%ebp), %eax
	movl	$__ZTV13CDerivedTest6+8, (%eax)
	movl	8(%ebp), %eax
	movl	$__ZTV13CDerivedTest6+24, 12(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC140, (%esp)
LEHB140:
	call	_printf
LEHE140:
	jmp	L772
L771:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__ZN8CTest6exD2Ev
	jmp	L769
L770:
	movl	%eax, %ebx
L769:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest6D2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB141:
	call	__Unwind_Resume
LEHE141:
L772:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE791:
	.section	.gcc_except_table,"w"
LLSDA791:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE791-LLSDACSB791
LLSDACSB791:
	.uleb128 LEHB138-LFB791
	.uleb128 LEHE138-LEHB138
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB139-LFB791
	.uleb128 LEHE139-LEHB139
	.uleb128 L770-LFB791
	.uleb128 0
	.uleb128 LEHB140-LFB791
	.uleb128 LEHE140-LEHB140
	.uleb128 L771-LFB791
	.uleb128 0
	.uleb128 LEHB141-LFB791
	.uleb128 LEHE141-LEHB141
	.uleb128 0
	.uleb128 0
LLSDACSE791:
	.section	.text$_ZN13CDerivedTest6C1EPKc,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC141:
	.ascii "CDerivedTest6::Destructor : name=\"%s\"\12\0"
	.section	.text$_ZN13CDerivedTest6D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CDerivedTest6D1Ev
	.def	__ZN13CDerivedTest6D1Ev;	.scl	2;	.type	32;	.endef
__ZN13CDerivedTest6D1Ev:
LFB794:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA794
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV13CDerivedTest6+8, (%eax)
	movl	8(%ebp), %eax
	movl	$__ZTV13CDerivedTest6+24, 12(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC141, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__ZN8CTest6exD2Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest6D2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L773
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L773:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE794:
	.section	.gcc_except_table,"w"
LLSDA794:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE794-LLSDACSB794
LLSDACSB794:
LLSDACSE794:
	.section	.text$_ZN13CDerivedTest6D1Ev,"x"
	.linkonce discard
	.section	.text$_ZThn12_N13CDerivedTest6D1Ev,"x"
	.linkonce discard
	.globl	__ZThn12_N13CDerivedTest6D1Ev
	.def	__ZThn12_N13CDerivedTest6D1Ev;	.scl	2;	.type	32;	.endef
__ZThn12_N13CDerivedTest6D1Ev:
LFB3873:
	.cfi_startproc
	subl	$12, 4(%esp)
	jmp	__ZN13CDerivedTest6D1Ev
	.cfi_endproc
LFE3873:
	.section	.text$_ZN13CDerivedTest6D0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CDerivedTest6D0Ev
	.def	__ZN13CDerivedTest6D0Ev;	.scl	2;	.type	32;	.endef
__ZN13CDerivedTest6D0Ev:
LFB795:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CDerivedTest6D1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE795:
	.section	.text$_ZThn12_N13CDerivedTest6D0Ev,"x"
	.linkonce discard
	.globl	__ZThn12_N13CDerivedTest6D0Ev
	.def	__ZThn12_N13CDerivedTest6D0Ev;	.scl	2;	.type	32;	.endef
__ZThn12_N13CDerivedTest6D0Ev:
LFB3874:
	.cfi_startproc
	subl	$12, 4(%esp)
	jmp	__ZN13CDerivedTest6D0Ev
	.cfi_endproc
LFE3874:
	.text
	.globl	__Z10test6_sub1PKcR10IAllocator
	.def	__Z10test6_sub1PKcR10IAllocator;	.scl	2;	.type	32;	.endef
__Z10test6_sub1PKcR10IAllocator:
LFB796:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA796
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
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$12, (%esp)
	call	__ZnwjR10IAllocator
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L779
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
LEHB142:
	call	__ZN6CTest6C1EPKc
LEHE142:
	movl	%ebx, %eax
	jmp	L780
L779:
	movl	%ebx, %eax
L780:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
LEHB143:
	call	_printf
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrI6CTest6EvRPT_R10IAllocator
LEHE143:
	jmp	L785
L783:
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvR10IAllocator
	movl	%esi, %eax
	jmp	L782
L784:
L782:
	movl	%eax, (%esp)
LEHB144:
	call	__Unwind_Resume
LEHE144:
L785:
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
LFE796:
	.section	.gcc_except_table,"w"
LLSDA796:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE796-LLSDACSB796
LLSDACSB796:
	.uleb128 LEHB142-LFB796
	.uleb128 LEHE142-LEHB142
	.uleb128 L783-LFB796
	.uleb128 0
	.uleb128 LEHB143-LFB796
	.uleb128 LEHE143-LEHB143
	.uleb128 L784-LFB796
	.uleb128 0
	.uleb128 LEHB144-LFB796
	.uleb128 LEHE144-LEHB144
	.uleb128 0
	.uleb128 0
LLSDACSE796:
	.text
	.globl	__Z10test6_sub2R10IAllocator
	.def	__Z10test6_sub2R10IAllocator;	.scl	2;	.type	32;	.endef
__Z10test6_sub2R10IAllocator:
LFB797:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA797
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$40, (%esp)
	call	__ZnajR10IAllocator
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L787
	movl	$3, (%ebx)
	leal	4(%ebx), %edi
	movl	$2, %esi
	movl	%edi, -44(%ebp)
	jmp	L788
L789:
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
LEHB145:
	call	__ZN6CTest6C1Ev
LEHE145:
	addl	$12, -44(%ebp)
	subl	$1, %esi
L788:
	cmpl	$-1, %esi
	jne	L789
	leal	4(%ebx), %eax
	jmp	L790
L787:
	movl	%ebx, %eax
L790:
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
LEHB146:
	call	_printf
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$3, 4(%esp)
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrI6CTest6EvRPT_jR10IAllocator
LEHE146:
	jmp	L797
L795:
	movl	%eax, -44(%ebp)
	testl	%edi, %edi
	je	L792
	movl	$2, %eax
	subl	%esi, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%edi,%eax), %esi
L793:
	cmpl	%edi, %esi
	je	L792
	subl	$12, %esi
	movl	(%esi), %eax
	movl	(%eax), %eax
	movl	%esi, (%esp)
	call	*%eax
	jmp	L793
L792:
	movl	-44(%ebp), %esi
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdaPvR10IAllocator
	movl	%esi, %eax
	jmp	L794
L796:
L794:
	movl	%eax, (%esp)
LEHB147:
	call	__Unwind_Resume
LEHE147:
L797:
	addl	$44, %esp
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
LFE797:
	.section	.gcc_except_table,"w"
LLSDA797:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE797-LLSDACSB797
LLSDACSB797:
	.uleb128 LEHB145-LFB797
	.uleb128 LEHE145-LEHB145
	.uleb128 L795-LFB797
	.uleb128 0
	.uleb128 LEHB146-LFB797
	.uleb128 LEHE146-LEHB146
	.uleb128 L796-LFB797
	.uleb128 0
	.uleb128 LEHB147-LFB797
	.uleb128 LEHE147-LEHB147
	.uleb128 0
	.uleb128 0
LLSDACSE797:
	.text
	.globl	__Z10test6_sub3PKcR10IAllocator
	.def	__Z10test6_sub3PKcR10IAllocator;	.scl	2;	.type	32;	.endef
__Z10test6_sub3PKcR10IAllocator:
LFB798:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA798
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
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$24, (%esp)
	call	__ZnwjR10IAllocator
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L799
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
LEHB148:
	call	__ZN13CDerivedTest6C1EPKc
LEHE148:
	movl	%ebx, %eax
	jmp	L800
L799:
	movl	%ebx, %eax
L800:
	testl	%eax, %eax
	je	L801
	addl	$12, %eax
	jmp	L802
L801:
	movl	$0, %eax
L802:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
LEHB149:
	call	_printf
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrI8CTest6exEvRPT_R10IAllocator
LEHE149:
	jmp	L807
L805:
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvR10IAllocator
	movl	%esi, %eax
	jmp	L804
L806:
L804:
	movl	%eax, (%esp)
LEHB150:
	call	__Unwind_Resume
LEHE150:
L807:
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
LFE798:
	.section	.gcc_except_table,"w"
LLSDA798:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE798-LLSDACSB798
LLSDACSB798:
	.uleb128 LEHB148-LFB798
	.uleb128 LEHE148-LEHB148
	.uleb128 L805-LFB798
	.uleb128 0
	.uleb128 LEHB149-LFB798
	.uleb128 LEHE149-LEHB149
	.uleb128 L806-LFB798
	.uleb128 0
	.uleb128 LEHB150-LFB798
	.uleb128 LEHE150-LEHB150
	.uleb128 0
	.uleb128 0
LLSDACSE798:
	.text
	.section .rdata,"dr"
	.align 4
LC142:
	.ascii "---------- test6:\345\205\261\351\200\232\343\202\242\343\203\255\343\202\261\343\203\274\343\202\277\343\202\244\343\203\263\343\202\277\343\203\274\343\203\225\343\202\247\343\203\274\343\202\271 ----------\0"
LC143:
	.ascii "----------CStdAllocAdp\0"
LC144:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-1a\0"
LC145:
	.ascii "----------CMonoAllocAdp\0"
LC146:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-2a\0"
LC147:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-2b\0"
LC148:
	.ascii "----------CStackAllocAdp\0"
LC149:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-3a\0"
LC150:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-3b\0"
LC151:
	.ascii "----------CDualStackAllocAdp\0"
LC152:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-4a\0"
LC153:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-4b\0"
	.align 4
LC154:
	.ascii "----------CIStackAllocAdp on CStackAllocAdp\0"
LC155:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-5a\0"
LC156:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-5b\0"
	.align 4
LC157:
	.ascii "----------CIStackAllocAdp on CDualStackAllocAdp\0"
LC158:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-6a\0"
LC159:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-6b\0"
LC160:
	.ascii "----------CPoolAllocAdp\0"
LC161:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-7a\0"
LC162:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-7b\0"
	.text
	.globl	__Z5test6v
	.def	__Z5test6v;	.scl	2;	.type	32;	.endef
__Z5test6v:
LFB799:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA799
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$708, %esp
	.cfi_offset 3, -12
	movl	$LC142, (%esp)
LEHB151:
	call	_puts
LEHE151:
	movl	$LC143, (%esp)
LEHB152:
	call	_puts
LEHE152:
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN12CStdAllocAdpC1Ev
	leal	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC144, (%esp)
LEHB153:
	call	__Z10test6_sub1PKcR10IAllocator
LEHE153:
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN12CStdAllocAdpD1Ev
	movl	$LC145, (%esp)
LEHB154:
	call	_puts
LEHE154:
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN21CMonoAllocAdpWithBuffILj128EEC1Ev
	leal	-692(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC146, (%esp)
LEHB155:
	call	__Z10test6_sub1PKcR10IAllocator
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10test6_sub2R10IAllocator
	leal	-692(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC147, (%esp)
	call	__Z10test6_sub3PKcR10IAllocator
LEHE155:
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN21CMonoAllocAdpWithBuffILj128EED1Ev
	movl	$LC148, (%esp)
LEHB156:
	call	_puts
LEHE156:
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj128EEC1Ev
	movl	$0, 8(%esp)
	leal	-692(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
LEHB157:
	call	__ZN14CStackAllocAdpC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE157:
	leal	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC149, (%esp)
LEHB158:
	call	__Z10test6_sub1PKcR10IAllocator
LEHE158:
	movl	$1, 8(%esp)
	leal	-692(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
LEHB159:
	call	__ZN14CStackAllocAdpC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE159:
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
LEHB160:
	call	__Z10test6_sub2R10IAllocator
LEHE160:
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CStackAllocAdpD1Ev
	leal	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC150, (%esp)
LEHB161:
	call	__Z10test6_sub3PKcR10IAllocator
LEHE161:
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CStackAllocAdpD1Ev
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj128EED1Ev
	movl	$LC151, (%esp)
LEHB162:
	call	_puts
LEHE162:
	movl	$1, 4(%esp)
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj128EEC1EN15IStackAllocator9E_ORDEREDE
	movl	$0, 12(%esp)
	movl	$-1, 8(%esp)
	leal	-692(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
LEHB163:
	call	__ZN18CDualStackAllocAdpC1ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE163:
	leal	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC152, (%esp)
LEHB164:
	call	__Z10test6_sub1PKcR10IAllocator
LEHE164:
	movl	$1, 12(%esp)
	movl	$-1, 8(%esp)
	leal	-692(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
LEHB165:
	call	__ZN18CDualStackAllocAdpC1ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE165:
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
LEHB166:
	call	__Z10test6_sub2R10IAllocator
LEHE166:
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CDualStackAllocAdpD1Ev
	leal	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC153, (%esp)
LEHB167:
	call	__Z10test6_sub3PKcR10IAllocator
LEHE167:
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CDualStackAllocAdpD1Ev
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj128EED1Ev
	movl	$LC154, (%esp)
LEHB168:
	call	_puts
LEHE168:
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj128EEC1Ev
	movl	$0, 8(%esp)
	leal	-692(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
LEHB169:
	call	__ZN15CIStackAllocAdpC1ER15IStackAllocatorNS_13E_AUTO_REWINDE
LEHE169:
	leal	-108(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC155, (%esp)
LEHB170:
	call	__Z10test6_sub1PKcR10IAllocator
LEHE170:
	movl	$1, 8(%esp)
	leal	-692(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
LEHB171:
	call	__ZN15CIStackAllocAdpC1ER15IStackAllocatorNS_13E_AUTO_REWINDE
LEHE171:
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
LEHB172:
	call	__Z10test6_sub2R10IAllocator
LEHE172:
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD1Ev
	leal	-108(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC156, (%esp)
LEHB173:
	call	__Z10test6_sub3PKcR10IAllocator
LEHE173:
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD1Ev
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj128EED1Ev
	movl	$LC157, (%esp)
LEHB174:
	call	_puts
LEHE174:
	movl	$1, 4(%esp)
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj128EEC1EN15IStackAllocator9E_ORDEREDE
	movl	$0, 8(%esp)
	leal	-692(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-140(%ebp), %eax
	movl	%eax, (%esp)
LEHB175:
	call	__ZN15CIStackAllocAdpC1ER15IStackAllocatorNS_13E_AUTO_REWINDE
LEHE175:
	leal	-140(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC158, (%esp)
LEHB176:
	call	__Z10test6_sub1PKcR10IAllocator
LEHE176:
	movl	$1, 8(%esp)
	leal	-692(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
LEHB177:
	call	__ZN15CIStackAllocAdpC1ER15IStackAllocatorNS_13E_AUTO_REWINDE
LEHE177:
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
LEHB178:
	call	__Z10test6_sub2R10IAllocator
LEHE178:
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD1Ev
	leal	-140(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC159, (%esp)
LEHB179:
	call	__Z10test6_sub3PKcR10IAllocator
LEHE179:
	leal	-140(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD1Ev
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj128EED1Ev
	movl	$LC160, (%esp)
LEHB180:
	call	_puts
LEHE180:
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithBuffILj24ELi5EEC1Ev
	leal	-692(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-164(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CPoolAllocAdpC1ER14CPoolAllocator
	leal	-164(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC161, (%esp)
LEHB181:
	call	__Z10test6_sub1PKcR10IAllocator
	leal	-164(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10test6_sub2R10IAllocator
	leal	-164(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC162, (%esp)
	call	__Z10test6_sub3PKcR10IAllocator
LEHE181:
	leal	-164(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CPoolAllocAdpD1Ev
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithBuffILj24ELi5EED1Ev
	jmp	L861
L836:
	movl	%eax, %ebx
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN12CStdAllocAdpD1Ev
	movl	%ebx, %eax
	jmp	L810
L835:
L810:
	movl	%eax, (%esp)
LEHB182:
	call	__Unwind_Resume
L838:
	movl	%eax, %ebx
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN21CMonoAllocAdpWithBuffILj128EED1Ev
	movl	%ebx, %eax
	jmp	L812
L837:
L812:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L843:
	movl	%eax, %ebx
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CStackAllocAdpD1Ev
	movl	%ebx, %eax
	jmp	L814
L842:
L814:
	movl	%eax, %ebx
	jmp	L815
L841:
	movl	%eax, %ebx
L815:
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CStackAllocAdpD1Ev
	jmp	L816
L840:
	movl	%eax, %ebx
L816:
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj128EED1Ev
	movl	%ebx, %eax
	jmp	L817
L839:
L817:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L848:
	movl	%eax, %ebx
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CDualStackAllocAdpD1Ev
	movl	%ebx, %eax
	jmp	L819
L847:
L819:
	movl	%eax, %ebx
	jmp	L820
L846:
	movl	%eax, %ebx
L820:
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CDualStackAllocAdpD1Ev
	jmp	L821
L845:
	movl	%eax, %ebx
L821:
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj128EED1Ev
	movl	%ebx, %eax
	jmp	L822
L844:
L822:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L853:
	movl	%eax, %ebx
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD1Ev
	movl	%ebx, %eax
	jmp	L824
L852:
L824:
	movl	%eax, %ebx
	jmp	L825
L851:
	movl	%eax, %ebx
L825:
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD1Ev
	jmp	L826
L850:
	movl	%eax, %ebx
L826:
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj128EED1Ev
	movl	%ebx, %eax
	jmp	L827
L849:
L827:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L858:
	movl	%eax, %ebx
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD1Ev
	movl	%ebx, %eax
	jmp	L829
L857:
L829:
	movl	%eax, %ebx
	jmp	L830
L856:
	movl	%eax, %ebx
L830:
	leal	-140(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD1Ev
	jmp	L831
L855:
	movl	%eax, %ebx
L831:
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj128EED1Ev
	movl	%ebx, %eax
	jmp	L832
L854:
L832:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L860:
	movl	%eax, %ebx
	leal	-164(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CPoolAllocAdpD1Ev
	leal	-692(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithBuffILj24ELi5EED1Ev
	movl	%ebx, %eax
	jmp	L834
L859:
L834:
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE182:
L861:
	addl	$708, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE799:
	.section	.gcc_except_table,"w"
LLSDA799:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE799-LLSDACSB799
LLSDACSB799:
	.uleb128 LEHB151-LFB799
	.uleb128 LEHE151-LEHB151
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB152-LFB799
	.uleb128 LEHE152-LEHB152
	.uleb128 L835-LFB799
	.uleb128 0
	.uleb128 LEHB153-LFB799
	.uleb128 LEHE153-LEHB153
	.uleb128 L836-LFB799
	.uleb128 0
	.uleb128 LEHB154-LFB799
	.uleb128 LEHE154-LEHB154
	.uleb128 L837-LFB799
	.uleb128 0
	.uleb128 LEHB155-LFB799
	.uleb128 LEHE155-LEHB155
	.uleb128 L838-LFB799
	.uleb128 0
	.uleb128 LEHB156-LFB799
	.uleb128 LEHE156-LEHB156
	.uleb128 L839-LFB799
	.uleb128 0
	.uleb128 LEHB157-LFB799
	.uleb128 LEHE157-LEHB157
	.uleb128 L840-LFB799
	.uleb128 0
	.uleb128 LEHB158-LFB799
	.uleb128 LEHE158-LEHB158
	.uleb128 L841-LFB799
	.uleb128 0
	.uleb128 LEHB159-LFB799
	.uleb128 LEHE159-LEHB159
	.uleb128 L842-LFB799
	.uleb128 0
	.uleb128 LEHB160-LFB799
	.uleb128 LEHE160-LEHB160
	.uleb128 L843-LFB799
	.uleb128 0
	.uleb128 LEHB161-LFB799
	.uleb128 LEHE161-LEHB161
	.uleb128 L841-LFB799
	.uleb128 0
	.uleb128 LEHB162-LFB799
	.uleb128 LEHE162-LEHB162
	.uleb128 L844-LFB799
	.uleb128 0
	.uleb128 LEHB163-LFB799
	.uleb128 LEHE163-LEHB163
	.uleb128 L845-LFB799
	.uleb128 0
	.uleb128 LEHB164-LFB799
	.uleb128 LEHE164-LEHB164
	.uleb128 L846-LFB799
	.uleb128 0
	.uleb128 LEHB165-LFB799
	.uleb128 LEHE165-LEHB165
	.uleb128 L847-LFB799
	.uleb128 0
	.uleb128 LEHB166-LFB799
	.uleb128 LEHE166-LEHB166
	.uleb128 L848-LFB799
	.uleb128 0
	.uleb128 LEHB167-LFB799
	.uleb128 LEHE167-LEHB167
	.uleb128 L846-LFB799
	.uleb128 0
	.uleb128 LEHB168-LFB799
	.uleb128 LEHE168-LEHB168
	.uleb128 L849-LFB799
	.uleb128 0
	.uleb128 LEHB169-LFB799
	.uleb128 LEHE169-LEHB169
	.uleb128 L850-LFB799
	.uleb128 0
	.uleb128 LEHB170-LFB799
	.uleb128 LEHE170-LEHB170
	.uleb128 L851-LFB799
	.uleb128 0
	.uleb128 LEHB171-LFB799
	.uleb128 LEHE171-LEHB171
	.uleb128 L852-LFB799
	.uleb128 0
	.uleb128 LEHB172-LFB799
	.uleb128 LEHE172-LEHB172
	.uleb128 L853-LFB799
	.uleb128 0
	.uleb128 LEHB173-LFB799
	.uleb128 LEHE173-LEHB173
	.uleb128 L851-LFB799
	.uleb128 0
	.uleb128 LEHB174-LFB799
	.uleb128 LEHE174-LEHB174
	.uleb128 L854-LFB799
	.uleb128 0
	.uleb128 LEHB175-LFB799
	.uleb128 LEHE175-LEHB175
	.uleb128 L855-LFB799
	.uleb128 0
	.uleb128 LEHB176-LFB799
	.uleb128 LEHE176-LEHB176
	.uleb128 L856-LFB799
	.uleb128 0
	.uleb128 LEHB177-LFB799
	.uleb128 LEHE177-LEHB177
	.uleb128 L857-LFB799
	.uleb128 0
	.uleb128 LEHB178-LFB799
	.uleb128 LEHE178-LEHB178
	.uleb128 L858-LFB799
	.uleb128 0
	.uleb128 LEHB179-LFB799
	.uleb128 LEHE179-LEHB179
	.uleb128 L856-LFB799
	.uleb128 0
	.uleb128 LEHB180-LFB799
	.uleb128 LEHE180-LEHB180
	.uleb128 L859-LFB799
	.uleb128 0
	.uleb128 LEHB181-LFB799
	.uleb128 LEHE181-LEHB181
	.uleb128 L860-LFB799
	.uleb128 0
	.uleb128 LEHB182-LFB799
	.uleb128 LEHE182-LEHB182
	.uleb128 0
	.uleb128 0
LLSDACSE799:
	.text
	.section	.text$_ZN14CPolyAllocatorptEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPolyAllocatorptEv
	.def	__ZN14CPolyAllocatorptEv;	.scl	2;	.type	32;	.endef
__ZN14CPolyAllocatorptEv:
LFB800:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$___emutls_v._ZN14CPolyAllocator11m_allocatorE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE800:
	.section	.text$_ZN14CPolyAllocator12setAllocatorER10IAllocator,"x"
	.linkonce discard
	.globl	__ZN14CPolyAllocator12setAllocatorER10IAllocator
	.def	__ZN14CPolyAllocator12setAllocatorER10IAllocator;	.scl	2;	.type	32;	.endef
__ZN14CPolyAllocator12setAllocatorER10IAllocator:
LFB802:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$___emutls_v._ZN14CPolyAllocator11m_allocatorE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %edx
	movl	%edx, -12(%ebp)
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE802:
	.section	.text$_ZN14CPolyAllocator21getAllocInfoWithResetEv,"x"
	.linkonce discard
	.globl	__ZN14CPolyAllocator21getAllocInfoWithResetEv
	.def	__ZN14CPolyAllocator21getAllocInfoWithResetEv;	.scl	2;	.type	32;	.endef
__ZN14CPolyAllocator21getAllocInfoWithResetEv:
LFB804:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$___emutls_v._ZN14CPolyAllocator11m_allocInfoE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %edx
	movl	%edx, -12(%ebp)
	movl	$0, (%eax)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE804:
	.section	.text$_ZN14CPolyAllocator12setAllocInfoEPK10ALLOC_INFO,"x"
	.linkonce discard
	.globl	__ZN14CPolyAllocator12setAllocInfoEPK10ALLOC_INFO
	.def	__ZN14CPolyAllocator12setAllocInfoEPK10ALLOC_INFO;	.scl	2;	.type	32;	.endef
__ZN14CPolyAllocator12setAllocInfoEPK10ALLOC_INFO:
LFB805:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$___emutls_v._ZN14CPolyAllocator11m_allocInfoE, (%esp)
	call	___emutls_get_address
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE805:
	.section	.text$_ZN14CPolyAllocatorC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPolyAllocatorC2Ev
	.def	__ZN14CPolyAllocatorC2Ev;	.scl	2;	.type	32;	.endef
__ZN14CPolyAllocatorC2Ev:
LFB807:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	$___emutls_v._ZN14CPolyAllocator11m_allocatorE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L869
	movl	$4, (%esp)
	call	__ZN12CStdAllocAdpnwEj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L872
	movl	%ebx, (%esp)
	call	__ZN12CStdAllocAdpC1Ev
L872:
	movl	$___emutls_v._ZN14CPolyAllocator11m_allocatorE, (%esp)
	call	___emutls_get_address
	movl	%ebx, (%eax)
L869:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE807:
	.section	.text$_ZN14CPolyAllocatorC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPolyAllocatorC1Ev
	.def	__ZN14CPolyAllocatorC1Ev;	.scl	2;	.type	32;	.endef
__ZN14CPolyAllocatorC1Ev:
LFB808:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	$___emutls_v._ZN14CPolyAllocator11m_allocatorE, (%esp)
	call	___emutls_get_address
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L873
	movl	$4, (%esp)
	call	__ZN12CStdAllocAdpnwEj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L876
	movl	%ebx, (%esp)
	call	__ZN12CStdAllocAdpC1Ev
L876:
	movl	$___emutls_v._ZN14CPolyAllocator11m_allocatorE, (%esp)
	call	___emutls_get_address
	movl	%ebx, (%eax)
L873:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE808:
	.section	.text$_ZN14CPolyAllocatorD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPolyAllocatorD2Ev
	.def	__ZN14CPolyAllocatorD2Ev;	.scl	2;	.type	32;	.endef
__ZN14CPolyAllocatorD2Ev:
LFB810:
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
LFE810:
	.section	.text$_ZN14CPolyAllocatorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPolyAllocatorD1Ev
	.def	__ZN14CPolyAllocatorD1Ev;	.scl	2;	.type	32;	.endef
__ZN14CPolyAllocatorD1Ev:
LFB811:
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
LFE811:
	.section	.text$_ZN10ALLOC_INFOC1EPKcS1_S1_fS1_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10ALLOC_INFOC1EPKcS1_S1_fS1_j
	.def	__ZN10ALLOC_INFOC1EPKcS1_S1_fS1_j;	.scl	2;	.type	32;	.endef
__ZN10ALLOC_INFOC1EPKcS1_S1_fS1_j:
LFB814:
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
	movl	8(%ebp), %eax
	movl	20(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %edx
	movl	24(%ebp), %eax
	movl	%eax, 12(%edx)
	movl	8(%ebp), %eax
	movl	28(%ebp), %edx
	movl	%edx, 16(%eax)
	movl	8(%ebp), %eax
	movl	32(%ebp), %edx
	movl	%edx, 20(%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE814:
	.section .rdata,"dr"
	.align 4
LC163:
	.ascii "new(size=%d, poly_allocator=\"%s\":%d/%d/%d)\12\0"
	.align 4
LC164:
	.ascii "  fileName=\"%s\", funcName=\"%s\", callPointName=\"%s\", time=%.3f, typename=\"%s\", align=%d\12\0"
	.text
	.globl	__Znwj
	.def	__Znwj;	.scl	2;	.type	32;	.endef
__Znwj:
LFB815:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA815
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
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorC1Ev
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$12, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
LEHB183:
	call	*%edx
	movl	%eax, %edi
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$8, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, %esi
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$4, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, %ebx
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC163, (%esp)
	call	_printf
	movl	$4, -28(%ebp)
	call	__ZN14CPolyAllocator21getAllocInfoWithResetEv
	movl	%eax, -32(%ebp)
	cmpl	$0, -32(%ebp)
	je	L883
	movl	-32(%ebp), %eax
	movl	20(%eax), %eax
	movl	%eax, -28(%ebp)
	movl	-32(%ebp), %eax
	movl	20(%eax), %esi
	movl	-32(%ebp), %eax
	movl	16(%eax), %ebx
	movl	-32(%ebp), %eax
	flds	12(%eax)
	movl	-32(%ebp), %eax
	movl	8(%eax), %ecx
	movl	-32(%ebp), %eax
	movl	4(%eax), %edx
	movl	-32(%ebp), %eax
	movl	(%eax), %eax
	movl	%esi, 28(%esp)
	movl	%ebx, 24(%esp)
	fstpl	16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC164, (%esp)
	call	_printf
L883:
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$16, %edx
	movl	(%edx), %edx
	movl	$0, 12(%esp)
	movl	-28(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	8(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
LEHE183:
	movl	-36(%ebp), %ebx
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorD1Ev
	movl	%ebx, %eax
	jmp	L887
L886:
	movl	%eax, %ebx
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB184:
	call	__Unwind_Resume
LEHE184:
L887:
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
LFE815:
	.section	.gcc_except_table,"w"
LLSDA815:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE815-LLSDACSB815
LLSDACSB815:
	.uleb128 LEHB183-LFB815
	.uleb128 LEHE183-LEHB183
	.uleb128 L886-LFB815
	.uleb128 0
	.uleb128 LEHB184-LFB815
	.uleb128 LEHE184-LEHB184
	.uleb128 0
	.uleb128 0
LLSDACSE815:
	.text
	.section .rdata,"dr"
	.align 4
LC166:
	.ascii "new[](size=%d, poly_allocator=\"%s\":%d/%d/%d)\12\0"
	.text
	.globl	__Znaj
	.def	__Znaj;	.scl	2;	.type	32;	.endef
__Znaj:
LFB816:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA816
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
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorC1Ev
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$12, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
LEHB185:
	call	*%edx
	movl	%eax, %edi
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$8, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, %esi
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$4, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, %ebx
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC166, (%esp)
	call	_printf
	movl	$4, -28(%ebp)
	call	__ZN14CPolyAllocator21getAllocInfoWithResetEv
	movl	%eax, -32(%ebp)
	cmpl	$0, -32(%ebp)
	je	L889
	movl	-32(%ebp), %eax
	movl	20(%eax), %eax
	movl	%eax, -28(%ebp)
	movl	-32(%ebp), %eax
	movl	20(%eax), %esi
	movl	-32(%ebp), %eax
	movl	16(%eax), %ebx
	movl	-32(%ebp), %eax
	flds	12(%eax)
	movl	-32(%ebp), %eax
	movl	8(%eax), %ecx
	movl	-32(%ebp), %eax
	movl	4(%eax), %edx
	movl	-32(%ebp), %eax
	movl	(%eax), %eax
	movl	%esi, 28(%esp)
	movl	%ebx, 24(%esp)
	fstpl	16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC164, (%esp)
	call	_printf
L889:
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$16, %edx
	movl	(%edx), %edx
	movl	$0, 12(%esp)
	movl	-28(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	8(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
LEHE185:
	movl	-36(%ebp), %ebx
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorD1Ev
	movl	%ebx, %eax
	jmp	L893
L892:
	movl	%eax, %ebx
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB186:
	call	__Unwind_Resume
LEHE186:
L893:
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
LFE816:
	.section	.gcc_except_table,"w"
LLSDA816:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE816-LLSDACSB816
LLSDACSB816:
	.uleb128 LEHB185-LFB816
	.uleb128 LEHE185-LEHB185
	.uleb128 L892-LFB816
	.uleb128 0
	.uleb128 LEHB186-LFB816
	.uleb128 LEHE186-LEHB186
	.uleb128 0
	.uleb128 0
LLSDACSE816:
	.text
	.section .rdata,"dr"
	.align 4
LC167:
	.ascii "delete(p=0x%p, poly_allocator=\"%s\":%d/%d/%d)\12\0"
	.text
	.globl	__ZdlPv
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
__ZdlPv:
LFB817:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA817
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
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorC1Ev
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$12, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, %edi
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$8, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, %esi
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$4, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, %ebx
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC167, (%esp)
	call	_printf
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$20, %edx
	movl	(%edx), %edx
	movl	8(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorD1Ev
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
LFE817:
	.section	.gcc_except_table,"w"
LLSDA817:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE817-LLSDACSB817
LLSDACSB817:
LLSDACSE817:
	.text
	.section .rdata,"dr"
	.align 4
LC168:
	.ascii "delete[](p=0x%p, poly_allocator=\"%s\":%d/%d/%d)\12\0"
	.text
	.globl	__ZdaPv
	.def	__ZdaPv;	.scl	2;	.type	32;	.endef
__ZdaPv:
LFB818:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA818
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
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorC1Ev
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$12, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, %edi
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$8, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, %esi
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$4, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, %ebx
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC168, (%esp)
	call	_printf
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$20, %edx
	movl	(%edx), %edx
	movl	8(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorD1Ev
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
LFE818:
	.section	.gcc_except_table,"w"
LLSDA818:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE818-LLSDACSB818
LLSDACSB818:
LLSDACSE818:
	.text
	.section .rdata,"dr"
LC169:
	.ascii "(unknown call-point)\0"
	.text
	.globl	__Z28getCurrentCallPointNameDummyv
	.def	__Z28getCurrentCallPointNameDummyv;	.scl	2;	.type	32;	.endef
__Z28getCurrentCallPointNameDummyv:
LFB819:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$LC169, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE819:
	.globl	__Z16getGameTimeDummyv
	.def	__Z16getGameTimeDummyv;	.scl	2;	.type	32;	.endef
__Z16getGameTimeDummyv:
LFB820:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	LC170, %eax
	movl	%eax, -4(%ebp)
	flds	-4(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE820:
	.section	.text$_Z25getConstFileNameRecursivePKcj,"x"
	.linkonce discard
	.globl	__Z25getConstFileNameRecursivePKcj
	.def	__Z25getConstFileNameRecursivePKcj;	.scl	2;	.type	32;	.endef
__Z25getConstFileNameRecursivePKcj:
LFB821:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	je	L901
	movl	12(%ebp), %eax
	leal	-1(%eax), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$92, %al
	je	L902
	movl	12(%ebp), %eax
	leal	-1(%eax), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$47, %al
	jne	L903
L902:
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	addl	%edx, %eax
	jmp	L904
L903:
	movl	12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25getConstFileNameRecursivePKcj
L904:
	jmp	L905
L901:
	movl	8(%ebp), %eax
L905:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE821:
	.section	.text$_Z16getConstFileNamePKc,"x"
	.linkonce discard
	.globl	__Z16getConstFileNamePKc
	.def	__Z16getConstFileNamePKc;	.scl	2;	.type	32;	.endef
__Z16getConstFileNamePKc:
LFB822:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25getConstFileNameRecursivePKcj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE822:
	.section	.text$_ZN22CTempPolyAllocatorBaseC2ER10IAllocator,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CTempPolyAllocatorBaseC2ER10IAllocator
	.def	__ZN22CTempPolyAllocatorBaseC2ER10IAllocator;	.scl	2;	.type	32;	.endef
__ZN22CTempPolyAllocatorBaseC2ER10IAllocator:
LFB826:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorC2Ev
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocator12setAllocatorER10IAllocator
	movl	8(%ebp), %edx
	movl	%eax, (%edx)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE826:
	.section	.text$_ZN22CTempPolyAllocatorBaseD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CTempPolyAllocatorBaseD2Ev
	.def	__ZN22CTempPolyAllocatorBaseD2Ev;	.scl	2;	.type	32;	.endef
__ZN22CTempPolyAllocatorBaseD2Ev:
LFB829:
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
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L911
	movl	8(%ebp), %eax
	movl	(%eax), %ebx
	movl	$___emutls_v._ZN14CPolyAllocator11m_allocatorE, (%esp)
	call	___emutls_get_address
	movl	%ebx, (%eax)
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L911:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorD2Ev
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE829:
	.section	.text$_ZN24CTempPolyIStackAllocatorC1ER15IStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN24CTempPolyIStackAllocatorC1ER15IStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
	.def	__ZN24CTempPolyIStackAllocatorC1ER15IStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE;	.scl	2;	.type	32;	.endef
__ZN24CTempPolyIStackAllocatorC1ER15IStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE:
LFB842:
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
	call	__ZN30CTempPolyAllocatorWithStackAdpI15CIStackAllocAdpEC2ER15IStackAllocatorNS0_13E_AUTO_REWINDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE842:
	.section	.text$_ZN24CTempPolyIStackAllocatorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN24CTempPolyIStackAllocatorD1Ev
	.def	__ZN24CTempPolyIStackAllocatorD1Ev;	.scl	2;	.type	32;	.endef
__ZN24CTempPolyIStackAllocatorD1Ev:
LFB845:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN30CTempPolyAllocatorWithStackAdpI15CIStackAllocAdpED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE845:
	.section	.text$_ZN23CTempPolyStackAllocatorC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CTempPolyStackAllocatorC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
	.def	__ZN23CTempPolyStackAllocatorC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE;	.scl	2;	.type	32;	.endef
__ZN23CTempPolyStackAllocatorC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE:
LFB848:
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
	call	__ZN30CTempPolyAllocatorWithStackAdpI14CStackAllocAdpEC2ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE848:
	.section	.text$_ZN23CTempPolyStackAllocatorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CTempPolyStackAllocatorD1Ev
	.def	__ZN23CTempPolyStackAllocatorD1Ev;	.scl	2;	.type	32;	.endef
__ZN23CTempPolyStackAllocatorD1Ev:
LFB851:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN30CTempPolyAllocatorWithStackAdpI14CStackAllocAdpED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE851:
	.section	.text$_ZN27CTempPolyDualStackAllocatorC1ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN27CTempPolyDualStackAllocatorC1ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE
	.def	__ZN27CTempPolyDualStackAllocatorC1ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE;	.scl	2;	.type	32;	.endef
__ZN27CTempPolyDualStackAllocatorC1ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE:
LFB854:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	20(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN30CTempPolyAllocatorWithStackAdpI18CDualStackAllocAdpEC2ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE854:
	.section	.text$_ZN27CTempPolyDualStackAllocatorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN27CTempPolyDualStackAllocatorD1Ev
	.def	__ZN27CTempPolyDualStackAllocatorD1Ev;	.scl	2;	.type	32;	.endef
__ZN27CTempPolyDualStackAllocatorD1Ev:
LFB857:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN30CTempPolyAllocatorWithStackAdpI18CDualStackAllocAdpED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE857:
	.section .rdata,"dr"
	.align 4
LC171:
	.ascii "CTest7::DefaultConstructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest7C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest7C1Ev
	.def	__ZN6CTest7C1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest7C1Ev:
LFB860:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA860
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	$LC10, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB187:
	call	__ZN6CTest7C1EPKc
LEHE187:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC171, (%esp)
LEHB188:
	call	_printf
LEHE188:
	jmp	L925
L924:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest7D1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB189:
	call	__Unwind_Resume
LEHE189:
L925:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE860:
	.section	.gcc_except_table,"w"
LLSDA860:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE860-LLSDACSB860
LLSDACSB860:
	.uleb128 LEHB187-LFB860
	.uleb128 LEHE187-LEHB187
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB188-LFB860
	.uleb128 LEHE188-LEHB188
	.uleb128 L924-LFB860
	.uleb128 0
	.uleb128 LEHB189-LFB860
	.uleb128 LEHE189-LEHB189
	.uleb128 0
	.uleb128 0
LLSDACSE860:
	.section	.text$_ZN6CTest7C1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC172:
	.ascii "CTest7::Constructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest7C2EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest7C2EPKc
	.def	__ZN6CTest7C2EPKc;	.scl	2;	.type	32;	.endef
__ZN6CTest7C2EPKc:
LFB862:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV6CTest7+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC172, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE862:
	.section	.text$_ZN6CTest7C1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest7C1EPKc
	.def	__ZN6CTest7C1EPKc;	.scl	2;	.type	32;	.endef
__ZN6CTest7C1EPKc:
LFB863:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV6CTest7+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC172, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE863:
	.section .rdata,"dr"
	.align 4
LC173:
	.ascii "CTest7::Destructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest7D2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest7D2Ev
	.def	__ZN6CTest7D2Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest7D2Ev:
LFB865:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA865
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV6CTest7+8, (%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC173, (%esp)
	call	_printf
	movl	$0, %eax
	testl	%eax, %eax
	je	L928
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L928:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE865:
	.section	.gcc_except_table,"w"
LLSDA865:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE865-LLSDACSB865
LLSDACSB865:
LLSDACSE865:
	.section	.text$_ZN6CTest7D2Ev,"x"
	.linkonce discard
	.section	.text$_ZN6CTest7D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest7D1Ev
	.def	__ZN6CTest7D1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest7D1Ev:
LFB866:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA866
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV6CTest7+8, (%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC173, (%esp)
	call	_printf
	movl	$0, %eax
	testl	%eax, %eax
	je	L931
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L931:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE866:
	.section	.gcc_except_table,"w"
LLSDA866:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE866-LLSDACSB866
LLSDACSB866:
LLSDACSE866:
	.section	.text$_ZN6CTest7D1Ev,"x"
	.linkonce discard
	.section	.text$_ZN6CTest7D0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest7D0Ev
	.def	__ZN6CTest7D0Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest7D0Ev:
LFB867:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest7D1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE867:
	.section .rdata,"dr"
LC174:
	.ascii "CTest7ex::Constructor\0"
	.section	.text$_ZN8CTest7exC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest7exC2Ev
	.def	__ZN8CTest7exC2Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest7exC2Ev:
LFB869:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV8CTest7ex+8, (%eax)
	movl	$LC174, (%esp)
	call	_puts
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE869:
	.section .rdata,"dr"
LC175:
	.ascii "CTest7ex::Destructor\0"
	.section	.text$_ZN8CTest7exD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest7exD2Ev
	.def	__ZN8CTest7exD2Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest7exD2Ev:
LFB872:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA872
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV8CTest7ex+8, (%eax)
	movl	$LC175, (%esp)
	call	_puts
	movl	$0, %eax
	testl	%eax, %eax
	je	L937
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L937:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE872:
	.section	.gcc_except_table,"w"
LLSDA872:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE872-LLSDACSB872
LLSDACSB872:
LLSDACSE872:
	.section	.text$_ZN8CTest7exD2Ev,"x"
	.linkonce discard
	.section	.text$_ZN8CTest7exD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest7exD1Ev
	.def	__ZN8CTest7exD1Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest7exD1Ev:
LFB873:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA873
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV8CTest7ex+8, (%eax)
	movl	$LC175, (%esp)
	call	_puts
	movl	$0, %eax
	testl	%eax, %eax
	je	L940
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L940:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE873:
	.section	.gcc_except_table,"w"
LLSDA873:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE873-LLSDACSB873
LLSDACSB873:
LLSDACSE873:
	.section	.text$_ZN8CTest7exD1Ev,"x"
	.linkonce discard
	.section	.text$_ZN8CTest7exD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest7exD0Ev
	.def	__ZN8CTest7exD0Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest7exD0Ev:
LFB874:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN8CTest7exD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE874:
	.section .rdata,"dr"
	.align 4
LC176:
	.ascii "CDerivedTest7::Constructor : name=\"%s\"\12\0"
	.section	.text$_ZN13CDerivedTest7C1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CDerivedTest7C1EPKc
	.def	__ZN13CDerivedTest7C1EPKc;	.scl	2;	.type	32;	.endef
__ZN13CDerivedTest7C1EPKc:
LFB880:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA880
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB190:
	call	__ZN6CTest7C2EPKc
LEHE190:
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
LEHB191:
	call	__ZN8CTest7exC2Ev
LEHE191:
	movl	8(%ebp), %eax
	movl	$__ZTV13CDerivedTest7+8, (%eax)
	movl	8(%ebp), %eax
	movl	$__ZTV13CDerivedTest7+24, 12(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC176, (%esp)
LEHB192:
	call	_printf
LEHE192:
	jmp	L950
L949:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__ZN8CTest7exD2Ev
	jmp	L947
L948:
	movl	%eax, %ebx
L947:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest7D2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB193:
	call	__Unwind_Resume
LEHE193:
L950:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE880:
	.section	.gcc_except_table,"w"
LLSDA880:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE880-LLSDACSB880
LLSDACSB880:
	.uleb128 LEHB190-LFB880
	.uleb128 LEHE190-LEHB190
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB191-LFB880
	.uleb128 LEHE191-LEHB191
	.uleb128 L948-LFB880
	.uleb128 0
	.uleb128 LEHB192-LFB880
	.uleb128 LEHE192-LEHB192
	.uleb128 L949-LFB880
	.uleb128 0
	.uleb128 LEHB193-LFB880
	.uleb128 LEHE193-LEHB193
	.uleb128 0
	.uleb128 0
LLSDACSE880:
	.section	.text$_ZN13CDerivedTest7C1EPKc,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC177:
	.ascii "CDerivedTest7::Destructor : name=\"%s\"\12\0"
	.section	.text$_ZN13CDerivedTest7D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CDerivedTest7D1Ev
	.def	__ZN13CDerivedTest7D1Ev;	.scl	2;	.type	32;	.endef
__ZN13CDerivedTest7D1Ev:
LFB883:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA883
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV13CDerivedTest7+8, (%eax)
	movl	8(%ebp), %eax
	movl	$__ZTV13CDerivedTest7+24, 12(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC177, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__ZN8CTest7exD2Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest7D2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L951
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L951:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE883:
	.section	.gcc_except_table,"w"
LLSDA883:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE883-LLSDACSB883
LLSDACSB883:
LLSDACSE883:
	.section	.text$_ZN13CDerivedTest7D1Ev,"x"
	.linkonce discard
	.section	.text$_ZThn12_N13CDerivedTest7D1Ev,"x"
	.linkonce discard
	.globl	__ZThn12_N13CDerivedTest7D1Ev
	.def	__ZThn12_N13CDerivedTest7D1Ev;	.scl	2;	.type	32;	.endef
__ZThn12_N13CDerivedTest7D1Ev:
LFB3875:
	.cfi_startproc
	subl	$12, 4(%esp)
	jmp	__ZN13CDerivedTest7D1Ev
	.cfi_endproc
LFE3875:
	.section	.text$_ZN13CDerivedTest7D0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CDerivedTest7D0Ev
	.def	__ZN13CDerivedTest7D0Ev;	.scl	2;	.type	32;	.endef
__ZN13CDerivedTest7D0Ev:
LFB884:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CDerivedTest7D1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE884:
	.section	.text$_ZThn12_N13CDerivedTest7D0Ev,"x"
	.linkonce discard
	.globl	__ZThn12_N13CDerivedTest7D0Ev
	.def	__ZThn12_N13CDerivedTest7D0Ev;	.scl	2;	.type	32;	.endef
__ZThn12_N13CDerivedTest7D0Ev:
LFB3876:
	.cfi_startproc
	subl	$12, 4(%esp)
	jmp	__ZN13CDerivedTest7D0Ev
	.cfi_endproc
LFE3876:
	.section .rdata,"dr"
	.align 4
LC178:
	.ascii "allocator.cpp(3087) [Wed Feb 26 17:31:29 2014]\0"
	.text
	.globl	__Z10test7_sub1PKc
	.def	__Z10test7_sub1PKc;	.scl	2;	.type	32;	.endef
__Z10test7_sub1PKc:
LFB885:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC178, (%esp)
	call	__Z16getConstFileNamePKc
	movl	8(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	$4, 8(%esp)
	movl	$__ZZ10test7_sub1PKcE19__PRETTY_FUNCTION__, 4(%esp)
	movl	%eax, (%esp)
	call	__Z11newWithInfoI6CTest7IPKcEEPT_S2_S2_jDpT0_
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	cmpl	$0, -12(%ebp)
	je	L956
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
L956:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE885:
	.section .rdata,"dr"
	.align 4
LC179:
	.ascii "allocator.cpp(3100) [Wed Feb 26 17:31:29 2014]\0"
	.text
	.globl	__Z10test7_sub2v
	.def	__Z10test7_sub2v;	.scl	2;	.type	32;	.endef
__Z10test7_sub2v:
LFB886:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	$LC179, (%esp)
	call	__Z16getConstFileNamePKc
	movl	$4, 8(%esp)
	movl	$__ZZ10test7_sub2vE19__PRETTY_FUNCTION__, 4(%esp)
	movl	%eax, (%esp)
	call	__Z16newArrayWithInfoI6CTest7Lj3EEPT_PKcS4_j
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	cmpl	$0, -12(%ebp)
	je	L958
	movl	-12(%ebp), %eax
	subl	$4, %eax
	movl	(%eax), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	leal	(%edx,%eax), %ebx
L961:
	cmpl	-12(%ebp), %ebx
	je	L960
	subl	$12, %ebx
	movl	(%ebx), %eax
	movl	(%eax), %eax
	movl	%ebx, (%esp)
	call	*%eax
	jmp	L961
L960:
	movl	-12(%ebp), %eax
	subl	$4, %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L958:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE886:
	.section .rdata,"dr"
	.align 4
LC180:
	.ascii "allocator.cpp(3113) [Wed Feb 26 17:31:29 2014]\0"
	.text
	.globl	__Z10test7_sub3PKc
	.def	__Z10test7_sub3PKc;	.scl	2;	.type	32;	.endef
__Z10test7_sub3PKc:
LFB887:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC180, (%esp)
	call	__Z16getConstFileNamePKc
	movl	8(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	$4, 8(%esp)
	movl	$__ZZ10test7_sub3PKcE19__PRETTY_FUNCTION__, 4(%esp)
	movl	%eax, (%esp)
	call	__Z11newWithInfoI13CDerivedTest7IPKcEEPT_S2_S2_jDpT0_
	testl	%eax, %eax
	je	L963
	addl	$12, %eax
	jmp	L964
L963:
	movl	$0, %eax
L964:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	cmpl	$0, -12(%ebp)
	je	L962
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
L962:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE887:
	.section .rdata,"dr"
	.align 4
LC181:
	.ascii "---------- test7:\343\202\260\343\203\255\343\203\274\343\203\220\343\203\253new/delete + \345\205\261\351\200\232\343\202\242\343\203\255\343\202\261\343\203\274\343\202\277\343\202\244\343\203\263\343\202\277\343\203\274\343\203\225\343\202\247\343\203\274\343\202\271 ----------\0"
LC182:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-1a\0"
LC183:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-1b\0"
LC184:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-2a\0"
LC185:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-2b\0"
LC186:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-3a\0"
LC187:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-3b\0"
LC188:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-4a\0"
LC189:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-4b\0"
LC190:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-5a\0"
LC191:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-5b\0"
LC192:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-6a\0"
LC193:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-6b\0"
LC194:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-7a\0"
LC195:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-7b\0"
	.text
	.globl	__Z5test7v
	.def	__Z5test7v;	.scl	2;	.type	32;	.endef
__Z5test7v:
LFB888:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA888
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$756, %esp
	.cfi_offset 3, -12
	movl	$LC181, (%esp)
LEHB194:
	call	_puts
LEHE194:
	movl	$LC143, (%esp)
LEHB195:
	call	_puts
LEHE195:
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN25CTempPolyAllocatorWithAdpI12CStdAllocAdpEC1Ev
	movl	$LC182, (%esp)
LEHB196:
	call	__Z10test7_sub1PKc
	call	__Z10test7_sub2v
	movl	$LC183, (%esp)
	call	__Z10test7_sub3PKc
LEHE196:
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN25CTempPolyAllocatorWithAdpI12CStdAllocAdpED1Ev
	movl	$LC145, (%esp)
LEHB197:
	call	_puts
LEHE197:
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN21CMonoAllocAdpWithBuffILj128EEC1Ev
	leal	-736(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN24CTempPolyAllocatorDirectI13CMonoAllocAdpEC1ERS0_
	movl	$LC184, (%esp)
LEHB198:
	call	__Z10test7_sub1PKc
	call	__Z10test7_sub2v
	movl	$LC185, (%esp)
	call	__Z10test7_sub3PKc
LEHE198:
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN24CTempPolyAllocatorDirectI13CMonoAllocAdpED1Ev
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN21CMonoAllocAdpWithBuffILj128EED1Ev
	movl	$LC148, (%esp)
LEHB199:
	call	_puts
LEHE199:
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj128EEC1Ev
	movl	$0, 8(%esp)
	leal	-736(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
LEHB200:
	call	__ZN23CTempPolyStackAllocatorC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE200:
	movl	$LC186, (%esp)
LEHB201:
	call	__Z10test7_sub1PKc
LEHE201:
	movl	$1, 8(%esp)
	leal	-736(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
LEHB202:
	call	__ZN23CTempPolyStackAllocatorC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE202:
LEHB203:
	call	__Z10test7_sub2v
LEHE203:
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorD1Ev
	movl	$LC187, (%esp)
LEHB204:
	call	__Z10test7_sub3PKc
LEHE204:
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorD1Ev
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj128EED1Ev
	movl	$LC151, (%esp)
LEHB205:
	call	_puts
LEHE205:
	movl	$1, 4(%esp)
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj128EEC1EN15IStackAllocator9E_ORDEREDE
	movl	$0, 12(%esp)
	movl	$-1, 8(%esp)
	leal	-736(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
LEHB206:
	call	__ZN27CTempPolyDualStackAllocatorC1ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE206:
	movl	$LC188, (%esp)
LEHB207:
	call	__Z10test7_sub1PKc
LEHE207:
	movl	$1, 12(%esp)
	movl	$-1, 8(%esp)
	leal	-736(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-116(%ebp), %eax
	movl	%eax, (%esp)
LEHB208:
	call	__ZN27CTempPolyDualStackAllocatorC1ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE208:
LEHB209:
	call	__Z10test7_sub2v
LEHE209:
	leal	-116(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CTempPolyDualStackAllocatorD1Ev
	movl	$LC189, (%esp)
LEHB210:
	call	__Z10test7_sub3PKc
LEHE210:
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CTempPolyDualStackAllocatorD1Ev
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj128EED1Ev
	movl	$LC154, (%esp)
LEHB211:
	call	_puts
LEHE211:
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj128EEC1Ev
	movl	$0, 8(%esp)
	leal	-736(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-136(%ebp), %eax
	movl	%eax, (%esp)
LEHB212:
	call	__ZN24CTempPolyIStackAllocatorC1ER15IStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE212:
	movl	$LC190, (%esp)
LEHB213:
	call	__Z10test7_sub1PKc
LEHE213:
	movl	$1, 8(%esp)
	leal	-736(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
LEHB214:
	call	__ZN24CTempPolyIStackAllocatorC1ER15IStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE214:
LEHB215:
	call	__Z10test7_sub2v
LEHE215:
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN24CTempPolyIStackAllocatorD1Ev
	movl	$LC191, (%esp)
LEHB216:
	call	__Z10test7_sub3PKc
LEHE216:
	leal	-136(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN24CTempPolyIStackAllocatorD1Ev
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj128EED1Ev
	movl	$LC157, (%esp)
LEHB217:
	call	_puts
LEHE217:
	movl	$1, 4(%esp)
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj128EEC1EN15IStackAllocator9E_ORDEREDE
	movl	$0, 8(%esp)
	leal	-736(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
LEHB218:
	call	__ZN24CTempPolyIStackAllocatorC1ER15IStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE218:
	movl	$LC192, (%esp)
LEHB219:
	call	__Z10test7_sub1PKc
LEHE219:
	movl	$1, 8(%esp)
	leal	-736(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-196(%ebp), %eax
	movl	%eax, (%esp)
LEHB220:
	call	__ZN24CTempPolyIStackAllocatorC1ER15IStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE220:
LEHB221:
	call	__Z10test7_sub2v
LEHE221:
	leal	-196(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN24CTempPolyIStackAllocatorD1Ev
	movl	$LC193, (%esp)
LEHB222:
	call	__Z10test7_sub3PKc
LEHE222:
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN24CTempPolyIStackAllocatorD1Ev
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj128EED1Ev
	movl	$LC160, (%esp)
LEHB223:
	call	_puts
LEHE223:
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithBuffILj24ELi5EEC1Ev
	leal	-736(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-208(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN25CTempPolyAllocatorWithAdpI13CPoolAllocAdpEC1ER14CPoolAllocator
	movl	$LC194, (%esp)
LEHB224:
	call	__Z10test7_sub1PKc
	call	__Z10test7_sub2v
	movl	$LC195, (%esp)
	call	__Z10test7_sub3PKc
LEHE224:
	leal	-208(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN25CTempPolyAllocatorWithAdpI13CPoolAllocAdpED1Ev
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithBuffILj24ELi5EED1Ev
	jmp	L1019
L994:
	movl	%eax, %ebx
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN25CTempPolyAllocatorWithAdpI12CStdAllocAdpED1Ev
	movl	%ebx, %eax
	jmp	L968
L993:
L968:
	movl	%eax, (%esp)
LEHB225:
	call	__Unwind_Resume
L996:
	movl	%eax, %ebx
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN24CTempPolyAllocatorDirectI13CMonoAllocAdpED1Ev
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN21CMonoAllocAdpWithBuffILj128EED1Ev
	movl	%ebx, %eax
	jmp	L970
L995:
L970:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L1001:
	movl	%eax, %ebx
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorD1Ev
	movl	%ebx, %eax
	jmp	L972
L1000:
L972:
	movl	%eax, %ebx
	jmp	L973
L999:
	movl	%eax, %ebx
L973:
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorD1Ev
	jmp	L974
L998:
	movl	%eax, %ebx
L974:
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj128EED1Ev
	movl	%ebx, %eax
	jmp	L975
L997:
L975:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L1006:
	movl	%eax, %ebx
	leal	-116(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CTempPolyDualStackAllocatorD1Ev
	movl	%ebx, %eax
	jmp	L977
L1005:
L977:
	movl	%eax, %ebx
	jmp	L978
L1004:
	movl	%eax, %ebx
L978:
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CTempPolyDualStackAllocatorD1Ev
	jmp	L979
L1003:
	movl	%eax, %ebx
L979:
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj128EED1Ev
	movl	%ebx, %eax
	jmp	L980
L1002:
L980:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L1011:
	movl	%eax, %ebx
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN24CTempPolyIStackAllocatorD1Ev
	movl	%ebx, %eax
	jmp	L982
L1010:
L982:
	movl	%eax, %ebx
	jmp	L983
L1009:
	movl	%eax, %ebx
L983:
	leal	-136(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN24CTempPolyIStackAllocatorD1Ev
	jmp	L984
L1008:
	movl	%eax, %ebx
L984:
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj128EED1Ev
	movl	%ebx, %eax
	jmp	L985
L1007:
L985:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L1016:
	movl	%eax, %ebx
	leal	-196(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN24CTempPolyIStackAllocatorD1Ev
	movl	%ebx, %eax
	jmp	L987
L1015:
L987:
	movl	%eax, %ebx
	jmp	L988
L1014:
	movl	%eax, %ebx
L988:
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN24CTempPolyIStackAllocatorD1Ev
	jmp	L989
L1013:
	movl	%eax, %ebx
L989:
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj128EED1Ev
	movl	%ebx, %eax
	jmp	L990
L1012:
L990:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L1018:
	movl	%eax, %ebx
	leal	-208(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN25CTempPolyAllocatorWithAdpI13CPoolAllocAdpED1Ev
	leal	-736(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithBuffILj24ELi5EED1Ev
	movl	%ebx, %eax
	jmp	L992
L1017:
L992:
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE225:
L1019:
	addl	$756, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE888:
	.section	.gcc_except_table,"w"
LLSDA888:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE888-LLSDACSB888
LLSDACSB888:
	.uleb128 LEHB194-LFB888
	.uleb128 LEHE194-LEHB194
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB195-LFB888
	.uleb128 LEHE195-LEHB195
	.uleb128 L993-LFB888
	.uleb128 0
	.uleb128 LEHB196-LFB888
	.uleb128 LEHE196-LEHB196
	.uleb128 L994-LFB888
	.uleb128 0
	.uleb128 LEHB197-LFB888
	.uleb128 LEHE197-LEHB197
	.uleb128 L995-LFB888
	.uleb128 0
	.uleb128 LEHB198-LFB888
	.uleb128 LEHE198-LEHB198
	.uleb128 L996-LFB888
	.uleb128 0
	.uleb128 LEHB199-LFB888
	.uleb128 LEHE199-LEHB199
	.uleb128 L997-LFB888
	.uleb128 0
	.uleb128 LEHB200-LFB888
	.uleb128 LEHE200-LEHB200
	.uleb128 L998-LFB888
	.uleb128 0
	.uleb128 LEHB201-LFB888
	.uleb128 LEHE201-LEHB201
	.uleb128 L999-LFB888
	.uleb128 0
	.uleb128 LEHB202-LFB888
	.uleb128 LEHE202-LEHB202
	.uleb128 L1000-LFB888
	.uleb128 0
	.uleb128 LEHB203-LFB888
	.uleb128 LEHE203-LEHB203
	.uleb128 L1001-LFB888
	.uleb128 0
	.uleb128 LEHB204-LFB888
	.uleb128 LEHE204-LEHB204
	.uleb128 L999-LFB888
	.uleb128 0
	.uleb128 LEHB205-LFB888
	.uleb128 LEHE205-LEHB205
	.uleb128 L1002-LFB888
	.uleb128 0
	.uleb128 LEHB206-LFB888
	.uleb128 LEHE206-LEHB206
	.uleb128 L1003-LFB888
	.uleb128 0
	.uleb128 LEHB207-LFB888
	.uleb128 LEHE207-LEHB207
	.uleb128 L1004-LFB888
	.uleb128 0
	.uleb128 LEHB208-LFB888
	.uleb128 LEHE208-LEHB208
	.uleb128 L1005-LFB888
	.uleb128 0
	.uleb128 LEHB209-LFB888
	.uleb128 LEHE209-LEHB209
	.uleb128 L1006-LFB888
	.uleb128 0
	.uleb128 LEHB210-LFB888
	.uleb128 LEHE210-LEHB210
	.uleb128 L1004-LFB888
	.uleb128 0
	.uleb128 LEHB211-LFB888
	.uleb128 LEHE211-LEHB211
	.uleb128 L1007-LFB888
	.uleb128 0
	.uleb128 LEHB212-LFB888
	.uleb128 LEHE212-LEHB212
	.uleb128 L1008-LFB888
	.uleb128 0
	.uleb128 LEHB213-LFB888
	.uleb128 LEHE213-LEHB213
	.uleb128 L1009-LFB888
	.uleb128 0
	.uleb128 LEHB214-LFB888
	.uleb128 LEHE214-LEHB214
	.uleb128 L1010-LFB888
	.uleb128 0
	.uleb128 LEHB215-LFB888
	.uleb128 LEHE215-LEHB215
	.uleb128 L1011-LFB888
	.uleb128 0
	.uleb128 LEHB216-LFB888
	.uleb128 LEHE216-LEHB216
	.uleb128 L1009-LFB888
	.uleb128 0
	.uleb128 LEHB217-LFB888
	.uleb128 LEHE217-LEHB217
	.uleb128 L1012-LFB888
	.uleb128 0
	.uleb128 LEHB218-LFB888
	.uleb128 LEHE218-LEHB218
	.uleb128 L1013-LFB888
	.uleb128 0
	.uleb128 LEHB219-LFB888
	.uleb128 LEHE219-LEHB219
	.uleb128 L1014-LFB888
	.uleb128 0
	.uleb128 LEHB220-LFB888
	.uleb128 LEHE220-LEHB220
	.uleb128 L1015-LFB888
	.uleb128 0
	.uleb128 LEHB221-LFB888
	.uleb128 LEHE221-LEHB221
	.uleb128 L1016-LFB888
	.uleb128 0
	.uleb128 LEHB222-LFB888
	.uleb128 LEHE222-LEHB222
	.uleb128 L1014-LFB888
	.uleb128 0
	.uleb128 LEHB223-LFB888
	.uleb128 LEHE223-LEHB223
	.uleb128 L1017-LFB888
	.uleb128 0
	.uleb128 LEHB224-LFB888
	.uleb128 LEHE224-LEHB224
	.uleb128 L1018-LFB888
	.uleb128 0
	.uleb128 LEHB225-LFB888
	.uleb128 LEHE225-LEHB225
	.uleb128 0
	.uleb128 0
LLSDACSE888:
	.text
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
	.text
	.def	__ZL18__gthread_active_pv;	.scl	3;	.type	32;	.endef
__ZL18__gthread_active_pv:
LFB1300:
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
LFE1300:
	.def	__ZL15__gthread_equalP11__pthread_tS0_;	.scl	3;	.type	32;	.endef
__ZL15__gthread_equalP11__pthread_tS0_:
LFB1304:
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
	call	_pthread_equal
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1304:
	.def	__ZN9__gnu_cxxL18__exchange_and_addEPVii;	.scl	3;	.type	32;	.endef
__ZN9__gnu_cxxL18__exchange_and_addEPVii:
LFB1327:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	lock xaddl	%edx, (%eax)
	movl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1327:
	.def	__ZN9__gnu_cxxL25__exchange_and_add_singleEPii;	.scl	3;	.type	32;	.endef
__ZN9__gnu_cxxL25__exchange_and_add_singleEPii:
LFB1329:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	addl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1329:
	.def	__ZN9__gnu_cxxL27__exchange_and_add_dispatchEPii;	.scl	3;	.type	32;	.endef
__ZN9__gnu_cxxL27__exchange_and_add_dispatchEPii:
LFB1331:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	__ZL18__gthread_active_pv
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	L1029
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxL18__exchange_and_addEPVii
	jmp	L1030
L1029:
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxL25__exchange_and_add_singleEPii
L1030:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1331:
	.section	.text$_ZNKSt4hashIjEclEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt4hashIjEclEj
	.def	__ZNKSt4hashIjEclEj;	.scl	2;	.type	32;	.endef
__ZNKSt4hashIjEclEj:
LFB1515:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1515:
	.section	.text$_ZNSt10_Hash_impl4hashEPKvjj,"x"
	.linkonce discard
	.globl	__ZNSt10_Hash_impl4hashEPKvjj
	.def	__ZNSt10_Hash_impl4hashEPKvjj;	.scl	2;	.type	32;	.endef
__ZNSt10_Hash_impl4hashEPKvjj:
LFB1518:
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
	call	__ZSt11_Hash_bytesPKvjj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1518:
	.section	.text$_ZN14crc_inner_calc7calcStrEjPKc,"x"
	.linkonce discard
	.globl	__ZN14crc_inner_calc7calcStrEjPKc
	.def	__ZN14crc_inner_calc7calcStrEjPKc;	.scl	2;	.type	32;	.endef
__ZN14crc_inner_calc7calcStrEjPKc:
LFB1582:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	je	L1036
	movl	12(%ebp), %eax
	leal	1(%eax), %edx
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	xorl	8(%ebp), %eax
	movzbl	%al, %eax
	movl	__ZN14crc_inner_calcL11s_calcTableE(,%eax,4), %eax
	movl	8(%ebp), %ecx
	shrl	$8, %ecx
	xorl	%ecx, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN14crc_inner_calc7calcStrEjPKc
	jmp	L1037
L1036:
	movl	8(%ebp), %eax
L1037:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1582:
	.section	.text$_Z9calcCRC32PKc,"x"
	.linkonce discard
	.globl	__Z9calcCRC32PKc
	.def	__Z9calcCRC32PKc;	.scl	2;	.type	32;	.endef
__Z9calcCRC32PKc:
LFB1584:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$-1, (%esp)
	call	__ZN14crc_inner_calc7calcStrEjPKc
	notl	%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1584:
	.section .rdata,"dr"
__ZStL13allocator_arg:
	.space 1
__ZStL6ignore:
	.space 1
	.section	.text$_ZNSt8__detail15_Hash_node_baseC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail15_Hash_node_baseC2Ev
	.def	__ZNSt8__detail15_Hash_node_baseC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt8__detail15_Hash_node_baseC2Ev:
LFB1796:
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
LFE1796:
	.section	.text$_ZNSt8__detail15_Hash_node_baseC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail15_Hash_node_baseC1Ev
	.def	__ZNSt8__detail15_Hash_node_baseC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8__detail15_Hash_node_baseC1Ev:
LFB1797:
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
LFE1797:
	.section	.text$_ZNKSt8__detail18_Mod_range_hashingclEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail18_Mod_range_hashingclEjj
	.def	__ZNKSt8__detail18_Mod_range_hashingclEjj;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail18_Mod_range_hashingclEjj:
LFB1822:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1822:
	.section	.text$_ZNSt8__detail20_Prime_rehash_policyC1Ef,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail20_Prime_rehash_policyC1Ef
	.def	__ZNSt8__detail20_Prime_rehash_policyC1Ef;	.scl	2;	.type	32;	.endef
__ZNSt8__detail20_Prime_rehash_policyC1Ef:
LFB1825:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movl	%eax, (%edx)
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1825:
	.section	.text$_ZNKSt8__detail20_Prime_rehash_policy15max_load_factorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail20_Prime_rehash_policy15max_load_factorEv
	.def	__ZNKSt8__detail20_Prime_rehash_policy15max_load_factorEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail20_Prime_rehash_policy15max_load_factorEv:
LFB1826:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	flds	-4(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1826:
	.section	.text$_ZNKSt8__detail20_Prime_rehash_policy19_M_bkt_for_elementsEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail20_Prime_rehash_policy19_M_bkt_for_elementsEj
	.def	__ZNKSt8__detail20_Prime_rehash_policy19_M_bkt_for_elementsEj;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail20_Prime_rehash_policy19_M_bkt_for_elementsEj:
LFB1827:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	movl	$0, %edx
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	fildq	-24(%ebp)
	movl	8(%ebp), %eax
	flds	(%eax)
	fdivrp	%st, %st(1)
	fstpl	-16(%ebp)
	fldl	-16(%ebp)
	fstpl	(%esp)
	call	_ceil
	fnstcw	-26(%ebp)
	movzwl	-26(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -28(%ebp)
	fldcw	-28(%ebp)
	fistpq	-24(%ebp)
	fldcw	-26(%ebp)
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1827:
	.section	.text$_ZNKSt8__detail20_Prime_rehash_policy8_M_stateEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail20_Prime_rehash_policy8_M_stateEv
	.def	__ZNKSt8__detail20_Prime_rehash_policy8_M_stateEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail20_Prime_rehash_policy8_M_stateEv:
LFB1828:
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
LFE1828:
	.section	.text$_ZNSt8__detail20_Prime_rehash_policy8_M_resetEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail20_Prime_rehash_policy8_M_resetEj
	.def	__ZNSt8__detail20_Prime_rehash_policy8_M_resetEj;	.scl	2;	.type	32;	.endef
__ZNSt8__detail20_Prime_rehash_policy8_M_resetEj:
LFB1829:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1829:
	.section	.text$_ZN6CTest84DATAC1EPKci,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest84DATAC1EPKci
	.def	__ZN6CTest84DATAC1EPKci;	.scl	2;	.type	32;	.endef
__ZN6CTest84DATAC1EPKci:
LFB2112:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_strcpy
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 20(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2112:
	.section	.text$_ZSt7forwardIjEOT_RNSt16remove_referenceIS0_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIjEOT_RNSt16remove_referenceIS0_E4typeE
	.def	__ZSt7forwardIjEOT_RNSt16remove_referenceIS0_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIjEOT_RNSt16remove_referenceIS0_E4typeE:
LFB2115:
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
LFE2115:
	.section	.text$_ZSt7forwardIRKN6CTest84DATAEEOT_RNSt16remove_referenceIS4_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRKN6CTest84DATAEEOT_RNSt16remove_referenceIS4_E4typeE
	.def	__ZSt7forwardIRKN6CTest84DATAEEOT_RNSt16remove_referenceIS4_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRKN6CTest84DATAEEOT_RNSt16remove_referenceIS4_E4typeE:
LFB2116:
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
LFE2116:
	.section	.text$_ZNSt4pairIjN6CTest84DATAEEC1IjvEEOT_RKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIjN6CTest84DATAEEC1IjvEEOT_RKS1_
	.def	__ZNSt4pairIjN6CTest84DATAEEC1IjvEEOT_RKS1_;	.scl	2;	.type	32;	.endef
__ZNSt4pairIjN6CTest84DATAEEC1IjvEEOT_RKS1_:
LFB2119:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIjEOT_RNSt16remove_referenceIS0_E4typeE
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	(%edx), %ecx
	movl	%ecx, 4(%eax)
	movl	4(%edx), %ecx
	movl	%ecx, 8(%eax)
	movl	8(%edx), %ecx
	movl	%ecx, 12(%eax)
	movl	12(%edx), %ecx
	movl	%ecx, 16(%eax)
	movl	16(%edx), %ecx
	movl	%ecx, 20(%eax)
	movl	20(%edx), %edx
	movl	%edx, 24(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2119:
	.section	.text$_ZSt9make_pairIjRKN6CTest84DATAEESt4pairINSt17__decay_and_stripIT_E6__typeENS5_IT0_E6__typeEEOS6_OS9_,"x"
	.linkonce discard
	.globl	__ZSt9make_pairIjRKN6CTest84DATAEESt4pairINSt17__decay_and_stripIT_E6__typeENS5_IT0_E6__typeEEOS6_OS9_
	.def	__ZSt9make_pairIjRKN6CTest84DATAEESt4pairINSt17__decay_and_stripIT_E6__typeENS5_IT0_E6__typeEEOS6_OS9_;	.scl	2;	.type	32;	.endef
__ZSt9make_pairIjRKN6CTest84DATAEESt4pairINSt17__decay_and_stripIT_E6__typeENS5_IT0_E6__typeEEOS6_OS9_:
LFB2114:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$12, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKN6CTest84DATAEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIjEOT_RNSt16remove_referenceIS0_E4typeE
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt4pairIjN6CTest84DATAEEC1IjvEEOT_RKS1_
	movl	8(%ebp), %eax
	addl	$12, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE2114:
	.section	.text$_ZSt7forwardIN6CTest84DATAEEOT_RNSt16remove_referenceIS2_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIN6CTest84DATAEEOT_RNSt16remove_referenceIS2_E4typeE
	.def	__ZSt7forwardIN6CTest84DATAEEOT_RNSt16remove_referenceIS2_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIN6CTest84DATAEEOT_RNSt16remove_referenceIS2_E4typeE:
LFB2121:
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
LFE2121:
	.section	.text$_ZNSt4pairIKjN6CTest84DATAEEC1IjS2_vEEOS_IT_T0_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIKjN6CTest84DATAEEC1IjS2_vEEOS_IT_T0_E
	.def	__ZNSt4pairIKjN6CTest84DATAEEC1IjS2_vEEOS_IT_T0_E;	.scl	2;	.type	32;	.endef
__ZNSt4pairIKjN6CTest84DATAEEC1IjS2_vEEOS_IT_T0_E:
LFB2123:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIjEOT_RNSt16remove_referenceIS0_E4typeE
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIN6CTest84DATAEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	8(%ebp), %edx
	movl	(%eax), %ecx
	movl	%ecx, 4(%edx)
	movl	4(%eax), %ecx
	movl	%ecx, 8(%edx)
	movl	8(%eax), %ecx
	movl	%ecx, 12(%edx)
	movl	12(%eax), %ecx
	movl	%ecx, 16(%edx)
	movl	16(%eax), %ecx
	movl	%ecx, 20(%edx)
	movl	20(%eax), %eax
	movl	%eax, 24(%edx)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2123:
	.section .rdata,"dr"
LC196:
	.ascii "CTest8::addData()\0"
	.section	.text$_ZN6CTest87addDataERKNS_4DATAE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest87addDataERKNS_4DATAE
	.def	__ZN6CTest87addDataERKNS_4DATAE;	.scl	2;	.type	32;	.endef
__ZN6CTest87addDataERKNS_4DATAE:
LFB2113:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2113
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$84, %esp
	.cfi_offset 3, -12
	movl	$LC196, (%esp)
LEHB226:
	call	_puts
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	$0, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE226:
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
LEHB227:
	call	__Z9calcCRC32PKc
LEHE227:
	movl	%eax, -12(%ebp)
	leal	-40(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt9make_pairIjRKN6CTest84DATAEESt4pairINSt17__decay_and_stripIT_E6__typeENS5_IT0_E6__typeEEOS6_OS9_
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	leal	-40(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB228:
	call	__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE6insertIS6_IjS1_EvEES6_INSt8__detail14_Node_iteratorIS8_Lb0ELb0EEEbEOT_
LEHE228:
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorD1Ev
	jmp	L1071
L1070:
	movl	%eax, %ebx
	jmp	L1066
L1069:
	movl	%eax, %ebx
L1066:
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorD1Ev
	movl	%ebx, %eax
	jmp	L1067
L1068:
L1067:
	movl	%eax, (%esp)
LEHB229:
	call	__Unwind_Resume
LEHE229:
L1071:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2113:
	.section	.gcc_except_table,"w"
LLSDA2113:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2113-LLSDACSB2113
LLSDACSB2113:
	.uleb128 LEHB226-LFB2113
	.uleb128 LEHE226-LEHB226
	.uleb128 L1068-LFB2113
	.uleb128 0
	.uleb128 LEHB227-LFB2113
	.uleb128 LEHE227-LEHB227
	.uleb128 L1069-LFB2113
	.uleb128 0
	.uleb128 LEHB228-LFB2113
	.uleb128 LEHE228-LEHB228
	.uleb128 L1070-LFB2113
	.uleb128 0
	.uleb128 LEHB229-LFB2113
	.uleb128 LEHE229-LEHB229
	.uleb128 0
	.uleb128 0
LLSDACSE2113:
	.section	.text$_ZN6CTest87addDataERKNS_4DATAE,"x"
	.linkonce discard
	.section .rdata,"dr"
LC197:
	.ascii "CTest8::find()\0"
	.section	.text$_ZNK6CTest84findEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6CTest84findEj
	.def	__ZNK6CTest84findEj;	.scl	2;	.type	32;	.endef
__ZNK6CTest84findEj:
LFB2124:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC197, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	leal	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE4findERS7_
	movl	%eax, -20(%ebp)
	leal	-20(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNKSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE4cendEv
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	leal	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt8__detaileqISt4pairIKjN6CTest84DATAEELb0EEEbRKNS_19_Node_iterator_baseIT_XT0_EEESA_
	testb	%al, %al
	je	L1073
	movl	$0, %eax
	jmp	L1074
L1073:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEptEv
	addl	$4, %eax
L1074:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2124:
	.section	.text$_ZNK6CTest84findEPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6CTest84findEPKc
	.def	__ZNK6CTest84findEPKc;	.scl	2;	.type	32;	.endef
__ZNK6CTest84findEPKc:
LFB2125:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z9calcCRC32PKc
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6CTest84findEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2125:
	.section .rdata,"dr"
LC198:
	.ascii "CTest8::Consructor()\0"
LC199:
	.ascii "new unordered_map\0"
LC200:
	.ascii "unordered_map::reserve\0"
LC201:
	.ascii "--\0"
	.section	.text$_ZN6CTest8C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest8C1Ev
	.def	__ZN6CTest8C1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest8C1Ev:
LFB2128:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2128
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
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj1024EEC1Ev
	movl	$LC198, (%esp)
LEHB230:
	call	_puts
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	$0, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE230:
	movl	$LC199, (%esp)
LEHB231:
	call	_puts
LEHE231:
	leal	-27(%ebp), %esi
	leal	-26(%ebp), %edi
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISt4pairIKjN6CTest84DATAEEEC1Ev
	leal	-25(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	$24, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1078
	movl	-60(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$10, 4(%esp)
	movl	%ebx, (%esp)
LEHB232:
	call	__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEEC1EjRKS3_RKS5_RKS9_
LEHE232:
	movl	%ebx, %eax
	jmp	L1079
L1078:
	movl	%ebx, %eax
L1079:
	movl	8(%ebp), %edx
	movl	%eax, (%edx)
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISt4pairIKjN6CTest84DATAEEED1Ev
	movl	$LC200, (%esp)
LEHB233:
	call	_puts
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	$10, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE7reserveEj
	movl	$LC201, (%esp)
	call	_puts
LEHE233:
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorD1Ev
	jmp	L1086
L1085:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZdlPv
	movl	%esi, %ebx
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISt4pairIKjN6CTest84DATAEEED1Ev
	movl	%ebx, %eax
	movl	%eax, %ebx
	jmp	L1081
L1084:
	movl	%eax, %ebx
L1081:
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorD1Ev
	movl	%ebx, %eax
	jmp	L1082
L1083:
L1082:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj1024EED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB234:
	call	__Unwind_Resume
LEHE234:
L1086:
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
LFE2128:
	.section	.gcc_except_table,"w"
LLSDA2128:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2128-LLSDACSB2128
LLSDACSB2128:
	.uleb128 LEHB230-LFB2128
	.uleb128 LEHE230-LEHB230
	.uleb128 L1083-LFB2128
	.uleb128 0
	.uleb128 LEHB231-LFB2128
	.uleb128 LEHE231-LEHB231
	.uleb128 L1084-LFB2128
	.uleb128 0
	.uleb128 LEHB232-LFB2128
	.uleb128 LEHE232-LEHB232
	.uleb128 L1085-LFB2128
	.uleb128 0
	.uleb128 LEHB233-LFB2128
	.uleb128 LEHE233-LEHB233
	.uleb128 L1084-LFB2128
	.uleb128 0
	.uleb128 LEHB234-LFB2128
	.uleb128 LEHE234-LEHB234
	.uleb128 0
	.uleb128 0
LLSDACSE2128:
	.section	.text$_ZN6CTest8C1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEED1Ev
	.def	__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEED1Ev:
LFB2132:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEED1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2132:
	.section .rdata,"dr"
LC202:
	.ascii "CTest8::Destructor()\0"
LC203:
	.ascii "delete unordered_map\0"
	.section	.text$_ZN6CTest8D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest8D1Ev
	.def	__ZN6CTest8D1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest8D1Ev:
LFB2134:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2134
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	$LC202, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	$0, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
	movl	$LC203, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	movl	(%eax), %ebx
	testl	%ebx, %ebx
	je	L1090
	movl	%ebx, (%esp)
	call	__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEED1Ev
	movl	%ebx, (%esp)
	call	__ZdlPv
L1090:
	movl	$LC201, (%esp)
	call	_puts
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorD1Ev
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj1024EED1Ev
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2134:
	.section	.gcc_except_table,"w"
LLSDA2134:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2134-LLSDACSB2134
LLSDACSB2134:
LLSDACSE2134:
	.section	.text$_ZN6CTest8D1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC204:
	.ascii "---------- test8:\346\250\231\346\272\226\343\203\251\343\202\244\343\203\226\343\203\251\343\203\252\343\202\222\344\276\277\345\210\251\343\201\253\345\210\251\347\224\250 ----------\0"
LC205:
	.ascii "\346\226\207\345\255\227\345\210\227\343\201\250\0"
LC206:
	.ascii "\346\226\207\345\255\227\345\210\227\343\202\222\0"
	.align 4
LC207:
	.ascii "\347\265\220\345\220\210\343\201\231\343\202\213\343\202\210\343\201\206\343\201\252\345\207\246\347\220\206\343\201\247\343\201\257\343\200\201\0"
LC208:
	.ascii "std::string\343\201\214\0"
LC209:
	.ascii "\343\202\204\343\201\243\343\201\261\343\202\212\344\276\277\345\210\251!!\0"
LC210:
	.ascii "str_buff=\"%s\"\12\0"
LC211:
	.ascii "----------CTest8\0"
LC212:
	.ascii "\345\244\252\351\203\216\0"
LC213:
	.ascii "\346\254\241\351\203\216\0"
LC214:
	.ascii "\344\270\211\351\203\216\0"
LC215:
	.ascii "new CTest8\0"
LC216:
	.ascii "ref1: name=\"%s\", age=%d\12\0"
LC217:
	.ascii "ref2: name=\"%s\", age=%d\12\0"
LC218:
	.ascii "ref3: name=\"%s\", age=%d\12\0"
LC219:
	.ascii "delete CTest8\0"
LC220:
	.ascii "----------CTest8:End\0"
	.text
	.globl	__Z5test8v
	.def	__Z5test8v;	.scl	2;	.type	32;	.endef
__Z5test8v:
LFB2135:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2135
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	movl	$8576, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	$LC204, (%esp)
LEHB235:
	call	_puts
LEHE235:
	movl	$LC148, (%esp)
LEHB236:
	call	_puts
LEHE236:
	leal	-8432(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj1024EEC1Ev
	movl	$0, 8(%esp)
	leal	-8432(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
LEHB237:
	call	__ZN23CTempPolyStackAllocatorC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE237:
	leal	-61(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-61(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC205, 4(%esp)
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
LEHB238:
	call	__ZNSsC1EPKcRKSaIcE
LEHE238:
	leal	-61(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-60(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC206, 4(%esp)
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
LEHB239:
	call	__ZNSsC1EPKcRKSaIcE
LEHE239:
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-59(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-59(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC207, 4(%esp)
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
LEHB240:
	call	__ZNSsC1EPKcRKSaIcE
LEHE240:
	leal	-59(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-58(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-58(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC208, 4(%esp)
	leal	-100(%ebp), %eax
	movl	%eax, (%esp)
LEHB241:
	call	__ZNSsC1EPKcRKSaIcE
LEHE241:
	leal	-58(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-57(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-57(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC209, 4(%esp)
	leal	-104(%ebp), %eax
	movl	%eax, (%esp)
LEHB242:
	call	__ZNSsC1EPKcRKSaIcE
LEHE242:
	leal	-57(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-48(%ebp), %eax
	leal	-92(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-88(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB243:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_
LEHE243:
	subl	$4, %esp
	leal	-52(%ebp), %eax
	leal	-96(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-48(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB244:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_
LEHE244:
	subl	$4, %esp
	leal	-56(%ebp), %eax
	leal	-100(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-52(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB245:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_
LEHE245:
	subl	$4, %esp
	leal	-108(%ebp), %eax
	leal	-104(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-56(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB246:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_
LEHE246:
	subl	$4, %esp
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSs5c_strEv
	movl	%eax, 4(%esp)
	leal	-8560(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcpy
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-100(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-8560(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC210, (%esp)
LEHB247:
	call	_printf
LEHE247:
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorD1Ev
	leal	-8432(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj1024EED1Ev
	movl	$LC143, (%esp)
LEHB248:
	call	_puts
LEHE248:
	leal	-41(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-41(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC205, 4(%esp)
	leal	-112(%ebp), %eax
	movl	%eax, (%esp)
LEHB249:
	call	__ZNSsC1EPKcRKSaIcE
LEHE249:
	leal	-41(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-40(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC206, 4(%esp)
	leal	-116(%ebp), %eax
	movl	%eax, (%esp)
LEHB250:
	call	__ZNSsC1EPKcRKSaIcE
LEHE250:
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-39(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-39(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC207, 4(%esp)
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
LEHB251:
	call	__ZNSsC1EPKcRKSaIcE
LEHE251:
	leal	-39(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-38(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-38(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC208, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
LEHB252:
	call	__ZNSsC1EPKcRKSaIcE
LEHE252:
	leal	-38(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-37(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC209, 4(%esp)
	leal	-128(%ebp), %eax
	movl	%eax, (%esp)
LEHB253:
	call	__ZNSsC1EPKcRKSaIcE
LEHE253:
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-28(%ebp), %eax
	leal	-116(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-112(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB254:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_
LEHE254:
	subl	$4, %esp
	leal	-32(%ebp), %eax
	leal	-120(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-28(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB255:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_
LEHE255:
	subl	$4, %esp
	leal	-36(%ebp), %eax
	leal	-124(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-32(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB256:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_
LEHE256:
	subl	$4, %esp
	leal	-132(%ebp), %eax
	leal	-128(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-36(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB257:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_
LEHE257:
	subl	$4, %esp
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSs5c_strEv
	movl	%eax, 4(%esp)
	leal	-8432(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcpy
	leal	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-128(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-116(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-8432(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC210, (%esp)
LEHB258:
	call	_printf
LEHE258:
	leal	-8432(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj8192EEC1Ev
	movl	$0, 8(%esp)
	leal	-8432(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-152(%ebp), %eax
	movl	%eax, (%esp)
LEHB259:
	call	__ZN23CTempPolyStackAllocatorC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE259:
	movl	$LC211, (%esp)
LEHB260:
	call	_puts
	movl	$40, 8(%esp)
	movl	$LC212, 4(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest84DATAC1EPKci
	movl	$30, 8(%esp)
	movl	$LC213, 4(%esp)
	leal	-200(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest84DATAC1EPKci
	movl	$20, 8(%esp)
	movl	$LC214, 4(%esp)
	leal	-224(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest84DATAC1EPKci
	movl	$LC215, (%esp)
	call	_puts
LEHE260:
	movl	$1044, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1093
	movl	%ebx, (%esp)
LEHB261:
	call	__ZN6CTest8C1Ev
LEHE261:
	movl	%ebx, %eax
	jmp	L1094
L1093:
	movl	%ebx, %eax
L1094:
	movl	%eax, -12(%ebp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
LEHB262:
	call	__ZN6CTest87addDataERKNS_4DATAE
	leal	-200(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest87addDataERKNS_4DATAE
	leal	-224(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest87addDataERKNS_4DATAE
	movl	$LC212, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6CTest84findEPKc
	movl	%eax, -16(%ebp)
	movl	$LC213, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6CTest84findEPKc
	movl	%eax, -20(%ebp)
	movl	$LC214, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK6CTest84findEPKc
	movl	%eax, -24(%ebp)
	cmpl	$0, -16(%ebp)
	je	L1095
	movl	-16(%ebp), %eax
	movl	20(%eax), %edx
	movl	-16(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC216, (%esp)
	call	_printf
L1095:
	cmpl	$0, -20(%ebp)
	je	L1096
	movl	-20(%ebp), %eax
	movl	20(%eax), %edx
	movl	-20(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC217, (%esp)
	call	_printf
L1096:
	cmpl	$0, -24(%ebp)
	je	L1097
	movl	-24(%ebp), %eax
	movl	20(%eax), %edx
	movl	-24(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC218, (%esp)
	call	_printf
L1097:
	movl	$LC219, (%esp)
	call	_puts
	movl	-12(%ebp), %ebx
	testl	%ebx, %ebx
	je	L1098
	movl	%ebx, (%esp)
	call	__ZN6CTest8D1Ev
	movl	%ebx, (%esp)
	call	__ZdlPv
L1098:
	movl	$LC220, (%esp)
	call	_puts
LEHE262:
	leal	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorD1Ev
	leal	-8432(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj8192EED1Ev
	jmp	L1159
L1136:
	movl	%eax, %ebx
	leal	-61(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	movl	%ebx, %eax
	jmp	L1100
L1137:
	movl	%eax, %ebx
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L1102
L1138:
	movl	%eax, %ebx
	leal	-59(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L1104
L1139:
	movl	%eax, %ebx
	leal	-58(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L1106
L1140:
	movl	%eax, %ebx
	leal	-57(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L1108
L1144:
	movl	%eax, %ebx
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L1110
L1143:
	movl	%eax, %ebx
L1110:
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L1111
L1142:
	movl	%eax, %ebx
L1111:
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L1112
L1141:
	movl	%eax, %ebx
L1112:
	leal	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L1108:
	leal	-100(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L1106:
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L1104:
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L1102:
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	movl	%ebx, %eax
L1100:
	movl	%eax, %ebx
	jmp	L1113
L1145:
	movl	%eax, %ebx
L1113:
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorD1Ev
	jmp	L1114
L1135:
	movl	%eax, %ebx
L1114:
	leal	-8432(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj1024EED1Ev
	movl	%ebx, %eax
	jmp	L1115
L1134:
L1115:
	movl	%eax, (%esp)
LEHB263:
	call	__Unwind_Resume
L1147:
	movl	%eax, %ebx
	leal	-41(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	movl	%ebx, %eax
	jmp	L1130
L1148:
	movl	%eax, %ebx
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L1119
L1149:
	movl	%eax, %ebx
	leal	-39(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L1121
L1150:
	movl	%eax, %ebx
	leal	-38(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L1123
L1151:
	movl	%eax, %ebx
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L1125
L1155:
	movl	%eax, %ebx
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L1127
L1154:
	movl	%eax, %ebx
L1127:
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L1128
L1153:
	movl	%eax, %ebx
L1128:
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L1129
L1152:
	movl	%eax, %ebx
L1129:
	leal	-128(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L1125:
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L1123:
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L1121:
	leal	-116(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L1119:
	leal	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	movl	%ebx, %eax
	jmp	L1130
L1146:
L1130:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L1158:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZdlPv
	movl	%esi, %eax
	jmp	L1132
L1157:
L1132:
	movl	%eax, %ebx
	leal	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CTempPolyStackAllocatorD1Ev
	jmp	L1133
L1156:
	movl	%eax, %ebx
L1133:
	leal	-8432(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj8192EED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE263:
L1159:
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
LFE2135:
	.section	.gcc_except_table,"w"
LLSDA2135:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2135-LLSDACSB2135
LLSDACSB2135:
	.uleb128 LEHB235-LFB2135
	.uleb128 LEHE235-LEHB235
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB236-LFB2135
	.uleb128 LEHE236-LEHB236
	.uleb128 L1134-LFB2135
	.uleb128 0
	.uleb128 LEHB237-LFB2135
	.uleb128 LEHE237-LEHB237
	.uleb128 L1135-LFB2135
	.uleb128 0
	.uleb128 LEHB238-LFB2135
	.uleb128 LEHE238-LEHB238
	.uleb128 L1136-LFB2135
	.uleb128 0
	.uleb128 LEHB239-LFB2135
	.uleb128 LEHE239-LEHB239
	.uleb128 L1137-LFB2135
	.uleb128 0
	.uleb128 LEHB240-LFB2135
	.uleb128 LEHE240-LEHB240
	.uleb128 L1138-LFB2135
	.uleb128 0
	.uleb128 LEHB241-LFB2135
	.uleb128 LEHE241-LEHB241
	.uleb128 L1139-LFB2135
	.uleb128 0
	.uleb128 LEHB242-LFB2135
	.uleb128 LEHE242-LEHB242
	.uleb128 L1140-LFB2135
	.uleb128 0
	.uleb128 LEHB243-LFB2135
	.uleb128 LEHE243-LEHB243
	.uleb128 L1141-LFB2135
	.uleb128 0
	.uleb128 LEHB244-LFB2135
	.uleb128 LEHE244-LEHB244
	.uleb128 L1142-LFB2135
	.uleb128 0
	.uleb128 LEHB245-LFB2135
	.uleb128 LEHE245-LEHB245
	.uleb128 L1143-LFB2135
	.uleb128 0
	.uleb128 LEHB246-LFB2135
	.uleb128 LEHE246-LEHB246
	.uleb128 L1144-LFB2135
	.uleb128 0
	.uleb128 LEHB247-LFB2135
	.uleb128 LEHE247-LEHB247
	.uleb128 L1145-LFB2135
	.uleb128 0
	.uleb128 LEHB248-LFB2135
	.uleb128 LEHE248-LEHB248
	.uleb128 L1146-LFB2135
	.uleb128 0
	.uleb128 LEHB249-LFB2135
	.uleb128 LEHE249-LEHB249
	.uleb128 L1147-LFB2135
	.uleb128 0
	.uleb128 LEHB250-LFB2135
	.uleb128 LEHE250-LEHB250
	.uleb128 L1148-LFB2135
	.uleb128 0
	.uleb128 LEHB251-LFB2135
	.uleb128 LEHE251-LEHB251
	.uleb128 L1149-LFB2135
	.uleb128 0
	.uleb128 LEHB252-LFB2135
	.uleb128 LEHE252-LEHB252
	.uleb128 L1150-LFB2135
	.uleb128 0
	.uleb128 LEHB253-LFB2135
	.uleb128 LEHE253-LEHB253
	.uleb128 L1151-LFB2135
	.uleb128 0
	.uleb128 LEHB254-LFB2135
	.uleb128 LEHE254-LEHB254
	.uleb128 L1152-LFB2135
	.uleb128 0
	.uleb128 LEHB255-LFB2135
	.uleb128 LEHE255-LEHB255
	.uleb128 L1153-LFB2135
	.uleb128 0
	.uleb128 LEHB256-LFB2135
	.uleb128 LEHE256-LEHB256
	.uleb128 L1154-LFB2135
	.uleb128 0
	.uleb128 LEHB257-LFB2135
	.uleb128 LEHE257-LEHB257
	.uleb128 L1155-LFB2135
	.uleb128 0
	.uleb128 LEHB258-LFB2135
	.uleb128 LEHE258-LEHB258
	.uleb128 L1146-LFB2135
	.uleb128 0
	.uleb128 LEHB259-LFB2135
	.uleb128 LEHE259-LEHB259
	.uleb128 L1156-LFB2135
	.uleb128 0
	.uleb128 LEHB260-LFB2135
	.uleb128 LEHE260-LEHB260
	.uleb128 L1157-LFB2135
	.uleb128 0
	.uleb128 LEHB261-LFB2135
	.uleb128 LEHE261-LEHB261
	.uleb128 L1158-LFB2135
	.uleb128 0
	.uleb128 LEHB262-LFB2135
	.uleb128 LEHE262-LEHB262
	.uleb128 L1157-LFB2135
	.uleb128 0
	.uleb128 LEHB263-LFB2135
	.uleb128 LEHE263-LEHB263
	.uleb128 0
	.uleb128 0
LLSDACSE2135:
	.text
	.section	.text$_ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_
	.def	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_;	.scl	2;	.type	32;	.endef
__ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_:
LFB2370:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	8(%ebp), %ecx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2370:
	.section	.text$_ZNSt6chrono8durationIxSt5ratioILx1ELx1EEEC1IxvEERKT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6chrono8durationIxSt5ratioILx1ELx1EEEC1IxvEERKT_
	.def	__ZNSt6chrono8durationIxSt5ratioILx1ELx1EEEC1IxvEERKT_;	.scl	2;	.type	32;	.endef
__ZNSt6chrono8durationIxSt5ratioILx1ELx1EEEC1IxvEERKT_:
LFB2381:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	8(%ebp), %ecx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2381:
	.section	.text$_ZNKSt6chrono8durationIxSt5ratioILx1ELx1EEE5countEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1EEE5countEv
	.def	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1EEE5countEv;	.scl	2;	.type	32;	.endef
__ZNKSt6chrono8durationIxSt5ratioILx1ELx1EEE5countEv:
LFB2382:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2382:
	.section	.text$_ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000000000EEEES2_ILx1000000000ELx1EExLb0ELb1EE6__castIxS2_ILx1ELx1EEEES4_RKNS1_IT_T0_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000000000EEEES2_ILx1000000000ELx1EExLb0ELb1EE6__castIxS2_ILx1ELx1EEEES4_RKNS1_IT_T0_EE
	.def	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000000000EEEES2_ILx1000000000ELx1EExLb0ELb1EE6__castIxS2_ILx1ELx1EEEES4_RKNS1_IT_T0_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000000000EEEES2_ILx1000000000ELx1EExLb0ELb1EE6__castIxS2_ILx1ELx1EEEES4_RKNS1_IT_T0_EE:
LFB2393:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$28, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1EEE5countEv
	imull	$1000000000, %edx, %ebx
	imull	$0, %eax, %ecx
	addl	%ecx, %ebx
	movl	$1000000000, %ecx
	mull	%ecx
	leal	(%ebx,%edx), %ecx
	movl	%ecx, %edx
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	addl	$28, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2393:
	.section	.text$_ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000000000EEEExS2_ILx1ELx1EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000000000EEEExS2_ILx1ELx1EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE
	.def	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000000000EEEExS2_ILx1ELx1EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000000000EEEExS2_ILx1ELx1EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE:
LFB2392:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000000000EEEES2_ILx1000000000ELx1EExLb0ELb1EE6__castIxS2_ILx1ELx1EEEES4_RKNS1_IT_T0_EE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2392:
	.section	.text$_ZNSt6thread2idC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6thread2idC1Ev
	.def	__ZNSt6thread2idC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6thread2idC1Ev:
LFB2982:
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
LFE2982:
	.section	.text$_ZSteqNSt6thread2idES0_,"x"
	.linkonce discard
	.globl	__ZSteqNSt6thread2idES0_
	.def	__ZSteqNSt6thread2idES0_;	.scl	2;	.type	32;	.endef
__ZSteqNSt6thread2idES0_:
LFB2986:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2986
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
	call	__ZL15__gthread_equalP11__pthread_tS0_
	testl	%eax, %eax
	setne	%al
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2986:
	.section	.gcc_except_table,"w"
LLSDA2986:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2986-LLSDACSB2986
LLSDACSB2986:
LLSDACSE2986:
	.section	.text$_ZSteqNSt6thread2idES0_,"x"
	.linkonce discard
	.section	.text$_ZNSt6threadD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6threadD1Ev
	.def	__ZNSt6threadD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6threadD1Ev:
LFB2996:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6thread8joinableEv
	testb	%al, %al
	je	L1171
	call	__ZSt9terminatev
L1171:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2996:
	.section	.text$_ZNKSt6thread8joinableEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6thread8joinableEv
	.def	__ZNKSt6thread8joinableEv;	.scl	2;	.type	32;	.endef
__ZNKSt6thread8joinableEv:
LFB2999:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread2idC1Ev
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZSteqNSt6thread2idES0_
	xorl	$1, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2999:
	.section	.text$_ZNSt12__shared_ptrINSt6thread10_Impl_baseELN9__gnu_cxx12_Lock_policyE2EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12__shared_ptrINSt6thread10_Impl_baseELN9__gnu_cxx12_Lock_policyE2EED2Ev
	.def	__ZNSt12__shared_ptrINSt6thread10_Impl_baseELN9__gnu_cxx12_Lock_policyE2EED2Ev;	.scl	2;	.type	32;	.endef
__ZNSt12__shared_ptrINSt6thread10_Impl_baseELN9__gnu_cxx12_Lock_policyE2EED2Ev:
LFB3006:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EED1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3006:
	.section	.text$_ZNSt10shared_ptrINSt6thread10_Impl_baseEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10shared_ptrINSt6thread10_Impl_baseEED1Ev
	.def	__ZNSt10shared_ptrINSt6thread10_Impl_baseEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt10shared_ptrINSt6thread10_Impl_baseEED1Ev:
LFB3009:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12__shared_ptrINSt6thread10_Impl_baseELN9__gnu_cxx12_Lock_policyE2EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3009:
	.section	.text$_ZNSt6thread10_Impl_baseD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6thread10_Impl_baseD2Ev
	.def	__ZNSt6thread10_Impl_baseD2Ev;	.scl	2;	.type	32;	.endef
__ZNSt6thread10_Impl_baseD2Ev:
LFB3010:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTVNSt6thread10_Impl_baseE+8, (%eax)
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZNSt10shared_ptrINSt6thread10_Impl_baseEED1Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L1179
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1179:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3010:
	.section	.text$_ZNSt6thread10_Impl_baseD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6thread10_Impl_baseD1Ev
	.def	__ZNSt6thread10_Impl_baseD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6thread10_Impl_baseD1Ev:
LFB3011:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTVNSt6thread10_Impl_baseE+8, (%eax)
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZNSt10shared_ptrINSt6thread10_Impl_baseEED1Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L1182
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1182:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3011:
	.section	.text$_ZNSt6thread10_Impl_baseD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6thread10_Impl_baseD0Ev
	.def	__ZNSt6thread10_Impl_baseD0Ev;	.scl	2;	.type	32;	.endef
__ZNSt6thread10_Impl_baseD0Ev:
LFB3012:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread10_Impl_baseD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3012:
	.section	.text$_ZNKSt4hashINSt6thread2idEEclERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt4hashINSt6thread2idEEclERKS1_
	.def	__ZNKSt4hashINSt6thread2idEEclERKS1_;	.scl	2;	.type	32;	.endef
__ZNKSt4hashINSt6thread2idEEclERKS1_:
LFB3018:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3018
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Hash_impl4hashIP11__pthread_tEEjRKT_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3018:
	.section	.gcc_except_table,"w"
LLSDA3018:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3018-LLSDACSB3018
LLSDACSB3018:
LLSDACSE3018:
	.section	.text$_ZNKSt4hashINSt6thread2idEEclERKS1_,"x"
	.linkonce discard
.lcomm __ZL17INVALID_THREAD_ID,4,4
	.section	.text$_ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IivEERKT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IivEERKT_
	.def	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IivEERKT_;	.scl	2;	.type	32;	.endef
__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IivEERKT_:
LFB3053:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cltd
	movl	8(%ebp), %ecx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3053:
	.section	.text$_ZN9CSpinLock4lockEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9CSpinLock4lockEi
	.def	__ZN9CSpinLock4lockEi;	.scl	2;	.type	32;	.endef
__ZN9CSpinLock4lockEi:
LFB3050:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3050
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	L1191
L1195:
	cmpl	$0, 12(%ebp)
	je	L1192
	addl	$1, -12(%ebp)
	movl	-12(%ebp), %eax
	cltd
	idivl	12(%ebp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	L1193
L1192:
	movl	$1, %eax
	jmp	L1194
L1193:
	movl	$0, %eax
L1194:
	testb	%al, %al
	je	L1191
	movl	$0, -16(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IivEERKT_
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
LEHB264:
	call	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1000EEEEvRKNSt6chrono8durationIT_T0_EE
LEHE264:
L1191:
	movl	8(%ebp), %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt11atomic_flag12test_and_setESt12memory_order
	testb	%al, %al
	jne	L1195
	jmp	L1198
L1197:
	movl	%eax, (%esp)
LEHB265:
	call	__Unwind_Resume
LEHE265:
L1198:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3050:
	.section	.gcc_except_table,"w"
LLSDA3050:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3050-LLSDACSB3050
LLSDACSB3050:
	.uleb128 LEHB264-LFB3050
	.uleb128 LEHE264-LEHB264
	.uleb128 L1197-LFB3050
	.uleb128 0
	.uleb128 LEHB265-LFB3050
	.uleb128 LEHE265-LEHB265
	.uleb128 0
	.uleb128 0
LLSDACSE3050:
	.section	.text$_ZN9CSpinLock4lockEi,"x"
	.linkonce discard
	.section	.text$_ZN9CSpinLock6unlockEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9CSpinLock6unlockEv
	.def	__ZN9CSpinLock6unlockEv;	.scl	2;	.type	32;	.endef
__ZN9CSpinLock6unlockEv:
LFB3054:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt11atomic_flag5clearESt12memory_order
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3054:
	.section	.text$_ZNSt18__atomic_flag_baseC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt18__atomic_flag_baseC2Ev
	.def	__ZNSt18__atomic_flag_baseC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt18__atomic_flag_baseC2Ev:
LFB3058:
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
LFE3058:
	.section	.text$_ZNSt11atomic_flagC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11atomic_flagC1Ev
	.def	__ZNSt11atomic_flagC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt11atomic_flagC1Ev:
LFB3061:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt18__atomic_flag_baseC2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3061:
	.section	.text$_ZN9CSpinLockC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9CSpinLockC1Ev
	.def	__ZN9CSpinLockC1Ev;	.scl	2;	.type	32;	.endef
__ZN9CSpinLockC1Ev:
LFB3063:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt11atomic_flagC1Ev
	movl	8(%ebp), %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt11atomic_flag5clearESt12memory_order
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3063:
	.section	.text$_ZN9CSpinLockD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9CSpinLockD1Ev
	.def	__ZN9CSpinLockD1Ev;	.scl	2;	.type	32;	.endef
__ZN9CSpinLockD1Ev:
LFB3066:
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
LFE3066:
	.section	.text$_ZNK20CSmartStackAllocator8getTotalEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator8getTotalEv
	.def	__ZNK20CSmartStackAllocator8getTotalEv;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator8getTotalEv:
LFB3067:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3067:
	.section	.text$_ZNK20CSmartStackAllocator7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator7getUsedEv
	.def	__ZNK20CSmartStackAllocator7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator7getUsedEv:
LFB3068:
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
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	movl	8(%ebp), %edx
	movl	8(%edx), %edx
	leal	(%eax,%edx), %ebx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	subl	%eax, %ebx
	movl	%ebx, %eax
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3068:
	.section	.text$_ZNK20CSmartStackAllocator9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator9getRemainEv
	.def	__ZNK20CSmartStackAllocator9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator9getRemainEv:
LFB3069:
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
	addl	$16, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	subl	%eax, %ebx
	movl	%ebx, %eax
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3069:
	.section	.text$_ZN20CSmartStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE
	.def	__ZN20CSmartStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE:
LFB3071:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$-1, 12(%ebp)
	jne	L1212
	movl	$-1, %eax
	jmp	L1213
L1212:
	movl	$1, %eax
L1213:
	movl	8(%ebp), %edx
	addl	$36, %edx
	movl	$5, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt6atomicIN15IStackAllocator9E_ORDEREDEE5storeES1_St12memory_order
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3071:
	.section	.text$_ZNK20CSmartStackAllocator10getNowPtrNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator10getNowPtrNEv
	.def	__ZNK20CSmartStackAllocator10getNowPtrNEv;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator10getNowPtrNEv:
LFB3073:
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
	movl	4(%eax), %ebx
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	addl	%ebx, %eax
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3073:
	.section	.text$_ZNK20CSmartStackAllocator10getNowPtrREv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator10getNowPtrREv
	.def	__ZNK20CSmartStackAllocator10getNowPtrREv;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator10getNowPtrREv:
LFB3074:
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
	movl	4(%eax), %ebx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	addl	%ebx, %eax
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3074:
	.section	.text$_ZNK20CSmartStackAllocator10getNowPtrDEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator10getNowPtrDEv
	.def	__ZNK20CSmartStackAllocator10getNowPtrDEv;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator10getNowPtrDEv:
LFB3075:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$36, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt6atomicIN15IStackAllocator9E_ORDEREDEE4loadESt12memory_order
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getNowPtrEN15IStackAllocator9E_ORDEREDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3075:
	.section	.text$_ZNK20CSmartStackAllocator9getNowPtrEN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator9getNowPtrEN15IStackAllocator9E_ORDEREDE
	.def	__ZNK20CSmartStackAllocator9getNowPtrEN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator9getNowPtrEN15IStackAllocator9E_ORDEREDE:
LFB3076:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L1221
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getNowPtrDEv
	jmp	L1222
L1221:
	cmpl	$-1, 12(%ebp)
	jne	L1223
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getNowPtrREv
	jmp	L1222
L1223:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getNowPtrNEv
L1222:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3076:
	.section	.text$_ZNK20CSmartStackAllocator9getNowPtrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator9getNowPtrEv
	.def	__ZNK20CSmartStackAllocator9getNowPtrEv;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator9getNowPtrEv:
LFB3077:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getNowPtrDEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3077:
	.section	.text$_ZNK20CSmartStackAllocator10getMarkerNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator10getMarkerNEv
	.def	__ZNK20CSmartStackAllocator10getMarkerNEv;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator10getMarkerNEv:
LFB3078:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3078:
	.section	.text$_ZNK20CSmartStackAllocator10getMarkerREv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator10getMarkerREv
	.def	__ZNK20CSmartStackAllocator10getMarkerREv;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator10getMarkerREv:
LFB3079:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3079:
	.section	.text$_ZNK20CSmartStackAllocator10getMarkerDEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator10getMarkerDEv
	.def	__ZNK20CSmartStackAllocator10getMarkerDEv;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator10getMarkerDEv:
LFB3080:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$36, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt6atomicIN15IStackAllocator9E_ORDEREDEE4loadESt12memory_order
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getMarkerEN15IStackAllocator9E_ORDEREDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3080:
	.section	.text$_ZNK20CSmartStackAllocator9getMarkerEN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator9getMarkerEN15IStackAllocator9E_ORDEREDE
	.def	__ZNK20CSmartStackAllocator9getMarkerEN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator9getMarkerEN15IStackAllocator9E_ORDEREDE:
LFB3081:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L1235
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerDEv
	jmp	L1236
L1235:
	cmpl	$-1, 12(%ebp)
	jne	L1237
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	jmp	L1236
L1237:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
L1236:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3081:
	.section	.text$_ZNK20CSmartStackAllocator9getMarkerEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator9getMarkerEv
	.def	__ZNK20CSmartStackAllocator9getMarkerEv;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator9getMarkerEv:
LFB3082:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerDEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3082:
	.section	.text$_ZNK20CSmartStackAllocator9getBeginNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator9getBeginNEv
	.def	__ZNK20CSmartStackAllocator9getBeginNEv;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator9getBeginNEv:
LFB3083:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3083:
	.section	.text$_ZNK20CSmartStackAllocator9getBeginREv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator9getBeginREv
	.def	__ZNK20CSmartStackAllocator9getBeginREv;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator9getBeginREv:
LFB3084:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3084:
	.section	.text$_ZNK20CSmartStackAllocator11getCounterNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator11getCounterNEv
	.def	__ZNK20CSmartStackAllocator11getCounterNEv;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator11getCounterNEv:
LFB3088:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIiE4loadESt12memory_order
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3088:
	.section	.text$_ZNK20CSmartStackAllocator11getCounterREv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK20CSmartStackAllocator11getCounterREv
	.def	__ZNK20CSmartStackAllocator11getCounterREv;	.scl	2;	.type	32;	.endef
__ZNK20CSmartStackAllocator11getCounterREv:
LFB3089:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIiE4loadESt12memory_order
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3089:
	.section	.text$_ZN20CSmartStackAllocator6allocNEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator6allocNEjj
	.def	__ZN20CSmartStackAllocator6allocNEjj;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator6allocNEjj:
LFB3093:
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
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	movl	12(%ebp), %edx
	leal	(%eax,%edx), %ebx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	cmpl	%eax, %ebx
	seta	%al
	testb	%al, %al
	je	L1251
	movl	$0, %eax
	jmp	L1252
L1251:
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	$1000, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9CSpinLock4lockEi
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	$5, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE9fetch_addEiSt12memory_order
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	addl	%ebx, %eax
	movl	%eax, -12(%ebp)
	cmpl	$0, 16(%ebp)
	je	L1253
	movl	-12(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	testl	%eax, %eax
	je	L1254
	movl	-12(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	movl	16(%ebp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	jmp	L1256
L1254:
	movl	$0, %eax
	jmp	L1256
L1253:
	movl	$0, %eax
L1256:
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	movl	-16(%ebp), %edx
	addl	%eax, %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	cmpl	-20(%ebp), %eax
	setb	%al
	testb	%al, %al
	je	L1257
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	subl	%eax, %ebx
	movl	%ebx, %eax
	movl	%eax, 12(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC69, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLock6unlockEv
	movl	$0, %eax
	jmp	L1252
L1257:
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	addl	%edx, %eax
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	leal	12(%eax), %edx
	movl	$5, 8(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLock6unlockEv
	movl	-24(%ebp), %eax
L1252:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3093:
	.section	.text$_ZN20CSmartStackAllocator6allocREjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator6allocREjj
	.def	__ZN20CSmartStackAllocator6allocREjj;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator6allocREjj:
LFB3094:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	subl	12(%ebp), %eax
	cmpl	%eax, %ebx
	seta	%al
	testb	%al, %al
	je	L1259
	movl	$0, %eax
	jmp	L1260
L1259:
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	$1000, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9CSpinLock4lockEi
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	$5, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE9fetch_addEiSt12memory_order
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	addl	%ebx, %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -16(%ebp)
	cmpl	$0, 16(%ebp)
	je	L1261
	movl	-16(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	jmp	L1262
L1261:
	movl	$0, %eax
L1262:
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	subl	12(%ebp), %eax
	subl	-20(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	cmpl	-24(%ebp), %eax
	ja	L1263
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	-24(%ebp), %eax
	jae	L1264
L1263:
	movl	$1, %eax
	jmp	L1265
L1264:
	movl	$0, %eax
L1265:
	testb	%al, %al
	je	L1266
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	subl	%eax, %ebx
	movl	%ebx, %eax
	movl	%eax, 12(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC70, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLock6unlockEv
	movl	$0, %eax
	jmp	L1260
L1266:
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	subl	-20(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	leal	16(%eax), %edx
	movl	$5, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLock6unlockEv
	movl	-28(%ebp), %eax
L1260:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3094:
	.section	.text$_ZN20CSmartStackAllocator6allocDEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator6allocDEjj
	.def	__ZN20CSmartStackAllocator6allocDEjj;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator6allocDEjj:
LFB3095:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$36, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt6atomicIN15IStackAllocator9E_ORDEREDEE4loadESt12memory_order
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3095:
	.section	.text$_ZN20CSmartStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj
	.def	__ZN20CSmartStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj:
LFB3096:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L1270
	movl	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator6allocDEjj
	jmp	L1271
L1270:
	cmpl	$-1, 12(%ebp)
	jne	L1272
	movl	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator6allocREjj
	jmp	L1271
L1272:
	movl	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator6allocNEjj
L1271:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3096:
	.section	.text$_ZN20CSmartStackAllocator5allocEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator5allocEjj
	.def	__ZN20CSmartStackAllocator5allocEjj;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator5allocEjj:
LFB3097:
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
	call	__ZN20CSmartStackAllocator6allocDEjj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3097:
	.section	.text$_ZN20CSmartStackAllocator5freeNEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator5freeNEPv
	.def	__ZN20CSmartStackAllocator5freeNEPv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator5freeNEPv:
LFB3098:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIiE4loadESt12memory_order
	testl	%eax, %eax
	setle	%al
	testb	%al, %al
	je	L1278
	jmp	L1277
L1278:
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	cmpl	-12(%ebp), %eax
	ja	L1280
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	cmpl	-12(%ebp), %eax
	jae	L1281
L1280:
	movl	$1, %eax
	jmp	L1282
L1281:
	movl	$0, %eax
L1282:
	testb	%al, %al
	je	L1283
	jmp	L1277
L1283:
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	$1000, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9CSpinLock4lockEi
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIiE4loadESt12memory_order
	testl	%eax, %eax
	jle	L1284
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	cmpl	-12(%ebp), %eax
	ja	L1284
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	cmpl	-12(%ebp), %eax
	jae	L1285
L1284:
	movl	$1, %eax
	jmp	L1286
L1285:
	movl	$0, %eax
L1286:
	testb	%al, %al
	je	L1287
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLock6unlockEv
	jmp	L1277
L1287:
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	$5, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE9fetch_subEiSt12memory_order
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIiE4loadESt12memory_order
	testl	%eax, %eax
	sete	%al
	testb	%al, %al
	je	L1288
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	movl	8(%ebp), %edx
	addl	$12, %edx
	movl	$5, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
L1288:
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLock6unlockEv
L1277:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3098:
	.section	.text$_ZN20CSmartStackAllocator5freeREPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator5freeREPv
	.def	__ZN20CSmartStackAllocator5freeREPv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator5freeREPv:
LFB3099:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIiE4loadESt12memory_order
	testl	%eax, %eax
	setle	%al
	testb	%al, %al
	je	L1290
	jmp	L1289
L1290:
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	cmpl	-12(%ebp), %eax
	jb	L1292
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	cmpl	-12(%ebp), %eax
	jbe	L1293
L1292:
	movl	$1, %eax
	jmp	L1294
L1293:
	movl	$0, %eax
L1294:
	testb	%al, %al
	je	L1295
	jmp	L1289
L1295:
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	$1000, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9CSpinLock4lockEi
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIiE4loadESt12memory_order
	testl	%eax, %eax
	jle	L1296
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	cmpl	-12(%ebp), %eax
	jb	L1296
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	cmpl	-12(%ebp), %eax
	jbe	L1297
L1296:
	movl	$1, %eax
	jmp	L1298
L1297:
	movl	$0, %eax
L1298:
	testb	%al, %al
	je	L1299
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLock6unlockEv
	jmp	L1289
L1299:
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	$5, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE9fetch_subEiSt12memory_order
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIiE4loadESt12memory_order
	testl	%eax, %eax
	sete	%al
	testb	%al, %al
	je	L1300
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	movl	8(%ebp), %edx
	addl	$16, %edx
	movl	$5, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
L1300:
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLock6unlockEv
L1289:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3099:
	.section	.text$_ZN20CSmartStackAllocator4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator4freeEPv
	.def	__ZN20CSmartStackAllocator4freeEPv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator4freeEPv:
LFB3100:
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
	call	__ZN20CSmartStackAllocator5freeNEPv
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator5freeREPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3100:
	.section	.text$_ZN20CSmartStackAllocator6beginNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator6beginNEv
	.def	__ZN20CSmartStackAllocator6beginNEv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator6beginNEv:
LFB3101:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	$1000, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9CSpinLock4lockEi
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	movl	8(%ebp), %edx
	addl	$20, %edx
	movl	$5, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	$5, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE5storeEiSt12memory_order
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLock6unlockEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3101:
	.section	.text$_ZN20CSmartStackAllocator6beginREv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator6beginREv
	.def	__ZN20CSmartStackAllocator6beginREv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator6beginREv:
LFB3102:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	$1000, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9CSpinLock4lockEi
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	movl	8(%ebp), %edx
	addl	$24, %edx
	movl	$5, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	$5, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE5storeEiSt12memory_order
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLock6unlockEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3102:
	.section	.text$_ZN20CSmartStackAllocator5backNEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator5backNEj
	.def	__ZN20CSmartStackAllocator5backNEj;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator5backNEj:
LFB3106:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	$1000, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9CSpinLock4lockEi
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	cmpl	12(%ebp), %eax
	setb	%al
	testb	%al, %al
	je	L1305
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLock6unlockEv
	jmp	L1304
L1305:
	movl	8(%ebp), %eax
	leal	12(%eax), %edx
	movl	$5, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	leal	20(%eax), %edx
	movl	$5, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	$5, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE5storeEiSt12memory_order
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLock6unlockEv
L1304:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3106:
	.section	.text$_ZN20CSmartStackAllocator5backNEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator5backNEPKv
	.def	__ZN20CSmartStackAllocator5backNEPKv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator5backNEPKv:
LFB3107:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator5backNEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3107:
	.section	.text$_ZN20CSmartStackAllocator5backREj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator5backREj
	.def	__ZN20CSmartStackAllocator5backREj;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator5backREj:
LFB3108:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	$1000, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9CSpinLock4lockEi
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	cmpl	12(%ebp), %eax
	ja	L1309
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	12(%ebp), %eax
	jae	L1310
L1309:
	movl	$1, %eax
	jmp	L1311
L1310:
	movl	$0, %eax
L1311:
	testb	%al, %al
	je	L1312
	jmp	L1308
L1312:
	movl	8(%ebp), %eax
	leal	16(%eax), %edx
	movl	$5, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	leal	24(%eax), %edx
	movl	$5, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	$5, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE5storeEiSt12memory_order
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLock6unlockEv
L1308:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3108:
	.section	.text$_ZN20CSmartStackAllocator5backREPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator5backREPKv
	.def	__ZN20CSmartStackAllocator5backREPKv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator5backREPKv:
LFB3109:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator5backREj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3109:
	.section	.text$_ZN20CSmartStackAllocator5backDEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator5backDEj
	.def	__ZN20CSmartStackAllocator5backDEj;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator5backDEj:
LFB3110:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$36, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt6atomicIN15IStackAllocator9E_ORDEREDEE4loadESt12memory_order
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator4backEN15IStackAllocator9E_ORDEREDEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3110:
	.section	.text$_ZN20CSmartStackAllocator5backDEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator5backDEPKv
	.def	__ZN20CSmartStackAllocator5backDEPKv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator5backDEPKv:
LFB3111:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$36, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt6atomicIN15IStackAllocator9E_ORDEREDEE4loadESt12memory_order
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator4backEN15IStackAllocator9E_ORDEREDEPKv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3111:
	.section	.text$_ZN20CSmartStackAllocator4backEN15IStackAllocator9E_ORDEREDEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator4backEN15IStackAllocator9E_ORDEREDEj
	.def	__ZN20CSmartStackAllocator4backEN15IStackAllocator9E_ORDEREDEj;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator4backEN15IStackAllocator9E_ORDEREDEj:
LFB3112:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L1318
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator5backDEj
	jmp	L1317
L1318:
	cmpl	$-1, 12(%ebp)
	jne	L1320
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator5backREj
	jmp	L1317
L1320:
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator5backNEj
L1317:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3112:
	.section	.text$_ZN20CSmartStackAllocator4backEN15IStackAllocator9E_ORDEREDEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator4backEN15IStackAllocator9E_ORDEREDEPKv
	.def	__ZN20CSmartStackAllocator4backEN15IStackAllocator9E_ORDEREDEPKv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator4backEN15IStackAllocator9E_ORDEREDEPKv:
LFB3113:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L1322
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator5backDEPKv
	jmp	L1321
L1322:
	cmpl	$-1, 12(%ebp)
	jne	L1324
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator5backREPKv
	jmp	L1321
L1324:
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator5backNEPKv
L1321:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3113:
	.section	.text$_ZN20CSmartStackAllocator4backEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator4backEj
	.def	__ZN20CSmartStackAllocator4backEj;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator4backEj:
LFB3114:
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
	call	__ZN20CSmartStackAllocator5backDEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3114:
	.section	.text$_ZN20CSmartStackAllocator4backEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator4backEPKv
	.def	__ZN20CSmartStackAllocator4backEPKv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator4backEPKv:
LFB3115:
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
	call	__ZN20CSmartStackAllocator5backDEPKv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3115:
	.section	.text$_ZN20CSmartStackAllocator6clearNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator6clearNEv
	.def	__ZN20CSmartStackAllocator6clearNEv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator6clearNEv:
LFB3116:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	$1000, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9CSpinLock4lockEi
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	$5, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	$5, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE5storeEiSt12memory_order
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLock6unlockEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3116:
	.section	.text$_ZN20CSmartStackAllocator6clearREv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator6clearREv
	.def	__ZN20CSmartStackAllocator6clearREv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator6clearREv:
LFB3117:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	$1000, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9CSpinLock4lockEi
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	8(%ebp), %edx
	addl	$16, %edx
	movl	$5, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	$5, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	$5, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE5storeEiSt12memory_order
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLock6unlockEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3117:
	.section	.text$_ZN20CSmartStackAllocator6clearDEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator6clearDEv
	.def	__ZN20CSmartStackAllocator6clearDEv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator6clearDEv:
LFB3118:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$36, %eax
	movl	$5, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt6atomicIN15IStackAllocator9E_ORDEREDEE4loadESt12memory_order
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator5clearEN15IStackAllocator9E_ORDEREDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3118:
	.section	.text$_ZN20CSmartStackAllocator7clearNREv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator7clearNREv
	.def	__ZN20CSmartStackAllocator7clearNREv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator7clearNREv:
LFB3119:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator6clearNEv
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator6clearREv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3119:
	.section	.text$_ZN20CSmartStackAllocator5clearEN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator5clearEN15IStackAllocator9E_ORDEREDE
	.def	__ZN20CSmartStackAllocator5clearEN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator5clearEN15IStackAllocator9E_ORDEREDE:
LFB3120:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L1332
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator6clearDEv
	jmp	L1331
L1332:
	cmpl	$-1, 12(%ebp)
	jne	L1334
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator6clearREv
	jmp	L1331
L1334:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator6clearNEv
L1331:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3120:
	.section	.text$_ZN20CSmartStackAllocator5clearEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator5clearEv
	.def	__ZN20CSmartStackAllocator5clearEv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator5clearEv:
LFB3121:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator6clearDEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3121:
	.section	.text$_ZN20CSmartStackAllocator8clearAllEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocator8clearAllEv
	.def	__ZN20CSmartStackAllocator8clearAllEv;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocator8clearAllEv:
LFB3122:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator7clearNREv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3122:
	.section	.text$_ZNSt13__atomic_baseIjEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13__atomic_baseIjEC2Ev
	.def	__ZNSt13__atomic_baseIjEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt13__atomic_baseIjEC2Ev:
LFB3126:
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
LFE3126:
	.section	.text$_ZNSt6atomicIjEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6atomicIjEC1Ev
	.def	__ZNSt6atomicIjEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6atomicIjEC1Ev:
LFB3129:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIjEC2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3129:
	.section	.text$_ZNSt6atomicIN15IStackAllocator9E_ORDEREDEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6atomicIN15IStackAllocator9E_ORDEREDEEC1Ev
	.def	__ZNSt6atomicIN15IStackAllocator9E_ORDEREDEEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6atomicIN15IStackAllocator9E_ORDEREDEEC1Ev:
LFB3132:
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
LFE3132:
	.section	.text$_ZN20CSmartStackAllocatorC2EPvjN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocatorC2EPvjN15IStackAllocator9E_ORDEREDE
	.def	__ZN20CSmartStackAllocatorC2EPvjN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocatorC2EPvjN15IStackAllocator9E_ORDEREDE:
LFB3133:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15IStackAllocatorC2Ev
	movl	8(%ebp), %eax
	movl	$__ZTV20CSmartStackAllocator+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__ZNSt6atomicIjEC1Ev
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	%eax, (%esp)
	call	__ZNSt6atomicIjEC1Ev
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	%eax, (%esp)
	call	__ZNSt6atomicIjEC1Ev
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	%eax, (%esp)
	call	__ZNSt6atomicIjEC1Ev
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	%eax, (%esp)
	call	__ZNSt6atomicIiEC1Ev
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	%eax, (%esp)
	call	__ZNSt6atomicIiEC1Ev
	movl	8(%ebp), %eax
	addl	$36, %eax
	movl	%eax, (%esp)
	call	__ZNSt6atomicIN15IStackAllocator9E_ORDEREDEEC1Ev
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLockC1Ev
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	$5, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	leal	16(%eax), %edx
	movl	$5, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	$5, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	leal	24(%eax), %edx
	movl	$5, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	$5, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE5storeEiSt12memory_order
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	$5, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt13__atomic_baseIiE5storeEiSt12memory_order
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3133:
	.section	.text$_ZN20CSmartStackAllocatorD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocatorD2Ev
	.def	__ZN20CSmartStackAllocatorD2Ev;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocatorD2Ev:
LFB3136:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV20CSmartStackAllocator+8, (%eax)
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLockD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15IStackAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L1341
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1341:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3136:
	.section	.text$_ZN20CSmartStackAllocatorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocatorD1Ev
	.def	__ZN20CSmartStackAllocatorD1Ev;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocatorD1Ev:
LFB3137:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV20CSmartStackAllocator+8, (%eax)
	movl	8(%ebp), %eax
	addl	$40, %eax
	movl	%eax, (%esp)
	call	__ZN9CSpinLockD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15IStackAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L1344
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1344:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3137:
	.section	.text$_ZN20CSmartStackAllocatorD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN20CSmartStackAllocatorD0Ev
	.def	__ZN20CSmartStackAllocatorD0Ev;	.scl	2;	.type	32;	.endef
__ZN20CSmartStackAllocatorD0Ev:
LFB3138:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocatorD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3138:
	.section .rdata,"dr"
LC221:
	.ascii "CSmartStackAllocAdp\0"
	.section	.text$_ZNK19CSmartStackAllocAdp7getNameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CSmartStackAllocAdp7getNameEv
	.def	__ZNK19CSmartStackAllocAdp7getNameEv;	.scl	2;	.type	32;	.endef
__ZNK19CSmartStackAllocAdp7getNameEv:
LFB3141:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$LC221, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3141:
	.section	.text$_ZN19CSmartStackAllocAdp12getAllocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CSmartStackAllocAdp12getAllocatorEv
	.def	__ZN19CSmartStackAllocAdp12getAllocatorEv;	.scl	2;	.type	32;	.endef
__ZN19CSmartStackAllocAdp12getAllocatorEv:
LFB3142:
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
LFE3142:
	.section	.text$_ZN19CSmartStackAllocAdp5allocEjjPK10ALLOC_INFO,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CSmartStackAllocAdp5allocEjjPK10ALLOC_INFO
	.def	__ZN19CSmartStackAllocAdp5allocEjjPK10ALLOC_INFO;	.scl	2;	.type	32;	.endef
__ZN19CSmartStackAllocAdp5allocEjjPK10ALLOC_INFO:
LFB3146:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CSmartStackAllocAdp12getAllocatorEv
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator5allocEN15IStackAllocator9E_ORDEREDEjj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3146:
	.section	.text$_ZN19CSmartStackAllocAdp4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CSmartStackAllocAdp4freeEPv
	.def	__ZN19CSmartStackAllocAdp4freeEPv;	.scl	2;	.type	32;	.endef
__ZN19CSmartStackAllocAdp4freeEPv:
LFB3147:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CSmartStackAllocAdp12getAllocatorEv
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator4freeEPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3147:
	.section	.text$_ZN19CSmartStackAllocAdpC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CSmartStackAllocAdpC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE
	.def	__ZN19CSmartStackAllocAdpC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN19CSmartStackAllocAdpC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE:
LFB3150:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	$0, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpC2ER15IStackAllocatorNS_13E_AUTO_REWINDE
	movl	8(%ebp), %eax
	movl	$__ZTV19CSmartStackAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 16(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3150:
	.section	.text$_ZN19CSmartStackAllocAdpD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CSmartStackAllocAdpD1Ev
	.def	__ZN19CSmartStackAllocAdpD1Ev;	.scl	2;	.type	32;	.endef
__ZN19CSmartStackAllocAdpD1Ev:
LFB3153:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV19CSmartStackAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L1358
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1358:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3153:
	.section	.text$_ZN19CSmartStackAllocAdpD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CSmartStackAllocAdpD0Ev
	.def	__ZN19CSmartStackAllocAdpD0Ev;	.scl	2;	.type	32;	.endef
__ZN19CSmartStackAllocAdpD0Ev:
LFB3154:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CSmartStackAllocAdpD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3154:
	.section	.text$_ZN28CTempPolySmartStackAllocatorC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN28CTempPolySmartStackAllocatorC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE
	.def	__ZN28CTempPolySmartStackAllocatorC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN28CTempPolySmartStackAllocatorC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE:
LFB3157:
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
	call	__ZN30CTempPolyAllocatorWithStackAdpI19CSmartStackAllocAdpEC2ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3157:
	.section	.text$_ZN28CTempPolySmartStackAllocatorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN28CTempPolySmartStackAllocatorD1Ev
	.def	__ZN28CTempPolySmartStackAllocatorD1Ev;	.scl	2;	.type	32;	.endef
__ZN28CTempPolySmartStackAllocatorD1Ev:
LFB3160:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN30CTempPolyAllocatorWithStackAdpI19CSmartStackAllocAdpED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3160:
	.section .rdata,"dr"
	.align 4
LC222:
	.ascii "CTest9::Constructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest9C1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest9C1EPKc
	.def	__ZN6CTest9C1EPKc;	.scl	2;	.type	32;	.endef
__ZN6CTest9C1EPKc:
LFB3166:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV6CTest9+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC222, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3166:
	.section .rdata,"dr"
	.align 4
LC223:
	.ascii "CTest9::Destructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest9D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest9D1Ev
	.def	__ZN6CTest9D1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest9D1Ev:
LFB3169:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3169
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV6CTest9+8, (%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC223, (%esp)
	call	_printf
	movl	$0, %eax
	testl	%eax, %eax
	je	L1367
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1367:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3169:
	.section	.gcc_except_table,"w"
LLSDA3169:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3169-LLSDACSB3169
LLSDACSB3169:
LLSDACSE3169:
	.section	.text$_ZN6CTest9D1Ev,"x"
	.linkonce discard
	.section	.text$_ZN6CTest9D0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest9D0Ev
	.def	__ZN6CTest9D0Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest9D0Ev:
LFB3170:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest9D1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3170:
.lcomm __ZL16s_stackForThread,1068,32
	.section	.text$_ZNSt6chrono8durationIxSt5ratioILx1ELx1EEEC1IivEERKT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6chrono8durationIxSt5ratioILx1ELx1EEEC1IivEERKT_
	.def	__ZNSt6chrono8durationIxSt5ratioILx1ELx1EEEC1IivEERKT_;	.scl	2;	.type	32;	.endef
__ZNSt6chrono8durationIxSt5ratioILx1ELx1EEEC1IivEERKT_:
LFB3174:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cltd
	movl	8(%ebp), %ecx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3174:
	.text
	.globl	__Z13test9thread_nPKc
	.def	__Z13test9thread_nPKc;	.scl	2;	.type	32;	.endef
__Z13test9thread_nPKc:
LFB3171:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3171
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
	movl	$1, 8(%esp)
	movl	$__ZL16s_stackForThread, 4(%esp)
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
LEHB266:
	call	__ZN28CTempPolySmartStackAllocatorC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE
LEHE266:
	movl	$12, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1374
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
LEHB267:
	call	__ZN6CTest9C1EPKc
LEHE267:
	movl	%ebx, %eax
	jmp	L1375
L1374:
	movl	%ebx, %eax
L1375:
	movl	%eax, -12(%ebp)
	movl	$1, -16(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1EEEC1IivEERKT_
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
LEHB268:
	call	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1EEEEvRKNSt6chrono8durationIT_T0_EE
LEHE268:
	cmpl	$0, -12(%ebp)
	je	L1376
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
L1376:
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CTempPolySmartStackAllocatorD1Ev
	jmp	L1384
L1382:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZdlPv
	movl	%esi, %ebx
	jmp	L1378
L1383:
	movl	%eax, %ebx
L1378:
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CTempPolySmartStackAllocatorD1Ev
	movl	%ebx, %eax
	jmp	L1380
L1381:
L1380:
	movl	%eax, (%esp)
LEHB269:
	call	__Unwind_Resume
LEHE269:
L1384:
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
LFE3171:
	.section	.gcc_except_table,"w"
LLSDA3171:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3171-LLSDACSB3171
LLSDACSB3171:
	.uleb128 LEHB266-LFB3171
	.uleb128 LEHE266-LEHB266
	.uleb128 L1381-LFB3171
	.uleb128 0
	.uleb128 LEHB267-LFB3171
	.uleb128 LEHE267-LEHB267
	.uleb128 L1382-LFB3171
	.uleb128 0
	.uleb128 LEHB268-LFB3171
	.uleb128 LEHE268-LEHB268
	.uleb128 L1383-LFB3171
	.uleb128 0
	.uleb128 LEHB269-LFB3171
	.uleb128 LEHE269-LEHB269
	.uleb128 0
	.uleb128 0
LLSDACSE3171:
	.text
	.globl	__Z13test9thread_rPKc
	.def	__Z13test9thread_rPKc;	.scl	2;	.type	32;	.endef
__Z13test9thread_rPKc:
LFB3175:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3175
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
	movl	$-1, 8(%esp)
	movl	$__ZL16s_stackForThread, 4(%esp)
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
LEHB270:
	call	__ZN28CTempPolySmartStackAllocatorC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE
LEHE270:
	movl	$12, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1386
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
LEHB271:
	call	__ZN6CTest9C1EPKc
LEHE271:
	movl	%ebx, %eax
	jmp	L1387
L1386:
	movl	%ebx, %eax
L1387:
	movl	%eax, -12(%ebp)
	movl	$1, -16(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1EEEC1IivEERKT_
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
LEHB272:
	call	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1EEEEvRKNSt6chrono8durationIT_T0_EE
LEHE272:
	cmpl	$0, -12(%ebp)
	je	L1388
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
L1388:
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CTempPolySmartStackAllocatorD1Ev
	jmp	L1396
L1394:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZdlPv
	movl	%esi, %ebx
	jmp	L1390
L1395:
	movl	%eax, %ebx
L1390:
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CTempPolySmartStackAllocatorD1Ev
	movl	%ebx, %eax
	jmp	L1392
L1393:
L1392:
	movl	%eax, (%esp)
LEHB273:
	call	__Unwind_Resume
LEHE273:
L1396:
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
LFE3175:
	.section	.gcc_except_table,"w"
LLSDA3175:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3175-LLSDACSB3175
LLSDACSB3175:
	.uleb128 LEHB270-LFB3175
	.uleb128 LEHE270-LEHB270
	.uleb128 L1393-LFB3175
	.uleb128 0
	.uleb128 LEHB271-LFB3175
	.uleb128 LEHE271-LEHB271
	.uleb128 L1394-LFB3175
	.uleb128 0
	.uleb128 LEHB272-LFB3175
	.uleb128 LEHE272-LEHB272
	.uleb128 L1395-LFB3175
	.uleb128 0
	.uleb128 LEHB273-LFB3175
	.uleb128 LEHE273-LEHB273
	.uleb128 0
	.uleb128 0
LLSDACSE3175:
	.text
	.section .rdata,"dr"
	.align 4
LC224:
	.ascii "---------- test9:\343\203\236\343\203\253\343\203\201\343\202\271\343\203\254\343\203\203\343\203\211\343\201\253\344\276\277\345\210\251\343\201\252\343\202\271\343\203\236\343\203\274\343\203\210\343\202\271\343\202\277\343\203\203\343\202\257\343\202\242\343\203\255\343\202\261\343\203\274\343\202\277 ----------\0"
	.align 4
LC225:
	.ascii "----------\345\237\272\346\234\254\345\213\225\344\275\234\343\203\201\343\202\247\343\203\203\343\202\257\0"
LC226:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "9-1\0"
	.align 4
LC227:
	.ascii "marker=(%d,%d), begin=(%d,%d), counter=(%d,%d)\12\0"
LC228:
	.ascii "beginN()\0"
LC229:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "9-2\0"
LC230:
	.ascii "beginR()\0"
LC231:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "9-3\0"
LC232:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "9-4\0"
LC233:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "9-5\0"
LC234:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "9-6\0"
LC235:
	.ascii "clearN()\0"
LC236:
	.ascii "clearR()\0"
	.align 4
LC237:
	.ascii "----------\343\202\271\343\203\254\343\203\203\343\203\211\344\275\277\347\224\250\343\203\201\343\202\247\343\203\203\343\202\257\0"
LC238:
	.ascii "\343\202\271\343\203\254\343\203\203\343\203\211\343\203\206\343\202\271\343\203\210"
	.ascii "9-1(N)\0"
LC239:
	.ascii "\343\202\271\343\203\254\343\203\203\343\203\211\343\203\206\343\202\271\343\203\210"
	.ascii "9-2(N)\0"
LC240:
	.ascii "\343\202\271\343\203\254\343\203\203\343\203\211\343\203\206\343\202\271\343\203\210"
	.ascii "9-3(R)\0"
LC241:
	.ascii "\343\202\271\343\203\254\343\203\203\343\203\211\343\203\206\343\202\271\343\203\210"
	.ascii "9-4(R)\0"
LC242:
	.ascii "sleep(500msec)\0"
LC243:
	.ascii "join\0"
LC244:
	.ascii "\343\202\271\343\203\254\343\203\203\343\203\211\343\203\206\343\202\271\343\203\210"
	.ascii "9-5(N)\0"
LC245:
	.ascii "sleep(200msec)\0"
LC246:
	.ascii "\343\202\271\343\203\254\343\203\203\343\203\211\343\203\206\343\202\271\343\203\210"
	.ascii "9-6(N)\0"
LC247:
	.ascii "\343\202\271\343\203\254\343\203\203\343\203\211\343\203\206\343\202\271\343\203\210"
	.ascii "9-7(R)\0"
LC248:
	.ascii "\343\202\271\343\203\254\343\203\203\343\203\211\343\203\206\343\202\271\343\203\210"
	.ascii "9-8(R)\0"
	.align 4
LC249:
	.ascii "\343\202\271\343\203\254\343\203\203\343\203\211\343\203\206\343\202\271\343\203\210(\345\211\262\343\202\212\350\276\274\343\201\277)\0"
LC250:
	.ascii "\343\202\271\343\203\254\343\203\203\343\203\211\343\203\206\343\202\271\343\203\210"
	.ascii "9-9(N)\0"
LC251:
	.ascii "\343\202\271\343\203\254\343\203\203\343\203\211\343\203\206\343\202\271\343\203\210"
	.ascii "9-10(N)\0"
LC252:
	.ascii "\343\202\271\343\203\254\343\203\203\343\203\211\343\203\206\343\202\271\343\203\210"
	.ascii "9-11(R)\0"
LC253:
	.ascii "\343\202\271\343\203\254\343\203\203\343\203\211\343\203\206\343\202\271\343\203\210"
	.ascii "9-12(R)\0"
	.text
	.globl	__Z5test9v
	.def	__Z5test9v;	.scl	2;	.type	32;	.endef
__Z5test9v:
LFB3176:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3176
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$604, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	$LC224, (%esp)
LEHB274:
	call	_puts
LEHE274:
	movl	$LC225, (%esp)
LEHB275:
	call	_puts
LEHE275:
	movl	$1, 4(%esp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CSmartStackAllocatorWithBuffILj128EEC1EN15IStackAllocator9E_ORDEREDE
	movl	$0, 8(%esp)
	leal	-556(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-240(%ebp), %eax
	movl	%eax, (%esp)
LEHB276:
	call	__ZN28CTempPolySmartStackAllocatorC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE
LEHE276:
	movl	$12, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1398
	movl	$LC226, 4(%esp)
	movl	%ebx, (%esp)
LEHB277:
	call	__ZN6CTest9C1EPKc
LEHE277:
	movl	%ebx, %eax
	jmp	L1399
L1398:
	movl	%ebx, %eax
L1399:
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC87, (%esp)
LEHB278:
	call	_printf
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
	movl	$LC228, (%esp)
	call	_puts
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator6beginNEv
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
LEHE278:
	movl	$-1, 4(%esp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE
	movl	$12, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1400
	movl	$LC229, 4(%esp)
	movl	%ebx, (%esp)
LEHB279:
	call	__ZN6CTest9C1EPKc
LEHE279:
	movl	%ebx, %eax
	jmp	L1401
L1400:
	movl	%ebx, %eax
L1401:
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC89, (%esp)
LEHB280:
	call	_printf
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
	movl	$LC230, (%esp)
	call	_puts
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator6beginREv
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
LEHE280:
	movl	$1, 4(%esp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE
	movl	$12, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1402
	movl	$LC231, 4(%esp)
	movl	%ebx, (%esp)
LEHB281:
	call	__ZN6CTest9C1EPKc
LEHE281:
	movl	%ebx, %eax
	jmp	L1403
L1402:
	movl	%ebx, %eax
L1403:
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC110, (%esp)
LEHB282:
	call	_printf
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
LEHE282:
	movl	$-1, 4(%esp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE
	movl	$12, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1404
	movl	$LC232, 4(%esp)
	movl	%ebx, (%esp)
LEHB283:
	call	__ZN6CTest9C1EPKc
LEHE283:
	movl	%ebx, %eax
	jmp	L1405
L1404:
	movl	%ebx, %eax
L1405:
	movl	%eax, -40(%ebp)
	movl	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC112, (%esp)
LEHB284:
	call	_printf
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
	cmpl	$0, -28(%ebp)
	je	L1406
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
L1406:
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
	cmpl	$0, -32(%ebp)
	je	L1407
	movl	-32(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
L1407:
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
	cmpl	$0, -36(%ebp)
	je	L1408
	movl	-36(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-36(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
L1408:
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
	cmpl	$0, -40(%ebp)
	je	L1409
	movl	-40(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-40(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
L1409:
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
LEHE284:
	movl	$1, 4(%esp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE
	movl	$12, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1410
	movl	$LC233, 4(%esp)
	movl	%ebx, (%esp)
LEHB285:
	call	__ZN6CTest9C1EPKc
LEHE285:
	movl	%ebx, %eax
	jmp	L1411
L1410:
	movl	%ebx, %eax
L1411:
	movl	%eax, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC114, (%esp)
LEHB286:
	call	_printf
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
LEHE286:
	movl	$-1, 4(%esp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator17setDefaultOrderedEN15IStackAllocator9E_ORDEREDE
	movl	$12, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1412
	movl	$LC234, 4(%esp)
	movl	%ebx, (%esp)
LEHB287:
	call	__ZN6CTest9C1EPKc
LEHE287:
	movl	%ebx, %eax
	jmp	L1413
L1412:
	movl	%ebx, %eax
L1413:
	movl	%eax, -48(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC116, (%esp)
LEHB288:
	call	_printf
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
	cmpl	$0, -44(%ebp)
	je	L1414
	movl	-44(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-44(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
L1414:
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
	cmpl	$0, -48(%ebp)
	je	L1415
	movl	-48(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-48(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
L1415:
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
	movl	$LC235, (%esp)
	call	_puts
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator6clearNEv
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
	movl	$LC236, (%esp)
	call	_puts
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocator6clearREv
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
LEHE288:
	leal	-240(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CTempPolySmartStackAllocatorD1Ev
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CSmartStackAllocatorWithBuffILj128EED1Ev
	movl	$LC237, (%esp)
LEHB289:
	call	_puts
LEHE289:
	movl	$0, -52(%ebp)
	movl	$0, -56(%ebp)
	movl	$0, -60(%ebp)
	movl	$1, 8(%esp)
	movl	$__ZL16s_stackForThread, 4(%esp)
	leal	-264(%ebp), %eax
	movl	%eax, (%esp)
LEHB290:
	call	__ZN28CTempPolySmartStackAllocatorC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE
LEHE290:
	movl	$8, (%esp)
	call	__Znaj
	movl	%eax, -52(%ebp)
	movl	$3, (%esp)
	call	__Znaj
	movl	%eax, -56(%ebp)
	movl	$16, (%esp)
	call	__Znaj
	movl	%eax, -60(%ebp)
	leal	-264(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CTempPolySmartStackAllocatorD1Ev
	movl	$0, -64(%ebp)
	movl	$0, -68(%ebp)
	movl	$0, -72(%ebp)
	movl	$-1, 8(%esp)
	movl	$__ZL16s_stackForThread, 4(%esp)
	leal	-288(%ebp), %eax
	movl	%eax, (%esp)
LEHB291:
	call	__ZN28CTempPolySmartStackAllocatorC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE
LEHE291:
	movl	$20, (%esp)
	call	__Znaj
	movl	%eax, -64(%ebp)
	movl	$6, (%esp)
	call	__Znaj
	movl	%eax, -68(%ebp)
	movl	$56, (%esp)
	call	__Znaj
	movl	%eax, -72(%ebp)
	leal	-288(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CTempPolySmartStackAllocatorD1Ev
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
LEHB292:
	call	_printf
	movl	$LC228, (%esp)
	call	_puts
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZN20CSmartStackAllocator6beginNEv
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
	movl	$LC230, (%esp)
	call	_puts
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZN20CSmartStackAllocator6beginREv
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
LEHE292:
	movl	$LC238, 8(%esp)
	movl	$__Z13test9thread_nPKc, 4(%esp)
	leal	-292(%ebp), %eax
	movl	%eax, (%esp)
LEHB293:
	call	__ZNSt6threadC1IRFvPKcEIRA28_S1_EEEOT_DpOT0_
LEHE293:
	movl	$LC239, 8(%esp)
	movl	$__Z13test9thread_nPKc, 4(%esp)
	leal	-296(%ebp), %eax
	movl	%eax, (%esp)
LEHB294:
	call	__ZNSt6threadC1IRFvPKcEIRA28_S1_EEEOT_DpOT0_
LEHE294:
	movl	$LC240, 8(%esp)
	movl	$__Z13test9thread_rPKc, 4(%esp)
	leal	-300(%ebp), %eax
	movl	%eax, (%esp)
LEHB295:
	call	__ZNSt6threadC1IRFvPKcEIRA28_S1_EEEOT_DpOT0_
LEHE295:
	movl	$LC241, 8(%esp)
	movl	$__Z13test9thread_rPKc, 4(%esp)
	leal	-304(%ebp), %eax
	movl	%eax, (%esp)
LEHB296:
	call	__ZNSt6threadC1IRFvPKcEIRA28_S1_EEEOT_DpOT0_
LEHE296:
	movl	$500, -204(%ebp)
	leal	-204(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-216(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IivEERKT_
	leal	-216(%ebp), %eax
	movl	%eax, (%esp)
LEHB297:
	call	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1000EEEEvRKNSt6chrono8durationIT_T0_EE
LEHE297:
	movl	$LC242, (%esp)
LEHB298:
	call	_puts
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
	leal	-292(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
	leal	-296(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
	leal	-300(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
	leal	-304(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
	movl	$LC243, (%esp)
	call	_puts
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
LEHE298:
	leal	-304(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	leal	-300(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	leal	-296(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	leal	-292(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	movl	$LC244, 8(%esp)
	movl	$__Z13test9thread_nPKc, 4(%esp)
	leal	-308(%ebp), %eax
	movl	%eax, (%esp)
LEHB299:
	call	__ZNSt6threadC1IRFvPKcEIRA28_S1_EEEOT_DpOT0_
LEHE299:
	movl	$200, -188(%ebp)
	leal	-188(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-200(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IivEERKT_
	leal	-200(%ebp), %eax
	movl	%eax, (%esp)
LEHB300:
	call	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1000EEEEvRKNSt6chrono8durationIT_T0_EE
LEHE300:
	movl	$LC245, (%esp)
LEHB301:
	call	_puts
	movl	$LC246, 8(%esp)
	movl	$__Z13test9thread_nPKc, 4(%esp)
	leal	-312(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadC1IRFvPKcEIRA28_S1_EEEOT_DpOT0_
LEHE301:
	movl	$200, -172(%ebp)
	leal	-172(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-184(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IivEERKT_
	leal	-184(%ebp), %eax
	movl	%eax, (%esp)
LEHB302:
	call	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1000EEEEvRKNSt6chrono8durationIT_T0_EE
LEHE302:
	movl	$LC245, (%esp)
LEHB303:
	call	_puts
	movl	$LC247, 8(%esp)
	movl	$__Z13test9thread_rPKc, 4(%esp)
	leal	-316(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadC1IRFvPKcEIRA28_S1_EEEOT_DpOT0_
LEHE303:
	movl	$200, -156(%ebp)
	leal	-156(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-168(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IivEERKT_
	leal	-168(%ebp), %eax
	movl	%eax, (%esp)
LEHB304:
	call	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1000EEEEvRKNSt6chrono8durationIT_T0_EE
LEHE304:
	movl	$LC245, (%esp)
LEHB305:
	call	_puts
	movl	$LC248, 8(%esp)
	movl	$__Z13test9thread_rPKc, 4(%esp)
	leal	-320(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadC1IRFvPKcEIRA28_S1_EEEOT_DpOT0_
LEHE305:
	movl	$200, -140(%ebp)
	leal	-140(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IivEERKT_
	leal	-152(%ebp), %eax
	movl	%eax, (%esp)
LEHB306:
	call	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1000EEEEvRKNSt6chrono8durationIT_T0_EE
LEHE306:
	movl	$LC245, (%esp)
LEHB307:
	call	_puts
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
LEHE307:
	movl	$1, 4(%esp)
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CSmartStackAllocatorWithBuffILj128EEC1EN15IStackAllocator9E_ORDEREDE
	movl	$0, 8(%esp)
	leal	-556(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-360(%ebp), %eax
	movl	%eax, (%esp)
LEHB308:
	call	__ZN28CTempPolySmartStackAllocatorC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE
LEHE308:
	movl	$12, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1416
	movl	$LC249, 4(%esp)
	movl	%ebx, (%esp)
LEHB309:
	call	__ZN6CTest9C1EPKc
LEHE309:
	movl	%ebx, %eax
	jmp	L1417
L1416:
	movl	%ebx, %eax
L1417:
	movl	%eax, -76(%ebp)
	cmpl	$0, -76(%ebp)
	je	L1418
	movl	-76(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-76(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
L1418:
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
LEHB310:
	call	_printf
LEHE310:
	leal	-360(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CTempPolySmartStackAllocatorD1Ev
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CSmartStackAllocatorWithBuffILj128EED1Ev
	movl	$LC250, 8(%esp)
	movl	$__Z13test9thread_nPKc, 4(%esp)
	leal	-324(%ebp), %eax
	movl	%eax, (%esp)
LEHB311:
	call	__ZNSt6threadC1IRFvPKcEIRA28_S1_EEEOT_DpOT0_
LEHE311:
	movl	$200, -124(%ebp)
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-136(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IivEERKT_
	leal	-136(%ebp), %eax
	movl	%eax, (%esp)
LEHB312:
	call	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1000EEEEvRKNSt6chrono8durationIT_T0_EE
LEHE312:
	movl	$LC245, (%esp)
LEHB313:
	call	_puts
	movl	$LC251, 8(%esp)
	movl	$__Z13test9thread_nPKc, 4(%esp)
	leal	-328(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadC1IRFvPKcEIRA29_S1_EEEOT_DpOT0_
LEHE313:
	movl	$200, -108(%ebp)
	leal	-108(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IivEERKT_
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
LEHB314:
	call	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1000EEEEvRKNSt6chrono8durationIT_T0_EE
LEHE314:
	movl	$LC245, (%esp)
LEHB315:
	call	_puts
	movl	$LC252, 8(%esp)
	movl	$__Z13test9thread_rPKc, 4(%esp)
	leal	-332(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadC1IRFvPKcEIRA29_S1_EEEOT_DpOT0_
LEHE315:
	movl	$200, -92(%ebp)
	leal	-92(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IivEERKT_
	leal	-104(%ebp), %eax
	movl	%eax, (%esp)
LEHB316:
	call	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1000EEEEvRKNSt6chrono8durationIT_T0_EE
LEHE316:
	movl	$LC245, (%esp)
LEHB317:
	call	_puts
	movl	$LC253, 8(%esp)
	movl	$__Z13test9thread_rPKc, 4(%esp)
	leal	-336(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadC1IRFvPKcEIRA29_S1_EEEOT_DpOT0_
LEHE317:
	movl	$200, -80(%ebp)
	leal	-80(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IivEERKT_
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
LEHB318:
	call	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1000EEEEvRKNSt6chrono8durationIT_T0_EE
LEHE318:
	movl	$LC245, (%esp)
LEHB319:
	call	_puts
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
	leal	-308(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
	leal	-312(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
	leal	-316(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
	leal	-320(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
	leal	-324(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
	leal	-328(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
	leal	-332(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
	leal	-336(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
	movl	$LC243, (%esp)
	call	_puts
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_printf
LEHE319:
	leal	-336(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	leal	-332(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	leal	-328(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	leal	-324(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	leal	-320(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	leal	-316(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	leal	-312(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	leal	-308(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	movl	$0, 8(%esp)
	movl	$__ZL16s_stackForThread, 4(%esp)
	leal	-384(%ebp), %eax
	movl	%eax, (%esp)
LEHB320:
	call	__ZN28CTempPolySmartStackAllocatorC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE
LEHE320:
	movl	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	movl	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	movl	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	movl	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	movl	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterREv
	movl	%eax, -572(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator11getCounterNEv
	movl	%eax, -576(%ebp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginREv
	movl	%eax, %edi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator9getBeginNEv
	movl	%eax, %esi
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZNK20CSmartStackAllocator10getMarkerNEv
	movl	-572(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-576(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
LEHB321:
	call	_printf
LEHE321:
	leal	-384(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CTempPolySmartStackAllocatorD1Ev
	jmp	L1497
L1460:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZdlPv
	movl	%esi, %ebx
	jmp	L1420
L1462:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZdlPv
	movl	%esi, %ebx
	jmp	L1420
L1463:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZdlPv
	movl	%esi, %ebx
	jmp	L1420
L1464:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZdlPv
	movl	%esi, %ebx
	jmp	L1420
L1465:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZdlPv
	movl	%esi, %ebx
	jmp	L1420
L1466:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZdlPv
	movl	%esi, %ebx
	jmp	L1420
L1461:
	movl	%eax, %ebx
L1420:
	leal	-240(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CTempPolySmartStackAllocatorD1Ev
	jmp	L1426
L1459:
	movl	%eax, %ebx
L1426:
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CSmartStackAllocatorWithBuffILj128EED1Ev
	movl	%ebx, %eax
	jmp	L1427
L1458:
L1427:
	movl	%eax, (%esp)
LEHB322:
	call	__Unwind_Resume
L1467:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L1468:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L1473:
	movl	%eax, %ebx
	jmp	L1431
L1474:
	movl	%eax, %ebx
L1431:
	leal	-304(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	jmp	L1432
L1472:
	movl	%eax, %ebx
L1432:
	leal	-300(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	jmp	L1433
L1471:
	movl	%eax, %ebx
L1433:
	leal	-296(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	jmp	L1434
L1470:
	movl	%eax, %ebx
L1434:
	leal	-292(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	movl	%ebx, %eax
	jmp	L1435
L1469:
L1435:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L1476:
	movl	%eax, %ebx
	jmp	L1437
L1478:
	movl	%eax, %ebx
	jmp	L1439
L1480:
	movl	%eax, %ebx
	jmp	L1441
L1482:
	movl	%eax, %ebx
	jmp	L1443
L1485:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZdlPv
	movl	%esi, %ebx
	jmp	L1445
L1486:
	movl	%eax, %ebx
L1445:
	leal	-360(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CTempPolySmartStackAllocatorD1Ev
	jmp	L1446
L1484:
	movl	%eax, %ebx
L1446:
	leal	-556(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CSmartStackAllocatorWithBuffILj128EED1Ev
	movl	%ebx, %eax
	movl	%eax, %ebx
	jmp	L1443
L1487:
	movl	%eax, %ebx
	jmp	L1448
L1489:
	movl	%eax, %ebx
	jmp	L1450
L1491:
	movl	%eax, %ebx
	jmp	L1452
L1493:
	movl	%eax, %ebx
	jmp	L1454
L1494:
	movl	%eax, %ebx
L1454:
	leal	-336(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	jmp	L1452
L1492:
	movl	%eax, %ebx
L1452:
	leal	-332(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	jmp	L1450
L1490:
	movl	%eax, %ebx
L1450:
	leal	-328(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	jmp	L1448
L1488:
	movl	%eax, %ebx
L1448:
	leal	-324(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	jmp	L1443
L1483:
	movl	%eax, %ebx
L1443:
	leal	-320(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	jmp	L1441
L1481:
	movl	%eax, %ebx
L1441:
	leal	-316(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	jmp	L1439
L1479:
	movl	%eax, %ebx
L1439:
	leal	-312(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	jmp	L1437
L1477:
	movl	%eax, %ebx
L1437:
	leal	-308(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6threadD1Ev
	movl	%ebx, %eax
	jmp	L1455
L1475:
L1455:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L1496:
	movl	%eax, %ebx
	leal	-384(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CTempPolySmartStackAllocatorD1Ev
	movl	%ebx, %eax
	jmp	L1457
L1495:
L1457:
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE322:
L1497:
	addl	$604, %esp
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
LFE3176:
	.section	.gcc_except_table,"w"
LLSDA3176:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3176-LLSDACSB3176
LLSDACSB3176:
	.uleb128 LEHB274-LFB3176
	.uleb128 LEHE274-LEHB274
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB275-LFB3176
	.uleb128 LEHE275-LEHB275
	.uleb128 L1458-LFB3176
	.uleb128 0
	.uleb128 LEHB276-LFB3176
	.uleb128 LEHE276-LEHB276
	.uleb128 L1459-LFB3176
	.uleb128 0
	.uleb128 LEHB277-LFB3176
	.uleb128 LEHE277-LEHB277
	.uleb128 L1460-LFB3176
	.uleb128 0
	.uleb128 LEHB278-LFB3176
	.uleb128 LEHE278-LEHB278
	.uleb128 L1461-LFB3176
	.uleb128 0
	.uleb128 LEHB279-LFB3176
	.uleb128 LEHE279-LEHB279
	.uleb128 L1462-LFB3176
	.uleb128 0
	.uleb128 LEHB280-LFB3176
	.uleb128 LEHE280-LEHB280
	.uleb128 L1461-LFB3176
	.uleb128 0
	.uleb128 LEHB281-LFB3176
	.uleb128 LEHE281-LEHB281
	.uleb128 L1463-LFB3176
	.uleb128 0
	.uleb128 LEHB282-LFB3176
	.uleb128 LEHE282-LEHB282
	.uleb128 L1461-LFB3176
	.uleb128 0
	.uleb128 LEHB283-LFB3176
	.uleb128 LEHE283-LEHB283
	.uleb128 L1464-LFB3176
	.uleb128 0
	.uleb128 LEHB284-LFB3176
	.uleb128 LEHE284-LEHB284
	.uleb128 L1461-LFB3176
	.uleb128 0
	.uleb128 LEHB285-LFB3176
	.uleb128 LEHE285-LEHB285
	.uleb128 L1465-LFB3176
	.uleb128 0
	.uleb128 LEHB286-LFB3176
	.uleb128 LEHE286-LEHB286
	.uleb128 L1461-LFB3176
	.uleb128 0
	.uleb128 LEHB287-LFB3176
	.uleb128 LEHE287-LEHB287
	.uleb128 L1466-LFB3176
	.uleb128 0
	.uleb128 LEHB288-LFB3176
	.uleb128 LEHE288-LEHB288
	.uleb128 L1461-LFB3176
	.uleb128 0
	.uleb128 LEHB289-LFB3176
	.uleb128 LEHE289-LEHB289
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB290-LFB3176
	.uleb128 LEHE290-LEHB290
	.uleb128 L1467-LFB3176
	.uleb128 0
	.uleb128 LEHB291-LFB3176
	.uleb128 LEHE291-LEHB291
	.uleb128 L1468-LFB3176
	.uleb128 0
	.uleb128 LEHB292-LFB3176
	.uleb128 LEHE292-LEHB292
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB293-LFB3176
	.uleb128 LEHE293-LEHB293
	.uleb128 L1469-LFB3176
	.uleb128 0
	.uleb128 LEHB294-LFB3176
	.uleb128 LEHE294-LEHB294
	.uleb128 L1470-LFB3176
	.uleb128 0
	.uleb128 LEHB295-LFB3176
	.uleb128 LEHE295-LEHB295
	.uleb128 L1471-LFB3176
	.uleb128 0
	.uleb128 LEHB296-LFB3176
	.uleb128 LEHE296-LEHB296
	.uleb128 L1472-LFB3176
	.uleb128 0
	.uleb128 LEHB297-LFB3176
	.uleb128 LEHE297-LEHB297
	.uleb128 L1473-LFB3176
	.uleb128 0
	.uleb128 LEHB298-LFB3176
	.uleb128 LEHE298-LEHB298
	.uleb128 L1474-LFB3176
	.uleb128 0
	.uleb128 LEHB299-LFB3176
	.uleb128 LEHE299-LEHB299
	.uleb128 L1475-LFB3176
	.uleb128 0
	.uleb128 LEHB300-LFB3176
	.uleb128 LEHE300-LEHB300
	.uleb128 L1476-LFB3176
	.uleb128 0
	.uleb128 LEHB301-LFB3176
	.uleb128 LEHE301-LEHB301
	.uleb128 L1477-LFB3176
	.uleb128 0
	.uleb128 LEHB302-LFB3176
	.uleb128 LEHE302-LEHB302
	.uleb128 L1478-LFB3176
	.uleb128 0
	.uleb128 LEHB303-LFB3176
	.uleb128 LEHE303-LEHB303
	.uleb128 L1479-LFB3176
	.uleb128 0
	.uleb128 LEHB304-LFB3176
	.uleb128 LEHE304-LEHB304
	.uleb128 L1480-LFB3176
	.uleb128 0
	.uleb128 LEHB305-LFB3176
	.uleb128 LEHE305-LEHB305
	.uleb128 L1481-LFB3176
	.uleb128 0
	.uleb128 LEHB306-LFB3176
	.uleb128 LEHE306-LEHB306
	.uleb128 L1482-LFB3176
	.uleb128 0
	.uleb128 LEHB307-LFB3176
	.uleb128 LEHE307-LEHB307
	.uleb128 L1483-LFB3176
	.uleb128 0
	.uleb128 LEHB308-LFB3176
	.uleb128 LEHE308-LEHB308
	.uleb128 L1484-LFB3176
	.uleb128 0
	.uleb128 LEHB309-LFB3176
	.uleb128 LEHE309-LEHB309
	.uleb128 L1485-LFB3176
	.uleb128 0
	.uleb128 LEHB310-LFB3176
	.uleb128 LEHE310-LEHB310
	.uleb128 L1486-LFB3176
	.uleb128 0
	.uleb128 LEHB311-LFB3176
	.uleb128 LEHE311-LEHB311
	.uleb128 L1483-LFB3176
	.uleb128 0
	.uleb128 LEHB312-LFB3176
	.uleb128 LEHE312-LEHB312
	.uleb128 L1487-LFB3176
	.uleb128 0
	.uleb128 LEHB313-LFB3176
	.uleb128 LEHE313-LEHB313
	.uleb128 L1488-LFB3176
	.uleb128 0
	.uleb128 LEHB314-LFB3176
	.uleb128 LEHE314-LEHB314
	.uleb128 L1489-LFB3176
	.uleb128 0
	.uleb128 LEHB315-LFB3176
	.uleb128 LEHE315-LEHB315
	.uleb128 L1490-LFB3176
	.uleb128 0
	.uleb128 LEHB316-LFB3176
	.uleb128 LEHE316-LEHB316
	.uleb128 L1491-LFB3176
	.uleb128 0
	.uleb128 LEHB317-LFB3176
	.uleb128 LEHE317-LEHB317
	.uleb128 L1492-LFB3176
	.uleb128 0
	.uleb128 LEHB318-LFB3176
	.uleb128 LEHE318-LEHB318
	.uleb128 L1493-LFB3176
	.uleb128 0
	.uleb128 LEHB319-LFB3176
	.uleb128 LEHE319-LEHB319
	.uleb128 L1494-LFB3176
	.uleb128 0
	.uleb128 LEHB320-LFB3176
	.uleb128 LEHE320-LEHB320
	.uleb128 L1495-LFB3176
	.uleb128 0
	.uleb128 LEHB321-LFB3176
	.uleb128 LEHE321-LEHB321
	.uleb128 L1496-LFB3176
	.uleb128 0
	.uleb128 LEHB322-LFB3176
	.uleb128 LEHE322-LEHB322
	.uleb128 0
	.uleb128 0
LLSDACSE3176:
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC254:
	.ascii "---------- main:start ----------\0"
	.align 4
LC255:
	.ascii "---------- main:end ----------\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB3177:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	$LC254, (%esp)
	call	_puts
	call	__Z5test0v
	call	__Z5test1v
	call	__Z5test2v
	call	__Z5test3v
	call	__Z6test4av
	call	__Z6test4bv
	call	__Z5test5v
	call	__Z5test6v
	call	__Z5test7v
	call	__Z5test8v
	call	__Z5test9v
	movl	$LC255, (%esp)
	call	_puts
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3177:
	.section	.text$_Z7new_ptrI6CTest0IPKcEEPT_PcDpT0_,"x"
	.linkonce discard
	.globl	__Z7new_ptrI6CTest0IPKcEEPT_PcDpT0_
	.def	__Z7new_ptrI6CTest0IPKcEEPT_PcDpT0_;	.scl	2;	.type	32;	.endef
__Z7new_ptrI6CTest0IPKcEEPT_PcDpT0_:
LFB3178:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3178
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	cmpl	$0, 8(%ebp)
	jne	L1501
	movl	$0, %eax
	jmp	L1507
L1501:
	movl	8(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	$4, (%esp)
	call	__ZnwjPc
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1503
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
LEHB323:
	call	__ZN6CTest0C1EPKc
LEHE323:
	movl	%ebx, %eax
	jmp	L1504
L1503:
	movl	%ebx, %eax
L1504:
	nop
	jmp	L1507
L1506:
	movl	%eax, %edi
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvPc
	movl	%edi, %eax
	movl	%eax, (%esp)
LEHB324:
	call	__Unwind_Resume
LEHE324:
L1507:
	addl	$28, %esp
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
LFE3178:
	.section	.gcc_except_table,"w"
LLSDA3178:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3178-LLSDACSB3178
LLSDACSB3178:
	.uleb128 LEHB323-LFB3178
	.uleb128 LEHE323-LEHB323
	.uleb128 L1506-LFB3178
	.uleb128 0
	.uleb128 LEHB324-LFB3178
	.uleb128 LEHE324-LEHB324
	.uleb128 0
	.uleb128 0
LLSDACSE3178:
	.section	.text$_Z7new_ptrI6CTest0IPKcEEPT_PcDpT0_,"x"
	.linkonce discard
	.weak	__Z7new_ptrI6CTest0JPKcEEPT_PcDpT0_
	.def	__Z7new_ptrI6CTest0JPKcEEPT_PcDpT0_;	.scl	2;	.type	32;	.endef
	.set	__Z7new_ptrI6CTest0JPKcEEPT_PcDpT0_,__Z7new_ptrI6CTest0IPKcEEPT_PcDpT0_
	.section	.text$_Z10delete_ptrI6CTest0EvRPT_Pc,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI6CTest0EvRPT_Pc
	.def	__Z10delete_ptrI6CTest0EvRPT_Pc;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI6CTest0EvRPT_Pc:
LFB3179:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1509
	jmp	L1508
L1509:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest0D1Ev
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1508:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3179:
	.section .rdata,"dr"
LC256:
	.ascii "delete_ptr(p=0x%p)\12\0"
	.section	.text$_Z10delete_ptrI6CTest1EvRPT_,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI6CTest1EvRPT_
	.def	__Z10delete_ptrI6CTest1EvRPT_;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI6CTest1EvRPT_:
LFB3180:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC256, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1512
	jmp	L1511
L1512:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest1D1Ev
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvPc
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1511:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3180:
	.section .rdata,"dr"
	.align 4
LC257:
	.ascii "delete_ptr(p=0x%p, array_num=%d)\12\0"
	.section	.text$_Z10delete_ptrI6CTest1EvRPT_j,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI6CTest1EvRPT_j
	.def	__Z10delete_ptrI6CTest1EvRPT_j;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI6CTest1EvRPT_j:
LFB3181:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC257, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1515
	jmp	L1514
L1515:
	movl	$0, -12(%ebp)
	jmp	L1517
L1518:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest1D1Ev
	addl	$1, -12(%ebp)
L1517:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1518
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdaPvPc
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1514:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3181:
	.section	.text$_Z10delete_ptrIcEvRPT_,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIcEvRPT_
	.def	__Z10delete_ptrIcEvRPT_;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIcEvRPT_:
LFB3182:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC256, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1520
	jmp	L1519
L1520:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvPc
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1519:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3182:
	.section	.text$_Z10delete_ptrIcEvRPT_j,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIcEvRPT_j
	.def	__Z10delete_ptrIcEvRPT_j;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIcEvRPT_j:
LFB3183:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC257, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1523
	jmp	L1522
L1523:
	movl	$0, -12(%ebp)
	jmp	L1525
L1526:
	addl	$1, -12(%ebp)
L1525:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1526
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdaPvPc
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1522:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3183:
	.section	.text$_Z10delete_ptrI8CTest1exEvRPT_,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI8CTest1exEvRPT_
	.def	__Z10delete_ptrI8CTest1exEvRPT_;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI8CTest1exEvRPT_:
LFB3184:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC256, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1528
	jmp	L1527
L1528:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN8CTest1exD1Ev
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvPc
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1527:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3184:
	.section	.text$_ZN10CSingletonI6CTest3EC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CSingletonI6CTest3EC1Ev
	.def	__ZN10CSingletonI6CTest3EC1Ev;	.scl	2;	.type	32;	.endef
__ZN10CSingletonI6CTest3EC1Ev:
LFB3187:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3187
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
	movl	__ZN10CSingletonI6CTest3E11m_singletonE, %eax
	testl	%eax, %eax
	jne	L1536
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZnwI6CTest3EPvjR10CSingletonIT_E
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1532
	movl	%ebx, (%esp)
LEHB325:
	call	__ZN6CTest3C1Ev
LEHE325:
	movl	%ebx, %eax
	jmp	L1533
L1532:
	movl	%ebx, %eax
L1533:
	movl	%eax, __ZN10CSingletonI6CTest3E11m_singletonE
	jmp	L1536
L1535:
	movl	%eax, %esi
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlI6CTest3EvPvR10CSingletonIT_E
	movl	%esi, %eax
	movl	%eax, (%esp)
LEHB326:
	call	__Unwind_Resume
LEHE326:
L1536:
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
LFE3187:
	.section	.gcc_except_table,"w"
LLSDA3187:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3187-LLSDACSB3187
LLSDACSB3187:
	.uleb128 LEHB325-LFB3187
	.uleb128 LEHE325-LEHB325
	.uleb128 L1535-LFB3187
	.uleb128 0
	.uleb128 LEHB326-LFB3187
	.uleb128 LEHE326-LEHB326
	.uleb128 0
	.uleb128 0
LLSDACSE3187:
	.section	.text$_ZN10CSingletonI6CTest3EC1Ev,"x"
	.linkonce discard
	.section	.text$_ZN10CSingletonI6CTest3EptEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CSingletonI6CTest3EptEv
	.def	__ZN10CSingletonI6CTest3EptEv;	.scl	2;	.type	32;	.endef
__ZN10CSingletonI6CTest3EptEv:
LFB3188:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	__ZN10CSingletonI6CTest3E11m_singletonE, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3188:
	.section	.text$_ZN10CSingletonI6CTest3E7destroyEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CSingletonI6CTest3E7destroyEv
	.def	__ZN10CSingletonI6CTest3E7destroyEv;	.scl	2;	.type	32;	.endef
__ZN10CSingletonI6CTest3E7destroyEv:
LFB3189:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	__ZN10CSingletonI6CTest3E11m_singletonE, %eax
	testl	%eax, %eax
	jne	L1540
	jmp	L1539
L1540:
	movl	__ZN10CSingletonI6CTest3E11m_singletonE, %eax
	movl	%eax, (%esp)
	call	__ZN6CTest3D1Ev
	movl	__ZN10CSingletonI6CTest3E11m_singletonE, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlI6CTest3EvPvR10CSingletonIT_E
	movl	$0, __ZN10CSingletonI6CTest3E11m_singletonE
L1539:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3189:
	.section	.text$_ZN23CStackAllocatorWithBuffILj64EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj64EEC1Ev
	.def	__ZN23CStackAllocatorWithBuffILj64EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj64EEC1Ev:
LFB3192:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$12, %esp
	movl	8(%ebp), %eax
	leal	16(%eax), %edx
	movl	8(%ebp), %eax
	movl	$64, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN15CStackAllocatorC2EPvj
	movl	8(%ebp), %eax
	movl	$__ZTV23CStackAllocatorWithBuffILj64EE+8, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3192:
	.section	.text$_ZN23CStackAllocatorWithBuffILj64EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj64EED1Ev
	.def	__ZN23CStackAllocatorWithBuffILj64EED1Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj64EED1Ev:
LFB3195:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV23CStackAllocatorWithBuffILj64EE+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CStackAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L1543
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1543:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3195:
	.section	.text$_ZN23CStackAllocatorWithBuffILj64EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj64EED0Ev
	.def	__ZN23CStackAllocatorWithBuffILj64EED0Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj64EED0Ev:
LFB3196:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EED1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3196:
	.section .rdata,"dr"
	.align 4
LC258:
	.ascii "delete_ptr(p=0x%p, array_num=%d, stack_allocator.marker=%d)\12\0"
	.section	.text$_Z10delete_ptrIfEvRPT_jR15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIfEvRPT_jR15CStackAllocator
	.def	__Z10delete_ptrIfEvRPT_jR15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIfEvRPT_jR15CStackAllocator:
LFB3197:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC258, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1549
	jmp	L1548
L1549:
	movl	$0, -12(%ebp)
	jmp	L1551
L1552:
	addl	$1, -12(%ebp)
L1551:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1552
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1548:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3197:
	.section	.text$_Z10delete_ptrIcEvRPT_jR15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIcEvRPT_jR15CStackAllocator
	.def	__Z10delete_ptrIcEvRPT_jR15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIcEvRPT_jR15CStackAllocator:
LFB3198:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC258, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1554
	jmp	L1553
L1554:
	movl	$0, -12(%ebp)
	jmp	L1556
L1557:
	addl	$1, -12(%ebp)
L1556:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1557
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1553:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3198:
	.section	.text$_Z10delete_ptrIiEvRPT_jR15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIiEvRPT_jR15CStackAllocator
	.def	__Z10delete_ptrIiEvRPT_jR15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIiEvRPT_jR15CStackAllocator:
LFB3199:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC258, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1559
	jmp	L1558
L1559:
	movl	$0, -12(%ebp)
	jmp	L1561
L1562:
	addl	$1, -12(%ebp)
L1561:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1562
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1558:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3199:
	.section .rdata,"dr"
	.align 4
LC259:
	.ascii "delete_ptr(p=0x%p, stack_allocator.marker=%d)\12\0"
	.section	.text$_Z10delete_ptrI7CTest4aEvRPT_R15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI7CTest4aEvRPT_R15CStackAllocator
	.def	__Z10delete_ptrI7CTest4aEvRPT_R15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI7CTest4aEvRPT_R15CStackAllocator:
LFB3200:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC259, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1564
	jmp	L1563
L1564:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN7CTest4aD1Ev
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1563:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3200:
	.section	.text$_Z10delete_ptrIfEvRPT_R15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIfEvRPT_R15CStackAllocator
	.def	__Z10delete_ptrIfEvRPT_R15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIfEvRPT_R15CStackAllocator:
LFB3201:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC259, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1567
	jmp	L1566
L1567:
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1566:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3201:
	.section	.text$_Z10delete_ptrIcEvRPT_R15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIcEvRPT_R15CStackAllocator
	.def	__Z10delete_ptrIcEvRPT_R15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIcEvRPT_R15CStackAllocator:
LFB3202:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC259, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1570
	jmp	L1569
L1570:
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1569:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3202:
	.section	.text$_Z10delete_ptrIiEvRPT_R15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIiEvRPT_R15CStackAllocator
	.def	__Z10delete_ptrIiEvRPT_R15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIiEvRPT_R15CStackAllocator:
LFB3203:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC259, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1573
	jmp	L1572
L1573:
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1572:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3203:
	.section	.text$_Z10delete_ptrI7CTest4aEvRPT_jR15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI7CTest4aEvRPT_jR15CStackAllocator
	.def	__Z10delete_ptrI7CTest4aEvRPT_jR15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI7CTest4aEvRPT_jR15CStackAllocator:
LFB3204:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC258, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1576
	jmp	L1575
L1576:
	movl	$0, -12(%ebp)
	jmp	L1578
L1579:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN7CTest4aD1Ev
	addl	$1, -12(%ebp)
L1578:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1579
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1575:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3204:
	.section	.text$_ZN27CDualStackAllocatorWithBuffILj64EEC1EN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN27CDualStackAllocatorWithBuffILj64EEC1EN15IStackAllocator9E_ORDEREDE
	.def	__ZN27CDualStackAllocatorWithBuffILj64EEC1EN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN27CDualStackAllocatorWithBuffILj64EEC1EN15IStackAllocator9E_ORDEREDE:
LFB3207:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	leal	24(%eax), %ecx
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	$64, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocatorC2EPvjN15IStackAllocator9E_ORDEREDE
	movl	8(%ebp), %eax
	movl	$__ZTV27CDualStackAllocatorWithBuffILj64EE+8, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3207:
	.section	.text$_ZN27CDualStackAllocatorWithBuffILj64EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev
	.def	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev;	.scl	2;	.type	32;	.endef
__ZN27CDualStackAllocatorWithBuffILj64EED1Ev:
LFB3210:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV27CDualStackAllocatorWithBuffILj64EE+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L1581
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1581:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3210:
	.section	.text$_ZN27CDualStackAllocatorWithBuffILj64EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN27CDualStackAllocatorWithBuffILj64EED0Ev
	.def	__ZN27CDualStackAllocatorWithBuffILj64EED0Ev;	.scl	2;	.type	32;	.endef
__ZN27CDualStackAllocatorWithBuffILj64EED0Ev:
LFB3211:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3211:
	.section .rdata,"dr"
	.align 4
LC260:
	.ascii "delete_ptr(p=0x%p, array_num=%d, dual_allocator.marker=%d,%d)\12\0"
	.section	.text$_Z10delete_ptrIfEvRPT_jR19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIfEvRPT_jR19CDualStackAllocator
	.def	__Z10delete_ptrIfEvRPT_jR19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIfEvRPT_jR19CDualStackAllocator:
LFB3212:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%ebx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC260, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1587
	jmp	L1586
L1587:
	movl	$0, -12(%ebp)
	jmp	L1589
L1590:
	addl	$1, -12(%ebp)
L1589:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1590
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1586:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3212:
	.section	.text$_Z10delete_ptrIcEvRPT_jR19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIcEvRPT_jR19CDualStackAllocator
	.def	__Z10delete_ptrIcEvRPT_jR19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIcEvRPT_jR19CDualStackAllocator:
LFB3213:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%ebx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC260, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1592
	jmp	L1591
L1592:
	movl	$0, -12(%ebp)
	jmp	L1594
L1595:
	addl	$1, -12(%ebp)
L1594:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1595
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1591:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3213:
	.section	.text$_Z10delete_ptrIiEvRPT_jR19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIiEvRPT_jR19CDualStackAllocator
	.def	__Z10delete_ptrIiEvRPT_jR19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIiEvRPT_jR19CDualStackAllocator:
LFB3214:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%ebx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC260, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1597
	jmp	L1596
L1597:
	movl	$0, -12(%ebp)
	jmp	L1599
L1600:
	addl	$1, -12(%ebp)
L1599:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1600
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1596:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3214:
	.section .rdata,"dr"
	.align 4
LC261:
	.ascii "delete_ptr(p=0x%p, dual_allocator.marker=%d,%d)\12\0"
	.section	.text$_Z10delete_ptrI7CTest4bEvRPT_R19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI7CTest4bEvRPT_R19CDualStackAllocator
	.def	__Z10delete_ptrI7CTest4bEvRPT_R19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI7CTest4bEvRPT_R19CDualStackAllocator:
LFB3215:
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
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC261, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1602
	jmp	L1601
L1602:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN7CTest4bD1Ev
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1601:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3215:
	.section	.text$_Z10delete_ptrIfEvRPT_R19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIfEvRPT_R19CDualStackAllocator
	.def	__Z10delete_ptrIfEvRPT_R19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIfEvRPT_R19CDualStackAllocator:
LFB3216:
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
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC261, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1605
	jmp	L1604
L1605:
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1604:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3216:
	.section	.text$_Z10delete_ptrIcEvRPT_R19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIcEvRPT_R19CDualStackAllocator
	.def	__Z10delete_ptrIcEvRPT_R19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIcEvRPT_R19CDualStackAllocator:
LFB3217:
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
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC261, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1608
	jmp	L1607
L1608:
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1607:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3217:
	.section	.text$_Z10delete_ptrIiEvRPT_R19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIiEvRPT_R19CDualStackAllocator
	.def	__Z10delete_ptrIiEvRPT_R19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIiEvRPT_R19CDualStackAllocator:
LFB3218:
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
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC261, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1611
	jmp	L1610
L1611:
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1610:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3218:
	.section	.text$_Z10delete_ptrI7CTest4bEvRPT_jR19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI7CTest4bEvRPT_jR19CDualStackAllocator
	.def	__Z10delete_ptrI7CTest4bEvRPT_jR19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI7CTest4bEvRPT_jR19CDualStackAllocator:
LFB3219:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerREv
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%ebx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC260, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1614
	jmp	L1613
L1614:
	movl	$0, -12(%ebp)
	jmp	L1616
L1617:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN7CTest4bD1Ev
	addl	$1, -12(%ebp)
L1616:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1617
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1613:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3219:
	.section	.text$_ZNKSt13__atomic_baseIiE4loadESt12memory_order,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13__atomic_baseIiE4loadESt12memory_order
	.def	__ZNKSt13__atomic_baseIiE4loadESt12memory_order;	.scl	2;	.type	32;	.endef
__ZNKSt13__atomic_baseIiE4loadESt12memory_order:
LFB3238:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZStanSt12memory_orderSt23__memory_order_modifier
	movl	%eax, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3238:
	.section	.text$_ZNSt13__atomic_baseIiE5storeEiSt12memory_order,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13__atomic_baseIiE5storeEiSt12memory_order
	.def	__ZNSt13__atomic_baseIiE5storeEiSt12memory_order;	.scl	2;	.type	32;	.endef
__ZNSt13__atomic_baseIiE5storeEiSt12memory_order:
LFB3239:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZStanSt12memory_orderSt23__memory_order_modifier
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	xchgl	(%eax), %edx
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3239:
	.section	.text$_ZNSt13__atomic_baseIiE9fetch_addEiSt12memory_order,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13__atomic_baseIiE9fetch_addEiSt12memory_order
	.def	__ZNSt13__atomic_baseIiE9fetch_addEiSt12memory_order;	.scl	2;	.type	32;	.endef
__ZNSt13__atomic_baseIiE9fetch_addEiSt12memory_order:
LFB3240:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	lock xaddl	%edx, (%eax)
	movl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3240:
	.section	.text$_ZNSt13__atomic_baseIiE9fetch_subEiSt12memory_order,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13__atomic_baseIiE9fetch_subEiSt12memory_order
	.def	__ZNSt13__atomic_baseIiE9fetch_subEiSt12memory_order;	.scl	2;	.type	32;	.endef
__ZNSt13__atomic_baseIiE9fetch_subEiSt12memory_order:
LFB3241:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	negl	%edx
	lock xaddl	%edx, (%eax)
	movl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3241:
	.section	.text$_ZN22CPoolAllocatorWithTypeI6CTest5Li5EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EEC1Ev
	.def	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithTypeI6CTest5Li5EEC1Ev:
LFB3244:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithBuffILj8ELi5EEC2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3244:
	.section	.text$_ZN22CPoolAllocatorWithTypeI6CTest5Li5EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EED1Ev
	.def	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EED1Ev;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithTypeI6CTest5Li5EED1Ev:
LFB3247:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithBuffILj8ELi5EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3247:
	.section	.text$_ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_
	.def	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_:
LFB3248:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator6createI6CTest5IPKcEEEPT_DpT0_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3248:
	.weak	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIJPKcEEEPS0_DpT_
	.def	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIJPKcEEEPS0_DpT_;	.scl	2;	.type	32;	.endef
	.set	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIJPKcEEEPS0_DpT_,__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_
	.section	.text$_ZN22CPoolAllocatorWithTypeI6CTest5Li5EE11destroyDataERPS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE11destroyDataERPS0_
	.def	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE11destroyDataERPS0_;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE11destroyDataERPS0_:
LFB3249:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator7destroyI6CTest5EEvRPT_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3249:
	.section	.text$_ZN14CPoolAllocator6createI7CTest5LIEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createI7CTest5LIEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createI7CTest5LIEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createI7CTest5LIEEEPT_DpT0_:
LFB3250:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$9, (%esp)
	call	__ZnwjR14CPoolAllocator
	testl	%eax, %eax
	je	L1633
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	movb	$0, 8(%eax)
L1633:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3250:
	.weak	__ZN14CPoolAllocator6createI7CTest5LJEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createI7CTest5LJEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN14CPoolAllocator6createI7CTest5LJEEEPT_DpT0_,__ZN14CPoolAllocator6createI7CTest5LIEEEPT_DpT0_
	.section	.text$_ZN14CPoolAllocator6createIcIEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createIcIEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIcIEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createIcIEEEPT_DpT0_:
LFB3251:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	call	__ZnwjR14CPoolAllocator
	testl	%eax, %eax
	je	L1637
	movb	$0, (%eax)
L1637:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3251:
	.weak	__ZN14CPoolAllocator6createIcJEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIcJEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN14CPoolAllocator6createIcJEEEPT_DpT0_,__ZN14CPoolAllocator6createIcIEEEPT_DpT0_
	.section	.text$_ZN14CPoolAllocator6createIsIEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createIsIEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIsIEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createIsIEEEPT_DpT0_:
LFB3252:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$2, (%esp)
	call	__ZnwjR14CPoolAllocator
	testl	%eax, %eax
	je	L1641
	movw	$0, (%eax)
L1641:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3252:
	.weak	__ZN14CPoolAllocator6createIsJEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIsJEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN14CPoolAllocator6createIsJEEEPT_DpT0_,__ZN14CPoolAllocator6createIsIEEEPT_DpT0_
	.section	.text$_ZN14CPoolAllocator6createIiIEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createIiIEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIiIEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createIiIEEEPT_DpT0_:
LFB3253:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZnwjR14CPoolAllocator
	testl	%eax, %eax
	je	L1645
	movl	$0, (%eax)
L1645:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3253:
	.weak	__ZN14CPoolAllocator6createIiJEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIiJEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN14CPoolAllocator6createIiJEEEPT_DpT0_,__ZN14CPoolAllocator6createIiIEEEPT_DpT0_
	.section	.text$_ZN14CPoolAllocator6createIfIEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createIfIEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIfIEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createIfIEEEPT_DpT0_:
LFB3254:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZnwjR14CPoolAllocator
	testl	%eax, %eax
	je	L1649
	movl	LC170, %edx
	movl	%edx, (%eax)
L1649:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3254:
	.weak	__ZN14CPoolAllocator6createIfJEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIfJEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN14CPoolAllocator6createIfJEEEPT_DpT0_,__ZN14CPoolAllocator6createIfIEEEPT_DpT0_
	.section	.text$_ZN14CPoolAllocator6createIdIEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createIdIEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIdIEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createIdIEEEPT_DpT0_:
LFB3255:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZnwjR14CPoolAllocator
	testl	%eax, %eax
	je	L1653
	fldz
	fstpl	(%eax)
L1653:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3255:
	.weak	__ZN14CPoolAllocator6createIdJEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIdJEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN14CPoolAllocator6createIdJEEEPT_DpT0_,__ZN14CPoolAllocator6createIdIEEEPT_DpT0_
	.section	.text$_ZN14CPoolAllocator6createIxIEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createIxIEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIxIEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createIxIEEEPT_DpT0_:
LFB3256:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZnwjR14CPoolAllocator
	testl	%eax, %eax
	je	L1657
	movl	$0, (%eax)
	movl	$0, 4(%eax)
L1657:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3256:
	.weak	__ZN14CPoolAllocator6createIxJEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIxJEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN14CPoolAllocator6createIxJEEEPT_DpT0_,__ZN14CPoolAllocator6createIxIEEEPT_DpT0_
	.section	.text$_ZN14CPoolAllocator7destroyI7CTest5LEEvRPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7destroyI7CTest5LEEvRPT_
	.def	__ZN14CPoolAllocator7destroyI7CTest5LEEvRPT_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7destroyI7CTest5LEEvRPT_:
LFB3257:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1660
	jmp	L1659
L1660:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	12(%ebp), %eax
	movl	$0, (%eax)
L1659:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3257:
	.section	.text$_ZN14CPoolAllocator7destroyIcEEvRPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7destroyIcEEvRPT_
	.def	__ZN14CPoolAllocator7destroyIcEEvRPT_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7destroyIcEEvRPT_:
LFB3258:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1663
	jmp	L1662
L1663:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	12(%ebp), %eax
	movl	$0, (%eax)
L1662:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3258:
	.section	.text$_ZN14CPoolAllocator7destroyIsEEvRPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7destroyIsEEvRPT_
	.def	__ZN14CPoolAllocator7destroyIsEEvRPT_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7destroyIsEEvRPT_:
LFB3259:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1666
	jmp	L1665
L1666:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	12(%ebp), %eax
	movl	$0, (%eax)
L1665:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3259:
	.section	.text$_ZN14CPoolAllocator7destroyIiEEvRPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7destroyIiEEvRPT_
	.def	__ZN14CPoolAllocator7destroyIiEEvRPT_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7destroyIiEEvRPT_:
LFB3260:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1669
	jmp	L1668
L1669:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	12(%ebp), %eax
	movl	$0, (%eax)
L1668:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3260:
	.section	.text$_ZN14CPoolAllocator7destroyIfEEvRPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7destroyIfEEvRPT_
	.def	__ZN14CPoolAllocator7destroyIfEEvRPT_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7destroyIfEEvRPT_:
LFB3261:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1672
	jmp	L1671
L1672:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	12(%ebp), %eax
	movl	$0, (%eax)
L1671:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3261:
	.section	.text$_ZN14CPoolAllocator7destroyIdEEvRPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7destroyIdEEvRPT_
	.def	__ZN14CPoolAllocator7destroyIdEEvRPT_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7destroyIdEEvRPT_:
LFB3262:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1675
	jmp	L1674
L1675:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	12(%ebp), %eax
	movl	$0, (%eax)
L1674:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3262:
	.section	.text$_ZN14CPoolAllocator7destroyIxEEvRPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7destroyIxEEvRPT_
	.def	__ZN14CPoolAllocator7destroyIxEEvRPT_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7destroyIxEEvRPT_:
LFB3263:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1678
	jmp	L1677
L1678:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	12(%ebp), %eax
	movl	$0, (%eax)
L1677:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3263:
	.section .rdata,"dr"
	.align 4
LC263:
	.ascii "delete_ptr(p=0x%p, i_allocator=\"%s\":%d/%d/%d)\12\0"
	.section	.text$_Z10delete_ptrI6CTest6EvRPT_R10IAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI6CTest6EvRPT_R10IAllocator
	.def	__Z10delete_ptrI6CTest6EvRPT_R10IAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI6CTest6EvRPT_R10IAllocator:
LFB3264:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %edi
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC263, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1681
	jmp	L1680
L1681:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR10IAllocator
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1680:
	addl	$44, %esp
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
LFE3264:
	.section .rdata,"dr"
	.align 4
LC264:
	.ascii "delete_ptr(p=0x%p, array_num=%d, i_allocator=\"%s\":%d/%d/%d)\12\0"
	.section	.text$_Z10delete_ptrI6CTest6EvRPT_jR10IAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI6CTest6EvRPT_jR10IAllocator
	.def	__Z10delete_ptrI6CTest6EvRPT_jR10IAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI6CTest6EvRPT_jR10IAllocator:
LFB3265:
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
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %edi
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %esi
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%edi, 24(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC264, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1684
	jmp	L1683
L1684:
	movl	$0, -28(%ebp)
	jmp	L1686
L1687:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, (%esp)
	call	*%eax
	addl	$1, -28(%ebp)
L1686:
	movl	-28(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1687
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdaPvR10IAllocator
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1683:
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
LFE3265:
	.section	.text$_Z10delete_ptrI8CTest6exEvRPT_R10IAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI8CTest6exEvRPT_R10IAllocator
	.def	__Z10delete_ptrI8CTest6exEvRPT_R10IAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI8CTest6exEvRPT_R10IAllocator:
LFB3266:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %edi
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC263, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1689
	jmp	L1688
L1689:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR10IAllocator
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1688:
	addl	$44, %esp
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
LFE3266:
	.section	.text$_ZN21CMonoAllocAdpWithBuffILj128EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN21CMonoAllocAdpWithBuffILj128EEC1Ev
	.def	__ZN21CMonoAllocAdpWithBuffILj128EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN21CMonoAllocAdpWithBuffILj128EEC1Ev:
LFB3269:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$12, %esp
	movl	8(%ebp), %eax
	leal	16(%eax), %edx
	movl	8(%ebp), %eax
	movl	$128, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN13CMonoAllocAdpC2EPvj
	movl	8(%ebp), %eax
	movl	$__ZTV21CMonoAllocAdpWithBuffILj128EE+8, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3269:
	.section	.text$_ZN21CMonoAllocAdpWithBuffILj128EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN21CMonoAllocAdpWithBuffILj128EED1Ev
	.def	__ZN21CMonoAllocAdpWithBuffILj128EED1Ev;	.scl	2;	.type	32;	.endef
__ZN21CMonoAllocAdpWithBuffILj128EED1Ev:
LFB3272:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV21CMonoAllocAdpWithBuffILj128EE+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CMonoAllocAdpD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L1692
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1692:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3272:
	.section	.text$_ZN21CMonoAllocAdpWithBuffILj128EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN21CMonoAllocAdpWithBuffILj128EED0Ev
	.def	__ZN21CMonoAllocAdpWithBuffILj128EED0Ev;	.scl	2;	.type	32;	.endef
__ZN21CMonoAllocAdpWithBuffILj128EED0Ev:
LFB3273:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN21CMonoAllocAdpWithBuffILj128EED1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3273:
	.section	.text$_ZN23CStackAllocatorWithBuffILj128EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj128EEC1Ev
	.def	__ZN23CStackAllocatorWithBuffILj128EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj128EEC1Ev:
LFB3276:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$12, %esp
	movl	8(%ebp), %eax
	leal	16(%eax), %edx
	movl	8(%ebp), %eax
	movl	$128, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN15CStackAllocatorC2EPvj
	movl	8(%ebp), %eax
	movl	$__ZTV23CStackAllocatorWithBuffILj128EE+8, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3276:
	.section	.text$_ZN23CStackAllocatorWithBuffILj128EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj128EED1Ev
	.def	__ZN23CStackAllocatorWithBuffILj128EED1Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj128EED1Ev:
LFB3279:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV23CStackAllocatorWithBuffILj128EE+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CStackAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L1698
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1698:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3279:
	.section	.text$_ZN23CStackAllocatorWithBuffILj128EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj128EED0Ev
	.def	__ZN23CStackAllocatorWithBuffILj128EED0Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj128EED0Ev:
LFB3280:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj128EED1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3280:
	.section	.text$_ZN27CDualStackAllocatorWithBuffILj128EEC1EN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN27CDualStackAllocatorWithBuffILj128EEC1EN15IStackAllocator9E_ORDEREDE
	.def	__ZN27CDualStackAllocatorWithBuffILj128EEC1EN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN27CDualStackAllocatorWithBuffILj128EEC1EN15IStackAllocator9E_ORDEREDE:
LFB3283:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	leal	24(%eax), %ecx
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	$128, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocatorC2EPvjN15IStackAllocator9E_ORDEREDE
	movl	8(%ebp), %eax
	movl	$__ZTV27CDualStackAllocatorWithBuffILj128EE+8, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3283:
	.section	.text$_ZN27CDualStackAllocatorWithBuffILj128EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN27CDualStackAllocatorWithBuffILj128EED1Ev
	.def	__ZN27CDualStackAllocatorWithBuffILj128EED1Ev;	.scl	2;	.type	32;	.endef
__ZN27CDualStackAllocatorWithBuffILj128EED1Ev:
LFB3286:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV27CDualStackAllocatorWithBuffILj128EE+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L1704
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1704:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3286:
	.section	.text$_ZN27CDualStackAllocatorWithBuffILj128EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN27CDualStackAllocatorWithBuffILj128EED0Ev
	.def	__ZN27CDualStackAllocatorWithBuffILj128EED0Ev;	.scl	2;	.type	32;	.endef
__ZN27CDualStackAllocatorWithBuffILj128EED0Ev:
LFB3287:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj128EED1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3287:
	.section	.text$_ZN22CPoolAllocatorWithBuffILj24ELi5EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithBuffILj24ELi5EEC1Ev
	.def	__ZN22CPoolAllocatorWithBuffILj24ELi5EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithBuffILj24ELi5EEC1Ev:
LFB3290:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	leal	24(%eax), %edx
	movl	8(%ebp), %eax
	movl	$5, 12(%esp)
	movl	$24, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocatorC2EPvji
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3290:
	.section	.text$_ZN22CPoolAllocatorWithBuffILj24ELi5EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithBuffILj24ELi5EED1Ev
	.def	__ZN22CPoolAllocatorWithBuffILj24ELi5EED1Ev;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithBuffILj24ELi5EED1Ev:
LFB3293:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocatorD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3293:
	.section	.text$_ZN30CTempPolyAllocatorWithStackAdpI15CIStackAllocAdpEC2ER15IStackAllocatorNS0_13E_AUTO_REWINDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN30CTempPolyAllocatorWithStackAdpI15CIStackAllocAdpEC2ER15IStackAllocatorNS0_13E_AUTO_REWINDE
	.def	__ZN30CTempPolyAllocatorWithStackAdpI15CIStackAllocAdpEC2ER15IStackAllocatorNS0_13E_AUTO_REWINDE;	.scl	2;	.type	32;	.endef
__ZN30CTempPolyAllocatorWithStackAdpI15CIStackAllocAdpEC2ER15IStackAllocatorNS0_13E_AUTO_REWINDE:
LFB3295:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3295
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseC2ER10IAllocator
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
LEHB327:
	call	__ZN15CIStackAllocAdpC1ER15IStackAllocatorNS_13E_AUTO_REWINDE
LEHE327:
	jmp	L1715
L1714:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseD2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB328:
	call	__Unwind_Resume
LEHE328:
L1715:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3295:
	.section	.gcc_except_table,"w"
LLSDA3295:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3295-LLSDACSB3295
LLSDACSB3295:
	.uleb128 LEHB327-LFB3295
	.uleb128 LEHE327-LEHB327
	.uleb128 L1714-LFB3295
	.uleb128 0
	.uleb128 LEHB328-LFB3295
	.uleb128 LEHE328-LEHB328
	.uleb128 0
	.uleb128 0
LLSDACSE3295:
	.section	.text$_ZN30CTempPolyAllocatorWithStackAdpI15CIStackAllocAdpEC2ER15IStackAllocatorNS0_13E_AUTO_REWINDE,"x"
	.linkonce discard
	.section	.text$_ZN30CTempPolyAllocatorWithStackAdpI15CIStackAllocAdpED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN30CTempPolyAllocatorWithStackAdpI15CIStackAllocAdpED2Ev
	.def	__ZN30CTempPolyAllocatorWithStackAdpI15CIStackAllocAdpED2Ev;	.scl	2;	.type	32;	.endef
__ZN30CTempPolyAllocatorWithStackAdpI15CIStackAllocAdpED2Ev:
LFB3298:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3298:
	.section	.text$_ZN30CTempPolyAllocatorWithStackAdpI14CStackAllocAdpEC2ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN30CTempPolyAllocatorWithStackAdpI14CStackAllocAdpEC2ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
	.def	__ZN30CTempPolyAllocatorWithStackAdpI14CStackAllocAdpEC2ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE;	.scl	2;	.type	32;	.endef
__ZN30CTempPolyAllocatorWithStackAdpI14CStackAllocAdpEC2ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE:
LFB3301:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3301
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseC2ER10IAllocator
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
LEHB329:
	call	__ZN14CStackAllocAdpC1ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE329:
	jmp	L1721
L1720:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseD2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB330:
	call	__Unwind_Resume
LEHE330:
L1721:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3301:
	.section	.gcc_except_table,"w"
LLSDA3301:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3301-LLSDACSB3301
LLSDACSB3301:
	.uleb128 LEHB329-LFB3301
	.uleb128 LEHE329-LEHB329
	.uleb128 L1720-LFB3301
	.uleb128 0
	.uleb128 LEHB330-LFB3301
	.uleb128 LEHE330-LEHB330
	.uleb128 0
	.uleb128 0
LLSDACSE3301:
	.section	.text$_ZN30CTempPolyAllocatorWithStackAdpI14CStackAllocAdpEC2ER15CStackAllocatorN15CIStackAllocAdp13E_AUTO_REWINDE,"x"
	.linkonce discard
	.section	.text$_ZN30CTempPolyAllocatorWithStackAdpI14CStackAllocAdpED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN30CTempPolyAllocatorWithStackAdpI14CStackAllocAdpED2Ev
	.def	__ZN30CTempPolyAllocatorWithStackAdpI14CStackAllocAdpED2Ev;	.scl	2;	.type	32;	.endef
__ZN30CTempPolyAllocatorWithStackAdpI14CStackAllocAdpED2Ev:
LFB3304:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZN14CStackAllocAdpD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3304:
	.section	.text$_ZN30CTempPolyAllocatorWithStackAdpI18CDualStackAllocAdpEC2ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN30CTempPolyAllocatorWithStackAdpI18CDualStackAllocAdpEC2ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE
	.def	__ZN30CTempPolyAllocatorWithStackAdpI18CDualStackAllocAdpEC2ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE;	.scl	2;	.type	32;	.endef
__ZN30CTempPolyAllocatorWithStackAdpI18CDualStackAllocAdpEC2ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE:
LFB3307:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3307
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseC2ER10IAllocator
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
LEHB331:
	call	__ZN18CDualStackAllocAdpC1ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE
LEHE331:
	jmp	L1727
L1726:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseD2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB332:
	call	__Unwind_Resume
LEHE332:
L1727:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3307:
	.section	.gcc_except_table,"w"
LLSDA3307:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3307-LLSDACSB3307
LLSDACSB3307:
	.uleb128 LEHB331-LFB3307
	.uleb128 LEHE331-LEHB331
	.uleb128 L1726-LFB3307
	.uleb128 0
	.uleb128 LEHB332-LFB3307
	.uleb128 LEHE332-LEHB332
	.uleb128 0
	.uleb128 0
LLSDACSE3307:
	.section	.text$_ZN30CTempPolyAllocatorWithStackAdpI18CDualStackAllocAdpEC2ER19CDualStackAllocatorN15IStackAllocator9E_ORDEREDEN15CIStackAllocAdp13E_AUTO_REWINDE,"x"
	.linkonce discard
	.section	.text$_ZN30CTempPolyAllocatorWithStackAdpI18CDualStackAllocAdpED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN30CTempPolyAllocatorWithStackAdpI18CDualStackAllocAdpED2Ev
	.def	__ZN30CTempPolyAllocatorWithStackAdpI18CDualStackAllocAdpED2Ev;	.scl	2;	.type	32;	.endef
__ZN30CTempPolyAllocatorWithStackAdpI18CDualStackAllocAdpED2Ev:
LFB3310:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZN18CDualStackAllocAdpD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3310:
	.section	.text$_Z11newWithInfoI6CTest7IPKcEEPT_S2_S2_jDpT0_,"x"
	.linkonce discard
	.globl	__Z11newWithInfoI6CTest7IPKcEEPT_S2_S2_jDpT0_
	.def	__Z11newWithInfoI6CTest7IPKcEEPT_S2_S2_jDpT0_;	.scl	2;	.type	32;	.endef
__Z11newWithInfoI6CTest7IPKcEEPT_S2_S2_jDpT0_:
LFB3312:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3312
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
	call	__Z28getCurrentCallPointNameDummyv
	movl	%eax, -12(%ebp)
	call	__Z16getGameTimeDummyv
	fstps	-16(%ebp)
	movl	$__ZTI6CTest7, (%esp)
	call	__ZNKSt9type_info4nameEv
	movl	16(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	%eax, 20(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10ALLOC_INFOC1EPKcS1_S1_fS1_j
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocator12setAllocInfoEPK10ALLOC_INFO
	movl	$12, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1731
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
LEHB333:
	call	__ZN6CTest7C1EPKc
LEHE333:
	movl	%ebx, %eax
	jmp	L1736
L1731:
	movl	%ebx, %eax
	jmp	L1736
L1735:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZdlPv
	movl	%esi, %eax
	movl	%eax, (%esp)
LEHB334:
	call	__Unwind_Resume
LEHE334:
L1736:
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
LFE3312:
	.section	.gcc_except_table,"w"
LLSDA3312:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3312-LLSDACSB3312
LLSDACSB3312:
	.uleb128 LEHB333-LFB3312
	.uleb128 LEHE333-LEHB333
	.uleb128 L1735-LFB3312
	.uleb128 0
	.uleb128 LEHB334-LFB3312
	.uleb128 LEHE334-LEHB334
	.uleb128 0
	.uleb128 0
LLSDACSE3312:
	.section	.text$_Z11newWithInfoI6CTest7IPKcEEPT_S2_S2_jDpT0_,"x"
	.linkonce discard
	.weak	__Z11newWithInfoI6CTest7JPKcEEPT_S2_S2_jDpT0_
	.def	__Z11newWithInfoI6CTest7JPKcEEPT_S2_S2_jDpT0_;	.scl	2;	.type	32;	.endef
	.set	__Z11newWithInfoI6CTest7JPKcEEPT_S2_S2_jDpT0_,__Z11newWithInfoI6CTest7IPKcEEPT_S2_S2_jDpT0_
	.section	.text$_Z16newArrayWithInfoI6CTest7Lj3EEPT_PKcS4_j,"x"
	.linkonce discard
	.globl	__Z16newArrayWithInfoI6CTest7Lj3EEPT_PKcS4_j
	.def	__Z16newArrayWithInfoI6CTest7Lj3EEPT_PKcS4_j;	.scl	2;	.type	32;	.endef
__Z16newArrayWithInfoI6CTest7Lj3EEPT_PKcS4_j:
LFB3313:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3313
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
	call	__Z28getCurrentCallPointNameDummyv
	movl	%eax, -28(%ebp)
	call	__Z16getGameTimeDummyv
	fstps	-32(%ebp)
	movl	$__ZTIA3_6CTest7, (%esp)
	call	__ZNKSt9type_info4nameEv
	movl	16(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	%eax, 20(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10ALLOC_INFOC1EPKcS1_S1_fS1_j
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocator12setAllocInfoEPK10ALLOC_INFO
	movl	$40, (%esp)
	call	__Znaj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1738
	movl	$3, (%ebx)
	leal	4(%ebx), %edi
	movl	$2, %esi
	movl	%edi, -60(%ebp)
	jmp	L1739
L1740:
	movl	-60(%ebp), %eax
	movl	%eax, (%esp)
LEHB335:
	call	__ZN6CTest7C1Ev
LEHE335:
	addl	$12, -60(%ebp)
	subl	$1, %esi
L1739:
	cmpl	$-1, %esi
	jne	L1740
	leal	4(%ebx), %eax
	jmp	L1747
L1738:
	movl	%ebx, %eax
	jmp	L1747
L1746:
	movl	%eax, -60(%ebp)
	testl	%edi, %edi
	je	L1744
	movl	$2, %eax
	subl	%esi, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%edi,%eax), %esi
L1745:
	cmpl	%edi, %esi
	je	L1744
	subl	$12, %esi
	movl	(%esi), %eax
	movl	(%eax), %eax
	movl	%esi, (%esp)
	call	*%eax
	jmp	L1745
L1744:
	movl	-60(%ebp), %esi
	movl	%ebx, (%esp)
	call	__ZdaPv
	movl	%esi, %eax
	movl	%eax, (%esp)
LEHB336:
	call	__Unwind_Resume
LEHE336:
L1747:
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
LFE3313:
	.section	.gcc_except_table,"w"
LLSDA3313:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3313-LLSDACSB3313
LLSDACSB3313:
	.uleb128 LEHB335-LFB3313
	.uleb128 LEHE335-LEHB335
	.uleb128 L1746-LFB3313
	.uleb128 0
	.uleb128 LEHB336-LFB3313
	.uleb128 LEHE336-LEHB336
	.uleb128 0
	.uleb128 0
LLSDACSE3313:
	.section	.text$_Z16newArrayWithInfoI6CTest7Lj3EEPT_PKcS4_j,"x"
	.linkonce discard
	.section	.text$_Z11newWithInfoI13CDerivedTest7IPKcEEPT_S2_S2_jDpT0_,"x"
	.linkonce discard
	.globl	__Z11newWithInfoI13CDerivedTest7IPKcEEPT_S2_S2_jDpT0_
	.def	__Z11newWithInfoI13CDerivedTest7IPKcEEPT_S2_S2_jDpT0_;	.scl	2;	.type	32;	.endef
__Z11newWithInfoI13CDerivedTest7IPKcEEPT_S2_S2_jDpT0_:
LFB3314:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3314
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
	call	__Z28getCurrentCallPointNameDummyv
	movl	%eax, -12(%ebp)
	call	__Z16getGameTimeDummyv
	fstps	-16(%ebp)
	movl	$__ZTI13CDerivedTest7, (%esp)
	call	__ZNKSt9type_info4nameEv
	movl	16(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	%eax, 20(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10ALLOC_INFOC1EPKcS1_S1_fS1_j
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocator12setAllocInfoEPK10ALLOC_INFO
	movl	$24, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1749
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
LEHB337:
	call	__ZN13CDerivedTest7C1EPKc
LEHE337:
	movl	%ebx, %eax
	jmp	L1754
L1749:
	movl	%ebx, %eax
	jmp	L1754
L1753:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZdlPv
	movl	%esi, %eax
	movl	%eax, (%esp)
LEHB338:
	call	__Unwind_Resume
LEHE338:
L1754:
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
LFE3314:
	.section	.gcc_except_table,"w"
LLSDA3314:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3314-LLSDACSB3314
LLSDACSB3314:
	.uleb128 LEHB337-LFB3314
	.uleb128 LEHE337-LEHB337
	.uleb128 L1753-LFB3314
	.uleb128 0
	.uleb128 LEHB338-LFB3314
	.uleb128 LEHE338-LEHB338
	.uleb128 0
	.uleb128 0
LLSDACSE3314:
	.section	.text$_Z11newWithInfoI13CDerivedTest7IPKcEEPT_S2_S2_jDpT0_,"x"
	.linkonce discard
	.weak	__Z11newWithInfoI13CDerivedTest7JPKcEEPT_S2_S2_jDpT0_
	.def	__Z11newWithInfoI13CDerivedTest7JPKcEEPT_S2_S2_jDpT0_;	.scl	2;	.type	32;	.endef
	.set	__Z11newWithInfoI13CDerivedTest7JPKcEEPT_S2_S2_jDpT0_,__Z11newWithInfoI13CDerivedTest7IPKcEEPT_S2_S2_jDpT0_
	.section	.text$_ZN25CTempPolyAllocatorWithAdpI12CStdAllocAdpEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN25CTempPolyAllocatorWithAdpI12CStdAllocAdpEC1Ev
	.def	__ZN25CTempPolyAllocatorWithAdpI12CStdAllocAdpEC1Ev;	.scl	2;	.type	32;	.endef
__ZN25CTempPolyAllocatorWithAdpI12CStdAllocAdpEC1Ev:
LFB3317:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseC2ER10IAllocator
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZN12CStdAllocAdpC1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3317:
	.section	.text$_ZN25CTempPolyAllocatorWithAdpI12CStdAllocAdpED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN25CTempPolyAllocatorWithAdpI12CStdAllocAdpED1Ev
	.def	__ZN25CTempPolyAllocatorWithAdpI12CStdAllocAdpED1Ev;	.scl	2;	.type	32;	.endef
__ZN25CTempPolyAllocatorWithAdpI12CStdAllocAdpED1Ev:
LFB3320:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZN12CStdAllocAdpD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3320:
	.section	.text$_ZN24CTempPolyAllocatorDirectI13CMonoAllocAdpEC1ERS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN24CTempPolyAllocatorDirectI13CMonoAllocAdpEC1ERS0_
	.def	__ZN24CTempPolyAllocatorDirectI13CMonoAllocAdpEC1ERS0_;	.scl	2;	.type	32;	.endef
__ZN24CTempPolyAllocatorDirectI13CMonoAllocAdpEC1ERS0_:
LFB3323:
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
	call	__ZN22CTempPolyAllocatorBaseC2ER10IAllocator
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3323:
	.section	.text$_ZN24CTempPolyAllocatorDirectI13CMonoAllocAdpED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN24CTempPolyAllocatorDirectI13CMonoAllocAdpED1Ev
	.def	__ZN24CTempPolyAllocatorDirectI13CMonoAllocAdpED1Ev;	.scl	2;	.type	32;	.endef
__ZN24CTempPolyAllocatorDirectI13CMonoAllocAdpED1Ev:
LFB3326:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3326:
	.section	.text$_ZN25CTempPolyAllocatorWithAdpI13CPoolAllocAdpEC1ER14CPoolAllocator,"x"
	.linkonce discard
	.align 2
	.globl	__ZN25CTempPolyAllocatorWithAdpI13CPoolAllocAdpEC1ER14CPoolAllocator
	.def	__ZN25CTempPolyAllocatorWithAdpI13CPoolAllocAdpEC1ER14CPoolAllocator;	.scl	2;	.type	32;	.endef
__ZN25CTempPolyAllocatorWithAdpI13CPoolAllocAdpEC1ER14CPoolAllocator:
LFB3329:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseC2ER10IAllocator
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZN13CPoolAllocAdpC1ER14CPoolAllocator
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3329:
	.section	.text$_ZN25CTempPolyAllocatorWithAdpI13CPoolAllocAdpED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN25CTempPolyAllocatorWithAdpI13CPoolAllocAdpED1Ev
	.def	__ZN25CTempPolyAllocatorWithAdpI13CPoolAllocAdpED1Ev;	.scl	2;	.type	32;	.endef
__ZN25CTempPolyAllocatorWithAdpI13CPoolAllocAdpED1Ev:
LFB3332:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZN13CPoolAllocAdpD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3332:
	.section	.text$_ZSt7forwardISt4pairIjN6CTest84DATAEEEOT_RNSt16remove_referenceIS4_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardISt4pairIjN6CTest84DATAEEEOT_RNSt16remove_referenceIS4_E4typeE
	.def	__ZSt7forwardISt4pairIjN6CTest84DATAEEEOT_RNSt16remove_referenceIS4_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardISt4pairIjN6CTest84DATAEEEOT_RNSt16remove_referenceIS4_E4typeE:
LFB3344:
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
LFE3344:
	.section	.text$_ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE6insertIS6_IjS1_EvEES6_INSt8__detail14_Node_iteratorIS8_Lb0ELb0EEEbEOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE6insertIS6_IjS1_EvEES6_INSt8__detail14_Node_iteratorIS8_Lb0ELb0EEEbEOT_
	.def	__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE6insertIS6_IjS1_EvEES6_INSt8__detail14_Node_iteratorIS8_Lb0ELb0EEEbEOT_;	.scl	2;	.type	32;	.endef
__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE6insertIS6_IjS1_EvEES6_INSt8__detail14_Node_iteratorIS8_Lb0ELb0EEEbEOT_:
LFB3343:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt4pairIjN6CTest84DATAEEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	8(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt8__detail7_InsertIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EE6insertIS1_IjS4_EvEES1_INS_14_Node_iteratorIS5_Lb0ELb0EEEbEOT_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3343:
	.section	.text$_ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE4findERS7_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE4findERS7_
	.def	__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE4findERS7_;	.scl	2;	.type	32;	.endef
__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE4findERS7_:
LFB3345:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE4findERS1_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3345:
	.section	.text$_ZNKSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE4cendEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE4cendEv
	.def	__ZNKSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE4cendEv;	.scl	2;	.type	32;	.endef
__ZNKSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE4cendEv:
LFB3346:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3346:
	.section	.text$_ZNSt8__detaileqISt4pairIKjN6CTest84DATAEELb0EEEbRKNS_19_Node_iterator_baseIT_XT0_EEESA_,"x"
	.linkonce discard
	.globl	__ZNSt8__detaileqISt4pairIKjN6CTest84DATAEELb0EEEbRKNS_19_Node_iterator_baseIT_XT0_EEESA_
	.def	__ZNSt8__detaileqISt4pairIKjN6CTest84DATAEELb0EEEbRKNS_19_Node_iterator_baseIT_XT0_EEESA_;	.scl	2;	.type	32;	.endef
__ZNSt8__detaileqISt4pairIKjN6CTest84DATAEELb0EEEbRKNS_19_Node_iterator_baseIT_XT0_EEESA_:
LFB3347:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	sete	%al
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3347:
	.section	.text$_ZNKSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEptEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEptEv
	.def	__ZNKSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEptEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEptEv:
LFB3348:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZSt11__addressofISt4pairIKjN6CTest84DATAEEEPT_RS5_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3348:
	.section	.text$_ZN23CStackAllocatorWithBuffILj1024EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj1024EEC1Ev
	.def	__ZN23CStackAllocatorWithBuffILj1024EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj1024EEC1Ev:
LFB3351:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$12, %esp
	movl	8(%ebp), %eax
	leal	16(%eax), %edx
	movl	8(%ebp), %eax
	movl	$1024, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN15CStackAllocatorC2EPvj
	movl	8(%ebp), %eax
	movl	$__ZTV23CStackAllocatorWithBuffILj1024EE+8, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3351:
	.section	.text$_ZN23CStackAllocatorWithBuffILj1024EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj1024EED1Ev
	.def	__ZN23CStackAllocatorWithBuffILj1024EED1Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj1024EED1Ev:
LFB3354:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV23CStackAllocatorWithBuffILj1024EE+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CStackAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L1777
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1777:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3354:
	.section	.text$_ZN23CStackAllocatorWithBuffILj1024EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj1024EED0Ev
	.def	__ZN23CStackAllocatorWithBuffILj1024EED0Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj1024EED0Ev:
LFB3355:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj1024EED1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3355:
	.section	.text$_ZNSaISt4pairIKjN6CTest84DATAEEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt4pairIKjN6CTest84DATAEEEC1Ev
	.def	__ZNSaISt4pairIKjN6CTest84DATAEEEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSaISt4pairIKjN6CTest84DATAEEEC1Ev:
LFB3358:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorISt4pairIKjN6CTest84DATAEEEC2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3358:
	.section	.text$_ZNSaISt4pairIKjN6CTest84DATAEEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt4pairIKjN6CTest84DATAEEED1Ev
	.def	__ZNSaISt4pairIKjN6CTest84DATAEEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSaISt4pairIKjN6CTest84DATAEEED1Ev:
LFB3361:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorISt4pairIKjN6CTest84DATAEEED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3361:
	.section	.text$_ZNSt17__allow_copy_consILb1EEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt17__allow_copy_consILb1EEC2Ev
	.def	__ZNSt17__allow_copy_consILb1EEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt17__allow_copy_consILb1EEC2Ev:
LFB3364:
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
LFE3364:
	.section	.text$_ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEEC1EjRKS3_RKS5_RKS9_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEEC1EjRKS3_RKS5_RKS9_
	.def	__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEEC1EjRKS3_RKS5_RKS9_;	.scl	2;	.type	32;	.endef
__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEEC1EjRKS3_RKS5_RKS9_:
LFB3367:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt17__allow_copy_consILb1EEC2Ev
	movl	8(%ebp), %eax
	movl	24(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	20(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKSB_RKS9_RKS5_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3367:
	.section	.text$_ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE7reserveEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE7reserveEj
	.def	__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE7reserveEj;	.scl	2;	.type	32;	.endef
__ZNSt13unordered_mapIjN6CTest84DATAESt4hashIjESt8equal_toIjESaISt4pairIKjS1_EEE7reserveEj:
LFB3368:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt8__detail12_Rehash_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE7reserveEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3368:
	.section	.text$_ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEED1Ev
	.def	__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEED1Ev:
LFB3372:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3372:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEED1Ev
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEED1Ev:
LFB3374:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3374
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEPPNS6_15_Hash_node_baseEj
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEED1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3374:
	.section	.gcc_except_table,"w"
LLSDA3374:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3374-LLSDACSB3374
LLSDACSB3374:
LLSDACSE3374:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEED1Ev,"x"
	.linkonce discard
	.section	.text$_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_,"x"
	.linkonce discard
	.globl	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_
	.def	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_;	.scl	2;	.type	32;	.endef
__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_:
LFB3393:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3393
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB339:
	call	__ZNSsC1ERKSs
LEHE339:
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB340:
	call	__ZNSs6appendERKSs
LEHE340:
	jmp	L1796
L1795:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB341:
	call	__Unwind_Resume
LEHE341:
L1796:
	movl	8(%ebp), %eax
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3393:
	.section	.gcc_except_table,"w"
LLSDA3393:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3393-LLSDACSB3393
LLSDACSB3393:
	.uleb128 LEHB339-LFB3393
	.uleb128 LEHE339-LEHB339
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB340-LFB3393
	.uleb128 LEHE340-LEHB340
	.uleb128 L1795-LFB3393
	.uleb128 0
	.uleb128 LEHB341-LFB3393
	.uleb128 LEHE341-LEHB341
	.uleb128 0
	.uleb128 0
LLSDACSE3393:
	.section	.text$_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_,"x"
	.linkonce discard
	.section	.text$_ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_
	.def	__ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_:
LFB3395:
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
LFE3395:
	.section	.text$_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_,"x"
	.linkonce discard
	.globl	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_
	.def	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_;	.scl	2;	.type	32;	.endef
__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_:
LFB3394:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSs6appendERKSs
	movl	%eax, (%esp)
	call	__ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1EOSs
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3394:
	.section	.text$_ZN23CStackAllocatorWithBuffILj8192EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj8192EEC1Ev
	.def	__ZN23CStackAllocatorWithBuffILj8192EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj8192EEC1Ev:
LFB3399:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$12, %esp
	movl	8(%ebp), %eax
	leal	16(%eax), %edx
	movl	8(%ebp), %eax
	movl	$8192, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN15CStackAllocatorC2EPvj
	movl	8(%ebp), %eax
	movl	$__ZTV23CStackAllocatorWithBuffILj8192EE+8, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3399:
	.section	.text$_ZN23CStackAllocatorWithBuffILj8192EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj8192EED1Ev
	.def	__ZN23CStackAllocatorWithBuffILj8192EED1Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj8192EED1Ev:
LFB3402:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV23CStackAllocatorWithBuffILj8192EE+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CStackAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L1802
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1802:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3402:
	.section	.text$_ZN23CStackAllocatorWithBuffILj8192EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj8192EED0Ev
	.def	__ZN23CStackAllocatorWithBuffILj8192EED0Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj8192EED0Ev:
LFB3403:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj8192EED1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3403:
	.section	.text$_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EED1Ev
	.def	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EED1Ev:
LFB3408:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L1807
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv
L1807:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3408:
	.section	.text$_ZNSt10_Hash_impl4hashIP11__pthread_tEEjRKT_,"x"
	.linkonce discard
	.globl	__ZNSt10_Hash_impl4hashIP11__pthread_tEEjRKT_
	.def	__ZNSt10_Hash_impl4hashIP11__pthread_tEEjRKT_;	.scl	2;	.type	32;	.endef
__ZNSt10_Hash_impl4hashIP11__pthread_tEEjRKT_:
LFB3409:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$-955291385, 8(%esp)
	movl	$4, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Hash_impl4hashEPKvjj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3409:
	.section	.text$_ZNKSt6chrono8durationIxSt5ratioILx1ELx1000EEE5countEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000EEE5countEv
	.def	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000EEE5countEv;	.scl	2;	.type	32;	.endef
__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000EEE5countEv:
LFB3413:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3413:
	.def	___divdi3;	.scl	2;	.type	32;	.endef
	.section	.text$_ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1EEEES2_ILx1ELx1000EExLb1ELb0EE6__castIxS5_EES4_RKNS1_IT_T0_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1EEEES2_ILx1ELx1000EExLb1ELb0EE6__castIxS5_EES4_RKNS1_IT_T0_EE
	.def	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1EEEES2_ILx1ELx1000EExLb1ELb0EE6__castIxS5_EES4_RKNS1_IT_T0_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1EEEES2_ILx1ELx1000EExLb1ELb0EE6__castIxS5_EES4_RKNS1_IT_T0_EE:
LFB3412:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000EEE5countEv
	movl	$1000, 8(%esp)
	movl	$0, 12(%esp)
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	___divdi3
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1EEEC1IxvEERKT_
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3412:
	.section	.text$_ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1EEEExS2_ILx1ELx1000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1EEEExS2_ILx1ELx1000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE
	.def	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1EEEExS2_ILx1ELx1000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1EEEExS2_ILx1ELx1000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE:
LFB3411:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1EEEES2_ILx1ELx1000EExLb1ELb0EE6__castIxS5_EES4_RKNS1_IT_T0_EE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3411:
	.section	.text$_ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IxvEERKT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IxvEERKT_
	.def	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IxvEERKT_;	.scl	2;	.type	32;	.endef
__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IxvEERKT_:
LFB3420:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	8(%ebp), %ecx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3420:
	.section	.text$_ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000EEEES2_ILx1000ELx1EExLb0ELb1EE6__castIxS2_ILx1ELx1EEEES4_RKNS1_IT_T0_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000EEEES2_ILx1000ELx1EExLb0ELb1EE6__castIxS2_ILx1ELx1EEEES4_RKNS1_IT_T0_EE
	.def	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000EEEES2_ILx1000ELx1EExLb0ELb1EE6__castIxS2_ILx1ELx1EEEES4_RKNS1_IT_T0_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000EEEES2_ILx1000ELx1EExLb0ELb1EE6__castIxS2_ILx1ELx1EEEES4_RKNS1_IT_T0_EE:
LFB3417:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$28, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1EEE5countEv
	imull	$1000, %edx, %ebx
	imull	$0, %eax, %ecx
	addl	%ecx, %ebx
	movl	$1000, %ecx
	mull	%ecx
	leal	(%ebx,%edx), %ecx
	movl	%ecx, %edx
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IxvEERKT_
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	addl	$28, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3417:
	.section	.text$_ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000EEEExS2_ILx1ELx1EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000EEEExS2_ILx1ELx1EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE
	.def	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000EEEExS2_ILx1ELx1EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000EEEExS2_ILx1ELx1EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE:
LFB3416:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000EEEES2_ILx1000ELx1EExLb0ELb1EE6__castIxS2_ILx1ELx1EEEES4_RKNS1_IT_T0_EE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3416:
	.section	.text$_ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IxS1_ILx1ELx1EEvEERKNS0_IT_T0_EE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IxS1_ILx1ELx1EEvEERKNS0_IT_T0_EE
	.def	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IxS1_ILx1ELx1EEvEERKNS0_IT_T0_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IxS1_ILx1ELx1EEvEERKNS0_IT_T0_EE:
LFB3422:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000EEEExS2_ILx1ELx1EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE
	movl	%eax, -8(%ebp)
	movl	%edx, -4(%ebp)
	leal	-8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000EEE5countEv
	movl	8(%ebp), %ecx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3422:
	.section	.text$_ZNSt6chronomiIxSt5ratioILx1ELx1000EExS1_ILx1ELx1EEEENSt11common_typeIINS_8durationIT_T0_EENS5_IT1_T2_EEEE4typeERKS8_RKSB_,"x"
	.linkonce discard
	.globl	__ZNSt6chronomiIxSt5ratioILx1ELx1000EExS1_ILx1ELx1EEEENSt11common_typeIINS_8durationIT_T0_EENS5_IT1_T2_EEEE4typeERKS8_RKSB_
	.def	__ZNSt6chronomiIxSt5ratioILx1ELx1000EExS1_ILx1ELx1EEEENSt11common_typeIINS_8durationIT_T0_EENS5_IT1_T2_EEEE4typeERKS8_RKSB_;	.scl	2;	.type	32;	.endef
__ZNSt6chronomiIxSt5ratioILx1ELx1000EExS1_ILx1ELx1EEEENSt11common_typeIINS_8durationIT_T0_EENS5_IT1_T2_EEEE4typeERKS8_RKSB_:
LFB3414:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$40, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000EEE5countEv
	movl	%eax, %ebx
	movl	%edx, %esi
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IxS1_ILx1ELx1EEvEERKNS0_IT_T0_EE
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000EEE5countEv
	subl	%eax, %ebx
	sbbl	%edx, %esi
	movl	%ebx, %eax
	movl	%esi, %edx
	movl	%eax, -32(%ebp)
	movl	%edx, -28(%ebp)
	leal	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000EEEC1IxvEERKT_
	movl	-40(%ebp), %eax
	movl	-36(%ebp), %edx
	addl	$40, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3414:
	.weak	__ZNSt6chronomiIxSt5ratioILx1ELx1000EExS1_ILx1ELx1EEEENSt11common_typeIJNS_8durationIT_T0_EENS5_IT1_T2_EEEE4typeERKS8_RKSB_
	.def	__ZNSt6chronomiIxSt5ratioILx1ELx1000EExS1_ILx1ELx1EEEENSt11common_typeIJNS_8durationIT_T0_EENS5_IT1_T2_EEEE4typeERKS8_RKSB_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt6chronomiIxSt5ratioILx1ELx1000EExS1_ILx1ELx1EEEENSt11common_typeIJNS_8durationIT_T0_EENS5_IT1_T2_EEEE4typeERKS8_RKSB_,__ZNSt6chronomiIxSt5ratioILx1ELx1000EExS1_ILx1ELx1EEEENSt11common_typeIINS_8durationIT_T0_EENS5_IT1_T2_EEEE4typeERKS8_RKSB_
	.section	.text$_ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000000000EEEES2_ILx1000000ELx1EExLb0ELb1EE6__castIxS2_ILx1ELx1000EEEES4_RKNS1_IT_T0_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000000000EEEES2_ILx1000000ELx1EExLb0ELb1EE6__castIxS2_ILx1ELx1000EEEES4_RKNS1_IT_T0_EE
	.def	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000000000EEEES2_ILx1000000ELx1EExLb0ELb1EE6__castIxS2_ILx1ELx1000EEEES4_RKNS1_IT_T0_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000000000EEEES2_ILx1000000ELx1EExLb0ELb1EE6__castIxS2_ILx1ELx1000EEEES4_RKNS1_IT_T0_EE:
LFB3424:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$28, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000EEE5countEv
	imull	$1000000, %edx, %ebx
	imull	$0, %eax, %ecx
	addl	%ecx, %ebx
	movl	$1000000, %ecx
	mull	%ecx
	leal	(%ebx,%edx), %ecx
	movl	%ecx, %edx
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	addl	$28, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3424:
	.section	.text$_ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000000000EEEExS2_ILx1ELx1000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000000000EEEExS2_ILx1ELx1000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE
	.def	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000000000EEEExS2_ILx1ELx1000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000000000EEEExS2_ILx1ELx1000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE:
LFB3423:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000000000EEEES2_ILx1000000ELx1EExLb0ELb1EE6__castIxS2_ILx1ELx1000EEEES4_RKNS1_IT_T0_EE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3423:
	.section	.text$_ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1000EEEEvRKNSt6chrono8durationIT_T0_EE,"x"
	.linkonce discard
	.globl	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1000EEEEvRKNSt6chrono8durationIT_T0_EE
	.def	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1000EEEEvRKNSt6chrono8durationIT_T0_EE;	.scl	2;	.type	32;	.endef
__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1000EEEEvRKNSt6chrono8durationIT_T0_EE:
LFB3410:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3410
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1EEEExS2_ILx1ELx1000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chronomiIxSt5ratioILx1ELx1000EExS1_ILx1ELx1EEEENSt11common_typeIINS_8durationIT_T0_EENS5_IT1_T2_EEEE4typeERKS8_RKSB_
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000000000EEEExS2_ILx1ELx1000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE
	movl	%eax, -32(%ebp)
	movl	%edx, -28(%ebp)
	movl	-32(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%eax, 8(%esp)
	movl	%edx, 12(%esp)
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
LEHB342:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
LEHE342:
	jmp	L1832
L1831:
	movl	%eax, (%esp)
LEHB343:
	call	__Unwind_Resume
LEHE343:
L1832:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3410:
	.section	.gcc_except_table,"w"
LLSDA3410:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3410-LLSDACSB3410
LLSDACSB3410:
	.uleb128 LEHB342-LFB3410
	.uleb128 LEHE342-LEHB342
	.uleb128 L1831-LFB3410
	.uleb128 0
	.uleb128 LEHB343-LFB3410
	.uleb128 LEHE343-LEHB343
	.uleb128 0
	.uleb128 0
LLSDACSE3410:
	.section	.text$_ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1000EEEEvRKNSt6chrono8durationIT_T0_EE,"x"
	.linkonce discard
	.section	.text$_ZNKSt13__atomic_baseIjE4loadESt12memory_order,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13__atomic_baseIjE4loadESt12memory_order
	.def	__ZNKSt13__atomic_baseIjE4loadESt12memory_order;	.scl	2;	.type	32;	.endef
__ZNKSt13__atomic_baseIjE4loadESt12memory_order:
LFB3425:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZStanSt12memory_orderSt23__memory_order_modifier
	movl	%eax, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3425:
	.section	.text$_ZNKSt6atomicIN15IStackAllocator9E_ORDEREDEE4loadESt12memory_order,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6atomicIN15IStackAllocator9E_ORDEREDEE4loadESt12memory_order
	.def	__ZNKSt6atomicIN15IStackAllocator9E_ORDEREDEE4loadESt12memory_order;	.scl	2;	.type	32;	.endef
__ZNKSt6atomicIN15IStackAllocator9E_ORDEREDEE4loadESt12memory_order:
LFB3426:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3426:
	.section	.text$_ZNSt6atomicIN15IStackAllocator9E_ORDEREDEE5storeES1_St12memory_order,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6atomicIN15IStackAllocator9E_ORDEREDEE5storeES1_St12memory_order
	.def	__ZNSt6atomicIN15IStackAllocator9E_ORDEREDEE5storeES1_St12memory_order;	.scl	2;	.type	32;	.endef
__ZNSt6atomicIN15IStackAllocator9E_ORDEREDEE5storeES1_St12memory_order:
LFB3427:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	xchgl	(%eax), %edx
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3427:
	.section	.text$_ZNSt13__atomic_baseIjE5storeEjSt12memory_order,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order
	.def	__ZNSt13__atomic_baseIjE5storeEjSt12memory_order;	.scl	2;	.type	32;	.endef
__ZNSt13__atomic_baseIjE5storeEjSt12memory_order:
LFB3428:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZStanSt12memory_orderSt23__memory_order_modifier
	movl	%eax, -4(%ebp)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	xchgl	(%eax), %edx
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3428:
	.section	.text$_ZN30CTempPolyAllocatorWithStackAdpI19CSmartStackAllocAdpEC2ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN30CTempPolyAllocatorWithStackAdpI19CSmartStackAllocAdpEC2ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE
	.def	__ZN30CTempPolyAllocatorWithStackAdpI19CSmartStackAllocAdpEC2ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN30CTempPolyAllocatorWithStackAdpI19CSmartStackAllocAdpEC2ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE:
LFB3430:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3430
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseC2ER10IAllocator
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
LEHB344:
	call	__ZN19CSmartStackAllocAdpC1ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE
LEHE344:
	jmp	L1842
L1841:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseD2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB345:
	call	__Unwind_Resume
LEHE345:
L1842:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3430:
	.section	.gcc_except_table,"w"
LLSDA3430:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3430-LLSDACSB3430
LLSDACSB3430:
	.uleb128 LEHB344-LFB3430
	.uleb128 LEHE344-LEHB344
	.uleb128 L1841-LFB3430
	.uleb128 0
	.uleb128 LEHB345-LFB3430
	.uleb128 LEHE345-LEHB345
	.uleb128 0
	.uleb128 0
LLSDACSE3430:
	.section	.text$_ZN30CTempPolyAllocatorWithStackAdpI19CSmartStackAllocAdpEC2ER20CSmartStackAllocatorN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.section	.text$_ZN30CTempPolyAllocatorWithStackAdpI19CSmartStackAllocAdpED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN30CTempPolyAllocatorWithStackAdpI19CSmartStackAllocAdpED2Ev
	.def	__ZN30CTempPolyAllocatorWithStackAdpI19CSmartStackAllocAdpED2Ev;	.scl	2;	.type	32;	.endef
__ZN30CTempPolyAllocatorWithStackAdpI19CSmartStackAllocAdpED2Ev:
LFB3433:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZN19CSmartStackAllocAdpD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CTempPolyAllocatorBaseD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3433:
	.section	.text$_ZN28CSmartStackAllocatorWithBuffILj1024EEC1EN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN28CSmartStackAllocatorWithBuffILj1024EEC1EN15IStackAllocator9E_ORDEREDE
	.def	__ZN28CSmartStackAllocatorWithBuffILj1024EEC1EN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN28CSmartStackAllocatorWithBuffILj1024EEC1EN15IStackAllocator9E_ORDEREDE:
LFB3437:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	leal	41(%eax), %ecx
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	$1024, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocatorC2EPvjN15IStackAllocator9E_ORDEREDE
	movl	8(%ebp), %eax
	movl	$__ZTV28CSmartStackAllocatorWithBuffILj1024EE+8, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3437:
	.section	.text$_ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1EEEES3_xLb1ELb1EE6__castIxS3_EES4_RKNS1_IT_T0_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1EEEES3_xLb1ELb1EE6__castIxS3_EES4_RKNS1_IT_T0_EE
	.def	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1EEEES3_xLb1ELb1EE6__castIxS3_EES4_RKNS1_IT_T0_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1EEEES3_xLb1ELb1EE6__castIxS3_EES4_RKNS1_IT_T0_EE:
LFB3440:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1EEE5countEv
	movl	%eax, -8(%ebp)
	movl	%edx, -4(%ebp)
	leal	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1EEEC1IxvEERKT_
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3440:
	.section	.text$_ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1EEEExS3_EENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES7_E4typeERKNS1_IT0_T1_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1EEEExS3_EENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES7_E4typeERKNS1_IT0_T1_EE
	.def	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1EEEExS3_EENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES7_E4typeERKNS1_IT0_T1_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1EEEExS3_EENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES7_E4typeERKNS1_IT0_T1_EE:
LFB3439:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1EEEES3_xLb1ELb1EE6__castIxS3_EES4_RKNS1_IT_T0_EE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3439:
	.section	.text$_ZNSt6chronomiIxSt5ratioILx1ELx1EExS2_EENSt11common_typeIINS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_,"x"
	.linkonce discard
	.globl	__ZNSt6chronomiIxSt5ratioILx1ELx1EExS2_EENSt11common_typeIINS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_
	.def	__ZNSt6chronomiIxSt5ratioILx1ELx1EExS2_EENSt11common_typeIINS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_;	.scl	2;	.type	32;	.endef
__ZNSt6chronomiIxSt5ratioILx1ELx1EExS2_EENSt11common_typeIINS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_:
LFB3441:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$40, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1EEE5countEv
	movl	%eax, %ebx
	movl	%edx, %esi
	movl	12(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1EEE5countEv
	subl	%eax, %ebx
	sbbl	%edx, %esi
	movl	%ebx, %eax
	movl	%esi, %edx
	movl	%eax, -32(%ebp)
	movl	%edx, -28(%ebp)
	leal	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1EEEC1IxvEERKT_
	movl	-40(%ebp), %eax
	movl	-36(%ebp), %edx
	addl	$40, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3441:
	.weak	__ZNSt6chronomiIxSt5ratioILx1ELx1EExS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_
	.def	__ZNSt6chronomiIxSt5ratioILx1ELx1EExS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt6chronomiIxSt5ratioILx1ELx1EExS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_,__ZNSt6chronomiIxSt5ratioILx1ELx1EExS2_EENSt11common_typeIINS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_
	.section	.text$_ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1EEEEvRKNSt6chrono8durationIT_T0_EE,"x"
	.linkonce discard
	.globl	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1EEEEvRKNSt6chrono8durationIT_T0_EE
	.def	__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1EEEEvRKNSt6chrono8durationIT_T0_EE;	.scl	2;	.type	32;	.endef
__ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1EEEEvRKNSt6chrono8durationIT_T0_EE:
LFB3438:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3438
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1EEEExS3_EENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES7_E4typeERKNS1_IT0_T1_EE
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chronomiIxSt5ratioILx1ELx1EExS2_EENSt11common_typeIINS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000000000EEEExS2_ILx1ELx1EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE
	movl	%eax, -32(%ebp)
	movl	%edx, -28(%ebp)
	movl	-32(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%eax, 8(%esp)
	movl	%edx, 12(%esp)
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
LEHB346:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
LEHE346:
	jmp	L1855
L1854:
	movl	%eax, (%esp)
LEHB347:
	call	__Unwind_Resume
LEHE347:
L1855:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3438:
	.section	.gcc_except_table,"w"
LLSDA3438:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3438-LLSDACSB3438
LLSDACSB3438:
	.uleb128 LEHB346-LFB3438
	.uleb128 LEHE346-LEHB346
	.uleb128 L1854-LFB3438
	.uleb128 0
	.uleb128 LEHB347-LFB3438
	.uleb128 LEHE347-LEHB347
	.uleb128 0
	.uleb128 0
LLSDACSE3438:
	.section	.text$_ZNSt11this_thread9sleep_forIxSt5ratioILx1ELx1EEEEvRKNSt6chrono8durationIT_T0_EE,"x"
	.linkonce discard
	.section	.text$_ZN28CSmartStackAllocatorWithBuffILj128EEC1EN15IStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN28CSmartStackAllocatorWithBuffILj128EEC1EN15IStackAllocator9E_ORDEREDE
	.def	__ZN28CSmartStackAllocatorWithBuffILj128EEC1EN15IStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN28CSmartStackAllocatorWithBuffILj128EEC1EN15IStackAllocator9E_ORDEREDE:
LFB3444:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	leal	41(%eax), %ecx
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	$128, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocatorC2EPvjN15IStackAllocator9E_ORDEREDE
	movl	8(%ebp), %eax
	movl	$__ZTV28CSmartStackAllocatorWithBuffILj128EE+8, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3444:
	.section	.text$_ZN28CSmartStackAllocatorWithBuffILj128EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN28CSmartStackAllocatorWithBuffILj128EED1Ev
	.def	__ZN28CSmartStackAllocatorWithBuffILj128EED1Ev;	.scl	2;	.type	32;	.endef
__ZN28CSmartStackAllocatorWithBuffILj128EED1Ev:
LFB3447:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV28CSmartStackAllocatorWithBuffILj128EE+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L1857
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1857:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3447:
	.section	.text$_ZN28CSmartStackAllocatorWithBuffILj128EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN28CSmartStackAllocatorWithBuffILj128EED0Ev
	.def	__ZN28CSmartStackAllocatorWithBuffILj128EED0Ev;	.scl	2;	.type	32;	.endef
__ZN28CSmartStackAllocatorWithBuffILj128EED0Ev:
LFB3448:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CSmartStackAllocatorWithBuffILj128EED1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3448:
	.section	.text$_ZSt7forwardIRFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE
	.def	__ZSt7forwardIRFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE:
LFB3450:
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
LFE3450:
	.section	.text$_ZSt7forwardIRA28_KcEOT_RNSt16remove_referenceIS3_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRA28_KcEOT_RNSt16remove_referenceIS3_E4typeE
	.def	__ZSt7forwardIRA28_KcEOT_RNSt16remove_referenceIS3_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRA28_KcEOT_RNSt16remove_referenceIS3_E4typeE:
LFB3451:
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
LFE3451:
	.section	.text$_ZNSt12__shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEELN9__gnu_cxx12_Lock_policyE2EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12__shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEELN9__gnu_cxx12_Lock_policyE2EED2Ev
	.def	__ZNSt12__shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEELN9__gnu_cxx12_Lock_policyE2EED2Ev;	.scl	2;	.type	32;	.endef
__ZNSt12__shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEELN9__gnu_cxx12_Lock_policyE2EED2Ev:
LFB3454:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EED1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3454:
	.section	.text$_ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEED1Ev
	.def	__ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEED1Ev:
LFB3457:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12__shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEELN9__gnu_cxx12_Lock_policyE2EED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3457:
	.section	.text$_ZNSt6threadC1IRFvPKcEIRA28_S1_EEEOT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6threadC1IRFvPKcEIRA28_S1_EEEOT_DpOT0_
	.def	__ZNSt6threadC1IRFvPKcEIRA28_S1_EEEOT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZNSt6threadC1IRFvPKcEIRA28_S1_EEEOT_DpOT0_:
LFB3459:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3459
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread2idC1Ev
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRA28_KcEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE
	leal	-16(%ebp), %edx
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
LEHB348:
	call	__ZSt13__bind_simpleIRFvPKcEIRA28_S0_EENSt19_Bind_simple_helperIT_IDpT0_EE6__typeEOS7_DpOS8_
LEHE348:
	subl	$4, %esp
	leal	-24(%ebp), %eax
	leal	-16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB349:
	call	__ZNSt6thread15_M_make_routineISt12_Bind_simpleIFPFvPKcES3_EEEESt10shared_ptrINS_5_ImplIT_EEEOSA_
LEHE349:
	subl	$4, %esp
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10shared_ptrINSt6thread10_Impl_baseEEC1INS0_5_ImplISt12_Bind_simpleIFPFvPKcES7_EEEEvEEOS_IT_E
	leal	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB350:
	call	__ZNSt6thread15_M_start_threadESt10shared_ptrINS_10_Impl_baseEE
LEHE350:
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10shared_ptrINSt6thread10_Impl_baseEED1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEED1Ev
	jmp	L1875
L1874:
	movl	%eax, %ebx
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10shared_ptrINSt6thread10_Impl_baseEED1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEED1Ev
	movl	%ebx, %eax
	jmp	L1872
L1873:
L1872:
	movl	%eax, (%esp)
LEHB351:
	call	__Unwind_Resume
LEHE351:
L1875:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3459:
	.section	.gcc_except_table,"w"
LLSDA3459:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3459-LLSDACSB3459
LLSDACSB3459:
	.uleb128 LEHB348-LFB3459
	.uleb128 LEHE348-LEHB348
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB349-LFB3459
	.uleb128 LEHE349-LEHB349
	.uleb128 L1873-LFB3459
	.uleb128 0
	.uleb128 LEHB350-LFB3459
	.uleb128 LEHE350-LEHB350
	.uleb128 L1874-LFB3459
	.uleb128 0
	.uleb128 LEHB351-LFB3459
	.uleb128 LEHE351-LEHB351
	.uleb128 0
	.uleb128 0
LLSDACSE3459:
	.section	.text$_ZNSt6threadC1IRFvPKcEIRA28_S1_EEEOT_DpOT0_,"x"
	.linkonce discard
	.weak	__ZNSt6threadC1IRFvPKcEJRA28_S1_EEEOT_DpOT0_
	.def	__ZNSt6threadC1IRFvPKcEJRA28_S1_EEEOT_DpOT0_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt6threadC1IRFvPKcEJRA28_S1_EEEOT_DpOT0_,__ZNSt6threadC1IRFvPKcEIRA28_S1_EEEOT_DpOT0_
	.section	.text$_ZSt7forwardIRA29_KcEOT_RNSt16remove_referenceIS3_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRA29_KcEOT_RNSt16remove_referenceIS3_E4typeE
	.def	__ZSt7forwardIRA29_KcEOT_RNSt16remove_referenceIS3_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRA29_KcEOT_RNSt16remove_referenceIS3_E4typeE:
LFB3461:
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
LFE3461:
	.section	.text$_ZNSt6threadC1IRFvPKcEIRA29_S1_EEEOT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6threadC1IRFvPKcEIRA29_S1_EEEOT_DpOT0_
	.def	__ZNSt6threadC1IRFvPKcEIRA29_S1_EEEOT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZNSt6threadC1IRFvPKcEIRA29_S1_EEEOT_DpOT0_:
LFB3463:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3463
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread2idC1Ev
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRA29_KcEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE
	leal	-16(%ebp), %edx
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
LEHB352:
	call	__ZSt13__bind_simpleIRFvPKcEIRA29_S0_EENSt19_Bind_simple_helperIT_IDpT0_EE6__typeEOS7_DpOS8_
LEHE352:
	subl	$4, %esp
	leal	-24(%ebp), %eax
	leal	-16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB353:
	call	__ZNSt6thread15_M_make_routineISt12_Bind_simpleIFPFvPKcES3_EEEESt10shared_ptrINS_5_ImplIT_EEEOSA_
LEHE353:
	subl	$4, %esp
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10shared_ptrINSt6thread10_Impl_baseEEC1INS0_5_ImplISt12_Bind_simpleIFPFvPKcES7_EEEEvEEOS_IT_E
	leal	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB354:
	call	__ZNSt6thread15_M_start_threadESt10shared_ptrINS_10_Impl_baseEE
LEHE354:
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10shared_ptrINSt6thread10_Impl_baseEED1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEED1Ev
	jmp	L1883
L1882:
	movl	%eax, %ebx
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10shared_ptrINSt6thread10_Impl_baseEED1Ev
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEED1Ev
	movl	%ebx, %eax
	jmp	L1880
L1881:
L1880:
	movl	%eax, (%esp)
LEHB355:
	call	__Unwind_Resume
LEHE355:
L1883:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3463:
	.section	.gcc_except_table,"w"
LLSDA3463:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3463-LLSDACSB3463
LLSDACSB3463:
	.uleb128 LEHB352-LFB3463
	.uleb128 LEHE352-LEHB352
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB353-LFB3463
	.uleb128 LEHE353-LEHB353
	.uleb128 L1881-LFB3463
	.uleb128 0
	.uleb128 LEHB354-LFB3463
	.uleb128 LEHE354-LEHB354
	.uleb128 L1882-LFB3463
	.uleb128 0
	.uleb128 LEHB355-LFB3463
	.uleb128 LEHE355-LEHB355
	.uleb128 0
	.uleb128 0
LLSDACSE3463:
	.section	.text$_ZNSt6threadC1IRFvPKcEIRA29_S1_EEEOT_DpOT0_,"x"
	.linkonce discard
	.weak	__ZNSt6threadC1IRFvPKcEJRA29_S1_EEEOT_DpOT0_
	.def	__ZNSt6threadC1IRFvPKcEJRA29_S1_EEEOT_DpOT0_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt6threadC1IRFvPKcEJRA29_S1_EEEOT_DpOT0_,__ZNSt6threadC1IRFvPKcEIRA29_S1_EEEOT_DpOT0_
	.section	.text$_ZnwI6CTest3EPvjR10CSingletonIT_E,"x"
	.linkonce discard
	.globl	__ZnwI6CTest3EPvjR10CSingletonIT_E
	.def	__ZnwI6CTest3EPvjR10CSingletonIT_E;	.scl	2;	.type	32;	.endef
__ZnwI6CTest3EPvjR10CSingletonIT_E:
LFB3464:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$__ZN10CSingletonI6CTest3E15m_singletonBuffE, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3464:
	.section	.text$_ZdlI6CTest3EvPvR10CSingletonIT_E,"x"
	.linkonce discard
	.globl	__ZdlI6CTest3EvPvR10CSingletonIT_E
	.def	__ZdlI6CTest3EvPvR10CSingletonIT_E;	.scl	2;	.type	32;	.endef
__ZdlI6CTest3EvPvR10CSingletonIT_E:
LFB3465:
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
LFE3465:
	.section	.text$_ZN22CPoolAllocatorWithBuffILj8ELi5EEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithBuffILj8ELi5EEC2Ev
	.def	__ZN22CPoolAllocatorWithBuffILj8ELi5EEC2Ev;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithBuffILj8ELi5EEC2Ev:
LFB3467:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	leal	24(%eax), %edx
	movl	8(%ebp), %eax
	movl	$5, 12(%esp)
	movl	$8, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocatorC2EPvji
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3467:
	.section	.text$_ZN22CPoolAllocatorWithBuffILj8ELi5EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithBuffILj8ELi5EED2Ev
	.def	__ZN22CPoolAllocatorWithBuffILj8ELi5EED2Ev;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithBuffILj8ELi5EED2Ev:
LFB3470:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocatorD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3470:
	.section	.text$_ZN14CPoolAllocator6createI6CTest5IPKcEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createI6CTest5IPKcEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createI6CTest5IPKcEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createI6CTest5IPKcEEEPT_DpT0_:
LFB3472:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3472
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
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZnwjR14CPoolAllocator
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1891
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
LEHB356:
	call	__ZN6CTest5C1EPKc
LEHE356:
	movl	%ebx, %eax
	jmp	L1896
L1891:
	movl	%ebx, %eax
	jmp	L1896
L1895:
	movl	%eax, %esi
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	%esi, %eax
	movl	%eax, (%esp)
LEHB357:
	call	__Unwind_Resume
LEHE357:
L1896:
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
LFE3472:
	.section	.gcc_except_table,"w"
LLSDA3472:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3472-LLSDACSB3472
LLSDACSB3472:
	.uleb128 LEHB356-LFB3472
	.uleb128 LEHE356-LEHB356
	.uleb128 L1895-LFB3472
	.uleb128 0
	.uleb128 LEHB357-LFB3472
	.uleb128 LEHE357-LEHB357
	.uleb128 0
	.uleb128 0
LLSDACSE3472:
	.section	.text$_ZN14CPoolAllocator6createI6CTest5IPKcEEEPT_DpT0_,"x"
	.linkonce discard
	.weak	__ZN14CPoolAllocator6createI6CTest5JPKcEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createI6CTest5JPKcEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN14CPoolAllocator6createI6CTest5JPKcEEEPT_DpT0_,__ZN14CPoolAllocator6createI6CTest5IPKcEEEPT_DpT0_
	.section	.text$_ZN14CPoolAllocator7destroyI6CTest5EEvRPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7destroyI6CTest5EEvRPT_
	.def	__ZN14CPoolAllocator7destroyI6CTest5EEvRPT_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7destroyI6CTest5EEvRPT_:
LFB3473:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1898
	jmp	L1897
L1898:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest5D1Ev
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	12(%ebp), %eax
	movl	$0, (%eax)
L1897:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3473:
	.section	.text$_ZNSt8__detail7_InsertIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EE6insertIS1_IjS4_EvEES1_INS_14_Node_iteratorIS5_Lb0ELb0EEEbEOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail7_InsertIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EE6insertIS1_IjS4_EvEES1_INS_14_Node_iteratorIS5_Lb0ELb0EEEbEOT_
	.def	__ZNSt8__detail7_InsertIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EE6insertIS1_IjS4_EvEES1_INS_14_Node_iteratorIS5_Lb0ELb0EEEbEOT_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail7_InsertIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EE6insertIS1_IjS4_EvEES1_INS_14_Node_iteratorIS5_Lb0ELb0EEEbEOT_:
LFB3482:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3482
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail12_Insert_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE20_M_conjure_hashtableEv
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt4pairIjN6CTest84DATAEEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	%eax, 8(%esp)
	movb	%bl, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
LEHB358:
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIIS0_IjS3_EEEES0_INS6_14_Node_iteratorIS4_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_
LEHE358:
	jmp	L1904
L1903:
	movl	%eax, (%esp)
LEHB359:
	call	__Unwind_Resume
LEHE359:
L1904:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3482:
	.section	.gcc_except_table,"w"
LLSDA3482:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3482-LLSDACSB3482
LLSDACSB3482:
	.uleb128 LEHB358-LFB3482
	.uleb128 LEHE358-LEHB358
	.uleb128 L1903-LFB3482
	.uleb128 0
	.uleb128 LEHB359-LFB3482
	.uleb128 LEHE359-LEHB359
	.uleb128 0
	.uleb128 0
LLSDACSE3482:
	.section	.text$_ZNSt8__detail7_InsertIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EE6insertIS1_IjS4_EvEES1_INS_14_Node_iteratorIS5_Lb0ELb0EEEbEOT_,"x"
	.linkonce discard
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE4findERS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE4findERS1_
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE4findERS1_;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE4findERS1_:
LFB3483:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE12_M_hash_codeERS2_
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexERS1_j
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE12_M_find_nodeEjRS1_j
	movl	%eax, -20(%ebp)
	cmpl	$0, -20(%ebp)
	je	L1906
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEC1EPNS_10_Hash_nodeIS5_Lb0EEE
	jmp	L1907
L1906:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv
	movl	%eax, -24(%ebp)
L1907:
	movl	-24(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3483:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv
	.def	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv:
LFB3484:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3484
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail20_Node_const_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEC1EPNS_10_Hash_nodeIS5_Lb0EEE
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3484:
	.section	.gcc_except_table,"w"
LLSDA3484:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3484-LLSDACSB3484
LLSDACSB3484:
LLSDACSE3484:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv,"x"
	.linkonce discard
	.section	.text$_ZSt11__addressofISt4pairIKjN6CTest84DATAEEEPT_RS5_,"x"
	.linkonce discard
	.globl	__ZSt11__addressofISt4pairIKjN6CTest84DATAEEEPT_RS5_
	.def	__ZSt11__addressofISt4pairIKjN6CTest84DATAEEEPT_RS5_;	.scl	2;	.type	32;	.endef
__ZSt11__addressofISt4pairIKjN6CTest84DATAEEEPT_RS5_:
LFB3485:
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
LFE3485:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt4pairIKjN6CTest84DATAEEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt4pairIKjN6CTest84DATAEEEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISt4pairIKjN6CTest84DATAEEEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt4pairIKjN6CTest84DATAEEEC2Ev:
LFB3487:
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
LFE3487:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt4pairIKjN6CTest84DATAEEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt4pairIKjN6CTest84DATAEEED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISt4pairIKjN6CTest84DATAEEED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt4pairIKjN6CTest84DATAEEED2Ev:
LFB3490:
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
LFE3490:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKSB_RKS9_RKS5_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKSB_RKS9_RKS5_
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKSB_RKS9_RKS5_;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKSB_RKS9_RKS5_:
LFB3494:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3494
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	24(%ebp), %eax
	movl	%eax, 28(%esp)
	leal	-11(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	20(%ebp), %eax
	movl	%eax, 20(%esp)
	leal	-10(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-9(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB360:
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKSB_RKSC_RKSD_RKS9_RKS7_RKS5_
LEHE360:
	jmp	L1919
L1918:
	movl	%eax, (%esp)
LEHB361:
	call	__Unwind_Resume
LEHE361:
L1919:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3494:
	.section	.gcc_except_table,"w"
LLSDA3494:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3494-LLSDACSB3494
LLSDACSB3494:
	.uleb128 LEHB360-LFB3494
	.uleb128 LEHE360-LEHB360
	.uleb128 L1918-LFB3494
	.uleb128 0
	.uleb128 LEHB361-LFB3494
	.uleb128 LEHE361-LEHB361
	.uleb128 0
	.uleb128 0
LLSDACSE3494:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKSB_RKS9_RKS5_,"x"
	.linkonce discard
	.section	.text$_ZNSt8__detail12_Rehash_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE7reserveEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail12_Rehash_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE7reserveEj
	.def	__ZNSt8__detail12_Rehash_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE7reserveEj;	.scl	2;	.type	32;	.endef
__ZNSt8__detail12_Rehash_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE7reserveEj:
LFB3495:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	$0, %edx
	movl	%eax, -32(%ebp)
	movl	%edx, -28(%ebp)
	fildq	-32(%ebp)
	fstps	-40(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail12_Rehash_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE15max_load_factorEv
	fdivrs	-40(%ebp)
	fstpl	(%esp)
	call	_ceil
	fnstcw	-34(%ebp)
	movzwl	-34(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -36(%ebp)
	fldcw	-36(%ebp)
	fistpq	-32(%ebp)
	fldcw	-34(%ebp)
	movl	-32(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE6rehashEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3495:
	.section	.text$_ZNSaINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEED2Ev
	.def	__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEED2Ev;	.scl	2;	.type	32;	.endef
__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEED2Ev:
LFB3497:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3497:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv:
LFB3499:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3499
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE8_M_beginEv
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_deallocate_nodesEPNS6_10_Hash_nodeIS4_Lb0EEE
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	_memset
	movl	8(%ebp), %eax
	movl	$0, 12(%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	$0, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3499:
	.section	.gcc_except_table,"w"
LLSDA3499:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3499-LLSDACSB3499
LLSDACSB3499:
LLSDACSE3499:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv,"x"
	.linkonce discard
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEPPNS6_15_Hash_node_baseEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEPPNS6_15_Hash_node_baseEj
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEPPNS6_15_Hash_node_baseEj;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEPPNS6_15_Hash_node_baseEj:
LFB3500:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	movl	%eax, 4(%esp)
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIPNSt8__detail15_Hash_node_baseEEC1INS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEERKSaIT_E
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS3_j
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIPNSt8__detail15_Hash_node_baseEED1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3500:
	.section	.text$_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv
	.def	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv;	.scl	2;	.type	32;	.endef
__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv:
LFB3515:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	$-1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxL27__exchange_and_add_dispatchEPii
	cmpl	$1, %eax
	sete	%al
	testb	%al, %al
	je	L1925
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	$-1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxL27__exchange_and_add_dispatchEPii
	cmpl	$1, %eax
	sete	%al
	testb	%al, %al
	je	L1925
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
L1925:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3515:
	.section	.text$_ZNSt11_Tuple_implILj1EIPKcEE7_M_tailERS2_,"x"
	.linkonce discard
	.globl	__ZNSt11_Tuple_implILj1EIPKcEE7_M_tailERS2_
	.def	__ZNSt11_Tuple_implILj1EIPKcEE7_M_tailERS2_;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj1EIPKcEE7_M_tailERS2_:
LFB3518:
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
LFE3518:
	.weak	__ZNSt11_Tuple_implILj1EJPKcEE7_M_tailERS2_
	.def	__ZNSt11_Tuple_implILj1EJPKcEE7_M_tailERS2_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt11_Tuple_implILj1EJPKcEE7_M_tailERS2_,__ZNSt11_Tuple_implILj1EIPKcEE7_M_tailERS2_
	.section	.text$_ZSt4moveIRSt11_Tuple_implILj2EIEEEONSt16remove_referenceIT_E4typeEOS4_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRSt11_Tuple_implILj2EIEEEONSt16remove_referenceIT_E4typeEOS4_
	.def	__ZSt4moveIRSt11_Tuple_implILj2EIEEEONSt16remove_referenceIT_E4typeEOS4_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRSt11_Tuple_implILj2EIEEEONSt16remove_referenceIT_E4typeEOS4_:
LFB3519:
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
LFE3519:
	.weak	__ZSt4moveIRSt11_Tuple_implILj2EJEEEONSt16remove_referenceIT_E4typeEOS4_
	.def	__ZSt4moveIRSt11_Tuple_implILj2EJEEEONSt16remove_referenceIT_E4typeEOS4_;	.scl	2;	.type	32;	.endef
	.set	__ZSt4moveIRSt11_Tuple_implILj2EJEEEONSt16remove_referenceIT_E4typeEOS4_,__ZSt4moveIRSt11_Tuple_implILj2EIEEEONSt16remove_referenceIT_E4typeEOS4_
	.section	.text$_ZNSt10_Head_baseILj1EPKcLb0EE7_M_headERS2_,"x"
	.linkonce discard
	.globl	__ZNSt10_Head_baseILj1EPKcLb0EE7_M_headERS2_
	.def	__ZNSt10_Head_baseILj1EPKcLb0EE7_M_headERS2_;	.scl	2;	.type	32;	.endef
__ZNSt10_Head_baseILj1EPKcLb0EE7_M_headERS2_:
LFB3521:
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
LFE3521:
	.section	.text$_ZNSt11_Tuple_implILj1EIPKcEE7_M_headERS2_,"x"
	.linkonce discard
	.globl	__ZNSt11_Tuple_implILj1EIPKcEE7_M_headERS2_
	.def	__ZNSt11_Tuple_implILj1EIPKcEE7_M_headERS2_;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj1EIPKcEE7_M_headERS2_:
LFB3520:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Head_baseILj1EPKcLb0EE7_M_headERS2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3520:
	.weak	__ZNSt11_Tuple_implILj1EJPKcEE7_M_headERS2_
	.def	__ZNSt11_Tuple_implILj1EJPKcEE7_M_headERS2_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt11_Tuple_implILj1EJPKcEE7_M_headERS2_,__ZNSt11_Tuple_implILj1EIPKcEE7_M_headERS2_
	.section	.text$_ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE
	.def	__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE:
LFB3522:
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
LFE3522:
	.section	.text$_ZNSt10_Head_baseILj1EPKcLb0EEC2IS1_vEEOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_Head_baseILj1EPKcLb0EEC2IS1_vEEOT_
	.def	__ZNSt10_Head_baseILj1EPKcLb0EEC2IS1_vEEOT_;	.scl	2;	.type	32;	.endef
__ZNSt10_Head_baseILj1EPKcLb0EEC2IS1_vEEOT_:
LFB3524:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3524:
	.section	.text$_ZNSt11_Tuple_implILj1EIPKcEEC2EOS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Tuple_implILj1EIPKcEEC2EOS2_
	.def	__ZNSt11_Tuple_implILj1EIPKcEEC2EOS2_;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj1EIPKcEEC2EOS2_:
LFB3526:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt11_Tuple_implILj1EIPKcEE7_M_tailERS2_
	movl	%eax, (%esp)
	call	__ZSt4moveIRSt11_Tuple_implILj2EIEEEONSt16remove_referenceIT_E4typeEOS4_
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt11_Tuple_implILj1EIPKcEE7_M_headERS2_
	movl	%eax, (%esp)
	call	__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE
	movl	8(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt10_Head_baseILj1EPKcLb0EEC2IS1_vEEOT_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3526:
	.weak	__ZNSt11_Tuple_implILj1EJPKcEEC2EOS2_
	.def	__ZNSt11_Tuple_implILj1EJPKcEEC2EOS2_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt11_Tuple_implILj1EJPKcEEC2EOS2_,__ZNSt11_Tuple_implILj1EIPKcEEC2EOS2_
	.section	.text$_ZNSt11_Tuple_implILj0EIPFvPKcES1_EE7_M_tailERS4_,"x"
	.linkonce discard
	.globl	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EE7_M_tailERS4_
	.def	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EE7_M_tailERS4_;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj0EIPFvPKcES1_EE7_M_tailERS4_:
LFB3531:
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
LFE3531:
	.weak	__ZNSt11_Tuple_implILj0EJPFvPKcES1_EE7_M_tailERS4_
	.def	__ZNSt11_Tuple_implILj0EJPFvPKcES1_EE7_M_tailERS4_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt11_Tuple_implILj0EJPFvPKcES1_EE7_M_tailERS4_,__ZNSt11_Tuple_implILj0EIPFvPKcES1_EE7_M_tailERS4_
	.section	.text$_ZSt4moveIRSt11_Tuple_implILj1EIPKcEEEONSt16remove_referenceIT_E4typeEOS6_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRSt11_Tuple_implILj1EIPKcEEEONSt16remove_referenceIT_E4typeEOS6_
	.def	__ZSt4moveIRSt11_Tuple_implILj1EIPKcEEEONSt16remove_referenceIT_E4typeEOS6_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRSt11_Tuple_implILj1EIPKcEEEONSt16remove_referenceIT_E4typeEOS6_:
LFB3532:
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
LFE3532:
	.weak	__ZSt4moveIRSt11_Tuple_implILj1EJPKcEEEONSt16remove_referenceIT_E4typeEOS6_
	.def	__ZSt4moveIRSt11_Tuple_implILj1EJPKcEEEONSt16remove_referenceIT_E4typeEOS6_;	.scl	2;	.type	32;	.endef
	.set	__ZSt4moveIRSt11_Tuple_implILj1EJPKcEEEONSt16remove_referenceIT_E4typeEOS6_,__ZSt4moveIRSt11_Tuple_implILj1EIPKcEEEONSt16remove_referenceIT_E4typeEOS6_
	.section	.text$_ZNSt10_Head_baseILj0EPFvPKcELb0EE7_M_headERS4_,"x"
	.linkonce discard
	.globl	__ZNSt10_Head_baseILj0EPFvPKcELb0EE7_M_headERS4_
	.def	__ZNSt10_Head_baseILj0EPFvPKcELb0EE7_M_headERS4_;	.scl	2;	.type	32;	.endef
__ZNSt10_Head_baseILj0EPFvPKcELb0EE7_M_headERS4_:
LFB3534:
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
LFE3534:
	.section	.text$_ZNSt11_Tuple_implILj0EIPFvPKcES1_EE7_M_headERS4_,"x"
	.linkonce discard
	.globl	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EE7_M_headERS4_
	.def	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EE7_M_headERS4_;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj0EIPFvPKcES1_EE7_M_headERS4_:
LFB3533:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Head_baseILj0EPFvPKcELb0EE7_M_headERS4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3533:
	.weak	__ZNSt11_Tuple_implILj0EJPFvPKcES1_EE7_M_headERS4_
	.def	__ZNSt11_Tuple_implILj0EJPFvPKcES1_EE7_M_headERS4_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt11_Tuple_implILj0EJPFvPKcES1_EE7_M_headERS4_,__ZNSt11_Tuple_implILj0EIPFvPKcES1_EE7_M_headERS4_
	.section	.text$_ZSt7forwardIPFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIPFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE
	.def	__ZSt7forwardIPFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIPFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE:
LFB3535:
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
LFE3535:
	.section	.text$_ZNSt10_Head_baseILj0EPFvPKcELb0EEC2IS3_vEEOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_Head_baseILj0EPFvPKcELb0EEC2IS3_vEEOT_
	.def	__ZNSt10_Head_baseILj0EPFvPKcELb0EEC2IS3_vEEOT_;	.scl	2;	.type	32;	.endef
__ZNSt10_Head_baseILj0EPFvPKcELb0EEC2IS3_vEEOT_:
LFB3537:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIPFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3537:
	.section	.text$_ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2EOS4_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2EOS4_
	.def	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2EOS4_;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2EOS4_:
LFB3539:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EE7_M_tailERS4_
	movl	%eax, (%esp)
	call	__ZSt4moveIRSt11_Tuple_implILj1EIPKcEEEONSt16remove_referenceIT_E4typeEOS6_
	movl	8(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt11_Tuple_implILj1EIPKcEEC2EOS2_
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EE7_M_headERS4_
	movl	%eax, (%esp)
	call	__ZSt7forwardIPFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	8(%ebp), %edx
	addl	$4, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt10_Head_baseILj0EPFvPKcELb0EEC2IS3_vEEOT_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3539:
	.weak	__ZNSt11_Tuple_implILj0EJPFvPKcES1_EEC2EOS4_
	.def	__ZNSt11_Tuple_implILj0EJPFvPKcES1_EEC2EOS4_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt11_Tuple_implILj0EJPFvPKcES1_EEC2EOS4_,__ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2EOS4_
	.section	.text$_ZNSt5tupleIIPFvPKcES1_EEC1EOS4_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5tupleIIPFvPKcES1_EEC1EOS4_
	.def	__ZNSt5tupleIIPFvPKcES1_EEC1EOS4_;	.scl	2;	.type	32;	.endef
__ZNSt5tupleIIPFvPKcES1_EEC1EOS4_:
LFB3542:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2EOS4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3542:
	.weak	__ZNSt5tupleIJPFvPKcES1_EEC1EOS4_
	.def	__ZNSt5tupleIJPFvPKcES1_EEC1EOS4_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt5tupleIJPFvPKcES1_EEC1EOS4_,__ZNSt5tupleIIPFvPKcES1_EEC1EOS4_
	.section	.text$_ZNSt12_Bind_simpleIFPFvPKcES1_EEC1EOS5_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1EOS5_
	.def	__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1EOS5_;	.scl	2;	.type	32;	.endef
__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1EOS5_:
LFB3544:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt5tupleIIPFvPKcES1_EEC1EOS4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3544:
	.section	.text$_ZSt13__bind_simpleIRFvPKcEIRA28_S0_EENSt19_Bind_simple_helperIT_IDpT0_EE6__typeEOS7_DpOS8_,"x"
	.linkonce discard
	.globl	__ZSt13__bind_simpleIRFvPKcEIRA28_S0_EENSt19_Bind_simple_helperIT_IDpT0_EE6__typeEOS7_DpOS8_
	.def	__ZSt13__bind_simpleIRFvPKcEIRA28_S0_EENSt19_Bind_simple_helperIT_IDpT0_EE6__typeEOS7_DpOS8_;	.scl	2;	.type	32;	.endef
__ZSt13__bind_simpleIRFvPKcEIRA28_S0_EENSt19_Bind_simple_helperIT_IDpT0_EE6__typeEOS7_DpOS8_:
LFB3516:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRA28_KcEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	%eax, -12(%ebp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt26_Maybe_wrap_member_pointerIPFvPKcEE9__do_wrapEOS3_
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IIRA28_S0_EvEEOS3_DpOT_
	movl	8(%ebp), %eax
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3516:
	.weak	__ZSt13__bind_simpleIRFvPKcEJRA28_S0_EENSt19_Bind_simple_helperIT_JDpT0_EE6__typeEOS7_DpOS8_
	.def	__ZSt13__bind_simpleIRFvPKcEJRA28_S0_EENSt19_Bind_simple_helperIT_JDpT0_EE6__typeEOS7_DpOS8_;	.scl	2;	.type	32;	.endef
	.set	__ZSt13__bind_simpleIRFvPKcEJRA28_S0_EENSt19_Bind_simple_helperIT_JDpT0_EE6__typeEOS7_DpOS8_,__ZSt13__bind_simpleIRFvPKcEIRA28_S0_EENSt19_Bind_simple_helperIT_IDpT0_EE6__typeEOS7_DpOS8_
	.section	.text$_ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE
	.def	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE:
LFB3546:
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
LFE3546:
	.section	.text$_ZNSt6thread15_M_make_routineISt12_Bind_simpleIFPFvPKcES3_EEEESt10shared_ptrINS_5_ImplIT_EEEOSA_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6thread15_M_make_routineISt12_Bind_simpleIFPFvPKcES3_EEEESt10shared_ptrINS_5_ImplIT_EEEOSA_
	.def	__ZNSt6thread15_M_make_routineISt12_Bind_simpleIFPFvPKcES3_EEEESt10shared_ptrINS_5_ImplIT_EEEOSA_;	.scl	2;	.type	32;	.endef
__ZNSt6thread15_M_make_routineISt12_Bind_simpleIFPFvPKcES3_EEEESt10shared_ptrINS_5_ImplIT_EEEOSA_:
LFB3545:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE
	movl	8(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZSt11make_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEIS8_EESt10shared_ptrIT_EDpOT0_
	subl	$4, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3545:
	.section	.text$_ZSt4moveIRSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEEONSt16remove_referenceIT_E4typeEOSE_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEEONSt16remove_referenceIT_E4typeEOSE_
	.def	__ZSt4moveIRSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEEONSt16remove_referenceIT_E4typeEOSE_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEEONSt16remove_referenceIT_E4typeEOSE_:
LFB3548:
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
LFE3548:
	.section	.text$_ZNSt10shared_ptrINSt6thread10_Impl_baseEEC1INS0_5_ImplISt12_Bind_simpleIFPFvPKcES7_EEEEvEEOS_IT_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10shared_ptrINSt6thread10_Impl_baseEEC1INS0_5_ImplISt12_Bind_simpleIFPFvPKcES7_EEEEvEEOS_IT_E
	.def	__ZNSt10shared_ptrINSt6thread10_Impl_baseEEC1INS0_5_ImplISt12_Bind_simpleIFPFvPKcES7_EEEEvEEOS_IT_E;	.scl	2;	.type	32;	.endef
__ZNSt10shared_ptrINSt6thread10_Impl_baseEEC1INS0_5_ImplISt12_Bind_simpleIFPFvPKcES7_EEEEvEEOS_IT_E:
LFB3550:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEEONSt16remove_referenceIT_E4typeEOSE_
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt12__shared_ptrINSt6thread10_Impl_baseELN9__gnu_cxx12_Lock_policyE2EEC2INS0_5_ImplISt12_Bind_simpleIFPFvPKcES9_EEEEvEEOS_IT_LS3_2EE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3550:
	.section	.text$_ZSt13__bind_simpleIRFvPKcEIRA29_S0_EENSt19_Bind_simple_helperIT_IDpT0_EE6__typeEOS7_DpOS8_,"x"
	.linkonce discard
	.globl	__ZSt13__bind_simpleIRFvPKcEIRA29_S0_EENSt19_Bind_simple_helperIT_IDpT0_EE6__typeEOS7_DpOS8_
	.def	__ZSt13__bind_simpleIRFvPKcEIRA29_S0_EENSt19_Bind_simple_helperIT_IDpT0_EE6__typeEOS7_DpOS8_;	.scl	2;	.type	32;	.endef
__ZSt13__bind_simpleIRFvPKcEIRA29_S0_EENSt19_Bind_simple_helperIT_IDpT0_EE6__typeEOS7_DpOS8_:
LFB3555:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRA29_KcEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	%eax, -12(%ebp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt26_Maybe_wrap_member_pointerIPFvPKcEE9__do_wrapEOS3_
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IIRA29_S0_EvEEOS3_DpOT_
	movl	8(%ebp), %eax
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3555:
	.weak	__ZSt13__bind_simpleIRFvPKcEJRA29_S0_EENSt19_Bind_simple_helperIT_JDpT0_EE6__typeEOS7_DpOS8_
	.def	__ZSt13__bind_simpleIRFvPKcEJRA29_S0_EENSt19_Bind_simple_helperIT_JDpT0_EE6__typeEOS7_DpOS8_;	.scl	2;	.type	32;	.endef
	.set	__ZSt13__bind_simpleIRFvPKcEJRA29_S0_EENSt19_Bind_simple_helperIT_JDpT0_EE6__typeEOS7_DpOS8_,__ZSt13__bind_simpleIRFvPKcEIRA29_S0_EENSt19_Bind_simple_helperIT_IDpT0_EE6__typeEOS7_DpOS8_
	.section	.text$_ZNSt8__detail12_Insert_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE20_M_conjure_hashtableEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail12_Insert_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE20_M_conjure_hashtableEv
	.def	__ZNSt8__detail12_Insert_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE20_M_conjure_hashtableEv;	.scl	2;	.type	32;	.endef
__ZNSt8__detail12_Insert_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE20_M_conjure_hashtableEv:
LFB3556:
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
LFE3556:
	.section	.text$_ZSt7forwardIRSt4pairIKjN6CTest84DATAEEEOT_RNSt16remove_referenceIS6_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRSt4pairIKjN6CTest84DATAEEEOT_RNSt16remove_referenceIS6_E4typeE
	.def	__ZSt7forwardIRSt4pairIKjN6CTest84DATAEEEOT_RNSt16remove_referenceIS6_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRSt4pairIKjN6CTest84DATAEEEOT_RNSt16remove_referenceIS6_E4typeE:
LFB3558:
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
LFE3558:
	.section	.text$_ZNSt10__pair_getILj0EE5__getIKjN6CTest84DATAEEERT_RSt4pairIS5_T0_E,"x"
	.linkonce discard
	.globl	__ZNSt10__pair_getILj0EE5__getIKjN6CTest84DATAEEERT_RSt4pairIS5_T0_E
	.def	__ZNSt10__pair_getILj0EE5__getIKjN6CTest84DATAEEERT_RSt4pairIS5_T0_E;	.scl	2;	.type	32;	.endef
__ZNSt10__pair_getILj0EE5__getIKjN6CTest84DATAEEERT_RSt4pairIS5_T0_E:
LFB3560:
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
LFE3560:
	.section	.text$_ZSt3getILj0EKjN6CTest84DATAEERNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERS7_,"x"
	.linkonce discard
	.globl	__ZSt3getILj0EKjN6CTest84DATAEERNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERS7_
	.def	__ZSt3getILj0EKjN6CTest84DATAEERNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERS7_;	.scl	2;	.type	32;	.endef
__ZSt3getILj0EKjN6CTest84DATAEERNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERS7_:
LFB3559:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10__pair_getILj0EE5__getIKjN6CTest84DATAEEERT_RSt4pairIS5_T0_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3559:
	.section	.text$_ZSt7forwardINSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEEEOT_RNSt16remove_referenceIS8_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardINSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEEEOT_RNSt16remove_referenceIS8_E4typeE
	.def	__ZSt7forwardINSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEEEOT_RNSt16remove_referenceIS8_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardINSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEEEOT_RNSt16remove_referenceIS8_E4typeE:
LFB3562:
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
LFE3562:
	.section	.text$_ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE
	.def	__ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE:
LFB3563:
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
LFE3563:
	.section	.text$_ZNSt4pairINSt8__detail14_Node_iteratorIS_IKjN6CTest84DATAEELb0ELb0EEEbEC1IS6_bvEEOT_OT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairINSt8__detail14_Node_iteratorIS_IKjN6CTest84DATAEELb0ELb0EEEbEC1IS6_bvEEOT_OT0_
	.def	__ZNSt4pairINSt8__detail14_Node_iteratorIS_IKjN6CTest84DATAEELb0ELb0EEEbEC1IS6_bvEEOT_OT0_;	.scl	2;	.type	32;	.endef
__ZNSt4pairINSt8__detail14_Node_iteratorIS_IKjN6CTest84DATAEELb0ELb0EEEbEC1IS6_bvEEOT_OT0_:
LFB3566:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardINSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEEEOT_RNSt16remove_referenceIS8_E4typeE
	movl	8(%ebp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE
	movzbl	(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, 4(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3566:
	.section	.text$_ZSt9make_pairINSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEEbES2_INSt17__decay_and_stripIT_E6__typeENS8_IT0_E6__typeEEOS9_OSC_,"x"
	.linkonce discard
	.globl	__ZSt9make_pairINSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEEbES2_INSt17__decay_and_stripIT_E6__typeENS8_IT0_E6__typeEEOS9_OSC_
	.def	__ZSt9make_pairINSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEEbES2_INSt17__decay_and_stripIT_E6__typeENS8_IT0_E6__typeEEOS9_OSC_;	.scl	2;	.type	32;	.endef
__ZSt9make_pairINSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEEbES2_INSt17__decay_and_stripIT_E6__typeENS8_IT0_E6__typeEEOS9_OSC_:
LFB3561:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$28, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardINSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEEEOT_RNSt16remove_referenceIS8_E4typeE
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt4pairINSt8__detail14_Node_iteratorIS_IKjN6CTest84DATAEELb0ELb0EEEbEC1IS6_bvEEOT_OT0_
	movl	-12(%ebp), %eax
	movl	-8(%ebp), %edx
	addl	$28, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3561:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIIS0_IjS3_EEEES0_INS6_14_Node_iteratorIS4_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIIS0_IjS3_EEEES0_INS6_14_Node_iteratorIS4_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIIS0_IjS3_EEEES0_INS6_14_Node_iteratorIS4_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIIS0_IjS3_EEEES0_INS6_14_Node_iteratorIS4_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_:
LFB3557:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3557
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt4pairIjN6CTest84DATAEEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB362:
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIIS0_IjS3_EEEEPNS6_10_Hash_nodeIS4_Lb0EEEDpOT_
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	leal	4(%eax), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv
LEHE362:
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Select1stclIRSt4pairIKjN6CTest84DATAEEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS8_
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB363:
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE12_M_hash_codeERS2_
LEHE363:
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB364:
	call	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexERS1_j
	movl	%eax, -24(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE12_M_find_nodeEjRS1_j
	movl	%eax, -28(%ebp)
	cmpl	$0, -28(%ebp)
	je	L1980
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS6_10_Hash_nodeIS4_Lb0EEE
LEHE364:
	movb	$0, -41(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
LEHB365:
	call	__ZNSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEC1EPNS_10_Hash_nodeIS5_Lb0EEE
LEHE365:
	leal	-41(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt9make_pairINSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEEbES2_INSt17__decay_and_stripIT_E6__typeENS8_IT0_E6__typeEEOS9_OSC_
	jmp	L1990
L1980:
	movb	$1, -33(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB366:
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEjjPNS6_10_Hash_nodeIS4_Lb0EEE
LEHE366:
	movl	%eax, -32(%ebp)
	leal	-33(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt9make_pairINSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEEbES2_INSt17__decay_and_stripIT_E6__typeENS8_IT0_E6__typeEEOS9_OSC_
	jmp	L1990
L1987:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB367:
	call	__Unwind_Resume
LEHE367:
L1986:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB368:
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS6_10_Hash_nodeIS4_Lb0EEE
	call	___cxa_rethrow
LEHE368:
L1988:
	movl	%eax, (%esp)
LEHB369:
	call	__Unwind_Resume
L1989:
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE369:
L1990:
	addl	$68, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3557:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA3557:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT3557-LLSDATTD3557
LLSDATTD3557:
	.byte	0x1
	.uleb128 LLSDACSE3557-LLSDACSB3557
LLSDACSB3557:
	.uleb128 LEHB362-LFB3557
	.uleb128 LEHE362-LEHB362
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB363-LFB3557
	.uleb128 LEHE363-LEHB363
	.uleb128 L1986-LFB3557
	.uleb128 0x1
	.uleb128 LEHB364-LFB3557
	.uleb128 LEHE364-LEHB364
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB365-LFB3557
	.uleb128 LEHE365-LEHB365
	.uleb128 L1988-LFB3557
	.uleb128 0
	.uleb128 LEHB366-LFB3557
	.uleb128 LEHE366-LEHB366
	.uleb128 L1989-LFB3557
	.uleb128 0
	.uleb128 LEHB367-LFB3557
	.uleb128 LEHE367-LEHB367
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB368-LFB3557
	.uleb128 LEHE368-LEHB368
	.uleb128 L1987-LFB3557
	.uleb128 0
	.uleb128 LEHB369-LFB3557
	.uleb128 LEHE369-LEHB369
	.uleb128 0
	.uleb128 0
LLSDACSE3557:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT3557:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIIS0_IjS3_EEEES0_INS6_14_Node_iteratorIS4_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_,"x"
	.linkonce discard
	.weak	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIJS0_IjS3_EEEES0_INS6_14_Node_iteratorIS4_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIJS0_IjS3_EEEES0_INS6_14_Node_iteratorIS4_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIJS0_IjS3_EEEES0_INS6_14_Node_iteratorIS4_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_,__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIIS0_IjS3_EEEES0_INS6_14_Node_iteratorIS4_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_
	.section	.text$_ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE12_M_hash_codeERS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE12_M_hash_codeERS2_
	.def	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE12_M_hash_codeERS2_;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE12_M_hash_codeERS2_:
LFB3567:
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
	movl	(%eax), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h1Ev
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt4hashIjEclEj
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3567:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexERS1_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexERS1_j
	.def	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexERS1_j;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexERS1_j:
LFB3568:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexERS2_jj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3568:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE12_M_find_nodeEjRS1_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE12_M_find_nodeEjRS1_j
	.def	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE12_M_find_nodeEjRS1_j;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE12_M_find_nodeEjRS1_j:
LFB3569:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_find_before_nodeEjRS1_j
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	L1996
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	jmp	L1997
L1996:
	movl	$0, %eax
L1997:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3569:
	.section	.text$_ZNSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEC1EPNS_10_Hash_nodeIS5_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEC1EPNS_10_Hash_nodeIS5_Lb0EEE
	.def	__ZNSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEC1EPNS_10_Hash_nodeIS5_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEC1EPNS_10_Hash_nodeIS5_Lb0EEE:
LFB3572:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt8__detail19_Node_iterator_baseISt4pairIKjN6CTest84DATAEELb0EEC2EPNS_10_Hash_nodeIS5_Lb0EEE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3572:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv:
LFB3573:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEC1EPNS_10_Hash_nodeIS5_Lb0EEE
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3573:
	.section	.text$_ZNSt8__detail20_Node_const_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEC1EPNS_10_Hash_nodeIS5_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail20_Node_const_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEC1EPNS_10_Hash_nodeIS5_Lb0EEE
	.def	__ZNSt8__detail20_Node_const_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEC1EPNS_10_Hash_nodeIS5_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt8__detail20_Node_const_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEC1EPNS_10_Hash_nodeIS5_Lb0EEE:
LFB3576:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt8__detail19_Node_iterator_baseISt4pairIKjN6CTest84DATAEELb0EEC2EPNS_10_Hash_nodeIS5_Lb0EEE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3576:
	.section	.text$_ZNSt8__detail12_Insert_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail12_Insert_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2Ev
	.def	__ZNSt8__detail12_Insert_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt8__detail12_Insert_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2Ev:
LFB3580:
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
LFE3580:
	.section	.text$_ZNSt8__detail7_InsertIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail7_InsertIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EEC2Ev
	.def	__ZNSt8__detail7_InsertIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt8__detail7_InsertIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EEC2Ev:
LFB3582:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail12_Insert_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3582:
	.section	.text$_ZNSt8__detail9_EqualityIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail9_EqualityIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEC2Ev
	.def	__ZNSt8__detail9_EqualityIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt8__detail9_EqualityIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEC2Ev:
LFB3585:
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
LFE3585:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKSB_RKSC_RKSD_RKS9_RKS7_RKS5_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKSB_RKSC_RKSD_RKS9_RKS7_RKS5_
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKSB_RKSC_RKSD_RKS9_RKS7_RKS5_;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKSB_RKSC_RKSD_RKS9_RKS7_RKS5_:
LFB3588:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3588
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	28(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	24(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB370:
	call	__ZNSt8__detail15_Hashtable_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2ERKS6_RKSA_RKSB_RKSC_RKS8_
LEHE370:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail7_InsertIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EEC2Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail9_EqualityIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEC2Ev
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	8(%ebp), %eax
	leal	8(%eax), %edx
	movl	36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEEC1IRKSaIS6_EEEOT_
	movl	8(%ebp), %eax
	movl	$0, 12(%eax)
	movl	8(%ebp), %eax
	leal	16(%eax), %edx
	movl	LC265, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt8__detail20_Prime_rehash_policyC1Ef
	movl	8(%ebp), %eax
	leal	16(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
LEHB371:
	call	__ZNKSt8__detail20_Prime_rehash_policy11_M_next_bktEj
	movl	8(%ebp), %edx
	movl	%eax, 4(%edx)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_allocate_bucketsEj
LEHE371:
	movl	8(%ebp), %edx
	movl	%eax, (%edx)
	jmp	L2008
L2007:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB372:
	call	__Unwind_Resume
LEHE372:
L2008:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3588:
	.section	.gcc_except_table,"w"
LLSDA3588:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3588-LLSDACSB3588
LLSDACSB3588:
	.uleb128 LEHB370-LFB3588
	.uleb128 LEHE370-LEHB370
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB371-LFB3588
	.uleb128 LEHE371-LEHB371
	.uleb128 L2007-LFB3588
	.uleb128 0
	.uleb128 LEHB372-LFB3588
	.uleb128 LEHE372-LEHB372
	.uleb128 0
	.uleb128 0
LLSDACSE3588:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKSB_RKSC_RKSD_RKS9_RKS7_RKS5_,"x"
	.linkonce discard
	.section	.text$_ZNKSt8__detail12_Rehash_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE15max_load_factorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail12_Rehash_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE15max_load_factorEv
	.def	__ZNKSt8__detail12_Rehash_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE15max_load_factorEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail12_Rehash_baseIjSt4pairIKjN6CTest84DATAEESaIS5_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE15max_load_factorEv:
LFB3589:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15__rehash_policyEv
	movl	%eax, (%esp)
	call	__ZNKSt8__detail20_Prime_rehash_policy15max_load_factorEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3589:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE6rehashEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE6rehashEj
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE6rehashEj;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE6rehashEj:
LFB3590:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail20_Prime_rehash_policy8_M_stateEv
	movl	%eax, -24(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt8__detail20_Prime_rehash_policy19_M_bkt_for_elementsEj
	movl	%eax, -20(%ebp)
	leal	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt3maxIjERKT_S2_S2_
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	leal	16(%eax), %edx
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNKSt8__detail20_Prime_rehash_policy11_M_next_bktEj
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-16(%ebp), %eax
	je	L2012
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEjRS1_
	jmp	L2011
L2012:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	addl	$16, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt8__detail20_Prime_rehash_policy8_M_resetEj
L2011:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3590:
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEED2Ev:
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
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_deallocate_nodesEPNS6_10_Hash_nodeIS4_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_deallocate_nodesEPNS6_10_Hash_nodeIS4_Lb0EEE
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_deallocate_nodesEPNS6_10_Hash_nodeIS4_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_deallocate_nodesEPNS6_10_Hash_nodeIS4_Lb0EEE:
LFB3594:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	jmp	L2017
L2018:
	movl	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EE7_M_nextEv
	movl	%eax, 12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS6_10_Hash_nodeIS4_Lb0EEE
L2017:
	cmpl	$0, 12(%ebp)
	jne	L2018
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3594:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE8_M_beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE8_M_beginEv
	.def	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE8_M_beginEv;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE8_M_beginEv:
LFB3595:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3595:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv:
LFB3596:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	addl	$8, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3596:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv:
LFB3597:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	addl	$8, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3597:
	.section	.text$_ZNSaIPNSt8__detail15_Hash_node_baseEEC1INS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEERKSaIT_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaIPNSt8__detail15_Hash_node_baseEEC1INS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEERKSaIT_E
	.def	__ZNSaIPNSt8__detail15_Hash_node_baseEEC1INS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEERKSaIT_E;	.scl	2;	.type	32;	.endef
__ZNSaIPNSt8__detail15_Hash_node_baseEEC1INS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEERKSaIT_E:
LFB3600:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEEC2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3600:
	.section	.text$_ZNSaIPNSt8__detail15_Hash_node_baseEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaIPNSt8__detail15_Hash_node_baseEED1Ev
	.def	__ZNSaIPNSt8__detail15_Hash_node_baseEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSaIPNSt8__detail15_Hash_node_baseEED1Ev:
LFB3603:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3603:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS3_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS3_j
	.def	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS3_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS3_j:
LFB3604:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3604:
	.section	.text$_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv
	.def	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv;	.scl	2;	.type	32;	.endef
__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv:
LFB3609:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	je	L2029
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
L2029:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3609:
	.section	.text$_ZNSt26_Maybe_wrap_member_pointerIPFvPKcEE9__do_wrapEOS3_,"x"
	.linkonce discard
	.globl	__ZNSt26_Maybe_wrap_member_pointerIPFvPKcEE9__do_wrapEOS3_
	.def	__ZNSt26_Maybe_wrap_member_pointerIPFvPKcEE9__do_wrapEOS3_;	.scl	2;	.type	32;	.endef
__ZNSt26_Maybe_wrap_member_pointerIPFvPKcEE9__do_wrapEOS3_:
LFB3610:
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
LFE3610:
	.section	.text$_ZSt4moveIRPFvPKcEEONSt16remove_referenceIT_E4typeEOS6_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRPFvPKcEEONSt16remove_referenceIT_E4typeEOS6_
	.def	__ZSt4moveIRPFvPKcEEONSt16remove_referenceIT_E4typeEOS6_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRPFvPKcEEONSt16remove_referenceIT_E4typeEOS6_:
LFB3612:
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
LFE3612:
	.section	.text$_ZNSt11_Tuple_implILj2EIEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Tuple_implILj2EIEEC2Ev
	.def	__ZNSt11_Tuple_implILj2EIEEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj2EIEEC2Ev:
LFB3617:
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
LFE3617:
	.weak	__ZNSt11_Tuple_implILj2EJEEC2Ev
	.def	__ZNSt11_Tuple_implILj2EJEEC2Ev;	.scl	2;	.type	32;	.endef
	.set	__ZNSt11_Tuple_implILj2EJEEC2Ev,__ZNSt11_Tuple_implILj2EIEEC2Ev
	.section	.text$_ZNSt10_Head_baseILj1EPKcLb0EEC2ERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_Head_baseILj1EPKcLb0EEC2ERKS1_
	.def	__ZNSt10_Head_baseILj1EPKcLb0EEC2ERKS1_;	.scl	2;	.type	32;	.endef
__ZNSt10_Head_baseILj1EPKcLb0EEC2ERKS1_:
LFB3620:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3620:
	.section	.text$_ZNSt11_Tuple_implILj1EIPKcEEC2ERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Tuple_implILj1EIPKcEEC2ERKS1_
	.def	__ZNSt11_Tuple_implILj1EIPKcEEC2ERKS1_;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj1EIPKcEEC2ERKS1_:
LFB3622:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt11_Tuple_implILj2EIEEC2Ev
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt10_Head_baseILj1EPKcLb0EEC2ERKS1_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3622:
	.weak	__ZNSt11_Tuple_implILj1EJPKcEEC2ERKS1_
	.def	__ZNSt11_Tuple_implILj1EJPKcEEC2ERKS1_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt11_Tuple_implILj1EJPKcEEC2ERKS1_,__ZNSt11_Tuple_implILj1EIPKcEEC2ERKS1_
	.section	.text$_ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2IS3_IRA28_S0_EvEEOT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2IS3_IRA28_S0_EvEEOT_DpOT0_
	.def	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2IS3_IRA28_S0_EvEEOT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2IS3_IRA28_S0_EvEEOT_DpOT0_:
LFB3624:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRA28_KcEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, -4(%ebp)
	movl	8(%ebp), %eax
	leal	-4(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt11_Tuple_implILj1EIPKcEEC2ERKS1_
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIPFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	8(%ebp), %edx
	addl	$4, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt10_Head_baseILj0EPFvPKcELb0EEC2IS3_vEEOT_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3624:
	.weak	__ZNSt11_Tuple_implILj0EJPFvPKcES1_EEC2IS3_JRA28_S0_EvEEOT_DpOT0_
	.def	__ZNSt11_Tuple_implILj0EJPFvPKcES1_EEC2IS3_JRA28_S0_EvEEOT_DpOT0_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt11_Tuple_implILj0EJPFvPKcES1_EEC2IS3_JRA28_S0_EvEEOT_DpOT0_,__ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2IS3_IRA28_S0_EvEEOT_DpOT0_
	.section	.text$_ZNSt5tupleIIPFvPKcES1_EEC1IS3_RA28_S0_vEEOT_OT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5tupleIIPFvPKcES1_EEC1IS3_RA28_S0_vEEOT_OT0_
	.def	__ZNSt5tupleIIPFvPKcES1_EEC1IS3_RA28_S0_vEEOT_OT0_;	.scl	2;	.type	32;	.endef
__ZNSt5tupleIIPFvPKcES1_EEC1IS3_RA28_S0_vEEOT_OT0_:
LFB3627:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$12, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRA28_KcEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIPFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	8(%ebp), %edx
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2IS3_IRA28_S0_EvEEOT_DpOT0_
	addl	$12, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3627:
	.weak	__ZNSt5tupleIJPFvPKcES1_EEC1IS3_RA28_S0_vEEOT_OT0_
	.def	__ZNSt5tupleIJPFvPKcES1_EEC1IS3_RA28_S0_vEEOT_OT0_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt5tupleIJPFvPKcES1_EEC1IS3_RA28_S0_vEEOT_OT0_,__ZNSt5tupleIIPFvPKcES1_EEC1IS3_RA28_S0_vEEOT_OT0_
	.section	.text$_ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IIRA28_S0_EvEEOS3_DpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IIRA28_S0_EvEEOS3_DpOT_
	.def	__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IIRA28_S0_EvEEOS3_DpOT_;	.scl	2;	.type	32;	.endef
__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IIRA28_S0_EvEEOS3_DpOT_:
LFB3629:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$12, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRA28_KcEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRPFvPKcEEONSt16remove_referenceIT_E4typeEOS6_
	movl	8(%ebp), %edx
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt5tupleIIPFvPKcES1_EEC1IS3_RA28_S0_vEEOT_OT0_
	addl	$12, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3629:
	.weak	__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IJRA28_S0_EvEEOS3_DpOT_
	.def	__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IJRA28_S0_EvEEOS3_DpOT_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IJRA28_S0_EvEEOS3_DpOT_,__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IIRA28_S0_EvEEOS3_DpOT_
	.section	.text$_ZSt11make_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEIS8_EESt10shared_ptrIT_EDpOT0_,"x"
	.linkonce discard
	.globl	__ZSt11make_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEIS8_EESt10shared_ptrIT_EDpOT0_
	.def	__ZSt11make_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEIS8_EESt10shared_ptrIT_EDpOT0_;	.scl	2;	.type	32;	.endef
__ZSt11make_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEIS8_EESt10shared_ptrIT_EDpOT0_:
LFB3630:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3630
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
	call	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE
	movl	%eax, %ebx
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC1Ev
	movl	8(%ebp), %eax
	movl	%ebx, 8(%esp)
	leal	-9(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB373:
	call	__ZSt15allocate_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_EIS8_EESt10shared_ptrIT_ERKT0_DpOT1_
LEHE373:
	subl	$4, %esp
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEED1Ev
	jmp	L2045
L2044:
	movl	%eax, %ebx
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB374:
	call	__Unwind_Resume
LEHE374:
L2045:
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3630:
	.section	.gcc_except_table,"w"
LLSDA3630:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3630-LLSDACSB3630
LLSDACSB3630:
	.uleb128 LEHB373-LFB3630
	.uleb128 LEHE373-LEHB373
	.uleb128 L2044-LFB3630
	.uleb128 0
	.uleb128 LEHB374-LFB3630
	.uleb128 LEHE374-LEHB374
	.uleb128 0
	.uleb128 0
LLSDACSE3630:
	.section	.text$_ZSt11make_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEIS8_EESt10shared_ptrIT_EDpOT0_,"x"
	.linkonce discard
	.weak	__ZSt11make_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEJS8_EESt10shared_ptrIT_EDpOT0_
	.def	__ZSt11make_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEJS8_EESt10shared_ptrIT_EDpOT0_;	.scl	2;	.type	32;	.endef
	.set	__ZSt11make_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEJS8_EESt10shared_ptrIT_EDpOT0_,__ZSt11make_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEIS8_EESt10shared_ptrIT_EDpOT0_
	.section	.text$_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC1Ev
	.def	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC1Ev:
LFB3637:
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
LFE3637:
	.section	.text$_ZNSt12__shared_ptrINSt6thread10_Impl_baseELN9__gnu_cxx12_Lock_policyE2EEC2INS0_5_ImplISt12_Bind_simpleIFPFvPKcES9_EEEEvEEOS_IT_LS3_2EE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12__shared_ptrINSt6thread10_Impl_baseELN9__gnu_cxx12_Lock_policyE2EEC2INS0_5_ImplISt12_Bind_simpleIFPFvPKcES9_EEEEvEEOS_IT_LS3_2EE
	.def	__ZNSt12__shared_ptrINSt6thread10_Impl_baseELN9__gnu_cxx12_Lock_policyE2EEC2INS0_5_ImplISt12_Bind_simpleIFPFvPKcES9_EEEEvEEOS_IT_LS3_2EE;	.scl	2;	.type	32;	.endef
__ZNSt12__shared_ptrINSt6thread10_Impl_baseELN9__gnu_cxx12_Lock_policyE2EEC2INS0_5_ImplISt12_Bind_simpleIFPFvPKcES9_EEEEvEEOS_IT_LS3_2EE:
LFB3638:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	call	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC1Ev
	movl	12(%ebp), %eax
	leal	4(%eax), %edx
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EE7_M_swapERS2_
	movl	12(%ebp), %eax
	movl	$0, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3638:
	.section	.text$_ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2IS3_IRA29_S0_EvEEOT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2IS3_IRA29_S0_EvEEOT_DpOT0_
	.def	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2IS3_IRA29_S0_EvEEOT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2IS3_IRA29_S0_EvEEOT_DpOT0_:
LFB3646:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRA29_KcEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, -4(%ebp)
	movl	8(%ebp), %eax
	leal	-4(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt11_Tuple_implILj1EIPKcEEC2ERKS1_
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIPFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	8(%ebp), %edx
	addl	$4, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt10_Head_baseILj0EPFvPKcELb0EEC2IS3_vEEOT_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3646:
	.weak	__ZNSt11_Tuple_implILj0EJPFvPKcES1_EEC2IS3_JRA29_S0_EvEEOT_DpOT0_
	.def	__ZNSt11_Tuple_implILj0EJPFvPKcES1_EEC2IS3_JRA29_S0_EvEEOT_DpOT0_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt11_Tuple_implILj0EJPFvPKcES1_EEC2IS3_JRA29_S0_EvEEOT_DpOT0_,__ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2IS3_IRA29_S0_EvEEOT_DpOT0_
	.section	.text$_ZNSt5tupleIIPFvPKcES1_EEC1IS3_RA29_S0_vEEOT_OT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5tupleIIPFvPKcES1_EEC1IS3_RA29_S0_vEEOT_OT0_
	.def	__ZNSt5tupleIIPFvPKcES1_EEC1IS3_RA29_S0_vEEOT_OT0_;	.scl	2;	.type	32;	.endef
__ZNSt5tupleIIPFvPKcES1_EEC1IS3_RA29_S0_vEEOT_OT0_:
LFB3649:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$12, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRA29_KcEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIPFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	8(%ebp), %edx
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EEC2IS3_IRA29_S0_EvEEOT_DpOT0_
	addl	$12, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3649:
	.weak	__ZNSt5tupleIJPFvPKcES1_EEC1IS3_RA29_S0_vEEOT_OT0_
	.def	__ZNSt5tupleIJPFvPKcES1_EEC1IS3_RA29_S0_vEEOT_OT0_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt5tupleIJPFvPKcES1_EEC1IS3_RA29_S0_vEEOT_OT0_,__ZNSt5tupleIIPFvPKcES1_EEC1IS3_RA29_S0_vEEOT_OT0_
	.section	.text$_ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IIRA29_S0_EvEEOS3_DpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IIRA29_S0_EvEEOS3_DpOT_
	.def	__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IIRA29_S0_EvEEOS3_DpOT_;	.scl	2;	.type	32;	.endef
__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IIRA29_S0_EvEEOS3_DpOT_:
LFB3651:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$12, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRA29_KcEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRPFvPKcEEONSt16remove_referenceIT_E4typeEOS6_
	movl	8(%ebp), %edx
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt5tupleIIPFvPKcES1_EEC1IS3_RA29_S0_vEEOT_OT0_
	addl	$12, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3651:
	.weak	__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IJRA29_S0_EvEEOS3_DpOT_
	.def	__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IJRA29_S0_EvEEOS3_DpOT_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IJRA29_S0_EvEEOS3_DpOT_,__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1IIRA29_S0_EvEEOS3_DpOT_
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIIS0_IjS3_EEEEPNS6_10_Hash_nodeIS4_Lb0EEEDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIIS0_IjS3_EEEEPNS6_10_Hash_nodeIS4_Lb0EEEDpOT_
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIIS0_IjS3_EEEEPNS6_10_Hash_nodeIS4_Lb0EEEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIIS0_IjS3_EEEEPNS6_10_Hash_nodeIS4_Lb0EEEDpOT_:
LFB3652:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3652
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	movl	$0, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
LEHB375:
	call	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE8allocateEjPKv
LEHE375:
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt4pairIjN6CTest84DATAEEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	movl	%ebx, 8(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB376:
	call	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE9constructIS8_IS3_IjS6_EEEEvPT_DpOT0_
LEHE376:
	movl	-12(%ebp), %eax
	jmp	L2057
L2056:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB377:
	call	__Unwind_Resume
LEHE377:
L2055:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	movl	$1, 8(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE10deallocateEPS8_j
LEHB378:
	call	___cxa_rethrow
LEHE378:
L2057:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3652:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA3652:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT3652-LLSDATTD3652
LLSDATTD3652:
	.byte	0x1
	.uleb128 LLSDACSE3652-LLSDACSB3652
LLSDACSB3652:
	.uleb128 LEHB375-LFB3652
	.uleb128 LEHE375-LEHB375
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB376-LFB3652
	.uleb128 LEHE376-LEHB376
	.uleb128 L2055-LFB3652
	.uleb128 0x1
	.uleb128 LEHB377-LFB3652
	.uleb128 LEHE377-LEHB377
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB378-LFB3652
	.uleb128 LEHE378-LEHB378
	.uleb128 L2056-LFB3652
	.uleb128 0
LLSDACSE3652:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT3652:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIIS0_IjS3_EEEEPNS6_10_Hash_nodeIS4_Lb0EEEDpOT_,"x"
	.linkonce discard
	.weak	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIJS0_IjS3_EEEEPNS6_10_Hash_nodeIS4_Lb0EEEDpOT_
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIJS0_IjS3_EEEEPNS6_10_Hash_nodeIS4_Lb0EEEDpOT_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIJS0_IjS3_EEEEPNS6_10_Hash_nodeIS4_Lb0EEEDpOT_,__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIIS0_IjS3_EEEEPNS6_10_Hash_nodeIS4_Lb0EEEDpOT_
	.section	.text$_ZNSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv
	.def	__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv;	.scl	2;	.type	32;	.endef
__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv:
LFB3653:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE6_S_getERS2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3653:
	.section	.text$_ZNKSt8__detail10_Select1stclIRSt4pairIKjN6CTest84DATAEEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS8_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail10_Select1stclIRSt4pairIKjN6CTest84DATAEEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS8_
	.def	__ZNKSt8__detail10_Select1stclIRSt4pairIKjN6CTest84DATAEEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS8_;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail10_Select1stclIRSt4pairIKjN6CTest84DATAEEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS8_:
LFB3654:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRSt4pairIKjN6CTest84DATAEEEOT_RNSt16remove_referenceIS6_E4typeE
	movl	%eax, (%esp)
	call	__ZSt3getILj0EKjN6CTest84DATAEERNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERS7_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3654:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS6_10_Hash_nodeIS4_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS6_10_Hash_nodeIS4_Lb0EEE
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS6_10_Hash_nodeIS4_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS6_10_Hash_nodeIS4_Lb0EEE:
LFB3655:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE7destroyIS8_EEvPT_
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	movl	$1, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE10deallocateEPS8_j
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3655:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEjjPNS6_10_Hash_nodeIS4_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEjjPNS6_10_Hash_nodeIS4_Lb0EEE
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEjjPNS6_10_Hash_nodeIS4_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEjjPNS6_10_Hash_nodeIS4_Lb0EEE:
LFB3656:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3656
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail20_Prime_rehash_policy8_M_stateEv
	movl	%eax, -20(%ebp)
	leal	-20(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	12(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	8(%ebp), %ecx
	addl	$16, %ecx
	movl	$1, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%ecx, (%esp)
LEHB379:
	call	__ZNKSt8__detail20_Prime_rehash_policy14_M_need_rehashEjjj
LEHE379:
	movl	%eax, -28(%ebp)
	movl	%edx, -24(%ebp)
	movzbl	-28(%ebp), %eax
	testb	%al, %al
	je	L2064
	movl	-24(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB380:
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEjRS1_
	movl	20(%ebp), %eax
	leal	4(%eax), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Select1stclIRSt4pairIKjN6CTest84DATAEEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS8_
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexERS1_j
	movl	%eax, 12(%ebp)
L2064:
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE13_M_store_codeEPNS_10_Hash_nodeIS5_Lb0EEEj
	movl	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE22_M_insert_bucket_beginEjPNS6_10_Hash_nodeIS4_Lb0EEE
LEHE380:
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 12(%eax)
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail14_Node_iteratorISt4pairIKjN6CTest84DATAEELb0ELb0EEC1EPNS_10_Hash_nodeIS5_Lb0EEE
	movl	-16(%ebp), %eax
	jmp	L2072
L2071:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	jmp	L2067
L2070:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS6_10_Hash_nodeIS4_Lb0EEE
LEHB381:
	call	___cxa_rethrow
LEHE381:
L2069:
L2067:
	movl	%eax, (%esp)
LEHB382:
	call	__Unwind_Resume
LEHE382:
L2072:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3656:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA3656:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT3656-LLSDATTD3656
LLSDATTD3656:
	.byte	0x1
	.uleb128 LLSDACSE3656-LLSDACSB3656
LLSDACSB3656:
	.uleb128 LEHB379-LFB3656
	.uleb128 LEHE379-LEHB379
	.uleb128 L2069-LFB3656
	.uleb128 0
	.uleb128 LEHB380-LFB3656
	.uleb128 LEHE380-LEHB380
	.uleb128 L2070-LFB3656
	.uleb128 0x1
	.uleb128 LEHB381-LFB3656
	.uleb128 LEHE381-LEHB381
	.uleb128 L2071-LFB3656
	.uleb128 0
	.uleb128 LEHB382-LFB3656
	.uleb128 LEHE382-LEHB382
	.uleb128 0
	.uleb128 0
LLSDACSE3656:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT3656:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEjjPNS6_10_Hash_nodeIS4_Lb0EEE,"x"
	.linkonce discard
	.section	.text$_ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h1Ev
	.def	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h1Ev;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h1Ev:
LFB3657:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EE7_S_cgetERKS3_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3657:
	.section	.text$_ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexERS2_jj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexERS2_jj
	.def	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexERS2_jj;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexERS2_jj:
LFB3658:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h2Ev
	movl	20(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt8__detail18_Mod_range_hashingclEjj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3658:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_find_before_nodeEjRS1_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_find_before_nodeEjRS1_j
	.def	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_find_before_nodeEjRS1_j;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_find_before_nodeEjRS1_j:
LFB3659:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L2078
	movl	$0, %eax
	jmp	L2079
L2078:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
L2086:
	movl	-16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_equalsERS2_jPNS_10_Hash_nodeIS5_Lb0EEE
	testb	%al, %al
	je	L2080
	movl	-12(%ebp), %eax
	jmp	L2079
L2080:
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L2081
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EE7_M_nextEv
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexEPNS6_10_Hash_nodeIS4_Lb0EEE
	cmpl	12(%ebp), %eax
	je	L2082
L2081:
	movl	$1, %eax
	jmp	L2083
L2082:
	movl	$0, %eax
L2083:
	testb	%al, %al
	je	L2084
	nop
	movl	$0, %eax
	jmp	L2079
L2084:
	movl	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EE7_M_nextEv
	movl	%eax, -16(%ebp)
	jmp	L2086
L2079:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3659:
	.section	.text$_ZNSt8__detail19_Node_iterator_baseISt4pairIKjN6CTest84DATAEELb0EEC2EPNS_10_Hash_nodeIS5_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail19_Node_iterator_baseISt4pairIKjN6CTest84DATAEELb0EEC2EPNS_10_Hash_nodeIS5_Lb0EEE
	.def	__ZNSt8__detail19_Node_iterator_baseISt4pairIKjN6CTest84DATAEELb0EEC2EPNS_10_Hash_nodeIS5_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt8__detail19_Node_iterator_baseISt4pairIKjN6CTest84DATAEELb0EEC2EPNS_10_Hash_nodeIS5_Lb0EEE:
LFB3661:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3661:
	.section	.text$_ZNSt8__detail15_Hashtable_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2ERKS6_RKSA_RKSB_RKSC_RKS8_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail15_Hashtable_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2ERKS6_RKSA_RKSB_RKSC_RKS8_
	.def	__ZNSt8__detail15_Hashtable_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2ERKS6_RKSA_RKSB_RKSC_RKS8_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail15_Hashtable_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2ERKS6_RKSA_RKSB_RKSC_RKS8_:
LFB3664:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	24(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EEC2ERKS6_RKS8_RKS9_RKSA_
	movl	28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EEC2ERKS2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3664:
	.section	.text$_ZSt7forwardIRKSaISt4pairIKjN6CTest84DATAEEEEOT_RNSt16remove_referenceIS8_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRKSaISt4pairIKjN6CTest84DATAEEEEOT_RNSt16remove_referenceIS8_E4typeE
	.def	__ZSt7forwardIRKSaISt4pairIKjN6CTest84DATAEEEEOT_RNSt16remove_referenceIS8_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRKSaISt4pairIKjN6CTest84DATAEEEEOT_RNSt16remove_referenceIS8_E4typeE:
LFB3667:
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
LFE3667:
	.section	.text$_ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEEC1IRKSaIS6_EEEOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEEC1IRKSaIS6_EEEOT_
	.def	__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEEC1IRKSaIS6_EEEOT_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEEC1IRKSaIS6_EEEOT_:
LFB3669:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKSaISt4pairIKjN6CTest84DATAEEEEOT_RNSt16remove_referenceIS8_E4typeE
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEC2IS5_EERKSaIT_E
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail15_Hash_node_baseC1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3669:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_allocate_bucketsEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_allocate_bucketsEj
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_allocate_bucketsEj;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_allocate_bucketsEj:
LFB3670:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3670
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	movl	%eax, 4(%esp)
	leal	-13(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIPNSt8__detail15_Hash_node_baseEEC1INS_10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEERKSaIT_E
	movl	$0, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-13(%ebp), %eax
	movl	%eax, (%esp)
LEHB383:
	call	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8allocateEjPKv
LEHE383:
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	_memset
	movl	-12(%ebp), %ebx
	leal	-13(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIPNSt8__detail15_Hash_node_baseEED1Ev
	movl	%ebx, %eax
	jmp	L2096
L2095:
	movl	%eax, %ebx
	leal	-13(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIPNSt8__detail15_Hash_node_baseEED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB384:
	call	__Unwind_Resume
LEHE384:
L2096:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3670:
	.section	.gcc_except_table,"w"
LLSDA3670:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3670-LLSDACSB3670
LLSDACSB3670:
	.uleb128 LEHB383-LFB3670
	.uleb128 LEHE383-LEHB383
	.uleb128 L2095-LFB3670
	.uleb128 0
	.uleb128 LEHB384-LFB3670
	.uleb128 LEHE384-LEHB384
	.uleb128 0
	.uleb128 0
LLSDACSE3670:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_allocate_bucketsEj,"x"
	.linkonce discard
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15__rehash_policyEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15__rehash_policyEv
	.def	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15__rehash_policyEv;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15__rehash_policyEv:
LFB3671:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	addl	$16, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3671:
	.section	.text$_ZSt3maxIjERKT_S2_S2_,"x"
	.linkonce discard
	.globl	__ZSt3maxIjERKT_S2_S2_
	.def	__ZSt3maxIjERKT_S2_S2_;	.scl	2;	.type	32;	.endef
__ZSt3maxIjERKT_S2_S2_:
LFB3672:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jae	L2100
	movl	12(%ebp), %eax
	jmp	L2101
L2100:
	movl	8(%ebp), %eax
L2101:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3672:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEjRS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEjRS1_
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEjRS1_;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEjRS1_:
LFB3673:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3673
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movb	%al, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB385:
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE13_M_rehash_auxEjSt17integral_constantIbLb1EE
LEHE385:
	jmp	L2107
L2105:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	addl	$16, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt8__detail20_Prime_rehash_policy8_M_resetEj
LEHB386:
	call	___cxa_rethrow
LEHE386:
L2106:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB387:
	call	__Unwind_Resume
LEHE387:
L2107:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3673:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA3673:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT3673-LLSDATTD3673
LLSDATTD3673:
	.byte	0x1
	.uleb128 LLSDACSE3673-LLSDACSB3673
LLSDACSB3673:
	.uleb128 LEHB385-LFB3673
	.uleb128 LEHE385-LEHB385
	.uleb128 L2105-LFB3673
	.uleb128 0x3
	.uleb128 LEHB386-LFB3673
	.uleb128 LEHE386-LEHB386
	.uleb128 L2106-LFB3673
	.uleb128 0
	.uleb128 LEHB387-LFB3673
	.uleb128 LEHE387-LEHB387
	.uleb128 0
	.uleb128 0
LLSDACSE3673:
	.byte	0x1
	.byte	0
	.byte	0
	.byte	0x7d
	.align 4
	.long	0
LLSDATT3673:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEjRS1_,"x"
	.linkonce discard
	.section	.text$_ZNKSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EE7_M_nextEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EE7_M_nextEv
	.def	__ZNKSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EE7_M_nextEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EE7_M_nextEv:
LFB3674:
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
LFE3674:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	.def	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv:
LFB3675:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	addl	$8, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3675:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEEC2Ev:
LFB3677:
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
LFE3677:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev:
LFB3680:
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
LFE3680:
	.section	.text$_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED2Ev
	.def	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED2Ev;	.scl	2;	.type	32;	.endef
__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED2Ev:
LFB3683:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	movl	$0, %eax
	testl	%eax, %eax
	je	L2115
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L2115:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3683:
	.section	.text$_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED1Ev
	.def	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED1Ev:
LFB3684:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	movl	$0, %eax
	testl	%eax, %eax
	je	L2118
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L2118:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3684:
	.section	.text$_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED0Ev
	.def	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED0Ev;	.scl	2;	.type	32;	.endef
__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED0Ev:
LFB3685:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3685:
	.section	.text$_ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC1Ev
	.def	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC1Ev:
LFB3688:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEC2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3688:
	.section	.text$_ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEED2Ev
	.def	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEED2Ev;	.scl	2;	.type	32;	.endef
__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEED2Ev:
LFB3690:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3690:
	.section	.text$_ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEED1Ev
	.def	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEED1Ev:
LFB3691:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3691:
	.section	.text$_ZSt15allocate_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_EIS8_EESt10shared_ptrIT_ERKT0_DpOT1_,"x"
	.linkonce discard
	.globl	__ZSt15allocate_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_EIS8_EESt10shared_ptrIT_ERKT0_DpOT1_
	.def	__ZSt15allocate_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_EIS8_EESt10shared_ptrIT_ERKT0_DpOT1_;	.scl	2;	.type	32;	.endef
__ZSt15allocate_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_EIS8_EESt10shared_ptrIT_ERKT0_DpOT1_:
LFB3692:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3692
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movb	%bl, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB388:
	call	__ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEC1ISaIS9_EIS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_
LEHE388:
	jmp	L2132
L2131:
	movl	%eax, (%esp)
LEHB389:
	call	__Unwind_Resume
LEHE389:
L2132:
	movl	8(%ebp), %eax
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE3692:
	.section	.gcc_except_table,"w"
LLSDA3692:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3692-LLSDACSB3692
LLSDACSB3692:
	.uleb128 LEHB388-LFB3692
	.uleb128 LEHE388-LEHB388
	.uleb128 L2131-LFB3692
	.uleb128 0
	.uleb128 LEHB389-LFB3692
	.uleb128 LEHE389-LEHB389
	.uleb128 0
	.uleb128 0
LLSDACSE3692:
	.section	.text$_ZSt15allocate_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_EIS8_EESt10shared_ptrIT_ERKT0_DpOT1_,"x"
	.linkonce discard
	.weak	__ZSt15allocate_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_EJS8_EESt10shared_ptrIT_ERKT0_DpOT1_
	.def	__ZSt15allocate_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_EJS8_EESt10shared_ptrIT_ERKT0_DpOT1_;	.scl	2;	.type	32;	.endef
	.set	__ZSt15allocate_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_EJS8_EESt10shared_ptrIT_ERKT0_DpOT1_,__ZSt15allocate_sharedINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_EIS8_EESt10shared_ptrIT_ERKT0_DpOT1_
	.section	.text$_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EE7_M_swapERS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EE7_M_swapERS2_
	.def	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EE7_M_swapERS2_;	.scl	2;	.type	32;	.endef
__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EE7_M_swapERS2_:
LFB3696:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3696:
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE8allocateEjPKv:
LFB3697:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE8max_sizeEv
	cmpl	12(%ebp), %eax
	setb	%al
	testb	%al, %al
	je	L2135
	call	__ZSt17__throw_bad_allocv
L2135:
	movl	12(%ebp), %eax
	sall	$5, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3697:
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE9constructIS8_IS3_IjS6_EEEEvPT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE9constructIS8_IS3_IjS6_EEEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE9constructIS8_IS3_IjS6_EEEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE9constructIS8_IS3_IjS6_EEEEvPT_DpOT0_:
LFB3698:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt4pairIjN6CTest84DATAEEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	__ZnwjPv
	testl	%eax, %eax
	je	L2137
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEC1IIS1_IjS4_EEEEDpOT_
L2137:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3698:
	.weak	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE9constructIS8_JS3_IjS6_EEEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE9constructIS8_JS3_IjS6_EEEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE9constructIS8_JS3_IjS6_EEEEvPT_DpOT0_,__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE9constructIS8_IS3_IjS6_EEEEvPT_DpOT0_
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE10deallocateEPS8_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE10deallocateEPS8_j
	.def	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE10deallocateEPS8_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE10deallocateEPS8_j:
LFB3699:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3699:
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE6_S_getERS2_,"x"
	.linkonce discard
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE6_S_getERS2_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE6_S_getERS2_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE6_S_getERS2_:
LFB3700:
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
LFE3700:
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE7destroyIS8_EEvPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE7destroyIS8_EEvPT_
	.def	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE7destroyIS8_EEvPT_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE7destroyIS8_EEvPT_:
LFB3701:
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
LFE3701:
	.section	.text$_ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE13_M_store_codeEPNS_10_Hash_nodeIS5_Lb0EEEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE13_M_store_codeEPNS_10_Hash_nodeIS5_Lb0EEEj
	.def	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE13_M_store_codeEPNS_10_Hash_nodeIS5_Lb0EEEj;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE13_M_store_codeEPNS_10_Hash_nodeIS5_Lb0EEEj:
LFB3702:
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
LFE3702:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE22_M_insert_bucket_beginEjPNS6_10_Hash_nodeIS4_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE22_M_insert_bucket_beginEjPNS6_10_Hash_nodeIS4_Lb0EEE
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE22_M_insert_bucket_beginEjPNS6_10_Hash_nodeIS4_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE22_M_insert_bucket_beginEjPNS6_10_Hash_nodeIS4_Lb0EEE:
LFB3703:
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
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L2146
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%eax)
	jmp	L2145
L2146:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	16(%ebp), %edx
	movl	%edx, (%eax)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L2148
	movl	8(%ebp), %eax
	movl	(%eax), %ebx
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EE7_M_nextEv
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexEPNS6_10_Hash_nodeIS4_Lb0EEE
	sall	$2, %eax
	leal	(%ebx,%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, (%edx)
L2148:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	sall	$2, %edx
	leal	(%eax,%edx), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	%eax, (%ebx)
L2145:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3703:
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EE7_S_cgetERKS3_,"x"
	.linkonce discard
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EE7_S_cgetERKS3_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EE7_S_cgetERKS3_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EE7_S_cgetERKS3_:
LFB3704:
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
LFE3704:
	.section	.text$_ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h2Ev
	.def	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h2Ev;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h2Ev:
LFB3705:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EE7_S_cgetERKS2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3705:
	.section	.text$_ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_equalsERS2_jPNS_10_Hash_nodeIS5_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_equalsERS2_jPNS_10_Hash_nodeIS5_Lb0EEE
	.def	__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_equalsERS2_jPNS_10_Hash_nodeIS5_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_equalsERS2_jPNS_10_Hash_nodeIS5_Lb0EEE:
LFB3706:
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
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE5_M_eqEv
	movl	20(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt8__detail13_Equal_helperIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjEjLb0EE9_S_equalsERKS8_RKS6_RS2_jPNS_10_Hash_nodeIS5_Lb0EEE
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3706:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexEPNS6_10_Hash_nodeIS4_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexEPNS6_10_Hash_nodeIS4_Lb0EEE
	.def	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexEPNS6_10_Hash_nodeIS4_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexEPNS6_10_Hash_nodeIS4_Lb0EEE:
LFB3707:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexEPKNS_10_Hash_nodeIS5_Lb0EEEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3707:
	.section	.text$_ZNSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EEC2ERKS6_RKS8_RKS9_RKSA_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EEC2ERKS6_RKS8_RKS9_RKSA_
	.def	__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EEC2ERKS6_RKS8_RKS9_RKSA_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EEC2ERKS6_RKS8_RKS9_RKSA_:
LFB3709:
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
	call	__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EEC2ERKS1_
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EEC2ERKS2_
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EEC2ERKS1_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3709:
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EEC2ERKS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EEC2ERKS2_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EEC2ERKS2_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EEC2ERKS2_:
LFB3712:
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
LFE3712:
	.section	.text$_ZNSaINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEC2IS5_EERKSaIT_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEC2IS5_EERKSaIT_E
	.def	__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEC2IS5_EERKSaIT_E;	.scl	2;	.type	32;	.endef
__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEC2IS5_EERKSaIT_E:
LFB3715:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEC2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3715:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8allocateEjPKv:
LFB3717:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8max_sizeEv
	cmpl	12(%ebp), %eax
	setb	%al
	testb	%al, %al
	je	L2161
	call	__ZSt17__throw_bad_allocv
L2161:
	movl	12(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3717:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE13_M_rehash_auxEjSt17integral_constantIbLb1EE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE13_M_rehash_auxEjSt17integral_constantIbLb1EE
	.def	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE13_M_rehash_auxEjSt17integral_constantIbLb1EE;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE13_M_rehash_auxEjSt17integral_constantIbLb1EE:
LFB3718:
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
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_allocate_bucketsEj
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE8_M_beginEv
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	$0, (%eax)
	movl	$0, -16(%ebp)
	jmp	L2164
L2168:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EE7_M_nextEv
	movl	%eax, -24(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexEPKNS_10_Hash_nodeIS5_Lb0EEEj
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L2165
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	movl	-28(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	leal	(%edx,%eax), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	%eax, (%ebx)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L2166
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%edx)
L2166:
	movl	-28(%ebp), %eax
	movl	%eax, -16(%ebp)
	jmp	L2167
L2165:
	movl	-28(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-28(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
L2167:
	movl	-24(%ebp), %eax
	movl	%eax, -12(%ebp)
L2164:
	cmpl	$0, -12(%ebp)
	jne	L2168
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjN6CTest84DATAEESaIS4_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS6_18_Mod_range_hashingENS6_20_Default_ranged_hashENS6_20_Prime_rehash_policyENS6_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEPPNS6_15_Hash_node_baseEj
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%eax)
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3718:
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEC2Ev:
LFB3720:
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
LFE3720:
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEED2Ev:
LFB3723:
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
LFE3723:
	.section	.text$_ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEC1ISaIS9_EIS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEC1ISaIS9_EIS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_
	.def	__ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEC1ISaIS9_EIS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEC1ISaIS9_EIS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_:
LFB3727:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE
	movl	8(%ebp), %edx
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movb	%bl, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt12__shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEELN9__gnu_cxx12_Lock_policyE2EEC2ISaIS9_EIS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3727:
	.weak	__ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEC1ISaIS9_EJS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_
	.def	__ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEC1ISaIS9_EJS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEC1ISaIS9_EJS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_,__ZNSt10shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEC1ISaIS9_EIS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_
	.section	.text$_ZNK9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEE8max_sizeEv:
LFB3728:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$134217727, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3728:
	.section	.text$_ZNSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEC1IIS1_IjS4_EEEEDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEC1IIS1_IjS4_EEEEDpOT_
	.def	__ZNSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEC1IIS1_IjS4_EEEEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEC1IIS1_IjS4_EEEEDpOT_:
LFB3731:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail15_Hash_node_baseC2Ev
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt4pairIjN6CTest84DATAEEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	8(%ebp), %edx
	addl	$4, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt4pairIKjN6CTest84DATAEEC1IjS2_vEEOS_IT_T0_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3731:
	.weak	__ZNSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEC1IJS1_IjS4_EEEEDpOT_
	.def	__ZNSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEC1IJS1_IjS4_EEEEDpOT_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEC1IJS1_IjS4_EEEEDpOT_,__ZNSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEC1IIS1_IjS4_EEEEDpOT_
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EE7_S_cgetERKS2_,"x"
	.linkonce discard
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EE7_S_cgetERKS2_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EE7_S_cgetERKS2_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EE7_S_cgetERKS2_:
LFB3732:
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
LFE3732:
	.section	.text$_ZNSt8__detail13_Equal_helperIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjEjLb0EE9_S_equalsERKS8_RKS6_RS2_jPNS_10_Hash_nodeIS5_Lb0EEE,"x"
	.linkonce discard
	.globl	__ZNSt8__detail13_Equal_helperIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjEjLb0EE9_S_equalsERKS8_RKS6_RS2_jPNS_10_Hash_nodeIS5_Lb0EEE
	.def	__ZNSt8__detail13_Equal_helperIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjEjLb0EE9_S_equalsERKS8_RKS6_RS2_jPNS_10_Hash_nodeIS5_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt8__detail13_Equal_helperIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjEjLb0EE9_S_equalsERKS8_RKS6_RS2_jPNS_10_Hash_nodeIS5_Lb0EEE:
LFB3733:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	24(%ebp), %eax
	addl	$4, %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Select1stclIRSt4pairIKjN6CTest84DATAEEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS8_
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8equal_toIjEclERKjS2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3733:
	.section	.text$_ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE5_M_eqEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE5_M_eqEv
	.def	__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE5_M_eqEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE5_M_eqEv:
LFB3734:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EE7_S_cgetERKS3_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3734:
	.section	.text$_ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv
	.def	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv:
LFB3735:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE7_S_cgetERKS2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3735:
	.section	.text$_ZSt7forwardIRKSt4pairIKjN6CTest84DATAEEEOT_RNSt16remove_referenceIS7_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRKSt4pairIKjN6CTest84DATAEEEOT_RNSt16remove_referenceIS7_E4typeE
	.def	__ZSt7forwardIRKSt4pairIKjN6CTest84DATAEEEOT_RNSt16remove_referenceIS7_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRKSt4pairIKjN6CTest84DATAEEEOT_RNSt16remove_referenceIS7_E4typeE:
LFB3737:
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
LFE3737:
	.section	.text$_ZNSt10__pair_getILj0EE11__const_getIKjN6CTest84DATAEEERKT_RKSt4pairIS5_T0_E,"x"
	.linkonce discard
	.globl	__ZNSt10__pair_getILj0EE11__const_getIKjN6CTest84DATAEEERKT_RKSt4pairIS5_T0_E
	.def	__ZNSt10__pair_getILj0EE11__const_getIKjN6CTest84DATAEEERKT_RKSt4pairIS5_T0_E;	.scl	2;	.type	32;	.endef
__ZNSt10__pair_getILj0EE11__const_getIKjN6CTest84DATAEEERKT_RKSt4pairIS5_T0_E:
LFB3739:
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
LFE3739:
	.section	.text$_ZSt3getILj0EKjN6CTest84DATAEERKNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERKS7_,"x"
	.linkonce discard
	.globl	__ZSt3getILj0EKjN6CTest84DATAEERKNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERKS7_
	.def	__ZSt3getILj0EKjN6CTest84DATAEERKNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERKS7_;	.scl	2;	.type	32;	.endef
__ZSt3getILj0EKjN6CTest84DATAEERKNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERKS7_:
LFB3738:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10__pair_getILj0EE11__const_getIKjN6CTest84DATAEEERKT_RKSt4pairIS5_T0_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3738:
	.section	.text$_ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexEPKNS_10_Hash_nodeIS5_Lb0EEEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexEPKNS_10_Hash_nodeIS5_Lb0EEEj
	.def	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexEPKNS_10_Hash_nodeIS5_Lb0EEEj;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexEPKNS_10_Hash_nodeIS5_Lb0EEEj:
LFB3736:
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
	leal	4(%eax), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Select1stclIRKSt4pairIKjN6CTest84DATAEEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS9_
	movl	(%eax), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h1Ev
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt4hashIjEclEj
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjN6CTest84DATAEENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h2Ev
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt8__detail18_Mod_range_hashingclEjj
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3736:
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EEC2ERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EEC2ERKS1_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EEC2ERKS1_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EEC2ERKS1_:
LFB3741:
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
LFE3741:
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EEC2ERKS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EEC2ERKS2_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EEC2ERKS2_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EEC2ERKS2_:
LFB3744:
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
LFE3744:
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EEC2ERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EEC2ERKS1_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EEC2ERKS1_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EEC2ERKS1_:
LFB3747:
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
LFE3747:
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjN6CTest84DATAEELb0EEEEC2Ev:
LFB3750:
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
LFE3750:
	.section	.text$_ZNK9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8max_sizeEv:
LFB3752:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$1073741823, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3752:
	.section	.text$_ZNSt12__shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEELN9__gnu_cxx12_Lock_policyE2EEC2ISaIS9_EIS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12__shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEELN9__gnu_cxx12_Lock_policyE2EEC2ISaIS9_EIS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_
	.def	__ZNSt12__shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEELN9__gnu_cxx12_Lock_policyE2EEC2ISaIS9_EIS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZNSt12__shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEELN9__gnu_cxx12_Lock_policyE2EEC2ISaIS9_EIS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_:
LFB3754:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE
	movl	8(%ebp), %edx
	addl	$4, %edx
	movl	%eax, 16(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$0, 8(%esp)
	movb	%bl, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC1INSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES8_EEEESaISD_EISC_EEESt19_Sp_make_shared_tagPT_RKT0_DpOT1_
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	$__ZTISt19_Sp_make_shared_tag, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %ecx
	addl	$4, %ecx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%ecx, (%esp)
	call	__ZSt32__enable_shared_from_this_helperILN9__gnu_cxx12_Lock_policyE2EEvRKSt14__shared_countIXT_EEz
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3754:
	.weak	__ZNSt12__shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEELN9__gnu_cxx12_Lock_policyE2EEC2ISaIS9_EJS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_
	.def	__ZNSt12__shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEELN9__gnu_cxx12_Lock_policyE2EEC2ISaIS9_EJS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt12__shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEELN9__gnu_cxx12_Lock_policyE2EEC2ISaIS9_EJS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_,__ZNSt12__shared_ptrINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEELN9__gnu_cxx12_Lock_policyE2EEC2ISaIS9_EIS8_EEESt19_Sp_make_shared_tagRKT_DpOT0_
	.section	.text$_ZNKSt8equal_toIjEclERKjS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8equal_toIjEclERKjS2_
	.def	__ZNKSt8equal_toIjEclERKjS2_;	.scl	2;	.type	32;	.endef
__ZNKSt8equal_toIjEclERKjS2_:
LFB3756:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	sete	%al
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3756:
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EE7_S_cgetERKS3_,"x"
	.linkonce discard
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EE7_S_cgetERKS3_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EE7_S_cgetERKS3_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EE7_S_cgetERKS3_:
LFB3757:
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
LFE3757:
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE7_S_cgetERKS2_,"x"
	.linkonce discard
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE7_S_cgetERKS2_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE7_S_cgetERKS2_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE7_S_cgetERKS2_:
LFB3758:
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
LFE3758:
	.section	.text$_ZNKSt8__detail10_Select1stclIRKSt4pairIKjN6CTest84DATAEEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS9_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail10_Select1stclIRKSt4pairIKjN6CTest84DATAEEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS9_
	.def	__ZNKSt8__detail10_Select1stclIRKSt4pairIKjN6CTest84DATAEEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS9_;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail10_Select1stclIRKSt4pairIKjN6CTest84DATAEEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS9_:
LFB3759:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKSt4pairIKjN6CTest84DATAEEEOT_RNSt16remove_referenceIS7_E4typeE
	movl	%eax, (%esp)
	call	__ZSt3getILj0EKjN6CTest84DATAEERKNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERKS7_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3759:
	.section	.text$_ZSt4moveIRKSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEEONSt16remove_referenceIT_E4typeEOSE_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRKSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEEONSt16remove_referenceIT_E4typeEOSE_
	.def	__ZSt4moveIRKSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEEONSt16remove_referenceIT_E4typeEOSE_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRKSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEEONSt16remove_referenceIT_E4typeEOSE_:
LFB3762:
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
LFE3762:
	.section	.text$_ZSt7forwardIKSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEEOT_RNSt16remove_referenceISC_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIKSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEEOT_RNSt16remove_referenceISC_E4typeE
	.def	__ZSt7forwardIKSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEEOT_RNSt16remove_referenceISC_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIKSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEEOT_RNSt16remove_referenceISC_E4typeE:
LFB3763:
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
LFE3763:
	.section	.text$_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC1INSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES8_EEEESaISD_EISC_EEESt19_Sp_make_shared_tagPT_RKT0_DpOT1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC1INSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES8_EEEESaISD_EISC_EEESt19_Sp_make_shared_tagPT_RKT0_DpOT1_
	.def	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC1INSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES8_EEEESaISD_EISC_EEESt19_Sp_make_shared_tagPT_RKT0_DpOT1_;	.scl	2;	.type	32;	.endef
__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC1INSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES8_EEEESaISD_EISC_EEESt19_Sp_make_shared_tagPT_RKT0_DpOT1_:
LFB3765:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3765
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-13(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEEC1IS9_EERKSaIT_E
	movl	$1, 4(%esp)
	leal	-13(%ebp), %eax
	movl	%eax, (%esp)
LEHB390:
	call	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE8allocateERSF_j
LEHE390:
	movl	%eax, -12(%ebp)
	movl	24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE
	movl	%eax, %ebx
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRKSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEEONSt16remove_referenceIT_E4typeEOSE_
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-13(%ebp), %eax
	movl	%eax, (%esp)
LEHB391:
	call	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE9constructISE_IKSB_S9_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSF_PT_DpOSJ_
LEHE391:
	movl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	leal	-13(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEED1Ev
	jmp	L2218
L2217:
	movl	%eax, %ebx
	call	___cxa_end_catch
	jmp	L2213
L2216:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	$1, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-13(%ebp), %eax
	movl	%eax, (%esp)
LEHB392:
	call	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE10deallocateERSF_PSE_j
	call	___cxa_rethrow
LEHE392:
L2215:
	movl	%eax, %ebx
L2213:
	leal	-13(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB393:
	call	__Unwind_Resume
LEHE393:
L2218:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3765:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA3765:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT3765-LLSDATTD3765
LLSDATTD3765:
	.byte	0x1
	.uleb128 LLSDACSE3765-LLSDACSB3765
LLSDACSB3765:
	.uleb128 LEHB390-LFB3765
	.uleb128 LEHE390-LEHB390
	.uleb128 L2215-LFB3765
	.uleb128 0
	.uleb128 LEHB391-LFB3765
	.uleb128 LEHE391-LEHB391
	.uleb128 L2216-LFB3765
	.uleb128 0x1
	.uleb128 LEHB392-LFB3765
	.uleb128 LEHE392-LEHB392
	.uleb128 L2217-LFB3765
	.uleb128 0
	.uleb128 LEHB393-LFB3765
	.uleb128 LEHE393-LEHB393
	.uleb128 0
	.uleb128 0
LLSDACSE3765:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT3765:
	.section	.text$_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC1INSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES8_EEEESaISD_EISC_EEESt19_Sp_make_shared_tagPT_RKT0_DpOT1_,"x"
	.linkonce discard
	.weak	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC1INSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES8_EEEESaISD_EJSC_EEESt19_Sp_make_shared_tagPT_RKT0_DpOT1_
	.def	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC1INSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES8_EEEESaISD_EJSC_EEESt19_Sp_make_shared_tagPT_RKT0_DpOT1_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC1INSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES8_EEEESaISD_EJSC_EEESt19_Sp_make_shared_tagPT_RKT0_DpOT1_,__ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC1INSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES8_EEEESaISD_EISC_EEESt19_Sp_make_shared_tagPT_RKT0_DpOT1_
	.section	.text$_ZNKSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info
	.def	__ZNKSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info;	.scl	2;	.type	32;	.endef
__ZNKSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info:
LFB3766:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3766
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L2220
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	12(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
	jmp	L2221
L2220:
	movl	$0, %eax
L2221:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3766:
	.section	.gcc_except_table,"w"
LLSDA3766:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3766-LLSDACSB3766
LLSDACSB3766:
LLSDACSE3766:
	.section	.text$_ZNKSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info,"x"
	.linkonce discard
	.section	.text$_ZSt32__enable_shared_from_this_helperILN9__gnu_cxx12_Lock_policyE2EEvRKSt14__shared_countIXT_EEz,"x"
	.linkonce discard
	.globl	__ZSt32__enable_shared_from_this_helperILN9__gnu_cxx12_Lock_policyE2EEvRKSt14__shared_countIXT_EEz
	.def	__ZSt32__enable_shared_from_this_helperILN9__gnu_cxx12_Lock_policyE2EEvRKSt14__shared_countIXT_EEz;	.scl	2;	.type	32;	.endef
__ZSt32__enable_shared_from_this_helperILN9__gnu_cxx12_Lock_policyE2EEvRKSt14__shared_countIXT_EEz:
LFB3767:
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
LFE3767:
	.section	.text$_ZNSaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEEC1IS9_EERKSaIT_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEEC1IS9_EERKSaIT_E
	.def	__ZNSaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEEC1IS9_EERKSaIT_E;	.scl	2;	.type	32;	.endef
__ZNSaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEEC1IS9_EERKSaIT_E:
LFB3770:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEEC2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3770:
	.section	.text$_ZNSaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEED1Ev
	.def	__ZNSaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEED1Ev:
LFB3773:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3773:
	.section	.text$_ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE8allocateERSF_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE8allocateERSF_j
	.def	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE8allocateERSF_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE8allocateERSF_j:
LFB3774:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$0, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE8allocateEjPKv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3774:
	.section	.text$_ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE9constructISE_IKSB_S9_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSF_PT_DpOSJ_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE9constructISE_IKSB_S9_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSF_PT_DpOSJ_
	.def	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE9constructISE_IKSB_S9_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSF_PT_DpOSJ_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE9constructISE_IKSB_S9_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSF_PT_DpOSJ_:
LFB3775:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIKSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEEOT_RNSt16remove_referenceISC_E4typeE
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE12_S_constructISE_IKSB_S9_EEENSt9enable_ifIXsrNSG_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERSF_PSL_DpOSM_
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3775:
	.weak	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE9constructISE_JKSB_S9_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSF_PT_DpOSJ_
	.def	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE9constructISE_JKSB_S9_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSF_PT_DpOSJ_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE9constructISE_JKSB_S9_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSF_PT_DpOSJ_,__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE9constructISE_IKSB_S9_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSF_PT_DpOSJ_
	.section	.text$_ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE10deallocateERSF_PSE_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE10deallocateERSF_PSE_j
	.def	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE10deallocateERSF_PSE_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE10deallocateERSF_PSE_j:
LFB3776:
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
	call	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE10deallocateEPSE_j
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3776:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEEC2Ev:
LFB3778:
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
LFE3778:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEED2Ev:
LFB3781:
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
LFE3781:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE8allocateEjPKv:
LFB3783:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE8max_sizeEv
	cmpl	12(%ebp), %eax
	setb	%al
	testb	%al, %al
	je	L2235
	call	__ZSt17__throw_bad_allocv
L2235:
	movl	12(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3783:
	.section	.text$_ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE12_S_constructISE_IKSB_S9_EEENSt9enable_ifIXsrNSG_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERSF_PSL_DpOSM_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE12_S_constructISE_IKSB_S9_EEENSt9enable_ifIXsrNSG_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERSF_PSL_DpOSM_
	.def	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE12_S_constructISE_IKSB_S9_EEENSt9enable_ifIXsrNSG_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERSF_PSL_DpOSM_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE12_S_constructISE_IKSB_S9_EEENSt9enable_ifIXsrNSG_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERSF_PSL_DpOSM_:
LFB3784:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIKSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEEOT_RNSt16remove_referenceISC_E4typeE
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE9constructISE_IKSC_SA_EEEvPT_DpOT0_
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3784:
	.weak	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE12_S_constructISE_JKSB_S9_EEENSt9enable_ifIXsrNSG_18__construct_helperIT_JDpT0_EEE5valueEvE4typeERSF_PSL_DpOSM_
	.def	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE12_S_constructISE_JKSB_S9_EEENSt9enable_ifIXsrNSG_18__construct_helperIT_JDpT0_EEE5valueEvE4typeERSF_PSL_DpOSM_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE12_S_constructISE_JKSB_S9_EEENSt9enable_ifIXsrNSG_18__construct_helperIT_JDpT0_EEE5valueEvE4typeERSF_PSL_DpOSM_,__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE12_S_constructISE_IKSB_S9_EEENSt9enable_ifIXsrNSG_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERSF_PSL_DpOSM_
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE10deallocateEPSE_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE10deallocateEPSE_j
	.def	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE10deallocateEPSE_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE10deallocateEPSE_j:
LFB3785:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3785:
	.section	.text$_ZNK9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE8max_sizeEv:
LFB3786:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$119304647, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3786:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE9constructISE_IKSC_SA_EEEvPT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE9constructISE_IKSC_SA_EEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE9constructISE_IKSC_SA_EEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE9constructISE_IKSC_SA_EEEvPT_DpOT0_:
LFB3787:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3787
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIKSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEEOT_RNSt16remove_referenceISC_E4typeE
	movl	%eax, 4(%esp)
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC1ERKS9_
	leal	-25(%ebp), %eax
	movl	%eax, -44(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE
	movl	%eax, %edi
	movl	12(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	$36, (%esp)
	call	__ZnwjPv
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L2243
	movl	%edi, 8(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
LEHB394:
	call	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEC1IIS8_EEESA_DpOT_
LEHE394:
L2243:
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEED1Ev
	jmp	L2246
L2245:
	movl	%eax, %edi
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvS_
	movl	%edi, %ebx
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB395:
	call	__Unwind_Resume
LEHE395:
L2246:
	addl	$44, %esp
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
LFE3787:
	.section	.gcc_except_table,"w"
LLSDA3787:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3787-LLSDACSB3787
LLSDACSB3787:
	.uleb128 LEHB394-LFB3787
	.uleb128 LEHE394-LEHB394
	.uleb128 L2245-LFB3787
	.uleb128 0
	.uleb128 LEHB395-LFB3787
	.uleb128 LEHE395-LEHB395
	.uleb128 0
	.uleb128 0
LLSDACSE3787:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE9constructISE_IKSC_SA_EEEvPT_DpOT0_,"x"
	.linkonce discard
	.weak	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE9constructISE_JKSC_SA_EEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE9constructISE_JKSC_SA_EEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE9constructISE_JKSC_SA_EEEvPT_DpOT0_,__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE9constructISE_IKSC_SA_EEEvPT_DpOT0_
	.section	.text$_ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC2ERKS9_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC2ERKS9_
	.def	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC2ERKS9_;	.scl	2;	.type	32;	.endef
__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC2ERKS9_:
LFB3789:
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
	call	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEC2ERKSB_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3789:
	.section	.text$_ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC1ERKS9_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC1ERKS9_
	.def	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC1ERKS9_;	.scl	2;	.type	32;	.endef
__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC1ERKS9_:
LFB3790:
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
	call	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEC2ERKSB_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3790:
	.section	.text$_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE5_ImplD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE5_ImplD1Ev
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE5_ImplD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE5_ImplD1Ev:
LFB3794:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3794:
	.section	.text$_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEC1IIS8_EEESA_DpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEC1IIS8_EEESA_DpOT_
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEC1IIS8_EEESA_DpOT_;	.scl	2;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEC1IIS8_EEESA_DpOT_:
LFB3796:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3796
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EEC2Ev
	movl	8(%ebp), %eax
	movl	$__ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC1ERKS9_
	movl	8(%ebp), %eax
	leal	12(%eax), %edx
	leal	-9(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE5_ImplC1ESA_
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEED1Ev
	movl	8(%ebp), %eax
	movl	$0, 16(%eax)
	movl	$0, 20(%eax)
	movl	$0, 24(%eax)
	movl	$0, 28(%eax)
	movl	$0, 32(%eax)
	movl	8(%ebp), %eax
	leal	16(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 12(%eax)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE
	movl	8(%ebp), %edx
	movl	12(%edx), %edx
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
LEHB396:
	call	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE9constructIS9_IS8_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSA_PT_DpOSD_
LEHE396:
	jmp	L2254
L2253:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE5_ImplD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB397:
	call	__Unwind_Resume
LEHE397:
L2254:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3796:
	.section	.gcc_except_table,"w"
LLSDA3796:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3796-LLSDACSB3796
LLSDACSB3796:
	.uleb128 LEHB396-LFB3796
	.uleb128 LEHE396-LEHB396
	.uleb128 L2253-LFB3796
	.uleb128 0
	.uleb128 LEHB397-LFB3796
	.uleb128 LEHE397-LEHB397
	.uleb128 0
	.uleb128 0
LLSDACSE3796:
	.section	.text$_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEC1IIS8_EEESA_DpOT_,"x"
	.linkonce discard
	.weak	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEC1IJS8_EEESA_DpOT_
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEC1IJS8_EEESA_DpOT_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEC1IJS8_EEESA_DpOT_,__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEC1IIS8_EEESA_DpOT_
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEC2ERKSB_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEC2ERKSB_
	.def	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEC2ERKSB_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEEC2ERKSB_:
LFB3798:
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
LFE3798:
	.section	.text$_ZNSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EEC2Ev
	.def	__ZNSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EEC2Ev:
LFB3802:
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
LFE3802:
	.section	.text$_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EEC2Ev
	.def	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EEC2Ev:
LFB3804:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EEC2Ev
	movl	8(%ebp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	movl	8(%ebp), %eax
	movl	$1, 4(%eax)
	movl	8(%ebp), %eax
	movl	$1, 8(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3804:
	.section	.text$_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE5_ImplC1ESA_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE5_ImplC1ESA_
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE5_ImplC1ESA_;	.scl	2;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE5_ImplC1ESA_:
LFB3808:
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
	call	__ZNSaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEEEC2ERKS9_
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3808:
	.section	.text$_ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE9constructIS9_IS8_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSA_PT_DpOSD_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE9constructIS9_IS8_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSA_PT_DpOSD_
	.def	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE9constructIS9_IS8_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSA_PT_DpOSD_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE9constructIS9_IS8_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSA_PT_DpOSD_:
LFB3809:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE12_S_constructIS9_IS8_EEENSt9enable_ifIXsrNSB_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERSA_PSF_DpOSG_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3809:
	.weak	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE9constructIS9_JS8_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSA_PT_DpOSD_
	.def	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE9constructIS9_JS8_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSA_PT_DpOSD_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE9constructIS9_JS8_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSA_PT_DpOSD_,__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE9constructIS9_IS8_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERSA_PT_DpOSD_
	.section	.text$_ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE12_S_constructIS9_IS8_EEENSt9enable_ifIXsrNSB_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERSA_PSF_DpOSG_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE12_S_constructIS9_IS8_EEENSt9enable_ifIXsrNSB_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERSA_PSF_DpOSG_
	.def	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE12_S_constructIS9_IS8_EEENSt9enable_ifIXsrNSB_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERSA_PSF_DpOSG_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE12_S_constructIS9_IS8_EEENSt9enable_ifIXsrNSB_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERSA_PSF_DpOSG_:
LFB3810:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEE9constructISA_IS9_EEEvPT_DpOT0_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3810:
	.weak	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE12_S_constructIS9_JS8_EEENSt9enable_ifIXsrNSB_18__construct_helperIT_JDpT0_EEE5valueEvE4typeERSA_PSF_DpOSG_
	.def	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE12_S_constructIS9_JS8_EEENSt9enable_ifIXsrNSB_18__construct_helperIT_JDpT0_EEE5valueEvE4typeERSA_PSF_DpOSG_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE12_S_constructIS9_JS8_EEENSt9enable_ifIXsrNSB_18__construct_helperIT_JDpT0_EEE5valueEvE4typeERSA_PSF_DpOSG_,__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE12_S_constructIS9_IS8_EEENSt9enable_ifIXsrNSB_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERSA_PSF_DpOSG_
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEE9constructISA_IS9_EEEvPT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEE9constructISA_IS9_EEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEE9constructISA_IS9_EEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEE9constructISA_IS9_EEEvPT_DpOT0_:
LFB3811:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$20, (%esp)
	call	__ZnwjPv
	testl	%eax, %eax
	je	L2261
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEC1EOS7_
L2261:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3811:
	.weak	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEE9constructISA_JS9_EEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEE9constructISA_JS9_EEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEE9constructISA_JS9_EEEvPT_DpOT0_,__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEE9constructISA_IS9_EEEvPT_DpOT0_
	.section	.text$_ZNSt6thread10_Impl_baseC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6thread10_Impl_baseC2Ev
	.def	__ZNSt6thread10_Impl_baseC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt6thread10_Impl_baseC2Ev:
LFB3820:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	$__ZTVNSt6thread10_Impl_baseE+8, (%eax)
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	8(%ebp), %eax
	movl	$0, 8(%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3820:
	.section	.text$_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEC1EOS7_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEC1EOS7_
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEC1EOS7_;	.scl	2;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEC1EOS7_:
LFB3823:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread10_Impl_baseC2Ev
	movl	8(%ebp), %eax
	movl	$__ZTVNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEE+8, (%eax)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt12_Bind_simpleIFPFvPKcES2_EEEOT_RNSt16remove_referenceIS7_E4typeE
	movl	8(%ebp), %edx
	addl	$12, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt12_Bind_simpleIFPFvPKcES1_EEC1EOS5_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3823:
	.globl	__ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE
	.section	.rdata$_ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE,"dr"
	.linkonce same_size
	.align 8
__ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE:
	.long	0
	.long	__ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EED1Ev
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EED0Ev
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info
	.globl	__ZTVNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEE
	.section	.rdata$_ZTVNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEE,"dr"
	.linkonce same_size
	.align 8
__ZTVNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEE:
	.long	0
	.long	__ZTINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEE
	.long	__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEED1Ev
	.long	__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEED0Ev
	.long	__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEE6_M_runEv
	.section	.text$_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEED1Ev
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEED1Ev:
LFB3826:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTVNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEE+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread10_Impl_baseD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L2266
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L2266:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3826:
	.section	.text$_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEED0Ev
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEED0Ev;	.scl	2;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEED0Ev:
LFB3827:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEED1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3827:
	.globl	__ZTV28CSmartStackAllocatorWithBuffILj128EE
	.section	.rdata$_ZTV28CSmartStackAllocatorWithBuffILj128EE,"dr"
	.linkonce same_size
	.align 32
__ZTV28CSmartStackAllocatorWithBuffILj128EE:
	.long	0
	.long	__ZTI28CSmartStackAllocatorWithBuffILj128EE
	.long	__ZNK20CSmartStackAllocator8getTotalEv
	.long	__ZNK20CSmartStackAllocator7getUsedEv
	.long	__ZNK20CSmartStackAllocator9getRemainEv
	.long	__ZNK20CSmartStackAllocator9getNowPtrEv
	.long	__ZNK20CSmartStackAllocator9getMarkerEv
	.long	__ZN20CSmartStackAllocator5allocEjj
	.long	__ZN20CSmartStackAllocator4backEj
	.long	__ZN20CSmartStackAllocator4backEPKv
	.long	__ZN20CSmartStackAllocator5clearEv
	.long	__ZN20CSmartStackAllocator8clearAllEv
	.long	__ZN28CSmartStackAllocatorWithBuffILj128EED1Ev
	.long	__ZN28CSmartStackAllocatorWithBuffILj128EED0Ev
	.globl	__ZTV28CSmartStackAllocatorWithBuffILj1024EE
	.section	.rdata$_ZTV28CSmartStackAllocatorWithBuffILj1024EE,"dr"
	.linkonce same_size
	.align 32
__ZTV28CSmartStackAllocatorWithBuffILj1024EE:
	.long	0
	.long	__ZTI28CSmartStackAllocatorWithBuffILj1024EE
	.long	__ZNK20CSmartStackAllocator8getTotalEv
	.long	__ZNK20CSmartStackAllocator7getUsedEv
	.long	__ZNK20CSmartStackAllocator9getRemainEv
	.long	__ZNK20CSmartStackAllocator9getNowPtrEv
	.long	__ZNK20CSmartStackAllocator9getMarkerEv
	.long	__ZN20CSmartStackAllocator5allocEjj
	.long	__ZN20CSmartStackAllocator4backEj
	.long	__ZN20CSmartStackAllocator4backEPKv
	.long	__ZN20CSmartStackAllocator5clearEv
	.long	__ZN20CSmartStackAllocator8clearAllEv
	.long	__ZN28CSmartStackAllocatorWithBuffILj1024EED1Ev
	.long	__ZN28CSmartStackAllocatorWithBuffILj1024EED0Ev
	.globl	__ZTV6CTest9
	.section	.rdata$_ZTV6CTest9,"dr"
	.linkonce same_size
	.align 8
__ZTV6CTest9:
	.long	0
	.long	__ZTI6CTest9
	.long	__ZN6CTest9D1Ev
	.long	__ZN6CTest9D0Ev
	.globl	__ZTV19CSmartStackAllocAdp
	.section	.rdata$_ZTV19CSmartStackAllocAdp,"dr"
	.linkonce same_size
	.align 32
__ZTV19CSmartStackAllocAdp:
	.long	0
	.long	__ZTI19CSmartStackAllocAdp
	.long	__ZNK19CSmartStackAllocAdp7getNameEv
	.long	__ZNK15CIStackAllocAdp8getTotalEv
	.long	__ZNK15CIStackAllocAdp7getUsedEv
	.long	__ZNK15CIStackAllocAdp9getRemainEv
	.long	__ZN19CSmartStackAllocAdp5allocEjjPK10ALLOC_INFO
	.long	__ZN19CSmartStackAllocAdp4freeEPv
	.long	__ZN19CSmartStackAllocAdpD1Ev
	.long	__ZN19CSmartStackAllocAdpD0Ev
	.globl	__ZTV20CSmartStackAllocator
	.section	.rdata$_ZTV20CSmartStackAllocator,"dr"
	.linkonce same_size
	.align 32
__ZTV20CSmartStackAllocator:
	.long	0
	.long	__ZTI20CSmartStackAllocator
	.long	__ZNK20CSmartStackAllocator8getTotalEv
	.long	__ZNK20CSmartStackAllocator7getUsedEv
	.long	__ZNK20CSmartStackAllocator9getRemainEv
	.long	__ZNK20CSmartStackAllocator9getNowPtrEv
	.long	__ZNK20CSmartStackAllocator9getMarkerEv
	.long	__ZN20CSmartStackAllocator5allocEjj
	.long	__ZN20CSmartStackAllocator4backEj
	.long	__ZN20CSmartStackAllocator4backEPKv
	.long	__ZN20CSmartStackAllocator5clearEv
	.long	__ZN20CSmartStackAllocator8clearAllEv
	.long	__ZN20CSmartStackAllocatorD1Ev
	.long	__ZN20CSmartStackAllocatorD0Ev
	.globl	__ZTVNSt6thread10_Impl_baseE
	.section	.rdata$_ZTVNSt6thread10_Impl_baseE,"dr"
	.linkonce same_size
	.align 8
__ZTVNSt6thread10_Impl_baseE:
	.long	0
	.long	__ZTINSt6thread10_Impl_baseE
	.long	__ZNSt6thread10_Impl_baseD1Ev
	.long	__ZNSt6thread10_Impl_baseD0Ev
	.long	___cxa_pure_virtual
	.globl	__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.section	.rdata$_ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE,"dr"
	.linkonce same_size
	.align 8
__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE:
	.long	0
	.long	__ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.long	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED1Ev
	.long	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED0Ev
	.long	___cxa_pure_virtual
	.long	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv
	.long	___cxa_pure_virtual
	.globl	__ZTV23CStackAllocatorWithBuffILj8192EE
	.section	.rdata$_ZTV23CStackAllocatorWithBuffILj8192EE,"dr"
	.linkonce same_size
	.align 32
__ZTV23CStackAllocatorWithBuffILj8192EE:
	.long	0
	.long	__ZTI23CStackAllocatorWithBuffILj8192EE
	.long	__ZNK15CStackAllocator8getTotalEv
	.long	__ZNK15CStackAllocator7getUsedEv
	.long	__ZNK15CStackAllocator9getRemainEv
	.long	__ZNK15CStackAllocator9getNowPtrEv
	.long	__ZNK15CStackAllocator9getMarkerEv
	.long	__ZN15CStackAllocator5allocEjj
	.long	__ZN15CStackAllocator4backEj
	.long	__ZN15CStackAllocator4backEPKv
	.long	__ZN15CStackAllocator5clearEv
	.long	__ZN15CStackAllocator8clearAllEv
	.long	__ZN23CStackAllocatorWithBuffILj8192EED1Ev
	.long	__ZN23CStackAllocatorWithBuffILj8192EED0Ev
	.globl	__ZTV23CStackAllocatorWithBuffILj1024EE
	.section	.rdata$_ZTV23CStackAllocatorWithBuffILj1024EE,"dr"
	.linkonce same_size
	.align 32
__ZTV23CStackAllocatorWithBuffILj1024EE:
	.long	0
	.long	__ZTI23CStackAllocatorWithBuffILj1024EE
	.long	__ZNK15CStackAllocator8getTotalEv
	.long	__ZNK15CStackAllocator7getUsedEv
	.long	__ZNK15CStackAllocator9getRemainEv
	.long	__ZNK15CStackAllocator9getNowPtrEv
	.long	__ZNK15CStackAllocator9getMarkerEv
	.long	__ZN15CStackAllocator5allocEjj
	.long	__ZN15CStackAllocator4backEj
	.long	__ZN15CStackAllocator4backEPKv
	.long	__ZN15CStackAllocator5clearEv
	.long	__ZN15CStackAllocator8clearAllEv
	.long	__ZN23CStackAllocatorWithBuffILj1024EED1Ev
	.long	__ZN23CStackAllocatorWithBuffILj1024EED0Ev
	.globl	__ZTV13CDerivedTest7
	.section	.rdata$_ZTV13CDerivedTest7,"dr"
	.linkonce same_size
	.align 32
__ZTV13CDerivedTest7:
	.long	0
	.long	__ZTI13CDerivedTest7
	.long	__ZN13CDerivedTest7D1Ev
	.long	__ZN13CDerivedTest7D0Ev
	.long	-12
	.long	__ZTI13CDerivedTest7
	.long	__ZThn12_N13CDerivedTest7D1Ev
	.long	__ZThn12_N13CDerivedTest7D0Ev
	.globl	__ZTV8CTest7ex
	.section	.rdata$_ZTV8CTest7ex,"dr"
	.linkonce same_size
	.align 8
__ZTV8CTest7ex:
	.long	0
	.long	__ZTI8CTest7ex
	.long	__ZN8CTest7exD1Ev
	.long	__ZN8CTest7exD0Ev
	.globl	__ZTV6CTest7
	.section	.rdata$_ZTV6CTest7,"dr"
	.linkonce same_size
	.align 8
__ZTV6CTest7:
	.long	0
	.long	__ZTI6CTest7
	.long	__ZN6CTest7D1Ev
	.long	__ZN6CTest7D0Ev
	.globl	__ZTV27CDualStackAllocatorWithBuffILj128EE
	.section	.rdata$_ZTV27CDualStackAllocatorWithBuffILj128EE,"dr"
	.linkonce same_size
	.align 32
__ZTV27CDualStackAllocatorWithBuffILj128EE:
	.long	0
	.long	__ZTI27CDualStackAllocatorWithBuffILj128EE
	.long	__ZNK19CDualStackAllocator8getTotalEv
	.long	__ZNK19CDualStackAllocator7getUsedEv
	.long	__ZNK19CDualStackAllocator9getRemainEv
	.long	__ZNK19CDualStackAllocator9getNowPtrEv
	.long	__ZNK19CDualStackAllocator9getMarkerEv
	.long	__ZN19CDualStackAllocator5allocEjj
	.long	__ZN19CDualStackAllocator4backEj
	.long	__ZN19CDualStackAllocator4backEPKv
	.long	__ZN19CDualStackAllocator5clearEv
	.long	__ZN19CDualStackAllocator8clearAllEv
	.long	__ZN27CDualStackAllocatorWithBuffILj128EED1Ev
	.long	__ZN27CDualStackAllocatorWithBuffILj128EED0Ev
	.globl	__ZTV23CStackAllocatorWithBuffILj128EE
	.section	.rdata$_ZTV23CStackAllocatorWithBuffILj128EE,"dr"
	.linkonce same_size
	.align 32
__ZTV23CStackAllocatorWithBuffILj128EE:
	.long	0
	.long	__ZTI23CStackAllocatorWithBuffILj128EE
	.long	__ZNK15CStackAllocator8getTotalEv
	.long	__ZNK15CStackAllocator7getUsedEv
	.long	__ZNK15CStackAllocator9getRemainEv
	.long	__ZNK15CStackAllocator9getNowPtrEv
	.long	__ZNK15CStackAllocator9getMarkerEv
	.long	__ZN15CStackAllocator5allocEjj
	.long	__ZN15CStackAllocator4backEj
	.long	__ZN15CStackAllocator4backEPKv
	.long	__ZN15CStackAllocator5clearEv
	.long	__ZN15CStackAllocator8clearAllEv
	.long	__ZN23CStackAllocatorWithBuffILj128EED1Ev
	.long	__ZN23CStackAllocatorWithBuffILj128EED0Ev
	.globl	__ZTV21CMonoAllocAdpWithBuffILj128EE
	.section	.rdata$_ZTV21CMonoAllocAdpWithBuffILj128EE,"dr"
	.linkonce same_size
	.align 32
__ZTV21CMonoAllocAdpWithBuffILj128EE:
	.long	0
	.long	__ZTI21CMonoAllocAdpWithBuffILj128EE
	.long	__ZNK13CMonoAllocAdp7getNameEv
	.long	__ZNK13CMonoAllocAdp8getTotalEv
	.long	__ZNK13CMonoAllocAdp7getUsedEv
	.long	__ZNK13CMonoAllocAdp9getRemainEv
	.long	__ZN13CMonoAllocAdp5allocEjjPK10ALLOC_INFO
	.long	__ZN13CMonoAllocAdp4freeEPv
	.long	__ZN21CMonoAllocAdpWithBuffILj128EED1Ev
	.long	__ZN21CMonoAllocAdpWithBuffILj128EED0Ev
	.globl	__ZTV13CDerivedTest6
	.section	.rdata$_ZTV13CDerivedTest6,"dr"
	.linkonce same_size
	.align 32
__ZTV13CDerivedTest6:
	.long	0
	.long	__ZTI13CDerivedTest6
	.long	__ZN13CDerivedTest6D1Ev
	.long	__ZN13CDerivedTest6D0Ev
	.long	-12
	.long	__ZTI13CDerivedTest6
	.long	__ZThn12_N13CDerivedTest6D1Ev
	.long	__ZThn12_N13CDerivedTest6D0Ev
	.globl	__ZTV8CTest6ex
	.section	.rdata$_ZTV8CTest6ex,"dr"
	.linkonce same_size
	.align 8
__ZTV8CTest6ex:
	.long	0
	.long	__ZTI8CTest6ex
	.long	__ZN8CTest6exD1Ev
	.long	__ZN8CTest6exD0Ev
	.globl	__ZTV6CTest6
	.section	.rdata$_ZTV6CTest6,"dr"
	.linkonce same_size
	.align 8
__ZTV6CTest6:
	.long	0
	.long	__ZTI6CTest6
	.long	__ZN6CTest6D1Ev
	.long	__ZN6CTest6D0Ev
	.globl	__ZTV13CPoolAllocAdp
	.section	.rdata$_ZTV13CPoolAllocAdp,"dr"
	.linkonce same_size
	.align 32
__ZTV13CPoolAllocAdp:
	.long	0
	.long	__ZTI13CPoolAllocAdp
	.long	__ZNK13CPoolAllocAdp7getNameEv
	.long	__ZNK13CPoolAllocAdp8getTotalEv
	.long	__ZNK13CPoolAllocAdp7getUsedEv
	.long	__ZNK13CPoolAllocAdp9getRemainEv
	.long	__ZN13CPoolAllocAdp5allocEjjPK10ALLOC_INFO
	.long	__ZN13CPoolAllocAdp4freeEPv
	.long	__ZN13CPoolAllocAdpD1Ev
	.long	__ZN13CPoolAllocAdpD0Ev
	.globl	__ZTV18CDualStackAllocAdp
	.section	.rdata$_ZTV18CDualStackAllocAdp,"dr"
	.linkonce same_size
	.align 32
__ZTV18CDualStackAllocAdp:
	.long	0
	.long	__ZTI18CDualStackAllocAdp
	.long	__ZNK18CDualStackAllocAdp7getNameEv
	.long	__ZNK15CIStackAllocAdp8getTotalEv
	.long	__ZNK15CIStackAllocAdp7getUsedEv
	.long	__ZNK15CIStackAllocAdp9getRemainEv
	.long	__ZN18CDualStackAllocAdp5allocEjjPK10ALLOC_INFO
	.long	__ZN18CDualStackAllocAdp4freeEPv
	.long	__ZN18CDualStackAllocAdpD1Ev
	.long	__ZN18CDualStackAllocAdpD0Ev
	.globl	__ZTV14CStackAllocAdp
	.section	.rdata$_ZTV14CStackAllocAdp,"dr"
	.linkonce same_size
	.align 32
__ZTV14CStackAllocAdp:
	.long	0
	.long	__ZTI14CStackAllocAdp
	.long	__ZNK14CStackAllocAdp7getNameEv
	.long	__ZNK15CIStackAllocAdp8getTotalEv
	.long	__ZNK15CIStackAllocAdp7getUsedEv
	.long	__ZNK15CIStackAllocAdp9getRemainEv
	.long	__ZN14CStackAllocAdp5allocEjjPK10ALLOC_INFO
	.long	__ZN14CStackAllocAdp4freeEPv
	.long	__ZN14CStackAllocAdpD1Ev
	.long	__ZN14CStackAllocAdpD0Ev
	.globl	__ZTV15CIStackAllocAdp
	.section	.rdata$_ZTV15CIStackAllocAdp,"dr"
	.linkonce same_size
	.align 32
__ZTV15CIStackAllocAdp:
	.long	0
	.long	__ZTI15CIStackAllocAdp
	.long	__ZNK15CIStackAllocAdp7getNameEv
	.long	__ZNK15CIStackAllocAdp8getTotalEv
	.long	__ZNK15CIStackAllocAdp7getUsedEv
	.long	__ZNK15CIStackAllocAdp9getRemainEv
	.long	__ZN15CIStackAllocAdp5allocEjjPK10ALLOC_INFO
	.long	__ZN15CIStackAllocAdp4freeEPv
	.long	__ZN15CIStackAllocAdpD1Ev
	.long	__ZN15CIStackAllocAdpD0Ev
	.globl	__ZTV13CMonoAllocAdp
	.section	.rdata$_ZTV13CMonoAllocAdp,"dr"
	.linkonce same_size
	.align 32
__ZTV13CMonoAllocAdp:
	.long	0
	.long	__ZTI13CMonoAllocAdp
	.long	__ZNK13CMonoAllocAdp7getNameEv
	.long	__ZNK13CMonoAllocAdp8getTotalEv
	.long	__ZNK13CMonoAllocAdp7getUsedEv
	.long	__ZNK13CMonoAllocAdp9getRemainEv
	.long	__ZN13CMonoAllocAdp5allocEjjPK10ALLOC_INFO
	.long	__ZN13CMonoAllocAdp4freeEPv
	.long	__ZN13CMonoAllocAdpD1Ev
	.long	__ZN13CMonoAllocAdpD0Ev
	.globl	__ZTV12CStdAllocAdp
	.section	.rdata$_ZTV12CStdAllocAdp,"dr"
	.linkonce same_size
	.align 32
__ZTV12CStdAllocAdp:
	.long	0
	.long	__ZTI12CStdAllocAdp
	.long	__ZNK12CStdAllocAdp7getNameEv
	.long	__ZNK12CStdAllocAdp8getTotalEv
	.long	__ZNK12CStdAllocAdp7getUsedEv
	.long	__ZNK12CStdAllocAdp9getRemainEv
	.long	__ZN12CStdAllocAdp5allocEjjPK10ALLOC_INFO
	.long	__ZN12CStdAllocAdp4freeEPv
	.long	__ZN12CStdAllocAdpD1Ev
	.long	__ZN12CStdAllocAdpD0Ev
	.globl	__ZTV10IAllocator
	.section	.rdata$_ZTV10IAllocator,"dr"
	.linkonce same_size
	.align 32
__ZTV10IAllocator:
	.long	0
	.long	__ZTI10IAllocator
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	__ZN10IAllocatorD1Ev
	.long	__ZN10IAllocatorD0Ev
	.globl	__ZTV27CDualStackAllocatorWithBuffILj64EE
	.section	.rdata$_ZTV27CDualStackAllocatorWithBuffILj64EE,"dr"
	.linkonce same_size
	.align 32
__ZTV27CDualStackAllocatorWithBuffILj64EE:
	.long	0
	.long	__ZTI27CDualStackAllocatorWithBuffILj64EE
	.long	__ZNK19CDualStackAllocator8getTotalEv
	.long	__ZNK19CDualStackAllocator7getUsedEv
	.long	__ZNK19CDualStackAllocator9getRemainEv
	.long	__ZNK19CDualStackAllocator9getNowPtrEv
	.long	__ZNK19CDualStackAllocator9getMarkerEv
	.long	__ZN19CDualStackAllocator5allocEjj
	.long	__ZN19CDualStackAllocator4backEj
	.long	__ZN19CDualStackAllocator4backEPKv
	.long	__ZN19CDualStackAllocator5clearEv
	.long	__ZN19CDualStackAllocator8clearAllEv
	.long	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev
	.long	__ZN27CDualStackAllocatorWithBuffILj64EED0Ev
	.globl	__ZTV23CStackAllocatorWithBuffILj64EE
	.section	.rdata$_ZTV23CStackAllocatorWithBuffILj64EE,"dr"
	.linkonce same_size
	.align 32
__ZTV23CStackAllocatorWithBuffILj64EE:
	.long	0
	.long	__ZTI23CStackAllocatorWithBuffILj64EE
	.long	__ZNK15CStackAllocator8getTotalEv
	.long	__ZNK15CStackAllocator7getUsedEv
	.long	__ZNK15CStackAllocator9getRemainEv
	.long	__ZNK15CStackAllocator9getNowPtrEv
	.long	__ZNK15CStackAllocator9getMarkerEv
	.long	__ZN15CStackAllocator5allocEjj
	.long	__ZN15CStackAllocator4backEj
	.long	__ZN15CStackAllocator4backEPKv
	.long	__ZN15CStackAllocator5clearEv
	.long	__ZN15CStackAllocator8clearAllEv
	.long	__ZN23CStackAllocatorWithBuffILj64EED1Ev
	.long	__ZN23CStackAllocatorWithBuffILj64EED0Ev
	.globl	__ZTV19CDualStackAllocator
	.section	.rdata$_ZTV19CDualStackAllocator,"dr"
	.linkonce same_size
	.align 32
__ZTV19CDualStackAllocator:
	.long	0
	.long	__ZTI19CDualStackAllocator
	.long	__ZNK19CDualStackAllocator8getTotalEv
	.long	__ZNK19CDualStackAllocator7getUsedEv
	.long	__ZNK19CDualStackAllocator9getRemainEv
	.long	__ZNK19CDualStackAllocator9getNowPtrEv
	.long	__ZNK19CDualStackAllocator9getMarkerEv
	.long	__ZN19CDualStackAllocator5allocEjj
	.long	__ZN19CDualStackAllocator4backEj
	.long	__ZN19CDualStackAllocator4backEPKv
	.long	__ZN19CDualStackAllocator5clearEv
	.long	__ZN19CDualStackAllocator8clearAllEv
	.long	__ZN19CDualStackAllocatorD1Ev
	.long	__ZN19CDualStackAllocatorD0Ev
	.globl	__ZTV15CStackAllocator
	.section	.rdata$_ZTV15CStackAllocator,"dr"
	.linkonce same_size
	.align 32
__ZTV15CStackAllocator:
	.long	0
	.long	__ZTI15CStackAllocator
	.long	__ZNK15CStackAllocator8getTotalEv
	.long	__ZNK15CStackAllocator7getUsedEv
	.long	__ZNK15CStackAllocator9getRemainEv
	.long	__ZNK15CStackAllocator9getNowPtrEv
	.long	__ZNK15CStackAllocator9getMarkerEv
	.long	__ZN15CStackAllocator5allocEjj
	.long	__ZN15CStackAllocator4backEj
	.long	__ZN15CStackAllocator4backEPKv
	.long	__ZN15CStackAllocator5clearEv
	.long	__ZN15CStackAllocator8clearAllEv
	.long	__ZN15CStackAllocatorD1Ev
	.long	__ZN15CStackAllocatorD0Ev
	.globl	__ZTV15IStackAllocator
	.section	.rdata$_ZTV15IStackAllocator,"dr"
	.linkonce same_size
	.align 32
__ZTV15IStackAllocator:
	.long	0
	.long	__ZTI15IStackAllocator
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	__ZN15IStackAllocatorD1Ev
	.long	__ZN15IStackAllocatorD0Ev
	.globl	__ZTV13CDerivedTest2
	.section	.rdata$_ZTV13CDerivedTest2,"dr"
	.linkonce same_size
	.align 32
__ZTV13CDerivedTest2:
	.long	0
	.long	__ZTI13CDerivedTest2
	.long	__ZN13CDerivedTest2D1Ev
	.long	__ZN13CDerivedTest2D0Ev
	.long	-12
	.long	__ZTI13CDerivedTest2
	.long	__ZThn12_N13CDerivedTest2D1Ev
	.long	__ZThn12_N13CDerivedTest2D0Ev
	.globl	__ZTV8CTest2ex
	.section	.rdata$_ZTV8CTest2ex,"dr"
	.linkonce same_size
	.align 8
__ZTV8CTest2ex:
	.long	0
	.long	__ZTI8CTest2ex
	.long	__ZN8CTest2exD1Ev
	.long	__ZN8CTest2exD0Ev
	.globl	__ZTV6CTest2
	.section	.rdata$_ZTV6CTest2,"dr"
	.linkonce same_size
	.align 8
__ZTV6CTest2:
	.long	0
	.long	__ZTI6CTest2
	.long	__ZN6CTest2D1Ev
	.long	__ZN6CTest2D0Ev
	.globl	__ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE
	.section	.rdata$_ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE,"dr"
	.linkonce same_size
	.align 32
__ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE:
	.ascii "St23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE\0"
	.globl	__ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE
	.section	.rdata$_ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE,"dr"
	.linkonce same_size
	.align 4
__ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE
	.long	__ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.globl	__ZTSSt19_Sp_make_shared_tag
	.section	.rdata$_ZTSSt19_Sp_make_shared_tag,"dr"
	.linkonce same_size
__ZTSSt19_Sp_make_shared_tag:
	.ascii "St19_Sp_make_shared_tag\0"
	.globl	__ZTISt19_Sp_make_shared_tag
	.section	.rdata$_ZTISt19_Sp_make_shared_tag,"dr"
	.linkonce same_size
	.align 4
__ZTISt19_Sp_make_shared_tag:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSSt19_Sp_make_shared_tag
	.globl	__ZTSNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEE
	.section	.rdata$_ZTSNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEE,"dr"
	.linkonce same_size
	.align 32
__ZTSNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEE:
	.ascii "NSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEE\0"
	.globl	__ZTINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEE
	.section	.rdata$_ZTINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEE,"dr"
	.linkonce same_size
	.align 4
__ZTINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTSNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEEE
	.long	__ZTINSt6thread10_Impl_baseE
	.globl	__ZTSA3_6CTest7
	.section	.rdata$_ZTSA3_6CTest7,"dr"
	.linkonce same_size
__ZTSA3_6CTest7:
	.ascii "A3_6CTest7\0"
	.globl	__ZTIA3_6CTest7
	.section	.rdata$_ZTIA3_6CTest7,"dr"
	.linkonce same_size
	.align 4
__ZTIA3_6CTest7:
	.long	__ZTVN10__cxxabiv117__array_type_infoE+8
	.long	__ZTSA3_6CTest7
	.globl	__ZTS28CSmartStackAllocatorWithBuffILj128EE
	.section	.rdata$_ZTS28CSmartStackAllocatorWithBuffILj128EE,"dr"
	.linkonce same_size
	.align 32
__ZTS28CSmartStackAllocatorWithBuffILj128EE:
	.ascii "28CSmartStackAllocatorWithBuffILj128EE\0"
	.globl	__ZTI28CSmartStackAllocatorWithBuffILj128EE
	.section	.rdata$_ZTI28CSmartStackAllocatorWithBuffILj128EE,"dr"
	.linkonce same_size
	.align 4
__ZTI28CSmartStackAllocatorWithBuffILj128EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS28CSmartStackAllocatorWithBuffILj128EE
	.long	__ZTI20CSmartStackAllocator
	.globl	__ZTS28CSmartStackAllocatorWithBuffILj1024EE
	.section	.rdata$_ZTS28CSmartStackAllocatorWithBuffILj1024EE,"dr"
	.linkonce same_size
	.align 32
__ZTS28CSmartStackAllocatorWithBuffILj1024EE:
	.ascii "28CSmartStackAllocatorWithBuffILj1024EE\0"
	.globl	__ZTI28CSmartStackAllocatorWithBuffILj1024EE
	.section	.rdata$_ZTI28CSmartStackAllocatorWithBuffILj1024EE,"dr"
	.linkonce same_size
	.align 4
__ZTI28CSmartStackAllocatorWithBuffILj1024EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS28CSmartStackAllocatorWithBuffILj1024EE
	.long	__ZTI20CSmartStackAllocator
	.globl	__ZTS6CTest9
	.section	.rdata$_ZTS6CTest9,"dr"
	.linkonce same_size
__ZTS6CTest9:
	.ascii "6CTest9\0"
	.globl	__ZTI6CTest9
	.section	.rdata$_ZTI6CTest9,"dr"
	.linkonce same_size
	.align 4
__ZTI6CTest9:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTS6CTest9
	.globl	__ZTS19CSmartStackAllocAdp
	.section	.rdata$_ZTS19CSmartStackAllocAdp,"dr"
	.linkonce same_size
__ZTS19CSmartStackAllocAdp:
	.ascii "19CSmartStackAllocAdp\0"
	.globl	__ZTI19CSmartStackAllocAdp
	.section	.rdata$_ZTI19CSmartStackAllocAdp,"dr"
	.linkonce same_size
	.align 4
__ZTI19CSmartStackAllocAdp:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS19CSmartStackAllocAdp
	.long	__ZTI15CIStackAllocAdp
	.globl	__ZTS20CSmartStackAllocator
	.section	.rdata$_ZTS20CSmartStackAllocator,"dr"
	.linkonce same_size
__ZTS20CSmartStackAllocator:
	.ascii "20CSmartStackAllocator\0"
	.globl	__ZTI20CSmartStackAllocator
	.section	.rdata$_ZTI20CSmartStackAllocator,"dr"
	.linkonce same_size
	.align 4
__ZTI20CSmartStackAllocator:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS20CSmartStackAllocator
	.long	__ZTI15IStackAllocator
	.globl	__ZTSNSt6thread10_Impl_baseE
	.section	.rdata$_ZTSNSt6thread10_Impl_baseE,"dr"
	.linkonce same_size
__ZTSNSt6thread10_Impl_baseE:
	.ascii "NSt6thread10_Impl_baseE\0"
	.globl	__ZTINSt6thread10_Impl_baseE
	.section	.rdata$_ZTINSt6thread10_Impl_baseE,"dr"
	.linkonce same_size
	.align 4
__ZTINSt6thread10_Impl_baseE:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSNSt6thread10_Impl_baseE
	.globl	__ZTSSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.section	.rdata$_ZTSSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE,"dr"
	.linkonce same_size
	.align 32
__ZTSSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE:
	.ascii "St16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE\0"
	.globl	__ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.section	.rdata$_ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE,"dr"
	.linkonce same_size
	.align 4
__ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTSSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.long	__ZTISt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE
	.globl	__ZTS23CStackAllocatorWithBuffILj8192EE
	.section	.rdata$_ZTS23CStackAllocatorWithBuffILj8192EE,"dr"
	.linkonce same_size
	.align 32
__ZTS23CStackAllocatorWithBuffILj8192EE:
	.ascii "23CStackAllocatorWithBuffILj8192EE\0"
	.globl	__ZTI23CStackAllocatorWithBuffILj8192EE
	.section	.rdata$_ZTI23CStackAllocatorWithBuffILj8192EE,"dr"
	.linkonce same_size
	.align 4
__ZTI23CStackAllocatorWithBuffILj8192EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS23CStackAllocatorWithBuffILj8192EE
	.long	__ZTI15CStackAllocator
	.globl	__ZTS23CStackAllocatorWithBuffILj1024EE
	.section	.rdata$_ZTS23CStackAllocatorWithBuffILj1024EE,"dr"
	.linkonce same_size
	.align 32
__ZTS23CStackAllocatorWithBuffILj1024EE:
	.ascii "23CStackAllocatorWithBuffILj1024EE\0"
	.globl	__ZTI23CStackAllocatorWithBuffILj1024EE
	.section	.rdata$_ZTI23CStackAllocatorWithBuffILj1024EE,"dr"
	.linkonce same_size
	.align 4
__ZTI23CStackAllocatorWithBuffILj1024EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS23CStackAllocatorWithBuffILj1024EE
	.long	__ZTI15CStackAllocator
	.globl	__ZTS13CDerivedTest7
	.section	.rdata$_ZTS13CDerivedTest7,"dr"
	.linkonce same_size
__ZTS13CDerivedTest7:
	.ascii "13CDerivedTest7\0"
	.globl	__ZTI13CDerivedTest7
	.section	.rdata$_ZTI13CDerivedTest7,"dr"
	.linkonce same_size
	.align 32
__ZTI13CDerivedTest7:
	.long	__ZTVN10__cxxabiv121__vmi_class_type_infoE+8
	.long	__ZTS13CDerivedTest7
	.long	0
	.long	2
	.long	__ZTI6CTest7
	.long	2
	.long	__ZTI8CTest7ex
	.long	3074
	.globl	__ZTS8CTest7ex
	.section	.rdata$_ZTS8CTest7ex,"dr"
	.linkonce same_size
__ZTS8CTest7ex:
	.ascii "8CTest7ex\0"
	.globl	__ZTI8CTest7ex
	.section	.rdata$_ZTI8CTest7ex,"dr"
	.linkonce same_size
	.align 4
__ZTI8CTest7ex:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTS8CTest7ex
	.globl	__ZTS6CTest7
	.section	.rdata$_ZTS6CTest7,"dr"
	.linkonce same_size
__ZTS6CTest7:
	.ascii "6CTest7\0"
	.globl	__ZTI6CTest7
	.section	.rdata$_ZTI6CTest7,"dr"
	.linkonce same_size
	.align 4
__ZTI6CTest7:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTS6CTest7
	.globl	__ZTS27CDualStackAllocatorWithBuffILj128EE
	.section	.rdata$_ZTS27CDualStackAllocatorWithBuffILj128EE,"dr"
	.linkonce same_size
	.align 32
__ZTS27CDualStackAllocatorWithBuffILj128EE:
	.ascii "27CDualStackAllocatorWithBuffILj128EE\0"
	.globl	__ZTI27CDualStackAllocatorWithBuffILj128EE
	.section	.rdata$_ZTI27CDualStackAllocatorWithBuffILj128EE,"dr"
	.linkonce same_size
	.align 4
__ZTI27CDualStackAllocatorWithBuffILj128EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS27CDualStackAllocatorWithBuffILj128EE
	.long	__ZTI19CDualStackAllocator
	.globl	__ZTS23CStackAllocatorWithBuffILj128EE
	.section	.rdata$_ZTS23CStackAllocatorWithBuffILj128EE,"dr"
	.linkonce same_size
	.align 32
__ZTS23CStackAllocatorWithBuffILj128EE:
	.ascii "23CStackAllocatorWithBuffILj128EE\0"
	.globl	__ZTI23CStackAllocatorWithBuffILj128EE
	.section	.rdata$_ZTI23CStackAllocatorWithBuffILj128EE,"dr"
	.linkonce same_size
	.align 4
__ZTI23CStackAllocatorWithBuffILj128EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS23CStackAllocatorWithBuffILj128EE
	.long	__ZTI15CStackAllocator
	.globl	__ZTS21CMonoAllocAdpWithBuffILj128EE
	.section	.rdata$_ZTS21CMonoAllocAdpWithBuffILj128EE,"dr"
	.linkonce same_size
	.align 32
__ZTS21CMonoAllocAdpWithBuffILj128EE:
	.ascii "21CMonoAllocAdpWithBuffILj128EE\0"
	.globl	__ZTI21CMonoAllocAdpWithBuffILj128EE
	.section	.rdata$_ZTI21CMonoAllocAdpWithBuffILj128EE,"dr"
	.linkonce same_size
	.align 4
__ZTI21CMonoAllocAdpWithBuffILj128EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS21CMonoAllocAdpWithBuffILj128EE
	.long	__ZTI13CMonoAllocAdp
	.globl	__ZTS13CDerivedTest6
	.section	.rdata$_ZTS13CDerivedTest6,"dr"
	.linkonce same_size
__ZTS13CDerivedTest6:
	.ascii "13CDerivedTest6\0"
	.globl	__ZTI13CDerivedTest6
	.section	.rdata$_ZTI13CDerivedTest6,"dr"
	.linkonce same_size
	.align 32
__ZTI13CDerivedTest6:
	.long	__ZTVN10__cxxabiv121__vmi_class_type_infoE+8
	.long	__ZTS13CDerivedTest6
	.long	0
	.long	2
	.long	__ZTI6CTest6
	.long	2
	.long	__ZTI8CTest6ex
	.long	3074
	.globl	__ZTS8CTest6ex
	.section	.rdata$_ZTS8CTest6ex,"dr"
	.linkonce same_size
__ZTS8CTest6ex:
	.ascii "8CTest6ex\0"
	.globl	__ZTI8CTest6ex
	.section	.rdata$_ZTI8CTest6ex,"dr"
	.linkonce same_size
	.align 4
__ZTI8CTest6ex:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTS8CTest6ex
	.globl	__ZTS6CTest6
	.section	.rdata$_ZTS6CTest6,"dr"
	.linkonce same_size
__ZTS6CTest6:
	.ascii "6CTest6\0"
	.globl	__ZTI6CTest6
	.section	.rdata$_ZTI6CTest6,"dr"
	.linkonce same_size
	.align 4
__ZTI6CTest6:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTS6CTest6
	.globl	__ZTS13CPoolAllocAdp
	.section	.rdata$_ZTS13CPoolAllocAdp,"dr"
	.linkonce same_size
__ZTS13CPoolAllocAdp:
	.ascii "13CPoolAllocAdp\0"
	.globl	__ZTI13CPoolAllocAdp
	.section	.rdata$_ZTI13CPoolAllocAdp,"dr"
	.linkonce same_size
	.align 4
__ZTI13CPoolAllocAdp:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS13CPoolAllocAdp
	.long	__ZTI10IAllocator
	.globl	__ZTS18CDualStackAllocAdp
	.section	.rdata$_ZTS18CDualStackAllocAdp,"dr"
	.linkonce same_size
__ZTS18CDualStackAllocAdp:
	.ascii "18CDualStackAllocAdp\0"
	.globl	__ZTI18CDualStackAllocAdp
	.section	.rdata$_ZTI18CDualStackAllocAdp,"dr"
	.linkonce same_size
	.align 4
__ZTI18CDualStackAllocAdp:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS18CDualStackAllocAdp
	.long	__ZTI15CIStackAllocAdp
	.globl	__ZTS14CStackAllocAdp
	.section	.rdata$_ZTS14CStackAllocAdp,"dr"
	.linkonce same_size
__ZTS14CStackAllocAdp:
	.ascii "14CStackAllocAdp\0"
	.globl	__ZTI14CStackAllocAdp
	.section	.rdata$_ZTI14CStackAllocAdp,"dr"
	.linkonce same_size
	.align 4
__ZTI14CStackAllocAdp:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS14CStackAllocAdp
	.long	__ZTI15CIStackAllocAdp
	.globl	__ZTS15CIStackAllocAdp
	.section	.rdata$_ZTS15CIStackAllocAdp,"dr"
	.linkonce same_size
__ZTS15CIStackAllocAdp:
	.ascii "15CIStackAllocAdp\0"
	.globl	__ZTI15CIStackAllocAdp
	.section	.rdata$_ZTI15CIStackAllocAdp,"dr"
	.linkonce same_size
	.align 4
__ZTI15CIStackAllocAdp:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS15CIStackAllocAdp
	.long	__ZTI10IAllocator
	.globl	__ZTS13CMonoAllocAdp
	.section	.rdata$_ZTS13CMonoAllocAdp,"dr"
	.linkonce same_size
__ZTS13CMonoAllocAdp:
	.ascii "13CMonoAllocAdp\0"
	.globl	__ZTI13CMonoAllocAdp
	.section	.rdata$_ZTI13CMonoAllocAdp,"dr"
	.linkonce same_size
	.align 4
__ZTI13CMonoAllocAdp:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS13CMonoAllocAdp
	.long	__ZTI10IAllocator
	.globl	__ZTS12CStdAllocAdp
	.section	.rdata$_ZTS12CStdAllocAdp,"dr"
	.linkonce same_size
__ZTS12CStdAllocAdp:
	.ascii "12CStdAllocAdp\0"
	.globl	__ZTI12CStdAllocAdp
	.section	.rdata$_ZTI12CStdAllocAdp,"dr"
	.linkonce same_size
	.align 4
__ZTI12CStdAllocAdp:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS12CStdAllocAdp
	.long	__ZTI10IAllocator
	.globl	__ZTS10IAllocator
	.section	.rdata$_ZTS10IAllocator,"dr"
	.linkonce same_size
__ZTS10IAllocator:
	.ascii "10IAllocator\0"
	.globl	__ZTI10IAllocator
	.section	.rdata$_ZTI10IAllocator,"dr"
	.linkonce same_size
	.align 4
__ZTI10IAllocator:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTS10IAllocator
	.globl	__ZTS27CDualStackAllocatorWithBuffILj64EE
	.section	.rdata$_ZTS27CDualStackAllocatorWithBuffILj64EE,"dr"
	.linkonce same_size
	.align 32
__ZTS27CDualStackAllocatorWithBuffILj64EE:
	.ascii "27CDualStackAllocatorWithBuffILj64EE\0"
	.globl	__ZTI27CDualStackAllocatorWithBuffILj64EE
	.section	.rdata$_ZTI27CDualStackAllocatorWithBuffILj64EE,"dr"
	.linkonce same_size
	.align 4
__ZTI27CDualStackAllocatorWithBuffILj64EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS27CDualStackAllocatorWithBuffILj64EE
	.long	__ZTI19CDualStackAllocator
	.globl	__ZTS23CStackAllocatorWithBuffILj64EE
	.section	.rdata$_ZTS23CStackAllocatorWithBuffILj64EE,"dr"
	.linkonce same_size
	.align 32
__ZTS23CStackAllocatorWithBuffILj64EE:
	.ascii "23CStackAllocatorWithBuffILj64EE\0"
	.globl	__ZTI23CStackAllocatorWithBuffILj64EE
	.section	.rdata$_ZTI23CStackAllocatorWithBuffILj64EE,"dr"
	.linkonce same_size
	.align 4
__ZTI23CStackAllocatorWithBuffILj64EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS23CStackAllocatorWithBuffILj64EE
	.long	__ZTI15CStackAllocator
	.globl	__ZTS19CDualStackAllocator
	.section	.rdata$_ZTS19CDualStackAllocator,"dr"
	.linkonce same_size
__ZTS19CDualStackAllocator:
	.ascii "19CDualStackAllocator\0"
	.globl	__ZTI19CDualStackAllocator
	.section	.rdata$_ZTI19CDualStackAllocator,"dr"
	.linkonce same_size
	.align 4
__ZTI19CDualStackAllocator:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS19CDualStackAllocator
	.long	__ZTI15IStackAllocator
	.globl	__ZTS15CStackAllocator
	.section	.rdata$_ZTS15CStackAllocator,"dr"
	.linkonce same_size
__ZTS15CStackAllocator:
	.ascii "15CStackAllocator\0"
	.globl	__ZTI15CStackAllocator
	.section	.rdata$_ZTI15CStackAllocator,"dr"
	.linkonce same_size
	.align 4
__ZTI15CStackAllocator:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS15CStackAllocator
	.long	__ZTI15IStackAllocator
	.globl	__ZTS15IStackAllocator
	.section	.rdata$_ZTS15IStackAllocator,"dr"
	.linkonce same_size
__ZTS15IStackAllocator:
	.ascii "15IStackAllocator\0"
	.globl	__ZTI15IStackAllocator
	.section	.rdata$_ZTI15IStackAllocator,"dr"
	.linkonce same_size
	.align 4
__ZTI15IStackAllocator:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTS15IStackAllocator
	.globl	__ZTS13CDerivedTest2
	.section	.rdata$_ZTS13CDerivedTest2,"dr"
	.linkonce same_size
__ZTS13CDerivedTest2:
	.ascii "13CDerivedTest2\0"
	.globl	__ZTI13CDerivedTest2
	.section	.rdata$_ZTI13CDerivedTest2,"dr"
	.linkonce same_size
	.align 32
__ZTI13CDerivedTest2:
	.long	__ZTVN10__cxxabiv121__vmi_class_type_infoE+8
	.long	__ZTS13CDerivedTest2
	.long	0
	.long	2
	.long	__ZTI6CTest2
	.long	2
	.long	__ZTI8CTest2ex
	.long	3074
	.globl	__ZTS8CTest2ex
	.section	.rdata$_ZTS8CTest2ex,"dr"
	.linkonce same_size
__ZTS8CTest2ex:
	.ascii "8CTest2ex\0"
	.globl	__ZTI8CTest2ex
	.section	.rdata$_ZTI8CTest2ex,"dr"
	.linkonce same_size
	.align 4
__ZTI8CTest2ex:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTS8CTest2ex
	.globl	__ZTS6CTest2
	.section	.rdata$_ZTS6CTest2,"dr"
	.linkonce same_size
__ZTS6CTest2:
	.ascii "6CTest2\0"
	.globl	__ZTI6CTest2
	.section	.rdata$_ZTI6CTest2,"dr"
	.linkonce same_size
	.align 4
__ZTI6CTest2:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTS6CTest2
	.text
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB3844:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	cmpl	$1, 8(%ebp)
	jne	L2272
	cmpl	$65535, 12(%ebp)
	jne	L2272
	movl	$__ZN16CTest3Singleton111m_singletonE, (%esp)
	call	__ZN16CTest3Singleton1C1Ev
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread2idC1Ev
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt4hashINSt6thread2idEEclERKS1_
	movl	%eax, __ZL17INVALID_THREAD_ID
	movl	$1, 4(%esp)
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZN28CSmartStackAllocatorWithBuffILj1024EEC1EN15IStackAllocator9E_ORDEREDE
L2272:
	cmpl	$0, 8(%ebp)
	jne	L2271
	cmpl	$65535, 12(%ebp)
	jne	L2271
	movl	$__ZL16s_stackForThread, (%esp)
	call	__ZN28CSmartStackAllocatorWithBuffILj1024EED1Ev
	movl	$__ZN16CTest3Singleton111m_singletonE, (%esp)
	call	__ZN16CTest3Singleton1D1Ev
L2271:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3844:
	.section .rdata,"dr"
	.align 4
__ZL11DSA_DEFAULT:
	.space 4
	.align 4
__ZL10DSA_NORMAL:
	.long	1
	.align 4
__ZL11DSA_REVERSE:
	.long	-1
	.align 4
__ZL17INITIAL_THREAD_ID:
	.long	-1
	.align 32
__ZN14crc_inner_calcL11s_calcTableE:
	.long	0
	.long	1996959894
	.long	-301047508
	.long	-1727442502
	.long	124634137
	.long	1886057615
	.long	-379345611
	.long	-1637575261
	.long	249268274
	.long	2044508324
	.long	-522852066
	.long	-1747789432
	.long	162941995
	.long	2125561021
	.long	-407360249
	.long	-1866523247
	.long	498536548
	.long	1789927666
	.long	-205950648
	.long	-2067906082
	.long	450548861
	.long	1843258603
	.long	-187386543
	.long	-2083289657
	.long	325883990
	.long	1684777152
	.long	-43845254
	.long	-1973040660
	.long	335633487
	.long	1661365465
	.long	-99664541
	.long	-1928851979
	.long	997073096
	.long	1281953886
	.long	-715111964
	.long	-1570279054
	.long	1006888145
	.long	1258607687
	.long	-770865667
	.long	-1526024853
	.long	901097722
	.long	1119000684
	.long	-608450090
	.long	-1396901568
	.long	853044451
	.long	1172266101
	.long	-589951537
	.long	-1412350631
	.long	651767980
	.long	1373503546
	.long	-925412992
	.long	-1076862698
	.long	565507253
	.long	1454621731
	.long	-809855591
	.long	-1195530993
	.long	671266974
	.long	1594198024
	.long	-972236366
	.long	-1324619484
	.long	795835527
	.long	1483230225
	.long	-1050600021
	.long	-1234817731
	.long	1994146192
	.long	31158534
	.long	-1731059524
	.long	-271249366
	.long	1907459465
	.long	112637215
	.long	-1614814043
	.long	-390540237
	.long	2013776290
	.long	251722036
	.long	-1777751922
	.long	-519137256
	.long	2137656763
	.long	141376813
	.long	-1855689577
	.long	-429695999
	.long	1802195444
	.long	476864866
	.long	-2056965928
	.long	-228458418
	.long	1812370925
	.long	453092731
	.long	-2113342271
	.long	-183516073
	.long	1706088902
	.long	314042704
	.long	-1950435094
	.long	-54949764
	.long	1658658271
	.long	366619977
	.long	-1932296973
	.long	-69972891
	.long	1303535960
	.long	984961486
	.long	-1547960204
	.long	-725929758
	.long	1256170817
	.long	1037604311
	.long	-1529756563
	.long	-740887301
	.long	1131014506
	.long	879679996
	.long	-1385723834
	.long	-631195440
	.long	1141124467
	.long	855842277
	.long	-1442165665
	.long	-586318647
	.long	1342533948
	.long	654459306
	.long	-1106571248
	.long	-921952122
	.long	1466479909
	.long	544179635
	.long	-1184443383
	.long	-832445281
	.long	1591671054
	.long	702138776
	.long	-1328506846
	.long	-942167884
	.long	1504918807
	.long	783551873
	.long	-1212326853
	.long	-1061524307
	.long	-306674912
	.long	-1698712650
	.long	62317068
	.long	1957810842
	.long	-355121351
	.long	-1647151185
	.long	81470997
	.long	1943803523
	.long	-480048366
	.long	-1805370492
	.long	225274430
	.long	2053790376
	.long	-468791541
	.long	-1828061283
	.long	167816743
	.long	2097651377
	.long	-267414716
	.long	-2029476910
	.long	503444072
	.long	1762050814
	.long	-144550051
	.long	-2140837941
	.long	426522225
	.long	1852507879
	.long	-19653770
	.long	-1982649376
	.long	282753626
	.long	1742555852
	.long	-105259153
	.long	-1900089351
	.long	397917763
	.long	1622183637
	.long	-690576408
	.long	-1580100738
	.long	953729732
	.long	1340076626
	.long	-776247311
	.long	-1497606297
	.long	1068828381
	.long	1219638859
	.long	-670225446
	.long	-1358292148
	.long	906185462
	.long	1090812512
	.long	-547295293
	.long	-1469587627
	.long	829329135
	.long	1181335161
	.long	-882789492
	.long	-1134132454
	.long	628085408
	.long	1382605366
	.long	-871598187
	.long	-1156888829
	.long	570562233
	.long	1426400815
	.long	-977650754
	.long	-1296233688
	.long	733239954
	.long	1555261956
	.long	-1026031705
	.long	-1244606671
	.long	752459403
	.long	1541320221
	.long	-1687895376
	.long	-328994266
	.long	1969922972
	.long	40735498
	.long	-1677130071
	.long	-351390145
	.long	1913087877
	.long	83908371
	.long	-1782625662
	.long	-491226604
	.long	2075208622
	.long	213261112
	.long	-1831694693
	.long	-438977011
	.long	2094854071
	.long	198958881
	.long	-2032938284
	.long	-237706686
	.long	1759359992
	.long	534414190
	.long	-2118248755
	.long	-155638181
	.long	1873836001
	.long	414664567
	.long	-2012718362
	.long	-15766928
	.long	1711684554
	.long	285281116
	.long	-1889165569
	.long	-127750551
	.long	1634467795
	.long	376229701
	.long	-1609899400
	.long	-686959890
	.long	1308918612
	.long	956543938
	.long	-1486412191
	.long	-799009033
	.long	1231636301
	.long	1047427035
	.long	-1362007478
	.long	-640263460
	.long	1088359270
	.long	936918000
	.long	-1447252397
	.long	-558129467
	.long	1202900863
	.long	817233897
	.long	-1111625188
	.long	-893730166
	.long	1404277552
	.long	615818150
	.long	-1160759803
	.long	-841546093
	.long	1423857449
	.long	601450431
	.long	-1285129682
	.long	-1000256840
	.long	1567103746
	.long	711928724
	.long	-1274298825
	.long	-1022587231
	.long	1510334235
	.long	755167117
	.align 4
__ZN9__gnu_cxxL21__default_lock_policyE:
	.long	2
	.globl	__ZN10CSingletonI6CTest3E11m_singletonE
	.section	.data$_ZN10CSingletonI6CTest3E11m_singletonE,"w"
	.linkonce same_size
	.align 4
__ZN10CSingletonI6CTest3E11m_singletonE:
	.space 4
	.globl	__ZN10CSingletonI6CTest3E15m_singletonBuffE
	.section	.data$_ZN10CSingletonI6CTest3E15m_singletonBuffE,"w"
	.linkonce same_size
__ZN10CSingletonI6CTest3E15m_singletonBuffE:
	.space 4
	.section	.text$_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EED1Ev
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EED1Ev:
LFB3847:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE5_ImplD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L2274
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L2274:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3847:
	.section	.text$_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EED0Ev
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EED0Ev;	.scl	2;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EED0Ev:
LFB3848:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EED1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3848:
	.section	.text$_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv;	.scl	2;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv:
LFB3849:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3849
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	8(%ebp), %edx
	addl	$12, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE7destroyIS9_EEvRSA_PT_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3849:
	.section	.gcc_except_table,"w"
LLSDA3849:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3849-LLSDACSB3849
LLSDACSB3849:
LLSDACSE3849:
	.section	.text$_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv,"x"
	.linkonce discard
	.section	.text$_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv;	.scl	2;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv:
LFB3850:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3850
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, 4(%esp)
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEEC1IS9_EERKSaIT_E
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE7destroyISE_EEvRSF_PT_
	movl	$1, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE10deallocateERSF_PSE_j
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EEED1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3850:
	.section	.gcc_except_table,"w"
LLSDA3850:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3850-LLSDACSB3850
LLSDACSB3850:
LLSDACSE3850:
	.section	.text$_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv,"x"
	.linkonce discard
	.section	.text$_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info;	.scl	2;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info:
LFB3851:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$__ZTISt19_Sp_make_shared_tag, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9type_infoeqERKS_
	testb	%al, %al
	je	L2282
	movl	8(%ebp), %eax
	addl	$16, %eax
	jmp	L2283
L2282:
	movl	$0, %eax
L2283:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3851:
	.section	.text$_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEE6_M_runEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEE6_M_runEv
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEE6_M_runEv;	.scl	2;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES3_EEE6_M_runEv:
LFB3852:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Bind_simpleIFPFvPKcES1_EEclEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3852:
	.section	.text$_ZN28CSmartStackAllocatorWithBuffILj1024EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN28CSmartStackAllocatorWithBuffILj1024EED1Ev
	.def	__ZN28CSmartStackAllocatorWithBuffILj1024EED1Ev;	.scl	2;	.type	32;	.endef
__ZN28CSmartStackAllocatorWithBuffILj1024EED1Ev:
LFB3855:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV28CSmartStackAllocatorWithBuffILj1024EE+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN20CSmartStackAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L2286
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L2286:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3855:
	.section	.text$_ZN28CSmartStackAllocatorWithBuffILj1024EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN28CSmartStackAllocatorWithBuffILj1024EED0Ev
	.def	__ZN28CSmartStackAllocatorWithBuffILj1024EED0Ev;	.scl	2;	.type	32;	.endef
__ZN28CSmartStackAllocatorWithBuffILj1024EED0Ev:
LFB3856:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN28CSmartStackAllocatorWithBuffILj1024EED1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3856:
	.section	.text$_ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE7destroyIS9_EEvRSA_PT_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE7destroyIS9_EEvRSA_PT_
	.def	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE7destroyIS9_EEvRSA_PT_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE7destroyIS9_EEvRSA_PT_:
LFB3857:
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
	call	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE10_S_destroyIS9_EENSt9enable_ifIXsrNSB_16__destroy_helperIT_EE5valueEvE4typeERSA_PSF_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3857:
	.section	.text$_ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE7destroyISE_EEvRSF_PT_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE7destroyISE_EEvRSF_PT_
	.def	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE7destroyISE_EEvRSF_PT_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE7destroyISE_EEvRSF_PT_:
LFB3858:
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
	call	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE10_S_destroyISE_EENSt9enable_ifIXsrNSG_16__destroy_helperIT_EE5valueEvE4typeERSF_PSK_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3858:
	.section	.text$_ZNSt12_Bind_simpleIFPFvPKcES1_EEclEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Bind_simpleIFPFvPKcES1_EEclEv
	.def	__ZNSt12_Bind_simpleIFPFvPKcES1_EEclEv;	.scl	2;	.type	32;	.endef
__ZNSt12_Bind_simpleIFPFvPKcES1_EEclEv:
LFB3859:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3859
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	%al, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB398:
	call	__ZNSt12_Bind_simpleIFPFvPKcES1_EE9_M_invokeIILj0EEEEvSt12_Index_tupleIIXspT_EEE
LEHE398:
	jmp	L2297
L2296:
	movl	%eax, (%esp)
LEHB399:
	call	__Unwind_Resume
LEHE399:
L2297:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3859:
	.section	.gcc_except_table,"w"
LLSDA3859:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3859-LLSDACSB3859
LLSDACSB3859:
	.uleb128 LEHB398-LFB3859
	.uleb128 LEHE398-LEHB398
	.uleb128 L2296-LFB3859
	.uleb128 0
	.uleb128 LEHB399-LFB3859
	.uleb128 LEHE399-LEHB399
	.uleb128 0
	.uleb128 0
LLSDACSE3859:
	.section	.text$_ZNSt12_Bind_simpleIFPFvPKcES1_EEclEv,"x"
	.linkonce discard
	.section	.text$_ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE10_S_destroyIS9_EENSt9enable_ifIXsrNSB_16__destroy_helperIT_EE5valueEvE4typeERSA_PSF_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE10_S_destroyIS9_EENSt9enable_ifIXsrNSB_16__destroy_helperIT_EE5valueEvE4typeERSA_PSF_
	.def	__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE10_S_destroyIS9_EENSt9enable_ifIXsrNSB_16__destroy_helperIT_EE5valueEvE4typeERSA_PSF_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEEEE10_S_destroyIS9_EENSt9enable_ifIXsrNSB_16__destroy_helperIT_EE5valueEvE4typeERSA_PSF_:
LFB3860:
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
	call	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEE7destroyISA_EEvPT_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3860:
	.section	.text$_ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE10_S_destroyISE_EENSt9enable_ifIXsrNSG_16__destroy_helperIT_EE5valueEvE4typeERSF_PSK_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE10_S_destroyISE_EENSt9enable_ifIXsrNSG_16__destroy_helperIT_EE5valueEvE4typeERSF_PSK_
	.def	__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE10_S_destroyISE_EENSt9enable_ifIXsrNSG_16__destroy_helperIT_EE5valueEvE4typeERSF_PSK_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEESaISA_ELN9__gnu_cxx12_Lock_policyE2EEEE10_S_destroyISE_EENSt9enable_ifIXsrNSG_16__destroy_helperIT_EE5valueEvE4typeERSF_PSK_:
LFB3861:
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
	call	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE7destroyISE_EEvPT_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3861:
	.section	.text$_ZSt12__get_helperILj0EPFvPKcEIS1_EENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS5_DpT1_EE,"x"
	.linkonce discard
	.globl	__ZSt12__get_helperILj0EPFvPKcEIS1_EENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS5_DpT1_EE
	.def	__ZSt12__get_helperILj0EPFvPKcEIS1_EENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS5_DpT1_EE;	.scl	2;	.type	32;	.endef
__ZSt12__get_helperILj0EPFvPKcEIS1_EENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS5_DpT1_EE:
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
	call	__ZNSt11_Tuple_implILj0EIPFvPKcES1_EE7_M_headERS4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3864:
	.weak	__ZSt12__get_helperILj0EPFvPKcEJS1_EENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EJS5_DpT1_EE
	.def	__ZSt12__get_helperILj0EPFvPKcEJS1_EENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EJS5_DpT1_EE;	.scl	2;	.type	32;	.endef
	.set	__ZSt12__get_helperILj0EPFvPKcEJS1_EENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EJS5_DpT1_EE,__ZSt12__get_helperILj0EPFvPKcEIS1_EENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS5_DpT1_EE
	.section	.text$_ZSt3getILj0EIPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS9_,"x"
	.linkonce discard
	.globl	__ZSt3getILj0EIPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS9_
	.def	__ZSt3getILj0EIPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS9_;	.scl	2;	.type	32;	.endef
__ZSt3getILj0EIPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS9_:
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
	call	__ZSt12__get_helperILj0EPFvPKcEIS1_EENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS5_DpT1_EE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3863:
	.weak	__ZSt3getILj0EJPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEE4typeERS9_
	.def	__ZSt3getILj0EJPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEE4typeERS9_;	.scl	2;	.type	32;	.endef
	.set	__ZSt3getILj0EJPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEE4typeERS9_,__ZSt3getILj0EIPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS9_
	.section	.text$_ZSt12__get_helperILj1EPKcIEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS3_DpT1_EE,"x"
	.linkonce discard
	.globl	__ZSt12__get_helperILj1EPKcIEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS3_DpT1_EE
	.def	__ZSt12__get_helperILj1EPKcIEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS3_DpT1_EE;	.scl	2;	.type	32;	.endef
__ZSt12__get_helperILj1EPKcIEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS3_DpT1_EE:
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
	call	__ZNSt11_Tuple_implILj1EIPKcEE7_M_headERS2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3866:
	.weak	__ZSt12__get_helperILj1EPKcJEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EJS3_DpT1_EE
	.def	__ZSt12__get_helperILj1EPKcJEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EJS3_DpT1_EE;	.scl	2;	.type	32;	.endef
	.set	__ZSt12__get_helperILj1EPKcJEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EJS3_DpT1_EE,__ZSt12__get_helperILj1EPKcIEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS3_DpT1_EE
	.section	.text$_ZSt3getILj1EIPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS9_,"x"
	.linkonce discard
	.globl	__ZSt3getILj1EIPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS9_
	.def	__ZSt3getILj1EIPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS9_;	.scl	2;	.type	32;	.endef
__ZSt3getILj1EIPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS9_:
LFB3865:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__get_helperILj1EPKcIEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS3_DpT1_EE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3865:
	.weak	__ZSt3getILj1EJPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEE4typeERS9_
	.def	__ZSt3getILj1EJPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEE4typeERS9_;	.scl	2;	.type	32;	.endef
	.set	__ZSt3getILj1EJPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEE4typeERS9_,__ZSt3getILj1EIPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS9_
	.section	.text$_ZNSt12_Bind_simpleIFPFvPKcES1_EE9_M_invokeIILj0EEEEvSt12_Index_tupleIIXspT_EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Bind_simpleIFPFvPKcES1_EE9_M_invokeIILj0EEEEvSt12_Index_tupleIIXspT_EEE
	.def	__ZNSt12_Bind_simpleIFPFvPKcES1_EE9_M_invokeIILj0EEEEvSt12_Index_tupleIIXspT_EEE;	.scl	2;	.type	32;	.endef
__ZNSt12_Bind_simpleIFPFvPKcES1_EE9_M_invokeIILj0EEEEvSt12_Index_tupleIIXspT_EEE:
LFB3862:
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
	call	__ZSt3getILj0EIPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS9_
	movl	%eax, (%esp)
	call	__ZSt7forwardIPFvPKcEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	(%eax), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt3getILj1EIPFvPKcES1_EENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS9_
	movl	%eax, (%esp)
	call	__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	*%ebx
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3862:
	.weak	__ZNSt12_Bind_simpleIFPFvPKcES1_EE9_M_invokeIJLj0EEEEvSt12_Index_tupleIJXspT_EEE
	.def	__ZNSt12_Bind_simpleIFPFvPKcES1_EE9_M_invokeIJLj0EEEEvSt12_Index_tupleIJXspT_EEE;	.scl	2;	.type	32;	.endef
	.set	__ZNSt12_Bind_simpleIFPFvPKcES1_EE9_M_invokeIJLj0EEEEvSt12_Index_tupleIJXspT_EEE,__ZNSt12_Bind_simpleIFPFvPKcES1_EE9_M_invokeIILj0EEEEvSt12_Index_tupleIIXspT_EEE
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEE7destroyISA_EEvPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEE7destroyISA_EEvPT_
	.def	__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEE7destroyISA_EEvPT_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES5_EEEEE7destroyISA_EEvPT_:
LFB3867:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3867:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE7destroyISE_EEvPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE7destroyISE_EEvPT_
	.def	__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE7destroyISE_EEvPT_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES6_EEEESaISB_ELNS_12_Lock_policyE2EEE7destroyISE_EEvPT_:
LFB3868:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvPKcES4_EEEESaIS9_ELN9__gnu_cxx12_Lock_policyE2EED1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3868:
	.globl	__ZTSSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE
	.section	.rdata$_ZTSSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE,"dr"
	.linkonce same_size
	.align 32
__ZTSSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE:
	.ascii "St11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE\0"
	.globl	__ZTISt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE
	.section	.rdata$_ZTISt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE,"dr"
	.linkonce same_size
	.align 4
__ZTISt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE
	.text
	.def	__GLOBAL__sub_I__Z5test0v;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z5test0v:
LFB3869:
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
LFE3869:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z5test0v
	.text
	.def	__GLOBAL__sub_D__Z5test0v;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_D__Z5test0v:
LFB3870:
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
LFE3870:
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__sub_D__Z5test0v
	.section .rdata,"dr"
__ZZ10test7_sub1PKcE19__PRETTY_FUNCTION__:
	.ascii "void test7_sub1(const char*)\0"
__ZZ10test7_sub2vE19__PRETTY_FUNCTION__:
	.ascii "void test7_sub2()\0"
__ZZ10test7_sub3PKcE19__PRETTY_FUNCTION__:
	.ascii "void test7_sub3(const char*)\0"
	.align 4
___emutls_t._ZN9CThreadID16m_thisThreadNameE:
	.space 4
	.globl	___emutls_v._ZN9CThreadID16m_thisThreadNameE
	.data
	.align 4
___emutls_v._ZN9CThreadID16m_thisThreadNameE:
	.long	4
	.long	4
	.long	0
	.long	___emutls_t._ZN9CThreadID16m_thisThreadNameE
	.section .rdata,"dr"
	.align 4
___emutls_t._ZN9CThreadID14m_thisThreadIDE:
	.long	-1
	.globl	___emutls_v._ZN9CThreadID14m_thisThreadIDE
	.data
	.align 4
___emutls_v._ZN9CThreadID14m_thisThreadIDE:
	.long	4
	.long	4
	.long	0
	.long	___emutls_t._ZN9CThreadID14m_thisThreadIDE
	.section .rdata,"dr"
	.align 4
___emutls_t._ZN14CPolyAllocator11m_allocInfoE:
	.space 4
	.globl	___emutls_v._ZN14CPolyAllocator11m_allocInfoE
	.data
	.align 4
___emutls_v._ZN14CPolyAllocator11m_allocInfoE:
	.long	4
	.long	4
	.long	0
	.long	___emutls_t._ZN14CPolyAllocator11m_allocInfoE
	.section .rdata,"dr"
	.align 4
___emutls_t._ZN14CPolyAllocator11m_allocatorE:
	.space 4
	.globl	___emutls_v._ZN14CPolyAllocator11m_allocatorE
	.data
	.align 4
___emutls_v._ZN14CPolyAllocator11m_allocatorE:
	.long	4
	.long	4
	.long	0
	.long	___emutls_t._ZN14CPolyAllocator11m_allocatorE
	.section .rdata,"dr"
	.align 4
LC170:
	.long	0
	.align 4
LC265:
	.long	1065353216
	.ident	"GCC: (GNU) 4.8.2"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	___cxa_call_unexpected;	.scl	2;	.type	32;	.endef
	.def	_memalign;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	___emutls_get_address;	.scl	2;	.type	32;	.endef
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_pthread_equal;	.scl	2;	.type	32;	.endef
	.def	__ZSt11_Hash_bytesPKvjj;	.scl	2;	.type	32;	.endef
	.def	_ceil;	.scl	2;	.type	32;	.endef
	.def	_strcpy;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcEC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1EPKcRKSaIcE;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNKSs5c_strEv;	.scl	2;	.type	32;	.endef
	.def	__ZSt9terminatev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6thread4joinEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1ERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZNSs6appendERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1EOSs;	.scl	2;	.type	32;	.endef
	.def	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6thread15_M_start_threadESt10shared_ptrINS_10_Impl_baseEE;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef
	.def	___cxa_end_catch;	.scl	2;	.type	32;	.endef
	.def	___cxa_begin_catch;	.scl	2;	.type	32;	.endef
	.def	___cxa_rethrow;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt8__detail20_Prime_rehash_policy11_M_next_bktEj;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt8__detail20_Prime_rehash_policy14_M_need_rehashEjjj;	.scl	2;	.type	32;	.endef
	.def	__ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	___cxa_pure_virtual;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt9type_infoeqERKS_;	.scl	2;	.type	32;	.endef

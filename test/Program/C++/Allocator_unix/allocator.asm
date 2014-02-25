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
LFB49:
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
LFE49:
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
LFB52:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA52
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
LFE52:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA52:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE52-LLSDACSB52
LLSDACSB52:
LLSDACSE52:
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
LFB53:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA53
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
	jmp	L9
L8:
	movl	%eax, (%esp)
LEHB1:
	call	__Unwind_Resume
LEHE1:
L9:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE53:
	.section	.gcc_except_table,"w"
LLSDA53:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE53-LLSDACSB53
LLSDACSB53:
	.uleb128 LEHB0-LFB53
	.uleb128 LEHE0-LEHB0
	.uleb128 L8-LFB53
	.uleb128 0
	.uleb128 LEHB1-LFB53
	.uleb128 LEHE1-LEHB1
	.uleb128 0
	.uleb128 0
LLSDACSE53:
	.text
	.section .rdata,"dr"
	.align 4
LC6:
	.ascii "placement new(size=%d, where=0x%p)\12\0"
	.text
	.globl	__ZnwjPc
	.def	__ZnwjPc;	.scl	2;	.type	32;	.endef
__ZnwjPc:
LFB54:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA54
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
	jmp	L15
L14:
	cmpl	$-1, %edx
	je	L13
	movl	%eax, (%esp)
LEHB3:
	call	__Unwind_Resume
L13:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE3:
L15:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE54:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA54:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT54-LLSDATTD54
LLSDATTD54:
	.byte	0x1
	.uleb128 LLSDACSE54-LLSDACSB54
LLSDACSB54:
	.uleb128 LEHB2-LFB54
	.uleb128 LEHE2-LEHB2
	.uleb128 L14-LFB54
	.uleb128 0x1
	.uleb128 LEHB3-LFB54
	.uleb128 LEHE3-LEHB3
	.uleb128 0
	.uleb128 0
LLSDACSE54:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT54:
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
LFB55:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA55
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
	jmp	L21
L20:
	cmpl	$-1, %edx
	je	L19
	movl	%eax, (%esp)
LEHB5:
	call	__Unwind_Resume
L19:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE5:
L21:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE55:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA55:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT55-LLSDATTD55
LLSDATTD55:
	.byte	0x1
	.uleb128 LLSDACSE55-LLSDACSB55
LLSDACSB55:
	.uleb128 LEHB4-LFB55
	.uleb128 LEHE4-LEHB4
	.uleb128 L20-LFB55
	.uleb128 0x1
	.uleb128 LEHB5-LFB55
	.uleb128 LEHE5-LEHB5
	.uleb128 0
	.uleb128 0
LLSDACSE55:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT55:
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
LFB56:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA56
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
	jmp	L26
L25:
	cmpl	$-1, %edx
	je	L24
	movl	%eax, (%esp)
LEHB7:
	call	__Unwind_Resume
L24:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE7:
L26:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE56:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA56:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT56-LLSDATTD56
LLSDATTD56:
	.byte	0x1
	.uleb128 LLSDACSE56-LLSDACSB56
LLSDACSB56:
	.uleb128 LEHB6-LFB56
	.uleb128 LEHE6-LEHB6
	.uleb128 L25-LFB56
	.uleb128 0x1
	.uleb128 LEHB7-LFB56
	.uleb128 LEHE7-LEHB7
	.uleb128 0
	.uleb128 0
LLSDACSE56:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT56:
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
LFB57:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA57
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
	jmp	L31
L30:
	cmpl	$-1, %edx
	je	L29
	movl	%eax, (%esp)
LEHB9:
	call	__Unwind_Resume
L29:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE9:
L31:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE57:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA57:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT57-LLSDATTD57
LLSDATTD57:
	.byte	0x1
	.uleb128 LLSDACSE57-LLSDACSB57
LLSDACSB57:
	.uleb128 LEHB8-LFB57
	.uleb128 LEHE8-LEHB8
	.uleb128 L30-LFB57
	.uleb128 0x1
	.uleb128 LEHB9-LFB57
	.uleb128 LEHE9-LEHB9
	.uleb128 0
	.uleb128 0
LLSDACSE57:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT57:
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
LFB62:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA62
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
	jmp	L35
L34:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest1D1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB12:
	call	__Unwind_Resume
LEHE12:
L35:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE62:
	.section	.gcc_except_table,"w"
LLSDA62:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE62-LLSDACSB62
LLSDACSB62:
	.uleb128 LEHB10-LFB62
	.uleb128 LEHE10-LEHB10
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB11-LFB62
	.uleb128 LEHE11-LEHB11
	.uleb128 L34-LFB62
	.uleb128 0
	.uleb128 LEHB12-LFB62
	.uleb128 LEHE12-LEHB12
	.uleb128 0
	.uleb128 0
LLSDACSE62:
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
LFB64:
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
LFE64:
	.section	.text$_ZN6CTest1C1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest1C1EPKc
	.def	__ZN6CTest1C1EPKc;	.scl	2;	.type	32;	.endef
__ZN6CTest1C1EPKc:
LFB65:
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
LFE65:
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
LFE67:
	.section	.gcc_except_table,"w"
LLSDA67:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE67-LLSDACSB67
LLSDACSB67:
LLSDACSE67:
	.section	.text$_ZN6CTest1D2Ev,"x"
	.linkonce discard
	.section	.text$_ZN6CTest1D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest1D1Ev
	.def	__ZN6CTest1D1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest1D1Ev:
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
LFE68:
	.section	.gcc_except_table,"w"
LLSDA68:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE68-LLSDACSB68
LLSDACSB68:
LLSDACSE68:
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
LFB70:
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
LFE70:
	.section .rdata,"dr"
LC15:
	.ascii "CTest1ex::Destructor\0"
	.section	.text$_ZN8CTest1exD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest1exD2Ev
	.def	__ZN8CTest1exD2Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest1exD2Ev:
LFB73:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA73
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
LFE73:
	.section	.gcc_except_table,"w"
LLSDA73:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE73-LLSDACSB73
LLSDACSB73:
LLSDACSE73:
	.section	.text$_ZN8CTest1exD2Ev,"x"
	.linkonce discard
	.section	.text$_ZN8CTest1exD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest1exD1Ev
	.def	__ZN8CTest1exD1Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest1exD1Ev:
LFB74:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA74
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
LFE74:
	.section	.gcc_except_table,"w"
LLSDA74:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE74-LLSDACSB74
LLSDACSB74:
LLSDACSE74:
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
LFB80:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA80
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
	jmp	L52
L51:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	%eax, (%esp)
	call	__ZN8CTest1exD2Ev
	jmp	L49
L50:
	movl	%eax, %ebx
L49:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest1D2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB16:
	call	__Unwind_Resume
LEHE16:
L52:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
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
	.uleb128 LEHB13-LFB80
	.uleb128 LEHE13-LEHB13
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB14-LFB80
	.uleb128 LEHE14-LEHB14
	.uleb128 L50-LFB80
	.uleb128 0
	.uleb128 LEHB15-LFB80
	.uleb128 LEHE15-LEHB15
	.uleb128 L51-LFB80
	.uleb128 0
	.uleb128 LEHB16-LFB80
	.uleb128 LEHE16-LEHB16
	.uleb128 0
	.uleb128 0
LLSDACSE80:
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
LFB84:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA84
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
	je	L54
	movl	$LC19, 4(%esp)
	movl	%ebx, (%esp)
LEHB19:
	call	__ZN6CTest1C1EPKc
LEHE19:
	movl	%ebx, %eax
	jmp	L55
L54:
	movl	%ebx, %eax
L55:
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
	je	L56
	movl	$3, (%ebx)
	leal	4(%ebx), %esi
	movl	$2, %edi
	movl	%esi, -140(%ebp)
	jmp	L57
L58:
	movl	-140(%ebp), %eax
	movl	%eax, (%esp)
LEHB22:
	call	__ZN6CTest1C1Ev
LEHE22:
	addl	$8, -140(%ebp)
	subl	$1, %edi
L57:
	cmpl	$-1, %edi
	jne	L58
	leal	4(%ebx), %eax
	jmp	L59
L56:
	movl	%ebx, %eax
L59:
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
	je	L60
	movl	$LC28, 4(%esp)
	movl	%ebx, (%esp)
LEHB27:
	call	__ZN13CDerivedTest1C1EPKc
LEHE27:
	movl	%ebx, %eax
	jmp	L61
L60:
	movl	%ebx, %eax
L61:
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, -40(%ebp)
	cmpl	$0, -36(%ebp)
	je	L62
	movl	-36(%ebp), %eax
	addl	$8, %eax
	jmp	L63
L62:
	movl	$0, %eax
L63:
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
	jmp	L82
L75:
	movl	%eax, %esi
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvPc
	movl	%esi, %eax
	jmp	L65
L74:
L65:
	movl	%eax, (%esp)
LEHB29:
	call	__Unwind_Resume
L77:
	movl	%eax, -140(%ebp)
	testl	%esi, %esi
	je	L67
	movl	$2, %eax
	subl	%edi, %eax
	sall	$3, %eax
	leal	(%esi,%eax), %edi
L68:
	cmpl	%esi, %edi
	je	L67
	subl	$8, %edi
	movl	%edi, (%esp)
	call	__ZN6CTest1D1Ev
	jmp	L68
L67:
	movl	-140(%ebp), %esi
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdaPvPc
	movl	%esi, %eax
	jmp	L69
L76:
L69:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L78:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L79:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L81:
	movl	%eax, %esi
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvPc
	movl	%esi, %eax
	jmp	L73
L80:
L73:
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE29:
L82:
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
LFE84:
	.section	.gcc_except_table,"w"
LLSDA84:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE84-LLSDACSB84
LLSDACSB84:
	.uleb128 LEHB17-LFB84
	.uleb128 LEHE17-LEHB17
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB18-LFB84
	.uleb128 LEHE18-LEHB18
	.uleb128 L74-LFB84
	.uleb128 0
	.uleb128 LEHB19-LFB84
	.uleb128 LEHE19-LEHB19
	.uleb128 L75-LFB84
	.uleb128 0
	.uleb128 LEHB20-LFB84
	.uleb128 LEHE20-LEHB20
	.uleb128 L74-LFB84
	.uleb128 0
	.uleb128 LEHB21-LFB84
	.uleb128 LEHE21-LEHB21
	.uleb128 L76-LFB84
	.uleb128 0
	.uleb128 LEHB22-LFB84
	.uleb128 LEHE22-LEHB22
	.uleb128 L77-LFB84
	.uleb128 0
	.uleb128 LEHB23-LFB84
	.uleb128 LEHE23-LEHB23
	.uleb128 L76-LFB84
	.uleb128 0
	.uleb128 LEHB24-LFB84
	.uleb128 LEHE24-LEHB24
	.uleb128 L78-LFB84
	.uleb128 0
	.uleb128 LEHB25-LFB84
	.uleb128 LEHE25-LEHB25
	.uleb128 L79-LFB84
	.uleb128 0
	.uleb128 LEHB26-LFB84
	.uleb128 LEHE26-LEHB26
	.uleb128 L80-LFB84
	.uleb128 0
	.uleb128 LEHB27-LFB84
	.uleb128 LEHE27-LEHB27
	.uleb128 L81-LFB84
	.uleb128 0
	.uleb128 LEHB28-LFB84
	.uleb128 LEHE28-LEHB28
	.uleb128 L80-LFB84
	.uleb128 0
	.uleb128 LEHB29-LFB84
	.uleb128 LEHE29-LEHB29
	.uleb128 0
	.uleb128 0
LLSDACSE84:
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
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC30, (%esp)
LEHB30:
	call	_printf
LEHE30:
	movl	$__ZL19s_buffForTestClass2, %eax
	jmp	L88
L87:
	cmpl	$-1, %edx
	je	L86
	movl	%eax, (%esp)
LEHB31:
	call	__Unwind_Resume
L86:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE31:
L88:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE85:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA85:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT85-LLSDATTD85
LLSDATTD85:
	.byte	0x1
	.uleb128 LLSDACSE85-LLSDACSB85
LLSDACSB85:
	.uleb128 LEHB30-LFB85
	.uleb128 LEHE30-LEHB30
	.uleb128 L87-LFB85
	.uleb128 0x1
	.uleb128 LEHB31-LFB85
	.uleb128 LEHE31-LEHB31
	.uleb128 0
	.uleb128 0
LLSDACSE85:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT85:
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
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC31, (%esp)
LEHB32:
	call	_printf
LEHE32:
	movl	$__ZL19s_buffForTestClass2, %eax
	jmp	L94
L93:
	cmpl	$-1, %edx
	je	L92
	movl	%eax, (%esp)
LEHB33:
	call	__Unwind_Resume
L92:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE33:
L94:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE86:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA86:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT86-LLSDATTD86
LLSDATTD86:
	.byte	0x1
	.uleb128 LLSDACSE86-LLSDACSB86
LLSDACSB86:
	.uleb128 LEHB32-LFB86
	.uleb128 LEHE32-LEHB32
	.uleb128 L93-LFB86
	.uleb128 0x1
	.uleb128 LEHB33-LFB86
	.uleb128 LEHE33-LEHB33
	.uleb128 0
	.uleb128 0
LLSDACSE86:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT86:
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
LFB87:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA87
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
	jmp	L99
L98:
	cmpl	$-1, %edx
	je	L97
	movl	%eax, (%esp)
LEHB35:
	call	__Unwind_Resume
L97:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE35:
L99:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE87:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA87:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT87-LLSDATTD87
LLSDATTD87:
	.byte	0x1
	.uleb128 LLSDACSE87-LLSDACSB87
LLSDACSB87:
	.uleb128 LEHB34-LFB87
	.uleb128 LEHE34-LEHB34
	.uleb128 L98-LFB87
	.uleb128 0x1
	.uleb128 LEHB35-LFB87
	.uleb128 LEHE35-LEHB35
	.uleb128 0
	.uleb128 0
LLSDACSE87:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT87:
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
LFB88:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA88
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
	jmp	L104
L103:
	cmpl	$-1, %edx
	je	L102
	movl	%eax, (%esp)
LEHB37:
	call	__Unwind_Resume
L102:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE37:
L104:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE88:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA88:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT88-LLSDATTD88
LLSDATTD88:
	.byte	0x1
	.uleb128 LLSDACSE88-LLSDACSB88
LLSDACSB88:
	.uleb128 LEHB36-LFB88
	.uleb128 LEHE36-LEHB36
	.uleb128 L103-LFB88
	.uleb128 0x1
	.uleb128 LEHB37-LFB88
	.uleb128 LEHE37-LEHB37
	.uleb128 0
	.uleb128 0
LLSDACSE88:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT88:
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
LFB91:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA91
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
	jmp	L108
L107:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest2D1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB40:
	call	__Unwind_Resume
LEHE40:
L108:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE91:
	.section	.gcc_except_table,"w"
LLSDA91:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE91-LLSDACSB91
LLSDACSB91:
	.uleb128 LEHB38-LFB91
	.uleb128 LEHE38-LEHB38
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB39-LFB91
	.uleb128 LEHE39-LEHB39
	.uleb128 L107-LFB91
	.uleb128 0
	.uleb128 LEHB40-LFB91
	.uleb128 LEHE40-LEHB40
	.uleb128 0
	.uleb128 0
LLSDACSE91:
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
LFB93:
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
LFE93:
	.section	.text$_ZN6CTest2C1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest2C1EPKc
	.def	__ZN6CTest2C1EPKc;	.scl	2;	.type	32;	.endef
__ZN6CTest2C1EPKc:
LFB94:
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
LFE94:
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
LFB96:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA96
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
	je	L111
	movl	$12, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest2dlEPvj
L111:
	leave
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
LLSDACSE96:
	.section	.text$_ZN6CTest2D2Ev,"x"
	.linkonce discard
	.section	.text$_ZN6CTest2D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest2D1Ev
	.def	__ZN6CTest2D1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest2D1Ev:
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
	movl	$__ZTV6CTest2+8, (%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC36, (%esp)
	call	_printf
	movl	$0, %eax
	testl	%eax, %eax
	je	L114
	movl	$12, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest2dlEPvj
L114:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE97:
	.section	.gcc_except_table,"w"
LLSDA97:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE97-LLSDACSB97
LLSDACSB97:
LLSDACSE97:
	.section	.text$_ZN6CTest2D1Ev,"x"
	.linkonce discard
	.section	.text$_ZN6CTest2D0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest2D0Ev
	.def	__ZN6CTest2D0Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest2D0Ev:
LFB98:
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
LFE98:
	.section .rdata,"dr"
LC37:
	.ascii "CTest2ex::delete(p=0x%p)\12\0"
	.section	.text$_ZN8CTest2exdlEPv,"x"
	.linkonce discard
	.globl	__ZN8CTest2exdlEPv
	.def	__ZN8CTest2exdlEPv;	.scl	2;	.type	32;	.endef
__ZN8CTest2exdlEPv:
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
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC37, (%esp)
LEHB41:
	call	_printf
LEHE41:
	jmp	L123
L122:
	cmpl	$-1, %edx
	je	L121
	movl	%eax, (%esp)
LEHB42:
	call	__Unwind_Resume
L121:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE42:
L123:
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
	.uleb128 LEHB41-LFB100
	.uleb128 LEHE41-LEHB41
	.uleb128 L122-LFB100
	.uleb128 0x1
	.uleb128 LEHB42-LFB100
	.uleb128 LEHE42-LEHB42
	.uleb128 0
	.uleb128 0
LLSDACSE100:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT100:
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
LFB102:
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
LFE102:
	.section .rdata,"dr"
LC39:
	.ascii "CTest2ex::Destructor\0"
	.section	.text$_ZN8CTest2exD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest2exD2Ev
	.def	__ZN8CTest2exD2Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest2exD2Ev:
LFB105:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA105
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
	je	L125
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN8CTest2exdlEPv
L125:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE105:
	.section	.gcc_except_table,"w"
LLSDA105:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE105-LLSDACSB105
LLSDACSB105:
LLSDACSE105:
	.section	.text$_ZN8CTest2exD2Ev,"x"
	.linkonce discard
	.section	.text$_ZN8CTest2exD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest2exD1Ev
	.def	__ZN8CTest2exD1Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest2exD1Ev:
LFB106:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA106
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
	je	L128
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN8CTest2exdlEPv
L128:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE106:
	.section	.gcc_except_table,"w"
LLSDA106:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE106-LLSDACSB106
LLSDACSB106:
LLSDACSE106:
	.section	.text$_ZN8CTest2exD1Ev,"x"
	.linkonce discard
	.section	.text$_ZN8CTest2exD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8CTest2exD0Ev
	.def	__ZN8CTest2exD0Ev;	.scl	2;	.type	32;	.endef
__ZN8CTest2exD0Ev:
LFB107:
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
LFE107:
	.section .rdata,"dr"
LC40:
	.ascii "CDerivedTest2::new(size=%d)\12\0"
	.section	.text$_ZN13CDerivedTest2nwEj,"x"
	.linkonce discard
	.globl	__ZN13CDerivedTest2nwEj
	.def	__ZN13CDerivedTest2nwEj;	.scl	2;	.type	32;	.endef
__ZN13CDerivedTest2nwEj:
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
	movl	%eax, 4(%esp)
	movl	$LC40, (%esp)
LEHB43:
	call	_printf
LEHE43:
	movl	$__ZL19s_buffForTestClass2, %eax
	jmp	L138
L137:
	cmpl	$-1, %edx
	je	L136
	movl	%eax, (%esp)
LEHB44:
	call	__Unwind_Resume
L136:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE44:
L138:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE108:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA108:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT108-LLSDATTD108
LLSDATTD108:
	.byte	0x1
	.uleb128 LLSDACSE108-LLSDACSB108
LLSDACSB108:
	.uleb128 LEHB43-LFB108
	.uleb128 LEHE43-LEHB43
	.uleb128 L137-LFB108
	.uleb128 0x1
	.uleb128 LEHB44-LFB108
	.uleb128 LEHE44-LEHB44
	.uleb128 0
	.uleb128 0
LLSDACSE108:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT108:
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
	movl	%eax, 4(%esp)
	movl	$LC41, (%esp)
LEHB45:
	call	_printf
LEHE45:
	jmp	L143
L142:
	cmpl	$-1, %edx
	je	L141
	movl	%eax, (%esp)
LEHB46:
	call	__Unwind_Resume
L141:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE46:
L143:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE109:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA109:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT109-LLSDATTD109
LLSDATTD109:
	.byte	0x1
	.uleb128 LLSDACSE109-LLSDACSB109
LLSDACSB109:
	.uleb128 LEHB45-LFB109
	.uleb128 LEHE45-LEHB45
	.uleb128 L142-LFB109
	.uleb128 0x1
	.uleb128 LEHB46-LFB109
	.uleb128 LEHE46-LEHB46
	.uleb128 0
	.uleb128 0
LLSDACSE109:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT109:
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
LFB115:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA115
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
	jmp	L149
L148:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__ZN8CTest2exD2Ev
	jmp	L146
L147:
	movl	%eax, %ebx
L146:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest2D2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB50:
	call	__Unwind_Resume
LEHE50:
L149:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE115:
	.section	.gcc_except_table,"w"
LLSDA115:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE115-LLSDACSB115
LLSDACSB115:
	.uleb128 LEHB47-LFB115
	.uleb128 LEHE47-LEHB47
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB48-LFB115
	.uleb128 LEHE48-LEHB48
	.uleb128 L147-LFB115
	.uleb128 0
	.uleb128 LEHB49-LFB115
	.uleb128 LEHE49-LEHB49
	.uleb128 L148-LFB115
	.uleb128 0
	.uleb128 LEHB50-LFB115
	.uleb128 LEHE50-LEHB50
	.uleb128 0
	.uleb128 0
LLSDACSE115:
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
	je	L150
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CDerivedTest2dlEPv
L150:
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
	.section	.text$_ZN13CDerivedTest2D1Ev,"x"
	.linkonce discard
	.section	.text$_ZThn12_N13CDerivedTest2D1Ev,"x"
	.linkonce discard
	.globl	__ZThn12_N13CDerivedTest2D1Ev
	.def	__ZThn12_N13CDerivedTest2D1Ev;	.scl	2;	.type	32;	.endef
__ZThn12_N13CDerivedTest2D1Ev:
LFB2437:
	.cfi_startproc
	subl	$12, 4(%esp)
	jmp	__ZN13CDerivedTest2D1Ev
	.cfi_endproc
LFE2437:
	.section	.text$_ZN13CDerivedTest2D0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CDerivedTest2D0Ev
	.def	__ZN13CDerivedTest2D0Ev;	.scl	2;	.type	32;	.endef
__ZN13CDerivedTest2D0Ev:
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
	call	__ZN13CDerivedTest2D1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CDerivedTest2dlEPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE119:
	.section	.text$_ZThn12_N13CDerivedTest2D0Ev,"x"
	.linkonce discard
	.globl	__ZThn12_N13CDerivedTest2D0Ev
	.def	__ZThn12_N13CDerivedTest2D0Ev;	.scl	2;	.type	32;	.endef
__ZThn12_N13CDerivedTest2D0Ev:
LFB2438:
	.cfi_startproc
	subl	$12, 4(%esp)
	jmp	__ZN13CDerivedTest2D0Ev
	.cfi_endproc
LFE2438:
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
LFB120:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA120
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
	je	L156
	movl	$LC46, 4(%esp)
	movl	%ebx, (%esp)
LEHB52:
	call	__ZN6CTest2C1EPKc
LEHE52:
	movl	%ebx, %eax
	jmp	L157
L156:
	movl	%ebx, %eax
L157:
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
LEHB53:
	call	_printf
	cmpl	$0, -28(%ebp)
	je	L158
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
L158:
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
	je	L159
	movl	$3, (%ebx)
	leal	4(%ebx), %edi
	movl	$2, %esi
	movl	%edi, -60(%ebp)
	jmp	L160
L161:
	movl	-60(%ebp), %eax
	movl	%eax, (%esp)
LEHB54:
	call	__ZN6CTest2C1Ev
LEHE54:
	addl	$12, -60(%ebp)
	subl	$1, %esi
L160:
	cmpl	$-1, %esi
	jne	L161
	leal	4(%ebx), %eax
	jmp	L162
L159:
	movl	%ebx, %eax
L162:
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
	je	L163
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
L165:
	cmpl	-32(%ebp), %ebx
	je	L164
	subl	$12, %ebx
	movl	(%ebx), %eax
	movl	(%eax), %eax
	movl	%ebx, (%esp)
	call	*%eax
	jmp	L165
L164:
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
L163:
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
	je	L166
	movl	$LC48, 4(%esp)
	movl	%ebx, (%esp)
LEHB56:
	call	__ZN13CDerivedTest2C1EPKc
LEHE56:
	movl	%ebx, %eax
	jmp	L167
L166:
	movl	%ebx, %eax
L167:
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, -40(%ebp)
	cmpl	$0, -36(%ebp)
	je	L168
	movl	-36(%ebp), %eax
	addl	$12, %eax
	jmp	L169
L168:
	movl	$0, %eax
L169:
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
	je	L179
	movl	-44(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-44(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	jmp	L179
L176:
	movl	%eax, %esi
	movl	$12, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN6CTest2dlEPvj
	movl	%esi, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
L177:
	movl	%eax, -60(%ebp)
	testl	%edi, %edi
	je	L173
	movl	$2, %eax
	subl	%esi, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%edi,%eax), %esi
L174:
	cmpl	%edi, %esi
	je	L173
	subl	$12, %esi
	movl	(%esi), %eax
	movl	(%eax), %eax
	movl	%esi, (%esp)
	call	*%eax
	jmp	L174
L173:
	movl	-60(%ebp), %esi
	movl	$40, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZN6CTest2daEPvj
	movl	%esi, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
L178:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZN13CDerivedTest2dlEPv
	movl	%esi, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE57:
L179:
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
LFE120:
	.section	.gcc_except_table,"w"
LLSDA120:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE120-LLSDACSB120
LLSDACSB120:
	.uleb128 LEHB51-LFB120
	.uleb128 LEHE51-LEHB51
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB52-LFB120
	.uleb128 LEHE52-LEHB52
	.uleb128 L176-LFB120
	.uleb128 0
	.uleb128 LEHB53-LFB120
	.uleb128 LEHE53-LEHB53
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB54-LFB120
	.uleb128 LEHE54-LEHB54
	.uleb128 L177-LFB120
	.uleb128 0
	.uleb128 LEHB55-LFB120
	.uleb128 LEHE55-LEHB55
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB56-LFB120
	.uleb128 LEHE56-LEHB56
	.uleb128 L178-LFB120
	.uleb128 0
	.uleb128 LEHB57-LFB120
	.uleb128 LEHE57-LEHB57
	.uleb128 0
	.uleb128 0
LLSDACSE120:
	.text
	.section	.text$_ZN16CTest3Singleton111getSigletonEv,"x"
	.linkonce discard
	.globl	__ZN16CTest3Singleton111getSigletonEv
	.def	__ZN16CTest3Singleton111getSigletonEv;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton111getSigletonEv:
LFB121:
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
LFE121:
	.section	.text$_ZNK16CTest3Singleton17getDataEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK16CTest3Singleton17getDataEv
	.def	__ZNK16CTest3Singleton17getDataEv;	.scl	2;	.type	32;	.endef
__ZNK16CTest3Singleton17getDataEv:
LFB122:
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
LFE122:
	.section	.text$_ZN16CTest3Singleton17setDataEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16CTest3Singleton17setDataEi
	.def	__ZN16CTest3Singleton17setDataEi;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton17setDataEi:
LFB123:
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
LFE123:
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
LFB126:
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
LFE126:
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
LFB129:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA129
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
LFE129:
	.section	.gcc_except_table,"w"
LLSDA129:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE129-LLSDACSB129
LLSDACSB129:
LLSDACSE129:
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
LFB130:
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
LFE130:
	.globl	__Z17updateData_typeA1v
	.def	__Z17updateData_typeA1v;	.scl	2;	.type	32;	.endef
__Z17updateData_typeA1v:
LFB131:
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
LFE131:
	.section	.text$_ZN16CTest3Singleton211getSigletonEv,"x"
	.linkonce discard
	.globl	__ZN16CTest3Singleton211getSigletonEv
	.def	__ZN16CTest3Singleton211getSigletonEv;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton211getSigletonEv:
LFB132:
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
LFE132:
	.section	.text$_ZNK16CTest3Singleton27getDataEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK16CTest3Singleton27getDataEv
	.def	__ZNK16CTest3Singleton27getDataEv;	.scl	2;	.type	32;	.endef
__ZNK16CTest3Singleton27getDataEv:
LFB133:
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
LFE133:
	.section	.text$_ZN16CTest3Singleton27setDataEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN16CTest3Singleton27setDataEi
	.def	__ZN16CTest3Singleton27setDataEi;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton27setDataEi:
LFB134:
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
LFE134:
	.section	.text$_ZN16CTest3Singleton2nwEj,"x"
	.linkonce discard
	.globl	__ZN16CTest3Singleton2nwEj
	.def	__ZN16CTest3Singleton2nwEj;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton2nwEj:
LFB135:
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
LFE135:
	.section	.text$_ZN16CTest3Singleton2dlEPv,"x"
	.linkonce discard
	.globl	__ZN16CTest3Singleton2dlEPv
	.def	__ZN16CTest3Singleton2dlEPv;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton2dlEPv:
LFB136:
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
LFE136:
	.section	.text$_ZN16CTest3Singleton26createEv,"x"
	.linkonce discard
	.globl	__ZN16CTest3Singleton26createEv
	.def	__ZN16CTest3Singleton26createEv;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton26createEv:
LFB137:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA137
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
	je	L199
	jmp	L198
L199:
	movl	$4, (%esp)
	call	__ZN16CTest3Singleton2nwEj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L201
	movl	%ebx, (%esp)
LEHB58:
	call	__ZN16CTest3Singleton2C1Ev
LEHE58:
	movl	%ebx, %eax
	jmp	L202
L201:
	movl	%ebx, %eax
L202:
	movl	%eax, __ZN16CTest3Singleton211m_singletonE
	jmp	L198
L204:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZN16CTest3Singleton2dlEPv
	movl	%esi, %eax
	movl	%eax, (%esp)
LEHB59:
	call	__Unwind_Resume
LEHE59:
L198:
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
LFE137:
	.section	.gcc_except_table,"w"
LLSDA137:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE137-LLSDACSB137
LLSDACSB137:
	.uleb128 LEHB58-LFB137
	.uleb128 LEHE58-LEHB58
	.uleb128 L204-LFB137
	.uleb128 0
	.uleb128 LEHB59-LFB137
	.uleb128 LEHE59-LEHB59
	.uleb128 0
	.uleb128 0
LLSDACSE137:
	.section	.text$_ZN16CTest3Singleton26createEv,"x"
	.linkonce discard
	.section	.text$_ZN16CTest3Singleton27destroyEv,"x"
	.linkonce discard
	.globl	__ZN16CTest3Singleton27destroyEv
	.def	__ZN16CTest3Singleton27destroyEv;	.scl	2;	.type	32;	.endef
__ZN16CTest3Singleton27destroyEv:
LFB138:
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
	jne	L206
	jmp	L205
L206:
	movl	__ZN16CTest3Singleton211m_singletonE, %ebx
	testl	%ebx, %ebx
	je	L208
	movl	%ebx, (%esp)
	call	__ZN16CTest3Singleton2D1Ev
	movl	%ebx, (%esp)
	call	__ZN16CTest3Singleton2dlEPv
L208:
	movl	$0, __ZN16CTest3Singleton211m_singletonE
L205:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE138:
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
LFB141:
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
LFE141:
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
LFB144:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA144
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
LFE144:
	.section	.gcc_except_table,"w"
LLSDA144:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE144-LLSDACSB144
LLSDACSB144:
LLSDACSE144:
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
LFB145:
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
LFE145:
	.globl	__Z17updateData_typeA2v
	.def	__Z17updateData_typeA2v;	.scl	2;	.type	32;	.endef
__Z17updateData_typeA2v:
LFB146:
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
LFE146:
	.globl	__Z26deleteIntentionally_typeA2v
	.def	__Z26deleteIntentionally_typeA2v;	.scl	2;	.type	32;	.endef
__Z26deleteIntentionally_typeA2v:
LFB147:
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
LFE147:
	.section	.text$_ZNK6CTest37getDataEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK6CTest37getDataEv
	.def	__ZNK6CTest37getDataEv;	.scl	2;	.type	32;	.endef
__ZNK6CTest37getDataEv:
LFB153:
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
LFE153:
	.section	.text$_ZN6CTest37setDataEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest37setDataEi
	.def	__ZN6CTest37setDataEi;	.scl	2;	.type	32;	.endef
__ZN6CTest37setDataEi:
LFB154:
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
LFE154:
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
LFB157:
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
LFE157:
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
LFB160:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA160
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
LFE160:
	.section	.gcc_except_table,"w"
LLSDA160:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE160-LLSDACSB160
LLSDACSB160:
LLSDACSE160:
	.section	.text$_ZN6CTest3D1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
LC56:
	.ascii "singleton->getData()=%d\12\0"
	.text
	.globl	__Z15printData_typeBv
	.def	__Z15printData_typeBv;	.scl	2;	.type	32;	.endef
__Z15printData_typeBv:
LFB161:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA161
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
	jmp	L224
L223:
	movl	%eax, (%esp)
LEHB61:
	call	__Unwind_Resume
LEHE61:
L224:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE161:
	.section	.gcc_except_table,"w"
LLSDA161:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE161-LLSDACSB161
LLSDACSB161:
	.uleb128 LEHB60-LFB161
	.uleb128 LEHE60-LEHB60
	.uleb128 L223-LFB161
	.uleb128 0
	.uleb128 LEHB61-LFB161
	.uleb128 LEHE61-LEHB61
	.uleb128 0
	.uleb128 0
LLSDACSE161:
	.text
	.globl	__Z16updateData_typeBv
	.def	__Z16updateData_typeBv;	.scl	2;	.type	32;	.endef
__Z16updateData_typeBv:
LFB162:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA162
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
	jmp	L228
L227:
	movl	%eax, (%esp)
LEHB63:
	call	__Unwind_Resume
LEHE63:
L228:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE162:
	.section	.gcc_except_table,"w"
LLSDA162:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE162-LLSDACSB162
LLSDACSB162:
	.uleb128 LEHB62-LFB162
	.uleb128 LEHE62-LEHB62
	.uleb128 L227-LFB162
	.uleb128 0
	.uleb128 LEHB63-LFB162
	.uleb128 LEHE63-LEHB63
	.uleb128 0
	.uleb128 0
LLSDACSE162:
	.text
	.globl	__Z25deleteIntentionally_typeBv
	.def	__Z25deleteIntentionally_typeBv;	.scl	2;	.type	32;	.endef
__Z25deleteIntentionally_typeBv:
LFB163:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA163
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
	jmp	L232
L231:
	movl	%eax, (%esp)
LEHB65:
	call	__Unwind_Resume
LEHE65:
L232:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE163:
	.section	.gcc_except_table,"w"
LLSDA163:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE163-LLSDACSB163
LLSDACSB163:
	.uleb128 LEHB64-LFB163
	.uleb128 LEHE64-LEHB64
	.uleb128 L231-LFB163
	.uleb128 0
	.uleb128 LEHB65-LFB163
	.uleb128 LEHE65-LEHB65
	.uleb128 0
	.uleb128 0
LLSDACSE163:
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
LFB164:
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
LFE164:
	.section	.text$_ZN15IStackAllocatorD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15IStackAllocatorD2Ev
	.def	__ZN15IStackAllocatorD2Ev;	.scl	2;	.type	32;	.endef
__ZN15IStackAllocatorD2Ev:
LFB166:
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
	je	L234
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L234:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE166:
	.section	.text$_ZN15IStackAllocatorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15IStackAllocatorD1Ev
	.def	__ZN15IStackAllocatorD1Ev;	.scl	2;	.type	32;	.endef
__ZN15IStackAllocatorD1Ev:
LFB167:
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
	je	L237
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L237:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE167:
	.section	.text$_ZN15IStackAllocatorD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15IStackAllocatorD0Ev
	.def	__ZN15IStackAllocatorD0Ev;	.scl	2;	.type	32;	.endef
__ZN15IStackAllocatorD0Ev:
LFB168:
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
LFE168:
	.section	.text$_ZNK15CStackAllocator8getTotalEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator8getTotalEv
	.def	__ZNK15CStackAllocator8getTotalEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator8getTotalEv:
LFB169:
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
LFE169:
	.section	.text$_ZNK15CStackAllocator7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator7getUsedEv
	.def	__ZNK15CStackAllocator7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator7getUsedEv:
LFB170:
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
LFE170:
	.section	.text$_ZNK15CStackAllocator9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator9getRemainEv
	.def	__ZNK15CStackAllocator9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator9getRemainEv:
LFB171:
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
LFE171:
	.section	.text$_ZNK15CStackAllocator7getBuffEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator7getBuffEv
	.def	__ZNK15CStackAllocator7getBuffEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator7getBuffEv:
LFB172:
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
LFE172:
	.section	.text$_ZNK15CStackAllocator10getNowPtrNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator10getNowPtrNEv
	.def	__ZNK15CStackAllocator10getNowPtrNEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator10getNowPtrNEv:
LFB173:
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
LFE173:
	.section	.text$_ZNK15CStackAllocator9getNowPtrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator9getNowPtrEv
	.def	__ZNK15CStackAllocator9getNowPtrEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator9getNowPtrEv:
LFB174:
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
LFE174:
	.section	.text$_ZNK15CStackAllocator10getMarkerNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator10getMarkerNEv
	.def	__ZNK15CStackAllocator10getMarkerNEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator10getMarkerNEv:
LFB175:
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
LFE175:
	.section	.text$_ZNK15CStackAllocator9getMarkerEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CStackAllocator9getMarkerEv
	.def	__ZNK15CStackAllocator9getMarkerEv;	.scl	2;	.type	32;	.endef
__ZNK15CStackAllocator9getMarkerEv:
LFB176:
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
LFE176:
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
LFB177:
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
	je	L259
	movl	-12(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	testl	%eax, %eax
	je	L260
	movl	-12(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	movl	16(%ebp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	jmp	L262
L260:
	movl	$0, %eax
	jmp	L262
L259:
	movl	$0, %eax
L262:
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
	jae	L263
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
	jmp	L264
L263:
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	addl	%edx, %eax
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	-24(%ebp), %eax
L264:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE177:
	.section	.text$_ZN15CStackAllocator5allocEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator5allocEjj
	.def	__ZN15CStackAllocator5allocEjj;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator5allocEjj:
LFB178:
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
LFE178:
	.section	.text$_ZN15CStackAllocator5backNEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator5backNEj
	.def	__ZN15CStackAllocator5backNEj;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator5backNEj:
LFB179:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	cmpl	12(%ebp), %eax
	ja	L268
	jmp	L267
L268:
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 12(%eax)
L267:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE179:
	.section	.text$_ZN15CStackAllocator4backEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator4backEj
	.def	__ZN15CStackAllocator4backEj;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator4backEj:
LFB180:
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
LFE180:
	.section	.text$_ZN15CStackAllocator5backNEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator5backNEPKv
	.def	__ZN15CStackAllocator5backNEPKv;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator5backNEPKv:
LFB181:
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
LFE181:
	.section	.text$_ZN15CStackAllocator4backEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator4backEPKv
	.def	__ZN15CStackAllocator4backEPKv;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator4backEPKv:
LFB182:
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
LFE182:
	.section	.text$_ZN15CStackAllocator6clearNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator6clearNEv
	.def	__ZN15CStackAllocator6clearNEv;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator6clearNEv:
LFB183:
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
LFE183:
	.section	.text$_ZN15CStackAllocator5clearEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator5clearEv
	.def	__ZN15CStackAllocator5clearEv;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator5clearEv:
LFB184:
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
LFE184:
	.section	.text$_ZN15CStackAllocator8clearAllEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocator8clearAllEv
	.def	__ZN15CStackAllocator8clearAllEv;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocator8clearAllEv:
LFB185:
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
LFE185:
	.section	.text$_ZN15IStackAllocatorC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15IStackAllocatorC2Ev
	.def	__ZN15IStackAllocatorC2Ev;	.scl	2;	.type	32;	.endef
__ZN15IStackAllocatorC2Ev:
LFB188:
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
LFE188:
	.section	.text$_ZN15CStackAllocatorC2EPvj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocatorC2EPvj
	.def	__ZN15CStackAllocatorC2EPvj;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocatorC2EPvj:
LFB190:
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
LFE190:
	.section	.text$_ZN15CStackAllocatorD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocatorD2Ev
	.def	__ZN15CStackAllocatorD2Ev;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocatorD2Ev:
LFB193:
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
	je	L279
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L279:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE193:
	.section	.text$_ZN15CStackAllocatorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocatorD1Ev
	.def	__ZN15CStackAllocatorD1Ev;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocatorD1Ev:
LFB194:
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
	je	L282
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L282:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE194:
	.section	.text$_ZN15CStackAllocatorD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CStackAllocatorD0Ev
	.def	__ZN15CStackAllocatorD0Ev;	.scl	2;	.type	32;	.endef
__ZN15CStackAllocatorD0Ev:
LFB195:
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
LFE195:
	.section .rdata,"dr"
	.align 4
LC62:
	.ascii "placement new(size=%d, stack_allocator.marker=%d, align=%d)\12\0"
	.text
	.globl	__ZnwjR15CStackAllocatorj
	.def	__ZnwjR15CStackAllocatorj;	.scl	2;	.type	32;	.endef
__ZnwjR15CStackAllocatorj:
LFB196:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA196
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
	jmp	L292
L291:
	cmpl	$-1, %edx
	je	L290
	movl	%eax, (%esp)
LEHB67:
	call	__Unwind_Resume
L290:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE67:
L292:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE196:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA196:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT196-LLSDATTD196
LLSDATTD196:
	.byte	0x1
	.uleb128 LLSDACSE196-LLSDACSB196
LLSDACSB196:
	.uleb128 LEHB66-LFB196
	.uleb128 LEHE66-LEHB66
	.uleb128 L291-LFB196
	.uleb128 0x1
	.uleb128 LEHB67-LFB196
	.uleb128 LEHE67-LEHB67
	.uleb128 0
	.uleb128 0
LLSDACSE196:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT196:
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
LFB197:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA197
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
	jmp	L298
L297:
	cmpl	$-1, %edx
	je	L296
	movl	%eax, (%esp)
LEHB69:
	call	__Unwind_Resume
L296:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE69:
L298:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE197:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA197:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT197-LLSDATTD197
LLSDATTD197:
	.byte	0x1
	.uleb128 LLSDACSE197-LLSDACSB197
LLSDACSB197:
	.uleb128 LEHB68-LFB197
	.uleb128 LEHE68-LEHB68
	.uleb128 L297-LFB197
	.uleb128 0x1
	.uleb128 LEHB69-LFB197
	.uleb128 LEHE69-LEHB69
	.uleb128 0
	.uleb128 0
LLSDACSE197:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT197:
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
LFB198:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA198
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
	jmp	L303
L302:
	cmpl	$-1, %edx
	je	L301
	movl	%eax, (%esp)
LEHB71:
	call	__Unwind_Resume
L301:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE71:
L303:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE198:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA198:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT198-LLSDATTD198
LLSDATTD198:
	.byte	0x1
	.uleb128 LLSDACSE198-LLSDACSB198
LLSDACSB198:
	.uleb128 LEHB70-LFB198
	.uleb128 LEHE70-LEHB70
	.uleb128 L302-LFB198
	.uleb128 0x1
	.uleb128 LEHB71-LFB198
	.uleb128 LEHE71-LEHB71
	.uleb128 0
	.uleb128 0
LLSDACSE198:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT198:
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
LFB199:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA199
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
	jmp	L308
L307:
	cmpl	$-1, %edx
	je	L306
	movl	%eax, (%esp)
LEHB73:
	call	__Unwind_Resume
L306:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE73:
L308:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE199:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA199:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT199-LLSDATTD199
LLSDATTD199:
	.byte	0x1
	.uleb128 LLSDACSE199-LLSDACSB199
LLSDACSB199:
	.uleb128 LEHB72-LFB199
	.uleb128 LEHE72-LEHB72
	.uleb128 L307-LFB199
	.uleb128 0x1
	.uleb128 LEHB73-LFB199
	.uleb128 LEHE73-LEHB73
	.uleb128 0
	.uleb128 0
LLSDACSE199:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT199:
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
LFB206:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA206
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
	jmp	L312
L311:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN7CTest4aD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB76:
	call	__Unwind_Resume
LEHE76:
L312:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE206:
	.section	.gcc_except_table,"w"
LLSDA206:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE206-LLSDACSB206
LLSDACSB206:
	.uleb128 LEHB74-LFB206
	.uleb128 LEHE74-LEHB74
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB75-LFB206
	.uleb128 LEHE75-LEHB75
	.uleb128 L311-LFB206
	.uleb128 0
	.uleb128 LEHB76-LFB206
	.uleb128 LEHE76-LEHB76
	.uleb128 0
	.uleb128 0
LLSDACSE206:
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
LFB209:
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
LFE209:
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
LFB212:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA212
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
LFE212:
	.section	.gcc_except_table,"w"
LLSDA212:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE212-LLSDACSB212
LLSDACSB212:
LLSDACSE212:
	.section	.text$_ZN7CTest4aD1Ev,"x"
	.linkonce discard
	.section	.text$_ZNK19CDualStackAllocator8getTotalEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator8getTotalEv
	.def	__ZNK19CDualStackAllocator8getTotalEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator8getTotalEv:
LFB213:
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
LFE213:
	.section	.text$_ZNK19CDualStackAllocator7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator7getUsedEv
	.def	__ZNK19CDualStackAllocator7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator7getUsedEv:
LFB214:
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
LFE214:
	.section	.text$_ZNK19CDualStackAllocator9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator9getRemainEv
	.def	__ZNK19CDualStackAllocator9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator9getRemainEv:
LFB215:
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
LFE215:
	.section	.text$_ZNK19CDualStackAllocator17getDefaultOrderedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator17getDefaultOrderedEv
	.def	__ZNK19CDualStackAllocator17getDefaultOrderedEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator17getDefaultOrderedEv:
LFB216:
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
LFE216:
	.section	.text$_ZN19CDualStackAllocator17setDefaultOrderedENS_9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator17setDefaultOrderedENS_9E_ORDEREDE
	.def	__ZN19CDualStackAllocator17setDefaultOrderedENS_9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator17setDefaultOrderedENS_9E_ORDEREDE:
LFB217:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 20(%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE217:
	.section	.text$_ZNK19CDualStackAllocator7getBuffEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator7getBuffEv
	.def	__ZNK19CDualStackAllocator7getBuffEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator7getBuffEv:
LFB218:
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
LFE218:
	.section	.text$_ZNK19CDualStackAllocator10getNowPtrNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator10getNowPtrNEv
	.def	__ZNK19CDualStackAllocator10getNowPtrNEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator10getNowPtrNEv:
LFB219:
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
LFE219:
	.section	.text$_ZNK19CDualStackAllocator10getNowPtrREv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator10getNowPtrREv
	.def	__ZNK19CDualStackAllocator10getNowPtrREv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator10getNowPtrREv:
LFB220:
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
LFE220:
	.section	.text$_ZNK19CDualStackAllocator10getNowPtrDEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator10getNowPtrDEv
	.def	__ZNK19CDualStackAllocator10getNowPtrDEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator10getNowPtrDEv:
LFB221:
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
	call	__ZNK19CDualStackAllocator9getNowPtrENS_9E_ORDEREDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE221:
	.section	.text$_ZNK19CDualStackAllocator9getNowPtrENS_9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator9getNowPtrENS_9E_ORDEREDE
	.def	__ZNK19CDualStackAllocator9getNowPtrENS_9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator9getNowPtrENS_9E_ORDEREDE:
LFB222:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L334
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getNowPtrDEv
	jmp	L335
L334:
	cmpl	$-1, 12(%ebp)
	jne	L336
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getNowPtrREv
	jmp	L335
L336:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getNowPtrNEv
L335:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE222:
	.section	.text$_ZNK19CDualStackAllocator9getNowPtrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator9getNowPtrEv
	.def	__ZNK19CDualStackAllocator9getNowPtrEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator9getNowPtrEv:
LFB223:
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
LFE223:
	.section	.text$_ZNK19CDualStackAllocator10getMarkerNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator10getMarkerNEv
	.def	__ZNK19CDualStackAllocator10getMarkerNEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator10getMarkerNEv:
LFB224:
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
LFE224:
	.section	.text$_ZNK19CDualStackAllocator10getMarkerREv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator10getMarkerREv
	.def	__ZNK19CDualStackAllocator10getMarkerREv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator10getMarkerREv:
LFB225:
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
LFE225:
	.section	.text$_ZNK19CDualStackAllocator10getMarkerDEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator10getMarkerDEv
	.def	__ZNK19CDualStackAllocator10getMarkerDEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator10getMarkerDEv:
LFB226:
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
	call	__ZNK19CDualStackAllocator9getMarkerENS_9E_ORDEREDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE226:
	.section	.text$_ZNK19CDualStackAllocator9getMarkerENS_9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator9getMarkerENS_9E_ORDEREDE
	.def	__ZNK19CDualStackAllocator9getMarkerENS_9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator9getMarkerENS_9E_ORDEREDE:
LFB227:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L348
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerDEv
	jmp	L349
L348:
	cmpl	$-1, 12(%ebp)
	jne	L350
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerREv
	jmp	L349
L350:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK19CDualStackAllocator10getMarkerNEv
L349:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE227:
	.section	.text$_ZNK19CDualStackAllocator9getMarkerEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK19CDualStackAllocator9getMarkerEv
	.def	__ZNK19CDualStackAllocator9getMarkerEv;	.scl	2;	.type	32;	.endef
__ZNK19CDualStackAllocator9getMarkerEv:
LFB228:
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
LFE228:
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
LFB229:
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
	je	L356
	movl	-12(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	testl	%eax, %eax
	je	L357
	movl	-12(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	movl	16(%ebp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	jmp	L359
L357:
	movl	$0, %eax
	jmp	L359
L356:
	movl	$0, %eax
L359:
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
	jae	L360
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
	jmp	L361
L360:
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	addl	%edx, %eax
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	-24(%ebp), %eax
L361:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE229:
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
LFB230:
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
	je	L363
	movl	-16(%ebp), %eax
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, %eax
	jmp	L364
L363:
	movl	$0, %eax
L364:
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	subl	12(%ebp), %eax
	subl	-20(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	cmpl	-24(%ebp), %eax
	ja	L365
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	-24(%ebp), %eax
	jae	L366
L365:
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
	jmp	L367
L366:
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
L367:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE230:
	.section	.text$_ZN19CDualStackAllocator6allocDEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator6allocDEjj
	.def	__ZN19CDualStackAllocator6allocDEjj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator6allocDEjj:
LFB231:
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
	call	__ZN19CDualStackAllocator5allocENS_9E_ORDEREDEjj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE231:
	.section	.text$_ZN19CDualStackAllocator5allocENS_9E_ORDEREDEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5allocENS_9E_ORDEREDEjj
	.def	__ZN19CDualStackAllocator5allocENS_9E_ORDEREDEjj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5allocENS_9E_ORDEREDEjj:
LFB232:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L371
	movl	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator6allocDEjj
	jmp	L372
L371:
	cmpl	$-1, 12(%ebp)
	jne	L373
	movl	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator6allocREjj
	jmp	L372
L373:
	movl	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator6allocNEjj
L372:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE232:
	.section	.text$_ZN19CDualStackAllocator5allocEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5allocEjj
	.def	__ZN19CDualStackAllocator5allocEjj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5allocEjj:
LFB233:
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
LFE233:
	.section	.text$_ZN19CDualStackAllocator5backNEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5backNEj
	.def	__ZN19CDualStackAllocator5backNEj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5backNEj:
LFB234:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	cmpl	12(%ebp), %eax
	jae	L379
	jmp	L378
L379:
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 12(%eax)
L378:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE234:
	.section	.text$_ZN19CDualStackAllocator5backNEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5backNEPKv
	.def	__ZN19CDualStackAllocator5backNEPKv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5backNEPKv:
LFB235:
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
LFE235:
	.section	.text$_ZN19CDualStackAllocator5backREj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5backREj
	.def	__ZN19CDualStackAllocator5backREj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5backREj:
LFB236:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	cmpl	12(%ebp), %eax
	ja	L383
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	12(%ebp), %eax
	jae	L384
L383:
	jmp	L382
L384:
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 16(%eax)
L382:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE236:
	.section	.text$_ZN19CDualStackAllocator5backREPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5backREPKv
	.def	__ZN19CDualStackAllocator5backREPKv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5backREPKv:
LFB237:
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
LFE237:
	.section	.text$_ZN19CDualStackAllocator5backDEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5backDEj
	.def	__ZN19CDualStackAllocator5backDEj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5backDEj:
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
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator4backENS_9E_ORDEREDEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE238:
	.section	.text$_ZN19CDualStackAllocator5backDEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5backDEPKv
	.def	__ZN19CDualStackAllocator5backDEPKv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5backDEPKv:
LFB239:
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
	call	__ZN19CDualStackAllocator4backENS_9E_ORDEREDEPKv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE239:
	.section	.text$_ZN19CDualStackAllocator4backENS_9E_ORDEREDEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator4backENS_9E_ORDEREDEj
	.def	__ZN19CDualStackAllocator4backENS_9E_ORDEREDEj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator4backENS_9E_ORDEREDEj:
LFB240:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L390
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backDEj
	jmp	L389
L390:
	cmpl	$-1, 12(%ebp)
	jne	L392
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backREj
	jmp	L389
L392:
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backNEj
L389:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE240:
	.section	.text$_ZN19CDualStackAllocator4backENS_9E_ORDEREDEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator4backENS_9E_ORDEREDEPKv
	.def	__ZN19CDualStackAllocator4backENS_9E_ORDEREDEPKv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator4backENS_9E_ORDEREDEPKv:
LFB241:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L394
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backDEPKv
	jmp	L393
L394:
	cmpl	$-1, 12(%ebp)
	jne	L396
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backREPKv
	jmp	L393
L396:
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5backNEPKv
L393:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE241:
	.section	.text$_ZN19CDualStackAllocator4backEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator4backEj
	.def	__ZN19CDualStackAllocator4backEj;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator4backEj:
LFB242:
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
LFE242:
	.section	.text$_ZN19CDualStackAllocator4backEPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator4backEPKv
	.def	__ZN19CDualStackAllocator4backEPKv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator4backEPKv:
LFB243:
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
LFE243:
	.section	.text$_ZN19CDualStackAllocator6clearNEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator6clearNEv
	.def	__ZN19CDualStackAllocator6clearNEv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator6clearNEv:
LFB244:
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
LFE244:
	.section	.text$_ZN19CDualStackAllocator6clearREv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator6clearREv
	.def	__ZN19CDualStackAllocator6clearREv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator6clearREv:
LFB245:
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
LFE245:
	.section	.text$_ZN19CDualStackAllocator6clearDEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator6clearDEv
	.def	__ZN19CDualStackAllocator6clearDEv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator6clearDEv:
LFB246:
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
	call	__ZN19CDualStackAllocator5clearENS_9E_ORDEREDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE246:
	.section	.text$_ZN19CDualStackAllocator7clearNREv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator7clearNREv
	.def	__ZN19CDualStackAllocator7clearNREv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator7clearNREv:
LFB247:
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
LFE247:
	.section	.text$_ZN19CDualStackAllocator5clearENS_9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5clearENS_9E_ORDEREDE
	.def	__ZN19CDualStackAllocator5clearENS_9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5clearENS_9E_ORDEREDE:
LFB248:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L404
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator6clearDEv
	jmp	L403
L404:
	cmpl	$-1, 12(%ebp)
	jne	L406
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator6clearREv
	jmp	L403
L406:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator6clearNEv
L403:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE248:
	.section	.text$_ZN19CDualStackAllocator5clearEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator5clearEv
	.def	__ZN19CDualStackAllocator5clearEv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator5clearEv:
LFB249:
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
LFE249:
	.section	.text$_ZN19CDualStackAllocator8clearAllEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocator8clearAllEv
	.def	__ZN19CDualStackAllocator8clearAllEv;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocator8clearAllEv:
LFB250:
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
LFE250:
	.section	.text$_ZN19CDualStackAllocatorC2EPvjNS_9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocatorC2EPvjNS_9E_ORDEREDE
	.def	__ZN19CDualStackAllocatorC2EPvjNS_9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocatorC2EPvjNS_9E_ORDEREDE:
LFB252:
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
	movl	8(%ebp), %eax
	movl	20(%ebp), %edx
	movl	%edx, 20(%eax)
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	cmpl	$-1, %eax
	je	L409
	movl	8(%ebp), %eax
	movl	$1, 20(%eax)
L409:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE252:
	.section	.text$_ZN19CDualStackAllocatorD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocatorD2Ev
	.def	__ZN19CDualStackAllocatorD2Ev;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocatorD2Ev:
LFB255:
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
	je	L411
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L411:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE255:
	.section	.text$_ZN19CDualStackAllocatorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocatorD1Ev
	.def	__ZN19CDualStackAllocatorD1Ev;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocatorD1Ev:
LFB256:
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
	je	L414
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L414:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE256:
	.section	.text$_ZN19CDualStackAllocatorD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN19CDualStackAllocatorD0Ev
	.def	__ZN19CDualStackAllocatorD0Ev;	.scl	2;	.type	32;	.endef
__ZN19CDualStackAllocatorD0Ev:
LFB257:
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
LFE257:
	.section .rdata,"dr"
	.align 4
LC71:
	.ascii "placement new(size=%d, dual_allocator.marker=%d,%d, align=%d, ordered=%d)\12\0"
	.text
	.globl	__ZnwjR19CDualStackAllocatorjNS_9E_ORDEREDE
	.def	__ZnwjR19CDualStackAllocatorjNS_9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZnwjR19CDualStackAllocatorjNS_9E_ORDEREDE:
LFB258:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA258
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
	call	__ZN19CDualStackAllocator5allocENS_9E_ORDEREDEjj
LEHE77:
	jmp	L424
L423:
	cmpl	$-1, %edx
	je	L422
	movl	%eax, (%esp)
LEHB78:
	call	__Unwind_Resume
L422:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE78:
L424:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE258:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA258:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT258-LLSDATTD258
LLSDATTD258:
	.byte	0x1
	.uleb128 LLSDACSE258-LLSDACSB258
LLSDACSB258:
	.uleb128 LEHB77-LFB258
	.uleb128 LEHE77-LEHB77
	.uleb128 L423-LFB258
	.uleb128 0x1
	.uleb128 LEHB78-LFB258
	.uleb128 LEHE78-LEHB78
	.uleb128 0
	.uleb128 0
LLSDACSE258:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT258:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC72:
	.ascii "placement new(size=%d, dual_allocator.marker=%d,%d, (align=%d), ordered=%d)\12\0"
	.text
	.globl	__ZnwjR19CDualStackAllocatorNS_9E_ORDEREDE
	.def	__ZnwjR19CDualStackAllocatorNS_9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZnwjR19CDualStackAllocatorNS_9E_ORDEREDE:
LFB259:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA259
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
	call	__ZN19CDualStackAllocator5allocENS_9E_ORDEREDEjj
LEHE79:
	jmp	L430
L429:
	cmpl	$-1, %edx
	je	L428
	movl	%eax, (%esp)
LEHB80:
	call	__Unwind_Resume
L428:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE80:
L430:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE259:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA259:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT259-LLSDATTD259
LLSDATTD259:
	.byte	0x1
	.uleb128 LLSDACSE259-LLSDACSB259
LLSDACSB259:
	.uleb128 LEHB79-LFB259
	.uleb128 LEHE79-LEHB79
	.uleb128 L429-LFB259
	.uleb128 0x1
	.uleb128 LEHB80-LFB259
	.uleb128 LEHE80-LEHB80
	.uleb128 0
	.uleb128 0
LLSDACSE259:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT259:
	.byte	0
	.text
	.globl	__ZnajR19CDualStackAllocatorjNS_9E_ORDEREDE
	.def	__ZnajR19CDualStackAllocatorjNS_9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZnajR19CDualStackAllocatorjNS_9E_ORDEREDE:
LFB260:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA260
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
	call	__ZN19CDualStackAllocator5allocENS_9E_ORDEREDEjj
LEHE81:
	jmp	L436
L435:
	cmpl	$-1, %edx
	je	L434
	movl	%eax, (%esp)
LEHB82:
	call	__Unwind_Resume
L434:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE82:
L436:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE260:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA260:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT260-LLSDATTD260
LLSDATTD260:
	.byte	0x1
	.uleb128 LLSDACSE260-LLSDACSB260
LLSDACSB260:
	.uleb128 LEHB81-LFB260
	.uleb128 LEHE81-LEHB81
	.uleb128 L435-LFB260
	.uleb128 0x1
	.uleb128 LEHB82-LFB260
	.uleb128 LEHE82-LEHB82
	.uleb128 0
	.uleb128 0
LLSDACSE260:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT260:
	.byte	0
	.text
	.globl	__ZnajR19CDualStackAllocatorNS_9E_ORDEREDE
	.def	__ZnajR19CDualStackAllocatorNS_9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZnajR19CDualStackAllocatorNS_9E_ORDEREDE:
LFB261:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA261
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
	call	__ZN19CDualStackAllocator5allocENS_9E_ORDEREDEjj
LEHE83:
	jmp	L442
L441:
	cmpl	$-1, %edx
	je	L440
	movl	%eax, (%esp)
LEHB84:
	call	__Unwind_Resume
L440:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE84:
L442:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE261:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA261:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT261-LLSDATTD261
LLSDATTD261:
	.byte	0x1
	.uleb128 LLSDACSE261-LLSDACSB261
LLSDACSB261:
	.uleb128 LEHB83-LFB261
	.uleb128 LEHE83-LEHB83
	.uleb128 L441-LFB261
	.uleb128 0x1
	.uleb128 LEHB84-LFB261
	.uleb128 LEHE84-LEHB84
	.uleb128 0
	.uleb128 0
LLSDACSE261:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT261:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC73:
	.ascii "placement delete(p=0x%p, dual_allocator.marker=%d,%d, align)\12\0"
	.text
	.globl	__ZdlPvR19CDualStackAllocatorjNS0_9E_ORDEREDE
	.def	__ZdlPvR19CDualStackAllocatorjNS0_9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZdlPvR19CDualStackAllocatorjNS0_9E_ORDEREDE:
LFB262:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA262
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
	jmp	L447
L446:
	cmpl	$-1, %edx
	je	L445
	movl	%eax, (%esp)
LEHB86:
	call	__Unwind_Resume
L445:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE86:
L447:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE262:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA262:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT262-LLSDATTD262
LLSDATTD262:
	.byte	0x1
	.uleb128 LLSDACSE262-LLSDACSB262
LLSDACSB262:
	.uleb128 LEHB85-LFB262
	.uleb128 LEHE85-LEHB85
	.uleb128 L446-LFB262
	.uleb128 0x1
	.uleb128 LEHB86-LFB262
	.uleb128 LEHE86-LEHB86
	.uleb128 0
	.uleb128 0
LLSDACSE262:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT262:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC74:
	.ascii "placement delete(p=0x%p, dual_allocator.marker=%d,%d)\12\0"
	.text
	.globl	__ZdlPvR19CDualStackAllocatorNS0_9E_ORDEREDE
	.def	__ZdlPvR19CDualStackAllocatorNS0_9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZdlPvR19CDualStackAllocatorNS0_9E_ORDEREDE:
LFB263:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA263
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
	jmp	L452
L451:
	cmpl	$-1, %edx
	je	L450
	movl	%eax, (%esp)
LEHB88:
	call	__Unwind_Resume
L450:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE88:
L452:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE263:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA263:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT263-LLSDATTD263
LLSDATTD263:
	.byte	0x1
	.uleb128 LLSDACSE263-LLSDACSB263
LLSDACSB263:
	.uleb128 LEHB87-LFB263
	.uleb128 LEHE87-LEHB87
	.uleb128 L451-LFB263
	.uleb128 0x1
	.uleb128 LEHB88-LFB263
	.uleb128 LEHE88-LEHB88
	.uleb128 0
	.uleb128 0
LLSDACSE263:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT263:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC75:
	.ascii "placement delete[](p=0x%p, dual_allocator.marker=%d,%d, align)\12\0"
	.text
	.globl	__ZdaPvR19CDualStackAllocatorjNS0_9E_ORDEREDE
	.def	__ZdaPvR19CDualStackAllocatorjNS0_9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZdaPvR19CDualStackAllocatorjNS0_9E_ORDEREDE:
LFB264:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA264
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
	jmp	L457
L456:
	cmpl	$-1, %edx
	je	L455
	movl	%eax, (%esp)
LEHB90:
	call	__Unwind_Resume
L455:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE90:
L457:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE264:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA264:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT264-LLSDATTD264
LLSDATTD264:
	.byte	0x1
	.uleb128 LLSDACSE264-LLSDACSB264
LLSDACSB264:
	.uleb128 LEHB89-LFB264
	.uleb128 LEHE89-LEHB89
	.uleb128 L456-LFB264
	.uleb128 0x1
	.uleb128 LEHB90-LFB264
	.uleb128 LEHE90-LEHB90
	.uleb128 0
	.uleb128 0
LLSDACSE264:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT264:
	.byte	0
	.text
	.section .rdata,"dr"
	.align 4
LC76:
	.ascii "placement delete[](p=0x%p, dual_allocator.marker=%d,%d)\12\0"
	.text
	.globl	__ZdaPvR19CDualStackAllocatorNS0_9E_ORDEREDE
	.def	__ZdaPvR19CDualStackAllocatorNS0_9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZdaPvR19CDualStackAllocatorNS0_9E_ORDEREDE:
LFB265:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA265
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
	jmp	L462
L461:
	cmpl	$-1, %edx
	je	L460
	movl	%eax, (%esp)
LEHB92:
	call	__Unwind_Resume
L460:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE92:
L462:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE265:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA265:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT265-LLSDATTD265
LLSDATTD265:
	.byte	0x1
	.uleb128 LLSDACSE265-LLSDACSB265
LLSDACSB265:
	.uleb128 LEHB91-LFB265
	.uleb128 LEHE91-LEHB91
	.uleb128 L461-LFB265
	.uleb128 0x1
	.uleb128 LEHB92-LFB265
	.uleb128 LEHE92-LEHB92
	.uleb128 0
	.uleb128 0
LLSDACSE265:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT265:
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
	jmp	L466
L465:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN7CTest4bD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB95:
	call	__Unwind_Resume
LEHE95:
L466:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE272:
	.section	.gcc_except_table,"w"
LLSDA272:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE272-LLSDACSB272
LLSDACSB272:
	.uleb128 LEHB93-LFB272
	.uleb128 LEHE93-LEHB93
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB94-LFB272
	.uleb128 LEHE94-LEHB94
	.uleb128 L465-LFB272
	.uleb128 0
	.uleb128 LEHB95-LFB272
	.uleb128 LEHE95-LEHB95
	.uleb128 0
	.uleb128 0
LLSDACSE272:
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
LFB275:
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
LFE275:
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
LFB278:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA278
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
LFE278:
	.section	.gcc_except_table,"w"
LLSDA278:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE278-LLSDACSB278
LLSDACSB278:
LLSDACSE278:
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
LFB279:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA279
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
	je	L471
	movl	$LC86, 4(%esp)
	movl	%ebx, (%esp)
LEHB99:
	call	__ZN7CTest4aC1EPKc
LEHE99:
	movl	%ebx, %eax
	jmp	L472
L471:
	movl	%ebx, %eax
L472:
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
	je	L473
	movl	$3, (%ebx)
	leal	4(%ebx), %esi
	movl	$2, %edi
	movl	%esi, -156(%ebp)
	jmp	L474
L475:
	movl	-156(%ebp), %eax
	movl	%eax, (%esp)
LEHB102:
	call	__ZN7CTest4aC1Ev
LEHE102:
	addl	$8, -156(%ebp)
	subl	$1, %edi
L474:
	cmpl	$-1, %edi
	jne	L475
	leal	4(%ebx), %eax
	jmp	L476
L473:
	movl	%ebx, %eax
L476:
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
	jmp	L491
L488:
	movl	%eax, %esi
	movl	$4, 8(%esp)
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvR15CStackAllocatorj
	movl	%esi, %eax
	jmp	L478
L487:
L478:
	movl	%eax, %ebx
	jmp	L479
L490:
	movl	%eax, -156(%ebp)
	testl	%esi, %esi
	je	L481
	movl	$2, %eax
	subl	%edi, %eax
	sall	$3, %eax
	leal	(%esi,%eax), %edi
L482:
	cmpl	%esi, %edi
	je	L481
	subl	$8, %edi
	movl	%edi, (%esp)
	call	__ZN7CTest4aD1Ev
	jmp	L482
L481:
	movl	-156(%ebp), %esi
	movl	$4, 8(%esp)
	leal	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdaPvR15CStackAllocatorj
	movl	%esi, %eax
	jmp	L483
L489:
L483:
	movl	%eax, %ebx
	jmp	L479
L486:
	movl	%eax, %ebx
L479:
	leal	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EED1Ev
	movl	%ebx, %eax
	jmp	L484
L485:
L484:
	movl	%eax, (%esp)
LEHB104:
	call	__Unwind_Resume
LEHE104:
L491:
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
LFE279:
	.section	.gcc_except_table,"w"
LLSDA279:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE279-LLSDACSB279
LLSDACSB279:
	.uleb128 LEHB96-LFB279
	.uleb128 LEHE96-LEHB96
	.uleb128 L485-LFB279
	.uleb128 0
	.uleb128 LEHB97-LFB279
	.uleb128 LEHE97-LEHB97
	.uleb128 L486-LFB279
	.uleb128 0
	.uleb128 LEHB98-LFB279
	.uleb128 LEHE98-LEHB98
	.uleb128 L487-LFB279
	.uleb128 0
	.uleb128 LEHB99-LFB279
	.uleb128 LEHE99-LEHB99
	.uleb128 L488-LFB279
	.uleb128 0
	.uleb128 LEHB100-LFB279
	.uleb128 LEHE100-LEHB100
	.uleb128 L487-LFB279
	.uleb128 0
	.uleb128 LEHB101-LFB279
	.uleb128 LEHE101-LEHB101
	.uleb128 L489-LFB279
	.uleb128 0
	.uleb128 LEHB102-LFB279
	.uleb128 LEHE102-LEHB102
	.uleb128 L490-LFB279
	.uleb128 0
	.uleb128 LEHB103-LFB279
	.uleb128 LEHE103-LEHB103
	.uleb128 L489-LFB279
	.uleb128 0
	.uleb128 LEHB104-LFB279
	.uleb128 LEHE104-LEHB104
	.uleb128 0
	.uleb128 0
LLSDACSE279:
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
LFB280:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA280
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
	call	__ZN27CDualStackAllocatorWithBuffILj64EEC1EN19CDualStackAllocator9E_ORDEREDE
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
	call	__ZnajR19CDualStackAllocatorNS_9E_ORDEREDE
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
	call	__ZnajR19CDualStackAllocatorjNS_9E_ORDEREDE
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
	call	__ZnajR19CDualStackAllocatorNS_9E_ORDEREDE
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
	call	__ZnwjR19CDualStackAllocatorNS_9E_ORDEREDE
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L493
	movl	$LC97, 4(%esp)
	movl	%ebx, (%esp)
LEHB108:
	call	__ZN7CTest4bC1EPKc
LEHE108:
	movl	%ebx, %eax
	jmp	L494
L493:
	movl	%ebx, %eax
L494:
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
	call	__ZN19CDualStackAllocator17setDefaultOrderedENS_9E_ORDEREDE
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
	call	__ZnajR19CDualStackAllocatorNS_9E_ORDEREDE
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L495
	movl	$3, (%ebx)
	leal	4(%ebx), %esi
	movl	$2, %edi
	movl	%esi, -188(%ebp)
	jmp	L496
L497:
	movl	-188(%ebp), %eax
	movl	%eax, (%esp)
LEHB111:
	call	__ZN7CTest4bC1Ev
LEHE111:
	addl	$8, -188(%ebp)
	subl	$1, %edi
L496:
	cmpl	$-1, %edi
	jne	L497
	leal	4(%ebx), %eax
	jmp	L498
L495:
	movl	%ebx, %eax
L498:
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
	call	__ZnwjR19CDualStackAllocatorNS_9E_ORDEREDE
	movl	%eax, -80(%ebp)
	movl	-80(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC90, (%esp)
	call	_printf
	movl	$1, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZnwjR19CDualStackAllocatorNS_9E_ORDEREDE
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
	call	__ZnwjR19CDualStackAllocatorjNS_9E_ORDEREDE
	movl	%eax, -88(%ebp)
	movl	-88(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC92, (%esp)
	call	_printf
	movl	$1, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$40, (%esp)
	call	__ZnajR19CDualStackAllocatorNS_9E_ORDEREDE
	movl	%eax, -52(%ebp)
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC100, (%esp)
	call	_printf
	movl	$0, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$40, (%esp)
	call	__ZnajR19CDualStackAllocatorNS_9E_ORDEREDE
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
	jmp	L513
L510:
	movl	%eax, %esi
	movl	$-1, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvR19CDualStackAllocatorNS0_9E_ORDEREDE
	movl	%esi, %eax
	jmp	L500
L509:
L500:
	movl	%eax, %ebx
	jmp	L501
L512:
	movl	%eax, -188(%ebp)
	testl	%esi, %esi
	je	L503
	movl	$2, %eax
	subl	%edi, %eax
	sall	$3, %eax
	leal	(%esi,%eax), %edi
L504:
	cmpl	%esi, %edi
	je	L503
	subl	$8, %edi
	movl	%edi, (%esp)
	call	__ZN7CTest4bD1Ev
	jmp	L504
L503:
	movl	-188(%ebp), %esi
	movl	$1, 8(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdaPvR19CDualStackAllocatorNS0_9E_ORDEREDE
	movl	%esi, %eax
	jmp	L505
L511:
L505:
	movl	%eax, %ebx
	jmp	L501
L508:
	movl	%eax, %ebx
L501:
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev
	movl	%ebx, %eax
	jmp	L506
L507:
L506:
	movl	%eax, (%esp)
LEHB113:
	call	__Unwind_Resume
LEHE113:
L513:
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
LFE280:
	.section	.gcc_except_table,"w"
LLSDA280:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE280-LLSDACSB280
LLSDACSB280:
	.uleb128 LEHB105-LFB280
	.uleb128 LEHE105-LEHB105
	.uleb128 L507-LFB280
	.uleb128 0
	.uleb128 LEHB106-LFB280
	.uleb128 LEHE106-LEHB106
	.uleb128 L508-LFB280
	.uleb128 0
	.uleb128 LEHB107-LFB280
	.uleb128 LEHE107-LEHB107
	.uleb128 L509-LFB280
	.uleb128 0
	.uleb128 LEHB108-LFB280
	.uleb128 LEHE108-LEHB108
	.uleb128 L510-LFB280
	.uleb128 0
	.uleb128 LEHB109-LFB280
	.uleb128 LEHE109-LEHB109
	.uleb128 L509-LFB280
	.uleb128 0
	.uleb128 LEHB110-LFB280
	.uleb128 LEHE110-LEHB110
	.uleb128 L511-LFB280
	.uleb128 0
	.uleb128 LEHB111-LFB280
	.uleb128 LEHE111-LEHB111
	.uleb128 L512-LFB280
	.uleb128 0
	.uleb128 LEHB112-LFB280
	.uleb128 LEHE112-LEHB112
	.uleb128 L511-LFB280
	.uleb128 0
	.uleb128 LEHB113-LFB280
	.uleb128 LEHE113-LEHB113
	.uleb128 0
	.uleb128 0
LLSDACSE280:
	.text
	.section	.text$_ZStanSt12memory_orderSt23__memory_order_modifier,"x"
	.linkonce discard
	.globl	__ZStanSt12memory_orderSt23__memory_order_modifier
	.def	__ZStanSt12memory_orderSt23__memory_order_modifier;	.scl	2;	.type	32;	.endef
__ZStanSt12memory_orderSt23__memory_order_modifier:
LFB282:
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
LFE282:
	.section	.text$_ZNK14CPoolAllocator7getBuffEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK14CPoolAllocator7getBuffEv
	.def	__ZNK14CPoolAllocator7getBuffEv;	.scl	2;	.type	32;	.endef
__ZNK14CPoolAllocator7getBuffEv:
LFB607:
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
LFE607:
	.section	.text$_ZNK14CPoolAllocator12getBlockSizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK14CPoolAllocator12getBlockSizeEv
	.def	__ZNK14CPoolAllocator12getBlockSizeEv;	.scl	2;	.type	32;	.endef
__ZNK14CPoolAllocator12getBlockSizeEv:
LFB608:
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
LFE608:
	.section	.text$_ZNK14CPoolAllocator12getBlocksNumEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK14CPoolAllocator12getBlocksNumEv
	.def	__ZNK14CPoolAllocator12getBlocksNumEv;	.scl	2;	.type	32;	.endef
__ZNK14CPoolAllocator12getBlocksNumEv:
LFB609:
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
LFE609:
	.section	.text$_ZNK14CPoolAllocator7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK14CPoolAllocator7getUsedEv
	.def	__ZNK14CPoolAllocator7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK14CPoolAllocator7getUsedEv:
LFB610:
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
LFE610:
	.section	.text$_ZNK14CPoolAllocator9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK14CPoolAllocator9getRemainEv
	.def	__ZNK14CPoolAllocator9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK14CPoolAllocator9getRemainEv:
LFB611:
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
LFE611:
	.section	.text$_ZN14CPoolAllocator8getBlockEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator8getBlockEi
	.def	__ZN14CPoolAllocator8getBlockEi;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator8getBlockEi:
LFB613:
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
LFE613:
	.section	.text$_ZN14CPoolAllocator5resetEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator5resetEv
	.def	__ZN14CPoolAllocator5resetEv;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator5resetEv:
LFB614:
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
LFE614:
	.section	.text$_ZN14CPoolAllocator6assignEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6assignEv
	.def	__ZN14CPoolAllocator6assignEv;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6assignEv:
LFB615:
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
	je	L530
	movl	$2147483647, %eax
	jmp	L531
L530:
	movl	$2147483647, -12(%ebp)
	movl	8(%ebp), %eax
	movl	16(%eax), %edx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	jge	L532
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
	jmp	L533
L532:
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	cmpl	$2147483647, %eax
	je	L533
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
L533:
	movl	-12(%ebp), %eax
L531:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE615:
	.section	.text$_ZN14CPoolAllocator7releaseEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7releaseEi
	.def	__ZN14CPoolAllocator7releaseEi;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7releaseEi:
LFB616:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	js	L535
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	12(%ebp), %eax
	jg	L536
L535:
	jmp	L534
L536:
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
L534:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE616:
	.section	.text$_ZN14CPoolAllocator5allocEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator5allocEj
	.def	__ZN14CPoolAllocator5allocEj;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator5allocEj:
LFB617:
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
	jae	L539
	movl	$0, %eax
	jmp	L540
L539:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator6assignEv
	movl	%eax, -12(%ebp)
	cmpl	$2147483647, -12(%ebp)
	je	L541
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator8getBlockEi
	jmp	L542
L541:
	movl	$0, %eax
L542:
L540:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE617:
	.section	.text$_ZN14CPoolAllocator4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator4freeEPv
	.def	__ZN14CPoolAllocator4freeEPv;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator4freeEPv:
LFB618:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	cmpl	$0, 12(%ebp)
	jne	L544
	jmp	L543
L544:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movl	-12(%ebp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	8(%ebp), %edx
	movl	4(%edx), %ecx
	movl	$0, %edx
	divl	%ecx
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPoolAllocator7releaseEi
L543:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE618:
	.section	.text$_ZNSt13__atomic_baseIiEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13__atomic_baseIiEC2Ev
	.def	__ZNSt13__atomic_baseIiEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt13__atomic_baseIiEC2Ev:
LFB624:
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
LFE624:
	.section	.text$_ZNSt6atomicIiEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6atomicIiEC1Ev
	.def	__ZNSt6atomicIiEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6atomicIiEC1Ev:
LFB627:
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
LFE627:
	.section	.text$_ZN14CPoolAllocatorC2EPvji,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocatorC2EPvji
	.def	__ZN14CPoolAllocatorC2EPvji;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocatorC2EPvji:
LFB628:
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
LFE628:
	.section	.text$_ZN14CPoolAllocatorD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocatorD2Ev
	.def	__ZN14CPoolAllocatorD2Ev;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocatorD2Ev:
LFB631:
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
LFE631:
	.section .rdata,"dr"
	.align 4
LC102:
	.ascii "placement new(size=%d, pool_allocator.used=%d/%d/%d)\12\0"
	.text
	.globl	__ZnwjR14CPoolAllocator
	.def	__ZnwjR14CPoolAllocator;	.scl	2;	.type	32;	.endef
__ZnwjR14CPoolAllocator:
LFB633:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA633
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
	jmp	L556
L555:
	cmpl	$-1, %edx
	je	L554
	movl	%eax, (%esp)
LEHB115:
	call	__Unwind_Resume
L554:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE115:
L556:
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
LFE633:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA633:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT633-LLSDATTD633
LLSDATTD633:
	.byte	0x1
	.uleb128 LLSDACSE633-LLSDACSB633
LLSDACSB633:
	.uleb128 LEHB114-LFB633
	.uleb128 LEHE114-LEHB114
	.uleb128 L555-LFB633
	.uleb128 0x1
	.uleb128 LEHB115-LFB633
	.uleb128 LEHE115-LEHB115
	.uleb128 0
	.uleb128 0
LLSDACSE633:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT633:
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
LFB634:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA634
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
	jmp	L561
L560:
	cmpl	$-1, %edx
	je	L559
	movl	%eax, (%esp)
LEHB117:
	call	__Unwind_Resume
L559:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE117:
L561:
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
LFE634:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA634:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT634-LLSDATTD634
LLSDATTD634:
	.byte	0x1
	.uleb128 LLSDACSE634-LLSDACSB634
LLSDACSB634:
	.uleb128 LEHB116-LFB634
	.uleb128 LEHE116-LEHB116
	.uleb128 L560-LFB634
	.uleb128 0x1
	.uleb128 LEHB117-LFB634
	.uleb128 LEHE117-LEHB117
	.uleb128 0
	.uleb128 0
LLSDACSE634:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT634:
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
LFB646:
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
LFE646:
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
LFB649:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA649
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
LFE649:
	.section	.gcc_except_table,"w"
LLSDA649:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE649-LLSDACSB649
LLSDACSB649:
LLSDACSE649:
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
LFB650:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA650
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
	jmp	L574
L572:
	movl	%eax, %ebx
	jmp	L567
L573:
	movl	%eax, %ebx
	jmp	L567
L571:
	movl	%eax, %ebx
L567:
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EED1Ev
	movl	%ebx, %eax
	jmp	L569
L570:
L569:
	movl	%eax, (%esp)
LEHB122:
	call	__Unwind_Resume
LEHE122:
L574:
	addl	$148, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE650:
	.section	.gcc_except_table,"w"
LLSDA650:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE650-LLSDACSB650
LLSDACSB650:
	.uleb128 LEHB118-LFB650
	.uleb128 LEHE118-LEHB118
	.uleb128 L570-LFB650
	.uleb128 0
	.uleb128 LEHB119-LFB650
	.uleb128 LEHE119-LEHB119
	.uleb128 L571-LFB650
	.uleb128 0
	.uleb128 LEHB120-LFB650
	.uleb128 LEHE120-LEHB120
	.uleb128 L572-LFB650
	.uleb128 0
	.uleb128 LEHB121-LFB650
	.uleb128 LEHE121-LEHB121
	.uleb128 L573-LFB650
	.uleb128 0
	.uleb128 LEHB122-LFB650
	.uleb128 LEHE122-LEHB122
	.uleb128 0
	.uleb128 0
LLSDACSE650:
	.text
	.section	.text$_ZN10IAllocatorD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10IAllocatorD2Ev
	.def	__ZN10IAllocatorD2Ev;	.scl	2;	.type	32;	.endef
__ZN10IAllocatorD2Ev:
LFB652:
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
	je	L575
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L575:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE652:
	.section	.text$_ZN10IAllocatorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10IAllocatorD1Ev
	.def	__ZN10IAllocatorD1Ev;	.scl	2;	.type	32;	.endef
__ZN10IAllocatorD1Ev:
LFB653:
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
	je	L578
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L578:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE653:
	.section	.text$_ZN10IAllocatorD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10IAllocatorD0Ev
	.def	__ZN10IAllocatorD0Ev;	.scl	2;	.type	32;	.endef
__ZN10IAllocatorD0Ev:
LFB654:
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
LFE654:
	.section .rdata,"dr"
LC124:
	.ascii "CStdAllocAdp\0"
	.section	.text$_ZNK12CStdAllocAdp7getNameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK12CStdAllocAdp7getNameEv
	.def	__ZNK12CStdAllocAdp7getNameEv;	.scl	2;	.type	32;	.endef
__ZNK12CStdAllocAdp7getNameEv:
LFB655:
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
LFE655:
	.section	.text$_ZNK12CStdAllocAdp8getTotalEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK12CStdAllocAdp8getTotalEv
	.def	__ZNK12CStdAllocAdp8getTotalEv;	.scl	2;	.type	32;	.endef
__ZNK12CStdAllocAdp8getTotalEv:
LFB656:
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
LFE656:
	.section	.text$_ZNK12CStdAllocAdp7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK12CStdAllocAdp7getUsedEv
	.def	__ZNK12CStdAllocAdp7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK12CStdAllocAdp7getUsedEv:
LFB657:
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
LFE657:
	.section	.text$_ZNK12CStdAllocAdp9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK12CStdAllocAdp9getRemainEv
	.def	__ZNK12CStdAllocAdp9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK12CStdAllocAdp9getRemainEv:
LFB658:
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
LFE658:
	.section	.text$_ZN12CStdAllocAdpnwEj,"x"
	.linkonce discard
	.globl	__ZN12CStdAllocAdpnwEj
	.def	__ZN12CStdAllocAdpnwEj;	.scl	2;	.type	32;	.endef
__ZN12CStdAllocAdpnwEj:
LFB659:
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
LFE659:
	.section	.text$_ZN12CStdAllocAdpdlEPv,"x"
	.linkonce discard
	.globl	__ZN12CStdAllocAdpdlEPv
	.def	__ZN12CStdAllocAdpdlEPv;	.scl	2;	.type	32;	.endef
__ZN12CStdAllocAdpdlEPv:
LFB660:
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
LFE660:
	.section	.text$_ZN12CStdAllocAdp5allocEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN12CStdAllocAdp5allocEjj
	.def	__ZN12CStdAllocAdp5allocEjj;	.scl	2;	.type	32;	.endef
__ZN12CStdAllocAdp5allocEjj:
LFB661:
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
LFE661:
	.section	.text$_ZN12CStdAllocAdp4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN12CStdAllocAdp4freeEPv
	.def	__ZN12CStdAllocAdp4freeEPv;	.scl	2;	.type	32;	.endef
__ZN12CStdAllocAdp4freeEPv:
LFB662:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	jne	L597
	jmp	L596
L597:
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
L596:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE662:
	.section	.text$_ZN10IAllocatorC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10IAllocatorC2Ev
	.def	__ZN10IAllocatorC2Ev;	.scl	2;	.type	32;	.endef
__ZN10IAllocatorC2Ev:
LFB665:
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
LFE665:
	.section	.text$_ZN12CStdAllocAdpC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN12CStdAllocAdpC1Ev
	.def	__ZN12CStdAllocAdpC1Ev;	.scl	2;	.type	32;	.endef
__ZN12CStdAllocAdpC1Ev:
LFB668:
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
LFE668:
	.section	.text$_ZN12CStdAllocAdpD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN12CStdAllocAdpD1Ev
	.def	__ZN12CStdAllocAdpD1Ev;	.scl	2;	.type	32;	.endef
__ZN12CStdAllocAdpD1Ev:
LFB671:
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
	je	L601
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN12CStdAllocAdpdlEPv
L601:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE671:
	.section	.text$_ZN12CStdAllocAdpD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN12CStdAllocAdpD0Ev
	.def	__ZN12CStdAllocAdpD0Ev;	.scl	2;	.type	32;	.endef
__ZN12CStdAllocAdpD0Ev:
LFB672:
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
LFE672:
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
LFB673:
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
LFE673:
	.section	.text$_ZNK13CMonoAllocAdp8getTotalEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK13CMonoAllocAdp8getTotalEv
	.def	__ZNK13CMonoAllocAdp8getTotalEv;	.scl	2;	.type	32;	.endef
__ZNK13CMonoAllocAdp8getTotalEv:
LFB674:
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
LFE674:
	.section	.text$_ZNK13CMonoAllocAdp7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK13CMonoAllocAdp7getUsedEv
	.def	__ZNK13CMonoAllocAdp7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK13CMonoAllocAdp7getUsedEv:
LFB675:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	12(%eax), %eax
	testb	%al, %al
	je	L611
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	jmp	L612
L611:
	movl	$0, %eax
L612:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE675:
	.section	.text$_ZNK13CMonoAllocAdp9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK13CMonoAllocAdp9getRemainEv
	.def	__ZNK13CMonoAllocAdp9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK13CMonoAllocAdp9getRemainEv:
LFB676:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	12(%eax), %eax
	testb	%al, %al
	je	L615
	movl	$0, %eax
	jmp	L616
L615:
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
L616:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE676:
	.section	.text$_ZN13CMonoAllocAdp5allocEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CMonoAllocAdp5allocEjj
	.def	__ZN13CMonoAllocAdp5allocEjj;	.scl	2;	.type	32;	.endef
__ZN13CMonoAllocAdp5allocEjj:
LFB680:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movzbl	12(%eax), %eax
	testb	%al, %al
	je	L619
	movl	$0, %eax
	jmp	L620
L619:
	movl	8(%ebp), %eax
	movb	$1, 12(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
L620:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE680:
	.section	.text$_ZN13CMonoAllocAdp4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CMonoAllocAdp4freeEPv
	.def	__ZN13CMonoAllocAdp4freeEPv;	.scl	2;	.type	32;	.endef
__ZN13CMonoAllocAdp4freeEPv:
LFB681:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	cmpl	$0, 12(%ebp)
	jne	L622
	jmp	L621
L622:
	movl	8(%ebp), %eax
	movzbl	12(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L624
	jmp	L621
L624:
	movl	8(%ebp), %eax
	movb	$0, 12(%eax)
L621:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE681:
	.section	.text$_ZN13CMonoAllocAdpC2EPvj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CMonoAllocAdpC2EPvj
	.def	__ZN13CMonoAllocAdpC2EPvj;	.scl	2;	.type	32;	.endef
__ZN13CMonoAllocAdpC2EPvj:
LFB683:
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
LFE683:
	.section	.text$_ZN13CMonoAllocAdpD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CMonoAllocAdpD2Ev
	.def	__ZN13CMonoAllocAdpD2Ev;	.scl	2;	.type	32;	.endef
__ZN13CMonoAllocAdpD2Ev:
LFB686:
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
	je	L626
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L626:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE686:
	.section	.text$_ZN13CMonoAllocAdpD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CMonoAllocAdpD1Ev
	.def	__ZN13CMonoAllocAdpD1Ev;	.scl	2;	.type	32;	.endef
__ZN13CMonoAllocAdpD1Ev:
LFB687:
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
	je	L629
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L629:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE687:
	.section	.text$_ZN13CMonoAllocAdpD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CMonoAllocAdpD0Ev
	.def	__ZN13CMonoAllocAdpD0Ev;	.scl	2;	.type	32;	.endef
__ZN13CMonoAllocAdpD0Ev:
LFB688:
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
LFE688:
	.section .rdata,"dr"
LC126:
	.ascii "CStackAllocAdp\0"
	.section	.text$_ZNK14CStackAllocAdp7getNameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK14CStackAllocAdp7getNameEv
	.def	__ZNK14CStackAllocAdp7getNameEv;	.scl	2;	.type	32;	.endef
__ZNK14CStackAllocAdp7getNameEv:
LFB691:
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
LFE691:
	.section	.text$_ZNK14CStackAllocAdp8getTotalEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK14CStackAllocAdp8getTotalEv
	.def	__ZNK14CStackAllocAdp8getTotalEv;	.scl	2;	.type	32;	.endef
__ZNK14CStackAllocAdp8getTotalEv:
LFB692:
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
LFE692:
	.section	.text$_ZNK14CStackAllocAdp7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK14CStackAllocAdp7getUsedEv
	.def	__ZNK14CStackAllocAdp7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK14CStackAllocAdp7getUsedEv:
LFB693:
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
LFE693:
	.section	.text$_ZNK14CStackAllocAdp9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK14CStackAllocAdp9getRemainEv
	.def	__ZNK14CStackAllocAdp9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK14CStackAllocAdp9getRemainEv:
LFB694:
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
LFE694:
	.section	.text$_ZN14CStackAllocAdp5allocEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CStackAllocAdp5allocEjj
	.def	__ZN14CStackAllocAdp5allocEjj;	.scl	2;	.type	32;	.endef
__ZN14CStackAllocAdp5allocEjj:
LFB696:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN15CStackAllocator6allocNEjj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE696:
	.section	.text$_ZN14CStackAllocAdp4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CStackAllocAdp4freeEPv
	.def	__ZN14CStackAllocAdp4freeEPv;	.scl	2;	.type	32;	.endef
__ZN14CStackAllocAdp4freeEPv:
LFB697:
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
LFE697:
	.section	.text$_ZN14CStackAllocAdpC1ER15CStackAllocator,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CStackAllocAdpC1ER15CStackAllocator
	.def	__ZN14CStackAllocAdpC1ER15CStackAllocator;	.scl	2;	.type	32;	.endef
__ZN14CStackAllocAdpC1ER15CStackAllocator:
LFB700:
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
	movl	$__ZTV14CStackAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE700:
	.section	.text$_ZN14CStackAllocAdpD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CStackAllocAdpD1Ev
	.def	__ZN14CStackAllocAdpD1Ev;	.scl	2;	.type	32;	.endef
__ZN14CStackAllocAdpD1Ev:
LFB703:
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
	call	__ZN10IAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L646
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L646:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE703:
	.section	.text$_ZN14CStackAllocAdpD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CStackAllocAdpD0Ev
	.def	__ZN14CStackAllocAdpD0Ev;	.scl	2;	.type	32;	.endef
__ZN14CStackAllocAdpD0Ev:
LFB704:
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
LFE704:
	.section .rdata,"dr"
LC127:
	.ascii "CDualStackAllocAdp\0"
	.section	.text$_ZNK18CDualStackAllocAdp7getNameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK18CDualStackAllocAdp7getNameEv
	.def	__ZNK18CDualStackAllocAdp7getNameEv;	.scl	2;	.type	32;	.endef
__ZNK18CDualStackAllocAdp7getNameEv:
LFB705:
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
LFE705:
	.section	.text$_ZNK18CDualStackAllocAdp8getTotalEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK18CDualStackAllocAdp8getTotalEv
	.def	__ZNK18CDualStackAllocAdp8getTotalEv;	.scl	2;	.type	32;	.endef
__ZNK18CDualStackAllocAdp8getTotalEv:
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
	.section	.text$_ZNK18CDualStackAllocAdp7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK18CDualStackAllocAdp7getUsedEv
	.def	__ZNK18CDualStackAllocAdp7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK18CDualStackAllocAdp7getUsedEv:
LFB707:
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
LFE707:
	.section	.text$_ZNK18CDualStackAllocAdp9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK18CDualStackAllocAdp9getRemainEv
	.def	__ZNK18CDualStackAllocAdp9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK18CDualStackAllocAdp9getRemainEv:
LFB708:
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
LFE708:
	.section	.text$_ZN18CDualStackAllocAdp5allocEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CDualStackAllocAdp5allocEjj
	.def	__ZN18CDualStackAllocAdp5allocEjj;	.scl	2;	.type	32;	.endef
__ZN18CDualStackAllocAdp5allocEjj:
LFB712:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	16(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	12(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN19CDualStackAllocator5allocENS_9E_ORDEREDEjj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE712:
	.section	.text$_ZN18CDualStackAllocAdp4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CDualStackAllocAdp4freeEPv
	.def	__ZN18CDualStackAllocAdp4freeEPv;	.scl	2;	.type	32;	.endef
__ZN18CDualStackAllocAdp4freeEPv:
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
	.section	.text$_ZN18CDualStackAllocAdpC1ER19CDualStackAllocatorNS0_9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CDualStackAllocAdpC1ER19CDualStackAllocatorNS0_9E_ORDEREDE
	.def	__ZN18CDualStackAllocAdpC1ER19CDualStackAllocatorNS0_9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN18CDualStackAllocAdpC1ER19CDualStackAllocatorNS0_9E_ORDEREDE:
LFB716:
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
	movl	$__ZTV18CDualStackAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE716:
	.section	.text$_ZN18CDualStackAllocAdpD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CDualStackAllocAdpD1Ev
	.def	__ZN18CDualStackAllocAdpD1Ev;	.scl	2;	.type	32;	.endef
__ZN18CDualStackAllocAdpD1Ev:
LFB719:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV18CDualStackAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10IAllocatorD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L663
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L663:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE719:
	.section	.text$_ZN18CDualStackAllocAdpD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CDualStackAllocAdpD0Ev
	.def	__ZN18CDualStackAllocAdpD0Ev;	.scl	2;	.type	32;	.endef
__ZN18CDualStackAllocAdpD0Ev:
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
	call	__ZN18CDualStackAllocAdpD1Ev
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
LC128:
	.ascii "CIStackAllocAdp\0"
	.section	.text$_ZNK15CIStackAllocAdp7getNameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CIStackAllocAdp7getNameEv
	.def	__ZNK15CIStackAllocAdp7getNameEv;	.scl	2;	.type	32;	.endef
__ZNK15CIStackAllocAdp7getNameEv:
LFB721:
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
LFE721:
	.section	.text$_ZNK15CIStackAllocAdp8getTotalEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CIStackAllocAdp8getTotalEv
	.def	__ZNK15CIStackAllocAdp8getTotalEv;	.scl	2;	.type	32;	.endef
__ZNK15CIStackAllocAdp8getTotalEv:
LFB722:
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
LFE722:
	.section	.text$_ZNK15CIStackAllocAdp7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CIStackAllocAdp7getUsedEv
	.def	__ZNK15CIStackAllocAdp7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK15CIStackAllocAdp7getUsedEv:
LFB723:
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
LFE723:
	.section	.text$_ZNK15CIStackAllocAdp9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK15CIStackAllocAdp9getRemainEv
	.def	__ZNK15CIStackAllocAdp9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK15CIStackAllocAdp9getRemainEv:
LFB724:
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
LFE724:
	.section	.text$_ZN15CIStackAllocAdp5allocEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CIStackAllocAdp5allocEjj
	.def	__ZN15CIStackAllocAdp5allocEjj;	.scl	2;	.type	32;	.endef
__ZN15CIStackAllocAdp5allocEjj:
LFB726:
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
LFE726:
	.section	.text$_ZN15CIStackAllocAdp4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CIStackAllocAdp4freeEPv
	.def	__ZN15CIStackAllocAdp4freeEPv;	.scl	2;	.type	32;	.endef
__ZN15CIStackAllocAdp4freeEPv:
LFB727:
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
LFE727:
	.section	.text$_ZN15CIStackAllocAdpC1ER15IStackAllocator,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CIStackAllocAdpC1ER15IStackAllocator
	.def	__ZN15CIStackAllocAdpC1ER15IStackAllocator;	.scl	2;	.type	32;	.endef
__ZN15CIStackAllocAdpC1ER15IStackAllocator:
LFB730:
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
	movl	$__ZTV15CIStackAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE730:
	.section	.text$_ZN15CIStackAllocAdpD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CIStackAllocAdpD1Ev
	.def	__ZN15CIStackAllocAdpD1Ev;	.scl	2;	.type	32;	.endef
__ZN15CIStackAllocAdpD1Ev:
LFB733:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV15CIStackAllocAdp+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN10IAllocatorD2Ev
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
LFE733:
	.section	.text$_ZN15CIStackAllocAdpD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15CIStackAllocAdpD0Ev
	.def	__ZN15CIStackAllocAdpD0Ev;	.scl	2;	.type	32;	.endef
__ZN15CIStackAllocAdpD0Ev:
LFB734:
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
LFE734:
	.section .rdata,"dr"
LC129:
	.ascii "CPoolAllocAdp\0"
	.section	.text$_ZNK13CPoolAllocAdp7getNameEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK13CPoolAllocAdp7getNameEv
	.def	__ZNK13CPoolAllocAdp7getNameEv;	.scl	2;	.type	32;	.endef
__ZNK13CPoolAllocAdp7getNameEv:
LFB735:
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
LFE735:
	.section	.text$_ZNK13CPoolAllocAdp8getTotalEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK13CPoolAllocAdp8getTotalEv
	.def	__ZNK13CPoolAllocAdp8getTotalEv;	.scl	2;	.type	32;	.endef
__ZNK13CPoolAllocAdp8getTotalEv:
LFB736:
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
LFE736:
	.section	.text$_ZNK13CPoolAllocAdp7getUsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK13CPoolAllocAdp7getUsedEv
	.def	__ZNK13CPoolAllocAdp7getUsedEv;	.scl	2;	.type	32;	.endef
__ZNK13CPoolAllocAdp7getUsedEv:
LFB737:
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
LFE737:
	.section	.text$_ZNK13CPoolAllocAdp9getRemainEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK13CPoolAllocAdp9getRemainEv
	.def	__ZNK13CPoolAllocAdp9getRemainEv;	.scl	2;	.type	32;	.endef
__ZNK13CPoolAllocAdp9getRemainEv:
LFB738:
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
LFE738:
	.section	.text$_ZN13CPoolAllocAdp5allocEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CPoolAllocAdp5allocEjj
	.def	__ZN13CPoolAllocAdp5allocEjj;	.scl	2;	.type	32;	.endef
__ZN13CPoolAllocAdp5allocEjj:
LFB740:
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
LFE740:
	.section	.text$_ZN13CPoolAllocAdp4freeEPv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CPoolAllocAdp4freeEPv
	.def	__ZN13CPoolAllocAdp4freeEPv;	.scl	2;	.type	32;	.endef
__ZN13CPoolAllocAdp4freeEPv:
LFB741:
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
LFE741:
	.section	.text$_ZN13CPoolAllocAdpC1ER14CPoolAllocator,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CPoolAllocAdpC1ER14CPoolAllocator
	.def	__ZN13CPoolAllocAdpC1ER14CPoolAllocator;	.scl	2;	.type	32;	.endef
__ZN13CPoolAllocAdpC1ER14CPoolAllocator:
LFB744:
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
LFE744:
	.section	.text$_ZN13CPoolAllocAdpD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CPoolAllocAdpD1Ev
	.def	__ZN13CPoolAllocAdpD1Ev;	.scl	2;	.type	32;	.endef
__ZN13CPoolAllocAdpD1Ev:
LFB747:
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
	je	L698
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L698:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE747:
	.section	.text$_ZN13CPoolAllocAdpD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN13CPoolAllocAdpD0Ev
	.def	__ZN13CPoolAllocAdpD0Ev;	.scl	2;	.type	32;	.endef
__ZN13CPoolAllocAdpD0Ev:
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
	call	__ZN13CPoolAllocAdpD1Ev
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
	.align 4
LC130:
	.ascii "placement new(size=%d, i_allocator=\"%s\":%d/%d/%d)\12\0"
LC131:
	.ascii "  p=0x%p\12\0"
	.text
	.globl	__ZnwjR10IAllocator
	.def	__ZnwjR10IAllocator;	.scl	2;	.type	32;	.endef
__ZnwjR10IAllocator:
LFB749:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA749
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
LEHB123:
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
LEHE123:
	movl	-28(%ebp), %eax
	jmp	L708
L707:
	cmpl	$-1, %edx
	je	L706
	movl	%eax, (%esp)
LEHB124:
	call	__Unwind_Resume
L706:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE124:
L708:
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
LFE749:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA749:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT749-LLSDATTD749
LLSDATTD749:
	.byte	0x1
	.uleb128 LLSDACSE749-LLSDACSB749
LLSDACSB749:
	.uleb128 LEHB123-LFB749
	.uleb128 LEHE123-LEHB123
	.uleb128 L707-LFB749
	.uleb128 0x1
	.uleb128 LEHB124-LFB749
	.uleb128 LEHE124-LEHB124
	.uleb128 0
	.uleb128 0
LLSDACSE749:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT749:
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
LFB750:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA750
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
LEHB125:
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
LEHE125:
	movl	-28(%ebp), %eax
	jmp	L714
L713:
	cmpl	$-1, %edx
	je	L712
	movl	%eax, (%esp)
LEHB126:
	call	__Unwind_Resume
L712:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE126:
L714:
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
LFE750:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA750:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT750-LLSDATTD750
LLSDATTD750:
	.byte	0x1
	.uleb128 LLSDACSE750-LLSDACSB750
LLSDACSB750:
	.uleb128 LEHB125-LFB750
	.uleb128 LEHE125-LEHB125
	.uleb128 L713-LFB750
	.uleb128 0x1
	.uleb128 LEHB126-LFB750
	.uleb128 LEHE126-LEHB126
	.uleb128 0
	.uleb128 0
LLSDACSE750:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT750:
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
LFB751:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA751
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
LEHE127:
	jmp	L719
L718:
	cmpl	$-1, %edx
	je	L717
	movl	%eax, (%esp)
LEHB128:
	call	__Unwind_Resume
L717:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE128:
L719:
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
LFE751:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA751:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT751-LLSDATTD751
LLSDATTD751:
	.byte	0x1
	.uleb128 LLSDACSE751-LLSDACSB751
LLSDACSB751:
	.uleb128 LEHB127-LFB751
	.uleb128 LEHE127-LEHB127
	.uleb128 L718-LFB751
	.uleb128 0x1
	.uleb128 LEHB128-LFB751
	.uleb128 LEHE128-LEHB128
	.uleb128 0
	.uleb128 0
LLSDACSE751:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT751:
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
LFB752:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA752
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
LEHE129:
	jmp	L724
L723:
	cmpl	$-1, %edx
	je	L722
	movl	%eax, (%esp)
LEHB130:
	call	__Unwind_Resume
L722:
	movl	%eax, (%esp)
	call	___cxa_call_unexpected
LEHE130:
L724:
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
LFE752:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA752:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT752-LLSDATTD752
LLSDATTD752:
	.byte	0x1
	.uleb128 LLSDACSE752-LLSDACSB752
LLSDACSB752:
	.uleb128 LEHB129-LFB752
	.uleb128 LEHE129-LEHB129
	.uleb128 L723-LFB752
	.uleb128 0x1
	.uleb128 LEHB130-LFB752
	.uleb128 LEHE130-LEHB130
	.uleb128 0
	.uleb128 0
LLSDACSE752:
	.byte	0x7f
	.byte	0
	.align 4
LLSDATT752:
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
LFB757:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA757
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
LEHB131:
	call	__ZN6CTest6C1EPKc
LEHE131:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC135, (%esp)
LEHB132:
	call	_printf
LEHE132:
	jmp	L728
L727:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest6D1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB133:
	call	__Unwind_Resume
LEHE133:
L728:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE757:
	.section	.gcc_except_table,"w"
LLSDA757:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE757-LLSDACSB757
LLSDACSB757:
	.uleb128 LEHB131-LFB757
	.uleb128 LEHE131-LEHB131
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB132-LFB757
	.uleb128 LEHE132-LEHB132
	.uleb128 L727-LFB757
	.uleb128 0
	.uleb128 LEHB133-LFB757
	.uleb128 LEHE133-LEHB133
	.uleb128 0
	.uleb128 0
LLSDACSE757:
	.section	.text$_ZN6CTest6C1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC136:
	.ascii "CTest6::Constructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest6C1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest6C1EPKc
	.def	__ZN6CTest6C1EPKc;	.scl	2;	.type	32;	.endef
__ZN6CTest6C1EPKc:
LFB760:
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
	movl	$LC136, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE760:
	.section .rdata,"dr"
	.align 4
LC137:
	.ascii "CTest6::Destructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest6D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest6D1Ev
	.def	__ZN6CTest6D1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest6D1Ev:
LFB763:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA763
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC137, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE763:
	.section	.gcc_except_table,"w"
LLSDA763:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE763-LLSDACSB763
LLSDACSB763:
LLSDACSE763:
	.section	.text$_ZN6CTest6D1Ev,"x"
	.linkonce discard
	.text
	.globl	__Z10test6_sub1PKcR10IAllocator
	.def	__Z10test6_sub1PKcR10IAllocator;	.scl	2;	.type	32;	.endef
__Z10test6_sub1PKcR10IAllocator:
LFB764:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA764
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
	movl	$8, (%esp)
	call	__ZnwjR10IAllocator
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L733
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
LEHB134:
	call	__ZN6CTest6C1EPKc
LEHE134:
	movl	%ebx, %eax
	jmp	L734
L733:
	movl	%ebx, %eax
L734:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
LEHB135:
	call	_printf
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrI6CTest6EvRPT_R10IAllocator
LEHE135:
	jmp	L739
L737:
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvR10IAllocator
	movl	%esi, %eax
	jmp	L736
L738:
L736:
	movl	%eax, (%esp)
LEHB136:
	call	__Unwind_Resume
LEHE136:
L739:
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
LFE764:
	.section	.gcc_except_table,"w"
LLSDA764:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE764-LLSDACSB764
LLSDACSB764:
	.uleb128 LEHB134-LFB764
	.uleb128 LEHE134-LEHB134
	.uleb128 L737-LFB764
	.uleb128 0
	.uleb128 LEHB135-LFB764
	.uleb128 LEHE135-LEHB135
	.uleb128 L738-LFB764
	.uleb128 0
	.uleb128 LEHB136-LFB764
	.uleb128 LEHE136-LEHB136
	.uleb128 0
	.uleb128 0
LLSDACSE764:
	.text
	.globl	__Z10test6_sub2R10IAllocator
	.def	__Z10test6_sub2R10IAllocator;	.scl	2;	.type	32;	.endef
__Z10test6_sub2R10IAllocator:
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
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$28, (%esp)
	call	__ZnajR10IAllocator
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L741
	movl	$3, (%ebx)
	leal	4(%ebx), %esi
	movl	$2, %edi
	movl	%esi, -44(%ebp)
	jmp	L742
L743:
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
LEHB137:
	call	__ZN6CTest6C1Ev
LEHE137:
	addl	$8, -44(%ebp)
	subl	$1, %edi
L742:
	cmpl	$-1, %edi
	jne	L743
	leal	4(%ebx), %eax
	jmp	L744
L741:
	movl	%ebx, %eax
L744:
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
LEHB138:
	call	_printf
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$3, 4(%esp)
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10delete_ptrI6CTest6EvRPT_jR10IAllocator
LEHE138:
	jmp	L751
L749:
	movl	%eax, -44(%ebp)
	testl	%esi, %esi
	je	L746
	movl	$2, %eax
	subl	%edi, %eax
	sall	$3, %eax
	leal	(%esi,%eax), %edi
L747:
	cmpl	%esi, %edi
	je	L746
	subl	$8, %edi
	movl	%edi, (%esp)
	call	__ZN6CTest6D1Ev
	jmp	L747
L746:
	movl	-44(%ebp), %esi
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdaPvR10IAllocator
	movl	%esi, %eax
	jmp	L748
L750:
L748:
	movl	%eax, (%esp)
LEHB139:
	call	__Unwind_Resume
LEHE139:
L751:
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
LLSDA765:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE765-LLSDACSB765
LLSDACSB765:
	.uleb128 LEHB137-LFB765
	.uleb128 LEHE137-LEHB137
	.uleb128 L749-LFB765
	.uleb128 0
	.uleb128 LEHB138-LFB765
	.uleb128 LEHE138-LEHB138
	.uleb128 L750-LFB765
	.uleb128 0
	.uleb128 LEHB139-LFB765
	.uleb128 LEHE139-LEHB139
	.uleb128 0
	.uleb128 0
LLSDACSE765:
	.text
	.section .rdata,"dr"
	.align 4
LC138:
	.ascii "---------- test6:\345\205\261\351\200\232\343\202\242\343\203\255\343\202\261\343\203\274\343\202\277\343\202\244\343\203\263\343\202\277\343\203\274\343\203\225\343\202\247\343\203\274\343\202\271 ----------\0"
LC139:
	.ascii "----------CStdAllocAdp\0"
LC140:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-1\0"
LC141:
	.ascii "----------CMonoAllocAdp\0"
LC142:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-2\0"
LC143:
	.ascii "----------CStackAllocAdp\0"
LC144:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-3\0"
LC145:
	.ascii "----------CDualStackAllocAdp\0"
LC146:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-4\0"
	.align 4
LC147:
	.ascii "----------CIStackAllocAdp on CStackAllocAdp\0"
LC148:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-5\0"
	.align 4
LC149:
	.ascii "----------CIStackAllocAdp on CDualStackAllocAdp\0"
LC150:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-6\0"
LC151:
	.ascii "----------CPoolAllocAdp\0"
LC152:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "6-7\0"
	.text
	.globl	__Z5test6v
	.def	__Z5test6v;	.scl	2;	.type	32;	.endef
__Z5test6v:
LFB766:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA766
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$164, %esp
	.cfi_offset 3, -12
	movl	$LC138, (%esp)
LEHB140:
	call	_puts
LEHE140:
	movl	$LC139, (%esp)
LEHB141:
	call	_puts
LEHE141:
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN12CStdAllocAdpC1Ev
	leal	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC140, (%esp)
LEHB142:
	call	__Z10test6_sub1PKcR10IAllocator
LEHE142:
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN12CStdAllocAdpD1Ev
	movl	$LC141, (%esp)
LEHB143:
	call	_puts
LEHE143:
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN21CMonoAllocAdpWithBuffILj64EEC1Ev
	leal	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC142, (%esp)
LEHB144:
	call	__Z10test6_sub1PKcR10IAllocator
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10test6_sub2R10IAllocator
LEHE144:
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN21CMonoAllocAdpWithBuffILj64EED1Ev
	movl	$LC143, (%esp)
LEHB145:
	call	_puts
LEHE145:
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EEC1Ev
	leal	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CStackAllocAdpC1ER15CStackAllocator
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC144, (%esp)
LEHB146:
	call	__Z10test6_sub1PKcR10IAllocator
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10test6_sub2R10IAllocator
LEHE146:
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CStackAllocAdpD1Ev
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EED1Ev
	movl	$LC145, (%esp)
LEHB147:
	call	_puts
LEHE147:
	movl	$1, 4(%esp)
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EEC1EN19CDualStackAllocator9E_ORDEREDE
	movl	$0, 8(%esp)
	leal	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CDualStackAllocAdpC1ER19CDualStackAllocatorNS0_9E_ORDEREDE
	leal	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC146, (%esp)
LEHB148:
	call	__Z10test6_sub1PKcR10IAllocator
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10test6_sub2R10IAllocator
LEHE148:
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CDualStackAllocAdpD1Ev
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev
	movl	$LC147, (%esp)
LEHB149:
	call	_puts
LEHE149:
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EEC1Ev
	leal	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpC1ER15IStackAllocator
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC148, (%esp)
LEHB150:
	call	__Z10test6_sub1PKcR10IAllocator
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10test6_sub2R10IAllocator
LEHE150:
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD1Ev
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EED1Ev
	movl	$LC149, (%esp)
LEHB151:
	call	_puts
LEHE151:
	movl	$1, 4(%esp)
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EEC1EN19CDualStackAllocator9E_ORDEREDE
	leal	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpC1ER15IStackAllocator
	leal	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC150, (%esp)
LEHB152:
	call	__Z10test6_sub1PKcR10IAllocator
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10test6_sub2R10IAllocator
LEHE152:
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD1Ev
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev
	movl	$LC151, (%esp)
LEHB153:
	call	_puts
LEHE153:
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithBuffILj8ELi5EEC1Ev
	leal	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CPoolAllocAdpC1ER14CPoolAllocator
	leal	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC152, (%esp)
LEHB154:
	call	__Z10test6_sub1PKcR10IAllocator
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10test6_sub2R10IAllocator
LEHE154:
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CPoolAllocAdpD1Ev
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithBuffILj8ELi5EED1Ev
	jmp	L781
L768:
	movl	%eax, %ebx
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN12CStdAllocAdpD1Ev
	movl	%ebx, %eax
	jmp	L754
L767:
L754:
	movl	%eax, (%esp)
LEHB155:
	call	__Unwind_Resume
L770:
	movl	%eax, %ebx
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN21CMonoAllocAdpWithBuffILj64EED1Ev
	movl	%ebx, %eax
	jmp	L756
L769:
L756:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L772:
	movl	%eax, %ebx
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CStackAllocAdpD1Ev
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EED1Ev
	movl	%ebx, %eax
	jmp	L758
L771:
L758:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L774:
	movl	%eax, %ebx
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CDualStackAllocAdpD1Ev
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev
	movl	%ebx, %eax
	jmp	L760
L773:
L760:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L776:
	movl	%eax, %ebx
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD1Ev
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EED1Ev
	movl	%ebx, %eax
	jmp	L762
L775:
L762:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L778:
	movl	%eax, %ebx
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN15CIStackAllocAdpD1Ev
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev
	movl	%ebx, %eax
	jmp	L764
L777:
L764:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L780:
	movl	%eax, %ebx
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CPoolAllocAdpD1Ev
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithBuffILj8ELi5EED1Ev
	movl	%ebx, %eax
	jmp	L766
L779:
L766:
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE155:
L781:
	addl	$164, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE766:
	.section	.gcc_except_table,"w"
LLSDA766:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE766-LLSDACSB766
LLSDACSB766:
	.uleb128 LEHB140-LFB766
	.uleb128 LEHE140-LEHB140
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB141-LFB766
	.uleb128 LEHE141-LEHB141
	.uleb128 L767-LFB766
	.uleb128 0
	.uleb128 LEHB142-LFB766
	.uleb128 LEHE142-LEHB142
	.uleb128 L768-LFB766
	.uleb128 0
	.uleb128 LEHB143-LFB766
	.uleb128 LEHE143-LEHB143
	.uleb128 L769-LFB766
	.uleb128 0
	.uleb128 LEHB144-LFB766
	.uleb128 LEHE144-LEHB144
	.uleb128 L770-LFB766
	.uleb128 0
	.uleb128 LEHB145-LFB766
	.uleb128 LEHE145-LEHB145
	.uleb128 L771-LFB766
	.uleb128 0
	.uleb128 LEHB146-LFB766
	.uleb128 LEHE146-LEHB146
	.uleb128 L772-LFB766
	.uleb128 0
	.uleb128 LEHB147-LFB766
	.uleb128 LEHE147-LEHB147
	.uleb128 L773-LFB766
	.uleb128 0
	.uleb128 LEHB148-LFB766
	.uleb128 LEHE148-LEHB148
	.uleb128 L774-LFB766
	.uleb128 0
	.uleb128 LEHB149-LFB766
	.uleb128 LEHE149-LEHB149
	.uleb128 L775-LFB766
	.uleb128 0
	.uleb128 LEHB150-LFB766
	.uleb128 LEHE150-LEHB150
	.uleb128 L776-LFB766
	.uleb128 0
	.uleb128 LEHB151-LFB766
	.uleb128 LEHE151-LEHB151
	.uleb128 L777-LFB766
	.uleb128 0
	.uleb128 LEHB152-LFB766
	.uleb128 LEHE152-LEHB152
	.uleb128 L778-LFB766
	.uleb128 0
	.uleb128 LEHB153-LFB766
	.uleb128 LEHE153-LEHB153
	.uleb128 L779-LFB766
	.uleb128 0
	.uleb128 LEHB154-LFB766
	.uleb128 LEHE154-LEHB154
	.uleb128 L780-LFB766
	.uleb128 0
	.uleb128 LEHB155-LFB766
	.uleb128 LEHE155-LEHB155
	.uleb128 0
	.uleb128 0
LLSDACSE766:
	.text
	.section	.text$_ZN14CPolyAllocatorptEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPolyAllocatorptEv
	.def	__ZN14CPolyAllocatorptEv;	.scl	2;	.type	32;	.endef
__ZN14CPolyAllocatorptEv:
LFB767:
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
LFE767:
	.section	.text$_ZN14CPolyAllocator12setAllocatorER10IAllocator,"x"
	.linkonce discard
	.globl	__ZN14CPolyAllocator12setAllocatorER10IAllocator
	.def	__ZN14CPolyAllocator12setAllocatorER10IAllocator;	.scl	2;	.type	32;	.endef
__ZN14CPolyAllocator12setAllocatorER10IAllocator:
LFB770:
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
LFE770:
	.section	.text$_ZN14CPolyAllocatorC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPolyAllocatorC2Ev
	.def	__ZN14CPolyAllocatorC2Ev;	.scl	2;	.type	32;	.endef
__ZN14CPolyAllocatorC2Ev:
LFB772:
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
	jne	L786
	movl	$4, (%esp)
	call	__ZN12CStdAllocAdpnwEj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L789
	movl	%ebx, (%esp)
	call	__ZN12CStdAllocAdpC1Ev
L789:
	movl	$___emutls_v._ZN14CPolyAllocator11m_allocatorE, (%esp)
	call	___emutls_get_address
	movl	%ebx, (%eax)
L786:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE772:
	.section	.text$_ZN14CPolyAllocatorC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPolyAllocatorC1Ev
	.def	__ZN14CPolyAllocatorC1Ev;	.scl	2;	.type	32;	.endef
__ZN14CPolyAllocatorC1Ev:
LFB773:
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
	jne	L790
	movl	$4, (%esp)
	call	__ZN12CStdAllocAdpnwEj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L793
	movl	%ebx, (%esp)
	call	__ZN12CStdAllocAdpC1Ev
L793:
	movl	$___emutls_v._ZN14CPolyAllocator11m_allocatorE, (%esp)
	call	___emutls_get_address
	movl	%ebx, (%eax)
L790:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE773:
	.section	.text$_ZN14CPolyAllocatorD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPolyAllocatorD2Ev
	.def	__ZN14CPolyAllocatorD2Ev;	.scl	2;	.type	32;	.endef
__ZN14CPolyAllocatorD2Ev:
LFB775:
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
LFE775:
	.section	.text$_ZN14CPolyAllocatorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPolyAllocatorD1Ev
	.def	__ZN14CPolyAllocatorD1Ev;	.scl	2;	.type	32;	.endef
__ZN14CPolyAllocatorD1Ev:
LFB776:
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
LFE776:
	.section	.text$_ZN22CTempPolyAllocatorBaseC2ER10IAllocator,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CTempPolyAllocatorBaseC2ER10IAllocator
	.def	__ZN22CTempPolyAllocatorBaseC2ER10IAllocator;	.scl	2;	.type	32;	.endef
__ZN22CTempPolyAllocatorBaseC2ER10IAllocator:
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
LFE778:
	.section	.text$_ZN22CTempPolyAllocatorBaseD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CTempPolyAllocatorBaseD2Ev
	.def	__ZN22CTempPolyAllocatorBaseD2Ev;	.scl	2;	.type	32;	.endef
__ZN22CTempPolyAllocatorBaseD2Ev:
LFB781:
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
	je	L800
	movl	8(%ebp), %eax
	movl	(%eax), %ebx
	movl	$___emutls_v._ZN14CPolyAllocator11m_allocatorE, (%esp)
	call	___emutls_get_address
	movl	%ebx, (%eax)
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L800:
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
LFE781:
	.section	.text$_ZN18CTempPolyAllocatorI12CStdAllocAdpEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CTempPolyAllocatorI12CStdAllocAdpEC1Ev
	.def	__ZN18CTempPolyAllocatorI12CStdAllocAdpEC1Ev;	.scl	2;	.type	32;	.endef
__ZN18CTempPolyAllocatorI12CStdAllocAdpEC1Ev:
LFB787:
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
LFE787:
	.section	.text$_ZN18CTempPolyAllocatorI12CStdAllocAdpED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CTempPolyAllocatorI12CStdAllocAdpED1Ev
	.def	__ZN18CTempPolyAllocatorI12CStdAllocAdpED1Ev;	.scl	2;	.type	32;	.endef
__ZN18CTempPolyAllocatorI12CStdAllocAdpED1Ev:
LFB790:
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
LFE790:
	.section	.text$_ZN18CTempPolyAllocatorI13CMonoAllocAdpEC1ERS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CTempPolyAllocatorI13CMonoAllocAdpEC1ERS0_
	.def	__ZN18CTempPolyAllocatorI13CMonoAllocAdpEC1ERS0_;	.scl	2;	.type	32;	.endef
__ZN18CTempPolyAllocatorI13CMonoAllocAdpEC1ERS0_:
LFB793:
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
LFE793:
	.section	.text$_ZN18CTempPolyAllocatorI13CMonoAllocAdpED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CTempPolyAllocatorI13CMonoAllocAdpED1Ev
	.def	__ZN18CTempPolyAllocatorI13CMonoAllocAdpED1Ev;	.scl	2;	.type	32;	.endef
__ZN18CTempPolyAllocatorI13CMonoAllocAdpED1Ev:
LFB796:
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
LFE796:
	.section	.text$_ZN18CTempPolyAllocatorI15CStackAllocatorEC1ERS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CTempPolyAllocatorI15CStackAllocatorEC1ERS0_
	.def	__ZN18CTempPolyAllocatorI15CStackAllocatorEC1ERS0_;	.scl	2;	.type	32;	.endef
__ZN18CTempPolyAllocatorI15CStackAllocatorEC1ERS0_:
LFB799:
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
	call	__ZN14CStackAllocAdpC1ER15CStackAllocator
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE799:
	.section	.text$_ZN18CTempPolyAllocatorI15CStackAllocatorED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CTempPolyAllocatorI15CStackAllocatorED1Ev
	.def	__ZN18CTempPolyAllocatorI15CStackAllocatorED1Ev;	.scl	2;	.type	32;	.endef
__ZN18CTempPolyAllocatorI15CStackAllocatorED1Ev:
LFB802:
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
LFE802:
	.section	.text$_ZN18CTempPolyAllocatorI19CDualStackAllocatorEC1ERS0_NS0_9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CTempPolyAllocatorI19CDualStackAllocatorEC1ERS0_NS0_9E_ORDEREDE
	.def	__ZN18CTempPolyAllocatorI19CDualStackAllocatorEC1ERS0_NS0_9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN18CTempPolyAllocatorI19CDualStackAllocatorEC1ERS0_NS0_9E_ORDEREDE:
LFB805:
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
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZN18CDualStackAllocAdpC1ER19CDualStackAllocatorNS0_9E_ORDEREDE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE805:
	.section	.text$_ZN18CTempPolyAllocatorI19CDualStackAllocatorED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CTempPolyAllocatorI19CDualStackAllocatorED1Ev
	.def	__ZN18CTempPolyAllocatorI19CDualStackAllocatorED1Ev;	.scl	2;	.type	32;	.endef
__ZN18CTempPolyAllocatorI19CDualStackAllocatorED1Ev:
LFB808:
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
LFE808:
	.section	.text$_ZN18CTempPolyAllocatorI15IStackAllocatorEC1ERS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CTempPolyAllocatorI15IStackAllocatorEC1ERS0_
	.def	__ZN18CTempPolyAllocatorI15IStackAllocatorEC1ERS0_;	.scl	2;	.type	32;	.endef
__ZN18CTempPolyAllocatorI15IStackAllocatorEC1ERS0_:
LFB811:
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
	call	__ZN15CIStackAllocAdpC1ER15IStackAllocator
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE811:
	.section	.text$_ZN18CTempPolyAllocatorI15IStackAllocatorED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CTempPolyAllocatorI15IStackAllocatorED1Ev
	.def	__ZN18CTempPolyAllocatorI15IStackAllocatorED1Ev;	.scl	2;	.type	32;	.endef
__ZN18CTempPolyAllocatorI15IStackAllocatorED1Ev:
LFB814:
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
LFE814:
	.section	.text$_ZN18CTempPolyAllocatorI14CPoolAllocatorEC1ERS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CTempPolyAllocatorI14CPoolAllocatorEC1ERS0_
	.def	__ZN18CTempPolyAllocatorI14CPoolAllocatorEC1ERS0_;	.scl	2;	.type	32;	.endef
__ZN18CTempPolyAllocatorI14CPoolAllocatorEC1ERS0_:
LFB817:
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
LFE817:
	.section	.text$_ZN18CTempPolyAllocatorI14CPoolAllocatorED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN18CTempPolyAllocatorI14CPoolAllocatorED1Ev
	.def	__ZN18CTempPolyAllocatorI14CPoolAllocatorED1Ev;	.scl	2;	.type	32;	.endef
__ZN18CTempPolyAllocatorI14CPoolAllocatorED1Ev:
LFB820:
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
LFE820:
	.section .rdata,"dr"
	.align 4
LC153:
	.ascii "new(size=%d, poly_allocator=\"%s\":%d/%d/%d)\12\0"
	.text
	.globl	__Znwj
	.def	__Znwj;	.scl	2;	.type	32;	.endef
__Znwj:
LFB821:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA821
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
	leal	-29(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorC1Ev
	leal	-29(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$12, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
LEHB156:
	call	*%edx
	movl	%eax, %edi
	leal	-29(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$8, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, %esi
	leal	-29(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$4, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, %ebx
	leal	-29(%ebp), %eax
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
	movl	$LC153, (%esp)
	call	_printf
	leal	-29(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$16, %edx
	movl	(%edx), %edx
	movl	$4, 8(%esp)
	movl	8(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
LEHE156:
	movl	-28(%ebp), %ebx
	leal	-29(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorD1Ev
	movl	%ebx, %eax
	jmp	L824
L823:
	movl	%eax, %ebx
	leal	-29(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB157:
	call	__Unwind_Resume
LEHE157:
L824:
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
LFE821:
	.section	.gcc_except_table,"w"
LLSDA821:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE821-LLSDACSB821
LLSDACSB821:
	.uleb128 LEHB156-LFB821
	.uleb128 LEHE156-LEHB156
	.uleb128 L823-LFB821
	.uleb128 0
	.uleb128 LEHB157-LFB821
	.uleb128 LEHE157-LEHB157
	.uleb128 0
	.uleb128 0
LLSDACSE821:
	.text
	.section .rdata,"dr"
	.align 4
LC154:
	.ascii "new[](size=%d, poly_allocator=\"%s\":%d/%d/%d)\12\0"
	.text
	.globl	__Znaj
	.def	__Znaj;	.scl	2;	.type	32;	.endef
__Znaj:
LFB822:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA822
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
	leal	-29(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorC1Ev
	leal	-29(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$12, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
LEHB158:
	call	*%edx
	movl	%eax, %edi
	leal	-29(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$8, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, %esi
	leal	-29(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$4, %edx
	movl	(%edx), %edx
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, %ebx
	leal	-29(%ebp), %eax
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
	movl	$LC154, (%esp)
	call	_printf
	leal	-29(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorptEv
	movl	(%eax), %edx
	addl	$16, %edx
	movl	(%edx), %edx
	movl	$4, 8(%esp)
	movl	8(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC131, (%esp)
	call	_printf
LEHE158:
	movl	-28(%ebp), %ebx
	leal	-29(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorD1Ev
	movl	%ebx, %eax
	jmp	L829
L828:
	movl	%eax, %ebx
	leal	-29(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN14CPolyAllocatorD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB159:
	call	__Unwind_Resume
LEHE159:
L829:
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
LFE822:
	.section	.gcc_except_table,"w"
LLSDA822:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE822-LLSDACSB822
LLSDACSB822:
	.uleb128 LEHB158-LFB822
	.uleb128 LEHE158-LEHB158
	.uleb128 L828-LFB822
	.uleb128 0
	.uleb128 LEHB159-LFB822
	.uleb128 LEHE159-LEHB159
	.uleb128 0
	.uleb128 0
LLSDACSE822:
	.text
	.section .rdata,"dr"
	.align 4
LC155:
	.ascii "delete(p=0x%p, poly_allocator=\"%s\":%d/%d/%d)\12\0"
	.text
	.globl	__ZdlPv
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
__ZdlPv:
LFB823:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA823
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
	movl	$LC155, (%esp)
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
LFE823:
	.section	.gcc_except_table,"w"
LLSDA823:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE823-LLSDACSB823
LLSDACSB823:
LLSDACSE823:
	.text
	.section .rdata,"dr"
	.align 4
LC156:
	.ascii "delete[](p=0x%p, poly_allocator=\"%s\":%d/%d/%d)\12\0"
	.text
	.globl	__ZdaPv
	.def	__ZdaPv;	.scl	2;	.type	32;	.endef
__ZdaPv:
LFB824:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA824
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
	movl	$LC156, (%esp)
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
LFE824:
	.section	.gcc_except_table,"w"
LLSDA824:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE824-LLSDACSB824
LLSDACSB824:
LLSDACSE824:
	.text
	.section .rdata,"dr"
	.align 4
LC157:
	.ascii "CTest7::DefaultConstructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest7C1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest7C1Ev
	.def	__ZN6CTest7C1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest7C1Ev:
LFB827:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA827
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
LEHB160:
	call	__ZN6CTest7C1EPKc
LEHE160:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC157, (%esp)
LEHB161:
	call	_printf
LEHE161:
	jmp	L835
L834:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest7D1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB162:
	call	__Unwind_Resume
LEHE162:
L835:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE827:
	.section	.gcc_except_table,"w"
LLSDA827:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE827-LLSDACSB827
LLSDACSB827:
	.uleb128 LEHB160-LFB827
	.uleb128 LEHE160-LEHB160
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB161-LFB827
	.uleb128 LEHE161-LEHB161
	.uleb128 L834-LFB827
	.uleb128 0
	.uleb128 LEHB162-LFB827
	.uleb128 LEHE162-LEHB162
	.uleb128 0
	.uleb128 0
LLSDACSE827:
	.section	.text$_ZN6CTest7C1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
	.align 4
LC158:
	.ascii "CTest7::Constructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest7C1EPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest7C1EPKc
	.def	__ZN6CTest7C1EPKc;	.scl	2;	.type	32;	.endef
__ZN6CTest7C1EPKc:
LFB830:
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
	movl	$LC158, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE830:
	.section .rdata,"dr"
	.align 4
LC159:
	.ascii "CTest7::Destructor : name=\"%s\"\12\0"
	.section	.text$_ZN6CTest7D1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6CTest7D1Ev
	.def	__ZN6CTest7D1Ev;	.scl	2;	.type	32;	.endef
__ZN6CTest7D1Ev:
LFB833:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA833
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC159, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE833:
	.section	.gcc_except_table,"w"
LLSDA833:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE833-LLSDACSB833
LLSDACSB833:
LLSDACSE833:
	.section	.text$_ZN6CTest7D1Ev,"x"
	.linkonce discard
	.text
	.globl	__Z10test7_sub1PKc
	.def	__Z10test7_sub1PKc;	.scl	2;	.type	32;	.endef
__Z10test7_sub1PKc:
LFB834:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA834
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
	movl	$8, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L840
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
LEHB163:
	call	__ZN6CTest7C1EPKc
LEHE163:
	movl	%ebx, %eax
	jmp	L841
L840:
	movl	%ebx, %eax
L841:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
LEHB164:
	call	_printf
	movl	-12(%ebp), %ebx
	testl	%ebx, %ebx
	je	L845
	movl	%ebx, (%esp)
	call	__ZN6CTest7D1Ev
	movl	%ebx, (%esp)
	call	__ZdlPv
	jmp	L845
L844:
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	__ZdlPv
	movl	%esi, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE164:
L845:
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
LFE834:
	.section	.gcc_except_table,"w"
LLSDA834:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE834-LLSDACSB834
LLSDACSB834:
	.uleb128 LEHB163-LFB834
	.uleb128 LEHE163-LEHB163
	.uleb128 L844-LFB834
	.uleb128 0
	.uleb128 LEHB164-LFB834
	.uleb128 LEHE164-LEHB164
	.uleb128 0
	.uleb128 0
LLSDACSE834:
	.text
	.globl	__Z10test7_sub2v
	.def	__Z10test7_sub2v;	.scl	2;	.type	32;	.endef
__Z10test7_sub2v:
LFB835:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA835
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
	movl	$28, (%esp)
	call	__Znaj
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L847
	movl	$3, (%ebx)
	leal	4(%ebx), %esi
	movl	$2, %edi
	movl	%esi, -44(%ebp)
	jmp	L848
L849:
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
LEHB165:
	call	__ZN6CTest7C1Ev
LEHE165:
	addl	$8, -44(%ebp)
	subl	$1, %edi
L848:
	cmpl	$-1, %edi
	jne	L849
	leal	4(%ebx), %eax
	jmp	L850
L847:
	movl	%ebx, %eax
L850:
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
LEHB166:
	call	_printf
	cmpl	$0, -28(%ebp)
	je	L858
	movl	-28(%ebp), %eax
	subl	$4, %eax
	movl	(%eax), %eax
	leal	0(,%eax,8), %edx
	movl	-28(%ebp), %eax
	leal	(%edx,%eax), %ebx
L853:
	cmpl	-28(%ebp), %ebx
	je	L852
	subl	$8, %ebx
	movl	%ebx, (%esp)
	call	__ZN6CTest7D1Ev
	jmp	L853
L852:
	movl	-28(%ebp), %eax
	subl	$4, %eax
	movl	%eax, (%esp)
	call	__ZdaPv
	jmp	L858
L857:
	movl	%eax, -44(%ebp)
	testl	%esi, %esi
	je	L855
	movl	$2, %eax
	subl	%edi, %eax
	sall	$3, %eax
	leal	(%esi,%eax), %edi
L856:
	cmpl	%esi, %edi
	je	L855
	subl	$8, %edi
	movl	%edi, (%esp)
	call	__ZN6CTest7D1Ev
	jmp	L856
L855:
	movl	-44(%ebp), %esi
	movl	%ebx, (%esp)
	call	__ZdaPv
	movl	%esi, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE166:
L858:
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
LFE835:
	.section	.gcc_except_table,"w"
LLSDA835:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE835-LLSDACSB835
LLSDACSB835:
	.uleb128 LEHB165-LFB835
	.uleb128 LEHE165-LEHB165
	.uleb128 L857-LFB835
	.uleb128 0
	.uleb128 LEHB166-LFB835
	.uleb128 LEHE166-LEHB166
	.uleb128 0
	.uleb128 0
LLSDACSE835:
	.text
	.section .rdata,"dr"
	.align 4
LC160:
	.ascii "---------- test7:\343\202\260\343\203\255\343\203\274\343\203\220\343\203\253new/delete + \345\205\261\351\200\232\343\202\242\343\203\255\343\202\261\343\203\274\343\202\277\343\202\244\343\203\263\343\202\277\343\203\274\343\203\225\343\202\247\343\203\274\343\202\271 ----------\0"
LC161:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-1\0"
LC162:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-2\0"
LC163:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-3\0"
LC164:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-4\0"
LC165:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-5\0"
LC166:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-6\0"
LC167:
	.ascii "\343\203\206\343\202\271\343\203\210"
	.ascii "7-7\0"
	.text
	.globl	__Z5test7v
	.def	__Z5test7v;	.scl	2;	.type	32;	.endef
__Z5test7v:
LFB836:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA836
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$196, %esp
	.cfi_offset 3, -12
	movl	$LC160, (%esp)
LEHB167:
	call	_puts
LEHE167:
	movl	$LC139, (%esp)
LEHB168:
	call	_puts
LEHE168:
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI12CStdAllocAdpEC1Ev
	movl	$LC161, (%esp)
LEHB169:
	call	__Z10test7_sub1PKc
	call	__Z10test7_sub2v
LEHE169:
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI12CStdAllocAdpED1Ev
	movl	$LC141, (%esp)
LEHB170:
	call	_puts
LEHE170:
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN21CMonoAllocAdpWithBuffILj64EEC1Ev
	leal	-172(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI13CMonoAllocAdpEC1ERS0_
	movl	$LC162, (%esp)
LEHB171:
	call	__Z10test7_sub1PKc
	call	__Z10test7_sub2v
LEHE171:
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI13CMonoAllocAdpED1Ev
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN21CMonoAllocAdpWithBuffILj64EED1Ev
	movl	$LC143, (%esp)
LEHB172:
	call	_puts
LEHE172:
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EEC1Ev
	leal	-172(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI15CStackAllocatorEC1ERS0_
	movl	$LC163, (%esp)
LEHB173:
	call	__Z10test7_sub1PKc
	call	__Z10test7_sub2v
LEHE173:
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI15CStackAllocatorED1Ev
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EED1Ev
	movl	$LC145, (%esp)
LEHB174:
	call	_puts
LEHE174:
	movl	$1, 4(%esp)
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EEC1EN19CDualStackAllocator9E_ORDEREDE
	movl	$0, 8(%esp)
	leal	-172(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI19CDualStackAllocatorEC1ERS0_NS0_9E_ORDEREDE
	movl	$LC164, (%esp)
LEHB175:
	call	__Z10test7_sub1PKc
	call	__Z10test7_sub2v
LEHE175:
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI19CDualStackAllocatorED1Ev
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev
	movl	$LC147, (%esp)
LEHB176:
	call	_puts
LEHE176:
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EEC1Ev
	leal	-172(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI15IStackAllocatorEC1ERS0_
	movl	$LC165, (%esp)
LEHB177:
	call	__Z10test7_sub1PKc
	call	__Z10test7_sub2v
LEHE177:
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI15IStackAllocatorED1Ev
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EED1Ev
	movl	$LC149, (%esp)
LEHB178:
	call	_puts
LEHE178:
	movl	$1, 4(%esp)
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EEC1EN19CDualStackAllocator9E_ORDEREDE
	leal	-172(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI15IStackAllocatorEC1ERS0_
	movl	$LC166, (%esp)
LEHB179:
	call	__Z10test7_sub1PKc
	call	__Z10test7_sub2v
LEHE179:
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI15IStackAllocatorED1Ev
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev
	movl	$LC151, (%esp)
LEHB180:
	call	_puts
LEHE180:
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithBuffILj8ELi5EEC1Ev
	leal	-172(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI14CPoolAllocatorEC1ERS0_
	movl	$LC167, (%esp)
LEHB181:
	call	__Z10test7_sub1PKc
	call	__Z10test7_sub2v
LEHE181:
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI14CPoolAllocatorED1Ev
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithBuffILj8ELi5EED1Ev
	jmp	L888
L875:
	movl	%eax, %ebx
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI12CStdAllocAdpED1Ev
	movl	%ebx, %eax
	jmp	L861
L874:
L861:
	movl	%eax, (%esp)
LEHB182:
	call	__Unwind_Resume
L877:
	movl	%eax, %ebx
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI13CMonoAllocAdpED1Ev
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN21CMonoAllocAdpWithBuffILj64EED1Ev
	movl	%ebx, %eax
	jmp	L863
L876:
L863:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L879:
	movl	%eax, %ebx
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI15CStackAllocatorED1Ev
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EED1Ev
	movl	%ebx, %eax
	jmp	L865
L878:
L865:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L881:
	movl	%eax, %ebx
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI19CDualStackAllocatorED1Ev
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev
	movl	%ebx, %eax
	jmp	L867
L880:
L867:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L883:
	movl	%eax, %ebx
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI15IStackAllocatorED1Ev
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj64EED1Ev
	movl	%ebx, %eax
	jmp	L869
L882:
L869:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L885:
	movl	%eax, %ebx
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI15IStackAllocatorED1Ev
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev
	movl	%ebx, %eax
	jmp	L871
L884:
L871:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L887:
	movl	%eax, %ebx
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI14CPoolAllocatorED1Ev
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN22CPoolAllocatorWithBuffILj8ELi5EED1Ev
	movl	%ebx, %eax
	jmp	L873
L886:
L873:
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE182:
L888:
	addl	$196, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE836:
	.section	.gcc_except_table,"w"
LLSDA836:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE836-LLSDACSB836
LLSDACSB836:
	.uleb128 LEHB167-LFB836
	.uleb128 LEHE167-LEHB167
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB168-LFB836
	.uleb128 LEHE168-LEHB168
	.uleb128 L874-LFB836
	.uleb128 0
	.uleb128 LEHB169-LFB836
	.uleb128 LEHE169-LEHB169
	.uleb128 L875-LFB836
	.uleb128 0
	.uleb128 LEHB170-LFB836
	.uleb128 LEHE170-LEHB170
	.uleb128 L876-LFB836
	.uleb128 0
	.uleb128 LEHB171-LFB836
	.uleb128 LEHE171-LEHB171
	.uleb128 L877-LFB836
	.uleb128 0
	.uleb128 LEHB172-LFB836
	.uleb128 LEHE172-LEHB172
	.uleb128 L878-LFB836
	.uleb128 0
	.uleb128 LEHB173-LFB836
	.uleb128 LEHE173-LEHB173
	.uleb128 L879-LFB836
	.uleb128 0
	.uleb128 LEHB174-LFB836
	.uleb128 LEHE174-LEHB174
	.uleb128 L880-LFB836
	.uleb128 0
	.uleb128 LEHB175-LFB836
	.uleb128 LEHE175-LEHB175
	.uleb128 L881-LFB836
	.uleb128 0
	.uleb128 LEHB176-LFB836
	.uleb128 LEHE176-LEHB176
	.uleb128 L882-LFB836
	.uleb128 0
	.uleb128 LEHB177-LFB836
	.uleb128 LEHE177-LEHB177
	.uleb128 L883-LFB836
	.uleb128 0
	.uleb128 LEHB178-LFB836
	.uleb128 LEHE178-LEHB178
	.uleb128 L884-LFB836
	.uleb128 0
	.uleb128 LEHB179-LFB836
	.uleb128 LEHE179-LEHB179
	.uleb128 L885-LFB836
	.uleb128 0
	.uleb128 LEHB180-LFB836
	.uleb128 LEHE180-LEHB180
	.uleb128 L886-LFB836
	.uleb128 0
	.uleb128 LEHB181-LFB836
	.uleb128 LEHE181-LEHB181
	.uleb128 L887-LFB836
	.uleb128 0
	.uleb128 LEHB182-LFB836
	.uleb128 LEHE182-LEHB182
	.uleb128 0
	.uleb128 0
LLSDACSE836:
	.text
	.section .rdata,"dr"
	.align 4
LC168:
	.ascii "constexpr \343\201\253\343\202\210\343\202\213\343\202\263\343\203\263\343\203\221\343\202\244\343\203\253\346\231\202\343\201\256CRC\350\250\210\347\256\227\347\265\220\346\236\234=0x%08x\12\0"
	.align 4
LC169:
	.ascii "constexpr \343\201\253\343\202\210\343\202\213\343\203\251\343\203\263\343\202\277\343\202\244\343\203\240\346\231\202\343\201\256CRC\350\250\210\347\256\227\347\265\220\346\236\234=0x%08x\12\0"
	.align 4
LC170:
	.ascii "\343\203\246\343\203\274\343\202\266\343\203\274\345\256\232\347\276\251\343\203\252\343\203\206\343\203\251\343\203\253\343\201\253\343\202\210\343\202\213\343\202\263\343\203\263\343\203\221\343\202\244\343\203\253\346\231\202\343\201\256CRC\350\250\210\347\256\227\347\265\220\346\236\234=0x%08x\12\0"
	.text
	.globl	__Z3subv
	.def	__Z3subv;	.scl	2;	.type	32;	.endef
__Z3subv:
LFB842:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$639479525, -12(%ebp)
	movl	$639479525, 4(%esp)
	movl	$LC168, (%esp)
	call	_printf
	movl	$639479525, -16(%ebp)
	movl	$639479525, 4(%esp)
	movl	$LC169, (%esp)
	call	_printf
	movl	$639479525, -20(%ebp)
	movl	$639479525, 4(%esp)
	movl	$LC170, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE842:
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
	.section	.text$_ZNKSt4hashIjEclEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt4hashIjEclEj
	.def	__ZNKSt4hashIjEclEj;	.scl	2;	.type	32;	.endef
__ZNKSt4hashIjEclEj:
LFB1482:
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
LFE1482:
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
LFB1745:
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
LFE1745:
	.section	.text$_ZNSt8__detail15_Hash_node_baseC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail15_Hash_node_baseC1Ev
	.def	__ZNSt8__detail15_Hash_node_baseC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8__detail15_Hash_node_baseC1Ev:
LFB1746:
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
LFE1746:
	.section	.text$_ZNKSt8__detail18_Mod_range_hashingclEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail18_Mod_range_hashingclEjj
	.def	__ZNKSt8__detail18_Mod_range_hashingclEjj;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail18_Mod_range_hashingclEjj:
LFB1771:
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
LFE1771:
	.section	.text$_ZNSt8__detail20_Prime_rehash_policyC1Ef,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail20_Prime_rehash_policyC1Ef
	.def	__ZNSt8__detail20_Prime_rehash_policyC1Ef;	.scl	2;	.type	32;	.endef
__ZNSt8__detail20_Prime_rehash_policyC1Ef:
LFB1774:
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
LFE1774:
	.section	.text$_ZNKSt8__detail20_Prime_rehash_policy15max_load_factorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail20_Prime_rehash_policy15max_load_factorEv
	.def	__ZNKSt8__detail20_Prime_rehash_policy15max_load_factorEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail20_Prime_rehash_policy15max_load_factorEv:
LFB1775:
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
LFE1775:
	.section	.text$_ZNKSt8__detail20_Prime_rehash_policy19_M_bkt_for_elementsEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail20_Prime_rehash_policy19_M_bkt_for_elementsEj
	.def	__ZNKSt8__detail20_Prime_rehash_policy19_M_bkt_for_elementsEj;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail20_Prime_rehash_policy19_M_bkt_for_elementsEj:
LFB1776:
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
LFE1776:
	.section	.text$_ZNKSt8__detail20_Prime_rehash_policy8_M_stateEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail20_Prime_rehash_policy8_M_stateEv
	.def	__ZNKSt8__detail20_Prime_rehash_policy8_M_stateEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail20_Prime_rehash_policy8_M_stateEv:
LFB1777:
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
LFE1777:
	.section	.text$_ZNSt8__detail20_Prime_rehash_policy8_M_resetEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail20_Prime_rehash_policy8_M_resetEj
	.def	__ZNSt8__detail20_Prime_rehash_policy8_M_resetEj;	.scl	2;	.type	32;	.endef
__ZNSt8__detail20_Prime_rehash_policy8_M_resetEj:
LFB1778:
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
LFE1778:
	.section	.text$_ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEED1Ev
	.def	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEED1Ev:
LFB2062:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2062:
	.section	.text$_ZSt7forwardIjEOT_RNSt16remove_referenceIS0_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIjEOT_RNSt16remove_referenceIS0_E4typeE
	.def	__ZSt7forwardIjEOT_RNSt16remove_referenceIS0_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIjEOT_RNSt16remove_referenceIS0_E4typeE:
LFB2064:
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
LFE2064:
	.section	.text$_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	.def	__ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE:
LFB2065:
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
LFE2065:
	.section	.text$_ZNSt4pairIjiEC1IjivEEOT_OT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIjiEC1IjivEEOT_OT0_
	.def	__ZNSt4pairIjiEC1IjivEEOT_OT0_;	.scl	2;	.type	32;	.endef
__ZNSt4pairIjiEC1IjivEEOT_OT0_:
LFB2068:
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
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2068:
	.section	.text$_ZSt9make_pairIjiESt4pairINSt17__decay_and_stripIT_E6__typeENS1_IT0_E6__typeEEOS2_OS5_,"x"
	.linkonce discard
	.globl	__ZSt9make_pairIjiESt4pairINSt17__decay_and_stripIT_E6__typeENS1_IT0_E6__typeEEOS2_OS5_
	.def	__ZSt9make_pairIjiESt4pairINSt17__decay_and_stripIT_E6__typeENS1_IT0_E6__typeEEOS2_OS5_;	.scl	2;	.type	32;	.endef
__ZSt9make_pairIjiESt4pairINSt17__decay_and_stripIT_E6__typeENS1_IT0_E6__typeEEOS2_OS5_:
LFB2063:
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
	call	__ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIjEOT_RNSt16remove_referenceIS0_E4typeE
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt4pairIjiEC1IjivEEOT_OT0_
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
LFE2063:
	.section	.text$_ZNSt4pairIKjiEC1IjivEEOS_IT_T0_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIKjiEC1IjivEEOS_IT_T0_E
	.def	__ZNSt4pairIKjiEC1IjivEEOS_IT_T0_E;	.scl	2;	.type	32;	.endef
__ZNSt4pairIKjiEC1IjivEEOS_IT_T0_E:
LFB2071:
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
	call	__ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2071:
	.section .rdata,"dr"
	.align 4
LC172:
	.ascii "---------- test8:\346\250\231\346\272\226\343\203\251\343\202\244\343\203\226\343\203\251\343\203\252\343\202\222\344\276\277\345\210\251\343\201\253\345\210\251\347\224\250 ----------\0"
LC173:
	.ascii "\346\226\207\345\255\227\345\210\227\343\201\250\0"
LC174:
	.ascii "\346\226\207\345\255\227\345\210\227\343\202\222\0"
	.align 4
LC175:
	.ascii "\347\265\220\345\220\210\343\201\231\343\202\213\343\202\210\343\201\206\343\201\252\345\207\246\347\220\206\343\201\247\343\201\257\343\200\201\0"
LC176:
	.ascii "std::string\343\201\214\0"
LC177:
	.ascii "\343\202\204\343\201\243\343\201\261\343\202\212\344\276\277\345\210\251!!\0"
LC178:
	.ascii "str_buff=\"%s\"\12\0"
LC179:
	.ascii "already reserved\0"
LC180:
	.ascii "\345\244\252\351\203\216\0"
LC181:
	.ascii "\346\254\241\351\203\216\0"
LC182:
	.ascii "\344\270\211\351\203\216\0"
LC183:
	.ascii "already inserted\0"
LC184:
	.ascii "individual data print\0"
LC185:
	.ascii "\"%s\"=%d\12\0"
LC186:
	.ascii "each data print\0"
	.text
	.globl	__Z5test8v
	.def	__Z5test8v;	.scl	2;	.type	32;	.endef
__Z5test8v:
LFB2059:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2059
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	movl	$8612, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	.cfi_offset 3, -12
	movl	$LC172, (%esp)
LEHB183:
	call	_puts
LEHE183:
	movl	$LC143, (%esp)
LEHB184:
	call	_puts
LEHE184:
	leal	-8452(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj1024EEC1Ev
	leal	-8452(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI15CStackAllocatorEC1ERS0_
	leal	-133(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-133(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC173, 4(%esp)
	leal	-152(%ebp), %eax
	movl	%eax, (%esp)
LEHB185:
	call	__ZNSsC1EPKcRKSaIcE
LEHE185:
	leal	-133(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-132(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC174, 4(%esp)
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
LEHB186:
	call	__ZNSsC1EPKcRKSaIcE
LEHE186:
	leal	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-131(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-131(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC175, 4(%esp)
	leal	-160(%ebp), %eax
	movl	%eax, (%esp)
LEHB187:
	call	__ZNSsC1EPKcRKSaIcE
LEHE187:
	leal	-131(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-130(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-130(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC176, 4(%esp)
	leal	-164(%ebp), %eax
	movl	%eax, (%esp)
LEHB188:
	call	__ZNSsC1EPKcRKSaIcE
LEHE188:
	leal	-130(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-129(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-129(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC177, 4(%esp)
	leal	-168(%ebp), %eax
	movl	%eax, (%esp)
LEHB189:
	call	__ZNSsC1EPKcRKSaIcE
LEHE189:
	leal	-129(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-120(%ebp), %eax
	leal	-156(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-152(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB190:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_
LEHE190:
	subl	$4, %esp
	leal	-124(%ebp), %eax
	leal	-160(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-120(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB191:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_
LEHE191:
	subl	$4, %esp
	leal	-128(%ebp), %eax
	leal	-164(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-124(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB192:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_
LEHE192:
	subl	$4, %esp
	leal	-172(%ebp), %eax
	leal	-168(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-128(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB193:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_
LEHE193:
	subl	$4, %esp
	leal	-128(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSs5c_strEv
	movl	%eax, 4(%esp)
	leal	-8580(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcpy
	leal	-172(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-168(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-164(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-160(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-8580(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC178, (%esp)
LEHB194:
	call	_printf
LEHE194:
	leal	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI15CStackAllocatorED1Ev
	leal	-8452(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj1024EED1Ev
	movl	$LC139, (%esp)
LEHB195:
	call	_puts
LEHE195:
	leal	-113(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-113(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC173, 4(%esp)
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
LEHB196:
	call	__ZNSsC1EPKcRKSaIcE
LEHE196:
	leal	-113(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-112(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC174, 4(%esp)
	leal	-180(%ebp), %eax
	movl	%eax, (%esp)
LEHB197:
	call	__ZNSsC1EPKcRKSaIcE
LEHE197:
	leal	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-111(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-111(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC175, 4(%esp)
	leal	-184(%ebp), %eax
	movl	%eax, (%esp)
LEHB198:
	call	__ZNSsC1EPKcRKSaIcE
LEHE198:
	leal	-111(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-110(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-110(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC176, 4(%esp)
	leal	-188(%ebp), %eax
	movl	%eax, (%esp)
LEHB199:
	call	__ZNSsC1EPKcRKSaIcE
LEHE199:
	leal	-110(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-109(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-109(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC177, 4(%esp)
	leal	-192(%ebp), %eax
	movl	%eax, (%esp)
LEHB200:
	call	__ZNSsC1EPKcRKSaIcE
LEHE200:
	leal	-109(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-100(%ebp), %eax
	leal	-180(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-176(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB201:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_
LEHE201:
	subl	$4, %esp
	leal	-104(%ebp), %eax
	leal	-184(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-100(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB202:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_
LEHE202:
	subl	$4, %esp
	leal	-108(%ebp), %eax
	leal	-188(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-104(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB203:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_
LEHE203:
	subl	$4, %esp
	leal	-196(%ebp), %eax
	leal	-192(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-108(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB204:
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_
LEHE204:
	subl	$4, %esp
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-100(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-196(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSs5c_strEv
	movl	%eax, 4(%esp)
	leal	-8452(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcpy
	leal	-196(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-192(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-188(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-184(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-180(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-8452(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC178, (%esp)
LEHB205:
	call	_printf
LEHE205:
	movl	$LC143, (%esp)
LEHB206:
	call	_puts
LEHE206:
	leal	-8452(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj8192EEC1Ev
	leal	-8452(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-208(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI15CStackAllocatorEC1ERS0_
	leal	-95(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISt4pairIKjiEEC1Ev
	leal	-95(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-94(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-93(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$10, 4(%esp)
	leal	-232(%ebp), %eax
	movl	%eax, (%esp)
LEHB207:
	call	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEEC1EjRKS1_RKS3_RKS7_
LEHE207:
	leal	-95(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISt4pairIKjiEED1Ev
	movl	$100, 4(%esp)
	leal	-232(%ebp), %eax
	movl	%eax, (%esp)
LEHB208:
	call	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE7reserveEj
	movl	$LC179, (%esp)
	call	_puts
LEHE208:
	movl	$123, -84(%ebp)
	movl	$LC180, %eax
	movl	%eax, -80(%ebp)
	leal	-84(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt9make_pairIjiESt4pairINSt17__decay_and_stripIT_E6__typeENS1_IT0_E6__typeEEOS2_OS5_
	movl	%eax, -92(%ebp)
	movl	%edx, -88(%ebp)
	leal	-92(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-232(%ebp), %eax
	movl	%eax, (%esp)
LEHB209:
	call	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE6insertIS4_IjiEvEES4_INSt8__detail14_Node_iteratorIS6_Lb0ELb0EEEbEOT_
LEHE209:
	movl	$456, -68(%ebp)
	movl	$LC181, %eax
	movl	%eax, -64(%ebp)
	leal	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt9make_pairIjiESt4pairINSt17__decay_and_stripIT_E6__typeENS1_IT0_E6__typeEEOS2_OS5_
	movl	%eax, -76(%ebp)
	movl	%edx, -72(%ebp)
	leal	-76(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-232(%ebp), %eax
	movl	%eax, (%esp)
LEHB210:
	call	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE6insertIS4_IjiEvEES4_INSt8__detail14_Node_iteratorIS6_Lb0ELb0EEEbEOT_
LEHE210:
	movl	$789, -52(%ebp)
	movl	$LC182, %eax
	movl	%eax, -48(%ebp)
	leal	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt9make_pairIjiESt4pairINSt17__decay_and_stripIT_E6__typeENS1_IT0_E6__typeEEOS2_OS5_
	movl	%eax, -60(%ebp)
	movl	%edx, -56(%ebp)
	leal	-60(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-232(%ebp), %eax
	movl	%eax, (%esp)
LEHB211:
	call	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE6insertIS4_IjiEvEES4_INSt8__detail14_Node_iteratorIS6_Lb0ELb0EEEbEOT_
LEHE211:
	movl	$LC183, (%esp)
LEHB212:
	call	_puts
	movl	$LC184, (%esp)
	call	_puts
LEHE212:
	movl	$LC180, %eax
	movl	%eax, -40(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-232(%ebp), %eax
	movl	%eax, (%esp)
LEHB213:
	call	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE4findERS5_
LEHE213:
	movl	%eax, -44(%ebp)
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEptEv
	movl	4(%eax), %eax
	movl	%eax, 8(%esp)
	movl	$LC180, 4(%esp)
	movl	$LC185, (%esp)
LEHB214:
	call	_printf
LEHE214:
	movl	$LC181, %eax
	movl	%eax, -32(%ebp)
	leal	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-232(%ebp), %eax
	movl	%eax, (%esp)
LEHB215:
	call	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE4findERS5_
LEHE215:
	movl	%eax, -36(%ebp)
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEptEv
	movl	4(%eax), %eax
	movl	%eax, 8(%esp)
	movl	$LC181, 4(%esp)
	movl	$LC185, (%esp)
LEHB216:
	call	_printf
LEHE216:
	movl	$LC182, %eax
	movl	%eax, -24(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-232(%ebp), %eax
	movl	%eax, (%esp)
LEHB217:
	call	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE4findERS5_
LEHE217:
	movl	%eax, -28(%ebp)
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEptEv
	movl	4(%eax), %eax
	movl	%eax, 8(%esp)
	movl	$LC182, 4(%esp)
	movl	$LC185, (%esp)
LEHB218:
	call	_printf
LEHE218:
	movl	$LC186, (%esp)
LEHB219:
	call	_puts
LEHE219:
	leal	-232(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE5beginEv
	movl	%eax, -236(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE3endEv
	movl	%eax, -240(%ebp)
	jmp	L915
L916:
	leal	-236(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEdeEv
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	4(%eax), %edx
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC185, (%esp)
LEHB220:
	call	_printf
	leal	-236(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEppEv
LEHE220:
L915:
	leal	-240(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-236(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detailneISt4pairIKjiELb0EEEbRKNS_19_Node_iterator_baseIT_XT0_EEES8_
	testb	%al, %al
	jne	L916
	leal	-232(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE6cbeginEv
	movl	%eax, -244(%ebp)
	jmp	L917
L918:
	leal	-244(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEptEv
	movl	4(%eax), %ebx
	leal	-244(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEptEv
	movl	(%eax), %eax
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC185, (%esp)
LEHB221:
	call	_printf
	leal	-244(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEppEv
LEHE221:
L917:
	leal	-232(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE4cendEv
	movl	%eax, -20(%ebp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-244(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detailneISt4pairIKjiELb0EEEbRKNS_19_Node_iterator_baseIT_XT0_EEES8_
	testb	%al, %al
	jne	L918
	leal	-232(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEED1Ev
	leal	-208(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI15CStackAllocatorED1Ev
	leal	-8452(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj8192EED1Ev
LEHB222:
	call	__Z3subv
	jmp	L1000
L966:
	movl	%eax, %ebx
	leal	-133(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	movl	%ebx, %eax
	jmp	L920
L967:
	movl	%eax, %ebx
	leal	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L922
L968:
	movl	%eax, %ebx
	leal	-131(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L924
L969:
	movl	%eax, %ebx
	leal	-130(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L926
L970:
	movl	%eax, %ebx
	leal	-129(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L928
L974:
	movl	%eax, %ebx
	leal	-128(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L930
L973:
	movl	%eax, %ebx
L930:
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L931
L972:
	movl	%eax, %ebx
L931:
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L932
L971:
	movl	%eax, %ebx
L932:
	leal	-168(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L928:
	leal	-164(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L926:
	leal	-160(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L924:
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L922:
	leal	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	movl	%ebx, %eax
L920:
	movl	%eax, %ebx
	jmp	L933
L975:
	movl	%eax, %ebx
L933:
	leal	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI15CStackAllocatorED1Ev
	leal	-8452(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj1024EED1Ev
	movl	%ebx, %eax
	jmp	L934
L965:
L934:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L977:
	movl	%eax, %ebx
	leal	-113(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	movl	%ebx, %eax
	jmp	L949
L978:
	movl	%eax, %ebx
	leal	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L938
L979:
	movl	%eax, %ebx
	leal	-111(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L940
L980:
	movl	%eax, %ebx
	leal	-110(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L942
L981:
	movl	%eax, %ebx
	leal	-109(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L944
L985:
	movl	%eax, %ebx
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L946
L984:
	movl	%eax, %ebx
L946:
	leal	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L947
L983:
	movl	%eax, %ebx
L947:
	leal	-100(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L948
L982:
	movl	%eax, %ebx
L948:
	leal	-192(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L944:
	leal	-188(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L942:
	leal	-184(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L940:
	leal	-180(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
L938:
	leal	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	movl	%ebx, %eax
	jmp	L949
L976:
L949:
	movl	%eax, (%esp)
	call	__Unwind_Resume
L987:
	movl	%eax, %ebx
	leal	-95(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISt4pairIKjiEED1Ev
	movl	%ebx, %eax
	jmp	L951
L989:
	movl	%eax, %ebx
	jmp	L953
L990:
	movl	%eax, %ebx
	jmp	L953
L991:
	movl	%eax, %ebx
	jmp	L953
L993:
	jmp	L957
L992:
L957:
	movl	%eax, %ebx
	jmp	L953
L995:
	jmp	L959
L994:
L959:
	movl	%eax, %ebx
	jmp	L953
L997:
	jmp	L961
L996:
L961:
	movl	%eax, %ebx
	jmp	L953
L998:
	movl	%eax, %ebx
	jmp	L953
L999:
	movl	%eax, %ebx
	jmp	L953
L988:
	movl	%eax, %ebx
L953:
	leal	-232(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEED1Ev
	movl	%ebx, %eax
L951:
	movl	%eax, %ebx
	leal	-208(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN18CTempPolyAllocatorI15CStackAllocatorED1Ev
	leal	-8452(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN23CStackAllocatorWithBuffILj8192EED1Ev
	movl	%ebx, %eax
	jmp	L964
L986:
L964:
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE222:
L1000:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
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
	.uleb128 LEHB183-LFB2059
	.uleb128 LEHE183-LEHB183
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB184-LFB2059
	.uleb128 LEHE184-LEHB184
	.uleb128 L965-LFB2059
	.uleb128 0
	.uleb128 LEHB185-LFB2059
	.uleb128 LEHE185-LEHB185
	.uleb128 L966-LFB2059
	.uleb128 0
	.uleb128 LEHB186-LFB2059
	.uleb128 LEHE186-LEHB186
	.uleb128 L967-LFB2059
	.uleb128 0
	.uleb128 LEHB187-LFB2059
	.uleb128 LEHE187-LEHB187
	.uleb128 L968-LFB2059
	.uleb128 0
	.uleb128 LEHB188-LFB2059
	.uleb128 LEHE188-LEHB188
	.uleb128 L969-LFB2059
	.uleb128 0
	.uleb128 LEHB189-LFB2059
	.uleb128 LEHE189-LEHB189
	.uleb128 L970-LFB2059
	.uleb128 0
	.uleb128 LEHB190-LFB2059
	.uleb128 LEHE190-LEHB190
	.uleb128 L971-LFB2059
	.uleb128 0
	.uleb128 LEHB191-LFB2059
	.uleb128 LEHE191-LEHB191
	.uleb128 L972-LFB2059
	.uleb128 0
	.uleb128 LEHB192-LFB2059
	.uleb128 LEHE192-LEHB192
	.uleb128 L973-LFB2059
	.uleb128 0
	.uleb128 LEHB193-LFB2059
	.uleb128 LEHE193-LEHB193
	.uleb128 L974-LFB2059
	.uleb128 0
	.uleb128 LEHB194-LFB2059
	.uleb128 LEHE194-LEHB194
	.uleb128 L975-LFB2059
	.uleb128 0
	.uleb128 LEHB195-LFB2059
	.uleb128 LEHE195-LEHB195
	.uleb128 L976-LFB2059
	.uleb128 0
	.uleb128 LEHB196-LFB2059
	.uleb128 LEHE196-LEHB196
	.uleb128 L977-LFB2059
	.uleb128 0
	.uleb128 LEHB197-LFB2059
	.uleb128 LEHE197-LEHB197
	.uleb128 L978-LFB2059
	.uleb128 0
	.uleb128 LEHB198-LFB2059
	.uleb128 LEHE198-LEHB198
	.uleb128 L979-LFB2059
	.uleb128 0
	.uleb128 LEHB199-LFB2059
	.uleb128 LEHE199-LEHB199
	.uleb128 L980-LFB2059
	.uleb128 0
	.uleb128 LEHB200-LFB2059
	.uleb128 LEHE200-LEHB200
	.uleb128 L981-LFB2059
	.uleb128 0
	.uleb128 LEHB201-LFB2059
	.uleb128 LEHE201-LEHB201
	.uleb128 L982-LFB2059
	.uleb128 0
	.uleb128 LEHB202-LFB2059
	.uleb128 LEHE202-LEHB202
	.uleb128 L983-LFB2059
	.uleb128 0
	.uleb128 LEHB203-LFB2059
	.uleb128 LEHE203-LEHB203
	.uleb128 L984-LFB2059
	.uleb128 0
	.uleb128 LEHB204-LFB2059
	.uleb128 LEHE204-LEHB204
	.uleb128 L985-LFB2059
	.uleb128 0
	.uleb128 LEHB205-LFB2059
	.uleb128 LEHE205-LEHB205
	.uleb128 L976-LFB2059
	.uleb128 0
	.uleb128 LEHB206-LFB2059
	.uleb128 LEHE206-LEHB206
	.uleb128 L986-LFB2059
	.uleb128 0
	.uleb128 LEHB207-LFB2059
	.uleb128 LEHE207-LEHB207
	.uleb128 L987-LFB2059
	.uleb128 0
	.uleb128 LEHB208-LFB2059
	.uleb128 LEHE208-LEHB208
	.uleb128 L988-LFB2059
	.uleb128 0
	.uleb128 LEHB209-LFB2059
	.uleb128 LEHE209-LEHB209
	.uleb128 L989-LFB2059
	.uleb128 0
	.uleb128 LEHB210-LFB2059
	.uleb128 LEHE210-LEHB210
	.uleb128 L990-LFB2059
	.uleb128 0
	.uleb128 LEHB211-LFB2059
	.uleb128 LEHE211-LEHB211
	.uleb128 L991-LFB2059
	.uleb128 0
	.uleb128 LEHB212-LFB2059
	.uleb128 LEHE212-LEHB212
	.uleb128 L988-LFB2059
	.uleb128 0
	.uleb128 LEHB213-LFB2059
	.uleb128 LEHE213-LEHB213
	.uleb128 L992-LFB2059
	.uleb128 0
	.uleb128 LEHB214-LFB2059
	.uleb128 LEHE214-LEHB214
	.uleb128 L993-LFB2059
	.uleb128 0
	.uleb128 LEHB215-LFB2059
	.uleb128 LEHE215-LEHB215
	.uleb128 L994-LFB2059
	.uleb128 0
	.uleb128 LEHB216-LFB2059
	.uleb128 LEHE216-LEHB216
	.uleb128 L995-LFB2059
	.uleb128 0
	.uleb128 LEHB217-LFB2059
	.uleb128 LEHE217-LEHB217
	.uleb128 L996-LFB2059
	.uleb128 0
	.uleb128 LEHB218-LFB2059
	.uleb128 LEHE218-LEHB218
	.uleb128 L997-LFB2059
	.uleb128 0
	.uleb128 LEHB219-LFB2059
	.uleb128 LEHE219-LEHB219
	.uleb128 L988-LFB2059
	.uleb128 0
	.uleb128 LEHB220-LFB2059
	.uleb128 LEHE220-LEHB220
	.uleb128 L998-LFB2059
	.uleb128 0
	.uleb128 LEHB221-LFB2059
	.uleb128 LEHE221-LEHB221
	.uleb128 L999-LFB2059
	.uleb128 0
	.uleb128 LEHB222-LFB2059
	.uleb128 LEHE222-LEHB222
	.uleb128 0
	.uleb128 0
LLSDACSE2059:
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC187:
	.ascii "---------- main:start ----------\0"
	.align 4
LC188:
	.ascii "---------- main:end ----------\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB2072:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	$LC187, (%esp)
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
	movl	$LC188, (%esp)
	call	_puts
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2072:
	.section	.text$_Z7new_ptrI6CTest0IPKcEEPT_PcDpT0_,"x"
	.linkonce discard
	.globl	__Z7new_ptrI6CTest0IPKcEEPT_PcDpT0_
	.def	__Z7new_ptrI6CTest0IPKcEEPT_PcDpT0_;	.scl	2;	.type	32;	.endef
__Z7new_ptrI6CTest0IPKcEEPT_PcDpT0_:
LFB2073:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2073
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
	jne	L1004
	movl	$0, %eax
	jmp	L1010
L1004:
	movl	8(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	$4, (%esp)
	call	__ZnwjPc
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1006
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
LEHB223:
	call	__ZN6CTest0C1EPKc
LEHE223:
	movl	%ebx, %eax
	jmp	L1007
L1006:
	movl	%ebx, %eax
L1007:
	nop
	jmp	L1010
L1009:
	movl	%eax, %edi
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvPc
	movl	%edi, %eax
	movl	%eax, (%esp)
LEHB224:
	call	__Unwind_Resume
LEHE224:
L1010:
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
LFE2073:
	.section	.gcc_except_table,"w"
LLSDA2073:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2073-LLSDACSB2073
LLSDACSB2073:
	.uleb128 LEHB223-LFB2073
	.uleb128 LEHE223-LEHB223
	.uleb128 L1009-LFB2073
	.uleb128 0
	.uleb128 LEHB224-LFB2073
	.uleb128 LEHE224-LEHB224
	.uleb128 0
	.uleb128 0
LLSDACSE2073:
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
LFB2074:
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
	jne	L1012
	jmp	L1011
L1012:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest0D1Ev
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1011:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2074:
	.section .rdata,"dr"
LC189:
	.ascii "delete_ptr(p=0x%p)\12\0"
	.section	.text$_Z10delete_ptrI6CTest1EvRPT_,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI6CTest1EvRPT_
	.def	__Z10delete_ptrI6CTest1EvRPT_;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI6CTest1EvRPT_:
LFB2075:
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
	movl	$LC189, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1015
	jmp	L1014
L1015:
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
L1014:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2075:
	.section .rdata,"dr"
	.align 4
LC190:
	.ascii "delete_ptr(p=0x%p, array_num=%d)\12\0"
	.section	.text$_Z10delete_ptrI6CTest1EvRPT_j,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI6CTest1EvRPT_j
	.def	__Z10delete_ptrI6CTest1EvRPT_j;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI6CTest1EvRPT_j:
LFB2076:
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
	movl	$LC190, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1018
	jmp	L1017
L1018:
	movl	$0, -12(%ebp)
	jmp	L1020
L1021:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest1D1Ev
	addl	$1, -12(%ebp)
L1020:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1021
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdaPvPc
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1017:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2076:
	.section	.text$_Z10delete_ptrIcEvRPT_,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIcEvRPT_
	.def	__Z10delete_ptrIcEvRPT_;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIcEvRPT_:
LFB2077:
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
	movl	$LC189, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1023
	jmp	L1022
L1023:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvPc
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1022:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2077:
	.section	.text$_Z10delete_ptrIcEvRPT_j,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIcEvRPT_j
	.def	__Z10delete_ptrIcEvRPT_j;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIcEvRPT_j:
LFB2078:
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
	movl	$LC190, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1026
	jmp	L1025
L1026:
	movl	$0, -12(%ebp)
	jmp	L1028
L1029:
	addl	$1, -12(%ebp)
L1028:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1029
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdaPvPc
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1025:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2078:
	.section	.text$_Z10delete_ptrI8CTest1exEvRPT_,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI8CTest1exEvRPT_
	.def	__Z10delete_ptrI8CTest1exEvRPT_;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI8CTest1exEvRPT_:
LFB2079:
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
	movl	$LC189, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1031
	jmp	L1030
L1031:
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
L1030:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2079:
	.section	.text$_ZN10CSingletonI6CTest3EC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CSingletonI6CTest3EC1Ev
	.def	__ZN10CSingletonI6CTest3EC1Ev;	.scl	2;	.type	32;	.endef
__ZN10CSingletonI6CTest3EC1Ev:
LFB2082:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2082
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
	jne	L1039
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZnwI6CTest3EPvjR10CSingletonIT_E
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1035
	movl	%ebx, (%esp)
LEHB225:
	call	__ZN6CTest3C1Ev
LEHE225:
	movl	%ebx, %eax
	jmp	L1036
L1035:
	movl	%ebx, %eax
L1036:
	movl	%eax, __ZN10CSingletonI6CTest3E11m_singletonE
	jmp	L1039
L1038:
	movl	%eax, %esi
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlI6CTest3EvPvR10CSingletonIT_E
	movl	%esi, %eax
	movl	%eax, (%esp)
LEHB226:
	call	__Unwind_Resume
LEHE226:
L1039:
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
LFE2082:
	.section	.gcc_except_table,"w"
LLSDA2082:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2082-LLSDACSB2082
LLSDACSB2082:
	.uleb128 LEHB225-LFB2082
	.uleb128 LEHE225-LEHB225
	.uleb128 L1038-LFB2082
	.uleb128 0
	.uleb128 LEHB226-LFB2082
	.uleb128 LEHE226-LEHB226
	.uleb128 0
	.uleb128 0
LLSDACSE2082:
	.section	.text$_ZN10CSingletonI6CTest3EC1Ev,"x"
	.linkonce discard
	.section	.text$_ZN10CSingletonI6CTest3EptEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CSingletonI6CTest3EptEv
	.def	__ZN10CSingletonI6CTest3EptEv;	.scl	2;	.type	32;	.endef
__ZN10CSingletonI6CTest3EptEv:
LFB2083:
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
LFE2083:
	.section	.text$_ZN10CSingletonI6CTest3E7destroyEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CSingletonI6CTest3E7destroyEv
	.def	__ZN10CSingletonI6CTest3E7destroyEv;	.scl	2;	.type	32;	.endef
__ZN10CSingletonI6CTest3E7destroyEv:
LFB2084:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	__ZN10CSingletonI6CTest3E11m_singletonE, %eax
	testl	%eax, %eax
	jne	L1043
	jmp	L1042
L1043:
	movl	__ZN10CSingletonI6CTest3E11m_singletonE, %eax
	movl	%eax, (%esp)
	call	__ZN6CTest3D1Ev
	movl	__ZN10CSingletonI6CTest3E11m_singletonE, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlI6CTest3EvPvR10CSingletonIT_E
	movl	$0, __ZN10CSingletonI6CTest3E11m_singletonE
L1042:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2084:
	.section	.text$_ZN23CStackAllocatorWithBuffILj64EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj64EEC1Ev
	.def	__ZN23CStackAllocatorWithBuffILj64EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj64EEC1Ev:
LFB2087:
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
LFE2087:
	.section	.text$_ZN23CStackAllocatorWithBuffILj64EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj64EED1Ev
	.def	__ZN23CStackAllocatorWithBuffILj64EED1Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj64EED1Ev:
LFB2090:
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
	je	L1046
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1046:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2090:
	.section	.text$_ZN23CStackAllocatorWithBuffILj64EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj64EED0Ev
	.def	__ZN23CStackAllocatorWithBuffILj64EED0Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj64EED0Ev:
LFB2091:
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
LFE2091:
	.section .rdata,"dr"
	.align 4
LC191:
	.ascii "delete_ptr(p=0x%p, array_num=%d, stack_allocator.marker=%d)\12\0"
	.section	.text$_Z10delete_ptrIfEvRPT_jR15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIfEvRPT_jR15CStackAllocator
	.def	__Z10delete_ptrIfEvRPT_jR15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIfEvRPT_jR15CStackAllocator:
LFB2092:
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
	movl	$LC191, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1052
	jmp	L1051
L1052:
	movl	$0, -12(%ebp)
	jmp	L1054
L1055:
	addl	$1, -12(%ebp)
L1054:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1055
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1051:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2092:
	.section	.text$_Z10delete_ptrIcEvRPT_jR15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIcEvRPT_jR15CStackAllocator
	.def	__Z10delete_ptrIcEvRPT_jR15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIcEvRPT_jR15CStackAllocator:
LFB2093:
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
	movl	$LC191, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1057
	jmp	L1056
L1057:
	movl	$0, -12(%ebp)
	jmp	L1059
L1060:
	addl	$1, -12(%ebp)
L1059:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1060
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1056:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2093:
	.section	.text$_Z10delete_ptrIiEvRPT_jR15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIiEvRPT_jR15CStackAllocator
	.def	__Z10delete_ptrIiEvRPT_jR15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIiEvRPT_jR15CStackAllocator:
LFB2094:
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
	movl	$LC191, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1062
	jmp	L1061
L1062:
	movl	$0, -12(%ebp)
	jmp	L1064
L1065:
	addl	$1, -12(%ebp)
L1064:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1065
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1061:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2094:
	.section .rdata,"dr"
	.align 4
LC192:
	.ascii "delete_ptr(p=0x%p, stack_allocator.marker=%d)\12\0"
	.section	.text$_Z10delete_ptrI7CTest4aEvRPT_R15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI7CTest4aEvRPT_R15CStackAllocator
	.def	__Z10delete_ptrI7CTest4aEvRPT_R15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI7CTest4aEvRPT_R15CStackAllocator:
LFB2095:
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
	movl	$LC192, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1067
	jmp	L1066
L1067:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN7CTest4aD1Ev
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1066:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2095:
	.section	.text$_Z10delete_ptrIfEvRPT_R15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIfEvRPT_R15CStackAllocator
	.def	__Z10delete_ptrIfEvRPT_R15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIfEvRPT_R15CStackAllocator:
LFB2096:
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
	movl	$LC192, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1070
	jmp	L1069
L1070:
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1069:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2096:
	.section	.text$_Z10delete_ptrIcEvRPT_R15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIcEvRPT_R15CStackAllocator
	.def	__Z10delete_ptrIcEvRPT_R15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIcEvRPT_R15CStackAllocator:
LFB2097:
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
	movl	$LC192, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1073
	jmp	L1072
L1073:
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1072:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2097:
	.section	.text$_Z10delete_ptrIiEvRPT_R15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIiEvRPT_R15CStackAllocator
	.def	__Z10delete_ptrIiEvRPT_R15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIiEvRPT_R15CStackAllocator:
LFB2098:
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
	movl	$LC192, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1076
	jmp	L1075
L1076:
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1075:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2098:
	.section	.text$_Z10delete_ptrI7CTest4aEvRPT_jR15CStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI7CTest4aEvRPT_jR15CStackAllocator
	.def	__Z10delete_ptrI7CTest4aEvRPT_jR15CStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI7CTest4aEvRPT_jR15CStackAllocator:
LFB2099:
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
	movl	$LC191, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1079
	jmp	L1078
L1079:
	movl	$0, -12(%ebp)
	jmp	L1081
L1082:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN7CTest4aD1Ev
	addl	$1, -12(%ebp)
L1081:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1082
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1078:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2099:
	.section	.text$_ZN27CDualStackAllocatorWithBuffILj64EEC1EN19CDualStackAllocator9E_ORDEREDE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN27CDualStackAllocatorWithBuffILj64EEC1EN19CDualStackAllocator9E_ORDEREDE
	.def	__ZN27CDualStackAllocatorWithBuffILj64EEC1EN19CDualStackAllocator9E_ORDEREDE;	.scl	2;	.type	32;	.endef
__ZN27CDualStackAllocatorWithBuffILj64EEC1EN19CDualStackAllocator9E_ORDEREDE:
LFB2102:
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
	call	__ZN19CDualStackAllocatorC2EPvjNS_9E_ORDEREDE
	movl	8(%ebp), %eax
	movl	$__ZTV27CDualStackAllocatorWithBuffILj64EE+8, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2102:
	.section	.text$_ZN27CDualStackAllocatorWithBuffILj64EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev
	.def	__ZN27CDualStackAllocatorWithBuffILj64EED1Ev;	.scl	2;	.type	32;	.endef
__ZN27CDualStackAllocatorWithBuffILj64EED1Ev:
LFB2105:
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
	je	L1084
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1084:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2105:
	.section	.text$_ZN27CDualStackAllocatorWithBuffILj64EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN27CDualStackAllocatorWithBuffILj64EED0Ev
	.def	__ZN27CDualStackAllocatorWithBuffILj64EED0Ev;	.scl	2;	.type	32;	.endef
__ZN27CDualStackAllocatorWithBuffILj64EED0Ev:
LFB2106:
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
LFE2106:
	.section .rdata,"dr"
	.align 4
LC193:
	.ascii "delete_ptr(p=0x%p, array_num=%d, dual_allocator.marker=%d,%d)\12\0"
	.section	.text$_Z10delete_ptrIfEvRPT_jR19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIfEvRPT_jR19CDualStackAllocator
	.def	__Z10delete_ptrIfEvRPT_jR19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIfEvRPT_jR19CDualStackAllocator:
LFB2107:
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
	movl	$LC193, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1090
	jmp	L1089
L1090:
	movl	$0, -12(%ebp)
	jmp	L1092
L1093:
	addl	$1, -12(%ebp)
L1092:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1093
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1089:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2107:
	.section	.text$_Z10delete_ptrIcEvRPT_jR19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIcEvRPT_jR19CDualStackAllocator
	.def	__Z10delete_ptrIcEvRPT_jR19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIcEvRPT_jR19CDualStackAllocator:
LFB2108:
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
	movl	$LC193, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1095
	jmp	L1094
L1095:
	movl	$0, -12(%ebp)
	jmp	L1097
L1098:
	addl	$1, -12(%ebp)
L1097:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1098
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1094:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2108:
	.section	.text$_Z10delete_ptrIiEvRPT_jR19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIiEvRPT_jR19CDualStackAllocator
	.def	__Z10delete_ptrIiEvRPT_jR19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIiEvRPT_jR19CDualStackAllocator:
LFB2109:
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
	movl	$LC193, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1100
	jmp	L1099
L1100:
	movl	$0, -12(%ebp)
	jmp	L1102
L1103:
	addl	$1, -12(%ebp)
L1102:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1103
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1099:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2109:
	.section .rdata,"dr"
	.align 4
LC194:
	.ascii "delete_ptr(p=0x%p, dual_allocator.marker=%d,%d)\12\0"
	.section	.text$_Z10delete_ptrI7CTest4bEvRPT_R19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI7CTest4bEvRPT_R19CDualStackAllocator
	.def	__Z10delete_ptrI7CTest4bEvRPT_R19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI7CTest4bEvRPT_R19CDualStackAllocator:
LFB2110:
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
	movl	$LC194, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1105
	jmp	L1104
L1105:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN7CTest4bD1Ev
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1104:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2110:
	.section	.text$_Z10delete_ptrIfEvRPT_R19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIfEvRPT_R19CDualStackAllocator
	.def	__Z10delete_ptrIfEvRPT_R19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIfEvRPT_R19CDualStackAllocator:
LFB2111:
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
	movl	$LC194, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1108
	jmp	L1107
L1108:
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1107:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2111:
	.section	.text$_Z10delete_ptrIcEvRPT_R19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIcEvRPT_R19CDualStackAllocator
	.def	__Z10delete_ptrIcEvRPT_R19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIcEvRPT_R19CDualStackAllocator:
LFB2112:
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
	movl	$LC194, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1111
	jmp	L1110
L1111:
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1110:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2112:
	.section	.text$_Z10delete_ptrIiEvRPT_R19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrIiEvRPT_R19CDualStackAllocator
	.def	__Z10delete_ptrIiEvRPT_R19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrIiEvRPT_R19CDualStackAllocator:
LFB2113:
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
	movl	$LC194, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1114
	jmp	L1113
L1114:
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1113:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2113:
	.section	.text$_Z10delete_ptrI7CTest4bEvRPT_jR19CDualStackAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI7CTest4bEvRPT_jR19CDualStackAllocator
	.def	__Z10delete_ptrI7CTest4bEvRPT_jR19CDualStackAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI7CTest4bEvRPT_jR19CDualStackAllocator:
LFB2114:
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
	movl	$LC193, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1117
	jmp	L1116
L1117:
	movl	$0, -12(%ebp)
	jmp	L1119
L1120:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN7CTest4bD1Ev
	addl	$1, -12(%ebp)
L1119:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1120
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1116:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2114:
	.section	.text$_ZNKSt13__atomic_baseIiE4loadESt12memory_order,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13__atomic_baseIiE4loadESt12memory_order
	.def	__ZNKSt13__atomic_baseIiE4loadESt12memory_order;	.scl	2;	.type	32;	.endef
__ZNKSt13__atomic_baseIiE4loadESt12memory_order:
LFB2133:
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
LFE2133:
	.section	.text$_ZNSt13__atomic_baseIiE5storeEiSt12memory_order,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13__atomic_baseIiE5storeEiSt12memory_order
	.def	__ZNSt13__atomic_baseIiE5storeEiSt12memory_order;	.scl	2;	.type	32;	.endef
__ZNSt13__atomic_baseIiE5storeEiSt12memory_order:
LFB2134:
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
LFE2134:
	.section	.text$_ZNSt13__atomic_baseIiE9fetch_addEiSt12memory_order,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13__atomic_baseIiE9fetch_addEiSt12memory_order
	.def	__ZNSt13__atomic_baseIiE9fetch_addEiSt12memory_order;	.scl	2;	.type	32;	.endef
__ZNSt13__atomic_baseIiE9fetch_addEiSt12memory_order:
LFB2135:
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
LFE2135:
	.section	.text$_ZNSt13__atomic_baseIiE9fetch_subEiSt12memory_order,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13__atomic_baseIiE9fetch_subEiSt12memory_order
	.def	__ZNSt13__atomic_baseIiE9fetch_subEiSt12memory_order;	.scl	2;	.type	32;	.endef
__ZNSt13__atomic_baseIiE9fetch_subEiSt12memory_order:
LFB2136:
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
LFE2136:
	.section	.text$_ZN22CPoolAllocatorWithTypeI6CTest5Li5EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EEC1Ev
	.def	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithTypeI6CTest5Li5EEC1Ev:
LFB2139:
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
LFE2139:
	.section	.text$_ZN22CPoolAllocatorWithTypeI6CTest5Li5EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EED1Ev
	.def	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EED1Ev;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithTypeI6CTest5Li5EED1Ev:
LFB2142:
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
LFE2142:
	.section	.text$_ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_
	.def	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_:
LFB2143:
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
LFE2143:
	.weak	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIJPKcEEEPS0_DpT_
	.def	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIJPKcEEEPS0_DpT_;	.scl	2;	.type	32;	.endef
	.set	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIJPKcEEEPS0_DpT_,__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE10createDataIIPKcEEEPS0_DpT_
	.section	.text$_ZN22CPoolAllocatorWithTypeI6CTest5Li5EE11destroyDataERPS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE11destroyDataERPS0_
	.def	__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE11destroyDataERPS0_;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithTypeI6CTest5Li5EE11destroyDataERPS0_:
LFB2144:
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
LFE2144:
	.section	.text$_ZN14CPoolAllocator6createI7CTest5LIEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createI7CTest5LIEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createI7CTest5LIEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createI7CTest5LIEEEPT_DpT0_:
LFB2145:
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
	je	L1136
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	movb	$0, 8(%eax)
L1136:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2145:
	.weak	__ZN14CPoolAllocator6createI7CTest5LJEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createI7CTest5LJEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN14CPoolAllocator6createI7CTest5LJEEEPT_DpT0_,__ZN14CPoolAllocator6createI7CTest5LIEEEPT_DpT0_
	.section	.text$_ZN14CPoolAllocator6createIcIEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createIcIEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIcIEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createIcIEEEPT_DpT0_:
LFB2146:
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
	je	L1140
	movb	$0, (%eax)
L1140:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2146:
	.weak	__ZN14CPoolAllocator6createIcJEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIcJEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN14CPoolAllocator6createIcJEEEPT_DpT0_,__ZN14CPoolAllocator6createIcIEEEPT_DpT0_
	.section	.text$_ZN14CPoolAllocator6createIsIEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createIsIEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIsIEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createIsIEEEPT_DpT0_:
LFB2147:
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
	je	L1144
	movw	$0, (%eax)
L1144:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2147:
	.weak	__ZN14CPoolAllocator6createIsJEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIsJEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN14CPoolAllocator6createIsJEEEPT_DpT0_,__ZN14CPoolAllocator6createIsIEEEPT_DpT0_
	.section	.text$_ZN14CPoolAllocator6createIiIEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createIiIEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIiIEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createIiIEEEPT_DpT0_:
LFB2148:
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
	je	L1148
	movl	$0, (%eax)
L1148:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2148:
	.weak	__ZN14CPoolAllocator6createIiJEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIiJEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN14CPoolAllocator6createIiJEEEPT_DpT0_,__ZN14CPoolAllocator6createIiIEEEPT_DpT0_
	.section	.text$_ZN14CPoolAllocator6createIfIEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createIfIEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIfIEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createIfIEEEPT_DpT0_:
LFB2149:
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
	je	L1152
	movl	LC195, %edx
	movl	%edx, (%eax)
L1152:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2149:
	.weak	__ZN14CPoolAllocator6createIfJEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIfJEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN14CPoolAllocator6createIfJEEEPT_DpT0_,__ZN14CPoolAllocator6createIfIEEEPT_DpT0_
	.section	.text$_ZN14CPoolAllocator6createIdIEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createIdIEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIdIEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createIdIEEEPT_DpT0_:
LFB2150:
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
	je	L1156
	fldz
	fstpl	(%eax)
L1156:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2150:
	.weak	__ZN14CPoolAllocator6createIdJEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIdJEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN14CPoolAllocator6createIdJEEEPT_DpT0_,__ZN14CPoolAllocator6createIdIEEEPT_DpT0_
	.section	.text$_ZN14CPoolAllocator6createIxIEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createIxIEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIxIEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createIxIEEEPT_DpT0_:
LFB2151:
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
	je	L1160
	movl	$0, (%eax)
	movl	$0, 4(%eax)
L1160:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2151:
	.weak	__ZN14CPoolAllocator6createIxJEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createIxJEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN14CPoolAllocator6createIxJEEEPT_DpT0_,__ZN14CPoolAllocator6createIxIEEEPT_DpT0_
	.section	.text$_ZN14CPoolAllocator7destroyI7CTest5LEEvRPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7destroyI7CTest5LEEvRPT_
	.def	__ZN14CPoolAllocator7destroyI7CTest5LEEvRPT_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7destroyI7CTest5LEEvRPT_:
LFB2152:
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
	jne	L1163
	jmp	L1162
L1163:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	12(%ebp), %eax
	movl	$0, (%eax)
L1162:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2152:
	.section	.text$_ZN14CPoolAllocator7destroyIcEEvRPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7destroyIcEEvRPT_
	.def	__ZN14CPoolAllocator7destroyIcEEvRPT_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7destroyIcEEvRPT_:
LFB2153:
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
	jne	L1166
	jmp	L1165
L1166:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	12(%ebp), %eax
	movl	$0, (%eax)
L1165:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2153:
	.section	.text$_ZN14CPoolAllocator7destroyIsEEvRPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7destroyIsEEvRPT_
	.def	__ZN14CPoolAllocator7destroyIsEEvRPT_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7destroyIsEEvRPT_:
LFB2154:
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
	jne	L1169
	jmp	L1168
L1169:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	12(%ebp), %eax
	movl	$0, (%eax)
L1168:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2154:
	.section	.text$_ZN14CPoolAllocator7destroyIiEEvRPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7destroyIiEEvRPT_
	.def	__ZN14CPoolAllocator7destroyIiEEvRPT_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7destroyIiEEvRPT_:
LFB2155:
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
	jne	L1172
	jmp	L1171
L1172:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	12(%ebp), %eax
	movl	$0, (%eax)
L1171:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2155:
	.section	.text$_ZN14CPoolAllocator7destroyIfEEvRPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7destroyIfEEvRPT_
	.def	__ZN14CPoolAllocator7destroyIfEEvRPT_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7destroyIfEEvRPT_:
LFB2156:
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
	jne	L1175
	jmp	L1174
L1175:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	12(%ebp), %eax
	movl	$0, (%eax)
L1174:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2156:
	.section	.text$_ZN14CPoolAllocator7destroyIdEEvRPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7destroyIdEEvRPT_
	.def	__ZN14CPoolAllocator7destroyIdEEvRPT_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7destroyIdEEvRPT_:
LFB2157:
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
	jne	L1178
	jmp	L1177
L1178:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	12(%ebp), %eax
	movl	$0, (%eax)
L1177:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2157:
	.section	.text$_ZN14CPoolAllocator7destroyIxEEvRPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator7destroyIxEEvRPT_
	.def	__ZN14CPoolAllocator7destroyIxEEvRPT_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator7destroyIxEEvRPT_:
LFB2158:
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
	jne	L1181
	jmp	L1180
L1181:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	12(%ebp), %eax
	movl	$0, (%eax)
L1180:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2158:
	.section .rdata,"dr"
	.align 4
LC197:
	.ascii "delete_ptr(p=0x%p, i_allocator=\"%s\":%d/%d/%d)\12\0"
	.section	.text$_Z10delete_ptrI6CTest6EvRPT_R10IAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI6CTest6EvRPT_R10IAllocator
	.def	__Z10delete_ptrI6CTest6EvRPT_R10IAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI6CTest6EvRPT_R10IAllocator:
LFB2159:
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
	movl	$LC197, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1184
	jmp	L1183
L1184:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest6D1Ev
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdlPvR10IAllocator
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1183:
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
LFE2159:
	.section .rdata,"dr"
	.align 4
LC198:
	.ascii "delete_ptr(p=0x%p, array_num=%d, i_allocator=\"%s\":%d/%d/%d)\12\0"
	.section	.text$_Z10delete_ptrI6CTest6EvRPT_jR10IAllocator,"x"
	.linkonce discard
	.globl	__Z10delete_ptrI6CTest6EvRPT_jR10IAllocator
	.def	__Z10delete_ptrI6CTest6EvRPT_jR10IAllocator;	.scl	2;	.type	32;	.endef
__Z10delete_ptrI6CTest6EvRPT_jR10IAllocator:
LFB2160:
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
	movl	$LC198, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1187
	jmp	L1186
L1187:
	movl	$0, -28(%ebp)
	jmp	L1189
L1190:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZN6CTest6D1Ev
	addl	$1, -28(%ebp)
L1189:
	movl	-28(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L1190
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZdaPvR10IAllocator
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L1186:
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
LFE2160:
	.section	.text$_ZN21CMonoAllocAdpWithBuffILj64EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN21CMonoAllocAdpWithBuffILj64EEC1Ev
	.def	__ZN21CMonoAllocAdpWithBuffILj64EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN21CMonoAllocAdpWithBuffILj64EEC1Ev:
LFB2163:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$12, %esp
	movl	8(%ebp), %eax
	leal	13(%eax), %edx
	movl	8(%ebp), %eax
	movl	$64, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN13CMonoAllocAdpC2EPvj
	movl	8(%ebp), %eax
	movl	$__ZTV21CMonoAllocAdpWithBuffILj64EE+8, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2163:
	.section	.text$_ZN21CMonoAllocAdpWithBuffILj64EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN21CMonoAllocAdpWithBuffILj64EED1Ev
	.def	__ZN21CMonoAllocAdpWithBuffILj64EED1Ev;	.scl	2;	.type	32;	.endef
__ZN21CMonoAllocAdpWithBuffILj64EED1Ev:
LFB2166:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZTV21CMonoAllocAdpWithBuffILj64EE+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN13CMonoAllocAdpD2Ev
	movl	$0, %eax
	testl	%eax, %eax
	je	L1192
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1192:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2166:
	.section	.text$_ZN21CMonoAllocAdpWithBuffILj64EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN21CMonoAllocAdpWithBuffILj64EED0Ev
	.def	__ZN21CMonoAllocAdpWithBuffILj64EED0Ev;	.scl	2;	.type	32;	.endef
__ZN21CMonoAllocAdpWithBuffILj64EED0Ev:
LFB2167:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN21CMonoAllocAdpWithBuffILj64EED1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2167:
	.section	.text$_ZN22CPoolAllocatorWithBuffILj8ELi5EEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithBuffILj8ELi5EEC2Ev
	.def	__ZN22CPoolAllocatorWithBuffILj8ELi5EEC2Ev;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithBuffILj8ELi5EEC2Ev:
LFB2169:
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
LFE2169:
	.section	.text$_ZN22CPoolAllocatorWithBuffILj8ELi5EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithBuffILj8ELi5EEC1Ev
	.def	__ZN22CPoolAllocatorWithBuffILj8ELi5EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithBuffILj8ELi5EEC1Ev:
LFB2170:
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
LFE2170:
	.section	.text$_ZN22CPoolAllocatorWithBuffILj8ELi5EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithBuffILj8ELi5EED2Ev
	.def	__ZN22CPoolAllocatorWithBuffILj8ELi5EED2Ev;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithBuffILj8ELi5EED2Ev:
LFB2172:
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
LFE2172:
	.section	.text$_ZN22CPoolAllocatorWithBuffILj8ELi5EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN22CPoolAllocatorWithBuffILj8ELi5EED1Ev
	.def	__ZN22CPoolAllocatorWithBuffILj8ELi5EED1Ev;	.scl	2;	.type	32;	.endef
__ZN22CPoolAllocatorWithBuffILj8ELi5EED1Ev:
LFB2173:
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
LFE2173:
	.section	.text$_ZN23CStackAllocatorWithBuffILj1024EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj1024EEC1Ev
	.def	__ZN23CStackAllocatorWithBuffILj1024EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj1024EEC1Ev:
LFB2186:
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
LFE2186:
	.section	.text$_ZN23CStackAllocatorWithBuffILj1024EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj1024EED1Ev
	.def	__ZN23CStackAllocatorWithBuffILj1024EED1Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj1024EED1Ev:
LFB2189:
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
	je	L1204
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1204:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2189:
	.section	.text$_ZN23CStackAllocatorWithBuffILj1024EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj1024EED0Ev
	.def	__ZN23CStackAllocatorWithBuffILj1024EED0Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj1024EED0Ev:
LFB2190:
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
LFE2190:
	.section	.text$_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_,"x"
	.linkonce discard
	.globl	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_
	.def	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_;	.scl	2;	.type	32;	.endef
__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_:
LFB2209:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2209
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
LEHB227:
	call	__ZNSsC1ERKSs
LEHE227:
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB228:
	call	__ZNSs6appendERKSs
LEHE228:
	jmp	L1213
L1212:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB229:
	call	__Unwind_Resume
LEHE229:
L1213:
	movl	8(%ebp), %eax
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE2209:
	.section	.gcc_except_table,"w"
LLSDA2209:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2209-LLSDACSB2209
LLSDACSB2209:
	.uleb128 LEHB227-LFB2209
	.uleb128 LEHE227-LEHB227
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB228-LFB2209
	.uleb128 LEHE228-LEHB228
	.uleb128 L1212-LFB2209
	.uleb128 0
	.uleb128 LEHB229-LFB2209
	.uleb128 LEHE229-LEHB229
	.uleb128 0
	.uleb128 0
LLSDACSE2209:
	.section	.text$_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_,"x"
	.linkonce discard
	.section	.text$_ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_
	.def	__ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_:
LFB2211:
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
LFE2211:
	.section	.text$_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_,"x"
	.linkonce discard
	.globl	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_
	.def	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_;	.scl	2;	.type	32;	.endef
__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_EOS6_RKS6_:
LFB2210:
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
LFE2210:
	.section	.text$_ZN23CStackAllocatorWithBuffILj8192EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj8192EEC1Ev
	.def	__ZN23CStackAllocatorWithBuffILj8192EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj8192EEC1Ev:
LFB2215:
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
LFE2215:
	.section	.text$_ZN23CStackAllocatorWithBuffILj8192EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj8192EED1Ev
	.def	__ZN23CStackAllocatorWithBuffILj8192EED1Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj8192EED1Ev:
LFB2218:
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
	je	L1219
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L1219:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2218:
	.section	.text$_ZN23CStackAllocatorWithBuffILj8192EED0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN23CStackAllocatorWithBuffILj8192EED0Ev
	.def	__ZN23CStackAllocatorWithBuffILj8192EED0Ev;	.scl	2;	.type	32;	.endef
__ZN23CStackAllocatorWithBuffILj8192EED0Ev:
LFB2219:
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
LFE2219:
	.section	.text$_ZNSaISt4pairIKjiEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt4pairIKjiEEC1Ev
	.def	__ZNSaISt4pairIKjiEEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSaISt4pairIKjiEEC1Ev:
LFB2222:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorISt4pairIKjiEEC2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2222:
	.section	.text$_ZNSaISt4pairIKjiEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt4pairIKjiEED1Ev
	.def	__ZNSaISt4pairIKjiEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSaISt4pairIKjiEED1Ev:
LFB2225:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorISt4pairIKjiEED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2225:
	.section	.text$_ZNSt17__allow_copy_consILb1EEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt17__allow_copy_consILb1EEC2Ev
	.def	__ZNSt17__allow_copy_consILb1EEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt17__allow_copy_consILb1EEC2Ev:
LFB2228:
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
LFE2228:
	.section	.text$_ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEEC1EjRKS1_RKS3_RKS7_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEEC1EjRKS1_RKS3_RKS7_
	.def	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEEC1EjRKS1_RKS3_RKS7_;	.scl	2;	.type	32;	.endef
__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEEC1EjRKS1_RKS3_RKS7_:
LFB2231:
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
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKS9_RKS7_RKS3_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2231:
	.section	.text$_ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjiELb0EEEEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjiELb0EEEEED1Ev
	.def	__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjiELb0EEEEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjiELb0EEEEED1Ev:
LFB2235:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2235:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED1Ev
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED1Ev:
LFB2237:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2237
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEPPNS4_15_Hash_node_baseEj
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjiELb0EEEEED1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2237:
	.section	.gcc_except_table,"w"
LLSDA2237:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2237-LLSDACSB2237
LLSDACSB2237:
LLSDACSE2237:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE7reserveEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE7reserveEj
	.def	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE7reserveEj;	.scl	2;	.type	32;	.endef
__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE7reserveEj:
LFB2238:
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
	call	__ZNSt8__detail12_Rehash_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE7reserveEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2238:
	.section	.text$_ZSt7forwardISt4pairIjiEEOT_RNSt16remove_referenceIS2_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardISt4pairIjiEEOT_RNSt16remove_referenceIS2_E4typeE
	.def	__ZSt7forwardISt4pairIjiEEOT_RNSt16remove_referenceIS2_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardISt4pairIjiEEOT_RNSt16remove_referenceIS2_E4typeE:
LFB2240:
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
LFE2240:
	.section	.text$_ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE6insertIS4_IjiEvEES4_INSt8__detail14_Node_iteratorIS6_Lb0ELb0EEEbEOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE6insertIS4_IjiEvEES4_INSt8__detail14_Node_iteratorIS6_Lb0ELb0EEEbEOT_
	.def	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE6insertIS4_IjiEvEES4_INSt8__detail14_Node_iteratorIS6_Lb0ELb0EEEbEOT_;	.scl	2;	.type	32;	.endef
__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE6insertIS4_IjiEvEES4_INSt8__detail14_Node_iteratorIS6_Lb0ELb0EEEbEOT_:
LFB2239:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt4pairIjiEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	8(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt8__detail7_InsertIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EE6insertIS1_IjiEvEES1_INS_14_Node_iteratorIS3_Lb0ELb0EEEbEOT_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2239:
	.section	.text$_ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE4findERS5_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE4findERS5_
	.def	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE4findERS5_;	.scl	2;	.type	32;	.endef
__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE4findERS5_:
LFB2241:
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
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE4findERS1_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2241:
	.section	.text$_ZNKSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEptEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEptEv
	.def	__ZNKSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEptEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEptEv:
LFB2242:
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
	call	__ZSt11__addressofISt4pairIKjiEEPT_RS3_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2242:
	.section	.text$_ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE5beginEv
	.def	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE5beginEv;	.scl	2;	.type	32;	.endef
__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE5beginEv:
LFB2243:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5beginEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2243:
	.section	.text$_ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE3endEv
	.def	__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE3endEv:
LFB2244:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2244:
	.section	.text$_ZNSt8__detailneISt4pairIKjiELb0EEEbRKNS_19_Node_iterator_baseIT_XT0_EEES8_,"x"
	.linkonce discard
	.globl	__ZNSt8__detailneISt4pairIKjiELb0EEEbRKNS_19_Node_iterator_baseIT_XT0_EEES8_
	.def	__ZNSt8__detailneISt4pairIKjiELb0EEEbRKNS_19_Node_iterator_baseIT_XT0_EEES8_;	.scl	2;	.type	32;	.endef
__ZNSt8__detailneISt4pairIKjiELb0EEEbRKNS_19_Node_iterator_baseIT_XT0_EEES8_:
LFB2245:
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
	setne	%al
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2245:
	.section	.text$_ZNSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEppEv
	.def	__ZNSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEppEv;	.scl	2;	.type	32;	.endef
__ZNSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEppEv:
LFB2246:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail19_Node_iterator_baseISt4pairIKjiELb0EE7_M_incrEv
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2246:
	.section	.text$_ZNKSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEdeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEdeEv
	.def	__ZNKSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEdeEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEdeEv:
LFB2247:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2247:
	.section	.text$_ZNKSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE6cbeginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE6cbeginEv
	.def	__ZNKSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE6cbeginEv;	.scl	2;	.type	32;	.endef
__ZNKSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE6cbeginEv:
LFB2248:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5beginEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2248:
	.section	.text$_ZNKSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE4cendEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE4cendEv
	.def	__ZNKSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE4cendEv;	.scl	2;	.type	32;	.endef
__ZNKSt13unordered_mapIjiSt4hashIjESt8equal_toIjESaISt4pairIKjiEEE4cendEv:
LFB2249:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2249:
	.section	.text$_ZNSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEppEv
	.def	__ZNSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEppEv;	.scl	2;	.type	32;	.endef
__ZNSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEppEv:
LFB2250:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail19_Node_iterator_baseISt4pairIKjiELb0EE7_M_incrEv
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2250:
	.section	.text$_ZNKSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEptEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEptEv
	.def	__ZNKSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEptEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEptEv:
LFB2251:
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
	call	__ZSt11__addressofISt4pairIKjiEEPT_RS3_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2251:
	.section	.text$_ZnwI6CTest3EPvjR10CSingletonIT_E,"x"
	.linkonce discard
	.globl	__ZnwI6CTest3EPvjR10CSingletonIT_E
	.def	__ZnwI6CTest3EPvjR10CSingletonIT_E;	.scl	2;	.type	32;	.endef
__ZnwI6CTest3EPvjR10CSingletonIT_E:
LFB2252:
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
LFE2252:
	.section	.text$_ZdlI6CTest3EvPvR10CSingletonIT_E,"x"
	.linkonce discard
	.globl	__ZdlI6CTest3EvPvR10CSingletonIT_E
	.def	__ZdlI6CTest3EvPvR10CSingletonIT_E;	.scl	2;	.type	32;	.endef
__ZdlI6CTest3EvPvR10CSingletonIT_E:
LFB2253:
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
LFE2253:
	.section	.text$_ZN14CPoolAllocator6createI6CTest5IPKcEEEPT_DpT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN14CPoolAllocator6createI6CTest5IPKcEEEPT_DpT0_
	.def	__ZN14CPoolAllocator6createI6CTest5IPKcEEEPT_DpT0_;	.scl	2;	.type	32;	.endef
__ZN14CPoolAllocator6createI6CTest5IPKcEEEPT_DpT0_:
LFB2254:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2254
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
	je	L1264
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
LEHB230:
	call	__ZN6CTest5C1EPKc
LEHE230:
	movl	%ebx, %eax
	jmp	L1269
L1264:
	movl	%ebx, %eax
	jmp	L1269
L1268:
	movl	%eax, %esi
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvR14CPoolAllocator
	movl	%esi, %eax
	movl	%eax, (%esp)
LEHB231:
	call	__Unwind_Resume
LEHE231:
L1269:
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
LFE2254:
	.section	.gcc_except_table,"w"
LLSDA2254:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2254-LLSDACSB2254
LLSDACSB2254:
	.uleb128 LEHB230-LFB2254
	.uleb128 LEHE230-LEHB230
	.uleb128 L1268-LFB2254
	.uleb128 0
	.uleb128 LEHB231-LFB2254
	.uleb128 LEHE231-LEHB231
	.uleb128 0
	.uleb128 0
LLSDACSE2254:
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
LFB2255:
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
	jne	L1271
	jmp	L1270
L1271:
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
L1270:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2255:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt4pairIKjiEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt4pairIKjiEEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISt4pairIKjiEEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt4pairIKjiEEC2Ev:
LFB2279:
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
LFE2279:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt4pairIKjiEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt4pairIKjiEED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISt4pairIKjiEED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt4pairIKjiEED2Ev:
LFB2282:
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
LFE2282:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKS9_RKS7_RKS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKS9_RKS7_RKS3_
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKS9_RKS7_RKS3_;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKS9_RKS7_RKS3_:
LFB2286:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2286
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
LEHB232:
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKS9_RKSA_RKSB_RKS7_RKS5_RKS3_
LEHE232:
	jmp	L1279
L1278:
	movl	%eax, (%esp)
LEHB233:
	call	__Unwind_Resume
LEHE233:
L1279:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2286:
	.section	.gcc_except_table,"w"
LLSDA2286:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2286-LLSDACSB2286
LLSDACSB2286:
	.uleb128 LEHB232-LFB2286
	.uleb128 LEHE232-LEHB232
	.uleb128 L1278-LFB2286
	.uleb128 0
	.uleb128 LEHB233-LFB2286
	.uleb128 LEHE233-LEHB233
	.uleb128 0
	.uleb128 0
LLSDACSE2286:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKS9_RKS7_RKS3_,"x"
	.linkonce discard
	.section	.text$_ZNSaINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEED2Ev
	.def	__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEED2Ev;	.scl	2;	.type	32;	.endef
__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEED2Ev:
LFB2288:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2288:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv:
LFB2290:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2290
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE8_M_beginEv
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_deallocate_nodesEPNS4_10_Hash_nodeIS2_Lb0EEE
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
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	$0, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2290:
	.section	.gcc_except_table,"w"
LLSDA2290:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2290-LLSDACSB2290
LLSDACSB2290:
LLSDACSE2290:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5clearEv,"x"
	.linkonce discard
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEPPNS4_15_Hash_node_baseEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEPPNS4_15_Hash_node_baseEj
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEPPNS4_15_Hash_node_baseEj;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEPPNS4_15_Hash_node_baseEj:
LFB2291:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	movl	%eax, 4(%esp)
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIPNSt8__detail15_Hash_node_baseEEC1INS_10_Hash_nodeISt4pairIKjiELb0EEEEERKSaIT_E
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
LFE2291:
	.section	.text$_ZNSt8__detail12_Rehash_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE7reserveEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail12_Rehash_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE7reserveEj
	.def	__ZNSt8__detail12_Rehash_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE7reserveEj;	.scl	2;	.type	32;	.endef
__ZNSt8__detail12_Rehash_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE7reserveEj:
LFB2292:
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
	call	__ZNKSt8__detail12_Rehash_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE15max_load_factorEv
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
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE6rehashEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2292:
	.section	.text$_ZNSt8__detail7_InsertIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EE6insertIS1_IjiEvEES1_INS_14_Node_iteratorIS3_Lb0ELb0EEEbEOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail7_InsertIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EE6insertIS1_IjiEvEES1_INS_14_Node_iteratorIS3_Lb0ELb0EEEbEOT_
	.def	__ZNSt8__detail7_InsertIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EE6insertIS1_IjiEvEES1_INS_14_Node_iteratorIS3_Lb0ELb0EEEbEOT_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail7_InsertIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EE6insertIS1_IjiEvEES1_INS_14_Node_iteratorIS3_Lb0ELb0EEEbEOT_:
LFB2293:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2293
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
	call	__ZNSt8__detail12_Insert_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE20_M_conjure_hashtableEv
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt4pairIjiEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, 8(%esp)
	movb	%bl, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
LEHB234:
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIIS0_IjiEEEES0_INS4_14_Node_iteratorIS2_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_
LEHE234:
	jmp	L1289
L1288:
	movl	%eax, (%esp)
LEHB235:
	call	__Unwind_Resume
LEHE235:
L1289:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2293:
	.section	.gcc_except_table,"w"
LLSDA2293:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2293-LLSDACSB2293
LLSDACSB2293:
	.uleb128 LEHB234-LFB2293
	.uleb128 LEHE234-LEHB234
	.uleb128 L1288-LFB2293
	.uleb128 0
	.uleb128 LEHB235-LFB2293
	.uleb128 LEHE235-LEHB235
	.uleb128 0
	.uleb128 0
LLSDACSE2293:
	.section	.text$_ZNSt8__detail7_InsertIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EE6insertIS1_IjiEvEES1_INS_14_Node_iteratorIS3_Lb0ELb0EEEbEOT_,"x"
	.linkonce discard
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE4findERS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE4findERS1_
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE4findERS1_;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE4findERS1_:
LFB2294:
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
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE12_M_hash_codeERS2_
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexERS1_j
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE12_M_find_nodeEjRS1_j
	movl	%eax, -20(%ebp)
	cmpl	$0, -20(%ebp)
	je	L1291
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEC1EPNS_10_Hash_nodeIS3_Lb0EEE
	jmp	L1292
L1291:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv
	movl	%eax, -24(%ebp)
L1292:
	movl	-24(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2294:
	.section	.text$_ZSt11__addressofISt4pairIKjiEEPT_RS3_,"x"
	.linkonce discard
	.globl	__ZSt11__addressofISt4pairIKjiEEPT_RS3_
	.def	__ZSt11__addressofISt4pairIKjiEEPT_RS3_;	.scl	2;	.type	32;	.endef
__ZSt11__addressofISt4pairIKjiEEPT_RS3_:
LFB2295:
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
LFE2295:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5beginEv
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5beginEv;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5beginEv:
LFB2296:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2296
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE8_M_beginEv
	movl	%eax, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEC1EPNS_10_Hash_nodeIS3_Lb0EEE
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2296:
	.section	.gcc_except_table,"w"
LLSDA2296:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2296-LLSDACSB2296
LLSDACSB2296:
LLSDACSE2296:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5beginEv,"x"
	.linkonce discard
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv:
LFB2297:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2297
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEC1EPNS_10_Hash_nodeIS3_Lb0EEE
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2297:
	.section	.gcc_except_table,"w"
LLSDA2297:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2297-LLSDACSB2297
LLSDACSB2297:
LLSDACSE2297:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv,"x"
	.linkonce discard
	.section	.text$_ZNSt8__detail19_Node_iterator_baseISt4pairIKjiELb0EE7_M_incrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail19_Node_iterator_baseISt4pairIKjiELb0EE7_M_incrEv
	.def	__ZNSt8__detail19_Node_iterator_baseISt4pairIKjiELb0EE7_M_incrEv;	.scl	2;	.type	32;	.endef
__ZNSt8__detail19_Node_iterator_baseISt4pairIKjiELb0EE7_M_incrEv:
LFB2298:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Hash_nodeISt4pairIKjiELb0EE7_M_nextEv
	movl	8(%ebp), %edx
	movl	%eax, (%edx)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2298:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5beginEv
	.def	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5beginEv;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5beginEv:
LFB2299:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2299
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE8_M_beginEv
	movl	%eax, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEC1EPNS_10_Hash_nodeIS3_Lb0EEE
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2299:
	.section	.gcc_except_table,"w"
LLSDA2299:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2299-LLSDACSB2299
LLSDACSB2299:
LLSDACSE2299:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE5beginEv,"x"
	.linkonce discard
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv
	.def	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv:
LFB2300:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2300
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEC1EPNS_10_Hash_nodeIS3_Lb0EEE
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2300:
	.section	.gcc_except_table,"w"
LLSDA2300:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2300-LLSDACSB2300
LLSDACSB2300:
LLSDACSE2300:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE3endEv,"x"
	.linkonce discard
	.section	.text$_ZNSt8__detail12_Insert_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail12_Insert_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2Ev
	.def	__ZNSt8__detail12_Insert_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt8__detail12_Insert_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2Ev:
LFB2308:
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
LFE2308:
	.section	.text$_ZNSt8__detail7_InsertIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail7_InsertIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EEC2Ev
	.def	__ZNSt8__detail7_InsertIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt8__detail7_InsertIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EEC2Ev:
LFB2310:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail12_Insert_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2310:
	.section	.text$_ZNSt8__detail9_EqualityIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail9_EqualityIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEC2Ev
	.def	__ZNSt8__detail9_EqualityIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt8__detail9_EqualityIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEC2Ev:
LFB2313:
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
LFE2313:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKS9_RKSA_RKSB_RKS7_RKS5_RKS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKS9_RKSA_RKSB_RKS7_RKS5_RKS3_
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKS9_RKSA_RKSB_RKS7_RKS5_RKS3_;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKS9_RKSA_RKSB_RKS7_RKS5_RKS3_:
LFB2316:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2316
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
LEHB236:
	call	__ZNSt8__detail15_Hashtable_baseIjSt4pairIKjiENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2ERKS4_RKS8_RKS9_RKSA_RKS6_
LEHE236:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail7_InsertIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb0ELb1EEC2Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail9_EqualityIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEC2Ev
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	8(%ebp), %eax
	leal	8(%eax), %edx
	movl	36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjiELb0EEEEEC1IRKSaIS4_EEEOT_
	movl	8(%ebp), %eax
	movl	$0, 12(%eax)
	movl	8(%ebp), %eax
	leal	16(%eax), %edx
	movl	LC199, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt8__detail20_Prime_rehash_policyC1Ef
	movl	8(%ebp), %eax
	leal	16(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
LEHB237:
	call	__ZNKSt8__detail20_Prime_rehash_policy11_M_next_bktEj
	movl	8(%ebp), %edx
	movl	%eax, 4(%edx)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_allocate_bucketsEj
LEHE237:
	movl	8(%ebp), %edx
	movl	%eax, (%edx)
	jmp	L1311
L1310:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjiELb0EEEEED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB238:
	call	__Unwind_Resume
LEHE238:
L1311:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2316:
	.section	.gcc_except_table,"w"
LLSDA2316:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2316-LLSDACSB2316
LLSDACSB2316:
	.uleb128 LEHB236-LFB2316
	.uleb128 LEHE236-LEHB236
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB237-LFB2316
	.uleb128 LEHE237-LEHB237
	.uleb128 L1310-LFB2316
	.uleb128 0
	.uleb128 LEHB238-LFB2316
	.uleb128 LEHE238-LEHB238
	.uleb128 0
	.uleb128 0
LLSDACSE2316:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEEC1EjRKS9_RKSA_RKSB_RKS7_RKS5_RKS3_,"x"
	.linkonce discard
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEED2Ev:
LFB2318:
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
LFE2318:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_deallocate_nodesEPNS4_10_Hash_nodeIS2_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_deallocate_nodesEPNS4_10_Hash_nodeIS2_Lb0EEE
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_deallocate_nodesEPNS4_10_Hash_nodeIS2_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_deallocate_nodesEPNS4_10_Hash_nodeIS2_Lb0EEE:
LFB2320:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	jmp	L1315
L1316:
	movl	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Hash_nodeISt4pairIKjiELb0EE7_M_nextEv
	movl	%eax, 12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS4_10_Hash_nodeIS2_Lb0EEE
L1315:
	cmpl	$0, 12(%ebp)
	jne	L1316
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2320:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE8_M_beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE8_M_beginEv
	.def	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE8_M_beginEv;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE8_M_beginEv:
LFB2321:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2321:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv:
LFB2322:
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
LFE2322:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv:
LFB2323:
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
LFE2323:
	.section	.text$_ZNSaIPNSt8__detail15_Hash_node_baseEEC1INS_10_Hash_nodeISt4pairIKjiELb0EEEEERKSaIT_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaIPNSt8__detail15_Hash_node_baseEEC1INS_10_Hash_nodeISt4pairIKjiELb0EEEEERKSaIT_E
	.def	__ZNSaIPNSt8__detail15_Hash_node_baseEEC1INS_10_Hash_nodeISt4pairIKjiELb0EEEEERKSaIT_E;	.scl	2;	.type	32;	.endef
__ZNSaIPNSt8__detail15_Hash_node_baseEEC1INS_10_Hash_nodeISt4pairIKjiELb0EEEEERKSaIT_E:
LFB2326:
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
LFE2326:
	.section	.text$_ZNSaIPNSt8__detail15_Hash_node_baseEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaIPNSt8__detail15_Hash_node_baseEED1Ev
	.def	__ZNSaIPNSt8__detail15_Hash_node_baseEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSaIPNSt8__detail15_Hash_node_baseEED1Ev:
LFB2329:
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
LFE2329:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS3_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS3_j
	.def	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS3_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS3_j:
LFB2330:
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
LFE2330:
	.section	.text$_ZNKSt8__detail12_Rehash_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE15max_load_factorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail12_Rehash_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE15max_load_factorEv
	.def	__ZNKSt8__detail12_Rehash_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE15max_load_factorEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail12_Rehash_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE15max_load_factorEv:
LFB2331:
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
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15__rehash_policyEv
	movl	%eax, (%esp)
	call	__ZNKSt8__detail20_Prime_rehash_policy15max_load_factorEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2331:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE6rehashEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE6rehashEj
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE6rehashEj;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE6rehashEj:
LFB2332:
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
	je	L1330
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEjRS1_
	jmp	L1329
L1330:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	addl	$16, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt8__detail20_Prime_rehash_policy8_M_resetEj
L1329:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2332:
	.section	.text$_ZNSt8__detail12_Insert_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE20_M_conjure_hashtableEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail12_Insert_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE20_M_conjure_hashtableEv
	.def	__ZNSt8__detail12_Insert_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE20_M_conjure_hashtableEv;	.scl	2;	.type	32;	.endef
__ZNSt8__detail12_Insert_baseIjSt4pairIKjiESaIS3_ENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEEE20_M_conjure_hashtableEv:
LFB2333:
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
LFE2333:
	.section	.text$_ZSt7forwardIRSt4pairIKjiEEOT_RNSt16remove_referenceIS4_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRSt4pairIKjiEEOT_RNSt16remove_referenceIS4_E4typeE
	.def	__ZSt7forwardIRSt4pairIKjiEEOT_RNSt16remove_referenceIS4_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRSt4pairIKjiEEOT_RNSt16remove_referenceIS4_E4typeE:
LFB2335:
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
LFE2335:
	.section	.text$_ZNSt10__pair_getILj0EE5__getIKjiEERT_RSt4pairIS3_T0_E,"x"
	.linkonce discard
	.globl	__ZNSt10__pair_getILj0EE5__getIKjiEERT_RSt4pairIS3_T0_E
	.def	__ZNSt10__pair_getILj0EE5__getIKjiEERT_RSt4pairIS3_T0_E;	.scl	2;	.type	32;	.endef
__ZNSt10__pair_getILj0EE5__getIKjiEERT_RSt4pairIS3_T0_E:
LFB2337:
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
LFE2337:
	.section	.text$_ZSt3getILj0EKjiERNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERS5_,"x"
	.linkonce discard
	.globl	__ZSt3getILj0EKjiERNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERS5_
	.def	__ZSt3getILj0EKjiERNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERS5_;	.scl	2;	.type	32;	.endef
__ZSt3getILj0EKjiERNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERS5_:
LFB2336:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10__pair_getILj0EE5__getIKjiEERT_RSt4pairIS3_T0_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2336:
	.section	.text$_ZSt7forwardINSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEEEOT_RNSt16remove_referenceIS6_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardINSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEEEOT_RNSt16remove_referenceIS6_E4typeE
	.def	__ZSt7forwardINSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEEEOT_RNSt16remove_referenceIS6_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardINSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEEEOT_RNSt16remove_referenceIS6_E4typeE:
LFB2339:
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
LFE2339:
	.section	.text$_ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE
	.def	__ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE:
LFB2340:
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
LFE2340:
	.section	.text$_ZNSt4pairINSt8__detail14_Node_iteratorIS_IKjiELb0ELb0EEEbEC1IS4_bvEEOT_OT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairINSt8__detail14_Node_iteratorIS_IKjiELb0ELb0EEEbEC1IS4_bvEEOT_OT0_
	.def	__ZNSt4pairINSt8__detail14_Node_iteratorIS_IKjiELb0ELb0EEEbEC1IS4_bvEEOT_OT0_;	.scl	2;	.type	32;	.endef
__ZNSt4pairINSt8__detail14_Node_iteratorIS_IKjiELb0ELb0EEEbEC1IS4_bvEEOT_OT0_:
LFB2343:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardINSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEEEOT_RNSt16remove_referenceIS6_E4typeE
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
LFE2343:
	.section	.text$_ZSt9make_pairINSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEEbES2_INSt17__decay_and_stripIT_E6__typeENS6_IT0_E6__typeEEOS7_OSA_,"x"
	.linkonce discard
	.globl	__ZSt9make_pairINSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEEbES2_INSt17__decay_and_stripIT_E6__typeENS6_IT0_E6__typeEEOS7_OSA_
	.def	__ZSt9make_pairINSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEEbES2_INSt17__decay_and_stripIT_E6__typeENS6_IT0_E6__typeEEOS7_OSA_;	.scl	2;	.type	32;	.endef
__ZSt9make_pairINSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEEbES2_INSt17__decay_and_stripIT_E6__typeENS6_IT0_E6__typeEEOS7_OSA_:
LFB2338:
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
	call	__ZSt7forwardINSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEEEOT_RNSt16remove_referenceIS6_E4typeE
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt4pairINSt8__detail14_Node_iteratorIS_IKjiELb0ELb0EEEbEC1IS4_bvEEOT_OT0_
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
LFE2338:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIIS0_IjiEEEES0_INS4_14_Node_iteratorIS2_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIIS0_IjiEEEES0_INS4_14_Node_iteratorIS2_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIIS0_IjiEEEES0_INS4_14_Node_iteratorIS2_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIIS0_IjiEEEES0_INS4_14_Node_iteratorIS2_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_:
LFB2334:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2334
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
	call	__ZSt7forwardISt4pairIjiEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB239:
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIIS0_IjiEEEEPNS4_10_Hash_nodeIS2_Lb0EEEDpOT_
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	leal	4(%eax), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv
LEHE239:
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Select1stclIRSt4pairIKjiEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS6_
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB240:
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE12_M_hash_codeERS2_
LEHE240:
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB241:
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexERS1_j
	movl	%eax, -24(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE12_M_find_nodeEjRS1_j
	movl	%eax, -28(%ebp)
	cmpl	$0, -28(%ebp)
	je	L1348
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS4_10_Hash_nodeIS2_Lb0EEE
LEHE241:
	movb	$0, -41(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
LEHB242:
	call	__ZNSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEC1EPNS_10_Hash_nodeIS3_Lb0EEE
LEHE242:
	leal	-41(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt9make_pairINSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEEbES2_INSt17__decay_and_stripIT_E6__typeENS6_IT0_E6__typeEEOS7_OSA_
	jmp	L1358
L1348:
	movb	$1, -33(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB243:
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEjjPNS4_10_Hash_nodeIS2_Lb0EEE
LEHE243:
	movl	%eax, -32(%ebp)
	leal	-33(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt9make_pairINSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEEbES2_INSt17__decay_and_stripIT_E6__typeENS6_IT0_E6__typeEEOS7_OSA_
	jmp	L1358
L1355:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB244:
	call	__Unwind_Resume
LEHE244:
L1354:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB245:
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS4_10_Hash_nodeIS2_Lb0EEE
	call	___cxa_rethrow
LEHE245:
L1356:
	movl	%eax, (%esp)
LEHB246:
	call	__Unwind_Resume
L1357:
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE246:
L1358:
	addl	$68, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2334:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA2334:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT2334-LLSDATTD2334
LLSDATTD2334:
	.byte	0x1
	.uleb128 LLSDACSE2334-LLSDACSB2334
LLSDACSB2334:
	.uleb128 LEHB239-LFB2334
	.uleb128 LEHE239-LEHB239
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB240-LFB2334
	.uleb128 LEHE240-LEHB240
	.uleb128 L1354-LFB2334
	.uleb128 0x1
	.uleb128 LEHB241-LFB2334
	.uleb128 LEHE241-LEHB241
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB242-LFB2334
	.uleb128 LEHE242-LEHB242
	.uleb128 L1356-LFB2334
	.uleb128 0
	.uleb128 LEHB243-LFB2334
	.uleb128 LEHE243-LEHB243
	.uleb128 L1357-LFB2334
	.uleb128 0
	.uleb128 LEHB244-LFB2334
	.uleb128 LEHE244-LEHB244
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB245-LFB2334
	.uleb128 LEHE245-LEHB245
	.uleb128 L1355-LFB2334
	.uleb128 0
	.uleb128 LEHB246-LFB2334
	.uleb128 LEHE246-LEHB246
	.uleb128 0
	.uleb128 0
LLSDACSE2334:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT2334:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIIS0_IjiEEEES0_INS4_14_Node_iteratorIS2_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_,"x"
	.linkonce discard
	.weak	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIJS0_IjiEEEES0_INS4_14_Node_iteratorIS2_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIJS0_IjiEEEES0_INS4_14_Node_iteratorIS2_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIJS0_IjiEEEES0_INS4_14_Node_iteratorIS2_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_,__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE10_M_emplaceIIS0_IjiEEEES0_INS4_14_Node_iteratorIS2_Lb0ELb0EEEbESt17integral_constantIbLb1EEDpOT_
	.section	.text$_ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE12_M_hash_codeERS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE12_M_hash_codeERS2_
	.def	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE12_M_hash_codeERS2_;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE12_M_hash_codeERS2_:
LFB2344:
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
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h1Ev
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
LFE2344:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexERS1_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexERS1_j
	.def	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexERS1_j;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexERS1_j:
LFB2345:
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
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexERS2_jj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2345:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE12_M_find_nodeEjRS1_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE12_M_find_nodeEjRS1_j
	.def	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE12_M_find_nodeEjRS1_j;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE12_M_find_nodeEjRS1_j:
LFB2346:
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
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_find_before_nodeEjRS1_j
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	L1364
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	jmp	L1365
L1364:
	movl	$0, %eax
L1365:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2346:
	.section	.text$_ZNSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEC1EPNS_10_Hash_nodeIS3_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEC1EPNS_10_Hash_nodeIS3_Lb0EEE
	.def	__ZNSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEC1EPNS_10_Hash_nodeIS3_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEC1EPNS_10_Hash_nodeIS3_Lb0EEE:
LFB2349:
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
	call	__ZNSt8__detail19_Node_iterator_baseISt4pairIKjiELb0EEC2EPNS_10_Hash_nodeIS3_Lb0EEE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2349:
	.section	.text$_ZNKSt8__detail10_Hash_nodeISt4pairIKjiELb0EE7_M_nextEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail10_Hash_nodeISt4pairIKjiELb0EE7_M_nextEv
	.def	__ZNKSt8__detail10_Hash_nodeISt4pairIKjiELb0EE7_M_nextEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail10_Hash_nodeISt4pairIKjiELb0EE7_M_nextEv:
LFB2350:
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
LFE2350:
	.section	.text$_ZNSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEC1EPNS_10_Hash_nodeIS3_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEC1EPNS_10_Hash_nodeIS3_Lb0EEE
	.def	__ZNSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEC1EPNS_10_Hash_nodeIS3_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt8__detail20_Node_const_iteratorISt4pairIKjiELb0ELb0EEC1EPNS_10_Hash_nodeIS3_Lb0EEE:
LFB2353:
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
	call	__ZNSt8__detail19_Node_iterator_baseISt4pairIKjiELb0EEC2EPNS_10_Hash_nodeIS3_Lb0EEE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2353:
	.section	.text$_ZNSt8__detail15_Hashtable_baseIjSt4pairIKjiENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2ERKS4_RKS8_RKS9_RKSA_RKS6_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail15_Hashtable_baseIjSt4pairIKjiENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2ERKS4_RKS8_RKS9_RKSA_RKS6_
	.def	__ZNSt8__detail15_Hashtable_baseIjSt4pairIKjiENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2ERKS4_RKS8_RKS9_RKSA_RKS6_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail15_Hashtable_baseIjSt4pairIKjiENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEEC2ERKS4_RKS8_RKS9_RKSA_RKS6_:
LFB2355:
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
	call	__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EEC2ERKS4_RKS6_RKS7_RKS8_
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
LFE2355:
	.section	.text$_ZSt7forwardIRKSaISt4pairIKjiEEEOT_RNSt16remove_referenceIS6_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRKSaISt4pairIKjiEEEOT_RNSt16remove_referenceIS6_E4typeE
	.def	__ZSt7forwardIRKSaISt4pairIKjiEEEOT_RNSt16remove_referenceIS6_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRKSaISt4pairIKjiEEEOT_RNSt16remove_referenceIS6_E4typeE:
LFB2358:
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
LFE2358:
	.section	.text$_ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjiELb0EEEEEC1IRKSaIS4_EEEOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjiELb0EEEEEC1IRKSaIS4_EEEOT_
	.def	__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjiELb0EEEEEC1IRKSaIS4_EEEOT_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail13_Before_beginISaINS_10_Hash_nodeISt4pairIKjiELb0EEEEEC1IRKSaIS4_EEEOT_:
LFB2360:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKSaISt4pairIKjiEEEOT_RNSt16remove_referenceIS6_E4typeE
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEEC2IS3_EERKSaIT_E
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail15_Hash_node_baseC1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2360:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_allocate_bucketsEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_allocate_bucketsEj
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_allocate_bucketsEj;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_allocate_bucketsEj:
LFB2361:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2361
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
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	movl	%eax, 4(%esp)
	leal	-13(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIPNSt8__detail15_Hash_node_baseEEC1INS_10_Hash_nodeISt4pairIKjiELb0EEEEERKSaIT_E
	movl	$0, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-13(%ebp), %eax
	movl	%eax, (%esp)
LEHB247:
	call	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8allocateEjPKv
LEHE247:
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
	jmp	L1378
L1377:
	movl	%eax, %ebx
	leal	-13(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIPNSt8__detail15_Hash_node_baseEED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB248:
	call	__Unwind_Resume
LEHE248:
L1378:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2361:
	.section	.gcc_except_table,"w"
LLSDA2361:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2361-LLSDACSB2361
LLSDACSB2361:
	.uleb128 LEHB247-LFB2361
	.uleb128 LEHE247-LEHB247
	.uleb128 L1377-LFB2361
	.uleb128 0
	.uleb128 LEHB248-LFB2361
	.uleb128 LEHE248-LEHB248
	.uleb128 0
	.uleb128 0
LLSDACSE2361:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_allocate_bucketsEj,"x"
	.linkonce discard
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS4_10_Hash_nodeIS2_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS4_10_Hash_nodeIS2_Lb0EEE
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS4_10_Hash_nodeIS2_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS4_10_Hash_nodeIS2_Lb0EEE:
LFB2362:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE7destroyIS6_EEvPT_
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	movl	$1, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE10deallocateEPS6_j
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2362:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	.def	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv:
LFB2363:
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
LFE2363:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEEC2Ev:
LFB2365:
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
LFE2365:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev:
LFB2368:
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
LFE2368:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15__rehash_policyEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15__rehash_policyEv
	.def	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15__rehash_policyEv;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15__rehash_policyEv:
LFB2370:
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
LFE2370:
	.section	.text$_ZSt3maxIjERKT_S2_S2_,"x"
	.linkonce discard
	.globl	__ZSt3maxIjERKT_S2_S2_
	.def	__ZSt3maxIjERKT_S2_S2_;	.scl	2;	.type	32;	.endef
__ZSt3maxIjERKT_S2_S2_:
LFB2371:
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
	jae	L1388
	movl	12(%ebp), %eax
	jmp	L1389
L1388:
	movl	8(%ebp), %eax
L1389:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2371:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEjRS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEjRS1_
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEjRS1_;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEjRS1_:
LFB2372:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2372
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
LEHB249:
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE13_M_rehash_auxEjSt17integral_constantIbLb1EE
LEHE249:
	jmp	L1395
L1393:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	addl	$16, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt8__detail20_Prime_rehash_policy8_M_resetEj
LEHB250:
	call	___cxa_rethrow
LEHE250:
L1394:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB251:
	call	__Unwind_Resume
LEHE251:
L1395:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2372:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA2372:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT2372-LLSDATTD2372
LLSDATTD2372:
	.byte	0x1
	.uleb128 LLSDACSE2372-LLSDACSB2372
LLSDACSB2372:
	.uleb128 LEHB249-LFB2372
	.uleb128 LEHE249-LEHB249
	.uleb128 L1393-LFB2372
	.uleb128 0x3
	.uleb128 LEHB250-LFB2372
	.uleb128 LEHE250-LEHB250
	.uleb128 L1394-LFB2372
	.uleb128 0
	.uleb128 LEHB251-LFB2372
	.uleb128 LEHE251-LEHB251
	.uleb128 0
	.uleb128 0
LLSDACSE2372:
	.byte	0x1
	.byte	0
	.byte	0
	.byte	0x7d
	.align 4
	.long	0
LLSDATT2372:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEjRS1_,"x"
	.linkonce discard
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIIS0_IjiEEEEPNS4_10_Hash_nodeIS2_Lb0EEEDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIIS0_IjiEEEEPNS4_10_Hash_nodeIS2_Lb0EEEDpOT_
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIIS0_IjiEEEEPNS4_10_Hash_nodeIS2_Lb0EEEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIIS0_IjiEEEEPNS4_10_Hash_nodeIS2_Lb0EEEDpOT_:
LFB2373:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2373
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
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	movl	$0, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
LEHB252:
	call	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE8allocateEjPKv
LEHE252:
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt4pairIjiEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	movl	%ebx, 8(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB253:
	call	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE9constructIS6_IS3_IjiEEEEvPT_DpOT0_
LEHE253:
	movl	-12(%ebp), %eax
	jmp	L1402
L1401:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB254:
	call	__Unwind_Resume
LEHE254:
L1400:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE17_M_node_allocatorEv
	movl	$1, 8(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE10deallocateEPS6_j
LEHB255:
	call	___cxa_rethrow
LEHE255:
L1402:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2373:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA2373:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT2373-LLSDATTD2373
LLSDATTD2373:
	.byte	0x1
	.uleb128 LLSDACSE2373-LLSDACSB2373
LLSDACSB2373:
	.uleb128 LEHB252-LFB2373
	.uleb128 LEHE252-LEHB252
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB253-LFB2373
	.uleb128 LEHE253-LEHB253
	.uleb128 L1400-LFB2373
	.uleb128 0x1
	.uleb128 LEHB254-LFB2373
	.uleb128 LEHE254-LEHB254
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB255-LFB2373
	.uleb128 LEHE255-LEHB255
	.uleb128 L1401-LFB2373
	.uleb128 0
LLSDACSE2373:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT2373:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIIS0_IjiEEEEPNS4_10_Hash_nodeIS2_Lb0EEEDpOT_,"x"
	.linkonce discard
	.weak	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIJS0_IjiEEEEPNS4_10_Hash_nodeIS2_Lb0EEEDpOT_
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIJS0_IjiEEEEPNS4_10_Hash_nodeIS2_Lb0EEEDpOT_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIJS0_IjiEEEEPNS4_10_Hash_nodeIS2_Lb0EEEDpOT_,__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE16_M_allocate_nodeIIS0_IjiEEEEPNS4_10_Hash_nodeIS2_Lb0EEEDpOT_
	.section	.text$_ZNSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv
	.def	__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv;	.scl	2;	.type	32;	.endef
__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv:
LFB2374:
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
LFE2374:
	.section	.text$_ZNKSt8__detail10_Select1stclIRSt4pairIKjiEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS6_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail10_Select1stclIRSt4pairIKjiEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS6_
	.def	__ZNKSt8__detail10_Select1stclIRSt4pairIKjiEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS6_;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail10_Select1stclIRSt4pairIKjiEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS6_:
LFB2375:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRSt4pairIKjiEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	%eax, (%esp)
	call	__ZSt3getILj0EKjiERNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERS5_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2375:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEjjPNS4_10_Hash_nodeIS2_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEjjPNS4_10_Hash_nodeIS2_Lb0EEE
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEjjPNS4_10_Hash_nodeIS2_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEjjPNS4_10_Hash_nodeIS2_Lb0EEE:
LFB2376:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2376
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
LEHB256:
	call	__ZNKSt8__detail20_Prime_rehash_policy14_M_need_rehashEjjj
LEHE256:
	movl	%eax, -28(%ebp)
	movl	%edx, -24(%ebp)
	movzbl	-28(%ebp), %eax
	testb	%al, %al
	je	L1408
	movl	-24(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB257:
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEjRS1_
	movl	20(%ebp), %eax
	leal	4(%eax), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Select1stclIRSt4pairIKjiEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS6_
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexERS1_j
	movl	%eax, 12(%ebp)
L1408:
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE13_M_store_codeEPNS_10_Hash_nodeIS3_Lb0EEEj
	movl	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE22_M_insert_bucket_beginEjPNS4_10_Hash_nodeIS2_Lb0EEE
LEHE257:
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 12(%eax)
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8__detail14_Node_iteratorISt4pairIKjiELb0ELb0EEC1EPNS_10_Hash_nodeIS3_Lb0EEE
	movl	-16(%ebp), %eax
	jmp	L1416
L1415:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	jmp	L1411
L1414:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE18_M_deallocate_nodeEPNS4_10_Hash_nodeIS2_Lb0EEE
LEHB258:
	call	___cxa_rethrow
LEHE258:
L1413:
L1411:
	movl	%eax, (%esp)
LEHB259:
	call	__Unwind_Resume
LEHE259:
L1416:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2376:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA2376:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT2376-LLSDATTD2376
LLSDATTD2376:
	.byte	0x1
	.uleb128 LLSDACSE2376-LLSDACSB2376
LLSDACSB2376:
	.uleb128 LEHB256-LFB2376
	.uleb128 LEHE256-LEHB256
	.uleb128 L1413-LFB2376
	.uleb128 0
	.uleb128 LEHB257-LFB2376
	.uleb128 LEHE257-LEHB257
	.uleb128 L1414-LFB2376
	.uleb128 0x1
	.uleb128 LEHB258-LFB2376
	.uleb128 LEHE258-LEHB258
	.uleb128 L1415-LFB2376
	.uleb128 0
	.uleb128 LEHB259-LFB2376
	.uleb128 LEHE259-LEHB259
	.uleb128 0
	.uleb128 0
LLSDACSE2376:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT2376:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEjjPNS4_10_Hash_nodeIS2_Lb0EEE,"x"
	.linkonce discard
	.section	.text$_ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h1Ev
	.def	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h1Ev;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h1Ev:
LFB2377:
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
LFE2377:
	.section	.text$_ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexERS2_jj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexERS2_jj
	.def	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexERS2_jj;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexERS2_jj:
LFB2378:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h2Ev
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
LFE2378:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_find_before_nodeEjRS1_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_find_before_nodeEjRS1_j
	.def	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_find_before_nodeEjRS1_j;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_find_before_nodeEjRS1_j:
LFB2379:
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
	jne	L1422
	movl	$0, %eax
	jmp	L1423
L1422:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
L1430:
	movl	-16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjiENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_equalsERS2_jPNS_10_Hash_nodeIS3_Lb0EEE
	testb	%al, %al
	je	L1424
	movl	-12(%ebp), %eax
	jmp	L1423
L1424:
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L1425
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Hash_nodeISt4pairIKjiELb0EE7_M_nextEv
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexEPNS4_10_Hash_nodeIS2_Lb0EEE
	cmpl	12(%ebp), %eax
	je	L1426
L1425:
	movl	$1, %eax
	jmp	L1427
L1426:
	movl	$0, %eax
L1427:
	testb	%al, %al
	je	L1428
	nop
	movl	$0, %eax
	jmp	L1423
L1428:
	movl	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Hash_nodeISt4pairIKjiELb0EE7_M_nextEv
	movl	%eax, -16(%ebp)
	jmp	L1430
L1423:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2379:
	.section	.text$_ZNSt8__detail19_Node_iterator_baseISt4pairIKjiELb0EEC2EPNS_10_Hash_nodeIS3_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail19_Node_iterator_baseISt4pairIKjiELb0EEC2EPNS_10_Hash_nodeIS3_Lb0EEE
	.def	__ZNSt8__detail19_Node_iterator_baseISt4pairIKjiELb0EEC2EPNS_10_Hash_nodeIS3_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt8__detail19_Node_iterator_baseISt4pairIKjiELb0EEC2EPNS_10_Hash_nodeIS3_Lb0EEE:
LFB2381:
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
LFE2381:
	.section	.text$_ZNSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EEC2ERKS4_RKS6_RKS7_RKS8_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EEC2ERKS4_RKS6_RKS7_RKS8_
	.def	__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EEC2ERKS4_RKS6_RKS7_RKS8_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EEC2ERKS4_RKS6_RKS7_RKS8_:
LFB2384:
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
LFE2384:
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EEC2ERKS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EEC2ERKS2_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EEC2ERKS2_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EEC2ERKS2_:
LFB2387:
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
LFE2387:
	.section	.text$_ZNSaINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEEC2IS3_EERKSaIT_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEEC2IS3_EERKSaIT_E
	.def	__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEEC2IS3_EERKSaIT_E;	.scl	2;	.type	32;	.endef
__ZNSaINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEEC2IS3_EERKSaIT_E:
LFB2390:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEEC2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2390:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8allocateEjPKv:
LFB2392:
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
	je	L1436
	call	__ZSt17__throw_bad_allocv
L1436:
	movl	12(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2392:
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE7destroyIS6_EEvPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE7destroyIS6_EEvPT_
	.def	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE7destroyIS6_EEvPT_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE7destroyIS6_EEvPT_:
LFB2393:
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
LFE2393:
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE10deallocateEPS6_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE10deallocateEPS6_j
	.def	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE10deallocateEPS6_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE10deallocateEPS6_j:
LFB2394:
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
LFE2394:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE13_M_rehash_auxEjSt17integral_constantIbLb1EE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE13_M_rehash_auxEjSt17integral_constantIbLb1EE
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE13_M_rehash_auxEjSt17integral_constantIbLb1EE;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE13_M_rehash_auxEjSt17integral_constantIbLb1EE:
LFB2395:
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
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE19_M_allocate_bucketsEj
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE8_M_beginEv
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	$0, (%eax)
	movl	$0, -16(%ebp)
	jmp	L1441
L1445:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Hash_nodeISt4pairIKjiELb0EE7_M_nextEv
	movl	%eax, -24(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexEPKNS_10_Hash_nodeIS3_Lb0EEEj
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1442
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	movl	-28(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	leal	(%edx,%eax), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	%eax, (%ebx)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L1443
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%edx)
L1443:
	movl	-28(%ebp), %eax
	movl	%eax, -16(%ebp)
	jmp	L1444
L1442:
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
L1444:
	movl	-24(%ebp), %eax
	movl	%eax, -12(%ebp)
L1441:
	cmpl	$0, -12(%ebp)
	jne	L1445
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_deallocate_bucketsEPPNS4_15_Hash_node_baseEj
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
LFE2395:
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE8allocateEjPKv:
LFB2396:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE8max_sizeEv
	cmpl	12(%ebp), %eax
	setb	%al
	testb	%al, %al
	je	L1447
	call	__ZSt17__throw_bad_allocv
L1447:
	movl	12(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2396:
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE9constructIS6_IS3_IjiEEEEvPT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE9constructIS6_IS3_IjiEEEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE9constructIS6_IS3_IjiEEEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE9constructIS6_IS3_IjiEEEEvPT_DpOT0_:
LFB2397:
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
	call	__ZSt7forwardISt4pairIjiEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$12, (%esp)
	call	__ZnwjPv
	testl	%eax, %eax
	je	L1449
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt8__detail10_Hash_nodeISt4pairIKjiELb0EEC1IIS1_IjiEEEEDpOT_
L1449:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2397:
	.weak	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE9constructIS6_JS3_IjiEEEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE9constructIS6_JS3_IjiEEEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
	.set	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE9constructIS6_JS3_IjiEEEEvPT_DpOT0_,__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE9constructIS6_IS3_IjiEEEEvPT_DpOT0_
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE6_S_getERS2_,"x"
	.linkonce discard
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE6_S_getERS2_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE6_S_getERS2_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE6_S_getERS2_:
LFB2398:
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
LFE2398:
	.section	.text$_ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE13_M_store_codeEPNS_10_Hash_nodeIS3_Lb0EEEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE13_M_store_codeEPNS_10_Hash_nodeIS3_Lb0EEEj
	.def	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE13_M_store_codeEPNS_10_Hash_nodeIS3_Lb0EEEj;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE13_M_store_codeEPNS_10_Hash_nodeIS3_Lb0EEEj:
LFB2399:
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
LFE2399:
	.section	.text$_ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE22_M_insert_bucket_beginEjPNS4_10_Hash_nodeIS2_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE22_M_insert_bucket_beginEjPNS4_10_Hash_nodeIS2_Lb0EEE
	.def	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE22_M_insert_bucket_beginEjPNS4_10_Hash_nodeIS2_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE22_M_insert_bucket_beginEjPNS4_10_Hash_nodeIS2_Lb0EEE:
LFB2400:
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
	je	L1456
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
	jmp	L1455
L1456:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	16(%ebp), %edx
	movl	%edx, (%eax)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L1458
	movl	8(%ebp), %eax
	movl	(%eax), %ebx
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Hash_nodeISt4pairIKjiELb0EE7_M_nextEv
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexEPNS4_10_Hash_nodeIS2_Lb0EEE
	sall	$2, %eax
	leal	(%ebx,%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, (%edx)
L1458:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	sall	$2, %edx
	leal	(%eax,%edx), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_before_beginEv
	movl	%eax, (%ebx)
L1455:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2400:
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EE7_S_cgetERKS3_,"x"
	.linkonce discard
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EE7_S_cgetERKS3_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EE7_S_cgetERKS3_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EE7_S_cgetERKS3_:
LFB2401:
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
LFE2401:
	.section	.text$_ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h2Ev
	.def	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h2Ev;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h2Ev:
LFB2402:
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
LFE2402:
	.section	.text$_ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjiENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_equalsERS2_jPNS_10_Hash_nodeIS3_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjiENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_equalsERS2_jPNS_10_Hash_nodeIS3_Lb0EEE
	.def	__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjiENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_equalsERS2_jPNS_10_Hash_nodeIS3_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjiENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_equalsERS2_jPNS_10_Hash_nodeIS3_Lb0EEE:
LFB2403:
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
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjiENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE5_M_eqEv
	movl	20(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt8__detail13_Equal_helperIjSt4pairIKjiENS_10_Select1stESt8equal_toIjEjLb0EE9_S_equalsERKS6_RKS4_RS2_jPNS_10_Hash_nodeIS3_Lb0EEE
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2403:
	.section	.text$_ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexEPNS4_10_Hash_nodeIS2_Lb0EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexEPNS4_10_Hash_nodeIS2_Lb0EEE
	.def	__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexEPNS4_10_Hash_nodeIS2_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNKSt10_HashtableIjSt4pairIKjiESaIS2_ENSt8__detail10_Select1stESt8equal_toIjESt4hashIjENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE15_M_bucket_indexEPNS4_10_Hash_nodeIS2_Lb0EEE:
LFB2404:
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
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexEPKNS_10_Hash_nodeIS3_Lb0EEEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2404:
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EEC2ERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EEC2ERKS1_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EEC2ERKS1_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EEC2ERKS1_:
LFB2406:
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
LFE2406:
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EEC2ERKS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EEC2ERKS2_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EEC2ERKS2_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi1ESt4hashIjELb1EEC2ERKS2_:
LFB2409:
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
LFE2409:
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EEC2ERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EEC2ERKS1_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EEC2ERKS1_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EEC2ERKS1_:
LFB2412:
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
LFE2412:
	.section	.text$_ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEEC2Ev:
LFB2415:
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
LFE2415:
	.section	.text$_ZNK9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorIPNSt8__detail15_Hash_node_baseEE8max_sizeEv:
LFB2417:
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
LFE2417:
	.section	.text$_ZSt7forwardIRKSt4pairIKjiEEOT_RNSt16remove_referenceIS5_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRKSt4pairIKjiEEOT_RNSt16remove_referenceIS5_E4typeE
	.def	__ZSt7forwardIRKSt4pairIKjiEEOT_RNSt16remove_referenceIS5_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRKSt4pairIKjiEEOT_RNSt16remove_referenceIS5_E4typeE:
LFB2419:
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
LFE2419:
	.section	.text$_ZNSt10__pair_getILj0EE11__const_getIKjiEERKT_RKSt4pairIS3_T0_E,"x"
	.linkonce discard
	.globl	__ZNSt10__pair_getILj0EE11__const_getIKjiEERKT_RKSt4pairIS3_T0_E
	.def	__ZNSt10__pair_getILj0EE11__const_getIKjiEERKT_RKSt4pairIS3_T0_E;	.scl	2;	.type	32;	.endef
__ZNSt10__pair_getILj0EE11__const_getIKjiEERKT_RKSt4pairIS3_T0_E:
LFB2421:
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
LFE2421:
	.section	.text$_ZSt3getILj0EKjiERKNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERKS5_,"x"
	.linkonce discard
	.globl	__ZSt3getILj0EKjiERKNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERKS5_
	.def	__ZSt3getILj0EKjiERKNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERKS5_;	.scl	2;	.type	32;	.endef
__ZSt3getILj0EKjiERKNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERKS5_:
LFB2420:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10__pair_getILj0EE11__const_getIKjiEERKT_RKSt4pairIS3_T0_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2420:
	.section	.text$_ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexEPKNS_10_Hash_nodeIS3_Lb0EEEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexEPKNS_10_Hash_nodeIS3_Lb0EEEj
	.def	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexEPKNS_10_Hash_nodeIS3_Lb0EEEj;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE15_M_bucket_indexEPKNS_10_Hash_nodeIS3_Lb0EEEj:
LFB2418:
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
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt8__detail10_Select1stclIRKSt4pairIKjiEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS7_
	movl	(%eax), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h1Ev
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt4hashIjEclEj
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE5_M_h2Ev
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
LFE2418:
	.section	.text$_ZNK9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorINSt8__detail10_Hash_nodeISt4pairIKjiELb0EEEE8max_sizeEv:
LFB2422:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$357913941, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2422:
	.section	.text$_ZNSt8__detail10_Hash_nodeISt4pairIKjiELb0EEC1IIS1_IjiEEEEDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8__detail10_Hash_nodeISt4pairIKjiELb0EEC1IIS1_IjiEEEEDpOT_
	.def	__ZNSt8__detail10_Hash_nodeISt4pairIKjiELb0EEC1IIS1_IjiEEEEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail10_Hash_nodeISt4pairIKjiELb0EEC1IIS1_IjiEEEEDpOT_:
LFB2425:
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
	call	__ZSt7forwardISt4pairIjiEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	8(%ebp), %edx
	addl	$4, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt4pairIKjiEC1IjivEEOS_IT_T0_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2425:
	.weak	__ZNSt8__detail10_Hash_nodeISt4pairIKjiELb0EEC1IJS1_IjiEEEEDpOT_
	.def	__ZNSt8__detail10_Hash_nodeISt4pairIKjiELb0EEC1IJS1_IjiEEEEDpOT_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt8__detail10_Hash_nodeISt4pairIKjiELb0EEC1IJS1_IjiEEEEDpOT_,__ZNSt8__detail10_Hash_nodeISt4pairIKjiELb0EEC1IIS1_IjiEEEEDpOT_
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EE7_S_cgetERKS2_,"x"
	.linkonce discard
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EE7_S_cgetERKS2_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EE7_S_cgetERKS2_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi2ENS_18_Mod_range_hashingELb1EE7_S_cgetERKS2_:
LFB2426:
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
LFE2426:
	.section	.text$_ZNSt8__detail13_Equal_helperIjSt4pairIKjiENS_10_Select1stESt8equal_toIjEjLb0EE9_S_equalsERKS6_RKS4_RS2_jPNS_10_Hash_nodeIS3_Lb0EEE,"x"
	.linkonce discard
	.globl	__ZNSt8__detail13_Equal_helperIjSt4pairIKjiENS_10_Select1stESt8equal_toIjEjLb0EE9_S_equalsERKS6_RKS4_RS2_jPNS_10_Hash_nodeIS3_Lb0EEE
	.def	__ZNSt8__detail13_Equal_helperIjSt4pairIKjiENS_10_Select1stESt8equal_toIjEjLb0EE9_S_equalsERKS6_RKS4_RS2_jPNS_10_Hash_nodeIS3_Lb0EEE;	.scl	2;	.type	32;	.endef
__ZNSt8__detail13_Equal_helperIjSt4pairIKjiENS_10_Select1stESt8equal_toIjEjLb0EE9_S_equalsERKS6_RKS4_RS2_jPNS_10_Hash_nodeIS3_Lb0EEE:
LFB2427:
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
	call	__ZNKSt8__detail10_Select1stclIRSt4pairIKjiEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS6_
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
LFE2427:
	.section	.text$_ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjiENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE5_M_eqEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjiENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE5_M_eqEv
	.def	__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjiENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE5_M_eqEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hashtable_baseIjSt4pairIKjiENS_10_Select1stESt8equal_toIjESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_17_Hashtable_traitsILb0ELb0ELb1EEEE5_M_eqEv:
LFB2428:
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
LFE2428:
	.section	.text$_ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv
	.def	__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail15_Hash_code_baseIjSt4pairIKjiENS_10_Select1stESt4hashIjENS_18_Mod_range_hashingENS_20_Default_ranged_hashELb0EE10_M_extractEv:
LFB2429:
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
LFE2429:
	.section	.text$_ZNKSt8__detail10_Select1stclIRKSt4pairIKjiEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS7_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8__detail10_Select1stclIRKSt4pairIKjiEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS7_
	.def	__ZNKSt8__detail10_Select1stclIRKSt4pairIKjiEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS7_;	.scl	2;	.type	32;	.endef
__ZNKSt8__detail10_Select1stclIRKSt4pairIKjiEEEDTcl3getILi0EEcl7forwardIT_Efp_EEEOS7_:
LFB2430:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKSt4pairIKjiEEOT_RNSt16remove_referenceIS5_E4typeE
	movl	%eax, (%esp)
	call	__ZSt3getILj0EKjiERKNSt13tuple_elementIXT_ESt4pairIT0_T1_EE4typeERKS5_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2430:
	.section	.text$_ZNKSt8equal_toIjEclERKjS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8equal_toIjEclERKjS2_
	.def	__ZNKSt8equal_toIjEclERKjS2_;	.scl	2;	.type	32;	.endef
__ZNKSt8equal_toIjEclERKjS2_:
LFB2431:
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
LFE2431:
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EE7_S_cgetERKS3_,"x"
	.linkonce discard
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EE7_S_cgetERKS3_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EE7_S_cgetERKS3_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi0ESt8equal_toIjELb1EE7_S_cgetERKS3_:
LFB2432:
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
LFE2432:
	.section	.text$_ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE7_S_cgetERKS2_,"x"
	.linkonce discard
	.globl	__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE7_S_cgetERKS2_
	.def	__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE7_S_cgetERKS2_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail21_Hashtable_ebo_helperILi0ENS_10_Select1stELb1EE7_S_cgetERKS2_:
LFB2433:
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
LFE2433:
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
	.globl	__ZTV21CMonoAllocAdpWithBuffILj64EE
	.section	.rdata$_ZTV21CMonoAllocAdpWithBuffILj64EE,"dr"
	.linkonce same_size
	.align 32
__ZTV21CMonoAllocAdpWithBuffILj64EE:
	.long	0
	.long	__ZTI21CMonoAllocAdpWithBuffILj64EE
	.long	__ZNK13CMonoAllocAdp7getNameEv
	.long	__ZNK13CMonoAllocAdp8getTotalEv
	.long	__ZNK13CMonoAllocAdp7getUsedEv
	.long	__ZNK13CMonoAllocAdp9getRemainEv
	.long	__ZN13CMonoAllocAdp5allocEjj
	.long	__ZN13CMonoAllocAdp4freeEPv
	.long	__ZN21CMonoAllocAdpWithBuffILj64EED1Ev
	.long	__ZN21CMonoAllocAdpWithBuffILj64EED0Ev
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
	.long	__ZN13CPoolAllocAdp5allocEjj
	.long	__ZN13CPoolAllocAdp4freeEPv
	.long	__ZN13CPoolAllocAdpD1Ev
	.long	__ZN13CPoolAllocAdpD0Ev
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
	.long	__ZN15CIStackAllocAdp5allocEjj
	.long	__ZN15CIStackAllocAdp4freeEPv
	.long	__ZN15CIStackAllocAdpD1Ev
	.long	__ZN15CIStackAllocAdpD0Ev
	.globl	__ZTV18CDualStackAllocAdp
	.section	.rdata$_ZTV18CDualStackAllocAdp,"dr"
	.linkonce same_size
	.align 32
__ZTV18CDualStackAllocAdp:
	.long	0
	.long	__ZTI18CDualStackAllocAdp
	.long	__ZNK18CDualStackAllocAdp7getNameEv
	.long	__ZNK18CDualStackAllocAdp8getTotalEv
	.long	__ZNK18CDualStackAllocAdp7getUsedEv
	.long	__ZNK18CDualStackAllocAdp9getRemainEv
	.long	__ZN18CDualStackAllocAdp5allocEjj
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
	.long	__ZNK14CStackAllocAdp8getTotalEv
	.long	__ZNK14CStackAllocAdp7getUsedEv
	.long	__ZNK14CStackAllocAdp9getRemainEv
	.long	__ZN14CStackAllocAdp5allocEjj
	.long	__ZN14CStackAllocAdp4freeEPv
	.long	__ZN14CStackAllocAdpD1Ev
	.long	__ZN14CStackAllocAdpD0Ev
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
	.long	__ZN13CMonoAllocAdp5allocEjj
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
	.long	__ZN12CStdAllocAdp5allocEjj
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
	.globl	__ZTS21CMonoAllocAdpWithBuffILj64EE
	.section	.rdata$_ZTS21CMonoAllocAdpWithBuffILj64EE,"dr"
	.linkonce same_size
	.align 4
__ZTS21CMonoAllocAdpWithBuffILj64EE:
	.ascii "21CMonoAllocAdpWithBuffILj64EE\0"
	.globl	__ZTI21CMonoAllocAdpWithBuffILj64EE
	.section	.rdata$_ZTI21CMonoAllocAdpWithBuffILj64EE,"dr"
	.linkonce same_size
	.align 4
__ZTI21CMonoAllocAdpWithBuffILj64EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS21CMonoAllocAdpWithBuffILj64EE
	.long	__ZTI13CMonoAllocAdp
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
	.long	__ZTI10IAllocator
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
LFB2434:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L1501
	cmpl	$65535, 12(%ebp)
	jne	L1501
	movl	$__ZN16CTest3Singleton111m_singletonE, (%esp)
	call	__ZN16CTest3Singleton1C1Ev
L1501:
	cmpl	$0, 8(%ebp)
	jne	L1500
	cmpl	$65535, 12(%ebp)
	jne	L1500
	movl	$__ZN16CTest3Singleton111m_singletonE, (%esp)
	call	__ZN16CTest3Singleton1D1Ev
L1500:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2434:
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
	.text
	.def	__GLOBAL__sub_I__Z5test0v;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z5test0v:
LFB2435:
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
LFE2435:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z5test0v
	.text
	.def	__GLOBAL__sub_D__Z5test0v;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_D__Z5test0v:
LFB2436:
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
LFE2436:
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__sub_D__Z5test0v
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
LC195:
	.long	0
	.align 4
LC199:
	.long	1065353216
	.ident	"GCC: (GNU) 4.8.2"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	___cxa_call_unexpected;	.scl	2;	.type	32;	.endef
	.def	_memalign;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	___emutls_get_address;	.scl	2;	.type	32;	.endef
	.def	_ceil;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcEC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1EPKcRKSaIcE;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNKSs5c_strEv;	.scl	2;	.type	32;	.endef
	.def	_strcpy;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1ERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZNSs6appendERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1EOSs;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt8__detail20_Prime_rehash_policy11_M_next_bktEj;	.scl	2;	.type	32;	.endef
	.def	___cxa_end_catch;	.scl	2;	.type	32;	.endef
	.def	___cxa_begin_catch;	.scl	2;	.type	32;	.endef
	.def	___cxa_rethrow;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt8__detail20_Prime_rehash_policy14_M_need_rehashEjjj;	.scl	2;	.type	32;	.endef
	.def	__ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	___cxa_pure_virtual;	.scl	2;	.type	32;	.endef

	.file	"cpu_optimization.cpp"
	.section	.text$_Z21testOpt03_Type1_Afteriii,"x"
	.linkonce discard
	.globl	__Z21testOpt03_Type1_Afteriii
	.def	__Z21testOpt03_Type1_Afteriii;	.scl	2;	.type	32;	.endef
__Z21testOpt03_Type1_Afteriii:
LFB0:
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
LFE0:
	.section	.text$_Z21testOpt03_Type2_Afteriiiiiiii,"x"
	.linkonce discard
	.globl	__Z21testOpt03_Type2_Afteriiiiiiii
	.def	__Z21testOpt03_Type2_Afteriiiiiiii;	.scl	2;	.type	32;	.endef
__Z21testOpt03_Type2_Afteriiiiiiii:
LFB1:
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
LFE1:
	.section	.text$_ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_
	.def	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_;	.scl	2;	.type	32;	.endef
__ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_:
LFB280:
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
LFE280:
	.section	.text$_ZNKSt6chrono8durationIxSt5ratioILx1ELx1000000000EEE5countEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000000000EEE5countEv
	.def	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000000000EEE5countEv;	.scl	2;	.type	32;	.endef
__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000000000EEE5countEv:
LFB284:
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
LFE284:
	.section	.text$_ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEE16time_since_epochEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEE16time_since_epochEv
	.def	__ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEE16time_since_epochEv;	.scl	2;	.type	32;	.endef
__ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEE16time_since_epochEv:
LFB286:
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
LFE286:
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
	.section	.text$_ZNSt6chronomiIxSt5ratioILx1ELx1000000000EExS2_EENSt11common_typeIINS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_,"x"
	.linkonce discard
	.globl	__ZNSt6chronomiIxSt5ratioILx1ELx1000000000EExS2_EENSt11common_typeIINS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_
	.def	__ZNSt6chronomiIxSt5ratioILx1ELx1000000000EExS2_EENSt11common_typeIINS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_;	.scl	2;	.type	32;	.endef
__ZNSt6chronomiIxSt5ratioILx1ELx1000000000EExS2_EENSt11common_typeIINS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_:
LFB2146:
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
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000000000EEE5countEv
	movl	%eax, %ebx
	movl	%edx, %esi
	movl	12(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000000000EEE5countEv
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
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_
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
LFE2146:
	.weak	__ZNSt6chronomiIxSt5ratioILx1ELx1000000000EExS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_
	.def	__ZNSt6chronomiIxSt5ratioILx1ELx1000000000EExS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_;	.scl	2;	.type	32;	.endef
	.set	__ZNSt6chronomiIxSt5ratioILx1ELx1000000000EExS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_,__ZNSt6chronomiIxSt5ratioILx1ELx1000000000EExS2_EENSt11common_typeIINS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_
	.section	.text$_ZNSt6chronomiINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEES6_EENSt11common_typeIIT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chronomiINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEES6_EENSt11common_typeIIT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE
	.def	__ZNSt6chronomiINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEES6_EENSt11common_typeIIT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chronomiINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEES6_EENSt11common_typeIIT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE:
LFB2145:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEE16time_since_epochEv
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEE16time_since_epochEv
	movl	%eax, -8(%ebp)
	movl	%edx, -4(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chronomiIxSt5ratioILx1ELx1000000000EExS2_EENSt11common_typeIINS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2145:
	.weak	__ZNSt6chronomiINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE
	.def	__ZNSt6chronomiINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE;	.scl	2;	.type	32;	.endef
	.set	__ZNSt6chronomiINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE,__ZNSt6chronomiINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEES6_EENSt11common_typeIIT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE
	.section	.text$_ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000000000EEEES2_ILx1ELx1EExLb1ELb1EE6__castIxS3_EES4_RKNS1_IT_T0_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000000000EEEES2_ILx1ELx1EExLb1ELb1EE6__castIxS3_EES4_RKNS1_IT_T0_EE
	.def	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000000000EEEES2_ILx1ELx1EExLb1ELb1EE6__castIxS3_EES4_RKNS1_IT_T0_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000000000EEEES2_ILx1ELx1EExLb1ELb1EE6__castIxS3_EES4_RKNS1_IT_T0_EE:
LFB2148:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000000000EEE5countEv
	movl	%eax, -8(%ebp)
	movl	%edx, -4(%ebp)
	leal	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2148:
	.section	.text$_ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000000000EEEExS3_EENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES7_E4typeERKNS1_IT0_T1_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000000000EEEExS3_EENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES7_E4typeERKNS1_IT0_T1_EE
	.def	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000000000EEEExS3_EENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES7_E4typeERKNS1_IT0_T1_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000000000EEEExS3_EENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES7_E4typeERKNS1_IT0_T1_EE:
LFB2147:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILx1ELx1000000000EEEES2_ILx1ELx1EExLb1ELb1EE6__castIxS3_EES4_RKNS1_IT_T0_EE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2147:
	.section .rdata,"dr"
LC1:
	.ascii "*elapsed time=%.9lf\0"
	.text
	.globl	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb
	.def	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb;	.scl	2;	.type	32;	.endef
__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb:
LFB2144:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2144
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$72, %esp
	movl	12(%ebp), %eax
	movb	%al, -44(%ebp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -32(%ebp)
	movl	%edx, -28(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chronomiINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEES6_EENSt11common_typeIIT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILx1ELx1000000000EEEExS3_EENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES7_E4typeERKNS1_IT0_T1_EE
	movl	%eax, -40(%ebp)
	movl	%edx, -36(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000000000EEE5countEv
	movl	%eax, -56(%ebp)
	movl	%edx, -52(%ebp)
	fildq	-56(%ebp)
	fldl	LC0
	fdivrp	%st, %st(1)
	fstpl	-16(%ebp)
	fldl	-16(%ebp)
	fstpl	4(%esp)
	movl	$LC1, (%esp)
LEHB0:
	call	_printf
	movzbl	-44(%ebp), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L22
	movl	$10, (%esp)
	call	_putchar
LEHE0:
	jmp	L22
L21:
	movl	%eax, (%esp)
LEHB1:
	call	__Unwind_Resume
LEHE1:
L22:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2144:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA2144:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2144-LLSDACSB2144
LLSDACSB2144:
	.uleb128 LEHB0-LFB2144
	.uleb128 LEHE0-LEHB0
	.uleb128 L21-LFB2144
	.uleb128 0
	.uleb128 LEHB1-LFB2144
	.uleb128 LEHE1-LEHB1
	.uleb128 0
	.uleb128 0
LLSDACSE2144:
	.text
	.section	.text$_Z25printElapsedTimeWithoutCRRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEE,"x"
	.linkonce discard
	.globl	__Z25printElapsedTimeWithoutCRRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEE
	.def	__Z25printElapsedTimeWithoutCRRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEE;	.scl	2;	.type	32;	.endef
__Z25printElapsedTimeWithoutCRRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEE:
LFB2149:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$1, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2149:
	.section .rdata,"dr"
	.align 4
LC3:
	.ascii "----------------------------------------\0"
LC4:
	.ascii "[Optimize Test 01]\0"
	.text
	.globl	__Z12runTestOpt01v
	.def	__Z12runTestOpt01v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt01v:
LFB2150:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2150
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$40040, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	movl	$LC3, (%esp)
LEHB2:
	call	_puts
	movl	$LC4, (%esp)
	call	_puts
	leal	-40012(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z9initOpt01R11dataOpt01_t
	leal	-40012(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z18runTestOpt01_Type1R11dataOpt01_t
LEHE2:
	jmp	L27
L26:
	movl	%eax, (%esp)
LEHB3:
	call	__Unwind_Resume
LEHE3:
L27:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2150:
	.section	.gcc_except_table,"w"
LLSDA2150:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2150-LLSDACSB2150
LLSDACSB2150:
	.uleb128 LEHB2-LFB2150
	.uleb128 LEHE2-LEHB2
	.uleb128 L26-LFB2150
	.uleb128 0
	.uleb128 LEHB3-LFB2150
	.uleb128 LEHE3-LEHB3
	.uleb128 0
	.uleb128 0
LLSDACSE2150:
	.text
	.section .rdata,"dr"
LC5:
	.ascii "Type1: *repeated * %d times.\12\0"
	.text
	.globl	__Z18runTestOpt01_Type1R11dataOpt01_t
	.def	__Z18runTestOpt01_Type1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z18runTestOpt01_Type1R11dataOpt01_t:
LFB2151:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$10000, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25runTestOpt01_Type1_BeforeR11dataOpt01_t
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25runTestOpt01_Type1_After1R11dataOpt01_t
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25runTestOpt01_Type1_After2R11dataOpt01_t
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z27runTestOpt01_Type1_AppendixR11dataOpt01_t
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2151:
	.section .rdata,"dr"
LC6:
	.ascii "  Before   ... \0"
	.text
	.globl	__Z25runTestOpt01_Type1_BeforeR11dataOpt01_t
	.def	__Z25runTestOpt01_Type1_BeforeR11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt01_Type1_BeforeR11dataOpt01_t:
LFB2152:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2152
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC6, (%esp)
LEHB4:
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	jmp	L30
L31:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt01_Type1_BeforeR11dataOpt01_t
	addl	$1, -12(%ebp)
L30:
	cmpl	$9999, -12(%ebp)
	jle	L31
	movl	$0, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb
LEHE4:
	jmp	L34
L33:
	movl	%eax, (%esp)
LEHB5:
	call	__Unwind_Resume
LEHE5:
L34:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2152:
	.section	.gcc_except_table,"w"
LLSDA2152:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2152-LLSDACSB2152
LLSDACSB2152:
	.uleb128 LEHB4-LFB2152
	.uleb128 LEHE4-LEHB4
	.uleb128 L33-LFB2152
	.uleb128 0
	.uleb128 LEHB5-LFB2152
	.uleb128 LEHE5-LEHB5
	.uleb128 0
	.uleb128 0
LLSDACSE2152:
	.text
	.section .rdata,"dr"
LC7:
	.ascii "  After1   ... \0"
	.text
	.globl	__Z25runTestOpt01_Type1_After1R11dataOpt01_t
	.def	__Z25runTestOpt01_Type1_After1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt01_Type1_After1R11dataOpt01_t:
LFB2153:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2153
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC7, (%esp)
LEHB6:
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	jmp	L36
L37:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt01_Type1_After1R11dataOpt01_t
	addl	$1, -12(%ebp)
L36:
	cmpl	$9999, -12(%ebp)
	jle	L37
	movl	$0, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb
LEHE6:
	jmp	L40
L39:
	movl	%eax, (%esp)
LEHB7:
	call	__Unwind_Resume
LEHE7:
L40:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2153:
	.section	.gcc_except_table,"w"
LLSDA2153:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2153-LLSDACSB2153
LLSDACSB2153:
	.uleb128 LEHB6-LFB2153
	.uleb128 LEHE6-LEHB6
	.uleb128 L39-LFB2153
	.uleb128 0
	.uleb128 LEHB7-LFB2153
	.uleb128 LEHE7-LEHB7
	.uleb128 0
	.uleb128 0
LLSDACSE2153:
	.text
	.section .rdata,"dr"
LC8:
	.ascii "  After2   ... \0"
	.text
	.globl	__Z25runTestOpt01_Type1_After2R11dataOpt01_t
	.def	__Z25runTestOpt01_Type1_After2R11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt01_Type1_After2R11dataOpt01_t:
LFB2154:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2154
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC8, (%esp)
LEHB8:
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	jmp	L42
L43:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt01_Type1_After2R11dataOpt01_t
	addl	$1, -12(%ebp)
L42:
	cmpl	$9999, -12(%ebp)
	jle	L43
	movl	$0, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb
LEHE8:
	jmp	L46
L45:
	movl	%eax, (%esp)
LEHB9:
	call	__Unwind_Resume
LEHE9:
L46:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2154:
	.section	.gcc_except_table,"w"
LLSDA2154:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2154-LLSDACSB2154
LLSDACSB2154:
	.uleb128 LEHB8-LFB2154
	.uleb128 LEHE8-LEHB8
	.uleb128 L45-LFB2154
	.uleb128 0
	.uleb128 LEHB9-LFB2154
	.uleb128 LEHE9-LEHB9
	.uleb128 0
	.uleb128 0
LLSDACSE2154:
	.text
	.section .rdata,"dr"
LC9:
	.ascii "  Appendix ... \0"
	.align 4
LC10:
	.ascii "  *Appendix is most brief style with C++11\0"
	.text
	.globl	__Z27runTestOpt01_Type1_AppendixR11dataOpt01_t
	.def	__Z27runTestOpt01_Type1_AppendixR11dataOpt01_t;	.scl	2;	.type	32;	.endef
__Z27runTestOpt01_Type1_AppendixR11dataOpt01_t:
LFB2155:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2155
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC9, (%esp)
LEHB10:
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	jmp	L48
L49:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z24testOpt01_Type1_AppendixR11dataOpt01_t
	addl	$1, -12(%ebp)
L48:
	cmpl	$9999, -12(%ebp)
	jle	L49
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25printElapsedTimeWithoutCRRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEE
	movl	$LC10, (%esp)
	call	_puts
LEHE10:
	jmp	L52
L51:
	movl	%eax, (%esp)
LEHB11:
	call	__Unwind_Resume
LEHE11:
L52:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2155:
	.section	.gcc_except_table,"w"
LLSDA2155:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2155-LLSDACSB2155
LLSDACSB2155:
	.uleb128 LEHB10-LFB2155
	.uleb128 LEHE10-LEHB10
	.uleb128 L51-LFB2155
	.uleb128 0
	.uleb128 LEHB11-LFB2155
	.uleb128 LEHE11-LEHB11
	.uleb128 0
	.uleb128 0
LLSDACSE2155:
	.text
	.section .rdata,"dr"
LC11:
	.ascii "[Optimize Test 02]\0"
	.text
	.globl	__Z12runTestOpt02v
	.def	__Z12runTestOpt02v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt02v:
LFB2156:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2156
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$40024, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	movl	$LC3, (%esp)
LEHB12:
	call	_puts
	movl	$LC11, (%esp)
	call	_puts
	leal	-40008(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z9initOpt02R11dataOpt02_t
	leal	-40008(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z18runTestOpt02_Type1R11dataOpt02_t
LEHE12:
	jmp	L56
L55:
	movl	%eax, (%esp)
LEHB13:
	call	__Unwind_Resume
LEHE13:
L56:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2156:
	.section	.gcc_except_table,"w"
LLSDA2156:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2156-LLSDACSB2156
LLSDACSB2156:
	.uleb128 LEHB12-LFB2156
	.uleb128 LEHE12-LEHB12
	.uleb128 L55-LFB2156
	.uleb128 0
	.uleb128 LEHB13-LFB2156
	.uleb128 LEHE13-LEHB13
	.uleb128 0
	.uleb128 0
LLSDACSE2156:
	.text
	.globl	__Z18runTestOpt02_Type1R11dataOpt02_t
	.def	__Z18runTestOpt02_Type1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z18runTestOpt02_Type1R11dataOpt02_t:
LFB2157:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$10000, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25runTestOpt02_Type1_BeforeR11dataOpt02_t
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25runTestOpt02_Type1_After1R11dataOpt02_t
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25runTestOpt02_Type1_After2R11dataOpt02_t
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2157:
	.globl	__Z25runTestOpt02_Type1_BeforeR11dataOpt02_t
	.def	__Z25runTestOpt02_Type1_BeforeR11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt02_Type1_BeforeR11dataOpt02_t:
LFB2158:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2158
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC6, (%esp)
LEHB14:
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	jmp	L59
L60:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt02_Type1_BeforeR11dataOpt02_t
	addl	$1, -12(%ebp)
L59:
	cmpl	$9999, -12(%ebp)
	jle	L60
	movl	$0, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb
LEHE14:
	jmp	L63
L62:
	movl	%eax, (%esp)
LEHB15:
	call	__Unwind_Resume
LEHE15:
L63:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2158:
	.section	.gcc_except_table,"w"
LLSDA2158:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2158-LLSDACSB2158
LLSDACSB2158:
	.uleb128 LEHB14-LFB2158
	.uleb128 LEHE14-LEHB14
	.uleb128 L62-LFB2158
	.uleb128 0
	.uleb128 LEHB15-LFB2158
	.uleb128 LEHE15-LEHB15
	.uleb128 0
	.uleb128 0
LLSDACSE2158:
	.text
	.globl	__Z25runTestOpt02_Type1_After1R11dataOpt02_t
	.def	__Z25runTestOpt02_Type1_After1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt02_Type1_After1R11dataOpt02_t:
LFB2159:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2159
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC7, (%esp)
LEHB16:
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	jmp	L65
L66:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt02_Type1_After1R11dataOpt02_t
	addl	$1, -12(%ebp)
L65:
	cmpl	$9999, -12(%ebp)
	jle	L66
	movl	$0, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb
LEHE16:
	jmp	L69
L68:
	movl	%eax, (%esp)
LEHB17:
	call	__Unwind_Resume
LEHE17:
L69:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2159:
	.section	.gcc_except_table,"w"
LLSDA2159:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2159-LLSDACSB2159
LLSDACSB2159:
	.uleb128 LEHB16-LFB2159
	.uleb128 LEHE16-LEHB16
	.uleb128 L68-LFB2159
	.uleb128 0
	.uleb128 LEHB17-LFB2159
	.uleb128 LEHE17-LEHB17
	.uleb128 0
	.uleb128 0
LLSDACSE2159:
	.text
	.globl	__Z25runTestOpt02_Type1_After2R11dataOpt02_t
	.def	__Z25runTestOpt02_Type1_After2R11dataOpt02_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt02_Type1_After2R11dataOpt02_t:
LFB2160:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2160
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC8, (%esp)
LEHB18:
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	jmp	L71
L72:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt02_Type1_After2R11dataOpt02_t
	addl	$1, -12(%ebp)
L71:
	cmpl	$9999, -12(%ebp)
	jle	L72
	movl	$0, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb
LEHE18:
	jmp	L75
L74:
	movl	%eax, (%esp)
LEHB19:
	call	__Unwind_Resume
LEHE19:
L75:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2160:
	.section	.gcc_except_table,"w"
LLSDA2160:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2160-LLSDACSB2160
LLSDACSB2160:
	.uleb128 LEHB18-LFB2160
	.uleb128 LEHE18-LEHB18
	.uleb128 L74-LFB2160
	.uleb128 0
	.uleb128 LEHB19-LFB2160
	.uleb128 LEHE19-LEHB19
	.uleb128 0
	.uleb128 0
LLSDACSE2160:
	.text
	.section .rdata,"dr"
LC12:
	.ascii "[Optimize Test 03]\0"
	.text
	.globl	__Z12runTestOpt03v
	.def	__Z12runTestOpt03v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt03v:
LFB2161:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$LC3, (%esp)
	call	_puts
	movl	$LC12, (%esp)
	call	_puts
	call	__Z18runTestOpt03_Type1v
	call	__Z18runTestOpt03_Type2v
	call	__Z18runTestOpt03_Type3v
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2161:
	.align 2
	.def	__ZZ18runTestOpt03_Type1vENKUlvE_clEv;	.scl	3;	.type	32;	.endef
__ZZ18runTestOpt03_Type1vENKUlvE_clEv:
LFB2163:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2163
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$9, 8(%esp)
	movl	$0, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
LEHB20:
	call	__ZNSt24uniform_int_distributionIiEC1Eii
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_
LEHE20:
	jmp	L81
L80:
	movl	%eax, (%esp)
LEHB21:
	call	__Unwind_Resume
LEHE21:
L81:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2163:
	.section	.gcc_except_table,"w"
LLSDA2163:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2163-LLSDACSB2163
LLSDACSB2163:
	.uleb128 LEHB20-LFB2163
	.uleb128 LEHE20-LEHB20
	.uleb128 L80-LFB2163
	.uleb128 0
	.uleb128 LEHB21-LFB2163
	.uleb128 LEHE21-LEHB21
	.uleb128 0
	.uleb128 0
LLSDACSE2163:
	.text
	.globl	__Z18runTestOpt03_Type1v
	.def	__Z18runTestOpt03_Type1v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt03_Type1v:
LFB2162:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2162
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$2536, %esp
	movl	$5489, 4(%esp)
	leal	-2520(%ebp), %eax
	movl	%eax, (%esp)
LEHB22:
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC1Ej
	leal	-2520(%ebp), %eax
	movl	%eax, -20(%ebp)
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ18runTestOpt03_Type1vENKUlvE_clEv
	movl	%eax, -12(%ebp)
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ18runTestOpt03_Type1vENKUlvE_clEv
	movl	%eax, -16(%ebp)
	movl	$100000000, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25runTestOpt03_Type1_Beforeii
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z24runTestOpt03_Type1_Afterii
LEHE22:
	jmp	L85
L84:
	movl	%eax, (%esp)
LEHB23:
	call	__Unwind_Resume
LEHE23:
L85:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2162:
	.section	.gcc_except_table,"w"
LLSDA2162:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2162-LLSDACSB2162
LLSDACSB2162:
	.uleb128 LEHB22-LFB2162
	.uleb128 LEHE22-LEHB22
	.uleb128 L84-LFB2162
	.uleb128 0
	.uleb128 LEHB23-LFB2162
	.uleb128 LEHE23-LEHB23
	.uleb128 0
	.uleb128 0
LLSDACSE2162:
	.text
	.section .rdata,"dr"
LC13:
	.ascii "  sum=%d\12\0"
	.text
	.globl	__Z25runTestOpt03_Type1_Beforeii
	.def	__Z25runTestOpt03_Type1_Beforeii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt03_Type1_Beforeii:
LFB2164:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2164
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC6, (%esp)
LEHB24:
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L87
L88:
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt03_Type1_Beforeiii
	addl	%eax, -12(%ebp)
	addl	$1, -16(%ebp)
L87:
	cmpl	$99999999, -16(%ebp)
	jle	L88
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25printElapsedTimeWithoutCRRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEE
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC13, (%esp)
	call	_printf
LEHE24:
	jmp	L91
L90:
	movl	%eax, (%esp)
LEHB25:
	call	__Unwind_Resume
LEHE25:
L91:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2164:
	.section	.gcc_except_table,"w"
LLSDA2164:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2164-LLSDACSB2164
LLSDACSB2164:
	.uleb128 LEHB24-LFB2164
	.uleb128 LEHE24-LEHB24
	.uleb128 L90-LFB2164
	.uleb128 0
	.uleb128 LEHB25-LFB2164
	.uleb128 LEHE25-LEHB25
	.uleb128 0
	.uleb128 0
LLSDACSE2164:
	.text
	.section .rdata,"dr"
LC14:
	.ascii "  After    ... \0"
	.text
	.globl	__Z24runTestOpt03_Type1_Afterii
	.def	__Z24runTestOpt03_Type1_Afterii;	.scl	2;	.type	32;	.endef
__Z24runTestOpt03_Type1_Afterii:
LFB2165:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2165
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC14, (%esp)
LEHB26:
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L93
L94:
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z21testOpt03_Type1_Afteriii
	addl	%eax, -12(%ebp)
	addl	$1, -16(%ebp)
L93:
	cmpl	$99999999, -16(%ebp)
	jle	L94
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25printElapsedTimeWithoutCRRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEE
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC13, (%esp)
	call	_printf
LEHE26:
	jmp	L97
L96:
	movl	%eax, (%esp)
LEHB27:
	call	__Unwind_Resume
LEHE27:
L97:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2165:
	.section	.gcc_except_table,"w"
LLSDA2165:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2165-LLSDACSB2165
LLSDACSB2165:
	.uleb128 LEHB26-LFB2165
	.uleb128 LEHE26-LEHB26
	.uleb128 L96-LFB2165
	.uleb128 0
	.uleb128 LEHB27-LFB2165
	.uleb128 LEHE27-LEHB27
	.uleb128 0
	.uleb128 0
LLSDACSE2165:
	.text
	.align 2
	.def	__ZZ18runTestOpt03_Type2vENKUlvE_clEv;	.scl	3;	.type	32;	.endef
__ZZ18runTestOpt03_Type2vENKUlvE_clEv:
LFB2167:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2167
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$9, 8(%esp)
	movl	$0, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
LEHB28:
	call	__ZNSt24uniform_int_distributionIiEC1Eii
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_
LEHE28:
	jmp	L102
L101:
	movl	%eax, (%esp)
LEHB29:
	call	__Unwind_Resume
LEHE29:
L102:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2167:
	.section	.gcc_except_table,"w"
LLSDA2167:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2167-LLSDACSB2167
LLSDACSB2167:
	.uleb128 LEHB28-LFB2167
	.uleb128 LEHE28-LEHB28
	.uleb128 L101-LFB2167
	.uleb128 0
	.uleb128 LEHB29-LFB2167
	.uleb128 LEHE29-LEHB29
	.uleb128 0
	.uleb128 0
LLSDACSE2167:
	.text
	.section .rdata,"dr"
LC15:
	.ascii "Type2: *repeated * %d times.\12\0"
	.text
	.globl	__Z18runTestOpt03_Type2v
	.def	__Z18runTestOpt03_Type2v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt03_Type2v:
LFB2166:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2166
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$2584, %esp
	movl	$5489, 4(%esp)
	leal	-2540(%ebp), %eax
	movl	%eax, (%esp)
LEHB30:
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC1Ej
	leal	-2540(%ebp), %eax
	movl	%eax, -40(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ18runTestOpt03_Type2vENKUlvE_clEv
	movl	%eax, -12(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ18runTestOpt03_Type2vENKUlvE_clEv
	movl	%eax, -16(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ18runTestOpt03_Type2vENKUlvE_clEv
	movl	%eax, -20(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ18runTestOpt03_Type2vENKUlvE_clEv
	movl	%eax, -24(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ18runTestOpt03_Type2vENKUlvE_clEv
	movl	%eax, -28(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ18runTestOpt03_Type2vENKUlvE_clEv
	movl	%eax, -32(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZZ18runTestOpt03_Type2vENKUlvE_clEv
	movl	%eax, -36(%ebp)
	movl	$100000000, 4(%esp)
	movl	$LC15, (%esp)
	call	_printf
	movl	-36(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25runTestOpt03_Type2_Beforeiiiiiii
	movl	-36(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z24runTestOpt03_Type2_Afteriiiiiii
LEHE30:
	jmp	L106
L105:
	movl	%eax, (%esp)
LEHB31:
	call	__Unwind_Resume
LEHE31:
L106:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2166:
	.section	.gcc_except_table,"w"
LLSDA2166:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2166-LLSDACSB2166
LLSDACSB2166:
	.uleb128 LEHB30-LFB2166
	.uleb128 LEHE30-LEHB30
	.uleb128 L105-LFB2166
	.uleb128 0
	.uleb128 LEHB31-LFB2166
	.uleb128 LEHE31-LEHB31
	.uleb128 0
	.uleb128 0
LLSDACSE2166:
	.text
	.globl	__Z25runTestOpt03_Type2_Beforeiiiiiii
	.def	__Z25runTestOpt03_Type2_Beforeiiiiiii;	.scl	2;	.type	32;	.endef
__Z25runTestOpt03_Type2_Beforeiiiiiii:
LFB2168:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2168
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	$LC6, (%esp)
LEHB32:
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L108
L109:
	movl	32(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	28(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	24(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	20(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt03_Type2_Beforeiiiiiiii
	addl	%eax, -12(%ebp)
	addl	$1, -16(%ebp)
L108:
	cmpl	$99999999, -16(%ebp)
	jle	L109
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25printElapsedTimeWithoutCRRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEE
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC13, (%esp)
	call	_printf
LEHE32:
	jmp	L112
L111:
	movl	%eax, (%esp)
LEHB33:
	call	__Unwind_Resume
LEHE33:
L112:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2168:
	.section	.gcc_except_table,"w"
LLSDA2168:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2168-LLSDACSB2168
LLSDACSB2168:
	.uleb128 LEHB32-LFB2168
	.uleb128 LEHE32-LEHB32
	.uleb128 L111-LFB2168
	.uleb128 0
	.uleb128 LEHB33-LFB2168
	.uleb128 LEHE33-LEHB33
	.uleb128 0
	.uleb128 0
LLSDACSE2168:
	.text
	.globl	__Z24runTestOpt03_Type2_Afteriiiiiii
	.def	__Z24runTestOpt03_Type2_Afteriiiiiii;	.scl	2;	.type	32;	.endef
__Z24runTestOpt03_Type2_Afteriiiiiii:
LFB2169:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2169
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	$LC14, (%esp)
LEHB34:
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L114
L115:
	movl	32(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	28(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	24(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	20(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z21testOpt03_Type2_Afteriiiiiiii
	addl	%eax, -12(%ebp)
	addl	$1, -16(%ebp)
L114:
	cmpl	$99999999, -16(%ebp)
	jle	L115
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25printElapsedTimeWithoutCRRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEE
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC13, (%esp)
	call	_printf
LEHE34:
	jmp	L118
L117:
	movl	%eax, (%esp)
LEHB35:
	call	__Unwind_Resume
LEHE35:
L118:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2169:
	.section	.gcc_except_table,"w"
LLSDA2169:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2169-LLSDACSB2169
LLSDACSB2169:
	.uleb128 LEHB34-LFB2169
	.uleb128 LEHE34-LEHB34
	.uleb128 L117-LFB2169
	.uleb128 0
	.uleb128 LEHB35-LFB2169
	.uleb128 LEHE35-LEHB35
	.uleb128 0
	.uleb128 0
LLSDACSE2169:
	.text
	.section .rdata,"dr"
LC16:
	.ascii "Type3: *repeated * %d times.\12\0"
	.text
	.globl	__Z18runTestOpt03_Type3v
	.def	__Z18runTestOpt03_Type3v;	.scl	2;	.type	32;	.endef
__Z18runTestOpt03_Type3v:
LFB2170:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$10000, 4(%esp)
	movl	$LC16, (%esp)
	call	_printf
	call	__Z25runTestOpt03_Type3_Beforev
	call	__Z24runTestOpt03_Type3_Afterv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2170:
	.section .rdata,"dr"
LC17:
	.ascii "  count=%d\12\0"
	.text
	.globl	__Z25runTestOpt03_Type3_Beforev
	.def	__Z25runTestOpt03_Type3_Beforev;	.scl	2;	.type	32;	.endef
__Z25runTestOpt03_Type3_Beforev:
LFB2171:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2171
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$40040, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	leal	-40024(%ebp), %eax
	movl	%eax, (%esp)
LEHB36:
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	$LC6, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L121
L122:
	leal	-40024(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt03_Type3_BeforeR11dataOpt03_t
	addl	%eax, -12(%ebp)
	addl	$1, -16(%ebp)
L121:
	cmpl	$9999, -16(%ebp)
	jle	L122
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25printElapsedTimeWithoutCRRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEE
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC17, (%esp)
	call	_printf
LEHE36:
	jmp	L125
L124:
	movl	%eax, (%esp)
LEHB37:
	call	__Unwind_Resume
LEHE37:
L125:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2171:
	.section	.gcc_except_table,"w"
LLSDA2171:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2171-LLSDACSB2171
LLSDACSB2171:
	.uleb128 LEHB36-LFB2171
	.uleb128 LEHE36-LEHB36
	.uleb128 L124-LFB2171
	.uleb128 0
	.uleb128 LEHB37-LFB2171
	.uleb128 LEHE37-LEHB37
	.uleb128 0
	.uleb128 0
LLSDACSE2171:
	.text
	.globl	__Z24runTestOpt03_Type3_Afterv
	.def	__Z24runTestOpt03_Type3_Afterv;	.scl	2;	.type	32;	.endef
__Z24runTestOpt03_Type3_Afterv:
LFB2172:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2172
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$40040, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	leal	-40024(%ebp), %eax
	movl	%eax, (%esp)
LEHB38:
	call	__Z15initOpt03_Type3R11dataOpt03_t
	movl	$LC14, (%esp)
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L127
L128:
	leal	-40024(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z21testOpt03_Type3_AfterR11dataOpt03_t
	addl	%eax, -12(%ebp)
	addl	$1, -16(%ebp)
L127:
	cmpl	$9999, -16(%ebp)
	jle	L128
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25printElapsedTimeWithoutCRRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEE
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC17, (%esp)
	call	_printf
LEHE38:
	jmp	L131
L130:
	movl	%eax, (%esp)
LEHB39:
	call	__Unwind_Resume
LEHE39:
L131:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2172:
	.section	.gcc_except_table,"w"
LLSDA2172:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2172-LLSDACSB2172
LLSDACSB2172:
	.uleb128 LEHB38-LFB2172
	.uleb128 LEHE38-LEHB38
	.uleb128 L130-LFB2172
	.uleb128 0
	.uleb128 LEHB39-LFB2172
	.uleb128 LEHE39-LEHB39
	.uleb128 0
	.uleb128 0
LLSDACSE2172:
	.text
	.section .rdata,"dr"
LC18:
	.ascii "[Optimize Test 04]\0"
	.text
	.globl	__Z12runTestOpt04v
	.def	__Z12runTestOpt04v;	.scl	2;	.type	32;	.endef
__Z12runTestOpt04v:
LFB2173:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2173
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$80024, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	movl	$LC3, (%esp)
LEHB40:
	call	_puts
	movl	$LC18, (%esp)
	call	_puts
	leal	-80008(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z9initOpt04R11dataOpt04_t
	leal	-80008(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z18runTestOpt04_Type1R11dataOpt04_t
LEHE40:
	jmp	L135
L134:
	movl	%eax, (%esp)
LEHB41:
	call	__Unwind_Resume
LEHE41:
L135:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2173:
	.section	.gcc_except_table,"w"
LLSDA2173:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2173-LLSDACSB2173
LLSDACSB2173:
	.uleb128 LEHB40-LFB2173
	.uleb128 LEHE40-LEHB40
	.uleb128 L134-LFB2173
	.uleb128 0
	.uleb128 LEHB41-LFB2173
	.uleb128 LEHE41-LEHB41
	.uleb128 0
	.uleb128 0
LLSDACSE2173:
	.text
	.globl	__Z18runTestOpt04_Type1R11dataOpt04_t
	.def	__Z18runTestOpt04_Type1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z18runTestOpt04_Type1R11dataOpt04_t:
LFB2174:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$10000, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25runTestOpt04_Type1_BeforeR11dataOpt04_t
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25runTestOpt04_Type1_After1R11dataOpt04_t
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z25runTestOpt04_Type1_After2R11dataOpt04_t
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2174:
	.globl	__Z25runTestOpt04_Type1_BeforeR11dataOpt04_t
	.def	__Z25runTestOpt04_Type1_BeforeR11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type1_BeforeR11dataOpt04_t:
LFB2175:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2175
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC6, (%esp)
LEHB42:
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	jmp	L138
L139:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt04_Type1_BeforeR11dataOpt04_t
	addl	$1, -12(%ebp)
L138:
	cmpl	$9999, -12(%ebp)
	jle	L139
	movl	$0, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb
LEHE42:
	jmp	L142
L141:
	movl	%eax, (%esp)
LEHB43:
	call	__Unwind_Resume
LEHE43:
L142:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2175:
	.section	.gcc_except_table,"w"
LLSDA2175:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2175-LLSDACSB2175
LLSDACSB2175:
	.uleb128 LEHB42-LFB2175
	.uleb128 LEHE42-LEHB42
	.uleb128 L141-LFB2175
	.uleb128 0
	.uleb128 LEHB43-LFB2175
	.uleb128 LEHE43-LEHB43
	.uleb128 0
	.uleb128 0
LLSDACSE2175:
	.text
	.globl	__Z25runTestOpt04_Type1_After1R11dataOpt04_t
	.def	__Z25runTestOpt04_Type1_After1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type1_After1R11dataOpt04_t:
LFB2176:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2176
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC7, (%esp)
LEHB44:
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	jmp	L144
L145:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt04_Type1_After1R11dataOpt04_t
	addl	$1, -12(%ebp)
L144:
	cmpl	$9999, -12(%ebp)
	jle	L145
	movl	$0, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb
LEHE44:
	jmp	L148
L147:
	movl	%eax, (%esp)
LEHB45:
	call	__Unwind_Resume
LEHE45:
L148:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2176:
	.section	.gcc_except_table,"w"
LLSDA2176:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2176-LLSDACSB2176
LLSDACSB2176:
	.uleb128 LEHB44-LFB2176
	.uleb128 LEHE44-LEHB44
	.uleb128 L147-LFB2176
	.uleb128 0
	.uleb128 LEHB45-LFB2176
	.uleb128 LEHE45-LEHB45
	.uleb128 0
	.uleb128 0
LLSDACSE2176:
	.text
	.globl	__Z25runTestOpt04_Type1_After2R11dataOpt04_t
	.def	__Z25runTestOpt04_Type1_After2R11dataOpt04_t;	.scl	2;	.type	32;	.endef
__Z25runTestOpt04_Type1_After2R11dataOpt04_t:
LFB2177:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2177
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC8, (%esp)
LEHB46:
	call	_printf
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	$0, -12(%ebp)
	jmp	L150
L151:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z22testOpt04_Type1_After2R11dataOpt04_t
	addl	$1, -12(%ebp)
L150:
	cmpl	$9999, -12(%ebp)
	jle	L151
	movl	$0, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z16printElapsedTimeRKNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEEEb
LEHE46:
	jmp	L154
L153:
	movl	%eax, (%esp)
LEHB47:
	call	__Unwind_Resume
LEHE47:
L154:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2177:
	.section	.gcc_except_table,"w"
LLSDA2177:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2177-LLSDACSB2177
LLSDACSB2177:
	.uleb128 LEHB46-LFB2177
	.uleb128 LEHE46-LEHB46
	.uleb128 L153-LFB2177
	.uleb128 0
	.uleb128 LEHB47-LFB2177
	.uleb128 LEHE47-LEHB47
	.uleb128 0
	.uleb128 0
LLSDACSE2177:
	.text
	.section .rdata,"dr"
	.align 4
LC19:
	.ascii "[Test for Lambda with closure]\0"
LC20:
	.ascii "Call lambda in main().\0"
	.text
	.globl	__Z14testForClosurev
	.def	__Z14testForClosurev;	.scl	2;	.type	32;	.endef
__Z14testForClosurev:
LFB2178:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2178
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC3, (%esp)
LEHB48:
	call	_puts
	movl	$LC19, (%esp)
	call	_puts
	movl	$0, -12(%ebp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z9setLambdaRi
	movl	$LC20, (%esp)
	call	_puts
	call	__Z12callLambda13v
	call	__Z12callLambda13v
	call	__Z12callLambda13v
LEHE48:
	jmp	L158
L157:
	movl	%eax, (%esp)
LEHB49:
	call	__Unwind_Resume
LEHE49:
L158:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2178:
	.section	.gcc_except_table,"w"
LLSDA2178:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2178-LLSDACSB2178
LLSDACSB2178:
	.uleb128 LEHB48-LFB2178
	.uleb128 LEHE48-LEHB48
	.uleb128 L157-LFB2178
	.uleb128 0
	.uleb128 LEHB49-LFB2178
	.uleb128 LEHE49-LEHB49
	.uleb128 0
	.uleb128 0
LLSDACSE2178:
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB2179:
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
	call	__Z12runTestOpt03v
	call	__Z12runTestOpt04v
	call	__Z14testForClosurev
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2179:
	.section	.text$_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC1Ej,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC1Ej
	.def	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC1Ej;	.scl	2;	.type	32;	.endef
__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC1Ej:
LFB2200:
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
LFE2200:
	.section	.text$_ZNSt24uniform_int_distributionIiEC1Eii,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt24uniform_int_distributionIiEC1Eii
	.def	__ZNSt24uniform_int_distributionIiEC1Eii;	.scl	2;	.type	32;	.endef
__ZNSt24uniform_int_distributionIiEC1Eii:
LFB2203:
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
LFE2203:
	.section	.text$_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_
	.def	__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_;	.scl	2;	.type	32;	.endef
__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_:
LFB2204:
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
LFE2204:
	.section	.text$_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE4seedEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE4seedEj
	.def	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE4seedEj;	.scl	2;	.type	32;	.endef
__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE4seedEj:
LFB2226:
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
	jmp	L166
L167:
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
L166:
	cmpl	$623, -12(%ebp)
	jbe	L167
	movl	8(%ebp), %eax
	movl	$624, 2496(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2226:
	.section	.text$_ZNSt24uniform_int_distributionIiE10param_typeC1Eii,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt24uniform_int_distributionIiE10param_typeC1Eii
	.def	__ZNSt24uniform_int_distributionIiE10param_typeC1Eii;	.scl	2;	.type	32;	.endef
__ZNSt24uniform_int_distributionIiE10param_typeC1Eii:
LFB2229:
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
LFE2229:
	.section	.text$_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE
	.def	__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE;	.scl	2;	.type	32;	.endef
__ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE:
LFB2230:
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
	je	L170
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
L171:
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	cmpl	-40(%ebp), %eax
	jae	L171
	movl	-12(%ebp), %eax
	movl	$0, %edx
	divl	-36(%ebp)
	movl	%eax, -12(%ebp)
	jmp	L172
L170:
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	movl	%eax, -12(%ebp)
L172:
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
LFE2230:
	.section	.text$_ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_,"x"
	.linkonce discard
	.globl	__ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_
	.def	__ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_:
LFB2242:
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
LFE2242:
	.section	.text$_ZNSt8__detail5__modIjLj624ELj1ELj0EEET_S1_,"x"
	.linkonce discard
	.globl	__ZNSt8__detail5__modIjLj624ELj1ELj0EEET_S1_
	.def	__ZNSt8__detail5__modIjLj624ELj1ELj0EEET_S1_;	.scl	2;	.type	32;	.endef
__ZNSt8__detail5__modIjLj624ELj1ELj0EEET_S1_:
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
	call	__ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2243:
	.section	.text$_ZNKSt24uniform_int_distributionIiE10param_type1aEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt24uniform_int_distributionIiE10param_type1aEv
	.def	__ZNKSt24uniform_int_distributionIiE10param_type1aEv;	.scl	2;	.type	32;	.endef
__ZNKSt24uniform_int_distributionIiE10param_type1aEv:
LFB2244:
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
LFE2244:
	.section	.text$_ZNKSt24uniform_int_distributionIiE10param_type1bEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt24uniform_int_distributionIiE10param_type1bEv
	.def	__ZNKSt24uniform_int_distributionIiE10param_type1bEv;	.scl	2;	.type	32;	.endef
__ZNKSt24uniform_int_distributionIiE10param_type1bEv:
LFB2245:
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
LFE2245:
	.section	.text$_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv
	.def	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv;	.scl	2;	.type	32;	.endef
__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv:
LFB2246:
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
	jbe	L183
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv
L183:
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
LFE2246:
	.section	.text$_ZNSt8__detail4_ModIjLj0ELj1ELj0ELb1ELb0EE6__calcEj,"x"
	.linkonce discard
	.globl	__ZNSt8__detail4_ModIjLj0ELj1ELj0ELb1ELb0EE6__calcEj
	.def	__ZNSt8__detail4_ModIjLj0ELj1ELj0ELb1ELb0EE6__calcEj;	.scl	2;	.type	32;	.endef
__ZNSt8__detail4_ModIjLj0ELj1ELj0ELb1ELb0EE6__calcEj:
LFB2255:
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
LFE2255:
	.section	.text$_ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj,"x"
	.linkonce discard
	.globl	__ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj
	.def	__ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj;	.scl	2;	.type	32;	.endef
__ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj:
LFB2256:
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
LFE2256:
	.section	.text$_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv
	.def	__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv;	.scl	2;	.type	32;	.endef
__ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv:
LFB2257:
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
	jmp	L190
L193:
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
	je	L191
	movl	$-1727483681, %eax
	jmp	L192
L191:
	movl	$0, %eax
L192:
	movl	%edx, %ecx
	xorl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%ecx, (%eax,%edx,4)
	addl	$1, -4(%ebp)
L190:
	cmpl	$226, -4(%ebp)
	jbe	L193
	movl	$227, -8(%ebp)
	jmp	L194
L197:
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
	je	L195
	movl	$-1727483681, %eax
	jmp	L196
L195:
	movl	$0, %eax
L196:
	movl	%edx, %ecx
	xorl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	-8(%ebp), %edx
	movl	%ecx, (%eax,%edx,4)
	addl	$1, -8(%ebp)
L194:
	cmpl	$622, -8(%ebp)
	jbe	L197
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
	je	L198
	movl	$-1727483681, %eax
	jmp	L199
L198:
	movl	$0, %eax
L199:
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
LFE2257:
	.section .rdata,"dr"
	.align 4
__ZL16LOOP_OPT01_TYPE1:
	.long	10000
	.align 4
__ZL16LOOP_OPT02_TYPE1:
	.long	10000
	.align 4
__ZL16LOOP_OPT03_TYPE1:
	.long	100000000
	.align 4
__ZL16LOOP_OPT03_TYPE2:
	.long	100000000
	.align 4
__ZL16LOOP_OPT03_TYPE3:
	.long	10000
	.align 4
__ZL16LOOP_OPT04_TYPE1:
	.long	10000
	.align 8
LC0:
	.long	0
	.long	1104006501
	.ident	"GCC: (GNU) 4.8.2"
	.def	__ZNSt6chrono3_V212system_clock3nowEv;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	__Z9initOpt01R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt01_Type1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt01_Type1_BeforeR11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt01_Type1_After1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt01_Type1_After2R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z27runTestOpt01_Type1_AppendixR11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt01_Type1_BeforeR11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt01_Type1_After1R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt01_Type1_After2R11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z24testOpt01_Type1_AppendixR11dataOpt01_t;	.scl	2;	.type	32;	.endef
	.def	__Z9initOpt02R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt02_Type1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt02_Type1_BeforeR11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt02_Type1_After1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt02_Type1_After2R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt02_Type1_BeforeR11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt02_Type1_After1R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt02_Type1_After2R11dataOpt02_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt03_Type1v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt03_Type2v;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt03_Type3v;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt03_Type1_Beforeii;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt03_Type1_Afterii;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt03_Type1_Beforeiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt03_Type2_Beforeiiiiiii;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt03_Type2_Afteriiiiiii;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt03_Type2_Beforeiiiiiiii;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt03_Type3_Beforev;	.scl	2;	.type	32;	.endef
	.def	__Z24runTestOpt03_Type3_Afterv;	.scl	2;	.type	32;	.endef
	.def	__Z15initOpt03_Type3R11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt03_Type3_BeforeR11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z21testOpt03_Type3_AfterR11dataOpt03_t;	.scl	2;	.type	32;	.endef
	.def	__Z9initOpt04R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z18runTestOpt04_Type1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type1_BeforeR11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type1_After1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z25runTestOpt04_Type1_After2R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt04_Type1_BeforeR11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt04_Type1_After1R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z22testOpt04_Type1_After2R11dataOpt04_t;	.scl	2;	.type	32;	.endef
	.def	__Z9setLambdaRi;	.scl	2;	.type	32;	.endef
	.def	__Z12callLambda13v;	.scl	2;	.type	32;	.endef

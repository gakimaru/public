	.file	"lock_free_algorithm.cpp"
	.section	.text$_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv
	.def	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv;	.scl	2;	.type	32;	.endef
__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv:
LFB3312:
	.cfi_startproc
	movl	4(%esp), %eax
	testl	%eax, %eax
	je	L1
	movl	(%eax), %edx
	movl	4(%edx), %eax
	jmp	*%eax
	.p2align 4,,7
L1:
	rep ret
	.cfi_endproc
LFE3312:
	.section	.text$_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED1Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED1Ev
	.def	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED1Ev:
LFB3560:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	ret
	.cfi_endproc
LFE3560:
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED2Ev;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED2Ev:
LFB3901:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	ret
	.cfi_endproc
LFE3901:
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED1Ev;	.scl	3;	.type	32;	.endef
	.set	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED1Ev,__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED2Ev
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv:
LFB3904:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	12(%eax), %eax
	movl	(%eax), %edx
	movl	%eax, 4(%esp)
	movl	(%edx), %eax
	jmp	*%eax
	.cfi_endproc
LFE3904:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED2Ev;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED2Ev:
LFB3908:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	ret
	.cfi_endproc
LFE3908:
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED1Ev;	.scl	3;	.type	32;	.endef
	.set	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED1Ev,__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED2Ev
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv:
LFB3911:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	12(%eax), %eax
	movl	(%eax), %edx
	movl	%eax, 4(%esp)
	movl	(%edx), %eax
	jmp	*%eax
	.cfi_endproc
LFE3911:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED2Ev;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED2Ev:
LFB3915:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	ret
	.cfi_endproc
LFE3915:
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED1Ev;	.scl	3;	.type	32;	.endef
	.set	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED1Ev,__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED2Ev
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv:
LFB3918:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	12(%eax), %eax
	movl	(%eax), %edx
	movl	%eax, 4(%esp)
	movl	(%edx), %eax
	jmp	*%eax
	.cfi_endproc
LFE3918:
	.section	.text$_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED0Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED0Ev
	.def	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED0Ev;	.scl	2;	.type	32;	.endef
__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED0Ev:
LFB3561:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	jmp	__ZdlPv
	.cfi_endproc
LFE3561:
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv:
LFB3919:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	jmp	__ZdlPv
	.cfi_endproc
LFE3919:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED0Ev;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED0Ev:
LFB3917:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	jmp	__ZdlPv
	.cfi_endproc
LFE3917:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv:
LFB3912:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	jmp	__ZdlPv
	.cfi_endproc
LFE3912:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED0Ev;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED0Ev:
LFB3910:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	jmp	__ZdlPv
	.cfi_endproc
LFE3910:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv:
LFB3905:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	jmp	__ZdlPv
	.cfi_endproc
LFE3905:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED0Ev;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED0Ev:
LFB3903:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	jmp	__ZdlPv
	.cfi_endproc
LFE3903:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info:
LFB3920:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	36(%esp), %eax
	movl	$__ZTISt19_Sp_make_shared_tag, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt9type_infoeqERKS_
	movl	32(%esp), %ecx
	xorl	%edx, %edx
	addl	$16, %ecx
	testb	%al, %al
	cmovne	%ecx, %edx
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	movl	%edx, %eax
	ret
	.cfi_endproc
LFE3920:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info:
LFB3913:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	36(%esp), %eax
	movl	$__ZTISt19_Sp_make_shared_tag, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt9type_infoeqERKS_
	movl	32(%esp), %ecx
	xorl	%edx, %edx
	addl	$16, %ecx
	testb	%al, %al
	cmovne	%ecx, %edx
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	movl	%edx, %eax
	ret
	.cfi_endproc
LFE3913:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info:
LFB3906:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	36(%esp), %eax
	movl	$__ZTISt19_Sp_make_shared_tag, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSt9type_infoeqERKS_
	movl	32(%esp), %ecx
	xorl	%edx, %edx
	addl	$16, %ecx
	testb	%al, %al
	cmovne	%ecx, %edx
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	movl	%edx, %eax
	ret
	.cfi_endproc
LFE3906:
	.section	.text.unlikely,"x"
	.align 2
	.def	__ZNSt6bitsetILj20EE9referenceaSEb.part.212;	.scl	3;	.type	32;	.endef
__ZNSt6bitsetILj20EE9referenceaSEb.part.212:
LFB4191:
	.cfi_startproc
	movl	4(%eax), %ecx
	movl	(%eax), %edx
	movl	$1, %eax
	sall	%cl, %eax
	orl	%eax, (%edx)
	ret
	.cfi_endproc
LFE4191:
	.text
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlP6data_tE3_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlP6data_tE3_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3133:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L33
	jle	L39
	cmpl	$2, %eax
	je	L36
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L32
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L32:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L36:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L39:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L32
	movl	32(%esp), %eax
	movl	$__ZTIZ8easyTestvEUlP6data_tE3_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L33:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3133:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlvE2_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlvE2_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation:
LFB3128:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L42
	jle	L48
	cmpl	$2, %eax
	je	L45
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L41
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L41:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L45:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L48:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L41
	movl	32(%esp), %eax
	movl	$__ZTIZ8easyTestvEUlvE2_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L42:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3128:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlP6data_tE5_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlP6data_tE5_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3142:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L51
	jle	L57
	cmpl	$2, %eax
	je	L54
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L50
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L50:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L54:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L57:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L50
	movl	32(%esp), %eax
	movl	$__ZTIZ8easyTestvEUlP6data_tE5_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L51:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3142:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlvE4_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlvE4_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation:
LFB3138:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L60
	jle	L66
	cmpl	$2, %eax
	je	L63
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L59
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L59:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L63:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L66:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L59
	movl	32(%esp), %eax
	movl	$__ZTIZ8easyTestvEUlvE4_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L60:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3138:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlR6data_tE7_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlR6data_tE7_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3151:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L69
	jle	L75
	cmpl	$2, %eax
	je	L72
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L68
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L68:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L72:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L75:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L68
	movl	32(%esp), %eax
	movl	$__ZTIZ8easyTestvEUlR6data_tE7_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L69:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3151:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlO6data_tE6_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlO6data_tE6_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3146:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L78
	jle	L84
	cmpl	$2, %eax
	je	L81
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L77
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L77:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L81:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L84:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L77
	movl	32(%esp), %eax
	movl	$__ZTIZ8easyTestvEUlO6data_tE6_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L78:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3146:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlR6data_tE9_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlR6data_tE9_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3160:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L87
	jle	L93
	cmpl	$2, %eax
	je	L90
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L86
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L86:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L90:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L93:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L86
	movl	32(%esp), %eax
	movl	$__ZTIZ8easyTestvEUlR6data_tE9_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L87:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3160:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlO6data_tE8_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlO6data_tE8_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3156:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L96
	jle	L102
	cmpl	$2, %eax
	je	L99
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L95
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L95:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L99:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L102:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L95
	movl	32(%esp), %eax
	movl	$__ZTIZ8easyTestvEUlO6data_tE8_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L96:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3156:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlR6data_tE11_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlR6data_tE11_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3168:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L105
	jle	L111
	cmpl	$2, %eax
	je	L108
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L104
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L104:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L108:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L111:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L104
	movl	32(%esp), %eax
	movl	$__ZTIZ8easyTestvEUlR6data_tE11_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L105:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3168:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlO6data_tE10_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlO6data_tE10_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3164:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L114
	jle	L120
	cmpl	$2, %eax
	je	L117
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L113
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L113:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L117:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L120:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L113
	movl	32(%esp), %eax
	movl	$__ZTIZ8easyTestvEUlO6data_tE10_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L114:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3164:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlR6data_tE13_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlR6data_tE13_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3176:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L123
	jle	L129
	cmpl	$2, %eax
	je	L126
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L122
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L122:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L126:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L129:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L122
	movl	32(%esp), %eax
	movl	$__ZTIZ8easyTestvEUlR6data_tE13_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L123:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3176:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlO6data_tE12_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlO6data_tE12_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3172:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L132
	jle	L138
	cmpl	$2, %eax
	je	L135
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L131
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L131:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L135:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L138:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L131
	movl	32(%esp), %eax
	movl	$__ZTIZ8easyTestvEUlO6data_tE12_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L132:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3172:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlP6data_tE3_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlP6data_tE3_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3271:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L141
	jle	L147
	cmpl	$2, %eax
	je	L144
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L140
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L140:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L144:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L147:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L140
	movl	32(%esp), %eax
	movl	$__ZTIZ11thread_testvEUlP6data_tE3_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L141:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3271:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlvE2_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlvE2_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation:
LFB3267:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L150
	jle	L156
	cmpl	$2, %eax
	je	L153
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L149
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L149:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L153:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L156:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L149
	movl	32(%esp), %eax
	movl	$__ZTIZ11thread_testvEUlvE2_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L150:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3267:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlP6data_tE5_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlP6data_tE5_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3279:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L159
	jle	L165
	cmpl	$2, %eax
	je	L162
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L158
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L158:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L162:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L165:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L158
	movl	32(%esp), %eax
	movl	$__ZTIZ11thread_testvEUlP6data_tE5_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L159:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3279:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlvE4_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlvE4_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation:
LFB3275:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L168
	jle	L174
	cmpl	$2, %eax
	je	L171
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L167
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L167:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L171:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L174:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L167
	movl	32(%esp), %eax
	movl	$__ZTIZ11thread_testvEUlvE4_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L168:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3275:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE7_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE7_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3287:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L177
	jle	L183
	cmpl	$2, %eax
	je	L180
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L176
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L176:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L180:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L183:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L176
	movl	32(%esp), %eax
	movl	$__ZTIZ11thread_testvEUlR6data_tE7_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L177:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3287:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE6_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE6_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3283:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L186
	jle	L192
	cmpl	$2, %eax
	je	L189
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L185
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L185:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L189:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L192:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L185
	movl	32(%esp), %eax
	movl	$__ZTIZ11thread_testvEUlO6data_tE6_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L186:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3283:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE9_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE9_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3295:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L195
	jle	L201
	cmpl	$2, %eax
	je	L198
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L194
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L194:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L198:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L201:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L194
	movl	32(%esp), %eax
	movl	$__ZTIZ11thread_testvEUlR6data_tE9_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L195:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3295:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE8_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE8_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3291:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L204
	jle	L210
	cmpl	$2, %eax
	je	L207
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L203
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L203:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L207:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L210:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L203
	movl	32(%esp), %eax
	movl	$__ZTIZ11thread_testvEUlO6data_tE8_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L204:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3291:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE11_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE11_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3303:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L213
	jle	L219
	cmpl	$2, %eax
	je	L216
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L212
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L212:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L216:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L219:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L212
	movl	32(%esp), %eax
	movl	$__ZTIZ11thread_testvEUlR6data_tE11_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L213:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3303:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE10_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE10_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3299:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L222
	jle	L228
	cmpl	$2, %eax
	je	L225
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L221
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L221:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L225:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L228:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L221
	movl	32(%esp), %eax
	movl	$__ZTIZ11thread_testvEUlO6data_tE10_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L222:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3299:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE13_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE13_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3311:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L231
	jle	L237
	cmpl	$2, %eax
	je	L234
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L230
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L230:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L234:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L237:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L230
	movl	32(%esp), %eax
	movl	$__ZTIZ11thread_testvEUlR6data_tE13_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L231:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3311:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE12_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE12_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3307:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	cmpl	$1, %eax
	je	L240
	jle	L246
	cmpl	$2, %eax
	je	L243
	cmpl	$3, %eax
	.p2align 4,,5
	jne	L239
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
L239:
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L243:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__Znwj
	movl	32(%esp), %ecx
	movl	%eax, (%ecx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L246:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L239
	movl	32(%esp), %eax
	movl	$__ZTIZ11thread_testvEUlO6data_tE12_, (%eax)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L240:
	.cfi_restore_state
	movl	36(%esp), %eax
	movl	32(%esp), %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	xorl	%eax, %eax
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3307:
	.section .rdata,"dr"
LC0:
	.ascii "IS_INVALID_POINTER_OF_POOL\0"
LC1:
	.ascii "lock_free_algorithm.cpp\0"
LC2:
	.ascii "IS_ALREADY_DELETE_POINTER\0"
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbP6data_tEZ8easyTestvEUlS1_E5_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbP6data_tEZ8easyTestvEUlS1_E5_E9_M_invokeERKSt9_Any_dataS1_:
LFB3141:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$40, %esp
	.cfi_def_cfa_offset 48
	movl	52(%esp), %ecx
	subl	$__ZL17s_lfPoolAllocator, %ecx
	shrl	$3, %ecx
	cmpl	$19, %ecx
	ja	L253
	movzbl	__ZL17s_lfPoolAllocator+169(%ecx), %eax
	leal	__ZL17s_lfPoolAllocator+169(%ecx), %ebx
	testb	%al, %al
	je	L254
	movl	$1, %edx
	lock xaddb	%dl, __ZL17s_lfPoolAllocator+168
	movl	__ZL17s_lfPoolAllocator+164, %eax
	sall	$24, %edx
	orl	%ecx, %edx
	movl	%eax, 16(%esp)
	leal	__ZL17s_lfPoolAllocator(,%ecx,8), %ecx
	.p2align 4,,7
L251:
	movl	%eax, (%ecx)
	mfence
	movl	16(%esp), %eax
	lock cmpxchgl	%edx, __ZL17s_lfPoolAllocator+164
	movl	%eax, 16(%esp)
	jne	L251
	lock subb	$1, (%ebx)
	movl	$1, %eax
	addl	$40, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L253:
	.cfi_restore_state
	movl	$LC0, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$555, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L254:
	movl	$LC2, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$561, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
	.cfi_endproc
LFE3141:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbO6data_tEZ8easyTestvEUlS1_E12_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbO6data_tEZ8easyTestvEUlS1_E12_E9_M_invokeERKSt9_Any_dataS1_:
LFB3171:
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
	subl	$64, %esp
	.cfi_def_cfa_offset 84
	movl	__ZL9s_lfQueue+320, %eax
	cmpl	$19, %eax
	ja	L278
	movl	$1, %eax
	lock xaddl	%eax, __ZL9s_lfQueue+320
	cmpl	$19, %eax
	jbe	L279
	cmpl	$20, %eax
	jne	L280
	.p2align 4,,7
L278:
	movl	__ZL9s_lfQueue+324, %eax
	cmpl	$-1, %eax
	movl	%eax, 36(%esp)
	je	L262
L282:
	andl	$16777215, %eax
	cmpl	$19, %eax
	movl	%eax, %edx
	ja	L278
	sall	$4, %eax
	leal	__ZL9s_lfQueue(%eax), %ecx
	movl	__ZL9s_lfQueue(%eax), %ebx
	movl	36(%esp), %eax
	leal	36(%esp), %esi
	lock cmpxchgl	%ebx, __ZL9s_lfQueue+324
	movl	%eax, 36(%esp)
	je	L281
	movl	36(%esp), %eax
	cmpl	$-1, %eax
	jne	L282
L262:
	addl	$64, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	xorl	%ebp, %ebp
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	movl	%ebp, %eax
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
L281:
	.cfi_restore_state
	movl	$-16843010, (%ecx)
	addl	$320, %edx
	mfence
	lock subb	$1, __ZL9s_lfQueue+9(%edx)
	movl	%ecx, %edi
L259:
	movl	88(%esp), %eax
	movl	$1, %ebp
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%edx, 12(%edi)
	movl	%eax, 8(%edi)
	lock xaddl	%ebp, __ZL9s_lfQueue+368
	movl	%edi, %eax
	cltd
	xorl	%eax, %eax
	orl	%edx, %ebp
	xorl	%edx, %edx
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
	fildq	12(%esp)
	movl	%ebp, (%esp)
	fistpq	(%ecx)
	mfence
	movl	$0, 20(%esp)
	movl	$0, 24(%esp)
L269:
	fildq	__ZL9s_lfQueue+360
	fistpq	12(%esp)
	movl	12(%esp), %eax
	movl	16(%esp), %edx
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	fildq	(%eax)
	fistpq	12(%esp)
	movl	16(%esp), %ebx
	movl	12(%esp), %ecx
	movl	%ebx, %eax
	orl	%ecx, %eax
	movl	%ecx, 4(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 36(%esp)
	movl	%ebx, 40(%esp)
	jne	L266
	fildq	__ZL9s_lfQueue+360
	movl	%edi, %ebx
	fistpq	12(%esp)
	movl	12(%esp), %eax
	movl	4(%esi), %edx
	movl	(%esp), %ecx
	movl	%eax, %ebp
	movl	(%esi), %eax
	lock cmpxchg8b	0(%ebp)
	sete	%cl
	testb	%cl, %cl
	movl	%ecx, %ebp
	movl	%eax, (%esi)
	movl	%edx, 4(%esi)
	je	L269
	movl	24(%esp), %edx
	movl	%edi, %ebx
	movl	20(%esp), %eax
	movl	(%esp), %ecx
	lock cmpxchg8b	__ZL9s_lfQueue+360
	addl	$64, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	%ebp, %eax
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
	.p2align 4,,7
L266:
	.cfi_restore_state
	movl	24(%esp), %edx
	movl	20(%esp), %eax
	movl	4(%esp), %ebx
	movl	8(%esp), %ecx
	lock cmpxchg8b	__ZL9s_lfQueue+360
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	jmp	L269
L280:
	movl	$20, __ZL9s_lfQueue+320
	mfence
	jmp	L278
L279:
	leal	320(%eax), %edx
	lock addb	$1, __ZL9s_lfQueue+9(%edx)
	sall	$4, %eax
	leal	__ZL9s_lfQueue(%eax), %edi
	movl	%edi, %ecx
	leal	36(%esp), %esi
	jmp	L259
	.cfi_endproc
LFE3171:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFP6data_tvEZ11thread_testvEUlvE4_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFP6data_tvEZ11thread_testvEUlvE4_E9_M_invokeERKSt9_Any_data:
LFB3274:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	__ZL17s_lfPoolAllocator+160, %eax
	cmpl	$19, %eax
	ja	L300
	movl	$1, %eax
	lock xaddl	%eax, __ZL17s_lfPoolAllocator+160
	cmpl	$19, %eax
	jbe	L301
	cmpl	$20, %eax
	jne	L302
	.p2align 4,,7
L300:
	movl	__ZL17s_lfPoolAllocator+164, %eax
	cmpl	$-1, %eax
	movl	%eax, (%esp)
	je	L290
L304:
	andl	$16777215, %eax
	cmpl	$19, %eax
	movl	%eax, %edx
	ja	L300
	leal	__ZL17s_lfPoolAllocator(,%eax,8), %ebx
	movl	__ZL17s_lfPoolAllocator(,%eax,8), %ecx
	movl	(%esp), %eax
	lock cmpxchgl	%ecx, __ZL17s_lfPoolAllocator+164
	movl	%eax, (%esp)
	je	L303
	movl	(%esp), %eax
	cmpl	$-1, %eax
	jne	L304
L290:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L303:
	.cfi_restore_state
	movl	$-16843010, (%ebx)
	addl	$160, %edx
	mfence
	lock subb	$1, __ZL17s_lfPoolAllocator+9(%edx)
	movl	%ebx, %eax
L287:
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L302:
	.cfi_restore_state
	movl	$20, __ZL17s_lfPoolAllocator+160
	mfence
	jmp	L300
L301:
	leal	160(%eax), %edx
	lock addb	$1, __ZL17s_lfPoolAllocator+9(%edx)
	leal	__ZL17s_lfPoolAllocator(,%eax,8), %eax
	jmp	L287
	.cfi_endproc
LFE3274:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFP6data_tvEZ8easyTestvEUlvE2_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFP6data_tvEZ8easyTestvEUlvE2_E9_M_invokeERKSt9_Any_data:
LFB3127:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3127
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL15s_poolAllocator+172, (%esp)
LEHB0:
	call	_pthread_mutex_lock
LEHE0:
	testl	%eax, %eax
	jne	L313
	movl	__ZL15s_poolAllocator+160, %ecx
	cmpl	$19, %ecx
	jbe	L314
	movl	__ZL15s_poolAllocator+164, %ecx
	cmpl	$-1, %ecx
	je	L309
	movl	__ZL15s_poolAllocator(,%ecx,8), %eax
	leal	__ZL15s_poolAllocator(,%ecx,8), %ebx
	movl	%eax, __ZL15s_poolAllocator+164
	movl	$1, %eax
	movl	$-16843010, __ZL15s_poolAllocator(,%ecx,8)
	sall	%cl, %eax
	orl	%eax, __ZL15s_poolAllocator+168
L308:
	movl	$__ZL15s_poolAllocator+172, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, %eax
	movl	$0, (%ebx)
	movl	$0, 4(%ebx)
L311:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L314:
	.cfi_restore_state
	leal	1(%ecx), %eax
	movl	%eax, __ZL15s_poolAllocator+160
	movl	$1, %eax
	sall	%cl, %eax
	leal	__ZL15s_poolAllocator(,%ecx,8), %ebx
	orl	%eax, __ZL15s_poolAllocator+168
	jmp	L308
	.p2align 4,,7
L309:
	movl	$__ZL15s_poolAllocator+172, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L311
L313:
	movl	%eax, (%esp)
LEHB1:
	call	__ZSt20__throw_system_errori
LEHE1:
	.cfi_endproc
LFE3127:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA3127:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3127-LLSDACSB3127
LLSDACSB3127:
	.uleb128 LEHB0-LFB3127
	.uleb128 LEHE0-LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB1-LFB3127
	.uleb128 LEHE1-LEHB1
	.uleb128 0
	.uleb128 0
LLSDACSE3127:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFP6data_tvEZ11thread_testvEUlvE2_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFP6data_tvEZ11thread_testvEUlvE2_E9_M_invokeERKSt9_Any_data:
LFB3266:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3266
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL15s_poolAllocator+172, (%esp)
LEHB2:
	call	_pthread_mutex_lock
LEHE2:
	testl	%eax, %eax
	jne	L323
	movl	__ZL15s_poolAllocator+160, %ecx
	cmpl	$19, %ecx
	jbe	L324
	movl	__ZL15s_poolAllocator+164, %ecx
	cmpl	$-1, %ecx
	je	L319
	movl	__ZL15s_poolAllocator(,%ecx,8), %eax
	leal	__ZL15s_poolAllocator(,%ecx,8), %ebx
	movl	%eax, __ZL15s_poolAllocator+164
	movl	$1, %eax
	movl	$-16843010, __ZL15s_poolAllocator(,%ecx,8)
	sall	%cl, %eax
	orl	%eax, __ZL15s_poolAllocator+168
L318:
	movl	$__ZL15s_poolAllocator+172, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, %eax
	movl	$0, (%ebx)
	movl	$0, 4(%ebx)
L321:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L324:
	.cfi_restore_state
	leal	1(%ecx), %eax
	movl	%eax, __ZL15s_poolAllocator+160
	movl	$1, %eax
	sall	%cl, %eax
	leal	__ZL15s_poolAllocator(,%ecx,8), %ebx
	orl	%eax, __ZL15s_poolAllocator+168
	jmp	L318
	.p2align 4,,7
L319:
	movl	$__ZL15s_poolAllocator+172, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L321
L323:
	movl	%eax, (%esp)
LEHB3:
	call	__ZSt20__throw_system_errori
LEHE3:
	.cfi_endproc
LFE3266:
	.section	.gcc_except_table,"w"
LLSDA3266:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3266-LLSDACSB3266
LLSDACSB3266:
	.uleb128 LEHB2-LFB3266
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB3-LFB3266
	.uleb128 LEHE3-LEHB3
	.uleb128 0
	.uleb128 0
LLSDACSE3266:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbP6data_tEZ8easyTestvEUlS1_E3_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbP6data_tEZ8easyTestvEUlS1_E3_E9_M_invokeERKSt9_Any_dataS1_:
LFB3132:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3132
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL15s_poolAllocator+172, (%esp)
LEHB4:
	call	_pthread_mutex_lock
LEHE4:
	testl	%eax, %eax
	jne	L333
	movl	36(%esp), %ecx
	subl	$__ZL15s_poolAllocator, %ecx
	shrl	$3, %ecx
	cmpl	$19, %ecx
	ja	L334
	movl	__ZL15s_poolAllocator+168, %edx
	movl	$1, %eax
	sall	%cl, %eax
	testl	%edx, %eax
	je	L335
	movl	__ZL15s_poolAllocator+164, %ebx
	notl	%eax
	andl	%edx, %eax
	movl	$__ZL15s_poolAllocator+172, (%esp)
	movl	%ebx, __ZL15s_poolAllocator(,%ecx,8)
	movl	%ecx, __ZL15s_poolAllocator+164
	movl	%eax, __ZL15s_poolAllocator+168
	call	_pthread_mutex_unlock
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	movl	$1, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L333:
	.cfi_restore_state
	movl	%eax, (%esp)
LEHB5:
	call	__ZSt20__throw_system_errori
LEHE5:
L335:
	movl	$LC2, 12(%esp)
	movl	$__ZZN14pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$287, 4(%esp)
	movl	$LC1, (%esp)
LEHB6:
	call	___assert_func
LEHE6:
L330:
	movl	%eax, %ebx
	movl	$__ZL15s_poolAllocator+172, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, (%esp)
LEHB7:
	call	__Unwind_Resume
LEHE7:
L334:
	movl	$LC0, 12(%esp)
	movl	$__ZZN14pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$281, 4(%esp)
	movl	$LC1, (%esp)
LEHB8:
	call	___assert_func
LEHE8:
	.cfi_endproc
LFE3132:
	.section	.gcc_except_table,"w"
LLSDA3132:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3132-LLSDACSB3132
LLSDACSB3132:
	.uleb128 LEHB4-LFB3132
	.uleb128 LEHE4-LEHB4
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB5-LFB3132
	.uleb128 LEHE5-LEHB5
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB6-LFB3132
	.uleb128 LEHE6-LEHB6
	.uleb128 L330-LFB3132
	.uleb128 0
	.uleb128 LEHB7-LFB3132
	.uleb128 LEHE7-LEHB7
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB8-LFB3132
	.uleb128 LEHE8-LEHB8
	.uleb128 L330-LFB3132
	.uleb128 0
LLSDACSE3132:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E10_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E10_E9_M_invokeERKSt9_Any_dataS1_:
LFB3298:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3298
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_queue+252, (%esp)
LEHB9:
	call	_pthread_mutex_lock
LEHE9:
	testl	%eax, %eax
	jne	L342
	movl	__ZL7s_queue+240, %ecx
	cmpl	$19, %ecx
	jbe	L347
	movl	__ZL7s_queue+244, %ecx
	cmpl	$-1, %ecx
	je	L340
	leal	(%ecx,%ecx,2), %eax
	sall	$2, %eax
	movl	__ZL7s_queue(%eax), %edx
	leal	__ZL7s_queue(%eax), %ebx
	movl	%edx, __ZL7s_queue+244
	movl	$1, %edx
	movl	$-16843010, __ZL7s_queue(%eax)
	sall	%cl, %edx
	orl	%edx, __ZL7s_queue+248
L339:
	movl	$__ZL7s_queue+252, (%esp)
	call	_pthread_mutex_unlock
	movl	36(%esp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	$__ZL7s_queue+264, (%esp)
	movl	$0, (%ebx)
	movl	%edx, 8(%ebx)
	movl	%eax, 4(%ebx)
LEHB10:
	call	_pthread_mutex_lock
LEHE10:
	testl	%eax, %eax
	jne	L342
	movl	__ZL7s_queue+260, %eax
	movl	%ebx, (%eax)
	movl	$__ZL7s_queue+264, (%esp)
	movl	%ebx, __ZL7s_queue+260
	call	_pthread_mutex_unlock
	movl	$1, %eax
L344:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L347:
	.cfi_restore_state
	leal	1(%ecx), %eax
	movl	%eax, __ZL7s_queue+240
	movl	$1, %eax
	sall	%cl, %eax
	orl	%eax, __ZL7s_queue+248
	leal	(%ecx,%ecx,2), %eax
	leal	__ZL7s_queue(,%eax,4), %ebx
	jmp	L339
	.p2align 4,,7
L340:
	movl	$__ZL7s_queue+252, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L344
L342:
	movl	%eax, (%esp)
LEHB11:
	call	__ZSt20__throw_system_errori
LEHE11:
	.cfi_endproc
LFE3298:
	.section	.gcc_except_table,"w"
LLSDA3298:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3298-LLSDACSB3298
LLSDACSB3298:
	.uleb128 LEHB9-LFB3298
	.uleb128 LEHE9-LEHB9
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB10-LFB3298
	.uleb128 LEHE10-LEHB10
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB11-LFB3298
	.uleb128 LEHE11-LEHB11
	.uleb128 0
	.uleb128 0
LLSDACSE3298:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbO6data_tEZ8easyTestvEUlS1_E6_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbO6data_tEZ8easyTestvEUlS1_E6_E9_M_invokeERKSt9_Any_dataS1_:
LFB3145:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3145
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_stack+252, (%esp)
LEHB12:
	call	_pthread_mutex_lock
LEHE12:
	testl	%eax, %eax
	jne	L354
	movl	__ZL7s_stack+240, %ecx
	cmpl	$19, %ecx
	jbe	L359
	movl	__ZL7s_stack+244, %ecx
	cmpl	$-1, %ecx
	je	L352
	leal	(%ecx,%ecx,2), %eax
	sall	$2, %eax
	movl	__ZL7s_stack(%eax), %edx
	leal	__ZL7s_stack(%eax), %ebx
	movl	%edx, __ZL7s_stack+244
	movl	$1, %edx
	movl	$-16843010, __ZL7s_stack(%eax)
	sall	%cl, %edx
	orl	%edx, __ZL7s_stack+248
L351:
	movl	$__ZL7s_stack+252, (%esp)
	call	_pthread_mutex_unlock
	movl	36(%esp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	$__ZL7s_stack+260, (%esp)
	movl	%edx, 8(%ebx)
	movl	%eax, 4(%ebx)
LEHB13:
	call	_pthread_mutex_lock
LEHE13:
	testl	%eax, %eax
	jne	L354
	movl	__ZL7s_stack+256, %eax
	movl	$__ZL7s_stack+260, (%esp)
	movl	%eax, (%ebx)
	movl	%ebx, __ZL7s_stack+256
	call	_pthread_mutex_unlock
	movl	$1, %eax
L356:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L359:
	.cfi_restore_state
	leal	1(%ecx), %eax
	movl	%eax, __ZL7s_stack+240
	movl	$1, %eax
	sall	%cl, %eax
	orl	%eax, __ZL7s_stack+248
	leal	(%ecx,%ecx,2), %eax
	leal	__ZL7s_stack(,%eax,4), %ebx
	jmp	L351
	.p2align 4,,7
L352:
	movl	$__ZL7s_stack+252, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L356
L354:
	movl	%eax, (%esp)
LEHB14:
	call	__ZSt20__throw_system_errori
LEHE14:
	.cfi_endproc
LFE3145:
	.section	.gcc_except_table,"w"
LLSDA3145:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3145-LLSDACSB3145
LLSDACSB3145:
	.uleb128 LEHB12-LFB3145
	.uleb128 LEHE12-LEHB12
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB13-LFB3145
	.uleb128 LEHE13-LEHB13
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB14-LFB3145
	.uleb128 LEHE14-LEHB14
	.uleb128 0
	.uleb128 0
LLSDACSE3145:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbO6data_tEZ8easyTestvEUlS1_E10_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbO6data_tEZ8easyTestvEUlS1_E10_E9_M_invokeERKSt9_Any_dataS1_:
LFB3163:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3163
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_queue+252, (%esp)
LEHB15:
	call	_pthread_mutex_lock
LEHE15:
	testl	%eax, %eax
	jne	L366
	movl	__ZL7s_queue+240, %ecx
	cmpl	$19, %ecx
	jbe	L371
	movl	__ZL7s_queue+244, %ecx
	cmpl	$-1, %ecx
	je	L364
	leal	(%ecx,%ecx,2), %eax
	sall	$2, %eax
	movl	__ZL7s_queue(%eax), %edx
	leal	__ZL7s_queue(%eax), %ebx
	movl	%edx, __ZL7s_queue+244
	movl	$1, %edx
	movl	$-16843010, __ZL7s_queue(%eax)
	sall	%cl, %edx
	orl	%edx, __ZL7s_queue+248
L363:
	movl	$__ZL7s_queue+252, (%esp)
	call	_pthread_mutex_unlock
	movl	36(%esp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	$__ZL7s_queue+264, (%esp)
	movl	$0, (%ebx)
	movl	%edx, 8(%ebx)
	movl	%eax, 4(%ebx)
LEHB16:
	call	_pthread_mutex_lock
LEHE16:
	testl	%eax, %eax
	jne	L366
	movl	__ZL7s_queue+260, %eax
	movl	%ebx, (%eax)
	movl	$__ZL7s_queue+264, (%esp)
	movl	%ebx, __ZL7s_queue+260
	call	_pthread_mutex_unlock
	movl	$1, %eax
L368:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L371:
	.cfi_restore_state
	leal	1(%ecx), %eax
	movl	%eax, __ZL7s_queue+240
	movl	$1, %eax
	sall	%cl, %eax
	orl	%eax, __ZL7s_queue+248
	leal	(%ecx,%ecx,2), %eax
	leal	__ZL7s_queue(,%eax,4), %ebx
	jmp	L363
	.p2align 4,,7
L364:
	movl	$__ZL7s_queue+252, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L368
L366:
	movl	%eax, (%esp)
LEHB17:
	call	__ZSt20__throw_system_errori
LEHE17:
	.cfi_endproc
LFE3163:
	.section	.gcc_except_table,"w"
LLSDA3163:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3163-LLSDACSB3163
LLSDACSB3163:
	.uleb128 LEHB15-LFB3163
	.uleb128 LEHE15-LEHB15
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB16-LFB3163
	.uleb128 LEHE16-LEHB16
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB17-LFB3163
	.uleb128 LEHE17-LEHB17
	.uleb128 0
	.uleb128 0
LLSDACSE3163:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E11_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E11_E9_M_invokeERKSt9_Any_dataS1_:
LFB3302:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3302
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_queue+264, (%esp)
LEHB18:
	call	_pthread_mutex_lock
LEHE18:
	testl	%eax, %eax
	jne	L385
	movl	__ZL7s_queue+256, %esi
	cmpl	__ZL7s_queue+260, %esi
	je	L380
	movl	(%esi), %ebx
	movl	$__ZL7s_queue+252, (%esp)
LEHB19:
	call	_pthread_mutex_lock
LEHE19:
	testl	%eax, %eax
	jne	L386
	subl	$__ZL7s_queue, %esi
	movl	$-1431655765, %ecx
	movl	%esi, %eax
	mull	%ecx
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L387
	movl	__ZL7s_queue+248, %esi
	movl	$1, %eax
	movl	%edx, %ecx
	sall	%cl, %eax
	testl	%esi, %eax
	je	L388
	movl	__ZL7s_queue+244, %edi
	notl	%eax
	leal	(%edx,%edx,2), %ecx
	andl	%esi, %eax
	movl	$__ZL7s_queue+252, (%esp)
	movl	%edi, __ZL7s_queue(,%ecx,4)
	movl	%edx, __ZL7s_queue+244
	movl	%eax, __ZL7s_queue+248
	call	_pthread_mutex_unlock
	movl	4(%ebx), %eax
	movl	8(%ebx), %edx
	movl	36(%esp), %ecx
	movl	%ebx, __ZL7s_queue+256
	movl	$1, %ebx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
L374:
	movl	$__ZL7s_queue+264, (%esp)
	call	_pthread_mutex_unlock
	addl	$16, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%ebx, %eax
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
	.p2align 4,,7
L380:
	.cfi_restore_state
	xorl	%ebx, %ebx
	jmp	L374
L386:
	movl	%eax, (%esp)
LEHB20:
	call	__ZSt20__throw_system_errori
LEHE20:
L381:
	movl	%eax, %ebx
L379:
	movl	$__ZL7s_queue+264, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, (%esp)
LEHB21:
	call	__Unwind_Resume
L385:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE21:
L388:
	movl	$LC2, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$287, 4(%esp)
	movl	$LC1, (%esp)
LEHB22:
	call	___assert_func
LEHE22:
L382:
	movl	$__ZL7s_queue+252, (%esp)
	movl	%eax, %ebx
	call	_pthread_mutex_unlock
	jmp	L379
L387:
	movl	$LC0, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$281, 4(%esp)
	movl	$LC1, (%esp)
LEHB23:
	call	___assert_func
LEHE23:
	.cfi_endproc
LFE3302:
	.section	.gcc_except_table,"w"
LLSDA3302:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3302-LLSDACSB3302
LLSDACSB3302:
	.uleb128 LEHB18-LFB3302
	.uleb128 LEHE18-LEHB18
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB19-LFB3302
	.uleb128 LEHE19-LEHB19
	.uleb128 L381-LFB3302
	.uleb128 0
	.uleb128 LEHB20-LFB3302
	.uleb128 LEHE20-LEHB20
	.uleb128 L381-LFB3302
	.uleb128 0
	.uleb128 LEHB21-LFB3302
	.uleb128 LEHE21-LEHB21
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB22-LFB3302
	.uleb128 LEHE22-LEHB22
	.uleb128 L382-LFB3302
	.uleb128 0
	.uleb128 LEHB23-LFB3302
	.uleb128 LEHE23-LEHB23
	.uleb128 L382-LFB3302
	.uleb128 0
LLSDACSE3302:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbR6data_tEZ8easyTestvEUlS1_E11_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbR6data_tEZ8easyTestvEUlS1_E11_E9_M_invokeERKSt9_Any_dataS1_:
LFB3167:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3167
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_queue+264, (%esp)
LEHB24:
	call	_pthread_mutex_lock
LEHE24:
	testl	%eax, %eax
	jne	L402
	movl	__ZL7s_queue+256, %esi
	cmpl	__ZL7s_queue+260, %esi
	je	L397
	movl	(%esi), %ebx
	movl	$__ZL7s_queue+252, (%esp)
LEHB25:
	call	_pthread_mutex_lock
LEHE25:
	testl	%eax, %eax
	jne	L403
	subl	$__ZL7s_queue, %esi
	movl	$-1431655765, %ecx
	movl	%esi, %eax
	mull	%ecx
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L404
	movl	__ZL7s_queue+248, %esi
	movl	$1, %eax
	movl	%edx, %ecx
	sall	%cl, %eax
	testl	%esi, %eax
	je	L405
	movl	__ZL7s_queue+244, %edi
	notl	%eax
	leal	(%edx,%edx,2), %ecx
	andl	%esi, %eax
	movl	$__ZL7s_queue+252, (%esp)
	movl	%edi, __ZL7s_queue(,%ecx,4)
	movl	%edx, __ZL7s_queue+244
	movl	%eax, __ZL7s_queue+248
	call	_pthread_mutex_unlock
	movl	4(%ebx), %eax
	movl	8(%ebx), %edx
	movl	36(%esp), %ecx
	movl	%ebx, __ZL7s_queue+256
	movl	$1, %ebx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
L391:
	movl	$__ZL7s_queue+264, (%esp)
	call	_pthread_mutex_unlock
	addl	$16, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%ebx, %eax
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
	.p2align 4,,7
L397:
	.cfi_restore_state
	xorl	%ebx, %ebx
	jmp	L391
L403:
	movl	%eax, (%esp)
LEHB26:
	call	__ZSt20__throw_system_errori
LEHE26:
L398:
	movl	%eax, %ebx
L396:
	movl	$__ZL7s_queue+264, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, (%esp)
LEHB27:
	call	__Unwind_Resume
L402:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE27:
L405:
	movl	$LC2, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$287, 4(%esp)
	movl	$LC1, (%esp)
LEHB28:
	call	___assert_func
LEHE28:
L399:
	movl	$__ZL7s_queue+252, (%esp)
	movl	%eax, %ebx
	call	_pthread_mutex_unlock
	jmp	L396
L404:
	movl	$LC0, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$281, 4(%esp)
	movl	$LC1, (%esp)
LEHB29:
	call	___assert_func
LEHE29:
	.cfi_endproc
LFE3167:
	.section	.gcc_except_table,"w"
LLSDA3167:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3167-LLSDACSB3167
LLSDACSB3167:
	.uleb128 LEHB24-LFB3167
	.uleb128 LEHE24-LEHB24
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB25-LFB3167
	.uleb128 LEHE25-LEHB25
	.uleb128 L398-LFB3167
	.uleb128 0
	.uleb128 LEHB26-LFB3167
	.uleb128 LEHE26-LEHB26
	.uleb128 L398-LFB3167
	.uleb128 0
	.uleb128 LEHB27-LFB3167
	.uleb128 LEHE27-LEHB27
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB28-LFB3167
	.uleb128 LEHE28-LEHB28
	.uleb128 L399-LFB3167
	.uleb128 0
	.uleb128 LEHB29-LFB3167
	.uleb128 LEHE29-LEHB29
	.uleb128 L399-LFB3167
	.uleb128 0
LLSDACSE3167:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbP6data_tEZ11thread_testvEUlS1_E3_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbP6data_tEZ11thread_testvEUlS1_E3_E9_M_invokeERKSt9_Any_dataS1_:
LFB3270:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3270
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL15s_poolAllocator+172, (%esp)
LEHB30:
	call	_pthread_mutex_lock
LEHE30:
	testl	%eax, %eax
	jne	L414
	movl	36(%esp), %ecx
	subl	$__ZL15s_poolAllocator, %ecx
	shrl	$3, %ecx
	cmpl	$19, %ecx
	ja	L415
	movl	__ZL15s_poolAllocator+168, %edx
	movl	$1, %eax
	sall	%cl, %eax
	testl	%edx, %eax
	je	L416
	movl	__ZL15s_poolAllocator+164, %ebx
	notl	%eax
	andl	%edx, %eax
	movl	$__ZL15s_poolAllocator+172, (%esp)
	movl	%ebx, __ZL15s_poolAllocator(,%ecx,8)
	movl	%ecx, __ZL15s_poolAllocator+164
	movl	%eax, __ZL15s_poolAllocator+168
	call	_pthread_mutex_unlock
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	movl	$1, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L414:
	.cfi_restore_state
	movl	%eax, (%esp)
LEHB31:
	call	__ZSt20__throw_system_errori
LEHE31:
L416:
	movl	$LC2, 12(%esp)
	movl	$__ZZN14pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$287, 4(%esp)
	movl	$LC1, (%esp)
LEHB32:
	call	___assert_func
LEHE32:
L411:
	movl	%eax, %ebx
	movl	$__ZL15s_poolAllocator+172, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, (%esp)
LEHB33:
	call	__Unwind_Resume
LEHE33:
L415:
	movl	$LC0, 12(%esp)
	movl	$__ZZN14pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$281, 4(%esp)
	movl	$LC1, (%esp)
LEHB34:
	call	___assert_func
LEHE34:
	.cfi_endproc
LFE3270:
	.section	.gcc_except_table,"w"
LLSDA3270:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3270-LLSDACSB3270
LLSDACSB3270:
	.uleb128 LEHB30-LFB3270
	.uleb128 LEHE30-LEHB30
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB31-LFB3270
	.uleb128 LEHE31-LEHB31
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB32-LFB3270
	.uleb128 LEHE32-LEHB32
	.uleb128 L411-LFB3270
	.uleb128 0
	.uleb128 LEHB33-LFB3270
	.uleb128 LEHE33-LEHB33
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB34-LFB3270
	.uleb128 LEHE34-LEHB34
	.uleb128 L411-LFB3270
	.uleb128 0
LLSDACSE3270:
	.text
	.p2align 4,,15
	.def	__Z41__static_initialization_and_destruction_0ii.part.314;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii.part.314:
LFB4293:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4293
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
	.p2align 4,,7
L426:
	movl	$0, 48(%esp)
	movl	$0, 52(%esp)
	movl	$0, 64(%esp)
	movl	$0, 68(%esp)
L418:
	fildq	__ZL9s_lfQueue+352
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	fildq	__ZL9s_lfQueue+360
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	48(%esp), %esi
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	fildq	(%esi)
	movl	64(%esp), %edx
	fistpq	24(%esp)
	movl	52(%esp), %eax
	xorl	68(%esp), %eax
	movl	24(%esp), %edi
	xorl	%esi, %edx
	movl	28(%esp), %ebp
	orl	%edx, %eax
	jne	L419
	movl	%ebp, %eax
	orl	%edi, %eax
	je	L420
	movl	64(%esp), %eax
	movl	%edi, %ebx
	movl	%ebp, %ecx
	movl	68(%esp), %edx
	lock cmpxchg8b	__ZL9s_lfQueue+360
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	jmp	L418
	.p2align 4,,7
L419:
	movl	48(%esp), %eax
	movl	%edi, %ebx
	movl	%ebp, %ecx
	movl	52(%esp), %edx
	lock cmpxchg8b	__ZL9s_lfQueue+352
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	jne	L418
	subl	$__ZL9s_lfQueue, %esi
	movl	%esi, %ecx
	shrl	$4, %ecx
	cmpl	$19, %ecx
	ja	L459
	movzbl	__ZL9s_lfQueue+329(%ecx), %eax
	leal	__ZL9s_lfQueue+329(%ecx), %ebx
	testb	%al, %al
	je	L427
	movl	$1, %edx
	lock xaddb	%dl, __ZL9s_lfQueue+328
	movl	__ZL9s_lfQueue+324, %eax
	sall	$24, %edx
	orl	%ecx, %edx
	sall	$4, %ecx
	movl	%eax, 32(%esp)
	addl	$__ZL9s_lfQueue, %ecx
	.p2align 4,,7
L425:
	movl	%eax, (%ecx)
	mfence
	movl	32(%esp), %eax
	lock cmpxchgl	%edx, __ZL9s_lfQueue+324
	movl	%eax, 32(%esp)
	jne	L425
	lock subb	$1, (%ebx)
	jmp	L426
L420:
	fildq	__ZL9s_lfQueue+352
	fistpq	24(%esp)
	movl	24(%esp), %eax
	subl	$__ZL9s_lfQueue, %eax
	shrl	$4, %eax
	cmpl	$19, %eax
	ja	L459
	movzbl	__ZL9s_lfQueue+329(%eax), %edx
	leal	__ZL9s_lfQueue+329(%eax), %esi
	testb	%dl, %dl
	je	L427
	movl	$1, %ecx
	lock xaddb	%cl, __ZL9s_lfQueue+328
	movl	__ZL9s_lfQueue+324, %edx
	sall	$24, %ecx
	orl	%eax, %ecx
	sall	$4, %eax
	movl	%edx, 64(%esp)
	leal	__ZL9s_lfQueue(%eax), %ebx
	jmp	L429
	.p2align 4,,7
L479:
	movl	%eax, %edx
L429:
	movl	%edx, (%ebx)
	mfence
	movl	64(%esp), %eax
	lock cmpxchgl	%ecx, __ZL9s_lfQueue+324
	movl	%eax, 64(%esp)
	jne	L479
	lock subb	$1, (%esi)
	movl	$1, %edi
	jmp	L435
	.p2align 4,,7
L483:
	movl	0(%ebp), %ebx
	movl	$__ZL7s_queue+252, (%esp)
LEHB35:
	call	_pthread_mutex_lock
LEHE35:
	testl	%eax, %eax
	jne	L480
	subl	$__ZL7s_queue, %ebp
	movl	$-1431655765, %esi
	movl	%ebp, %eax
	mull	%esi
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L481
	movl	__ZL7s_queue+248, %eax
	movl	%edx, %ecx
	movl	%edi, %ebp
	sall	%cl, %ebp
	movl	%ebp, %ecx
	testl	%eax, %ebp
	je	L482
	movl	__ZL7s_queue+244, %esi
	notl	%ecx
	leal	(%edx,%edx,2), %ebp
	andl	%eax, %ecx
	movl	$__ZL7s_queue+252, (%esp)
	movl	%esi, __ZL7s_queue(,%ebp,4)
	movl	%edx, __ZL7s_queue+244
	movl	%ecx, __ZL7s_queue+248
	call	_pthread_mutex_unlock
	movl	$__ZL7s_queue+264, (%esp)
	movl	%ebx, __ZL7s_queue+256
	call	_pthread_mutex_unlock
L435:
	movl	$__ZL7s_queue+264, (%esp)
	call	_pthread_mutex_lock
	testl	%eax, %eax
	jne	L461
	movl	__ZL7s_queue+256, %ebp
	cmpl	__ZL7s_queue+260, %ebp
	jne	L483
	movl	$__ZL7s_queue+264, (%esp)
	call	_pthread_mutex_unlock
	movl	__ZL7s_queue+256, %ebx
	movl	$__ZL7s_queue+252, (%esp)
	call	_pthread_mutex_lock
	testl	%eax, %eax
	jne	L461
	subl	$__ZL7s_queue, %ebx
	movl	$-1431655765, %ecx
	movl	%ebx, %eax
	mull	%ecx
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L484
	movl	__ZL7s_queue+248, %ebx
	movl	$1, %eax
	movl	%edx, %ecx
	sall	%cl, %eax
	testl	%ebx, %eax
	je	L485
	movl	__ZL7s_queue+244, %esi
	notl	%eax
	leal	(%edx,%edx,2), %ecx
	andl	%ebx, %eax
	movl	$__ZL7s_queue+252, (%esp)
	movl	%esi, __ZL7s_queue(,%ecx,4)
	movl	%edx, __ZL7s_queue+244
	movl	%eax, __ZL7s_queue+248
	call	_pthread_mutex_unlock
	.p2align 4,,7
L440:
	fildq	__ZL9s_lfStack+352
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 64(%esp)
	movl	%eax, %esi
	movl	%edx, 68(%esp)
	movl	%edx, %eax
L443:
	orl	%esi, %eax
	je	L486
	fildq	(%esi)
	fistpq	24(%esp)
	movl	24(%esp), %edi
	movl	28(%esp), %ebp
	movl	64(%esp), %eax
	movl	68(%esp), %edx
	movl	%edi, %ebx
	movl	%ebp, %ecx
	lock cmpxchg8b	__ZL9s_lfStack+352
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	jne	L444
	subl	$__ZL9s_lfStack, %esi
	movl	%esi, %ecx
	shrl	$4, %ecx
	cmpl	$19, %ecx
	ja	L487
	movzbl	__ZL9s_lfStack+329(%ecx), %eax
	leal	__ZL9s_lfStack+329(%ecx), %ebx
	testb	%al, %al
	je	L488
	movl	$1, %edx
	lock xaddb	%dl, __ZL9s_lfStack+328
	movl	__ZL9s_lfStack+324, %eax
	sall	$24, %edx
	orl	%ecx, %edx
	sall	$4, %ecx
	movl	%eax, 48(%esp)
	addl	$__ZL9s_lfStack, %ecx
	.p2align 4,,7
L448:
	movl	%eax, (%ecx)
	mfence
	movl	48(%esp), %eax
	lock cmpxchgl	%edx, __ZL9s_lfStack+324
	movl	%eax, 48(%esp)
	jne	L448
	lock subb	$1, (%ebx)
	jmp	L440
L486:
	movl	$-1431655765, %esi
	movl	$1, %ebx
	jmp	L456
	.p2align 4,,7
L493:
	movl	(%edi), %eax
	movl	$__ZL7s_stack+252, (%esp)
	movl	%eax, __ZL7s_stack+256
LEHB36:
	call	_pthread_mutex_lock
LEHE36:
	testl	%eax, %eax
	jne	L489
	subl	$__ZL7s_stack, %edi
	movl	%edi, %eax
	mull	%esi
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L490
	movl	__ZL7s_stack+248, %edi
	movl	%ebx, %eax
	movl	%edx, %ecx
	sall	%cl, %eax
	testl	%edi, %eax
	je	L491
	movl	__ZL7s_stack+244, %ebp
	notl	%eax
	leal	(%edx,%edx,2), %ecx
	andl	%edi, %eax
	movl	$__ZL7s_stack+252, (%esp)
	movl	%ebp, __ZL7s_stack(,%ecx,4)
	movl	%edx, __ZL7s_stack+244
	movl	%eax, __ZL7s_stack+248
	call	_pthread_mutex_unlock
	movl	$__ZL7s_stack+260, (%esp)
	call	_pthread_mutex_unlock
L456:
	movl	$__ZL7s_stack+260, (%esp)
	call	_pthread_mutex_lock
	testl	%eax, %eax
	jne	L492
	movl	__ZL7s_stack+256, %edi
	testl	%edi, %edi
	jne	L493
	movl	$__ZL7s_stack+260, (%esp)
	call	_pthread_mutex_unlock
	addl	$92, %esp
	.cfi_remember_state
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
L461:
	.cfi_restore_state
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
L480:
	movl	%eax, (%esp)
LEHB37:
	call	__ZSt20__throw_system_errori
LEHE37:
L463:
L437:
	movl	$__ZL7s_queue+264, (%esp)
	call	_pthread_mutex_unlock
L478:
	call	__ZSt9terminatev
L482:
	movl	$LC2, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$287, 4(%esp)
	movl	$LC1, (%esp)
LEHB38:
	call	___assert_func
LEHE38:
L464:
	movl	$__ZL7s_queue+252, (%esp)
	call	_pthread_mutex_unlock
	jmp	L437
L444:
	movl	64(%esp), %esi
	movl	68(%esp), %eax
	jmp	L443
L481:
	movl	$LC0, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$281, 4(%esp)
	movl	$LC1, (%esp)
LEHB39:
	call	___assert_func
LEHE39:
L487:
	movl	$LC0, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$555, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L488:
	movl	$LC2, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$561, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L492:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
L489:
	movl	%eax, (%esp)
LEHB40:
	call	__ZSt20__throw_system_errori
LEHE40:
L466:
L458:
	movl	$__ZL7s_stack+260, (%esp)
	call	_pthread_mutex_unlock
	jmp	L478
L490:
	movl	$LC0, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$281, 4(%esp)
	movl	$LC1, (%esp)
LEHB41:
	call	___assert_func
LEHE41:
L467:
	movl	$__ZL7s_stack+252, (%esp)
	call	_pthread_mutex_unlock
	jmp	L458
L491:
	movl	$LC2, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$287, 4(%esp)
	movl	$LC1, (%esp)
LEHB42:
	call	___assert_func
LEHE42:
L427:
	movl	$LC2, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$561, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L459:
	movl	$LC0, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$555, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L484:
	movl	$LC0, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$281, 4(%esp)
	movl	$LC1, (%esp)
LEHB43:
	call	___assert_func
L485:
	movl	$LC2, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$287, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
LEHE43:
L465:
	movl	$__ZL7s_queue+252, (%esp)
	call	_pthread_mutex_unlock
	jmp	L478
	.cfi_endproc
LFE4293:
	.section	.gcc_except_table,"w"
LLSDA4293:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4293-LLSDACSB4293
LLSDACSB4293:
	.uleb128 LEHB35-LFB4293
	.uleb128 LEHE35-LEHB35
	.uleb128 L463-LFB4293
	.uleb128 0
	.uleb128 LEHB36-LFB4293
	.uleb128 LEHE36-LEHB36
	.uleb128 L466-LFB4293
	.uleb128 0
	.uleb128 LEHB37-LFB4293
	.uleb128 LEHE37-LEHB37
	.uleb128 L463-LFB4293
	.uleb128 0
	.uleb128 LEHB38-LFB4293
	.uleb128 LEHE38-LEHB38
	.uleb128 L464-LFB4293
	.uleb128 0
	.uleb128 LEHB39-LFB4293
	.uleb128 LEHE39-LEHB39
	.uleb128 L464-LFB4293
	.uleb128 0
	.uleb128 LEHB40-LFB4293
	.uleb128 LEHE40-LEHB40
	.uleb128 L466-LFB4293
	.uleb128 0
	.uleb128 LEHB41-LFB4293
	.uleb128 LEHE41-LEHB41
	.uleb128 L467-LFB4293
	.uleb128 0
	.uleb128 LEHB42-LFB4293
	.uleb128 LEHE42-LEHB42
	.uleb128 L467-LFB4293
	.uleb128 0
	.uleb128 LEHB43-LFB4293
	.uleb128 LEHE43-LEHB43
	.uleb128 L465-LFB4293
	.uleb128 0
LLSDACSE4293:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbP6data_tEZ11thread_testvEUlS1_E5_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbP6data_tEZ11thread_testvEUlS1_E5_E9_M_invokeERKSt9_Any_dataS1_:
LFB3278:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$40, %esp
	.cfi_def_cfa_offset 48
	movl	52(%esp), %ecx
	subl	$__ZL17s_lfPoolAllocator, %ecx
	shrl	$3, %ecx
	cmpl	$19, %ecx
	ja	L500
	movzbl	__ZL17s_lfPoolAllocator+169(%ecx), %eax
	leal	__ZL17s_lfPoolAllocator+169(%ecx), %ebx
	testb	%al, %al
	je	L501
	movl	$1, %edx
	lock xaddb	%dl, __ZL17s_lfPoolAllocator+168
	movl	__ZL17s_lfPoolAllocator+164, %eax
	sall	$24, %edx
	orl	%ecx, %edx
	movl	%eax, 16(%esp)
	leal	__ZL17s_lfPoolAllocator(,%ecx,8), %ecx
	.p2align 4,,7
L498:
	movl	%eax, (%ecx)
	mfence
	movl	16(%esp), %eax
	lock cmpxchgl	%edx, __ZL17s_lfPoolAllocator+164
	movl	%eax, 16(%esp)
	jne	L498
	lock subb	$1, (%ebx)
	movl	$1, %eax
	addl	$40, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L500:
	.cfi_restore_state
	movl	$LC0, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$555, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L501:
	movl	$LC2, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$561, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
	.cfi_endproc
LFE3278:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E6_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E6_E9_M_invokeERKSt9_Any_dataS1_:
LFB3282:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3282
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_stack+252, (%esp)
LEHB44:
	call	_pthread_mutex_lock
LEHE44:
	testl	%eax, %eax
	jne	L508
	movl	__ZL7s_stack+240, %ecx
	cmpl	$19, %ecx
	jbe	L513
	movl	__ZL7s_stack+244, %ecx
	cmpl	$-1, %ecx
	je	L506
	leal	(%ecx,%ecx,2), %eax
	sall	$2, %eax
	movl	__ZL7s_stack(%eax), %edx
	leal	__ZL7s_stack(%eax), %ebx
	movl	%edx, __ZL7s_stack+244
	movl	$1, %edx
	movl	$-16843010, __ZL7s_stack(%eax)
	sall	%cl, %edx
	orl	%edx, __ZL7s_stack+248
L505:
	movl	$__ZL7s_stack+252, (%esp)
	call	_pthread_mutex_unlock
	movl	36(%esp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	$__ZL7s_stack+260, (%esp)
	movl	%edx, 8(%ebx)
	movl	%eax, 4(%ebx)
LEHB45:
	call	_pthread_mutex_lock
LEHE45:
	testl	%eax, %eax
	jne	L508
	movl	__ZL7s_stack+256, %eax
	movl	$__ZL7s_stack+260, (%esp)
	movl	%eax, (%ebx)
	movl	%ebx, __ZL7s_stack+256
	call	_pthread_mutex_unlock
	movl	$1, %eax
L510:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L513:
	.cfi_restore_state
	leal	1(%ecx), %eax
	movl	%eax, __ZL7s_stack+240
	movl	$1, %eax
	sall	%cl, %eax
	orl	%eax, __ZL7s_stack+248
	leal	(%ecx,%ecx,2), %eax
	leal	__ZL7s_stack(,%eax,4), %ebx
	jmp	L505
	.p2align 4,,7
L506:
	movl	$__ZL7s_stack+252, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L510
L508:
	movl	%eax, (%esp)
LEHB46:
	call	__ZSt20__throw_system_errori
LEHE46:
	.cfi_endproc
LFE3282:
	.section	.gcc_except_table,"w"
LLSDA3282:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3282-LLSDACSB3282
LLSDACSB3282:
	.uleb128 LEHB44-LFB3282
	.uleb128 LEHE44-LEHB44
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB45-LFB3282
	.uleb128 LEHE45-LEHB45
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB46-LFB3282
	.uleb128 LEHE46-LEHB46
	.uleb128 0
	.uleb128 0
LLSDACSE3282:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFP6data_tvEZ8easyTestvEUlvE4_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFP6data_tvEZ8easyTestvEUlvE4_E9_M_invokeERKSt9_Any_data:
LFB3137:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	__ZL17s_lfPoolAllocator+160, %eax
	cmpl	$19, %eax
	ja	L531
	movl	$1, %eax
	lock xaddl	%eax, __ZL17s_lfPoolAllocator+160
	cmpl	$19, %eax
	jbe	L532
	cmpl	$20, %eax
	jne	L533
	.p2align 4,,7
L531:
	movl	__ZL17s_lfPoolAllocator+164, %eax
	cmpl	$-1, %eax
	movl	%eax, (%esp)
	je	L521
L535:
	andl	$16777215, %eax
	cmpl	$19, %eax
	movl	%eax, %edx
	ja	L531
	leal	__ZL17s_lfPoolAllocator(,%eax,8), %ebx
	movl	__ZL17s_lfPoolAllocator(,%eax,8), %ecx
	movl	(%esp), %eax
	lock cmpxchgl	%ecx, __ZL17s_lfPoolAllocator+164
	movl	%eax, (%esp)
	je	L534
	movl	(%esp), %eax
	cmpl	$-1, %eax
	jne	L535
L521:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L534:
	.cfi_restore_state
	movl	$-16843010, (%ebx)
	addl	$160, %edx
	mfence
	lock subb	$1, __ZL17s_lfPoolAllocator+9(%edx)
	movl	%ebx, %eax
L518:
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L533:
	.cfi_restore_state
	movl	$20, __ZL17s_lfPoolAllocator+160
	mfence
	jmp	L531
L532:
	leal	160(%eax), %edx
	lock addb	$1, __ZL17s_lfPoolAllocator+9(%edx)
	leal	__ZL17s_lfPoolAllocator(,%eax,8), %eax
	jmp	L518
	.cfi_endproc
LFE3137:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E7_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E7_E9_M_invokeERKSt9_Any_dataS1_:
LFB3286:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3286
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_stack+260, (%esp)
LEHB47:
	call	_pthread_mutex_lock
LEHE47:
	testl	%eax, %eax
	jne	L549
	movl	__ZL7s_stack+256, %ebx
	testl	%ebx, %ebx
	je	L544
	movl	(%ebx), %eax
	movl	4(%ebx), %edx
	movl	8(%ebx), %ecx
	movl	%eax, __ZL7s_stack+256
	movl	36(%esp), %eax
	movl	%edx, (%eax)
	movl	%ecx, 4(%eax)
	movl	$__ZL7s_stack+252, (%esp)
LEHB48:
	call	_pthread_mutex_lock
LEHE48:
	testl	%eax, %eax
	jne	L550
	subl	$__ZL7s_stack, %ebx
	movl	$-1431655765, %ecx
	movl	%ebx, %eax
	mull	%ecx
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L551
	movl	__ZL7s_stack+248, %ebx
	movl	$1, %eax
	movl	%edx, %ecx
	sall	%cl, %eax
	testl	%ebx, %eax
	je	L552
	movl	__ZL7s_stack+244, %esi
	notl	%eax
	andl	%ebx, %eax
	movl	$1, %ebx
	leal	(%edx,%edx,2), %ecx
	movl	$__ZL7s_stack+252, (%esp)
	movl	%esi, __ZL7s_stack(,%ecx,4)
	movl	%edx, __ZL7s_stack+244
	movl	%eax, __ZL7s_stack+248
	call	_pthread_mutex_unlock
L538:
	movl	$__ZL7s_stack+260, (%esp)
	call	_pthread_mutex_unlock
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	movl	%ebx, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L544:
	.cfi_restore_state
	xorl	%ebx, %ebx
	jmp	L538
L550:
	movl	%eax, (%esp)
LEHB49:
	call	__ZSt20__throw_system_errori
LEHE49:
L545:
	movl	%eax, %ebx
L543:
	movl	$__ZL7s_stack+260, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, (%esp)
LEHB50:
	call	__Unwind_Resume
L549:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE50:
L552:
	movl	$LC2, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$287, 4(%esp)
	movl	$LC1, (%esp)
LEHB51:
	call	___assert_func
LEHE51:
L546:
	movl	$__ZL7s_stack+252, (%esp)
	movl	%eax, %ebx
	call	_pthread_mutex_unlock
	jmp	L543
L551:
	movl	$LC0, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$281, 4(%esp)
	movl	$LC1, (%esp)
LEHB52:
	call	___assert_func
LEHE52:
	.cfi_endproc
LFE3286:
	.section	.gcc_except_table,"w"
LLSDA3286:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3286-LLSDACSB3286
LLSDACSB3286:
	.uleb128 LEHB47-LFB3286
	.uleb128 LEHE47-LEHB47
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB48-LFB3286
	.uleb128 LEHE48-LEHB48
	.uleb128 L545-LFB3286
	.uleb128 0
	.uleb128 LEHB49-LFB3286
	.uleb128 LEHE49-LEHB49
	.uleb128 L545-LFB3286
	.uleb128 0
	.uleb128 LEHB50-LFB3286
	.uleb128 LEHE50-LEHB50
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB51-LFB3286
	.uleb128 LEHE51-LEHB51
	.uleb128 L546-LFB3286
	.uleb128 0
	.uleb128 LEHB52-LFB3286
	.uleb128 LEHE52-LEHB52
	.uleb128 L546-LFB3286
	.uleb128 0
LLSDACSE3286:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbR6data_tEZ8easyTestvEUlS1_E7_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbR6data_tEZ8easyTestvEUlS1_E7_E9_M_invokeERKSt9_Any_dataS1_:
LFB3150:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3150
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_stack+260, (%esp)
LEHB53:
	call	_pthread_mutex_lock
LEHE53:
	testl	%eax, %eax
	jne	L566
	movl	__ZL7s_stack+256, %ebx
	testl	%ebx, %ebx
	je	L561
	movl	(%ebx), %eax
	movl	4(%ebx), %edx
	movl	8(%ebx), %ecx
	movl	%eax, __ZL7s_stack+256
	movl	36(%esp), %eax
	movl	%edx, (%eax)
	movl	%ecx, 4(%eax)
	movl	$__ZL7s_stack+252, (%esp)
LEHB54:
	call	_pthread_mutex_lock
LEHE54:
	testl	%eax, %eax
	jne	L567
	subl	$__ZL7s_stack, %ebx
	movl	$-1431655765, %ecx
	movl	%ebx, %eax
	mull	%ecx
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L568
	movl	__ZL7s_stack+248, %ebx
	movl	$1, %eax
	movl	%edx, %ecx
	sall	%cl, %eax
	testl	%ebx, %eax
	je	L569
	movl	__ZL7s_stack+244, %esi
	notl	%eax
	andl	%ebx, %eax
	movl	$1, %ebx
	leal	(%edx,%edx,2), %ecx
	movl	$__ZL7s_stack+252, (%esp)
	movl	%esi, __ZL7s_stack(,%ecx,4)
	movl	%edx, __ZL7s_stack+244
	movl	%eax, __ZL7s_stack+248
	call	_pthread_mutex_unlock
L555:
	movl	$__ZL7s_stack+260, (%esp)
	call	_pthread_mutex_unlock
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	movl	%ebx, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L561:
	.cfi_restore_state
	xorl	%ebx, %ebx
	jmp	L555
L567:
	movl	%eax, (%esp)
LEHB55:
	call	__ZSt20__throw_system_errori
LEHE55:
L562:
	movl	%eax, %ebx
L560:
	movl	$__ZL7s_stack+260, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, (%esp)
LEHB56:
	call	__Unwind_Resume
L566:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE56:
L569:
	movl	$LC2, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$287, 4(%esp)
	movl	$LC1, (%esp)
LEHB57:
	call	___assert_func
LEHE57:
L563:
	movl	$__ZL7s_stack+252, (%esp)
	movl	%eax, %ebx
	call	_pthread_mutex_unlock
	jmp	L560
L568:
	movl	$LC0, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$281, 4(%esp)
	movl	$LC1, (%esp)
LEHB58:
	call	___assert_func
LEHE58:
	.cfi_endproc
LFE3150:
	.section	.gcc_except_table,"w"
LLSDA3150:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3150-LLSDACSB3150
LLSDACSB3150:
	.uleb128 LEHB53-LFB3150
	.uleb128 LEHE53-LEHB53
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB54-LFB3150
	.uleb128 LEHE54-LEHB54
	.uleb128 L562-LFB3150
	.uleb128 0
	.uleb128 LEHB55-LFB3150
	.uleb128 LEHE55-LEHB55
	.uleb128 L562-LFB3150
	.uleb128 0
	.uleb128 LEHB56-LFB3150
	.uleb128 LEHE56-LEHB56
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB57-LFB3150
	.uleb128 LEHE57-LEHB57
	.uleb128 L563-LFB3150
	.uleb128 0
	.uleb128 LEHB58-LFB3150
	.uleb128 LEHE58-LEHB58
	.uleb128 L563-LFB3150
	.uleb128 0
LLSDACSE3150:
	.text
	.section	.text$_ZNSt6thread10_Impl_baseD1Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt6thread10_Impl_baseD1Ev
	.def	__ZNSt6thread10_Impl_baseD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6thread10_Impl_baseD1Ev:
LFB1988:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %eax
	movl	8(%eax), %ebx
	movl	$__ZTVNSt6thread10_Impl_baseE+8, (%eax)
	testl	%ebx, %ebx
	je	L570
	lock subl	$1, 4(%ebx)
	je	L575
L570:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L575:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L570
	movl	(%ebx), %eax
	movl	%ebx, 32(%esp)
	movl	12(%eax), %eax
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	*%eax
	.cfi_endproc
LFE1988:
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED2Ev;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED2Ev:
LFB3880:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %eax
	movl	8(%eax), %ebx
	movl	$__ZTVNSt6thread10_Impl_baseE+8, (%eax)
	testl	%ebx, %ebx
	je	L576
	lock subl	$1, 4(%ebx)
	je	L581
L576:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L581:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L576
	movl	(%ebx), %eax
	movl	%ebx, 32(%esp)
	movl	12(%eax), %eax
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	*%eax
	.cfi_endproc
LFE3880:
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED1Ev;	.scl	3;	.type	32;	.endef
	.set	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED1Ev,__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED2Ev
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED2Ev;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED2Ev:
LFB3876:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %eax
	movl	8(%eax), %ebx
	movl	$__ZTVNSt6thread10_Impl_baseE+8, (%eax)
	testl	%ebx, %ebx
	je	L582
	lock subl	$1, 4(%ebx)
	je	L587
L582:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L587:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L582
	movl	(%ebx), %eax
	movl	%ebx, 32(%esp)
	movl	12(%eax), %eax
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	*%eax
	.cfi_endproc
LFE3876:
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED1Ev;	.scl	3;	.type	32;	.endef
	.set	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED1Ev,__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED2Ev
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED2Ev;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED2Ev:
LFB3872:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %eax
	movl	8(%eax), %ebx
	movl	$__ZTVNSt6thread10_Impl_baseE+8, (%eax)
	testl	%ebx, %ebx
	je	L588
	lock subl	$1, 4(%ebx)
	je	L593
L588:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L593:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L588
	movl	(%ebx), %eax
	movl	%ebx, 32(%esp)
	movl	12(%eax), %eax
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	*%eax
	.cfi_endproc
LFE3872:
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED1Ev;	.scl	3;	.type	32;	.endef
	.set	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED1Ev,__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED2Ev
	.section	.text$_ZNSt6thread10_Impl_baseD0Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt6thread10_Impl_baseD0Ev
	.def	__ZNSt6thread10_Impl_baseD0Ev;	.scl	2;	.type	32;	.endef
__ZNSt6thread10_Impl_baseD0Ev:
LFB1989:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %esi
	movl	8(%esi), %ebx
	movl	$__ZTVNSt6thread10_Impl_baseE+8, (%esi)
	testl	%ebx, %ebx
	je	L596
	lock subl	$1, 4(%ebx)
	je	L599
L596:
	movl	%esi, 32(%esp)
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	__ZdlPv
	.p2align 4,,7
L599:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L596
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*12(%eax)
	.p2align 4,,3
	jmp	L596
	.cfi_endproc
LFE1989:
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED0Ev;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED0Ev:
LFB3882:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %esi
	movl	8(%esi), %ebx
	movl	$__ZTVNSt6thread10_Impl_baseE+8, (%esi)
	testl	%ebx, %ebx
	je	L602
	lock subl	$1, 4(%ebx)
	je	L605
L602:
	movl	%esi, 32(%esp)
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	__ZdlPv
	.p2align 4,,7
L605:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L602
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*12(%eax)
	.p2align 4,,3
	jmp	L602
	.cfi_endproc
LFE3882:
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED0Ev;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED0Ev:
LFB3878:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %esi
	movl	8(%esi), %ebx
	movl	$__ZTVNSt6thread10_Impl_baseE+8, (%esi)
	testl	%ebx, %ebx
	je	L608
	lock subl	$1, 4(%ebx)
	je	L611
L608:
	movl	%esi, 32(%esp)
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	__ZdlPv
	.p2align 4,,7
L611:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L608
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*12(%eax)
	.p2align 4,,3
	jmp	L608
	.cfi_endproc
LFE3878:
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED0Ev;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED0Ev:
LFB3874:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %esi
	movl	8(%esi), %ebx
	movl	$__ZTVNSt6thread10_Impl_baseE+8, (%esi)
	testl	%ebx, %ebx
	je	L614
	lock subl	$1, 4(%ebx)
	je	L617
L614:
	movl	%esi, 32(%esp)
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	__ZdlPv
	.p2align 4,,7
L617:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L614
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*12(%eax)
	.p2align 4,,3
	jmp	L614
	.cfi_endproc
LFE3874:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbR6data_tEZ8easyTestvEUlS1_E9_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbR6data_tEZ8easyTestvEUlS1_E9_E9_M_invokeERKSt9_Any_dataS1_:
LFB3159:
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
	subl	$76, %esp
	.cfi_def_cfa_offset 96
	fildq	__ZL9s_lfStack+352
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 48(%esp)
	movl	%eax, %esi
	movl	%edx, 52(%esp)
	movl	%edx, %eax
L619:
	orl	%esi, %eax
	je	L628
	fildq	(%esi)
	fistpq	24(%esp)
	movl	24(%esp), %edi
	movl	28(%esp), %ebp
	movl	52(%esp), %edx
	movl	48(%esp), %eax
	movl	%edi, %ebx
	movl	%ebp, %ecx
	lock cmpxchg8b	__ZL9s_lfStack+352
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	jne	L620
	movl	8(%esi), %eax
	movl	12(%esi), %edx
	subl	$__ZL9s_lfStack, %esi
	movl	100(%esp), %ecx
	shrl	$4, %esi
	cmpl	$19, %esi
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	ja	L629
	movzbl	__ZL9s_lfStack+329(%esi), %eax
	leal	__ZL9s_lfStack+329(%esi), %ebx
	testb	%al, %al
	je	L630
	movl	$1, %ecx
	lock xaddb	%cl, __ZL9s_lfStack+328
	movl	__ZL9s_lfStack+324, %eax
	sall	$24, %ecx
	orl	%esi, %ecx
	sall	$4, %esi
	movl	%eax, 32(%esp)
	addl	$__ZL9s_lfStack, %esi
	.p2align 4,,7
L624:
	movl	%eax, (%esi)
	mfence
	movl	32(%esp), %eax
	lock cmpxchgl	%ecx, __ZL9s_lfStack+324
	sete	%dl
	testb	%dl, %dl
	movl	%eax, 32(%esp)
	je	L624
	lock subb	$1, (%ebx)
L625:
	addl	$76, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	%edx, %eax
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
L628:
	.cfi_restore_state
	xorl	%edx, %edx
	jmp	L625
L630:
	movl	$LC2, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$561, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L629:
	movl	$LC0, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$555, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L620:
	movl	48(%esp), %esi
	movl	52(%esp), %eax
	jmp	L619
	.cfi_endproc
LFE3159:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E9_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E9_E9_M_invokeERKSt9_Any_dataS1_:
LFB3294:
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
	subl	$76, %esp
	.cfi_def_cfa_offset 96
	fildq	__ZL9s_lfStack+352
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 48(%esp)
	movl	%eax, %esi
	movl	%edx, 52(%esp)
	movl	%edx, %eax
L632:
	orl	%esi, %eax
	je	L641
	fildq	(%esi)
	fistpq	24(%esp)
	movl	24(%esp), %edi
	movl	28(%esp), %ebp
	movl	52(%esp), %edx
	movl	48(%esp), %eax
	movl	%edi, %ebx
	movl	%ebp, %ecx
	lock cmpxchg8b	__ZL9s_lfStack+352
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	jne	L633
	movl	8(%esi), %eax
	movl	12(%esi), %edx
	subl	$__ZL9s_lfStack, %esi
	movl	100(%esp), %ecx
	shrl	$4, %esi
	cmpl	$19, %esi
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	ja	L642
	movzbl	__ZL9s_lfStack+329(%esi), %eax
	leal	__ZL9s_lfStack+329(%esi), %ebx
	testb	%al, %al
	je	L643
	movl	$1, %ecx
	lock xaddb	%cl, __ZL9s_lfStack+328
	movl	__ZL9s_lfStack+324, %eax
	sall	$24, %ecx
	orl	%esi, %ecx
	sall	$4, %esi
	movl	%eax, 32(%esp)
	addl	$__ZL9s_lfStack, %esi
	.p2align 4,,7
L637:
	movl	%eax, (%esi)
	mfence
	movl	32(%esp), %eax
	lock cmpxchgl	%ecx, __ZL9s_lfStack+324
	sete	%dl
	testb	%dl, %dl
	movl	%eax, 32(%esp)
	je	L637
	lock subb	$1, (%ebx)
L638:
	addl	$76, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	%edx, %eax
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
L641:
	.cfi_restore_state
	xorl	%edx, %edx
	jmp	L638
L643:
	movl	$LC2, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$561, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L642:
	movl	$LC0, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$555, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L633:
	movl	48(%esp), %esi
	movl	52(%esp), %eax
	jmp	L632
	.cfi_endproc
LFE3294:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbO6data_tEZ8easyTestvEUlS1_E8_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbO6data_tEZ8easyTestvEUlS1_E8_E9_M_invokeERKSt9_Any_dataS1_:
LFB3155:
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
	subl	$40, %esp
	.cfi_def_cfa_offset 60
	movl	__ZL9s_lfStack+320, %eax
	cmpl	$19, %eax
	ja	L663
	movl	$1, %eax
	lock xaddl	%eax, __ZL9s_lfStack+320
	cmpl	$19, %eax
	jbe	L664
	cmpl	$20, %eax
	jne	L665
	.p2align 4,,7
L663:
	movl	__ZL9s_lfStack+324, %eax
	cmpl	$-1, %eax
	movl	%eax, 12(%esp)
	je	L651
L667:
	andl	$16777215, %eax
	cmpl	$19, %eax
	movl	%eax, %edx
	ja	L663
	sall	$4, %eax
	movl	__ZL9s_lfStack(%eax), %ecx
	leal	__ZL9s_lfStack(%eax), %edi
	movl	12(%esp), %eax
	leal	12(%esp), %ebx
	movl	%ebx, (%esp)
	lock cmpxchgl	%ecx, __ZL9s_lfStack+324
	movl	%eax, 12(%esp)
	je	L666
	movl	12(%esp), %eax
	cmpl	$-1, %eax
	jne	L667
L651:
	xorl	%eax, %eax
L661:
	addl	$40, %esp
	.cfi_remember_state
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
	.p2align 4,,7
L666:
	.cfi_restore_state
	movl	$-16843010, (%edi)
	addl	$320, %edx
	mfence
	lock subb	$1, __ZL9s_lfStack+9(%edx)
	movl	%edi, %esi
L648:
	movl	64(%esp), %eax
	movl	$1, %ecx
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%edx, 12(%esi)
	movl	%eax, 8(%esi)
	movq	__ZL9s_lfStack+352, %xmm0
	movq	%xmm0, (%edi)
	mfence
	lock xaddl	%ecx, __ZL9s_lfStack+360
	movl	%esi, %eax
	cltd
	orl	%edx, %ecx
L657:
	fildq	(%edi)
	fistpq	4(%esp)
	movl	(%esp), %ebx
	movl	8(%esp), %edx
	movl	4(%esp), %eax
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	4(%ebx), %edx
	movl	%esi, %ebx
	lock cmpxchg8b	__ZL9s_lfStack+352
	movl	(%esp), %ebx
	movl	%eax, %ebp
	sete	%al
	testb	%al, %al
	movl	%ebp, (%ebx)
	movl	%edx, 4(%ebx)
	jne	L661
	fildq	12(%esp)
	fistpq	(%edi)
	mfence
	jmp	L657
	.p2align 4,,7
L665:
	movl	$20, __ZL9s_lfStack+320
	mfence
	jmp	L663
L664:
	leal	320(%eax), %edx
	lock addb	$1, __ZL9s_lfStack+9(%edx)
	sall	$4, %eax
	leal	__ZL9s_lfStack(%eax), %esi
	leal	12(%esp), %eax
	movl	%esi, %edi
	movl	%eax, (%esp)
	jmp	L648
	.cfi_endproc
LFE3155:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E8_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E8_E9_M_invokeERKSt9_Any_dataS1_:
LFB3290:
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
	subl	$40, %esp
	.cfi_def_cfa_offset 60
	movl	__ZL9s_lfStack+320, %eax
	cmpl	$19, %eax
	ja	L687
	movl	$1, %eax
	lock xaddl	%eax, __ZL9s_lfStack+320
	cmpl	$19, %eax
	jbe	L688
	cmpl	$20, %eax
	jne	L689
	.p2align 4,,7
L687:
	movl	__ZL9s_lfStack+324, %eax
	cmpl	$-1, %eax
	movl	%eax, 12(%esp)
	je	L675
L691:
	andl	$16777215, %eax
	cmpl	$19, %eax
	movl	%eax, %edx
	ja	L687
	sall	$4, %eax
	movl	__ZL9s_lfStack(%eax), %ecx
	leal	__ZL9s_lfStack(%eax), %edi
	movl	12(%esp), %eax
	leal	12(%esp), %ebx
	movl	%ebx, (%esp)
	lock cmpxchgl	%ecx, __ZL9s_lfStack+324
	movl	%eax, 12(%esp)
	je	L690
	movl	12(%esp), %eax
	cmpl	$-1, %eax
	jne	L691
L675:
	xorl	%eax, %eax
L685:
	addl	$40, %esp
	.cfi_remember_state
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
	.p2align 4,,7
L690:
	.cfi_restore_state
	movl	$-16843010, (%edi)
	addl	$320, %edx
	mfence
	lock subb	$1, __ZL9s_lfStack+9(%edx)
	movl	%edi, %esi
L672:
	movl	64(%esp), %eax
	movl	$1, %ecx
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%edx, 12(%esi)
	movl	%eax, 8(%esi)
	movq	__ZL9s_lfStack+352, %xmm0
	movq	%xmm0, (%edi)
	mfence
	lock xaddl	%ecx, __ZL9s_lfStack+360
	movl	%esi, %eax
	cltd
	orl	%edx, %ecx
L681:
	fildq	(%edi)
	fistpq	4(%esp)
	movl	(%esp), %ebx
	movl	8(%esp), %edx
	movl	4(%esp), %eax
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	4(%ebx), %edx
	movl	%esi, %ebx
	lock cmpxchg8b	__ZL9s_lfStack+352
	movl	(%esp), %ebx
	movl	%eax, %ebp
	sete	%al
	testb	%al, %al
	movl	%ebp, (%ebx)
	movl	%edx, 4(%ebx)
	jne	L685
	fildq	12(%esp)
	fistpq	(%edi)
	mfence
	jmp	L681
	.p2align 4,,7
L689:
	movl	$20, __ZL9s_lfStack+320
	mfence
	jmp	L687
L688:
	leal	320(%eax), %edx
	lock addb	$1, __ZL9s_lfStack+9(%edx)
	sall	$4, %eax
	leal	__ZL9s_lfStack(%eax), %esi
	leal	12(%esp), %eax
	movl	%esi, %edi
	movl	%eax, (%esp)
	jmp	L672
	.cfi_endproc
LFE3290:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E13_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E13_E9_M_invokeERKSt9_Any_dataS1_:
LFB3310:
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
	movl	$0, 48(%esp)
	movl	$0, 52(%esp)
	movl	$0, 64(%esp)
	movl	$0, 68(%esp)
L693:
	fildq	__ZL9s_lfQueue+352
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	fildq	__ZL9s_lfQueue+360
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	48(%esp), %esi
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	fildq	(%esi)
	movl	64(%esp), %edx
	fistpq	24(%esp)
	movl	52(%esp), %eax
	xorl	68(%esp), %eax
	movl	24(%esp), %edi
	xorl	%esi, %edx
	movl	28(%esp), %ebp
	orl	%edx, %eax
	jne	L694
	movl	%ebp, %eax
	orl	%edi, %eax
	je	L701
	movl	68(%esp), %edx
	movl	%edi, %ebx
	movl	%ebp, %ecx
	movl	64(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfQueue+360
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	jmp	L693
	.p2align 4,,7
L694:
	movl	52(%esp), %edx
	movl	%edi, %ebx
	movl	%ebp, %ecx
	movl	48(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfQueue+352
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	jne	L693
	movl	8(%edi), %eax
	subl	$__ZL9s_lfQueue, %esi
	movl	12(%edi), %edx
	shrl	$4, %esi
	movl	116(%esp), %ecx
	cmpl	$19, %esi
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	ja	L706
	movzbl	__ZL9s_lfQueue+329(%esi), %eax
	leal	__ZL9s_lfQueue+329(%esi), %ebx
	testb	%al, %al
	je	L707
	movl	$1, %ecx
	lock xaddb	%cl, __ZL9s_lfQueue+328
	movl	__ZL9s_lfQueue+324, %eax
	sall	$24, %ecx
	orl	%esi, %ecx
	sall	$4, %esi
	movl	%eax, 32(%esp)
	addl	$__ZL9s_lfQueue, %esi
	.p2align 4,,7
L700:
	movl	%eax, (%esi)
	mfence
	movl	32(%esp), %eax
	lock cmpxchgl	%ecx, __ZL9s_lfQueue+324
	sete	%dl
	testb	%dl, %dl
	movl	%eax, 32(%esp)
	je	L700
	lock subb	$1, (%ebx)
L695:
	addl	$92, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	%edx, %eax
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
L701:
	.cfi_restore_state
	xorl	%edx, %edx
	jmp	L695
L707:
	movl	$LC2, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$561, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L706:
	movl	$LC0, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$555, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
	.cfi_endproc
LFE3310:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbR6data_tEZ8easyTestvEUlS1_E13_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbR6data_tEZ8easyTestvEUlS1_E13_E9_M_invokeERKSt9_Any_dataS1_:
LFB3175:
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
	movl	$0, 48(%esp)
	movl	$0, 52(%esp)
	movl	$0, 64(%esp)
	movl	$0, 68(%esp)
L709:
	fildq	__ZL9s_lfQueue+352
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	fildq	__ZL9s_lfQueue+360
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	48(%esp), %esi
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	fildq	(%esi)
	movl	64(%esp), %edx
	fistpq	24(%esp)
	movl	52(%esp), %eax
	xorl	68(%esp), %eax
	movl	24(%esp), %edi
	xorl	%esi, %edx
	movl	28(%esp), %ebp
	orl	%edx, %eax
	jne	L710
	movl	%ebp, %eax
	orl	%edi, %eax
	je	L717
	movl	68(%esp), %edx
	movl	%edi, %ebx
	movl	%ebp, %ecx
	movl	64(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfQueue+360
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	jmp	L709
	.p2align 4,,7
L710:
	movl	52(%esp), %edx
	movl	%edi, %ebx
	movl	%ebp, %ecx
	movl	48(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfQueue+352
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	jne	L709
	movl	8(%edi), %eax
	subl	$__ZL9s_lfQueue, %esi
	movl	12(%edi), %edx
	shrl	$4, %esi
	movl	116(%esp), %ecx
	cmpl	$19, %esi
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	ja	L722
	movzbl	__ZL9s_lfQueue+329(%esi), %eax
	leal	__ZL9s_lfQueue+329(%esi), %ebx
	testb	%al, %al
	je	L723
	movl	$1, %ecx
	lock xaddb	%cl, __ZL9s_lfQueue+328
	movl	__ZL9s_lfQueue+324, %eax
	sall	$24, %ecx
	orl	%esi, %ecx
	sall	$4, %esi
	movl	%eax, 32(%esp)
	addl	$__ZL9s_lfQueue, %esi
	.p2align 4,,7
L716:
	movl	%eax, (%esi)
	mfence
	movl	32(%esp), %eax
	lock cmpxchgl	%ecx, __ZL9s_lfQueue+324
	sete	%dl
	testb	%dl, %dl
	movl	%eax, 32(%esp)
	je	L716
	lock subb	$1, (%ebx)
L711:
	addl	$92, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	%edx, %eax
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
L717:
	.cfi_restore_state
	xorl	%edx, %edx
	jmp	L711
L723:
	movl	$LC2, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$561, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L722:
	movl	$LC0, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$555, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
	.cfi_endproc
LFE3175:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E12_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E12_E9_M_invokeERKSt9_Any_dataS1_:
LFB3306:
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
	subl	$64, %esp
	.cfi_def_cfa_offset 84
	movl	__ZL9s_lfQueue+320, %eax
	cmpl	$19, %eax
	ja	L747
	movl	$1, %eax
	lock xaddl	%eax, __ZL9s_lfQueue+320
	cmpl	$19, %eax
	jbe	L748
	cmpl	$20, %eax
	jne	L749
	.p2align 4,,7
L747:
	movl	__ZL9s_lfQueue+324, %eax
	cmpl	$-1, %eax
	movl	%eax, 36(%esp)
	je	L731
L751:
	andl	$16777215, %eax
	cmpl	$19, %eax
	movl	%eax, %edx
	ja	L747
	sall	$4, %eax
	leal	__ZL9s_lfQueue(%eax), %ecx
	movl	__ZL9s_lfQueue(%eax), %ebx
	movl	36(%esp), %eax
	leal	36(%esp), %esi
	lock cmpxchgl	%ebx, __ZL9s_lfQueue+324
	movl	%eax, 36(%esp)
	je	L750
	movl	36(%esp), %eax
	cmpl	$-1, %eax
	jne	L751
L731:
	addl	$64, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	xorl	%ebp, %ebp
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	movl	%ebp, %eax
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
L750:
	.cfi_restore_state
	movl	$-16843010, (%ecx)
	addl	$320, %edx
	mfence
	lock subb	$1, __ZL9s_lfQueue+9(%edx)
	movl	%ecx, %edi
L728:
	movl	88(%esp), %eax
	movl	$1, %ebp
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%edx, 12(%edi)
	movl	%eax, 8(%edi)
	lock xaddl	%ebp, __ZL9s_lfQueue+368
	movl	%edi, %eax
	cltd
	xorl	%eax, %eax
	orl	%edx, %ebp
	xorl	%edx, %edx
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
	fildq	12(%esp)
	movl	%ebp, (%esp)
	fistpq	(%ecx)
	mfence
	movl	$0, 20(%esp)
	movl	$0, 24(%esp)
L738:
	fildq	__ZL9s_lfQueue+360
	fistpq	12(%esp)
	movl	12(%esp), %eax
	movl	16(%esp), %edx
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	fildq	(%eax)
	fistpq	12(%esp)
	movl	16(%esp), %ebx
	movl	12(%esp), %ecx
	movl	%ebx, %eax
	orl	%ecx, %eax
	movl	%ecx, 4(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 36(%esp)
	movl	%ebx, 40(%esp)
	jne	L735
	fildq	__ZL9s_lfQueue+360
	movl	%edi, %ebx
	fistpq	12(%esp)
	movl	12(%esp), %eax
	movl	4(%esi), %edx
	movl	(%esp), %ecx
	movl	%eax, %ebp
	movl	(%esi), %eax
	lock cmpxchg8b	0(%ebp)
	sete	%cl
	testb	%cl, %cl
	movl	%ecx, %ebp
	movl	%eax, (%esi)
	movl	%edx, 4(%esi)
	je	L738
	movl	24(%esp), %edx
	movl	%edi, %ebx
	movl	20(%esp), %eax
	movl	(%esp), %ecx
	lock cmpxchg8b	__ZL9s_lfQueue+360
	addl	$64, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	%ebp, %eax
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
	.p2align 4,,7
L735:
	.cfi_restore_state
	movl	24(%esp), %edx
	movl	20(%esp), %eax
	movl	4(%esp), %ebx
	movl	8(%esp), %ecx
	lock cmpxchg8b	__ZL9s_lfQueue+360
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	jmp	L738
L749:
	movl	$20, __ZL9s_lfQueue+320
	mfence
	jmp	L747
L748:
	leal	320(%eax), %edx
	lock addb	$1, __ZL9s_lfQueue+9(%edx)
	sall	$4, %eax
	leal	__ZL9s_lfQueue(%eax), %edi
	movl	%edi, %ecx
	leal	36(%esp), %esi
	jmp	L728
	.cfi_endproc
LFE3306:
	.p2align 4,,15
	.globl	__Z11allocNormalv
	.def	__Z11allocNormalv;	.scl	2;	.type	32;	.endef
__Z11allocNormalv:
LFB2509:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2509
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL15s_poolAllocator+172, (%esp)
LEHB59:
	call	_pthread_mutex_lock
LEHE59:
	testl	%eax, %eax
	jne	L760
	movl	__ZL15s_poolAllocator+160, %ecx
	cmpl	$19, %ecx
	jbe	L761
	movl	__ZL15s_poolAllocator+164, %ecx
	cmpl	$-1, %ecx
	je	L756
	movl	__ZL15s_poolAllocator(,%ecx,8), %eax
	leal	__ZL15s_poolAllocator(,%ecx,8), %ebx
	movl	%eax, __ZL15s_poolAllocator+164
	movl	$1, %eax
	movl	$-16843010, __ZL15s_poolAllocator(,%ecx,8)
	sall	%cl, %eax
	orl	%eax, __ZL15s_poolAllocator+168
L755:
	movl	$__ZL15s_poolAllocator+172, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, %eax
	movl	$0, (%ebx)
	movl	$0, 4(%ebx)
L758:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L761:
	.cfi_restore_state
	leal	1(%ecx), %eax
	movl	%eax, __ZL15s_poolAllocator+160
	movl	$1, %eax
	sall	%cl, %eax
	leal	__ZL15s_poolAllocator(,%ecx,8), %ebx
	orl	%eax, __ZL15s_poolAllocator+168
	jmp	L755
	.p2align 4,,7
L756:
	movl	$__ZL15s_poolAllocator+172, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L758
L760:
	movl	%eax, (%esp)
LEHB60:
	call	__ZSt20__throw_system_errori
LEHE60:
	.cfi_endproc
LFE2509:
	.section	.gcc_except_table,"w"
LLSDA2509:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2509-LLSDACSB2509
LLSDACSB2509:
	.uleb128 LEHB59-LFB2509
	.uleb128 LEHE59-LEHB59
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB60-LFB2509
	.uleb128 LEHE60-LEHB60
	.uleb128 0
	.uleb128 0
LLSDACSE2509:
	.text
	.p2align 4,,15
	.globl	__Z10freeNormalP6data_t
	.def	__Z10freeNormalP6data_t;	.scl	2;	.type	32;	.endef
__Z10freeNormalP6data_t:
LFB2510:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2510
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL15s_poolAllocator+172, (%esp)
LEHB61:
	call	_pthread_mutex_lock
LEHE61:
	testl	%eax, %eax
	jne	L770
	movl	32(%esp), %ecx
	subl	$__ZL15s_poolAllocator, %ecx
	shrl	$3, %ecx
	cmpl	$19, %ecx
	ja	L771
	movl	__ZL15s_poolAllocator+168, %edx
	movl	$1, %eax
	sall	%cl, %eax
	testl	%edx, %eax
	je	L772
	movl	__ZL15s_poolAllocator+164, %ebx
	notl	%eax
	andl	%edx, %eax
	movl	$__ZL15s_poolAllocator+172, (%esp)
	movl	%ebx, __ZL15s_poolAllocator(,%ecx,8)
	movl	%ecx, __ZL15s_poolAllocator+164
	movl	%eax, __ZL15s_poolAllocator+168
	call	_pthread_mutex_unlock
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	movl	$1, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L770:
	.cfi_restore_state
	movl	%eax, (%esp)
LEHB62:
	call	__ZSt20__throw_system_errori
LEHE62:
L772:
	movl	$LC2, 12(%esp)
	movl	$__ZZN14pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$287, 4(%esp)
	movl	$LC1, (%esp)
LEHB63:
	call	___assert_func
LEHE63:
L767:
	movl	%eax, %ebx
	movl	$__ZL15s_poolAllocator+172, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, (%esp)
LEHB64:
	call	__Unwind_Resume
LEHE64:
L771:
	movl	$LC0, 12(%esp)
	movl	$__ZZN14pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$281, 4(%esp)
	movl	$LC1, (%esp)
LEHB65:
	call	___assert_func
LEHE65:
	.cfi_endproc
LFE2510:
	.section	.gcc_except_table,"w"
LLSDA2510:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2510-LLSDACSB2510
LLSDACSB2510:
	.uleb128 LEHB61-LFB2510
	.uleb128 LEHE61-LEHB61
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB62-LFB2510
	.uleb128 LEHE62-LEHB62
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB63-LFB2510
	.uleb128 LEHE63-LEHB63
	.uleb128 L767-LFB2510
	.uleb128 0
	.uleb128 LEHB64-LFB2510
	.uleb128 LEHE64-LEHB64
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB65-LFB2510
	.uleb128 LEHE65-LEHB65
	.uleb128 L767-LFB2510
	.uleb128 0
LLSDACSE2510:
	.text
	.p2align 4,,15
	.globl	__Z13allocLockFreev
	.def	__Z13allocLockFreev;	.scl	2;	.type	32;	.endef
__Z13allocLockFreev:
LFB2511:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	__ZL17s_lfPoolAllocator+160, %eax
	cmpl	$19, %eax
	ja	L790
	movl	$1, %eax
	lock xaddl	%eax, __ZL17s_lfPoolAllocator+160
	cmpl	$19, %eax
	jbe	L791
	cmpl	$20, %eax
	jne	L792
	.p2align 4,,7
L790:
	movl	__ZL17s_lfPoolAllocator+164, %eax
	cmpl	$-1, %eax
	movl	%eax, (%esp)
	je	L780
L794:
	andl	$16777215, %eax
	cmpl	$19, %eax
	movl	%eax, %edx
	ja	L790
	leal	__ZL17s_lfPoolAllocator(,%eax,8), %ebx
	movl	__ZL17s_lfPoolAllocator(,%eax,8), %ecx
	movl	(%esp), %eax
	lock cmpxchgl	%ecx, __ZL17s_lfPoolAllocator+164
	movl	%eax, (%esp)
	je	L793
	movl	(%esp), %eax
	cmpl	$-1, %eax
	jne	L794
L780:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L793:
	.cfi_restore_state
	movl	$-16843010, (%ebx)
	addl	$160, %edx
	mfence
	lock subb	$1, __ZL17s_lfPoolAllocator+9(%edx)
	movl	%ebx, %eax
L777:
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L792:
	.cfi_restore_state
	movl	$20, __ZL17s_lfPoolAllocator+160
	mfence
	jmp	L790
L791:
	leal	160(%eax), %edx
	lock addb	$1, __ZL17s_lfPoolAllocator+9(%edx)
	leal	__ZL17s_lfPoolAllocator(,%eax,8), %eax
	jmp	L777
	.cfi_endproc
LFE2511:
	.p2align 4,,15
	.globl	__Z12freeLockFreeP6data_t
	.def	__Z12freeLockFreeP6data_t;	.scl	2;	.type	32;	.endef
__Z12freeLockFreeP6data_t:
LFB2512:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$40, %esp
	.cfi_def_cfa_offset 48
	movl	48(%esp), %ecx
	subl	$__ZL17s_lfPoolAllocator, %ecx
	shrl	$3, %ecx
	cmpl	$19, %ecx
	ja	L801
	movzbl	__ZL17s_lfPoolAllocator+169(%ecx), %eax
	leal	__ZL17s_lfPoolAllocator+169(%ecx), %ebx
	testb	%al, %al
	je	L802
	movl	$1, %edx
	lock xaddb	%dl, __ZL17s_lfPoolAllocator+168
	movl	__ZL17s_lfPoolAllocator+164, %eax
	sall	$24, %edx
	orl	%ecx, %edx
	movl	%eax, 16(%esp)
	leal	__ZL17s_lfPoolAllocator(,%ecx,8), %ecx
	.p2align 4,,7
L799:
	movl	%eax, (%ecx)
	mfence
	movl	16(%esp), %eax
	lock cmpxchgl	%edx, __ZL17s_lfPoolAllocator+164
	movl	%eax, 16(%esp)
	jne	L799
	lock subb	$1, (%ebx)
	movl	$1, %eax
	addl	$40, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L801:
	.cfi_restore_state
	movl	$LC0, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$555, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L802:
	movl	$LC2, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$561, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
	.cfi_endproc
LFE2512:
	.p2align 4,,15
	.globl	__Z10pushNormalO6data_t
	.def	__Z10pushNormalO6data_t;	.scl	2;	.type	32;	.endef
__Z10pushNormalO6data_t:
LFB2513:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2513
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_stack+252, (%esp)
LEHB66:
	call	_pthread_mutex_lock
LEHE66:
	testl	%eax, %eax
	jne	L809
	movl	__ZL7s_stack+240, %ecx
	cmpl	$19, %ecx
	jbe	L814
	movl	__ZL7s_stack+244, %ecx
	cmpl	$-1, %ecx
	je	L807
	leal	(%ecx,%ecx,2), %eax
	sall	$2, %eax
	movl	__ZL7s_stack(%eax), %edx
	leal	__ZL7s_stack(%eax), %ebx
	movl	%edx, __ZL7s_stack+244
	movl	$1, %edx
	movl	$-16843010, __ZL7s_stack(%eax)
	sall	%cl, %edx
	orl	%edx, __ZL7s_stack+248
L806:
	movl	$__ZL7s_stack+252, (%esp)
	call	_pthread_mutex_unlock
	movl	32(%esp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	$__ZL7s_stack+260, (%esp)
	movl	%edx, 8(%ebx)
	movl	%eax, 4(%ebx)
LEHB67:
	call	_pthread_mutex_lock
LEHE67:
	testl	%eax, %eax
	jne	L809
	movl	__ZL7s_stack+256, %eax
	movl	$__ZL7s_stack+260, (%esp)
	movl	%eax, (%ebx)
	movl	%ebx, __ZL7s_stack+256
	call	_pthread_mutex_unlock
	movl	$1, %eax
L811:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L814:
	.cfi_restore_state
	leal	1(%ecx), %eax
	movl	%eax, __ZL7s_stack+240
	movl	$1, %eax
	sall	%cl, %eax
	orl	%eax, __ZL7s_stack+248
	leal	(%ecx,%ecx,2), %eax
	leal	__ZL7s_stack(,%eax,4), %ebx
	jmp	L806
	.p2align 4,,7
L807:
	movl	$__ZL7s_stack+252, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L811
L809:
	movl	%eax, (%esp)
LEHB68:
	call	__ZSt20__throw_system_errori
LEHE68:
	.cfi_endproc
LFE2513:
	.section	.gcc_except_table,"w"
LLSDA2513:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2513-LLSDACSB2513
LLSDACSB2513:
	.uleb128 LEHB66-LFB2513
	.uleb128 LEHE66-LEHB66
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB67-LFB2513
	.uleb128 LEHE67-LEHB67
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB68-LFB2513
	.uleb128 LEHE68-LEHB68
	.uleb128 0
	.uleb128 0
LLSDACSE2513:
	.text
	.p2align 4,,15
	.globl	__Z10pushNormalR6data_t
	.def	__Z10pushNormalR6data_t;	.scl	2;	.type	32;	.endef
__Z10pushNormalR6data_t:
LFB2515:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2515
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_stack+252, (%esp)
LEHB69:
	call	_pthread_mutex_lock
LEHE69:
	testl	%eax, %eax
	jne	L821
	movl	__ZL7s_stack+240, %ecx
	cmpl	$19, %ecx
	jbe	L826
	movl	__ZL7s_stack+244, %ecx
	cmpl	$-1, %ecx
	je	L819
	leal	(%ecx,%ecx,2), %eax
	sall	$2, %eax
	movl	__ZL7s_stack(%eax), %edx
	leal	__ZL7s_stack(%eax), %ebx
	movl	%edx, __ZL7s_stack+244
	movl	$1, %edx
	movl	$-16843010, __ZL7s_stack(%eax)
	sall	%cl, %edx
	orl	%edx, __ZL7s_stack+248
L818:
	movl	$__ZL7s_stack+252, (%esp)
	call	_pthread_mutex_unlock
	movl	32(%esp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	$__ZL7s_stack+260, (%esp)
	movl	%edx, 8(%ebx)
	movl	%eax, 4(%ebx)
LEHB70:
	call	_pthread_mutex_lock
LEHE70:
	testl	%eax, %eax
	jne	L821
	movl	__ZL7s_stack+256, %eax
	movl	$__ZL7s_stack+260, (%esp)
	movl	%eax, (%ebx)
	movl	%ebx, __ZL7s_stack+256
	call	_pthread_mutex_unlock
	movl	$1, %eax
L823:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L826:
	.cfi_restore_state
	leal	1(%ecx), %eax
	movl	%eax, __ZL7s_stack+240
	movl	$1, %eax
	sall	%cl, %eax
	orl	%eax, __ZL7s_stack+248
	leal	(%ecx,%ecx,2), %eax
	leal	__ZL7s_stack(,%eax,4), %ebx
	jmp	L818
	.p2align 4,,7
L819:
	movl	$__ZL7s_stack+252, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L823
L821:
	movl	%eax, (%esp)
LEHB71:
	call	__ZSt20__throw_system_errori
LEHE71:
	.cfi_endproc
LFE2515:
	.section	.gcc_except_table,"w"
LLSDA2515:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2515-LLSDACSB2515
LLSDACSB2515:
	.uleb128 LEHB69-LFB2515
	.uleb128 LEHE69-LEHB69
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB70-LFB2515
	.uleb128 LEHE70-LEHB70
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB71-LFB2515
	.uleb128 LEHE71-LEHB71
	.uleb128 0
	.uleb128 0
LLSDACSE2515:
	.text
	.p2align 4,,15
	.globl	__Z9popNormalR6data_t
	.def	__Z9popNormalR6data_t;	.scl	2;	.type	32;	.endef
__Z9popNormalR6data_t:
LFB2516:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2516
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_stack+260, (%esp)
LEHB72:
	call	_pthread_mutex_lock
LEHE72:
	testl	%eax, %eax
	jne	L840
	movl	__ZL7s_stack+256, %ebx
	testl	%ebx, %ebx
	je	L835
	movl	(%ebx), %eax
	movl	4(%ebx), %edx
	movl	8(%ebx), %ecx
	movl	%eax, __ZL7s_stack+256
	movl	32(%esp), %eax
	movl	%edx, (%eax)
	movl	%ecx, 4(%eax)
	movl	$__ZL7s_stack+252, (%esp)
LEHB73:
	call	_pthread_mutex_lock
LEHE73:
	testl	%eax, %eax
	jne	L841
	subl	$__ZL7s_stack, %ebx
	movl	$-1431655765, %ecx
	movl	%ebx, %eax
	mull	%ecx
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L842
	movl	__ZL7s_stack+248, %ebx
	movl	$1, %eax
	movl	%edx, %ecx
	sall	%cl, %eax
	testl	%ebx, %eax
	je	L843
	movl	__ZL7s_stack+244, %esi
	notl	%eax
	andl	%ebx, %eax
	movl	$1, %ebx
	leal	(%edx,%edx,2), %ecx
	movl	$__ZL7s_stack+252, (%esp)
	movl	%esi, __ZL7s_stack(,%ecx,4)
	movl	%edx, __ZL7s_stack+244
	movl	%eax, __ZL7s_stack+248
	call	_pthread_mutex_unlock
L829:
	movl	$__ZL7s_stack+260, (%esp)
	call	_pthread_mutex_unlock
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	movl	%ebx, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L835:
	.cfi_restore_state
	xorl	%ebx, %ebx
	jmp	L829
L841:
	movl	%eax, (%esp)
LEHB74:
	call	__ZSt20__throw_system_errori
LEHE74:
L836:
	movl	%eax, %ebx
L834:
	movl	$__ZL7s_stack+260, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, (%esp)
LEHB75:
	call	__Unwind_Resume
L840:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE75:
L843:
	movl	$LC2, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$287, 4(%esp)
	movl	$LC1, (%esp)
LEHB76:
	call	___assert_func
LEHE76:
L837:
	movl	$__ZL7s_stack+252, (%esp)
	movl	%eax, %ebx
	call	_pthread_mutex_unlock
	jmp	L834
L842:
	movl	$LC0, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$281, 4(%esp)
	movl	$LC1, (%esp)
LEHB77:
	call	___assert_func
LEHE77:
	.cfi_endproc
LFE2516:
	.section	.gcc_except_table,"w"
LLSDA2516:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2516-LLSDACSB2516
LLSDACSB2516:
	.uleb128 LEHB72-LFB2516
	.uleb128 LEHE72-LEHB72
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB73-LFB2516
	.uleb128 LEHE73-LEHB73
	.uleb128 L836-LFB2516
	.uleb128 0
	.uleb128 LEHB74-LFB2516
	.uleb128 LEHE74-LEHB74
	.uleb128 L836-LFB2516
	.uleb128 0
	.uleb128 LEHB75-LFB2516
	.uleb128 LEHE75-LEHB75
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB76-LFB2516
	.uleb128 LEHE76-LEHB76
	.uleb128 L837-LFB2516
	.uleb128 0
	.uleb128 LEHB77-LFB2516
	.uleb128 LEHE77-LEHB77
	.uleb128 L837-LFB2516
	.uleb128 0
LLSDACSE2516:
	.text
	.p2align 4,,15
	.globl	__Z12pushLockFreeO6data_t
	.def	__Z12pushLockFreeO6data_t;	.scl	2;	.type	32;	.endef
__Z12pushLockFreeO6data_t:
LFB2517:
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
	subl	$40, %esp
	.cfi_def_cfa_offset 60
	movl	__ZL9s_lfStack+320, %eax
	cmpl	$19, %eax
	ja	L863
	movl	$1, %eax
	lock xaddl	%eax, __ZL9s_lfStack+320
	cmpl	$19, %eax
	jbe	L864
	cmpl	$20, %eax
	jne	L865
	.p2align 4,,7
L863:
	movl	__ZL9s_lfStack+324, %eax
	cmpl	$-1, %eax
	movl	%eax, 12(%esp)
	je	L851
L867:
	andl	$16777215, %eax
	cmpl	$19, %eax
	movl	%eax, %edx
	ja	L863
	sall	$4, %eax
	movl	__ZL9s_lfStack(%eax), %ecx
	leal	__ZL9s_lfStack(%eax), %edi
	movl	12(%esp), %eax
	leal	12(%esp), %ebx
	movl	%ebx, (%esp)
	lock cmpxchgl	%ecx, __ZL9s_lfStack+324
	movl	%eax, 12(%esp)
	je	L866
	movl	12(%esp), %eax
	cmpl	$-1, %eax
	jne	L867
L851:
	xorl	%eax, %eax
L861:
	addl	$40, %esp
	.cfi_remember_state
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
	.p2align 4,,7
L866:
	.cfi_restore_state
	movl	$-16843010, (%edi)
	addl	$320, %edx
	mfence
	lock subb	$1, __ZL9s_lfStack+9(%edx)
	movl	%edi, %esi
L848:
	movl	60(%esp), %eax
	movl	$1, %ecx
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%edx, 12(%esi)
	movl	%eax, 8(%esi)
	movq	__ZL9s_lfStack+352, %xmm0
	movq	%xmm0, (%edi)
	mfence
	lock xaddl	%ecx, __ZL9s_lfStack+360
	movl	%esi, %eax
	cltd
	orl	%edx, %ecx
L857:
	fildq	(%edi)
	fistpq	4(%esp)
	movl	(%esp), %ebx
	movl	8(%esp), %edx
	movl	4(%esp), %eax
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	4(%ebx), %edx
	movl	%esi, %ebx
	lock cmpxchg8b	__ZL9s_lfStack+352
	movl	(%esp), %ebx
	movl	%eax, %ebp
	sete	%al
	testb	%al, %al
	movl	%ebp, (%ebx)
	movl	%edx, 4(%ebx)
	jne	L861
	fildq	12(%esp)
	fistpq	(%edi)
	mfence
	jmp	L857
	.p2align 4,,7
L865:
	movl	$20, __ZL9s_lfStack+320
	mfence
	jmp	L863
L864:
	leal	320(%eax), %edx
	lock addb	$1, __ZL9s_lfStack+9(%edx)
	sall	$4, %eax
	leal	__ZL9s_lfStack(%eax), %esi
	leal	12(%esp), %eax
	movl	%esi, %edi
	movl	%eax, (%esp)
	jmp	L848
	.cfi_endproc
LFE2517:
	.p2align 4,,15
	.globl	__Z12pushLockFreeR6data_t
	.def	__Z12pushLockFreeR6data_t;	.scl	2;	.type	32;	.endef
__Z12pushLockFreeR6data_t:
LFB2518:
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
	subl	$40, %esp
	.cfi_def_cfa_offset 60
	movl	__ZL9s_lfStack+320, %eax
	cmpl	$19, %eax
	ja	L887
	movl	$1, %eax
	lock xaddl	%eax, __ZL9s_lfStack+320
	cmpl	$19, %eax
	jbe	L888
	cmpl	$20, %eax
	jne	L889
	.p2align 4,,7
L887:
	movl	__ZL9s_lfStack+324, %eax
	cmpl	$-1, %eax
	movl	%eax, 12(%esp)
	je	L875
L891:
	andl	$16777215, %eax
	cmpl	$19, %eax
	movl	%eax, %edx
	ja	L887
	sall	$4, %eax
	movl	__ZL9s_lfStack(%eax), %ecx
	leal	__ZL9s_lfStack(%eax), %edi
	movl	12(%esp), %eax
	leal	12(%esp), %ebx
	movl	%ebx, (%esp)
	lock cmpxchgl	%ecx, __ZL9s_lfStack+324
	movl	%eax, 12(%esp)
	je	L890
	movl	12(%esp), %eax
	cmpl	$-1, %eax
	jne	L891
L875:
	xorl	%eax, %eax
L885:
	addl	$40, %esp
	.cfi_remember_state
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
	.p2align 4,,7
L890:
	.cfi_restore_state
	movl	$-16843010, (%edi)
	addl	$320, %edx
	mfence
	lock subb	$1, __ZL9s_lfStack+9(%edx)
	movl	%edi, %esi
L872:
	movl	60(%esp), %eax
	movl	$1, %ecx
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%edx, 12(%esi)
	movl	%eax, 8(%esi)
	movq	__ZL9s_lfStack+352, %xmm0
	movq	%xmm0, (%edi)
	mfence
	lock xaddl	%ecx, __ZL9s_lfStack+360
	movl	%esi, %eax
	cltd
	orl	%edx, %ecx
L881:
	fildq	(%edi)
	fistpq	4(%esp)
	movl	(%esp), %ebx
	movl	8(%esp), %edx
	movl	4(%esp), %eax
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	4(%ebx), %edx
	movl	%esi, %ebx
	lock cmpxchg8b	__ZL9s_lfStack+352
	movl	(%esp), %ebx
	movl	%eax, %ebp
	sete	%al
	testb	%al, %al
	movl	%ebp, (%ebx)
	movl	%edx, 4(%ebx)
	jne	L885
	fildq	12(%esp)
	fistpq	(%edi)
	mfence
	jmp	L881
	.p2align 4,,7
L889:
	movl	$20, __ZL9s_lfStack+320
	mfence
	jmp	L887
L888:
	leal	320(%eax), %edx
	lock addb	$1, __ZL9s_lfStack+9(%edx)
	sall	$4, %eax
	leal	__ZL9s_lfStack(%eax), %esi
	leal	12(%esp), %eax
	movl	%esi, %edi
	movl	%eax, (%esp)
	jmp	L872
	.cfi_endproc
LFE2518:
	.p2align 4,,15
	.globl	__Z11popLockFreeR6data_t
	.def	__Z11popLockFreeR6data_t;	.scl	2;	.type	32;	.endef
__Z11popLockFreeR6data_t:
LFB2519:
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
	subl	$76, %esp
	.cfi_def_cfa_offset 96
	fildq	__ZL9s_lfStack+352
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 48(%esp)
	movl	%eax, %esi
	movl	%edx, 52(%esp)
	movl	%edx, %eax
L893:
	orl	%esi, %eax
	je	L902
	fildq	(%esi)
	fistpq	24(%esp)
	movl	24(%esp), %edi
	movl	28(%esp), %ebp
	movl	52(%esp), %edx
	movl	48(%esp), %eax
	movl	%edi, %ebx
	movl	%ebp, %ecx
	lock cmpxchg8b	__ZL9s_lfStack+352
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	jne	L894
	movl	8(%esi), %eax
	movl	12(%esi), %edx
	subl	$__ZL9s_lfStack, %esi
	movl	96(%esp), %ecx
	shrl	$4, %esi
	cmpl	$19, %esi
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	ja	L903
	movzbl	__ZL9s_lfStack+329(%esi), %eax
	leal	__ZL9s_lfStack+329(%esi), %ebx
	testb	%al, %al
	je	L904
	movl	$1, %ecx
	lock xaddb	%cl, __ZL9s_lfStack+328
	movl	__ZL9s_lfStack+324, %eax
	sall	$24, %ecx
	orl	%esi, %ecx
	sall	$4, %esi
	movl	%eax, 32(%esp)
	addl	$__ZL9s_lfStack, %esi
	.p2align 4,,7
L898:
	movl	%eax, (%esi)
	mfence
	movl	32(%esp), %eax
	lock cmpxchgl	%ecx, __ZL9s_lfStack+324
	sete	%dl
	testb	%dl, %dl
	movl	%eax, 32(%esp)
	je	L898
	lock subb	$1, (%ebx)
L899:
	addl	$76, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	%edx, %eax
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
L902:
	.cfi_restore_state
	xorl	%edx, %edx
	jmp	L899
L904:
	movl	$LC2, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$561, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L903:
	movl	$LC0, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$555, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L894:
	movl	48(%esp), %esi
	movl	52(%esp), %eax
	jmp	L893
	.cfi_endproc
LFE2519:
	.p2align 4,,15
	.globl	__Z13enqueueNormalO6data_t
	.def	__Z13enqueueNormalO6data_t;	.scl	2;	.type	32;	.endef
__Z13enqueueNormalO6data_t:
LFB2520:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2520
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_queue+252, (%esp)
LEHB78:
	call	_pthread_mutex_lock
LEHE78:
	testl	%eax, %eax
	jne	L911
	movl	__ZL7s_queue+240, %ecx
	cmpl	$19, %ecx
	jbe	L916
	movl	__ZL7s_queue+244, %ecx
	cmpl	$-1, %ecx
	je	L909
	leal	(%ecx,%ecx,2), %eax
	sall	$2, %eax
	movl	__ZL7s_queue(%eax), %edx
	leal	__ZL7s_queue(%eax), %ebx
	movl	%edx, __ZL7s_queue+244
	movl	$1, %edx
	movl	$-16843010, __ZL7s_queue(%eax)
	sall	%cl, %edx
	orl	%edx, __ZL7s_queue+248
L908:
	movl	$__ZL7s_queue+252, (%esp)
	call	_pthread_mutex_unlock
	movl	32(%esp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	$__ZL7s_queue+264, (%esp)
	movl	$0, (%ebx)
	movl	%edx, 8(%ebx)
	movl	%eax, 4(%ebx)
LEHB79:
	call	_pthread_mutex_lock
LEHE79:
	testl	%eax, %eax
	jne	L911
	movl	__ZL7s_queue+260, %eax
	movl	%ebx, (%eax)
	movl	$__ZL7s_queue+264, (%esp)
	movl	%ebx, __ZL7s_queue+260
	call	_pthread_mutex_unlock
	movl	$1, %eax
L913:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L916:
	.cfi_restore_state
	leal	1(%ecx), %eax
	movl	%eax, __ZL7s_queue+240
	movl	$1, %eax
	sall	%cl, %eax
	orl	%eax, __ZL7s_queue+248
	leal	(%ecx,%ecx,2), %eax
	leal	__ZL7s_queue(,%eax,4), %ebx
	jmp	L908
	.p2align 4,,7
L909:
	movl	$__ZL7s_queue+252, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L913
L911:
	movl	%eax, (%esp)
LEHB80:
	call	__ZSt20__throw_system_errori
LEHE80:
	.cfi_endproc
LFE2520:
	.section	.gcc_except_table,"w"
LLSDA2520:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2520-LLSDACSB2520
LLSDACSB2520:
	.uleb128 LEHB78-LFB2520
	.uleb128 LEHE78-LEHB78
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB79-LFB2520
	.uleb128 LEHE79-LEHB79
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB80-LFB2520
	.uleb128 LEHE80-LEHB80
	.uleb128 0
	.uleb128 0
LLSDACSE2520:
	.text
	.p2align 4,,15
	.globl	__Z13enqueueNormalR6data_t
	.def	__Z13enqueueNormalR6data_t;	.scl	2;	.type	32;	.endef
__Z13enqueueNormalR6data_t:
LFB2521:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2521
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_queue+252, (%esp)
LEHB81:
	call	_pthread_mutex_lock
LEHE81:
	testl	%eax, %eax
	jne	L923
	movl	__ZL7s_queue+240, %ecx
	cmpl	$19, %ecx
	jbe	L928
	movl	__ZL7s_queue+244, %ecx
	cmpl	$-1, %ecx
	je	L921
	leal	(%ecx,%ecx,2), %eax
	sall	$2, %eax
	movl	__ZL7s_queue(%eax), %edx
	leal	__ZL7s_queue(%eax), %ebx
	movl	%edx, __ZL7s_queue+244
	movl	$1, %edx
	movl	$-16843010, __ZL7s_queue(%eax)
	sall	%cl, %edx
	orl	%edx, __ZL7s_queue+248
L920:
	movl	$__ZL7s_queue+252, (%esp)
	call	_pthread_mutex_unlock
	movl	32(%esp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	$__ZL7s_queue+264, (%esp)
	movl	$0, (%ebx)
	movl	%edx, 8(%ebx)
	movl	%eax, 4(%ebx)
LEHB82:
	call	_pthread_mutex_lock
LEHE82:
	testl	%eax, %eax
	jne	L923
	movl	__ZL7s_queue+260, %eax
	movl	%ebx, (%eax)
	movl	$__ZL7s_queue+264, (%esp)
	movl	%ebx, __ZL7s_queue+260
	call	_pthread_mutex_unlock
	movl	$1, %eax
L925:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L928:
	.cfi_restore_state
	leal	1(%ecx), %eax
	movl	%eax, __ZL7s_queue+240
	movl	$1, %eax
	sall	%cl, %eax
	orl	%eax, __ZL7s_queue+248
	leal	(%ecx,%ecx,2), %eax
	leal	__ZL7s_queue(,%eax,4), %ebx
	jmp	L920
	.p2align 4,,7
L921:
	movl	$__ZL7s_queue+252, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L925
L923:
	movl	%eax, (%esp)
LEHB83:
	call	__ZSt20__throw_system_errori
LEHE83:
	.cfi_endproc
LFE2521:
	.section	.gcc_except_table,"w"
LLSDA2521:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2521-LLSDACSB2521
LLSDACSB2521:
	.uleb128 LEHB81-LFB2521
	.uleb128 LEHE81-LEHB81
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB82-LFB2521
	.uleb128 LEHE82-LEHB82
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB83-LFB2521
	.uleb128 LEHE83-LEHB83
	.uleb128 0
	.uleb128 0
LLSDACSE2521:
	.text
	.p2align 4,,15
	.globl	__Z13dequeueNormalR6data_t
	.def	__Z13dequeueNormalR6data_t;	.scl	2;	.type	32;	.endef
__Z13dequeueNormalR6data_t:
LFB2522:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2522
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_queue+264, (%esp)
LEHB84:
	call	_pthread_mutex_lock
LEHE84:
	testl	%eax, %eax
	jne	L942
	movl	__ZL7s_queue+256, %esi
	cmpl	__ZL7s_queue+260, %esi
	je	L937
	movl	(%esi), %ebx
	movl	$__ZL7s_queue+252, (%esp)
LEHB85:
	call	_pthread_mutex_lock
LEHE85:
	testl	%eax, %eax
	jne	L943
	subl	$__ZL7s_queue, %esi
	movl	$-1431655765, %ecx
	movl	%esi, %eax
	mull	%ecx
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L944
	movl	__ZL7s_queue+248, %esi
	movl	$1, %eax
	movl	%edx, %ecx
	sall	%cl, %eax
	testl	%esi, %eax
	je	L945
	movl	__ZL7s_queue+244, %edi
	notl	%eax
	leal	(%edx,%edx,2), %ecx
	andl	%esi, %eax
	movl	$__ZL7s_queue+252, (%esp)
	movl	%edi, __ZL7s_queue(,%ecx,4)
	movl	%edx, __ZL7s_queue+244
	movl	%eax, __ZL7s_queue+248
	call	_pthread_mutex_unlock
	movl	4(%ebx), %eax
	movl	8(%ebx), %edx
	movl	32(%esp), %ecx
	movl	%ebx, __ZL7s_queue+256
	movl	$1, %ebx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
L931:
	movl	$__ZL7s_queue+264, (%esp)
	call	_pthread_mutex_unlock
	addl	$16, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	movl	%ebx, %eax
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
	.p2align 4,,7
L937:
	.cfi_restore_state
	xorl	%ebx, %ebx
	jmp	L931
L943:
	movl	%eax, (%esp)
LEHB86:
	call	__ZSt20__throw_system_errori
LEHE86:
L938:
	movl	%eax, %ebx
L936:
	movl	$__ZL7s_queue+264, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, (%esp)
LEHB87:
	call	__Unwind_Resume
L942:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE87:
L945:
	movl	$LC2, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$287, 4(%esp)
	movl	$LC1, (%esp)
LEHB88:
	call	___assert_func
LEHE88:
L939:
	movl	$__ZL7s_queue+252, (%esp)
	movl	%eax, %ebx
	call	_pthread_mutex_unlock
	jmp	L936
L944:
	movl	$LC0, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$281, 4(%esp)
	movl	$LC1, (%esp)
LEHB89:
	call	___assert_func
LEHE89:
	.cfi_endproc
LFE2522:
	.section	.gcc_except_table,"w"
LLSDA2522:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2522-LLSDACSB2522
LLSDACSB2522:
	.uleb128 LEHB84-LFB2522
	.uleb128 LEHE84-LEHB84
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB85-LFB2522
	.uleb128 LEHE85-LEHB85
	.uleb128 L938-LFB2522
	.uleb128 0
	.uleb128 LEHB86-LFB2522
	.uleb128 LEHE86-LEHB86
	.uleb128 L938-LFB2522
	.uleb128 0
	.uleb128 LEHB87-LFB2522
	.uleb128 LEHE87-LEHB87
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB88-LFB2522
	.uleb128 LEHE88-LEHB88
	.uleb128 L939-LFB2522
	.uleb128 0
	.uleb128 LEHB89-LFB2522
	.uleb128 LEHE89-LEHB89
	.uleb128 L939-LFB2522
	.uleb128 0
LLSDACSE2522:
	.text
	.p2align 4,,15
	.globl	__Z15enqueueLockFreeO6data_t
	.def	__Z15enqueueLockFreeO6data_t;	.scl	2;	.type	32;	.endef
__Z15enqueueLockFreeO6data_t:
LFB2523:
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
	subl	$64, %esp
	.cfi_def_cfa_offset 84
	movl	__ZL9s_lfQueue+320, %eax
	cmpl	$19, %eax
	ja	L969
	movl	$1, %eax
	lock xaddl	%eax, __ZL9s_lfQueue+320
	cmpl	$19, %eax
	jbe	L970
	cmpl	$20, %eax
	jne	L971
	.p2align 4,,7
L969:
	movl	__ZL9s_lfQueue+324, %eax
	cmpl	$-1, %eax
	movl	%eax, 36(%esp)
	je	L953
L973:
	andl	$16777215, %eax
	cmpl	$19, %eax
	movl	%eax, %edx
	ja	L969
	sall	$4, %eax
	leal	__ZL9s_lfQueue(%eax), %ecx
	movl	__ZL9s_lfQueue(%eax), %ebx
	movl	36(%esp), %eax
	leal	36(%esp), %esi
	lock cmpxchgl	%ebx, __ZL9s_lfQueue+324
	movl	%eax, 36(%esp)
	je	L972
	movl	36(%esp), %eax
	cmpl	$-1, %eax
	jne	L973
L953:
	addl	$64, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	xorl	%ebp, %ebp
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	movl	%ebp, %eax
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
L972:
	.cfi_restore_state
	movl	$-16843010, (%ecx)
	addl	$320, %edx
	mfence
	lock subb	$1, __ZL9s_lfQueue+9(%edx)
	movl	%ecx, %edi
L950:
	movl	84(%esp), %eax
	movl	$1, %ebp
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%edx, 12(%edi)
	movl	%eax, 8(%edi)
	lock xaddl	%ebp, __ZL9s_lfQueue+368
	movl	%edi, %eax
	cltd
	xorl	%eax, %eax
	orl	%edx, %ebp
	xorl	%edx, %edx
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
	fildq	12(%esp)
	movl	%ebp, (%esp)
	fistpq	(%ecx)
	mfence
	movl	$0, 20(%esp)
	movl	$0, 24(%esp)
L960:
	fildq	__ZL9s_lfQueue+360
	fistpq	12(%esp)
	movl	12(%esp), %eax
	movl	16(%esp), %edx
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	fildq	(%eax)
	fistpq	12(%esp)
	movl	16(%esp), %ebx
	movl	12(%esp), %ecx
	movl	%ebx, %eax
	orl	%ecx, %eax
	movl	%ecx, 4(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 36(%esp)
	movl	%ebx, 40(%esp)
	jne	L957
	fildq	__ZL9s_lfQueue+360
	movl	%edi, %ebx
	fistpq	12(%esp)
	movl	12(%esp), %eax
	movl	4(%esi), %edx
	movl	(%esp), %ecx
	movl	%eax, %ebp
	movl	(%esi), %eax
	lock cmpxchg8b	0(%ebp)
	sete	%cl
	testb	%cl, %cl
	movl	%ecx, %ebp
	movl	%eax, (%esi)
	movl	%edx, 4(%esi)
	je	L960
	movl	24(%esp), %edx
	movl	%edi, %ebx
	movl	20(%esp), %eax
	movl	(%esp), %ecx
	lock cmpxchg8b	__ZL9s_lfQueue+360
	addl	$64, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	%ebp, %eax
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
	.p2align 4,,7
L957:
	.cfi_restore_state
	movl	24(%esp), %edx
	movl	20(%esp), %eax
	movl	4(%esp), %ebx
	movl	8(%esp), %ecx
	lock cmpxchg8b	__ZL9s_lfQueue+360
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	jmp	L960
L971:
	movl	$20, __ZL9s_lfQueue+320
	mfence
	jmp	L969
L970:
	leal	320(%eax), %edx
	lock addb	$1, __ZL9s_lfQueue+9(%edx)
	sall	$4, %eax
	leal	__ZL9s_lfQueue(%eax), %edi
	movl	%edi, %ecx
	leal	36(%esp), %esi
	jmp	L950
	.cfi_endproc
LFE2523:
	.p2align 4,,15
	.globl	__Z15enqueueLockFreeR6data_t
	.def	__Z15enqueueLockFreeR6data_t;	.scl	2;	.type	32;	.endef
__Z15enqueueLockFreeR6data_t:
LFB2524:
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
	subl	$64, %esp
	.cfi_def_cfa_offset 84
	movl	__ZL9s_lfQueue+320, %eax
	cmpl	$19, %eax
	ja	L997
	movl	$1, %eax
	lock xaddl	%eax, __ZL9s_lfQueue+320
	cmpl	$19, %eax
	jbe	L998
	cmpl	$20, %eax
	jne	L999
	.p2align 4,,7
L997:
	movl	__ZL9s_lfQueue+324, %eax
	cmpl	$-1, %eax
	movl	%eax, 36(%esp)
	je	L981
L1001:
	andl	$16777215, %eax
	cmpl	$19, %eax
	movl	%eax, %edx
	ja	L997
	sall	$4, %eax
	leal	__ZL9s_lfQueue(%eax), %ecx
	movl	__ZL9s_lfQueue(%eax), %ebx
	movl	36(%esp), %eax
	leal	36(%esp), %esi
	lock cmpxchgl	%ebx, __ZL9s_lfQueue+324
	movl	%eax, 36(%esp)
	je	L1000
	movl	36(%esp), %eax
	cmpl	$-1, %eax
	jne	L1001
L981:
	addl	$64, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	xorl	%ebp, %ebp
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	movl	%ebp, %eax
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
L1000:
	.cfi_restore_state
	movl	$-16843010, (%ecx)
	addl	$320, %edx
	mfence
	lock subb	$1, __ZL9s_lfQueue+9(%edx)
	movl	%ecx, %edi
L978:
	movl	84(%esp), %eax
	movl	$1, %ebp
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%edx, 12(%edi)
	movl	%eax, 8(%edi)
	lock xaddl	%ebp, __ZL9s_lfQueue+368
	movl	%edi, %eax
	cltd
	xorl	%eax, %eax
	orl	%edx, %ebp
	xorl	%edx, %edx
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
	fildq	12(%esp)
	movl	%ebp, (%esp)
	fistpq	(%ecx)
	mfence
	movl	$0, 20(%esp)
	movl	$0, 24(%esp)
L988:
	fildq	__ZL9s_lfQueue+360
	fistpq	12(%esp)
	movl	12(%esp), %eax
	movl	16(%esp), %edx
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	fildq	(%eax)
	fistpq	12(%esp)
	movl	16(%esp), %ebx
	movl	12(%esp), %ecx
	movl	%ebx, %eax
	orl	%ecx, %eax
	movl	%ecx, 4(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 36(%esp)
	movl	%ebx, 40(%esp)
	jne	L985
	fildq	__ZL9s_lfQueue+360
	movl	%edi, %ebx
	fistpq	12(%esp)
	movl	12(%esp), %eax
	movl	4(%esi), %edx
	movl	(%esp), %ecx
	movl	%eax, %ebp
	movl	(%esi), %eax
	lock cmpxchg8b	0(%ebp)
	sete	%cl
	testb	%cl, %cl
	movl	%ecx, %ebp
	movl	%eax, (%esi)
	movl	%edx, 4(%esi)
	je	L988
	movl	24(%esp), %edx
	movl	%edi, %ebx
	movl	20(%esp), %eax
	movl	(%esp), %ecx
	lock cmpxchg8b	__ZL9s_lfQueue+360
	addl	$64, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	%ebp, %eax
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
	.p2align 4,,7
L985:
	.cfi_restore_state
	movl	24(%esp), %edx
	movl	20(%esp), %eax
	movl	4(%esp), %ebx
	movl	8(%esp), %ecx
	lock cmpxchg8b	__ZL9s_lfQueue+360
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	jmp	L988
L999:
	movl	$20, __ZL9s_lfQueue+320
	mfence
	jmp	L997
L998:
	leal	320(%eax), %edx
	lock addb	$1, __ZL9s_lfQueue+9(%edx)
	sall	$4, %eax
	leal	__ZL9s_lfQueue(%eax), %edi
	movl	%edi, %ecx
	leal	36(%esp), %esi
	jmp	L978
	.cfi_endproc
LFE2524:
	.p2align 4,,15
	.globl	__Z15dequeueLockFreeR6data_t
	.def	__Z15dequeueLockFreeR6data_t;	.scl	2;	.type	32;	.endef
__Z15dequeueLockFreeR6data_t:
LFB2525:
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
	movl	$0, 48(%esp)
	movl	$0, 52(%esp)
	movl	$0, 64(%esp)
	movl	$0, 68(%esp)
L1003:
	fildq	__ZL9s_lfQueue+352
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	fildq	__ZL9s_lfQueue+360
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	48(%esp), %esi
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	fildq	(%esi)
	movl	64(%esp), %edx
	fistpq	24(%esp)
	movl	52(%esp), %eax
	xorl	68(%esp), %eax
	movl	24(%esp), %edi
	xorl	%esi, %edx
	movl	28(%esp), %ebp
	orl	%edx, %eax
	jne	L1004
	movl	%ebp, %eax
	orl	%edi, %eax
	je	L1011
	movl	68(%esp), %edx
	movl	%edi, %ebx
	movl	%ebp, %ecx
	movl	64(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfQueue+360
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	jmp	L1003
	.p2align 4,,7
L1004:
	movl	52(%esp), %edx
	movl	%edi, %ebx
	movl	%ebp, %ecx
	movl	48(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfQueue+352
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	jne	L1003
	movl	8(%edi), %eax
	subl	$__ZL9s_lfQueue, %esi
	movl	12(%edi), %edx
	shrl	$4, %esi
	movl	112(%esp), %ecx
	cmpl	$19, %esi
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	ja	L1016
	movzbl	__ZL9s_lfQueue+329(%esi), %eax
	leal	__ZL9s_lfQueue+329(%esi), %ebx
	testb	%al, %al
	je	L1017
	movl	$1, %ecx
	lock xaddb	%cl, __ZL9s_lfQueue+328
	movl	__ZL9s_lfQueue+324, %eax
	sall	$24, %ecx
	orl	%esi, %ecx
	sall	$4, %esi
	movl	%eax, 32(%esp)
	addl	$__ZL9s_lfQueue, %esi
	.p2align 4,,7
L1010:
	movl	%eax, (%esi)
	mfence
	movl	32(%esp), %eax
	lock cmpxchgl	%ecx, __ZL9s_lfQueue+324
	sete	%dl
	testb	%dl, %dl
	movl	%eax, 32(%esp)
	je	L1010
	lock subb	$1, (%ebx)
L1005:
	addl	$92, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	%edx, %eax
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
L1011:
	.cfi_restore_state
	xorl	%edx, %edx
	jmp	L1005
L1017:
	movl	$LC2, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$561, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
L1016:
	movl	$LC0, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$555, 4(%esp)
	movl	$LC1, (%esp)
	call	___assert_func
	.cfi_endproc
LFE2525:
	.section .rdata,"dr"
	.align 4
LC4:
	.ascii "================================================================================\0"
	.align 4
LC5:
	.ascii "[Test for Lock-free pool-allocator/stack/queue]\0"
	.align 4
LC6:
	.ascii "--------------------------------------------------------------------------------\0"
LC7:
	.ascii "Normal Pool-allocator\0"
LC8:
	.ascii "[%s:START]\12\0"
	.align 4
LC9:
	.ascii "*Test count                     = %d\12\0"
	.align 4
LC10:
	.ascii "*Allocate and free test threads = %d\12\0"
	.align 4
LC11:
	.ascii "*Memory pool size               = %d\12\0"
	.align 4
LC13:
	.ascii "[%s:END] elapsed_time=%.9llf sec\12\0"
LC14:
	.ascii "Lock-Free Pool-allocator\0"
LC15:
	.ascii "Normal Stack\0"
	.align 4
LC16:
	.ascii "*Test count                = %d\12\0"
	.align 4
LC17:
	.ascii "*Push/Enqueue test threads = %d\12\0"
	.align 4
LC18:
	.ascii "*Pop/Dequeue  test threads = %d\12\0"
	.align 4
LC19:
	.ascii "*Memory pool size          = %d\12\0"
LC20:
	.ascii "Lock-Free Stack\0"
LC21:
	.ascii "Normal Queue\0"
LC22:
	.ascii "Lock-Free Queue\0"
	.text
	.p2align 4,,15
	.globl	__Z8easyTestv
	.def	__Z8easyTestv;	.scl	2;	.type	32;	.endef
__Z8easyTestv:
LFB2526:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2526
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
	subl	$204, %esp
	.cfi_def_cfa_offset 224
	movl	$LC4, (%esp)
LEHB90:
	call	_puts
	movl	$LC5, (%esp)
	call	_puts
LEHE90:
	movl	$1, (%esp)
	movl	$0, 88(%esp)
LEHB91:
	call	__Znwj
LEHE91:
	movl	$1, (%esp)
	movl	%eax, 80(%esp)
	movl	$__ZNSt17_Function_handlerIFbP6data_tEZ8easyTestvEUlS1_E3_E9_M_invokeERKSt9_Any_dataS1_, 92(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlP6data_tE3_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 88(%esp)
	movl	$0, 72(%esp)
LEHB92:
	call	__Znwj
LEHE92:
	movl	$LC6, (%esp)
	movl	%eax, 64(%esp)
	movl	$__ZNSt17_Function_handlerIFP6data_tvEZ8easyTestvEUlvE2_E9_M_invokeERKSt9_Any_data, 76(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlvE2_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation, 72(%esp)
LEHB93:
	call	_puts
LEHE93:
	movl	$LC7, 4(%esp)
	movl	$LC8, (%esp)
LEHB94:
	call	_printf
LEHE94:
	movl	$100000, 4(%esp)
	movl	$LC9, (%esp)
LEHB95:
	call	_printf
LEHE95:
	movl	$1, 4(%esp)
	movl	$LC10, (%esp)
LEHB96:
	call	_printf
LEHE96:
	movl	$20, 4(%esp)
	movl	$LC11, (%esp)
LEHB97:
	call	_printf
LEHE97:
	call	__ZNSt6chrono3_V212system_clock3nowEv
	leal	96(%esp), %esi
	movl	$21, %ecx
	movl	%esi, %edi
	xorl	%ebx, %ebx
	movl	$0, 24(%esp)
	leal	80(%esp), %ebp
	movl	%eax, 32(%esp)
	xorl	%eax, %eax
	rep stosl
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1035:
	movl	72(%esp), %ecx
	leal	1(%ebx), %edi
	testl	%ecx, %ecx
	je	L1526
	leal	64(%esp), %eax
	movl	%eax, (%esp)
LEHB98:
	call	*76(%esp)
LEHE98:
	testl	%eax, %eax
	movl	%eax, 96(%esp,%ebx,4)
	je	L1039
	movl	24(%esp), %ecx
	movl	$0, (%eax)
	leal	1(%ecx), %edx
	cmpl	$100000, %edx
	movl	%ecx, 4(%eax)
	jle	L1261
	movl	%edx, 24(%esp)
L1039:
	xorl	%ebx, %ebx
	.p2align 4,,7
L1048:
	movl	(%esi,%ebx,4), %eax
	testl	%eax, %eax
	je	L1046
	movl	88(%esp), %edx
	testl	%edx, %edx
	je	L1527
	movl	%eax, 4(%esp)
	movl	%ebp, (%esp)
LEHB99:
	call	*92(%esp)
LEHE99:
L1046:
	addl	$1, %ebx
	cmpl	%ebx, %edi
	jg	L1048
	cmpl	$100000, 24(%esp)
	jg	L1528
	xorl	%ebx, %ebx
	jmp	L1035
	.p2align 4,,7
L1261:
	movl	%edi, %ebx
	movl	%edx, 24(%esp)
	jmp	L1035
L1528:
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, 4(%esp)
	movl	$LC13, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC12
	fstpl	8(%esp)
LEHB100:
	call	_printf
LEHE100:
	movl	$LC6, (%esp)
LEHB101:
	call	_puts
LEHE101:
	movl	72(%esp), %eax
	testl	%eax, %eax
	je	L1053
	leal	64(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1053:
	movl	88(%esp), %eax
	testl	%eax, %eax
	je	L1054
	leal	80(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1054:
	movl	$1, (%esp)
	movl	$0, 88(%esp)
LEHB102:
	call	__Znwj
LEHE102:
	movl	$1, (%esp)
	movl	%eax, 80(%esp)
	movl	$__ZNSt17_Function_handlerIFbP6data_tEZ8easyTestvEUlS1_E5_E9_M_invokeERKSt9_Any_dataS1_, 92(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlP6data_tE5_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 88(%esp)
	movl	$0, 72(%esp)
LEHB103:
	call	__Znwj
LEHE103:
	movl	$LC6, (%esp)
	movl	%eax, 64(%esp)
	movl	$__ZNSt17_Function_handlerIFP6data_tvEZ8easyTestvEUlvE4_E9_M_invokeERKSt9_Any_data, 76(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlvE4_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation, 72(%esp)
LEHB104:
	call	_puts
LEHE104:
	movl	$LC14, 4(%esp)
	movl	$LC8, (%esp)
LEHB105:
	call	_printf
LEHE105:
	movl	$100000, 4(%esp)
	movl	$LC9, (%esp)
LEHB106:
	call	_printf
LEHE106:
	movl	$1, 4(%esp)
	movl	$LC10, (%esp)
LEHB107:
	call	_printf
LEHE107:
	movl	$20, 4(%esp)
	movl	$LC11, (%esp)
LEHB108:
	call	_printf
LEHE108:
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%esi, %edi
	movl	$21, %ecx
	xorl	%ebx, %ebx
	movl	$0, 24(%esp)
	leal	80(%esp), %ebp
	movl	%eax, 32(%esp)
	xorl	%eax, %eax
	rep stosl
	movl	%edx, 36(%esp)
	.p2align 4,,7
L1071:
	movl	72(%esp), %ecx
	leal	1(%ebx), %edi
	testl	%ecx, %ecx
	je	L1529
	leal	64(%esp), %eax
	movl	%eax, (%esp)
LEHB109:
	call	*76(%esp)
LEHE109:
	testl	%eax, %eax
	movl	%eax, 96(%esp,%ebx,4)
	je	L1075
	movl	24(%esp), %ecx
	movl	$0, (%eax)
	movl	%ecx, %edx
	addl	$1, %edx
	cmpl	$100000, %edx
	movl	%ecx, 4(%eax)
	jle	L1263
	movl	%edx, 24(%esp)
L1075:
	xorl	%ebx, %ebx
	.p2align 4,,7
L1084:
	movl	(%esi,%ebx,4), %eax
	testl	%eax, %eax
	je	L1082
	movl	88(%esp), %edx
	testl	%edx, %edx
	je	L1530
	movl	%eax, 4(%esp)
	movl	%ebp, (%esp)
LEHB110:
	call	*92(%esp)
LEHE110:
L1082:
	addl	$1, %ebx
	cmpl	%ebx, %edi
	jg	L1084
	cmpl	$100000, 24(%esp)
	jg	L1531
	xorl	%ebx, %ebx
	jmp	L1071
	.p2align 4,,7
L1263:
	movl	%edi, %ebx
	movl	%edx, 24(%esp)
	jmp	L1071
L1531:
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC14, 4(%esp)
	movl	$LC13, (%esp)
	subl	32(%esp), %eax
	sbbl	36(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC12
	fstpl	8(%esp)
LEHB111:
	call	_printf
LEHE111:
	movl	$LC6, (%esp)
LEHB112:
	call	_puts
LEHE112:
	movl	72(%esp), %eax
	testl	%eax, %eax
	je	L1089
	leal	64(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1089:
	movl	88(%esp), %eax
	testl	%eax, %eax
	je	L1090
	leal	80(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1090:
	movl	$1, (%esp)
	movl	$0, 104(%esp)
LEHB113:
	call	__Znwj
LEHE113:
	movl	$1, (%esp)
	movl	%eax, 96(%esp)
	movl	$__ZNSt17_Function_handlerIFbR6data_tEZ8easyTestvEUlS1_E7_E9_M_invokeERKSt9_Any_dataS1_, 108(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlR6data_tE7_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 104(%esp)
	movl	$0, 88(%esp)
LEHB114:
	call	__Znwj
LEHE114:
	movl	$LC6, (%esp)
	movl	%eax, 80(%esp)
	movl	$__ZNSt17_Function_handlerIFbO6data_tEZ8easyTestvEUlS1_E6_E9_M_invokeERKSt9_Any_dataS1_, 92(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlO6data_tE6_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 88(%esp)
LEHB115:
	call	_puts
LEHE115:
	movl	$LC15, 4(%esp)
	movl	$LC8, (%esp)
LEHB116:
	call	_printf
LEHE116:
	movl	$100000, 4(%esp)
	movl	$LC16, (%esp)
LEHB117:
	call	_printf
LEHE117:
	movl	$1, 4(%esp)
	movl	$LC17, (%esp)
LEHB118:
	call	_printf
LEHE118:
	movl	$1, 4(%esp)
	movl	$LC18, (%esp)
LEHB119:
	call	_printf
LEHE119:
	movl	$20, 4(%esp)
	movl	$LC19, (%esp)
LEHB120:
	call	_printf
LEHE120:
	call	__ZNSt6chrono3_V212system_clock3nowEv
	xorl	%ebp, %ebp
	leal	80(%esp), %edi
	leal	48(%esp), %ebx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	.p2align 4,,7
L1109:
	movl	88(%esp), %eax
	movl	$0, 68(%esp)
	movl	%ebp, 64(%esp)
	testl	%eax, %eax
	je	L1532
	leal	64(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
LEHB121:
	call	*92(%esp)
LEHE121:
	testb	%al, %al
	je	L1485
	addl	$1, %ebp
	cmpl	$100000, %ebp
	jle	L1109
	.p2align 4,,7
L1485:
	movl	104(%esp), %eax
	testl	%eax, %eax
	je	L1533
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
LEHB122:
	call	*108(%esp)
LEHE122:
	testb	%al, %al
	jne	L1485
	cmpl	$100000, %ebp
	jle	L1109
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC15, 4(%esp)
	movl	$LC13, (%esp)
	subl	24(%esp), %eax
	sbbl	28(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC12
	fstpl	8(%esp)
LEHB123:
	call	_printf
LEHE123:
	movl	$LC6, (%esp)
LEHB124:
	call	_puts
LEHE124:
	movl	88(%esp), %eax
	testl	%eax, %eax
	je	L1127
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L1127:
	movl	104(%esp), %eax
	testl	%eax, %eax
	je	L1128
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
L1128:
	movl	$1, (%esp)
	movl	$0, 104(%esp)
LEHB125:
	call	__Znwj
LEHE125:
	movl	$1, (%esp)
	movl	%eax, 96(%esp)
	movl	$__ZNSt17_Function_handlerIFbR6data_tEZ8easyTestvEUlS1_E9_E9_M_invokeERKSt9_Any_dataS1_, 108(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlR6data_tE9_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 104(%esp)
	movl	$0, 88(%esp)
LEHB126:
	call	__Znwj
LEHE126:
	movl	$LC6, (%esp)
	movl	%eax, 80(%esp)
	movl	$__ZNSt17_Function_handlerIFbO6data_tEZ8easyTestvEUlS1_E8_E9_M_invokeERKSt9_Any_dataS1_, 92(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlO6data_tE8_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 88(%esp)
LEHB127:
	call	_puts
LEHE127:
	movl	$LC20, 4(%esp)
	movl	$LC8, (%esp)
LEHB128:
	call	_printf
LEHE128:
	movl	$100000, 4(%esp)
	movl	$LC16, (%esp)
LEHB129:
	call	_printf
LEHE129:
	movl	$1, 4(%esp)
	movl	$LC17, (%esp)
LEHB130:
	call	_printf
LEHE130:
	movl	$1, 4(%esp)
	movl	$LC18, (%esp)
LEHB131:
	call	_printf
LEHE131:
	movl	$20, 4(%esp)
	movl	$LC19, (%esp)
LEHB132:
	call	_printf
LEHE132:
	call	__ZNSt6chrono3_V212system_clock3nowEv
	xorl	%ebp, %ebp
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	.p2align 4,,7
L1147:
	movl	88(%esp), %eax
	movl	$0, 68(%esp)
	movl	%ebp, 64(%esp)
	testl	%eax, %eax
	je	L1534
	leal	64(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
LEHB133:
	call	*92(%esp)
LEHE133:
	testb	%al, %al
	je	L1494
	addl	$1, %ebp
	cmpl	$100000, %ebp
	jle	L1147
	.p2align 4,,7
L1494:
	movl	104(%esp), %eax
	testl	%eax, %eax
	je	L1535
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
LEHB134:
	call	*108(%esp)
LEHE134:
	testb	%al, %al
	jne	L1494
	cmpl	$100000, %ebp
	jle	L1147
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC20, 4(%esp)
	movl	$LC13, (%esp)
	subl	24(%esp), %eax
	sbbl	28(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC12
	fstpl	8(%esp)
LEHB135:
	call	_printf
LEHE135:
	movl	$LC6, (%esp)
LEHB136:
	call	_puts
LEHE136:
	movl	88(%esp), %eax
	testl	%eax, %eax
	je	L1165
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L1165:
	movl	104(%esp), %eax
	testl	%eax, %eax
	je	L1166
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
L1166:
	movl	$1, (%esp)
	movl	$0, 104(%esp)
LEHB137:
	call	__Znwj
LEHE137:
	movl	$1, (%esp)
	movl	%eax, 96(%esp)
	movl	$__ZNSt17_Function_handlerIFbR6data_tEZ8easyTestvEUlS1_E11_E9_M_invokeERKSt9_Any_dataS1_, 108(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlR6data_tE11_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 104(%esp)
	movl	$0, 88(%esp)
LEHB138:
	call	__Znwj
LEHE138:
	movl	$LC6, (%esp)
	movl	%eax, 80(%esp)
	movl	$__ZNSt17_Function_handlerIFbO6data_tEZ8easyTestvEUlS1_E10_E9_M_invokeERKSt9_Any_dataS1_, 92(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlO6data_tE10_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 88(%esp)
LEHB139:
	call	_puts
LEHE139:
	movl	$LC21, 4(%esp)
	movl	$LC8, (%esp)
LEHB140:
	call	_printf
LEHE140:
	movl	$100000, 4(%esp)
	movl	$LC16, (%esp)
LEHB141:
	call	_printf
LEHE141:
	movl	$1, 4(%esp)
	movl	$LC17, (%esp)
LEHB142:
	call	_printf
LEHE142:
	movl	$1, 4(%esp)
	movl	$LC18, (%esp)
LEHB143:
	call	_printf
LEHE143:
	movl	$20, 4(%esp)
	movl	$LC19, (%esp)
LEHB144:
	call	_printf
LEHE144:
	call	__ZNSt6chrono3_V212system_clock3nowEv
	xorl	%ebp, %ebp
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	.p2align 4,,7
L1185:
	movl	88(%esp), %eax
	movl	$0, 68(%esp)
	movl	%ebp, 64(%esp)
	testl	%eax, %eax
	je	L1536
	leal	64(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
LEHB145:
	call	*92(%esp)
LEHE145:
	testb	%al, %al
	je	L1503
	addl	$1, %ebp
	cmpl	$100000, %ebp
	jle	L1185
	.p2align 4,,7
L1503:
	movl	104(%esp), %ecx
	testl	%ecx, %ecx
	je	L1537
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
LEHB146:
	call	*108(%esp)
LEHE146:
	testb	%al, %al
	jne	L1503
	cmpl	$100000, %ebp
	jle	L1185
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC21, 4(%esp)
	movl	$LC13, (%esp)
	subl	24(%esp), %eax
	sbbl	28(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC12
	fstpl	8(%esp)
LEHB147:
	call	_printf
LEHE147:
	movl	$LC6, (%esp)
LEHB148:
	call	_puts
LEHE148:
	movl	88(%esp), %eax
	testl	%eax, %eax
	je	L1203
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L1203:
	movl	104(%esp), %eax
	testl	%eax, %eax
	je	L1204
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
L1204:
	movl	$1, (%esp)
	movl	$0, 104(%esp)
LEHB149:
	call	__Znwj
LEHE149:
	movl	$1, (%esp)
	movl	%eax, 96(%esp)
	movl	$__ZNSt17_Function_handlerIFbR6data_tEZ8easyTestvEUlS1_E13_E9_M_invokeERKSt9_Any_dataS1_, 108(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlR6data_tE13_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 104(%esp)
	movl	$0, 88(%esp)
LEHB150:
	call	__Znwj
LEHE150:
	movl	$LC6, (%esp)
	movl	%eax, 80(%esp)
	movl	$__ZNSt17_Function_handlerIFbO6data_tEZ8easyTestvEUlS1_E12_E9_M_invokeERKSt9_Any_dataS1_, 92(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ8easyTestvEUlO6data_tE12_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 88(%esp)
LEHB151:
	call	_puts
LEHE151:
	movl	$LC22, 4(%esp)
	movl	$LC8, (%esp)
LEHB152:
	call	_printf
LEHE152:
	movl	$100000, 4(%esp)
	movl	$LC16, (%esp)
LEHB153:
	call	_printf
LEHE153:
	movl	$1, 4(%esp)
	movl	$LC17, (%esp)
LEHB154:
	call	_printf
LEHE154:
	movl	$1, 4(%esp)
	movl	$LC18, (%esp)
LEHB155:
	call	_printf
LEHE155:
	movl	$20, 4(%esp)
	movl	$LC19, (%esp)
LEHB156:
	call	_printf
LEHE156:
	call	__ZNSt6chrono3_V212system_clock3nowEv
	xorl	%ebp, %ebp
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	.p2align 4,,7
L1223:
	movl	88(%esp), %edx
	movl	$0, 68(%esp)
	movl	%ebp, 64(%esp)
	testl	%edx, %edx
	je	L1538
	leal	64(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
LEHB157:
	call	*92(%esp)
LEHE157:
	testb	%al, %al
	je	L1512
	addl	$1, %ebp
	cmpl	$100000, %ebp
	jle	L1223
	.p2align 4,,7
L1512:
	movl	104(%esp), %eax
	testl	%eax, %eax
	je	L1539
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
LEHB158:
	call	*108(%esp)
LEHE158:
	testb	%al, %al
	jne	L1512
	cmpl	$100000, %ebp
	jle	L1223
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC22, 4(%esp)
	movl	$LC13, (%esp)
	subl	24(%esp), %eax
	sbbl	28(%esp), %edx
	movl	%eax, 40(%esp)
	movl	%edx, 44(%esp)
	fildq	40(%esp)
	fdivs	LC12
	fstpl	8(%esp)
LEHB159:
	call	_printf
LEHE159:
	movl	$LC6, (%esp)
LEHB160:
	call	_puts
LEHE160:
	movl	88(%esp), %eax
	testl	%eax, %eax
	je	L1241
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L1241:
	movl	104(%esp), %eax
	testl	%eax, %eax
	je	L1018
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
L1018:
	addl	$204, %esp
	.cfi_remember_state
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
L1527:
	.cfi_restore_state
LEHB161:
	call	__ZSt25__throw_bad_function_callv
LEHE161:
L1530:
LEHB162:
	call	__ZSt25__throw_bad_function_callv
LEHE162:
L1533:
	.p2align 4,,5
LEHB163:
	call	__ZSt25__throw_bad_function_callv
LEHE163:
L1535:
	.p2align 4,,5
LEHB164:
	call	__ZSt25__throw_bad_function_callv
LEHE164:
L1290:
L1520:
	movl	%eax, %ebx
	movl	72(%esp), %eax
	testl	%eax, %eax
	je	L1025
	leal	64(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1025:
	movl	88(%esp), %eax
	testl	%eax, %eax
	je	L1260
	leal	80(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1260:
	movl	%ebx, (%esp)
LEHB165:
	call	__Unwind_Resume
LEHE165:
L1322:
L1523:
	movl	%eax, %ebx
	movl	88(%esp), %eax
	testl	%eax, %eax
	je	L1135
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L1135:
	movl	104(%esp), %eax
	testl	%eax, %eax
	je	L1260
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
	jmp	L1260
L1311:
L1522:
	movl	%eax, %ebx
	movl	88(%esp), %eax
	testl	%eax, %eax
	je	L1097
	leal	80(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1097:
	movl	104(%esp), %eax
	testl	%eax, %eax
	je	L1260
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
	jmp	L1260
L1300:
L1521:
	movl	%eax, %ebx
	movl	72(%esp), %eax
	testl	%eax, %eax
	je	L1061
	leal	64(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1061:
	movl	88(%esp), %eax
	testl	%eax, %eax
	je	L1260
	leal	80(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
	jmp	L1260
	.p2align 4,,7
L1539:
LEHB166:
	call	__ZSt25__throw_bad_function_callv
LEHE166:
L1344:
L1525:
	movl	%eax, %ebx
	movl	88(%esp), %eax
	testl	%eax, %eax
	je	L1211
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L1211:
	movl	104(%esp), %eax
	testl	%eax, %eax
	je	L1260
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
	jmp	L1260
	.p2align 4,,7
L1537:
LEHB167:
	call	__ZSt25__throw_bad_function_callv
LEHE167:
L1333:
L1524:
	movl	%eax, %ebx
	movl	88(%esp), %eax
	testl	%eax, %eax
	je	L1173
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%eax
L1173:
	movl	104(%esp), %eax
	testl	%eax, %eax
	je	L1260
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
	jmp	L1260
L1335:
	jmp	L1524
L1291:
	.p2align 4,,11
	jmp	L1520
L1267:
	.p2align 4,,11
	jmp	L1522
L1278:
	movl	88(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	.p2align 4,,3
	je	L1135
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%edx
	jmp	L1135
L1308:
	jmp	L1522
L1307:
	.p2align 4,,11
	jmp	L1522
L1306:
	.p2align 4,,11
	jmp	L1522
L1305:
	.p2align 4,,11
	jmp	L1522
L1304:
	.p2align 4,,11
	jmp	L1522
L1303:
	.p2align 4,,11
	jmp	L1522
L1276:
	movl	88(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	.p2align 4,,3
	je	L1097
	leal	80(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L1097
L1277:
	movl	104(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1260
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%edx
	jmp	L1260
L1289:
	jmp	L1520
L1323:
	.p2align 4,,11
	jmp	L1523
L1268:
	.p2align 4,,11
	jmp	L1523
L1324:
	.p2align 4,,11
	jmp	L1523
L1326:
	.p2align 4,,11
	jmp	L1524
L1325:
	.p2align 4,,11
	jmp	L1524
L1280:
	movl	88(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	.p2align 4,,3
	je	L1173
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%edx
	jmp	L1173
L1279:
	movl	104(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1260
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%edx
	jmp	L1260
L1321:
	jmp	L1523
L1534:
	.p2align 4,,11
LEHB168:
	call	__ZSt25__throw_bad_function_callv
LEHE168:
L1319:
	.p2align 4,,8
	jmp	L1523
L1318:
	.p2align 4,,8
	jmp	L1523
L1320:
	movl	%eax, %ebx
	.p2align 4,,9
	jmp	L1135
L1317:
	.p2align 4,,9
	jmp	L1523
L1316:
	.p2align 4,,9
	jmp	L1523
L1315:
	.p2align 4,,11
	jmp	L1523
L1314:
	.p2align 4,,11
	jmp	L1523
L1312:
	.p2align 4,,11
	jmp	L1522
L1301:
	.p2align 4,,11
	jmp	L1521
L1266:
	.p2align 4,,11
	jmp	L1521
L1302:
	.p2align 4,,11
	jmp	L1521
L1299:
	.p2align 4,,11
	jmp	L1521
L1529:
	.p2align 4,,11
LEHB169:
	call	__ZSt25__throw_bad_function_callv
LEHE169:
L1297:
	.p2align 4,,8
	jmp	L1521
L1296:
	.p2align 4,,8
	jmp	L1521
L1298:
	movl	%eax, %ebx
	.p2align 4,,9
	jmp	L1061
L1295:
	.p2align 4,,9
	jmp	L1521
L1294:
	.p2align 4,,9
	jmp	L1521
L1293:
	.p2align 4,,11
	jmp	L1521
L1274:
	movl	72(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	.p2align 4,,3
	je	L1061
	leal	64(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
	jmp	L1061
L1273:
	movl	88(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1260
	leal	80(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L1260
L1265:
	jmp	L1520
L1292:
	.p2align 4,,11
	jmp	L1520
L1313:
	.p2align 4,,11
	jmp	L1522
L1310:
	.p2align 4,,11
	jmp	L1522
L1532:
	.p2align 4,,11
LEHB170:
	call	__ZSt25__throw_bad_function_callv
LEHE170:
L1270:
	.p2align 4,,8
	jmp	L1525
L1346:
	.p2align 4,,8
	jmp	L1525
L1309:
	movl	%eax, %ebx
	.p2align 4,,9
	jmp	L1097
L1343:
	.p2align 4,,9
	jmp	L1525
L1538:
	.p2align 4,,9
LEHB171:
	call	__ZSt25__throw_bad_function_callv
LEHE171:
L1341:
	.p2align 4,,8
	jmp	L1525
L1340:
	.p2align 4,,8
	jmp	L1525
L1342:
	movl	%eax, %ebx
	.p2align 4,,9
	jmp	L1211
L1526:
	.p2align 4,,9
LEHB172:
	call	__ZSt25__throw_bad_function_callv
LEHE172:
L1287:
	.p2align 4,,6
	jmp	L1520
L1288:
	movl	%eax, %ebx
	.p2align 4,,6
	jmp	L1025
L1286:
	.p2align 4,,9
	jmp	L1520
L1285:
	.p2align 4,,9
	jmp	L1520
L1284:
	.p2align 4,,11
	jmp	L1520
L1283:
	.p2align 4,,11
	jmp	L1520
L1272:
	movl	72(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	.p2align 4,,3
	je	L1025
	leal	64(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L1025
L1275:
	movl	104(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1260
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%edx
	jmp	L1260
L1345:
	jmp	L1525
L1334:
	.p2align 4,,11
	jmp	L1524
L1332:
	.p2align 4,,11
	jmp	L1524
L1536:
	.p2align 4,,11
LEHB173:
	call	__ZSt25__throw_bad_function_callv
LEHE173:
L1330:
	.p2align 4,,8
	jmp	L1524
L1328:
	.p2align 4,,8
	jmp	L1524
L1327:
	.p2align 4,,11
	jmp	L1524
L1329:
	.p2align 4,,11
	jmp	L1524
L1331:
	movl	%eax, %ebx
	.p2align 4,,9
	jmp	L1173
L1339:
	.p2align 4,,9
	jmp	L1525
L1338:
	.p2align 4,,9
	jmp	L1525
L1337:
	.p2align 4,,11
	jmp	L1525
L1336:
	.p2align 4,,11
	jmp	L1525
L1282:
	movl	88(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	.p2align 4,,3
	je	L1211
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	call	*%edx
	jmp	L1211
L1281:
	movl	104(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1260
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%edx
	jmp	L1260
L1269:
	jmp	L1524
L1271:
	movl	88(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	.p2align 4,,3
	je	L1260
	leal	80(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L1260
	.cfi_endproc
LFE2526:
	.section	.gcc_except_table,"w"
LLSDA2526:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2526-LLSDACSB2526
LLSDACSB2526:
	.uleb128 LEHB90-LFB2526
	.uleb128 LEHE90-LEHB90
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB91-LFB2526
	.uleb128 LEHE91-LEHB91
	.uleb128 L1271-LFB2526
	.uleb128 0
	.uleb128 LEHB92-LFB2526
	.uleb128 LEHE92-LEHB92
	.uleb128 L1272-LFB2526
	.uleb128 0
	.uleb128 LEHB93-LFB2526
	.uleb128 LEHE93-LEHB93
	.uleb128 L1283-LFB2526
	.uleb128 0
	.uleb128 LEHB94-LFB2526
	.uleb128 LEHE94-LEHB94
	.uleb128 L1284-LFB2526
	.uleb128 0
	.uleb128 LEHB95-LFB2526
	.uleb128 LEHE95-LEHB95
	.uleb128 L1285-LFB2526
	.uleb128 0
	.uleb128 LEHB96-LFB2526
	.uleb128 LEHE96-LEHB96
	.uleb128 L1286-LFB2526
	.uleb128 0
	.uleb128 LEHB97-LFB2526
	.uleb128 LEHE97-LEHB97
	.uleb128 L1287-LFB2526
	.uleb128 0
	.uleb128 LEHB98-LFB2526
	.uleb128 LEHE98-LEHB98
	.uleb128 L1289-LFB2526
	.uleb128 0
	.uleb128 LEHB99-LFB2526
	.uleb128 LEHE99-LEHB99
	.uleb128 L1291-LFB2526
	.uleb128 0
	.uleb128 LEHB100-LFB2526
	.uleb128 LEHE100-LEHB100
	.uleb128 L1292-LFB2526
	.uleb128 0
	.uleb128 LEHB101-LFB2526
	.uleb128 LEHE101-LEHB101
	.uleb128 L1265-LFB2526
	.uleb128 0
	.uleb128 LEHB102-LFB2526
	.uleb128 LEHE102-LEHB102
	.uleb128 L1273-LFB2526
	.uleb128 0
	.uleb128 LEHB103-LFB2526
	.uleb128 LEHE103-LEHB103
	.uleb128 L1274-LFB2526
	.uleb128 0
	.uleb128 LEHB104-LFB2526
	.uleb128 LEHE104-LEHB104
	.uleb128 L1293-LFB2526
	.uleb128 0
	.uleb128 LEHB105-LFB2526
	.uleb128 LEHE105-LEHB105
	.uleb128 L1294-LFB2526
	.uleb128 0
	.uleb128 LEHB106-LFB2526
	.uleb128 LEHE106-LEHB106
	.uleb128 L1295-LFB2526
	.uleb128 0
	.uleb128 LEHB107-LFB2526
	.uleb128 LEHE107-LEHB107
	.uleb128 L1296-LFB2526
	.uleb128 0
	.uleb128 LEHB108-LFB2526
	.uleb128 LEHE108-LEHB108
	.uleb128 L1297-LFB2526
	.uleb128 0
	.uleb128 LEHB109-LFB2526
	.uleb128 LEHE109-LEHB109
	.uleb128 L1299-LFB2526
	.uleb128 0
	.uleb128 LEHB110-LFB2526
	.uleb128 LEHE110-LEHB110
	.uleb128 L1301-LFB2526
	.uleb128 0
	.uleb128 LEHB111-LFB2526
	.uleb128 LEHE111-LEHB111
	.uleb128 L1302-LFB2526
	.uleb128 0
	.uleb128 LEHB112-LFB2526
	.uleb128 LEHE112-LEHB112
	.uleb128 L1266-LFB2526
	.uleb128 0
	.uleb128 LEHB113-LFB2526
	.uleb128 LEHE113-LEHB113
	.uleb128 L1275-LFB2526
	.uleb128 0
	.uleb128 LEHB114-LFB2526
	.uleb128 LEHE114-LEHB114
	.uleb128 L1276-LFB2526
	.uleb128 0
	.uleb128 LEHB115-LFB2526
	.uleb128 LEHE115-LEHB115
	.uleb128 L1303-LFB2526
	.uleb128 0
	.uleb128 LEHB116-LFB2526
	.uleb128 LEHE116-LEHB116
	.uleb128 L1304-LFB2526
	.uleb128 0
	.uleb128 LEHB117-LFB2526
	.uleb128 LEHE117-LEHB117
	.uleb128 L1305-LFB2526
	.uleb128 0
	.uleb128 LEHB118-LFB2526
	.uleb128 LEHE118-LEHB118
	.uleb128 L1306-LFB2526
	.uleb128 0
	.uleb128 LEHB119-LFB2526
	.uleb128 LEHE119-LEHB119
	.uleb128 L1307-LFB2526
	.uleb128 0
	.uleb128 LEHB120-LFB2526
	.uleb128 LEHE120-LEHB120
	.uleb128 L1308-LFB2526
	.uleb128 0
	.uleb128 LEHB121-LFB2526
	.uleb128 LEHE121-LEHB121
	.uleb128 L1310-LFB2526
	.uleb128 0
	.uleb128 LEHB122-LFB2526
	.uleb128 LEHE122-LEHB122
	.uleb128 L1312-LFB2526
	.uleb128 0
	.uleb128 LEHB123-LFB2526
	.uleb128 LEHE123-LEHB123
	.uleb128 L1313-LFB2526
	.uleb128 0
	.uleb128 LEHB124-LFB2526
	.uleb128 LEHE124-LEHB124
	.uleb128 L1267-LFB2526
	.uleb128 0
	.uleb128 LEHB125-LFB2526
	.uleb128 LEHE125-LEHB125
	.uleb128 L1277-LFB2526
	.uleb128 0
	.uleb128 LEHB126-LFB2526
	.uleb128 LEHE126-LEHB126
	.uleb128 L1278-LFB2526
	.uleb128 0
	.uleb128 LEHB127-LFB2526
	.uleb128 LEHE127-LEHB127
	.uleb128 L1314-LFB2526
	.uleb128 0
	.uleb128 LEHB128-LFB2526
	.uleb128 LEHE128-LEHB128
	.uleb128 L1315-LFB2526
	.uleb128 0
	.uleb128 LEHB129-LFB2526
	.uleb128 LEHE129-LEHB129
	.uleb128 L1316-LFB2526
	.uleb128 0
	.uleb128 LEHB130-LFB2526
	.uleb128 LEHE130-LEHB130
	.uleb128 L1317-LFB2526
	.uleb128 0
	.uleb128 LEHB131-LFB2526
	.uleb128 LEHE131-LEHB131
	.uleb128 L1318-LFB2526
	.uleb128 0
	.uleb128 LEHB132-LFB2526
	.uleb128 LEHE132-LEHB132
	.uleb128 L1319-LFB2526
	.uleb128 0
	.uleb128 LEHB133-LFB2526
	.uleb128 LEHE133-LEHB133
	.uleb128 L1321-LFB2526
	.uleb128 0
	.uleb128 LEHB134-LFB2526
	.uleb128 LEHE134-LEHB134
	.uleb128 L1323-LFB2526
	.uleb128 0
	.uleb128 LEHB135-LFB2526
	.uleb128 LEHE135-LEHB135
	.uleb128 L1324-LFB2526
	.uleb128 0
	.uleb128 LEHB136-LFB2526
	.uleb128 LEHE136-LEHB136
	.uleb128 L1268-LFB2526
	.uleb128 0
	.uleb128 LEHB137-LFB2526
	.uleb128 LEHE137-LEHB137
	.uleb128 L1279-LFB2526
	.uleb128 0
	.uleb128 LEHB138-LFB2526
	.uleb128 LEHE138-LEHB138
	.uleb128 L1280-LFB2526
	.uleb128 0
	.uleb128 LEHB139-LFB2526
	.uleb128 LEHE139-LEHB139
	.uleb128 L1325-LFB2526
	.uleb128 0
	.uleb128 LEHB140-LFB2526
	.uleb128 LEHE140-LEHB140
	.uleb128 L1326-LFB2526
	.uleb128 0
	.uleb128 LEHB141-LFB2526
	.uleb128 LEHE141-LEHB141
	.uleb128 L1327-LFB2526
	.uleb128 0
	.uleb128 LEHB142-LFB2526
	.uleb128 LEHE142-LEHB142
	.uleb128 L1328-LFB2526
	.uleb128 0
	.uleb128 LEHB143-LFB2526
	.uleb128 LEHE143-LEHB143
	.uleb128 L1329-LFB2526
	.uleb128 0
	.uleb128 LEHB144-LFB2526
	.uleb128 LEHE144-LEHB144
	.uleb128 L1330-LFB2526
	.uleb128 0
	.uleb128 LEHB145-LFB2526
	.uleb128 LEHE145-LEHB145
	.uleb128 L1332-LFB2526
	.uleb128 0
	.uleb128 LEHB146-LFB2526
	.uleb128 LEHE146-LEHB146
	.uleb128 L1334-LFB2526
	.uleb128 0
	.uleb128 LEHB147-LFB2526
	.uleb128 LEHE147-LEHB147
	.uleb128 L1335-LFB2526
	.uleb128 0
	.uleb128 LEHB148-LFB2526
	.uleb128 LEHE148-LEHB148
	.uleb128 L1269-LFB2526
	.uleb128 0
	.uleb128 LEHB149-LFB2526
	.uleb128 LEHE149-LEHB149
	.uleb128 L1281-LFB2526
	.uleb128 0
	.uleb128 LEHB150-LFB2526
	.uleb128 LEHE150-LEHB150
	.uleb128 L1282-LFB2526
	.uleb128 0
	.uleb128 LEHB151-LFB2526
	.uleb128 LEHE151-LEHB151
	.uleb128 L1336-LFB2526
	.uleb128 0
	.uleb128 LEHB152-LFB2526
	.uleb128 LEHE152-LEHB152
	.uleb128 L1337-LFB2526
	.uleb128 0
	.uleb128 LEHB153-LFB2526
	.uleb128 LEHE153-LEHB153
	.uleb128 L1338-LFB2526
	.uleb128 0
	.uleb128 LEHB154-LFB2526
	.uleb128 LEHE154-LEHB154
	.uleb128 L1339-LFB2526
	.uleb128 0
	.uleb128 LEHB155-LFB2526
	.uleb128 LEHE155-LEHB155
	.uleb128 L1340-LFB2526
	.uleb128 0
	.uleb128 LEHB156-LFB2526
	.uleb128 LEHE156-LEHB156
	.uleb128 L1341-LFB2526
	.uleb128 0
	.uleb128 LEHB157-LFB2526
	.uleb128 LEHE157-LEHB157
	.uleb128 L1343-LFB2526
	.uleb128 0
	.uleb128 LEHB158-LFB2526
	.uleb128 LEHE158-LEHB158
	.uleb128 L1345-LFB2526
	.uleb128 0
	.uleb128 LEHB159-LFB2526
	.uleb128 LEHE159-LEHB159
	.uleb128 L1346-LFB2526
	.uleb128 0
	.uleb128 LEHB160-LFB2526
	.uleb128 LEHE160-LEHB160
	.uleb128 L1270-LFB2526
	.uleb128 0
	.uleb128 LEHB161-LFB2526
	.uleb128 LEHE161-LEHB161
	.uleb128 L1290-LFB2526
	.uleb128 0
	.uleb128 LEHB162-LFB2526
	.uleb128 LEHE162-LEHB162
	.uleb128 L1300-LFB2526
	.uleb128 0
	.uleb128 LEHB163-LFB2526
	.uleb128 LEHE163-LEHB163
	.uleb128 L1311-LFB2526
	.uleb128 0
	.uleb128 LEHB164-LFB2526
	.uleb128 LEHE164-LEHB164
	.uleb128 L1322-LFB2526
	.uleb128 0
	.uleb128 LEHB165-LFB2526
	.uleb128 LEHE165-LEHB165
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB166-LFB2526
	.uleb128 LEHE166-LEHB166
	.uleb128 L1344-LFB2526
	.uleb128 0
	.uleb128 LEHB167-LFB2526
	.uleb128 LEHE167-LEHB167
	.uleb128 L1333-LFB2526
	.uleb128 0
	.uleb128 LEHB168-LFB2526
	.uleb128 LEHE168-LEHB168
	.uleb128 L1320-LFB2526
	.uleb128 0
	.uleb128 LEHB169-LFB2526
	.uleb128 LEHE169-LEHB169
	.uleb128 L1298-LFB2526
	.uleb128 0
	.uleb128 LEHB170-LFB2526
	.uleb128 LEHE170-LEHB170
	.uleb128 L1309-LFB2526
	.uleb128 0
	.uleb128 LEHB171-LFB2526
	.uleb128 LEHE171-LEHB171
	.uleb128 L1342-LFB2526
	.uleb128 0
	.uleb128 LEHB172-LFB2526
	.uleb128 LEHE172-LEHB172
	.uleb128 L1288-LFB2526
	.uleb128 0
	.uleb128 LEHB173-LFB2526
	.uleb128 LEHE173-LEHB173
	.uleb128 L1331-LFB2526
	.uleb128 0
LLSDACSE2526:
	.text
	.section	.text$_ZN17lf_pool_allocatorI6data_tLj20EEC1Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZN17lf_pool_allocatorI6data_tLj20EEC1Ev
	.def	__ZN17lf_pool_allocatorI6data_tLj20EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN17lf_pool_allocatorI6data_tLj20EEC1Ev:
LFB2768:
	.cfi_startproc
	movl	4(%esp), %edx
	xorl	%eax, %eax
	movl	$0, 160(%edx)
	mfence
	movl	$-1, 164(%edx)
	mfence
	.p2align 4,,7
L1542:
	movb	$0, 169(%edx,%eax)
	addl	$1, %eax
	cmpl	$20, %eax
	mfence
	jne	L1542
	rep ret
	.cfi_endproc
LFE2768:
	.section	.text$_ZN5queueI6data_tLj20EEC1Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZN5queueI6data_tLj20EEC1Ev
	.def	__ZN5queueI6data_tLj20EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN5queueI6data_tLj20EEC1Ev:
LFB2788:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2788
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	leal	252(%ebx), %esi
	movl	$0, 240(%ebx)
	movl	$-1, 244(%ebx)
	movl	$0, 248(%ebx)
	movl	$20, 252(%ebx)
	movl	$20, 264(%ebx)
	movl	%esi, (%esp)
LEHB174:
	call	_pthread_mutex_lock
LEHE174:
	testl	%eax, %eax
	jne	L1551
	movl	240(%ebx), %ecx
	cmpl	$19, %ecx
	jbe	L1552
	movl	244(%ebx), %ecx
	cmpl	$-1, %ecx
	je	L1547
	leal	(%ecx,%ecx,2), %eax
	leal	(%ebx,%eax,4), %eax
	movl	(%eax), %edx
	movl	%eax, %edi
	movl	%edx, 244(%ebx)
	movl	$1, %edx
	movl	$-16843010, (%eax)
	sall	%cl, %edx
	orl	%edx, 248(%ebx)
L1546:
	movl	%esi, (%esp)
	call	_pthread_mutex_unlock
	movl	%edi, %eax
L1548:
	movl	$0, (%eax)
	movl	%eax, 256(%ebx)
	movl	%eax, 260(%ebx)
	addl	$16, %esp
	.cfi_remember_state
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
	.p2align 4,,7
L1552:
	.cfi_restore_state
	leal	1(%ecx), %eax
	movl	%eax, 240(%ebx)
	movl	$1, %eax
	sall	%cl, %eax
	orl	%eax, 248(%ebx)
	leal	(%ecx,%ecx,2), %eax
	leal	(%ebx,%eax,4), %edi
	jmp	L1546
	.p2align 4,,7
L1547:
	movl	%esi, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L1548
L1551:
	movl	%eax, (%esp)
LEHB175:
	call	__ZSt20__throw_system_errori
LEHE175:
	.cfi_endproc
LFE2788:
	.section	.gcc_except_table,"w"
LLSDA2788:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2788-LLSDACSB2788
LLSDACSB2788:
	.uleb128 LEHB174-LFB2788
	.uleb128 LEHE174-LEHB174
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB175-LFB2788
	.uleb128 LEHE175-LEHB175
	.uleb128 0
	.uleb128 0
LLSDACSE2788:
	.section	.text$_ZN5queueI6data_tLj20EEC1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv
	.def	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv;	.scl	2;	.type	32;	.endef
__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv:
LFB3030:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	lock subl	$1, 4(%ebx)
	je	L1558
L1553:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L1558:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L1553
	movl	(%ebx), %eax
	movl	%ebx, 32(%esp)
	movl	12(%eax), %eax
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	*%eax
	.cfi_endproc
LFE3030:
	.text
	.align 2
	.p2align 4,,15
	.def	__ZZ11thread_testvENKUlPKcS0_S0_St8functionIFbO6data_tEES1_IFbRS2_EEE0_clES0_S0_S0_S5_S8_.isra.312;	.scl	3;	.type	32;	.endef
__ZZ11thread_testvENKUlPKcS0_S0_St8functionIFbO6data_tEES1_IFbRS2_EEE0_clES0_S0_S0_S5_S8_.isra.312:
LFB4291:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4291
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
	movl	%eax, %ebx
	subl	$156, %esp
	.cfi_def_cfa_offset 176
	movl	$LC6, (%esp)
	movl	%edx, 44(%esp)
	movl	%ecx, 40(%esp)
	movl	%eax, 28(%esp)
LEHB176:
	call	_puts
	movl	%ebx, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
	movl	$100000, 4(%esp)
	movl	$LC16, (%esp)
	call	_printf
	movl	$3, 4(%esp)
	movl	$LC17, (%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC18, (%esp)
	call	_printf
	movl	$20, 4(%esp)
	movl	$LC19, (%esp)
	call	_printf
LEHE176:
	leal	60(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSt18condition_variableC1Ev
	leal	59(%esp), %eax
	movl	$20, 64(%esp)
	movb	$0, 59(%esp)
	mfence
	movl	%eax, 68(%esp)
	leal	64(%esp), %eax
	movl	$0, 72(%esp)
	mfence
	movl	$0, 76(%esp)
	mfence
	movl	$0, 80(%esp)
	mfence
	movl	$0, 84(%esp)
	mfence
	movl	$0, 88(%esp)
	mfence
	movl	$0, 92(%esp)
	mfence
	movl	%eax, (%esp)
LEHB177:
	call	_pthread_mutex_lock
LEHE177:
	testl	%eax, %eax
	jne	L1623
	xorl	%ebx, %ebx
	jmp	L1587
	.p2align 4,,7
L1563:
	movl	%esi, 132(%esp,%ebx,4)
	addl	$1, %ebx
	cmpl	$3, %ebx
	je	L1624
L1587:
	movl	$4, (%esp)
LEHB178:
	call	__Znwj
LEHE178:
	movl	$0, (%eax)
	movl	%eax, %esi
	movl	$72, (%esp)
LEHB179:
	call	__Znwj
LEHE179:
	movl	%eax, %edi
	xorl	%eax, %eax
	testl	%edi, %edi
	je	L1561
	leal	16(%edi), %eax
	movl	%eax, 12(%edi)
	leal	44(%esp), %eax
	movl	%eax, 32(%edi)
	movl	176(%esp), %eax
	movl	$1, 4(%edi)
	movl	$1, 8(%edi)
	movl	$__ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE+8, (%edi)
	movl	%eax, 36(%edi)
	leal	60(%esp), %eax
	movl	%eax, 40(%edi)
	leal	64(%esp), %eax
	movl	%eax, 44(%edi)
	leal	68(%esp), %eax
	movl	%eax, 48(%edi)
	leal	72(%esp), %eax
	movl	%eax, 52(%edi)
	leal	76(%esp), %eax
	movl	%eax, 56(%edi)
	leal	80(%esp), %eax
	movl	%eax, 60(%edi)
	leal	84(%esp), %eax
	movl	%eax, 64(%edi)
	leal	92(%esp), %eax
	movl	$0, 20(%edi)
	movl	$0, 24(%edi)
	movl	$__ZTVNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEEE+8, 16(%edi)
	movl	%ebx, 28(%edi)
	movl	%eax, 68(%edi)
	movl	$__ZTISt19_Sp_make_shared_tag, 4(%esp)
	movl	%edi, (%esp)
	call	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info
L1561:
	leal	112(%esp), %ebp
	movl	%ebp, 4(%esp)
	movl	%esi, (%esp)
	movl	%eax, 112(%esp)
	movl	%edi, 116(%esp)
LEHB180:
	call	__ZNSt6thread15_M_start_threadESt10shared_ptrINS_10_Impl_baseEE
LEHE180:
	movl	116(%esp), %edi
	testl	%edi, %edi
	je	L1563
	lock subl	$1, 4(%edi)
	jne	L1563
	movl	(%edi), %eax
	movl	%edi, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%edi)
	jne	L1563
	movl	(%edi), %eax
	movl	%edi, (%esp)
	call	*12(%eax)
	movl	%esi, 132(%esp,%ebx,4)
	addl	$1, %ebx
	cmpl	$3, %ebx
	jne	L1587
	.p2align 4,,7
L1624:
	xorl	%esi, %esi
	jmp	L1589
	.p2align 4,,7
L1569:
	movl	%edi, 0(%ebp,%esi,4)
	addl	$1, %esi
	addl	$1, %ebx
	cmpl	$2, %esi
	je	L1625
L1589:
	movl	$4, (%esp)
LEHB181:
	call	__Znwj
LEHE181:
	movl	$0, (%eax)
	movl	%eax, %edi
	movl	$68, (%esp)
LEHB182:
	call	__Znwj
LEHE182:
	movl	%eax, %edx
	xorl	%eax, %eax
	testl	%edx, %edx
	je	L1567
	leal	16(%edx), %eax
	movl	%eax, 12(%edx)
	leal	40(%esp), %eax
	movl	%eax, 32(%edx)
	movl	180(%esp), %eax
	movl	$1, 4(%edx)
	movl	$1, 8(%edx)
	movl	$__ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE+8, (%edx)
	movl	%eax, 36(%edx)
	leal	60(%esp), %eax
	movl	%eax, 40(%edx)
	leal	64(%esp), %eax
	movl	%eax, 44(%edx)
	leal	68(%esp), %eax
	movl	%eax, 48(%edx)
	leal	72(%esp), %eax
	movl	%eax, 52(%edx)
	leal	76(%esp), %eax
	movl	%eax, 56(%edx)
	leal	80(%esp), %eax
	movl	%eax, 60(%edx)
	leal	88(%esp), %eax
	movl	$0, 20(%edx)
	movl	$0, 24(%edx)
	movl	$__ZTVNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEEE+8, 16(%edx)
	movl	%esi, 28(%edx)
	movl	%eax, 64(%edx)
	movl	%edx, (%esp)
	movl	$__ZTISt19_Sp_make_shared_tag, 4(%esp)
	movl	%edx, 16(%esp)
	call	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info
	movl	16(%esp), %edx
L1567:
	movl	%eax, 96(%esp)
	leal	96(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	movl	%edx, 100(%esp)
LEHB183:
	call	__ZNSt6thread15_M_start_threadESt10shared_ptrINS_10_Impl_baseEE
LEHE183:
	movl	100(%esp), %eax
	testl	%eax, %eax
	je	L1569
	lock subl	$1, 4(%eax)
	jne	L1569
	movl	(%eax), %edx
	movl	%eax, 16(%esp)
	movl	%eax, (%esp)
	call	*8(%edx)
	movl	16(%esp), %eax
	movl	$-1, %edx
	lock xaddl	%edx, 8(%eax)
	cmpl	$1, %edx
	jne	L1569
	movl	(%eax), %edx
	addl	$1, %ebx
	movl	%eax, (%esp)
	call	*12(%edx)
	movl	%edi, 0(%ebp,%esi,4)
	addl	$1, %esi
	cmpl	$2, %esi
	jne	L1589
	.p2align 4,,7
L1625:
	movl	$1000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
LEHB184:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
LEHE184:
	leal	64(%esp), %eax
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	movb	$1, 59(%esp)
	mfence
	.p2align 4,,7
L1574:
	leal	60(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSt18condition_variable10notify_allEv
	movl	$1000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
LEHB185:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	76(%esp), %eax
	cmpl	%eax, %ebx
	jne	L1574
	leal	132(%esp), %ebx
	leal	144(%esp), %esi
L1578:
	movl	(%ebx), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
LEHE185:
	movl	(%ebx), %edi
	testl	%edi, %edi
	je	L1575
	movl	$0, 4(%esp)
	movl	(%edi), %eax
	movl	%eax, (%esp)
	call	_pthread_equal
	testl	%eax, %eax
	je	L1580
	movl	%edi, (%esp)
	call	__ZdlPv
L1575:
	movl	$0, (%ebx)
	addl	$4, %ebx
	cmpl	%esi, %ebx
	jne	L1578
	leal	120(%esp), %ebx
L1583:
	movl	0(%ebp), %eax
	movl	%eax, (%esp)
LEHB186:
	call	__ZNSt6thread4joinEv
LEHE186:
	movl	0(%ebp), %esi
	testl	%esi, %esi
	je	L1579
	movl	$0, 4(%esp)
	movl	(%esi), %eax
	movl	%eax, (%esp)
	call	_pthread_equal
	testl	%eax, %eax
	je	L1580
	movl	%esi, (%esp)
	call	__ZdlPv
L1579:
	movl	$0, 0(%ebp)
	addl	$4, %ebp
	cmpl	%ebx, %ebp
	jne	L1583
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC13, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 32(%esp)
	movl	28(%esp), %eax
	movl	%edx, 36(%esp)
	fildq	32(%esp)
	fdivs	LC12
	movl	%eax, 4(%esp)
	fstpl	8(%esp)
LEHB187:
	call	_printf
	movl	$LC6, (%esp)
	call	_puts
LEHE187:
	leal	60(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSt18condition_variableD1Ev
	addl	$156, %esp
	.cfi_remember_state
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
L1592:
	.cfi_restore_state
	movl	%eax, %ebx
L1585:
	leal	60(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSt18condition_variableD1Ev
	movl	%ebx, (%esp)
LEHB188:
	call	__Unwind_Resume
LEHE188:
L1580:
	call	__ZSt9terminatev
L1597:
	movl	100(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1572
	movl	%edx, (%esp)
	call	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv
L1572:
	movl	%edi, (%esp)
	call	__ZdlPv
L1584:
	leal	64(%esp), %eax
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
	jmp	L1585
L1594:
	movl	%eax, %ebx
	jmp	L1572
L1596:
	movl	116(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1566
	movl	%edx, (%esp)
	call	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv
L1566:
	movl	%esi, (%esp)
	call	__ZdlPv
	jmp	L1584
L1595:
	movl	%eax, %ebx
	.p2align 4,,3
	jmp	L1566
L1593:
	movl	%eax, %ebx
	.p2align 4,,7
	jmp	L1584
L1623:
	movl	%eax, (%esp)
LEHB189:
	call	__ZSt20__throw_system_errori
LEHE189:
	.cfi_endproc
LFE4291:
	.section	.gcc_except_table,"w"
LLSDA4291:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4291-LLSDACSB4291
LLSDACSB4291:
	.uleb128 LEHB176-LFB4291
	.uleb128 LEHE176-LEHB176
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB177-LFB4291
	.uleb128 LEHE177-LEHB177
	.uleb128 L1592-LFB4291
	.uleb128 0
	.uleb128 LEHB178-LFB4291
	.uleb128 LEHE178-LEHB178
	.uleb128 L1593-LFB4291
	.uleb128 0
	.uleb128 LEHB179-LFB4291
	.uleb128 LEHE179-LEHB179
	.uleb128 L1595-LFB4291
	.uleb128 0
	.uleb128 LEHB180-LFB4291
	.uleb128 LEHE180-LEHB180
	.uleb128 L1596-LFB4291
	.uleb128 0
	.uleb128 LEHB181-LFB4291
	.uleb128 LEHE181-LEHB181
	.uleb128 L1593-LFB4291
	.uleb128 0
	.uleb128 LEHB182-LFB4291
	.uleb128 LEHE182-LEHB182
	.uleb128 L1594-LFB4291
	.uleb128 0
	.uleb128 LEHB183-LFB4291
	.uleb128 LEHE183-LEHB183
	.uleb128 L1597-LFB4291
	.uleb128 0
	.uleb128 LEHB184-LFB4291
	.uleb128 LEHE184-LEHB184
	.uleb128 L1593-LFB4291
	.uleb128 0
	.uleb128 LEHB185-LFB4291
	.uleb128 LEHE185-LEHB185
	.uleb128 L1592-LFB4291
	.uleb128 0
	.uleb128 LEHB186-LFB4291
	.uleb128 LEHE186-LEHB186
	.uleb128 L1592-LFB4291
	.uleb128 0
	.uleb128 LEHB187-LFB4291
	.uleb128 LEHE187-LEHB187
	.uleb128 L1592-LFB4291
	.uleb128 0
	.uleb128 LEHB188-LFB4291
	.uleb128 LEHE188-LEHB188
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB189-LFB4291
	.uleb128 LEHE189-LEHB189
	.uleb128 L1592-LFB4291
	.uleb128 0
LLSDACSE4291:
	.text
	.section .rdata,"dr"
	.align 4
LC23:
	.ascii "[Test for Lock-free pool-allocator/stack/queue with threads]\0"
LC24:
	.ascii "POP \0"
LC25:
	.ascii "PUSH\0"
LC26:
	.ascii "DEQUEUE\0"
LC27:
	.ascii "ENQUEUE\0"
	.text
	.p2align 4,,15
	.globl	__Z11thread_testv
	.def	__Z11thread_testv;	.scl	2;	.type	32;	.endef
__Z11thread_testv:
LFB2606:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2606
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
	subl	$236, %esp
	.cfi_def_cfa_offset 256
	movl	$LC4, (%esp)
LEHB190:
	call	_puts
	movl	$LC23, (%esp)
	call	_puts
LEHE190:
	movl	$1, (%esp)
	movl	$0, 120(%esp)
LEHB191:
	call	__Znwj
LEHE191:
	movl	$1, (%esp)
	movl	%eax, 112(%esp)
	movl	$__ZNSt17_Function_handlerIFbP6data_tEZ11thread_testvEUlS1_E3_E9_M_invokeERKSt9_Any_dataS1_, 124(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlP6data_tE3_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 120(%esp)
	movl	$0, 104(%esp)
LEHB192:
	call	__Znwj
LEHE192:
	movl	$LC6, (%esp)
	movl	%eax, 96(%esp)
	movl	$__ZNSt17_Function_handlerIFP6data_tvEZ11thread_testvEUlvE2_E9_M_invokeERKSt9_Any_data, 108(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlvE2_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation, 104(%esp)
LEHB193:
	call	_puts
	movl	$LC7, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
	movl	$100000, 4(%esp)
	movl	$LC9, (%esp)
	call	_printf
	movl	$5, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	movl	$20, 4(%esp)
	movl	$LC11, (%esp)
	call	_printf
LEHE193:
	leal	40(%esp), %edi
	movl	%edi, (%esp)
	call	__ZNSt18condition_variableC1Ev
	leal	38(%esp), %eax
	movl	$20, 44(%esp)
	movb	$0, 38(%esp)
	mfence
	movl	%eax, 48(%esp)
	leal	44(%esp), %eax
	movl	$0, 52(%esp)
	mfence
	movl	$0, 56(%esp)
	mfence
	movl	$0, 60(%esp)
	mfence
	movl	$0, 64(%esp)
	mfence
	movl	%eax, (%esp)
LEHB194:
	call	_pthread_mutex_lock
LEHE194:
	testl	%eax, %eax
	jne	L1896
	xorl	%ebx, %ebx
	jmp	L1733
	.p2align 4,,7
L1637:
	movl	%ebp, 160(%esp,%ebx,4)
	addl	$1, %ebx
	cmpl	$5, %ebx
	je	L1897
L1733:
	movl	$4, (%esp)
LEHB195:
	call	__Znwj
LEHE195:
	movl	$0, (%eax)
	movl	%eax, %ebp
	movl	$68, (%esp)
LEHB196:
	call	__Znwj
LEHE196:
	movl	%eax, %esi
	xorl	%eax, %eax
	testl	%esi, %esi
	je	L1635
	leal	16(%esi), %eax
	movl	%eax, 12(%esi)
	leal	96(%esp), %eax
	movl	%eax, 32(%esi)
	leal	112(%esp), %eax
	movl	%eax, 36(%esi)
	leal	44(%esp), %eax
	movl	%eax, 44(%esi)
	leal	48(%esp), %eax
	movl	%eax, 48(%esi)
	leal	52(%esp), %eax
	movl	%eax, 52(%esi)
	leal	56(%esp), %eax
	movl	%eax, 56(%esi)
	leal	60(%esp), %eax
	movl	%eax, 60(%esi)
	leal	64(%esp), %eax
	movl	$1, 4(%esi)
	movl	$1, 8(%esi)
	movl	$__ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE+8, (%esi)
	movl	$0, 20(%esi)
	movl	$0, 24(%esi)
	movl	$__ZTVNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEEE+8, 16(%esi)
	movl	%ebx, 28(%esi)
	movl	%edi, 40(%esi)
	movl	%eax, 64(%esi)
	movl	$__ZTISt19_Sp_make_shared_tag, 4(%esp)
	movl	%esi, (%esp)
	call	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info
L1635:
	movl	%esi, 196(%esp)
	leal	192(%esp), %esi
	movl	%esi, 4(%esp)
	movl	%ebp, (%esp)
	movl	%eax, 192(%esp)
LEHB197:
	call	__ZNSt6thread15_M_start_threadESt10shared_ptrINS_10_Impl_baseEE
LEHE197:
	movl	196(%esp), %eax
	testl	%eax, %eax
	je	L1637
	lock subl	$1, 4(%eax)
	jne	L1637
	movl	(%eax), %edx
	movl	%eax, 16(%esp)
	movl	%eax, (%esp)
	call	*8(%edx)
	movl	16(%esp), %eax
	movl	$-1, %edx
	lock xaddl	%edx, 8(%eax)
	cmpl	$1, %edx
	jne	L1637
	movl	(%eax), %edx
	movl	%eax, (%esp)
	call	*12(%edx)
	movl	%ebp, 160(%esp,%ebx,4)
	addl	$1, %ebx
	cmpl	$5, %ebx
	jne	L1733
	.p2align 4,,7
L1897:
	movl	$1000000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
LEHB198:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
LEHE198:
	leal	44(%esp), %eax
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	movb	$1, 38(%esp)
	mfence
	.p2align 4,,7
L1642:
	movl	%edi, (%esp)
	call	__ZNSt18condition_variable10notify_allEv
	movl	$1000000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
LEHB199:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	56(%esp), %eax
	cmpl	$5, %eax
	jne	L1642
	leal	160(%esp), %ebx
L1646:
	movl	(%ebx), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
LEHE199:
	movl	(%ebx), %ebp
	testl	%ebp, %ebp
	je	L1643
	movl	$0, 4(%esp)
	movl	0(%ebp), %eax
	movl	%eax, (%esp)
	call	_pthread_equal
	testl	%eax, %eax
	je	L1670
	movl	%ebp, (%esp)
	call	__ZdlPv
L1643:
	movl	$0, (%ebx)
	leal	180(%esp), %eax
	addl	$4, %ebx
	cmpl	%eax, %ebx
	jne	L1646
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC7, 4(%esp)
	movl	$LC13, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC12
	fstpl	8(%esp)
LEHB200:
	call	_printf
	movl	$LC6, (%esp)
	call	_puts
LEHE200:
	movl	%edi, (%esp)
	call	__ZNSt18condition_variableD1Ev
	movl	104(%esp), %eax
	testl	%eax, %eax
	je	L1648
	leal	96(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1648:
	movl	120(%esp), %eax
	testl	%eax, %eax
	je	L1652
	leal	112(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1652:
	movl	$1, (%esp)
	movl	$0, 152(%esp)
LEHB201:
	call	__Znwj
LEHE201:
	movl	$1, (%esp)
	movl	%eax, 144(%esp)
	movl	$__ZNSt17_Function_handlerIFbP6data_tEZ11thread_testvEUlS1_E5_E9_M_invokeERKSt9_Any_dataS1_, 156(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlP6data_tE5_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 152(%esp)
	movl	$0, 136(%esp)
LEHB202:
	call	__Znwj
LEHE202:
	movl	$LC6, (%esp)
	movl	%eax, 128(%esp)
	movl	$__ZNSt17_Function_handlerIFP6data_tvEZ11thread_testvEUlvE4_E9_M_invokeERKSt9_Any_data, 140(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlvE4_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation, 136(%esp)
LEHB203:
	call	_puts
	movl	$LC14, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
	movl	$100000, 4(%esp)
	movl	$LC9, (%esp)
	call	_printf
	movl	$5, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	movl	$20, 4(%esp)
	movl	$LC11, (%esp)
	call	_printf
LEHE203:
	leal	68(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSt18condition_variableC1Ev
	leal	39(%esp), %eax
	movl	$20, 72(%esp)
	movb	$0, 39(%esp)
	mfence
	movl	%eax, 76(%esp)
	leal	72(%esp), %eax
	movl	$0, 80(%esp)
	mfence
	movl	$0, 84(%esp)
	mfence
	movl	$0, 88(%esp)
	mfence
	movl	$0, 92(%esp)
	mfence
	movl	%eax, (%esp)
LEHB204:
	call	_pthread_mutex_lock
LEHE204:
	testl	%eax, %eax
	jne	L1898
	xorl	%ebx, %ebx
	jmp	L1735
	.p2align 4,,7
L1663:
	movl	%edi, (%esi,%ebx,4)
	addl	$1, %ebx
	cmpl	$5, %ebx
	je	L1899
L1735:
	movl	$4, (%esp)
LEHB205:
	call	__Znwj
LEHE205:
	movl	$0, (%eax)
	movl	%eax, %edi
	movl	$68, (%esp)
LEHB206:
	call	__Znwj
LEHE206:
	movl	%eax, %ebp
	xorl	%eax, %eax
	testl	%ebp, %ebp
	je	L1661
	leal	16(%ebp), %eax
	movl	%eax, 12(%ebp)
	leal	128(%esp), %eax
	movl	%eax, 32(%ebp)
	leal	144(%esp), %eax
	movl	%eax, 36(%ebp)
	leal	68(%esp), %eax
	movl	%eax, 40(%ebp)
	leal	72(%esp), %eax
	movl	%eax, 44(%ebp)
	leal	76(%esp), %eax
	movl	%eax, 48(%ebp)
	leal	80(%esp), %eax
	movl	%eax, 52(%ebp)
	leal	84(%esp), %eax
	movl	%eax, 56(%ebp)
	leal	88(%esp), %eax
	movl	%eax, 60(%ebp)
	leal	92(%esp), %eax
	movl	$1, 4(%ebp)
	movl	$1, 8(%ebp)
	movl	$__ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE+8, 0(%ebp)
	movl	$0, 20(%ebp)
	movl	$0, 24(%ebp)
	movl	$__ZTVNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEEE+8, 16(%ebp)
	movl	%ebx, 28(%ebp)
	movl	%eax, 64(%ebp)
	movl	$__ZTISt19_Sp_make_shared_tag, 4(%esp)
	movl	%ebp, (%esp)
	call	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info
L1661:
	movl	%eax, 160(%esp)
	leal	160(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	movl	%ebp, 164(%esp)
LEHB207:
	call	__ZNSt6thread15_M_start_threadESt10shared_ptrINS_10_Impl_baseEE
LEHE207:
	movl	164(%esp), %eax
	testl	%eax, %eax
	je	L1663
	lock subl	$1, 4(%eax)
	jne	L1663
	movl	(%eax), %edx
	movl	%eax, 16(%esp)
	movl	%eax, (%esp)
	call	*8(%edx)
	movl	16(%esp), %eax
	movl	$-1, %edx
	lock xaddl	%edx, 8(%eax)
	cmpl	$1, %edx
	jne	L1663
	movl	(%eax), %edx
	movl	%eax, (%esp)
	call	*12(%edx)
	movl	%edi, (%esi,%ebx,4)
	addl	$1, %ebx
	cmpl	$5, %ebx
	jne	L1735
	.p2align 4,,7
L1899:
	movl	$1000000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
LEHB208:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
LEHE208:
	leal	72(%esp), %eax
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	movb	$1, 39(%esp)
	mfence
	.p2align 4,,7
L1668:
	leal	68(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSt18condition_variable10notify_allEv
	movl	$1000000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
LEHB209:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	84(%esp), %eax
	cmpl	$5, %eax
	jne	L1668
	movl	%esi, %ebx
	leal	212(%esp), %ebp
L1673:
	movl	(%ebx), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
LEHE209:
	movl	(%ebx), %edi
	testl	%edi, %edi
	je	L1669
	movl	$0, 4(%esp)
	movl	(%edi), %eax
	movl	%eax, (%esp)
	call	_pthread_equal
	testl	%eax, %eax
	je	L1670
	movl	%edi, (%esp)
	call	__ZdlPv
L1669:
	movl	$0, (%ebx)
	addl	$4, %ebx
	cmpl	%ebp, %ebx
	jne	L1673
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC14, 4(%esp)
	movl	$LC13, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC12
	fstpl	8(%esp)
LEHB210:
	call	_printf
	movl	$LC6, (%esp)
	call	_puts
LEHE210:
	leal	68(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSt18condition_variableD1Ev
	movl	136(%esp), %eax
	testl	%eax, %eax
	je	L1675
	leal	128(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1675:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L1679
	leal	144(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1679:
	movl	$1, (%esp)
	movl	$0, 200(%esp)
LEHB211:
	call	__Znwj
LEHE211:
	movl	$1, (%esp)
	movl	%eax, 192(%esp)
	movl	$__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E7_E9_M_invokeERKSt9_Any_dataS1_, 204(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE7_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 200(%esp)
	movl	$0, 168(%esp)
LEHB212:
	call	__Znwj
LEHE212:
	movl	%eax, 160(%esp)
	leal	160(%esp), %eax
	movl	$LC24, %ecx
	movl	%eax, (%esp)
	movl	$LC25, %edx
	movl	$LC15, %eax
	movl	%esi, 4(%esp)
	movl	$__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E6_E9_M_invokeERKSt9_Any_dataS1_, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE6_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 168(%esp)
LEHB213:
	call	__ZZ11thread_testvENKUlPKcS0_S0_St8functionIFbO6data_tEES1_IFbRS2_EEE0_clES0_S0_S0_S5_S8_.isra.312
LEHE213:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L1687
	leal	160(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%eax
L1687:
	movl	200(%esp), %eax
	testl	%eax, %eax
	je	L1688
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
L1688:
	movl	$1, (%esp)
	movl	$0, 200(%esp)
LEHB214:
	call	__Znwj
LEHE214:
	movl	$1, (%esp)
	movl	%eax, 192(%esp)
	movl	$__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E9_E9_M_invokeERKSt9_Any_dataS1_, 204(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE9_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 200(%esp)
	movl	$0, 168(%esp)
LEHB215:
	call	__Znwj
LEHE215:
	movl	%eax, 160(%esp)
	leal	160(%esp), %eax
	movl	$LC24, %ecx
	movl	%eax, (%esp)
	movl	$LC25, %edx
	movl	$LC20, %eax
	movl	%esi, 4(%esp)
	movl	$__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E8_E9_M_invokeERKSt9_Any_dataS1_, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE8_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 168(%esp)
LEHB216:
	call	__ZZ11thread_testvENKUlPKcS0_S0_St8functionIFbO6data_tEES1_IFbRS2_EEE0_clES0_S0_S0_S5_S8_.isra.312
LEHE216:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L1696
	leal	160(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%eax
L1696:
	movl	200(%esp), %eax
	testl	%eax, %eax
	je	L1697
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
L1697:
	movl	$1, (%esp)
	movl	$0, 200(%esp)
LEHB217:
	call	__Znwj
LEHE217:
	movl	$1, (%esp)
	movl	%eax, 192(%esp)
	movl	$__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E11_E9_M_invokeERKSt9_Any_dataS1_, 204(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE11_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 200(%esp)
	movl	$0, 168(%esp)
LEHB218:
	call	__Znwj
LEHE218:
	movl	%eax, 160(%esp)
	leal	160(%esp), %eax
	movl	$LC26, %ecx
	movl	%eax, (%esp)
	movl	$LC27, %edx
	movl	$LC21, %eax
	movl	%esi, 4(%esp)
	movl	$__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E10_E9_M_invokeERKSt9_Any_dataS1_, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE10_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 168(%esp)
LEHB219:
	call	__ZZ11thread_testvENKUlPKcS0_S0_St8functionIFbO6data_tEES1_IFbRS2_EEE0_clES0_S0_S0_S5_S8_.isra.312
LEHE219:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L1705
	leal	160(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%eax
L1705:
	movl	200(%esp), %eax
	testl	%eax, %eax
	je	L1706
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
L1706:
	movl	$1, (%esp)
	movl	$0, 200(%esp)
LEHB220:
	call	__Znwj
LEHE220:
	movl	$1, (%esp)
	movl	%eax, 192(%esp)
	movl	$__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E13_E9_M_invokeERKSt9_Any_dataS1_, 204(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE13_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 200(%esp)
	movl	$0, 168(%esp)
LEHB221:
	call	__Znwj
LEHE221:
	movl	%eax, 160(%esp)
	leal	160(%esp), %eax
	movl	$LC26, %ecx
	movl	%eax, (%esp)
	movl	$LC27, %edx
	movl	$LC22, %eax
	movl	%esi, 4(%esp)
	movl	$__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E12_E9_M_invokeERKSt9_Any_dataS1_, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE12_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 168(%esp)
LEHB222:
	call	__ZZ11thread_testvENKUlPKcS0_S0_St8functionIFbO6data_tEES1_IFbRS2_EEE0_clES0_S0_S0_S5_S8_.isra.312
LEHE222:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L1714
	leal	160(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%eax
L1714:
	movl	200(%esp), %eax
	testl	%eax, %eax
	je	L1626
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
L1626:
	addl	$236, %esp
	.cfi_remember_state
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
L1744:
	.cfi_restore_state
	movl	120(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1731
	leal	112(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
L1731:
	movl	%ebx, (%esp)
LEHB223:
	call	__Unwind_Resume
LEHE223:
L1743:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1713
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
L1713:
	movl	200(%esp), %eax
	testl	%eax, %eax
	je	L1731
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
	jmp	L1731
L1763:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1713
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
	jmp	L1713
L1762:
	movl	200(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1731
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%edx
	jmp	L1731
L1742:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1704
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
L1704:
	movl	200(%esp), %eax
	testl	%eax, %eax
	je	L1731
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
	jmp	L1731
L1761:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1704
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
	jmp	L1704
L1760:
	movl	200(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1731
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%edx
	jmp	L1731
L1741:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1695
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
L1695:
	movl	200(%esp), %eax
	testl	%eax, %eax
	je	L1731
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
	jmp	L1731
L1759:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1695
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
	jmp	L1695
L1758:
	movl	200(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1731
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%edx
	jmp	L1731
L1740:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1686
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
L1686:
	movl	200(%esp), %eax
	testl	%eax, %eax
	je	L1731
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
	jmp	L1731
L1757:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1686
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
	jmp	L1686
L1756:
	movl	200(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1731
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%edx
	jmp	L1731
L1755:
	movl	164(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1666
	movl	%edx, (%esp)
	call	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv
L1666:
	movl	%edi, (%esp)
	call	__ZdlPv
L1676:
	leal	72(%esp), %eax
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
L1677:
	leal	68(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSt18condition_variableD1Ev
L1678:
	movl	136(%esp), %eax
	testl	%eax, %eax
	je	L1659
	leal	128(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1659:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L1731
	leal	144(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
	jmp	L1731
L1754:
	movl	%eax, %ebx
	jmp	L1666
L1753:
	movl	%eax, %ebx
	.p2align 4,,7
	jmp	L1676
L1898:
	movl	%eax, (%esp)
LEHB224:
	call	__ZSt20__throw_system_errori
LEHE224:
L1752:
	movl	%eax, %ebx
	jmp	L1677
L1739:
	movl	%eax, %ebx
	jmp	L1678
L1751:
	movl	136(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1659
	leal	128(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L1659
L1750:
	movl	152(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1731
	leal	144(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L1731
L1670:
	call	__ZSt9terminatev
L1749:
	movl	196(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1640
	movl	%edx, (%esp)
	call	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv
L1640:
	movl	%ebp, (%esp)
	call	__ZdlPv
L1649:
	leal	44(%esp), %eax
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
L1650:
	movl	%edi, (%esp)
	call	__ZNSt18condition_variableD1Ev
L1651:
	movl	104(%esp), %eax
	testl	%eax, %eax
	je	L1633
	leal	96(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L1633:
	movl	120(%esp), %eax
	testl	%eax, %eax
	je	L1731
	leal	112(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
	jmp	L1731
L1748:
	movl	%eax, %ebx
	jmp	L1640
L1747:
	movl	%eax, %ebx
	.p2align 4,,7
	jmp	L1649
L1896:
	movl	%eax, (%esp)
LEHB225:
	call	__ZSt20__throw_system_errori
LEHE225:
L1746:
	movl	%eax, %ebx
	jmp	L1650
L1738:
	movl	%eax, %ebx
	jmp	L1651
L1745:
	movl	104(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L1633
	leal	96(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L1633
	.cfi_endproc
LFE2606:
	.section	.gcc_except_table,"w"
LLSDA2606:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2606-LLSDACSB2606
LLSDACSB2606:
	.uleb128 LEHB190-LFB2606
	.uleb128 LEHE190-LEHB190
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB191-LFB2606
	.uleb128 LEHE191-LEHB191
	.uleb128 L1744-LFB2606
	.uleb128 0
	.uleb128 LEHB192-LFB2606
	.uleb128 LEHE192-LEHB192
	.uleb128 L1745-LFB2606
	.uleb128 0
	.uleb128 LEHB193-LFB2606
	.uleb128 LEHE193-LEHB193
	.uleb128 L1738-LFB2606
	.uleb128 0
	.uleb128 LEHB194-LFB2606
	.uleb128 LEHE194-LEHB194
	.uleb128 L1746-LFB2606
	.uleb128 0
	.uleb128 LEHB195-LFB2606
	.uleb128 LEHE195-LEHB195
	.uleb128 L1747-LFB2606
	.uleb128 0
	.uleb128 LEHB196-LFB2606
	.uleb128 LEHE196-LEHB196
	.uleb128 L1748-LFB2606
	.uleb128 0
	.uleb128 LEHB197-LFB2606
	.uleb128 LEHE197-LEHB197
	.uleb128 L1749-LFB2606
	.uleb128 0
	.uleb128 LEHB198-LFB2606
	.uleb128 LEHE198-LEHB198
	.uleb128 L1747-LFB2606
	.uleb128 0
	.uleb128 LEHB199-LFB2606
	.uleb128 LEHE199-LEHB199
	.uleb128 L1746-LFB2606
	.uleb128 0
	.uleb128 LEHB200-LFB2606
	.uleb128 LEHE200-LEHB200
	.uleb128 L1746-LFB2606
	.uleb128 0
	.uleb128 LEHB201-LFB2606
	.uleb128 LEHE201-LEHB201
	.uleb128 L1750-LFB2606
	.uleb128 0
	.uleb128 LEHB202-LFB2606
	.uleb128 LEHE202-LEHB202
	.uleb128 L1751-LFB2606
	.uleb128 0
	.uleb128 LEHB203-LFB2606
	.uleb128 LEHE203-LEHB203
	.uleb128 L1739-LFB2606
	.uleb128 0
	.uleb128 LEHB204-LFB2606
	.uleb128 LEHE204-LEHB204
	.uleb128 L1752-LFB2606
	.uleb128 0
	.uleb128 LEHB205-LFB2606
	.uleb128 LEHE205-LEHB205
	.uleb128 L1753-LFB2606
	.uleb128 0
	.uleb128 LEHB206-LFB2606
	.uleb128 LEHE206-LEHB206
	.uleb128 L1754-LFB2606
	.uleb128 0
	.uleb128 LEHB207-LFB2606
	.uleb128 LEHE207-LEHB207
	.uleb128 L1755-LFB2606
	.uleb128 0
	.uleb128 LEHB208-LFB2606
	.uleb128 LEHE208-LEHB208
	.uleb128 L1753-LFB2606
	.uleb128 0
	.uleb128 LEHB209-LFB2606
	.uleb128 LEHE209-LEHB209
	.uleb128 L1752-LFB2606
	.uleb128 0
	.uleb128 LEHB210-LFB2606
	.uleb128 LEHE210-LEHB210
	.uleb128 L1752-LFB2606
	.uleb128 0
	.uleb128 LEHB211-LFB2606
	.uleb128 LEHE211-LEHB211
	.uleb128 L1756-LFB2606
	.uleb128 0
	.uleb128 LEHB212-LFB2606
	.uleb128 LEHE212-LEHB212
	.uleb128 L1757-LFB2606
	.uleb128 0
	.uleb128 LEHB213-LFB2606
	.uleb128 LEHE213-LEHB213
	.uleb128 L1740-LFB2606
	.uleb128 0
	.uleb128 LEHB214-LFB2606
	.uleb128 LEHE214-LEHB214
	.uleb128 L1758-LFB2606
	.uleb128 0
	.uleb128 LEHB215-LFB2606
	.uleb128 LEHE215-LEHB215
	.uleb128 L1759-LFB2606
	.uleb128 0
	.uleb128 LEHB216-LFB2606
	.uleb128 LEHE216-LEHB216
	.uleb128 L1741-LFB2606
	.uleb128 0
	.uleb128 LEHB217-LFB2606
	.uleb128 LEHE217-LEHB217
	.uleb128 L1760-LFB2606
	.uleb128 0
	.uleb128 LEHB218-LFB2606
	.uleb128 LEHE218-LEHB218
	.uleb128 L1761-LFB2606
	.uleb128 0
	.uleb128 LEHB219-LFB2606
	.uleb128 LEHE219-LEHB219
	.uleb128 L1742-LFB2606
	.uleb128 0
	.uleb128 LEHB220-LFB2606
	.uleb128 LEHE220-LEHB220
	.uleb128 L1762-LFB2606
	.uleb128 0
	.uleb128 LEHB221-LFB2606
	.uleb128 LEHE221-LEHB221
	.uleb128 L1763-LFB2606
	.uleb128 0
	.uleb128 LEHB222-LFB2606
	.uleb128 LEHE222-LEHB222
	.uleb128 L1743-LFB2606
	.uleb128 0
	.uleb128 LEHB223-LFB2606
	.uleb128 LEHE223-LEHB223
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB224-LFB2606
	.uleb128 LEHE224-LEHB224
	.uleb128 L1752-LFB2606
	.uleb128 0
	.uleb128 LEHB225-LFB2606
	.uleb128 LEHE225-LEHB225
	.uleb128 L1746-LFB2606
	.uleb128 0
LLSDACSE2606:
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB2684:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	call	___main
	call	__Z8easyTestv
	call	__Z11thread_testv
	xorl	%eax, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	.p2align 4,,2
	ret
	.cfi_endproc
LFE2684:
	.section	.text$_ZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EEC1Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EEC1Ev
	.def	__ZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EEC1Ev:
LFB3074:
	.cfi_startproc
	movl	4(%esp), %edx
	xorl	%eax, %eax
	movl	$0, 320(%edx)
	mfence
	movl	$-1, 324(%edx)
	mfence
	.p2align 4,,7
L1904:
	movb	$0, 329(%edx,%eax)
	addl	$1, %eax
	cmpl	$20, %eax
	mfence
	jne	L1904
	rep ret
	.cfi_endproc
LFE3074:
	.section	.text$_ZN8lf_stackI6data_tLj20EE10initializeEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZN8lf_stackI6data_tLj20EE10initializeEv
	.def	__ZN8lf_stackI6data_tLj20EE10initializeEv;	.scl	2;	.type	32;	.endef
__ZN8lf_stackI6data_tLj20EE10initializeEv:
LFB3078:
	.cfi_startproc
	subl	$12, %esp
	.cfi_def_cfa_offset 16
	xorl	%eax, %eax
	movl	16(%esp), %ecx
	xorl	%edx, %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	fildq	(%esp)
	fistpq	352(%ecx)
	mfence
	movl	$0, 360(%ecx)
	mfence
	addl	$12, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3078:
	.section	.text$_ZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EEC1Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EEC1Ev
	.def	__ZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EEC1Ev:
LFB3106:
	.cfi_startproc
	movl	4(%esp), %edx
	xorl	%eax, %eax
	movl	$0, 320(%edx)
	mfence
	movl	$-1, 324(%edx)
	mfence
	.p2align 4,,7
L1909:
	movb	$0, 329(%edx,%eax)
	addl	$1, %eax
	cmpl	$20, %eax
	mfence
	jne	L1909
	rep ret
	.cfi_endproc
LFE3106:
	.section	.text$_ZN8lf_queueI6data_tLj20EE10initializeEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZN8lf_queueI6data_tLj20EE10initializeEv
	.def	__ZN8lf_queueI6data_tLj20EE10initializeEv;	.scl	2;	.type	32;	.endef
__ZN8lf_queueI6data_tLj20EE10initializeEv:
LFB3110:
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
	subl	$24, %esp
	.cfi_def_cfa_offset 40
	movl	40(%esp), %esi
	movl	320(%esi), %edx
	leal	320(%esi), %eax
	cmpl	$19, %edx
	ja	L1912
	movl	$1, %edx
	lock xaddl	%edx, (%eax)
	cmpl	$19, %edx
	jbe	L1926
	cmpl	$20, %edx
	jne	L1927
L1912:
	movl	324(%esi), %eax
	leal	324(%esi), %ecx
	movl	%eax, 8(%esp)
	.p2align 4,,7
L1916:
	cmpl	$-1, %eax
	je	L1928
L1917:
	andl	$16777215, %eax
	cmpl	$19, %eax
	movl	%eax, %edx
	jbe	L1919
	movl	(%ecx), %eax
	cmpl	$-1, %eax
	movl	%eax, 8(%esp)
	jne	L1917
L1928:
	xorl	%edi, %edi
	xorl	%eax, %eax
	xorl	%edx, %edx
L1914:
	xorl	%ebx, %ebx
	xorl	%ecx, %ecx
	movl	%ecx, (%esp)
	movl	%ebx, 4(%esp)
	fildq	(%esp)
	fistpq	(%edi)
	mfence
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	fildq	(%esp)
	fistpq	352(%esi)
	mfence
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	fildq	(%esp)
	fistpq	360(%esi)
	mfence
	movl	$0, 368(%esi)
	mfence
	addl	$24, %esp
	.cfi_remember_state
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
	.p2align 4,,7
L1919:
	.cfi_restore_state
	movl	%eax, %ebx
	sall	$4, %ebx
	addl	%esi, %ebx
	movl	(%ebx), %edi
	movl	8(%esp), %eax
	lock cmpxchgl	%edi, (%ecx)
	movl	%eax, 8(%esp)
	je	L1929
	movl	8(%esp), %eax
	jmp	L1916
	.p2align 4,,7
L1929:
	movl	$-16843010, (%ebx)
	addl	$320, %edx
	mfence
	lock subb	$1, 9(%esi,%edx)
	movl	%ebx, %eax
	movl	%ebx, %edi
	cltd
	jmp	L1914
L1927:
	movl	$20, 320(%esi)
	mfence
	jmp	L1912
L1926:
	leal	320(%edx), %eax
	lock addb	$1, 9(%esi,%eax)
	sall	$4, %edx
	leal	(%esi,%edx), %edi
	movl	%edi, %eax
	cltd
	jmp	L1914
	.cfi_endproc
LFE3110:
	.section	.text$_ZNSt11unique_lockISt5mutexE6unlockEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt11unique_lockISt5mutexE6unlockEv
	.def	__ZNSt11unique_lockISt5mutexE6unlockEv;	.scl	2;	.type	32;	.endef
__ZNSt11unique_lockISt5mutexE6unlockEv:
LFB3178:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	cmpb	$0, 4(%ebx)
	je	L1937
	movl	(%ebx), %eax
	testl	%eax, %eax
	je	L1930
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
	movb	$0, 4(%ebx)
L1930:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L1937:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__ZSt20__throw_system_errori
	.cfi_endproc
LFE3178:
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEE6_M_runEv;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEE6_M_runEv:
LFB3923:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3923
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
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	80(%esp), %esi
	movl	36(%esi), %eax
	lock addl	$1, (%eax)
	movl	28(%esi), %eax
	movb	$0, 36(%esp)
	testl	%eax, %eax
	movl	%eax, 32(%esp)
	je	L1962
	movl	%eax, (%esp)
LEHB226:
	call	_pthread_mutex_lock
LEHE226:
	testl	%eax, %eax
	jne	L1963
	movl	32(%esi), %eax
	leal	32(%esp), %edi
	movb	$1, 36(%esp)
	movl	24(%esi), %ebp
	movl	(%eax), %ebx
	jmp	L1941
	.p2align 4,,7
L1942:
	movl	%edi, 4(%esp)
	movl	%ebp, (%esp)
LEHB227:
	call	__ZNSt18condition_variable4waitERSt11unique_lockISt5mutexE
LEHE227:
L1941:
	movzbl	(%ebx), %eax
	testb	%al, %al
	je	L1942
	cmpb	$0, 36(%esp)
	jne	L1964
L1943:
	movl	40(%esi), %eax
	lock addl	$1, (%eax)
	xorl	%edi, %edi
	xorl	%ebx, %ebx
	movl	$274877907, %ebp
L1944:
	movl	48(%esi), %eax
	movl	(%eax), %eax
	cmpl	$100000, %eax
	jg	L1945
L1967:
	addl	$1, %ebx
	movl	%ebx, %eax
	imull	%ebp
	movl	%ebx, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %ebx
	je	L1965
L1946:
	movl	16(%esi), %eax
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L1949
	movl	%eax, (%esp)
LEHB228:
	call	*12(%eax)
	testl	%eax, %eax
	movl	%eax, 28(%esp)
	je	L1944
	movl	48(%esi), %edx
	lock addl	$1, (%edx)
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	20(%esi), %edx
	movl	8(%edx), %eax
	testl	%eax, %eax
	je	L1949
	movl	28(%esp), %eax
	addl	$1, %edi
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	*12(%edx)
	movl	%edi, %eax
	imull	%ebp
	movl	%edi, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %edi
	je	L1966
L1950:
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	48(%esi), %eax
	movl	(%eax), %eax
	cmpl	$100000, %eax
	jle	L1967
L1945:
	movl	44(%esi), %eax
	lock addl	$1, (%eax)
	addl	$60, %esp
	.cfi_remember_state
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
	.p2align 4,,7
L1965:
	.cfi_restore_state
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	jmp	L1946
	.p2align 4,,7
L1966:
	movl	$1000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
LEHE228:
	jmp	L1950
	.p2align 4,,7
L1964:
	movl	32(%esp), %eax
	testl	%eax, %eax
	je	L1943
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
	jmp	L1943
L1949:
	.p2align 4,,5
LEHB229:
	call	__ZSt25__throw_bad_function_callv
L1962:
	movl	$1, (%esp)
	call	__ZSt20__throw_system_errori
LEHE229:
L1953:
	cmpb	$0, 36(%esp)
	movl	%eax, %ebx
	je	L1952
	movl	%edi, (%esp)
	call	__ZNSt11unique_lockISt5mutexE6unlockEv
L1952:
	movl	%ebx, (%esp)
LEHB230:
	call	__Unwind_Resume
L1963:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE230:
	.cfi_endproc
LFE3923:
	.section	.gcc_except_table,"w"
LLSDA3923:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3923-LLSDACSB3923
LLSDACSB3923:
	.uleb128 LEHB226-LFB3923
	.uleb128 LEHE226-LEHB226
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB227-LFB3923
	.uleb128 LEHE227-LEHB227
	.uleb128 L1953-LFB3923
	.uleb128 0
	.uleb128 LEHB228-LFB3923
	.uleb128 LEHE228-LEHB228
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB229-LFB3923
	.uleb128 LEHE229-LEHB229
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB230-LFB3923
	.uleb128 LEHE230-LEHB230
	.uleb128 0
	.uleb128 0
LLSDACSE3923:
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEE6_M_runEv;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEE6_M_runEv:
LFB3922:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3922
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
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	64(%esp), %ebx
	movl	36(%ebx), %eax
	lock addl	$1, (%eax)
	movl	28(%ebx), %eax
	movb	$0, 20(%esp)
	testl	%eax, %eax
	movl	%eax, 16(%esp)
	je	L1991
	movl	%eax, (%esp)
LEHB231:
	call	_pthread_mutex_lock
LEHE231:
	testl	%eax, %eax
	jne	L1992
	movl	32(%ebx), %eax
	leal	16(%esp), %edi
	movb	$1, 20(%esp)
	movl	24(%ebx), %ebp
	movl	(%eax), %esi
	jmp	L1971
	.p2align 4,,7
L1972:
	movl	%edi, 4(%esp)
	movl	%ebp, (%esp)
LEHB232:
	call	__ZNSt18condition_variable4waitERSt11unique_lockISt5mutexE
LEHE232:
L1971:
	movzbl	(%esi), %eax
	testb	%al, %al
	je	L1972
	cmpb	$0, 20(%esp)
	jne	L1993
L1973:
	movl	40(%ebx), %eax
	lock addl	$1, (%eax)
	xorl	%edi, %edi
	xorl	%ebp, %ebp
	movl	$274877907, %esi
	.p2align 4,,7
L1974:
	movl	48(%ebx), %eax
	movl	(%eax), %eax
	cmpl	$100000, %eax
	jg	L1975
L1997:
	addl	$1, %ebp
	movl	%ebp, %eax
	imull	%esi
	movl	%ebp, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %ebp
	je	L1994
L1976:
	movl	52(%ebx), %eax
	movl	$1, %edx
	lock xaddl	%edx, (%eax)
	cmpl	$100000, %edx
	jg	L1990
	movl	20(%ebx), %eax
	movl	$0, 16(%esp)
	movl	%edx, 20(%esp)
	movl	8(%eax), %ecx
	testl	%ecx, %ecx
	je	L1995
	leal	16(%esp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
LEHB233:
	call	*12(%eax)
	testb	%al, %al
	je	L1990
	movl	48(%ebx), %eax
	lock addl	$1, (%eax)
	addl	$1, %edi
	movl	%edi, %eax
	imull	%esi
	movl	%edi, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %edi
	je	L1996
L1981:
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	48(%ebx), %eax
	movl	(%eax), %eax
	cmpl	$100000, %eax
	jle	L1997
L1975:
	movl	44(%ebx), %eax
	lock addl	$1, (%eax)
	addl	$44, %esp
	.cfi_remember_state
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
	.p2align 4,,7
L1990:
	.cfi_restore_state
	movl	52(%ebx), %eax
	lock subl	$1, (%eax)
	jmp	L1974
	.p2align 4,,7
L1994:
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	jmp	L1976
	.p2align 4,,7
L1996:
	movl	$1000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
LEHE233:
	jmp	L1981
	.p2align 4,,7
L1993:
	movl	16(%esp), %eax
	testl	%eax, %eax
	je	L1973
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
	jmp	L1973
L1995:
	.p2align 4,,5
LEHB234:
	call	__ZSt25__throw_bad_function_callv
L1991:
	movl	$1, (%esp)
	call	__ZSt20__throw_system_errori
LEHE234:
L1984:
	cmpb	$0, 20(%esp)
	movl	%eax, %ebx
	je	L1983
	movl	%edi, (%esp)
	call	__ZNSt11unique_lockISt5mutexE6unlockEv
L1983:
	movl	%ebx, (%esp)
LEHB235:
	call	__Unwind_Resume
L1992:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE235:
	.cfi_endproc
LFE3922:
	.section	.gcc_except_table,"w"
LLSDA3922:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3922-LLSDACSB3922
LLSDACSB3922:
	.uleb128 LEHB231-LFB3922
	.uleb128 LEHE231-LEHB231
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB232-LFB3922
	.uleb128 LEHE232-LEHB232
	.uleb128 L1984-LFB3922
	.uleb128 0
	.uleb128 LEHB233-LFB3922
	.uleb128 LEHE233-LEHB233
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB234-LFB3922
	.uleb128 LEHE234-LEHB234
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB235-LFB3922
	.uleb128 LEHE235-LEHB235
	.uleb128 0
	.uleb128 0
LLSDACSE3922:
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEE6_M_runEv;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEE6_M_runEv:
LFB3921:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3921
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
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	64(%esp), %ebx
	movl	36(%ebx), %eax
	lock addl	$1, (%eax)
	movl	28(%ebx), %eax
	movb	$0, 20(%esp)
	testl	%eax, %eax
	movl	%eax, 16(%esp)
	je	L2019
	movl	%eax, (%esp)
LEHB236:
	call	_pthread_mutex_lock
LEHE236:
	testl	%eax, %eax
	jne	L2020
	movl	32(%ebx), %eax
	leal	16(%esp), %edi
	movb	$1, 20(%esp)
	movl	24(%ebx), %ebp
	movl	(%eax), %esi
	jmp	L2001
	.p2align 4,,7
L2002:
	movl	%edi, 4(%esp)
	movl	%ebp, (%esp)
LEHB237:
	call	__ZNSt18condition_variable4waitERSt11unique_lockISt5mutexE
LEHE237:
L2001:
	movzbl	(%esi), %eax
	testb	%al, %al
	je	L2002
	cmpb	$0, 20(%esp)
	jne	L2021
L2003:
	movl	40(%ebx), %eax
	lock addl	$1, (%eax)
	leal	16(%esp), %esi
	jmp	L2004
	.p2align 4,,7
L2006:
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
LEHB238:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
L2004:
	movl	48(%ebx), %eax
	movl	(%eax), %eax
	cmpl	$100000, %eax
	jg	L2022
	movl	20(%ebx), %eax
	movl	8(%eax), %edi
	testl	%edi, %edi
	je	L2023
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	*12(%eax)
LEHE238:
	testb	%al, %al
	je	L2006
	movl	48(%ebx), %eax
	lock addl	$1, (%eax)
	jmp	L2006
	.p2align 4,,7
L2022:
	movl	44(%ebx), %eax
	lock addl	$1, (%eax)
	addl	$44, %esp
	.cfi_remember_state
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
	.p2align 4,,7
L2021:
	.cfi_restore_state
	movl	16(%esp), %eax
	testl	%eax, %eax
	je	L2003
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
	jmp	L2003
L2023:
	.p2align 4,,5
LEHB239:
	call	__ZSt25__throw_bad_function_callv
L2019:
	movl	$1, (%esp)
	call	__ZSt20__throw_system_errori
LEHE239:
L2010:
	cmpb	$0, 20(%esp)
	movl	%eax, %ebx
	je	L2009
	movl	%edi, (%esp)
	call	__ZNSt11unique_lockISt5mutexE6unlockEv
L2009:
	movl	%ebx, (%esp)
LEHB240:
	call	__Unwind_Resume
L2020:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE240:
	.cfi_endproc
LFE3921:
	.section	.gcc_except_table,"w"
LLSDA3921:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3921-LLSDACSB3921
LLSDACSB3921:
	.uleb128 LEHB236-LFB3921
	.uleb128 LEHE236-LEHB236
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB237-LFB3921
	.uleb128 LEHE237-LEHB237
	.uleb128 L2010-LFB3921
	.uleb128 0
	.uleb128 LEHB238-LFB3921
	.uleb128 LEHE238-LEHB238
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB239-LFB3921
	.uleb128 LEHE239-LEHB239
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB240-LFB3921
	.uleb128 LEHE240-LEHB240
	.uleb128 0
	.uleb128 0
LLSDACSE3921:
	.text
	.section	.text.startup,"x"
	.p2align 4,,15
	.def	__GLOBAL__sub_I__Z11allocNormalv;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z11allocNormalv:
LFB3977:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL17s_lfPoolAllocator, (%esp)
	movl	$0, __ZL15s_poolAllocator+160
	movl	$-1, __ZL15s_poolAllocator+164
	movl	$0, __ZL15s_poolAllocator+168
	movl	$20, __ZL15s_poolAllocator+172
	call	__ZN17lf_pool_allocatorI6data_tLj20EEC1Ev
	movl	$__ZL9s_lfStack, (%esp)
	movl	$0, __ZL7s_stack+240
	movl	$-1, __ZL7s_stack+244
	movl	$0, __ZL7s_stack+248
	movl	$20, __ZL7s_stack+252
	movl	$20, __ZL7s_stack+260
	movl	$0, __ZL7s_stack+256
	call	__ZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EEC1Ev
	movl	$__ZL9s_lfStack, (%esp)
	call	__ZN8lf_stackI6data_tLj20EE10initializeEv
	movl	$__ZL7s_queue, (%esp)
	call	__ZN5queueI6data_tLj20EEC1Ev
	movl	$__ZL9s_lfQueue, (%esp)
	call	__ZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EEC1Ev
	movl	$__ZL9s_lfQueue, (%esp)
	call	__ZN8lf_queueI6data_tLj20EE10initializeEv
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3977:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z11allocNormalv
	.section	.text.exit,"x"
	.p2align 4,,15
	.def	__GLOBAL__sub_D__Z11allocNormalv;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_D__Z11allocNormalv:
LFB3978:
	.cfi_startproc
	jmp	__Z41__static_initialization_and_destruction_0ii.part.314
	.cfi_endproc
LFE3978:
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__sub_D__Z11allocNormalv
	.section .rdata,"dr"
	.align 32
__ZZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__:
	.ascii "std::size_t lf_pool_allocator<T, POOL>::ptrToIndex(void*) [with T = lf_queue<data_t, 20u>::queue_t; unsigned int POOL = 20u; std::size_t = unsigned int]\0"
	.align 32
__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__:
	.ascii "std::size_t pool_allocator<T, POOL>::ptrToIndex(void*) [with T = queue<data_t, 20u>::queue_t; unsigned int POOL = 20u; std::size_t = unsigned int]\0"
	.align 32
__ZZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__:
	.ascii "std::size_t lf_pool_allocator<T, POOL>::ptrToIndex(void*) [with T = lf_stack<data_t, 20u>::stack_t; unsigned int POOL = 20u; std::size_t = unsigned int]\0"
	.align 32
__ZZN14pool_allocatorIN5stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__:
	.ascii "std::size_t pool_allocator<T, POOL>::ptrToIndex(void*) [with T = stack<data_t, 20u>::stack_t; unsigned int POOL = 20u; std::size_t = unsigned int]\0"
	.align 32
__ZZN17lf_pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__:
	.ascii "std::size_t lf_pool_allocator<T, POOL>::ptrToIndex(void*) [with T = data_t; unsigned int POOL = 20u; std::size_t = unsigned int]\0"
	.align 32
__ZZN14pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__:
	.ascii "std::size_t pool_allocator<T, POOL>::ptrToIndex(void*) [with T = data_t; unsigned int POOL = 20u; std::size_t = unsigned int]\0"
	.globl	__ZTISt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE
	.section	.rdata$_ZTISt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE,"dr"
	.linkonce same_size
	.align 4
__ZTISt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE
	.globl	__ZTSSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE
	.section	.rdata$_ZTSSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE,"dr"
	.linkonce same_size
	.align 32
__ZTSSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE:
	.ascii "St11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE\0"
	.section .rdata,"dr"
	.align 32
__ZTSNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEEE:
	.ascii "*NSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEEE\0"
	.align 32
__ZTSNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEEE:
	.ascii "*NSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEEE\0"
	.align 32
__ZTSNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEEE:
	.ascii "*NSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEEE\0"
__ZTSZ8easyTestvEUlvE2_:
	.ascii "*Z8easyTestvEUlvE2_\0"
__ZTSZ8easyTestvEUlP6data_tE3_:
	.ascii "*Z8easyTestvEUlP6data_tE3_\0"
__ZTSZ8easyTestvEUlvE4_:
	.ascii "*Z8easyTestvEUlvE4_\0"
__ZTSZ8easyTestvEUlP6data_tE5_:
	.ascii "*Z8easyTestvEUlP6data_tE5_\0"
__ZTSZ8easyTestvEUlO6data_tE6_:
	.ascii "*Z8easyTestvEUlO6data_tE6_\0"
__ZTSZ8easyTestvEUlR6data_tE7_:
	.ascii "*Z8easyTestvEUlR6data_tE7_\0"
__ZTSZ8easyTestvEUlO6data_tE8_:
	.ascii "*Z8easyTestvEUlO6data_tE8_\0"
__ZTSZ8easyTestvEUlR6data_tE9_:
	.ascii "*Z8easyTestvEUlR6data_tE9_\0"
__ZTSZ8easyTestvEUlO6data_tE10_:
	.ascii "*Z8easyTestvEUlO6data_tE10_\0"
__ZTSZ8easyTestvEUlR6data_tE11_:
	.ascii "*Z8easyTestvEUlR6data_tE11_\0"
__ZTSZ8easyTestvEUlO6data_tE12_:
	.ascii "*Z8easyTestvEUlO6data_tE12_\0"
__ZTSZ8easyTestvEUlR6data_tE13_:
	.ascii "*Z8easyTestvEUlR6data_tE13_\0"
__ZTSZ11thread_testvEUlvE2_:
	.ascii "*Z11thread_testvEUlvE2_\0"
	.align 4
__ZTSZ11thread_testvEUlP6data_tE3_:
	.ascii "*Z11thread_testvEUlP6data_tE3_\0"
__ZTSZ11thread_testvEUlvE4_:
	.ascii "*Z11thread_testvEUlvE4_\0"
	.align 4
__ZTSZ11thread_testvEUlP6data_tE5_:
	.ascii "*Z11thread_testvEUlP6data_tE5_\0"
	.align 4
__ZTSZ11thread_testvEUlO6data_tE6_:
	.ascii "*Z11thread_testvEUlO6data_tE6_\0"
	.align 4
__ZTSZ11thread_testvEUlR6data_tE7_:
	.ascii "*Z11thread_testvEUlR6data_tE7_\0"
	.align 4
__ZTSZ11thread_testvEUlO6data_tE8_:
	.ascii "*Z11thread_testvEUlO6data_tE8_\0"
	.align 4
__ZTSZ11thread_testvEUlR6data_tE9_:
	.ascii "*Z11thread_testvEUlR6data_tE9_\0"
	.align 32
__ZTSZ11thread_testvEUlO6data_tE10_:
	.ascii "*Z11thread_testvEUlO6data_tE10_\0"
	.align 32
__ZTSZ11thread_testvEUlR6data_tE11_:
	.ascii "*Z11thread_testvEUlR6data_tE11_\0"
	.align 32
__ZTSZ11thread_testvEUlO6data_tE12_:
	.ascii "*Z11thread_testvEUlO6data_tE12_\0"
	.align 32
__ZTSZ11thread_testvEUlR6data_tE13_:
	.ascii "*Z11thread_testvEUlR6data_tE13_\0"
	.align 32
__ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE:
	.ascii "*St23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE\0"
	.align 32
__ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE:
	.ascii "*St23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE\0"
	.align 32
__ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE:
	.ascii "*St23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE\0"
	.align 4
__ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE
	.long	__ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.align 4
__ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE
	.long	__ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.align 4
__ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE
	.long	__ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.align 4
__ZTIZ11thread_testvEUlR6data_tE13_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ11thread_testvEUlR6data_tE13_
	.align 4
__ZTIZ11thread_testvEUlO6data_tE12_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ11thread_testvEUlO6data_tE12_
	.align 4
__ZTIZ11thread_testvEUlR6data_tE11_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ11thread_testvEUlR6data_tE11_
	.align 4
__ZTIZ11thread_testvEUlO6data_tE10_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ11thread_testvEUlO6data_tE10_
	.align 4
__ZTIZ11thread_testvEUlR6data_tE9_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ11thread_testvEUlR6data_tE9_
	.align 4
__ZTIZ11thread_testvEUlO6data_tE8_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ11thread_testvEUlO6data_tE8_
	.align 4
__ZTIZ11thread_testvEUlR6data_tE7_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ11thread_testvEUlR6data_tE7_
	.align 4
__ZTIZ11thread_testvEUlO6data_tE6_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ11thread_testvEUlO6data_tE6_
	.align 4
__ZTIZ11thread_testvEUlP6data_tE5_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ11thread_testvEUlP6data_tE5_
	.align 4
__ZTIZ11thread_testvEUlvE4_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ11thread_testvEUlvE4_
	.align 4
__ZTIZ11thread_testvEUlP6data_tE3_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ11thread_testvEUlP6data_tE3_
	.align 4
__ZTIZ11thread_testvEUlvE2_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ11thread_testvEUlvE2_
	.align 4
__ZTIZ8easyTestvEUlR6data_tE13_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ8easyTestvEUlR6data_tE13_
	.align 4
__ZTIZ8easyTestvEUlO6data_tE12_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ8easyTestvEUlO6data_tE12_
	.align 4
__ZTIZ8easyTestvEUlR6data_tE11_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ8easyTestvEUlR6data_tE11_
	.align 4
__ZTIZ8easyTestvEUlO6data_tE10_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ8easyTestvEUlO6data_tE10_
	.align 4
__ZTIZ8easyTestvEUlR6data_tE9_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ8easyTestvEUlR6data_tE9_
	.align 4
__ZTIZ8easyTestvEUlO6data_tE8_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ8easyTestvEUlO6data_tE8_
	.align 4
__ZTIZ8easyTestvEUlR6data_tE7_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ8easyTestvEUlR6data_tE7_
	.align 4
__ZTIZ8easyTestvEUlO6data_tE6_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ8easyTestvEUlO6data_tE6_
	.align 4
__ZTIZ8easyTestvEUlP6data_tE5_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ8easyTestvEUlP6data_tE5_
	.align 4
__ZTIZ8easyTestvEUlvE4_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ8easyTestvEUlvE4_
	.align 4
__ZTIZ8easyTestvEUlP6data_tE3_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ8easyTestvEUlP6data_tE3_
	.align 4
__ZTIZ8easyTestvEUlvE2_:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSZ8easyTestvEUlvE2_
	.align 4
__ZTINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEEE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTSNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEEE
	.long	__ZTINSt6thread10_Impl_baseE
	.align 4
__ZTINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEEE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTSNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEEE
	.long	__ZTINSt6thread10_Impl_baseE
	.align 4
__ZTINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEEE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTSNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEEE
	.long	__ZTINSt6thread10_Impl_baseE
	.globl	__ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.section	.rdata$_ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE,"dr"
	.linkonce same_size
	.align 4
__ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTSSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.long	__ZTISt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE
	.globl	__ZTSSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.section	.rdata$_ZTSSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE,"dr"
	.linkonce same_size
	.align 32
__ZTSSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE:
	.ascii "St16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE\0"
	.globl	__ZTINSt6thread10_Impl_baseE
	.section	.rdata$_ZTINSt6thread10_Impl_baseE,"dr"
	.linkonce same_size
	.align 4
__ZTINSt6thread10_Impl_baseE:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSNSt6thread10_Impl_baseE
	.globl	__ZTSNSt6thread10_Impl_baseE
	.section	.rdata$_ZTSNSt6thread10_Impl_baseE,"dr"
	.linkonce same_size
__ZTSNSt6thread10_Impl_baseE:
	.ascii "NSt6thread10_Impl_baseE\0"
	.globl	__ZTISt19_Sp_make_shared_tag
	.section	.rdata$_ZTISt19_Sp_make_shared_tag,"dr"
	.linkonce same_size
	.align 4
__ZTISt19_Sp_make_shared_tag:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSSt19_Sp_make_shared_tag
	.globl	__ZTSSt19_Sp_make_shared_tag
	.section	.rdata$_ZTSSt19_Sp_make_shared_tag,"dr"
	.linkonce same_size
__ZTSSt19_Sp_make_shared_tag:
	.ascii "St19_Sp_make_shared_tag\0"
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
	.section .rdata,"dr"
	.align 8
__ZTVNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEEE:
	.long	0
	.long	__ZTINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEEE
	.long	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED1Ev
	.long	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED0Ev
	.long	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEE6_M_runEv
	.align 8
__ZTVNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEEE:
	.long	0
	.long	__ZTINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEEE
	.long	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED1Ev
	.long	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED0Ev
	.long	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEE6_M_runEv
	.align 8
__ZTVNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEEE:
	.long	0
	.long	__ZTINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEEE
	.long	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED1Ev
	.long	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED0Ev
	.long	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEE6_M_runEv
	.align 8
__ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE:
	.long	0
	.long	__ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED1Ev
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED0Ev
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info
	.align 8
__ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE:
	.long	0
	.long	__ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED1Ev
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED0Ev
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info
	.align 8
__ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE:
	.long	0
	.long	__ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED1Ev
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED0Ev
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv
	.long	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info
.lcomm __ZL9s_lfQueue,376,32
.lcomm __ZL7s_queue,268,32
.lcomm __ZL9s_lfStack,368,32
.lcomm __ZL7s_stack,264,32
.lcomm __ZL17s_lfPoolAllocator,192,32
.lcomm __ZL15s_poolAllocator,176,32
	.align 4
LC12:
	.long	1315859240
	.ident	"GCC: (GNU) 4.8.2"
	.def	___real__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt9type_infoeqERKS_;	.scl	2;	.type	32;	.endef
	.def	___real__Znwj;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	___assert_func;	.scl	2;	.type	32;	.endef
	.def	_pthread_mutex_lock;	.scl	2;	.type	32;	.endef
	.def	_pthread_mutex_unlock;	.scl	2;	.type	32;	.endef
	.def	__ZSt20__throw_system_errori;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZSt9terminatev;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6chrono3_V212system_clock3nowEv;	.scl	2;	.type	32;	.endef
	.def	__ZSt25__throw_bad_function_callv;	.scl	2;	.type	32;	.endef
	.def	__ZNSt18condition_variableC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6thread15_M_start_threadESt10shared_ptrINS_10_Impl_baseEE;	.scl	2;	.type	32;	.endef
	.def	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE;	.scl	2;	.type	32;	.endef
	.def	__ZNSt18condition_variable10notify_allEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6thread4joinEv;	.scl	2;	.type	32;	.endef
	.def	_pthread_equal;	.scl	2;	.type	32;	.endef
	.def	__ZNSt18condition_variableD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZSt9terminatev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt18condition_variable4waitERSt11unique_lockISt5mutexE;	.scl	2;	.type	32;	.endef
	.def	___cxa_pure_virtual;	.scl	2;	.type	32;	.endef

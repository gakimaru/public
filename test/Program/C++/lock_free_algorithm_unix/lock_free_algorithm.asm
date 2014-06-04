	.file	"lock_free_algorithm.cpp"
	.section	.text$_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv
	.def	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv;	.scl	2;	.type	32;	.endef
__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv:
LFB3125:
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
LFE3125:
	.section	.text$_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED1Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED1Ev
	.def	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED1Ev:
LFB3315:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	ret
	.cfi_endproc
LFE3315:
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED2Ev;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED2Ev:
LFB3612:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	ret
	.cfi_endproc
LFE3612:
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED1Ev;	.scl	3;	.type	32;	.endef
	.set	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED1Ev,__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED2Ev
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv:
LFB3615:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	12(%eax), %eax
	movl	(%eax), %edx
	movl	%eax, 4(%esp)
	movl	(%edx), %eax
	jmp	*%eax
	.cfi_endproc
LFE3615:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED2Ev;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED2Ev:
LFB3619:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	ret
	.cfi_endproc
LFE3619:
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED1Ev;	.scl	3;	.type	32;	.endef
	.set	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED1Ev,__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED2Ev
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv:
LFB3622:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	12(%eax), %eax
	movl	(%eax), %edx
	movl	%eax, 4(%esp)
	movl	(%edx), %eax
	jmp	*%eax
	.cfi_endproc
LFE3622:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED2Ev;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED2Ev:
LFB3626:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	ret
	.cfi_endproc
LFE3626:
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED1Ev;	.scl	3;	.type	32;	.endef
	.set	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED1Ev,__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED2Ev
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv:
LFB3629:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	12(%eax), %eax
	movl	(%eax), %edx
	movl	%eax, 4(%esp)
	movl	(%edx), %eax
	jmp	*%eax
	.cfi_endproc
LFE3629:
	.section	.text$_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED0Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED0Ev
	.def	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED0Ev;	.scl	2;	.type	32;	.endef
__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EED0Ev:
LFB3316:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	jmp	__ZdlPv
	.cfi_endproc
LFE3316:
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv:
LFB3630:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	jmp	__ZdlPv
	.cfi_endproc
LFE3630:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED0Ev;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EED0Ev:
LFB3628:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	jmp	__ZdlPv
	.cfi_endproc
LFE3628:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv:
LFB3623:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	jmp	__ZdlPv
	.cfi_endproc
LFE3623:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED0Ev;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED0Ev:
LFB3621:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	jmp	__ZdlPv
	.cfi_endproc
LFE3621:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv:
LFB3616:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	jmp	__ZdlPv
	.cfi_endproc
LFE3616:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED0Ev;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EED0Ev:
LFB3614:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	$__ZTVSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE+8, (%eax)
	jmp	__ZdlPv
	.cfi_endproc
LFE3614:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES5_IFbS7_EEE_clES4_S9_SB_EUliE0_iEEEESaISG_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info:
LFB3631:
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
LFE3631:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE0_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info:
LFB3624:
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
LFE3624:
	.align 2
	.p2align 4,,15
	.def	__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info;	.scl	3;	.type	32;	.endef
__ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS4_S4_St8functionIFbO6data_tEES5_IFbRS6_EEE0_clES4_S4_S4_S9_SC_EUliE1_iEEEESaISH_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info:
LFB3617:
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
LFE3617:
	.section	.text.unlikely,"x"
	.align 2
	.def	__ZNSt6bitsetILj20EE9referenceaSEb.part.144;	.scl	3;	.type	32;	.endef
__ZNSt6bitsetILj20EE9referenceaSEb.part.144:
LFB3837:
	.cfi_startproc
	movl	4(%eax), %ecx
	movl	(%eax), %edx
	movl	$1, %eax
	sall	%cl, %eax
	orl	%eax, (%edx)
	ret
	.cfi_endproc
LFE3837:
	.text
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlP6data_tE3_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlP6data_tE3_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3073:
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
	movl	$__ZTIZ11thread_testvEUlP6data_tE3_, (%eax)
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
LFE3073:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlvE2_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlvE2_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation:
LFB3068:
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
	movl	$__ZTIZ11thread_testvEUlvE2_, (%eax)
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
LFE3068:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlP6data_tE5_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlP6data_tE5_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3082:
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
	movl	$__ZTIZ11thread_testvEUlP6data_tE5_, (%eax)
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
LFE3082:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlvE4_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlvE4_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation:
LFB3078:
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
	movl	$__ZTIZ11thread_testvEUlvE4_, (%eax)
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
LFE3078:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE7_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE7_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3091:
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
	movl	$__ZTIZ11thread_testvEUlR6data_tE7_, (%eax)
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
LFE3091:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE6_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE6_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3086:
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
	movl	$__ZTIZ11thread_testvEUlO6data_tE6_, (%eax)
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
LFE3086:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE9_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE9_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3100:
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
	movl	$__ZTIZ11thread_testvEUlR6data_tE9_, (%eax)
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
LFE3100:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE8_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE8_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3096:
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
	movl	$__ZTIZ11thread_testvEUlO6data_tE8_, (%eax)
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
LFE3096:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE11_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE11_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3108:
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
	movl	$__ZTIZ11thread_testvEUlR6data_tE11_, (%eax)
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
LFE3108:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE10_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE10_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3104:
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
	movl	$__ZTIZ11thread_testvEUlO6data_tE10_, (%eax)
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
LFE3104:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE13_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE13_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3116:
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
	movl	$__ZTIZ11thread_testvEUlR6data_tE13_, (%eax)
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
LFE3116:
	.p2align 4,,15
	.def	__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE12_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation;	.scl	3;	.type	32;	.endef
__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE12_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation:
LFB3112:
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
	movl	$__ZTIZ11thread_testvEUlO6data_tE12_, (%eax)
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
LFE3112:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E8_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E8_E9_M_invokeERKSt9_Any_dataS1_:
LFB3095:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	movl	$1, %eax
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$48, %esp
	.cfi_def_cfa_offset 64
	lock xaddl	%eax, __ZL9s_lfStack+320
	cmpl	$19, %eax
	jbe	L156
	movl	$20, __ZL9s_lfStack+320
	movl	$1, %edx
	mfence
	movl	__ZL9s_lfStack+324, %eax
	movl	%eax, 32(%esp)
L142:
	cmpl	$-1, %eax
	je	L145
L157:
	addl	$320, %eax
	movl	$1, %ecx
	lock xaddb	%cl, __ZL9s_lfStack+8(%eax)
	testb	%cl, %cl
	je	L146
	movl	32(%esp), %eax
	addl	$320, %eax
	lock subb	$1, __ZL9s_lfStack+8(%eax)
	movl	__ZL9s_lfStack+324, %eax
	addl	$1, %edx
	cmpl	$1000, %edx
	movl	%eax, 32(%esp)
	je	L143
L159:
	movl	32(%esp), %eax
	cmpl	$-1, %eax
	jne	L157
L145:
	xorl	%eax, %eax
L154:
	addl	$48, %esp
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
L146:
	.cfi_restore_state
	movl	32(%esp), %edi
	leal	32(%esp), %esi
	movl	%edi, %ecx
	movl	%edi, %eax
	sall	$4, %ecx
	leal	__ZL9s_lfStack(%ecx), %ebx
	movl	__ZL9s_lfStack(%ecx), %ecx
	lock cmpxchgl	%ecx, __ZL9s_lfStack+324
	movl	%eax, 32(%esp)
	je	L158
	addl	$320, %edi
	lock subb	$1, __ZL9s_lfStack+8(%edi)
	addl	$1, %edx
	cmpl	$1000, %edx
	jne	L159
L143:
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	__ZL9s_lfStack+324, %eax
	xorl	%edx, %edx
	movl	%eax, 32(%esp)
	jmp	L142
	.p2align 4,,7
L156:
	leal	320(%eax), %edx
	lock addb	$1, __ZL9s_lfStack+8(%edx)
	movl	%eax, %edx
	sall	$4, %edx
	leal	__ZL9s_lfStack(%edx), %ebx
	movl	$-16843010, __ZL9s_lfStack(%edx)
	lock addl	$1, __ZL9s_lfStack+348
	leal	352(,%eax,4), %eax
	lock addl	$1, __ZL9s_lfStack(%eax)
	leal	32(%esp), %esi
L141:
	movl	$0, 12(%ebx)
	movl	$1, %ecx
	movl	$0, 8(%ebx)
	movl	$0, (%ebx)
	movl	$0, 4(%ebx)
	movq	__ZL9s_lfStack+512, %xmm0
	movq	%xmm0, (%ebx)
	mfence
	movl	68(%esp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%edx, 12(%ebx)
	movl	%eax, 8(%ebx)
	lock xaddl	%ecx, __ZL9s_lfStack+520
	movl	%ebx, %eax
	cltd
	orl	%edx, %ecx
L153:
	fildq	(%ebx)
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	fildq	__ZL9s_lfStack+512
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	xorl	36(%esp), %edx
	xorl	32(%esp), %eax
	orl	%eax, %edx
	jne	L149
	movl	(%esi), %eax
	movl	4(%esi), %edx
	lock cmpxchg8b	__ZL9s_lfStack+512
	movl	%eax, %edi
	sete	%al
	testb	%al, %al
	movl	%edi, (%esi)
	movl	%edx, 4(%esi)
	jne	L154
	fildq	32(%esp)
	fistpq	(%ebx)
	mfence
	jmp	L153
	.p2align 4,,7
L149:
	movq	__ZL9s_lfStack+512, %xmm0
	movq	%xmm0, (%ebx)
	mfence
	jmp	L153
	.p2align 4,,7
L158:
	sall	$4, %eax
	movl	$-16843010, __ZL9s_lfStack(%eax)
	lock addl	$1, __ZL9s_lfStack+348
	movl	32(%esp), %eax
	leal	352(,%eax,4), %eax
	lock addl	$1, __ZL9s_lfStack(%eax)
	jmp	L141
	.cfi_endproc
LFE3095:
	.section .rdata,"dr"
LC1:
	.ascii "IS_INVALID_POINTER_OF_POOL\0"
LC2:
	.ascii "lock_free_algorithm.cpp\0"
LC3:
	.ascii "IS_ALREADY_DELETE_POINTER\0"
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbP6data_tEZ11thread_testvEUlS1_E3_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbP6data_tEZ11thread_testvEUlS1_E3_E9_M_invokeERKSt9_Any_dataS1_:
LFB3072:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3072
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL15s_poolAllocator+176, (%esp)
LEHB0:
	call	_pthread_mutex_lock
LEHE0:
	testl	%eax, %eax
	jne	L168
	movl	36(%esp), %ecx
	subl	$__ZL15s_poolAllocator, %ecx
	shrl	$3, %ecx
	cmpl	$19, %ecx
	ja	L169
	movl	__ZL15s_poolAllocator+168, %edx
	movl	$1, %eax
	sall	%cl, %eax
	testl	%edx, %eax
	je	L170
	movl	__ZL15s_poolAllocator+164, %ebx
	notl	%eax
	andl	%edx, %eax
	movl	$__ZL15s_poolAllocator+176, (%esp)
	movl	%ebx, __ZL15s_poolAllocator(,%ecx,8)
	movl	%ecx, __ZL15s_poolAllocator+164
	movl	%eax, __ZL15s_poolAllocator+168
	subl	$1, __ZL15s_poolAllocator+172
	call	_pthread_mutex_unlock
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	movl	$1, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L168:
	.cfi_restore_state
	movl	%eax, (%esp)
LEHB1:
	call	__ZSt20__throw_system_errori
LEHE1:
L170:
	movl	$LC3, 12(%esp)
	movl	$__ZZN14pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$230, 4(%esp)
	movl	$LC2, (%esp)
LEHB2:
	call	___assert_func
LEHE2:
L165:
	movl	%eax, %ebx
	movl	$__ZL15s_poolAllocator+176, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, (%esp)
LEHB3:
	call	__Unwind_Resume
LEHE3:
L169:
	movl	$LC1, 12(%esp)
	movl	$__ZZN14pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$224, 4(%esp)
	movl	$LC2, (%esp)
LEHB4:
	call	___assert_func
LEHE4:
	.cfi_endproc
LFE3072:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA3072:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3072-LLSDACSB3072
LLSDACSB3072:
	.uleb128 LEHB0-LFB3072
	.uleb128 LEHE0-LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB1-LFB3072
	.uleb128 LEHE1-LEHB1
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB2-LFB3072
	.uleb128 LEHE2-LEHB2
	.uleb128 L165-LFB3072
	.uleb128 0
	.uleb128 LEHB3-LFB3072
	.uleb128 LEHE3-LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB4-LFB3072
	.uleb128 LEHE4-LEHB4
	.uleb128 L165-LFB3072
	.uleb128 0
LLSDACSE3072:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFP6data_tvEZ11thread_testvEUlvE2_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFP6data_tvEZ11thread_testvEUlvE2_E9_M_invokeERKSt9_Any_data:
LFB3067:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3067
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL15s_poolAllocator+176, (%esp)
LEHB5:
	call	_pthread_mutex_lock
LEHE5:
	testl	%eax, %eax
	jne	L179
	movl	__ZL15s_poolAllocator+160, %ecx
	cmpl	$19, %ecx
	jbe	L180
	movl	__ZL15s_poolAllocator+164, %ecx
	cmpl	$-1, %ecx
	je	L175
	movl	__ZL15s_poolAllocator(,%ecx,8), %eax
	leal	__ZL15s_poolAllocator(,%ecx,8), %ebx
	movl	%eax, __ZL15s_poolAllocator+164
	movl	$1, %eax
	movl	$-16843010, __ZL15s_poolAllocator(,%ecx,8)
	sall	%cl, %eax
	addl	$1, __ZL15s_poolAllocator+172
	orl	%eax, __ZL15s_poolAllocator+168
L174:
	movl	$__ZL15s_poolAllocator+176, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, %eax
	movl	$0, (%ebx)
	movl	$0, 4(%ebx)
L177:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L180:
	.cfi_restore_state
	leal	1(%ecx), %eax
	movl	%eax, __ZL15s_poolAllocator+160
	movl	$1, %eax
	movl	$-16843010, __ZL15s_poolAllocator(,%ecx,8)
	sall	%cl, %eax
	addl	$1, __ZL15s_poolAllocator+172
	orl	%eax, __ZL15s_poolAllocator+168
	leal	__ZL15s_poolAllocator(,%ecx,8), %ebx
	jmp	L174
	.p2align 4,,7
L175:
	movl	$__ZL15s_poolAllocator+176, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L177
L179:
	movl	%eax, (%esp)
LEHB6:
	call	__ZSt20__throw_system_errori
LEHE6:
	.cfi_endproc
LFE3067:
	.section	.gcc_except_table,"w"
LLSDA3067:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3067-LLSDACSB3067
LLSDACSB3067:
	.uleb128 LEHB5-LFB3067
	.uleb128 LEHE5-LEHB5
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB6-LFB3067
	.uleb128 LEHE6-LEHB6
	.uleb128 0
	.uleb128 0
LLSDACSE3067:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbP6data_tEZ11thread_testvEUlS1_E5_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbP6data_tEZ11thread_testvEUlS1_E5_E9_M_invokeERKSt9_Any_dataS1_:
LFB3081:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$40, %esp
	.cfi_def_cfa_offset 48
	movl	52(%esp), %edx
	subl	$__ZL17s_lfPoolAllocator, %edx
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L187
	movzbl	__ZL17s_lfPoolAllocator+168(%edx), %eax
	leal	__ZL17s_lfPoolAllocator+168(%edx), %ebx
	testb	%al, %al
	je	L188
	movl	__ZL17s_lfPoolAllocator+164, %eax
	leal	__ZL17s_lfPoolAllocator(,%edx,8), %ecx
	movl	%eax, 16(%esp)
	.p2align 4,,7
L185:
	movl	%eax, (%ecx)
	movl	16(%esp), %eax
	lock cmpxchgl	%edx, __ZL17s_lfPoolAllocator+164
	movl	%eax, 16(%esp)
	jne	L185
	lock subb	$1, (%ebx)
	lock subl	$1, __ZL17s_lfPoolAllocator+188
	leal	272(,%edx,4), %eax
	lock addl	$1, __ZL17s_lfPoolAllocator(%eax)
	movl	$1, %eax
	addl	$40, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L187:
	.cfi_restore_state
	movl	$LC1, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$460, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
L188:
	movl	$LC3, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$466, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
	.cfi_endproc
LFE3081:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E6_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E6_E9_M_invokeERKSt9_Any_dataS1_:
LFB3085:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3085
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_stack+256, (%esp)
LEHB7:
	call	_pthread_mutex_lock
LEHE7:
	testl	%eax, %eax
	jne	L194
	movl	__ZL7s_stack+240, %ecx
	cmpl	$19, %ecx
	jbe	L200
	movl	__ZL7s_stack+244, %ecx
	cmpl	$-1, %ecx
	je	L193
	leal	(%ecx,%ecx,2), %eax
	sall	$2, %eax
	movl	__ZL7s_stack(%eax), %edx
	leal	__ZL7s_stack(%eax), %ebx
	movl	%edx, __ZL7s_stack+244
	movl	$1, %edx
	movl	$-16843010, __ZL7s_stack(%eax)
	sall	%cl, %edx
	addl	$1, __ZL7s_stack+252
	orl	%edx, __ZL7s_stack+248
L192:
	movl	$__ZL7s_stack+256, (%esp)
	call	_pthread_mutex_unlock
	movl	36(%esp), %eax
	movl	$0, 8(%ebx)
	movl	$0, 4(%ebx)
	movl	$0, (%ebx)
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	$__ZL7s_stack+264, (%esp)
	movl	%edx, 8(%ebx)
	movl	%eax, 4(%ebx)
LEHB8:
	call	_pthread_mutex_lock
LEHE8:
	testl	%eax, %eax
	jne	L194
	movl	__ZL7s_stack+260, %eax
	movl	$__ZL7s_stack+264, (%esp)
	movl	%eax, (%ebx)
	movl	%ebx, __ZL7s_stack+260
	call	_pthread_mutex_unlock
	movl	$1, %eax
L197:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L200:
	.cfi_restore_state
	leal	1(%ecx), %eax
	leal	(%ecx,%ecx,2), %edx
	movl	%eax, __ZL7s_stack+240
	sall	$2, %edx
	movl	$1, %eax
	movl	$-16843010, __ZL7s_stack(%edx)
	sall	%cl, %eax
	addl	$1, __ZL7s_stack+252
	orl	%eax, __ZL7s_stack+248
	leal	__ZL7s_stack(%edx), %ebx
	jmp	L192
	.p2align 4,,7
L193:
	movl	$__ZL7s_stack+256, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L197
L194:
	movl	%eax, (%esp)
LEHB9:
	call	__ZSt20__throw_system_errori
LEHE9:
	.cfi_endproc
LFE3085:
	.section	.gcc_except_table,"w"
LLSDA3085:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3085-LLSDACSB3085
LLSDACSB3085:
	.uleb128 LEHB7-LFB3085
	.uleb128 LEHE7-LEHB7
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB8-LFB3085
	.uleb128 LEHE8-LEHB8
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB9-LFB3085
	.uleb128 LEHE9-LEHB9
	.uleb128 0
	.uleb128 0
LLSDACSE3085:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E10_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E10_E9_M_invokeERKSt9_Any_dataS1_:
LFB3103:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3103
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_queue+256, (%esp)
LEHB10:
	call	_pthread_mutex_lock
LEHE10:
	testl	%eax, %eax
	jne	L206
	movl	__ZL7s_queue+240, %ecx
	cmpl	$19, %ecx
	jbe	L212
	movl	__ZL7s_queue+244, %ecx
	cmpl	$-1, %ecx
	je	L205
	leal	(%ecx,%ecx,2), %eax
	sall	$2, %eax
	movl	__ZL7s_queue(%eax), %edx
	leal	__ZL7s_queue(%eax), %ebx
	movl	%edx, __ZL7s_queue+244
	movl	$1, %edx
	movl	$-16843010, __ZL7s_queue(%eax)
	sall	%cl, %edx
	addl	$1, __ZL7s_queue+252
	orl	%edx, __ZL7s_queue+248
L204:
	movl	$__ZL7s_queue+256, (%esp)
	call	_pthread_mutex_unlock
	movl	36(%esp), %eax
	movl	$0, 8(%ebx)
	movl	$0, 4(%ebx)
	movl	$0, (%ebx)
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	$__ZL7s_queue+268, (%esp)
	movl	%edx, 8(%ebx)
	movl	%eax, 4(%ebx)
LEHB11:
	call	_pthread_mutex_lock
LEHE11:
	testl	%eax, %eax
	jne	L206
	movl	__ZL7s_queue+264, %eax
	movl	%ebx, (%eax)
	movl	$__ZL7s_queue+268, (%esp)
	movl	%ebx, __ZL7s_queue+264
	call	_pthread_mutex_unlock
	movl	$1, %eax
L209:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L212:
	.cfi_restore_state
	leal	1(%ecx), %eax
	leal	(%ecx,%ecx,2), %edx
	movl	%eax, __ZL7s_queue+240
	sall	$2, %edx
	movl	$1, %eax
	movl	$-16843010, __ZL7s_queue(%edx)
	sall	%cl, %eax
	addl	$1, __ZL7s_queue+252
	orl	%eax, __ZL7s_queue+248
	leal	__ZL7s_queue(%edx), %ebx
	jmp	L204
	.p2align 4,,7
L205:
	movl	$__ZL7s_queue+256, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L209
L206:
	movl	%eax, (%esp)
LEHB12:
	call	__ZSt20__throw_system_errori
LEHE12:
	.cfi_endproc
LFE3103:
	.section	.gcc_except_table,"w"
LLSDA3103:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3103-LLSDACSB3103
LLSDACSB3103:
	.uleb128 LEHB10-LFB3103
	.uleb128 LEHE10-LEHB10
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB11-LFB3103
	.uleb128 LEHE11-LEHB11
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB12-LFB3103
	.uleb128 LEHE12-LEHB12
	.uleb128 0
	.uleb128 0
LLSDACSE3103:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E11_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E11_E9_M_invokeERKSt9_Any_dataS1_:
LFB3107:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3107
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
	movl	$__ZL7s_queue+268, (%esp)
LEHB13:
	call	_pthread_mutex_lock
LEHE13:
	testl	%eax, %eax
	jne	L226
	movl	__ZL7s_queue+260, %esi
	cmpl	__ZL7s_queue+264, %esi
	je	L221
	movl	(%esi), %ebx
	movl	$__ZL7s_queue+256, (%esp)
LEHB14:
	call	_pthread_mutex_lock
LEHE14:
	testl	%eax, %eax
	jne	L227
	subl	$__ZL7s_queue, %esi
	movl	$-1431655765, %ecx
	movl	%esi, %eax
	mull	%ecx
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L228
	movl	__ZL7s_queue+248, %esi
	movl	$1, %eax
	movl	%edx, %ecx
	sall	%cl, %eax
	testl	%esi, %eax
	je	L229
	movl	__ZL7s_queue+244, %edi
	notl	%eax
	leal	(%edx,%edx,2), %ecx
	andl	%esi, %eax
	movl	$__ZL7s_queue+256, (%esp)
	movl	%edi, __ZL7s_queue(,%ecx,4)
	movl	%edx, __ZL7s_queue+244
	movl	%eax, __ZL7s_queue+248
	subl	$1, __ZL7s_queue+252
	call	_pthread_mutex_unlock
	movl	4(%ebx), %eax
	movl	8(%ebx), %edx
	movl	36(%esp), %ecx
	movl	%ebx, __ZL7s_queue+260
	movl	$1, %ebx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
L215:
	movl	$__ZL7s_queue+268, (%esp)
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
L221:
	.cfi_restore_state
	xorl	%ebx, %ebx
	jmp	L215
L227:
	movl	%eax, (%esp)
LEHB15:
	call	__ZSt20__throw_system_errori
LEHE15:
L222:
	movl	%eax, %ebx
L220:
	movl	$__ZL7s_queue+268, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, (%esp)
LEHB16:
	call	__Unwind_Resume
L226:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE16:
L229:
	movl	$LC3, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$230, 4(%esp)
	movl	$LC2, (%esp)
LEHB17:
	call	___assert_func
LEHE17:
L223:
	movl	$__ZL7s_queue+256, (%esp)
	movl	%eax, %ebx
	call	_pthread_mutex_unlock
	jmp	L220
L228:
	movl	$LC1, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$224, 4(%esp)
	movl	$LC2, (%esp)
LEHB18:
	call	___assert_func
LEHE18:
	.cfi_endproc
LFE3107:
	.section	.gcc_except_table,"w"
LLSDA3107:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3107-LLSDACSB3107
LLSDACSB3107:
	.uleb128 LEHB13-LFB3107
	.uleb128 LEHE13-LEHB13
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB14-LFB3107
	.uleb128 LEHE14-LEHB14
	.uleb128 L222-LFB3107
	.uleb128 0
	.uleb128 LEHB15-LFB3107
	.uleb128 LEHE15-LEHB15
	.uleb128 L222-LFB3107
	.uleb128 0
	.uleb128 LEHB16-LFB3107
	.uleb128 LEHE16-LEHB16
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB17-LFB3107
	.uleb128 LEHE17-LEHB17
	.uleb128 L223-LFB3107
	.uleb128 0
	.uleb128 LEHB18-LFB3107
	.uleb128 LEHE18-LEHB18
	.uleb128 L223-LFB3107
	.uleb128 0
LLSDACSE3107:
	.text
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E7_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E7_E9_M_invokeERKSt9_Any_dataS1_:
LFB3090:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3090
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_stack+264, (%esp)
LEHB19:
	call	_pthread_mutex_lock
LEHE19:
	testl	%eax, %eax
	jne	L243
	movl	__ZL7s_stack+260, %ebx
	testl	%ebx, %ebx
	je	L238
	movl	(%ebx), %eax
	movl	4(%ebx), %edx
	movl	8(%ebx), %ecx
	movl	%eax, __ZL7s_stack+260
	movl	36(%esp), %eax
	movl	%edx, (%eax)
	movl	%ecx, 4(%eax)
	movl	$__ZL7s_stack+256, (%esp)
LEHB20:
	call	_pthread_mutex_lock
LEHE20:
	testl	%eax, %eax
	jne	L244
	subl	$__ZL7s_stack, %ebx
	movl	$-1431655765, %ecx
	movl	%ebx, %eax
	mull	%ecx
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L245
	movl	__ZL7s_stack+248, %ebx
	movl	$1, %eax
	movl	%edx, %ecx
	sall	%cl, %eax
	testl	%ebx, %eax
	je	L246
	movl	__ZL7s_stack+244, %esi
	notl	%eax
	andl	%ebx, %eax
	movl	$1, %ebx
	leal	(%edx,%edx,2), %ecx
	movl	$__ZL7s_stack+256, (%esp)
	movl	%esi, __ZL7s_stack(,%ecx,4)
	movl	%edx, __ZL7s_stack+244
	movl	%eax, __ZL7s_stack+248
	subl	$1, __ZL7s_stack+252
	call	_pthread_mutex_unlock
L232:
	movl	$__ZL7s_stack+264, (%esp)
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
L238:
	.cfi_restore_state
	xorl	%ebx, %ebx
	jmp	L232
L244:
	movl	%eax, (%esp)
LEHB21:
	call	__ZSt20__throw_system_errori
LEHE21:
L239:
	movl	%eax, %ebx
L237:
	movl	$__ZL7s_stack+264, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, (%esp)
LEHB22:
	call	__Unwind_Resume
L243:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE22:
L246:
	movl	$LC3, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$230, 4(%esp)
	movl	$LC2, (%esp)
LEHB23:
	call	___assert_func
LEHE23:
L240:
	movl	$__ZL7s_stack+256, (%esp)
	movl	%eax, %ebx
	call	_pthread_mutex_unlock
	jmp	L237
L245:
	movl	$LC1, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$224, 4(%esp)
	movl	$LC2, (%esp)
LEHB24:
	call	___assert_func
LEHE24:
	.cfi_endproc
LFE3090:
	.section	.gcc_except_table,"w"
LLSDA3090:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3090-LLSDACSB3090
LLSDACSB3090:
	.uleb128 LEHB19-LFB3090
	.uleb128 LEHE19-LEHB19
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB20-LFB3090
	.uleb128 LEHE20-LEHB20
	.uleb128 L239-LFB3090
	.uleb128 0
	.uleb128 LEHB21-LFB3090
	.uleb128 LEHE21-LEHB21
	.uleb128 L239-LFB3090
	.uleb128 0
	.uleb128 LEHB22-LFB3090
	.uleb128 LEHE22-LEHB22
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB23-LFB3090
	.uleb128 LEHE23-LEHB23
	.uleb128 L240-LFB3090
	.uleb128 0
	.uleb128 LEHB24-LFB3090
	.uleb128 LEHE24-LEHB24
	.uleb128 L240-LFB3090
	.uleb128 0
LLSDACSE3090:
	.text
	.p2align 4,,15
	.def	__Z41__static_initialization_and_destruction_0ii.part.221;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii.part.221:
LFB3914:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3914
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
L258:
	movl	$0, 48(%esp)
	movl	$0, 52(%esp)
	movl	$0, 64(%esp)
	movl	$0, 68(%esp)
	.p2align 4,,7
L250:
	fildq	__ZL9s_lfQueue+512
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	fildq	__ZL9s_lfQueue+520
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	48(%esp), %esi
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	fildq	(%esi)
	fistpq	24(%esp)
	movl	24(%esp), %ecx
	movl	28(%esp), %ebx
	fildq	__ZL9s_lfQueue+512
	fistpq	24(%esp)
	movl	52(%esp), %edi
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	xorl	%esi, %eax
	xorl	%edi, %edx
	orl	%eax, %edx
	jne	L250
	movl	64(%esp), %eax
	xorl	68(%esp), %edi
	xorl	%esi, %eax
	orl	%eax, %edi
	jne	L251
	movl	%ebx, %eax
	movl	%ebx, %ebp
	orl	%ecx, %eax
	je	L252
	movl	64(%esp), %eax
	movl	%ecx, %ebx
	movl	%ebp, %ecx
	movl	68(%esp), %edx
	lock cmpxchg8b	__ZL9s_lfQueue+520
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	jmp	L250
	.p2align 4,,7
L251:
	movl	48(%esp), %eax
	movl	%ebx, %ebp
	movl	%ecx, %ebx
	movl	52(%esp), %edx
	movl	%ebp, %ecx
	lock cmpxchg8b	__ZL9s_lfQueue+512
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	jne	L250
	subl	$__ZL9s_lfQueue, %esi
	shrl	$4, %esi
	cmpl	$19, %esi
	ja	L293
	movzbl	__ZL9s_lfQueue+328(%esi), %eax
	leal	__ZL9s_lfQueue+328(%esi), %ecx
	testb	%al, %al
	je	L259
	movl	__ZL9s_lfQueue+324, %eax
	movl	%esi, %edx
	sall	$4, %edx
	addl	$__ZL9s_lfQueue, %edx
	movl	%eax, 32(%esp)
	.p2align 4,,7
L257:
	movl	%eax, (%edx)
	movl	32(%esp), %eax
	lock cmpxchgl	%esi, __ZL9s_lfQueue+324
	movl	%eax, 32(%esp)
	jne	L257
	lock subb	$1, (%ecx)
	lock subl	$1, __ZL9s_lfQueue+348
	leal	432(,%esi,4), %eax
	lock addl	$1, __ZL9s_lfQueue(%eax)
	jmp	L258
L252:
	movq	__ZL9s_lfQueue+512, %xmm0
	movq	%xmm0, 24(%esp)
	movl	24(%esp), %eax
	movl	%eax, %ecx
	subl	$__ZL9s_lfQueue, %ecx
	shrl	$4, %ecx
	cmpl	$19, %ecx
	ja	L293
	movzbl	__ZL9s_lfQueue+328(%ecx), %eax
	leal	__ZL9s_lfQueue+328(%ecx), %esi
	testb	%al, %al
	je	L259
	movl	__ZL9s_lfQueue+324, %edx
	movl	%ecx, %ebx
	sall	$4, %ebx
	addl	$__ZL9s_lfQueue, %ebx
	movl	%edx, 64(%esp)
	jmp	L261
	.p2align 4,,7
L315:
	movl	%eax, %edx
L261:
	movl	%edx, (%ebx)
	movl	64(%esp), %eax
	lock cmpxchgl	%ecx, __ZL9s_lfQueue+324
	movl	%eax, 64(%esp)
	jne	L315
	lock subb	$1, (%esi)
	lock subl	$1, __ZL9s_lfQueue+348
	leal	432(,%ecx,4), %eax
	lock addl	$1, __ZL9s_lfQueue(%eax)
	movl	$1, %edi
	jmp	L267
	.p2align 4,,7
L319:
	movl	0(%ebp), %ebx
	movl	$__ZL7s_queue+256, (%esp)
LEHB25:
	call	_pthread_mutex_lock
LEHE25:
	testl	%eax, %eax
	jne	L316
	subl	$__ZL7s_queue, %ebp
	movl	$-1431655765, %ecx
	movl	%ebp, %eax
	mull	%ecx
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L317
	movl	__ZL7s_queue+248, %eax
	movl	%edx, %ecx
	movl	%edi, %ebp
	sall	%cl, %ebp
	movl	%ebp, %ecx
	testl	%eax, %ebp
	je	L318
	movl	__ZL7s_queue+244, %esi
	notl	%ecx
	leal	(%edx,%edx,2), %ebp
	andl	%eax, %ecx
	movl	$__ZL7s_queue+256, (%esp)
	movl	%esi, __ZL7s_queue(,%ebp,4)
	movl	%edx, __ZL7s_queue+244
	movl	%ecx, __ZL7s_queue+248
	subl	$1, __ZL7s_queue+252
	call	_pthread_mutex_unlock
	movl	$__ZL7s_queue+268, (%esp)
	movl	%ebx, __ZL7s_queue+260
	call	_pthread_mutex_unlock
L267:
	movl	$__ZL7s_queue+268, (%esp)
	call	_pthread_mutex_lock
	testl	%eax, %eax
	jne	L295
	movl	__ZL7s_queue+260, %ebp
	cmpl	__ZL7s_queue+264, %ebp
	jne	L319
	movl	$__ZL7s_queue+268, (%esp)
	call	_pthread_mutex_unlock
	movl	__ZL7s_queue+260, %ebx
	movl	$__ZL7s_queue+256, (%esp)
	call	_pthread_mutex_lock
	testl	%eax, %eax
	jne	L295
	subl	$__ZL7s_queue, %ebx
	movl	$-1431655765, %edx
	movl	%ebx, %eax
	mull	%edx
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L320
	movl	__ZL7s_queue+248, %ebx
	movl	$1, %eax
	movl	%edx, %ecx
	sall	%cl, %eax
	testl	%ebx, %eax
	je	L321
	movl	__ZL7s_queue+244, %esi
	notl	%eax
	leal	(%edx,%edx,2), %ecx
	andl	%ebx, %eax
	movl	$__ZL7s_queue+256, (%esp)
	movl	%esi, __ZL7s_queue(,%ecx,4)
	movl	%edx, __ZL7s_queue+244
	movl	%eax, __ZL7s_queue+248
	subl	$1, __ZL7s_queue+252
	call	_pthread_mutex_unlock
	.p2align 4,,7
L272:
	fildq	__ZL9s_lfStack+512
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
L313:
	movl	%eax, %esi
	movl	%edx, %eax
	orl	%esi, %eax
	je	L322
L283:
	fildq	(%esi)
	fistpq	24(%esp)
	movl	24(%esp), %edi
	movl	28(%esp), %ebp
	fildq	__ZL9s_lfStack+512
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	xorl	68(%esp), %edx
	xorl	64(%esp), %eax
	orl	%eax, %edx
	je	L323
	fildq	__ZL9s_lfStack+512
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, %esi
	movl	%eax, 64(%esp)
	movl	%edx, %eax
	orl	%esi, %eax
	movl	%edx, 68(%esp)
	jne	L283
L322:
	movl	$-1431655765, %esi
	movl	$1, %ebx
	jmp	L290
	.p2align 4,,7
L328:
	movl	(%edi), %eax
	movl	$__ZL7s_stack+256, (%esp)
	movl	%eax, __ZL7s_stack+260
LEHB26:
	call	_pthread_mutex_lock
LEHE26:
	testl	%eax, %eax
	jne	L324
	subl	$__ZL7s_stack, %edi
	movl	%edi, %eax
	mull	%esi
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L325
	movl	__ZL7s_stack+248, %edi
	movl	%ebx, %eax
	movl	%edx, %ecx
	sall	%cl, %eax
	testl	%edi, %eax
	je	L326
	movl	__ZL7s_stack+244, %ebp
	notl	%eax
	leal	(%edx,%edx,2), %ecx
	andl	%edi, %eax
	movl	$__ZL7s_stack+256, (%esp)
	movl	%ebp, __ZL7s_stack(,%ecx,4)
	movl	%edx, __ZL7s_stack+244
	movl	%eax, __ZL7s_stack+248
	subl	$1, __ZL7s_stack+252
	call	_pthread_mutex_unlock
	movl	$__ZL7s_stack+264, (%esp)
	call	_pthread_mutex_unlock
L290:
	movl	$__ZL7s_stack+264, (%esp)
	call	_pthread_mutex_lock
	testl	%eax, %eax
	jne	L327
	movl	__ZL7s_stack+260, %edi
	testl	%edi, %edi
	jne	L328
	movl	$__ZL7s_stack+264, (%esp)
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
	.p2align 4,,7
L323:
	.cfi_restore_state
	movl	64(%esp), %eax
	movl	%edi, %ebx
	movl	%ebp, %ecx
	movl	68(%esp), %edx
	lock cmpxchg8b	__ZL9s_lfStack+512
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	jne	L313
	subl	$__ZL9s_lfStack, %esi
	shrl	$4, %esi
	cmpl	$19, %esi
	ja	L329
	movzbl	__ZL9s_lfStack+328(%esi), %eax
	leal	__ZL9s_lfStack+328(%esi), %ecx
	testb	%al, %al
	je	L330
	movl	__ZL9s_lfStack+324, %eax
	movl	%esi, %edx
	sall	$4, %edx
	addl	$__ZL9s_lfStack, %edx
	movl	%eax, 48(%esp)
	.p2align 4,,7
L282:
	movl	%eax, (%edx)
	movl	48(%esp), %eax
	lock cmpxchgl	%esi, __ZL9s_lfStack+324
	movl	%eax, 48(%esp)
	jne	L282
	lock subb	$1, (%ecx)
	lock subl	$1, __ZL9s_lfStack+348
	leal	432(,%esi,4), %eax
	lock addl	$1, __ZL9s_lfStack(%eax)
	jmp	L272
L295:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
L297:
L269:
	movl	$__ZL7s_queue+268, (%esp)
	call	_pthread_mutex_unlock
L314:
	call	__ZSt9terminatev
L316:
	movl	%eax, (%esp)
LEHB27:
	call	__ZSt20__throw_system_errori
LEHE27:
L317:
	movl	$LC1, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$224, 4(%esp)
	movl	$LC2, (%esp)
LEHB28:
	call	___assert_func
L318:
	movl	$LC3, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$230, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
LEHE28:
L321:
	movl	$LC3, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$230, 4(%esp)
	movl	$LC2, (%esp)
LEHB29:
	call	___assert_func
LEHE29:
L329:
	movl	$LC1, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$460, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
L299:
	movl	$__ZL7s_queue+256, (%esp)
	call	_pthread_mutex_unlock
	jmp	L314
L320:
	movl	$LC1, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$224, 4(%esp)
	movl	$LC2, (%esp)
LEHB30:
	call	___assert_func
LEHE30:
L298:
	movl	$__ZL7s_queue+256, (%esp)
	call	_pthread_mutex_unlock
	jmp	L269
L330:
	movl	$LC3, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$466, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
L327:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
L300:
L292:
	movl	$__ZL7s_stack+264, (%esp)
	call	_pthread_mutex_unlock
	jmp	L314
L324:
	movl	%eax, (%esp)
LEHB31:
	call	__ZSt20__throw_system_errori
LEHE31:
L325:
	movl	$LC1, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$224, 4(%esp)
	movl	$LC2, (%esp)
LEHB32:
	call	___assert_func
L326:
	movl	$LC3, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$230, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
LEHE32:
L301:
	movl	$__ZL7s_stack+256, (%esp)
	call	_pthread_mutex_unlock
	jmp	L292
L259:
	movl	$LC3, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$466, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
L293:
	movl	$LC1, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$460, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
	.cfi_endproc
LFE3914:
	.section	.gcc_except_table,"w"
LLSDA3914:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3914-LLSDACSB3914
LLSDACSB3914:
	.uleb128 LEHB25-LFB3914
	.uleb128 LEHE25-LEHB25
	.uleb128 L297-LFB3914
	.uleb128 0
	.uleb128 LEHB26-LFB3914
	.uleb128 LEHE26-LEHB26
	.uleb128 L300-LFB3914
	.uleb128 0
	.uleb128 LEHB27-LFB3914
	.uleb128 LEHE27-LEHB27
	.uleb128 L297-LFB3914
	.uleb128 0
	.uleb128 LEHB28-LFB3914
	.uleb128 LEHE28-LEHB28
	.uleb128 L298-LFB3914
	.uleb128 0
	.uleb128 LEHB29-LFB3914
	.uleb128 LEHE29-LEHB29
	.uleb128 L299-LFB3914
	.uleb128 0
	.uleb128 LEHB30-LFB3914
	.uleb128 LEHE30-LEHB30
	.uleb128 L299-LFB3914
	.uleb128 0
	.uleb128 LEHB31-LFB3914
	.uleb128 LEHE31-LEHB31
	.uleb128 L300-LFB3914
	.uleb128 0
	.uleb128 LEHB32-LFB3914
	.uleb128 LEHE32-LEHB32
	.uleb128 L301-LFB3914
	.uleb128 0
LLSDACSE3914:
	.text
	.section	.text$_ZNSt6thread10_Impl_baseD1Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt6thread10_Impl_baseD1Ev
	.def	__ZNSt6thread10_Impl_baseD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6thread10_Impl_baseD1Ev:
LFB2087:
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
	je	L331
	lock subl	$1, 4(%ebx)
	je	L336
L331:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L336:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L331
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
LFE2087:
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED2Ev;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED2Ev:
LFB3591:
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
	je	L337
	lock subl	$1, 4(%ebx)
	je	L342
L337:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L342:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L337
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
LFE3591:
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED1Ev;	.scl	3;	.type	32;	.endef
	.set	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED1Ev,__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED2Ev
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED2Ev;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED2Ev:
LFB3583:
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
	je	L343
	lock subl	$1, 4(%ebx)
	je	L348
L343:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L348:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L343
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
LFE3583:
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED1Ev;	.scl	3;	.type	32;	.endef
	.set	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED1Ev,__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED2Ev
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED2Ev;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED2Ev:
LFB3587:
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
	je	L349
	lock subl	$1, 4(%ebx)
	je	L354
L349:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L354:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L349
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
LFE3587:
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED1Ev;	.scl	3;	.type	32;	.endef
	.set	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED1Ev,__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED2Ev
	.section	.text$_ZNSt6thread10_Impl_baseD0Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt6thread10_Impl_baseD0Ev
	.def	__ZNSt6thread10_Impl_baseD0Ev;	.scl	2;	.type	32;	.endef
__ZNSt6thread10_Impl_baseD0Ev:
LFB2088:
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
	je	L357
	lock subl	$1, 4(%ebx)
	je	L360
L357:
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
L360:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L357
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*12(%eax)
	.p2align 4,,3
	jmp	L357
	.cfi_endproc
LFE2088:
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED0Ev;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEED0Ev:
LFB3593:
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
	je	L363
	lock subl	$1, 4(%ebx)
	je	L366
L363:
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
L366:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L363
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*12(%eax)
	.p2align 4,,3
	jmp	L363
	.cfi_endproc
LFE3593:
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED0Ev;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEED0Ev:
LFB3589:
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
	je	L369
	lock subl	$1, 4(%ebx)
	je	L372
L369:
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
L372:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L369
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*12(%eax)
	.p2align 4,,3
	jmp	L369
	.cfi_endproc
LFE3589:
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED0Ev;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEED0Ev:
LFB3585:
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
	je	L375
	lock subl	$1, 4(%ebx)
	je	L378
L375:
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
L378:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L375
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*12(%eax)
	.p2align 4,,3
	jmp	L375
	.cfi_endproc
LFE3585:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFP6data_tvEZ11thread_testvEUlvE4_E9_M_invokeERKSt9_Any_data;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFP6data_tvEZ11thread_testvEUlvE4_E9_M_invokeERKSt9_Any_data:
LFB3077:
	.cfi_startproc
	movl	$1, %edx
	lock xaddl	%edx, __ZL17s_lfPoolAllocator+160
	cmpl	$19, %edx
	jbe	L392
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	movl	$1, %edx
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$20, __ZL17s_lfPoolAllocator+160
	mfence
	movl	__ZL17s_lfPoolAllocator+164, %eax
	movl	%eax, 16(%esp)
L382:
	cmpl	$-1, %eax
	je	L385
L393:
	addl	$160, %eax
	movl	$1, %ecx
	lock xaddb	%cl, __ZL17s_lfPoolAllocator+8(%eax)
	testb	%cl, %cl
	je	L386
	movl	16(%esp), %eax
	addl	$160, %eax
	lock subb	$1, __ZL17s_lfPoolAllocator+8(%eax)
	movl	__ZL17s_lfPoolAllocator+164, %eax
	addl	$1, %edx
	cmpl	$1000, %edx
	movl	%eax, 16(%esp)
	je	L383
L395:
	movl	16(%esp), %eax
	cmpl	$-1, %eax
	jne	L393
L385:
	addl	$36, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L386:
	.cfi_restore_state
	movl	16(%esp), %ecx
	movl	__ZL17s_lfPoolAllocator(,%ecx,8), %esi
	leal	__ZL17s_lfPoolAllocator(,%ecx,8), %ebx
	movl	%ecx, %eax
	lock cmpxchgl	%esi, __ZL17s_lfPoolAllocator+164
	movl	%eax, 16(%esp)
	je	L394
	addl	$160, %ecx
	lock subb	$1, __ZL17s_lfPoolAllocator+8(%ecx)
	addl	$1, %edx
	cmpl	$1000, %edx
	jne	L395
L383:
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	__ZL17s_lfPoolAllocator+164, %eax
	xorl	%edx, %edx
	movl	%eax, 16(%esp)
	jmp	L382
	.p2align 4,,7
L392:
	.cfi_def_cfa_offset 4
	.cfi_restore 3
	.cfi_restore 6
	leal	160(%edx), %eax
	lock addb	$1, __ZL17s_lfPoolAllocator+8(%eax)
	leal	__ZL17s_lfPoolAllocator(,%edx,8), %eax
	movl	$-16843010, __ZL17s_lfPoolAllocator(,%edx,8)
	lock addl	$1, __ZL17s_lfPoolAllocator+188
	leal	192(,%edx,4), %edx
	lock addl	$1, __ZL17s_lfPoolAllocator(%edx)
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	ret
	.p2align 4,,7
L394:
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -12
	.cfi_offset 6, -8
	movl	$-16843010, __ZL17s_lfPoolAllocator(,%eax,8)
	lock addl	$1, __ZL17s_lfPoolAllocator+188
	movl	16(%esp), %eax
	leal	192(,%eax,4), %eax
	lock addl	$1, __ZL17s_lfPoolAllocator(%eax)
	movl	$0, (%ebx)
	movl	%ebx, %eax
	movl	$0, 4(%ebx)
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
LFE3077:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E9_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E9_E9_M_invokeERKSt9_Any_dataS1_:
LFB3099:
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
	fildq	__ZL9s_lfStack+512
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
L409:
	movl	%eax, %esi
	movl	%edx, %eax
	orl	%esi, %eax
	je	L410
L406:
	fildq	(%esi)
	fistpq	24(%esp)
	movl	24(%esp), %edi
	movl	28(%esp), %ebp
	fildq	__ZL9s_lfStack+512
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	xorl	52(%esp), %edx
	xorl	48(%esp), %eax
	orl	%eax, %edx
	je	L411
	fildq	__ZL9s_lfStack+512
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, %esi
	movl	%eax, 48(%esp)
	movl	%edx, %eax
	orl	%esi, %eax
	movl	%edx, 52(%esp)
	jne	L406
L410:
	addl	$76, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	xorl	%edx, %edx
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	movl	%edx, %eax
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
L411:
	.cfi_restore_state
	movl	52(%esp), %edx
	movl	%edi, %ebx
	movl	%ebp, %ecx
	movl	48(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfStack+512
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	jne	L409
	movl	8(%esi), %eax
	movl	12(%esi), %edx
	subl	$__ZL9s_lfStack, %esi
	movl	100(%esp), %ecx
	shrl	$4, %esi
	cmpl	$19, %esi
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	ja	L412
	movzbl	__ZL9s_lfStack+328(%esi), %eax
	leal	__ZL9s_lfStack+328(%esi), %ebx
	testb	%al, %al
	je	L413
	movl	__ZL9s_lfStack+324, %eax
	movl	%esi, %ecx
	sall	$4, %ecx
	addl	$__ZL9s_lfStack, %ecx
	movl	%eax, 32(%esp)
	.p2align 4,,7
L404:
	movl	%eax, (%ecx)
	movl	32(%esp), %eax
	lock cmpxchgl	%esi, __ZL9s_lfStack+324
	sete	%dl
	testb	%dl, %dl
	movl	%eax, 32(%esp)
	je	L404
	lock subb	$1, (%ebx)
	lock subl	$1, __ZL9s_lfStack+348
	leal	432(,%esi,4), %eax
	lock addl	$1, __ZL9s_lfStack(%eax)
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
L412:
	.cfi_restore_state
	movl	$LC1, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$460, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
L413:
	movl	$LC3, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$466, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
	.cfi_endproc
LFE3099:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E12_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E12_E9_M_invokeERKSt9_Any_dataS1_:
LFB3111:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$1, %eax
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
	lock xaddl	%eax, __ZL9s_lfQueue+320
	cmpl	$19, %eax
	jbe	L435
	movl	$20, __ZL9s_lfQueue+320
	movl	$1, %edx
	mfence
	movl	__ZL9s_lfQueue+324, %eax
	movl	%eax, 48(%esp)
L417:
	cmpl	$-1, %eax
	je	L420
L436:
	addl	$320, %eax
	movl	$1, %ecx
	lock xaddb	%cl, __ZL9s_lfQueue+8(%eax)
	testb	%cl, %cl
	je	L421
	movl	48(%esp), %eax
	addl	$320, %eax
	lock subb	$1, __ZL9s_lfQueue+8(%eax)
	movl	__ZL9s_lfQueue+324, %eax
	addl	$1, %edx
	cmpl	$1000, %edx
	movl	%eax, 48(%esp)
	je	L418
L438:
	movl	48(%esp), %eax
	cmpl	$-1, %eax
	jne	L436
L420:
	addl	$76, %esp
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
L421:
	.cfi_restore_state
	movl	48(%esp), %ebx
	leal	48(%esp), %esi
	movl	%ebx, %ecx
	movl	%ebx, %eax
	sall	$4, %ecx
	leal	__ZL9s_lfQueue(%ecx), %edi
	movl	__ZL9s_lfQueue(%ecx), %ecx
	lock cmpxchgl	%ecx, __ZL9s_lfQueue+324
	movl	%eax, 48(%esp)
	je	L437
	addl	$320, %ebx
	lock subb	$1, __ZL9s_lfQueue+8(%ebx)
	addl	$1, %edx
	cmpl	$1000, %edx
	jne	L438
L418:
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	__ZL9s_lfQueue+324, %eax
	xorl	%edx, %edx
	movl	%eax, 48(%esp)
	jmp	L417
	.p2align 4,,7
L435:
	leal	320(%eax), %edx
	lock addb	$1, __ZL9s_lfQueue+8(%edx)
	movl	%eax, %edx
	sall	$4, %edx
	leal	__ZL9s_lfQueue(%edx), %edi
	movl	$-16843010, __ZL9s_lfQueue(%edx)
	lock addl	$1, __ZL9s_lfQueue+348
	leal	352(,%eax,4), %eax
	lock addl	$1, __ZL9s_lfQueue(%eax)
	leal	48(%esp), %esi
L416:
	movl	$0, (%edi)
	movl	$1, %ecx
	movl	$0, 4(%edi)
	movl	$0, 8(%edi)
	movl	$0, 12(%edi)
	lock xaddl	%ecx, __ZL9s_lfQueue+528
	movl	%edi, %eax
	cltd
	xorl	%eax, %eax
	orl	%edx, %ecx
	xorl	%edx, %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	movl	%ecx, 20(%esp)
	fistpq	(%edi)
	mfence
	movl	100(%esp), %eax
	movl	$0, 32(%esp)
	movl	$0, 36(%esp)
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%edx, 12(%edi)
	movl	%eax, 8(%edi)
L429:
	fildq	__ZL9s_lfQueue+520
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	movl	%eax, 16(%esp)
	fildq	(%eax)
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	fildq	__ZL9s_lfQueue+520
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	xorl	36(%esp), %edx
	xorl	32(%esp), %eax
	orl	%eax, %edx
	jne	L429
	movl	52(%esp), %ecx
	movl	48(%esp), %ebp
	movl	%ecx, %eax
	orl	%ebp, %eax
	jne	L426
	movl	(%esi), %eax
	movl	%edi, %ebx
	movl	4(%esi), %edx
	movl	20(%esp), %ecx
	movl	16(%esp), %ebp
	lock cmpxchg8b	0(%ebp)
	sete	%bl
	testb	%bl, %bl
	movl	%ebx, %ebp
	movl	%eax, (%esi)
	movl	%edx, 4(%esi)
	je	L429
	movl	36(%esp), %edx
	movl	%edi, %ebx
	movl	32(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfQueue+520
	addl	$76, %esp
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
L426:
	.cfi_restore_state
	movl	36(%esp), %edx
	movl	%ebp, %ebx
	movl	32(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfQueue+520
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	jmp	L429
	.p2align 4,,7
L437:
	sall	$4, %eax
	movl	$-16843010, __ZL9s_lfQueue(%eax)
	lock addl	$1, __ZL9s_lfQueue+348
	movl	48(%esp), %eax
	leal	352(,%eax,4), %eax
	lock addl	$1, __ZL9s_lfQueue(%eax)
	jmp	L416
	.cfi_endproc
LFE3111:
	.p2align 4,,15
	.def	__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E13_E9_M_invokeERKSt9_Any_dataS1_;	.scl	3;	.type	32;	.endef
__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E13_E9_M_invokeERKSt9_Any_dataS1_:
LFB3115:
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
	.p2align 4,,7
L442:
	fildq	__ZL9s_lfQueue+512
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	fildq	__ZL9s_lfQueue+520
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 64(%esp)
	movl	48(%esp), %eax
	movl	%edx, 68(%esp)
	movl	%eax, 20(%esp)
	movl	%eax, %ecx
	fildq	(%eax)
	fistpq	24(%esp)
	movl	24(%esp), %esi
	movl	28(%esp), %edi
	fildq	__ZL9s_lfQueue+512
	fistpq	24(%esp)
	movl	52(%esp), %ebp
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	xorl	%ecx, %eax
	xorl	%ebp, %edx
	orl	%eax, %edx
	jne	L442
	movl	%ecx, %eax
	movl	%esi, %ebx
	xorl	68(%esp), %ebp
	movl	%edi, %ecx
	xorl	64(%esp), %eax
	orl	%eax, %ebp
	jne	L443
	movl	%esi, %eax
	orl	%edi, %eax
	je	L450
	movl	68(%esp), %edx
	movl	64(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfQueue+520
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	jmp	L442
	.p2align 4,,7
L443:
	movl	52(%esp), %edx
	movl	48(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfQueue+512
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	jne	L442
	movl	20(%esp), %ebx
	movl	8(%esi), %eax
	movl	12(%esi), %edx
	movl	116(%esp), %ecx
	subl	$__ZL9s_lfQueue, %ebx
	shrl	$4, %ebx
	cmpl	$19, %ebx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	ja	L455
	movzbl	__ZL9s_lfQueue+328(%ebx), %eax
	leal	__ZL9s_lfQueue+328(%ebx), %esi
	testb	%al, %al
	je	L456
	movl	__ZL9s_lfQueue+324, %eax
	movl	%ebx, %ecx
	sall	$4, %ecx
	addl	$__ZL9s_lfQueue, %ecx
	movl	%eax, 32(%esp)
	.p2align 4,,7
L449:
	movl	%eax, (%ecx)
	movl	32(%esp), %eax
	lock cmpxchgl	%ebx, __ZL9s_lfQueue+324
	sete	%dl
	testb	%dl, %dl
	movl	%eax, 32(%esp)
	je	L449
	lock subb	$1, (%esi)
	lock subl	$1, __ZL9s_lfQueue+348
	leal	432(,%ebx,4), %eax
	lock addl	$1, __ZL9s_lfQueue(%eax)
L444:
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
L450:
	.cfi_restore_state
	xorl	%edx, %edx
	jmp	L444
L456:
	movl	$LC3, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$466, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
L455:
	movl	$LC1, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$460, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
	.cfi_endproc
LFE3115:
	.p2align 4,,15
	.globl	__Z11allocNormalv
	.def	__Z11allocNormalv;	.scl	2;	.type	32;	.endef
__Z11allocNormalv:
LFB2491:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2491
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL15s_poolAllocator+176, (%esp)
LEHB33:
	call	_pthread_mutex_lock
LEHE33:
	testl	%eax, %eax
	jne	L465
	movl	__ZL15s_poolAllocator+160, %ecx
	cmpl	$19, %ecx
	jbe	L466
	movl	__ZL15s_poolAllocator+164, %ecx
	cmpl	$-1, %ecx
	je	L461
	movl	__ZL15s_poolAllocator(,%ecx,8), %eax
	leal	__ZL15s_poolAllocator(,%ecx,8), %ebx
	movl	%eax, __ZL15s_poolAllocator+164
	movl	$1, %eax
	movl	$-16843010, __ZL15s_poolAllocator(,%ecx,8)
	sall	%cl, %eax
	addl	$1, __ZL15s_poolAllocator+172
	orl	%eax, __ZL15s_poolAllocator+168
L460:
	movl	$__ZL15s_poolAllocator+176, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, %eax
	movl	$0, (%ebx)
	movl	$0, 4(%ebx)
L463:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L466:
	.cfi_restore_state
	leal	1(%ecx), %eax
	movl	%eax, __ZL15s_poolAllocator+160
	movl	$1, %eax
	movl	$-16843010, __ZL15s_poolAllocator(,%ecx,8)
	sall	%cl, %eax
	addl	$1, __ZL15s_poolAllocator+172
	orl	%eax, __ZL15s_poolAllocator+168
	leal	__ZL15s_poolAllocator(,%ecx,8), %ebx
	jmp	L460
	.p2align 4,,7
L461:
	movl	$__ZL15s_poolAllocator+176, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L463
L465:
	movl	%eax, (%esp)
LEHB34:
	call	__ZSt20__throw_system_errori
LEHE34:
	.cfi_endproc
LFE2491:
	.section	.gcc_except_table,"w"
LLSDA2491:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2491-LLSDACSB2491
LLSDACSB2491:
	.uleb128 LEHB33-LFB2491
	.uleb128 LEHE33-LEHB33
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB34-LFB2491
	.uleb128 LEHE34-LEHB34
	.uleb128 0
	.uleb128 0
LLSDACSE2491:
	.text
	.p2align 4,,15
	.globl	__Z10freeNormalP6data_t
	.def	__Z10freeNormalP6data_t;	.scl	2;	.type	32;	.endef
__Z10freeNormalP6data_t:
LFB2492:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2492
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL15s_poolAllocator+176, (%esp)
LEHB35:
	call	_pthread_mutex_lock
LEHE35:
	testl	%eax, %eax
	jne	L475
	movl	32(%esp), %ecx
	subl	$__ZL15s_poolAllocator, %ecx
	shrl	$3, %ecx
	cmpl	$19, %ecx
	ja	L476
	movl	__ZL15s_poolAllocator+168, %edx
	movl	$1, %eax
	sall	%cl, %eax
	testl	%edx, %eax
	je	L477
	movl	__ZL15s_poolAllocator+164, %ebx
	notl	%eax
	andl	%edx, %eax
	movl	$__ZL15s_poolAllocator+176, (%esp)
	movl	%ebx, __ZL15s_poolAllocator(,%ecx,8)
	movl	%ecx, __ZL15s_poolAllocator+164
	movl	%eax, __ZL15s_poolAllocator+168
	subl	$1, __ZL15s_poolAllocator+172
	call	_pthread_mutex_unlock
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	movl	$1, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L475:
	.cfi_restore_state
	movl	%eax, (%esp)
LEHB36:
	call	__ZSt20__throw_system_errori
LEHE36:
L477:
	movl	$LC3, 12(%esp)
	movl	$__ZZN14pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$230, 4(%esp)
	movl	$LC2, (%esp)
LEHB37:
	call	___assert_func
LEHE37:
L472:
	movl	%eax, %ebx
	movl	$__ZL15s_poolAllocator+176, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, (%esp)
LEHB38:
	call	__Unwind_Resume
LEHE38:
L476:
	movl	$LC1, 12(%esp)
	movl	$__ZZN14pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$224, 4(%esp)
	movl	$LC2, (%esp)
LEHB39:
	call	___assert_func
LEHE39:
	.cfi_endproc
LFE2492:
	.section	.gcc_except_table,"w"
LLSDA2492:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2492-LLSDACSB2492
LLSDACSB2492:
	.uleb128 LEHB35-LFB2492
	.uleb128 LEHE35-LEHB35
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB36-LFB2492
	.uleb128 LEHE36-LEHB36
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB37-LFB2492
	.uleb128 LEHE37-LEHB37
	.uleb128 L472-LFB2492
	.uleb128 0
	.uleb128 LEHB38-LFB2492
	.uleb128 LEHE38-LEHB38
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB39-LFB2492
	.uleb128 LEHE39-LEHB39
	.uleb128 L472-LFB2492
	.uleb128 0
LLSDACSE2492:
	.text
	.p2align 4,,15
	.globl	__Z13allocLockFreev
	.def	__Z13allocLockFreev;	.scl	2;	.type	32;	.endef
__Z13allocLockFreev:
LFB2493:
	.cfi_startproc
	movl	$1, %edx
	lock xaddl	%edx, __ZL17s_lfPoolAllocator+160
	cmpl	$19, %edx
	jbe	L491
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	movl	$1, %edx
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	$20, __ZL17s_lfPoolAllocator+160
	mfence
	movl	__ZL17s_lfPoolAllocator+164, %eax
	movl	%eax, 16(%esp)
L481:
	cmpl	$-1, %eax
	je	L484
L492:
	addl	$160, %eax
	movl	$1, %ecx
	lock xaddb	%cl, __ZL17s_lfPoolAllocator+8(%eax)
	testb	%cl, %cl
	je	L485
	movl	16(%esp), %eax
	addl	$160, %eax
	lock subb	$1, __ZL17s_lfPoolAllocator+8(%eax)
	movl	__ZL17s_lfPoolAllocator+164, %eax
	addl	$1, %edx
	cmpl	$1000, %edx
	movl	%eax, 16(%esp)
	je	L482
L494:
	movl	16(%esp), %eax
	cmpl	$-1, %eax
	jne	L492
L484:
	addl	$36, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L485:
	.cfi_restore_state
	movl	16(%esp), %ecx
	movl	__ZL17s_lfPoolAllocator(,%ecx,8), %esi
	leal	__ZL17s_lfPoolAllocator(,%ecx,8), %ebx
	movl	%ecx, %eax
	lock cmpxchgl	%esi, __ZL17s_lfPoolAllocator+164
	movl	%eax, 16(%esp)
	je	L493
	addl	$160, %ecx
	lock subb	$1, __ZL17s_lfPoolAllocator+8(%ecx)
	addl	$1, %edx
	cmpl	$1000, %edx
	jne	L494
L482:
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	__ZL17s_lfPoolAllocator+164, %eax
	xorl	%edx, %edx
	movl	%eax, 16(%esp)
	jmp	L481
	.p2align 4,,7
L491:
	.cfi_def_cfa_offset 4
	.cfi_restore 3
	.cfi_restore 6
	leal	160(%edx), %eax
	lock addb	$1, __ZL17s_lfPoolAllocator+8(%eax)
	leal	__ZL17s_lfPoolAllocator(,%edx,8), %eax
	movl	$-16843010, __ZL17s_lfPoolAllocator(,%edx,8)
	lock addl	$1, __ZL17s_lfPoolAllocator+188
	leal	192(,%edx,4), %edx
	lock addl	$1, __ZL17s_lfPoolAllocator(%edx)
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	ret
	.p2align 4,,7
L493:
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -12
	.cfi_offset 6, -8
	movl	$-16843010, __ZL17s_lfPoolAllocator(,%eax,8)
	lock addl	$1, __ZL17s_lfPoolAllocator+188
	movl	16(%esp), %eax
	leal	192(,%eax,4), %eax
	lock addl	$1, __ZL17s_lfPoolAllocator(%eax)
	movl	$0, (%ebx)
	movl	%ebx, %eax
	movl	$0, 4(%ebx)
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
LFE2493:
	.p2align 4,,15
	.globl	__Z12freeLockFreeP6data_t
	.def	__Z12freeLockFreeP6data_t;	.scl	2;	.type	32;	.endef
__Z12freeLockFreeP6data_t:
LFB2494:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$40, %esp
	.cfi_def_cfa_offset 48
	movl	48(%esp), %edx
	subl	$__ZL17s_lfPoolAllocator, %edx
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L501
	movzbl	__ZL17s_lfPoolAllocator+168(%edx), %eax
	leal	__ZL17s_lfPoolAllocator+168(%edx), %ebx
	testb	%al, %al
	je	L502
	movl	__ZL17s_lfPoolAllocator+164, %eax
	leal	__ZL17s_lfPoolAllocator(,%edx,8), %ecx
	movl	%eax, 16(%esp)
	.p2align 4,,7
L499:
	movl	%eax, (%ecx)
	movl	16(%esp), %eax
	lock cmpxchgl	%edx, __ZL17s_lfPoolAllocator+164
	movl	%eax, 16(%esp)
	jne	L499
	lock subb	$1, (%ebx)
	lock subl	$1, __ZL17s_lfPoolAllocator+188
	leal	272(,%edx,4), %eax
	lock addl	$1, __ZL17s_lfPoolAllocator(%eax)
	movl	$1, %eax
	addl	$40, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L501:
	.cfi_restore_state
	movl	$LC1, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$460, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
L502:
	movl	$LC3, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorI6data_tLj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$466, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
	.cfi_endproc
LFE2494:
	.p2align 4,,15
	.globl	__Z10pushNormalO6data_t
	.def	__Z10pushNormalO6data_t;	.scl	2;	.type	32;	.endef
__Z10pushNormalO6data_t:
LFB2495:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2495
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_stack+256, (%esp)
LEHB40:
	call	_pthread_mutex_lock
LEHE40:
	testl	%eax, %eax
	jne	L508
	movl	__ZL7s_stack+240, %ecx
	cmpl	$19, %ecx
	jbe	L514
	movl	__ZL7s_stack+244, %ecx
	cmpl	$-1, %ecx
	je	L507
	leal	(%ecx,%ecx,2), %eax
	sall	$2, %eax
	movl	__ZL7s_stack(%eax), %edx
	leal	__ZL7s_stack(%eax), %ebx
	movl	%edx, __ZL7s_stack+244
	movl	$1, %edx
	movl	$-16843010, __ZL7s_stack(%eax)
	sall	%cl, %edx
	addl	$1, __ZL7s_stack+252
	orl	%edx, __ZL7s_stack+248
L506:
	movl	$__ZL7s_stack+256, (%esp)
	call	_pthread_mutex_unlock
	movl	32(%esp), %eax
	movl	$0, 8(%ebx)
	movl	$0, 4(%ebx)
	movl	$0, (%ebx)
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	$__ZL7s_stack+264, (%esp)
	movl	%edx, 8(%ebx)
	movl	%eax, 4(%ebx)
LEHB41:
	call	_pthread_mutex_lock
LEHE41:
	testl	%eax, %eax
	jne	L508
	movl	__ZL7s_stack+260, %eax
	movl	$__ZL7s_stack+264, (%esp)
	movl	%eax, (%ebx)
	movl	%ebx, __ZL7s_stack+260
	call	_pthread_mutex_unlock
	movl	$1, %eax
L511:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L514:
	.cfi_restore_state
	leal	1(%ecx), %eax
	leal	(%ecx,%ecx,2), %edx
	movl	%eax, __ZL7s_stack+240
	sall	$2, %edx
	movl	$1, %eax
	movl	$-16843010, __ZL7s_stack(%edx)
	sall	%cl, %eax
	addl	$1, __ZL7s_stack+252
	orl	%eax, __ZL7s_stack+248
	leal	__ZL7s_stack(%edx), %ebx
	jmp	L506
	.p2align 4,,7
L507:
	movl	$__ZL7s_stack+256, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L511
L508:
	movl	%eax, (%esp)
LEHB42:
	call	__ZSt20__throw_system_errori
LEHE42:
	.cfi_endproc
LFE2495:
	.section	.gcc_except_table,"w"
LLSDA2495:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2495-LLSDACSB2495
LLSDACSB2495:
	.uleb128 LEHB40-LFB2495
	.uleb128 LEHE40-LEHB40
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB41-LFB2495
	.uleb128 LEHE41-LEHB41
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB42-LFB2495
	.uleb128 LEHE42-LEHB42
	.uleb128 0
	.uleb128 0
LLSDACSE2495:
	.text
	.p2align 4,,15
	.globl	__Z9popNormalR6data_t
	.def	__Z9popNormalR6data_t;	.scl	2;	.type	32;	.endef
__Z9popNormalR6data_t:
LFB2497:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2497
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_stack+264, (%esp)
LEHB43:
	call	_pthread_mutex_lock
LEHE43:
	testl	%eax, %eax
	jne	L528
	movl	__ZL7s_stack+260, %ebx
	testl	%ebx, %ebx
	je	L523
	movl	(%ebx), %eax
	movl	4(%ebx), %edx
	movl	8(%ebx), %ecx
	movl	%eax, __ZL7s_stack+260
	movl	32(%esp), %eax
	movl	%edx, (%eax)
	movl	%ecx, 4(%eax)
	movl	$__ZL7s_stack+256, (%esp)
LEHB44:
	call	_pthread_mutex_lock
LEHE44:
	testl	%eax, %eax
	jne	L529
	subl	$__ZL7s_stack, %ebx
	movl	$-1431655765, %ecx
	movl	%ebx, %eax
	mull	%ecx
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L530
	movl	__ZL7s_stack+248, %ebx
	movl	$1, %eax
	movl	%edx, %ecx
	sall	%cl, %eax
	testl	%ebx, %eax
	je	L531
	movl	__ZL7s_stack+244, %esi
	notl	%eax
	andl	%ebx, %eax
	movl	$1, %ebx
	leal	(%edx,%edx,2), %ecx
	movl	$__ZL7s_stack+256, (%esp)
	movl	%esi, __ZL7s_stack(,%ecx,4)
	movl	%edx, __ZL7s_stack+244
	movl	%eax, __ZL7s_stack+248
	subl	$1, __ZL7s_stack+252
	call	_pthread_mutex_unlock
L517:
	movl	$__ZL7s_stack+264, (%esp)
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
L523:
	.cfi_restore_state
	xorl	%ebx, %ebx
	jmp	L517
L529:
	movl	%eax, (%esp)
LEHB45:
	call	__ZSt20__throw_system_errori
LEHE45:
L524:
	movl	%eax, %ebx
L522:
	movl	$__ZL7s_stack+264, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, (%esp)
LEHB46:
	call	__Unwind_Resume
L528:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE46:
L531:
	movl	$LC3, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$230, 4(%esp)
	movl	$LC2, (%esp)
LEHB47:
	call	___assert_func
LEHE47:
L525:
	movl	$__ZL7s_stack+256, (%esp)
	movl	%eax, %ebx
	call	_pthread_mutex_unlock
	jmp	L522
L530:
	movl	$LC1, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$224, 4(%esp)
	movl	$LC2, (%esp)
LEHB48:
	call	___assert_func
LEHE48:
	.cfi_endproc
LFE2497:
	.section	.gcc_except_table,"w"
LLSDA2497:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2497-LLSDACSB2497
LLSDACSB2497:
	.uleb128 LEHB43-LFB2497
	.uleb128 LEHE43-LEHB43
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB44-LFB2497
	.uleb128 LEHE44-LEHB44
	.uleb128 L524-LFB2497
	.uleb128 0
	.uleb128 LEHB45-LFB2497
	.uleb128 LEHE45-LEHB45
	.uleb128 L524-LFB2497
	.uleb128 0
	.uleb128 LEHB46-LFB2497
	.uleb128 LEHE46-LEHB46
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB47-LFB2497
	.uleb128 LEHE47-LEHB47
	.uleb128 L525-LFB2497
	.uleb128 0
	.uleb128 LEHB48-LFB2497
	.uleb128 LEHE48-LEHB48
	.uleb128 L525-LFB2497
	.uleb128 0
LLSDACSE2497:
	.text
	.p2align 4,,15
	.globl	__Z12pushLockFreeO6data_t
	.def	__Z12pushLockFreeO6data_t;	.scl	2;	.type	32;	.endef
__Z12pushLockFreeO6data_t:
LFB2498:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	movl	$1, %eax
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$48, %esp
	.cfi_def_cfa_offset 64
	lock xaddl	%eax, __ZL9s_lfStack+320
	cmpl	$19, %eax
	jbe	L549
	movl	$20, __ZL9s_lfStack+320
	movl	$1, %edx
	mfence
	movl	__ZL9s_lfStack+324, %eax
	movl	%eax, 32(%esp)
L535:
	cmpl	$-1, %eax
	je	L538
L550:
	addl	$320, %eax
	movl	$1, %ecx
	lock xaddb	%cl, __ZL9s_lfStack+8(%eax)
	testb	%cl, %cl
	je	L539
	movl	32(%esp), %eax
	addl	$320, %eax
	lock subb	$1, __ZL9s_lfStack+8(%eax)
	movl	__ZL9s_lfStack+324, %eax
	addl	$1, %edx
	cmpl	$1000, %edx
	movl	%eax, 32(%esp)
	je	L536
L552:
	movl	32(%esp), %eax
	cmpl	$-1, %eax
	jne	L550
L538:
	xorl	%eax, %eax
L547:
	addl	$48, %esp
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
L539:
	.cfi_restore_state
	movl	32(%esp), %edi
	leal	32(%esp), %esi
	movl	%edi, %ecx
	movl	%edi, %eax
	sall	$4, %ecx
	leal	__ZL9s_lfStack(%ecx), %ebx
	movl	__ZL9s_lfStack(%ecx), %ecx
	lock cmpxchgl	%ecx, __ZL9s_lfStack+324
	movl	%eax, 32(%esp)
	je	L551
	addl	$320, %edi
	lock subb	$1, __ZL9s_lfStack+8(%edi)
	addl	$1, %edx
	cmpl	$1000, %edx
	jne	L552
L536:
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	__ZL9s_lfStack+324, %eax
	xorl	%edx, %edx
	movl	%eax, 32(%esp)
	jmp	L535
	.p2align 4,,7
L549:
	leal	320(%eax), %edx
	lock addb	$1, __ZL9s_lfStack+8(%edx)
	movl	%eax, %edx
	sall	$4, %edx
	leal	__ZL9s_lfStack(%edx), %ebx
	movl	$-16843010, __ZL9s_lfStack(%edx)
	lock addl	$1, __ZL9s_lfStack+348
	leal	352(,%eax,4), %eax
	lock addl	$1, __ZL9s_lfStack(%eax)
	leal	32(%esp), %esi
L534:
	movl	$0, 12(%ebx)
	movl	$1, %ecx
	movl	$0, 8(%ebx)
	movl	$0, (%ebx)
	movl	$0, 4(%ebx)
	movq	__ZL9s_lfStack+512, %xmm0
	movq	%xmm0, (%ebx)
	mfence
	movl	64(%esp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%edx, 12(%ebx)
	movl	%eax, 8(%ebx)
	lock xaddl	%ecx, __ZL9s_lfStack+520
	movl	%ebx, %eax
	cltd
	orl	%edx, %ecx
L546:
	fildq	(%ebx)
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	fildq	__ZL9s_lfStack+512
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	xorl	36(%esp), %edx
	xorl	32(%esp), %eax
	orl	%eax, %edx
	jne	L542
	movl	(%esi), %eax
	movl	4(%esi), %edx
	lock cmpxchg8b	__ZL9s_lfStack+512
	movl	%eax, %edi
	sete	%al
	testb	%al, %al
	movl	%edi, (%esi)
	movl	%edx, 4(%esi)
	jne	L547
	fildq	32(%esp)
	fistpq	(%ebx)
	mfence
	jmp	L546
	.p2align 4,,7
L542:
	movq	__ZL9s_lfStack+512, %xmm0
	movq	%xmm0, (%ebx)
	mfence
	jmp	L546
	.p2align 4,,7
L551:
	sall	$4, %eax
	movl	$-16843010, __ZL9s_lfStack(%eax)
	lock addl	$1, __ZL9s_lfStack+348
	movl	32(%esp), %eax
	leal	352(,%eax,4), %eax
	lock addl	$1, __ZL9s_lfStack(%eax)
	jmp	L534
	.cfi_endproc
LFE2498:
	.p2align 4,,15
	.globl	__Z11popLockFreeR6data_t
	.def	__Z11popLockFreeR6data_t;	.scl	2;	.type	32;	.endef
__Z11popLockFreeR6data_t:
LFB2499:
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
	fildq	__ZL9s_lfStack+512
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
L566:
	movl	%eax, %esi
	movl	%edx, %eax
	orl	%esi, %eax
	je	L567
L563:
	fildq	(%esi)
	fistpq	24(%esp)
	movl	24(%esp), %edi
	movl	28(%esp), %ebp
	fildq	__ZL9s_lfStack+512
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	xorl	52(%esp), %edx
	xorl	48(%esp), %eax
	orl	%eax, %edx
	je	L568
	fildq	__ZL9s_lfStack+512
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, %esi
	movl	%eax, 48(%esp)
	movl	%edx, %eax
	orl	%esi, %eax
	movl	%edx, 52(%esp)
	jne	L563
L567:
	addl	$76, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	xorl	%edx, %edx
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	movl	%edx, %eax
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
L568:
	.cfi_restore_state
	movl	52(%esp), %edx
	movl	%edi, %ebx
	movl	%ebp, %ecx
	movl	48(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfStack+512
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	jne	L566
	movl	8(%esi), %eax
	movl	12(%esi), %edx
	subl	$__ZL9s_lfStack, %esi
	movl	96(%esp), %ecx
	shrl	$4, %esi
	cmpl	$19, %esi
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	ja	L569
	movzbl	__ZL9s_lfStack+328(%esi), %eax
	leal	__ZL9s_lfStack+328(%esi), %ebx
	testb	%al, %al
	je	L570
	movl	__ZL9s_lfStack+324, %eax
	movl	%esi, %ecx
	sall	$4, %ecx
	addl	$__ZL9s_lfStack, %ecx
	movl	%eax, 32(%esp)
	.p2align 4,,7
L561:
	movl	%eax, (%ecx)
	movl	32(%esp), %eax
	lock cmpxchgl	%esi, __ZL9s_lfStack+324
	sete	%dl
	testb	%dl, %dl
	movl	%eax, 32(%esp)
	je	L561
	lock subb	$1, (%ebx)
	lock subl	$1, __ZL9s_lfStack+348
	leal	432(,%esi,4), %eax
	lock addl	$1, __ZL9s_lfStack(%eax)
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
L569:
	.cfi_restore_state
	movl	$LC1, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$460, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
L570:
	movl	$LC3, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$466, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
	.cfi_endproc
LFE2499:
	.p2align 4,,15
	.globl	__Z13enqueueNormalO6data_t
	.def	__Z13enqueueNormalO6data_t;	.scl	2;	.type	32;	.endef
__Z13enqueueNormalO6data_t:
LFB2500:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2500
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL7s_queue+256, (%esp)
LEHB49:
	call	_pthread_mutex_lock
LEHE49:
	testl	%eax, %eax
	jne	L576
	movl	__ZL7s_queue+240, %ecx
	cmpl	$19, %ecx
	jbe	L582
	movl	__ZL7s_queue+244, %ecx
	cmpl	$-1, %ecx
	je	L575
	leal	(%ecx,%ecx,2), %eax
	sall	$2, %eax
	movl	__ZL7s_queue(%eax), %edx
	leal	__ZL7s_queue(%eax), %ebx
	movl	%edx, __ZL7s_queue+244
	movl	$1, %edx
	movl	$-16843010, __ZL7s_queue(%eax)
	sall	%cl, %edx
	addl	$1, __ZL7s_queue+252
	orl	%edx, __ZL7s_queue+248
L574:
	movl	$__ZL7s_queue+256, (%esp)
	call	_pthread_mutex_unlock
	movl	32(%esp), %eax
	movl	$0, 8(%ebx)
	movl	$0, 4(%ebx)
	movl	$0, (%ebx)
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	$__ZL7s_queue+268, (%esp)
	movl	%edx, 8(%ebx)
	movl	%eax, 4(%ebx)
LEHB50:
	call	_pthread_mutex_lock
LEHE50:
	testl	%eax, %eax
	jne	L576
	movl	__ZL7s_queue+264, %eax
	movl	%ebx, (%eax)
	movl	$__ZL7s_queue+268, (%esp)
	movl	%ebx, __ZL7s_queue+264
	call	_pthread_mutex_unlock
	movl	$1, %eax
L579:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L582:
	.cfi_restore_state
	leal	1(%ecx), %eax
	leal	(%ecx,%ecx,2), %edx
	movl	%eax, __ZL7s_queue+240
	sall	$2, %edx
	movl	$1, %eax
	movl	$-16843010, __ZL7s_queue(%edx)
	sall	%cl, %eax
	addl	$1, __ZL7s_queue+252
	orl	%eax, __ZL7s_queue+248
	leal	__ZL7s_queue(%edx), %ebx
	jmp	L574
	.p2align 4,,7
L575:
	movl	$__ZL7s_queue+256, (%esp)
	call	_pthread_mutex_unlock
	xorl	%eax, %eax
	jmp	L579
L576:
	movl	%eax, (%esp)
LEHB51:
	call	__ZSt20__throw_system_errori
LEHE51:
	.cfi_endproc
LFE2500:
	.section	.gcc_except_table,"w"
LLSDA2500:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2500-LLSDACSB2500
LLSDACSB2500:
	.uleb128 LEHB49-LFB2500
	.uleb128 LEHE49-LEHB49
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB50-LFB2500
	.uleb128 LEHE50-LEHB50
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB51-LFB2500
	.uleb128 LEHE51-LEHB51
	.uleb128 0
	.uleb128 0
LLSDACSE2500:
	.text
	.p2align 4,,15
	.globl	__Z13dequeueNormalR6data_t
	.def	__Z13dequeueNormalR6data_t;	.scl	2;	.type	32;	.endef
__Z13dequeueNormalR6data_t:
LFB2501:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2501
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
	movl	$__ZL7s_queue+268, (%esp)
LEHB52:
	call	_pthread_mutex_lock
LEHE52:
	testl	%eax, %eax
	jne	L596
	movl	__ZL7s_queue+260, %esi
	cmpl	__ZL7s_queue+264, %esi
	je	L591
	movl	(%esi), %ebx
	movl	$__ZL7s_queue+256, (%esp)
LEHB53:
	call	_pthread_mutex_lock
LEHE53:
	testl	%eax, %eax
	jne	L597
	subl	$__ZL7s_queue, %esi
	movl	$-1431655765, %ecx
	movl	%esi, %eax
	mull	%ecx
	shrl	$3, %edx
	cmpl	$19, %edx
	ja	L598
	movl	__ZL7s_queue+248, %esi
	movl	$1, %eax
	movl	%edx, %ecx
	sall	%cl, %eax
	testl	%esi, %eax
	je	L599
	movl	__ZL7s_queue+244, %edi
	notl	%eax
	leal	(%edx,%edx,2), %ecx
	andl	%esi, %eax
	movl	$__ZL7s_queue+256, (%esp)
	movl	%edi, __ZL7s_queue(,%ecx,4)
	movl	%edx, __ZL7s_queue+244
	movl	%eax, __ZL7s_queue+248
	subl	$1, __ZL7s_queue+252
	call	_pthread_mutex_unlock
	movl	4(%ebx), %eax
	movl	8(%ebx), %edx
	movl	32(%esp), %ecx
	movl	%ebx, __ZL7s_queue+260
	movl	$1, %ebx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
L585:
	movl	$__ZL7s_queue+268, (%esp)
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
L591:
	.cfi_restore_state
	xorl	%ebx, %ebx
	jmp	L585
L597:
	movl	%eax, (%esp)
LEHB54:
	call	__ZSt20__throw_system_errori
LEHE54:
L592:
	movl	%eax, %ebx
L590:
	movl	$__ZL7s_queue+268, (%esp)
	call	_pthread_mutex_unlock
	movl	%ebx, (%esp)
LEHB55:
	call	__Unwind_Resume
L596:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE55:
L599:
	movl	$LC3, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$230, 4(%esp)
	movl	$LC2, (%esp)
LEHB56:
	call	___assert_func
LEHE56:
L593:
	movl	$__ZL7s_queue+256, (%esp)
	movl	%eax, %ebx
	call	_pthread_mutex_unlock
	jmp	L590
L598:
	movl	$LC1, 12(%esp)
	movl	$__ZZN14pool_allocatorIN5queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$224, 4(%esp)
	movl	$LC2, (%esp)
LEHB57:
	call	___assert_func
LEHE57:
	.cfi_endproc
LFE2501:
	.section	.gcc_except_table,"w"
LLSDA2501:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2501-LLSDACSB2501
LLSDACSB2501:
	.uleb128 LEHB52-LFB2501
	.uleb128 LEHE52-LEHB52
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB53-LFB2501
	.uleb128 LEHE53-LEHB53
	.uleb128 L592-LFB2501
	.uleb128 0
	.uleb128 LEHB54-LFB2501
	.uleb128 LEHE54-LEHB54
	.uleb128 L592-LFB2501
	.uleb128 0
	.uleb128 LEHB55-LFB2501
	.uleb128 LEHE55-LEHB55
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB56-LFB2501
	.uleb128 LEHE56-LEHB56
	.uleb128 L593-LFB2501
	.uleb128 0
	.uleb128 LEHB57-LFB2501
	.uleb128 LEHE57-LEHB57
	.uleb128 L593-LFB2501
	.uleb128 0
LLSDACSE2501:
	.text
	.p2align 4,,15
	.globl	__Z15enqueueLockFreeO6data_t
	.def	__Z15enqueueLockFreeO6data_t;	.scl	2;	.type	32;	.endef
__Z15enqueueLockFreeO6data_t:
LFB2502:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$1, %eax
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
	lock xaddl	%eax, __ZL9s_lfQueue+320
	cmpl	$19, %eax
	jbe	L621
	movl	$20, __ZL9s_lfQueue+320
	movl	$1, %edx
	mfence
	movl	__ZL9s_lfQueue+324, %eax
	movl	%eax, 48(%esp)
L603:
	cmpl	$-1, %eax
	je	L606
L622:
	addl	$320, %eax
	movl	$1, %ecx
	lock xaddb	%cl, __ZL9s_lfQueue+8(%eax)
	testb	%cl, %cl
	je	L607
	movl	48(%esp), %eax
	addl	$320, %eax
	lock subb	$1, __ZL9s_lfQueue+8(%eax)
	movl	__ZL9s_lfQueue+324, %eax
	addl	$1, %edx
	cmpl	$1000, %edx
	movl	%eax, 48(%esp)
	je	L604
L624:
	movl	48(%esp), %eax
	cmpl	$-1, %eax
	jne	L622
L606:
	addl	$76, %esp
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
L607:
	.cfi_restore_state
	movl	48(%esp), %ebx
	leal	48(%esp), %esi
	movl	%ebx, %ecx
	movl	%ebx, %eax
	sall	$4, %ecx
	leal	__ZL9s_lfQueue(%ecx), %edi
	movl	__ZL9s_lfQueue(%ecx), %ecx
	lock cmpxchgl	%ecx, __ZL9s_lfQueue+324
	movl	%eax, 48(%esp)
	je	L623
	addl	$320, %ebx
	lock subb	$1, __ZL9s_lfQueue+8(%ebx)
	addl	$1, %edx
	cmpl	$1000, %edx
	jne	L624
L604:
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	__ZL9s_lfQueue+324, %eax
	xorl	%edx, %edx
	movl	%eax, 48(%esp)
	jmp	L603
	.p2align 4,,7
L621:
	leal	320(%eax), %edx
	lock addb	$1, __ZL9s_lfQueue+8(%edx)
	movl	%eax, %edx
	sall	$4, %edx
	leal	__ZL9s_lfQueue(%edx), %edi
	movl	$-16843010, __ZL9s_lfQueue(%edx)
	lock addl	$1, __ZL9s_lfQueue+348
	leal	352(,%eax,4), %eax
	lock addl	$1, __ZL9s_lfQueue(%eax)
	leal	48(%esp), %esi
L602:
	movl	$0, (%edi)
	movl	$1, %ecx
	movl	$0, 4(%edi)
	movl	$0, 8(%edi)
	movl	$0, 12(%edi)
	lock xaddl	%ecx, __ZL9s_lfQueue+528
	movl	%edi, %eax
	cltd
	xorl	%eax, %eax
	orl	%edx, %ecx
	xorl	%edx, %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	movl	%ecx, 20(%esp)
	fistpq	(%edi)
	mfence
	movl	96(%esp), %eax
	movl	$0, 32(%esp)
	movl	$0, 36(%esp)
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%edx, 12(%edi)
	movl	%eax, 8(%edi)
L615:
	fildq	__ZL9s_lfQueue+520
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	movl	%eax, 16(%esp)
	fildq	(%eax)
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	fildq	__ZL9s_lfQueue+520
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	xorl	36(%esp), %edx
	xorl	32(%esp), %eax
	orl	%eax, %edx
	jne	L615
	movl	52(%esp), %ecx
	movl	48(%esp), %ebp
	movl	%ecx, %eax
	orl	%ebp, %eax
	jne	L612
	movl	(%esi), %eax
	movl	%edi, %ebx
	movl	4(%esi), %edx
	movl	20(%esp), %ecx
	movl	16(%esp), %ebp
	lock cmpxchg8b	0(%ebp)
	sete	%bl
	testb	%bl, %bl
	movl	%ebx, %ebp
	movl	%eax, (%esi)
	movl	%edx, 4(%esi)
	je	L615
	movl	36(%esp), %edx
	movl	%edi, %ebx
	movl	32(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfQueue+520
	addl	$76, %esp
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
L612:
	.cfi_restore_state
	movl	36(%esp), %edx
	movl	%ebp, %ebx
	movl	32(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfQueue+520
	movl	%eax, 32(%esp)
	movl	%edx, 36(%esp)
	jmp	L615
	.p2align 4,,7
L623:
	sall	$4, %eax
	movl	$-16843010, __ZL9s_lfQueue(%eax)
	lock addl	$1, __ZL9s_lfQueue+348
	movl	48(%esp), %eax
	leal	352(,%eax,4), %eax
	lock addl	$1, __ZL9s_lfQueue(%eax)
	jmp	L602
	.cfi_endproc
LFE2502:
	.p2align 4,,15
	.globl	__Z15dequeueLockFreeR6data_t
	.def	__Z15dequeueLockFreeR6data_t;	.scl	2;	.type	32;	.endef
__Z15dequeueLockFreeR6data_t:
LFB2503:
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
	.p2align 4,,7
L628:
	fildq	__ZL9s_lfQueue+512
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	fildq	__ZL9s_lfQueue+520
	fistpq	24(%esp)
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	movl	%eax, 64(%esp)
	movl	48(%esp), %eax
	movl	%edx, 68(%esp)
	movl	%eax, 20(%esp)
	movl	%eax, %ecx
	fildq	(%eax)
	fistpq	24(%esp)
	movl	24(%esp), %esi
	movl	28(%esp), %edi
	fildq	__ZL9s_lfQueue+512
	fistpq	24(%esp)
	movl	52(%esp), %ebp
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	xorl	%ecx, %eax
	xorl	%ebp, %edx
	orl	%eax, %edx
	jne	L628
	movl	%ecx, %eax
	movl	%esi, %ebx
	xorl	68(%esp), %ebp
	movl	%edi, %ecx
	xorl	64(%esp), %eax
	orl	%eax, %ebp
	jne	L629
	movl	%esi, %eax
	orl	%edi, %eax
	je	L636
	movl	68(%esp), %edx
	movl	64(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfQueue+520
	movl	%eax, 64(%esp)
	movl	%edx, 68(%esp)
	jmp	L628
	.p2align 4,,7
L629:
	movl	52(%esp), %edx
	movl	48(%esp), %eax
	lock cmpxchg8b	__ZL9s_lfQueue+512
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	jne	L628
	movl	20(%esp), %ebx
	movl	8(%esi), %eax
	movl	12(%esi), %edx
	movl	112(%esp), %ecx
	subl	$__ZL9s_lfQueue, %ebx
	shrl	$4, %ebx
	cmpl	$19, %ebx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	ja	L641
	movzbl	__ZL9s_lfQueue+328(%ebx), %eax
	leal	__ZL9s_lfQueue+328(%ebx), %esi
	testb	%al, %al
	je	L642
	movl	__ZL9s_lfQueue+324, %eax
	movl	%ebx, %ecx
	sall	$4, %ecx
	addl	$__ZL9s_lfQueue, %ecx
	movl	%eax, 32(%esp)
	.p2align 4,,7
L635:
	movl	%eax, (%ecx)
	movl	32(%esp), %eax
	lock cmpxchgl	%ebx, __ZL9s_lfQueue+324
	sete	%dl
	testb	%dl, %dl
	movl	%eax, 32(%esp)
	je	L635
	lock subb	$1, (%esi)
	lock subl	$1, __ZL9s_lfQueue+348
	leal	432(,%ebx,4), %eax
	lock addl	$1, __ZL9s_lfQueue(%eax)
L630:
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
L636:
	.cfi_restore_state
	xorl	%edx, %edx
	jmp	L630
L642:
	movl	$LC3, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$466, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
L641:
	movl	$LC1, 12(%esp)
	movl	$__ZZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EE10ptrToIndexEPvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$460, 4(%esp)
	movl	$LC2, (%esp)
	call	___assert_func
	.cfi_endproc
LFE2503:
	.section	.text$_ZN17lf_pool_allocatorI6data_tLj20EEC1Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZN17lf_pool_allocatorI6data_tLj20EEC1Ev
	.def	__ZN17lf_pool_allocatorI6data_tLj20EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN17lf_pool_allocatorI6data_tLj20EEC1Ev:
LFB2691:
	.cfi_startproc
	movl	4(%esp), %ecx
	xorl	%eax, %eax
	movl	$0, 160(%ecx)
	leal	192(%ecx), %edx
	mfence
	movl	$-1, 164(%ecx)
	mfence
	movl	$0, 188(%ecx)
	mfence
	.p2align 4,,7
L645:
	movb	$0, 168(%ecx,%eax)
	addl	$1, %eax
	addl	$4, %edx
	mfence
	movl	$0, -4(%edx)
	mfence
	movl	$0, 76(%edx)
	cmpl	$20, %eax
	mfence
	jne	L645
	rep ret
	.cfi_endproc
LFE2691:
	.section	.text$_ZN5queueI6data_tLj20EEC1Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZN5queueI6data_tLj20EEC1Ev
	.def	__ZN5queueI6data_tLj20EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN5queueI6data_tLj20EEC1Ev:
LFB2709:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2709
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
	leal	256(%ebx), %edi
	movl	$0, 240(%ebx)
	movl	$-1, 244(%ebx)
	movl	$0, 248(%ebx)
	movl	$20, 256(%ebx)
	movl	$20, 268(%ebx)
	movl	%edi, (%esp)
LEHB58:
	call	_pthread_mutex_lock
LEHE58:
	testl	%eax, %eax
	jne	L654
	movl	240(%ebx), %ecx
	cmpl	$19, %ecx
	jbe	L655
	movl	244(%ebx), %ecx
	cmpl	$-1, %ecx
	je	L650
	leal	(%ecx,%ecx,2), %eax
	leal	(%ebx,%eax,4), %esi
	movl	(%esi), %eax
	movl	%eax, 244(%ebx)
	movl	$1, %eax
	movl	$-16843010, (%esi)
	sall	%cl, %eax
	addl	$1, 252(%ebx)
	orl	%eax, 248(%ebx)
L649:
	movl	%edi, (%esp)
	call	_pthread_mutex_unlock
	movl	$0, (%esi)
	movl	$0, 4(%esi)
	movl	$0, 8(%esi)
L651:
	movl	$0, (%esi)
	movl	%esi, 260(%ebx)
	movl	%esi, 264(%ebx)
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
L655:
	.cfi_restore_state
	leal	1(%ecx), %eax
	movl	%eax, 240(%ebx)
	leal	(%ecx,%ecx,2), %eax
	leal	(%ebx,%eax,4), %esi
	movl	$1, %eax
	movl	$-16843010, (%esi)
	sall	%cl, %eax
	addl	$1, 252(%ebx)
	orl	%eax, 248(%ebx)
	jmp	L649
	.p2align 4,,7
L650:
	movl	%edi, (%esp)
	xorl	%esi, %esi
	call	_pthread_mutex_unlock
	jmp	L651
L654:
	movl	%eax, (%esp)
LEHB59:
	call	__ZSt20__throw_system_errori
LEHE59:
	.cfi_endproc
LFE2709:
	.section	.gcc_except_table,"w"
LLSDA2709:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2709-LLSDACSB2709
LLSDACSB2709:
	.uleb128 LEHB58-LFB2709
	.uleb128 LEHE58-LEHB58
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB59-LFB2709
	.uleb128 LEHE59-LEHB59
	.uleb128 0
	.uleb128 0
LLSDACSE2709:
	.section	.text$_ZN5queueI6data_tLj20EEC1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv
	.def	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv;	.scl	2;	.type	32;	.endef
__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv:
LFB2913:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	lock subl	$1, 4(%ebx)
	je	L661
L656:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
L661:
	.cfi_restore_state
	movl	(%ebx), %eax
	movl	%ebx, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%ebx)
	jne	L656
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
LFE2913:
	.section .rdata,"dr"
	.align 4
LC4:
	.ascii "--------------------------------------------------------------------------------\0"
LC5:
	.ascii "[%s:START]\12\0"
	.align 4
LC6:
	.ascii "*Test count                = %d\12\0"
	.align 4
LC7:
	.ascii "*Push/Enqueue test threads = %d\12\0"
	.align 4
LC8:
	.ascii "*Pop/Dequeue  test threads = %d\12\0"
	.align 4
LC9:
	.ascii "*Memory pool size          = %d\12\0"
LC11:
	.ascii "[%s:END] elapsed_time=%.9llf\12\0"
	.text
	.align 2
	.p2align 4,,15
	.def	__ZZ11thread_testvENKUlPKcS0_S0_St8functionIFbO6data_tEES1_IFbRS2_EEE0_clES0_S0_S0_S5_S8_.isra.218;	.scl	3;	.type	32;	.endef
__ZZ11thread_testvENKUlPKcS0_S0_St8functionIFbO6data_tEES1_IFbRS2_EEE0_clES0_S0_S0_S5_S8_.isra.218:
LFB3911:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3911
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
	subl	$188, %esp
	.cfi_def_cfa_offset 208
	movl	$LC4, (%esp)
	movl	%edx, 44(%esp)
	movl	%ecx, 40(%esp)
	movl	%eax, 28(%esp)
LEHB60:
	call	_puts
	movl	%ebx, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$20000, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	$10, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	$5, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
	movl	$20, 4(%esp)
	movl	$LC9, (%esp)
	call	_printf
LEHE60:
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
LEHB61:
	call	_pthread_mutex_lock
LEHE61:
	testl	%eax, %eax
	jne	L726
	xorl	%ebx, %ebx
	jmp	L690
	.p2align 4,,7
L666:
	movl	%esi, 136(%esp,%ebx,4)
	addl	$1, %ebx
	cmpl	$10, %ebx
	je	L727
L690:
	movl	$4, (%esp)
LEHB62:
	call	__Znwj
LEHE62:
	movl	$0, (%eax)
	movl	%eax, %esi
	movl	$72, (%esp)
LEHB63:
	call	__Znwj
LEHE63:
	movl	%eax, %edi
	xorl	%eax, %eax
	testl	%edi, %edi
	je	L664
	leal	16(%edi), %eax
	movl	%eax, 12(%edi)
	leal	44(%esp), %eax
	movl	%eax, 32(%edi)
	movl	208(%esp), %eax
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
L664:
	leal	112(%esp), %ebp
	movl	%ebp, 4(%esp)
	movl	%esi, (%esp)
	movl	%eax, 112(%esp)
	movl	%edi, 116(%esp)
LEHB64:
	call	__ZNSt6thread15_M_start_threadESt10shared_ptrINS_10_Impl_baseEE
LEHE64:
	movl	116(%esp), %edi
	testl	%edi, %edi
	je	L666
	lock subl	$1, 4(%edi)
	jne	L666
	movl	(%edi), %eax
	movl	%edi, (%esp)
	call	*8(%eax)
	lock subl	$1, 8(%edi)
	jne	L666
	movl	(%edi), %eax
	movl	%edi, (%esp)
	call	*12(%eax)
	movl	%esi, 136(%esp,%ebx,4)
	addl	$1, %ebx
	cmpl	$10, %ebx
	jne	L690
	.p2align 4,,7
L727:
	xorl	%esi, %esi
	jmp	L692
	.p2align 4,,7
L672:
	movl	%edi, 0(%ebp,%esi,4)
	addl	$1, %esi
	addl	$1, %ebx
	cmpl	$5, %esi
	je	L728
L692:
	movl	$4, (%esp)
LEHB65:
	call	__Znwj
LEHE65:
	movl	$0, (%eax)
	movl	%eax, %edi
	movl	$68, (%esp)
LEHB66:
	call	__Znwj
LEHE66:
	movl	%eax, %edx
	xorl	%eax, %eax
	testl	%edx, %edx
	je	L670
	leal	16(%edx), %eax
	movl	%eax, 12(%edx)
	leal	40(%esp), %eax
	movl	%eax, 32(%edx)
	movl	212(%esp), %eax
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
L670:
	movl	%eax, 96(%esp)
	leal	96(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	movl	%edx, 100(%esp)
LEHB67:
	call	__ZNSt6thread15_M_start_threadESt10shared_ptrINS_10_Impl_baseEE
LEHE67:
	movl	100(%esp), %eax
	testl	%eax, %eax
	je	L672
	lock subl	$1, 4(%eax)
	jne	L672
	movl	(%eax), %edx
	movl	%eax, 16(%esp)
	movl	%eax, (%esp)
	call	*8(%edx)
	movl	16(%esp), %eax
	movl	$-1, %edx
	lock xaddl	%edx, 8(%eax)
	cmpl	$1, %edx
	jne	L672
	movl	(%eax), %edx
	addl	$1, %ebx
	movl	%eax, (%esp)
	call	*12(%edx)
	movl	%edi, 0(%ebp,%esi,4)
	addl	$1, %esi
	cmpl	$5, %esi
	jne	L692
	.p2align 4,,7
L728:
	movl	$1000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
LEHB68:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
LEHE68:
	leal	64(%esp), %eax
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	movb	$1, 59(%esp)
	mfence
	.p2align 4,,7
L677:
	leal	60(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSt18condition_variable10notify_allEv
	movl	$1000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
LEHB69:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	76(%esp), %eax
	cmpl	%eax, %ebx
	jne	L677
	leal	136(%esp), %ebx
	leal	176(%esp), %esi
	.p2align 4,,7
L681:
	movl	(%ebx), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
LEHE69:
	movl	(%ebx), %edi
	testl	%edi, %edi
	je	L678
	movl	$0, 4(%esp)
	movl	(%edi), %eax
	movl	%eax, (%esp)
	call	_pthread_equal
	testl	%eax, %eax
	je	L683
	movl	%edi, (%esp)
	call	__ZdlPv
L678:
	movl	$0, (%ebx)
	addl	$4, %ebx
	cmpl	%esi, %ebx
	jne	L681
	leal	132(%esp), %ebx
L686:
	movl	0(%ebp), %eax
	movl	%eax, (%esp)
LEHB70:
	call	__ZNSt6thread4joinEv
LEHE70:
	movl	0(%ebp), %esi
	testl	%esi, %esi
	je	L682
	movl	$0, 4(%esp)
	movl	(%esi), %eax
	movl	%eax, (%esp)
	call	_pthread_equal
	testl	%eax, %eax
	je	L683
	movl	%esi, (%esp)
	call	__ZdlPv
L682:
	movl	$0, 0(%ebp)
	addl	$4, %ebp
	cmpl	%ebx, %ebp
	jne	L686
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC11, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 32(%esp)
	movl	28(%esp), %eax
	movl	%edx, 36(%esp)
	fildq	32(%esp)
	fdivs	LC10
	movl	%eax, 4(%esp)
	fstpl	8(%esp)
LEHB71:
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
LEHE71:
	leal	60(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSt18condition_variableD1Ev
	addl	$188, %esp
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
L683:
	.cfi_restore_state
	call	__ZSt9terminatev
L700:
	movl	100(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L675
	movl	%edx, (%esp)
	call	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv
L675:
	movl	%edi, (%esp)
	call	__ZdlPv
L687:
	leal	64(%esp), %eax
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
L688:
	leal	60(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSt18condition_variableD1Ev
	movl	%ebx, (%esp)
LEHB72:
	call	__Unwind_Resume
LEHE72:
L697:
	movl	%eax, %ebx
	jmp	L675
L699:
	movl	116(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L669
	movl	%edx, (%esp)
	call	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv
L669:
	movl	%esi, (%esp)
	call	__ZdlPv
	jmp	L687
L698:
	movl	%eax, %ebx
	.p2align 4,,3
	jmp	L669
L696:
	movl	%eax, %ebx
	.p2align 4,,7
	jmp	L687
L726:
	movl	%eax, (%esp)
LEHB73:
	call	__ZSt20__throw_system_errori
LEHE73:
L695:
	movl	%eax, %ebx
	jmp	L688
	.cfi_endproc
LFE3911:
	.section	.gcc_except_table,"w"
LLSDA3911:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3911-LLSDACSB3911
LLSDACSB3911:
	.uleb128 LEHB60-LFB3911
	.uleb128 LEHE60-LEHB60
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB61-LFB3911
	.uleb128 LEHE61-LEHB61
	.uleb128 L695-LFB3911
	.uleb128 0
	.uleb128 LEHB62-LFB3911
	.uleb128 LEHE62-LEHB62
	.uleb128 L696-LFB3911
	.uleb128 0
	.uleb128 LEHB63-LFB3911
	.uleb128 LEHE63-LEHB63
	.uleb128 L698-LFB3911
	.uleb128 0
	.uleb128 LEHB64-LFB3911
	.uleb128 LEHE64-LEHB64
	.uleb128 L699-LFB3911
	.uleb128 0
	.uleb128 LEHB65-LFB3911
	.uleb128 LEHE65-LEHB65
	.uleb128 L696-LFB3911
	.uleb128 0
	.uleb128 LEHB66-LFB3911
	.uleb128 LEHE66-LEHB66
	.uleb128 L697-LFB3911
	.uleb128 0
	.uleb128 LEHB67-LFB3911
	.uleb128 LEHE67-LEHB67
	.uleb128 L700-LFB3911
	.uleb128 0
	.uleb128 LEHB68-LFB3911
	.uleb128 LEHE68-LEHB68
	.uleb128 L696-LFB3911
	.uleb128 0
	.uleb128 LEHB69-LFB3911
	.uleb128 LEHE69-LEHB69
	.uleb128 L695-LFB3911
	.uleb128 0
	.uleb128 LEHB70-LFB3911
	.uleb128 LEHE70-LEHB70
	.uleb128 L695-LFB3911
	.uleb128 0
	.uleb128 LEHB71-LFB3911
	.uleb128 LEHE71-LEHB71
	.uleb128 L695-LFB3911
	.uleb128 0
	.uleb128 LEHB72-LFB3911
	.uleb128 LEHE72-LEHB72
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB73-LFB3911
	.uleb128 LEHE73-LEHB73
	.uleb128 L695-LFB3911
	.uleb128 0
LLSDACSE3911:
	.text
	.section .rdata,"dr"
	.align 4
LC12:
	.ascii "================================================================================\0"
	.align 4
LC13:
	.ascii "[Test for Lock-free pool-allocator/stack/queue with threads]\0"
LC14:
	.ascii "Normal Pool-allocator\0"
	.align 4
LC15:
	.ascii "*Test count                     = %d\12\0"
	.align 4
LC16:
	.ascii "*Allocate and free test threads = %d\12\0"
	.align 4
LC17:
	.ascii "*Memory pool size               = %d\12\0"
LC18:
	.ascii "Lock-Free Pool-allocator\0"
LC19:
	.ascii "POP \0"
LC20:
	.ascii "PUSH\0"
LC21:
	.ascii "Normal Stack\0"
LC22:
	.ascii "Lock-Free Stack\0"
LC23:
	.ascii "DEQUEUE\0"
LC24:
	.ascii "ENQUEUE\0"
LC25:
	.ascii "Normal Queue\0"
LC26:
	.ascii "Lock-Free Queue\0"
	.text
	.p2align 4,,15
	.globl	__Z11thread_testv
	.def	__Z11thread_testv;	.scl	2;	.type	32;	.endef
__Z11thread_testv:
LFB2522:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2522
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
	subl	$300, %esp
	.cfi_def_cfa_offset 320
	movl	$LC12, (%esp)
LEHB74:
	call	_puts
	movl	$LC13, (%esp)
	call	_puts
LEHE74:
	movl	$1, (%esp)
	movl	$0, 120(%esp)
LEHB75:
	call	__Znwj
LEHE75:
	movl	$1, (%esp)
	movl	%eax, 112(%esp)
	movl	$__ZNSt17_Function_handlerIFbP6data_tEZ11thread_testvEUlS1_E3_E9_M_invokeERKSt9_Any_dataS1_, 124(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlP6data_tE3_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 120(%esp)
	movl	$0, 104(%esp)
LEHB76:
	call	__Znwj
LEHE76:
	movl	$LC4, (%esp)
	movl	%eax, 96(%esp)
	movl	$__ZNSt17_Function_handlerIFP6data_tvEZ11thread_testvEUlvE2_E9_M_invokeERKSt9_Any_data, 108(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlvE2_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation, 104(%esp)
LEHB77:
	call	_puts
	movl	$LC14, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$20000, 4(%esp)
	movl	$LC15, (%esp)
	call	_printf
	movl	$15, 4(%esp)
	movl	$LC16, (%esp)
	call	_printf
	movl	$20, 4(%esp)
	movl	$LC17, (%esp)
	call	_printf
LEHE77:
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
LEHB78:
	call	_pthread_mutex_lock
LEHE78:
	testl	%eax, %eax
	jne	L999
	xorl	%ebx, %ebx
	jmp	L836
	.p2align 4,,7
L740:
	movl	%ebp, 160(%esp,%ebx,4)
	addl	$1, %ebx
	cmpl	$15, %ebx
	je	L1000
L836:
	movl	$4, (%esp)
LEHB79:
	call	__Znwj
LEHE79:
	movl	$0, (%eax)
	movl	%eax, %ebp
	movl	$68, (%esp)
LEHB80:
	call	__Znwj
LEHE80:
	movl	%eax, %esi
	xorl	%eax, %eax
	testl	%esi, %esi
	je	L738
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
L738:
	movl	%esi, 228(%esp)
	leal	224(%esp), %esi
	movl	%esi, 4(%esp)
	movl	%ebp, (%esp)
	movl	%eax, 224(%esp)
LEHB81:
	call	__ZNSt6thread15_M_start_threadESt10shared_ptrINS_10_Impl_baseEE
LEHE81:
	movl	228(%esp), %eax
	testl	%eax, %eax
	je	L740
	lock subl	$1, 4(%eax)
	jne	L740
	movl	(%eax), %edx
	movl	%eax, 16(%esp)
	movl	%eax, (%esp)
	call	*8(%edx)
	movl	16(%esp), %eax
	movl	$-1, %edx
	lock xaddl	%edx, 8(%eax)
	cmpl	$1, %edx
	jne	L740
	movl	(%eax), %edx
	movl	%eax, (%esp)
	call	*12(%edx)
	movl	%ebp, 160(%esp,%ebx,4)
	addl	$1, %ebx
	cmpl	$15, %ebx
	jne	L836
	.p2align 4,,7
L1000:
	movl	$1000000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
LEHB82:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
LEHE82:
	leal	44(%esp), %eax
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	movb	$1, 38(%esp)
	mfence
	.p2align 4,,7
L745:
	movl	%edi, (%esp)
	call	__ZNSt18condition_variable10notify_allEv
	movl	$1000000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
LEHB83:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	56(%esp), %eax
	cmpl	$15, %eax
	jne	L745
	leal	160(%esp), %ebx
	.p2align 4,,7
L749:
	movl	(%ebx), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
LEHE83:
	movl	(%ebx), %ebp
	testl	%ebp, %ebp
	je	L746
	movl	$0, 4(%esp)
	movl	0(%ebp), %eax
	movl	%eax, (%esp)
	call	_pthread_equal
	testl	%eax, %eax
	je	L773
	movl	%ebp, (%esp)
	call	__ZdlPv
L746:
	movl	$0, (%ebx)
	leal	220(%esp), %eax
	addl	$4, %ebx
	cmpl	%eax, %ebx
	jne	L749
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC14, 4(%esp)
	movl	$LC11, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC10
	fstpl	8(%esp)
LEHB84:
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
LEHE84:
	movl	%edi, (%esp)
	call	__ZNSt18condition_variableD1Ev
	movl	104(%esp), %eax
	testl	%eax, %eax
	je	L751
	leal	96(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L751:
	movl	120(%esp), %eax
	testl	%eax, %eax
	je	L755
	leal	112(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L755:
	movl	$1, (%esp)
	movl	$0, 152(%esp)
LEHB85:
	call	__Znwj
LEHE85:
	movl	$1, (%esp)
	movl	%eax, 144(%esp)
	movl	$__ZNSt17_Function_handlerIFbP6data_tEZ11thread_testvEUlS1_E5_E9_M_invokeERKSt9_Any_dataS1_, 156(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlP6data_tE5_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 152(%esp)
	movl	$0, 136(%esp)
LEHB86:
	call	__Znwj
LEHE86:
	movl	$LC4, (%esp)
	movl	%eax, 128(%esp)
	movl	$__ZNSt17_Function_handlerIFP6data_tvEZ11thread_testvEUlvE4_E9_M_invokeERKSt9_Any_data, 140(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlvE4_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation, 136(%esp)
LEHB87:
	call	_puts
	movl	$LC18, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$20000, 4(%esp)
	movl	$LC15, (%esp)
	call	_printf
	movl	$15, 4(%esp)
	movl	$LC16, (%esp)
	call	_printf
	movl	$20, 4(%esp)
	movl	$LC17, (%esp)
	call	_printf
LEHE87:
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
LEHB88:
	call	_pthread_mutex_lock
LEHE88:
	testl	%eax, %eax
	jne	L1001
	xorl	%ebx, %ebx
	jmp	L838
	.p2align 4,,7
L766:
	movl	%edi, (%esi,%ebx,4)
	addl	$1, %ebx
	cmpl	$15, %ebx
	je	L1002
L838:
	movl	$4, (%esp)
LEHB89:
	call	__Znwj
LEHE89:
	movl	$0, (%eax)
	movl	%eax, %edi
	movl	$68, (%esp)
LEHB90:
	call	__Znwj
LEHE90:
	movl	%eax, %ebp
	xorl	%eax, %eax
	testl	%ebp, %ebp
	je	L764
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
L764:
	movl	%eax, 160(%esp)
	leal	160(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	movl	%ebp, 164(%esp)
LEHB91:
	call	__ZNSt6thread15_M_start_threadESt10shared_ptrINS_10_Impl_baseEE
LEHE91:
	movl	164(%esp), %eax
	testl	%eax, %eax
	je	L766
	lock subl	$1, 4(%eax)
	jne	L766
	movl	(%eax), %edx
	movl	%eax, 16(%esp)
	movl	%eax, (%esp)
	call	*8(%edx)
	movl	16(%esp), %eax
	movl	$-1, %edx
	lock xaddl	%edx, 8(%eax)
	cmpl	$1, %edx
	jne	L766
	movl	(%eax), %edx
	movl	%eax, (%esp)
	call	*12(%edx)
	movl	%edi, (%esi,%ebx,4)
	addl	$1, %ebx
	cmpl	$15, %ebx
	jne	L838
	.p2align 4,,7
L1002:
	movl	$1000000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
LEHB92:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
LEHE92:
	leal	72(%esp), %eax
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	movb	$1, 39(%esp)
	mfence
	.p2align 4,,7
L771:
	leal	68(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSt18condition_variable10notify_allEv
	movl	$1000000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
LEHB93:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	84(%esp), %eax
	cmpl	$15, %eax
	jne	L771
	movl	%esi, %ebx
	leal	284(%esp), %ebp
	.p2align 4,,7
L776:
	movl	(%ebx), %eax
	movl	%eax, (%esp)
	call	__ZNSt6thread4joinEv
LEHE93:
	movl	(%ebx), %edi
	testl	%edi, %edi
	je	L772
	movl	$0, 4(%esp)
	movl	(%edi), %eax
	movl	%eax, (%esp)
	call	_pthread_equal
	testl	%eax, %eax
	je	L773
	movl	%edi, (%esp)
	call	__ZdlPv
L772:
	movl	$0, (%ebx)
	addl	$4, %ebx
	cmpl	%ebp, %ebx
	jne	L776
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$LC18, 4(%esp)
	movl	$LC11, (%esp)
	subl	16(%esp), %eax
	sbbl	20(%esp), %edx
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fdivs	LC10
	fstpl	8(%esp)
LEHB94:
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
LEHE94:
	leal	68(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSt18condition_variableD1Ev
	movl	136(%esp), %eax
	testl	%eax, %eax
	je	L778
	leal	128(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L778:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L782
	leal	144(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L782:
	movl	$1, (%esp)
	movl	$0, 232(%esp)
LEHB95:
	call	__Znwj
LEHE95:
	movl	$1, (%esp)
	movl	%eax, 224(%esp)
	movl	$__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E7_E9_M_invokeERKSt9_Any_dataS1_, 236(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE7_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 232(%esp)
	movl	$0, 168(%esp)
LEHB96:
	call	__Znwj
LEHE96:
	movl	%eax, 160(%esp)
	leal	160(%esp), %eax
	movl	$LC19, %ecx
	movl	%eax, (%esp)
	movl	$LC20, %edx
	movl	$LC21, %eax
	movl	%esi, 4(%esp)
	movl	$__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E6_E9_M_invokeERKSt9_Any_dataS1_, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE6_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 168(%esp)
LEHB97:
	call	__ZZ11thread_testvENKUlPKcS0_S0_St8functionIFbO6data_tEES1_IFbRS2_EEE0_clES0_S0_S0_S5_S8_.isra.218
LEHE97:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L790
	leal	160(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%eax
L790:
	movl	232(%esp), %eax
	testl	%eax, %eax
	je	L791
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
L791:
	movl	$1, (%esp)
	movl	$0, 232(%esp)
LEHB98:
	call	__Znwj
LEHE98:
	movl	$1, (%esp)
	movl	%eax, 224(%esp)
	movl	$__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E9_E9_M_invokeERKSt9_Any_dataS1_, 236(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE9_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 232(%esp)
	movl	$0, 168(%esp)
LEHB99:
	call	__Znwj
LEHE99:
	movl	%eax, 160(%esp)
	leal	160(%esp), %eax
	movl	$LC19, %ecx
	movl	%eax, (%esp)
	movl	$LC20, %edx
	movl	$LC22, %eax
	movl	%esi, 4(%esp)
	movl	$__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E8_E9_M_invokeERKSt9_Any_dataS1_, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE8_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 168(%esp)
LEHB100:
	call	__ZZ11thread_testvENKUlPKcS0_S0_St8functionIFbO6data_tEES1_IFbRS2_EEE0_clES0_S0_S0_S5_S8_.isra.218
LEHE100:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L799
	leal	160(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%eax
L799:
	movl	232(%esp), %eax
	testl	%eax, %eax
	je	L800
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
L800:
	movl	$1, (%esp)
	movl	$0, 232(%esp)
LEHB101:
	call	__Znwj
LEHE101:
	movl	$1, (%esp)
	movl	%eax, 224(%esp)
	movl	$__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E11_E9_M_invokeERKSt9_Any_dataS1_, 236(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE11_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 232(%esp)
	movl	$0, 168(%esp)
LEHB102:
	call	__Znwj
LEHE102:
	movl	%eax, 160(%esp)
	leal	160(%esp), %eax
	movl	$LC23, %ecx
	movl	%eax, (%esp)
	movl	$LC24, %edx
	movl	$LC25, %eax
	movl	%esi, 4(%esp)
	movl	$__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E10_E9_M_invokeERKSt9_Any_dataS1_, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE10_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 168(%esp)
LEHB103:
	call	__ZZ11thread_testvENKUlPKcS0_S0_St8functionIFbO6data_tEES1_IFbRS2_EEE0_clES0_S0_S0_S5_S8_.isra.218
LEHE103:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L808
	leal	160(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%eax
L808:
	movl	232(%esp), %eax
	testl	%eax, %eax
	je	L809
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
L809:
	movl	$1, (%esp)
	movl	$0, 232(%esp)
LEHB104:
	call	__Znwj
LEHE104:
	movl	$1, (%esp)
	movl	%eax, 224(%esp)
	movl	$__ZNSt17_Function_handlerIFbR6data_tEZ11thread_testvEUlS1_E13_E9_M_invokeERKSt9_Any_dataS1_, 236(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlR6data_tE13_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 232(%esp)
	movl	$0, 168(%esp)
LEHB105:
	call	__Znwj
LEHE105:
	movl	%eax, 160(%esp)
	leal	160(%esp), %eax
	movl	$LC23, %ecx
	movl	%eax, (%esp)
	movl	$LC24, %edx
	movl	$LC26, %eax
	movl	%esi, 4(%esp)
	movl	$__ZNSt17_Function_handlerIFbO6data_tEZ11thread_testvEUlS1_E12_E9_M_invokeERKSt9_Any_dataS1_, 172(%esp)
	movl	$__ZNSt14_Function_base13_Base_managerIZ11thread_testvEUlO6data_tE12_E10_M_managerERSt9_Any_dataRKS5_St18_Manager_operation, 168(%esp)
LEHB106:
	call	__ZZ11thread_testvENKUlPKcS0_S0_St8functionIFbO6data_tEES1_IFbRS2_EEE0_clES0_S0_S0_S5_S8_.isra.218
LEHE106:
	movl	168(%esp), %eax
	testl	%eax, %eax
	je	L817
	leal	160(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%eax
L817:
	movl	232(%esp), %eax
	testl	%eax, %eax
	je	L729
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
L729:
	addl	$300, %esp
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
L773:
	.cfi_restore_state
	call	__ZSt9terminatev
L852:
	movl	228(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L743
	movl	%edx, (%esp)
	call	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv
L743:
	movl	%ebp, (%esp)
	call	__ZdlPv
L752:
	leal	44(%esp), %eax
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
L753:
	movl	%edi, (%esp)
	call	__ZNSt18condition_variableD1Ev
L754:
	movl	104(%esp), %eax
	testl	%eax, %eax
	je	L736
	leal	96(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L736:
	movl	120(%esp), %eax
	testl	%eax, %eax
	je	L834
	leal	112(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L834:
	movl	%ebx, (%esp)
LEHB107:
	call	__Unwind_Resume
LEHE107:
L851:
	movl	%eax, %ebx
	jmp	L743
L850:
	movl	%eax, %ebx
	jmp	L752
L999:
	movl	%eax, (%esp)
LEHB108:
	call	__ZSt20__throw_system_errori
LEHE108:
L849:
	movl	%eax, %ebx
	jmp	L753
L841:
	movl	%eax, %ebx
	jmp	L754
L848:
	movl	104(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L736
	leal	96(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L736
L847:
	movl	120(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L834
	leal	112(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L834
L846:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L816
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
L816:
	movl	232(%esp), %eax
	testl	%eax, %eax
	je	L834
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
	jmp	L834
L866:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L816
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
	jmp	L816
L865:
	movl	232(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L834
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%edx
	jmp	L834
L845:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L807
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
L807:
	movl	232(%esp), %eax
	testl	%eax, %eax
	je	L834
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
	jmp	L834
L864:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L807
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
	jmp	L807
L863:
	movl	232(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L834
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%edx
	jmp	L834
L844:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L798
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
L798:
	movl	232(%esp), %eax
	testl	%eax, %eax
	je	L834
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
	jmp	L834
L862:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L798
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
	jmp	L798
L861:
	movl	232(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L834
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%edx
	jmp	L834
L843:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L789
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
L789:
	movl	232(%esp), %eax
	testl	%eax, %eax
	je	L834
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%eax
	jmp	L834
L860:
	movl	168(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L789
	leal	160(%esp), %eax
	movl	$3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%eax, (%esp)
	call	*%edx
	jmp	L789
L859:
	movl	232(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L834
	movl	$3, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%esi, (%esp)
	call	*%edx
	jmp	L834
L858:
	movl	164(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L769
	movl	%edx, (%esp)
	call	__ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv
L769:
	movl	%edi, (%esp)
	call	__ZdlPv
L779:
	leal	72(%esp), %eax
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
L780:
	leal	68(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSt18condition_variableD1Ev
L781:
	movl	136(%esp), %eax
	testl	%eax, %eax
	je	L762
	leal	128(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
L762:
	movl	152(%esp), %eax
	testl	%eax, %eax
	je	L834
	leal	144(%esp), %edx
	movl	$3, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
	jmp	L834
L857:
	movl	%eax, %ebx
	jmp	L769
L856:
	movl	%eax, %ebx
	.p2align 4,,7
	jmp	L779
L1001:
	movl	%eax, (%esp)
LEHB109:
	call	__ZSt20__throw_system_errori
LEHE109:
L855:
	movl	%eax, %ebx
	jmp	L780
L842:
	movl	%eax, %ebx
	jmp	L781
L854:
	movl	136(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L762
	leal	128(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L762
L853:
	movl	152(%esp), %edx
	movl	%eax, %ebx
	testl	%edx, %edx
	je	L834
	leal	144(%esp), %ecx
	movl	$3, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%ecx, (%esp)
	call	*%edx
	jmp	L834
	.cfi_endproc
LFE2522:
	.section	.gcc_except_table,"w"
LLSDA2522:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2522-LLSDACSB2522
LLSDACSB2522:
	.uleb128 LEHB74-LFB2522
	.uleb128 LEHE74-LEHB74
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB75-LFB2522
	.uleb128 LEHE75-LEHB75
	.uleb128 L847-LFB2522
	.uleb128 0
	.uleb128 LEHB76-LFB2522
	.uleb128 LEHE76-LEHB76
	.uleb128 L848-LFB2522
	.uleb128 0
	.uleb128 LEHB77-LFB2522
	.uleb128 LEHE77-LEHB77
	.uleb128 L841-LFB2522
	.uleb128 0
	.uleb128 LEHB78-LFB2522
	.uleb128 LEHE78-LEHB78
	.uleb128 L849-LFB2522
	.uleb128 0
	.uleb128 LEHB79-LFB2522
	.uleb128 LEHE79-LEHB79
	.uleb128 L850-LFB2522
	.uleb128 0
	.uleb128 LEHB80-LFB2522
	.uleb128 LEHE80-LEHB80
	.uleb128 L851-LFB2522
	.uleb128 0
	.uleb128 LEHB81-LFB2522
	.uleb128 LEHE81-LEHB81
	.uleb128 L852-LFB2522
	.uleb128 0
	.uleb128 LEHB82-LFB2522
	.uleb128 LEHE82-LEHB82
	.uleb128 L850-LFB2522
	.uleb128 0
	.uleb128 LEHB83-LFB2522
	.uleb128 LEHE83-LEHB83
	.uleb128 L849-LFB2522
	.uleb128 0
	.uleb128 LEHB84-LFB2522
	.uleb128 LEHE84-LEHB84
	.uleb128 L849-LFB2522
	.uleb128 0
	.uleb128 LEHB85-LFB2522
	.uleb128 LEHE85-LEHB85
	.uleb128 L853-LFB2522
	.uleb128 0
	.uleb128 LEHB86-LFB2522
	.uleb128 LEHE86-LEHB86
	.uleb128 L854-LFB2522
	.uleb128 0
	.uleb128 LEHB87-LFB2522
	.uleb128 LEHE87-LEHB87
	.uleb128 L842-LFB2522
	.uleb128 0
	.uleb128 LEHB88-LFB2522
	.uleb128 LEHE88-LEHB88
	.uleb128 L855-LFB2522
	.uleb128 0
	.uleb128 LEHB89-LFB2522
	.uleb128 LEHE89-LEHB89
	.uleb128 L856-LFB2522
	.uleb128 0
	.uleb128 LEHB90-LFB2522
	.uleb128 LEHE90-LEHB90
	.uleb128 L857-LFB2522
	.uleb128 0
	.uleb128 LEHB91-LFB2522
	.uleb128 LEHE91-LEHB91
	.uleb128 L858-LFB2522
	.uleb128 0
	.uleb128 LEHB92-LFB2522
	.uleb128 LEHE92-LEHB92
	.uleb128 L856-LFB2522
	.uleb128 0
	.uleb128 LEHB93-LFB2522
	.uleb128 LEHE93-LEHB93
	.uleb128 L855-LFB2522
	.uleb128 0
	.uleb128 LEHB94-LFB2522
	.uleb128 LEHE94-LEHB94
	.uleb128 L855-LFB2522
	.uleb128 0
	.uleb128 LEHB95-LFB2522
	.uleb128 LEHE95-LEHB95
	.uleb128 L859-LFB2522
	.uleb128 0
	.uleb128 LEHB96-LFB2522
	.uleb128 LEHE96-LEHB96
	.uleb128 L860-LFB2522
	.uleb128 0
	.uleb128 LEHB97-LFB2522
	.uleb128 LEHE97-LEHB97
	.uleb128 L843-LFB2522
	.uleb128 0
	.uleb128 LEHB98-LFB2522
	.uleb128 LEHE98-LEHB98
	.uleb128 L861-LFB2522
	.uleb128 0
	.uleb128 LEHB99-LFB2522
	.uleb128 LEHE99-LEHB99
	.uleb128 L862-LFB2522
	.uleb128 0
	.uleb128 LEHB100-LFB2522
	.uleb128 LEHE100-LEHB100
	.uleb128 L844-LFB2522
	.uleb128 0
	.uleb128 LEHB101-LFB2522
	.uleb128 LEHE101-LEHB101
	.uleb128 L863-LFB2522
	.uleb128 0
	.uleb128 LEHB102-LFB2522
	.uleb128 LEHE102-LEHB102
	.uleb128 L864-LFB2522
	.uleb128 0
	.uleb128 LEHB103-LFB2522
	.uleb128 LEHE103-LEHB103
	.uleb128 L845-LFB2522
	.uleb128 0
	.uleb128 LEHB104-LFB2522
	.uleb128 LEHE104-LEHB104
	.uleb128 L865-LFB2522
	.uleb128 0
	.uleb128 LEHB105-LFB2522
	.uleb128 LEHE105-LEHB105
	.uleb128 L866-LFB2522
	.uleb128 0
	.uleb128 LEHB106-LFB2522
	.uleb128 LEHE106-LEHB106
	.uleb128 L846-LFB2522
	.uleb128 0
	.uleb128 LEHB107-LFB2522
	.uleb128 LEHE107-LEHB107
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB108-LFB2522
	.uleb128 LEHE108-LEHB108
	.uleb128 L849-LFB2522
	.uleb128 0
	.uleb128 LEHB109-LFB2522
	.uleb128 LEHE109-LEHB109
	.uleb128 L855-LFB2522
	.uleb128 0
LLSDACSE2522:
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB2616:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	call	___main
	call	__Z11thread_testv
	xorl	%eax, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2616:
	.section	.text$_ZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EEC1Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EEC1Ev
	.def	__ZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN17lf_pool_allocatorIN8lf_stackI6data_tLj20EE7stack_tELj20EEC1Ev:
LFB2936:
	.cfi_startproc
	movl	4(%esp), %ecx
	xorl	%eax, %eax
	movl	$0, 320(%ecx)
	leal	352(%ecx), %edx
	mfence
	movl	$-1, 324(%ecx)
	mfence
	movl	$0, 348(%ecx)
	mfence
	.p2align 4,,7
L1007:
	movb	$0, 328(%ecx,%eax)
	addl	$1, %eax
	addl	$4, %edx
	mfence
	movl	$0, -4(%edx)
	mfence
	movl	$0, 76(%edx)
	cmpl	$20, %eax
	mfence
	jne	L1007
	rep ret
	.cfi_endproc
LFE2936:
	.section	.text$_ZN8lf_stackI6data_tLj20EE10initializeEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZN8lf_stackI6data_tLj20EE10initializeEv
	.def	__ZN8lf_stackI6data_tLj20EE10initializeEv;	.scl	2;	.type	32;	.endef
__ZN8lf_stackI6data_tLj20EE10initializeEv:
LFB2940:
	.cfi_startproc
	subl	$12, %esp
	.cfi_def_cfa_offset 16
	xorl	%eax, %eax
	movl	16(%esp), %ecx
	xorl	%edx, %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	fildq	(%esp)
	fistpq	512(%ecx)
	mfence
	movl	$0, 520(%ecx)
	mfence
	addl	$12, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE2940:
	.section	.text$_ZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EEC1Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EEC1Ev
	.def	__ZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EEC1Ev;	.scl	2;	.type	32;	.endef
__ZN17lf_pool_allocatorIN8lf_queueI6data_tLj20EE7queue_tELj20EEC1Ev:
LFB2963:
	.cfi_startproc
	movl	4(%esp), %ecx
	xorl	%eax, %eax
	movl	$0, 320(%ecx)
	leal	352(%ecx), %edx
	mfence
	movl	$-1, 324(%ecx)
	mfence
	movl	$0, 348(%ecx)
	mfence
	.p2align 4,,7
L1012:
	movb	$0, 328(%ecx,%eax)
	addl	$1, %eax
	addl	$4, %edx
	mfence
	movl	$0, -4(%edx)
	mfence
	movl	$0, 76(%edx)
	cmpl	$20, %eax
	mfence
	jne	L1012
	rep ret
	.cfi_endproc
LFE2963:
	.section	.text$_ZN8lf_queueI6data_tLj20EE10initializeEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZN8lf_queueI6data_tLj20EE10initializeEv
	.def	__ZN8lf_queueI6data_tLj20EE10initializeEv;	.scl	2;	.type	32;	.endef
__ZN8lf_queueI6data_tLj20EE10initializeEv:
LFB2967:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	$1, %edx
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
	leal	320(%esi), %eax
	lock xaddl	%edx, (%eax)
	cmpl	$19, %edx
	jbe	L1026
	movl	$20, 320(%esi)
	leal	324(%esi), %ebx
	movl	$1, %edx
	mfence
	movl	324(%esi), %eax
	movl	%eax, 32(%esp)
L1016:
	cmpl	$-1, %eax
	je	L1019
L1027:
	addl	$320, %eax
	movl	$1, %ecx
	lock xaddb	%cl, 8(%esi,%eax)
	testb	%cl, %cl
	je	L1020
	movl	32(%esp), %eax
	addl	$320, %eax
	lock subb	$1, 8(%esi,%eax)
	movl	(%ebx), %eax
	addl	$1, %edx
	cmpl	$1000, %edx
	movl	%eax, 32(%esp)
	je	L1017
L1029:
	movl	32(%esp), %eax
	cmpl	$-1, %eax
	jne	L1027
L1019:
	xorl	%eax, %eax
	xorl	%edx, %edx
	xorl	%edi, %edi
L1023:
	xorl	%ebx, %ebx
	xorl	%ecx, %ecx
	movl	%ebx, 28(%esp)
	movl	%ecx, 24(%esp)
	fildq	24(%esp)
	fistpq	(%edi)
	mfence
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fistpq	512(%esi)
	mfence
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
	fildq	24(%esp)
	fistpq	520(%esi)
	mfence
	movl	$0, 528(%esi)
	mfence
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
L1020:
	.cfi_restore_state
	movl	32(%esp), %ecx
	movl	%ecx, %edi
	movl	%ecx, %eax
	sall	$4, %edi
	addl	%esi, %edi
	movl	(%edi), %ebp
	lock cmpxchgl	%ebp, (%ebx)
	movl	%eax, 32(%esp)
	je	L1028
	addl	$320, %ecx
	lock subb	$1, 8(%esi,%ecx)
	addl	$1, %edx
	cmpl	$1000, %edx
	jne	L1029
L1017:
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	(%ebx), %eax
	xorl	%edx, %edx
	movl	%eax, 32(%esp)
	jmp	L1016
	.p2align 4,,7
L1026:
	leal	320(%edx), %eax
	lock addb	$1, 8(%esi,%eax)
	movl	%edx, %edi
	sall	$4, %edi
	addl	%esi, %edi
	movl	$-16843010, (%edi)
	lock addl	$1, 348(%esi)
	leal	352(,%edx,4), %eax
	lock addl	$1, (%esi,%eax)
L1015:
	movl	%edi, %eax
	movl	$0, (%edi)
	cltd
	movl	$0, 4(%edi)
	movl	$0, 8(%edi)
	movl	$0, 12(%edi)
	jmp	L1023
	.p2align 4,,7
L1028:
	sall	$4, %eax
	movl	$-16843010, (%esi,%eax)
	lock addl	$1, 348(%esi)
	movl	32(%esp), %eax
	leal	352(,%eax,4), %eax
	lock addl	$1, (%esi,%eax)
	jmp	L1015
	.cfi_endproc
LFE2967:
	.section	.text$_ZNSt11unique_lockISt5mutexE6unlockEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt11unique_lockISt5mutexE6unlockEv
	.def	__ZNSt11unique_lockISt5mutexE6unlockEv;	.scl	2;	.type	32;	.endef
__ZNSt11unique_lockISt5mutexE6unlockEv:
LFB2979:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	cmpb	$0, 4(%ebx)
	je	L1037
	movl	(%ebx), %eax
	testl	%eax, %eax
	je	L1030
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
	movb	$0, 4(%ebx)
L1030:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
L1037:
	.cfi_restore_state
	movl	$1, (%esp)
	call	__ZSt20__throw_system_errori
	.cfi_endproc
LFE2979:
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEE6_M_runEv;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcSt8functionIFP6data_tvEES4_IFbS6_EEE_clES3_S8_SA_EUliE0_iEEE6_M_runEv:
LFB3634:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3634
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
	je	L1062
	movl	%eax, (%esp)
LEHB110:
	call	_pthread_mutex_lock
LEHE110:
	testl	%eax, %eax
	jne	L1063
	movl	32(%esi), %eax
	leal	32(%esp), %edi
	movb	$1, 36(%esp)
	movl	24(%esi), %ebp
	movl	(%eax), %ebx
	jmp	L1041
	.p2align 4,,7
L1042:
	movl	%edi, 4(%esp)
	movl	%ebp, (%esp)
LEHB111:
	call	__ZNSt18condition_variable4waitERSt11unique_lockISt5mutexE
LEHE111:
L1041:
	movzbl	(%ebx), %eax
	testb	%al, %al
	je	L1042
	cmpb	$0, 36(%esp)
	jne	L1064
L1043:
	movl	40(%esi), %eax
	lock addl	$1, (%eax)
	xorl	%edi, %edi
	xorl	%ebx, %ebx
	movl	$274877907, %ebp
L1044:
	movl	48(%esi), %eax
	movl	(%eax), %eax
	cmpl	$20000, %eax
	jg	L1045
L1067:
	addl	$1, %ebx
	movl	%ebx, %eax
	imull	%ebp
	movl	%ebx, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %ebx
	je	L1065
L1046:
	movl	16(%esi), %eax
	movl	8(%eax), %edx
	testl	%edx, %edx
	je	L1049
	movl	%eax, (%esp)
LEHB112:
	call	*12(%eax)
	testl	%eax, %eax
	movl	%eax, 28(%esp)
	je	L1044
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
	je	L1049
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
	je	L1066
L1050:
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	48(%esi), %eax
	movl	(%eax), %eax
	cmpl	$20000, %eax
	jle	L1067
L1045:
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
L1065:
	.cfi_restore_state
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	jmp	L1046
	.p2align 4,,7
L1066:
	movl	$1000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
LEHE112:
	jmp	L1050
	.p2align 4,,7
L1064:
	movl	32(%esp), %eax
	testl	%eax, %eax
	je	L1043
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
	jmp	L1043
L1049:
	.p2align 4,,5
LEHB113:
	call	__ZSt25__throw_bad_function_callv
L1062:
	movl	$1, (%esp)
	call	__ZSt20__throw_system_errori
LEHE113:
L1053:
	cmpb	$0, 36(%esp)
	movl	%eax, %ebx
	je	L1052
	movl	%edi, (%esp)
	call	__ZNSt11unique_lockISt5mutexE6unlockEv
L1052:
	movl	%ebx, (%esp)
LEHB114:
	call	__Unwind_Resume
L1063:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE114:
	.cfi_endproc
LFE3634:
	.section	.gcc_except_table,"w"
LLSDA3634:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3634-LLSDACSB3634
LLSDACSB3634:
	.uleb128 LEHB110-LFB3634
	.uleb128 LEHE110-LEHB110
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB111-LFB3634
	.uleb128 LEHE111-LEHB111
	.uleb128 L1053-LFB3634
	.uleb128 0
	.uleb128 LEHB112-LFB3634
	.uleb128 LEHE112-LEHB112
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB113-LFB3634
	.uleb128 LEHE113-LEHB113
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB114-LFB3634
	.uleb128 LEHE114-LEHB114
	.uleb128 0
	.uleb128 0
LLSDACSE3634:
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEE6_M_runEv;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE0_iEEE6_M_runEv:
LFB3633:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3633
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
	je	L1091
	movl	%eax, (%esp)
LEHB115:
	call	_pthread_mutex_lock
LEHE115:
	testl	%eax, %eax
	jne	L1092
	movl	32(%ebx), %eax
	leal	16(%esp), %edi
	movb	$1, 20(%esp)
	movl	24(%ebx), %ebp
	movl	(%eax), %esi
	jmp	L1071
	.p2align 4,,7
L1072:
	movl	%edi, 4(%esp)
	movl	%ebp, (%esp)
LEHB116:
	call	__ZNSt18condition_variable4waitERSt11unique_lockISt5mutexE
LEHE116:
L1071:
	movzbl	(%esi), %eax
	testb	%al, %al
	je	L1072
	cmpb	$0, 20(%esp)
	jne	L1093
L1073:
	movl	40(%ebx), %eax
	lock addl	$1, (%eax)
	xorl	%edi, %edi
	xorl	%ebp, %ebp
	movl	$274877907, %esi
	.p2align 4,,7
L1074:
	movl	48(%ebx), %eax
	movl	(%eax), %eax
	cmpl	$20000, %eax
	jg	L1075
L1097:
	addl	$1, %ebp
	movl	%ebp, %eax
	imull	%esi
	movl	%ebp, %eax
	sarl	$31, %eax
	sarl	$6, %edx
	subl	%eax, %edx
	imull	$1000, %edx, %edx
	cmpl	%edx, %ebp
	je	L1094
L1076:
	movl	52(%ebx), %eax
	movl	$1, %edx
	lock xaddl	%edx, (%eax)
	cmpl	$20000, %edx
	jg	L1090
	movl	20(%ebx), %eax
	movl	$0, 16(%esp)
	movl	%edx, 20(%esp)
	movl	8(%eax), %ecx
	testl	%ecx, %ecx
	je	L1095
	leal	16(%esp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
LEHB117:
	call	*12(%eax)
	testb	%al, %al
	je	L1090
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
	je	L1096
L1081:
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	movl	48(%ebx), %eax
	movl	(%eax), %eax
	cmpl	$20000, %eax
	jle	L1097
L1075:
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
L1090:
	.cfi_restore_state
	movl	52(%ebx), %eax
	lock subl	$1, (%eax)
	jmp	L1074
	.p2align 4,,7
L1094:
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
	jmp	L1076
	.p2align 4,,7
L1096:
	movl	$1000, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
LEHE117:
	jmp	L1081
	.p2align 4,,7
L1093:
	movl	16(%esp), %eax
	testl	%eax, %eax
	je	L1073
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
	jmp	L1073
L1095:
	.p2align 4,,5
LEHB118:
	call	__ZSt25__throw_bad_function_callv
L1091:
	movl	$1, (%esp)
	call	__ZSt20__throw_system_errori
LEHE118:
L1084:
	cmpb	$0, 20(%esp)
	movl	%eax, %ebx
	je	L1083
	movl	%edi, (%esp)
	call	__ZNSt11unique_lockISt5mutexE6unlockEv
L1083:
	movl	%ebx, (%esp)
LEHB119:
	call	__Unwind_Resume
L1092:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE119:
	.cfi_endproc
LFE3633:
	.section	.gcc_except_table,"w"
LLSDA3633:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3633-LLSDACSB3633
LLSDACSB3633:
	.uleb128 LEHB115-LFB3633
	.uleb128 LEHE115-LEHB115
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB116-LFB3633
	.uleb128 LEHE116-LEHB116
	.uleb128 L1084-LFB3633
	.uleb128 0
	.uleb128 LEHB117-LFB3633
	.uleb128 LEHE117-LEHB117
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB118-LFB3633
	.uleb128 LEHE118-LEHB118
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB119-LFB3633
	.uleb128 LEHE119-LEHB119
	.uleb128 0
	.uleb128 0
LLSDACSE3633:
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEE6_M_runEv;	.scl	3;	.type	32;	.endef
__ZNSt6thread5_ImplISt12_Bind_simpleIFZZ11thread_testvENKUlPKcS3_S3_St8functionIFbO6data_tEES4_IFbRS5_EEE0_clES3_S3_S3_S8_SB_EUliE1_iEEE6_M_runEv:
LFB3632:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3632
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
	je	L1119
	movl	%eax, (%esp)
LEHB120:
	call	_pthread_mutex_lock
LEHE120:
	testl	%eax, %eax
	jne	L1120
	movl	32(%ebx), %eax
	leal	16(%esp), %edi
	movb	$1, 20(%esp)
	movl	24(%ebx), %ebp
	movl	(%eax), %esi
	jmp	L1101
	.p2align 4,,7
L1102:
	movl	%edi, 4(%esp)
	movl	%ebp, (%esp)
LEHB121:
	call	__ZNSt18condition_variable4waitERSt11unique_lockISt5mutexE
LEHE121:
L1101:
	movzbl	(%esi), %eax
	testb	%al, %al
	je	L1102
	cmpb	$0, 20(%esp)
	jne	L1121
L1103:
	movl	40(%ebx), %eax
	lock addl	$1, (%eax)
	leal	16(%esp), %esi
	jmp	L1104
	.p2align 4,,7
L1106:
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
LEHB122:
	call	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE
L1104:
	movl	48(%ebx), %eax
	movl	(%eax), %eax
	cmpl	$20000, %eax
	jg	L1122
	movl	20(%ebx), %eax
	movl	8(%eax), %edi
	testl	%edi, %edi
	je	L1123
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	*12(%eax)
LEHE122:
	testb	%al, %al
	je	L1106
	movl	48(%ebx), %eax
	lock addl	$1, (%eax)
	jmp	L1106
	.p2align 4,,7
L1122:
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
L1121:
	.cfi_restore_state
	movl	16(%esp), %eax
	testl	%eax, %eax
	je	L1103
	movl	%eax, (%esp)
	call	_pthread_mutex_unlock
	jmp	L1103
L1123:
	.p2align 4,,5
LEHB123:
	call	__ZSt25__throw_bad_function_callv
L1119:
	movl	$1, (%esp)
	call	__ZSt20__throw_system_errori
LEHE123:
L1110:
	cmpb	$0, 20(%esp)
	movl	%eax, %ebx
	je	L1109
	movl	%edi, (%esp)
	call	__ZNSt11unique_lockISt5mutexE6unlockEv
L1109:
	movl	%ebx, (%esp)
LEHB124:
	call	__Unwind_Resume
L1120:
	movl	%eax, (%esp)
	call	__ZSt20__throw_system_errori
LEHE124:
	.cfi_endproc
LFE3632:
	.section	.gcc_except_table,"w"
LLSDA3632:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3632-LLSDACSB3632
LLSDACSB3632:
	.uleb128 LEHB120-LFB3632
	.uleb128 LEHE120-LEHB120
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB121-LFB3632
	.uleb128 LEHE121-LEHB121
	.uleb128 L1110-LFB3632
	.uleb128 0
	.uleb128 LEHB122-LFB3632
	.uleb128 LEHE122-LEHB122
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB123-LFB3632
	.uleb128 LEHE123-LEHB123
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB124-LFB3632
	.uleb128 LEHE124-LEHB124
	.uleb128 0
	.uleb128 0
LLSDACSE3632:
	.text
	.section	.text.startup,"x"
	.p2align 4,,15
	.def	__GLOBAL__sub_I__Z11allocNormalv;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z11allocNormalv:
LFB3691:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZL17s_lfPoolAllocator, (%esp)
	movl	$0, __ZL15s_poolAllocator+160
	movl	$-1, __ZL15s_poolAllocator+164
	movl	$0, __ZL15s_poolAllocator+168
	movl	$20, __ZL15s_poolAllocator+176
	call	__ZN17lf_pool_allocatorI6data_tLj20EEC1Ev
	movl	$__ZL9s_lfStack, (%esp)
	movl	$0, __ZL7s_stack+240
	movl	$-1, __ZL7s_stack+244
	movl	$0, __ZL7s_stack+248
	movl	$20, __ZL7s_stack+256
	movl	$20, __ZL7s_stack+264
	movl	$0, __ZL7s_stack+260
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
LFE3691:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z11allocNormalv
	.section	.text.exit,"x"
	.p2align 4,,15
	.def	__GLOBAL__sub_D__Z11allocNormalv;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_D__Z11allocNormalv:
LFB3692:
	.cfi_startproc
	jmp	__Z41__static_initialization_and_destruction_0ii.part.221
	.cfi_endproc
LFE3692:
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
.lcomm __ZL9s_lfQueue,536,32
.lcomm __ZL7s_queue,272,32
.lcomm __ZL9s_lfStack,528,32
.lcomm __ZL7s_stack,268,32
.lcomm __ZL17s_lfPoolAllocator,352,32
.lcomm __ZL15s_poolAllocator,180,32
	.align 4
LC10:
	.long	1315859240
	.ident	"GCC: (GNU) 4.8.2"
	.def	___real__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt9type_infoeqERKS_;	.scl	2;	.type	32;	.endef
	.def	___real__Znwj;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	__ZNSt11this_thread11__sleep_forENSt6chrono8durationIxSt5ratioILx1ELx1EEEENS1_IxS2_ILx1ELx1000000000EEEE;	.scl	2;	.type	32;	.endef
	.def	_pthread_mutex_lock;	.scl	2;	.type	32;	.endef
	.def	_pthread_mutex_unlock;	.scl	2;	.type	32;	.endef
	.def	__ZSt20__throw_system_errori;	.scl	2;	.type	32;	.endef
	.def	___assert_func;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZSt9terminatev;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	__ZNSt18condition_variableC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6thread15_M_start_threadESt10shared_ptrINS_10_Impl_baseEE;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6chrono3_V212system_clock3nowEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSt18condition_variable10notify_allEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6thread4joinEv;	.scl	2;	.type	32;	.endef
	.def	_pthread_equal;	.scl	2;	.type	32;	.endef
	.def	__ZNSt18condition_variableD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZSt9terminatev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt18condition_variable4waitERSt11unique_lockISt5mutexE;	.scl	2;	.type	32;	.endef
	.def	__ZSt25__throw_bad_function_callv;	.scl	2;	.type	32;	.endef
	.def	___cxa_pure_virtual;	.scl	2;	.type	32;	.endef

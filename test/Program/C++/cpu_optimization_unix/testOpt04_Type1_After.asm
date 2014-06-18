LFE3115:
	.p2align 4,,15
	.globl	__Z21testOpt04_Type1_Afterf
	.def	__Z21testOpt04_Type1_Afterf;	.scl	2;	.type	32;	.endef
__Z21testOpt04_Type1_Afterf:
LFB3116:
	.cfi_startproc
	flds	LC9
	fmuls	4(%esp)
	fadds	LC7
	ret
	.cfi_endproc
LC7:
	.long	1069547520
	.align 4
LC9:
	.long	1062557013
	.align 4

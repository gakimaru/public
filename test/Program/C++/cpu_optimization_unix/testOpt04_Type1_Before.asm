	.text
	.p2align 4,,15
	.globl	__Z22testOpt04_Type1_Beforef
	.def	__Z22testOpt04_Type1_Beforef;	.scl	2;	.type	32;	.endef
__Z22testOpt04_Type1_Beforef:
LFB3115:
	.cfi_startproc
	flds	LC6
	fdivrs	4(%esp)
	fadds	LC7
	ret
	.cfi_endproc
LC6:
	.long	1067030938
	.align 4
LC7:
	.long	1069547520
	.align 4

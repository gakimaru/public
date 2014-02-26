	.file	"constexpr.cpp"
	.section	.text$_ZN14crc_inner_calc7calcStrEjPKc,"x"
	.linkonce discard
	.globl	__ZN14crc_inner_calc7calcStrEjPKc
	.def	__ZN14crc_inner_calc7calcStrEjPKc;	.scl	2;	.type	32;	.endef
__ZN14crc_inner_calc7calcStrEjPKc:
LFB7:
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
	je	L2
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
	jmp	L3
L2:
	movl	8(%ebp), %eax
L3:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE7:
	.section	.text$_Z14calcConstCRC32PKc,"x"
	.linkonce discard
	.globl	__Z14calcConstCRC32PKc
	.def	__Z14calcConstCRC32PKc;	.scl	2;	.type	32;	.endef
__Z14calcConstCRC32PKc:
LFB9:
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
LFE9:
	.text
	.globl	__Z9calcCRC32PKc
	.def	__Z9calcCRC32PKc;	.scl	2;	.type	32;	.endef
__Z9calcCRC32PKc:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$-1, -4(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	jmp	L8
L9:
	movl	-8(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	xorl	-4(%ebp), %eax
	movzbl	%al, %eax
	movl	__ZN14crc_inner_calcL11s_calcTableE(,%eax,4), %eax
	movl	-4(%ebp), %edx
	shrl	$8, %edx
	xorl	%edx, %eax
	movl	%eax, -4(%ebp)
	addl	$1, -8(%ebp)
L8:
	movl	-8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L9
	movl	-4(%ebp), %eax
	notl	%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.globl	__Z9calcCRC32PKcj
	.def	__Z9calcCRC32PKcj;	.scl	2;	.type	32;	.endef
__Z9calcCRC32PKcj:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$-1, -4(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	$0, -12(%ebp)
	jmp	L12
L13:
	movl	-8(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	xorl	-4(%ebp), %eax
	movzbl	%al, %eax
	movl	__ZN14crc_inner_calcL11s_calcTableE(,%eax,4), %eax
	movl	-4(%ebp), %edx
	shrl	$8, %edx
	xorl	%edx, %eax
	movl	%eax, -4(%ebp)
	addl	$1, -12(%ebp)
	addl	$1, -8(%ebp)
L12:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L13
	movl	-4(%ebp), %eax
	notl	%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "constexpr \343\201\253\343\202\210\343\202\213\343\202\263\343\203\263\343\203\221\343\202\244\343\203\253\346\231\202\343\201\256CRC\350\250\210\347\256\227\347\265\220\346\236\234=0x%08x\12\0"
LC1:
	.ascii "1234567890\0"
LC2:
	.ascii "crc2 == 0x261daee5\0"
LC3:
	.ascii "constexpr.cpp\0"
	.align 4
LC4:
	.ascii "constexpr \343\201\253\343\202\210\343\202\213\343\203\251\343\203\263\343\202\277\343\202\244\343\203\240\346\231\202\343\201\256CRC\350\250\210\347\256\227\347\265\220\346\236\234=0x%08x\12\0"
LC5:
	.ascii "crc3 == 0x261daee5\0"
	.align 4
LC6:
	.ascii "\351\200\232\345\270\270\351\226\242\346\225\260\343\201\253\343\202\210\343\202\213\343\203\251\343\203\263\343\202\277\343\202\244\343\203\240\346\231\202\343\201\256CRC\350\250\210\347\256\227\347\265\220\346\236\234=0x%08x\12\0"
	.align 4
LC7:
	.ascii "\343\203\246\343\203\274\343\202\266\343\203\274\345\256\232\347\276\251\343\203\252\343\203\206\343\203\251\343\203\253\343\201\253\343\202\210\343\202\213\343\202\263\343\203\263\343\203\221\343\202\244\343\203\253\346\231\202\343\201\256CRC\350\250\210\347\256\227\347\265\220\346\236\234=0x%08x\12\0"
	.text
	.globl	__Z14test_constexprv
	.def	__Z14test_constexprv;	.scl	2;	.type	32;	.endef
__Z14test_constexprv:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$639479525, -12(%ebp)
	movl	$639479525, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$LC1, (%esp)
	call	__Z14calcConstCRC32PKc
	movl	%eax, -16(%ebp)
	cmpl	$639479525, -16(%ebp)
	je	L16
	movl	$LC2, 12(%esp)
	movl	$__ZZ14test_constexprvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$216, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L16:
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC1, (%esp)
	call	__Z9calcCRC32PKc
	movl	%eax, -20(%ebp)
	cmpl	$639479525, -20(%ebp)
	je	L17
	movl	$LC5, 12(%esp)
	movl	$__ZZ14test_constexprvE19__PRETTY_FUNCTION__, 8(%esp)
	movl	$245, 4(%esp)
	movl	$LC3, (%esp)
	call	___assert_func
L17:
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	$639479525, -24(%ebp)
	movl	$639479525, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	call	___main
	call	__Z14test_constexprv
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.section .rdata,"dr"
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
__ZZ14test_constexprvE19__PRETTY_FUNCTION__:
	.ascii "void test_constexpr()\0"
	.ident	"GCC: (GNU) 4.8.2"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	___assert_func;	.scl	2;	.type	32;	.endef

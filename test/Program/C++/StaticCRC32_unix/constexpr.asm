	.file	"constexpr.cpp"
	.text
	.globl	__Z9calcCRC32PKc
	.def	__Z9calcCRC32PKc;	.scl	2;	.type	32;	.endef
__Z9calcCRC32PKc:
LFB562:
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
	jmp	L2
L4:
	movl	-8(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -8(%ebp)
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	-4(%ebp), %edx
	movl	%edx, -12(%ebp)
	movb	%al, -13(%ebp)
	movzbl	-13(%ebp), %edx
	movl	-12(%ebp), %eax
	crc32b	%dl, %eax
	movl	%eax, -4(%ebp)
L2:
	movl	-8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L4
	movl	-4(%ebp), %eax
	notl	%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE562:
	.globl	__Z9calcCRC32PKcj
	.def	__Z9calcCRC32PKcj;	.scl	2;	.type	32;	.endef
__Z9calcCRC32PKcj:
LFB563:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$32, %esp
	movl	$-1, -4(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	$0, -12(%ebp)
	jmp	L7
L9:
	movl	-8(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -8(%ebp)
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	-4(%ebp), %edx
	movl	%edx, -16(%ebp)
	movb	%al, -17(%ebp)
	movzbl	-17(%ebp), %edx
	movl	-16(%ebp), %eax
	crc32b	%dl, %eax
	movl	%eax, -4(%ebp)
	addl	$1, -12(%ebp)
L7:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L9
	movl	-4(%ebp), %eax
	notl	%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE563:
	.section .rdata,"dr"
	.align 32
__ZN7crc_subL11s_polyTableE:
	.long	0
	.long	-227835133
	.long	-516198153
	.long	324072436
	.long	-946170081
	.long	904991772
	.long	648144872
	.long	-724933397
	.long	-1965467441
	.long	2024987596
	.long	1809983544
	.long	-1719030981
	.long	1296289744
	.long	-1087877933
	.long	-1401372889
	.long	1578318884
	.long	274646895
	.long	-499825556
	.long	-244992104
	.long	51262619
	.long	-675000208
	.long	632279923
	.long	922689671
	.long	-996891772
	.long	-1702387808
	.long	1760304291
	.long	2075979607
	.long	-1982370732
	.long	1562183871
	.long	-1351185476
	.long	-1138329528
	.long	1313733451
	.long	549293790
	.long	-757723683
	.long	-1048117719
	.long	871202090
	.long	-416867903
	.long	357341890
	.long	102525238
	.long	-193467851
	.long	-1436232175
	.long	1477399826
	.long	1264559846
	.long	-1187764763
	.long	1845379342
	.long	-1617575411
	.long	-1933233671
	.long	2125378298
	.long	820201905
	.long	-1031222606
	.long	-774358714
	.long	598981189
	.long	-143008082
	.long	85089709
	.long	373468761
	.long	-467063462
	.long	-1170599554
	.long	1213305469
	.long	1526817161
	.long	-1452612982
	.long	2107672161
	.long	-1882520222
	.long	-1667500394
	.long	1861252501
	.long	1098587580
	.long	-1290756417
	.long	-1606390453
	.long	1378610760
	.long	-2032039261
	.long	1955203488
	.long	1742404180
	.long	-1783531177
	.long	-878557837
	.long	969524848
	.long	714683780
	.long	-655182201
	.long	205050476
	.long	-28094097
	.long	-318528869
	.long	526918040
	.long	1361435347
	.long	-1555146288
	.long	-1340167644
	.long	1114974503
	.long	-1765847604
	.long	1691668175
	.long	2005155131
	.long	-2047885768
	.long	-604208612
	.long	697762079
	.long	986182379
	.long	-928222744
	.long	476452099
	.long	-301099520
	.long	-44210700
	.long	255256311
	.long	1640403810
	.long	-1817374623
	.long	-2130844779
	.long	1922457750
	.long	-1503918979
	.long	1412925310
	.long	1197962378
	.long	-1257441399
	.long	-350237779
	.long	427051182
	.long	170179418
	.long	-129025959
	.long	746937522
	.long	-554770511
	.long	-843174843
	.long	1070968646
	.long	1905808397
	.long	-2081171698
	.long	-1868356358
	.long	1657317369
	.long	-1241332974
	.long	1147748369
	.long	1463399397
	.long	-1521340186
	.long	-79622974
	.long	153784257
	.long	444234805
	.long	-401473738
	.long	1021025245
	.long	-827320098
	.long	-572462294
	.long	797665321
	.long	-2097792136
	.long	1889384571
	.long	1674398607
	.long	-1851340660
	.long	1164749927
	.long	-1224265884
	.long	-1537745776
	.long	1446797203
	.long	137323447
	.long	-96149324
	.long	-384560320
	.long	461344835
	.long	-810158936
	.long	1037989803
	.long	781091935
	.long	-588970148
	.long	-1834419177
	.long	1623424788
	.long	1939049696
	.long	-2114449437
	.long	1429367560
	.long	-1487280117
	.long	-1274471425
	.long	1180866812
	.long	410100952
	.long	-367384613
	.long	-112536529
	.long	186734380
	.long	-538233913
	.long	763408580
	.long	1053836080
	.long	-860110797
	.long	-1572096602
	.long	1344288421
	.long	1131464017
	.long	-1323612590
	.long	1708204729
	.long	-1749376582
	.long	-2065018290
	.long	1988219213
	.long	680717673
	.long	-621187478
	.long	-911630946
	.long	1002577565
	.long	-284657034
	.long	493091189
	.long	238226049
	.long	-61306494
	.long	-1307217207
	.long	1082061258
	.long	1395524158
	.long	-1589280451
	.long	1972364758
	.long	-2015074603
	.long	-1800104671
	.long	1725896226
	.long	952904198
	.long	-894981883
	.long	-638100751
	.long	731699698
	.long	-11092711
	.long	222117402
	.long	510512622
	.long	-335130899
	.long	-1014159676
	.long	837199303
	.long	582374963
	.long	-790768336
	.long	68661723
	.long	-159632680
	.long	-450051796
	.long	390545967
	.long	1230274059
	.long	-1153434360
	.long	-1469116676
	.long	1510247935
	.long	-1899042540
	.long	2091215383
	.long	1878366691
	.long	-1650582816
	.long	-741088853
	.long	565732008
	.long	854102364
	.long	-1065151905
	.long	340358836
	.long	-433916489
	.long	-177076669
	.long	119113024
	.long	1493875044
	.long	-1419691417
	.long	-1204696685
	.long	1247431312
	.long	-1634718085
	.long	1828433272
	.long	2141937292
	.long	-1916740209
	.long	-483350502
	.long	291187481
	.long	34330861
	.long	-262120466
	.long	615137029
	.long	-691946490
	.long	-980332558
	.long	939183345
	.long	1776939221
	.long	-1685949482
	.long	-1999470558
	.long	2058945313
	.long	-1368168502
	.long	1545135305
	.long	1330124605
	.long	-1121741762
	.long	-210866315
	.long	17165430
	.long	307568514
	.long	-532767615
	.long	888469610
	.long	-962626711
	.long	-707819363
	.long	665062302
	.long	2042050490
	.long	-1948470087
	.long	-1735637171
	.long	1793573966
	.long	-1104306011
	.long	1279665062
	.long	1595330642
	.long	-1384295599
	.ident	"GCC: (GNU) 4.8.2"

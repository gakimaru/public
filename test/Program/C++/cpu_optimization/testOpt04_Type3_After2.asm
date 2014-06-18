   774: //ÅyÉ^ÉCÉvÇRÅzç≈ìKâªå„ÇQ
   775: //Å¶ïÇìÆè¨êîì_ââéZÇÃêîÇå∏ÇÁÇ∑ÅiêÆêîââéZÇÃÇ‹Ç‹Ç≈ÇÊÇ¢Ç∆Ç±ÇÎÇÕêÆêîââéZÇ…Ç∑ÇÈÅj
   776: void testOpt04_Type3_After2(dataOpt04_t& data)
   777: {
003B9670 55                   push        ebp  
003B9671 8B EC                mov         ebp,esp  
   778: 	//çáåvíléZèo
   779: 	int sum = 0;
   780: 	for (int i = 0; i < extentof(data.elems); ++i)
003B9673 8B 55 08             mov         edx,dword ptr [data]  
003B9676 0F 57 E4             xorps       xmm4,xmm4  
003B9679 B9 C4 09 00 00       mov         ecx,9C4h  
003B967E 8D 42 10             lea         eax,[edx+10h]  
   781: 	{
   782: 		dataOpt04_t::elem_t* elem_p = &data.elems[i];
   783: 		sum += elem_p->value;
003B9681 66 0F 6E 50 08       movd        xmm2,dword ptr [eax+8]  
003B9686 8D 40 20             lea         eax,[eax+20h]  
003B9689 66 0F 6E 40 E0       movd        xmm0,dword ptr [eax-20h]  
003B968E 66 0F 6E 48 D8       movd        xmm1,dword ptr [eax-28h]  
003B9693 66 0F 6E 58 D0       movd        xmm3,dword ptr [eax-30h]  
003B9698 66 0F 62 D8          punpckldq   xmm3,xmm0  
003B969C 66 0F 62 CA          punpckldq   xmm1,xmm2  
003B96A0 66 0F 62 D9          punpckldq   xmm3,xmm1  
003B96A4 66 0F FE E3          paddd       xmm4,xmm3  
003B96A8 49                   dec         ecx  
003B96A9 75 D6                jne         testOpt04_Type3_After2+11h (03B9681h)  
   784: 	}
   785: 	//äeóvëfÇÃï™ïzî‰ó¶ÇéZèo
   786: 	const float mul = 1.f / static_cast<float>(sum);
003B96AB F3 0F 10 0D AC 8C 3C 00 movss       xmm1,dword ptr ds:[3C8CACh]  
003B96B3 66 0F 6F C4          movdqa      xmm0,xmm4  
003B96B7 66 0F 73 D8 08       psrldq      xmm0,8  
003B96BC B9 E8 03 00 00       mov         ecx,3E8h  
003B96C1 66 0F FE E0          paddd       xmm4,xmm0  
003B96C5 66 0F 6F C4          movdqa      xmm0,xmm4  
003B96C9 66 0F 73 D8 04       psrldq      xmm0,4  
003B96CE 66 0F FE E0          paddd       xmm4,xmm0  
003B96D2 66 0F 7E E0          movd        eax,xmm4  
003B96D6 66 0F 6E C0          movd        xmm0,eax  
003B96DA 8D 42 14             lea         eax,[edx+14h]  
003B96DD 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B96E0 F3 0F 5E C8          divss       xmm1,xmm0  
   787: 	for (int i = 0; i < extentof(data.elems); ++i)
   788: 	{
   789: 		dataOpt04_t::elem_t* elem_p = &data.elems[i];
   790: 		elem_p->ratio = static_cast<float>(elem_p->value) * mul;
003B96E4 66 0F 6E 40 EC       movd        xmm0,dword ptr [eax-14h]  
003B96E9 8D 40 50             lea         eax,[eax+50h]  
003B96EC 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B96EF F3 0F 59 C1          mulss       xmm0,xmm1  
003B96F3 F3 0F 11 40 A0       movss       dword ptr [eax-60h],xmm0  
003B96F8 66 0F 6E 40 A4       movd        xmm0,dword ptr [eax-5Ch]  
003B96FD 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9700 F3 0F 59 C1          mulss       xmm0,xmm1  
003B9704 F3 0F 11 40 A8       movss       dword ptr [eax-58h],xmm0  
003B9709 66 0F 6E 40 AC       movd        xmm0,dword ptr [eax-54h]  
003B970E 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9711 F3 0F 59 C1          mulss       xmm0,xmm1  
003B9715 F3 0F 11 40 B0       movss       dword ptr [eax-50h],xmm0  
003B971A 66 0F 6E 40 B4       movd        xmm0,dword ptr [eax-4Ch]  
003B971F 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9722 F3 0F 59 C1          mulss       xmm0,xmm1  
   787: 	for (int i = 0; i < extentof(data.elems); ++i)
   788: 	{
   789: 		dataOpt04_t::elem_t* elem_p = &data.elems[i];
   790: 		elem_p->ratio = static_cast<float>(elem_p->value) * mul;
003B9726 F3 0F 11 40 B8       movss       dword ptr [eax-48h],xmm0  
003B972B 66 0F 6E 40 BC       movd        xmm0,dword ptr [eax-44h]  
003B9730 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9733 F3 0F 59 C1          mulss       xmm0,xmm1  
003B9737 F3 0F 11 40 C0       movss       dword ptr [eax-40h],xmm0  
003B973C 66 0F 6E 40 C4       movd        xmm0,dword ptr [eax-3Ch]  
003B9741 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9744 F3 0F 59 C1          mulss       xmm0,xmm1  
003B9748 F3 0F 11 40 C8       movss       dword ptr [eax-38h],xmm0  
003B974D 66 0F 6E 40 CC       movd        xmm0,dword ptr [eax-34h]  
003B9752 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9755 F3 0F 59 C1          mulss       xmm0,xmm1  
003B9759 F3 0F 11 40 D0       movss       dword ptr [eax-30h],xmm0  
003B975E 66 0F 6E 40 D4       movd        xmm0,dword ptr [eax-2Ch]  
003B9763 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9766 F3 0F 59 C1          mulss       xmm0,xmm1  
003B976A F3 0F 11 40 D8       movss       dword ptr [eax-28h],xmm0  
003B976F 66 0F 6E 40 DC       movd        xmm0,dword ptr [eax-24h]  
003B9774 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9777 F3 0F 59 C1          mulss       xmm0,xmm1  
003B977B F3 0F 11 40 E0       movss       dword ptr [eax-20h],xmm0  
003B9780 66 0F 6E 40 E4       movd        xmm0,dword ptr [eax-1Ch]  
003B9785 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9788 F3 0F 59 C1          mulss       xmm0,xmm1  
003B978C F3 0F 11 40 E8       movss       dword ptr [eax-18h],xmm0  
003B9791 49                   dec         ecx  
003B9792 0F 85 4C FF FF FF    jne         testOpt04_Type3_After2+74h (03B96E4h)  
   791: 	}
   792: }
003B9798 5D                   pop         ebp  
003B9799 C3                   ret  
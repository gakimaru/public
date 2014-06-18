   735: //【タイプ３】最適化前
   736: //※素直な浮動小数点データ演算、および、除算
   737: void testOpt04_Type3_Before(dataOpt04_t& data)
   738: {
003B97F0 55                   push        ebp  
003B97F1 8B EC                mov         ebp,esp  
   739: 	//合計値算出
   740: 	float sum = 0.f;
003B97F3 8B 55 08             mov         edx,dword ptr [data]  
003B97F6 0F 57 D2             xorps       xmm2,xmm2  
003B97F9 B9 E8 03 00 00       mov         ecx,3E8h  
003B97FE 8D 42 10             lea         eax,[edx+10h]  
   741: 	for (int i = 0; i < extentof(data.elems); ++i)
   742: 	{
   743: 		dataOpt04_t::elem_t* elem_p = &data.elems[i];
   744: 		sum += static_cast<float>(elem_p->value);
003B9801 66 0F 6E 48 F0       movd        xmm1,dword ptr [eax-10h]  
003B9806 66 0F 6E 40 F8       movd        xmm0,dword ptr [eax-8]  
003B980B 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B980E 0F 5B C9             cvtdq2ps    xmm1,xmm1  
003B9811 F3 0F 58 D1          addss       xmm2,xmm1  
003B9815 F3 0F 58 D0          addss       xmm2,xmm0  
003B9819 66 0F 6E 00          movd        xmm0,dword ptr [eax]  
003B981D 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9820 F3 0F 58 D0          addss       xmm2,xmm0  
003B9824 66 0F 6E 40 08       movd        xmm0,dword ptr [eax+8]  
003B9829 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B982C F3 0F 58 D0          addss       xmm2,xmm0  
003B9830 66 0F 6E 40 10       movd        xmm0,dword ptr [eax+10h]  
003B9835 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9838 F3 0F 58 D0          addss       xmm2,xmm0  
003B983C 66 0F 6E 40 18       movd        xmm0,dword ptr [eax+18h]  
003B9841 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9844 F3 0F 58 D0          addss       xmm2,xmm0  
003B9848 66 0F 6E 40 20       movd        xmm0,dword ptr [eax+20h]  
003B984D 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9850 F3 0F 58 D0          addss       xmm2,xmm0  
003B9854 66 0F 6E 40 28       movd        xmm0,dword ptr [eax+28h]  
003B9859 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B985C F3 0F 58 D0          addss       xmm2,xmm0  
003B9860 66 0F 6E 40 30       movd        xmm0,dword ptr [eax+30h]  
003B9865 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9868 F3 0F 58 D0          addss       xmm2,xmm0  
003B986C 66 0F 6E 40 38       movd        xmm0,dword ptr [eax+38h]  
003B9871 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9874 83 C0 50             add         eax,50h  
003B9877 F3 0F 58 D0          addss       xmm2,xmm0  
003B987B 49                   dec         ecx  
003B987C 75 83                jne         testOpt04_Type3_Before+11h (03B9801h)  
   745: 	}
   746: 	//各要素の分布比率を算出
   747: 	for (int i = 0; i < extentof(data.elems); ++i)
003B987E 8D 42 14             lea         eax,[edx+14h]  
003B9881 B9 E8 03 00 00       mov         ecx,3E8h  
003B9886 EB 08                jmp         testOpt04_Type3_Before+0A0h (03B9890h)  
003B9888 8D A4 24 00 00 00 00 lea         esp,[esp]  
003B988F 90                   nop  
   748: 	{
   749: 		dataOpt04_t::elem_t* elem_p = &data.elems[i];
   750: 		elem_p->ratio = static_cast<float>(elem_p->value) / sum;
003B9890 66 0F 6E 40 EC       movd        xmm0,dword ptr [eax-14h]  
003B9895 8D 40 50             lea         eax,[eax+50h]  
   748: 	{
   749: 		dataOpt04_t::elem_t* elem_p = &data.elems[i];
   750: 		elem_p->ratio = static_cast<float>(elem_p->value) / sum;
003B9898 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B989B F3 0F 5E C2          divss       xmm0,xmm2  
003B989F F3 0F 11 40 A0       movss       dword ptr [eax-60h],xmm0  
003B98A4 66 0F 6E 40 A4       movd        xmm0,dword ptr [eax-5Ch]  
003B98A9 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B98AC F3 0F 5E C2          divss       xmm0,xmm2  
003B98B0 F3 0F 11 40 A8       movss       dword ptr [eax-58h],xmm0  
003B98B5 66 0F 6E 40 AC       movd        xmm0,dword ptr [eax-54h]  
003B98BA 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B98BD F3 0F 5E C2          divss       xmm0,xmm2  
003B98C1 F3 0F 11 40 B0       movss       dword ptr [eax-50h],xmm0  
003B98C6 66 0F 6E 40 B4       movd        xmm0,dword ptr [eax-4Ch]  
003B98CB 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B98CE F3 0F 5E C2          divss       xmm0,xmm2  
003B98D2 F3 0F 11 40 B8       movss       dword ptr [eax-48h],xmm0  
003B98D7 66 0F 6E 40 BC       movd        xmm0,dword ptr [eax-44h]  
003B98DC 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B98DF F3 0F 5E C2          divss       xmm0,xmm2  
003B98E3 F3 0F 11 40 C0       movss       dword ptr [eax-40h],xmm0  
003B98E8 66 0F 6E 40 C4       movd        xmm0,dword ptr [eax-3Ch]  
003B98ED 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B98F0 F3 0F 5E C2          divss       xmm0,xmm2  
003B98F4 F3 0F 11 40 C8       movss       dword ptr [eax-38h],xmm0  
003B98F9 66 0F 6E 40 CC       movd        xmm0,dword ptr [eax-34h]  
003B98FE 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9901 F3 0F 5E C2          divss       xmm0,xmm2  
003B9905 F3 0F 11 40 D0       movss       dword ptr [eax-30h],xmm0  
003B990A 66 0F 6E 40 D4       movd        xmm0,dword ptr [eax-2Ch]  
003B990F 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9912 F3 0F 5E C2          divss       xmm0,xmm2  
003B9916 F3 0F 11 40 D8       movss       dword ptr [eax-28h],xmm0  
003B991B 66 0F 6E 40 DC       movd        xmm0,dword ptr [eax-24h]  
003B9920 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9923 F3 0F 5E C2          divss       xmm0,xmm2  
003B9927 F3 0F 11 40 E0       movss       dword ptr [eax-20h],xmm0  
003B992C 66 0F 6E 40 E4       movd        xmm0,dword ptr [eax-1Ch]  
003B9931 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9934 F3 0F 5E C2          divss       xmm0,xmm2  
003B9938 F3 0F 11 40 E8       movss       dword ptr [eax-18h],xmm0  
003B993D 49                   dec         ecx  
003B993E 0F 85 4C FF FF FF    jne         testOpt04_Type3_Before+0A0h (03B9890h)  
   751: 	}
   752: }
003B9944 5D                   pop         ebp  
003B9945 C3                   ret  

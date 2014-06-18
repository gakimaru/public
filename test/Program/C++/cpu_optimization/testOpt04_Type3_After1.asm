   754: //ÅyÉ^ÉCÉvÇRÅzç≈ìKâªå„ÇP
   755: //Å¶èúéZÇèÊéZÇ…ïœçX
   756: void testOpt04_Type3_After1(dataOpt04_t& data)
   757: {
003B94B0 55                   push        ebp  
003B94B1 8B EC                mov         ebp,esp  
   758: 	//çáåvíléZèo
   759: 	float sum = 0.f;
003B94B3 8B 55 08             mov         edx,dword ptr [data]  
003B94B6 0F 57 C0             xorps       xmm0,xmm0  
003B94B9 B9 E8 03 00 00       mov         ecx,3E8h  
003B94BE 8D 42 10             lea         eax,[edx+10h]  
   760: 	for (int i = 0; i < extentof(data.elems); ++i)
   761: 	{
   762: 		dataOpt04_t::elem_t* elem_p = &data.elems[i];
   763: 		sum += static_cast<float>(elem_p->value);
003B94C1 66 0F 6E 48 F0       movd        xmm1,dword ptr [eax-10h]  
003B94C6 0F 5B C9             cvtdq2ps    xmm1,xmm1  
003B94C9 F3 0F 58 C8          addss       xmm1,xmm0  
003B94CD 66 0F 6E 40 F8       movd        xmm0,dword ptr [eax-8]  
003B94D2 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B94D5 F3 0F 58 C8          addss       xmm1,xmm0  
003B94D9 66 0F 6E 00          movd        xmm0,dword ptr [eax]  
003B94DD 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B94E0 F3 0F 58 C8          addss       xmm1,xmm0  
003B94E4 66 0F 6E 40 08       movd        xmm0,dword ptr [eax+8]  
   760: 	for (int i = 0; i < extentof(data.elems); ++i)
   761: 	{
   762: 		dataOpt04_t::elem_t* elem_p = &data.elems[i];
   763: 		sum += static_cast<float>(elem_p->value);
003B94E9 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B94EC F3 0F 58 C8          addss       xmm1,xmm0  
003B94F0 66 0F 6E 40 10       movd        xmm0,dword ptr [eax+10h]  
003B94F5 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B94F8 F3 0F 58 C8          addss       xmm1,xmm0  
003B94FC 66 0F 6E 40 18       movd        xmm0,dword ptr [eax+18h]  
003B9501 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9504 F3 0F 58 C8          addss       xmm1,xmm0  
003B9508 66 0F 6E 40 20       movd        xmm0,dword ptr [eax+20h]  
003B950D 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9510 F3 0F 58 C8          addss       xmm1,xmm0  
003B9514 66 0F 6E 40 28       movd        xmm0,dword ptr [eax+28h]  
003B9519 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B951C F3 0F 58 C8          addss       xmm1,xmm0  
003B9520 66 0F 6E 40 30       movd        xmm0,dword ptr [eax+30h]  
003B9525 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9528 F3 0F 58 C8          addss       xmm1,xmm0  
003B952C 66 0F 6E 40 38       movd        xmm0,dword ptr [eax+38h]  
003B9531 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9534 83 C0 50             add         eax,50h  
003B9537 F3 0F 58 C8          addss       xmm1,xmm0  
003B953B 0F 28 C1             movaps      xmm0,xmm1  
003B953E 49                   dec         ecx  
003B953F 75 80                jne         testOpt04_Type3_After1+11h (03B94C1h)  
   764: 	}
   765: 	//äeóvëfÇÃï™ïzî‰ó¶ÇéZèo
   766: 	const float mul = 1.f / sum;
003B9541 F3 0F 10 0D AC 8C 3C 00 movss       xmm1,dword ptr ds:[3C8CACh]  
003B9549 8D 42 14             lea         eax,[edx+14h]  
003B954C F3 0F 5E C8          divss       xmm1,xmm0  
003B9550 B9 E8 03 00 00       mov         ecx,3E8h  
   767: 	for (int i = 0; i < extentof(data.elems); ++i)
   768: 	{
   769: 		dataOpt04_t::elem_t* elem_p = &data.elems[i];
   770: 		elem_p->ratio = static_cast<float>(elem_p->value) * mul;
003B9555 66 0F 6E 40 EC       movd        xmm0,dword ptr [eax-14h]  
003B955A 8D 40 50             lea         eax,[eax+50h]  
003B955D 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9560 F3 0F 59 C1          mulss       xmm0,xmm1  
003B9564 F3 0F 11 40 A0       movss       dword ptr [eax-60h],xmm0  
003B9569 66 0F 6E 40 A4       movd        xmm0,dword ptr [eax-5Ch]  
003B956E 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9571 F3 0F 59 C1          mulss       xmm0,xmm1  
003B9575 F3 0F 11 40 A8       movss       dword ptr [eax-58h],xmm0  
003B957A 66 0F 6E 40 AC       movd        xmm0,dword ptr [eax-54h]  
003B957F 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9582 F3 0F 59 C1          mulss       xmm0,xmm1  
003B9586 F3 0F 11 40 B0       movss       dword ptr [eax-50h],xmm0  
003B958B 66 0F 6E 40 B4       movd        xmm0,dword ptr [eax-4Ch]  
003B9590 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B9593 F3 0F 59 C1          mulss       xmm0,xmm1  
003B9597 F3 0F 11 40 B8       movss       dword ptr [eax-48h],xmm0  
003B959C 66 0F 6E 40 BC       movd        xmm0,dword ptr [eax-44h]  
003B95A1 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B95A4 F3 0F 59 C1          mulss       xmm0,xmm1  
003B95A8 F3 0F 11 40 C0       movss       dword ptr [eax-40h],xmm0  
003B95AD 66 0F 6E 40 C4       movd        xmm0,dword ptr [eax-3Ch]  
003B95B2 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B95B5 F3 0F 59 C1          mulss       xmm0,xmm1  
003B95B9 F3 0F 11 40 C8       movss       dword ptr [eax-38h],xmm0  
003B95BE 66 0F 6E 40 CC       movd        xmm0,dword ptr [eax-34h]  
003B95C3 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B95C6 F3 0F 59 C1          mulss       xmm0,xmm1  
003B95CA F3 0F 11 40 D0       movss       dword ptr [eax-30h],xmm0  
003B95CF 66 0F 6E 40 D4       movd        xmm0,dword ptr [eax-2Ch]  
003B95D4 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B95D7 F3 0F 59 C1          mulss       xmm0,xmm1  
003B95DB F3 0F 11 40 D8       movss       dword ptr [eax-28h],xmm0  
003B95E0 66 0F 6E 40 DC       movd        xmm0,dword ptr [eax-24h]  
003B95E5 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B95E8 F3 0F 59 C1          mulss       xmm0,xmm1  
003B95EC F3 0F 11 40 E0       movss       dword ptr [eax-20h],xmm0  
003B95F1 66 0F 6E 40 E4       movd        xmm0,dword ptr [eax-1Ch]  
003B95F6 0F 5B C0             cvtdq2ps    xmm0,xmm0  
003B95F9 F3 0F 59 C1          mulss       xmm0,xmm1  
003B95FD F3 0F 11 40 E8       movss       dword ptr [eax-18h],xmm0  
003B9602 49                   dec         ecx  
003B9603 0F 85 4C FF FF FF    jne         testOpt04_Type3_After1+0A5h (03B9555h)  
   771: 	}
   772: }
003B9609 5D                   pop         ebp  
003B960A C3                   ret  

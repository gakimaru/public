   124: //【タイプ１】最適化後１
   125: //※分布集計だけポインタ計算に変更
   126: int testOpt02_Type1_After1(dataOpt02_t& data)
   127: {
00354680 55                   push        ebp  
00354681 8B EC                mov         ebp,esp  
00354683 83 EC 5C             sub         esp,5Ch  
00354686 A1 10 80 36 00       mov         eax,dword ptr ds:[00368010h]  
0035468B 33 C5                xor         eax,ebp  
0035468D 89 45 FC             mov         dword ptr [ebp-4],eax  
00354690 8B 4D 08             mov         ecx,dword ptr [data]  
   128: 	//分布集計用構造体
   129: 	struct dist_t
   130: 	{
   131: 		int value;
   132: 		int count;
   133: 	};
   134: 	//分布集計用変数初期化
   135: 	dist_t dist[dataOpt02_t::elem_t::VALUE_RANGE];
   136: 	for (int value = 0; value < dataOpt02_t::elem_t::VALUE_RANGE; ++value)
00354693 33 C0                xor         eax,eax  
00354695 EB 09                jmp         testOpt02_Type1_After1+20h (03546A0h)  
00354697 8D A4 24 00 00 00 00 lea         esp,[esp]  
0035469E 8B FF                mov         edi,edi  
   137: 	{
   138: 		dist[value].value = value;
003546A0 89 44 C5 A4          mov         dword ptr dist[eax*8],eax  
   139: 		dist[value].count = 0;
003546A4 C7 44 C5 A8 00 00 00 00 mov         dword ptr [ebp+eax*8-58h],0  
003546AC 40                   inc         eax  
003546AD 83 F8 0B             cmp         eax,0Bh  
003546B0 72 EE                jb          testOpt02_Type1_After1+20h (03546A0h)  
   140: 	}
   141: 	//分布集計
   142: 	{
   143: 		const dataOpt02_t::elem_t* end = data.elems + extentof(data.elems);
003546B2 8D 91 40 9C 00 00    lea         edx,[ecx+9C40h]  
   144: 		for (const dataOpt02_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
003546B8 3B CA                cmp         ecx,edx  
003546BA 73 11                jae         testOpt02_Type1_After1+4Dh (03546CDh)  
003546BC 8D 64 24 00          lea         esp,[esp]  
   145: 			++dist[elem_p->value].count;
003546C0 8B 01                mov         eax,dword ptr [ecx]  
003546C2 83 C1 04             add         ecx,4  
003546C5 FF 44 C5 A8          inc         dword ptr [ebp+eax*8-58h]  
003546C9 3B CA                cmp         ecx,edx  
003546CB 72 F3                jb          testOpt02_Type1_After1+40h (03546C0h)  
   146: 	}
   147: 	//最大分布取得
   148: 	const dist_t* top_dist_p = &dist[0];
   149: 	for (std::size_t i = 1; i < dataOpt02_t::elem_t::VALUE_RANGE; ++i)
   150: 	{
   151: 		if (top_dist_p->count < dist[i].count)
003546CD 8B 45 A8             mov         eax,dword ptr [ebp-58h]  
003546D0 8D 55 A4             lea         edx,[dist]  
003546D3 3B 45 B0             cmp         eax,dword ptr [ebp-50h]  
003546D6 8D 4D AC             lea         ecx,[ebp-54h]  
003546D9 56                   push        esi  
003546DA 0F 4D CA             cmovge      ecx,edx  
003546DD 8D 75 EC             lea         esi,[ebp-14h]  
003546E0 8D 55 B4             lea         edx,[ebp-4Ch]  
003546E3 8B 41 04             mov         eax,dword ptr [ecx+4]  
003546E6 3B 45 B8             cmp         eax,dword ptr [ebp-48h]  
003546E9 0F 4D D1             cmovge      edx,ecx  
003546EC 8D 4D BC             lea         ecx,[ebp-44h]  
003546EF 8B 42 04             mov         eax,dword ptr [edx+4]  
003546F2 3B 45 C0             cmp         eax,dword ptr [ebp-40h]  
003546F5 0F 4D CA             cmovge      ecx,edx  
003546F8 8D 55 C4             lea         edx,[ebp-3Ch]  
003546FB 8B 41 04             mov         eax,dword ptr [ecx+4]  
003546FE 3B 45 C8             cmp         eax,dword ptr [ebp-38h]  
00354701 0F 4D D1             cmovge      edx,ecx  
00354704 8D 4D CC             lea         ecx,[ebp-34h]  
00354707 8B 42 04             mov         eax,dword ptr [edx+4]  
0035470A 3B 45 D0             cmp         eax,dword ptr [ebp-30h]  
0035470D 0F 4D CA             cmovge      ecx,edx  
00354710 8D 55 D4             lea         edx,[ebp-2Ch]  
00354713 8B 41 04             mov         eax,dword ptr [ecx+4]  
00354716 3B 45 D8             cmp         eax,dword ptr [ebp-28h]  
00354719 0F 4D D1             cmovge      edx,ecx  
0035471C 8D 4D DC             lea         ecx,[ebp-24h]  
0035471F 8B 42 04             mov         eax,dword ptr [edx+4]  
00354722 3B 45 E0             cmp         eax,dword ptr [ebp-20h]  
00354725 0F 4D CA             cmovge      ecx,edx  
00354728 8D 55 E4             lea         edx,[ebp-1Ch]  
0035472B 8B 41 04             mov         eax,dword ptr [ecx+4]  
0035472E 3B 45 E8             cmp         eax,dword ptr [ebp-18h]  
00354731 0F 4D D1             cmovge      edx,ecx  
00354734 8D 4D F4             lea         ecx,[ebp-0Ch]  
00354737 8B 42 04             mov         eax,dword ptr [edx+4]  
0035473A 3B 45 F0             cmp         eax,dword ptr [ebp-10h]  
0035473D 0F 4D F2             cmovge      esi,edx  
00354740 8B 46 04             mov         eax,dword ptr [esi+4]  
00354743 3B 45 F8             cmp         eax,dword ptr [ebp-8]  
00354746 0F 4D CE             cmovge      ecx,esi  
00354749 5E                   pop         esi  
   152: 			top_dist_p = &dist[i];
   153: 	}
   154: 	return (top_dist_p->count << 16) | top_dist_p->value;
0035474A 8B 41 04             mov         eax,dword ptr [ecx+4]  
0035474D C1 E0 10             shl         eax,10h  
00354750 0B 01                or          eax,dword ptr [ecx]  
   155: }
00354752 8B 4D FC             mov         ecx,dword ptr [ebp-4]  
00354755 33 CD                xor         ecx,ebp  
00354757 E8 86 86 00 00       call        __security_check_cookie (035CDE2h)  
0035475C 8B E5                mov         esp,ebp  
0035475E 5D                   pop         ebp  
0035475F C3                   ret  

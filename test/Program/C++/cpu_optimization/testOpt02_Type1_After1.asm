   101: //【タイプ１】最適化後１
   102: //※分布集計だけポインタ計算に変更
   103: int testOpt02_Type1_After1(dataOpt02_t& data)
   104: {
01023100 55                   push        ebp  
01023101 8B EC                mov         ebp,esp  
01023103 83 EC 5C             sub         esp,5Ch  
01023106 A1 10 70 02 01       mov         eax,dword ptr ds:[01027010h]  
0102310B 33 C5                xor         eax,ebp  
0102310D 89 45 FC             mov         dword ptr [ebp-4],eax  
01023110 8B 4D 08             mov         ecx,dword ptr [data]  
   105: 	//分布集計用構造体
   106: 	struct dist_t
   107: 	{
   108: 		int value;
   109: 		int count;
   110: 	};
   111: 	//分布集計用変数初期化
   112: 	dist_t dist[dataOpt02_t::elem_t::VALUE_RANGE];
   113: 	for (int value = 0; value < dataOpt02_t::elem_t::VALUE_RANGE; ++value)
01023113 33 C0                xor         eax,eax  
01023115 EB 09                jmp         testOpt02_Type1_After1+20h (01023120h)  
01023117 8D A4 24 00 00 00 00 lea         esp,[esp]  
0102311E 8B FF                mov         edi,edi  
   114: 	{
   115: 		dist[value].value = value;
01023120 89 44 C5 A4          mov         dword ptr dist[eax*8],eax  
   116: 		dist[value].count = 0;
01023124 C7 44 C5 A8 00 00 00 00 mov         dword ptr [ebp+eax*8-58h],0  
   116: 		dist[value].count = 0;
0102312C 40                   inc         eax  
0102312D 83 F8 0B             cmp         eax,0Bh  
01023130 72 EE                jb          testOpt02_Type1_After1+20h (01023120h)  
   117: 	}
   118: 	//分布集計
   119: 	{
   120: 		const dataOpt02_t::elem_t* end = data.elems + extentof(data.elems);
01023132 8D 91 40 9C 00 00    lea         edx,[ecx+9C40h]  
   121: 		for (const dataOpt02_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
01023138 3B CA                cmp         ecx,edx  
0102313A 73 11                jae         testOpt02_Type1_After1+4Dh (0102314Dh)  
0102313C 8D 64 24 00          lea         esp,[esp]  
   122: 			++dist[elem_p->value].count;
01023140 8B 01                mov         eax,dword ptr [ecx]  
01023142 83 C1 04             add         ecx,4  
01023145 FF 44 C5 A8          inc         dword ptr [ebp+eax*8-58h]  
01023149 3B CA                cmp         ecx,edx  
0102314B 72 F3                jb          testOpt02_Type1_After1+40h (01023140h)  
   123: 	}
   124: 	//最大分布取得
   125: 	const dist_t* top_dist_p = &dist[0];
   126: 	for (std::size_t i = 1; i < dataOpt02_t::elem_t::VALUE_RANGE; ++i)
   127: 	{
   128: 		if (top_dist_p->count < dist[i].count)
0102314D 8B 45 A8             mov         eax,dword ptr [ebp-58h]  
01023150 8D 55 A4             lea         edx,[dist]  
01023153 3B 45 B0             cmp         eax,dword ptr [ebp-50h]  
01023156 8D 4D AC             lea         ecx,[ebp-54h]  
01023159 56                   push        esi  
0102315A 0F 4D CA             cmovge      ecx,edx  
0102315D 8D 75 EC             lea         esi,[ebp-14h]  
01023160 8D 55 B4             lea         edx,[ebp-4Ch]  
01023163 8B 41 04             mov         eax,dword ptr [ecx+4]  
01023166 3B 45 B8             cmp         eax,dword ptr [ebp-48h]  
01023169 0F 4D D1             cmovge      edx,ecx  
0102316C 8D 4D BC             lea         ecx,[ebp-44h]  
0102316F 8B 42 04             mov         eax,dword ptr [edx+4]  
01023172 3B 45 C0             cmp         eax,dword ptr [ebp-40h]  
01023175 0F 4D CA             cmovge      ecx,edx  
01023178 8D 55 C4             lea         edx,[ebp-3Ch]  
0102317B 8B 41 04             mov         eax,dword ptr [ecx+4]  
0102317E 3B 45 C8             cmp         eax,dword ptr [ebp-38h]  
01023181 0F 4D D1             cmovge      edx,ecx  
01023184 8D 4D CC             lea         ecx,[ebp-34h]  
01023187 8B 42 04             mov         eax,dword ptr [edx+4]  
0102318A 3B 45 D0             cmp         eax,dword ptr [ebp-30h]  
0102318D 0F 4D CA             cmovge      ecx,edx  
01023190 8D 55 D4             lea         edx,[ebp-2Ch]  
01023193 8B 41 04             mov         eax,dword ptr [ecx+4]  
01023196 3B 45 D8             cmp         eax,dword ptr [ebp-28h]  
01023199 0F 4D D1             cmovge      edx,ecx  
0102319C 8D 4D DC             lea         ecx,[ebp-24h]  
0102319F 8B 42 04             mov         eax,dword ptr [edx+4]  
010231A2 3B 45 E0             cmp         eax,dword ptr [ebp-20h]  
010231A5 0F 4D CA             cmovge      ecx,edx  
010231A8 8D 55 E4             lea         edx,[ebp-1Ch]  
010231AB 8B 41 04             mov         eax,dword ptr [ecx+4]  
010231AE 3B 45 E8             cmp         eax,dword ptr [ebp-18h]  
010231B1 0F 4D D1             cmovge      edx,ecx  
010231B4 8D 4D F4             lea         ecx,[ebp-0Ch]  
010231B7 8B 42 04             mov         eax,dword ptr [edx+4]  
010231BA 3B 45 F0             cmp         eax,dword ptr [ebp-10h]  
010231BD 0F 4D F2             cmovge      esi,edx  
010231C0 8B 46 04             mov         eax,dword ptr [esi+4]  
010231C3 3B 45 F8             cmp         eax,dword ptr [ebp-8]  
010231C6 0F 4D CE             cmovge      ecx,esi  
010231C9 5E                   pop         esi  
   129: 			top_dist_p = &dist[i];
   130: 	}
   131: 	return (top_dist_p->count << 16) | top_dist_p->value;
010231CA 8B 41 04             mov         eax,dword ptr [ecx+4]  
010231CD C1 E0 10             shl         eax,10h  
010231D0 0B 01                or          eax,dword ptr [ecx]  
   132: }
010231D2 8B 4D FC             mov         ecx,dword ptr [ebp-4]  
010231D5 33 CD                xor         ecx,ebp  
010231D7 E8 CA 07 00 00       call        __security_check_cookie (010239A6h)  
010231DC 8B E5                mov         esp,ebp  
010231DE 5D                   pop         ebp  
010231DF C3                   ret  

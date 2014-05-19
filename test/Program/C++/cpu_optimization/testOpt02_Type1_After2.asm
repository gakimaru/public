   134: //【タイプ１】最適化後２
   135: //※徹底的にポインタ計算に変更
   136: int testOpt02_Type1_After2(dataOpt02_t& data)
   137: {
010231E0 55                   push        ebp  
010231E1 8B EC                mov         ebp,esp  
010231E3 83 EC 5C             sub         esp,5Ch  
010231E6 A1 10 70 02 01       mov         eax,dword ptr ds:[01027010h]  
010231EB 33 C5                xor         eax,ebp  
010231ED 89 45 FC             mov         dword ptr [ebp-4],eax  
010231F0 8B 4D 08             mov         ecx,dword ptr [data]  
   138: 	//分布集計用構造体
   139: 	struct dist_t
   140: 	{
   141: 		int value;
   142: 		int count;
   143: 	};
   144: 	//分布集計用変数初期化
   145: 	dist_t dist[dataOpt02_t::elem_t::VALUE_RANGE];
   146: 	const dist_t* dist_end = dist + dataOpt02_t::elem_t::VALUE_RANGE;
   147: 	{
   148: 		int value = 0;
   149: 		for (dist_t* dist_p = dist; dist_p < dist_end; ++dist_p)
010231F3 8D 45 A4             lea         eax,[dist]  
010231F6 33 D2                xor         edx,edx  
010231F8 56                   push        esi  
010231F9 8D A4 24 00 00 00 00 lea         esp,[esp]  
   150: 		{
   151: 			dist_p->value = value++;
01023200 89 10                mov         dword ptr [eax],edx  
01023202 8D 75 FC             lea         esi,[ebp-4]  
   152: 			dist_p->count = 0;
01023205 C7 40 04 00 00 00 00 mov         dword ptr [eax+4],0  
0102320C 42                   inc         edx  
0102320D 83 C0 08             add         eax,8  
01023210 3B C6                cmp         eax,esi  
01023212 72 EC                jb          testOpt02_Type1_After2+20h (01023200h)  
   153: 		}
   154: 	}
   155: 	//分布集計
   156: 	{
   157: 		const dataOpt02_t::elem_t* end = data.elems + extentof(data.elems);
01023214 8D 91 40 9C 00 00    lea         edx,[ecx+9C40h]  
0102321A 5E                   pop         esi  
   158: 		for (const dataOpt02_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
0102321B 3B CA                cmp         ecx,edx  
0102321D 73 0E                jae         testOpt02_Type1_After2+4Dh (0102322Dh)  
0102321F 90                   nop  
   159: 			++dist[elem_p->value].count;
01023220 8B 01                mov         eax,dword ptr [ecx]  
01023222 83 C1 04             add         ecx,4  
01023225 FF 44 C5 A8          inc         dword ptr [ebp+eax*8-58h]  
01023229 3B CA                cmp         ecx,edx  
0102322B 72 F3                jb          testOpt02_Type1_After2+40h (01023220h)  
   160: 	}
   161: 	//最大分布取得
   162: 	const dist_t* top_dist_p = dist;
0102322D 8D 4D A4             lea         ecx,[dist]  
   163: 	{
   164: 		for (const dist_t* dist_p = top_dist_p + 1; dist_p < dist_end; ++dist_p)
01023230 8D 55 AC             lea         edx,[ebp-54h]  
   165: 		{
   166: 			if (top_dist_p->count < dist_p->count)
01023233 8B 41 04             mov         eax,dword ptr [ecx+4]  
01023236 3B 42 04             cmp         eax,dword ptr [edx+4]  
01023239 8D 45 FC             lea         eax,[ebp-4]  
0102323C 0F 4C CA             cmovl       ecx,edx  
0102323F 83 C2 08             add         edx,8  
01023242 3B D0                cmp         edx,eax  
01023244 72 ED                jb          testOpt02_Type1_After2+53h (01023233h)  
   167: 				top_dist_p = dist_p;
   168: 		}
   169: 	}
   170: 	return (top_dist_p->count << 16) | top_dist_p->value;
01023246 8B 41 04             mov         eax,dword ptr [ecx+4]  
01023249 C1 E0 10             shl         eax,10h  
0102324C 0B 01                or          eax,dword ptr [ecx]  
   171: }
0102324E 8B 4D FC             mov         ecx,dword ptr [ebp-4]  
01023251 33 CD                xor         ecx,ebp  
   171: }
01023253 E8 4E 07 00 00       call        __security_check_cookie (010239A6h)  
01023258 8B E5                mov         esp,ebp  
0102325A 5D                   pop         ebp  
0102325B C3                   ret  

    71: //【タイプ１】最適化前
    72: //※ループ処理で配列要素を直接指定
    73: int testOpt02_Type1_Before(dataOpt02_t& data)
    74: {
01023260 55                   push        ebp  
01023261 8B EC                mov         ebp,esp  
01023263 83 EC 5C             sub         esp,5Ch  
01023266 A1 10 70 02 01       mov         eax,dword ptr ds:[01027010h]  
0102326B 33 C5                xor         eax,ebp  
0102326D 89 45 FC             mov         dword ptr [ebp-4],eax  
01023270 8B 4D 08             mov         ecx,dword ptr [data]  
    75: 	//分布集計用構造体
    76: 	struct dist_t
    77: 	{
    78: 		int value;
    79: 		int count;
    80: 	};
    81: 	//分布集計用変数初期化
    82: 	dist_t dist[dataOpt02_t::elem_t::VALUE_RANGE];
    83: 	for (int value = 0; value < dataOpt02_t::elem_t::VALUE_RANGE; ++value)
01023273 33 C0                xor         eax,eax  
01023275 EB 09                jmp         testOpt02_Type1_Before+20h (01023280h)  
01023277 8D A4 24 00 00 00 00 lea         esp,[esp]  
0102327E 8B FF                mov         edi,edi  
    84: 	{
    85: 		dist[value].value = value;
01023280 89 44 C5 A4          mov         dword ptr dist[eax*8],eax  
    86: 		dist[value].count = 0;
01023284 C7 44 C5 A8 00 00 00 00 mov         dword ptr [ebp+eax*8-58h],0  
    86: 		dist[value].count = 0;
0102328C 40                   inc         eax  
0102328D 83 F8 0B             cmp         eax,0Bh  
01023290 72 EE                jb          testOpt02_Type1_Before+20h (01023280h)  
    87: 	}
    88: 	//分布集計
    89: 	for (std::size_t i = 0; i < extentof(data.elems); ++i)
01023292 8D 41 08             lea         eax,[ecx+8]  
01023295 BA D0 07 00 00       mov         edx,7D0h  
0102329A 8D 9B 00 00 00 00    lea         ebx,[ebx]  
    90: 		++dist[data.elems[i].value].count;
010232A0 8B 48 F8             mov         ecx,dword ptr [eax-8]  
010232A3 8D 40 14             lea         eax,[eax+14h]  
010232A6 FF 44 CD A8          inc         dword ptr [ebp+ecx*8-58h]  
010232AA 8B 48 E8             mov         ecx,dword ptr [eax-18h]  
010232AD FF 44 CD A8          inc         dword ptr [ebp+ecx*8-58h]  
010232B1 8B 48 EC             mov         ecx,dword ptr [eax-14h]  
010232B4 FF 44 CD A8          inc         dword ptr [ebp+ecx*8-58h]  
010232B8 8B 48 F0             mov         ecx,dword ptr [eax-10h]  
010232BB FF 44 CD A8          inc         dword ptr [ebp+ecx*8-58h]  
010232BF 8B 48 F4             mov         ecx,dword ptr [eax-0Ch]  
010232C2 FF 44 CD A8          inc         dword ptr [ebp+ecx*8-58h]  
010232C6 4A                   dec         edx  
010232C7 75 D7                jne         testOpt02_Type1_Before+40h (010232A0h)  
    91: 	//最大分布取得
    92: 	const dist_t* top_dist_p = &dist[0];
    93: 	for (std::size_t i = 1; i < dataOpt02_t::elem_t::VALUE_RANGE; ++i)
    94: 	{
    95: 		if (top_dist_p->count < dist[i].count)
010232C9 8B 45 A8             mov         eax,dword ptr [ebp-58h]  
010232CC 8D 55 A4             lea         edx,[dist]  
010232CF 3B 45 B0             cmp         eax,dword ptr [ebp-50h]  
010232D2 8D 4D AC             lea         ecx,[ebp-54h]  
010232D5 56                   push        esi  
010232D6 0F 4D CA             cmovge      ecx,edx  
010232D9 8D 75 EC             lea         esi,[ebp-14h]  
010232DC 8D 55 B4             lea         edx,[ebp-4Ch]  
010232DF 8B 41 04             mov         eax,dword ptr [ecx+4]  
010232E2 3B 45 B8             cmp         eax,dword ptr [ebp-48h]  
010232E5 0F 4D D1             cmovge      edx,ecx  
010232E8 8D 4D BC             lea         ecx,[ebp-44h]  
010232EB 8B 42 04             mov         eax,dword ptr [edx+4]  
010232EE 3B 45 C0             cmp         eax,dword ptr [ebp-40h]  
010232F1 0F 4D CA             cmovge      ecx,edx  
010232F4 8D 55 C4             lea         edx,[ebp-3Ch]  
010232F7 8B 41 04             mov         eax,dword ptr [ecx+4]  
010232FA 3B 45 C8             cmp         eax,dword ptr [ebp-38h]  
010232FD 0F 4D D1             cmovge      edx,ecx  
01023300 8D 4D CC             lea         ecx,[ebp-34h]  
01023303 8B 42 04             mov         eax,dword ptr [edx+4]  
01023306 3B 45 D0             cmp         eax,dword ptr [ebp-30h]  
01023309 0F 4D CA             cmovge      ecx,edx  
0102330C 8D 55 D4             lea         edx,[ebp-2Ch]  
0102330F 8B 41 04             mov         eax,dword ptr [ecx+4]  
01023312 3B 45 D8             cmp         eax,dword ptr [ebp-28h]  
01023315 0F 4D D1             cmovge      edx,ecx  
01023318 8D 4D DC             lea         ecx,[ebp-24h]  
0102331B 8B 42 04             mov         eax,dword ptr [edx+4]  
0102331E 3B 45 E0             cmp         eax,dword ptr [ebp-20h]  
01023321 0F 4D CA             cmovge      ecx,edx  
01023324 8D 55 E4             lea         edx,[ebp-1Ch]  
01023327 8B 41 04             mov         eax,dword ptr [ecx+4]  
0102332A 3B 45 E8             cmp         eax,dword ptr [ebp-18h]  
0102332D 0F 4D D1             cmovge      edx,ecx  
01023330 8D 4D F4             lea         ecx,[ebp-0Ch]  
01023333 8B 42 04             mov         eax,dword ptr [edx+4]  
01023336 3B 45 F0             cmp         eax,dword ptr [ebp-10h]  
01023339 0F 4D F2             cmovge      esi,edx  
0102333C 8B 46 04             mov         eax,dword ptr [esi+4]  
0102333F 3B 45 F8             cmp         eax,dword ptr [ebp-8]  
01023342 0F 4D CE             cmovge      ecx,esi  
01023345 5E                   pop         esi  
    96: 			top_dist_p = &dist[i];
    97: 	}
    98: 	return (top_dist_p->count << 16) | top_dist_p->value;
01023346 8B 41 04             mov         eax,dword ptr [ecx+4]  
01023349 C1 E0 10             shl         eax,10h  
0102334C 0B 01                or          eax,dword ptr [ecx]  
    99: }
0102334E 8B 4D FC             mov         ecx,dword ptr [ebp-4]  
01023351 33 CD                xor         ecx,ebp  
01023353 E8 4E 06 00 00       call        __security_check_cookie (010239A6h)  
01023358 8B E5                mov         esp,ebp  
0102335A 5D                   pop         ebp  
0102335B C3                   ret  

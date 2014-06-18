    94: //【タイプ１】最適化前
    95: //※ループ処理で配列要素を直接指定
    96: int testOpt02_Type1_Before(dataOpt02_t& data)
    97: {
00354840 55                   push        ebp  
00354841 8B EC                mov         ebp,esp  
00354843 83 EC 5C             sub         esp,5Ch  
00354846 A1 10 80 36 00       mov         eax,dword ptr ds:[00368010h]  
0035484B 33 C5                xor         eax,ebp  
0035484D 89 45 FC             mov         dword ptr [ebp-4],eax  
00354850 8B 4D 08             mov         ecx,dword ptr [data]  
    98: 	//分布集計用構造体
    99: 	struct dist_t
   100: 	{
   101: 		int value;
   102: 		int count;
   103: 	};
   104: 	//分布集計用変数初期化
   105: 	dist_t dist[dataOpt02_t::elem_t::VALUE_RANGE];
   106: 	for (int value = 0; value < dataOpt02_t::elem_t::VALUE_RANGE; ++value)
00354853 33 C0                xor         eax,eax  
00354855 EB 09                jmp         testOpt02_Type1_Before+20h (0354860h)  
00354857 8D A4 24 00 00 00 00 lea         esp,[esp]  
0035485E 8B FF                mov         edi,edi  
   107: 	{
   108: 		dist[value].value = value;
00354860 89 44 C5 A4          mov         dword ptr dist[eax*8],eax  
   109: 		dist[value].count = 0;
00354864 C7 44 C5 A8 00 00 00 00 mov         dword ptr [ebp+eax*8-58h],0  
0035486C 40                   inc         eax  
0035486D 83 F8 0B             cmp         eax,0Bh  
00354870 72 EE                jb          testOpt02_Type1_Before+20h (0354860h)  
   110: 	}
   111: 	//分布集計
   112: 	for (std::size_t i = 0; i < extentof(data.elems); ++i)
00354872 8D 41 08             lea         eax,[ecx+8]  
   110: 	}
   111: 	//分布集計
   112: 	for (std::size_t i = 0; i < extentof(data.elems); ++i)
00354875 BA D0 07 00 00       mov         edx,7D0h  
0035487A 8D 9B 00 00 00 00    lea         ebx,[ebx]  
   113: 		++dist[data.elems[i].value].count;
00354880 8B 48 F8             mov         ecx,dword ptr [eax-8]  
00354883 8D 40 14             lea         eax,[eax+14h]  
00354886 FF 44 CD A8          inc         dword ptr [ebp+ecx*8-58h]  
0035488A 8B 48 E8             mov         ecx,dword ptr [eax-18h]  
0035488D FF 44 CD A8          inc         dword ptr [ebp+ecx*8-58h]  
00354891 8B 48 EC             mov         ecx,dword ptr [eax-14h]  
00354894 FF 44 CD A8          inc         dword ptr [ebp+ecx*8-58h]  
00354898 8B 48 F0             mov         ecx,dword ptr [eax-10h]  
0035489B FF 44 CD A8          inc         dword ptr [ebp+ecx*8-58h]  
0035489F 8B 48 F4             mov         ecx,dword ptr [eax-0Ch]  
003548A2 FF 44 CD A8          inc         dword ptr [ebp+ecx*8-58h]  
003548A6 4A                   dec         edx  
003548A7 75 D7                jne         testOpt02_Type1_Before+40h (0354880h)  
   114: 	//最大分布取得
   115: 	const dist_t* top_dist_p = &dist[0];
   116: 	for (std::size_t i = 1; i < dataOpt02_t::elem_t::VALUE_RANGE; ++i)
   117: 	{
   118: 		if (top_dist_p->count < dist[i].count)
003548A9 8B 45 A8             mov         eax,dword ptr [ebp-58h]  
003548AC 8D 55 A4             lea         edx,[dist]  
003548AF 3B 45 B0             cmp         eax,dword ptr [ebp-50h]  
003548B2 8D 4D AC             lea         ecx,[ebp-54h]  
003548B5 56                   push        esi  
003548B6 0F 4D CA             cmovge      ecx,edx  
003548B9 8D 75 EC             lea         esi,[ebp-14h]  
003548BC 8D 55 B4             lea         edx,[ebp-4Ch]  
003548BF 8B 41 04             mov         eax,dword ptr [ecx+4]  
003548C2 3B 45 B8             cmp         eax,dword ptr [ebp-48h]  
003548C5 0F 4D D1             cmovge      edx,ecx  
003548C8 8D 4D BC             lea         ecx,[ebp-44h]  
003548CB 8B 42 04             mov         eax,dword ptr [edx+4]  
003548CE 3B 45 C0             cmp         eax,dword ptr [ebp-40h]  
003548D1 0F 4D CA             cmovge      ecx,edx  
003548D4 8D 55 C4             lea         edx,[ebp-3Ch]  
003548D7 8B 41 04             mov         eax,dword ptr [ecx+4]  
003548DA 3B 45 C8             cmp         eax,dword ptr [ebp-38h]  
003548DD 0F 4D D1             cmovge      edx,ecx  
003548E0 8D 4D CC             lea         ecx,[ebp-34h]  
003548E3 8B 42 04             mov         eax,dword ptr [edx+4]  
003548E6 3B 45 D0             cmp         eax,dword ptr [ebp-30h]  
003548E9 0F 4D CA             cmovge      ecx,edx  
003548EC 8D 55 D4             lea         edx,[ebp-2Ch]  
003548EF 8B 41 04             mov         eax,dword ptr [ecx+4]  
003548F2 3B 45 D8             cmp         eax,dword ptr [ebp-28h]  
003548F5 0F 4D D1             cmovge      edx,ecx  
003548F8 8D 4D DC             lea         ecx,[ebp-24h]  
003548FB 8B 42 04             mov         eax,dword ptr [edx+4]  
003548FE 3B 45 E0             cmp         eax,dword ptr [ebp-20h]  
00354901 0F 4D CA             cmovge      ecx,edx  
00354904 8D 55 E4             lea         edx,[ebp-1Ch]  
00354907 8B 41 04             mov         eax,dword ptr [ecx+4]  
0035490A 3B 45 E8             cmp         eax,dword ptr [ebp-18h]  
0035490D 0F 4D D1             cmovge      edx,ecx  
00354910 8D 4D F4             lea         ecx,[ebp-0Ch]  
00354913 8B 42 04             mov         eax,dword ptr [edx+4]  
00354916 3B 45 F0             cmp         eax,dword ptr [ebp-10h]  
00354919 0F 4D F2             cmovge      esi,edx  
0035491C 8B 46 04             mov         eax,dword ptr [esi+4]  
0035491F 3B 45 F8             cmp         eax,dword ptr [ebp-8]  
00354922 0F 4D CE             cmovge      ecx,esi  
00354925 5E                   pop         esi  
   119: 			top_dist_p = &dist[i];
   120: 	}
   121: 	return (top_dist_p->count << 16) | top_dist_p->value;
00354926 8B 41 04             mov         eax,dword ptr [ecx+4]  
00354929 C1 E0 10             shl         eax,10h  
0035492C 0B 01                or          eax,dword ptr [ecx]  
   122: }
0035492E 8B 4D FC             mov         ecx,dword ptr [ebp-4]  
00354931 33 CD                xor         ecx,ebp  
00354933 E8 AA 84 00 00       call        __security_check_cookie (035CDE2h)  
00354938 8B E5                mov         esp,ebp  
0035493A 5D                   pop         ebp  
0035493B C3                   ret  

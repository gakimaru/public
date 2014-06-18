   197: //【タイプ１】最適化後３
   198: //※徹底的にポインタ計算に変更
   199: int testOpt02_Type1_After3(dataOpt02_t& data)
   200: {
000F4830 55                   push        ebp  
000F4831 8B EC                mov         ebp,esp  
000F4833 83 EC 5C             sub         esp,5Ch  
000F4836 A1 10 80 10 00       mov         eax,dword ptr ds:[00108010h]  
000F483B 33 C5                xor         eax,ebp  
000F483D 89 45 FC             mov         dword ptr [ebp-4],eax  
000F4840 8B 4D 08             mov         ecx,dword ptr [data]  
   201: 	//分布集計用構造体
   202: 	struct dist_t
   203: 	{
   204: 		int value;
   205: 		int count;
   206: 	};
   207: 	//分布集計用変数初期化
   208: 	dist_t dist[dataOpt02_t::elem_t::VALUE_RANGE];
   209: 	for (int value = 0; value < dataOpt02_t::elem_t::VALUE_RANGE; ++value)
000F4843 33 C0                xor         eax,eax  
000F4845 EB 09                jmp         testOpt02_Type1_After3+20h (0F4850h)  
000F4847 8D A4 24 00 00 00 00 lea         esp,[esp]  
000F484E 8B FF                mov         edi,edi  
   210: 	{
   211: 		dist_t* dist_p = &dist[value];
   212: 		dist_p->value = value;
000F4850 89 44 C5 A4          mov         dword ptr dist[eax*8],eax  
   213: 		dist_p->count = 0;
000F4854 C7 44 C5 A8 00 00 00 00 mov         dword ptr [ebp+eax*8-58h],0  
000F485C 40                   inc         eax  
000F485D 83 F8 0B             cmp         eax,0Bh  
000F4860 72 EE                jb          testOpt02_Type1_After3+20h (0F4850h)  
   214: 	}
   215: 	//分布集計
   216: 	for (std::size_t i = 0; i < extentof(data.elems); ++i)
000F4862 8D 41 08             lea         eax,[ecx+8]  
   214: 	}
   215: 	//分布集計
   216: 	for (std::size_t i = 0; i < extentof(data.elems); ++i)
000F4865 BA D0 07 00 00       mov         edx,7D0h  
000F486A 8D 9B 00 00 00 00    lea         ebx,[ebx]  
   217: 	{
   218: 		const dataOpt02_t::elem_t* elem_p = &data.elems[i];
   219: 		++dist[elem_p->value].count;
000F4870 8B 48 F8             mov         ecx,dword ptr [eax-8]  
000F4873 8D 40 14             lea         eax,[eax+14h]  
000F4876 FF 44 CD A8          inc         dword ptr [ebp+ecx*8-58h]  
000F487A 8B 48 E8             mov         ecx,dword ptr [eax-18h]  
000F487D FF 44 CD A8          inc         dword ptr [ebp+ecx*8-58h]  
000F4881 8B 48 EC             mov         ecx,dword ptr [eax-14h]  
000F4884 FF 44 CD A8          inc         dword ptr [ebp+ecx*8-58h]  
000F4888 8B 48 F0             mov         ecx,dword ptr [eax-10h]  
000F488B FF 44 CD A8          inc         dword ptr [ebp+ecx*8-58h]  
000F488F 8B 48 F4             mov         ecx,dword ptr [eax-0Ch]  
000F4892 FF 44 CD A8          inc         dword ptr [ebp+ecx*8-58h]  
000F4896 4A                   dec         edx  
000F4897 75 D7                jne         testOpt02_Type1_After3+40h (0F4870h)  
   220: 	}
   221: 	//最大分布取得
   222: 	const dist_t* top_dist_p = &dist[0];
   223: 	for (std::size_t i = 1; i < dataOpt02_t::elem_t::VALUE_RANGE; ++i)
   224: 	{
   225: 		dist_t* dist_p = &dist[i];
   226: 		if (top_dist_p->count < dist_p->count)
000F4899 8B 45 A8             mov         eax,dword ptr [ebp-58h]  
000F489C 8D 55 A4             lea         edx,[dist]  
000F489F 3B 45 B0             cmp         eax,dword ptr [ebp-50h]  
000F48A2 8D 4D AC             lea         ecx,[ebp-54h]  
000F48A5 56                   push        esi  
000F48A6 0F 4D CA             cmovge      ecx,edx  
000F48A9 8D 75 EC             lea         esi,[ebp-14h]  
000F48AC 8D 55 B4             lea         edx,[ebp-4Ch]  
000F48AF 8B 41 04             mov         eax,dword ptr [ecx+4]  
000F48B2 3B 45 B8             cmp         eax,dword ptr [ebp-48h]  
000F48B5 0F 4D D1             cmovge      edx,ecx  
000F48B8 8D 4D BC             lea         ecx,[ebp-44h]  
000F48BB 8B 42 04             mov         eax,dword ptr [edx+4]  
000F48BE 3B 45 C0             cmp         eax,dword ptr [ebp-40h]  
000F48C1 0F 4D CA             cmovge      ecx,edx  
000F48C4 8D 55 C4             lea         edx,[ebp-3Ch]  
000F48C7 8B 41 04             mov         eax,dword ptr [ecx+4]  
000F48CA 3B 45 C8             cmp         eax,dword ptr [ebp-38h]  
000F48CD 0F 4D D1             cmovge      edx,ecx  
000F48D0 8D 4D CC             lea         ecx,[ebp-34h]  
000F48D3 8B 42 04             mov         eax,dword ptr [edx+4]  
000F48D6 3B 45 D0             cmp         eax,dword ptr [ebp-30h]  
000F48D9 0F 4D CA             cmovge      ecx,edx  
000F48DC 8D 55 D4             lea         edx,[ebp-2Ch]  
000F48DF 8B 41 04             mov         eax,dword ptr [ecx+4]  
000F48E2 3B 45 D8             cmp         eax,dword ptr [ebp-28h]  
000F48E5 0F 4D D1             cmovge      edx,ecx  
000F48E8 8D 4D DC             lea         ecx,[ebp-24h]  
000F48EB 8B 42 04             mov         eax,dword ptr [edx+4]  
000F48EE 3B 45 E0             cmp         eax,dword ptr [ebp-20h]  
000F48F1 0F 4D CA             cmovge      ecx,edx  
000F48F4 8D 55 E4             lea         edx,[ebp-1Ch]  
000F48F7 8B 41 04             mov         eax,dword ptr [ecx+4]  
000F48FA 3B 45 E8             cmp         eax,dword ptr [ebp-18h]  
000F48FD 0F 4D D1             cmovge      edx,ecx  
000F4900 8D 4D F4             lea         ecx,[ebp-0Ch]  
000F4903 8B 42 04             mov         eax,dword ptr [edx+4]  
000F4906 3B 45 F0             cmp         eax,dword ptr [ebp-10h]  
000F4909 0F 4D F2             cmovge      esi,edx  
000F490C 8B 46 04             mov         eax,dword ptr [esi+4]  
000F490F 3B 45 F8             cmp         eax,dword ptr [ebp-8]  
000F4912 0F 4D CE             cmovge      ecx,esi  
000F4915 5E                   pop         esi  
   227: 			top_dist_p = dist_p;
   228: 	}
   229: 	return (top_dist_p->count << 16) | top_dist_p->value;
000F4916 8B 41 04             mov         eax,dword ptr [ecx+4]  
000F4919 C1 E0 10             shl         eax,10h  
000F491C 0B 01                or          eax,dword ptr [ecx]  
   230: }
000F491E 8B 4D FC             mov         ecx,dword ptr [ebp-4]  
000F4921 33 CD                xor         ecx,ebp  
000F4923 E8 EA 85 00 00       call        __security_check_cookie (0FCF12h)  
000F4928 8B E5                mov         esp,ebp  
000F492A 5D                   pop         ebp  
000F492B C3                   ret  

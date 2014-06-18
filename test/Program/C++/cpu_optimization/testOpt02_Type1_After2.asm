   157: //【タイプ１】最適化後２
   158: //※徹底的にポインタ計算に変更
   159: int testOpt02_Type1_After2(dataOpt02_t& data)
   160: {
00FB47A0 55                   push        ebp  
00FB47A1 8B EC                mov         ebp,esp  
00FB47A3 83 EC 5C             sub         esp,5Ch  
00FB47A6 A1 10 80 FC 00       mov         eax,dword ptr ds:[00FC8010h]  
00FB47AB 33 C5                xor         eax,ebp  
00FB47AD 89 45 FC             mov         dword ptr [ebp-4],eax  
00FB47B0 8B 4D 08             mov         ecx,dword ptr [data]  
   161: 	//分布集計用構造体
   162: 	struct dist_t
   163: 	{
   164: 		int value;
   165: 		int count;
   166: 	};
   167: 	//分布集計用変数初期化
   168: 	dist_t dist[dataOpt02_t::elem_t::VALUE_RANGE];
   169: 	{
   170: 		int value = 0;
   171: 		const dist_t* dist_end = dist + dataOpt02_t::elem_t::VALUE_RANGE;
   172: 		for (dist_t* dist_p = dist; dist_p < dist_end; ++dist_p)
00FB47B3 8D 45 A4             lea         eax,[dist]  
00FB47B6 33 D2                xor         edx,edx  
00FB47B8 56                   push        esi  
00FB47B9 8D A4 24 00 00 00 00 lea         esp,[esp]  
   173: 		{
   174: 			dist_p->value = value++;
00FB47C0 89 10                mov         dword ptr [eax],edx  
00FB47C2 8D 75 FC             lea         esi,[ebp-4]  
   175: 			dist_p->count = 0;
00FB47C5 C7 40 04 00 00 00 00 mov         dword ptr [eax+4],0  
00FB47CC 42                   inc         edx  
00FB47CD 83 C0 08             add         eax,8  
00FB47D0 3B C6                cmp         eax,esi  
00FB47D2 72 EC                jb          testOpt02_Type1_After2+20h (0FB47C0h)  
   176: 		}
   177: 	}
   178: 	//分布集計
   179: 	{
   180: 		const dataOpt02_t::elem_t* elem_end = data.elems + extentof(data.elems);
00FB47D4 8D 91 40 9C 00 00    lea         edx,[ecx+9C40h]  
00FB47DA 5E                   pop         esi  
   181: 		for (const dataOpt02_t::elem_t* elem_p = data.elems; elem_p < elem_end; ++elem_p)
00FB47DB 3B CA                cmp         ecx,edx  
00FB47DD 73 0E                jae         testOpt02_Type1_After2+4Dh (0FB47EDh)  
00FB47DF 90                   nop  
   182: 			++dist[elem_p->value].count;
00FB47E0 8B 01                mov         eax,dword ptr [ecx]  
00FB47E2 83 C1 04             add         ecx,4  
00FB47E5 FF 44 C5 A8          inc         dword ptr [ebp+eax*8-58h]  
00FB47E9 3B CA                cmp         ecx,edx  
00FB47EB 72 F3                jb          testOpt02_Type1_After2+40h (0FB47E0h)  
   183: 	}
   184: 	//最大分布取得
   185: 	const dist_t* top_dist_p = dist;
00FB47ED 8D 4D A4             lea         ecx,[dist]  
   186: 	{
   187: 		const dist_t* dist_end = dist + dataOpt02_t::elem_t::VALUE_RANGE;
   188: 		for (const dist_t* dist_p = top_dist_p + 1; dist_p < dist_end; ++dist_p)
00FB47F0 8D 55 AC             lea         edx,[ebp-54h]  
   189: 		{
   190: 			if (top_dist_p->count < dist_p->count)
00FB47F3 8B 41 04             mov         eax,dword ptr [ecx+4]  
00FB47F6 3B 42 04             cmp         eax,dword ptr [edx+4]  
00FB47F9 8D 45 FC             lea         eax,[ebp-4]  
00FB47FC 0F 4C CA             cmovl       ecx,edx  
00FB47FF 83 C2 08             add         edx,8  
00FB4802 3B D0                cmp         edx,eax  
00FB4804 72 ED                jb          testOpt02_Type1_After2+53h (0FB47F3h)  
   191: 				top_dist_p = dist_p;
   192: 		}
   193: 	}
   194: 	return (top_dist_p->count << 16) | top_dist_p->value;
00FB4806 8B 41 04             mov         eax,dword ptr [ecx+4]  
00FB4809 C1 E0 10             shl         eax,10h  
00FB480C 0B 01                or          eax,dword ptr [ecx]  
   195: }
00FB480E 8B 4D FC             mov         ecx,dword ptr [ebp-4]  
00FB4811 33 CD                xor         ecx,ebp  
00FB4813 E8 CA 85 00 00       call        __security_check_cookie (0FBCDE2h)  
00FB4818 8B E5                mov         esp,ebp  
00FB481A 5D                   pop         ebp  
00FB481B C3                   ret  

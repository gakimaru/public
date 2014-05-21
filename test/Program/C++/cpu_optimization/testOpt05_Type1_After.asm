   407: //【タイプ１】最適化後
   408: #include <iostream>
   409: #include <exception>
   410: //※乗算のレイテンシを5と仮定し、シフト演算を1加算を1として、計5未満ならシフト演算と加算に展開した特殊化を適用する
   411: template<int N> inline int intMulOpt(const int val){ return val * N; }
   412: template<>      inline int intMulOpt<0>(const int val){ return 0; }
   413: template<>      inline int intMulOpt<1>(const int val){ return val; }
   414: template<>      inline int intMulOpt<2>(const int val){ return val << 1; }
   415: template<>      inline int intMulOpt<3>(const int val){ return (val << 1) + val; }
   416: template<>      inline int intMulOpt<4>(const int val){ return val << 2; }
   417: template<>      inline int intMulOpt<5>(const int val){ return (val << 2) + val; }
   418: template<>      inline int intMulOpt<6>(const int val){ return (val << 2) + (val << 1); }
   419: template<>      inline int intMulOpt<7>(const int val){ return (val << 2) + (val << 1) + val; }
   420: template<>      inline int intMulOpt<8>(const int val){ return val << 3; }
   421: template<>      inline int intMulOpt<9>(const int val){ return (val << 3) + val; }
   422: template<>      inline int intMulOpt<10>(const int val){ return (val << 3) + (val << 1); }
   423: template<>      inline int intMulOpt<11>(const int val){ return (val << 3) + (val << 1) + val; }
   424: template<>      inline int intMulOpt<12>(const int val){ return (val << 3) + (val << 2); }
   425: template<>      inline int intMulOpt<13>(const int val){ return (val << 3) + (val << 2) + val; }
   426: template<>      inline int intMulOpt<16>(const int val){ return val << 4; }
   427: template<>      inline int intMulOpt<20>(const int val){ return (val << 4) + (val << 2); }
   428: template<>      inline int intMulOpt<24>(const int val){ return (val << 4) + (val << 3); }
   429: template<>      inline int intMulOpt<32>(const int val){ return val << 5; }
   430: template<>      inline int intMulOpt<64>(const int val){ return val << 6; }
   431: template<>      inline int intMulOpt<128>(const int val){ return val << 7; }
   432: template<>      inline int intMulOpt<256>(const int val){ return val << 8; }
   433: template<>      inline int intMulOpt<512>(const int val){ return val << 9; }
   434: template<>      inline int intMulOpt<1024>(const int val){ return val << 10; }
   435: //template<int N> inline int intDivOpt(const int val){ return (static_cast<long long>(val) * (0xffffffffll / static_cast<long long>(N)) + 32) >> 32; }//逆数を定数化して整数演算
   436: //template<int N> constexpr int getReciprocalDivisor(){ return static_cast<int>(0xffffffffll / static_cast<long long>(N)); }
   437: //template<int N> inline int intDivOpt(const int val)//逆数を定数化して整数演算（インラインアセンブラ版）
   438: //{
   439: //	//return (static_cast<long long>(val) * (0xffffffffll / static_cast<long long>(N)) + 32) >> 32;
   440: //	const int rec = getReciprocalDivisor<N>();
   441: //	__asm
   442: //	{
   443: //		mov     eax, rec	//eax ← rec
   444: //		mul     val			//edx:eax ← eax * val
   445: //		add     eax, 32		//eax ← eax + 32
   446: //		adc     edx, 0		//edx ← edx + 0 + キャリーフラグ
   447: //		mov     eax, edx	//eax ← edx ※戻り値
   448: //	}
   449: //}
   450: //template<int N> inline int intDivOpt(const int val){ return static_cast<int>(static_cast<float>(val) * (1.f / (static_cast<float>(N)))); }//逆数を定数化して浮動小数点演算した後に整数化
   451: template<int N> inline int intDivOpt(const int val){ return val / N; }//そのまま演算
   452: template<>      inline int intDivOpt<0>(const int val){ throw std::overflow_error("Integer division by zero");	return 0; }
   453: template<>      inline int intDivOpt<1>(const int val){ return val; }
   454: template<>      inline int intDivOpt<2>(const int val){ return val >> 1; }
   455: template<>      inline int intDivOpt<4>(const int val){ return val >> 2; }
   456: template<>      inline int intDivOpt<8>(const int val){ return val >> 3; }
   457: template<>      inline int intDivOpt<16>(const int val){ return val >> 4; }
   458: template<>      inline int intDivOpt<32>(const int val){ return val >> 5; }
   459: template<>      inline int intDivOpt<64>(const int val){ return val >> 6; }
   460: template<>      inline int intDivOpt<128>(const int val){ return val >> 7; }
   461: template<>      inline int intDivOpt<256>(const int val){ return val >> 8; }
   462: template<>      inline int intDivOpt<512>(const int val){ return val >> 9; }
   463: template<>      inline int intDivOpt<1024>(const int val){ return val >> 10; }
   464: //template<int N> inline int intModOpt(const int val){ return (((static_cast<long long>(val) * (0xffffffffll / static_cast<long long>(N)) + 32) & 0xffffffffll) * static_cast<long long>(N)) >> 32; }//逆数を定数化して整数演算
   465: //template<int N> inline int intModOpt(const int val)//逆数を定数化して整数演算（インラインアセンブラ版）
   466: //{
   467: //	//return (((static_cast<long long>(val) * (0xffffffffll / static_cast<long long>(N)) + 32) & 0xffffffffll) * static_cast<long long>(N)) >> 32;
   468: //	const int rec = getReciprocalDivisor<N>();
   469: //	const int n = N;
   470: //	__asm
   471: //	{
   472: //		mov     eax, rec	//eax ← rec
   473: //		mul     val			//edx:eax ← eax * val
   474: //		add     eax, 32		//eax ← eax + 32
   475: //		mul     n           //edx:eax ← eax * N
   476: //		mov     eax, edx	//eax ← edx ※戻り値
   477: //	}
   478: //}
   479: //template<int N> inline int intModOpt(const int val){ return val - static_cast<int>(static_cast<float>(val)* (1.f / (static_cast<float>(N)))) * N; }//逆数を定数化して浮動小数点演算した後に整数化
   480: template<int N> inline int intModOpt(const int val){ return val % N; }//そのまま演算
   481: template<>      inline int intModOpt<0>(const int val){ throw std::overflow_error("Integer division by zero");	return 0; }
   482: template<>      inline int intModOpt<1>(const int val){ return 0; }
   483: template<>      inline int intModOpt<2>(const int val){ return val & (2 - 1); }
   484: template<>      inline int intModOpt<4>(const int val){ return val & (4 - 1); }
   485: template<>      inline int intModOpt<8>(const int val){ return val & (8 - 1); }
   486: template<>      inline int intModOpt<16>(const int val){ return val & (16 - 1); }
   487: template<>      inline int intModOpt<32>(const int val){ return val & (32 - 1); }
   488: template<>      inline int intModOpt<64>(const int val){ return val & (64 - 1); }
   489: template<>      inline int intModOpt<128>(const int val){ return val & (128 - 1); }
   490: template<>      inline int intModOpt<256>(const int val){ return val & (256 - 1); }
   491: template<>      inline int intModOpt<512>(const int val){ return val & (512 - 1); }
   492: template<>      inline int intModOpt<1024>(const int val){ return val & (1024 - 1); }
   493: int testOpt05_Type1_After(const int val,
   494:                           int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
   495: 						  int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
   496: 						  int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24)
   497: {
00903AB0 55                   push        ebp  
00903AB1 8B EC                mov         ebp,esp  
00903AB3 83 EC 08             sub         esp,8  
   498: 	m2 = intMulOpt<2>(val);
00903AB6 8B 4D 0C             mov         ecx,dword ptr [m2]  
00903AB9 53                   push        ebx  
00903ABA 8B 5D 08             mov         ebx,dword ptr [val]  
00903ABD 56                   push        esi  
00903ABE 57                   push        edi  
00903ABF 8D 04 1B             lea         eax,[ebx+ebx]  
00903AC2 89 01                mov         dword ptr [ecx],eax  
   499: 	m3 = intMulOpt<3>(val);
00903AC4 8D 04 5B             lea         eax,[ebx+ebx*2]  
00903AC7 8B 4D 10             mov         ecx,dword ptr [m3]  
00903ACA 89 01                mov         dword ptr [ecx],eax  
   500: 	m4 = intMulOpt<4>(val);
00903ACC 8D 04 9D 00 00 00 00 lea         eax,[ebx*4]  
00903AD3 8B 4D 14             mov         ecx,dword ptr [m4]  
00903AD6 89 01                mov         dword ptr [ecx],eax  
   501: 	m5 = intMulOpt<5>(val);
00903AD8 8D 04 9B             lea         eax,[ebx+ebx*4]  
00903ADB 8B 4D 18             mov         ecx,dword ptr [m5]  
00903ADE 89 01                mov         dword ptr [ecx],eax  
   502: 	m10 = intMulOpt<10>(val);
00903AE0 8D 04 9B             lea         eax,[ebx+ebx*4]  
00903AE3 8B 4D 1C             mov         ecx,dword ptr [m10]  
00903AE6 03 C0                add         eax,eax  
00903AE8 89 01                mov         dword ptr [ecx],eax  
   503: 	m16 = intMulOpt<16>(val);
00903AEA 8B C3                mov         eax,ebx  
   503: 	m16 = intMulOpt<16>(val);
00903AEC 8B 4D 20             mov         ecx,dword ptr [m16]  
00903AEF C1 E0 04             shl         eax,4  
00903AF2 89 01                mov         dword ptr [ecx],eax  
   504: 	m24 = intMulOpt<24>(val);
00903AF4 8D 04 5B             lea         eax,[ebx+ebx*2]  
00903AF7 8B 4D 24             mov         ecx,dword ptr [m24]  
00903AFA C1 E0 03             shl         eax,3  
00903AFD 89 01                mov         dword ptr [ecx],eax  
   505: 	d2 = intDivOpt<2>(val);
00903AFF 8B C3                mov         eax,ebx  
00903B01 8B 4D 28             mov         ecx,dword ptr [d2]  
00903B04 D1 F8                sar         eax,1  
00903B06 89 01                mov         dword ptr [ecx],eax  
   506: 	d3 = intDivOpt<3>(val);
00903B08 B8 56 55 55 55       mov         eax,55555556h  
00903B0D F7 EB                imul        ebx  
00903B0F 8B 45 2C             mov         eax,dword ptr [d3]  
   507: 	d4 = intDivOpt<4>(val);
00903B12 8B 4D 30             mov         ecx,dword ptr [d4]  
   506: 	d3 = intDivOpt<3>(val);
00903B15 8B FA                mov         edi,edx  
00903B17 C1 EF 1F             shr         edi,1Fh  
00903B1A 03 FA                add         edi,edx  
00903B1C 89 38                mov         dword ptr [eax],edi  
   507: 	d4 = intDivOpt<4>(val);
00903B1E 8B C3                mov         eax,ebx  
00903B20 C1 F8 02             sar         eax,2  
00903B23 89 01                mov         dword ptr [ecx],eax  
   508: 	d5 = intDivOpt<5>(val);
00903B25 B8 67 66 66 66       mov         eax,66666667h  
00903B2A F7 EB                imul        ebx  
00903B2C 8B 45 34             mov         eax,dword ptr [d5]  
   509: 	d10 = intDivOpt<10>(val);
00903B2F 8B 4D 38             mov         ecx,dword ptr [d10]  
   508: 	d5 = intDivOpt<5>(val);
00903B32 D1 FA                sar         edx,1  
00903B34 8B F2                mov         esi,edx  
00903B36 C1 EE 1F             shr         esi,1Fh  
00903B39 03 F2                add         esi,edx  
00903B3B 89 30                mov         dword ptr [eax],esi  
   509: 	d10 = intDivOpt<10>(val);
00903B3D B8 67 66 66 66       mov         eax,66666667h  
00903B42 F7 EB                imul        ebx  
00903B44 C1 FA 02             sar         edx,2  
00903B47 8B C2                mov         eax,edx  
00903B49 C1 E8 1F             shr         eax,1Fh  
00903B4C 03 C2                add         eax,edx  
00903B4E 89 01                mov         dword ptr [ecx],eax  
   510: 	d16 = intDivOpt<16>(val);
00903B50 8B 4D 3C             mov         ecx,dword ptr [d16]  
   509: 	d10 = intDivOpt<10>(val);
00903B53 89 45 FC             mov         dword ptr [ebp-4],eax  
   510: 	d16 = intDivOpt<16>(val);
00903B56 8B C3                mov         eax,ebx  
00903B58 C1 F8 04             sar         eax,4  
00903B5B 89 01                mov         dword ptr [ecx],eax  
   511: 	d24 = intDivOpt<24>(val);
00903B5D B8 AB AA AA 2A       mov         eax,2AAAAAABh  
00903B62 8B 4D 40             mov         ecx,dword ptr [d24]  
00903B65 F7 EB                imul        ebx  
00903B67 C1 FA 02             sar         edx,2  
00903B6A 8B C2                mov         eax,edx  
00903B6C C1 E8 1F             shr         eax,1Fh  
00903B6F 03 C2                add         eax,edx  
00903B71 89 01                mov         dword ptr [ecx],eax  
   512: 	r2 = intModOpt<2>(val);
00903B73 8B 4D 44             mov         ecx,dword ptr [r2]  
   511: 	d24 = intDivOpt<24>(val);
00903B76 89 45 F8             mov         dword ptr [ebp-8],eax  
   512: 	r2 = intModOpt<2>(val);
00903B79 8B C3                mov         eax,ebx  
00903B7B 83 E0 01             and         eax,1  
00903B7E 89 01                mov         dword ptr [ecx],eax  
   513: 	r3 = intModOpt<3>(val);
00903B80 8B CB                mov         ecx,ebx  
00903B82 8B 5D 48             mov         ebx,dword ptr [r3]  
00903B85 8D 04 7F             lea         eax,[edi+edi*2]  
00903B88 2B C8                sub         ecx,eax  
00903B8A 89 0B                mov         dword ptr [ebx],ecx  
   514: 	r4 = intModOpt<4>(val);
00903B8C 8B 5D 08             mov         ebx,dword ptr [val]  
00903B8F 8B C3                mov         eax,ebx  
00903B91 8B 7D 4C             mov         edi,dword ptr [r4]  
00903B94 83 E0 03             and         eax,3  
   516: 	r10 = intModOpt<10>(val);
00903B97 8B 55 54             mov         edx,dword ptr [r10]  
   515: 	r5 = intModOpt<5>(val);
00903B9A 8B CB                mov         ecx,ebx  
   514: 	r4 = intModOpt<4>(val);
00903B9C 89 07                mov         dword ptr [edi],eax  
   515: 	r5 = intModOpt<5>(val);
00903B9E 8D 04 B6             lea         eax,[esi+esi*4]  
00903BA1 2B C8                sub         ecx,eax  
00903BA3 8B 75 50             mov         esi,dword ptr [r5]  
   516: 	r10 = intModOpt<10>(val);
00903BA6 8B 45 FC             mov         eax,dword ptr [ebp-4]  
   515: 	r5 = intModOpt<5>(val);
00903BA9 89 0E                mov         dword ptr [esi],ecx  
00903BAB 8B CB                mov         ecx,ebx  
00903BAD 8D 04 80             lea         eax,[eax+eax*4]  
00903BB0 03 C0                add         eax,eax  
00903BB2 2B C8                sub         ecx,eax  
   517: 	r16 = intModOpt<16>(val);
00903BB4 8B C3                mov         eax,ebx  
   516: 	r10 = intModOpt<10>(val);
00903BB6 89 0A                mov         dword ptr [edx],ecx  
   517: 	r16 = intModOpt<16>(val);
00903BB8 83 E0 0F             and         eax,0Fh  
00903BBB 8B 4D 58             mov         ecx,dword ptr [r16]  
00903BBE 89 01                mov         dword ptr [ecx],eax  
   518: 	r24 = intModOpt<24>(val);
00903BC0 8B 45 F8             mov         eax,dword ptr [ebp-8]  
00903BC3 8D 04 40             lea         eax,[eax+eax*2]  
00903BC6 C1 E0 03             shl         eax,3  
00903BC9 2B D8                sub         ebx,eax  
00903BCB 8B 45 5C             mov         eax,dword ptr [r24]  
00903BCE 89 5D 08             mov         dword ptr [val],ebx  
00903BD1 89 18                mov         dword ptr [eax],ebx  
   519: 	return m2 + m3 + m4 + m5 + m10 + m16 + m24 +
   520: 	       d2 + d3 + d4 + d5 + d10 + d16 + d24 +
   521: 	       r2 + r3 + r4 + r5 + r10 + r16 + r24;
00903BD3 8B 45 24             mov         eax,dword ptr [m24]  
00903BD6 8B 5D 44             mov         ebx,dword ptr [r2]  
00903BD9 8B 00                mov         eax,dword ptr [eax]  
00903BDB 03 03                add         eax,dword ptr [ebx]  
00903BDD 8B 5D 28             mov         ebx,dword ptr [d2]  
00903BE0 03 03                add         eax,dword ptr [ebx]  
00903BE2 8B 5D 48             mov         ebx,dword ptr [r3]  
00903BE5 03 03                add         eax,dword ptr [ebx]  
00903BE7 8B 5D 0C             mov         ebx,dword ptr [m2]  
00903BEA 03 03                add         eax,dword ptr [ebx]  
00903BEC 8B 5D 2C             mov         ebx,dword ptr [d3]  
00903BEF 03 03                add         eax,dword ptr [ebx]  
00903BF1 03 07                add         eax,dword ptr [edi]  
00903BF3 8B 7D 10             mov         edi,dword ptr [m3]  
00903BF6 03 07                add         eax,dword ptr [edi]  
00903BF8 8B 7D 30             mov         edi,dword ptr [d4]  
00903BFB 03 07                add         eax,dword ptr [edi]  
00903BFD 03 06                add         eax,dword ptr [esi]  
00903BFF 8B 75 14             mov         esi,dword ptr [m4]  
00903C02 5F                   pop         edi  
00903C03 03 06                add         eax,dword ptr [esi]  
00903C05 8B 75 34             mov         esi,dword ptr [d5]  
00903C08 03 06                add         eax,dword ptr [esi]  
00903C0A 03 02                add         eax,dword ptr [edx]  
00903C0C 8B 55 18             mov         edx,dword ptr [m5]  
00903C0F 5E                   pop         esi  
00903C10 5B                   pop         ebx  
00903C11 03 02                add         eax,dword ptr [edx]  
00903C13 8B 55 38             mov         edx,dword ptr [d10]  
00903C16 03 02                add         eax,dword ptr [edx]  
00903C18 03 01                add         eax,dword ptr [ecx]  
00903C1A 8B 4D 1C             mov         ecx,dword ptr [m10]  
00903C1D 03 45 08             add         eax,dword ptr [val]  
00903C20 03 01                add         eax,dword ptr [ecx]  
00903C22 8B 4D 3C             mov         ecx,dword ptr [d16]  
00903C25 03 01                add         eax,dword ptr [ecx]  
00903C27 8B 4D 20             mov         ecx,dword ptr [m16]  
00903C2A 03 01                add         eax,dword ptr [ecx]  
00903C2C 8B 4D 40             mov         ecx,dword ptr [d24]  
00903C2F 03 01                add         eax,dword ptr [ecx]  
   522: }
00903C31 8B E5                mov         esp,ebp  
00903C33 5D                   pop         ebp  
00903C34 C3                   ret  

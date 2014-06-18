   971: int testOpt05_Type1_After(int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
   972: 						  int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
   973: 						  int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24)
   974: {
0083A2B0 55                   push        ebp  
0083A2B1 8B EC                mov         ebp,esp  
   975: 	m2  = intMulOpt< 2>(m2 );//val *  2
0083A2B3 8B 45 08             mov         eax,dword ptr [m2]  
   976: 	m3  = intMulOpt< 3>(m3 );//val *  3
0083A2B6 8B 4D 0C             mov         ecx,dword ptr [m3]  
0083A2B9 53                   push        ebx  
   985: 	d5  = intDivOpt< 5>(d5 );//val /  5
0083A2BA 8B 5D 30             mov         ebx,dword ptr [d5]  
   975: 	m2  = intMulOpt< 2>(m2 );//val *  2
0083A2BD D1 20                shl         dword ptr [eax],1  
   976: 	m3  = intMulOpt< 3>(m3 );//val *  3
0083A2BF 8B 01                mov         eax,dword ptr [ecx]  
0083A2C1 56                   push        esi  
   990: 	r3  = intModOpt< 3>(r3 );//val %  3
0083A2C2 BE 03 00 00 00       mov         esi,3  
0083A2C7 57                   push        edi  
   976: 	m3  = intMulOpt< 3>(m3 );//val *  3
0083A2C8 8D 04 40             lea         eax,[eax+eax*2]  
   993: 	r10 = intModOpt<10>(r10);//val % 10
0083A2CB 8B 7D 50             mov         edi,dword ptr [r10]  
   976: 	m3  = intMulOpt< 3>(m3 );//val *  3
0083A2CE 89 01                mov         dword ptr [ecx],eax  
   977: 	m4  = intMulOpt< 4>(m4 );//val *  4
0083A2D0 8B 45 10             mov         eax,dword ptr [m4]  
   978: 	m5  = intMulOpt< 5>(m5 );//val *  5
0083A2D3 8B 4D 14             mov         ecx,dword ptr [m5]  
   977: 	m4  = intMulOpt< 4>(m4 );//val *  4
0083A2D6 C1 20 02             shl         dword ptr [eax],2  
0083A2D9 8B 01                mov         eax,dword ptr [ecx]  
0083A2DB 8D 04 80             lea         eax,[eax+eax*4]  
0083A2DE 89 01                mov         dword ptr [ecx],eax  
   979: 	m10 = intMulOpt<10>(m10);//val * 10
0083A2E0 8B 4D 18             mov         ecx,dword ptr [m10]  
0083A2E3 8B 01                mov         eax,dword ptr [ecx]  
0083A2E5 8D 04 80             lea         eax,[eax+eax*4]  
0083A2E8 03 C0                add         eax,eax  
0083A2EA 89 01                mov         dword ptr [ecx],eax  
   980: 	m16 = intMulOpt<16>(m16);//val * 16
0083A2EC 8B 45 1C             mov         eax,dword ptr [m16]  
   981: 	m24 = intMulOpt<24>(m24);//val * 24
0083A2EF 8B 4D 20             mov         ecx,dword ptr [m24]  
   980: 	m16 = intMulOpt<16>(m16);//val * 16
0083A2F2 C1 20 04             shl         dword ptr [eax],4  
   981: 	m24 = intMulOpt<24>(m24);//val * 24
0083A2F5 8B 01                mov         eax,dword ptr [ecx]  
0083A2F7 8D 04 40             lea         eax,[eax+eax*2]  
0083A2FA C1 E0 03             shl         eax,3  
0083A2FD 89 01                mov         dword ptr [ecx],eax  
   982: 	d2  = intDivOpt< 2>(d2 );//val /  2
0083A2FF 8B 45 24             mov         eax,dword ptr [d2]  
   983: 	d3  = intDivOpt< 3>(d3 );//val /  3
0083A302 8B 4D 28             mov         ecx,dword ptr [d3]  
   982: 	d2  = intDivOpt< 2>(d2 );//val /  2
0083A305 D1 38                sar         dword ptr [eax],1  
   983: 	d3  = intDivOpt< 3>(d3 );//val /  3
0083A307 B8 56 55 55 55       mov         eax,55555556h  
0083A30C F7 29                imul        dword ptr [ecx]  
0083A30E 8B C2                mov         eax,edx  
0083A310 C1 E8 1F             shr         eax,1Fh  
0083A313 03 C2                add         eax,edx  
0083A315 89 01                mov         dword ptr [ecx],eax  
   984: 	d4  = intDivOpt< 4>(d4 );//val /  4
0083A317 8B 45 2C             mov         eax,dword ptr [d4]  
0083A31A C1 38 02             sar         dword ptr [eax],2  
   985: 	d5  = intDivOpt< 5>(d5 );//val /  5
0083A31D B8 67 66 66 66       mov         eax,66666667h  
0083A322 F7 2B                imul        dword ptr [ebx]  
   986: 	d10 = intDivOpt<10>(d10);//val / 10
0083A324 B8 67 66 66 66       mov         eax,66666667h  
   985: 	d5  = intDivOpt< 5>(d5 );//val /  5
0083A329 D1 FA                sar         edx,1  
0083A32B 8B CA                mov         ecx,edx  
0083A32D C1 E9 1F             shr         ecx,1Fh  
0083A330 03 CA                add         ecx,edx  
0083A332 89 0B                mov         dword ptr [ebx],ecx  
   986: 	d10 = intDivOpt<10>(d10);//val / 10
0083A334 8B 4D 34             mov         ecx,dword ptr [d10]  
   991: 	r4  = intModOpt< 4>(r4 );//val %  4
0083A337 8B 5D 48             mov         ebx,dword ptr [r4]  
   986: 	d10 = intDivOpt<10>(d10);//val / 10
0083A33A F7 29                imul        dword ptr [ecx]  
0083A33C C1 FA 02             sar         edx,2  
0083A33F 8B C2                mov         eax,edx  
0083A341 C1 E8 1F             shr         eax,1Fh  
0083A344 03 C2                add         eax,edx  
0083A346 89 01                mov         dword ptr [ecx],eax  
   987: 	d16 = intDivOpt<16>(d16);//val / 16
0083A348 8B 45 38             mov         eax,dword ptr [d16]  
   988: 	d24 = intDivOpt<24>(d24);//val / 24
0083A34B 8B 4D 3C             mov         ecx,dword ptr [d24]  
0083A34E C1 38 04             sar         dword ptr [eax],4  
   988: 	d24 = intDivOpt<24>(d24);//val / 24
0083A351 B8 AB AA AA 2A       mov         eax,2AAAAAABh  
0083A356 F7 29                imul        dword ptr [ecx]  
0083A358 C1 FA 02             sar         edx,2  
0083A35B 8B C2                mov         eax,edx  
0083A35D C1 E8 1F             shr         eax,1Fh  
0083A360 03 C2                add         eax,edx  
0083A362 89 01                mov         dword ptr [ecx],eax  
   989: 	r2  = intModOpt< 2>(r2 );//val %  2
0083A364 8B 45 40             mov         eax,dword ptr [r2]  
   990: 	r3  = intModOpt< 3>(r3 );//val %  3
0083A367 8B 4D 44             mov         ecx,dword ptr [r3]  
   989: 	r2  = intModOpt< 2>(r2 );//val %  2
0083A36A 83 20 01             and         dword ptr [eax],1  
   990: 	r3  = intModOpt< 3>(r3 );//val %  3
0083A36D 8B 01                mov         eax,dword ptr [ecx]  
0083A36F 99                   cdq  
0083A370 F7 FE                idiv        eax,esi  
0083A372 89 11                mov         dword ptr [ecx],edx  
   992: 	r5  = intModOpt< 5>(r5 );//val %  5
0083A374 8B 4D 4C             mov         ecx,dword ptr [r5]  
   991: 	r4  = intModOpt< 4>(r4 );//val %  4
0083A377 21 33                and         dword ptr [ebx],esi  
   992: 	r5  = intModOpt< 5>(r5 );//val %  5
0083A379 BE 05 00 00 00       mov         esi,5  
0083A37E 8B 01                mov         eax,dword ptr [ecx]  
0083A380 99                   cdq  
0083A381 F7 FE                idiv        eax,esi  
0083A383 89 11                mov         dword ptr [ecx],edx  
   993: 	r10 = intModOpt<10>(r10);//val % 10
0083A385 8B 07                mov         eax,dword ptr [edi]  
0083A387 B9 0A 00 00 00       mov         ecx,0Ah  
0083A38C 99                   cdq  
0083A38D F7 F9                idiv        eax,ecx  
   994: 	r16 = intModOpt<16>(r16);//val % 16
0083A38F 8B 75 54             mov         esi,dword ptr [r16]  
   995: 	r24 = intModOpt<24>(r24);//val % 24
0083A392 8B 4D 58             mov         ecx,dword ptr [r24]  
   993: 	r10 = intModOpt<10>(r10);//val % 10
0083A395 89 17                mov         dword ptr [edi],edx  
   995: 	r24 = intModOpt<24>(r24);//val % 24
0083A397 C7 45 48 18 00 00 00 mov         dword ptr [r4],18h  
   994: 	r16 = intModOpt<16>(r16);//val % 16
0083A39E 83 26 0F             and         dword ptr [esi],0Fh  
   995: 	r24 = intModOpt<24>(r24);//val % 24
0083A3A1 8B 01                mov         eax,dword ptr [ecx]  
0083A3A3 99                   cdq  
0083A3A4 F7 7D 48             idiv        eax,dword ptr [r4]  
   996: 	return m2 + m3 + m4 + m5 + m10 + m16 + m24 +
   997: 	       d2 + d3 + d4 + d5 + d10 + d16 + d24 +
   998: 	       r2 + r3 + r4 + r5 + r10 + r16 + r24;
0083A3A7 8B 45 20             mov         eax,dword ptr [m24]  
0083A3AA 89 11                mov         dword ptr [ecx],edx  
0083A3AC 8B 4D 40             mov         ecx,dword ptr [r2]  
0083A3AF 8B 00                mov         eax,dword ptr [eax]  
0083A3B1 03 01                add         eax,dword ptr [ecx]  
0083A3B3 8B 4D 24             mov         ecx,dword ptr [d2]  
0083A3B6 03 01                add         eax,dword ptr [ecx]  
0083A3B8 8B 4D 44             mov         ecx,dword ptr [r3]  
0083A3BB 03 01                add         eax,dword ptr [ecx]  
0083A3BD 8B 4D 08             mov         ecx,dword ptr [m2]  
0083A3C0 03 01                add         eax,dword ptr [ecx]  
0083A3C2 8B 4D 28             mov         ecx,dword ptr [d3]  
0083A3C5 03 01                add         eax,dword ptr [ecx]  
0083A3C7 03 03                add         eax,dword ptr [ebx]  
0083A3C9 8B 4D 0C             mov         ecx,dword ptr [m3]  
0083A3CC 03 01                add         eax,dword ptr [ecx]  
0083A3CE 8B 4D 2C             mov         ecx,dword ptr [d4]  
0083A3D1 03 01                add         eax,dword ptr [ecx]  
0083A3D3 8B 4D 4C             mov         ecx,dword ptr [r5]  
0083A3D6 03 01                add         eax,dword ptr [ecx]  
0083A3D8 8B 4D 10             mov         ecx,dword ptr [m4]  
0083A3DB 03 01                add         eax,dword ptr [ecx]  
0083A3DD 8B 4D 30             mov         ecx,dword ptr [d5]  
0083A3E0 03 01                add         eax,dword ptr [ecx]  
0083A3E2 03 07                add         eax,dword ptr [edi]  
0083A3E4 8B 4D 14             mov         ecx,dword ptr [m5]  
0083A3E7 03 C2                add         eax,edx  
0083A3E9 5F                   pop         edi  
0083A3EA 03 01                add         eax,dword ptr [ecx]  
0083A3EC 8B 4D 34             mov         ecx,dword ptr [d10]  
0083A3EF 03 01                add         eax,dword ptr [ecx]  
0083A3F1 03 06                add         eax,dword ptr [esi]  
0083A3F3 8B 4D 18             mov         ecx,dword ptr [m10]  
0083A3F6 5E                   pop         esi  
0083A3F7 5B                   pop         ebx  
0083A3F8 03 01                add         eax,dword ptr [ecx]  
0083A3FA 8B 4D 38             mov         ecx,dword ptr [d16]  
0083A3FD 03 01                add         eax,dword ptr [ecx]  
0083A3FF 8B 4D 1C             mov         ecx,dword ptr [m16]  
0083A402 03 01                add         eax,dword ptr [ecx]  
0083A404 8B 4D 3C             mov         ecx,dword ptr [d24]  
0083A407 03 01                add         eax,dword ptr [ecx]  
   999: }
0083A409 5D                   pop         ebp  
0083A40A C3                   ret  

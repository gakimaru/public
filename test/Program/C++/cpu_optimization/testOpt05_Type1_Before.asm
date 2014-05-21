   370: //【タイプ１】最適化前
   371: template<int N>
   372: inline int intMul(const int val){ return val * N; }
   373: template<int N>
   374: inline int intDiv(const int val){ return val / N; }
   375: template<int N>
   376: inline int intMod(const int val){ return val % N; }
   377: int testOpt05_Type1_Before(const int val, 
   378:                            int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
   379: 						   int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
   380: 						   int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24)
   381: {
00903C40 55                   push        ebp  
00903C41 8B EC                mov         ebp,esp  
00903C43 83 EC 08             sub         esp,8  
   382: 	m2 = intMul<2>(val);
00903C46 8B 4D 0C             mov         ecx,dword ptr [m2]  
00903C49 53                   push        ebx  
00903C4A 8B 5D 08             mov         ebx,dword ptr [val]  
00903C4D 56                   push        esi  
00903C4E 57                   push        edi  
00903C4F 8D 04 1B             lea         eax,[ebx+ebx]  
00903C52 89 01                mov         dword ptr [ecx],eax  
   383: 	m3 = intMul<3>(val);
00903C54 8D 04 5B             lea         eax,[ebx+ebx*2]  
00903C57 8B 4D 10             mov         ecx,dword ptr [m3]  
00903C5A 89 01                mov         dword ptr [ecx],eax  
   384: 	m4 = intMul<4>(val);
00903C5C 8D 04 9D 00 00 00 00 lea         eax,[ebx*4]  
00903C63 8B 4D 14             mov         ecx,dword ptr [m4]  
00903C66 89 01                mov         dword ptr [ecx],eax  
   385: 	m5 = intMul<5>(val);
00903C68 8D 04 9B             lea         eax,[ebx+ebx*4]  
00903C6B 8B 4D 18             mov         ecx,dword ptr [m5]  
00903C6E 89 01                mov         dword ptr [ecx],eax  
   386: 	m10 = intMul<10>(val);
00903C70 8D 04 9B             lea         eax,[ebx+ebx*4]  
00903C73 8B 4D 1C             mov         ecx,dword ptr [m10]  
00903C76 03 C0                add         eax,eax  
00903C78 89 01                mov         dword ptr [ecx],eax  
   387: 	m16 = intMul<16>(val);
00903C7A 8B C3                mov         eax,ebx  
   387: 	m16 = intMul<16>(val);
00903C7C 8B 4D 20             mov         ecx,dword ptr [m16]  
00903C7F C1 E0 04             shl         eax,4  
00903C82 89 01                mov         dword ptr [ecx],eax  
   388: 	m24 = intMul<24>(val);
00903C84 8D 04 5B             lea         eax,[ebx+ebx*2]  
00903C87 8B 4D 24             mov         ecx,dword ptr [m24]  
00903C8A C1 E0 03             shl         eax,3  
00903C8D 89 01                mov         dword ptr [ecx],eax  
   389: 	d2 = intDiv<2>(val);
00903C8F 8B C3                mov         eax,ebx  
00903C91 8B 4D 28             mov         ecx,dword ptr [d2]  
00903C94 99                   cdq  
00903C95 2B C2                sub         eax,edx  
00903C97 D1 F8                sar         eax,1  
00903C99 89 01                mov         dword ptr [ecx],eax  
   390: 	d3 = intDiv<3>(val);
00903C9B B8 56 55 55 55       mov         eax,55555556h  
00903CA0 F7 EB                imul        ebx  
00903CA2 8B 45 2C             mov         eax,dword ptr [d3]  
   391: 	d4 = intDiv<4>(val);
00903CA5 8B 4D 30             mov         ecx,dword ptr [d4]  
   390: 	d3 = intDiv<3>(val);
00903CA8 8B FA                mov         edi,edx  
00903CAA C1 EF 1F             shr         edi,1Fh  
00903CAD 03 FA                add         edi,edx  
00903CAF 89 38                mov         dword ptr [eax],edi  
   391: 	d4 = intDiv<4>(val);
00903CB1 8B C3                mov         eax,ebx  
00903CB3 99                   cdq  
00903CB4 83 E2 03             and         edx,3  
00903CB7 03 C2                add         eax,edx  
00903CB9 C1 F8 02             sar         eax,2  
00903CBC 89 01                mov         dword ptr [ecx],eax  
   392: 	d5 = intDiv<5>(val);
00903CBE B8 67 66 66 66       mov         eax,66666667h  
00903CC3 F7 EB                imul        ebx  
00903CC5 8B 45 34             mov         eax,dword ptr [d5]  
   393: 	d10 = intDiv<10>(val);
00903CC8 8B 4D 38             mov         ecx,dword ptr [d10]  
   392: 	d5 = intDiv<5>(val);
00903CCB D1 FA                sar         edx,1  
00903CCD 8B F2                mov         esi,edx  
00903CCF C1 EE 1F             shr         esi,1Fh  
00903CD2 03 F2                add         esi,edx  
00903CD4 89 30                mov         dword ptr [eax],esi  
   393: 	d10 = intDiv<10>(val);
00903CD6 B8 67 66 66 66       mov         eax,66666667h  
   393: 	d10 = intDiv<10>(val);
00903CDB F7 EB                imul        ebx  
00903CDD C1 FA 02             sar         edx,2  
00903CE0 8B C2                mov         eax,edx  
00903CE2 C1 E8 1F             shr         eax,1Fh  
00903CE5 03 C2                add         eax,edx  
00903CE7 89 01                mov         dword ptr [ecx],eax  
   394: 	d16 = intDiv<16>(val);
00903CE9 8B 4D 3C             mov         ecx,dword ptr [d16]  
   393: 	d10 = intDiv<10>(val);
00903CEC 89 45 FC             mov         dword ptr [ebp-4],eax  
   394: 	d16 = intDiv<16>(val);
00903CEF 8B C3                mov         eax,ebx  
00903CF1 99                   cdq  
00903CF2 83 E2 0F             and         edx,0Fh  
00903CF5 03 C2                add         eax,edx  
00903CF7 C1 F8 04             sar         eax,4  
00903CFA 89 01                mov         dword ptr [ecx],eax  
   395: 	d24 = intDiv<24>(val);
00903CFC B8 AB AA AA 2A       mov         eax,2AAAAAABh  
00903D01 8B 4D 40             mov         ecx,dword ptr [d24]  
00903D04 F7 EB                imul        ebx  
00903D06 C1 FA 02             sar         edx,2  
00903D09 8B C2                mov         eax,edx  
00903D0B C1 E8 1F             shr         eax,1Fh  
00903D0E 03 C2                add         eax,edx  
00903D10 89 45 F8             mov         dword ptr [ebp-8],eax  
00903D13 89 01                mov         dword ptr [ecx],eax  
   396: 	r2 = intMod<2>(val);
00903D15 8B C3                mov         eax,ebx  
00903D17 25 01 00 00 80       and         eax,80000001h  
00903D1C 79 05                jns         testOpt05_Type1_Before+0E3h (0903D23h)  
00903D1E 48                   dec         eax  
00903D1F 83 C8 FE             or          eax,0FFFFFFFEh  
00903D22 40                   inc         eax  
00903D23 8B 4D 44             mov         ecx,dword ptr [r2]  
00903D26 89 01                mov         dword ptr [ecx],eax  
   397: 	r3 = intMod<3>(val);
00903D28 8B CB                mov         ecx,ebx  
00903D2A 8B 5D 48             mov         ebx,dword ptr [r3]  
00903D2D 8D 04 7F             lea         eax,[edi+edi*2]  
00903D30 2B C8                sub         ecx,eax  
00903D32 89 0B                mov         dword ptr [ebx],ecx  
   398: 	r4 = intMod<4>(val);
00903D34 8B 5D 08             mov         ebx,dword ptr [val]  
00903D37 8B C3                mov         eax,ebx  
00903D39 25 03 00 00 80       and         eax,80000003h  
00903D3E 79 05                jns         testOpt05_Type1_Before+105h (0903D45h)  
00903D40 48                   dec         eax  
00903D41 83 C8 FC             or          eax,0FFFFFFFCh  
00903D44 40                   inc         eax  
00903D45 8B 7D 4C             mov         edi,dword ptr [r4]  
   399: 	r5 = intMod<5>(val);
00903D48 8B CB                mov         ecx,ebx  
   400: 	r10 = intMod<10>(val);
00903D4A 8B 55 54             mov         edx,dword ptr [r10]  
00903D4D 89 07                mov         dword ptr [edi],eax  
   399: 	r5 = intMod<5>(val);
00903D4F 8D 04 B6             lea         eax,[esi+esi*4]  
00903D52 8B 75 50             mov         esi,dword ptr [r5]  
00903D55 2B C8                sub         ecx,eax  
   400: 	r10 = intMod<10>(val);
00903D57 8B 45 FC             mov         eax,dword ptr [ebp-4]  
   399: 	r5 = intMod<5>(val);
00903D5A 89 0E                mov         dword ptr [esi],ecx  
   400: 	r10 = intMod<10>(val);
00903D5C 8B CB                mov         ecx,ebx  
00903D5E 8D 04 80             lea         eax,[eax+eax*4]  
00903D61 03 C0                add         eax,eax  
00903D63 2B C8                sub         ecx,eax  
   401: 	r16 = intMod<16>(val);
00903D65 8B C3                mov         eax,ebx  
   400: 	r10 = intMod<10>(val);
00903D67 89 0A                mov         dword ptr [edx],ecx  
   401: 	r16 = intMod<16>(val);
00903D69 25 0F 00 00 80       and         eax,8000000Fh  
00903D6E 79 05                jns         testOpt05_Type1_Before+135h (0903D75h)  
00903D70 48                   dec         eax  
00903D71 83 C8 F0             or          eax,0FFFFFFF0h  
00903D74 40                   inc         eax  
00903D75 8B 4D 58             mov         ecx,dword ptr [r16]  
00903D78 89 01                mov         dword ptr [ecx],eax  
   402: 	r24 = intMod<24>(val);
00903D7A 8B 45 F8             mov         eax,dword ptr [ebp-8]  
00903D7D 8D 04 40             lea         eax,[eax+eax*2]  
00903D80 C1 E0 03             shl         eax,3  
00903D83 2B D8                sub         ebx,eax  
00903D85 8B 45 5C             mov         eax,dword ptr [r24]  
00903D88 89 5D 08             mov         dword ptr [val],ebx  
00903D8B 89 18                mov         dword ptr [eax],ebx  
   403: 	return m2 + m3 + m4 + m5 + m10 + m16 + m24 +
   404: 	       d2 + d3 + d4 + d5 + d10 + d16 + d24 + 
   405: 	       r2 + r3 + r4 + r5 + r10 + r16 + r24;
00903D8D 8B 45 24             mov         eax,dword ptr [m24]  
00903D90 8B 5D 44             mov         ebx,dword ptr [r2]  
00903D93 8B 00                mov         eax,dword ptr [eax]  
00903D95 03 03                add         eax,dword ptr [ebx]  
00903D97 8B 5D 28             mov         ebx,dword ptr [d2]  
00903D9A 03 03                add         eax,dword ptr [ebx]  
00903D9C 8B 5D 48             mov         ebx,dword ptr [r3]  
00903D9F 03 03                add         eax,dword ptr [ebx]  
00903DA1 8B 5D 0C             mov         ebx,dword ptr [m2]  
00903DA4 03 03                add         eax,dword ptr [ebx]  
00903DA6 8B 5D 2C             mov         ebx,dword ptr [d3]  
00903DA9 03 03                add         eax,dword ptr [ebx]  
00903DAB 03 07                add         eax,dword ptr [edi]  
00903DAD 8B 7D 10             mov         edi,dword ptr [m3]  
00903DB0 03 07                add         eax,dword ptr [edi]  
00903DB2 8B 7D 30             mov         edi,dword ptr [d4]  
00903DB5 03 07                add         eax,dword ptr [edi]  
00903DB7 03 06                add         eax,dword ptr [esi]  
00903DB9 8B 75 14             mov         esi,dword ptr [m4]  
00903DBC 5F                   pop         edi  
00903DBD 03 06                add         eax,dword ptr [esi]  
00903DBF 8B 75 34             mov         esi,dword ptr [d5]  
00903DC2 03 06                add         eax,dword ptr [esi]  
00903DC4 03 02                add         eax,dword ptr [edx]  
00903DC6 8B 55 18             mov         edx,dword ptr [m5]  
00903DC9 5E                   pop         esi  
00903DCA 5B                   pop         ebx  
00903DCB 03 02                add         eax,dword ptr [edx]  
00903DCD 8B 55 38             mov         edx,dword ptr [d10]  
00903DD0 03 02                add         eax,dword ptr [edx]  
00903DD2 03 01                add         eax,dword ptr [ecx]  
00903DD4 8B 4D 1C             mov         ecx,dword ptr [m10]  
00903DD7 03 45 08             add         eax,dword ptr [val]  
00903DDA 03 01                add         eax,dword ptr [ecx]  
00903DDC 8B 4D 3C             mov         ecx,dword ptr [d16]  
00903DDF 03 01                add         eax,dword ptr [ecx]  
00903DE1 8B 4D 20             mov         ecx,dword ptr [m16]  
00903DE4 03 01                add         eax,dword ptr [ecx]  
00903DE6 8B 4D 40             mov         ecx,dword ptr [d24]  
00903DE9 03 01                add         eax,dword ptr [ecx]  
   406: }
00903DEB 8B E5                mov         esp,ebp  
00903DED 5D                   pop         ebp  
00903DEE C3                   ret  

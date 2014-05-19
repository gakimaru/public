    49: //【タイプ１】【参考】C++11でもっとも簡潔な記述
    50: //※C++11の範囲に基づくforループを使用し、最も簡潔に記述したコード（遅い）
    51: void testOpt01_Type1_Appendix(dataOpt01_t& data)
    52: {
01023070 55                   push        ebp  
01023071 8B EC                mov         ebp,esp  
01023073 53                   push        ebx  
01023074 56                   push        esi  
    53: 	for (auto elems : data.elems)
01023075 8B 75 08             mov         esi,dword ptr [data]  
01023078 33 DB                xor         ebx,ebx  
0102307A 57                   push        edi  
0102307B 33 D2                xor         edx,edx  
0102307D 8D 46 04             lea         eax,[esi+4]  
01023080 8D 88 40 9C 00 00    lea         ecx,[eax+9C40h]  
01023086 8B F9                mov         edi,ecx  
01023088 2B F8                sub         edi,eax  
0102308A 83 C7 03             add         edi,3  
0102308D C1 EF 02             shr         edi,2  
01023090 3B C1                cmp         eax,ecx  
01023092 0F 47 FB             cmova       edi,ebx  
01023095 85 FF                test        edi,edi  
01023097 74 13                je          testOpt01_Type1_Appendix+3Ch (010230ACh)  
01023099 8D A4 24 00 00 00 00 lea         esp,[esp]  
    54: 		data.sum += elems.value;
010230A0 8B 08                mov         ecx,dword ptr [eax]  
010230A2 8D 40 04             lea         eax,[eax+4]  
010230A5 01 0E                add         dword ptr [esi],ecx  
010230A7 42                   inc         edx  
010230A8 3B D7                cmp         edx,edi  
010230AA 75 F4                jne         testOpt01_Type1_Appendix+30h (010230A0h)  
010230AC 5F                   pop         edi  
010230AD 5E                   pop         esi  
010230AE 5B                   pop         ebx  
    55: }
010230AF 5D                   pop         ebp  
010230B0 C3                   ret  

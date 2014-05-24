    71: //【タイプ１】【参考】C++11でもっとも簡潔な記述（遅い）
    72: //※C++11 範囲に基づくforループ
    73: void testOpt01_Type1_Appendix(dataOpt01_t& data)
    74: {
00ADBDB0 55                   push        ebp  
00ADBDB1 8B EC                mov         ebp,esp  
00ADBDB3 53                   push        ebx  
00ADBDB4 56                   push        esi  
    75: 	data.sum = 0;
00ADBDB5 8B 75 08             mov         esi,dword ptr [data]  
00ADBDB8 33 DB                xor         ebx,ebx  
00ADBDBA 57                   push        edi  
00ADBDBB 33 D2                xor         edx,edx  
    76: 	for (auto elem : data.elems)
00ADBDBD 8D 46 04             lea         eax,[esi+4]  
00ADBDC0 C7 06 00 00 00 00    mov         dword ptr [esi],0  
00ADBDC6 8D 88 40 9C 00 00    lea         ecx,[eax+9C40h]  
00ADBDCC 8B F9                mov         edi,ecx  
00ADBDCE 2B F8                sub         edi,eax  
00ADBDD0 83 C7 03             add         edi,3  
00ADBDD3 C1 EF 02             shr         edi,2  
00ADBDD6 3B C1                cmp         eax,ecx  
00ADBDD8 0F 47 FB             cmova       edi,ebx  
00ADBDDB 85 FF                test        edi,edi  
00ADBDDD 74 0D                je          testOpt01_Type1_Appendix+3Ch (0ADBDECh)  
00ADBDDF 90                   nop  
    77: 		data.sum += elem.value;
00ADBDE0 8B 08                mov         ecx,dword ptr [eax]  
00ADBDE2 8D 40 04             lea         eax,[eax+4]  
00ADBDE5 01 0E                add         dword ptr [esi],ecx  
00ADBDE7 42                   inc         edx  
00ADBDE8 3B D7                cmp         edx,edi  
00ADBDEA 75 F4                jne         testOpt01_Type1_Appendix+30h (0ADBDE0h)  
00ADBDEC 5F                   pop         edi  
00ADBDED 5E                   pop         esi  
00ADBDEE 5B                   pop         ebx  
    78: }
00ADBDEF 5D                   pop         ebp  
00ADBDF0 C3                   ret  

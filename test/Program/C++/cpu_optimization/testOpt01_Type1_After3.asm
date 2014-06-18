    49: //【タイプ１】最適化後３
    50: //※ポインタ計算に置き換えてループカウンタを無くす
    51: void testOpt01_Type1_After3(dataOpt01_t& data)
    52: {
00ADBD50 55                   push        ebp  
00ADBD51 8B EC                mov         ebp,esp  
00ADBD53 53                   push        ebx  
    53: 	int sum_tmp = 0;
    54: 	const dataOpt01_t::elem_t* end = data.elems + extentof(data.elems);
00ADBD54 8B 5D 08             mov         ebx,dword ptr [data]  
00ADBD57 33 D2                xor         edx,edx  
00ADBD59 56                   push        esi  
00ADBD5A 57                   push        edi  
00ADBD5B 33 F6                xor         esi,esi  
00ADBD5D 33 FF                xor         edi,edi  
00ADBD5F 8D 8B 44 9C 00 00    lea         ecx,[ebx+9C44h]  
    55: 	for (dataOpt01_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
00ADBD65 8D 43 04             lea         eax,[ebx+4]  
00ADBD68 3B C1                cmp         eax,ecx  
00ADBD6A 73 31                jae         testOpt01_Type1_After3+4Dh (0ADBD9Dh)  
00ADBD6C 2B C8                sub         ecx,eax  
00ADBD6E 83 C1 03             add         ecx,3  
00ADBD71 83 E1 FC             and         ecx,0FFFFFFFCh  
    55: 	for (dataOpt01_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
00ADBD74 83 F9 08             cmp         ecx,8  
00ADBD77 72 13                jb          testOpt01_Type1_After3+3Ch (0ADBD8Ch)  
00ADBD79 8D 8B 40 9C 00 00    lea         ecx,[ebx+9C40h]  
00ADBD7F 90                   nop  
    56: 		sum_tmp += elem_p->value;
00ADBD80 03 10                add         edx,dword ptr [eax]  
00ADBD82 03 70 04             add         esi,dword ptr [eax+4]  
00ADBD85 83 C0 08             add         eax,8  
00ADBD88 3B C1                cmp         eax,ecx  
00ADBD8A 72 F4                jb          testOpt01_Type1_After3+30h (0ADBD80h)  
    55: 	for (dataOpt01_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
00ADBD8C 8D 8B 44 9C 00 00    lea         ecx,[ebx+9C44h]  
00ADBD92 3B C1                cmp         eax,ecx  
00ADBD94 73 02                jae         testOpt01_Type1_After3+48h (0ADBD98h)  
    56: 		sum_tmp += elem_p->value;
00ADBD96 8B 38                mov         edi,dword ptr [eax]  
00ADBD98 8D 04 16             lea         eax,[esi+edx]  
00ADBD9B 03 F8                add         edi,eax  
    57: 	data.sum = sum_tmp;
00ADBD9D 89 3B                mov         dword ptr [ebx],edi  
00ADBD9F 5F                   pop         edi  
00ADBDA0 5E                   pop         esi  
00ADBDA1 5B                   pop         ebx  
    58: }
00ADBDA2 5D                   pop         ebp  
00ADBDA3 C3                   ret  

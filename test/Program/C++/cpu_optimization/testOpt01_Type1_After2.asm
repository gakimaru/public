    38: //【タイプ１】最適化後２
    39: //※ポインタ計算に置き換えてループカウンタを無くす
    40: void testOpt01_Type1_After2(dataOpt01_t& data)
    41: {
01023010 55                   push        ebp  
01023011 8B EC                mov         ebp,esp  
01023013 53                   push        ebx  
    42: 	int sum_tmp = 0;
    43: 	const dataOpt01_t::elem_t* end = data.elems + extentof(data.elems);
01023014 8B 5D 08             mov         ebx,dword ptr [data]  
01023017 33 D2                xor         edx,edx  
01023019 56                   push        esi  
0102301A 57                   push        edi  
0102301B 33 F6                xor         esi,esi  
0102301D 33 FF                xor         edi,edi  
0102301F 8D 8B 44 9C 00 00    lea         ecx,[ebx+9C44h]  
    44: 	for (dataOpt01_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
01023025 8D 43 04             lea         eax,[ebx+4]  
01023028 3B C1                cmp         eax,ecx  
    44: 	for (dataOpt01_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
0102302A 73 31                jae         testOpt01_Type1_After2+4Dh (0102305Dh)  
0102302C 2B C8                sub         ecx,eax  
0102302E 83 C1 03             add         ecx,3  
01023031 83 E1 FC             and         ecx,0FFFFFFFCh  
01023034 83 F9 08             cmp         ecx,8  
01023037 72 13                jb          testOpt01_Type1_After2+3Ch (0102304Ch)  
01023039 8D 8B 40 9C 00 00    lea         ecx,[ebx+9C40h]  
0102303F 90                   nop  
    45: 		sum_tmp += elem_p->value;
01023040 03 10                add         edx,dword ptr [eax]  
01023042 03 70 04             add         esi,dword ptr [eax+4]  
01023045 83 C0 08             add         eax,8  
01023048 3B C1                cmp         eax,ecx  
0102304A 72 F4                jb          testOpt01_Type1_After2+30h (01023040h)  
    44: 	for (dataOpt01_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
0102304C 8D 8B 44 9C 00 00    lea         ecx,[ebx+9C44h]  
01023052 3B C1                cmp         eax,ecx  
01023054 73 02                jae         testOpt01_Type1_After2+48h (01023058h)  
    45: 		sum_tmp += elem_p->value;
01023056 8B 38                mov         edi,dword ptr [eax]  
01023058 8D 04 16             lea         eax,[esi+edx]  
0102305B 03 F8                add         edi,eax  
    46: 	data.sum = sum_tmp;
0102305D 89 3B                mov         dword ptr [ebx],edi  
0102305F 5F                   pop         edi  
01023060 5E                   pop         esi  
01023061 5B                   pop         ebx  
    47: }
01023062 5D                   pop         ebp  
01023063 C3                   ret  

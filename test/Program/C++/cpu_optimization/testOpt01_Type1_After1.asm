    28: //【タイプ１】最適化後１
    29: //※一時変数を用意してループ中のメンバー変数へのアクセスを減らす
    30: void testOpt01_Type1_After1(dataOpt01_t& data)
    31: {
01022FE0 55                   push        ebp  
01022FE1 8B EC                mov         ebp,esp  
01022FE3 56                   push        esi  
01022FE4 57                   push        edi  
    32: 	int sum_tmp = 0;
01022FE5 8B 7D 08             mov         edi,dword ptr [data]  
01022FE8 33 C9                xor         ecx,ecx  
01022FEA 33 D2                xor         edx,edx  
01022FEC BE 88 13 00 00       mov         esi,1388h  
01022FF1 8D 47 04             lea         eax,[edi+4]  
    33: 	for (std::size_t i = 0; i < extentof(data.elems); ++i)
    34: 		sum_tmp += data.elems[i].value;
01022FF4 03 08                add         ecx,dword ptr [eax]  
01022FF6 8D 40 08             lea         eax,[eax+8]  
01022FF9 03 50 FC             add         edx,dword ptr [eax-4]  
    33: 	for (std::size_t i = 0; i < extentof(data.elems); ++i)
    34: 		sum_tmp += data.elems[i].value;
01022FFC 4E                   dec         esi  
01022FFD 75 F5                jne         testOpt01_Type1_After1+14h (01022FF4h)  
    35: 	data.sum = sum_tmp;
01022FFF 8D 04 0A             lea         eax,[edx+ecx]  
01023002 89 07                mov         dword ptr [edi],eax  
01023004 5F                   pop         edi  
01023005 5E                   pop         esi  
    36: }
01023006 5D                   pop         ebp  
01023007 C3                   ret  

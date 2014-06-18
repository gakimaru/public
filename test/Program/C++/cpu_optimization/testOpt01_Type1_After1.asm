    29: //【タイプ１】最適化後１
    30: //※一時変数を用意してループ中のメンバー変数へのアクセスを減らす
    31: void testOpt01_Type1_After1(dataOpt01_t& data)
    32: {
00ADBD20 55                   push        ebp  
00ADBD21 8B EC                mov         ebp,esp  
00ADBD23 56                   push        esi  
00ADBD24 57                   push        edi  
    33: 	int sum_tmp = 0;
00ADBD25 8B 7D 08             mov         edi,dword ptr [data]  
00ADBD28 33 C9                xor         ecx,ecx  
00ADBD2A 33 D2                xor         edx,edx  
00ADBD2C BE 88 13 00 00       mov         esi,1388h  
00ADBD31 8D 47 04             lea         eax,[edi+4]  
    34: 	for (std::size_t i = 0; i < extentof(data.elems); ++i)
    35: 		sum_tmp += data.elems[i].value;
00ADBD34 03 08                add         ecx,dword ptr [eax]  
00ADBD36 8D 40 08             lea         eax,[eax+8]  
00ADBD39 03 50 FC             add         edx,dword ptr [eax-4]  
00ADBD3C 4E                   dec         esi  
00ADBD3D 75 F5                jne         testOpt01_Type1_After2+14h (0ADBD34h)  
    36: 	data.sum = sum_tmp;
00ADBD3F 8D 04 0A             lea         eax,[edx+ecx]  
00ADBD42 89 07                mov         dword ptr [edi],eax  
    36: 	data.sum = sum_tmp;
00ADBD44 5F                   pop         edi  
00ADBD45 5E                   pop         esi  
    37: }
00ADBD46 5D                   pop         ebp  
00ADBD47 C3                   ret  

    20: //【タイプ１】最適化前
    21: //※単純な配列ループアクセス
    22: void testOpt01_Type1_Before(dataOpt01_t& data)
    23: {
010230C0 55                   push        ebp  
010230C1 8B EC                mov         ebp,esp  
    24: 	for (std::size_t i = 0; i < extentof(data.elems); ++i)
010230C3 8B 45 08             mov         eax,dword ptr [data]  
010230C6 56                   push        esi  
010230C7 BE 08 00 00 00       mov         esi,8  
010230CC 8D 64 24 00          lea         esp,[esp]  
    25: 		data.sum += data.elems[i].value;
010230D0 8B 4C 06 FC          mov         ecx,dword ptr [esi+eax-4]  
010230D4 01 08                add         dword ptr [eax],ecx  
010230D6 8B 10                mov         edx,dword ptr [eax]  
010230D8 03 14 06             add         edx,dword ptr [esi+eax]  
010230DB 89 10                mov         dword ptr [eax],edx  
010230DD 03 54 06 04          add         edx,dword ptr [esi+eax+4]  
010230E1 89 10                mov         dword ptr [eax],edx  
010230E3 03 54 06 08          add         edx,dword ptr [esi+eax+8]  
010230E7 89 10                mov         dword ptr [eax],edx  
010230E9 8B 4C 06 0C          mov         ecx,dword ptr [esi+eax+0Ch]  
010230ED 83 C6 14             add         esi,14h  
010230F0 03 CA                add         ecx,edx  
010230F2 89 08                mov         dword ptr [eax],ecx  
010230F4 81 FE 48 9C 00 00    cmp         esi,9C48h  
010230FA 72 D4                jb          testOpt01_Type1_Before+10h (010230D0h)  
010230FC 5E                   pop         esi  
    26: }
010230FD 5D                   pop         ebp  
010230FE C3                   ret  

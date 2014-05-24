    20: //【タイプ１】最適化前
    21: //※単純な配列ループアクセス
    22: void testOpt01_Type1_Before(dataOpt01_t& data)
    23: {
00ADBE00 55                   push        ebp  
00ADBE01 8B EC                mov         ebp,esp  
    24: 	data.sum = 0;
00ADBE03 8B 45 08             mov         eax,dword ptr [data]  
00ADBE06 56                   push        esi  
00ADBE07 BE 08 00 00 00       mov         esi,8  
00ADBE0C C7 00 00 00 00 00    mov         dword ptr [eax],0  
    25: 	for (std::size_t i = 0; i < extentof(data.elems); ++i)
    26: 		data.sum += data.elems[i].value;
00ADBE12 8B 4C 06 FC          mov         ecx,dword ptr [esi+eax-4]  
00ADBE16 01 08                add         dword ptr [eax],ecx  
00ADBE18 8B 10                mov         edx,dword ptr [eax]  
00ADBE1A 03 14 06             add         edx,dword ptr [esi+eax]  
00ADBE1D 89 10                mov         dword ptr [eax],edx  
00ADBE1F 03 54 06 04          add         edx,dword ptr [esi+eax+4]  
00ADBE23 89 10                mov         dword ptr [eax],edx  
00ADBE25 03 54 06 08          add         edx,dword ptr [esi+eax+8]  
00ADBE29 89 10                mov         dword ptr [eax],edx  
00ADBE2B 8B 4C 06 0C          mov         ecx,dword ptr [esi+eax+0Ch]  
00ADBE2F 83 C6 14             add         esi,14h  
00ADBE32 03 CA                add         ecx,edx  
00ADBE34 89 08                mov         dword ptr [eax],ecx  
00ADBE36 81 FE 48 9C 00 00    cmp         esi,9C48h  
00ADBE3C 72 D4                jb          testOpt01_Type1_Before+12h (0ADBE12h)  
00ADBE3E 5E                   pop         esi  
    27: }
00ADBE3F 5D                   pop         ebp  
00ADBE40 C3                   ret  

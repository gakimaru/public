   248: //最適化前
   249: void runTestOpt03_Type1_Before(const int coef1, const int coef2)
   250: {
000C1FD0 55                   push        ebp  
000C1FD1 8B EC                mov         ebp,esp  
000C1FD3 83 EC 08             sub         esp,8  
000C1FD6 53                   push        ebx  
000C1FD7 56                   push        esi  
000C1FD8 57                   push        edi  
   251: 	printf("  Before   ... ");
000C1FD9 68 84 52 0C 00       push        0C5284h  
000C1FDE FF 15 C4 50 0C 00    call        dword ptr ds:[0C50C4h]  
000C1FE4 83 C4 04             add         esp,4  
   252: 	const auto prev_time = std::chrono::system_clock::now();
000C1FE7 FF 15 3C 50 0C 00    call        dword ptr ds:[0C503Ch]  
   253: 	int sum = 0;
   254: 	for (int loop = 0; loop < LOOP_OPT03_TYPE1; ++loop)
000C1FED 8B 5D 0C             mov         ebx,dword ptr [coef2]  
000C1FF0 33 FF                xor         edi,edi  
   252: 	const auto prev_time = std::chrono::system_clock::now();
000C1FF2 89 45 FC             mov         dword ptr [ebp-4],eax  
000C1FF5 33 F6                xor         esi,esi  
   252: 	const auto prev_time = std::chrono::system_clock::now();
000C1FF7 89 55 F8             mov         dword ptr [ebp-8],edx  
000C1FFA 8D 9B 00 00 00 00    lea         ebx,[ebx]  
   255: 		sum += testOpt03_Type1_Before(loop, coef1, coef2);
000C2000 53                   push        ebx  
000C2001 FF 75 08             push        dword ptr [coef1]  
000C2004 56                   push        esi  
000C2005 E8 56 13 00 00       call        testOpt03_Type1_Before (0C3360h)  
000C200A 46                   inc         esi  
000C200B 83 C4 0C             add         esp,0Ch  
000C200E 03 F8                add         edi,eax  
000C2010 81 FE 00 E1 F5 05    cmp         esi,5F5E100h  
000C2016 7C E8                jl          runTestOpt03_Type1_Before+30h (0C2000h)  
   256: 	printElapsedTimeWithoutCR(prev_time);
000C2018 FF 15 3C 50 0C 00    call        dword ptr ds:[0C503Ch]  
000C201E 2B 45 FC             sub         eax,dword ptr [ebp-4]  
000C2021 6A 00                push        0  
000C2023 1B 55 F8             sbb         edx,dword ptr [ebp-8]  
000C2026 6A 64                push        64h  
000C2028 52                   push        edx  
000C2029 50                   push        eax  
000C202A E8 A1 19 00 00       call        _allmul (0C39D0h)  
000C202F 8B C8                mov         ecx,eax  
000C2031 E8 A7 1D 00 00       call        _ltod3 (0C3DDDh)  
000C2036 F2 0F 5E 05 F8 53 0C 00 divsd       xmm0,mmword ptr ds:[0C53F8h]  
000C203E 8B 35 C4 50 0C 00    mov         esi,dword ptr ds:[0C50C4h]  
000C2044 83 EC 08             sub         esp,8  
000C2047 F2 0F 11 04 24       movsd       mmword ptr [esp],xmm0  
000C204C 68 0C 52 0C 00       push        0C520Ch  
000C2051 FF D6                call        esi  
   257: 	printf("  sum=%d\n", sum);
000C2053 57                   push        edi  
000C2054 68 18 53 0C 00       push        0C5318h  
000C2059 FF D6                call        esi  
000C205B 83 C4 14             add         esp,14h  
000C205E 5F                   pop         edi  
000C205F 5E                   pop         esi  
000C2060 5B                   pop         ebx  
   258: }
000C2061 8B E5                mov         esp,ebp  
000C2063 5D                   pop         ebp  
000C2064 C3                   ret  

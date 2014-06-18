   294: //最適化前
   295: void runTestOpt03_Type2_Before(const int coef1, const int coef2, const int coef3, const int coef4, const int coef5, const int coef6, const int coef7)
   296: {
000C2390 55                   push        ebp  
000C2391 8B EC                mov         ebp,esp  
000C2393 83 EC 08             sub         esp,8  
000C2396 53                   push        ebx  
000C2397 56                   push        esi  
000C2398 57                   push        edi  
   297: 	printf("  Before   ... ");
000C2399 68 84 52 0C 00       push        0C5284h  
000C239E FF 15 C4 50 0C 00    call        dword ptr ds:[0C50C4h]  
000C23A4 83 C4 04             add         esp,4  
   298: 	const auto prev_time = std::chrono::system_clock::now();
000C23A7 FF 15 3C 50 0C 00    call        dword ptr ds:[0C503Ch]  
   299: 	int sum = 0;
   300: 	for (int loop = 0; loop < LOOP_OPT03_TYPE2; ++loop)
000C23AD 8B 5D 20             mov         ebx,dword ptr [coef7]  
000C23B0 33 FF                xor         edi,edi  
   298: 	const auto prev_time = std::chrono::system_clock::now();
000C23B2 89 45 FC             mov         dword ptr [ebp-4],eax  
   299: 	int sum = 0;
   300: 	for (int loop = 0; loop < LOOP_OPT03_TYPE2; ++loop)
000C23B5 33 F6                xor         esi,esi  
   298: 	const auto prev_time = std::chrono::system_clock::now();
000C23B7 89 55 F8             mov         dword ptr [ebp-8],edx  
000C23BA 8D 9B 00 00 00 00    lea         ebx,[ebx]  
   301: 		sum += testOpt03_Type2_Before(loop, coef1, coef2, coef3, coef4, coef5, coef6, coef7);
000C23C0 53                   push        ebx  
000C23C1 FF 75 1C             push        dword ptr [coef6]  
000C23C4 FF 75 18             push        dword ptr [coef5]  
000C23C7 FF 75 14             push        dword ptr [coef4]  
000C23CA FF 75 10             push        dword ptr [coef3]  
000C23CD FF 75 0C             push        dword ptr [coef2]  
000C23D0 FF 75 08             push        dword ptr [coef1]  
000C23D3 56                   push        esi  
000C23D4 E8 97 0F 00 00       call        testOpt03_Type2_Before (0C3370h)  
000C23D9 46                   inc         esi  
000C23DA 83 C4 20             add         esp,20h  
000C23DD 03 F8                add         edi,eax  
000C23DF 81 FE 00 E1 F5 05    cmp         esi,5F5E100h  
000C23E5 7C D9                jl          runTestOpt03_Type2_Before+30h (0C23C0h)  
   302: 	printElapsedTimeWithoutCR(prev_time);
000C23E7 FF 15 3C 50 0C 00    call        dword ptr ds:[0C503Ch]  
000C23ED 2B 45 FC             sub         eax,dword ptr [ebp-4]  
000C23F0 6A 00                push        0  
000C23F2 1B 55 F8             sbb         edx,dword ptr [ebp-8]  
000C23F5 6A 64                push        64h  
000C23F7 52                   push        edx  
000C23F8 50                   push        eax  
000C23F9 E8 D2 15 00 00       call        _allmul (0C39D0h)  
000C23FE 8B C8                mov         ecx,eax  
000C2400 E8 D8 19 00 00       call        _ltod3 (0C3DDDh)  
000C2405 F2 0F 5E 05 F8 53 0C 00 divsd       xmm0,mmword ptr ds:[0C53F8h]  
000C240D 8B 35 C4 50 0C 00    mov         esi,dword ptr ds:[0C50C4h]  
   302: 	printElapsedTimeWithoutCR(prev_time);
000C2413 83 EC 08             sub         esp,8  
000C2416 F2 0F 11 04 24       movsd       mmword ptr [esp],xmm0  
000C241B 68 0C 52 0C 00       push        0C520Ch  
000C2420 FF D6                call        esi  
   303: 	printf("  sum=%d\n", sum);
000C2422 57                   push        edi  
000C2423 68 18 53 0C 00       push        0C5318h  
000C2428 FF D6                call        esi  
000C242A 83 C4 14             add         esp,14h  
000C242D 5F                   pop         edi  
000C242E 5E                   pop         esi  
000C242F 5B                   pop         ebx  
   304: }
000C2430 8B E5                mov         esp,ebp  
000C2432 5D                   pop         ebp  
000C2433 C3                   ret  

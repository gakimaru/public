   305: //最適化後
   306: void runTestOpt03_Type2_After(const int coef1, const int coef2, const int coef3, const int coef4, const int coef5, const int coef6, const int coef7)
   307: {
000C22F0 55                   push        ebp  
000C22F1 8B EC                mov         ebp,esp  
000C22F3 83 EC 08             sub         esp,8  
000C22F6 53                   push        ebx  
000C22F7 56                   push        esi  
000C22F8 57                   push        edi  
   308: 	printf("  After    ... ");
000C22F9 68 24 53 0C 00       push        0C5324h  
000C22FE FF 15 C4 50 0C 00    call        dword ptr ds:[0C50C4h]  
000C2304 83 C4 04             add         esp,4  
   309: 	const auto prev_time = std::chrono::system_clock::now();
000C2307 FF 15 3C 50 0C 00    call        dword ptr ds:[0C503Ch]  
   308: 	printf("  After    ... ");
000C230D 8B 75 10             mov         esi,dword ptr [coef3]  
   310: 	int sum = 0;
000C2310 33 FF                xor         edi,edi  
   310: 	int sum = 0;
000C2312 8B 4D 1C             mov         ecx,dword ptr [coef6]  
000C2315 0F AF 4D 20          imul        ecx,dword ptr [coef7]  
000C2319 0F AF 75 14          imul        esi,dword ptr [coef4]  
000C231D 8B 5D 0C             mov         ebx,dword ptr [coef2]  
   309: 	const auto prev_time = std::chrono::system_clock::now();
000C2320 89 55 F8             mov         dword ptr [ebp-8],edx  
   308: 	printf("  After    ... ");
000C2323 8B 55 18             mov         edx,dword ptr [coef5]  
   309: 	const auto prev_time = std::chrono::system_clock::now();
000C2326 89 45 FC             mov         dword ptr [ebp-4],eax  
   308: 	printf("  After    ... ");
000C2329 03 F1                add         esi,ecx  
000C232B B9 00 E1 F5 05       mov         ecx,5F5E100h  
000C2330 F7 DE                neg         esi  
   311: 	for (int loop = 0; loop < LOOP_OPT03_TYPE2; ++loop)
   312: 		sum += testOpt03_Type2_After(loop, coef1, coef2, coef3, coef4, coef5, coef6, coef7);
000C2332 8D 04 1E             lea         eax,[esi+ebx]  
000C2335 03 75 08             add         esi,dword ptr [coef1]  
000C2338 03 C2                add         eax,edx  
000C233A 03 F8                add         edi,eax  
000C233C 49                   dec         ecx  
000C233D 75 F3                jne         runTestOpt03_Type2_After+42h (0C2332h)  
   313: 	printElapsedTimeWithoutCR(prev_time);
000C233F FF 15 3C 50 0C 00    call        dword ptr ds:[0C503Ch]  
000C2345 2B 45 FC             sub         eax,dword ptr [ebp-4]  
000C2348 6A 00                push        0  
000C234A 1B 55 F8             sbb         edx,dword ptr [ebp-8]  
000C234D 6A 64                push        64h  
000C234F 52                   push        edx  
000C2350 50                   push        eax  
000C2351 E8 7A 16 00 00       call        _allmul (0C39D0h)  
000C2356 8B C8                mov         ecx,eax  
000C2358 E8 80 1A 00 00       call        _ltod3 (0C3DDDh)  
000C235D F2 0F 5E 05 F8 53 0C 00 divsd       xmm0,mmword ptr ds:[0C53F8h]  
000C2365 8B 35 C4 50 0C 00    mov         esi,dword ptr ds:[0C50C4h]  
000C236B 83 EC 08             sub         esp,8  
000C236E F2 0F 11 04 24       movsd       mmword ptr [esp],xmm0  
000C2373 68 0C 52 0C 00       push        0C520Ch  
000C2378 FF D6                call        esi  
   314: 	printf("  sum=%d\n", sum);
000C237A 57                   push        edi  
000C237B 68 18 53 0C 00       push        0C5318h  
000C2380 FF D6                call        esi  
000C2382 83 C4 14             add         esp,14h  
000C2385 5F                   pop         edi  
000C2386 5E                   pop         esi  
000C2387 5B                   pop         ebx  
   315: }
000C2388 8B E5                mov         esp,ebp  
000C238A 5D                   pop         ebp  
000C238B C3                   ret  

   259: //最適化後
   260: void runTestOpt03_Type1_After(const int coef1, const int coef2)
   261: {
000C1F40 55                   push        ebp  
000C1F41 8B EC                mov         ebp,esp  
000C1F43 83 EC 08             sub         esp,8  
000C1F46 53                   push        ebx  
000C1F47 56                   push        esi  
000C1F48 57                   push        edi  
   262: 	printf("  After    ... ");
000C1F49 68 24 53 0C 00       push        0C5324h  
000C1F4E FF 15 C4 50 0C 00    call        dword ptr ds:[0C50C4h]  
000C1F54 83 C4 04             add         esp,4  
   263: 	const auto prev_time = std::chrono::system_clock::now();
000C1F57 FF 15 3C 50 0C 00    call        dword ptr ds:[0C503Ch]  
   262: 	printf("  After    ... ");
000C1F5D 8B 5D 08             mov         ebx,dword ptr [coef1]  
   264: 	int sum = 0;
000C1F60 33 F6                xor         esi,esi  
   263: 	const auto prev_time = std::chrono::system_clock::now();
000C1F62 89 55 F8             mov         dword ptr [ebp-8],edx  
   262: 	printf("  After    ... ");
000C1F65 33 C9                xor         ecx,ecx  
000C1F67 8B 55 0C             mov         edx,dword ptr [coef2]  
000C1F6A BF 00 E1 F5 05       mov         edi,5F5E100h  
   263: 	const auto prev_time = std::chrono::system_clock::now();
000C1F6F 89 45 FC             mov         dword ptr [ebp-4],eax  
   265: 	for (int loop = 0; loop < LOOP_OPT03_TYPE1; ++loop)
   266: 		sum += testOpt03_Type1_After(loop, coef1, coef2);
000C1F72 8D 04 11             lea         eax,[ecx+edx]  
000C1F75 03 CB                add         ecx,ebx  
000C1F77 03 F0                add         esi,eax  
000C1F79 4F                   dec         edi  
000C1F7A 75 F6                jne         runTestOpt03_Type1_After+32h (0C1F72h)  
   267: 	printElapsedTimeWithoutCR(prev_time);
000C1F7C FF 15 3C 50 0C 00    call        dword ptr ds:[0C503Ch]  
000C1F82 2B 45 FC             sub         eax,dword ptr [ebp-4]  
000C1F85 57                   push        edi  
000C1F86 1B 55 F8             sbb         edx,dword ptr [ebp-8]  
000C1F89 6A 64                push        64h  
000C1F8B 52                   push        edx  
000C1F8C 50                   push        eax  
000C1F8D E8 3E 1A 00 00       call        _allmul (0C39D0h)  
000C1F92 8B C8                mov         ecx,eax  
000C1F94 E8 44 1E 00 00       call        _ltod3 (0C3DDDh)  
000C1F99 F2 0F 5E 05 F8 53 0C 00 divsd       xmm0,mmword ptr ds:[0C53F8h]  
000C1FA1 8B 3D C4 50 0C 00    mov         edi,dword ptr ds:[0C50C4h]  
000C1FA7 83 EC 08             sub         esp,8  
000C1FAA F2 0F 11 04 24       movsd       mmword ptr [esp],xmm0  
000C1FAF 68 0C 52 0C 00       push        0C520Ch  
000C1FB4 FF D7                call        edi  
   268: 	printf("  sum=%d\n", sum);
000C1FB6 56                   push        esi  
000C1FB7 68 18 53 0C 00       push        0C5318h  
000C1FBC FF D7                call        edi  
000C1FBE 83 C4 14             add         esp,14h  
000C1FC1 5F                   pop         edi  
000C1FC2 5E                   pop         esi  
000C1FC3 5B                   pop         ebx  
   269: }
000C1FC4 8B E5                mov         esp,ebp  
000C1FC6 5D                   pop         ebp  
000C1FC7 C3                   ret  

   856: int testOpt05_Type1_Before(int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
   857: 						   int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
   858: 						   int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24)
   859: {
0083A470 55                   push        ebp  
0083A471 8B EC                mov         ebp,esp  
   860: 	m2  = intMul< 2>(m2 );//val *  2
0083A473 8B 4D 08             mov         ecx,dword ptr [m2]  
0083A476 53                   push        ebx  
   870: 	d5  = intDiv< 5>(d5 );//val /  5
0083A477 8B 5D 30             mov         ebx,dword ptr [d5]  
0083A47A 56                   push        esi  
   860: 	m2  = intMul< 2>(m2 );//val *  2
0083A47B 8B 01                mov         eax,dword ptr [ecx]  
0083A47D 03 C0                add         eax,eax  
0083A47F 89 01                mov         dword ptr [ecx],eax  
   861: 	m3  = intMul< 3>(m3 );//val *  3
0083A481 8B 4D 0C             mov         ecx,dword ptr [m3]  
0083A484 57                   push        edi  
0083A485 8B 01                mov         eax,dword ptr [ecx]  
0083A487 8D 04 40             lea         eax,[eax+eax*2]  
0083A48A 89 01                mov         dword ptr [ecx],eax  
   862: 	m4  = intMul< 4>(m4 );//val *  4
0083A48C 8B 4D 10             mov         ecx,dword ptr [m4]  
0083A48F 8B 01                mov         eax,dword ptr [ecx]  
0083A491 C1 E0 02             shl         eax,2  
0083A494 89 01                mov         dword ptr [ecx],eax  
   863: 	m5  = intMul< 5>(m5 );//val *  5
0083A496 8B 4D 14             mov         ecx,dword ptr [m5]  
0083A499 8B 01                mov         eax,dword ptr [ecx]  
0083A49B 8D 04 80             lea         eax,[eax+eax*4]  
0083A49E 89 01                mov         dword ptr [ecx],eax  
   864: 	m10 = intMul<10>(m10);//val * 10
0083A4A0 8B 4D 18             mov         ecx,dword ptr [m10]  
0083A4A3 8B 01                mov         eax,dword ptr [ecx]  
0083A4A5 8D 04 80             lea         eax,[eax+eax*4]  
0083A4A8 03 C0                add         eax,eax  
0083A4AA 89 01                mov         dword ptr [ecx],eax  
   865: 	m16 = intMul<16>(m16);//val * 16
0083A4AC 8B 4D 1C             mov         ecx,dword ptr [m16]  
0083A4AF 8B 01                mov         eax,dword ptr [ecx]  
0083A4B1 C1 E0 04             shl         eax,4  
0083A4B4 89 01                mov         dword ptr [ecx],eax  
   866: 	m24 = intMul<24>(m24);//val * 24
0083A4B6 8B 4D 20             mov         ecx,dword ptr [m24]  
0083A4B9 8B 01                mov         eax,dword ptr [ecx]  
0083A4BB 8D 04 40             lea         eax,[eax+eax*2]  
0083A4BE C1 E0 03             shl         eax,3  
0083A4C1 89 01                mov         dword ptr [ecx],eax  
   867: 	d2  = intDiv< 2>(d2 );//val /  2
0083A4C3 8B 4D 24             mov         ecx,dword ptr [d2]  
0083A4C6 8B 01                mov         eax,dword ptr [ecx]  
0083A4C8 99                   cdq  
0083A4C9 2B C2                sub         eax,edx  
0083A4CB D1 F8                sar         eax,1  
0083A4CD 89 01                mov         dword ptr [ecx],eax  
   868: 	d3  = intDiv< 3>(d3 );//val /  3
0083A4CF B8 56 55 55 55       mov         eax,55555556h  
0083A4D4 8B 4D 28             mov         ecx,dword ptr [d3]  
0083A4D7 F7 29                imul        dword ptr [ecx]  
0083A4D9 8B C2                mov         eax,edx  
   868: 	d3  = intDiv< 3>(d3 );//val /  3
0083A4DB C1 E8 1F             shr         eax,1Fh  
0083A4DE 03 C2                add         eax,edx  
0083A4E0 89 01                mov         dword ptr [ecx],eax  
   869: 	d4  = intDiv< 4>(d4 );//val /  4
0083A4E2 8B 4D 2C             mov         ecx,dword ptr [d4]  
0083A4E5 8B 01                mov         eax,dword ptr [ecx]  
0083A4E7 99                   cdq  
0083A4E8 83 E2 03             and         edx,3  
0083A4EB 03 C2                add         eax,edx  
0083A4ED C1 F8 02             sar         eax,2  
0083A4F0 89 01                mov         dword ptr [ecx],eax  
   870: 	d5  = intDiv< 5>(d5 );//val /  5
0083A4F2 B8 67 66 66 66       mov         eax,66666667h  
0083A4F7 F7 2B                imul        dword ptr [ebx]  
   871: 	d10 = intDiv<10>(d10);//val / 10
0083A4F9 B8 67 66 66 66       mov         eax,66666667h  
   870: 	d5  = intDiv< 5>(d5 );//val /  5
0083A4FE D1 FA                sar         edx,1  
0083A500 8B CA                mov         ecx,edx  
0083A502 C1 E9 1F             shr         ecx,1Fh  
0083A505 03 CA                add         ecx,edx  
0083A507 89 0B                mov         dword ptr [ebx],ecx  
   871: 	d10 = intDiv<10>(d10);//val / 10
0083A509 8B 4D 34             mov         ecx,dword ptr [d10]  
0083A50C F7 29                imul        dword ptr [ecx]  
0083A50E C1 FA 02             sar         edx,2  
0083A511 8B C2                mov         eax,edx  
0083A513 C1 E8 1F             shr         eax,1Fh  
0083A516 03 C2                add         eax,edx  
0083A518 89 01                mov         dword ptr [ecx],eax  
   872: 	d16 = intDiv<16>(d16);//val / 16
0083A51A 8B 4D 38             mov         ecx,dword ptr [d16]  
0083A51D 8B 01                mov         eax,dword ptr [ecx]  
0083A51F 99                   cdq  
0083A520 83 E2 0F             and         edx,0Fh  
0083A523 03 C2                add         eax,edx  
0083A525 C1 F8 04             sar         eax,4  
0083A528 89 01                mov         dword ptr [ecx],eax  
   873: 	d24 = intDiv<24>(d24);//val / 24
0083A52A B8 AB AA AA 2A       mov         eax,2AAAAAABh  
0083A52F 8B 4D 3C             mov         ecx,dword ptr [d24]  
0083A532 F7 29                imul        dword ptr [ecx]  
0083A534 C1 FA 02             sar         edx,2  
0083A537 8B C2                mov         eax,edx  
0083A539 C1 E8 1F             shr         eax,1Fh  
0083A53C 03 C2                add         eax,edx  
0083A53E 89 01                mov         dword ptr [ecx],eax  
   874: 	r2  = intMod< 2>(r2 );//val %  2
0083A540 8B 4D 40             mov         ecx,dword ptr [r2]  
0083A543 8B 01                mov         eax,dword ptr [ecx]  
0083A545 25 01 00 00 80       and         eax,80000001h  
0083A54A 79 05                jns         testOpt05_Type1_Before+0E1h (083A551h)  
0083A54C 48                   dec         eax  
0083A54D 83 C8 FE             or          eax,0FFFFFFFEh  
0083A550 40                   inc         eax  
0083A551 89 01                mov         dword ptr [ecx],eax  
   875: 	r3  = intMod< 3>(r3 );//val %  3
0083A553 BE 03 00 00 00       mov         esi,3  
0083A558 8B 4D 44             mov         ecx,dword ptr [r3]  
0083A55B 8B 01                mov         eax,dword ptr [ecx]  
0083A55D 99                   cdq  
0083A55E F7 FE                idiv        eax,esi  
0083A560 89 11                mov         dword ptr [ecx],edx  
   876: 	r4  = intMod< 4>(r4 );//val %  4
0083A562 8B 4D 48             mov         ecx,dword ptr [r4]  
0083A565 8B 01                mov         eax,dword ptr [ecx]  
0083A567 25 03 00 00 80       and         eax,80000003h  
0083A56C 79 05                jns         testOpt05_Type1_Before+103h (083A573h)  
0083A56E 48                   dec         eax  
0083A56F 83 C8 FC             or          eax,0FFFFFFFCh  
0083A572 40                   inc         eax  
   877: 	r5  = intMod< 5>(r5 );//val %  5
0083A573 8B 5D 4C             mov         ebx,dword ptr [r5]  
   876: 	r4  = intMod< 4>(r4 );//val %  4
0083A576 89 01                mov         dword ptr [ecx],eax  
   877: 	r5  = intMod< 5>(r5 );//val %  5
0083A578 B9 05 00 00 00       mov         ecx,5  
   878: 	r10 = intMod<10>(r10);//val % 10
0083A57D 8B 7D 50             mov         edi,dword ptr [r10]  
   879: 	r16 = intMod<16>(r16);//val % 16
0083A580 8B 75 54             mov         esi,dword ptr [r16]  
   877: 	r5  = intMod< 5>(r5 );//val %  5
0083A583 8B 03                mov         eax,dword ptr [ebx]  
   877: 	r5  = intMod< 5>(r5 );//val %  5
0083A585 99                   cdq  
0083A586 F7 F9                idiv        eax,ecx  
   878: 	r10 = intMod<10>(r10);//val % 10
0083A588 B9 0A 00 00 00       mov         ecx,0Ah  
   877: 	r5  = intMod< 5>(r5 );//val %  5
0083A58D 89 13                mov         dword ptr [ebx],edx  
   878: 	r10 = intMod<10>(r10);//val % 10
0083A58F 8B 07                mov         eax,dword ptr [edi]  
0083A591 99                   cdq  
0083A592 F7 F9                idiv        eax,ecx  
0083A594 89 17                mov         dword ptr [edi],edx  
   879: 	r16 = intMod<16>(r16);//val % 16
0083A596 8B 06                mov         eax,dword ptr [esi]  
0083A598 25 0F 00 00 80       and         eax,8000000Fh  
0083A59D 79 05                jns         testOpt05_Type1_Before+134h (083A5A4h)  
0083A59F 48                   dec         eax  
0083A5A0 83 C8 F0             or          eax,0FFFFFFF0h  
0083A5A3 40                   inc         eax  
   880: 	r24 = intMod<24>(r24);//val % 24
0083A5A4 8B 4D 58             mov         ecx,dword ptr [r24]  
   879: 	r16 = intMod<16>(r16);//val % 16
0083A5A7 89 06                mov         dword ptr [esi],eax  
   880: 	r24 = intMod<24>(r24);//val % 24
0083A5A9 C7 45 4C 18 00 00 00 mov         dword ptr [r5],18h  
0083A5B0 8B 01                mov         eax,dword ptr [ecx]  
0083A5B2 99                   cdq  
0083A5B3 F7 7D 4C             idiv        eax,dword ptr [r5]  
   881: 	return m2 + m3 + m4 + m5 + m10 + m16 + m24 +
   882: 	       d2 + d3 + d4 + d5 + d10 + d16 + d24 + 
   883: 	       r2 + r3 + r4 + r5 + r10 + r16 + r24;
0083A5B6 8B 45 20             mov         eax,dword ptr [m24]  
0083A5B9 89 11                mov         dword ptr [ecx],edx  
0083A5BB 8B 4D 40             mov         ecx,dword ptr [r2]  
0083A5BE 8B 00                mov         eax,dword ptr [eax]  
0083A5C0 03 01                add         eax,dword ptr [ecx]  
0083A5C2 8B 4D 24             mov         ecx,dword ptr [d2]  
0083A5C5 03 01                add         eax,dword ptr [ecx]  
0083A5C7 8B 4D 44             mov         ecx,dword ptr [r3]  
0083A5CA 03 01                add         eax,dword ptr [ecx]  
0083A5CC 8B 4D 08             mov         ecx,dword ptr [m2]  
0083A5CF 03 01                add         eax,dword ptr [ecx]  
0083A5D1 8B 4D 28             mov         ecx,dword ptr [d3]  
0083A5D4 03 01                add         eax,dword ptr [ecx]  
0083A5D6 8B 4D 48             mov         ecx,dword ptr [r4]  
0083A5D9 03 01                add         eax,dword ptr [ecx]  
0083A5DB 8B 4D 0C             mov         ecx,dword ptr [m3]  
0083A5DE 03 01                add         eax,dword ptr [ecx]  
0083A5E0 8B 4D 2C             mov         ecx,dword ptr [d4]  
0083A5E3 03 01                add         eax,dword ptr [ecx]  
0083A5E5 03 03                add         eax,dword ptr [ebx]  
0083A5E7 8B 4D 10             mov         ecx,dword ptr [m4]  
0083A5EA 03 01                add         eax,dword ptr [ecx]  
0083A5EC 8B 4D 30             mov         ecx,dword ptr [d5]  
0083A5EF 03 01                add         eax,dword ptr [ecx]  
0083A5F1 03 07                add         eax,dword ptr [edi]  
0083A5F3 8B 4D 14             mov         ecx,dword ptr [m5]  
0083A5F6 03 C2                add         eax,edx  
0083A5F8 5F                   pop         edi  
0083A5F9 03 01                add         eax,dword ptr [ecx]  
0083A5FB 8B 4D 34             mov         ecx,dword ptr [d10]  
0083A5FE 03 01                add         eax,dword ptr [ecx]  
0083A600 03 06                add         eax,dword ptr [esi]  
0083A602 8B 4D 18             mov         ecx,dword ptr [m10]  
0083A605 5E                   pop         esi  
0083A606 5B                   pop         ebx  
0083A607 03 01                add         eax,dword ptr [ecx]  
0083A609 8B 4D 38             mov         ecx,dword ptr [d16]  
0083A60C 03 01                add         eax,dword ptr [ecx]  
0083A60E 8B 4D 1C             mov         ecx,dword ptr [m16]  
0083A611 03 01                add         eax,dword ptr [ecx]  
0083A613 8B 4D 3C             mov         ecx,dword ptr [d24]  
0083A616 03 01                add         eax,dword ptr [ecx]  
   884: }
0083A618 5D                   pop         ebp  
0083A619 C3                   ret  

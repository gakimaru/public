  3619: int testOpt09_Type1_After1(dataOpt08_t& data)
  3620: {
00DD17F0 55                   push        ebp  
00DD17F1 8B EC                mov         ebp,esp  
00DD17F3 56                   push        esi  
  3621: 	int sum = 0;
  3622: 	for (int i = static_cast<int>(extentof(data.elems)) - 1; i >= 0; --i)
00DD17F4 8B 75 08             mov         esi,dword ptr [data]  
00DD17F7 33 C0                xor         eax,eax  
00DD17F9 B9 0F 27 00 00       mov         ecx,270Fh  
00DD17FE 33 D2                xor         edx,edx  
  3623: 	{
  3624: 		sum += data.elems[i].value;
00DD1800 03 04 8E             add         eax,dword ptr [esi+ecx*4]  
00DD1803 03 54 8E FC          add         edx,dword ptr [esi+ecx*4-4]  
00DD1807 83 E9 02             sub         ecx,2  
00DD180A 79 F4                jns         testOpt09_Type1_After1+10h (0DD1800h)  
00DD180C 03 C2                add         eax,edx  
00DD180E 5E                   pop         esi  
  3625: 	}
  3626: 	return sum;
  3627: }
00DD180F 5D                   pop         ebp  
00DD1810 C3                   ret  

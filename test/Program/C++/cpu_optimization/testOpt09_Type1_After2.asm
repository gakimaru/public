  3630: int testOpt09_Type1_After2(dataOpt08_t& data)
  3631: {
00DD1820 55                   push        ebp  
00DD1821 8B EC                mov         ebp,esp  
  3632: 	int sum = 0;
  3633: 	const dataOpt08_t::elem_t* elem_end = data.elems + extentof(data.elems);
00DD1823 8B 45 08             mov         eax,dword ptr [data]  
00DD1826 33 D2                xor         edx,edx  
00DD1828 53                   push        ebx  
00DD1829 56                   push        esi  
00DD182A 57                   push        edi  
00DD182B 8D 98 40 9C 00 00    lea         ebx,[eax+9C40h]  
00DD1831 33 F6                xor         esi,esi  
00DD1833 33 FF                xor         edi,edi  
00DD1835 3B C3                cmp         eax,ebx  
00DD1837 73 33                jae         testOpt09_Type1_After2+4Ch (0DD186Ch)  
  3634: 	for (const dataOpt08_t::elem_t* elem = data.elems; elem < elem_end; ++elem)
00DD1839 8B CB                mov         ecx,ebx  
00DD183B 2B C8                sub         ecx,eax  
00DD183D 83 C1 03             add         ecx,3  
00DD1840 83 E1 FC             and         ecx,0FFFFFFFCh  
  3634: 	for (const dataOpt08_t::elem_t* elem = data.elems; elem < elem_end; ++elem)
00DD1843 83 F9 08             cmp         ecx,8  
00DD1846 72 14                jb          testOpt09_Type1_After2+3Ch (0DD185Ch)  
00DD1848 8D 4B FC             lea         ecx,[ebx-4]  
00DD184B EB 03                jmp         testOpt09_Type1_After2+30h (0DD1850h)  
00DD184D 8D 49 00             lea         ecx,[ecx]  
  3635: 	{
  3636: 		sum += elem->value;
00DD1850 03 10                add         edx,dword ptr [eax]  
00DD1852 03 70 04             add         esi,dword ptr [eax+4]  
00DD1855 83 C0 08             add         eax,8  
00DD1858 3B C1                cmp         eax,ecx  
00DD185A 72 F4                jb          testOpt09_Type1_After2+30h (0DD1850h)  
  3634: 	for (const dataOpt08_t::elem_t* elem = data.elems; elem < elem_end; ++elem)
00DD185C 3B C3                cmp         eax,ebx  
00DD185E 73 02                jae         testOpt09_Type1_After2+42h (0DD1862h)  
  3635: 	{
  3636: 		sum += elem->value;
00DD1860 8B 38                mov         edi,dword ptr [eax]  
00DD1862 8D 04 16             lea         eax,[esi+edx]  
00DD1865 03 C7                add         eax,edi  
00DD1867 5F                   pop         edi  
00DD1868 5E                   pop         esi  
00DD1869 5B                   pop         ebx  
  3639: }
00DD186A 5D                   pop         ebp  
00DD186B C3                   ret  
  3637: 	}
  3638: 	return sum;
00DD186C 8B C7                mov         eax,edi  
00DD186E 5F                   pop         edi  
00DD186F 5E                   pop         esi  
00DD1870 5B                   pop         ebx  
  3639: }
00DD1871 5D                   pop         ebp  
00DD1872 C3                   ret  

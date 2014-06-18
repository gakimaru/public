  3642: int testOpt09_Type1_After3(dataOpt08_t& data)
  3643: {
00111880 55                   push        ebp  
00111881 8B EC                mov         ebp,esp  
  3644: 	int sum = 0;
  3645: 	const dataOpt08_t::elem_t* elem_end = data.elems + extentof(data.elems);
00111883 8B 4D 08             mov         ecx,dword ptr [data]  
00111886 33 C0                xor         eax,eax  
00111888 8D 91 40 9C 00 00    lea         edx,[ecx+9C40h]  
  3646: 	for (const dataOpt08_t::elem_t* elem = data.elems; elem < elem_end;)
0011188E 3B CA                cmp         ecx,edx  
00111890 73 0C                jae         testOpt09_Type1_After3+1Eh (011189Eh)  
  3647: 	{
  3648: 		sum += elem->value; ++elem;
00111892 03 01                add         eax,dword ptr [ecx]  
  3649: 		sum += elem->value; ++elem;
00111894 03 41 04             add         eax,dword ptr [ecx+4]  
00111897 83 C1 08             add         ecx,8  
0011189A 3B CA                cmp         ecx,edx  
0011189C 72 F4                jb          testOpt09_Type1_After3+12h (0111892h)  
  3650: 	}
  3651: 	return sum;
  3652: }
0011189E 5D                   pop         ebp  
0011189F C3                   ret  

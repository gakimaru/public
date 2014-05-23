  3670: int testOpt09_Type1_After5(dataOpt08_t& data)
  3671: {
001118E0 55                   push        ebp  
001118E1 8B EC                mov         ebp,esp  
  3672: 	int sum = 0;
  3673: 	const dataOpt08_t::elem_t* elem_end = data.elems + extentof(data.elems);
001118E3 8B 4D 08             mov         ecx,dword ptr [data]  
001118E6 33 C0                xor         eax,eax  
001118E8 8D 91 40 9C 00 00    lea         edx,[ecx+9C40h]  
  3674: 	for (const dataOpt08_t::elem_t* elem = data.elems; elem < elem_end;)
001118EE 3B CA                cmp         ecx,edx  
001118F0 73 24                jae         testOpt09_Type1_After5+36h (0111916h)  
  3675: 	{
  3676: 		sum += elem->value; ++elem;
001118F2 03 01                add         eax,dword ptr [ecx]  
  3677: 		sum += elem->value; ++elem;
001118F4 03 41 04             add         eax,dword ptr [ecx+4]  
  3678: 		sum += elem->value; ++elem;
001118F7 03 41 08             add         eax,dword ptr [ecx+8]  
  3679: 		sum += elem->value; ++elem;
001118FA 03 41 0C             add         eax,dword ptr [ecx+0Ch]  
  3680: 		sum += elem->value; ++elem;
001118FD 03 41 10             add         eax,dword ptr [ecx+10h]  
  3681: 		sum += elem->value; ++elem;
00111900 03 41 14             add         eax,dword ptr [ecx+14h]  
  3682: 		sum += elem->value; ++elem;
00111903 03 41 18             add         eax,dword ptr [ecx+18h]  
  3683: 		sum += elem->value; ++elem;
00111906 03 41 1C             add         eax,dword ptr [ecx+1Ch]  
  3684: 		sum += elem->value; ++elem;
00111909 03 41 20             add         eax,dword ptr [ecx+20h]  
  3685: 		sum += elem->value; ++elem;
0011190C 03 41 24             add         eax,dword ptr [ecx+24h]  
  3685: 		sum += elem->value; ++elem;
0011190F 83 C1 28             add         ecx,28h  
00111912 3B CA                cmp         ecx,edx  
00111914 72 DC                jb          testOpt09_Type1_After5+12h (01118F2h)  
  3686: 	}
  3687: 	return sum;
  3688: }
00111916 5D                   pop         ebp  
00111917 C3                   ret  

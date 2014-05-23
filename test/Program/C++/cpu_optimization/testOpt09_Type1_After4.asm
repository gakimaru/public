  3655: int testOpt09_Type1_After4(dataOpt08_t& data)
  3656: {
001118A0 55                   push        ebp  
001118A1 8B EC                mov         ebp,esp  
  3658: 	const dataOpt08_t::elem_t* elem_end = data.elems + extentof(data.elems);
001118A3 8B 55 08             mov         edx,dword ptr [data]  
001118A6 33 C0                xor         eax,eax  
001118A8 56                   push        esi  
001118A9 8D B2 40 9C 00 00    lea         esi,[edx+9C40h]  
  3659: 	for (const dataOpt08_t::elem_t* elem = data.elems; elem < elem_end;)
001118AF 3B D6                cmp         edx,esi  
001118B1 73 21                jae         testOpt09_Type1_After4+34h (01118D4h)  
  3657: 	int sum = 0;
001118B3 2B F2                sub         esi,edx  
001118B5 8D 4A 08             lea         ecx,[edx+8]  
001118B8 4E                   dec         esi  
001118B9 C1 EE 04             shr         esi,4  
001118BC 46                   inc         esi  
001118BD 8D 49 00             lea         ecx,[ecx]  
  3660: 	{
  3661: 		sum += elem->value; ++elem;
001118C0 8B 51 F8             mov         edx,dword ptr [ecx-8]  
001118C3 8D 49 10             lea         ecx,[ecx+10h]  
  3660: 	{
  3661: 		sum += elem->value; ++elem;
001118C6 03 51 EC             add         edx,dword ptr [ecx-14h]  
001118C9 03 51 F4             add         edx,dword ptr [ecx-0Ch]  
001118CC 03 51 F0             add         edx,dword ptr [ecx-10h]  
001118CF 03 C2                add         eax,edx  
001118D1 4E                   dec         esi  
001118D2 75 EC                jne         testOpt09_Type1_After4+20h (01118C0h)  
001118D4 5E                   pop         esi  
  3662: 		sum += elem->value; ++elem;
  3663: 		sum += elem->value; ++elem;
  3664: 		sum += elem->value; ++elem;
  3665: 	}
  3666: 	return sum;
  3667: }
001118D5 5D                   pop         ebp  
001118D6 C3                   ret  

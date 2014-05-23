  3608: int testOpt09_Type1_Before(dataOpt08_t& data)
  3609: {
00DD1940 55                   push        ebp  
00DD1941 8B EC                mov         ebp,esp  
  3610: 	int sum = 0;
  3611: 	for (int i = 0; i < static_cast<int>(extentof(data.elems)); ++i)
00DD1943 8B 45 08             mov         eax,dword ptr [data]  
00DD1946 0F 57 E4             xorps       xmm4,xmm4  
00DD1949 83 C0 08             add         eax,8  
00DD194C B9 C4 09 00 00       mov         ecx,9C4h  
  3612: 	{
  3613: 		sum += data.elems[i].value;
00DD1951 66 0F 6E 50 04       movd        xmm2,dword ptr [eax+4]  
00DD1956 8D 40 10             lea         eax,[eax+10h]  
00DD1959 66 0F 6E 40 F0       movd        xmm0,dword ptr [eax-10h]  
00DD195E 66 0F 6E 48 EC       movd        xmm1,dword ptr [eax-14h]  
00DD1963 66 0F 6E 58 E8       movd        xmm3,dword ptr [eax-18h]  
00DD1968 66 0F 62 D8          punpckldq   xmm3,xmm0  
00DD196C 66 0F 62 CA          punpckldq   xmm1,xmm2  
00DD1970 66 0F 62 D9          punpckldq   xmm3,xmm1  
00DD1974 66 0F FE E3          paddd       xmm4,xmm3  
00DD1978 49                   dec         ecx  
  3612: 	{
  3613: 		sum += data.elems[i].value;
00DD1979 75 D6                jne         testOpt09_Type1_Before+11h (0DD1951h)  
00DD197B 66 0F 6F C4          movdqa      xmm0,xmm4  
00DD197F 66 0F 73 D8 08       psrldq      xmm0,8  
00DD1984 66 0F FE E0          paddd       xmm4,xmm0  
00DD1988 66 0F 6F C4          movdqa      xmm0,xmm4  
00DD198C 66 0F 73 D8 04       psrldq      xmm0,4  
00DD1991 66 0F FE E0          paddd       xmm4,xmm0  
00DD1995 66 0F 7E E0          movd        eax,xmm4  
  3614: 	}
  3615: 	return sum;
  3616: }
00DD1999 5D                   pop         ebp  
00DD199A C3                   ret  

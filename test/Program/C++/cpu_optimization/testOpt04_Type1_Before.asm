   707: //【タイプ１】最適化前
   708: //※定数による除算
   709: float testOpt04_Type1_Before(const float value)
   710: {
0023A0B0 55                   push        ebp  
0023A0B1 8B EC                mov         ebp,esp  
   711: 	return value / 1.2f;
0023A0B3 F3 0F 10 45 08       movss       xmm0,dword ptr [value]  
0023A0B8 F3 0F 5E 05 80 C6 24 00 divss       xmm0,dword ptr ds:[24C680h]  
0023A0C0 F3 0F 11 45 08       movss       dword ptr [value],xmm0  
0023A0C5 D9 45 08             fld         dword ptr [value]  
   712: }
0023A0C8 5D                   pop         ebp  
0023A0C9 C3                   ret  

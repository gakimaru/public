   714: //yƒ^ƒCƒv‚PzÅ“K‰»Œã
   715: //¦’è”‚É‚æ‚éœZ‚ğæZ‚É•ÏX
   716: float testOpt04_Type1_After(const float value)
   717: {
0023A090 55                   push        ebp  
0023A091 8B EC                mov         ebp,esp  
   718: 	return value * (1.f / 1.2f);
0023A093 F3 0F 10 45 08       movss       xmm0,dword ptr [value]  
0023A098 F3 0F 59 05 7C C6 24 00 mulss       xmm0,dword ptr ds:[24C67Ch]  
0023A0A0 F3 0F 11 45 08       movss       dword ptr [value],xmm0  
0023A0A5 D9 45 08             fld         dword ptr [value]  
   719: }
0023A0A8 5D                   pop         ebp  
0023A0A9 C3                   ret  

   721: //yƒ^ƒCƒv‚QzÅ“K‰»‘O
   722: //¦•Ï”‚É‚æ‚éœZ
   723: float testOpt04_Type2_Before(const float value, const float div)
   724: {
0023A0F0 55                   push        ebp  
0023A0F1 8B EC                mov         ebp,esp  
   725: 	return value / div;
0023A0F3 F3 0F 10 45 08       movss       xmm0,dword ptr [value]  
0023A0F8 F3 0F 5E 45 0C       divss       xmm0,dword ptr [div]  
0023A0FD F3 0F 11 45 08       movss       dword ptr [value],xmm0  
0023A102 D9 45 08             fld         dword ptr [value]  
   726: }
0023A105 5D                   pop         ebp  
0023A106 C3                   ret  

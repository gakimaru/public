   728: //�y�^�C�v�Q�z�œK����
   729: //���ϐ��ɂ�鏜�Z����Z�ɕύX�i�������A�Ăяo�����ŏ�Z�ɓK������l�ŌĂяo���K�v������j
   730: float testOpt04_Type2_After(const float value, const float mul)
   731: {
0023A0D0 55                   push        ebp  
0023A0D1 8B EC                mov         ebp,esp  
   732: 	return value * mul;
0023A0D3 F3 0F 10 45 08       movss       xmm0,dword ptr [value]  
0023A0D8 F3 0F 59 45 0C       mulss       xmm0,dword ptr [mul]  
0023A0DD F3 0F 11 45 08       movss       dword ptr [value],xmm0  
0023A0E2 D9 45 08             fld         dword ptr [value]  
   733: }
0023A0E5 5D                   pop         ebp  
0023A0E6 C3                   ret  

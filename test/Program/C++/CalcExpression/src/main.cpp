#include <stdio.h>
#include <stdlib.h>

//�Q�[���f�[�^��`
struct T_GAME_DATA_DECL
{
	//�Q�[���f�[�^�\���̒�`
	struct STRUCT
	{
		//�Q�[���f�[�^�\���̃����o�[��`
		struct MEMBER
		{
			unsigned int memberNameCrc;	//�����o�[��CRC
			unsigned int dataNameCrc;	//�\���̖�CRC�@���^��� = struct �̏ꍇ�Ɏw��B
			unsigned int baseType : 3;	//�^��ʁ@��0 = int, 1 = float, 2 = dec, 3 = bool, 4 = str�A
			//�@�@�@�@�@5 = expr, 6 = ptr, 7 = struct�B
			unsigned int isUnsigned : 1;	//���������^���H�@���^��� = int �̎������w��B
			unsigned int size : 4;		//�^�̃T�C�Y�@��int �̏ꍇ�́A1,2,4,8 �̂����ꂩ�B
			//�@�@�@�@�@�@�@float �̏ꍇ�́A2,4,8 �̂����ꂩ�B
			//�@�@�@�@�@�@�@dec �̏ꍇ�� 2,4,8 �̂����ꂩ�B
			//�@�@�@�@�@�@�@bool �̏ꍇ�� 1�B
			//�@�@�@�@�@�@�@str / expr / ptr /struct �̏ꍇ�� 0�B
			unsigned int isVariableArray : 1;//�s�蒷�z�񂩁H�@��true �ŕs�蒷�z��B���̎��A�����o�[�̎��ۂ�
			//�@�@�@�@�@�@�@�@�@�@�f�[�^�^�̓|�C���^�[�ƂȂ�B
			unsigned int arraySize : 16;	//�z��v�f���@���z��łȂ�����s�蒷�̎��� 0�B
		};

		unsigned int structNameCrc;	//�\���̖�CRC
		unsigned short membersNum;	//�\���̃����o�[��
		MEMBER* members;			//�\���̃����o�[��`�̎Q��
	};

	unsigned int formatNameCrc;	//�f�[�^�t�H�[�}�b�g��CRC
	unsigned short majorVer;		//�f�[�^�t�H�[�}�b�g���W���[�o�[�W����
	unsigned short minorVer;		//�f�[�^�t�H�[�}�b�g�}�C�i�[�o�[�W����
	unsigned char ptrSize;		//�|�C���^�[�T�C�Y(4 or 8)
	unsigned short structsNum;	//�\���̐�
	STRUCT* structs;			//�\���̒�`�̎Q��
};

namespace charaDataDecl
{

	//�L�����p�����[�^�\����`
	//Name: CharaData
	//Version: 1.0
	//Update: 204.1.10 12:34:56

	//�f�[�^�\����`
	static const int s_structMembersNum = 9 + 4 + 2;
	static T_GAME_DATA_DECL::STRUCT::MEMBER s_structMembers[s_structMembersNum] =
	{
		//T_CHARA
		{ 0xe66c3671, 0x00000000, 0, true, 4, false, 0 },	//����ID:�hid�h:crc
		{ 0xab8a01a0, 0x00000000, 0, false, 1, false, 0 },	//��:�hpower�h:i8
		{ 0x9c504212, 0x00000000, 0, false, 1, false, 0 },	//�A�r���e�B(Num):�habiriliesNum�h:i8
		{ 0x9ec9ce32, 0x00000000, 0, false, 2, false, 0 },	//�Œ�l:�hfixed�h:i16
		{ 0x5e237e06, 0x00000000, 4, false, 0, false, 0 },	//���O:�hname�h:str
		{ 0xbdd68843, 0x00000000, 5, false, 0, false, 0 },	//�L��������:�hcondition�h:expr
		{ 0x0ad84385, 0x00000000, 1, false, 1, false, 10 },	//�ϐ�:�htol�h:f32
		{ 0xb8388da4, 0x00000000, 0, true, 4, true, 0 },	//�A�r���e�B:�habilities�h:u32*
		{ 0xa4fa7c89, 0x22a2e1dc, 7, false, 0, false, 0 },	//�p�����[�^:�hparam�h:T_PARAM
		//T_PARAM
		{ 0x27677c27, 0x00000000, 0, false, 2, false, 0 },	//�U����:�hatk�h:i16
		{ 0x0cc4e161, 0x00000000, 0, false, 2, false, 0 },	//�h���:�hdef�h:i16
		{ 0xcd1415d7, 0x00000000, 0, false, 4, false, 0 },	//����\��(Num):�hspecialsNum�h:i32
		{ 0x4c6b3fe3, 0x84f96e44, 7, false, 0, true, 0 },	//����\��:�hspecials�h:T_SPECIAL_PARAM*
		//T_SPECIAL_PARAM
		{ 0x1b7cbdfb, 0x00000000, 0, true, 4, false, 0 },	//��:�hdark�h:u32
		{ 0x076291bf, 0x00000000, 0, true, 4, false, 0 },	//��:�hshine�h:u32
	};
	static const int s_structsNum = 3;
	static T_GAME_DATA_DECL::STRUCT s_structs[s_structsNum] =
	{
		{ 0x0ed35394, 9, &s_structMembers[0] },	//T_CHARA
		{ 0x22a2e1dc, 4, &s_structMembers[9] },	//T_PARAM
		{ 0x84f96e44, 2, &s_structMembers[13] },	//T_SPECIAL_PARAM
	};
	static T_GAME_DATA_DECL s_decl =
	{
		0xe1e4a645,	//�f�[�^�t�H�[�}�b�g��CRC�FCharaData
		1,		//�f�[�^�t�H�[�}�b�g���W���[�o�[�W����
		0,		//�f�[�^�t�H�[�}�b�g�}�C�i�[�o�[�W����
		8,		//�|�C���^�[�T�C�Y
		s_structsNum,//�\���ΐ�
		&s_structs[0]//�\���̒�`�̎Q��
	};

	//�f�[�^�\����`�擾�֐�
	const T_GAME_DATA_DECL* getGameDataDecl(){ return &s_decl; }
}

int sub()
{
	printf("    -> Called!\n");
	return 1;
}

#define TEST(expr) { printf("expr=\"%s\"\n", #expr); const int ret = (expr); printf("  result=%d\n", ret); }

int main(const int argc, const char* argv[])
{
	const T_GAME_DATA_DECL* o = charaDataDecl::getGameDataDecl();

	TEST(1);
	TEST(1 + 1);
	
	TEST(true && sub());
	TEST(false && sub());
	TEST(true || sub());
	TEST(false || sub());
	TEST(sub() && true);
	TEST(sub() && false);
	TEST(sub() || true);
	TEST(sub() || false);
	TEST(true ? sub() : 999);
	TEST(false ? sub() : 999);
	TEST(true ? 999 : sub());
	TEST(false ? 999 : sub());
	TEST(0xffffffff & sub());
	TEST(0x00000000 & sub());
	TEST(0xffffffff | sub());
	TEST(0x00000000 | sub());
	TEST(sub() & 0xffffffff);
	TEST(sub() & 0x00000000);
	TEST(sub() | 0xffffffff);
	TEST(sub() | 0x00000000);
	TEST(1 * sub());
	TEST(0 * sub());
	TEST(1 / sub());
	TEST(0 / sub());
	TEST(sub() * 1);
	TEST(sub() * 0);
	TEST(sub() / 1);
//	TEST(sub() / 0);
	
//�y���ʁz
//	expr = "1"
//	  result = 1
//	expr = "1 + 1"
//	  result = 2
//	expr = "true && sub()"
//	    ->Called!
//	  result = 1
//	expr = "false && sub()"
//	  result = 0
//	expr = "true || sub()"
//	  result = 1
//	expr = "false || sub()"
//	    ->Called!
//	  result = 1
//	expr = "sub() && true"
//	    ->Called!
//	  result = 1
//	expr = "sub() && false"
//	    ->Called!
//	  result = 0
//	expr = "sub() || true"
//	    ->Called!
//	  result = 1
//	expr = "sub() || false"
//	    ->Called!
//	  result = 1
//	expr = "true ? sub() : 999"
//	    ->Called!
//	  result = 1
//	expr = "false ? sub() : 999"
//	  result = 999
//	expr = "true ? 999 : sub()"
//	  result = 999
//	expr = "false ? 999 : sub()"
//	    ->Called!
//	  result = 1
//	expr = "0xffffffff & sub()"
//	    ->Called!
//	  result = 1
//	expr = "0x00000000 & sub()"
//	    ->Called!
//	  result = 0
//	expr = "0xffffffff | sub()"
//	    ->Called!
//	  result = -1
//	expr = "0x00000000 | sub()"
//	    ->Called!
//	  result = 1
//	expr = "sub() & 0xffffffff"
//	    ->Called!
//	  result = 1
//	expr = "sub() & 0x00000000"
//	    ->Called!
//	  result = 0
//	expr = "sub() | 0xffffffff"
//	    ->Called!
//	  result = -1
//	expr = "sub() | 0x00000000"
//	    ->Called!
//	  result = 1
//	expr = "1 * sub()"
//	    ->Called!
//	  result = 1
//	expr = "0 * sub()"
//	    ->Called!
//	  result = 0
//	expr = "1 / sub()"
//	    ->Called!
//	  result = 1
//	expr = "0 / sub()"
//	    ->Called!
//	  result = 0
//	expr = "sub() * 1"
//	    ->Called!
//	  result = 1
//	expr = "sub() * 0"
//	    ->Called!
//	  result = 0
//	expr = "sub() / 1"
//	    ->Called!
//	  result = 1
	
	return EXIT_FAILURE;
}

// End of file


#include <stdio.h>
#include <stdlib.h>

//�Q�[���f�[�^��`
struct T_GDBIN_DECL
{
	//�^���
	struct TYPE_INFO
	{
		unsigned int dataNameCrc;	//�\���̖�CRC�@���^��� = struct �̏ꍇ�Ɏw��B
		unsigned char baseType : 3;	//�^��ʁ@��0 = int, 1 = float, 2 = dec, 3 = bool, 4 = str�A
		//�@�@�@�@�@5 = expr, 6 = ptr, 7 = struct�B
		unsigned char isUnsigned : 1;	//���������^���H�@���^��� = int �̏ꍇ�̂ݎw��B
		unsigned char size : 4;		//�^�̃T�C�Y�@��int �̏ꍇ�́A1,2,4,8 �̂����ꂩ�B
		//�@�@�@�@�@�@�@float �̏ꍇ�́A2,4,8 �̂����ꂩ�B
		//�@�@�@�@�@�@�@dec �̏ꍇ�� 2,4,8 �̂����ꂩ�B
		//�@�@�@�@�@�@�@bool �̏ꍇ�� 1�B
		//�@�@�@�@�@�@�@str / expr / ptr /struct �̏ꍇ�� 0�B
		unsigned char padding[3];	//�p�f�B���O�@��0xdb�Ŗ��߂�
	};

	//�Q�[���f�[�^�\���̒�`
	struct STRUCT
	{
		//�Q�[���f�[�^�\���̃����o�[��`
		struct MEMBER
		{
			TYPE_INFO type;			//�^���
			unsigned int memberNameCrc;	//�����o�[��CRC
			unsigned int isVariableArray : 1;//�s�蒷�z�񂩁H�@��true �ŕs�蒷�z��B���̎��A�����o�[�̎��ۂ�
			//�@�@�@�@�@�@�@�@�@�@�f�[�^�^�̓|�C���^�[�ƂȂ�B
			unsigned int arraySize : 31;	//�z��v�f���@���z��łȂ�����s�蒷�̎��� 0�B
		};

		unsigned int structNameCrc;	//�\���̖�CRC
		unsigned short membersNum;	//�\���̃����o�[��
		MEMBER* members;			//�\���̃����o�[��`�̎Q��
	};

	//�s�蒷�f�[�^���
	struct VARIABLE_DATA_INFO
	{
		TYPE_INFO type;			//�^���
		unsigned int recotdSize;	//�s�蒷�f�[�^�̃��R�[�h�T�C�Y�i�P��������̃f�[�^�T�C�Y�j
	};

	unsigned int formatNameCrc;	//�f�[�^�t�H�[�}�b�g��CRC
	unsigned short majorVer;		//�f�[�^�t�H�[�}�b�g���W���[�o�[�W����
	unsigned short minorVer;		//�f�[�^�t�H�[�}�b�g�}�C�i�[�o�[�W����

	unsigned short structsNum;				//�\���̐�
	unsigned short structMembersNum;		//�S�\���̂̑S�����o�[��
	unsigned short variableDataInfosNum;	//�s�蒷�f�[�^���
	unsigned char padding[2];				//�p�f�B���O�@��0xdb�Ŗ��߂�
	
	unsigned int recotdSize;				//��{�\���̂̃��R�[�h�T�C�Y�i�P��������̃f�[�^�T�C�Y�j
	unsigned int primaryKeyNameCrc;			//��L�[�����o�[��CRC
	
	STRUCT* structs;						//�\���̒�`�̎Q��
	VARIABLE_DATA_INFO* variableDataInfos;	//�s�蒷�f�[�^���̎Q��
};

namespace charaDataDecl
{

	//�L�����p�����[�^�\����`
	//Name: CharaData
	//Version: 1.0
	//Update: 204.1.10 12:34:56

	//�f�[�^�\����`

	//�\���̂̃����o�[��`
	static const int s_structMembersNum = 9 + 4 + 2; //�S�\���̂̑S�����o�[��
	static T_GDBIN_DECL::STRUCT::MEMBER s_structMembers[s_structMembersNum] =
	{
		//T_CHARA�\����
		{ { 0x00000000, 0, true, 4, { 0xdb,0xdb,0xdb } }, 0xe66c3671, false, 0 },	//����ID:�hid�h:crc
		{ { 0x00000000, 0, false, 1, { 0xdb,0xdb,0xdb } }, 0xab8a01a0, false, 0 },	//��:�hpower�h:i8
		{ { 0x00000000, 0, false, 1, { 0xdb,0xdb,0xdb } }, 0x9c504212, false, 0 },	//�A�r���e�B(Num):�habiriliesNum�h:i8
		{ { 0x00000000, 0, false, 2, { 0xdb,0xdb,0xdb } }, 0x9ec9ce32, false, 0 },	//�Œ�l:�hfixed�h:i16
		{ { 0x00000000, 4, false, 0, { 0xdb,0xdb,0xdb } }, 0x5e237e06, false, 0 },	//���O:�hname�h:str
		{ { 0x00000000, 5, false, 0, { 0xdb,0xdb,0xdb } }, 0xbdd68843, false, 0 },	//�L��������:�hcondition�h:expr
		{ { 0x00000000, 1, false, 4, { 0xdb,0xdb,0xdb } }, 0x0ad84385, false, 10 },	//�ϐ�:�htol�h:f32[10]
		{ { 0x00000000, 0, true, 4, { 0xdb,0xdb,0xdb } }, 0xb8388da4, true, 0 },	//�A�r���e�B:�habilities�h:u32*
		{ { 0x22a2e1dc, 7, false, 0, { 0xdb,0xdb,0xdb } }, 0xa4fa7c89, false, 0 },	//�p�����[�^:�hparam�h:T_PARAM
		//T_PARAM�\����
		{ { 0x00000000, 0, false, 2, { 0xdb,0xdb,0xdb } }, 0x27677c27, false, 0 },	//�U����:�hatk�h:i16
		{ { 0x00000000, 0, false, 2, { 0xdb,0xdb,0xdb } }, 0x0cc4e161, false, 0 },	//�h���:�hdef�h:i16
		{ { 0x00000000, 0, false, 4, { 0xdb,0xdb,0xdb } }, 0xcd1415d7, false, 0 },	//����\��(Num):�hspecialsNum�h:i32
		{ { 0x84f96e44, 7, false, 0, { 0xdb,0xdb,0xdb } }, 0x4c6b3fe3, true, 0 },	//����\��:�hspecials�h:T_SPECIAL_PARAM*
		//T_SPECIAL_PARAM�\����
		{ { 0x00000000, 0, true, 4, { 0xdb,0xdb,0xdb } }, 0x1b7cbdfb, false, 0 },	//��:�hdark�h:u32
		{ { 0x00000000, 0, true, 4, { 0xdb,0xdb,0xdb } }, 0x076291bf, false, 0 },	//��:�hshine�h:u32
	};

	//�\���̂̒�`
	static const int s_structsNum = 3; //�S�\���̐�
	static T_GDBIN_DECL::STRUCT s_structs[s_structsNum] =
	{
		{ 0x0ed35394, 9, &s_structMembers[0] },	//T_CHARA
		{ 0x22a2e1dc, 4, &s_structMembers[9] },	//T_PARAM
		{ 0x84f96e44, 2, &s_structMembers[13] },	//T_SPECIAL_PARAM
	};

	//�s�蒷�f�[�^���
	static const int s_variableDataInfoNum = 2; //�s�蒷�f�[�^���
	static T_GDBIN_DECL::VARIABLE_DATA_INFO s_variableDataInfos[s_variableDataInfoNum] =
	{
		{ { 0x00000000, 0, true, 4, { 0xdb,0xdb,0xdb } }, 4 },	//u32
		{ { 0x84f96e44, 7, false, 0, { 0xdb,0xdb,0xdb } }, 8 },	//T_SPECIAL_PARAM
	};

	//�t�H�[�}�b�g����`�i�o�[�W�������܂ށj
	static T_GDBIN_DECL s_decl =
	{
		0xe1e4a645,	//�t�H�[�}�b�g��CRC�FCharaData
		1,		//�t�H�[�}�b�g���W���[�o�[�W����
		0,		//�t�H�[�}�b�g�}�C�i�[�o�[�W����

		s_structsNum,			//�\���̐�
		s_structMembersNum,		//�S�\���̂̑S�����o�[��
		s_variableDataInfoNum,	//�s�蒷�f�[�^���
		{ 0xdb,0xdb },			//�p�f�B���O
		
		72,						//��{�\���̂̃��R�[�h�T�C�Y�i�P��������̃f�[�^�T�C�Y�j
		0xe66c3671,				//��L�[�����o�[��CRC�Fid
		
		&s_structs[0],			//�\���̒�`�̎Q��
		&s_variableDataInfos[0]	//�s�蒷�f�[�^���̎Q��
	};

	//�f�[�^�\����`�擾�֐�
	const T_GDBIN_DECL* getDecl(){ return &s_decl; }

}//charaDataDecl

int main(const int argc, const char* argv[])
{
	const T_GDBIN_DECL* decl = charaDataDecl::getDecl();
	printf("Ver=%d.%d\n", decl->majorVer, decl->majorVer);
	return EXIT_SUCCESS;
}

// End of file

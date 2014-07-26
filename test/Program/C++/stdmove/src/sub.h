//���ؗp�\���̂`�F���[�u�I�y���[�^�^���[�u�R���X�g���N�^�Ȃ�
struct type_a
{
	int var;
	type_a& operator=(const type_a& rhs);//�R�s�[�I�y���[�^
	type_a(const type_a& obj);//�R�s�[�R���X�g���N�^
	type_a(const int v);//�R���X�g���N�^
	type_a();//�R���X�g���N�^
	~type_a();//�f�X�g���N�^
};

//���ؗp�\���̂a�F���[�u�I�y���[�^�^���[�u�R���X�g���N�^����
struct type_b
{
	int var;
	type_b& operator=(const type_b& rhs);//�R�s�[�I�y���[�^
	type_b(const type_b& obj);//�R�s�[�R���X�g���N�^
	type_b& operator=(type_b&& rhs);//���[�u�I�y���[�^
	type_b(type_b&& obj);//���[�u�R���X�g���N�^
	type_b(const int v);//�R���X�g���N�^
	type_b();//�R���X�g���N�^
	~type_b();//�f�X�g���N�^
};

//�y�����r�z
//�p�^�[���`�@�F�߂�l�𕁒ʂɕԂ�
type_a getA(const int v);
//�p�^�[���`�A�F�߂�l��std::move()�ŕԂ�
type_a getA_v(const int v);
//�p�^�[���a�@�F�߂�l�𕁒ʂɕԂ�
type_b getB(const int v);
//�p�^�[���a�A�F�߂�l��std::move()�ŕԂ�
type_b getB_v(const int v);

//--------------------------------------------------------------------------------
//���S�Ȏ󂯓n���e�X�g

//Perfectforward�i���S�Ȏ󂯓n���j�e�X�g�p�\����
struct forPerfectForward
{
	int m_val1;
	int m_val2;

	//���[�u�R���X�g���N�^
	forPerfectForward(const forPerfectForward&& obj);
	//�R�s�[�R���X�g���N�^
	forPerfectForward(const forPerfectForward& obj);
	//�R���X�g���N�^�i�����l���E�Ӓl�Q�Ɠn���j
	forPerfectForward(const int&& val1, const int&& val2);
	//�R���X�g���N�^�i�����l���Q�Ɠn���j
	forPerfectForward(const int& val1, const int& val2);
	//�f�t�H���g�R���X�g���N�^
	forPerfectForward();
};
//�������p�֐�
#include <new>//�z�unew
#include <utility>//std::forward()
template<typename... Tx>
void initForPerfectForward(forPerfectForward& obj, Tx&&... args)
{
	new(&obj)forPerfectForward(std::forward<Tx>(args)...);
}

// End of file

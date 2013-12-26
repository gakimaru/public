#include <stdio.h>
#include <stdlib.h>

#include "game_main.h"
#include "unit_test.h"
#include "unit_test_id.h"

//�Q�[�����C���N���X

//�R���X�g���N�^
CGameMain::CGameMain(const int argc, const char* argv[]):
	m_argc(argc),
	m_argv(argv),
	m_initializeResult(EXIT_SUCCESS),
	m_finalizeResult(EXIT_SUCCESS),
	m_mainResult(EXIT_SUCCESS)
{
	printf("- CGameMain::CGameMain()\n");
}

//�f�X�g���N�^
CGameMain::~CGameMain()
{
	printf("- CGameMain::~CGameMain()\n");
}

//����������
int CGameMain::initialize()
{
	printf("- CGameMain::initialize() [BEGIN] ...\n");
	this->m_initializeResult = EXIT_SUCCESS;
	printf("- CGameMain::initialize() [END]\n");
	return this->m_initializeResult;
}

//�I������
int CGameMain::finalize()
{
	printf("- CGameMain::finalize() [BEGIN] ...\n");
	this->m_finalizeResult = EXIT_SUCCESS;
	printf("- CGameMain::finalize() [END]\n");
	return this->m_finalizeResult;
}

//���C������
int CGameMain::main()
{
	printf("- CGameMain::main() [BEGIN] ...\n");

	//�������j�b�g�e�X�g
	//��UT_ENABLED �� UT_AUTO ����`����Ă��鎞�����������L���������
	//�@UT_TARGET_MODULE �� UT_TARGET_GROUP �̒�`�̉e�����󂯂āA���s����郆�j�b�g�e�X�g�����肳���B
	//�@���C�������̍ŏ��Ɏ��s�����悤�ɂ��Ă����B�������Ǘ��Ȃǂ̊�{�I�ȏ������������I������オ�ǂ��B
	//�����j�b�g�e�X�g�̌��ʂɈ�ł��~�X���������� return ����Breturn �l�̓~�X���B
	//�@���� return �l�� main�֐��� return �l�ɂ���B
	//�@����ɂ��Ajenkins �Ȃǂ̃c�[�����烆�j�b�g�e�X�g�̌��ʂ��n���h�����O�ł���B
	UT_RUN_MAIN();
	
#if 1
	//�蓮���j�b�g�e�X�g
	//��UT_ENABLED ����`����Ă��鎞�����������L���������
	//�@�v���O�������̔C�ӂ̏ꏊ����Ăяo����B
	UT_OUTPUT("�蓮���j�b�g�e�X�g:ALL\n");
	UT_RUN_ALL();             //UT_AUTO �Ɩ��֌W�ɑS���W���[���̃e�X�g�����s����}�N��
	UT_OUTPUT("�蓮���j�b�g�e�X�g:MODULE(\"CModuleB\")\n");
	UT_RUN_MODULE("CModuleB");//UT_AUTO �Ɩ��֌W�Ɏw��̃��W���[���̃e�X�g�����s����}�N��
	UT_OUTPUT("�蓮���j�b�g�e�X�g:GROUP(2)\n");
	UT_RUN_GROUP(2);          //UT_AUTO �Ɩ��֌W�Ɏw��̃O���[�v�̃e�X�g�����s����}�N��
	UT_OUTPUT("�蓮���j�b�g�e�X�g:STANDARD\n");
	UT_RUN_STANDARD();        //UT_AUTO �Ɩ��֌W�Ƀ��W���[���̃e�X�g�����s����}�N��
	                          //��UT_TARGET_MODULE �� UT_TARGET_GROUP �̒�`�̉e�����󂯂āA���s����郆�j�b�g�e�X�g�����肳���B
#endif

#if 1
	//�O��̃��j�b�g�e�X�g�̌��ʂ��m�F�^���Z�b�g�^���ʂɊ�Â��ďI��
	UT_OUTPUT("�蓮���j�b�g�e�X�g���ʁFpassed=%d, missed=%d\n", UT_LAST_PASSED_TOTAL(), UT_LAST_MISSED_TOTAL());//�O��̃��j�b�g�e�X�g�̌��ʂ��擾
	UT_RESET_LAST_RESULT();   //�O��̃��j�b�g�e�X�g�̌��ʂ����Z�b�g
	UT_OUTPUT("���ʂ����Z�b�g�Fpassed=%d, missed=%d\n", UT_LAST_PASSED_TOTAL(), UT_LAST_MISSED_TOTAL());
	UT_RETURN_WHEN_MISSED();  //�O��̃��j�b�g�e�X�g�̌��ʂɈ�ł��~�X���������� return ����
	UT_EXIT_WHEN_MISSED();    //�O��̃��j�b�g�e�X�g�̌��ʂɈ�ł��~�X���������� exit ����
	UT_ABORT_WHEN_MISSED();   //�O��̃��j�b�g�e�X�g�̌��ʂɈ�ł��~�X���������� abort ����
	UT_ASSERT_WHEN_MISSED();  //�O��̃��j�b�g�e�X�g�̌��ʂɈ�ł��~�X����������A�T�[�V�����ᔽ�Ƃ���
#endif

#if 1
	//���j�b�g�e�X�g�̃T�|�[�g����
	UT_OUTPUT("UT_SET_OUTPUT_FUNC()�F���s�O\n");
	UT_SET_OUTPUT_FUNC(nullptr); //���j�b�g�e�X�g�̕\���p�֐���ύX����i�^�[�Q�b�g�v���b�g�t�H�[���ɍ��킹���֐��ɂ���Ȃǁj
	                             //���^:int(*UNIT_TEST_OUTPUT_FUNC_P)(const char* fmt, va_list list)
	                             //�@nullptr ���w�肷��ƈ�؉����\������Ȃ��Ȃ�B
	UT_OUTPUT("UT_SET_OUTPUT_FUNC()�F���s��\n");
	UT_WITH_(printf("UT_WITH_()�}�N�����g���ăv�����g\n")); //��UT_WITH_()�}�N�����ɏ����������́AUT_ENABLED �L�����̂ݎ��s�����B
#endif
	
	//�ȉ��A�{���̃Q�[�����C������
	printf("�{���̃Q�[�����C������ ...\n");

	this->m_mainResult = EXIT_SUCCESS;
	printf("- CGameMain::main() [END]\n");
	return this->m_mainResult;
}

// End of file

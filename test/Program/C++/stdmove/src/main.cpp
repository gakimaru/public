#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

#include "sub.h"

//----------------------------------------
//���C��
int main(const int argc, const char* argv[])
{
	//�y�}��z
	printf("- notes -\n");
	printf("[a**]   ... type_a\n");
	printf("[b**]   ... type_b\n");
	printf("[*p*]   ... Initialize by constructor parameter.\n");
	printf("[*s*]   ... Initialize by substitute.\n");
	printf("[**x]   ... Initialize from fixed value.\n");
	printf("[**f]   ... Initialize from function.\n");
	printf("[**v]   ... Initialize from function with std::move.\n");
	printf("[***_v] ... Initialize with std::move.\n");

	{
		printf("\n");
		printf("[fixed value]\n");
		printf("type_a fixed(9999);\n");
		type_a fix(9999);
		{
			printf("\n");
			printf("[apx]\n");
			printf("type_a apx(fix);\n");
			type_a apx(fix);
			printf("apx = fix; (&apx=%p)\n", &apx);
			apx = fix;
			printf("[apx:end]\n");
		}
		{
			printf("\n");
			printf("[apx_v]\n");
			printf("type_a apx_v(std::move(fix));\n");
			type_a apx_v(std::move(fix));
			printf("apx_v = std::move(fix); (&apx_v=%p)\n", &apx_v);
			apx_v = std::move(fix);
			printf("[apx_v:end]\n");
		}
		{
			printf("\n");
			printf("[asx]\n");
			printf("type_a asx = fix;\n");
			type_a asx = fix;
			printf("asx = fix; (&asx=%p)\n", &asx);
			asx = fix;
			printf("[asx:end]\n");
		}
		{
			printf("\n");
			printf("[asx_v]\n");
			printf("type_a asx_v = std::move(fix);\n");
			type_a asx_v = std::move(fix);
			printf("asx_v = std::move(fix); (&asx_v=%p)\n", &asx_v);
			asx_v = std::move(fix);
			printf("[asx_v:end]\n");
		}
		printf("[fixed value:end]\n");
	}
	{
		printf("\n");
		printf("[apf]\n");
		printf("type_a apf(getA(11100));\n");
		type_a apf(getA(11100));
		printf("apf = getA(11101); (&apf=%p)\n", &apf);
		apf = getA(11101);
		printf("[apf:end]\n");
	}
	{
		printf("\n");
		printf("[apf_v]\n");
		printf("type_a apf_v(std::move(getA(11110)));\n");
		type_a apf_v(std::move(getA(11110)));
		printf("apf_v = std::move(getA(11111)); (&apf_v=%p)\n", &apf_v);
		apf_v = std::move(getA(11111));
		printf("[apf_v:end]\n");
	}
	{
		printf("\n");
		printf("[asf]\n");
		printf("type_a asf = getA(12100);\n");
		type_a asf = getA(12100);
		printf("asf = getA(12101); (&asf=%p)\n", &asf);
		asf = getA(12101);
		printf("[asf:end]\n");
	}
	{
		printf("\n");
		printf("[asf_v]\n");
		printf("type_a asf_v = std::move(getA(12110));\n");
		type_a asf_v = std::move(getA(12110));
		printf("asf_v = std::move(getA(12111)); (&asf_v=%p)\n", &asf_v);
		asf_v = std::move(getA(12111));
		printf("[asf_v:end]\n");
	}
	{
		printf("\n");
		printf("[apv]\n");
		printf("type_a apv(getA_v(11200));\n");
		type_a apv(getA_v(11200));
		printf("apv = getA_v(11201); (&apv=%p)\n", &apv);
		apv = getA_v(11201);
		printf("[apv:end]\n");
	}
	{
		printf("\n");
		printf("[apv_v]\n");
		printf("type_a apv_v(std::move(getA_v(11210)));\n");
		type_a apv_v(std::move(getA_v(11210)));
		printf("apv_v = std::move(getA_v(11211)); (&apv_v=%p)\n", &apv_v);
		apv_v = std::move(getA_v(11211));
		printf("[apv_v:end]\n");
	}
	{
		printf("\n");
		printf("[asv]\n");
		printf("type_a asv = getA_v(12200);\n");
		type_a asv = getA_v(12200);
		printf("asv = getA_v(12201); (&asv=%p)\n", &asv);
		asv = getA_v(12201);
		printf("[asv:end]\n");
	}
	{
		printf("\n");
		printf("[asv_v]\n");
		printf("type_a asv_v = std::move(getA_v(12210));\n");
		type_a asv_v = std::move(getA_v(12210));
		printf("asv_v = std::move(getA_v(12211)); (&asv_v=%p)\n", &asv_v);
		asv_v = std::move(getA_v(12211));
		printf("[asv_v:end]\n");
	}
	{
		printf("\n");
		printf("[fixed value]\n");
		printf("type_b fixed(9999);\n");
		type_b fix(9999);
		{
			printf("\n");
			printf("[bpx]\n");
			printf("type_b bpx(fix);\n");
			type_b bpx(fix);
			printf("bpx = fix; (&apxbpxp)\n", &bpx);
			bpx = fix;
			printf("[bpx:end]\n");
		}
		{
			printf("\n");
			printf("[bpx_v]\n");
			printf("type_b bpx_v(std::move(fix));\n");
			type_b bpx_v(std::move(fix));
			printf("bpx_v = std::move(fix); (&bpx_v=%p)\n", &bpx_v);
			bpx_v = std::move(fix);
			printf("[bpx_v:end]\n");
		}
		{
			printf("\n");
			printf("[bsx]\n");
			printf("type_b bsx = fix;\n");
			type_b bsx = fix;
			printf("bsx = fix; (&bsx=%p)\n", &bsx);
			bsx = fix;
			printf("[bsx:end]\n");
		}
		{
			printf("\n");
			printf("[bsx_v]\n");
			printf("type_b bsx_v = std::move(fix);\n");
			type_b bsx_v = std::move(fix);
			printf("bsx_v = std::move(fix); (&bsx_v=%p)\n", &bsx_v);
			bsx_v = std::move(fix);
			printf("[bsx_v:end]\n");
		}
		printf("[fixed value:end]\n");
	}
	{
		printf("\n");
		printf("[bpf]\n");
		printf("type_b bpf(getB(21100));\n");
		type_b bpf(getB(21100));
		printf("bpf = getB(21101); (&bpf=%p)\n", &bpf);
		bpf = getB(21101);
		printf("[bpf:end]\n");
	}
	{
		printf("\n");
		printf("[bpf_v]\n");
		printf("type_b bpf_v(std::move(getB(21110)));\n");
		type_b bpf_v(std::move(getB(21110)));
		printf("bpf_v = std::move(getB(21111)); (&bpf_v=%p)\n", &bpf_v);
		bpf_v = std::move(getB(21111));
		printf("[bpf_v:end]\n");
	}
	{
		printf("\n");
		printf("[bsf]\n");
		printf("type_b bsf = getB(22100);\n");
		type_b bsf = getB(22100);
		printf("bsf = getB(22101); (&bsf=%p)\n", &bsf);
		bsf = getB(22101);
		printf("[bsf:end]\n");
	}
	{
		printf("\n");
		printf("[bsf_v]\n");
		printf("type_b bsf_v = std::move(getB(22110));\n");
		type_b bsf_v = std::move(getB(22110));
		printf("bsf_v = std::move(getB(22111)); (&bsf_v=%p)\n", &bsf_v);
		bsf_v = std::move(getB(22111));
		printf("[bsf_v:end]\n");
	}
	{
		printf("\n");
		printf("[bpv]\n");
		printf("type_b bpv(getB_v(21200));\n");
		type_b bpv(getB_v(21200));
		printf("bpv = getB_v(21201); (&bpv=%p)\n", &bpv);
		bpv = getB_v(21201);
		printf("[bpv:end]\n");
	}
	{
		printf("\n");
		printf("[bpv_v]\n");
		printf("type_b bpv_v(std::move(getB_v(21210)));\n");
		type_b bpv_v(std::move(getB_v(21210)));
		printf("bpv_v = std::move(getB_v(21211)); (&bpv_v=%p)\n", &bpv_v);
		bpv_v = std::move(getB_v(21211));
		printf("[bpv_v:end]\n");
	}
	{
		printf("\n");
		printf("[bsv]\n");
		printf("type_b bsv = getB_v(22200);\n");
		type_b bsv = getB_v(22200);
		printf("bsv = getB_v(22201); (&bsv=%p)\n", &bsv);
		bsv = getB_v(22201);
		printf("[bsv:end]\n");
	}
	{
		printf("\n");
		printf("[bsv_v]\n");
		printf("type_b bsv_v = std::move(getB_v(22210));\n");
		type_b bsv_v = std::move(getB_v(22210));
		printf("bsv_v = std::move(getB_v(22211)); (&bsv_v=%p)\n", &bsv_v);
		bsv_v = std::move(getB_v(22211));
		printf("[bsv_v:end]\n");
	}
	
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("[ Test for perfect-forwarding (std::forward) ]\n");
	printf("\n");

	{
		int fixed_val = 1;
		auto right_val = []() -> int { return 2; };
		forPerfectForward obj1;
		forPerfectForward obj2;
		initForPerfectForward(obj1, fixed_val, fixed_val);
		initForPerfectForward(obj1, right_val(), right_val());
		initForPerfectForward(obj1, fixed_val, right_val());
		initForPerfectForward(obj1, right_val(), fixed_val);
		initForPerfectForward(obj1, 3, 4);
		initForPerfectForward(obj2, obj1);
		initForPerfectForward(obj2, std::move(obj1));
	}

	printf("\n");
	printf("[end]\n");
	
	return EXIT_SUCCESS;
}

//�y���،��ʁz
//�p�^�[���@�F�߂�l�𕁒ʂɕԂ�
//    �R���p�C������эœK���I�v�V�����ɂ��A���L�Q�p�^�[���̂����ꂩ�̓���ɂȂ邱�Ƃ��m�F�B
//
//    �E����p�^�[���P�F�R���p�C���̍œK���������Ȃ�
//
//        type obj = func();//�Ăяo�����̏���
//
//        type func()//�I�u�W�F�N�g�̎��̂�Ԃ��֐�
//        {
//            type new_data;//���֐����̃��[�J���ϐ��@���R���X�g���N�^�Ăяo��
//            new_data.m = 123;
//            return new_data;//�Ăяo������ obj �̃��[�u�R���X�g���N�^�Ăяo���ƁAnew_data�̃f�X�g���N�^�Ăяo��������
//        }
//
//        ���ʁA�R���X�g���N�^�Ăяo����2��ƃf�X�g���N�^�Ăяo����1�񔭐�����B
//        �߂�l�͊�{�I�ɉE�Ӓl�����̂��߁A���[�u�R���X�g���N�^������ΗD��I�ɌĂяo�����B
//        ���[�u�R���X�g���N�^���Ȃ���΃R�s�[�R���X�g���N�^���Ăяo�����B
//
//    �E����p�^�[���Q�F�R���p�C���̍œK��������
//
//        type obj = func();//�Ăяo�����̏���
//
//        type func()//�I�u�W�F�N�g�̎��̂�Ԃ��֐�
//        {
//            type new_data;//���֐����̃��[�J���ϐ��Ɍ����邪�A���ۂɂ�obj�̎Q�Ɓ@���R���X�g���N�^�Ăяo��
//            new_data.m = 123;
//            return new_data;
//        }
//
//        ���ʁA�R���X�g���N�^��I�y���[�^�̌Ăяo���́A�֐����� new_data �𐶐��������̂݁B
//        �p�����[�^�ŎQ�Ɠn������̂Ɠ��������ɂȂ�B
//        
//�p�^�[���A�F�߂�l��std::move()�ŕԂ�
//    �R���p�C������эœK���I�v�V�����Ɋ֌W�Ȃ��A��ɏ�L�u����p�^�[���P�v�̋����ƂȂ邱�Ƃ��m�F�B

// End of file

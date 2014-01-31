#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <array>

#include <cstdint>
#include <random>

//�J�X�^������������
namespace custom
{
	//���`�����@ �v�Z���i�Q�����j�FX = ( A * X{�O��̒l} + B) % M
	static const int SEED_INIT = 1;  //�����V�[�h
	static const int A = 1103515245; //������A��B�̒l���ǂ���
	static const int B = 12345;      //�@�ϓ����z���Ǝ��������ǂ��Ȃ�
//	static const int M = 0x800000000;//32�r�b�g�S�悪�Ώ�
	static       int X = SEED_INIT;  //�O��̒l�i�V�[�h�j
	static const int MAX = 0x7fff;   //�����̍ő�l

	//�������擾
	int rand()
	{
		X = (A * X + B);            //�u% M�v�͏ȗ��i32�r�b�g�S���Ώۂɂ��邽�߁j
		return (X >> 16) & RAND_MAX;//���`�����@�́A���ʃr�b�g�̃o�����������̂ŁA���16�r�b�g��Ԃ�
	}
	//�V�[�h���X�V
	void srand(const int seed)
	{
		X = seed;
		//rand();//���̎���x�����𔭍s���郉�C�u����������
	}
}

int main(const int argc, const char* argv[])
{
	//���ݎ��ԂŃV�[�h����������
	{
		printf("- ���ݎ��ԂŃV�[�h���������� -\n");
		srand(static_cast<unsigned int>(time(nullptr)));
		printf("rand()=");
		for (int i = 0; i < 10; ++ i)
			printf(" %d", rand());
		printf("\n");
	}

	//�V�[�h���Œ�l�ɏ�������
	{
		printf("- �V�[�h���Œ�l�ɏ������� -\n");
		for (int loop = 1; loop <= 3; ++loop)
		{
			srand(123);
			printf("(%d ���)\n", loop);
			printf("rand()=");
			for (int i = 0; i < 10; ++i)
				printf(" %d", rand());
			printf("\n");
		}
	}

	//�������z�S����
	{
		printf("\n- �������z�S���� -\n");
		printf("RAND_MAX=%d\n", RAND_MAX);
		int r_init = rand();
		for (int loop = 1; loop <= 3; ++loop)
		{
			printf("<%d���>\n", loop);
			int step = 0;
			while (true)
			{
				int r = rand();
				bool is_print = false;
				if (step < 5 || r == r_init)//�ŏ���5��ƍŌゾ���\��
					is_print = true;
				if (is_print)
					printf("[%d]: %d\n", step, r);
				if (r == r_init)
					break;
				++step;
			}
		}
		printf("\n");
	}

	//�������z�S���񋓁i������`�����@�j
	{
		printf("\n- �������z�S���񋓁i������`�����@�j -\n");
		printf("custome::RAND_MAX=%d\n", custom::MAX);
		int r_init = custom::rand();
		for (int loop = 1; loop <= 3; ++loop)
		{
			printf("<%d���>\n", loop);
			int step = 0;
			while (true)
			{
				//�����Z�o
				int r = custom::rand();
				bool is_print = false;
				if (step < 5 || r == r_init)//�ŏ���5��ƍŌゾ���\��
					is_print = true;
				if (is_print)
					printf("[%d]: %d\n", step, r);
				if (r == r_init)
					break;
				++step;
			}
		}
		printf("\n");
	}

	//����1�r�b�g�̗�����100��
	{
		printf("\n- ����1�r�b�g�̗�����100�� -\n");
		for (int i = 0; i < 100; ++i){ printf("%d", rand() & 1); }
		printf("\n");
	}

	//�ŏ��1�r�b�g�̗�����100��
	{
		printf("\n- �ŏ��1�r�b�g�̗�����100�� -\n");
		for (int i = 0; i < 100; ++i){ printf("%d", (rand() & 0x4000) != 0x0); }
		printf("\n");
	}

	//x�Ŋ������]��̗���
	{
		const int probability_num = 5;
		const int test_count = 10000;
		printf("\n- %d�Ŋ������]��̗��� -\n", probability_num);
		int probability[probability_num] = {};
		for (int i = 0; i < test_count; ++i)
		{
			int r = rand() % probability_num;
			++ probability[r];
		}
		for (int i = 0; i < probability_num; ++i)
		{
			printf("[%3d] = %d��\n", i, probability[i]);
		}
		{
			int min = -1;
			int min_probability = -1;
			int max = -1;
			int max_probability = -1;
			for (int i = 0; i < probability_num; ++i)
			{
				if (min < 0 || min > probability[i])
				{
					min = probability[i];
					min_probability = i;
				}
				if (max < 0 || max < probability[i])
				{
					max = probability[i];
					max_probability = i;
				}
			}
			printf("�ŏ�: [%3d] = %d��\n", min_probability, min);
			printf("�ő�: [%3d] = %d��\n", max_probability, max);
			printf("�� = %d\n", max - min);
		}
	}

	//��U����������x�ł���������
	{
		const int probability_num = 5;
		const int test_count = 10000;
		printf("\n- ��U����������%d�ł��������� -\n", probability_num);
		int probability[probability_num] = {};
		for (int i = 0; i < test_count; ++i)
		{
			double ratio = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
			int r = static_cast<int>(ratio * static_cast<double>(probability_num));
			++probability[r];
		}
		for (int i = 0; i < probability_num; ++i)
		{
			printf("[%3d] = %d��\n", i, probability[i]);
		}
		{
			int min = -1;
			int min_probability = -1;
			int max = -1;
			int max_probability = -1;
			for (int i = 0; i < probability_num; ++i)
			{
				if (min < 0 || min > probability[i])
				{
					min = probability[i];
					min_probability = i;
				}
				if (max < 0 || max < probability[i])
				{
					max = probability[i];
					max_probability = i;
				}
			}
			printf("�ŏ�: [%3d] = %d��\n", min_probability, min);
			printf("�ő�: [%3d] = %d��\n", max_probability, max);
			printf("�� = %d\n", max - min);
		}
	}

	//C++11�̐V�����������g�p
	{
		const int probability_num = 5;
		const int test_count = 10000;
		printf("\n- C++11�̐V�����������g�p -\n", probability_num);
		std::mt19937 engine1;
		std::mt19937 engine2;
		std::uint32_t min = engine1.min();//�����̍ŏ��l
		std::uint32_t max = engine1.max();//�����̍ő�l
		std::uint32_t r = engine1();      //�����擾
		std::uniform_int_distribution<int> distribution(0, probability_num - 1);
		int probability1[probability_num] = {};
		int probability2[probability_num] = {};
		for (int i = 0; i < test_count; ++i)
		{
			int r1 = distribution(engine1);
			int r2 = distribution(engine2);
			++probability1[r1];
			++probability2[r2];
		}
		printf("(probability1)\n");
		for (int i = 0; i < probability_num; ++i)
		{
			printf("[%3d] = %d��\n", i, probability1[i]);
		}
		{
			int min = -1;
			int min_probability = -1;
			int max = -1;
			int max_probability = -1;
			for (int i = 0; i < probability_num; ++i)
			{
				if (min < 0 || min > probability1[i])
				{
					min = probability1[i];
					min_probability = i;
				}
				if (max < 0 || max < probability1[i])
				{
					max = probability1[i];
					max_probability = i;
				}
			}
			printf("�ŏ�: [%3d] = %d��\n", min_probability, min);
			printf("�ő�: [%3d] = %d��\n", max_probability, max);
			printf("�� = %d\n", max - min);
		}
		printf("(probability2)\n");
		for (int i = 0; i < probability_num; ++i)
		{
			printf("[%3d] = %d��\n", i, probability2[i]);
		}
		{
			int min = -1;
			int min_probability = -1;
			int max = -1;
			int max_probability = -1;
			for (int i = 0; i < probability_num; ++i)
			{
				if (min < 0 || min > probability2[i])
				{
					min = probability2[i];
					min_probability = i;
				}
				if (max < 0 || max < probability2[i])
				{
					max = probability2[i];
					max_probability = i;
				}
			}
			printf("�ŏ�: [%3d] = %d��\n", min_probability, min);
			printf("�ő�: [%3d] = %d��\n", max_probability, max);
			printf("�� = %d\n", max - min);
		}
		//�񌈒�I�ȗ��������G���W���i�\���s�\�ȗ���������j
		//���n�[�h�E�F�A�̃m�C�Y��}�E�X�̓����Ƃ��������̂��痐���𐶐������@�B�x���B
		//�@���R�A�V�[�h���Œ肷��悤�Ȃ��Ƃ��ł��Ȃ��B
		{
			printf("std::random_device\n");
			std::random_device rnd;
			std::uniform_int_distribution<int> dist(10, 20);
			for (int i = 0; i < 20; ++i)
			{
				int r = dist(rnd);
				printf(" %d", r);
			}
			printf("\n");
			std::uniform_int_distribution<int> dist1(10, 20);
			std::uniform_real_distribution<float> dist2(0.5f, 1.2f);
			std::normal_distribution<> dist3(100.0, 20.0);
			for (int i = 0; i < 10; ++i)
				printf("%d,%.5f,%.5llf\n", dist1(rnd), dist2(rnd), dist3(rnd));
			printf("%d,%d,%d,%d,%d\n", sizeof(std::mt19937), sizeof(std::mt19937_64), sizeof(std::minstd_rand0), sizeof(std::minstd_rand), sizeof(std::random_device));
		}
	}

	//
	return EXIT_SUCCESS;
}

// End of file

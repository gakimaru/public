#include <stdio.h>
#include <stdlib.h>

#include <future>//�񓯊��֐��p

#include <thread>//�X���[�v�p
#include <chrono>//���Ԍv���p

#include <vector>//�e�X�g�v�Z�p
#include <algorithm>//�e�X�g�v�Z�p

//�v�Z�p�֐�A
int calcSubA()
{
	//���Ԃ̂����鏈������̃X���[�v
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	return 1;
}

//�v�Z�p�֐�B
int calcSubB()
{
	//���Ԃ̂����鏈������̃X���[�v
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	return 2;
}

//�v�Z�p�֐�C
int calcSubC()
{
	//���Ԃ̂����鏈������̃X���[�v
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	return 3;
}

//�ʏ�֐�����
void testNormalCalc()
{
	//���Ԍv���J�n
	auto begin = std::chrono::high_resolution_clock::now();
	
	//����
	int result = 0;
	static const int TEST_TIMES = 100;
	for (int i = 0; i < TEST_TIMES; ++i)
	{
		result += (calcSubA() + calcSubB() + calcSubC());
	}
	
	//���Ԍv���I��
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000.);
	
	//���ʕ\��
	printf("----------------------------------------\n");
	printf("subNormalCalc: result = %d (%.6f sec)\n", result, duration);
}

//�񓯊��֐�����
void testAsyncCalc()
{
	//���Ԍv���J�n
	auto begin = std::chrono::high_resolution_clock::now();

	//����
	int result = 0;
	static const int TEST_TIMES = 100;
	for (int i = 0; i < TEST_TIMES; ++i)
	{
		//����(future)�Ɍ��ʂ��Ԃ�֐���񓯊��Ŏ��s
		std::future<int> r1 = std::async(calcSubA),
			             r2 = std::async(calcSubB),
			             r3 = std::async(calcSubC);
		
		//.get()���\�b�h�́A�����̊�����҂��Č��ʂ�Ԃ�
		result += (r1.get() + r2.get() + r3.get());
	}
	
	//���Ԍv���I��
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000.);

	//���ʕ\��
	printf("----------------------------------------\n");
	printf("subAsyncCalc: result = %d (%.6f sec)\n", result, duration);
}

//�񓯊��֐��y���p�z
void testAsyncCalcEx()
{
	//���X�g�쐬
	static const int LIST_MAX = 10000000;
	std::vector<int> list_org;
	list_org.reserve(LIST_MAX);
	for (int i = 0; i < LIST_MAX; ++i)
	{
		list_org.push_back(i);
	}

	//���X�g�V���b�t��
	std::random_shuffle(list_org.begin(), list_org.end());
		
	//���̎��_�̃��X�g��\��
	printf("----------------------------------------\n");
	printf("subAsyncCalcEx: before\n");
	printf("list =");
	std::for_each(list_org.begin(), list_org.begin() + 10, [](int val){printf(" %d", val); });
	printf(" ... ");
	std::for_each(list_org.end() - 10, list_org.end(), [](int val){printf(" %d", val); });
	printf("\n");

	//�ʏ�\�[�g
	{
		//���Ԍv���J�n
		auto begin = std::chrono::high_resolution_clock::now();
		
		//���������F�V���b�t���ς݃��X�g���R�s�[
		std::vector<int> list = list_org;
		
		//�N�C�b�N�\�[�g
		std::sort(list.begin(), list.end());
		
		//���Ԍv���I��
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000.);
		
		//���ʕ\��
		printf("----------------------------------------\n");
		printf("subAsyncCalcEx: normal-sort: result (%.6f sec):\n", duration);
		printf("list =");
		std::for_each(list.begin(), list.begin() + 10, [](int val){printf(" %d", val);});
		printf(" ... ");
		std::for_each(list.end() - 10, list.end(), [](int val){printf(" %d", val); });
		printf("\n");
	}
	
	//�񓯊��֐��Ń\�[�g
	//����ʂɃo�b�t�@�������
	{
		//���Ԍv���J�n
		auto begin = std::chrono::high_resolution_clock::now();

		//���������F�V���b�t���ς݃��X�g���R�s�[
		std::vector<int> list = list_org;
		const int list_size = list.size();

		//4�����ŕ���N�C�b�N�\�[�g
		std::future<void> r_a[4];
		{
			//�񓯊������ɂ́A�֐��|�C���^�[�ȊO�ɂ��A�֐��I�u�W�F�N�g�⃉���_����n�����Ƃ��ł���
			auto sort_lambda = [&list](const int index, const int list_begin, const int list_end)
			{
				std::vector<int>::iterator ite_begin = list.begin() + list_begin;
				std::vector<int>::iterator ite_end = list.begin() + list_end;
				std::sort(ite_begin, ite_end);
			};
			r_a[0] = std::async(sort_lambda, 0, list_size / 4 * 0, list_size / 4 * 1);
			r_a[1] = std::async(sort_lambda, 1, list_size / 4 * 1, list_size / 4 * 2);
			r_a[2] = std::async(sort_lambda, 2, list_size / 4 * 2, list_size / 4 * 3);
			r_a[3] = std::async(sort_lambda, 3, list_size / 4 * 3, list_size);
		}

		//2�����ŕ���}�[�W�\�[�g
		std::future<void> r_b[2];
		{
			//�񓯊������ɂ́A�֐��|�C���^�[�ȊO�ɂ��A�֐��I�u�W�F�N�g�⃉���_����n�����Ƃ��ł���
			auto merge_sort_lambda = [&r_a, &list](const int index, const int list_begin, const int list_mid, const int list_end)
			{
				r_a[index * 2 + 0].wait();
				r_a[index * 2 + 1].wait();
				std::vector<int>::iterator ite_begin = list.begin() + list_begin;
				std::vector<int>::iterator ite_mid = list.begin() + list_mid;
				std::vector<int>::iterator ite_end = list.begin() + list_end;
				std::inplace_merge(ite_begin, ite_mid, ite_end);//��̃��X�g����}�[�W�\�[�g����ꍇ�ɂ� std::merge() ���g����
			};
			r_b[0] = std::async(merge_sort_lambda, 0, list_size / 2 * 0, list_size / 2 * 0 + list_size / 4, list_size / 2 * 1);
			r_b[1] = std::async(merge_sort_lambda, 1, list_size / 2 * 1, list_size / 2 * 1 + list_size / 4, list_size);
		}
		
		//�}�[�W�\�[�g�i�����j
		{
			r_b[0].wait();
			r_b[1].wait();
			std::vector<int>::iterator ite_begin = list.begin();
			std::vector<int>::iterator ite_mid = list.begin() + list_size / 2;
			std::vector<int>::iterator ite_end = list.end();
			std::inplace_merge(ite_begin, ite_mid, ite_end);//��̃��X�g����}�[�W�\�[�g����ꍇ�ɂ� std::merge() ���g����
		}

		//���Ԍv���I��
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000.);
		
		//���ʕ\��
		printf("----------------------------------------\n");
		printf("subAsyncCalcEx: async-sort: result (%.6f sec):\n", duration);
		printf("list =");
		std::for_each(list.begin(), list.begin() + 10, [](int val){printf(" %d", val); });
		printf(" ... ");
		std::for_each(list.end() - 10, list.end(), [](int val){printf(" %d", val); });
		printf("\n");
	}
}

//�e�X�g
int main(const int argc, const char* argv[])
{
	//�ʏ�֐�����
	testNormalCalc();
	
	//�񓯊��֐�����
	testAsyncCalc();

	//�񓯊��֐����p
	testAsyncCalcEx();

	return EXIT_SUCCESS;
}

// End of file

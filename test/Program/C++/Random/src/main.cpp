#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <array>

#include <cstdint>
#include <random>

//カスタム乱数生成器
namespace custom
{
	//線形合同法 計算式（漸化式）：X = ( A * X{前回の値} + B) % M
	static const int SEED_INIT = 1;  //初期シード
	static const int A = 1103515245; //←このAとBの値が良いと
	static const int B = 12345;      //　均等分布性と周期性が良くなる
//	static const int M = 0x800000000;//32ビット全域が対象
	static       int X = SEED_INIT;  //前回の値（シード）
	static const int MAX = 0x7fff;   //乱数の最大値

	//乱数を取得
	int rand()
	{
		X = (A * X + B);            //「% M」は省略（32ビット全域を対象にするため）
		return (X >> 16) & RAND_MAX;//線形合同法は、下位ビットのバラつきが悪いので、上位16ビットを返す
	}
	//シードを更新
	void srand(const int seed)
	{
		X = seed;
		//rand();//この時一度乱数を発行するライブラリもある
	}
}

int main(const int argc, const char* argv[])
{
	//現在時間でシードを書き換え
	{
		printf("- 現在時間でシードを書き換え -\n");
		srand(static_cast<unsigned int>(time(nullptr)));
		printf("rand()=");
		for (int i = 0; i < 10; ++ i)
			printf(" %d", rand());
		printf("\n");
	}

	//シードを固定値に書き換え
	{
		printf("- シードを固定値に書き換え -\n");
		for (int loop = 1; loop <= 3; ++loop)
		{
			srand(123);
			printf("(%d 回目)\n", loop);
			printf("rand()=");
			for (int i = 0; i < 10; ++i)
				printf(" %d", rand());
			printf("\n");
		}
	}

	//乱数分布全部列挙
	{
		printf("\n- 乱数分布全部列挙 -\n");
		printf("RAND_MAX=%d\n", RAND_MAX);
		int r_init = rand();
		for (int loop = 1; loop <= 3; ++loop)
		{
			printf("<%d回目>\n", loop);
			int step = 0;
			while (true)
			{
				int r = rand();
				bool is_print = false;
				if (step < 5 || r == r_init)//最初の5回と最後だけ表示
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

	//乱数分布全部列挙（自作線形合同法）
	{
		printf("\n- 乱数分布全部列挙（自作線形合同法） -\n");
		printf("custome::RAND_MAX=%d\n", custom::MAX);
		int r_init = custom::rand();
		for (int loop = 1; loop <= 3; ++loop)
		{
			printf("<%d回目>\n", loop);
			int step = 0;
			while (true)
			{
				//乱数算出
				int r = custom::rand();
				bool is_print = false;
				if (step < 5 || r == r_init)//最初の5回と最後だけ表示
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

	//下位1ビットの乱数を100回
	{
		printf("\n- 下位1ビットの乱数を100回 -\n");
		for (int i = 0; i < 100; ++i){ printf("%d", rand() & 1); }
		printf("\n");
	}

	//最上位1ビットの乱数を100回
	{
		printf("\n- 最上位1ビットの乱数を100回 -\n");
		for (int i = 0; i < 100; ++i){ printf("%d", (rand() & 0x4000) != 0x0); }
		printf("\n");
	}

	//xで割った余りの乱数
	{
		const int probability_num = 5;
		const int test_count = 10000;
		printf("\n- %dで割った余りの乱数 -\n", probability_num);
		int probability[probability_num] = {};
		for (int i = 0; i < test_count; ++i)
		{
			int r = rand() % probability_num;
			++ probability[r];
		}
		for (int i = 0; i < probability_num; ++i)
		{
			printf("[%3d] = %d回\n", i, probability[i]);
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
			printf("最小: [%3d] = %d回\n", min_probability, min);
			printf("最大: [%3d] = %d回\n", max_probability, max);
			printf("差 = %d\n", max - min);
		}
	}

	//一旦小数化してxでかけた乱数
	{
		const int probability_num = 5;
		const int test_count = 10000;
		printf("\n- 一旦小数化して%dでかけた乱数 -\n", probability_num);
		int probability[probability_num] = {};
		for (int i = 0; i < test_count; ++i)
		{
			double ratio = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
			int r = static_cast<int>(ratio * static_cast<double>(probability_num));
			++probability[r];
		}
		for (int i = 0; i < probability_num; ++i)
		{
			printf("[%3d] = %d回\n", i, probability[i]);
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
			printf("最小: [%3d] = %d回\n", min_probability, min);
			printf("最大: [%3d] = %d回\n", max_probability, max);
			printf("差 = %d\n", max - min);
		}
	}

	//C++11の新しい乱数を使用
	{
		const int probability_num = 5;
		const int test_count = 10000;
		printf("\n- C++11の新しい乱数を使用 -\n", probability_num);
		std::mt19937 engine1;
		std::mt19937 engine2;
		std::uint32_t min = engine1.min();//乱数の最小値
		std::uint32_t max = engine1.max();//乱数の最大値
		std::uint32_t r = engine1();      //乱数取得
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
			printf("[%3d] = %d回\n", i, probability1[i]);
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
			printf("最小: [%3d] = %d回\n", min_probability, min);
			printf("最大: [%3d] = %d回\n", max_probability, max);
			printf("差 = %d\n", max - min);
		}
		printf("(probability2)\n");
		for (int i = 0; i < probability_num; ++i)
		{
			printf("[%3d] = %d回\n", i, probability2[i]);
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
			printf("最小: [%3d] = %d回\n", min_probability, min);
			printf("最大: [%3d] = %d回\n", max_probability, max);
			printf("差 = %d\n", max - min);
		}
		//非決定的な乱数生成エンジン（予測不能な乱数生成器）
		//※ハードウェアのノイズやマウスの動きといったものから乱数を生成する手法。遅い。
		//　当然、シードを固定するようなこともできない。
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
